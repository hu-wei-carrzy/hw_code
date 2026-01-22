
/*--------------------------------------------------------------------------
  Body Identification
  --------------------------------------------------------------------------*/

#define LIB   "LIB"

/*-------------------------------------------------------------------------
  Included files

  #include <system_file_name.h>
  #include "project_file_name.h"
  --------------------------------------------------------------------------*/
#include "lib.h"


/*--------------------------------------------------------------------------
  Local constants

  #define cConstantName   ((tType) ConstantValue)
  --------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------
  Local macross

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
  DESCRIPTION :
  
  PARAMETERS (Type,Name,Min,Max) :   none

  RETURN VALUE :   none
 
  DESIGN INFORMATION :   refer to Detailed Design Document
  ==========================================================================*/
//static type FunctionName(...)

/*============================================================================
  =========================== EXPORTED FUNCTIONS =============================
  ==========================================================================*/

extern U32  u32Random1p25Ms;
U32   LIBGetCurTime(void )
{
	return u32Random1p25Ms;
}



/*============================================================================
  DESCRIPTION :
  
  PARAMETERS (Type,Name,Min,Max) :  none

  RETURN VALUE :  none
 
  DESIGN INFORMATION :  refer to Detailed Design Document
============================================================================*/
#ifdef DEBUG
void LIBAssertionFailed(char *file_name, U32 file_name_length, U32 line_num)
{
    BSP_LOG_Print("Assert Failed: %s:%d\n", file_name, line_num);
    BSP_LOG_Print("System Halted!\n");
    // This function allows to detect assertion failure.
    // You can set a BreakPoint here.
    while( 1 == 1 );

}
#endif
