

#ifndef _LDB_SUP_H_
#define _LDB_SUP_H_

//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//
// #include <system_file_name.h>
// #include "project_file_name.h"
//------------------------------------------------------------------------------

#include "ARCH_CFG.h"

#ifdef cHeadIncludeType_Directly
#include "LDB.h"
#include "BSP_SUP_EXPORT.h"
#include "BSP_TIM_EXPORT.h"
#else
#include ".\..\LDB_API\LDB.h"
#include ".\..\..\..\BSP\BSP_SUP\BSP_SUP_EXPORT.h"
#include ".\..\..\..\BSP\BSP_TIM\BSP_TIM_EXPORT.h"
#include ".\..\..\..\BSP\BSP_WDOG\BSP_WDOG_EXPORT.h"
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
extern void LDBRefreshWatchDog(void);
extern void LDBSupInit(void);
extern void LDBSupEnterSleepMode(void);
extern void LDBSupLeaveSleepMode(void);
extern void LDBSupStart(void);
extern void LDBSupEndInit();
extern void LDBSuppreInit();

#endif   /* I_SUP_H */
