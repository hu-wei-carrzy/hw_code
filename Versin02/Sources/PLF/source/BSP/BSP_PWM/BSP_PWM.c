/*
 * BSP_PWM.c
 *
 *  Created on: 2024年12月23日
 *      Author: 00361759
 */
//------------------------------------------------------------------------------
// Body Identification
//------------------------------------------------------------------------------
#define bsp_pwm "bsp_pwm"
//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//------------------------------------------------------------------------------
#include "BSP_PWM.h"
#include "GDFLIB_FilterMA.h"


//------------------------------------------------------------------------------
// Local constants
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Local macros
//------------------------------------------------------------------------------
#define mPWMMAXDUTY  32768
#define mPWMPRECENTDUTY  327.68

#define I_MAX                           (12.5F)

#define mPRECENTVALUE  100

//------------------------------------------------------------------------------
// Local data
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Exported data
//------------------------------------------------------------------------------
float32 DC_Current_Change = 12.218;  //5000/(1023*20*20)*1000mA=12.218(mA)
float32 DC_iq_offset = 451;
uint16_t DC_ADataArray[4];
float32 DC_current_max[4][100];
uint16  DC_GetMaxCurTimes = 0;
uint16_t adcRawValue[6];
uint16_t bldcadcRawValue[4];
uint16_t TestBLDCflag = 0;
tADCresults  		ADCResults;
GDFLIB_FILTER_MA_T_FLT Idcb_filt;
tFloat 	u_dc_bus_filt, torque_filt;

tFloat ADC0CHnResult;
uint8_t ADC0CHnComplete;

tFloat ADC1CHnResult;
uint8_t ADC1CHnComplete;


//------------------------------------------------------------------------------
// Local function prototypes
//------------------------------------------------------------------------------
void PDB1_IRQHandler(void);
void PDB0_IRQHandler(void);
void ADC0_IRQHandler(void);
void ADC1_IRQHandler(void);
void BSDC_CurAD_Log(void);


//==============================================================================
// LOCAL FUNCTIONS
//==============================================================================
/*******************************************************************************
*
* Function: 	tBool MEAS_GetDCBCurrent(tFloat *getDCBCurrent)
*
* Description:  This function performs DC bus current measurement.
* 				Conversion complete interrupt is disabled.
*
* Param[in,out]: *getDCBCurrent - pointer to a variable - DC bus current
*
*
* @return     	# true  - when measurement ended successfully
            	# false - when measurement is ongoing, or error occurred.
*
*******************************************************************************/
tBool MEAS_GetUICurrent(tFloat *getDCBCurrent)
{
	uint16_t 			adcResult;

	ADC_DRV_GetChanResult(INST_ADCONV0, 0, &adcResult);

	*getDCBCurrent = MLIB_Mul(((tFloat)MLIB_Div((tFloat)(adcResult & 0x00000FFF), (tFloat)0x00000FFF)), I_MAX);

	return 1;
}
/*******************************************************************************
*
* Function: 	tBool MEAS_GetDCBCurrent(tFloat *getDCBCurrent)
*
* Description:  This function performs DC bus current measurement.
* 				Conversion complete interrupt is disabled.
*
* Param[in,out]: *getDCBCurrent - pointer to a variable - DC bus current
*
*
* @return     	# true  - when measurement ended successfully
            	# false - when measurement is ongoing, or error occurred.
*
*******************************************************************************/
tBool MEAS_GetVICurrent(tFloat *getDCBCurrent)
{
	uint16_t 			adcResult;

	ADC_DRV_GetChanResult(INST_ADCONV0, 1, &adcResult);

	*getDCBCurrent = MLIB_Mul(((tFloat)MLIB_Div((tFloat)(adcResult & 0x00000FFF), (tFloat)0x00000FFF)), I_MAX);

	return 1;
}
/*******************************************************************************
*
* Function: 	tBool MEAS_GetDCBCurrent(tFloat *getDCBCurrent)
*
* Description:  This function performs DC bus current measurement.
* 				Conversion complete interrupt is disabled.
*
* Param[in,out]: *getDCBCurrent - pointer to a variable - DC bus current
*
*
* @return     	# true  - when measurement ended successfully
            	# false - when measurement is ongoing, or error occurred.
*
*******************************************************************************/
tBool MEAS_GetWICurrent(tFloat *getDCBCurrent)
{
	uint16_t 			adcResult;

	ADC_DRV_GetChanResult(INST_ADCONV0, 2, &adcResult);

	*getDCBCurrent = MLIB_Mul(((tFloat)MLIB_Div((tFloat)(adcResult & 0x00000FFF), (tFloat)0x00000FFF)), I_MAX);

	return 1;
}
/*******************************************************************************
*
* Function: 	tBool MEAS_GetDCBCurrent(tFloat *getDCBCurrent)
*
* Description:  This function performs DC bus current measurement.
* 				Conversion complete interrupt is disabled.
*
* Param[in,out]: *getDCBCurrent - pointer to a variable - DC bus current
*
*
* @return     	# true  - when measurement ended successfully
            	# false - when measurement is ongoing, or error occurred.
*
*******************************************************************************/
tBool MEAS_GetADC0Current(tFloat *getDCBCurrent)
{
	uint16_t 			adcResult;

	ADC_DRV_GetChanResult(INST_ADCONV0, 3, &adcResult);

	//*getDCBCurrent = MLIB_Mul(((tFloat)MLIB_Div((tFloat)(adcResult & 0x00000FFF), (tFloat)0x00000FFF)), I_MAX);
	*getDCBCurrent = adcResult;

	return 1;
}
/*******************************************************************************
*
* Function: 	tBool MEAS_GetDCBCurrent(tFloat *getDCBCurrent)
*
* Description:  This function performs DC bus current measurement.
* 				Conversion complete interrupt is disabled.
*
* Param[in,out]: *getDCBCurrent - pointer to a variable - DC bus current
*
*
* @return     	# true  - when measurement ended successfully
            	# false - when measurement is ongoing, or error occurred.
*
*******************************************************************************/
tBool MEAS_GetADC1Current(tFloat *getDCBCurrent)
{
	uint16_t 			adcResult;

	ADC_DRV_GetChanResult(INST_ADCONV1, 4, &adcResult);

	//*getDCBCurrent = MLIB_Mul(((tFloat)MLIB_Div((tFloat)(adcResult & 0x00000FFF), (tFloat)0x00000FFF)), I_MAX);
	*getDCBCurrent = adcResult;

	return 1;
}


//==============================================================================
// DESCRIPTION :BSP_MotorPWM0_Init
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void BSP_MotorPWM0_Init(void)
{
	static ftm_state_t ftm3state;

	/*FTM3配置时钟和分频代码*/
	FTM_DRV_Init(INST_DC_PWM1, &DC_pwm1_InitConfig,&ftm3state);
	/*FTM3配置Hz代码*/
	FTM_DRV_InitPwm(INST_DC_PWM1, &DC_pwm1_PwmConfig);
	/*FTM3配置PWM触发PDB1的通道FTM3*/
	FTM_RMW_EXTTRIG_REG(FTM3, FTM_EXTTRIG_INITTRIGEN_MASK, FTM_EXTTRIG_INITTRIGEN(1UL));
}

//==============================================================================
// DESCRIPTION :BSP_MotorPWM1_Init
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void BSP_MotorPWM1_Init(void)
{
	static ftm_state_t ftm2state;

	/*FTM3配置时钟和分频代码*/
	FTM_DRV_Init(INST_BLDC_PWM2, &BLDC_pwm2_InitConfig,&ftm2state);
	/*FTM3配置Hz代码*/
	FTM_DRV_InitPwm(INST_BLDC_PWM2, &BLDC_pwm2_PwmConfig);
	/*FTM3配置PWM触发PDB1的通道FTM3*/
	FTM_RMW_EXTTRIG_REG(FTM2, FTM_EXTTRIG_INITTRIGEN_MASK, FTM_EXTTRIG_INITTRIGEN(1UL));
}

//==============================================================================
// DESCRIPTION :BSP_MotorPWM1_Init
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void BSP_PWMSync_Init(void)
{
	static ftm_state_t ftm2state;

//	FTM_RMW_SYNC(g_ftmBase[2],  FTM_SYNC_REINIT_MASK, FTM_SYNC_REINIT(true));
//	FTM_RMW_SYNC(g_ftmBase[3],  FTM_SYNC_REINIT_MASK, FTM_SYNC_REINIT(true));

	g_ftmBase[2]->SYNCONF = (g_ftmBase[2]->SYNCONF & ~FTM_SYNCONF_SWRSTCNT_MASK) | FTM_SYNCONF_SWRSTCNT(true);
	g_ftmBase[3]->SYNCONF = (g_ftmBase[3]->SYNCONF & ~FTM_SYNCONF_SWRSTCNT_MASK) | FTM_SYNCONF_SWRSTCNT(true);

	FTM_RMW_SYNC(g_ftmBase[2],  FTM_SYNC_SWSYNC_MASK, FTM_SYNC_SWSYNC(true));
	FTM_RMW_SYNC(g_ftmBase[3],  FTM_SYNC_SWSYNC_MASK, FTM_SYNC_SWSYNC(true));

	FTM_RMW_SYNC(g_ftmBase[2],  FTM_SYNC_SWSYNC_MASK, FTM_SYNC_SWSYNC(false));
	FTM_RMW_SYNC(g_ftmBase[3],  FTM_SYNC_SWSYNC_MASK, FTM_SYNC_SWSYNC(false));

	g_ftmBase[2]->SYNCONF = (g_ftmBase[2]->SYNCONF & ~FTM_SYNCONF_SWRSTCNT_MASK) | FTM_SYNCONF_SWRSTCNT(false);
	g_ftmBase[3]->SYNCONF = (g_ftmBase[3]->SYNCONF & ~FTM_SYNCONF_SWRSTCNT_MASK) | FTM_SYNCONF_SWRSTCNT(false);

}


//==============================================================================
// DESCRIPTION :BSP_MotorPDB0_Init
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void BSP_MotorPDB0_Init(void)
{
	/*初始化PDB*/
	PDB_DRV_Init(INST_PDB0, &pdb0_InitConfig0);
	/*初始化PDB触发ADC的3个预触发通道*/
	PDB_DRV_ConfigAdcPreTrigger(INST_PDB0, 0, &pdb0_AdcTrigInitConfig0);

	PDB_DRV_ConfigAdcPreTrigger(INST_PDB0, 0, &pdb0_AdcTrigInitConfig1);

	PDB_DRV_ConfigAdcPreTrigger(INST_PDB0, 0, &pdb0_AdcTrigInitConfig2);

	PDB_DRV_ConfigAdcPreTrigger(INST_PDB0, 0, &pdb0_AdcTrigInitConfig3);

	/*初始化PDB溢出MOD时间，触发时间和reload时间*/
	PDB_DRV_SetTimerModulusValue(INST_PDB0,4000);

	PDB_DRV_SetAdcPreTriggerDelayValue(INST_PDB0, 0, 0, 10);

	//PDB_DRV_SetAdcPreTriggerDelayValue(INST_PDB0, 0, 1, 180);

	//PDB_DRV_SetAdcPreTriggerDelayValue(INST_PDB0, 0, 2, 360);

	//PDB_DRV_SetValueForTimerInterrupt(INST_PDB0, 34999);
	/*使能PDB0的计数*/
	PDB_DRV_Enable(INST_PDB0);

	PDB_DRV_LoadValuesCmd(INST_PDB0);

}

//==============================================================================
// DESCRIPTION :BSP_MotorPDB1_Init
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void BSP_MotorPDB1_Init(void)
{
	/*初始化PDB*/
	PDB_DRV_Init(INST_PDB1, &pdb1_InitConfig0);
	/*初始化PDB触发ADC的4个预触发通道*/
	PDB_DRV_ConfigAdcPreTrigger(INST_PDB1, 0, &pdb1_AdcTrigInitConfig0);
	PDB_DRV_ConfigAdcPreTrigger(INST_PDB1, 0, &pdb1_AdcTrigInitConfig1);
	PDB_DRV_ConfigAdcPreTrigger(INST_PDB1, 0, &pdb1_AdcTrigInitConfig2);
	PDB_DRV_ConfigAdcPreTrigger(INST_PDB1, 0, &pdb1_AdcTrigInitConfig3);
	/*初始化PDB触发计时器开始，与系统80M时钟保持一致*/
	PDB_DRV_SetTimerModulusValue(INST_PDB1,39700);
	PDB_DRV_SetAdcPreTriggerDelayValue(INST_PDB1, 0, 0, 1);
	PDB_DRV_SetValueForTimerInterrupt(INST_PDB1, 39699);
	/*使能PDB中断*/
	PDB_DRV_Enable(INST_PDB1);
	PDB_DRV_LoadValuesCmd(INST_PDB1);
}



//==============================================================================
// EXPORTED FUNCTIONS
//==============================================================================

//==============================================================================
// DESCRIPTION :BSP_MotorPDB0_Init
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void BSPPWM_Init(void)
{

	/*初始化Trgmux，主要包括将FTM3的InitTrig与pdb1绑定*/
	TRGMUX_DRV_Init(INST_TRGMUX1, &trgmux1_InitConfig0);

	BSP_MotorPDB0_Init();

	BSP_MotorPDB1_Init();

	BSP_MotorPWM0_Init();

	BSP_MotorPWM1_Init();

	BSP_PWMSync_Init();

	/*中断函数注册*/
	INT_SYS_InstallHandler(PDB1_IRQn,&PDB1_IRQHandler,(isr_t*)0);
	INT_SYS_InstallHandler(ADC1_IRQn,&ADC1_IRQHandler,(isr_t*)0);
	INT_SYS_InstallHandler(PDB0_IRQn,&PDB0_IRQHandler,(isr_t*)0);
	INT_SYS_InstallHandler(ADC0_IRQn,&ADC0_IRQHandler,(isr_t*)0);
	/*中断函数优先级设定*/
	INT_SYS_SetPriority(PDB1_IRQn,0x08);
	INT_SYS_SetPriority(ADC1_IRQn,0x07);
	INT_SYS_SetPriority(PDB0_IRQn,0x06);
	INT_SYS_SetPriority(ADC0_IRQn,0x05);

    /* Initialize DC bus current moving average filter */
    GDFLIB_FilterMAInit_FLT(&Idcb_filt);
    Idcb_filt.fltLambda = TORQUE_LOOP_MAF;



}

//==============================================================================
// DESCRIPTION :BSP_PDB0_ISREnable
//
// PARAMETERS (Type,Name,Min,Max) :
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : 开启PBD0 和 ADC0的中断
//==============================================================================
void BSP_PDB0_ISREnable(void)
{
	INT_SYS_EnableIRQ(PDB0_IRQn);                     // Enable PDB1 interrupt
	INT_SYS_EnableIRQ(ADC0_IRQn);                     // Enable PDB1 interrupt
}

//==============================================================================
// DESCRIPTION :BSP_PDB1_ISREnable
//
// PARAMETERS (Type,Name,Min,Max) :
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : 开启PBD1 和 ADC1的中断
//==============================================================================
void BSP_PDB1_ISREnable(void)
{
	INT_SYS_EnableIRQ(PDB1_IRQn);                     // Enable PDB1 interrupt
	INT_SYS_EnableIRQ(ADC1_IRQn);                     // Enable PDB1 interrupt
}

//==============================================================================
// DESCRIPTION :BSP_PWM_SetDuty
//
// PARAMETERS (Type,Name,Min,Max) :
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION :设置PWM占空比，duty为0~100
//==============================================================================
void BSP_PWM_SetDuty(uint8_t x_PWM,uint8_t channel,uint16_t duty)
{
	uint8_t instance = 0;
	uint16_t Value = 0;

	switch(x_PWM)
	{
	case BLDC_PWM:
		instance = INST_BLDC_PWM2;
		break;
	case DC_PWM:
		instance = INST_DC_PWM1;
		break;
	default:
		break;
	}

	if ((channel > 0) && (channel < 5))
	{
		channel = channel - 1;
	}

	if(duty <= mPRECENTVALUE)
	{
		Value = duty * mPWMPRECENTDUTY;
	}
	else
	{
		Value = mPWMMAXDUTY;
	}

	FTM_DRV_UpdatePwmChannel(instance,channel,FTM_PWM_UPDATE_IN_DUTY_CYCLE,Value,0U,true);
}

//==============================================================================
// DESCRIPTION :BSDC_CurAD_Log
//
// PARAMETERS (Type,Name,Min,Max) :
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION :计算电流平均值
//==============================================================================
void BSDC_CurAD_Log(void)
{

	DC_current_max[0][DC_GetMaxCurTimes] = adcRawValue[0];
	DC_current_max[1][DC_GetMaxCurTimes] = adcRawValue[1];
	DC_current_max[2][DC_GetMaxCurTimes] = adcRawValue[2];
	DC_current_max[3][DC_GetMaxCurTimes] = adcRawValue[3];

	DC_GetMaxCurTimes++;

	if(DC_GetMaxCurTimes > 99)
	{
		DC_GetMaxCurTimes = 0;
	}
}

//==============================================================================
// DESCRIPTION :PDB1_IRQHandler
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : 中断处理PDB1的溢出情况，并开启FTM3的触发源，主要是BSDC的ADC触发采集
//==============================================================================
void PDB1_IRQHandler(void)
{
	/*判断PDB是否出现触发序列错误*/
	if(PDB_DRV_GetAdcPreTriggerSeqErrFlags(INST_PDB1,0,0xff))
	{
		// Disable PDB0
		PDB_DRV_Disable(INST_PDB1);

		// Clear PDB0 sequence errors
		PDB_DRV_ClearAdcPreTriggerSeqErrFlags(INST_PDB1, 0, 0xFF);

		// Enable PDB0 此处再进行计数则count值重新计算
		PDB_DRV_Enable(INST_PDB1);
	}
	/*判断PDB是否出现溢出*/
	if(PDB_DRV_GetTimerIntFlag(INST_PDB1))
	{
		//Clear PDB0 timer interrupt flag
		PDB_DRV_ClearTimerIntFlag(INST_PDB1);
	}
	//重新开启FTM3触发PDB1计数
	FTM_RMW_EXTTRIG_REG(FTM3, FTM_EXTTRIG_INITTRIGEN_MASK, FTM_EXTTRIG_INITTRIGEN(1UL));
}

//==============================================================================
// DESCRIPTION :ADC1_IRQHandler
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION :  主要采集4个BSDC电机的电流值
//==============================================================================
void ADC1_IRQHandler(void)
{
	//屏蔽和停止FTM3可以触发PDB1计数
	FTM_RMW_EXTTRIG_REG(FTM3, FTM_EXTTRIG_INITTRIGEN_MASK, FTM_EXTTRIG_INITTRIGEN(0UL));
	//PDB1触发ADC1的采集结果
	ADC_DRV_GetChanResult(INST_ADCONV1, 0U, (uint16_t*)adcRawValue);
	ADC_DRV_GetChanResult(INST_ADCONV1, 1U, (uint16_t*)(adcRawValue + 1));
	ADC_DRV_GetChanResult(INST_ADCONV1, 2U, (uint16_t*)(adcRawValue + 2));
	ADC_DRV_GetChanResult(INST_ADCONV1, 3U, (uint16_t*)(adcRawValue + 3));
	MEAS_GetADC1Current(&ADC1CHnResult);


	ADC1CHnComplete = 1;

	//ADC采集的数据放入记录数组内，为求平均值
	BSDC_CurAD_Log();

}
//==============================================================================
// DESCRIPTION :PDB0_IRQHandler
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : 中断处理PDB0的溢出情况，并开启FTM2的触发源，主要是BLDC的ADC触发采集
//==============================================================================
void PDB0_IRQHandler(void)
{
	// Disable PDB0
	PDB_DRV_Disable(INST_PDB0);

	// Clear PDB0 sequence errors
	PDB_DRV_ClearAdcPreTriggerSeqErrFlags(INST_PDB0, 0, 0xFF);

	// Enable PDB0
	PDB_DRV_Enable(INST_PDB0);
}

//==============================================================================
// DESCRIPTION :ADC0_IRQHandler
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION :  主要采集BLDC电机三相电流值
//==============================================================================
void ADC0_IRQHandler(void)
{
	//屏蔽和停止FTM2可以触发PDB0计数
	//FTM_RMW_EXTTRIG_REG(FTM2, FTM_EXTTRIG_INITTRIGEN_MASK, FTM_EXTTRIG_INITTRIGEN(0UL));

//	ADC_DRV_GetChanResult(INST_ADCONV0, 0U, (uint16_t*)bldcadcRawValue);
//	ADC_DRV_GetChanResult(INST_ADCONV0, 1U, (uint16_t*)(bldcadcRawValue + 1));
//	ADC_DRV_GetChanResult(INST_ADCONV0, 2U, (uint16_t*)(bldcadcRawValue + 2));

	ADCResults.DCBIOffset 	= (I_MAX/2.0F);

	MEAS_GetUICurrent(&ADCResults.DCBUIVoltageRaw);
	MEAS_GetVICurrent(&ADCResults.DCBVIVoltageRaw);
	MEAS_GetWICurrent(&ADCResults.DCBWIVoltageRaw);
	MEAS_GetADC0Current(&ADC0CHnResult);

	ADC0CHnComplete = 1;

	ADCResults.DCBIVoltageRaw = (ADCResults.DCBUIVoltageRaw < ADCResults.DCBVIVoltageRaw) ? ADCResults.DCBUIVoltageRaw : ADCResults.DCBVIVoltageRaw;
//	ADCResults.DCBIVoltageRaw = (ADCResults.DCBIVoltageRaw > ADCResults.DCBWIVoltageRaw) ? ADCResults.DCBIVoltageRaw : ADCResults.DCBWIVoltageRaw;

	if(ADCResults.DCBIVoltageRaw <= 5)
	{
//		// Real DC Bus current = Raw value - DC bus current offset
		ADCResults.DCBIVoltage = MLIB_Sub(ADCResults.DCBIOffset , ADCResults.DCBIVoltageRaw);

	}

	torque_filt = GDFLIB_FilterMA(ADCResults.DCBIVoltage, &Idcb_filt);

	//CtrlTask_FOCA();
}


