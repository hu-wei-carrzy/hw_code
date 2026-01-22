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

#ifndef _CANIF_CBK_H_
#define _CANIF_CBK_H_

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "CanIf_Cfg.h"
#include "CanIf_Type.h"

/*******************************************************************************
*   Callback Function Declaration 
*******************************************************************************/
#define CANIF_START_SEC_PUBLIC_CODE
//#include "MemMap.h"

extern FUNC(void, CANIF_PUBLIC_CODE) CanIf_TxConfirmation
( 
    PduIdType CanTxPduId
);

extern FUNC(void, CANIF_PUBLIC_CODE) CanIf_RxIndication
( 
    Can_HwHandleType Hrh, 
    Can_IdType CanId,
    uint8 CanDlc,
    P2CONST(uint8, AUTOMATIC, CANIF_APPL_DATA) CanSduPtr
);
#if(CANIF_PUBLIC_CANCEL_TRANSMIT_SUPPORT == STD_ON) 
extern FUNC(void, CANIF_PUBLIC_CODE) CanIf_CancelTxConfirmation
( 
    P2CONST(Can_PduType, AUTOMATIC, CANIF_APPL_DATA) PduInfoPtr
);
#endif

extern FUNC(void, CANIF_PUBLIC_CODE) CanIf_ControllerBusOff
( 
    uint8 Controller 
);

extern FUNC(void, CANIF_PUBLIC_CODE) CanIf_ControllerWakeUp
( 
    uint8 Controller 
); 

extern FUNC(void, CANIF_PUBLIC_CODE) CanIf_ControllerModeIndication
( 
    uint8 Controller,
    CanIf_ControllerModeType ControllerMode
);

extern void AR422_CanIf_RxIndication
(
  const Can_HwType* Mailbox,
  const PduInfoType* PduInfoPtr
);

#define CANIF_STOP_SEC_PUBLIC_CODE
//#include "MemMap.h"
                           
#endif/* _CANIF_CBK_H_ */

