//******************************************************************************
// Company:      Johnson Controls Inc.
// -----------------------------------------------------------------------------
// Copyright:    This software is JYD property.
//               Duplication or disclosure without JYD written authorization
//               is prohibited.
// -----------------------------------------------------------------------------
// Project:      N330
// Language:     ANSI-C
// -----------------------------------------------------------------------------
// Component:    DAT_MOD
//               
// -----------------------------------------------------------------------------
// $Date:   Jan 17 2014 18:14:10  $
// $Archive:   
// $Revision:   1.0  $
// -----------------------------------------------------------------------------
/* $Log:   //DI_JMC_N330_IC/archives/1016282/DEV/BUILD/SOURCES/DAT_MOD.h-arc  $
 * 
 *    Rev 1.0   Jan 17 2014 18:14:10   aluant
 * Initial revision.
 //
*/  
//******************************************************************************


#ifndef I_DAT_MOD_H
#define I_DAT_MOD_H

//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//
// #include <system_file_name.h>
// #include "project_file_name.h"
//------------------------------------------------------------------------------



//#include "ARCH_CFG.h"
#include "DAT_MOD_INCLUDE.h"
#include "DAT_MOD_CFG.h"

//------------------------------------------------------------------------------
// Data prefix for constant & data
//
// unsigned int {u8,u16,u32} / signed int {s8,s16,s32} 
// register size unsigned int {r} / float {f32,f64}  / s for struct 
// no prefix for other types.
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

extern	void	DATModStartupInit(void);
extern	void	DATModEnterActiveState(void);
extern	void	DATModLeaveActiveState(void);
extern	void	DATModTask(void);

extern	void	DATModIsMaintainActiveState(void);
extern	void	DATModIsMaintainActiveSleepState(void);
extern  U8		DATModGetSysMod(void);



#endif   /* I_DAT_MOD_H */

