

/*********************************************************************************************
** Header files
*********************************************************************************************/

#include "typedefs.h"
//#include "os_timer.h"
//#include "r_cg_adc.h"
//#include "latch_control.h"
#include "system_control.h"
#include "system_calibration.h"
//#include "speed_control.h"
//#include "obstacle_detect.h"
//#include "fault_process.h"
#include "message_process.h"
//#include "request_process.h"
#include "api_interface.h"
//#include "pinout_manage.h"
//#include "spindle_control.h"
//#include "telltales_report.h"
//#include "buzzer_control.h"
//#include "command_process.h"
//#include "ecu_fft_test.h"
//#include "speed_control.h"
//#include "spoiler_control.h"
//#include "gate_calibrationfile.h"
//#include "manual_control.h"
#include "S32K144Types.h"

/*********************************************************************************************
** Local define and type
*********************************************************************************************/


/*********************************************************************************************
**   Pinout manage
*********************************************************************************************/

const uint16_t K_AntiPinchATD_OnePressed_LowLimit = 230U;
const uint16_t K_AntiPinchATD_OnePressed_HighLimit = 270U;

const uint16_t K_AntiPinchATD_TwoPressed_LowLimit = 0U;
const uint16_t K_AntiPinchATD_TwoPressed_HighLimit = 50U;

const uint16_t K_AntiPinchRightATD_OnePressed_LowLimit = 0U;
const uint16_t K_AntiPinchRightATD_OnePressed_HighLimit = 50U;

const uint16_t K_AntiPinchLeftATD_OnePressed_LowLimit = 0U;
const uint16_t K_AntiPinchLeftATD_OnePressed_HighLimit = 50U;

const uint16_t K_PawlSwitch_HallEffect_Active_LowLimit = 2800U;/*12V = 2936 TRUE*/
const uint16_t K_PawlSwitch_HallEffect_Active_HighLimit = 3100U;

const uint16_t K_PawlSwitch_HallEffect_Inactive_LowLimit = 1400U;/*12V = 1286 FALSE*/
const uint16_t K_PawlSwitch_HallEffect_Inactive_HighLimit = 1100U;

const uint16_t K_PositionSwitch_HallEffect_Active_LowLimit = 2800U;/*12V = 2936 TRUE*/
const uint16_t K_PositionSwitch_HallEffect_Active_HighLimit = 3100U;

const uint16_t K_PositionSwitch_HallEffect_Inactive_LowLimit = 1400U;/*12V = 1286 FALSE*/
const uint16_t K_PositionSwitch_HallEffect_Inactive_HighLimit = 1100U;

const uint16_t K_ModeSwitchInput_Ratio_Denominator = 100U; /*Denominator*/
const uint16_t K_NormalSwitchRatio_LowLimit = 80U;  /* Ratio */
const uint16_t K_NormalSwitchRatio_HighLimit = 90U;  /* Ratio */

const uint16_t K_GarageSwitchRatio_LowLimit = 60U;  /* Ratio */
const uint16_t K_GarageSwitchRatio_HighLimit = 70U;  /* Ratio */

const uint16_t K_DisableSwitchRatio_LowLimit = 40U;  /* Ratio */
const uint16_t K_DisableSwitchRatio_HighLimit = 45U;  /* Ratio */

const uint16_t K_NormalSwitchInput_Voltage_LowLimit = 65U;  /* 100=1V */
const uint16_t K_NormalSwitchInput_Voltage_HighLimit = 100U;  /* 100=1V */
const uint16_t K_GarageSwitchInput_Voltage_LowLimit = 180U;  /* 100=1V */
const uint16_t K_GarageSwitchInput_Voltage_HighLimit = 210U;  /* 100=1V */
const uint16_t K_DisableSwitchInput_Voltage_LowLimit = 10U;  /* 100=1V */
const uint16_t K_DisableSwitchInput_Voltage_HighLimit = 50U;  /* 100=1V */



const uint16_t K_HandleHandFreeShareSwitch_ShortPress_LowLimit_Time = 3U; /* 3 x 10ms*/
const uint16_t K_HandleHandFreeShareSwitch_ShortPress_HighLimit_Time = 12U; /* 100 x 10ms*/
const uint16_t K_HandleHandFreeShareSwitch_LongPress_LowLimit_Time = 12U; /* 30 x 10ms*/
const uint16_t K_HandleHandFreeShareSwitch_LongPress_HighLimit_Time = 500U; /* 500 x 10ms*/

const uint16_t K_HandleOpenSwitch_ShortPress_LowLimit_Time = 5U; /* 50 x 10ms*/
const uint16_t K_HandleOpenSwitch_ShortPress_HighLimit_Time = 100U; /* 100 x 10ms*/
const uint16_t K_HandleOpenSwitch_LongPress_LowLimit_Time = 100U; /* 300 x 10ms*/
const uint16_t K_HandleOpenSwitch_LongPress_HighLimit_Time = 500U; /* 500 x 10ms*/

const uint16_t K_HandleCloseSwitch_ShortPress_LowLimit_Time = 5U; /* 50 x 10ms*/
const uint16_t K_HandleCloseSwitch_ShortPress_HighLimit_Time = 100U; /* 100 x 10ms*/
const uint16_t K_HandleCloseSwitch_LongPress_LowLimit_Time = 100U; /* 300 x 10ms*/
const uint16_t K_HandleCloseSwitch_LongPress_HighLimit_Time = 500U; /* 500 x 10ms*/

const uint16_t K_BrakeSwitch_ShortPress_LowLimit_Time = 5U; /* 50 x 10ms*/
const uint16_t K_BrakeSwitch_ShortPress_HighLimit_Time = 50U;//100U; /* 100 x 10ms*/
const uint16_t K_BrakeSwitch_LongPress_LowLimit_Time = 50U;//100U; /* 300 x 10ms*/
const uint16_t K_BrakeSwitch_LongPress_HighLimit_Time = 500U; /* 500 x 10ms*/


const uint16_t K_Current_Value_PerOneAmp = 100U;

const uint16_t K_Motor1_High_Range_Current = 1600U; // 1600 = 16amps
const uint16_t K_Motor2_High_Range_Current = 1600U; // 1600 = 16amps

const uint16_t K_Motor1_Low_Range_Current = 1600U; // 1600 = 16amps
const uint16_t K_Motor2_Low_Range_Current = 1600U; // 1600 = 16amps

const uint16_t K_Motor1_Current_Range_Count = 5U; // 5 x 5ms
const uint16_t K_Motor2_Current_Range_Count = 5U; // 5 x 5ms

const uint16_t K_ReleaseMotor_Buzzer_Clutch_CurrentSensor_Time = 2;

#ifdef _CONFIG_Gen1_Board
const uint16_t K_Motor1_FET_Base_Offset_Value_Default = 600U;
const uint16_t K_Motor1_FET_Cal_Ratio_Value_Default = 100U;
const uint16_t K_Motor1_FET_Cal_Ratio_Denominator = 100U;

const uint16_t K_Motor2_FET_Base_Offset_Value_Default = 600U;
const uint16_t K_Motor2_FET_Cal_Ratio_Value_Default = 100U;
const uint16_t K_Motor2_FET_Cal_Ratio_Denominator = 100U;

const uint16_t K_CinchMotor_FET_Base_Offset_Value_Default = 0U;
const uint16_t K_CinchMotor_FET_Cal_Ratio_Value_Default = 100U;
const uint16_t K_CinchMotor_FET_Cal_Ratio_Denominator = 100U;

const uint16_t K_ReleaseMotor_FET_Base_Offset_Value_Default = 10U;
const uint16_t K_ReleaseMotor_FET_Cal_Ratio_Value_Default = 100U;
const uint16_t K_ReleaseMotor_FET_Cal_Ratio_Denominator = 100U;

const uint16_t K_Buzzer_FET_Base_Offset_Value_Default = 10U;
const uint16_t K_Buzzer_FET_Cal_Ratio_Value_Default = 100U;
const uint16_t K_Buzzer_FET_Cal_Ratio_Denominator = 100U;

const uint16_t K_Clutch_FET_Base_Offset_Value_Default = 0U;
const uint16_t K_Clutch_FET_Cal_Ratio_Value_Default = 100U;
const uint16_t K_Clutch_FET_Cal_Ratio_Denominator = 100U;
#endif

#ifdef _CONFIG_Gen2_Board
const uint16_t K_Motor1_FET_Base_Offset_Value_Default = 30U;
const uint16_t K_Motor1_FET_Cal_Ratio_Value_Default = 100U;
const uint16_t K_Motor1_FET_Cal_Ratio_Denominator = 100U;

const uint16_t K_Motor2_FET_Base_Offset_Value_Default = 30U;
const uint16_t K_Motor2_FET_Cal_Ratio_Value_Default = 100U;
const uint16_t K_Motor2_FET_Cal_Ratio_Denominator = 100U;

const uint16_t K_CinchMotor_FET_Base_Offset_Value_Default = 30U;
const uint16_t K_CinchMotor_FET_Cal_Ratio_Value_Default = 100U;
const uint16_t K_CinchMotor_FET_Cal_Ratio_Denominator = 100U;

const uint16_t K_ReleaseMotor_FET_Base_Offset_Value_Default = 0U;
const uint16_t K_ReleaseMotor_FET_Cal_Ratio_Value_Default = 100U;
const uint16_t K_ReleaseMotor_FET_Cal_Ratio_Denominator = 100U;

const uint16_t K_Buzzer_FET_Base_Offset_Value_Default = 0U;
const uint16_t K_Buzzer_FET_Cal_Ratio_Value_Default = 100U;
const uint16_t K_Buzzer_FET_Cal_Ratio_Denominator = 100U;

const uint16_t K_Clutch_FET_Base_Offset_Value_Default = 0U;
const uint16_t K_Clutch_FET_Cal_Ratio_Value_Default = 100U;
const uint16_t K_Clutch_FET_Cal_Ratio_Denominator = 100U;
#endif

#ifdef _CONFIG_Gen3_Board
const uint16_t K_Motor1_FET_Base_Offset_Value_Default = 2048U;
const uint16_t K_Motor1_FET_Cal_Ratio_Value_Default = 100U;
const uint16_t K_Motor1_FET_Cal_Ratio_Denominator = 100U;

const uint16_t K_Motor2_FET_Base_Offset_Value_Default = 2048U;
const uint16_t K_Motor2_FET_Cal_Ratio_Value_Default = 100U;
const uint16_t K_Motor2_FET_Cal_Ratio_Denominator = 100U;

const uint16_t K_CinchMotor_FET_Base_Offset_Value_Default = 2048U;
const uint16_t K_CinchMotor_FET_Cal_Ratio_Value_Default = 100U;
const uint16_t K_CinchMotor_FET_Cal_Ratio_Denominator = 100U;

const uint16_t K_Motor4_FET_Base_Offset_Value_Default = 2048U;
const uint16_t K_Motor4_FET_Cal_Ratio_Value_Default = 100U;
const uint16_t K_Motor4_FET_Cal_Ratio_Denominator = 100U;

const uint16_t K_ReleaseMotor_FET_Base_Offset_Value_Default = 0U;
const uint16_t K_ReleaseMotor_FET_Cal_Ratio_Value_Default = 100U;
const uint16_t K_ReleaseMotor_FET_Cal_Ratio_Denominator = 100U;

const uint16_t K_Buzzer_FET_Base_Offset_Value_Default = 0U;
const uint16_t K_Buzzer_FET_Cal_Ratio_Value_Default = 100U;
const uint16_t K_Buzzer_FET_Cal_Ratio_Denominator = 100U;

const uint16_t K_Clutch_FET_Base_Offset_Value_Default = 0U;
const uint16_t K_Clutch_FET_Cal_Ratio_Value_Default = 100U;
const uint16_t K_Clutch_FET_Cal_Ratio_Denominator = 100U;
#endif

#ifdef _CONFIG_Gen4_Board
const uint16_t K_Motor1_FET_Base_Offset_Value_Default = 0U;
const uint16_t K_Motor1_FET_Cal_Ratio_Value_Default = 100U;
const uint16_t K_Motor1_FET_Cal_Ratio_Denominator = 100U;

const uint16_t K_Motor2_FET_Base_Offset_Value_Default = 2048U;
const uint16_t K_Motor2_FET_Cal_Ratio_Value_Default = 100U;
const uint16_t K_Motor2_FET_Cal_Ratio_Denominator = 100U;

const uint16_t K_CinchMotor_FET_Base_Offset_Value_Default = 0U;
const uint16_t K_CinchMotor_FET_Cal_Ratio_Value_Default = 100U;
const uint16_t K_CinchMotor_FET_Cal_Ratio_Denominator = 100U;

const uint16_t K_Motor4_FET_Base_Offset_Value_Default = 2048U;
const uint16_t K_Motor4_FET_Cal_Ratio_Value_Default = 100U;
const uint16_t K_Motor4_FET_Cal_Ratio_Denominator = 100U;

const uint16_t K_ReleaseMotor_FET_Base_Offset_Value_Default = 0U;
const uint16_t K_ReleaseMotor_FET_Cal_Ratio_Value_Default = 100U;
const uint16_t K_ReleaseMotor_FET_Cal_Ratio_Denominator = 100U;

const uint16_t K_Buzzer_FET_Base_Offset_Value_Default = 0U;
const uint16_t K_Buzzer_FET_Cal_Ratio_Value_Default = 100U;
const uint16_t K_Buzzer_FET_Cal_Ratio_Denominator = 100U;

const uint16_t K_Clutch_FET_Base_Offset_Value_Default = 0U;
const uint16_t K_Clutch_FET_Cal_Ratio_Value_Default = 100U;
const uint16_t K_Clutch_FET_Cal_Ratio_Denominator = 100U;
#endif

const uint16_t K_Motor1_Current_Voltage_Value_Diagnostic_Threshold = 3900U;
const uint16_t K_Motor2_Current_Voltage_Value_Diagnostic_Threshold = 3900U;
const uint16_t K_CinchMotor_Current_Voltage_Value_Diagnostic_Threshold = 3900U;
const uint16_t K_ReleaseMotor_Current_Voltage_Value_Diagnostic_Threshold = 3900U;
const uint16_t K_Buzzer_Current_Voltage_Value_Diagnostic_Threshold = 3900U;
const uint16_t K_Clutch_Current_Voltage_Value_Diagnostic_Threshold = 3900U;

const uint16_t K_AnalogInputDebounce_Start_Time = 10U; /* 10ms x  */
const uint16_t K_Pinout_Initial_End_Time = 3U;  /* 10ms x  */




#ifdef _CONFIG_Pinout_Initial_ShortTimeDebounce
const uint16_t K_LatchPowerOn_Time = 0U;//6U; /* 10ms x  */
const uint16_t K_LatchWakeUp_Time = 0U;//6U; /* 10ms x  */
const uint16_t K_LatchReset_Time = 0U;//6U; /* 10ms x  */
#else
const uint16_t K_LatchPowerOn_Time = 7U; /* 10ms x  */
const uint16_t K_LatchWakeUp_Time = 7U; /* 10ms x  */
const uint16_t K_LatchReset_Time = 7U;//6U; /* 10ms x  */
#endif

#ifdef _CONFIG_InginLatch
/*********************************************************************************************
**    Ingin Latch Control
*********************************************************************************************/
const uint16_t K_PowerCinchInSecondPosition_AfterPowerUp_Enable = TRUE;

const uint16_t K_LatchPreCinchCheck_Timeout = 2000U; /* 1ms x  */

#ifdef _CONFIG_InginLatch_PSA
const uint16_t K_LatchPowerCinching_Timeout = 4000U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterCinch_Timeout = 4000U; /* 1ms x  */
const uint16_t K_LatchPowerReleasing_Timeout = 4000U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterRelease_Timeout = 1000U; /* 1ms x  */
const uint16_t K_ContinueFindHomeAfterRelease_Time = 10U; /* 1ms x  */
#else
const uint16_t K_LatchPowerCinching_Timeout = 4000U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterCinch_Timeout = 4000U; /* 1ms x  */
const uint16_t K_LatchPowerReleasing_Timeout = 2000U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterRelease_Timeout = 1000U; /* 1ms x  */
const uint16_t K_ContinueFindHomeAfterRelease_Time = 50U;//100U; /* 1ms x  */
#endif

const uint16_t K_LatchPreReleasing_Timeout = 4000U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterRelease_Mini_Time = 100U; /* 1ms x  */
const uint16_t K_LatchFindHomeReleaseDirection_Timeout = 5000U; /* 1ms x  */
const uint16_t K_LatchFindHomeCinchDirection_Timeout = 500U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterPark_Timeout = 500U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterBlip_Timeout = 100U; /* 1ms x  */

const uint16_t K_LatchCrankWait_Timeout = 2000U; /* 1ms x  */
const uint16_t K_LatchMechFailure_Timeout = 2000U;

const uint16_t K_LatchPreCinchCheck_Time = 70U; /* 1ms x  */


const uint16_t K_PowerReleasing_PawlSwitch_Delay_Time = 100U; /* 1ms x  */ 
const uint16_t K_PowerReleasing_OutofLatch_Delay_Time = 0U;//50U; /* 1ms x  */ 

const uint16_t K_CinchMotor_IncreaseStep_Duty = 1U; /* x% x  */

#ifdef _SAICMIFA_SPX1
const uint16_t K_PowerCinching_Delay_Time = 10U; /* 1ms x  */
const uint16_t K_PreReleased_OutofLatch_Delay_Time = 1000U;//3000U;//500U; /* 1ms x  */
const uint16_t K_LatchPreReleased_Timeout = 8000U; 
const uint16_t K_LatchPreRelease_SnowLoad_Time = 1000U;
const uint16_t K_SnowLoad_Timeout_PowerCinching_Delay_Time = 5000U; /* 1ms x  */
#else
const uint16_t K_PowerCinching_Delay_Time = 30U; /* 1ms x  */
const uint16_t K_PreReleased_OutofLatch_Delay_Time = 100U;//500U; /* 1ms x  */
const uint16_t K_LatchPreReleased_Timeout = 3000U; 
const uint16_t K_LatchPreRelease_SnowLoad_Time = 3000U;
const uint16_t K_SnowLoad_Timeout_PowerCinching_Delay_Time = 3000U; /* 1ms x  */
#endif

const uint16_t K_StopBeforePowerReleasing_Time = 0U; /* 1ms x  */
const uint16_t K_StopBeforePreReleasing_Time = 0U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeAfterRelease_Time = 50U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeAfterPark_Time = 50U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeAfterBlip_Time = 50U; /* 1ms x  */
const uint16_t K_MiniWorkingInCinchDirection_Time = 100U; /* 1ms x  */
const uint16_t K_ChangeDutyInFindHomeAfterRelease_Time = 100U;/* 1ms x  */
const uint16_t K_FindHomeAfterPark_PositionSwitch_Delay_Time = 100U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeCinchDirection_Time = 100U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeReleaseDirection_Time = 100U;  /* 1ms x  */
const uint16_t K_LatchFindHomeFailure_Timeout = 1000U;  /* 1ms x  */

const uint16_t K_FindHomeReleaseDirection_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_FindHomeCinchDirection_Inrush_Time = 200U; /* 1ms x  */

const uint16_t K_PowerCinching_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_FindHomeAfterCinch_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_FindHomeAfterPark_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_PreReleasing_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_PowerReleasing_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_FindHomeAfterRelease_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_PowerReleasing_Mini_Time = 200U; /* 1ms x  */

const uint16_t K_FindHomeAfterCinch_StartDuty_Time = 50U;  /*10ms x */
const uint16_t K_FindHomeAfterCinch_DecreaseDuty_Time = 2U;   /* 10ms x  */
const uint16_t K_FindHomeAfterCinch_IncreaseDuty_Time = 1U;   /* 10ms x  */

const uint16_t K_CinchMotorFindHome_Count = 3;

const uint16_t K_PrimaryPositionIsArrived_Time= 2U;
const uint16_t K_ChangeDutyInFindHomeAfterCinch_Time = 300U; /* 1ms x  */
const uint16_t K_ChangeDutyInFindHomeAfterCinch_Time_2nd = 100U; /* 1ms x  */
#ifdef _CONFIG_InginLatch_PSA
const uint16_t K_ChangeDutyInPowerCinching_Time = 2000U; /* 1ms x  */
const uint16_t K_ContinueParking_Time = 10U;
const uint16_t K_ContinueParking_Time_2nd = 10U;
#else
const uint16_t K_ChangeDutyInPowerCinching_Time = 3000U; /* 1ms x  */
const uint16_t K_ContinueParking_Time = 130U;
const uint16_t K_ContinueParking_Time_2nd = 130U;
#endif
const uint16_t K_CinchMotor_PowerCinching_Duty = 80U;
const uint16_t K_CinchMotor_PowerCinching_Duty_2nd = 80U;

const uint16_t K_CinchMotor_FindHomeAfterCinch_Duty = 20U;
const uint16_t K_CinchMotor_FindHomeAfterCinch_Duty_2nd = 70U;

const uint16_t K_LowDutyFailFindHomeAfterCinch_Time = 6000U;/* 1ms x  */ 
const uint16_t K_LowDutyFailFindHomeAfterCinch_Duty = 60U; 
#ifdef _CONFIG_InginLatch_PSA
const uint16_t K_LowDutyFailPowerCinching_Time = 2500U;/* 1ms x  */ 
#else
const uint16_t K_LowDutyFailPowerCinching_Time = 3200U;/* 1ms x  */ 
#endif
const uint16_t K_LowDutyFailPowerCinching_Duty = 100U;

const uint16_t K_CinchMotor_FindHomeAfterRelease_Duty = 70U;
const uint16_t K_CinchMotor_FindHomeAfterRelease_Duty_2nd = 70U;
const uint16_t K_CinchMotor_FindHomeAfterRelease_Duty_3rd = 70U;

const uint16_t K_CinchMotor_FindHomeReleaseDirection_Duty = 100U;
const uint16_t K_CinchMotor_FindHomeReleaseDirection_Duty_2nd = 50U;
const uint16_t K_CinchMotor_FindHomeCinchDirection_Duty = 100U;
const uint16_t K_CinchMotor_FindHomeCinchDirection_Duty_2nd = 50U;

const uint16_t K_CinchMotor_FindHomeAfterPark_Duty = 70U;
const uint16_t K_CinchMotor_FindHomeAfterBlip_Duty = 30U;

const uint16_t K_ReleaseMotor_PowerReleasing_Duty = 100U;
const uint16_t K_ReleaseMotor_PowerReleasing_Duty_2nd = 100U;
const uint16_t K_CinchMotor_PowerReleasing_Duty = 100U;
const uint16_t K_CinchMotor_PowerReleasing_Duty_2nd = 100U;

#ifdef _CONFIG_InginLatch_PSA
const uint16_t K_PowerReleasing_ComfirmCurrent = 500U;

const uint16_t K_PowerCinching_SoftStall_Current = 2000U;
const uint16_t K_FindHomeAfterCinch_SoftStall_Current = 2000U;
const uint16_t K_PreReleasing_SoftStall_Current = 2000U;
const uint16_t K_PowerReleasing_SoftStall_Current = 2000U;
const uint16_t K_FindHomeAfterRelease_SoftStall_Current = 2000U;
const uint16_t K_FindHomeReleaseDirection_SoftStall_Current = 500U;
const uint16_t K_FindHomeCinchDirection_SoftStall_Current = 500U;
const uint16_t K_FindHomeAfterPark_SoftStall_Current = 2000U;
#else
const uint16_t K_PowerReleasing_ComfirmCurrent = 200U;

const uint16_t K_PowerCinching_SoftStall_Current = 1000U;
const uint16_t K_FindHomeAfterCinch_SoftStall_Current = 1000U;
const uint16_t K_PreReleasing_SoftStall_Current = 1000U;
const uint16_t K_PowerReleasing_SoftStall_Current = 1000U;
const uint16_t K_FindHomeAfterRelease_SoftStall_Current = 1000U;
const uint16_t K_FindHomeReleaseDirection_SoftStall_Current = 200U;
const uint16_t K_FindHomeCinchDirection_SoftStall_Current = 200U;
const uint16_t K_FindHomeAfterPark_SoftStall_Current = 1000U;
#endif


const uint16_t K_PowerCinching_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeAfterCinch_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_PreReleasing_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_PowerReleasing_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeAfterRelease_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeReleaseDirection_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeCinchDirection_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeAfterPark_SoftStall_Time = 10U; /* 10ms x  */
 
const uint16_t K_StopBeforeFindHomeAfterCinch_Time = 20U;  /* 1ms x  */
const uint16_t K_LatchNotLeaveHomeInMiniPowerCinch_Time = 0U; /* 1ms x  */
const uint16_t K_PowerReleasing_ComfirmCurrent_Time = 5U; /* 10ms x  */
const uint16_t K_FindHomeAfterCinch_Work_MiniTime = 20U; /* 10ms x  */ 
const uint16_t K_ChangeDutyInFindHomeReleaseDirection_Time = 200U; /* 10ms x  */
const uint16_t K_ChangeDutyInFindHomeCinchDirection_Time = 200U; /* 10ms x  */

#endif

#ifdef _CONFIG_WitteLatch_SGM 
/*********************************************************************************************
**    Witte Latch Control
*********************************************************************************************/
const uint16_t K_PowerCinchInSecondPosition_AfterPowerUp_Enable = TRUE;

const uint16_t K_LatchPreCinchCheck_Timeout = 2000U; /* 1ms x  */
const uint16_t K_LatchPowerCinching_Timeout = 4000U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterCinch_Timeout = 4000U; /* 1ms x  */
const uint16_t K_LatchPreReleasing_Timeout = 4000U; /* 1ms x  */
const uint16_t K_LatchPowerReleasing_Timeout = 3000U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterRelease_Timeout = 2000U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterRelease_Mini_Time = 100U; /* 1ms x  */

const uint16_t K_PowerReleasing_OutofLatch_Delay_Time = 0U; /* 1ms x  */

const uint16_t K_LatchFindHomeReleaseDirection_Timeout = 5000U; /* 1ms x  */
const uint16_t K_LatchFindHomeCinchDirection_Timeout = 5000U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterPark_Timeout = 5000U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterBlip_Timeout = 100U; /* 1ms x  */


const uint16_t K_LatchPreReleased_Timeout = 3000U; 
const uint16_t K_LatchPreRelease_SnowLoad_Time = 3000U;
const uint16_t K_LatchMechFailure_Timeout = 2000U;

const uint16_t K_LatchCrankWait_Timeout = 2000U; /* 1ms x  */

const uint16_t K_LatchPreCinchCheck_Time = 50U;//100U; /* 1ms x  */

const uint16_t K_PowerCinching_Delay_Time = 30U; /* 1ms x  */
const uint16_t K_PowerReleasing_PawlSwitch_Delay_Time = 300U; /* 1ms x  */

const uint16_t K_StopBeforePowerReleasing_Time = 0U; /* 1ms x  */
const uint16_t K_StopBeforePreReleasing_Time = 0U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeAfterRelease_Time = 50U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeAfterPark_Time = 50U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeAfterBlip_Time = 50U; /* 1ms x  */
const uint16_t K_MiniWorkingInCinchDirection_Time = 100U; /* 1ms x  */
const uint16_t K_ContinueFindHomeAfterRelease_Time = 30U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeCinchDirection_Time = 100U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeReleaseDirection_Time = 100U;
const uint16_t K_LatchFindHomeFailure_Timeout = 1000U;


const uint16_t K_FindHomeReleaseDirection_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_FindHomeCinchDirection_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_PowerCinching_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_FindHomeAfterCinch_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_FindHomeAfterPark_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_PreReleasing_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_PowerReleasing_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_FindHomeAfterRelease_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_PowerReleasing_Mini_Time = 300U; /* 1ms x  */

const uint16_t K_CinchMotorFindHome_Count = 3;
const uint16_t K_CinchMotor_PowerCinching_Duty = 100U;

const uint16_t K_CinchMotor_FindHomeAfterCinch_Duty = 100U;
const uint16_t K_CinchMotor_FindHomeAfterCinch_Duty_2nd = 30U;
const uint16_t K_CinchMotor_FindHomeReleaseDirection_Duty = 100U;
const uint16_t K_CinchMotor_FindHomeReleaseDirection_Duty_2nd = 50U;
const uint16_t K_CinchMotor_FindHomeCinchDirection_Duty = 100U;
const uint16_t K_CinchMotor_FindHomeCinchDirection_Duty_2nd = 50U;


const uint16_t K_CinchMotor_FindHomeAfterPark_Duty = 50U;
const uint16_t K_CinchMotor_FindHomeAfterBlip_Duty = 30U;

const uint16_t K_ReleaseMotor_PowerReleasing_Duty = 100U;
const uint16_t K_ReleaseMotor_PowerReleasing_Duty_2nd = 100U;
const uint16_t K_CinchMotor_PowerReleasing_Duty = 50U;
const uint16_t K_CinchMotor_PowerReleasing_Duty_2nd = 50U;

const uint16_t K_PowerReleasing_ComfirmCurrent = 200U;

const uint16_t K_PowerCinching_SoftStall_Current = 1000U;
const uint16_t K_FindHomeAfterCinch_SoftStall_Current = 1000U;
const uint16_t K_PreReleasing_SoftStall_Current = 1000U;
const uint16_t K_PowerReleasing_SoftStall_Current = 1000U;
const uint16_t K_FindHomeAfterRelease_SoftStall_Current = 1000U;
const uint16_t K_FindHomeReleaseDirection_SoftStall_Current = 200U;
const uint16_t K_FindHomeCinchDirection_SoftStall_Current = 200U;
const uint16_t K_FindHomeAfterPark_SoftStall_Current = 1000U;



const uint16_t K_PowerCinching_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeAfterCinch_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_PreReleasing_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_PowerReleasing_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeAfterRelease_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeReleaseDirection_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeCinchDirection_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeAfterPark_SoftStall_Time = 10U; /* 10ms x  */

const uint16_t K_PrimaryPositionIsArrived_Time= 5U; 
const uint16_t K_StopBeforeFindHomeAfterCinch_Time = 100U;  /* 10ms x  */
const uint16_t K_LatchNotLeaveHomeInMiniPowerCinch_Time = 50U; /* 1ms x  */
const uint16_t K_ChangeDutyInFindHomeAfterCinch_Time = 200U;  /* 10ms x  */

const uint16_t K_PowerReleasing_ComfirmCurrent_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeAfterCinch_Work_MiniTime = 20U; /* 10ms x  */ 
const uint16_t K_ChangeDutyInFindHomeCinchDirection_Time = 200U; /* 10ms x  */

#endif

#ifdef _CONFIG_WitteLatch_Volvo
/*********************************************************************************************
**    Witte Latch Control
*********************************************************************************************/
const uint16_t K_PowerCinchInSecondPosition_AfterPowerUp_Enable = TRUE;

const uint16_t K_LatchPreCinchCheck_Timeout = 2000U; /* 1ms x  */
const uint16_t K_LatchPowerCinching_Timeout = 8000U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterCinch_Timeout = 15000U; /* 1ms x  */
const uint16_t K_LatchPreReleasing_Timeout = 5000U; /* 1ms x  */
const uint16_t K_LatchPowerReleasing_Timeout = 4000U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterRelease_Timeout = 2000U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterRelease_Mini_Time = 100U; /* 1ms x  */

const uint16_t K_LatchFindHomeReleaseDirection_Timeout = 5000U; /* 1ms x  */
const uint16_t K_LatchFindHomeCinchDirection_Timeout = 4000U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterPark_Timeout = 5000U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterBlip_Timeout = 100U; /* 1ms x  */

const uint16_t K_LatchPreReleased_Timeout = 3000U; 
const uint16_t K_LatchPreRelease_SnowLoad_Time = 3000U;
const uint16_t K_LatchCrankWait_Timeout = 2000U; /* 1ms x  */
const uint16_t K_LatchMechFailure_Timeout = 2000U;

const uint16_t K_LatchPreCinchCheck_Time = 100U; /* 1ms x  */

const uint16_t K_PowerCinching_Delay_Time = 30U; /* 1ms x  */
const uint16_t K_PowerReleasing_PawlSwitch_Delay_Time = 150U; /* 1ms x  */ 
const uint16_t K_PowerReleasing_OutofLatch_Delay_Time = 0U;//50U; /* 1ms x  */ 
const uint16_t K_PreReleased_OutofLatch_Delay_Time = 100U;//500U; /* 1ms x  */ 

const uint16_t K_StopBeforePowerReleasing_Time = 0U; /* 1ms x  */
const uint16_t K_StopBeforePreReleasing_Time = 0U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeAfterRelease_Time = 50U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeAfterPark_Time = 50U; /* 1ms x  */
const uint16_t K_MiniWorkingInCinchDirection_Time = 100U; /* 1ms x  */
const uint16_t K_ContinueFindHomeAfterRelease_Time = 100U; /* 1ms x  */
const uint16_t K_ChangeDutyInFindHomeAfterRelease_Time = 100U;/* 1ms x  */
const uint16_t K_FindHomeAfterPark_PositionSwitch_Delay_Time = 100U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeCinchDirection_Time = 100U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeReleaseDirection_Time = 100U;  /* 1ms x  */
const uint16_t K_LatchFindHomeFailure_Timeout = 1000U;  /* 1ms x  */

const uint16_t K_FindHomeReleaseDirection_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_FindHomeCinchDirection_Inrush_Time = 200U; /* 1ms x  */

const uint16_t K_PowerCinching_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_FindHomeAfterCinch_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_FindHomeAfterPark_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_PreReleasing_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_PowerReleasing_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_FindHomeAfterRelease_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_PowerReleasing_Mini_Time = 200U; /* 1ms x  */

const uint16_t K_FindHomeAfterCinch_StartDuty_Time = 50U;  /*10ms x */
const uint16_t K_FindHomeAfterCinch_DecreaseDuty_Time = 2U;   /* 10ms x  */
const uint16_t K_FindHomeAfterCinch_IncreaseDuty_Time = 1U;   /* 10ms x  */

const uint16_t K_CinchMotorFindHome_Count = 3;
const uint16_t K_PrimaryPositionIsArrived_Time= 10U;
const uint16_t K_ChangeDutyInFindHomeAfterCinch_Time = 500U; /* 1ms x  */
const uint16_t K_ChangeDutyInFindHomeAfterCinch_Time_2nd = 100U; /* 1ms x  */
const uint16_t K_ChangeDutyInPowerCinching_Time = 500U;//1200U; /* 1ms x  */
const uint16_t K_CinchMotor_PowerCinching_Duty = 100U;
const uint16_t K_CinchMotor_PowerCinching_Duty_2nd = 100U;

const uint16_t K_CinchMotor_FindHomeAfterCinch_Duty = 100U;
const uint16_t K_CinchMotor_FindHomeAfterCinch_Duty_2nd = 100U;

const uint16_t K_ContinueParking_Time = 200U;
const uint16_t K_ContinueParking_Time_2nd = 100U;

const uint16_t K_LowDutyFailFindHomeAfterCinch_Time = 8000U;/* 1ms x  */ 
const uint16_t K_LowDutyFailFindHomeAfterCinch_Duty = 60U; 
const uint16_t K_LowDutyFailPowerCinching_Time = 4000U;/* 1ms x  */ 
const uint16_t K_LowDutyFailPowerCinching_Duty = 100U;


const uint16_t K_CinchMotor_FindHomeAfterRelease_Duty = 80U;
const uint16_t K_CinchMotor_FindHomeAfterRelease_Duty_2nd = 50U;
const uint16_t K_CinchMotor_FindHomeAfterRelease_Duty_3rd = 50U;

const uint16_t K_CinchMotor_FindHomeReleaseDirection_Duty = 100U;
const uint16_t K_CinchMotor_FindHomeReleaseDirection_Duty_2nd = 50U;
const uint16_t K_CinchMotor_FindHomeCinchDirection_Duty = 100U;
const uint16_t K_CinchMotor_FindHomeCinchDirection_Duty_2nd = 50U;

const uint16_t K_CinchMotor_FindHomeAfterPark_Duty = 50U;
const uint16_t K_CinchMotor_FindHomeAfterBlip_Duty = 30U;

const uint16_t K_ReleaseMotor_PowerReleasing_Duty = 100U;
const uint16_t K_ReleaseMotor_PowerReleasing_Duty_2nd = 100U;
const uint16_t K_CinchMotor_PowerReleasing_Duty = 100U;
const uint16_t K_CinchMotor_PowerReleasing_Duty_2nd = 100U;

const uint16_t K_PowerReleasing_ComfirmCurrent = 200U;

const uint16_t K_PowerCinching_SoftStall_Current = 1000U;
const uint16_t K_FindHomeAfterCinch_SoftStall_Current = 1000U;
const uint16_t K_PreReleasing_SoftStall_Current = 1000U;
const uint16_t K_PowerReleasing_SoftStall_Current = 1000U;
const uint16_t K_FindHomeAfterRelease_SoftStall_Current = 1000U;
const uint16_t K_FindHomeReleaseDirection_SoftStall_Current = 200U;
const uint16_t K_FindHomeCinchDirection_SoftStall_Current = 200U;
const uint16_t K_FindHomeAfterPark_SoftStall_Current = 1000U;

const uint16_t K_PowerCinching_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeAfterCinch_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_PreReleasing_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_PowerReleasing_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeAfterRelease_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeReleaseDirection_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeCinchDirection_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeAfterPark_SoftStall_Time = 10U; /* 10ms x  */
 
const uint16_t K_StopBeforeFindHomeAfterCinch_Time = 100U;  /* 1ms x  */
const uint16_t K_LatchNotLeaveHomeInMiniPowerCinch_Time = 50U; /* 1ms x  */

const uint16_t K_PowerReleasing_ComfirmCurrent_Time = 5U; /* 10ms x  */
const uint16_t K_FindHomeAfterCinch_Work_MiniTime = 20U; /* 10ms x  */ 
const uint16_t K_ChangeDutyInFindHomeReleaseDirection_Time = 200U; /* 10ms x  */
const uint16_t K_ChangeDutyInFindHomeCinchDirection_Time = 200U; /* 10ms x  */

#endif

#ifdef _CONFIG_G5X_Latch
/*********************************************************************************************
**    Ingin Latch Control
*********************************************************************************************/
const uint16_t K_PowerCinchInSecondPosition_AfterPowerUp_Enable = TRUE;

const uint16_t K_LatchPreCinchCheck_Timeout = 2000U; /* 1ms x  */
const uint16_t K_LatchPowerCinching_Timeout = 6000U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterCinch_Timeout = 5000U; /* 1ms x  */
const uint16_t K_LatchPreReleasing_Timeout = 5000U; /* 1ms x  */
const uint16_t K_LatchPowerReleasing_Timeout = 4000U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterRelease_Timeout = 2000U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterRelease_Mini_Time = 100U; /* 1ms x  */

const uint16_t K_LatchFindHomeReleaseDirection_Timeout = 5000U; /* 1ms x  */
const uint16_t K_LatchFindHomeCinchDirection_Timeout = 4000U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterPark_Timeout = 5000U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterBlip_Timeout = 100U; /* 1ms x  */

const uint16_t K_LatchPreReleased_Timeout = 3000U; 
const uint16_t K_LatchPreRelease_SnowLoad_Time = 3000U;
const uint16_t K_LatchCrankWait_Timeout = 2000U; /* 1ms x  */
const uint16_t K_LatchMechFailure_Timeout = 2000U;

const uint16_t K_LatchPreCinchCheck_Time = 100U; /* 1ms x  */
const uint16_t K_PowerCinching_Delay_Time = 30U; /* 1ms x  */
const uint16_t K_PowerReleasing_PawlSwitch_Delay_Time = 150U; /* 1ms x  */ 
const uint16_t K_PowerReleasing_OutofLatch_Delay_Time = 0U;//50U; /* 1ms x  */ 
const uint16_t K_PreReleased_OutofLatch_Delay_Time = 100U;//500U; /* 1ms x  */ 

const uint16_t K_StopBeforePowerReleasing_Time = 0U; /* 1ms x  */
const uint16_t K_StopBeforePreReleasing_Time = 0U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeAfterRelease_Time = 50U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeAfterPark_Time = 50U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeAfterBlip_Time = 50U; /* 1ms x  */
const uint16_t K_MiniWorkingInCinchDirection_Time = 100U; /* 1ms x  */
const uint16_t K_ContinueFindHomeAfterRelease_Time = 200U; /* 1ms x  */
const uint16_t K_ChangeDutyInFindHomeAfterRelease_Time = 100U;/* 1ms x  */
const uint16_t K_FindHomeAfterPark_PositionSwitch_Delay_Time = 150U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeCinchDirection_Time = 100U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeReleaseDirection_Time = 100U;  /* 1ms x  */
const uint16_t K_LatchFindHomeFailure_Timeout = 1000U;  /* 1ms x  */

const uint16_t K_FindHomeReleaseDirection_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_FindHomeCinchDirection_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_PowerCinching_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_FindHomeAfterCinch_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_FindHomeAfterPark_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_PreReleasing_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_PowerReleasing_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_FindHomeAfterRelease_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_PowerReleasing_Mini_Time = 200U; /* 1ms x  */

const uint16_t K_FindHomeAfterCinch_StartDuty_Time = 50U;  /*10ms x */
const uint16_t K_FindHomeAfterCinch_DecreaseDuty_Time = 2U;   /* 10ms x  */
const uint16_t K_FindHomeAfterCinch_IncreaseDuty_Time = 1U;   /* 10ms x  */

const uint16_t K_CinchMotorFindHome_Count = 3;

const uint16_t K_CinchMotor_PowerCinching_Duty = 50U;
const uint16_t K_CinchMotor_PowerCinching_Duty_2nd = 100U;

const uint16_t K_CinchMotor_FindHomeAfterCinch_Duty = 40U;
const uint16_t K_CinchMotor_FindHomeAfterCinch_Duty_2nd = 60U;

const uint16_t K_ChangeDutyInPowerCinching_Time = 200U;//1000U; /* 1ms x  */

const uint16_t K_ContinueParking_Time = 100U;
const uint16_t K_ContinueParking_Time_2nd = 100U;

const uint16_t K_CinchMotor_FindHomeAfterRelease_Duty = 50U;
const uint16_t K_CinchMotor_FindHomeAfterRelease_Duty_2nd = 50U;
const uint16_t K_CinchMotor_FindHomeAfterRelease_Duty_3rd = 50U;

const uint16_t K_CinchMotor_FindHomeReleaseDirection_Duty = 100U;
const uint16_t K_CinchMotor_FindHomeReleaseDirection_Duty_2nd = 100U;
const uint16_t K_CinchMotor_FindHomeCinchDirection_Duty = 100U;
const uint16_t K_CinchMotor_FindHomeCinchDirection_Duty_2nd = 50U;

const uint16_t K_CinchMotor_FindHomeAfterPark_Duty = 50U;
const uint16_t K_CinchMotor_FindHomeAfterBlip_Duty = 30U;

const uint16_t K_ReleaseMotor_PowerReleasing_Duty = 100U;
const uint16_t K_ReleaseMotor_PowerReleasing_Duty_2nd = 100U;
const uint16_t K_CinchMotor_PowerReleasing_Duty = 100U;
const uint16_t K_CinchMotor_PowerReleasing_Duty_2nd = 100U;

const uint16_t K_PowerReleasing_ComfirmCurrent = 200U;

const uint16_t K_PowerCinching_SoftStall_Current = 1000U;
const uint16_t K_FindHomeAfterCinch_SoftStall_Current = 1000U;
const uint16_t K_PreReleasing_SoftStall_Current = 1000U;
const uint16_t K_PowerReleasing_SoftStall_Current = 1000U;
const uint16_t K_FindHomeAfterRelease_SoftStall_Current = 500U;
const uint16_t K_FindHomeReleaseDirection_SoftStall_Current = 200U;
const uint16_t K_FindHomeCinchDirection_SoftStall_Current = 200U;
const uint16_t K_FindHomeAfterPark_SoftStall_Current = 1000U;

const uint16_t K_PowerCinching_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeAfterCinch_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_PreReleasing_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_PowerReleasing_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeAfterRelease_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeReleaseDirection_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeCinchDirection_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeAfterPark_SoftStall_Time = 10U; /* 10ms x  */

const uint16_t K_PrimaryPositionIsArrived_Time= 5U; 
const uint16_t K_StopBeforeFindHomeAfterCinch_Time = 100U;  /* 1ms x  */
const uint16_t K_LatchNotLeaveHomeInMiniPowerCinch_Time = 50U; /* 1ms x  */
const uint16_t K_ChangeDutyInFindHomeAfterCinch_Time = 100U; /* 1ms x  */
const uint16_t K_ChangeDutyInFindHomeAfterCinch_Time_2nd = 100U; /* 1ms x  */

const uint16_t K_PowerReleasing_ComfirmCurrent_Time = 5U; /* 10ms x  */
const uint16_t K_AjarSwitchConfirm_Time = 30U; /* 10ms x  */
const uint16_t K_FindHomeAfterCinch_Work_MiniTime = 20U; /* 10ms x  */ 
const uint16_t K_ChangeDutyInFindHomeReleaseDirection_Time = 200U; /* 10ms x  */
const uint16_t K_ChangeDutyInFindHomeCinchDirection_Time = 200U; /* 10ms x  */

#endif
#ifdef _CONFIG_IntevaLatch_PowerStrike
/*********************************************************************************************
**    Inteva Latch Control
*********************************************************************************************/
const uint16_t K_PowerCinchInSecondPosition_AfterPowerUp_Enable = TRUE;

const uint16_t K_LatchPreCinchCheck_Timeout = 3000U; /* 1ms x  */
const uint16_t K_LatchPowerCinching_Timeout = 8000U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterCinch_Timeout = 15000U; /* 1ms x  */
const uint16_t K_LatchPreReleasing_Timeout = 5000U; /* 1ms x  */
const uint16_t K_LatchPowerReleasing_Timeout = 4000U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterRelease_Timeout = 2000U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterRelease_Mini_Time = 100U; /* 1ms x  */

const uint16_t K_LatchFindHomeReleaseDirection_Timeout = 5000U; /* 1ms x  */
const uint16_t K_LatchFindHomeCinchDirection_Timeout = 500U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterPark_Timeout = 5000U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterBlip_Timeout = 100U; /* 1ms x  */

const uint16_t K_LatchPreReleased_Timeout = 3000U; 
const uint16_t K_LatchPreRelease_SnowLoad_Time = 3000U;
const uint16_t K_LatchCrankWait_Timeout = 2000U; /* 1ms x  */
const uint16_t K_LatchMechFailure_Timeout = 2000U;

const uint16_t K_PreReleasing_Strike_Prework_FromHome_Time = 1000U; /* 1ms x  */ 
const uint16_t K_PreReleasing_Strike_Prework_FromMiddle_Time = 500U; /* 1ms x  */

const uint16_t K_LatchPreCinchCheck_Time = 2000U; /* 1ms x  */

const uint16_t K_PowerCinching_Delay_Time = 0U; /* 1ms x  */
const uint16_t K_PowerReleasing_PawlSwitch_Delay_Time = 300U; /* 1ms x  */ 
const uint16_t K_PowerReleasing_OutofLatch_Delay_Time = 0U;//50U; /* 1ms x  */ 
const uint16_t K_PreReleased_OutofLatch_Delay_Time = 100U;//500U; /* 1ms x  */ 

const uint16_t K_StopBeforePowerReleasing_Time = 0U; /* 1ms x  */
const uint16_t K_StopBeforePreReleasing_Time = 0U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeAfterRelease_Time = 50U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeAfterPark_Time = 50U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeAfterBlip_Time = 50U; /* 1ms x  */
const uint16_t K_MiniWorkingInCinchDirection_Time = 100U; /* 1ms x  */
const uint16_t K_ContinueFindHomeAfterRelease_Time = 100U; /* 1ms x  */
const uint16_t K_ChangeDutyInFindHomeAfterRelease_Time = 100U;/* 1ms x  */
const uint16_t K_FindHomeAfterPark_PositionSwitch_Delay_Time = 100U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeCinchDirection_Time = 100U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeReleaseDirection_Time = 100U;  /* 1ms x  */
const uint16_t K_LatchFindHomeFailure_Timeout = 1000U;  /* 1ms x  */

const uint16_t K_FindHomeReleaseDirection_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_FindHomeCinchDirection_Inrush_Time = 200U; /* 1ms x  */

const uint16_t K_PowerCinching_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_FindHomeAfterCinch_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_FindHomeAfterPark_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_PreReleasing_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_PowerReleasing_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_FindHomeAfterRelease_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_PowerReleasing_Mini_Time = 300U; /* 1ms x  */

const uint16_t K_FindHomeAfterCinch_StartDuty_Time = 50U;  /*10ms x */
const uint16_t K_FindHomeAfterCinch_DecreaseDuty_Time = 2U;   /* 10ms x  */
const uint16_t K_FindHomeAfterCinch_IncreaseDuty_Time = 1U;   /* 10ms x  */

const uint16_t K_CinchMotorFindHome_Count = 3;

const uint16_t K_PrimaryPositionIsArrived_Time= 10U;
const uint16_t K_ChangeDutyInFindHomeAfterCinch_Time = 500U; /* 1ms x  */
const uint16_t K_ChangeDutyInFindHomeAfterCinch_Time_2nd = 100U; /* 1ms x  */
const uint16_t K_ChangeDutyInPowerCinching_Time = 500U;//1200U; /* 1ms x  */
const uint16_t K_CinchMotor_PowerCinching_Duty = 100U;
const uint16_t K_CinchMotor_PowerCinching_Duty_2nd = 100U;
const uint16_t K_CinchMotor_FindHomeAfterCinch_Duty = 70U;
const uint16_t K_CinchMotor_FindHomeAfterCinch_Duty_2nd = 70U;

const uint16_t K_ContinueParking_Time = 200U;
const uint16_t K_ContinueParking_Time_2nd = 100U;

const uint16_t K_LowDutyFailFindHomeAfterCinch_Time = 8000U;/* 1ms x  */ 
const uint16_t K_LowDutyFailFindHomeAfterCinch_Duty = 60U; 
const uint16_t K_LowDutyFailPowerCinching_Time = 4000U;/* 1ms x  */ 
const uint16_t K_LowDutyFailPowerCinching_Duty = 100U;

const uint16_t K_CinchMotor_FindHomeAfterRelease_Duty = 80U;
const uint16_t K_CinchMotor_FindHomeAfterRelease_Duty_2nd = 80U;
const uint16_t K_CinchMotor_FindHomeAfterRelease_Duty_3rd = 80U;

const uint16_t K_CinchMotor_FindHomeReleaseDirection_Duty = 100U;
const uint16_t K_CinchMotor_FindHomeReleaseDirection_Duty_2nd = 100U;
const uint16_t K_CinchMotor_FindHomeCinchDirection_Duty = 100U;
const uint16_t K_CinchMotor_FindHomeCinchDirection_Duty_2nd = 50U;

const uint16_t K_CinchMotor_FindHomeAfterPark_Duty = 50U;
const uint16_t K_CinchMotor_FindHomeAfterBlip_Duty = 30U;

const uint16_t K_ReleaseMotor_PowerReleasing_Duty = 100U;
const uint16_t K_ReleaseMotor_PowerReleasing_Duty_2nd = 100U;
const uint16_t K_CinchMotor_PowerReleasing_Duty = 100U;
const uint16_t K_CinchMotor_PowerReleasing_Duty_2nd = 100U;

const uint16_t K_PowerReleasing_ComfirmCurrent = 200U;

const uint16_t K_PowerCinching_SoftStall_Current = 1000U;
const uint16_t K_FindHomeAfterCinch_SoftStall_Current = 1000U;
const uint16_t K_PreReleasing_SoftStall_Current = 1000U;
const uint16_t K_PowerReleasing_SoftStall_Current = 1000U;
const uint16_t K_FindHomeAfterRelease_SoftStall_Current = 500U;
const uint16_t K_FindHomeReleaseDirection_SoftStall_Current = 200U;
const uint16_t K_FindHomeCinchDirection_SoftStall_Current = 200U;
const uint16_t K_FindHomeAfterPark_SoftStall_Current = 1000U;


const uint16_t K_PowerCinching_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeAfterCinch_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_PreReleasing_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_PowerReleasing_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeAfterRelease_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeReleaseDirection_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeCinchDirection_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeAfterPark_SoftStall_Time = 10U; /* 10ms x  */
 
const uint16_t K_StopBeforeFindHomeAfterCinch_Time = 100U;  /* 1ms x  */
const uint16_t K_LatchNotLeaveHomeInMiniPowerCinch_Time = 50U; /* 1ms x  */

const uint16_t K_PowerReleasing_ComfirmCurrent_Time = 5U; /* 10ms x  */
const uint16_t K_FindHomeAfterCinch_Work_MiniTime = 20U; /* 10ms x  */ 
const uint16_t K_ChangeDutyInFindHomeReleaseDirection_Time = 200U; /* 10ms x  */
const uint16_t K_ChangeDutyInFindHomeCinchDirection_Time = 200U; /* 10ms x  */

#endif
#ifdef _CONFIG_PSA4008_Latch
/*********************************************************************************************
**    Ingin Latch Control
*********************************************************************************************/
const uint16_t K_PowerCinchInSecondPosition_AfterPowerUp_Enable = TRUE;

const uint16_t K_LatchPreCinchCheck_Timeout = 2000U; /* 1ms x  */
const uint16_t K_LatchPowerCinching_Timeout = 3000U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterCinch_Timeout = 600U; /* 1ms x  */
const uint16_t K_LatchPreReleasing_Timeout = 4000U; /* 1ms x  */
const uint16_t K_LatchPowerReleasing_Timeout = 4000U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterRelease_Timeout = 2000U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterRelease_Mini_Time = 100U; /* 1ms x  */

const uint16_t K_LatchFindHomeReleaseDirection_Timeout = 5000U; /* 1ms x  */
const uint16_t K_LatchFindHomeCinchDirection_Timeout = 4000U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterPark_Timeout = 5000U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterBlip_Timeout = 100U; /* 1ms x  */

const uint16_t K_LatchPreReleased_Timeout = 3000U; 
const uint16_t K_LatchPreRelease_SnowLoad_Time = 3000U;
const uint16_t K_LatchCrankWait_Timeout = 2000U; /* 1ms x  */
const uint16_t K_LatchMechFailure_Timeout = 2000U;

const uint16_t K_LatchPreCinchCheck_Time = 100U; /* 1ms x  */
const uint16_t K_PowerCinching_Delay_Time = 30U; /* 1ms x  */
const uint16_t K_PowerReleasing_PawlSwitch_Delay_Time = 150U; /* 1ms x  */ 
const uint16_t K_PowerReleasing_OutofLatch_Delay_Time = 0U;//50U; /* 1ms x  */ 
const uint16_t K_PreReleased_OutofLatch_Delay_Time = 100U;//500U; /* 1ms x  */ 

const uint16_t K_StopBeforePowerReleasing_Time = 0U; /* 1ms x  */
const uint16_t K_StopBeforePreReleasing_Time = 0U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeAfterRelease_Time = 50U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeAfterPark_Time = 50U; /* 1ms x  */
const uint16_t K_MiniWorkingInCinchDirection_Time = 100U; /* 1ms x  */
const uint16_t K_ContinueFindHomeAfterRelease_Time = 100U; /* 1ms x  */
const uint16_t K_ChangeDutyInFindHomeAfterRelease_Time = 100U;/* 1ms x  */
const uint16_t K_FindHomeAfterPark_PositionSwitch_Delay_Time = 100U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeCinchDirection_Time = 100U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeReleaseDirection_Time = 100U;  /* 1ms x  */
const uint16_t K_LatchFindHomeFailure_Timeout = 1000U;  /* 1ms x  */

const uint16_t K_FindHomeReleaseDirection_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_FindHomeCinchDirection_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_PowerCinching_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_FindHomeAfterCinch_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_FindHomeAfterPark_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_PreReleasing_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_PowerReleasing_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_FindHomeAfterRelease_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_PowerReleasing_Mini_Time = 200U; /* 1ms x  */

const uint16_t K_FindHomeAfterCinch_StartDuty_Time = 50U;  /*10ms x */
const uint16_t K_FindHomeAfterCinch_DecreaseDuty_Time = 2U;   /* 10ms x  */
const uint16_t K_FindHomeAfterCinch_IncreaseDuty_Time = 1U;   /* 10ms x  */

const uint16_t K_CinchMotorFindHome_Count = 3;

const uint16_t K_ChangeDutyInFindHomeAfterCinch_Time = 500U; /* 1ms x  */
const uint16_t K_ChangeDutyInFindHomeAfterCinch_Time_2nd = 100U; /* 1ms x  */
const uint16_t K_ChangeDutyInPowerCinching_Time = 1200U; /* 1ms x  */
const uint16_t K_CinchMotor_PowerCinching_Duty = 90U;
const uint16_t K_CinchMotor_PowerCinching_Duty_2nd = 100U;

const uint16_t K_CinchMotor_FindHomeAfterCinch_Duty = 5U;
const uint16_t K_CinchMotor_FindHomeAfterCinch_Duty_2nd = 5U;

const uint16_t K_LowDutyFailFindHomeAfterCinch_Time = 8000U;/* 1ms x  */ 
const uint16_t K_LowDutyFailFindHomeAfterCinch_Duty = 60U; 
const uint16_t K_LowDutyFailPowerCinching_Duty = 100U;

const uint16_t K_ContinueParking_Time = 100U;
const uint16_t K_ContinueParking_Time_2nd = 100U;

const uint16_t K_CinchMotor_FindHomeAfterRelease_Duty = 80U;
const uint16_t K_CinchMotor_FindHomeAfterRelease_Duty_2nd = 50U;
const uint16_t K_CinchMotor_FindHomeAfterRelease_Duty_3rd = 50U;

const uint16_t K_CinchMotor_FindHomeReleaseDirection_Duty = 100U;
const uint16_t K_CinchMotor_FindHomeReleaseDirection_Duty_2nd = 50U;
const uint16_t K_CinchMotor_FindHomeCinchDirection_Duty = 100U;
const uint16_t K_CinchMotor_FindHomeCinchDirection_Duty_2nd = 50U;

const uint16_t K_CinchMotor_FindHomeAfterPark_Duty = 50U;
const uint16_t K_CinchMotor_FindHomeAfterBlip_Duty = 30U;

const uint16_t K_ReleaseMotor_PowerReleasing_Duty = 100U;
const uint16_t K_ReleaseMotor_PowerReleasing_Duty_2nd = 100U;
const uint16_t K_CinchMotor_PowerReleasing_Duty = 50U;
const uint16_t K_CinchMotor_PowerReleasing_Duty_2nd = 100U;

const uint16_t K_PowerReleasing_ComfirmCurrent = 200U;

const uint16_t K_PowerCinching_SoftStall_Current = 1000U;
const uint16_t K_FindHomeAfterCinch_SoftStall_Current = 200U;
const uint16_t K_PreReleasing_SoftStall_Current = 200U;
const uint16_t K_PowerReleasing_SoftStall_Current = 1000U;
const uint16_t K_FindHomeAfterRelease_SoftStall_Current = 1000U;
const uint16_t K_FindHomeReleaseDirection_SoftStall_Current = 200U;
const uint16_t K_FindHomeCinchDirection_SoftStall_Current = 200U;
const uint16_t K_FindHomeAfterPark_SoftStall_Current = 1000U;


const uint16_t K_PowerCinching_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeAfterCinch_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_PreReleasing_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_PowerReleasing_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeAfterRelease_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeReleaseDirection_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeCinchDirection_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeAfterPark_SoftStall_Time = 10U; /* 10ms x  */

const uint16_t K_PrimaryPositionIsArrived_Time= 10U; 
const uint16_t K_StopBeforeFindHomeAfterCinch_Time = 10U;  /* 1ms x  */
const uint16_t K_LatchNotLeaveHomeInMiniPowerCinch_Time = 50U; /* 1ms x  */

const uint16_t K_PowerReleasing_ComfirmCurrent_Time = 5U; /* 10ms x  */
const uint16_t K_FindHomeAfterCinch_Work_MiniTime = 20U; /* 10ms x  */ 
const uint16_t K_ChangeDutyInFindHomeReleaseDirection_Time = 200U; /* 10ms x  */
const uint16_t K_ChangeDutyInFindHomeCinchDirection_Time = 200U; /* 10ms x  */

#endif

#ifdef _CONFIG_KiekertSideLatch
/*********************************************************************************************
**    Ingin Latch Control
*********************************************************************************************/
const uint16_t K_PowerCinchInSecondPosition_AfterPowerUp_Enable = TRUE;

const uint16_t K_LatchPreCinchCheck_Timeout = 2000U; /* 1ms x  */
const uint16_t K_LatchPowerCinching_Timeout = 8000U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterCinch_Timeout = 15000U; /* 1ms x  */
const uint16_t K_LatchPreReleasing_Timeout = 5000U; /* 1ms x  */
const uint16_t K_LatchPowerReleasing_Timeout = 500U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterRelease_Timeout = 300U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterRelease_Mini_Time = 100U; /* 1ms x  */

const uint16_t K_LatchFindHomeReleaseDirection_Timeout = 5000U; /* 1ms x  */
const uint16_t K_LatchFindHomeCinchDirection_Timeout = 4000U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterPark_Timeout = 5000U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterBlip_Timeout = 100U; /* 1ms x  */

const uint16_t K_LatchPreReleased_Timeout = 3000U; 
const uint16_t K_LatchPreRelease_SnowLoad_Time = 3000U;
const uint16_t K_LatchCrankWait_Timeout = 2000U; /* 1ms x  */
const uint16_t K_LatchMechFailure_Timeout = 2000U;

const uint16_t K_LatchPreCinchCheck_Time = 100U; /* 1ms x  */

const uint16_t K_PowerCinching_Delay_Time = 30U; /* 1ms x  */
const uint16_t K_PowerReleasing_PawlSwitch_Delay_Time = 150U; /* 1ms x  */ 
const uint16_t K_PowerReleasing_OutofLatch_Delay_Time = 50U;//50U; /* 1ms x  */ 
const uint16_t K_PreReleased_OutofLatch_Delay_Time = 100U;//500U; /* 1ms x  */ 

const uint16_t K_StopBeforePowerReleasing_Time = 0U; /* 1ms x  */
const uint16_t K_StopBeforePreReleasing_Time = 0U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeAfterRelease_Time = 50U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeAfterPark_Time = 50U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeAfterBlip_Time = 50U; /* 1ms x  */
const uint16_t K_MiniWorkingInCinchDirection_Time = 100U; /* 1ms x  */
const uint16_t K_ContinueFindHomeAfterRelease_Time = 100U; /* 1ms x  */
const uint16_t K_ChangeDutyInFindHomeAfterRelease_Time = 100U;/* 1ms x  */
const uint16_t K_FindHomeAfterPark_PositionSwitch_Delay_Time = 100U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeCinchDirection_Time = 100U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeReleaseDirection_Time = 100U;  /* 1ms x  */
const uint16_t K_LatchFindHomeFailure_Timeout = 1000U;  /* 1ms x  */

const uint16_t K_FindHomeReleaseDirection_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_FindHomeCinchDirection_Inrush_Time = 200U; /* 1ms x  */

const uint16_t K_PowerCinching_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_FindHomeAfterCinch_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_FindHomeAfterPark_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_PreReleasing_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_PowerReleasing_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_FindHomeAfterRelease_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_PowerReleasing_Mini_Time = 300U; /* 1ms x  */

const uint16_t K_FindHomeAfterCinch_StartDuty_Time = 50U;  /*10ms x */
const uint16_t K_FindHomeAfterCinch_DecreaseDuty_Time = 2U;   /* 10ms x  */
const uint16_t K_FindHomeAfterCinch_IncreaseDuty_Time = 1U;   /* 10ms x  */

const uint16_t K_CinchMotorFindHome_Count = 3;

const uint16_t K_ChangeDutyInFindHomeAfterCinch_Time = 500U; /* 1ms x  */
const uint16_t K_ChangeDutyInFindHomeAfterCinch_Time_2nd = 100U; /* 1ms x  */
const uint16_t K_ChangeDutyInPowerCinching_Time = 500U;//1200U; /* 1ms x  */
const uint16_t K_ChangeDutyInPowerCinching_Time_2nd = 500U; /* 1ms x  */
const uint16_t K_CinchMotor_PowerCinching_Duty = 90U;
const uint16_t K_CinchMotor_PowerCinching_Duty_2nd = 100U;

const uint16_t K_CinchMotor_FindHomeAfterCinch_Duty = 80U;
const uint16_t K_CinchMotor_FindHomeAfterCinch_Duty_2nd = 60U;

const uint16_t K_LowDutyFailFindHomeAfterCinch_Time = 8000U;/* 1ms x  */ 
const uint16_t K_LowDutyFailFindHomeAfterCinch_Duty = 60U; 
const uint16_t K_LowDutyFailPowerCinching_Time = 4000U;/* 1ms x  */ 
const uint16_t K_LowDutyFailPowerCinching_Duty = 100U;

const uint16_t K_ContinueParking_Time = 100U;
const uint16_t K_ContinueParking_Time_2nd = 100U;

const uint16_t K_CinchMotor_FindHomeAfterRelease_Duty = 80U;
const uint16_t K_CinchMotor_FindHomeAfterRelease_Duty_2nd = 50U;
const uint16_t K_CinchMotor_FindHomeAfterRelease_Duty_3rd = 50U;

const uint16_t K_CinchMotor_FindHomeReleaseDirection_Duty = 100U;
const uint16_t K_CinchMotor_FindHomeReleaseDirection_Duty_2nd = 50U;
const uint16_t K_CinchMotor_FindHomeCinchDirection_Duty = 100U;
const uint16_t K_CinchMotor_FindHomeCinchDirection_Duty_2nd = 50U;

const uint16_t K_CinchMotor_FindHomeAfterPark_Duty = 50U;
const uint16_t K_CinchMotor_FindHomeAfterBlip_Duty = 30U;

const uint16_t K_ReleaseMotor_PowerReleasing_Duty = 100U;
const uint16_t K_ReleaseMotor_PowerReleasing_Duty_2nd = 100U;
const uint16_t K_CinchMotor_PowerReleasing_Duty = 100U;
const uint16_t K_CinchMotor_PowerReleasing_Duty_2nd = 100U;

const uint16_t K_PowerReleasing_ComfirmCurrent = 200U;

const uint16_t K_PowerCinching_SoftStall_Current = 1000U;
const uint16_t K_FindHomeAfterCinch_SoftStall_Current = 1000U;
const uint16_t K_PreReleasing_SoftStall_Current = 1000U;
const uint16_t K_PowerReleasing_SoftStall_Current = 1000U;
const uint16_t K_FindHomeAfterRelease_SoftStall_Current = 500U;
const uint16_t K_FindHomeReleaseDirection_SoftStall_Current = 200U;
const uint16_t K_FindHomeCinchDirection_SoftStall_Current = 200U;
const uint16_t K_FindHomeAfterPark_SoftStall_Current = 1000U;

const uint16_t K_PowerCinching_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeAfterCinch_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_PreReleasing_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_PowerReleasing_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeAfterRelease_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeReleaseDirection_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeCinchDirection_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeAfterPark_SoftStall_Time = 10U; /* 10ms x  */

const uint16_t K_PrimaryPositionIsArrived_Time= 10U; 
const uint16_t K_StopBeforeFindHomeAfterCinch_Time = 100U;  /* 1ms x  */
const uint16_t K_LatchNotLeaveHomeInMiniPowerCinch_Time = 50U; /* 1ms x  */

const uint16_t K_PowerReleasing_ComfirmCurrent_Time = 5U; /* 10ms x  */
const uint16_t K_FindHomeAfterCinch_Work_MiniTime = 20U; /* 10ms x  */ 
const uint16_t K_ChangeDutyInFindHomeReleaseDirection_Time = 200U; /* 10ms x  */
const uint16_t K_ChangeDutyInFindHomeCinchDirection_Time = 200U; /* 10ms x  */

#endif

#ifdef _CONFIG_BranoLatch
/*********************************************************************************************
**    Ingin Latch Control
*********************************************************************************************/
const uint16_t K_PowerCinchInSecondPosition_AfterPowerUp_Enable = TRUE;

const uint16_t K_LatchPreCinchCheck_Timeout = 2000U; /* 1ms x  */
const uint16_t K_LatchPowerCinching_Timeout = 8000U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterCinch_Timeout = 15000U; /* 1ms x  */
const uint16_t K_LatchPreReleasing_Timeout = 5000U; /* 1ms x  */
const uint16_t K_LatchPowerReleasing_Timeout = 800U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterRelease_Timeout = 300U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterRelease_Mini_Time = 100U; /* 1ms x  */

const uint16_t K_LatchFindHomeReleaseDirection_Timeout = 5000U; /* 1ms x  */
const uint16_t K_LatchFindHomeCinchDirection_Timeout = 4000U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterPark_Timeout = 5000U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterBlip_Timeout = 100U; /* 1ms x  */

const uint16_t K_LatchPreReleased_Timeout = 3000U; 
const uint16_t K_LatchPreRelease_SnowLoad_Time = 3000U;
const uint16_t K_LatchCrankWait_Timeout = 2000U; /* 1ms x  */
const uint16_t K_LatchMechFailure_Timeout = 2000U;


const uint16_t K_LatchPreCinchCheck_Time = 100U; /* 1ms x  */

const uint16_t K_PowerCinching_Delay_Time = 30U; /* 1ms x  */
const uint16_t K_PowerReleasing_PawlSwitch_Delay_Time = 150U; /* 1ms x  */ 
const uint16_t K_PowerReleasing_OutofLatch_Delay_Time = 50U;//50U; /* 1ms x  */ 
const uint16_t K_PreReleased_OutofLatch_Delay_Time = 100U;//500U; /* 1ms x  */ 

const uint16_t K_StopBeforePowerReleasing_Time = 0U; /* 1ms x  */
const uint16_t K_StopBeforePreReleasing_Time = 0U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeAfterRelease_Time = 50U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeAfterPark_Time = 50U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeAfterBlip_Time = 50U; /* 1ms x  */
const uint16_t K_MiniWorkingInCinchDirection_Time = 100U; /* 1ms x  */
const uint16_t K_ContinueFindHomeAfterRelease_Time = 100U; /* 1ms x  */
const uint16_t K_ChangeDutyInFindHomeAfterRelease_Time = 100U;/* 1ms x  */
const uint16_t K_FindHomeAfterPark_PositionSwitch_Delay_Time = 100U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeCinchDirection_Time = 100U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeReleaseDirection_Time = 100U;  /* 1ms x  */
const uint16_t K_LatchFindHomeFailure_Timeout = 1000U;  /* 1ms x  */

const uint16_t K_FindHomeReleaseDirection_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_FindHomeCinchDirection_Inrush_Time = 200U; /* 1ms x  */

const uint16_t K_PowerCinching_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_FindHomeAfterCinch_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_FindHomeAfterPark_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_PreReleasing_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_PowerReleasing_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_FindHomeAfterRelease_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_PowerReleasing_Mini_Time = 300U; /* 1ms x  */

const uint16_t K_FindHomeAfterCinch_StartDuty_Time = 50U;  /*10ms x */
const uint16_t K_FindHomeAfterCinch_DecreaseDuty_Time = 2U;   /* 10ms x  */
const uint16_t K_FindHomeAfterCinch_IncreaseDuty_Time = 1U;   /* 10ms x  */

const uint16_t K_CinchMotorFindHome_Count = 3;

const uint16_t K_ChangeDutyInFindHomeAfterCinch_Time = 500U; /* 1ms x  */
const uint16_t K_ChangeDutyInFindHomeAfterCinch_Time_2nd = 100U; /* 1ms x  */
const uint16_t K_ChangeDutyInPowerCinching_Time = 500U;//1200U; /* 1ms x  */
const uint16_t K_ChangeDutyInPowerCinching_Time_2nd = 500U; /* 1ms x  */

const uint16_t K_CinchMotor_PowerCinching_Duty = 100U;
const uint16_t K_CinchMotor_PowerCinching_Duty_2nd = 100U;

const uint16_t K_CinchMotor_FindHomeAfterCinch_Duty = 100U;
const uint16_t K_CinchMotor_FindHomeAfterCinch_Duty_2nd = 100U;

const uint16_t K_LowDutyFailFindHomeAfterCinch_Time = 8000U;/* 1ms x  */ 
const uint16_t K_LowDutyFailFindHomeAfterCinch_Duty = 60U; 
const uint16_t K_LowDutyFailPowerCinching_Time = 4000U;/* 1ms x  */ 
const uint16_t K_LowDutyFailPowerCinching_Duty = 100U;

const uint16_t K_ContinueParking_Time = 100U;
const uint16_t K_ContinueParking_Time_2nd = 100U;

const uint16_t K_CinchMotor_FindHomeAfterRelease_Duty = 80U;
const uint16_t K_CinchMotor_FindHomeAfterRelease_Duty_2nd = 50U;
const uint16_t K_CinchMotor_FindHomeAfterRelease_Duty_3rd = 50U;

const uint16_t K_CinchMotor_FindHomeReleaseDirection_Duty = 100U;
const uint16_t K_CinchMotor_FindHomeReleaseDirection_Duty_2nd = 50U;
const uint16_t K_CinchMotor_FindHomeCinchDirection_Duty = 100U;
const uint16_t K_CinchMotor_FindHomeCinchDirection_Duty_2nd = 50U;

const uint16_t K_CinchMotor_FindHomeAfterPark_Duty = 50U;
const uint16_t K_CinchMotor_FindHomeAfterBlip_Duty = 30U;

const uint16_t K_ReleaseMotor_PowerReleasing_Duty = 100U;
const uint16_t K_ReleaseMotor_PowerReleasing_Duty_2nd = 100U;
const uint16_t K_CinchMotor_PowerReleasing_Duty = 100U;
const uint16_t K_CinchMotor_PowerReleasing_Duty_2nd = 100U;

const uint16_t K_PowerReleasing_ComfirmCurrent = 200U;

const uint16_t K_PowerCinching_SoftStall_Current = 1000U;
const uint16_t K_FindHomeAfterCinch_SoftStall_Current = 1000U;
const uint16_t K_PreReleasing_SoftStall_Current = 1000U;
const uint16_t K_PowerReleasing_SoftStall_Current = 1000U;
const uint16_t K_FindHomeAfterRelease_SoftStall_Current = 500U;
const uint16_t K_FindHomeReleaseDirection_SoftStall_Current = 200U;
const uint16_t K_FindHomeCinchDirection_SoftStall_Current = 200U;
const uint16_t K_FindHomeAfterPark_SoftStall_Current = 1000U;


const uint16_t K_PowerCinching_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeAfterCinch_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_PreReleasing_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_PowerReleasing_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeAfterRelease_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeReleaseDirection_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeCinchDirection_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeAfterPark_SoftStall_Time = 10U; /* 10ms x  */

const uint16_t K_PrimaryPositionIsArrived_Time= 10U; 
const uint16_t K_StopBeforeFindHomeAfterCinch_Time = 100U;  /* 1ms x  */
const uint16_t K_LatchNotLeaveHomeInMiniPowerCinch_Time = 50U; /* 1ms x  */

const uint16_t K_PowerReleasing_ComfirmCurrent_Time = 5U; /* 10ms x  */
const uint16_t K_FindHomeAfterCinch_Work_MiniTime = 20U; /* 10ms x  */ 
const uint16_t K_ChangeDutyInFindHomeReleaseDirection_Time = 200U; /* 10ms x  */
const uint16_t K_ChangeDutyInFindHomeCinchDirection_Time = 200U; /* 10ms x  */

#endif


#ifdef _CONFIG_MagnaLatch_TwoSwitch
/*********************************************************************************************
**    Ingin Latch Control
*********************************************************************************************/
const uint16_t K_PowerCinchInSecondPosition_AfterPowerUp_Enable = TRUE;

const uint16_t K_LatchPreCinchCheck_Timeout = 2000U; /* 1ms x  */
const uint16_t K_LatchPowerCinching_Timeout = 6000U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterCinch_Timeout = 8000U; /* 1ms x  */
const uint16_t K_LatchPreReleasing_Timeout = 5000U; /* 1ms x  */
const uint16_t K_LatchPowerReleasing_Timeout = 2000U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterRelease_Timeout = 270U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterRelease_Mini_Time = 100U; /* 1ms x  */

const uint16_t K_LatchFindHomeReleaseDirection_Timeout = 5000U; /* 1ms x  */
const uint16_t K_LatchFindHomeCinchDirection_Timeout = 150U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterPark_Timeout = 150U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterBlip_Timeout = 800U;//300U; /* 1ms x  */

const uint16_t K_LatchPreReleased_Timeout = 3000U; 
const uint16_t K_LatchPreRelease_SnowLoad_Time = 3000U;
const uint16_t K_LatchCrankWait_Timeout = 2000U; /* 1ms x  */
const uint16_t K_LatchMechFailure_Timeout = 2000U;

const uint16_t K_LatchPreCinchCheck_Time = 100U; /* 1ms x  */

const uint16_t K_PowerCinching_Delay_Time = 100U; /* 1ms x  */
const uint16_t K_PowerReleasing_PawlSwitch_Delay_Time = 100U; /* 1ms x  */ 
const uint16_t K_PowerReleasing_OutofLatch_Delay_Time = 30U;//50U; /* 1ms x  */ 
const uint16_t K_PreReleased_OutofLatch_Delay_Time = 100U;//500U; /* 1ms x  */ 

const uint16_t K_StopBeforePowerReleasing_Time = 0U; /* 1ms x  */
const uint16_t K_StopBeforePreReleasing_Time = 0U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeAfterRelease_Time = 150U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeAfterPark_Time = 50U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeAfterBlip_Time = 100U; /* 1ms x  */
const uint16_t K_MiniWorkingInCinchDirection_Time = 50U; /* 1ms x  */
const uint16_t K_ContinueFindHomeAfterRelease_Time = 100U; /* 1ms x  */
const uint16_t K_ChangeDutyInFindHomeAfterRelease_Time = 100U;/* 1ms x  */
const uint16_t K_FindHomeAfterPark_PositionSwitch_Delay_Time = 100U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeCinchDirection_Time = 100U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeReleaseDirection_Time = 100U;  /* 1ms x  */
const uint16_t K_LatchFindHomeFailure_Timeout = 1000U;  /* 1ms x  */

const uint16_t K_FindHomeReleaseDirection_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_FindHomeCinchDirection_Inrush_Time = 200U; /* 1ms x  */

const uint16_t K_PowerCinching_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_FindHomeAfterCinch_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_FindHomeAfterPark_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_PreReleasing_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_PowerReleasing_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_FindHomeAfterRelease_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_PowerReleasing_Mini_Time = 200U; /* 1ms x  */

const uint16_t K_FindHomeAfterCinch_StartDuty_Time = 50U;  /*10ms x */
const uint16_t K_FindHomeAfterCinch_DecreaseDuty_Time = 2U;   /* 10ms x  */
const uint16_t K_FindHomeAfterCinch_IncreaseDuty_Time = 1U;   /* 10ms x  */

const uint16_t K_CinchMotorFindHome_Count = 3;

const uint16_t K_PrimaryPositionIsArrived_Time= 2U;
const uint16_t K_ChangeDutyInFindHomeAfterCinch_Time = 120U; /* 1ms x  */
const uint16_t K_ChangeDutyInFindHomeAfterCinch_Time_2nd = 100U; /* 1ms x  */
const uint16_t K_ChangeDutyInPowerCinching_Time = 3000U; /* 1ms x  */
const uint16_t K_CinchMotor_PowerCinching_Duty = 80U;
const uint16_t K_CinchMotor_PowerCinching_Duty_2nd = 80U;

const uint16_t K_CinchMotor_FindHomeAfterCinch_Duty = 21U;
const uint16_t K_CinchMotor_FindHomeAfterCinch_Duty_2nd = 60U;

const uint16_t K_ContinueParking_Time = 100U;
const uint16_t K_ContinueParking_Time_2nd = 100U;

const uint16_t K_LowDutyFailFindHomeAfterCinch_Time = 8000U;/* 1ms x  */ 
const uint16_t K_LowDutyFailFindHomeAfterCinch_Duty = 20U; 
const uint16_t K_LowDutyFailPowerCinching_Time = 2000U;/* 1ms x  */ 
const uint16_t K_LowDutyFailPowerCinching_Duty = 100U;

const uint16_t K_CinchMotor_FindHomeAfterRelease_Duty = 90U;
const uint16_t K_CinchMotor_FindHomeAfterRelease_Duty_2nd = 90U;
const uint16_t K_CinchMotor_FindHomeAfterRelease_Duty_3rd = 80U;

const uint16_t K_CinchMotor_FindHomeReleaseDirection_Duty = 21U;
const uint16_t K_CinchMotor_FindHomeReleaseDirection_Duty_2nd = 21U;
const uint16_t K_CinchMotor_FindHomeCinchDirection_Duty = 50U;
const uint16_t K_CinchMotor_FindHomeCinchDirection_Duty_2nd = 50U;

const uint16_t K_CinchMotor_FindHomeAfterPark_Duty = 50U;
const uint16_t K_CinchMotor_FindHomeAfterBlip_Duty = 21U;

const uint16_t K_ReleaseMotor_PowerReleasing_Duty = 100U;
const uint16_t K_ReleaseMotor_PowerReleasing_Duty_2nd = 100U;
const uint16_t K_CinchMotor_PowerReleasing_Duty = 100U;
const uint16_t K_CinchMotor_PowerReleasing_Duty_2nd = 100U;

const uint16_t K_PowerReleasing_ComfirmCurrent = 300U;

const uint16_t K_PowerCinching_SoftStall_Current = 1500U;
const uint16_t K_FindHomeAfterCinch_SoftStall_Current = 1500U;
const uint16_t K_PreReleasing_SoftStall_Current = 1500U;
const uint16_t K_PowerReleasing_SoftStall_Current = 1500U;
const uint16_t K_FindHomeAfterRelease_SoftStall_Current = 1500U;
const uint16_t K_FindHomeReleaseDirection_SoftStall_Current = 200U;
const uint16_t K_FindHomeCinchDirection_SoftStall_Current = 200U;
const uint16_t K_FindHomeAfterPark_SoftStall_Current = 1500U;


const uint16_t K_PowerCinching_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeAfterCinch_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_PreReleasing_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_PowerReleasing_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeAfterRelease_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeReleaseDirection_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeCinchDirection_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeAfterPark_SoftStall_Time = 10U; /* 10ms x  */
 
const uint16_t K_StopBeforeFindHomeAfterCinch_Time = 100U;  /* 1ms x  */
const uint16_t K_LatchNotLeaveHomeInMiniPowerCinch_Time = 50U; /* 1ms x  */

const uint16_t K_PowerReleasing_ComfirmCurrent_Time = 5U; /* 10ms x  */
const uint16_t K_FindHomeAfterCinch_Work_MiniTime = 20U; /* 10ms x  */ 
const uint16_t K_ChangeDutyInFindHomeReleaseDirection_Time = 100U; /* 10ms x  */
const uint16_t K_ChangeDutyInFindHomeCinchDirection_Time = 200U; /* 10ms x  */

const uint16_t K_CinchMotor_EnhancedCurrent_Detect[8][8] = 
{
	/* 9v10v11v12v13v14v15v16v  */
        {18,18,18,18,18,18,18,18},  /*-40degree*/
	{17,17,17,17,17,17,17,17},  /*-25degree*/
	{16,16,16,16,16,16,16,16},  /*-10degree*/
	{15,15,15,15,15,15,15,15},  /*+05degree*/
	{15,15,15,15,15,15,15,15},  /*+20degree*/
	{15,15,15,15,15,15,15,15},  /*+35degree*/
	{15,15,15,15,15,15,15,15},  /*+50degree*/
	{15,15,15,15,15,15,15,15}   /*+65degree*/
	
};
const uint16_t K_CinchMotor_EnhancedCurrent_DecreasePerTimer = 1U;    /*10ms x */
const uint16_t K_CinchMotor_EnhancedCurrent_Decrease_Time = 2U;       /*10ms x */
const uint16_t K_CinchMotor_EnhancedCurrent_IncreasePerTimer = 5U;  /*10ms x */
const uint16_t K_CinchMotor_EnhancedCurrent_Increase_Time = 30U;      /*10ms x */
const uint16_t K_CinchMotor_EnhancedCurrent_Threshold_Time = 2U;     /*10ms x */ 


const uint16_t K_LargeSpringPosition_FixedCurrent_Level_1_Cal[8][8] =    /*100 = 1A */ 
{
	/* 9v10v11v12v13v14v15v16v  */
        {35,35,35,35,35,35,35,35},  /*-40degree*/
	{35,35,35,35,35,35,35,35},  /*-25degree*/
	{30,30,30,30,30,30,30,30},  /*-10degree*/
	{25,25,25,25,25,25,25,25},  /*+05degree*/
	{25,25,25,25,25,25,25,25},  /*+20degree*/
	{25,25,25,25,25,25,25,25},  /*+35degree*/
	{25,25,25,25,25,25,25,25},  /*+50degree*/
	{25,25,25,25,25,25,25,25},   /*+65degree*/
	
};
const uint16_t K_LargeSpringPosition_FixedCurrent_Level_1_NoCal[8][8] =    /*100 = 1A */ 
{
	/* 9v10v11v12v13v14v15v16v  */
        {90,90,90,90,90,90,90,90},  /*-40degree*/
	{90,90,90,90,90,90,90,90},  /*-25degree*/
	{85,85,85,85,85,85,85,85},  /*-10degree*/
	{80,80,80,80,80,80,80,80},  /*+05degree*/
	{80,80,80,80,80,80,80,80},  /*+20degree*/
	{80,80,80,80,80,80,80,80},  /*+35degree*/
	{80,80,80,80,80,80,80,80},  /*+50degree*/
	{80,80,80,80,80,80,80,80},   /*+65degree*/
	
};
const uint16_t K_LargeSpringPosition_FixedCurrent_Level_1_Time = 400U;     /*10ms x */

const uint16_t K_LargeSpringPosition_FixedCurrent_Level_2_Cal[8][8] =     /*100 = 1A */
{
	/* 9v10v11v12v13v14v15v16v  */
        {40,40,40,40,40,40,40,40},  /*-40degree*/
	{40,40,40,40,40,40,40,40},  /*-25degree*/
	{35,35,35,35,35,35,35,35},  /*-10degree*/
	{30,30,30,30,30,30,30,30},  /*+05degree*/
	{30,30,30,30,30,30,30,30},  /*+20degree*/
	{30,30,30,30,30,30,30,30},  /*+35degree*/
	{30,30,30,30,30,30,30,30},  /*+50degree*/
	{30,30,30,30,30,30,30,30},   /*+65degree*/
	
};

const uint16_t K_LargeSpringPosition_FixedCurrent_Level_2_NoCal[8][8] =    /*100 = 1A */ 
{
	/* 9v10v11v12v13v14v15v16v  */
        {130,130,130,130,130,130,130,130},  /*-40degree*/
	{130,130,130,130,130,130,130,130},  /*-25degree*/
	{125,125,125,125,125,125,125,125},  /*-10degree*/
	{120,120,120,120,120,120,120,120},  /*+05degree*/
	{120,120,120,120,120,120,120,120},  /*+20degree*/
	{120,120,120,120,120,120,120,120},  /*+35degree*/
	{120,120,120,120,120,120,120,120},  /*+50degree*/
	{120,120,120,120,120,120,120,120},   /*+65degree*/
	
};
const uint16_t K_LargeSpringPosition_FixedCurrent_Level_2_Time = 50U;     /*10ms x */

const uint16_t K_LargeSpringPosition_FixedCurrent_Level_3_Cal[8][8] =     /*100 = 1A */
{
	/* 9v10v11v12v13v14v15v16v  */
        {60,60,60,60,60,60,60,60},  /*-40degree*/
	{60,60,60,60,60,60,60,60},  /*-25degree*/
	{55,55,55,55,55,55,55,55},  /*-10degree*/
	{50,50,50,50,50,50,50,50},  /*+05degree*/
	{50,50,50,50,50,50,50,50},  /*+20degree*/
	{50,50,50,50,50,50,50,50},  /*+35degree*/
	{50,50,50,50,50,50,50,50},  /*+50degree*/
	{50,50,50,50,50,50,50,50},   /*+65degree*/
	
};
const uint16_t K_LargeSpringPosition_FixedCurrent_Level_3_NoCal[8][8] =    /*100 = 1A */ 
{
	/* 9v10v11v12v13v14v15v16v  */
        {160,160,160,160,160,160,160,160},  /*-40degree*/
	{160,160,160,160,160,160,160,160},  /*-25degree*/
	{155,155,155,155,155,155,155,155},  /*-10degree*/
	{150,150,150,150,150,150,150,150},  /*+05degree*/
	{150,150,150,150,150,150,150,150},  /*+20degree*/
	{150,150,150,150,150,150,150,150},  /*+35degree*/
	{150,150,150,150,150,150,150,150},  /*+50degree*/
	{150,150,150,150,150,150,150,150},   /*+65degree*/
	
};
const uint16_t K_LargeSpringPosition_FixedCurrent_Level_3_Time = 10U;     /*10ms x */

const uint16_t K_FindHomeAfterCinch_ComfirmCurrent = 150U;     /*100 = 1A */
const uint16_t K_FindHomeAfterCinch_ComfirmCurrent_Time = 10U;     /*10ms x */
const uint16_t K_FindHomeAfterBlip_ComfirmCurrent = 150U;     /*100 = 1A */
const uint16_t K_FindHomeAfterBlip_ComfirmCurrent_Time = 5U;     /*10ms x */
#endif

#ifdef _CONFIG_IntevaSideLatch
/*********************************************************************************************
**    Inteva Latch Control
*********************************************************************************************/
const uint16_t K_PowerCinchInSecondPosition_AfterPowerUp_Enable = TRUE;

const uint16_t K_LatchPreCinchCheck_Timeout = 200U; /* 1ms x  */
const uint16_t K_LatchPreCinchCheck_Timeout_LongDelay = 3000U; /* 1ms x  */

const uint16_t K_LatchPowerCinching_Timeout = 4500U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterCinch_Timeout = 5000U; /* 1ms x  */
const uint16_t K_LatchPreReleasing_Timeout = 5000U; /* 1ms x  */
const uint16_t K_LatchPowerReleasing_Timeout = 500U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterRelease_Timeout = 2000U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterRelease_Mini_Time = 200U; /* 1ms x  */

const uint16_t K_LatchFindHomeReleaseDirection_Timeout = 5000U; /* 1ms x  */
const uint16_t K_LatchFindHomeCinchDirection_Timeout = 500U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterPark_Timeout = 5000U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterBlip_Timeout = 100U; /* 1ms x  */

const uint16_t K_LatchPreReleased_Timeout = 3000U; 
const uint16_t K_LatchPreRelease_SnowLoad_Time = 3000U;
const uint16_t K_LatchCrankWait_Timeout = 2000U; /* 1ms x  */
const uint16_t K_LatchMechFailure_Timeout = 2000U;
const uint16_t K_LatchPreCinchCheck_Time = 100U; /* 1ms x  */
const uint16_t K_LatchPreCinchCheck_Time_LongDelay = 2000U; /* 1ms x  */

const uint16_t K_PowerCinching_Delay_Time = 0U; /* 1ms x  */
const uint16_t K_PowerReleasing_PawlSwitch_Delay_Time = 100U; /* 1ms x  */ 
const uint16_t K_PowerReleasing_OutofLatch_Delay_Time = 0U;//50U; /* 1ms x  */ 
const uint16_t K_PreReleased_OutofLatch_Delay_Time = 100U;//500U; /* 1ms x  */

const uint16_t K_StopBeforePowerReleasing_Time = 50U; /* 1ms x  */
const uint16_t K_StopBeforePreReleasing_Time = 500U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeAfterRelease_Time = 500U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeAfterPark_Time = 100U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeAfterBlip_Time = 100U; /* 1ms x  */
const uint16_t K_MiniWorkingInCinchDirection_Time = 100U; /* 1ms x  */
const uint16_t K_ContinueFindHomeAfterRelease_Time = 100U; /* 1ms x  */
const uint16_t K_ChangeDutyInFindHomeAfterRelease_Time = 100U;/* 1ms x  */
const uint16_t K_FindHomeAfterPark_PositionSwitch_Delay_Time = 100U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeCinchDirection_Time = 100U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeReleaseDirection_Time = 100U;  /* 1ms x  */
const uint16_t K_LatchFindHomeFailure_Timeout = 1000U;  /* 1ms x  */

const uint16_t K_FindHomeReleaseDirection_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_FindHomeCinchDirection_Inrush_Time = 200U; /* 1ms x  */

const uint16_t K_PowerCinching_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_FindHomeAfterCinch_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_FindHomeAfterPark_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_PreReleasing_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_PowerReleasing_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_FindHomeAfterRelease_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_PowerReleasing_Mini_Time = 100U; /* 1ms x  */

const uint16_t K_WaitForPowerCinching_Time = 200U;/* 1ms x  */

const uint16_t K_FindHomeAfterCinch_StartDuty_Time = 50U;  /*10ms x */
const uint16_t K_FindHomeAfterCinch_DecreaseDuty_Time = 2U;   /* 10ms x  */
const uint16_t K_FindHomeAfterCinch_IncreaseDuty_Time = 1U;   /* 10ms x  */

const uint16_t K_CinchMotorFindHome_Count = 3;
const uint16_t K_PrimaryPositionIsArrived_Time= 2U;
const uint16_t K_ChangeDutyInFindHomeAfterCinch_Time = 100U; /* 1ms x  */
const uint16_t K_ChangeDutyInFindHomeAfterCinch_Time_2nd = 100U; /* 1ms x  */
const uint16_t K_ChangeDutyInPowerCinching_Time = 500U; /* 1ms x  */
const uint16_t K_CinchMotor_PowerCinching_Duty = 80U;
const uint16_t K_CinchMotor_PowerCinching_Duty_2nd = 80U;

const uint16_t K_CinchMotor_FindHomeAfterCinch_Duty = 80U;
const uint16_t K_CinchMotor_FindHomeAfterCinch_Duty_2nd = 70U;

const uint16_t K_ContinueParking_Time = 0U;
const uint16_t K_ContinueParking_Time_2nd = 0U;

const uint16_t K_LowDutyFailFindHomeAfterCinch_Time = 8000U;/* 1ms x  */ 
const uint16_t K_LowDutyFailFindHomeAfterCinch_Duty = 60U; 
const uint16_t K_LowDutyFailPowerCinching_Time = 3000U;/* 1ms x  */ 
const uint16_t K_LowDutyFailPowerCinching_Duty = 100U;

const uint16_t K_ReleaseMotor_FindHomeAfterRelease_Duty = 70U; 
const uint16_t K_ReleaseMotor_FindHomeAfterRelease_Duty_2nd = 70U;

const uint16_t K_CinchMotor_FindHomeAfterRelease_Duty = 80U;
const uint16_t K_CinchMotor_FindHomeAfterRelease_Duty_2nd = 80U;
const uint16_t K_CinchMotor_FindHomeAfterRelease_Duty_3rd = 80U;

const uint16_t K_CinchMotor_FindHomeReleaseDirection_Duty = 70U;
const uint16_t K_CinchMotor_FindHomeReleaseDirection_Duty_2nd = 70U;
const uint16_t K_CinchMotor_FindHomeCinchDirection_Duty = 100U;
const uint16_t K_CinchMotor_FindHomeCinchDirection_Duty_2nd = 50U;

const uint16_t IntevaSide_K_CinchMotor_FindHomeAfterPark_Duty = 50U;
const uint16_t IntevaSide_K_CinchMotor_FindHomeAfterBlip_Duty = 30U;

const uint16_t K_ReleaseMotor_PowerReleasing_Duty = 100U;
const uint16_t K_ReleaseMotor_PowerReleasing_Duty_2nd = 50U;
const uint16_t K_CinchMotor_PowerReleasing_Duty = 100U;
const uint16_t K_CinchMotor_PowerReleasing_Duty_2nd = 50U;

const uint16_t K_PowerReleasing_ComfirmCurrent = 200U;

const uint16_t K_PowerCinching_SoftStall_Current = 1000U;
const uint16_t K_FindHomeAfterCinch_SoftStall_Current = 1000U;
const uint16_t K_PreReleasing_SoftStall_Current = 1000U;
const uint16_t K_PowerReleasing_SoftStall_Current = 1000U;
const uint16_t K_FindHomeAfterRelease_SoftStall_Current = 1000U;
const uint16_t K_FindHomeReleaseDirection_SoftStall_Current = 200U;
const uint16_t K_FindHomeCinchDirection_SoftStall_Current = 200U;
const uint16_t K_FindHomeAfterPark_SoftStall_Current = 1000U;


const uint16_t K_PowerCinching_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeAfterCinch_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_PreReleasing_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_PowerReleasing_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeAfterRelease_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeReleaseDirection_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeCinchDirection_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeAfterPark_SoftStall_Time = 10U; /* 10ms x  */

const uint16_t K_StopBeforeFindHomeAfterCinch_Time = 500U;  /* 1ms x  */
const uint16_t K_LatchNotLeaveHomeInMiniPowerCinch_Time = 50U; /* 1ms x  */

const uint16_t K_PowerReleasing_ComfirmCurrent_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeAfterCinch_Work_MiniTime = 20U; /* 10ms x  */ 
const uint16_t K_ChangeDutyInFindHomeReleaseDirection_Time = 200U; /* 10ms x  */
const uint16_t K_ChangeDutyInFindHomeCinchDirection_Time = 200U; /* 10ms x  */
#endif

#ifdef _CONFIG_IntevaSideLatch_ES1T
/*********************************************************************************************
**    Inteva Latch Control
*********************************************************************************************/
const uint16_t IntevaSide_K_PowerCinchInSecondPosition_AfterPowerUp_Enable = TRUE;
const uint16_t IntevaSide_K_LatchPreCinchCheck_Timeout = 200U; /* 1ms x  */
const uint16_t IntevaSide_K_LatchPreCinchCheck_Timeout_LongDelay = 3000U; /* 1ms x  */

#ifdef _CHERYE0X_PD_PowerCinching_Pause
const uint16_t IntevaSide_K_LatchPowerCinching_Timeout = 4000U; /* 1ms x  */
#else
const uint16_t IntevaSide_K_LatchPowerCinching_Timeout = 3000U; /* 1ms x  */
#endif

const uint16_t IntevaSide_K_LatchFindHomeAfterCinch_Timeout = 2500U; /* 1ms x  */
const uint16_t IntevaSide_K_LatchPreReleasing_Timeout = 2500U; /* 1ms x  */
#ifdef _AUDI427_PD
const uint16_t IntevaSide_K_LatchPowerReleasing_Timeout = 2000U; /* 1ms x  */
#else
const uint16_t IntevaSide_K_LatchPowerReleasing_Timeout = 1000U; /* 1ms x  */
#endif
const uint16_t IntevaSide_K_LatchFindHomeAfterRelease_Timeout = 400U; /* 1ms x  */
const uint16_t IntevaSide_K_LatchFindHomeAfterRelease_Mini_Time = 200U; /* 1ms x  */

const uint16_t IntevaSide_K_LatchFindHomeReleaseDirection_Timeout = 2500U; /* 1ms x  */
const uint16_t IntevaSide_K_LatchFindHomeCinchDirection_Timeout = 500U; /* 1ms x  */
const uint16_t IntevaSide_K_LatchFindHomeReleaseMotor_Timeout = 500U; /* 1ms x  */
const uint16_t IntevaSide_K_LatchFindHomeAfterPark_Timeout = 5000U; /* 1ms x  */
const uint16_t IntevaSide_K_LatchFindHomeAfterBlip_Timeout = 100U; /* 1ms x  */

#ifdef _CHERYE0X_PD_SmoothManualPowerOperation
const uint16_t IntevaSide_K_LatchPreReleased_Timeout = 1000U;//3000U; //1000U;//3000U;
#else
const uint16_t IntevaSide_K_LatchPreReleased_Timeout = 500U;//3000U; //1000U;//3000U;
#endif
const uint16_t IntevaSide_K_LatchPreReleased_Timeout_LongDelay = 3000U; //1000U;//3000U;

const uint16_t IntevaSide_K_LatchPreRelease_SnowLoad_Time = 3000U;
const uint16_t IntevaSide_K_LatchCrankWait_Timeout = 2000U; /* 1ms x  */
const uint16_t IntevaSide_K_LatchMechFailure_Timeout = 2000U;
const uint16_t IntevaSide_K_LatchIceBreaking_Timeout = 3000U; /* 1ms x  */
const uint16_t IntevaSide_K_LatchFindHomeAfterIceBreak_Timeout = 2500U; /* 1ms x  */

const uint16_t IntevaSide_K_LatchPreCinchCheck_Time = 10U; //100U;/* 1ms x  */
const uint16_t IntevaSide_K_LatchPreCinchCheck_Time_LongDelay = 2000U; /* 1ms x  */
const uint16_t IntevaSide_K_PowerCinching_Delay_Time = 0U; /* 1ms x  */
const uint16_t IntevaSide_K_PowerReleasing_PawlSwitch_Delay_Time = 100U; /* 1ms x  */ 
const uint16_t IntevaSide_K_PowerReleasing_OutofLatch_Delay_Time = 0U;//50U; /* 1ms x  */ 
const uint16_t IntevaSide_K_PreReleased_OutofLatch_Delay_Time = 100U;//500U; /* 1ms x  */
const uint16_t IntevaSide_K_IceBreaking_OutofLatch_Delay_Time = 100U;//50U; /* 1ms x  */

const uint16_t IntevaSide_K_StopBeforePowerReleasing_Time = 50U; /* 1ms x  */
const uint16_t IntevaSide_K_StopBeforePreReleasing_Time = 100U; /* 1ms x  */
const uint16_t IntevaSide_K_StopBeforeFindHomeAfterRelease_Time = 100U; /* 1ms x  */
const uint16_t IntevaSide_K_StopBeforeFindHomeAfterPark_Time = 100U; /* 1ms x  */
const uint16_t IntevaSide_K_StopBeforeFindHomeAfterBlip_Time = 100U; /* 1ms x  */
const uint16_t IntevaSide_K_StopBeforeIceBreaking_Time = 100U; /* 1ms x  */
const uint16_t IntevaSide_K_StopBeforeFindHomeAfterIceBreak_Time = 100U; /* 1ms x  */

const uint16_t IntevaSide_K_MiniWorkingInCinchDirection_Time = 100U; /* 1ms x  */
const uint16_t IntevaSide_K_ContinueFindHomeAfterRelease_Time = 100U; /* 1ms x  */
const uint16_t IntevaSide_K_ContinueFindHomeAfterIceBreak_Time = 50U; /* 1ms x  */
const uint16_t IntevaSide_K_ChangeDutyInFindHomeAfterRelease_Time = 100U;/* 1ms x  */
const uint16_t IntevaSide_K_ChangeDutyInFindHomeAfterRelease_Time_2nd = 20U;/* 1ms x  */
const uint16_t IntevaSide_K_ChangeDutyInFindHomeAfterRelease_Time_3rd = 80U;/* 1ms x  */

const uint16_t IntevaSide_K_FindHomeAfterPark_PositionSwitch_Delay_Time = 100U; /* 1ms x  */
const uint16_t IntevaSide_K_StopBeforeFindHomeReleaseMotor_Time = 100U; /* 1ms x  */
const uint16_t IntevaSide_K_StopBeforeFindHomeCinchDirection_Time = 100U; /* 1ms x  */
const uint16_t IntevaSide_K_StopBeforeFindHomeReleaseDirection_Time = 100U;  /* 1ms x  */
const uint16_t IntevaSide_K_LatchFindHomeFailure_Timeout = 1000U;  /* 1ms x  */

const uint16_t IntevaSide_K_FindHomeReleaseDirection_Inrush_Time = 200U; /* 1ms x  */
const uint16_t IntevaSide_K_FindHomeCinchDirection_Inrush_Time = 200U; /* 1ms x  */
const uint16_t IntevaSide_K_FindHomeReleaseMotor_Inrush_Time = 100U; /* 1ms x  */
const uint16_t IntevaSide_K_PowerCinching_Inrush_Time = 200U; /* 1ms x  */
const uint16_t IntevaSide_K_FindHomeAfterCinch_Inrush_Time = 200U; /* 1ms x  */
const uint16_t IntevaSide_K_FindHomeAfterPark_Inrush_Time = 200U; /* 1ms x  */
const uint16_t IntevaSide_K_PreReleasing_Inrush_Time = 200U; /* 1ms x  */
const uint16_t IntevaSide_K_PowerReleasing_Inrush_Time = 200U; /* 1ms x  */
const uint16_t IntevaSide_K_FindHomeAfterRelease_Inrush_Time = 200U; /* 1ms x  */
const uint16_t IntevaSide_K_IceBreaking_Inrush_Time = 200U; /* 1ms x  */
const uint16_t IntevaSide_K_FindHomeAfterIceBreak_Inrush_Time = 200U; /* 1ms x  */


const uint16_t IntevaSide_K_PowerReleasing_Mini_Time = 100U; /* 1ms x  */
const uint16_t IntevaSide_K_PreReleased_Mini_Time = 200U; /* 1ms x  */

const uint16_t IntevaSide_K_WaitForPowerCinching_Time = 200U;/* 1ms x  */

const uint16_t IntevaSide_K_FindHomeAfterCinch_StartDuty_Time = 50U;  /*10ms x */
const uint16_t IntevaSide_K_FindHomeAfterCinch_DecreaseDuty_Time = 2U;   /* 10ms x  */
const uint16_t IntevaSide_K_FindHomeAfterCinch_IncreaseDuty_Time = 1U;   /* 10ms x  */

const uint16_t IntevaSide_K_CinchMotorFindHome_Count = 3;
const uint16_t IntevaSide_K_PrimaryPositionIsArrived_Time= 10U;
const uint16_t IntevaSide_K_ChangeDutyInFindHomeAfterCinch_Time = 100U; /* 1ms x  */
const uint16_t IntevaSide_K_ChangeDutyInFindHomeAfterCinch_Time_2nd = 50U; /* 1ms x  */

const uint16_t IntevaSide_K_ChangeDutyInPowerCinching_Time = 500U;//* 1ms x  */
const uint16_t IntevaSide_K_ChangeDutyInPowerCinching_Time_2nd = 800U; /* 1ms x  */
const uint16_t IntevaSide_K_ChangeDutyInIceBreaking_Time = 500U; /* 1ms x  */
const uint16_t IntevaSide_K_ChangeDutyInIceBreaking_Time_2nd = 500U; /* 1ms x  */
const uint16_t IntevaSide_K_ChangeDutyInFindHomeAfterIceBreak_Time = 100U; /* 1ms x  */

const uint16_t IntevaSide_K_CinchMotor_PowerCinching_Duty = 87U;
#ifdef _CHERYE0X_PD_PowerCinching_Pause
const uint16_t IntevaSide_K_CinchMotor_PowerCinching_Duty_2nd = 0U;
const uint16_t IntevaSide_K_CinchMotor_PowerCinching_Duty_2nd_LongDelay = 87U;
#else
const uint16_t IntevaSide_K_CinchMotor_PowerCinching_Duty_2nd = 87U;
#endif
const uint16_t IntevaSide_K_CinchMotor_PowerCinching_Duty_3rd = 87U;

const uint16_t IntevaSide_K_CinchMotor_FindHomeAfterCinch_Duty = 100U;
const uint16_t IntevaSide_K_CinchMotor_FindHomeAfterCinch_Duty_2nd = 55U;
const uint16_t IntevaSide_K_CinchMotor_FindHomeAfterCinch_Duty_3rd = 55U;
const uint16_t IntevaSide_K_CinchMotor_PreReleasing_Duty = 100U;

const uint16_t IntevaSide_K_ContinueParking_Time = 20U;
const uint16_t IntevaSide_K_ContinueParking_Time_2nd = 20U;

const uint16_t IntevaSide_K_LowDutyFailFindHomeAfterCinch_Time = 3000U;/* 1ms x  */ 
const uint16_t IntevaSide_K_LowDutyFailFindHomeAfterCinch_Duty = 100U; 
const uint16_t IntevaSide_K_LowDutyFailPowerCinching_Time = 2500U;/* 1ms x  */ 
const uint16_t IntevaSide_K_LowDutyFailPowerCinching_Duty = 100U;
const uint16_t IntevaSide_K_LowDutyFailIceBreaking_Time = 3000U;/* 1ms x  */ 
const uint16_t IntevaSide_K_LowDutyFailIceBreaking_Duty = 100U;
const uint16_t IntevaSide_K_LowDutyFailFindHomeAfterIceBreak_Time = 3000U;/* 1ms x  */ 
const uint16_t IntevaSide_K_LowDutyFailFindHomeAfterIceBreak_Duty = 100U;

const uint16_t IntevaSide_K_ReleaseMotor_FindHomeAfterRelease_Duty = 60U; 
const uint16_t IntevaSide_K_ReleaseMotor_FindHomeAfterRelease_Duty_2nd = 60U;
const uint16_t IntevaSide_K_ReleaseMotor_FindHomeAfterRelease_Duty_3rd = 60U;
const uint16_t IntevaSide_K_ReleaseMotor_FindHomeAfterRelease_Duty_4th = 60U;

const uint16_t IntevaSide_K_CinchMotor_FindHomeAfterRelease_Duty = 80U;
const uint16_t IntevaSide_K_CinchMotor_FindHomeAfterRelease_Duty_2nd = 80U;
const uint16_t IntevaSide_K_CinchMotor_FindHomeAfterRelease_Duty_3rd = 80U;

const uint16_t IntevaSide_K_CinchMotor_FindHomeReleaseDirection_Duty = 100U;
const uint16_t IntevaSide_K_CinchMotor_FindHomeReleaseDirection_Duty_2nd = 55U;
const uint16_t IntevaSide_K_CinchMotor_FindHomeCinchDirection_Duty = 60U;
const uint16_t IntevaSide_K_CinchMotor_FindHomeCinchDirection_Duty_2nd = 60U;

const uint16_t IntevaSide_K_ReleaseMotor_FindHomeReleaseMotor_Duty = 60U;
const uint16_t IntevaSide_K_ReleaseMotor_FindHomeReleaseMotor_Duty_2nd = 60U;

const uint16_t IntevaSide_K_CinchMotor_FindHomeAfterPark_Duty = 50U;
const uint16_t IntevaSide_K_CinchMotor_FindHomeAfterBlip_Duty = 30U;

const uint16_t IntevaSide_K_ReleaseMotor_PowerReleasing_Duty = 87U;
const uint16_t IntevaSide_K_ReleaseMotor_PowerReleasing_Duty_2nd = 87U;
const uint16_t IntevaSide_K_CinchMotor_PowerReleasing_Duty = 100U;
const uint16_t IntevaSide_K_CinchMotor_PowerReleasing_Duty_2nd = 50U;

const uint16_t IntevaSide_K_CinchMotor_IceBreaking_Duty = 100U;
const uint16_t IntevaSide_K_CinchMotor_IceBreaking_Duty_2nd = 100U;
const uint16_t IntevaSide_K_CinchMotor_IceBreaking_Duty_3rd = 100U;
const uint16_t IntevaSide_K_CinchMotor_FindHomeAfterIceBreak_Duty = 100U;
const uint16_t IntevaSide_K_CinchMotor_FindHomeAfterIceBreak_Duty_2nd = 55U;

const uint16_t IntevaSide_K_PowerReleasing_ComfirmCurrent = 300U;

const uint16_t IntevaSide_K_PowerCinching_SoftStall_Current = 1500U;
const uint16_t IntevaSide_K_FindHomeAfterCinch_SoftStall_Current = 1500U;
const uint16_t IntevaSide_K_PreReleasing_SoftStall_Current = 1500U;
const uint16_t IntevaSide_K_PowerReleasing_SoftStall_Current = 1500U;
const uint16_t IntevaSide_K_FindHomeAfterRelease_SoftStall_Current = 1500U;
const uint16_t IntevaSide_K_FindHomeReleaseDirection_SoftStall_Current = 1000U;
const uint16_t IntevaSide_K_FindHomeCinchDirection_SoftStall_Current = 1000U;
const uint16_t IntevaSide_K_FindHomeAfterPark_SoftStall_Current = 1500U;

const uint16_t IntevaSide_K_IceBreaking_SoftStall_Current = 1500U;
const uint16_t IntevaSide_K_FindHomeAfterIceBreak_SoftStall_Current = 1500U;
const uint16_t IntevaSide_K_FindHomeReleaseMotor_SoftStall_Current = 1500U;

const uint16_t IntevaSide_K_PowerCinching_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t IntevaSide_K_FindHomeAfterCinch_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t IntevaSide_K_PreReleasing_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t IntevaSide_K_PowerReleasing_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t IntevaSide_K_FindHomeAfterRelease_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t IntevaSide_K_FindHomeReleaseDirection_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t IntevaSide_K_FindHomeCinchDirection_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t IntevaSide_K_FindHomeReleaseMotor_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t IntevaSide_K_FindHomeAfterPark_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t IntevaSide_K_IceBreaking_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t IntevaSide_K_FindHomeAfterIceBreak_SoftStall_Time = 10U; /* 10ms x  */
 
const uint16_t IntevaSide_K_StopBeforeFindHomeAfterCinch_Time = 100U;  /* 1ms x  */
const uint16_t IntevaSide_K_LatchNotLeaveHomeInMiniPowerCinch_Time = 50U; /* 1ms x  */
const uint16_t IntevaSide_K_LatchNotLeaveHomeInMiniIceBreak_Time = 50U; /* 1ms x  */

const uint16_t IntevaSide_K_PowerReleasing_ComfirmCurrent_Time = 10U; /* 10ms x  */
const uint16_t IntevaSide_K_FindHomeAfterCinch_Work_MiniTime = 20U; /* 10ms x  */ 
const uint16_t IntevaSide_K_ChangeDutyInFindHomeReleaseDirection_Time = 5U; /* 10ms x  */
const uint16_t IntevaSide_K_ChangeDutyInFindHomeCinchDirection_Time = 5U; /* 10ms x  */
const uint16_t IntevaSide_K_ChangeDutyInFindHomeReleaseMotor_Time = 5U; /* 10ms x  */
const uint16_t IntevaSide_K_LatchFullyReleased_Braking_Timeout = 10U; /* 10ms x  */
const uint16_t IntevaSide_K_LatchFullyCinched_Braking_Timeout = 10U; /* 10ms x  */
const uint16_t IntevaSide_K_LatchPreReleased_Braking_Timeout = 10U; /* 10ms x  */

#ifdef _IntevaSide_CONFIG_ReleaseMotorHardStop_EnhancedCurrent
const uint16_t IntevaSide_K_ReleaseMotorHardStop_EnhancedCurrent_Detect = 40U;   /*100 = 1A */ 
const uint16_t IntevaSide_K_ReleaseMotorHardStop_EnhancedCurrent_DecreasePerTimer = 1U;    /*10ms x */
const uint16_t IntevaSide_K_ReleaseMotorHardStop_EnhancedCurrent_Decrease_Time = 2U;    /*10ms x */
const uint16_t IntevaSide_K_ReleaseMotorHardStop_EnhancedCurrent_IncreasePerTimer = 5U;    /*10ms x */
const uint16_t IntevaSide_K_ReleaseMotorHardStop_EnhancedCurrent_Increase_Time = 30U;    /*10ms x */
const uint16_t IntevaSide_K_ReleaseMotorHardStop_EnhancedCurrent_Threshold_Time = 2U;    /*10ms x */ 
#endif
#ifdef _IntevaSide_CONFIG_ReleaseMotorHardStop_FixedCurrent
const uint16_t IntevaSide_K_ReleaseMotorHardStop_FixedCurrent_Level_1_Cal = 25U;   /*100 = 1A */ 
const uint16_t IntevaSide_K_ReleaseMotorHardStop_FixedCurrent_Level_1_NoCal = 80U;   /*100 = 1A */ 
const uint16_t IntevaSide_K_ReleaseMotorHardStop_FixedCurrent_Level_1_Time = 40U;   /*10ms x */
const uint16_t IntevaSide_K_ReleaseMotorHardStop_FixedCurrent_Level_2_Cal = 30U;   /*100 = 1A */
const uint16_t IntevaSide_K_ReleaseMotorHardStop_FixedCurrent_Level_2_NoCal = 100U;   /*100 = 1A */ 
const uint16_t IntevaSide_K_ReleaseMotorHardStop_FixedCurrent_Level_2_Time = 10U;    /*10ms x */
const uint16_t IntevaSide_K_ReleaseMotorHardStop_FixedCurrent_Level_3_Cal = 50U;    /*100 = 1A */
const uint16_t IntevaSide_K_ReleaseMotorHardStop_FixedCurrent_Level_3_NoCal = 150U;    /*100 = 1A */ 
const uint16_t IntevaSide_K_ReleaseMotorHardStop_FixedCurrent_Level_3_Time = 5U;     /*10ms x */
#endif

#ifdef _IntevaSide_CONFIG_CinchMotorHardStop_EnhancedCurrent
const uint16_t IntevaSide_K_CinchMotorHardStop_EnhancedCurrent_Detect = 100U;   /*100 = 1A */ 
const uint16_t IntevaSide_K_CinchMotorHardStop_EnhancedCurrent_DecreasePerTimer = 1U;    /*10ms x */
const uint16_t IntevaSide_K_CinchMotorHardStop_EnhancedCurrent_Decrease_Time = 2U;    /*10ms x */
const uint16_t IntevaSide_K_CinchMotorHardStop_EnhancedCurrent_IncreasePerTimer = 5U;    /*10ms x */
const uint16_t IntevaSide_K_CinchMotorHardStop_EnhancedCurrent_Increase_Time = 30U;    /*10ms x */
const uint16_t IntevaSide_K_CinchMotorHardStop_EnhancedCurrent_Threshold_Time = 2U;    /*10ms x */ 
#endif
#ifdef _IntevaSide_CONFIG_CinchMotorHardStop_FixedCurrent
const uint16_t IntevaSide_K_CinchMotorHardStop_FixedCurrent_Level_1_Cal = 100U;   /*100 = 1A */ 
const uint16_t IntevaSide_K_CinchMotorHardStop_FixedCurrent_Level_1_NoCal = 100U;   /*100 = 1A */ 
const uint16_t IntevaSide_K_CinchMotorHardStop_FixedCurrent_Level_1_Time = 40U;   /*10ms x */
const uint16_t IntevaSide_K_CinchMotorHardStop_FixedCurrent_Level_2_Cal = 200U;   /*100 = 1A */
const uint16_t IntevaSide_K_CinchMotorHardStop_FixedCurrent_Level_2_NoCal = 200U;   /*100 = 1A */ 
const uint16_t IntevaSide_K_CinchMotorHardStop_FixedCurrent_Level_2_Time = 20U;    /*10ms x */
const uint16_t IntevaSide_K_CinchMotorHardStop_FixedCurrent_Level_3_Cal = 300U;    /*100 = 1A */
const uint16_t IntevaSide_K_CinchMotorHardStop_FixedCurrent_Level_3_NoCal = 300U;    /*100 = 1A */ 
const uint16_t IntevaSide_K_CinchMotorHardStop_FixedCurrent_Level_3_Time = 10U;     /*10ms x */
#endif


#endif

#ifdef _CONFIG_InginSideLatch
/*********************************************************************************************
**    Inteva Latch Control
*********************************************************************************************/
const uint16_t K_PowerCinchInSecondPosition_AfterPowerUp_Enable = TRUE;

const uint16_t K_LatchPreCinchCheck_Timeout = 200U; /* 1ms x  */
const uint16_t K_LatchPreCinchCheck_Timeout_LongDelay = 3000U; /* 1ms x  */
const uint16_t K_LatchPowerCinching_Timeout = 4000U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterCinch_Timeout = 4000U; /* 1ms x  */
const uint16_t K_LatchPreReleasing_Timeout = 4000U; /* 1ms x  */
const uint16_t K_LatchPowerReleasing_Timeout = 500U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterRelease_Timeout = 500U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterRelease_Mini_Time = 200U;//300U; /* 1ms x  */

const uint16_t K_LatchFindHomeReleaseDirection_Timeout = 4000U; /* 1ms x  */
const uint16_t K_LatchFindHomeCinchDirection_Timeout = 4000U; /* 1ms x  */
const uint16_t K_LatchFindHomeReleaseMotor_Timeout = 500U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterPark_Timeout = 500U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterBlip_Timeout = 2500U; /* 1ms x  */

const uint16_t K_LatchPreReleased_Timeout = 3000U; //15000U; //
const uint16_t K_LatchPreReleased_Timeout_LongDelay = 3000U; //15000U; //

const uint16_t K_LatchPreRelease_SnowLoad_Time = 3000U;
const uint16_t K_LatchCrankWait_Timeout = 2000U; /* 1ms x  */
const uint16_t K_LatchMechFailure_Timeout = 2000U;
const uint16_t K_LatchIceBreaking_Timeout = 4000U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterIceBreak_Timeout = 4000U; /* 1ms x  */

const uint16_t K_LatchPreCinchCheck_Time = 20U;//100U; /* 1ms x  */
const uint16_t K_LatchPreCinchCheck_Time_LongDelay = 2000U; /* 1ms x  */
const uint16_t K_PowerCinching_Delay_Time = 0U; /* 1ms x  */
const uint16_t K_PowerReleasing_PawlSwitch_Delay_Time = 100U; /* 1ms x  */ 
const uint16_t K_PowerReleasing_OutofLatch_Delay_Time = 0U;//50U; /* 1ms x  */ 
const uint16_t K_PreReleased_OutofLatch_Delay_Time = 100U;//500U; /* 1ms x  */
const uint16_t K_IceBreaking_OutofLatch_Delay_Time = 0U;//50U; /* 1ms x  */

const uint16_t K_StopBeforePowerReleasing_Time = 50U; /* 1ms x  */
const uint16_t K_StopBeforePreReleasing_Time = 100U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeAfterRelease_Time = 100U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeAfterPark_Time = 100U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeAfterBlip_Time = 100U; /* 1ms x  */
const uint16_t K_StopBeforeIceBreaking_Time = 100U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeAfterIceBreak_Time = 100U; /* 1ms x  */

const uint16_t K_CinchMotor_IncreaseStep_Duty = 3U; /* x% x  */
const uint16_t K_CinchMotor_DecreaseStep_Duty = 2U; /* x% x  */
const uint16_t K_ReleaseMotor_IncreaseStep_Duty = 5U; /* x% x  */
const uint16_t K_ReleaseMotor_DecreaseStep_Duty = 3U; /* x% x  */

const uint16_t K_MiniWorkingInCinchDirection_Time = 100U; /* 1ms x  */
const uint16_t K_ContinueFindHomeAfterRelease_Time = 100U; /* 1ms x  */
const uint16_t K_ContinueFindHomeAfterIceBreak_Time = 50U; /* 1ms x  */
const uint16_t K_ChangeDutyInFindHomeAfterRelease_Time = 10U;/* 1ms x  */
const uint16_t K_ChangeDutyInFindHomeAfterRelease_Time_2nd = 100U;///20U;/* 1ms x  */
const uint16_t K_ChangeDutyInFindHomeAfterRelease_Time_3rd = 0U;/* 1ms x  */

const uint16_t K_FindHomeAfterPark_PositionSwitch_Delay_Time = 50U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeReleaseMotor_Time = 100U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeCinchDirection_Time = 100U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeReleaseDirection_Time = 100U;  /* 1ms x  */
const uint16_t K_LatchFindHomeFailure_Timeout = 1500U;  /* 1ms x  */

const uint16_t K_FindHomeReleaseDirection_Inrush_Time = 100U; /* 1ms x  */
const uint16_t K_FindHomeCinchDirection_Inrush_Time = 100U; /* 1ms x  */
const uint16_t K_FindHomeReleaseMotor_Inrush_Time = 100U; /* 1ms x  */

const uint16_t K_PowerCinching_Inrush_Time = 100U; /* 1ms x  */
const uint16_t K_FindHomeAfterCinch_Inrush_Time = 100U; /* 1ms x  */
const uint16_t K_FindHomeAfterPark_Inrush_Time = 100U; /* 1ms x  */
const uint16_t K_PreReleasing_Inrush_Time = 100U; /* 1ms x  */
const uint16_t K_PowerReleasing_Inrush_Time = 100U; /* 1ms x  */
const uint16_t K_FindHomeAfterRelease_Inrush_Time = 100U; /* 1ms x  */
const uint16_t K_IceBreaking_Inrush_Time = 100U; /* 1ms x  */
const uint16_t K_FindHomeAfterIceBreak_Inrush_Time = 100U; /* 1ms x  */


const uint16_t K_PowerReleasing_Mini_Time = 200U; /* 1ms x  */
const uint16_t K_PreReleased_Mini_Time = 500U; /* 1ms x  */

const uint16_t K_WaitForPowerCinching_Time = 200U;/* 1ms x  */

const uint16_t K_FindHomeAfterCinch_StartDuty_Time = 50U;  /*10ms x */
const uint16_t K_FindHomeAfterCinch_DecreaseDuty_Time = 2U;   /* 10ms x  */
const uint16_t K_FindHomeAfterCinch_IncreaseDuty_Time = 1U;   /* 10ms x  */

const uint16_t K_CinchMotorFindHome_Count = 3;
const uint16_t K_PrimaryPositionIsArrived_Time= 2U;//10U;
const uint16_t K_ChangeDutyInFindHomeAfterCinch_Time = 100U; /* 1ms x  */
const uint16_t K_ChangeDutyInFindHomeAfterCinch_Time_2nd = 1200U; /* 1ms x  */
const uint16_t K_ChangeDutyInPowerCinching_Time = 700U; /* 1ms x  */
const uint16_t K_ChangeDutyInPowerCinching_Time_2nd = 800U; /* 1ms x  */
const uint16_t K_ChangeDutyInIceBreaking_Time = 500U; /* 1ms x  */
const uint16_t K_ChangeDutyInIceBreaking_Time_2nd = 500U; /* 1ms x  */
const uint16_t K_ChangeDutyInFindHomeAfterIceBreak_Time = 100U; /* 1ms x  */

const uint16_t K_CinchMotor_PowerCinching_Duty = 60U;
const uint16_t K_CinchMotor_PowerCinching_Duty_2nd = 0U;
const uint16_t K_CinchMotor_PowerCinching_Duty_2nd_LongDelay = 60U;
const uint16_t K_CinchMotor_PowerCinching_Duty_3rd = 60U;

const uint16_t K_CinchMotor_FindHomeAfterCinch_Duty = 20U;
const uint16_t K_CinchMotor_FindHomeAfterCinch_Duty_2nd = 50U;
const uint16_t K_CinchMotor_FindHomeAfterCinch_Duty_3rd = 50U;
const uint16_t K_CinchMotor_PreReleasing_Duty = 65U;

const uint16_t K_ContinueParking_Time = 0U;
const uint16_t K_ContinueParking_Time_2nd = 0U;

const uint16_t K_LowDutyFailFindHomeAfterCinch_Time = 3000U;/* 1ms x  */ 
const uint16_t K_LowDutyFailFindHomeAfterCinch_Duty = 100U; 
const uint16_t K_LowDutyFailPowerCinching_Time = 3000U;/* 1ms x  */ 
const uint16_t K_LowDutyFailPowerCinching_Duty = 100U;
const uint16_t K_LowDutyFailIceBreaking_Time = 2000U;/* 1ms x  */ 
const uint16_t K_LowDutyFailIceBreaking_Duty = 100U;
const uint16_t K_LowDutyFailFindHomeAfterIceBreak_Time = 2000U;/* 1ms x  */ 
const uint16_t K_LowDutyFailFindHomeAfterIceBreak_Duty = 100U;

const uint16_t K_ReleaseMotor_FindHomeAfterRelease_Duty = 10U; 
const uint16_t K_ReleaseMotor_FindHomeAfterRelease_Duty_2nd = 40U;//60U;
const uint16_t K_ReleaseMotor_FindHomeAfterRelease_Duty_3rd = 40U;//20U;
const uint16_t K_ReleaseMotor_FindHomeAfterRelease_Duty_4th = 100U;//60U;


const uint16_t K_CinchMotor_FindHomeAfterRelease_Duty = 80U;
const uint16_t K_CinchMotor_FindHomeAfterRelease_Duty_2nd = 80U;
const uint16_t K_CinchMotor_FindHomeAfterRelease_Duty_3rd = 80U;

const uint16_t K_CinchMotor_FindHomeReleaseDirection_Duty = 100U;
const uint16_t K_CinchMotor_FindHomeReleaseDirection_Duty_2nd = 55U;
const uint16_t K_CinchMotor_FindHomeCinchDirection_Duty = 60U;
const uint16_t K_CinchMotor_FindHomeCinchDirection_Duty_2nd = 60U;

const uint16_t K_ReleaseMotor_FindHomeReleaseMotor_Duty = 60U;
const uint16_t K_ReleaseMotor_FindHomeReleaseMotor_Duty_2nd = 60U;

const uint16_t K_CinchMotor_FindHomeAfterPark_Duty = 60U;
const uint16_t K_CinchMotor_FindHomeAfterBlip_Duty = 60U;

const uint16_t K_ReleaseMotor_PowerReleasing_Duty = 80U; 
const uint16_t K_ReleaseMotor_PowerReleasing_Duty_2nd = 80U; 
const uint16_t K_CinchMotor_PowerReleasing_Duty = 100U;
const uint16_t K_CinchMotor_PowerReleasing_Duty_2nd = 80U;

const uint16_t K_CinchMotor_IceBreaking_Duty = 65U;
const uint16_t K_CinchMotor_IceBreaking_Duty_2nd = 65U;
const uint16_t K_CinchMotor_IceBreaking_Duty_3rd = 65U;
const uint16_t K_CinchMotor_FindHomeAfterIceBreak_Duty = 100U;
const uint16_t K_CinchMotor_FindHomeAfterIceBreak_Duty_2nd = 55U;

const uint16_t K_PowerReleasing_ComfirmCurrent = 200U;

const uint16_t K_PowerCinching_SoftStall_Current = 1500U;
const uint16_t K_FindHomeAfterCinch_SoftStall_Current = 1500U;
const uint16_t K_PreReleasing_SoftStall_Current = 1500U;
const uint16_t K_PowerReleasing_SoftStall_Current = 1500U;
const uint16_t K_FindHomeAfterRelease_SoftStall_Current = 1500U;
const uint16_t K_FindHomeReleaseDirection_SoftStall_Current = 1000U;
const uint16_t K_FindHomeCinchDirection_SoftStall_Current = 1000U;
const uint16_t K_FindHomeAfterPark_SoftStall_Current = 1500U;

const uint16_t K_IceBreaking_SoftStall_Current = 1500U;
const uint16_t K_FindHomeAfterIceBreak_SoftStall_Current = 1500U;
const uint16_t K_FindHomeReleaseMotor_SoftStall_Current = 1500U;


const uint16_t K_PowerCinching_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeAfterCinch_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_PreReleasing_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_PowerReleasing_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeAfterRelease_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeReleaseDirection_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeCinchDirection_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeReleaseMotor_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeAfterPark_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_IceBreaking_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeAfterIceBreak_SoftStall_Time = 10U; /* 10ms x  */
 
const uint16_t K_StopBeforeFindHomeAfterCinch_Time = 20U;  /* 1ms x  */
const uint16_t K_LatchNotLeaveHomeInMiniPowerCinch_Time = 50U; /* 1ms x  */
const uint16_t K_LatchNotLeaveHomeInMiniIceBreak_Time = 50U; /* 1ms x  */

const uint16_t K_PowerReleasing_ComfirmCurrent_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeAfterCinch_Work_MiniTime = 20U; /* 10ms x  */ 
const uint16_t K_ChangeDutyInFindHomeReleaseDirection_Time = 5U; /* 10ms x  */
const uint16_t K_ChangeDutyInFindHomeCinchDirection_Time = 5U; /* 10ms x  */
const uint16_t K_ChangeDutyInFindHomeReleaseMotor_Time = 5U; /* 10ms x  */
const uint16_t K_LatchFullyReleased_Braking_Timeout = 10U; /* 10ms x  */
const uint16_t K_LatchFullyCinched_Braking_Timeout = 10U; /* 10ms x  */
const uint16_t K_LatchPreReleased_Braking_Timeout = 10U; /* 10ms x  */


#ifdef _CONFIG_ReleaseMotorHardStop_EnhancedCurrent
const uint16_t K_ReleaseMotorHardStop_EnhancedCurrent_Detect = 40U;   /*100 = 1A */ 
const uint16_t K_ReleaseMotorHardStop_EnhancedCurrent_DecreasePerTimer = 1U;    /*10ms x */
const uint16_t K_ReleaseMotorHardStop_EnhancedCurrent_Decrease_Time = 2U;       /*10ms x */
const uint16_t K_ReleaseMotorHardStop_EnhancedCurrent_IncreasePerTimer = 5U;  /*10ms x */
const uint16_t K_ReleaseMotorHardStop_EnhancedCurrent_Increase_Time = 30U;      /*10ms x */
const uint16_t K_ReleaseMotorHardStop_EnhancedCurrent_Threshold_Time = 2U;     /*10ms x */ 
#endif
#ifdef _CONFIG_ReleaseMotorHardStop_FixedCurrent
const uint16_t K_ReleaseMotorHardStop_FixedCurrent_Level_1_Cal = 25U;   /*100 = 1A */ 
const uint16_t K_ReleaseMotorHardStop_FixedCurrent_Level_1_NoCal = 80U;   /*100 = 1A */ 
const uint16_t K_ReleaseMotorHardStop_FixedCurrent_Level_1_Time = 40U;   /*10ms x */
const uint16_t K_ReleaseMotorHardStop_FixedCurrent_Level_2_Cal = 30U;   /*100 = 1A */
const uint16_t K_ReleaseMotorHardStop_FixedCurrent_Level_2_NoCal = 100U;   /*100 = 1A */ 
const uint16_t K_ReleaseMotorHardStop_FixedCurrent_Level_2_Time = 10U;    /*10ms x */
const uint16_t K_ReleaseMotorHardStop_FixedCurrent_Level_3_Cal = 50U;    /*100 = 1A */
const uint16_t K_ReleaseMotorHardStop_FixedCurrent_Level_3_NoCal = 150U;    /*100 = 1A */ 
const uint16_t K_ReleaseMotorHardStop_FixedCurrent_Level_3_Time = 5U;     /*10ms x */
#endif

#ifdef _CONFIG_CinchMotorHardStop_EnhancedCurrent
const uint16_t K_CinchMotorHardStop_EnhancedCurrent_Detect = 40U;   /*100 = 1A */ 
const uint16_t K_CinchMotorHardStop_EnhancedCurrent_DecreasePerTimer = 1U;    /*10ms x */
const uint16_t K_CinchMotorHardStop_EnhancedCurrent_Decrease_Time = 2U;       /*10ms x */
const uint16_t K_CinchMotorHardStop_EnhancedCurrent_IncreasePerTimer = 5U;  /*10ms x */
const uint16_t K_CinchMotorHardStop_EnhancedCurrent_Increase_Time = 30U;      /*10ms x */
const uint16_t K_CinchMotorHardStop_EnhancedCurrent_Threshold_Time = 2U;     /*10ms x */ 
#endif
#ifdef _CONFIG_CinchMotorHardStop_FixedCurrent
const uint16_t K_CinchMotorHardStop_FixedCurrent_Level_1_Cal = 25U;   /*100 = 1A */ 
const uint16_t K_CinchMotorHardStop_FixedCurrent_Level_1_NoCal = 80U;   /*100 = 1A */ 
const uint16_t K_CinchMotorHardStop_FixedCurrent_Level_1_Time = 40U;   /*10ms x */
const uint16_t K_CinchMotorHardStop_FixedCurrent_Level_2_Cal = 30U;   /*100 = 1A */
const uint16_t K_CinchMotorHardStop_FixedCurrent_Level_2_NoCal = 100U;   /*100 = 1A */ 
const uint16_t K_CinchMotorHardStop_FixedCurrent_Level_2_Time = 10U;    /*10ms x */
const uint16_t K_CinchMotorHardStop_FixedCurrent_Level_3_Cal = 50U;    /*100 = 1A */
const uint16_t K_CinchMotorHardStop_FixedCurrent_Level_3_NoCal = 150U;    /*100 = 1A */ 
const uint16_t K_CinchMotorHardStop_FixedCurrent_Level_3_Time = 5U;     /*10ms x */
#endif

#endif


#ifdef _CONFIG_IntevaSideLatch_S20C
/*********************************************************************************************
**    Inteva Latch Control
*********************************************************************************************/
const uint16_t K_PowerCinchInSecondPosition_AfterPowerUp_Enable = TRUE;

const uint16_t K_LatchPreCinchCheck_Timeout = 200U; /* 1ms x  */
const uint16_t K_LatchPreCinchCheck_Timeout_LongDelay = 3000U; /* 1ms x  */
const uint16_t K_LatchPowerCinching_Timeout = 4000U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterCinch_Timeout = 4000U; /* 1ms x  */
const uint16_t K_LatchPreReleasing_Timeout = 4000U; /* 1ms x  */
const uint16_t K_LatchPowerReleasing_Timeout = 500U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterRelease_Timeout = 500U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterRelease_Mini_Time = 200U;//300U; /* 1ms x  */

const uint16_t K_LatchFindHomeReleaseDirection_Timeout = 4000U; /* 1ms x  */
const uint16_t K_LatchFindHomeCinchDirection_Timeout = 4000U; /* 1ms x  */
const uint16_t K_LatchFindHomeReleaseMotor_Timeout = 500U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterPark_Timeout = 500U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterBlip_Timeout = 2500U; /* 1ms x  */

const uint16_t K_LatchPreReleased_Timeout = 3000U; //15000U; //
const uint16_t K_LatchPreReleased_Timeout_LongDelay = 3000U; //15000U; //

const uint16_t K_LatchPreRelease_SnowLoad_Time = 3000U;
const uint16_t K_LatchCrankWait_Timeout = 2000U; /* 1ms x  */
const uint16_t K_LatchMechFailure_Timeout = 2000U;
const uint16_t K_LatchIceBreaking_Timeout = 4000U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterIceBreak_Timeout = 4000U; /* 1ms x  */

const uint16_t K_LatchPreCinchCheck_Time = 20U;//100U; /* 1ms x  */
const uint16_t K_LatchPreCinchCheck_Time_LongDelay = 2000U; /* 1ms x  */
const uint16_t K_PowerCinching_Delay_Time = 0U; /* 1ms x  */
const uint16_t K_PowerReleasing_PawlSwitch_Delay_Time = 100U; /* 1ms x  */ 
const uint16_t K_PowerReleasing_OutofLatch_Delay_Time = 0U;//50U; /* 1ms x  */ 
const uint16_t K_PreReleased_OutofLatch_Delay_Time = 100U;//500U; /* 1ms x  */
const uint16_t K_IceBreaking_OutofLatch_Delay_Time = 0U;//50U; /* 1ms x  */

const uint16_t K_StopBeforePowerReleasing_Time = 50U; /* 1ms x  */
const uint16_t K_StopBeforePreReleasing_Time = 100U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeAfterRelease_Time = 100U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeAfterPark_Time = 100U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeAfterBlip_Time = 100U; /* 1ms x  */
const uint16_t K_StopBeforeIceBreaking_Time = 100U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeAfterIceBreak_Time = 100U; /* 1ms x  */

const uint16_t K_CinchMotor_IncreaseStep_Duty = 3U; /* x% x  */
const uint16_t K_CinchMotor_DecreaseStep_Duty = 2U; /* x% x  */
const uint16_t K_ReleaseMotor_IncreaseStep_Duty = 5U; /* x% x  */
const uint16_t K_ReleaseMotor_DecreaseStep_Duty = 3U; /* x% x  */

const uint16_t K_MiniWorkingInCinchDirection_Time = 100U; /* 1ms x  */
const uint16_t K_ContinueFindHomeAfterRelease_Time = 100U; /* 1ms x  */
const uint16_t K_ContinueFindHomeAfterIceBreak_Time = 50U; /* 1ms x  */
const uint16_t K_ChangeDutyInFindHomeAfterRelease_Time = 10U;/* 1ms x  */
const uint16_t K_ChangeDutyInFindHomeAfterRelease_Time_2nd = 100U;///20U;/* 1ms x  */
const uint16_t K_ChangeDutyInFindHomeAfterRelease_Time_3rd = 0U;/* 1ms x  */

const uint16_t K_FindHomeAfterPark_PositionSwitch_Delay_Time = 50U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeReleaseMotor_Time = 100U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeCinchDirection_Time = 100U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeReleaseDirection_Time = 100U;  /* 1ms x  */
const uint16_t K_LatchFindHomeFailure_Timeout = 1500U;  /* 1ms x  */

const uint16_t K_FindHomeReleaseDirection_Inrush_Time = 100U; /* 1ms x  */
const uint16_t K_FindHomeCinchDirection_Inrush_Time = 100U; /* 1ms x  */
const uint16_t K_FindHomeReleaseMotor_Inrush_Time = 100U; /* 1ms x  */

const uint16_t K_PowerCinching_Inrush_Time = 100U; /* 1ms x  */
const uint16_t K_FindHomeAfterCinch_Inrush_Time = 100U; /* 1ms x  */
const uint16_t K_FindHomeAfterPark_Inrush_Time = 100U; /* 1ms x  */
const uint16_t K_PreReleasing_Inrush_Time = 100U; /* 1ms x  */
const uint16_t K_PowerReleasing_Inrush_Time = 100U; /* 1ms x  */
const uint16_t K_FindHomeAfterRelease_Inrush_Time = 100U; /* 1ms x  */
const uint16_t K_IceBreaking_Inrush_Time = 100U; /* 1ms x  */
const uint16_t K_FindHomeAfterIceBreak_Inrush_Time = 100U; /* 1ms x  */


const uint16_t K_PowerReleasing_Mini_Time = 200U; /* 1ms x  */
const uint16_t K_PreReleased_Mini_Time = 500U; /* 1ms x  */

const uint16_t K_WaitForPowerCinching_Time = 200U;/* 1ms x  */

const uint16_t K_FindHomeAfterCinch_StartDuty_Time = 50U;  /*10ms x */
const uint16_t K_FindHomeAfterCinch_DecreaseDuty_Time = 2U;   /* 10ms x  */
const uint16_t K_FindHomeAfterCinch_IncreaseDuty_Time = 1U;   /* 10ms x  */

const uint16_t K_CinchMotorFindHome_Count = 3;
const uint16_t K_PrimaryPositionIsArrived_Time= 2U;//10U;
const uint16_t K_ChangeDutyInFindHomeAfterCinch_Time = 100U; /* 1ms x  */
const uint16_t K_ChangeDutyInFindHomeAfterCinch_Time_2nd = 1200U; /* 1ms x  */
const uint16_t K_ChangeDutyInPowerCinching_Time = 700U; /* 1ms x  */
const uint16_t K_ChangeDutyInPowerCinching_Time_2nd = 800U; /* 1ms x  */
const uint16_t K_ChangeDutyInIceBreaking_Time = 500U; /* 1ms x  */
const uint16_t K_ChangeDutyInIceBreaking_Time_2nd = 500U; /* 1ms x  */
const uint16_t K_ChangeDutyInFindHomeAfterIceBreak_Time = 100U; /* 1ms x  */

const uint16_t K_CinchMotor_PowerCinching_Duty = 60U;
const uint16_t K_CinchMotor_PowerCinching_Duty_2nd = 0U;
const uint16_t K_CinchMotor_PowerCinching_Duty_2nd_LongDelay = 60U;
const uint16_t K_CinchMotor_PowerCinching_Duty_3rd = 60U;

const uint16_t K_CinchMotor_FindHomeAfterCinch_Duty = 20U;
const uint16_t K_CinchMotor_FindHomeAfterCinch_Duty_2nd = 50U;
const uint16_t K_CinchMotor_FindHomeAfterCinch_Duty_3rd = 50U;
const uint16_t K_CinchMotor_PreReleasing_Duty = 65U;

const uint16_t K_ContinueParking_Time = 0U;
const uint16_t K_ContinueParking_Time_2nd = 0U;

const uint16_t K_LowDutyFailFindHomeAfterCinch_Time = 3000U;/* 1ms x  */ 
const uint16_t K_LowDutyFailFindHomeAfterCinch_Duty = 100U; 
const uint16_t K_LowDutyFailPowerCinching_Time = 3000U;/* 1ms x  */ 
const uint16_t K_LowDutyFailPowerCinching_Duty = 100U;
const uint16_t K_LowDutyFailIceBreaking_Time = 2000U;/* 1ms x  */ 
const uint16_t K_LowDutyFailIceBreaking_Duty = 100U;
const uint16_t K_LowDutyFailFindHomeAfterIceBreak_Time = 2000U;/* 1ms x  */ 
const uint16_t K_LowDutyFailFindHomeAfterIceBreak_Duty = 100U;

const uint16_t K_ReleaseMotor_FindHomeAfterRelease_Duty = 10U; 
const uint16_t K_ReleaseMotor_FindHomeAfterRelease_Duty_2nd = 40U;//60U;
const uint16_t K_ReleaseMotor_FindHomeAfterRelease_Duty_3rd = 40U;//20U;
const uint16_t K_ReleaseMotor_FindHomeAfterRelease_Duty_4th = 100U;//60U;


const uint16_t K_CinchMotor_FindHomeAfterRelease_Duty = 80U;
const uint16_t K_CinchMotor_FindHomeAfterRelease_Duty_2nd = 80U;
const uint16_t K_CinchMotor_FindHomeAfterRelease_Duty_3rd = 80U;

const uint16_t K_CinchMotor_FindHomeReleaseDirection_Duty = 100U;
const uint16_t K_CinchMotor_FindHomeReleaseDirection_Duty_2nd = 55U;
const uint16_t K_CinchMotor_FindHomeCinchDirection_Duty = 60U;
const uint16_t K_CinchMotor_FindHomeCinchDirection_Duty_2nd = 60U;

const uint16_t K_ReleaseMotor_FindHomeReleaseMotor_Duty = 60U;
const uint16_t K_ReleaseMotor_FindHomeReleaseMotor_Duty_2nd = 60U;

const uint16_t K_CinchMotor_FindHomeAfterPark_Duty = 60U;
const uint16_t K_CinchMotor_FindHomeAfterBlip_Duty = 60U;

const uint16_t K_ReleaseMotor_PowerReleasing_Duty = 80U; 
const uint16_t K_ReleaseMotor_PowerReleasing_Duty_2nd = 80U; 
const uint16_t K_CinchMotor_PowerReleasing_Duty = 100U;
const uint16_t K_CinchMotor_PowerReleasing_Duty_2nd = 80U;

const uint16_t K_CinchMotor_IceBreaking_Duty = 65U;
const uint16_t K_CinchMotor_IceBreaking_Duty_2nd = 65U;
const uint16_t K_CinchMotor_IceBreaking_Duty_3rd = 65U;
const uint16_t K_CinchMotor_FindHomeAfterIceBreak_Duty = 100U;
const uint16_t K_CinchMotor_FindHomeAfterIceBreak_Duty_2nd = 55U;

const uint16_t K_PowerReleasing_ComfirmCurrent = 200U;

const uint16_t K_PowerCinching_SoftStall_Current = 1500U;
const uint16_t K_FindHomeAfterCinch_SoftStall_Current = 1500U;
const uint16_t K_PreReleasing_SoftStall_Current = 1500U;
const uint16_t K_PowerReleasing_SoftStall_Current = 1500U;
const uint16_t K_FindHomeAfterRelease_SoftStall_Current = 1500U;
const uint16_t K_FindHomeReleaseDirection_SoftStall_Current = 1000U;
const uint16_t K_FindHomeCinchDirection_SoftStall_Current = 1000U;
const uint16_t K_FindHomeAfterPark_SoftStall_Current = 1500U;

const uint16_t K_IceBreaking_SoftStall_Current = 1500U;
const uint16_t K_FindHomeAfterIceBreak_SoftStall_Current = 1500U;
const uint16_t K_FindHomeReleaseMotor_SoftStall_Current = 1500U;


const uint16_t K_PowerCinching_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeAfterCinch_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_PreReleasing_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_PowerReleasing_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeAfterRelease_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeReleaseDirection_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeCinchDirection_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeReleaseMotor_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeAfterPark_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_IceBreaking_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeAfterIceBreak_SoftStall_Time = 10U; /* 10ms x  */
 
const uint16_t K_StopBeforeFindHomeAfterCinch_Time = 20U;  /* 1ms x  */
const uint16_t K_LatchNotLeaveHomeInMiniPowerCinch_Time = 50U; /* 1ms x  */
const uint16_t K_LatchNotLeaveHomeInMiniIceBreak_Time = 50U; /* 1ms x  */

const uint16_t K_PowerReleasing_ComfirmCurrent_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeAfterCinch_Work_MiniTime = 20U; /* 10ms x  */ 
const uint16_t K_ChangeDutyInFindHomeReleaseDirection_Time = 5U; /* 10ms x  */
const uint16_t K_ChangeDutyInFindHomeCinchDirection_Time = 5U; /* 10ms x  */
const uint16_t K_ChangeDutyInFindHomeReleaseMotor_Time = 5U; /* 10ms x  */
const uint16_t K_LatchFullyReleased_Braking_Timeout = 10U; /* 10ms x  */
const uint16_t K_LatchFullyCinched_Braking_Timeout = 10U; /* 10ms x  */
const uint16_t K_LatchPreReleased_Braking_Timeout = 10U; /* 10ms x  */


#ifdef _CONFIG_ReleaseMotorHardStop_EnhancedCurrent
const uint16_t K_ReleaseMotorHardStop_EnhancedCurrent_Detect = 40U;   /*100 = 1A */ 
const uint16_t K_ReleaseMotorHardStop_EnhancedCurrent_DecreasePerTimer = 1U;    /*10ms x */
const uint16_t K_ReleaseMotorHardStop_EnhancedCurrent_Decrease_Time = 2U;       /*10ms x */
const uint16_t K_ReleaseMotorHardStop_EnhancedCurrent_IncreasePerTimer = 5U;  /*10ms x */
const uint16_t K_ReleaseMotorHardStop_EnhancedCurrent_Increase_Time = 30U;      /*10ms x */
const uint16_t K_ReleaseMotorHardStop_EnhancedCurrent_Threshold_Time = 2U;     /*10ms x */ 
#endif
#ifdef _CONFIG_ReleaseMotorHardStop_FixedCurrent
const uint16_t K_ReleaseMotorHardStop_FixedCurrent_Level_1_Cal = 25U;   /*100 = 1A */ 
const uint16_t K_ReleaseMotorHardStop_FixedCurrent_Level_1_NoCal = 80U;   /*100 = 1A */ 
const uint16_t K_ReleaseMotorHardStop_FixedCurrent_Level_1_Time = 40U;   /*10ms x */
const uint16_t K_ReleaseMotorHardStop_FixedCurrent_Level_2_Cal = 30U;   /*100 = 1A */
const uint16_t K_ReleaseMotorHardStop_FixedCurrent_Level_2_NoCal = 100U;   /*100 = 1A */ 
const uint16_t K_ReleaseMotorHardStop_FixedCurrent_Level_2_Time = 10U;    /*10ms x */
const uint16_t K_ReleaseMotorHardStop_FixedCurrent_Level_3_Cal = 50U;    /*100 = 1A */
const uint16_t K_ReleaseMotorHardStop_FixedCurrent_Level_3_NoCal = 150U;    /*100 = 1A */ 
const uint16_t K_ReleaseMotorHardStop_FixedCurrent_Level_3_Time = 5U;     /*10ms x */
#endif

#ifdef _CONFIG_CinchMotorHardStop_EnhancedCurrent
const uint16_t K_CinchMotorHardStop_EnhancedCurrent_Detect = 40U;   /*100 = 1A */ 
const uint16_t K_CinchMotorHardStop_EnhancedCurrent_DecreasePerTimer = 1U;    /*10ms x */
const uint16_t K_CinchMotorHardStop_EnhancedCurrent_Decrease_Time = 2U;       /*10ms x */
const uint16_t K_CinchMotorHardStop_EnhancedCurrent_IncreasePerTimer = 5U;  /*10ms x */
const uint16_t K_CinchMotorHardStop_EnhancedCurrent_Increase_Time = 30U;      /*10ms x */
const uint16_t K_CinchMotorHardStop_EnhancedCurrent_Threshold_Time = 2U;     /*10ms x */ 
#endif
#ifdef _CONFIG_CinchMotorHardStop_FixedCurrent
const uint16_t K_CinchMotorHardStop_FixedCurrent_Level_1_Cal = 25U;   /*100 = 1A */ 
const uint16_t K_CinchMotorHardStop_FixedCurrent_Level_1_NoCal = 80U;   /*100 = 1A */ 
const uint16_t K_CinchMotorHardStop_FixedCurrent_Level_1_Time = 40U;   /*10ms x */
const uint16_t K_CinchMotorHardStop_FixedCurrent_Level_2_Cal = 30U;   /*100 = 1A */
const uint16_t K_CinchMotorHardStop_FixedCurrent_Level_2_NoCal = 100U;   /*100 = 1A */ 
const uint16_t K_CinchMotorHardStop_FixedCurrent_Level_2_Time = 10U;    /*10ms x */
const uint16_t K_CinchMotorHardStop_FixedCurrent_Level_3_Cal = 50U;    /*100 = 1A */
const uint16_t K_CinchMotorHardStop_FixedCurrent_Level_3_NoCal = 150U;    /*100 = 1A */ 
const uint16_t K_CinchMotorHardStop_FixedCurrent_Level_3_Time = 5U;     /*10ms x */
#endif

#endif


#ifdef _CONFIG_MagnaSideLatch_CCL
/*********************************************************************************************
**    Inteva Latch Control
*********************************************************************************************/
const uint16_t K_PowerCinchInSecondPosition_AfterPowerUp_Enable = TRUE;

const uint16_t K_LatchPreCinchCheck_Timeout = 200U; /* 1ms x  */
const uint16_t K_LatchPreCinchCheck_Timeout_LongDelay = 3000U; /* 1ms x  */
const uint16_t K_LatchPowerCinching_Timeout = 4000U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterCinch_Timeout = 4000U; /* 1ms x  */
const uint16_t K_LatchPreReleasing_Timeout = 4000U; /* 1ms x  */
const uint16_t K_LatchPowerReleasing_Timeout = 500U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterRelease_Timeout = 500U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterRelease_Mini_Time = 300U; /* 1ms x  */

const uint16_t K_LatchFindHomeReleaseDirection_Timeout = 4000U; /* 1ms x  */
const uint16_t K_LatchFindHomeCinchDirection_Timeout = 4000U; /* 1ms x  */
const uint16_t K_LatchFindHomeReleaseMotor_Timeout = 500U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterPark_Timeout = 500U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterBlip_Timeout = 2500U; /* 1ms x  */

const uint16_t K_LatchPreReleased_Timeout = 5000U; //15000U; //
const uint16_t K_LatchPreReleased_Timeout_LongDelay = 5000U; //15000U; //

const uint16_t K_LatchPreRelease_SnowLoad_Time = 3000U;
const uint16_t K_LatchCrankWait_Timeout = 2000U; /* 1ms x  */
const uint16_t K_LatchMechFailure_Timeout = 2000U;
const uint16_t K_LatchIceBreaking_Timeout = 4000U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterIceBreak_Timeout = 4000U; /* 1ms x  */
const uint16_t K_LatchUnlock_Timeout = 1000U; /* 1ms x  */
const uint16_t K_LatchUnlockReset_Timeout = 1000U; /* 1ms x  */

const uint16_t K_LatchPreCinchCheck_Time = 200U;//100U; /* 1ms x  */
const uint16_t K_LatchPreCinchCheck_Time_LongDelay = 2000U; /* 1ms x  */
const uint16_t K_PowerCinching_Delay_Time = 0U; /* 1ms x  */
const uint16_t K_PowerReleasing_PawlSwitch_Delay_Time = 100U; /* 1ms x  */ 
const uint16_t K_PowerReleasing_OutofLatch_Delay_Time = 0U;//50U; /* 1ms x  */ 
const uint16_t K_PreReleased_OutofLatch_Delay_Time = 100U;//500U; /* 1ms x  */
const uint16_t K_IceBreaking_OutofLatch_Delay_Time = 0U;//50U; /* 1ms x  */
const uint16_t K_PowerUnlock_UnlockSwitch_Delay_Time = 30U; /* 1ms x  */ 
const uint16_t K_PowerLock_UnlockSwitch_Delay_Time = 0U; /* 1ms x  */ 

const uint16_t K_StopBeforePowerReleasing_Time = 50U; /* 1ms x  */
const uint16_t K_StopBeforePowerReleasing_CinchMotorBrake_Time = 200U; /* 1ms x  */
const uint16_t K_StopBeforePreReleasing_Time = 100U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeAfterRelease_Time = 200U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeAfterPark_Time = 100U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeAfterBlip_Time = 100U; /* 1ms x  */
const uint16_t K_StopBeforeIceBreaking_Time = 100U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeAfterIceBreak_Time = 100U; /* 1ms x  */

const uint16_t K_CinchMotor_IncreaseStep_Duty = 3U; /* x% x  */
const uint16_t K_CinchMotor_DecreaseStep_Duty = 2U; /* x% x  */
const uint16_t K_ReleaseMotor_IncreaseStep_Duty = 5U; /* x% x  */
const uint16_t K_ReleaseMotor_DecreaseStep_Duty = 3U; /* x% x  */

const uint16_t K_MiniWorkingInCinchDirection_Time = 100U; /* 1ms x  */
const uint16_t K_ContinueFindHomeAfterRelease_Time = 100U; /* 1ms x  */
const uint16_t K_ContinueFindHomeAfterIceBreak_Time = 50U; /* 1ms x  */
const uint16_t K_ChangeDutyInFindHomeAfterRelease_Time = 10U;/* 1ms x  */
const uint16_t K_ChangeDutyInFindHomeAfterRelease_Time_2nd = 100U;///20U;/* 1ms x  */
const uint16_t K_ChangeDutyInFindHomeAfterRelease_Time_3rd = 0U;/* 1ms x  */

const uint16_t K_FindHomeAfterPark_PositionSwitch_Delay_Time = 50U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeReleaseMotor_Time = 100U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeCinchDirection_Time = 100U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeReleaseDirection_Time = 100U;  /* 1ms x  */
const uint16_t K_LatchFindHomeFailure_Timeout = 1500U;  /* 1ms x  */

const uint16_t K_FindHomeReleaseDirection_Inrush_Time = 100U; /* 1ms x  */
const uint16_t K_FindHomeCinchDirection_Inrush_Time = 100U; /* 1ms x  */
const uint16_t K_FindHomeReleaseMotor_Inrush_Time = 100U; /* 1ms x  */

const uint16_t K_PowerCinching_Inrush_Time = 100U; /* 1ms x  */
const uint16_t K_FindHomeAfterCinch_Inrush_Time = 100U; /* 1ms x  */
const uint16_t K_FindHomeAfterPark_Inrush_Time = 100U; /* 1ms x  */
const uint16_t K_PreReleasing_Inrush_Time = 100U; /* 1ms x  */
const uint16_t K_PowerReleasing_Inrush_Time = 100U; /* 1ms x  */
const uint16_t K_FindHomeAfterRelease_Inrush_Time = 100U; /* 1ms x  */
const uint16_t K_IceBreaking_Inrush_Time = 100U; /* 1ms x  */
const uint16_t K_FindHomeAfterIceBreak_Inrush_Time = 100U; /* 1ms x  */
const uint16_t K_PowerUnlock_Inrush_Time = 100U; /* 1ms x  */


const uint16_t K_PowerReleasing_Mini_Time = 120U; /* 1ms x  */
const uint16_t K_PreReleased_Mini_Time = 500U; /* 1ms x  */
const uint16_t K_PowerUnlock_Mini_Time = 0U; /* 1ms x  */
const uint16_t K_PowerUnlockReset_Mini_Time = 40U; /* 1ms x  */

const uint16_t K_WaitForPowerCinching_Time = 200U;/* 1ms x  */

const uint16_t K_FindHomeAfterCinch_StartDuty_Time = 50U;  /*10ms x */
const uint16_t K_FindHomeAfterCinch_DecreaseDuty_Time = 2U;   /* 10ms x  */
const uint16_t K_FindHomeAfterCinch_IncreaseDuty_Time = 1U;   /* 10ms x  */

const uint16_t K_CinchMotorFindHome_Count = 3;
const uint16_t K_PrimaryPositionIsArrived_Time= 5U;//10U;
const uint16_t K_ChangeDutyInFindHomeAfterCinch_Time = 100U; /* 1ms x  */
const uint16_t K_ChangeDutyInFindHomeAfterCinch_Time_2nd = 1200U; /* 1ms x  */
const uint16_t K_ChangeDutyInPowerCinching_Time = 700U; /* 1ms x  */
const uint16_t K_ChangeDutyInPowerCinching_Time_2nd = 800U; /* 1ms x  */
const uint16_t K_ChangeDutyInIceBreaking_Time = 500U; /* 1ms x  */
const uint16_t K_ChangeDutyInIceBreaking_Time_2nd = 500U; /* 1ms x  */
const uint16_t K_ChangeDutyInFindHomeAfterIceBreak_Time = 100U; /* 1ms x  */

const uint16_t K_CinchMotor_PowerCinching_Duty = 100U;
const uint16_t K_CinchMotor_PowerCinching_Duty_2nd = 100U;
const uint16_t K_CinchMotor_PowerCinching_Duty_2nd_LongDelay = 100U;
const uint16_t K_CinchMotor_PowerCinching_Duty_3rd = 100U;

const uint16_t K_CinchMotor_FindHomeAfterCinch_Duty = 75U;
const uint16_t K_CinchMotor_FindHomeAfterCinch_Duty_2nd = 75U;
const uint16_t K_CinchMotor_FindHomeAfterCinch_Duty_3rd = 75U;
const uint16_t K_CinchMotor_PreReleasing_Duty = 65U;

const uint16_t K_ContinueParking_Time = 0U;
const uint16_t K_ContinueParking_Time_2nd = 0U;

const uint16_t K_LowDutyFailFindHomeAfterCinch_Time = 3000U;/* 1ms x  */ 
const uint16_t K_LowDutyFailFindHomeAfterCinch_Duty = 100U; 
const uint16_t K_LowDutyFailPowerCinching_Time = 3000U;/* 1ms x  */ 
const uint16_t K_LowDutyFailPowerCinching_Duty = 100U;
const uint16_t K_LowDutyFailIceBreaking_Time = 2000U;/* 1ms x  */ 
const uint16_t K_LowDutyFailIceBreaking_Duty = 100U;
const uint16_t K_LowDutyFailFindHomeAfterIceBreak_Time = 2000U;/* 1ms x  */ 
const uint16_t K_LowDutyFailFindHomeAfterIceBreak_Duty = 100U;

const uint16_t K_ReleaseMotor_FindHomeAfterRelease_Duty = 75U; 
const uint16_t K_ReleaseMotor_FindHomeAfterRelease_Duty_2nd = 75U;//60U;
const uint16_t K_ReleaseMotor_FindHomeAfterRelease_Duty_3rd = 75U;//20U;
const uint16_t K_ReleaseMotor_FindHomeAfterRelease_Duty_4th = 75U;//60U;


const uint16_t K_CinchMotor_FindHomeAfterRelease_Duty = 80U;
const uint16_t K_CinchMotor_FindHomeAfterRelease_Duty_2nd = 80U;
const uint16_t K_CinchMotor_FindHomeAfterRelease_Duty_3rd = 80U;

const uint16_t K_CinchMotor_FindHomeReleaseDirection_Duty = 100U;
const uint16_t K_CinchMotor_FindHomeReleaseDirection_Duty_2nd = 55U;
const uint16_t K_CinchMotor_FindHomeCinchDirection_Duty = 60U;
const uint16_t K_CinchMotor_FindHomeCinchDirection_Duty_2nd = 60U;

const uint16_t K_ReleaseMotor_FindHomeReleaseMotor_Duty = 60U;
const uint16_t K_ReleaseMotor_FindHomeReleaseMotor_Duty_2nd = 60U;

const uint16_t K_CinchMotor_FindHomeAfterPark_Duty = 60U;
const uint16_t K_CinchMotor_FindHomeAfterBlip_Duty = 60U;

const uint16_t K_ReleaseMotor_PowerReleasing_Duty = 100U; 
const uint16_t K_ReleaseMotor_PowerReleasing_Duty_2nd = 100U; 
const uint16_t K_CinchMotor_PowerReleasing_Duty = 100U;
const uint16_t K_CinchMotor_PowerReleasing_Duty_2nd = 80U;

const uint16_t K_CinchMotor_IceBreaking_Duty = 65U;
const uint16_t K_CinchMotor_IceBreaking_Duty_2nd = 65U;
const uint16_t K_CinchMotor_IceBreaking_Duty_3rd = 65U;
const uint16_t K_CinchMotor_FindHomeAfterIceBreak_Duty = 100U;
const uint16_t K_CinchMotor_FindHomeAfterIceBreak_Duty_2nd = 55U;

const uint16_t K_ReleaseMotor_PowerUnlock_Duty = 100U; 
const uint16_t K_ReleaseMotor_PowerUnlock_Duty_2nd = 100U; 
const uint16_t K_ReleaseMotor_PowerUnlockReset_Duty = 40U; 
const uint16_t K_ReleaseMotor_PowerUnlockReset_Duty_2nd = 40U; 

const uint16_t K_PowerReleasing_ComfirmCurrent = 200U;

const uint16_t K_PowerCinching_SoftStall_Current = 1500U;
const uint16_t K_FindHomeAfterCinch_SoftStall_Current = 1500U;
const uint16_t K_PreReleasing_SoftStall_Current = 1500U;
const uint16_t K_PowerReleasing_SoftStall_Current = 1500U;
const uint16_t K_FindHomeAfterRelease_SoftStall_Current = 1500U;
const uint16_t K_FindHomeReleaseDirection_SoftStall_Current = 1000U;
const uint16_t K_FindHomeCinchDirection_SoftStall_Current = 1000U;
const uint16_t K_FindHomeAfterPark_SoftStall_Current = 1500U;

const uint16_t K_IceBreaking_SoftStall_Current = 1500U;
const uint16_t K_FindHomeAfterIceBreak_SoftStall_Current = 1500U;
const uint16_t K_FindHomeReleaseMotor_SoftStall_Current = 1500U;


const uint16_t K_PowerCinching_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeAfterCinch_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_PreReleasing_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_PowerReleasing_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeAfterRelease_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeReleaseDirection_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeCinchDirection_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeReleaseMotor_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeAfterPark_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_IceBreaking_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeAfterIceBreak_SoftStall_Time = 10U; /* 10ms x  */
 
const uint16_t K_StopBeforeFindHomeAfterCinch_Time = 20U;  /* 1ms x  */
const uint16_t K_LatchNotLeaveHomeInMiniPowerCinch_Time = 50U; /* 1ms x  */
const uint16_t K_LatchNotLeaveHomeInMiniIceBreak_Time = 50U; /* 1ms x  */

const uint16_t K_PowerReleasing_ComfirmCurrent_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeAfterCinch_Work_MiniTime = 20U; /* 10ms x  */ 
const uint16_t K_ChangeDutyInFindHomeReleaseDirection_Time = 5U; /* 10ms x  */
const uint16_t K_ChangeDutyInFindHomeCinchDirection_Time = 5U; /* 10ms x  */
const uint16_t K_ChangeDutyInFindHomeReleaseMotor_Time = 5U; /* 10ms x  */
const uint16_t K_LatchFullyReleased_Braking_Timeout = 10U; /* 10ms x  */
const uint16_t K_LatchFullyCinched_Braking_Timeout = 10U; /* 10ms x  */
const uint16_t K_LatchPreReleased_Braking_Timeout = 500U; /* 10ms x  */


#ifdef _CONFIG_ReleaseMotorHardStop_EnhancedCurrent
const uint16_t K_ReleaseMotorHardStop_EnhancedCurrent_Detect = 40U;   /*100 = 1A */ 
const uint16_t K_ReleaseMotorHardStop_EnhancedCurrent_DecreasePerTimer = 1U;    /*10ms x */
const uint16_t K_ReleaseMotorHardStop_EnhancedCurrent_Decrease_Time = 2U;       /*10ms x */
const uint16_t K_ReleaseMotorHardStop_EnhancedCurrent_IncreasePerTimer = 5U;  /*10ms x */
const uint16_t K_ReleaseMotorHardStop_EnhancedCurrent_Increase_Time = 30U;      /*10ms x */
const uint16_t K_ReleaseMotorHardStop_EnhancedCurrent_Threshold_Time = 2U;     /*10ms x */ 
#endif
#ifdef _CONFIG_ReleaseMotorHardStop_FixedCurrent
const uint16_t K_ReleaseMotorHardStop_FixedCurrent_Level_1_Cal = 25U;   /*100 = 1A */ 
const uint16_t K_ReleaseMotorHardStop_FixedCurrent_Level_1_NoCal = 80U;   /*100 = 1A */ 
const uint16_t K_ReleaseMotorHardStop_FixedCurrent_Level_1_Time = 40U;   /*10ms x */
const uint16_t K_ReleaseMotorHardStop_FixedCurrent_Level_2_Cal = 30U;   /*100 = 1A */
const uint16_t K_ReleaseMotorHardStop_FixedCurrent_Level_2_NoCal = 100U;   /*100 = 1A */ 
const uint16_t K_ReleaseMotorHardStop_FixedCurrent_Level_2_Time = 10U;    /*10ms x */
const uint16_t K_ReleaseMotorHardStop_FixedCurrent_Level_3_Cal = 50U;    /*100 = 1A */
const uint16_t K_ReleaseMotorHardStop_FixedCurrent_Level_3_NoCal = 150U;    /*100 = 1A */ 
const uint16_t K_ReleaseMotorHardStop_FixedCurrent_Level_3_Time = 5U;     /*10ms x */
#endif

#ifdef _CONFIG_CinchMotorHardStop_EnhancedCurrent
const uint16_t K_CinchMotorHardStop_EnhancedCurrent_Detect = 40U;   /*100 = 1A */ 
const uint16_t K_CinchMotorHardStop_EnhancedCurrent_DecreasePerTimer = 1U;    /*10ms x */
const uint16_t K_CinchMotorHardStop_EnhancedCurrent_Decrease_Time = 2U;       /*10ms x */
const uint16_t K_CinchMotorHardStop_EnhancedCurrent_IncreasePerTimer = 5U;  /*10ms x */
const uint16_t K_CinchMotorHardStop_EnhancedCurrent_Increase_Time = 30U;      /*10ms x */
const uint16_t K_CinchMotorHardStop_EnhancedCurrent_Threshold_Time = 2U;     /*10ms x */ 
#endif
#ifdef _CONFIG_CinchMotorHardStop_FixedCurrent
const uint16_t K_CinchMotorHardStop_FixedCurrent_Level_1_Cal = 25U;   /*100 = 1A */ 
const uint16_t K_CinchMotorHardStop_FixedCurrent_Level_1_NoCal = 80U;   /*100 = 1A */ 
const uint16_t K_CinchMotorHardStop_FixedCurrent_Level_1_Time = 40U;   /*10ms x */
const uint16_t K_CinchMotorHardStop_FixedCurrent_Level_2_Cal = 30U;   /*100 = 1A */
const uint16_t K_CinchMotorHardStop_FixedCurrent_Level_2_NoCal = 100U;   /*100 = 1A */ 
const uint16_t K_CinchMotorHardStop_FixedCurrent_Level_2_Time = 10U;    /*10ms x */
const uint16_t K_CinchMotorHardStop_FixedCurrent_Level_3_Cal = 50U;    /*100 = 1A */
const uint16_t K_CinchMotorHardStop_FixedCurrent_Level_3_NoCal = 150U;    /*100 = 1A */ 
const uint16_t K_CinchMotorHardStop_FixedCurrent_Level_3_Time = 5U;     /*10ms x */
#endif

#endif

#ifdef _CONFIG_IntevaLatch_SL5
/*********************************************************************************************
**    Inteva SL5 Latch Control
*********************************************************************************************/
const uint16_t K_PowerCinchInSecondPosition_AfterPowerUp_Enable = TRUE;

const uint16_t K_LatchPreCinchCheck_Timeout = 2000U; /* 1ms x  */
const uint16_t K_LatchPowerCinching_Timeout = 3000U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterCinch_Timeout = 4000U; /* 1ms x  */
const uint16_t K_LatchPreReleasing_Timeout = 5000U; /* 1ms x  */
const uint16_t K_LatchPowerReleasing_Timeout = 3000U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterRelease_Timeout = 3000U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterRelease_Mini_Time = 100U; /* 1ms x  */

const uint16_t K_LatchFindHomeReleaseDirection_Timeout = 4000U; /* 1ms x  */
const uint16_t K_LatchFindHomeCinchDirection_Timeout = 500U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterPark_Timeout = 5000U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterBlip_Timeout = 100U; /* 1ms x  */

const uint16_t K_LatchPreReleased_Timeout = 3000U; 
const uint16_t K_LatchPreRelease_SnowLoad_Time = 3000U;
const uint16_t K_LatchCrankWait_Timeout = 2000U; /* 1ms x  */
const uint16_t K_LatchMechFailure_Timeout = 2000U;

const uint16_t K_LatchPreCinchCheck_Time = 100U; /* 1ms x  */



const uint16_t K_PowerReleasing_PawlSwitch_Delay_Time = 100U; /* 1ms x  */ 
const uint16_t K_PowerReleasing_OutofLatch_Delay_Time = 50U; /* 1ms x  */ 
const uint16_t K_PowerCinching_Delay_Time = 30U; /* 1ms x  */
const uint16_t K_PreReleased_OutofLatch_Delay_Time = 100U;//500U; /* 1ms x  */

const uint16_t K_StopBeforePowerReleasing_Time = 0U; /* 1ms x  */
const uint16_t K_StopBeforePreReleasing_Time = 0U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeAfterRelease_Time = 50U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeAfterPark_Time = 50U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeAfterBlip_Time = 50U; /* 1ms x  */
const uint16_t K_MiniWorkingInCinchDirection_Time = 100U; /* 1ms x  */
const uint16_t K_ContinueFindHomeAfterRelease_Time = 20U; /* 1ms x  */
const uint16_t K_ChangeDutyInFindHomeAfterRelease_Time = 50U;/* 1ms x  */
const uint16_t K_FindHomeAfterPark_PositionSwitch_Delay_Time = 100U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeCinchDirection_Time = 100U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeReleaseDirection_Time = 100U;  /* 1ms x  */
const uint16_t K_LatchFindHomeFailure_Timeout = 1000U;  /* 1ms x  */

const uint16_t K_FindHomeReleaseDirection_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_FindHomeCinchDirection_Inrush_Time = 200U; /* 1ms x  */

const uint16_t K_PowerCinching_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_FindHomeAfterCinch_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_FindHomeAfterPark_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_PreReleasing_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_PowerReleasing_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_FindHomeAfterRelease_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_PowerReleasing_Mini_Time = 200U; /* 1ms x  */

const uint16_t K_FindHomeAfterCinch_StartDuty_Time = 50U;  /*10ms x */
const uint16_t K_FindHomeAfterCinch_DecreaseDuty_Time = 2U;   /* 10ms x  */
const uint16_t K_FindHomeAfterCinch_IncreaseDuty_Time = 1U;   /* 10ms x  */

const uint16_t K_CinchMotorFindHome_Count = 3;
const uint16_t K_PrimaryPositionIsArrived_Time= 2U;
const uint16_t K_ChangeDutyInFindHomeAfterCinch_Time = 50U; /* 1ms x  */
const uint16_t K_ChangeDutyInFindHomeAfterCinch_Time_2nd = 100U; /* 1ms x  */

const uint16_t K_ChangeDutyInPowerCinching_Time = 3000U; /* 1ms x  */
const uint16_t K_CinchMotor_PowerCinching_Duty = 80U;
const uint16_t K_CinchMotor_PowerCinching_Duty_2nd = 100U;

const uint16_t K_CinchMotor_FindHomeAfterCinch_Duty = 60U;
const uint16_t K_CinchMotor_FindHomeAfterCinch_Duty_2nd = 60U;

const uint16_t K_ContinueParking_Time = 20U;
const uint16_t K_ContinueParking_Time_2nd = 20U;

const uint16_t K_LowDutyFailFindHomeAfterCinch_Time = 2500U;/* 1ms x  */ 
const uint16_t K_LowDutyFailFindHomeAfterCinch_Duty = 100U; 
const uint16_t K_LowDutyFailPowerCinching_Time = 1500U;/* 1ms x  */ 
const uint16_t K_LowDutyFailPowerCinching_Duty = 100U;

const uint16_t K_CinchMotor_FindHomeAfterRelease_Duty = 55U;
const uint16_t K_CinchMotor_FindHomeAfterRelease_Duty_2nd = 55U;
const uint16_t K_CinchMotor_FindHomeAfterRelease_Duty_3rd = 55U;

const uint16_t K_CinchMotor_FindHomeReleaseDirection_Duty = 55U;
const uint16_t K_CinchMotor_FindHomeReleaseDirection_Duty_2nd = 55U;
const uint16_t K_CinchMotor_FindHomeCinchDirection_Duty = 55U;
const uint16_t K_CinchMotor_FindHomeCinchDirection_Duty_2nd = 55U;


const uint16_t Huff_K_CinchMotor_FindHomeAfterPark_Duty = 60U;
const uint16_t Huff_K_CinchMotor_FindHomeAfterBlip_Duty = 30U;

const uint16_t K_ReleaseMotor_PowerReleasing_Duty = 100U;
const uint16_t K_ReleaseMotor_PowerReleasing_Duty_2nd = 100U;
const uint16_t K_CinchMotor_PowerReleasing_Duty = 100U;
const uint16_t K_CinchMotor_PowerReleasing_Duty_2nd = 100U;


const uint16_t K_PowerReleasing_ComfirmCurrent = 300U;

const uint16_t K_PowerCinching_SoftStall_Current = 1000U;
const uint16_t K_FindHomeAfterCinch_SoftStall_Current = 1000U;
const uint16_t K_PreReleasing_SoftStall_Current = 1000U;
const uint16_t K_PowerReleasing_SoftStall_Current = 1000U;
const uint16_t K_FindHomeAfterRelease_SoftStall_Current = 1000U;
const uint16_t K_FindHomeReleaseDirection_SoftStall_Current = 300U;
const uint16_t K_FindHomeCinchDirection_SoftStall_Current = 300U;
const uint16_t K_FindHomeAfterPark_SoftStall_Current = 1000U;


const uint16_t K_PowerCinching_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeAfterCinch_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_PreReleasing_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_PowerReleasing_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeAfterRelease_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeReleaseDirection_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeCinchDirection_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeAfterPark_SoftStall_Time = 10U; /* 10ms x  */
 
const uint16_t K_StopBeforeFindHomeAfterCinch_Time = 200U;  /* 1ms x  */
const uint16_t K_LatchNotLeaveHomeInMiniPowerCinch_Time = 10U; /* 1ms x  */

const uint16_t K_PowerReleasing_ComfirmCurrent_Time = 5U; /* 10ms x  */
const uint16_t K_FindHomeAfterCinch_Work_MiniTime = 20U; /* 10ms x  */ 
const uint16_t K_ChangeDutyInFindHomeReleaseDirection_Time = 200U; /* 10ms x  */
const uint16_t K_ChangeDutyInFindHomeCinchDirection_Time = 200U; /* 10ms x  */

#endif

#ifdef _CONFIG_HuffLatch
/*********************************************************************************************
**    Huff Latch Control
*********************************************************************************************/
const uint16_t Huff_K_PowerCinchInSecondPosition_AfterPowerUp_Enable = TRUE;
const uint16_t Huff_K_LatchPreCinchCheck_Timeout = 2000U; /* 1ms x  */

const uint16_t Huff_K_LatchPowerCinching_Timeout = 4000U; /* 1ms x  */
const uint16_t Huff_K_LatchFindHomeAfterCinch_Timeout = 3000U; /* 1ms x  */
const uint16_t Huff_K_LatchPowerReleasing_Timeout = 1000U; /* 1ms x  */
const uint16_t Huff_K_LatchFindHomeAfterRelease_Timeout = 1000U; /* 1ms x  */
const uint16_t Huff_K_ContinueFindHomeAfterRelease_Time = 100U; /* 1ms x  */

const uint16_t Huff_K_LatchPreReleasing_Timeout = 2000U; /* 1ms x  */
const uint16_t Huff_K_LatchFindHomeAfterRelease_Mini_Time = 100U; /* 1ms x  */
const uint16_t Huff_K_LatchFindHomeReleaseDirection_Timeout = 3000U; /* 1ms x  */
const uint16_t Huff_K_LatchFindHomeCinchDirection_Timeout = 500U; /* 1ms x  */
const uint16_t Huff_K_LatchFindHomeAfterPark_Timeout = 500U; /* 1ms x  */
const uint16_t Huff_K_LatchFindHomeAfterBlip_Timeout = 100U; /* 1ms x  */

const uint16_t Huff_K_LatchPreReleased_Timeout = 3000U; 
const uint16_t Huff_K_LatchPreRelease_SnowLoad_Time = 3000U;
const uint16_t Huff_K_LatchCrankWait_Timeout = 2000U; /* 1ms x  */
const uint16_t Huff_K_LatchMechFailure_Timeout = 2000U;
const uint16_t Huff_K_SnowLoad_Timeout_PowerCinching_Delay_Time = 5000U; /* 1ms x  */


const uint16_t Huff_K_LatchPreCinchCheck_Time = 100U; /* 1ms x  */
const uint16_t Huff_K_PowerReleasing_PawlSwitch_Delay_Time = 100U; /* 1ms x  */ 
const uint16_t Huff_K_PowerReleasing_OutofLatch_Delay_Time = 0U;//50U; /* 1ms x  */ 
const uint16_t Huff_K_PreReleasing_PositionSwitch_Delay_Time = 10U; /* 10ms x  */
const uint16_t Huff_K_PowerCinching_Delay_Time = 30U; /* 1ms x  */
const uint16_t Huff_K_PreReleased_OutofLatch_Delay_Time = 100U;//500U; /* 1ms x  */

const uint16_t Huff_K_StopBeforePowerReleasing_Time = 0U; /* 1ms x  */
const uint16_t Huff_K_StopBeforePreReleasing_Time = 0U; /* 1ms x  */
const uint16_t Huff_K_StopBeforeFindHomeAfterRelease_Time = 50U; /* 1ms x  */
const uint16_t Huff_K_StopBeforeFindHomeAfterPark_Time = 50U; /* 1ms x  */
const uint16_t Huff_K_StopBeforeFindHomeAfterBlip_Time = 50U; /* 1ms x  */
const uint16_t Huff_K_MiniWorkingInCinchDirection_Time = 100U; /* 1ms x  */
const uint16_t Huff_K_ChangeDutyInFindHomeAfterRelease_Time = 100U;/* 1ms x  */
const uint16_t Huff_K_FindHomeAfterPark_PositionSwitch_Delay_Time = 100U; /* 1ms x  */
const uint16_t Huff_K_StopBeforeFindHomeCinchDirection_Time = 100U; /* 1ms x  */
const uint16_t Huff_K_StopBeforeFindHomeReleaseDirection_Time = 100U;  /* 1ms x  */
const uint16_t Huff_K_LatchFindHomeFailure_Timeout = 1000U;  /* 1ms x  */

const uint16_t Huff_K_FindHomeReleaseDirection_Inrush_Time = 200U; /* 1ms x  */
const uint16_t Huff_K_FindHomeCinchDirection_Inrush_Time = 200U; /* 1ms x  */
const uint16_t Huff_K_PowerCinching_Inrush_Time = 200U; /* 1ms x  */
const uint16_t Huff_K_FindHomeAfterCinch_Inrush_Time = 200U; /* 1ms x  */
const uint16_t Huff_K_FindHomeAfterPark_Inrush_Time = 200U; /* 1ms x  */
const uint16_t Huff_K_PreReleasing_Inrush_Time = 200U; /* 1ms x  */
const uint16_t Huff_K_PowerReleasing_Inrush_Time = 200U; /* 1ms x  */
const uint16_t Huff_K_FindHomeAfterRelease_Inrush_Time = 200U; /* 1ms x  */
const uint16_t Huff_K_PowerReleasing_Mini_Time = 200U; /* 1ms x  */

const uint16_t Huff_K_FindHomeAfterCinch_StartDuty_Time = 50U;  /*10ms x */
const uint16_t Huff_K_FindHomeAfterCinch_DecreaseDuty_Time = 2U;   /* 10ms x  */
const uint16_t Huff_K_FindHomeAfterCinch_IncreaseDuty_Time = 1U;   /* 10ms x  */

const uint16_t Huff_K_CinchMotorFindHome_Count = 3;
const uint16_t Huff_K_PrimaryPositionIsArrived_Time= 2U;
const uint16_t Huff_K_ChangeDutyInFindHomeAfterCinch_Time = 300U; /* 1ms x  */
const uint16_t Huff_K_ChangeDutyInFindHomeAfterCinch_Time_2nd = 100U; /* 1ms x  */

const uint16_t Huff_K_ChangeDutyInPowerCinching_Time = 3000U; /* 1ms x  */

const uint16_t Huff_K_ContinueParking_Time = 50U;
const uint16_t Huff_K_ContinueParking_Time_2nd = 50U;

const uint16_t Huff_K_CinchMotor_PowerCinching_Duty = 100U;
const uint16_t Huff_K_CinchMotor_PowerCinching_Duty_2nd = 100U;

const uint16_t Huff_K_CinchMotor_FindHomeAfterCinch_Duty = 70U;
const uint16_t Huff_K_CinchMotor_FindHomeAfterCinch_Duty_2nd = 70U;

const uint16_t Huff_K_LowDutyFailFindHomeAfterCinch_Time = 6000U;/* 1ms x  */ 
const uint16_t Huff_K_LowDutyFailFindHomeAfterCinch_Duty = 60U; 

const uint16_t Huff_K_LowDutyFailPowerCinching_Time = 3200U;/* 1ms x  */ 
const uint16_t Huff_K_LowDutyFailPowerCinching_Duty = 100U;

const uint16_t Huff_K_CinchMotor_FindHomeAfterRelease_Duty = 70U;
const uint16_t Huff_K_CinchMotor_FindHomeAfterRelease_Duty_2nd = 70U;
const uint16_t Huff_K_CinchMotor_FindHomeAfterRelease_Duty_3rd = 70U;

const uint16_t Huff_K_CinchMotor_FindHomeReleaseDirection_Duty = 100U;
const uint16_t Huff_K_CinchMotor_FindHomeReleaseDirection_Duty_2nd = 50U;
const uint16_t Huff_K_CinchMotor_FindHomeCinchDirection_Duty = 100U;
const uint16_t Huff_K_CinchMotor_FindHomeCinchDirection_Duty_2nd = 50U;

const uint16_t Huff_K_CinchMotor_FindHomeAfterPark_Duty = 70U;
const uint16_t Huff_K_CinchMotor_FindHomeAfterBlip_Duty = 30U;

const uint16_t Huff_K_ReleaseMotor_PowerReleasing_Duty = 100U;
const uint16_t Huff_K_ReleaseMotor_PowerReleasing_Duty_2nd = 100U;
const uint16_t Huff_K_CinchMotor_PowerReleasing_Duty = 100U;
const uint16_t Huff_K_CinchMotor_PowerReleasing_Duty_2nd = 100U;


const uint16_t Huff_K_PowerReleasing_ComfirmCurrent = 300U;

const uint16_t Huff_K_PowerCinching_SoftStall_Current = 1000U;
const uint16_t Huff_K_FindHomeAfterCinch_SoftStall_Current = 1000U;
const uint16_t Huff_K_PreReleasing_SoftStall_Current = 1000U;
const uint16_t Huff_K_PowerReleasing_SoftStall_Current = 1000U;
const uint16_t Huff_K_FindHomeAfterRelease_SoftStall_Current = 1000U;
const uint16_t Huff_K_FindHomeReleaseDirection_SoftStall_Current = 300U;
const uint16_t Huff_K_FindHomeCinchDirection_SoftStall_Current = 300U;
const uint16_t Huff_K_FindHomeAfterPark_SoftStall_Current = 1000U;


const uint16_t Huff_K_PowerCinching_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t Huff_K_FindHomeAfterCinch_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t Huff_K_PreReleasing_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t Huff_K_PowerReleasing_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t Huff_K_FindHomeAfterRelease_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t Huff_K_FindHomeReleaseDirection_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t Huff_K_FindHomeCinchDirection_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t Huff_K_FindHomeAfterPark_SoftStall_Time = 10U; /* 10ms x  */
 
const uint16_t Huff_K_StopBeforeFindHomeAfterCinch_Time = 100U;  /* 1ms x  */
const uint16_t Huff_K_LatchNotLeaveHomeInMiniPowerCinch_Time = 0U; /* 1ms x  */

const uint16_t Huff_K_PowerReleasing_ComfirmCurrent_Time = 5U; /* 10ms x  */
const uint16_t Huff_K_FindHomeAfterCinch_Work_MiniTime = 20U; /* 10ms x  */ 
const uint16_t Huff_K_ChangeDutyInFindHomeReleaseDirection_Time = 200U; /* 10ms x  */
const uint16_t Huff_K_ChangeDutyInFindHomeCinchDirection_Time = 200U; /* 10ms x  */
#endif



#ifdef _CONFIG_XinrunHoodLatch 
/*********************************************************************************************
**    Ingin Latch Control
*********************************************************************************************/
const uint16_t K_PowerCinchInSecondPosition_AfterPowerUp_Enable = TRUE;

const uint16_t K_LatchPreCinchCheck_Timeout = 2000U; /* 1ms x  */
const uint16_t K_LatchPowerCinching_Timeout = 4000U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterCinch_Timeout = 4000U; /* 1ms x  */
const uint16_t K_LatchPowerReleasing_Timeout = 2000U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterRelease_Timeout = 1000U; /* 1ms x  */
const uint16_t K_ContinueFindHomeAfterRelease_Time = 100U; /* 1ms x  */

const uint16_t K_LatchPreReleasing_Timeout = 4000U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterRelease_Mini_Time = 100U; /* 1ms x  */
const uint16_t K_LatchFindHomeReleaseDirection_Timeout = 5000U; /* 1ms x  */
const uint16_t K_LatchFindHomeCinchDirection_Timeout = 500U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterPark_Timeout = 500U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterBlip_Timeout = 100U; /* 1ms x  */

const uint16_t K_LatchPreReleased_Timeout = 3000U; 
const uint16_t K_LatchPreRelease_SnowLoad_Time = 3000U;
const uint16_t K_LatchCrankWait_Timeout = 2000U; /* 1ms x  */
const uint16_t K_LatchMechFailure_Timeout = 2000U;

const uint16_t K_LatchPreCinchCheck_Time = 100U; /* 1ms x  */


const uint16_t K_PowerReleasing_PawlSwitch_Delay_Time = 100U; /* 1ms x  */ 
const uint16_t K_PowerReleasing_OutofLatch_Delay_Time = 0U;//50U; /* 1ms x  */ 

const uint16_t K_CinchMotor_IncreaseStep_Duty = 1U; /* x% x  */
const uint16_t K_PowerCinching_Delay_Time = 30U; /* 1ms x  */
const uint16_t K_PreReleased_OutofLatch_Delay_Time = 100U;//500U; /* 1ms x  */
const uint16_t K_SnowLoad_Timeout_PowerCinching_Delay_Time = 3000U; /* 1ms x  */

const uint16_t K_StopBeforePowerReleasing_Time = 0U; /* 1ms x  */
const uint16_t K_StopBeforePreReleasing_Time = 0U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeAfterRelease_Time = 50U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeAfterPark_Time = 50U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeAfterBlip_Time = 50U; /* 1ms x  */
const uint16_t K_MiniWorkingInCinchDirection_Time = 100U; /* 1ms x  */
const uint16_t K_ChangeDutyInFindHomeAfterRelease_Time = 100U;/* 1ms x  */
const uint16_t K_FindHomeAfterPark_PositionSwitch_Delay_Time = 100U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeCinchDirection_Time = 100U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeReleaseDirection_Time = 100U;  /* 1ms x  */
const uint16_t K_LatchFindHomeFailure_Timeout = 1000U;  /* 1ms x  */

const uint16_t K_FindHomeReleaseDirection_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_FindHomeCinchDirection_Inrush_Time = 200U; /* 1ms x  */

const uint16_t K_PowerCinching_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_FindHomeAfterCinch_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_FindHomeAfterPark_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_PreReleasing_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_PowerReleasing_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_FindHomeAfterRelease_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_PowerReleasing_Mini_Time = 100U; /* 1ms x  */

const uint16_t K_FindHomeAfterCinch_StartDuty_Time = 50U;  /*10ms x */
const uint16_t K_FindHomeAfterCinch_DecreaseDuty_Time = 2U;   /* 10ms x  */
const uint16_t K_FindHomeAfterCinch_IncreaseDuty_Time = 1U;   /* 10ms x  */

const uint16_t K_CinchMotorFindHome_Count = 3;
const uint16_t K_PrimaryPositionIsArrived_Time= 2U;
const uint16_t K_ChangeDutyInFindHomeAfterCinch_Time = 300U; /* 1ms x  */
const uint16_t K_ChangeDutyInFindHomeAfterCinch_Time_2nd = 100U; /* 1ms x  */

const uint16_t K_ChangeDutyInPowerCinching_Time = 3000U; /* 1ms x  */

const uint16_t K_ContinueParking_Time = 130U;
const uint16_t K_ContinueParking_Time_2nd = 130U;

const uint16_t K_CinchMotor_PowerCinching_Duty = 80U;
const uint16_t K_CinchMotor_PowerCinching_Duty_2nd = 80U;

const uint16_t K_CinchMotor_FindHomeAfterCinch_Duty = 20U;
const uint16_t K_CinchMotor_FindHomeAfterCinch_Duty_2nd = 65U;

const uint16_t K_LowDutyFailFindHomeAfterCinch_Time = 6000U;/* 1ms x  */ 
const uint16_t K_LowDutyFailFindHomeAfterCinch_Duty = 60U; 
const uint16_t K_LowDutyFailPowerCinching_Time = 3200U;/* 1ms x  */ 
const uint16_t K_LowDutyFailPowerCinching_Duty = 100U;

const uint16_t K_CinchMotor_FindHomeAfterRelease_Duty = 70U;
const uint16_t K_CinchMotor_FindHomeAfterRelease_Duty_2nd = 70U;
const uint16_t K_CinchMotor_FindHomeAfterRelease_Duty_3rd = 70U;

const uint16_t K_CinchMotor_FindHomeReleaseDirection_Duty = 100U;
const uint16_t K_CinchMotor_FindHomeReleaseDirection_Duty_2nd = 50U;
const uint16_t K_CinchMotor_FindHomeCinchDirection_Duty = 100U;
const uint16_t K_CinchMotor_FindHomeCinchDirection_Duty_2nd = 50U;

const uint16_t K_CinchMotor_FindHomeAfterPark_Duty = 70U;
const uint16_t K_CinchMotor_FindHomeAfterBlip_Duty = 30U;

const uint16_t K_ReleaseMotor_PowerReleasing_Duty = 100U;
const uint16_t K_ReleaseMotor_PowerReleasing_Duty_2nd = 100U;
const uint16_t K_CinchMotor_PowerReleasing_Duty = 100U;
const uint16_t K_CinchMotor_PowerReleasing_Duty_2nd = 100U;

const uint16_t K_PowerReleasing_ComfirmCurrent = 200U;

const uint16_t K_PowerCinching_SoftStall_Current = 1000U;
const uint16_t K_FindHomeAfterCinch_SoftStall_Current = 1000U;
const uint16_t K_PreReleasing_SoftStall_Current = 1000U;
const uint16_t K_PowerReleasing_SoftStall_Current = 1000U;
const uint16_t K_FindHomeAfterRelease_SoftStall_Current = 1000U;
const uint16_t K_FindHomeReleaseDirection_SoftStall_Current = 200U;
const uint16_t K_FindHomeCinchDirection_SoftStall_Current = 200U;
const uint16_t K_FindHomeAfterPark_SoftStall_Current = 1000U;


const uint16_t K_PowerCinching_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeAfterCinch_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_PreReleasing_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_PowerReleasing_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeAfterRelease_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeReleaseDirection_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeCinchDirection_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeAfterPark_SoftStall_Time = 10U; /* 10ms x  */
 
const uint16_t K_StopBeforeFindHomeAfterCinch_Time = 20U;  /* 1ms x  */
const uint16_t K_LatchNotLeaveHomeInMiniPowerCinch_Time = 0U; /* 1ms x  */

const uint16_t K_PowerReleasing_ComfirmCurrent_Time = 5U; /* 10ms x  */
const uint16_t K_FindHomeAfterCinch_Work_MiniTime = 20U; /* 10ms x  */ 
const uint16_t K_ChangeDutyInFindHomeReleaseDirection_Time = 200U; /* 10ms x  */
const uint16_t K_ChangeDutyInFindHomeCinchDirection_Time = 200U; /* 10ms x  */
#endif


#ifdef _CONFIG_SV65PSDLatch
/*********************************************************************************************
**    Ingin Latch Control
*********************************************************************************************/
const uint16_t K_PowerCinchInSecondPosition_AfterPowerUp_Enable = TRUE;

const uint16_t K_LatchPreCinchCheck_Timeout = 2000U; /* 1ms x  */

const uint16_t K_LatchPowerCinching_Timeout = 4000U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterCinch_Timeout = 4000U; /* 1ms x  */
const uint16_t K_LatchPowerReleasing_Timeout = 2000U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterRelease_Timeout = 3000U; /* 1ms x  */
const uint16_t K_ContinueFindHomeAfterRelease_Time = 50U;//100U; /* 1ms x  */

const uint16_t K_LatchPreReleasing_Timeout = 4000U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterRelease_Mini_Time = 100U; /* 1ms x  */
const uint16_t K_LatchFindHomeReleaseDirection_Timeout = 4000U; /* 1ms x  */
const uint16_t K_LatchFindHomeCinchDirection_Timeout = 1000U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterPark_Timeout = 500U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterBlip_Timeout = 100U; /* 1ms x  */

const uint16_t K_LatchCrankWait_Timeout = 2000U; /* 1ms x  */
const uint16_t K_LatchMechFailure_Timeout = 2000U;

const uint16_t K_LatchPreCinchCheck_Time = 70U; /* 1ms x  */


const uint16_t K_PowerReleasing_PawlSwitch_Delay_Time = 100U; /* 1ms x  */ 
const uint16_t K_PowerReleasing_OutofLatch_Delay_Time = 0U;//50U; /* 1ms x  */ 

const uint16_t K_CinchMotor_IncreaseStep_Duty = 1U; /* x% x  */
const uint16_t K_PowerCinching_Delay_Time = 30U; /* 1ms x  */
const uint16_t K_PreReleased_OutofLatch_Delay_Time = 100U;//500U; /* 1ms x  */
const uint16_t K_LatchPreReleased_Timeout = 3000U; 
const uint16_t K_LatchPreRelease_SnowLoad_Time = 3000U;
const uint16_t K_SnowLoad_Timeout_PowerCinching_Delay_Time = 3000U; /* 1ms x  */

const uint16_t K_StopBeforePowerReleasing_Time = 0U; /* 1ms x  */
const uint16_t K_StopBeforePreReleasing_Time = 0U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeAfterRelease_Time = 50U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeAfterPark_Time = 50U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeAfterBlip_Time = 50U; /* 1ms x  */
const uint16_t K_MiniWorkingInCinchDirection_Time = 100U; /* 1ms x  */
const uint16_t K_ChangeDutyInFindHomeAfterRelease_Time = 50U;/* 1ms x  */
const uint16_t K_FindHomeAfterPark_PositionSwitch_Delay_Time = 100U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeCinchDirection_Time = 100U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeReleaseDirection_Time = 100U;  /* 1ms x  */
const uint16_t K_LatchFindHomeFailure_Timeout = 1000U;  /* 1ms x  */

const uint16_t K_FindHomeReleaseDirection_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_FindHomeCinchDirection_Inrush_Time = 200U; /* 1ms x  */

const uint16_t K_PowerCinching_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_FindHomeAfterCinch_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_FindHomeAfterPark_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_PreReleasing_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_PowerReleasing_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_FindHomeAfterRelease_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_PowerReleasing_Mini_Time = 200U; /* 1ms x  */

const uint16_t K_FindHomeAfterCinch_StartDuty_Time = 50U;  /*10ms x */
const uint16_t K_FindHomeAfterCinch_DecreaseDuty_Time = 2U;   /* 10ms x  */
const uint16_t K_FindHomeAfterCinch_IncreaseDuty_Time = 1U;   /* 10ms x  */

const uint16_t K_CinchMotorFindHome_Count = 3;
const uint16_t K_PrimaryPositionIsArrived_Time= 2U;
const uint16_t K_ChangeDutyInFindHomeAfterCinch_Time = 300U; /* 1ms x  */
const uint16_t K_ChangeDutyInFindHomeAfterCinch_Time_2nd = 100U; /* 1ms x  */
const uint16_t K_ChangeDutyInPowerCinching_Time = 3000U; /* 1ms x  */

const uint16_t K_ContinueParking_Time = 80U;
const uint16_t K_ContinueParking_Time_2nd = 80U;

const uint16_t K_CinchMotor_PowerCinching_Duty = 80U;
const uint16_t K_CinchMotor_PowerCinching_Duty_2nd = 80U;

const uint16_t K_CinchMotor_FindHomeAfterCinch_Duty = 80U;
const uint16_t K_CinchMotor_FindHomeAfterCinch_Duty_2nd = 55U;

const uint16_t K_LowDutyFailFindHomeAfterCinch_Time = 2500U;/* 1ms x  */ 
const uint16_t K_LowDutyFailFindHomeAfterCinch_Duty = 100U; 
const uint16_t K_LowDutyFailPowerCinching_Time = 1500U;/* 1ms x  */ 
const uint16_t K_LowDutyFailPowerCinching_Duty = 100U;

const uint16_t K_CinchMotor_FindHomeAfterRelease_Duty = 80U;
const uint16_t K_CinchMotor_FindHomeAfterRelease_Duty_2nd = 55U;
const uint16_t K_CinchMotor_FindHomeAfterRelease_Duty_3rd = 55U;

const uint16_t K_CinchMotor_FindHomeReleaseDirection_Duty = 80U;
const uint16_t K_CinchMotor_FindHomeReleaseDirection_Duty_2nd = 80U;
const uint16_t K_CinchMotor_FindHomeCinchDirection_Duty = 80U;
const uint16_t K_CinchMotor_FindHomeCinchDirection_Duty_2nd = 80U;

const uint16_t K_CinchMotor_FindHomeAfterPark_Duty = 80U;
const uint16_t K_CinchMotor_FindHomeAfterBlip_Duty = 30U;

const uint16_t K_ReleaseMotor_PowerReleasing_Duty = 100U;
const uint16_t K_ReleaseMotor_PowerReleasing_Duty_2nd = 100U;
const uint16_t K_CinchMotor_PowerReleasing_Duty = 80U;
const uint16_t K_CinchMotor_PowerReleasing_Duty_2nd = 80U;

const uint16_t K_PowerReleasing_ComfirmCurrent = 300U;

const uint16_t K_PowerCinching_SoftStall_Current = 1000U;
const uint16_t K_FindHomeAfterCinch_SoftStall_Current = 1000U;
const uint16_t K_PreReleasing_SoftStall_Current = 1000U;
const uint16_t K_PowerReleasing_SoftStall_Current = 1000U;
const uint16_t K_FindHomeAfterRelease_SoftStall_Current = 600U;
const uint16_t K_FindHomeReleaseDirection_SoftStall_Current = 600U;
const uint16_t K_FindHomeCinchDirection_SoftStall_Current = 600U;
const uint16_t K_FindHomeAfterPark_SoftStall_Current = 1000U;


const uint16_t K_PowerCinching_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeAfterCinch_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_PreReleasing_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_PowerReleasing_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeAfterRelease_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeReleaseDirection_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeCinchDirection_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeAfterPark_SoftStall_Time = 10U; /* 10ms x  */
 
const uint16_t K_StopBeforeFindHomeAfterCinch_Time = 20U;  /* 1ms x  */
const uint16_t K_LatchNotLeaveHomeInMiniPowerCinch_Time = 0U; /* 1ms x  */
const uint16_t K_PowerReleasing_ComfirmCurrent_Time = 3U; /* 10ms x  */
const uint16_t K_FindHomeAfterCinch_Work_MiniTime = 20U; /* 10ms x  */ 
const uint16_t K_ChangeDutyInFindHomeReleaseDirection_Time = 200U; /* 10ms x  */
const uint16_t K_ChangeDutyInFindHomeCinchDirection_Time = 200U; /* 10ms x  */
#endif





#ifdef _CONFIG_AisinPSDLatch
/*********************************************************************************************
**    Ingin Latch Control
*********************************************************************************************/
const uint16_t K_PowerCinchInSecondPosition_AfterPowerUp_Enable = TRUE;

const uint16_t K_LatchPreCinchCheck_Timeout = 2000U; /* 1ms x  */

const uint16_t K_LatchPowerCinching_Timeout = 4000U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterCinch_Timeout = 4000U; /* 1ms x  */
const uint16_t K_LatchPowerReleasing_Timeout = 2000U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterRelease_Timeout = 3000U; /* 1ms x  */
const uint16_t K_ContinueFindHomeAfterRelease_Time = 50U;//100U; /* 1ms x  */

const uint16_t K_LatchPreReleasing_Timeout = 4000U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterRelease_Mini_Time = 100U; /* 1ms x  */
const uint16_t K_LatchFindHomeReleaseDirection_Timeout = 4000U; /* 1ms x  */
const uint16_t K_LatchFindHomeCinchDirection_Timeout = 1000U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterPark_Timeout = 500U; /* 1ms x  */
const uint16_t K_LatchFindHomeAfterBlip_Timeout = 100U; /* 1ms x  */

const uint16_t K_LatchCrankWait_Timeout = 2000U; /* 1ms x  */
const uint16_t K_LatchMechFailure_Timeout = 2000U;

const uint16_t K_LatchPreCinchCheck_Time = 70U; /* 1ms x  */

const uint16_t K_PowerReleasing_PawlSwitch_Delay_Time = 100U; /* 1ms x  */ 
const uint16_t K_PowerReleasing_OutofLatch_Delay_Time = 0U;//50U; /* 1ms x  */ 

const uint16_t K_CinchMotor_IncreaseStep_Duty = 1U; /* x% x  */
const uint16_t K_PowerCinching_Delay_Time = 30U; /* 1ms x  */
const uint16_t K_PreReleased_OutofLatch_Delay_Time = 100U;//500U; /* 1ms x  */
const uint16_t K_LatchPreReleased_Timeout = 3000U; 
const uint16_t K_LatchPreRelease_SnowLoad_Time = 3000U;
const uint16_t K_SnowLoad_Timeout_PowerCinching_Delay_Time = 3000U; /* 1ms x  */

const uint16_t K_StopBeforePowerReleasing_Time = 0U; /* 1ms x  */
const uint16_t K_StopBeforePreReleasing_Time = 0U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeAfterRelease_Time = 50U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeAfterPark_Time = 50U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeAfterBlip_Time = 50U; /* 1ms x  */
const uint16_t K_MiniWorkingInCinchDirection_Time = 100U; /* 1ms x  */
const uint16_t K_ChangeDutyInFindHomeAfterRelease_Time = 50U;/* 1ms x  */
const uint16_t K_FindHomeAfterPark_PositionSwitch_Delay_Time = 100U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeCinchDirection_Time = 100U; /* 1ms x  */
const uint16_t K_StopBeforeFindHomeReleaseDirection_Time = 100U;  /* 1ms x  */
const uint16_t K_LatchFindHomeFailure_Timeout = 1000U;  /* 1ms x  */

const uint16_t K_FindHomeReleaseDirection_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_FindHomeCinchDirection_Inrush_Time = 200U; /* 1ms x  */

const uint16_t K_PowerCinching_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_FindHomeAfterCinch_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_FindHomeAfterPark_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_PreReleasing_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_PowerReleasing_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_FindHomeAfterRelease_Inrush_Time = 200U; /* 1ms x  */
const uint16_t K_PowerReleasing_Mini_Time = 200U; /* 1ms x  */

const uint16_t K_FindHomeAfterCinch_StartDuty_Time = 50U;  /*10ms x */
const uint16_t K_FindHomeAfterCinch_DecreaseDuty_Time = 2U;   /* 10ms x  */
const uint16_t K_FindHomeAfterCinch_IncreaseDuty_Time = 1U;   /* 10ms x  */

const uint16_t K_CinchMotorFindHome_Count = 3;
const uint16_t K_PrimaryPositionIsArrived_Time= 2U;
const uint16_t K_ChangeDutyInFindHomeAfterCinch_Time = 300U; /* 1ms x  */
const uint16_t K_ChangeDutyInFindHomeAfterCinch_Time_2nd = 100U; /* 1ms x  */
const uint16_t K_ChangeDutyInPowerCinching_Time = 3000U; /* 1ms x  */

const uint16_t K_ContinueParking_Time = 80U;
const uint16_t K_ContinueParking_Time_2nd = 80U;

const uint16_t K_CinchMotor_PowerCinching_Duty = 80U;
const uint16_t K_CinchMotor_PowerCinching_Duty_2nd = 80U;

const uint16_t K_CinchMotor_FindHomeAfterCinch_Duty = 80U;
const uint16_t K_CinchMotor_FindHomeAfterCinch_Duty_2nd = 55U;

const uint16_t K_LowDutyFailFindHomeAfterCinch_Time = 2500U;/* 1ms x  */ 
const uint16_t K_LowDutyFailFindHomeAfterCinch_Duty = 100U; 
const uint16_t K_LowDutyFailPowerCinching_Time = 1500U;/* 1ms x  */ 
const uint16_t K_LowDutyFailPowerCinching_Duty = 100U;

const uint16_t K_CinchMotor_FindHomeAfterRelease_Duty = 80U;
const uint16_t K_CinchMotor_FindHomeAfterRelease_Duty_2nd = 55U;
const uint16_t K_CinchMotor_FindHomeAfterRelease_Duty_3rd = 55U;

const uint16_t K_CinchMotor_FindHomeReleaseDirection_Duty = 80U;
const uint16_t K_CinchMotor_FindHomeReleaseDirection_Duty_2nd = 80U;
const uint16_t K_CinchMotor_FindHomeCinchDirection_Duty = 80U;
const uint16_t K_CinchMotor_FindHomeCinchDirection_Duty_2nd = 80U;

const uint16_t K_CinchMotor_FindHomeAfterPark_Duty = 80U;
const uint16_t K_CinchMotor_FindHomeAfterBlip_Duty = 30U;

const uint16_t K_ReleaseMotor_PowerReleasing_Duty = 100U;
const uint16_t K_ReleaseMotor_PowerReleasing_Duty_2nd = 100U;
const uint16_t K_CinchMotor_PowerReleasing_Duty = 80U;
const uint16_t K_CinchMotor_PowerReleasing_Duty_2nd = 80U;

const uint16_t K_PowerReleasing_ComfirmCurrent = 300U;

const uint16_t K_PowerCinching_SoftStall_Current = 1000U;
const uint16_t K_FindHomeAfterCinch_SoftStall_Current = 1000U;
const uint16_t K_PreReleasing_SoftStall_Current = 1000U;
const uint16_t K_PowerReleasing_SoftStall_Current = 1000U;
const uint16_t K_FindHomeAfterRelease_SoftStall_Current = 600U;
const uint16_t K_FindHomeReleaseDirection_SoftStall_Current = 600U;
const uint16_t K_FindHomeCinchDirection_SoftStall_Current = 600U;
const uint16_t K_FindHomeAfterPark_SoftStall_Current = 1000U;

const uint16_t K_PowerCinching_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeAfterCinch_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_PreReleasing_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_PowerReleasing_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeAfterRelease_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeReleaseDirection_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeCinchDirection_SoftStall_Time = 10U; /* 10ms x  */
const uint16_t K_FindHomeAfterPark_SoftStall_Time = 10U; /* 10ms x  */
 
const uint16_t K_StopBeforeFindHomeAfterCinch_Time = 20U;  /* 1ms x  */
const uint16_t K_LatchNotLeaveHomeInMiniPowerCinch_Time = 0U; /* 1ms x  */
const uint16_t K_PowerReleasing_ComfirmCurrent_Time = 3U; /* 10ms x  */
const uint16_t K_FindHomeAfterCinch_Work_MiniTime = 20U; /* 10ms x  */ 
const uint16_t K_ChangeDutyInFindHomeReleaseDirection_Time = 200U; /* 10ms x  */
const uint16_t K_ChangeDutyInFindHomeCinchDirection_Time = 200U; /* 10ms x  */

#ifdef _CONFIG_ReleaseToPowerClose
const uint16_t K_SystemReleaseToPowerClose_Timeout = 3000U; /* 1ms x 0 */
const uint16_t K_ReleaseToPowerClose_Delay_Time = 100U; /* 1ms x 0 */
const uint16_t K_ReleaseToPowerClose_Work_Time = 200U; /* 1ms x 0 */
const uint16_t K_ReleaseToPowerClose_HallCount = 400U; 
const uint16_t K_ReleaseToPowerClose_Duty = 40U;
const uint16_t K_ReleaseToPowerClose_Duty_Adder_HighTemp = 10U;
const uint16_t K_ReleaseToPowerClose_Duty_Adder_LowTemp = 10U;
const int16_t K_ReleaseToPowerClose_Duty_Adder_CloseUpgrade = -10;
const int16_t K_ReleaseToPowerClose_Duty_Adder_CloseDowngrade = 10U; 
#endif

#endif

/*********************************************************************************************
**    Diagnostic Control
*********************************************************************************************/
#ifdef _SGMW_COM
const uint16_t K_Diagnostic_PreCondition_Start_Time = 150U; /* 10ms x  */
const uint16_t K_Diagnostic_PreCondition_Crank_Time = 100U; /* 10ms x  */
const uint16_t K_Diagnostic_PreCondition_Voltage_Time = 100U; /* 10ms x  */

const uint16_t K_DTCReport_PreCondition_Start_Time = 100U; /* 10ms x  */
const uint16_t K_DTCReport_PreCondition_Crank_Time = 100U; /* 10ms x  */
const uint16_t K_DTCReport_PreCondition_Voltage_Time = 100U; /* 10ms x  */
#endif
#ifdef _SGM_COM
const uint16_t K_Diagnostic_PreCondition_Start_Time = 150U; /* 10ms x  */
const uint16_t K_Diagnostic_PreCondition_Crank_Time = 100U; /* 10ms x  */
const uint16_t K_Diagnostic_PreCondition_Voltage_Time = 100U; /* 10ms x  */

const uint16_t K_DTCReport_PreCondition_Start_Time = 100U; /* 10ms x  */
const uint16_t K_DTCReport_PreCondition_Crank_Time = 100U; /* 10ms x  */
const uint16_t K_DTCReport_PreCondition_Voltage_Time = 100U; /* 10ms x  */
#endif
#ifdef _CTCS_COM
const uint16_t K_Diagnostic_PreCondition_Start_Time = 150U; /* 10ms x  */
const uint16_t K_Diagnostic_PreCondition_Crank_Time = 100U; /* 10ms x  */
const uint16_t K_Diagnostic_PreCondition_Voltage_Time = 100U; /* 10ms x  */

const uint16_t K_DTCReport_PreCondition_Start_Time = 100U; /* 10ms x  */
const uint16_t K_DTCReport_PreCondition_Crank_Time = 100U; /* 10ms x  */
const uint16_t K_DTCReport_PreCondition_Voltage_Time = 100U; /* 10ms x  */
#endif
#ifdef _DEARCC_COM
const uint16_t K_Diagnostic_PreCondition_Start_Time = 150U; /* 10ms x  */
const uint16_t K_Diagnostic_PreCondition_Crank_Time = 100U; /* 10ms x  */
const uint16_t K_Diagnostic_PreCondition_Voltage_Time = 100U; /* 10ms x  */

const uint16_t K_DTCReport_PreCondition_Start_Time = 100U; /* 10ms x  */
const uint16_t K_DTCReport_PreCondition_Crank_Time = 100U; /* 10ms x  */
const uint16_t K_DTCReport_PreCondition_Voltage_Time = 100U; /* 10ms x  */
#endif
#ifdef _MAXUS_COM
const uint16_t K_Diagnostic_PreCondition_Start_Time = 100U; /* 10ms x  */
const uint16_t K_Diagnostic_PreCondition_Crank_Time = 100U; /* 10ms x  */
const uint16_t K_Diagnostic_PreCondition_Voltage_Time = 100U; /* 10ms x  */

const uint16_t K_DTCReport_PreCondition_Start_Time = 100U; /* 10ms x  */
const uint16_t K_DTCReport_PreCondition_Crank_Time = 100U; /* 10ms x  */
const uint16_t K_DTCReport_PreCondition_Voltage_Time = 100U; /* 10ms x  */
#endif
#ifdef _DFMC_COM
const uint16_t K_Diagnostic_PreCondition_Start_Time = 150U; /* 10ms x  */
const uint16_t K_Diagnostic_PreCondition_Crank_Time = 100U; /* 10ms x  */
const uint16_t K_Diagnostic_PreCondition_Voltage_Time = 100U; /* 10ms x  */

const uint16_t K_DTCReport_PreCondition_Start_Time = 100U; /* 10ms x  */
const uint16_t K_DTCReport_PreCondition_Crank_Time = 100U; /* 10ms x  */
const uint16_t K_DTCReport_PreCondition_Voltage_Time = 100U; /* 10ms x  */
#endif
#ifdef _BAIC_COM
const uint16_t K_Diagnostic_PreCondition_Start_Time = 150U; /* 10ms x  */
const uint16_t K_Diagnostic_PreCondition_Crank_Time = 100U; /* 10ms x  */
const uint16_t K_Diagnostic_PreCondition_Voltage_Time = 100U; /* 10ms x  */

const uint16_t K_DTCReport_PreCondition_Start_Time = 500U; /* 10ms x  */
const uint16_t K_DTCReport_PreCondition_Crank_Time = 500U; /* 10ms x  */
const uint16_t K_DTCReport_PreCondition_Voltage_Time = 500U; /* 10ms x  */
#endif
#ifdef _DFLZM_COM
const uint16_t K_Diagnostic_PreCondition_Start_Time = 150U; /* 10ms x  */
const uint16_t K_Diagnostic_PreCondition_Crank_Time = 100U; /* 10ms x  */
const uint16_t K_Diagnostic_PreCondition_Voltage_Time = 100U; /* 10ms x  */

const uint16_t K_DTCReport_PreCondition_Start_Time = 500U; /* 10ms x  */
const uint16_t K_DTCReport_PreCondition_Crank_Time = 500U; /* 10ms x  */
const uint16_t K_DTCReport_PreCondition_Voltage_Time = 500U; /* 10ms x  */
#endif
#ifdef _FAW_COM
const uint16_t K_Diagnostic_PreCondition_Start_Time = 150U; /* 10ms x  */
const uint16_t K_Diagnostic_PreCondition_Crank_Time = 100U; /* 10ms x  */
const uint16_t K_Diagnostic_PreCondition_Voltage_Time = 100U; /* 10ms x  */

const uint16_t K_DTCReport_PreCondition_Start_Time = 100U; /* 10ms x  */
const uint16_t K_DTCReport_PreCondition_Crank_Time = 100U; /* 10ms x  */
const uint16_t K_DTCReport_PreCondition_Voltage_Time = 100U; /* 10ms x  */
#endif
#ifdef _CHANGAN_COM
const uint16_t K_Diagnostic_PreCondition_Start_Time = 150U; /* 10ms x  */
const uint16_t K_Diagnostic_PreCondition_Crank_Time = 100U; /* 10ms x  */
const uint16_t K_Diagnostic_PreCondition_Voltage_Time = 100U; /* 10ms x  */

const uint16_t K_DTCReport_PreCondition_Start_Time = 100U; /* 10ms x  */
const uint16_t K_DTCReport_PreCondition_Crank_Time = 100U; /* 10ms x  */
const uint16_t K_DTCReport_PreCondition_Voltage_Time = 100U; /* 10ms x  */
#endif
#ifdef _CHERY_COM
const uint16_t K_Diagnostic_PreCondition_Start_Time = 150U; /* 10ms x  */
const uint16_t K_Diagnostic_PreCondition_Crank_Time = 100U; /* 10ms x  */
const uint16_t K_Diagnostic_PreCondition_Voltage_Time = 100U; /* 10ms x  */

const uint16_t K_DTCReport_PreCondition_Start_Time = 100U; /* 10ms x  */
const uint16_t K_DTCReport_PreCondition_Crank_Time = 100U; /* 10ms x  */
const uint16_t K_DTCReport_PreCondition_Voltage_Time = 300U; /* 10ms x  */
#endif

#ifdef _VOYAH_COM
const uint16_t K_Diagnostic_PreCondition_Start_Time = 150U; /* 10ms x  */
const uint16_t K_Diagnostic_PreCondition_Crank_Time = 100U; /* 10ms x  */
const uint16_t K_Diagnostic_PreCondition_Voltage_Time = 100U; /* 10ms x  */

const uint16_t K_DTCReport_PreCondition_Start_Time = 100U; /* 10ms x  */
const uint16_t K_DTCReport_PreCondition_Crank_Time = 100U; /* 10ms x  */
const uint16_t K_DTCReport_PreCondition_Voltage_Time = 300U; /* 10ms x  */
#endif


#ifdef _AUDI_COM
const uint16_t K_Diagnostic_PreCondition_Start_Time = 150U; /* 10ms x  */
const uint16_t K_Diagnostic_PreCondition_Crank_Time = 100U; /* 10ms x  */
const uint16_t K_Diagnostic_PreCondition_Voltage_Time = 100U; /* 10ms x  */

const uint16_t K_DTCReport_PreCondition_Start_Time = 100U; /* 10ms x  */
const uint16_t K_DTCReport_PreCondition_Crank_Time = 100U; /* 10ms x  */
const uint16_t K_DTCReport_PreCondition_Voltage_Time = 300U; /* 10ms x  */
#endif

#ifdef _NIU_COM
const uint16_t K_Diagnostic_PreCondition_Start_Time = 150U; /* 10ms x  */
const uint16_t K_Diagnostic_PreCondition_Crank_Time = 100U; /* 10ms x  */
const uint16_t K_Diagnostic_PreCondition_Voltage_Time = 100U; /* 10ms x  */

const uint16_t K_DTCReport_PreCondition_Start_Time = 100U; /* 10ms x  */
const uint16_t K_DTCReport_PreCondition_Crank_Time = 100U; /* 10ms x  */
const uint16_t K_DTCReport_PreCondition_Voltage_Time = 100U; /* 10ms x  */
#endif
#ifdef _XIAOPENG_COM
const uint16_t K_Diagnostic_PreCondition_Start_Time = 150U; /* 10ms x  */
const uint16_t K_Diagnostic_PreCondition_Crank_Time = 100U; /* 10ms x  */
const uint16_t K_Diagnostic_PreCondition_Voltage_Time = 100U; /* 10ms x  */

const uint16_t K_DTCReport_PreCondition_Start_Time = 100U; /* 10ms x  */
const uint16_t K_DTCReport_PreCondition_Crank_Time = 100U; /* 10ms x  */
const uint16_t K_DTCReport_PreCondition_Voltage_Time = 100U; /* 10ms x  */
#endif

const uint16_t K_CinchMotor_P_Ratio_Denominator = 1000U; //100U;
const uint16_t K_CinchMotor_N_Ratio_Denominator = 1000U; //100U;
const uint16_t K_ReleaseMotor_P_Ratio_Denominator = 1000U; //100U;
const uint16_t K_Buzzer_P_Ratio_Denominator = 1000U; //100U;
const uint16_t K_Clutch_P_Ratio_Denominator = 1000U; //100U;
const uint16_t K_Motor1_P_Ratio_Denominator = 1000U; //100U;
const uint16_t K_Motor1_N_Ratio_Denominator = 1000U; //100U;
const uint16_t K_Motor2_P_Ratio_Denominator = 1000U; //100U;
const uint16_t K_Motor2_N_Ratio_Denominator = 1000U; //100U;

#ifdef _CHERY_COM
const uint16_t K_CinchMotor_STG_StaticDiag_Time = 25U;  /* 20ms x  */
const uint16_t K_ReleaseMotor_STG_StaticDiag_Time = 25U;  /* 20ms x  */
const uint16_t K_Buzzer_STG_StaticDiag_Time = 25U;  /* 20ms x  */
const uint16_t K_Clutch_STG_StaticDiag_Time = 25U;  /* 20ms x  */
const uint16_t K_Motor1_STG_StaticDiag_Time = 25U;  /* 20ms x  */
const uint16_t K_Motor2_STG_StaticDiag_Time = 25U;  /* 20ms x  */

const uint16_t K_CinchMotor_OC_StaticDiag_Time = 50U;  /* 20ms x  */
const uint16_t K_ReleaseMotor_OC_StaticDiag_Time = 50U;  /* 20ms x  */
const uint16_t K_Buzzer_OC_StaticDiag_Time = 50U;  /* 20ms x  */
const uint16_t K_Clutch_OC_StaticDiag_Time = 50U;  /* 20ms x  */
const uint16_t K_Motor1_OC_StaticDiag_Time = 50U;  /* 20ms x  */
const uint16_t K_Motor2_OC_StaticDiag_Time = 50U;  /* 20ms x  */

const uint16_t K_CinchMotor_STB_StaticDiag_Time = 25U;  /* 20ms x  */
const uint16_t K_ReleaseMotor_STB_StaticDiag_Time = 25U;  /* 20ms x  */
const uint16_t K_Buzzer_STB_StaticDiag_Time = 25U;  /* 20ms x  */
const uint16_t K_Clutch_STB_StaticDiag_Time = 25U;  /* 20ms x  */
const uint16_t K_Motor1_STB_StaticDiag_Time = 25U;  /* 20ms x  */
const uint16_t K_Motor2_STB_StaticDiag_Time = 25U;  /* 20ms x  */

const uint16_t K_CinchMotor_Error_StaticDiag_Time = 100U;  /* 20ms x  */
const uint16_t K_ReleaseMotor_Error_StaticDiag_Time = 100U;  /* 20ms x  */
const uint16_t K_Buzzer_Error_StaticDiag_Time = 100U;  /* 20ms x  */
const uint16_t K_Clutch_Error_StaticDiag_Time = 100U;  /* 20ms x  */
const uint16_t K_Motor1_Error_StaticDiag_Time = 100U;  /* 20ms x  */
const uint16_t K_Motor2_Error_StaticDiag_Time = 100U;  /* 20ms x  */

const uint16_t K_CinchMotor_Normal_StaticDiag_Time = 25U;  /* 20ms x  */
const uint16_t K_ReleaseMotor_Normal_StaticDiag_Time = 25U;  /* 20ms x  */
const uint16_t K_Buzzer_Normal_StaticDiag_Time = 25U;  /* 20ms x  */
const uint16_t K_Clutch_Normal_StaticDiag_Time = 25U;  /* 20ms x  */
const uint16_t K_Motor1_Normal_StaticDiag_Time = 25U;  /* 20ms x  */
const uint16_t K_Motor2_Normal_StaticDiag_Time = 25U;  /* 20ms x  */
#endif


#ifdef _VOYAH_COM
const uint16_t K_CinchMotor_STG_StaticDiag_Time = 25U;  /* 20ms x  */
const uint16_t K_ReleaseMotor_STG_StaticDiag_Time = 25U;  /* 20ms x  */
const uint16_t K_Buzzer_STG_StaticDiag_Time = 25U;  /* 20ms x  */
const uint16_t K_Clutch_STG_StaticDiag_Time = 25U;  /* 20ms x  */
const uint16_t K_Motor1_STG_StaticDiag_Time = 25U;  /* 20ms x  */
const uint16_t K_Motor2_STG_StaticDiag_Time = 25U;  /* 20ms x  */

const uint16_t K_CinchMotor_OC_StaticDiag_Time = 50U;  /* 20ms x  */
const uint16_t K_ReleaseMotor_OC_StaticDiag_Time = 50U;  /* 20ms x  */
const uint16_t K_Buzzer_OC_StaticDiag_Time = 50U;  /* 20ms x  */
const uint16_t K_Clutch_OC_StaticDiag_Time = 50U;  /* 20ms x  */
const uint16_t K_Motor1_OC_StaticDiag_Time = 50U;  /* 20ms x  */
const uint16_t K_Motor2_OC_StaticDiag_Time = 50U;  /* 20ms x  */

const uint16_t K_CinchMotor_STB_StaticDiag_Time = 25U;  /* 20ms x  */
const uint16_t K_ReleaseMotor_STB_StaticDiag_Time = 25U;  /* 20ms x  */
const uint16_t K_Buzzer_STB_StaticDiag_Time = 25U;  /* 20ms x  */
const uint16_t K_Clutch_STB_StaticDiag_Time = 25U;  /* 20ms x  */
const uint16_t K_Motor1_STB_StaticDiag_Time = 25U;  /* 20ms x  */
const uint16_t K_Motor2_STB_StaticDiag_Time = 25U;  /* 20ms x  */

const uint16_t K_CinchMotor_Error_StaticDiag_Time = 100U;  /* 20ms x  */
const uint16_t K_ReleaseMotor_Error_StaticDiag_Time = 100U;  /* 20ms x  */
const uint16_t K_Buzzer_Error_StaticDiag_Time = 100U;  /* 20ms x  */
const uint16_t K_Clutch_Error_StaticDiag_Time = 100U;  /* 20ms x  */
const uint16_t K_Motor1_Error_StaticDiag_Time = 100U;  /* 20ms x  */
const uint16_t K_Motor2_Error_StaticDiag_Time = 100U;  /* 20ms x  */

const uint16_t K_CinchMotor_Normal_StaticDiag_Time = 25U;  /* 20ms x  */
const uint16_t K_ReleaseMotor_Normal_StaticDiag_Time = 25U;  /* 20ms x  */
const uint16_t K_Buzzer_Normal_StaticDiag_Time = 25U;  /* 20ms x  */
const uint16_t K_Clutch_Normal_StaticDiag_Time = 25U;  /* 20ms x  */
const uint16_t K_Motor1_Normal_StaticDiag_Time = 25U;  /* 20ms x  */
const uint16_t K_Motor2_Normal_StaticDiag_Time = 25U;  /* 20ms x  */
#endif



#ifdef _AUDI_COM
const uint16_t K_CinchMotor_STG_StaticDiag_Time = 25U;  /* 20ms x  */
const uint16_t K_ReleaseMotor_STG_StaticDiag_Time = 25U;  /* 20ms x  */
const uint16_t K_Buzzer_STG_StaticDiag_Time = 25U;  /* 20ms x  */
const uint16_t K_Clutch_STG_StaticDiag_Time = 25U;  /* 20ms x  */
const uint16_t K_Motor1_STG_StaticDiag_Time = 25U;  /* 20ms x  */
const uint16_t K_Motor2_STG_StaticDiag_Time = 25U;  /* 20ms x  */

const uint16_t K_CinchMotor_OC_StaticDiag_Time = 50U;  /* 20ms x  */
const uint16_t K_ReleaseMotor_OC_StaticDiag_Time = 50U;  /* 20ms x  */
const uint16_t K_Buzzer_OC_StaticDiag_Time = 50U;  /* 20ms x  */
const uint16_t K_Clutch_OC_StaticDiag_Time = 50U;  /* 20ms x  */
const uint16_t K_Motor1_OC_StaticDiag_Time = 50U;  /* 20ms x  */
const uint16_t K_Motor2_OC_StaticDiag_Time = 50U;  /* 20ms x  */

const uint16_t K_CinchMotor_STB_StaticDiag_Time = 25U;  /* 20ms x  */
const uint16_t K_ReleaseMotor_STB_StaticDiag_Time = 25U;  /* 20ms x  */
const uint16_t K_Buzzer_STB_StaticDiag_Time = 25U;  /* 20ms x  */
const uint16_t K_Clutch_STB_StaticDiag_Time = 25U;  /* 20ms x  */
const uint16_t K_Motor1_STB_StaticDiag_Time = 25U;  /* 20ms x  */
const uint16_t K_Motor2_STB_StaticDiag_Time = 25U;  /* 20ms x  */

const uint16_t K_CinchMotor_Error_StaticDiag_Time = 100U;  /* 20ms x  */
const uint16_t K_ReleaseMotor_Error_StaticDiag_Time = 100U;  /* 20ms x  */
const uint16_t K_Buzzer_Error_StaticDiag_Time = 100U;  /* 20ms x  */
const uint16_t K_Clutch_Error_StaticDiag_Time = 100U;  /* 20ms x  */
const uint16_t K_Motor1_Error_StaticDiag_Time = 100U;  /* 20ms x  */
const uint16_t K_Motor2_Error_StaticDiag_Time = 100U;  /* 20ms x  */

const uint16_t K_CinchMotor_Normal_StaticDiag_Time = 25U;  /* 20ms x  */
const uint16_t K_ReleaseMotor_Normal_StaticDiag_Time = 25U;  /* 20ms x  */
const uint16_t K_Buzzer_Normal_StaticDiag_Time = 25U;  /* 20ms x  */
const uint16_t K_Clutch_Normal_StaticDiag_Time = 25U;  /* 20ms x  */
const uint16_t K_Motor1_Normal_StaticDiag_Time = 25U;  /* 20ms x  */
const uint16_t K_Motor2_Normal_StaticDiag_Time = 25U;  /* 20ms x  */
#endif


#ifdef _CONFIG_Motor4
const uint16_t K_Motor4_STG_StaticDiag_Time = 5U;  /* 20ms x  */
const uint16_t K_Motor4_OC_StaticDiag_Time = 50U;  /* 20ms x  */
const uint16_t K_Motor4_STB_StaticDiag_Time = 5U;  /* 20ms x  */
const uint16_t K_Motor4_Error_StaticDiag_Time = 100U;  /* 20ms x  */
const uint16_t K_Motor4_Normal_StaticDiag_Time = 5U;  /* 20ms x  */
#endif

#ifdef _CONFIG_Gen1_Board
const uint16_t K_ReleaseMotor_P_STG_StaticDiag_Ratio_LowLimit = 0U;  
const uint16_t K_ReleaseMotor_P_STG_StaticDiag_Ratio_HighLimit = 10U; //5U;

const uint16_t K_ReleaseMotor_P_OC_StaticDiag_Ratio_LowLimit = 160U; //48U;  
const uint16_t K_ReleaseMotor_P_OC_StaticDiag_Ratio_HighLimit = 190U; //55U;

const uint16_t K_ReleaseMotor_P_STB_StaticDiag_Ratio_LowLimit = 220U;//110U;  
const uint16_t K_ReleaseMotor_P_STB_StaticDiag_Ratio_HighLimit = 250U;//120U;

const uint16_t K_ReleaseMotor_P_Normal_StaticDiag_Ratio_LowLimit = 0U;  
const uint16_t K_ReleaseMotor_P_Normal_StaticDiag_Ratio_HighLimit = 10U; //5U;

const uint16_t K_Buzzer_P_STG_StaticDiag_Ratio_LowLimit = 0U;  
const uint16_t K_Buzzer_P_STG_StaticDiag_Ratio_HighLimit = 10U; //5U;

const uint16_t K_Buzzer_P_OC_StaticDiag_Ratio_LowLimit = 160U; //48U;  
const uint16_t K_Buzzer_P_OC_StaticDiag_Ratio_HighLimit = 190U; //55U;

const uint16_t K_Buzzer_P_STB_StaticDiag_Ratio_LowLimit = 220U;//110U;  
const uint16_t K_Buzzer_P_STB_StaticDiag_Ratio_HighLimit = 250U;//120U;

const uint16_t K_Buzzer_P_Normal_StaticDiag_Ratio_LowLimit = 0U;  
const uint16_t K_Buzzer_P_Normal_StaticDiag_Ratio_HighLimit = 10U; //5U;

const uint16_t K_Clutch_P_STG_StaticDiag_Ratio_LowLimit = 0U;  
const uint16_t K_Clutch_P_STG_StaticDiag_Ratio_HighLimit = 10U; //5U;

const uint16_t K_Clutch_P_OC_StaticDiag_Ratio_LowLimit = 160U; //48U;  
const uint16_t K_Clutch_P_OC_StaticDiag_Ratio_HighLimit = 190U; //55U;

const uint16_t K_Clutch_P_STB_StaticDiag_Ratio_LowLimit = 220U;//110U;  
const uint16_t K_Clutch_P_STB_StaticDiag_Ratio_HighLimit = 250U;//120U;

const uint16_t K_Clutch_P_Normal_StaticDiag_Ratio_LowLimit = 0U; 
const uint16_t K_Clutch_P_Normal_StaticDiag_Ratio_HighLimit = 10U; //5U;

const uint16_t K_CinchMotor_P_STG_StaticDiag_Ratio_LowLimit = 0U;  
const uint16_t K_CinchMotor_P_STG_StaticDiag_Ratio_HighLimit = 10U;
const uint16_t K_CinchMotor_N_STG_StaticDiag_Ratio_LowLimit = 0U;
const uint16_t K_CinchMotor_N_STG_StaticDiag_Ratio_HighLimit = 10U;

const uint16_t K_CinchMotor_P_OC_StaticDiag_Ratio_LowLimit = 0U;  
const uint16_t K_CinchMotor_P_OC_StaticDiag_Ratio_HighLimit = 10U;
const uint16_t K_CinchMotor_N_OC_StaticDiag_Ratio_LowLimit = 75U;//39U;
const uint16_t K_CinchMotor_N_OC_StaticDiag_Ratio_HighLimit = 110U;//49U;

const uint16_t K_CinchMotor_P_STB_StaticDiag_Ratio_LowLimit = 230U;//110U;  
const uint16_t K_CinchMotor_P_STB_StaticDiag_Ratio_HighLimit = 250U;//120U;
const uint16_t K_CinchMotor_N_STB_StaticDiag_Ratio_LowLimit = 230U;//110U;
const uint16_t K_CinchMotor_N_STB_StaticDiag_Ratio_HighLimit = 250;//120U;

const uint16_t K_CinchMotor_P_Normal_StaticDiag_Ratio_LowLimit = 50U;//25U;  
const uint16_t K_CinchMotor_P_Normal_StaticDiag_Ratio_HighLimit = 100U;//50U;
const uint16_t K_CinchMotor_N_Normal_StaticDiag_Ratio_LowLimit = 50U;//25U;
const uint16_t K_CinchMotor_N_Normal_StaticDiag_Ratio_HighLimit = 100U;//50U;

const uint16_t K_Motor1_P_STG_StaticDiag_Ratio_LowLimit = 0U;  
const uint16_t K_Motor1_P_STG_StaticDiag_Ratio_HighLimit = 10U;
const uint16_t K_Motor1_N_STG_StaticDiag_Ratio_LowLimit = 0U;
const uint16_t K_Motor1_N_STG_StaticDiag_Ratio_HighLimit = 10U;

const uint16_t K_Motor1_P_OC_StaticDiag_Ratio_LowLimit = 0U;  
const uint16_t K_Motor1_P_OC_StaticDiag_Ratio_HighLimit = 10U;
const uint16_t K_Motor1_N_OC_StaticDiag_Ratio_LowLimit = 160U; //80U;
const uint16_t K_Motor1_N_OC_StaticDiag_Ratio_HighLimit = 200U;//90U;

const uint16_t K_Motor1_P_STB_StaticDiag_Ratio_LowLimit = 230U;//110U;  
const uint16_t K_Motor1_P_STB_StaticDiag_Ratio_HighLimit = 250U;//120U;
const uint16_t K_Motor1_N_STB_StaticDiag_Ratio_LowLimit = 230U;//110U;
const uint16_t K_Motor1_N_STB_StaticDiag_Ratio_HighLimit = 250U;//120U;

const uint16_t K_Motor1_P_Normal_StaticDiag_Ratio_LowLimit = 120U;//60U;  
const uint16_t K_Motor1_P_Normal_StaticDiag_Ratio_HighLimit = 180U;//86U;
const uint16_t K_Motor1_N_Normal_StaticDiag_Ratio_LowLimit = 120U;//60U;
const uint16_t K_Motor1_N_Normal_StaticDiag_Ratio_HighLimit = 180U;//86U;

const uint16_t K_Motor2_P_STG_StaticDiag_Ratio_LowLimit = 0U;  
const uint16_t K_Motor2_P_STG_StaticDiag_Ratio_HighLimit = 10U;
const uint16_t K_Motor2_N_STG_StaticDiag_Ratio_LowLimit = 0U;
const uint16_t K_Motor2_N_STG_StaticDiag_Ratio_HighLimit = 10U;

const uint16_t K_Motor2_P_OC_StaticDiag_Ratio_LowLimit = 0U;  
const uint16_t K_Motor2_P_OC_StaticDiag_Ratio_HighLimit = 10U;
const uint16_t K_Motor2_N_OC_StaticDiag_Ratio_LowLimit = 160U; //80U;
const uint16_t K_Motor2_N_OC_StaticDiag_Ratio_HighLimit = 200U;//90U;

const uint16_t K_Motor2_P_STB_StaticDiag_Ratio_LowLimit = 230U;//110U; 
const uint16_t K_Motor2_P_STB_StaticDiag_Ratio_HighLimit = 250U;//120U;
const uint16_t K_Motor2_N_STB_StaticDiag_Ratio_LowLimit = 230U;//110U;
const uint16_t K_Motor2_N_STB_StaticDiag_Ratio_HighLimit = 250U;//120U;

const uint16_t K_Motor2_P_Normal_StaticDiag_Ratio_LowLimit = 120U;//60U; 
const uint16_t K_Motor2_P_Normal_StaticDiag_Ratio_HighLimit = 180U;//86U;
const uint16_t K_Motor2_N_Normal_StaticDiag_Ratio_LowLimit = 120U;//60U;
const uint16_t K_Motor2_N_Normal_StaticDiag_Ratio_HighLimit = 180U;//86U;
#endif

#ifdef _CONFIG_Gen2_Board
const uint16_t K_ReleaseMotor_P_STG_StaticDiag_Ratio_LowLimit = 0U;  
const uint16_t K_ReleaseMotor_P_STG_StaticDiag_Ratio_HighLimit = 10U; 

const uint16_t K_ReleaseMotor_P_OC_StaticDiag_Ratio_LowLimit = 230U;
const uint16_t K_ReleaseMotor_P_OC_StaticDiag_Ratio_HighLimit = 270U; 

const uint16_t K_ReleaseMotor_P_STB_StaticDiag_Ratio_LowLimit = 480U;  
const uint16_t K_ReleaseMotor_P_STB_StaticDiag_Ratio_HighLimit = 520U;

const uint16_t K_ReleaseMotor_P_Normal_StaticDiag_Ratio_LowLimit = 0U;  
const uint16_t K_ReleaseMotor_P_Normal_StaticDiag_Ratio_HighLimit = 50U; 

const uint16_t K_Buzzer_P_STG_StaticDiag_Ratio_LowLimit = 0U;  
const uint16_t K_Buzzer_P_STG_StaticDiag_Ratio_HighLimit = 10U; 

const uint16_t K_Buzzer_P_OC_StaticDiag_Ratio_LowLimit = 230U;   
const uint16_t K_Buzzer_P_OC_StaticDiag_Ratio_HighLimit = 270U; 

const uint16_t K_Buzzer_P_STB_StaticDiag_Ratio_LowLimit = 480U;  
const uint16_t K_Buzzer_P_STB_StaticDiag_Ratio_HighLimit = 520U;

const uint16_t K_Buzzer_P_Normal_StaticDiag_Ratio_LowLimit = 0U;  
const uint16_t K_Buzzer_P_Normal_StaticDiag_Ratio_HighLimit = 50U; 

const uint16_t K_Clutch_P_STG_StaticDiag_Ratio_LowLimit = 0U;  
const uint16_t K_Clutch_P_STG_StaticDiag_Ratio_HighLimit = 10U; 

const uint16_t K_Clutch_P_OC_StaticDiag_Ratio_LowLimit = 230U;  
const uint16_t K_Clutch_P_OC_StaticDiag_Ratio_HighLimit = 270U;

const uint16_t K_Clutch_P_STB_StaticDiag_Ratio_LowLimit = 480U;
const uint16_t K_Clutch_P_STB_StaticDiag_Ratio_HighLimit = 520U;

const uint16_t K_Clutch_P_Normal_StaticDiag_Ratio_LowLimit = 0U; 
const uint16_t K_Clutch_P_Normal_StaticDiag_Ratio_HighLimit = 50U; 

const uint16_t K_CinchMotor_P_STG_StaticDiag_Ratio_LowLimit = 0U;  
const uint16_t K_CinchMotor_P_STG_StaticDiag_Ratio_HighLimit = 10U;
const uint16_t K_CinchMotor_N_STG_StaticDiag_Ratio_LowLimit = 0U;
const uint16_t K_CinchMotor_N_STG_StaticDiag_Ratio_HighLimit = 10U;

const uint16_t K_CinchMotor_P_OC_StaticDiag_Ratio_LowLimit = 30U;  
const uint16_t K_CinchMotor_P_OC_StaticDiag_Ratio_HighLimit = 50U;
const uint16_t K_CinchMotor_N_OC_StaticDiag_Ratio_LowLimit = 0U;
const uint16_t K_CinchMotor_N_OC_StaticDiag_Ratio_HighLimit = 10U;

const uint16_t K_CinchMotor_P_STB_StaticDiag_Ratio_LowLimit = 300U;  
const uint16_t K_CinchMotor_P_STB_StaticDiag_Ratio_HighLimit = 520U;
const uint16_t K_CinchMotor_N_STB_StaticDiag_Ratio_LowLimit = 300U;
const uint16_t K_CinchMotor_N_STB_StaticDiag_Ratio_HighLimit = 520U;

const uint16_t K_CinchMotor_P_Normal_StaticDiag_Ratio_LowLimit = 30U;  
const uint16_t K_CinchMotor_P_Normal_StaticDiag_Ratio_HighLimit = 50U;
const uint16_t K_CinchMotor_N_Normal_StaticDiag_Ratio_LowLimit = 30U;
const uint16_t K_CinchMotor_N_Normal_StaticDiag_Ratio_HighLimit = 50U;

const uint16_t K_Motor1_P_STG_StaticDiag_Ratio_LowLimit = 0U;  
const uint16_t K_Motor1_P_STG_StaticDiag_Ratio_HighLimit = 10U;
const uint16_t K_Motor1_N_STG_StaticDiag_Ratio_LowLimit = 0U;
const uint16_t K_Motor1_N_STG_StaticDiag_Ratio_HighLimit = 10U;

const uint16_t K_Motor1_P_OC_StaticDiag_Ratio_LowLimit = 30U;  
const uint16_t K_Motor1_P_OC_StaticDiag_Ratio_HighLimit = 50U;
const uint16_t K_Motor1_N_OC_StaticDiag_Ratio_LowLimit = 0U; 
const uint16_t K_Motor1_N_OC_StaticDiag_Ratio_HighLimit = 10U;

const uint16_t K_Motor1_P_STB_StaticDiag_Ratio_LowLimit = 300U;  
const uint16_t K_Motor1_P_STB_StaticDiag_Ratio_HighLimit = 520U;
const uint16_t K_Motor1_N_STB_StaticDiag_Ratio_LowLimit = 300U;
const uint16_t K_Motor1_N_STB_StaticDiag_Ratio_HighLimit = 520U;

const uint16_t K_Motor1_P_Normal_StaticDiag_Ratio_LowLimit = 30U;  
const uint16_t K_Motor1_P_Normal_StaticDiag_Ratio_HighLimit = 50U;
const uint16_t K_Motor1_N_Normal_StaticDiag_Ratio_LowLimit = 30U;
const uint16_t K_Motor1_N_Normal_StaticDiag_Ratio_HighLimit = 50U;

const uint16_t K_Motor2_P_STG_StaticDiag_Ratio_LowLimit = 0U;  
const uint16_t K_Motor2_P_STG_StaticDiag_Ratio_HighLimit = 10U;
const uint16_t K_Motor2_N_STG_StaticDiag_Ratio_LowLimit = 0U;
const uint16_t K_Motor2_N_STG_StaticDiag_Ratio_HighLimit = 10U;

const uint16_t K_Motor2_P_OC_StaticDiag_Ratio_LowLimit = 30U;  
const uint16_t K_Motor2_P_OC_StaticDiag_Ratio_HighLimit = 50U;
const uint16_t K_Motor2_N_OC_StaticDiag_Ratio_LowLimit = 0U;
const uint16_t K_Motor2_N_OC_StaticDiag_Ratio_HighLimit = 10U;

const uint16_t K_Motor2_P_STB_StaticDiag_Ratio_LowLimit = 300U;
const uint16_t K_Motor2_P_STB_StaticDiag_Ratio_HighLimit = 520U;
const uint16_t K_Motor2_N_STB_StaticDiag_Ratio_LowLimit = 300U;
const uint16_t K_Motor2_N_STB_StaticDiag_Ratio_HighLimit = 520U;

const uint16_t K_Motor2_P_Normal_StaticDiag_Ratio_LowLimit = 30U; 
const uint16_t K_Motor2_P_Normal_StaticDiag_Ratio_HighLimit = 50U;
const uint16_t K_Motor2_N_Normal_StaticDiag_Ratio_LowLimit = 30U;
const uint16_t K_Motor2_N_Normal_StaticDiag_Ratio_HighLimit = 50U;
#endif

#ifdef _CONFIG_Gen3_Board
const uint16_t K_ReleaseMotor_P_STG_StaticDiag_Ratio_LowLimit = 0U;  
const uint16_t K_ReleaseMotor_P_STG_StaticDiag_Ratio_HighLimit = 10U; 

const uint16_t K_ReleaseMotor_P_OC_StaticDiag_Ratio_LowLimit = 230U;
const uint16_t K_ReleaseMotor_P_OC_StaticDiag_Ratio_HighLimit = 270U; 

const uint16_t K_ReleaseMotor_P_STB_StaticDiag_Ratio_LowLimit = 480U;  
const uint16_t K_ReleaseMotor_P_STB_StaticDiag_Ratio_HighLimit = 520U;

const uint16_t K_ReleaseMotor_P_Normal_StaticDiag_Ratio_LowLimit = 0U;  
const uint16_t K_ReleaseMotor_P_Normal_StaticDiag_Ratio_HighLimit = 50U; 

const uint16_t K_Buzzer_P_STG_StaticDiag_Ratio_LowLimit = 0U;  
const uint16_t K_Buzzer_P_STG_StaticDiag_Ratio_HighLimit = 10U; 

const uint16_t K_Buzzer_P_OC_StaticDiag_Ratio_LowLimit = 230U;   
const uint16_t K_Buzzer_P_OC_StaticDiag_Ratio_HighLimit = 270U; 

const uint16_t K_Buzzer_P_STB_StaticDiag_Ratio_LowLimit = 480U;  
const uint16_t K_Buzzer_P_STB_StaticDiag_Ratio_HighLimit = 520U;

const uint16_t K_Buzzer_P_Normal_StaticDiag_Ratio_LowLimit = 0U;  
const uint16_t K_Buzzer_P_Normal_StaticDiag_Ratio_HighLimit = 50U; 

const uint16_t K_Clutch_P_STG_StaticDiag_Ratio_LowLimit = 0U;  
const uint16_t K_Clutch_P_STG_StaticDiag_Ratio_HighLimit = 10U; 

const uint16_t K_Clutch_P_OC_StaticDiag_Ratio_LowLimit = 230U;  
const uint16_t K_Clutch_P_OC_StaticDiag_Ratio_HighLimit = 270U;

const uint16_t K_Clutch_P_STB_StaticDiag_Ratio_LowLimit = 480U;
const uint16_t K_Clutch_P_STB_StaticDiag_Ratio_HighLimit = 520U;

const uint16_t K_Clutch_P_Normal_StaticDiag_Ratio_LowLimit = 0U; 
const uint16_t K_Clutch_P_Normal_StaticDiag_Ratio_HighLimit = 50U; 

const uint16_t K_CinchMotor_P_STG_StaticDiag_Ratio_LowLimit = 0U;  
const uint16_t K_CinchMotor_P_STG_StaticDiag_Ratio_HighLimit = 30U;
const uint16_t K_CinchMotor_N_STG_StaticDiag_Ratio_LowLimit = 0U;
const uint16_t K_CinchMotor_N_STG_StaticDiag_Ratio_HighLimit = 30U;

const uint16_t K_CinchMotor_P_OC_StaticDiag_Ratio_LowLimit = 230U;  
const uint16_t K_CinchMotor_P_OC_StaticDiag_Ratio_HighLimit = 290U;
const uint16_t K_CinchMotor_N_OC_StaticDiag_Ratio_LowLimit = 0U;
const uint16_t K_CinchMotor_N_OC_StaticDiag_Ratio_HighLimit = 30U;

const uint16_t K_CinchMotor_P_STB_StaticDiag_Ratio_LowLimit = 450U;  
const uint16_t K_CinchMotor_P_STB_StaticDiag_Ratio_HighLimit = 520U;
const uint16_t K_CinchMotor_N_STB_StaticDiag_Ratio_LowLimit = 450U;
const uint16_t K_CinchMotor_N_STB_StaticDiag_Ratio_HighLimit = 520U;

const uint16_t K_CinchMotor_P_Normal_StaticDiag_Ratio_LowLimit = 170U;  
const uint16_t K_CinchMotor_P_Normal_StaticDiag_Ratio_HighLimit = 230U;
const uint16_t K_CinchMotor_N_Normal_StaticDiag_Ratio_LowLimit = 170U;
const uint16_t K_CinchMotor_N_Normal_StaticDiag_Ratio_HighLimit = 230U;

const uint16_t K_Motor1_P_STG_StaticDiag_Ratio_LowLimit = 0U;  
const uint16_t K_Motor1_P_STG_StaticDiag_Ratio_HighLimit = 30U;
const uint16_t K_Motor1_N_STG_StaticDiag_Ratio_LowLimit = 0U;
const uint16_t K_Motor1_N_STG_StaticDiag_Ratio_HighLimit = 30U;

const uint16_t K_Motor1_P_OC_StaticDiag_Ratio_LowLimit = 230U;  
const uint16_t K_Motor1_P_OC_StaticDiag_Ratio_HighLimit =290U;
const uint16_t K_Motor1_N_OC_StaticDiag_Ratio_LowLimit = 0U; 
const uint16_t K_Motor1_N_OC_StaticDiag_Ratio_HighLimit = 30U;

const uint16_t K_Motor1_P_STB_StaticDiag_Ratio_LowLimit = 450U;  
const uint16_t K_Motor1_P_STB_StaticDiag_Ratio_HighLimit = 520U;
const uint16_t K_Motor1_N_STB_StaticDiag_Ratio_LowLimit = 450U;
const uint16_t K_Motor1_N_STB_StaticDiag_Ratio_HighLimit = 520U;

const uint16_t K_Motor1_P_Normal_StaticDiag_Ratio_LowLimit = 170U;  
const uint16_t K_Motor1_P_Normal_StaticDiag_Ratio_HighLimit = 230U;
const uint16_t K_Motor1_N_Normal_StaticDiag_Ratio_LowLimit = 170U;
const uint16_t K_Motor1_N_Normal_StaticDiag_Ratio_HighLimit = 230U;

const uint16_t K_Motor2_P_STG_StaticDiag_Ratio_LowLimit = 0U;  
const uint16_t K_Motor2_P_STG_StaticDiag_Ratio_HighLimit = 30U;
const uint16_t K_Motor2_N_STG_StaticDiag_Ratio_LowLimit = 0U;
const uint16_t K_Motor2_N_STG_StaticDiag_Ratio_HighLimit = 30U;

const uint16_t K_Motor2_P_OC_StaticDiag_Ratio_LowLimit = 230U;  
const uint16_t K_Motor2_P_OC_StaticDiag_Ratio_HighLimit = 290U;
const uint16_t K_Motor2_N_OC_StaticDiag_Ratio_LowLimit = 0U;
const uint16_t K_Motor2_N_OC_StaticDiag_Ratio_HighLimit = 30U;

const uint16_t K_Motor2_P_STB_StaticDiag_Ratio_LowLimit = 450U;
const uint16_t K_Motor2_P_STB_StaticDiag_Ratio_HighLimit = 520U;
const uint16_t K_Motor2_N_STB_StaticDiag_Ratio_LowLimit = 450U;
const uint16_t K_Motor2_N_STB_StaticDiag_Ratio_HighLimit = 520U;

const uint16_t K_Motor2_P_Normal_StaticDiag_Ratio_LowLimit = 170U; 
const uint16_t K_Motor2_P_Normal_StaticDiag_Ratio_HighLimit = 230U;
const uint16_t K_Motor2_N_Normal_StaticDiag_Ratio_LowLimit = 170U;
const uint16_t K_Motor2_N_Normal_StaticDiag_Ratio_HighLimit = 230U;

#ifdef _CONFIG_Motor4
const uint16_t K_Motor4_P_STG_StaticDiag_Ratio_LowLimit = 0U;  
const uint16_t K_Motor4_P_STG_StaticDiag_Ratio_HighLimit = 30U;
const uint16_t K_Motor4_N_STG_StaticDiag_Ratio_LowLimit = 0U;
const uint16_t K_Motor4_N_STG_StaticDiag_Ratio_HighLimit = 30U;

const uint16_t K_Motor4_P_OC_StaticDiag_Ratio_LowLimit = 230U;  
const uint16_t K_Motor4_P_OC_StaticDiag_Ratio_HighLimit = 290U;
const uint16_t K_Motor4_N_OC_StaticDiag_Ratio_LowLimit = 0U;
const uint16_t K_Motor4_N_OC_StaticDiag_Ratio_HighLimit = 30U;

const uint16_t K_Motor4_P_STB_StaticDiag_Ratio_LowLimit = 450U;
const uint16_t K_Motor4_P_STB_StaticDiag_Ratio_HighLimit = 520U;
const uint16_t K_Motor4_N_STB_StaticDiag_Ratio_LowLimit = 450U;
const uint16_t K_Motor4_N_STB_StaticDiag_Ratio_HighLimit = 520U;

const uint16_t K_Motor4_P_Normal_StaticDiag_Ratio_LowLimit = 170U; 
const uint16_t K_Motor4_P_Normal_StaticDiag_Ratio_HighLimit = 230U;
const uint16_t K_Motor4_N_Normal_StaticDiag_Ratio_LowLimit = 170U;
const uint16_t K_Motor4_N_Normal_StaticDiag_Ratio_HighLimit = 230U;
#endif
#endif

#ifdef _CONFIG_Gen4_Board
const uint16_t K_ReleaseMotor_P_STG_StaticDiag_Ratio_LowLimit = 0U;  
const uint16_t K_ReleaseMotor_P_STG_StaticDiag_Ratio_HighLimit = 10U; 

const uint16_t K_ReleaseMotor_P_OC_StaticDiag_Ratio_LowLimit = 230U;
const uint16_t K_ReleaseMotor_P_OC_StaticDiag_Ratio_HighLimit = 270U; 

const uint16_t K_ReleaseMotor_P_STB_StaticDiag_Ratio_LowLimit = 480U;  
const uint16_t K_ReleaseMotor_P_STB_StaticDiag_Ratio_HighLimit = 520U;

const uint16_t K_ReleaseMotor_P_Normal_StaticDiag_Ratio_LowLimit = 0U;  
const uint16_t K_ReleaseMotor_P_Normal_StaticDiag_Ratio_HighLimit = 50U; 

const uint16_t K_Buzzer_P_STG_StaticDiag_Ratio_LowLimit = 0U;  
const uint16_t K_Buzzer_P_STG_StaticDiag_Ratio_HighLimit = 10U; 

const uint16_t K_Buzzer_P_OC_StaticDiag_Ratio_LowLimit = 230U;   
const uint16_t K_Buzzer_P_OC_StaticDiag_Ratio_HighLimit = 270U; 

const uint16_t K_Buzzer_P_STB_StaticDiag_Ratio_LowLimit = 480U;  
const uint16_t K_Buzzer_P_STB_StaticDiag_Ratio_HighLimit = 520U;

const uint16_t K_Buzzer_P_Normal_StaticDiag_Ratio_LowLimit = 0U;  
const uint16_t K_Buzzer_P_Normal_StaticDiag_Ratio_HighLimit = 50U; 

const uint16_t K_Clutch_P_STG_StaticDiag_Ratio_LowLimit = 0U;  
const uint16_t K_Clutch_P_STG_StaticDiag_Ratio_HighLimit = 10U; 

const uint16_t K_Clutch_P_OC_StaticDiag_Ratio_LowLimit = 230U;  
const uint16_t K_Clutch_P_OC_StaticDiag_Ratio_HighLimit = 270U;

const uint16_t K_Clutch_P_STB_StaticDiag_Ratio_LowLimit = 480U;
const uint16_t K_Clutch_P_STB_StaticDiag_Ratio_HighLimit = 520U;

const uint16_t K_Clutch_P_Normal_StaticDiag_Ratio_LowLimit = 0U; 
const uint16_t K_Clutch_P_Normal_StaticDiag_Ratio_HighLimit = 50U; 

const uint16_t K_CinchMotor_P_STG_StaticDiag_Ratio_LowLimit = 0U;  
const uint16_t K_CinchMotor_P_STG_StaticDiag_Ratio_HighLimit = 20U;
const uint16_t K_CinchMotor_N_STG_StaticDiag_Ratio_LowLimit = 0U;
const uint16_t K_CinchMotor_N_STG_StaticDiag_Ratio_HighLimit = 20U;

const uint16_t K_CinchMotor_P_OC_StaticDiag_Ratio_LowLimit = 90U;  
const uint16_t K_CinchMotor_P_OC_StaticDiag_Ratio_HighLimit = 130U;
const uint16_t K_CinchMotor_N_OC_StaticDiag_Ratio_LowLimit = 0U;
const uint16_t K_CinchMotor_N_OC_StaticDiag_Ratio_HighLimit = 30U;

const uint16_t K_CinchMotor_P_STB_StaticDiag_Ratio_LowLimit = 450U;  
const uint16_t K_CinchMotor_P_STB_StaticDiag_Ratio_HighLimit = 520U;
const uint16_t K_CinchMotor_N_STB_StaticDiag_Ratio_LowLimit = 450U;
const uint16_t K_CinchMotor_N_STB_StaticDiag_Ratio_HighLimit = 520U;

const uint16_t K_CinchMotor_P_Normal_StaticDiag_Ratio_LowLimit = 60U;  
const uint16_t K_CinchMotor_P_Normal_StaticDiag_Ratio_HighLimit = 100U;
const uint16_t K_CinchMotor_N_Normal_StaticDiag_Ratio_LowLimit = 60U;
const uint16_t K_CinchMotor_N_Normal_StaticDiag_Ratio_HighLimit = 100U;

const uint16_t K_Motor1_P_STG_StaticDiag_Ratio_LowLimit = 0U;  
const uint16_t K_Motor1_P_STG_StaticDiag_Ratio_HighLimit = 20U;
const uint16_t K_Motor1_N_STG_StaticDiag_Ratio_LowLimit = 0U;
const uint16_t K_Motor1_N_STG_StaticDiag_Ratio_HighLimit = 20U;

const uint16_t K_Motor1_P_OC_StaticDiag_Ratio_LowLimit = 90U;  
const uint16_t K_Motor1_P_OC_StaticDiag_Ratio_HighLimit =130U;
const uint16_t K_Motor1_N_OC_StaticDiag_Ratio_LowLimit = 0U; 
const uint16_t K_Motor1_N_OC_StaticDiag_Ratio_HighLimit = 30U;

const uint16_t K_Motor1_P_STB_StaticDiag_Ratio_LowLimit = 450U;  
const uint16_t K_Motor1_P_STB_StaticDiag_Ratio_HighLimit = 520U;
const uint16_t K_Motor1_N_STB_StaticDiag_Ratio_LowLimit = 450U;
const uint16_t K_Motor1_N_STB_StaticDiag_Ratio_HighLimit = 520U;

const uint16_t K_Motor1_P_Normal_StaticDiag_Ratio_LowLimit = 60U;  
const uint16_t K_Motor1_P_Normal_StaticDiag_Ratio_HighLimit = 100U;
const uint16_t K_Motor1_N_Normal_StaticDiag_Ratio_LowLimit = 60U;
const uint16_t K_Motor1_N_Normal_StaticDiag_Ratio_HighLimit = 100U;

const uint16_t K_Motor2_P_STG_StaticDiag_Ratio_LowLimit = 0U;  
const uint16_t K_Motor2_P_STG_StaticDiag_Ratio_HighLimit = 30U;
const uint16_t K_Motor2_N_STG_StaticDiag_Ratio_LowLimit = 0U;
const uint16_t K_Motor2_N_STG_StaticDiag_Ratio_HighLimit = 30U;

const uint16_t K_Motor2_P_OC_StaticDiag_Ratio_LowLimit = 230U;  
const uint16_t K_Motor2_P_OC_StaticDiag_Ratio_HighLimit = 290U;
const uint16_t K_Motor2_N_OC_StaticDiag_Ratio_LowLimit = 0U;
const uint16_t K_Motor2_N_OC_StaticDiag_Ratio_HighLimit = 30U;

const uint16_t K_Motor2_P_STB_StaticDiag_Ratio_LowLimit = 450U;
const uint16_t K_Motor2_P_STB_StaticDiag_Ratio_HighLimit = 520U;
const uint16_t K_Motor2_N_STB_StaticDiag_Ratio_LowLimit = 450U;
const uint16_t K_Motor2_N_STB_StaticDiag_Ratio_HighLimit = 520U;

const uint16_t K_Motor2_P_Normal_StaticDiag_Ratio_LowLimit = 170U; 
const uint16_t K_Motor2_P_Normal_StaticDiag_Ratio_HighLimit = 230U;
const uint16_t K_Motor2_N_Normal_StaticDiag_Ratio_LowLimit = 170U;
const uint16_t K_Motor2_N_Normal_StaticDiag_Ratio_HighLimit = 230U;

#ifdef _CONFIG_Motor4
const uint16_t K_Motor4_P_STG_StaticDiag_Ratio_LowLimit = 0U;  
const uint16_t K_Motor4_P_STG_StaticDiag_Ratio_HighLimit = 30U;
const uint16_t K_Motor4_N_STG_StaticDiag_Ratio_LowLimit = 0U;
const uint16_t K_Motor4_N_STG_StaticDiag_Ratio_HighLimit = 30U;

const uint16_t K_Motor4_P_OC_StaticDiag_Ratio_LowLimit = 230U;  
const uint16_t K_Motor4_P_OC_StaticDiag_Ratio_HighLimit = 290U;
const uint16_t K_Motor4_N_OC_StaticDiag_Ratio_LowLimit = 0U;
const uint16_t K_Motor4_N_OC_StaticDiag_Ratio_HighLimit = 30U;

const uint16_t K_Motor4_P_STB_StaticDiag_Ratio_LowLimit = 450U;
const uint16_t K_Motor4_P_STB_StaticDiag_Ratio_HighLimit = 520U;
const uint16_t K_Motor4_N_STB_StaticDiag_Ratio_LowLimit = 450U;
const uint16_t K_Motor4_N_STB_StaticDiag_Ratio_HighLimit = 520U;

const uint16_t K_Motor4_P_Normal_StaticDiag_Ratio_LowLimit = 170U; 
const uint16_t K_Motor4_P_Normal_StaticDiag_Ratio_HighLimit = 230U;
const uint16_t K_Motor4_N_Normal_StaticDiag_Ratio_LowLimit = 170U;
const uint16_t K_Motor4_N_Normal_StaticDiag_Ratio_HighLimit = 230U;
#endif
#endif

const uint16_t K_CinchMotor_STG_DynamicDiag_Time = 5U;  /* 20ms x  */
const uint16_t K_ReleaseMotor_STG_DynamicDiag_Time = 5U;  /* 20ms x  */
const uint16_t K_Buzzer_STG_DynamicDiag_Time = 5U;  /* 20ms x  */
const uint16_t K_Clutch_STG_DynamicDiag_Time = 5U;  /* 20ms x  */
const uint16_t K_Motor1_STG_DynamicDiag_Time = 5U;  /* 20ms x  */
const uint16_t K_Motor2_STG_DynamicDiag_Time = 5U;  /* 20ms x  */

const uint16_t K_CinchMotor_OC_DynamicDiag_Time = 100U;  /* 20ms x  */
const uint16_t K_ReleaseMotor_OC_DynamicDiag_Time = 100U;  /* 20ms x  */
const uint16_t K_Buzzer_OC_DynamicDiag_Time = 100U;  /* 20ms x  */
const uint16_t K_Clutch_OC_DynamicDiag_Time = 100U;  /* 20ms x  */
const uint16_t K_Motor1_OC_DynamicDiag_Time = 100U;  /* 20ms x  */
const uint16_t K_Motor2_OC_DynamicDiag_Time = 100U;  /* 20ms x  */

const uint16_t K_CinchMotor_STB_DynamicDiag_Time = 5U;  /* 20ms x  */
const uint16_t K_ReleaseMotor_STB_DynamicDiag_Time = 5U;  /* 20ms x  */
const uint16_t K_Buzzer_STB_DynamicDiag_Time = 5U;  /* 20ms x  */
const uint16_t K_Clutch_STB_DynamicDiag_Time = 5U;  /* 20ms x  */
const uint16_t K_Motor1_STB_DynamicDiag_Time = 5U;  /* 20ms x  */
const uint16_t K_Motor2_STB_DynamicDiag_Time = 5U;  /* 20ms x  */

const uint16_t K_CinchMotor_SCL_DynamicDiag_Time = 40U;  /* 20ms x  */
const uint16_t K_ReleaseMotor_SCL_DynamicDiag_Time = 40U;  /* 20ms x  */
const uint16_t K_Buzzer_SCL_DynamicDiag_Time = 40U;  /* 20ms x  */
const uint16_t K_Clutch_SCL_DynamicDiag_Time = 40U;  /* 20ms x  */
const uint16_t K_Motor1_SCL_DynamicDiag_Time = 40U;  /* 20ms x  */
const uint16_t K_Motor2_SCL_DynamicDiag_Time = 40U;  /* 20ms x  */

const uint16_t K_CinchMotor_Normal_DynamicDiag_Time = 5U;  /* 20ms x  */
const uint16_t K_ReleaseMotor_Normal_DynamicDiag_Time = 5U;  /* 20ms x  */
const uint16_t K_Buzzer_Normal_DynamicDiag_Time = 5U;  /* 20ms x  */
const uint16_t K_Clutch_Normal_DynamicDiag_Time = 5U;  /* 20ms x  */
const uint16_t K_Motor1_Normal_DynamicDiag_Time = 5U;  /* 20ms x  */
const uint16_t K_Motor2_Normal_DynamicDiag_Time = 5U;  /* 20ms x  */

const uint16_t K_Motor1_STG_DynamicDiag_Duty = 20;
const uint16_t K_Motor2_STG_DynamicDiag_Duty = 20;
const uint16_t K_CinchMotor_STG_DynamicDiag_Duty = 20;
const uint16_t K_ReleaseMotor_STG_DynamicDiag_Duty = 20;
const uint16_t K_Buzzer_STG_DynamicDiag_Duty = 20;
const uint16_t K_Clutch_STG_DynamicDiag_Duty = 20;

const uint16_t K_Motor1_OC_DynamicDiag_Duty = 50;
const uint16_t K_Motor2_OC_DynamicDiag_Duty = 50;
const uint16_t K_CinchMotor_OC_DynamicDiag_Duty = 50;
const uint16_t K_ReleaseMotor_OC_DynamicDiag_Duty = 50;
const uint16_t K_Buzzer_OC_DynamicDiag_Duty = 30;
const uint16_t K_Clutch_OC_DynamicDiag_Duty = 30;

const uint16_t K_Motor1_STB_DynamicDiag_Duty = 20;
const uint16_t K_Motor2_STB_DynamicDiag_Duty = 20;
const uint16_t K_CinchMotor_STB_DynamicDiag_Duty = 20;
const uint16_t K_ReleaseMotor_STB_DynamicDiag_Duty = 20;
const uint16_t K_Buzzer_STB_DynamicDiag_Duty = 20;
const uint16_t K_Clutch_STB_DynamicDiag_Duty = 20;

const uint16_t K_Motor1_STB_DynamicDiag_Duty_LowLimit = 40;
const uint16_t K_Motor2_STB_DynamicDiag_Duty_LowLimit = 40;
const uint16_t K_CinchMotor_STB_DynamicDiag_Duty_LowLimit = 40;
const uint16_t K_ReleaseMotor_STB_DynamicDiag_Duty_LowLimit = 60;
const uint16_t K_Buzzer_STB_DynamicDiag_Duty_LowLimit = 60;
const uint16_t K_Clutch_STB_DynamicDiag_Duty_LowLimit = 60;

const uint16_t K_Motor1_SCL_DynamicDiag_Duty = 20;
const uint16_t K_Motor2_SCL_DynamicDiag_Duty = 20;
const uint16_t K_CinchMotor_SCL_DynamicDiag_Duty = 20;
const uint16_t K_ReleaseMotor_SCL_DynamicDiag_Duty = 20;
const uint16_t K_Buzzer_SCL_DynamicDiag_Duty = 20;
const uint16_t K_Clutch_SCL_DynamicDiag_Duty = 20;

#ifdef _CONFIG_Gen1_Board
const uint16_t K_Motor1_Current_STG_DynamicDiag_Value = 3800;  /* 4095 = 5V Logic High */
const uint16_t K_Motor2_Current_STG_DynamicDiag_Value = 3800;  /* 4095 = 5V Logic High */
const uint16_t K_CinchMotor_Current_STG_DynamicDiag_Value = 3800;  /* 4095 = 5V Logic High */
const uint16_t K_ReleaseMotor_Current_STG_DynamicDiag_Value = 3800;  /* 4095 = 5V Logic High */
const uint16_t K_Buzzer_Current_STG_DynamicDiag_Value = 3800;  /* 4095 = 5V Logic High */
const uint16_t K_Clutch_Current_STG_DynamicDiag_Value = 3800;  /* 4095 = 5V Logic High */

const uint16_t K_ReleaseMotor_Current_STB_StaticDiag_Value = 3800;  /* 4095 = 5V Logic High */
const uint16_t K_Buzzer_Current_STB_StaticDiag_Value = 3800;  /* 4095 = 5V Logic High */
const uint16_t K_Clutch_Current_STB_StaticDiag_Value = 3800;  /* 4095 = 5V Logic High */

const uint16_t K_Motor1_Current_OC_DynamicDiag_Value = 2;  /* 100 = 1A */
const uint16_t K_Motor2_Current_OC_DynamicDiag_Value = 2;  /* 100 = 1A */
const uint16_t K_CinchMotor_Current_OC_DynamicDiag_Value = 2;  /* 100 = 1A */
const uint16_t K_ReleaseMotor_Current_OC_DynamicDiag_Value = 2;  /* 100 = 1A */
const uint16_t K_Buzzer_Current_OC_DynamicDiag_Value = 2;  /* 100 = 1A */
const uint16_t K_Clutch_Current_OC_DynamicDiag_Value = 2;  /* 100 = 1A */

const uint16_t K_Motor1_Current_STB_DynamicDiag_Value = 3800;  /* 4095 = 5V Logic High */
const uint16_t K_Motor2_Current_STB_DynamicDiag_Value = 3800;  /* 4095 = 5V Logic High */
const uint16_t K_CinchMotor_Current_STB_DynamicDiag_Value = 3800;  /* 4095 = 5V Logic High */
const uint16_t K_ReleaseMotor_Current_STB_DynamicDiag_Value = 3800;  /* 4095 = 5V Logic High */
const uint16_t K_Buzzer_Current_STB_DynamicDiag_Value = 3800;  /* 4095 = 5V Logic High */
const uint16_t K_Clutch_Current_STB_DynamicDiag_Value = 3800;  /* 4095 = 5V Logic High */

const uint16_t K_Motor1_Current_STB_DynamicDiag_Value_HighLimit = 1000;  /* 4095 = 5V Logic High */
const uint16_t K_Motor2_Current_STB_DynamicDiag_Value_HighLimit = 1000;  /* 4095 = 5V Logic High */
const uint16_t K_CinchMotor_Current_STB_DynamicDiag_Value_HighLimit = 1000;  /* 4095 = 5V Logic High */
const uint16_t K_ReleaseMotor_Current_STB_DynamicDiag_Value_HighLimit = 1000;  /* 4095 = 5V Logic High */
const uint16_t K_Buzzer_Current_STB_DynamicDiag_Value_HighLimit = 1000;  /* 4095 = 5V Logic High */
const uint16_t K_Clutch_Current_STB_DynamicDiag_Value_HighLimit = 1000;  /* 4095 = 5V Logic High */

const uint16_t K_Motor1_Current_STB_DynamicDiag_Value_LowLimit = 20;  /* 4095 = 5V Logic High */
const uint16_t K_Motor2_Current_STB_DynamicDiag_Value_LowLimit = 20;  /* 4095 = 5V Logic High */
const uint16_t K_CinchMotor_Current_STB_DynamicDiag_Value_LowLimit = 20;  /* 4095 = 5V Logic High */
const uint16_t K_ReleaseMotor_Current_STB_DynamicDiag_Value_LowLimit = 20;  /* 4095 = 5V Logic High */
const uint16_t K_Buzzer_Current_STB_DynamicDiag_Value_LowLimit = 20;  /* 4095 = 5V Logic High */
const uint16_t K_Clutch_Current_STB_DynamicDiag_Value_LowLimit = 20;  /* 4095 = 5V Logic High */

const uint16_t K_Motor1_Current_SCL_DynamicDiag_Value = 3800;  /* 4095 = 5V Logic High */
const uint16_t K_Motor2_Current_SCL_DynamicDiag_Value = 3800;  /* 4095 = 5V Logic High */
const uint16_t K_CinchMotor_Current_SCL_DynamicDiag_Value = 3800;  /* 4095 = 5V Logic High */
const uint16_t K_ReleaseMotor_Current_SCL_DynamicDiag_Value = 3800;  /* 4095 = 5V Logic High */
const uint16_t K_Buzzer_Current_SCL_DynamicDiag_Value = 3800;  /* 4095 = 5V Logic High */
const uint16_t K_Clutch_Current_SCL_DynamicDiag_Value = 3800;  /* 4095 = 5V Logic High */

const uint16_t K_Motor1_P_STG_DynamicDiag_Ratio_LowLimit = 0U;  
const uint16_t K_Motor1_P_STG_DynamicDiag_Ratio_HighLimit = 2U;
const uint16_t K_Motor1_N_STG_DynamicDiag_Ratio_LowLimit = 0U;
const uint16_t K_Motor1_N_STG_DynamicDiag_Ratio_HighLimit = 2U;

const uint16_t K_Motor1_P_OC_DynamicDiag_Ratio_LowLimit = 0U;  
const uint16_t K_Motor1_P_OC_DynamicDiag_Ratio_HighLimit = 2U;
const uint16_t K_Motor1_N_OC_DynamicDiag_Ratio_LowLimit = 80U;
const uint16_t K_Motor1_N_OC_DynamicDiag_Ratio_HighLimit = 90U;

const uint16_t K_Motor1_P_STB_DynamicDiag_Ratio_LowLimit = 110U;  
const uint16_t K_Motor1_P_STB_DynamicDiag_Ratio_HighLimit = 120U;
const uint16_t K_Motor1_N_STB_DynamicDiag_Ratio_LowLimit = 110U;
const uint16_t K_Motor1_N_STB_DynamicDiag_Ratio_HighLimit = 120U;

const uint16_t K_Motor1_P_Normal_DynamicDiag_Ratio_LowLimit = 68U;  
const uint16_t K_Motor1_P_Normal_DynamicDiag_Ratio_HighLimit = 78U;
const uint16_t K_Motor1_N_Normal_DynamicDiag_Ratio_LowLimit = 68U;
const uint16_t K_Motor1_N_Normal_DynamicDiag_Ratio_HighLimit = 78U;

const uint16_t K_Motor2_P_STG_DynamicDiag_Ratio_LowLimit = 0U;  
const uint16_t K_Motor2_P_STG_DynamicDiag_Ratio_HighLimit = 2U;
const uint16_t K_Motor2_N_STG_DynamicDiag_Ratio_LowLimit = 0U;
const uint16_t K_Motor2_N_STG_DynamicDiag_Ratio_HighLimit = 2U;

const uint16_t K_Motor2_P_OC_DynamicDiag_Ratio_LowLimit = 0U;  
const uint16_t K_Motor2_P_OC_DynamicDiag_Ratio_HighLimit = 2U;
const uint16_t K_Motor2_N_OC_DynamicDiag_Ratio_LowLimit = 80U;
const uint16_t K_Motor2_N_OC_DynamicDiag_Ratio_HighLimit = 90U;

const uint16_t K_Motor2_P_STB_DynamicDiag_Ratio_LowLimit = 110U;  
const uint16_t K_Motor2_P_STB_DynamicDiag_Ratio_HighLimit = 120U;
const uint16_t K_Motor2_N_STB_DynamicDiag_Ratio_LowLimit = 110U;
const uint16_t K_Motor2_N_STB_DynamicDiag_Ratio_HighLimit = 120U;

const uint16_t K_Motor2_P_Normal_DynamicDiag_Ratio_LowLimit = 68U;  
const uint16_t K_Motor2_P_Normal_DynamicDiag_Ratio_HighLimit = 78U;
const uint16_t K_Motor2_N_Normal_DynamicDiag_Ratio_LowLimit = 68U;
const uint16_t K_Motor2_N_Normal_DynamicDiag_Ratio_HighLimit = 78U;

const uint16_t K_CinchMotor_P_STG_DynamicDiag_Ratio_LowLimit = 0U;  
const uint16_t K_CinchMotor_P_STG_DynamicDiag_Ratio_HighLimit = 10U;
const uint16_t K_CinchMotor_N_STG_DynamicDiag_Ratio_LowLimit = 0U;
const uint16_t K_CinchMotor_N_STG_DynamicDiag_Ratio_HighLimit = 10U;

const uint16_t K_CinchMotor_P_OC_DynamicDiag_Ratio_LowLimit = 0U;  
const uint16_t K_CinchMotor_P_OC_DynamicDiag_Ratio_HighLimit = 2U;
const uint16_t K_CinchMotor_N_OC_DynamicDiag_Ratio_LowLimit = 39U;
const uint16_t K_CinchMotor_N_OC_DynamicDiag_Ratio_HighLimit = 49U;

const uint16_t K_CinchMotor_P_STB_DynamicDiag_Ratio_LowLimit = 110U;  
const uint16_t K_CinchMotor_P_STB_DynamicDiag_Ratio_HighLimit = 120U;
const uint16_t K_CinchMotor_N_STB_DynamicDiag_Ratio_LowLimit = 110U;
const uint16_t K_CinchMotor_N_STB_DynamicDiag_Ratio_HighLimit = 120U;

const uint16_t K_CinchMotor_P_Normal_DynamicDiag_Ratio_LowLimit = 25U;  
const uint16_t K_CinchMotor_P_Normal_DynamicDiag_Ratio_HighLimit = 42U;
const uint16_t K_CinchMotor_N_Normal_DynamicDiag_Ratio_LowLimit = 25U;
const uint16_t K_CinchMotor_N_Normal_DynamicDiag_Ratio_HighLimit = 42U;

const uint16_t K_ReleaseMotor_P_STG_DynamicDiag_Ratio_LowLimit = 0U;  
const uint16_t K_ReleaseMotor_P_STG_DynamicDiag_Ratio_HighLimit = 5U;

const uint16_t K_ReleaseMotor_P_OC_DynamicDiag_Ratio_LowLimit = 0U;  
const uint16_t K_ReleaseMotor_P_OC_DynamicDiag_Ratio_HighLimit = 10U;

const uint16_t K_ReleaseMotor_P_STB_DynamicDiag_Ratio_LowLimit = 110U;  
const uint16_t K_ReleaseMotor_P_STB_DynamicDiag_Ratio_HighLimit = 120U;

const uint16_t K_ReleaseMotor_P_Normal_DynamicDiag_Ratio_LowLimit = 48U;  
const uint16_t K_ReleaseMotor_P_Normal_DynamicDiag_Ratio_HighLimit = 54U;

const uint16_t K_Buzzer_P_STG_DynamicDiag_Ratio_LowLimit = 0U;  
const uint16_t K_Buzzer_P_STG_DynamicDiag_Ratio_HighLimit = 5U;

const uint16_t K_Buzzer_P_OC_DynamicDiag_Ratio_LowLimit = 0U;  
const uint16_t K_Buzzer_P_OC_DynamicDiag_Ratio_HighLimit = 50U;

const uint16_t K_Buzzer_P_STB_DynamicDiag_Ratio_LowLimit = 110U;  
const uint16_t K_Buzzer_P_STB_DynamicDiag_Ratio_HighLimit = 120U;

const uint16_t K_Buzzer_P_Normal_DynamicDiag_Ratio_LowLimit = 48U;  
const uint16_t K_Buzzer_P_Normal_DynamicDiag_Ratio_HighLimit = 54U;

const uint16_t K_Clutch_P_STG_DynamicDiag_Ratio_LowLimit = 0U;  
const uint16_t K_Clutch_P_STG_DynamicDiag_Ratio_HighLimit = 5U;

const uint16_t K_Clutch_P_OC_DynamicDiag_Ratio_LowLimit = 0U;  
const uint16_t K_Clutch_P_OC_DynamicDiag_Ratio_HighLimit = 50U;

const uint16_t K_Clutch_P_STB_DynamicDiag_Ratio_LowLimit = 110U;  
const uint16_t K_Clutch_P_STB_DynamicDiag_Ratio_HighLimit = 120U;

const uint16_t K_Clutch_P_Normal_DynamicDiag_Ratio_LowLimit = 48U;  
const uint16_t K_Clutch_P_Normal_DynamicDiag_Ratio_HighLimit = 54U;

const uint16_t K_ModeSwitch_STG_StaticDiag_Ratio = 10U; 
const uint16_t K_ModeSwitch_OC_StaticDiag_Ratio = 90U;
const uint16_t K_ModeSwitch_STB_StaticDiag_Ratio = 95U;
const uint16_t K_ModeSwitch_StaticDiag_Time = 5U; /* 100ms x  */
#endif

#ifdef _CONFIG_Gen2_Board
const uint16_t K_Motor1_Current_STG_DynamicDiag_Value = 3800;  /* 4095 = 5V Logic High */
const uint16_t K_Motor2_Current_STG_DynamicDiag_Value = 3800;  /* 4095 = 5V Logic High */
const uint16_t K_CinchMotor_Current_STG_DynamicDiag_Value = 3800;  /* 4095 = 5V Logic High */
const uint16_t K_ReleaseMotor_Current_STG_DynamicDiag_Value = 3800;  /* 4095 = 5V Logic High */
const uint16_t K_Buzzer_Current_STG_DynamicDiag_Value = 3800;  /* 4095 = 5V Logic High */
const uint16_t K_Clutch_Current_STG_DynamicDiag_Value = 3800;  /* 4095 = 5V Logic High */

const uint16_t K_ReleaseMotor_Current_STB_StaticDiag_Value = 3800;  /* 4095 = 5V Logic High */
const uint16_t K_Buzzer_Current_STB_StaticDiag_Value = 3800;  /* 4095 = 5V Logic High */
const uint16_t K_Clutch_Current_STB_StaticDiag_Value = 3800;  /* 4095 = 5V Logic High */

#ifdef _CONFIG_IntevaSideLatch
const uint16_t K_Motor2_Current_OC_DynamicDiag_Value = 50;  /* 100 = 1A */
const uint16_t K_CinchMotor_Current_OC_DynamicDiag_Value = 30;//2;  /* 100 = 1A */
#else
const uint16_t K_Motor2_Current_OC_DynamicDiag_Value = 2;  /* 100 = 1A */
const uint16_t K_CinchMotor_Current_OC_DynamicDiag_Value = 2;  /* 100 = 1A */
#endif
const uint16_t K_Motor1_Current_OC_DynamicDiag_Value = 2;  /* 100 = 1A */
const uint16_t K_ReleaseMotor_Current_OC_DynamicDiag_Value = 2;  /* 100 = 1A */
const uint16_t K_Buzzer_Current_OC_DynamicDiag_Value = 2;  /* 100 = 1A */
const uint16_t K_Clutch_Current_OC_DynamicDiag_Value = 2;  /* 100 = 1A */

const uint16_t K_Motor1_Current_STB_DynamicDiag_Value = 3800;  /* 4095 = 5V Logic High */
const uint16_t K_Motor2_Current_STB_DynamicDiag_Value = 3800;  /* 4095 = 5V Logic High */
const uint16_t K_CinchMotor_Current_STB_DynamicDiag_Value = 3800;  /* 4095 = 5V Logic High */
const uint16_t K_ReleaseMotor_Current_STB_DynamicDiag_Value = 3800;  /* 4095 = 5V Logic High */
const uint16_t K_Buzzer_Current_STB_DynamicDiag_Value = 3800;  /* 4095 = 5V Logic High */
const uint16_t K_Clutch_Current_STB_DynamicDiag_Value = 3800;  /* 4095 = 5V Logic High */

const uint16_t K_Motor1_Current_STB_DynamicDiag_Value_HighLimit = 1000;  /* 4095 = 5V Logic High */
const uint16_t K_Motor2_Current_STB_DynamicDiag_Value_HighLimit = 1000;  /* 4095 = 5V Logic High */
const uint16_t K_CinchMotor_Current_STB_DynamicDiag_Value_HighLimit = 1000;  /* 4095 = 5V Logic High */
const uint16_t K_ReleaseMotor_Current_STB_DynamicDiag_Value_HighLimit = 1000;  /* 4095 = 5V Logic High */
const uint16_t K_Buzzer_Current_STB_DynamicDiag_Value_HighLimit = 1000;  /* 4095 = 5V Logic High */
const uint16_t K_Clutch_Current_STB_DynamicDiag_Value_HighLimit = 1000;  /* 4095 = 5V Logic High */

const uint16_t K_Motor1_Current_STB_DynamicDiag_Value_LowLimit = 20;  /* 4095 = 5V Logic High */
const uint16_t K_Motor2_Current_STB_DynamicDiag_Value_LowLimit = 20;  /* 4095 = 5V Logic High */
const uint16_t K_CinchMotor_Current_STB_DynamicDiag_Value_LowLimit = 20;  /* 4095 = 5V Logic High */
const uint16_t K_ReleaseMotor_Current_STB_DynamicDiag_Value_LowLimit = 20;  /* 4095 = 5V Logic High */
const uint16_t K_Buzzer_Current_STB_DynamicDiag_Value_LowLimit = 20;  /* 4095 = 5V Logic High */
const uint16_t K_Clutch_Current_STB_DynamicDiag_Value_LowLimit = 20;  /* 4095 = 5V Logic High */

const uint16_t K_Motor1_Current_SCL_DynamicDiag_Value = 3800;  /* 4095 = 5V Logic High */
const uint16_t K_Motor2_Current_SCL_DynamicDiag_Value = 3800;  /* 4095 = 5V Logic High */
const uint16_t K_CinchMotor_Current_SCL_DynamicDiag_Value = 3800;  /* 4095 = 5V Logic High */
const uint16_t K_ReleaseMotor_Current_SCL_DynamicDiag_Value = 3800;  /* 4095 = 5V Logic High */
const uint16_t K_Buzzer_Current_SCL_DynamicDiag_Value = 3800;  /* 4095 = 5V Logic High */
const uint16_t K_Clutch_Current_SCL_DynamicDiag_Value = 3800;  /* 4095 = 5V Logic High */

const uint16_t K_Motor1_P_STG_DynamicDiag_Ratio_LowLimit = 0U;  
const uint16_t K_Motor1_P_STG_DynamicDiag_Ratio_HighLimit = 2U;
const uint16_t K_Motor1_N_STG_DynamicDiag_Ratio_LowLimit = 0U;
const uint16_t K_Motor1_N_STG_DynamicDiag_Ratio_HighLimit = 2U;

const uint16_t K_Motor1_P_OC_DynamicDiag_Ratio_LowLimit = 0U;  
const uint16_t K_Motor1_P_OC_DynamicDiag_Ratio_HighLimit = 2U;
const uint16_t K_Motor1_N_OC_DynamicDiag_Ratio_LowLimit = 80U;
const uint16_t K_Motor1_N_OC_DynamicDiag_Ratio_HighLimit = 90U;

const uint16_t K_Motor1_P_STB_DynamicDiag_Ratio_LowLimit = 110U;  
const uint16_t K_Motor1_P_STB_DynamicDiag_Ratio_HighLimit = 120U;
const uint16_t K_Motor1_N_STB_DynamicDiag_Ratio_LowLimit = 110U;
const uint16_t K_Motor1_N_STB_DynamicDiag_Ratio_HighLimit = 120U;

const uint16_t K_Motor1_P_Normal_DynamicDiag_Ratio_LowLimit = 68U;  
const uint16_t K_Motor1_P_Normal_DynamicDiag_Ratio_HighLimit = 78U;
const uint16_t K_Motor1_N_Normal_DynamicDiag_Ratio_LowLimit = 68U;
const uint16_t K_Motor1_N_Normal_DynamicDiag_Ratio_HighLimit = 78U;

const uint16_t K_Motor2_P_STG_DynamicDiag_Ratio_LowLimit = 0U;  
const uint16_t K_Motor2_P_STG_DynamicDiag_Ratio_HighLimit = 2U;
const uint16_t K_Motor2_N_STG_DynamicDiag_Ratio_LowLimit = 0U;
const uint16_t K_Motor2_N_STG_DynamicDiag_Ratio_HighLimit = 2U;

const uint16_t K_Motor2_P_OC_DynamicDiag_Ratio_LowLimit = 0U;  
const uint16_t K_Motor2_P_OC_DynamicDiag_Ratio_HighLimit = 2U;
const uint16_t K_Motor2_N_OC_DynamicDiag_Ratio_LowLimit = 80U;
const uint16_t K_Motor2_N_OC_DynamicDiag_Ratio_HighLimit = 90U;

const uint16_t K_Motor2_P_STB_DynamicDiag_Ratio_LowLimit = 110U;  
const uint16_t K_Motor2_P_STB_DynamicDiag_Ratio_HighLimit = 120U;
const uint16_t K_Motor2_N_STB_DynamicDiag_Ratio_LowLimit = 110U;
const uint16_t K_Motor2_N_STB_DynamicDiag_Ratio_HighLimit = 120U;

const uint16_t K_Motor2_P_Normal_DynamicDiag_Ratio_LowLimit = 68U;  
const uint16_t K_Motor2_P_Normal_DynamicDiag_Ratio_HighLimit = 78U;
const uint16_t K_Motor2_N_Normal_DynamicDiag_Ratio_LowLimit = 68U;
const uint16_t K_Motor2_N_Normal_DynamicDiag_Ratio_HighLimit = 78U;

const uint16_t K_CinchMotor_P_STG_DynamicDiag_Ratio_LowLimit = 0U;  
const uint16_t K_CinchMotor_P_STG_DynamicDiag_Ratio_HighLimit = 2U;
const uint16_t K_CinchMotor_N_STG_DynamicDiag_Ratio_LowLimit = 0U;
const uint16_t K_CinchMotor_N_STG_DynamicDiag_Ratio_HighLimit = 2U;

const uint16_t K_CinchMotor_P_OC_DynamicDiag_Ratio_LowLimit = 0U;  
const uint16_t K_CinchMotor_P_OC_DynamicDiag_Ratio_HighLimit = 2U;
const uint16_t K_CinchMotor_N_OC_DynamicDiag_Ratio_LowLimit = 39U;
const uint16_t K_CinchMotor_N_OC_DynamicDiag_Ratio_HighLimit = 49U;

const uint16_t K_CinchMotor_P_STB_DynamicDiag_Ratio_LowLimit = 110U;  
const uint16_t K_CinchMotor_P_STB_DynamicDiag_Ratio_HighLimit = 120U;
const uint16_t K_CinchMotor_N_STB_DynamicDiag_Ratio_LowLimit = 110U;
const uint16_t K_CinchMotor_N_STB_DynamicDiag_Ratio_HighLimit = 120U;

const uint16_t K_CinchMotor_P_Normal_DynamicDiag_Ratio_LowLimit = 25U;  
const uint16_t K_CinchMotor_P_Normal_DynamicDiag_Ratio_HighLimit = 42U;
const uint16_t K_CinchMotor_N_Normal_DynamicDiag_Ratio_LowLimit = 25U;
const uint16_t K_CinchMotor_N_Normal_DynamicDiag_Ratio_HighLimit = 42U;

const uint16_t K_ReleaseMotor_P_STG_DynamicDiag_Ratio_LowLimit = 0U;  
const uint16_t K_ReleaseMotor_P_STG_DynamicDiag_Ratio_HighLimit = 5U;

const uint16_t K_ReleaseMotor_P_OC_DynamicDiag_Ratio_LowLimit = 0U;  
const uint16_t K_ReleaseMotor_P_OC_DynamicDiag_Ratio_HighLimit = 10U;

const uint16_t K_ReleaseMotor_P_STB_DynamicDiag_Ratio_LowLimit = 110U;  
const uint16_t K_ReleaseMotor_P_STB_DynamicDiag_Ratio_HighLimit = 120U;

const uint16_t K_ReleaseMotor_P_Normal_DynamicDiag_Ratio_LowLimit = 48U;  
const uint16_t K_ReleaseMotor_P_Normal_DynamicDiag_Ratio_HighLimit = 54U;

const uint16_t K_Buzzer_P_STG_DynamicDiag_Ratio_LowLimit = 0U;  
const uint16_t K_Buzzer_P_STG_DynamicDiag_Ratio_HighLimit = 5U;

const uint16_t K_Buzzer_P_OC_DynamicDiag_Ratio_LowLimit = 0U;  
const uint16_t K_Buzzer_P_OC_DynamicDiag_Ratio_HighLimit = 50U;

const uint16_t K_Buzzer_P_STB_DynamicDiag_Ratio_LowLimit = 110U;  
const uint16_t K_Buzzer_P_STB_DynamicDiag_Ratio_HighLimit = 120U;

const uint16_t K_Buzzer_P_Normal_DynamicDiag_Ratio_LowLimit = 48U;  
const uint16_t K_Buzzer_P_Normal_DynamicDiag_Ratio_HighLimit = 54U;

const uint16_t K_Clutch_P_STG_DynamicDiag_Ratio_LowLimit = 0U;  
const uint16_t K_Clutch_P_STG_DynamicDiag_Ratio_HighLimit = 5U;

const uint16_t K_Clutch_P_OC_DynamicDiag_Ratio_LowLimit = 0U;  
const uint16_t K_Clutch_P_OC_DynamicDiag_Ratio_HighLimit = 50U;

const uint16_t K_Clutch_P_STB_DynamicDiag_Ratio_LowLimit = 110U;  
const uint16_t K_Clutch_P_STB_DynamicDiag_Ratio_HighLimit = 120U;

const uint16_t K_Clutch_P_Normal_DynamicDiag_Ratio_LowLimit = 48U;  
const uint16_t K_Clutch_P_Normal_DynamicDiag_Ratio_HighLimit = 54U;

const uint16_t K_ModeSwitch_STG_StaticDiag_Value = 10U; 
const uint16_t K_ModeSwitch_OC_StaticDiag_Value = 450U;
const uint16_t K_ModeSwitch_STB_StaticDiag_Value = 495U;
const uint16_t K_ModeSwitch_StaticDiag_Time = 5U; /* 100ms x  */
#endif


#ifdef _CONFIG_Gen3_Board
const uint16_t K_Motor1_Current_STG_DynamicDiag_Value = 3800;  /* 4095 = 5V Logic High */
const uint16_t K_Motor2_Current_STG_DynamicDiag_Value = 3800;  /* 4095 = 5V Logic High */
const uint16_t K_Motor4_Current_STG_DynamicDiag_Value = 3800;  /* 4095 = 5V Logic High */
const uint16_t K_CinchMotor_Current_STG_DynamicDiag_Value = 3800;  /* 4095 = 5V Logic High */
const uint16_t K_ReleaseMotor_Current_STG_DynamicDiag_Value = 3800;  /* 4095 = 5V Logic High */
const uint16_t K_Buzzer_Current_STG_DynamicDiag_Value = 3800;  /* 4095 = 5V Logic High */
const uint16_t K_Clutch_Current_STG_DynamicDiag_Value = 3800;  /* 4095 = 5V Logic High */

const uint16_t K_ReleaseMotor_Current_STB_StaticDiag_Value = 3800;  /* 4095 = 5V Logic High */
const uint16_t K_Buzzer_Current_STB_StaticDiag_Value = 3800;  /* 4095 = 5V Logic High */
const uint16_t K_Clutch_Current_STB_StaticDiag_Value = 3800;  /* 4095 = 5V Logic High */

#ifdef _CONFIG_IntevaSideLatch
const uint16_t K_Motor2_Current_OC_DynamicDiag_Value = 50;  /* 100 = 1A */
const uint16_t K_CinchMotor_Current_OC_DynamicDiag_Value = 30;//2;  /* 100 = 1A */
#else
const uint16_t K_Motor2_Current_OC_DynamicDiag_Value = 2;  /* 100 = 1A */
const uint16_t K_CinchMotor_Current_OC_DynamicDiag_Value = 2;  /* 100 = 1A */
#endif
const uint16_t K_Motor1_Current_OC_DynamicDiag_Value = 2;  /* 100 = 1A */
const uint16_t K_Motor4_Current_OC_DynamicDiag_Value = 2;  /* 100 = 1A */
const uint16_t K_ReleaseMotor_Current_OC_DynamicDiag_Value = 2;  /* 100 = 1A */
const uint16_t K_Buzzer_Current_OC_DynamicDiag_Value = 2;  /* 100 = 1A */
const uint16_t K_Clutch_Current_OC_DynamicDiag_Value = 2;  /* 100 = 1A */

const uint16_t K_Motor1_Current_STB_DynamicDiag_Value = 3800;  /* 4095 = 5V Logic High */
const uint16_t K_Motor2_Current_STB_DynamicDiag_Value = 3800;  /* 4095 = 5V Logic High */
const uint16_t K_Motor4_Current_STB_DynamicDiag_Value = 3800;  /* 4095 = 5V Logic High */
const uint16_t K_CinchMotor_Current_STB_DynamicDiag_Value = 3800;  /* 4095 = 5V Logic High */
const uint16_t K_ReleaseMotor_Current_STB_DynamicDiag_Value = 3800;  /* 4095 = 5V Logic High */
const uint16_t K_Buzzer_Current_STB_DynamicDiag_Value = 3800;  /* 4095 = 5V Logic High */
const uint16_t K_Clutch_Current_STB_DynamicDiag_Value = 3800;  /* 4095 = 5V Logic High */

const uint16_t K_Motor1_Current_STB_DynamicDiag_Value_HighLimit = 1000;  /* 4095 = 5V Logic High */
const uint16_t K_Motor2_Current_STB_DynamicDiag_Value_HighLimit = 1000;  /* 4095 = 5V Logic High */
const uint16_t K_Motor4_Current_STB_DynamicDiag_Value_HighLimit = 1000;  /* 4095 = 5V Logic High */
const uint16_t K_CinchMotor_Current_STB_DynamicDiag_Value_HighLimit = 1000;  /* 4095 = 5V Logic High */
const uint16_t K_ReleaseMotor_Current_STB_DynamicDiag_Value_HighLimit = 1000;  /* 4095 = 5V Logic High */
const uint16_t K_Buzzer_Current_STB_DynamicDiag_Value_HighLimit = 1000;  /* 4095 = 5V Logic High */
const uint16_t K_Clutch_Current_STB_DynamicDiag_Value_HighLimit = 1000;  /* 4095 = 5V Logic High */

const uint16_t K_Motor1_Current_STB_DynamicDiag_Value_LowLimit = 20;  /* 4095 = 5V Logic High */
const uint16_t K_Motor2_Current_STB_DynamicDiag_Value_LowLimit = 20;  /* 4095 = 5V Logic High */
const uint16_t K_Motor4_Current_STB_DynamicDiag_Value_LowLimit = 20;  /* 4095 = 5V Logic High */
const uint16_t K_CinchMotor_Current_STB_DynamicDiag_Value_LowLimit = 20;  /* 4095 = 5V Logic High */
const uint16_t K_ReleaseMotor_Current_STB_DynamicDiag_Value_LowLimit = 20;  /* 4095 = 5V Logic High */
const uint16_t K_Buzzer_Current_STB_DynamicDiag_Value_LowLimit = 20;  /* 4095 = 5V Logic High */
const uint16_t K_Clutch_Current_STB_DynamicDiag_Value_LowLimit = 20;  /* 4095 = 5V Logic High */

const uint16_t K_Motor1_Current_SCL_DynamicDiag_Value = 3800;  /* 4095 = 5V Logic High */
const uint16_t K_Motor2_Current_SCL_DynamicDiag_Value = 3800;  /* 4095 = 5V Logic High */
const uint16_t K_Motor4_Current_SCL_DynamicDiag_Value = 3800;  /* 4095 = 5V Logic High */
const uint16_t K_CinchMotor_Current_SCL_DynamicDiag_Value = 3800;  /* 4095 = 5V Logic High */
const uint16_t K_ReleaseMotor_Current_SCL_DynamicDiag_Value = 3800;  /* 4095 = 5V Logic High */
const uint16_t K_Buzzer_Current_SCL_DynamicDiag_Value = 3800;  /* 4095 = 5V Logic High */
const uint16_t K_Clutch_Current_SCL_DynamicDiag_Value = 3800;  /* 4095 = 5V Logic High */

const uint16_t K_Motor1_P_STG_DynamicDiag_Ratio_LowLimit = 0U;  
const uint16_t K_Motor1_P_STG_DynamicDiag_Ratio_HighLimit = 2U;
const uint16_t K_Motor1_N_STG_DynamicDiag_Ratio_LowLimit = 0U;
const uint16_t K_Motor1_N_STG_DynamicDiag_Ratio_HighLimit = 2U;

const uint16_t K_Motor1_P_OC_DynamicDiag_Ratio_LowLimit = 0U;  
const uint16_t K_Motor1_P_OC_DynamicDiag_Ratio_HighLimit = 2U;
const uint16_t K_Motor1_N_OC_DynamicDiag_Ratio_LowLimit = 80U;
const uint16_t K_Motor1_N_OC_DynamicDiag_Ratio_HighLimit = 90U;

const uint16_t K_Motor1_P_STB_DynamicDiag_Ratio_LowLimit = 110U;  
const uint16_t K_Motor1_P_STB_DynamicDiag_Ratio_HighLimit = 120U;
const uint16_t K_Motor1_N_STB_DynamicDiag_Ratio_LowLimit = 110U;
const uint16_t K_Motor1_N_STB_DynamicDiag_Ratio_HighLimit = 120U;

const uint16_t K_Motor1_P_Normal_DynamicDiag_Ratio_LowLimit = 68U;  
const uint16_t K_Motor1_P_Normal_DynamicDiag_Ratio_HighLimit = 78U;
const uint16_t K_Motor1_N_Normal_DynamicDiag_Ratio_LowLimit = 68U;
const uint16_t K_Motor1_N_Normal_DynamicDiag_Ratio_HighLimit = 78U;

const uint16_t K_Motor2_P_STG_DynamicDiag_Ratio_LowLimit = 0U;  
const uint16_t K_Motor2_P_STG_DynamicDiag_Ratio_HighLimit = 2U;
const uint16_t K_Motor2_N_STG_DynamicDiag_Ratio_LowLimit = 0U;
const uint16_t K_Motor2_N_STG_DynamicDiag_Ratio_HighLimit = 2U;

const uint16_t K_Motor2_P_OC_DynamicDiag_Ratio_LowLimit = 0U;  
const uint16_t K_Motor2_P_OC_DynamicDiag_Ratio_HighLimit = 2U;
const uint16_t K_Motor2_N_OC_DynamicDiag_Ratio_LowLimit = 80U;
const uint16_t K_Motor2_N_OC_DynamicDiag_Ratio_HighLimit = 90U;

const uint16_t K_Motor2_P_STB_DynamicDiag_Ratio_LowLimit = 110U;  
const uint16_t K_Motor2_P_STB_DynamicDiag_Ratio_HighLimit = 120U;
const uint16_t K_Motor2_N_STB_DynamicDiag_Ratio_LowLimit = 110U;
const uint16_t K_Motor2_N_STB_DynamicDiag_Ratio_HighLimit = 120U;

const uint16_t K_Motor2_P_Normal_DynamicDiag_Ratio_LowLimit = 68U;  
const uint16_t K_Motor2_P_Normal_DynamicDiag_Ratio_HighLimit = 78U;
const uint16_t K_Motor2_N_Normal_DynamicDiag_Ratio_LowLimit = 68U;
const uint16_t K_Motor2_N_Normal_DynamicDiag_Ratio_HighLimit = 78U;

const uint16_t K_CinchMotor_P_STG_DynamicDiag_Ratio_LowLimit = 0U;  
const uint16_t K_CinchMotor_P_STG_DynamicDiag_Ratio_HighLimit = 2U;
const uint16_t K_CinchMotor_N_STG_DynamicDiag_Ratio_LowLimit = 0U;
const uint16_t K_CinchMotor_N_STG_DynamicDiag_Ratio_HighLimit = 2U;

const uint16_t K_CinchMotor_P_OC_DynamicDiag_Ratio_LowLimit = 0U;  
const uint16_t K_CinchMotor_P_OC_DynamicDiag_Ratio_HighLimit = 2U;
const uint16_t K_CinchMotor_N_OC_DynamicDiag_Ratio_LowLimit = 39U;
const uint16_t K_CinchMotor_N_OC_DynamicDiag_Ratio_HighLimit = 49U;

const uint16_t K_CinchMotor_P_STB_DynamicDiag_Ratio_LowLimit = 110U;  
const uint16_t K_CinchMotor_P_STB_DynamicDiag_Ratio_HighLimit = 120U;
const uint16_t K_CinchMotor_N_STB_DynamicDiag_Ratio_LowLimit = 110U;
const uint16_t K_CinchMotor_N_STB_DynamicDiag_Ratio_HighLimit = 120U;

const uint16_t K_CinchMotor_P_Normal_DynamicDiag_Ratio_LowLimit = 25U;  
const uint16_t K_CinchMotor_P_Normal_DynamicDiag_Ratio_HighLimit = 42U;
const uint16_t K_CinchMotor_N_Normal_DynamicDiag_Ratio_LowLimit = 25U;
const uint16_t K_CinchMotor_N_Normal_DynamicDiag_Ratio_HighLimit = 42U;

const uint16_t K_Motor4_P_STG_DynamicDiag_Ratio_LowLimit = 0U;  
const uint16_t K_Motor4_P_STG_DynamicDiag_Ratio_HighLimit = 2U;
const uint16_t K_Motor4_N_STG_DynamicDiag_Ratio_LowLimit = 0U;
const uint16_t K_Motor4_N_STG_DynamicDiag_Ratio_HighLimit = 2U;

const uint16_t K_Motor4_P_OC_DynamicDiag_Ratio_LowLimit = 0U;  
const uint16_t K_Motor4_P_OC_DynamicDiag_Ratio_HighLimit = 2U;
const uint16_t K_Motor4_N_OC_DynamicDiag_Ratio_LowLimit = 80U;
const uint16_t K_Motor4_N_OC_DynamicDiag_Ratio_HighLimit = 90U;

const uint16_t K_Motor4_P_STB_DynamicDiag_Ratio_LowLimit = 110U;  
const uint16_t K_Motor4_P_STB_DynamicDiag_Ratio_HighLimit = 120U;
const uint16_t K_Motor4_N_STB_DynamicDiag_Ratio_LowLimit = 110U;
const uint16_t K_Motor4_N_STB_DynamicDiag_Ratio_HighLimit = 120U;

const uint16_t K_Motor4_P_Normal_DynamicDiag_Ratio_LowLimit = 68U;  
const uint16_t K_Motor4_P_Normal_DynamicDiag_Ratio_HighLimit = 78U;
const uint16_t K_Motor4_N_Normal_DynamicDiag_Ratio_LowLimit = 68U;
const uint16_t K_Motor4_N_Normal_DynamicDiag_Ratio_HighLimit = 78U;

const uint16_t K_ReleaseMotor_P_STG_DynamicDiag_Ratio_LowLimit = 0U;  
const uint16_t K_ReleaseMotor_P_STG_DynamicDiag_Ratio_HighLimit = 5U;

const uint16_t K_ReleaseMotor_P_OC_DynamicDiag_Ratio_LowLimit = 0U;  
const uint16_t K_ReleaseMotor_P_OC_DynamicDiag_Ratio_HighLimit = 10U;

const uint16_t K_ReleaseMotor_P_STB_DynamicDiag_Ratio_LowLimit = 110U;  
const uint16_t K_ReleaseMotor_P_STB_DynamicDiag_Ratio_HighLimit = 120U;

const uint16_t K_ReleaseMotor_P_Normal_DynamicDiag_Ratio_LowLimit = 48U;  
const uint16_t K_ReleaseMotor_P_Normal_DynamicDiag_Ratio_HighLimit = 54U;

const uint16_t K_Buzzer_P_STG_DynamicDiag_Ratio_LowLimit = 0U;  
const uint16_t K_Buzzer_P_STG_DynamicDiag_Ratio_HighLimit = 5U;

const uint16_t K_Buzzer_P_OC_DynamicDiag_Ratio_LowLimit = 0U;  
const uint16_t K_Buzzer_P_OC_DynamicDiag_Ratio_HighLimit = 50U;

const uint16_t K_Buzzer_P_STB_DynamicDiag_Ratio_LowLimit = 110U;  
const uint16_t K_Buzzer_P_STB_DynamicDiag_Ratio_HighLimit = 120U;

const uint16_t K_Buzzer_P_Normal_DynamicDiag_Ratio_LowLimit = 48U;  
const uint16_t K_Buzzer_P_Normal_DynamicDiag_Ratio_HighLimit = 54U;

const uint16_t K_Clutch_P_STG_DynamicDiag_Ratio_LowLimit = 0U;  
const uint16_t K_Clutch_P_STG_DynamicDiag_Ratio_HighLimit = 5U;

const uint16_t K_Clutch_P_OC_DynamicDiag_Ratio_LowLimit = 0U;  
const uint16_t K_Clutch_P_OC_DynamicDiag_Ratio_HighLimit = 50U;

const uint16_t K_Clutch_P_STB_DynamicDiag_Ratio_LowLimit = 110U;  
const uint16_t K_Clutch_P_STB_DynamicDiag_Ratio_HighLimit = 120U;

const uint16_t K_Clutch_P_Normal_DynamicDiag_Ratio_LowLimit = 48U;  
const uint16_t K_Clutch_P_Normal_DynamicDiag_Ratio_HighLimit = 54U;

const uint16_t K_ModeSwitch_STG_StaticDiag_Value = 10U; 
const uint16_t K_ModeSwitch_OC_StaticDiag_Value = 450U;
const uint16_t K_ModeSwitch_STB_StaticDiag_Value = 495U;
const uint16_t K_ModeSwitch_StaticDiag_Time = 5U; /* 100ms x  */
#endif


#ifdef _CONFIG_Gen4_Board
const uint16_t K_Motor1_Current_STG_DynamicDiag_Value = 3800;  /* 4095 = 5V Logic High */
const uint16_t K_Motor2_Current_STG_DynamicDiag_Value = 3800;  /* 4095 = 5V Logic High */
const uint16_t K_Motor4_Current_STG_DynamicDiag_Value = 3800;  /* 4095 = 5V Logic High */
const uint16_t K_CinchMotor_Current_STG_DynamicDiag_Value = 3800;  /* 4095 = 5V Logic High */
const uint16_t K_ReleaseMotor_Current_STG_DynamicDiag_Value = 3800;  /* 4095 = 5V Logic High */
const uint16_t K_Buzzer_Current_STG_DynamicDiag_Value = 3800;  /* 4095 = 5V Logic High */
const uint16_t K_Clutch_Current_STG_DynamicDiag_Value = 3800;  /* 4095 = 5V Logic High */

const uint16_t K_ReleaseMotor_Current_STB_StaticDiag_Value = 3800;  /* 4095 = 5V Logic High */
const uint16_t K_Buzzer_Current_STB_StaticDiag_Value = 3800;  /* 4095 = 5V Logic High */
const uint16_t K_Clutch_Current_STB_StaticDiag_Value = 3800;  /* 4095 = 5V Logic High */

#ifdef _CONFIG_IntevaSideLatch
const uint16_t K_Motor2_Current_OC_DynamicDiag_Value = 50;  /* 100 = 1A */
const uint16_t K_CinchMotor_Current_OC_DynamicDiag_Value = 30;//2;  /* 100 = 1A */
#else
const uint16_t K_Motor2_Current_OC_DynamicDiag_Value = 2;  /* 100 = 1A */
const uint16_t K_CinchMotor_Current_OC_DynamicDiag_Value = 2;  /* 100 = 1A */
#endif
const uint16_t K_Motor1_Current_OC_DynamicDiag_Value = 2;  /* 100 = 1A */
const uint16_t K_Motor4_Current_OC_DynamicDiag_Value = 2;  /* 100 = 1A */
const uint16_t K_ReleaseMotor_Current_OC_DynamicDiag_Value = 2;  /* 100 = 1A */
const uint16_t K_Buzzer_Current_OC_DynamicDiag_Value = 2;  /* 100 = 1A */
const uint16_t K_Clutch_Current_OC_DynamicDiag_Value = 2;  /* 100 = 1A */

const uint16_t K_Motor1_Current_STB_DynamicDiag_Value = 3800;  /* 4095 = 5V Logic High */
const uint16_t K_Motor2_Current_STB_DynamicDiag_Value = 3800;  /* 4095 = 5V Logic High */
const uint16_t K_Motor4_Current_STB_DynamicDiag_Value = 3800;  /* 4095 = 5V Logic High */
const uint16_t K_CinchMotor_Current_STB_DynamicDiag_Value = 3800;  /* 4095 = 5V Logic High */
const uint16_t K_ReleaseMotor_Current_STB_DynamicDiag_Value = 3800;  /* 4095 = 5V Logic High */
const uint16_t K_Buzzer_Current_STB_DynamicDiag_Value = 3800;  /* 4095 = 5V Logic High */
const uint16_t K_Clutch_Current_STB_DynamicDiag_Value = 3800;  /* 4095 = 5V Logic High */

const uint16_t K_Motor1_Current_STB_DynamicDiag_Value_HighLimit = 1000;  /* 4095 = 5V Logic High */
const uint16_t K_Motor2_Current_STB_DynamicDiag_Value_HighLimit = 1000;  /* 4095 = 5V Logic High */
const uint16_t K_Motor4_Current_STB_DynamicDiag_Value_HighLimit = 1000;  /* 4095 = 5V Logic High */
const uint16_t K_CinchMotor_Current_STB_DynamicDiag_Value_HighLimit = 1000;  /* 4095 = 5V Logic High */
const uint16_t K_ReleaseMotor_Current_STB_DynamicDiag_Value_HighLimit = 1000;  /* 4095 = 5V Logic High */
const uint16_t K_Buzzer_Current_STB_DynamicDiag_Value_HighLimit = 1000;  /* 4095 = 5V Logic High */
const uint16_t K_Clutch_Current_STB_DynamicDiag_Value_HighLimit = 1000;  /* 4095 = 5V Logic High */

const uint16_t K_Motor1_Current_STB_DynamicDiag_Value_LowLimit = 20;  /* 4095 = 5V Logic High */
const uint16_t K_Motor2_Current_STB_DynamicDiag_Value_LowLimit = 20;  /* 4095 = 5V Logic High */
const uint16_t K_Motor4_Current_STB_DynamicDiag_Value_LowLimit = 20;  /* 4095 = 5V Logic High */
const uint16_t K_CinchMotor_Current_STB_DynamicDiag_Value_LowLimit = 20;  /* 4095 = 5V Logic High */
const uint16_t K_ReleaseMotor_Current_STB_DynamicDiag_Value_LowLimit = 20;  /* 4095 = 5V Logic High */
const uint16_t K_Buzzer_Current_STB_DynamicDiag_Value_LowLimit = 20;  /* 4095 = 5V Logic High */
const uint16_t K_Clutch_Current_STB_DynamicDiag_Value_LowLimit = 20;  /* 4095 = 5V Logic High */

const uint16_t K_Motor1_Current_SCL_DynamicDiag_Value = 3800;  /* 4095 = 5V Logic High */
const uint16_t K_Motor2_Current_SCL_DynamicDiag_Value = 3800;  /* 4095 = 5V Logic High */
const uint16_t K_Motor4_Current_SCL_DynamicDiag_Value = 3800;  /* 4095 = 5V Logic High */
const uint16_t K_CinchMotor_Current_SCL_DynamicDiag_Value = 3800;  /* 4095 = 5V Logic High */
const uint16_t K_ReleaseMotor_Current_SCL_DynamicDiag_Value = 3800;  /* 4095 = 5V Logic High */
const uint16_t K_Buzzer_Current_SCL_DynamicDiag_Value = 3800;  /* 4095 = 5V Logic High */
const uint16_t K_Clutch_Current_SCL_DynamicDiag_Value = 3800;  /* 4095 = 5V Logic High */

const uint16_t K_Motor1_P_STG_DynamicDiag_Ratio_LowLimit = 0U;  
const uint16_t K_Motor1_P_STG_DynamicDiag_Ratio_HighLimit = 2U;
const uint16_t K_Motor1_N_STG_DynamicDiag_Ratio_LowLimit = 0U;
const uint16_t K_Motor1_N_STG_DynamicDiag_Ratio_HighLimit = 2U;

const uint16_t K_Motor1_P_OC_DynamicDiag_Ratio_LowLimit = 0U;  
const uint16_t K_Motor1_P_OC_DynamicDiag_Ratio_HighLimit = 2U;
const uint16_t K_Motor1_N_OC_DynamicDiag_Ratio_LowLimit = 80U;
const uint16_t K_Motor1_N_OC_DynamicDiag_Ratio_HighLimit = 90U;

const uint16_t K_Motor1_P_STB_DynamicDiag_Ratio_LowLimit = 110U;  
const uint16_t K_Motor1_P_STB_DynamicDiag_Ratio_HighLimit = 120U;
const uint16_t K_Motor1_N_STB_DynamicDiag_Ratio_LowLimit = 110U;
const uint16_t K_Motor1_N_STB_DynamicDiag_Ratio_HighLimit = 120U;

const uint16_t K_Motor1_P_Normal_DynamicDiag_Ratio_LowLimit = 68U;  
const uint16_t K_Motor1_P_Normal_DynamicDiag_Ratio_HighLimit = 78U;
const uint16_t K_Motor1_N_Normal_DynamicDiag_Ratio_LowLimit = 68U;
const uint16_t K_Motor1_N_Normal_DynamicDiag_Ratio_HighLimit = 78U;

const uint16_t K_Motor2_P_STG_DynamicDiag_Ratio_LowLimit = 0U;  
const uint16_t K_Motor2_P_STG_DynamicDiag_Ratio_HighLimit = 2U;
const uint16_t K_Motor2_N_STG_DynamicDiag_Ratio_LowLimit = 0U;
const uint16_t K_Motor2_N_STG_DynamicDiag_Ratio_HighLimit = 2U;

const uint16_t K_Motor2_P_OC_DynamicDiag_Ratio_LowLimit = 0U;  
const uint16_t K_Motor2_P_OC_DynamicDiag_Ratio_HighLimit = 2U;
const uint16_t K_Motor2_N_OC_DynamicDiag_Ratio_LowLimit = 80U;
const uint16_t K_Motor2_N_OC_DynamicDiag_Ratio_HighLimit = 90U;

const uint16_t K_Motor2_P_STB_DynamicDiag_Ratio_LowLimit = 110U;  
const uint16_t K_Motor2_P_STB_DynamicDiag_Ratio_HighLimit = 120U;
const uint16_t K_Motor2_N_STB_DynamicDiag_Ratio_LowLimit = 110U;
const uint16_t K_Motor2_N_STB_DynamicDiag_Ratio_HighLimit = 120U;

const uint16_t K_Motor2_P_Normal_DynamicDiag_Ratio_LowLimit = 68U;  
const uint16_t K_Motor2_P_Normal_DynamicDiag_Ratio_HighLimit = 78U;
const uint16_t K_Motor2_N_Normal_DynamicDiag_Ratio_LowLimit = 68U;
const uint16_t K_Motor2_N_Normal_DynamicDiag_Ratio_HighLimit = 78U;

const uint16_t K_CinchMotor_P_STG_DynamicDiag_Ratio_LowLimit = 0U;  
const uint16_t K_CinchMotor_P_STG_DynamicDiag_Ratio_HighLimit = 2U;
const uint16_t K_CinchMotor_N_STG_DynamicDiag_Ratio_LowLimit = 0U;
const uint16_t K_CinchMotor_N_STG_DynamicDiag_Ratio_HighLimit = 2U;

const uint16_t K_CinchMotor_P_OC_DynamicDiag_Ratio_LowLimit = 0U;  
const uint16_t K_CinchMotor_P_OC_DynamicDiag_Ratio_HighLimit = 2U;
const uint16_t K_CinchMotor_N_OC_DynamicDiag_Ratio_LowLimit = 39U;
const uint16_t K_CinchMotor_N_OC_DynamicDiag_Ratio_HighLimit = 49U;

const uint16_t K_CinchMotor_P_STB_DynamicDiag_Ratio_LowLimit = 110U;  
const uint16_t K_CinchMotor_P_STB_DynamicDiag_Ratio_HighLimit = 120U;
const uint16_t K_CinchMotor_N_STB_DynamicDiag_Ratio_LowLimit = 110U;
const uint16_t K_CinchMotor_N_STB_DynamicDiag_Ratio_HighLimit = 120U;

const uint16_t K_CinchMotor_P_Normal_DynamicDiag_Ratio_LowLimit = 25U;  
const uint16_t K_CinchMotor_P_Normal_DynamicDiag_Ratio_HighLimit = 42U;
const uint16_t K_CinchMotor_N_Normal_DynamicDiag_Ratio_LowLimit = 25U;
const uint16_t K_CinchMotor_N_Normal_DynamicDiag_Ratio_HighLimit = 42U;

const uint16_t K_Motor4_P_STG_DynamicDiag_Ratio_LowLimit = 0U;  
const uint16_t K_Motor4_P_STG_DynamicDiag_Ratio_HighLimit = 2U;
const uint16_t K_Motor4_N_STG_DynamicDiag_Ratio_LowLimit = 0U;
const uint16_t K_Motor4_N_STG_DynamicDiag_Ratio_HighLimit = 2U;

const uint16_t K_Motor4_P_OC_DynamicDiag_Ratio_LowLimit = 0U;  
const uint16_t K_Motor4_P_OC_DynamicDiag_Ratio_HighLimit = 2U;
const uint16_t K_Motor4_N_OC_DynamicDiag_Ratio_LowLimit = 80U;
const uint16_t K_Motor4_N_OC_DynamicDiag_Ratio_HighLimit = 90U;

const uint16_t K_Motor4_P_STB_DynamicDiag_Ratio_LowLimit = 110U;  
const uint16_t K_Motor4_P_STB_DynamicDiag_Ratio_HighLimit = 120U;
const uint16_t K_Motor4_N_STB_DynamicDiag_Ratio_LowLimit = 110U;
const uint16_t K_Motor4_N_STB_DynamicDiag_Ratio_HighLimit = 120U;

const uint16_t K_Motor4_P_Normal_DynamicDiag_Ratio_LowLimit = 68U;  
const uint16_t K_Motor4_P_Normal_DynamicDiag_Ratio_HighLimit = 78U;
const uint16_t K_Motor4_N_Normal_DynamicDiag_Ratio_LowLimit = 68U;
const uint16_t K_Motor4_N_Normal_DynamicDiag_Ratio_HighLimit = 78U;

const uint16_t K_ReleaseMotor_P_STG_DynamicDiag_Ratio_LowLimit = 0U;  
const uint16_t K_ReleaseMotor_P_STG_DynamicDiag_Ratio_HighLimit = 5U;

const uint16_t K_ReleaseMotor_P_OC_DynamicDiag_Ratio_LowLimit = 0U;  
const uint16_t K_ReleaseMotor_P_OC_DynamicDiag_Ratio_HighLimit = 10U;

const uint16_t K_ReleaseMotor_P_STB_DynamicDiag_Ratio_LowLimit = 110U;  
const uint16_t K_ReleaseMotor_P_STB_DynamicDiag_Ratio_HighLimit = 120U;

const uint16_t K_ReleaseMotor_P_Normal_DynamicDiag_Ratio_LowLimit = 48U;  
const uint16_t K_ReleaseMotor_P_Normal_DynamicDiag_Ratio_HighLimit = 54U;

const uint16_t K_Buzzer_P_STG_DynamicDiag_Ratio_LowLimit = 0U;  
const uint16_t K_Buzzer_P_STG_DynamicDiag_Ratio_HighLimit = 5U;

const uint16_t K_Buzzer_P_OC_DynamicDiag_Ratio_LowLimit = 0U;  
const uint16_t K_Buzzer_P_OC_DynamicDiag_Ratio_HighLimit = 50U;

const uint16_t K_Buzzer_P_STB_DynamicDiag_Ratio_LowLimit = 110U;  
const uint16_t K_Buzzer_P_STB_DynamicDiag_Ratio_HighLimit = 120U;

const uint16_t K_Buzzer_P_Normal_DynamicDiag_Ratio_LowLimit = 48U;  
const uint16_t K_Buzzer_P_Normal_DynamicDiag_Ratio_HighLimit = 54U;

const uint16_t K_Clutch_P_STG_DynamicDiag_Ratio_LowLimit = 0U;  
const uint16_t K_Clutch_P_STG_DynamicDiag_Ratio_HighLimit = 5U;

const uint16_t K_Clutch_P_OC_DynamicDiag_Ratio_LowLimit = 0U;  
const uint16_t K_Clutch_P_OC_DynamicDiag_Ratio_HighLimit = 50U;

const uint16_t K_Clutch_P_STB_DynamicDiag_Ratio_LowLimit = 110U;  
const uint16_t K_Clutch_P_STB_DynamicDiag_Ratio_HighLimit = 120U;

const uint16_t K_Clutch_P_Normal_DynamicDiag_Ratio_LowLimit = 48U;  
const uint16_t K_Clutch_P_Normal_DynamicDiag_Ratio_HighLimit = 54U;

const uint16_t K_ModeSwitch_STG_StaticDiag_Value = 10U; 
const uint16_t K_ModeSwitch_OC_StaticDiag_Value = 450U;
const uint16_t K_ModeSwitch_STB_StaticDiag_Value = 495U;
const uint16_t K_ModeSwitch_StaticDiag_Time = 5U; /* 100ms x  */
#endif

#ifdef _CHERY_COM
const uint16_t K_BatteryVoltage_StaticDiag_VolAbove = 1600U; //K_16V_ATD;
const uint16_t K_BatteryVoltage_StaticDiag_VolBelow = 900U; //K_09V_ATD;
const uint16_t K_BatteryVoltage_StaticDiag_Recovery_Low = 950U; //K_9V5_ATD;
const uint16_t K_BatteryVoltage_StaticDiag_Recovery_High = 1550U; //K_15V5_ATD;

const uint16_t K_OpenCloseSwitch_STG_StaticDiag_Time = 300U;  /* 100ms x  */
const uint16_t K_OutsideHandleSwitch_STG_StaticDiag_Time = 300U;  /* 100ms x  */
const uint16_t K_ShutFaceSwitch_STG_StaticDiag_Time = 300U;  /* 100ms x  */  
const uint16_t K_ShutFaceLockSwitch_STG_StaticDiag_Time = 300U;  /* 100ms x  */
const uint16_t K_OpenCloseSwitch_Normal_StaticDiag_Time = 10U;  /* 100ms x  */
const uint16_t K_OutsideHandleSwitch_Normal_StaticDiag_Time = 10U;  /* 100ms x  */
const uint16_t K_ShutFaceSwitch_Normal_StaticDiag_Time = 10U;  /* 100ms x  */  
const uint16_t K_ShutFaceLockSwitch_Normal_StaticDiag_Time = 10U;  /* 100ms x  */

const uint16_t K_PowerSupply_Error_StaticDiag_Time = 50U;  /* 100ms x  */
const uint16_t K_PowerSupply_Normal_StaticDiag_Time = 10U;  /* 100ms x  */
const uint16_t K_DigitalSupply_Error_StaticDiag_Time = 30U;  /* 100ms x  */
const uint16_t K_DigitalSupply_Normal_StaticDiag_Time = 10U;  /* 100ms x  */

const uint16_t K_HallPower1_Normal_StaticDiag_Time = 5U;  /* 100ms x  */
const uint16_t K_HallPower2_Normal_StaticDiag_Time = 5U;  /* 100ms x  */
const uint16_t K_HallPower1_Failure_StaticDiag_Time = 50U;  /* 100ms x  */
const uint16_t K_HallPower2_Failure_StaticDiag_Time = 50U;  /* 100ms x  */
#endif

#ifdef _VOYAH_COM
const uint16_t K_BatteryVoltage_StaticDiag_VolAbove = 1600U; //K_16V_ATD;
const uint16_t K_BatteryVoltage_StaticDiag_VolBelow = 900U; //K_09V_ATD;
const uint16_t K_BatteryVoltage_StaticDiag_Recovery_Low = 950U; //K_9V5_ATD;
const uint16_t K_BatteryVoltage_StaticDiag_Recovery_High = 1550U; //K_15V5_ATD;

const uint16_t K_OpenCloseSwitch_STG_StaticDiag_Time = 300U;  /* 100ms x  */
const uint16_t K_OutsideHandleSwitch_STG_StaticDiag_Time = 300U;  /* 100ms x  */
const uint16_t K_ShutFaceSwitch_STG_StaticDiag_Time = 300U;  /* 100ms x  */  
const uint16_t K_ShutFaceLockSwitch_STG_StaticDiag_Time = 300U;  /* 100ms x  */
const uint16_t K_OpenCloseSwitch_Normal_StaticDiag_Time = 10U;  /* 100ms x  */
const uint16_t K_OutsideHandleSwitch_Normal_StaticDiag_Time = 10U;  /* 100ms x  */
const uint16_t K_ShutFaceSwitch_Normal_StaticDiag_Time = 10U;  /* 100ms x  */  
const uint16_t K_ShutFaceLockSwitch_Normal_StaticDiag_Time = 10U;  /* 100ms x  */

const uint16_t K_PowerSupply_Error_StaticDiag_Time = 50U;  /* 100ms x  */
const uint16_t K_PowerSupply_Normal_StaticDiag_Time = 10U;  /* 100ms x  */
const uint16_t K_DigitalSupply_Error_StaticDiag_Time = 30U;  /* 100ms x  */
const uint16_t K_DigitalSupply_Normal_StaticDiag_Time = 10U;  /* 100ms x  */

const uint16_t K_HallPower1_Normal_StaticDiag_Time = 5U;  /* 100ms x  */
const uint16_t K_HallPower2_Normal_StaticDiag_Time = 5U;  /* 100ms x  */
const uint16_t K_HallPower1_Failure_StaticDiag_Time = 50U;  /* 100ms x  */
const uint16_t K_HallPower2_Failure_StaticDiag_Time = 50U;  /* 100ms x  */
#endif


#ifdef _AUDI_COM
const uint16_t K_BatteryVoltage_StaticDiag_VolAbove = 1600U; //K_16V_ATD;
const uint16_t K_BatteryVoltage_StaticDiag_VolBelow = 900U; //K_09V_ATD;
const uint16_t K_BatteryVoltage_StaticDiag_Recovery_Low = 950U; //K_9V5_ATD;
const uint16_t K_BatteryVoltage_StaticDiag_Recovery_High = 1550U; //K_15V5_ATD;

const uint16_t K_OpenCloseSwitch_STG_StaticDiag_Time = 300U;  /* 100ms x  */
const uint16_t K_OutsideHandleSwitch_STG_StaticDiag_Time = 300U;  /* 100ms x  */
const uint16_t K_ShutFaceSwitch_STG_StaticDiag_Time = 300U;  /* 100ms x  */  
const uint16_t K_ShutFaceLockSwitch_STG_StaticDiag_Time = 300U;  /* 100ms x  */
const uint16_t K_OpenCloseSwitch_Normal_StaticDiag_Time = 10U;  /* 100ms x  */
const uint16_t K_OutsideHandleSwitch_Normal_StaticDiag_Time = 10U;  /* 100ms x  */
const uint16_t K_ShutFaceSwitch_Normal_StaticDiag_Time = 10U;  /* 100ms x  */  
const uint16_t K_ShutFaceLockSwitch_Normal_StaticDiag_Time = 10U;  /* 100ms x  */

const uint16_t K_PowerSupply_Error_StaticDiag_Time = 50U;  /* 100ms x  */
const uint16_t K_PowerSupply_Normal_StaticDiag_Time = 10U;  /* 100ms x  */
const uint16_t K_DigitalSupply_Error_StaticDiag_Time = 30U;  /* 100ms x  */
const uint16_t K_DigitalSupply_Normal_StaticDiag_Time = 10U;  /* 100ms x  */

const uint16_t K_HallPower1_Normal_StaticDiag_Time = 5U;  /* 100ms x  */
const uint16_t K_HallPower2_Normal_StaticDiag_Time = 5U;  /* 100ms x  */
const uint16_t K_HallPower1_Failure_StaticDiag_Time = 50U;  /* 100ms x  */
const uint16_t K_HallPower2_Failure_StaticDiag_Time = 50U;  /* 100ms x  */
#endif


#ifdef _SGMW_COM
const uint16_t K_BatteryVoltage_StaticDiag_VolAbove = 1600U; //K_16V_ATD;
const uint16_t K_BatteryVoltage_StaticDiag_VolBelow = 900U; //K_09V_ATD;
const uint16_t K_BatteryVoltage_StaticDiag_Recovery_Low = 950U; //K_9V5_ATD;
const uint16_t K_BatteryVoltage_StaticDiag_Recovery_High = 1550U; //K_15V5_ATD;

const uint16_t K_OpenCloseSwitch_STG_StaticDiag_Time = 200U;  /* 100ms x  */
const uint16_t K_OutsideHandleSwitch_STG_StaticDiag_Time = 200U;  /* 100ms x  */
const uint16_t K_ShutFaceSwitch_STG_StaticDiag_Time = 200U;  /* 100ms x  */  
const uint16_t K_ShutFaceLockSwitch_STG_StaticDiag_Time = 200U;  /* 100ms x  */
const uint16_t K_OpenCloseSwitch_Normal_StaticDiag_Time = 10U;  /* 100ms x  */
const uint16_t K_OutsideHandleSwitch_Normal_StaticDiag_Time = 10U;  /* 100ms x  */
const uint16_t K_ShutFaceSwitch_Normal_StaticDiag_Time = 10U;  /* 100ms x  */  
const uint16_t K_ShutFaceLockSwitch_Normal_StaticDiag_Time = 10U;  /* 100ms x  */

const uint16_t K_PowerSupply_Error_StaticDiag_Time = 30U;  /* 100ms x  */
const uint16_t K_PowerSupply_Normal_StaticDiag_Time = 10U;  /* 100ms x  */
const uint16_t K_DigitalSupply_Error_StaticDiag_Time = 30U;  /* 100ms x  */
const uint16_t K_DigitalSupply_Normal_StaticDiag_Time = 10U;  /* 100ms x  */

const uint16_t K_HallPower1_Normal_StaticDiag_Time = 5U;  /* 100ms x  */
const uint16_t K_HallPower2_Normal_StaticDiag_Time = 5U;  /* 100ms x  */
const uint16_t K_HallPower1_Failure_StaticDiag_Time = 10U;  /* 100ms x  */
const uint16_t K_HallPower2_Failure_StaticDiag_Time = 10U;  /* 100ms x  */
#endif
#ifdef _SGM_COM
const uint16_t K_BatteryVoltage_StaticDiag_VolAbove = 1600U; //K_16V_ATD;
const uint16_t K_BatteryVoltage_StaticDiag_VolBelow = 900U; //K_09V_ATD;
const uint16_t K_BatteryVoltage_StaticDiag_Recovery_Low = 950U; //K_9V5_ATD;
const uint16_t K_BatteryVoltage_StaticDiag_Recovery_High = 1550U; //K_15V5_ATD;

const uint16_t K_OpenCloseSwitch_STG_StaticDiag_Time = 200U;  /* 100ms x  */
const uint16_t K_OutsideHandleSwitch_STG_StaticDiag_Time = 200U;  /* 100ms x  */
const uint16_t K_ShutFaceSwitch_STG_StaticDiag_Time = 200U;  /* 100ms x  */  
const uint16_t K_ShutFaceLockSwitch_STG_StaticDiag_Time = 200U;  /* 100ms x  */
const uint16_t K_OpenCloseSwitch_Normal_StaticDiag_Time = 10U;  /* 100ms x  */
const uint16_t K_OutsideHandleSwitch_Normal_StaticDiag_Time = 10U;  /* 100ms x  */
const uint16_t K_ShutFaceSwitch_Normal_StaticDiag_Time = 10U;  /* 100ms x  */  
const uint16_t K_ShutFaceLockSwitch_Normal_StaticDiag_Time = 10U;  /* 100ms x  */

const uint16_t K_PowerSupply_Error_StaticDiag_Time = 30U;  /* 100ms x  */
const uint16_t K_PowerSupply_Normal_StaticDiag_Time = 10U;  /* 100ms x  */
const uint16_t K_DigitalSupply_Error_StaticDiag_Time = 30U;  /* 100ms x  */
const uint16_t K_DigitalSupply_Normal_StaticDiag_Time = 10U;  /* 100ms x  */

const uint16_t K_HallPower1_Normal_StaticDiag_Time = 5U;  /* 100ms x  */
const uint16_t K_HallPower2_Normal_StaticDiag_Time = 5U;  /* 100ms x  */
const uint16_t K_HallPower1_Failure_StaticDiag_Time = 10U;  /* 100ms x  */
const uint16_t K_HallPower2_Failure_StaticDiag_Time = 10U;  /* 100ms x  */
#endif
#ifdef _CTCS_COM
const uint16_t K_BatteryVoltage_StaticDiag_VolAbove = 1600U; //K_16V_ATD;
const uint16_t K_BatteryVoltage_StaticDiag_VolBelow = 900U; //K_09V_ATD;
const uint16_t K_BatteryVoltage_StaticDiag_Recovery_Low = 950U; //K_9V5_ATD;
const uint16_t K_BatteryVoltage_StaticDiag_Recovery_High = 1550U; //K_15V5_ATD;

const uint16_t K_OpenCloseSwitch_STG_StaticDiag_Time = 200U;  /* 100ms x  */
const uint16_t K_OutsideHandleSwitch_STG_StaticDiag_Time = 200U;  /* 100ms x  */
const uint16_t K_ShutFaceSwitch_STG_StaticDiag_Time = 200U;  /* 100ms x  */  
const uint16_t K_ShutFaceLockSwitch_STG_StaticDiag_Time = 200U;  /* 100ms x  */
const uint16_t K_OpenCloseSwitch_Normal_StaticDiag_Time = 10U;  /* 100ms x  */
const uint16_t K_OutsideHandleSwitch_Normal_StaticDiag_Time = 10U;  /* 100ms x  */
const uint16_t K_ShutFaceSwitch_Normal_StaticDiag_Time = 10U;  /* 100ms x  */  
const uint16_t K_ShutFaceLockSwitch_Normal_StaticDiag_Time = 10U;  /* 100ms x  */

const uint16_t K_PowerSupply_Error_StaticDiag_Time = 30U;  /* 100ms x  */
const uint16_t K_PowerSupply_Normal_StaticDiag_Time = 10U;  /* 100ms x  */
const uint16_t K_DigitalSupply_Error_StaticDiag_Time = 30U;  /* 100ms x  */
const uint16_t K_DigitalSupply_Normal_StaticDiag_Time = 10U;  /* 100ms x  */

const uint16_t K_HallPower1_Normal_StaticDiag_Time = 5U;  /* 100ms x  */
const uint16_t K_HallPower2_Normal_StaticDiag_Time = 5U;  /* 100ms x  */
const uint16_t K_HallPower1_Failure_StaticDiag_Time = 10U;  /* 100ms x  */
const uint16_t K_HallPower2_Failure_StaticDiag_Time = 10U;  /* 100ms x  */
#endif
#ifdef _DEARCC_COM
const uint16_t K_BatteryVoltage_StaticDiag_VolAbove = 1600U; //K_16V_ATD;
const uint16_t K_BatteryVoltage_StaticDiag_VolBelow = 900U; //K_09V_ATD;
const uint16_t K_BatteryVoltage_StaticDiag_Recovery_Low = 950U; //K_9V5_ATD;
const uint16_t K_BatteryVoltage_StaticDiag_Recovery_High = 1550U; //K_15V5_ATD;

const uint16_t K_OpenCloseSwitch_STG_StaticDiag_Time = 200U;  /* 100ms x  */
const uint16_t K_OutsideHandleSwitch_STG_StaticDiag_Time = 200U;  /* 100ms x  */
const uint16_t K_ShutFaceSwitch_STG_StaticDiag_Time = 200U;  /* 100ms x  */  
const uint16_t K_ShutFaceLockSwitch_STG_StaticDiag_Time = 200U;  /* 100ms x  */
const uint16_t K_OpenCloseSwitch_Normal_StaticDiag_Time = 10U;  /* 100ms x  */
const uint16_t K_OutsideHandleSwitch_Normal_StaticDiag_Time = 10U;  /* 100ms x  */
const uint16_t K_ShutFaceSwitch_Normal_StaticDiag_Time = 10U;  /* 100ms x  */  
const uint16_t K_ShutFaceLockSwitch_Normal_StaticDiag_Time = 10U;  /* 100ms x  */

const uint16_t K_PowerSupply_Error_StaticDiag_Time = 30U;  /* 100ms x  */
const uint16_t K_PowerSupply_Normal_StaticDiag_Time = 10U;  /* 100ms x  */
const uint16_t K_DigitalSupply_Error_StaticDiag_Time = 30U;  /* 100ms x  */
const uint16_t K_DigitalSupply_Normal_StaticDiag_Time = 10U;  /* 100ms x  */

const uint16_t K_HallPower1_Normal_StaticDiag_Time = 5U;  /* 100ms x  */
const uint16_t K_HallPower2_Normal_StaticDiag_Time = 5U;  /* 100ms x  */
const uint16_t K_HallPower1_Failure_StaticDiag_Time = 10U;  /* 100ms x  */
const uint16_t K_HallPower2_Failure_StaticDiag_Time = 10U;  /* 100ms x  */
#endif
#ifdef _XIAOPENG_COM
const uint16_t K_BatteryVoltage_StaticDiag_VolAbove = 1600U; //K_16V_ATD;
const uint16_t K_BatteryVoltage_StaticDiag_VolBelow = 900U; //K_09V_ATD;
const uint16_t K_BatteryVoltage_StaticDiag_Recovery_Low = 950U; //K_9V5_ATD;
const uint16_t K_BatteryVoltage_StaticDiag_Recovery_High = 1550U; //K_15V5_ATD;

const uint16_t K_OpenCloseSwitch_STG_StaticDiag_Time = 200U;  /* 100ms x  */
const uint16_t K_OutsideHandleSwitch_STG_StaticDiag_Time = 200U;  /* 100ms x  */
const uint16_t K_ShutFaceSwitch_STG_StaticDiag_Time = 200U;  /* 100ms x  */  
const uint16_t K_ShutFaceLockSwitch_STG_StaticDiag_Time = 200U;  /* 100ms x  */
const uint16_t K_OpenCloseSwitch_Normal_StaticDiag_Time = 10U;  /* 100ms x  */
const uint16_t K_OutsideHandleSwitch_Normal_StaticDiag_Time = 10U;  /* 100ms x  */
const uint16_t K_ShutFaceSwitch_Normal_StaticDiag_Time = 10U;  /* 100ms x  */  
const uint16_t K_ShutFaceLockSwitch_Normal_StaticDiag_Time = 10U;  /* 100ms x  */

const uint16_t K_PowerSupply_Error_StaticDiag_Time = 30U;  /* 100ms x  */
const uint16_t K_PowerSupply_Normal_StaticDiag_Time = 10U;  /* 100ms x  */
const uint16_t K_DigitalSupply_Error_StaticDiag_Time = 30U;  /* 100ms x  */
const uint16_t K_DigitalSupply_Normal_StaticDiag_Time = 10U;  /* 100ms x  */

const uint16_t K_HallPower1_Normal_StaticDiag_Time = 5U;  /* 100ms x  */
const uint16_t K_HallPower2_Normal_StaticDiag_Time = 5U;  /* 100ms x  */
const uint16_t K_HallPower1_Failure_StaticDiag_Time = 10U;  /* 100ms x  */
const uint16_t K_HallPower2_Failure_StaticDiag_Time = 10U;  /* 100ms x  */
#endif
#ifdef _MAXUS_COM
const uint16_t K_BatteryVoltage_StaticDiag_VolAbove = 1600U; //K_16V_ATD;
const uint16_t K_BatteryVoltage_StaticDiag_VolBelow = 900U; //K_09V_ATD;
const uint16_t K_BatteryVoltage_StaticDiag_Recovery_Low = 950U; //K_9V5_ATD;
const uint16_t K_BatteryVoltage_StaticDiag_Recovery_High = 1550U; //K_15V5_ATD;

const uint16_t K_OpenCloseSwitch_STG_StaticDiag_Time = 200U;  /* 100ms x  */
const uint16_t K_OutsideHandleSwitch_STG_StaticDiag_Time = 200U;  /* 100ms x  */
const uint16_t K_ShutFaceSwitch_STG_StaticDiag_Time = 200U;  /* 100ms x  */  
const uint16_t K_ShutFaceLockSwitch_STG_StaticDiag_Time = 200U;  /* 100ms x  */
const uint16_t K_OpenCloseSwitch_Normal_StaticDiag_Time = 10U;  /* 100ms x  */
const uint16_t K_OutsideHandleSwitch_Normal_StaticDiag_Time = 10U;  /* 100ms x  */
const uint16_t K_ShutFaceSwitch_Normal_StaticDiag_Time = 10U;  /* 100ms x  */  
const uint16_t K_ShutFaceLockSwitch_Normal_StaticDiag_Time = 10U;  /* 100ms x  */

const uint16_t K_PowerSupply_Error_StaticDiag_Time = 30U;  /* 100ms x  */
const uint16_t K_PowerSupply_Normal_StaticDiag_Time = 10U;  /* 100ms x  */
const uint16_t K_DigitalSupply_Error_StaticDiag_Time = 30U;  /* 100ms x  */
const uint16_t K_DigitalSupply_Normal_StaticDiag_Time = 10U;  /* 100ms x  */

const uint16_t K_HallPower1_Normal_StaticDiag_Time = 5U;  /* 100ms x  */
const uint16_t K_HallPower2_Normal_StaticDiag_Time = 5U;  /* 100ms x  */
const uint16_t K_HallPower1_Failure_StaticDiag_Time = 10U;  /* 100ms x  */
const uint16_t K_HallPower2_Failure_StaticDiag_Time = 10U;  /* 100ms x  */
#endif
#ifdef _DFMC_COM
const uint16_t K_BatteryVoltage_StaticDiag_VolAbove = 1600U; //K_16V_ATD;
const uint16_t K_BatteryVoltage_StaticDiag_VolBelow = 900U; //K_09V_ATD;
const uint16_t K_BatteryVoltage_StaticDiag_Recovery_Low = 1000U; //K_9V5_ATD;
const uint16_t K_BatteryVoltage_StaticDiag_Recovery_High = 1500U; //K_15V5_ATD;

const uint16_t K_OpenCloseSwitch_STG_StaticDiag_Time = 300U;  /* 100ms x  */
const uint16_t K_OutsideHandleSwitch_STG_StaticDiag_Time = 300U;  /* 100ms x  */
const uint16_t K_ShutFaceSwitch_STG_StaticDiag_Time = 300U;  /* 100ms x  */  
const uint16_t K_ShutFaceLockSwitch_STG_StaticDiag_Time = 300U;  /* 100ms x  */
const uint16_t K_OpenCloseSwitch_Normal_StaticDiag_Time = 10U;  /* 100ms x  */
const uint16_t K_OutsideHandleSwitch_Normal_StaticDiag_Time = 10U;  /* 100ms x  */
const uint16_t K_ShutFaceSwitch_Normal_StaticDiag_Time = 10U;  /* 100ms x  */  
const uint16_t K_ShutFaceLockSwitch_Normal_StaticDiag_Time = 10U;  /* 100ms x  */

const uint16_t K_PowerSupply_Error_StaticDiag_Time = 30U;  /* 100ms x  */
const uint16_t K_PowerSupply_Normal_StaticDiag_Time = 10U;  /* 100ms x  */
const uint16_t K_DigitalSupply_Error_StaticDiag_Time = 30U;  /* 100ms x  */
const uint16_t K_DigitalSupply_Normal_StaticDiag_Time = 10U;  /* 100ms x  */

const uint16_t K_HallPower1_Normal_StaticDiag_Time = 5U;  /* 100ms x  */
const uint16_t K_HallPower2_Normal_StaticDiag_Time = 5U;  /* 100ms x  */
const uint16_t K_HallPower1_Failure_StaticDiag_Time = 10U;  /* 100ms x  */
const uint16_t K_HallPower2_Failure_StaticDiag_Time = 10U;  /* 100ms x  */
#endif
#ifdef _BAIC_COM
const uint16_t K_BatteryVoltage_StaticDiag_VolAbove = 1650U; //K_16V5_ATD;
const uint16_t K_BatteryVoltage_StaticDiag_VolBelow = 850U; //K_8V5_ATD;
const uint16_t K_BatteryVoltage_StaticDiag_Recovery_Low = 900U; //K_9V_ATD;
const uint16_t K_BatteryVoltage_StaticDiag_Recovery_High = 1600U; //K_16V_ATD;

const uint16_t K_OpenCloseSwitch_STG_StaticDiag_Time = 200U;  /* 100ms x  */
const uint16_t K_OutsideHandleSwitch_STG_StaticDiag_Time = 200U;  /* 100ms x  */
const uint16_t K_ShutFaceSwitch_STG_StaticDiag_Time = 200U;  /* 100ms x  */  
const uint16_t K_ShutFaceLockSwitch_STG_StaticDiag_Time = 200U;  /* 100ms x  */
const uint16_t K_OpenCloseSwitch_Normal_StaticDiag_Time = 10U;  /* 100ms x  */
const uint16_t K_OutsideHandleSwitch_Normal_StaticDiag_Time = 10U;  /* 100ms x  */
const uint16_t K_ShutFaceSwitch_Normal_StaticDiag_Time = 10U;  /* 100ms x  */  
const uint16_t K_ShutFaceLockSwitch_Normal_StaticDiag_Time = 10U;  /* 100ms x  */

const uint16_t K_PowerSupply_Error_StaticDiag_Time = 30U;  /* 100ms x  */
const uint16_t K_PowerSupply_Normal_StaticDiag_Time = 10U;  /* 100ms x  */
const uint16_t K_DigitalSupply_Error_StaticDiag_Time = 30U;  /* 100ms x  */
const uint16_t K_DigitalSupply_Normal_StaticDiag_Time = 10U;  /* 100ms x  */

const uint16_t K_HallPower1_Normal_StaticDiag_Time = 5U;  /* 100ms x  */
const uint16_t K_HallPower2_Normal_StaticDiag_Time = 5U;  /* 100ms x  */
const uint16_t K_HallPower1_Failure_StaticDiag_Time = 10U;  /* 100ms x  */
const uint16_t K_HallPower2_Failure_StaticDiag_Time = 10U;  /* 100ms x  */
#endif

#ifdef _DFLZM_COM
const uint16_t K_BatteryVoltage_StaticDiag_VolAbove = 1650U; //K_16V5_ATD;
const uint16_t K_BatteryVoltage_StaticDiag_VolBelow = 850U; //K_8V5_ATD;
const uint16_t K_BatteryVoltage_StaticDiag_Recovery_Low = 900U; //K_9V_ATD;
const uint16_t K_BatteryVoltage_StaticDiag_Recovery_High = 1600U; //K_16V_ATD;

const uint16_t K_OpenCloseSwitch_STG_StaticDiag_Time = 200U;  /* 100ms x  */
const uint16_t K_OutsideHandleSwitch_STG_StaticDiag_Time = 200U;  /* 100ms x  */
const uint16_t K_ShutFaceSwitch_STG_StaticDiag_Time = 200U;  /* 100ms x  */  
const uint16_t K_ShutFaceLockSwitch_STG_StaticDiag_Time = 200U;  /* 100ms x  */
const uint16_t K_OpenCloseSwitch_Normal_StaticDiag_Time = 10U;  /* 100ms x  */
const uint16_t K_OutsideHandleSwitch_Normal_StaticDiag_Time = 10U;  /* 100ms x  */
const uint16_t K_ShutFaceSwitch_Normal_StaticDiag_Time = 10U;  /* 100ms x  */  
const uint16_t K_ShutFaceLockSwitch_Normal_StaticDiag_Time = 10U;  /* 100ms x  */

const uint16_t K_PowerSupply_Error_StaticDiag_Time = 30U;  /* 100ms x  */
const uint16_t K_PowerSupply_Normal_StaticDiag_Time = 10U;  /* 100ms x  */
const uint16_t K_DigitalSupply_Error_StaticDiag_Time = 30U;  /* 100ms x  */
const uint16_t K_DigitalSupply_Normal_StaticDiag_Time = 10U;  /* 100ms x  */

const uint16_t K_HallPower1_Normal_StaticDiag_Time = 5U;  /* 100ms x  */
const uint16_t K_HallPower2_Normal_StaticDiag_Time = 5U;  /* 100ms x  */
const uint16_t K_HallPower1_Failure_StaticDiag_Time = 10U;  /* 100ms x  */
const uint16_t K_HallPower2_Failure_StaticDiag_Time = 10U;  /* 100ms x  */
#endif
#ifdef _NIU_COM
const uint16_t K_BatteryVoltage_StaticDiag_VolAbove = 1600U; //K_16V_ATD;
const uint16_t K_BatteryVoltage_StaticDiag_VolBelow = 900U; //K_09V_ATD;
const uint16_t K_BatteryVoltage_StaticDiag_Recovery_Low = 950U; //K_9V5_ATD;
const uint16_t K_BatteryVoltage_StaticDiag_Recovery_High = 1550U; //K_15V5_ATD;

const uint16_t K_OpenCloseSwitch_STG_StaticDiag_Time = 200U;  /* 100ms x  */
const uint16_t K_OutsideHandleSwitch_STG_StaticDiag_Time = 200U;  /* 100ms x  */
const uint16_t K_ShutFaceSwitch_STG_StaticDiag_Time = 200U;  /* 100ms x  */  
const uint16_t K_ShutFaceLockSwitch_STG_StaticDiag_Time = 200U;  /* 100ms x  */
const uint16_t K_OpenCloseSwitch_Normal_StaticDiag_Time = 10U;  /* 100ms x  */
const uint16_t K_OutsideHandleSwitch_Normal_StaticDiag_Time = 10U;  /* 100ms x  */
const uint16_t K_ShutFaceSwitch_Normal_StaticDiag_Time = 10U;  /* 100ms x  */  
const uint16_t K_ShutFaceLockSwitch_Normal_StaticDiag_Time = 10U;  /* 100ms x  */

const uint16_t K_PowerSupply_Error_StaticDiag_Time = 30U;  /* 100ms x  */
const uint16_t K_PowerSupply_Normal_StaticDiag_Time = 10U;  /* 100ms x  */
const uint16_t K_DigitalSupply_Error_StaticDiag_Time = 30U;  /* 100ms x  */
const uint16_t K_DigitalSupply_Normal_StaticDiag_Time = 10U;  /* 100ms x  */

const uint16_t K_HallPower1_Normal_StaticDiag_Time = 5U;  /* 100ms x  */
const uint16_t K_HallPower2_Normal_StaticDiag_Time = 5U;  /* 100ms x  */
const uint16_t K_HallPower1_Failure_StaticDiag_Time = 10U;  /* 100ms x  */
const uint16_t K_HallPower2_Failure_StaticDiag_Time = 10U;  /* 100ms x  */
#endif
#ifdef _FAW_COM
const uint16_t K_BatteryVoltage_StaticDiag_VolAbove = 1650U; //K_16V5_ATD;
const uint16_t K_BatteryVoltage_StaticDiag_VolBelow = 950U; //K_9V5_ATD;
const uint16_t K_BatteryVoltage_StaticDiag_Recovery_Low = 950U; //K_9V5_ATD;
const uint16_t K_BatteryVoltage_StaticDiag_Recovery_High = 1650U; //K_16V5_ATD;

const uint16_t K_OpenCloseSwitch_STG_StaticDiag_Time = 200U;  /* 100ms x  */
const uint16_t K_OutsideHandleSwitch_STG_StaticDiag_Time = 200U;  /* 100ms x  */
const uint16_t K_ShutFaceSwitch_STG_StaticDiag_Time = 200U;  /* 100ms x  */  
const uint16_t K_ShutFaceLockSwitch_STG_StaticDiag_Time = 200U;  /* 100ms x  */
const uint16_t K_OpenCloseSwitch_Normal_StaticDiag_Time = 10U;  /* 100ms x  */
const uint16_t K_OutsideHandleSwitch_Normal_StaticDiag_Time = 10U;  /* 100ms x  */
const uint16_t K_ShutFaceSwitch_Normal_StaticDiag_Time = 10U;  /* 100ms x  */  
const uint16_t K_ShutFaceLockSwitch_Normal_StaticDiag_Time = 10U;  /* 100ms x  */

const uint16_t K_PowerSupply_Error_StaticDiag_Time = 30U;  /* 100ms x  */
const uint16_t K_PowerSupply_Normal_StaticDiag_Time = 10U;  /* 100ms x  */
const uint16_t K_DigitalSupply_Error_StaticDiag_Time = 30U;  /* 100ms x  */
const uint16_t K_DigitalSupply_Normal_StaticDiag_Time = 10U;  /* 100ms x  */

const uint16_t K_HallPower1_Normal_StaticDiag_Time = 5U;  /* 100ms x  */
const uint16_t K_HallPower2_Normal_StaticDiag_Time = 5U;  /* 100ms x  */
const uint16_t K_HallPower1_Failure_StaticDiag_Time = 10U;  /* 100ms x  */
const uint16_t K_HallPower2_Failure_StaticDiag_Time = 10U;  /* 100ms x  */
#endif
#ifdef _CHANGAN_COM
const uint16_t K_BatteryVoltage_StaticDiag_VolAbove = 1600U; //K_16V_ATD;
const uint16_t K_BatteryVoltage_StaticDiag_VolBelow = 900U; //K_09V_ATD;
const uint16_t K_BatteryVoltage_StaticDiag_Recovery_Low = 950U; //K_9V5_ATD;
const uint16_t K_BatteryVoltage_StaticDiag_Recovery_High = 1550U; //K_15V5_ATD;

const uint16_t K_OpenCloseSwitch_STG_StaticDiag_Time = 200U;  /* 100ms x  */
const uint16_t K_OutsideHandleSwitch_STG_StaticDiag_Time = 200U;  /* 100ms x  */
const uint16_t K_ShutFaceSwitch_STG_StaticDiag_Time = 200U;  /* 100ms x  */  
const uint16_t K_ShutFaceLockSwitch_STG_StaticDiag_Time = 200U;  /* 100ms x  */
const uint16_t K_OpenCloseSwitch_Normal_StaticDiag_Time = 10U;  /* 100ms x  */
const uint16_t K_OutsideHandleSwitch_Normal_StaticDiag_Time = 10U;  /* 100ms x  */
const uint16_t K_ShutFaceSwitch_Normal_StaticDiag_Time = 10U;  /* 100ms x  */  
const uint16_t K_ShutFaceLockSwitch_Normal_StaticDiag_Time = 10U;  /* 100ms x  */

const uint16_t K_PowerSupply_Error_StaticDiag_Time = 30U;  /* 100ms x  */
const uint16_t K_PowerSupply_Normal_StaticDiag_Time = 10U;  /* 100ms x  */

const uint16_t K_DigitalSupply_Error_StaticDiag_Time = 30U;  /* 100ms x  */
const uint16_t K_DigitalSupply_Normal_StaticDiag_Time = 10U;  /* 100ms x  */

const uint16_t K_HallPower1_Normal_StaticDiag_Time = 5U;  /* 100ms x  */
const uint16_t K_HallPower2_Normal_StaticDiag_Time = 5U;  /* 100ms x  */
const uint16_t K_HallPower1_Failure_StaticDiag_Time = 10U;  /* 100ms x  */
const uint16_t K_HallPower2_Failure_StaticDiag_Time = 10U;  /* 100ms x  */
#endif

const uint16_t K_BatteryVoltage_StaticDiag_Time = 15U; /* 100ms x  */

const uint16_t K_BatteryVoltage_DynamicDiag_VolAbove = 1600U; //K_16V_ATD;
const uint16_t K_BatteryVoltage_DynamicDiag_VolBelow = 900U; //K_09V_ATD;
const uint16_t K_BatteryVoltage_DynamicDiag_Recovery_Low = 950U; //K_9V5_ATD;
const uint16_t K_BatteryVoltage_DynamicDiag_Recovery_High = 1550U; //K_15V5_ATD;
const uint16_t K_BatteryVoltage_DynamicDiag_Time = 15U; /* 100ms x  */

const uint16_t K_Temperature_StaticDiag_Time = 5U; /* 100ms x  */
const uint16_t K_LatchSwitch_StaticDiag_Time = 5U; /* 100ms x  */

const uint16_t K_AntiPinch_STG_DiagValue = 10U;//200U;
const uint16_t K_AntiPinch_OC_DiagValue = 450U;//3600U;
const uint16_t K_AntiPinch_STB_DiagValue = 480U;//3900U;
const uint16_t K_AntiPinch_STG_StaticDiag_Time = 100U; /* 100ms x  */
const uint16_t K_AntiPinch_OC_StaticDiag_Time = 100U; /* 100ms x  */
const uint16_t K_AntiPinch_STB_StaticDiag_Time = 100U; /* 100ms x  */
const uint16_t K_AntiPinch_Active_StaticDiag_Time = 100U; /* 100ms x  */
const uint16_t K_AntiPinch_Normal_StaticDiag_Time = 10U; /* 100ms x  */
const uint16_t K_AntiPinch_DynamicDiag_Time = 5U; /* 100ms x  */

const uint16_t K_AntiPinchRight_STG_DiagValue = 10U;//200U;
const uint16_t K_AntiPinchRight_OC_DiagValue = 450U;//3600U;
const uint16_t K_AntiPinchRight_STB_DiagValue = 480U;//3900U;
const uint16_t K_AntiPinchRight_STG_StaticDiag_Time = 100U; /* 100ms x  */
const uint16_t K_AntiPinchRight_OC_StaticDiag_Time = 100U; /* 100ms x  */
const uint16_t K_AntiPinchRight_STB_StaticDiag_Time = 100U; /* 100ms x  */
const uint16_t K_AntiPinchRight_Active_StaticDiag_Time = 100U; /* 100ms x  */
const uint16_t K_AntiPinchRight_Normal_StaticDiag_Time = 10U; /* 100ms x  */
const uint16_t K_AntiPinchRight_DynamicDiag_Time = 5U; /* 100ms x  */

const uint16_t K_AntiPinchLeft_STG_DiagValue = 10U;//200U; 
const uint16_t K_AntiPinchLeft_OC_DiagValue = 450U;//3600U;
const uint16_t K_AntiPinchLeft_STB_DiagValue = 480U;//3900U;
const uint16_t K_AntiPinchLeft_STG_StaticDiag_Time = 100U; /* 100ms x  */
const uint16_t K_AntiPinchLeft_OC_StaticDiag_Time = 100U; /* 100ms x  */
const uint16_t K_AntiPinchLeft_STB_StaticDiag_Time = 100U; /* 100ms x  */
const uint16_t K_AntiPinchLeft_Active_StaticDiag_Time = 100U; /* 100ms x  */
const uint16_t K_AntiPinchLeft_Normal_StaticDiag_Time = 10U; /* 100ms x  */
const uint16_t K_AntiPinchLeft_DynamicDiag_Time = 5U; /* 100ms x  */

const uint16_t K_HandleOpenSwitch_StaticDiag_Time = 300U;  /* 100ms x  */ 
const uint16_t K_HandleCloseSwitch_StaticDiag_Time = 300U;  /* 100ms x  */ 

const uint16_t K_HallA1_OverRange_DynamicDiag_HallCount = 1000U;
const uint16_t K_HallA2_OverRange_DynamicDiag_HallCount = 1000U;
const uint16_t K_HallB1_OverRange_DynamicDiag_HallCount = 1000U;
const uint16_t K_HallB2_OverRange_DynamicDiag_HallCount = 1000U;

const uint16_t K_HallA1_NoHall_DynamicDiag_HallCount = 3U;
const uint16_t K_HallA2_NoHall_DynamicDiag_HallCount = 3U;
const uint16_t K_HallB1_NoHall_DynamicDiag_HallCount = 3U;
const uint16_t K_HallB2_NoHall_DynamicDiag_HallCount = 3U;

const uint16_t K_Motor1_DynamicDiag_HallCount_Delta = 3U;
const uint16_t K_Motor2_DynamicDiag_HallCount_Delta = 3U;

const uint16_t K_HallA_DynamicDiag_Time = 10U;   /* 100ms x  */
const uint16_t K_HallB_DynamicDiag_Time = 10U;   /* 100ms x  */

const uint16_t K_Hall_StaticDiag_Delay_Time = 5U;   /* 100ms x  */
const uint16_t K_HallA1_StaticDiag_Time = 3U;   /* 100ms x  */
const uint16_t K_HallA2_StaticDiag_Time = 3U;   /* 100ms x  */
const uint16_t K_HallB1_StaticDiag_Time = 3U;   /* 100ms x  */
const uint16_t K_HallB2_StaticDiag_Time = 3U;   /* 100ms x  */

/*********************************************************************************************
**    Buzzer Control
*********************************************************************************************/

const uint16_t K_Buzzer_Base_Duty = 30U; /*100%*/

const uint16_t K_Mode_0_Period = 50U; /* 50 x 10ms */
const uint16_t K_Mode_0_Duty = 20U; /* 20 x 10ms */

const uint16_t K_Mode_1_Period = 80U; /* 50 x 10ms */
const uint16_t K_Mode_1_Duty = 40U; /* 20 x 10ms */

const uint16_t K_Mode_2_Period = 80U; /* 50 x 10ms */
const uint16_t K_Mode_2_Duty = 40U; /* 20 x 10ms */
 
const uint16_t K_Mode_3_Period = 50U; /* 50 x 10ms */
const uint16_t K_Mode_3_Duty = 20U; /* 20 x 10ms */

const uint16_t K_Mode_4_Period = 50U; /* 50 x 10ms */
const uint16_t K_Mode_4_Duty = 20U; /* 20 x 10ms */
 
const uint16_t K_Mode_5_Period = 50U; /* 50 x 10ms */
const uint16_t K_Mode_5_Duty = 20U; /* 20 x 10ms */

const uint16_t K_Mode_6_Period = 50U; /* 50 x 10ms */
const uint16_t K_Mode_6_Duty = 20U; /* 20 x 10ms */

const uint16_t K_Speaker_Music_Enable = TRUE;
const uint16_t K_Normal_Buzzer_Enable = FALSE;

const uint16_t K_Speaker_Working_Time = 200U; /* 20 x 10ms */

#ifdef _OPERATION_CHIME_10_TIMES
const uint16_t K_Mode_0_Speaker_Break_Time = 50U;
const uint16_t K_Mode_1_Speaker_Break_Time = 30U;  /* 30 x 10ms */
const uint16_t K_Mode_2_Speaker_Break_Time = 20U;  /* 20 x 10ms */
const uint16_t K_Mode_3_Speaker_Break_Time = 20U;  /* 50 x 10ms */
const uint16_t K_Mode_4_Speaker_Break_Time = 50U;  /* 50 x 10ms */
const uint16_t K_Mode_5_Speaker_Break_Time = 50U;  /* 50 x 10ms */
const uint16_t K_Mode_6_Speaker_Break_Time = 50U;  /* 50 x 10ms */

const tD_Buzzer_Mode K_PowerOpen_Buzzer_Mode = Mode_4;
const tD_Buzzer_Priority K_PowerOpen_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_PowerOpen_Buzzer_Repetition = Repetition_10;

const tD_Buzzer_Mode K_PowerClose_Buzzer_Mode = Mode_4;
const tD_Buzzer_Priority K_PowerClose_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_PowerClose_Buzzer_Repetition = Repetition_10;

const tD_Buzzer_Mode K_ReleaseOnly_Buzzer_Mode = Mode_2;
const tD_Buzzer_Priority K_ReleaseOnly_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_ReleaseOnly_Buzzer_Repetition = Repetition_3;

const tD_Buzzer_Mode K_Fault_Buzzer_Mode = Mode_2;
const tD_Buzzer_Priority K_Fault_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_Fault_Buzzer_Repetition = Repetition_3;

const tD_Buzzer_Mode K_PreCondition_Buzzer_Mode = Mode_3;
const tD_Buzzer_Priority K_PreCondition_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_PreCondition_Buzzer_Repetition = Repetition_4;

const tD_Buzzer_Mode K_Brake_Buzzer_Mode = Mode_2;
const tD_Buzzer_Priority K_Brake_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_Brake_Buzzer_Repetition = Repetition_3;

const tD_Buzzer_Mode K_KickSensorStart_Buzzer_Mode = Mode_Idle;
const tD_Buzzer_Priority K_KickSensorStart_Buzzer_Priority = Priority_0;
const tD_Buzzer_Repetition K_KickSensorStart_Buzzer_Repetition = Repetition_0;

const tD_Buzzer_Mode K_KickSensorStop_Buzzer_Mode = Mode_4;
const tD_Buzzer_Priority K_KickSensorStop_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_KickSensorStop_Buzzer_Repetition = Repetition_10;

const tD_Buzzer_Mode K_SoftStop_Buzzer_Mode = Mode_Idle;
const tD_Buzzer_Priority K_SoftStop_Buzzer_Priority = Priority_0;
const tD_Buzzer_Repetition K_SoftStop_Buzzer_Repetition = Repetition_0;

const tD_Buzzer_Mode K_StopDirectly_Buzzer_Mode = Mode_Idle;
const tD_Buzzer_Priority K_StopDirectly_Buzzer_Priority = Priority_0;
const tD_Buzzer_Repetition K_StopDirectly_Buzzer_Repetition = Repetition_0;

const tD_Buzzer_Mode K_Learn_Buzzer_Mode = Mode_1;
const tD_Buzzer_Priority K_Learn_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_Learn_Buzzer_Repetition = Repetition_2;

const tD_Buzzer_Mode K_LearnFailure_Buzzer_Mode = Mode_Idle;
const tD_Buzzer_Priority K_LearnFailure_Buzzer_Priority = Priority_0;
const tD_Buzzer_Repetition K_LearnFailure_Buzzer_Repetition = Repetition_0;

const tD_Buzzer_Mode K_Obstacle_Buzzer_Mode = Mode_2;
const tD_Buzzer_Priority K_Obstacle_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_Obstacle_Buzzer_Repetition = Repetition_3;

const tD_Buzzer_Mode K_Radar_Buzzer_Mode = Mode_2;
const tD_Buzzer_Priority K_Radar_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_Radar_Buzzer_Repetition = Repetition_3;

const tD_Buzzer_Mode K_SpeedStop_Buzzer_Mode = Mode_1;
const tD_Buzzer_Priority K_SpeedStop_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_SpeedStop_Buzzer_Repetition = Repetition_2;

const tD_Buzzer_Mode K_GarageModeChange_Buzzer_Mode = Mode_1;
const tD_Buzzer_Priority K_GarageModeChange_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_GarageModeChange_Buzzer_Repetition = Repetition_2;

const tD_Buzzer_Mode K_DelayClose_Buzzer_Mode = Mode_1;
const tD_Buzzer_Priority K_DelayClose_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_DelayClose_Buzzer_Repetition = Repetition_20;

const tD_Buzzer_Mode K_BoardInclineLearn_Buzzer_Mode = Mode_1;
const tD_Buzzer_Priority K_BoardInclineLearn_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_BoardInclineLearn_Buzzer_Repetition = Repetition_2;

const tD_Buzzer_Mode K_BoardInclineUnlearn_Buzzer_Mode = Mode_1;
const tD_Buzzer_Priority K_BoardInclineUnlearn_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_BoardInclineUnlearn_Buzzer_Repetition = Repetition_1;

const tD_Flasher_Mode K_DelayClose_Flasher_Mode = Flasher_Mode_4;
const tD_Flasher_Priority K_DelayClose_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_DelayClose_Flasher_Repetition = Flasher_Repetition_3;

const tD_Flasher_Mode K_Latch_Flasher_Mode = Flasher_Mode_1;
const tD_Flasher_Priority K_Latch_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_Latch_Flasher_Repetition = Flasher_Repetition_1;

const tD_Flasher_Mode K_ReleaseOnly_Flasher_Mode = Flasher_Mode_2;
const tD_Flasher_Priority K_ReleaseOnly_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_ReleaseOnly_Flasher_Repetition = Flasher_Repetition_3;

const tD_Flasher_Mode K_GarageModeChange_Flasher_Mode = Flasher_Mode_2;
const tD_Flasher_Priority K_GarageModeChange_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_GarageModeChange_Flasher_Repetition = Flasher_Repetition_2;

const tD_Flasher_Mode K_PowerOpen_Flasher_Mode = Flasher_Mode_1;
const tD_Flasher_Priority K_PowerOpen_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_PowerOpen_Flasher_Repetition = Flasher_Repetition_3;

const tD_Flasher_Mode K_PowerClose_Flasher_Mode = Flasher_Mode_1;
const tD_Flasher_Priority K_PowerClose_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_PowerClose_Flasher_Repetition = Flasher_Repetition_3;

const tD_Flasher_Mode K_Fault_Flasher_Mode = Flasher_Mode_2;
const tD_Flasher_Priority K_Fault_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_Fault_Flasher_Repetition = Flasher_Repetition_3;

const tD_Flasher_Mode K_PreCondition_Flasher_Mode = Flasher_Mode_2;
const tD_Flasher_Priority K_PreCondition_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_PreCondition_Flasher_Repetition = Flasher_Repetition_3;

const tD_Flasher_Mode K_Brake_Flasher_Mode = Flasher_Mode_5;
const tD_Flasher_Priority K_Brake_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_Brake_Flasher_Repetition = Flasher_Repetition_5;

const tD_Flasher_Mode K_SpeedStop_Flasher_Mode = Flasher_Mode_5;
const tD_Flasher_Priority K_SpeedStop_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_SpeedStop_Flasher_Repetition = Flasher_Repetition_5;

const tD_Flasher_Mode K_SoftStop_Flasher_Mode = Flasher_Mode_1;
const tD_Flasher_Priority K_SoftStop_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_SoftStop_Flasher_Repetition = Flasher_Repetition_2;

const tD_Flasher_Mode K_StopDirectly_Flasher_Mode = Flasher_Mode_4;
const tD_Flasher_Priority K_StopDirectly_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_StopDirectly_Flasher_Repetition = Flasher_Repetition_3;

const tD_Flasher_Mode K_Learn_Flasher_Mode = Flasher_Mode_2;
const tD_Flasher_Priority K_Learn_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_Learn_Flasher_Repetition = Flasher_Repetition_1;

const tD_Flasher_Mode K_Obstacle_Flasher_Mode = Flasher_Mode_3;
const tD_Flasher_Priority K_Obstacle_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_Obstacle_Flasher_Repetition = Flasher_Repetition_1;

const tD_Flasher_Mode K_Radar_Flasher_Mode = Flasher_Mode_4;
const tD_Flasher_Priority K_Radar_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_Radar_Flasher_Repetition = Flasher_Repetition_1;

const tD_Flasher_Mode K_LearnFailure_Flasher_Mode = Flasher_Mode_Idle;
const tD_Flasher_Priority K_LearnFailure_Flasher_Priority = Flasher_Priority_0;
const tD_Flasher_Repetition K_LearnFailure_Flasher_Repetition = Flasher_Repetition_0;
#endif

#ifdef _OPERATION_CHIME_12_TIMES
const uint16_t K_Mode_0_Speaker_Break_Time = 50U;
const uint16_t K_Mode_1_Speaker_Break_Time = 70U;  /* 30 x 10ms */
const uint16_t K_Mode_2_Speaker_Break_Time = 70U;  /* 20 x 10ms */
const uint16_t K_Mode_3_Speaker_Break_Time = 30U;  /* 50 x 10ms */
const uint16_t K_Mode_4_Speaker_Break_Time = 50U;  /* 50 x 10ms */
const uint16_t K_Mode_5_Speaker_Break_Time = 50U;  /* 50 x 10ms */
const uint16_t K_Mode_6_Speaker_Break_Time = 50U;  /* 50 x 10ms */

const tD_Buzzer_Mode K_PowerOpen_Buzzer_Mode = Mode_1;
const tD_Buzzer_Priority K_PowerOpen_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_PowerOpen_Buzzer_Repetition = Repetition_12;

const tD_Buzzer_Mode K_PowerClose_Buzzer_Mode = Mode_1;
const tD_Buzzer_Priority K_PowerClose_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_PowerClose_Buzzer_Repetition = Repetition_12;

const tD_Buzzer_Mode K_ReleaseOnly_Buzzer_Mode = Mode_Idle;
const tD_Buzzer_Priority K_ReleaseOnly_Buzzer_Priority = Priority_0;
const tD_Buzzer_Repetition K_ReleaseOnly_Buzzer_Repetition = Repetition_0;

const tD_Buzzer_Mode K_Fault_Buzzer_Mode = Mode_3;
const tD_Buzzer_Priority K_Fault_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_Fault_Buzzer_Repetition = Repetition_3;

const tD_Buzzer_Mode K_PreCondition_Buzzer_Mode = Mode_3;
const tD_Buzzer_Priority K_PreCondition_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_PreCondition_Buzzer_Repetition = Repetition_4;

const tD_Buzzer_Mode K_Brake_Buzzer_Mode = Mode_Idle;
const tD_Buzzer_Priority K_Brake_Buzzer_Priority = Priority_0;
const tD_Buzzer_Repetition K_Brake_Buzzer_Repetition = Repetition_0;

const tD_Buzzer_Mode K_KickSensorStart_Buzzer_Mode = Mode_Idle;
const tD_Buzzer_Priority K_KickSensorStart_Buzzer_Priority = Priority_0;
const tD_Buzzer_Repetition K_KickSensorStart_Buzzer_Repetition = Repetition_0;

const tD_Buzzer_Mode K_KickSensorStop_Buzzer_Mode = Mode_Idle;
const tD_Buzzer_Priority K_KickSensorStop_Buzzer_Priority = Priority_0;
const tD_Buzzer_Repetition K_KickSensorStop_Buzzer_Repetition = Repetition_0;

const tD_Buzzer_Mode K_Learn_Buzzer_Mode = Mode_2;
const tD_Buzzer_Priority K_Learn_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_Learn_Buzzer_Repetition = Repetition_1;

const tD_Buzzer_Mode K_LearnFailure_Buzzer_Mode = Mode_Idle;
const tD_Buzzer_Priority K_LearnFailure_Buzzer_Priority = Priority_0;
const tD_Buzzer_Repetition K_LearnFailure_Buzzer_Repetition = Repetition_0;

const tD_Buzzer_Mode K_Obstacle_Buzzer_Mode = Mode_3;
const tD_Buzzer_Priority K_Obstacle_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_Obstacle_Buzzer_Repetition = Repetition_3;

const tD_Buzzer_Mode K_SpeedStop_Buzzer_Mode = Mode_Idle;
const tD_Buzzer_Priority K_SpeedStop_Buzzer_Priority = Priority_0;
const tD_Buzzer_Repetition K_SpeedStop_Buzzer_Repetition = Repetition_0;

const tD_Buzzer_Mode K_SoftStop_Buzzer_Mode = Mode_Idle;
const tD_Buzzer_Priority K_SoftStop_Buzzer_Priority = Priority_0;
const tD_Buzzer_Repetition K_SoftStop_Buzzer_Repetition = Repetition_0;

const tD_Buzzer_Mode K_StopDirectly_Buzzer_Mode = Mode_Idle;
const tD_Buzzer_Priority K_StopDirectly_Buzzer_Priority = Priority_0;
const tD_Buzzer_Repetition K_StopDirectly_Buzzer_Repetition = Repetition_0;

const tD_Buzzer_Mode K_GarageModeChange_Buzzer_Mode = Mode_1;
const tD_Buzzer_Priority K_GarageModeChange_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_GarageModeChange_Buzzer_Repetition = Repetition_3;

const tD_Buzzer_Mode K_DelayClose_Buzzer_Mode = Mode_1;
const tD_Buzzer_Priority K_DelayClose_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_DelayClose_Buzzer_Repetition = Repetition_20;

const tD_Flasher_Mode K_DelayClose_Flasher_Mode = Flasher_Mode_4;
const tD_Flasher_Priority K_DelayClose_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_DelayClose_Flasher_Repetition = Flasher_Repetition_3;

const tD_Flasher_Mode K_Latch_Flasher_Mode = Flasher_Mode_1;
const tD_Flasher_Priority K_Latch_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_Latch_Flasher_Repetition = Flasher_Repetition_1;

const tD_Flasher_Mode K_ReleaseOnly_Flasher_Mode = Flasher_Mode_2;
const tD_Flasher_Priority K_ReleaseOnly_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_ReleaseOnly_Flasher_Repetition = Flasher_Repetition_3;

const tD_Flasher_Mode K_GarageModeChange_Flasher_Mode = Flasher_Mode_2;
const tD_Flasher_Priority K_GarageModeChange_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_GarageModeChange_Flasher_Repetition = Flasher_Repetition_2;

const tD_Flasher_Mode K_PowerOpen_Flasher_Mode = Flasher_Mode_1;
const tD_Flasher_Priority K_PowerOpen_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_PowerOpen_Flasher_Repetition = Flasher_Repetition_3;

const tD_Flasher_Mode K_PowerClose_Flasher_Mode = Flasher_Mode_1;
const tD_Flasher_Priority K_PowerClose_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_PowerClose_Flasher_Repetition = Flasher_Repetition_3;

const tD_Flasher_Mode K_Fault_Flasher_Mode = Flasher_Mode_2;
const tD_Flasher_Priority K_Fault_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_Fault_Flasher_Repetition = Flasher_Repetition_3;

const tD_Flasher_Mode K_PreCondition_Flasher_Mode = Flasher_Mode_2;
const tD_Flasher_Priority K_PreCondition_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_PreCondition_Flasher_Repetition = Flasher_Repetition_3;

const tD_Flasher_Mode K_Brake_Flasher_Mode = Flasher_Mode_5;
const tD_Flasher_Priority K_Brake_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_Brake_Flasher_Repetition = Flasher_Repetition_5;

const tD_Flasher_Mode K_SpeedStop_Flasher_Mode = Flasher_Mode_5;
const tD_Flasher_Priority K_SpeedStop_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_SpeedStop_Flasher_Repetition = Flasher_Repetition_5;

const tD_Flasher_Mode K_SoftStop_Flasher_Mode = Flasher_Mode_1;
const tD_Flasher_Priority K_SoftStop_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_SoftStop_Flasher_Repetition = Flasher_Repetition_2;

const tD_Flasher_Mode K_StopDirectly_Flasher_Mode = Flasher_Mode_4;
const tD_Flasher_Priority K_StopDirectly_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_StopDirectly_Flasher_Repetition = Flasher_Repetition_1;

const tD_Flasher_Mode K_Learn_Flasher_Mode = Flasher_Mode_2;
const tD_Flasher_Priority K_Learn_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_Learn_Flasher_Repetition = Flasher_Repetition_1;

const tD_Flasher_Mode K_Obstacle_Flasher_Mode = Flasher_Mode_3;
const tD_Flasher_Priority K_Obstacle_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_Obstacle_Flasher_Repetition = Flasher_Repetition_1;

const tD_Flasher_Mode K_LearnFailure_Flasher_Mode = Flasher_Mode_Idle;
const tD_Flasher_Priority K_LearnFailure_Flasher_Priority = Flasher_Priority_0;
const tD_Flasher_Repetition K_LearnFailure_Flasher_Repetition = Flasher_Repetition_0;
#endif
		
#ifdef _OPERATION_CHIME_1_TIMES
const uint16_t K_Mode_0_Speaker_Break_Time = 50U;
const uint16_t K_Mode_1_Speaker_Break_Time = 30U;  /* 30 x 10ms */
const uint16_t K_Mode_2_Speaker_Break_Time = 20U;  /* 20 x 10ms */
const uint16_t K_Mode_3_Speaker_Break_Time = 20U;  /* 50 x 10ms */
const uint16_t K_Mode_4_Speaker_Break_Time = 50U;  /* 50 x 10ms */
const uint16_t K_Mode_5_Speaker_Break_Time = 50U;  /* 50 x 10ms */
const uint16_t K_Mode_6_Speaker_Break_Time = 50U;  /* 50 x 10ms */

const tD_Buzzer_Mode K_PowerOpen_Buzzer_Mode = Mode_1;
const tD_Buzzer_Priority K_PowerOpen_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_PowerOpen_Buzzer_Repetition = Repetition_1;

const tD_Buzzer_Mode K_PowerClose_Buzzer_Mode = Mode_1;
const tD_Buzzer_Priority K_PowerClose_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_PowerClose_Buzzer_Repetition = Repetition_1;

const tD_Buzzer_Mode K_ReleaseOnly_Buzzer_Mode = Mode_2;
const tD_Buzzer_Priority K_ReleaseOnly_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_ReleaseOnly_Buzzer_Repetition = Repetition_3;

const tD_Buzzer_Mode K_Fault_Buzzer_Mode = Mode_2;
const tD_Buzzer_Priority K_Fault_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_Fault_Buzzer_Repetition = Repetition_3;

const tD_Buzzer_Mode K_PreCondition_Buzzer_Mode = Mode_3;
const tD_Buzzer_Priority K_PreCondition_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_PreCondition_Buzzer_Repetition = Repetition_4;

const tD_Buzzer_Mode K_Learn_Buzzer_Mode = Mode_1;
const tD_Buzzer_Priority K_Learn_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_Learn_Buzzer_Repetition = Repetition_2;

const tD_Buzzer_Mode K_LearnFailure_Buzzer_Mode = Mode_Idle;
const tD_Buzzer_Priority K_LearnFailure_Buzzer_Priority = Priority_0;
const tD_Buzzer_Repetition K_LearnFailure_Buzzer_Repetition = Repetition_0;

const tD_Buzzer_Mode K_Brake_Buzzer_Mode = Mode_2;
const tD_Buzzer_Priority K_Brake_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_Brake_Buzzer_Repetition = Repetition_3;

const tD_Buzzer_Mode K_KickSensorStart_Buzzer_Mode = Mode_1;
const tD_Buzzer_Priority K_KickSensorStart_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_KickSensorStart_Buzzer_Repetition = Repetition_1;

const tD_Buzzer_Mode K_KickSensorStop_Buzzer_Mode = Mode_1;
const tD_Buzzer_Priority K_KickSensorStop_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_KickSensorStop_Buzzer_Repetition = Repetition_1;

const tD_Buzzer_Mode K_Obstacle_Buzzer_Mode = Mode_2;
const tD_Buzzer_Priority K_Obstacle_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_Obstacle_Buzzer_Repetition = Repetition_3;

const tD_Buzzer_Mode K_SpeedStop_Buzzer_Mode = Mode_1;
const tD_Buzzer_Priority K_SpeedStop_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_SpeedStop_Buzzer_Repetition = Repetition_2;

#ifdef _CHIME_IF_RECEIVE_STOP_COMMAND
const tD_Buzzer_Mode K_SoftStop_Buzzer_Mode = Mode_2;
const tD_Buzzer_Priority K_SoftStop_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_SoftStop_Buzzer_Repetition = Repetition_1;
#else
const tD_Buzzer_Mode K_SoftStop_Buzzer_Mode = Mode_Idle;
const tD_Buzzer_Priority K_SoftStop_Buzzer_Priority = Priority_0;
const tD_Buzzer_Repetition K_SoftStop_Buzzer_Repetition = Repetition_0;
#endif

const tD_Buzzer_Mode K_StopDirectly_Buzzer_Mode = Mode_Idle;
const tD_Buzzer_Priority K_StopDirectly_Buzzer_Priority = Priority_0;
const tD_Buzzer_Repetition K_StopDirectly_Buzzer_Repetition = Repetition_0;

const tD_Buzzer_Mode K_GarageModeChange_Buzzer_Mode = Mode_1;
const tD_Buzzer_Priority K_GarageModeChange_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_GarageModeChange_Buzzer_Repetition = Repetition_3;

const tD_Buzzer_Mode K_DelayClose_Buzzer_Mode = Mode_1;
const tD_Buzzer_Priority K_DelayClose_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_DelayClose_Buzzer_Repetition = Repetition_20;

const tD_Flasher_Mode K_DelayClose_Flasher_Mode = Flasher_Mode_4;
const tD_Flasher_Priority K_DelayClose_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_DelayClose_Flasher_Repetition = Flasher_Repetition_3;

const tD_Flasher_Mode K_Latch_Flasher_Mode = Flasher_Mode_1;
const tD_Flasher_Priority K_Latch_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_Latch_Flasher_Repetition = Flasher_Repetition_1;

const tD_Flasher_Mode K_ReleaseOnly_Flasher_Mode = Flasher_Mode_2;
const tD_Flasher_Priority K_ReleaseOnly_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_ReleaseOnly_Flasher_Repetition = Flasher_Repetition_3;

const tD_Flasher_Mode K_GarageModeChange_Flasher_Mode = Flasher_Mode_2;
const tD_Flasher_Priority K_GarageModeChange_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_GarageModeChange_Flasher_Repetition = Flasher_Repetition_2;

const tD_Flasher_Mode K_PowerOpen_Flasher_Mode = Flasher_Mode_1;
const tD_Flasher_Priority K_PowerOpen_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_PowerOpen_Flasher_Repetition = Flasher_Repetition_1;

const tD_Flasher_Mode K_PowerClose_Flasher_Mode = Flasher_Mode_1;
const tD_Flasher_Priority K_PowerClose_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_PowerClose_Flasher_Repetition = Flasher_Repetition_1;

const tD_Flasher_Mode K_Fault_Flasher_Mode = Flasher_Mode_2;
const tD_Flasher_Priority K_Fault_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_Fault_Flasher_Repetition = Flasher_Repetition_3;

const tD_Flasher_Mode K_PreCondition_Flasher_Mode = Flasher_Mode_3;
const tD_Flasher_Priority K_PreCondition_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_PreCondition_Flasher_Repetition = Flasher_Repetition_4;

const tD_Flasher_Mode K_Brake_Flasher_Mode = Flasher_Mode_5;
const tD_Flasher_Priority K_Brake_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_Brake_Flasher_Repetition = Flasher_Repetition_5;

const tD_Flasher_Mode K_SpeedStop_Flasher_Mode = Flasher_Mode_5;
const tD_Flasher_Priority K_SpeedStop_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_SpeedStop_Flasher_Repetition = Flasher_Repetition_5;

const tD_Flasher_Mode K_SoftStop_Flasher_Mode = Flasher_Mode_1;
const tD_Flasher_Priority K_SoftStop_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_SoftStop_Flasher_Repetition = Flasher_Repetition_2;

const tD_Flasher_Mode K_StopDirectly_Flasher_Mode = Flasher_Mode_4;
const tD_Flasher_Priority K_StopDirectly_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_StopDirectly_Flasher_Repetition = Flasher_Repetition_1;

const tD_Flasher_Mode K_Learn_Flasher_Mode = Flasher_Mode_2;
const tD_Flasher_Priority K_Learn_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_Learn_Flasher_Repetition = Flasher_Repetition_1;

const tD_Flasher_Mode K_Obstacle_Flasher_Mode = Flasher_Mode_3;
const tD_Flasher_Priority K_Obstacle_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_Obstacle_Flasher_Repetition = Flasher_Repetition_1;

const tD_Flasher_Mode K_LearnFailure_Flasher_Mode = Flasher_Mode_Idle;
const tD_Flasher_Priority K_LearnFailure_Flasher_Priority = Flasher_Priority_0;
const tD_Flasher_Repetition K_LearnFailure_Flasher_Repetition = Flasher_Repetition_0;
#endif
	   
#ifdef _OPERATION_CHIME_2_TIMES
const uint16_t K_Mode_0_Speaker_Break_Time = 50U;
const uint16_t K_Mode_1_Speaker_Break_Time = 30U;  /* 30 x 10ms */
const uint16_t K_Mode_2_Speaker_Break_Time = 20U;  /* 20 x 10ms */
const uint16_t K_Mode_3_Speaker_Break_Time = 20U;  /* 50 x 10ms */
const uint16_t K_Mode_4_Speaker_Break_Time = 50U;  /* 50 x 10ms */
const uint16_t K_Mode_5_Speaker_Break_Time = 50U;  /* 50 x 10ms */
const uint16_t K_Mode_6_Speaker_Break_Time = 50U;  /* 50 x 10ms */

const tD_Buzzer_Mode K_PowerOpen_Buzzer_Mode = Mode_1;
const tD_Buzzer_Priority K_PowerOpen_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_PowerOpen_Buzzer_Repetition = Repetition_2;

const tD_Buzzer_Mode K_PowerClose_Buzzer_Mode = Mode_1;
const tD_Buzzer_Priority K_PowerClose_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_PowerClose_Buzzer_Repetition = Repetition_2;

const tD_Buzzer_Mode K_ReleaseOnly_Buzzer_Mode = Mode_2;
const tD_Buzzer_Priority K_ReleaseOnly_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_ReleaseOnly_Buzzer_Repetition = Repetition_3;

const tD_Buzzer_Mode K_Fault_Buzzer_Mode = Mode_2;
const tD_Buzzer_Priority K_Fault_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_Fault_Buzzer_Repetition = Repetition_3;

const tD_Buzzer_Mode K_PreCondition_Buzzer_Mode = Mode_3;
const tD_Buzzer_Priority K_PreCondition_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_PreCondition_Buzzer_Repetition = Repetition_4;

const tD_Buzzer_Mode K_Learn_Buzzer_Mode = Mode_1;
const tD_Buzzer_Priority K_Learn_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_Learn_Buzzer_Repetition = Repetition_2;

const tD_Buzzer_Mode K_LearnFailure_Buzzer_Mode = Mode_Idle;
const tD_Buzzer_Priority K_LearnFailure_Buzzer_Priority = Priority_0;
const tD_Buzzer_Repetition K_LearnFailure_Buzzer_Repetition = Repetition_0;

const tD_Buzzer_Mode K_Brake_Buzzer_Mode = Mode_2;
const tD_Buzzer_Priority K_Brake_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_Brake_Buzzer_Repetition = Repetition_3;

const tD_Buzzer_Mode K_KickSensorStart_Buzzer_Mode = Mode_1;
const tD_Buzzer_Priority K_KickSensorStart_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_KickSensorStart_Buzzer_Repetition = Repetition_2;

const tD_Buzzer_Mode K_KickSensorStop_Buzzer_Mode = Mode_1;
const tD_Buzzer_Priority K_KickSensorStop_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_KickSensorStop_Buzzer_Repetition = Repetition_2;

const tD_Buzzer_Mode K_Obstacle_Buzzer_Mode = Mode_2;
const tD_Buzzer_Priority K_Obstacle_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_Obstacle_Buzzer_Repetition = Repetition_3;

const tD_Buzzer_Mode K_SpeedStop_Buzzer_Mode = Mode_1;
const tD_Buzzer_Priority K_SpeedStop_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_SpeedStop_Buzzer_Repetition = Repetition_2;

const tD_Buzzer_Mode K_SoftStop_Buzzer_Mode = Mode_Idle;
const tD_Buzzer_Priority K_SoftStop_Buzzer_Priority = Priority_0;
const tD_Buzzer_Repetition K_SoftStop_Buzzer_Repetition = Repetition_0;

const tD_Buzzer_Mode K_StopDirectly_Buzzer_Mode = Mode_Idle;
const tD_Buzzer_Priority K_StopDirectly_Buzzer_Priority = Priority_0;
const tD_Buzzer_Repetition K_StopDirectly_Buzzer_Repetition = Repetition_0;

const tD_Buzzer_Mode K_GarageModeChange_Buzzer_Mode = Mode_1;
const tD_Buzzer_Priority K_GarageModeChange_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_GarageModeChange_Buzzer_Repetition = Repetition_3;

const tD_Buzzer_Mode K_DelayClose_Buzzer_Mode = Mode_1;
const tD_Buzzer_Priority K_DelayClose_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_DelayClose_Buzzer_Repetition = Repetition_20;

const tD_Flasher_Mode K_DelayClose_Flasher_Mode = Flasher_Mode_4;
const tD_Flasher_Priority K_DelayClose_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_DelayClose_Flasher_Repetition = Flasher_Repetition_3;

const tD_Flasher_Mode K_Latch_Flasher_Mode = Flasher_Mode_1;
const tD_Flasher_Priority K_Latch_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_Latch_Flasher_Repetition = Flasher_Repetition_1;

const tD_Flasher_Mode K_ReleaseOnly_Flasher_Mode = Flasher_Mode_2;
const tD_Flasher_Priority K_ReleaseOnly_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_ReleaseOnly_Flasher_Repetition = Flasher_Repetition_3;

const tD_Flasher_Mode K_GarageModeChange_Flasher_Mode = Flasher_Mode_2;
const tD_Flasher_Priority K_GarageModeChange_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_GarageModeChange_Flasher_Repetition = Flasher_Repetition_2;

const tD_Flasher_Mode K_PowerOpen_Flasher_Mode = Flasher_Mode_1;
const tD_Flasher_Priority K_PowerOpen_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_PowerOpen_Flasher_Repetition = Flasher_Repetition_3;

const tD_Flasher_Mode K_PowerClose_Flasher_Mode = Flasher_Mode_1;
const tD_Flasher_Priority K_PowerClose_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_PowerClose_Flasher_Repetition = Flasher_Repetition_3;

const tD_Flasher_Mode K_Fault_Flasher_Mode = Flasher_Mode_2;
const tD_Flasher_Priority K_Fault_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_Fault_Flasher_Repetition = Flasher_Repetition_3;

const tD_Flasher_Mode K_PreCondition_Flasher_Mode = Flasher_Mode_3;
const tD_Flasher_Priority K_PreCondition_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_PreCondition_Flasher_Repetition = Flasher_Repetition_4;

const tD_Flasher_Mode K_Brake_Flasher_Mode = Flasher_Mode_5;
const tD_Flasher_Priority K_Brake_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_Brake_Flasher_Repetition = Flasher_Repetition_5;

const tD_Flasher_Mode K_SpeedStop_Flasher_Mode = Flasher_Mode_5;
const tD_Flasher_Priority K_SpeedStop_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_SpeedStop_Flasher_Repetition = Flasher_Repetition_5;

const tD_Flasher_Mode K_SoftStop_Flasher_Mode = Flasher_Mode_1;
const tD_Flasher_Priority K_SoftStop_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_SoftStop_Flasher_Repetition = Flasher_Repetition_2;

const tD_Flasher_Mode K_StopDirectly_Flasher_Mode = Flasher_Mode_4;
const tD_Flasher_Priority K_StopDirectly_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_StopDirectly_Flasher_Repetition = Flasher_Repetition_1;

const tD_Flasher_Mode K_Learn_Flasher_Mode = Flasher_Mode_2;
const tD_Flasher_Priority K_Learn_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_Learn_Flasher_Repetition = Flasher_Repetition_1;

const tD_Flasher_Mode K_Obstacle_Flasher_Mode = Flasher_Mode_3;
const tD_Flasher_Priority K_Obstacle_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_Obstacle_Flasher_Repetition = Flasher_Repetition_1;

const tD_Flasher_Mode K_LearnFailure_Flasher_Mode = Flasher_Mode_Idle;
const tD_Flasher_Priority K_LearnFailure_Flasher_Priority = Flasher_Priority_0;
const tD_Flasher_Repetition K_LearnFailure_Flasher_Repetition = Flasher_Repetition_0;
#endif

#ifdef _OPERATION_CHIME_3_TIMES
const uint16_t K_Mode_0_Speaker_Break_Time = 50U;
const uint16_t K_Mode_1_Speaker_Break_Time = 30U;  /* 30 x 10ms */
const uint16_t K_Mode_2_Speaker_Break_Time = 20U;  /* 20 x 10ms */
const uint16_t K_Mode_3_Speaker_Break_Time = 20U;  /* 50 x 10ms */
const uint16_t K_Mode_4_Speaker_Break_Time = 50U;  /* 50 x 10ms */
const uint16_t K_Mode_5_Speaker_Break_Time = 50U;  /* 50 x 10ms */
const uint16_t K_Mode_6_Speaker_Break_Time = 50U;  /* 50 x 10ms */

const tD_Buzzer_Mode K_PowerOpen_Buzzer_Mode = Mode_1;
const tD_Buzzer_Priority K_PowerOpen_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_PowerOpen_Buzzer_Repetition = Repetition_3;

const tD_Buzzer_Mode K_PowerClose_Buzzer_Mode = Mode_1;
const tD_Buzzer_Priority K_PowerClose_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_PowerClose_Buzzer_Repetition = Repetition_3;

const tD_Buzzer_Mode K_ReleaseOnly_Buzzer_Mode = Mode_Idle;
const tD_Buzzer_Priority K_ReleaseOnly_Buzzer_Priority = Priority_0;
const tD_Buzzer_Repetition K_ReleaseOnly_Buzzer_Repetition = Repetition_0;

const tD_Buzzer_Mode K_Fault_Buzzer_Mode = Mode_1;
const tD_Buzzer_Priority K_Fault_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_Fault_Buzzer_Repetition = Repetition_1;

const tD_Buzzer_Mode K_PreCondition_Buzzer_Mode = Mode_3;
const tD_Buzzer_Priority K_PreCondition_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_PreCondition_Buzzer_Repetition = Repetition_4;

const tD_Buzzer_Mode K_Learn_Buzzer_Mode = Mode_1;
const tD_Buzzer_Priority K_Learn_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_Learn_Buzzer_Repetition = Repetition_2;

const tD_Buzzer_Mode K_LearnFailure_Buzzer_Mode = Mode_Idle;
const tD_Buzzer_Priority K_LearnFailure_Buzzer_Priority = Priority_0;
const tD_Buzzer_Repetition K_LearnFailure_Buzzer_Repetition = Repetition_0;

const tD_Buzzer_Mode K_Brake_Buzzer_Mode = Mode_Idle;
const tD_Buzzer_Priority K_Brake_Buzzer_Priority = Priority_0;
const tD_Buzzer_Repetition K_Brake_Buzzer_Repetition = Repetition_0;

const tD_Buzzer_Mode K_KickSensorStart_Buzzer_Mode = Mode_Idle;
const tD_Buzzer_Priority K_KickSensorStart_Buzzer_Priority = Priority_0;
const tD_Buzzer_Repetition K_KickSensorStart_Buzzer_Repetition = Repetition_0;

const tD_Buzzer_Mode K_KickSensorStop_Buzzer_Mode = Mode_Idle;
const tD_Buzzer_Priority K_KickSensorStop_Buzzer_Priority = Priority_0;
const tD_Buzzer_Repetition K_KickSensorStop_Buzzer_Repetition = Repetition_0;

const tD_Buzzer_Mode K_Obstacle_Buzzer_Mode = Mode_1;
const tD_Buzzer_Priority K_Obstacle_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_Obstacle_Buzzer_Repetition = Repetition_1;

const tD_Buzzer_Mode K_SpeedStop_Buzzer_Mode = Mode_Idle;
const tD_Buzzer_Priority K_SpeedStop_Buzzer_Priority = Priority_0;
const tD_Buzzer_Repetition K_SpeedStop_Buzzer_Repetition = Repetition_0;

const tD_Buzzer_Mode K_SoftStop_Buzzer_Mode = Mode_Idle;
const tD_Buzzer_Priority K_SoftStop_Buzzer_Priority = Priority_0;
const tD_Buzzer_Repetition K_SoftStop_Buzzer_Repetition = Repetition_0;

const tD_Buzzer_Mode K_StopDirectly_Buzzer_Mode = Mode_Idle;
const tD_Buzzer_Priority K_StopDirectly_Buzzer_Priority = Priority_0;
const tD_Buzzer_Repetition K_StopDirectly_Buzzer_Repetition = Repetition_0;

const tD_Buzzer_Mode K_GarageModeChange_Buzzer_Mode = Mode_1;
const tD_Buzzer_Priority K_GarageModeChange_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_GarageModeChange_Buzzer_Repetition = Repetition_3;

const tD_Buzzer_Mode K_DelayClose_Buzzer_Mode = Mode_1;
const tD_Buzzer_Priority K_DelayClose_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_DelayClose_Buzzer_Repetition = Repetition_20;

const tD_Flasher_Mode K_DelayClose_Flasher_Mode = Flasher_Mode_4;
const tD_Flasher_Priority K_DelayClose_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_DelayClose_Flasher_Repetition = Flasher_Repetition_3;

const tD_Flasher_Mode K_Latch_Flasher_Mode = Flasher_Mode_1;
const tD_Flasher_Priority K_Latch_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_Latch_Flasher_Repetition = Flasher_Repetition_1;

const tD_Flasher_Mode K_ReleaseOnly_Flasher_Mode = Flasher_Mode_Idle;
const tD_Flasher_Priority K_ReleaseOnly_Flasher_Priority = Flasher_Priority_0;
const tD_Flasher_Repetition K_ReleaseOnly_Flasher_Repetition = Flasher_Repetition_0;

const tD_Flasher_Mode K_GarageModeChange_Flasher_Mode = Flasher_Mode_2;
const tD_Flasher_Priority K_GarageModeChange_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_GarageModeChange_Flasher_Repetition = Flasher_Repetition_2;

const tD_Flasher_Mode K_PowerOpen_Flasher_Mode = Flasher_Mode_1;
const tD_Flasher_Priority K_PowerOpen_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_PowerOpen_Flasher_Repetition = Flasher_Repetition_3;

const tD_Flasher_Mode K_PowerClose_Flasher_Mode = Flasher_Mode_1;
const tD_Flasher_Priority K_PowerClose_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_PowerClose_Flasher_Repetition = Flasher_Repetition_3;

const tD_Flasher_Mode K_Fault_Flasher_Mode = Flasher_Mode_2;
const tD_Flasher_Priority K_Fault_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_Fault_Flasher_Repetition = Flasher_Repetition_3;

const tD_Flasher_Mode K_PreCondition_Flasher_Mode = Flasher_Mode_3;
const tD_Flasher_Priority K_PreCondition_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_PreCondition_Flasher_Repetition = Flasher_Repetition_4;

const tD_Flasher_Mode K_Brake_Flasher_Mode = Flasher_Mode_5;
const tD_Flasher_Priority K_Brake_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_Brake_Flasher_Repetition = Flasher_Repetition_5;

const tD_Flasher_Mode K_SpeedStop_Flasher_Mode = Flasher_Mode_5;
const tD_Flasher_Priority K_SpeedStop_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_SpeedStop_Flasher_Repetition = Flasher_Repetition_5;

const tD_Flasher_Mode K_SoftStop_Flasher_Mode = Flasher_Mode_1;
const tD_Flasher_Priority K_SoftStop_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_SoftStop_Flasher_Repetition = Flasher_Repetition_2;

const tD_Flasher_Mode K_StopDirectly_Flasher_Mode = Flasher_Mode_4;
const tD_Flasher_Priority K_StopDirectly_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_StopDirectly_Flasher_Repetition = Flasher_Repetition_1;

const tD_Flasher_Mode K_Learn_Flasher_Mode = Flasher_Mode_2;
const tD_Flasher_Priority K_Learn_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_Learn_Flasher_Repetition = Flasher_Repetition_1;

const tD_Flasher_Mode K_Obstacle_Flasher_Mode = Flasher_Mode_3;
const tD_Flasher_Priority K_Obstacle_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_Obstacle_Flasher_Repetition = Flasher_Repetition_1;

const tD_Flasher_Mode K_LearnFailure_Flasher_Mode = Flasher_Mode_Idle;
const tD_Flasher_Priority K_LearnFailure_Flasher_Priority = Flasher_Priority_0;
const tD_Flasher_Repetition K_LearnFailure_Flasher_Repetition = Flasher_Repetition_0;
#endif

#ifdef _CONFIG_Flasher
const uint16_t K_Mode_0_Flasher_Break_Time = 50U;
const uint16_t K_Mode_1_Flasher_Break_Time = 10U;  /* x 10ms */
const uint16_t K_Mode_2_Flasher_Break_Time = 50U;  /* x 10ms */
const uint16_t K_Mode_3_Flasher_Break_Time = 50U;  /* x 10ms */
const uint16_t K_Mode_4_Flasher_Break_Time = 50U;  /* x 10ms */
const uint16_t K_Mode_5_Flasher_Break_Time = 50U;  /* x 10ms */
const uint16_t K_Mode_6_Flasher_Break_Time = 50U;  /* x 10ms */
#endif

#ifdef _OPERATION_CHIME_BAIC_TIMES
const uint16_t K_Mode_0_Speaker_Break_Time = 50U;
const uint16_t K_Mode_1_Speaker_Break_Time = 80U;  /* 30 x 10ms */
const uint16_t K_Mode_2_Speaker_Break_Time = 80U;  /* 20 x 10ms */
const uint16_t K_Mode_3_Speaker_Break_Time = 80U;  /* 50 x 10ms */
const uint16_t K_Mode_4_Speaker_Break_Time = 80U;  /* 50 x 10ms */
const uint16_t K_Mode_5_Speaker_Break_Time = 80U;  /* 50 x 10ms */
const uint16_t K_Mode_6_Speaker_Break_Time = 80U;  /* 50 x 10ms */

const tD_Buzzer_Mode K_PowerOpen_Buzzer_Mode = Mode_1;
const tD_Buzzer_Priority K_PowerOpen_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_PowerOpen_Buzzer_Repetition = Repetition_4;//Repetition_3;

const tD_Buzzer_Mode K_PowerClose_Buzzer_Mode = Mode_2;
const tD_Buzzer_Priority K_PowerClose_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_PowerClose_Buzzer_Repetition = Repetition_4;//Repetition_3;


const tD_Buzzer_Mode K_ReleaseOnly_Buzzer_Mode = Mode_Idle;
const tD_Buzzer_Priority K_ReleaseOnly_Buzzer_Priority = Priority_0;
const tD_Buzzer_Repetition K_ReleaseOnly_Buzzer_Repetition = Repetition_0;

const tD_Buzzer_Mode K_Fault_Buzzer_Mode = Mode_Idle;
const tD_Buzzer_Priority K_Fault_Buzzer_Priority = Priority_0;
const tD_Buzzer_Repetition K_Fault_Buzzer_Repetition = Repetition_0;

const tD_Buzzer_Mode K_PreCondition_Buzzer_Mode = Mode_Idle;
const tD_Buzzer_Priority K_PreCondition_Buzzer_Priority = Priority_0;
const tD_Buzzer_Repetition K_PreCondition_Buzzer_Repetition = Repetition_0;

const tD_Buzzer_Mode K_Learn_Buzzer_Mode = Mode_2;
const tD_Buzzer_Priority K_Learn_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_Learn_Buzzer_Repetition = Repetition_1;

const tD_Buzzer_Mode K_LearnFailure_Buzzer_Mode = Mode_Idle;
const tD_Buzzer_Priority K_LearnFailure_Buzzer_Priority = Priority_0;
const tD_Buzzer_Repetition K_LearnFailure_Buzzer_Repetition = Repetition_0;

const tD_Buzzer_Mode K_Brake_Buzzer_Mode = Mode_Idle;
const tD_Buzzer_Priority K_Brake_Buzzer_Priority = Priority_0;
const tD_Buzzer_Repetition K_Brake_Buzzer_Repetition = Repetition_0;

const tD_Buzzer_Mode K_KickSensorStart_Buzzer_Mode = Mode_Idle;
const tD_Buzzer_Priority K_KickSensorStart_Buzzer_Priority = Priority_0;
const tD_Buzzer_Repetition K_KickSensorStart_Buzzer_Repetition = Repetition_0;

const tD_Buzzer_Mode K_KickSensorStop_Buzzer_Mode = Mode_Idle;
const tD_Buzzer_Priority K_KickSensorStop_Buzzer_Priority = Priority_0;
const tD_Buzzer_Repetition K_KickSensorStop_Buzzer_Repetition = Repetition_0;

const tD_Buzzer_Mode K_Obstacle_Buzzer_Mode = Mode_3;
const tD_Buzzer_Priority K_Obstacle_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_Obstacle_Buzzer_Repetition = Repetition_1;

const tD_Buzzer_Mode K_SpeedStop_Buzzer_Mode = Mode_Idle;
const tD_Buzzer_Priority K_SpeedStop_Buzzer_Priority = Priority_0;
const tD_Buzzer_Repetition K_SpeedStop_Buzzer_Repetition = Repetition_0;

#ifdef _CHIME_IF_RECEIVE_STOP_COMMAND
const tD_Buzzer_Mode K_SoftStop_Buzzer_Mode = Mode_Idle;
const tD_Buzzer_Priority K_SoftStop_Buzzer_Priority = Priority_0;
const tD_Buzzer_Repetition K_SoftStop_Buzzer_Repetition = Repetition_0;
#else
const tD_Buzzer_Mode K_SoftStop_Buzzer_Mode = Mode_Idle;
const tD_Buzzer_Priority K_SoftStop_Buzzer_Priority = Priority_0;
const tD_Buzzer_Repetition K_SoftStop_Buzzer_Repetition = Repetition_0;
#endif

const tD_Buzzer_Mode K_StopDirectly_Buzzer_Mode = Mode_Idle;
const tD_Buzzer_Priority K_StopDirectly_Buzzer_Priority = Priority_0;
const tD_Buzzer_Repetition K_StopDirectly_Buzzer_Repetition = Repetition_0;

const tD_Buzzer_Mode K_GarageModeChange_Buzzer_Mode = Mode_Idle;
const tD_Buzzer_Priority K_GarageModeChange_Buzzer_Priority = Priority_0;
const tD_Buzzer_Repetition K_GarageModeChange_Buzzer_Repetition = Repetition_0;

const tD_Buzzer_Mode K_DelayClose_Buzzer_Mode = Mode_1;
const tD_Buzzer_Priority K_DelayClose_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_DelayClose_Buzzer_Repetition = Repetition_2;

const tD_Flasher_Mode K_DelayClose_Flasher_Mode = Flasher_Mode_1;
const tD_Flasher_Priority K_DelayClose_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_DelayClose_Flasher_Repetition = Flasher_Repetition_2;

const tD_Flasher_Mode K_Latch_Flasher_Mode = Flasher_Mode_Idle;
const tD_Flasher_Priority K_Latch_Flasher_Priority = Flasher_Priority_0;
const tD_Flasher_Repetition K_Latch_Flasher_Repetition = Flasher_Repetition_0;

const tD_Flasher_Mode K_ReleaseOnly_Flasher_Mode = Flasher_Mode_Idle;
const tD_Flasher_Priority K_ReleaseOnly_Flasher_Priority = Flasher_Priority_0;
const tD_Flasher_Repetition K_ReleaseOnly_Flasher_Repetition = Flasher_Repetition_0;

const tD_Flasher_Mode K_GarageModeChange_Flasher_Mode = Flasher_Mode_Idle;
const tD_Flasher_Priority K_GarageModeChange_Flasher_Priority = Flasher_Priority_0;
const tD_Flasher_Repetition K_GarageModeChange_Flasher_Repetition = Flasher_Repetition_0;

const tD_Flasher_Mode K_PowerOpen_Flasher_Mode = Flasher_Mode_1;
const tD_Flasher_Priority K_PowerOpen_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_PowerOpen_Flasher_Repetition = Flasher_Repetition_3;

const tD_Flasher_Mode K_PowerClose_Flasher_Mode = Flasher_Mode_2;
const tD_Flasher_Priority K_PowerClose_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_PowerClose_Flasher_Repetition = Flasher_Repetition_3;

const tD_Flasher_Mode K_Fault_Flasher_Mode = Flasher_Mode_Idle;
const tD_Flasher_Priority K_Fault_Flasher_Priority = Flasher_Priority_0;
const tD_Flasher_Repetition K_Fault_Flasher_Repetition = Flasher_Repetition_0;

const tD_Flasher_Mode K_PreCondition_Flasher_Mode = Flasher_Mode_Idle;
const tD_Flasher_Priority K_PreCondition_Flasher_Priority = Flasher_Priority_0;
const tD_Flasher_Repetition K_PreCondition_Flasher_Repetition = Flasher_Repetition_0;

const tD_Flasher_Mode K_Brake_Flasher_Mode = Flasher_Mode_Idle;
const tD_Flasher_Priority K_Brake_Flasher_Priority = Flasher_Priority_0;
const tD_Flasher_Repetition K_Brake_Flasher_Repetition = Flasher_Repetition_0;

const tD_Flasher_Mode K_SpeedStop_Flasher_Mode = Flasher_Mode_Idle;
const tD_Flasher_Priority K_SpeedStop_Flasher_Priority = Flasher_Priority_0;
const tD_Flasher_Repetition K_SpeedStop_Flasher_Repetition = Flasher_Repetition_0;

const tD_Flasher_Mode K_SoftStop_Flasher_Mode = Flasher_Mode_Idle;
const tD_Flasher_Priority K_SoftStop_Flasher_Priority = Flasher_Priority_0;
const tD_Flasher_Repetition K_SoftStop_Flasher_Repetition = Flasher_Repetition_0;

const tD_Flasher_Mode K_StopDirectly_Flasher_Mode = Flasher_Mode_Idle;
const tD_Flasher_Priority K_StopDirectly_Flasher_Priority = Flasher_Priority_0;
const tD_Flasher_Repetition K_StopDirectly_Flasher_Repetition = Flasher_Repetition_0;

const tD_Flasher_Mode K_Learn_Flasher_Mode = Flasher_Mode_2;
const tD_Flasher_Priority K_Learn_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_Learn_Flasher_Repetition = Flasher_Repetition_1;

const tD_Flasher_Mode K_Obstacle_Flasher_Mode = Flasher_Mode_3;
const tD_Flasher_Priority K_Obstacle_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_Obstacle_Flasher_Repetition = Flasher_Repetition_1;

const tD_Flasher_Mode K_LearnFailure_Flasher_Mode = Flasher_Mode_Idle;
const tD_Flasher_Priority K_LearnFailure_Flasher_Priority = Flasher_Priority_0;
const tD_Flasher_Repetition K_LearnFailure_Flasher_Repetition = Flasher_Repetition_0;
#endif

#ifdef _OPERATION_CHIME_DFLZM_TIMES
const uint16_t K_Mode_0_Speaker_Break_Time = 50U;
const uint16_t K_Mode_1_Speaker_Break_Time = 40U;  /* 30 x 10ms */
const uint16_t K_Mode_2_Speaker_Break_Time = 80U;  /* 20 x 10ms */
const uint16_t K_Mode_3_Speaker_Break_Time = 50U;  /* 50 x 10ms */
const uint16_t K_Mode_4_Speaker_Break_Time = 50U;  /* 50 x 10ms */
const uint16_t K_Mode_5_Speaker_Break_Time = 50U;  /* 50 x 10ms */
const uint16_t K_Mode_6_Speaker_Break_Time = 50U;  /* 50 x 10ms */

const tD_Buzzer_Mode K_PowerOpen_Buzzer_Mode = Mode_1;
const tD_Buzzer_Priority K_PowerOpen_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_PowerOpen_Buzzer_Repetition = Repetition_2;//Repetition_3;

const tD_Buzzer_Mode K_PowerClose_Buzzer_Mode = Mode_1;
const tD_Buzzer_Priority K_PowerClose_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_PowerClose_Buzzer_Repetition = Repetition_2;//Repetition_3;

const tD_Buzzer_Mode K_ReleaseOnly_Buzzer_Mode = Mode_Idle;
const tD_Buzzer_Priority K_ReleaseOnly_Buzzer_Priority = Priority_0;
const tD_Buzzer_Repetition K_ReleaseOnly_Buzzer_Repetition = Repetition_0;

const tD_Buzzer_Mode K_Fault_Buzzer_Mode = Mode_Idle;
const tD_Buzzer_Priority K_Fault_Buzzer_Priority = Priority_0;
const tD_Buzzer_Repetition K_Fault_Buzzer_Repetition = Repetition_0;

const tD_Buzzer_Mode K_PreCondition_Buzzer_Mode = Mode_1;
const tD_Buzzer_Priority K_PreCondition_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_PreCondition_Buzzer_Repetition = Repetition_3;

const tD_Buzzer_Mode K_Learn_Buzzer_Mode = Mode_3;
const tD_Buzzer_Priority K_Learn_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_Learn_Buzzer_Repetition = Repetition_1;

const tD_Buzzer_Mode K_LearnFailure_Buzzer_Mode = Mode_Idle;
const tD_Buzzer_Priority K_LearnFailure_Buzzer_Priority = Priority_0;
const tD_Buzzer_Repetition K_LearnFailure_Buzzer_Repetition = Repetition_0;

const tD_Buzzer_Mode K_Brake_Buzzer_Mode = Mode_Idle;
const tD_Buzzer_Priority K_Brake_Buzzer_Priority = Priority_0;
const tD_Buzzer_Repetition K_Brake_Buzzer_Repetition = Repetition_0;

const tD_Buzzer_Mode K_KickSensorStart_Buzzer_Mode = Mode_Idle;
const tD_Buzzer_Priority K_KickSensorStart_Buzzer_Priority = Priority_0;
const tD_Buzzer_Repetition K_KickSensorStart_Buzzer_Repetition = Repetition_0;

const tD_Buzzer_Mode K_KickSensorStop_Buzzer_Mode = Mode_Idle;
const tD_Buzzer_Priority K_KickSensorStop_Buzzer_Priority = Priority_0;
const tD_Buzzer_Repetition K_KickSensorStop_Buzzer_Repetition = Repetition_0;

const tD_Buzzer_Mode K_Obstacle_Buzzer_Mode = Mode_1;
const tD_Buzzer_Priority K_Obstacle_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_Obstacle_Buzzer_Repetition = Repetition_3;

const tD_Buzzer_Mode K_SpeedStop_Buzzer_Mode = Mode_Idle;
const tD_Buzzer_Priority K_SpeedStop_Buzzer_Priority = Priority_0;
const tD_Buzzer_Repetition K_SpeedStop_Buzzer_Repetition = Repetition_0;

const tD_Buzzer_Mode K_SoftStop_Buzzer_Mode = Mode_Idle;
const tD_Buzzer_Priority K_SoftStop_Buzzer_Priority = Priority_0;
const tD_Buzzer_Repetition K_SoftStop_Buzzer_Repetition = Repetition_0;

const tD_Buzzer_Mode K_StopDirectly_Buzzer_Mode = Mode_Idle;
const tD_Buzzer_Priority K_StopDirectly_Buzzer_Priority = Priority_0;
const tD_Buzzer_Repetition K_StopDirectly_Buzzer_Repetition = Repetition_0;

const tD_Buzzer_Mode K_GarageModeChange_Buzzer_Mode = Mode_Idle;
const tD_Buzzer_Priority K_GarageModeChange_Buzzer_Priority = Priority_0;
const tD_Buzzer_Repetition K_GarageModeChange_Buzzer_Repetition = Repetition_0;

const tD_Buzzer_Mode K_DelayClose_Buzzer_Mode = Mode_Idle;
const tD_Buzzer_Priority K_DelayClose_Buzzer_Priority = Priority_0;
const tD_Buzzer_Repetition K_DelayClose_Buzzer_Repetition = Repetition_0;

const tD_Flasher_Mode K_DelayClose_Flasher_Mode = Mode_Idle;
const tD_Flasher_Priority K_DelayClose_Flasher_Priority = Priority_0;
const tD_Flasher_Repetition K_DelayClose_Flasher_Repetition = Repetition_0;

const tD_Flasher_Mode K_Latch_Flasher_Mode = Flasher_Mode_Idle;
const tD_Flasher_Priority K_Latch_Flasher_Priority = Flasher_Priority_0;
const tD_Flasher_Repetition K_Latch_Flasher_Repetition = Flasher_Repetition_0;

const tD_Flasher_Mode K_ReleaseOnly_Flasher_Mode = Flasher_Mode_Idle;
const tD_Flasher_Priority K_ReleaseOnly_Flasher_Priority = Flasher_Priority_0;
const tD_Flasher_Repetition K_ReleaseOnly_Flasher_Repetition = Flasher_Repetition_0;

const tD_Flasher_Mode K_GarageModeChange_Flasher_Mode = Flasher_Mode_Idle;
const tD_Flasher_Priority K_GarageModeChange_Flasher_Priority = Flasher_Priority_0;
const tD_Flasher_Repetition K_GarageModeChange_Flasher_Repetition = Flasher_Repetition_0;

const tD_Flasher_Mode K_PowerOpen_Flasher_Mode = Flasher_Mode_1;
const tD_Flasher_Priority K_PowerOpen_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_PowerOpen_Flasher_Repetition = Flasher_Repetition_2;

const tD_Flasher_Mode K_PowerClose_Flasher_Mode = Flasher_Mode_1;
const tD_Flasher_Priority K_PowerClose_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_PowerClose_Flasher_Repetition = Flasher_Repetition_2;

const tD_Flasher_Mode K_Fault_Flasher_Mode = Flasher_Mode_1;
const tD_Flasher_Priority K_Fault_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_Fault_Flasher_Repetition = Flasher_Repetition_10;

const tD_Flasher_Mode K_PreCondition_Flasher_Mode = Flasher_Mode_2;
const tD_Flasher_Priority K_PreCondition_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_PreCondition_Flasher_Repetition = Flasher_Repetition_3;

const tD_Flasher_Mode K_Brake_Flasher_Mode = Flasher_Mode_Idle;
const tD_Flasher_Priority K_Brake_Flasher_Priority = Flasher_Priority_0;
const tD_Flasher_Repetition K_Brake_Flasher_Repetition = Flasher_Repetition_0;

const tD_Flasher_Mode K_SpeedStop_Flasher_Mode = Flasher_Mode_Idle;
const tD_Flasher_Priority K_SpeedStop_Flasher_Priority = Flasher_Priority_0;
const tD_Flasher_Repetition K_SpeedStop_Flasher_Repetition = Flasher_Repetition_0;

const tD_Flasher_Mode K_SoftStop_Flasher_Mode = Flasher_Mode_Idle;
const tD_Flasher_Priority K_SoftStop_Flasher_Priority = Flasher_Priority_0;
const tD_Flasher_Repetition K_SoftStop_Flasher_Repetition = Flasher_Repetition_0;

const tD_Flasher_Mode K_StopDirectly_Flasher_Mode = Flasher_Mode_Idle;
const tD_Flasher_Priority K_StopDirectly_Flasher_Priority = Flasher_Priority_0;
const tD_Flasher_Repetition K_StopDirectly_Flasher_Repetition = Flasher_Repetition_0;

const tD_Flasher_Mode K_Learn_Flasher_Mode = Flasher_Mode_3;
const tD_Flasher_Priority K_Learn_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_Learn_Flasher_Repetition = Flasher_Repetition_1;

const tD_Flasher_Mode K_Obstacle_Flasher_Mode = Flasher_Mode_1;
const tD_Flasher_Priority K_Obstacle_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_Obstacle_Flasher_Repetition = Flasher_Repetition_3;

const tD_Flasher_Mode K_LearnFailure_Flasher_Mode = Flasher_Mode_Idle;
const tD_Flasher_Priority K_LearnFailure_Flasher_Priority = Flasher_Priority_0;
const tD_Flasher_Repetition K_LearnFailure_Flasher_Repetition = Flasher_Repetition_0;
#endif

#ifdef _OPERATION_CHIME_DFMC_TIMES
const uint16_t K_Mode_0_Speaker_Break_Time = 50U;
const uint16_t K_Mode_1_Speaker_Break_Time = 20U;  /* 30 x 10ms */
const uint16_t K_Mode_2_Speaker_Break_Time = 10U;  /* 20 x 10ms */
const uint16_t K_Mode_3_Speaker_Break_Time = 50U;  /* 50 x 10ms */
const uint16_t K_Mode_4_Speaker_Break_Time = 50U;  /* 50 x 10ms */
const uint16_t K_Mode_5_Speaker_Break_Time = 6U;  /* 50 x 10ms */
const uint16_t K_Mode_6_Speaker_Break_Time = 80U;  /* 50 x 10ms */

const tD_Buzzer_Mode K_PowerOpen_Buzzer_Mode = Mode_1;
const tD_Buzzer_Priority K_PowerOpen_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_PowerOpen_Buzzer_Repetition = Repetition_2;

const tD_Buzzer_Mode K_PowerClose_Buzzer_Mode = Mode_1;
const tD_Buzzer_Priority K_PowerClose_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_PowerClose_Buzzer_Repetition = Repetition_2;

const tD_Buzzer_Mode K_ReleaseOnly_Buzzer_Mode = Mode_1;
const tD_Buzzer_Priority K_ReleaseOnly_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_ReleaseOnly_Buzzer_Repetition = Repetition_2;

const tD_Buzzer_Mode K_Fault_Buzzer_Mode = Mode_2;
const tD_Buzzer_Priority K_Fault_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_Fault_Buzzer_Repetition = Repetition_3;

const tD_Buzzer_Mode K_PreCondition_Buzzer_Mode = Mode_2;
const tD_Buzzer_Priority K_PreCondition_Buzzer_Priority = Priority_0;
const tD_Buzzer_Repetition K_PreCondition_Buzzer_Repetition = Repetition_3;

const tD_Buzzer_Mode K_Learn_Buzzer_Mode = Mode_3;
const tD_Buzzer_Priority K_Learn_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_Learn_Buzzer_Repetition = Repetition_1;

const tD_Buzzer_Mode K_LearnFailure_Buzzer_Mode = Mode_Idle;
const tD_Buzzer_Priority K_LearnFailure_Buzzer_Priority = Priority_0;
const tD_Buzzer_Repetition K_LearnFailure_Buzzer_Repetition = Repetition_0;

const tD_Buzzer_Mode K_Brake_Buzzer_Mode = Mode_4;
const tD_Buzzer_Priority K_Brake_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_Brake_Buzzer_Repetition = Repetition_1;

const tD_Buzzer_Mode K_KickSensorStart_Buzzer_Mode = Mode_1;
const tD_Buzzer_Priority K_KickSensorStart_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_KickSensorStart_Buzzer_Repetition = Repetition_2;

const tD_Buzzer_Mode K_KickSensorStop_Buzzer_Mode = Mode_1;
const tD_Buzzer_Priority K_KickSensorStop_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_KickSensorStop_Buzzer_Repetition = Repetition_2;

const tD_Buzzer_Mode K_Obstacle_Buzzer_Mode = Mode_2;
const tD_Buzzer_Priority K_Obstacle_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_Obstacle_Buzzer_Repetition = Repetition_3;

const tD_Buzzer_Mode K_SpeedStop_Buzzer_Mode = Mode_5;
const tD_Buzzer_Priority K_SpeedStop_Buzzer_Priority = Priority_2;
const tD_Buzzer_Repetition K_SpeedStop_Buzzer_Repetition = Repetition_400;

#ifdef _CHIME_IF_RECEIVE_STOP_COMMAND
const tD_Buzzer_Mode K_SoftStop_Buzzer_Mode = Mode_1;
const tD_Buzzer_Priority K_SoftStop_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_SoftStop_Buzzer_Repetition = Repetition_2;
#else
const tD_Buzzer_Mode K_SoftStop_Buzzer_Mode = Mode_Idle;
const tD_Buzzer_Priority K_SoftStop_Buzzer_Priority = Priority_0;
const tD_Buzzer_Repetition K_SoftStop_Buzzer_Repetition = Repetition_0;
#endif

const tD_Buzzer_Mode K_StopDirectly_Buzzer_Mode = Mode_4;
const tD_Buzzer_Priority K_StopDirectly_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_StopDirectly_Buzzer_Repetition = Repetition_1;

const tD_Buzzer_Mode K_GarageModeChange_Buzzer_Mode = Mode_3;
const tD_Buzzer_Priority K_GarageModeChange_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_GarageModeChange_Buzzer_Repetition = Repetition_1;

const tD_Buzzer_Mode K_DelayClose_Buzzer_Mode = Mode_1;
const tD_Buzzer_Priority K_DelayClose_Buzzer_Priority = Priority_1;
const tD_Buzzer_Repetition K_DelayClose_Buzzer_Repetition = Repetition_20;

const tD_Flasher_Mode K_DelayClose_Flasher_Mode = Flasher_Mode_4;
const tD_Flasher_Priority K_DelayClose_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_DelayClose_Flasher_Repetition = Flasher_Repetition_3;

const tD_Flasher_Mode K_Latch_Flasher_Mode = Flasher_Mode_1;
const tD_Flasher_Priority K_Latch_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_Latch_Flasher_Repetition = Flasher_Repetition_1;

const tD_Flasher_Mode K_ReleaseOnly_Flasher_Mode = Flasher_Mode_1;
const tD_Flasher_Priority K_ReleaseOnly_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_ReleaseOnly_Flasher_Repetition = Flasher_Repetition_2;

const tD_Flasher_Mode K_GarageModeChange_Flasher_Mode = Flasher_Mode_2;
const tD_Flasher_Priority K_GarageModeChange_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_GarageModeChange_Flasher_Repetition = Flasher_Repetition_2;

const tD_Flasher_Mode K_PowerOpen_Flasher_Mode = Flasher_Mode_1;
const tD_Flasher_Priority K_PowerOpen_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_PowerOpen_Flasher_Repetition = Flasher_Repetition_2;

const tD_Flasher_Mode K_PowerClose_Flasher_Mode = Flasher_Mode_1;
const tD_Flasher_Priority K_PowerClose_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_PowerClose_Flasher_Repetition = Flasher_Repetition_2;

const tD_Flasher_Mode K_Fault_Flasher_Mode = Flasher_Mode_2;
const tD_Flasher_Priority K_Fault_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_Fault_Flasher_Repetition = Flasher_Repetition_3;

const tD_Flasher_Mode K_PreCondition_Flasher_Mode = Flasher_Mode_2;
const tD_Flasher_Priority K_PreCondition_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_PreCondition_Flasher_Repetition = Flasher_Repetition_3;

const tD_Flasher_Mode K_Brake_Flasher_Mode = Flasher_Mode_4;
const tD_Flasher_Priority K_Brake_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_Brake_Flasher_Repetition = Flasher_Repetition_1;

const tD_Flasher_Mode K_SpeedStop_Flasher_Mode = Flasher_Mode_5;
const tD_Flasher_Priority K_SpeedStop_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_SpeedStop_Flasher_Repetition = Flasher_Repetition_1;

const tD_Flasher_Mode K_SoftStop_Flasher_Mode = Flasher_Mode_1;
const tD_Flasher_Priority K_SoftStop_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_SoftStop_Flasher_Repetition = Flasher_Repetition_2;

const tD_Flasher_Mode K_StopDirectly_Flasher_Mode = Flasher_Mode_4;
const tD_Flasher_Priority K_StopDirectly_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_StopDirectly_Flasher_Repetition = Flasher_Repetition_1;

const tD_Flasher_Mode K_Learn_Flasher_Mode = Flasher_Mode_3;
const tD_Flasher_Priority K_Learn_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_Learn_Flasher_Repetition = Flasher_Repetition_1;

const tD_Flasher_Mode K_Obstacle_Flasher_Mode = Flasher_Mode_3;
const tD_Flasher_Priority K_Obstacle_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_Obstacle_Flasher_Repetition = Flasher_Repetition_3;

const tD_Flasher_Mode K_LearnFailure_Flasher_Mode = Flasher_Mode_3;
const tD_Flasher_Priority K_LearnFailure_Flasher_Priority = Flasher_Priority_1;
const tD_Flasher_Repetition K_LearnFailure_Flasher_Repetition = Flasher_Repetition_2;
#endif




/*********************************************************************************************
**    Telltals Control
*********************************************************************************************/

/*********************************************************************************************
**    sleep_manage
*********************************************************************************************/
#ifdef _CHERY_COM
#ifdef _CHERY_COM_PLG
const uint16_t K_WakeupMiniTime_Time = 100U; /* 10ms x 10 */
const uint16_t K_ReadyToSleep_InClose_Delay_Time = 500U; /* 10ms x 10 */
const uint16_t K_ReadyToSleep_InOpen_Delay_Time = 500U; /* 10ms x 10 */
#endif
#ifdef _CHERY_COM_PD
const uint16_t K_WakeupMiniTime_Time = 100U; /* 10ms x 10 */
const uint16_t K_ReadyToSleep_InClose_Delay_Time = 10U; /* 10ms x 10 */
const uint16_t K_ReadyToSleep_InOpen_Delay_Time = 10U; /* 10ms x 10 */
#endif

#ifdef _CONFIG_Gen1_Board
const uint16_t K_DataUpdateBeforeSleep_Time = 20U; /* 10ms x 10 */
#endif
#ifdef _CONFIG_Gen2_Board
const uint16_t K_DataUpdateBeforeSleep_Time = 2U; /* 10ms x 10 */
#endif
#ifdef _CONFIG_Gen3_Board
const uint16_t K_DataUpdateBeforeSleep_Time = 2U; /* 10ms x 10 */
#endif
#ifdef _CONFIG_Gen4_Board
const uint16_t K_DataUpdateBeforeSleep_Time = 2U; /* 10ms x 10 */
#endif
const uint16_t K_SleepInOpen_LongTime_Time = 900U; /* 1s x  *//*_CHERY_Fixture_Test*/
#endif


#ifdef _VOYAH_COM
#ifdef _VOYAH_COM_PLG
const uint16_t K_WakeupMiniTime_Time = 100U; /* 10ms x 10 */
const uint16_t K_ReadyToSleep_InClose_Delay_Time = 500U; /* 10ms x 10 */
const uint16_t K_ReadyToSleep_InOpen_Delay_Time = 500U; /* 10ms x 10 */
#endif
#ifdef _VOYAH_COM_PD
const uint16_t K_WakeupMiniTime_Time = 100U; /* 10ms x 10 */
const uint16_t K_ReadyToSleep_InClose_Delay_Time = 10U; /* 10ms x 10 */
const uint16_t K_ReadyToSleep_InOpen_Delay_Time = 10U; /* 10ms x 10 */
#endif

#ifdef _CONFIG_Gen1_Board
const uint16_t K_DataUpdateBeforeSleep_Time = 20U; /* 10ms x 10 */
#endif
#ifdef _CONFIG_Gen2_Board
const uint16_t K_DataUpdateBeforeSleep_Time = 2U; /* 10ms x 10 */
#endif
#ifdef _CONFIG_Gen3_Board
const uint16_t K_DataUpdateBeforeSleep_Time = 2U; /* 10ms x 10 */
#endif
#ifdef _CONFIG_Gen4_Board
const uint16_t K_DataUpdateBeforeSleep_Time = 2U; /* 10ms x 10 */
#endif
const uint16_t K_SleepInOpen_LongTime_Time = 900U; /* 1s x  *//*_CHERY_Fixture_Test*/
#endif


#ifdef _AUDI_COM
#ifdef _AUDI_COM_PLG
const uint16_t K_WakeupMiniTime_Time = 100U; /* 10ms x 10 */
const uint16_t K_ReadyToSleep_InClose_Delay_Time = 500U; /* 10ms x 10 */
const uint16_t K_ReadyToSleep_InOpen_Delay_Time = 500U; /* 10ms x 10 */
#endif
#ifdef _AUDI_COM_PD
const uint16_t K_WakeupMiniTime_Time = 100U; /* 10ms x 10 */
const uint16_t K_ReadyToSleep_InClose_Delay_Time = 10U; /* 10ms x 10 */
const uint16_t K_ReadyToSleep_InOpen_Delay_Time = 10U; /* 10ms x 10 */
#endif

#ifdef _CONFIG_Gen1_Board
const uint16_t K_DataUpdateBeforeSleep_Time = 20U; /* 10ms x 10 */
#endif
#ifdef _CONFIG_Gen2_Board
const uint16_t K_DataUpdateBeforeSleep_Time = 2U; /* 10ms x 10 */
#endif
#ifdef _CONFIG_Gen3_Board
const uint16_t K_DataUpdateBeforeSleep_Time = 2U; /* 10ms x 10 */
#endif
#ifdef _CONFIG_Gen4_Board
const uint16_t K_DataUpdateBeforeSleep_Time = 2U; /* 10ms x 10 */
#endif
const uint16_t K_SleepInOpen_LongTime_Time = 900U; /* 1s x  *//*_AUDI_Fixture_Test*/
#endif


#ifdef _SGMW_COM
const uint16_t K_WakeupMiniTime_Time = 100U; /* 10ms x 10 */
const uint16_t K_ReadyToSleep_InClose_Delay_Time = 460U; /* 10ms x 10 */
const uint16_t K_ReadyToSleep_InOpen_Delay_Time = 460U; /* 10ms x 10 */
#ifdef _CONFIG_Gen1_Board
const uint16_t K_DataUpdateBeforeSleep_Time = 20U; /* 10ms x 10 */
#endif
#ifdef _CONFIG_Gen2_Board
const uint16_t K_DataUpdateBeforeSleep_Time = 2U; /* 10ms x 10 */
#endif
#ifdef _CONFIG_Gen3_Board
const uint16_t K_DataUpdateBeforeSleep_Time = 2U; /* 10ms x 10 */
#endif
#ifdef _CONFIG_Gen4_Board
const uint16_t K_DataUpdateBeforeSleep_Time = 2U; /* 10ms x 10 */
#endif
const uint16_t K_SleepInOpen_LongTime_Time = 0U; /* 1s x  */
#endif

#ifdef _SGM_COM
const uint16_t K_WakeupMiniTime_Time = 100U; /* 10ms x 10 */
const uint16_t K_ReadyToSleep_InClose_Delay_Time = 460U; /* 10ms x 10 */
const uint16_t K_ReadyToSleep_InOpen_Delay_Time = 460U; /* 10ms x 10 */
#ifdef _CONFIG_Gen1_Board
const uint16_t K_DataUpdateBeforeSleep_Time = 20U; /* 10ms x 10 */
#endif
#ifdef _CONFIG_Gen2_Board
const uint16_t K_DataUpdateBeforeSleep_Time = 2U; /* 10ms x 10 */
#endif
#ifdef _CONFIG_Gen3_Board
const uint16_t K_DataUpdateBeforeSleep_Time = 2U; /* 10ms x 10 */
#endif
#ifdef _CONFIG_Gen4_Board
const uint16_t K_DataUpdateBeforeSleep_Time = 2U; /* 10ms x 10 */
#endif
const uint16_t K_SleepInOpen_LongTime_Time = 0U; /* 1s x  */
#endif

#ifdef _CTCS_COM
const uint16_t K_WakeupMiniTime_Time = 100U; /* 10ms x 10 */
const uint16_t K_ReadyToSleep_InClose_Delay_Time = 500U; /* 10ms x 10 */
const uint16_t K_ReadyToSleep_InOpen_Delay_Time = 500U; /* 10ms x 10 */
#ifdef _CONFIG_Gen1_Board
const uint16_t K_DataUpdateBeforeSleep_Time = 20U; /* 10ms x 10 */
#endif
#ifdef _CONFIG_Gen2_Board
const uint16_t K_DataUpdateBeforeSleep_Time = 2U; /* 10ms x 10 */
#endif
#ifdef _CONFIG_Gen3_Board
const uint16_t K_DataUpdateBeforeSleep_Time = 2U; /* 10ms x 10 */
#endif
#ifdef _CONFIG_Gen4_Board
const uint16_t K_DataUpdateBeforeSleep_Time = 2U; /* 10ms x 10 */
#endif
const uint16_t K_SleepInOpen_LongTime_Time = 3600U; /* 1s x  */
#endif

#ifdef _MAXUS_COM
const uint16_t K_WakeupMiniTime_Time = 100U; /* 10ms x 10 */
const uint16_t K_ReadyToSleep_InClose_Delay_Time = 10U; /* 10ms x 10 */
const uint16_t K_ReadyToSleep_InOpen_Delay_Time = 10U; /* 10ms x 10 */
#ifdef _CONFIG_Gen1_Board
const uint16_t K_DataUpdateBeforeSleep_Time = 20U; /* 10ms x 10 */
#endif
#ifdef _CONFIG_Gen2_Board
const uint16_t K_DataUpdateBeforeSleep_Time = 2U; /* 10ms x 10 */
#endif
#ifdef _CONFIG_Gen3_Board
const uint16_t K_DataUpdateBeforeSleep_Time = 2U; /* 10ms x 10 */
#endif
#ifdef _CONFIG_Gen4_Board
const uint16_t K_DataUpdateBeforeSleep_Time = 2U; /* 10ms x 10 */
#endif
const uint16_t K_SleepInOpen_LongTime_Time = 600U; /* 1s x  */
#endif

#ifdef _DFMC_COM
const uint16_t K_WakeupMiniTime_Time = 100U; /* 10ms x 10 */
const uint16_t K_ReadyToSleep_InClose_Delay_Time = 500U; /* 10ms x 10 */
const uint16_t K_ReadyToSleep_InOpen_Delay_Time = 10U; /* 10ms x 10 */
#ifdef _CONFIG_Gen1_Board
const uint16_t K_DataUpdateBeforeSleep_Time = 20U; /* 10ms x 10 */
#endif
#ifdef _CONFIG_Gen2_Board
const uint16_t K_DataUpdateBeforeSleep_Time = 2U; /* 10ms x 10 */
#endif
#ifdef _CONFIG_Gen3_Board
const uint16_t K_DataUpdateBeforeSleep_Time = 2U; /* 10ms x 10 */
#endif
#ifdef _CONFIG_Gen4_Board
const uint16_t K_DataUpdateBeforeSleep_Time = 2U; /* 10ms x 10 */
#endif
const uint16_t K_SleepInOpen_LongTime_Time = 600U; /* 1s x  */
#endif

#ifdef _BAIC_COM
const uint16_t K_WakeupMiniTime_Time = 100U; /* 10ms x 10 */
const uint16_t K_ReadyToSleep_InClose_Delay_Time = 10U; /* 10ms x 10 */
const uint16_t K_ReadyToSleep_InOpen_Delay_Time = 10U; /* 10ms x 10 */
#ifdef _CONFIG_Gen1_Board
const uint16_t K_DataUpdateBeforeSleep_Time = 20U; /* 10ms x 10 */
#endif
#ifdef _CONFIG_Gen2_Board
const uint16_t K_DataUpdateBeforeSleep_Time = 2U; /* 10ms x 10 */
#endif
#ifdef _CONFIG_Gen3_Board
const uint16_t K_DataUpdateBeforeSleep_Time = 2U; /* 10ms x 10 */
#endif
#ifdef _CONFIG_Gen4_Board
const uint16_t K_DataUpdateBeforeSleep_Time = 2U; /* 10ms x 10 */
#endif
const uint16_t K_SleepInOpen_LongTime_Time = 600U; //10U;///* 1s x  *//*BAIC_Fixture_Test*/
#endif

#ifdef _DFLZM_COM
const uint16_t K_WakeupMiniTime_Time = 100U; /* 10ms x 10 */
const uint16_t K_ReadyToSleep_InClose_Delay_Time = 10U; /* 10ms x 10 */
const uint16_t K_ReadyToSleep_InOpen_Delay_Time = 10U; /* 10ms x 10 */
#ifdef _CONFIG_Gen1_Board
const uint16_t K_DataUpdateBeforeSleep_Time = 20U; /* 10ms x 10 */
#endif
#ifdef _CONFIG_Gen2_Board
const uint16_t K_DataUpdateBeforeSleep_Time = 2U; /* 10ms x 10 */
#endif
#ifdef _CONFIG_Gen3_Board
const uint16_t K_DataUpdateBeforeSleep_Time = 2U; /* 10ms x 10 */
#endif
#ifdef _CONFIG_Gen4_Board
const uint16_t K_DataUpdateBeforeSleep_Time = 2U; /* 10ms x 10 */
#endif
const uint16_t K_SleepInOpen_LongTime_Time = 600U; //10U;///* 1s x  *//*BAIC_Fixture_Test*/
#endif

#ifdef _NIU_COM
const uint16_t K_WakeupMiniTime_Time = 100U; /* 10ms x 10 */
const uint16_t K_ReadyToSleep_InClose_Delay_Time = 10U; /* 10ms x 10 */
const uint16_t K_ReadyToSleep_InOpen_Delay_Time = 10U; /* 10ms x 10 */
#ifdef _CONFIG_Gen1_Board
const uint16_t K_DataUpdateBeforeSleep_Time = 20U; /* 10ms x 10 */
#endif
#ifdef _CONFIG_Gen2_Board
const uint16_t K_DataUpdateBeforeSleep_Time = 2U; /* 10ms x 10 */
#endif
#ifdef _CONFIG_Gen3_Board
const uint16_t K_DataUpdateBeforeSleep_Time = 2U; /* 10ms x 10 */
#endif
#ifdef _CONFIG_Gen4_Board
const uint16_t K_DataUpdateBeforeSleep_Time = 2U; /* 10ms x 10 */
#endif
const uint16_t K_SleepInOpen_LongTime_Time = 600U; /* 1s x  */
#endif

#ifdef _FAW_COM
const uint16_t K_WakeupMiniTime_Time = 100U; /* 10ms x 10 */
const uint16_t K_ReadyToSleep_InClose_Delay_Time = 0U; /* 10ms x 10 */
const uint16_t K_ReadyToSleep_InOpen_Delay_Time = 0U; /* 10ms x 10 */
#ifdef _CONFIG_Gen1_Board
const uint16_t K_DataUpdateBeforeSleep_Time = 20U; /* 10ms x 10 */
#endif
#ifdef _CONFIG_Gen2_Board
const uint16_t K_DataUpdateBeforeSleep_Time = 2U; /* 10ms x 10 */
#endif
#ifdef _CONFIG_Gen3_Board
const uint16_t K_DataUpdateBeforeSleep_Time = 2U; /* 10ms x 10 */
#endif
#ifdef _CONFIG_Gen4_Board
const uint16_t K_DataUpdateBeforeSleep_Time = 2U; /* 10ms x 10 */
#endif
const uint16_t K_SleepInOpen_LongTime_Time = 1800U; /* 1s x  */
#endif
#ifdef _DEARCC_COM
const uint16_t K_WakeupMiniTime_Time = 100U; /* 10ms x 10 */
const uint16_t K_ReadyToSleep_InClose_Delay_Time = 50U; /* 10ms x 10 */
const uint16_t K_ReadyToSleep_InOpen_Delay_Time = 50U; /* 10ms x 10 */
#ifdef _CONFIG_Gen1_Board
const uint16_t K_DataUpdateBeforeSleep_Time = 20U; /* 10ms x 10 */
#endif
#ifdef _CONFIG_Gen2_Board
const uint16_t K_DataUpdateBeforeSleep_Time = 2U; /* 10ms x 10 */
#endif
#ifdef _CONFIG_Gen3_Board
const uint16_t K_DataUpdateBeforeSleep_Time = 2U; /* 10ms x 10 */
#endif
#ifdef _CONFIG_Gen4_Board
const uint16_t K_DataUpdateBeforeSleep_Time = 2U; /* 10ms x 10 */
#endif
const uint16_t K_SleepInOpen_LongTime_Time = 0;//900U; /* 1s x  */
#endif
#ifdef _XIAOPENG_COM
const uint16_t K_WakeupMiniTime_Time = 100U; /* 10ms x 10 */
const uint16_t K_ReadyToSleep_InClose_Delay_Time = 0U; /* 10ms x 10 */
const uint16_t K_ReadyToSleep_InOpen_Delay_Time = 0U; /* 10ms x 10 */
#ifdef _CONFIG_Gen1_Board
const uint16_t K_DataUpdateBeforeSleep_Time = 20U; /* 10ms x 10 */
#endif
#ifdef _CONFIG_Gen2_Board
const uint16_t K_DataUpdateBeforeSleep_Time = 2U; /* 10ms x 10 */
#endif
#ifdef _CONFIG_Gen3_Board
const uint16_t K_DataUpdateBeforeSleep_Time = 2U; /* 10ms x 10 */
#endif
#ifdef _CONFIG_Gen4_Board
const uint16_t K_DataUpdateBeforeSleep_Time = 2U; /* 10ms x 10 */
#endif
const uint16_t K_SleepInOpen_LongTime_Time = 0;//900U; /* 1s x  */
#endif
#ifdef _CHANGAN_COM
const uint16_t K_WakeupMiniTime_Time = 100U; /* 10ms x 10 */
const uint16_t K_ReadyToSleep_InClose_Delay_Time = 500U; /* 10ms x 10 */
const uint16_t K_ReadyToSleep_InOpen_Delay_Time = 500U; /* 10ms x 10 */
#ifdef _CONFIG_Gen1_Board
const uint16_t K_DataUpdateBeforeSleep_Time = 20U; /* 10ms x 10 */
#endif
#ifdef _CONFIG_Gen2_Board
const uint16_t K_DataUpdateBeforeSleep_Time = 2U; /* 10ms x 10 */
#endif
#ifdef _CONFIG_Gen3_Board
const uint16_t K_DataUpdateBeforeSleep_Time = 2U; /* 10ms x 10 */
#endif
#ifdef _CONFIG_Gen4_Board
const uint16_t K_DataUpdateBeforeSleep_Time = 2U; /* 10ms x 10 */
#endif
const uint16_t K_SleepInOpen_LongTime_Time = 3600U; /* 1s x  */
#endif

/*********************************************************************************************
**    ecu_fft_test
*********************************************************************************************/
const uint16_t K_FFT_Motor1_Current_Calibrate1_Duty = 100U;
const uint16_t K_FFT_Motor2_Current_Calibrate1_Duty = 100U;
const uint16_t K_FFT_CinchMotor_Current_Calibrate1_Duty = 100U;
const uint16_t K_FFT_ReleaseMotor_Current_Calibrate1_Duty = 100U;

const uint16_t K_FFT_Motor1_Current_Calibrate2_Duty = 100U;
const uint16_t K_FFT_Motor2_Current_Calibrate2_Duty = 100U;
const uint16_t K_FFT_CinchMotor_Current_Calibrate2_Duty = 100U;
const uint16_t K_FFT_ReleaseMotor_Current_Calibrate2_Duty = 100U;

#if defined(_CONFIG_Gen1_Board) || defined(_CONFIG_Gen2_Board)
const uint16_t K_Motor1_Current_Calibrate_Time = 5U;   /* 100ms x 5 */
const uint16_t K_Motor2_Current_Calibrate_Time = 5U;   /* 100ms x 5 */
const uint16_t K_CinchMotor_Current_Calibrate_Time = 5U;   /* 100ms x 5 */
const uint16_t K_ReleaseMotor_Current_Calibrate_Time = 5U;   /* 100ms x 5 */
#endif
#if defined(_CONFIG_Gen3_Board) || defined(_CONFIG_Gen4_Board)
const uint16_t K_Motor1_Current_Calibrate_Time = 10U;//5U;   /* 100ms x 5 */
const uint16_t K_Motor2_Current_Calibrate_Time = 10U;//5U;;   /* 100ms x 5 */
const uint16_t K_CinchMotor_Current_Calibrate_Time = 10U;//5U;   /* 100ms x 5 */
const uint16_t K_ReleaseMotor_Current_Calibrate_Time = 10U;//5U;   /* 100ms x 5 */
#endif

const uint16_t K_Motor1_Calibrate_Sampling_Size = 5U;
const uint16_t K_Motor2_Calibrate_Sampling_Size = 5U;    
const uint16_t K_CinchMotor_Calibrate_Sampling_Size = 5U;
const uint16_t K_ReleaseMotor_Calibrate_Sampling_Size = 5U;  

const uint16_t K_Motor1_Current_Calibrate_Timeout = 50U;//100U;   /* 100ms x 5 */
const uint16_t K_Motor2_Current_Calibrate_Timeout = 50U;//100U;   /* 100ms x 5 */
const uint16_t K_CinchMotor_Current_Calibrate_Timeout = 50U;//100U;   /* 100ms x 5 */
const uint16_t K_ReleaseMotor_Current_Calibrate_Timeout = 100U;   /* 100ms x 5 */

const uint16_t K_Motor1_Current_Real_Calibrate1_Value = 1000U;  /* 10A - 5A */
const uint16_t K_Motor2_Current_Real_Calibrate1_Value = 1000U;  /* 10A - 5A */
const uint16_t K_CinchMotor_Current_Real_Calibrate1_Value = 400U;  /* 4A - 2A */
const uint16_t K_ReleaseMotor_Current_Real_Calibrate1_Value = 300U;  /* 3A - 1A */

#ifdef _10A_5A_CALIBRATE
const uint16_t K_Motor1_Current_Real_Calibrate2_Value = 500U;  /* 10A - 5A */
const uint16_t K_Motor2_Current_Real_Calibrate2_Value = 500U;  /* 10A - 5A */
const uint16_t K_CinchMotor_Current_Real_Calibrate2_Value = 200U;  /* 4A - 2A */
const uint16_t K_ReleaseMotor_Current_Real_Calibrate2_Value = 100U;  /* 3A - 1A */
const uint16_t K_Motor4_Current_Real_Calibrate2_Value = 500U;  /* 10A - 5A */
#endif

#ifdef _10A_0A_CALIBRATE
const uint16_t K_Motor1_Current_Real_Calibrate2_Value = 0U;  /* 10A - 0A */
const uint16_t K_Motor2_Current_Real_Calibrate2_Value = 0U;  /* 10A - 0A */
const uint16_t K_CinchMotor_Current_Real_Calibrate2_Value = 0U;  /* 4A - 0A */
const uint16_t K_ReleaseMotor_Current_Real_Calibrate2_Value = 0U;  /* 3A - 0A */
const uint16_t K_Motor4_Current_Real_Calibrate2_Value = 0U;  /* 10A - 0A */
#endif

#ifdef _CONFIG_Gen1_Board
const uint16_t K_Motor1_FET_Base_Offset_Calibrate_Compensation = 40U;/*0.1A*/
const uint16_t K_Motor1_FET_Cal_Ratio_Calibrate_Compensation = 2U;
const uint16_t K_Motor2_FET_Base_Offset_Calibrate_Compensation = 40U;/*0.1A*/
const uint16_t K_Motor2_FET_Cal_Ratio_Calibrate_Compensation = 2U;
const uint16_t K_CinchMotor_FET_Base_Offset_Calibrate_Compensation = 0U;/*0.1A*/
const uint16_t K_CinchMotor_FET_Cal_Ratio_Calibrate_Compensation = 2U;
const uint16_t K_ReleaseMotor_FET_Base_Offset_Calibrate_Compensation = 0U;/*0.1A*/
const uint16_t K_ReleaseMotor_FET_Cal_Ratio_Calibrate_Compensation = 2U;

const uint16_t K_Motor1_Current_Offset_Compensation_Limit = 100U;/*1A*/
const uint16_t K_Motor2_Current_Offset_Compensation_Limit = 100U;/*1A*/
const uint16_t K_CinchMotor_Current_Offset_Compensation_Limit = 100U;/*1A*/
const uint16_t K_ReleaseMotor_Current_Offset_Compensation_Limit = 100U;/*1A*/

#endif
#ifdef _CONFIG_Gen2_Board
const uint16_t K_Motor1_FET_Base_Offset_Calibrate_Compensation = 10U;/*0.02A*/
const uint16_t K_Motor1_FET_Cal_Ratio_Calibrate_Compensation = 2U;
const uint16_t K_Motor2_FET_Base_Offset_Calibrate_Compensation = 10U;/*0.02A*/
const uint16_t K_Motor2_FET_Cal_Ratio_Calibrate_Compensation = 2U;
const uint16_t K_CinchMotor_FET_Base_Offset_Calibrate_Compensation = 5U;/*0.02A*/
const uint16_t K_CinchMotor_FET_Cal_Ratio_Calibrate_Compensation = 2U;
const uint16_t K_ReleaseMotor_FET_Base_Offset_Calibrate_Compensation = 0U;/*0.02A*/
const uint16_t K_ReleaseMotor_FET_Cal_Ratio_Calibrate_Compensation = 2U;

const uint16_t K_Motor1_Current_Offset_Compensation_Limit = 100U;/*1A*/
const uint16_t K_Motor2_Current_Offset_Compensation_Limit = 100U;/*1A*/
const uint16_t K_CinchMotor_Current_Offset_Compensation_Limit = 100U;/*1A*/
const uint16_t K_ReleaseMotor_Current_Offset_Compensation_Limit = 100U;/*1A*/
#endif

#ifdef _CONFIG_Gen3_Board
#ifdef _CONFIG_Motor4
const uint16_t K_FFT_Motor4_Current_Calibrate1_Duty = 100U;
const uint16_t K_FFT_Motor4_Current_Calibrate2_Duty = 100U;
const uint16_t K_Motor4_Current_Calibrate_Time = 10U;//5U;   /* 100ms x 5 */
const uint16_t K_Motor4_Calibrate_Sampling_Size = 5U;
const uint16_t K_Motor4_Current_Calibrate_Timeout = 50U;//100U;   /* 100ms x 5 */
const uint16_t K_Motor4_Current_Real_Calibrate1_Value = 1000U;  /* 10A - 5A */
#endif

const uint16_t K_Motor1_FET_Base_Offset_Calibrate_Compensation = 10U;/*0.02A*/
const uint16_t K_Motor1_FET_Cal_Ratio_Calibrate_Compensation = 2U;
const uint16_t K_Motor2_FET_Base_Offset_Calibrate_Compensation = 10U;/*0.02A*/
const uint16_t K_Motor2_FET_Cal_Ratio_Calibrate_Compensation = 2U;
const uint16_t K_CinchMotor_FET_Base_Offset_Calibrate_Compensation = 5U;/*0.02A*/
const uint16_t K_CinchMotor_FET_Cal_Ratio_Calibrate_Compensation = 2U;
const uint16_t K_Motor4_FET_Base_Offset_Calibrate_Compensation = 10U;/*0.02A*/
const uint16_t K_Motor4_FET_Cal_Ratio_Calibrate_Compensation = 2U;
const uint16_t K_ReleaseMotor_FET_Base_Offset_Calibrate_Compensation = 0U;/*0.02A*/
const uint16_t K_ReleaseMotor_FET_Cal_Ratio_Calibrate_Compensation = 2U;

const uint16_t K_Motor1_Current_Offset_Compensation_Limit = 100U;/*1A*/
const uint16_t K_Motor2_Current_Offset_Compensation_Limit = 100U;/*1A*/
const uint16_t K_CinchMotor_Current_Offset_Compensation_Limit = 100U;/*1A*/
const uint16_t K_ReleaseMotor_Current_Offset_Compensation_Limit = 100U;/*1A*/
const uint16_t K_Motor4_Current_Offset_Compensation_Limit = 100U;/*1A*/
#endif
#ifdef _CONFIG_Gen4_Board
#ifdef _CONFIG_Motor4
const uint16_t K_FFT_Motor4_Current_Calibrate1_Duty = 100U;
const uint16_t K_FFT_Motor4_Current_Calibrate2_Duty = 100U;
const uint16_t K_Motor4_Current_Calibrate_Time = 10U;//5U;   /* 100ms x 5 */
const uint16_t K_Motor4_Calibrate_Sampling_Size = 5U;
const uint16_t K_Motor4_Current_Calibrate_Timeout = 50U;//100U;   /* 100ms x 5 */
const uint16_t K_Motor4_Current_Real_Calibrate1_Value = 1000U;  /* 10A - 5A */
#endif

const uint16_t K_Motor1_FET_Base_Offset_Calibrate_Compensation = 10U;/*0.02A*/
const uint16_t K_Motor1_FET_Cal_Ratio_Calibrate_Compensation = 2U;
const uint16_t K_Motor2_FET_Base_Offset_Calibrate_Compensation = 10U;/*0.02A*/
const uint16_t K_Motor2_FET_Cal_Ratio_Calibrate_Compensation = 2U;
const uint16_t K_CinchMotor_FET_Base_Offset_Calibrate_Compensation = 5U;/*0.02A*/
const uint16_t K_CinchMotor_FET_Cal_Ratio_Calibrate_Compensation = 2U;
const uint16_t K_Motor4_FET_Base_Offset_Calibrate_Compensation = 10U;/*0.02A*/
const uint16_t K_Motor4_FET_Cal_Ratio_Calibrate_Compensation = 2U;
const uint16_t K_ReleaseMotor_FET_Base_Offset_Calibrate_Compensation = 0U;/*0.02A*/
const uint16_t K_ReleaseMotor_FET_Cal_Ratio_Calibrate_Compensation = 2U;

const uint16_t K_Motor1_Current_Offset_Compensation_Limit = 100U;/*1A*/
const uint16_t K_Motor2_Current_Offset_Compensation_Limit = 100U;/*1A*/
const uint16_t K_CinchMotor_Current_Offset_Compensation_Limit = 100U;/*1A*/
const uint16_t K_ReleaseMotor_Current_Offset_Compensation_Limit = 100U;/*1A*/
const uint16_t K_Motor4_Current_Offset_Compensation_Limit = 100U;/*1A*/
#endif


/*********************************************************************************************
**    mgb_eol_test
*********************************************************************************************/
const uint16_t K_Motor1_MGB_Open_Duty = 40U;
const uint16_t K_Motor2_MGB_Open_Duty = 40U;

const uint16_t K_MGB_TestOpen_Time = 100U; /*10ms x */
const uint16_t K_MGB_TestPass_Time = 100U; /*10ms x */
const uint16_t K_MGB_TestFail_Time = 300U; /*10ms x */

const uint16_t K_MGB_Test_HallCount = 100U;

const uint16_t K_MGB_TestOpen_Current_Time = 70U; /*10ms x */
const uint16_t K_MGB_TestOpen_Current_Limit = 100U;




/*********************************************************************************************
**    did process
*********************************************************************************************/
const uint16_t K_CPID_Motor1_Open_Duty_Default = 50U;
const uint16_t K_CPID_Motor2_Open_Duty_Default = 50U;
const uint16_t K_CPID_CinchMotor_Cinch_Duty_Default = 50U;
const uint16_t K_CPID_ReleaseMotor_Release_Duty_Default = 50U;

const uint16_t K_CPID_Motor1_Close_Duty_Default = 50U;
const uint16_t K_CPID_Motor2_Close_Duty_Default = 50U;
const uint16_t K_CPID_CinchMotor_Netrual_Duty_Default = 50U;

const uint16_t K_CPID_SpindleMotor_Open_Timeout = 1000U; /*10ms x 50 */
const uint16_t K_CPID_SpindleMotor_Close_Timeout = 1000U; /*10ms x 50 */

const uint16_t K_CPID_CinchMotor_Cinch_Timeout = 1000U; /*10ms x 15 */
const uint16_t K_CPID_CinchMotor_Netrual_Timeout = 1000U; /*10ms x 15 */

const uint16_t K_CPID_ReleaseMotor_Release_Timeout = 1000U; /*10ms x 5 */
const uint16_t K_CPID_Buzzer_Work_Timeout = 1000U; /*10ms x 5 */

const uint16_t K_CPID_Clutch_Work_Timeout = 1000U; /*10ms x 5 */
const uint16_t K_CPID_Backlight_Work_Timeout = 1000U; /*10ms x 5 */
const uint16_t K_CPID_LSD_Work_Timeout = 1000U; /*10ms x 5 */

const uint16_t K_CPID_Motor1_FET_Calibrate_Time = 50U; /*10ms x 100*/
const uint16_t K_CPID_Motor1_FET_Calibrate_Timeout = 100U; /*10ms x 150*/

const uint16_t K_CPID_Motor2_FET_Calibrate_Time = 50U; /*10ms x 100*/
const uint16_t K_CPID_Motor2_FET_Calibrate_Timeout = 100U; /*10ms x 150*/

const uint16_t K_CPID_CinchMotor_FET_Calibrate_Time = 50U; /*10ms x 100*/
const uint16_t K_CPID_CinchMotor_FET_Calibrate_Timeout = 100U; /*10ms x 150*/

#ifdef _CONFIG_Motor4
const uint16_t K_CPID_Motor4_Open_Duty_Default = 50U;
const uint16_t K_CPID_Motor4_Close_Duty_Default = 50U;
const uint16_t K_CPID_Motor4_Open_Timeout = 1000U; /*10ms x 50 */
const uint16_t K_CPID_Motor4_Close_Timeout = 1000U; /*10ms x 50 */
const uint16_t K_CPID_Motor4_FET_Calibrate_Time = 50U; /*10ms x 100*/
const uint16_t K_CPID_Motor4_FET_Calibrate_Timeout = 100U; /*10ms x 150*/
#endif

#ifdef _10A_5A_CALIBRATE
#ifdef _CONFIG_Gen1_Board
const uint16_t K_CPID_Motor1_Current_Voltage_Value_Compensation = 40U; /* 10 = 0.1A */
const uint16_t K_CPID_Motor2_Current_Voltage_Value_Compensation = 40U; /* 10 = 0.1A */
const uint16_t K_CPID_CinchMotor_Current_Voltage_Value_Compensation = 0U; /* 10 = 0.1A */
#endif
#ifdef _CONFIG_Gen2_Board
const uint16_t K_CPID_Motor1_Current_Voltage_Value_Compensation = 5U; /* 10 = 0.1A */
const uint16_t K_CPID_Motor2_Current_Voltage_Value_Compensation = 5U; /* 10 = 0.1A */
const uint16_t K_CPID_CinchMotor_Current_Voltage_Value_Compensation = 5U; /* 10 = 0.1A */
#endif
#ifdef _CONFIG_Gen3_Board
const uint16_t K_CPID_Motor1_Current_Voltage_Value_Compensation = 5U; /* 10 = 0.1A */
const uint16_t K_CPID_Motor2_Current_Voltage_Value_Compensation = 5U; /* 10 = 0.1A */
const uint16_t K_CPID_CinchMotor_Current_Voltage_Value_Compensation = 5U; /* 10 = 0.1A */
const uint16_t K_CPID_Motor4_Current_Voltage_Value_Compensation = 5U; /* 10 = 0.1A */
#endif
#ifdef _CONFIG_Gen4_Board
const uint16_t K_CPID_Motor1_Current_Voltage_Value_Compensation = 5U; /* 10 = 0.1A */
const uint16_t K_CPID_Motor2_Current_Voltage_Value_Compensation = 5U; /* 10 = 0.1A */
const uint16_t K_CPID_CinchMotor_Current_Voltage_Value_Compensation = 5U; /* 10 = 0.1A */
const uint16_t K_CPID_Motor4_Current_Voltage_Value_Compensation = 5U; /* 10 = 0.1A */
#endif
#endif
#ifdef _10A_0A_CALIBRATE
const uint16_t K_CPID_Motor1_Current_Voltage_Value_Compensation = 2U; /* 10 = 0.1A */
const uint16_t K_CPID_Motor2_Current_Voltage_Value_Compensation = 2U; /* 10 = 0.1A */
const uint16_t K_CPID_CinchMotor_Current_Voltage_Value_Compensation = 2U; /* 10 = 0.1A */
const uint16_t K_CPID_Motor4_Current_Voltage_Value_Compensation = 2U; /* 10 = 0.1A */
#endif

const uint16_t K_IO_Motor1_Open_Duty_Default = 50U;
const uint16_t K_IO_Motor2_Open_Duty_Default = 50U;
const uint16_t K_IO_CinchMotor_Cinch_Duty_Default = 100U;
const uint16_t K_IO_ReleaseMotor_Release_Duty_Default = 100U;

const uint16_t K_IO_Motor1_Close_Duty_Default = 50U;
const uint16_t K_IO_Motor2_Close_Duty_Default = 50U;
const uint16_t K_IO_CinchMotor_Netrual_Duty_Default = 100U;

const uint16_t K_IO_SpindleMotor_Open_Timeout = 500U; /*10ms x */
const uint16_t K_IO_SpindleMotor_Close_Timeout = 500U; /*10ms x */

const uint16_t K_IO_CinchMotor_Cinch_Timeout = 500U; /*10ms x */
const uint16_t K_IO_CinchMotor_Netrual_Timeout = 500U; /*10ms x */
const uint16_t K_IO_ReleaseMotor_Release_Timeout = 300U; /*10ms x */

const uint16_t K_IO_Motor1_Open_Timeout = 500U; /*10ms x */
const uint16_t K_IO_Motor1_Close_Timeout = 500U; /*10ms x */
const uint16_t K_IO_Motor2_Open_Timeout = 500U; /*10ms x */
const uint16_t K_IO_Motor2_Close_Timeout = 500U; /*10ms x */

const uint16_t K_TriggerSignal_Timeout = 100U; /*10ms x */

const uint16_t K_CPIDInd_LearnPowerClose_Continue_Delay_Time = 150U;

/*********************************************************************************************
**    ecu_emc_test
*********************************************************************************************/
const uint16_t K_Motor1_EMC_Open_Duty = 100U;
const uint16_t K_Motor2_EMC_Open_Duty = 100U;
const uint16_t K_CinchMotor_EMC_Cinch_Duty = 100U;
const uint16_t K_ReleaseMotor_EMC_Release_Duty = 100U;

const uint16_t K_Motor1_EMC_Close_Duty = 100U;
const uint16_t K_Motor2_EMC_Close_Duty = 100U;
const uint16_t K_CinchMotor_EMC_Netrual_Duty = 100U;

#ifdef _CONFIG_Motor4
const uint16_t K_Motor4_EMC_Open_Duty = 100U;
const uint16_t K_Motor4_EMC_Close_Duty = 100U;
#endif

#ifdef _CONFIG_EMC_Test
const uint16_t K_EMC_NoAction_Stop_Time = 50U; /*100ms x 10*/
const uint16_t K_EMC_CinchMotor_Neutral_Stop_Time = 10U; /*100ms x 10*/
const uint16_t K_EMC_CinchMotor_Neutral_Start_Time = 30U; /*100ms x 10*/

const uint16_t K_EMC_SpindleMotor_Open_Stop_Time = 10U; /*100ms x 10*/
const uint16_t K_EMC_SpindleMotor_Open_Start_Time = 60U; /*100ms x 10*/

const uint16_t K_EMC_SpindleMotor_Close_Stop_Time = 10U; /*100ms x 10*/
const uint16_t K_EMC_SpindleMotor_Close_Start_Time = 60U; /*100ms x 10*/

const uint16_t K_EMC_CinchMotor_Cinch_Stop_Time = 10U; /*100ms x 10*/
const uint16_t K_EMC_CinchMotor_Cinch_Start_Time = 30U; /*100ms x 10*/

const uint16_t K_EMC_ReleaseMotor_Release_Stop_Time = 10U; /*100ms x 10*/
const uint16_t K_EMC_ReleaseMotor_Release_Start_Time = 30U; /*100ms x 10*/
const uint16_t K_EMC_BrakeToGround_Delay_Time = 1U; /*100ms x 10*/
#endif

/*********************************************************************************************
**    Network Manage
*********************************************************************************************/
const uint16_t K_NM_Comm_Reset_Timeout = 1U;  /*10ms x 10 */
const uint16_t K_SGMWNM_Init_Timeout = 0U;  /*10ms x 0 */

const uint16_t K_NM_Continue_Message_Period_Time = 100U;  /*10ms x 100 */
const uint16_t K_SGMWNM_AppTx_Delay_Time = 4U;   /*10ms x 1 */
const uint16_t K_NM_AppTx_Stop_Delay_Time = 300U;  /*10ms x 1 */
const uint16_t K_NM_Continue_Message_BusOff_Time = 0U;//2U; /*10ms x 1 */
const uint16_t K_Send_NM_Initialize_BusOffDelay_Time = 99; /*10ms x 1 */

const uint16_t K_NM_AfterWakeup_Time = 200U;  /*10ms x  */

#ifdef _CHERY_COM
const uint16_t K_NM_RemoteEvent_Timeout = 200U;  /*10ms x  */
const uint16_t K_UDS_RemoteEvent_Timeout = 6000U;  /*10ms x  */
const uint16_t K_NM_LocalEvent_Short_Timeout = 200U;  /*10ms x  */
const uint16_t K_NM_LocalEvent_Long_Timeout = 200U;  /*10ms x  */
const uint32_t K_NM_LocalEvent_Delay_Time = 600U;//90000U;//2000U; //900U;  /*10ms x  */
const uint32_t K_NM_LocalEvent_MinTime = 600U;  /*10ms x  */
const uint16_t K_Com_TxStart_Request_Time = 7U;  /*10ms x  */
const uint16_t K_UDS_KeepEvent_Timeout = 600U;  /*10ms x  */
const uint16_t K_Igntion_KeepEvent_Timeout = 10U;  /*10ms x  */
const uint16_t K_NMFrame_Timeout = 200U;  /*10ms x  */
const uint16_t K_UDSFrame_Timeout = 500U;  /*10ms x  */
#endif


/*********************************************************************************************
**    Power Manage
*********************************************************************************************/
const uint16_t K_VBATT1_Voltage_Dropping_Rate = 50U;//170U; /*Delta 100 = Delta 1V*/
const uint16_t K_VBATT1_Voltage_Rising_Rate = 50U; //170U; /*Delta 100 = Delta 1V*/
const uint16_t K_VBATT2_Voltage_Time = 20; /*5ms x 20 = 100ms*/
const uint16_t K_VBATT1_Voltage_PowerDrop_Threshold = 1000U; /*K_10V_ATD*/
const uint16_t K_VBATT1_Voltage_Stable_Rate = 10U; //170U; /*Delta 100 = Delta 1V*/
const uint16_t K_VBATT1_Voltage_Dropping_Time = 20U; /*5ms x 20 = 100ms*/

const uint16_t K_Power_Manager_Init_Time = 20U; /*5ms x 20 = 100ms*/

#if defined(_CONFIG_Gen1_Board) || defined(_CONFIG_Gen2_Board)
const uint16_t K_Hall_Power_OverCurrentShutDown_Voltage = 400U; /*100 = 1V*/
const uint16_t K_HallPower_Recovery_Count_HighLimit = 10U; /*10 times*/
const uint16_t K_HallPower_Recovery_Timeout = 10U; /*10ms x */
const uint16_t K_HallPower_Recovery_Delay_Time = 10U;/*10ms x */
#endif

#if defined(_CONFIG_Gen3_Board) || defined(_CONFIG_Gen4_Board)
const uint16_t K_HallPower1_OverCurrentShutDown_Voltage = 400U; /*100 = 1V*/
const uint16_t K_HallPower1_Recovery_Count_HighLimit = 10U; /*10 times*/
const uint16_t K_HallPower1_Recovery_Timeout = 10U; /*10ms x */
const uint16_t K_HallPower1_Recovery_Delay_Time = 10U;/*10ms x */

const uint16_t K_HallPower2_OverCurrentShutDown_Voltage = 400U; /*100 = 1V*/
const uint16_t K_HallPower2_Recovery_Count_HighLimit = 10U; /*10 times*/
const uint16_t K_HallPower2_Recovery_Timeout = 10U; /*10ms x */
const uint16_t K_HallPower2_Recovery_Delay_Time = 10U;/*10ms x */
#endif


/*********************************************************************************************
**    memory_manage
*********************************************************************************************/
const uint16_t K_MemorySave_Delay_Time = 300U;

/*********************************************************************************************
**    dtc_report
*********************************************************************************************/
const uint16_t K_OperationCycle_AfterWakeup_Time = 10U; /*10ms x 10 = 100ms*/
const uint16_t K_DTCData_SaveImmediately_Time = 100U; /*10ms x 10 = 100ms*/

const uint16_t K_DTC_PendingCount = 2U;     
const uint16_t K_DTC_AgingCount = 40U; 
#ifdef _CHERY_COM
const uint8_t K_DTC_Mask_Bit = 0x09;
#endif
#ifdef _VOYAH_COM
const uint8_t K_DTC_Mask_Bit = 0x09;
#endif
#ifdef _AUDI_COM
const uint8_t K_DTC_Mask_Bit = 0x09;
#endif
#ifdef _SGMW_COM
const uint8_t K_DTC_Mask_Bit = 0x4b;
#endif
#ifdef _SGM_COM
const uint8_t K_DTC_Mask_Bit = 0x09;
#endif
#ifdef _CTCS_COM
const uint8_t K_DTC_Mask_Bit = 0x09;
#endif
#ifdef _DEARCC_COM
const uint8_t K_DTC_Mask_Bit = 0x09;
#endif
#ifdef _XIAOPENG_COM
const uint8_t K_DTC_Mask_Bit = 0x09;
#endif
#ifdef _MAXUS_COM
const uint8_t K_DTC_Mask_Bit = 0x0b;
#endif
#ifdef _DFMC_COM
const uint8_t K_DTC_Mask_Bit = 0x09;
#endif
#ifdef _BAIC_COM
const uint8_t K_DTC_Mask_Bit = 0x09;
#endif
#ifdef _DFLZM_COM
const uint8_t K_DTC_Mask_Bit = 0x09;
#endif
#ifdef _NIU_COM
const uint8_t K_DTC_Mask_Bit = 0x09;
#endif
#ifdef _FAW_COM
const uint8_t K_DTC_Mask_Bit = 0x09;
#endif
#ifdef _CHANGAN_COM
const uint8_t K_DTC_Mask_Bit = 0x09;
#endif

/*********************************************************************************************
**    mode_control
*********************************************************************************************/
const uint16_t K_ECU_Reset_Delay_Time = 10U; /*10m x 10 */

/*********************************************************************************************
**    handle_control
*********************************************************************************************/
#ifdef _CONFIG_PowerHandle
const uint16_t K_HandlePowerOn_Time = 7U; /*10m x 10 */
const uint16_t K_HandleWakeUp_Time = 7U; /*10m x 10 */
const uint16_t K_HandleReset_Time = 7U; /*10m x 10 */

const uint16_t K_HandlePowerOpening_SoftStall_Time = 10U; /*10m x 10 */
const uint16_t K_HandlePowerClosing_SoftStall_Time = 10U; /*10m x 10 */

const uint16_t K_CentralLockSwitch_HandleCommandInterval_Enable = FALSE;
const uint16_t K_HandlePowerOpening_ObstacleDetected_Reverse_Enable = FALSE;
const uint16_t K_HandlePowerClosing_ObstacleDetected_Reverse_Enable = FALSE;

const uint16_t K_HandleCommandInterval_Time = 50U; /*10m x 10 */
const uint16_t K_CentralLockSwitch_HandleCommandDelay_Time = 50U; /*10m x 10 */

const uint16_t K_HandlePowerOpening_Timeout = 150U; /*10m x 10 */
const uint16_t K_HandlePowerClosing_Timeout = 150U; /*10m x 10 */

const uint16_t K_HandleOpenedFully_Timeout = 500U; /*10m x 10 */
const uint16_t K_HandleReleased_Timeout = 500U; /*10m x 10 */

const uint16_t K_ChangeDutyInHandlePowerOpening_1st_Time = 10U; /*10m x 10 */
const uint16_t K_ChangeDutyInHandlePowerClosing_1st_Time = 10U; /*10m x 10 */

const uint16_t K_StopBefore_HandlePowerOpening_Time = 10U; /*10m x 10 */
const uint16_t K_StopBefore_HandlePowerClosing_Time = 10U; /*10m x 10 */

const uint16_t K_HandlePowerOpening_Inrush_Time = 10U; /*10m x 10 */
const uint16_t K_HandlePowerClosing_Inrush_Time = 10U; /*10m x 10 */

const uint16_t K_HandleMotor_EnhancedCurrent_DecreasePerTimer = 5U;    /*10ms x */
const uint16_t K_HandleMotor_EnhancedCurrent_Decrease_Time = 2U;       /*10ms x */
const uint16_t K_HandleMotor_EnhancedCurrent_IncreasePerTimer = 5U;  /*10ms x */
const uint16_t K_HandleMotor_EnhancedCurrent_Increase_Time = 2U;      /*10ms x */
const uint16_t K_HandleMotor_EnhancedCurrent_Threshold_Time = 2U;     /*10ms x */

const uint16_t K_HandleMotor_SoftStall_Detect_Time = 50U;    /*10ms x */
const uint16_t K_HandleMotor_FixedCurrent_Detect_Time = 10U;    /*10ms x */

const uint16_t K_HandleHomePosition_Delay_Time = 10U; /*10m x 10 */
const uint16_t K_HandleSpreadPosition_Delay_Time = 10U; /*10m x 10 */

const uint16_t K_HandleMotor_EnhancedCurrent_Detect[8][8]=
{     
      /* 9v  10v 11v 12v 13v14v15v16v  */
	{10,10,10,10,10,10,10,10},
	{10,10,10,10,10,10,10,10},
	{10,10,10,10,10,10,10,10},
	{10,10,10,10,10,10,10,10},
	{10,10,10,10,10,10,10,10},
	{10,10,10,10,10,10,10,10},
	{10,10,10,10,10,10,10,10},
	{10,10,10,10,10,10,10,10}
};

const uint16_t K_HandleMotor_SoftStallCurrent_TopLimit[8][8]=
{     
      /* 9v  10v 11v 12v 13v14v15v16v  */
	{100,100,100,100,100,100,100,100},
	{100,100,100,100,100,100,100,100},
	{100,100,100,100,100,100,100,100},
	{100,100,100,100,100,100,100,100},
	{100,100,100,100,100,100,100,100},
	{100,100,100,100,100,100,100,100},
	{100,100,100,100,100,100,100,100},
	{100,100,100,100,100,100,100,100}
};

const uint16_t K_HandleMotor_FixedCurrentStall_TopLimit[8][8]=
{     
      /* 9v  10v 11v 12v 13v14v15v16v  */
	{300,300,300,300,300,300,300,300},
	{300,300,300,300,300,300,300,300},
	{300,300,300,300,300,300,300,300},
	{300,300,300,300,300,300,300,300},
	{300,300,300,300,300,300,300,300},
	{300,300,300,300,300,300,300,300},
	{300,300,300,300,300,300,300,300},
	{300,300,300,300,300,300,300,300}
};

const uint16_t K_HandleMotor_HandlePowerOpening_Duty[8][8]=
{     
      /* 9v  10v 11v 12v 13v14v15v16v  */
	{30,30,30,30,30,30,30,30},
	{30,30,30,30,30,30,30,30},
	{30,30,30,30,30,30,30,30},
	{30,30,30,30,30,30,30,30},
	{30,30,30,30,30,30,30,30},
	{30,30,30,30,30,30,30,30},
	{30,30,30,30,30,30,30,30},
	{30,30,30,30,30,30,30,30}
};
const uint16_t K_HandleMotor_HandlePowerOpening_Duty_2nd[8][8]=
{     
	 /* 9v  10v 11v 12v 13v14v15v16v  */
	{30,30,30,30,30,30,30,30},
	{30,30,30,30,30,30,30,30},
	{30,30,30,30,30,30,30,30},
	{30,30,30,30,30,30,30,30},
	{30,30,30,30,30,30,30,30},
	{30,30,30,30,30,30,30,30},
	{30,30,30,30,30,30,30,30},
	{30,30,30,30,30,30,30,30}
 
};
const uint16_t K_HandleMotor_HandlePowerClosing_Duty[8][8]=
{     
     /* 9v  10v 11v 12v 13v14v15v16v  */
	{30,30,30,30,30,30,30,30},
	{30,30,30,30,30,30,30,30},
	{30,30,30,30,30,30,30,30},
	{30,30,30,30,30,30,30,30},
	{30,30,30,30,30,30,30,30},
	{30,30,30,30,30,30,30,30},
	{30,30,30,30,30,30,30,30},
	{30,30,30,30,30,30,30,30}
};

const uint16_t K_HandleMotor_HandlePowerClosing_Duty_2nd[8][8]=
{     
      /* 9v  10v 11v 12v 13v14v15v16v  */
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20}
};
#endif

/*********************************************************************************************
**    spoiler_control
*********************************************************************************************/
#ifdef _CONFIG_PowerSpoiler
#ifdef _Spoiler_ChanganH53
/* Spoiler_PID Control - Default */
const uint8_t K_Spoiler_Prop_Open[20] = {30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30};
const uint8_t K_Spoiler_PropScale_Open[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
const uint8_t K_Spoiler_Int_Open[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
const uint8_t K_Spoiler_IntScale_Open[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
const uint8_t K_Spoiler_Diff_Open[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
const uint8_t K_Spoiler_DiffScale_Open[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

const uint8_t K_Spoiler_Prop_Close[20] = {30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30};
const uint8_t K_Spoiler_PropScale_Close[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
const uint8_t K_Spoiler_Int_Close[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
const uint8_t K_Spoiler_IntScale_Close[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
const uint8_t K_Spoiler_Diff_Close[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
const uint8_t K_Spoiler_DiffScale_Close[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

const uint8_t K_Spoiler_Prop_PushPID = 2U;
const uint8_t K_Spoiler_PropScale_PushPID = 1U;
const uint8_t K_Spoiler_Int_PushPID = 1U;
const uint8_t K_Spoiler_IntScale_PushPID = 1U;
const uint8_t K_Spoiler_Diff_PushPID = 1U;
const uint8_t K_Spoiler_DiffScale_PushPID = 1U;

const uint16_t K_Spoiler_PushPID_HallCount = 100U;
const uint16_t K_Spoiler_PushPIDSpeed_Tigger_Delta = 3U;
const uint16_t K_Spoiler_PushPIDSpeed_Quit_Delta = 2U;
const uint16_t K_Spoiler_PushPID_Timeout = 50U; /*20ms x*/
const uint16_t K_Spoiler_PushPID_ObstacleAdder_Timeout = 50U; /*20ms x*/

const uint16_t K_SpoilerPowerOn_Time = 7U; /*10m x 10 */
const uint16_t K_SpoilerWakeUp_Time = 7U; /*10m x 10 */
const uint16_t K_SpoilerReset_Time = 7U; /*10m x 10 */

const uint16_t K_SpoilerPowerOpening_SoftStall_Time = 10U; /*10m x 10 */
const uint16_t K_SpoilerPowerClosing_SoftStall_Time = 10U; /*10m x 10 */

const uint16_t K_SpoilerPowerOpening_ObstacleDetected_Reverse_Enable = TRUE;
const uint16_t K_SpoilerPowerClosing_ObstacleDetected_Reverse_Enable = TRUE;

const uint16_t K_SpoilerSwitch_ShortPress_LowLimit_Time = 5U; /* 50 x 10ms*/
const uint16_t K_SpoilerSwitch_ShortPress_HighLimit_Time = 100U; /* 100 x 10ms*/
const uint16_t K_SpoilerSwitch_LongPress_LowLimit_Time = 100U; /* 300 x 10ms*/
const uint16_t K_SpoilerSwitch_LongPress_HighLimit_Time = 500U; /* 500 x 10ms*/

const uint16_t K_SpoilerOpenSwitch_ShortPress_LowLimit_Time = 5U; /* 50 x 10ms*/
const uint16_t K_SpoilerOpenSwitch_ShortPress_HighLimit_Time = 100U; /* 100 x 10ms*/
const uint16_t K_SpoilerOpenSwitch_LongPress_LowLimit_Time = 100U; /* 300 x 10ms*/
const uint16_t K_SpoilerOpenSwitch_LongPress_HighLimit_Time = 500U; /* 500 x 10ms*/

const uint16_t K_SpoilerCloseSwitch_ShortPress_LowLimit_Time = 5U; /* 50 x 10ms*/
const uint16_t K_SpoilerCloseSwitch_ShortPress_HighLimit_Time = 100U; /* 100 x 10ms*/
const uint16_t K_SpoilerCloseSwitch_LongPress_LowLimit_Time = 100U; /* 300 x 10ms*/
const uint16_t K_SpoilerCloseSwitch_LongPress_HighLimit_Time = 500U; /* 500 x 10ms*/

const uint16_t K_SpoilerSwitch_LongPress_ManualUnlearn_Time = 500U; /* 500 x 10ms*/

const uint16_t K_SpoilerCommandInterval_Time = 50U; /*10m x 10 */

const uint16_t K_CentralLockSwitch_SpoilerCommandInterval_Enable = FALSE;
const uint16_t K_CentralLockSwitch_SpoilerCommandDelay_Time = 0U; /*10m x 10 */
const uint16_t K_CentralLockSwitch_Wakeup_SpoilerCommandDelay_Time = 50U; /*10m x 10 */

const uint16_t K_SpoilerSwitch_SpoilerCommandInterval_Enable = FALSE;
const uint16_t K_SpoilerSwitch_SpoilerCommandDelay_Time = 0U; /*10m x 10 */
const uint16_t K_SpoilerSwitch_Wakeup_SpoilerCommandDelay_Time = 50U; /*10m x 10 */

const uint16_t K_SpoilerOpenSwitch_SpoilerCommandInterval_Enable = FALSE;
const uint16_t K_SpoilerOpenSwitch_SpoilerCommandDelay_Time = 0U; /*10m x 10 */
const uint16_t K_SpoilerOpenSwitch_Wakeup_SpoilerCommandDelay_Time = 50U; /*10m x 10 */

const uint16_t K_SpoilerCloseSwitch_SpoilerCommandInterval_Enable = FALSE;
const uint16_t K_SpoilerCloseSwitch_SpoilerCommandDelay_Time = 0U; /*10m x 10 */
const uint16_t K_SpoilerCloseSwitch_Wakeup_SpoilerCommandDelay_Time = 50U; /*10m x 10 */

const uint16_t K_SpoilerCommandInhibition_Min_Time = 20U; /*10m x 10 */
const uint16_t K_SpoilerSwitch_ShortPress_SpoilerCommandInhibition_Time = 100U; /*10m x 10 */
const uint16_t K_SpoilerOpenSwitch_ShortPress_SpoilerCommandInhibition_Time = 100U; /*10m x 10 */
const uint16_t K_SpoilerCloseSwitch_ShortPress_SpoilerCommandInhibition_Time = 100U; /*10m x 10 */

const uint16_t K_SpoilerPowerOpening_Timeout = 800U; /*10m x 10 */
const uint16_t K_SpoilerPowerClosing_Timeout = 800U; /*10m x 10 */

const uint16_t K_SpoilerOpenEnd_FullOpenSwitchPosition_Compensation = 0U;
const uint16_t K_SpoilerCloseEnd_FullCloseSwitchPosition_Compensation = 0U;
const uint16_t K_SpoilerMiddleEnd_MiddleSwitchPosition_Compensation = 35U;

const uint16_t K_SpoilerFullOpenPosition_Delay_Time = 0U; /*10m x */
const uint16_t K_SpoilerFullClosePosition_Delay_Time = 0U; /*10m x */
const uint16_t K_SpoilerMiddlePosition_Delay_Time = 0U; /*10m x */

const uint16_t K_SpoilerFullOpenSwitchVirtual_HallCount = 800U;
const uint16_t K_SpoilerFullCloseSwitchVirtual_HallCount = 200U;
const uint16_t K_SpoilerMiddleSwitchVirtual_HallCount = 600U;
const uint16_t K_SpoilerLearnMiniPosition_HallCount = 600U;

const uint16_t K_SpoilerMaxPosition_HallCount_Default = 1500U;

const uint16_t K_SpoilerOpenedFully_Timeout = 500U; /*10m x 10 */
const uint16_t K_SpoilerReleased_Timeout = 500U; /*10m x 10 */
const uint16_t K_SpoilerMechFailure_Timeout = 100U; /*10m x 10 */

const uint16_t K_ChangeDutyInSpoilerPowerOpening_1st_Time = 10U; /*10m x 10 */
const uint16_t K_ChangeDutyInSpoilerPowerClosing_1st_Time = 10U; /*10m x 10 */

const uint16_t K_StopBefore_SpoilerPowerOpening_Time = 10U; /*10m x 10 */
const uint16_t K_StopBefore_SpoilerPowerClosing_Time = 10U; /*10m x 10 */

const uint16_t K_SpoilerPowerOpening_Inrush_Time = 10U; /*10m x 10 */
const uint16_t K_SpoilerPowerClosing_Inrush_Time = 10U; /*10m x 10 */

const uint16_t K_Spoiler_ObstacleIndex = 10U;
const uint16_t K_Spoiler_HallCountPerObstacleZone_Min = 60U;
const uint16_t K_Spoiler_HallCountPerObstacleZone_Max = 150U;    
const uint16_t K_Spoiler_HallCountPerObstacleZone_Default = 100U;

const uint16_t K_Spoiler_PowerOpening_HallCount_Delta = 0U;
const uint16_t K_Spoiler_PowerClosing_HallCount_Delta = 0U;

const uint16_t K_Spoiler_EnhancedCurrent_DecreasePerTimer = 5U;    /*10ms x */
const uint16_t K_Spoiler_EnhancedCurrent_Decrease_Time = 2U;       /*10ms x */
const uint16_t K_Spoiler_EnhancedCurrent_IncreasePerTimer = 40U;  /*10ms x */
const uint16_t K_Spoiler_EnhancedCurrent_Increase_Time = 20U;      /*10ms x */
const uint16_t K_Spoiler_EnhancedCurrent_Threshold_Time = 1U;     /*10ms x */

const uint16_t K_Spoiler_SoftStall_Detect_Time = 50U;    /*10ms x */
const uint16_t K_Spoiler_FixedCurrent_Detect_Time = 10U;    /*10ms x */

const uint16_t K_SpoilerHomePosition_Delay_Time = 10U; /*10m x 10 */
const uint16_t K_SpoilerSpreadPosition_Delay_Time = 10U; /*10m x 10 */

const uint16_t K_Spoiler_EnhancedCurrent_Detect_PushPID_Open_Adder[10] = {10,10,10,10,10,10,10,10,10,10};
const uint16_t K_Spoiler_EnhancedCurrent_Detect_PushPID_Close_Adder[10] = {10,10,10,10,10,10,10,10,10,10};
const uint16_t K_Spoiler_SpoilerPowerOpening_Duty[8][8]=
{     
      /* 9v  10v 11v 12v 13v14v15v16v  */
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20}
};
const uint16_t K_Spoiler_SpoilerPowerClosing_Duty[8][8]=
{     
      /* 9v  10v 11v 12v 13v14v15v16v  */
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20}
};

const uint16_t K_Spoiler_PositionObstacle_Detect_Delta = 20U;
const uint16_t K_Spoiler_PositionObstacle_Detect_Open_Timer[10] = {10,10,10,10,10,10,10,10,10,10};
const uint16_t K_Spoiler_PositionObstacle_Detect_Close_Timer[10] = {10,10,10,10,10,10,10,10,10,10};

const uint16_t K_Spoiler_HallPluse1Width_Time = 30U;
const uint16_t K_Spoiler_HallPluse2Width_Time = 30U;

const uint16_t K_Spoiler_SpeedZoneIndex = 20U;
const uint16_t K_Spoiler_HallCountPerSpeedZone_Min = 60U;
const uint16_t K_Spoiler_HallCountPerSpeedZone_Max = 200U;
const uint16_t K_Spoiler_HallCountPerSpeedZone_Default = 90U;

const uint16_t K_Spoiler_StopFromMaxTravel_HallCount = 20U;
const uint16_t K_SpoilerOpenEnd_SoftStop_HallCount_Compensation = 50U;
const uint16_t K_SpoilerCloseEnd_SoftStop_HallCount_Compensation = 80U;
const uint16_t K_SpoilerMiddleEnd_SoftStop_HallCount_Compensation = 50U;
/* Desired power opening speed value */
const uint16_t K_Spoiler_Desired_Open_Speed[8][20] = 
{
	{5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,5},          /*-40degree*/
	{5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,5},          /*-25degree*/
	{5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,5},          /*-10degree*/
	{5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,5},          /*+05degree*/
	{5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,5},          /*+20degree*/
	{5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,5},          /*+35degree*/
	{5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,5},          /*+50degree*/
	{5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,5},          /*+65degree*/
};

/* Desired power closing speed value */
const uint16_t K_Spoiler_Desired_Close_Speed[8][20] = 
{
	{5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,5},          /*-40degree*/
	{5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,5},          /*-25degree*/
	{5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,5},          /*-10degree*/
	{5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,5},          /*+05degree*/
	{5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,5},          /*+20degree*/
	{5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,5},          /*+35degree*/
	{5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,5},          /*+50degree*/
	{5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,5},          /*+65degree*/
};


const uint16_t K_Spoiler_FixedVoltage_Open_Enable[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
const uint16_t K_Spoiler_FixedVoltage_Close_Enable[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
const uint16_t K_Spoiler_FixedVoltage_Open_Duty[20] = {60,60,60,60,60,60,60,60,60,60,50,50,50,50,50,50,50,50,50,50};
const uint16_t K_Spoiler_FixedVoltage_Close_Duty[20] = {50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50};
const uint16_t K_Spoiler_FixedVoltage_Open_Timeout[20] = {100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100};
const uint16_t K_Spoiler_FixedVoltage_Close_Timeout[20] = {100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100};

const uint16_t K_Spoiler_PID_PWM_Max_PowerOpening[20] = {100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100};
const uint16_t K_Spoiler_PID_PWM_Max_PowerClosing[20] = {100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100};

const uint16_t K_Spoiler_Opening_IncreaseDuty_Time = 1U; /*10ms x*/
const uint16_t K_Spoiler_Opening_IncreasePerTime_Duty = 2U;
const uint16_t K_Spoiler_Closing_IncreaseDuty_Time = 1U; /*10ms x*/
const uint16_t K_Spoiler_Closing_IncreasePerTime_Duty = 2U; 
const uint16_t K_Spoiler_Opening_Start_Duty[10] = {30,30,30,30,30,30,30,30,30,30};
const uint16_t K_Spoiler_Closing_Start_Duty[10] = {30,30,30,30,30,30,30,30,30,30};
const uint16_t K_Spoiler_SoftStop_Opening_Step_Duty = 5U;
const uint16_t K_Spoiler_SoftStop_Opening_Step_Time = 1U; /* 10ms x 5 */
const uint16_t K_Spoiler_SoftStop_Opening_End_Duty  = 20U;
const uint16_t K_Spoiler_SoftStop_Closing_Step_Duty = 5U;
const uint16_t K_Spoiler_SoftStop_Closing_Step_Time = 1U; /* 10ms x 5 */
const uint16_t K_Spoiler_SoftStop_Closing_End_Duty  = 20U;
const uint16_t K_SpoilerHallObstacle_SoftStop_Time = 100U; /* 10ms x 100 */

const uint16_t K_Spoiler_SoftStart_Opening_HallCount_LowLimit = 0U; /**/
const uint16_t K_Spoiler_SoftStart_Closing_HallCount_LowLimit = 0U;
const uint16_t K_Spoiler_SoftStart_Opening_HallCount_HighLimit = 3500U; /**/
const uint16_t K_Spoiler_SoftStart_Closing_HallCount_HighLimit = 3500U;

const uint16_t K_SpoilerPowerOpening_Speedup_FullOpen_Time = 30U; /* 10ms x */
const uint16_t K_SpoilerPowerClosing_Speedup_FullClose_Time = 30U; /* 10ms x */
const uint16_t K_SpoilerPowerOpening_Speedup_Time = 50U; /* 10ms x */
const uint16_t K_SpoilerPowerClosing_Speedup_Time = 50U; /* 10ms x */
const uint16_t K_SpoilerPowerOpening_HardStart_Time[10] = {60,50,50,30,30,30,30,30,30,30}; /* 10ms x */
const uint16_t K_SpoilerPowerClosing_HardStart_Time[10] = {30,30,30,30,30,30,30,30,30,30}; /* 10ms x */

const uint16_t K_Spoiler_HardStart_Enable = TRUE;
const uint16_t K_Spoiler_Speedup_OpenInLowZone_HallCount = 20U;
const uint16_t K_Spoiler_Speedup_OpenInMiddleZone_HallCount = 20U;
const uint16_t K_Spoiler_Speedup_OpenInHighZone_HallCount = 20U;

const uint16_t K_Spoiler_Speedup_CloseInLowZone_HallCount = 20U;
const uint16_t K_Spoiler_Speedup_CloseInMiddleZone_HallCount = 20U;
const uint16_t K_Spoiler_Speedup_CloseInHighZone_HallCount = 20U;

const uint16_t K_Spoiler_SpeedupInLowZone_HallCount = 100U;   
const uint16_t K_Spoiler_SpeedupInHighZone_HallCount = 2500U; 

const uint16_t K_Spoiler_SpeedupInLowZone_Open_Duty[8][8] = 
{
 	{30,30,30,30,30,30,30,30},   /*-40degree*/
	{30,30,30,30,30,30,30,30},   /*-25degree*/
	{30,30,30,30,30,30,30,30},   /*-10degree*/
	{30,30,30,30,30,30,30,30},   /*+05degree*/
	{30,30,30,30,30,30,30,30},   /*+20degree*/
	{30,30,30,30,30,30,30,30},   /*+35degree*/
	{30,30,30,30,30,30,30,30},   /*+50degree*/
	{30,30,30,30,30,30,30,30}    /*+65degree*/
};

const uint16_t K_Spoiler_SpeedupInLowZone_Close_Duty[8][8] = 
{
	{30,30,30,30,30,30,30,30},   /*-40degree*/
	{30,30,30,30,30,30,30,30},   /*-25degree*/
	{30,30,30,30,30,30,30,30},   /*-10degree*/
	{30,30,30,30,30,30,30,30},   /*+05degree*/
	{30,30,30,30,30,30,30,30},   /*+20degree*/
	{30,30,30,30,30,30,30,30},   /*+35degree*/
	{30,30,30,30,30,30,30,30},   /*+50degree*/
	{30,30,30,30,30,30,30,30}    /*+65degree*/
};

const uint16_t K_Spoiler_SpeedupInMiddleZone_Open_Duty[8][8] = 
{
	{30,30,30,30,30,30,30,30},   /*-40degree*/
	{30,30,30,30,30,30,30,30},   /*-25degree*/
	{30,30,30,30,30,30,30,30},   /*-10degree*/
	{30,30,30,30,30,30,30,30},   /*+05degree*/
	{30,30,30,30,30,30,30,30},   /*+20degree*/
	{30,30,30,30,30,30,30,30},   /*+35degree*/
	{30,30,30,30,30,30,30,30},   /*+50degree*/
	{30,30,30,30,30,30,30,30}    /*+65degree*/
};

const uint16_t K_Spoiler_SpeedupInMiddleZone_Close_Duty[8][8] = 
{
	{30,30,30,30,30,30,30,30},   /*-40degree*/
	{30,30,30,30,30,30,30,30},   /*-25degree*/
	{30,30,30,30,30,30,30,30},   /*-10degree*/
	{30,30,30,30,30,30,30,30},   /*+05degree*/
	{30,30,30,30,30,30,30,30},   /*+20degree*/
	{30,30,30,30,30,30,30,30},   /*+35degree*/
	{30,30,30,30,30,30,30,30},   /*+50degree*/
	{30,30,30,30,30,30,30,30}    /*+65degree*/
};

const uint16_t K_Spoiler_SpeedupInHighZone_Open_Duty[8][8] = 
{
	{30,30,30,30,30,30,30,30},   /*-40degree*/
	{30,30,30,30,30,30,30,30},   /*-25degree*/
	{30,30,30,30,30,30,30,30},   /*-10degree*/
	{30,30,30,30,30,30,30,30},   /*+05degree*/
	{30,30,30,30,30,30,30,30},   /*+20degree*/
	{30,30,30,30,30,30,30,30},   /*+35degree*/
	{30,30,30,30,30,30,30,30},   /*+50degree*/
	{30,30,30,30,30,30,30,30}    /*+65degree*/
};

const uint16_t K_Spoiler_SpeedupInHighZone_Close_Duty[8][8] = 
{
	{30,30,30,30,30,30,30,30},   /*-40degree*/
	{30,30,30,30,30,30,30,30},   /*-25degree*/
	{30,30,30,30,30,30,30,30},   /*-10degree*/
	{30,30,30,30,30,30,30,30},   /*+05degree*/
	{30,30,30,30,30,30,30,30},   /*+20degree*/
	{30,30,30,30,30,30,30,30},   /*+35degree*/
	{30,30,30,30,30,30,30,30},   /*+50degree*/
	{30,30,30,30,30,30,30,30}    /*+65degree*/
};

const uint16_t K_Spoiler_ShortDistanceInOpening_HallCount[10] = {250,250,250,250,250,250,250,250,250,250};
const uint16_t K_Spoiler_ShortDistanceInClosing_HallCount[10] = {100,100,100,100,100,100,100,100,100,100};

const uint16_t K_Spoiler_ObstacleTimes_Continue_Count = 2U;
const uint16_t K_Spoiler_ObstacleTimes_Total_Count = 6U;

const uint16_t K_SpoilerLearned_Position_Default = 2500U;
const uint16_t K_SpoilerFullOpenSwitch_Position_Default = 2500U;
const uint16_t K_SpoilerFullCloseSwitch_Position_Default = 500U;
const uint16_t K_SpoilerMiddleSwitch_Position_Default = 1500U;
const uint16_t K_SpoilerMaxTravel_Position_Default = 3500U;
const uint16_t K_SpoilerMiddlePosition_TravelHallCount_Default = 100U;

const uint16_t K_SpoilerFullOpenSwitch_Position_Open_Delta = 60U;
const uint16_t K_SpoilerFullOpenSwitch_Position_Close_Delta = 0U;
const uint16_t K_Spoiler_LearnNearClosePosition_HallCount = 200U;
const uint16_t K_Spoiler_LearnNearClosePosition_Close_Time = 60U; /* 10ms x */
const uint16_t K_SpoilerFullOpenSwitch_Position_LearnNearClosePosition_Compensation = 20U;
const uint16_t K_SpoilerFullOpenSwitch_Position_LearnFarClosePosition_Compensation = 0U; 
const uint16_t K_SpoilerFullCloseSwitch_Position_LearnNearClosePosition_Compensation = 20U;
const uint16_t K_SpoilerFullCloseSwitch_Position_LearnFarClosePosition_Compensation = 0U;
const uint16_t K_SpoilerMiddleSwitch_Position_LearnNearClosePosition_Compensation = 20U;
const uint16_t K_SpoilerMiddleSwitch_Position_LearnFarClosePosition_Compensation = 0U; 

const uint16_t K_SpoilerFullOpenSwitch_HallEffect_Active_LowLimit = 2800U;/*12V = 2936 TRUE*/
const uint16_t K_SpoilerFullOpenSwitch_HallEffect_Active_HighLimit = 3100U;

const uint16_t K_SpoilerFullOpenSwitch_HallEffect_Inactive_LowLimit = 1400U;/*12V = 1286 FALSE*/
const uint16_t K_SpoilerFullOpenSwitch_HallEffect_Inactive_HighLimit = 1100U;

const uint16_t K_SpoilerFullCloseSwitch_HallEffect_Active_LowLimit = 2800U;/*12V = 2936 TRUE*/
const uint16_t K_SpoilerFullCloseSwitch_HallEffect_Active_HighLimit = 3100U;

const uint16_t K_SpoilerFullCloseSwitch_HallEffect_Inactive_LowLimit = 1400U;/*12V = 1286 FALSE*/
const uint16_t K_SpoilerFullCloseSwitch_HallEffect_Inactive_HighLimit = 1100U;
const uint16_t K_Spoiler_EnhancedCurrent_Detect_Open[8][10] = 
{
	{250,250,200,200,200,200,200,200,200,200},  /*<09V*/
	{250,250,200,200,200,200,200,200,200,200},  /*<10V*/
	{250,250,200,200,200,200,200,200,200,200},  /*<11V*/
	{250,250,200,200,200,200,200,200,200,200},  /*<12V*/
	{250,250,200,200,200,200,200,200,200,200},  /*<13V*/
	{250,250,200,200,200,200,200,200,200,200},  /*<14V*/
	{250,250,200,200,200,200,200,200,200,200},  /*<15V*/
	{250,250,200,200,200,200,200,200,200,200},  /*<16V*/
};

const uint16_t K_Spoiler_EnhancedCurrent_Detect_Open_Temp[8][10] = 
{
	{200,200,200,200,200,200,200,200,200,200},  /*-40degree*/
	{150,150,150,150,150,150,150,150,150,150},   /*-25degree*/
	{50,50,50,50,50,50,50,50,50,50},    /*-10degree*/
	{0,0,0,0,0,0,0,0,0,0},  /*+05degree*/
	{0,0,0,0,0,0,0,0,0,0},   /*+20degree*/
	{50,50,50,50,50,50,50,50,50,50},   /*+35degree*/
	{150,150,150,150,150,150,150,150,150,150},   /*+50degree*/
	{200,200,200,200,200,200,200,200,200,200},   /*+65degree*/
};

const uint16_t K_Spoiler_EnhancedCurrent_Detect_Close[8][10] = 
{
	{250,200,150,150,150,150,150,150,150,150},  /*<09V*/
	{250,200,150,150,150,150,150,150,150,150},  /*<10V*/
	{250,200,150,150,150,150,150,150,150,150},  /*<11V*/
	{250,200,150,150,150,150,150,150,150,150},  /*<12V*/
	{250,200,150,150,150,150,150,150,150,150},  /*<13V*/
	{250,200,150,150,150,150,150,150,150,150},  /*<14V*/
	{250,200,150,150,150,150,150,150,150,150},  /*<15V*/
	{250,200,150,150,150,150,150,150,150,150},  /*<16V*/
};

const uint16_t K_Spoiler_EnhancedCurrent_Detect_Close_Temp[8][10] = 
{
	{200,200,200,200,200,200,200,200,200,200},  /*-40degree*/
	{150,150,150,150,150,150,150,150,150,150},   /*-25degree*/
	{50,50,50,50,50,50,50,50,50,50},    /*-10degree*/
	{0,0,0,0,0,0,0,0,0,0},  /*+05degree*/
	{0,0,0,0,0,0,0,0,0,0},   /*+20degree*/
	{50,50,50,50,50,50,50,50,50,50},   /*+35degree*/
	{150,150,150,150,150,150,150,150,150,150},   /*+50degree*/
	{200,200,200,200,200,200,200,200,200,200},   /*+65degree*/
};
const uint16_t K_Spoiler_SoftStallCurrent_TopLimit[8][8]=
{     
     /* 9v  10v 11v 12v 13v14v15v16v  */
	{800,800,800,800,800,800,800,800},
	{800,800,800,800,800,800,800,800},
	{800,800,800,800,800,800,800,800},
	{800,800,800,800,800,800,800,800},
	{800,800,800,800,800,800,800,800},
	{800,800,800,800,800,800,800,800},
	{800,800,800,800,800,800,800,800},
	{800,800,800,800,800,800,800,800},
};

const uint16_t K_Spoiler_FixedCurrentStall_TopLimit[8][8]=
{     
      /* 9v  10v 11v 12v 13v14v15v16v  */
	{1600,1600,1600,1600,1600,1600,1600,1600},
	{1600,1600,1600,1600,1600,1600,1600,1600},
	{1600,1600,1600,1600,1600,1600,1600,1600},
	{1600,1600,1600,1600,1600,1600,1600,1600},
	{1600,1600,1600,1600,1600,1600,1600,1600},
	{1600,1600,1600,1600,1600,1600,1600,1600},
	{1600,1600,1600,1600,1600,1600,1600,1600},
	{1600,1600,1600,1600,1600,1600,1600,1600},
};
#endif
#ifdef _Spoiler_NioLibra
/* Spoiler_PID Control - Default */
const uint8_t K_Spoiler_Prop_Open[20] = {30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30};
const uint8_t K_Spoiler_PropScale_Open[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
const uint8_t K_Spoiler_Int_Open[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
const uint8_t K_Spoiler_IntScale_Open[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
const uint8_t K_Spoiler_Diff_Open[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
const uint8_t K_Spoiler_DiffScale_Open[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

const uint8_t K_Spoiler_Prop_Close[20] = {30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30};
const uint8_t K_Spoiler_PropScale_Close[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
const uint8_t K_Spoiler_Int_Close[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
const uint8_t K_Spoiler_IntScale_Close[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
const uint8_t K_Spoiler_Diff_Close[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
const uint8_t K_Spoiler_DiffScale_Close[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

const uint8_t K_Spoiler_Prop_PushPID = 2U;
const uint8_t K_Spoiler_PropScale_PushPID = 1U;
const uint8_t K_Spoiler_Int_PushPID = 1U;
const uint8_t K_Spoiler_IntScale_PushPID = 1U;
const uint8_t K_Spoiler_Diff_PushPID = 1U;
const uint8_t K_Spoiler_DiffScale_PushPID = 1U;

const uint16_t K_Spoiler_PushPID_HallCount = 100U;
const uint16_t K_Spoiler_PushPIDSpeed_Tigger_Delta = 3U;
const uint16_t K_Spoiler_PushPIDSpeed_Quit_Delta = 2U;
const uint16_t K_Spoiler_PushPID_Timeout = 50U; /*20ms x*/
const uint16_t K_Spoiler_PushPID_ObstacleAdder_Timeout = 50U; /*20ms x*/

const uint16_t K_SpoilerPowerOn_Time = 7U; /*10m x 10 */
const uint16_t K_SpoilerWakeUp_Time = 7U; /*10m x 10 */
const uint16_t K_SpoilerReset_Time = 7U; /*10m x 10 */

const uint16_t K_SpoilerPowerOpening_SoftStall_Time = 10U; /*10m x 10 */
const uint16_t K_SpoilerPowerClosing_SoftStall_Time = 10U; /*10m x 10 */

const uint16_t K_SpoilerPowerOpening_ObstacleDetected_Reverse_Enable = TRUE;
const uint16_t K_SpoilerPowerClosing_ObstacleDetected_Reverse_Enable = TRUE;

const uint16_t K_SpoilerSwitch_ShortPress_LowLimit_Time = 5U; /* 50 x 10ms*/
const uint16_t K_SpoilerSwitch_ShortPress_HighLimit_Time = 100U; /* 100 x 10ms*/
const uint16_t K_SpoilerSwitch_LongPress_LowLimit_Time = 100U; /* 300 x 10ms*/
const uint16_t K_SpoilerSwitch_LongPress_HighLimit_Time = 500U; /* 500 x 10ms*/

const uint16_t K_SpoilerOpenSwitch_ShortPress_LowLimit_Time = 5U; /* 50 x 10ms*/
const uint16_t K_SpoilerOpenSwitch_ShortPress_HighLimit_Time = 100U; /* 100 x 10ms*/
const uint16_t K_SpoilerOpenSwitch_LongPress_LowLimit_Time = 100U; /* 300 x 10ms*/
const uint16_t K_SpoilerOpenSwitch_LongPress_HighLimit_Time = 500U; /* 500 x 10ms*/

const uint16_t K_SpoilerCloseSwitch_ShortPress_LowLimit_Time = 5U; /* 50 x 10ms*/
const uint16_t K_SpoilerCloseSwitch_ShortPress_HighLimit_Time = 100U; /* 100 x 10ms*/
const uint16_t K_SpoilerCloseSwitch_LongPress_LowLimit_Time = 100U; /* 300 x 10ms*/
const uint16_t K_SpoilerCloseSwitch_LongPress_HighLimit_Time = 500U; /* 500 x 10ms*/

const uint16_t K_SpoilerSwitch_LongPress_ManualUnlearn_Time = 500U; /* 500 x 10ms*/

const uint16_t K_SpoilerCommandInterval_Time = 50U; /*10m x 10 */

const uint16_t K_CentralLockSwitch_SpoilerCommandInterval_Enable = FALSE;
const uint16_t K_CentralLockSwitch_SpoilerCommandDelay_Time = 0U; /*10m x 10 */
const uint16_t K_CentralLockSwitch_Wakeup_SpoilerCommandDelay_Time = 50U; /*10m x 10 */

const uint16_t K_SpoilerSwitch_SpoilerCommandInterval_Enable = FALSE;
const uint16_t K_SpoilerSwitch_SpoilerCommandDelay_Time = 0U; /*10m x 10 */
const uint16_t K_SpoilerSwitch_Wakeup_SpoilerCommandDelay_Time = 50U; /*10m x 10 */

const uint16_t K_SpoilerOpenSwitch_SpoilerCommandInterval_Enable = FALSE;
const uint16_t K_SpoilerOpenSwitch_SpoilerCommandDelay_Time = 0U; /*10m x 10 */
const uint16_t K_SpoilerOpenSwitch_Wakeup_SpoilerCommandDelay_Time = 50U; /*10m x 10 */

const uint16_t K_SpoilerCloseSwitch_SpoilerCommandInterval_Enable = FALSE;
const uint16_t K_SpoilerCloseSwitch_SpoilerCommandDelay_Time = 0U; /*10m x 10 */
const uint16_t K_SpoilerCloseSwitch_Wakeup_SpoilerCommandDelay_Time = 50U; /*10m x 10 */

const uint16_t K_SpoilerCommandInhibition_Min_Time = 20U; /*10m x 10 */
const uint16_t K_SpoilerSwitch_ShortPress_SpoilerCommandInhibition_Time = 100U; /*10m x 10 */
const uint16_t K_SpoilerOpenSwitch_ShortPress_SpoilerCommandInhibition_Time = 100U; /*10m x 10 */
const uint16_t K_SpoilerCloseSwitch_ShortPress_SpoilerCommandInhibition_Time = 100U; /*10m x 10 */

const uint16_t K_SpoilerPowerOpening_Timeout = 800U; /*10m x 10 */
const uint16_t K_SpoilerPowerClosing_Timeout = 800U; /*10m x 10 */

const uint16_t K_SpoilerOpenEnd_FullOpenSwitchPosition_Compensation = 0U;
const uint16_t K_SpoilerCloseEnd_FullCloseSwitchPosition_Compensation = 0U;
const uint16_t K_SpoilerMiddleEnd_MiddleSwitchPosition_Compensation = 35U;

const uint16_t K_SpoilerFullOpenPosition_Delay_Time = 0U; /*10m x */
const uint16_t K_SpoilerFullClosePosition_Delay_Time = 0U; /*10m x */
const uint16_t K_SpoilerMiddlePosition_Delay_Time = 0U; /*10m x */

const uint16_t K_SpoilerFullOpenSwitchVirtual_HallCount = 1500U;
const uint16_t K_SpoilerFullCloseSwitchVirtual_HallCount = 500U;
const uint16_t K_SpoilerMiddleSwitchVirtual_HallCount = 1200U;
const uint16_t K_SpoilerLearnMiniPosition_HallCount = 1200U;

const uint16_t K_SpoilerMaxPosition_HallCount_Default = 3500U;

const uint16_t K_SpoilerOpenedFully_Timeout = 500U; /*10m x 10 */
const uint16_t K_SpoilerReleased_Timeout = 500U; /*10m x 10 */
const uint16_t K_SpoilerMechFailure_Timeout = 100U; /*10m x 10 */

const uint16_t K_ChangeDutyInSpoilerPowerOpening_1st_Time = 10U; /*10m x 10 */
const uint16_t K_ChangeDutyInSpoilerPowerClosing_1st_Time = 10U; /*10m x 10 */

const uint16_t K_StopBefore_SpoilerPowerOpening_Time = 10U; /*10m x 10 */
const uint16_t K_StopBefore_SpoilerPowerClosing_Time = 10U; /*10m x 10 */

const uint16_t K_SpoilerPowerOpening_Inrush_Time = 10U; /*10m x 10 */
const uint16_t K_SpoilerPowerClosing_Inrush_Time = 10U; /*10m x 10 */

const uint16_t K_Spoiler_ObstacleIndex = 10U;
const uint16_t K_Spoiler_HallCountPerObstacleZone_Min = 150U;
const uint16_t K_Spoiler_HallCountPerObstacleZone_Max = 350U;    
const uint16_t K_Spoiler_HallCountPerObstacleZone_Default = 280U;

const uint16_t K_Spoiler_PowerOpening_HallCount_Delta = 0U;
const uint16_t K_Spoiler_PowerClosing_HallCount_Delta = 0U;

const uint16_t K_Spoiler_EnhancedCurrent_DecreasePerTimer = 5U;    /*10ms x */
const uint16_t K_Spoiler_EnhancedCurrent_Decrease_Time = 2U;       /*10ms x */
const uint16_t K_Spoiler_EnhancedCurrent_IncreasePerTimer = 40U;  /*10ms x */
const uint16_t K_Spoiler_EnhancedCurrent_Increase_Time = 20U;      /*10ms x */
const uint16_t K_Spoiler_EnhancedCurrent_Threshold_Time = 1U;     /*10ms x */

const uint16_t K_Spoiler_SoftStall_Detect_Time = 50U;    /*10ms x */
const uint16_t K_Spoiler_FixedCurrent_Detect_Time = 10U;    /*10ms x */

const uint16_t K_SpoilerHomePosition_Delay_Time = 10U; /*10m x 10 */
const uint16_t K_SpoilerSpreadPosition_Delay_Time = 10U; /*10m x 10 */

const uint16_t K_Spoiler_EnhancedCurrent_Detect_PushPID_Open_Adder[10] = {10,10,10,10,10,10,10,10,10,10};
const uint16_t K_Spoiler_EnhancedCurrent_Detect_PushPID_Close_Adder[10] = {10,10,10,10,10,10,10,10,10,10};
const uint16_t K_Spoiler_SpoilerPowerOpening_Duty[8][8]=
{     
      /* 9v  10v 11v 12v 13v14v15v16v  */
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20}
};
const uint16_t K_Spoiler_SpoilerPowerClosing_Duty[8][8]=
{     
      /* 9v  10v 11v 12v 13v14v15v16v  */
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20}
};

const uint16_t K_Spoiler_PositionObstacle_Detect_Delta = 20U;
const uint16_t K_Spoiler_PositionObstacle_Detect_Open_Timer[10] = {10,10,10,10,10,10,10,10,10,10};
const uint16_t K_Spoiler_PositionObstacle_Detect_Close_Timer[10] = {10,10,10,10,10,10,10,10,10,10};

const uint16_t K_Spoiler_HallPluse1Width_Time = 30U;
const uint16_t K_Spoiler_HallPluse2Width_Time = 30U;

const uint16_t K_Spoiler_SpeedZoneIndex = 20U;
const uint16_t K_Spoiler_HallCountPerSpeedZone_Min = 60U;
const uint16_t K_Spoiler_HallCountPerSpeedZone_Max = 200U;
const uint16_t K_Spoiler_HallCountPerSpeedZone_Default = 90U;

#ifdef _CONFIG_SpoilerMotor_ZWMotor
const uint16_t K_Spoiler_StopFromMaxTravel_HallCount = 20U;
const uint16_t K_SpoilerOpenEnd_SoftStop_HallCount_Compensation = 50U;
const uint16_t K_SpoilerCloseEnd_SoftStop_HallCount_Compensation = 100U;
const uint16_t K_SpoilerMiddleEnd_SoftStop_HallCount_Compensation = 50U;
/* Desired power opening speed value */
const uint16_t K_Spoiler_Desired_Open_Speed[8][20] = 
{
	{14,15,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,15,14},          /*-40degree*/
	{14,15,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,15,14},          /*-25degree*/
	{14,15,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,15,14},          /*-10degree*/
	{14,15,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,15,14},          /*+05degree*/
	{14,15,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,15,14},          /*+20degree*/
	{14,15,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,15,14},          /*+35degree*/
	{14,15,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,15,14},          /*+50degree*/
	{14,15,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,15,14},          /*+65degree*/
};

/* Desired power closing speed value */
const uint16_t K_Spoiler_Desired_Close_Speed[8][20] = 
{
	{14,15,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,15,14},          /*-40degree*/
	{14,15,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,15,14},          /*-25degree*/
	{14,15,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,15,14},          /*-10degree*/
	{14,15,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,15,14},          /*+05degree*/
	{14,15,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,15,14},          /*+20degree*/
	{14,15,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,15,14},          /*+35degree*/
	{14,15,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,15,14},          /*+50degree*/
	{14,15,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,15,14},          /*+65degree*/
};
#endif

#ifdef _CONFIG_SpoilerMotor_JEMotor
const uint16_t K_Spoiler_StopFromMaxTravel_HallCount = 20U;
const uint16_t K_SpoilerOpenEnd_SoftStop_HallCount_Compensation = 50U;
const uint16_t K_SpoilerCloseEnd_SoftStop_HallCount_Compensation = 80U;
const uint16_t K_SpoilerMiddleEnd_SoftStop_HallCount_Compensation = 50U;
/* Desired power opening speed value */
const uint16_t K_Spoiler_Desired_Open_Speed[8][20] = 
{
	{14,15,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,15,14},          /*-40degree*/
	{14,15,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,15,14},          /*-25degree*/
	{14,15,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,15,14},          /*-10degree*/
	{14,15,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,15,14},          /*+05degree*/
	{14,15,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,15,14},          /*+20degree*/
	{14,15,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,15,14},          /*+35degree*/
	{14,15,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,15,14},          /*+50degree*/
	{14,15,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,15,14},          /*+65degree*/
};

/* Desired power closing speed value */
const uint16_t K_Spoiler_Desired_Close_Speed[8][20] = 
{
	{14,15,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,15,14},          /*-40degree*/
	{14,15,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,15,14},          /*-25degree*/
	{14,15,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,15,14},          /*-10degree*/
	{14,15,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,15,14},          /*+05degree*/
	{14,15,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,15,14},          /*+20degree*/
	{14,15,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,15,14},          /*+35degree*/
	{14,15,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,15,14},          /*+50degree*/
	{14,15,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,15,14},          /*+65degree*/
};
#endif

const uint16_t K_Spoiler_FixedVoltage_Open_Enable[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
const uint16_t K_Spoiler_FixedVoltage_Close_Enable[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
const uint16_t K_Spoiler_FixedVoltage_Open_Duty[20] = {60,60,60,60,60,60,60,60,60,60,50,50,50,50,50,50,50,50,50,50};
const uint16_t K_Spoiler_FixedVoltage_Close_Duty[20] = {50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50};
const uint16_t K_Spoiler_FixedVoltage_Open_Timeout[20] = {100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100};
const uint16_t K_Spoiler_FixedVoltage_Close_Timeout[20] = {100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100};

const uint16_t K_Spoiler_PID_PWM_Max_PowerOpening[20] = {100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100};
const uint16_t K_Spoiler_PID_PWM_Max_PowerClosing[20] = {100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100};

const uint16_t K_Spoiler_Opening_IncreaseDuty_Time = 1U; /*10ms x*/
const uint16_t K_Spoiler_Opening_IncreasePerTime_Duty = 2U;
const uint16_t K_Spoiler_Closing_IncreaseDuty_Time = 1U; /*10ms x*/
const uint16_t K_Spoiler_Closing_IncreasePerTime_Duty = 2U; 
const uint16_t K_Spoiler_Opening_Start_Duty[10] = {50,50,50,50,50,50,50,50,50,50};
const uint16_t K_Spoiler_Closing_Start_Duty[10] = {50,50,50,50,50,50,50,50,50,50};
const uint16_t K_Spoiler_SoftStop_Opening_Step_Duty = 5U;
const uint16_t K_Spoiler_SoftStop_Opening_Step_Time = 1U; /* 10ms x 5 */
const uint16_t K_Spoiler_SoftStop_Opening_End_Duty  = 20U;
const uint16_t K_Spoiler_SoftStop_Closing_Step_Duty = 5U;
const uint16_t K_Spoiler_SoftStop_Closing_Step_Time = 1U; /* 10ms x 5 */
const uint16_t K_Spoiler_SoftStop_Closing_End_Duty  = 20U;
const uint16_t K_SpoilerHallObstacle_SoftStop_Time = 100U; /* 10ms x 100 */

const uint16_t K_Spoiler_SoftStart_Opening_HallCount_LowLimit = 0U; /**/
const uint16_t K_Spoiler_SoftStart_Closing_HallCount_LowLimit = 0U;
const uint16_t K_Spoiler_SoftStart_Opening_HallCount_HighLimit = 3500U; /**/
const uint16_t K_Spoiler_SoftStart_Closing_HallCount_HighLimit = 3500U;

const uint16_t K_SpoilerPowerOpening_Speedup_FullOpen_Time = 30U; /* 10ms x */
const uint16_t K_SpoilerPowerClosing_Speedup_FullClose_Time = 30U; /* 10ms x */
const uint16_t K_SpoilerPowerOpening_Speedup_Time = 50U; /* 10ms x */
const uint16_t K_SpoilerPowerClosing_Speedup_Time = 50U; /* 10ms x */
const uint16_t K_SpoilerPowerOpening_HardStart_Time[10] = {60,50,50,30,30,30,30,30,30,30}; /* 10ms x */
const uint16_t K_SpoilerPowerClosing_HardStart_Time[10] = {30,30,30,30,30,30,30,30,30,30}; /* 10ms x */

const uint16_t K_Spoiler_HardStart_Enable = TRUE;
const uint16_t K_Spoiler_Speedup_OpenInLowZone_HallCount = 20U;
const uint16_t K_Spoiler_Speedup_OpenInMiddleZone_HallCount = 20U;
const uint16_t K_Spoiler_Speedup_OpenInHighZone_HallCount = 20U;

const uint16_t K_Spoiler_Speedup_CloseInLowZone_HallCount = 20U;
const uint16_t K_Spoiler_Speedup_CloseInMiddleZone_HallCount = 20U;
const uint16_t K_Spoiler_Speedup_CloseInHighZone_HallCount = 20U;

const uint16_t K_Spoiler_SpeedupInLowZone_HallCount = 100U;   
const uint16_t K_Spoiler_SpeedupInHighZone_HallCount = 2500U; 

const uint16_t K_Spoiler_SpeedupInLowZone_Open_Duty[8][8] = 
{
 	{30,30,30,30,30,30,30,30},   /*-40degree*/
	{30,30,30,30,30,30,30,30},   /*-25degree*/
	{30,30,30,30,30,30,30,30},   /*-10degree*/
	{30,30,30,30,30,30,30,30},   /*+05degree*/
	{30,30,30,30,30,30,30,30},   /*+20degree*/
	{30,30,30,30,30,30,30,30},   /*+35degree*/
	{30,30,30,30,30,30,30,30},   /*+50degree*/
	{30,30,30,30,30,30,30,30}    /*+65degree*/
};

const uint16_t K_Spoiler_SpeedupInLowZone_Close_Duty[8][8] = 
{
	{30,30,30,30,30,30,30,30},   /*-40degree*/
	{30,30,30,30,30,30,30,30},   /*-25degree*/
	{30,30,30,30,30,30,30,30},   /*-10degree*/
	{30,30,30,30,30,30,30,30},   /*+05degree*/
	{30,30,30,30,30,30,30,30},   /*+20degree*/
	{30,30,30,30,30,30,30,30},   /*+35degree*/
	{30,30,30,30,30,30,30,30},   /*+50degree*/
	{30,30,30,30,30,30,30,30}    /*+65degree*/
};

const uint16_t K_Spoiler_SpeedupInMiddleZone_Open_Duty[8][8] = 
{
	{30,30,30,30,30,30,30,30},   /*-40degree*/
	{30,30,30,30,30,30,30,30},   /*-25degree*/
	{30,30,30,30,30,30,30,30},   /*-10degree*/
	{30,30,30,30,30,30,30,30},   /*+05degree*/
	{30,30,30,30,30,30,30,30},   /*+20degree*/
	{30,30,30,30,30,30,30,30},   /*+35degree*/
	{30,30,30,30,30,30,30,30},   /*+50degree*/
	{30,30,30,30,30,30,30,30}    /*+65degree*/
};

const uint16_t K_Spoiler_SpeedupInMiddleZone_Close_Duty[8][8] = 
{
	{30,30,30,30,30,30,30,30},   /*-40degree*/
	{30,30,30,30,30,30,30,30},   /*-25degree*/
	{30,30,30,30,30,30,30,30},   /*-10degree*/
	{30,30,30,30,30,30,30,30},   /*+05degree*/
	{30,30,30,30,30,30,30,30},   /*+20degree*/
	{30,30,30,30,30,30,30,30},   /*+35degree*/
	{30,30,30,30,30,30,30,30},   /*+50degree*/
	{30,30,30,30,30,30,30,30}    /*+65degree*/
};

const uint16_t K_Spoiler_SpeedupInHighZone_Open_Duty[8][8] = 
{
	{30,30,30,30,30,30,30,30},   /*-40degree*/
	{30,30,30,30,30,30,30,30},   /*-25degree*/
	{30,30,30,30,30,30,30,30},   /*-10degree*/
	{30,30,30,30,30,30,30,30},   /*+05degree*/
	{30,30,30,30,30,30,30,30},   /*+20degree*/
	{30,30,30,30,30,30,30,30},   /*+35degree*/
	{30,30,30,30,30,30,30,30},   /*+50degree*/
	{30,30,30,30,30,30,30,30}    /*+65degree*/
};

const uint16_t K_Spoiler_SpeedupInHighZone_Close_Duty[8][8] = 
{
	{30,30,30,30,30,30,30,30},   /*-40degree*/
	{30,30,30,30,30,30,30,30},   /*-25degree*/
	{30,30,30,30,30,30,30,30},   /*-10degree*/
	{30,30,30,30,30,30,30,30},   /*+05degree*/
	{30,30,30,30,30,30,30,30},   /*+20degree*/
	{30,30,30,30,30,30,30,30},   /*+35degree*/
	{30,30,30,30,30,30,30,30},   /*+50degree*/
	{30,30,30,30,30,30,30,30}    /*+65degree*/
};

const uint16_t K_Spoiler_ShortDistanceInOpening_HallCount[10] = {250,250,250,250,250,250,250,250,250,250};
const uint16_t K_Spoiler_ShortDistanceInClosing_HallCount[10] = {100,100,100,100,100,100,100,100,100,100};

const uint16_t K_Spoiler_ObstacleTimes_Continue_Count = 2U;
const uint16_t K_Spoiler_ObstacleTimes_Total_Count = 6U;

const uint16_t K_SpoilerLearned_Position_Default = 2500U;
const uint16_t K_SpoilerFullOpenSwitch_Position_Default = 2500U;
const uint16_t K_SpoilerFullCloseSwitch_Position_Default = 500U;
const uint16_t K_SpoilerMiddleSwitch_Position_Default = 1500U;
const uint16_t K_SpoilerMaxTravel_Position_Default = 3500U;
const uint16_t K_SpoilerMiddlePosition_TravelHallCount_Default = 100U;

const uint16_t K_SpoilerFullOpenSwitch_Position_Open_Delta = 60U;
const uint16_t K_SpoilerFullOpenSwitch_Position_Close_Delta = 0U;
const uint16_t K_Spoiler_LearnNearClosePosition_HallCount = 200U;
const uint16_t K_Spoiler_LearnNearClosePosition_Close_Time = 60U; /* 10ms x */
const uint16_t K_SpoilerFullOpenSwitch_Position_LearnNearClosePosition_Compensation = 20U;
const uint16_t K_SpoilerFullOpenSwitch_Position_LearnFarClosePosition_Compensation = 0U; 
const uint16_t K_SpoilerFullCloseSwitch_Position_LearnNearClosePosition_Compensation = 20U;
const uint16_t K_SpoilerFullCloseSwitch_Position_LearnFarClosePosition_Compensation = 0U;
const uint16_t K_SpoilerMiddleSwitch_Position_LearnNearClosePosition_Compensation = 20U;
const uint16_t K_SpoilerMiddleSwitch_Position_LearnFarClosePosition_Compensation = 0U; 

const uint16_t K_SpoilerFullOpenSwitch_HallEffect_Active_LowLimit = 2800U;/*12V = 2936 TRUE*/
const uint16_t K_SpoilerFullOpenSwitch_HallEffect_Active_HighLimit = 3100U;

const uint16_t K_SpoilerFullOpenSwitch_HallEffect_Inactive_LowLimit = 1400U;/*12V = 1286 FALSE*/
const uint16_t K_SpoilerFullOpenSwitch_HallEffect_Inactive_HighLimit = 1100U;

const uint16_t K_SpoilerFullCloseSwitch_HallEffect_Active_LowLimit = 2800U;/*12V = 2936 TRUE*/
const uint16_t K_SpoilerFullCloseSwitch_HallEffect_Active_HighLimit = 3100U;

const uint16_t K_SpoilerFullCloseSwitch_HallEffect_Inactive_LowLimit = 1400U;/*12V = 1286 FALSE*/
const uint16_t K_SpoilerFullCloseSwitch_HallEffect_Inactive_HighLimit = 1100U;
const uint16_t K_Spoiler_EnhancedCurrent_Detect_Open[8][10] = 
{
	{250,250,200,200,200,200,200,200,200,200},  /*<09V*/
	{250,250,200,200,200,200,200,200,200,200},  /*<10V*/
	{250,250,200,200,200,200,200,200,200,200},  /*<11V*/
	{250,250,200,200,200,200,200,200,200,200},  /*<12V*/
	{250,250,200,200,200,200,200,200,200,200},  /*<13V*/
	{250,250,200,200,200,200,200,200,200,200},  /*<14V*/
	{250,250,200,200,200,200,200,200,200,200},  /*<15V*/
	{250,250,200,200,200,200,200,200,200,200},  /*<16V*/
};

const uint16_t K_Spoiler_EnhancedCurrent_Detect_Open_Temp[8][10] = 
{
	{200,200,200,200,200,200,200,200,200,200},  /*-40degree*/
	{150,150,150,150,150,150,150,150,150,150},   /*-25degree*/
	{50,50,50,50,50,50,50,50,50,50},    /*-10degree*/
	{0,0,0,0,0,0,0,0,0,0},  /*+05degree*/
	{0,0,0,0,0,0,0,0,0,0},   /*+20degree*/
	{50,50,50,50,50,50,50,50,50,50},   /*+35degree*/
	{150,150,150,150,150,150,150,150,150,150},   /*+50degree*/
	{200,200,200,200,200,200,200,200,200,200},   /*+65degree*/
};

const uint16_t K_Spoiler_EnhancedCurrent_Detect_Close[8][10] = 
{
	{250,200,150,150,150,150,150,150,150,150},  /*<09V*/
	{250,200,150,150,150,150,150,150,150,150},  /*<10V*/
	{250,200,150,150,150,150,150,150,150,150},  /*<11V*/
	{250,200,150,150,150,150,150,150,150,150},  /*<12V*/
	{250,200,150,150,150,150,150,150,150,150},  /*<13V*/
	{250,200,150,150,150,150,150,150,150,150},  /*<14V*/
	{250,200,150,150,150,150,150,150,150,150},  /*<15V*/
	{250,200,150,150,150,150,150,150,150,150},  /*<16V*/
};

const uint16_t K_Spoiler_EnhancedCurrent_Detect_Close_Temp[8][10] = 
{
	{200,200,200,200,200,200,200,200,200,200},  /*-40degree*/
	{150,150,150,150,150,150,150,150,150,150},   /*-25degree*/
	{50,50,50,50,50,50,50,50,50,50},    /*-10degree*/
	{0,0,0,0,0,0,0,0,0,0},  /*+05degree*/
	{0,0,0,0,0,0,0,0,0,0},   /*+20degree*/
	{50,50,50,50,50,50,50,50,50,50},   /*+35degree*/
	{150,150,150,150,150,150,150,150,150,150},   /*+50degree*/
	{200,200,200,200,200,200,200,200,200,200},   /*+65degree*/
};
const uint16_t K_Spoiler_SoftStallCurrent_TopLimit[8][8]=
{     
     /* 9v  10v 11v 12v 13v14v15v16v  */
	{800,800,800,800,800,800,800,800},
	{800,800,800,800,800,800,800,800},
	{800,800,800,800,800,800,800,800},
	{800,800,800,800,800,800,800,800},
	{800,800,800,800,800,800,800,800},
	{800,800,800,800,800,800,800,800},
	{800,800,800,800,800,800,800,800},
	{800,800,800,800,800,800,800,800},
};

const uint16_t K_Spoiler_FixedCurrentStall_TopLimit[8][8]=
{     
      /* 9v  10v 11v 12v 13v14v15v16v  */
	{1600,1600,1600,1600,1600,1600,1600,1600},
	{1600,1600,1600,1600,1600,1600,1600,1600},
	{1600,1600,1600,1600,1600,1600,1600,1600},
	{1600,1600,1600,1600,1600,1600,1600,1600},
	{1600,1600,1600,1600,1600,1600,1600,1600},
	{1600,1600,1600,1600,1600,1600,1600,1600},
	{1600,1600,1600,1600,1600,1600,1600,1600},
	{1600,1600,1600,1600,1600,1600,1600,1600},
};
#endif
#ifdef _Spoiler_ChanganC281
/* Spoiler_PID Control - Default */
const uint8_t K_Spoiler_Prop_Open[20] = {30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30};
const uint8_t K_Spoiler_PropScale_Open[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
const uint8_t K_Spoiler_Int_Open[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
const uint8_t K_Spoiler_IntScale_Open[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
const uint8_t K_Spoiler_Diff_Open[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
const uint8_t K_Spoiler_DiffScale_Open[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

const uint8_t K_Spoiler_Prop_Close[20] = {30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30};
const uint8_t K_Spoiler_PropScale_Close[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
const uint8_t K_Spoiler_Int_Close[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
const uint8_t K_Spoiler_IntScale_Close[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
const uint8_t K_Spoiler_Diff_Close[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
const uint8_t K_Spoiler_DiffScale_Close[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

const uint8_t K_Spoiler_Prop_PushPID = 2U;
const uint8_t K_Spoiler_PropScale_PushPID = 1U;
const uint8_t K_Spoiler_Int_PushPID = 1U;
const uint8_t K_Spoiler_IntScale_PushPID = 1U;
const uint8_t K_Spoiler_Diff_PushPID = 1U;
const uint8_t K_Spoiler_DiffScale_PushPID = 1U;

const uint16_t K_Spoiler_PushPID_HallCount = 100U;
const uint16_t K_Spoiler_PushPIDSpeed_Tigger_Delta = 3U;
const uint16_t K_Spoiler_PushPIDSpeed_Quit_Delta = 2U;
const uint16_t K_Spoiler_PushPID_Timeout = 50U; /*20ms x*/
const uint16_t K_Spoiler_PushPID_ObstacleAdder_Timeout = 50U; /*20ms x*/

const uint16_t K_SpoilerPowerOn_Time = 7U; /*10m x 10 */
const uint16_t K_SpoilerWakeUp_Time = 7U; /*10m x 10 */
const uint16_t K_SpoilerReset_Time = 7U; /*10m x 10 */

const uint16_t K_SpoilerPowerOpening_SoftStall_Time = 10U; /*10m x 10 */
const uint16_t K_SpoilerPowerClosing_SoftStall_Time = 10U; /*10m x 10 */

const uint16_t K_SpoilerPowerOpening_ObstacleDetected_Reverse_Enable = TRUE;
const uint16_t K_SpoilerPowerClosing_ObstacleDetected_Reverse_Enable = TRUE;

const uint16_t K_SpoilerSwitch_ShortPress_LowLimit_Time = 5U; /* 50 x 10ms*/
const uint16_t K_SpoilerSwitch_ShortPress_HighLimit_Time = 100U; /* 100 x 10ms*/
const uint16_t K_SpoilerSwitch_LongPress_LowLimit_Time = 100U; /* 300 x 10ms*/
const uint16_t K_SpoilerSwitch_LongPress_HighLimit_Time = 500U; /* 500 x 10ms*/

const uint16_t K_SpoilerSwitch_LongPress_ManualUnlearn_Time = 500U; /* 500 x 10ms*/

const uint16_t K_SpoilerCommandInterval_Time = 50U; /*10m x 10 */

const uint16_t K_CentralLockSwitch_SpoilerCommandInterval_Enable = FALSE;
const uint16_t K_CentralLockSwitch_SpoilerCommandDelay_Time = 0U; /*10m x 10 */
const uint16_t K_CentralLockSwitch_Wakeup_SpoilerCommandDelay_Time = 50U; /*10m x 10 */

const uint16_t K_SpoilerSwitch_SpoilerCommandInterval_Enable = FALSE;
const uint16_t K_SpoilerSwitch_SpoilerCommandDelay_Time = 0U; /*10m x 10 */
const uint16_t K_SpoilerSwitch_Wakeup_SpoilerCommandDelay_Time = 50U; /*10m x 10 */

const uint16_t K_SpoilerCommandInhibition_Min_Time = 20U; /*10m x 10 */
const uint16_t K_SpoilerSwitch_ShortPress_SpoilerCommandInhibition_Time = 100U; /*10m x 10 */

const uint16_t K_SpoilerPowerOpening_Timeout = 800U; /*10m x 10 */
const uint16_t K_SpoilerPowerClosing_Timeout = 800U; /*10m x 10 */

const uint16_t K_Spoiler_StopFromMaxTravel_HallCount = 50U;
const uint16_t K_SpoilerOpenEnd_SoftStop_HallCount_Compensation = 60U;
const uint16_t K_SpoilerCloseEnd_SoftStop_HallCount_Compensation = 60U;
const uint16_t K_SpoilerOpenEnd_FullOpenSwitchPosition_Compensation = 0U;

const uint16_t K_SpoilerFullOpenPosition_Delay_Time = 0U; /*10m x */
const uint16_t K_SpoilerFullClosePosition_Delay_Time = 0U; /*10m x */

const uint16_t K_SpoilerFullOpenSwitchVirtual_HallCount = 2500U;
const uint16_t K_SpoilerFullCloseSwitchVirtual_HallCount = 250U;

const uint16_t K_SpoilerMaxPosition_HallCount_Default = 3500U;

const uint16_t K_SpoilerOpenedFully_Timeout = 500U; /*10m x 10 */
const uint16_t K_SpoilerReleased_Timeout = 500U; /*10m x 10 */
const uint16_t K_SpoilerMechFailure_Timeout = 100U; /*10m x 10 */

const uint16_t K_ChangeDutyInSpoilerPowerOpening_1st_Time = 10U; /*10m x 10 */
const uint16_t K_ChangeDutyInSpoilerPowerClosing_1st_Time = 10U; /*10m x 10 */

const uint16_t K_StopBefore_SpoilerPowerOpening_Time = 10U; /*10m x 10 */
const uint16_t K_StopBefore_SpoilerPowerClosing_Time = 10U; /*10m x 10 */

const uint16_t K_SpoilerPowerOpening_Inrush_Time = 10U; /*10m x 10 */
const uint16_t K_SpoilerPowerClosing_Inrush_Time = 10U; /*10m x 10 */

const uint16_t K_Spoiler_ObstacleIndex = 10U;
const uint16_t K_Spoiler_HallCountPerObstacleZone_Min = 150U;
const uint16_t K_Spoiler_HallCountPerObstacleZone_Max = 350U;    
const uint16_t K_Spoiler_HallCountPerObstacleZone_Default = 280U;

const uint16_t K_Spoiler_PowerOpening_HallCount_Delta = 0U;
const uint16_t K_Spoiler_PowerClosing_HallCount_Delta = 0U;

const uint16_t K_Spoiler_EnhancedCurrent_DecreasePerTimer = 5U;    /*10ms x */
const uint16_t K_Spoiler_EnhancedCurrent_Decrease_Time = 2U;       /*10ms x */
const uint16_t K_Spoiler_EnhancedCurrent_IncreasePerTimer = 40U;  /*10ms x */
const uint16_t K_Spoiler_EnhancedCurrent_Increase_Time = 20U;      /*10ms x */
const uint16_t K_Spoiler_EnhancedCurrent_Threshold_Time = 1U;     /*10ms x */

const uint16_t K_Spoiler_SoftStall_Detect_Time = 50U;    /*10ms x */
const uint16_t K_Spoiler_FixedCurrent_Detect_Time = 10U;    /*10ms x */

const uint16_t K_SpoilerHomePosition_Delay_Time = 10U; /*10m x 10 */
const uint16_t K_SpoilerSpreadPosition_Delay_Time = 10U; /*10m x 10 */

const uint16_t K_Spoiler_EnhancedCurrent_Detect_PushPID_Open_Adder[10] = {10,10,10,10,10,10,10,10,10,10};
const uint16_t K_Spoiler_EnhancedCurrent_Detect_PushPID_Close_Adder[10] = {10,10,10,10,10,10,10,10,10,10};
const uint16_t K_Spoiler_SpoilerPowerOpening_Duty[8][8]=
{     
      /* 9v  10v 11v 12v 13v14v15v16v  */
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20}
};
const uint16_t K_Spoiler_SpoilerPowerClosing_Duty[8][8]=
{     
      /* 9v  10v 11v 12v 13v14v15v16v  */
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20}
};

const uint16_t K_Spoiler_PositionObstacle_Detect_Delta = 20U;
const uint16_t K_Spoiler_PositionObstacle_Detect_Open_Timer[10] = {10,10,10,10,10,10,10,10,10,10};
const uint16_t K_Spoiler_PositionObstacle_Detect_Close_Timer[10] = {10,10,10,10,10,10,10,10,10,10};

const uint16_t K_Spoiler_HallPluse1Width_Time = 30U;
const uint16_t K_Spoiler_HallPluse2Width_Time = 30U;

const uint16_t K_Spoiler_SpeedZoneIndex = 20U;
const uint16_t K_Spoiler_HallCountPerSpeedZone_Min = 80U;
const uint16_t K_Spoiler_HallCountPerSpeedZone_Max = 180U;
const uint16_t K_Spoiler_HallCountPerSpeedZone_Default = 140U;

/* Desired power opening speed value */
const uint16_t K_Spoiler_Desired_Open_Speed[8][20] = 
{
	{15,16,17,18,19,20,20,20,20,20,20,20,20,20,20,20,19,18,17,16},          /*-40degree*/
	{15,16,17,18,19,20,20,20,20,20,20,20,20,20,20,20,19,18,17,16},          /*-25degree*/
	{15,16,17,18,19,20,20,20,20,20,20,20,20,20,20,20,19,18,17,16},          /*-10degree*/
	{15,16,17,18,19,20,20,20,20,20,20,20,20,20,20,20,19,18,17,16},          /*+05degree*/
	{15,16,17,18,19,20,20,20,20,20,20,20,20,20,20,20,19,18,17,16},          /*+20degree*/
	{15,16,17,18,19,20,20,20,20,20,20,20,20,20,20,20,19,18,17,16},          /*+35degree*/
	{15,16,17,18,19,20,20,20,20,20,20,20,20,20,20,20,19,18,17,16},          /*+50degree*/
	{15,16,17,18,19,20,20,20,20,20,20,20,20,20,20,20,19,18,17,16},          /*+65degree*/
};

/* Desired power closing speed value */
const uint16_t K_Spoiler_Desired_Close_Speed[8][20] = 
{
	{15,16,17,18,19,20,20,20,20,20,20,20,20,20,20,20,19,18,17,16},          /*-40degree*/
	{15,16,17,18,19,20,20,20,20,20,20,20,20,20,20,20,19,18,17,16},          /*-25degree*/
	{15,16,17,18,19,20,20,20,20,20,20,20,20,20,20,20,19,18,17,16},          /*-10degree*/
	{15,16,17,18,19,20,20,20,20,20,20,20,20,20,20,20,19,18,17,16},          /*+05degree*/
	{15,16,17,18,19,20,20,20,20,20,20,20,20,20,20,20,19,18,17,16},          /*+20degree*/
	{15,16,17,18,19,20,20,20,20,20,20,20,20,20,20,20,19,18,17,16},          /*+35degree*/
	{15,16,17,18,19,20,20,20,20,20,20,20,20,20,20,20,19,18,17,16},          /*+50degree*/
	{15,16,17,18,19,20,20,20,20,20,20,20,20,20,20,20,19,18,17,16},           /*+65degree*/
};
const uint16_t K_Spoiler_FixedVoltage_Open_Enable[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
const uint16_t K_Spoiler_FixedVoltage_Close_Enable[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
const uint16_t K_Spoiler_FixedVoltage_Open_Duty[20] = {60,60,60,60,60,60,60,60,60,60,50,50,50,50,50,50,50,50,50,50};
const uint16_t K_Spoiler_FixedVoltage_Close_Duty[20] = {50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50};
const uint16_t K_Spoiler_FixedVoltage_Open_Timeout[20] = {100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100};
const uint16_t K_Spoiler_FixedVoltage_Close_Timeout[20] = {100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100};

const uint16_t K_Spoiler_PID_PWM_Max_PowerOpening[20] = {100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100};
const uint16_t K_Spoiler_PID_PWM_Max_PowerClosing[20] = {100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100};

const uint16_t K_Spoiler_Opening_IncreaseDuty_Time = 1U; /*10ms x*/
const uint16_t K_Spoiler_Opening_IncreasePerTime_Duty = 2U;
const uint16_t K_Spoiler_Closing_IncreaseDuty_Time = 1U; /*10ms x*/
const uint16_t K_Spoiler_Closing_IncreasePerTime_Duty = 2U; 
const uint16_t K_Spoiler_Opening_Start_Duty[10] = {20,20,20,20,20,20,20,20,20,20};
const uint16_t K_Spoiler_Closing_Start_Duty[10] = {20,20,20,20,20,20,20,20,20,20};
const uint16_t K_Spoiler_SoftStop_Opening_Step_Duty = 2U;
const uint16_t K_Spoiler_SoftStop_Opening_Step_Time = 1U; /* 10ms x 5 */
const uint16_t K_Spoiler_SoftStop_Opening_End_Duty  = 10U;
const uint16_t K_Spoiler_SoftStop_Closing_Step_Duty = 2U;
const uint16_t K_Spoiler_SoftStop_Closing_Step_Time = 1U; /* 10ms x 5 */
const uint16_t K_Spoiler_SoftStop_Closing_End_Duty  = 10U;
const uint16_t K_SpoilerHallObstacle_SoftStop_Time = 100U; /* 10ms x 100 */

const uint16_t K_Spoiler_SoftStart_Opening_HallCount_LowLimit = 0U; /**/
const uint16_t K_Spoiler_SoftStart_Closing_HallCount_LowLimit = 0U;
const uint16_t K_Spoiler_SoftStart_Opening_HallCount_HighLimit = 3500U; /**/
const uint16_t K_Spoiler_SoftStart_Closing_HallCount_HighLimit = 3500U;

const uint16_t K_SpoilerPowerOpening_Speedup_FullOpen_Time = 30U; /* 10ms x */
const uint16_t K_SpoilerPowerClosing_Speedup_FullClose_Time = 30U; /* 10ms x */
const uint16_t K_SpoilerPowerOpening_Speedup_Time = 50U; /* 10ms x */
const uint16_t K_SpoilerPowerClosing_Speedup_Time = 50U; /* 10ms x */
const uint16_t K_SpoilerPowerOpening_HardStart_Time[10] = {60,50,50,30,30,30,30,30,30,30}; /* 10ms x */
const uint16_t K_SpoilerPowerClosing_HardStart_Time[10] = {30,30,30,30,30,30,30,30,30,30}; /* 10ms x */

const uint16_t K_Spoiler_HardStart_Enable = TRUE;
const uint16_t K_Spoiler_Speedup_OpenInLowZone_HallCount = 20U;
const uint16_t K_Spoiler_Speedup_OpenInMiddleZone_HallCount = 20U;
const uint16_t K_Spoiler_Speedup_OpenInHighZone_HallCount = 20U;

const uint16_t K_Spoiler_Speedup_CloseInLowZone_HallCount = 20U;
const uint16_t K_Spoiler_Speedup_CloseInMiddleZone_HallCount = 20U;
const uint16_t K_Spoiler_Speedup_CloseInHighZone_HallCount = 20U;

const uint16_t K_Spoiler_SpeedupInLowZone_HallCount = 100U;   
const uint16_t K_Spoiler_SpeedupInHighZone_HallCount = 2500U; 

const uint16_t K_Spoiler_SpeedupInLowZone_Open_Duty[8][8] = 
{
 	{30,30,30,30,30,30,30,30},   /*-40degree*/
	{30,30,30,30,30,30,30,30},   /*-25degree*/
	{30,30,30,30,30,30,30,30},   /*-10degree*/
	{30,30,30,30,30,30,30,30},   /*+05degree*/
	{30,30,30,30,30,30,30,30},   /*+20degree*/
	{30,30,30,30,30,30,30,30},   /*+35degree*/
	{30,30,30,30,30,30,30,30},   /*+50degree*/
	{30,30,30,30,30,30,30,30}    /*+65degree*/
};

const uint16_t K_Spoiler_SpeedupInLowZone_Close_Duty[8][8] = 
{
	{30,30,30,30,30,30,30,30},   /*-40degree*/
	{30,30,30,30,30,30,30,30},   /*-25degree*/
	{30,30,30,30,30,30,30,30},   /*-10degree*/
	{30,30,30,30,30,30,30,30},   /*+05degree*/
	{30,30,30,30,30,30,30,30},   /*+20degree*/
	{30,30,30,30,30,30,30,30},   /*+35degree*/
	{30,30,30,30,30,30,30,30},   /*+50degree*/
	{30,30,30,30,30,30,30,30}    /*+65degree*/
};

const uint16_t K_Spoiler_SpeedupInMiddleZone_Open_Duty[8][8] = 
{
	{30,30,30,30,30,30,30,30},   /*-40degree*/
	{30,30,30,30,30,30,30,30},   /*-25degree*/
	{30,30,30,30,30,30,30,30},   /*-10degree*/
	{30,30,30,30,30,30,30,30},   /*+05degree*/
	{30,30,30,30,30,30,30,30},   /*+20degree*/
	{30,30,30,30,30,30,30,30},   /*+35degree*/
	{30,30,30,30,30,30,30,30},   /*+50degree*/
	{30,30,30,30,30,30,30,30}    /*+65degree*/
};

const uint16_t K_Spoiler_SpeedupInMiddleZone_Close_Duty[8][8] = 
{
	{30,30,30,30,30,30,30,30},   /*-40degree*/
	{30,30,30,30,30,30,30,30},   /*-25degree*/
	{30,30,30,30,30,30,30,30},   /*-10degree*/
	{30,30,30,30,30,30,30,30},   /*+05degree*/
	{30,30,30,30,30,30,30,30},   /*+20degree*/
	{30,30,30,30,30,30,30,30},   /*+35degree*/
	{30,30,30,30,30,30,30,30},   /*+50degree*/
	{30,30,30,30,30,30,30,30}    /*+65degree*/
};

const uint16_t K_Spoiler_SpeedupInHighZone_Open_Duty[8][8] = 
{
	{30,30,30,30,30,30,30,30},   /*-40degree*/
	{30,30,30,30,30,30,30,30},   /*-25degree*/
	{30,30,30,30,30,30,30,30},   /*-10degree*/
	{30,30,30,30,30,30,30,30},   /*+05degree*/
	{30,30,30,30,30,30,30,30},   /*+20degree*/
	{30,30,30,30,30,30,30,30},   /*+35degree*/
	{30,30,30,30,30,30,30,30},   /*+50degree*/
	{30,30,30,30,30,30,30,30}    /*+65degree*/
};

const uint16_t K_Spoiler_SpeedupInHighZone_Close_Duty[8][8] = 
{
	{30,30,30,30,30,30,30,30},   /*-40degree*/
	{30,30,30,30,30,30,30,30},   /*-25degree*/
	{30,30,30,30,30,30,30,30},   /*-10degree*/
	{30,30,30,30,30,30,30,30},   /*+05degree*/
	{30,30,30,30,30,30,30,30},   /*+20degree*/
	{30,30,30,30,30,30,30,30},   /*+35degree*/
	{30,30,30,30,30,30,30,30},   /*+50degree*/
	{30,30,30,30,30,30,30,30}    /*+65degree*/
};

const uint16_t K_Spoiler_ShortDistanceInOpening_HallCount[10] = {250,250,250,250,250,250,250,250,250,250};
const uint16_t K_Spoiler_ShortDistanceInClosing_HallCount[10] = {100,100,100,100,100,100,100,100,100,100};

const uint16_t K_Spoiler_ObstacleTimes_Continue_Count = 2U;
const uint16_t K_Spoiler_ObstacleTimes_Total_Count = 6U;

const uint16_t K_SpoilerLearned_Position_Default = 2500U;
const uint16_t K_SpoilerFullOpenSwitch_Position_Default = 2500U;
const uint16_t K_SpoilerMaxTravel_Position_Default = 3500U;

const uint16_t K_SpoilerFullOpenSwitch_Position_Open_Delta = 0U;
const uint16_t K_SpoilerFullOpenSwitch_Position_Close_Delta = 0U;
const uint16_t K_Spoiler_LearnNearClosePosition_HallCount = 200U;
const uint16_t K_Spoiler_LearnNearClosePosition_Close_Time = 60U; /* 10ms x */
const uint16_t K_SpoilerFullOpenSwitch_Position_LearnNearClosePosition_Compensation = 50U;
const uint16_t K_SpoilerFullOpenSwitch_Position_LearnFarClosePosition_Compensation = 0U; 

const uint16_t K_SpoilerFullOpenSwitch_HallEffect_Active_LowLimit = 2800U;/*12V = 2936 TRUE*/
const uint16_t K_SpoilerFullOpenSwitch_HallEffect_Active_HighLimit = 3100U;

const uint16_t K_SpoilerFullOpenSwitch_HallEffect_Inactive_LowLimit = 1400U;/*12V = 1286 FALSE*/
const uint16_t K_SpoilerFullOpenSwitch_HallEffect_Inactive_HighLimit = 1100U;

const uint16_t K_SpoilerFullCloseSwitch_HallEffect_Active_LowLimit = 2800U;/*12V = 2936 TRUE*/
const uint16_t K_SpoilerFullCloseSwitch_HallEffect_Active_HighLimit = 3100U;

const uint16_t K_SpoilerFullCloseSwitch_HallEffect_Inactive_LowLimit = 1400U;/*12V = 1286 FALSE*/
const uint16_t K_SpoilerFullCloseSwitch_HallEffect_Inactive_HighLimit = 1100U;
const uint16_t K_Spoiler_EnhancedCurrent_Detect_Open[8][10] = 
{
	{250,250,200,200,200,200,200,200,200,200},  /*<09V*/
	{250,250,200,200,200,200,200,200,200,200},  /*<10V*/
	{250,250,200,200,200,200,200,200,200,200},  /*<11V*/
	{250,250,200,200,200,200,200,200,200,200},  /*<12V*/
	{250,250,200,200,200,200,200,200,200,200},  /*<13V*/
	{250,250,200,200,200,200,200,200,200,200},  /*<14V*/
	{250,250,200,200,200,200,200,200,200,200},  /*<15V*/
	{250,250,200,200,200,200,200,200,200,200},  /*<16V*/
};

const uint16_t K_Spoiler_EnhancedCurrent_Detect_Open_Temp[8][10] = 
{
	{200,200,200,200,200,200,200,200,200,200},  /*-40degree*/
	{150,150,150,150,150,150,150,150,150,150},   /*-25degree*/
	{50,50,50,50,50,50,50,50,50,50},    /*-10degree*/
	{0,0,0,0,0,0,0,0,0,0},  /*+05degree*/
	{0,0,0,0,0,0,0,0,0,0},   /*+20degree*/
	{50,50,50,50,50,50,50,50,50,50},   /*+35degree*/
	{150,150,150,150,150,150,150,150,150,150},   /*+50degree*/
	{200,200,200,200,200,200,200,200,200,200},   /*+65degree*/
};

const uint16_t K_Spoiler_EnhancedCurrent_Detect_Close[8][10] = 
{
	{250,250,200,200,200,200,200,200,200,200},  /*<09V*/
	{250,250,200,200,200,200,200,200,200,200},  /*<10V*/
	{250,250,200,200,200,200,200,200,200,200},  /*<11V*/
	{250,250,200,200,200,200,200,200,200,200},  /*<12V*/
	{250,250,200,200,200,200,200,200,200,200},  /*<13V*/
	{250,250,200,200,200,200,200,200,200,200},  /*<14V*/
	{250,250,200,200,200,200,200,200,200,200},  /*<15V*/
	{250,250,200,200,200,200,200,200,200,200},  /*<16V*/
};

const uint16_t K_Spoiler_EnhancedCurrent_Detect_Close_Temp[8][10] = 
{
	{200,200,200,200,200,200,200,200,200,200},  /*-40degree*/
	{150,150,150,150,150,150,150,150,150,150},   /*-25degree*/
	{50,50,50,50,50,50,50,50,50,50},    /*-10degree*/
	{0,0,0,0,0,0,0,0,0,0},  /*+05degree*/
	{0,0,0,0,0,0,0,0,0,0},   /*+20degree*/
	{50,50,50,50,50,50,50,50,50,50},   /*+35degree*/
	{150,150,150,150,150,150,150,150,150,150},   /*+50degree*/
	{200,200,200,200,200,200,200,200,200,200},   /*+65degree*/
};
const uint16_t K_Spoiler_SoftStallCurrent_TopLimit[8][8]=
{     
     /* 9v  10v 11v 12v 13v14v15v16v  */
	{800,800,800,800,800,800,800,800},
	{800,800,800,800,800,800,800,800},
	{800,800,800,800,800,800,800,800},
	{800,800,800,800,800,800,800,800},
	{800,800,800,800,800,800,800,800},
	{800,800,800,800,800,800,800,800},
	{800,800,800,800,800,800,800,800},
	{800,800,800,800,800,800,800,800},
};

const uint16_t K_Spoiler_FixedCurrentStall_TopLimit[8][8]=
{     
      /* 9v  10v 11v 12v 13v14v15v16v  */
	{1600,1600,1600,1600,1600,1600,1600,1600},
	{1600,1600,1600,1600,1600,1600,1600,1600},
	{1600,1600,1600,1600,1600,1600,1600,1600},
	{1600,1600,1600,1600,1600,1600,1600,1600},
	{1600,1600,1600,1600,1600,1600,1600,1600},
	{1600,1600,1600,1600,1600,1600,1600,1600},
	{1600,1600,1600,1600,1600,1600,1600,1600},
	{1600,1600,1600,1600,1600,1600,1600,1600},
};
#endif
#ifdef _Spoiler_AudiBenchmark
/* Spoiler_PID Control - Default */
const uint8_t K_Spoiler_Prop_Open[20] = {30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30};
const uint8_t K_Spoiler_PropScale_Open[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
const uint8_t K_Spoiler_Int_Open[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
const uint8_t K_Spoiler_IntScale_Open[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
const uint8_t K_Spoiler_Diff_Open[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
const uint8_t K_Spoiler_DiffScale_Open[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

const uint8_t K_Spoiler_Prop_Close[20] = {30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30};
const uint8_t K_Spoiler_PropScale_Close[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
const uint8_t K_Spoiler_Int_Close[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
const uint8_t K_Spoiler_IntScale_Close[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
const uint8_t K_Spoiler_Diff_Close[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
const uint8_t K_Spoiler_DiffScale_Close[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

const uint8_t K_Spoiler_Prop_PushPID = 2U;
const uint8_t K_Spoiler_PropScale_PushPID = 1U;
const uint8_t K_Spoiler_Int_PushPID = 1U;
const uint8_t K_Spoiler_IntScale_PushPID = 1U;
const uint8_t K_Spoiler_Diff_PushPID = 1U;
const uint8_t K_Spoiler_DiffScale_PushPID = 1U;

const uint16_t K_Spoiler_PushPID_HallCount = 100U;
const uint16_t K_Spoiler_PushPIDSpeed_Tigger_Delta = 3U;
const uint16_t K_Spoiler_PushPIDSpeed_Quit_Delta = 2U;
const uint16_t K_Spoiler_PushPID_Timeout = 50U; /*20ms x*/
const uint16_t K_Spoiler_PushPID_ObstacleAdder_Timeout = 50U; /*20ms x*/

const uint16_t K_SpoilerPowerOn_Time = 7U; /*10m x 10 */
const uint16_t K_SpoilerWakeUp_Time = 7U; /*10m x 10 */
const uint16_t K_SpoilerReset_Time = 7U; /*10m x 10 */

const uint16_t K_SpoilerPowerOpening_SoftStall_Time = 10U; /*10m x 10 */
const uint16_t K_SpoilerPowerClosing_SoftStall_Time = 10U; /*10m x 10 */

const uint16_t K_SpoilerPowerOpening_ObstacleDetected_Reverse_Enable = TRUE;
const uint16_t K_SpoilerPowerClosing_ObstacleDetected_Reverse_Enable = TRUE;

const uint16_t K_SpoilerSwitch_ShortPress_LowLimit_Time = 5U; /* 50 x 10ms*/
const uint16_t K_SpoilerSwitch_ShortPress_HighLimit_Time = 100U; /* 100 x 10ms*/
const uint16_t K_SpoilerSwitch_LongPress_LowLimit_Time = 100U; /* 300 x 10ms*/
const uint16_t K_SpoilerSwitch_LongPress_HighLimit_Time = 500U; /* 500 x 10ms*/

const uint16_t K_SpoilerSwitch_LongPress_ManualUnlearn_Time = 500U; /* 500 x 10ms*/

const uint16_t K_SpoilerCommandInterval_Time = 50U; /*10m x 10 */

const uint16_t K_CentralLockSwitch_SpoilerCommandInterval_Enable = FALSE;
const uint16_t K_CentralLockSwitch_SpoilerCommandDelay_Time = 0U; /*10m x 10 */
const uint16_t K_CentralLockSwitch_Wakeup_SpoilerCommandDelay_Time = 50U; /*10m x 10 */

const uint16_t K_SpoilerSwitch_SpoilerCommandInterval_Enable = FALSE;
const uint16_t K_SpoilerSwitch_SpoilerCommandDelay_Time = 0U; /*10m x 10 */
const uint16_t K_SpoilerSwitch_Wakeup_SpoilerCommandDelay_Time = 50U; /*10m x 10 */

const uint16_t K_SpoilerCommandInhibition_Min_Time = 20U; /*10m x 10 */
const uint16_t K_SpoilerSwitch_ShortPress_SpoilerCommandInhibition_Time = 100U; /*10m x 10 */

const uint16_t K_SpoilerPowerOpening_Timeout = 800U; /*10m x 10 */
const uint16_t K_SpoilerPowerClosing_Timeout = 800U; /*10m x 10 */

const uint16_t K_Spoiler_StopFromMaxTravel_HallCount = 50U;
const uint16_t K_SpoilerOpenEnd_SoftStop_HallCount_Compensation = 60U;
const uint16_t K_SpoilerCloseEnd_SoftStop_HallCount_Compensation = 60U;
const uint16_t K_SpoilerOpenEnd_FullOpenSwitchPosition_Compensation = 0U;

const uint16_t K_SpoilerFullOpenPosition_Delay_Time = 0U; /*10m x */
const uint16_t K_SpoilerFullClosePosition_Delay_Time = 0U; /*10m x */

const uint16_t K_SpoilerFullOpenSwitchVirtual_HallCount = 2500U;
const uint16_t K_SpoilerFullCloseSwitchVirtual_HallCount = 250U;

const uint16_t K_SpoilerMaxPosition_HallCount_Default = 3500U;

const uint16_t K_SpoilerOpenedFully_Timeout = 500U; /*10m x 10 */
const uint16_t K_SpoilerReleased_Timeout = 500U; /*10m x 10 */
const uint16_t K_SpoilerMechFailure_Timeout = 100U; /*10m x 10 */

const uint16_t K_ChangeDutyInSpoilerPowerOpening_1st_Time = 10U; /*10m x 10 */
const uint16_t K_ChangeDutyInSpoilerPowerClosing_1st_Time = 10U; /*10m x 10 */

const uint16_t K_StopBefore_SpoilerPowerOpening_Time = 10U; /*10m x 10 */
const uint16_t K_StopBefore_SpoilerPowerClosing_Time = 10U; /*10m x 10 */

const uint16_t K_SpoilerPowerOpening_Inrush_Time = 10U; /*10m x 10 */
const uint16_t K_SpoilerPowerClosing_Inrush_Time = 10U; /*10m x 10 */

const uint16_t K_Spoiler_ObstacleIndex = 10U;
const uint16_t K_Spoiler_HallCountPerObstacleZone_Min = 150U;
const uint16_t K_Spoiler_HallCountPerObstacleZone_Max = 350U;    
const uint16_t K_Spoiler_HallCountPerObstacleZone_Default = 280U;

const uint16_t K_Spoiler_PowerOpening_HallCount_Delta = 0U;
const uint16_t K_Spoiler_PowerClosing_HallCount_Delta = 0U;

const uint16_t K_Spoiler_EnhancedCurrent_DecreasePerTimer = 5U;    /*10ms x */
const uint16_t K_Spoiler_EnhancedCurrent_Decrease_Time = 2U;       /*10ms x */
const uint16_t K_Spoiler_EnhancedCurrent_IncreasePerTimer = 40U;  /*10ms x */
const uint16_t K_Spoiler_EnhancedCurrent_Increase_Time = 20U;      /*10ms x */
const uint16_t K_Spoiler_EnhancedCurrent_Threshold_Time = 1U;     /*10ms x */

const uint16_t K_Spoiler_SoftStall_Detect_Time = 50U;    /*10ms x */
const uint16_t K_Spoiler_FixedCurrent_Detect_Time = 10U;    /*10ms x */

const uint16_t K_SpoilerHomePosition_Delay_Time = 10U; /*10m x 10 */
const uint16_t K_SpoilerSpreadPosition_Delay_Time = 10U; /*10m x 10 */

const uint16_t K_Spoiler_EnhancedCurrent_Detect_PushPID_Open_Adder[10] = {10,10,10,10,10,10,10,10,10,10};
const uint16_t K_Spoiler_EnhancedCurrent_Detect_PushPID_Close_Adder[10] = {10,10,10,10,10,10,10,10,10,10};
const uint16_t K_Spoiler_SpoilerPowerOpening_Duty[8][8]=
{     
      /* 9v  10v 11v 12v 13v14v15v16v  */
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20}
};
const uint16_t K_Spoiler_SpoilerPowerClosing_Duty[8][8]=
{     
      /* 9v  10v 11v 12v 13v14v15v16v  */
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20}
};

const uint16_t K_Spoiler_PositionObstacle_Detect_Delta = 20U;
const uint16_t K_Spoiler_PositionObstacle_Detect_Open_Timer[10] = {10,10,10,10,10,10,10,10,10,10};
const uint16_t K_Spoiler_PositionObstacle_Detect_Close_Timer[10] = {10,10,10,10,10,10,10,10,10,10};

const uint16_t K_Spoiler_HallPluse1Width_Time = 30U;
const uint16_t K_Spoiler_HallPluse2Width_Time = 30U;

const uint16_t K_Spoiler_SpeedZoneIndex = 20U;
const uint16_t K_Spoiler_HallCountPerSpeedZone_Min = 80U;
const uint16_t K_Spoiler_HallCountPerSpeedZone_Max = 180U;
const uint16_t K_Spoiler_HallCountPerSpeedZone_Default = 140U;

/* Desired power opening speed value */
const uint16_t K_Spoiler_Desired_Open_Speed[8][20] = 
{
	{15,16,17,18,19,20,20,20,20,20,20,20,20,20,20,20,19,18,17,16},          /*-40degree*/
	{15,16,17,18,19,20,20,20,20,20,20,20,20,20,20,20,19,18,17,16},          /*-25degree*/
	{15,16,17,18,19,20,20,20,20,20,20,20,20,20,20,20,19,18,17,16},          /*-10degree*/
	{15,16,17,18,19,20,20,20,20,20,20,20,20,20,20,20,19,18,17,16},          /*+05degree*/
	{15,16,17,18,19,20,20,20,20,20,20,20,20,20,20,20,19,18,17,16},          /*+20degree*/
	{15,16,17,18,19,20,20,20,20,20,20,20,20,20,20,20,19,18,17,16},          /*+35degree*/
	{15,16,17,18,19,20,20,20,20,20,20,20,20,20,20,20,19,18,17,16},          /*+50degree*/
	{15,16,17,18,19,20,20,20,20,20,20,20,20,20,20,20,19,18,17,16},          /*+65degree*/
};

/* Desired power closing speed value */
const uint16_t K_Spoiler_Desired_Close_Speed[8][20] = 
{
	{15,16,17,18,19,20,20,20,20,20,20,20,20,20,20,20,19,18,17,16},          /*-40degree*/
	{15,16,17,18,19,20,20,20,20,20,20,20,20,20,20,20,19,18,17,16},          /*-25degree*/
	{15,16,17,18,19,20,20,20,20,20,20,20,20,20,20,20,19,18,17,16},          /*-10degree*/
	{15,16,17,18,19,20,20,20,20,20,20,20,20,20,20,20,19,18,17,16},          /*+05degree*/
	{15,16,17,18,19,20,20,20,20,20,20,20,20,20,20,20,19,18,17,16},          /*+20degree*/
	{15,16,17,18,19,20,20,20,20,20,20,20,20,20,20,20,19,18,17,16},          /*+35degree*/
	{15,16,17,18,19,20,20,20,20,20,20,20,20,20,20,20,19,18,17,16},          /*+50degree*/
	{15,16,17,18,19,20,20,20,20,20,20,20,20,20,20,20,19,18,17,16},           /*+65degree*/
};
const uint16_t K_Spoiler_FixedVoltage_Open_Enable[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
const uint16_t K_Spoiler_FixedVoltage_Close_Enable[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
const uint16_t K_Spoiler_FixedVoltage_Open_Duty[20] = {60,60,60,60,60,60,60,60,60,60,50,50,50,50,50,50,50,50,50,50};
const uint16_t K_Spoiler_FixedVoltage_Close_Duty[20] = {50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50};
const uint16_t K_Spoiler_FixedVoltage_Open_Timeout[20] = {100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100};
const uint16_t K_Spoiler_FixedVoltage_Close_Timeout[20] = {100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100};

const uint16_t K_Spoiler_PID_PWM_Max_PowerOpening[20] = {100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100};
const uint16_t K_Spoiler_PID_PWM_Max_PowerClosing[20] = {100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100};

const uint16_t K_Spoiler_Opening_IncreaseDuty_Time = 1U; /*10ms x*/
const uint16_t K_Spoiler_Opening_IncreasePerTime_Duty = 2U;
const uint16_t K_Spoiler_Closing_IncreaseDuty_Time = 1U; /*10ms x*/
const uint16_t K_Spoiler_Closing_IncreasePerTime_Duty = 2U; 
const uint16_t K_Spoiler_Opening_Start_Duty[10] = {20,20,20,20,20,20,20,20,20,20};
const uint16_t K_Spoiler_Closing_Start_Duty[10] = {20,20,20,20,20,20,20,20,20,20};
const uint16_t K_Spoiler_SoftStop_Opening_Step_Duty = 2U;
const uint16_t K_Spoiler_SoftStop_Opening_Step_Time = 1U; /* 10ms x 5 */
const uint16_t K_Spoiler_SoftStop_Opening_End_Duty  = 10U;
const uint16_t K_Spoiler_SoftStop_Closing_Step_Duty = 2U;
const uint16_t K_Spoiler_SoftStop_Closing_Step_Time = 1U; /* 10ms x 5 */
const uint16_t K_Spoiler_SoftStop_Closing_End_Duty  = 10U;
const uint16_t K_SpoilerHallObstacle_SoftStop_Time = 100U; /* 10ms x 100 */

const uint16_t K_Spoiler_SoftStart_Opening_HallCount_LowLimit = 0U; /**/
const uint16_t K_Spoiler_SoftStart_Closing_HallCount_LowLimit = 0U;
const uint16_t K_Spoiler_SoftStart_Opening_HallCount_HighLimit = 3500U; /**/
const uint16_t K_Spoiler_SoftStart_Closing_HallCount_HighLimit = 3500U;

const uint16_t K_SpoilerPowerOpening_Speedup_FullOpen_Time = 30U; /* 10ms x */
const uint16_t K_SpoilerPowerClosing_Speedup_FullClose_Time = 30U; /* 10ms x */
const uint16_t K_SpoilerPowerOpening_Speedup_Time = 50U; /* 10ms x */
const uint16_t K_SpoilerPowerClosing_Speedup_Time = 50U; /* 10ms x */
const uint16_t K_SpoilerPowerOpening_HardStart_Time[10] = {60,50,50,30,30,30,30,30,30,30}; /* 10ms x */
const uint16_t K_SpoilerPowerClosing_HardStart_Time[10] = {30,30,30,30,30,30,30,30,30,30}; /* 10ms x */

const uint16_t K_Spoiler_HardStart_Enable = TRUE;
const uint16_t K_Spoiler_Speedup_OpenInLowZone_HallCount = 20U;
const uint16_t K_Spoiler_Speedup_OpenInMiddleZone_HallCount = 20U;
const uint16_t K_Spoiler_Speedup_OpenInHighZone_HallCount = 20U;

const uint16_t K_Spoiler_Speedup_CloseInLowZone_HallCount = 20U;
const uint16_t K_Spoiler_Speedup_CloseInMiddleZone_HallCount = 20U;
const uint16_t K_Spoiler_Speedup_CloseInHighZone_HallCount = 20U;

const uint16_t K_Spoiler_SpeedupInLowZone_HallCount = 100U;   
const uint16_t K_Spoiler_SpeedupInHighZone_HallCount = 2500U; 

const uint16_t K_Spoiler_SpeedupInLowZone_Open_Duty[8][8] = 
{
 	{30,30,30,30,30,30,30,30},   /*-40degree*/
	{30,30,30,30,30,30,30,30},   /*-25degree*/
	{30,30,30,30,30,30,30,30},   /*-10degree*/
	{30,30,30,30,30,30,30,30},   /*+05degree*/
	{30,30,30,30,30,30,30,30},   /*+20degree*/
	{30,30,30,30,30,30,30,30},   /*+35degree*/
	{30,30,30,30,30,30,30,30},   /*+50degree*/
	{30,30,30,30,30,30,30,30}    /*+65degree*/
};

const uint16_t K_Spoiler_SpeedupInLowZone_Close_Duty[8][8] = 
{
	{30,30,30,30,30,30,30,30},   /*-40degree*/
	{30,30,30,30,30,30,30,30},   /*-25degree*/
	{30,30,30,30,30,30,30,30},   /*-10degree*/
	{30,30,30,30,30,30,30,30},   /*+05degree*/
	{30,30,30,30,30,30,30,30},   /*+20degree*/
	{30,30,30,30,30,30,30,30},   /*+35degree*/
	{30,30,30,30,30,30,30,30},   /*+50degree*/
	{30,30,30,30,30,30,30,30}    /*+65degree*/
};

const uint16_t K_Spoiler_SpeedupInMiddleZone_Open_Duty[8][8] = 
{
	{30,30,30,30,30,30,30,30},   /*-40degree*/
	{30,30,30,30,30,30,30,30},   /*-25degree*/
	{30,30,30,30,30,30,30,30},   /*-10degree*/
	{30,30,30,30,30,30,30,30},   /*+05degree*/
	{30,30,30,30,30,30,30,30},   /*+20degree*/
	{30,30,30,30,30,30,30,30},   /*+35degree*/
	{30,30,30,30,30,30,30,30},   /*+50degree*/
	{30,30,30,30,30,30,30,30}    /*+65degree*/
};

const uint16_t K_Spoiler_SpeedupInMiddleZone_Close_Duty[8][8] = 
{
	{30,30,30,30,30,30,30,30},   /*-40degree*/
	{30,30,30,30,30,30,30,30},   /*-25degree*/
	{30,30,30,30,30,30,30,30},   /*-10degree*/
	{30,30,30,30,30,30,30,30},   /*+05degree*/
	{30,30,30,30,30,30,30,30},   /*+20degree*/
	{30,30,30,30,30,30,30,30},   /*+35degree*/
	{30,30,30,30,30,30,30,30},   /*+50degree*/
	{30,30,30,30,30,30,30,30}    /*+65degree*/
};

const uint16_t K_Spoiler_SpeedupInHighZone_Open_Duty[8][8] = 
{
	{30,30,30,30,30,30,30,30},   /*-40degree*/
	{30,30,30,30,30,30,30,30},   /*-25degree*/
	{30,30,30,30,30,30,30,30},   /*-10degree*/
	{30,30,30,30,30,30,30,30},   /*+05degree*/
	{30,30,30,30,30,30,30,30},   /*+20degree*/
	{30,30,30,30,30,30,30,30},   /*+35degree*/
	{30,30,30,30,30,30,30,30},   /*+50degree*/
	{30,30,30,30,30,30,30,30}    /*+65degree*/
};

const uint16_t K_Spoiler_SpeedupInHighZone_Close_Duty[8][8] = 
{
	{30,30,30,30,30,30,30,30},   /*-40degree*/
	{30,30,30,30,30,30,30,30},   /*-25degree*/
	{30,30,30,30,30,30,30,30},   /*-10degree*/
	{30,30,30,30,30,30,30,30},   /*+05degree*/
	{30,30,30,30,30,30,30,30},   /*+20degree*/
	{30,30,30,30,30,30,30,30},   /*+35degree*/
	{30,30,30,30,30,30,30,30},   /*+50degree*/
	{30,30,30,30,30,30,30,30}    /*+65degree*/
};

const uint16_t K_Spoiler_ShortDistanceInOpening_HallCount[10] = {250,250,250,250,250,250,250,250,250,250};
const uint16_t K_Spoiler_ShortDistanceInClosing_HallCount[10] = {100,100,100,100,100,100,100,100,100,100};

const uint16_t K_Spoiler_ObstacleTimes_Continue_Count = 2U;
const uint16_t K_Spoiler_ObstacleTimes_Total_Count = 6U;

const uint16_t K_SpoilerLearned_Position_Default = 2500U;
const uint16_t K_SpoilerFullOpenSwitch_Position_Default = 2500U;
const uint16_t K_SpoilerMaxTravel_Position_Default = 3500U;

const uint16_t K_SpoilerFullOpenSwitch_Position_Open_Delta = 20U;
const uint16_t K_SpoilerFullOpenSwitch_Position_Close_Delta = 0U;
const uint16_t K_Spoiler_LearnNearClosePosition_HallCount = 200U;
const uint16_t K_Spoiler_LearnNearClosePosition_Close_Time = 60U; /* 10ms x */
const uint16_t K_SpoilerFullOpenSwitch_Position_LearnNearClosePosition_Compensation = 50U;
const uint16_t K_SpoilerFullOpenSwitch_Position_LearnFarClosePosition_Compensation = 0U; 

const uint16_t K_SpoilerFullOpenSwitch_HallEffect_Active_LowLimit = 2800U;/*12V = 2936 TRUE*/
const uint16_t K_SpoilerFullOpenSwitch_HallEffect_Active_HighLimit = 3100U;

const uint16_t K_SpoilerFullOpenSwitch_HallEffect_Inactive_LowLimit = 1400U;/*12V = 1286 FALSE*/
const uint16_t K_SpoilerFullOpenSwitch_HallEffect_Inactive_HighLimit = 1100U;

const uint16_t K_SpoilerFullCloseSwitch_HallEffect_Active_LowLimit = 2800U;/*12V = 2936 TRUE*/
const uint16_t K_SpoilerFullCloseSwitch_HallEffect_Active_HighLimit = 3100U;

const uint16_t K_SpoilerFullCloseSwitch_HallEffect_Inactive_LowLimit = 1400U;/*12V = 1286 FALSE*/
const uint16_t K_SpoilerFullCloseSwitch_HallEffect_Inactive_HighLimit = 1100U;
const uint16_t K_Spoiler_EnhancedCurrent_Detect_Open[8][10] = 
{
	{500,250,200,200,200,200,200,200,200,200},  /*<09V*/
	{500,250,200,200,200,200,200,200,200,200},  /*<10V*/
	{500,250,200,200,200,200,200,200,200,200},  /*<11V*/
	{500,250,200,200,200,200,200,200,200,200},  /*<12V*/
	{500,250,200,200,200,200,200,200,200,200},  /*<13V*/
	{500,250,200,200,200,200,200,200,200,200},  /*<14V*/
	{500,250,200,200,200,200,200,200,200,200},  /*<15V*/
	{500,250,200,200,200,200,200,200,200,200},  /*<16V*/
};

const uint16_t K_Spoiler_EnhancedCurrent_Detect_Open_Temp[8][10] = 
{
	{150,150,150,150,150,150,150,150,150,150},  /*-40degree*/
	{100,100,100,100,100,100,100,100,100,150},   /*-25degree*/
	{50,50,50,50,50,50,50,50,50,50},    /*-10degree*/
	{0,0,0,0,0,0,0,0,0,0},  /*+05degree*/
	{0,0,0,0,0,0,0,0,0,0},   /*+20degree*/
	{50,50,50,50,50,50,50,50,50,50},   /*+35degree*/
	{100,100,100,100,100,100,100,100,100,150},   /*+50degree*/
	{150,150,150,150,150,150,150,150,150,150},   /*+65degree*/
};

const uint16_t K_Spoiler_EnhancedCurrent_Detect_Close[8][10] = 
{
	{250,250,200,200,200,200,200,200,200,200},  /*<09V*/
	{250,250,200,200,200,200,200,200,200,200},  /*<10V*/
	{250,250,200,200,200,200,200,200,200,200},  /*<11V*/
	{250,250,200,200,200,200,200,200,200,200},  /*<12V*/
	{250,250,200,200,200,200,200,200,200,200},  /*<13V*/
	{250,250,200,200,200,200,200,200,200,200},  /*<14V*/
	{250,250,200,200,200,200,200,200,200,200},  /*<15V*/
	{250,250,200,200,200,200,200,200,200,200},  /*<16V*/
};

const uint16_t K_Spoiler_EnhancedCurrent_Detect_Close_Temp[8][10] = 
{
	{0,0,0,0,0,0,0,0,0,0},  /*-40degree*/
	{0,0,0,0,0,0,0,0,0,0},   /*-25degree*/
	{0,0,0,0,0,0,0,0,0,0},    /*-10degree*/
	{0,0,0,0,0,0,0,0,0,0},  /*+05degree*/
	{0,0,0,0,0,0,0,0,0,0},   /*+20degree*/
	{0,0,0,0,0,0,0,0,0,0},   /*+35degree*/
	{0,0,0,0,0,0,0,0,0,0},   /*+50degree*/
	{0,0,0,0,0,0,0,0,0,0},   /*+65degree*/
};
const uint16_t K_Spoiler_SoftStallCurrent_TopLimit[8][8]=
{     
     /* 9v  10v 11v 12v 13v14v15v16v  */
	{1000,1000,1000,1000,1000,1000,1000,1000},
	{1000,1000,1000,1000,1000,1000,1000,1000},
	{1000,1000,1000,1000,1000,1000,1000,1000},
	{1000,1000,1000,1000,1000,1000,1000,1000},
	{1000,1000,1000,1000,1000,1000,1000,1000},
	{1000,1000,1000,1000,1000,1000,1000,1000},
	{1000,1000,1000,1000,1000,1000,1000,1000},
	{1000,1000,1000,1000,1000,1000,1000,1000},
};

const uint16_t K_Spoiler_FixedCurrentStall_TopLimit[8][8]=
{     
        /* 9v  10v 11v 12v 13v 14v 15v 16v */
	{1600,1600,1600,1600,1600,1600,1600,1600},
	{1600,1600,1600,1600,1600,1600,1600,1600},
	{1600,1600,1600,1600,1600,1600,1600,1600},
	{1600,1600,1600,1600,1600,1600,1600,1600},
	{1600,1600,1600,1600,1600,1600,1600,1600},
	{1600,1600,1600,1600,1600,1600,1600,1600},
	{1600,1600,1600,1600,1600,1600,1600,1600},
	{1600,1600,1600,1600,1600,1600,1600,1600},
};
#endif
#ifdef _Spoiler_ChanganE11
/* Spoiler_PID Control - Default */
const uint8_t K_Spoiler_Prop_Open[20] = {30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30};
const uint8_t K_Spoiler_PropScale_Open[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
const uint8_t K_Spoiler_Int_Open[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
const uint8_t K_Spoiler_IntScale_Open[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
const uint8_t K_Spoiler_Diff_Open[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
const uint8_t K_Spoiler_DiffScale_Open[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

const uint8_t K_Spoiler_Prop_Close[20] = {30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30};
const uint8_t K_Spoiler_PropScale_Close[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
const uint8_t K_Spoiler_Int_Close[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
const uint8_t K_Spoiler_IntScale_Close[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
const uint8_t K_Spoiler_Diff_Close[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
const uint8_t K_Spoiler_DiffScale_Close[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

const uint8_t K_Spoiler_Prop_PushPID = 2U;
const uint8_t K_Spoiler_PropScale_PushPID = 1U;
const uint8_t K_Spoiler_Int_PushPID = 1U;
const uint8_t K_Spoiler_IntScale_PushPID = 1U;
const uint8_t K_Spoiler_Diff_PushPID = 1U;
const uint8_t K_Spoiler_DiffScale_PushPID = 1U;

const uint16_t K_Spoiler_PushPID_HallCount = 100U;
const uint16_t K_Spoiler_PushPIDSpeed_Tigger_Delta = 3U;
const uint16_t K_Spoiler_PushPIDSpeed_Quit_Delta = 2U;
const uint16_t K_Spoiler_PushPID_Timeout = 50U; /*20ms x*/
const uint16_t K_Spoiler_PushPID_ObstacleAdder_Timeout = 50U; /*20ms x*/

const uint16_t K_SpoilerPowerOn_Time = 7U; /*10m x 10 */
const uint16_t K_SpoilerWakeUp_Time = 7U; /*10m x 10 */
const uint16_t K_SpoilerReset_Time = 7U; /*10m x 10 */

const uint16_t K_SpoilerPowerOpening_SoftStall_Time = 10U; /*10m x 10 */
const uint16_t K_SpoilerPowerClosing_SoftStall_Time = 10U; /*10m x 10 */

const uint16_t K_SpoilerPowerOpening_ObstacleDetected_Reverse_Enable = TRUE;
const uint16_t K_SpoilerPowerClosing_ObstacleDetected_Reverse_Enable = TRUE;

const uint16_t K_SpoilerSwitch_ShortPress_LowLimit_Time = 5U; /* 50 x 10ms*/
const uint16_t K_SpoilerSwitch_ShortPress_HighLimit_Time = 100U; /* 100 x 10ms*/
const uint16_t K_SpoilerSwitch_LongPress_LowLimit_Time = 100U; /* 300 x 10ms*/
const uint16_t K_SpoilerSwitch_LongPress_HighLimit_Time = 500U; /* 500 x 10ms*/

const uint16_t K_SpoilerSwitch_LongPress_ManualUnlearn_Time = 500U; /* 500 x 10ms*/

const uint16_t K_SpoilerCommandInterval_Time = 50U; /*10m x 10 */

const uint16_t K_CentralLockSwitch_SpoilerCommandInterval_Enable = FALSE;
const uint16_t K_CentralLockSwitch_SpoilerCommandDelay_Time = 0U; /*10m x 10 */
const uint16_t K_CentralLockSwitch_Wakeup_SpoilerCommandDelay_Time = 50U; /*10m x 10 */

const uint16_t K_SpoilerSwitch_SpoilerCommandInterval_Enable = FALSE;
const uint16_t K_SpoilerSwitch_SpoilerCommandDelay_Time = 0U; /*10m x 10 */
const uint16_t K_SpoilerSwitch_Wakeup_SpoilerCommandDelay_Time = 50U; /*10m x 10 */

const uint16_t K_SpoilerCommandInhibition_Min_Time = 20U; /*10m x 10 */
const uint16_t K_SpoilerSwitch_ShortPress_SpoilerCommandInhibition_Time = 100U; /*10m x 10 */
const uint16_t K_SpoilerPowerOpening_Timeout = 800U; /*10m x 10 */
const uint16_t K_SpoilerPowerClosing_Timeout = 800U; /*10m x 10 */

const uint16_t K_SpoilerFullOpenPosition_Delay_Time = 0U; /*10m x */
const uint16_t K_SpoilerFullClosePosition_Delay_Time = 0U; /*10m x */
const uint16_t K_SpoilerOpenedFully_Timeout = 500U; /*10m x 10 */
const uint16_t K_SpoilerReleased_Timeout = 500U; /*10m x 10 */
const uint16_t K_SpoilerMechFailure_Timeout = 100U; /*10m x 10 */

const uint16_t K_ChangeDutyInSpoilerPowerOpening_1st_Time = 10U; /*10m x 10 */
const uint16_t K_ChangeDutyInSpoilerPowerClosing_1st_Time = 10U; /*10m x 10 */
const uint16_t K_StopBefore_SpoilerPowerOpening_Time = 10U; /*10m x 10 */
const uint16_t K_StopBefore_SpoilerPowerClosing_Time = 10U; /*10m x 10 */
const uint16_t K_SpoilerPowerOpening_Inrush_Time = 10U; /*10m x 10 */
const uint16_t K_SpoilerPowerClosing_Inrush_Time = 10U; /*10m x 10 */

const uint16_t K_SpoilerHomePosition_Delay_Time = 10U; /*10m x 10 */
const uint16_t K_SpoilerSpreadPosition_Delay_Time = 10U; /*10m x 10 */

const uint16_t K_Spoiler_FixedVoltage_Open_Enable[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
const uint16_t K_Spoiler_FixedVoltage_Close_Enable[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
const uint16_t K_Spoiler_FixedVoltage_Open_Duty[20] = {60,60,60,60,60,60,60,60,60,60,50,50,50,50,50,50,50,50,50,50};
const uint16_t K_Spoiler_FixedVoltage_Close_Duty[20] = {50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50};
const uint16_t K_Spoiler_FixedVoltage_Open_Timeout[20] = {100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100};
const uint16_t K_Spoiler_FixedVoltage_Close_Timeout[20] = {100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100};

const uint16_t K_Spoiler_PID_PWM_Max_PowerOpening[20] = {100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100};
const uint16_t K_Spoiler_PID_PWM_Max_PowerClosing[20] = {100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100};

const uint16_t K_SpoilerPowerOpening_Speedup_FullOpen_Time = 30U; /* 10ms x */
const uint16_t K_SpoilerPowerClosing_Speedup_FullClose_Time = 30U; /* 10ms x */
const uint16_t K_SpoilerPowerOpening_Speedup_Time = 50U; /* 10ms x */
const uint16_t K_SpoilerPowerClosing_Speedup_Time = 50U; /* 10ms x */
const uint16_t K_SpoilerPowerOpening_HardStart_Time[10] = {60,50,50,30,30,30,30,30,30,30}; /* 10ms x */
const uint16_t K_SpoilerPowerClosing_HardStart_Time[10] = {30,30,30,30,30,30,30,30,30,30}; /* 10ms x */
const uint16_t K_Spoiler_HardStart_Enable = TRUE;

const uint16_t K_Spoiler_ShortDistanceInOpening_HallCount[10] = {250,250,250,250,250,250,250,250,250,250};
const uint16_t K_Spoiler_ShortDistanceInClosing_HallCount[10] = {100,100,100,100,100,100,100,100,100,100};

const uint16_t K_Spoiler_ObstacleTimes_Continue_Count = 2U;
const uint16_t K_Spoiler_ObstacleTimes_Total_Count = 6U;


const uint16_t K_SpoilerFullOpenSwitch_HallEffect_Active_LowLimit = 2800U;/*12V = 2936 TRUE*/
const uint16_t K_SpoilerFullOpenSwitch_HallEffect_Active_HighLimit = 3100U;

const uint16_t K_SpoilerFullOpenSwitch_HallEffect_Inactive_LowLimit = 1400U;/*12V = 1286 FALSE*/
const uint16_t K_SpoilerFullOpenSwitch_HallEffect_Inactive_HighLimit = 1100U;

const uint16_t K_SpoilerFullCloseSwitch_HallEffect_Active_LowLimit = 2800U;/*12V = 2936 TRUE*/
const uint16_t K_SpoilerFullCloseSwitch_HallEffect_Active_HighLimit = 3100U;

const uint16_t K_SpoilerFullCloseSwitch_HallEffect_Inactive_LowLimit = 1400U;/*12V = 1286 FALSE*/
const uint16_t K_SpoilerFullCloseSwitch_HallEffect_Inactive_HighLimit = 1100U;

#ifdef _CONFIG_SpoilerMotor_HengshuaiMotor
const uint16_t K_Spoiler_StopFromMaxTravel_HallCount = 50U;
const uint16_t K_SpoilerOpenEnd_SoftStop_HallCount_Compensation = 60U;
const uint16_t K_SpoilerCloseEnd_SoftStop_HallCount_Compensation = 200U;
const uint16_t K_SpoilerOpenEnd_FullOpenSwitchPosition_Compensation = 0U;

const uint16_t K_SpoilerFullOpenSwitchVirtual_HallCount = 2500U;
const uint16_t K_SpoilerFullCloseSwitchVirtual_HallCount = 250U;
const uint16_t K_SpoilerMaxPosition_HallCount_Default = 3500U;

const uint16_t K_Spoiler_ObstacleIndex = 10U;
const uint16_t K_Spoiler_HallCountPerObstacleZone_Min = 150U;
const uint16_t K_Spoiler_HallCountPerObstacleZone_Max = 350U;    
const uint16_t K_Spoiler_HallCountPerObstacleZone_Default = 280U;

const uint16_t K_Spoiler_PowerOpening_HallCount_Delta = 0U;
const uint16_t K_Spoiler_PowerClosing_HallCount_Delta = 0U;

const uint16_t K_Spoiler_EnhancedCurrent_DecreasePerTimer = 5U;    /*10ms x */
const uint16_t K_Spoiler_EnhancedCurrent_Decrease_Time = 2U;       /*10ms x */
const uint16_t K_Spoiler_EnhancedCurrent_IncreasePerTimer = 40U;  /*10ms x */
const uint16_t K_Spoiler_EnhancedCurrent_Increase_Time = 20U;      /*10ms x */
const uint16_t K_Spoiler_EnhancedCurrent_Threshold_Time = 1U;     /*10ms x */

const uint16_t K_Spoiler_SoftStall_Detect_Time = 50U;    /*10ms x */
const uint16_t K_Spoiler_FixedCurrent_Detect_Time = 10U;    /*10ms x */

const uint16_t K_Spoiler_EnhancedCurrent_Detect_PushPID_Open_Adder[10] = {10,10,10,10,10,10,10,10,10,10};
const uint16_t K_Spoiler_EnhancedCurrent_Detect_PushPID_Close_Adder[10] = {10,10,10,10,10,10,10,10,10,10};
const uint16_t K_Spoiler_SpoilerPowerOpening_Duty[8][8]=
{     
      /* 9v  10v 11v 12v 13v14v15v16v  */
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20}
};
const uint16_t K_Spoiler_SpoilerPowerClosing_Duty[8][8]=
{     
      /* 9v  10v 11v 12v 13v14v15v16v  */
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20}
};

const uint16_t K_Spoiler_PositionObstacle_Detect_Delta = 20U;
const uint16_t K_Spoiler_PositionObstacle_Detect_Open_Timer[10] = {10,10,10,10,10,10,10,10,10,10};
const uint16_t K_Spoiler_PositionObstacle_Detect_Close_Timer[10] = {10,10,10,10,10,10,10,10,10,10};

const uint16_t K_Spoiler_HallPluse1Width_Time = 30U;
const uint16_t K_Spoiler_HallPluse2Width_Time = 30U;

const uint16_t K_Spoiler_SpeedZoneIndex = 20U;
const uint16_t K_Spoiler_HallCountPerSpeedZone_Min = 80U;
const uint16_t K_Spoiler_HallCountPerSpeedZone_Max = 180U;
const uint16_t K_Spoiler_HallCountPerSpeedZone_Default = 140U;

/* Desired power opening speed value */
const uint16_t K_Spoiler_Desired_Open_Speed[8][20] = 
{
	{15,16,17,18,19,20,20,20,20,20,20,20,20,20,20,20,19,18,17,16},          /*-40degree*/
	{15,16,17,18,19,20,20,20,20,20,20,20,20,20,20,20,19,18,17,16},          /*-25degree*/
	{15,16,17,18,19,20,20,20,20,20,20,20,20,20,20,20,19,18,17,16},          /*-10degree*/
	{15,16,17,18,19,20,20,20,20,20,20,20,20,20,20,20,19,18,17,16},          /*+05degree*/
	{15,16,17,18,19,20,20,20,20,20,20,20,20,20,20,20,19,18,17,16},          /*+20degree*/
	{15,16,17,18,19,20,20,20,20,20,20,20,20,20,20,20,19,18,17,16},          /*+35degree*/
	{15,16,17,18,19,20,20,20,20,20,20,20,20,20,20,20,19,18,17,16},          /*+50degree*/
	{15,16,17,18,19,20,20,20,20,20,20,20,20,20,20,20,19,18,17,16},          /*+65degree*/
};

/* Desired power closing speed value */
const uint16_t K_Spoiler_Desired_Close_Speed[8][20] = 
{
	{15,16,17,18,19,20,20,20,20,20,20,20,20,20,20,20,19,18,17,16},          /*-40degree*/
	{15,16,17,18,19,20,20,20,20,20,20,20,20,20,20,20,19,18,17,16},          /*-25degree*/
	{15,16,17,18,19,20,20,20,20,20,20,20,20,20,20,20,19,18,17,16},          /*-10degree*/
	{15,16,17,18,19,20,20,20,20,20,20,20,20,20,20,20,19,18,17,16},          /*+05degree*/
	{15,16,17,18,19,20,20,20,20,20,20,20,20,20,20,20,19,18,17,16},          /*+20degree*/
	{15,16,17,18,19,20,20,20,20,20,20,20,20,20,20,20,19,18,17,16},          /*+35degree*/
	{15,16,17,18,19,20,20,20,20,20,20,20,20,20,20,20,19,18,17,16},          /*+50degree*/
	{15,16,17,18,19,20,20,20,20,20,20,20,20,20,20,20,19,18,17,16},           /*+65degree*/
};

const uint16_t K_Spoiler_Opening_IncreaseDuty_Time = 1U; /*10ms x*/
const uint16_t K_Spoiler_Opening_IncreasePerTime_Duty = 2U;
const uint16_t K_Spoiler_Closing_IncreaseDuty_Time = 1U; /*10ms x*/
const uint16_t K_Spoiler_Closing_IncreasePerTime_Duty = 2U; 
const uint16_t K_Spoiler_Opening_Start_Duty[10] = {20,20,20,20,20,20,20,20,20,20};
const uint16_t K_Spoiler_Closing_Start_Duty[10] = {20,20,20,20,20,20,20,20,20,20};
const uint16_t K_Spoiler_SoftStop_Opening_Step_Duty = 2U;
const uint16_t K_Spoiler_SoftStop_Opening_Step_Time = 1U; /* 10ms x 5 */
const uint16_t K_Spoiler_SoftStop_Opening_End_Duty  = 10U;
const uint16_t K_Spoiler_SoftStop_Closing_Step_Duty = 2U;
const uint16_t K_Spoiler_SoftStop_Closing_Step_Time = 1U; /* 10ms x 5 */
const uint16_t K_Spoiler_SoftStop_Closing_End_Duty  = 10U;
const uint16_t K_SpoilerHallObstacle_SoftStop_Time = 100U; /* 10ms x 100 */

const uint16_t K_Spoiler_SoftStart_Opening_HallCount_LowLimit = 0U; /**/
const uint16_t K_Spoiler_SoftStart_Closing_HallCount_LowLimit = 0U;
const uint16_t K_Spoiler_SoftStart_Opening_HallCount_HighLimit = 3500U; /**/
const uint16_t K_Spoiler_SoftStart_Closing_HallCount_HighLimit = 3500U;

const uint16_t K_Spoiler_Speedup_OpenInLowZone_HallCount = 20U;
const uint16_t K_Spoiler_Speedup_OpenInMiddleZone_HallCount = 20U;
const uint16_t K_Spoiler_Speedup_OpenInHighZone_HallCount = 20U;

const uint16_t K_Spoiler_Speedup_CloseInLowZone_HallCount = 20U;
const uint16_t K_Spoiler_Speedup_CloseInMiddleZone_HallCount = 20U;
const uint16_t K_Spoiler_Speedup_CloseInHighZone_HallCount = 20U;

const uint16_t K_Spoiler_SpeedupInLowZone_HallCount = 100U;   
const uint16_t K_Spoiler_SpeedupInHighZone_HallCount = 2500U; 

const uint16_t K_SpoilerLearned_Position_Default = 2500U;
const uint16_t K_SpoilerFullOpenSwitch_Position_Default = 2500U;
const uint16_t K_SpoilerMaxTravel_Position_Default = 3500U;

const uint16_t K_SpoilerFullOpenSwitch_Position_Open_Delta = 20U;
const uint16_t K_SpoilerFullOpenSwitch_Position_Close_Delta = 0U;
const uint16_t K_Spoiler_LearnNearClosePosition_HallCount = 200U;
const uint16_t K_Spoiler_LearnNearClosePosition_Close_Time = 60U; /* 10ms x */
const uint16_t K_SpoilerFullOpenSwitch_Position_LearnNearClosePosition_Compensation = 75U;
const uint16_t K_SpoilerFullOpenSwitch_Position_LearnFarClosePosition_Compensation = 0U; 

const uint16_t K_Spoiler_SpeedupInLowZone_Open_Duty[8][8] = 
{
 	{30,30,30,30,30,30,30,30},   /*-40degree*/
	{30,30,30,30,30,30,30,30},   /*-25degree*/
	{30,30,30,30,30,30,30,30},   /*-10degree*/
	{30,30,30,30,30,30,30,30},   /*+05degree*/
	{30,30,30,30,30,30,30,30},   /*+20degree*/
	{30,30,30,30,30,30,30,30},   /*+35degree*/
	{30,30,30,30,30,30,30,30},   /*+50degree*/
	{30,30,30,30,30,30,30,30}    /*+65degree*/
};

const uint16_t K_Spoiler_SpeedupInLowZone_Close_Duty[8][8] = 
{
	{30,30,30,30,30,30,30,30},   /*-40degree*/
	{30,30,30,30,30,30,30,30},   /*-25degree*/
	{30,30,30,30,30,30,30,30},   /*-10degree*/
	{30,30,30,30,30,30,30,30},   /*+05degree*/
	{30,30,30,30,30,30,30,30},   /*+20degree*/
	{30,30,30,30,30,30,30,30},   /*+35degree*/
	{30,30,30,30,30,30,30,30},   /*+50degree*/
	{30,30,30,30,30,30,30,30}    /*+65degree*/
};

const uint16_t K_Spoiler_SpeedupInMiddleZone_Open_Duty[8][8] = 
{
	{30,30,30,30,30,30,30,30},   /*-40degree*/
	{30,30,30,30,30,30,30,30},   /*-25degree*/
	{30,30,30,30,30,30,30,30},   /*-10degree*/
	{30,30,30,30,30,30,30,30},   /*+05degree*/
	{30,30,30,30,30,30,30,30},   /*+20degree*/
	{30,30,30,30,30,30,30,30},   /*+35degree*/
	{30,30,30,30,30,30,30,30},   /*+50degree*/
	{30,30,30,30,30,30,30,30}    /*+65degree*/
};

const uint16_t K_Spoiler_SpeedupInMiddleZone_Close_Duty[8][8] = 
{
	{30,30,30,30,30,30,30,30},   /*-40degree*/
	{30,30,30,30,30,30,30,30},   /*-25degree*/
	{30,30,30,30,30,30,30,30},   /*-10degree*/
	{30,30,30,30,30,30,30,30},   /*+05degree*/
	{30,30,30,30,30,30,30,30},   /*+20degree*/
	{30,30,30,30,30,30,30,30},   /*+35degree*/
	{30,30,30,30,30,30,30,30},   /*+50degree*/
	{30,30,30,30,30,30,30,30}    /*+65degree*/
};

const uint16_t K_Spoiler_SpeedupInHighZone_Open_Duty[8][8] = 
{
	{30,30,30,30,30,30,30,30},   /*-40degree*/
	{30,30,30,30,30,30,30,30},   /*-25degree*/
	{30,30,30,30,30,30,30,30},   /*-10degree*/
	{30,30,30,30,30,30,30,30},   /*+05degree*/
	{30,30,30,30,30,30,30,30},   /*+20degree*/
	{30,30,30,30,30,30,30,30},   /*+35degree*/
	{30,30,30,30,30,30,30,30},   /*+50degree*/
	{30,30,30,30,30,30,30,30}    /*+65degree*/
};

const uint16_t K_Spoiler_SpeedupInHighZone_Close_Duty[8][8] = 
{
	{30,30,30,30,30,30,30,30},   /*-40degree*/
	{30,30,30,30,30,30,30,30},   /*-25degree*/
	{30,30,30,30,30,30,30,30},   /*-10degree*/
	{30,30,30,30,30,30,30,30},   /*+05degree*/
	{30,30,30,30,30,30,30,30},   /*+20degree*/
	{30,30,30,30,30,30,30,30},   /*+35degree*/
	{30,30,30,30,30,30,30,30},   /*+50degree*/
	{30,30,30,30,30,30,30,30}    /*+65degree*/
};

const uint16_t K_Spoiler_EnhancedCurrent_Detect_Open[8][10] = 
{
	{400,400,400,400,400,400,400,400,400,400},  /*<09V*/
	{400,400,400,400,400,400,400,400,400,400},  /*<10V*/
	{400,400,400,400,400,400,400,400,400,400},  /*<11V*/
	{400,400,400,400,400,400,400,400,400,400},  /*<12V*/
	{400,400,400,400,400,400,400,400,400,400},  /*<13V*/
	{400,400,400,400,400,400,400,400,400,400},  /*<14V*/
	{400,400,400,400,400,400,400,400,400,400},  /*<15V*/
	{400,400,400,400,400,400,400,400,400,400},  /*<16V*/
};

const uint16_t K_Spoiler_EnhancedCurrent_Detect_Open_Temp[8][10] = 
{
	{200,200,200,200,200,200,200,200,200,200},  /*-40degree*/
	{150,150,150,150,150,150,150,150,150,150},   /*-25degree*/
	{50,50,50,50,50,50,50,50,50,50},    /*-10degree*/
	{0,0,0,0,0,0,0,0,0,0},  /*+05degree*/
	{0,0,0,0,0,0,0,0,0,0},   /*+20degree*/
	{50,50,50,50,50,50,50,50,50,50},   /*+35degree*/
	{150,150,150,150,150,150,150,150,150,150},   /*+50degree*/
	{200,200,200,200,200,200,200,200,200,200},   /*+65degree*/
};

const uint16_t K_Spoiler_EnhancedCurrent_Detect_Close[8][10] = 
{
	{400,400,400,400,400,400,400,400,400,400},  /*<09V*/
	{400,400,400,400,400,400,400,400,400,400},  /*<10V*/
	{400,400,400,400,400,400,400,400,400,400},  /*<11V*/
	{400,400,400,400,400,400,400,400,400,400},  /*<12V*/
	{400,400,400,400,400,400,400,400,400,400},  /*<13V*/
	{400,400,400,400,400,400,400,400,400,400},  /*<14V*/
	{400,400,400,400,400,400,400,400,400,400},  /*<15V*/
	{400,400,400,400,400,400,400,400,400,400},  /*<16V*/
};

const uint16_t K_Spoiler_EnhancedCurrent_Detect_Close_Temp[8][10] = 
{
	{200,200,200,200,200,200,200,200,200,200},  /*-40degree*/
	{150,150,150,150,150,150,150,150,150,150},   /*-25degree*/
	{50,50,50,50,50,50,50,50,50,50},    /*-10degree*/
	{0,0,0,0,0,0,0,0,0,0},  /*+05degree*/
	{0,0,0,0,0,0,0,0,0,0},   /*+20degree*/
	{50,50,50,50,50,50,50,50,50,50},   /*+35degree*/
	{150,150,150,150,150,150,150,150,150,150},   /*+50degree*/
	{200,200,200,200,200,200,200,200,200,200},   /*+65degree*/
};
const uint16_t K_Spoiler_SoftStallCurrent_TopLimit[8][8]=
{     
     /* 9v  10v 11v 12v 13v14v15v16v  */
	{1000,1000,1000,1000,1000,1000,1000,1000},
	{1000,1000,1000,1000,1000,1000,1000,1000},
	{1000,1000,1000,1000,1000,1000,1000,1000},
	{1000,1000,1000,1000,1000,1000,1000,1000},
	{1000,1000,1000,1000,1000,1000,1000,1000},
	{1000,1000,1000,1000,1000,1000,1000,1000},
	{1000,1000,1000,1000,1000,1000,1000,1000},
	{1000,1000,1000,1000,1000,1000,1000,1000},
};

const uint16_t K_Spoiler_FixedCurrentStall_TopLimit[8][8]=
{     
        /* 9v  10v 11v 12v 13v 14v 15v 16v */
	{1600,1600,1600,1600,1600,1600,1600,1600},
	{1600,1600,1600,1600,1600,1600,1600,1600},
	{1600,1600,1600,1600,1600,1600,1600,1600},
	{1600,1600,1600,1600,1600,1600,1600,1600},
	{1600,1600,1600,1600,1600,1600,1600,1600},
	{1600,1600,1600,1600,1600,1600,1600,1600},
	{1600,1600,1600,1600,1600,1600,1600,1600},
	{1600,1600,1600,1600,1600,1600,1600,1600},
};
#endif

#ifdef _CONFIG_SpoilerMotor_LVMotor
const uint16_t K_Spoiler_StopFromMaxTravel_HallCount = 30U;
const uint16_t K_SpoilerOpenEnd_SoftStop_HallCount_Compensation = 30U;
const uint16_t K_SpoilerCloseEnd_SoftStop_HallCount_Compensation = 80U;
const uint16_t K_SpoilerOpenEnd_FullOpenSwitchPosition_Compensation = 0U;

const uint16_t K_SpoilerFullOpenSwitchVirtual_HallCount = 1000U;
const uint16_t K_SpoilerFullCloseSwitchVirtual_HallCount = 100U;
const uint16_t K_SpoilerMaxPosition_HallCount_Default = 1500U;

const uint16_t K_Spoiler_ObstacleIndex = 10U;
const uint16_t K_Spoiler_HallCountPerObstacleZone_Min = 60U;
const uint16_t K_Spoiler_HallCountPerObstacleZone_Max = 150U;    
const uint16_t K_Spoiler_HallCountPerObstacleZone_Default = 100U;

const uint16_t K_Spoiler_PowerOpening_HallCount_Delta = 0U;
const uint16_t K_Spoiler_PowerClosing_HallCount_Delta = 0U;

const uint16_t K_Spoiler_EnhancedCurrent_DecreasePerTimer = 5U;    /*10ms x */
const uint16_t K_Spoiler_EnhancedCurrent_Decrease_Time = 2U;       /*10ms x */
const uint16_t K_Spoiler_EnhancedCurrent_IncreasePerTimer = 40U;  /*10ms x */
const uint16_t K_Spoiler_EnhancedCurrent_Increase_Time = 20U;      /*10ms x */
const uint16_t K_Spoiler_EnhancedCurrent_Threshold_Time = 1U;     /*10ms x */

const uint16_t K_Spoiler_SoftStall_Detect_Time = 50U;    /*10ms x */
const uint16_t K_Spoiler_FixedCurrent_Detect_Time = 10U;    /*10ms x */

const uint16_t K_Spoiler_EnhancedCurrent_Detect_PushPID_Open_Adder[10] = {10,10,10,10,10,10,10,10,10,10};
const uint16_t K_Spoiler_EnhancedCurrent_Detect_PushPID_Close_Adder[10] = {10,10,10,10,10,10,10,10,10,10};
const uint16_t K_Spoiler_SpoilerPowerOpening_Duty[8][8]=
{     
      /* 9v  10v 11v 12v 13v14v15v16v  */
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20}
};
const uint16_t K_Spoiler_SpoilerPowerClosing_Duty[8][8]=
{     
      /* 9v  10v 11v 12v 13v14v15v16v  */
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20}
};

const uint16_t K_Spoiler_PositionObstacle_Detect_Delta = 20U;
const uint16_t K_Spoiler_PositionObstacle_Detect_Open_Timer[10] = {10,10,10,10,10,10,10,10,10,10};
const uint16_t K_Spoiler_PositionObstacle_Detect_Close_Timer[10] = {10,10,10,10,10,10,10,10,10,10};

const uint16_t K_Spoiler_HallPluse1Width_Time = 30U;
const uint16_t K_Spoiler_HallPluse2Width_Time = 30U;

const uint16_t K_Spoiler_SpeedZoneIndex = 20U;
const uint16_t K_Spoiler_HallCountPerSpeedZone_Min = 80U;
const uint16_t K_Spoiler_HallCountPerSpeedZone_Max = 180U;
const uint16_t K_Spoiler_HallCountPerSpeedZone_Default = 140U;

/* Desired power opening speed value */
const uint16_t K_Spoiler_Desired_Open_Speed[8][20] = 
{
	{5,6,7,8,8,8,8,8,8,8,8,8,8,8,8,8,8,7,6,5},          /*-40degree*/
	{5,6,7,8,8,8,8,8,8,8,8,8,8,8,8,8,8,7,6,5},          /*-25degree*/
	{5,6,7,8,8,8,8,8,8,8,8,8,8,8,8,8,8,7,6,5},          /*-10degree*/
	{5,6,7,8,8,8,8,8,8,8,8,8,8,8,8,8,8,7,6,5},          /*+05degree*/
	{5,6,7,8,8,8,8,8,8,8,8,8,8,8,8,8,8,7,6,5},          /*+20degree*/
	{5,6,7,8,8,8,8,8,8,8,8,8,8,8,8,8,8,7,6,5},          /*+35degree*/
	{5,6,7,8,8,8,8,8,8,8,8,8,8,8,8,8,8,7,6,5},          /*+50degree*/
	{5,6,7,8,8,8,8,8,8,8,8,8,8,8,8,8,8,7,6,5},          /*+65degree*/
};

/* Desired power closing speed value */
const uint16_t K_Spoiler_Desired_Close_Speed[8][20] = 
{
	{5,6,7,8,8,8,8,8,8,8,8,8,8,8,8,8,8,7,6,5},          /*-40degree*/
	{5,6,7,8,8,8,8,8,8,8,8,8,8,8,8,8,8,7,6,5},          /*-25degree*/
	{5,6,7,8,8,8,8,8,8,8,8,8,8,8,8,8,8,7,6,5},          /*-10degree*/
	{5,6,7,8,8,8,8,8,8,8,8,8,8,8,8,8,8,7,6,5},          /*+05degree*/
	{5,6,7,8,8,8,8,8,8,8,8,8,8,8,8,8,8,7,6,5},          /*+20degree*/
	{5,6,7,8,8,8,8,8,8,8,8,8,8,8,8,8,8,7,6,5},          /*+35degree*/
	{5,6,7,8,8,8,8,8,8,8,8,8,8,8,8,8,8,7,6,5},          /*+50degree*/
	{5,6,7,8,8,8,8,8,8,8,8,8,8,8,8,8,8,7,6,5},          /*+65degree*/
};

const uint16_t K_Spoiler_Opening_IncreaseDuty_Time = 1U; /*10ms x*/
const uint16_t K_Spoiler_Opening_IncreasePerTime_Duty = 2U;
const uint16_t K_Spoiler_Closing_IncreaseDuty_Time = 1U; /*10ms x*/
const uint16_t K_Spoiler_Closing_IncreasePerTime_Duty = 2U; 
const uint16_t K_Spoiler_Opening_Start_Duty[10] = {20,20,20,20,20,20,20,20,20,20};
const uint16_t K_Spoiler_Closing_Start_Duty[10] = {20,20,20,20,20,20,20,20,20,20};
const uint16_t K_Spoiler_SoftStop_Opening_Step_Duty = 2U;
const uint16_t K_Spoiler_SoftStop_Opening_Step_Time = 1U; /* 10ms x 5 */
const uint16_t K_Spoiler_SoftStop_Opening_End_Duty  = 10U;
const uint16_t K_Spoiler_SoftStop_Closing_Step_Duty = 2U;
const uint16_t K_Spoiler_SoftStop_Closing_Step_Time = 1U; /* 10ms x 5 */
const uint16_t K_Spoiler_SoftStop_Closing_End_Duty  = 10U;
const uint16_t K_SpoilerHallObstacle_SoftStop_Time = 100U; /* 10ms x 100 */

const uint16_t K_Spoiler_SoftStart_Opening_HallCount_LowLimit = 0U; /**/
const uint16_t K_Spoiler_SoftStart_Closing_HallCount_LowLimit = 0U;
const uint16_t K_Spoiler_SoftStart_Opening_HallCount_HighLimit = 1500U; /**/
const uint16_t K_Spoiler_SoftStart_Closing_HallCount_HighLimit = 1500U;

const uint16_t K_Spoiler_Speedup_OpenInLowZone_HallCount = 20U;
const uint16_t K_Spoiler_Speedup_OpenInMiddleZone_HallCount = 20U;
const uint16_t K_Spoiler_Speedup_OpenInHighZone_HallCount = 20U;

const uint16_t K_Spoiler_Speedup_CloseInLowZone_HallCount = 20U;
const uint16_t K_Spoiler_Speedup_CloseInMiddleZone_HallCount = 20U;
const uint16_t K_Spoiler_Speedup_CloseInHighZone_HallCount = 20U;

const uint16_t K_Spoiler_SpeedupInLowZone_HallCount = 100U;   
const uint16_t K_Spoiler_SpeedupInHighZone_HallCount = 1000U; 

const uint16_t K_SpoilerLearned_Position_Default = 1000U;
const uint16_t K_SpoilerFullOpenSwitch_Position_Default = 1000U;
const uint16_t K_SpoilerMaxTravel_Position_Default = 1500U;

const uint16_t K_SpoilerFullOpenSwitch_Position_Open_Delta = 0U;
const uint16_t K_SpoilerFullOpenSwitch_Position_Close_Delta = 0U;
const uint16_t K_Spoiler_LearnNearClosePosition_HallCount = 100U;
const uint16_t K_Spoiler_LearnNearClosePosition_Close_Time = 60U; /* 10ms x */
const uint16_t K_SpoilerFullOpenSwitch_Position_LearnNearClosePosition_Compensation = 30U;
const uint16_t K_SpoilerFullOpenSwitch_Position_LearnFarClosePosition_Compensation = 0U; 

const uint16_t K_Spoiler_SpeedupInLowZone_Open_Duty[8][8] = 
{
 	{30,30,30,30,30,30,30,30},   /*-40degree*/
	{30,30,30,30,30,30,30,30},   /*-25degree*/
	{30,30,30,30,30,30,30,30},   /*-10degree*/
	{30,30,30,30,30,30,30,30},   /*+05degree*/
	{30,30,30,30,30,30,30,30},   /*+20degree*/
	{30,30,30,30,30,30,30,30},   /*+35degree*/
	{30,30,30,30,30,30,30,30},   /*+50degree*/
	{30,30,30,30,30,30,30,30}    /*+65degree*/
};

const uint16_t K_Spoiler_SpeedupInLowZone_Close_Duty[8][8] = 
{
	{30,30,30,30,30,30,30,30},   /*-40degree*/
	{30,30,30,30,30,30,30,30},   /*-25degree*/
	{30,30,30,30,30,30,30,30},   /*-10degree*/
	{30,30,30,30,30,30,30,30},   /*+05degree*/
	{30,30,30,30,30,30,30,30},   /*+20degree*/
	{30,30,30,30,30,30,30,30},   /*+35degree*/
	{30,30,30,30,30,30,30,30},   /*+50degree*/
	{30,30,30,30,30,30,30,30}    /*+65degree*/
};

const uint16_t K_Spoiler_SpeedupInMiddleZone_Open_Duty[8][8] = 
{
	{30,30,30,30,30,30,30,30},   /*-40degree*/
	{30,30,30,30,30,30,30,30},   /*-25degree*/
	{30,30,30,30,30,30,30,30},   /*-10degree*/
	{30,30,30,30,30,30,30,30},   /*+05degree*/
	{30,30,30,30,30,30,30,30},   /*+20degree*/
	{30,30,30,30,30,30,30,30},   /*+35degree*/
	{30,30,30,30,30,30,30,30},   /*+50degree*/
	{30,30,30,30,30,30,30,30}    /*+65degree*/
};

const uint16_t K_Spoiler_SpeedupInMiddleZone_Close_Duty[8][8] = 
{
	{30,30,30,30,30,30,30,30},   /*-40degree*/
	{30,30,30,30,30,30,30,30},   /*-25degree*/
	{30,30,30,30,30,30,30,30},   /*-10degree*/
	{30,30,30,30,30,30,30,30},   /*+05degree*/
	{30,30,30,30,30,30,30,30},   /*+20degree*/
	{30,30,30,30,30,30,30,30},   /*+35degree*/
	{30,30,30,30,30,30,30,30},   /*+50degree*/
	{30,30,30,30,30,30,30,30}    /*+65degree*/
};

const uint16_t K_Spoiler_SpeedupInHighZone_Open_Duty[8][8] = 
{
	{30,30,30,30,30,30,30,30},   /*-40degree*/
	{30,30,30,30,30,30,30,30},   /*-25degree*/
	{30,30,30,30,30,30,30,30},   /*-10degree*/
	{30,30,30,30,30,30,30,30},   /*+05degree*/
	{30,30,30,30,30,30,30,30},   /*+20degree*/
	{30,30,30,30,30,30,30,30},   /*+35degree*/
	{30,30,30,30,30,30,30,30},   /*+50degree*/
	{30,30,30,30,30,30,30,30}    /*+65degree*/
};

const uint16_t K_Spoiler_SpeedupInHighZone_Close_Duty[8][8] = 
{
	{30,30,30,30,30,30,30,30},   /*-40degree*/
	{30,30,30,30,30,30,30,30},   /*-25degree*/
	{30,30,30,30,30,30,30,30},   /*-10degree*/
	{30,30,30,30,30,30,30,30},   /*+05degree*/
	{30,30,30,30,30,30,30,30},   /*+20degree*/
	{30,30,30,30,30,30,30,30},   /*+35degree*/
	{30,30,30,30,30,30,30,30},   /*+50degree*/
	{30,30,30,30,30,30,30,30}    /*+65degree*/
};

const uint16_t K_Spoiler_EnhancedCurrent_Detect_Open[8][10] = 
{
	{400,400,400,400,400,400,400,400,400,400},  /*<09V*/
	{400,400,400,400,400,400,400,400,400,400},  /*<10V*/
	{400,400,400,400,400,400,400,400,400,400},  /*<11V*/
	{400,400,400,400,400,400,400,400,400,400},  /*<12V*/
	{400,400,400,400,400,400,400,400,400,400},  /*<13V*/
	{400,400,400,400,400,400,400,400,400,400},  /*<14V*/
	{400,400,400,400,400,400,400,400,400,400},  /*<15V*/
	{400,400,400,400,400,400,400,400,400,400},  /*<16V*/
};

const uint16_t K_Spoiler_EnhancedCurrent_Detect_Open_Temp[8][10] = 
{
	{200,200,200,200,200,200,200,200,200,200},  /*-40degree*/
	{150,150,150,150,150,150,150,150,150,150},   /*-25degree*/
	{50,50,50,50,50,50,50,50,50,50},    /*-10degree*/
	{0,0,0,0,0,0,0,0,0,0},  /*+05degree*/
	{0,0,0,0,0,0,0,0,0,0},   /*+20degree*/
	{50,50,50,50,50,50,50,50,50,50},   /*+35degree*/
	{150,150,150,150,150,150,150,150,150,150},   /*+50degree*/
	{200,200,200,200,200,200,200,200,200,200},   /*+65degree*/
};

const uint16_t K_Spoiler_EnhancedCurrent_Detect_Close[8][10] = 
{
	{400,400,400,400,400,400,400,400,400,400},  /*<09V*/
	{400,400,400,400,400,400,400,400,400,400},  /*<10V*/
	{400,400,400,400,400,400,400,400,400,400},  /*<11V*/
	{400,400,400,400,400,400,400,400,400,400},  /*<12V*/
	{400,400,400,400,400,400,400,400,400,400},  /*<13V*/
	{400,400,400,400,400,400,400,400,400,400},  /*<14V*/
	{400,400,400,400,400,400,400,400,400,400},  /*<15V*/
	{400,400,400,400,400,400,400,400,400,400},  /*<16V*/
};

const uint16_t K_Spoiler_EnhancedCurrent_Detect_Close_Temp[8][10] = 
{
	{200,200,200,200,200,200,200,200,200,200},  /*-40degree*/
	{150,150,150,150,150,150,150,150,150,150},   /*-25degree*/
	{50,50,50,50,50,50,50,50,50,50},    /*-10degree*/
	{0,0,0,0,0,0,0,0,0,0},  /*+05degree*/
	{0,0,0,0,0,0,0,0,0,0},   /*+20degree*/
	{50,50,50,50,50,50,50,50,50,50},   /*+35degree*/
	{150,150,150,150,150,150,150,150,150,150},   /*+50degree*/
	{200,200,200,200,200,200,200,200,200,200},   /*+65degree*/
};
const uint16_t K_Spoiler_SoftStallCurrent_TopLimit[8][8]=
{     
     /* 9v  10v 11v 12v 13v14v15v16v  */
	{1000,1000,1000,1000,1000,1000,1000,1000},
	{1000,1000,1000,1000,1000,1000,1000,1000},
	{1000,1000,1000,1000,1000,1000,1000,1000},
	{1000,1000,1000,1000,1000,1000,1000,1000},
	{1000,1000,1000,1000,1000,1000,1000,1000},
	{1000,1000,1000,1000,1000,1000,1000,1000},
	{1000,1000,1000,1000,1000,1000,1000,1000},
	{1000,1000,1000,1000,1000,1000,1000,1000},
};

const uint16_t K_Spoiler_FixedCurrentStall_TopLimit[8][8]=
{     
        /* 9v  10v 11v 12v 13v 14v 15v 16v */
	{1600,1600,1600,1600,1600,1600,1600,1600},
	{1600,1600,1600,1600,1600,1600,1600,1600},
	{1600,1600,1600,1600,1600,1600,1600,1600},
	{1600,1600,1600,1600,1600,1600,1600,1600},
	{1600,1600,1600,1600,1600,1600,1600,1600},
	{1600,1600,1600,1600,1600,1600,1600,1600},
	{1600,1600,1600,1600,1600,1600,1600,1600},
	{1600,1600,1600,1600,1600,1600,1600,1600},
};
#endif

#endif
#endif

/*********************************************************************************************
**    Window_control
*********************************************************************************************/
#ifdef _CONFIG_PowerWindow
/* Window_PID Control - Default */
const uint8_t K_Window_Prop_Open[20] = {60,60,60,60,60,60,60,60,60,60,60,60,60,60,60,60,60,60,60,60};
const uint8_t K_Window_PropScale_Open[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
const uint8_t K_Window_Int_Open[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
const uint8_t K_Window_IntScale_Open[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
const uint8_t K_Window_Diff_Open[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
const uint8_t K_Window_DiffScale_Open[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

const uint8_t K_Window_Prop_Close[20] = {60,60,60,60,60,60,60,60,60,60,60,60,60,60,60,60,60,60,60,60};
const uint8_t K_Window_PropScale_Close[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
const uint8_t K_Window_Int_Close[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
const uint8_t K_Window_IntScale_Close[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
const uint8_t K_Window_Diff_Close[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
const uint8_t K_Window_DiffScale_Close[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

const uint8_t K_Window_Prop_PushPID = 2U;
const uint8_t K_Window_PropScale_PushPID = 1U;
const uint8_t K_Window_Int_PushPID = 1U;
const uint8_t K_Window_IntScale_PushPID = 1U;
const uint8_t K_Window_Diff_PushPID = 1U;
const uint8_t K_Window_DiffScale_PushPID = 1U;

const uint16_t K_Window_PushPID_HallCount = 100U;
const uint16_t K_Window_PushPIDSpeed_Tigger_Delta = 3U;
const uint16_t K_Window_PushPIDSpeed_Quit_Delta = 2U;
const uint16_t K_Window_PushPID_Timeout = 50U; /*20ms x*/
const uint16_t K_Window_PushPID_ObstacleAdder_Timeout = 50U; /*20ms x*/

const uint16_t K_WindowPowerOn_Time = 7U; /*10m x 10 */
const uint16_t K_WindowWakeUp_Time = 7U; /*10m x 10 */
const uint16_t K_WindowReset_Time = 7U; /*10m x 10 */

const uint16_t K_WindowPowerOpening_SoftStall_Time = 10U; /*10m x 10 */
const uint16_t K_WindowPowerClosing_SoftStall_Time = 10U; /*10m x 10 */

const uint16_t K_WindowPowerOpening_ObstacleDetected_Reverse_Enable = FALSE;
const uint16_t K_WindowPowerClosing_ObstacleDetected_Reverse_Enable = FALSE;

const uint16_t K_WindowSwitch_ShortPress_LowLimit_Time = 5U; /* 50 x 10ms*/
const uint16_t K_WindowSwitch_ShortPress_HighLimit_Time = 100U; /* 100 x 10ms*/
const uint16_t K_WindowSwitch_LongPress_LowLimit_Time = 100U; /* 300 x 10ms*/
const uint16_t K_WindowSwitch_LongPress_HighLimit_Time = 500U; /* 500 x 10ms*/

const uint16_t K_WindowCommandInterval_Time = 50U; /*10m x 10 */

const uint16_t K_CentralLockSwitch_WindowCommandInterval_Enable = FALSE;
const uint16_t K_CentralLockSwitch_WindowCommandDelay_Time = 50U; /*10m x 10 */
const uint16_t K_CentralLockSwitch_Wakeup_WindowCommandDelay_Time = 50U; /*10m x 10 */

const uint16_t K_WindowSwitch_WindowCommandInterval_Enable = FALSE;
const uint16_t K_WindowSwitch_WindowCommandDelay_Time = 50U; /*10m x 10 */
const uint16_t K_WindowSwitch_Wakeup_WindowCommandDelay_Time = 50U; /*10m x 10 */

const uint16_t K_WindowCommandInhibition_Min_Time = 20U; /*10m x 10 */
const uint16_t K_WindowSwitch_ShortPress_WindowCommandInhibition_Time = 50U; /*10m x 10 */

const uint16_t K_WindowPowerOpening_Timeout = 800U; /*10m x 10 */
const uint16_t K_WindowPowerClosing_Timeout = 800U; /*10m x 10 */

const uint16_t K_Window_StopFromMaxTravel_HallCount = 10U;
const uint16_t K_Window_OpenEnd_SoftStop_HallCount_Compensation = 40U;
const uint16_t K_Window_CloseEnd_SoftStop_HallCount_Compensation = 40U;

const uint16_t K_Window_VirtualFullOpenSwitch_HallCount = 900U;
const uint16_t K_Window_FullCloseSwitchVirtual_HallCount = 20U;

const uint16_t K_Window_MaxPosition_HallCount_Default = 1200U;

const uint16_t K_WindowOpenedFully_Timeout = 500U; /*10m x 10 */
const uint16_t K_WindowReleased_Timeout = 500U; /*10m x 10 */

const uint16_t K_ChangeDutyInWindowPowerOpening_1st_Time = 10U; /*10m x 10 */
const uint16_t K_ChangeDutyInWindowPowerClosing_1st_Time = 10U; /*10m x 10 */

const uint16_t K_StopBefore_WindowPowerOpening_Time = 10U; /*10m x 10 */
const uint16_t K_StopBefore_WindowPowerClosing_Time = 10U; /*10m x 10 */

const uint16_t K_WindowPowerOpening_Inrush_Time = 10U; /*10m x 10 */
const uint16_t K_WindowPowerClosing_Inrush_Time = 10U; /*10m x 10 */

const uint16_t K_Window_ObstacleIndex = 10U;
const uint16_t K_Window_HallCountPerObstacleZone_Min = 120U;
const uint16_t K_Window_HallCountPerObstacleZone_Max = 230U;    
const uint16_t K_Window_HallCountPerObstacleZone_Default = 180U;

const uint16_t K_Window_PowerOpening_HallCount_Delta = 0U;
const uint16_t K_Window_PowerClosing_HallCount_Delta = 0U;

const uint16_t K_Window_EnhancedCurrent_DecreasePerTimer = 5U;    /*10ms x */
const uint16_t K_Window_EnhancedCurrent_Decrease_Time = 2U;       /*10ms x */
const uint16_t K_Window_EnhancedCurrent_IncreasePerTimer = 10U;  /*10ms x */
const uint16_t K_Window_EnhancedCurrent_Increase_Time = 20U;      /*10ms x */
const uint16_t K_Window_EnhancedCurrent_Threshold_Time = 2U;     /*10ms x */

const uint16_t K_Window_SoftStall_Detect_Time = 50U;    /*10ms x */
const uint16_t K_Window_FixedCurrent_Detect_Time = 10U;    /*10ms x */

const uint16_t K_WindowHomePosition_Delay_Time = 10U; /*10m x 10 */
const uint16_t K_WindowSpreadPosition_Delay_Time = 10U; /*10m x 10 */

const uint16_t K_Window_EnhancedCurrent_Detect_PushPID_Open_Adder[10] = {10,10,10,10,10,10,10,10,10,10};
const uint16_t K_Window_EnhancedCurrent_Detect_PushPID_Close_Adder[10] = {10,10,10,10,10,10,10,10,10,10};

const uint16_t K_Window_EnhancedCurrent_Detect_Open[8][10] = 
{
	{80,80,80,80,80,80,80,80,80,80},  /*<09V*/
	{80,80,80,80,80,80,80,80,80,80},  /*<10V*/
	{80,80,80,80,80,80,80,80,80,80},  /*<11V*/
	{80,80,80,80,80,80,80,80,80,80},  /*<12V*/
	{80,80,80,80,80,80,80,80,80,80},  /*<13V*/
	{80,80,80,80,80,80,80,80,80,80},  /*<14V*/
	{80,80,80,80,80,80,80,80,80,80},  /*<15V*/
	{80,80,80,80,80,80,80,80,80,80},  /*<16V*/
};

const uint16_t K_Window_EnhancedCurrent_Detect_Open_Temp[8][10] = 
{
	{0,0,0,0,0,0,0,0,0,0},  /*-40degree*/
	{0,0,0,0,0,0,0,0,0,0},   /*-25degree*/
	{0,0,0,0,0,0,0,0,0,0},    /*-10degree*/
	{0,0,0,0,0,0,0,0,0,0},  /*+05degree*/
	{0,0,0,0,0,0,0,0,0,0},   /*+20degree*/
	{0,0,0,0,0,0,0,0,0,0},   /*+35degree*/
	{0,0,0,0,0,0,0,0,0,0},   /*+50degree*/
	{0,0,0,0,0,0,0,0,0,0},   /*+65degree*/
};

const uint16_t K_Window_EnhancedCurrent_Detect_Close[8][10] = 
{
	{80,80,80,80,80,90,100,100,100,100},  /*<09V*/
	{80,80,80,80,80,90,100,100,100,100},  /*<10V*/
	{80,80,80,80,80,90,100,100,100,100},  /*<11V*/
	{80,80,80,80,80,90,100,100,100,100},  /*<12V*/
	{80,80,80,80,80,90,100,100,100,100},  /*<13V*/
	{80,80,80,80,80,90,100,100,100,100},  /*<14V*/
	{80,80,80,80,80,90,100,100,100,100},  /*<15V*/
	{80,80,80,80,80,90,100,100,100,100},  /*<16V*/
};

const uint16_t K_Window_EnhancedCurrent_Detect_Close_Temp[8][10] = 
{
	{0,0,0,0,0,0,0,0,0,0},  /*-40degree*/
	{0,0,0,0,0,0,0,0,0,0},   /*-25degree*/
	{0,0,0,0,0,0,0,0,0,0},    /*-10degree*/
	{0,0,0,0,0,0,0,0,0,0},  /*+05degree*/
	{0,0,0,0,0,0,0,0,0,0},   /*+20degree*/
	{0,0,0,0,0,0,0,0,0,0},   /*+35degree*/
	{0,0,0,0,0,0,0,0,0,0},   /*+50degree*/
	{0,0,0,0,0,0,0,0,0,0},   /*+65degree*/
};

const uint16_t K_Window_SoftStallCurrent_TopLimit[8][8]=
{     
     /* 9v  10v 11v 12v 13v14v15v16v  */
	{800,800,800,800,800,800,800,800},
	{800,800,800,800,800,800,800,800},
	{800,800,800,800,800,800,800,800},
	{800,800,800,800,800,800,800,800},
	{800,800,800,800,800,800,800,800},
	{800,800,800,800,800,800,800,800},
	{800,800,800,800,800,800,800,800},
	{800,800,800,800,800,800,800,800},
};

const uint16_t K_Window_FixedCurrentStall_TopLimit[8][8]=
{     
      /* 9v  10v 11v 12v 13v14v15v16v  */
	{1000,1000,1000,1000,1000,1000,1000,1000},
	{1000,1000,1000,1000,1000,1000,1000,1000},
	{1000,1000,1000,1000,1000,1000,1000,1000},
	{1000,1000,1000,1000,1000,1000,1000,1000},
	{1000,1000,1000,1000,1000,1000,1000,1000},
	{1000,1000,1000,1000,1000,1000,1000,1000},
	{1000,1000,1000,1000,1000,1000,1000,1000},
	{1000,1000,1000,1000,1000,1000,1000,1000},
};

const uint16_t K_Window_WindowPowerOpening_Duty[8][8]=
{     
      /* 9v  10v 11v 12v 13v14v15v16v  */
	{30,30,30,30,30,30,30,30},
	{30,30,30,30,30,30,30,30},
	{30,30,30,30,30,30,30,30},
	{30,30,30,30,30,30,30,30},
	{30,30,30,30,30,30,30,30},
	{30,30,30,30,30,30,30,30},
	{30,30,30,30,30,30,30,30},
	{30,30,30,30,30,30,30,30}
};
const uint16_t K_Window_WindowPowerOpening_Duty_2nd[8][8]=
{     
	 /* 9v  10v 11v 12v 13v14v15v16v  */
	{30,30,30,30,30,30,30,30},
	{30,30,30,30,30,30,30,30},
	{30,30,30,30,30,30,30,30},
	{30,30,30,30,30,30,30,30},
	{30,30,30,30,30,30,30,30},
	{30,30,30,30,30,30,30,30},
	{30,30,30,30,30,30,30,30},
	{30,30,30,30,30,30,30,30}
 
};
const uint16_t K_Window_WindowPowerClosing_Duty[8][8]=
{     
     /* 9v  10v 11v 12v 13v14v15v16v  */
	{30,30,30,30,30,30,30,30},
	{30,30,30,30,30,30,30,30},
	{30,30,30,30,30,30,30,30},
	{30,30,30,30,30,30,30,30},
	{30,30,30,30,30,30,30,30},
	{30,30,30,30,30,30,30,30},
	{30,30,30,30,30,30,30,30},
	{30,30,30,30,30,30,30,30}
};

const uint16_t K_Window_WindowPowerClosing_Duty_2nd[8][8]=
{     
      /* 9v  10v 11v 12v 13v14v15v16v  */
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20},
	{20,20,20,20,20,20,20,20}
};
const uint16_t K_Window_PositionObstacle_Detect_Delta = 20U;
const uint16_t K_Window_PositionObstacle_Detect_Open_Timer[10] = {10,10,10,10,10,10,10,10,10,10};
const uint16_t K_Window_PositionObstacle_Detect_Close_Timer[10] = {10,10,10,10,10,10,10,10,10,10};

const uint16_t K_Window_HallPluse1Width_Time = 30U;
const uint16_t K_Window_HallPluse2Width_Time = 30U;

const uint16_t K_Window_SpeedZoneIndex = 20U;
const uint16_t K_Window_HallCountPerSpeedZone_Min = 60U;
const uint16_t K_Window_HallCountPerSpeedZone_Max = 100U;
const uint16_t K_Window_HallCountPerSpeedZone_Default = 80U;

/* Desired power opening speed value */
const uint16_t K_Window_Desired_Open_Speed[8][20] = 
{
	{10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10},          /*-40degree*/
	{10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10},          /*-25degree*/
	{10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10},          /*-10degree*/
	{10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10},          /*+05degree*/
	{10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10},          /*+20degree*/
	{10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10},          /*+35degree*/
	{10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10},          /*+50degree*/
	{10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10},          /*+65degree*/
};

/* Desired power closing speed value */
const uint16_t K_Window_Desired_Close_Speed[8][20] = 
{
	{10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10},          /*-40degree*/
	{10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10},          /*-25degree*/
	{10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10},          /*-10degree*/
	{10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10},          /*+05degree*/
	{10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10},          /*+20degree*/
	{10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10},          /*+35degree*/
	{10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10},          /*+50degree*/
	{10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10},          /*+65degree*/
};
const uint16_t K_Window_FixedVoltage_Open_Enable[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
const uint16_t K_Window_FixedVoltage_Close_Enable[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
const uint16_t K_Window_FixedVoltage_Open_Duty[20] = {50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50};
const uint16_t K_Window_FixedVoltage_Close_Duty[20] = {50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50};
const uint16_t K_Window_FixedVoltage_Open_Timeout[20] = {100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100};
const uint16_t K_Window_FixedVoltage_Close_Timeout[20] = {100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100};

const uint16_t K_Window_PID_PWM_Max_PowerOpening[20] = {100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100};
const uint16_t K_Window_PID_PWM_Max_PowerClosing[20] = {100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100};

const uint16_t K_Window_Opening_IncreaseDuty_Time = 1U; /*10ms x*/
const uint16_t K_Window_Opening_IncreasePerTime_Duty = 2U;
const uint16_t K_Window_Closing_IncreaseDuty_Time = 1U; /*10ms x*/
const uint16_t K_Window_Closing_IncreasePerTime_Duty = 2U; 
const uint16_t K_Window_Opening_Start_Duty[10] = {60,60,60,60,60,60,60,60,60,60};
const uint16_t K_Window_Closing_Start_Duty[10] = {80,80,80,80,80,80,80,80,80,80};
const uint16_t K_Window_SoftStop_Opening_Step_Duty = 2U;
const uint16_t K_Window_SoftStop_Opening_Step_Time = 1U; /* 10ms x 5 */
const uint16_t K_Window_SoftStop_Opening_End_Duty  = 30U;
const uint16_t K_Window_SoftStop_Closing_Step_Duty = 2U;
const uint16_t K_Window_SoftStop_Closing_Step_Time = 1U; /* 10ms x 5 */
const uint16_t K_Window_SoftStop_Closing_End_Duty  = 40U;
const uint16_t K_WindowHallObstacle_SoftStop_Time = 100U; /* 10ms x 100 */

const uint16_t K_Window_SoftStart_Opening_HallCount_LowLimit = 0U; /**/
const uint16_t K_Window_SoftStart_Closing_HallCount_LowLimit = 0U;
const uint16_t K_Window_SoftStart_Opening_HallCount_HighLimit = 1200U; /**/
const uint16_t K_Window_SoftStart_Closing_HallCount_HighLimit = 1200U;

const uint16_t K_WindowPowerOpening_Speedup_Time = 50U; /* 10ms x */
const uint16_t K_WindowPowerClosing_Speedup_Time = 50U; /* 10ms x */
const uint16_t K_WindowPowerOpening_HardStart_Time[10] = {30,30,30,30,30,30,30,30,30,30}; /* 10ms x */
const uint16_t K_WindowPowerClosing_HardStart_Time[10] = {30,30,30,30,30,30,30,30,30,30}; /* 10ms x */

const uint16_t K_Window_HardStart_Enable = TRUE;
const uint16_t K_Window_Speedup_OpenInLowZone_HallCount = 20U;
const uint16_t K_Window_Speedup_OpenInMiddleZone_HallCount = 20U;
const uint16_t K_Window_Speedup_OpenInHighZone_HallCount = 20U;

const uint16_t K_Window_Speedup_CloseInLowZone_HallCount = 20U;
const uint16_t K_Window_Speedup_CloseInMiddleZone_HallCount = 20U;
const uint16_t K_Window_Speedup_CloseInHighZone_HallCount = 20U;

const uint16_t K_Window_SpeedupInLowZone_HallCount = 100U;   
const uint16_t K_Window_SpeedupInHighZone_HallCount = 500U; 

const uint16_t K_Window_SpeedupInLowZone_Open_Duty[8][8] = 
{
        {60,60,60,60,60,60,60,50},  /*-40degree*/
	{60,60,60,60,60,60,60,50},  /*-25degree*/
	{60,60,60,60,60,60,60,50},  /*-10degree*/
	{60,60,60,60,60,60,60,50},  /*+05degree*/
	{60,60,60,60,60,60,60,50},  /*+20degree*/
	{60,60,60,60,60,60,60,50},  /*+35degree*/
	{60,60,60,60,60,60,60,50},  /*+50degree*/
	{60,60,60,60,60,60,60,50},   /*+65degree*/
};

const uint16_t K_Window_SpeedupInLowZone_Close_Duty[8][8] = 
{
        {60,60,60,60,60,60,60,50},  /*-40degree*/
	{60,60,60,60,60,60,60,50},  /*-25degree*/
	{60,60,60,60,60,60,60,50},  /*-10degree*/
	{60,60,60,60,60,60,60,50},  /*+05degree*/
	{60,60,60,60,60,60,60,50},  /*+20degree*/
	{60,60,60,60,60,60,60,50},  /*+35degree*/
	{60,60,60,60,60,60,60,50},  /*+50degree*/
	{60,60,60,60,60,60,60,50},   /*+65degree*/
};

const uint16_t K_Window_SpeedupInMiddleZone_Open_Duty[8][8] = 
{
	{30,30,30,30,30,30,30,30},   /*-40degree*/
	{30,30,30,30,30,30,30,30},   /*-25degree*/
	{30,30,30,30,30,30,30,30},   /*-10degree*/
	{30,30,30,30,30,30,30,30},   /*+05degree*/
	{30,30,30,30,30,30,30,30},   /*+20degree*/
	{30,30,30,30,30,30,30,30},   /*+35degree*/
	{30,30,30,30,30,30,30,30},   /*+50degree*/
	{30,30,30,30,30,30,30,30}    /*+65degree*/
};

const uint16_t K_Window_SpeedupInMiddleZone_Close_Duty[8][8] = 
{
	{30,30,30,30,30,30,30,30},   /*-40degree*/
	{30,30,30,30,30,30,30,30},   /*-25degree*/
	{30,30,30,30,30,30,30,30},   /*-10degree*/
	{30,30,30,30,30,30,30,30},   /*+05degree*/
	{30,30,30,30,30,30,30,30},   /*+20degree*/
	{30,30,30,30,30,30,30,30},   /*+35degree*/
	{30,30,30,30,30,30,30,30},   /*+50degree*/
	{30,30,30,30,30,30,30,30}    /*+65degree*/
};

const uint16_t K_Window_SpeedupInHighZone_Open_Duty[8][8] = 
{
	{30,30,30,30,30,30,30,30},   /*-40degree*/
	{30,30,30,30,30,30,30,30},   /*-25degree*/
	{30,30,30,30,30,30,30,30},   /*-10degree*/
	{30,30,30,30,30,30,30,30},   /*+05degree*/
	{30,30,30,30,30,30,30,30},   /*+20degree*/
	{30,30,30,30,30,30,30,30},   /*+35degree*/
	{30,30,30,30,30,30,30,30},   /*+50degree*/
	{30,30,30,30,30,30,30,30}    /*+65degree*/
};

const uint16_t K_Window_SpeedupInHighZone_Close_Duty[8][8] = 
{
	{30,30,30,30,30,30,30,30},   /*-40degree*/
	{30,30,30,30,30,30,30,30},   /*-25degree*/
	{30,30,30,30,30,30,30,30},   /*-10degree*/
	{30,30,30,30,30,30,30,30},   /*+05degree*/
	{30,30,30,30,30,30,30,30},   /*+20degree*/
	{30,30,30,30,30,30,30,30},   /*+35degree*/
	{30,30,30,30,30,30,30,30},   /*+50degree*/
	{30,30,30,30,30,30,30,30}    /*+65degree*/
};

const uint16_t K_Window_ShortDistanceInOpening_HallCount[10] = {250,250,250,250,250,250,250,250,250,250};
const uint16_t K_Window_ShortDistanceInClosing_HallCount[10] = {100,100,100,100,100,100,100,100,100,100};

const uint16_t K_Window_ContinueObstacle_Reversal_Count = 2U;
const uint16_t K_Window_TotalObstacle_Reversal_Count = 6U;

const uint16_t K_WindowLearned_Position_Default = 1000U;
#endif



/*********************************************************************************************
** End of file
*********************************************************************************************/
