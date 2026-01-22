/*
 * Hall_Pro.c
 *
 *  Created on: 2016?ê10??31è?
 *      Author: shenhua
 */

#include "Platform_Types.h"
#include "MOTORA_Settings.h"
#include "MOTORA_ICU.h"
#include "../BSP_DIO/BSP_DIO.h"



/* clockwise :		315462*/
/* anticlockwise : 	264513*/

uint8 u8_motor_type = 8U;	//电机类型
HALL3 hall3 = HALL_DEFAULT;

float32 delta_theta = 0.0;
float32 Speed_calc_Fb = 0.0;
float32 Speed_calc_Fb_pre = 0.0;
//float32 Speed_calc_Fb_diff = 0.0;

//uint8  rotationDir = ROTATION_DIR_CW;
uint8  rotationDir = ROTATION_DIR_CCW;

uint8 hall_array[2][6] =
{
	  /* Clockwise rotation direction */
	  {
			0,   /* sector 0 */
			4,   /* sector 1 */
			5,   /* sector 2 */
			2,   /* sector 3 */
			1,   /* sector 4 */
			3,   /* sector 5 */
	  },
	  /* Counterclockwise rotation direction */
	  {
			0,   /* sector 0 */
			2,   /* sector 1 */
			1,   /* sector 2 */
			4,   /* sector 3 */
			5,   /* sector 4 */
			3,   /* sector 5 */
	  }
};


uint32 delta_theta_test[50] = {0};
uint32 delta_theta_test1[50] = {0};
uint32 delta_theta_test2[50] = {0};

static uint32 hall_state_change_time[18] = {0};
static uint32 speed_state_change_sumtime = 0;
static float32 speed_state_change_avgtime = 0;

static uint32 speed_state_time = 0;
static uint32 speed_pre_state_time = 0;
static uint32 speed_hall_state_time = 0;
static boolean speed_pre_state_change = 0;    //计算速度时，前一个hall是否变化
static boolean speed_state_change = 0;    //计算速度时，前一个hall是否变化

static uint8 hall_state_count=0;
static uint8 hall_state_change_count=0;
static uint8 hall_state_init_count=0;			//霍尔初始计数器，用于初始化的霍尔变化计算
static uint8 hall_state_loop=0;


static uint16 su16_timer_hall_error_num = 0U;
static boolean sb_hall_error_num = FALSE;

extern float32 speed_erps;

uint8 direct_clockwise_num = 0;
uint8 direct_anticlockwise_num = 0;
uint8 direct_clockwise_num_sin = 0;
uint8 direct_anticlockwise_num_sin = 0;
//uint16 hall_state_bak = 0;
uint16 hall_state_sum = 0;
sint32 counter_loops_bak = 0U;

//
//uint16 cout = 0;
//uint16 halllog[100] = { 0 };
//float32 halltimelog[100] = { 0 };

tSensorHall 	SensorHall;



//==============================================================================
// DESCRIPTION :
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void clear_fault_hall(void)
{
	hall3.error_order = 0;
	hall3.error_num = 0;
}

//==============================================================================
// DESCRIPTION :
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void pre_hall_init(void)
{
	hall3.pre_hall_state = hall3.hall_state;
	hall3.pre_hall_state_sin = hall3.hall_state_sin;
}

//==============================================================================
// DESCRIPTION :
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void init_hall(void)
{

}
//==============================================================================
// DESCRIPTION :
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void get_hallnum(void)
{
    uint16 tmp1,tmp2;

    tmp1 = ((PINS_DRV_ReadPins(PTD) >> 8) & 0x01)<<2;
    tmp1 += ((PINS_DRV_ReadPins(PTB) >> 3) & 0x01)<<1;
    tmp1 += ((PINS_DRV_ReadPins(PTA) >> 11) & 0x01);

    tmp2 = ((PINS_DRV_ReadPins(PTD) >> 8) & 0x01)<<2;
    tmp2 += ((PINS_DRV_ReadPins(PTB) >> 3) & 0x01)<<1;
    tmp2 += ((PINS_DRV_ReadPins(PTA) >> 11) & 0x01);


    /*连读两次霍尔传感器值，相同才更新霍尔状态; 不同时，重新读一遍*/
    if((tmp1 == tmp2)&&( hall3.hall_state != tmp1))
    {
    	hall_state_sum++;
    	if(hall_state_sum > 1)
    	{
    		hall_state_sum = 0;

    		IcuHallTime.bak_hall_state = IcuHallTime.hall_state;
    		IcuHallTime.hall_state = tmp1;
    		IcuHallTime.hall_state_sin = tmp1;
    	}
    }
    else
    {
    	hall_state_sum = 0;
    }
}
//==============================================================================
// DESCRIPTION :eangle : EANGLE_0 , EANGLE_6 , EANGLE_12, EANGLE_18, EANGLE_24, EANGLE_30
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void hall_update(float32 eangle, uint16 pre_state, uint16 now_state, uint16 later_state)
{
	float32 eangle_margin_clockwise;		//电机顺时针转动进入一个电角度的边界值
	float32 eangle_margin_anticlockwise;	//电机逆时针转动进入一个电角度的边界值

	uint8 i;

	if (hall3.pre_hall_state != now_state)
	{
		if (pre_state == hall3.pre_hall_state)
		{
			direct_anticlockwise_num = 0;
			if (direct_clockwise_num > 1)
			{
				direct_clockwise_num = 0;
				hall3.direction = CLOCKWISE;
			}
			else
			{
				direct_clockwise_num++;
			}
			hall3.error_order = 0;
			counter_loops--;
		}
		else if (later_state == hall3.pre_hall_state)
		{
			direct_clockwise_num = 0;
			if (direct_anticlockwise_num > 1)
			{
				direct_anticlockwise_num = 0;
				hall3.direction = ANTICLOCKWISE;
			}
			else
			{
				direct_anticlockwise_num++;
			}
			hall3.error_order = 0;
			counter_loops++;
		}
		else
		{
			hall3.error_order = HALLSTATE_ORDER_ERROR;
		}


		speed_state_time = hall3.hall_state_time;
		speed_pre_state_time = hall3.pre_hall_state_time;
		hall3.pre_hall_state_time = hall3.hall_state_time;

	}
}

//==============================================================================
// DESCRIPTION :
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void get_HallState(void)// PWM Task
{

	hall3.hall_state = IcuHallTime.hall_state;
	hall3.hall_state_sin = IcuHallTime.hall_state_sin;

    switch(hall3.hall_state)
    {
		case HALLSTATE_5:
			sb_hall_error_num = FALSE;
			hall_update(EANGLE_6, HALLSTATE_1, HALLSTATE_5, HALLSTATE_4);

			break;

		case HALLSTATE_4:
			sb_hall_error_num = FALSE;
			hall_update(EANGLE_12, HALLSTATE_5, HALLSTATE_4, HALLSTATE_6);
			break;

		case HALLSTATE_6:
			sb_hall_error_num = FALSE;
			hall_update(EANGLE_18, HALLSTATE_4, HALLSTATE_6, HALLSTATE_2);
			break;

		case HALLSTATE_2:
			sb_hall_error_num = FALSE;
			hall_update(EANGLE_24, HALLSTATE_6, HALLSTATE_2, HALLSTATE_3);
			break;

		case HALLSTATE_3:
			sb_hall_error_num = FALSE;
			hall_update(EANGLE_30, HALLSTATE_2, HALLSTATE_3, HALLSTATE_1);
			break;

		case HALLSTATE_1:
			sb_hall_error_num = FALSE;
			hall_update(EANGLE_0, HALLSTATE_3, HALLSTATE_1, HALLSTATE_5);
			break;

		default:
			sb_hall_error_num = TRUE;
			break;
    }

    /*霍尔值有效时更新*/
//    if((hall3.error_num != HALLSTATE_NUM_ERROR) && (hall3.error_order != HALLSTATE_ORDER_ERROR))
//    {
    	//最后更新状态
    	hall3.pre_hall_state = hall3.hall_state;
    	hall3.pre_hall_state_sin = hall3.hall_state_sin;
//	}
}

//==============================================================================
// DESCRIPTION :电机霍尔传感器输出脉冲状态错误诊断
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void get_Speed_Value(void)// 计算电机转速
{
	Speed_calc_Fb = (hall3.direction*Speed_calc_Fb);
	counter_loops_bak = counter_loops;
}


//==============================================================================
// DESCRIPTION :电机霍尔传感器输出脉冲状态错误诊断
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
static void dia_hallA_error_num(void)
{
	su16_timer_hall_error_num++;

	if(TRUE == sb_hall_error_num)
	{
		if(su16_timer_hall_error_num > HALL_ERROR_NUM_DELAY_TIMES)
		{
			hall3.error_num = HALLSTATE_NUM_ERROR;
			su16_timer_hall_error_num = 0U;
		}
	}
	else
	{
		su16_timer_hall_error_num = 0U;
	}
}

//==============================================================================
// DESCRIPTION :
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
tBool HALL_GetSector(tSensorHall *Hall)
{
	Hall->InA = (PINS_DRV_ReadPins(PTD) >> 8) & 0x1;
	Hall->InB = (PINS_DRV_ReadPins(PTB) >> 3) & 0x1;
	Hall->InC = (PINS_DRV_ReadPins(PTA) >> 11)  & 0x1;
	Hall->InABC = ((Hall->InA << 2) + (Hall->InB << 1) + Hall->InC) - 1;

	Hall->Sector = hall_array[rotationDir][Hall->InABC];

	return 1;
}

//==============================================================================
// DESCRIPTION :
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void dia_hallA(void)
{
#if __HW_VERSION__ == 3
	dia_hallA_error_num();
#endif
	dia_hallA_error_num();

}

