

#ifndef I_RST_H
#define I_RST_H

//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//
// #include <system_file_name.h>
// #include "project_file_name.h"
//------------------------------------------------------------------------------
#include "ARCH_CFG.h"

#ifdef cHeadIncludeType_Directly
#include "ldb.h"
#include "LDB_RST_LIFE.h"
#include "BSP_RST.h"
#else
#include ".\..\LDB\LDB_API\ldb.h"
#include ".\..\..\..\BSP\BSP_RST\BSP_RST.h"
#include "LDB_RST_LIFE.h"
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
#define mLDBRSTInit()                       LDBRstInit()
#define mLDBRSTReceiveWithoutAddr(Msg)   	LDBRstReceiveWithoutAddr((Msg))


//------------------------------------------------------------------------------
// Exported functions
//
// extern tReturnType LAYCmpFunctionName(tTypeArgument1 ArgumentName1, ... );
//------------------------------------------------------------------------------
extern	void	LDBRstInit(void);
extern	void	LDBRstReceiveWithoutAddr(tMsg * pMsg);



#endif   // I_RST_H
