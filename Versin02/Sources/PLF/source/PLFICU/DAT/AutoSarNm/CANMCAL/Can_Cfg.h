/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Can_Cfg.h                                                   */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2021 Renesas Electronics Corporation. All rights reserved.    */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains pre-compile time parameters.                            */
/* AUTOMATICALLY GENERATED FILE - DO NOT EDIT                                 */
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
/*              Devices:        R7F701684                                     */
/*============================================================================*/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*============================================================================*/
/* Version    Last modified   Description                                     */
/*============================================================================*/
/* V1.0.0:    16-Mar-2021   : Initial Version                                 */


/*******************************************************************************
**                      Generation Tool Version                               **
*******************************************************************************/
/*                                                                            */
/* TOOL VERSION:  CanF1x.dll version: 1.0.2, MCALConfGen.exe version: 1.0.3   */
/*                                                                            */

/*******************************************************************************
**                      Input File                                            **
*******************************************************************************/
/*
 * INPUT FILE:    D:\01_Works\02_DoResearch\RH850\F1KM\CAN_Gen\MCU_CAN_F1KM.arxml
 *                D:\01_Works\02_DoResearch\RH850\F1KM\CAN_Gen\EcuM_Can.arxml
 *                D:\01_Works\02_DoResearch\RH850\F1KM\CAN_Gen\Os_Can.arxml
 *                D:\01_Works\02_DoResearch\RH850\F1KM\CAN_Gen\Dem_Can.arxml
 *                D:\01_Works\02_DoResearch\RH850\F1KM\CAN_Gen\App_GLOBAL_F1KM_701684_Sample.arxml
 *                D:\01_Works\02_DoResearch\RH850\F1KM\CAN_Gen\App_CAN_F1KM_701684_Sample.arxml
 *                D:\01_Works\02_DoResearch\RH850\F1KM\CAN_Gen\R422_CAN_F1x_BSWMDT.arxml
 *                D:\01_Works\02_DoResearch\RH850\F1KM\CAN_Gen\Sample_Application_F1x.trxml
 * GENERATED ON:  20 6鏈� 2022 - 05:05:30
 */

#ifndef CAN_CFG_H
#define CAN_CFG_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "ComStack_Types.h"
//#include "Dem_Cfg.h"
/*******************************************************************************
**                      QAC Warning                                           **
*******************************************************************************/


/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* Autosar Release Version Information */
#define CAN_CFG_AR_RELEASE_MAJOR_VERSION                4
#define CAN_CFG_AR_RELEASE_MINOR_VERSION                2
#define CAN_CFG_AR_RELEASE_REVISION_VERSION             2

/* File Version Information */
#define CAN_CFG_SW_MAJOR_VERSION                        1
#define CAN_CFG_SW_MINOR_VERSION                        0

#define CAN_USED_CONTROLLER_NUM                         (1)
#define CAN_USED_HOH_NUM                     12//11 //jjq(8u)
/*******************************************************************************
**                      Common Published Information                          **
*******************************************************************************/
#define CAN_AR_RELEASE_MAJOR_VERSION_VALUE              4U
#define CAN_AR_RELEASE_MINOR_VERSION_VALUE              2U
#define CAN_AR_RELEASE_REVISION_VERSION_VALUE           2U

#define CAN_SW_MAJOR_VERSION_VALUE                      1U
#define CAN_SW_MINOR_VERSION_VALUE                      0U
#define CAN_SW_PATCH_VERSION_VALUE                      2U

#define CAN_VENDOR_ID_VALUE                             59U
#define CAN_MODULE_ID_VALUE                             80U


/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/* Pre-compile option for Version information */
#define CAN_AR_VERSION                                  CAN_AR_422_VERSION

/* Pre-compile option for Number of configured hardware units */
#define CAN_NO_OF_UNITS                                 1U

/* Pre-compile option for Number of configured Controllers */
#define CAN_NO_OF_CONTROLLERS                           1U

/* Pre-compile option for Number of configured hardware object handles */
#define CAN_NO_OF_HOHS                                  9U

/* Pre-compile option for maximum number of controller */
#define RSCAN0_MAX_NUMBER_OF_CONTROLLER                 (uint8)6U
#define RSCAN1_MAX_NUMBER_OF_CONTROLLER                 (uint8)0U

/* Pre-compile option for Os Counter ID */
#define CAN_OS_COUNTER_ID                               OsCounter0

/* Pre-compile option for The macro for including MemMap */
#define CAN_MEMMAP_FILE                                 "Can_MemMap.h"

/* Pre-compile option for Set baudrate API */
#define CAN_SET_BAUDRATE_API                            STD_ON

/* Pre-compile option for Can_CheckWakeup API */
#define CAN_CHECK_WAKEUP_API                            STD_ON

/* Pre-compile option for Version Info API */
#define CAN_VERSION_INFO_API                            STD_ON

/* Pre-compile option for Change baudrate API */
#define CAN_CHANGE_BAUDRATE_API                         STD_ON

/* Pre-compile option for Development Error Detect */
#define CAN_DEV_ERROR_DETECT                            STD_ON

/* Pre-compile option for allowing re-initialization with Can_Init API */
#define CAN_ALREADY_INIT_DET_CHECK                      STD_ON

/* Pre-compile option for RSCANn handling */
#define CAN_RSCAN_CONFIGURED                            STD_OFF

/* Pre-compile option for RSCANFDn handling */
#define CAN_RSCANFD_CONFIGURED                          STD_ON

/* Pre-compile option for Critical Section Protection */
#define CAN_CRITICAL_SECTION_PROTECTION                 STD_ON

/* Pre-compile option for Can Wakeup Support */
#define CAN_WAKEUP_SUPPORT                              STD_ON

/* Pre-compile option for name of callout function */
#define CAN_LPDU_RECEIVE_CALLOUT_FUNCTION               UserCalloutFunction

/* Pre-compile option for External Module Version Check */
#define CAN_VERSION_CHECK_EXT_MODULES                   STD_ON

/* Pre-compile option for Wakeup Interrupt */
#define CAN_WAKEUP_POLLING                              STD_OFF

/* Pre-compile option for Rx Interrupt */
#define CAN_RX_POLLING                                  STD_ON

/* Pre-compile option for Busoff Interrupt */
#define CAN_BUSOFF_POLLING                              STD_OFF

/* Pre-compile option for Rx FIFO Interrupt */
#define CAN_RSCAN0_RXFIFO_INTERRUPT                     STD_ON
#define CAN_RSCAN1_RXFIFO_INTERRUPT                     STD_OFF

/* Pre-compile option for Tx Interrupt */
#define CAN_TX_POLLING                                  STD_OFF

/* Pre-compile option for Receive BUFFER is configured */
#define CAN_RX_BUFFER                                   STD_OFF

/* Pre-compile option for Transmit BUFFER is configured */
#define CAN_TX_BUFFER                                   STD_ON

/* Pre-compile option for Receive FIFO is configured */
#define CAN_RX_FIFO                                     STD_ON

/* Pre-compile option for Receive FIFO is configured in Tx/RX FIFO */
#define CAN_RX_COMFIFO                                  STD_OFF

/* Pre-compile option for Transmit FIFO is configured in Tx/RX FIFO */
#define CAN_TX_COMFIFO                                  STD_OFF

/* Pre-compile option for GATEWAY is configured in Tx/RX FIFO */
#define CAN_GATEWAY_COMFIFO                             STD_OFF

/* Pre-compile option for Transmit QUEUE is configured */
#define CAN_TX_QUEUE                                    STD_OFF

/* Pre-compile option for Timeout Count */
#define CAN_TIMEOUT_COUNT                               5UL

/* Pre-compile option for OS Counter Max Value */
#define CAN_OS_COUNTER_MAX_VALUE                        1000U

/* Pre-compile option for Receive Object is configured */
#define CAN_RX_OBJECT                                   STD_ON

/* Pre-compile option for DEM for CAN Driver for Time out value */
#define CAN_E_TIMEOUT_FAILURE                           \
  DemConf_DemEventParameter_DemEventParameter0

/* Pre-compile option for Busoff Interrupt */
#define CAN_CONTROLLER0_BUSOFF_INTERRUPT                STD_ON
#define CAN_CONTROLLER1_BUSOFF_INTERRUPT                STD_OFF
#define CAN_CONTROLLER2_BUSOFF_INTERRUPT                STD_OFF
#define CAN_CONTROLLER3_BUSOFF_INTERRUPT                STD_OFF
#define CAN_CONTROLLER4_BUSOFF_INTERRUPT                STD_OFF
#define CAN_CONTROLLER5_BUSOFF_INTERRUPT                STD_OFF
#define CAN_CONTROLLER6_BUSOFF_INTERRUPT                STD_OFF
#define CAN_CONTROLLER7_BUSOFF_INTERRUPT                STD_OFF
#define CAN_CONTROLLER8_BUSOFF_INTERRUPT                STD_OFF
#define CAN_CONTROLLER9_BUSOFF_INTERRUPT                STD_OFF
#define CAN_CONTROLLER10_BUSOFF_INTERRUPT               STD_OFF
#define CAN_CONTROLLER11_BUSOFF_INTERRUPT               STD_OFF

/* Pre-compile option for Wakeup Interrupt */
#define CAN_CONTROLLER0_WAKEUP_INTERRUPT                STD_ON
#define CAN_CONTROLLER1_WAKEUP_INTERRUPT                STD_OFF
#define CAN_CONTROLLER2_WAKEUP_INTERRUPT                STD_OFF
#define CAN_CONTROLLER3_WAKEUP_INTERRUPT                STD_OFF
#define CAN_CONTROLLER4_WAKEUP_INTERRUPT                STD_OFF
#define CAN_CONTROLLER5_WAKEUP_INTERRUPT                STD_OFF
#define CAN_CONTROLLER6_WAKEUP_INTERRUPT                STD_OFF
#define CAN_CONTROLLER7_WAKEUP_INTERRUPT                STD_OFF
#define CAN_CONTROLLER8_WAKEUP_INTERRUPT                STD_OFF
#define CAN_CONTROLLER9_WAKEUP_INTERRUPT                STD_OFF
#define CAN_CONTROLLER10_WAKEUP_INTERRUPT               STD_OFF
#define CAN_CONTROLLER11_WAKEUP_INTERRUPT               STD_OFF

/* Pre-compile option for Rx Interrupt */
#define CAN_CONTROLLER0_RX_INTERRUPT                    STD_OFF
#define CAN_CONTROLLER1_RX_INTERRUPT                    STD_OFF
#define CAN_CONTROLLER2_RX_INTERRUPT                    STD_OFF
#define CAN_CONTROLLER3_RX_INTERRUPT                    STD_OFF
#define CAN_CONTROLLER4_RX_INTERRUPT                    STD_OFF
#define CAN_CONTROLLER5_RX_INTERRUPT                    STD_OFF
#define CAN_CONTROLLER6_RX_INTERRUPT                    STD_OFF
#define CAN_CONTROLLER7_RX_INTERRUPT                    STD_OFF
#define CAN_CONTROLLER8_RX_INTERRUPT                    STD_OFF
#define CAN_CONTROLLER9_RX_INTERRUPT                    STD_OFF
#define CAN_CONTROLLER10_RX_INTERRUPT                   STD_OFF
#define CAN_CONTROLLER11_RX_INTERRUPT                   STD_OFF

/* Pre-compile option for Tx Interrupt */
#define CAN_CONTROLLER0_TX_INTERRUPT                    STD_ON
#define CAN_CONTROLLER1_TX_INTERRUPT                    STD_OFF
#define CAN_CONTROLLER2_TX_INTERRUPT                    STD_OFF
#define CAN_CONTROLLER3_TX_INTERRUPT                    STD_OFF
#define CAN_CONTROLLER4_TX_INTERRUPT                    STD_OFF
#define CAN_CONTROLLER5_TX_INTERRUPT                    STD_OFF
#define CAN_CONTROLLER6_TX_INTERRUPT                    STD_OFF
#define CAN_CONTROLLER7_TX_INTERRUPT                    STD_OFF
#define CAN_CONTROLLER8_TX_INTERRUPT                    STD_OFF
#define CAN_CONTROLLER9_TX_INTERRUPT                    STD_OFF
#define CAN_CONTROLLER10_TX_INTERRUPT                   STD_OFF
#define CAN_CONTROLLER11_TX_INTERRUPT                   STD_OFF

/* Pre-compile option for trigger transmit function is configured */
#define CAN_TRIGGER_TRANSMIT_FUNCTION                   STD_OFF

/* Enables/Disables the interrupt consistency check in the ISRs */
#define CAN_INTERRUPT_CONSISTENCY_CHECK                 STD_ON

/* CAT2 ISR category using */
#define CAN_ISR_CATEGORY_2                              STD_OFF

/* Pre-compile option for CANV2 */
#define CAN_CANV2_CONFIGURED                            STD_OFF

/* Pre-compile option for Wakeup Factor */
#define CAN_WAKEUPFACTOR_CLEAR                          STD_OFF

/* Reference to configured DEM event */
#define CAN_E_INT_INCONSISTENT                          \
  DemConf_DemEventParameter_DemEventParameter0

/* Pre-compile option for RAM mirror */
#define CAN_RAM_MIRROR                                  STD_ON

/* The number of main function periods used */
#define CAN_NUMBER_OF_MAINFUNCTIONS                     1U

/* Pre-compile option for Ram Test feature */
#define CAN_RAMTEST_API                                 STD_ON

/* Maximum ram test page number */
#define CAN_MAX_RAMPAGES_HARDWARE                       (uint32)0x000000C6UL

/* Maximum ram test page number of unit 0 */
#define RSCAN0_PAGEID_MAX_VALUE                         (uint32)0x000000C6UL

/* Size of last ram page of unit 0 */
#define RSCAN0_RAM_LAST_PAGE_SIZE                       (uint8)0x30U

#define CAN_USE_WV_ERROR_INTERFACE                      STD_OFF

/* Pre-compile option for write verify */
#define CAN_WRITE_VERIFY                                CAN_WV_DISABLE

/* DEM event that will be reported to when Tx history overflow occurs */
#define CAN_E_TX_HISTORY_OVERFLOW                       \
  DemConf_DemEventParameter_DemEventParameter0

/* Controller ID offset */
#define CAN_CONTROLLER_OFFSET                           0U

/* CAN Controller Configuration Handle */
#define CanConf_CanController_CanController0            0U

/* Hardware Objects Configuration Handle */
#define CanConf_CanHardwareObject_CanHardwareObject0    (Can_HwHandleType)0
#define CanConf_CanHardwareObject_CanHardwareObject1    (Can_HwHandleType)1
#define CanConf_CanHardwareObject_CanHardwareObject2    (Can_HwHandleType)2
#define CanConf_CanHardwareObject_CanHardwareObject3    (Can_HwHandleType)3
#define CanConf_CanHardwareObject_CanHardwareObject4    (Can_HwHandleType)4
#define CanConf_CanHardwareObject_CanHardwareObject5    (Can_HwHandleType)5

/* Configuration Set Handles */
#define CanConfigSet0                                   (&Can_GaaConfig[0])



/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/


/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/


/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/


#endif /* CAN_CFG_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

