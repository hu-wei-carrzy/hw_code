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
// $Date:   Jan 17 2014 18:20:32  $
// $Archive:   //DI_JMC_N330_IC/archives/1016282/DEV/BUILD/SOURCES/LAP_RWA.h-arc  $
// $Revision:   1.0  $
// -----------------------------------------------------------------------------
/* $Log:   //DI_JMC_N330_IC/archives/1016282/DEV/BUILD/SOURCES/LAP_RWA.h-arc  $
 * 
 *    Rev 1.0   Jan 17 2014 18:20:32   aluant
 * Initial revision.
 // 
 //    Rev 1.0   Dec 30 2010 16:29:04   aliuz0
 // Initial revision.
 * 
 *    Rev 1.0   Apr 17 2008 10:35:00   amonniy
 * Initial revision.
 * 
*/
//******************************************************************************

#ifndef I_LAP_RWA_H
#define I_LAP_RWA_H (1)

//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//
// #include <system_file_name.h>
// #include "project_file_name.h"
//------------------------------------------------------------------------------
#include "ARCH_CFG.h"

#include "LAP_RWA_INCLUDE.h"

#ifdef cHeadIncludeType_Directly
#include "LAP_DIA.h"
#else
#include ".\..\LAP_DIA\LAP_DIA.h"
#endif



#include "LAP_RWA_CFG.h"


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
extern void LAPRwaReadMemoryByAddress(void);
extern void LAPRwaWriteMemoryByAddress(void);

extern void LAPRwaOpenSession (void);
extern void LAPRwaCloseSession(void);

#endif   /* I_LAP_RWA_H */
