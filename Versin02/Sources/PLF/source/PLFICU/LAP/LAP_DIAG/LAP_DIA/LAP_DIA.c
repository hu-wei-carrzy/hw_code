//******************************************************************************
// Company:      Johnson Controls Inc.
// -----------------------------------------------------------------------------
// Copyright:    This software is JCI property.
//               Duplication or disclosure without JCI written authorization
//               is prohibited.
// -----------------------------------------------------------------------------
// Project:      N351
// Language:     C
// -----------------------------------------------------------------------------
// Component:    Diag On Can Management: UDS/DiagOnCAN implementation
//               this component is a template which may be modify to implement
//               project Dia requirements
//******************************************************************************
//2018年2月1日 16:06:28
//zjb
//3597
//添加代码，在向Loader跳转时，先设置标志位，再设置相应的管脚，然后再
//跳转，避免连续下载时，屏幕变黑的问题。此问题，经查证，是图形板Linux
//停止运行，可能是没有供电，后续会继续查为什么没有供电。
//在复位前，设置下相应的电源管脚，连续下载时，屏幕可正常亮起来

//------------------------------------------------------------------------------
// Body Identification
//------------------------------------------------------------------------------
#define lap_dia  "lap_dia"


//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//
// #include <system_file_name.h>
// #include "project_file_name.h"
//------------------------------------------------------------------------------

#define cLAP_DIA_SELFINCLUDE

#include "LAP_DIA.h"
#include "LAP_DIA.hgr"


//------------------------------------------------------------------------------
// Local constants
//
// #define cConstantName   ((tType) ConstantValue)
//------------------------------------------------------------------------------
#define cEndCommunicationTimeOut        (mTOSConvMsInTimerTick(5000UL))//(mTOSConvMsInTimerTick(5000UL))
#define cEndP2Timer                     (mTOSConvMsInTimerTick(cLAPDiaP2ResponseTimeout))
#define cEndP2Timer_JCI					(mTOSConvMsInTimerTick(600))

#define cLAPDiaSeaDTTimeOut        		(mTOSConvMsInTimerTick(10000UL))

#define cLngReqDiagnosticSessionControl   ((U8)0x02U)
#define cLngRepDiagnosticSessionControl   ((U8)0x06U)

#define cLngReqCommunicationControl       ((U8)0x03U)
#define cLngRepCommunicationControl       ((U8)0x02U)

#define cLngReqTesterPresent            ((U8)0x02U)
#define cLngRepTesterPresent            ((U8)0x02U)

#define cNegativeResponseCode           ((U8)0x7FU)
#define cLngOfNegativeResponse          ((U8)0x03U)

// Parameter of LAPDiaResponse.From data
#define cLAPDiaResponseFromProtocol                            ((U8)0)
#define cLAPDiaResponseFromService                             ((U8)1)
#define cLAPDiaResponseFromP2TimeOut                           ((U8)2)


// Parameter of RequestInAnalyze.Status and LAPDiaMemorizedRequest.Status
#define cNoRequest                                            ((U8)0)
#define cRequestP2P                                           ((U8)1)
#define cRequestALL                                           ((U8)2)

//the customized test service request parameter
#define cTestServiceEchoRequest                              ((U8)1)
#define cTestServiceMaxLng                                    ((U8)33)
#define cCtrlType_EnableRx_EnableTx							((U8)0x00)
#define cCtrlType_EnableRx_DisableTx						((U8)0x01)
#define cCtrlType_DisableRx_EnableTx						((U8)0x02)
#define cCtrlType_DisableRx_DisableTx						((U8)0x03)
#define cCtrlType_Max										((U8)0x04)

#define cCtrlType_KindRx									((U8)0x00)
#define cCtrlType_KindTx									((U8)0x01)
#define cCtrlType_KindMax									((U8)0x02)

#define cComType_App										((U8)0x01)//Bit0
#define cComType_NM											((U8)0x02)//Bit1
#define cComType_BitNummax									((U8)0x02)//total 2 bits

#define cComType_TypeMax									((U8)0x03)//total type:3

//------------------------------------------------------------------------------
// Local macros
//
// #define mMacroName   (MacroDefinition)
//------------------------------------------------------------------------------
#define mGetRequestedDiagnosticSessionType()			((U8)(LAPDiaMemorizedRequest.Buffer[(U8)1] & (U8)0x7FU))
#define mGetRequestedTesterPresentSubService()			((U8)(LAPDiaMemorizedRequest.Buffer[1] & (U8)0x7FU))
#define mGetSuppresPosRspMsgIndicationBit()				((U8)((U8)(LAPDiaMemorizedRequest.Buffer[1] & (U8)0x80U) >> 7))

#define mGetRequestedCommunicationControlType()			((U8)(LAPDiaMemorizedRequest.Buffer[(U8)1] & (U8)0x7FU))


//------------------------------------------------------------------------------
// Local types
//
// typedef Expression    tTypeName;
//------------------------------------------------------------------------------
#if cLAPDiaLngBufferRequestP2P <= 0xFFUL
  typedef U8 tWorkableLng;
#else
  typedef U16 tWorkableLng;
#endif


typedef struct
{
    U8              *pBuffer;
    U16             Length;
    tWorkableLng    WorkableLength;
    BOOL            bProtected;
}tReceivedRequest;


typedef struct
{
  tReceivedRequest  *pReceivedRequest;
  U8                SessionIndex;
  U8                Status;
}tRequestInAnalyze;


typedef struct
{
	U8				u8ComTypeId;
	const	U8		(*pCtrlTbl)[cCtrlType_KindMax];
}tComCtrl;

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
static tTOSTimer            CommunicationTimeOut;
static tTOSTimer            P2Timer;
static tTOSTimer			tLAPDia_SeaTimer;

static tRequestInAnalyze    RequestInAnalyze;
static tReceivedRequest     ReceivedRequestP2P;

static U8                   BufferReceivedRequestP2P[cLAPDiaLngBufferRequestP2P];

#ifdef BROADCAST_REQUEST
    static tReceivedRequest ReceivedRequestALL;
    static U8               BufferReceivedRequestALL[cLAPDiaLngBufferRequestALL];
#endif

static BOOL                 DiaResponseOverflow;
static  BOOL            gbIsDiagMode;
static BOOL				gbIsPwrOutCfgTestMode;
static  U8              gu8DiagSt;

static U8				TestEnableFlag;								//测试DID状态

U8  mu8IOC_ScaleBackLight;
U8  mu8IOC_LCDBackLight;
U8  mu8IOC_LCDDisplay;
U8  mu8IOC_BuzType;
U8  mu8IOC_PwrLockType;
U16 mu16IOC_C3Out;
U32 mu32IOC_LEDOutL;
U16 mu16IOC_LEDOutH;
U8  mu8IOC_Speed;
U16 mu16IOC_Tacho;
U32 mu32IOC_AgeFlag;
U16 mu16IOC_PowerOut;
U8 mu8IOC_VideoChn;
U8 mu8IOC_KeyBackLight;
//------------------------------------------------------------------------------
// Constant local data
//
// static const tType  VariableName;
//------------------------------------------------------------------------------
mLAPDiaInitConstantLocalData()


//------------------------------------------------------------------------------
// Exported data
//
// tType   u8LAYCmpVariableName; (LAY: 3 characters to identify the layer)
// tType*  pu8LAYCmpVariableName;(Cmp: 3 characters to identify the component)
//------------------------------------------------------------------------------
tLAPDiaParamOfSession*  pLAPDiaActiveSession;

tLAPDiaMemorizedRequest LAPDiaMemorizedRequest;
tLAPDiaResponse         LAPDiaResponse;

tLAPDiaService          LAPDiaActiveService;

#ifdef ACCESSIBILITY_UNDER_VEHICLE_PROTECTION
/*    BOOL                bLAPDiaVehicleImmobilization;*/
#endif


//------------------------------------------------------------------------------
// Constant exported data
//
//             (LAY: 3 characters to identify the layer)
//             (Cmp: 3 characters to identify this component)
//
// const tType   LAYCmpVariableName;
//------------------------------------------------------------------------------
static const U8	LapdiaCommunationCtrlAppMsgTbl[cCtrlType_Max][cCtrlType_KindMax] =
{
	{cTOSControlLAPDiaAppEnableRx	,cTOSControlLAPDiaAppEnableTx	},//00	enableRxAndTx
	{cTOSControlLAPDiaAppEnableRx	,cTOSControlLAPDiaAppDisableTx	},//01	enableRxAndDisableTx
	{cTOSControlLAPDiaAppDisableRx	,cTOSControlLAPDiaAppEnableTx	},//02	disableRxAndEnableTx
	{cTOSControlLAPDiaAppDisableRx	,cTOSControlLAPDiaAppDisableTx	} //03	disableRxAndTx
};

static const U8	LapdiaCommunationCtrlNMMsgTbl[cCtrlType_Max][cCtrlType_KindMax] =
{
	{cTOSControlLAPDiaNMEnableRx	,cTOSControlLAPDiaNMEnableTx	},//00	enableRxAndTx
	{cTOSControlLAPDiaNMEnableRx	,cTOSControlLAPDiaNMDisableTx	},//01	enableRxAndDisableTx
	{cTOSControlLAPDiaNMDisableRx	,cTOSControlLAPDiaNMEnableTx	},//02	disableRxAndEnableTx
	{cTOSControlLAPDiaNMDisableRx	,cTOSControlLAPDiaNMDisableTx	} //03	disableRxAndTx
};

static	const	tComCtrl	sLapdiaComCtrlTbl[cComType_BitNummax] =
{
	{cComType_App	,LapdiaCommunationCtrlAppMsgTbl	},
	{cComType_NM	,LapdiaCommunationCtrlNMMsgTbl	}
};

//------------------------------------------------------------------------------
// Local function prototypes
//
// static tTypeRetour FunctionName(tTypeArgument1 ArgumentName1, ... );
//------------------------------------------------------------------------------
static BOOL ServiceKnownByECU(U8 IdService);
static BOOL ServiceSupportedInActiveSession(U8 IdService);
static BOOL CheckpActiveSession(void);
static BOOL ResponseIsNotRequired(void);

#ifdef ACCESSIBILITY_UNDER_VEHICLE_PROTECTION
    static BOOL ServiceSecurityAccessCheck(U8 IdService);
#endif
static BOOL IsConditionOK(void);
static void LAPDiaSessionUpdate(void);
static void EnableMsgTxAndRx(void);
//==============================================================================
//=========================== LOCAL FUNCTIONS ==================================
//==============================================================================
//==============================================================================
// DESCRIPTION : ServiceKnownByECU
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
static BOOL ServiceKnownByECU(U8 IdService)
{
    tLAPDiaParamOfSession * pSession;
    U8 IndexSession;
    U8 IndexService;
    BOOL bServiceKnownByECU;

    bServiceKnownByECU = cFalse;
    for (IndexSession=0; ((IndexSession<cNbSessions) && (bServiceKnownByECU == cFalse)); IndexSession++)
    {
        pSession = (tLAPDiaParamOfSession*)pLAPDiaSession[IndexSession];
        for (IndexService=0; (IndexService<pSession->NbOfSupportedService); IndexService++)
        {
            if (IdService == (pSession->pTabIdentifierOfSupportedService)[IndexService])
            {
                bServiceKnownByECU = cTrue;
            }
        }
    }

    return(bServiceKnownByECU);
}
//==============================================================================
// DESCRIPTION : ServiceSupportedInActiveSession
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
static BOOL ServiceSupportedInActiveSession(U8 IdService)
{
    U8 I;
    BOOL bServiceSupportedInActiveSession;
    BOOL bStatus;

    bServiceSupportedInActiveSession = cFalse;

    bStatus = CheckpActiveSession();
    //CCOV amanevm: bStatus is always cTrue because pLAPDiaActiveSession is one of elements of pLAPDiaSession
    if(bStatus != cFalse)
    {
        for (I=0; ((I<pLAPDiaActiveSession->NbOfSupportedService) && (bServiceSupportedInActiveSession == cFalse)); I++)
        {
            if (IdService == (pLAPDiaActiveSession->pTabIdentifierOfSupportedService)[I])
            {
                bServiceSupportedInActiveSession = cTrue;
                RequestInAnalyze.SessionIndex = I;
            }
        }
    }
    else
    {
        mLIBassert(cFalse);
    }
    return(bServiceSupportedInActiveSession);
}

//==============================================================================
// DESCRIPTION : ServiceSupportedInActiveSession
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
static BOOL ServiceIsNotSupportedInFunctionMode(U8 IdService)
{
    /*add by zc   boot跳转*/
    if(IdService == cLAPDiaIdRoutineControl)
    {
        return cFalse;
    }
    /************/

    return (BOOL)
    (
        ( ((IdService == cLAPDiaIdSecurityAccess)							||
           (IdService == cLAPDiaIdWriteDataByIdentifier)					||
           (IdService == cLAPDiaIdInputOutputControlByIdentifier)           ||
           (IdService == cLAPDiaIdRoutineControl) )
		   &&(RequestInAnalyze.pReceivedRequest == &ReceivedRequestALL) )
    );
}
//==============================================================================
// DESCRIPTION : ServiceSecurityAccessCheck
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
#ifdef ACCESSIBILITY_UNDER_VEHICLE_PROTECTION
static BOOL ServiceSecurityAccessCheck(U8 IdService)
{
	U16		DataIdentifier;
	BOOL	bReturn;

	DataIdentifier = ((U16)((RequestInAnalyze.pReceivedRequest->pBuffer)[2]) << 8) +
                	((RequestInAnalyze.pReceivedRequest->pBuffer)[3]);

	switch(LAPDiaGetActiveSession())
	{
		case cLAPDiaIdEXTDSSession: //WriteDID, RoutineControl, IOControl need security access permission
			if(//	((IdService == cLAPDiaIdWriteDataByIdentifier)&&(cFalse    == LAPSeaIsServiceUnLocked())) ||
				((IdService == cLAPDiaIdRoutineControl)&&(cFalse    == LAPSeaIsServiceUnLocked())) ||
				((IdService == cLAPDiaIdInputOutputControlByIdentifier)&&(cFalse    == LAPSeaIsServiceUnLocked())) ||
				((IdService == cLAPDiaIdWriteDataByIdentifier)&&(cFalse    == LAPSeaIsServiceUnLocked())) ||
				((IdService == cLAPDiaIdWriteMemoryByAddress)&&(cFalse    == LAPSeaIsServiceUnLocked()))
				)
			{
				bReturn = cTrue;
			}
			else
			{
				bReturn = cFalse;
			}

			if(0XFF02 == DataIdentifier)//0XFF02=CheckProgrammingPreconditions does not need security access
			{
				bReturn = cFalse;
			}
			break;

	    //all the product diagnostic service need security access.
		case cLAPDiaIdJCISession:
			if(//	(IdService == cLAPDiaIdRoutineControl)&&
				(cFalse    == LAPSeaIsServiceUnLocked()))//&&
				//((0xF0FA == DataIdentifier)||(0xFE00 == DataIdentifier)||(0xFE01 == DataIdentifier)))

			{
				bReturn = cTrue; //need security access, but not yet unlock ECU
			}
			else
			{
				bReturn = cFalse; //need security access and ECU is unlocked.
			}

			if((IdService == cLAPDiaIdSecurityAccess) ||
			   (IdService == cLAPDiaIdDiagnosticSessionControl) ||
			   (IdService == cLAPDiaIdControlDTCSetting))
			{
				bReturn = cFalse; //security access and session switch should not apply to itself.
			}

			break;

		default:
			bReturn = cFalse;
			break;
	}

    return(bReturn);
	//return cFalse;
}
#endif

//==============================================================================
// DESCRIPTION : ResponseIsNotRequired
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
static BOOL ResponseIsNotRequired(void)
{
    return (BOOL)
    (
        ( ((LAPDiaMemorizedRequest.Buffer[cLAPDiaService] == cLAPDiaIdDiagnosticSessionControl) ||
           (LAPDiaMemorizedRequest.Buffer[cLAPDiaService] == cLAPDiaIdEcuReset)                 ||
           (LAPDiaMemorizedRequest.Buffer[cLAPDiaService] == cLAPDiaIdSecurityAccess)           ||
           (LAPDiaMemorizedRequest.Buffer[cLAPDiaService] == cLAPDiaIdTesterPresent)            ||
           (LAPDiaMemorizedRequest.Buffer[cLAPDiaService] == cLAPDiaIdControlDTCSetting)        ||
           (LAPDiaMemorizedRequest.Buffer[cLAPDiaService] == cLAPDiaIdRoutineControl)			||
           (LAPDiaMemorizedRequest.Buffer[cLAPDiaService] == cLAPDiaIdCommunicationControl)		||
           (LAPDiaMemorizedRequest.Buffer[cLAPDiaService] == cLAPDiaIdReadDTCInformation))
         &&(mGetSuppresPosRspMsgIndicationBit() != (U8)0x00U) )
    );
}

//==============================================================================
// DESCRIPTION : CheckpActiveSession
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
static BOOL CheckpActiveSession(void)
{
    U8 u8Loop;
    BOOL bFind;

    bFind = cFalse;

    for (u8Loop = 0; u8Loop < cNbSessions; u8Loop++)
    {
        if (pLAPDiaActiveSession == pLAPDiaSession[u8Loop])
        {
            bFind = cTrue;
        }
    }
    return(bFind);
}

//==============================================================================
// DESCRIPTION : IsConditionOK for enter non-default session
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
static BOOL IsConditionOK(void)
{
    BOOL bConditionOK = cTrue;

//	if( cLAPDiaIdDefaultSession != LAPDiaMemorizedRequest.Buffer[cLAPDiaService+1] )
//	{	// SysRs_11_CustomerDiagnosis_611, for JCI session, it is the same as EXTDS. see SMRS24
//		if(1)
//		{
//			if (cTrue == mSERRead(U1Bit, IsDiagBatNormal, Default))
//			{
//				bConditionOK = cTrue;
//			}
//			else
//			{
//				bConditionOK = cFalse;
//			}
//		}
//		else	// IG off
//		{
//			if(cTrue == mSERRead(U1Bit,IsDiagBatNormal,Default))
//			{
//				// Power mode is "Normal" or "Middle-Over"
//			}
//			else
//			{
//				bConditionOK = cFalse;
//			}
//		}
//	}
//	else
//	{
//		// always condition OK for enter the default session
//	}

	return bConditionOK;
}


static void LAPDiaSessionUpdate(void)
{
   /* switch(LAPDiaGetActiveSession())
    {

    case cLAPDiaIdEXTDSSession:
        mSERWrite(U1Bit,CustomerSession, cTrue,Default);
        break;

    case cLAPDiaIdJCISession:
        mSERWrite(U1Bit,FactorySession, cTrue,Default);
        break;

    case cLAPDiaIdPRGSSession:
        mSERWrite(U1Bit, ProgramSession, cTrue, Default);
        break;

    case cLAPDiaIdDefaultSession:
        mSERWrite(U1Bit,DefaultSession, cTrue,Default);
        break;
    default:
        //error occur
        break;
    }*/

    if(cLAPDiaIdDefaultSession != LAPDiaGetActiveSession())
    {
        //mSERWrite(U1Bit, DiagMode, cTrue, Default);
        gbIsDiagMode = cTrue;
    }
    else
    {
        //mSERWrite(U1Bit, DiagMode, cFalse, Default);
        gbIsDiagMode = cFalse;
    }

}


static void EnableMsgTxAndRx(void)
{
	//enable message(App and NM) Rx and Tx
	TOSSendControl(cTOSControlLAPDiaAppEnableRx);
	TOSSendControl(cTOSControlLAPDiaAppEnableTx);
	TOSSendControl(cTOSControlLAPDiaNMEnableRx);
	TOSSendControl(cTOSControlLAPDiaNMEnableTx);
}


//==============================================================================
//=========================== EXPORTED FUNCTIONS ===============================
//==============================================================================

//==============================================================================
// DESCRIPTION : LAPDiaInitialize
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void LAPDiaInitialize(void)
{
    //Initialization of the temporisations
    TOSStopTimer(&CommunicationTimeOut);
    TOSStopTimer(&P2Timer);
    // don't touch this timer for Cm079509
	// TOSStopTimer(&tLAPDia_SeaTimer);

    RequestInAnalyze.pReceivedRequest   = &ReceivedRequestP2P;
    RequestInAnalyze.Status             = cNoRequest;

    mLIBmemset(&BufferReceivedRequestP2P, 0, cLAPDiaLngBufferRequestP2P);
    ReceivedRequestP2P.pBuffer          = BufferReceivedRequestP2P;
    ReceivedRequestP2P.bProtected       = cFalse;
    ReceivedRequestP2P.Length           = 0;
    ReceivedRequestP2P.WorkableLength   = 0;

    #ifdef BROADCAST_REQUEST
    mLIBmemset(&BufferReceivedRequestALL, 0, cLAPDiaLngBufferRequestALL);
    ReceivedRequestALL.pBuffer          = BufferReceivedRequestALL;
    ReceivedRequestALL.bProtected       = cFalse;
    ReceivedRequestALL.Length           = 0;
    ReceivedRequestALL.WorkableLength   = 0;
    #endif

    mLIBmemset(LAPDiaMemorizedRequest.Buffer, 0, cLAPDiaLngBufferRequestP2P);
    LAPDiaMemorizedRequest.Status  = cNoRequest;
    LAPDiaMemorizedRequest.Length = 0;

    mLIBmemset(LAPDiaResponse.Buffer, 0, cLAPDiaLngBufferResponse);
    LAPDiaResponse.Length = 0;
    LAPDiaResponse.From = cLAPDiaResponseFromProtocol;


    // After a init, the active session is the defaut session
    pLAPDiaActiveSession = (tLAPDiaParamOfSession*)&ParametersDefaultSession;

    LAPDiaActiveService.Step = cLAPDiaStartOfService;

    #ifdef ACCESSIBILITY_UNDER_VEHICLE_PROTECTION
/*        bLAPDiaVehicleImmobilization = cFalse;*/
    #endif

    gbIsDiagMode = cFalse;

    mu8IOC_ScaleBackLight = 0U;
    mu8IOC_LCDBackLight = 0U;
    mu8IOC_LCDDisplay = 0U;
    mu8IOC_Speed = 0U;
    mu16IOC_Tacho = 0U;
    mu32IOC_AgeFlag = 0U;
    mu8IOC_VideoChn = 0U;
    mu8IOC_KeyBackLight = 0U;

}
//==============================================================================
// DESCRIPTION : LAPDiaStart
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void LAPDiaStart(void)
{
    LAPDiaInitialize();
	//mSERWrite(U1Bit, ICGoToSleep, cFalse, Default);
}
//==============================================================================
// DESCRIPTION : LAPDiaStop
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void LAPDiaStop(void)
{
    LAPDiaInitialize();

    TOSSeqDeactivateGraph(cTOSSeqLAPDiaTreatRequest);
    TOSSeqDeactivateGraph(cTOSSeqLAPDiaCommunicationTimeOut);
    TOSSeqDeactivateGraph(cTOSSeqLAPDiaTreatService);
    TOSSeqDeactivateGraph(cTOSSeqLAPDiaP2TimeOut);
}
//==============================================================================
// DESCRIPTION : LAPDiaIsMaintainActiveState
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void LAPDiaIsMaintainActiveState(void)
{
    BOOL bStatus;
    bStatus = CheckpActiveSession();
    //CCOV amanevm: bStatus is always cTrue because pLAPDiaActiveSession is one of elements of pLAPDiaSession
    if(bStatus != cFalse)
    {
        if(pLAPDiaActiveSession->SessionIdentifier != cLAPDiaIdDefaultSession)
        {
            TOSWriteSignal(cTOSSignalSomebodyMaintainActiveState);
        }
    }
    else
    {
        mLIBassert(cFalse);
    }
}

//==============================================================================
// DESCRIPTION :
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
extern void Boot_SetFlagCallBack(void);
void LAPDiaDiagnosticSessionControl(void)
{
    U8    u8Loop;
    BOOL  bInvalidSession;
    BOOL  bInvalidLength;
    BOOL  bStatus;

    #if ((defined(cLIBStkCarBoot_VW) || defined (cLIBStkDatCanConfig_Rno) || defined (cLIBStkDatCanConfig_RnoMultiCells)) && defined(BOOTLOADER_IS_SUPPORTED))

    #ifndef COMPILATION_NATIVE
    //tBootLinkTable  * pReturnToBoot;
    #else
    tBootLinkTable* pReturnToBoot;
    #endif
    BOOL CheckDynamicParameters;
    BOOL IsBootSession;

    CheckDynamicParameters = cFalse;
    IsBootSession = cFalse;

	if(cFalse == IsConditionOK())
	{
		LAPDiaResponse.NegativeCode = cLAPDiaConditionsNotCorrect;
		LAPDiaPrepareNegativeResponse( LAPDiaResponse.NegativeCode);
	}
	else
	{
	    if ( ( LAPDiaMemorizedRequest.Buffer[cLAPDiaService+1] == cLAPDiaIdPRGSSession)
	       &&( LAPDiaMemorizedRequest.Length == cLngReqDiagnosticSessionControl))
	    {
	        //check the condition for enter programming session
	        IsBootSession = cTrue;

	        CheckDynamicParameters = cTrue;//mLAPDiaCheckBootJumpConditions();//

	        if(CheckDynamicParameters != cFalse)
	        {
	            LDBRefreshWatchDog();

	            //2018年2月1日 16:04:38
	            //zjb
	            //先设置跳转标志
	            Boot_SetFlagCallBack();
	            //执行具体的复位动作。因为执行复位动作时，要先设置图形板的电源管脚。
	            mSERControl(Cpu, Reset);

//
//	            //Execute specific command
//	            mLAPDiaAddSpecificCommand();
//
//	            #ifndef COMPILATION_NATIVE
//	            // call LIBReturnToBoot function (defined in LIB_BOO.C)
//	            pReturnToBoot = (tBootLinkTable  * )cLIBBooBootLinkTableAddress;
//	            // Polyspace justification: amanevm:
//	            // cLIBBooBootLinkTableAddress is address of structure of type tBootLinkTable.
//	            // In case bootloader is supported at this address structure is valid and
//	            // all pointers are valid functions in bootloader scope
//	            (*pReturnToBoot->pReturnToBootLink)(cTrue, CheckDynamicParameters/*,TOSClock*/);
//	            // After the boot jump, a RESET is done by the BOOT
//	            #else
//	            pReturnToBoot = NULL;          //to avoid a warning
//	            pReturnToBoot = pReturnToBoot; //to avoid a warning
//	            #endif
	        }
	        else
	        {
	            //Send negative response
	            LAPDiaPrepareNegativeResponse(cLAPDiaConditionsNotCorrect);
	            return;
	        }
	    }
	    #endif // BOOTLOADER_IS_SUPPORTED

	    //non programming session
	    #if ((defined(cLIBStkCarBoot_VW) || defined (cLIBStkDatCanConfig_Rno) || defined (cLIBStkDatCanConfig_RnoMultiCells)) && defined(BOOTLOADER_IS_SUPPORTED))
	    if((CheckDynamicParameters == cFalse)&&(IsBootSession == cFalse))
	    {
	    #endif
	    bInvalidSession = cTrue;
	    bInvalidLength = cTrue;

	    // Check if LAPDiaMemorizedRequest.Buffer[cLAPDiaService + (U8)1] exists
	    if (LAPDiaMemorizedRequest.Length > (cLAPDiaService + (U8)1))
	    {
	        for (u8Loop =0; (u8Loop < cNbSessions ); u8Loop++)
	        {
	            if (mGetRequestedDiagnosticSessionType() == pLAPDiaSession[u8Loop]->SessionIdentifier)
	            {
	                bInvalidSession = cFalse;

	                if (LAPDiaMemorizedRequest.Length == cLngReqDiagnosticSessionControl)
	                {
	                    bInvalidLength = cFalse;

	                    bStatus = CheckpActiveSession();
	                    //CCOV amanevm: bStatus is always cTrue because pLAPDiaActiveSession is one of elements of pLAPDiaSession
	                    if(bStatus != cFalse)
	                    {
							#if 0			// SysRs_11_CustomerDiagnosis_118
	                        if (pLAPDiaActiveSession->SessionIdentifier == mGetRequestedDiagnosticSessionType())
	                        {
	                            // No action. A positive response must be sent
	                        }
	                        else
							#endif
	                        {
	                            // Close the active session and open the new session
	                            TOSSendControl(cTOSControlLAPCloseDiagnosticSession);
	                            pLAPDiaActiveSession = (tLAPDiaParamOfSession*)pLAPDiaSession[u8Loop];
	                            LAPDiaSessionUpdate();
	                            TOSSendControl(cTOSControlLAPOpenDiagnosticSession);

	                            // Active the communication time out
	                            if (pLAPDiaActiveSession->SessionIdentifier != cLAPDiaIdDefaultSession)
	                            {
	                                bStatus = TOSSeqGraphState(cTOSSeqLAPDiaCommunicationTimeOut);
	                                if(bStatus == cTOSSeqInactiveGraph)
	                                {
	                                    TOSSeqActivateGraph(cTOSSeqLAPDiaCommunicationTimeOut);
	                                }

	                            }
	                            else
	                            {
	                                TOSSeqDeactivateGraph(cTOSSeqLAPDiaCommunicationTimeOut);
	                            }
	                        }
	                    }
	                    else
	                    {
	                        mLIBassert(cFalse);
	                    }
	                }
	            }
	        }
	    }
	    else
	    {
	        bInvalidSession = cFalse;
	    }

	    if (bInvalidSession != cFalse)
	    {
	        // GEN-VHL-ST-UDS.0320(0)
	        LAPDiaPrepareNegativeResponse(cLAPDiaSubFunctionNotSupported);
	    }
	    else if (bInvalidLength != cFalse)
	    {
	        // GEN-VHL-ST-UDS.0320(0)
	        LAPDiaPrepareNegativeResponse(cLAPDiaIncorrectMessageLengthOrInvalidFormat);
	    }
	    else
	    {
			//here add the return parameters:
			//P2Can_Server_max = 0x0032(50ms).
	        //P2*Can_Server_max = 0x01F4(5000ms)

			LAPDiaResponse.Buffer[2] = 0x00;
			LAPDiaResponse.Buffer[3] = 0x32;
			LAPDiaResponse.Buffer[4] = 0x01;
			LAPDiaResponse.Buffer[5] = 0xF4;
			//+4 stand for lenght of the above two parameters
	        LAPDiaPreparePositiveResponse(cLngRepDiagnosticSessionControl);
	    }
	    #if ((defined(cLIBStkCarBoot_VW) || defined (cLIBStkDatCanConfig_Rno) || defined (cLIBStkDatCanConfig_RnoMultiCells)) && defined(BOOTLOADER_IS_SUPPORTED))
	    }
	    else
	    {
	        LAPDiaPrepareNegativeResponse(cLAPDiaSubFunctionNotSupportedInActiveSession);
	    }
	    #endif
	}
}


//==============================================================================
// DESCRIPTION : LAPDiaTesterPresent
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void LAPDiaTesterPresent(void)
{
	if (LAPDiaMemorizedRequest.Length < cLngReqTesterPresent)
    {
        // GEN-VHL-ST-UDS.0490(0)
        LAPDiaPrepareNegativeResponse(cLAPDiaIncorrectMessageLengthOrInvalidFormat);
    }
    else if (mGetRequestedTesterPresentSubService() != (U8)0x00U)
    {
        // GEN-VHL-ST-UDS.0490(0)
        LAPDiaPrepareNegativeResponse(cLAPDiaSubFunctionNotSupported);
    }
    else if (LAPDiaMemorizedRequest.Length != cLngReqTesterPresent)
    {
        // GEN-VHL-ST-UDS.0490(0)
        LAPDiaPrepareNegativeResponse(cLAPDiaIncorrectMessageLengthOrInvalidFormat);
    }
    else
    {
        LAPDiaPreparePositiveResponse(cLngRepTesterPresent);
    }
}



//==============================================================================
// DESCRIPTION : LAPDiaTesterPresent
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void LAPDiaCommunicationControl(void)
{
	//SysRs_11_CustomerDiagnosis_125
	//when from diagnostic session(03/60) enter into default session(01), the CommuicationControl
	//should be reset, so before sending out the message code will check the current session value
	//the corresponding is implemented in DATCplPreparerEmission(), DAT_CPL.c

	//this function is used to control communication proces
	U8	u8CtrlType=0;
	U8	u8ComType=0;
	U8	u8Loop=0;

	//TODO，暂时没有条件
	if(0)//if((0U != mSERRead(U16Bit, SpeedKmph, Default)) ||(0U != mSERRead(U16Bit, TachoRpm, Default)))
	{
		LAPDiaPrepareNegativeResponse(cLAPDiaConditionsNotCorrect);
	}
	else if(LAPDiaMemorizedRequest.Length <= 1 ) //msg check
	{
		LAPDiaPrepareNegativeResponse(cLAPDiaIncorrectMessageLengthOrInvalidFormat);
	}
	else if(mGetRequestedCommunicationControlType() >= cCtrlType_Max) //sub function check
	{
		LAPDiaPrepareNegativeResponse(cLAPDiaSubFunctionNotSupported);
	}
	else if(cLngReqCommunicationControl != LAPDiaMemorizedRequest.Length) //msg check
	{
		LAPDiaPrepareNegativeResponse(cLAPDiaIncorrectMessageLengthOrInvalidFormat);
	}
	else if((0 == LAPDiaMemorizedRequest.Buffer[2]) || (LAPDiaMemorizedRequest.Buffer[2] > cComType_TypeMax)) //01,10,11
	{
		LAPDiaPrepareNegativeResponse(cLAPDiaRequestOutOfRange);
	}

	else //length & sub function & communation type all ok
	{
		u8CtrlType = mGetRequestedCommunicationControlType();	//control type
		u8ComType  = LAPDiaMemorizedRequest.Buffer[2];	//communication type

		for(u8Loop = 0;u8Loop < cComType_BitNummax;u8Loop++)
		{
			if(sLapdiaComCtrlTbl[u8Loop].u8ComTypeId == (u8ComType & sLapdiaComCtrlTbl[u8Loop].u8ComTypeId))
			{
				TOSSendControl(sLapdiaComCtrlTbl[u8Loop].pCtrlTbl[u8CtrlType][cCtrlType_KindRx]);
				TOSSendControl(sLapdiaComCtrlTbl[u8Loop].pCtrlTbl[u8CtrlType][cCtrlType_KindTx]);
			}
			else
			{
				//not control
			}
		}

		LAPDiaPreparePositiveResponse(cLngRepCommunicationControl);
	}

}
//==============================================================================
// DESCRIPTION :
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void LAPDiaReceiveRequestP2P(void)
{
    BOOL bStatus;
    if(ReceivedRequestP2P.bProtected == cFalse)
    {
        ReceivedRequestP2P.bProtected = cTrue;

        mLIBassert(ReceivedRequestP2P.pBuffer == (U8*)&BufferReceivedRequestP2P);

        mGetP2PFrameToDiag()
            ;

        bStatus = TOSSeqGraphState(cTOSSeqLAPDiaTreatRequest);
        if(bStatus == cTOSSeqInactiveGraph)
        {
            TOSSeqActivateGraph(cTOSSeqLAPDiaTreatRequest);
        }
    }
}


//==============================================================================
// DESCRIPTION : LAPDiaReceivedRequestALL
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
#ifdef BROADCAST_REQUEST
void LAPDiaReceiveRequestALL(void)
{
    BOOL bStatus;

    if(ReceivedRequestALL.bProtected == cFalse)
    {
        ReceivedRequestALL.bProtected = cTrue;

        mLIBassert(ReceivedRequestALL.pBuffer == (U8*)&BufferReceivedRequestALL);

        mGetALLFrameToDiag();


        bStatus = TOSSeqGraphState(cTOSSeqLAPDiaTreatRequest);
        if(bStatus == cTOSSeqInactiveGraph)
        {
            TOSSeqActivateGraph(cTOSSeqLAPDiaTreatRequest);
        }
    }
}
#endif


//==============================================================================
// DESCRIPTION :
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void LAPDiaResponseBegin( void)
{
    // first byte in response is for RDBIPR
    LAPDiaResponse.Length = 1;
    DiaResponseOverflow = cFalse;
}
//==============================================================================
// DESCRIPTION :
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void LAPDiaResponseWriteByte( U8 Data)
{
    // if data is writen in buffer
    if( LAPDiaResponse.Length < (U16)cLAPDiaLngBufferResponse)
    {
        LAPDiaResponse.Buffer[LAPDiaResponse.Length] = Data;

        LAPDiaResponse.Length ++;
    }

    // if data is writen after end of buffer
    else
    {
        DiaResponseOverflow = cTrue;
    }
}
//==============================================================================
// DESCRIPTION :
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
BOOL LAPDiaIsResponseLengthOverflow( void)
{
    return DiaResponseOverflow;
}
//==============================================================================
// DESCRIPTION : LAPDiaPrepareNegativeResponse
//
// PARAMETERS (Type,Name,Min,Max) :   NRC
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void LAPDiaPrepareNegativeResponse(U8 NRC)
{
    // NRC : Negative Response Code
    LAPDiaResponse.NegativeCode = NRC;

    LAPDiaResponse.Length   = cLngOfNegativeResponse;
    LAPDiaResponse.Buffer[0]= cNegativeResponseCode;
    LAPDiaResponse.Buffer[2]= mLAPDiaReadNegativeResponseCode();

    if (LAPDiaResponse.From == cLAPDiaResponseFromProtocol)
    {
        //CCOV amanevm: request is always received using specific buffer and is stored in specific buffer
        if(mCheckpReceivedRequest() && mCheckpReceivedRequestpBuffer())
        {
            LAPDiaResponse.Buffer[1] = (RequestInAnalyze.pReceivedRequest->pBuffer)[cLAPDiaService];
        }
        else
        {
            mLIBassert(cFalse);
        }
    }
    else
    {
        LAPDiaResponse.Buffer[1] = LAPDiaMemorizedRequest.Buffer[cLAPDiaService];
    }

    LAPDiaSendResponse(cFalse);
}


//==============================================================================
// DESCRIPTION : LAPDiaPreparePositiveResponse
//
// PARAMETERS (Type,Name,Min,Max) :   Length
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void LAPDiaPreparePositiveResponse(U8 Length)
{
    LAPDiaResponse.Buffer[1] = LAPDiaMemorizedRequest.Buffer[cLAPDiaService + (U8)1];
    LAPDiaPreparePositiveResponseSimple(Length);
}
//==============================================================================
// DESCRIPTION : LAPDiaPreparePositiveResponseSimple
//
// PARAMETERS (Type,Name,Min,Max) :   Length
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void LAPDiaPreparePositiveResponseSimple(U8 Length)
{
    LAPDiaResponse.Buffer[0] = LAPDiaMemorizedRequest.Buffer[cLAPDiaService] + ((U8)0x40U);
    LAPDiaResponse.Length = Length;

    LAPDiaSendResponse(cTrue);
}
//==============================================================================
// DESCRIPTION : LAPDiaSendResponse
//
// PARAMETERS (Type,Name,Min,Max) :   bPositive
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void LAPDiaSendResponse(BOOL bPositive)
{
    BOOL bRep;
	BOOL bSend;

	U8  RequestedService; //add by zc/*add by zc   boot跳转*/

    bRep = ResponseIsNotRequired();
	bSend = cFalse;

	if(bRep == cFalse)
	{
		//suppress-bit is not supported
		if	(RequestInAnalyze.Status != cRequestALL)
		{
			//Diagnostic is in P2P mode
			bSend = cTrue;
		}
		else
		{
			//Diagnostic is in P2AlL mode
			if(bPositive == cFalse)
			{
				//Negative Respond
				if	( (mLAPDiaReadNegativeResponseCode() != cLAPDiaSubFunctionNotSupported)
					&&(mLAPDiaReadNegativeResponseCode() != cLAPDiaServiceNotSupported)
					&&(mLAPDiaReadNegativeResponseCode() != cLAPDiaRequestOutOfRange)/*
					&&(mLAPDiaReadNegativeResponseCode() != cLAPDiaServiceNotSupportedInActiveSession)*/) //Cm054894&Cm054803 del cLAPDiaServiceNotSupportedInActiveSession
				{
					bSend = cTrue;
					//Cluster will Send Negative Respond
				}

			}
			else
			{
				//Cluster will Send Positive Respond
				bSend = cTrue;
			}
		}
	}
	else
	{
		//suppress-bit is supported
		if(bPositive == cFalse)
		{
			//Diagnostic is iN negative Respond
			if	(RequestInAnalyze.Status != cRequestALL)
			{
				//Cluster is In P2P mode
				//cluster will send Negative respond
				bSend = cTrue;
			}
			else
			{
				if	( (mLAPDiaReadNegativeResponseCode() != cLAPDiaSubFunctionNotSupported)
					&&(mLAPDiaReadNegativeResponseCode() != cLAPDiaServiceNotSupported)
					&&(mLAPDiaReadNegativeResponseCode() != cLAPDiaRequestOutOfRange)/*
					&&(mLAPDiaReadNegativeResponseCode() != cLAPDiaServiceNotSupportedInActiveSession)*/) //Cm054894&Cm054803 del cLAPDiaServiceNotSupportedInActiveSession
				{
					bSend = cTrue;
				}
			}
		}
	}

	/*add by zc   boot跳转*/
	RequestedService = (RequestInAnalyze.pReceivedRequest->pBuffer)[cLAPDiaService];
	if(0x31U == RequestedService)
	{
	    LAPDiaResponse.Length = 0x05U;
	    LAPDiaResponse.Buffer[0] = 0x71U;
	    LAPDiaResponse.Buffer[1] = 0x01U;
	    LAPDiaResponse.Buffer[2] = 0xFFU;
	    LAPDiaResponse.Buffer[3] = 0x02U;
	    LAPDiaResponse.Buffer[4] = 0x00U;
	    LAPDiaResponse.Buffer[5] = 0x55U;
	    LAPDiaResponse.Buffer[6] = 0x55U;
	    mSERWriteStruct(MsgDiag, LAPDiaResponse, &LAPDiaResponse, Default);
	            //mDiagOnCANSendResponse();
	    mSERControl(CANEmission, DiagP2P_0x18DAE7F9);
	}
	/***************/

	if(bSend)
	{
	    //zjb:暂时没找到函数归宿，待会再处理
		mSERWriteStruct(MsgDiag, LAPDiaResponse, &LAPDiaResponse, Default);
		//mDiagOnCANSendResponse();
		mSERControl(CANEmission, DiagP2P_0x18DAE7F9);
	}
    if (LAPDiaResponse.From == cLAPDiaResponseFromService)
    { // Service is finished

        TOSStopTimer(&P2Timer);
        TOSSeqDeactivateGraph(cTOSSeqLAPDiaP2TimeOut);
    }
    else
    {   // Negative response from AnalyzeRequest or from P2TimeOut
        // Nothing to do
    }

    if (LAPDiaActiveService.bReadyToFinished != cFalse)
    { // Service is finished
        mLIBmemset(LAPDiaMemorizedRequest.Buffer, 0, cLAPDiaLngBufferRequestP2P);
        LAPDiaMemorizedRequest.Length  = 0;
        LAPDiaMemorizedRequest.Status  = cNoRequest;

        TOSSeqDeactivateGraph(cTOSSeqLAPDiaTreatService);
    }
    else
    {   // Service is not finished
        // Nothing to do
    }

    //CCOV amanevm: in case of RequestInAnalyze.Status is different from cRequestP2P mLIBassert is generated
    if (
         (RequestInAnalyze.Status == cRequestP2P)
        #ifdef BROADCAST_REQUEST
       ||(RequestInAnalyze.Status == cRequestALL)
        #endif
        )
    {
        //CCOV amanevm: request is always received using specific buffer
        if(mCheckpReceivedRequest())
        {
            // Free the received request to be ready to received a new request
            RequestInAnalyze.pReceivedRequest->bProtected = cFalse;
        }
        else
        {
            mLIBassert(cFalse);
        }
    }
    else
    {
        // The response is P2P frame
        // we can't arrive here
        mLIBassert(cFalse);
    }
}
//==============================================================================
// DESCRIPTION :
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
U32 LAPDiaFindDIDIndex( const U16 *DidTable, U16 Did, U32 TableSize)
{
    U32 Index;

    for( Index=0; (Index < TableSize) && (DidTable[Index] != Did); Index++)
    {
        // empty
    }

    return Index;
}
#if defined(cLIBStkCarBoot_VW)
//==============================================================================
// DESCRIPTION :
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
U8 LAPDiaGetActiveSession( void )
{
    return pLAPDiaActiveSession->SessionIdentifier;
}
#endif
//==============================================================================
//=========================== GRAPH FUNCTIONS ==================================
//==============================================================================

//==============================================================================
// DESCRIPTION :
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
BOOL LAPDiaNewRequestIsReceived(void)
{
    BOOL bNewRequestIsReceived;

    bNewRequestIsReceived = cFalse;
    RequestInAnalyze.Status  = cNoRequest;

    #ifdef BROADCAST_REQUEST
    if (ReceivedRequestALL.bProtected != cFalse)
    {
        bNewRequestIsReceived = cTrue;
        RequestInAnalyze.pReceivedRequest   = &ReceivedRequestALL;
        RequestInAnalyze.Status             = cRequestALL;
    }
    #endif

    // The P2P request is priority as a broadcast request
    if (ReceivedRequestP2P.bProtected != cFalse)
    {
        bNewRequestIsReceived = cTrue;
        RequestInAnalyze.pReceivedRequest   = &ReceivedRequestP2P;
        RequestInAnalyze.Status             = cRequestP2P;
    }


    return(bNewRequestIsReceived);
}


//==============================================================================
// DESCRIPTION : LAPDiaAnalyzeRequest
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void LAPDiaAnalyzeRequest(void)
{
    BOOL  bRequest;
    U8  RequestedService;

    LAPDiaActiveService.bReadyToFinished = cFalse;

    LAPDiaResponse.From = cLAPDiaResponseFromProtocol;

    LAPDiaResponse.NegativeCode = cLAPDiaServiceIsCorrect;

    //CCOV amanevm: request is always received using specific buffer and is stored in specific buffer
    if( mCheckpReceivedRequest() && mCheckpReceivedRequestpBuffer())
    {
        RequestedService = (RequestInAnalyze.pReceivedRequest->pBuffer)[cLAPDiaService];

        // Reset the communcation time out
        TOSStartTimer(&CommunicationTimeOut);

        // Check if the service is known by the ECU
        bRequest = ServiceKnownByECU(RequestedService);
        if (bRequest != cFalse)
        {
            // The service is known
            // Check if the service is supported in the active session
            bRequest = ServiceSupportedInActiveSession(RequestedService);
            if(bRequest != cFalse)
            {
				bRequest = ServiceIsNotSupportedInFunctionMode(RequestedService);
				if(bRequest == cFalse)
				{
					#ifdef ACCESSIBILITY_UNDER_VEHICLE_PROTECTION
					// Check if Immo is not active
					bRequest = ServiceSecurityAccessCheck(RequestedService);
					if	(bRequest != cFalse)
					{
						LAPDiaPrepareNegativeResponse(cLAPDiaSecurityAccessDenied);
					}
					else
					#endif
					{
						//CCOV amanevm: request is always received using specific buffer and is stored in specific buffer
						if(mCheckpReceivedRequest() && mCheckpReceivedRequestpBuffer())
						{
							if (LAPDiaMemorizedRequest.Status == cNoRequest)
							{
								// Store the new request
								LAPDiaMemorizedRequest.Length = RequestInAnalyze.pReceivedRequest->Length;
								LAPDiaMemorizedRequest.Status = RequestInAnalyze.Status;
								#ifdef BROADCAST_REQUEST
								if (RequestInAnalyze.pReceivedRequest == &ReceivedRequestP2P)
								{
								#endif
									mLIBmemcpy(LAPDiaMemorizedRequest.Buffer,RequestInAnalyze.pReceivedRequest->pBuffer, cLAPDiaLngBufferRequestP2P);
								#ifdef BROADCAST_REQUEST
								}
								else // (RequestInAnalyze.pReceivedRequest == &ReceivedRequestALL)
								{
									mLIBmemcpy(LAPDiaMemorizedRequest.Buffer,RequestInAnalyze.pReceivedRequest->pBuffer, cLAPDiaLngBufferRequestALL);
								}
								#endif

								// Free the received request to be ready to received a new request
								RequestInAnalyze.pReceivedRequest->bProtected = cFalse;

								// Initialize the buffer of response
								mLIBmemset(LAPDiaResponse.Buffer, (U8)0x00U,cLAPDiaLngBufferResponse);

								// Prepare to treat the new service
								LAPDiaActiveService.SessionIndex = RequestInAnalyze.SessionIndex;
								LAPDiaActiveService.Step = cLAPDiaStartOfService;
								//QACJ 3416: amanevm: it is only an assert
								mLIBassert(TOSSeqGraphState(cTOSSeqLAPDiaTreatService) == cTOSSeqInactiveGraph);
								TOSSeqActivateGraph(cTOSSeqLAPDiaTreatService);

								// Start P2 TimeOut Alarm
								//QACJ 3416: amanevm: it is only an assert
								mLIBassert(TOSSeqGraphState(cTOSSeqLAPDiaP2TimeOut) == cTOSSeqInactiveGraph);
								TOSSeqActivateGraph(cTOSSeqLAPDiaP2TimeOut);
								TOSStartTimer(&P2Timer);
							}
							else // if (LAPDiaMemorizedRequest.Status != cNoRequest)
							{   // There are already another request in treatment
								#ifdef BROADCAST_REQUEST
								// We abondoned the new request if it is in the same mode
								if (RequestInAnalyze.Status == LAPDiaMemorizedRequest.Status)
								#endif  // The request is in treatment (already memorized)
								{
									RequestInAnalyze.pReceivedRequest->bProtected = cFalse;
								}
								#ifdef BROADCAST_REQUEST
								else
								{
									// Nothing to do => the new request is kept
									mLIBassert(cTrue);
								}
								#endif  // The request is in treatment (already memorized)
							}
						}
						else
						{
							mLIBassert(cFalse);
						}
					}
				}
				else
				{
					LAPDiaPrepareNegativeResponse(cLAPDiaServiceNotSupportedInActiveSession);
				}
            }
            else
            {
                // The service is not supported in the active session
                LAPDiaPrepareNegativeResponse(cLAPDiaServiceNotSupportedInActiveSession);
            }
        }
        else
        {
            // the service is unknown
            LAPDiaPrepareNegativeResponse(cLAPDiaServiceNotSupported);
        }
    }
    else
    {
        mLIBassert(cFalse);
    }
}


//==============================================================================
// DESCRIPTION : LAPDiaCommunicationTimeOutIsElapsed
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
BOOL LAPDiaCommunicationTimeOutIsElapsed(void)
{
	BOOL bStatus;

	/*
	 * In N330, when IGOff, the diagnostic session is still available
	if(mSERRead(U1Bit, IGInput, Delayed) == cFalse)
	{
		bStatus = cTrue;
	}
	else
	*/
	{
		bStatus = (BOOL) (TOSIsTimerElapsed(&CommunicationTimeOut, cEndCommunicationTimeOut) );
	}

	return bStatus;
}
//==============================================================================
// DESCRIPTION : LAPDiaTreatCommunicationTimeOut
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void LAPDiaTreatCommunicationTimeOut(void)
{
    TOSStopTimer(&CommunicationTimeOut);

    // Close the active session
    TOSSendControl(cTOSControlLAPCloseDiagnosticSession);

    LAPDiaStop();

    gbIsDiagMode = cFalse;
}


//==============================================================================
// DESCRIPTION : LAPDiaExecuteService
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void LAPDiaExecuteService(void)
{
    BOOL bStatus;
    LAPDiaResponse.From     = cLAPDiaResponseFromService;
    RequestInAnalyze.Status = LAPDiaMemorizedRequest.Status;
    LAPDiaActiveService.bReadyToFinished = cTrue;

    bStatus = CheckpActiveSession();
    //SysRs_11_CustomerDiagnosis_110
	//here check the battery value to avoid recheck battery in each componentd
	if(cFalse == mSERRead(U1Bit,IsDiagBatNormal,Default))
	{
		LAPDiaResponse.NegativeCode = cLAPDiaConditionsNotCorrect;
		LAPDiaPrepareNegativeResponse( LAPDiaResponse.NegativeCode);
	}
    //CCOV amanevm: bStatus is always cTrue because pLAPDiaActiveSession is one of elements of pLAPDiaSession
	else if(bStatus != cFalse)
    {
		if(LAPDiaActiveService.SessionIndex < pLAPDiaActiveSession->NbOfSupportedService)
		{
	        // Launch the execution of the service
	        (*(pLAPDiaActiveSession->pTabFunctionOfSupportedService[LAPDiaActiveService.SessionIndex]))();
		}
   }
    else
    {
        mLIBassert(cFalse);
    }
}


//==============================================================================
// DESCRIPTION :
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
BOOL LAPDiaP2TimeOutIsElapsed(void)
{
	BOOL bRev;

    mLIBassert(LAPDiaMemorizedRequest.Status != cNoRequest);

	if (pLAPDiaActiveSession->SessionIdentifier != cLAPDiaIdJCISession)
	{
		bRev = (BOOL) ( TOSIsTimerElapsed(&P2Timer, cEndP2Timer) );
	}
	else
	{
		bRev = (BOOL) ( TOSIsTimerElapsed(&P2Timer, cEndP2Timer_JCI) );
	}

	return bRev;
}


//==============================================================================
// DESCRIPTION :
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void LAPDiaSendBusyResponse(void)
{
    LAPDiaResponse.From     = cLAPDiaResponseFromP2TimeOut;
    RequestInAnalyze.Status = LAPDiaMemorizedRequest.Status;
    LAPDiaActiveService.bReadyToFinished  = cFalse;
    // rearm timer
    TOSStartTimer(&P2Timer);

    LAPDiaPrepareNegativeResponse(cLAPDiaResponsePending);
}

//==============================================================================
// DESCRIPTION :
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
BOOL LAPDiaIsFunctionAddress()
{
	return (RequestInAnalyze.Status==cRequestALL);
}
//==============================================================================
// DESCRIPTION :
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
BOOL LAPDiaIsPhysicalAddress()
{
	return (RequestInAnalyze.Status==cRequestP2P);
}

//==============================================================================
// DESCRIPTION :
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
BOOL LAPDia_IsSeaDTElapsed(void)
{
	return(TOSIsTimerElapsed(&tLAPDia_SeaTimer, cLAPDiaSeaDTTimeOut));
}
//==============================================================================
// DESCRIPTION :
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void LAPDia_StartDT(void)
{
	TOSStartTimer(&tLAPDia_SeaTimer);
}
//==============================================================================
// DESCRIPTION :
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void LAPDiaDiagExit(void)
{
	//exit from diag session
	//enter default session
	LAPDiaInitialize();
}


BOOL LAPDiaGetCurDiagSt(void)
{
    return gbIsDiagMode;
}

BOOL LAPDiaGetTestMode(void)
{
    return gbIsPwrOutCfgTestMode;
}

void LAPDiaSetTestMode(BOOL mode)
{
    if (mode <= 1)
	{
    	gbIsPwrOutCfgTestMode = mode;
	}
}

void LAPDia_SetDiagStByDiagSession(U8 u8DiagSession,BOOL bValue)
{
    if(eDiagSt_SessionNum > u8DiagSession)
    {
        if(bValue)
        {
            //because there is only on bit is 1 in gu8DiagSt, so I have to clear
            //gu8DiagSt first.
            gu8DiagSt = 0;
            gu8DiagSt = (1<<u8DiagSession);
        }
        else
        {
            gu8DiagSt &= ~(1<<u8DiagSession);
        }
    }
}


BOOL LAPDia_GetDiagStBySession(U8 u8DiagSession)
{
    BOOL bRet = cFalse;
    if(eDiagSt_SessionNum > u8DiagSession)
    {
       bRet =  ((BOOL)(gu8DiagSt & (((U8)1)<<(u8DiagSession))) != 0);
    }
    else
    {
        //do nothing
    }

    return bRet;
}

U32 LAPDia_GetRunInFlag(void )
{
	return mu32IOC_AgeFlag;
}

void LAPDiaCloseSession(void)
{

}

void LAPDiaOpenSession(void)
{
	EnableMsgTxAndRx();
}


U8 LAPDiaGetTestEnableflag(void)
{
	return TestEnableFlag;
}

U8 LAPDiaSetTestEnableflag(Sta)
{
	TestEnableFlag = Sta;
}
