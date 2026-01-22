/*<WLEGHead>
|---------------------------------------------------------------------------------------------
| Project Name:     SAIC MIFA PLG
| File Name:       
|
|  Description:     
|
|---------------------------------------------------------------------------------------------
|                          All rights reserved
|---------------------------------------------------------------------------------------------
|
|                            CONFIDENTIAL
|
|
|---------------------------------------------------------------------------------------------
|                       R E V I S I O N   H I S T O R Y
|---------------------------------------------------------------------------------------------
| Date        Version   Author  Description
|                               Why                 What
| --------------------------------------------------------------------------------------------
| 02-12-2016  01.00      William Wei     Creation            First Version      
|---------------------------------------------------------------------------------------------
<WLEGHead>*/


/*******************************************************************************
*   Includes 
*******************************************************************************/
//#include "can_schedule.h"
#include "CanNm_Lcfg.h"
#define CANNM_START_SEC_VAR_NOINIT_UNSPECIFIED
//#include "MemMap.h"
VAR(Nm_StateType, CANNM_VAR_NOINIT) CanNm_State[CANNM_NUMBER_OF_CHANNELS];
VAR(uint8, CANNM_VAR_NOINIT) CanNm_TxPduBuff[CANNM_NUMBER_OF_CHANNELS][CANNM_PDU_LENGTH];
VAR(PduInfoType, CANNM_VAR_NOINIT) CanNm_TxPdu[CANNM_NUMBER_OF_CHANNELS];
VAR(uint8, CANNM_VAR_NOINIT) CanNm_RxPduBuff[CANNM_NUMBER_OF_CHANNELS][CANNM_PDU_LENGTH];
VAR(PduInfoType, CANNM_VAR_NOINIT) CanNm_RxPdu[CANNM_NUMBER_OF_CHANNELS];
VAR(Nm_ModeType, CANNM_VAR_NOINIT) CanNm_Mode[CANNM_NUMBER_OF_CHANNELS];
VAR(CanNm_NetworkStateType, CANNM_VAR_NOINIT) CanNm_NetworkState[CANNM_NUMBER_OF_CHANNELS];
/*[SWS_CanNm_00257]*//*[SWS_CanNm_00260]*/
VAR(boolean, CANNM_VAR_NOINIT) CanNm_MsgTxEnabled[CANNM_NUMBER_OF_CHANNELS];
STATIC VAR(uint16, CANNM_VAR_NOINIT) CanNm_MsgCycOffsetTimer[CANNM_NUMBER_OF_CHANNELS];
STATIC VAR(uint16, CANNM_VAR_NOINIT) CanNm_MsgCycTimer[CANNM_NUMBER_OF_CHANNELS];
VAR(uint8, CANNM_VAR_NOINIT) CanNm_ImmTrans[CANNM_NUMBER_OF_CHANNELS];
VAR(boolean, CANNM_VAR_NOINIT) CanNm_TxCfmFlg[CANNM_NUMBER_OF_CHANNELS];
VAR(boolean, CANNM_VAR_NOINIT) CanNm_TxReqFlg[CANNM_NUMBER_OF_CHANNELS];
VAR(boolean, CANNM_VAR_NOINIT) CanNm_RxIndFlg[CANNM_NUMBER_OF_CHANNELS];
VAR(boolean, CANNM_VAR_NOINIT) CanNm_RptMsgReq[CANNM_NUMBER_OF_CHANNELS];
VAR(boolean, CANNM_VAR_NOINIT) CanNm_RptMsgReqBit[CANNM_NUMBER_OF_CHANNELS];
VAR(CanNm_NetworkReqType, CANNM_VAR_NOINIT) CanNm_NetworkReqCmd[CANNM_NUMBER_OF_CHANNELS];
STATIC VAR(uint16, CANNM_VAR_NOINIT) CanNm_NmTOTimer[CANNM_NUMBER_OF_CHANNELS];
STATIC VAR(uint16, CANNM_VAR_NOINIT) CanNm_RptMsgTimer[CANNM_NUMBER_OF_CHANNELS];
STATIC VAR(uint16, CANNM_VAR_NOINIT) CanNm_WbsTimer[CANNM_NUMBER_OF_CHANNELS];
STATIC VAR(uint16, CANNM_VAR_NOINIT) CanNm_TxTOTimer[CANNM_NUMBER_OF_CHANNELS];
VAR(CanNm_MsgTxRptType, CANNM_VAR_NOINIT)  CanNm_MsgTxRptCmd[CANNM_NUMBER_OF_CHANNELS];

#if(CANNM_COM_CONTROL_ENABLED == STD_ON)
VAR(boolean, CANNM_VAR_NOINIT) CanNm_ComTxEnabled[CANNM_NUMBER_OF_CHANNELS];
#endif

#define CANNM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
//#include "MemMap.h"

#define CANNM_START_SEC_CONFIG_DATA_UNSPECIFIED
//#include "MemMap.h"
CONST(CanNm_LConfigType, CANNM_CONST) CanNm_LConfig[CANNM_NUMBER_OF_CHANNELS] =
{
    {
        ((boolean)STD_OFF),                                  /*CanNmActiveWakeupBitEnabled*/
        ((boolean)STD_OFF),                                 /*CanNmAllNmMessagesKeepAwake*/
        ((uint8)0),                                         /*CanNmCarWakeUpBitPosition*/
        ((uint8)0),                                         /*CanNmCarWakeUpBytePosition*/
        ((boolean)STD_OFF),                                 /*CanNmCarWakeUpFilterEnabled*/
        ((uint8)0u),                                        /*CanNmCarWakeUpFilterNodeId*/
        ((boolean)STD_OFF),                                 /*CanNmCarWakeUpRxEnabled*/
        ((uint16)2),                                        /*CanNmImmediateNmCycleTime*/
        ((uint8)10u),                                        /*CanNmImmediateNmTransmissions*/
        ((uint16)1u),                                        /*CanNmMsgCycleOffset*/
        ((uint16)100u),                                      /*CanNmMsgCycleTime*/
        ((uint16)10u),                                        /*CanNmMsgTimeoutTime*/
        CANNM_PDU_BYTE_1,                                   /*CanNmPduCbvPosition*/
        CANNM_PDU_BYTE_0,                                   /*CanNmPduNidPosition*/
        ((uint16)300u),                                      /*CanNmRepeatMessageTime*/
        ((boolean)STD_OFF),                                 /*CanNmRetryFirstMessageRequest*/
        ((uint16)250u),                                      /*CanNmTimeoutTime*/
	
        ((uint16)1500u),                                      /*CanNmWaitBusSleepTime*/
        ((NetworkHandleType)0u),                             /*CanNmComMNetworkHandleRef*/
    },
};


CONST(CanNm_TimerType, CANNM_CONST) CanNm_Timer[CANNM_NUMBER_OF_CHANNELS] =
{
    {
        {&CanNm_MsgCycOffsetTimer[0]},
        {&CanNm_MsgCycTimer[0]},
        {&CanNm_TxTOTimer[0]},
        {&CanNm_NmTOTimer[0]},
        {&CanNm_RptMsgTimer[0]},
        {&CanNm_WbsTimer[0]},
    },
};


CONST(CanNm_ConfigType, CANNM_CONST) CanNm_Config[CANNM_NUMBER_OF_CHANNELS] =
{
#if  E0X_DCM == E0X_DCM_FL
    {0x33, 4},
#elif  E0X_DCM == E0X_DCM_FR
    {0x59, 4},
#elif  E0X_DCM == E0X_DCM_RL
    {0x5A, 4},
#elif  E0X_DCM == E0X_DCM_RR
    {0x5B, 4},    
#else
#error "the define E0X_DCM is error!"
#endif 
};

#define CANNM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
//#include "MemMap.h"



