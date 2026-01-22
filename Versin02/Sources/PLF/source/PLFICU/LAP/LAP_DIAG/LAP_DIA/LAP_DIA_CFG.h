//******************************************************************************
// Company:      Johnson Controls Inc.
// -----------------------------------------------------------------------------
// Copyright:    This software is JCI property.
//               Duplication or disclosure without JCI written authorization
//               is prohibited.
// -----------------------------------------------------------------------------
// Project:      <STANDARD>
// Language:     C
// -----------------------------------------------------------------------------
// Component:    Diag On Can Management: UDS/DiagOnCAN implementation
//               this component is a the parameterization part of a template
//               which may be modify to implement project special requirements
//******************************************************************************


#ifndef I_LAP_DIAP_H
#define I_LAP_DIAP_H (1)

//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//
// #include <system_file_name.h>
// #include "project_file_name.h"
//------------------------------------------------------------------------------
#include "ARCH_CFG.h"

#ifdef cHeadIncludeType_Directly

#else

#endif

//------------------------------------------------------------------------------
// Data prefix for constant & data
//
// unsigned int {u8,u16,u32} / signed int {s8,s16,s32} 
// register size unsigned int {r} / float {f32,f64}  / s for struct 
// no prefix for other types.
//
//------------------------------------------------------------------------------
// Constant data
//
// #define cu16LAYCmpConstantName   ((U16) ConstantValueUL)
//------------------------------------------------------------------------------


//SoftVersion
#define cSw_Version_BCD								(0x03)
#define cSw_Revision_BCD							(0x01)

// Use this define to enable or disable response to broadcast request
// Normaly if there is response it is done using response service of standard diagnostic 
#define BROADCAST_REQUEST_RESPONSE_ENABLE


//=========================================================


//------------------------------------------------------------------------------
// Exported Macros
//
// #define LAYCmpMacroName(...)   (MacroDefinition)
//------------------------------------------------------------------------------

//Add here the project specific macro to execute actions before jump into the boot
#define  mLAPDiaAddSpecificCommand()
        /*Warning: if you have a high voltage supply you should wait the electronic has finished*/
        /*to switch his power supply to the battery supply before jump into the boot software*/
        /*#define  mLAPDiaAddSpecificCommand()\*/
        /*while (IsHighVoltageAlimStopped == cFalse)\*/
        /*{\*/
        /*               LDBRefreshWatchDog();\*/
        /*}*/

//Add here the project specific macro for BOOT jump condition check
#ifndef COMPILATION_NATIVE
//SysRs_11_CustomerDiagnosis_108, only 03 and 02 session can enter into 02 session.
//so here the code should check current session ID.
//TODO

// jy add 20190221 添加跳转进入loader的判定条件。
// jy 20190225 这个跳转判定条件自己定为1.在工作状态2.不在配置期间 两种条件进入。
#define	mIsPrgConditionOk  				(cFalse == mSERRead(U1Bit,IsSysBatAbNormal,Default))
#define mLAPDiaCheckBootJumpConditions()   mIsPrgConditionOk

//((cLAPDiaIdPRGSSession==LAPDiaGetActiveSession())||(cLAPDiaIdEXTDSSession==LAPDiaGetActiveSession()))

        /* for example:*/
        /*#define mLAPDiaCheckBootJumpConditions()\*/
        /*(   (mDATRead(U16Bit, DATMotorRPM, Default) == 0)\*/
        /*    && (mDATRead(U16Bit, DATCarSpeed, Default) == 0)\*/
        /*   && (mDATRead(U1Bit, DATAPCIsPresent,Default) == cFalse)\*/
        /*))*/
#else
#define mLAPDiaCheckBootJumpConditions() ((cLAPDiaIdPRGSSession==LAPDiaGetActiveSession())||(cLAPDiaIdEXTDSSession==LAPDiaGetActiveSession()))
#endif

// list here all supplier (JCI) sessions
#define mLAPDiaIsSupplierSession(Session)   ((Session) == cLAPDiaIdJCISession)

//------------------------------------------------------------------------------
// Exported type
//
// typedef Expression tLAYCmpTypeName;
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Exported data
//
// extern  tType   u8LAYCmpVariableName;
// extern  tType*  ps32LAYCmpVariableName; 
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Constant exported data
//
// extern const tType  s8LAYCmpVariableName;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Exported functions
//
// extern tReturnType LAYCmpFunctionName(tTypeArgument1 ArgumentName1, ... );
//------------------------------------------------------------------------------

#endif /* I_LAP_DIAP_H */
