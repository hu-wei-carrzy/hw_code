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


#ifndef I_DAT_BSDC_H
#define I_DAT_BSDC_H

//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//
// #include <system_file_name.h>
// #include "project_file_name.h"
//------------------------------------------------------------------------------



#include "ARCH_CFG.h"
#include "DAT_BSDC_INCLUDE.h"
#include "DAT_BSDC_CFG.h"
#include "./../../BSP/BSP_ICU/BSP_ICU.h"
#include "./../../BSP/BSP_SPI/BSP_DRV8718.h"



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
#define CW_FORWARD 1
#define SPEED_SET_MAX 3000

//------------------------------------------------------------------------------
// Exported type
//
// typedef Expression tLAYCmpTypeName;
//------------------------------------------------------------------------------
typedef enum
{
    eInit=0,
    eIdle,
	eCWRun,
	eCCWRun,
	eStoping,
	eStop,
	eBrake,
	eError
} eDCMotorStatus;

typedef struct
{


    uint16_t TargetSpeed;
    uint16_t Fdkspeed;

    int16_t TargetCur;
    int16_t FdkCur;
    int16_t BaseCur;

    int8_t TargetDuty;
    int8_t SetDuty;
    int8_t StepDuty;

    int8_t TargetDir;
    int8_t SetDir;
    int8_t FdkDir;

    eDCMotorStatus Status;

} tDCMotor;

typedef enum
{
    eDCMode_Disable = 0,
	eDCMode_Enable,
	eDCMode_Brake,

} eDCMotorMode;

typedef enum
{
    eDCMOTOR_1 = 1,
	eDCMOTOR_2,
	eDCMOTOR_3,
	eDCMOTOR_4,
	eDCMOTOR_COUNT // 用于统计电机数量
} eDCMotorChannel;




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

extern U8 DATBSDC_A_DualHall_Direction(void);
extern U8 DATBSDC_B_DualHall_Direction(void);
extern U8 DATBSDC_C_DualHall_Direction(void);
extern U8 DATBSDC_D_DualHall_Direction(void);

extern U16 DATBSDC_GetMaxCur_A(void);
extern U16 DATBSDC_GetMaxCur_B(void);
extern U16 DATBSDC_GetMaxCur_C(void);
extern U16 DATBSDC_GetMaxCur_D(void);

extern U16 DATBSDC_GetHall_A(void);
extern U16 DATBSDC_GetHall_B(void);
extern U16 DATBSDC_GetHall_C(void);
extern U16 DATBSDC_GetHall_D(void);

extern void DATBSDC_A_SetDuty(uint8_t duty);
extern void DATBSDC_B_SetDuty(uint8_t duty);
extern void DATBSDC_C_SetDuty(uint8_t duty);
extern void DATBSDC_D_SetDuty(uint8_t duty);

extern U16 DATBSDC_GetHall1_A(void);
extern U16 DATBSDC_GetHall2_A(void);


extern uint16_t DATBSDC_GET_SpeedA(void);
extern uint16_t  DATBSDC_GET_SpeedB(void);
extern uint16_t  DATBSDC_GET_SpeedC(void);
extern uint16_t  DATBSDC_GET_SpeedD(void);


#endif   /* I_DAT_BSDC_H */
