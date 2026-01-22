
#ifndef I_LAP_SRI_H
#define I_LAP_SRI_H (1)

//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//
// #include <system_file_name.h>
// #include "project_file_name.h"
//------------------------------------------------------------------------------
#include "ARCH_CFG.h"


#include "LAP_SRI_INCLUDE.h"

#ifdef cHeadIncludeType_Directly
#include "LAP_DIA.h"
#else
#include ".\..\LAP_DIA\LAP_DIA.h"
#endif



//------------------------------------------------------------------------------
// Data prefix for constant & data: see coding guideline
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
extern void LAPSriOpenSession (void);
extern void LAPSriCloseSession(void);

extern void LAPSriRoutineControl(void);
extern void LAPSriEcuReset(void);
extern void LAPSriEcuResetCallBackDiagFrameSending(void);

#endif   /* I_LAP_SRI_H */

