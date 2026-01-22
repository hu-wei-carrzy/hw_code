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

#ifndef _COM_CFG_H_
#define _COM_CFG_H_

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "Com_Types.h"
/*adding underlying layer's head files here if necessary*/ 
#include "../CanIf/CanIf.h"
//#include "can_schedule.h"
/*******************************************************************************
*   Macro define
*******************************************************************************/
#define COM_VERSION_INFO_API                         STD_OFF
#define COM_ENABLE_ACTIVEPORPERTY
#define COM_ENABLE_TXCONFIRMATIONFUN
#define COM_ENABLE_TXTOINDFUN
#define COM_ENABLE_RXINDICATIONFUN
#define COM_ENABLE_RXTOINDFUN
#define COM_TXMAIN_FUNCTION_PERIOD                   (10U)
#define COM_RXMAIN_FUNCTION_PERIOD                   (10U)
#define COM_SIGNALROUTINEMAIN_FUNCTION_PERIOD        (10U)

/******************************************************************************
*    number of Tx object                                                       
******************************************************************************/
#define COM_TXIPDUNUM    (4U)

#define COM_TXIPDUDCM_2                             (0U)
#define COM_TXIPDUDCM_1                             (1U)
#define COM_TXIPDUDCM_3                             (2U)
#define COM_TXIPDUDCM_RemoteDiag                    (3U)
/******************************************************************************
*    number of Tx object Signal                                                
******************************************************************************/
#define COM_TXSIGNUM    (41U)
/******************************************************************************
*    Handles of receive messages                                                  
******************************************************************************/

/******************************************************************************
*    Send Signal structures                                                    
******************************************************************************/
typedef struct {
    uint8 DCM_1_CRC1 : 8;
    uint8 DCM_1_RollgCntr1 : 4;
    uint8 DCM_1_Resd1 : 4;
    uint8 LearnedStatus : 1;
    uint8 CurrentOpenPosition : 7;
    uint8 SetOpenAngleFb : 7;
    uint8 Reserved_Byte0 : 1;
    uint8 SystemMotionStatus : 3;
    uint8 LatchMotionStatus : 3;
    uint8 Reserved_Byte1 : 1;
    uint8 ResetSwitch : 1;    
    uint8 DoorCloseStatus : 2;
    uint8 Reserved_Byte2 : 1;
    uint8 MotorFaultStatus : 4;  
    uint8 AntipinchEvent : 1;
    uint8 PSDModeControlFb : 2;
    uint8 Reminder : 2;
    uint8 RadarDetectRequirement : 1;
    uint8 ADASDetectRequirement : 1;
    uint8 Reserved_Byte4 : 2;
    uint8 Reserved_Byte5 : 1;
    uint8 ClutchStatus : 1;
    uint8 Inhibition : 4;
    uint8 ReleaseLatch : 1;
    uint8 Warning : 1;
}IpduDCM_1_Type;

typedef struct {
    uint8 DCM_TotalFaultNum : 8;
    uint8 DCM_FrameIndex : 5;
    uint8 DCM_SupplierNum : 3;
    uint8 DCM_FaultNum1_Hi : 8;
    uint8 DCM_FaultNum2_Hi : 4;
    uint8 DCM_FaultNum1_Lo : 4;
    uint8 DCM_FaultNum2_Lo : 8;
    uint8 DCM_FaultNum3_Hi : 8;
    uint8 DCM_FaultNum4_Hi : 4;
    uint8 DCM_FaultNum3_Lo : 4;
    uint8 DCM_FaultNum4_Lo : 8;
}IpduDCM_RemoteDiag_Type;

typedef struct {
    uint8 DCM_2_CRC1 : 8;
    uint8 DCM_2_RollgCntr1 : 4;
    uint8 DCM_2_Resd1 : 4;
    uint8 DCM_2_DRMDetectRequirement : 3;
    uint8 DCM_2_RCMDetectRequirement : 1;
    uint8 DCM_2_SystemMotionStatus : 4;
    uint8 DCM_2_CurrentOpenPosition : 8;
    uint8 DCM_2_SetOpenAngleFb : 8;
    uint8 DCM_2_DCMAngularSpeed : 8;
    uint8 DoorCurrentoperation : 2;
    uint8 DoorFunctionInhibit : 1;
    uint8 Reserved_Byte1 : 5;
    uint8 Reserved_Byte2 : 8;
}IpduDCM_2_Type;

typedef struct {
    uint8 DCM_3_CRC1 : 8;
    uint8 DCM_3_RollgCntr1 : 4;
    uint8 DCM_3_Resd1 : 4;
#if  E0X_DCM == E0X_DCM_FL
    uint8 FLDCM_3_BLEOpenDriverDoorFB : 1;
    uint8 FLDCM_3_PedalCloseDriverDoorFB : 1;
    uint8 FLDCM_3_DoorRemoteKeyControlFB : 1;
    uint8 FLDCM_3_FL_ParkDoorControlNotic : 1;
    uint8 FLDoorMotionDirection : 2;
#elif  E0X_DCM == E0X_DCM_FR
    uint8 Reserved_Bit0 : 1;
    uint8 FRDCM_3_PedalCloseDriverDoorFB : 1;
    uint8 FRDCM_3_DoorRemoteKeyControlFB : 1;
    uint8 FRDCM_3_FR_ParkDoorControlNotic : 1;
    uint8 FRDoorMotionDirection : 2;
#elif  E0X_DCM == E0X_DCM_RL
    uint8 Reserved_Bit0 : 1;
    uint8 Reserved_Bit1 : 1;
    //uint8 Reserved_Bit2 : 1;
    uint8 RLDCM_3_DoorRemoteKeyControlFB : 1;
    uint8 RLDCM_3_RL_ParkDoorControlNotic : 1;
    uint8 RLDoorMotionDirection : 2;
#elif  E0X_DCM == E0X_DCM_RR
    uint8 Reserved_Bit0 : 1;
    uint8 Reserved_Bit1 : 1;
    //uint8 Reserved_Bit2 : 1;
    uint8 RRDCM_3_DoorRemoteKeyControlFB : 1;
    uint8 RRDCM_3_RR_ParkDoorControlNotic : 1;
    uint8 RRDoorMotionDirection : 2;
#else
#error "the define E0X_DCM is error!"
#endif
    uint8 Reserved_Byte1 : 2;
    uint8 AccX_Hi : 8;
    uint8 AccY_Hi : 4;
    uint8 AccX_Lo : 4;
    uint8 AccY_Lo : 8;
    uint8 AccZ_Hi : 8;
    uint8 Reserved_Byte6 : 4;
    uint8 AccZ_Lo : 4;
    
}IpduDCM_3_Type;
/******************************************************************************
*    Send Message unions                                                       
******************************************************************************/
typedef union {
    IpduDCM_1_Type  Ipdu;
    uint8  _c[8];
}IpduDCM_1_bufType;

typedef union {
    IpduDCM_2_Type  Ipdu;
    uint8  _c[8];
}IpduDCM_2_bufType;

typedef union {
    IpduDCM_RemoteDiag_Type  Ipdu;
    uint8  _c[8];
}IpduDCM_RemoteDiag_bufType;

typedef union {
    IpduDCM_3_Type  Ipdu;
    uint8  _c[8];
}IpduDCM_3_bufType;
/******************************************************************************
*    Databuffer for sended objects                                             
******************************************************************************/
#define COM_START_SEC_VAR_UNSPECIFIED  
//#include "MemMap.h"
#if  E0X_DCM == E0X_DCM_FL
extern VAR(IpduDCM_1_bufType, COM_PRIVATE_DATA) TxIpduFLDCM_1;
extern VAR(IpduDCM_2_bufType, COM_PRIVATE_DATA) TxIpduFLDCM_2;
extern VAR(IpduDCM_3_bufType, COM_PRIVATE_DATA) TxIpduFLDCM_3;
extern VAR(IpduDCM_RemoteDiag_bufType, COM_PRIVATE_DATA) TxIpduFLDCM_RemoteDiag;
#elif  E0X_DCM == E0X_DCM_FR
extern VAR(IpduDCM_1_bufType, COM_PRIVATE_DATA) TxIpduFRDCM_1;
extern VAR(IpduDCM_2_bufType, COM_PRIVATE_DATA) TxIpduFRDCM_2;
extern VAR(IpduDCM_3_bufType, COM_PRIVATE_DATA) TxIpduFRDCM_3;
extern VAR(IpduDCM_RemoteDiag_bufType, COM_PRIVATE_DATA) TxIpduFRDCM_RemoteDiag;
#elif  E0X_DCM == E0X_DCM_RL
extern VAR(IpduDCM_1_bufType, COM_PRIVATE_DATA) TxIpduRLDCM_1;
extern VAR(IpduDCM_2_bufType, COM_PRIVATE_DATA) TxIpduRLDCM_2;
extern VAR(IpduDCM_3_bufType, COM_PRIVATE_DATA) TxIpduRLDCM_3;
extern VAR(IpduDCM_RemoteDiag_bufType, COM_PRIVATE_DATA) TxIpduRLDCM_RemoteDiag;
#elif  E0X_DCM == E0X_DCM_RR
extern VAR(IpduDCM_1_bufType, COM_PRIVATE_DATA) TxIpduRRDCM_1;
extern VAR(IpduDCM_2_bufType, COM_PRIVATE_DATA) TxIpduRRDCM_2;
extern VAR(IpduDCM_3_bufType, COM_PRIVATE_DATA) TxIpduRRDCM_3;
extern VAR(IpduDCM_RemoteDiag_bufType, COM_PRIVATE_DATA) TxIpduRRDCM_RemoteDiag;
#else
#error "the define E0X_DCM is error!"
#endif
#define COM_STOP_SEC_VAR_UNSPECIFIED  
//#include "MemMap.h"

/******************************************************************************
*    Databuffer for Sended Message default Value                               
******************************************************************************/
#define COM_START_SEC_CONFIG_DATA_UNSPECIFIED  
//#include "MemMap.h"
extern CONST(IpduDCM_1_bufType, COM_CONFIG_CONST)  TxIpduDCM_1DefaultValue;
extern CONST(IpduDCM_2_bufType, COM_CONFIG_CONST)  TxIpduDCM_2DefaultValue;
extern CONST(IpduDCM_3_bufType, COM_CONFIG_CONST)  TxIpduDCM_3DefaultValue;
extern CONST(IpduDCM_RemoteDiag_bufType, COM_CONFIG_CONST)  TxIpduDCM_RemoteDiagDefaultValue;
#define COM_STOP_SEC_CONFIG_DATA_UNSPECIFIED  
//#include "MemMap.h"

#if (COM_TXIPDUNUM >= 1u)
/******************************************************************************
*    used for application:message tx timeout indication Function               
******************************************************************************/
#ifdef COM_ENABLE_TXTOINDFUN 
extern void AppIpduDCM_1_TxTOIndication(void);
extern void AppIpduDCM_2_TxTOIndication(void);
extern void AppIpduDCM_3_TxTOIndication(void);
extern void AppIpduDCM_RemoteDiag_TxTOIndication(void);
#endif

/******************************************************************************
*    Ipdu Tx Confirmation function declare                                     
******************************************************************************/
#ifdef COM_ENABLE_TXCONFIRMATIONFUN 
extern void AppIpduDCM_1_Conf(void);
extern void AppIpduDCM_2_Conf(void);
extern void AppIpduDCM_3_Conf(void);
extern void AppIpduDCM_RemoteDiag_Conf(void);
#endif

#endif /*#if (COM_TXIPDUNUM>=1)*/ 

/******************************************************************************
*    number of Rx object                                                       
******************************************************************************/
#define COM_RXIPDUNUM    (39U)
/******************************************************************************
*    Handles of receive messages                                                  
******************************************************************************/
#define COM_RXIPDUACU_3                  (0U)
#define COM_RXIPDUACU_2                  (1U)
#define COM_RXIPDUFLZCU_1                (2U)
#define COM_RXIPDUFRZCU_2                (3U)
#define COM_RXIPDUBNCM_14                (4U)
#define COM_RXIPDUFRZCU_1                (5U)
#define COM_RXIPDURZCU_2                 (6U)

#if  E0X_DCM == E0X_DCM_FL 
#define COM_RXIPDURCM_1                  (7U)
#define COM_RXIPDURCM_3                  (8U)
#define COM_RXIPDUFLDRM_1                (9U)
#elif  E0X_DCM == E0X_DCM_FR 
#define COM_RXIPDURCM_2                  (7U)
#define COM_RXIPDURCM_4                  (8U)
#define COM_RXIPDUFRDRM_1                (9U)
#elif  E0X_DCM == E0X_DCM_RL 
#define COM_RXIPDURCM_1                  (7U)
#define COM_RXIPDURCM_3                  (8U)
#define COM_RXIPDURLDRM_1                (9U)
#elif  E0X_DCM == E0X_DCM_RR 
#define COM_RXIPDURCM_2                  (7U)
#define COM_RXIPDURCM_4                  (8U)
#define COM_RXIPDURRDRM_1                (9U)
#else
#error "the define E0X_DCM is error!"
#endif 

#define COM_RXIPDUASU_2                  (10U)
#define COM_RXIPDUBNCM_1                 (11U)
#define COM_RXIPDUVCC_4                  (12U)
#define COM_RXIPDUVCC_5                  (13U)
#define COM_RXIPDUVCC_6                  (14U)
#define COM_RXIPDUFLZCU_5                (15U)

#if  E0X_DCM == E0X_DCM_FL 
#define COM_RXIPDUFRDCM_1                (16U)
#define COM_RXIPDURLDCM_1                (17U)
#define COM_RXIPDURRDCM_1                (18U)

#elif  E0X_DCM == E0X_DCM_FR 
#define COM_RXIPDUFLDCM_1                (16U)
#define COM_RXIPDURLDCM_1                (17U)
#define COM_RXIPDURRDCM_1                (18U)

#elif  E0X_DCM == E0X_DCM_RL 
#define COM_RXIPDUFLDCM_1                (16U)
#define COM_RXIPDUFRDCM_1                (17U)
#define COM_RXIPDURRDCM_1                (18U)

#elif  E0X_DCM == E0X_DCM_RR 
#define COM_RXIPDUFLDCM_1                (16U)
#define COM_RXIPDUFRDCM_1                (17U)
#define COM_RXIPDURLDCM_1                (18U)

#else
#error "the define E0X_DCM is error!"
#endif 
#define COM_RXIPDUVCC_1                  (19U)
#define COM_RXIPDUVCC_2                  (20U)
#define COM_RXIPDURLCR_1                 (21U)
#define COM_RXIPDURLCR_2                 (22U)
#define COM_RXIPDUICC_BD_11              (23U)
#define COM_RXIPDUONEBOX_1_G             (24U)
#define COM_RXIPDURZCU_1                 (25U)
#define COM_RXIPDUBNCM_15                (26U)
#define COM_RXIPDUTMS_1                  (27U)
#define COM_RXIPDUACU_1                  (28U)
#define COM_RXIPDUFLZCU_9                (29U)
#define COM_RXIPDUBNCM_6                 (30U)
#define COM_RXIPDUVCU_1_G                (31U)

#define COM_RXIPDUVCU_2_G                (32U)
#define COM_RXIPDUASU_1                  (33U)
#define COM_RXIPDUICC_COM_1              (34U)
#define COM_RXIPDURRCR_1                 (35U)
#define COM_RXIPDUPEPS_3                 (26U)
#define COM_RXIPDUICC_COM_16             (37U)
#define COM_RXIPDUICC_COM_8              (38U)

/******************************************************************************
*    the buffer size of Message received                                       
******************************************************************************/
#define COM_RXIPDUACU_3_BUFFER_SIZE               (8U)
#define COM_RXIPDUACU_2_BUFFER_SIZE               (8U)
#define COM_RXIPDUFLZCU_1_BUFFER_SIZE             (8U)
#define COM_RXIPDUFRZCU_2_BUFFER_SIZE             (8U)
#define COM_RXIPDUFRZCU_1_BUFFER_SIZE             (8U)
#define COM_RXIPDURZCU_2_BUFFER_SIZE              (8U)

#define COM_RXIPDURCM_1_BUFFER_SIZE               (8U)
#define COM_RXIPDURCM_2_BUFFER_SIZE               (8U)
#define COM_RXIPDURCM_3_BUFFER_SIZE               (8U)
#define COM_RXIPDURCM_4_BUFFER_SIZE               (8U)

#define COM_RXIPDUFLDRM_1_BUFFER_SIZE             (8U)
#define COM_RXIPDUFRDRM_1_BUFFER_SIZE             (8U)
#define COM_RXIPDURLDRM_1_BUFFER_SIZE             (8U)
#define COM_RXIPDURRDRM_1_BUFFER_SIZE             (8U)


#define COM_RXIPDUBNCM_1_BUFFER_SIZE              (8U)
#define COM_RXIPDUASU_2_BUFFER_SIZE               (8U)
#define COM_RXIPDUFLDCM_1_BUFFER_SIZE             (8U)
#define COM_RXIPDUFRDCM_1_BUFFER_SIZE             (8U)
#define COM_RXIPDURLDCM_1_BUFFER_SIZE             (8U)
#define COM_RXIPDURRDCM_1_BUFFER_SIZE             (8U)

#define COM_RXIPDUHCU_EMS_2_G_BUFFER_SIZE         (8U)
#define COM_RXIPDUPEPS_1_BUFFER_SIZE              (8U)
#define COM_RXIPDUONEBOX_1_G_BUFFER_SIZE          (8U)
#define COM_RXIPDURZCU_1_BUFFER_SIZE              (8U)
#define COM_RXIPDUTMS_1_BUFFER_SIZE               (8U)
#define COM_RXIPDUFLZCU_9_BUFFER_SIZE             (8U)
#define COM_RXIPDUBNCM_6_BUFFER_SIZE              (8U)
#define COM_RXIPDUVCU_1_G_BUFFER_SIZE             (8U)
#define COM_RXIPDUVCU_2_G_BUFFER_SIZE             (8U)
#define COM_RXIPDUICC_COM_1_BUFFER_SIZE           (8U)
#define COM_RXIPDUICC_COM_8_BUFFER_SIZE           (8U)
#define COM_RXIPDUICC_COM_16_BUFFER_SIZE           (8U)

#define COM_RXIPDUASU_1_BUFFER_SIZE               (8U)
#define COM_RXIPDURLCR_1_BUFFER_SIZE              (8U)
#define COM_RXIPDURLCR_2_BUFFER_SIZE              (8U)
#define COM_RXIPDUICC_BD_11_BUFFER_SIZE           (8U)
#define COM_RXIPDURRCR_1_BUFFER_SIZE              (8U)

#define COM_RXIPDUBNCM_14_BUFFER_SIZE              (8U)
#define COM_RXIPDUBNCM_15_BUFFER_SIZE              (8U)
#define COM_RXIPDUFLZCU_5_BUFFER_SIZE              (8U)
#define COM_RXIPDUVCC_1_BUFFER_SIZE                (8U)
#define COM_RXIPDUVCC_2_BUFFER_SIZE                (8U)
#define COM_RXIPDUVCC_4_BUFFER_SIZE                (8U)
#define COM_RXIPDUVCC_5_BUFFER_SIZE                (8U)
#define COM_RXIPDUVCC_6_BUFFER_SIZE                (8U)
#define COM_RXIPDUACU_1_BUFFER_SIZE                (8U)
#define COM_RXIPDUPEPS_3_BUFFER_SIZE               (8U)
/******************************************************************************
*    number of Rx object Signal                                                
******************************************************************************/
#define COM_RXSIGNUM    (120U)
/******************************************************************************
*    Receive Signal structures                                                    
******************************************************************************/
typedef struct {
    uint8 unused0_Byte0 : 8;
    uint8 unused0_Byte1 : 8;
    uint8 unused0_Byte2 : 8;
    uint8 ACU_1_PsngrSeatBeltWarning : 2; 
    uint8 ACU_1_SecRowLBeltWarning : 1;
    uint8 unused0_Byte3: 1;
    uint8 ACU_1_SecRowMBeltWarning : 1;
    uint8 unused0_Byte4 : 1;
    uint8 ACU_1_SecRowRBeltWarning : 1;
    uint8 unused0_Byte5 : 1;    
    uint8 unused0_Byte6 : 6;
    uint8 ACU_1_PsngrSeatOccupiedSts : 2;
    uint8 ACU_1_SecRowLSeatOccupiedSts : 2;
    uint8 ACU_1_SecRowMSeatOccupiedSts : 2;
    uint8 ACU_1_SecRowRSeatOccupiedSts : 2;
    uint8 unused0_Byte7 : 2;
    uint8 unused0_Byte8 : 8;
    uint8 unused0_Byte9 : 8;
}IpduACU_1_Type;

typedef struct {
    uint8 unused0_Byte0 : 8;
    uint8 unused0_Byte1 : 8;
    uint8 PEPS_LockButtAct : 2;
    uint8 PEPS_UnLockButtAct : 2;   
    uint8 PEPS_SingleSidePolling : 2;
    uint8 unused0_Byte2 : 2;
    uint8 unused0_Byte3 : 8;
    uint8 unused0_Byte4 : 8;
    uint8 unused0_Byte5 : 8;
    uint8 unused0_Byte6 : 8;
    uint8 unused0_Byte7 : 8;
}IpduPEPS_3_Type;

typedef struct {
    uint8 unused0_Byte0 : 8;
    uint8 unused0_Byte1 : 8;
    uint8 unused0_Byte2 : 7;
    uint8 VCC_2_ConfigurationMessageTrg : 1;   
    uint8 unused0_Byte3 : 8;
    uint8 unused0_Byte4 : 8;
    uint8 unused0_Byte5 : 8;
    uint8 unused0_Byte6 : 8;
    uint8 unused0_Byte7 : 8;
}IpduVCC_2_Type;

typedef struct {
    uint8 VCC_4_CRC : 8;
    uint8 VCC_4_RollgCntr : 4;
    uint8 VCC_4_Resd1 : 4;
    uint8 VCC_4_SN : 8; 
    uint8 unused0_Byte0 : 8;
    uint8 unused0_Byte1 : 8;
    uint8 unused0_Byte2 : 8;
    //uint8 BNCM : 1;
    uint8 LeftAndRightRudder : 1;
    uint8 unused0_Byte3 : 6;
    uint8 BNCM : 1;
    uint8 SideDoorOpeningMode : 6;
    uint8 unused0_Byte4 : 2;
}IpduVCC_4_Type;

typedef struct {
    uint8 VCC_5_CRC : 8;
    uint8 VCC_5_RollgCntr : 4;
    uint8 VCC_5_Resd1 : 4;
    uint8 VCC_5_SN : 8; 
    uint8 unused0_Byte0 : 8;
    uint8 unused0_Byte1 : 8;
    uint8 unused0_Byte2 : 8;
    uint8 unused0_Byte3 : 8;
    uint8 unused0_Byte4 : 8;
}IpduVCC_5_Type;

typedef struct {
    uint8 VCC_6_CRC : 8;
    uint8 VCC_6_RollgCntr : 4;
    uint8 VCC_6_Resd1 : 4;
    uint8 VCC_6_SN : 8; 
    uint8 unused0_Byte0 : 8;
    uint8 unused0_Byte1 : 8;
    uint8 unused0_Byte2 : 8;
    uint8 unused0_Byte3 : 8;
    uint8 unused0_Byte4 : 8;
}IpduVCC_6_Type;

typedef struct {
    uint8 unused0_Byte0 : 8;
    uint8 unused0_Byte1 : 8;
    uint8 unused0_Byte2 : 8;
    uint8 unused0_Byte3 : 5;
    uint8 VCC_1_CarMode : 3;
    uint8 unused0_Byte4 : 8;
    uint8 unused0_Byte5 : 8;
    uint8 unused0_Byte6 : 8;
    uint8 unused0_Byte7 : 8;
}IpduVCC_1_Type;

typedef struct {
    uint8 unused0_Byte0 : 8;
    uint8 unused0_Byte1 : 8;
    uint8 BNCM_14_LockButtAct : 2;
    uint8 BNCM_14_UnLockButtAct : 2;
    uint8 unused0_Byte2 : 4;
    uint8 unused0_Byte3 : 8;
    uint8 unused0_Byte4 : 8;
    uint8 unused0_Byte5 : 8;
    uint8 unused0_Byte6 : 8;
    uint8 unused0_Byte7 : 8;
}IpduBNCM_14_Type;

typedef struct {
    uint8 unused0_Byte0 : 8;
    uint8 unused0_Byte1 : 8;
    uint8 unused0_Byte2 : 8;
    uint8 unused0_Byte3 : 4;
    uint8 BNCM_FL_BLEControlDoor : 1;
    uint8 BNCM_FR_BLEControlDoor : 1;
    uint8 BNCM_RL_BLEControlDoor : 1;
    uint8 BNCM_RR_BLEControlDoor : 1;
    uint8 BNCM_BLE_CloseAllDoors : 1;
    uint8 unused0_Byte4 : 7;
    uint8 unused0_Byte5 : 8;
    uint8 unused0_Byte6 : 8;
    uint8 unused0_Byte7 : 8;
}IpduBNCM_15_Type;

typedef struct {
    uint8 unused0_Byte0 : 8;
    uint8 unused0_Byte1 : 8;
    uint8 ASU_2_LFHeight_Lo : 8;
    uint8 ASU_2_RFHeight_Lo : 4;
    uint8 ASU_2_LFHeight_Hi : 4;
    uint8 ASU_2_RFHeight_Hi : 8;
    uint8 ASU_2_LRHeight_Lo : 8;
    uint8 ASU_2_RRHeight_Lo : 4;
    uint8 ASU_2_LRHeight_Hi : 4;
    uint8 ASU_2_RRHeight_Hi : 8;
}IpduASU_2_Type;

typedef struct {
    uint8 unused0_Byte0 : 8;
    uint8 unused0_Byte1 : 8;
    uint8 RLCR_1_SysSt : 2;
    uint8 RLCR_1_BlkSts : 1;
    uint8 unused0_Byte2 : 3;
    uint8 RLCR_1_DOWWarn : 2;
    uint8 RLCR_1_DowLock : 2;
    uint8 unused0_Byte3 : 6;
    uint8 unused0_Byte4 : 8;
    uint8 unused0_Byte5 : 8;
    uint8 unused0_Byte6 : 8;
    uint8 unused0_Byte7 : 8;
}IpduRLCR_1_Type;

typedef struct {
    uint8 unused0_Byte0 : 8;
    uint8 unused0_Byte1 : 8;
    uint8 unused0_Byte2 : 8;
    uint8 unused0_Byte3 : 8;
    uint8 unused0_Byte4 : 2;
    uint8 RLCR_2_DOWONOFFSts : 2;
    uint8 unused0_Byte5 : 4;
    uint8 unused0_Byte6 : 8;
    uint8 unused0_Byte7 : 8;
    uint8 unused0_Byte8 : 8;
}IpduRLCR_2_Type;

typedef struct {
    uint8 unused0_Byte0 : 8;
    uint8 unused0_Byte1 : 8;
    uint8 unused0_Byte2 : 8;
    uint8 ICC_FLDoorButton : 2;
    uint8 ICC_FRDoorButton : 2;
    uint8 unused0_Byte3 : 4;
    uint8 ICC_RRDoorButton : 2;
    uint8 ICC_RLDoorButton : 2;
    uint8 ICC_CloseAllDoors : 2;
    uint8 ICC_DoorRemoteKeyControlEnable : 2;
    uint8 ICC_SetOpenAngle : 2;
    uint8 ICC_BLEOpenDriverDoorEnable : 2;
    uint8 ICC_FrontDoorPowerMode : 2;
    uint8 ICC_RearDoorPowerMode : 2;
    uint8 ICC_PedalCloseDriverDoorEnable : 2;
    uint8 RR_Door_RearScreen_Control : 2;
    uint8 ICC_RearDoorVoiceControlEnable : 2;
    uint8 ICC_FLVoiceControl : 2;
    uint8 ICC_FRVoiceControl : 2;
    uint8 ICC_RRVoiceControl : 2;
    uint8 ICC_RLVoiceControl : 2;
    uint8 RL_Door_RearScreen_Control : 2;
}IpduICC_BD_11_Type;

typedef struct {
    uint8 unused0_Byte0 : 8;
    uint8 unused0_Byte1 : 8;
    uint8 RRCR_1_SysSt : 2;
    uint8 RRCR_1_BlkSts : 1;
    uint8 unused0_Byte2 : 3;
    uint8 RRCR_1_DOWWarn : 2;
    uint8 RRCR_1_DowLock : 2;
    uint8 unused0_Byte3 : 6;
    uint8 unused0_Byte4 : 8;
    uint8 unused0_Byte5 : 8;
    uint8 unused0_Byte6 : 8;
    uint8 unused0_Byte7 : 8;
}IpduRRCR_1_Type;

typedef struct {
    uint8 unused0_Byte0 : 8;
    uint8 unused0_Byte1 : 8;
    uint8 unused0_Byte2 : 4;
    uint8 ASU_1_SuspCurrentLvl : 4;
    uint8 unused0_Byte3 : 5;
    uint8 ASU_1_SuspTarLvl : 3;
    uint8 ASU_1_EasyEntryEna : 1;
    uint8 ASU_1_AutoEasyEntryFb : 1;
    uint8 unused0_Byte4 : 3;
    uint8 ASU_1_BluetoothManEasyEntryFb : 1;
    uint8 unused0_Byte5 : 2;
    uint8 unused0_Byte6 : 8;
    uint8 unused0_Byte7 : 8;
    uint8 unused0_Byte8 : 8;
}IpduASU_1_Type;

typedef struct {
    uint8 unused0_Byte0 : 8;
    uint8 unused0_Byte1 : 8;
    uint8 unused0_Byte2 : 8;
    uint8 OrderInformation : 4;
    uint8 unused0_Byte3 : 2;
    uint8 InformationSource : 2;
    uint8 unused0_Byte4 : 8;
    uint8 unused0_Byte5 : 8;
    uint8 unused0_Byte6 : 8;
    uint8 unused0_Byte7 : 8; 
}IpduPEPS_1_Type;

typedef struct {
    uint8 unused0_Byte0 : 8;
    uint8 unused0_Byte1 : 8;
    uint8 unused0_Byte2 : 8;
    uint8 unused0_Byte3 : 5;
    uint8 BrakePedalSts : 1;
    uint8 BrakePedalStsValidData : 1;
    uint8 unused0_Byte4 : 1;
    uint8 unused0_Byte5 : 8;
    uint8 unused0_Byte6 : 8;
    uint8 unused0_Byte7 : 8; 
    uint8 unused0_Byte8 : 8; 
}IpduHCU_EMS_2_G_Type;

typedef struct {
    uint8 unused0_Byte0 : 8;
    uint8 unused0_Byte1 : 8;
    uint8 ACU_2_LateralAcceleration_Lo : 8;
    uint8 ACU_2_LateralAcceleration_Hi : 8;
    uint8 unused0_Byte4 : 8;
    uint8 unused0_Byte5 : 8;
    uint8 unused0_Byte6 : 3;
    uint8 ACU_2_LateralAccelerationSigVD : 2;
    uint8 unused0_Byte7 : 3;
    uint8 unused0_Byte8 : 8; 
}IpduACU_2_Type;

typedef struct {
    uint8 unused0_Byte0 : 8;
    uint8 unused0_Byte1 : 8;
    uint8 ACU_3_LongitudinalAcceleration_Lo : 8;
    uint8 ACU_3_LongitudinalAcceleration_Hi : 8;
    uint8 unused0_Byte2 : 6;
    uint8 ACU_3_LongitudinalAccelerationVD : 2;
    uint8 ACU_3_CrashOutputSts : 8;
    uint8 unused0_Byte3 : 8;
    uint8 unused0_Byte4 : 8;
}IpduACU_3_Type;

typedef struct {
    uint8 unused0_Byte0 : 8;
    uint8 unused0_Byte1 : 8;
    uint8 unused0_Byte2 : 8;
    uint8 unused0_Byte3 : 2;
    uint8 BNCM_1_UIRUnLockRequest : 1;
    uint8 unused0_Byte4 : 5;
    uint8 unused0_Byte5 : 8;
    uint8 unused0_Byte6 : 8;
    uint8 unused0_Byte7 : 8;
    uint8 BNCM_1_ValidKeyType : 3;
    uint8 BNCM_1_DriDoorReq : 1;   
    uint8 unused0_Byte8 : 4;
}IpduBNCM_1_Type;

typedef struct {
    uint8 BNCM_6_RemoteControl : 5;
    uint8 unused0_Byte0 : 3;
    uint8 unused0_Byte1 : 8;
    uint8 unused0_Byte2 : 8;
    uint8 unused0_Byte3 : 8;
    uint8 unused0_Byte4 : 8;
    uint8 unused0_Byte5 : 8;
    uint8 unused0_Byte6 : 8;
    uint8 unused0_Byte7 : 8;
}IpduBNCM_6_Type;

typedef struct {
    uint8 unused0_Byte0 : 8;
    uint8 unused0_Byte1 : 8;
    uint8 unused0_Byte2 : 8;
    uint8 unused0_Byte3 : 8;
    uint8 ExternalTemperature_C : 8;
    uint8 ExternalTemperatureFailSts : 1;
    uint8 BlowSpeedLevelDisplaySts : 4;
    uint8 CirculationModeDisplaySts : 1;
    uint8 unused0_Byte6 : 2;
    uint8 unused0_Byte7 : 8;
    uint8 unused0_Byte8 : 8;
}IpduTMS_1_Type;

typedef struct {
    uint8 unused0_Byte0 : 8;
    uint8 unused0_Byte1 : 8;
    uint8 unused0_Byte2 : 5;
    uint8 FL_SeatOccupiedSts : 1;
    uint8 LHFDoorSts : 2;
    uint8 unused0_Byte3 : 7;
    uint8 LHFSeatBeltSW : 1;    
    uint8 FLWinPosn : 7;
    uint8 FLLockReleaseInsdSW : 1;    
    uint8 FLLockReleaseOutsdSW : 1; 
    uint8 FL_CentralLockSwitch : 2;
    uint8 unused0_Byte5 : 5;
    uint8 unused0_Byte6 : 8;
    uint8 FL_DoorOpenSwitch : 1;   
    uint8 FL_DoorAjarSwitch : 1; 
    uint8 FL_ReleaseLatchStatus : 3;
    uint8 unused0_Byte7 : 3;
}IpduFLZCU_1_Type;

typedef struct {
    uint8 unused0_Byte0 : 8;
    uint8 unused0_Byte1 : 8;
    uint8 unused0_Byte2 : 6;
    uint8 HandleSwitchStsFL : 2;
    uint8 HandleSwitchStsFR : 2;    
    uint8 HandleSwitchStsRR : 2;
    uint8 HandleSwitchStsRL : 2;    
    uint8 unused0_Byte3 : 2;
    uint8 unused0_Byte4 : 8;
    uint8 unused0_Byte5 : 8;
    uint8 unused0_Byte6 : 8;
    uint8 unused0_Byte7 : 8;
}IpduFLZCU_5_Type;

typedef struct {
    uint8 unused0_Byte0 : 8;
    uint8 unused0_Byte1 : 8;
    uint8 RCM_FRRadarAngle : 8;
    uint8 RCM_FRRadar1Distance : 8;    
    uint8 RCM_FRRadar2Distance : 8;
    uint8 RCM_FRRadar3Distance : 8;    
    uint8 unused0_Byte2 : 4;
    uint8 RCM_FRRadarDetection : 2;
    uint8 RCM_FRRadarStatus : 2;
    uint8 unused0_Byte3 : 8;
}IpduFRZCU_4_Type;

typedef struct {
    uint8 unused0_Byte0 : 8;
    uint8 unused0_Byte1 : 8;
    uint8 RCM_RRRadarAngle : 8;
    uint8 RCM_RRRadar1Distance : 8;    
    uint8 RCM_RRRadar2Distance : 8;
    uint8 RCM_RRRadar3Distance : 8;    
    uint8 unused0_Byte2 : 4;
    uint8 RCM_RRRadarDetection : 2;
    uint8 RCM_RRRadarStatus : 2;
    uint8 unused0_Byte3 : 8;
}IpduFRZCU_5_Type;

typedef struct {
    uint8 unused0_Byte0 : 8;
    uint8 unused0_Byte1 : 8;
    uint8 RCM_RLRadarAngle : 8;
    uint8 RCM_RLRadar1Distance : 8;    
    uint8 RCM_RLRadar2Distance : 8;
    uint8 RCM_RLRadar3Distance : 8;    
    uint8 unused0_Byte2 : 4;
    uint8 RCM_RLRadarDetection : 2;
    uint8 RCM_RLRadarStatus : 2;
    uint8 unused0_Byte3 : 8;
}IpduRZCU_3_Type;

typedef struct {
    uint8 unused0_Byte0 : 8;
    uint8 unused0_Byte1 : 8;
    uint8 DRM_1_DRMAngle : 7;
    uint8 unused0_Byte2 : 1;
    uint8 DRM_1_AbstacleToDRMXdistance : 8;    
    uint8 DRM_1_AbstacleToDRMYDistance : 8;
    uint8 DRM_1_AbstacleToDRMZdistance : 8;    
    uint8 DRM_1_VAbstacleToDRMSpeed : 7;
    uint8 unused0_Byte3 : 1;
    uint8 DRM_1_StsDRMToDCM : 3;
    uint8 DRM_1_DRMFaultBusoff : 1;
    uint8 DRM_1_DRMFaultOvervoltage : 1;
    uint8 DRM_1_DRMFaultUndervoltage : 1;
    uint8 DRM_1_DRMFaultOvertemp : 1;
    uint8 DRM_1_ReqDRMToDCM : 1;
}IpduDRM_1_Type;

typedef struct {
    uint8 unused0_Byte0 : 8;
    uint8 unused0_Byte1 : 8;
    uint8 FLZCU_9_PowerMode : 2;
    uint8 unused0_Byte2 : 6;
    uint8 FLZCU_9_ArmingSts : 2;
    uint8 unused0_Byte3 : 6;
    uint8 FLZCU_9_BLEOpenDriverDoorSts : 2;
    uint8 unused0_Byte4 : 6;
    uint8 unused0_Byte5 : 8;
    uint8 unused0_Byte6 : 8;
    uint8 unused0_Byte7 : 8;
}IpduFLZCU_9_Type;

typedef struct {
    uint8 unused0_Byte0 : 8;
    uint8 unused0_Byte1 : 8;
    uint8 unused0_Byte2 : 2;
    uint8 FRLockReleaseInsdSW : 1;
    uint8 unused2_Byte0 : 2;
    uint8 RHFDoorSts : 2;
    uint8 unused2_Byte1 : 1;
    uint8 FRWinPosn : 7;    
    uint8 unused0_Byte3 : 1;
    uint8 RRWinPosn : 7;
    uint8 unused1_Byte4 : 1;
    uint8 unused0_Byte5 : 8;
    uint8 RHRDoorSts : 2;
    uint8 FRLockReleaseOutsdSW : 1;
    uint8 unused0_Byte6 : 5;
    uint8 RRLockReleaseInsdSW : 1;
    uint8 RRLockReleaseOutsdSW : 1;
    uint8 unused0_Byte7 : 6;
}IpduFRZCU_1_Type;

typedef struct {
    uint8 unused0_Byte0 : 8;
    uint8 unused0_Byte1 : 8;
    uint8 FR_DoorOpenSwitch : 1;
    uint8 FR_DoorAjarSwitch : 1;
    uint8 FR_ReleaseLatchStatus : 3;
    uint8 RR_DoorOpenSwitch : 1;
    uint8 RR_DoorAjarSwitch : 1; 
    uint8 unused1_Byte2 : 1;
    uint8 RR_ChildrenProtectSwitch : 2;
    uint8 RR_ReleaseLatchStatus : 3;
    uint8 unused1_Byte3 : 3;
    uint8 unused0_Byte4 : 8;
    uint8 unused0_Byte5 : 8;
    uint8 unused0_Byte6 : 8;
    uint8 unused0_Byte7 : 8;
}IpduFRZCU_2_Type;

typedef struct {
    uint8 unused2_Byte0 : 8;
    uint8 unused2_Byte1 : 8;
    uint8 PLG_OperateSts : 8;
    uint8 unused2_Byte2 : 8;
    uint8 unused2_Byte3 : 8;
    uint8 unused2_Byte4 : 8;
    uint8 unused2_Byte5 : 8;
    uint8 unused2_Byte6 : 8;
}IpduRZCU_1_Type;

typedef struct {
    uint8 unused2_Byte0 : 8;
    uint8 unused2_Byte1 : 8;
    uint8 unused1_Byte2 : 2;
    uint8 RLLockReleaseInsdSW : 1;
    uint8 RLLockReleaseOutsdSW : 1;
    uint8 LHRdoorSts : 2;
    uint8 unused2_Byte2 : 2;
    uint8 RLWinPosn : 7;
    uint8 unused2_Byte3 : 1;
    uint8 unused2_Byte4 : 8;   
    uint8 RL_DoorOpenSwitch : 1;
    uint8 RL_DoorAjarSwitch : 1;
    uint8 RL_ChildrenProtectSwitch : 2;
    uint8 RL_ReleaseLatchStatus : 3;
    uint8 unused2_Byte5 : 1;
    uint8 unused2_Byte6 : 8;
    uint8 unused2_Byte7 : 8;
}IpduRZCU_2_Type;

typedef struct {
    uint8 unused0_Byte0 : 8;
    uint8 unused0_Byte1 : 8;
    uint8 TotalOdometer_km_OBD_Lo : 8; 
    uint8 TotalOdometer_km_OBD_Mi : 8;
    uint8 TotalOdometer_km_OBD_Hi : 8;
    uint8 unused0_Byte2 : 8;
    uint8 unused0_Byte3 : 8;
    uint8 unused0_Byte4 : 8;
}IpduICC_COM_1_Type;

typedef struct {

    uint8 CurrentTimeYear : 8;
    uint8 unused0_Byte0 : 4;
    uint8 CurrentTimeMonth : 4;
    uint8 unused0_Byte1 : 3;
    uint8 CurrentTimeDay : 5;   
    uint8 unused0_Byte2 : 3;
    uint8 CurrentTimeHour : 5;
    uint8 unused0_Byte3 : 2;
    uint8 CurrentTimeMinute : 6;   
    uint8 unused0_Byte4 : 2; 
    uint8 CurrentTimeSecond : 6;
    uint8 unused0_Byte5 : 8; 
    uint8 unused0_Byte6 : 8; 
}IpduICC_COM_8_Type;

typedef struct {
    uint8 unused0_Byte0 : 8;
    uint8 unused0_Byte1 : 8;
    uint8 VehicleSpeedVSOSig_Lo : 8;  
    uint8 unused0_Byte2 : 2;
    uint8 VehicleSpeedVSOSigValidData  : 1;    
    uint8 VehicleSpeedVSOSig_Hi : 5; 
    uint8 unused0_Byte3 : 8;   
    uint8 unused0_Byte4 : 8;
    uint8 unused0_Byte5 : 8;   
    uint8 unused0_Byte6 : 8;
}IpduONEBOX_1_G_Type;

typedef struct {
    uint8 unused0_Byte0 : 8;
    uint8 unused0_Byte1 : 8;   
    uint8 RCM_1_FLRadarAngle : 7;
    uint8 unused0_Byte2 : 1;
    uint8 RCM_1_FLRadar1Distance : 7;
    uint8 unused0_Byte3 : 1;
    uint8 RCM_1_FLRadar2Distance : 7;
    uint8 unused0_Byte4 : 1;
    uint8 RCM_1_FLRadarDetection : 2;
    uint8 RCM_1_FLRadarStatus : 2;
    uint8 RCM_1_LRadarVoltageStatus : 2;
    uint8 RCM_1_VoltageStatus : 2;
    uint8 RCM_1_FLDoorTemperatureStatus : 1;
    uint8 unused0_Byte5 : 7;
    uint8 unused0_Byte6 : 8;
}IpduRCM_1_Type;

typedef struct {
    uint8 unused0_Byte0 : 8;
    uint8 unused0_Byte1 : 8;   
    uint8 RCM_2_FRRadarAngle : 7;
    uint8 unused0_Byte2 : 1;
    uint8 RCM_2_FRRadar1Distance : 7;
    uint8 unused0_Byte3 : 1;
    uint8 RCM_2_FRRadar2Distance : 7;
    uint8 unused0_Byte4 : 1;
    uint8 RCM_2_FRRadarDetection : 2;
    uint8 RCM_2_FRRadarStatus : 2;
    uint8 RCM_2_RRadarVoltageStatus : 2;
    uint8 unused0_Byte5 : 2;
    uint8 RCM_2_FRDoorTemperatureStatus : 1;
    uint8 unused0_Byte6 : 7;
    uint8 unused0_Byte7 : 8;
}IpduRCM_2_Type;

typedef struct {
    uint8 unused0_Byte0 : 8;
    uint8 unused0_Byte1 : 8;   
    uint8 RCM_3_RLRadarAngle : 7;
    uint8 unused0_Byte2 : 1;
    uint8 RCM_3_RLRadar1Distance : 7;
    uint8 unused0_Byte3 : 1;
    uint8 RCM_3_RLRadar2Distance : 7;
    uint8 unused0_Byte4 : 1;
    uint8 RCM_3_RLRadar3Distance : 7;
    uint8 unused0_Byte5 : 1;
    uint8 RCM_3_RLRadarDetection : 2;
    uint8 RCM_3_RLRadarStatus : 3;
    uint8 RCM_3_RLDoorTemperatureStatus : 1;
    uint8 unused0_Byte6 : 2;
    uint8 unused0_Byte7 : 8;
}IpduRCM_3_Type;

typedef struct {
    uint8 unused0_Byte0 : 8;
    uint8 unused0_Byte1 : 8;   
    uint8 RCM_4_RRRadarAngle : 7;
    uint8 unused0_Byte2 : 1;
    uint8 RCM_4_RRRadar1Distance : 7;
    uint8 unused0_Byte3 : 1;
    uint8 RCM_4_RRRadar2Distance : 7;
    uint8 unused0_Byte4 : 1;
    uint8 RCM_4_RRRadar3Distance : 7;
    uint8 unused0_Byte5 : 1;
    uint8 RCM_4_RRRadarDetection : 2;
    uint8 RCM_4_RRRadarStatus : 3;
    uint8 RCM_4_RRDoorTemperatureStatus : 1;
    uint8 unused0_Byte6 : 2;
    uint8 unused0_Byte7 : 8;
}IpduRCM_4_Type;

typedef struct {
    uint8 unused0_Byte0 : 8;
    uint8 unused0_Byte1 : 8;   
    uint8 unused0_Byte2 : 8;
    uint8 unused0_Byte3 : 8;
    uint8 VCU_PTReady : 1;
    uint8 unused0_Byte4 : 7;
    uint8 unused0_Byte5 : 8;
    uint8 unused0_Byte6 : 8;
    uint8 unused0_Byte7 : 4;
    uint8 VCU_PRNDGearAct : 3;
    uint8 unused0_Byte8 : 1;
}IpduVCU_1_G_Type;


typedef struct {
    uint8 unused0_Byte0 : 8;
    uint8 unused0_Byte1 : 8;
    uint8 unused0_Byte2 : 8;
    uint8 unused0_Byte3 : 8;
    uint8 unused0_Byte4 : 6;
    uint8 ICC_CleanMode : 2;
    uint8 unused0_Byte5 : 8;
    uint8 unused0_Byte6 : 8;
    uint8 unused0_Byte7 : 8;

}IpduICC_COM_16_Type;

typedef struct {
    uint8 unused0_Byte0 : 8;
    uint8 unused0_Byte1 : 8;
    uint8 unused0_Byte2 : 8;
    uint8 unused0_Byte3 : 7;
    uint8 VCU_BrakePedalStsValidData : 1;
    uint8 unused0_Byte4 : 4;
    uint8 VCU_BrakePedalSts : 1;
    uint8 unused0_Byte5 : 1;
    uint8 VCU_HVReady : 1;
    uint8 unused0_Byte6 : 1;
    uint8 unused0_Byte7 : 8;
    uint8 unused0_Byte8 : 8;
    uint8 unused0_Byte9 : 8;
}IpduVCU_2_G_Type;
/******************************************************************************
*    Receive Message unions                                                       
******************************************************************************/
typedef union {
    IpduACU_1_Type  Ipdu;
    uint8  _c[8];
}IpduACU_1_bufType;

typedef union {
    IpduPEPS_3_Type  Ipdu;
    uint8  _c[8];
}IpduPEPS_3_bufType;

typedef union {
    IpduASU_2_Type  Ipdu;
    uint8  _c[8];
}IpduASU_2_bufType;

typedef union {
    IpduPEPS_1_Type  Ipdu;
    uint8  _c[8];
}IpduPEPS_1_bufType;

typedef union {
    IpduHCU_EMS_2_G_Type  Ipdu;
    uint8  _c[8];
}IpduHCU_EMS_2_G_bufType;

typedef union {
    IpduACU_2_Type  Ipdu;
    uint8  _c[8];
}IpduACU_2_bufType;

typedef union {
    IpduACU_3_Type  Ipdu;
    uint8  _c[8];
}IpduACU_3_bufType;

typedef union {
    IpduBNCM_1_Type  Ipdu;
    uint8  _c[8];
}IpduBNCM_1_bufType;

typedef union {
    IpduBNCM_6_Type  Ipdu;
    uint8  _c[8];
}IpduBNCM_6_bufType;

typedef union {
    IpduTMS_1_Type  Ipdu;
    uint8  _c[8];
}IpduTMS_1_bufType;

typedef union {
    IpduFLZCU_1_Type  Ipdu;
    uint8  _c[8];
}IpduFLZCU_1_bufType;

typedef union {
    IpduFLZCU_5_Type  Ipdu;
    uint8  _c[8];
}IpduFLZCU_5_bufType;

typedef union {
    IpduFRZCU_4_Type  Ipdu;
    uint8  _c[8];
}IpduFRZCU_4_bufType;

typedef union {
    IpduDRM_1_Type  Ipdu;
    uint8  _c[8];
}IpduDRM_1_bufType;

typedef union {
    IpduFRZCU_5_Type  Ipdu;
    uint8  _c[8];
}IpduFRZCU_5_bufType;

typedef union {
    IpduRZCU_3_Type  Ipdu;
    uint8  _c[8];
}IpduRZCU_3_bufType;

typedef union {
    IpduFLZCU_9_Type  Ipdu;
    uint8  _c[8];
}IpduFLZCU_9_bufType;

typedef union {
    IpduFRZCU_1_Type  Ipdu;
    uint8  _c[8];
}IpduFRZCU_1_bufType;

typedef union {
    IpduRZCU_1_Type  Ipdu;
    uint8  _c[8];
}IpduRZCU_1_bufType;

typedef union {
    IpduRZCU_2_Type  Ipdu;
    uint8  _c[8];
}IpduRZCU_2_bufType;

typedef union {
    IpduICC_COM_1_Type  Ipdu;
    uint8  _c[8];
}IpduICC_COM_1_bufType;

typedef union {
    IpduICC_COM_8_Type  Ipdu;
    uint8  _c[8];
}IpduICC_COM_8_bufType;

typedef union {
    IpduONEBOX_1_G_Type  Ipdu;
    uint8  _c[8];
}IpduONEBOX_1_G_bufType;

typedef union {
    IpduVCU_1_G_Type  Ipdu;
    uint8  _c[8];
}IpduVCU_1_G_bufType;

typedef union {
    IpduVCU_2_G_Type  Ipdu;
    uint8  _c[8];
}IpduVCU_2_G_bufType;

typedef union {
    IpduRCM_1_Type  Ipdu;
    uint8  _c[8];
}IpduRCM_1_bufType;

typedef union {
    IpduRCM_2_Type  Ipdu;
    uint8  _c[8];
}IpduRCM_2_bufType;

typedef union {
    IpduRCM_3_Type  Ipdu;
    uint8  _c[8];
}IpduRCM_3_bufType;

typedef union {
    IpduRCM_4_Type  Ipdu;
    uint8  _c[8];
}IpduRCM_4_bufType;

typedef union {
    IpduFRZCU_2_Type  Ipdu;
    uint8  _c[8];
}IpduFRZCU_2_bufType;

typedef union {
    IpduRLCR_1_Type  Ipdu;
    uint8  _c[8];
}IpduRLCR_1_bufType;

typedef union {
    IpduRLCR_2_Type  Ipdu;
    uint8  _c[8];
}IpduRLCR_2_bufType;

typedef union {
    IpduICC_BD_11_Type  Ipdu;
    uint8  _c[8];
}IpduICC_BD_11_bufType;

typedef union {
    IpduASU_1_Type  Ipdu;
    uint8  _c[8];
}IpduASU_1_bufType;

typedef union {
    IpduRRCR_1_Type  Ipdu;
    uint8  _c[8];
}IpduRRCR_1_bufType;

typedef union {
    IpduBNCM_14_Type  Ipdu;
    uint8  _c[8];
}IpduBNCM_14_bufType;

typedef union {
    IpduBNCM_15_Type  Ipdu;
    uint8  _c[8];
}IpduBNCM_15_bufType;

typedef union {
    IpduVCC_1_Type  Ipdu;
    uint8  _c[8];
}IpduVCC_1_bufType;

typedef union {
    IpduVCC_2_Type  Ipdu;
    uint8  _c[8];
}IpduVCC_2_bufType;

typedef union {
    IpduVCC_4_Type  Ipdu;
    uint8  _c[8];
}IpduVCC_4_bufType;

typedef union {
    IpduVCC_5_Type  Ipdu;
    uint8  _c[8];
}IpduVCC_5_bufType;

typedef union {
    IpduICC_COM_16_Type  Ipdu;
    uint8  _c[8];
}IpduICC_COM_16_bufType;

typedef union {
    IpduVCC_6_Type  Ipdu;
    uint8  _c[8];
}IpduVCC_6_bufType;
/******************************************************************************
*    Databuffer for Receive objects                                             
******************************************************************************/
#define COM_START_SEC_VAR_UNSPECIFIED  
//#include "MemMap.h"
extern VAR(IpduACU_3_bufType, COM_PRIVATE_DATA)  RxIpduACU_3;
extern VAR(IpduACU_2_bufType, COM_PRIVATE_DATA)  RxIpduACU_2;
extern VAR(IpduFLZCU_1_bufType, COM_PRIVATE_DATA)  RxIpduFLZCU_1;
extern VAR(IpduFRZCU_2_bufType, COM_PRIVATE_DATA)  RxIpduFRZCU_2;
extern VAR(IpduBNCM_14_bufType, COM_PRIVATE_DATA)  RxIpduBNCM_14;
extern VAR(IpduFRZCU_1_bufType, COM_PRIVATE_DATA)  RxIpduFRZCU_1;
extern VAR(IpduRZCU_2_bufType, COM_PRIVATE_DATA)  RxIpduRZCU_2;

#if  E0X_DCM == E0X_DCM_FL
extern VAR(IpduRCM_1_bufType, COM_PRIVATE_DATA)  RxIpduRCM_1;
extern VAR(IpduRCM_3_bufType, COM_PRIVATE_DATA)  RxIpduRCM_3;
extern VAR(IpduDRM_1_bufType, COM_PRIVATE_DATA)  RxIpduFLDRM_1;
#elif  E0X_DCM == E0X_DCM_FR
extern VAR(IpduRCM_2_bufType, COM_PRIVATE_DATA)  RxIpduRCM_2;
extern VAR(IpduRCM_4_bufType, COM_PRIVATE_DATA)  RxIpduRCM_4;
extern VAR(IpduDRM_1_bufType, COM_PRIVATE_DATA)  RxIpduFRDRM_1;
#elif  E0X_DCM == E0X_DCM_RL
extern VAR(IpduRCM_1_bufType, COM_PRIVATE_DATA)  RxIpduRCM_1;
extern VAR(IpduRCM_3_bufType, COM_PRIVATE_DATA)  RxIpduRCM_3;
extern VAR(IpduDRM_1_bufType, COM_PRIVATE_DATA)  RxIpduRLDRM_1;
#elif  E0X_DCM == E0X_DCM_RR
extern VAR(IpduRCM_2_bufType, COM_PRIVATE_DATA)  RxIpduRCM_2;
extern VAR(IpduRCM_4_bufType, COM_PRIVATE_DATA)  RxIpduRCM_4;
extern VAR(IpduDRM_1_bufType, COM_PRIVATE_DATA)  RxIpduRRDRM_1;
#else
#error "the define E0X_DCM is error!"
#endif

extern VAR(IpduASU_2_bufType, COM_PRIVATE_DATA)  RxIpduASU_2;
extern VAR(IpduVCC_4_bufType, COM_PRIVATE_DATA)  RxIpduVCC_4;
extern VAR(IpduVCC_5_bufType, COM_PRIVATE_DATA)  RxIpduVCC_5;
extern VAR(IpduVCC_6_bufType, COM_PRIVATE_DATA)  RxIpduVCC_6;
extern VAR(IpduBNCM_1_bufType, COM_PRIVATE_DATA)  RxIpduBNCM_1;
extern VAR(IpduFLZCU_5_bufType, COM_PRIVATE_DATA)  RxIpduFLZCU_5;

#if  E0X_DCM == E0X_DCM_FL 
extern VAR(IpduDCM_1_bufType, COM_PRIVATE_DATA) RxIpduFRDCM_1;
extern VAR(IpduDCM_1_bufType, COM_PRIVATE_DATA)  RxIpduRLDCM_1;
extern VAR(IpduDCM_1_bufType, COM_PRIVATE_DATA) RxIpduRRDCM_1;

#elif  E0X_DCM == E0X_DCM_FR 
extern VAR(IpduDCM_1_bufType, COM_PRIVATE_DATA) RxIpduFLDCM_1;
extern VAR(IpduDCM_1_bufType, COM_PRIVATE_DATA)  RxIpduRLDCM_1;
extern VAR(IpduDCM_1_bufType, COM_PRIVATE_DATA) RxIpduRRDCM_1;

#elif  E0X_DCM == E0X_DCM_RL 
extern VAR(IpduDCM_1_bufType, COM_PRIVATE_DATA) RxIpduFLDCM_1;
extern VAR(IpduDCM_1_bufType, COM_PRIVATE_DATA) RxIpduFRDCM_1;
extern VAR(IpduDCM_1_bufType, COM_PRIVATE_DATA) RxIpduRRDCM_1;

#elif  E0X_DCM == E0X_DCM_RR 
extern VAR(IpduDCM_1_bufType, COM_PRIVATE_DATA) RxIpduFLDCM_1;
extern VAR(IpduDCM_1_bufType, COM_PRIVATE_DATA) RxIpduFRDCM_1;
extern VAR(IpduDCM_1_bufType, COM_PRIVATE_DATA)  RxIpduRLDCM_1;

#else
#error "the define E0X_DCM is error!"
#endif 
extern VAR(IpduVCC_1_bufType, COM_PRIVATE_DATA) RxIpduVCC_1;
extern VAR(IpduVCC_2_bufType, COM_PRIVATE_DATA) RxIpduVCC_2;
extern VAR(IpduRLCR_1_bufType, COM_PRIVATE_DATA) RxIpduRLCR_1;
extern VAR(IpduRLCR_2_bufType, COM_PRIVATE_DATA) RxIpduRLCR_2;
extern VAR(IpduICC_BD_11_bufType, COM_PRIVATE_DATA) RxIpduICC_BD_11;
extern VAR(IpduONEBOX_1_G_bufType, COM_PRIVATE_DATA) RxIpduONEBOX_1_G;
extern VAR(IpduRZCU_1_bufType, COM_PRIVATE_DATA) RxIpduRZCU_1;
extern VAR(IpduBNCM_15_bufType, COM_PRIVATE_DATA) RxIpduBNCM_15;
extern VAR(IpduTMS_1_bufType, COM_PRIVATE_DATA) RxIpduTMS_1;
extern VAR(IpduACU_1_bufType, COM_PRIVATE_DATA) RxIpduACU_1;
extern VAR(IpduFLZCU_9_bufType, COM_PRIVATE_DATA) RxIpduFLZCU_9;
extern VAR(IpduBNCM_6_bufType, COM_PRIVATE_DATA) RxIpduBNCM_6;
extern VAR(IpduVCU_1_G_bufType, COM_PRIVATE_DATA)  RxIpduVCU_1_G;

extern VAR(IpduVCU_2_G_bufType, COM_PRIVATE_DATA) RxIpduVCU_2_G;
extern VAR(IpduASU_1_bufType, COM_PRIVATE_DATA) RxIpduASU_1;
extern VAR(IpduICC_COM_1_bufType, COM_PRIVATE_DATA) RxIpduICC_COM_1;
extern VAR(IpduRRCR_1_bufType, COM_PRIVATE_DATA) RxIpduRRCR_1;
extern VAR(IpduPEPS_3_bufType, COM_PRIVATE_DATA) RxIpduPEPS_3;
extern VAR(IpduICC_COM_16_bufType, COM_PRIVATE_DATA)  RxIpduICC_COM_16;
extern VAR(IpduICC_COM_8_bufType, COM_PRIVATE_DATA)  RxIpduICC_COM_8;

#define COM_STOP_SEC_VAR_UNSPECIFIED  
//#include "MemMap.h"
/******************************************************************************
*    Databuffer for Receive Message default Value                               
******************************************************************************/
#define COM_START_SEC_CONFIG_DATA_UNSPECIFIED
//#include "MemMap.h"
extern CONST(IpduACU_3_bufType, COM_PRIVATE_DATA)  RxIpduACU_3DefaultValue;
extern CONST(IpduACU_2_bufType, COM_PRIVATE_DATA)  RxIpduACU_2DefaultValue;

extern CONST(IpduFLZCU_1_bufType, COM_PRIVATE_DATA)  RxIpduFLZCU_1DefaultValue;
extern CONST(IpduFRZCU_2_bufType, COM_PRIVATE_DATA)  RxIpduFRZCU_2DefaultValue;
extern CONST(IpduBNCM_14_bufType, COM_PRIVATE_DATA)  RxIpduBNCM_14DefaultValue;
extern CONST(IpduFRZCU_1_bufType, COM_PRIVATE_DATA)  RxIpduFRZCU_1DefaultValue;
extern CONST(IpduRZCU_2_bufType, COM_PRIVATE_DATA)  RxIpduRZCU_2DefaultValue;

#if  E0X_DCM == E0X_DCM_FL
extern CONST(IpduRCM_1_bufType, COM_PRIVATE_DATA)  RxIpduRCM_1DefaultValue;
extern CONST(IpduRCM_3_bufType, COM_PRIVATE_DATA)  RxIpduRCM_3DefaultValue;
extern CONST(IpduDRM_1_bufType, COM_PRIVATE_DATA)  RxIpduFLDRM_1DefaultValue;
#elif  E0X_DCM == E0X_DCM_FR
extern CONST(IpduRCM_2_bufType, COM_PRIVATE_DATA)  RxIpduRCM_2DefaultValue;
extern CONST(IpduRCM_4_bufType, COM_PRIVATE_DATA)  RxIpduRCM_4DefaultValue;
extern CONST(IpduDRM_1_bufType, COM_PRIVATE_DATA)  RxIpduFRDRM_1DefaultValue;
#elif  E0X_DCM == E0X_DCM_RL
extern CONST(IpduRCM_1_bufType, COM_PRIVATE_DATA)  RxIpduRCM_1DefaultValue;
extern CONST(IpduRCM_3_bufType, COM_PRIVATE_DATA)  RxIpduRCM_3DefaultValue;
extern CONST(IpduDRM_1_bufType, COM_PRIVATE_DATA)  RxIpduRLDRM_1DefaultValue;
#elif  E0X_DCM == E0X_DCM_RR
extern CONST(IpduRCM_2_bufType, COM_PRIVATE_DATA)  RxIpduRCM_2DefaultValue;
extern CONST(IpduRCM_4_bufType, COM_PRIVATE_DATA)  RxIpduRCM_4DefaultValue;
extern CONST(IpduDRM_1_bufType, COM_PRIVATE_DATA)  RxIpduRRDRM_1DefaultValue;
#else
#error "the define E0X_DCM is error!"
#endif

extern CONST(IpduBNCM_1_bufType, COM_PRIVATE_DATA)  RxIpduBNCM_1DefaultValue;
extern CONST(IpduASU_2_bufType, COM_PRIVATE_DATA)  RxIpduASU_2DefaultValue;
extern CONST(IpduVCC_4_bufType, COM_PRIVATE_DATA)  RxIpduVCC_4DefaultValue;
extern CONST(IpduVCC_5_bufType, COM_PRIVATE_DATA)  RxIpduVCC_5DefaultValue;
extern CONST(IpduVCC_6_bufType, COM_PRIVATE_DATA)  RxIpduVCC_6DefaultValue;
extern CONST(IpduFLZCU_5_bufType, COM_PRIVATE_DATA)  RxIpduFLZCU_5DefaultValue;

#if  E0X_DCM == E0X_DCM_FL 
extern CONST(IpduDCM_1_bufType, COM_PRIVATE_DATA) RxIpduFRDCM_1DefaultValue;
extern CONST(IpduDCM_1_bufType, COM_PRIVATE_DATA)  RxIpduRLDCM_1DefaultValue;
extern CONST(IpduDCM_1_bufType, COM_PRIVATE_DATA) RxIpduRRDCM_1DefaultValue;

#elif  E0X_DCM == E0X_DCM_FR 
extern CONST(IpduDCM_1_bufType, COM_PRIVATE_DATA) RxIpduFLDCM_1DefaultValue;
extern CONST(IpduDCM_1_bufType, COM_PRIVATE_DATA)  RxIpduRLDCM_1DefaultValue;
extern CONST(IpduDCM_1_bufType, COM_PRIVATE_DATA) RxIpduRRDCM_1DefaultValue;

#elif  E0X_DCM == E0X_DCM_RL 
extern CONST(IpduDCM_1_bufType, COM_PRIVATE_DATA) RxIpduFLDCM_1DefaultValue;
extern CONST(IpduDCM_1_bufType, COM_PRIVATE_DATA) RxIpduFRDCM_1DefaultValue;
extern CONST(IpduDCM_1_bufType, COM_PRIVATE_DATA) RxIpduRRDCM_1DefaultValue;

#elif  E0X_DCM == E0X_DCM_RR 
extern CONST(IpduDCM_1_bufType, COM_PRIVATE_DATA) RxIpduFLDCM_1DefaultValue;
extern CONST(IpduDCM_1_bufType, COM_PRIVATE_DATA) RxIpduFRDCM_1DefaultValue;
extern CONST(IpduDCM_1_bufType, COM_PRIVATE_DATA)  RxIpduRLDCM_1DefaultValue;

#else
#error "the define E0X_DCM is error!"
#endif 

extern CONST(IpduVCC_1_bufType, COM_PRIVATE_DATA) RxIpduVCC_1DefaultValue;
extern CONST(IpduVCC_2_bufType, COM_PRIVATE_DATA) RxIpduVCC_2DefaultValue;
extern CONST(IpduRLCR_1_bufType, COM_PRIVATE_DATA) RxIpduRLCR_1DefaultValue;
extern CONST(IpduRLCR_2_bufType, COM_PRIVATE_DATA) RxIpduRLCR_2DefaultValue;
extern CONST(IpduICC_BD_11_bufType, COM_PRIVATE_DATA) RxIpduICC_BD_11DefaultValue;
extern CONST(IpduONEBOX_1_G_bufType, COM_PRIVATE_DATA) RxIpduONEBOX_1_GDefaultValue;
extern CONST(IpduRZCU_1_bufType, COM_PRIVATE_DATA) RxIpduRZCU_1DefaultValue;
extern CONST(IpduBNCM_15_bufType, COM_PRIVATE_DATA) RxIpduBNCM_15DefaultValue;
extern CONST(IpduTMS_1_bufType, COM_PRIVATE_DATA) RxIpduTMS_1DefaultValue;
extern CONST(IpduACU_1_bufType, COM_PRIVATE_DATA) RxIpduACU_1DefaultValue;
extern CONST(IpduFLZCU_9_bufType, COM_PRIVATE_DATA) RxIpduFLZCU_9DefaultValue;
extern CONST(IpduBNCM_6_bufType, COM_PRIVATE_DATA) RxIpduBNCM_6DefaultValue;
extern CONST(IpduVCU_1_G_bufType, COM_PRIVATE_DATA)  RxIpduVCU_1_GDefaultValue;

extern CONST(IpduVCU_2_G_bufType, COM_PRIVATE_DATA) RxIpduVCU_2_GDefaultValue;
extern CONST(IpduASU_1_bufType, COM_PRIVATE_DATA) RxIpduASU_1DefaultValue;
extern CONST(IpduICC_COM_1_bufType, COM_PRIVATE_DATA) RxIpduICC_COM_1DefaultValue;
extern CONST(IpduRRCR_1_bufType, COM_PRIVATE_DATA) RxIpduRRCR_1DefaultValue;
extern CONST(IpduPEPS_3_bufType, COM_PRIVATE_DATA) RxIpduPEPS_3DefaultValue;
extern CONST(IpduICC_COM_16_bufType, COM_PRIVATE_DATA)  RxIpduICC_COM_16DefaultValue;
extern CONST(IpduICC_COM_8_bufType, COM_PRIVATE_DATA)  RxIpduICC_COM_8DefaultValue;


#define COM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
//#include "MemMap.h"

#if (COM_RXIPDUNUM >= 1u)

/******************************************************************************
*    rx Ipdu timeout indication function Declare                               
******************************************************************************/
#ifdef COM_ENABLE_RXTOINDFUN 

extern void AppIpduACU_3_TimeOutInd(void);
extern void AppIpduACU_2_TimeOutInd(void);

extern void AppIpduFLZCU_1_TimeOutInd(void);
extern void AppIpduFRZCU_2_TimeOutInd(void);
extern void AppIpduBNCM_14_TimeOutInd(void);
extern void AppIpduFRZCU_1_TimeOutInd(void);
extern void AppIpduRZCU_2_TimeOutInd(void);

#if  E0X_DCM == E0X_DCM_FL
extern void AppIpduRCM_1_TimeOutInd(void);
extern void AppIpduRCM_3_TimeOutInd(void);
extern void AppIpduFLDRM_1_TimeOutInd(void);
#elif  E0X_DCM == E0X_DCM_FR
extern void AppIpduRCM_2_TimeOutInd(void);
extern void AppIpduRCM_4_TimeOutInd(void);
extern void AppIpduFRDRM_1_TimeOutInd(void);
#elif  E0X_DCM == E0X_DCM_RL
extern void AppIpduRCM_1_TimeOutInd(void);
extern void AppIpduRCM_3_TimeOutInd(void);
extern void AppIpduRLDRM_1_TimeOutInd(void);
#elif  E0X_DCM == E0X_DCM_RR
extern void AppIpduRCM_2_TimeOutInd(void);
extern void AppIpduRCM_4_TimeOutInd(void);
extern void AppIpduRRDRM_1_TimeOutInd(void);
#else
#error "the define E0X_DCM is error!"
#endif

extern void AppIpduBNCM_1_TimeOutInd(void);
extern void AppIpduASU_2_TimeOutInd(void);
extern void AppIpduVCC_4_TimeOutInd(void);
extern void AppIpduVCC_5_TimeOutInd(void);
extern void AppIpduVCC_6_TimeOutInd(void);
extern void AppIpduFLZCU_5_TimeOutInd(void);

#if  E0X_DCM == E0X_DCM_FL 
extern void AppIpduFRDCM_1_TimeOutInd(void);
extern void AppIpduRLDCM_1_TimeOutInd(void);
extern void AppIpduRRDCM_1_TimeOutInd(void);

#elif  E0X_DCM == E0X_DCM_FR 
extern void AppIpduFLDCM_1_TimeOutInd(void);
extern void AppIpduRLDCM_1_TimeOutInd(void);
extern void AppIpduRRDCM_1_TimeOutInd(void);

#elif  E0X_DCM == E0X_DCM_RL 
extern void AppIpduFLDCM_1_TimeOutInd(void);
extern void AppIpduFRDCM_1_TimeOutInd(void);
extern void AppIpduRRDCM_1_TimeOutInd(void);

#elif  E0X_DCM == E0X_DCM_RR 
extern void AppIpduFLDCM_1_TimeOutInd(void);
extern void AppIpduFRDCM_1_TimeOutInd(void);
extern void AppIpduRLDCM_1_TimeOutInd(void);

#else
#error "the define E0X_DCM is error!"
#endif 

extern void AppIpduVCC_1_TimeOutInd(void);
extern void AppIpduVCC_2_TimeOutInd(void);
extern void AppIpduRLCR_1_TimeOutInd(void);
extern void AppIpduRLCR_2_TimeOutInd(void);
extern void AppIpduICC_BD_11_TimeOutInd(void);
extern void AppIpduONEBOX_1_G_TimeOutInd(void);
extern void AppIpduRZCU_1_TimeOutInd(void);
extern void AppIpduBNCM_15_TimeOutInd(void);
extern void AppIpduTMS_1_TimeOutInd(void);
extern void AppIpduACU_1_TimeOutInd(void);
extern void AppIpduFLZCU_9_TimeOutInd(void);
extern void AppIpduBNCM_6_TimeOutInd(void);
extern void AppIpduVCU_1_G_TimeOutInd(void);

extern void AppIpduVCU_2_G_TimeOutInd(void);
extern void AppIpduASU_1_TimeOutInd(void);
extern void AppIpduICC_COM_1_TimeOutInd(void);
extern void AppIpduRRCR_1_TimeOutInd(void);
extern void AppIpduPEPS_3_TimeOutInd(void);
extern void AppIpduICC_COM_16_TimeOutInd(void);
extern void AppIpduICC_COM_8_TimeOutInd(void);

#endif

/******************************************************************************
*    Rx indication function Declare                                            
******************************************************************************/
#ifdef COM_ENABLE_RXINDICATIONFUN 
extern void AppIpduACU_3_Ind(void);
extern void AppIpduACU_2_Ind(void);


extern void AppIpduFLZCU_1_Ind(void);
extern void AppIpduFRZCU_2_Ind(void);
extern void AppIpduBNCM_14_Ind(void);
extern void AppIpduFRZCU_1_Ind(void);
extern void AppIpduRZCU_2_Ind(void);

#if  E0X_DCM == E0X_DCM_FL
extern void AppIpduRCM_1_Ind(void);
extern void AppIpduRCM_3_Ind(void);
extern void AppIpduFLDRM_1_Ind(void);
#elif  E0X_DCM == E0X_DCM_FR
extern void AppIpduRCM_2_Ind(void);
extern void AppIpduRCM_4_Ind(void);
extern void AppIpduFRDRM_1_Ind(void);
#elif  E0X_DCM == E0X_DCM_RL
extern void AppIpduRCM_1_Ind(void);
extern void AppIpduRCM_3_Ind(void);
extern void AppIpduRLDRM_1_Ind(void);
#elif  E0X_DCM == E0X_DCM_RR
extern void AppIpduRCM_2_Ind(void);
extern void AppIpduRCM_4_Ind(void);
extern void AppIpduRRDRM_1_Ind(void);
#else
#error "the define E0X_DCM is error!"
#endif

extern void AppIpduBNCM_1_Ind(void);
extern void AppIpduASU_2_Ind(void);
extern void AppIpduVCC_4_Ind(void);
extern void AppIpduVCC_5_Ind(void);
extern void AppIpduVCC_6_Ind(void);
extern void AppIpduFLZCU_5_Ind(void);

#if  E0X_DCM == E0X_DCM_FL 
extern void AppIpduFRDCM_1_Ind(void);
extern void AppIpduRLDCM_1_Ind(void);
extern void AppIpduRRDCM_1_Ind(void);

#elif  E0X_DCM == E0X_DCM_FR 
extern void AppIpduFLDCM_1_Ind(void);
extern void AppIpduRLDCM_1_Ind(void);
extern void AppIpduRRDCM_1_Ind(void);

#elif  E0X_DCM == E0X_DCM_RL 
extern void AppIpduFLDCM_1_Ind(void);
extern void AppIpduFRDCM_1_Ind(void);
extern void AppIpduRRDCM_1_Ind(void);

#elif  E0X_DCM == E0X_DCM_RR 
extern void AppIpduFLDCM_1_Ind(void);
extern void AppIpduFRDCM_1_Ind(void);
extern void AppIpduRLDCM_1_Ind(void);

#else
#error "the define E0X_DCM is error!"
#endif 

extern void AppIpduVCC_1_Ind(void);
extern void AppIpduVCC_2_Ind(void);
extern void AppIpduRLCR_1_Ind(void);
extern void AppIpduRLCR_2_Ind(void);
extern void AppIpduICC_BD_11_Ind(void);
extern void AppIpduONEBOX_1_G_Ind(void);
extern void AppIpduRZCU_1_Ind(void);
extern void AppIpduBNCM_15_Ind(void);
extern void AppIpduTMS_1_Ind(void);
extern void AppIpduACU_1_Ind(void);
extern void AppIpduFLZCU_9_Ind(void);
extern void AppIpduBNCM_6_Ind(void);
extern void AppIpduVCU_1_G_Ind(void);

extern void AppIpduVCU_2_G_Ind(void);
extern void AppIpduASU_1_Ind(void);
extern void AppIpduICC_COM_1_Ind(void);
extern void AppIpduRRCR_1_Ind(void);
extern void AppIpduPEPS_3_Ind(void);
extern void AppIpduICC_COM_16_Ind(void);
extern void AppIpduICC_COM_8_Ind(void);

#endif
#endif /*#if (COM_RXIPDUNUM>=1)*/ 

/******************************************************************************
*    Signal Gateway                                                            
******************************************************************************/
#ifdef COM_ENABLE_ROUTESIGNAL
#define COM_GWIPDUNUM    (0U)
#define COM_GWSIGNUM     (0U)
#endif

/******************************************************************************
*    Ipdu Group                                                                
******************************************************************************/
#if((COM_TXIPDUNUM >= 1u) || (COM_RXIPDUNUM >= 1u))
#define COM_IPDUGROUPNUM    (2U)
#define COM_IPDUGROUP0    (0x3U)
#define COM_IPDUGROUP1    (0x39U)
#define COM_GROUPIPDUNUM    (42U)
#endif

/******************************************************************************
*    data declaration                                                          
******************************************************************************/
extern void Com_TxIpduCallout(PduIdType PduId, uint8 *DataPtr);
extern void Com_RxIpduCallout(PduIdType PduId, uint8 *DataPtr);

#if(COM_TXIPDUNUM >= 1u)
#define COM_START_SEC_VAR_UNSPECIFIED  
//#include "MemMap.h"

extern VAR(PduInfoType, COM_APPL_DATA) Com_TxIpdu[COM_TXIPDUNUM];

#define COM_STOP_SEC_VAR_UNSPECIFIED  
//#include "MemMap.h"

#define COM_START_SEC_CONFIG_DATA_UNSPECIFIED  
//#include "MemMap.h"

extern CONST(PduInfoType, COM_CONFIG_CONST)  Com_TxIpduInitTable[COM_TXIPDUNUM]; 
extern CONST(Com_TxSigTableType, COM_CONFIG_CONST)  Com_TxSigTable[COM_TXSIGNUM];
extern CONSTP2CONST(uint8,COM_CONFIG_CONST,COM_CONFIG_CONST) Com_TxIpduDefaultValue[COM_TXIPDUNUM];

#ifdef COM_ENABLE_TXCONFIRMATIONFUN
extern CONST(Com_TxConfirmationType, COM_CONFIG_CONST)  Com_TxIpduConfirmTable[COM_TXIPDUNUM];
#endif

#ifdef COM_ENABLE_TXTOINDFUN
extern CONST(Com_TOIndicationType, COM_CONFIG_CONST)  Com_TxIpduTOIndicationTable[COM_TXIPDUNUM];
#endif

#ifdef COM_ENABLE_LPDUTXERRINDFUN
extern CONST(Com_ErrIndicationType, COM_CONFIG_CONST)  Com_LpduTxErrIndicationTable[COM_TXIPDUNUM];
#endif

extern CONST(uint8, COM_CONFIG_CONST)  Com_TxIpduTable[COM_TXIPDUNUM];

#ifndef COM_ENABLE_NONSENDTYPEONLY

#ifdef COM_ENABLE_ACTIVEPORPERTY 
extern CONST(uint16, COM_CONFIG_CONST) Com_TxIpduFastCycleTable[COM_TXIPDUNUM];
extern CONST(uint8, COM_CONFIG_CONST) Com_TxIpduSigNum[COM_TXIPDUNUM];

extern FUNC(void, COM_PUBLIC_CODE) Com_ActiveSig
(
    Com_SignalIdType SignalId
);

extern FUNC(void, COM_PUBLIC_CODE) Com_DisactiveSig
(
    Com_SignalIdType SignalId
);

extern CONST(Com_SignalIdType, COM_CONFIG_CONST)  Com_TxSigOffsetTable[COM_TXIPDUNUM];

#endif

extern CONST(uint16, COM_CONFIG_CONST) Com_TxIpduTdelayTable[COM_TXIPDUNUM];
extern CONST(uint8, COM_CONFIG_CONST) Com_TxIpduRepNumTable[COM_TXIPDUNUM];
#endif /*#ifndef COM_ENABLE_NONSENDTYPEONLY*/

extern CONST(uint16, COM_CONFIG_CONST) Com_TxIpduCycleTable[COM_TXIPDUNUM]; 
extern CONST(uint16, COM_CONFIG_CONST) Com_TxIpduTimeOutTable[COM_TXIPDUNUM]; 
extern CONST(uint16, COM_CONFIG_CONST) Com_TxIpduOffsetTable[COM_TXIPDUNUM];

#define COM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
//#include "MemMap.h"

#endif /*#if(COM_TXIPDUNUM>=1)*/

#if(COM_RXIPDUNUM >= 1u)

#ifdef COM_ENABLE_RXEXTEND
extern CONST(uint8, COM_CONFIG_CONST) Com_RxIpduSigNum[COM_RXIPDUNUM];
extern CONST(Com_SignalIdType, COM_CONFIG_CONST) Com_RxSigOffsetTable[COM_RXIPDUNUM];
#endif

extern CONST(PduInfoType, COM_CONFIG_CONST) Com_RxIpduInitTable[COM_RXIPDUNUM];
extern CONST(Com_RxSigTableType, COM_CONFIG_CONST) Com_RxSigTable[COM_RXSIGNUM];
extern CONST(Com_RxIpduTableType, COM_CONFIG_CONST) Com_RxIpduTable[COM_RXIPDUNUM];
extern CONSTP2CONST(uint8,COM_CONFIG_CONST,COM_CONFIG_CONST) Com_RxIpduDefaultValue[COM_RXIPDUNUM];

#ifdef COM_ENABLE_RXINDICATIONFUN
extern CONST(Com_RxIndicationType, COM_CONFIG_CONST) Com_RxIpduIndicationTable[COM_RXIPDUNUM]; 
#endif

#ifdef COM_ENABLE_RXTOINDFUN 
extern CONST(Com_TOIndicationType, COM_CONFIG_CONST) Com_RxIpduTOIndicationTable[COM_RXIPDUNUM];
#endif

#ifdef COM_ENABLE_LPDURXERRINDFUN
extern CONST(Com_ErrIndicationType, COM_CONFIG_CONST) Com_LpduRxErrIndicationTable[COM_RXIPDUNUM];
#endif

#ifdef COM_ENABLE_LPDURXSTARTINDIFUN
extern CONST(Com_LpduRxStartIndicationType, COM_CONFIG_CONST)  
             Com_LpduRxStartIndicationTable[COM_RXIPDUNUM];
#endif

#ifdef COM_ENABLE_RXTIMEOUTVALUE
extern  CONSTP2CONST(uint8,COM_CONFIG_CONST,COM_CONFIG_CONST) Com_RxIpduTimeoutValue[COM_RXIPDUNUM];
#endif

extern CONST(PduLengthType, COM_CONFIG_CONST)  Com_RxIpduBufferSize[COM_RXIPDUNUM];


#endif /*#if(COM_RXIPDUNUM>=1)*/


#if(COM_TXIPDUNUM >= 1u)
extern CONST(Com_SendSignalType, COM_CONFIG_CONST)  Com_SendSignalTable[COM_TXSIGNUM];
#endif


#if(COM_RXIPDUNUM >= 1u)
extern  CONST(Com_ReceiveSignalType, COM_CONFIG_CONST)   Com_ReceiveSignalTable[COM_RXSIGNUM];
#endif

#ifdef COM_ENABLE_ROUTESIGNAL
#if(COM_GWSIGNUM >= 1u)
extern CONST(Com_SignalGatewayIpduTableType, COM_CONFIG_CONST)  
             Com_SignalGatewayIpduTable[COM_GWIPDUNUM];
             
extern CONST(Com_SignalGatewayTableType, COM_CONFIG_CONST)  Com_SignalGatewayTable[COM_GWSIGNUM];
#endif /*#if(COM_GWSIGNUM>=1)*/
#endif /*#ifdef COM_ENABLE_ROUTESIGNAL*/


#if(COM_IPDUGROUPNUM >= 1u)
extern CONST(Com_GroupIpduTableType, COM_CONFIG_CONST)  Com_GroupIpduTable[COM_GROUPIPDUNUM];
extern CONST(Com_IpduGroupTableType, COM_CONFIG_CONST)  Com_IpduGroupTable[COM_IPDUGROUPNUM];
#endif

#if(COM_TXIPDUNUM >= 1u)
extern CONST(PduIdType, COM_CONFIG_CONST) Com_TxIpduIdMapTable[COM_TXIPDUNUM];
#define Com_TransmitLPDU(ComTxPduId,PduInfoPtr)     CanIf_Transmit(Com_TxIpduIdMapTable[ComTxPduId],PduInfoPtr) 
#define Com_Transmit(ComTxPduId,PduInfoPtr)            CanIf_Transmit(Com_TxIpduIdMapTable[ComTxPduId],PduInfoPtr)
#endif

#endif



