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

#ifndef _CANNM_LCFG_H_
#define _CANNM_LCFG_H_

/*******************************************************************************
*   Includes 
*******************************************************************************/
#include "CanNm_Types.h"
//#include "can_schedule.h"
#define CANNM_PDU_LENGTH                                    ((uint8)8u)

#if  E0X_DCM == E0X_DCM_FL
#define CANNM_CH0_NODE_ID                                   ((uint8)0x33)
#elif  E0X_DCM == E0X_DCM_FR
#define CANNM_CH0_NODE_ID                                   ((uint8)0x59)
#elif  E0X_DCM == E0X_DCM_RL
#define CANNM_CH0_NODE_ID                                   ((uint8)0x5A)
#elif  E0X_DCM == E0X_DCM_RR
#define CANNM_CH0_NODE_ID                                   ((uint8)0x5B)
#else
#error "the define E0X_DCM is error!"
#endif 

#define CANNM_CH0_TX_PDU_ID                                 ((uint8)0u)


#define CANNM_CHANNELNUM       CANNM_NUMBER_OF_CHANNELS
#define CANNM_START_SEC_CONFIG_DATA_UNSPECIFIED
//#include "MemMap.h"
extern CONST(CanNm_ConfigType, CANNM_CONST) CanNm_Config[CANNM_NUMBER_OF_CHANNELS];
extern CONST(CanNm_LConfigType, CANNM_CONST) CanNm_LConfig[CANNM_NUMBER_OF_CHANNELS];
extern CONST(CanNm_TimerType, CANNM_CONST) CanNm_Timer[CANNM_NUMBER_OF_CHANNELS];
#define CANNM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
//#include "MemMap.h"
#define CANNM_START_SEC_VAR_NOINIT_UNSPECIFIED
//#include "MemMap.h"
extern VAR(Nm_StateType, CANNM_VAR_NOINIT) CanNm_State[CANNM_NUMBER_OF_CHANNELS];
extern VAR(uint8, CANNM_VAR_NOINIT) CanNm_TxPduBuff[CANNM_NUMBER_OF_CHANNELS][CANNM_PDU_LENGTH];
extern VAR(PduInfoType, CANNM_VAR_NOINIT) CanNm_TxPdu[CANNM_NUMBER_OF_CHANNELS];
extern VAR(uint8, CANNM_VAR_NOINIT) CanNm_RxPduBuff[CANNM_NUMBER_OF_CHANNELS][CANNM_PDU_LENGTH];
extern VAR(PduInfoType, CANNM_VAR_NOINIT) CanNm_RxPdu[CANNM_NUMBER_OF_CHANNELS];
extern VAR(Nm_ModeType, CANNM_VAR_NOINIT) CanNm_Mode[CANNM_NUMBER_OF_CHANNELS];
extern VAR(CanNm_NetworkStateType, CANNM_VAR_NOINIT) CanNm_NetworkState[CANNM_NUMBER_OF_CHANNELS];
/*[SWS_CanNm_00257]*//*[SWS_CanNm_00260]*/
extern VAR(boolean, CANNM_VAR_NOINIT) CanNm_MsgTxEnabled[CANNM_NUMBER_OF_CHANNELS];
extern VAR(uint8, CANNM_VAR_NOINIT) CanNm_ImmTrans[CANNM_NUMBER_OF_CHANNELS];
extern VAR(boolean, CANNM_VAR_NOINIT) CanNm_TxCfmFlg[CANNM_NUMBER_OF_CHANNELS];
extern VAR(boolean, CANNM_VAR_NOINIT) CanNm_TxReqFlg[CANNM_NUMBER_OF_CHANNELS];
extern VAR(boolean, CANNM_VAR_NOINIT) CanNm_RxIndFlg[CANNM_NUMBER_OF_CHANNELS];
extern VAR(boolean, CANNM_VAR_NOINIT) CanNm_RptMsgReq[CANNM_NUMBER_OF_CHANNELS];
extern VAR(boolean, CANNM_VAR_NOINIT) CanNm_RptMsgReqBit[CANNM_NUMBER_OF_CHANNELS];
extern VAR(CanNm_NetworkReqType, CANNM_VAR_NOINIT) CanNm_NetworkReqCmd[CANNM_NUMBER_OF_CHANNELS];
extern VAR(CanNm_MsgTxRptType, CANNM_VAR_NOINIT)  CanNm_MsgTxRptCmd[CANNM_NUMBER_OF_CHANNELS];

#if(CANNM_COM_CONTROL_ENABLED == STD_ON)
extern VAR(boolean, CANNM_VAR_NOINIT) CanNm_ComTxEnabled[CANNM_NUMBER_OF_CHANNELS];
#endif

#define CANNM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
//#include "MemMap.h"
#endif


