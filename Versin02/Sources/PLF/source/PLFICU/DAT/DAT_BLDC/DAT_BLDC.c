//******************************************************************************
// Copyright:    This software is JYD property.
//               Duplication or disclosure without JYD written authorization
//               is prohibited.
// -----------------------------------------------------------------------------
// Project:      BCM313
// Language:     C
// -----------------------------------------------------------------------------
// Component:  each 5ms finish a list of AD conversion and output the
//                       digital input values.
// -----------------------------------------------------------------------------
//******************************************************************************
// This line is used to separate code and file header.This is begin.
//*****************************BEGIN_NOMOVE*************************************
// Time:2016-08-31 08:55:33
// 1:comment the code in DATBatLeaveActiveState to continue the AD conversion.
//   after leaving active state and MCU release power lock.
//Time:2016-09-04 13:44:40
//1: change the AD conversion strategy for the  new added capacitance on 4051 output.
// Time��2016-09-19 10:18:25
// 1: add code to get averaged AD value
// 2: add task scheduler for low time consumption of AD task.
// Time:2016-09-22 14:55:31
// 1:bug fix about the 6200 channel switch.
//*****************************END_NOMOVE***************************************
// This line is used to separate code and file header. This is last line.
//******************************************************************************

#define DAT_BLDC  "DAT_BLDC"
#include "DAT_BLDC.h"
#include "gdflib.h"
#include "gflib.h"
#include "gmclib.h"
#include "mlib.h"
#include "SWLIBS_Typedefs.h"

#define cDATBLDC_TaskPeriodMs		((U8)10)
static	tTOSAlarm  tDATBLDC_TaskAlarm;

U8   su8DATBLDC_MotorState;                  //���״̬

uint8 ACT_u8EPSPwmEnable = 0u;

uint32_t 	period6ZC, period6Hall;
tFloat 	actualSpeed = 0.0F;
tFloat 	torqueErr;
tFloat 	speedErr;


tFloat 	speedPIOut, currentPIOut;

GFLIB_CONTROLLER_PIAW_P_T_FLT 	speedPIPrms, currentPIPrms;

tFloat 	requiredSpeed = 3000;//N_MIN;

tFloat 		mcat_NMin = N_MIN;

tFloat 	requiredSpeedRamp;

GFLIB_RAMP_T_FLT 				speedRampPrms;

tFloat   			duty_cycle;

static uint32_t cont = 1;

uint8 testduty = 0u;

/**************************************************************************//*!
@brief Set PWM dytycyle, the dutycycle will by updated on next reload event

@param[in,out]

@return
******************************************************************************/
tBool ACTUATE_SetDutycycle(tFloat dutyCycle, tBool ftmInputTrig)
{
	tBool 				statePwm 	= true;
	uint16_t   			dutyTicks;
	const uint8_t 		channels[6] = {2, 3, 4, 5, 6, 7};

    /* Duty cycle in clock ticks format */
	dutyTicks = (uint16_t)MLIB_Mul(MLIB_Div(dutyCycle, 100.0F), 4000);

	/* Set duty cycle for all PWM channels */
	uint16_t pwms[ 6] = {dutyTicks, 0, dutyTicks, 0, dutyTicks, 0};

    /* Clear FTM3SYNCBIT to prepare HW trigger for FTM3 */
    SIM->FTMOPT1 &= ~(SIM_FTMOPT1_FTM2SYNCBIT_MASK & (ftmInputTrig << SIM_FTMOPT1_FTM2SYNCBIT_SHIFT));

    /* Update PWM duty cycle */
	FTM_DRV_FastUpdatePwmChannels(INST_BLDC_PWM2, 6, channels, pwms, false);

    /* Set FTM3SYNCBIT to trigger and update FTM3 registers */
    SIM->FTMOPT1 |= (SIM_FTMOPT1_FTM2SYNCBIT_MASK & (ftmInputTrig << SIM_FTMOPT1_FTM2SYNCBIT_SHIFT));

	statePwm = false;

	return(statePwm);
}
/**************************************************************************//*!
@brief Unmask PWM output and set 0% dytucyle

@param[in,out]

@return
******************************************************************************/
tBool ACTUATE_EnableOutput(tBool ftmInputTrig)
{
	uint16_t duty_cycle;

    // Enable PWM
	FTM_DRV_MaskOutputChannels(INST_BLDC_PWM2, 0x0, false);

	// Apply 0% duty cycle
	duty_cycle = 0;

	// Update duty cycle
	ACTUATE_SetDutycycle(duty_cycle, ftmInputTrig);

	return 1;
}

/**************************************************************************************************
 ���ƣ�DATANAEnterActiveState
 ���ã����뼤��״̬
  ���룺��
 ���أ���
 ��������BSP_SUP.c��BSPSUPPinCfg���Ѿ���4051������ѡ��˿�����Ϊ0��Ҳ����ѡ������4051�ĵ�0ͨ����
                ���BSPSUPPinCfg()��������main�����󣬵�һ��ִ�еģ���ִ�е�����ʱ�������˺ܶ���룬��ѹӦ��
	     �Ѿ��ȶ��ˣ����ʱ������õ�Ϊ24ms�������������������ADת��
**************************************************************************************************/
void DATBLDCInit()
{

    /* Speed PI controller initialization */
    speedPIPrms.fltPropGain = SPEED_LOOP_KP_GAIN;
    speedPIPrms.fltIntegGain = SPEED_LOOP_KI_GAIN;
    speedPIPrms.fltUpperLimit = CTRL_LOOP_LIM_HIGH;
    speedPIPrms.fltLowerLimit = CTRL_LOOP_LIM_LOW;

    /* Current PI controller initialization */
    currentPIPrms.fltPropGain = TORQUE_LOOP_KP_GAIN;
    currentPIPrms.fltIntegGain = TORQUE_LOOP_KI_GAIN;
    currentPIPrms.fltUpperLimit = CTRL_LOOP_LIM_HIGH;;
    currentPIPrms.fltLowerLimit = CTRL_LOOP_LIM_LOW;

    /* SPeed ramp initialization */
    speedRampPrms.fltRampUp = SPEED_LOOP_RAMP_UP;
    speedRampPrms.fltRampDown = SPEED_LOOP_RAMP_DOWN;



    BLDC_HALL_Init();



}

/**************************************************************************************************
 ���ƣ�DATBLDCEnterActiveState
 ���ã����뼤��״̬
  ���룺��
 ���أ���
 ���������뼤��״̬Ҫ��������ģʽΪfalse
**************************************************************************************************/
void DATBLDCEnterActiveState(void)
{
    //To permit to the input to be stabilized before going into sleep mode,
    //and avoid to miss a wake up condition (IT are not authorized)
	tDATBLDC_TaskAlarm.TaskID = cTOSTaskID_DATBLDCTask;
	TOSSetRelAlarm(&tDATBLDC_TaskAlarm, 0, mTOSConvMsInAlarmTick(cDATBLDC_TaskPeriodMs));

	extern void BSP_PDB0_ISREnable(void);
	BSP_PDB0_ISREnable();

	// Enable actuator
	ACTUATE_EnableOutput(HW_INPUT_TRIG1);
}

/**************************************************************************************************
 ���ƣ�DATANALeaveActiveState
 ���ã�
  ���룺
 ���أ���
 ������ADת��Ҫ��������
**************************************************************************************************/
void DATBLDCLeaveActiveState(void)
{

}

/**************************************************************************************************
 ���ƣ�DATANATask
 ���ã�ADת�����ݴ�������
  ���룺��
 ���أ���
 ���������뼤��״̬Ҫ��������ģʽΪfalse
**************************************************************************************************/
void DATBLDCTask(void)
{
	uint8_t i;
//	U8	u8SysMode;
//	static uint16_t TestSpeed;
//	static uint8_t TestSpeedL;
//	static uint8_t TestSpeedH;
//
//	static uint16_t TestSigCmd;
//	static uint8_t TestSigCmdL;
//	static uint8_t TestSigCmdH;
//
//
//	trigger_bldc(cTrue);
//	dia_hallA();
//
//	if(TestBLDCflag == 1)
//	{
////		cont++;
////		if(cont >= 5000 )
////		{
////			cont = 0;
////			TestBLDCflag = 0;
////		}
//	}
//
//
//	TestSpeed = (uint16_t)Speed_calc_Fb;
//	TestSpeedL = TestSpeed & 0xFF;
//	TestSpeedH = (TestSpeed>>8) & 0xFF;
//
//	mSERWrite(U8Bit,Sig_BackPinchSafeValueL,TestSpeedL,Delayed);
//	mSERWrite(U8Bit,Sig_BackPinchSafeValueH,TestSpeedH,Delayed);
//
////	TestSigCmdL = mSERRead(U8Bit,Sig_CMDL,Delayed);
////	TestSigCmdH = mSERRead(U8Bit,Sig_CMDH,Delayed);
////	TestSigCmd = TestSigCmdL + (TestSigCmdH << 8 );
////
////	SpeedRef = TestSigCmd;
//
//	extern void DRV8305_ReadReg(void);
	DRV8305_ReadReg();
	//DATBLDC_JudgeMotorState();

	period6ZC = SensorHall.Period[0];
	for(i=1;i<6;i++)
	{
		period6ZC += SensorHall.Period[i];
	}

    // Actual rotor speed is calculated based on ZC period or period measured by FTM2 Input Capture mode
    actualSpeed = MLIB_Mul(MLIB_ConvertPU_FLTF32(MLIB_DivSat_F32(SPEED_SCALE_CONST, period6ZC)), N_MAX);

	torqueErr = MLIB_Sub(I_DCB_LIMIT, torque_filt);

	currentPIOut = GFLIB_ControllerPIpAW(torqueErr, &currentPIPrms);

    /* Speed control */

    // Upper speed limit due to the limited DC bus voltage 12V
    if(requiredSpeed >= N_MAX)
    	requiredSpeed = N_MAX;

//    // Lower speed limit keeping reliable sensorless operation
//    if(requiredSpeed < mcat_NMin)
//    	requiredSpeed = mcat_NMin;

    requiredSpeedRamp = GFLIB_Ramp(requiredSpeed, &speedRampPrms);
    speedErr = MLIB_Sub(requiredSpeedRamp, actualSpeed);
    speedPIOut = GFLIB_ControllerPIpAW(speedErr, &speedPIPrms);

//    if(currentPIOut >= speedPIOut)
//    {
//    	/* If max torque not achieved, use speed PI output */
//        currentPIPrms.fltIntegPartK_1 = speedPIOut;
//        currentPIPrms.fltInK_1 = 0;
//        /* PWM duty cycle update <- speed PI */
//        duty_cycle = speedPIOut;
//    }
//    else
//    {
//    	/* Limit speed PI output by current PI if max. torque achieved */
//        speedPIPrms.fltIntegPartK_1 = currentPIOut;
//        speedPIPrms.fltInK_1 = 0;
//        /* PWM duty cycle update <- current PI */
//    	duty_cycle = currentPIOut;
//    }


//    duty_cycle = testduty;
    duty_cycle = speedPIOut;

    // Update PWM duty cycle
    ACTUATE_SetDutycycle(duty_cycle, HW_INPUT_TRIG1);

}



