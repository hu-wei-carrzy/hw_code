

/*-------------------------------------------------------------------------
  Includes non re entry
  -------------------------------------------------------------------------*/
#ifndef I_DAT_DOU_H
#define I_DAT_DOU_H

/*--------------------------------------------------------------------------
  Included files to resolve specific definitions in this file

  #include <system_file_name.h>
  #include "project_file_name.h"
  --------------------------------------------------------------------------*/
#define cDAT_AD_DATAINCLUDE

#include "ARCH_CFG.h"
#ifdef cHeadIncludeType_Directly
#include "DAT_DOU_CFG.h"
#include "DAT_DOUx.h"

#else
#include "DAT_DOU_CFG.h"
#include ".\..\..\..\SCC2Gen\GEN\DAT_DOUx.h"

#endif

#include "DAT_DOU_INCLUDE.h"
/*--------------------------------------------------------------------------
  Constant data

  #define cCMPConstantName   ((tType) ConstantValue)
  --------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------
  Exported Macros

  #define mCMPMacroName   (MacroDefinition)
  --------------------------------------------------------------------------*/ 

// Launch logical refresh
#define mDATDouRefreshOutput() TOSActivateTask(cTOSTaskID_WriteLogical)

/*--------------------------------------------------------------------------
  Exported types

  struct  sCMPStructureName { ... };
  union   uCMPUnionName { ... };
  enum    eCMPEnumerationName { ... };
  typedef Expression tCMPTypeName;

  --------------------------------------------------------------------------*/
typedef U8 tDATDou_ByteIndex;
typedef U8 tDATDou_BitIndex;

typedef U8 tDATDouState;

/*--------------------------------------------------------------------------
  Exported data

  extern  tType   CMPVariableName;
  extern  tType*  pCMPVariableName; 
  --------------------------------------------------------------------------*/ 
extern U8 DATDouOutputBuffer[cDATDouOutputBufferSizeInBytes];

/*--------------------------------------------------------------------------
  Constant exported data

  extern const tType  CMPVariableName;
  --------------------------------------------------------------------------*/ 

/*--------------------------------------------------------------------------
  Exported functions

  extern tReturnType CMPFunctionName(tTypeArgument1 ArgumentName1, ... );
  --------------------------------------------------------------------------*/ 
extern void DATDouInit(const U8*pBuffer);

extern void DATDouEnterActiveState(void);
extern void DATDouEnterSleepMode(void);

// DAT_DOU's Task
extern void DATDouRefreshOutputTask(void);

// LDB's call-backs
extern void DATDouCallBackEndCtrl(tCtrl Ctrl, tStatus Statut);
extern void DATDouCallBackTxWithoutAddr(tStatus Statut);

// DAT_POU's Call-back
extern void DATPouPrepareRefresh(void);
extern void DATDouRegistSysCheckTask(void);
extern void DATDouCtrl(tCtrl Ctrl);
extern void DATDouOutPut(tAddress tLDBDouAdr,U8 u8Par);
/*-------------------------------------------------------------------------
  End of includes non re entry
  -------------------------------------------------------------------------*/
#endif  /* I_DAT_DOU_H */

