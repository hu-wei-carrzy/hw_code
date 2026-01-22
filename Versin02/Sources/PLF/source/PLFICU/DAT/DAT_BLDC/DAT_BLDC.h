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


#ifndef I_DAT_BLDC_H
#define I_DAT_BLDC_H

//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//
// #include <system_file_name.h>
// #include "project_file_name.h"
//------------------------------------------------------------------------------



#include "ARCH_CFG.h"
#include "DAT_BLDC_INCLUDE.h"
#include "DAT_BLDC_CFG.h"

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

#define SPEED_SCALE_CONST               (1704)
#define N_MAX                           (5500.0F)
#define I_DCB_LIMIT                     (6.5F)
#define N_MIN                           (800.0F)

//Control loop limits
#define CTRL_LOOP_LIM_HIGH              (90.0F)
#define CTRL_LOOP_LIM_LOW               (10.0F)

#define SPEED_LOOP_KP_GAIN              (0.000020000000F)
#define SPEED_LOOP_KI_GAIN              (0.000030000000F)

//Speed ramp increments
#define SPEED_LOOP_RAMP_UP              (2.0F)
#define SPEED_LOOP_RAMP_DOWN            (2.0F)

//Torque Controller - Parallel type
#define TORQUE_LOOP_KP_GAIN             (0.05F)
#define TORQUE_LOOP_KI_GAIN             (0.014F)
#define TORQUE_LOOP_MAF                 (0.03125F)



//------------------------------------------------------------------------------
// Exported type
//
// typedef Expression tLAYCmpTypeName;
//------------------------------------------------------------------------------
extern U8   su8DATBLDC_MotorState;
extern U8   ACT_u8EPSPwmEnable;
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




#endif   /* I_DAT_MOD_H */
