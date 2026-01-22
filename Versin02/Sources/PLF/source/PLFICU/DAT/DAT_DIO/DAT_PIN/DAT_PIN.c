/****************************************************************************
  Project ......................... Project Name
  Component ....................... dat_Pin
  File revision.................... $
  Last modification date .......... $Modtime:   Dec 11 2013 14:39:14  $
  -------------------------------------------------------------------------
  Copyright ... This software is JYD property. Duplication or
                disclosure is prohibited without JYD written permission
  ------------------------------------------------------------------------- 

  - Macros, constants et types which are not exported are defined in 
    this file
  - Variables and functions which are not exported are defined in this 
    file with the static keyword
  
  -------------------------------------------------------------------------
  Comments about the component (role, algorithm, structure, limitations,
           defined tasks and events...)
  - Role :
  
  -------------------------------------------------------------------------
  dat_Pin.c file review : 

   $

*****************************************************************************/

/*--------------------------------------------------------------------------
  Body Identification
  --------------------------------------------------------------------------*/
#define dat_Pin  "dat_Pin"

/*--------------------------------------------------------------------------
  Included files

  #include <system_file_name.h>
  #include "project_file_name.h"
  --------------------------------------------------------------------------*/
#include "ARCH_CFG.h"

#include "DAT_PIN.h"



/*--------------------------------------------------------------------------
  Local constants

  #define cConstantName   ((tType) ConstantValue)
  --------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------
  Local macros

  #define mMacroName   (MacroDefinition)
  --------------------------------------------------------------------------*/

/*****************************************************************************
  State Change Macros
                        *** WARNING ***
  Theses states are available during the call of DATPinStateChange function.
  ***************************************************************************/
#define mIsRaisingEdge(Data)    \
   (mDATDinGetRaisingEdge( cDATPin##Data##ByteIndex, cDATPin##Data##BitIndex )   )
         
#define mIsFallingEdge(Data)    \
   (mDATDinGetFallingEdge( cDATPin##Data##ByteIndex, cDATPin##Data##BitIndex )  )
          
#define mIsStateChange(Data)    \
   (mDATDinGetStateChange( cDATPin##Data##ByteIndex, cDATPin##Data##BitIndex ))

#define mIsFilteredVal(Data)    \
   (mDATDinGetFilteredValue( cDATPin##Data##ByteIndex, cDATPin##Data##BitIndex )   )


/*--------------------------------------------------------------------------
  Local types

  struct  sStructureName { ... };
  union   uUnionName { ... };
  enum    eEnumerationName { ... };
  typedef Expression tTypeName;
  --------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------
  Local data

  static  tType   VariableName;
  static  tType*  pVariableName; 
  --------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------
  Constant local Data

  static const tType  VariableName;
  --------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------
  Exported data

  tType   CMPVariableName;      (CMP: 3 characters to identify this component)
  tType*  pCMPVariableName;     (CMP: 3 characters to identify this component)
  --------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------
  Constant exported data
 
  const tType   CMPVariableName;(CMP: 3 characters to identify this component)
  --------------------------------------------------------------------------*/
const U8 DATPinInitArray[] = cDATPinInitBufferDinGeneratorMessage;

/*--------------------------------------------------------------------------
  Local function prototypes
  
  static tTypeRetour FunctionName(tTypeArgument1 ArgumentName1, ... );
  --------------------------------------------------------------------------*/

/****************************************************************************
*...........................................................................*
*............................ LOCAL FUNCTIONS ..............................*
*...........................................................................*
****************************************************************************/
/*============================================================================
  DESCRIPTION :
  
  PARAMETERS (Type,Name,Min,Max) :  none

  RETURN VALUE :  none
 
  DESIGN INFORMATION :  refer to Detailed Design Document
============================================================================*/




/****************************************************************************
*...........................................................................*
*........................... EXPORTED FUNCTIONS.............................*
*...........................................................................*
****************************************************************************/
/*============================================================================
  DESCRIPTION : Initialise DAT_Pin and DAT_DIN component
  
  PARAMETERS (Type,Name,Min,Max) :  none

  RETURN VALUE :  none
 
  DESIGN INFORMATION :  refer to Detailed Design Document
============================================================================*/
void DATPinInit(void)
{
    DATDinInit(DATPinInitArray);
}

/*============================================================================
  DESCRIPTION : Allows to invalidate some inputs
  
  PARAMETERS (Type,Name,Min,Max) :  none

  RETURN VALUE :  none
 
  DESIGN INFORMATION :  refer to Detailed Design Document
============================================================================*/
void DATPinSelection(void)
{

}

/*============================================================================
  DESCRIPTION : Indicates that input has changed
  
  PARAMETERS (Type,Name,Min,Max) :  none

  RETURN VALUE :  none
 
  DESIGN INFORMATION :  refer to Detailed Design Document
============================================================================*/
void DATPinStateChange(void)
{

}

/****************************************************************************
  DESCRIPTION         : Maintain Active State if Tige_Droite = 1

  PARAMETERS          : None
  (Type,Name,Min,Max) 

  RETURN VALUE        : None

  DESIGN INFORMATION  : Refer to Detailed Design Document

*****************************************************************************/
void DATPinIsMaintainActiveState(void)
{

}


