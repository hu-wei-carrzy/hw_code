
#include "BSP_AD.h"
#include"S32K144.h"
#include ".\..\BSP_DIO\BSP_DIO_EXPORT.h"
#include ".\..\BSP_DIO\BSP_DIO_CFG_GEN.h"
#include "..\BSP_PDB\BSP_PDB.h"
#include "..\BSP_PWM\BSP_PWM.h"

static void BSPAdCalibration(ADC_Type *base);
static void BSPAdFuncCfg(ADC_Type *base);
static void BSPAdSelectPDBAsTrigger(void);


//==============================================================================
// DESCRIPTION :BSP_MotorADC0_Init
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void BSP_ADC0_Init(void)
{
	/*初始化ADC0的位数和触发源*/
	ADC_DRV_ConfigConverter(INST_ADCONV0, &adConv0_ConvConfig0);
	ADC_DRV_AutoCalibration(INST_ADCONV0);

	ADC_DRV_ConfigChan(INST_ADCONV0, 0, &adConv0_ChnConfig0);
	ADC_DRV_ConfigChan(INST_ADCONV0, 1, &adConv0_ChnConfig1);
	ADC_DRV_ConfigChan(INST_ADCONV0, 2, &adConv0_ChnConfig2);
	ADC_DRV_ConfigChan(INST_ADCONV0, 3, &adConv0_ChnConfig3);
}

//==============================================================================
// DESCRIPTION :BSP_MotorADC1_Init
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void BSP_ADC1_Init(void)
{
	/*初始化ADC的位数和触发源*/
	ADC_DRV_ConfigConverter(INST_ADCONV1, &adConv1_ConvConfig0);
	ADC_DRV_AutoCalibration(INST_ADCONV1);

	/*初始化ADC的通道：对于DC电机主要是ADC1的3/13/6/2*/
	ADC_DRV_ConfigChan(INST_ADCONV1, 0, &adConv1_ChnConfig0);
	ADC_DRV_ConfigChan(INST_ADCONV1, 1, &adConv1_ChnConfig1);
	ADC_DRV_ConfigChan(INST_ADCONV1, 2, &adConv1_ChnConfig2);
	ADC_DRV_ConfigChan(INST_ADCONV1, 3, &adConv1_ChnConfig3);
}


/**************************************************************************************************
 名称：BSPAdReadAdc0ConversionFlag
 作用：读取AD转换完成标志
  输入：无
 返回：无
 描述：
**************************************************************************************************/
uint8_t BSPAdReadAdc0ConversionFlg(void)
{
	return ADC0CHnComplete;
    //return (ADC0->SC1[0]) & ADC_SC1_COCO_MASK;
	//return 0;
}

/**************************************************************************************************
 名称：BSPAdClearAdc0ConversionFlag
 作用：读取AD转换完成标志
  输入：无
 返回：无
 描述：
**************************************************************************************************/
uint8_t BSPAdClearAdc0ConversionFlag(void)
{
	ADC0CHnComplete = 0;
	return ADC0CHnComplete;
    //return (ADC0->SC1[0]) & ADC_SC1_COCO_MASK;
	//return 0;
}
/**************************************************************************************************
 名称：BSPAdReadAdc1ConversionFlag
 作用：读取AD转换完成标志
  输入：无
 返回：无
 描述：
**************************************************************************************************/
uint8_t BSPAdReadAdc1ConversionFlg(void)
{
    //return (ADC1->SC1[0]) & ADC_SC1_COCO_MASK;
	return ADC1CHnComplete;
    //return 0;
}
/**************************************************************************************************
 名称：BSPAdClearAdc0ConversionFlag
 作用：读取AD转换完成标志
  输入：无
 返回：无
 描述：
**************************************************************************************************/
uint8_t BSPAdClearAdc1ConversionFlag(void)
{
	ADC1CHnComplete = 0;
	return ADC1CHnComplete;
    //return (ADC0->SC1[0]) & ADC_SC1_COCO_MASK;
	//return 0;
}

/**************************************************************************************************
 名称：BSPReadADC0Value
 作用：读取ADC0指定通道的值
  输入：chn——通道序号
 返回：通道的AD值
 描述：
**************************************************************************************************/
uint16_t BSPAdReadAdc0Value(void)
{
	uint16_t temp = 0;

	temp = ADC0CHnResult;

    //temp = ADC0->R[0];

    return (uint16_t)temp;
}

/**************************************************************************************************
 名称：BSPReadADC0Value
 作用：读取ADC0指定通道的值
  输入：chn——通道序号
 返回：通道的AD值
 描述：
**************************************************************************************************/
uint16_t BSPAdReadAdc1Value(void)
{
	uint16_t temp = 0;

	temp = ADC1CHnResult;

    //temp = ADC1->R[0];

    return (uint16_t)temp;
}

/**************************************************************************************************
 名称：BSPReadADC0Value
 作用：读取ADC0指定通道的值
  输入：chn——通道序号
 返回：通道的AD值
 描述：
**************************************************************************************************/
void BSPAdSelectADC0chn (uint8_t chn)
{
    uint32_t temp = 0;

    temp = ADC0->SC1[3];
    temp &= ~(ADC_SC1_ADCH_MASK);
    temp |= ADC_SC1_ADCH(chn);
    ADC0->SC1[3] = temp;
}

/**************************************************************************************************
 名称：BSPReadADC0Value
 作用：读取ADC0指定通道的值
  输入：chn——通道序号
 返回：通道的AD值
 描述：
**************************************************************************************************/
void BSPAdSelectADC1chn (uint8_t chn)
{
    uint32_t temp = 0;

    temp = ADC1->SC1[4];
    temp &= ~(ADC_SC1_ADCH_MASK);
    temp |= ADC_SC1_ADCH(chn);
    ADC1->SC1[0] = temp;
}

/**************************************************************************************************
 名称：ADC_CAL
 作用：用于校准AD模块，不校准的话数据可能不对
  输入：base：对应AD模块基地址，ADC0,ADC1
 返回：无
 描述：根据手册S32K1XXRM Rev. 9, 09/2018的ADC模块中Calibration function功能描述，进行校准
 	     前提条件：  1. VREF稳定，系统运行到这个地方，默认为系统已经稳定了
  		     	2. AD模块时钟<=1/2的最大允许AD时钟，S32K144最大时钟为40MHZ，目前系统配置的AD时钟为20MHZ，
  	     操作： 1. 清零CLPS, CLP3, CLP2, CLP1, CLP0, CLPX, and CLP9
  	        2. Start ADC calibration by writing SC3[CAL] = 1, SC3[AVGE] = 1, and SC3[AVGS] = 11b.
  	        3. 这一步与手册不同，手册要求：Wait for calibration to finish. This will be indicated by conversion complete
  	           flag (SC1n[COCO] = 1)，实际测试这个位没有，而PE中自动校准使用的是CAL标志位
**************************************************************************************************/
static void BSPAdCalibration(ADC_Type *base)
{
    uint32_t delay = 0;

    base->CLPS = 0;
    base->CLP3 = 0;
    base->CLP2 = 0;
    base->CLP1 = 0;
    base->CLP0 = 0;
    base->CLPX = 0;
    base->CLP9 = 0;

    base->SC3 = ADC_SC3_CAL(1) + ADC_SC3_AVGE(1) + ADC_SC3_AVGS(3);
    while ((base->SC3 & ADC_SC3_CAL_MASK))  //等待校准完成
    {
        delay++; 			//10ms超时退出
        if (delay > 30000u)
        {
            break;
        }
    }
}

/**************************************************************************************************
 名称：BSPAdFuncCfg
 作用：配置AD模块的功能，为ADC设置关键参数
  输入：base：AD模块的地址
 返回：无
 描述：定义ADC的多个关键特性，包括时钟频率、数据精度、采样时间、触发方式和触发模式。
**************************************************************************************************/
static void BSPAdFuncCfg(ADC_Type *base)
{

}

/**************************************************************************************************
 名称：BSPAdResetAdc0ChnStatus
 作用：清空通道的状态，如果不清除，PDB模块可能会出错
  输入：无
 返回：无
 描述：
**************************************************************************************************/
static void BSPAdResetChnStatus(ADC_Type * base)
{

}

/**************************************************************************************************
 名称：BSPADInit
 作用：用于初始化AD模块
  输入：无
 返回：无
 描述：
**************************************************************************************************/
void BSPAdInit(void)
{
	BSP_ADC0_Init();
	BSPAdCalibration(ADC0); 				// 校准ADC0，否则误差比较大
	BSP_ADC1_Init();
	BSPAdCalibration(ADC1); 				// 校准ADC1，否则误差比较大
}

/**************************************************************************************************
 名称：BSPAd0Start
 作用：启动AD转换
  输入：无
 返回：无
 描述：注意PDB模块不能重复触发，因为会导致通道错误
**************************************************************************************************/
void BSPAdStart(void)
{

}

/**************************************************************************************************
 名称：BSPAdStop
 作用：停止AD转换
  输入：无
 返回：无
 描述：因为AD转换是单次的，所以会自动停止，不需要在进入休眠的时候进行处理
**************************************************************************************************/
void BSPAdStop(void)
{

}
