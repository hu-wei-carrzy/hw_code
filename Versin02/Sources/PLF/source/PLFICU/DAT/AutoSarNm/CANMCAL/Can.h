/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Can.h                                                       */
/* Version      = V1.0.2                                                      */
/* Date         = 03-Jun-2021                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* (c) 2019-2021 Renesas Electronics Corporation. All rights reserved.        */
/*============================================================================*/
/* Purpose:                                                                   */
/* Provision of external declaration of APIs and Service IDs.                 */
/*                                                                            */
/*============================================================================*/
/*                                                                            */
/* Unless otherwise agreed upon in writing between your company and           */
/* Renesas Electronics Corporation the following shall apply!                 */
/*                                                                            */
/* Warranty Disclaimer                                                        */
/*                                                                            */
/* There is no warranty of any kind whatsoever granted by Renesas. Any        */
/* warranty is expressly disclaimed and excluded by Renesas, either expressed */
/* or implied, including but not limited to those for non-infringement of     */
/* intellectual property, merchantability and/or fitness for the particular   */
/* purpose.                                                                   */
/*                                                                            */
/* Renesas shall not have any obligation to maintain, service or provide bug  */
/* fixes for the supplied Product(s) and/or the Application.                  */
/*                                                                            */
/* Each User is solely responsible for determining the appropriateness of     */
/* using the Product(s) and assumes all risks associated with its exercise    */
/* of rights under this Agreement, including, but not limited to the risks    */
/* and costs of program errors, compliance with applicable laws, damage to    */
/* or loss of data, programs or equipment, and unavailability or              */
/* interruption of operations.                                                */
/*                                                                            */
/* Limitation of Liability                                                    */
/*                                                                            */
/* In no event shall Renesas be liable to the User for any incidental,        */
/* consequential, indirect, or punitive damage (including but not limited     */
/* to lost profits) regardless of whether such liability is based on breach   */
/* of contract, tort, strict liability, breach of warranties, failure of      */
/* essential purpose or otherwise and even if advised of the possibility of   */
/* such damages. Renesas shall not be liable for any services or products     */
/* provided by third party vendors, developers or consultants identified or   */
/* referred to the User by Renesas in connection with the Product(s) and/or   */
/* the Application.                                                           */
/*                                                                            */
/*============================================================================*/
/* Environment:                                                               */
/*              Devices:        X1x                                           */
/*============================================================================*/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V1.0.0:  31-May-2019  : Initial version
 * V1.0.1:  25-Sep-2020  : Update patch version to 1U.
 * V1.0.2:  19-Mar-2021  : As per ARDAABD-3191, Add comment for some structure
 *                         missing in Source comment.
 *          24-Mar-2021  : Update patch version to 2U.
 *          25-Mar-2021  : As per ARDAABD-5506, Change type of BaudRateConfigID
 *                         parameter in Can_SetBaudrate() API to uint16.
 *          03-Apr-2021  : Update QAC 931, MISRA-C Rule Violation.
 *          03-Jun-2021  : Added QAC Warning messages.
 */
/******************************************************************************/

#ifndef CAN_H
#define CAN_H

/*******************************************************************************
**      To support different AUTOSAR releases in a single package             **
*******************************************************************************/
#define CAN_AR_FOUR_ZERO_THREE    403
#define CAN_AR_FOUR_TWO_TWO       422

#define CAN_AR_403_VERSION     CAN_AR_FOUR_ZERO_THREE
#define CAN_AR_422_VERSION     CAN_AR_FOUR_TWO_TWO

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Can_Cfg.h"
/* CAN Driver GeneralTypes Header File */
//#include "Can_GeneralTypes.h"
/* Type definition header file */
#include "ComStack_Types.h"
#include "../../LAP/LAP_CPULOAD/Include/Basedef_cfg.h"
#include "Can_Type.h"


/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

#define CAN_VENDOR_ID              CAN_VENDOR_ID_VALUE
#define CAN_MODULE_ID              CAN_MODULE_ID_VALUE
#define CAN_INSTANCE_ID            CAN_INSTANCE_ID_VALUE


#if (CAN_AR_VERSION == CAN_AR_422_VERSION)
/* AUTOSAR release version information */
#define CAN_AR_RELEASE_MAJOR_VERSION     4U
#define CAN_AR_RELEASE_MINOR_VERSION     2U
#define CAN_AR_RELEASE_REVISION_VERSION  2U
#else
/* AUTOSAR release version information */
#define CAN_AR_RELEASE_MAJOR_VERSION     4U
#define CAN_AR_RELEASE_MINOR_VERSION     0U
#define CAN_AR_RELEASE_REVISION_VERSION  3U
#endif

/* Module Software version information */
#define CAN_SW_MAJOR_VERSION    1U
#define CAN_SW_MINOR_VERSION    0U
#define CAN_SW_PATCH_VERSION    2U

#define CAN_DATA_DLC     ((uint8)0x08U)
/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/

/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (2:3684) Array declared with unknown size.                 */
/* Rule          : MISRA-C:2004 Rule 8.12                                     */
/* Justification : Arrays used are verified in the file which are only        */
/*                 declarations and size is configuration dependent.          */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:3684)-1 and                           */
/*                 END Msg(2:3684)-1 tags in the code.                        */
/******************************************************************************/
/*******************************************************************************
**                                QAC Warning                                 **
*******************************************************************************/

/* 1. QAC warning:                                                            */
/* Message       : (2:0832) Macro substitution in #include preprocessing      */
/*                 directive.                                                 */
/* Rule          : No MISRA-C:2004 Rules applicable to message 0832           */
/* Justification : The included file name is necessary to be defined as macro */
/*                 to support multiple configration of Autosar version which  */
/*                 have different requirement for Memmap file name. In        */
/*                 additional, JB0019 coding guideline do not restrict        */
/*                 this usage of macro.                                       */
/* Verification  : This is quite legitimate in C. It is necessary for macro   */
/*                 substitution and it is not having any impact.              */
/* Reference     : Look for START Msg(2:0832)-1 and                           */
/*                 END Msg(2:0832)-1 tags in the code.                        */
/******************************************************************************/
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/*******************************************************************************
**                        Service IDs                                         **
*******************************************************************************/
/* Service ID for Can_Init */
#define CAN_INIT_SID                          (uint8)0x00
/* Service ID for Can_MainFunction_Write */
#define CAN_MAIN_WRITE_SID                    (uint8)0x01
/* Service ID for Can_SetControllerMode */
#define CAN_SET_MODECNTRL_SID                 (uint8)0x03
/* Service ID for Can_DisableControllerInterupts */
#define CAN_DISABLE_CNTRL_INT_SID             (uint8)0x04
/* Service ID for Can_EnableControllerInterupts */
#define CAN_ENABLE_CNTRL_INT_SID              (uint8)0x05
/* Service ID for Can_Write */
#define CAN_WRITE_SID                         (uint8)0x06
/* Service ID for Can_GetVersionInfo */
#define CAN_GET_VERSIONINFO_SID               (uint8)0x07
/* Service ID for Can_MainFunction_Read */
#define CAN_MAIN_READ_SID                     (uint8)0x08
/* Service ID for Can_MainFunction_BusOff */
#define CAN_MAIN_BUSOFF_SID                   (uint8)0x09
/* Service ID for Can_MainFunction_Wakeup */
#define CAN_MAIN_WAKEUP_SID                   (uint8)0x0A
/* Service ID for Can_CheckWakeup */
#define CAN_CHECK_WAKEUP_SID                  (uint8)0x0B
/* Service ID for Can_MainFunction_Mode */
#define CAN_MAIN_MODE_SID                     (uint8)0x0C
/*Service ID for Can_ChangeBaudrate */
#define CAN_CHANGE_BAUDRATE_SID               (uint8)0x0D
/*Service ID for Can_CheckBaudrate */
#define CAN_CHECK_BAUDRATE_SID                (uint8)0x0E
/* Service ID for Can_SetBaudrate */
#define CAN_SET_BAUDRATE_SID                  (uint8)0x0F
/* Service ID for Can_RxProcessing */
#define CAN_RXPROCESSING_SID                  (uint8)0x10
/* Service Id of Can_CheckHWConsistency */
#define CAN_CHECK_HW_CONSISTENCY_SID          (uint8)0x11
/* Service ID for Can_RAMTest */
#define CAN_RAMTEST_SID                       (uint8)0x14
/* Service ID for Can_SelfTestChannel */
#define CAN_SELFTESTCHANNEL_SID               (uint8)0x15

/* DET ERRORS */
/* API service called with null Pointer */
#define CAN_E_PARAM_POINTER                   (uint8)0x01
/* API service called with wrong Handle */
#define CAN_E_PARAM_HANDLE                    (uint8)0x02
/* API service called with wrong DLC */
#define CAN_E_PARAM_DLC                       (uint8)0x03
/* API service called with wrong Controller Id */
#define CAN_E_PARAM_CONTROLLER                (uint8)0x04
/* API service called with de-initialization */
#define CAN_E_UNINIT                          (uint8)0x05
/* API service called with wrong Transition */
#define CAN_E_TRANSITION                      (uint8)0x06
/* Received CAN Message is lost */
#define CAN_E_DATALOST                        (uint8)0x07
/* API service called with invalid baudrate value */
#define CAN_E_PARAM_BAUDRATE                  (uint8)0x08
/* API service called with invalid ICOM configuration Id */
#define CAN_E_ICOM_CONFIG_INVALID             (uint8)0x09
/* API service called with invalid configuration set */
#define CAN_E_INIT_FAILED                     (uint8)0x0A
/* API service called with wrong database address */
#define CAN_E_INVALID_DATABASE                (uint8)0xEF
/* Instance ID Value of CAN driver*/
#define CAN_INSTANCE_ID_VALUE                 (uint8)0x00
/* API service called with BlockId is out of range */
#define CAN_RAMTEST_E_OUT_OF_RANGE            (uint8)0x0B
/* API service called when RSCAN is not in Global Stop mode */
#define CAN_RAMTEST_E_GLOBAL_STOP             (uint8)0x0C
/* API service called with wrong parameter */
#define CAN_E_PARAM_VALUE                     (uint8)0x0D

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/* CAN Driver Initialization configuration */
typedef struct STag_Can_ConfigType
{
  /* StartOfDbToc */
  uint32 ulStartOfDbToc;
  /* Pointer to HWUnit configuration structures */
  P2CONST(void, TYPEDEF, CAN_RSCAN_CONFIG_DATA) pHWUnitInfo;
  /* Pointer to Controller Pre-compile Configuration structures */
  P2CONST(void, TYPEDEF, CAN_RSCAN_CONFIG_DATA)
    pControllerPCConfig;
  /* Pointer to Controller Post-build Configuration structures */
  P2CONST(void, TYPEDEF, CAN_RSCAN_CONFIG_DATA)
    pControllerPBConfig;
  /* Pointer to HTH/HRH configuration structures */
  P2CONST(void, TYPEDEF, CAN_RSCAN_CONFIG_DATA) pHohConfig;
  /* Pointer to Physical Controller configuration structures */
  P2CONST(void, TYPEDEF, CAN_RSCAN_CONFIG_DATA) pPhysicalControllerToIndex;
} Can_ConfigType;

/* Enum deceleration for Can_SelfTest */
typedef enum ETag_Can_SelfTestType
{
  /* Disable self-test */
  CAN_T_SELF_OFF = 0,
  /* Self-test mode 0 (External loopback mode) */
  CAN_T_SELF_EXTERNAL,
  /* Self-test mode 1 (Internal loopback mode) */
  CAN_T_SELF_INTERNAL
} Can_SelfTestType;

/*******************************************************************************
**                      RAM Mirror Types                                      **
*******************************************************************************/
/* Type definition for Can_HWConsistencyModeType */
typedef enum ETag_Can_HWConsistencyModeType
{
  /* Check HW Consistency in static mode */
  CAN_STATIC = 0,
  /* Check HW Consistency in dynamic mode */
  CAN_DYNAMIC
}Can_HWConsistencyModeType;

/* This structure is used as an backup value for global register */
/* in ram mirror function */
typedef struct STag_Can_MirrorGlobalType
{
  /* Value to check for GCTR */
  uint32 ulGCTR;
} Can_MirrorGlobalType;

/* This structure is used as an backup value for channel register */ 
/* in ram mirror function */
typedef struct STag_Can_MirrorChannelType
{
  /* Value to check for CmCFG */
  uint32 ulCFG;
  /* Value to check for CmCTR */
  uint32 ulCTR;
  /* Value to check for CmFDCFG */
  uint32 ulFDCFG;
  /* Value to check for CmDCFG */
  uint32 ulDCFG;
} Can_MirrorChannelType;

/* This structure is used as an backup value for global register */
/* in ram mirror function */
typedef struct STag_Can_MirrorHohType
{
  /* Value to check for RFCC register */
  uint32 ulRFCC;
  /* Value to check for TXQCC register */
  uint32 ulTXQCC;
  /* Value to check for CFCC register */
  uint32 ulCFCC;
} Can_MirrorHohType;
/*******************************************************************************
**                      Extern declarations for Global Data                   **
*******************************************************************************/
#define CAN_RSCAN_START_SEC_DBTOC_DATA_UNSPECIFIED
/* QAC Warning: START Msg(2:0832)-1 */
//#include CAN_MEMMAP_FILE
/* END Msg(2:0832)-1 */
/* Global array for Config structure */
/* MISRA Violation: START Msg(2:3684)-1 */
extern CONST(Can_ConfigType, CAN_RSCAN_CONST) Can_GaaConfig[];
/* END Msg(2:3684)-1 */

#define CAN_RSCAN_STOP_SEC_DBTOC_DATA_UNSPECIFIED
/* QAC Warning: START Msg(2:0832)-1 */
//#include CAN_MEMMAP_FILE
/* END Msg(2:0832)-1 */

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define CAN_RSCAN_START_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-1 */
//#include CAN_MEMMAP_FILE
/* END Msg(2:0832)-1 */

/* API for global initialization */
extern FUNC(void, CAN_RSCAN_PUBLIC_CODE) Can_Init
(P2CONST(Can_ConfigType, AUTOMATIC, CAN_RSCAN_APPL_CONST) Config);

#if (CAN_CHANGE_BAUDRATE_API == STD_ON)
/* API for changing baudrate of the Controller */
extern FUNC(Std_ReturnType, CAN_RSCAN_PUBLIC_CODE) Can_ChangeBaudrate(
  uint8 Controller, const uint16 Baudrate);

/* API for checking baudrates configured for the Controller */
extern FUNC(Std_ReturnType, CAN_RSCAN_PUBLIC_CODE) Can_CheckBaudrate(
  uint8 Controller, const uint16 Baudrate);
#endif

#if (CAN_SET_BAUDRATE_API == STD_ON)
/* API for changing baudrate of the Controller */
extern FUNC(Std_ReturnType, CAN_RSCAN_PUBLIC_CODE) Can_SetBaudrate(
  uint8 Controller, uint16 BaudRateConfigID);
#endif

/* API for set Controller mode */
extern FUNC(Can_ReturnType, CAN_RSCAN_PUBLIC_CODE) Can_SetControllerMode(
  uint8 Controller, Can_StateTransitionType Transition);

/* API for disabling Controller interrupt */
extern FUNC(void, CAN_RSCAN_PUBLIC_CODE) Can_DisableControllerInterrupts(
  uint8 Controller);

/* API for enabling Controller interrupt */
extern FUNC(void, CAN_RSCAN_PUBLIC_CODE) Can_EnableControllerInterrupts(
  uint8 Controller);

/* API for Can Write */
extern FUNC(Can_ReturnType, CAN_RSCAN_PUBLIC_CODE) Can_Write(
  Can_HwHandleType Hth,
  P2CONST(Can_PduType, AUTOMATIC, CAN_RSCAN_APPL_CONST) PduInfo);

/* API for schedule processing of write */
extern FUNC(void, CAN_RSCAN_PUBLIC_CODE) Can_MainFunction_Write(void);
#if (CAN_NUMBER_OF_MAINFUNCTIONS > 0U)
extern FUNC(void, CAN_RSCAN_PUBLIC_CODE) Can_MainFunction_Write_0(void);
#endif
#if (CAN_NUMBER_OF_MAINFUNCTIONS > 1U)
extern FUNC(void, CAN_RSCAN_PUBLIC_CODE) Can_MainFunction_Write_1(void);
#endif
#if (CAN_NUMBER_OF_MAINFUNCTIONS > 2U)
extern FUNC(void, CAN_RSCAN_PUBLIC_CODE) Can_MainFunction_Write_2(void);
#endif
#if (CAN_NUMBER_OF_MAINFUNCTIONS > 3U)
extern FUNC(void, CAN_RSCAN_PUBLIC_CODE) Can_MainFunction_Write_3(void);
#endif
#if (CAN_NUMBER_OF_MAINFUNCTIONS > 4U)
extern FUNC(void, CAN_RSCAN_PUBLIC_CODE) Can_MainFunction_Write_4(void);
#endif
#if (CAN_NUMBER_OF_MAINFUNCTIONS > 5U)
extern FUNC(void, CAN_RSCAN_PUBLIC_CODE) Can_MainFunction_Write_5(void);
#endif
#if (CAN_NUMBER_OF_MAINFUNCTIONS > 6U)
extern FUNC(void, CAN_RSCAN_PUBLIC_CODE) Can_MainFunction_Write_6(void);
#endif
#if (CAN_NUMBER_OF_MAINFUNCTIONS > 7U)
extern FUNC(void, CAN_RSCAN_PUBLIC_CODE) Can_MainFunction_Write_7(void);
#endif
/* API for schedule processing of read */
extern FUNC(void, CAN_RSCAN_PUBLIC_CODE) Can_MainFunction_Read(void);
#if (CAN_NUMBER_OF_MAINFUNCTIONS > 0U)
extern FUNC(void, CAN_RSCAN_PUBLIC_CODE) Can_MainFunction_Read_0(void);
#endif
#if (CAN_NUMBER_OF_MAINFUNCTIONS > 1U)
extern FUNC(void, CAN_RSCAN_PUBLIC_CODE) Can_MainFunction_Read_1(void);
#endif
#if (CAN_NUMBER_OF_MAINFUNCTIONS > 2U)
extern FUNC(void, CAN_RSCAN_PUBLIC_CODE) Can_MainFunction_Read_2(void);
#endif
#if (CAN_NUMBER_OF_MAINFUNCTIONS > 3U)
extern FUNC(void, CAN_RSCAN_PUBLIC_CODE) Can_MainFunction_Read_3(void);
#endif
#if (CAN_NUMBER_OF_MAINFUNCTIONS > 4U)
extern FUNC(void, CAN_RSCAN_PUBLIC_CODE) Can_MainFunction_Read_4(void);
#endif
#if (CAN_NUMBER_OF_MAINFUNCTIONS > 5U)
extern FUNC(void, CAN_RSCAN_PUBLIC_CODE) Can_MainFunction_Read_5(void);
#endif
#if (CAN_NUMBER_OF_MAINFUNCTIONS > 6U)
extern FUNC(void, CAN_RSCAN_PUBLIC_CODE) Can_MainFunction_Read_6(void);
#endif
#if (CAN_NUMBER_OF_MAINFUNCTIONS > 7U)
extern FUNC(void, CAN_RSCAN_PUBLIC_CODE) Can_MainFunction_Read_7(void);
#endif
/* API for schedule processing of BusOff */
extern FUNC(void, CAN_RSCAN_PUBLIC_CODE) Can_MainFunction_BusOff(void);
/* API for schedule processing of Wakeup */
extern FUNC(void, CAN_RSCAN_PUBLIC_CODE) Can_MainFunction_Wakeup(void);
/* API for schedule processing of Mode */
extern FUNC(void, CAN_RSCAN_PUBLIC_CODE) Can_MainFunction_Mode(void);

extern FUNC(void, CAN_PUBLIC_CODE)Can_ResetController
(
    uint8 Controller
);

#if (CAN_VERSION_INFO_API == STD_ON)
extern FUNC(void, CAN_RSCAN_PUBLIC_CODE) Can_GetVersionInfo(
  P2VAR(Std_VersionInfoType, AUTOMATIC, CAN_RSCAN_APPL_DATA) versioninfo);
#endif

#if (CAN_CHECK_WAKEUP_API == STD_ON)
extern FUNC(Can_ReturnType, CAN_RSCAN_PUBLIC_CODE) Can_CheckWakeup(
  uint8 Controller);
#endif

#if (CAN_RAM_MIRROR == STD_ON)
extern FUNC(Std_ReturnType, CAN_RSCAN_PUBLIC_CODE) Can_CheckHWConsistency
                               (Can_HWConsistencyModeType LenHWConsistencyMode);
#endif

#if (CAN_RAMTEST_API == STD_ON)
extern FUNC(Std_ReturnType, CAN_RSCAN_PUBLIC_CODE) Can_RAMTest(
  uint32 LulPageID);
#endif

/* API for setting self test of the Controller */
extern FUNC(Std_ReturnType, CAN_RSCAN_PUBLIC_CODE) Can_SelfTestChannel
                    (uint8 LucController, Can_SelfTestType LenTest_Transition);

#define CAN_RSCAN_STOP_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-1 */
//#include CAN_MEMMAP_FILE
/* END Msg(2:0832)-1 */


#define CAN_RSCAN_START_SEC_APPL_CODE
/* QAC Warning: START Msg(2:0832)-1 */
//#include CAN_MEMMAP_FILE
/* END Msg(2:0832)-1 */

#if defined(CAN_LPDU_RECEIVE_CALLOUT_FUNCTION)
extern FUNC(boolean, CAN_RSCAN_APPL_CODE) CAN_LPDU_RECEIVE_CALLOUT_FUNCTION(
  uint8 Hrh, Can_IdType CanId, uint8 CanDataLength,
  P2CONST(uint8, AUTOMATIC, CAN_RSCAN_APPL_CONST) CanSduPtr);
#endif

#define CAN_RSCAN_STOP_SEC_APPL_CODE
/* QAC Warning: START Msg(2:0832)-1 */
//#include CAN_MEMMAP_FILE
/* END Msg(2:0832)-1 */

#endif /* CAN_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
