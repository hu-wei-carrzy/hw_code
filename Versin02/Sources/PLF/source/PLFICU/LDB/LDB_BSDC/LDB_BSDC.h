/*
 * LDB_BSDC.h
 *
 *  Created on: 2025Äê5ÔÂ8ÈÕ
 *      Author: lenovo
 */

//----  Mono-inclusion Definition-----
#ifdef I_LDB_BSDC_H
#else
#define I_LDB_BSDC_H 1


/*-------------------------------------------------------------------------
  Included files to resolve specific definitions in this file

  #include <system_file_name.h>
  #include "project_file_name.h"
  -------------------------------------------------------------------------*/
#include "ARCH_CFG.h"

#ifdef cHeadIncludeType_Directly

#include "ldb.h"

#include <PLF/source/PLFICU/LDB/LDB_ICU/LDB_BSDC_LIFE.h>
#include <PLF/source/PLFICU/LDB/LDB_ICU/LDB_BSDC_CFG.h>
#include "BSPBSDC_EXPORT.h"
#include "ldb_tos.h"
#else

#include ".\..\LDB\LDB_API\ldb.h"
#include <PLF/source/PLFICU/LDB/LDB_BSDC/LDB_BSDC_LIFE.h>
#include <PLF/source/PLFICU/LDB/LDB_BSDC/LDB_BSDC_CFG.h>
#include ".\..\LDB\LDB_API\ldb_tos.h"
#endif



/*-------------------------------------------------------------------------
  Constant data

  #define cCMPConstantName   ((tType) ConstantValue)
  -------------------------------------------------------------------------*/
#define mLDBBSDCInit						LDBBSDCInit
//#define mLDBBSDCLeaveSleepMode			LDBBSDCLeaveSleepMode
//#define mLDBBSDCEnterSleepMode			LDBBSDCEnterSleepMode

//#define mLDBBSDCReceiveWithoutAddr   		LDBBSDCReceiveWithoutAddr
//#define mLDBBSDCReceiveWithAddr  			LDBBSDCReceiveWithAddr
//#define mLDBBSDCControl                	LDBBSDCControl






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

extern void LDBBSDCInit(void);
extern void LDBBSDCReceiveWithoutAddr(tMsg* pMsg);
extern void LDBBSDCReceiveWithAddr(tAddress addr,tMsg* pMsg);
extern void LDBBSDCControl(tCtrl Ctrl);
extern void LDBBSDCLeaveSleepMode(void);
extern void LDBBSDCEnterSleepMode(void);


#endif /* PLF_SOURCE_PLFICU_LDB_LDB_BSDC_LDB_BSDC_H_ */
