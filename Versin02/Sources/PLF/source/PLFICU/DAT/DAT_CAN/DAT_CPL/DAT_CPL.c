

//------------------------------------------------------------------------------
// Body Identification
//------------------------------------------------------------------------------
#define dat_cpl  "dat_cpl"

//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//
// #include <system_file_name.h>
// #include "project_file_name.h"
//------------------------------------------------------------------------------
#define cDAT_CPL_SELFINCLUDE
#include "DAT_CPL.h"
#include "DAT_CPL_GEN_FILE.h"
#include "DAT_CPL_TXHANDLE2CH.h"
#include "network_manage.h"
//------------------------------------------------------------------------------
// Local constants
//
// #define cConstantName   ((tType) ConstantValue)
//------------------------------------------------------------------------------

//"- cDATCnl_NbUS" because the treatment of the 2 Diag on Can message are directly made by
// the LAP_DIA (Diag on can management)
#define cDATCpl_NbRx cDATCdl_NbUURx - cDATCnl_NbUS


//#define	Debug_Output_By_Can	1

//------------------------------------------------------------------------------
// Local types
//
// typedef Expression    tTypeName;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Local macros
//
// #define mMacroName   (MacroDefinition)
//------------------------------------------------------------------------------
// Access to the Rx buffer
#define mDATCplBufferRxHandle(RxHandle) DATCplTableROMRx[RxHandle]

//Access to the default data
#define mDATCplBufferRxHandleDefault(RxHandle) TableROMRxDefault[RxHandle]


//------------------------------------------------------------------------------
// Data prefix
//
// unsigned int {u8,u16,u32} / signed int {s8,s16,s32} 
// register size unsigned int {r} / float {f32,f64}  / s for struct 
//
// -----------------------------------------------------------------------------
// Local data
//
// static  tType   u8VariableName;  
// static  tType*  pu8VariableName; 
//------------------------------------------------------------------------------

//Flag Table to authorize (or not) the frame transmission by DAT_CAN (usefull if there is
// some applicative condition to block the periodical transmission or several vehicule
// configuration to manage)
U8 DATCplPeriodTxFlag[cDATCplTxFlagLength];
U8 DATCplTrigTxFlag[cDATCplTxFlagLength];

//Flag Table set at each frame tranmission (usefull for the LAP which treat the data under graph)
U8 DATCplTableTramesPresentes[cDATCplRxFlagLength];

static	U8		su8HandleDisableRxCtrlArr[cDATCplRxFlagLength];
static	U8		su8HandleDisableTxCtrlArr[cDATCplTxFlagLength];

static BOOL sbCanTimeoutStopFlag;   //报文超时计时标志  0：正常计时  1：停止超时计时

//DATCplTableTramesPresentes2nd is the same as DATCplTableTramesPresentes,
//but it is only for app default(2s) timeout
U8  DATCplTableTramesPresentes2nd[cDATCplRxFlagLength];

//add by zc 报文是否收到过标志
U8  DATCplTableMsgReceivedFlg[cDATCplRxFlagLength];

//接收报文超时时间数组，由脚本自动生成
#include"DAT_CPL_TableTimeout.h"

//change by zc u32
static U32 u32DATCplAppMsgTimer[cDATCdl_NbUURx];

static	U8	u8DATCplCanErrCntBuf[2];
static const tMsg CanErrCntMsg =
{
	u8DATCplCanErrCntBuf,
	2
};

// Record the NM Rx Address, This is a special record process for NM only
static tAddress uNMRxAddress = cCanInvalidFrameAddress;
//------------------------------------------------------------------------------
// Constant local data
//
// static const tType  VariableName;
//------------------------------------------------------------------------------

//Initial ROM table value of the received frame
static const tDATCplpBuffersRx InitBuffersReception =
{
    mInitInitBuffersReception()
};

//Default ROM table value of the received frame: default value is put when there is
// applicative timeout of frame reception or in particular case (eg: invalid value of a signal, then the default value must be forced)
static const tDATCplpBuffersRx DefaultBuffersReception =
{
    mInitDefaultBuffersReception()
};

//Initial ROM table value of the transmitted frame
static const tDATCdlBuffersUUTx InitBuffersEmission =
{
    mInitInitBuffersEmission()
};

//ROM table of pointer of the initial value for each received frame
static const U8* const TableROMRxDefault[cDATCpl_NbRx] =
    { 
       mDATCplDefaultTableROMRxInit()
    };

//------------------------------------------------------------------------------
// Exported data
//
// tType   u8LAYCmpVariableName; (LAY: 3 characters to identify the layer)
// tType*  pu8LAYCmpVariableName;(Cmp: 3 characters to identify the component)
//------------------------------------------------------------------------------

//Reception table for the applicative access
//Must contain all frame + USDT + ASDT message but not the Diagnostic message
tDATCplpBuffersRx  DATCplImageBuffersReception;


//------------------------------------------------------------------------------
// Constant exported data
//
//             (LAY: 3 characters to identify the layer)
//             (Cmp: 3 characters to identify this component)
// 
// const tType   LAYCmpVariableName;
//------------------------------------------------------------------------------

const U8* const DATCplTableROMRx[cDATCpl_NbRx] =
    { 
       mDATCplResetTableROMRx()
    };

//------------------------------------------------------------------------------
// Local function prototypes
// 
// static tTypeRetour FunctionName(tTypeArgument1 ArgumentName1, ... );
//------------------------------------------------------------------------------
static void DATCplTreateAppMsgTimeout(void);
#if 0
static void SetFrameDefaultValue(tDATCilI_RxHandle RxHandle);
#endif
//==============================================================================
//=========================== LOCAL FUNCTIONS ==================================
//==============================================================================
//==============================================================================
// DESCRIPTION : For Application, Signal missing action is taken after 2s(default)
// 			 since signal is missing.
// PARAMETERS (Type,Name,Min,Max) : tDATCilI_RxHandle RxHandle: Frame identifier
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
static void DATCplTreateAppMsgTimeout(void)
{
    tDATCilI_RxHandle RxHandle;


	for(RxHandle=0;RxHandle<cDATCdl_NbUURx;RxHandle++)
	{
		if(mDATCplIsClearFlag(DATCplTableTramesPresentes,RxHandle))
		{

			if(u32DATCplAppMsgTimer[RxHandle] < (cau32DATCplTableTimeoutMs[RxHandle]/cDATCdlTickMs))
			{
				u32DATCplAppMsgTimer[RxHandle]++;
			}
			else
			{
				mDATCplClearFlag(DATCplTableTramesPresentes2nd, RxHandle);
				//mDATCanMsgTimeoutPro(RxHandle);
			}
		}
		else
		{
			u32DATCplAppMsgTimer[RxHandle] = 0;
		}
	}
}

//==============================================================================
// DESCRIPTION : Do the treatment for each x3 non reception timeout
//
// PARAMETERS (Type,Name,Min,Max) : tDATCilI_RxHandle RxHandle: Frame identifier
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
#if 0
static void SetFrameDefaultValue(tDATCilI_RxHandle RxHandle)
{
    U8* pCplMsgImage;
    U8* pCplMsgImageDefaut;

    // No Timeout on the USDT Frames because they aren't periodic.
    // The diagnostic frames aren't planned to be copied in Cpl image buffer.
    // There is a overflow memory risk because the handle is 0 and the working 
    // index is decremented of 1 because the size of Cpl image buffer, for the 
    // LAP presentation, is less than the total number of messages.
    mLIBassert(RxHandle >= cDATCnl_NbUS);

    pCplMsgImage = (U8*)(mDATCplBufferRxHandle(RxHandle - cDATCnl_NbUS));
    pCplMsgImageDefaut = (U8*)(mDATCplBufferRxHandleDefault(RxHandle - cDATCnl_NbUS));
    //"-cDATCnl_NbUS" because there is 2 eventmential USDT message but not treated by DAT_CPL
    mLIBmemcpy( pCplMsgImage, pCplMsgImageDefaut, mDATCdlLngMaxStatiqueRxHandle(RxHandle) ); 
}

#endif
//==============================================================================
//=========================== EXPORTED FUNCTIONS ===============================
//==============================================================================

//==============================================================================
// DESCRIPTION : Do the treatment on reception of frame or message, but not for a 
// Diag on Can message
//
// PARAMETERS (Type,Name,Min,Max) : tDATCilI_RxHandle RxHandle : Frame identifier
//                                  BOOL Timeout               : reception status
//                                  cTrue: timeout has occured
//                                  cFalse: real frame reception
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void DATCplTraiterReception(tDATCilI_RxHandle RxHandle, BOOL Timeout)
{

  U8* pCdlMsg;
  U8* pCplMsgImage;
  U8* pCplMsgImageDefaut;




  if( !Timeout )
  {
        //If you use the DAT_CDL (not DAT_CDL2 with a rolling buffer) component
        //you must block the reception to avoid an reception interrupt conflict
        #ifndef DAT_Cdl2
        mDATCdlDisableITRx();
        #endif

         //In case of Diag on Can segmentated message treatments are particular
         switch( RxHandle )
         {
            //Diag on Can request
            case( cDATCnlN_USHandleDiagP2P_0x18DAE7F9 ) :
            {
            	UDS_RxIndication_Status = TRUE;
                //Control for LAP_DIA component (do not remove!)
                TOSSendControl(cTOSControlLAPDiaRequestP2P);
                break;
            }

            //Diag on Can diffusion request (do not remove!)
            case( cDATCnlN_USHandleDiagP2A_0x18DBFFF9 ) :
            {
            	UDS_RxIndication_Status = TRUE;
                //Control for LAP_DIA component (do not remove!)
                TOSSendControl(cTOSControlLAPDiaRequestALL);
                break;
            }

            //In this example the other frame are UUDT, otherwise you must use for USDT
            //and ASDT the data and length reading macro from DAT_CNL
            default:
            {
                U8 RxLen;

				if(mDATCanMsgIsRxDisable(RxHandle)&&(cSysMod_Diag == mSERRead(U8Bit,SysMode,Default)))
				{
					//Diag mode
					//Rx is disabled,no statement
				}
				else
				{
					pCdlMsg = mDATCdlBufferRxHandle(RxHandle);
					
					//"-cDATCnl_NbUS" because there is 2 eventmential USDT message but
					//not treated by DAT_CPL
					pCplMsgImage = (U8*)mDATCplBufferRxHandle(RxHandle - cDATCnl_NbUS);
					
					mLIBassert(RxHandle >= cDATCnl_NbUS);
					
					RxLen = mMin(mDATCdlLngRxHandle(RxHandle), mDATCdlLngMaxStatiqueRxHandle(RxHandle));
					
					if(RxLen != 0)
					{
						(void)mLIBmemcpy( pCplMsgImage, pCdlMsg, RxLen );
					}
					
					if( RxLen < mDATCdlLngMaxStatiqueRxHandle(RxHandle))
					{
						//"-cDATCnl_NbUS" because there is 2 eventmential USDT message but
						//not treated by DAT_CPL
						pCplMsgImageDefaut = (U8*)(mDATCplBufferRxHandleDefault(RxHandle - cDATCnl_NbUS));
						pCplMsgImageDefaut += RxLen;
						pCplMsgImage	   += RxLen;
						(void)mLIBmemcpy( pCplMsgImage ,pCplMsgImageDefaut,mDATCdlLngMaxStatiqueRxHandle(RxHandle)-RxLen);
					}

					//if(cDATCdlD_UURxHandleIP_RX_NM == RxHandle)
					{  // Address Information needed by LAP_CAN
					//	uNMRxAddress = mDATCdlAddressRxHandle(RxHandle);
					}
					/*
					RS-IL-12 Data Length Code, DLC JMC input document:1689-201-003RS01 Interaction Layer.pdf
					The DLC shall be set to 8 for all the messages. Only message with DLC = 8 shall be regarded as correct 
					and used. Message with DLC != 8 shall be regarded as incorrect and shall not be used.
					==>This is done in JMC_N351.jil file
					==>see MinLength attribute
					*/
				}
                break;
            }
         }

        //Unblock the reception IT if you use DAT_CDL component
        #ifndef DAT_Cdl2
        mDATCdlEnableITRx(); 
        #endif

		if(mDATCanMsgIsRxDisable(RxHandle)&&(cSysMod_Diag == mSERRead(U8Bit,SysMode,Default)))
		{
			//Diag mode
			//Rx is disabled,no statement
	        mDATCplClearFlag(DATCplTableTramesPresentes, RxHandle);
	        mDATCplClearFlag(DATCplTableTramesPresentes2nd, RxHandle);
		}
		else
		{
			//Set the flag of received frame
			mDATCplSetFlag(DATCplTableTramesPresentes, RxHandle);
			mDATCplSetFlag(DATCplTableTramesPresentes2nd, RxHandle);
		
			mDATCanMsgRcvedPro(RxHandle);
		}
    }
    else
    {
        //Reception timeout (timeout value of each frame must be parametered
        //as x3 the nominal frame period
        mDATCplClearFlag(DATCplTableTramesPresentes, RxHandle);

        /*switch( RxHandle )
        {
            case( xxx ):
                // Traitement absence
                // remplacer xxx par le handle de la trame
                // remplacer yyy par le handle de l'ECU supervis閑
                if( mDATCnmReadConfirmedFaultStatus( yyy) != cFalse )
                {
                    SetFrameDefaultValue( xxx )
                }

            break;
        }*/

        switch( RxHandle )
        {
            //case( cDATCdlD_UURxHandleIP_RX_NM ):
            	// TODO: see DATCplPreparerEmission NM bus sleep enter process
            	// so when really enter bus sleep, need to reset the NM Rx image buffer.
            	// to prevent the disabled transmission of application message when Ig ON
            	// and with NO NM NODE INTERACTION.
				//SetFrameDefaultValue( cDATCdlD_UURxHandleIP_RX_NM );
            //break;
            default:
            break;
        }

        //mSERReadU8BitCanControllerStatusDefault
		if(cNM_BusOff == mSERRead(U8Bit,CanControllerStatus,Default))
		{
			//Bus Off,no statement
		}
		else
		{
			//!Bus Off
#ifdef LaterUpdate
			mDATCanMsgTimeoutDTCPro(RxHandle);
#endif
		}
    }
}
//==============================================================================
// DESCRIPTION : Do the presentation treatments for the transmission of message and frame
//
// PARAMETERS (Type,Name,Min,Max) : 
// tDATCilI_RxHandle RxHandle : Identify the message or the frame
//
// RETURN VALUE : BOOL : transmission authorization
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
BOOL DATCplPreparerEmission(tDATCilI_TxHandle TxHandle)
{
    //Here you can set the lenght of the transmitted message/frame if need
    //Data are already copied to the DAT_CDL transmisssion buffer by macro
    //Note that you can't stop the automatical periodical transmission
    BOOL EnableTransmission = cTrue;

    U8 u8CANCh = 0U;
	U8 u8TxMsgLng = 8U;

	if(TxHandle < cU8MaxTxHandle)
	{
		//get the Txed Msg length and set the value.
		if(su8TxHandle2TxMsgLng[TxHandle]  > 8U)
		{
			u8TxMsgLng = 8U;			
		}
		else
		{
			u8TxMsgLng = su8TxHandle2TxMsgLng[TxHandle];
		}
		
		mDATCdlLngTxHandle(TxHandle) = u8TxMsgLng;
	}
	else
	{
		EnableTransmission = cFalse;
	}

    // TODO: bug fix for the application message transmitted after the NM message with sleep.ack==1
    // AS NM is driven by a periodic task, and all NM event is not processed immediately, though this
    // bug fix is ugly, it works.
    // NM bus sleep enter process
    //if(TxHandle != cDATCdlD_UUTxHandleAUXIO2_0X18A70017)
    //{
		//if ( ( 0x20&mDATRead(U8Bit, AUXIO2_0X18A70017_OpCode, Default) ) ||
		//	 ( 0x20&mDATRead(U8Bit, IP_RX_NM_OpCode, Default) ) )
    	//if(0)
	//	{	// Any SleepAck set, enter wait bus sleep
		//	EnableTransmission = cFalse;
		//}
    //}

    if(EnableTransmission != cFalse)
    {
    	if(mDATCanMsgIsTxDisable(TxHandle))//*&&(cSysMod_Diag == mDATRead(U8Bit,SysMode,Default)))
		{
			//diag mode
			//Tx is disable
			EnableTransmission = cFalse;
		}
		else
		{
		    //mSERControl(PeriodTxEnable, TX_XXXXXXXX)这句话会使能消息发送，其本质上就是设置
		    //DATCplPeriodTxFlag这个数组中的相应标志位，某位为1，表示允许发送，如果为False表示禁止发送。
		    //如果添加触发式发送，那么这个标志位会由mSERControl(PeriodTxEnable,TX_XXXXXX)设置
		    //如果消息发送成功后，则自动清除这个标志位。
			mDATCplSetFlag(DATCplPeriodTxFlag, TxHandle);
			EnableTransmission = mDATCplIsSetFlag(DATCplPeriodTxFlag, TxHandle);
			mDATCplClearFlag(DATCplPeriodTxFlag, TxHandle);
		};

    	//这里添加对触发式发送的判断
    	if(mDATCplIsSetFlag(DATCplTrigTxFlag, TxHandle))
    	{
    	    EnableTransmission = cTrue;
    	    mDATCplClearFlag(DATCplTrigTxFlag, TxHandle);
    	}

    }
	else
	{
		//kept judgement result
	}
#ifdef COMPILATION_NATIVE
	//no statement
#else
    //这里要判断是哪个通道的消息，根据通道号来决定是否发送。所以这里要添加代码，
    //查询通道和Handle间的对应关系
	//2018年4月12日 14:54:12，zjb
	//只有在允许发送时，才查询发送通道。否则跳过
    if((cTrue == EnableTransmission) && (TxHandle < cU8MaxTxHandle))
    {
    	u8CANCh = scu8TxHandle2Ch[TxHandle];
    	if(cLDBChannelCanPosHolder != u8CANCh)
    	{
    		LDBReceiveWithAddr(u8CANCh, cLDBCanAdrControllerSts,(tMsg *)&CanErrCntMsg);
    		if(0x04 == (u8DATCplCanErrCntBuf[1] & 0x04)) //Bus Off
    		{
    			EnableTransmission = cFalse;
    		}
    		else
    		{
    			//kept judgement result
    		}
    	}
    }

#endif

    return(EnableTransmission);
}
//==============================================================================
// DESCRIPTION : ASDT without session management message callback for confirmation of the transmission
// (This type of message is NOT USED)
//
// PARAMETERS (Type,Name,Min,Max) :   none
// tDATCilI_TxHandle TxHandle :  identify the message
// BOOL          EmissionOk: cTrue: emission is Ok 
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
#ifdef COMPOSANT_DAT_CTL_ON
void DATCplI_ASDataCon( tDATCilI_TxHandle TxHandle, BOOL EmissionOk )
{
    TxHandle = TxHandle;
    EmissionOk = EmissionOk;

    //To defined
}
#endif

//==============================================================================
// DESCRIPTION : ASDT with session management message callback for confirmation of the transmission
// This type of frame is used by the Renault multimedia network
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
#ifdef DAT_CTL_SESSION_ON
void DATCplI_ASSDataCon( tDATCilI_TxHandle TxHandle, BOOL EmissionOk )
{
    TxHandle = TxHandle;
    EmissionOk = EmissionOk;
    
    //To defined

}
#endif

//==============================================================================
// DESCRIPTION : Do the confirmation of an emission of a message treatments
//
// PARAMETERS (Type,Name,Min,Max) :   none
// tDATCilI_TxHandle TxHandle :  identify the message
// BOOL          EmissionOk: cTrue: emission is Ok
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void DATCplI_USDataCon( tDATCilI_TxHandle TxHandle, BOOL EmissionOk )
{
    //TxHandle = TxHandle;
    //EmissionOk = EmissionOk;
    //Send a control to the LAP_DIA component (do not remove!)
	switch(TxHandle)
	{
		case cDATCilI_TxHandleDiagP2A_0x18DBFFF9:
		case cDATCilI_TxHandleDiagP2P_0x18DAE7F9:
			if(EmissionOk)
			{
				TOSSendControl(cTOSControlLAPDiaFrameTransmitted);
			}
			else
			{
				//sending failure
			}
			break;
		default:
			break;
	}

    //For other USDT message treatment to defined
}

//==============================================================================
// DESCRIPTION : Do the confirmation of an emission of a frame treatments
//
// PARAMETERS (Type,Name,Min,Max) :   none
// tDATCilI_TxHandle TxHandle : identify the frame
// BOOL             EmissionOk: cTrue: emission is Ok
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void DATCplI_UUDataCon( tDATCilI_TxHandle TxHandle, BOOL EmissionOk )
{
    //TxHandle = TxHandle;
	if(EmissionOk)
	{
	    switch(TxHandle)
		{
			#ifdef Debug_Output_By_Can
			case cDATCilI_TxHandleIC_DbgInfor:	
				//TOSSendControl(cTOSControlLAPCanMsg_IC_DbgInfor_Txed);
				break;
			#endif
			//case cDATCilI_TxHandleAUXIO2_0X18A70017:
			//	TOSSendControl(cTOSControlNMMessageTransmitted);
			//	break;
			//case cDATCilI_TxHandleIC_0x510:
			//	break;
			default:
				mLIBassert(cFalse);
				break;
		}
	}
}

//add by zc响应IG off >> On5s后的控制，启动报文超时计时
void DatCplCanTimeoutStart(void)
{
    //启动超时计时
    sbCanTimeoutStopFlag = cFalse;
}

//add by zc响应IG off >> On的控制，初始化接收报文超时相关变量，停止报文超时计算，5s后启动
void DatCplCanTimeoutStop(void)
{
    //超时标志重置为假，即不超时
    mDATCplSetAllFlag(DATCplTableTramesPresentes);
    mDATCplSetAllFlag(DATCplTableTramesPresentes2nd);

    //停止超时计时
    sbCanTimeoutStopFlag = cTrue;
    mLIBmemset(u32DATCplAppMsgTimer,0,sizeof(u32DATCplAppMsgTimer));
}

//==============================================================================
// DESCRIPTION : Do the end of communication treatments
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
#ifdef M_MULTIBUS_CAN
extern void DATCpl_P_Stop(tDATCilIdCanalCan IdCanalCan)
#else
void DATCpl_P_Stop(void)
#endif
{
    // Initialization of the presentation buffer for the LAP layer
    mLIBmemcpy( 
        &DATCplImageBuffersReception, 
        &InitBuffersReception, 
        sizeof(tDATCplpBuffersRx) );

//    mDATCplClearAllFlag(DATCplTableTramesPresentes);
//    mDATCplClearAllFlag(DATCplTableTramesPresentes2nd);

      //超时标志上电默认不超时
      mDATCplSetAllFlag(DATCplTableTramesPresentes);
      mDATCplSetAllFlag(DATCplTableTramesPresentes2nd);

      //报文收到标志上电默认未收到
      mDATCplClearAllFlag(DATCplTableMsgReceivedFlg);

    mLIBmemset(u32DATCplAppMsgTimer,0,sizeof(u32DATCplAppMsgTimer));
}

//==============================================================================
// DESCRIPTION : Intialize the component (call during the startup)
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void DATCplInit(void)
{
    //Initialization of the transmission buffers 
    mLIBmemcpy( 
         &DATCdlBuffersUUTx,
         &InitBuffersEmission,
         sizeof(tDATCdlBuffersUUTx) );

    //To initialize the LAP presentation buffer and the flag
#ifdef M_MULTIBUS_CAN
    DATCpl_P_Stop(0);
#else
    DATCpl_P_Stop();
#endif
    (void)mLIBmemset((void*)su8HandleDisableRxCtrlArr,0x00U, cDATCplRxFlagLength);
    (void)mLIBmemset((void*)su8HandleDisableTxCtrlArr,0x00U, cDATCplTxFlagLength);

	uNMRxAddress = cCanInvalidFrameAddress;
}

//==============================================================================
// DESCRIPTION : Initialize the component on start of the communication
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
#ifdef M_MULTIBUS_CAN
void DATCpl_P_Init(tDATCilIdCanalCan IdCanalCan)
#else
void DATCpl_P_Init(void)
#endif
{
    //Initialization of all the flag and data
    DATCplInit();
}

//==============================================================================
// DESCRIPTION : Do the periodical treatments (CAN Tick task)
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void DATCplTick(void)
{
    //Here your quick periodical treatments (for example some applicative timeout management)
    if(cFalse == sbCanTimeoutStopFlag)//计时停止标志为假时，正常计时
    {
        DATCplTreateAppMsgTimeout();
    }

#ifdef LaterUpDate
//Rx/Tx diag enable/disable process
	if(cSysMod_Diag != mSERRead(U8Bit,SysMode,Default))
	{
#if defined(COMPILATION_NATIVE)
		if(su8HandleDisableRxCtrlArr || su8HandleDisableTxCtrlArr)
		{
			mLDBTrace("wildcard: Enable All.");
		}
#endif
		su8HandleDisableRxCtrlArr = 0x00000000;
		su8HandleDisableTxCtrlArr = 0x00000000;
		TalkNM();
	}
	else
	{
		//no statement
	}
#endif
}

//==============================================================================
// DESCRIPTION : APP Rx/Tx,NM Rx/Tx enable/disable process
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void	DatCplDiagDisableAppRx(void)
{
    mMacroDatCplDiagDisableAppRx();
}
void	DatCplDiagDisableNMRx(void)
{
	//do nothing, no NM message
}
void	DatCplDiagEnableAppRx(void)
{
    mMacroDatCplDiagEnableAppRx();

}
void	DatCplDiagEnableNMRx(void)
{
	//do nothing, no NM message
}
void	DatCplDiagEnableAppTx(void)
{
    mMacroDatCplDiagEnableAppTx();
}


void	DatCplDiagDisableAppTx(void)
{
    mMacroDatCplDiagDisableAppTx();
}

void	DatCplDiagEnableNMTx(void)
{	
	//do nothing,no NM message
}
void	DatCplDiagDisableNMTx(void)
{
	//do nothing, no NM message
}
//==============================================================================
// DESCRIPTION : APP Rx/Tx,NM Rx/Tx enable/disable process
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
BOOL	DatCplNoMsgToClusterOnCANBus(void)
{
	U8		u8Loop;
	BOOL	bReturn;

	bReturn = cTrue;

	for(u8Loop = 0;u8Loop < cDATCplRxFlagLength;u8Loop++)
	{
		if((U8)0x00 != DATCplTableMsgReceivedFlg[u8Loop])
		{
			//Cluster needed msg received
			bReturn = cFalse;
			break;
		}
		else
		{
			//no statement
		}
	}

	return(bReturn);
}

//==============================================================================
// DESCRIPTION : Get The Rx Frame CAN ID for NM only
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : this call back is only available for LAP_CAN D_WindowDataInd
//==============================================================================
tAddress DATCplGetRxNmFrameAddress(void)
{
	// return the latest Rx Nm message Frame address if received.
	tAddress address;
	if(0)
	//if(mDATCplReadTrameReceived(IP_RX_NM) != cFalse)
	{
		address = uNMRxAddress;
	}
	else
	{
		address = cCanInvalidFrameAddress;
	}
	return address;
}

