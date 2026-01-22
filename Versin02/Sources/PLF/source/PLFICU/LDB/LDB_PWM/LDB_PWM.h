

//----  Mono-inclusion Definition-----
#ifdef I_LDB_PWM_H
#else
#define I_LDB_PWM_H 1


/*-------------------------------------------------------------------------
  Included files to resolve specific definitions in this file

  #include <system_file_name.h>
  #include "project_file_name.h"
  -------------------------------------------------------------------------*/
#include "ARCH_CFG.h"

#ifdef cHeadIncludeType_Directly

#include "ldb.h"
 
#include <PLF/source/PLFICU/LDB/LDB_ICU/LDB_ICU_LIFE.h>
#include <PLF/source/PLFICU/LDB/LDB_ICU/LDB_ICU_CFG.h>
#include "BSP_DIO_EXPORT.h"
#include "ldb_tos.h"
#else

#include ".\..\LDB\LDB_API\ldb.h"
#include <PLF/source/PLFICU/LDB/LDB_PWM/LDB_PWM_LIFE.h>
#include <PLF/source/PLFICU/LDB/LDB_PWM/LDB_PWM_CFG.h>
#include ".\..\LDB\LDB_API\ldb_tos.h"
#endif



/*-------------------------------------------------------------------------
  Constant data

  #define cCMPConstantName   ((tType) ConstantValue)
  -------------------------------------------------------------------------*/
#define mLDBPWMInit						LDBPWMInit
//#define mLDBICULeaveSleepMode			LDBICULeaveSleepMode
//#define mLDBICUnterSleepMode			LDBICUEnterSleepMode

//#define mLDBICUReceiveWithoutAddr   	LDBICUReceiveWithoutAddr
//#define mLDBICUReceiveWithAddr  		LDBICUReceiveWithAddr
//#define mLDBICUControl                	LDBICUControl






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

extern void LDBPWMInit(void);
extern void LDBPWMReceiveWithoutAddr(tMsg* pMsg);
extern void LDBPWMReceiveWithAddr(tAddress addr,tMsg* pMsg);
extern void LDBPWMControl(tCtrl Ctrl);
extern void LDBPWMLeaveSleepMode(void);
extern void LDBPWMEnterSleepMode(void);
#endif
