

//----  Mono-inclusion Definition-----
#ifdef I_LDB_DIN_H
#else
#define I_LDB_DIN_H 1


/*-------------------------------------------------------------------------
  Included files to resolve specific definitions in this file

  #include <system_file_name.h>
  #include "project_file_name.h"
  -------------------------------------------------------------------------*/
#include "ARCH_CFG.h"

#ifdef cHeadIncludeType_Directly

#include "ldb.h"
 
#include "LDB_DIN_LIFE.h"
#include "LDB_DIN_CFG.h"
#include "BSP_DIO_EXPORT.h"
#include "ldb_tos.h"
#else

#include ".\..\LDB\LDB_API\ldb.h"
#include "LDB_DIN_LIFE.h"
#include "LDB_DIN_CFG.h"
#include ".\..\..\..\BSP\BSP_DIO\BSP_DIO_EXPORT.h"
#include ".\..\LDB\LDB_API\ldb_tos.h"
#endif



/*-------------------------------------------------------------------------
  Constant data

  #define cCMPConstantName   ((tType) ConstantValue)
  -------------------------------------------------------------------------*/
#define mLDBDINInit()						LDBDinInit()
#define mLDBDINLeaveSleepMode()				LDBDinLeaveSleepMode()
#define mLDBDINEnterSleepMode()				LDBDinEnterSleepMode()

#define mLDBDINReceiveWithoutAddr(pMsg)     LDBDinReceiveWithoutAddr((pMsg))
#define mLDBDINReceiveWithAddr(Addr,pMsg)   LDBDinReceiveWithAddr((Addr),(pMsg))
#define mLDBDINControl(Ctrl)                LDBDinControl((Ctrl))






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

extern void LDBDinInit(void);
extern void LDBDinReceiveWithoutAddr(tMsg* pMsg);
extern void LDBDinReceiveWithAddr(tAddress addr,tMsg* pMsg);
extern void LDBDinControl(tCtrl Ctrl);
extern void LDBDinLeaveSleepMode(void);
extern void LDBDinEnterSleepMode(void);
#endif
