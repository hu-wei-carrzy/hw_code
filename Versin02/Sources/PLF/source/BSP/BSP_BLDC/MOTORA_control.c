/*
 * DMC_control.c
 *
 * Created on: 2017年4月17日
 * Author    : shenhua
 */

#include "../BSP_DIO/BSP_DIO.h"
#include "MOTORA_Settings.h"
#include "../../DAT/DAT_BLDC/DAT_BLDC_TYPEEXPORT.h"
#include "../../DAT/DAT_BLDC/DAT_BLDC.h"

static float32 dI_iq_fb         = 0.0;    //电流差值
static uint16 tmp_open_blocked  = FALSE;
static uint16 tmp_close_blocked = FALSE;

static uint16 hall_blocked_pre0    = 0U;
static uint16 hall_blocked_pre1    = 1U;
static uint16 hall_pre0_rotor_stop = 0U;
static uint16 hall_pre1_rotor_stop = 1U;

static float32 Bldc_Current_Change = 0.006; //5000/(4096*38.01*2.5)*1000mA=12.864(mA)

uint32 u32_blocked_timer     = 0U;     //堵转计时
uint32 u32_rotor_stop_timer  = 0U;     //转子停转计时
uint16 flag_close_blocked    = FALSE;  //关门堵转标志
uint16 flag_open_blocked     = FALSE;  //开门堵转标志
uint16 flag_close_blocked_HC = FALSE;  //
uint16 flag_open_blocked_HC  = FALSE;  //
uint16 flag_rotor_stop       = FALSE;  //转子停转标志
uint8  uint8_door_type       = 0U;     //门洞类型
uint8  POLES                 = 8U;     //级数-联谊3对极6极


//电流预紧状态更新
static float32 siq_ref_pre = 0.0;
static float32 delta_ref;
static uint32 u32_delta_ref_timer   = 0U;
static uint16 flag_ref_delta_stable = FALSE;
static uint16 u16_delta_ref_prescaler;
static uint8 suint8_hall_state;

uint16  GetMaxCurTimes    = 0;
float32 GetMaxCurrent     = 0;
uint16  GetMaxCurrent_lim = 20000;  //全程最大限制电流mA

float32 CUR_MAX   = 20000;      //最大限制电流
float32 iq_offset = 2059;
float32 ADataArray[4];
float32 Bldc_current_max[200];
float32 current_max_sum = 0;

float32 pi_Kp        = 0.05;    //0.008
float32 pi_Ki        = 0.01;//0.001;
float32 pi_Vi_MAX     = 60000;    //0.008

float32 Speed_Vi_MAX = 20000;
float32 Speed_Kp_MAX = 0.05;   //0.01
float32 Speed_Ki_MAX = 0.01;//0.001;  //0.0006

float32 pi_iq_MAX    = 30000.0;

//uint16 cout = 0;
//uint16 halllog[100] = { 0 };
//float32 halltimelog[100] = { 0 };

//==============================================================================
// DESCRIPTION :堵转 , 持续TIMER_BLOCK_TURN : 电流达到，转子不动
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
static void update_block_state(void)
{
	if((SpeedRef > 0)&&(pi_iq.Fbk > IQ_FB_CLOSE_BLOCK)&&(hall3.direction == ANTICLOCKWISE))//关门过程中出现反转信号
	{
		flag_close_blocked = TRUE;
		u32_blocked_timer  = 0;
	}
	else if((SpeedRef < 0)&&(pi_iq.Fbk < IQ_FB_OPEN_BLOCK)&&(hall3.direction == CLOCKWISE))//开门过程中出现反转信号
	{
		flag_open_blocked = TRUE;
		u32_blocked_timer = 0;
	}
	//持续时间： 满足堵转条件
	if(u32_blocked_timer < TIMER_BLOCK_TURN)
	{
		//电流差值
		dI_iq_fb = (pi_iq.Fbk > pi_iq.Ref)? (pi_iq.Fbk -  pi_iq.Ref):( pi_iq.Ref - pi_iq.Fbk);

		//堵转电流达到  && 转子停转
//		if( (pi_iq.Fbk > IQ_FB_CLOSE_LIMIT) && (dI_iq_fb < D_CUR_VALUE)
//											&& (hall3.hall_state == hall_blocked_pre0)
//											&& (TRUE == flag_ref_delta_stable))
		if((pi_iq.Fbk > IQ_FB_CLOSE_LIMIT) && (dI_iq_fb < D_CUR_VALUE) &&
				((hall3.hall_state == hall_blocked_pre0)||(hall3.hall_state == hall_blocked_pre1)))
	    {
	    	tmp_close_blocked = TRUE;
	    }
//	    else if ((pi_iq.Fbk < IQ_FB_OPEN_LIMIT) &&  (dI_iq_fb < D_CUR_VALUE)
//	    										&& (hall3.hall_state == hall_blocked_pre0)
//												&& (TRUE == flag_ref_delta_stable))
	    else if ((pi_iq.Fbk < IQ_FB_OPEN_LIMIT) &&  (dI_iq_fb < D_CUR_VALUE) &&
	    		((hall3.hall_state == hall_blocked_pre0)||(hall3.hall_state == hall_blocked_pre1)))
	    {
	    	tmp_open_blocked = TRUE;
	    }
	    else
	    {
	    	tmp_close_blocked = FALSE;
	    	tmp_open_blocked  = FALSE;

	    	flag_close_blocked = FALSE;
	    	flag_open_blocked  = FALSE;

	    	u32_blocked_timer = 0;
	    }
	}
	else
	{
		if(TRUE == tmp_close_blocked )
		{
			flag_close_blocked = TRUE;
		}
		else if (TRUE == tmp_open_blocked)
		{
			flag_open_blocked = TRUE;
		}
		else
		{
		}

		u32_blocked_timer = 0;

	}

	//状态更新
	if(hall_blocked_pre1 != hall3.hall_state)
	{
		hall_blocked_pre1 = hall_blocked_pre0;
		hall_blocked_pre0 = hall3.hall_state;
	}

}

//==============================================================================
// DESCRIPTION :电机正转的前一个霍尔值；     clockwise :	315462
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
static uint8 getprestate_clockwise(uint8 hallstate)
{
	uint8 temp_preHall = 0U;

	switch(hallstate)
	{
		case 3: 
			temp_preHall = 2;
			break;
		case 1: 
			temp_preHall = 3;
			break;
		case 5: 
			temp_preHall = 1;
			break;
		case 4: 
			temp_preHall = 5;
			break;
		case 6: 
			temp_preHall = 4;
			break;
		case 2: 
			temp_preHall = 6;
			break;
		default: 
			break;
	}

	return temp_preHall;
}

//==============================================================================
// DESCRIPTION :电机反转的前一个霍尔值；   anti clockwise : 264513
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
static uint8 getprestate_anticlockwise(uint8 hallstate)
{
	uint8 temp_preHall = 0U;

	switch(hallstate)
	{
		case 2: 
			temp_preHall = 3;
			break;
		case 6: 
			temp_preHall = 2;
			break;
		case 4: 
			temp_preHall = 6;
			break;
		case 5: 
			temp_preHall = 4;
			break;
		case 1: 
			temp_preHall = 5;
			break;
		case 3: 
			temp_preHall = 1;
			break;
		default: 
			break;
	}

	return temp_preHall;
}
//==============================================================================
// DESCRIPTION :转子停转状态
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void update_rotor_state(void)
{
	if((hall_pre0_rotor_stop == hall3.hall_state)||(hall_pre1_rotor_stop == hall3.hall_state ))
	{
//		hall_pre2_rotor_stop = hall_pre1_rotor_stop;
		if(u32_rotor_stop_timer >= TIMER_BLOCK_TURN)
		{
			flag_rotor_stop      = TRUE;
			u32_rotor_stop_timer = 0U;
		}
	}
	else
	{

		if(hall_pre1_rotor_stop != hall3.hall_state)
		{
			flag_rotor_stop      = FALSE;
			u32_rotor_stop_timer = 0U;
			hall_pre1_rotor_stop = hall_pre0_rotor_stop;
			hall_pre0_rotor_stop = hall3.hall_state;
		}

	}
}

//==============================================================================
// DESCRIPTION :电流预紧状态更新
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void update_motor_ref_state(void)
{
	if(u16_delta_ref_prescaler >=  DELTA_REF_PRESCALER) // DELTA_FB_PRESCALER * 67.7us计算一次
	{
		//电流反馈差值
		delta_ref = (pi_iq.Ref > siq_ref_pre)? (pi_iq.Ref - siq_ref_pre):( siq_ref_pre - pi_iq.Ref);

		if(delta_ref < DELTA_REF_LIMIT)
		{
			if(u32_delta_ref_timer > TIMER_DELTA_REF_LIMIT)	// TIMER_DELTA_FB_LIMIT 次滤波判断
			{
				flag_ref_delta_stable = TRUE;
				u32_delta_ref_timer   = 0U;
			}
		}
		else
		{
			flag_ref_delta_stable = FALSE;
			u32_delta_ref_timer   = 0U;
		}

		u32_delta_ref_timer++;
		siq_ref_pre = pi_iq.Ref ;

		u16_delta_ref_prescaler = 0U;
	}
	else
	{
		u16_delta_ref_prescaler++;
	}
}

//==============================================================================
// DESCRIPTION :电机状态更新
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void update_motor_state(void)
{
	update_block_state();

	update_motor_ref_state();
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

void init_motor(void)
{
		pi_iq.Kp   = pi_Kp;       //1.4
		pi_iq.Ki   = pi_Ki;       //0.01
		pi_iq.Umax = pi_iq_MAX;
		pi_iq.Umin = -pi_iq_MAX;
		pi_iq.viUmax = pi_Vi_MAX;
		pi_iq.viUmin = -pi_Vi_MAX;


		pi_spd.viUmax   = Speed_Vi_MAX;
		pi_spd.viUmin   = Speed_Vi_MAX;
		pi_spd.Kp   = Speed_Kp_MAX;
		pi_spd.Ki   = Speed_Ki_MAX;
		pi_spd.Umax = CUR_MAX;
		pi_spd.Umin = -CUR_MAX;

}
//==============================================================================
// DESCRIPTION :计算电流最大值
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void CurAD_get_max(void)
{
	uint8 i = 0;
	float32 tmp1, tmp2, tmp3, val;


	ADataArray[0] = (float32)(bldcadcRawValue[0]);
	ADataArray[1] = (float32)(bldcadcRawValue[1]);
	//ADataArray[2] = (float32)(bldcadcRawValue[2]);

	tmp1 = ADataArray[0]-iq_offset;
	tmp2 = ADataArray[1]-iq_offset;
	//tmp3 = ADataArray[2]-iq_offset;

	ADataArray[0] = tmp1*Bldc_Current_Change;
	ADataArray[1] = tmp2*Bldc_Current_Change;
	ADataArray[2] = -(tmp1+tmp2)*Bldc_Current_Change;

	tmp1 = fabs(ADataArray[0]);
	tmp2 = fabs(ADataArray[1]);
	tmp3 = fabs(ADataArray[2]);
	val  = (tmp1 > tmp2) ? tmp1 : tmp2;
	val  = (val > tmp3) ? val : tmp3;

	current_max_sum  = current_max_sum - Bldc_current_max[GetMaxCurTimes];
	Bldc_current_max[GetMaxCurTimes]  = val;
	current_max_sum += Bldc_current_max[GetMaxCurTimes];

    GetMaxCurTimes ++;
    if(GetMaxCurTimes > 199)
    {
    	GetMaxCurTimes = 0;
    }

	current_max_sum = 0;
	for(i=0; i<200; i++)
	{
		current_max_sum += Bldc_current_max[i];
	}
	GetMaxCurrent = current_max_sum*5;  //A->mA

}

//==============================================================================
// DESCRIPTION :获取三相电流最大值
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
uint16 GetMotorMaxCur(void)
{
    uint16 TempCurVal;

    TempCurVal = GetMaxCurrent;
    //用完之后清零
    GetMaxCurrent = 0;

    return TempCurVal;
}


/***************************************************************************
 名称：BSPBSDC_Init
 作用：控制初始化
  输入：
 返回：无
 描述：
****************************************************************************/
void BSPBLDC_Init(void)
{
	DRV8305_Init();
}
