/*
 * BSP_ICU.h
 *
 *  Created on: 2024Äê12ÔÂ20ÈÕ
 *      Author: 00361759
 */

#ifndef BSP_ICU_H_
#define BSP_ICU_H_

#include "Cpu.h"
#include "string.h"
#include "DC_ic1.h"
#include "./../BSP_BLDC/MOTORA_ICU.h"

#define MaxRecord 65535U
#define Motormaxspeed 23000U
#define MaxHz 13U
#define OverFLowHold 2U

#define HALL_IC1_Time 16U
#define Second2Us 1000000.0
#define Second2Min 60.0

#define HALL_A_POLES 10U
#define HALL_B_POLES 10U
#define HALL_C_POLES 10U
#define HALL_D_POLES 60U

#define Halt 		0
#define Positive 	1
#define Negative 	2
#define Fault    	3

typedef struct
{
	uint8_t direction;

	uint16_t before_edge_time;
	uint16_t last_edge_time;
	uint16_t now_edge_time;

	uint16_t A_HallCount;
	uint16_t B_HallCount;

	uint16_t Period;
	uint16_t width;
}tBrushedMotorHallData;


void IC_Init(void);
void FTM0_Overflow_ISR(void);

uint16_t BSP_GetSpeed_CH0(void);
uint16_t BSP_GetSpeed_CH1(void);
uint16_t BSP_GetSpeed_CH2(void);
uint16_t BSP_GetSpeed_CH3(void);

uint16_t BSP_GetHallA_CH0(void);
uint16_t BSP_GetHallB_CH0(void);
uint16_t BSP_GetHallA_CH1(void);
uint16_t BSP_GetHallB_CH1(void);
uint16_t BSP_GetHallA_CH2(void);
uint16_t BSP_GetHallB_CH2(void);
uint16_t BSP_GetHallA_CH3(void);
uint16_t BSP_GetHallB_CH3(void);


#endif /* BSP_ICU_H_ */



