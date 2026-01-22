
#ifndef  I_LDB_AD_CFG_H_
#define  I_LDB_AD_CFG_H_

/*-------------------------------------------------------------------------
  Included files to resolve specific definitions in this file

  #include <system_file_name.h>
  #include "project_file_name.h"
  -------------------------------------------------------------------------*/
#include "ARCH_CFG.h"

#ifdef cHeadIncludeType_Directly
#include "ldb.h"
#else
#include ".\..\LDB\LDB_API\ldb.h"
#endif



// --------------------------------------------------------------
//     Channel LDB_AD
// --------------------------------------------------------------
//add your code here


/*-------------------------------------------------------------------------
  Constant data

  #define cCMPConstantName   ((tType) ConstantValue)
  -------------------------------------------------------------------------*/

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

#endif
