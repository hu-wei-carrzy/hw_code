

#ifndef I_DAT_DDI
#define I_DAT_DDI

//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//
// #include <system_file_name.h>
// #include "project_file_name.h"
//------------------------------------------------------------------------------

#include "ARCH_CFG.h"
#ifdef cHeadIncludeType_Directly
#include "DAT_DDB.h"
#else
#include ".\..\DAT_DDB\DAT_DDB.h"
#endif
#include "DAT_DDI_INCLUDE.h"

//------------------------------------------------------------------------------
// Data prefix for constant & data: see coding guideline
//
//------------------------------------------------------------------------------
// Constant data
//
// #define cu16DATCmpConstantName   ((U16) ConstantValueUL)
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Exported Macros
//
// #define DATCmpMacroName(...)   (MacroDefinition)
//------------------------------------------------------------------------------

#define mDATReadU8BitDTCQueryResultDefault()                                   \
    (DATDdiGetQueryResult())



//------------------------------------------------------------------------------
// Exported types
//
// typedef Expression    tTypeName;
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Exported data
//
// extern  tType   u8DATCmpVariableName;
// extern  tType*  ps32DATCmpVariableName;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Constant exported data
//
// extern const tType  s8DATCmpVariableName;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Exported functions
//
// extern tReturnType DATCmpFunctionName(tTypeArgument1 ArgumentName1, ... );
//------------------------------------------------------------------------------




extern U8 DATDdiGetQueryResult(void);
extern void DATDdiEnterActiveState(void);
extern U16  DATDdiGetQueryDTCCount(void);

#endif  //I_DAT_DDI

