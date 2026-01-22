/*
 * LDB_BLDC.h
 *
 *  Created on: 2025Äê5ÔÂ8ÈÕ
 *      Author: lenovo
 */

//----  Mono-inclusion Definition-----
#ifdef I_LDB_BLDC_H
#else
#define I_LDB_BLDC_H 1


/*-------------------------------------------------------------------------
  Included files to resolve specific definitions in this file

  #include <system_file_name.h>
  #include "project_file_name.h"
  -------------------------------------------------------------------------*/
#include "ARCH_CFG.h"

#ifdef cHeadIncludeType_Directly

#include "ldb.h"

#include <PLF/source/PLFICU/LDB/LDB_ICU/LDB_BLDC_LIFE.h>
#include <PLF/source/PLFICU/LDB/LDB_ICU/LDB_BLDC_CFG.h>
#include "BSPBSDC_EXPORT.h"
#include "ldb_tos.h"
#else

#include ".\..\LDB\LDB_API\ldb.h"
#include <PLF/source/PLFICU/LDB/LDB_BLDC/LDB_BLDC_LIFE.h>
#include <PLF/source/PLFICU/LDB/LDB_BLDC/LDB_BLDC_CFG.h>
#include ".\..\LDB\LDB_API\ldb_tos.h"
#endif



/*-------------------------------------------------------------------------
  Constant data

  #define cCMPConstantName   ((tType) ConstantValue)
  -------------------------------------------------------------------------*/
#define mLDBBLDCInit						LDBBLDCInit
//#define mLDBBLDCLeaveSleepMode			LDBBLDCLeaveSleepMode
//#define mLDBBLDCEnterSleepMode			LDBBLDCEnterSleepMode

//#define mLDBBLDCReceiveWithoutAddr   		LDBBLDCReceiveWithoutAddr
//#define mLDBBLDCReceiveWithAddr  			LDBBLDCReceiveWithAddr
//#define mLDBBLDCControl                	LDBBLDCControl






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

extern void LDBBLDCInit(void);
extern void LDBBLDCReceiveWithoutAddr(tMsg* pMsg);
extern void LDBBLDCReceiveWithAddr(tAddress addr,tMsg* pMsg);
extern void LDBBLDCControl(tCtrl Ctrl);
extern void LDBBLDCLeaveSleepMode(void);
extern void LDBBLDCEnterSleepMode(void);


#endif /* PLF_SOURCE_PLFICU_LDB_LDB_BSDC_LDB_BSDC_H_ */
