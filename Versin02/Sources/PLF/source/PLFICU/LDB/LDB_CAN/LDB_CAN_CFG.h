
#ifndef  I_LDB_CAN_CFG_H_
#define  I_LDB_CAN_CFG_H_

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
//     Channel LDB_CAN
// --------------------------------------------------------------
//add your code here


/*-------------------------------------------------------------------------
  Constant data

  #define cCMPConstantName   ((tType) ConstantValue)
  -------------------------------------------------------------------------*/
#define cLogicCAN0     ((U8)0U)
#define cLogicCAN1     ((U8)1U)
#define cLogicCAN2     ((U8)2U)

#define cU8MCUCAN0     ((U8)0U)
#define cU8MCUCAN1     ((U8)1U)
#define cU8MCUCAN2     ((U8)2U)

#define cU8LogicCANMaxNum    ((U8)3U)
#define cU8MCUCANMaxNum    ((U8)3U)

#define cLogicCAN0Used
#define cLogicCAN1Used
#define cLogicCAN2Used
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
