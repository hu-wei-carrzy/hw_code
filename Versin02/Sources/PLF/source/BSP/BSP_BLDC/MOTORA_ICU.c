/*
 * MOTORA_ICU.c
 *
 *  Created on: 2025年6月10日
 *      Author: lenovo
 */


#include "MOTORA_ICU.h"
#include "MOTORA_Hall.h"

#include "gdflib.h"
#include "gflib.h"
#include "gmclib.h"
#include "mlib.h"
#include "SWLIBS_Typedefs.h"


uint32_t u32_IcuTicker = 0U;
IcuTime IcuHallTime = { 0U,0U,0U,0U,0U,0U };

uint16_t u16_HallCount =0U;
uint16_t u16_BothHallCount =0U;

float32 SpeedIcuValue_100ms[10] ={0U};
uint16_t u16_SpeedCount =0U;
float32 SpeedIcuAvgValue =0U;

/* FTM3 channel output mask control */
 const uint8_t ui8FTM3OutmaskVal[2][8] =
{

    {/* Clockwise rotation direction */
    	0x4C,   /* sector 3 */
    	0xC4,   /* sector 1 */
		0x34,   /* sector 2 */
		0x1C,   /* sector 0 */
		0xD0,   /* sector 5 */
		0x70,   /* sector 4 */

        0x14,   /* alignment vector */
        0x3F    /* PWM off */
    },

    { /* Counterclockwise rotation direction */
		0x1C,   /* sector 5 */
		0x34,   /* sector 4 */
		0xC4,   /* sector 3 */
    	0x4C,   /* sector 3 */
    	0x70,   /* sector 4 */
		0xD0,   /* sector 0 */

        0x14,    //alignment vector
        0x3F     //PWM off
    }
};

 /* FTM3 channel software output control */
  const uint16_t ui16FTM3SwOctrlVal[2][8] =
 {
	/* Clockwise rotation direction */
	 {
		 0x8080, /* sector 1 */
		 0x0808, /* sector 3 */
		 0x0808, /* sector 4 */
		 0x2020, /* sector 0 */
		 0x2020, /* sector 5 */
		 0x8080, /* sector 2 */

		 0x2828, /* alignment vector */
		 0x0000  /* PWM off */
	 },
	 /* Counterclockwise rotation direction */
     {
		 0x2020, /* sector 0 */
		 0x0808, /* sector 3 */
		 0x0808, /* sector 4 */
		 0x8080, /* sector 2 */
		 0x8080, /* sector 1 */
		 0x2020, /* sector 5 */

         0x2828, /* alignment vector */
         0x0000  /* PWM off */
     }
 };

void BLDC_HALL0_Callback(ic_event_t event, void *userData);
void BLDC_HALL1_Callback(ic_event_t event, void *userData);
void BLDC_HALL2_Callback(ic_event_t event, void *userData);

/**************************************************************************//*!
@brief Set PWM Mask, Mask will by updated on next reload event

@param[in,out]

@return
******************************************************************************/
tBool ACTUATE_SetPwmMask(uint8_t ui8OutMask, uint16_t ui16SwCtrl, tBool ftmInputTrig)
{
	/* Clear FTM3SYNCBIT to prepare HW trigger for FTM3 */
    SIM->FTMOPT1 &= ~(SIM_FTMOPT1_FTM2SYNCBIT_MASK & (ftmInputTrig << SIM_FTMOPT1_FTM2SYNCBIT_SHIFT));

    // Apply Mask
    //FTM3->OUTMASK = ui8OutMask;
    FTM_DRV_MaskOutputChannels(INST_BLDC_PWM2, ui8OutMask, false);
    FTM2->SWOCTRL = ui16SwCtrl;

    /* Set FTM3SYNCBIT to trigger and update FTM3 registers */
    SIM->FTMOPT1 |= (SIM_FTMOPT1_FTM2SYNCBIT_MASK & (ftmInputTrig << SIM_FTMOPT1_FTM2SYNCBIT_SHIFT));

	return 1;
}


/***************************************************************************
 名称：BLDC_IC_Init
 作用：输入捕获初始化
  输入：无
 返回：无
 描述：ftm0statestructure（DC电机初始化结构体）ftm1statestructure（BLDC电机初始化结构体）
****************************************************************************/
void BLDC_IC_Init(void)
{


}

/***************************************************************************
 名称：FTM1_Overflow_ISR
 作用：溢出中断计数
  输入：无
 返回：无
 描述：优先级高于输入捕获中断
****************************************************************************/
void FTM1_Overflow_ISR(void)
{
	u32_IcuTicker++;

//	get_hallnum();
//
//	update_speedvalue();

	FTM_DRV_ClearStatusFlags(INST_BLDC_IC,(uint32_t)FTM_TIME_OVER_FLOW_FLAG);

}

/***************************************************************************
 名称：BLDC_HALLA_Callback
 作用：输入捕获中断
  输入：无
 返回：无
 描述：
****************************************************************************/
void BLDC_HALL0_Callback(ic_event_t event, void *userData)
{
	// Reset FTM2 counter every input capture event
	FTM1->CNT = 0 ;

	// Get commutation sector based on the Hall logic
	HALL_GetSector(&SensorHall);

	// Commutation period is measured by input capture mode of the FTM1_CH2 channel
	SensorHall.Period[SensorHall.Sector] = FTM_DRV_GetInputCaptureMeasurement(INST_BLDC_IC, 1U);

	/* Prepare PWM settings for the next commutation sector */
	ACTUATE_SetPwmMask(ui8FTM3OutmaskVal[rotationDir][SensorHall.Sector],
					  ui16FTM3SwOctrlVal[rotationDir][SensorHall.Sector], HW_INPUT_TRIG1);


	//get_hallnum();
	//采集新的hall状态
	//u16_BothHallCount++;
}
/***************************************************************************
 名称：BLDC_HALLA_Callback
 作用：输入捕获中断
  输入：无
 返回：无
 描述：
****************************************************************************/
void BLDC_HALL1_Callback(ic_event_t event, void *userData)
{
	// Reset FTM2 counter every input capture event
	FTM1->CNT = 0 ;

	// Get commutation sector based on the Hall logic
	HALL_GetSector(&SensorHall);

	// Commutation period is measured by input capture mode of the FTM1_CH2 channel
	SensorHall.Period[SensorHall.Sector] = FTM_DRV_GetInputCaptureMeasurement(INST_BLDC_IC, 4U);

	/* Prepare PWM settings for the next commutation sector */
	ACTUATE_SetPwmMask(ui8FTM3OutmaskVal[rotationDir][SensorHall.Sector],
					  ui16FTM3SwOctrlVal[rotationDir][SensorHall.Sector], HW_INPUT_TRIG1);

	//get_hallnum();
	//采集新的hall状态
	//u16_BothHallCount++;
}
/***************************************************************************
 名称：BLDC_HALLA_Callback
 作用：输入捕获中断
  输入：无
 返回：无
 描述：
****************************************************************************/
void BLDC_HALL2_Callback(ic_event_t event, void *userData)
{
	// Reset FTM2 counter every input capture event
	FTM1->CNT = 0 ;

	// Get commutation sector based on the Hall logic
	HALL_GetSector(&SensorHall);

	// Commutation period is measured by input capture mode of the FTM1_CH2 channel
	SensorHall.Period[SensorHall.Sector] = FTM_DRV_GetInputCaptureMeasurement(INST_BLDC_IC, 5U);

	/* Prepare PWM settings for the next commutation sector */
	ACTUATE_SetPwmMask(ui8FTM3OutmaskVal[rotationDir][SensorHall.Sector],
					  ui16FTM3SwOctrlVal[rotationDir][SensorHall.Sector], HW_INPUT_TRIG1);

	//get_hallnum();
	//采集新的hall状态
	//u16_BothHallCount++;
}
/***************************************************************************
 名称：BLDC_HALLA_Callback
 作用：输入捕获中断
  输入：无
 返回：无
 描述：
****************************************************************************/
void update_speedvalue(void)
{
	//更新速度
	float32 temp = (float32)u16_BothHallCount;
	if(u16_SpeedCount < 10)
	{
		SpeedIcuAvgValue -= SpeedIcuValue_100ms[u16_SpeedCount];
		SpeedIcuValue_100ms[u16_SpeedCount] = (temp/24/100)*100*60;
		SpeedIcuAvgValue += SpeedIcuValue_100ms[u16_SpeedCount];
		u16_SpeedCount++;
	}
	else
	{
		u16_SpeedCount = 0;
	}
	Speed_calc_Fb = SpeedIcuAvgValue;
	u16_HallCount = 0;
	u16_BothHallCount = 0;

}
void BLDC_HALL_Init(void)
{
	HALL_GetSector(&SensorHall);

	/* Prepare PWM settings for the next commutation sector */
	ACTUATE_SetPwmMask(ui8FTM3OutmaskVal[rotationDir][SensorHall.Sector],
					  ui16FTM3SwOctrlVal[rotationDir][SensorHall.Sector], HW_INPUT_TRIG1);
}

