


/*--------------------------------------------------------------------------
Body Identification
--------------------------------------------------------------------------*/

#define LDB_CAN "LDB_CAN"

/*-------------------------------------------------------------------------
Included files

  #include <system_file_name.h>
  #include "project_file_name.h"
--------------------------------------------------------------------------*/
#include "LDB_CAN.h"
#include ".\..\..\TOS\TOS.h"

/*--------------------------------------------------------------------------
Local constants

  #define cConstantName   ((tType) ConstantValue)
--------------------------------------------------------------------------*/
#define cNothing           ((U32) 0xFFFFFFFFU)
#define CAN_BUFFER_SIZE    ((U8)8U) // Size of CAN RX buffer (in bytes)

/*--------------------------------------------------------------------------
Local macros

  #define mMacroName   (MacroDefinition)
--------------------------------------------------------------------------*/



/*--------------------------------------------------------------------------
Local types

  struct  sStructureName { ... };
  union   uUnionName { ... };
  enum    eEnumerationName { ... };
  typedef Expression tTypeName;
--------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------
Local data

  static  tType   VariableName;
  static  tType*  pVariableName; 
--------------------------------------------------------------------------*/
static tAddress tSendAddress[cMaxMCUCANChaNum];
static BOOL bArrIsFirstInit[cMaxMCUCANChaNum];



/*--------------------------------------------------------------------------
Local function prototypes

  static tTypeRetour FunctionName(tTypeArgument1 ArgumentName1, ... );
--------------------------------------------------------------------------*/




/*--------------------------------------------------------------------------
Constant local data

  static const tType  VariableName;
--------------------------------------------------------------------------*/
static const U8 su8LogicToMCUCanBuf[cU8LogicCANMaxNum] =
{
    cU8MCUCAN0,  //LogicCAN0<->MCUCAN0
    cU8MCUCAN1,   //LogicCAN2<->MCUCAN1
    cU8MCUCAN2  //LogicCAN1<->MCUCAN2
};

static const U8 su8MCUToLogicCanBuf[cU8MCUCANMaxNum] =
{
    cLogicCAN0,         //LogicCAN0<->MCUCAN0
    cLogicCAN1,          //LogicCAN1<->MCUCAN2
    cLogicCAN2         //LogicCAN2<->MCUCAN1
};


/*--------------------------------------------------------------------------
Exported data

  tType   CMPVariableName;      (CMP: 3 characters to identify this component)
  tType*  pCMPVariableName;     (CMP: 3 characters to identify this component)
--------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------
Constant exported data

  const tType   CMPVariableName;(CMP: 3 characters to identify this component)
--------------------------------------------------------------------------*/



/*============================================================================
=========================== LOCAL FUNCTIONS ================================
==========================================================================*/

/*============================================================================
=========================== EXPORTED FUNCTIONS =============================
==========================================================================*/

/*============================================================================
  DESCRIPTION : 

  PARAMETERS (Type,Name,Min,Max) :  none
  
  RETURN VALUE :  none
    
  DESIGN INFORMATION :  refer to Detailed Design Document
============================================================================*/
void LDBCANInit(void)
{
    U8 u8Loop = 0U;

    for(u8Loop=0U;u8Loop<cMaxMCUCANChaNum;u8Loop++)
    {
        tSendAddress[u8Loop] = cNothing;
        bArrIsFirstInit[u8Loop] = cTrue;
    }
}



//==============================================================================
// DESCRIPTION : LDB_CAN initialization
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void LDBCanReceiveWithAddrStub( tAddress Address, tMsg* pMsg , U8 u8LogicCAN)
{
    U16 StatusReg = 0U;
    U8 u8MCUCANCh = 0U;

    mLIBassert(u8LogicCAN<cU8LogicCANMaxNum);
    u8MCUCANCh = su8LogicToMCUCanBuf[u8LogicCAN];

    switch(Address)
    {
        case cLDBCanAdrControllerSts:
            StatusReg = BSPCanGetCANStatus(u8MCUCANCh);
            pMsg->pBuffer[0U] = (U8)(StatusReg >> 8U);
            pMsg->pBuffer[1U] = (U8)(StatusReg >> 0U);
            break;
        default:
            break;
    }
}


void LDBCanSendWithAddrStub(U8 u8LogicCAN, tAddress Address, tMsg* pMsg )
{
    U8 u8MCUCANCh = 0U;
//    U32 u32Wait = 0;
//    U8 u8Loop = 0;
//    U32 u32DataHigh = 0;
//    U32 u32DataLow  = 0;
//    U32 u16AD1 = 0 ;
//    U32 u16AD2 = 0;
//    U32 u16AD3 = 0;
//    U32 u16AD4 = 0;


    mLIBassert(u8LogicCAN < cU8LogicCANMaxNum);
    u8MCUCANCh = su8LogicToMCUCanBuf[u8LogicCAN];

#define cTxResult_OK    0
    U8 u8TxResult = cTxResult_OK;
    tBSPCanSendMsg tSendMsgObj = {0};
    tSendMsgObj.u32Data0 = *((U32 *)&pMsg->pBuffer [0]);
    tSendMsgObj.u32Data1 = *((U32 *)&pMsg->pBuffer [4]);


    if((Address >> 12U) == 0U)
    {
    	tSendAddress[u8MCUCANCh] = (Address & 0x7FFU);
    	tSendMsgObj.u32MsgID = (Address & 0x7FFU);
    	tSendMsgObj.u8IsExtended = (U8)0U;
    }
    else
    {
    	tSendAddress[u8MCUCANCh] = Address;
    	tSendMsgObj.u32MsgID = Address;
    	tSendMsgObj.u8IsExtended = (U8)1U;
    }

    tSendMsgObj.u8Source = (U8)1U;//这个值应该是个宏，和BSP_CAN共享这个宏的定义，所以要定义二者间的类型导出协议
    tSendMsgObj.u8Len = (U8)(pMsg->Lng);


//    //ZJB just for AD test and send out from CAN1
//
//    //18FEF121,18FEF122=第一片的，按照AD通道计算

//	if(0x18FEF121 == Address)
//	{
//	   for(u8Loop = 0 ; u8Loop < 26; u8Loop++)
//	   {
//
//		   //这里将所有的数据都发出来，共104个U16数字，要占用22个消息.2个消息ID才可以发送一个4051上的所有数据
//		   extern U16  DATAnaBufferFromLDB[104];
//		   u16AD1 = DATAnaBufferFromLDB[0+u8Loop*4];
//		   u16AD2 = DATAnaBufferFromLDB[1+ u8Loop*4];
//		   u16AD3 = DATAnaBufferFromLDB[2+ u8Loop*4];
//		   u16AD4 = DATAnaBufferFromLDB[3+ u8Loop*4];
//
//		   u32DataLow = (u16AD2 << 16) + u16AD1;
//		   u32DataHigh = (u16AD4 << 16) + u16AD3;
//
//		   tSendMsgObj.u32Data0 =  u32DataLow;
//		   tSendMsgObj.u32Data1 = u32DataHigh;
//
//
//		   u8TxResult = BSPCanSendMsg(0, &tSendMsgObj);
//
//		   tSendMsgObj.u32MsgID++;
//		   if(u8TxResult != cTxResult_OK)
//		   {
//			   tSendAddress[0] = cNothing;
//		   }
//
//
//		   u32Wait = 10000;
//		   while(u32Wait)
//		   {u32Wait--;}
//
//		   TOSSchedule();
//	   }
//
//	}

    u8TxResult = BSPCanSendMsg(u8MCUCANCh, &tSendMsgObj);

    if(u8TxResult != 0U)
    {
        tSendAddress[u8MCUCANCh] = cNothing;
    }
}
/*============================================================================
  DESCRIPTION : 

  PARAMETERS (Type,Name,Min,Max) :  none
  
  RETURN VALUE :  none
    
  DESIGN INFORMATION :  refer to Detailed Design Document
============================================================================*/
void LDBCANControlStub(tCtrl Ctrl, U8 u8LogicCAN)
{
    tStatus Status;

    U8 u8MCUCANCh = 0U;


    mLIBassert(u8LogicCAN < cU8LogicCANMaxNum);

    u8MCUCANCh = su8LogicToMCUCanBuf[u8LogicCAN];

    Status = cLDBCorrect;

    switch(Ctrl)
    {
    case cLDBCanInit :
        if(bArrIsFirstInit[u8MCUCANCh] == cTrue)
        {
            bArrIsFirstInit[u8MCUCANCh] = cFalse;
            BSPCanInit(u8MCUCANCh);
        }
        else
        {
            BSPCanBusOffRecovery(u8MCUCANCh);
            DATMultiCanCallBackCtrl(u8LogicCAN,cLDBCanBusOn);

        }
        break;

    case cLDBCanStart :
        BSPCanStartCom(u8MCUCANCh);
        break;

    case cLDBCanStop :
        BSPCanStopCom(u8MCUCANCh);
        //设置管脚的功能,这里只设置一次，所以只在第2路CAN上调用
        if(u8MCUCANCh == 0U)
        {
        	(void)TOSReadSignal(cTOSSignalMCUWakeUpRequested);
        	BSPCanPinAsDIN();
        	BSPCanPinAsDIN_EnableINT();
        }

        break;

    case cLDBCanCancelTransmissionInProgress :
        BSPCanCancelTransmission(u8MCUCANCh);
        break;

    case cLDBCanEnableRxCallBack:
        BSPCanEnableRXINT(u8MCUCANCh);
        break;

    case cLDBCanDisableRxCallBack :
        BSPCanDisableRXINT(u8MCUCANCh);
        break;

     case cLDBCanEnableBus_offCallBack:
        BSPCanEnableBusOffINT(u8MCUCANCh);
        break;

    case cLDBCanDisableBus_offCallBack :
        BSPCanDisableBusOffINT(u8MCUCANCh);
        break;

    default:
        mLIBassert(cFalse); //unknown control
        break;
    }

    DATMultiCanCallBackEndCtrl(Ctrl,Status,u8LogicCAN);
}


#ifdef cMCUCANCh0
void LDBCan_MCUCANCh0_RxCBK(tBSPCanRxCBK* ptBSPCanRxCBK)
{
    U8 u8TempMsgArray [CAN_BUFFER_SIZE];
    tMsg Msg;

    *((U32 *)&u8TempMsgArray [0U]) = ptBSPCanRxCBK->u32Data0;
    *((U32 *)&u8TempMsgArray [4U]) = ptBSPCanRxCBK->u32Data1;
    Msg.Lng = 8U;
    Msg.pBuffer = u8TempMsgArray;
    //will call DATCdlReceptionMessageCAN

   DATCanRxSpontTable[ptBSPCanRxCBK->u8MsgHandle].pCallBackRx (ptBSPCanRxCBK->u32MsgID, cLDBCorrect, &Msg);

}

void LDBCan_MCUCANCh0_TxCBK(tBSPCanTxCBK*  pTxCBK)
{
    if ((cNothing != tSendAddress[pTxCBK->u8MCUCANCh]))
    {
        DATMultiCanCallBackTxWithAddr(pTxCBK->u8MCUCANCh,tSendAddress[pTxCBK->u8MCUCANCh], cLDBCorrect);
        tSendAddress[pTxCBK->u8MCUCANCh] = cNothing;
    }
}

void LDBCan_MCUCANCh0_BusOffCBK(tBSPCanErrCBK* pErrCBK)
{
    //禁止Error中断
    BSPCanDisableBusOffINT(pErrCBK->u8MCUCANCh);
    BSPCanCancelTransmission(pErrCBK->u8MCUCANCh);
    DATMultiCanCallBackCtrl(pErrCBK->u8MCUCANCh,cLDBCanBusOff);
}


#endif


#ifdef cMCUCANCh1
void LDBCan_MCUCANCh1_RxCBK(tBSPCanRxCBK* ptBSPCanRxCBK)
{
    U8 u8TempMsgArray [CAN_BUFFER_SIZE];
    tMsg Msg;

    *((U32 *)&u8TempMsgArray [0U]) = ptBSPCanRxCBK->u32Data0;
    *((U32 *)&u8TempMsgArray [4U]) = ptBSPCanRxCBK->u32Data1;
    Msg.Lng = 8U;
    Msg.pBuffer = u8TempMsgArray;

    //DATCdlReceptionMessageCAN
    DATCanRxSpontTable[ptBSPCanRxCBK->u8MsgHandle].pCallBackRx (ptBSPCanRxCBK->u32MsgID, cLDBCorrect, &Msg);

}

void LDBCan_MCUCANCh1_TxCBK(tBSPCanTxCBK*  pTxCBK)
{
    U8 u8LogicCAN = (U8)0U;

    if ((cNothing != tSendAddress[pTxCBK->u8MCUCANCh]))
    {
        mLIBassert(pTxCBK->u8MCUCANCh < cU8MCUCANMaxNum);
        u8LogicCAN = su8MCUToLogicCanBuf[pTxCBK->u8MCUCANCh];

        DATMultiCanCallBackTxWithAddr(u8LogicCAN,tSendAddress[pTxCBK->u8MCUCANCh], cLDBCorrect);
        tSendAddress[pTxCBK->u8MCUCANCh] = cNothing;
    }

}

void LDBCan_MCUCANCh1_BusOffCBK(tBSPCanErrCBK* pErrCBK)
{
    U8 u8LogicCAN = (U8)0U;

    mLIBassert(pErrCBK->u8MCUCANCh < cU8MCUCANMaxNum);
    u8LogicCAN = su8MCUToLogicCanBuf[pErrCBK->u8MCUCANCh];

    //禁止Error中断
    BSPCanDisableBusOffINT(pErrCBK->u8MCUCANCh);
    BSPCanCancelTransmission(pErrCBK->u8MCUCANCh);

    DATMultiCanCallBackCtrl(u8LogicCAN,cLDBCanBusOff);

}

#endif




#ifdef cMCUCANCh2

void LDBCan_MCUCANCh2_RxCBK(tBSPCanRxCBK* ptBSPCanRxCBK)
{
    U8 u8TempMsgArray [CAN_BUFFER_SIZE];
    tMsg Msg;

    *((U32 *)&u8TempMsgArray [0U]) = ptBSPCanRxCBK->u32Data0;
    *((U32 *)&u8TempMsgArray [4U]) = ptBSPCanRxCBK->u32Data1;
    Msg.Lng = 8U;
    Msg.pBuffer = u8TempMsgArray;

    //DATCdlReceptionMessageCAN
    DATCanRxSpontTable[ptBSPCanRxCBK->u8MsgHandle].pCallBackRx (ptBSPCanRxCBK->u32MsgID, cLDBCorrect, &Msg);

}

void LDBCan_MCUCANCh2_TxCBK(tBSPCanTxCBK*  pTxCBK)
{
    U8 u8LogicCAN = (U8)0U;

    if ((cNothing != tSendAddress[pTxCBK->u8MCUCANCh]))
    {
        mLIBassert(pTxCBK->u8MCUCANCh < cU8MCUCANMaxNum);
        u8LogicCAN = su8MCUToLogicCanBuf[pTxCBK->u8MCUCANCh];

        DATMultiCanCallBackTxWithAddr(u8LogicCAN,tSendAddress[pTxCBK->u8MCUCANCh], cLDBCorrect);
        tSendAddress[pTxCBK->u8MCUCANCh] = cNothing;
    }

}

void LDBCan_MCUCANCh2_BusOffCBK(tBSPCanErrCBK* pErrCBK)
{
    U8 u8LogicCAN = (U8)0U;

    mLIBassert(pErrCBK->u8MCUCANCh < cU8MCUCANMaxNum);
    u8LogicCAN = su8MCUToLogicCanBuf[pErrCBK->u8MCUCANCh];

    //禁止Error中断
    BSPCanDisableBusOffINT(pErrCBK->u8MCUCANCh);
    BSPCanCancelTransmission(pErrCBK->u8MCUCANCh);
    DATMultiCanCallBackCtrl(u8LogicCAN,cLDBCanBusOff);

}
#endif

//唤醒时调用
void LDBCanCanCallBackCtrl(U8 u8LogicCAN)
{
	DATMultiCanCallBackCtrl(u8LogicCAN,cLDBCanWakeUp);
}


void LDBDinCANWakeUpIsr(void)
{
	LDBCanCanCallBackCtrl(0U);
	TOSWriteSignal(cTOSSignalMCUWakeUpRequested);
	//当将CAN引脚作为DIN时的中断响应函数
	BSPCanPinAsDIN_DisableINT();
	BSPCanPinAsCANRx();
	TOSSendControl(cTOSControlWakeUpRequest);          //start CPU
}


