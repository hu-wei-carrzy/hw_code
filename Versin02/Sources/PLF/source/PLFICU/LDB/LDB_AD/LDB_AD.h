//----  Mono-inclusion Definition-----
#ifndef I_LDB_AD_H
#define I_LDB_AD_H 1


/*-------------------------------------------------------------------------
  Included files to resolve specific definitions in this file

  #include <system_file_name.h>
  #include "project_file_name.h"
  -------------------------------------------------------------------------*/

#include "ARCH_CFG.h"

#ifdef cHeadIncludeType_Directly
#include "ldb.h"
#include "BSP_AD.h"
#else
#include ".\..\LDB\LDB_API\ldb.h"
#include ".\..\..\..\BSP\BSP_AD\BSP_AD.h"
#endif

#include "LDB_AD_LIFE.h"
#include "LDB_AD_CFG.h"

typedef struct
{
   U8 index;
   U8 chn ;
   U16 adBuff;

} ADchnCfg;
/*-------------------------------------------------------------------------
  Constant data

  #define cCMPConstantName   ((tType) ConstantValue)
  -------------------------------------------------------------------------*/
#define mLDBADInit						LDBADInit
//#define mLDBADLeaveSleepMode()				//add your code here according to real situation
//#define mLDBADEnterSleepMode()				//add your code here according to real situation
#define mLDBADControl                     LDBADControl
#define mLDBADSendWithoutAddr             LDBADSendWithoutAddr
#define mLDBADReceiveWithAddr             LDBADReceiveWithAddr




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

extern void LDBADInit(void);
extern void LDBADReceiveWithoutAddr(tMsg* pMsg);
extern void LDBADReceiveWithAddr(tAddress addr,tMsg* pMsg);
extern void LDBADControl(tCtrl Ctrl);
extern void LDBADSendWithoutAddr(tMsg* pMsg);
#endif
