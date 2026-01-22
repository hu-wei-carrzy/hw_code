/*
 * MOTORA_ICU.h
 *
 *  Created on: 2025年6月10日
 *      Author: lenovo
 */

#ifndef PLF_SOURCE_BSP_BSP_BLDC_MOTORA_ICU_H_
#define PLF_SOURCE_BSP_BSP_BLDC_MOTORA_ICU_H_


#include "Cpu.h"
#include "string.h"


typedef struct IcuStr
{
	uint32_t pre_hall_state_time;
	uint32_t hall_state_time;
	uint16_t hall_state;		/*当前霍尔状态*/
	uint16_t pre_hall_state;	/*之前的状态*/
	uint16_t bak_hall_state;	/*前一个状态*/
	uint16_t hall_state_sin;
}IcuTime;

typedef enum
{
	HW_INPUT_TRIG0,			/* FTM3 is triggered automatically by FTM0 init trigger through FTM3 signal input TRIG0 */
	HW_INPUT_TRIG1 			/* FTM3 is triggered manually by FTM3 SYNC bit through FTM3 signal input TRIG1 */
} ftm_hw_trigger_t;





extern uint32_t u32_IcuTicker;
extern IcuTime IcuHallTime;


extern void FTM1_Overflow_ISR(void);
extern void BLDC_HALL_Init(void);

#endif /* PLF_SOURCE_BSP_BSP_BLDC_MOTORA_ICU_H_ */
