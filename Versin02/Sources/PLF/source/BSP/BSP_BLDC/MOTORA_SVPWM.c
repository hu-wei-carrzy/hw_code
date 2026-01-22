//#include "Hall_Pro.h"
//#include "GenSVPWM.h"
#include "Platform_Types.h"
#include "MOTORA_Settings.h"
#include "../BSP_DIO/BSP_DIO.h"
#include "MOTORA_control.h"
#include "../../DAT/DAT_BLDC/DAT_BLDC.h"
#include <math.h>

//static uint32 su32_IsrTicker = 0U;
volatile uint16 EnableFlag = FALSE;
boolean MotorA_Run = FALSE;
static RMPCNTL rc2 = RMPCNTL_DEFAULTS;

float32 PWM_Duty = 10000.0;
float32	FreqSet = 30000;


PI_CONTROLLER pi_spd = PI_CONTROLLER_DEFAULTS;
PI_CONTROLLER pi_iq = PI_CONTROLLER_DEFAULTS;

float32 SpeedRef = 0;
float32 Iq_Ref = 0;

uint16 su16_SpeedLoopPrescaler = 1;
uint16 su16_SpeedLoopCount = 0;


boolean iq_mode = 0;
sint32 MotorCircles = 0U;        	/*电机转动圈数*/
sint32 counter_loops = 0U;       /*霍尔脉冲计数器*/


boolean spd_mode= 0;


static uint32 su32_speed_fb_timer = 0U;
uint16 SPEED_ZERO_TIMER = 1250;

uint32 su32_cap_counter = 0;
uint32 su32_cap_counter_pre= 0;
float32 speed_rps = 0.0;

uint16 u16duty = 0;

uint16 cout = 0;
//uint16 halllog[1000] = { 0 };
float32 halltimelog[1000] = { 0 };

void CtrlTask_FOCA(void)// 2Khz的运行频率
{
	init_motor();

	su32_speed_fb_timer++;
	u32_rotor_stop_timer++;		//转子停转计时
	u32_blocked_timer++;		//堵转计时

	hall3.hall_state_time = u32_IcuTicker;

	get_HallState();			//更新电角度
	get_Speed_Value();			//计算电机转速
//	update_rotor_state();		//更新转子状态
	CurAD_get_max();			//计算电流最大值

	if(TestBLDCflag)
	{
		rc2.TargetValue = SpeedRef; //g_velocityControl.ref;
		RC_MACRO1(&rc2);

		if(su16_SpeedLoopPrescaler <= su16_SpeedLoopCount)
		{
			pi_spd.Ref = rc2.SetpointValue;
			pi_spd.Fbk = Speed_calc_Fb;;
			PI_MACRO1(&pi_spd);
			su16_SpeedLoopCount = 1;
		}
		else
		{
			su16_SpeedLoopCount++;
		}

		//全程电流限制
		if(pi_spd.Out > IQ_CLOSE_LIMIT_ALL)                 //当设定电流为32A时，电流的限值在0.66，在设定为16A时，电流的限值在0.95
		{
			pi_spd.Out = IQ_CLOSE_LIMIT_ALL;
		}
		else if(pi_spd.Out < IQ_OPEN_LIMIT_ALL)
		{
			pi_spd.Out = IQ_OPEN_LIMIT_ALL;
		}

		pi_iq.Ref = pi_spd.Out;
		pi_iq.Fbk = GetMaxCurrent;
		PI_MACRO1(&pi_iq);

		u16duty = fabs((int16_t)pi_iq.Out);

		SET_PWM_VALUE(u16duty);

	 }// end of if(MotorA_Run)
}


//==============================================================================
// DESCRIPTION :电机停止
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void motor_stopA(void)
{
	uint8 i = 0;
//	SpeedRef = 0;
//	EnableFlag = 0;
	ACT_u8EPSPwmEnable = FALSE;

    pi_iq.i1 = 0.0;                   /*电机控制参数复位*/
    pi_iq.v1 = 0.0;
    pi_iq.w1 = 0.0;
    pi_iq.Out = 0.0;
    pi_iq.ui = 0.0;
    pi_iq.up = 0.0;
    pi_iq.Ref = 0.0;
    pi_iq.Fbk = 0.0;
    pi_iq.Out = 0.0;
    pi_iq.Umax = DC_Volt/1.732;
    pi_iq.Umin = -DC_Volt/1.732;

    pi_spd.i1 = 0.0;
    pi_spd.v1 = 0.0;
    pi_spd.w1 = 0.0;
    pi_spd.Out = 0.0;
    pi_spd.ui = 0.0;
    pi_spd.up = 0.0;
    pi_spd.Ref = 0.0;
    pi_spd.Fbk = 0.0;
    pi_spd.Out = 0.0;
//    pi_spd.Umax = 0.0;//CUR_MAX;
//    pi_spd.Umin = 0.0;//-CUR_MAX;

    rc2.TargetValue = 0.0;
    rc2.RampDelayMax = 5U;
//    rc2.RampLowLimit = -BASE_SPEED/60.0*(POLES/2);//4-->polepaires
//    rc2.RampHighLimit = BASE_SPEED/60.0*(POLES/2);//4-->polepaires
    rc2.RampLowLimit = -2800;//4-->polepaires
    rc2.RampHighLimit = 2800;//4-->polepaires
    rc2.EqualFlag = 0U;
    rc2.RampDelayCount = 0U;
    rc2.SetpointValue = 0.0;

    ADataArray[0] = 0;
    ADataArray[1] = 0;
    ADataArray[2] = 0;

    for(i=0; i<200; i++)
    {
    	Bldc_current_max[i] = 0;
    }
    GetMaxCurrent = 0;
    current_max_sum = 0;
}

//==============================================================================
// DESCRIPTION : get the loops of motor
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
static void get_loops(void)
{
    /*
     *0.1 圈
     *MotorCircles = counter_loops * 10 / ((POLES / 2) * 6 / 2);
     */
//    MotorCircles = counter_loops /( 6U *(POLES / 2U));
	MotorCircles = counter_loops;	//4对级电机24脉冲为电机转动一圈
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
static void motor_init(void)
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
static void motor_start(void)
{
//	ACT_u8EPSPwmEnable = TRUE;

    /* Clear any spurious OV trip*/
//    EALLOW;
//    EPwm1Regs.TZCLR.bit.OST = 1U;
//    EPwm2Regs.TZCLR.bit.OST = 1U;
//    EPwm3Regs.TZCLR.bit.OST = 1U;
//    EDIS;
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
static void enable_control(void)
{
    if(FALSE == EnableFlag)
    {
//        motor_init();
    	MotorA_Run = FALSE;
    }
    else if((TRUE == EnableFlag) && (FALSE == MotorA_Run))
    {
    	MotorA_Run = TRUE;
        motor_start();
    }
    else
    {
    	motor_start();
        /*电机运行中，加速停机计数置零*/
//        su32_accelerate_timer_on_stop = 0U;
    }

//	State_run();
}
//==============================================================================
// DESCRIPTION :bldc control
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void trigger_bldc(uint32 onoff)
{
//    if(0 == read_DRV8350_nfault())   /*nFault高电平无故障*/
//    {
//        get_status_8305(&SpiaRegs, &drv8305_regs);
//    }

    enable_control();

    get_loops();   						/*反馈圈数(0.1)；*/

    update_motor_state();
}


static void set_speed_fb_zero(void)	//速度反馈低速置零
{
    if(su32_speed_fb_timer > SPEED_ZERO_TIMER)
    {
        if(su32_cap_counter == su32_cap_counter_pre)
        {
            siq_speed_fb = 0.0;
            speed_rps = 0.0;
        }

        su32_speed_fb_timer = 0U;
        su32_cap_counter_pre = su32_cap_counter;
    }
}

void SET_PWM_VALUE(uint16_t value)
{
	uint16_t temp = 0;
	temp = value;
	if(pi_iq.Out>0)
	{
		switch(hall3.hall_state)
		{
		case 4:
			FTM_DRV_MaskOutputChannels(INST_BLDC_PWM2,0x0C,true);
			FTM_DRV_UpdatePwmChannel(INST_BLDC_PWM2,6,FTM_PWM_UPDATE_IN_DUTY_CYCLE,temp,0U,true);
			FTM_DRV_UpdatePwmChannel(INST_BLDC_PWM2,4,FTM_PWM_UPDATE_IN_DUTY_CYCLE,0,0U,true);
			break;

		case 5:
			FTM_DRV_MaskOutputChannels(INST_BLDC_PWM2,0x30,true);
			FTM_DRV_UpdatePwmChannel(INST_BLDC_PWM2,6,FTM_PWM_UPDATE_IN_DUTY_CYCLE,temp,0U,true);
			FTM_DRV_UpdatePwmChannel(INST_BLDC_PWM2,2,FTM_PWM_UPDATE_IN_DUTY_CYCLE,0,0U,true);
			break;

		case 1:
			FTM_DRV_MaskOutputChannels(INST_BLDC_PWM2,0xC0,true);
			FTM_DRV_UpdatePwmChannel(INST_BLDC_PWM2,4,FTM_PWM_UPDATE_IN_DUTY_CYCLE,temp,0U,true);
			FTM_DRV_UpdatePwmChannel(INST_BLDC_PWM2,2,FTM_PWM_UPDATE_IN_DUTY_CYCLE,0,0U,true);
			break;

		case 3:
			FTM_DRV_MaskOutputChannels(INST_BLDC_PWM2,0x0C,true);
			FTM_DRV_UpdatePwmChannel(INST_BLDC_PWM2,4,FTM_PWM_UPDATE_IN_DUTY_CYCLE,temp,0U,true);
			FTM_DRV_UpdatePwmChannel(INST_BLDC_PWM2,6,FTM_PWM_UPDATE_IN_DUTY_CYCLE,0,0U,true);
			break;

		case 2:
			FTM_DRV_MaskOutputChannels(INST_BLDC_PWM2,0x30,true);
			FTM_DRV_UpdatePwmChannel(INST_BLDC_PWM2,2,FTM_PWM_UPDATE_IN_DUTY_CYCLE,temp,0U,true);
			FTM_DRV_UpdatePwmChannel(INST_BLDC_PWM2,6,FTM_PWM_UPDATE_IN_DUTY_CYCLE,0,0U,true);
			break;

		case 6:
			FTM_DRV_MaskOutputChannels(INST_BLDC_PWM2,0xC0,true);
			FTM_DRV_UpdatePwmChannel(INST_BLDC_PWM2,2,FTM_PWM_UPDATE_IN_DUTY_CYCLE,temp,0U,true);
			FTM_DRV_UpdatePwmChannel(INST_BLDC_PWM2,4,FTM_PWM_UPDATE_IN_DUTY_CYCLE,0,0U,true);
			break;


		default:
			break;
		}
	}
	else if (pi_iq.Out<0)
	{

		switch(hall3.hall_state)
		{
		case 4:
			FTM_DRV_MaskOutputChannels(INST_BLDC_PWM2,0x0C,true);
			FTM_DRV_UpdatePwmChannel(INST_BLDC_PWM2,4,FTM_PWM_UPDATE_IN_DUTY_CYCLE,temp,0U,true);
			FTM_DRV_UpdatePwmChannel(INST_BLDC_PWM2,6,FTM_PWM_UPDATE_IN_DUTY_CYCLE,0,0U,true);
			break;

		case 5:
			FTM_DRV_MaskOutputChannels(INST_BLDC_PWM2,0x30,true);
			FTM_DRV_UpdatePwmChannel(INST_BLDC_PWM2,2,FTM_PWM_UPDATE_IN_DUTY_CYCLE,temp,0U,true);
			FTM_DRV_UpdatePwmChannel(INST_BLDC_PWM2,6,FTM_PWM_UPDATE_IN_DUTY_CYCLE,0,0U,true);
			break;

		case 1:
			FTM_DRV_MaskOutputChannels(INST_BLDC_PWM2,0xC0,true);
			FTM_DRV_UpdatePwmChannel(INST_BLDC_PWM2,2,FTM_PWM_UPDATE_IN_DUTY_CYCLE,temp,0U,true);
			FTM_DRV_UpdatePwmChannel(INST_BLDC_PWM2,4,FTM_PWM_UPDATE_IN_DUTY_CYCLE,0,0U,true);
			break;

		case 3:
			FTM_DRV_MaskOutputChannels(INST_BLDC_PWM2,0x0C,true);
			FTM_DRV_UpdatePwmChannel(INST_BLDC_PWM2,6,FTM_PWM_UPDATE_IN_DUTY_CYCLE,temp,0U,true);
			FTM_DRV_UpdatePwmChannel(INST_BLDC_PWM2,4,FTM_PWM_UPDATE_IN_DUTY_CYCLE,0,0U,true);
			break;

		case 2:
			FTM_DRV_MaskOutputChannels(INST_BLDC_PWM2,0x30,true);
			FTM_DRV_UpdatePwmChannel(INST_BLDC_PWM2,6,FTM_PWM_UPDATE_IN_DUTY_CYCLE,temp,0U,true);
			FTM_DRV_UpdatePwmChannel(INST_BLDC_PWM2,2,FTM_PWM_UPDATE_IN_DUTY_CYCLE,0,0U,true);
			break;

		case 6:
			FTM_DRV_MaskOutputChannels(INST_BLDC_PWM2,0xC0,true);
			FTM_DRV_UpdatePwmChannel(INST_BLDC_PWM2,4,FTM_PWM_UPDATE_IN_DUTY_CYCLE,temp,0U,true);
			FTM_DRV_UpdatePwmChannel(INST_BLDC_PWM2,2,FTM_PWM_UPDATE_IN_DUTY_CYCLE,0,0U,true);
			break;

		default:
			break;
		}
	}
}

