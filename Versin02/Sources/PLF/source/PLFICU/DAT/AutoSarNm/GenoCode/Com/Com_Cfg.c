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
#include "Com.h"

#if(COM_TXIPDUNUM >= 1u)

/*******************************************************************************
*   Tx Msg Buffer 
*******************************************************************************/
#define COM_START_SEC_VAR_UNSPECIFIED 
//#include "MemMap.h"
#if  E0X_DCM == E0X_DCM_FL
VAR(IpduDCM_1_bufType, COM_PRIVATE_DATA) TxIpduFLDCM_1;
VAR(IpduDCM_2_bufType, COM_PRIVATE_DATA) TxIpduFLDCM_2;
VAR(IpduDCM_3_bufType, COM_PRIVATE_DATA) TxIpduFLDCM_3;
VAR(IpduDCM_RemoteDiag_bufType, COM_PRIVATE_DATA) TxIpduFLDCM_RemoteDiag;
#elif  E0X_DCM == E0X_DCM_FR
VAR(IpduDCM_1_bufType, COM_PRIVATE_DATA) TxIpduFRDCM_1;
VAR(IpduDCM_2_bufType, COM_PRIVATE_DATA) TxIpduFRDCM_2;
VAR(IpduDCM_3_bufType, COM_PRIVATE_DATA) TxIpduFRDCM_3;
VAR(IpduDCM_RemoteDiag_bufType, COM_PRIVATE_DATA) TxIpduFRDCM_RemoteDiag;
#elif  E0X_DCM == E0X_DCM_RL
VAR(IpduDCM_1_bufType, COM_PRIVATE_DATA) TxIpduRLDCM_1;
VAR(IpduDCM_2_bufType, COM_PRIVATE_DATA) TxIpduRLDCM_2;
VAR(IpduDCM_3_bufType, COM_PRIVATE_DATA) TxIpduRLDCM_3;
VAR(IpduDCM_RemoteDiag_bufType, COM_PRIVATE_DATA) TxIpduRLDCM_RemoteDiag;
#elif  E0X_DCM == E0X_DCM_RR
VAR(IpduDCM_1_bufType, COM_PRIVATE_DATA) TxIpduRRDCM_1;
VAR(IpduDCM_2_bufType, COM_PRIVATE_DATA) TxIpduRRDCM_2;
VAR(IpduDCM_3_bufType, COM_PRIVATE_DATA) TxIpduRRDCM_3;
VAR(IpduDCM_RemoteDiag_bufType, COM_PRIVATE_DATA) TxIpduRRDCM_RemoteDiag;
#else
#error "the define E0X_DCM is error!"
#endif
#define COM_STOP_SEC_VAR_UNSPECIFIED 
//#include "MemMap.h"

/*******************************************************************************
*   for Tx Message and Signals 
*******************************************************************************/
#define COM_START_SEC_CONFIG_DATA_UNSPECIFIED 
//#include "MemMap.h"

CONST(IpduDCM_1_bufType, COM_CONFIG_CONST) TxIpduDCM_1DefaultValue = 
{
    {
        0,0,0,0,0,0,0,0
    }
};

CONST(IpduDCM_2_bufType, COM_CONFIG_CONST) TxIpduDCM_2DefaultValue = 
{
    {
        0,0,0,0,0,0,0,0
    }
};

CONST(IpduDCM_3_bufType, COM_CONFIG_CONST) TxIpduDCM_3DefaultValue = 
{
    {
        0,0,0,0,0,0,0,0
    }
};

CONST(IpduDCM_RemoteDiag_bufType, COM_CONFIG_CONST)  TxIpduDCM_RemoteDiagDefaultValue = 
{
    {
        0,0,0,0,0,0,0,0
    }
};

CONST(PduInfoType, COM_CONFIG_CONST) Com_TxIpduInitTable[COM_TXIPDUNUM] = 
{
#if  E0X_DCM == E0X_DCM_FL	
    {TxIpduFLDCM_2._c, 8U},
    {TxIpduFLDCM_1._c, 8U},
    {TxIpduFLDCM_3._c, 8U},
    {TxIpduFLDCM_RemoteDiag._c, 8U}
#elif  E0X_DCM == E0X_DCM_FR 
    {TxIpduFRDCM_2._c, 8U},
    {TxIpduFRDCM_1._c, 8U},
    {TxIpduFRDCM_3._c, 8U},
    {TxIpduFRDCM_RemoteDiag._c, 8U}
#elif  E0X_DCM == E0X_DCM_RL 
    {TxIpduRLDCM_2._c, 8U},
    {TxIpduRLDCM_1._c, 8U},
    {TxIpduRLDCM_3._c, 8U},
    {TxIpduRLDCM_RemoteDiag._c, 8U}
#elif  E0X_DCM == E0X_DCM_RR 
    {TxIpduRRDCM_2._c, 8U},
    {TxIpduRRDCM_1._c, 8U},
    {TxIpduRRDCM_3._c, 8U},
    {TxIpduRRDCM_RemoteDiag._c, 8U}
#else
#error "the define E0X_DCM is error!"
#endif    
};

CONST(uint8, COM_CONFIG_CONST) Com_TxIpduSigNum[COM_TXIPDUNUM] = 
{
    8U,
    20U,
    6U,
    7U
};

CONST(Com_TxSigTableType, COM_CONFIG_CONST) Com_TxSigTable[COM_TXSIGNUM] = 
{
    {0U, COM_SENDTYPECYCLIC | COM_SENDTYPEIFACTIVE, (Com_SigInActiveType*)0},
    {0U, COM_SENDTYPECYCLIC | COM_SENDTYPEIFACTIVE, (Com_SigInActiveType*)0},
    {0U, COM_SENDTYPECYCLIC | COM_SENDTYPEIFACTIVE, (Com_SigInActiveType*)0},
    {0U, COM_SENDTYPECYCLIC | COM_SENDTYPEIFACTIVE, (Com_SigInActiveType*)0},
    {0U, COM_SENDTYPECYCLIC | COM_SENDTYPEIFACTIVE, (Com_SigInActiveType*)0},
    {0U, COM_SENDTYPECYCLIC | COM_SENDTYPEIFACTIVE, (Com_SigInActiveType*)0},
    {0U, COM_SENDTYPECYCLIC | COM_SENDTYPEIFACTIVE, (Com_SigInActiveType*)0},
    {0U, COM_SENDTYPECYCLIC | COM_SENDTYPEIFACTIVE, (Com_SigInActiveType*)0},
    {1U, COM_SENDTYPECYCLIC | COM_SENDTYPEIFACTIVE, (Com_SigInActiveType*)0},
    {1U, COM_SENDTYPECYCLIC | COM_SENDTYPEIFACTIVE, (Com_SigInActiveType*)0},
    {1U, COM_SENDTYPECYCLIC | COM_SENDTYPEIFACTIVE, (Com_SigInActiveType*)0},
    {1U, COM_SENDTYPECYCLIC | COM_SENDTYPEIFACTIVE, (Com_SigInActiveType*)0},
    {1U, COM_SENDTYPECYCLIC | COM_SENDTYPEIFACTIVE, (Com_SigInActiveType*)0},
    {1U, COM_SENDTYPECYCLIC | COM_SENDTYPEIFACTIVE, (Com_SigInActiveType*)0},
    {1U, COM_SENDTYPECYCLIC | COM_SENDTYPEIFACTIVE, (Com_SigInActiveType*)0},
    {1U, COM_SENDTYPECYCLIC | COM_SENDTYPEIFACTIVE, (Com_SigInActiveType*)0},
    {1U, COM_SENDTYPECYCLIC | COM_SENDTYPEIFACTIVE, (Com_SigInActiveType*)0},
    {1U, COM_SENDTYPECYCLIC | COM_SENDTYPEIFACTIVE, (Com_SigInActiveType*)0},
    {1U, COM_SENDTYPECYCLIC | COM_SENDTYPEIFACTIVE, (Com_SigInActiveType*)0},
    {1U, COM_SENDTYPECYCLIC | COM_SENDTYPEIFACTIVE, (Com_SigInActiveType*)0},
    {1U, COM_SENDTYPECYCLIC | COM_SENDTYPEIFACTIVE, (Com_SigInActiveType*)0},
    {1U, COM_SENDTYPECYCLIC | COM_SENDTYPEIFACTIVE, (Com_SigInActiveType*)0},
    {1U, COM_SENDTYPECYCLIC | COM_SENDTYPEIFACTIVE, (Com_SigInActiveType*)0},
    {1U, COM_SENDTYPECYCLIC | COM_SENDTYPEIFACTIVE, (Com_SigInActiveType*)0},
    {1U, COM_SENDTYPECYCLIC | COM_SENDTYPEIFACTIVE, (Com_SigInActiveType*)0},
    {1U, COM_SENDTYPECYCLIC | COM_SENDTYPEIFACTIVE, (Com_SigInActiveType*)0},
    {1U, COM_SENDTYPECYCLIC | COM_SENDTYPEIFACTIVE, (Com_SigInActiveType*)0},
    {1U, COM_SENDTYPECYCLIC | COM_SENDTYPEIFACTIVE, (Com_SigInActiveType*)0},
    {2U, COM_SENDTYPECYCLIC | COM_SENDTYPEIFACTIVE, (Com_SigInActiveType*)0},
    {2U, COM_SENDTYPECYCLIC | COM_SENDTYPEIFACTIVE, (Com_SigInActiveType*)0},
    {2U, COM_SENDTYPECYCLIC | COM_SENDTYPEIFACTIVE, (Com_SigInActiveType*)0},
    {2U, COM_SENDTYPECYCLIC | COM_SENDTYPEIFACTIVE, (Com_SigInActiveType*)0},
    {2U, COM_SENDTYPECYCLIC | COM_SENDTYPEIFACTIVE, (Com_SigInActiveType*)0},
    {2U, COM_SENDTYPECYCLIC | COM_SENDTYPEIFACTIVE, (Com_SigInActiveType*)0},
    {3U, COM_SENDTYPECYCLIC | COM_SENDTYPEIFACTIVE, (Com_SigInActiveType*)0},
    {3U, COM_SENDTYPECYCLIC | COM_SENDTYPEIFACTIVE, (Com_SigInActiveType*)0},
    {3U, COM_SENDTYPECYCLIC | COM_SENDTYPEIFACTIVE, (Com_SigInActiveType*)0},
    {3U, COM_SENDTYPECYCLIC | COM_SENDTYPEIFACTIVE, (Com_SigInActiveType*)0},
    {3U, COM_SENDTYPECYCLIC | COM_SENDTYPEIFACTIVE, (Com_SigInActiveType*)0},
    {3U, COM_SENDTYPECYCLIC | COM_SENDTYPEIFACTIVE, (Com_SigInActiveType*)0},
    {3U, COM_SENDTYPECYCLIC | COM_SENDTYPEIFACTIVE, (Com_SigInActiveType*)0}
};

CONSTP2CONST(uint8,COM_CONFIG_CONST,COM_CONFIG_CONST ) Com_TxIpduDefaultValue[COM_TXIPDUNUM] = 
{
    TxIpduDCM_2DefaultValue._c,
    TxIpduDCM_1DefaultValue._c,
    TxIpduDCM_3DefaultValue._c,
    TxIpduDCM_RemoteDiagDefaultValue._c,
};

CONST(uint8, COM_CONFIG_CONST) Com_TxIpduTable[COM_TXIPDUNUM] = 
{
    (COM_SENDTYPECYCLIC | COM_SENDTYPETIMEOUTMONITOR),
    (COM_SENDTYPECYCLIC | COM_SENDTYPETIMEOUTMONITOR),
    (COM_SENDTYPECYCLIC | COM_SENDTYPETIMEOUTMONITOR),
    (COM_SENDTYPECYCLIC | COM_SENDTYPETIMEOUTMONITOR)
};

CONST(uint16, COM_CONFIG_CONST) Com_TxIpduCycleTable[COM_TXIPDUNUM] = 
{
    20U,
    50U,
    100U,
    500U
};

CONST(uint16, COM_CONFIG_CONST) Com_TxIpduFastCycleTable[COM_TXIPDUNUM] = 
{
    0U,
    0U,
    0U,
    0U
};

CONST(Com_SignalIdType, COM_CONFIG_CONST) Com_TxSigOffsetTable[COM_TXIPDUNUM] = 
{
    0U,
    0U,
    0U,
    0U
};

CONST(uint16, COM_CONFIG_CONST) Com_TxIpduTdelayTable[COM_TXIPDUNUM] = 
{
    0U,
    0U,
    0U,
    0U
};

CONST(uint8, COM_CONFIG_CONST) Com_TxIpduRepNumTable[COM_TXIPDUNUM] = 
{
    0U,
    0U,
    0U,
    0U
};

CONST(uint16, COM_CONFIG_CONST) Com_TxIpduTimeOutTable[COM_TXIPDUNUM] = 
{
    30U,
    30U,
    30U,
    30U
};

CONST(uint16, COM_CONFIG_CONST) Com_TxIpduOffsetTable[COM_TXIPDUNUM] = 
{
    0U,
    0U,
    0U,
    0U
};

#ifdef COM_ENABLE_TXTOINDFUN
CONST(Com_TOIndicationType, COM_CONFIG_CONST) Com_TxIpduTOIndicationTable[COM_TXIPDUNUM] = 
{
    &AppIpduDCM_2_TxTOIndication,
    &AppIpduDCM_1_TxTOIndication,
    &AppIpduDCM_3_TxTOIndication,
    &AppIpduDCM_RemoteDiag_TxTOIndication
};
#endif

#ifdef COM_ENABLE_TXCONFIRMATIONFUN
CONST(Com_TxConfirmationType, COM_CONFIG_CONST) Com_TxIpduConfirmTable[COM_TXIPDUNUM] = 
{
    &AppIpduDCM_2_Conf,
    &AppIpduDCM_1_Conf,
    &AppIpduDCM_3_Conf,
    &AppIpduDCM_RemoteDiag_Conf
};
#endif

CONST(PduIdType, COM_CONFIG_CONST) Com_TxIpduIdMapTable[COM_TXIPDUNUM]=
{
    0U,
    1U,
    2U,
    3U
};
 
#define COM_STOP_SEC_CONFIG_DATA_UNSPECIFIED 
//#include "MemMap.h"
 
#endif /*#if(COM_TXIPDUNUM>=1)*/

#if(COM_RXIPDUNUM >= 1u)

/*******************************************************************************
*   Rx Msg Buffer 
*******************************************************************************/
#define COM_START_SEC_VAR_UNSPECIFIED 
//#include "MemMap.h"
VAR(IpduACU_3_bufType, COM_PRIVATE_DATA)  RxIpduACU_3;
VAR(IpduACU_2_bufType, COM_PRIVATE_DATA)  RxIpduACU_2;

VAR(IpduFLZCU_1_bufType, COM_PRIVATE_DATA)  RxIpduFLZCU_1;
VAR(IpduFRZCU_2_bufType, COM_PRIVATE_DATA)  RxIpduFRZCU_2;
VAR(IpduBNCM_14_bufType, COM_PRIVATE_DATA)  RxIpduBNCM_14;
VAR(IpduFRZCU_1_bufType, COM_PRIVATE_DATA)  RxIpduFRZCU_1;
VAR(IpduRZCU_2_bufType, COM_PRIVATE_DATA)  RxIpduRZCU_2;

#if  E0X_DCM == E0X_DCM_FL
VAR(IpduRCM_1_bufType, COM_PRIVATE_DATA)  RxIpduRCM_1;
VAR(IpduRCM_3_bufType, COM_PRIVATE_DATA)  RxIpduRCM_3;
VAR(IpduDRM_1_bufType, COM_PRIVATE_DATA)  RxIpduFLDRM_1;
#elif  E0X_DCM == E0X_DCM_FR
VAR(IpduRCM_2_bufType, COM_PRIVATE_DATA)  RxIpduRCM_2;
VAR(IpduRCM_4_bufType, COM_PRIVATE_DATA)  RxIpduRCM_4;
VAR(IpduDRM_1_bufType, COM_PRIVATE_DATA)  RxIpduFRDRM_1;
#elif  E0X_DCM == E0X_DCM_RL
VAR(IpduRCM_1_bufType, COM_PRIVATE_DATA)  RxIpduRCM_1;
VAR(IpduRCM_3_bufType, COM_PRIVATE_DATA)  RxIpduRCM_3;
VAR(IpduDRM_1_bufType, COM_PRIVATE_DATA)  RxIpduRLDRM_1;
#elif  E0X_DCM == E0X_DCM_RR
VAR(IpduRCM_2_bufType, COM_PRIVATE_DATA)  RxIpduRCM_2;
VAR(IpduRCM_4_bufType, COM_PRIVATE_DATA)  RxIpduRCM_4;
VAR(IpduDRM_1_bufType, COM_PRIVATE_DATA)  RxIpduRRDRM_1;
#else
#error "the define E0X_DCM is error!"
#endif

VAR(IpduASU_2_bufType, COM_PRIVATE_DATA)  RxIpduASU_2;
VAR(IpduVCC_4_bufType, COM_PRIVATE_DATA)  RxIpduVCC_4;
VAR(IpduVCC_5_bufType, COM_PRIVATE_DATA)  RxIpduVCC_5;
VAR(IpduVCC_6_bufType, COM_PRIVATE_DATA)  RxIpduVCC_6;
VAR(IpduBNCM_1_bufType, COM_PRIVATE_DATA)  RxIpduBNCM_1;
VAR(IpduFLZCU_5_bufType, COM_PRIVATE_DATA)  RxIpduFLZCU_5;

#if  E0X_DCM == E0X_DCM_FL 
VAR(IpduDCM_1_bufType, COM_PRIVATE_DATA) RxIpduFRDCM_1;
VAR(IpduDCM_1_bufType, COM_PRIVATE_DATA)  RxIpduRLDCM_1;
VAR(IpduDCM_1_bufType, COM_PRIVATE_DATA) RxIpduRRDCM_1;

#elif  E0X_DCM == E0X_DCM_FR 
VAR(IpduDCM_1_bufType, COM_PRIVATE_DATA) RxIpduFLDCM_1;
VAR(IpduDCM_1_bufType, COM_PRIVATE_DATA)  RxIpduRLDCM_1;
VAR(IpduDCM_1_bufType, COM_PRIVATE_DATA) RxIpduRRDCM_1;

#elif  E0X_DCM == E0X_DCM_RL 
VAR(IpduDCM_1_bufType, COM_PRIVATE_DATA) RxIpduFLDCM_1;
VAR(IpduDCM_1_bufType, COM_PRIVATE_DATA) RxIpduFRDCM_1;
VAR(IpduDCM_1_bufType, COM_PRIVATE_DATA) RxIpduRRDCM_1;

#elif  E0X_DCM == E0X_DCM_RR 
VAR(IpduDCM_1_bufType, COM_PRIVATE_DATA) RxIpduFLDCM_1;
VAR(IpduDCM_1_bufType, COM_PRIVATE_DATA) RxIpduFRDCM_1;
VAR(IpduDCM_1_bufType, COM_PRIVATE_DATA)  RxIpduRLDCM_1;

#else
#error "the define E0X_DCM is error!"
#endif 

VAR(IpduVCC_1_bufType, COM_PRIVATE_DATA) RxIpduVCC_1;
VAR(IpduVCC_2_bufType, COM_PRIVATE_DATA)  RxIpduVCC_2;
VAR(IpduRLCR_1_bufType, COM_PRIVATE_DATA) RxIpduRLCR_1;
VAR(IpduRLCR_2_bufType, COM_PRIVATE_DATA) RxIpduRLCR_2;
VAR(IpduICC_BD_11_bufType, COM_PRIVATE_DATA) RxIpduICC_BD_11;
VAR(IpduONEBOX_1_G_bufType, COM_PRIVATE_DATA) RxIpduONEBOX_1_G;
VAR(IpduRZCU_1_bufType, COM_PRIVATE_DATA) RxIpduRZCU_1;
VAR(IpduBNCM_15_bufType, COM_PRIVATE_DATA) RxIpduBNCM_15;
VAR(IpduTMS_1_bufType, COM_PRIVATE_DATA) RxIpduTMS_1;
VAR(IpduACU_1_bufType, COM_PRIVATE_DATA) RxIpduACU_1;
VAR(IpduFLZCU_9_bufType, COM_PRIVATE_DATA) RxIpduFLZCU_9;
VAR(IpduBNCM_6_bufType, COM_PRIVATE_DATA) RxIpduBNCM_6;
VAR(IpduVCU_1_G_bufType, COM_PRIVATE_DATA)  RxIpduVCU_1_G;

VAR(IpduVCU_2_G_bufType, COM_PRIVATE_DATA) RxIpduVCU_2_G;
VAR(IpduASU_1_bufType, COM_PRIVATE_DATA) RxIpduASU_1;
VAR(IpduICC_COM_1_bufType, COM_PRIVATE_DATA) RxIpduICC_COM_1;
VAR(IpduRRCR_1_bufType, COM_PRIVATE_DATA) RxIpduRRCR_1;
VAR(IpduPEPS_3_bufType, COM_PRIVATE_DATA) RxIpduPEPS_3;
VAR(IpduICC_COM_16_bufType, COM_PRIVATE_DATA)  RxIpduICC_COM_16;
VAR(IpduICC_COM_8_bufType, COM_PRIVATE_DATA)  RxIpduICC_COM_8;

#define COM_STOP_SEC_VAR_UNSPECIFIED 
//#include "MemMap.h"

/*******************************************************************************
*   for Rx Message and Signals 
*******************************************************************************/
#define COM_START_SEC_CONFIG_DATA_UNSPECIFIED 
//#include "MemMap.h"

CONST(IpduACU_3_bufType, COM_PRIVATE_DATA)  RxIpduACU_3DefaultValue = 
{
    {
        0,0,0,0,0,0,0,0
    }
};
CONST(IpduACU_2_bufType, COM_PRIVATE_DATA)  RxIpduACU_2DefaultValue = 
{
    {
        0,0,0,0,0,0,0,0
    }
};

CONST(IpduFLZCU_1_bufType, COM_PRIVATE_DATA)  RxIpduFLZCU_1DefaultValue = 
{
    {
        0,0,0,0,0,0,0,0
    }
};
CONST(IpduFRZCU_2_bufType, COM_PRIVATE_DATA)  RxIpduFRZCU_2DefaultValue = 
{
    {
        0,0,0,0,0,0,0,0
    }
};
CONST(IpduFRZCU_1_bufType, COM_PRIVATE_DATA)  RxIpduFRZCU_1DefaultValue = 
{
    {
        0,0,0,0,0,0,0,0
    }
};
CONST(IpduRZCU_2_bufType, COM_PRIVATE_DATA)  RxIpduRZCU_2DefaultValue = 
{
    {
        0,0,0,0,0,0,0,0
    }
};

#if  E0X_DCM == E0X_DCM_FL
CONST(IpduRCM_1_bufType, COM_PRIVATE_DATA)  RxIpduRCM_1DefaultValue = 
{
    {
        0,0,0,0,0,0,0,0
    }
};
CONST(IpduRCM_3_bufType, COM_PRIVATE_DATA)  RxIpduRCM_3DefaultValue = 
{
    {
        0,0,0,0,0,0,0,0
    }
};
CONST(IpduDRM_1_bufType, COM_PRIVATE_DATA)  RxIpduFLDRM_1DefaultValue = 
{
    {
        0,0,0,0,0,0,0,0
    }
};
#elif  E0X_DCM == E0X_DCM_FR
CONST(IpduRCM_2_bufType, COM_PRIVATE_DATA)  RxIpduRCM_2DefaultValue = 
{
    {
        0,0,0,0,0,0,0,0
    }
};
CONST(IpduRCM_4_bufType, COM_PRIVATE_DATA)  RxIpduRCM_4DefaultValue = 
{
    {
        0,0,0,0,0,0,0,0
    }
};
CONST(IpduDRM_1_bufType, COM_PRIVATE_DATA)  RxIpduFRDRM_1DefaultValue = 
{
    {
        0,0,0,0,0,0,0,0
    }
};
#elif  E0X_DCM == E0X_DCM_RL
CONST(IpduRCM_1_bufType, COM_PRIVATE_DATA)  RxIpduRCM_1DefaultValue = 
{
    {
        0,0,0,0,0,0,0,0
    }
};
CONST(IpduRCM_3_bufType, COM_PRIVATE_DATA)  RxIpduRCM_3DefaultValue = 
{
    {
        0,0,0,0,0,0,0,0
    }
};
CONST(IpduDRM_1_bufType, COM_PRIVATE_DATA)  RxIpduRLDRM_1DefaultValue = 
{
    {
        0,0,0,0,0,0,0,0
    }
};
#elif  E0X_DCM == E0X_DCM_RR
CONST(IpduRCM_2_bufType, COM_PRIVATE_DATA)  RxIpduRCM_2DefaultValue = 
{
    {
        0,0,0,0,0,0,0,0
    }
};
CONST(IpduRCM_4_bufType, COM_PRIVATE_DATA)  RxIpduRCM_4DefaultValue = 
{
    {
        0,0,0,0,0,0,0,0
    }
};
CONST(IpduDRM_1_bufType, COM_PRIVATE_DATA)  RxIpduRRDRM_1DefaultValue = 
{
    {
        0,0,0,0,0,0,0,0
    }
};
#else
#error "the define E0X_DCM is error!"
#endif

CONST(IpduASU_2_bufType, COM_PRIVATE_DATA)  RxIpduASU_2DefaultValue = 
{
    {
        0,0,0,0,0,0,0,0
    }
};

CONST(IpduBNCM_1_bufType, COM_PRIVATE_DATA)  RxIpduBNCM_1DefaultValue = 
{
    {
        0,0,0,0,0,0,0,0
    }
};
#if  E0X_DCM == E0X_DCM_FL 
CONST(IpduDCM_1_bufType, COM_PRIVATE_DATA) RxIpduFRDCM_1DefaultValue = 
{
    {
        0,0,0,0,0,0,0,0
    }
};
CONST(IpduDCM_1_bufType, COM_PRIVATE_DATA)  RxIpduRLDCM_1DefaultValue = 
{
    {
        0,0,0,0,0,0,0,0
    }
};
CONST(IpduDCM_1_bufType, COM_PRIVATE_DATA) RxIpduRRDCM_1DefaultValue = 
{
    {
        0,0,0,0,0,0,0,0
    }
};
#elif  E0X_DCM == E0X_DCM_FR 
CONST(IpduDCM_1_bufType, COM_PRIVATE_DATA) RxIpduFLDCM_1DefaultValue = 
{
    {
        0,0,0,0,0,0,0,0
    }
};
CONST(IpduDCM_1_bufType, COM_PRIVATE_DATA)  RxIpduRLDCM_1DefaultValue = 
{
    {
        0,0,0,0,0,0,0,0
    }
};
CONST(IpduDCM_1_bufType, COM_PRIVATE_DATA) RxIpduRRDCM_1DefaultValue = 
{
    {
        0,0,0,0,0,0,0,0
    }
};
#elif  E0X_DCM == E0X_DCM_RL 
CONST(IpduDCM_1_bufType, COM_PRIVATE_DATA) RxIpduFLDCM_1DefaultValue = 
{
    {
        0,0,0,0,0,0,0,0
    }
};
CONST(IpduDCM_1_bufType, COM_PRIVATE_DATA) RxIpduFRDCM_1DefaultValue = 
{
    {
        0,0,0,0,0,0,0,0
    }
};
CONST(IpduDCM_1_bufType, COM_PRIVATE_DATA) RxIpduRRDCM_1DefaultValue = 
{
    {
        0,0,0,0,0,0,0,0
    }
};
#elif  E0X_DCM == E0X_DCM_RR 
CONST(IpduDCM_1_bufType, COM_PRIVATE_DATA) RxIpduFLDCM_1DefaultValue = 
{
    {
        0,0,0,0,0,0,0,0
    }
};
CONST(IpduDCM_1_bufType, COM_PRIVATE_DATA) RxIpduFRDCM_1DefaultValue = 
{
    {
        0,0,0,0,0,0,0,0
    }
};
CONST(IpduDCM_1_bufType, COM_PRIVATE_DATA)  RxIpduRLDCM_1DefaultValue = 
{
    {
        0,0,0,0,0,0,0,0
    }
};
#else
#error "the define E0X_DCM is error!"
#endif 

CONST(IpduASU_1_bufType, COM_PRIVATE_DATA) RxIpduASU_1DefaultValue = 
{
    {
        0,0,0,0,0,0,0,0
    }
};

CONST(IpduRRCR_1_bufType, COM_PRIVATE_DATA) RxIpduRRCR_1DefaultValue = 
{
    {
        0,0,0,0,0,0,0,0
    }
};

CONST(IpduRLCR_1_bufType, COM_PRIVATE_DATA) RxIpduRLCR_1DefaultValue = 
{
    {
        0,0,0,0,0,0,0,0
    }
};

CONST(IpduRLCR_2_bufType, COM_PRIVATE_DATA) RxIpduRLCR_2DefaultValue = 
{
    {
        0,0,0,0,0,0,0,0
    }
};


CONST(IpduICC_BD_11_bufType, COM_PRIVATE_DATA) RxIpduICC_BD_11DefaultValue = 
{
    {
        0,0,0,0,0,0,0,0
    }
};


CONST(IpduONEBOX_1_G_bufType, COM_PRIVATE_DATA) RxIpduONEBOX_1_GDefaultValue = 
{
    {
        0,0,0,0,0,0,0,0
    }
};
CONST(IpduRZCU_1_bufType, COM_PRIVATE_DATA) RxIpduRZCU_1DefaultValue = 
{
    {
        0,0,0,0,0,0,0,0
    }
};
CONST(IpduTMS_1_bufType, COM_PRIVATE_DATA) RxIpduTMS_1DefaultValue = 
{
    {
        0,0,0,0,0,0,0,0
    }
};

CONST(IpduACU_1_bufType, COM_PRIVATE_DATA) RxIpduACU_1DefaultValue = 
{
    {
        0,0,0,0,0,0,0,0
    }
};

CONST(IpduFLZCU_9_bufType, COM_PRIVATE_DATA) RxIpduFLZCU_9DefaultValue = 
{
    {
        0,0,0,0,0,0,0,0
    }
};
CONST(IpduBNCM_6_bufType, COM_PRIVATE_DATA) RxIpduBNCM_6DefaultValue = 
{
    {
        0,0,0,0,0,0,0,0
    }
};
CONST(IpduVCU_1_G_bufType, COM_PRIVATE_DATA)  RxIpduVCU_1_GDefaultValue = 
{
    {
        0,0,0,0,0,0,0,0
    }
};

CONST(IpduVCU_2_G_bufType, COM_PRIVATE_DATA) RxIpduVCU_2_GDefaultValue = 
{
    {
        0,0,0,0,0,0,0,0
    }
};
CONST(IpduICC_COM_1_bufType, COM_PRIVATE_DATA) RxIpduICC_COM_1DefaultValue = 
{
    {
        0,0,0,0,0,0,0,0
    }
};
CONST(IpduICC_COM_8_bufType, COM_PRIVATE_DATA)  RxIpduICC_COM_8DefaultValue = 
{
    {
        0,0,0,0,0,0,0,0
    }
};

CONST(IpduBNCM_14_bufType, COM_PRIVATE_DATA)  RxIpduBNCM_14DefaultValue = 
{
    {
        0,0,0,0,0,0,0,0
    }
};

CONST(IpduFLZCU_5_bufType, COM_PRIVATE_DATA)  RxIpduFLZCU_5DefaultValue = 
{
    {
        0,0,0,0,0,0,0,0
    }
};

CONST(IpduBNCM_15_bufType, COM_PRIVATE_DATA) RxIpduBNCM_15DefaultValue = 
{
    {
        0,0,0,0,0,0,0,0
    }
};

CONST(IpduVCC_1_bufType, COM_PRIVATE_DATA) RxIpduVCC_1DefaultValue = 
{
    {
        0,0,0,0,0,0,0,0
    }
};

CONST(IpduVCC_2_bufType, COM_PRIVATE_DATA) RxIpduVCC_2DefaultValue = 
{
    {
        0,0,0,0,0,0,0,0
    }
};

CONST(IpduVCC_4_bufType, COM_PRIVATE_DATA) RxIpduVCC_4DefaultValue = 
{
    {
        0,0,0,0,0,0,0,0
    }
};

CONST(IpduVCC_5_bufType, COM_PRIVATE_DATA) RxIpduVCC_5DefaultValue = 
{
    {
        0,0,0,0,0,0,0,0
    }
};

CONST(IpduVCC_6_bufType, COM_PRIVATE_DATA) RxIpduVCC_6DefaultValue = 
{
    {
        0,0,0,0,0,0,0,0
    }
};

CONST(IpduICC_COM_16_bufType, COM_PRIVATE_DATA) RxIpduICC_COM_16DefaultValue = 
{
    {
        0,0,0,0,0,0,0,0
    }
};
CONST(IpduPEPS_3_bufType, COM_PRIVATE_DATA) RxIpduPEPS_3DefaultValue = 
{
    {
        0,0,0,0,0,0,0,0
    }
};


CONST(PduInfoType, COM_CONFIG_CONST) Com_RxIpduInitTable[COM_RXIPDUNUM] = 
{
    {RxIpduACU_3._c, 8U},
    {RxIpduACU_2._c, 8U},
    {RxIpduFLZCU_1._c, 8U},
    {RxIpduFRZCU_2._c, 8U},
    {RxIpduBNCM_14._c, 8U},
    {RxIpduFRZCU_1._c, 8U},
    {RxIpduRZCU_2._c, 8U},
    
#if  E0X_DCM == E0X_DCM_FL
    {RxIpduRCM_1._c, 8U},
    {RxIpduRCM_3._c, 8U},
    {RxIpduFLDRM_1._c, 8U},
#elif  E0X_DCM == E0X_DCM_FR
    {RxIpduRCM_2._c, 8U},
    {RxIpduRCM_4._c, 8U},
    {RxIpduFRDRM_1._c, 8U},
#elif  E0X_DCM == E0X_DCM_RL
    {RxIpduRCM_1._c, 8U},
    {RxIpduRCM_3._c, 8U},
    {RxIpduRLDRM_1._c, 8U},
#elif  E0X_DCM == E0X_DCM_RR
    {RxIpduRCM_2._c, 8U},
    {RxIpduRCM_4._c, 8U},
    {RxIpduRRDRM_1._c, 8U},
#else
#error "the define E0X_DCM is error!"
#endif

    {RxIpduASU_2._c, 8U},
    {RxIpduVCC_4._c, 8U},
    {RxIpduVCC_5._c, 8U},
    {RxIpduVCC_6._c, 8U},
    {RxIpduBNCM_1._c, 8U},
    {RxIpduFLZCU_5._c, 8U},
    
#if  E0X_DCM == E0X_DCM_FL 
    {RxIpduFRDCM_1._c, 8U},
    {RxIpduRLDCM_1._c, 8U},
    {RxIpduRRDCM_1._c, 8U},
    
#elif  E0X_DCM == E0X_DCM_FR 
    {RxIpduFLDCM_1._c, 8U},
    {RxIpduRLDCM_1._c, 8U},
    {RxIpduRRDCM_1._c, 8U},
    
#elif  E0X_DCM == E0X_DCM_RL 
    {RxIpduFLDCM_1._c, 8U},
    {RxIpduFRDCM_1._c, 8U},
    {RxIpduRRDCM_1._c, 8U},
    
#elif  E0X_DCM == E0X_DCM_RR 
    {RxIpduFLDCM_1._c, 8U},
    {RxIpduFRDCM_1._c, 8U},
    {RxIpduRLDCM_1._c, 8U},
    
#else
#error "the define E0X_DCM is error!"
#endif 

    {RxIpduVCC_1._c, 8U},
    {RxIpduVCC_2._c, 8U},
    {RxIpduRLCR_1._c, 8U},
    {RxIpduRLCR_2._c, 8U},
    {RxIpduICC_BD_11._c, 8U},
    {RxIpduONEBOX_1_G._c, 8U},
    {RxIpduRZCU_1._c, 8U},
    {RxIpduBNCM_15._c, 8U},
    {RxIpduTMS_1._c, 8U},
    {RxIpduACU_1._c, 8U},
    {RxIpduFLZCU_9._c, 8U},
    {RxIpduBNCM_6._c, 8U},
    {RxIpduVCU_1_G._c, 8U},

    {RxIpduVCU_2_G._c, 8U},
    {RxIpduASU_1._c, 8U},
    {RxIpduICC_COM_1._c, 8U},
    {RxIpduRRCR_1._c, 8U},
    {RxIpduPEPS_3._c, 8U},
    {RxIpduICC_COM_16._c, 8U},
    {RxIpduICC_COM_8._c, 8U},
    
};

CONSTP2CONST(uint8,COM_CONFIG_CONST,COM_CONFIG_CONST ) Com_RxIpduDefaultValue[COM_RXIPDUNUM] = 
{
    RxIpduACU_3DefaultValue._c,
    RxIpduACU_2DefaultValue._c,

    RxIpduFLZCU_1DefaultValue._c,
    RxIpduFRZCU_2DefaultValue._c,
    RxIpduBNCM_14DefaultValue._c,
    RxIpduFRZCU_1DefaultValue._c,
    RxIpduRZCU_2DefaultValue._c,
    
#if  E0X_DCM == E0X_DCM_FL
    RxIpduRCM_1DefaultValue._c,
    RxIpduRCM_3DefaultValue._c, 
    RxIpduFLDRM_1DefaultValue._c,
#elif  E0X_DCM == E0X_DCM_FR
    RxIpduRCM_2DefaultValue._c,
    RxIpduRCM_4DefaultValue._c,
    RxIpduFRDRM_1DefaultValue._c,
#elif  E0X_DCM == E0X_DCM_RL
    RxIpduRCM_1DefaultValue._c,
    RxIpduRCM_3DefaultValue._c,
    RxIpduRLDRM_1DefaultValue._c,
#elif  E0X_DCM == E0X_DCM_RR
    RxIpduRCM_2DefaultValue._c,
    RxIpduRCM_4DefaultValue._c,
    RxIpduRRDRM_1DefaultValue._c,
#else
#error "the define E0X_DCM is error!"
#endif

    RxIpduASU_2DefaultValue._c,
    RxIpduVCC_4DefaultValue._c,
    RxIpduVCC_5DefaultValue._c,
    RxIpduVCC_6DefaultValue._c,
    RxIpduBNCM_1DefaultValue._c,
    RxIpduFLZCU_5DefaultValue._c,
    
#if  E0X_DCM == E0X_DCM_FL 
    RxIpduFRDCM_1DefaultValue._c,
    RxIpduRLDCM_1DefaultValue._c,
    RxIpduRRDCM_1DefaultValue._c,
   
#elif  E0X_DCM == E0X_DCM_FR 
    RxIpduFLDCM_1DefaultValue._c,
    RxIpduRLDCM_1DefaultValue._c,
    RxIpduRRDCM_1DefaultValue._c,
    
#elif  E0X_DCM == E0X_DCM_RL 
    RxIpduFLDCM_1DefaultValue._c,
    RxIpduFRDCM_1DefaultValue._c,
    RxIpduRRDCM_1DefaultValue._c,
    
#elif  E0X_DCM == E0X_DCM_RR 
    RxIpduFLDCM_1DefaultValue._c,
    RxIpduFRDCM_1DefaultValue._c,
    RxIpduRLDCM_1DefaultValue._c,
    
#else
#error "the define E0X_DCM is error!"
#endif 

    RxIpduVCC_1DefaultValue._c,
    RxIpduVCC_2DefaultValue._c,
    RxIpduRLCR_1DefaultValue._c,
    RxIpduRLCR_2DefaultValue._c,
    RxIpduICC_BD_11DefaultValue._c,
    RxIpduONEBOX_1_GDefaultValue._c,
    RxIpduRZCU_1DefaultValue._c,
    RxIpduBNCM_15DefaultValue._c,
    RxIpduTMS_1DefaultValue._c,
    RxIpduACU_1DefaultValue._c,
    RxIpduFLZCU_9DefaultValue._c,
    RxIpduBNCM_6DefaultValue._c,
    RxIpduVCU_1_GDefaultValue._c,

    RxIpduVCU_2_GDefaultValue._c,
    RxIpduASU_1DefaultValue._c,
    RxIpduICC_COM_1DefaultValue._c,
    RxIpduRRCR_1DefaultValue._c,
    RxIpduPEPS_3DefaultValue._c,
    RxIpduICC_COM_16DefaultValue._c,
    RxIpduICC_COM_8DefaultValue._c
   
};

CONST(PduLengthType, COM_CONFIG_CONST) Com_RxIpduBufferSize[COM_RXIPDUNUM]=
{
    COM_RXIPDUACU_3_BUFFER_SIZE,
    COM_RXIPDUACU_2_BUFFER_SIZE,

    COM_RXIPDUFLZCU_1_BUFFER_SIZE,
    COM_RXIPDUFRZCU_2_BUFFER_SIZE,
    COM_RXIPDUBNCM_14_BUFFER_SIZE,
    COM_RXIPDUFRZCU_1_BUFFER_SIZE,
    COM_RXIPDURZCU_2_BUFFER_SIZE,
    
#if  E0X_DCM == E0X_DCM_FL
    COM_RXIPDURCM_1_BUFFER_SIZE,
    COM_RXIPDURCM_3_BUFFER_SIZE, 
    COM_RXIPDUFLDRM_1_BUFFER_SIZE,
#elif  E0X_DCM == E0X_DCM_FR
    COM_RXIPDURCM_2_BUFFER_SIZE,
    COM_RXIPDURCM_4_BUFFER_SIZE,
    COM_RXIPDUFRDRM_1_BUFFER_SIZE,
#elif  E0X_DCM == E0X_DCM_RL
    COM_RXIPDURCM_1_BUFFER_SIZE,
    COM_RXIPDURCM_3_BUFFER_SIZE,
    COM_RXIPDURLDRM_1_BUFFER_SIZE,
#elif  E0X_DCM == E0X_DCM_RR
    COM_RXIPDURCM_2_BUFFER_SIZE,
    COM_RXIPDURCM_4_BUFFER_SIZE,
    COM_RXIPDURRDRM_1_BUFFER_SIZE,
#else
#error "the define E0X_DCM is error!"
#endif

    COM_RXIPDUASU_2_BUFFER_SIZE,
    COM_RXIPDUVCC_4_BUFFER_SIZE,
    COM_RXIPDUVCC_5_BUFFER_SIZE,
    COM_RXIPDUVCC_6_BUFFER_SIZE,
    COM_RXIPDUBNCM_1_BUFFER_SIZE,
    COM_RXIPDUFLZCU_5_BUFFER_SIZE,
    
#if  E0X_DCM == E0X_DCM_FL 
    COM_RXIPDUFRDCM_1_BUFFER_SIZE,
    COM_RXIPDURLDCM_1_BUFFER_SIZE,
    COM_RXIPDURRDCM_1_BUFFER_SIZE,
    
#elif  E0X_DCM == E0X_DCM_FR 
    COM_RXIPDUFLDCM_1_BUFFER_SIZE,
    COM_RXIPDURLDCM_1_BUFFER_SIZE,
    COM_RXIPDURRDCM_1_BUFFER_SIZE,
    
#elif  E0X_DCM == E0X_DCM_RL 
    COM_RXIPDUFLDCM_1_BUFFER_SIZE,
    COM_RXIPDUFRDCM_1_BUFFER_SIZE,
    COM_RXIPDURRDCM_1_BUFFER_SIZE,
    
#elif  E0X_DCM == E0X_DCM_RR 
    COM_RXIPDUFLDCM_1_BUFFER_SIZE,
    COM_RXIPDUFRDCM_1_BUFFER_SIZE,
    COM_RXIPDURLDCM_1_BUFFER_SIZE,
    
#else
#error "the define E0X_DCM is error!"
#endif   

    COM_RXIPDUVCC_1_BUFFER_SIZE,
    COM_RXIPDUVCC_2_BUFFER_SIZE,
    COM_RXIPDURLCR_1_BUFFER_SIZE,
    COM_RXIPDURLCR_2_BUFFER_SIZE,
    COM_RXIPDUICC_BD_11_BUFFER_SIZE,
    COM_RXIPDUONEBOX_1_G_BUFFER_SIZE,
    COM_RXIPDURZCU_1_BUFFER_SIZE,
    COM_RXIPDUBNCM_15_BUFFER_SIZE,
    COM_RXIPDUTMS_1_BUFFER_SIZE,
    COM_RXIPDUACU_1_BUFFER_SIZE,
    COM_RXIPDUFLZCU_9_BUFFER_SIZE,
    COM_RXIPDUBNCM_6_BUFFER_SIZE,
    COM_RXIPDUVCU_1_G_BUFFER_SIZE,

    COM_RXIPDUVCU_2_G_BUFFER_SIZE,
    COM_RXIPDUASU_1_BUFFER_SIZE,
    COM_RXIPDUICC_COM_1_BUFFER_SIZE,
    COM_RXIPDURRCR_1_BUFFER_SIZE,
    COM_RXIPDUPEPS_3_BUFFER_SIZE,
    COM_RXIPDUICC_COM_16_BUFFER_SIZE,
    COM_RXIPDUICC_COM_8_BUFFER_SIZE
};

CONST(uint8, COM_CONFIG_CONST) Com_RxIpduSigNum[COM_RXIPDUNUM] = 
{
    3,
    2,

    8,
    3,
    1,
    8,
    8,
    
#if  E0X_DCM == E0X_DCM_FL
    7,
    6, 
    8,
#elif  E0X_DCM == E0X_DCM_FR
    7,
    6,
    8,
#elif  E0X_DCM == E0X_DCM_RL
    7,
    6,
    8,
#elif  E0X_DCM == E0X_DCM_RR
    7,
    6,
    8,
#else
#error "the define E0X_DCM is error!"
#endif
    4,
    1,
    1,
    1,
    1,
    1,
    
#if  E0X_DCM == E0X_DCM_FL 
    1,
    1,
    1,
    
#elif  E0X_DCM == E0X_DCM_FR 
    1,
    1,
    1,
    
#elif  E0X_DCM == E0X_DCM_RL 
    1,
    1,
    1,
    
#elif  E0X_DCM == E0X_DCM_RR 
    1,
    1,
    1,
    
#else
#error "the define E0X_DCM is error!"
#endif 
      
    1,
    1,
    4,
    1,
    17,
    2,
    1,
    1,
    2,
    1,
    2,
    1,
    2,

    3,
    5,
    1,
    1,
    1,
    1,
    6
};

CONST(Com_SignalIdType, COM_CONFIG_CONST) Com_RxSigOffsetTable[COM_RXIPDUNUM] = 
{
    0,
    3,

    5,
    13,
    16,
    17,
    25,
    
#if  E0X_DCM == E0X_DCM_FL
    33,
    40, 
    46,
#elif  E0X_DCM == E0X_DCM_FR
    33,
    40, 
    46,
#elif  E0X_DCM == E0X_DCM_RL
    33,
    40, 
    46,
#elif  E0X_DCM == E0X_DCM_RR
    33,
    40, 
    46,
#else
#error "the define E0X_DCM is error!"
#endif
    52,
    56,
    57,
    58,
    59,
    60,
    
#if  E0X_DCM == E0X_DCM_FL 
    61,
    62,
    63,   
    
#elif  E0X_DCM == E0X_DCM_FR 
    61,
    62,
    63,
    
#elif  E0X_DCM == E0X_DCM_RL 
    61,
    62,
    63,
    
#elif  E0X_DCM == E0X_DCM_RR 
    61,
    62,
    63,
#else
#error "the define E0X_DCM is error!"
#endif 

    
    64,
    65,
    66,
    70,
    71,
    88,
    90,
    91,
    92,
    94,
    95,
    97,
    98,

    100,
    103,
    108,
    109,
    110,
    111
 
    
};

CONST(Com_RxSigTableType, COM_CONFIG_CONST) Com_RxSigTable[COM_RXSIGNUM] = 
{
    {0U, 0U},
    {0U, 0U},
    {0U, 0U},
    {1U, 0U},
    {1U, 0U},

    {2U, 0U},
    {2U, 0U},
    {2U, 0U},
    {2U, 0U},
    {2U, 0U},
    {2U, 0U},
    {2U, 0U},
    {2U, 0U},
    {3U, 0U},
    {3U, 0U},
    {3U, 0U},
    {4U, 0U},
    {5U, 0U},
    {5U, 0U},
    {5U, 0U},
    {5U, 0U},
    {5U, 0U},
    {5U, 0U},
    {5U, 0U},
    {5U, 0U},
    {6U, 0U},
    {6U, 0U},
    {6U, 0U},
    {6U, 0U},
    {6U, 0U},
    {6U, 0U},
    {6U, 0U},
    {6U, 0U},
   
#if  E0X_DCM == E0X_DCM_FL
    {7U, 0U},
    {7U, 0U},
    {7U, 0U},
    {7U, 0U},
    {7U, 0U},
    {7U, 0U},
    {7U, 0U},
    {8U, 0U},
    {8U, 0U},
    {8U, 0U},
    {8U, 0U},
    {8U, 0U},
    {8U, 0U},
    {9U, 0U},
    {9U, 0U},
    {9U, 0U},
    {9U, 0U},
    {9U, 0U},
    {9U, 0U},
    {9U, 0U},
    {9U, 0U},
#elif  E0X_DCM == E0X_DCM_FR
    {7U, 0U},
    {7U, 0U},
    {7U, 0U},
    {7U, 0U},
    {7U, 0U},
    {7U, 0U},
    {7U, 0U},
    {8U, 0U},
    {8U, 0U},
    {8U, 0U},
    {8U, 0U},
    {8U, 0U},
    {8U, 0U},
    {9U, 0U},
    {9U, 0U},
    {9U, 0U},
    {9U, 0U},
    {9U, 0U},
    {9U, 0U},
    {9U, 0U},
    {9U, 0U},
#elif  E0X_DCM == E0X_DCM_RL
    {7U, 0U},
    {7U, 0U},
    {7U, 0U},
    {7U, 0U},
    {7U, 0U},
    {7U, 0U},
    {7U, 0U},
    {8U, 0U},
    {8U, 0U},
    {8U, 0U},
    {8U, 0U},
    {8U, 0U},
    {8U, 0U},
    {9U, 0U},
    {9U, 0U},
    {9U, 0U},
    {9U, 0U},
    {9U, 0U},
    {9U, 0U},
    {9U, 0U},
    {9U, 0U},
#elif  E0X_DCM == E0X_DCM_RR
    {7U, 0U},
    {7U, 0U},
    {7U, 0U},
    {7U, 0U},
    {7U, 0U},
    {7U, 0U},
    {7U, 0U},
    {8U, 0U},
    {8U, 0U},
    {8U, 0U},
    {8U, 0U},
    {8U, 0U},
    {8U, 0U},
    {9U, 0U},
    {9U, 0U},
    {9U, 0U},
    {9U, 0U},
    {9U, 0U},
    {9U, 0U},
    {9U, 0U},
    {9U, 0U},
#else
#error "the define E0X_DCM is error!"
#endif

    {10U, 0U},
    {10U, 0U},
    {10U, 0U},
    {10U, 0U},
    {11U, 0U},
    {12U, 0U},
    {13U, 0U},
    {14U, 0U},
    {15U, 0U},
    
#if  E0X_DCM == E0X_DCM_FL 
    {16U, 0U},
    {17U, 0U},
    {18U, 0U},
    
#elif  E0X_DCM == E0X_DCM_FR 
    {16U, 0U},
    {17U, 0U},
    {18U, 0U},
    
#elif  E0X_DCM == E0X_DCM_RL 
    {16U, 0U},
    {17U, 0U},
    {18U, 0U},

#elif  E0X_DCM == E0X_DCM_RR 
    {16U, 0U},
    {17U, 0U},
    {18U, 0U},

#else
#error "the define E0X_DCM is error!"
#endif 

    {19U, 0U},
    {20U, 0U},
    {21U, 0U},
    {21U, 0U},
    {21U, 0U},
    {21U, 0U},
    {22U, 0U},
    {23U, 0U},
    {23U, 0U},
    {23U, 0U},
    {23U, 0U},
    {23U, 0U},
    {23U, 0U},
    {23U, 0U},
    {23U, 0U},
    {23U, 0U},
    {23U, 0U},
    {23U, 0U},
    {23U, 0U},
    {23U, 0U},
    {23U, 0U},
    {23U, 0U},
    {23U, 0U},
    {23U, 0U},
    {24U, 0U},
    {24U, 0U},
    {25U, 0U},
    {26U, 0U},
    {27U, 0U},
    {27U, 0U},
    {28U, 0U},
    {29U, 0U},
    {29U, 0U},
    {30U, 0U},

    {30U, 0U},
    {30U, 0U},
    {31U, 0U},
    {31U, 0U},
    {31U, 0U},
    {32U, 0U},
    {32U, 0U},
    {32U, 0U},
    {32U, 0U},
    {32U, 0U},
    {33U, 0U},
    {34U, 0U},
    {35U, 0U},
    {36U, 0U},
    {37U, 0U},
    {37U, 0U},
    {37U, 0U},
    {37U, 0U},
    {37U, 0U},
    {37U, 0U}   
};

CONST(Com_RxIpduTableType, COM_CONFIG_CONST) Com_RxIpduTable[COM_RXIPDUNUM] = 
{
    {COM_RXTIMEOUTMONITOR_YES, 10U},
    {COM_RXTIMEOUTMONITOR_YES, 10U},

    {COM_RXTIMEOUTMONITOR_YES, 20U},
    {COM_RXTIMEOUTMONITOR_YES, 20U},
    {COM_RXTIMEOUTMONITOR_YES, 20U},
    {COM_RXTIMEOUTMONITOR_YES, 20U},
    {COM_RXTIMEOUTMONITOR_YES, 20U},
    
#if  E0X_DCM == E0X_DCM_FL
    {COM_RXTIMEOUTMONITOR_YES, 20U},
    {COM_RXTIMEOUTMONITOR_YES, 20U},
    {COM_RXTIMEOUTMONITOR_YES, 20U},
#elif  E0X_DCM == E0X_DCM_FR
    {COM_RXTIMEOUTMONITOR_YES, 20U},
    {COM_RXTIMEOUTMONITOR_YES, 20U},
    {COM_RXTIMEOUTMONITOR_YES, 20U},
#elif  E0X_DCM == E0X_DCM_RL
    {COM_RXTIMEOUTMONITOR_YES, 20U},
    {COM_RXTIMEOUTMONITOR_YES, 20U},
    {COM_RXTIMEOUTMONITOR_YES, 20U},
#elif  E0X_DCM == E0X_DCM_RR
    {COM_RXTIMEOUTMONITOR_YES, 20U},
    {COM_RXTIMEOUTMONITOR_YES, 20U},
    {COM_RXTIMEOUTMONITOR_YES, 20U},
#else
#error "the define E0X_DCM is error!"
#endif

    {COM_RXTIMEOUTMONITOR_YES, 50U},
    {COM_RXTIMEOUTMONITOR_NO, 100U},
    {COM_RXTIMEOUTMONITOR_NO, 100U},
    {COM_RXTIMEOUTMONITOR_NO, 100U},
    {COM_RXTIMEOUTMONITOR_YES, 50U},
    {COM_RXTIMEOUTMONITOR_YES, 50U},
    
#if  E0X_DCM == E0X_DCM_FL 
    {COM_RXTIMEOUTMONITOR_YES, 50U},
    {COM_RXTIMEOUTMONITOR_YES, 50U},
    {COM_RXTIMEOUTMONITOR_YES, 50U},
    
#elif  E0X_DCM == E0X_DCM_FR 
    {COM_RXTIMEOUTMONITOR_YES, 50U},
    {COM_RXTIMEOUTMONITOR_YES, 50U},
    {COM_RXTIMEOUTMONITOR_YES, 50U},

#elif  E0X_DCM == E0X_DCM_RL 
    {COM_RXTIMEOUTMONITOR_YES, 50U},
    {COM_RXTIMEOUTMONITOR_YES, 50U},
    {COM_RXTIMEOUTMONITOR_YES, 50U},
 
#elif  E0X_DCM == E0X_DCM_RR 
    {COM_RXTIMEOUTMONITOR_YES, 50U},
    {COM_RXTIMEOUTMONITOR_YES, 50U},
    {COM_RXTIMEOUTMONITOR_YES, 50U},

#else
#error "the define E0X_DCM is error!"
#endif 
        
    {COM_RXTIMEOUTMONITOR_YES, 100U},
    {COM_RXTIMEOUTMONITOR_NO, 100U},
    {COM_RXTIMEOUTMONITOR_YES, 100U},
    {COM_RXTIMEOUTMONITOR_YES, 100U},
    {COM_RXTIMEOUTMONITOR_YES, 100U},
    {COM_RXTIMEOUTMONITOR_YES, 100U},
    {COM_RXTIMEOUTMONITOR_YES, 100U},
    {COM_RXTIMEOUTMONITOR_YES, 100U},
    {COM_RXTIMEOUTMONITOR_YES, 100U},
    {COM_RXTIMEOUTMONITOR_YES, 100U},
    {COM_RXTIMEOUTMONITOR_YES, 100U},
    {COM_RXTIMEOUTMONITOR_NO, 100U},
    {COM_RXTIMEOUTMONITOR_YES, 100U},

    {COM_RXTIMEOUTMONITOR_YES, 100U},
    {COM_RXTIMEOUTMONITOR_YES, 100U},
    {COM_RXTIMEOUTMONITOR_YES, 100U},
    {COM_RXTIMEOUTMONITOR_YES, 100U},
    {COM_RXTIMEOUTMONITOR_YES, 100U},
    {COM_RXTIMEOUTMONITOR_YES, 100U},
    {COM_RXTIMEOUTMONITOR_YES, 500U}
};

#ifdef COM_ENABLE_RXINDICATIONFUN
CONST(Com_RxIndicationType, COM_CONFIG_CONST) Com_RxIpduIndicationTable[COM_RXIPDUNUM] = 
{
    &AppIpduACU_3_Ind,
    &AppIpduACU_2_Ind,

    &AppIpduFLZCU_1_Ind,
    &AppIpduFRZCU_2_Ind,
    &AppIpduBNCM_14_Ind,
    &AppIpduFRZCU_1_Ind,
    &AppIpduRZCU_2_Ind,

#if  E0X_DCM == E0X_DCM_FL
    &AppIpduRCM_1_Ind,
    &AppIpduRCM_3_Ind,
    &AppIpduFLDRM_1_Ind,
#elif  E0X_DCM == E0X_DCM_FR
    &AppIpduRCM_2_Ind,
    &AppIpduRCM_4_Ind,
    &AppIpduFRDRM_1_Ind,
#elif  E0X_DCM == E0X_DCM_RL
    &AppIpduRCM_1_Ind,
    &AppIpduRCM_3_Ind,
    &AppIpduRLDRM_1_Ind,
#elif  E0X_DCM == E0X_DCM_RR
    &AppIpduRCM_2_Ind,
    &AppIpduRCM_4_Ind,
    &AppIpduRRDRM_1_Ind,
#else
#error "the define E0X_DCM is error!"
#endif

    &AppIpduASU_2_Ind,
    &AppIpduVCC_4_Ind,
    &AppIpduVCC_5_Ind,
    &AppIpduVCC_6_Ind,
    &AppIpduBNCM_1_Ind,
    &AppIpduFLZCU_5_Ind,
    
#if  E0X_DCM == E0X_DCM_FL 
    &AppIpduFRDCM_1_Ind,
    &AppIpduRLDCM_1_Ind,
    &AppIpduRRDCM_1_Ind,
    
#elif  E0X_DCM == E0X_DCM_FR 
    &AppIpduFLDCM_1_Ind,
    &AppIpduRLDCM_1_Ind,
    &AppIpduRRDCM_1_Ind,
    
#elif  E0X_DCM == E0X_DCM_RL 
    &AppIpduFLDCM_1_Ind,
    &AppIpduFRDCM_1_Ind,
    &AppIpduRRDCM_1_Ind,
    
#elif  E0X_DCM == E0X_DCM_RR 
    &AppIpduFLDCM_1_Ind,
    &AppIpduFRDCM_1_Ind,
    &AppIpduRLDCM_1_Ind,
 
#else
#error "the define E0X_DCM is error!"
#endif  

    &AppIpduVCC_1_Ind,
    &AppIpduVCC_2_Ind,
    &AppIpduRLCR_1_Ind,
    &AppIpduRLCR_2_Ind,
    &AppIpduICC_BD_11_Ind,
    &AppIpduONEBOX_1_G_Ind,
    &AppIpduRZCU_1_Ind,
    &AppIpduBNCM_15_Ind,
    &AppIpduTMS_1_Ind,
    &AppIpduACU_1_Ind,
    &AppIpduFLZCU_9_Ind,
    &AppIpduBNCM_6_Ind,
    &AppIpduVCU_1_G_Ind,

    &AppIpduVCU_2_G_Ind,
    &AppIpduASU_1_Ind,
    &AppIpduICC_COM_1_Ind,
    &AppIpduRRCR_1_Ind,
    &AppIpduPEPS_3_Ind,
    &AppIpduICC_COM_16_Ind,
    &AppIpduICC_COM_8_Ind
   
};
#endif

#ifdef COM_ENABLE_RXTOINDFUN
CONST(Com_TOIndicationType, COM_CONFIG_CONST) Com_RxIpduTOIndicationTable[COM_RXIPDUNUM] = 
{
 
    &AppIpduACU_3_TimeOutInd,
    &AppIpduACU_2_TimeOutInd,

    &AppIpduFLZCU_1_TimeOutInd,
    &AppIpduFRZCU_2_TimeOutInd,
    &AppIpduBNCM_14_TimeOutInd,
    &AppIpduFRZCU_1_TimeOutInd,
    &AppIpduRZCU_2_TimeOutInd,

#if  E0X_DCM == E0X_DCM_FL
    &AppIpduRCM_1_TimeOutInd,
    &AppIpduRCM_3_TimeOutInd,
    &AppIpduFLDRM_1_TimeOutInd,
#elif  E0X_DCM == E0X_DCM_FR
    &AppIpduRCM_2_TimeOutInd,
    &AppIpduRCM_4_TimeOutInd,
    &AppIpduFRDRM_1_TimeOutInd,
#elif  E0X_DCM == E0X_DCM_RL
    &AppIpduRCM_1_TimeOutInd,
    &AppIpduRCM_3_TimeOutInd,
    &AppIpduRLDRM_1_TimeOutInd,
#elif  E0X_DCM == E0X_DCM_RR
    &AppIpduRCM_2_TimeOutInd,
    &AppIpduRCM_4_TimeOutInd,
    &AppIpduRRDRM_1_TimeOutInd,
#else
#error "the define E0X_DCM is error!"
#endif

    &AppIpduASU_2_TimeOutInd,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    &AppIpduBNCM_1_TimeOutInd,
    &AppIpduFLZCU_5_TimeOutInd,
    
#if  E0X_DCM == E0X_DCM_FL 
    &AppIpduFRDCM_1_TimeOutInd,
    &AppIpduRLDCM_1_TimeOutInd,
    &AppIpduRRDCM_1_TimeOutInd,

#elif  E0X_DCM == E0X_DCM_FR 
    &AppIpduFLDCM_1_TimeOutInd,
    &AppIpduRLDCM_1_TimeOutInd,
    &AppIpduRRDCM_1_TimeOutInd,

#elif  E0X_DCM == E0X_DCM_RL 
    &AppIpduFLDCM_1_TimeOutInd,
    &AppIpduFRDCM_1_TimeOutInd,
    &AppIpduRRDCM_1_TimeOutInd,
    
#elif  E0X_DCM == E0X_DCM_RR 
    &AppIpduFLDCM_1_TimeOutInd,
    &AppIpduFRDCM_1_TimeOutInd,
    &AppIpduRLDCM_1_TimeOutInd,
 
#else
#error "the define E0X_DCM is error!"
#endif 
    
    &AppIpduVCC_1_TimeOutInd,
    NULL_PTR,
    &AppIpduRLCR_1_TimeOutInd,
    &AppIpduRLCR_2_TimeOutInd,
    &AppIpduICC_BD_11_TimeOutInd,
    &AppIpduONEBOX_1_G_TimeOutInd,
    &AppIpduRZCU_1_TimeOutInd,
    &AppIpduBNCM_15_TimeOutInd,
    &AppIpduTMS_1_TimeOutInd,
    &AppIpduACU_1_TimeOutInd,
    &AppIpduFLZCU_9_TimeOutInd,
    &AppIpduBNCM_6_TimeOutInd,
    &AppIpduVCU_1_G_TimeOutInd,

    &AppIpduVCU_2_G_TimeOutInd,
    &AppIpduASU_1_TimeOutInd,
    &AppIpduICC_COM_1_TimeOutInd,
    &AppIpduRRCR_1_TimeOutInd,
    &AppIpduPEPS_3_TimeOutInd,
    &AppIpduICC_COM_16_TimeOutInd,
    &AppIpduICC_COM_8_TimeOutInd  
};
#endif
#define COM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
//#include "MemMap.h"

#endif /*#if(COM_RXIPDUNUM>=1)*/

#ifdef COM_ENABLE_ROUTESIGNAL

#define COM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

#if((COM_TXIPDUNUM>=1) && (COM_RXIPDUNUM>=1) && (COM_GWIPDUNUM>=1) && (COM_GWSIGNUM>=1))
CONST(Com_SignalGatewayTableType, COM_CONFIG_CONST) Com_SignalGatewayTable[COM_GWSIGNUM]=
{
};

CONST(Com_SignalGatewayIpduTableType, COM_CONFIG_CONST) Com_SignalGatewayIpduTable[COM_GWIPDUNUM]=
{
};
#endif/*#if((COM_TXIPDUNUM>=1) && (COM_RXIPDUNUM>=1) && (COM_GWIPDUNUM>=1) && (COM_GWSIGNUM>=1))*/

#define COM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

#endif/*#ifdef COM_ENABLE_ROUTESIGNAL*/

#if(COM_GROUPIPDUNUM >= 1)
#define COM_START_SEC_CONFIG_DATA_UNSPECIFIED
//#include "MemMap.h"

CONST(Com_GroupIpduTableType, COM_CONFIG_CONST) Com_GroupIpduTable[COM_GROUPIPDUNUM]=
{
    {0U, COM_DIRECTION_TX},
    {1U, COM_DIRECTION_TX},
    {2U, COM_DIRECTION_TX},
    {0U, COM_DIRECTION_RX},
    {1U, COM_DIRECTION_RX},
    {2U, COM_DIRECTION_RX},
    {3U, COM_DIRECTION_RX},
    {4U, COM_DIRECTION_RX},
    {5U, COM_DIRECTION_RX},
    {6U, COM_DIRECTION_RX},
    {7U, COM_DIRECTION_RX},
    {8U, COM_DIRECTION_RX},
    {9U, COM_DIRECTION_RX},
    {10U, COM_DIRECTION_RX},
    {11U, COM_DIRECTION_RX},
    {12U, COM_DIRECTION_RX},
    {13U, COM_DIRECTION_RX},
    {14U, COM_DIRECTION_RX},
    {15U, COM_DIRECTION_RX},
    {16U, COM_DIRECTION_RX},
    {17U, COM_DIRECTION_RX},
    {18U, COM_DIRECTION_RX},
    {19U, COM_DIRECTION_RX},
    {20U, COM_DIRECTION_RX},
    {21U, COM_DIRECTION_RX},
    {22U, COM_DIRECTION_RX},
    {23U, COM_DIRECTION_RX},
    {24U, COM_DIRECTION_RX},
    {25U, COM_DIRECTION_RX},
    {26U, COM_DIRECTION_RX},
    {27U, COM_DIRECTION_RX},
    {28U, COM_DIRECTION_RX},
    {29U, COM_DIRECTION_RX},
    {30U, COM_DIRECTION_RX},
    {31U, COM_DIRECTION_RX},
    {32U, COM_DIRECTION_RX},
    {33U, COM_DIRECTION_RX},
    {34U, COM_DIRECTION_RX},
    {35U, COM_DIRECTION_RX},
    {36U, COM_DIRECTION_RX},
    {37U, COM_DIRECTION_RX},
    {38U, COM_DIRECTION_RX}
};

CONST(Com_IpduGroupTableType, COM_CONFIG_CONST) Com_IpduGroupTable[COM_IPDUGROUPNUM]=
{
    {0, 3},
    {1, 39},
};

#define COM_STOP_SEC_CONFIG_DATA_UNSPECIFIED  
//#include "MemMap.h"

#endif
