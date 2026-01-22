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
#include "../CanIf/CanIf.h"
//#include "CanTp_Cbk.h"
#include "CanNm_Cbk.h"
#include "Com_Cbk.h"
//#include "XcpOnCan_Cbk.h"
//#include "pinout_manage.h"
//#include "can_schedule.h"
/*******************************************************************************
*   Macro
*******************************************************************************/

#define CANIF_CFG_TOTAL_TXPDUID             (7)  
#define CANIF_CFG_TOTAL_RXPDUID             (43)  

#if (STD_ON == CANIF_RX_PDU_RANGE_CANID) 
    #define CANIF_CFG_RANGE_CANID_RXPDUID   (1)
#endif
#define CANIF_CFG_TOTAL_HRH                 (1)  

/*******************************************************************************
*   Global Data Define, No need to be configed 
*******************************************************************************/
#define CANIF_START_SEC_VAR_UNSPECIFIED 
//#include "MemMap.h"

#if (STD_ON == CANIF_PUBLIC_TX_BUFFERING)
    VAR(boolean, CANIF_PRIVATE_DATA) 
                              CanIfTxBufferPDUFillflag[CANIF_CFG_TOTAL_TXPDUID];

    VAR(uint8, CANIF_PRIVATE_DATA)
                        CanIfTxBufferSdu[CANIF_CFG_TOTAL_TXPDUID][CAN_DATA_DLC];

    VAR(Can_PduType, CANIF_PRIVATE_DATA) 
                                      CanIfTxBufferPdu[CANIF_CFG_TOTAL_TXPDUID];
#endif

#if (STD_ON == CANIF_PUBLIC_SETDYNAMICTXID_API)
    VAR(Can_IdType, CANIF_PRIVATE_DATA) 
                             CanIfTxPduCanIdForDynamic[CANIF_CFG_TOTAL_TXPDUID]; 
#endif 

#if(STD_ON == CANIF_PUBLIC_READTXPDU_NOTIFY_STATUS_API)
    VAR(CanIf_NotifStatusType, CANIF_PRIVATE_DATA)
                                    CanIfTxNotifStatus[CANIF_CFG_TOTAL_TXPDUID];
#endif 

#if(STD_ON == CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API) 
    VAR(CanIf_NotifStatusType, CANIF_PRIVATE_DATA)
                                    CanIfRxNotifStatus[CANIF_CFG_TOTAL_RXPDUID];
#endif

#if (STD_ON == CANIF_PUBLIC_READRXPDU_DATA_API)
    VAR(uint8, CANIF_PRIVATE_DATA) 
                    CanIfRxBufferSduData[CANIF_CFG_TOTAL_RXPDUID][CAN_DATA_DLC];
    VAR(PduLengthType, CANIF_PRIVATE_DATA) 
                                CanIfRxBufferSduLength[CANIF_CFG_TOTAL_RXPDUID];
#endif

#define CANIF_STOP_SEC_VAR_UNSPECIFIED
//#include "MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
//#include "MemMap.h"
CONST(PduIdType, CANIF_CONFIG_CONST) CanIfInitNumberOfCanRxPduIds 
                                                      = CANIF_CFG_TOTAL_RXPDUID;
CONST(PduIdType, CANIF_CONFIG_CONST) CanIfInitNumberOfCanTxPduIds 
                                                      = CANIF_CFG_TOTAL_TXPDUID;
CONST(Can_HwHandleType, CANIF_CONFIG_CONST) CanIfInitNumberofHrh 
                                                          = CANIF_CFG_TOTAL_HRH;

/*******************************************************************************
*   Config Parameters   
*******************************************************************************/

#if (STD_ON == CANIF_RX_PDU_RANGE_CANID)
CONST(CanIf_RxPduCanIdRangeType, CANIF_CONFIG_CONST) 
                         CanIfRxPduCanIdRangeConfig[CANIF_CFG_RANGE_CANID_RXPDUID] = 
{
    {
        0x600U,
        0x67FU,
        CanNm_RxIndication
    },
}; 
#endif 

CONST(CanIf_RxPduConfigType, CANIF_CONFIG_CONST)
                         CanIfRxPduConfig[CANIF_CFG_TOTAL_RXPDUID] =
{
    /* 0 */
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        0,    /* CanIfRxPduUpperLayerHandle */
        #endif

        0x21U, /* CanId*/
        STANDARD_CAN, /* CanIdType */
        0, /* CanIfRxPduHrhIdRef */
        8, /* CanIfRxPduDlc */
        Com_RxIndication, /* CanIfRxPduUserRxIndicationName */
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API)
        FALSE, /* CanIfRxPduReadNotifyStatus */
        #endif
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_DATA_API)
        FALSE, /* CanIfRxPduReadData */
        #endif
        #if(STD_ON == CANIF_RX_PDU_RANGE_CANID)
        NULL_PTR, /* CanIfRxPduRangePtr */
        #endif
        #if(CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE)
        1, /* CanIfRxPduNextHrh */
        #endif
    },
     /* 1 */
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        1,    /* CanIfRxPduUpperLayerHandle */
        #endif

        0x31U, /* CanId*/
        STANDARD_CAN, /* CanIdType */
        0, /* CanIfRxPduHrhIdRef */
        8, /* CanIfRxPduDlc */
        Com_RxIndication, /* CanIfRxPduUserRxIndicationName */
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API)
        FALSE, /* CanIfRxPduReadNotifyStatus */
        #endif
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_DATA_API)
        FALSE, /* CanIfRxPduReadData */
        #endif
        #if(STD_ON == CANIF_RX_PDU_RANGE_CANID)
        NULL_PTR, /* CanIfRxPduRangePtr */
        #endif
        #if(CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE)
        2, /* CanIfRxPduNextHrh */
        #endif
    },
         /* 2 */
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        2,    /* CanIfRxPduUpperLayerHandle */
        #endif

        0x23BU, /* CanId*/
        STANDARD_CAN, /* CanIdType */
        0, /* CanIfRxPduHrhIdRef */
        8, /* CanIfRxPduDlc */
        Com_RxIndication, /* CanIfRxPduUserRxIndicationName */
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API)
        FALSE, /* CanIfRxPduReadNotifyStatus */
        #endif
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_DATA_API)
        FALSE, /* CanIfRxPduReadData */
        #endif
        #if(STD_ON == CANIF_RX_PDU_RANGE_CANID)
        NULL_PTR, /* CanIfRxPduRangePtr */
        #endif
        #if(CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE)
        3, /* CanIfRxPduNextHrh */
        #endif
    },
     /* 3 */
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        3,    /* CanIfRxPduUpperLayerHandle */
        #endif

        0x258U, /* CanId*/
        STANDARD_CAN, /* CanIdType */
        0, /* CanIfRxPduHrhIdRef */
        8, /* CanIfRxPduDlc */
        Com_RxIndication, /* CanIfRxPduUserRxIndicationName */
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API)
        FALSE, /* CanIfRxPduReadNotifyStatus */
        #endif
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_DATA_API)
        FALSE, /* CanIfRxPduReadData */
        #endif
        #if(STD_ON == CANIF_RX_PDU_RANGE_CANID)
        NULL_PTR, /* CanIfRxPduRangePtr */
        #endif
        #if(CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE)
        4, /* CanIfRxPduNextHrh */
        #endif
    },
     /* 4 */
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        4,    /* CanIfRxPduUpperLayerHandle */
        #endif

        0x2A0U, /* CanId*/
        STANDARD_CAN, /* CanIdType */
        0, /* CanIfRxPduHrhIdRef */
        8, /* CanIfRxPduDlc */
        Com_RxIndication, /* CanIfRxPduUserRxIndicationName */
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API)
        FALSE, /* CanIfRxPduReadNotifyStatus */
        #endif
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_DATA_API)
        FALSE, /* CanIfRxPduReadData */
        #endif
        #if(STD_ON == CANIF_RX_PDU_RANGE_CANID)
        NULL_PTR, /* CanIfRxPduRangePtr */
        #endif
        #if(CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE)
        5, /* CanIfRxPduNextHrh */
        #endif
    },
    /* 5 */
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        5,    /* CanIfRxPduUpperLayerHandle */
        #endif

        0x2ABU, /* CanId*/
        STANDARD_CAN, /* CanIdType */
        0, /* CanIfRxPduHrhIdRef */
        8, /* CanIfRxPduDlc */
        Com_RxIndication, /* CanIfRxPduUserRxIndicationName */
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API)
        FALSE, /* CanIfRxPduReadNotifyStatus */
        #endif
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_DATA_API)
        FALSE, /* CanIfRxPduReadData */
        #endif
        #if(STD_ON == CANIF_RX_PDU_RANGE_CANID)
        NULL_PTR, /* CanIfRxPduRangePtr */
        #endif
        #if(CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE)
        6, /* CanIfRxPduNextHrh */
        #endif
    },
       /* 6 */
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        6,    /* CanIfRxPduUpperLayerHandle */
        #endif

        0x2BBU, /* CanId*/
        STANDARD_CAN, /* CanIdType */
        0, /* CanIfRxPduHrhIdRef */
        8, /* CanIfRxPduDlc */
        Com_RxIndication, /* CanIfRxPduUserRxIndicationName */
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API)
        FALSE, /* CanIfRxPduReadNotifyStatus */
        #endif
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_DATA_API)
        FALSE, /* CanIfRxPduReadData */
        #endif
        #if(STD_ON == CANIF_RX_PDU_RANGE_CANID)
        NULL_PTR, /* CanIfRxPduRangePtr */
        #endif
        #if(CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE)
        7, /* CanIfRxPduNextHrh */
        #endif
    },
#if  E0X_DCM == E0X_DCM_FL
     /* 7 */
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        7,    /* CanIfRxPduUpperLayerHandle */
        #endif

        0x2D1U, /* CanId*/
        STANDARD_CAN, /* CanIdType */
        0, /* CanIfRxPduHrhIdRef */
        8, /* CanIfRxPduDlc */
        Com_RxIndication, /* CanIfRxPduUserRxIndicationName */
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API)
        FALSE, /* CanIfRxPduReadNotifyStatus */
        #endif
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_DATA_API)
        FALSE, /* CanIfRxPduReadData */
        #endif
        #if(STD_ON == CANIF_RX_PDU_RANGE_CANID)
        NULL_PTR, /* CanIfRxPduRangePtr */
        #endif
        #if(CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE)
        8, /* CanIfRxPduNextHrh */
        #endif
    },
         /* 8 */
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        8,    /* CanIfRxPduUpperLayerHandle */
        #endif

        0x2DBU, /* CanId*/
        STANDARD_CAN, /* CanIdType */
        0, /* CanIfRxPduHrhIdRef */
        8, /* CanIfRxPduDlc */
        Com_RxIndication, /* CanIfRxPduUserRxIndicationName */
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API)
        FALSE, /* CanIfRxPduReadNotifyStatus */
        #endif
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_DATA_API)
        FALSE, /* CanIfRxPduReadData */
        #endif
        #if(STD_ON == CANIF_RX_PDU_RANGE_CANID)
        NULL_PTR, /* CanIfRxPduRangePtr */
        #endif
        #if(CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE)
        9, /* CanIfRxPduNextHrh */
        #endif
    },
         /* 9 */
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        9,    /* CanIfRxPduUpperLayerHandle */
        #endif

        0x2E1U, /* CanId*/
        STANDARD_CAN, /* CanIdType */
        0, /* CanIfRxPduHrhIdRef */
        8, /* CanIfRxPduDlc */
        Com_RxIndication, /* CanIfRxPduUserRxIndicationName */
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API)
        FALSE, /* CanIfRxPduReadNotifyStatus */
        #endif
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_DATA_API)
        FALSE, /* CanIfRxPduReadData */
        #endif
        #if(STD_ON == CANIF_RX_PDU_RANGE_CANID)
        NULL_PTR, /* CanIfRxPduRangePtr */
        #endif
        #if(CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE)
        10, /* CanIfRxPduNextHrh */
        #endif
    },
#elif  E0X_DCM == E0X_DCM_FR
    /* 7 */
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        7,    /* CanIfRxPduUpperLayerHandle */
        #endif

        0x2D6U, /* CanId*/
        STANDARD_CAN, /* CanIdType */
        0, /* CanIfRxPduHrhIdRef */
        8, /* CanIfRxPduDlc */
        Com_RxIndication, /* CanIfRxPduUserRxIndicationName */
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API)
        FALSE, /* CanIfRxPduReadNotifyStatus */
        #endif
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_DATA_API)
        FALSE, /* CanIfRxPduReadData */
        #endif
        #if(STD_ON == CANIF_RX_PDU_RANGE_CANID)
        NULL_PTR, /* CanIfRxPduRangePtr */
        #endif
        #if(CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE)
        8, /* CanIfRxPduNextHrh */
        #endif
    },
         /* 8 */
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        8,    /* CanIfRxPduUpperLayerHandle */
        #endif

        0x2DEU, /* CanId*/
        STANDARD_CAN, /* CanIdType */
        0, /* CanIfRxPduHrhIdRef */
        8, /* CanIfRxPduDlc */
        Com_RxIndication, /* CanIfRxPduUserRxIndicationName */
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API)
        FALSE, /* CanIfRxPduReadNotifyStatus */
        #endif
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_DATA_API)
        FALSE, /* CanIfRxPduReadData */
        #endif
        #if(STD_ON == CANIF_RX_PDU_RANGE_CANID)
        NULL_PTR, /* CanIfRxPduRangePtr */
        #endif
        #if(CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE)
        9, /* CanIfRxPduNextHrh */
        #endif
    },
         /* 9 */
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        9,    /* CanIfRxPduUpperLayerHandle */
        #endif

        0x2E5U, /* CanId*/
        STANDARD_CAN, /* CanIdType */
        0, /* CanIfRxPduHrhIdRef */
        8, /* CanIfRxPduDlc */
        Com_RxIndication, /* CanIfRxPduUserRxIndicationName */
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API)
        FALSE, /* CanIfRxPduReadNotifyStatus */
        #endif
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_DATA_API)
        FALSE, /* CanIfRxPduReadData */
        #endif
        #if(STD_ON == CANIF_RX_PDU_RANGE_CANID)
        NULL_PTR, /* CanIfRxPduRangePtr */
        #endif
        #if(CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE)
        10, /* CanIfRxPduNextHrh */
        #endif
    },
#elif  E0X_DCM == E0X_DCM_RL
    /* 7 */
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        7,    /* CanIfRxPduUpperLayerHandle */
        #endif

        0x2D1U, /* CanId*/
        STANDARD_CAN, /* CanIdType */
        0, /* CanIfRxPduHrhIdRef */
        8, /* CanIfRxPduDlc */
        Com_RxIndication, /* CanIfRxPduUserRxIndicationName */
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API)
        FALSE, /* CanIfRxPduReadNotifyStatus */
        #endif
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_DATA_API)
        FALSE, /* CanIfRxPduReadData */
        #endif
        #if(STD_ON == CANIF_RX_PDU_RANGE_CANID)
        NULL_PTR, /* CanIfRxPduRangePtr */
        #endif
        #if(CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE)
        8, /* CanIfRxPduNextHrh */
        #endif
    },
         /* 8 */
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        8,    /* CanIfRxPduUpperLayerHandle */
        #endif

        0x2DBU, /* CanId*/
        STANDARD_CAN, /* CanIdType */
        0, /* CanIfRxPduHrhIdRef */
        8, /* CanIfRxPduDlc */
        Com_RxIndication, /* CanIfRxPduUserRxIndicationName */
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API)
        FALSE, /* CanIfRxPduReadNotifyStatus */
        #endif
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_DATA_API)
        FALSE, /* CanIfRxPduReadData */
        #endif
        #if(STD_ON == CANIF_RX_PDU_RANGE_CANID)
        NULL_PTR, /* CanIfRxPduRangePtr */
        #endif
        #if(CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE)
        9, /* CanIfRxPduNextHrh */
        #endif
    },
         /* 9 */
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        9,    /* CanIfRxPduUpperLayerHandle */
        #endif

        0x2E8U, /* CanId*/
        STANDARD_CAN, /* CanIdType */
        0, /* CanIfRxPduHrhIdRef */
        8, /* CanIfRxPduDlc */
        Com_RxIndication, /* CanIfRxPduUserRxIndicationName */
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API)
        FALSE, /* CanIfRxPduReadNotifyStatus */
        #endif
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_DATA_API)
        FALSE, /* CanIfRxPduReadData */
        #endif
        #if(STD_ON == CANIF_RX_PDU_RANGE_CANID)
        NULL_PTR, /* CanIfRxPduRangePtr */
        #endif
        #if(CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE)
        10, /* CanIfRxPduNextHrh */
        #endif
    },
#elif  E0X_DCM == E0X_DCM_RR
    /* 7 */
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        7,    /* CanIfRxPduUpperLayerHandle */
        #endif

        0x2D6U, /* CanId*/
        STANDARD_CAN, /* CanIdType */
        0, /* CanIfRxPduHrhIdRef */
        8, /* CanIfRxPduDlc */
        Com_RxIndication, /* CanIfRxPduUserRxIndicationName */
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API)
        FALSE, /* CanIfRxPduReadNotifyStatus */
        #endif
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_DATA_API)
        FALSE, /* CanIfRxPduReadData */
        #endif
        #if(STD_ON == CANIF_RX_PDU_RANGE_CANID)
        NULL_PTR, /* CanIfRxPduRangePtr */
        #endif
        #if(CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE)
        8, /* CanIfRxPduNextHrh */
        #endif
    },
         /* 8 */
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        8,    /* CanIfRxPduUpperLayerHandle */
        #endif

        0x2DEU, /* CanId*/
        STANDARD_CAN, /* CanIdType */
        0, /* CanIfRxPduHrhIdRef */
        8, /* CanIfRxPduDlc */
        Com_RxIndication, /* CanIfRxPduUserRxIndicationName */
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API)
        FALSE, /* CanIfRxPduReadNotifyStatus */
        #endif
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_DATA_API)
        FALSE, /* CanIfRxPduReadData */
        #endif
        #if(STD_ON == CANIF_RX_PDU_RANGE_CANID)
        NULL_PTR, /* CanIfRxPduRangePtr */
        #endif
        #if(CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE)
        9, /* CanIfRxPduNextHrh */
        #endif
    },
         /* 9 */
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        9,    /* CanIfRxPduUpperLayerHandle */
        #endif

        0x2ECU, /* CanId*/
        STANDARD_CAN, /* CanIdType */
        0, /* CanIfRxPduHrhIdRef */
        8, /* CanIfRxPduDlc */
        Com_RxIndication, /* CanIfRxPduUserRxIndicationName */
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API)
        FALSE, /* CanIfRxPduReadNotifyStatus */
        #endif
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_DATA_API)
        FALSE, /* CanIfRxPduReadData */
        #endif
        #if(STD_ON == CANIF_RX_PDU_RANGE_CANID)
        NULL_PTR, /* CanIfRxPduRangePtr */
        #endif
        #if(CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE)
        10, /* CanIfRxPduNextHrh */
        #endif
    },
#else
#error "the define E0X_DCM is error!"
#endif
    /* 10 */
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        10,    /* CanIfRxPduUpperLayerHandle */
        #endif

        0x308U, /* CanId*/
        STANDARD_CAN, /* CanIdType */
        0, /* CanIfRxPduHrhIdRef */
        8, /* CanIfRxPduDlc */
        Com_RxIndication, /* CanIfRxPduUserRxIndicationName */
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API)
        FALSE, /* CanIfRxPduReadNotifyStatus */
        #endif
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_DATA_API)
        FALSE, /* CanIfRxPduReadData */
        #endif
        #if(STD_ON == CANIF_RX_PDU_RANGE_CANID)
        NULL_PTR, /* CanIfRxPduRangePtr */
        #endif
        #if(CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE)
        11, /* CanIfRxPduNextHrh */
        #endif
    },
    /* 11 */
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        11,    /* CanIfRxPduUpperLayerHandle */
        #endif

        0x343U, /* CanId*/
        STANDARD_CAN, /* CanIdType */
        0, /* CanIfRxPduHrhIdRef */
        8, /* CanIfRxPduDlc */
        Com_RxIndication, /* CanIfRxPduUserRxIndicationName */
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API)
        FALSE, /* CanIfRxPduReadNotifyStatus */
        #endif
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_DATA_API)
        FALSE, /* CanIfRxPduReadData */
        #endif
        #if(STD_ON == CANIF_RX_PDU_RANGE_CANID)
        NULL_PTR, /* CanIfRxPduRangePtr */
        #endif
        #if(CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE)
        12, /* CanIfRxPduNextHrh */
        #endif
    },
    /* 12 */
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        12,    /* CanIfRxPduUpperLayerHandle */
        #endif

        0x347U, /* CanId*/
        STANDARD_CAN, /* CanIdType */
        0, /* CanIfRxPduHrhIdRef */
        8, /* CanIfRxPduDlc */
        Com_RxIndication, /* CanIfRxPduUserRxIndicationName */
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API)
        FALSE, /* CanIfRxPduReadNotifyStatus */
        #endif
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_DATA_API)
        FALSE, /* CanIfRxPduReadData */
        #endif
        #if(STD_ON == CANIF_RX_PDU_RANGE_CANID)
        NULL_PTR, /* CanIfRxPduRangePtr */
        #endif
        #if(CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE)
        13, /* CanIfRxPduNextHrh */
        #endif
    },
    /* 13 */
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        13,    /* CanIfRxPduUpperLayerHandle */
        #endif

        0x34fU, /* CanId*/
        STANDARD_CAN, /* CanIdType */
        0, /* CanIfRxPduHrhIdRef */
        8, /* CanIfRxPduDlc */
        Com_RxIndication, /* CanIfRxPduUserRxIndicationName */
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API)
        FALSE, /* CanIfRxPduReadNotifyStatus */
        #endif
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_DATA_API)
        FALSE, /* CanIfRxPduReadData */
        #endif
        #if(STD_ON == CANIF_RX_PDU_RANGE_CANID)
        NULL_PTR, /* CanIfRxPduRangePtr */
        #endif
        #if(CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE)
        14, /* CanIfRxPduNextHrh */
        #endif
    },
    /* 14 */
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        14,    /* CanIfRxPduUpperLayerHandle */
        #endif

        0x354U, /* CanId*/
        STANDARD_CAN, /* CanIdType */
        0, /* CanIfRxPduHrhIdRef */
        8, /* CanIfRxPduDlc */
        Com_RxIndication, /* CanIfRxPduUserRxIndicationName */
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API)
        FALSE, /* CanIfRxPduReadNotifyStatus */
        #endif
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_DATA_API)
        FALSE, /* CanIfRxPduReadData */
        #endif
        #if(STD_ON == CANIF_RX_PDU_RANGE_CANID)
        NULL_PTR, /* CanIfRxPduRangePtr */
        #endif
        #if(CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE)
        15, /* CanIfRxPduNextHrh */
        #endif
    },
        /* 15 */
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        15,    /* CanIfRxPduUpperLayerHandle */
        #endif

        0x35BU, /* CanId*/
        STANDARD_CAN, /* CanIdType */
        0, /* CanIfRxPduHrhIdRef */
        8, /* CanIfRxPduDlc */
        Com_RxIndication, /* CanIfRxPduUserRxIndicationName */
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API)
        FALSE, /* CanIfRxPduReadNotifyStatus */
        #endif
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_DATA_API)
        FALSE, /* CanIfRxPduReadData */
        #endif
        #if(STD_ON == CANIF_RX_PDU_RANGE_CANID)
        NULL_PTR, /* CanIfRxPduRangePtr */
        #endif
        #if(CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE)
        16, /* CanIfRxPduNextHrh */
        #endif
    },
#if  E0X_DCM == E0X_DCM_FL
     /* 16*/
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        16,    /* CanIfRxPduUpperLayerHandle */
        #endif

        0x39DU, /* CanId*/
        STANDARD_CAN, /* CanIdType */
        0, /* CanIfRxPduHrhIdRef */
        8, /* CanIfRxPduDlc */
        Com_RxIndication, /* CanIfRxPduUserRxIndicationName */
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API)
        FALSE, /* CanIfRxPduReadNotifyStatus */
        #endif
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_DATA_API)
        FALSE, /* CanIfRxPduReadData */
        #endif
        #if(STD_ON == CANIF_RX_PDU_RANGE_CANID)
        NULL_PTR, /* CanIfRxPduRangePtr */
        #endif
        #if(CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE)
        17, /* CanIfRxPduNextHrh */
        #endif
    },
            /*17*/
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        17,    /* CanIfRxPduUpperLayerHandle */
        #endif

        0x3AEU, /* CanId*/
        STANDARD_CAN, /* CanIdType */
        0, /* CanIfRxPduHrhIdRef */
        8, /* CanIfRxPduDlc */
        Com_RxIndication, /* CanIfRxPduUserRxIndicationName */
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API)
        FALSE, /* CanIfRxPduReadNotifyStatus */
        #endif
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_DATA_API)
        FALSE, /* CanIfRxPduReadData */
        #endif
        #if(STD_ON == CANIF_RX_PDU_RANGE_CANID)
        NULL_PTR, /* CanIfRxPduRangePtr */
        #endif
        #if(CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE)
        18, /* CanIfRxPduNextHrh */
        #endif
    },
            /*18*/
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        18,    /* CanIfRxPduUpperLayerHandle */
        #endif

        0x3BEU, /* CanId*/
        STANDARD_CAN, /* CanIdType */
        0, /* CanIfRxPduHrhIdRef */
        8, /* CanIfRxPduDlc */
        Com_RxIndication, /* CanIfRxPduUserRxIndicationName */
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API)
        FALSE, /* CanIfRxPduReadNotifyStatus */
        #endif
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_DATA_API)
        FALSE, /* CanIfRxPduReadData */
        #endif
        #if(STD_ON == CANIF_RX_PDU_RANGE_CANID)
        NULL_PTR, /* CanIfRxPduRangePtr */
        #endif
        #if(CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE)
        19, /* CanIfRxPduNextHrh */
        #endif
    },
#elif  E0X_DCM == E0X_DCM_FR
     /* 16*/
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        16,    /* CanIfRxPduUpperLayerHandle */
        #endif

        0x38EU, /* CanId*/
        STANDARD_CAN, /* CanIdType */
        0, /* CanIfRxPduHrhIdRef */
        8, /* CanIfRxPduDlc */
        Com_RxIndication, /* CanIfRxPduUserRxIndicationName */
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API)
        FALSE, /* CanIfRxPduReadNotifyStatus */
        #endif
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_DATA_API)
        FALSE, /* CanIfRxPduReadData */
        #endif
        #if(STD_ON == CANIF_RX_PDU_RANGE_CANID)
        NULL_PTR, /* CanIfRxPduRangePtr */
        #endif
        #if(CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE)
        17, /* CanIfRxPduNextHrh */
        #endif
    },
            /*17*/
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        17,    /* CanIfRxPduUpperLayerHandle */
        #endif

        0x3AEU, /* CanId*/
        STANDARD_CAN, /* CanIdType */
        0, /* CanIfRxPduHrhIdRef */
        8, /* CanIfRxPduDlc */
        Com_RxIndication, /* CanIfRxPduUserRxIndicationName */
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API)
        FALSE, /* CanIfRxPduReadNotifyStatus */
        #endif
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_DATA_API)
        FALSE, /* CanIfRxPduReadData */
        #endif
        #if(STD_ON == CANIF_RX_PDU_RANGE_CANID)
        NULL_PTR, /* CanIfRxPduRangePtr */
        #endif
        #if(CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE)
        18, /* CanIfRxPduNextHrh */
        #endif
    },
            /*18*/
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        18,    /* CanIfRxPduUpperLayerHandle */
        #endif

        0x3BEU, /* CanId*/
        STANDARD_CAN, /* CanIdType */
        0, /* CanIfRxPduHrhIdRef */
        8, /* CanIfRxPduDlc */
        Com_RxIndication, /* CanIfRxPduUserRxIndicationName */
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API)
        FALSE, /* CanIfRxPduReadNotifyStatus */
        #endif
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_DATA_API)
        FALSE, /* CanIfRxPduReadData */
        #endif
        #if(STD_ON == CANIF_RX_PDU_RANGE_CANID)
        NULL_PTR, /* CanIfRxPduRangePtr */
        #endif
        #if(CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE)
        19, /* CanIfRxPduNextHrh */
        #endif
    },
#elif  E0X_DCM == E0X_DCM_RL
                /* 16*/
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        16,    /* CanIfRxPduUpperLayerHandle */
        #endif

        0x38EU, /* CanId*/
        STANDARD_CAN, /* CanIdType */
        0, /* CanIfRxPduHrhIdRef */
        8, /* CanIfRxPduDlc */
        Com_RxIndication, /* CanIfRxPduUserRxIndicationName */
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API)
        FALSE, /* CanIfRxPduReadNotifyStatus */
        #endif
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_DATA_API)
        FALSE, /* CanIfRxPduReadData */
        #endif
        #if(STD_ON == CANIF_RX_PDU_RANGE_CANID)
        NULL_PTR, /* CanIfRxPduRangePtr */
        #endif
        #if(CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE)
        17, /* CanIfRxPduNextHrh */
        #endif
    },
            /*17*/
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        17,    /* CanIfRxPduUpperLayerHandle */
        #endif

        0x39DU, /* CanId*/
        STANDARD_CAN, /* CanIdType */
        0, /* CanIfRxPduHrhIdRef */
        8, /* CanIfRxPduDlc */
        Com_RxIndication, /* CanIfRxPduUserRxIndicationName */
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API)
        FALSE, /* CanIfRxPduReadNotifyStatus */
        #endif
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_DATA_API)
        FALSE, /* CanIfRxPduReadData */
        #endif
        #if(STD_ON == CANIF_RX_PDU_RANGE_CANID)
        NULL_PTR, /* CanIfRxPduRangePtr */
        #endif
        #if(CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE)
        18, /* CanIfRxPduNextHrh */
        #endif
    },
            /*18*/
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        18,    /* CanIfRxPduUpperLayerHandle */
        #endif

        0x3BEU, /* CanId*/
        STANDARD_CAN, /* CanIdType */
        0, /* CanIfRxPduHrhIdRef */
        8, /* CanIfRxPduDlc */
        Com_RxIndication, /* CanIfRxPduUserRxIndicationName */
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API)
        FALSE, /* CanIfRxPduReadNotifyStatus */
        #endif
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_DATA_API)
        FALSE, /* CanIfRxPduReadData */
        #endif
        #if(STD_ON == CANIF_RX_PDU_RANGE_CANID)
        NULL_PTR, /* CanIfRxPduRangePtr */
        #endif
        #if(CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE)
        19, /* CanIfRxPduNextHrh */
        #endif
    },
#elif  E0X_DCM == E0X_DCM_RR
     /* 16*/
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        16,    /* CanIfRxPduUpperLayerHandle */
        #endif

        0x38EU, /* CanId*/
        STANDARD_CAN, /* CanIdType */
        0, /* CanIfRxPduHrhIdRef */
        8, /* CanIfRxPduDlc */
        Com_RxIndication, /* CanIfRxPduUserRxIndicationName */
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API)
        FALSE, /* CanIfRxPduReadNotifyStatus */
        #endif
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_DATA_API)
        FALSE, /* CanIfRxPduReadData */
        #endif
        #if(STD_ON == CANIF_RX_PDU_RANGE_CANID)
        NULL_PTR, /* CanIfRxPduRangePtr */
        #endif
        #if(CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE)
        17, /* CanIfRxPduNextHrh */
        #endif
    },
            /*17*/
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        17,    /* CanIfRxPduUpperLayerHandle */
        #endif

        0x39DU, /* CanId*/
        STANDARD_CAN, /* CanIdType */
        0, /* CanIfRxPduHrhIdRef */
        8, /* CanIfRxPduDlc */
        Com_RxIndication, /* CanIfRxPduUserRxIndicationName */
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API)
        FALSE, /* CanIfRxPduReadNotifyStatus */
        #endif
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_DATA_API)
        FALSE, /* CanIfRxPduReadData */
        #endif
        #if(STD_ON == CANIF_RX_PDU_RANGE_CANID)
        NULL_PTR, /* CanIfRxPduRangePtr */
        #endif
        #if(CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE)
        18, /* CanIfRxPduNextHrh */
        #endif
    },
            /*18*/
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        18,    /* CanIfRxPduUpperLayerHandle */
        #endif

        0x3AEU, /* CanId*/
        STANDARD_CAN, /* CanIdType */
        0, /* CanIfRxPduHrhIdRef */
        8, /* CanIfRxPduDlc */
        Com_RxIndication, /* CanIfRxPduUserRxIndicationName */
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API)
        FALSE, /* CanIfRxPduReadNotifyStatus */
        #endif
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_DATA_API)
        FALSE, /* CanIfRxPduReadData */
        #endif
        #if(STD_ON == CANIF_RX_PDU_RANGE_CANID)
        NULL_PTR, /* CanIfRxPduRangePtr */
        #endif
        #if(CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE)
        19, /* CanIfRxPduNextHrh */
        #endif
    },
#else
#error "the define E0X_DCM is error!"
#endif
    /* 19*/
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        19,    /* CanIfRxPduUpperLayerHandle */
        #endif

        0x40BU, /* CanId*/
        STANDARD_CAN, /* CanIdType */
        0, /* CanIfRxPduHrhIdRef */
        8, /* CanIfRxPduDlc */
        Com_RxIndication, /* CanIfRxPduUserRxIndicationName */
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API)
        FALSE, /* CanIfRxPduReadNotifyStatus */
        #endif
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_DATA_API)
        FALSE, /* CanIfRxPduReadData */
        #endif
        #if(STD_ON == CANIF_RX_PDU_RANGE_CANID)
        NULL_PTR, /* CanIfRxPduRangePtr */
        #endif
        #if(CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE)
        20, /* CanIfRxPduNextHrh */
        #endif
    },
     /* 20*/
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        20,    /* CanIfRxPduUpperLayerHandle */
        #endif

        0x433U, /* CanId*/
        STANDARD_CAN, /* CanIdType */
        0, /* CanIfRxPduHrhIdRef */
        8, /* CanIfRxPduDlc */
        Com_RxIndication, /* CanIfRxPduUserRxIndicationName */
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API)
        FALSE, /* CanIfRxPduReadNotifyStatus */
        #endif
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_DATA_API)
        FALSE, /* CanIfRxPduReadData */
        #endif
        #if(STD_ON == CANIF_RX_PDU_RANGE_CANID)
        NULL_PTR, /* CanIfRxPduRangePtr */
        #endif
        #if(CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE)
        21, /* CanIfRxPduNextHrh */
        #endif
    },
    /* 21*/
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        21,    /* CanIfRxPduUpperLayerHandle */
        #endif

        0x447U, /* CanId*/
        STANDARD_CAN, /* CanIdType */
        0, /* CanIfRxPduHrhIdRef */
        8, /* CanIfRxPduDlc */
        Com_RxIndication, /* CanIfRxPduUserRxIndicationName */
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API)
        FALSE, /* CanIfRxPduReadNotifyStatus */
        #endif
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_DATA_API)
        FALSE, /* CanIfRxPduReadData */
        #endif
        #if(STD_ON == CANIF_RX_PDU_RANGE_CANID)
        NULL_PTR, /* CanIfRxPduRangePtr */
        #endif
        #if(CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE)
        22, /* CanIfRxPduNextHrh */
        #endif
    },
     /* 22*/
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        22,    /* CanIfRxPduUpperLayerHandle */
        #endif

        0x450U, /* CanId*/
        STANDARD_CAN, /* CanIdType */
        0, /* CanIfRxPduHrhIdRef */
        8, /* CanIfRxPduDlc */
        Com_RxIndication, /* CanIfRxPduUserRxIndicationName */
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API)
        FALSE, /* CanIfRxPduReadNotifyStatus */
        #endif
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_DATA_API)
        FALSE, /* CanIfRxPduReadData */
        #endif
        #if(STD_ON == CANIF_RX_PDU_RANGE_CANID)
        NULL_PTR, /* CanIfRxPduRangePtr */
        #endif
        #if(CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE)
        23, /* CanIfRxPduNextHrh */
        #endif
    },
         /* 23*/
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        23,    /* CanIfRxPduUpperLayerHandle */
        #endif

        0x47EU, /* CanId*/
        STANDARD_CAN, /* CanIdType */
        0, /* CanIfRxPduHrhIdRef */
        8, /* CanIfRxPduDlc */
        Com_RxIndication, /* CanIfRxPduUserRxIndicationName */
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API)
        FALSE, /* CanIfRxPduReadNotifyStatus */
        #endif
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_DATA_API)
        FALSE, /* CanIfRxPduReadData */
        #endif
        #if(STD_ON == CANIF_RX_PDU_RANGE_CANID)
        NULL_PTR, /* CanIfRxPduRangePtr */
        #endif
        #if(CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE)
        24, /* CanIfRxPduNextHrh */
        #endif
    },
     /* 24*/
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        24,    /* CanIfRxPduUpperLayerHandle */
        #endif

        0x48AU, /* CanId*/
        STANDARD_CAN, /* CanIdType */
        0, /* CanIfRxPduHrhIdRef */
        8, /* CanIfRxPduDlc */
        Com_RxIndication, /* CanIfRxPduUserRxIndicationName */
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API)
        FALSE, /* CanIfRxPduReadNotifyStatus */
        #endif
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_DATA_API)
        FALSE, /* CanIfRxPduReadData */
        #endif
        #if(STD_ON == CANIF_RX_PDU_RANGE_CANID)
        NULL_PTR, /* CanIfRxPduRangePtr */
        #endif
        #if(CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE)
        25, /* CanIfRxPduNextHrh */
        #endif
    },
     /* 25*/
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        25,    /* CanIfRxPduUpperLayerHandle */
        #endif

        0x48DU, /* CanId*/
        STANDARD_CAN, /* CanIdType */
        0, /* CanIfRxPduHrhIdRef */
        8, /* CanIfRxPduDlc */
        Com_RxIndication, /* CanIfRxPduUserRxIndicationName */
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API)
        FALSE, /* CanIfRxPduReadNotifyStatus */
        #endif
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_DATA_API)
        FALSE, /* CanIfRxPduReadData */
        #endif
        #if(STD_ON == CANIF_RX_PDU_RANGE_CANID)
        NULL_PTR, /* CanIfRxPduRangePtr */
        #endif
        #if(CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE)
        26, /* CanIfRxPduNextHrh */
        #endif
    },
      /* 26*/
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        26,    /* CanIfRxPduUpperLayerHandle */
        #endif

        0x490U, /* CanId*/
        STANDARD_CAN, /* CanIdType */
        0, /* CanIfRxPduHrhIdRef */
        8, /* CanIfRxPduDlc */
        Com_RxIndication, /* CanIfRxPduUserRxIndicationName */
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API)
        FALSE, /* CanIfRxPduReadNotifyStatus */
        #endif
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_DATA_API)
        FALSE, /* CanIfRxPduReadData */
        #endif
        #if(STD_ON == CANIF_RX_PDU_RANGE_CANID)
        NULL_PTR, /* CanIfRxPduRangePtr */
        #endif
        #if(CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE)
        27, /* CanIfRxPduNextHrh */
        #endif
    },
        /* 27*/
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        27,    /* CanIfRxPduUpperLayerHandle */
        #endif

        0x494U, /* CanId*/
        STANDARD_CAN, /* CanIdType */
        0, /* CanIfRxPduHrhIdRef */
        8, /* CanIfRxPduDlc */
        Com_RxIndication, /* CanIfRxPduUserRxIndicationName */
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API)
        FALSE, /* CanIfRxPduReadNotifyStatus */
        #endif
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_DATA_API)
        FALSE, /* CanIfRxPduReadData */
        #endif
        #if(STD_ON == CANIF_RX_PDU_RANGE_CANID)
        NULL_PTR, /* CanIfRxPduRangePtr */
        #endif
        #if(CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE)
        28, /* CanIfRxPduNextHrh */
        #endif
    },
         /* 28*/
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        28,    /* CanIfRxPduUpperLayerHandle */
        #endif

        0x49CU, /* CanId*/
        STANDARD_CAN, /* CanIdType */
        0, /* CanIfRxPduHrhIdRef */
        8, /* CanIfRxPduDlc */
        Com_RxIndication, /* CanIfRxPduUserRxIndicationName */
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API)
        FALSE, /* CanIfRxPduReadNotifyStatus */
        #endif
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_DATA_API)
        FALSE, /* CanIfRxPduReadData */
        #endif
        #if(STD_ON == CANIF_RX_PDU_RANGE_CANID)
        NULL_PTR, /* CanIfRxPduRangePtr */
        #endif
        #if(CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE)
        29, /* CanIfRxPduNextHrh */
        #endif
    },
     /* 29*/
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        29,    /* CanIfRxPduUpperLayerHandle */
        #endif

        0x49DU, /* CanId*/
        STANDARD_CAN, /* CanIdType */
        0, /* CanIfRxPduHrhIdRef */
        8, /* CanIfRxPduDlc */
        Com_RxIndication, /* CanIfRxPduUserRxIndicationName */
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API)
        FALSE, /* CanIfRxPduReadNotifyStatus */
        #endif
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_DATA_API)
        FALSE, /* CanIfRxPduReadData */
        #endif
        #if(STD_ON == CANIF_RX_PDU_RANGE_CANID)
        NULL_PTR, /* CanIfRxPduRangePtr */
        #endif
        #if(CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE)
        30, /* CanIfRxPduNextHrh */
        #endif
    },
    /* 30*/
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        30,    /* CanIfRxPduUpperLayerHandle */
        #endif

        0x4A7U, /* CanId*/
        STANDARD_CAN, /* CanIdType */
        0, /* CanIfRxPduHrhIdRef */
        8, /* CanIfRxPduDlc */
        Com_RxIndication, /* CanIfRxPduUserRxIndicationName */
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API)
        FALSE, /* CanIfRxPduReadNotifyStatus */
        #endif
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_DATA_API)
        FALSE, /* CanIfRxPduReadData */
        #endif
        #if(STD_ON == CANIF_RX_PDU_RANGE_CANID)
        NULL_PTR, /* CanIfRxPduRangePtr */
        #endif
        #if(CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE)
        31, /* CanIfRxPduNextHrh */
        #endif
    },
    /* 31*/
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        31,    /* CanIfRxPduUpperLayerHandle */
        #endif

        0x4B4U, /* CanId*/
        STANDARD_CAN, /* CanIdType */
        0, /* CanIfRxPduHrhIdRef */
        8, /* CanIfRxPduDlc */
        Com_RxIndication, /* CanIfRxPduUserRxIndicationName */
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API)
        FALSE, /* CanIfRxPduReadNotifyStatus */
        #endif
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_DATA_API)
        FALSE, /* CanIfRxPduReadData */
        #endif
        #if(STD_ON == CANIF_RX_PDU_RANGE_CANID)
        NULL_PTR, /* CanIfRxPduRangePtr */
        #endif
        #if(CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE)
        32, /* CanIfRxPduNextHrh */
        #endif
    },
          /* 32*/
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        32,    /* CanIfRxPduUpperLayerHandle */
        #endif

        0x4B9U, /* CanId*/
        STANDARD_CAN, /* CanIdType */
        0, /* CanIfRxPduHrhIdRef */
        8, /* CanIfRxPduDlc */
        Com_RxIndication, /* CanIfRxPduUserRxIndicationName */
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API)
        FALSE, /* CanIfRxPduReadNotifyStatus */
        #endif
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_DATA_API)
        FALSE, /* CanIfRxPduReadData */
        #endif
        #if(STD_ON == CANIF_RX_PDU_RANGE_CANID)
        NULL_PTR, /* CanIfRxPduRangePtr */
        #endif
        #if(CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE)
        33, /* CanIfRxPduNextHrh */
        #endif
    },
          /* 33*/
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        33,    /* CanIfRxPduUpperLayerHandle */
        #endif

        0x4C1U, /* CanId*/
        STANDARD_CAN, /* CanIdType */
        0, /* CanIfRxPduHrhIdRef */
        8, /* CanIfRxPduDlc */
        Com_RxIndication, /* CanIfRxPduUserRxIndicationName */
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API)
        FALSE, /* CanIfRxPduReadNotifyStatus */
        #endif
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_DATA_API)
        FALSE, /* CanIfRxPduReadData */
        #endif
        #if(STD_ON == CANIF_RX_PDU_RANGE_CANID)
        NULL_PTR, /* CanIfRxPduRangePtr */
        #endif
        #if(CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE)
        34, /* CanIfRxPduNextHrh */
        #endif
    },
          /* 34*/
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        34,    /* CanIfRxPduUpperLayerHandle */
        #endif

        0x4E4U, /* CanId*/
        STANDARD_CAN, /* CanIdType */
        0, /* CanIfRxPduHrhIdRef */
        8, /* CanIfRxPduDlc */
        Com_RxIndication, /* CanIfRxPduUserRxIndicationName */
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API)
        FALSE, /* CanIfRxPduReadNotifyStatus */
        #endif
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_DATA_API)
        FALSE, /* CanIfRxPduReadData */
        #endif
        #if(STD_ON == CANIF_RX_PDU_RANGE_CANID)
        NULL_PTR, /* CanIfRxPduRangePtr */
        #endif
        #if(CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE)
        35, /* CanIfRxPduNextHrh */
        #endif
    },
         /* 35*/
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        35,    /* CanIfRxPduUpperLayerHandle */
        #endif

        0x4F3U, /* CanId*/
        STANDARD_CAN, /* CanIdType */
        0, /* CanIfRxPduHrhIdRef */
        8, /* CanIfRxPduDlc */
        Com_RxIndication, /* CanIfRxPduUserRxIndicationName */
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API)
        FALSE, /* CanIfRxPduReadNotifyStatus */
        #endif
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_DATA_API)
        FALSE, /* CanIfRxPduReadData */
        #endif
        #if(STD_ON == CANIF_RX_PDU_RANGE_CANID)
        NULL_PTR, /* CanIfRxPduRangePtr */
        #endif
        #if(CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE)
        36, /* CanIfRxPduNextHrh */
        #endif
    },
             /* 36*/
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        36,    /* CanIfRxPduUpperLayerHandle */
        #endif

        0x4F6U, /* CanId*/
        STANDARD_CAN, /* CanIdType */
        0, /* CanIfRxPduHrhIdRef */
        8, /* CanIfRxPduDlc */
        Com_RxIndication, /* CanIfRxPduUserRxIndicationName */
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API)
        FALSE, /* CanIfRxPduReadNotifyStatus */
        #endif
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_DATA_API)
        FALSE, /* CanIfRxPduReadData */
        #endif
        #if(STD_ON == CANIF_RX_PDU_RANGE_CANID)
        NULL_PTR, /* CanIfRxPduRangePtr */
        #endif
        #if(CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE)
        37, /* CanIfRxPduNextHrh */
        #endif
    },
    /* 37*/
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        37,    /* CanIfRxPduUpperLayerHandle */
        #endif

        0x4FFU, /* CanId*/
        STANDARD_CAN, /* CanIdType */
        0, /* CanIfRxPduHrhIdRef */
        8, /* CanIfRxPduDlc */
        Com_RxIndication, /* CanIfRxPduUserRxIndicationName */
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API)
        FALSE, /* CanIfRxPduReadNotifyStatus */
        #endif
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_DATA_API)
        FALSE, /* CanIfRxPduReadData */
        #endif
        #if(STD_ON == CANIF_RX_PDU_RANGE_CANID)
        NULL_PTR, /* CanIfRxPduRangePtr */
        #endif
        #if(CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE)
        38, /* CanIfRxPduNextHrh */
        #endif
    },
          /* 38*/
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        38,    /* CanIfRxPduUpperLayerHandle */
        #endif

        0x510U, /* CanId*/
        STANDARD_CAN, /* CanIdType */
        0, /* CanIfRxPduHrhIdRef */
        8, /* CanIfRxPduDlc */
        Com_RxIndication, /* CanIfRxPduUserRxIndicationName */
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API)
        FALSE, /* CanIfRxPduReadNotifyStatus */
        #endif
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_DATA_API)
        FALSE, /* CanIfRxPduReadData */
        #endif
        #if(STD_ON == CANIF_RX_PDU_RANGE_CANID)
        NULL_PTR, /* CanIfRxPduRangePtr */
        #endif
        #if(CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE)
        39, /* CanIfRxPduNextHrh */
        #endif
    },
     /* 39 */
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        0,//5,    /* CanIfRxPduUpperLayerHandle */
        #endif

        0x600U, /* CanId*/
        STANDARD_CAN, /* CanIdType */
        0, /* CanIfRxPduHrhIdRef */
        8, /* CanIfRxPduDlc */
        NULL_PTR, /* CanIfRxPduUserRxIndicationName */
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API)
        FALSE, /* CanIfRxPduReadNotifyStatus */
        #endif
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_DATA_API)
        TRUE, /* CanIfRxPduReadData */
        #endif
        #if(STD_ON == CANIF_RX_PDU_RANGE_CANID)
        &CanIfRxPduCanIdRangeConfig[0], /* CanIfRxPduRangePtr */
        #endif
        #if(CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE)
        40, /* CanIfRxPduNextHrh */
        #endif
    },
     /* 40 */
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        0,    /* CanIfRxPduUpperLayerHandle */
        #endif

        0x702U, /* CanId*/
        STANDARD_CAN, /* CanIdType */
        0, /* CanIfRxPduHrhIdRef */
        8, /* CanIfRxPduDlc */
		NULL_PTR, /* CanIfRxPduUserRxIndicationName */
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API)
        FALSE, /* CanIfRxPduReadNotifyStatus */
        #endif
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_DATA_API)
        FALSE, /* CanIfRxPduReadData */
        #endif
        #if(STD_ON == CANIF_RX_PDU_RANGE_CANID)
        NULL_PTR, /* CanIfRxPduRangePtr */
        #endif
        #if(CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE)
        41, /* CanIfRxPduNextHrh */
        #endif
    },
#if  E0X_DCM == E0X_DCM_FL
    /* 41*/
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        0,    /* CanIfRxPduUpperLayerHandle */
        #endif

		0x700U, /* CanId*/
        STANDARD_CAN, /* CanIdType */
        0, /* CanIfRxPduHrhIdRef */
        8, /* CanIfRxPduDlc */
		NULL_PTR, /* CanIfRxPduUserRxIndicationName */
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API)
        FALSE, /* CanIfRxPduReadNotifyStatus */
        #endif
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_DATA_API)
        FALSE, /* CanIfRxPduReadData */
        #endif
        #if(STD_ON == CANIF_RX_PDU_RANGE_CANID)
        NULL_PTR, /* CanIfRxPduRangePtr */
        #endif
        #if(CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE)
        42, /* CanIfRxPduNextHrh */
        #endif
    },
#elif  E0X_DCM == E0X_DCM_FR
    /* 41*/
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        0,    /* CanIfRxPduUpperLayerHandle */
        #endif

	0x701U, /* CanId*/
        STANDARD_CAN, /* CanIdType */
        0, /* CanIfRxPduHrhIdRef */
        8, /* CanIfRxPduDlc */
        CanTp_RxIndication, /* CanIfRxPduUserRxIndicationName */
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API)
        FALSE, /* CanIfRxPduReadNotifyStatus */
        #endif
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_DATA_API)
        FALSE, /* CanIfRxPduReadData */
        #endif
        #if(STD_ON == CANIF_RX_PDU_RANGE_CANID)
        NULL_PTR, /* CanIfRxPduRangePtr */
        #endif
        #if(CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE)
        42, /* CanIfRxPduNextHrh */
        #endif
    },
#elif  E0X_DCM == E0X_DCM_RL
    /* 41*/
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        0,    /* CanIfRxPduUpperLayerHandle */
        #endif

	0x704U, /* CanId*/
        STANDARD_CAN, /* CanIdType */
        0, /* CanIfRxPduHrhIdRef */
        8, /* CanIfRxPduDlc */
        CanTp_RxIndication, /* CanIfRxPduUserRxIndicationName */
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API)
        FALSE, /* CanIfRxPduReadNotifyStatus */
        #endif
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_DATA_API)
        FALSE, /* CanIfRxPduReadData */
        #endif
        #if(STD_ON == CANIF_RX_PDU_RANGE_CANID)
        NULL_PTR, /* CanIfRxPduRangePtr */
        #endif
        #if(CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE)
        42, /* CanIfRxPduNextHrh */
        #endif
    },
#elif  E0X_DCM == E0X_DCM_RR
    /* 41*/
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        0,    /* CanIfRxPduUpperLayerHandle */
        #endif

	0x705U, /* CanId*/
        STANDARD_CAN, /* CanIdType */
        0, /* CanIfRxPduHrhIdRef */
        8, /* CanIfRxPduDlc */
        CanTp_RxIndication, /* CanIfRxPduUserRxIndicationName */
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API)
        FALSE, /* CanIfRxPduReadNotifyStatus */
        #endif
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_DATA_API)
        FALSE, /* CanIfRxPduReadData */
        #endif
        #if(STD_ON == CANIF_RX_PDU_RANGE_CANID)
        NULL_PTR, /* CanIfRxPduRangePtr */
        #endif
        #if(CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE)
        42, /* CanIfRxPduNextHrh */
        #endif
    },
#else
#error "the define E0X_DCM is error!"
#endif
    /* 42 */
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        1,    /* CanIfRxPduUpperLayerHandle */
        #endif

        0x7dfU, /* CanId*/
        STANDARD_CAN, /* CanIdType */
        0, /* CanIfRxPduHrhIdRef */
        8, /* CanIfRxPduDlc */
		NULL_PTR, /* CanIfRxPduUserRxIndicationName */
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API)
        FALSE, /* CanIfRxPduReadNotifyStatus */
        #endif
        #if(STD_ON == CANIF_PUBLIC_READRXPDU_DATA_API)
        FALSE, /* CanIfRxPduReadData */
        #endif
        #if(STD_ON == CANIF_RX_PDU_RANGE_CANID)
        NULL_PTR, /* CanIfRxPduRangePtr */
        #endif
        #if(CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE)
        CANIF_LAST_HOH_PDUID, /* CanIfRxPduNextHrh */
        #endif
    },
};

#if(CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE)
CONST(Can_HwHandleType, CANIF_CONFIG_CONST)
                                     CanIfHrhFirstRxPduID[CANIF_CFG_TOTAL_HRH] = 
{ 
    0,
};

#if(STD_ON == CANIF_PUBLIC_TX_BUFFERING)
CONST(Can_HwHandleType, CANIF_CONFIG_CONST)
                                         CanIfHthFirstTxPduID[3] =
{
    0,
    1,
    2,
};
#endif
#endif 

#if(STD_ON == CANIF_HRH_RANGE_FILTER)
CONST(CanIf_HrhRangeCfgType, CANIF_CONFIG_CONST)
                                         CanIfHrhRangeCfg[CANIF_CFG_TOTAL_HRH] =
{
    /* not supported */  
};
#endif 

CONST(CanIf_TxPduConfigType, CANIF_CONFIG_CONST)
                         CanIfTxPduConfig[CANIF_CFG_TOTAL_TXPDUID] = 
{
#if  E0X_DCM == E0X_DCM_FL
     /* 0 */ 
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        0,    /* CanIfTxPduUpperLayerHandle */ 
        #endif 
        
        0x2C2U, /* CanId*/ 
        STANDARD_CAN, /* CanIdType */ 
        1, /* CanIfTxPduHthIdRef */ 
        8, /* CanIfTxPduDlc */ 
        Com_TxConfirmation, /* CanIfTxPduUserTxConfirmationUL */ 
        #if(STD_ON == CANIF_PUBLIC_SETDYNAMICTXID_API)  
        STATIC_TXPDU, /* CanIfTxPduType */ 
        #endif 
        #if(STD_ON == CANIF_PUBLIC_READTXPDU_NOTIFY_STATUS_API)  
        FALSE, /* CanIfTxPduReadData */ 
        #endif 
        #if((CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE) \
        &&(STD_ON == CANIF_PUBLIC_TX_BUFFERING))
        1   /* HthNextTxPduID */  
        #endif
    },
    /* 1 */ 
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        1,    /* CanIfTxPduUpperLayerHandle */ 
        #endif 
        
        0x38EU, /* CanId*/ 
        STANDARD_CAN, /* CanIdType */ 
        2, /* CanIfTxPduHthIdRef */ 
        8, /* CanIfTxPduDlc */ 
        Com_TxConfirmation, /* CanIfTxPduUserTxConfirmationUL */ 
        #if(STD_ON == CANIF_PUBLIC_SETDYNAMICTXID_API)  
        STATIC_TXPDU, /* CanIfTxPduType */ 
        #endif 
        #if(STD_ON == CANIF_PUBLIC_READTXPDU_NOTIFY_STATUS_API)  
        FALSE, /* CanIfTxPduReadData */ 
        #endif 
        #if((CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE) \
        &&(STD_ON == CANIF_PUBLIC_TX_BUFFERING))
        2   /* HthNextTxPduID */  
        #endif
    },
    /* 2 */ 
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        2,    /* CanIfTxPduUpperLayerHandle */ 
        #endif 
        
        0x40EU, /* CanId*/ 
        STANDARD_CAN, /* CanIdType */ 
        3, /* CanIfTxPduHthIdRef */ 
        8, /* CanIfTxPduDlc */ 
        Com_TxConfirmation, /* CanIfTxPduUserTxConfirmationUL */ 
        #if(STD_ON == CANIF_PUBLIC_SETDYNAMICTXID_API)  
        STATIC_TXPDU, /* CanIfTxPduType */ 
        #endif 
        #if(STD_ON == CANIF_PUBLIC_READTXPDU_NOTIFY_STATUS_API)  
        FALSE, /* CanIfTxPduReadData */ 
        #endif 
        #if((CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE) \
        &&(STD_ON == CANIF_PUBLIC_TX_BUFFERING))
        3   /* HthNextTxPduID */  
        #endif
    },    
    /* 3 */ 
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        3,    /* CanIfTxPduUpperLayerHandle */ 
        #endif 
        
        0x572U, /* CanId*/ 
        STANDARD_CAN, /* CanIdType */ 
        4, /* CanIfTxPduHthIdRef */ 
        8, /* CanIfTxPduDlc */ 
        Com_TxConfirmation, /* CanIfTxPduUserTxConfirmationUL */ 
        #if(STD_ON == CANIF_PUBLIC_SETDYNAMICTXID_API)  
        STATIC_TXPDU, /* CanIfTxPduType */ 
        #endif 
        #if(STD_ON == CANIF_PUBLIC_READTXPDU_NOTIFY_STATUS_API)  
        FALSE, /* CanIfTxPduReadData */ 
        #endif 
        #if((CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE) \
        &&(STD_ON == CANIF_PUBLIC_TX_BUFFERING))
        4   /* HthNextTxPduID */  
        #endif
    },
    /* 4 */ 
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        0,    /* CanIfTxPduUpperLayerHandle */ 
        #endif 
        
        0x633U, /* CanId*/ 
        STANDARD_CAN, /* CanIdType */ 
        5, /* CanIfTxPduHthIdRef */ 
        8, /* CanIfTxPduDlc */ 
        CanNm_TxConfirmation, /* CanIfTxPduUserTxConfirmationUL */ 
        #if(STD_ON == CANIF_PUBLIC_SETDYNAMICTXID_API)  
        STATIC_TXPDU, /* CanIfTxPduType */ 
        #endif 
        #if(STD_ON == CANIF_PUBLIC_READTXPDU_NOTIFY_STATUS_API)  
        FALSE, /* CanIfTxPduReadData */ 
        #endif 
        #if((CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE) \
        &&(STD_ON == CANIF_PUBLIC_TX_BUFFERING))
        5   /* HthNextTxPduID */  
        #endif
    },
        /* 5 */ 
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        0,    /* CanIfTxPduUpperLayerHandle */ 
        #endif 
        
        0x702U, /* CanId*/ 
        STANDARD_CAN, /* CanIdType */ 
        6, /* CanIfTxPduHthIdRef */ 
        8, /* CanIfTxPduDlc */ 
		NULL_PTR, /* CanIfTxPduUserTxConfirmationUL */
        #if(STD_ON == CANIF_PUBLIC_SETDYNAMICTXID_API)  
        STATIC_TXPDU, /* CanIfTxPduType */ 
        #endif 
        #if(STD_ON == CANIF_PUBLIC_READTXPDU_NOTIFY_STATUS_API)  
        FALSE, /* CanIfTxPduReadData */ 
        #endif 
        #if((CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE) \
        &&(STD_ON == CANIF_PUBLIC_TX_BUFFERING))
        6   /* HthNextTxPduID */  
        #endif
    },
    /* 6 */ 
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        6,    /* CanIfTxPduUpperLayerHandle */ 
        #endif 

        0x780U, /* CanId*/ 
        STANDARD_CAN, /* CanIdType */ 
        7, /* CanIfTxPduHthIdRef */ 
        8, /* CanIfTxPduDlc */ 
		NULL_PTR, /* CanIfTxPduUserTxConfirmationUL */
        #if(STD_ON == CANIF_PUBLIC_SETDYNAMICTXID_API)  
        STATIC_TXPDU, /* CanIfTxPduType */ 
        #endif 
        #if(STD_ON == CANIF_PUBLIC_READTXPDU_NOTIFY_STATUS_API)  
        FALSE, /* CanIfTxPduReadData */ 
        #endif 
        #if((CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE) \
        &&(STD_ON == CANIF_PUBLIC_TX_BUFFERING))
        CANIF_LAST_HOH_PDUID   /* HthNextTxPduID */  
        #endif
    }
#elif  E0X_DCM == E0X_DCM_FR
 /* 0 */ 
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        0,    /* CanIfTxPduUpperLayerHandle */ 
        #endif 
        
        0x2C5U, /* CanId*/ 
        STANDARD_CAN, /* CanIdType */ 
        1, /* CanIfTxPduHthIdRef */ 
        8, /* CanIfTxPduDlc */ 
        Com_TxConfirmation, /* CanIfTxPduUserTxConfirmationUL */ 
        #if(STD_ON == CANIF_PUBLIC_SETDYNAMICTXID_API)  
        STATIC_TXPDU, /* CanIfTxPduType */ 
        #endif 
        #if(STD_ON == CANIF_PUBLIC_READTXPDU_NOTIFY_STATUS_API)  
        FALSE, /* CanIfTxPduReadData */ 
        #endif 
        #if((CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE) \
        &&(STD_ON == CANIF_PUBLIC_TX_BUFFERING))
        1   /* HthNextTxPduID */  
        #endif
    },
    /* 1 */ 
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        1,    /* CanIfTxPduUpperLayerHandle */ 
        #endif 
        
        0x39DU, /* CanId*/ 
        STANDARD_CAN, /* CanIdType */ 
        2, /* CanIfTxPduHthIdRef */ 
        8, /* CanIfTxPduDlc */ 
        Com_TxConfirmation, /* CanIfTxPduUserTxConfirmationUL */ 
        #if(STD_ON == CANIF_PUBLIC_SETDYNAMICTXID_API)  
        STATIC_TXPDU, /* CanIfTxPduType */ 
        #endif 
        #if(STD_ON == CANIF_PUBLIC_READTXPDU_NOTIFY_STATUS_API)  
        FALSE, /* CanIfTxPduReadData */ 
        #endif 
        #if((CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE) \
        &&(STD_ON == CANIF_PUBLIC_TX_BUFFERING))
        2   /* HthNextTxPduID */  
        #endif
    },
        /* 2 */ 
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        2,    /* CanIfTxPduUpperLayerHandle */ 
        #endif 
        
        0x415U, /* CanId*/ 
        STANDARD_CAN, /* CanIdType */ 
        3, /* CanIfTxPduHthIdRef */ 
        8, /* CanIfTxPduDlc */ 
        Com_TxConfirmation, /* CanIfTxPduUserTxConfirmationUL */ 
        #if(STD_ON == CANIF_PUBLIC_SETDYNAMICTXID_API)  
        STATIC_TXPDU, /* CanIfTxPduType */ 
        #endif 
        #if(STD_ON == CANIF_PUBLIC_READTXPDU_NOTIFY_STATUS_API)  
        FALSE, /* CanIfTxPduReadData */ 
        #endif 
        #if((CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE) \
        &&(STD_ON == CANIF_PUBLIC_TX_BUFFERING))
        3   /* HthNextTxPduID */  
        #endif
    },
     /* 3 */ 
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        3,    /* CanIfTxPduUpperLayerHandle */ 
        #endif 
        
        0x574U, /* CanId*/ 
        STANDARD_CAN, /* CanIdType */ 
        4, /* CanIfTxPduHthIdRef */ 
        8, /* CanIfTxPduDlc */ 
        Com_TxConfirmation, /* CanIfTxPduUserTxConfirmationUL */ 
        #if(STD_ON == CANIF_PUBLIC_SETDYNAMICTXID_API)  
        STATIC_TXPDU, /* CanIfTxPduType */ 
        #endif 
        #if(STD_ON == CANIF_PUBLIC_READTXPDU_NOTIFY_STATUS_API)  
        FALSE, /* CanIfTxPduReadData */ 
        #endif 
        #if((CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE) \
        &&(STD_ON == CANIF_PUBLIC_TX_BUFFERING))
        4   /* HthNextTxPduID */  
        #endif
    },
    /* 4 */ 
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        0,    /* CanIfTxPduUpperLayerHandle */ 
        #endif 
        
        0x659U, /* CanId*/ 
        STANDARD_CAN, /* CanIdType */ 
        5, /* CanIfTxPduHthIdRef */ 
        8, /* CanIfTxPduDlc */ 
        CanNm_TxConfirmation, /* CanIfTxPduUserTxConfirmationUL */ 
        #if(STD_ON == CANIF_PUBLIC_SETDYNAMICTXID_API)  
        STATIC_TXPDU, /* CanIfTxPduType */ 
        #endif 
        #if(STD_ON == CANIF_PUBLIC_READTXPDU_NOTIFY_STATUS_API)  
        FALSE, /* CanIfTxPduReadData */ 
        #endif 
        #if((CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE) \
        &&(STD_ON == CANIF_PUBLIC_TX_BUFFERING))
        5   /* HthNextTxPduID */  
        #endif
    },
        /* 5 */ 
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        0,    /* CanIfTxPduUpperLayerHandle */ 
        #endif 
        
        0x702U, /* CanId*/ 
        STANDARD_CAN, /* CanIdType */ 
        6, /* CanIfTxPduHthIdRef */ 
        8, /* CanIfTxPduDlc */ 
        Xcp_CanIfTxConfirmation, /* CanIfTxPduUserTxConfirmationUL */ 
        #if(STD_ON == CANIF_PUBLIC_SETDYNAMICTXID_API)  
        STATIC_TXPDU, /* CanIfTxPduType */ 
        #endif 
        #if(STD_ON == CANIF_PUBLIC_READTXPDU_NOTIFY_STATUS_API)  
        FALSE, /* CanIfTxPduReadData */ 
        #endif 
        #if((CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE) \
        &&(STD_ON == CANIF_PUBLIC_TX_BUFFERING))
        6   /* HthNextTxPduID */  
        #endif
    },
    /* 6 */ 
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        6,    /* CanIfTxPduUpperLayerHandle */ 
        #endif 

        0x781U, /* CanId*/ 
        STANDARD_CAN, /* CanIdType */ 
        7, /* CanIfTxPduHthIdRef */ 
        8, /* CanIfTxPduDlc */ 
        CanTp_TxConfirmation, /* CanIfTxPduUserTxConfirmationUL */ 
        #if(STD_ON == CANIF_PUBLIC_SETDYNAMICTXID_API)  
        STATIC_TXPDU, /* CanIfTxPduType */ 
        #endif 
        #if(STD_ON == CANIF_PUBLIC_READTXPDU_NOTIFY_STATUS_API)  
        FALSE, /* CanIfTxPduReadData */ 
        #endif 
        #if((CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE) \
        &&(STD_ON == CANIF_PUBLIC_TX_BUFFERING))
        CANIF_LAST_HOH_PDUID   /* HthNextTxPduID */  
        #endif
    }
#elif  E0X_DCM == E0X_DCM_RL
    /* 0 */ 
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        0,    /* CanIfTxPduUpperLayerHandle */ 
        #endif 
        
        0x2C8U, /* CanId*/ 
        STANDARD_CAN, /* CanIdType */ 
        1, /* CanIfTxPduHthIdRef */ 
        8, /* CanIfTxPduDlc */ 
        Com_TxConfirmation, /* CanIfTxPduUserTxConfirmationUL */ 
        #if(STD_ON == CANIF_PUBLIC_SETDYNAMICTXID_API)  
        STATIC_TXPDU, /* CanIfTxPduType */ 
        #endif 
        #if(STD_ON == CANIF_PUBLIC_READTXPDU_NOTIFY_STATUS_API)  
        FALSE, /* CanIfTxPduReadData */ 
        #endif 
        #if((CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE) \
        &&(STD_ON == CANIF_PUBLIC_TX_BUFFERING))
        1   /* HthNextTxPduID */  
        #endif
    },
    /* 1 */ 
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        1,    /* CanIfTxPduUpperLayerHandle */ 
        #endif 
        
        0x3AEU, /* CanId*/ 
        STANDARD_CAN, /* CanIdType */ 
        2, /* CanIfTxPduHthIdRef */ 
        8, /* CanIfTxPduDlc */ 
        Com_TxConfirmation, /* CanIfTxPduUserTxConfirmationUL */ 
        #if(STD_ON == CANIF_PUBLIC_SETDYNAMICTXID_API)  
        STATIC_TXPDU, /* CanIfTxPduType */ 
        #endif 
        #if(STD_ON == CANIF_PUBLIC_READTXPDU_NOTIFY_STATUS_API)  
        FALSE, /* CanIfTxPduReadData */ 
        #endif 
        #if((CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE) \
        &&(STD_ON == CANIF_PUBLIC_TX_BUFFERING))
        2   /* HthNextTxPduID */  
        #endif
    },
    /* 2 */ 
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        2,    /* CanIfTxPduUpperLayerHandle */ 
        #endif 
        
        0x437U, /* CanId*/ 
        STANDARD_CAN, /* CanIdType */ 
        3, /* CanIfTxPduHthIdRef */ 
        8, /* CanIfTxPduDlc */ 
        Com_TxConfirmation, /* CanIfTxPduUserTxConfirmationUL */ 
        #if(STD_ON == CANIF_PUBLIC_SETDYNAMICTXID_API)  
        STATIC_TXPDU, /* CanIfTxPduType */ 
        #endif 
        #if(STD_ON == CANIF_PUBLIC_READTXPDU_NOTIFY_STATUS_API)  
        FALSE, /* CanIfTxPduReadData */ 
        #endif 
        #if((CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE) \
        &&(STD_ON == CANIF_PUBLIC_TX_BUFFERING))
        3   /* HthNextTxPduID */  
        #endif
    },
    /* 3 */ 
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        3,    /* CanIfTxPduUpperLayerHandle */ 
        #endif 
        
        0x575U, /* CanId*/ 
        STANDARD_CAN, /* CanIdType */ 
        4, /* CanIfTxPduHthIdRef */ 
        8, /* CanIfTxPduDlc */ 
        Com_TxConfirmation, /* CanIfTxPduUserTxConfirmationUL */ 
        #if(STD_ON == CANIF_PUBLIC_SETDYNAMICTXID_API)  
        STATIC_TXPDU, /* CanIfTxPduType */ 
        #endif 
        #if(STD_ON == CANIF_PUBLIC_READTXPDU_NOTIFY_STATUS_API)  
        FALSE, /* CanIfTxPduReadData */ 
        #endif 
        #if((CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE) \
        &&(STD_ON == CANIF_PUBLIC_TX_BUFFERING))
        4   /* HthNextTxPduID */  
        #endif
    },
    /* 4 */ 
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        0,    /* CanIfTxPduUpperLayerHandle */ 
        #endif 
        
        0x65AU, /* CanId*/ 
        STANDARD_CAN, /* CanIdType */ 
        5, /* CanIfTxPduHthIdRef */ 
        8, /* CanIfTxPduDlc */ 
        CanNm_TxConfirmation, /* CanIfTxPduUserTxConfirmationUL */ 
        #if(STD_ON == CANIF_PUBLIC_SETDYNAMICTXID_API)  
        STATIC_TXPDU, /* CanIfTxPduType */ 
        #endif 
        #if(STD_ON == CANIF_PUBLIC_READTXPDU_NOTIFY_STATUS_API)  
        FALSE, /* CanIfTxPduReadData */ 
        #endif 
        #if((CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE) \
        &&(STD_ON == CANIF_PUBLIC_TX_BUFFERING))
        5   /* HthNextTxPduID */  
        #endif
    },
        /* 5 */ 
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        0,    /* CanIfTxPduUpperLayerHandle */ 
        #endif 
        
        0x702U, /* CanId*/ 
        STANDARD_CAN, /* CanIdType */ 
        6, /* CanIfTxPduHthIdRef */ 
        8, /* CanIfTxPduDlc */ 
        Xcp_CanIfTxConfirmation, /* CanIfTxPduUserTxConfirmationUL */ 
        #if(STD_ON == CANIF_PUBLIC_SETDYNAMICTXID_API)  
        STATIC_TXPDU, /* CanIfTxPduType */ 
        #endif 
        #if(STD_ON == CANIF_PUBLIC_READTXPDU_NOTIFY_STATUS_API)  
        FALSE, /* CanIfTxPduReadData */ 
        #endif 
        #if((CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE) \
        &&(STD_ON == CANIF_PUBLIC_TX_BUFFERING))
        6   /* HthNextTxPduID */  
        #endif
    },
    /* 6 */ 
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        6,    /* CanIfTxPduUpperLayerHandle */ 
        #endif 

        0x784U, /* CanId*/ 
        STANDARD_CAN, /* CanIdType */ 
        7, /* CanIfTxPduHthIdRef */ 
        8, /* CanIfTxPduDlc */ 
        CanTp_TxConfirmation, /* CanIfTxPduUserTxConfirmationUL */ 
        #if(STD_ON == CANIF_PUBLIC_SETDYNAMICTXID_API)  
        STATIC_TXPDU, /* CanIfTxPduType */ 
        #endif 
        #if(STD_ON == CANIF_PUBLIC_READTXPDU_NOTIFY_STATUS_API)  
        FALSE, /* CanIfTxPduReadData */ 
        #endif 
        #if((CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE) \
        &&(STD_ON == CANIF_PUBLIC_TX_BUFFERING))
        CANIF_LAST_HOH_PDUID   /* HthNextTxPduID */  
        #endif
    }
#elif  E0X_DCM == E0X_DCM_RR
    /* 0 */ 
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        0,    /* CanIfTxPduUpperLayerHandle */ 
        #endif 
        
        0x2CEU, /* CanId*/ 
        STANDARD_CAN, /* CanIdType */ 
        1, /* CanIfTxPduHthIdRef */ 
        8, /* CanIfTxPduDlc */ 
        Com_TxConfirmation, /* CanIfTxPduUserTxConfirmationUL */ 
        #if(STD_ON == CANIF_PUBLIC_SETDYNAMICTXID_API)  
        STATIC_TXPDU, /* CanIfTxPduType */ 
        #endif 
        #if(STD_ON == CANIF_PUBLIC_READTXPDU_NOTIFY_STATUS_API)  
        FALSE, /* CanIfTxPduReadData */ 
        #endif 
        #if((CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE) \
        &&(STD_ON == CANIF_PUBLIC_TX_BUFFERING))
        1   /* HthNextTxPduID */  
        #endif
    },
    /* 1 */ 
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        1,    /* CanIfTxPduUpperLayerHandle */ 
        #endif 
        
        0x3BEU, /* CanId*/ 
        STANDARD_CAN, /* CanIdType */ 
        2, /* CanIfTxPduHthIdRef */ 
        8, /* CanIfTxPduDlc */ 
        Com_TxConfirmation, /* CanIfTxPduUserTxConfirmationUL */ 
        #if(STD_ON == CANIF_PUBLIC_SETDYNAMICTXID_API)  
        STATIC_TXPDU, /* CanIfTxPduType */ 
        #endif 
        #if(STD_ON == CANIF_PUBLIC_READTXPDU_NOTIFY_STATUS_API)  
        FALSE, /* CanIfTxPduReadData */ 
        #endif 
        #if((CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE) \
        &&(STD_ON == CANIF_PUBLIC_TX_BUFFERING))
        2   /* HthNextTxPduID */  
        #endif
    },
        /* 2 */ 
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        2,    /* CanIfTxPduUpperLayerHandle */ 
        #endif 
        
        0x463U, /* CanId*/ 
        STANDARD_CAN, /* CanIdType */ 
        3, /* CanIfTxPduHthIdRef */ 
        8, /* CanIfTxPduDlc */ 
        Com_TxConfirmation, /* CanIfTxPduUserTxConfirmationUL */ 
        #if(STD_ON == CANIF_PUBLIC_SETDYNAMICTXID_API)  
        STATIC_TXPDU, /* CanIfTxPduType */ 
        #endif 
        #if(STD_ON == CANIF_PUBLIC_READTXPDU_NOTIFY_STATUS_API)  
        FALSE, /* CanIfTxPduReadData */ 
        #endif 
        #if((CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE) \
        &&(STD_ON == CANIF_PUBLIC_TX_BUFFERING))
        3   /* HthNextTxPduID */  
        #endif
    },  
        /* 3 */ 
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        3,    /* CanIfTxPduUpperLayerHandle */ 
        #endif 
        
        0x589U, /* CanId*/ 
        STANDARD_CAN, /* CanIdType */ 
        4, /* CanIfTxPduHthIdRef */ 
        8, /* CanIfTxPduDlc */ 
        Com_TxConfirmation, /* CanIfTxPduUserTxConfirmationUL */ 
        #if(STD_ON == CANIF_PUBLIC_SETDYNAMICTXID_API)  
        STATIC_TXPDU, /* CanIfTxPduType */ 
        #endif 
        #if(STD_ON == CANIF_PUBLIC_READTXPDU_NOTIFY_STATUS_API)  
        FALSE, /* CanIfTxPduReadData */ 
        #endif 
        #if((CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE) \
        &&(STD_ON == CANIF_PUBLIC_TX_BUFFERING))
        4   /* HthNextTxPduID */  
        #endif
    },     
    /* 4 */ 
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        0,    /* CanIfTxPduUpperLayerHandle */ 
        #endif 
        
        0x65BU, /* CanId*/ 
        STANDARD_CAN, /* CanIdType */ 
        5, /* CanIfTxPduHthIdRef */ 
        8, /* CanIfTxPduDlc */ 
        CanNm_TxConfirmation, /* CanIfTxPduUserTxConfirmationUL */ 
        #if(STD_ON == CANIF_PUBLIC_SETDYNAMICTXID_API)  
        STATIC_TXPDU, /* CanIfTxPduType */ 
        #endif 
        #if(STD_ON == CANIF_PUBLIC_READTXPDU_NOTIFY_STATUS_API)  
        FALSE, /* CanIfTxPduReadData */ 
        #endif 
        #if((CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE) \
        &&(STD_ON == CANIF_PUBLIC_TX_BUFFERING))
        5   /* HthNextTxPduID */  
        #endif
    },
        /* 5 */ 
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        0,    /* CanIfTxPduUpperLayerHandle */ 
        #endif 
        
        0x702U, /* CanId*/ 
        STANDARD_CAN, /* CanIdType */ 
        6, /* CanIfTxPduHthIdRef */ 
        8, /* CanIfTxPduDlc */ 
        Xcp_CanIfTxConfirmation, /* CanIfTxPduUserTxConfirmationUL */ 
        #if(STD_ON == CANIF_PUBLIC_SETDYNAMICTXID_API)  
        STATIC_TXPDU, /* CanIfTxPduType */ 
        #endif 
        #if(STD_ON == CANIF_PUBLIC_READTXPDU_NOTIFY_STATUS_API)  
        FALSE, /* CanIfTxPduReadData */ 
        #endif 
        #if((CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE) \
        &&(STD_ON == CANIF_PUBLIC_TX_BUFFERING))
        6   /* HthNextTxPduID */  
        #endif
    },
    /* 6 */ 
    {
        #if (STD_ON == CANIF_UPPER_LAYER_HANDLE)
        6,    /* CanIfTxPduUpperLayerHandle */ 
        #endif 

        0x785U, /* CanId*/ 
        STANDARD_CAN, /* CanIdType */ 
        7, /* CanIfTxPduHthIdRef */ 
        8, /* CanIfTxPduDlc */ 
        CanTp_TxConfirmation, /* CanIfTxPduUserTxConfirmationUL */ 
        #if(STD_ON == CANIF_PUBLIC_SETDYNAMICTXID_API)  
        STATIC_TXPDU, /* CanIfTxPduType */ 
        #endif 
        #if(STD_ON == CANIF_PUBLIC_READTXPDU_NOTIFY_STATUS_API)  
        FALSE, /* CanIfTxPduReadData */ 
        #endif 
        #if((CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE) \
        &&(STD_ON == CANIF_PUBLIC_TX_BUFFERING))
        CANIF_LAST_HOH_PDUID   /* HthNextTxPduID */  
        #endif
    }   
#else
#error "the define E0X_DCM is error!"
#endif    
}; 




#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
//#include "MemMap.h"
