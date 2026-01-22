/*
 * LDB_BLDC.c
 *
 *  Created on: 2025年5月8日
 *      Author: lenovo
 */


/*--------------------------------------------------------------------------
Body Identification
--------------------------------------------------------------------------*/

#define ldb_bldc "ldb_bldc"

/*-------------------------------------------------------------------------
Included files

  #include <system_file_name.h>
  #include "project_file_name.h"
--------------------------------------------------------------------------*/

#include <PLF/source/PLFICU/LDB/LDB_BLDC/LDB_BLDC.h>
#include ".\..\..\TOS\TOS.h"

/*--------------------------------------------------------------------------
Local constants

  #define cConstantName   ((tType) ConstantValue)
--------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------
Local macros

  #define mMacroName   (MacroDefinition)
--------------------------------------------------------------------------*/

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
Constant local data

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

/*--------------------------------------------------------------------------
Local function prototypes

  static tTypeRetour FunctionName(tTypeArgument1 ArgumentName1, ... );
--------------------------------------------------------------------------*/


/*============================================================================
=========================== LOCAL FUNCTIONS ================================
==========================================================================*/

/*============================================================================
  DESCRIPTION : DisableInterrupts

  PARAMETERS (Type,Name,Min,Max) :   none

  RETURN VALUE :   none

  DESIGN INFORMATION :   refer to Detailed Design Document
==========================================================================*/


/*============================================================================
  DESCRIPTION : NotifyWakeUp

  PARAMETERS (Type,Name,Min,Max) :   none

  RETURN VALUE :   none

  DESIGN INFORMATION :   refer to Detailed Design Document
==========================================================================*/



/*============================================================================
=========================== EXPORTED FUNCTIONS =============================
==========================================================================*/

/*============================================================================
  DESCRIPTION :

  PARAMETERS (Type,Name,Min,Max) :  none

  RETURN VALUE :  none

  DESIGN INFORMATION :  refer to Detailed Design Document
============================================================================*/
void LDBBLDCInit(void)
{
	BSPBLDC_Init();
}

/*============================================================================
  DESCRIPTION :

  PARAMETERS (Type,Name,Min,Max) :  none

  RETURN VALUE :  none

  DESIGN INFORMATION :  refer to Detailed Design Document
============================================================================*/
void LDBBLDCReceiveWithoutAddr(tMsg* pMsg)
{

}

/*============================================================================
  DESCRIPTION :

  PARAMETERS (Type,Name,Min,Max) :  none

  RETURN VALUE :  none

  DESIGN INFORMATION :  refer to Detailed Design Document
============================================================================*/
void LDBBLDCReceiveWithAddr(tAddress addr, tMsg* pMsg)
{

}

/*============================================================================
  DESCRIPTION :

  PARAMETERS (Type,Name,Min,Max) :  none

  RETURN VALUE :  none

  DESIGN INFORMATION :  refer to Detailed Design Document
============================================================================*/
void LDBBLDCControl(tCtrl Ctrl)
{

}

/*============================================================================
  DESCRIPTION :

  PARAMETERS (Type,Name,Min,Max) :  none

  RETURN VALUE :  none

  DESIGN INFORMATION :  refer to Detailed Design Document
============================================================================*/
void LDBBLDCLeaveSleepMode(void)
{

}

/*============================================================================
  DESCRIPTION :

  PARAMETERS (Type,Name,Min,Max) :  none

  RETURN VALUE :  none

  DESIGN INFORMATION :  refer to Detailed Design Document
============================================================================*/
void LDBBLDCEnterSleepMode(void)
{

}

/*============================================================================
  DESCRIPTION :

  PARAMETERS (Type,Name,Min,Max) :  none

  RETURN VALUE :  none

  DESIGN INFORMATION :  refer to Detailed Design Document
============================================================================*/
//唤醒中断响应函数都定义在LDB层，方便编程
void LDBBLDCWakeUpIsr(void)
{

}



