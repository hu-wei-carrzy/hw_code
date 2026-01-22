//******************************************************************************
// Company:      Johnson Controls Inc.
// -----------------------------------------------------------------------------
// Copyright:    This software is JCI property.
//               Duplication or disclosure without JCI written authorization
//               is prohibited.
// -----------------------------------------------------------------------------
// Project:      <PROJECT>
// Language:     ANSI-C
// -----------------------------------------------------------------------------
// Component:    <Comments about the component (role, algorithm, structure, 
//               limitations, defined tasks and events...)>
// -----------------------------------------------------------------------------
// $Date:   Jan 17 2014 18:19:32  $
// $Archive:   //DI_JMC_N330_IC/archives/1016282/DEV/BUILD/SOURCES/LAP_IOC.h-arc  $
// $Revision:   1.0  $
// -----------------------------------------------------------------------------
/* $Log:   //DI_JMC_N330_IC/archives/1016282/DEV/BUILD/SOURCES/LAP_IOC.h-arc  $
 * 
 *    Rev 1.0   Jan 17 2014 18:19:32   aluant
 * Initial revision.
 // 
 //    Rev 1.0   Dec 30 2010 16:28:56   aliuz0
 // Initial revision.
 * 
 *    Rev 1.0   Apr 22 2008 11:33:20   amonniy
 * Initial revision.
 * 
*/
//******************************************************************************

#ifndef I_LAP_IOC_H
#define I_LAP_IOC_H (1)

//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//
// #include <system_file_name.h>
// #include "project_file_name.h"
//------------------------------------------------------------------------------
#include "ARCH_CFG.h"

#include "LAP_IOC_INCLUDE.h"

#ifdef cHeadIncludeType_Directly
#include "LAP_DIA.h"
#else
#include ".\..\LAP_DIA\LAP_DIA.h"
#endif

//------------------------------------------------------------------------------
// Data prefix for constant & data: see coding guideline
//
//------------------------------------------------------------------------------
// Constant data
//
// #define cu16LAYCmpConstantName   ((U16) ConstantValueUL)
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Exported type
//
// typedef Expression tLAYCmpTypeName;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Exported data
//
// extern  tType   u8LAYCmpVariableName;
// extern  tType*  ps32LAYCmpVariableName; 
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Constant exported data
//
// extern const tType  s8LAYCmpVariableName;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Exported Macros
//
// #define LAYCmpMacroName(...)   (MacroDefinition)
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Exported functions
//
// extern tReturnType LAYCmpFunctionName(tTypeArgument1 ArgumentName1, ... );
//------------------------------------------------------------------------------
extern void LAPIocInputOutputControlByIdentifier(void);

extern void LAPIocOpenSession (void);
extern void LAPIocCloseSession(void);

#endif   /* I_LAP_IOC_H */
