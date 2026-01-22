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

#ifndef _COM_CBK_H_
#define _COM_CBK_H_
/*******************************************************************************
*   Includes
*******************************************************************************/
 #include "Com.h"


/*******************************************************************************
*   Function Declaration 
*******************************************************************************/
#define COM_START_SEC_PUBLIC_CODE
//#include "MemMap.h"

#if (COM_TXIPDUNUM >= 1u) 

extern FUNC(void, COM_PUBLIC_CODE) Com_TxConfirmation
(
    PduIdType TxPduId
);

extern FUNC(BufReq_ReturnType, COM_PUBLIC_CODE) Com_CopyTxData
(
    PduIdType PduId, 
    P2CONST(PduInfoType, COM_APPL_DATA, COM_AUTOMOTIVE) PduInfoPtr,
    P2VAR(RetryInfoType, COM_APPL_DATA, COM_AUTOMOTIVE) RetryInfoPtr,
    P2VAR(PduLengthType, COM_APPL_DATA, COM_AUTOMOTIVE) TxDataCntPtr
);

extern FUNC(void, COM_PUBLIC_CODE) Com_TpTxConfirmation
(
    PduIdType PduId,
    NotifResultType Result
);

/*#if (COM_TXIPDUNUM >= 1u)*/
#endif

#if (COM_RXIPDUNUM >= 1u)

extern FUNC(void, COM_PUBLIC_CODE) Com_RxIndication
(
    PduIdType RxPduId,
    P2CONST(PduInfoType, COM_APPL_DATA, COM_AUTOMOTIVE) PduInfoPtr
);

extern FUNC(BufReq_ReturnType, COM_PUBLIC_CODE) Com_StartOfReception
(
    PduIdType ComRxPduId,
    PduLengthType TpSduLength,
    P2VAR(PduLengthType, COM_APPL_DATA, COM_AUTOMOTIVE) RxBufferSizePtr
);

extern FUNC(BufReq_ReturnType, COM_PUBLIC_CODE) Com_CopyRxData
(
    PduIdType PduId,
    P2CONST(PduInfoType, COM_APPL_DATA, COM_AUTOMOTIVE) PduInfoPointer,
    P2VAR(PduLengthType, COM_APPL_DATA, COM_AUTOMOTIVE) RxBufferSizePtr
);

extern FUNC(void, COM_PUBLIC_CODE) Com_TpRxIndication
(
    PduIdType PduId,
    NotifResultType Result
);

extern FUNC(Std_ReturnType, COM_PUBLIC_CODE) Com_TriggerTransmit
(
    PduIdType TxPduId,
    PduInfoType* PduInfoPtr
);


/*#if (COM_RXIPDUNUM >= 1u)*/
#endif

#define COM_STOP_SEC_PUBLIC_CODE
//#include "MemMap.h"

#endif



