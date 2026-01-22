/*
 * LDB_BSDC_CFG.h
 *
 *  Created on: 2025Äê5ÔÂ8ÈÕ
 *      Author: lenovo
 */

#ifndef LDB_BLDC_LDB_BSDC_CFG_H_
#define LDB_BLDC_LDB_BSDC_CFG_H_

 /*Included files to resolve specific definitions in this file

  #include <system_file_name.h>
  #include "project_file_name.h"
  -------------------------------------------------------------------------*/

#include "ARCH_CFG.h"

#ifdef cHeadIncludeType_Directly
#include "ldb.h"
#include "BSP_DIO.h"
#else
#include ".\..\LDB\LDB_API\ldb.h"
#include ".\..\..\..\BSP\BSP_BLDC\MOTORA_control.h"
#endif

// --------------------------------------------------------------
//     Channel Din
// --------------------------------------------------------------



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

#endif /* PLF_SOURCE_PLFICU_LDB_LDB_BSDC_LDB_BSDC_CFG_H_ */
