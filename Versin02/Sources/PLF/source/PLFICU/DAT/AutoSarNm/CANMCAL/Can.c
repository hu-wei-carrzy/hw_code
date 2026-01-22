/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Can.c                                                       */
/* Version      = V1.0.2                                                      */
/* Date         = 03-Jun-2021                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* (c) 2019-2021 Renesas Electronics Corporation. All rights reserved.        */
/*============================================================================*/
/* Purpose:                                                                   */
/* Provision of Initialization, ReInitialization and Version Control          */
/* Functionality.                                                             */
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
 *          13-Jul-2019  : Change write verify and RAM mirror to INLINE function
 *          01-Aug-2019  : Improve write verify by using Can_VerifyWriteReg
 *                         function and macro functions CAN_WRITE_VERIFY_INIT,
 *                         CAN_WRITE_VERIFY_MIRROR_INIT,
 *                         CAN_WRITE_VERIFY_RUNTIME,
 *                         CAN_WRITE_VERIFY_MIRROR_RUNTIME
 *          25-Sep-2019  : Update MISRA C Rule Violations, remove QAC message
 *                         (4:0310). Update QAC message (4:0491).
 *          11-Oct-2019  : Initialize Can_GaaHwAccessFlag in Can_Init.
 * V1.0.1:  24-Sep-2020  : Add QAC justification and comments.
 *          23-Oct-2020  : Correct Service ID of Can_RAMTest().
 * V1.0.2:  16-Mar-2021  : As per ARDAABD-2992, Update Global Variable Used and
 *                         register used of all functions at function's banner.
 *                         As per ARDAABD-2517: Update Function Invoked of    
 *                         functions at function's banner                       
 *          25-Mar-2021  : As per ARDAABD-5506, Change type of BaudRateConfigID
 *                         parameter in Can_SetBaudrate() API to uint16.
 *          03-Apr-2021  : Update QAC 931, MISRA-C Rule Violation.
 *                         Remove QAC message (2:2016)
 *                         Add QAC message (2:0857), (4:5087),(1:1503),
 *                         (2:3138), (2:2982).
 *          03-Jun-2021  : Added QAC Warning messages.
 */
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* CAN module header file */
#include "Can.h"
//#include "can_drv.h"
//#include "Can_GeneralTypes.h"
//#include "Can_LTTypes.h"
//#include "Can_PBTypes.h"
//#include "Can_Irq.h"
/* MISRA Violation: START Msg(2:0857)-9 */
//#include "Can_RegWrite.h"
/* END Msg(2:0857)-9 */
/* including DEM header file */
//#include "Dem.h"
/* Included for RAM variable declarations */
//#include "Can_Ram.h"
//#include "Can_ModeCntrl.h"
/* MISRA Violation: START Msg(2:0857)-9 */
//#include "Can_MainServ.h"
/* END Msg(2:0857)-9 */
//#if (CAN_WAKEUP_SUPPORT == STD_ON)
/* ECUM callback and call-out header file */
//#include "EcuM_Cbk.h"
//#endif
/*
 * OS Header File to have the prototype of GetCounterValue() for getting current
 * tick of OS
 */
//#include "Os.h"

#if (CAN_CRITICAL_SECTION_PROTECTION == STD_ON)
/* Included for the declaration of the critical section protection functions */
//#include "SchM_Can.h"
#endif
/* Included for the declaration of Det_ReportError() */
#if (CAN_DEV_ERROR_DETECT == STD_ON)
//#include "Det.h"
#endif
//#include "rh850_Types.h"

#if (CAN_RAMTEST_API == STD_ON)
/* CAN Driver RAM Test Header File */
//#include "Can_RamTest.h"
#endif

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR release version information */
#define CAN_C_AR_RELEASE_MAJOR_VERSION CAN_AR_RELEASE_MAJOR_VERSION
#define CAN_C_AR_RELEASE_MINOR_VERSION CAN_AR_RELEASE_MINOR_VERSION
#define CAN_C_AR_RELEASE_REVISION_VERSION CAN_AR_RELEASE_REVISION_VERSION

/* File version information */
#define CAN_C_SW_MAJOR_VERSION    CAN_SW_MAJOR_VERSION
#define CAN_C_SW_MINOR_VERSION    CAN_SW_MINOR_VERSION

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (CAN_C_AR_RELEASE_MAJOR_VERSION != CAN_AR_RELEASE_MAJOR_VERSION_VALUE)
  #error "Can.c : Mismatch in Release Major Version"
#endif
#if (CAN_C_AR_RELEASE_MINOR_VERSION != CAN_AR_RELEASE_MINOR_VERSION_VALUE)
  #error "Can.c : Mismatch in Release Minor Version"
#endif
#if (CAN_C_AR_RELEASE_REVISION_VERSION != CAN_AR_RELEASE_REVISION_VERSION_VALUE)
  #error "Can.c : Mismatch in Release Revision Version"
#endif

#if (CAN_C_SW_MAJOR_VERSION != CAN_SW_MAJOR_VERSION_VALUE)
  #error "Can.c : Mismatch in Software Major Version"
#endif
#if (CAN_C_SW_MINOR_VERSION != CAN_SW_MINOR_VERSION_VALUE)
  #error "Can.c : Mismatch in Software Minor Version"
#endif

/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/

/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (2:0316) Cast from a pointer to void to a pointer to       */
/*                 object type .                                              */
/* Rule          : MISRA-C:2004 Rule-11.4                                     */
/* Justification : Typecasting from void* is necessary to hide internal types */
/*                 from the header files which are exposed to user.           */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:0316)-1 and                           */
/*                 END Msg(2:0316)-1 tags in the code.                        */
/******************************************************************************/

/* 2. MISRA C RULE VIOLATION:                                                 */
/* Message       : (2:0491) Array subscripting applied to an object of        */
/*                 pointer type.                                              */
/* Rule          : MISRA-C:2004 Rule-17.4                                     */
/* Justification : This is necessary to support configuration.                */
/*                 The actual array can't be decided statically.              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:0491)-2 and                           */
/*                 END Msg(2:0491)-2 tags in the code.                        */
/******************************************************************************/

/* 3. MISRA C RULE VIOLATION:                                                 */
/* Message       : (2:1055) [C99] The keyword 'inline' has been used.         */
/* Rule          : MISRA-C:2004 Rule 1.1                                      */
/* Justification : This message is allowed in F1x to improve software metric. */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:1055)-3 and                           */
/*                 END Msg(2:1055)-3 tags in the code.                        */
/******************************************************************************/

/* 4. MISRA C RULE VIOLATION:                                                 */
/* Message       : (2:3458) Macro defines a braced code statement block.      */
/* Rule          : MISRA-C:2004 Rule-19.4                                     */
/* Justification : Since the macros are implemented as function macros braces */
/*                 cannot be avoided.                                         */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for  MISRA Violation: START Msg(2:3458)-4 and         */
/*                 END Msg(2:3458)-4 tags in the code.                        */
/******************************************************************************/

/* 5. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:2984) This operation is redundant. The value of the     */
/*                 result is always '1'.                                      */
/* Rule          : MISRA-C:2004 Rule 21.1                                     */
/* Justification : If user configures controller offset ID is more than 1,    */
/*                 this warning will  not occur.                              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2984)-5 and                           */
/*                 END Msg(4:2984)-5 tags in the code.                        */
/******************************************************************************/

/* 6. MISRA C RULE VIOLATION:                                                 */
/* Message       : (6:2877) This loop will never be executed more than once.  */
/* Rule          : MISRA-C:2004 Rule-21.1                                     */
/* Justification : It is depend on configuration, the maximum of loop count   */
/*                 shall be more than one with different configurations.      */
/* Verification  : However, part of the code is verified manually             */
/*                 and it is not having any impact.                           */
/* Reference     : Look for START Msg(6:2877)-6 and                           */
/*                 END Msg(6:2877)-6 tags in the code.                        */
/******************************************************************************/

/* 7. MISRA C RULE VIOLATION:                                                 */
/* Message       : (6:2993) The value of this 'do - while' loop controlling.  */
/*                  expression is always 'false'. The loop will only be       */
/*                  executed once.                                            */
/* Rule          : MISRA-C:2004 Rule-13.7                                     */
/* Justification : It is depend on configuration, the maximum of loop count   */
/*                 shall be more than one with different configurations.      */
/* Verification  : However, part of the code is verified manually             */
/*                 and it is not having any impact.                           */
/* Reference     : Look for START Msg(6:2993)-7 and                           */
/*                 END Msg(6:2993)-7 tags in the code.                        */
/******************************************************************************/

/* 8. MISRA C RULE VIOLATION:                                                 */
/* Message       : (6:2996) The result of this logical operation is always    */
/*                 'false'.                                                   */
/* Rule          : MISRA-C:2004 Rule-13.7                                     */
/* Justification : Condition check is for all use cases and the warning is    */
/*                 for only particular configuration.                         */
/* Verification  : However, this part of the code is verified manually and it */
/*                 is not having any impact.                                  */
/* Reference     : Look for START Msg(6:2996)-8 and                           */
/*                 END Msg(6:2996)-8 tags in the code.                        */
/******************************************************************************/

/* 9. MISRA C RULE VIOLATION:                                                 */
/* Message       : (2:0857) [L] Number of macro definitions exceeds 1024 -    */
/*                  program does not conform strictly to ISO:C90.             */
/* Rule          : MISRA-C:2004 Rule-1.1                                      */
/* Justification : This is accepted as of macros are used for better          */
/*                 readability of code and/or to support configuration        */
/*                 flexibility                                                */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:0857)-9  and                          */
/*                 END Msg(2:0857)-9  tags in the code.                       */
/******************************************************************************/

/* 10. MISRA C RULE VIOLATION:                                                */
/* Message       : (4:5087) Use of #include directive after code fragment.    */
/* Rule          : MISRA-C:2004 Rule-19.1                                     */
/* Justification : This is accepted, due to implementation for include        */
/*                 memmap is following AUTOSAR rule.                          */
/* Verification  : However, part of the code is verified manually             */
/*                 and it is not having any impact.                           */
/* Reference     : Look for START Msg(4:5087)-10 and                          */
/*                 END Msg(4:5087)-10 tags in the code.                       */
/******************************************************************************/

/* 11. MISRA C RULE VIOLATION:                                                */
/* Message       : (1:1503) The function '%1s' is defined but is not used     */
/*                  within this project.                                      */
/* Rule          : MISRA-C:2004 Rule-14.1                                     */
/* Justification : This is accepted, due to the module's API is exported      */
/*                 for user's usage.                                          */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(1:1503)-11  and                         */
/*                 END Msg(1:1503)-11  tags in the code.                      */
/******************************************************************************/

/* 12. MISRA C RULE VIOLATION:                                                */
/* Message       : (2:3138) Null statement is located close to other code or  */
/*                 comments.                                                  */
/* Rule          : MISRA-C:2004 Rule-14.3                                     */
/* Justification : This is limitation of QAC since it can't compile assembler */
/*                 There is no impact on operation.                           */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:3138)-12  and                         */
/*                 END Msg(2:3138)-12  tags in the code.                      */
/******************************************************************************/

/* 13. MISRA C RULE VIOLATION:                                                */
/* Message       : (2:2982) This assignment is redundant. The value of this   */
/*                 object is never used before being modified.                */
/* Rule          : MISRA-C:2004 Rule-21.1                                     */
/* Justification : This variable is necessary to initialized before using.    */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:2982)-13 and                          */
/*                 END Msg(2:2982)-13 tags in the code.                       */
/******************************************************************************/
/******************************************************************************/
/**                      QAC warning                                         **/
/******************************************************************************/

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

/* 2. QAC Warning:                                                            */
/* Message       : (2:3441) Function call argument is an expression with      */
/*                 possible side effects                                      */
/* Rule          : No MISRA-C:2004 Rules applicable to message 3441           */
/* Justification : Logical operation accesses volatile object which is a      */
/*                 register access and timeout counter. All register addresses*/
/*                 and timeout counter are generated with volatile qualifier. */
/*                 There is no impact on the functionality                    */
/*                 due to this conditional check for mode change.             */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:3441)-2 and END Msg(2:3441)-2         */
/*                 tags in the code.                                          */
/******************************************************************************/

/* 3. QAC warning:                                                            */
/* Message       : (2:3457) Macro defines a braced initializer.               */
/* Rule          : No MISRA-C:2004 Rules applicable to message 3457           */
/* Justification : Since the macros are implemented as function macros braces */
/*                 cannot be avoided.                                         */
/* Verification  : However, part of the code is verified manually             */
/*                 and it is not having any impact.                           */
/* Reference     : Look for START Msg(2:3457)-3 and                           */
/*                 END Msg(2:3457)-3 tags in the code.                        */
/******************************************************************************/

/* 4. QAC warning:                                                            */
/* Message       : (2:3227) The parameter '%s' is never modified and          */
/*                 so it could be declared with the 'const' qualifier.        */
/* Rule          : No MISRA-C:2004 Rules applicable to message 3227           */
/*                 REFERENCE - ISO:C90-6.5.3 Type Qualifiers                  */
/* Justification : To follow AUTOSAR and/or Renesas requirement for this API, */
/*                 the const shall not be used.                               */
/* Verification  : However, part of the code is verified manually             */
/*                 and it is not having any impact.                           */
/* Reference     : Look for START Msg(2:3227)-4 and                           */
/*                 END Msg(2:3227)-4 tags in the code.                        */
/******************************************************************************/

/* 5. QAC Warning:                                                            */
/* Message       : (3:3416) Logical operation performed on expression with    */
/*                 possible side effects.                                     */
/* Justification : Logical operation accesses volatile object which is a      */
/*                 register access and timeout counter. All register addresses*/
/*                 and timeout counter are generated with volatile qualifier. */
/*                 There is no impact on the functionality                    */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(3:3416)-5 and END Msg(3:3416)-5         */
/*                 tags in the code.                                          */
/******************************************************************************/

/* 6. QAC Warning:                                                            */
/* Message       : (2:3352) This 'switch' statement contains only two         */
/*                 execution paths.                                           */
/* Rule          : No MISRA-C:2004 Rules applicable to message 3352           */
/* Justification : The number of switch case is depend on configurations      */
/*                 So using switch is necessary instead of if-else.           */
/* Verification  : However, part of the code is verified manually             */
/*                 and it is not having any impact.                           */
/* Reference     : Look for START Msg(2:3352)-6 and                           */
/*                 END Msg(2:3352)-6 tags in the code.                        */
/******************************************************************************/
/******************************************************************************/

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
/*******************************************************************************
**                      Inline Function Definitions                           **
*******************************************************************************/

/*******************************************************************************
** Function Name         : Can_VerifyWriteReg
**
** Description           : This function is to check write verify.
**
** Input Parameters      : LpWriteRegAddr, LulRegWriteValue, LulMaskValue,
**                         LucApiId
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Pre-conditions        : None
**
** Functions invoked     : None
*******************************************************************************/
#define CAN_RSCAN_START_SEC_PRIVATE_CODE
/* QAC Warning: START Msg(2:0832)-1 */
//#include CAN_MEMMAP_FILE
/* END Msg(2:0832)-1 */
#if (CAN_WRITE_VERIFY != CAN_WV_DISABLE)
/* MISRA Violation: START Msg(2:1055)-3 */
static INLINE FUNC(void, CAN_RSCAN_PRIVATE_CODE) Can_VerifyWriteReg(
  CONSTP2CONST(volatile uint32, AUTOMATIC, REGSPACE) LpWriteRegAddr,
  CONST(uint32, AUTOMATIC) LulRegWriteValue,
  CONST(uint32, AUTOMATIC) LulMaskValue,
  CONST(uint8, AUTOMATIC) LucApiId)
/* END Msg(2:1055)-3 */
{
  /* References: CAN_DDD_ACT_066 */
  CAN_VERIFY_WRITE_REG(LpWriteRegAddr, LulRegWriteValue, LulMaskValue, LucApiId)
}
#endif /* End of #if (CAN_WRITE_VERIFY != CAN_WV_DISABLE) */
#define CAN_RSCAN_STOP_SEC_PRIVATE_CODE
/* QAC Warning: START Msg(2:0832)-1 */
/* MISRA Violation: START Msg(4:5087)-10 */
//#include CAN_MEMMAP_FILE
/* END Msg(4:5087)-10 */
/* END Msg(2:0832)-1 */

#if (CAN_WRITE_VERIFY != CAN_WV_DISABLE)
  /* MISRA Violation: START Msg(2:3458)-4 */
  #define CAN_WRITE_VERIFY_INIT(pWriteRegAddr, \
                                RegWriteValue, MaskValue, ApiId) \
  { \
    CAN_WRITE_REG_ONLY(pWriteRegAddr, RegWriteValue) \
    Can_VerifyWriteReg(pWriteRegAddr, RegWriteValue, MaskValue, ApiId); \
  }
  /* END Msg(2:3458)-4 */

  /* MISRA Violation: START Msg(2:3458)-4 */
  #define CAN_WRITE_VERIFY_MIRROR_INIT(pWriteRegAddr, \
                                RegWriteValue, pMirrorAddr, MaskValue, ApiId) \
  { \
    CAN_WRITE_REG_ONLY(pWriteRegAddr, RegWriteValue) \
    Can_VerifyWriteReg(pWriteRegAddr, RegWriteValue, MaskValue, ApiId); \
    CAN_WRITE_RAM_MIRROR(pMirrorAddr, RegWriteValue) \
  }
  /* END Msg(2:3458)-4 */
#else
  /* QAC Warning: START Msg(2:3457)-3 */
  #define CAN_WRITE_VERIFY_INIT(pWriteRegAddr, \
                                RegWriteValue, MaskValue, ApiId) \
  { \
    CAN_WRITE_REG_ONLY(pWriteRegAddr, RegWriteValue) \
  }
  /* END Msg(2:3457)-3 */

  /* QAC Warning: START Msg(2:3457)-3 */
  #define CAN_WRITE_VERIFY_MIRROR_INIT(pWriteRegAddr, \
                                RegWriteValue, pMirrorAddr, MaskValue, ApiId) \
  { \
    CAN_WRITE_REG_ONLY(pWriteRegAddr, RegWriteValue) \
    CAN_WRITE_RAM_MIRROR(pMirrorAddr, RegWriteValue) \
  }
  /* END Msg(2:3457)-3 */
#endif
#if (CAN_WRITE_VERIFY == CAN_WV_INIT_RUNTIME)
  /* MISRA Violation: START Msg(2:3458)-4 */
  #define CAN_WRITE_VERIFY_RUNTIME(pWriteRegAddr, \
                                RegWriteValue, MaskValue, ApiId) \
  { \
    CAN_WRITE_REG_ONLY(pWriteRegAddr, RegWriteValue) \
    Can_VerifyWriteReg(pWriteRegAddr, RegWriteValue, MaskValue, ApiId); \
  }
  /* END Msg(2:3458)-4 */

  /* MISRA Violation: START Msg(2:3458)-4 */
  #define CAN_WRITE_VERIFY_MIRROR_RUNTIME(pWriteRegAddr, \
                                RegWriteValue, pMirrorAddr, MaskValue, ApiId) \
  { \
    CAN_WRITE_REG_ONLY(pWriteRegAddr, RegWriteValue) \
    CAN_WRITE_RAM_MIRROR(pMirrorAddr, RegWriteValue) \
  }
  /* END Msg(2:3458)-4 */
#else
  /* QAC Warning: START Msg(2:3457)-3 */
  #define CAN_WRITE_VERIFY_RUNTIME(pWriteRegAddr, \
                                RegWriteValue, MaskValue, ApiId) \
  { \
    CAN_WRITE_REG_ONLY(pWriteRegAddr, RegWriteValue) \
  }
  /* END Msg(2:3457)-3 */

  /* QAC Warning: START Msg(2:3457)-3 */
  #define CAN_WRITE_VERIFY_MIRROR_RUNTIME(pWriteRegAddr, \
                                RegWriteValue, pMirrorAddr, MaskValue, ApiId) \
  { \
    CAN_WRITE_REG_ONLY(pWriteRegAddr, RegWriteValue) \
    CAN_WRITE_RAM_MIRROR(pMirrorAddr, RegWriteValue) \
  }
  /* END Msg(2:3457)-3 */
#endif

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
#define CAN_RSCAN_START_SEC_PRIVATE_CODE
/* QAC Warning: START Msg(2:0832)-1 */
/* MISRA Violation: START Msg(4:5087)-10 */
//#include CAN_MEMMAP_FILE
/* END Msg(4:5087)-10 */
/* END Msg(2:0832)-1 */

/* Set global status */
static FUNC(void, CAN_RSCAN_PRIVATE_CODE) Can_SetStatus(
  const boolean LblStatus);
/* Sub function to initialize RSCANn module */
static FUNC(boolean, CAN_RSCAN_PRIVATE_CODE) Can_InitModule(
  const uint8 LucUnit);
/* Sub function to initialize Controller */
static FUNC(boolean, CAN_RSCAN_PRIVATE_CODE) Can_InitController(
  const uint8 LucCtrlIndex);

#if (CAN_CHANGE_BAUDRATE_API == STD_ON)
/* Sub function to get index of baudrate config table with baudrate */
static FUNC(uint32, CAN_RSCAN_PRIVATE_CODE) Can_SearchBaudrate(
  const uint8 LucCtrlIndex, const uint16 LusBaudrate);
#endif

#if (CAN_SET_BAUDRATE_API == STD_ON)
/* Sub function to get index of baudrate config table with ID */
static FUNC(uint32, CAN_RSCAN_PRIVATE_CODE) Can_SearchBaudrateID(
  const uint8 LucCtrlIndex, const uint16 LusBaudrateID);
#endif

#if (CAN_RAM_MIRROR == STD_ON)
/* Sub function to check consistency in static mode */
static FUNC(Std_ReturnType, CAN_RSCAN_PRIVATE_CODE) Can_CheckConsistencyStatic(
  void);
/* Sub function to check consistency in dynamic mode */
static FUNC(Std_ReturnType, CAN_RSCAN_PRIVATE_CODE) Can_CheckConsistencyDynamic(
  void);
#endif

#define CAN_RSCAN_STOP_SEC_PRIVATE_CODE
/* QAC Warning: START Msg(2:0832)-1 */
/* MISRA Violation: START Msg(4:5087)-10 */
//#include CAN_MEMMAP_FILE
/* END Msg(4:5087)-10 */
/* END Msg(2:0832)-1 */

#define CAN_RSCAN_START_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-1 */
/* MISRA Violation: START Msg(4:5087)-10 */
//#include CAN_MEMMAP_FILE
/* END Msg(4:5087)-10 */
/* END Msg(2:0832)-1 */

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Can_ResetController
*
* Description:   This function initializes the bit timing related settings
*                of a CAN controller.
*
* Inputs:        Controller:  CAN controller to be initialized
*                config: paramter config pointer
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, CAN_PUBLIC_CODE)Can_ResetController
(
    uint8 Controller
)
{

}
/*******************************************************************************
** Function Name         : Can_GetVersionInfo
**
** Service ID            : 0x07
**
** Description           : This function returns the version information of CAN
**                         driver component.
**
** Sync/Async            : Synchronous
**
** Re-entrancy           : Re-entrant
**
** Input Parameters      : None
**
** InOut Parameters      : None
**
** Output Parameters     : versioninfo
**
** Return parameter      : None
**
** Preconditions         : CanVersionInfoApi is configured as true.
**
** Global Variables      : None
**
** Functions invoked     : Det_ReportError
**
** Registers Used        : None
*******************************************************************************/
#if (CAN_VERSION_INFO_API == STD_ON)
/* MISRA Violation: START Msg(1:1503)-11 */
/* QAC Warning: START Msg(2:3227)-4 */
FUNC(void, CAN_RSCAN_PUBLIC_CODE) Can_GetVersionInfo(
  P2VAR(Std_VersionInfoType, AUTOMATIC, CAN_RSCAN_APPL_DATA) versioninfo)
/* END Msg(2:3227)-4 */
/* END Msg(1:1503)-11 */
{
  /* References: CAN_DDD_ACT_007 */
#if (CAN_DEV_ERROR_DETECT == STD_ON)
  /* Check if parameter passed is equal to Null pointer */
  if(NULL_PTR == versioninfo)
  {
    /* Report to DET  */
    (void)Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID,
                            CAN_GET_VERSIONINFO_SID, CAN_E_PARAM_POINTER);
    /* References: CAN_DDD_ACT_007_ERR001 */
  }
  else
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Copy the vendor Id */
    versioninfo->vendorID = CAN_VENDOR_ID;
    /* Copy the module Id */
    versioninfo->moduleID = CAN_MODULE_ID;
    /* Copy Software Major Version */
    versioninfo->sw_major_version = CAN_SW_MAJOR_VERSION;
    /* Copy Software Minor Version */
    versioninfo->sw_minor_version = CAN_SW_MINOR_VERSION;
    /* Copy Software Patch Version */
    versioninfo->sw_patch_version = CAN_SW_PATCH_VERSION;
  }
}
#endif /* (CAN_VERSION_INFO_API == STD_ON) */

/*******************************************************************************
** Function Name         : Can_Init
**
** Service ID            : 0x00
**
** Description           : This function initializes the static variables and
**                         CAN HW Unit global hardware settings for the further
**                         processing and initiates the setup of all CAN
**                         Controller specific settings.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non Re-entrant
**
** Input Parameters      : Config : Pointer to the configuration structure
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : None
**
** Preconditions         : None
**
** Global Variables Used : Can_GblInitialized,Can_GpConfig,
**                         Can_GpPCController, Can_GpPBController,
**                         Can_GpHohConfig, Can_GaaGlobalStateTransition,
**                         Can_GaaActiveControllers,
**                         Can_GaaGlobalIntCount, Can_GaaCtrlState
**                         Can_GaaHwAccessFlag
**
** Functions Invoked     : Det_ReportError, Dem_ReportErrorStatus,
**                         Can_SetStatus, Can_InitModule, Can_InitController,
**                         Can_GlobalModeChange
**
** Registers Used        : (CFD)GSTS, CFDGRMCFG, CFDGFDCFG, (CFD)RMNB,
**                         (CFD)GAFLCFG, (CFD)GCFG, (CFD)TMIECy,
**                         (CFD)GAFLECTR, (CFD)GAFLIDj, (CFD)GAFLMj,
**                         (CFD)GAFLP0_j, (CFD)GAFLP1_j,(CFD)CFCCk, 
**                         (CFD)TXQCCm, (CFD)RFCCx,(CFD)THLCCm,
**                         (CFD)Cm(N)CFG, CFDCmFDCFG, CFDCmDCFG,(CFD)CmCTR,
**                         EIC, (CFD)GCTR
**                         
*******************************************************************************/
/* MISRA Violation: START Msg(1:1503)-11 */
/* QAC Warning: START Msg(2:3227)-4 */
FUNC(void, CAN_RSCAN_PUBLIC_CODE) Can_Init(
  P2CONST(Can_ConfigType, CAN_VAR, CAN_RSCAN_APPL_CONST) Config)
/* END Msg(2:3227)-4 */
/* END Msg(1:1503)-11 */
{


}

/*******************************************************************************
** Function Name         : Can_ChangeBaudrate
**
** Service ID            : 0x0D
**
** Description           : This function set baudrate of CAN Controller.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non-Reentrant
**
** Input Parameters      : Controller : Controller ID
**                         Baudrate   : Baudrate in kbps, it must be in
**                                    baudrate configuration of this Controller.
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : Std_ReturnType(E_OK/E_NOT_OK)
**
** Preconditions         : CanDriver module must be initialized and
**                         the state of Controller must be CAN_T_STOP.
**
** Global Variables Used : Can_GaaCtrlState,
**                         Can_GpPBController, Can_GpPCController,
**                         Can_GaaRegs, Can_GaaMirrorChannelReg             
**
** Functions Invoked     : Can_CommonDetCheck, Det_ReportError,
**                         Can_SearchBaudrate, EcuM_SetWakeupEvent
**
** Registers Used        : (CFD)CmCFG, CFDCmDCFG, CFDCmFDCFG
*******************************************************************************/
#if (CAN_CHANGE_BAUDRATE_API == STD_ON)
/* MISRA Violation: START Msg(1:1503)-11 */
/* QAC Warning: START Msg(2:3227)-4 */
FUNC(Std_ReturnType, CAN_RSCAN_PUBLIC_CODE) Can_ChangeBaudrate(
  uint8 Controller, const uint16 Baudrate)
/* END Msg(2:3227)-4 */
/* END Msg(1:1503)-11 */
{

  return 0;
}
#endif

/*******************************************************************************
** Function Name         : Can_CheckBaudrate
**
** Service ID            : 0x0E
**
** Description           : This function checks the baud rates configured for
**                         CAN Controller.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Re-entrant
**
** Input Parameters      : Controller : Controller ID
**                         Baudrate   : Baudrate in kbps
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : Std_ReturnType(E_OK/E_NOT_OK)
**
** Preconditions         : CanDriver module must be initialized.
**
** Global Variables Used : None
**
** Functions Invoked     : Can_CommonDetCheck, Can_SearchBaudrate,
**                         Det_ReportError
**
** Registers Used        : None
*******************************************************************************/
#if (CAN_CHANGE_BAUDRATE_API == STD_ON)
/* MISRA Violation: START Msg(1:1503)-11 */
/* QAC Warning: START Msg(2:3227)-4 */
FUNC(Std_ReturnType, CAN_RSCAN_PUBLIC_CODE) Can_CheckBaudrate(
  uint8 Controller, const uint16 Baudrate)
/* END Msg(2:3227)-4 */
/* END Msg(1:1503)-11 */
{
  /* References: CAN_DDD_ACT_014 */
  Std_ReturnType LucReturnValue;
  uint32 LulBaudrateIndex;


  return(LucReturnValue);
}
#endif
/*******************************************************************************
** Function Name         : Can_SetBaudrate
**
** Service ID            : 0x0F
**
** Description           : This function set baudrate of CAN Controller.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Re-entrant for different Controller,
**                         Non Re-entrant for the same Controller
**
** Input Parameters      : Controller         : Controller ID
**                         BaudRateConfigID   : Baudrate ID
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : Std_ReturnType(E_OK/E_NOT_OK)
**
** Preconditions         : CanDriver module must be initialized.
**                         CanSetBaudrateApi is configured as true.
**                         The state of Controller must be CAN_T_STOP.
**
** Global Variables Used : Can_GaaCtrlState,Can_GpPBController
**                         Can_GpPCController, Can_GaaRegs,
**                         Can_GaaMirrorChannelReg          
**
** Functions Invoked     : Can_CommonDetCheck,Det_ReportError,
**                         Can_SearchBaudrateID
**
** Registers Used        : (CFD)CmCFG, CFDCmDCFG, CFDCmFDCFG
*******************************************************************************/
#if (CAN_SET_BAUDRATE_API == STD_ON)
/* MISRA Violation: START Msg(1:1503)-11 */
/* QAC Warning: START Msg(2:3227)-4 */
FUNC(Std_ReturnType, CAN_RSCAN_PUBLIC_CODE) Can_SetBaudrate(
  uint8 Controller, uint16 BaudRateConfigID)
/* END Msg(2:3227)-4 */
/* END Msg(1:1503)-11 */
{
  /* References: CAN_DDD_ACT_015 */
  Std_ReturnType LucReturnValue;


  return LucReturnValue;
}
#endif /* (CAN_SET_BAUDRATE_API == STD_ON) */

/*******************************************************************************
** Function Name         : Can_DisableControllerInterrupts
**
** Service ID            : 0x04
**
** Description           : This function disables all interrupts for this CAN
**                         Controller.
**                         If interrupt event occurs after this API, it is kept
**                         and handled after Can_EnableControllerInterrupts.
**                         Note that RxFIFO interruption is not disabled
**                         since it is global interruption.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Re-entrant
**
** Input Parameters      : Controller : Controller ID
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : The CAN Driver must be initialized.
**
** Global Variables Used : Can_GpPCController, Can_GaaCtrlState
**                         Can_GaaRegs, Can_GaaGlobalIntCount
**                         
** Functions Invoked     : Can_CommonDetCheck, CAN_ENTER_CRITICAL_SECTION,
**                         CAN_EXIT_CRITICAL_SECTION
**
** Registers Used        : EICn registers
*******************************************************************************/
/* MISRA Violation: START Msg(1:1503)-11 */
/* QAC Warning: START Msg(2:3227)-4 */
FUNC(void, CAN_RSCAN_PUBLIC_CODE) Can_DisableControllerInterrupts(
  uint8 Controller)
/* END Msg(2:3227)-4 */
/* END Msg(1:1503)-11 */
{

}

/*******************************************************************************
** Function Name         : Can_EnableControllerInterrupts
**
** Service ID            : 0x05
**
** Description           : This function enables all interrupts for this CAN
**                         Controller.
**                         If Can_DisableControllerInterrupt has been called
**                         multiple times, this function should be called
**                         same times to enable interrupts.
**                         If this function when interrupts already enabled,
**                         nothing is done.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Re-entrant
**
** Input Parameters      : Controller : Controller ID
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : The CAN Driver must be initialized.
**
** Global Variables Used : Can_GpPCController, Can_GaaCtrlState
**                         Can_GaaGlobalIntCount, Can_GaaRegs            
**
** Functions Invoked     : Can_CommonDetCheck, CAN_ENTER_CRITICAL_SECTION
**                         CAN_EXIT_CRITICAL_SECTION
**
** Registers Used        : EICn registers
*******************************************************************************/
/* MISRA Violation: START Msg(1:1503)-11 */
/* QAC Warning: START Msg(2:3227)-4 */
FUNC(void, CAN_RSCAN_PUBLIC_CODE) Can_EnableControllerInterrupts(
  uint8 Controller)
/* END Msg(2:3227)-4 */
/* END Msg(1:1503)-11 */
{

}

/*******************************************************************************
** Function Name         : Can_CheckWakeup
**
** Service ID            : 0x0B
**
** Description           : This function checks if a wakeup has occurred for the
**                         given controller.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non Re-entrant
**
** Input Parameters      : Controller
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : Can_ReturnType (CAN_OK / CAN_NOT_OK)
**
** Preconditions         : The CAN Driver must be initialized.
**                         CanWakeupFunctionalityAPI is configured as true.
**
** Global Variables Used : Can_GaaCtrlState, Can_GpPCController
**
** Functions Invoked     : Can_CommonDetCheck, EcuM_SetWakeupEvent
**
** Registers Used        : None
*******************************************************************************/
#if (CAN_CHECK_WAKEUP_API == STD_ON)
/* MISRA Violation: START Msg(1:1503)-11 */
/* QAC Warning: START Msg(2:3227)-4 */
FUNC(Can_ReturnType, CAN_RSCAN_PUBLIC_CODE) Can_CheckWakeup(uint8 Controller)
/* END Msg(2:3227)-4 */
/* END Msg(1:1503)-11 */
{
  /* References: CAN_DDD_ACT_011 */
  Can_ReturnType LenReturnValue;

  return(LenReturnValue);
}
#endif /* (CAN_CHECK_WAKEUP_API == STD_ON) */

#define CAN_RSCAN_STOP_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-1 */
/* MISRA Violation: START Msg(4:5087)-10 */
//#include CAN_MEMMAP_FILE
/* END Msg(4:5087)-10 */
/* END Msg(2:0832)-1 */

#define CAN_RSCAN_START_SEC_PRIVATE_CODE
/* QAC Warning: START Msg(2:0832)-1 */
/* MISRA Violation: START Msg(4:5087)-10 */
//#include CAN_MEMMAP_FILE
/* END Msg(4:5087)-10 */
/* END Msg(2:0832)-1 */

/*******************************************************************************
** Function Name       : Can_SetStatus
**
** Service ID          : Not Applicable
**
** Description         : This function updates Can_GblInitialized.
**                       The purpose of this function is to prevent the order of
**                       instructions being changed by the compiler.
**
** Sync/Async          : Synchronous
**
** Re-entrancy         : Non Re-entrant
**
** Input Parameters    : LblStatus: New status value
**
** InOut Parameters    : None
**
** Output Parameters   : None
**
** Return parameter    : None
**
** Preconditions       : None
**
** Global Variable     : None
**
** Function invoked    : None
**
** Registers Used      : None
*******************************************************************************/
static FUNC(void, CAN_RSCAN_PRIVATE_CODE) Can_SetStatus(
  const boolean LblStatus)
{
  /* References: CAN_DDD_ACT_045 */
  //Can_GblInitialized = LblStatus;
  /* References: CAN_DDD_ACT_045_GBL001 */
}

/*******************************************************************************
** Function Name         : Can_InitModule
**
** Service ID            : Not applicable
**
** Description           : Initialize RSCANn module.
**                         After this function, module becomes GLOBAL_RESET.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non Re-entrant
**
** Input Parameters      : LucUnit : Index of Can_GaaRegs for the target unit
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : When any error occurred CAN_TRUE, otherwise CAN_FALSE
**
** Preconditions         : Can_GpConfig must be initialized
**
** Global Variables Used : Can_GpConfig, Can_GaaRegs
**
** Functions Invoked     : Dem_ReportErrorStatus, Can_WaitRegisterChange,
**                         Can_GlobalModeChange
**
** Registers Used        : (CFD)GSTS, CFDGRMCFG, CFDGFDCFG, (CFD)RMNB,
**                         (CFD)GAFLCFG, (CFD)GCFG, (CFD)TMIECy,
**                         (CFD)GAFLECTR, (CFD)GAFLIDj, (CFD)GAFLMj,
**                         (CFD)GAFLP0_j, (CFD)GAFLP1_j,
**                         EIC registers, (CFD)GCTR
*******************************************************************************/
static FUNC(boolean, CAN_RSCAN_PRIVATE_CODE) Can_InitModule(
  const uint8 LucUnit)
{
  /* References: CAN_DDD_ACT_026 */
  boolean LblErrFlag;
  uint32 LulTimeoutDuration;
  Std_ReturnType LucTimeoutResult;
  uint32 LulCount;

  return LblErrFlag;
}

/*******************************************************************************
** Function Name         : Can_InitController
**
** Service ID            : Not applicable
**
** Description           : Initialize a Controller.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non Re-entrant
**
** Input Parameters      : LucCtrlIndex : Index of Controller
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : When any error occurred CAN_TRUE, otherwise CAN_FALSE
**
** Preconditions         : Can_GpConfig must be initialized
**                         Global state must be GLOBAL_RESET mode
**
** Global Variables Used : Can_GpPCController, Can_GpPBController
**                         Can_GaaActiveControllers, Can_GaaRegs
**                         Can_GaaMirrorChannelReg, Can_GpHohConfig
**                         Can_GaaMirrorHohReg
**
** Functions Invoked     : Dem_ReportErrorStatus, Can_ChannelModeChange
**
** Registers Used        : (CFD)CFCCk, (CFD)TXQCCm, (CFD)RFCCx,(CFD)THLCCm
**                         (CFD)Cm(N)CFG, CFDCmFDCFG, CFDCmDCFG, (CFD)CmCTR,
**                         EIC registers,(CFD)CmSTS
*******************************************************************************/
static FUNC(boolean, CAN_RSCAN_PRIVATE_CODE) Can_InitController(
  const uint8 LucCtrlIndex)
{
  /* References: CAN_DDD_ACT_027 */
  boolean LblErrFlag;
  uint8 LucUnit;
  uint8 LucCh;
  uint32 LulHohIndex;

  return LblErrFlag;
}

/*******************************************************************************
** Function Name         : Can_SearchBaudrate
**
** Service ID            : Not Applicable
**
** Description           : This function searches the baudrate configured for
**                         CAN Controller.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non Re-entrant
**
** Input Parameters      : LucCtrlIndex : Index of Controller config table
**                         LusBaudrate  : Baudrate in kbps
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : If specified baudrate is found, its index.
**                         Otherwise CAN_INALID_INDEX.
**
** Preconditions         : CanDriver module must be initialized.
**
** Global Variables Used : Can_GpPBController
**
** Functions Invoked     : None
**
** Registers Used        : None
*******************************************************************************/
#if (CAN_CHANGE_BAUDRATE_API == STD_ON)
static FUNC(uint32, CAN_RSCAN_PRIVATE_CODE) Can_SearchBaudrate(
  const uint8 LucCtrlIndex, const uint16 LusBaudrate)
{
  /* References: CAN_DDD_ACT_024 */
  P2CONST(Can_ControllerBaudrateConfigType, AUTOMATIC, CAN_RSCAN_APPL_CONST)
    LpBaudrateConfig;
  uint32 LulReturnValue;
  uint32 LulBaudrateConfigCount;
  uint32 LulCount;


  return(LulReturnValue);
}
#endif
/*******************************************************************************
** Function Name         : Can_SearchBaudrateID
**
** Service ID            : Not Applicable
**
** Description           : This function searches the baud rate configured for
**                         CAN Controller.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non Re-entrant
**
** Input Parameters      : LucCtrlIndex  : Index of Controller config table
**                         LusBaudrateID : Baudrate ID
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : If specified baudrate is found, its index.
**                         Otherwise CAN_INALID_INDEX.
**
** Preconditions         : CanDriver module must be initialized.
**
** Global Variables Used : Can_GpPBController
**
** Functions Invoked     : None
**
** Registers Used        : None
*******************************************************************************/
#if (CAN_SET_BAUDRATE_API == STD_ON)
static FUNC(uint32, CAN_RSCAN_PRIVATE_CODE) Can_SearchBaudrateID(
  const uint8 LucCtrlIndex, const uint16 LusBaudrateID)
{
  /* References: CAN_DDD_ACT_025 */
  P2CONST(Can_ControllerBaudrateConfigType, AUTOMATIC, CAN_RSCAN_APPL_CONST)
    LpBaudrateConfig;
  uint32 LulReturnValue;
  uint32 LulBaudrateConfigCount;
  uint32 LulCount;


  return(LulReturnValue);
}
#endif /* (CAN_SET_BAUDRATE_API == STD_ON) */

#define CAN_RSCAN_STOP_SEC_PRIVATE_CODE
/* QAC Warning: START Msg(2:0832)-1 */
/* MISRA Violation: START Msg(4:5087)-10 */
//#include CAN_MEMMAP_FILE
/* END Msg(4:5087)-10 */
/* END Msg(2:0832)-1 */

/*******************************************************************************
** Function Name         : Can_RAMTest
**
** Service ID            : 0x14
**
** Description           : This API used for testing one RAM page in
**                         the foreground.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non-Reentrant
**
** Input Parameters      : LulPageID
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : LucResult
**
** Preconditions         : All controllers must be in STOP state.
**
** Global Variables Used : Can_GaaRegs, Can_GulPageID(W), 
**                         Can_GblInitialized
**
** Function(s) invoked   : Can_RamTest_Checker_Algorithm(),
**                         Can_RamTst_WalkPath_Algorithm(),
**                         Can_RamTst_Set_RAMData(), Det_ReportError(),
**                         Can_GlobalModeChange(),Dem_ReportErrorStatus().
**
** Registers Used        : (CFD)GSTS, (CFD)GCTR,(CFD)GLOCKK, 
**                         (CFD)GTSTCTR, (CFD)GTSTCFG, (CFD)RPGACCr
**
*******************************************************************************/
#if (CAN_RAMTEST_API == STD_ON)
#define CAN_RSCAN_START_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-1 */
/* MISRA Violation: START Msg(4:5087)-10 */
//#include CAN_MEMMAP_FILE
/* END Msg(4:5087)-10 */
/* END Msg(2:0832)-1 */
/* MISRA Violation: START Msg(1:1503)-11 */
/* QAC Warning: START Msg(2:3227)-4 */
FUNC(Std_ReturnType, CAN_RSCAN_PUBLIC_CODE) Can_RAMTest(uint32 LulPageID)
/* END Msg(2:3227)-4 */
/* END Msg(1:1503)-11 */
{
  /* References: CAN_DDD_ACT_061 */
  /* Number of tested RAM cells */
  uint8 LucNumTestCell;
  uint8 LucUnit;
  /* Variable to store the Result of RAM Test in each cycle*/
  Std_ReturnType LucResult;
  uint32 LulTimeoutDuration;
  Std_ReturnType LucTimeoutResult;

  return(LucResult);
}
#define CAN_RSCAN_STOP_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-1 */
/* MISRA Violation: START Msg(4:5087)-10 */
//#include CAN_MEMMAP_FILE
/* END Msg(4:5087)-10 */
/* END Msg(2:0832)-1 */
#endif /* End of CAN_RAMTEST_API == STD_ON */

/*******************************************************************************
** Function Name         : Can_CheckHWConsistency
**
** Service ID            : 0x11
**
** Description           : This is CAN Driver Component support function.
**                         This API compares the control register values with
**                         its corresponding RAM mirror variable if
**                         CAN_RAM_MIRROR is enabled.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : LenHWConsistencyMode
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : LenRetConsistencyState
**
** Preconditions         : CAN_RAM_MIRROR should be enabled.
**                         CAN Driver must be initialized.
**
** Global Variables Used : Can_GblInitialized
**
** Functions invoked     : Det_ReportError, Can_CheckConsistencyStatic(),
**                         Can_CheckConsistencyDynamic().
**
** Registers Used        : RSCANnGAFLCFG0, RSCANnGAFLCFG1, RSCANnGCFG,
**                         RSCANnGAFLECTR, RSCANnRMNB, RSCFDnCFDGRMCFG
**                         RSCFDnCFDGAFLIDj, RSCFDnCFDGAFLMj,  RSCANnGAFLIDj,
**                         RSCANnGAFLMj, RSCFDnCFDGAFLP0_j, RSCFDnCFDGAFLP1_j,
**                         RSCANnGAFLP0j, RSCANnGAFLP1j.
**
*******************************************************************************/
#if (CAN_RAM_MIRROR == STD_ON)
#define CAN_RSCAN_START_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-1 */
/* MISRA Violation: START Msg(4:5087)-10 */
//#include CAN_MEMMAP_FILE
/* END Msg(4:5087)-10 */
/* END Msg(2:0832)-1 */
/* MISRA Violation: START Msg(1:1503)-11 */
/* QAC Warning: START Msg(2:3227)-4 */
FUNC(Std_ReturnType, CAN_RSCAN_PUBLIC_CODE) Can_CheckHWConsistency
                                (Can_HWConsistencyModeType LenHWConsistencyMode)
/* END Msg(2:3227)-4 */
/* END Msg(1:1503)-11 */
{
  /* References: CAN_DDD_ACT_058 */
  /* Declare the variable to store the DET return value */
  Std_ReturnType LenRetConsistencyState;
  LenRetConsistencyState = E_OK;

  return(LenRetConsistencyState);
}
#define CAN_RSCAN_STOP_SEC_PUBLIC_CODE
/* QAC Warning: START Msg(2:0832)-1 */
/* MISRA Violation: START Msg(4:5087)-10 */
//#include CAN_MEMMAP_FILE
/* END Msg(4:5087)-10 */
/* END Msg(2:0832)-1 */

/*******************************************************************************
** Function Name         : Can_CheckConsistencyStatic
**
** Service ID            : Not Applicable
**
** Description           : This is CAN Driver Component support function.
**                         This API compares the control register values with
**                         its corresponding RAM mirror variable if
**                         CAN_RAM_MIRROR is enabled.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : None
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : LenRetConsistencyState
**
** Preconditions         : CAN_RAM_MIRROR should be enabled.
**
** Global Variables Used : Can_GpConfig, Can_GaaRegs
**
** Functions invoked     : Det_ReportError
**
** Registers Used        : RSCANnGAFLCFG0, RSCANnGAFLCFG1, RSCANnGCFG,
**                         RSCANnGAFLECTR, RSCANnRMNB, RSCFDnCFDGRMCFG
**                         RSCFDnCFDGAFLIDj, RSCFDnCFDGAFLMj,  RSCANnGAFLIDj,
**                         RSCANnGAFLMj, RSCFDnCFDGAFLP0_j, RSCFDnCFDGAFLP1_j,
**                         RSCANnGAFLP0j, RSCANnGAFLP1j.
**
*******************************************************************************/
#define CAN_RSCAN_START_SEC_PRIVATE_CODE
/* QAC Warning: START Msg(2:0832)-1 */
/* MISRA Violation: START Msg(4:5087)-10 */
//#include CAN_MEMMAP_FILE
/* END Msg(4:5087)-10 */
/* END Msg(2:0832)-1 */
static FUNC(Std_ReturnType, CAN_RSCAN_PRIVATE_CODE)
                                  Can_CheckConsistencyStatic (void)
{

  return 0;
}

/*******************************************************************************
** Function Name         : Can_CheckConsistencyDynamic
**
** Service ID            : Not Applicable
**
** Description           : This is CAN Driver Component support function.
**                         This API compares the control register values with
**                         its corresponding RAM mirror variable if
**                         CAN_RAM_MIRROR is enabled.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : None
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : LenRetConsistencyState
**
** Preconditions         : CAN_RAM_MIRROR should be enabled.
**
** Global Variables Used : Can_GaaRegs,Can_GaaMirrorChannelReg
**                         Can_GaaMirrorHohReg,Can_GaaMirrorGlobalReg,
**                         Can_GpPCController, Can_GpHohConfig
**
** Functions invoked     : Det_ReportError, CAN_ENTER_CRITICAL_SECTION,
**                         CAN_EXIT_CRITICAL_SECTION.
**
** Registers Used        : RSCANnGAFLCFG0, RSCANnGAFLCFG1, RSCANnGCFG,
**                         RSCANnGAFLECTR, RSCANnRMNB, RSCFDnCFDGRMCFG
**                         RSCFDnCFDGAFLIDj, RSCFDnCFDGAFLMj,  RSCANnGAFLIDj,
**                         RSCANnGAFLMj, RSCFDnCFDGAFLP0_j, RSCFDnCFDGAFLP1_j,
**                         RSCANnGAFLP0j, RSCANnGAFLP1j.
**
*******************************************************************************/
static FUNC(Std_ReturnType, CAN_RSCAN_PRIVATE_CODE)
                                        Can_CheckConsistencyDynamic (void)
{
  /* References: CAN_DDD_ACT_060 */
  //P2CONST(Can_HohConfigType, AUTOMATIC, CAN_RSCAN_CONFIG_DATA) LpHoh;
  uint8 LucController;
  uint8 LucUnit;
  uint8 LucCh;
  uint32 LulHohIndex;
  Std_ReturnType LenRetValue;


  return LenRetValue;
}
#define CAN_RSCAN_STOP_SEC_PRIVATE_CODE
/* QAC Warning: START Msg(2:0832)-1 */
/* MISRA Violation: START Msg(4:5087)-10 */
//#include CAN_MEMMAP_FILE
/* END Msg(4:5087)-10 */
/* END Msg(2:0832)-1 */
#endif
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
