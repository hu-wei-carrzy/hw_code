#ifndef I_LDB_BUZ_CFG_H_
#define I_LDB_BUZ_CFG_H_ (1)

//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//
// #include <system_file_name.h>
// #include "project_file_name.h"
//------------------------------------------------------------------------------

#include "ARCH_CFG.h"

#ifdef cHeadIncludeType_Directly
#include "ldb.h"

#else
#include ".\..\LDB\LDB_API\ldb.h"

#endif

/*-------------------------------------------------------------------------
  Constant data

  #define cCMPConstantName   ((tType) ConstantValue)
  -------------------------------------------------------------------------*/
#define cBuzChannel_0			0
#define cBuzChannel_1			1

#define cBuzOutpin_SGO0			0
#define cBuzOutpin_SGO1			1
#define cBuzOutpin_SGO0R		2
#define cBuzOutpin_SGO1R		3

#define cBuzChannel_x			cBuzChannel_0		//you should select the right channel accroding to real shematic
#define cBuzOutpin_x			cBuzOutpin_SGO0		//you should select the right channel accroding to real shematic


#define	cLDBBuzAddr_IsBuzStop						((tAddress)0x00)



/*-------------------------------------------------------------------------
  Exported Macros

  #define mCMPMacroName   (MacroDefinition)
  -------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
  Exported type

  struct  sCMPStructureName { ... };
  union   uCMPUnionName { ... };
  enum    eCMPEnumerationName { ... };
  typedef Expression tCMPTypeName;

  -------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
  Exported data

  extern  tType   CMPVariableName;
  extern  tType*  pCMPVariableName;
  -------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
  Constant exported data

  extern const tType  CMPVariableName;
  -------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
  Exported functions

  extern tReturnType CMPFunctionName(tTypeArgument1 ArgumentName1, ... );
  -------------------------------------------------------------------------*/


#endif   // _LDB_BUZ_CFG_H_
// ============================================================================
//                                  EOF
// ============================================================================
