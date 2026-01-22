/*
 * GenSVPWM.h
 *
 *  Created on: 2021年11月25日
 *      Author: jiaosw
 */

#ifndef _GENSVPWM_H_
#define _GENSVPWM_H_

//#include "pid_grando.h"
#include "MOTORA_Settings.h"
#include "Platform_Types.h"

//#define CUR_MAX 3000
//float32 CUR_MAX = 5;

#define IQ_OPEN_LIMIT_ALL	-CUR_MAX*0.9
#define IQ_CLOSE_LIMIT_ALL	CUR_MAX*0.9

#define IQ_OPEN_LIMIT		-CUR_MAX*0.8
#define IQ_CLOSE_LIMIT		CUR_MAX*0.8
#define	OPENDOOR_FORWARD	0


extern PI_CONTROLLER pi_iq;
extern PI_CONTROLLER pi_spd;
extern uint16 SPEED_ZERO_TIMER;
extern boolean MotorA_Run;
extern float32 siq_speed_fb;

extern float32 SpeedRef;
extern float32	Current_MAX_Times;
extern float32	Current_MIN_Times;
extern void CtrlTask_FOCA(void);
extern void trigger_bldc(uint32 onoff);
#endif /* 0_APPSW_TRICORE_DMC101_FILES_GENSVPWM_H_ */
extern float32 PWM_Duty;
extern sint32 counter_loops;       	/*圈数记录计数器*/
extern sint32 MotorCircles;        	/*电机转动圈数*/
extern volatile uint16 EnableFlag;


extern void motor_stopA(void);

