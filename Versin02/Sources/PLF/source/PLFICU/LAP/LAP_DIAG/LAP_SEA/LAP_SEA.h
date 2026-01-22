#ifndef _QAC_
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
// $Date:   Jan 17 2014 18:20:50  $
// $Archive:   //DI_JMC_N330_IC/archives/1016282/DEV/BUILD/SOURCES/LAP_SEA.h-arc  $
// $Revision:   1.0  $
// -----------------------------------------------------------------------------
/* $Log:   //DI_JMC_N330_IC/archives/1016282/DEV/BUILD/SOURCES/LAP_SEA.h-arc  $
 * 
 *    Rev 1.0   Jan 17 2014 18:20:50   aluant
 * Initial revision.
 // 
 //    Rev 1.1   Sep 03 2012 18:32:16   agaod
 // Cm039834:Update code for SecurityAccess(#27)
 // 
 //    Rev 1.0   Dec 30 2010 16:29:24   aliuz0
 // Initial revision.
 * 
 *    Rev 1.1   Mar 02 2010 17:21:56   amanevm
 * Tm107451: LDBRefreshWatchDog() is not properly used 
 * 
 *    Rev 1.0   Apr 17 2008 10:42:10   amonniy
 * Initial revision.
 * 
 *    Rev 1.0   Nov 28 2006 15:35:48   amonniy
 * Initial revision.
*/
//******************************************************************************
#endif

#ifndef I_LAP_SEA_H
#define I_LAP_SEA_H (1)

//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//
// #include <system_file_name.h>
// #include "project_file_name.h"
//------------------------------------------------------------------------------
#include "ARCH_CFG.h"
#ifdef cHeadIncludeType_Directly
#include "LAP_DIA.h"
#include "LIB_BOO.h"
#else

#include ".\..\LAP_DIA\LAP_DIA.h"

#ifdef BOOTLOADER_IS_SUPPORTED
#include ".\..\..\..\LIB\LIB_BOO\LIB_BOO.h"
#endif
#endif



#include  "LAP_SEA_INCLUDE.h"

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
extern void LAPSeaSecurityAccess(void);

extern void LAPSeaOpenSession (void);
extern void LAPSeaCloseSession(void);

extern	BOOL	LAPSeaIsServiceUnLocked(void);


#endif   /* I_LAP_SEA_H */
