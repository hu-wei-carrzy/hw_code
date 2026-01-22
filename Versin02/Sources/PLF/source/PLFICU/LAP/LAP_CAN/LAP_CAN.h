//******************************************************************************
// Company:      Johnson Controls Inc.
// -----------------------------------------------------------------------------
// Copyright:    This software is JCI property.
//               Duplication or disclosure without JCI written authorization
//               is prohibited.
// -----------------------------------------------------------------------------
// Project:      <PROJECT>
// Language:     C
// -----------------------------------------------------------------------------
// Component:    <Comments about the component (role, algorithm, structure, 
//               limitations, defined tasks and events...)>
// -----------------------------------------------------------------------------
//******************************************************************************

#ifndef I_LAP_CAN_H
#define I_LAP_CAN_H (1)

//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//
// #include <system_file_name.h>
// #include "project_file_name.h"
//------------------------------------------------------------------------------
#include "ARCH_CFG.h"
#include "LAP_CAN_INCLUDE.h"
#include "LAP_CAN_CFG.h"

#ifdef cHeadIncludeType_Directly
#include "DAT_PANx.h"
#else
#include ".\..\..\SCC2Gen\GEN\DAT_PANx.h"
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
extern void SilentNM(void);
extern void TalkNM(void);
extern void StopNM(void);
extern void LAPCanWakeUp(void);


//export from OsekNm_App.c of J1939 model
extern unsigned char ApplIsCAN0BufOff(void);
extern unsigned char ApplIsCAN1BufOff(void);

extern void LAPCANActiveProcess(void);extern void LAPCANBatAbnormalProcess(void);extern void LAPCANDiagProcess(void);extern void LAPCANInit(void);extern BOOL LAPCANIsActiveMod(void);
extern BOOL LAPCANIsBatAbnormal(void);
extern BOOL LAPCANIsDiagMod(void);
extern BOOL LAPCANIsRuninMod(void);
extern BOOL LAPCANIsSelfChkMod(void);
extern BOOL LAPCANIsWorkMod(void);
extern void LAPCANSelfChkEndProcess(void);extern void LAPCANSelfChkProcess(void);extern void LAPCANWorkProcess(void);
/* [EXPORTED_FUNCTIONS_END] */


#endif   /* I_LAP_CAN_H */

