/****************************************************************************
  Project ......................... Project Name
  Component ....................... dat_pou
  File revision.................... $
  Last modification date .......... $Modtime:   Nov 21 2014 15:22:04  $
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
  dat_pst.h file review :
  
   $

*****************************************************************************/

/*-------------------------------------------------------------------------
  Includes non re entry
  -------------------------------------------------------------------------*/
#ifndef I_DAT_POU_H
#define I_DAT_POU_H

/*--------------------------------------------------------------------------
  Included files to resolve specific definitions in this file

  #include <system_file_name.h>
  #include "project_file_name.h"
  --------------------------------------------------------------------------*/

#include "ARCH_CFG.h"
#ifdef cHeadIncludeType_Directly
#include "HAL.h"
#include "DAT_DEPENDCY.h"
#include "dat_poux.h"
#else
#include ".\..\..\..\HAL\HAL.h"
#include ".\..\..\DAT_DEPENDCY.h"
#include ".\..\..\..\SCC2Gen\GEN\dat_poux.h"
#endif

/*--------------------------------------------------------------------------
  Constant data

  #define cCMPConstantName   ((tType) ConstantValue)
  --------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------
  Exported Macros

  #define mCMPMacroName   (MacroDefinition)
  --------------------------------------------------------------------------*/ 

// Write macros
#define mDATPouWriteU1BitDelayed(ByteNbr,BitNbr,BitValue) \
  {\
    U8 Mask;\
    if ((BitValue)) \
    { \
      Mask = (1U << (BitNbr)); \
      *(DATDouOutputBuffer+(ByteNbr)) |= Mask; \
    } \
    else  \
    { \
      Mask = ~(1U << (BitNbr)); \
      *(DATDouOutputBuffer+(ByteNbr)) &= Mask; \
    } \
  }

#define mDATPouWriteU1BitImmediate(ByteNbr,BitNbr,BitValue)   \
  {\
    if(mDATPouReadU1Bit(Inutile,(ByteNbr), (BitNbr),default) != (BitValue))\
    {\
        mDATPouWriteU1BitDelayed((ByteNbr),(BitNbr),(BitValue));          \
        mDATDouRefreshOutput();\
    }\
  }

// Read macros
#define mDATPouWriteU1Bit(Inutile,Octet,Bit,Etat,TypeTraitement)\
  (mDATPouWriteU1Bit##TypeTraitement((Octet), (Bit),(Etat)))

#define mDATPouReadU1Bit(Inutile,ByteNbr,BitNbr,TypeTraitement) \
  ((DATDouOutputBuffer[(ByteNbr)] & (1 << (BitNbr)))!=0)

#define mDATPouRead(Inutile,Octet,Bit,Etat,TypeTraitement) \
  (mDATDouLireU1Bit((Octet),(Bit),(Etat)))


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
extern const U8 DATPouInitArray[];

/*--------------------------------------------------------------------------
  Exported functions

  extern tReturnType CMPFunctionName(tTypeArgument1 ArgumentName1, ... );
  --------------------------------------------------------------------------*/ 
extern void DATPouInit(void);
extern void DATPouPrepareRefresh(void);
extern void DATPouAdc_StartGroup1And2Conversion(void);
/*-------------------------------------------------------------------------
  End of includes non re entry
  -------------------------------------------------------------------------*/
#endif  /* I_DAT_PST_H */
