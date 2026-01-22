/*============================================================================
  Project ......................... PROJET
  Component ....................... DATParam.h
  File revision.................... $
  Last modification date .......... $Modtime:   Aug 12 2014 16:41:54  $
  -------------------------------------------------------------------------
  Copyright ... This software is JCI property. Duplication or
                disclosure is prohibited without JCI written permission
  -------------------------------------------------------------------------

  - This file should only contain data useful to the programmer to use
    this component
  - Component exported macros, constants and types are defined in this file
  - Component exported variables and functions are declared in this file
    with the "extern" key word

  -------------------------------------------------------------------------
  paramdat.h file review :

   $

  ==========================================================================*/
#ifndef I_DATPARAM_H
#define I_DATPARAM_H (1)

/*-------------------------------------------------------------------------
  Included files to resolve specific definitions in this file

  #include <system_file_name.h>
  #include "project_file_name.h"
  -------------------------------------------------------------------------*/

// TODO : Add the header file of DAT Components
//#include "DATComponent.h"
//System series
#include "DAT_CPU.H"
#include "DAT_PIN.H"
#include "DAT_POU.H"
#include "DAT_PAN.H"
#include "DAT_BAT.h"

#include "DAT_MOD.H"
#include "DAT_COM.H"
#include "DAT_PWM.H"

//Display series

//Application series
#include "DAT_CVT.h"
//CAN&Diagnostic series
#include "DAT_CNM.H"
#include "DAT_DDB.h"
#include "DAT_DDI.h"
#include "DAT_DII.h"


#ifdef cLIBStkDFA_Used
#include "DAT_DFAx.h"
#include "DAT_FPL.H"
#endif

#ifdef cLIBStkEep_Used
//EEP
#include "DAT_PEE.H"
#endif


// TODO : DATPC Using
//#define DATPC_ENABLE	1
#if defined(COMPILATION_NATIVE) && defined(DATPC_ENABLE)
#include "DatpcPar.h"
#endif

/*-------------------------------------------------------------------------
  Constant data

  #define cCMPConstantName   ((tType) ConstantValue)
  -------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
  Exported Macro

  #define mCMPMacroName   (MacroDefinition)
  -------------------------------------------------------------------------*/
#define mDATWriteU16BitXCP_AFC_ExpCoefDefault(v)  	LAPFC_XCP_AFC_ExpCoef(v)
#define mDATWriteU16BitXCP_DTE_Para_AFCDefault(v) 	LAPFC_XCP_DTE_Para_AFC(v)
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
extern void LAPFC_XCP_AFC_ExpCoef(U16 u16Exp);
extern void LAPFC_XCP_DTE_Para_AFC(U16 u16AvgFc);
/*-------------------------------------------------------------------------
  End of includes non re entry
  -------------------------------------------------------------------------*/
#endif   /* I_DATPARAM_H */

