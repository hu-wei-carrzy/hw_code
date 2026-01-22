/*
 * BSP_PWM.h
 *
 *  Created on: 2024Äê12ÔÂ23ÈÕ
 *      Author: 00361759
 */

#ifndef BSP_PWM_H_
#define BSP_PWM_H_

#include "gdflib.h"
#include "gflib.h"
#include "gmclib.h"
#include "mlib.h"
#include "SWLIBS_Typedefs.h"

#include "..\BSP_ICU\BSP_ICU.h"
#include "..\BSP_BSDC\FTM_common.h"
#include "..\BSP_BLDC\MOTORA_SVPWM.h"
#include "Platform_Types.h"
#include <math.h>



#define BLDC_PWM 1U
#define DC_PWM 2U

#define TORQUE_LOOP_MAF                 (0.03125F)

typedef struct {
	tFloat BEMFVoltage;
	tFloat DCBVVoltage;
	tFloat DCBIVoltage;
	tFloat DCBUIVoltageRaw;
	tFloat DCBVIVoltageRaw;
	tFloat DCBWIVoltageRaw;
	tFloat DCBIVoltageRaw;
	tFloat DCBIOffset;
}tADCresults;


//extern DutyControl MotorA;
//extern DutyControl MotorB;
//extern DutyControl MotorC;
//extern DutyControl MotorD;

extern bool MotorAChange;
extern bool MotorBChange;
extern bool MotorCChange;
extern bool MotorDChange;

extern GDFLIB_FILTER_MA_T_FLT Idcb_filt;
extern tFloat 	u_dc_bus_filt, torque_filt;
extern uint8_t ADC0CHnComplete;
extern tFloat ADC0CHnResult;
extern uint8_t ADC1CHnComplete;
extern tFloat ADC1CHnResult;


void PWM_Init(void);
void BSP_PWM_SetPeriod(uint8_t xPWM,uint16_t period);
void BSP_PWM_SetDuty(uint8_t xPWM,uint8_t channel,uint16_t duty);
void BSP_PWM_ISR(void);
void BSP_MotorA_Control(void);
void BSP_MotorB_Control(void);
void BSP_MotorC_Control(void);
void BSP_MotorD_Control(void);
//void MotorUpdateData(Readvalue *P);




#endif /* BSP_PWM_H_ */
