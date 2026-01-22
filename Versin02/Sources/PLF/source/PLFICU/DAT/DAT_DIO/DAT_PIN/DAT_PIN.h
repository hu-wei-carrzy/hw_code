/****************************************************************************
  Project ......................... Project Name
  Component ....................... dat_Pin
  File revision.................... $
  Last modification date .......... $Modtime:   Dec 11 2013 14:39:14  $
  -------------------------------------------------------------------------
  Copyright ... This software is JYD property. Duplication or
                disclosure is prohibited without JYD written permission
  ------------------------------------------------------------------------- 
    
  - This file should only contain data useful to the programmer to use
    this component
  - Component exported macros, constants and types are defined in this file
  - Component exported variables and functions are declared in this file 
    with the "extern" keyword
  
  -------------------------------------------------------------------------
  dat_Pin.h file review :
  
   $

*****************************************************************************/

/*-------------------------------------------------------------------------
  Includes non re entry
  -------------------------------------------------------------------------*/
#ifndef I_DAT_Pin_H
#define I_DAT_Pin_H

/*--------------------------------------------------------------------------
  Included files to resolve specific definitions in this file

  #include <system_file_name.h>
  #include "project_file_name.h"
  --------------------------------------------------------------------------*/

#include "ARCH_CFG.h"


#include "DAT_PIN_CFG.h"
#include "DAt_PIN_INCLUDE.h"

#ifdef cHeadIncludeType_Directly
#include "dat_pinx.h"
#include "DAT_DIN.h"
#else
#include ".\..\..\..\SCC2Gen\GEN\dat_pinx.h"
#include ".\..\DAT_DIN\DAT_DIN.h"
#endif


/*--------------------------------------------------------------------------
  Constant data

  #define cCMPConstantName   ((tType) ConstantValue)
  --------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------
  Exported Macros

  #define mCMPMacroName   (MacroDefinition)
  --------------------------------------------------------------------------*/ 
// Read macros
#define mDATPinReadU1BitDelayed(Octet,Bit)  mDATDinGetFilteredValue((Octet),(Bit))
#define mDATPinReadU1BitImmediate(Octet,Bit) mDATDinGetNonFilteredValue((Octet),(Bit))

#define mDATPinReadU1Bit(Trame, Octet, Bit, TypeTraitement) \
  (mDATPinReadU1Bit##TypeTraitement((Octet), (Bit)))

#define mDATPinWriteU1Bit(Trame,Octet,Bit, Etat,TypeTraitement)\
(mDATPinWriteU1Bit##TypeTraitement((Trame),(Octet), (Bit),(Etat)))

#define mDATPinWriteU1BitDelayed(Trame,Octet,Bit,Etat) \
   (mDATDinSetFilteredValue((Octet),(Bit),(Etat)))

#define mDATPinWriteU1BitImmediate(Trame,Octet,Bit,Etat) \
   mDATDinSetNonFilteredValue((Octet),(Bit),(Etat)); \
   mDATDinSetFilteredValue((Octet),(Bit),(Etat))

// Control macros
#define mDATControlPinStop()              (DATDinStop())
#define mDATControlPinStart()             (DATDinStart())
#define mDATControlPinEnterSleepMode()    (DATDinEnterSleepMode())
#define mDATControlPinInit()              (DATPinInit())

#define mDATControlDin(Cmd)               (mDATControlPin##Cmd())

/*--------------------------------------------------------------------------
  Exported types

  struct  sCMPStructureName { ... };
  union   uCMPUnionName { ... };
  enum    eCMPEnumerationName { ... };
  typedef Expression tCMPTypeName;

  --------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------
  Exported data

  extern  tType   CMPVariableName;
  extern  tType*  pCMPVariableName; 
  --------------------------------------------------------------------------*/ 

/*--------------------------------------------------------------------------
  Constant exported data

  extern const tType  CMPVariableName;
  --------------------------------------------------------------------------*/ 
extern const U8 DATPinInitArray[];

/*--------------------------------------------------------------------------
  Exported functions

  extern tReturnType CMPFunctionName(tTypeArgument1 ArgumentName1, ... );
  --------------------------------------------------------------------------*/ 
extern void DATPinInit(void);
extern void DATPinIsMaintainActiveState(void);

/*-------------------------------------------------------------------------
  End of includes non re entry
  -------------------------------------------------------------------------*/
#endif  /* I_DAT_Pin_H */
