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

#ifndef _COM_H_
#define _COM_H_
/*******************************************************************************
*   Includes
*******************************************************************************/
 #include "ComStack_Types.h"
 #include "Com_Types.h"
 #include "Com_Cfg.h"

/*******************************************************************************
*   Function Declaration 
*******************************************************************************/
#define COM_START_SEC_PUBLIC_CODE
//#include "MemMap.h"

#define COM_VENDOR_ID             (uint16)(0xFFFFu)  /*Supplier ID */
#define COM_MODULE_ID             (uint16)(0x0023u)  /*CanTp Moudle ID */
#define COM_INSTANCE_ID           ((uint8)0)

/* CanTp Component release Version  */
#define COM_SW_MAJOR_VERSION      (uint8)(0x01u)
#define COM_SW_MINOR_VERSION      (uint8)(0x00u)
#define COM_SW_PATCH_VERSION      (uint8)(0x00u)
/* Autosar release version */
#define COM_AR_MAJOR_VERSION      (uint8)(0x04u)
#define COM_AR_MINOR_VERSION      (uint8)(0x00u)
#define COM_AR_PATCH_VERSION      (uint8)(0x00u)

#if(COM_VERSION_INFO_API == STD_ON)
extern FUNC(void,COM_PUBLIC_CODE) Com_GetVersionInfo
(
    P2VAR(Std_VersionInfoType,AUTOMATIC,COM_APPL_DATA) VersionInfo
);
#endif
extern FUNC(void, COM_PUBLIC_CODE) Com_Init
(
    void
);

extern FUNC(void, COM_PUBLIC_CODE) Com_IpduGroupControl
(
    Com_IpduGroupVector IpduGroupVector, 
    boolean Initialize
);


#if (COM_TXIPDUNUM >= 1u)

extern FUNC(void, COM_PUBLIC_CODE) Com_MainFunctionTx
( 
    void 
);

extern FUNC(void, COM_PUBLIC_CODE) Com_TxStart
( 
    void 
);

extern FUNC(void, COM_PUBLIC_CODE) Com_TxStop
( 
    void 
);

extern FUNC(void, COM_PUBLIC_CODE) Com_TriggerIPDUSend
(
    PduIdType PduId
);

#ifndef COM_ENABLE_NONSENDTYPEONLY
extern FUNC(void, COM_PUBLIC_CODE) Com_SetSendRequest
(
    Com_SignalIdType ComTxSignalId
);
#endif

extern FUNC(void, COM_PUBLIC_CODE) Com_StartTxIpdu
(
    PduIdType ComTxPduId
);

extern FUNC(void, COM_PUBLIC_CODE) Com_StopTxIpdu
(
    PduIdType ComTxPduId
);

extern FUNC(uint8, COM_PUBLIC_CODE) Com_GetTxIpduStatus
(
    PduIdType ComTxPduId
);

extern FUNC(uint8, COM_PUBLIC_CODE) Com_SendSignal
(
    Com_SignalIdType ComTxSignalId,
    P2CONST(void, COM_APPL_DATA, COM_AUTOMOTIVE) SignalDataPtr
);

/*#if (COM_TXIPDUNUM >= 1u)*/
#endif

#if (COM_RXIPDUNUM >= 1u)

extern FUNC(void, COM_PUBLIC_CODE) Com_MainFunctionRx
(
    void
);

extern FUNC(void, COM_PUBLIC_CODE)  Com_RxStart
(
    void
);

extern FUNC(void, COM_PUBLIC_CODE) Com_RxStop
( 
    void 
);

extern FUNC(void, COM_PUBLIC_CODE) Com_StartRxIpdu
(
    PduIdType ComRxPduId
);

extern FUNC(void, COM_PUBLIC_CODE) Com_StopRxIpdu
(
    PduIdType ComRxPduId
);

extern FUNC(uint8, COM_PUBLIC_CODE) Com_GetRxIpduStatus
(
    PduIdType ComRxPduId
);

extern FUNC(uint16, COM_PUBLIC_CODE) Com_GetRxIpduLength
(
    PduIdType ComRxPduId
);

extern FUNC(uint8, COM_PUBLIC_CODE) Com_ReceiveSignal
(
    Com_SignalIdType ComRxSignalId, 
    P2VAR(void, COM_APPL_DATA, COM_AUTOMOTIVE) SignalDataPtr
);

/*#if (COM_RXIPDUNUM >= 1u)*/
#endif


#ifdef COM_ENABLE_ROUTESIGNAL

#if(COM_GWSIGNUM >= 1u)

extern FUNC(void, COM_PUBLIC_CODE)  Com_MainFunctionRouteSignals
(
    void
);
/*
#if(COM_GWSIGNUM >= 1u)
*/
#endif
/*#ifdef COM_ENABLE_ROUTESIGNAL*/
#endif

#define COM_STOP_SEC_PUBLIC_CODE
//#include "MemMap.h"

#endif




