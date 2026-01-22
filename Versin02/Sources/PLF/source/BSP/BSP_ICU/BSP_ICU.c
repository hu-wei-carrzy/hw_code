/*
 * BSP_ICU.c
 *
 *  Created on: 2024年12月20日
 *      Author: 00361759
 */
//------------------------------------------------------------------------------
// Body Identification
//------------------------------------------------------------------------------
#define bsp_icu "bsp_icu"
//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//------------------------------------------------------------------------------
#include "BSP_ICU.h"

//------------------------------------------------------------------------------
// Local constants
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Local macros
//------------------------------------------------------------------------------
#define Dir_CH0_Negative
#define Dir_CH1_Negative
#define Dir_CH2_Negative
#define Dir_CH3_Negative

//------------------------------------------------------------------------------
// Local data
//------------------------------------------------------------------------------
//通道HALL6 和  HALL10
static uint8_t IC_CH0_overflow = 0;
//通道HALL5 和  HALL8
static uint8_t IC_CH1_overflow = 0;
//通道HALL7 和  HALL9
static uint8_t IC_CH2_overflow = 0;
//通道HALL1 和  HALL4
static uint8_t IC_CH3_overflow = 0;

static ftm_state_t ftm0statestructure;
static ftm_state_t ftm1statestructure;

//------------------------------------------------------------------------------
// Exported data
//------------------------------------------------------------------------------
tBrushedMotorHallData Hall_CH0;
tBrushedMotorHallData Hall_CH1;
tBrushedMotorHallData Hall_CH2;
tBrushedMotorHallData Hall_CH3;


//------------------------------------------------------------------------------
// Local function prototypes
//------------------------------------------------------------------------------
void DCMotorA_A_Callback(ic_event_t event, void *userData);
void DCMotorB_A_Callback(ic_event_t event, void *userData);
void DCMotorC_A_Callback(ic_event_t event, void *userData);
void DCMotorD_A_Callback(ic_event_t event, void *userData);

//==============================================================================
// LOCAL FUNCTIONS
//==============================================================================

/***************************************************************************
 名称：IC_Init
 作用：输入捕获初始化
  输入：无
 返回：无
 描述：ftm0statestructure（DC电机初始化结构体）ftm1statestructure（BLDC电机初始化结构体）
****************************************************************************/
void IC_Init(void)
{

	memset(&Hall_CH0,0,sizeof(tBrushedMotorHallData));//结构体赋值为0；
	memset(&Hall_CH1,0,sizeof(tBrushedMotorHallData));
	memset(&Hall_CH2,0,sizeof(tBrushedMotorHallData));
	memset(&Hall_CH3,0,sizeof(tBrushedMotorHallData));

	//BSDC电机HALL的捕获通道初始化
    FTM_DRV_Init(INST_DC_IC1, &DC_ic1_InitConfig,&ftm0statestructure);
    FTM_DRV_InitInputCapture(INST_DC_IC1, &DC_ic1_InputCaptureConfig);

	//BLDC电机HALL的捕获通道初始化
    FTM_DRV_Init(INST_BLDC_IC, &BLDC_ic_InitConfig,&ftm1statestructure);
    FTM_DRV_InitInputCapture(INST_BLDC_IC, &BLDC_ic_InputCaptureConfig);

	//FTM0&FTM1的计数溢出接口初始化
	INT_SYS_InstallHandler(FTM0_Ovf_Reload_IRQn,&FTM0_Overflow_ISR,(isr_t*) 0U);
	INT_SYS_InstallHandler(FTM1_Ovf_Reload_IRQn,&FTM1_Overflow_ISR,(isr_t*) 0U);

	//FTM0&FTM1的溢出优先级
	INT_SYS_SetPriority(FTM0_Ovf_Reload_IRQn,12);
	INT_SYS_SetPriority(FTM1_Ovf_Reload_IRQn,12);

	//各通道捕获的优先级
	INT_SYS_SetPriority(FTM0_Ch0_Ch1_IRQn | FTM0_Ch2_Ch3_IRQn | FTM0_Ch4_Ch5_IRQn|FTM0_Ch6_Ch7_IRQn,11);
	INT_SYS_SetPriority(FTM1_Ch0_Ch1_IRQn | FTM1_Ch2_Ch3_IRQn | FTM1_Ch4_Ch5_IRQn|FTM1_Ch6_Ch7_IRQn,11);

	//使能FTM0&FTM1的溢出中断
	INT_SYS_EnableIRQ(FTM0_Ovf_Reload_IRQn);
	INT_SYS_EnableIRQ(FTM1_Ovf_Reload_IRQn);

	BSP_ICU_Init_CHx();
}
/***************************************************************************
 名称：IC_Init
 作用：输入捕获初始化
  输入：无
 返回：无
 描述：ftm0statestructure（DC电机初始化结构体）ftm1statestructure（BLDC电机初始化结构体）
****************************************************************************/
void BSP_ICU_Init_CHx(void)
{
	Hall_CH0.width = MaxRecord/2;
	Hall_CH0.Period = MaxRecord;
	Hall_CH0.direction = Halt;

	Hall_CH1.width = MaxRecord/2;
	Hall_CH1.Period = MaxRecord;
	Hall_CH1.direction = Halt;

	Hall_CH2.width = MaxRecord/2;
	Hall_CH2.Period = MaxRecord;
	Hall_CH2.direction = Halt;

	Hall_CH3.width = MaxRecord/2;
	Hall_CH3.Period = MaxRecord;
	Hall_CH3.direction = Halt;
}
/***************************************************************************
 名称：FTM0_Overflow_ISR
 作用：溢出中断计数
  输入：无
 返回：无
 描述：优先级高于输入捕获中断
****************************************************************************/
void FTM0_Overflow_ISR(void)
{
	IC_CH0_overflow++;
	IC_CH1_overflow++;
	IC_CH2_overflow++;
	IC_CH3_overflow++;

	if (IC_CH0_overflow > 1)
	{
		Hall_CH0.width = MaxRecord/2;
		Hall_CH0.Period = MaxRecord;
		//Hall_CH0.direction = Halt;
		IC_CH0_overflow = OverFLowHold;
	}
	if (IC_CH1_overflow > 1)
	{
		Hall_CH1.width = MaxRecord/2;
		Hall_CH1.Period = MaxRecord;
		//Hall_CH1.direction = Halt;
		IC_CH1_overflow = OverFLowHold;
	}
	if (IC_CH2_overflow > 1)
	{
		Hall_CH2.width = MaxRecord/2;
		Hall_CH2.Period = MaxRecord;
		//Hall_CH2.direction = Halt;
		IC_CH2_overflow = OverFLowHold;
	}
	if (IC_CH3_overflow > 1)
	{
		Hall_CH3.width = MaxRecord/2;
		Hall_CH3.Period = MaxRecord;
		//Hall_CH3.direction = Halt;
		IC_CH3_overflow = OverFLowHold;
	}

	FTM_DRV_ClearStatusFlags(INST_DC_IC1,(uint32_t)FTM_TIME_OVER_FLOW_FLAG);
}

/***************************************************************************
 名称：DCMotorA_A_Callback
 作用：输入捕获中断
  输入：无
 返回：无
 描述：电机A-A相脉冲Hall计算、占空比计算（双边捕获）,PTB12引脚
****************************************************************************/
void DCMotorA_A_Callback(ic_event_t event, void *userData)
{
	uint32_t value1,value2;
	uint8_t Pinlevel;

	Hall_CH0.before_edge_time = Hall_CH0.last_edge_time;
	Hall_CH0.last_edge_time = Hall_CH0.now_edge_time;
	Hall_CH0.now_edge_time = FTM_DRV_GetInputCaptureMeasurement(INST_DC_IC1,0);

	Pinlevel = (PINS_DRV_ReadPins(PTB) >> 12) & 0x01;

	if(Hall_CH0.before_edge_time != 0)
	{
		if( IC_CH0_overflow > 1 )
		{
			value1 = MaxRecord/2;
			value2 = MaxRecord/2;
		}
		else if(IC_CH0_overflow == 1)
		{
			if( Hall_CH0.last_edge_time < Hall_CH0.before_edge_time)
			{
				value1 = MaxRecord - Hall_CH0.before_edge_time + Hall_CH0.last_edge_time;
			}
			else
			{
				value1 = Hall_CH0.last_edge_time - Hall_CH0.before_edge_time;
			}
			if(Hall_CH0.now_edge_time < Hall_CH0.last_edge_time)
			{
				value2 = MaxRecord - Hall_CH0.last_edge_time + Hall_CH0.now_edge_time;
			}
			else
			{
				value2 = Hall_CH0.now_edge_time - Hall_CH0.last_edge_time;
			}
		}
		else
		{
			if(  Hall_CH0.last_edge_time <  Hall_CH0.before_edge_time)
			{
				value1 = MaxRecord - Hall_CH0.before_edge_time +  Hall_CH0.last_edge_time;
			}
			else
			{
				value1 = Hall_CH0.last_edge_time - Hall_CH0.before_edge_time;
			}
			value2 = Hall_CH0.now_edge_time - Hall_CH0.last_edge_time;
		}
		if(Pinlevel)
		{
			Hall_CH0.width = value1;
			Hall_CH0.Period = value1+value2;
		}
		else
		{
			Hall_CH0.width = value2;
			Hall_CH0.Period = value1+value2;
		}
		Hall_CH0.A_HallCount++;
		IC_CH0_overflow = 0;
	}
}

/***************************************************************************
 名称：DCMotorA_B_Callback
 作用：电机A的B相脉冲
  输入：无
 返回：无
 描述：电机A方向判断（上升沿捕获）1为正转 2为反转 0为无结果
****************************************************************************/
void DCMotorA_B_Callback(ic_event_t event, void *userData)
{
	Hall_CH0.B_HallCount++;
	uint8_t PinAlevel = (PINS_DRV_ReadPins(PTB) >> 12) & 0x01;
	uint8_t PinBlevel = (PINS_DRV_ReadPins(PTB) >> 13) & 0x01;
#ifndef Dir_CH0_Negative
	if((PinAlevel == 1)&&(PinBlevel == 1))
	{
		Hall_CH0.direction = Positive;
	}
	else if((PinAlevel == 0)&&(PinBlevel == 0))
	{
		Hall_CH0.direction = Positive;
	}
	else if((PinAlevel == 0)&&(PinBlevel == 1))
	{
		Hall_CH0.direction = Negative;
	}
	else if((PinAlevel == 1)&&(PinBlevel == 0))
	{
		Hall_CH0.direction = Negative;
	}
	else
	{
		Hall_CH0.direction = Fault;
	}
#else
	{
		if((PinAlevel == 1)&&(PinBlevel == 1))
		{
			Hall_CH0.direction = Negative;
		}
		else if((PinAlevel == 0)&&(PinBlevel == 0))
		{
			Hall_CH0.direction = Negative;
		}
		else if((PinAlevel == 0)&&(PinBlevel == 1))
		{
			Hall_CH0.direction = Positive;
		}
		else if((PinAlevel == 1)&&(PinBlevel == 0))
		{
			Hall_CH0.direction = Positive;
		}
		else
		{
			Hall_CH0.direction = Fault;
		}
	}
#endif

}

/***************************************************************************
 名称：DCMotorB_A_Callback
 作用：输入捕获中断
  输入：无
 返回：无
 描述：电机B-A相脉冲Hall计算、占空比计算（双边捕获）,PTB14引脚
****************************************************************************/
void DCMotorB_A_Callback(ic_event_t event, void *userData)
{
	uint32_t value1,value2;
	uint8_t Pinlevel;

	Hall_CH1.before_edge_time = Hall_CH1.last_edge_time;
	Hall_CH1.last_edge_time = Hall_CH1.now_edge_time;
	Hall_CH1.now_edge_time = FTM_DRV_GetInputCaptureMeasurement(INST_DC_IC1,2);

	Pinlevel = (PINS_DRV_ReadPins(PTB) >> 14) & 0x01;

	if(Hall_CH1.before_edge_time != 0)
	{
		if( IC_CH1_overflow > 1 )
		{
			value1 = MaxRecord/2;
			value1 = MaxRecord/2;
		}
		else if(IC_CH1_overflow == 1)
		{
			if( Hall_CH1.last_edge_time < Hall_CH1.before_edge_time)
			{
				value1 = MaxRecord - Hall_CH1.before_edge_time + Hall_CH1.last_edge_time;
			}
			else
			{
				value1 = Hall_CH1.last_edge_time - Hall_CH1.before_edge_time;
			}
			if(Hall_CH1.now_edge_time < Hall_CH1.last_edge_time)
			{
				value2 = MaxRecord - Hall_CH1.last_edge_time + Hall_CH1.now_edge_time;
			}
			else
			{
				value2 = Hall_CH1.now_edge_time - Hall_CH1.last_edge_time;
			}
		}
		else
		{
			if(  Hall_CH1.last_edge_time <  Hall_CH1.before_edge_time)
			{
				value1 = MaxRecord - Hall_CH1.before_edge_time +  Hall_CH1.last_edge_time;
			}
			else
			{
				value1 = Hall_CH1.last_edge_time - Hall_CH1.before_edge_time;
			}
			value2 = Hall_CH1.now_edge_time - Hall_CH1.last_edge_time;
		}
		if(Pinlevel)
		{
			Hall_CH1.width = value1;
			Hall_CH1.Period = value1+value2;
		}
		else
		{
			Hall_CH1.width = value2;
			Hall_CH1.Period = value1+value2;
		}
		Hall_CH1.A_HallCount++;
		IC_CH1_overflow = 0;
	}
}

/***************************************************************************
 名称：DCMotorB_B_Callback
 作用：电机B的B相脉冲
  输入：无
 返回：无
 描述：电机A方向判断（上升沿捕获）1为正转 2为反转 0为无结果
****************************************************************************/
void DCMotorB_B_Callback(ic_event_t event, void *userData)
{
	Hall_CH1.B_HallCount++;
	uint8_t PinAlevel = (PINS_DRV_ReadPins(PTB) >> 14) & 0x01;
	uint8_t PinBlevel = (PINS_DRV_ReadPins(PTD) >> 1) & 0x01;
#ifndef Dir_CH1_Negative
	if((PinAlevel == 1)&&(PinBlevel == 1))
	{
		Hall_CH1.direction = Positive;
	}
	else if((PinAlevel == 0)&&(PinBlevel == 0))
	{
		Hall_CH1.direction = Positive;
	}
	else if((PinAlevel == 0)&&(PinBlevel == 1))
	{
		Hall_CH1.direction = Negative;
	}
	else if((PinAlevel == 1)&&(PinBlevel == 0))
	{
		Hall_CH1.direction = Negative;
	}
	else
	{
		Hall_CH1.direction = Fault;
	}
#else
	{
		if((PinAlevel == 1)&&(PinBlevel == 1))
		{
			Hall_CH1.direction = Negative;
		}
		else if((PinAlevel == 0)&&(PinBlevel == 0))
		{
			Hall_CH1.direction = Negative;
		}
		else if((PinAlevel == 0)&&(PinBlevel == 1))
		{
			Hall_CH1.direction = Positive;
		}
		else if((PinAlevel == 1)&&(PinBlevel == 0))
		{
			Hall_CH1.direction = Positive;
		}
		else
		{
			Hall_CH1.direction = Fault;
		}
	}
#endif
}

/***************************************************************************
 名称：DCMotorC_A_Callback
 作用：输入捕获中断
  输入：无
 返回：无
 描述：电机C-A相脉冲Hall计算、占空比计算（双边捕获）,PTB4引脚
****************************************************************************/
void DCMotorC_A_Callback(ic_event_t event, void *userData)
{
	uint32_t value1,value2;
	uint8_t Pinlevel;

	Hall_CH2.before_edge_time = Hall_CH2.last_edge_time;
	Hall_CH2.last_edge_time = Hall_CH2.now_edge_time;
	Hall_CH2.now_edge_time = FTM_DRV_GetInputCaptureMeasurement(INST_DC_IC1,4);

	Pinlevel = (PINS_DRV_ReadPins(PTB) >> 4) & 0x01;

	if(Hall_CH2.before_edge_time != 0)
	{
		if( IC_CH2_overflow > 1 )
		{
			value1 = MaxRecord/2;
			value2 = MaxRecord/2;
		}
		else if(IC_CH2_overflow == 1)
		{
			if( Hall_CH2.last_edge_time < Hall_CH2.before_edge_time)
			{
				value1 = MaxRecord - Hall_CH2.before_edge_time + Hall_CH2.last_edge_time;
			}
			else
			{
				value1 = Hall_CH2.last_edge_time - Hall_CH2.before_edge_time;
			}
			if(Hall_CH2.now_edge_time < Hall_CH2.last_edge_time)
			{
				value2 = MaxRecord - Hall_CH2.last_edge_time + Hall_CH2.now_edge_time;
			}
			else
			{
				value2 = Hall_CH2.now_edge_time - Hall_CH2.last_edge_time;
			}
		}
		else
		{
			if(  Hall_CH2.last_edge_time <  Hall_CH2.before_edge_time)
			{
				value1 = MaxRecord - Hall_CH2.before_edge_time +  Hall_CH2.last_edge_time;
			}
			else
			{
				value1 = Hall_CH2.last_edge_time - Hall_CH2.before_edge_time;
			}
			value2 = Hall_CH2.now_edge_time - Hall_CH2.last_edge_time;
		}
		if(Pinlevel)
		{
			Hall_CH2.width = value1;
			Hall_CH2.Period = value1+value2;
		}
		else
		{
			Hall_CH2.width = value2;
			Hall_CH2.Period = value1+value2;
		}
		Hall_CH2.A_HallCount++;
		IC_CH2_overflow = 0;
	}
}


/***************************************************************************
 名称：DCMotorC_D_Callback
 作用：电机A的B相脉冲
  输入：无
 返回：无
 描述：电机A方向判断（上升沿捕获）1为正转 2为反转 0为无结果
****************************************************************************/
void DCMotorC_B_Callback(ic_event_t event, void *userData)
{
	Hall_CH2.B_HallCount++;
	uint8_t PinAlevel = (PINS_DRV_ReadPins(PTB) >> 4) & 0x01;
	uint8_t PinBlevel = (PINS_DRV_ReadPins(PTB) >> 17) & 0x01;
#ifndef Dir_CH2_Negative
	if((PinAlevel == 1)&&(PinBlevel == 1))
	{
		Hall_CH2.direction = Positive;
	}
	else if((PinAlevel == 0)&&(PinBlevel == 0))
	{
		Hall_CH2.direction = Positive;
	}
	else if((PinAlevel == 0)&&(PinBlevel == 1))
	{
		Hall_CH2.direction = Negative;
	}
	else if((PinAlevel == 1)&&(PinBlevel == 0))
	{
		Hall_CH2.direction = Negative;
	}
	else
	{
		Hall_CH2.direction = Fault;
	}
#else
	{
		if((PinAlevel == 1)&&(PinBlevel == 1))
		{
			Hall_CH2.direction = Negative;
		}
		else if((PinAlevel == 0)&&(PinBlevel == 0))
		{
			Hall_CH2.direction = Negative;
		}
		else if((PinAlevel == 0)&&(PinBlevel == 1))
		{
			Hall_CH2.direction = Positive;
		}
		else if((PinAlevel == 1)&&(PinBlevel == 0))
		{
			Hall_CH2.direction = Positive;
		}
		else
		{
			Hall_CH2.direction = Fault;
		}
	}
#endif
}

/***************************************************************************
 名称：DCMotorD_A_Callback
 作用：输入捕获中断
  输入：无
 返回：无
 描述：电机D-A相脉冲Hall计算、占空比计算（双边捕获）,PTE8引脚
****************************************************************************/
void DCMotorD_B_Callback(ic_event_t event, void *userData)
{
	uint32_t value1,value2;
	uint8_t Pinlevel;

	Hall_CH3.before_edge_time = Hall_CH3.last_edge_time;
	Hall_CH3.last_edge_time = Hall_CH3.now_edge_time;
	Hall_CH3.now_edge_time = FTM_DRV_GetInputCaptureMeasurement(INST_DC_IC1,7);

	Pinlevel = (PINS_DRV_ReadPins(PTE) >> 7) & 0x01;

	if(Hall_CH3.before_edge_time != 0)
	{
		if( IC_CH3_overflow > 1 )
		{
			value1 = MaxRecord/2;
			value2 = MaxRecord/2;
		}
		else if(IC_CH3_overflow == 1)
		{
			if( Hall_CH3.last_edge_time < Hall_CH3.before_edge_time)
			{
				value1 = MaxRecord - Hall_CH3.before_edge_time + Hall_CH3.last_edge_time;
			}
			else
			{
				value1 = Hall_CH3.last_edge_time - Hall_CH3.before_edge_time;
			}
			if(Hall_CH3.now_edge_time < Hall_CH3.last_edge_time)
			{
				value2 = MaxRecord - Hall_CH3.last_edge_time + Hall_CH3.now_edge_time;
			}
			else
			{
				value2 = Hall_CH3.now_edge_time - Hall_CH3.last_edge_time;
			}
		}
		else
		{
			if(  Hall_CH3.last_edge_time <  Hall_CH3.before_edge_time)
			{
				value1 = MaxRecord - Hall_CH3.before_edge_time +  Hall_CH3.last_edge_time;
			}
			else
			{
				value1 = Hall_CH3.last_edge_time - Hall_CH3.before_edge_time;
			}
			value2 = Hall_CH3.now_edge_time - Hall_CH3.last_edge_time;
		}
		if(Pinlevel)
		{
			Hall_CH3.width = value1;
			Hall_CH3.Period = value1+value2;
		}
		else
		{
			Hall_CH3.width = value2;
			Hall_CH3.Period = value1+value2;
		}
		Hall_CH3.A_HallCount++;
		IC_CH3_overflow = 0;
	}
}


/***************************************************************************
 名称：DCMotorD_B_Callback
 作用：电机A的B相脉冲
  输入：无
 返回：无
 描述：电机A方向判断（上升沿捕获）1为正转 2为反转 0为无结果
****************************************************************************/
void DCMotorD_A_Callback(ic_event_t event, void *userData)
{
	Hall_CH3.B_HallCount++;
	uint8_t PinAlevel = (PINS_DRV_ReadPins(PTE) >> 7) & 0x01;
	uint8_t PinBlevel = (PINS_DRV_ReadPins(PTE) >> 8) & 0x01;
#ifndef Dir_CH3_Negative
	if((PinAlevel == 1)&&(PinBlevel == 1))
	{
		Hall_CH3.direction = Positive;
	}
	else if((PinAlevel == 0)&&(PinBlevel == 0))
	{
		Hall_CH3.direction = Positive;
	}
	else if((PinAlevel == 0)&&(PinBlevel == 1))
	{
		Hall_CH3.direction = Negative;
	}
	else if((PinAlevel == 1)&&(PinBlevel == 0))
	{
		Hall_CH3.direction = Negative;
	}
	else
	{
		Hall_CH3.direction = Fault;
	}
#else
	{
		if((PinAlevel == 1)&&(PinBlevel == 1))
		{
			Hall_CH3.direction = Negative;
		}
		else if((PinAlevel == 0)&&(PinBlevel == 0))
		{
			Hall_CH3.direction = Negative;
		}
		else if((PinAlevel == 0)&&(PinBlevel == 1))
		{
			Hall_CH3.direction = Positive;
		}
		else if((PinAlevel == 1)&&(PinBlevel == 0))
		{
			Hall_CH3.direction = Positive;
		}
		else
		{
			Hall_CH3.direction = Fault;
		}
	}
#endif
}

/***************************************************************************
 名称：BSP_GetHall_CH0
 作用：读取CH0通道的Hall
  输入：无
 返回：无
 描述：作为10ms任务存在，10ms读取Hall值并清零
****************************************************************************/
uint16_t BSP_GetHall_CH0(void)
{
	 uint16_t SumHall = Hall_CH0.A_HallCount + Hall_CH0.B_HallCount;
	 Hall_CH0.A_HallCount = 0;
	 Hall_CH0.B_HallCount = 0;
	 return SumHall;
}
uint16_t BSP_GetHallA_CH0(void)
{
	 uint16_t CH0_HallA = Hall_CH0.A_HallCount;
	 Hall_CH0.A_HallCount = 0;
	 return CH0_HallA;
}
uint16_t BSP_GetHallB_CH0(void)
{
	 uint16_t CH0_HallB = Hall_CH0.B_HallCount;
	 Hall_CH0.B_HallCount = 0;
	 return CH0_HallB;
}
/***************************************************************************
 名称：BSP_GetHall_CH1
 作用：读取CH1通道的Hall
  输入：无
 返回：无
 描述：作为10ms任务存在，10ms读取Hall值并清零
****************************************************************************/
uint16_t BSP_GetHall_CH1(void)
{
	 uint16_t SumHall = Hall_CH1.A_HallCount + Hall_CH1.B_HallCount;
	 Hall_CH1.A_HallCount = 0;
	 Hall_CH1.B_HallCount = 0;
	 return SumHall;
}
uint16_t BSP_GetHallA_CH1(void)
{
	 uint16_t CH1_HallA = Hall_CH1.A_HallCount;
	 Hall_CH1.A_HallCount = 0;
	 return CH1_HallA;
}
uint16_t BSP_GetHallB_CH1(void)
{
	 uint16_t CH1_HallB = Hall_CH1.B_HallCount;
	 Hall_CH1.B_HallCount = 0;
	 return CH1_HallB;
}
/***************************************************************************
 名称：BSP_GetHall_CH2
 作用：读取CH2通道的Hall
  输入：无
 返回：无
 描述：作为10ms任务存在，10ms读取Hall值并清零
****************************************************************************/
uint16_t BSP_GetHall_CH2(void)
{
	 uint16_t SumHall = Hall_CH2.A_HallCount + Hall_CH2.B_HallCount;
	 Hall_CH2.A_HallCount = 0;
	 Hall_CH2.B_HallCount = 0;
	 return SumHall;
}
uint16_t BSP_GetHallA_CH2(void)
{
	 uint16_t CH2_HallA = Hall_CH2.A_HallCount;
	 Hall_CH2.A_HallCount = 0;
	 return CH2_HallA;
}
uint16_t BSP_GetHallB_CH2(void)
{
	 uint16_t CH2_HallB = Hall_CH2.B_HallCount;
	 Hall_CH2.B_HallCount = 0;
	 return CH2_HallB;
}
/***************************************************************************
 名称：BSP_GetHall_CH3
 作用：读取CH3通道的Hall
  输入：无
 返回：无
 描述：作为10ms任务存在，10ms读取Hall值并清零
****************************************************************************/
uint16_t BSP_GetHall_CH3(void)
{
	 uint16_t SumHall = Hall_CH3.A_HallCount + Hall_CH3.B_HallCount;
	 Hall_CH3.A_HallCount = 0;
	 Hall_CH3.B_HallCount = 0;
	 return SumHall;
}
uint16_t BSP_GetHallA_CH3(void)
{
	 uint16_t CH3_HallA = Hall_CH3.A_HallCount;
	 Hall_CH3.A_HallCount = 0;
	 return CH3_HallA;
}
uint16_t BSP_GetHallB_CH3(void)
{
	 uint16_t CH3_HallB = Hall_CH3.B_HallCount;
	 Hall_CH3.B_HallCount = 0;
	 return CH3_HallB;
}
/***************************************************************************
 名称：BSP_GetSpeed_CH0
 作用：读取CH0通道的Hall
  输入：无
 返回：无
 描述：作为10ms任务存在，10ms读取Hall值并清零
****************************************************************************/
uint16_t BSP_GetSpeed_CH0(void)
{
	uint16_t tmp;
	tmp = (Second2Us * Second2Min / (Hall_CH0.Period * HALL_IC1_Time * HALL_A_POLES));
	if(tmp < 10)
	{
		tmp = 0;
	}
	return tmp;
}
/***************************************************************************
 名称：BSP_GetSpeed_CH1
 作用：读取CH1通道的Hall
  输入：无
 返回：无
 描述：作为10ms任务存在，10ms读取Hall值并清零
****************************************************************************/
uint16_t BSP_GetSpeed_CH1(void)
{
	uint16_t tmp;
	tmp = Second2Us * Second2Min / (Hall_CH1.Period * HALL_IC1_Time * HALL_B_POLES);
	if(tmp < 10)
	{
		tmp = 0;
	}
	return tmp;
}
/***************************************************************************
 名称：BSP_GetSpeed_CH2
 作用：读取CH2通道的Hall
  输入：无
 返回：无
 描述：作为10ms任务存在，10ms读取Hall值并清零
****************************************************************************/
uint16_t BSP_GetSpeed_CH2(void)
{
	uint16_t tmp;
	tmp = Second2Us * Second2Min / (Hall_CH2.Period * HALL_IC1_Time * HALL_C_POLES);
	if(tmp < 10)
	{
		tmp = 0;
	}
	return tmp;
}
/***************************************************************************
 名称：BSP_GetSpeed_CH3
 作用：读取CH3通道的Hall
  输入：无
 返回：无
 描述：作为10ms任务存在，10ms读取Hall值并清零
****************************************************************************/
uint16_t BSP_GetSpeed_CH3(void)
{
	uint16_t tmp;
	tmp = Second2Us * Second2Min / (Hall_CH3.Period * HALL_IC1_Time * HALL_D_POLES);
	if(tmp < 10)
	{
		tmp = 0;
	}
	return tmp;
}
/***************************************************************************
 名称：BSP_ICU_Direction
 作用：读取对应电机Direction
  输入：无
 返回：无
 描述：
****************************************************************************/
uint8_t BSP_ICU_Direction_CH0(void)
{
	uint8_t Direction = Hall_CH0.direction;
	return Direction;
}
/***************************************************************************
 名称：BSP_ICU_Direction
 作用：读取对应电机Direction
  输入：无
 返回：无
 描述：
****************************************************************************/
uint8_t BSP_ICU_Direction_CH1(void)
{
	uint8_t Direction = Hall_CH1.direction;
	return Direction;
}
/***************************************************************************
 名称：BSP_ICU_Direction
 作用：读取对应电机Direction
  输入：无
 返回：无
 描述：
****************************************************************************/
uint8_t BSP_ICU_Direction_CH2(void)
{
	uint8_t Direction = Hall_CH2.direction;
	return Direction;
}
/***************************************************************************
 名称：BSP_ICU_Direction
 作用：读取对应电机Direction
  输入：无
 返回：无
 描述：
****************************************************************************/
uint8_t BSP_ICU_Direction_CH3(void)
{
	uint8_t Direction = Hall_CH3.direction;
	return Direction;
}




