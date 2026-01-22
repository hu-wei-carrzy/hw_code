/*============================================================================
  Project ......................... COMMON
  Component ....................... DAT_PEE
  File revision.................... :   1.0  $
  Last modification date .......... $Modtime:   Feb 02 2013 12:55:58  $
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
  DAT_PEEP.h file review :
  
    :   P:/STANDARD/AEH/STK/PVCS/archives/STANDARD/DAT/EEP/DAT_PEE/Dat_peep.h-arc  $
 * 
 *    Rev 1.0   May 21 2003 13:26:18   aguillg
 * Initial revision.

  ==========================================================================*/

#ifndef I_DAT_PEE_CFG_H
#define I_DAT_PEE_CFG_H

/*-------------------------------------------------------------------------
  Included files

  #include <system_file_name.h>
  #include "project_file_name.h"
  --------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
  Constant data

  #define cCMPConstantName   ((tType) ConstantValue)
  -------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
  Exported Macros

  #define mCMPMacroName   (MacroDefinition)
  -------------------------------------------------------------------------*/ 

#define	mPEEDTCReport(v)																		\
{																								\
	/*mDATWriteTable(U1Bit, DTCFaults, eDTCIDEEPROM, v , Default);	*/							\
	mSERControl(Dtc, ReportDTCStatus);															\
}


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

#endif   /* I_DAT_PEE_CFG_H */
