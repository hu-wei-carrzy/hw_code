#ifndef I_LAP_RUNIN_CFG_H
#define I_LAP_RUNIN_CFG_H


#define cU16Cfg_Tacho_Max    ((U16)4000U)
#define cU16Cfg_Speed_Max    ((U16)14000U)



#define cU8Cfg_RunIn_AllwStartTim   ((U8)10U)
#define cU8Cfg_RunIn_AllwEndTim   ((U8)60U)


#define cU8Cfg_LED_RunIn_Step1    ((U8)3U)
#define cU8Cfg_LED_RunIn_Step2    ((U8)5U)


#define cU8Cfg_Buz_RunIn_Step1    ((U8)5U)
#define cU8Cfg_Buz_RunIn_Step2    ((U8)10U)


#define cU8Cfg_Backlight_RunIn_Step1    ((U8)10U)
#define cU8Cfg_Backlight_RunIn_Step2    ((U8)20U)
#define cU8Cfg_Backlight_Val_Step1      ((U8)100U)
#define cU8Cfg_Backlight_Val_Step2      ((U8)20U)


#define cU8Cfg_Mort_StepSize            ((U8)2U)
#define mDefMotorStep(val)              (cU8Cfg_Mort_StepSize * (val))


#define cU8Cfg_Motor_RunIN_Step1        mDefMotorStep(1U)
#define cU8Cfg_Motor_RunIN_Step2        mDefMotorStep(2U)
#define cU8Cfg_Motor_RunIN_Step3        mDefMotorStep(3U)
#define cU8Cfg_Motor_RunIN_Step4        mDefMotorStep(4U)
#define cU8Cfg_Motor_RunIN_Step5        mDefMotorStep(5U)
#define cU8Cfg_Motor_RunIN_Step6        mDefMotorStep(6U)
#define cU8Cfg_Motor_RunIN_Step7        mDefMotorStep(7U)
#define cU8Cfg_Motor_RunIN_Step8        mDefMotorStep(8U)
#define cU8Cfg_Motor_RunIN_Step9        mDefMotorStep(9U)
#define cU8Cfg_Motor_RunIN_Step10       mDefMotorStep(10U)


#define cU8Cfg_PwrOut_RunIN_Step1       (U8)1U
#define cU8Cfg_PwrOut_RunIN_Step2       (U8)2U
#define cU8Cfg_PwrOut_RunIN_Step3       (U8)3U
#define cU8Cfg_PwrOut_RunIN_Step4       (U8)4U
#define cU8Cfg_PwrOut_RunIN_Step5       (U8)5U
#define cU8Cfg_PwrOut_RunIN_Step6       (U8)6U

#define cU16CfgRunInMode				(U16)1U
#define cU16CfgRunInFinish				(U16)1U


#endif
