#ifndef I_DAT_BAT_CFG_H
#define I_DAT_BAT_CFG_H


#define cU16DATBAT_VolStableLowerLimit  ((U16)(18000u))//上电稳定电压下限值
#define cU16DATBAT_WaitVolStableTime ((U16)(200U/cU16DATBat_TaskPeriodMs))//上电等待时间200ms

//2017年11月27日 16:40:13
//zjb, 3302
//根据测试结果，将更新时间由原来的1000ms修改为400ms,电压串口更新周期为500ms
//所以速度更快也没有太大意义。
//#define cU16VolForLcdRefreshPeriodMs    ((U16)400U) //LCD屏显示电压更新周期400ms
//#define cU8VolForLcdCnt               ((U8)(cU16VolForLcdRefreshPeriodMs / cU16DATBat_TaskPeriodMs))

//电压确认次数
#define cU16DATBat_Sts_Cofirm_Times_Low     ((U16)((cU16DATBat_Sts_Cofirm_Time - ((U16)cU16DATBat_TaskPeriodMs * cU8DATBAT_SampledNumMax)) / cU16DATBat_TaskPeriodMs))
#define cU16DATBat_Sts_Cofirm_Times_Normal      cU16DATBat_Sts_Cofirm_Times_Low
#define cU16DATBat_Sts_Cofirm_Times_High        cU16DATBat_Sts_Cofirm_Times_Low

//确认电压状态界限值,单位mv
#define cU16DATBAT_Low2ToLow2Max   ((U16)(11500U))  //12V//电源管理方案为12V软件实现未11.5V，避免低电压，超差，仪表误处理。
#define cU16DATBAT_Low2ToLow1Min   ((U16)(11500U))
#define cU16DATBAT_Low2ToLow1Max   ((U16)(18000U))
#define cU16DATBAT_Low2ToNormalMax ((U16)(33000U))
#define cU16DATBAT_Low2ToHignMin   ((U16)(33000U))

#define cU16DATBAT_Low1ToLow2Max   ((U16)(11500U))  //12V
#define cU16DATBAT_Low1ToLow1Min   ((U16)(11500U))
#define cU16DATBAT_Low1ToNormalMin   ((U16)(18000U))
#define cU16DATBAT_Low1ToNormalMax ((U16)(33000U))
#define cU16DATBAT_Low1ToHignMin   ((U16)(33000U))

#define cU16DATBAT_NormalToLow2Max   ((U16)(11500U))
#define cU16DATBAT_NormalToLow1Max   ((U16)(16000U))
#define cU16DATBAT_NormalToNormalMin    ((U16)(16000U))
#define cU16DATBAT_NormalToNormalMax    ((U16)(33000U))
#define cU16DATBAT_NormalToHignMin  ((U16)(33000U))

#define cU16DATBAT_HignToLow2Max     ((U16)(11500U))
#define cU16DATBAT_HignToLow1Max     ((U16)(16000U))
#define cU16DATBAT_HignToNormalMin  ((U16)(16000U))
#define cU16DATBAT_HignToNormalMax  ((U16)(32000U))
#define cU16DATBAT_HignToHignMin    ((U16)(32000U))
/*
#define cU16DATBAT_LowToLowMax  ((U16)(18000U))  //18V
#define cU16DATBAT_LowToNormalMin   ((U16)(18000U))
#define cU16DATBAT_LowToNormalMax   ((U16)(33500U))
#define cU16DATBAT_LowToHignMin ((U16)(33500U))

#define cU16DATBAT_NormalToLowMax   ((U16)(16000U))
#define cU16DATBAT_NormalToNormalMin    ((U16)(16000U))
#define cU16DATBAT_NormalToNormalMax    ((U16)(33500U))
#define cU16DATBAT_NormalToHignMin  ((U16)(33500U))

#define cU16DATBAT_HignToLowMax ((U16)(16000U))
#define cU16DATBAT_HignToNormalMin  ((U16)(16000U))
#define cU16DATBAT_HignToNormalMax  ((U16)(32000U))
#define cU16DATBAT_HignToHignMin    ((U16)(32000U))
*/
//诊断电压值,单位mv,change by zc 与电源管理上下限值保持一致
#define cU16DATBAT_DiagVoltageBelow         cU16DATBAT_Low1ToLow2Max
#define cU16DATBAT_DiagVoltageAbove         cU16DATBAT_NormalToHignMin

//编号： SFREQ-4.46  电压报警限值，单位mv
#define cU16DATBAT_AlarmVoltageAbove            ((U16)(300U))//为避免在报警点附近波动，降低分辨率  banfy
#define cU16DATBAT_AlarmVoltageBelow            ((U16)(220U))//为避免在报警点附近波动，降低分辨率  banfy

//电压报警确认时间，单位ms
#define cU16DATBAT_AlarmVoltageHighTime ((U16)(1000U))//电压高报警：电压持续1秒大于30V
#define cU16DATBAT_AlarmVoltageLowTime      ((U16)(3000U))//电压低报警：电压持续3秒小于22V



#define cU16BatCalInvalid        ((U16)0xFFFFU)
#endif
