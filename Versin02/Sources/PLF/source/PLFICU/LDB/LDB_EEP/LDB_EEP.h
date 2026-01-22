//******************************************************************************
// Copyright:    This software is JYD property.
//               Duplication or disclosure without JYD written authorization
//               is prohibited.
// -----------------------------------------------------------------------------
// Project:      BCM313
// Language:     C
// -----------------------------------------------------------------------------
// Component:  define the EEP interface with MCU related function.
//                       
// -----------------------------------------------------------------------------
//******************************************************************************
// This line is used to separate code and file header.This is begin.
//*****************************BEGIN_NOMOVE*************************************
// Time:2016-09-19 09:31:07
// 1: because now EEP is OK, now enable the EEP related macros
//*****************************END_NOMOVE***************************************
// This line is used to separate code and file header. This is last line.
//******************************************************************************

//----  Mono-inclusion Definition-----
#ifndef I_LDB_EEP_H
#define I_LDB_EEP_H 1


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

#include "LDB_EEP_LIFE.h"

/*-------------------------------------------------------------------------
  Constant data

  #define cCMPConstantName   ((tType) ConstantValue)
  -------------------------------------------------------------------------*/

#define mLDBEEPInit                     LDBEepInit
#define mLDBEEPSendWithAddr             LDBEepSendWithAddr
#define mLDBEEPReceiveWithAddr          LDBEepReceiveWithAddr
#define mLDBEEPControl                  LDBEepControl






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
extern void LDBEepInit(void);
extern void LDBEepSendWithAddr(tAddress ,tMsg* );
extern void LDBEepReceiveWithAddr(tAddress ,tMsg* );
extern void LDBEepControl(tCtrl );
extern void LDBCallBackTxWithAddr (tChannel Channel, tAddress Addr, tStatus Status);
extern void LDBCallBackRxWithAddr (tChannel Channel, tAddress Addr, tStatus Status);
extern void LDBCallBackEndControl (tChannel Channel, tCtrl Ctrl,tStatus Status);
#endif
