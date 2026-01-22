/*
 * DMC_control.h
 *
 *  Created on: 2017年4月17日
 *      Author: shenhua
 */

#ifndef SOURCE_PLF_DAT_DAT_BLDC_FWS_DMC_CONTROL_H_
#define SOURCE_PLF_DAT_DAT_BLDC_FWS_DMC_CONTROL_H_

#include "MOTORA_Settings.h"
#include "Platform_Types.h"
/*
 *  1rps :   1000 * 1000 /100 / 6 / (POLLES/2)
 *  4对极： 416
 *  5对极： 333
 */
//#define TIMER_BLOCK_TURN 	  (Uint32) (((5000 * ISR_FREQUENCY) / ISR_FREQUENCY_10K) / POLES)  //(Uint32)(7500 / POLES)  //  //(Uint32)(5000 / POLES)
#if (FREQUENCY_10 == ISR_FREQUENCY)
#define TIMER_BLOCK_TURN 	  (uint32)(5000 / POLES)  //(Uint32)(7500 / POLES)  //  //(Uint32)(5000 / POLES)
#elif (FREQUENCY_15 == ISR_FREQUENCY)
#define TIMER_BLOCK_TURN 	  (uint32)(7500 / POLES)
#endif


//#define CUR_MAX		5
#define DC_Volt  12.0
#define D_CUR_VALUE		0.05*CUR_MAX	//电流差值
#define IQ_FB_OPEN_LIMIT		-0.6*CUR_MAX
#define IQ_FB_CLOSE_LIMIT		0.6*CUR_MAX
#define IQ_FB_OPEN_BLOCK		-0.2*CUR_MAX
#define IQ_FB_CLOSE_BLOCK		0.2*CUR_MAX
#define ZERO_CUR		100U		//无电流阈值

#define cCurADNumberOfChanels	4U		//通道数
#if (FREQUENCY_10 == ISR_FREQUENCY)
#define cCurADAveragedCount		11U		//滤波值平均次数
#elif (FREQUENCY_15 == ISR_FREQUENCY)
#define cCurADAveragedCount		17U		//滤波值平均次数
#endif


#define DELTA_REF_LIMIT         0.08*CUR_MAX
#define TIMER_DELTA_REF_LIMIT  	3U		// 滤波采样次数
#define DELTA_REF_PRESCALER 	10U		// DELTA_REF_PRESCALER * 10 ms 采样一次


extern void update_motor_state(void);
extern void init_motor(void);
extern void update_rotor_state(void);
extern void update_block_state_HC(void);
extern uint16 GetMotorMaxCur(void);
extern void CurAD_get_max(void);
extern void BSPBLDC_Init(void);


extern uint32 u32_blocked_timer;
extern uint32 u32_rotor_stop_timer;
extern uint16 flag_close_blocked;
extern uint16 flag_open_blocked;
extern uint16 flag_close_blocked_HC;
extern uint16 flag_open_blocked_HC;
extern uint16 flag_rotor_stop;
extern uint8 u8_motor_type;
extern uint8 u8_door_type;
extern uint8 POLES;

extern float32 ADataArray[4];
extern float32	GetMaxCurrent;
extern float32	CUR_MAX;
extern float32 Bldc_current_max[200];
extern float32	current_max_sum;

#endif /* SOURCE_PLF_DAT_DAT_BLDC_FWS_DMC_CONTROL_H_ */
