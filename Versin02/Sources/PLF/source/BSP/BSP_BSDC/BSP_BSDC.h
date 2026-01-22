/*
 * BSP_BSDC.h
 *
 *  Created on: 2025年5月8日
 *      Author: lenovo
 */

#ifndef PLF_SOURCE_BSP_BSP_BSDC_BSP_BSDC_H_
#define PLF_SOURCE_BSP_BSP_BSDC_BSP_BSDC_H_

#include "..\BSP_ICU\BSP_ICU.h"
#include "..\BSP_PWM\BSP_PWM.h"
#include "FTM_common.h"
#include "..\BSP_PWM\BSP_PWM_EXPORT.h"
#include "Platform_Types.h"
#include <math.h>

#define MaxDuty 100
#define MinDuty 0

uint16 GetBSDCMaxCurA(void);
uint16 GetBSDCMaxCurB(void);
uint16 GetBSDCMaxCurC(void);
uint16 GetBSDCMaxCurD(void);
//void MotorSpeedUpdate(Readvalue *P);



//PID算法参数
typedef struct
{
    float target_val;               //目标值
    float actual_val;                       //实际值
    float err;                              //定义偏差值
    float err_last;                         //定义上一个偏差值
    float Kp,Ki,Kd;                         //定义比例、积分、微分系数
    float integral;                         //定义积分值
}_PID;


typedef struct
{
	uint8_t TargetDuty;
	uint8_t SetDuty;
	uint8_t StepDuty;
	uint8_t SetMaxDuty;
	uint8_t SetMinDuty;
}DutyControl;


void Motor_DutyStep_control(int8_t channel , uint8_t SetDuty );

uint16 GetBSDCAvgCurA(void);
uint16 GetBSDCAvgCurB(void);
uint16 GetBSDCAvgCurC(void);
uint16 GetBSDCAvgCurD(void);

uint8_t BSP_ICU_Direction_CH0(void);
uint8_t BSP_ICU_Direction_CH1(void);
uint8_t BSP_ICU_Direction_CH2(void);
uint8_t BSP_ICU_Direction_CH3(void);

uint16_t GetBSDCAvgSpeedA();
uint16_t GetBSDCAvgSpeedB();
uint16_t GetBSDCAvgSpeedC();
uint16_t GetBSDCAvgSpeedD();

#endif /* PLF_SOURCE_BSP_BSP_BSDC_BSP_BSDC_H_ */
