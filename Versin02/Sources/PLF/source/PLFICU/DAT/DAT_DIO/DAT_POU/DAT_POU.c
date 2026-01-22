
/*--------------------------------------------------------------------------
  Body Identification
  --------------------------------------------------------------------------*/
#define dat_pst  "dat_pou"

/*--------------------------------------------------------------------------
  Included files

  #include <system_file_name.h>
  #include "project_file_name.h"
  --------------------------------------------------------------------------*/

#include "ARCH_CFG.h"
#ifdef cHeadIncludeType_Directly
#include "DAT_DOU.h"
#else
#include ".\..\DAT_DOU\DAT_DOU.h"
#endif
#include "DAT_POU.h"


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
const U8 DATPouInitArray[] = cDATPouInitBufferDouGeneratorMessage;

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
  DESCRIPTION : Initialise DAT_POU and DAT_DOU component
  
  PARAMETERS (Type,Name,Min,Max) :  none

  RETURN VALUE :  none
 
  DESIGN INFORMATION :  refer to Detailed Design Document
============================================================================*/
void DATPouInit(void)
{
    DATDouInit(DATPouInitArray);
}

/*============================================================================
  DESCRIPTION : Modifies the logical output buffer befor writing
  
  PARAMETERS (Type,Name,Min,Max) :  none

  RETURN VALUE :  none
 
  DESIGN INFORMATION :  refer to Detailed Design Document
============================================================================*/
void DATPouPrepareRefresh(void)
{	
	if(mSERRead(U1Bit,IsBatNormal,Default))
    {
		//output dou,
	}
	else/*extinguish all*/
	{
		(void)mLIBmemset((void*)DATDouOutputBuffer, 0, sizeof(DATDouOutputBuffer));
	}
}

/*============================================================================
  DESCRIPTION : DATPouAdc_StartGroup1And2Conversion

  PARAMETERS (Type,Name,Min,Max) :  none

  RETURN VALUE :  none

  DESIGN INFORMATION :  refer to Detailed Design Document
============================================================================*/
void DATPouAdc_StartGroup1And2Conversion(void)
{
	//TOSSendControl(cTOSControlAdc_ReadGroup1);

	//if(mDATRead(U1Bit,IsSelfChkEnable,Default))
	//{
	//	TOSSendControl(cTOSControlAdc_ReadGroup2);
	//}
}



