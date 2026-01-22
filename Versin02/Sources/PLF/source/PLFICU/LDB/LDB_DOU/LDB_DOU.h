

//----  Mono-inclusion Definition-----
#ifndef I_LDB_DOU_H
#define I_LDB_DOU_H 1

/*-------------------------------------------------------------------------
  Included files to resolve specific definitions in this file

  #include <system_file_name.h>
  #include "project_file_name.h"
  -------------------------------------------------------------------------*/

#include "ARCH_CFG.h"

#ifdef cHeadIncludeType_Directly
#include "ldb.h"
#include "LDB_DOU_LIFE.h"
#else
#include ".\..\LDB\LDB_API\ldb.h"
#include "LDB_DOU_LIFE.h"
#endif
/*-------------------------------------------------------------------------
  Constant data

  #define cCMPConstantName   ((tType) ConstantValue)
  -------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
  Exported Macros

  #define mCMPMacroName   (MacroDefinition)
  -------------------------------------------------------------------------*/ 

#define mLDBDOUInit()                          (LDBDouInit())
#define mLDBDOULeaveSleepMode()                LDBDouLeaveSleepMode()
#define mLDBDOUEnterSleepMode()                LDBDouEnterSleepMode()

#define mLDBDOUSendWithoutAddr(pMsg)    LDBDouSendWithoutAddr((pMsg))
#define mLDBDOUControl(Ctrl)            LDBDouControl((Ctrl))
#define mLDBDOUSendWithAddr(Addr, pMsg)          LDBDouSendWithAddr((Addr), (pMsg))


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

extern void LDBDouInit(void);
extern void LDBDouSendWithoutAddr(tMsg* pMsg);
extern void LDBDouControl(tCtrl Ctrl);
extern void LDBDouLeaveSleepMode();
extern void LDBDouEnterSleepMode();
extern void LDBDouSendWithAddr(tAddress Addr, tMsg *pMsg );



#endif
