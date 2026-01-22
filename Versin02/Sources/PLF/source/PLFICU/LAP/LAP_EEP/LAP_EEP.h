//******************************************************************************
// Copyright:    This software is JYD property.
//               Duplication or disclosure without JYD written authorization
//               is prohibited.
// -----------------------------------------------------------------------------
// Project:      BCM313
// Language:     C
// -----------------------------------------------------------------------------
// Component:  init the EEP content with default values
//                       
// -----------------------------------------------------------------------------
//******************************************************************************
// This line is used to separate code and file header.This is begin.
//*****************************BEGIN_NOMOVE*************************************
// Time:2016-09-19 09:31:07
// 1: change the group name
//*****************************END_NOMOVE***************************************
// This line is used to separate code and file header. This is last line.
//******************************************************************************

#ifndef I_lap_eep_H
#define I_lap_eep_H (1)

//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//
// #include <system_file_name.h>
// #include "project_file_name.h"
//------------------------------------------------------------------------------
#include "ARCH_CFG.h"


#include "LAP_EEP_INCLUDE.h"
#include "LAP_EEP_CFG.h"
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
// Exported Macros
//
// #define LAYCmpMacroName(...)   (MacroDefinition)
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Exported functions
//
// extern tReturnType LAYCmpFunctionName(tTypeArgument1 ArgumentName1, ... );
//------------------------------------------------------------------------------

extern void LAPEepInitEEPIng(void);extern BOOL LAPEepIsExitNow(void);extern void LAPEepInitEEPOver(void);
extern BOOL LAPEepIsInitEEPOver(void);
extern BOOL LAPEepIsNeedInitEEP(void);
extern void LAPEepWaitForExit(void);extern BOOL LAPEepInitDelay60s(void);
extern void LAPEepGraphInit(void);/* [EXPORTED_FUNCTIONS_END] */


#endif   /* I_lap_eep_H */

