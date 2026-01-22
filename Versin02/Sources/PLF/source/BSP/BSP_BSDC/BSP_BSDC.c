/*
 * BSP_BSDC.c
 *
 *  Created on: 2025年5月8日
 *      Author: lenovo
 */
 //------------------------------------------------------------------------------
 // Body Identification
 //------------------------------------------------------------------------------
#define bsp_bsdc "bsp_bsdc"
//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//------------------------------------------------------------------------------
#include "BSP_BSDC.h"
//------------------------------------------------------------------------------
// Local constants
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Local macros
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Local data
//------------------------------------------------------------------------------
static float32	current_max_sum_A = 0;
static float32	current_max_sum_B = 0;
static float32	current_max_sum_C = 0;
static float32	current_max_sum_D = 0;

//------------------------------------------------------------------------------
// Exported data
//------------------------------------------------------------------------------



float Setduty;
float duty;

_PID pid;

//------------------------------------------------------------------------------
// Local function prototypes
//------------------------------------------------------------------------------

//==============================================================================
// LOCAL FUNCTIONS
//==============================================================================

/***************************************************************************
 名称：PID_Init
 作用：PID参数初始化
  输入：无
 返回：无
 描述：
****************************************************************************/
void PID_Init(void)
{
	pid.target_val = 0.0;
	pid.actual_val = 0.0;
	pid.err = 0.0;
	pid.err_last = 0.0;
	pid.integral = 0.0;
	pid.Kp = 0.1;//0.0;
	pid.Ki = 0.01;//0.0;
	pid.Kd = 0.0;//0.0;
}


/***************************************************************************
 名称：PID_parameter_control
 作用：kp\ki\kd 设置
  输入：无
 返回：无
 描述：
****************************************************************************/
void PID_parameter_control(float KP, float KI, float KD)
{
	pid.Kp = KP;
	pid.Ki = KI;
	pid.Kd = KD;
}
/***************************************************************************
 名称：PID_Common
 作用：PID算法
  输入：无
 返回：无
 描述：
****************************************************************************/
float PID_Common(float actual_val)
{
	pid.err = pid.target_val - actual_val;													//计算目标值和当前值的误差
	pid.integral += pid.err;																//误差累积
	pid.actual_val = pid.Kp * pid.err + pid.Ki * pid.integral + pid.Kd * (pid.err - pid.err_last);	//PID公式计算
	pid.err_last = pid.err;																	//传递误差
	return pid.actual_val;
}

/***************************************************************************
 名称：Motor_DutyStep_control
 作用：电机控制速度环PID
  输入：无
 返回：无
 描述：
****************************************************************************/
void Motor_DutyStep_control(int8_t channel , uint8_t SetDuty )
{
	BSP_PWM_SetDuty(DC_PWM, channel, SetDuty);
}


/***************************************************************************
 名称：Motor_stopA
 作用：相关参数清0
  输入：
 返回：无
 描述：每次电机停止时，调用此函数对参数进行清0
****************************************************************************/
void Motor_stop(DutyControl *P)
{
	memset(P,0,sizeof(DutyControl));
	//MotorDRun = false;
}

//==============================================================================
// EXPORTED FUNCTIONS
//==============================================================================
/***************************************************************************
 名称：BSPBSDC_Init
 作用：控制初始化
  输入：
 返回：无
 描述：
****************************************************************************/
void BSPBSDC_Init(void)
{
	//设置SPI的片选信号
    DRV8718_Awake();
    //设置SPI的配置参数
	SPI_Init();
	//设置8718预驱的参数
	DRV8718_Init();
	//设置Pid参数
	PID_Init();

}
//==============================================================================
// DESCRIPTION :获取电机通道的初始值
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
bool BSPBSDC_InitCur_Chn(uint8_t tmpchl , int16_t* Value)
{
	int8_t tmpchl_dec = tmpchl - 1;
	int8_t tmpcount;
	int8_t ret = false;

	static uint8 initcount = 99;
	static uint16 Initvol_Value_sum = 0;

	if((tmpchl_dec == 1)||(tmpchl_dec == 3))
	{
		*Value = 0;
		ret = true;
	}

	if (DC_current_max[tmpchl_dec][initcount] != 0)
	{
		for(tmpcount = initcount; tmpcount > initcount - 5;tmpcount--)
		{
			Initvol_Value_sum += DC_current_max[tmpchl_dec][tmpcount];
		}
		*Value = Initvol_Value_sum / 5;
		Initvol_Value_sum = 0;
		ret = true;
	}

	return ret;
}

//==============================================================================
// DESCRIPTION :获取A项DC电机电流平均值
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
uint16 GetBSDCAvgCurA(void)
{
    uint16 TempCurVal;
    uint8 i;

	current_max_sum_A = 0;

	for(i=0; i<100; i++)
	{
		current_max_sum_A += DC_current_max[0][i];
	}
	current_max_sum_A = current_max_sum_A/100;

	TempCurVal = current_max_sum_A;

    return TempCurVal;
}
//==============================================================================
// DESCRIPTION :获取B项DC电机电流平均值
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
uint16 GetBSDCAvgCurB(void)
{
    uint16 TempCurVal;
    uint8 i;

	current_max_sum_B = 0;

	for(i=0; i<100; i++)
	{
		current_max_sum_B += DC_current_max[1][i];
	}
	current_max_sum_B = current_max_sum_B/100;

	TempCurVal = current_max_sum_B;

    return TempCurVal;
}
//==============================================================================
// DESCRIPTION :获取C项DC电机电流平均值
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
uint16 GetBSDCAvgCurC(void)
{
    uint16 TempCurVal;
    uint8 i;

	current_max_sum_C = 0;

	for(i=0; i<100; i++)//考虑能否不适用For循环，累加器？
	{
		current_max_sum_C += DC_current_max[2][i];
	}
	current_max_sum_C = current_max_sum_C/100;

	TempCurVal = current_max_sum_C;

    return TempCurVal;
}
//==============================================================================
// DESCRIPTION :获取D项DC电机电流平均值
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
uint16 GetBSDCAvgCurD(void)
{
    uint16 TempCurVal;
    uint8 i;

	current_max_sum_D = 0;

	for(i=0; i<100; i++)
	{
		current_max_sum_D += DC_current_max[3][i];
	}
	current_max_sum_D = current_max_sum_D/100;

	TempCurVal = current_max_sum_D;

    return TempCurVal;
}
/***************************************************************************
 名称：GetBSDCAvgSpeedA
 作用：计算速度平均值
  输入：
 返回：无
 描述：
****************************************************************************/
uint16_t GetBSDCAvgSpeedA()
{
	static uint16_t speed[5] = {0};
	uint16_t sum = 0;
	uint16_t speed_average = 0;//（暂时局部进行接收）全局变量，后面算法会进行调用
	//速度采集
	speed[0] = speed[1];
	speed[1] = speed[2];
	speed[2] = speed[3];
	speed[3] = speed[4];
	speed[4] = BSP_GetSpeed_CH0();
	sum = speed[0] + speed[1] + speed[2] + speed[3] + speed[4];
	speed_average = sum / 5;
	return speed_average;
}
/***************************************************************************
 名称：GetBSDCAvgSpeedB
 作用：计算速度平均值
  输入：
 返回：无
 描述：
****************************************************************************/
uint16_t GetBSDCAvgSpeedB()
{
	static uint16_t speed[5] = {0};
	uint16_t sum = 0;
	uint16_t speed_average = 0;//（暂时局部进行接收）全局变量，后面算法会进行调用
	//速度采集
	speed[0] = speed[1];
	speed[1] = speed[2];
	speed[2] = speed[3];
	speed[3] = speed[4];
	speed[4] = BSP_GetSpeed_CH1();
	sum = speed[0] + speed[1] + speed[2] + speed[3] + speed[4];
	speed_average = sum / 5;
	return speed_average;
}
/***************************************************************************
 名称：GetBSDCAvgSpeedC
 作用：计算速度平均值
  输入：
 返回：无
 描述：
****************************************************************************/
uint16_t GetBSDCAvgSpeedC()
{
	static uint16_t speed[5] = {0};
	uint16_t sum = 0;
	uint16_t speed_average = 0;//（暂时局部进行接收）全局变量，后面算法会进行调用
	//速度采集
	speed[0] = speed[1];
	speed[1] = speed[2];
	speed[2] = speed[3];
	speed[3] = speed[4];
	speed[4] = BSP_GetSpeed_CH2();
	sum = speed[0] + speed[1] + speed[2] + speed[3] + speed[4];
	speed_average = sum / 5;
	return speed_average;
}
/***************************************************************************
 名称：GetBSDCAvgSpeedA
 作用：计算速度平均值
  输入：
 返回：无
 描述：
****************************************************************************/
uint16_t GetBSDCAvgSpeedD()
{
	static uint16_t speed[5] = {0};
	uint16_t sum = 0;
	uint16_t speed_average = 0;//（暂时局部进行接收）全局变量，后面算法会进行调用
	//速度采集
	speed[0] = speed[1];
	speed[1] = speed[2];
	speed[2] = speed[3];
	speed[3] = speed[4];
	speed[4] = BSP_GetSpeed_CH3();
	sum = speed[0] + speed[1] + speed[2] + speed[3] + speed[4];
	speed_average = sum / 5;
	return speed_average;
}
