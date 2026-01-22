

/*********************************************************************************************
** Header Files
*********************************************************************************************/

#include "typedefs.h"
//#include "os_timer.h"
#include "system_control.h"
#include "system_calibration.h"
//#include "project_calibration.h"
//#include "com_calibration.h"
//#include "speed_control.h"
//#include "obstacle_detect.h"
//#include "fault_process.h"
//#include "request_process.h"
//#include "api_interface.h"
//#include "pinout_manage.h"
//#include "r_cg_taub.h"
//#include "r_cg_taud.h"
//#include "BTN8962.h"
//#include "BTS5030.h"
//#include "VNH7040.h"
//#include "Sbc_Tle9263.h"
//#include "Sbc_Tle9562.h"
//#include "Sbc_Tle9562_Types.h"
//#include "r_cg_tauj.h"
//#include "r_cg_adc.h"
//#include "r_cg_wdt.h"
//#include "eel_data_operation.h"
//#include "r_eel_types.h"
//#include "DRV8702.h"
//#include "BTS7040.h"
//#include "DRV8705.h"

//#include "r_cg_port.h"
//#include "r_cg_userdefine.h"
//#include "r_cg_macrodriver.h"
//
//#include "window_control.h"
//#include "spoiler_control.h"
//#include "spoiler_app.h"
//#include "handle_control.h"
//
//#include "uds_calibrate.h"
//#include "gate_calibration.h"
//#include "gate_calibrationfile.h"
//#include "door_calibration.h"
//#include "door_calibrationfile.h"

/*********************************************************************************************
** Global Variables Definitions
*********************************************************************************************/
uint8_t SoftStop_Working_Status;
uint8_t SoftStart_Working_Status;
uint8_t SoftStop_Finish_Status;

uint8_t Motor1_SoftStop_Enable;
uint8_t Motor1_SoftStop_Finish_Status;
uint8_t Motor1_BrakeToGround_Status;
uint8_t Motor1_BrakeToBattery_Status;
uint8_t Motor1_Direction_Request;
uint8_t Motor1_Working_Status;
uint8_t Motor1_Working_LastStatus;
//tD_Direction_Request Motor1_Direction_Status;


uint8_t Motor2_SoftStop_Enable;
uint8_t Motor2_SoftStop_Finish_Status;
uint8_t Motor2_BrakeToGround_Status;
uint8_t Motor2_BrakeToBattery_Status;
uint8_t Motor2_Direction_Request;
uint8_t Motor2_Working_Status;
uint8_t Motor2_Working_LastStatus;
//tD_Direction_Request Motor2_Direction_Status;

uint8_t CinchMotor_BrakeToGround_Status;
uint8_t CinchMotor_BrakeToBattery_Status;
uint8_t CinchMotor_Direction_Request;
uint8_t CinchMotor_Working_Status;
uint8_t CinchMotor_Working_LastStatus;
uint8_t CinchMotor_Direction_Status;


uint8_t Motor4_BrakeToGround_Status;
uint8_t Motor4_BrakeToBattery_Status;
uint8_t Motor4_Direction_Request;
uint8_t Motor4_Working_Status;
uint8_t Motor4_Working_LastStatus;

uint8_t ReleaseMotor_Direction_Request;
uint8_t ReleaseMotor_Working_Status;
uint8_t ReleaseMotor_Working_LastStatus;
uint8_t ReleaseMotor_Direction_Status;

uint8_t Clutch_Direction_Request;
uint8_t Clutch_Working_Status;
uint8_t Clutch_Direction_Status;

uint8_t Buzzer_Working_Status;
uint8_t Speaker_Working_Status;

#if defined(_CONFIG_BTS5030) || defined(_CONFIG_BTS7040)
uint8_t BTS_IN0_CurrentSensor_Status;
uint8_t BTS_IN1_CurrentSensor_Status;
#endif

uint16_t HallA1_Low_Pluse_Timer;
uint16_t HallA2_Low_Pluse_Timer;
uint16_t HallA1_High_Pluse_Timer;
uint16_t HallA2_High_Pluse_Timer;
uint16_t HallA1_HallCounter;
uint16_t HallA2_HallCounter;

uint16_t HallB1_Low_Pluse_Timer;
uint16_t HallB2_Low_Pluse_Timer;
uint16_t HallB1_High_Pluse_Timer;
uint16_t HallB2_High_Pluse_Timer;
uint16_t HallB1_HallCounter;
uint16_t HallB2_HallCounter;


#ifdef _CONFIG_Flasher
uint8_t Flasher_Working_Status;
#endif

uint8_t HallPower_Status;

//#ifdef _CONFIG_Gen3_Board
uint8_t HallPower1_Status;
uint8_t HallPower2_Status;
uint8_t LatchSwitchPower_Status;
//#endif

#ifdef _CONFIG_Motor4
uint16_t Motor4_HallCounter;
uint16_t Motor4_HallPluse1Width_Timer;
uint16_t Motor4_HallPluse2Width_Timer;
uint8_t Motor4_Working_Status;
tD_Direction_Request Motor4_Direction_Status;

uint16_t Motor4_Position;
int16_t Motor4_Location;
#endif

#ifdef _CONFIG_HallC
uint16_t HallC_Accumulator;
uint16_t HallC1_DynamicDiag_HallCounter;
uint16_t HallC2_DynamicDiag_HallCounter;
uint16_t HallC1_HallCounter;
uint16_t HallC2_HallCounter;
uint8_t HallC1_Status;
uint8_t HallC2_Status;

uint16_t HallC1_Low_Pluse_Timer;
uint16_t HallC2_Low_Pluse_Timer;
uint16_t HallC1_High_Pluse_Timer;
uint16_t HallC2_High_Pluse_Timer;

uint8_t HallC1_Diagnostic_Working_Status;
uint8_t HallC2_Diagnostic_Working_Status;

uint8_t HallPower3_Status;
#endif

#ifdef _CONFIG_HallD
uint16_t HallD_Accumulator;
uint16_t HallD1_DynamicDiag_HallCounter;
uint16_t HallD2_DynamicDiag_HallCounter;
uint16_t HallD1_HallCounter;
uint16_t HallD2_HallCounter;
uint8_t HallD1_Status;
uint8_t HallD2_Status;

uint16_t HallD1_Low_Pluse_Timer;
uint16_t HallD2_Low_Pluse_Timer;
uint16_t HallD1_High_Pluse_Timer;
uint16_t HallD2_High_Pluse_Timer;

uint8_t HallD1_Diagnostic_Working_Status;
uint8_t HallD2_Diagnostic_Working_Status;

uint16_t CinchMotor_HallCounter;
uint16_t CinchMotor_HallPluse1Width_Timer;
uint16_t CinchMotor_HallPluse2Width_Timer;
uint8_t CinchMotor_Working_Status;
tD_Direction_Request CinchMotor_Direction_Status;

uint16_t CinchMotor_Position;
int16_t CinchMotor_Location;
#endif
     

uint8_t VBATT1_SW_Feed_Status;
uint8_t VCC2_5V_Feed_Status;
uint8_t VCC3_5V_Feed_Status;
uint8_t SBC_HS3_OUT_Output_Status;
uint8_t HS4_Output_Status;

uint8_t HallA1_Status;
uint8_t HallA2_Status;
uint8_t HallB1_Status;
uint8_t HallB2_Status;

#ifdef _CONFIG_DIAG_Hall_StaticDiag
uint8_t HallA1_Diagnostic_Working_Status;
uint8_t HallA2_Diagnostic_Working_Status;
uint8_t HallB1_Diagnostic_Working_Status;
uint8_t HallB2_Diagnostic_Working_Status;
#endif

#ifdef _CONFIG_HighSideOutputControl
uint8_t Output_J2_1_Work_Status;
uint8_t Output_J2_2_Work_Status;
uint8_t Output_J3_1_Work_Status;
uint8_t Output_J3_2_Work_Status;
uint8_t Output_J3_3_Work_Status;
uint8_t Output_J3_4_Work_Status;
#endif

#ifdef _CONFIG_MOSFET_Connection
uint8_t CinchMotor1_Direction_Request;
uint8_t CinchMotor2_Direction_Request;
uint8_t ReleaseMotor1_Direction_Request;
uint8_t ReleaseMotor2_Direction_Request;

uint8_t CinchMotor1_Working_Status;
uint8_t CinchMotor2_Working_Status;
uint8_t ReleaseMotor1_Working_Status;
uint8_t ReleaseMotor2_Working_Status;

tD_H_Bridge_Side CinchMotor1_H_Bridge;
tD_H_Bridge_Side CinchMotor2_H_Bridge;
tD_H_Bridge_Side ReleaseMotor1_H_Bridge;
tD_H_Bridge_Side ReleaseMotor2_H_Bridge;

uint8_t CinchMotor1_Cinch_Disable;
uint8_t CinchMotor1_Neutral_Disable;
uint8_t ReleaseMotor1_Release_Disable;
uint8_t ReleaseMotor1_Findhome_Disable;

uint8_t CinchMotor2_Cinch_Disable;
uint8_t CinchMotor2_Neutral_Disable;
uint8_t ReleaseMotor2_Release_Disable;
uint8_t ReleaseMotor2_Findhome_Disable;
#endif
/* Test API, Need to remove in production */
uint16_t Flag_Motor1_Duty_Request;

#ifdef _CONFIG_ChipTest
uint8_t Flag_ShutFaceSwitch_RiseEdge;
uint8_t Flag_ShutFaceSwitch_FallEdge;
uint8_t Flag_ShutFaceSwitch_ShortPress;
uint8_t Flag_ShutFaceSwitch_LongPress;
	
uint8_t Flag_test;
uint16_t Time_Test1;
uint16_t Time_Test2;
uint16_t Time_Test_Delta;
uint8_t CMUR1;

uint16_t HallCount_Test;



uint8_t EEL_Test0 = 0;
uint16_t EEL_Test1 = 0;
uint16_t EEL_Test2 = 0;
uint16_t EEL_Test3 = 0;
uint32_t EEL_Test4 = 0;
r_eel_status_t Mem_Read_Return_Test0;
r_eel_status_t Mem_Read_Return_Test1;
r_eel_status_t Mem_Read_Return_Test2;
r_eel_status_t Mem_Read_Return_Test3;
r_eel_status_t Mem_Read_Return_Test4;

#endif
#ifdef _CONFIG_SbcTest
uint8_t SBC_Reset_Reason;
#endif

/*********************************************************************************************
** Variables at File Scope
*********************************************************************************************/
#ifdef _CONFIG_ChipTest
#ifdef _CONFIG_Gen1_Board
uint16_t Get_ODL_0_DIA_AD ;   
uint16_t Get_ODH_0_DIA_AD ;    
uint16_t Get_OPX_1_DIA_AD ;    
uint16_t Get_OPX_0_DIA_AD ;    
uint16_t Get_IGN_SW_IN_AD ;   
uint16_t Get_Motor1_AD ;       
uint16_t Get_Motor2_AD ;       
uint16_t Get_CINCH_SEN_AD ;    
uint16_t Get_IA_0_MIN_AD ;     
uint16_t Get_IA_1_MIN_AD ;     
uint16_t Get_HS_SENSE_IA_AD ;  
uint16_t Get_VCC2_5V_DIA_AD ;  
uint16_t Get_Temp_AD ;         
uint16_t Get_VBATT1_SW_AD ;   
uint16_t Get_VBATT2_AD ;       
uint16_t Get_VBATT1_AD ;       
uint16_t Get_ODH_3_DIA_AD ;    
uint16_t Get_ODH_4_DIA_AD ;    
uint16_t Get_ODH_2_DIA_AD ;    
uint16_t Get_ODH_1_DIA_AD ;    
uint16_t Get_ODH_6_DIA_AD ;    
uint16_t Get_ODH_5_DIA_AD ; 

uint16_t Get_ODL_0_STA;                 
uint16_t Get_IDL_1_MIN;                 
uint16_t Get_IDL_0_MIN;                 
uint16_t Get_IDX_0_MIN;                 
uint16_t Get_IDL_8_MIN;                 
uint16_t Get_IDX_1_MIN;                 
uint16_t Get_IDL_7_MIN;                 
uint16_t Get_IDL_3_MIN;                 
uint16_t Get_IDL_2_MIN;                 
uint16_t Get_IDL_4_MIN;                 
uint16_t Get_IDL_9_MIN;                 
uint16_t Get_IDL_5_MIN;                 
uint16_t Get_IDL_6_MIN;                 
uint16_t Get_FO1;
#endif

#ifdef _CONFIG_Gen2_Board
uint16_t Get_HS2_DIA_U1_67_AD;
uint16_t Get_HS1_DIA_U1_68_AD;
uint16_t Get_J2_2_DIA_U1_66_AD;
uint16_t Get_J2_1_DIA_U1_65_AD;
uint16_t Get_HS3_OUT_AD;
uint16_t Get_Motor1_AD_U1_63_AD;
uint16_t Get_Motor2_AD_U1_62_AD;
uint16_t Get_Motor3_AD_U1_61_AD;
uint16_t Get_IA_0_MIN_U1_60_AD;
uint16_t Get_IA_1_MIN_U1_59_AD;
uint16_t Get_HS_DIA_U1_58_AD;
uint16_t Get_VCC2_5V_AD;
uint16_t Get_Thermistor_U1_56_AD;
uint16_t Get_Hall_Power_AD;
uint16_t Get_VBATT2_AD_U1_54_AD;
uint16_t Get_VBATT1_AD_U1_53_AD;
uint16_t Get_J3_1_DIA_U1_20_AD;
uint16_t Get_J3_2_DIA_U1_21_AD;
uint16_t Get_VBATT1_SW_AD;
uint16_t Get_J3_3_DIA_U1_71_AD;
uint16_t Get_J3_4_DIA_U1_72_AD;
 
uint16_t Get_IDL_11_MIN_U1_2;
uint16_t Get_IDL_1_MIN_U1_8;
uint16_t Get_IDL_0_MIN_U1_9;
uint16_t Get_IDL_5_MIN_U1_12;
uint16_t Get_IDL_6_MIN_U1_11;

uint16_t Get_IDX_0_MIN_U1_15;
uint16_t Get_IDL_8_MIN_U1_16;
uint16_t Get_IDX_1_MIN_U1_17;
uint16_t Get_IDL_7_MIN_U1_19;
uint16_t Get_IDL_3_MIN_U1_37;
uint16_t Get_IDL_2_MIN_U1_38;
uint16_t Get_IDL_4_MIN_U1_43;

uint16_t Get_IDL_9_MIN_U1_73;
uint16_t Get_U4_Fault_U1_98;
uint16_t Get_IDL_10_U1_100;

uint16_t Get_FO1_U1_95;
uint16_t Get_CANRX;

uint16_t Get_UP_Wakeup_U1_93;
uint16_t Get_Down_Wakeup_U1_94;
uint16_t Get_U5_Fault_U1_13;
 
uint8_t Get_Hall_1A_U1_42;
uint8_t Get_Hall_1B_U1_44;
uint8_t Get_Hall_2A_U1_45;
uint8_t Get_Hall_2B_U1_46;
#endif

#ifdef _CONFIG_Gen3_Board
uint16_t Get_HS1_DIA_AP0_0_AD;
uint16_t Get_HS2_DIA_AP0_1_AD;
uint16_t Get_M3_DIA_AP0_2_AD;
uint16_t Get_M3_DIA_AP0_3_AD;
uint16_t Get_M4_DIA_AP0_4_AD;
uint16_t Get_M1_AD_AP0_5_AD;
uint16_t Get_M2_AD_AP0_6_AD;
uint16_t Get_M3_AD_AP0_7_AD;
uint16_t Get_AI1_AP0_8_AD;
uint16_t Get_AI2_AP0_9_AD;
uint16_t Get_7040_DIA_AP0_10_AD;
uint16_t Get_M4_DIA_AP0_11_AD;
uint16_t Get_Temp_AD_AP0_12_AD;
uint16_t Get_M4_AD_AP0_13_AD;
uint16_t Get_Load_12V_AD_AP0_14_AD;
uint16_t Get_DIG_12V_AD_AP0_15_AD;
 
uint16_t Get_M1_DIA_P8_10_AD;
uint16_t Get_M1_DIA_P8_11_AD;
uint16_t Get_M2_DIA_P9_2_AD;
uint16_t Get_M2_DIA_P9_3_AD;


uint8_t Get_DI_X2_20_P10_4;
uint8_t Get_Speaker_DIA_P11_0;
uint8_t Get_DI_X2_3_P0_2;
uint8_t Get_DI_X2_11_P0_3;
uint8_t Get_DI_X2_21_P0_4;
uint8_t Get_DI_X2_7_P0_5;
uint8_t Get_DI_X2_2_P0_6;
uint8_t Get_DI_X2_18_P0_11;
uint8_t Get_DI_X2_10_P0_12;
uint8_t Get_DI_X2_9_P8_2;
uint8_t Get_DI_X2_22_P8_12;
uint8_t Get_LSD_DIA_JP0_3;
uint8_t Get_DI_X2_1_P0_10;
uint8_t Get_DI_X2_4_P0_9;
uint8_t Get_DI_X2_24_P9_4;
uint8_t Get_SBC_INT_P0_7;
uint8_t Get_DI_X2_8_P8_1;

uint8_t Get_Hall_1A_P8_0;
uint8_t Get_Hall_2B_P8_3;
uint8_t Get_Hall_2A_P8_4;
uint8_t Get_Hall_1B_P8_5;

uint8_t Get_Hall_Power1_DIA_P9_0;
uint8_t Get_Hall_Power2_DIA_P9_5;

uint8_t Get_M1_Fault_P10_6;
uint8_t Get_M4_Fault_P11_6;
uint8_t Get_M3_Fault_P11_7;
uint8_t Get_M2_Fault_P10_0;
uint8_t Get_CANRX;
#endif


#ifdef _CONFIG_Gen4_Board
uint16_t Get_HS1_DIA_AP0_0_AD;
uint16_t Get_HS2_DIA_AP0_1_AD;
uint16_t Get_M3_DIA_AP0_2_AD;
uint16_t Get_M3_DIA_AP0_3_AD;
uint16_t Get_M4_DIA_AP0_4_AD;
uint16_t Get_M1_AD_AP0_5_AD;
uint16_t Get_M2_AD_AP0_6_AD;
uint16_t Get_M3_AD_AP0_7_AD;
uint16_t Get_M4_DIA_AP0_8_AD;
uint16_t Get_AI1_AP0_9_AD;
uint16_t Get_7040_DIA_AP0_10_AD;
uint16_t Get_AI2_AP0_11_AD;
uint16_t Get_Temp_AD_AP0_12_AD;
uint16_t Get_M4_AD_AP0_13_AD;
uint16_t Get_Load_12V_AD_AP0_14_AD;
uint16_t Get_DIG_12V_AD_AP0_15_AD;
 
uint16_t Get_M1_DIA_P8_10_AD;
uint16_t Get_M1_DIA_P8_8_AD;
uint16_t Get_M2_DIA_P9_2_AD;
uint16_t Get_M2_DIA_P9_3_AD;

uint16_t Get_AI_DI_1_X2_15_P8_6_AD;
uint16_t Get_Hall_3A_X2_24_P9_4_AD;
uint16_t Get_Hall_3B_X2_22_P9_5_AD;
uint16_t Get_Hall_4A_X2_21_P8_11_AD;
uint16_t Get_Hall_4B_X2_20_P8_12_AD;

uint8_t Get_DI_X2_20_P8_12;
uint8_t Get_DI_X2_3_P0_2;
uint8_t Get_DI_X2_11_P10_3;
uint8_t Get_DI_X2_21_P8_11;
uint8_t Get_DI_X2_7_P8_9;
uint8_t Get_DI_X2_2_P0_4;
uint8_t Get_DI_X2_18_P0_6;
uint8_t Get_DI_X2_10_P8_7;
uint8_t Get_DI_X2_9_P8_2;
uint8_t Get_DI_X2_22_P10_5;
uint8_t Get_DI_X2_1_P0_3;
uint8_t Get_DI_X2_4_P0_5;
uint8_t Get_DI_X2_24_P10_12;
uint8_t Get_SBC_INT_P0_7;
uint8_t Get_DI_X2_8_P10_6;

uint8_t Get_Hall_1A_P9_4;
uint8_t Get_Hall_2B_P8_3;
uint8_t Get_Hall_2A_P8_4;
uint8_t Get_Hall_1B_P8_5;

uint8_t Get_Hall_Power1_DIA_P0_10;
uint8_t Get_Hall_Power2_DIA_P10_14;
uint8_t Get_Hall_Power3_DIA_P10_4;

uint8_t Get_M_Fault_P10_6;
uint8_t Get_CANRX;

#ifdef _CONFIG_AI_DI_1_X2_15_P8_6_As_DI
uint8_t Get_AI_DI_1_X2_15_P8_6;
#endif
#ifndef _CONFIG_DI_2_LSD_X2_23_P11_7_As_Output
uint8_t Get_DI_2_LSD_X2_23_P11_7;
#endif
#ifndef _CONFIG_AI_1_X2_12_AP0_9_As_AI
uint8_t Get_AI_1_X2_12_AP0_9;
#endif
#ifndef _CONFIG_AI_2_X2_13_AP0_11_As_AI
uint8_t Get_AI_2_X2_13_AP0_11;
#endif
#ifdef _CONFIG_HallC_As_DI
uint8_t Get_Hall_3A_X2_24_P9_4;
uint8_t Get_Hall_3B_X2_22_P9_5;
#endif
#ifdef _CONFIG_HallD_As_DI
uint8_t Get_Hall_4A_X2_21_P8_11;
uint8_t Get_Hall_4B_X2_20_P8_12;
#endif

#endif
#endif



/*********************************************************************************************
** Functions with Global Scope
*********************************************************************************************/


/*********************************************************************************************
** Functions with Global Scope
*********************************************************************************************/

void API_Motor1_SoftStop_Trigger(void);
void API_Motor2_SoftStop_Trigger(void);



#ifdef _CONFIG_IncreaseStepDuty
uint16_t API_IncreaseStepDuty_Control(uint16_t Duty_Request,uint16_t Duty_Target,uint16_t OnePercentPWM_Value,uint16_t IncreaseStep_Duty);
#endif
#ifdef _CONFIG_DecreaseStepDuty
uint16_t API_DecreaseStepDuty_Control(uint16_t Duty_Request,uint16_t Duty_Target,uint16_t OnePercentPWM_Value,uint16_t DecreaseStep_Duty);
#endif
uint16_t API_ReferTo12Voltage_Duty(uint16_t vol_12v_duty);
uint16_t API_ReferTo12Voltage_Current(uint16_t vol_12v_current);
uint16_t API_ReferTo12Voltage_Data(uint16_t vol_12v_data);
int16_t API_ReferTo20Degree_Adder(int16_t temp_80_degree_data, int16_t temp_n40_degree_data);

#ifdef _CONFIG_CosSinDegree 
uint16_t API_Cos100Times(int16_t degree10times);
uint16_t API_Sin100Times(int16_t degree10times);
#endif
#ifdef _CONFIG_ArcSinDegree
uint16_t API_ArcSinDegree10Times(int16_t sin1000times);
#endif


void API_ECU_Soft_Reset(void);
void API_CinchMotor_BrakeToGround(void);
void API_CinchMotor_BrakeToBattery(void);

void API_Motor1_BrakeToGround(void);
void API_Motor1_BrakeToBattery(void);

void API_Motor2_BrakeToGround(void);
void API_Motor2_BrakeToBattery(void);

void API_Motor4_BrakeToGround(void);
void API_Motor4_BrakeToBattery(void);

#ifdef _CONFIG_Gen1_Board
void API_TurnOn_VBATT1_SW(void);
void API_TurnOff_VBATT1_SW(void);
#endif

 
#if defined(_CONFIG_Gen1_Board) || defined(_CONFIG_Gen2_Board)
void API_TurnOn_HallPower(void);
void API_TurnOff_HallPower(void);
#endif

#if defined(_CONFIG_Gen3_Board) || defined(_CONFIG_Gen4_Board)
void API_TurnOn_HallPower1(void);
void API_TurnOff_HallPower1(void);

void API_TurnOn_HallPower2(void);
void API_TurnOff_HallPower2(void);

void API_TurnOn_LatchSwitchPower(void);
void API_TurnOff_LatchSwitchPower(void);

void API_TurnOn_LoadPower_EN(void);
void API_TurnOff_LoadPower_EN(void);

#ifdef _CONFIG_HallC
void API_TurnOn_HallPower3(void);
void API_TurnOff_HallPower3(void);
#endif
#endif


void API_TurnOn_VCC2_5V(void);
void API_TurnOff_VCC2_5V(void);

void API_TurnOn_VCC3_5V(void);
void API_TurnOff_VCC3_5V(void);

void API_TurnOn_SBC_HS3(void);
void API_TurnOff_SBC_HS3(void);

void API_TurnOn_SBC_HS4(void);
void API_TurnOff_SBC_HS4(void);

void API_TurnOn_SBC_HS4_PWM1(void);
void API_Set_SBC_HS4_PercentDuty(uint16_t duty_percent);

void API_TurnOn_Diag_Power(void);
void API_TurnOff_Diag_Power(void);

void API_TurnOn_VBATT1_SW(void);
void API_TurnOff_VBATT1_SW(void);

void API_TurnOn_Batt_AD_EN(void);
void API_TurnOff_Batt_AD_EN(void);

void API_HallA1_Interrupt(void);
void API_HallA2_Interrupt(void);
void API_HallB1_Interrupt(void);
void API_HallB2_Interrupt(void);

void API_TurnOff_Motor1(void);
void API_TurnOff_Motor2(void);
void API_TurnOff_Motor4(void);

void API_TurnOn_Motor1_Open(void);
void API_TurnOn_Motor2_Open(void);
void API_TurnOn_Motor4_Open(void);

void API_TurnOn_Motor1_Close(void);
void API_TurnOn_Motor2_Close(void);
void API_TurnOn_Motor4_Close(void);

#ifdef _CONFIG_MagnaSideLatch_CCL
void API_TurnOn_Motor2_PRReset(void);
#endif

void API_TurnOff_CinchMotor(void);  
void API_TurnOn_CinchMotor_Cinch(void);
void API_TurnOn_CinchMotor_Neutral(void);


#if defined(_CONFIG_Clutch) || defined(_CONFIG_ClutchHold)
void API_TurnOn_Clutch(void);
void API_TurnOff_Clutch(void);
#endif

#ifdef _CONFIG_ReleaseMotor
void API_TurnOn_ReleaseMotor(void);
void API_TurnOff_ReleaseMotor(void);
#endif

void API_TurnOn_BTS_IN0_CurrentSensor(void);
void API_TurnOn_BTS_IN1_CurrentSensor(void);

void API_TurnOn_Buzzer(void);
void API_TurnOff_Buzzer(void);
void API_Set_Buzzer_Period(uint16_t period);
void API_Set_Buzzer_PercentDuty(uint16_t duty_percent);

void API_TurnOn_Speaker(void);
void API_TurnOff_Speaker(void);
void API_Set_Speaker_Period(uint16_t period_us);
void API_Set_Speaker_PercentDuty(uint16_t duty_percent);

#ifdef _CONFIG_Flasher
void API_TurnOn_Flasher(void);
void API_TurnOff_Flasher(void);
void API_Set_Flasher_Period(uint16_t period_us);
void API_Set_Flasher_Duty(uint16_t duty);
void API_Set_Flasher_PercentDuty(uint16_t duty_percent);
#endif


#ifdef _CONFIG_Gen1_Board
void API_TurnOn_LowSideOutput(void);
void API_TurnOff_LowSideOutput(void);
#endif

#ifdef _CONFIG_Gen3_Board
void API_TurnOn_LSD(void);
void API_TurnOff_LSD(void);

void API_TurnOn_LSD2(void);
void API_TurnOff_LSD2(void);
#endif

#ifdef _CONFIG_Gen4_Board
void API_TurnOn_LSD(void);
void API_TurnOff_LSD(void);
#endif

void API_Motor1_PWMDuty_Update(uint16_t duty,uint16_t direction);
void API_Motor2_PWMDuty_Update(uint16_t duty,uint16_t direction);
void API_CinchMotor_PWMDuty_Update(uint16_t duty,uint16_t direction);
void API_Motor4_PWMDuty_Update(uint16_t duty,uint16_t direction);
void API_ReleaseMotor_PWMDuty_Update(uint16_t duty);
void API_Buzzer_PWMDuty_Update(uint16_t duty);
void API_Clutch_PWMDuty_Update(uint16_t duty);

void API_Set_Motor1_PWMPeriod(uint16_t period);
void API_Set_Motor2_PWMPeriod(uint16_t period);
void API_Set_CinchMotor_PWMPeriod(uint16_t period);
void API_Set_Motor4_PWMPeriod(uint16_t period);

void API_Feed_Watchdog_SBC(void);
void API_Feed_Watchdog_MCU(void);
void API_ATD_Scan_Start(void);


#ifdef _CONFIG_HighSideOutputControl
/*Independent Motor Control*/
void API_Motor1_Control(uint16_t pecentduty,uint16_t direction);
void API_Motor1_Control(uint16_t pecentduty,uint16_t direction);
void API_CinchMotor_Control(uint16_t pecentduty,uint16_t direction);
void API_ReleaseMotor_Control(uint16_t pecentduty);

/*High and Low Side Output Control*/
void API_TurnOn_HS_Output_J2_1(void);
void API_TurnOn_HS_Output_J2_2(void);
void API_TurnOn_HS_Output_J3_1(void);
void API_TurnOn_HS_Output_J3_2(void);
void API_TurnOn_HS_Output_J3_3(void);
void API_TurnOn_HS_Output_J3_4(void);

void API_TurnOff_HS_Output_J2_1(void);
void API_TurnOff_HS_Output_J2_2(void);
void API_TurnOff_HS_Output_J3_1(void);
void API_TurnOff_HS_Output_J3_2(void);
void API_TurnOff_HS_Output_J3_3(void);
void API_TurnOff_HS_Output_J3_4(void);

void API_TurnOn_LS_Output_J2_1(void);
void API_TurnOn_LS_Output_J2_2(void);
void API_TurnOn_LS_Output_J3_1(void);
void API_TurnOn_LS_Output_J3_2(void);
void API_TurnOn_LS_Output_J3_3(void);
void API_TurnOn_LS_Output_J3_4(void);

void API_TurnOff_LS_Output_J2_1(void);
void API_TurnOff_LS_Output_J2_2(void);
void API_TurnOff_LS_Output_J3_1(void);
void API_TurnOff_LS_Output_J3_2(void);
void API_TurnOff_LS_Output_J3_3(void);
void API_TurnOff_LS_Output_J3_4(void);

void API_Output_J2_1_PWMDuty(uint16_t pecentduty,tD_H_Bridge_Side side);
void API_Output_J2_2_PWMDuty(uint16_t pecentduty,tD_H_Bridge_Side side);
void API_Output_J3_1_PWMDuty(uint16_t pecentduty,tD_H_Bridge_Side side);
void API_Output_J3_2_PWMDuty(uint16_t pecentduty,tD_H_Bridge_Side side);
void API_Output_J3_3_PWMDuty(uint16_t pecentduty,tD_H_Bridge_Side side);
void API_Output_J3_4_PWMDuty(uint16_t pecentduty,tD_H_Bridge_Side side);

void API_Set_Output_J2_1_PWMPeriod(uint16_t period);
void API_Set_Output_J2_2_PWMPeriod(uint16_t period);
void API_Set_Output_J3_1_PWMPeriod(uint16_t period);
void API_Set_Output_J3_2_PWMPeriod(uint16_t period);
void API_Set_Output_J3_3_PWMPeriod(uint16_t period);
void API_Set_Output_J3_4_PWMPeriod(uint16_t period);
#endif

/*Power Side Latch Motor Control*/
#ifdef _CONFIG_MOSFET_Connection
void API_TurnOn_CinchMotor1_Cinch(void);
void API_TurnOn_CinchMotor1_Neutral(void);
void API_TurnOn_ReleaseMotor1_Release(void);
void API_TurnOn_ReleaseMotor1_Findhome(void);

void API_TurnOn_CinchMotor2_Cinch(void);
void API_TurnOn_CinchMotor2_Neutral(void);
void API_TurnOn_ReleaseMotor2_Release(void);
void API_TurnOn_ReleaseMotor2_Findhome(void);

void API_TurnOff_CinchMotor1(void);
void API_TurnOff_CinchMotor2(void);
void API_TurnOff_ReleaseMotor1(void);
void API_TurnOff_ReleaseMotor2(void);

void API_CinchMotor1_PWMDuty_Update(uint16_t duty,uint16_t direction);
void API_CinchMotor2_PWMDuty_Update(uint16_t duty,uint16_t direction);
void API_ReleaseMotor1_PWMDuty_Update(uint16_t duty,uint16_t direction);
void API_ReleaseMotor2_PWMDuty_Update(uint16_t duty,uint16_t direction);

void API_CinchMotor1_BrakeToGround(void);
void API_CinchMotor1_BrakeToBattery(void);

void API_CinchMotor2_BrakeToGround(void);
void API_CinchMotor2_BrakeToBattery(void);

void API_ReleaseMotor1_BrakeToGround(void);
void API_ReleaseMotor1_BrakeToBattery(void);

void API_ReleaseMotor2_BrakeToGround(void);
void API_ReleaseMotor2_BrakeToBattery(void);
#endif


/*Test API, Need to remove in production*/

void API_Task_Scheduler_Test(void);
void API_Analog_Value_ATD_Test(void); 
void API_SBC_HS_Test(void);
void API_Switch_Input_Test(void);

void API_CAN_Implement_Test(void);
void API_EEL_Implement_Test(void);

void API_Speaker_Test(void);
void API_Tle9263_Test(void);
void API_Tle9562_Test(void);
void API_DRV8702_Test(void);
void API_DRV8705_Test(void);

void API_ManualCurrentCalibrate(void);  /* Need to OC Motor firstly Need to remove in production */

#ifdef _CONFIG_ChipTest
/*********************************************************************************************
** Name:	  API_DRV8702_Test
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_DRV8702_Test(void)
{ 
    //DRV8702_U3_Inactive();
    //API_TurnOn_Motor1_Open();  
    //API_TurnOn_Motor2_Open();  
    //API_TurnOn_CinchMotor_Neutral();
    //API_TurnOn_ReleaseMotor();
    
    //API_TurnOn_Motor1_Close();  
    //API_TurnOn_Motor2_Close(); 
    //API_TurnOn_CinchMotor_Cinch();   
    
    //API_TurnOff_Motor1(); 
    //API_TurnOff_Motor2();
    
    
    //Motor1_Duty_Request = 100 * Motor1_OnePercentPWM_Value;
    //Motor2_Duty_Request = 100 * Motor2_OnePercentPWM_Value;
    //CinchMotor_Duty_Request = 100 * CinchMotor_OnePercentPWM_Value;
    //ReleaseMotor_Duty_Request = 40 * ReleaseMotor_OnePercentPWM_Value;
    
    //API_Output_J2_1_PWMDuty(40,High_Side);
    //API_Output_J2_2_PWMDuty(40,High_Side);
    //API_Output_J3_1_PWMDuty(40,High_Side);
    //API_Output_J3_2_PWMDuty(40,High_Side);
    //API_Output_J3_3_PWMDuty(40,High_Side);
    //API_Output_J3_4_PWMDuty(40,High_Side);
    
    //API_TurnOn_LS_Output_J3_3();
    //API_TurnOn_HS_Output_J3_3();
    //API_TurnOff_LS_Output_J3_3();
}

/*********************************************************************************************
** Name:	  API_DRV8705_Test
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_DRV8705_Test(void)
{ 
   
    //DRV8705_U3_Inactive();
    //API_TurnOn_Motor1_Open();  
    //API_TurnOn_Motor2_Open();  
    //API_TurnOn_Motor4_Open();
    //API_TurnOn_CinchMotor_Neutral();
    //API_TurnOn_ReleaseMotor();
    //API_TurnOn_Buzzer();
    //API_TurnOn_Speaker();
    //API_Set_Speaker_Period(DoH);
    
    //API_TurnOn_Motor1_Close();  
    //API_TurnOn_Motor2_Close(); 
    //API_TurnOn_Motor4_Close(); 
    //API_TurnOn_CinchMotor_Cinch();   
    
    //API_TurnOff_Motor1(); 
    //API_TurnOff_Motor2();
    //API_TurnOff_Motor4();
    
    
    //Motor1_Duty_Request = 20 * Motor1_OnePercentPWM_Value;
    //Motor2_Duty_Request = 100 * Motor2_OnePercentPWM_Value;
    //CinchMotor_Duty_Request = 20 * CinchMotor_OnePercentPWM_Value;
    //Motor4_Duty_Request = 50 * Motor4_OnePercentPWM_Value;
    //ReleaseMotor_Duty_Request = 20 * ReleaseMotor_OnePercentPWM_Value;
    //Buzzer_Duty_Request = 20 * Buzzer_OnePercentPWM_Value;

    //CinchMotor_Duty_Target = 4000;
    //CinchMotor_Duty_Request = API_IncreaseStepDuty_Control(CinchMotor_Duty_Request,CinchMotor_Duty_Target,CinchMotor_OnePercentPWM_Value,K_CinchMotor_IncreaseStep_Duty);
    
    //Motor1_Duty_Target = 4000;
    //Motor1_Duty_Request = API_IncreaseStepDuty_Control(Motor1_Duty_Request,Motor1_Duty_Target,Motor1_OnePercentPWM_Value,2);
    
    //API_TurnOn_Motor1_Open();
    //Motor1_Duty_Request = (API_ReferTo12Voltage_Duty(5)) * Motor1_OnePercentPWM_Value;
    
}
#endif

#ifdef _CONFIG_ManualCurrentCalibrate
/*********************************************************************************************
** Name:	  API_ManualCurrentCalibrate
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_ManualCurrentCalibrate(void)
{

     #ifdef _CONFIG_Gen1_Board	
     API_TurnOn_Motor1_Open();
     API_TurnOn_Motor2_Open();
     //API_TurnOn_CinchMotor_Cinch();
     
     Motor1_Duty_Request = 100 * Motor1_OnePercentPWM_Value;
     Motor2_Duty_Request = 100 * Motor2_OnePercentPWM_Value;
     //CinchMotor_Duty_Request = 100 * CinchMotor_OnePercentPWM_Value;
     #endif
     #ifdef _CONFIG_Gen2_Board	
     API_TurnOn_Motor1_Open();
     API_TurnOn_Motor2_Open();
     API_TurnOn_CinchMotor_Cinch();
     
     Motor1_Duty_Request = 100 * Motor1_OnePercentPWM_Value;
     Motor2_Duty_Request = 100 * Motor2_OnePercentPWM_Value;
     CinchMotor_Duty_Request = 100 * CinchMotor_OnePercentPWM_Value;
     #endif
     
     #ifdef _CONFIG_Gen3_Board	
     API_TurnOn_Motor1_Open();
     API_TurnOn_Motor2_Open();
     API_TurnOn_CinchMotor_Cinch();
     API_TurnOn_Motor4_Open();
     
     Motor1_Duty_Request = 100 * Motor1_OnePercentPWM_Value;
     Motor2_Duty_Request = 100 * Motor2_OnePercentPWM_Value;
     CinchMotor_Duty_Request = 100 * CinchMotor_OnePercentPWM_Value;
     Motor4_Duty_Request = 100 * Motor4_OnePercentPWM_Value;
     #endif
     
     #ifdef _CONFIG_Gen4_Board	
     API_TurnOn_Motor1_Open();
     API_TurnOn_Motor2_Open();
     API_TurnOn_CinchMotor_Cinch();
     API_TurnOn_Motor4_Open();
     
     Motor1_Duty_Request = 100 * Motor1_OnePercentPWM_Value;
     Motor2_Duty_Request = 100 * Motor2_OnePercentPWM_Value;
     CinchMotor_Duty_Request = 100 * CinchMotor_OnePercentPWM_Value;
     Motor4_Duty_Request = 100 * Motor4_OnePercentPWM_Value;
     #endif
	
}
#endif
/*********************************************************************************************
** Name:	  void API_Motor1_Control(uint16_t pecentduty,uint16_t direction)
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_Motor1_Control(uint16_t pecentduty,uint16_t direction)
{

     
}


/*********************************************************************************************
** Name:	  void API_Motor2_Control(uint16_t pecentduty,uint16_t direction)
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_Motor2_Control(uint16_t pecentduty,uint16_t direction)
{

}

#ifdef _CONFIG_Motor4
/*********************************************************************************************
** Name:	  void API_Motor4_Control(uint16_t pecentduty,uint16_t direction)
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_Motor4_Control(uint16_t pecentduty,uint16_t direction)
{
    if(direction == Direction_Open)
    {
	  API_TurnOn_Motor4_Open();
	  Motor4_Duty_Request = pecentduty * Motor4_OnePercentPWM_Value;

    }
    else if(direction == Direction_Close)
    {
	  API_TurnOn_Motor4_Close();
	  Motor4_Duty_Request = pecentduty * Motor4_OnePercentPWM_Value;
    }
    else
    {
	  API_TurnOff_Motor4();
    }
}
#endif
/*********************************************************************************************
** Name:	  void API_CinchMotor_Control(uint16_t pecentduty,uint16_t direction)
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_CinchMotor_Control(uint16_t pecentduty,uint16_t direction)
{

}

#ifdef _CONFIG_ReleaseMotor
/*********************************************************************************************
** Name:	  void API_ReleaseMotor_Control(uint16_t pecentduty)
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_ReleaseMotor_Control(uint16_t pecentduty)
{
     API_TurnOn_ReleaseMotor();
     ReleaseMotor_Duty_Request = pecentduty * ReleaseMotor_OnePercentPWM_Value;
}
#endif

#if defined(_CONFIG_Clutch) || defined(_CONFIG_ClutchHold)
/*********************************************************************************************
** Name:	  void API_Clutch_Control(uint16_t pecentduty)
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_Clutch_Control(uint16_t pecentduty)
{
     API_TurnOn_Clutch();
     Clutch_Duty_Request = pecentduty * Clutch_OnePercentPWM_Value;
}
#endif

#ifdef _CONFIG_SbcTest
#ifdef _CONFIG_TLE9263
/*********************************************************************************************
** Name:	  API_Tle9263_Test
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_Tle9263_Test(void)
{
     (void)Sbc_Tle9263_Sts_Read(&TsSBC_h_CurrentStatus);
     
     SBC_Reset_Reason = (uint8_t)(Sbc_Tle9263_Rst_GetReason());
}
#endif
#ifdef _CONFIG_TLE9562
/*********************************************************************************************
** Name:	  API_Tle9562_Test
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_Tle9562_Test(void)
{
     (void)Sbc_Tle9562_Sts_Read(&TsSBC_h_CurrentStatus);
     
     //SBC_Reset_Reason = (uint8_t)(Sbc_Tle9562_Rst_GetReason());
}
#endif
#endif

#ifdef _CONFIG_ChipTest
/*********************************************************************************************
** Name:	  API_Switch_Input_Test
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_Switch_Input_Test(void)
{
     #ifdef _CONFIG_ShutFaceSwitch
     if(TRUE == ShutFaceSwitch_RiseEdge_Active)
     {  
	  Flag_ShutFaceSwitch_RiseEdge = TRUE;
     }
     if(TRUE == ShutFaceSwitch_FallEdge_Active)
     {
	  Flag_ShutFaceSwitch_FallEdge = TRUE;
     }
     if(TRUE == ShutFaceSwitch_ShortPress_Active)
     {
	  Flag_ShutFaceSwitch_ShortPress = TRUE;
     }
     if(TRUE == ShutFaceSwitch_LongPress_Active)
     {
	  Flag_ShutFaceSwitch_LongPress = TRUE;
     }
     #endif
     
     //API_TurnOn_LoadPower_EN();
     
     #ifdef _CONFIG_Gen1_Board
     Get_ODL_0_STA = Get_ODL_0_STA_Port_Status();                 
     Get_IDL_1_MIN = Get_IDL_1_MIN_Port_Status();                 
     Get_IDL_0_MIN = Get_IDL_0_MIN_Port_Status();                 
     Get_IDX_0_MIN = Get_IDX_0_MIN_Port_Status();                 
     Get_IDL_8_MIN = Get_IDL_8_MIN_Port_Status();                 
     Get_IDX_1_MIN = Get_IDX_1_MIN_Port_Status();                 
     Get_IDL_7_MIN = Get_IDL_7_MIN_Port_Status();                 
     Get_IDL_3_MIN = Get_IDL_3_MIN_Port_Status();                 
     Get_IDL_2_MIN = Get_IDL_2_MIN_Port_Status();                 
     Get_IDL_4_MIN = Get_IDL_4_MIN_Port_Status();                 
     Get_IDL_9_MIN = Get_IDL_9_MIN_Port_Status();                 
     Get_IDL_5_MIN = Get_IDL_5_MIN_Port_Status();                 
     Get_IDL_6_MIN = Get_IDL_6_MIN_Port_Status();                 
     Get_FO1 = Get_FO1_Port_Status();
     #endif
     #ifdef _CONFIG_Gen2_Board
     Get_IDL_11_MIN_U1_2 = Get_IDL_11_MIN_U1_2_Port_Status();
     Get_IDL_1_MIN_U1_8 = Get_IDL_1_MIN_U1_8_Port_Status();
     Get_IDL_0_MIN_U1_9 = Get_IDL_0_MIN_U1_9_Port_Status(); 

     Get_IDL_5_MIN_U1_12 = Get_IDL_5_MIN_U1_12_Port_Status();
     Get_IDL_6_MIN_U1_11 = Get_IDL_6_MIN_U1_11_Port_Status();

     Get_IDX_0_MIN_U1_15 = Get_IDX_0_MIN_U1_15_Port_Status();
     Get_IDL_8_MIN_U1_16 = Get_IDL_8_MIN_U1_16_Port_Status();
     Get_IDX_1_MIN_U1_17 = Get_IDX_1_MIN_U1_17_Port_Status();
     Get_IDL_7_MIN_U1_19 = Get_IDL_7_MIN_U1_19_Port_Status();
     Get_IDL_3_MIN_U1_37 = Get_IDL_3_MIN_U1_37_Port_Status();
     Get_IDL_2_MIN_U1_38 = Get_IDL_2_MIN_U1_38_Port_Status();
     Get_IDL_4_MIN_U1_43 = Get_IDL_4_MIN_U1_43_Port_Status();

     Get_IDL_9_MIN_U1_73 = Get_IDL_9_MIN_U1_73_Port_Status();

     Get_U4_Fault_U1_98 = Get_U4_Fault_U1_98_Port_Status();
     Get_IDL_10_U1_100 = Get_IDL_10_U1_100_Port_Status();

     Get_FO1_U1_95 = Get_FO1_U1_95_Port_Status();
     Get_CANRX = Get_CANRX_Status();

     //Get_UP_Wakeup_U1_93 = Get_UP_Wakeup_U1_93_Port_Status();
     //Get_Down_Wakeup_U1_94 = Get_Down_Wakeup_U1_94_Port_Status();
     Get_U5_Fault_U1_13 = Get_U5_Fault_U1_13_Port_Status();
     
     /*HallA1_IO_Port_Status = Get_Hall_1A_U1_42_Port_Status();
     HallA2_IO_Port_Status = Get_Hall_1B_U1_44_Port_Status();
     HallB1_IO_Port_Status = Get_Hall_2A_U1_45_Port_Status();
     HallB2_IO_Port_Status = Get_Hall_2B_U1_46_Port_Status();*/
     
     Get_Hall_1A_U1_42 = Get_Hall_1A_U1_42_Port_Status();
     Get_Hall_1B_U1_44 = Get_Hall_1B_U1_44_Port_Status();
     Get_Hall_2A_U1_45 = Get_Hall_2A_U1_45_Port_Status();
     Get_Hall_2B_U1_46 = Get_Hall_2B_U1_46_Port_Status();
     #endif
     
     #ifdef _CONFIG_Gen3_Board
     Get_DI_X2_20_P10_4 = Get_DI_X2_20_P10_4_Port_Status();
     //Get_Speaker_DIA_P11_0 = Get_Speaker_DIA_P11_0_Port_Status();
     Get_DI_X2_3_P0_2 = Get_DI_X2_3_P0_2_Port_Status();
     Get_DI_X2_11_P0_3 = Get_DI_X2_11_P0_3_Port_Status();
     Get_DI_X2_21_P0_4 = Get_DI_X2_21_P0_4_Port_Status();
     Get_DI_X2_7_P0_5 = Get_DI_X2_7_P0_5_Port_Status();
     Get_DI_X2_2_P0_6 = Get_DI_X2_2_P0_6_Port_Status();
     Get_DI_X2_18_P0_11 = Get_DI_X2_18_P0_11_Port_Status();
     Get_DI_X2_10_P0_12 = Get_DI_X2_10_P0_12_Port_Status();
     Get_DI_X2_9_P8_2 = Get_DI_X2_9_P8_2_Port_Status();
     //Get_DI_X2_22_P8_12 = Get_DI_X2_22_P8_12_Port_Status();
     Get_LSD_DIA_JP0_3 = Get_LSD_DIA_JP0_3_Port_Status();
     Get_DI_X2_1_P0_10 = Get_DI_X2_1_P0_10_Port_Status();
     Get_DI_X2_4_P0_9 = Get_DI_X2_4_P0_9_Port_Status();
     Get_DI_X2_24_P9_4 = Get_DI_X2_24_P9_4_Port_Status();
     Get_SBC_INT_P0_7 = Get_SBC_INT_P0_7_Port_Status();
     Get_DI_X2_8_P8_1 = Get_DI_X2_8_P8_1_Port_Status();

     Get_Hall_1A_P8_0 = Get_Hall_1A_P8_0_Port_Status();
     Get_Hall_2B_P8_3 = Get_Hall_2B_P8_3_Port_Status();
     Get_Hall_2A_P8_4 = Get_Hall_2A_P8_4_Port_Status();
     Get_Hall_1B_P8_5 = Get_Hall_1B_P8_5_Port_Status();

     Get_Hall_Power1_DIA_P9_0 = Get_Hall_Power1_DIA_P9_0_Port_Status();
     Get_Hall_Power2_DIA_P9_5 = Get_Hall_Power2_DIA_P9_5_Port_Status();

     //Get_M1_Fault_P10_6 = Get_M1_Fault_P10_6_Port_Status();
     //Get_M4_Fault_P11_6 = Get_M4_Fault_P11_6_Port_Status();
     //Get_M3_Fault_P11_7 = Get_M3_Fault_P11_7_Port_Status();
     //Get_M2_Fault_P10_0 = Get_M2_Fault_P10_0_Port_Status();
     Get_CANRX = Get_CANRX_Status();
     #endif
     
     #ifdef _CONFIG_Gen4_Board
     Get_DI_X2_20_P8_12 = Get_DI_X2_20_P8_12_Port_Status();
     Get_DI_X2_3_P0_2 = Get_DI_X2_3_P0_2_Port_Status();
     Get_DI_X2_11_P10_3 = Get_DI_X2_11_P10_3_Port_Status();
     Get_DI_X2_21_P8_11 = Get_DI_X2_21_P8_11_Port_Status();
     Get_DI_X2_7_P8_9 = Get_DI_X2_7_P8_9_Port_Status();
     Get_DI_X2_2_P0_4 = Get_DI_X2_2_P0_4_Port_Status();
     Get_DI_X2_18_P0_6 = Get_DI_X2_18_P0_6_Port_Status();
     Get_DI_X2_10_P8_7 = Get_DI_X2_10_P8_7_Port_Status();
     Get_DI_X2_9_P8_2 = Get_DI_X2_9_P8_2_Port_Status();
     Get_DI_X2_22_P10_5 = Get_DI_X2_22_P10_5_Port_Status();
     Get_DI_X2_1_P0_3 = Get_DI_X2_1_P0_3_Port_Status();
     Get_DI_X2_4_P0_5 = Get_DI_X2_4_P0_5_Port_Status();
     Get_DI_X2_24_P10_12 = Get_DI_X2_24_P10_12_Port_Status();
     Get_SBC_INT_P0_7 = Get_SBC_INT_P0_7_Port_Status();
     Get_DI_X2_8_P10_6 = Get_DI_X2_8_P10_6_Port_Status();

     Get_Hall_1A_P9_4 = Get_Hall_1A_P9_4_Port_Status();
     Get_Hall_2B_P8_3 = Get_Hall_2B_P8_3_Port_Status();
     Get_Hall_2A_P8_4 = Get_Hall_2A_P8_4_Port_Status();
     Get_Hall_1B_P8_5 = Get_Hall_1B_P8_5_Port_Status();

     Get_Hall_Power1_DIA_P0_10 = Get_Hall_Power1_DIA_P0_10_Port_Status();
     Get_Hall_Power2_DIA_P10_14 = Get_Hall_Power2_DIA_P10_14_Port_Status();
     Get_Hall_Power3_DIA_P10_4 = Get_Hall_Power3_DIA_P10_4_Port_Status();

     Get_M_Fault_P10_6 = Get_M_Fault_P10_6_Port_Status();
     Get_CANRX = Get_CANRX_Status();

     #ifdef _CONFIG_AI_DI_1_X2_15_P8_6_As_DI
     Get_AI_DI_1_X2_15_P8_6 = Get_AI_DI_1_X2_15_P8_6_Port_Status();
     #endif
     #ifndef _CONFIG_DI_2_LSD_X2_23_P11_7_As_Output
     Get_DI_2_LSD_X2_23_P11_7 = Get_DI_2_LSD_X2_23_P11_7_Port_Status();
     #endif
     #ifndef _CONFIG_AI_1_X2_12_AP0_9_As_AI
     Get_AI_1_X2_12_AP0_9 = Get_AI_1_X2_12_AP0_9_Port_Status();
     #endif
     #ifndef _CONFIG_AI_2_X2_13_AP0_11_As_AI
     Get_AI_2_X2_13_AP0_11 = Get_AI_2_X2_13_AP0_11_Port_Status();
     #endif
     #ifdef _CONFIG_HallC_As_DI
     Get_Hall_3A_X2_24_P9_4 = Get_Hall_3A_X2_24_P9_4_Port_Status();
     Get_Hall_3B_X2_22_P9_5 = Get_Hall_3B_X2_22_P9_5_Port_Status();
     #endif
     #ifdef _CONFIG_HallD_As_DI
     Get_Hall_4A_X2_21_P8_11 = Get_Hall_4A_X2_21_P8_11_Port_Status();
     Get_Hall_4B_X2_20_P8_12 = Get_Hall_4B_X2_20_P8_12_Port_Status();
     #endif
     #endif
}

#ifdef _CONFIG_TLE9263

/*********************************************************************************************
** Name:	  API_SBC_HS_Test
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_SBC_HS_Test(void)
{       
     Time_Test1 = OSTM0.CNT;
        //Sbc_Tle9263_Hsd_SetCtrl(SBC_HSD1,SBC_HSD_ON);
	//Sbc_Tle9263_Hsd_SetCtrl(SBC_HSD2,SBC_HSD_ON);
	//Sbc_Tle9263_Hsd_SetCtrl(SBC_HSD3,SBC_HSD_ON);
	//Sbc_Tle9263_Hsd_SetCtrl(SBC_HSD4,SBC_HSD_ON);
	
     /*#ifdef _CONFIG_Gen1_Board
     API_TurnOn_HallPower();
     API_TurnOn_VBATT1_SW();
     #endif
     
     #ifdef _GEN2BOARD
     API_TurnOn_HallPower();
     API_TurnOn_Batt_AD_EN();
     API_TurnOn_Diag_Power();
     #endif*/
     
     #ifdef _CONFIG_Gen3_Board
     API_TurnOn_HallPower1();    
         #ifdef _CONFIG_HallB
     API_TurnOn_HallPower2();
         #endif
     API_TurnOn_Batt_AD_EN();
     API_TurnOn_Diag_Power();	
     API_TurnOn_LatchSwitchPower();
     #endif
	
     Time_Test2 = OSTM0.CNT;
	
     API_TurnOn_VCC2_5V();
	
}
#endif
#ifdef _CONFIG_TLE9562
/*********************************************************************************************
** Name:	  API_SBC_HS_Test
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_SBC_HS_Test(void)
{       
     Time_Test1 = OSTM0.CNT;
        //Sbc_Tle9562_Hsd_SetCtrl(SBC_HSD1,SBC_HSD_ON);
	//Sbc_Tle9562_Hsd_SetCtrl(SBC_HSD2,SBC_HSD_ON);
	//Sbc_Tle9562_Hsd_SetCtrl(SBC_HSD3,SBC_HSD_ON);
	//Sbc_Tle9562_Hsd_SetCtrl(SBC_HSD4,SBC_HSD_ON);
	
     /*#ifdef _CONFIG_Gen1_Board
     API_TurnOn_HallPower();
     API_TurnOn_VBATT1_SW();
     API_TurnOn_VCC2_5V();
     #endif
     
     #ifdef _CONFIG_Gen2_Board
     API_TurnOn_HallPower();
     API_TurnOn_Batt_AD_EN();
     API_TurnOn_Diag_Power();
     API_TurnOn_VCC2_5V();
     #endif*/
     
     #ifdef _CONFIG_Gen3_Board
     API_TurnOn_HallPower1();    
         #ifdef _CONFIG_HallB
     API_TurnOn_HallPower2();
         #endif
     API_TurnOn_Batt_AD_EN();
     API_TurnOn_Diag_Power();	
     API_TurnOn_LatchSwitchPower();
     
     API_TurnOn_VCC2_5V();
     #endif
	
     #ifdef _CONFIG_Gen4_Board
     API_TurnOn_HallPower1();    
         #ifdef _CONFIG_HallB
     API_TurnOn_HallPower2();
         #endif
     API_TurnOn_Batt_AD_EN();
     API_TurnOn_Diag_Power();	
     API_TurnOn_LatchSwitchPower();
     #endif

     Time_Test2 = OSTM0.CNT;

}
#endif

/*********************************************************************************************
** Name:	  API_CAN_Implement_Test
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_CAN_Implement_Test(void)
{
        Time_Test1 = OSTM0.CNT;
        PE10ms_Com_CAN_Master();
	Time_Test2 = OSTM0.CNT;
}

/*********************************************************************************************
** Name:	  API_CAN_Implement_Test
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/ 
void API_EEL_Implement_Test(void)
{
  //uint8_t wBuf_au08[15] = {0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0xaa,0xbb,0xcc,0xdd,0xee,0xff};
  uint8_t wBuf_au08[6] = {0x11,0x22,0x33,0x44,0x55,0x66};
  uint8_t rBuf_au08[15] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
  
  uint8_t w1Buf_au08[40] = {
                           0x12,0x34,0x56,0x78,0x9a,0xbc,0xde,0xf0,
                           0x12,0x34,0x56,0x78,0x9a,0xbc,0xde,0xf0,
			   0x12,0x34,0x56,0x78,0x9a,0xbc,0xde,0xf0,
			   0x12,0x34,0x56,0x78,0x9a,0xbc,0xde,0xf0,
			   0x12,0x34,0x56,0x78,0x9a,0xbc,0xde,0xf0
  };
  uint8_t r1Buf_au08[40] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                           0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
			   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
			   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
			   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
  };	
	
	
    Time_Test1 = OSTM0.CNT;
    
    EEL_Write_Data_Buffer(0x0001, wBuf_au08);
    //EEL_Write_Data_Buffer(0x0003, w1Buf_au08);
    
    Time_Test2 = OSTM0.CNT;
    Time_Test_Delta = Time_Test1 - Time_Test2;
    
    
    EEL_Read_Data(0x0002, rBuf_au08, 0x000f, 0x0000);
    EEL_Read_Data(0x0005, r1Buf_au08, 0x0028, 0x0000);
    
    
   /* Time_Test1 = OSTM0.CNT;
    
    EEL_Write_4Byte(0x0001, 0x11111111);
    //EEL_Write_2Byte(0x2000, 0x2222);
    //EEL_Write_2Byte(0x2001, 0x3333);
    //EEL_Write_2Byte(0x2002, 0x4444);
    
    //EEL_Write_1Byte(0x1000, 0x11);
    
    Time_Test2 = OSTM0.CNT;
    
    
    Mem_Read_Return_Test4 = EEL_Read_4Byte(0x0001, &EEL_Test4);
    //Mem_Read_Return_Test1 = EEL_Read_2Byte(0x2000, &EEL_Test1);
    //Mem_Read_Return_Test2 = EEL_Read_2Byte(0x2001, &EEL_Test2);
    //Mem_Read_Return_Test3 = EEL_Read_2Byte(0x2002, &EEL_Test3);
    //Mem_Read_Return_Test0 = EEL_Read_1Byte(0x1000, &EEL_Test0);*/	
    
    
}

/*********************************************************************************************
** Name:	  API_Task_Scheduler_Test
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_Task_Scheduler_Test(void)
{     
      //VNH7040_Inactive();
	//BTN8962_Group1_Inactive();
	//BTN8962_Group2_Inactive();
      if (Flag_test ==  FALSE)
      {
	    API_TurnOn_Motor1_Open();
           API_TurnOn_Motor2_Open();

           //API_TurnOn_Motor1_Close();
            //API_TurnOn_Motor2_Close();
            //BTN8962_Group1_Active();
	    //BTN8962_Group2_Active();
	     
	    Motor1_Duty_Request = 50 * Motor1_OnePercentPWM_Value;
           Motor2_Duty_Request = 50 * Motor2_OnePercentPWM_Value;
	   
           //Set_ODH_3_CTN_PercentDuty(50);
	   //Set_ODH_4_CTN_PercentDuty(0);
	   
	  // Set_ODH_5_CTN_PercentDuty(50);
	   //Set_ODH_6_CTN_PercentDuty(0);
	   
	   
	   
	   //API_TurnOn_CinchMotor_Cinch();
	   //CinchMotor_Duty_Request = 40 * CinchMotor_OnePercentPWM_Value;
	   //API_TurnOn_CinchMotor_Neutral();
	   //VNH7040_Left_Bridge_Enable();
	   //Set_CINCH_PWM_PercentDuty(30);
	   //API_CinchMotor_PWMDuty_Update(1200,Direction_No);
	   
	   //API_TurnOn_ReleaseMotor();
	   //API_TurnOn_Clutch();
	   
	   //Set_ODH_1_CTN_Duty(50);
	   
	   //API_TurnOn_Buzzer();
	    
	   //Set_ODH_2_CTN_Duty(50);
	   //API_Buzzer_PWMDuty_Update(50);
	   
	   
	   //BTN8962_Group1_Output(LEFT_BRIDGE, 50);
    	   //BTN8962_Group2_Output(LEFT_BRIDGE, 50);
	   
	   //API_TurnOff_VBATT1_SW();
	   //Flag_test = TRUE;

      }
      
      else if (Flag_test == TRUE)
      {    
	   //API_TurnOff_Motor1();  
	   //API_TurnOff_Motor2();
	   
	   //Set_ODH_3_CTN_PercentDuty(0);
	   //Set_ODH_4_CTN_PercentDuty(0);
	   
	   //Set_ODH_5_CTN_PercentDuty(0);
	   //Set_ODH_6_CTN_PercentDuty(0);
	   
	   //API_TurnOff_CinchMotor();
	   //VNH7040_Inactive();
	   //VNH7040_Right_Bridge_Enable();
	  // Set_CINCH_PWM_PercentDuty(0);
	   
	   //Set_ODH_2_CTN_Duty(0);
	   
	  // API_Buzzer_PWMDuty_Update(0);
	   
	   //API_TurnOff_Buzzer();
	  // API_TurnOff_ReleaseMotor();
	   //API_TurnOn_VBATT1_SW();
	   Flag_test = FALSE;
      }	
}


/*********************************************************************************************
** Name:	  API_Analog_Value_ATD_Test
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_Analog_Value_ATD_Test(void)
{
      #ifdef _CONFIG_Gen1_Board
      Get_ODL_0_DIA_AD = Get_ODL_0_DIA_AD();   
      Get_ODH_0_DIA_AD = Get_ODH_0_DIA_AD();    
      Get_OPX_1_DIA_AD = Get_OPX_1_DIA_AD();    
      Get_OPX_0_DIA_AD = Get_OPX_0_DIA_AD();    
      Get_IGN_SW_IN_AD = Get_IGN_SW_IN_AD();   
      Get_Motor1_AD = Get_Motor1_AD();       
      Get_Motor2_AD = Get_Motor2_AD();       
      Get_CINCH_SEN_AD = Get_CINCH_SEN_AD();    
      Get_IA_0_MIN_AD = Get_IA_0_MIN_AD();     
      Get_IA_1_MIN_AD = Get_AntiPinchSensor_ATD_Value();//Get_IA_1_MIN_AD();     
      Get_HS_SENSE_IA_AD = Get_HS_SENSE_IA_AD();  
      Get_VCC2_5V_DIA_AD = Get_VCC2_5V_DIA_AD();  
      Get_Temp_AD = Get_Temp_AD();         
      Get_VBATT1_SW_AD = Get_VBATT1_SW_AD();   
      Get_VBATT2_AD = Get_VBATT2_AD();       
      Get_VBATT1_AD = Get_VBATT1_AD();   
      
      Get_ODH_3_DIA_AD = Get_ODH_3_DIA_AD();    
      Get_ODH_4_DIA_AD = Get_ODH_4_DIA_AD();    
      Get_ODH_2_DIA_AD = Get_ODH_2_DIA_AD();    
      Get_ODH_1_DIA_AD = Get_ODH_1_DIA_AD();    
      Get_ODH_6_DIA_AD = Get_ODH_6_DIA_AD();    
      Get_ODH_5_DIA_AD = Get_ODH_5_DIA_AD();
      #endif
      
      #ifdef _CONFIG_Gen2_Board
      
      Get_HS2_DIA_U1_67_AD = Get_HS2_DIA_U1_67_AD();  /*reverse for 67 OK*/
      Get_HS1_DIA_U1_68_AD = Get_HS1_DIA_U1_68_AD();  /*OK*/
      Get_J2_2_DIA_U1_66_AD = Get_J2_2_DIA_U1_66_AD();
      Get_J2_1_DIA_U1_65_AD = Get_J2_1_DIA_U1_65_AD();
      Get_HS3_OUT_AD = Get_HS3_OUT_AD();/*OK*/
      Get_Motor1_AD_U1_63_AD = Get_Motor1_AD_U1_63_AD();/*OK*/
      Get_Motor2_AD_U1_62_AD = Get_Motor2_AD_U1_62_AD();/*OK*/
      Get_Motor3_AD_U1_61_AD = Get_Motor3_AD_U1_61_AD();/*OK*/
      Get_IA_0_MIN_U1_60_AD = Get_IA_0_MIN_U1_60_AD();/*OK*/
      Get_IA_1_MIN_U1_59_AD = Get_IA_1_MIN_U1_59_AD();/*OK*/
      Get_HS_DIA_U1_58_AD = Get_HS_DIA_U1_58_AD();
      Get_VCC2_5V_AD = Get_VCC2_5V_AD();/*OK*/
      Get_Thermistor_U1_56_AD = Get_Thermistor_U1_56_AD();/*OK*/
      Get_Hall_Power_AD = Get_Hall_Power_AD();/*OK*/
      Get_VBATT2_AD_U1_54_AD = Get_VBATT2_AD_U1_54_AD();
      Get_VBATT1_AD_U1_53_AD = Get_VBATT1_AD_U1_53_AD();
      Get_J3_1_DIA_U1_20_AD = Get_J3_1_DIA_U1_20_AD();
      Get_J3_2_DIA_U1_21_AD = Get_J3_2_DIA_U1_21_AD();
      Get_VBATT1_SW_AD = Get_VBATT1_SW_AD();/*OK*/
      Get_J3_3_DIA_U1_71_AD = Get_J3_3_DIA_U1_71_AD();
      Get_J3_4_DIA_U1_72_AD = Get_J3_4_DIA_U1_72_AD();
      #endif
      
      #ifdef _CONFIG_Gen3_Board      
      Get_HS1_DIA_AP0_0_AD = Get_HS1_DIA_AP0_0_AD();
      Get_HS2_DIA_AP0_1_AD = Get_HS2_DIA_AP0_1_AD();
      Get_M3_DIA_AP0_2_AD = Get_M3_DIA_AP0_2_AD();
      Get_M3_DIA_AP0_3_AD = Get_M3_DIA_AP0_3_AD();
      Get_M4_DIA_AP0_4_AD = Get_M4_DIA_AP0_4_AD();
      Get_M1_AD_AP0_5_AD = Get_M1_AD_AP0_5_AD();
      Get_M2_AD_AP0_6_AD = Get_M2_AD_AP0_6_AD();
      Get_M3_AD_AP0_7_AD = Get_M3_AD_AP0_7_AD();
      Get_AI1_AP0_8_AD = Get_AI1_AP0_8_AD();
      Get_AI2_AP0_9_AD = Get_AI2_AP0_9_AD();
      Get_7040_DIA_AP0_10_AD = Get_7040_DIA_AP0_10_AD();
      Get_M4_DIA_AP0_11_AD = Get_M4_DIA_AP0_11_AD();
      Get_Temp_AD_AP0_12_AD = Get_Temp_AD_AP0_12_AD();
      Get_M4_AD_AP0_13_AD = Get_M4_AD_AP0_13_AD();
      Get_Load_12V_AD_AP0_14_AD = Get_Load_12V_AD_AP0_14_AD();
      Get_DIG_12V_AD_AP0_15_AD = Get_DIG_12V_AD_AP0_15_AD();
 
      Get_M1_DIA_P8_10_AD = Get_M1_DIA_P8_10_AD();
      Get_M1_DIA_P8_11_AD = Get_M1_DIA_P8_11_AD();
      Get_M2_DIA_P9_2_AD = Get_M2_DIA_P9_2_AD();
      Get_M2_DIA_P9_3_AD = Get_M2_DIA_P9_3_AD();
      #endif
      
      
      #ifdef _CONFIG_Gen4_Board      
      Get_HS1_DIA_AP0_0_AD = Get_HS1_DIA_AP0_0_AD();
      Get_HS2_DIA_AP0_1_AD = Get_HS2_DIA_AP0_1_AD();
      Get_M3_DIA_AP0_2_AD = Get_M3_DIA_AP0_2_AD();
      Get_M3_DIA_AP0_3_AD = Get_M3_DIA_AP0_3_AD();
      Get_M4_DIA_AP0_4_AD = Get_M4_DIA_AP0_4_AD();
      Get_M1_AD_AP0_5_AD = Get_M1_AD_AP0_5_AD();
      Get_M2_AD_AP0_6_AD = Get_M2_AD_AP0_6_AD();
      Get_M3_AD_AP0_7_AD = Get_M3_AD_AP0_7_AD();
      Get_M4_DIA_AP0_8_AD = Get_M4_DIA_AP0_8_AD();
      #ifdef _CONFIG_AI_1_X2_12_AP0_9_As_AI
      Get_AI1_AP0_9_AD = Get_AI1_AP0_9_AD();
      #endif
      Get_7040_DIA_AP0_10_AD = Get_7040_DIA_AP0_10_AD();
      #ifdef _CONFIG_AI_2_X2_13_AP0_11_As_AI
      Get_AI2_AP0_11_AD = Get_AI2_AP0_11_AD();
      #endif
      Get_Temp_AD_AP0_12_AD = Get_Temp_AD_AP0_12_AD();
      Get_M4_AD_AP0_13_AD = Get_M4_AD_AP0_13_AD();
      Get_Load_12V_AD_AP0_14_AD = Get_Load_12V_AD_AP0_14_AD();
      Get_DIG_12V_AD_AP0_15_AD = Get_DIG_12V_AD_AP0_15_AD();
 
      Get_M1_DIA_P8_10_AD = Get_M1_DIA_P8_10_AD();
      Get_M1_DIA_P8_8_AD = Get_M1_DIA_P8_8_AD();
      Get_M2_DIA_P9_2_AD = Get_M2_DIA_P9_2_AD();
      Get_M2_DIA_P9_3_AD = Get_M2_DIA_P9_3_AD();

      #ifndef _CONFIG_AI_DI_1_X2_15_P8_6_As_DI
      Get_AI_DI_1_X2_15_P8_6_AD = Get_AI_DI_1_X2_15_P8_6_AD();  
      #endif
      #ifdef _CONFIG_HallC_As_AI
      Get_Hall_3A_X2_24_P9_4_AD = Get_Hall_3A_X2_24_P9_4_AD();
      Get_Hall_3B_X2_22_P9_5_AD = Get_Hall_3B_X2_22_P9_5_AD(); 
      #endif
      #ifdef _CONFIG_HallD_As_AI
      Get_Hall_4A_X2_21_P8_11_AD = Get_Hall_4A_X2_21_P8_11_AD(); 
      Get_Hall_4B_X2_20_P8_12_AD = Get_Hall_4B_X2_20_P8_12_AD();  
      #endif
      #endif
}
#endif


/*********************************************************************************************
** Name:	   API_ATD_Scan_Start
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_ATD_Scan_Start(void)
{
     ADC_Scan_Once();
}


/*********************************************************************************************
** Name:	   API_Feed_Watchdog_SBC
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_Feed_Watchdog_SBC(void)
{
     #ifdef _CONFIG_Buzzer_SBC_HS4	
     if((FALSE == Speaker_Working_Status)
       #ifdef _CONFIG_Flasher
       && (FALSE == Flasher_Working_Status)
       #endif
       )
     {
	 #ifdef _CONFIG_TLE9263
         Sbc_Tle9263_Wdg_SetTrigger();
	 #endif
	 #ifdef _CONFIG_TLE9562
         Sbc_Tle9562_Wdg_SetTrigger();
	 #endif
     }
     #else
         #ifdef _CONFIG_TLE9263
     Sbc_Tle9263_Wdg_SetTrigger();
         #endif
	 #ifdef _CONFIG_TLE9562
     Sbc_Tle9562_Wdg_SetTrigger();
         #endif
     #endif
}

/*********************************************************************************************
** Name:	  API_Feed_Watchdog_MCU   
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_Feed_Watchdog_MCU(void)
{
     #ifdef _CONFIG_RH850F1L
     R_WDT0_Restart(); 
     /*BA2FFFCF*/
     #endif
     #ifdef _CONFIG_RH850F1K
     R_Config_WDT0_Restart();
     /*BA2FFFCF*/
     #endif
}

/*********************************************************************************************
** Name:	   API_HallA1_Interrupt
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_HallA1_Interrupt(void)
{
  #ifdef _CONFIG_HallA_Dual	
     #ifdef _CONFIG_DIAG_Hall_StaticDiag
     if(FALSE == HallA1_Diagnostic_Working_Status)
     {
     #endif	     
      HallA_Accumulator ++;       /*Used for Speed Control*/
      Motor1_HallCounter ++; /*Used for motor1 speedup*/
      Motor1_HallPluse1Width_Timer = 0; /*Used for HallPluseObstacle*/
      HallA1_DynamicDiag_HallCounter ++; /*Used for Hall DynamicDiag*/
      HallA1_HallCounter ++;   /*Used for Monitoring Hall Counter of each channel*/

    #ifndef _CONFIG_Gen4_Board_003_004
    if(_TAUJ_INPUT_EDGE_FALLING == TAUJ0.CMUR0)
    #else
    if(_TAUJ_INPUT_EDGE_FALLING == TAUJ1.CMUR0)
    #endif
    {
       // TAUJ0.CMUR0 = _TAUJ_INPUT_EDGE_RISING;
	HallA1_Status = FALSE;
	if(TRUE == HallA2_Status)
        {
	     #ifdef _CONFIG_HallA_Dual_Direction_From_2_To_1
	     Motor1_Direction_Status = Direction_Close;
	     if(Motor1_Position > 0)
	     {
		  Motor1_Position --;
	     }
	     Motor1_Location --;
	     #else
	     Motor1_Direction_Status = Direction_Open;
	     Motor1_Position ++;
	     Motor1_Location ++;
	     #endif
        }
	else
	{    	     
	     
	     #ifdef _CONFIG_HallA_Dual_Direction_From_2_To_1
	     Motor1_Direction_Status = Direction_Open;
	     Motor1_Position ++;
	     Motor1_Location ++;
	     #else
	     Motor1_Direction_Status = Direction_Close;
	     if(Motor1_Position > 0)
	     {
		  Motor1_Position --;
	     }
	     Motor1_Location --;
	     #endif
	}
	HallA1_Low_Pluse_Timer = 0;
    }
    
    #ifndef _CONFIG_Gen4_Board_003_004
    if(_TAUJ_INPUT_EDGE_RISING == TAUJ0.CMUR0)
    #else
    if(_TAUJ_INPUT_EDGE_RISING == TAUJ1.CMUR0)
    #endif
    {
        //TAUJ0.CMUR0 = _TAUJ_INPUT_EDGE_FALLING;	
        HallA1_Status = TRUE;
	if(FALSE == HallA2_Status)
        {
	     #ifdef _CONFIG_HallA_Dual_Direction_From_2_To_1
	     Motor1_Direction_Status = Direction_Close;
	     if(Motor1_Position > 0)
	     {
		  Motor1_Position --;		
	     }
	     Motor1_Location --;
	     #else
	     Motor1_Direction_Status = Direction_Open;
	     Motor1_Position ++;  
	     Motor1_Location ++;
	     #endif
        }
	else
	{    
	     
	     #ifdef _CONFIG_HallA_Dual_Direction_From_2_To_1
	     Motor1_Direction_Status = Direction_Open;
	     Motor1_Position ++;
	     Motor1_Location ++;
	     #else
	     Motor1_Direction_Status = Direction_Close;
	     if(Motor1_Position > 0)
	     {
		  Motor1_Position --;		
	     }
	     Motor1_Location --;
	     #endif
	}
	HallA1_High_Pluse_Timer = 0;
     }
    #ifdef _CONFIG_DIAG_Hall_StaticDiag
    }
    #endif
  #endif
  #ifdef _CONFIG_HallA_Single
     #ifdef _CONFIG_DIAG_Hall_StaticDiag
     if(FALSE == HallA1_Diagnostic_Working_Status)
     {
     #endif	   
      #ifndef _CONFIG_HallA_Single_Pluse_2_Direction_1
      HallA_Accumulator ++;       /*Used for Speed Control*/
      Motor1_HallCounter ++; /*Used for motor1 speedup*/
      Motor1_HallPluse1Width_Timer = 0; /*Used for HallPluseObstacle*/
      HallA1_DynamicDiag_HallCounter ++; /*Used for Hall DynamicDiag*/
      HallA1_HallCounter ++;   /*Used for Monitoring Hall Counter of each channel*/
     
      
     #ifdef _CONFIG_Gen2_Board
     HallA2_Status = Get_Hall_1B_U1_44_Port_Status();
     #endif
     #ifdef _CONFIG_Gen3_Board
     HallA2_Status = Get_Hall_1B_P8_5_Port_Status();
     #endif
     #ifdef _CONFIG_Gen4_Board
     HallA2_Status = Get_Hall_1B_P8_5_Port_Status();
     #endif
     
     #ifndef _CONFIG_Gen4_Board_003_004
     if(_TAUJ_INPUT_EDGE_FALLING == TAUJ0.CMUR0)
     #else
     if(_TAUJ_INPUT_EDGE_FALLING == TAUJ1.CMUR0)
     #endif
     {
       // TAUJ0.CMUR0 = _TAUJ_INPUT_EDGE_RISING;
	HallA1_Status = FALSE;
	#ifdef _CONFIG_HallA_Single_Low_Open_High_Close
	if(FALSE == HallA2_Status)
	#else
	if(TRUE == HallA2_Status)
	#endif
        {
	     Motor1_Direction_Status = Direction_Open;
	     Motor1_Position ++;
	     Motor1_Location ++;
        }
	else
	{    	     
	     A1_Test ++;
	     Motor1_Direction_Status = Direction_Close;
	     if(Motor1_Position > 0)
	     {
		  Motor1_Position --;
	     }
	     Motor1_Location --;
	}
	HallA1_Low_Pluse_Timer = 0;
     }
    
     #ifndef _CONFIG_Gen4_Board_003_004
     if(_TAUJ_INPUT_EDGE_RISING == TAUJ0.CMUR0)
     #else
     if(_TAUJ_INPUT_EDGE_RISING == TAUJ1.CMUR0)
     #endif
     {
        //TAUJ0.CMUR0 = _TAUJ_INPUT_EDGE_FALLING;	
        HallA1_Status = TRUE;
	#ifdef _CONFIG_HallA_Single_Low_Open_High_Close
	if(FALSE == HallA2_Status)
	#else
	if(TRUE == HallA2_Status)
	#endif
        {
	     Motor1_Direction_Status = Direction_Open;
	     Motor1_Position ++;  
	     Motor1_Location ++;
        }
	else
	{    
	     A1_Test ++;
	     Motor1_Direction_Status = Direction_Close;
	     if(Motor1_Position > 0)
	     {
		  Motor1_Position --;		
	     }
	     Motor1_Location --;
	}
	HallA1_High_Pluse_Timer = 0;
     }
     #else
     /*if(_TAUJ_INPUT_EDGE_FALLING == TAUJ0.CMUR0)
     {
	HallA1_Status = FALSE;
     }
     if(_TAUJ_INPUT_EDGE_RISING == TAUJ0.CMUR0)
     {	
        HallA1_Status = TRUE;
     }*/
     #endif
    #ifdef _CONFIG_DIAG_Hall_StaticDiag
    }
    #endif
  #endif
}

/*********************************************************************************************
** Name:	  API_HallA2_Interrupt   
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_HallA2_Interrupt(void)
{
   #ifdef _CONFIG_HallA_Dual
     #ifdef _CONFIG_DIAG_Hall_StaticDiag
     if(FALSE == HallA2_Diagnostic_Working_Status)
     {
     #endif
     HallA_Accumulator ++;     /*Used for Speed Control*/
     Motor1_HallCounter ++; /*Used for motor1 speedup*/
     Motor1_HallPluse2Width_Timer = 0; /*Used for HallPluseObstacle*/  
     HallA2_DynamicDiag_HallCounter ++; /*Used for Hall DynamicDiag*/
     HallA2_HallCounter ++;   /*Used for Monitoring Hall Counter of each channel*/
    
    
     #if defined(_CONFIG_Gen1_Board) || defined(_CONFIG_Gen2_Board)
     if(_TAUJ_INPUT_EDGE_FALLING == TAUJ0.CMUR1)
     #endif
     #if defined(_CONFIG_Gen3_Board) || defined(_CONFIG_Gen4_Board)
     if(_TAUJ_INPUT_EDGE_FALLING == TAUJ0.CMUR3)
     #endif
     {
       // TAUJ0.CMUR1 = _TAUJ_INPUT_EDGE_RISING;
	HallA2_Status = FALSE;
	if(FALSE == HallA1_Status)
        {
	     #ifdef _CONFIG_HallA_Dual_Direction_From_2_To_1
	     Motor1_Direction_Status = Direction_Close;
	     if(Motor1_Position > 0)
	     {
		  Motor1_Position --;		  
	     }
	     Motor1_Location --;
	     #else
	     Motor1_Direction_Status = Direction_Open;
	     Motor1_Position ++; 
	     Motor1_Location ++;
	     #endif
        }
	else
	{    
	     
	     #ifdef _CONFIG_HallA_Dual_Direction_From_2_To_1
	     Motor1_Direction_Status = Direction_Open;
	     Motor1_Position ++;
	     Motor1_Location ++;
	     #else
	     Motor1_Direction_Status = Direction_Close;
	     if(Motor1_Position > 0)
	     {
		  Motor1_Position --;		  
	     }
	     Motor1_Location --;
	     #endif
	}
	HallA2_Low_Pluse_Timer = 0;
    }
    
    
     #if defined(_CONFIG_Gen1_Board) || defined(_CONFIG_Gen2_Board)
     if(_TAUJ_INPUT_EDGE_RISING == TAUJ0.CMUR1)
     #endif
     #if defined(_CONFIG_Gen3_Board) || defined(_CONFIG_Gen4_Board)
     if(_TAUJ_INPUT_EDGE_RISING == TAUJ0.CMUR3)
     #endif
     {
        //TAUJ0.CMUR1 = _TAUJ_INPUT_EDGE_FALLING;	
        HallA2_Status = TRUE;
	if(TRUE == HallA1_Status)
        {
	     #ifdef _CONFIG_HallA_Dual_Direction_From_2_To_1
	     Motor1_Direction_Status = Direction_Close;
	     if(Motor1_Position > 0)
	     {
		  Motor1_Position --;		 
	     }
	     Motor1_Location --;
	     #else
	     Motor1_Direction_Status = Direction_Open;
	     Motor1_Position ++; 
	     Motor1_Location ++;
	     #endif
        }
	else
	{    
	     
	     #ifdef _CONFIG_HallA_Dual_Direction_From_2_To_1
	     Motor1_Direction_Status = Direction_Open;
	     Motor1_Position ++;
	     Motor1_Location ++;
	     #else
	     Motor1_Direction_Status = Direction_Close;
	     if(Motor1_Position > 0)
	     {
		  Motor1_Position --;		 
	     }
	     Motor1_Location --;
	     #endif
	}
	HallA2_High_Pluse_Timer = 0;
    }
    #ifdef _CONFIG_DIAG_Hall_StaticDiag
    }
    #endif
  #endif
  #ifdef _CONFIG_HallA_Single
     #ifdef _CONFIG_DIAG_Hall_StaticDiag
     if(FALSE == HallA2_Diagnostic_Working_Status)
     {
     #endif
     #ifdef _CONFIG_HallA_Single_Pluse_2_Direction_1
     HallA_Accumulator ++;     /*Used for Speed Control*/
     Motor1_HallCounter ++; /*Used for motor1 speedup*/
     Motor1_HallPluse2Width_Timer = 0; /*Used for HallPluseObstacle*/  
     HallA2_DynamicDiag_HallCounter ++; /*Used for Hall DynamicDiag*/
     HallA2_HallCounter ++;   /*Used for Monitoring Hall Counter of each channel*/
         
     #ifdef _CONFIG_Gen2_Board
     HallA1_Status = Get_Hall_1A_U1_42_Port_Status();
     #endif
     #ifdef _CONFIG_Gen3_Board
     HallA1_Status = Get_Hall_1A_P8_0_Port_Status();
     #endif
     #ifdef _CONFIG_Gen4_Board_003_004
     HallA1_Status = Get_Hall_1A_P9_4_Port_Status();
     #endif
     
     #if defined(_CONFIG_Gen1_Board) || defined(_CONFIG_Gen2_Board)
     if(_TAUJ_INPUT_EDGE_FALLING == TAUJ0.CMUR1)
     #endif
     #if defined(_CONFIG_Gen3_Board) || defined(_CONFIG_Gen4_Board)
     if(_TAUJ_INPUT_EDGE_FALLING == TAUJ0.CMUR3)
     #endif
     {
       // TAUJ0.CMUR1 = _TAUJ_INPUT_EDGE_RISING;
	HallA2_Status = FALSE;
	#ifdef _CONFIG_HallA_Single_Low_Open_High_Close
	if(FALSE == HallA1_Status)
	#else
	if(TRUE == HallA1_Status)
	#endif
        {
	     Motor1_Direction_Status = Direction_Open;
	     Motor1_Position ++; 
	     Motor1_Location ++;
        }
	else
	{    
	     A2_Test ++;
	     Motor1_Direction_Status = Direction_Close;
	     if(Motor1_Position > 0)
	     {
		  Motor1_Position --;		  
	     }
	     Motor1_Location --;
	}
	HallA2_Low_Pluse_Timer = 0;
     }
    
     
     #if defined(_CONFIG_Gen1_Board) || defined(_CONFIG_Gen2_Board)
     if(_TAUJ_INPUT_EDGE_RISING == TAUJ0.CMUR1)
     #endif
     #if defined(_CONFIG_Gen3_Board) || defined(_CONFIG_Gen4_Board)
     if(_TAUJ_INPUT_EDGE_RISING == TAUJ0.CMUR3)
     #endif
     {
        //TAUJ0.CMUR1 = _TAUJ_INPUT_EDGE_FALLING;	
        HallA2_Status = TRUE;
	if(TRUE == HallA1_Status)
        {
	     Motor1_Direction_Status = Direction_Open;
	     Motor1_Position ++; 
	     Motor1_Location ++;
        }
	else
	{    
	     A2_Test ++;
	     Motor1_Direction_Status = Direction_Close;
	     if(Motor1_Position > 0)
	     {
		  Motor1_Position --;		 
	     }
	     Motor1_Location --;
	 }
	 HallA2_High_Pluse_Timer = 0;
     }
     #else
     /*if(_TAUJ_INPUT_EDGE_FALLING == TAUJ0.CMUR1)
     {
	  HallA2_Status = FALSE;
     }
     if(_TAUJ_INPUT_EDGE_RISING == TAUJ0.CMUR1)
     {
	  HallA2_Status = TRUE;
     }*/
     #endif
    #ifdef _CONFIG_DIAG_Hall_StaticDiag
    }
    #endif
    
  #endif 
}

/*********************************************************************************************
** Name:	  API_HallB1_Interrupt
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_HallB1_Interrupt(void)
{
  #ifdef _CONFIG_HallB_Dual
     #ifdef _CONFIG_DIAG_Hall_StaticDiag
     if(FALSE == HallB1_Diagnostic_Working_Status)
     {
     #endif
     HallB_Accumulator ++;    /*Used for Speed Control*/
     Motor2_HallCounter ++; /*Used for motor2 speedup*/
     Motor2_HallPluse1Width_Timer = 0; /*Used for HallPluseObstacle*/     
     HallB1_DynamicDiag_HallCounter ++; /*Used for Hall DynamicDiag*/
     HallB1_HallCounter ++;   /*Used for Monitoring Hall Counter of each channel*/
     
     if(_TAUJ_INPUT_EDGE_FALLING == TAUJ0.CMUR2)
     {
       // TAUJ0.CMUR2 = _TAUJ_INPUT_EDGE_RISING;
	HallB1_Status = FALSE;
	if(TRUE == HallB2_Status)
        {
	     #ifdef _CONFIG_HallB_Dual_Direction_From_2_To_1
	     Motor2_Direction_Status = Direction_Close;
	     if(Motor2_Position > 0)
	     {
		  Motor2_Position --;  
	     }
	     Motor2_Location --;
	     #else
	     Motor2_Direction_Status = Direction_Open;
	     Motor2_Position ++;
	     Motor2_Location ++;
	     #endif
        }
	else
	{    
	     #ifdef _CONFIG_HallB_Dual_Direction_From_2_To_1
	     Motor2_Direction_Status = Direction_Open;
	     Motor2_Position ++;
	     Motor2_Location ++;
	     #else
	     Motor2_Direction_Status = Direction_Close;
	     if(Motor2_Position > 0)
	     {
		  Motor2_Position --;  
	     }
	     Motor2_Location --;
	     #endif
	}
	HallB1_Low_Pluse_Timer = 0;
     }
    
    if(_TAUJ_INPUT_EDGE_RISING == TAUJ0.CMUR2)
    {
        //TAUJ0.CMUR2 = _TAUJ_INPUT_EDGE_FALLING;	
        HallB1_Status = TRUE;
	if(FALSE == HallB2_Status)
        {
	     #ifdef _CONFIG_HallB_Dual_Direction_From_2_To_1
	     Motor2_Direction_Status = Direction_Close;
	     if(Motor2_Position > 0)
	     {
		  Motor2_Position --;
	     }
	     Motor2_Location --;
	     #else
	     Motor2_Direction_Status = Direction_Open;
	     Motor2_Position ++;
	     Motor2_Location ++;
	     #endif
        }
	else
	{    
	     #ifdef _CONFIG_HallB_Dual_Direction_From_2_To_1
	     Motor2_Direction_Status = Direction_Open;
	     Motor2_Position ++;
	     Motor2_Location ++;
	     #else
	     Motor2_Direction_Status = Direction_Close;
	     if(Motor2_Position > 0)
	     {
		  Motor2_Position --;
	     }
	     Motor2_Location --;
	     #endif
	}
	HallB1_High_Pluse_Timer = 0;
    }
    #ifdef _CONFIG_DIAG_Hall_StaticDiag
    }
    #endif
  #endif
  #ifdef _CONFIG_HallB_Single
     #ifdef _CONFIG_DIAG_Hall_StaticDiag
     if(FALSE == HallB1_Diagnostic_Working_Status)
     {
     #endif
     #ifndef _CONFIG_HallB_Single_Pluse_2_Direction_1
     HallB_Accumulator ++;    /*Used for Speed Control*/
     Motor2_HallCounter ++; /*Used for motor2 speedup*/
     Motor2_HallPluse1Width_Timer = 0; /*Used for HallPluseObstacle*/     
     HallB1_DynamicDiag_HallCounter ++; /*Used for Hall DynamicDiag*/
     HallB1_HallCounter ++;   /*Used for Monitoring Hall Counter of each channel*/
     
     #ifdef _CONFIG_Gen2_Board
     HallB2_Status = Get_Hall_2B_U1_46_Port_Status();
     #endif
     #if defined(_CONFIG_Gen3_Board) || defined(_CONFIG_Gen4_Board)
     HallB2_Status = Get_Hall_2B_P8_3_Port_Status();
     #endif
     if(_TAUJ_INPUT_EDGE_FALLING == TAUJ0.CMUR2)
     {
       // TAUJ0.CMUR2 = _TAUJ_INPUT_EDGE_RISING;
	HallB1_Status = FALSE;
	#ifdef _CONFIG_HallB_Single_Low_Open_High_Close
	if(FALSE == HallB2_Status)
	#else
	if(TRUE == HallB2_Status)
	#endif
        {
	     Motor2_Direction_Status = Direction_Open;
	     Motor2_Position ++;
	     Motor2_Location ++;
        }
	else
	{    
	     Motor2_Direction_Status = Direction_Close;
	     if(Motor2_Position > 0)
	     {
		  Motor2_Position --;  
	     }
	     Motor2_Location --;
	}
	HallB1_Low_Pluse_Timer = 0;
     }
    
     if(_TAUJ_INPUT_EDGE_RISING == TAUJ0.CMUR2)
     {
        //TAUJ0.CMUR2 = _TAUJ_INPUT_EDGE_FALLING;	
        HallB1_Status = TRUE;
	#ifdef _CONFIG_HallB_Single_Low_Open_High_Close
	if(FALSE == HallB2_Status)
	#else
	if(TRUE == HallB2_Status)
	#endif
        {
	     Motor2_Direction_Status = Direction_Open;
	     Motor2_Position ++;
	     Motor2_Location ++;
        }
	else
	{    
	     Motor2_Direction_Status = Direction_Close;
	     if(Motor2_Position > 0)
	     {
		  Motor2_Position --;
	     }
	     Motor2_Location --;
	}
	HallB1_High_Pluse_Timer = 0;
     }
     #else
     /*if(_TAUJ_INPUT_EDGE_FALLING == TAUJ0.CMUR2)
     {
	HallB1_Status = FALSE;
     }
     if(_TAUJ_INPUT_EDGE_RISING == TAUJ0.CMUR2)
     {	
        HallB1_Status = TRUE;
     }*/
     #endif
    #ifdef _CONFIG_DIAG_Hall_StaticDiag
    }
    #endif
  #endif
}

/*********************************************************************************************
** Name:	  API_HallB2_Interrupt
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_HallB2_Interrupt(void)
{
  #ifdef _CONFIG_HallB_Dual
     #ifdef _CONFIG_DIAG_Hall_StaticDiag
     if(FALSE == HallB2_Diagnostic_Working_Status)
     {
     #endif
     HallB_Accumulator ++;      /*Used for Speed Control*/
     Motor2_HallCounter ++; /*Used for motor2 speedup*/
     Motor2_HallPluse2Width_Timer = 0; /*Used for HallPluseObstacle*/    
     HallB2_DynamicDiag_HallCounter ++; /*Used for Hall DynamicDiag*/
     HallB2_HallCounter ++;   /*Used for Monitoring Hall Counter of each channel*/
     
    
     #if defined(_CONFIG_Gen1_Board) || defined(_CONFIG_Gen2_Board)
     if(_TAUJ_INPUT_EDGE_FALLING == TAUJ0.CMUR3)
     #endif
     #if defined(_CONFIG_Gen3_Board) || defined(_CONFIG_Gen4_Board)
     if(_TAUJ_INPUT_EDGE_FALLING == TAUJ0.CMUR1)
     #endif
     {
       // TAUJ0.CMUR3 = _TAUJ_INPUT_EDGE_RISING;
	HallB2_Status = FALSE;
	if(FALSE == HallB1_Status)
        {
	     #ifdef _CONFIG_HallB_Dual_Direction_From_2_To_1
	     Motor2_Direction_Status = Direction_Close;
	     if(Motor2_Position > 0)
	     {
		  Motor2_Position --;  
	     }
	     Motor2_Location --;
	     #else
	     Motor2_Direction_Status = Direction_Open;
	     Motor2_Position ++;
	     Motor2_Location ++;
	     #endif
	    
        }
	else
	{    
	     #ifdef _CONFIG_HallB_Dual_Direction_From_2_To_1
	     Motor2_Direction_Status = Direction_Open;
	     Motor2_Position ++;
	     Motor2_Location ++;
	     #else
	     Motor2_Direction_Status = Direction_Close;
	     if(Motor2_Position > 0)
	     {
		  Motor2_Position --;  
	     }
	     Motor2_Location --;
	     #endif
	}
	HallB2_Low_Pluse_Timer = 0;
    }    
    
     #if defined(_CONFIG_Gen1_Board) || defined(_CONFIG_Gen2_Board)
     if(_TAUJ_INPUT_EDGE_RISING == TAUJ0.CMUR3)
     #endif
     #if defined(_CONFIG_Gen3_Board) || defined(_CONFIG_Gen4_Board)
     if(_TAUJ_INPUT_EDGE_RISING == TAUJ0.CMUR1)
     #endif
    {
        //TAUJ0.CMUR3 = _TAUJ_INPUT_EDGE_FALLING;	
        HallB2_Status = TRUE;
	if(TRUE == HallB1_Status)
        {
	     #ifdef _CONFIG_HallB_Dual_Direction_From_2_To_1
	     Motor2_Direction_Status = Direction_Close;
	     if(Motor2_Position > 0)
	     {
		  Motor2_Position --;
	     }
	     Motor2_Location --;
	     #else
	     Motor2_Direction_Status = Direction_Open;
	     Motor2_Position ++; 
	     Motor2_Location ++;
	     #endif
        }
	else
	{    
	     #ifdef _CONFIG_HallB_Dual_Direction_From_2_To_1
	     Motor2_Direction_Status = Direction_Open;
	     Motor2_Position ++;
	     Motor2_Location ++;
	     #else
	     Motor2_Direction_Status = Direction_Close;
	     if(Motor2_Position > 0)
	     {
		  Motor2_Position --;
	     }
	     Motor2_Location --;
	     #endif
	}
	HallB2_High_Pluse_Timer = 0;
    }
    #ifdef _CONFIG_DIAG_Hall_StaticDiag
    }
    #endif  
  #endif
  #ifdef _CONFIG_HallB_Single
  #ifdef _CONFIG_DIAG_Hall_StaticDiag
     if(FALSE == HallB2_Diagnostic_Working_Status)
     {
     #endif
     #ifdef _CONFIG_HallB_Single_Pluse_2_Direction_1
     HallB_Accumulator ++;      /*Used for Speed Control*/
     Motor2_HallCounter ++; /*Used for motor2 speedup*/
     Motor2_HallPluse2Width_Timer = 0; /*Used for HallPluseObstacle*/    
     HallB2_DynamicDiag_HallCounter ++; /*Used for Hall DynamicDiag*/
     HallB2_HallCounter ++;   /*Used for Monitoring Hall Counter of each channel*/
         
     #ifdef _CONFIG_Gen2_Board
     HallB1_Status = Get_Hall_2A_U1_45_Port_Status();
     #endif
     #if defined(_CONFIG_Gen3_Board) || defined(_CONFIG_Gen4_Board)
     HallB1_Status = Get_Hall_2A_P8_4_Port_Status();
     #endif
     
     #if defined(_CONFIG_Gen1_Board) || defined(_CONFIG_Gen2_Board)
     if(_TAUJ_INPUT_EDGE_FALLING == TAUJ0.CMUR3)
     #endif
     #if defined(_CONFIG_Gen3_Board) || defined(_CONFIG_Gen4_Board)
     if(_TAUJ_INPUT_EDGE_FALLING == TAUJ0.CMUR1)
     #endif
     {
       // TAUJ0.CMUR3 = _TAUJ_INPUT_EDGE_RISING;
	HallB2_Status = FALSE;
	#ifdef _CONFIG_HallB_Single_Low_Open_High_Close
	if(FALSE == HallB1_Status)
	#else
	if(TRUE == HallB1_Status)
	#endif
        {
	     Motor2_Direction_Status = Direction_Open;
	     Motor2_Position ++;
	     Motor2_Location ++; 
        }
	else
	{    
	     Motor2_Direction_Status = Direction_Close;
	     if(Motor2_Position > 0)
	     {
		  Motor2_Position --;  
	     }
	     Motor2_Location --;
	}
	HallB2_Low_Pluse_Timer = 0;
     }
     
     #if defined(_CONFIG_Gen1_Board) || defined(_CONFIG_Gen2_Board)
     if(_TAUJ_INPUT_EDGE_RISING == TAUJ0.CMUR3)
     #endif
     #if defined(_CONFIG_Gen3_Board) || defined(_CONFIG_Gen4_Board)
     if(_TAUJ_INPUT_EDGE_RISING == TAUJ0.CMUR1)
     #endif
     {
        //TAUJ0.CMUR3 = _TAUJ_INPUT_EDGE_FALLING;	
        HallB2_Status = TRUE;
	#ifdef _CONFIG_HallB_Single_Low_Open_High_Close
	if(FALSE == HallB1_Status)
	#else
	if(TRUE == HallB1_Status)
	#endif
        {
	     Motor2_Direction_Status = Direction_Open;
	     Motor2_Position ++; 
	     Motor2_Location ++;
        }
	else
	{    
	     Motor2_Direction_Status = Direction_Close;
	     if(Motor2_Position > 0)
	     {
		  Motor2_Position --;
	     }
	     Motor2_Location --;
	 }
	 HallB2_High_Pluse_Timer = 0;
     }
     #else
     /*if(_TAUJ_INPUT_EDGE_FALLING == TAUJ0.CMUR3)
     {
	 HallB2_Status = FALSE;
     }
     if(_TAUJ_INPUT_EDGE_RISING == TAUJ0.CMUR3)
     {	
         HallB2_Status = TRUE;
     }*/
     #endif
    #ifdef _CONFIG_DIAG_Hall_StaticDiag
    }
    #endif  
  #endif  
}


#ifdef _CONFIG_HallC
/*********************************************************************************************
** Name:	   API_HallC1_Interrupt
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_HallC1_Interrupt(void)
{
  #ifdef _CONFIG_HallC_Dual	
     #ifdef _CONFIG_DIAG_Hall_StaticDiag
     if(FALSE == HallC1_Diagnostic_Working_Status)
     {
     #endif	     
      HallC_Accumulator ++;       /*Used for Speed Control*/
      Motor4_HallCounter ++; /*Used for motor4 speedup*/
      Motor4_HallPluse1Width_Timer = 0; /*Used for HallPluseObstacle*/
      HallC1_DynamicDiag_HallCounter ++; /*Used for Hall DynamicDiag*/
      HallC1_HallCounter ++;   /*Used for Monitoring Hall Counter of each channel*/
    
    #ifndef _CONFIG_Gen4_Board_003_004
    if(_TAUJ_INPUT_EDGE_FALLING == TAUJ1.CMUR0)
    #else
    if(_TAUB_INPUT_EDGE_FALLING == TAUB0.CMUR3)
    #endif
    {
        //TAUJ1.CMUR0 = _TAUJ_INPUT_EDGE_RISING;
	HallC1_Status = FALSE;
	if(TRUE == HallC2_Status)
        {
	     #ifdef _CONFIG_HallC_Dual_Direction_From_2_To_1
	     Motor4_Direction_Status = Direction_Close;
	     if(Motor4_Position > 0)
	     {
		  Motor4_Position --;
	     }
	     Motor4_Location --;
	     #else
	     Motor4_Direction_Status = Direction_Open;
	     Motor4_Position ++;
	     Motor4_Location ++;
	     #endif
        }
	else
	{    	     
	     
	     #ifdef _CONFIG_HallC_Dual_Direction_From_2_To_1
	     Motor4_Direction_Status = Direction_Open;
	     Motor4_Position ++;
	     Motor4_Location ++;
	     #else
	     Motor4_Direction_Status = Direction_Close;
	     if(Motor4_Position > 0)
	     {
		  Motor4_Position --;
	     }
	     Motor4_Location --;
	     #endif
	}
	HallC1_Low_Pluse_Timer = 0;
    }
    
    #ifndef _CONFIG_Gen4_Board_003_004
    if(_TAUJ_INPUT_EDGE_RISING == TAUJ1.CMUR0)
    #else
    if(_TAUB_INPUT_EDGE_RISING == TAUB0.CMUR3)
    #endif
    {
        //TAUJ1.CMUR0 = _TAUJ_INPUT_EDGE_FALLING;	
        HallC1_Status = TRUE;
	if(FALSE == HallC2_Status)
        {
	     #ifdef _CONFIG_HallC_Dual_Direction_From_2_To_1
	     Motor4_Direction_Status = Direction_Close;
	     if(Motor4_Position > 0)
	     {
		  Motor4_Position --;		
	     }
	     Motor4_Location --;
	     #else
	     Motor4_Direction_Status = Direction_Open;
	     Motor4_Position ++;  
	     Motor4_Location ++;
	     #endif
        }
	else
	{    
	     
	     #ifdef _CONFIG_HallC_Dual_Direction_From_2_To_1
	     Motor4_Direction_Status = Direction_Open;
	     Motor4_Position ++;
	     Motor4_Location ++;
	     #else
	     Motor4_Direction_Status = Direction_Close;
	     if(Motor4_Position > 0)
	     {
		  Motor4_Position --;		
	     }
	     Motor4_Location --;
	     #endif
	}
	HallC1_High_Pluse_Timer = 0;
     }
    #ifdef _CONFIG_DIAG_Hall_StaticDiag
    }
    #endif
  #endif
  #ifdef _CONFIG_HallC_Single
     #ifdef _CONFIG_DIAG_Hall_StaticDiag
     if(FALSE == HallC1_Diagnostic_Working_Status)
     {
     #endif	   
      #ifndef _CONFIG_HallC_Single_Pluse_2_Direction_1
      HallC_Accumulator ++;       /*Used for Speed Control*/
      Motor4_HallCounter ++; /*Used for Motor4 speedup*/
      Motor4_HallPluse1Width_Timer = 0; /*Used for HallPluseObstacle*/
      HallC1_DynamicDiag_HallCounter ++; /*Used for Hall DynamicDiag*/
      HallC1_HallCounter ++;   /*Used for Monitoring Hall Counter of each channel*/
     
     #ifdef _CONFIG_Gen3_Board
     HallC2_Status = Get_DI_X2_24_P9_4_Port_Status();
     #endif
     #ifdef _CONFIG_Gen4_Board_003_004
     HallC2_Status = Get_DI_X2_22_P10_5_Port_Status();
     #endif
     
     #ifndef _CONFIG_Gen4_Board_003_004
     if(_TAUJ_INPUT_EDGE_FALLING == TAUJ1.CMUR0)
     #else
     if(_TAUB_INPUT_EDGE_FALLING == TAUB0.CMUR3)
     #endif
     {
       // TAUJ1.CMUR0 = _TAUJ_INPUT_EDGE_RISING;
	HallC1_Status = FALSE;
	#ifdef _CONFIG_HallC_Single_Low_Open_High_Close
	if(FALSE == HallC2_Status)
	#else
	if(TRUE == HallC2_Status)
	#endif
        {
	     Motor4_Direction_Status = Direction_Open;
	     Motor4_Position ++;
	     Motor4_Location ++;
        }
	else
	{    	     
	     Motor4_Direction_Status = Direction_Close;
	     if(Motor4_Position > 0)
	     {
		  Motor4_Position --;
	     }
	     Motor4_Location --;
	}
	HallC1_Low_Pluse_Timer = 0;
     }
    
     #ifndef _CONFIG_Gen4_Board_003_004
     if(_TAUJ_INPUT_EDGE_RISING == TAUJ1.CMUR0)
     #else
     if(_TAUB_INPUT_EDGE_RISING == TAUB0.CMUR3)
     #endif
     {
        //TAUJ1.CMUR0 = _TAUJ_INPUT_EDGE_FALLING;	
        HallC1_Status = TRUE;
	#ifdef _CONFIG_HallC_Single_Low_Open_High_Close
	if(FALSE == HallC2_Status)
	#else
	if(TRUE == HallC2_Status)
	#endif
        {
	     Motor4_Direction_Status = Direction_Open;
	     Motor4_Position ++;  
	     Motor4_Location ++;
        }
	else
	{    
	     Motor4_Direction_Status = Direction_Close;
	     if(Motor4_Position > 0)
	     {
		  Motor4_Position --;		
	     }
	     Motor4_Location --;
	}
	HallC1_High_Pluse_Timer = 0;
     }
     #else
     /*if(_TAUJ_INPUT_EDGE_FALLING == TAUJ1.CMUR0)
     {
	HallC1_Status = FALSE;
     }
     if(_TAUJ_INPUT_EDGE_RISING == TAUJ1.CMUR0)
     {	
        HallC1_Status = TRUE;
     }*/
     #endif
    #ifdef _CONFIG_DIAG_Hall_StaticDiag
    }
    #endif
  #endif
}

/*********************************************************************************************
** Name:	  API_HallC2_Interrupt   
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_HallC2_Interrupt(void)
{
   #ifdef _CONFIG_HallC_Dual
     #ifdef _CONFIG_DIAG_Hall_StaticDiag
     if(FALSE == HallC2_Diagnostic_Working_Status)
     {
     #endif
     HallC_Accumulator ++;     /*Used for Speed Control*/
     Motor4_HallCounter ++; /*Used for Motor4 speedup*/
     Motor4_HallPluse2Width_Timer = 0; /*Used for HallPluseObstacle*/  
     HallC2_DynamicDiag_HallCounter ++; /*Used for Hall DynamicDiag*/
     HallC2_HallCounter ++;   /*Used for Monitoring Hall Counter of each channel*/
    
     #ifdef _CONFIG_Gen3_Board
     if(_TAUB_INPUT_EDGE_FALLING == TAUB0.CMUR11)
     #endif
     #ifdef _CONFIG_Gen4_Board_003_004
     if(_TAUD_INPUT_EDGE_FALLING == TAUD0.CMUR11)
     #endif
     {
       // TAUB0.CMUR11 = _TAUB_INPUT_EDGE_RISING;
	HallC2_Status = FALSE;
	if(FALSE == HallC1_Status)
        {
	     #ifdef _CONFIG_HallC_Dual_Direction_From_2_To_1
	     Motor4_Direction_Status = Direction_Close;
	     if(Motor4_Position > 0)
	     {
		  Motor4_Position --;		  
	     }
	     Motor4_Location --;
	     #else
	     Motor4_Direction_Status = Direction_Open;
	     Motor4_Position ++; 
	     Motor4_Location ++;
	     #endif
        }
	else
	{    
	     
	     #ifdef _CONFIG_HallC_Dual_Direction_From_2_To_1
	     Motor4_Direction_Status = Direction_Open;
	     Motor4_Position ++;
	     Motor4_Location ++;
	     #else
	     Motor4_Direction_Status = Direction_Close;
	     if(Motor4_Position > 0)
	     {
		  Motor4_Position --;		  
	     }
	     Motor4_Location --;
	     #endif
	}
	HallC2_Low_Pluse_Timer = 0;
    }
    
     #ifdef _CONFIG_Gen3_Board
     if(_TAUB_INPUT_EDGE_RISING == TAUB0.CMUR11)
     #endif
     #ifdef _CONFIG_Gen4_Board_003_004
     if(_TAUD_INPUT_EDGE_RISING == TAUD0.CMUR11)
     #endif
     {
        //TAUB0.CMUR11 = _TAUB_INPUT_EDGE_FALLING;	
        HallC2_Status = TRUE;
	if(TRUE == HallC1_Status)
        {
	     #ifdef _CONFIG_HallC_Dual_Direction_From_2_To_1
	     Motor4_Direction_Status = Direction_Close;
	     if(Motor4_Position > 0)
	     {
		  Motor4_Position --;		 
	     }
	     Motor4_Location --;
	     #else
	     Motor4_Direction_Status = Direction_Open;
	     Motor4_Position ++; 
	     Motor4_Location ++;
	     #endif
        }
	else
	{    
	     
	     #ifdef _CONFIG_HallC_Dual_Direction_From_2_To_1
	     Motor4_Direction_Status = Direction_Open;
	     Motor4_Position ++;
	     Motor4_Location ++;
	     #else
	     Motor4_Direction_Status = Direction_Close;
	     if(Motor4_Position > 0)
	     {
		  Motor4_Position --;		 
	     }
	     Motor4_Location --;
	     #endif
	}
	HallC2_High_Pluse_Timer = 0;
    }
    #ifdef _CONFIG_DIAG_Hall_StaticDiag
    }
    #endif
  #endif
  #ifdef _CONFIG_HallC_Single
     #ifdef _CONFIG_DIAG_Hall_StaticDiag
     if(FALSE == HallC2_Diagnostic_Working_Status)
     {
     #endif
     #ifdef _CONFIG_HallC_Single_Pluse_2_Direction_1
     HallC_Accumulator ++;     /*Used for Speed Control*/
     Motor4_HallCounter ++; /*Used for Motor4 speedup*/
     Motor4_HallPluse2Width_Timer = 0; /*Used for HallPluseObstacle*/  
     HallC2_DynamicDiag_HallCounter ++; /*Used for Hall DynamicDiag*/
     HallC2_HallCounter ++;   /*Used for Monitoring Hall Counter of each channel*/
         
     #ifdef _CONFIG_Gen3_Board
     HallC1_Status = Get_DI_X2_22_P11_0_Port_Status();
     #endif     
     #ifdef _CONFIG_Gen4_Board_003_004
     HallC1_Status = Get_DI_X2_24_P10_12_Port_Status();
     #endif
     
     #ifdef _CONFIG_Gen3_Board
     if(_TAUB_INPUT_EDGE_FALLING == TAUB0.CMUR11)
     #endif
     #ifdef _CONFIG_Gen4_Board_003_004
     if(_TAUD_INPUT_EDGE_FALLING == TAUD0.CMUR11)
     #endif
     {
       // TAUB0.CMUR11 = _TAUB_INPUT_EDGE_RISING;
	HallC2_Status = FALSE;
	#ifdef _CONFIG_HallC_Single_Low_Open_High_Close
	if(FALSE == HallC1_Status)
	#else
	if(TRUE == HallC1_Status)
	#endif
        {
	     Motor4_Direction_Status = Direction_Open;
	     Motor4_Position ++; 
	     Motor4_Location ++;
        }
	else
	{    
	     Motor4_Direction_Status = Direction_Close;
	     if(Motor4_Position > 0)
	     {
		  Motor4_Position --;		  
	     }
	     Motor4_Location --;
	}
	HallC2_Low_Pluse_Timer = 0;
     }
    
     #ifdef _CONFIG_Gen3_Board
     if(_TAUB_INPUT_EDGE_RISING == TAUB0.CMUR11)
     #endif
     #ifdef _CONFIG_Gen4_Board_003_004
     if(_TAUD_INPUT_EDGE_RISING == TAUD0.CMUR11)
     #endif
     {
        //TAUB0.CMUR11 = _TAUB_INPUT_EDGE_FALLING;	
        HallC2_Status = TRUE;
	if(TRUE == HallC1_Status)
        {
	     Motor4_Direction_Status = Direction_Open;
	     Motor4_Position ++; 
	     Motor4_Location ++;
        }
	else
	{    
	     Motor4_Direction_Status = Direction_Close;
	     if(Motor4_Position > 0)
	     {
		  Motor4_Position --;		 
	     }
	     Motor4_Location --;
	 }
	 HallC2_High_Pluse_Timer = 0;
     }
     #else
     /*if(_TAUB_INPUT_EDGE_FALLING == TAUB0.CMUR11)
     {
	  HallC2_Status = FALSE;
     }
     if(_TAUB_INPUT_EDGE_RISING == TAUB0.CMUR11)
     {
	  HallC2_Status = TRUE;
     }*/
     #endif
    #ifdef _CONFIG_DIAG_Hall_StaticDiag
    }
    #endif
    
  #endif 
}
#endif

#ifdef _CONFIG_HallD
/*********************************************************************************************
** Name:	   API_HallD1_Interrupt
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_HallD1_Interrupt(void)
{
  #ifdef _CONFIG_HallD_Dual	
     #ifdef _CONFIG_DIAG_Hall_StaticDiag
     if(FALSE == HallD1_Diagnostic_Working_Status)
     {
     #endif	     
      HallD_Accumulator ++;       /*Used for Speed Control*/
      CinchMotor_HallCounter ++; /*Used for CinchMotor speedup*/
      CinchMotor_HallPluse1Width_Timer = 0; /*Used for HallPluseObstacle*/
      HallD1_DynamicDiag_HallCounter ++; /*Used for Hall DynamicDiag*/
      HallD1_HallCounter ++;   /*Used for Monitoring Hall Counter of each channel*/

    if(_TAUJ_INPUT_EDGE_FALLING == TAUJ1.CMUR2)
    {
        //TAUJ1.CMUR2 = _TAUJ_INPUT_EDGE_RISING;
	HallD1_Status = FALSE;
	if(TRUE == HallD2_Status)
        {
	     #ifdef _CONFIG_HallD_Dual_Direction_From_2_To_1
	     CinchMotor_Direction_Status = Direction_Close;
	     if(CinchMotor_Position > 0)
	     {
	          CinchMotor_Position --;
	     }
	     CinchMotor_Location --;
	     #else
	     CinchMotor_Direction_Status = Direction_Open;
	     CinchMotor_Position ++;
	     CinchMotor_Location ++;
	     #endif
        }
	else
	{    	     
	     
	     #ifdef _CONFIG_HallD_Dual_Direction_From_2_To_1
	     CinchMotor_Direction_Status = Direction_Open;
	     CinchMotor_Position ++;
	     CinchMotor_Location ++;
	     #else
	     CinchMotor_Direction_Status = Direction_Close;
	     if(CinchMotor_Position > 0)
	     {
		   CinchMotor_Position --;
	     }
	     CinchMotor_Location --;
	     #endif
	}
	HallD1_Low_Pluse_Timer = 0;
    }
    
    if(_TAUJ_INPUT_EDGE_RISING == TAUJ1.CMUR2)
    {
        //TAUJ1.CMUR2 = _TAUJ_INPUT_EDGE_FALLING;	
        HallD1_Status = TRUE;
	if(FALSE == HallD2_Status)
        {
	     #ifdef _CONFIG_HallD_Dual_Direction_From_2_To_1
	     CinchMotor_Direction_Status = Direction_Close;
	     if(CinchMotor_Position > 0)
	     {
	          CinchMotor_Position --;		
	     }
	     CinchMotor_Location --;
	     #else
	     CinchMotor_Direction_Status = Direction_Open;
	     CinchMotor_Position ++;  
	     CinchMotor_Location ++;
	     #endif
        }
	else
	{    
	     
	     #ifdef _CONFIG_HallD_Dual_Direction_From_2_To_1
	     CinchMotor_Direction_Status = Direction_Open;
	     CinchMotor_Position ++;
	     CinchMotor_Location ++;
	     #else
	     CinchMotor_Direction_Status = Direction_Close;
	     if(CinchMotor_Position > 0)
	     {
	          CinchMotor_Position --;		
	     }
	     CinchMotor_Location --;
	     #endif
	}
	HallD1_High_Pluse_Timer = 0;
     }
    #ifdef _CONFIG_DIAG_Hall_StaticDiag
    }
    #endif
  #endif
  #ifdef _CONFIG_HallD_Single
     #ifdef _CONFIG_DIAG_Hall_StaticDiag
     if(FALSE == HallD1_Diagnostic_Working_Status)
     {
     #endif	   
      #ifndef _CONFIG_HallD_Single_Pluse_2_Direction_1
      HallD_Accumulator ++;       /*Used for Speed Control*/
      CinchMotor_HallCounter ++; /*Used for CinchMotor speedup*/
      CinchMotor_HallPluse1Width_Timer = 0; /*Used for HallPluseObstacle*/
      HallD1_DynamicDiag_HallCounter ++; /*Used for Hall DynamicDiag*/
      HallD1_HallCounter ++;   /*Used for Monitoring Hall Counter of each channel*/
     
     #ifdef _CONFIG_Gen4_Board
     HallD2_Status = Get_DI_X2_20_P8_12_Port_Status();
     #endif
     if(_TAUJ_INPUT_EDGE_FALLING == TAUJ1.CMUR2)
     {
       // TAUJ1.CMUR2 = _TAUJ_INPUT_EDGE_RISING;
	HallD1_Status = FALSE;
	#ifdef _CONFIG_HallD_Single_Low_Open_High_Close
	if(FALSE == HallD2_Status)
	#else
	if(TRUE == HallD2_Status)
	#endif
        {
	     CinchMotor_Direction_Status = Direction_Open;
	     CinchMotor_Position ++;
	     CinchMotor_Location ++;
        }
	else
	{    	     
	     CinchMotor_Direction_Status = Direction_Close;
	     if(CinchMotor_Position > 0)
	     {
		   CinchMotor_Position --;
	     }
	     CinchMotor_Location --;
	}
	HallD1_Low_Pluse_Timer = 0;
     }
    
     if(_TAUJ_INPUT_EDGE_RISING == TAUJ1.CMUR2)
     {
        //TAUJ1.CMUR2 = _TAUJ_INPUT_EDGE_FALLING;	
        HallD1_Status = TRUE;
	#ifdef _CONFIG_HallD_Single_Low_Open_High_Close
	if(FALSE == HallD2_Status)
	#else
	if(TRUE == HallD2_Status)
	#endif
        {
	     CinchMotor_Direction_Status = Direction_Open;
	     CinchMotor_Position ++;  
	     CinchMotor_Location ++;
        }
	else
	{    
	     CinchMotor_Direction_Status = Direction_Close;
	     if(CinchMotor_Position > 0)
	     {
	          CinchMotor_Position --;		
	     }
	     CinchMotor_Location --;
	}
	HallD1_High_Pluse_Timer = 0;
     }
     #else
     /*if(_TAUJ_INPUT_EDGE_FALLING == TAUJ1.CMUR2)
     {
	HallD1_Status = FALSE;
     }
     if(_TAUJ_INPUT_EDGE_RISING == TAUJ1.CMUR2)
     {	
        HallD1_Status = TRUE;
     }*/
     #endif
    #ifdef _CONFIG_DIAG_Hall_StaticDiag
    }
    #endif
  #endif
}

/*********************************************************************************************
** Name:	  API_HallD2_Interrupt   
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_HallD2_Interrupt(void)
{
   #ifdef _CONFIG_HallD_Dual
     #ifdef _CONFIG_DIAG_Hall_StaticDiag
     if(FALSE == HallD2_Diagnostic_Working_Status)
     {
     #endif
     HallD_Accumulator ++;     /*Used for Speed Control*/
     CinchMotor_HallCounter ++; /*Used for CinchMotor speedup*/
     CinchMotor_HallPluse2Width_Timer = 0; /*Used for HallPluseObstacle*/  
     HallD2_DynamicDiag_HallCounter ++; /*Used for Hall DynamicDiag*/
     HallD2_HallCounter ++;   /*Used for Monitoring Hall Counter of each channel*/
    
     #ifdef _CONFIG_Gen4_Board
     if(_TAUJ_INPUT_EDGE_FALLING == TAUJ1.CMUR3)
     #endif
     {
       // TAUJ1.CMUR3 = _TAUB_INPUT_EDGE_RISING;
	HallD2_Status = FALSE;
	if(FALSE == HallD1_Status)
        {
	     #ifdef _CONFIG_HallD_Dual_Direction_From_2_To_1
	     CinchMotor_Direction_Status = Direction_Close;
	     if(CinchMotor_Position > 0)
	     {
		  CinchMotor_Position --;		  
	     }
	     CinchMotor_Location --;
	     #else
	     CinchMotor_Direction_Status = Direction_Open;
	     CinchMotor_Position ++; 
	     CinchMotor_Location ++;
	     #endif
        }
	else
	{    
	     
	     #ifdef _CONFIG_HallD_Dual_Direction_From_2_To_1
	     CinchMotor_Direction_Status = Direction_Open;
	     CinchMotor_Position ++;
	     CinchMotor_Location ++;
	     #else
	     CinchMotor_Direction_Status = Direction_Close;
	     if(CinchMotor_Position > 0)
	     {
		  CinchMotor_Position --;		  
	     }
	     CinchMotor_Location --;
	     #endif
	}
	HallD2_Low_Pluse_Timer = 0;
    }
    
     #ifdef _CONFIG_Gen4_Board
     if(_TAUJ_INPUT_EDGE_RISING == TAUJ1.CMUR3)
     #endif
     {
        //TAUJ1.CMUR3 = _TAUB_INPUT_EDGE_FALLING;	
        HallD2_Status = TRUE;
	if(TRUE == HallD1_Status)
        {
	     #ifdef _CONFIG_HallD_Dual_Direction_From_2_To_1
	     CinchMotor_Direction_Status = Direction_Close;
	     if(CinchMotor_Position > 0)
	     {
		  CinchMotor_Position --;		 
	     }
	     CinchMotor_Location --;
	     #else
	     CinchMotor_Direction_Status = Direction_Open;
	     CinchMotor_Position ++; 
	     CinchMotor_Location ++;
	     #endif
        }
	else
	{    
	     
	     #ifdef _CONFIG_HallD_Dual_Direction_From_2_To_1
	     CinchMotor_Direction_Status = Direction_Open;
	     CinchMotor_Position ++;
	     CinchMotor_Location ++;
	     #else
	     CinchMotor_Direction_Status = Direction_Close;
	     if(CinchMotor_Position > 0)
	     {
		  CinchMotor_Position --;		 
	     }
	     CinchMotor_Location --;
	     #endif
	}
	HallD2_High_Pluse_Timer = 0;
    }
    #ifdef _CONFIG_DIAG_Hall_StaticDiag
    }
    #endif
  #endif
  #ifdef _CONFIG_HallD_Single
     #ifdef _CONFIG_DIAG_Hall_StaticDiag
     if(FALSE == HallD2_Diagnostic_Working_Status)
     {
     #endif
     #ifdef _CONFIG_HallD_Single_Pluse_2_Direction_1
     HallD_Accumulator ++;     /*Used for Speed Control*/
     CinchMotor_HallCounter ++; /*Used for CinchMotor speedup*/
     CinchMotor_HallPluse2Width_Timer = 0; /*Used for HallPluseObstacle*/  
     HallD2_DynamicDiag_HallCounter ++; /*Used for Hall DynamicDiag*/
     HallD2_HallCounter ++;   /*Used for Monitoring Hall Counter of each channel*/
         
     #ifdef _CONFIG_Gen4_Board
     HallD1_Status = Get_DI_X2_21_P8_11_Port_Status();
     #endif
     
     #ifdef _CONFIG_Gen4_Board
     if(_TAUJ_INPUT_EDGE_FALLING == TAUJ1.CMUR3)
     #endif
     {
       TAUJ1.CMUR3 = _TAUB_INPUT_EDGE_RISING;
	HallD2_Status = FALSE;
	#ifdef _CONFIG_HallD_Single_Low_Open_High_Close
	if(FALSE == HallD1_Status)
	#else
	if(TRUE == HallD1_Status)
	#endif
        {
	     CinchMotor_Direction_Status = Direction_Open;
	     CinchMotor_Position ++; 
	     CinchMotor_Location ++;
        }
	else
	{    
	     CinchMotor_Direction_Status = Direction_Close;
	     if(CinchMotor_Position > 0)
	     {
		  CinchMotor_Position --;		  
	     }
	     CinchMotor_Location --;
	}
	HallD2_Low_Pluse_Timer = 0;
     }
    
     #ifdef _CONFIG_Gen4_Board
     if(_TAUJ_INPUT_EDGE_RISING == TAUJ1.CMUR3)
     #endif
     {
        //TAUJ1.CMUR3 = _TAUB_INPUT_EDGE_FALLING;	
        HallD2_Status = TRUE;
	if(TRUE == HallD1_Status)
        {
	     CinchMotor_Direction_Status = Direction_Open;
	     CinchMotor_Position ++; 
	     CinchMotor_Location ++;
        }
	else
	{    
	     CinchMotor_Direction_Status = Direction_Close;
	     if(CinchMotor_Position > 0)
	     {
		  CinchMotor_Position --;		 
	     }
	     CinchMotor_Location --;
	 }
	 HallD2_High_Pluse_Timer = 0;
     }
     #else
     /*if(_TAUJ_INPUT_EDGE_FALLING == TAUJ1.CMUR3)
     {
	  HallD2_Status = FALSE;
     }
     if(_TAUJ_INPUT_EDGE_RISING == TAUJ1.CMUR3)
     {
	  HallD2_Status = TRUE;
     }*/
     #endif
    #ifdef _CONFIG_DIAG_Hall_StaticDiag
    }
    #endif
    
  #endif 
}
#endif

/*********************************************************************************************
** Name:	  API_Motor1_PWMDuty_Update
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_Motor1_PWMDuty_Update(uint16_t duty,uint16_t direction)
{
    #ifdef _CONFIG_Gen1_Board
    if(direction == Direction_Open)
    {	  
	  #ifdef _CONFIG_Motor1_Direction_From_2_To_1
	  Set_ODH_4_CTN_Duty(0);
	  Set_ODH_3_CTN_Duty(duty);
	  #else
	  Set_ODH_4_CTN_Duty(duty);
	  Set_ODH_3_CTN_Duty(0);
	  #endif
    }
    else if(direction == Direction_Close)
    {
	  #ifdef _CONFIG_Motor1_Direction_From_2_To_1
	  Set_ODH_4_CTN_Duty(duty);
	  Set_ODH_3_CTN_Duty(0);
	  #else
	  Set_ODH_4_CTN_Duty(0);
	  Set_ODH_3_CTN_Duty(duty);
	  #endif
    }
    else
    {
	  Set_ODH_4_CTN_Duty(0);
	  Set_ODH_3_CTN_Duty(0);
	  
    }
    #endif
    
    #ifdef _CONFIG_Gen2_Board
    if(direction == Direction_Open)
    {
	  //DRV8702_U3_StandardPWM_Control();
	  #ifdef _CONFIG_Motor1_Direction_From_2_To_1
	  Set_U3_IN1_PH_U1_85_Duty(Motor1_Period - duty);  /*J3_2 to J3_1*/
	  Set_U3_IN2_EN_U1_86_Duty(Motor1_Period);
	  #else
	  Set_U3_IN1_PH_U1_85_Duty(Motor1_Period);       
	  Set_U3_IN2_EN_U1_86_Duty(Motor1_Period - duty);  /*J3_1 to J3_2*/
	  #endif
    }
    else if(direction == Direction_Close)
    {	  
	  //DRV8702_U3_StandardPWM_Control();
	  #ifdef _CONFIG_Motor1_Direction_From_2_To_1
	  Set_U3_IN1_PH_U1_85_Duty(Motor1_Period);       
	  Set_U3_IN2_EN_U1_86_Duty(Motor1_Period - duty);  /*J3_1 to J3_2*/
	  #else
	  Set_U3_IN1_PH_U1_85_Duty(Motor1_Period - duty);  /*J3_2 to J3_1*/
	  Set_U3_IN2_EN_U1_86_Duty(Motor1_Period);
	  #endif
    }
    else
    {
	  //DRV8702_U3_StandardPWM_Control();
	  Set_U3_IN1_PH_U1_85_Duty(0);
	  Set_U3_IN2_EN_U1_86_Duty(0);
    }
    #endif
    
    #ifdef _CONFIG_Gen3_Board
    if(direction == Direction_Open)
    {
	  //DRV8705_U3_H_Bridge_PWM_Control();
	  #ifdef _CONFIG_Motor1_Direction_From_2_To_1
	  Set_M1_IN1_P10_11_Duty(Motor1_Period - duty);  /*J3_2 to J3_1*/
	  Set_M1_IN2_P10_12_Duty(Motor1_Period);
	  #else
	  Set_M1_IN1_P10_11_Duty(Motor1_Period);       
	  Set_M1_IN2_P10_12_Duty(Motor1_Period - duty);  /*J3_1 to J3_2*/
	  #endif
    }
    else if(direction == Direction_Close)
    {	  
	  //DRV8705_U3_H_Bridge_PWM_Control();
	  #ifdef _CONFIG_Motor1_Direction_From_2_To_1
	  Set_M1_IN1_P10_11_Duty(Motor1_Period);       
	  Set_M1_IN2_P10_12_Duty(Motor1_Period - duty);  /*J3_1 to J3_2*/
	  #else
	  Set_M1_IN1_P10_11_Duty(Motor1_Period - duty);  /*J3_2 to J3_1*/
	  Set_M1_IN2_P10_12_Duty(Motor1_Period);
	  #endif
    }
    else
    {
	  //DRV8705_U3_H_Bridge_PWM_Control();
	  Set_M1_IN1_P10_11_Duty(0);
	  Set_M1_IN2_P10_12_Duty(0);
    }
    #endif
    
    #ifdef _CONFIG_Gen4_Board
    if((direction == Direction_Open) || (direction == Direction_Close))
    {
          Set_M1_IN1_P10_11_Duty(duty);  
          //Set_M1_IN2_P10_12_Duty(Motor1_Period);
    }
    else
    {
          Set_M1_IN1_P10_11_Duty(0);
          //Set_M1_IN2_P10_12_Duty(0);
    }
    #endif
}

/*********************************************************************************************
** Name:	  API_Motor2_PWMDuty_Update
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_Motor2_PWMDuty_Update(uint16_t duty,uint16_t direction)
{
    #ifdef _CONFIG_Gen1_Board
    if(direction == Direction_Open)
    {
	  #ifdef _CONFIG_Motor2_Direction_From_2_To_1
	  Set_ODH_6_CTN_Duty(0);
	  Set_ODH_5_CTN_Duty(duty);
	  #else
	  Set_ODH_6_CTN_Duty(duty);
	  Set_ODH_5_CTN_Duty(0);
	  #endif
    }
    else if(direction == Direction_Close)
    {
	  #ifdef _CONFIG_Motor2_Direction_From_2_To_1
	  Set_ODH_6_CTN_Duty(duty);
	  Set_ODH_5_CTN_Duty(0);
	  #else
	  Set_ODH_6_CTN_Duty(0);
	  Set_ODH_5_CTN_Duty(duty);
	  #endif
    }
    else
    {
	  Set_ODH_6_CTN_Duty(0);
	  Set_ODH_5_CTN_Duty(0);	  
    }
    #endif
    #ifdef _CONFIG_Gen2_Board
    if(direction == Direction_Open)
    { 
	  //DRV8702_U4_StandardPWM_Control();
	  #ifdef _CONFIG_Motor2_Direction_From_2_To_1
	  Set_U4_IN1_PH_U1_81_Duty(Motor2_Period - duty);   /*J3_4 to J3_3*/
	  Set_U4_IN2_EN_U1_82_Duty(Motor2_Period);
	  #else
	  Set_U4_IN1_PH_U1_81_Duty(Motor2_Period);
	  Set_U4_IN2_EN_U1_82_Duty(Motor2_Period - duty);   /*J3_3 to J3_4*/
	  #endif
	  	  
    }
    else if(direction == Direction_Close)
    {	  
	  //DRV8702_U4_StandardPWM_Control();
	  #ifdef _CONFIG_Motor2_Direction_From_2_To_1
	  Set_U4_IN1_PH_U1_81_Duty(Motor2_Period);
	  Set_U4_IN2_EN_U1_82_Duty(Motor2_Period - duty);   /*J3_3 to J3_4*/
	  #else
	  Set_U4_IN1_PH_U1_81_Duty(Motor2_Period - duty);   /*J3_4 to J3_3*/
	  Set_U4_IN2_EN_U1_82_Duty(Motor2_Period);
	  #endif
    }
    else
    {
	  //DRV8702_U4_StandardPWM_Control();
	  Set_U4_IN1_PH_U1_81_Duty(0);
	  Set_U4_IN2_EN_U1_82_Duty(0);
    }
    #endif

    #if defined(_CONFIG_Gen3_Board) || defined(_CONFIG_Gen4_Board)
    #ifndef _CONFIG_Gen4B_Board
    if(direction == Direction_Open)
    { 
	  //DRV8705_U4_H_Bridge_PWM_Control();
	  #ifdef _CONFIG_Motor2_Direction_From_2_To_1
	  Set_M2_IN1_P10_7_Duty(Motor2_Period - duty);   /*J3_4 to J3_3*/
	  Set_M2_IN2_P10_8_Duty(Motor2_Period);
	  #else
	  Set_M2_IN1_P10_7_Duty(Motor2_Period);
	  Set_M2_IN2_P10_8_Duty(Motor2_Period - duty);   /*J3_3 to J3_4*/
	  #endif
	  	  
    }
    else if(direction == Direction_Close)
    {	  
	  //DRV8705_U4_H_Bridge_PWM_Control();
	  #ifdef _CONFIG_Motor2_Direction_From_2_To_1
	  Set_M2_IN1_P10_7_Duty(Motor2_Period);
	  Set_M2_IN2_P10_8_Duty(Motor2_Period - duty);   /*J3_3 to J3_4*/
	  #else
	  Set_M2_IN1_P10_7_Duty(Motor2_Period - duty);   /*J3_4 to J3_3*/
	  Set_M2_IN2_P10_8_Duty(Motor2_Period);
	  #endif
    }
    else
    {
	  //DRV8705_U4_H_Bridge_PWM_Control();
	  Set_M2_IN1_P10_7_Duty(0);
	  Set_M2_IN2_P10_8_Duty(0);
    }
    #else
    #ifdef _CONFIG_MagnaSideLatch_CCL
    if(direction == Direction_Release)
    { 
	  Set_M2_IN1_P10_7_Duty(duty);
	  Set_M2_IN2_P10_8_Duty(0);
    }
    else if(direction == Direction_Neutral)
    {	  
	  Set_M2_IN1_P10_7_Duty(0);
	  Set_M2_IN2_P10_8_Duty(0);
       Set_M4_IN1_P10_2_Duty(duty);
    }
    else if(direction == Direction_Unlock)
    {	  
	  Set_M2_IN1_P10_7_Duty(0);
	  Set_M2_IN2_P10_8_Duty(duty);
    }
    else
    {
	  Set_M2_IN1_P10_7_Duty(0);
	  Set_M2_IN2_P10_8_Duty(0);
       Set_M4_IN1_P10_2_Duty(0);
    }
    #endif
    #endif
    #endif
}

#ifdef _CONFIG_Motor4
/*********************************************************************************************
** Name:	  API_Motor4_PWMDuty_Update
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_Motor4_PWMDuty_Update(uint16_t duty,uint16_t direction)
{
    #if defined(_CONFIG_Gen3_Board) || defined(_CONFIG_Gen4_Board)
    if(direction == Direction_Open)
    { 
	  //DRV8705_U6_H_Bridge_PWM_Control();
	  #ifdef _CONFIG_Motor4_Direction_From_2_To_1
	  Set_M4_IN1_P10_2_Duty(Motor4_Period - duty);   /*J3_4 to J3_3*/
	  Set_M4_IN2_P10_1_Duty(Motor4_Period);
	  #else
	  Set_M4_IN1_P10_2_Duty(Motor4_Period);
	  Set_M4_IN2_P10_1_Duty(Motor4_Period - duty);   /*J3_3 to J3_4*/
	  #endif
	  	  
    }
    else if(direction == Direction_Close)
    {	  
	  //DRV8705_U6_H_Bridge_PWM_Control();
	  #ifdef _CONFIG_Motor4_Direction_From_2_To_1
	  Set_M4_IN1_P10_2_Duty(Motor4_Period);
	  Set_M4_IN2_P10_1_Duty(Motor4_Period - duty);   /*J3_3 to J3_4*/
	  #else
	  Set_M4_IN1_P10_2_Duty(Motor4_Period - duty);   /*J3_4 to J3_3*/
	  Set_M4_IN2_P10_1_Duty(Motor4_Period);
	  #endif
    }
    else
    {
	  //DRV8705_U6_H_Bridge_PWM_Control();
	  Set_M4_IN1_P10_2_Duty(0);
	  Set_M4_IN2_P10_1_Duty(0);
    }
    #endif
}
#endif


/*********************************************************************************************
** Name:	  API_CinchMotor_PWMDuty_Update
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_CinchMotor_PWMDuty_Update(uint16_t duty,uint16_t direction)
{
    #ifdef _CONFIG_Gen1_Board  
    if(direction == Direction_Neutral)
    { 
	  Set_CINCH_PWM_Duty(duty);
    }
    else if(direction == Direction_Cinch)
    {
	  Set_CINCH_PWM_Duty(duty);
    }
    else
    {
	  Set_CINCH_PWM_Duty(duty);
    }
    #endif
    
    #ifdef _CONFIG_Gen2_Board
    if(direction == Direction_Neutral)
    { 
	  //DRV8702_U5_StandardPWM_Control();
	  #ifdef _CONFIG_CinchMotor_Direction_From_2_To_1
	  Set_U5_IN1_PH_U1_89_Duty(CinchMotor_Period - duty);   /*J2_2 to J2_1*/
	  Set_U5_IN2_EN_U1_1_Duty(CinchMotor_Period);
	  #else
	  Set_U5_IN1_PH_U1_89_Duty(CinchMotor_Period);
	  Set_U5_IN2_EN_U1_1_Duty(CinchMotor_Period - duty);   /*J2_1 to J2_2*/
	  #endif
    }
    else if(direction == Direction_Cinch)
    {
	  //DRV8702_U5_StandardPWM_Control();
	  #ifdef _CONFIG_CinchMotor_Direction_From_2_To_1
	  Set_U5_IN1_PH_U1_89_Duty(CinchMotor_Period);
	  Set_U5_IN2_EN_U1_1_Duty(CinchMotor_Period - duty);   /*J2_1 to J2_2*/
	  #else
	  Set_U5_IN1_PH_U1_89_Duty(CinchMotor_Period - duty);   /*J2_2 to J2_1*/
	  Set_U5_IN2_EN_U1_1_Duty(CinchMotor_Period);
	  #endif
    }
    else
    {
	  //DRV8702_U5_StandardPWM_Control();
	  Set_U5_IN1_PH_U1_89_Duty(0);
	  Set_U5_IN2_EN_U1_1_Duty(0);
    }
    #endif
    
    #ifdef _CONFIG_Gen3_Board
    if(direction == Direction_Neutral)
    { 
         #ifdef _CONFIG_CalibrationFile_T1X
	      #ifdef _CONFIG_LatchControl_Together
	 if(CurrentLatchType == LatchType_InginLatch)
	 {
	      Set_M3_IN1_P11_1_Duty(CinchMotor_Period - duty);   /*J2_2 to J2_1*/
	      Set_M3_IN2_P10_3_Duty(CinchMotor_Period);
	 }
	 else if(CurrentLatchType == LatchType_HuffLatch)
	 {
	      Set_M3_IN1_P11_1_Duty(CinchMotor_Period);
	      Set_M3_IN2_P10_3_Duty(CinchMotor_Period - duty);   /*J2_1 to J2_2*/
	 }
	 else if(CurrentLatchType == LatchType_Default)
	 {
	      Set_M3_IN1_P11_1_Duty(CinchMotor_Period);
	      Set_M3_IN2_P10_3_Duty(CinchMotor_Period - duty);   /*J2_1 to J2_2*/
	 }
	      #endif
	 #else
              //DRV8705_U5_H_Bridge_PWM_Control();
	      #ifdef _CONFIG_CinchMotor_Direction_From_2_To_1
	      Set_M3_IN1_P11_1_Duty(CinchMotor_Period - duty);   /*J2_2 to J2_1*/
	      Set_M3_IN2_P10_3_Duty(CinchMotor_Period);
	      #else
	      Set_M3_IN1_P11_1_Duty(CinchMotor_Period);
	      Set_M3_IN2_P10_3_Duty(CinchMotor_Period - duty);   /*J2_1 to J2_2*/
	      #endif
	 #endif
	  
    }
    else if(direction == Direction_Cinch)
    {
	 #ifdef _CONFIG_CalibrationFile_T1X
	      #ifdef _CONFIG_LatchControl_Together
	 if(CurrentLatchType == LatchType_InginLatch)
	 {
	      Set_M3_IN1_P11_1_Duty(CinchMotor_Period);
	      Set_M3_IN2_P10_3_Duty(CinchMotor_Period - duty);   /*J2_1 to J2_2*/
	 }
	 else if(CurrentLatchType == LatchType_HuffLatch)
	 {
	      Set_M3_IN1_P11_1_Duty(CinchMotor_Period - duty);   /*J2_2 to J2_1*/
	      Set_M3_IN2_P10_3_Duty(CinchMotor_Period);
	 }
	 else if(CurrentLatchType == LatchType_Default)
	 {
	      Set_M3_IN1_P11_1_Duty(CinchMotor_Period - duty);   /*J2_2 to J2_1*/
	      Set_M3_IN2_P10_3_Duty(CinchMotor_Period);
	 } 
	      #endif
	 #else
              //DRV8705_U5_H_Bridge_PWM_Control();
	      #ifdef _CONFIG_CinchMotor_Direction_From_2_To_1
	      Set_M3_IN1_P11_1_Duty(CinchMotor_Period);
	      Set_M3_IN2_P10_3_Duty(CinchMotor_Period - duty);   /*J2_1 to J2_2*/
	      #else
	      Set_M3_IN1_P11_1_Duty(CinchMotor_Period - duty);   /*J2_2 to J2_1*/
	      Set_M3_IN2_P10_3_Duty(CinchMotor_Period);
	      #endif
	 #endif	  
    }
    else
    {
	  //DRV8705_U5_H_Bridge_PWM_Control();
	  Set_M3_IN1_P11_1_Duty(0);
	  Set_M3_IN2_P10_3_Duty(0);
    }
    #endif
    
    #ifdef _CONFIG_Gen4_Board
    if((direction == Direction_Neutral) || (direction == Direction_Cinch))
    {
          Set_M3_IN1_P11_1_Duty(duty);   /*J2_2 to J2_1*/
          //Set_M3_IN2_P10_3_Duty(CinchMotor_Period);
    }
    else
    {
          Set_M3_IN1_P11_1_Duty(0);
          //Set_M3_IN2_P10_3_Duty(0);
    }
    #endif
}

#ifdef _CONFIG_ReleaseMotor 
/*********************************************************************************************
** Name:	  API_ReleaseMotor_PWMDuty_Update    
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_ReleaseMotor_PWMDuty_Update(uint16_t duty)
{     
      #ifdef _CONFIG_Gen1_Board
      //Set_ODH_1_CTN_Duty(duty);
      //BTS5030_IN0_Set_Duty(duty);
      BTS5030_IN0_Set_PercentDuty(duty);
      #endif
      #ifdef _CONFIG_Gen2_Board
      //Set_U6_IN0_U1_50_Duty(duty);
      //BTS7040_IN0_Set_Duty(duty);
      BTS7040_IN0_Set_PercentDuty(duty);
      #endif
      
      #if defined(_CONFIG_Gen3_Board) || defined(_CONFIG_Gen4_Board)
      //Set_7040_IN0_P8_9_Duty(duty);
      //BTS7040_IN0_Set_Duty(duty);
      BTS7040_IN0_Set_PercentDuty(duty);
      #endif
      
}
#endif
#ifdef _CONFIG_Buzzer
/*********************************************************************************************
** Name:	   API_Buzzer_PWMDuty_Update
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_Buzzer_PWMDuty_Update(uint16_t duty)
{    
      #ifdef _CONFIG_Gen1_Board
      //Set_ODH_2_CTN_Duty(duty);
      //BTS5030_IN1_Set_Duty(duty);
      BTS5030_IN1_Set_PercentDuty(duty);
      #endif
      #ifdef _CONFIG_Gen2_Board
      //Set_U6_IN1_U1_49_Duty(duty);
      //BTS7040_IN1_Set_Duty(duty);
      BTS7040_IN1_Set_PercentDuty(duty);
      #endif
      
      #if defined(_CONFIG_Gen3_Board) || defined(_CONFIG_Gen4_Board)
      //Set_7040_IN1_P8_8_Duty(duty);
      //BTS7040_IN1_Set_Duty(duty);
      BTS7040_IN1_Set_PercentDuty(duty);
      #endif
}
#endif

#if defined(_CONFIG_Clutch) || defined(_CONFIG_ClutchHold)
/*********************************************************************************************
** Name:	  API_Clutch_PWMDuty_Update
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_Clutch_PWMDuty_Update(uint16_t duty)
{
      #ifdef _CONFIG_Gen1_Board
      //Set_ODH_2_CTN_Duty(duty);
      //BTS5030_IN1_Set_Duty(duty);
      BTS5030_IN1_Set_PercentDuty(duty);
      #endif
      #ifdef _CONFIG_Gen2_Board     
         #if defined(_CONFIG_Clutch_BTS_IN0) || defined(_CONFIG_ClutchHold_BTS_IN0)
      //Set_U6_IN0_U1_50_Duty(duty);
      //BTS7040_IN0_Set_Duty(duty);
      BTS7040_IN0_Set_PercentDuty(duty);
         #endif
         #if defined(_CONFIG_Clutch_BTS_IN1) || defined(_CONFIG_ClutchHold_BTS_IN1)
      //Set_U6_IN1_U1_49_Duty(duty);
      //BTS7040_IN1_Set_Duty(duty);
      BTS7040_IN1_Set_PercentDuty(duty);
         #endif
      #endif
      
      #if defined(_CONFIG_Gen3_Board) || defined(_CONFIG_Gen4_Board)
	 #if defined(_CONFIG_Clutch_BTS_IN0) || defined(_CONFIG_ClutchHold_BTS_IN0)
      //Set_7040_IN0_P8_9_Duty(duty);
      //BTS7040_IN0_Set_Duty(duty);
      BTS7040_IN0_Set_PercentDuty(duty);
         #endif
         #if defined(_CONFIG_Clutch_BTS_IN1) || defined(_CONFIG_ClutchHold_BTS_IN1)
      //Set_7040_IN1_P8_8_Duty(duty);
      //BTS7040_IN1_Set_Duty(duty);
      BTS7040_IN1_Set_PercentDuty(duty);
         #endif
      #endif
}
#endif

/*********************************************************************************************
** Name:	  API_Motor1_SoftStop_Trigger
** Function:	  To smoothly stop motor
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_Motor1_SoftStop_Trigger(void)
{

 
}

/*********************************************************************************************
** Name:	  API_Motor2_SoftStop_Trigger
** Function:	  To smoothly stop motor
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_Motor2_SoftStop_Trigger(void)
{

}

#ifdef  _CONFIG_IncreaseStepDuty
/*********************************************************************************************
** Name:	  API_IncreaseStepDuty_Control(uint16_t Duty_Request,uint16_t Duty_Target,uint16_t OnePercentPWM_Value,uint16_t IncreaseStep_Duty)
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
uint16_t API_IncreaseStepDuty_Control(uint16_t Duty_Request,uint16_t Duty_Target,uint16_t OnePercentPWM_Value,uint16_t IncreaseStep_Duty)
{
     uint16_t StepDuty_Request;
     uint16_t StepDuty_IncreaseStep_Duty;
     
     StepDuty_Request = Duty_Request;
     StepDuty_IncreaseStep_Duty = IncreaseStep_Duty;
     
     if(Duty_Target > (StepDuty_Request + (StepDuty_IncreaseStep_Duty * OnePercentPWM_Value)))
     {		
	   StepDuty_Request = StepDuty_Request + (StepDuty_IncreaseStep_Duty * OnePercentPWM_Value);	 
     }
     else
     {
	   StepDuty_Request = Duty_Target;
     }
     
     return (StepDuty_Request);
}
#endif
#ifdef _CONFIG_DecreaseStepDuty
/*********************************************************************************************
** Name:	  API_DecreaseStepDuty_Control(uint16_t Duty_Request,uint16_t Duty_Target,uint16_t OnePercentPWM_Value,uint16_t DecreaseStep_Duty)
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
uint16_t API_DecreaseStepDuty_Control(uint16_t Duty_Request,uint16_t Duty_Target,uint16_t OnePercentPWM_Value,uint16_t DecreaseStep_Duty)
{
     uint16_t StepDuty_Request;
     uint16_t StepDuty_DecreaseStep_Duty;
     
     StepDuty_Request = Duty_Request;
     StepDuty_DecreaseStep_Duty = DecreaseStep_Duty;
     
     if(StepDuty_Request > (StepDuty_DecreaseStep_Duty * OnePercentPWM_Value))
     {
           if(Duty_Target < (StepDuty_Request - (StepDuty_DecreaseStep_Duty * OnePercentPWM_Value)))
           {	
	         StepDuty_Request = StepDuty_Request - (StepDuty_DecreaseStep_Duty * OnePercentPWM_Value);	 
           }
	   else
	   {
		 StepDuty_Request = Duty_Target;
	   }
     }
     else
     {
	   StepDuty_Request = Duty_Target;
     }
     
     return (StepDuty_Request);
}
#endif

/*********************************************************************************************
** Name:	  API_ReferTo12Voltage_Duty
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
uint16_t API_ReferTo12Voltage_Duty(uint16_t vol_12v_duty)
{
      uint16_t ReferTo12Voltage_Duty;
      uint16_t CurrentVoltage;
      

      
      return (ReferTo12Voltage_Duty);
}

/*********************************************************************************************
** Name:	  API_ReferTo12Voltage_Current
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
uint16_t API_ReferTo12Voltage_Current(uint16_t vol_12v_current)
{
      uint16_t ReferTo12Voltage_Current;
      uint16_t CurrentVoltage;
      


      return (ReferTo12Voltage_Current);
}

/*********************************************************************************************
** Name:	  API_ReferTo12Voltage_Data
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
uint16_t API_ReferTo12Voltage_Data(uint16_t vol_12v_data)
{
      uint16_t ReferTo12Voltage_Data;
      uint16_t CurrentVoltage;
      

      
      return (ReferTo12Voltage_Data);
}

/*********************************************************************************************
** Name:	  API_ReferTo20Degree_Adder
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
int16_t API_ReferTo20Degree_Adder(int16_t temp_80_degree_data, int16_t temp_n40_degree_data)
{
      int16_t ReferTo20Degree_Adder;

      
      return (ReferTo20Degree_Adder);
}


#ifdef _CONFIG_CosSinDegree 
uint16_t Cos1000Times_List[91] = 
{ 1000,
  999,999,998,997,996,994,992,990,987,984,
  981,978,974,970,965,961,956,951,945,939,
  933,927,920,913,906,898,891,882,874,866,
  857,848,838,829,819,809,798,788,777,766,
  754,743,731,719,707,694,681,669,656,642,
  629,615,601,587,573,559,544,529,515,500,
  484,469,453,438,422,406,390,374,358,342,
  325,309,292,275,258,241,224,207,190,173,
  156,139,121,104,87,69,52,34,17,0};

uint16_t Sin1000Times_List[91] = 
{ 0,17,34,52,69,87,104,121,139,156,
  173,190,207,224,241,258,275,292,309,325,
  342,358,374,390,406,422,438,453,469,484,
  500,515,529,544,559,573,587,601,615,629,
  642,656,669,681,694,707,719,731,743,754,
  766,777,788,798,809,819,829,838,848,857,
  866,874,882,891,898,906,913,920,927,933,
  939,945,951,956,961,965,970,974,978,981,
  984,987,990,992,994,996,997,998,999,999,
  1000};
/*********************************************************************************************
** Name:	  API_Cos1000Times
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
uint16_t API_Cos1000Times(int16_t degree10times)
{
      uint8_t degree1time_number; 
      uint16_t degree1time_remainder;
      uint16_t cos1000times_degree_delta;
      uint16_t cos1000times;
       
      if((degree10times >= 0) && (degree10times < 900))
      {
	    degree1time_number = degree10times/K_Incline_Degree_Denominator;
            degree1time_remainder = degree10times%K_Incline_Degree_Denominator;
	    cos1000times_degree_delta = Cos1000Times_List[(degree1time_number)] - Cos1000Times_List[degree1time_number + 1]; 
	    cos1000times = Cos1000Times_List[degree1time_number + 1] 
	                 + ((K_Incline_Degree_Denominator - degree1time_remainder) * cos1000times_degree_delta)/K_Incline_Degree_Denominator;
      }
      else if(degree10times < 0)
      {
	    cos1000times = Cos1000Times_List[0];
      }
      else if(degree10times >= 900)
      {
	    cos1000times = Cos1000Times_List[90];
      }
      
      return cos1000times;

}
/*********************************************************************************************
** Name:	  API_Sin1000Times
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
uint16_t API_Sin1000Times(int16_t degree10times)
{
      uint8_t degree1time_number; 
      uint16_t degree1time_remainder;
      uint16_t sin1000times_degree_delta;
      uint16_t sin1000times;
       
      if((degree10times >= 0) && (degree10times < 900))
      {
	    degree1time_number = degree10times/K_Incline_Degree_Denominator;
            degree1time_remainder = degree10times%K_Incline_Degree_Denominator;
	    sin1000times_degree_delta = Sin1000Times_List[(degree1time_number + 1)] - Sin1000Times_List[degree1time_number]; 	    
	    sin1000times = Sin1000Times_List[degree1time_number] 
	                 + (degree1time_remainder * sin1000times_degree_delta)/K_Incline_Degree_Denominator;
      }
      else if(degree10times < 0)
      {
	    sin1000times = Sin1000Times_List[0];
      }
      else if(degree10times >= 900)
      {
	    sin1000times = Sin1000Times_List[90];
      }
      
      return sin1000times;

}
#endif
#ifdef _CONFIG_ArcSinDegree
/*********************************************************************************************
** Name:	  API_Sin1000Times
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
uint16_t API_ArcSinDegree10Times(int16_t sin1000times)
{
      uint8_t degree1time_number; 
      uint16_t degree10times_delta;
      uint16_t sin1000times_number_delta;
      uint16_t sin1000times_delta;
      uint16_t degree10times;
      uint8_t i;
	
      if((sin1000times >= 0) && (sin1000times < 1000))
      {
	     for(i=0;i<90;i++)
	     {
		   if((sin1000times >= Sin1000Times_List[i]) && (sin1000times < Sin1000Times_List[i + 1]))
		   {
			 degree1time_number = i;
			 sin1000times_delta = (sin1000times - Sin1000Times_List[i]);
			 sin1000times_number_delta = (Sin1000Times_List[i + 1] - Sin1000Times_List[i]);
			 degree10times_delta = (sin1000times_delta * K_Incline_Degree_Denominator)/sin1000times_number_delta;
			 degree10times = degree1time_number * K_Incline_Degree_Denominator + degree10times_delta;
			      
			 break;
		   }
	     }
      }
      else if(sin1000times < 0)
      {
	    degree10times = 0;
      }
      else if(sin1000times >= 1000)
      {
	    degree10times = 900;
      }
      
      return degree10times;
      
}
#endif






/*********************************************************************************************
** Name:	  API_ECU_Soft_Reset
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_ECU_Soft_Reset(void)
{
}

/*********************************************************************************************
** Name:	  API_CinchMotor_BrakeToGround
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_CinchMotor_BrakeToGround(void)
{
      #ifdef _CONFIG_Gen1_Board
      Set_CINCH_INA_Port_Low();
      Set_CINCH_INB_Port_Low();
      
      Set_CINCH_SEL0_Port_Low();
      Set_CINCH_SEL1_Port_Low();
      
      Set_CINCH_SEN_EN_Port_High();
      //Set_CINCH_PWM_PercentDuty(100);
      CinchMotor_Duty_Request = 100 * CinchMotor_OnePercentPWM_Value; 
      CinchMotor_Direction_Request = Direction_No;
      CinchMotor_BrakeToGround_Status = TRUE;
      #endif
      
      #ifdef _CONFIG_Gen2_Board
      DRV8702_U5_Active();
      DRV8702_U5_StandardPWM_Control();
      Set_U5_IN1_PH_U1_89_Duty(CinchMotor_Period);
      Set_U5_IN2_EN_U1_1_Duty(CinchMotor_Period);
      CinchMotor_Direction_Request = Direction_No;
      CinchMotor_BrakeToGround_Status = TRUE;
      #endif
      
      #ifdef _CONFIG_Gen3_Board
      DRV8705_U5_Active();
      DRV8705_U5_H_Bridge_PWM_Control();
      Set_M3_IN1_P11_1_Duty(CinchMotor_Period);
      Set_M3_IN2_P10_3_Duty(CinchMotor_Period);
      CinchMotor_Direction_Request = Direction_No;
      CinchMotor_BrakeToGround_Status = TRUE;
      #endif
      
      #ifdef _CONFIG_Gen4_Board
      //Sbc_Tle9562_FailFlag_Clear();
      Sbc_Tle9562_BMODE_SetCtrl(SBC_HB3,SBC_HBMODE_LS_ON,SBC_HB_AFW_DISABLE,SBC_HB_PWM_INACTIVE,
                                SBC_HB4,SBC_HBMODE_LS_ON,SBC_HB_AFW_DISABLE,SBC_HB_PWM_INACTIVE);
      CinchMotor_Direction_Request = Direction_No;
      CinchMotor_BrakeToGround_Status = TRUE;
      #endif
}

/*********************************************************************************************
** Name:	  API_CinchMotor_BrakeToBattery
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_CinchMotor_BrakeToBattery(void)
{
      #ifdef _CONFIG_Gen1_Board
      Set_CINCH_INA_Port_High();
      Set_CINCH_INB_Port_High();
      
      Set_CINCH_SEL0_Port_Low();
      Set_CINCH_SEL1_Port_Low();
      
      Set_CINCH_SEN_EN_Port_High();
      //Set_CINCH_PWM_PercentDuty(0);
      
      CinchMotor_Duty_Request = 0;
      CinchMotor_Direction_Request = Direction_No;
      CinchMotor_BrakeToBattery_Status = FALSE;
      #endif
         
      #ifdef _CONFIG_Gen2_Board
      DRV8702_U5_Active();
      DRV8702_U5_StandardPWM_Control();
      Set_U5_IN1_PH_U1_89_Duty(0);
      Set_U5_IN2_EN_U1_1_Duty(0);
      CinchMotor_Direction_Request = Direction_No;
      CinchMotor_BrakeToBattery_Status = FALSE;
      #endif
      
      #ifdef _CONFIG_Gen3_Board
      DRV8705_U5_Active();
      DRV8705_U5_H_Bridge_PWM_Control();
      Set_M3_IN1_P11_1_Duty(0);
      Set_M3_IN2_P10_3_Duty(0);
      CinchMotor_Direction_Request = Direction_No;
      CinchMotor_BrakeToBattery_Status = FALSE;
      #endif
      
      #ifdef _CONFIG_Gen4_Board
      //Sbc_Tle9562_FailFlag_Clear();
      Sbc_Tle9562_BMODE_SetCtrl(SBC_HB3,SBC_HBMODE_HS_ON,SBC_HB_AFW_DISABLE,SBC_HB_PWM_INACTIVE,
                                SBC_HB4,SBC_HBMODE_HS_ON,SBC_HB_AFW_DISABLE,SBC_HB_PWM_INACTIVE);
      CinchMotor_Direction_Request = Direction_No;
      CinchMotor_BrakeToBattery_Status = TRUE;
      #endif
}

/*********************************************************************************************
** Name:	  API_Motor1_BrakeToGround
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_Motor1_BrakeToGround(void)
{
    #ifdef _CONFIG_Gen1_Board
    BTN8962_Group1_Active();
    //Set_ODH_3_CTN_PercentDuty(0); 
    //Set_ODH_4_CTN_PercentDuty(0);    
    Motor1_Duty_Request = 0;
    Motor1_Direction_Request = Direction_No; 
    Motor1_BrakeToGround_Status = TRUE; 
    #endif
    
    #ifdef _CONFIG_Gen2_Board
    DRV8702_U3_Active();
    DRV8702_U3_StandardPWM_Control();
    Set_U3_IN1_PH_U1_85_Duty(Motor1_Period);
    Set_U3_IN2_EN_U1_86_Duty(Motor1_Period);
    
    Motor1_Duty_Request = 0;
    Motor1_Direction_Request = Direction_No; 
    Motor1_BrakeToGround_Status = TRUE; 
    #endif
    
    #ifdef _CONFIG_Gen3_Board
    DRV8705_U3_Active();
    DRV8705_U3_H_Bridge_PWM_Control();
    Set_M1_IN1_P10_11_Duty(Motor1_Period);
    Set_M1_IN2_P10_12_Duty(Motor1_Period);
    
    Motor1_Duty_Request = 0;
    Motor1_Direction_Request = Direction_No; 
    Motor1_BrakeToGround_Status = TRUE; 
    #endif
    
    #ifdef _CONFIG_Gen4_Board
    //Sbc_Tle9562_FailFlag_Clear();
    Sbc_Tle9562_BMODE_SetCtrl(SBC_HB1,SBC_HBMODE_LS_ON,SBC_HB_AFW_DISABLE,SBC_HB_PWM_INACTIVE,
                              SBC_HB2,SBC_HBMODE_LS_ON,SBC_HB_AFW_DISABLE,SBC_HB_PWM_INACTIVE);
    Motor1_Direction_Request = Direction_No; 
    Motor1_BrakeToGround_Status = TRUE; 
    #endif
}

/*********************************************************************************************
** Name:	  API_Motor1_BrakeToBattery
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_Motor1_BrakeToBattery(void)
{
      #ifdef _CONFIG_Gen1_Board
      BTN8962_Group1_Active();   
      Set_ODH_3_CTN_PercentDuty(Motor1_Period); 
      Set_ODH_4_CTN_PercentDuty(Motor1_Period);
      
      //Motor1_Duty_Request = 0;
      Motor1_Direction_Request = Direction_No;      
      Motor1_BrakeToBattery_Status = TRUE;
      #endif
      
      #ifdef _CONFIG_Gen2_Board
      DRV8702_U3_Active();
      DRV8702_U3_StandardPWM_Control();
      Set_U3_IN1_PH_U1_85_Duty(0);
      Set_U3_IN2_EN_U1_86_Duty(0);
      
      Motor1_Direction_Request = Direction_No;  
      Motor1_BrakeToBattery_Status = TRUE; 
      #endif
      
      #ifdef _CONFIG_Gen3_Board
      DRV8705_U3_Active();
      DRV8705_U3_H_Bridge_PWM_Control();
      Set_M1_IN1_P10_11_Duty(0);
      Set_M1_IN2_P10_12_Duty(0);
      
      Motor1_Direction_Request = Direction_No;  
      Motor1_BrakeToBattery_Status = TRUE; 
      #endif
      
      #ifdef _CONFIG_Gen4_Board
      //Sbc_Tle9562_FailFlag_Clear();
      Sbc_Tle9562_BMODE_SetCtrl(SBC_HB1,SBC_HBMODE_HS_ON,SBC_HB_AFW_DISABLE,SBC_HB_PWM_INACTIVE,
                                SBC_HB2,SBC_HBMODE_HS_ON,SBC_HB_AFW_DISABLE,SBC_HB_PWM_INACTIVE);
      Motor1_Direction_Request = Direction_No;  
      Motor1_BrakeToBattery_Status = TRUE; 
      #endif
}

/*********************************************************************************************
** Name:	  API_Motor2_BrakeToGround
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_Motor2_BrakeToGround(void)
{
    #ifdef _CONFIG_Gen1_Board
    BTN8962_Group2_Active();
    //Set_ODH_5_CTN_PercentDuty(0); 
    //Set_ODH_6_CTN_PercentDuty(0); 
    Motor2_Duty_Request = 0;
    Motor2_Direction_Request = Direction_No;    
    Motor2_BrakeToGround_Status = TRUE;
    #endif
    
    #ifdef _CONFIG_Gen2_Board
    DRV8702_U4_Active();
    DRV8702_U4_StandardPWM_Control();
    Set_U4_IN1_PH_U1_81_Duty(Motor2_Period);
    Set_U4_IN2_EN_U1_82_Duty(Motor2_Period);
    
    Motor2_Duty_Request = 0;
    Motor2_Direction_Request = Direction_No;    
    Motor2_BrakeToGround_Status = TRUE; 
    #endif
    
    #if defined(_CONFIG_Gen3_Board) || defined(_CONFIG_Gen4_Board)
    DRV8705_U4_Active();
    #ifndef _CONFIG_Gen4B_Board
    DRV8705_U4_H_Bridge_PWM_Control();
    Set_M2_IN1_P10_7_Duty(Motor2_Period);
    Set_M2_IN2_P10_8_Duty(Motor2_Period);
    #else
    #ifdef _CONFIG_MagnaSideLatch_CCL
    DRV8705_U4_Half_Bridge1_Control_On();
    DRV8705_U4_Half_Bridge2_Control_On();
    DRV8705_U6_Half_Bridge1_Control_Off();
    Set_M2_IN1_P10_7_Duty(0);
    Set_M2_IN2_P10_8_Duty(0);
    #endif
    #endif
    
    Motor2_Duty_Request = 0;
    Motor2_Direction_Request = Direction_No;    
    Motor2_BrakeToGround_Status = TRUE; 
    #endif
    
}

/*********************************************************************************************
** Name:	  API_Motor2_BrakeToBattery
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_Motor2_BrakeToBattery(void)
{
      #ifdef _CONFIG_Gen1_Board
      BTN8962_Group2_Active();    
      Set_ODH_5_CTN_PercentDuty(Motor2_Period); 
      Set_ODH_6_CTN_PercentDuty(Motor2_Period);
      
      //Motor2_Duty_Request = 0;
      Motor2_Direction_Request = Direction_No;
      Motor2_BrakeToBattery_Status = TRUE;
      #endif
      
     #ifdef _CONFIG_Gen2_Board
     DRV8702_U4_Active();
     DRV8702_U4_StandardPWM_Control();
     Set_U4_IN1_PH_U1_81_Duty(0);
     Set_U4_IN2_EN_U1_82_Duty(0);
     Motor2_Direction_Request = Direction_No;    
     Motor2_BrakeToBattery_Status = TRUE; 
     #endif
     
     #if defined(_CONFIG_Gen3_Board) || defined(_CONFIG_Gen4_Board)
     DRV8705_U4_Active();
     DRV8705_U4_H_Bridge_PWM_Control();
     Set_M2_IN1_P10_7_Duty(0);
     Set_M2_IN2_P10_8_Duty(0);
     Motor2_Direction_Request = Direction_No;    
     Motor2_BrakeToBattery_Status = TRUE; 
     #endif
    
}

#ifdef _CONFIG_Motor4
/*********************************************************************************************
** Name:	  API_Motor4_BrakeToGround
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_Motor4_BrakeToGround(void)
{
    
    #if defined(_CONFIG_Gen3_Board) || defined(_CONFIG_Gen4_Board)
    DRV8705_U6_Active();
    DRV8705_U6_H_Bridge_PWM_Control();
    Set_M4_IN1_P10_2_Duty(Motor4_Period);
    Set_M4_IN2_P10_1_Duty(Motor4_Period);
    
    Motor4_Duty_Request = 0;
    Motor4_Direction_Request = Direction_No;    
    Motor4_BrakeToGround_Status = TRUE; 
    #endif
    
}
/*********************************************************************************************
** Name:	  API_Motor4_BrakeToBattery
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_Motor4_BrakeToBattery(void)
{    
     #if defined(_CONFIG_Gen3_Board) || defined(_CONFIG_Gen4_Board)
     DRV8705_U6_Active();
     DRV8705_U6_H_Bridge_PWM_Control();
     Set_M4_IN1_P10_2_Duty(0);
     Set_M4_IN2_P10_1_Duty(0);
     Motor4_Direction_Request = Direction_No;    
     Motor4_BrakeToBattery_Status = TRUE; 
     #endif
    
}
#endif
#if defined(_CONFIG_Gen1_Board) || defined(_CONFIG_Gen2_Board)
/*********************************************************************************************
** Name:	  API_TurnOn_VBATT1_SW
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOn_VBATT1_SW(void)
{
     Sbc_Tle9263_Hsd_SetCtrl(SBC_HSD2,SBC_HSD_ON); 
     VBATT1_SW_Feed_Status = TRUE;
}

/*********************************************************************************************
** Name:	   API_TurnOff_VBATT1_SW
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOff_VBATT1_SW(void)
{
     Sbc_Tle9263_Hsd_SetCtrl(SBC_HSD2,SBC_HSD_OFF);
     VBATT1_SW_Feed_Status = FALSE;
}
#endif

#if defined(_CONFIG_Gen1_Board) || defined(_CONFIG_Gen2_Board) || defined(_CONFIG_Gen3_Board)
/*********************************************************************************************
** Name:	   API_TurnOn_VCC2_5V
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOn_VCC2_5V(void)
{
     Sbc_Tle9263_Ldo_SetVcc2(SBC_VCC2_ALWAYS_ON);
     VCC2_5V_Feed_Status = TRUE;
}

/*********************************************************************************************
** Name:	   API_TurnOff_VCC2_5V
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOff_VCC2_5V(void)
{
    Sbc_Tle9263_Ldo_SetVcc2(SBC_VCC2_OFF);
    VCC2_5V_Feed_Status = FALSE;
}


/*********************************************************************************************
** Name:	   API_TurnOn_VCC3_5V
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOn_VCC3_5V(void)
{
    Sbc_Tle9263_Ldo_SetVcc3(SBC_VCC3_ON);
    VCC3_5V_Feed_Status = TRUE;
}

/*********************************************************************************************
** Name:	   API_TurnOff_VCC3_5V
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOff_VCC3_5V(void)
{
    Sbc_Tle9263_Ldo_SetVcc3(SBC_VCC3_OFF);
    VCC3_5V_Feed_Status = FALSE;
}
#endif

/*********************************************************************************************
** Name:	   API_TurnOn_SBC_HS3
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOn_SBC_HS3(void)
{
    #ifdef _CONFIG_TLE9263
    Sbc_Tle9263_Hsd_SetCtrl(SBC_HSD1,SBC_HSD_ON); 
    #endif
    #ifdef _CONFIG_TLE9562
    Sbc_Tle9562_Hsd_SetCtrl(SBC_HSD1,SBC_HSD_ON); 
    #endif
    
    SBC_HS3_OUT_Output_Status = TRUE;
}

/*********************************************************************************************
** Name:	   API_TurnOff_SBC_HS3
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOff_SBC_HS3(void)
{
    #ifdef _CONFIG_TLE9263
    Sbc_Tle9263_Hsd_SetCtrl(SBC_HSD1,SBC_HSD_OFF);
    #endif
    #ifdef _CONFIG_TLE9562
    Sbc_Tle9562_Hsd_SetCtrl(SBC_HSD1,SBC_HSD_OFF); 
    #endif
     
    SBC_HS3_OUT_Output_Status = FALSE;
}

/*********************************************************************************************
** Name:	   API_TurnOn_SBC_HS4
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOn_SBC_HS4(void)
{
    #ifdef _CONFIG_TLE9263
    Sbc_Tle9263_Hsd_SetCtrl(SBC_HSD4,SBC_HSD_ON); 
    #endif
    #ifdef _CONFIG_TLE9562
    Sbc_Tle9562_Hsd_SetCtrl(SBC_HSD4,SBC_HSD_ON);
    #endif
    
    HS4_Output_Status = TRUE;
    #ifdef _CONFIG_Buzzer_SBC_HS4
    if((TRUE == Speaker_Working_Status)
       #ifdef _CONFIG_Flasher
       || (TRUE == Flasher_Working_Status)
       #endif
       )
    {
	#ifdef _CONFIG_TLE9263
        Sbc_Tle9263_Wdg_SetTrigger();
        #endif
        #ifdef _CONFIG_TLE9562
        Sbc_Tle9562_Wdg_SetTrigger();
        #endif       
    }
    #endif
    
    
}

/*********************************************************************************************
** Name:	   API_TurnOff_SBC_HS4
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOff_SBC_HS4(void)
{
    //Time_Test1 = OSTM0.CNT;
    #ifdef _CONFIG_TLE9263
    Sbc_Tle9263_Hsd_SetCtrl(SBC_HSD4,SBC_HSD_OFF); 
    #endif
    #ifdef _CONFIG_TLE9562
    Sbc_Tle9562_Hsd_SetCtrl(SBC_HSD4,SBC_HSD_OFF);
    #endif   
      
    #ifdef _CONFIG_Buzzer_SBC_HS4
    if((TRUE == Speaker_Working_Status)
      #ifdef _CONFIG_Flasher
       || (FALSE == Flasher_Working_Status)
       #endif
       )
    {
        #ifdef _CONFIG_TLE9263
        Sbc_Tle9263_Wdg_SetTrigger();
        #endif
        #ifdef _CONFIG_TLE9562
        Sbc_Tle9562_Wdg_SetTrigger();
        #endif 
    }
    #endif
    //Time_Test2 = OSTM0.CNT;
    HS4_Output_Status = FALSE;
}

/*********************************************************************************************
** Name:	   API_TurnOn_SBC_HS4_PWM1
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOn_SBC_HS4_PWM1(void)
{
    #ifdef _CONFIG_TLE9263
    Sbc_Tle9263_Hsd_SetCtrl(SBC_HSD4,SBC_HSD_CTRL_BY_PWM1);
    Sbc_Tle9263_Hsd_SetDuty(SBC_HSD_PWM1,16384); /*50%*/ 
    #endif
    #ifdef _CONFIG_TLE9562
    Sbc_Tle9562_Hsd_SetCtrl(SBC_HSD4,SBC_HSD_CTRL_BY_PWM1);
    Sbc_Tle9562_Hsd_SetDuty(SBC_HSD_PWM1,16384); /*50%*/
    #endif

    HS4_Output_Status = TRUE;
}


/*********************************************************************************************
** Name:	  API_TurnOn_Diag_Power
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOn_Diag_Power(void)
{
    #ifdef _CONFIG_Gen2_Board
    Set_Load_Diag_EN_Port_High();
    #endif
    #if defined(_CONFIG_Gen3_Board) || defined(_CONFIG_Gen4_Board)
    Set_Diag_5V_EN_P11_5_Port_Low();
    #endif
}
/*********************************************************************************************
** Name:	  API_TurnOff_Diag_Power
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOff_Diag_Power(void)
{
    #ifdef _CONFIG_Gen2_Board
    Set_Load_Diag_EN_Port_Low();
    #endif
    #if defined(_CONFIG_Gen3_Board) || defined(_CONFIG_Gen4_Board)
    Set_Diag_5V_EN_P11_5_Port_High();
    #endif
}

/*********************************************************************************************
** Name:	   API_TurnOn_Batt_AD_EN
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOn_Batt_AD_EN(void)
{
     #ifdef _CONFIG_Gen1_Board
     Set_VBATT_EN_Port_High(); 
     #endif
     
     #ifdef _CONFIG_Gen2_Board
     Set_Batt_AD_EN_Port_High();
     #endif
     
     #ifdef _CONFIG_Gen3_Board
     Set_Batt_AD_EN_P9_6_Port_High();
     #endif

     #ifdef _CONFIG_Gen4_Board_003_004
     Set_Batt_AD_EN_P0_8_Port_High();
     #endif
}

/*********************************************************************************************
** Name:	   API_TurnOff_Batt_AD_EN 
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOff_Batt_AD_EN(void)
{
      #ifdef _CONFIG_Gen1_Board
      Set_VBATT_EN_Port_Low();
      #endif
      
      #ifdef _CONFIG_Gen2_Board
      Set_Batt_AD_EN_Port_Low();
      #endif
      
      #ifdef _CONFIG_Gen3_Board
      Set_Batt_AD_EN_P9_6_Port_Low();
      #endif
      
      #ifdef _CONFIG_Gen4_Board_003_004
      Set_Batt_AD_EN_P0_8_Port_Low();
      #endif
}

#if defined(_CONFIG_Gen1_Board) || defined(_CONFIG_Gen2_Board)
/*********************************************************************************************
** Name:	  API_TurnOn_HallPower
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOn_HallPower(void)
{
     Sbc_Tle9263_Hsd_SetCtrl(SBC_HSD3,SBC_HSD_ON);
     HallPower_Status = TRUE;
     
}

/*********************************************************************************************
** Name:	  API_TurnOff_HallPower
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOff_HallPower(void)
{    
     Sbc_Tle9263_Hsd_SetCtrl(SBC_HSD3,SBC_HSD_OFF);
     HallPower_Status = FALSE;
}
#endif

#if defined(_CONFIG_Gen3_Board) || defined(_CONFIG_Gen4_Board)
#ifndef _CONFIG_Gen4_Board_003_004
/*********************************************************************************************
** Name:	  API_TurnOn_LoadPower_EN
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOn_LoadPower_EN(void)
{
     Set_LoadPower_EN_P0_8_Port_High();
}
/*********************************************************************************************
** Name:	  API_TurnOff_LoadPower_EN
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOff_LoadPower_EN(void)
{
     Set_LoadPower_EN_P0_8_Port_Low();
}
#endif
/*********************************************************************************************
** Name:	  API_TurnOn_LatchSwitchPower
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOn_LatchSwitchPower(void)
{
     #ifdef _CONFIG_TLE9263
     Sbc_Tle9263_Hsd_SetCtrl(SBC_HSD2,SBC_HSD_ON); 
     #endif
     #ifdef _CONFIG_TLE9562
     Sbc_Tle9562_Hsd_SetCtrl(SBC_HSD2,SBC_HSD_ON);
     #endif
    
     LatchSwitchPower_Status = TRUE;
}
/*********************************************************************************************
** Name:	  API_TurnOff_LatchSwitchPower
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOff_LatchSwitchPower(void)
{
     #ifdef _CONFIG_TLE9263
     Sbc_Tle9263_Hsd_SetCtrl(SBC_HSD2,SBC_HSD_OFF);
     #endif
     #ifdef _CONFIG_TLE9562
     Sbc_Tle9562_Hsd_SetCtrl(SBC_HSD2,SBC_HSD_OFF);
     #endif
     
     LatchSwitchPower_Status = FALSE;
}
/*********************************************************************************************
** Name:	  API_TurnOn_HallPower1
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOn_HallPower1(void)
{
     if((FALSE == HallPower1_Status)
         #ifdef _CONFIG_HallPower1_DIA
         || (TRUE == HallPower1_DIA_Status) 
         #else
         || (HallPower1_Voltage < K_04V_ATD)
         #endif
        )
       {
	   #ifdef _CONFIG_TLE9263
           Sbc_Tle9263_Hsd_SetCtrl(SBC_HSD3,SBC_HSD_ON);
           #endif
           #ifdef _CONFIG_TLE9562
           Sbc_Tle9562_Hsd_SetCtrl(SBC_HSD3,SBC_HSD_ON);
           #endif 
          
           HallPower1_Status = TRUE;
       } 
}
/*********************************************************************************************
** Name:	  API_TurnOff_HallPower1
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOff_HallPower1(void)
{
     #ifdef _CONFIG_TLE9263
     Sbc_Tle9263_Hsd_SetCtrl(SBC_HSD3,SBC_HSD_OFF);
     #endif
     #ifdef _CONFIG_TLE9562
     Sbc_Tle9562_Hsd_SetCtrl(SBC_HSD3,SBC_HSD_OFF);
     #endif
     
     HallPower1_Status = FALSE;
}
/*********************************************************************************************
** Name:	  API_TurnOn_HallPower2
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOn_HallPower2(void)
{
     if((FALSE == HallPower2_Status)
        #ifdef _CONFIG_HallPower2_DIA
        || (TRUE == HallPower2_DIA_Status) 
        #else
        || (HallPower2_Voltage < K_04V_ATD)
        #endif
        )
     {
	   #ifdef _CONFIG_TLE9263
           Sbc_Tle9263_Hsd_SetCtrl(SBC_HSD1,SBC_HSD_ON);
           #endif
           #ifdef _CONFIG_TLE9562
           Sbc_Tle9562_Hsd_SetCtrl(SBC_HSD1,SBC_HSD_ON);
           #endif
           
           HallPower2_Status = TRUE;
     }
}
/*********************************************************************************************
** Name:	  API_TurnOff_HallPower2
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOff_HallPower2(void)
{
     #ifdef _CONFIG_TLE9263
     Sbc_Tle9263_Hsd_SetCtrl(SBC_HSD1,SBC_HSD_OFF);
     #endif
     #ifdef _CONFIG_TLE9562
     Sbc_Tle9562_Hsd_SetCtrl(SBC_HSD1,SBC_HSD_OFF);
     #endif
     
     HallPower2_Status = FALSE;
}

#ifdef _CONFIG_HallC
/*********************************************************************************************
** Name:	  API_TurnOn_HallPower3
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOn_HallPower3(void)
{
     if(FALSE == HallPower3_Status)
     {
	   API_TurnOn_SBC_HS4();  
	   HallPower3_Status = TRUE;
     }
}
/*********************************************************************************************
** Name:	  API_TurnOff_HallPower3
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOff_HallPower3(void)
{
     if(TRUE == HallPower3_Status)
     {
	   API_TurnOff_SBC_HS4(); 
	   HallPower3_Status = FALSE;
     }
}
#endif
#endif

/*********************************************************************************************
** Name:	  API_TurnOff_Motor1
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOff_Motor1(void)
{
    #ifdef _CONFIG_Gen1_Board
    BTN8962_Group1_Inactive();    
    //Set_ODH_3_CTN_PercentDuty(0); 
    //Set_ODH_4_CTN_PercentDuty(0); 
    Motor1_Duty_Request = 0;
    Motor1_Working_Status = FALSE;
    Motor1_Direction_Request = Direction_No;
    
    Motor1_BrakeToGround_Status = FALSE;
    Motor1_BrakeToBattery_Status = FALSE;
    #endif
    
    #ifdef _CONFIG_Gen2_Board
    DRV8702_U3_Inactive();
    DRV8702_U3_StandardPWM_Control();
    Set_U3_IN1_PH_U1_85_Duty(0);
    Set_U3_IN2_EN_U1_86_Duty(0);

    Motor1_Duty_Request = 0;
    Motor1_Working_Status = FALSE;
    Motor1_Direction_Request = Direction_No;
    
    Motor1_BrakeToGround_Status = FALSE;
    Motor1_BrakeToBattery_Status = FALSE;
    #endif
    
    #ifdef _CONFIG_Gen3_Board
    DRV8705_U3_Inactive();
    DRV8705_U3_H_Bridge_PWM_Control();
    Set_M1_IN1_P10_11_Duty(0);
    Set_M1_IN2_P10_12_Duty(0);

    Motor1_Duty_Request = 0;
    Motor1_Working_Status = FALSE;
    Motor1_Direction_Request = Direction_No;
    
    Motor1_BrakeToGround_Status = FALSE;
    Motor1_BrakeToBattery_Status = FALSE;
    #endif
    
    #ifdef _CONFIG_Gen4_Board
    Sbc_Tle9562_BMODE_SetCtrl(SBC_HB1,SBC_HBMODE_PASSIVE_OFF,SBC_HB_AFW_DISABLE,SBC_HB_PWM_INACTIVE,
                              SBC_HB2,SBC_HBMODE_PASSIVE_OFF,SBC_HB_AFW_DISABLE,SBC_HB_PWM_INACTIVE);

    Motor1_Duty_Request = 0;
    Motor1_Working_Status = FALSE;
    Motor1_Direction_Request = Direction_No;
    
    Motor1_BrakeToGround_Status = FALSE;
    Motor1_BrakeToBattery_Status = FALSE;
    #endif
}

/*********************************************************************************************
** Name:	  API_TurnOff_Motor2
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOff_Motor2(void)
{
    #ifdef _CONFIG_Gen1_Board
    BTN8962_Group2_Inactive(); 
    //Set_ODH_5_CTN_PercentDuty(0); 
    //Set_ODH_6_CTN_PercentDuty(0); 
        
    Motor2_Duty_Request = 0;
    Motor2_Working_Status = FALSE;
    Motor2_Direction_Request = Direction_No;
    
    Motor2_BrakeToGround_Status = FALSE;
    Motor2_BrakeToBattery_Status = FALSE;
    #endif
    
    #ifdef _CONFIG_Gen2_Board
    DRV8702_U4_Inactive();
    DRV8702_U4_StandardPWM_Control();
    Set_U4_IN1_PH_U1_81_Duty(0);
    Set_U4_IN2_EN_U1_82_Duty(0);

    Motor2_Duty_Request = 0;
    Motor2_Working_Status = FALSE;
    Motor2_Direction_Request = Direction_No;
    
    Motor2_BrakeToGround_Status = FALSE;
    Motor2_BrakeToBattery_Status = FALSE;
    #endif
    
    #if defined(_CONFIG_Gen3_Board) || defined(_CONFIG_Gen4_Board)
    DRV8705_U4_Inactive();
    DRV8705_U4_H_Bridge_PWM_Control();
    Set_M2_IN1_P10_7_Duty(0);
    Set_M2_IN2_P10_8_Duty(0);

    Motor2_Duty_Request = 0;
    Motor2_Working_Status = FALSE;
    Motor2_Direction_Request = Direction_No;
    
    Motor2_BrakeToGround_Status = FALSE;
    Motor2_BrakeToBattery_Status = FALSE;
    #endif
}

#ifdef _CONFIG_Motor4
/*********************************************************************************************
** Name:	  API_TurnOff_Motor4
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOff_Motor4(void)
{ 
    #if defined(_CONFIG_Gen3_Board) || defined(_CONFIG_Gen4_Board)
    DRV8705_U6_Inactive();
    DRV8705_U6_H_Bridge_PWM_Control();
    Set_M4_IN1_P10_2_Duty(0);
    Set_M4_IN2_P10_1_Duty(0);

    Motor4_Duty_Request = 0;
    Motor4_Working_Status = FALSE;
    Motor4_Direction_Request = Direction_No;
    
    Motor4_BrakeToGround_Status = FALSE;
    Motor4_BrakeToBattery_Status = FALSE;
    #endif
}
#endif
/*********************************************************************************************
** Name:	  API_TurnOn_Motor1_Open
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOn_Motor1_Open(void)
{
     #ifdef _CONFIG_Gen1_Board
     BTN8962_Group1_Active();
     Motor1_Direction_Request = Direction_Open;
     Motor1_Working_Status = TRUE;     
     #endif
     
     #ifdef _CONFIG_Gen2_Board
     DRV8702_U3_Active();
     DRV8702_U3_StandardPWM_Control();
     Motor1_Direction_Request = Direction_Open;
     Motor1_Working_Status = TRUE;     
     #endif
     
     #ifdef _CONFIG_Gen3_Board
     DRV8705_U3_Active();
     DRV8705_U3_H_Bridge_PWM_Control();
     Motor1_Direction_Request = Direction_Open;
     Motor1_Working_Status = TRUE;     
     #endif
     
     #ifdef _CONFIG_Gen4_Board   
     Sbc_Tle9562_FailFlag_Clear();
     
         #ifdef _CONFIG_Motor1_Direction_From_2_To_1  /*X1_11 to X1_4*/
     Sbc_Tle9562_GenCtrl_SetCtrl(SBC_CPEN_ENABLE,SBC_PWM1,SBC_PWM1_TO_HB2);
     Sbc_Tle9562_BMODE_SetCtrl(SBC_HB1,SBC_HBMODE_LS_ON,SBC_HB_AFW_DISABLE,SBC_HB_PWM_INACTIVE,
                               SBC_HB2,SBC_HBMODE_HS_ON,SBC_HB_AFW_ENABLE,SBC_HB_PWM_ACTIVE);
	 #else  /*X1_4 to X1_11*/
     Sbc_Tle9562_GenCtrl_SetCtrl(SBC_CPEN_ENABLE,SBC_PWM1,SBC_PWM1_TO_HB1);
     Sbc_Tle9562_BMODE_SetCtrl(SBC_HB1,SBC_HBMODE_HS_ON,SBC_HB_AFW_ENABLE,SBC_HB_PWM_ACTIVE,
                               SBC_HB2,SBC_HBMODE_LS_ON,SBC_HB_AFW_DISABLE,SBC_HB_PWM_INACTIVE);
         #endif
     Motor1_Direction_Request = Direction_Open;
     Motor1_Working_Status = TRUE;  
     #endif
}

/*********************************************************************************************
** Name:	  API_TurnOn_Motor2_Open
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOn_Motor2_Open(void)
{
     #ifdef _CONFIG_Gen1_Board
     BTN8962_Group2_Active();   
     Motor2_Direction_Request = Direction_Open;
     Motor2_Working_Status = TRUE;
     #endif
     
     #ifdef _CONFIG_Gen2_Board
     DRV8702_U4_Active();  
     DRV8702_U4_StandardPWM_Control();
     Motor2_Direction_Request = Direction_Open;
     Motor2_Working_Status = TRUE;
     #endif
     
     #if defined(_CONFIG_Gen3_Board) || defined(_CONFIG_Gen4_Board)
     #ifndef _CONFIG_Gen4B_Board
     DRV8705_U4_Active();  
     DRV8705_U4_H_Bridge_PWM_Control();
     Motor2_Direction_Request = Direction_Open;
     #else
     #ifdef _CONFIG_MagnaSideLatch_CCL
     DRV8705_U4_Active();  
     DRV8705_U4_Half_Bridge1_Control_On();
     DRV8705_U4_Half_Bridge2_Control_On();
     DRV8705_U6_Half_Bridge1_Control_Off();
     Motor2_Direction_Request = Direction_Release;
     #endif
     #endif
     Motor2_Working_Status = TRUE;
     #endif
}

#ifdef _CONFIG_Motor4
/*********************************************************************************************
** Name:	  API_TurnOn_Motor4_Open
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOn_Motor4_Open(void)
{ 
     #if defined(_CONFIG_Gen3_Board) || defined(_CONFIG_Gen4_Board)
     DRV8705_U6_Active();  
     DRV8705_U6_H_Bridge_PWM_Control();
     Motor4_Direction_Request = Direction_Open;
     Motor4_Working_Status = TRUE;
     #endif
}
#endif
/*********************************************************************************************
** Name:	  API_TurnOn_Motor1_Close
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOn_Motor1_Close(void)
{
     #ifdef _CONFIG_Gen1_Board
     BTN8962_Group1_Active();     
     Motor1_Direction_Request = Direction_Close;
     Motor1_Working_Status = TRUE;
     #endif
     
     #ifdef _CONFIG_Gen2_Board
     DRV8702_U3_Active(); 
     DRV8702_U3_StandardPWM_Control();
     Motor1_Direction_Request = Direction_Close;
     Motor1_Working_Status = TRUE;
     #endif
     
     #ifdef _CONFIG_Gen3_Board
     DRV8705_U3_Active(); 
     DRV8705_U3_H_Bridge_PWM_Control();
     Motor1_Direction_Request = Direction_Close;
     Motor1_Working_Status = TRUE;
     #endif
     
     #ifdef _CONFIG_Gen4_Board
     Sbc_Tle9562_FailFlag_Clear();
     
         #ifdef _CONFIG_Motor1_Direction_From_2_To_1   /*X1_4 to X1_11*/
     Sbc_Tle9562_GenCtrl_SetCtrl(SBC_CPEN_ENABLE,SBC_PWM1,SBC_PWM1_TO_HB1);
     Sbc_Tle9562_BMODE_SetCtrl(SBC_HB1,SBC_HBMODE_HS_ON,SBC_HB_AFW_ENABLE,SBC_HB_PWM_ACTIVE,
                               SBC_HB2,SBC_HBMODE_LS_ON,SBC_HB_AFW_DISABLE,SBC_HB_PWM_INACTIVE);
	 #else   /*X1_11 to X1_4*/
     Sbc_Tle9562_GenCtrl_SetCtrl(SBC_CPEN_ENABLE,SBC_PWM1,SBC_PWM1_TO_HB2);
     Sbc_Tle9562_BMODE_SetCtrl(SBC_HB1,SBC_HBMODE_LS_ON,SBC_HB_AFW_DISABLE,SBC_HB_PWM_INACTIVE,
                               SBC_HB2,SBC_HBMODE_HS_ON,SBC_HB_AFW_ENABLE,SBC_HB_PWM_ACTIVE);
         #endif
     Motor1_Direction_Request = Direction_Close;
     Motor1_Working_Status = TRUE;  
     #endif
       
}

/*********************************************************************************************
** Name:	  API_TurnOn_Motor2_Close
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOn_Motor2_Close(void)
{
     #ifdef _CONFIG_Gen1_Board
     BTN8962_Group2_Active();
     Motor2_Direction_Request = Direction_Close;
     Motor2_Working_Status = TRUE;
     #endif
     
     #ifdef _CONFIG_Gen2_Board
     DRV8702_U4_Active();
     DRV8702_U4_StandardPWM_Control();
     Motor2_Direction_Request = Direction_Close;
     Motor2_Working_Status = TRUE;
     #endif
     
     #if defined(_CONFIG_Gen3_Board) || defined(_CONFIG_Gen4_Board)
     #ifndef _CONFIG_Gen4B_Board
     DRV8705_U4_Active();
     DRV8705_U4_H_Bridge_PWM_Control();
     Motor2_Direction_Request = Direction_Close;
     #else
     #ifdef _CONFIG_MagnaSideLatch_CCL
     DRV8705_U4_Active();  
     DRV8705_U4_Half_Bridge1_Control_On();
     DRV8705_U4_Half_Bridge2_Control_On();
     DRV8705_U6_Half_Bridge1_Control_Off();
     Motor2_Direction_Request = Direction_Unlock;
     #endif
     #endif
     Motor2_Working_Status = TRUE;
     #endif
}

#ifdef _CONFIG_Motor4
/*********************************************************************************************
** Name:	  API_TurnOn_Motor4_Close
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOn_Motor4_Close(void)
{    
     #if defined(_CONFIG_Gen3_Board) || defined(_CONFIG_Gen4_Board)
     DRV8705_U6_Active();
     DRV8705_U6_H_Bridge_PWM_Control();
     Motor4_Direction_Request = Direction_Close;
     Motor4_Working_Status = TRUE;
     #endif
}
#endif

#ifdef _CONFIG_MagnaSideLatch_CCL
/*********************************************************************************************
** Name:	  API_TurnOn_Motor2_PRReset
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOn_Motor2_PRReset(void)
{
     DRV8705_U4_Active();
     DRV8705_U6_Half_Bridge1_Control_On();
     DRV8705_U4_Half_Bridge1_Control_On();
     DRV8705_U4_Half_Bridge2_Control_Off();
     Motor2_Direction_Request = Direction_Neutral;
     Motor2_Working_Status = TRUE;
}
#endif

/*********************************************************************************************
** Name:	  API_TurnOff_CinchMotor
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOff_CinchMotor(void)
{
      #ifdef _CONFIG_Gen1_Board
      Set_CINCH_INA_Port_Low();
      Set_CINCH_INB_Port_Low();
      
      Set_CINCH_SEL0_Port_Low();
      Set_CINCH_SEL1_Port_Low();
      
      Set_CINCH_SEN_EN_Port_Low();
      //Set_CINCH_PWM_PercentDuty(0);
      
      CinchMotor_Duty_Request = 0;      
      CinchMotor_Direction_Request = Direction_No;
      CinchMotor_Working_Status = FALSE;
      
      CinchMotor_BrakeToGround_Status = FALSE;
      CinchMotor_BrakeToBattery_Status = FALSE;
      #endif
      
      #ifdef _CONFIG_Gen2_Board
      DRV8702_U5_Inactive();
      DRV8702_U5_StandardPWM_Control();
      Set_U5_IN1_PH_U1_89_Duty(0);
      Set_U5_IN2_EN_U1_1_Duty(0);

      CinchMotor_Duty_Request = 0;      
      CinchMotor_Direction_Request = Direction_No;
      CinchMotor_Working_Status = FALSE;
      
      CinchMotor_BrakeToGround_Status = FALSE;
      CinchMotor_BrakeToBattery_Status = FALSE;
      #endif
      
      #ifdef _CONFIG_Gen3_Board
      DRV8705_U5_Inactive();
      DRV8705_U5_H_Bridge_PWM_Control();
      Set_M3_IN1_P11_1_Duty(0);
      Set_M3_IN2_P10_3_Duty(0);

      CinchMotor_Duty_Request = 0;      
      CinchMotor_Direction_Request = Direction_No;
      CinchMotor_Working_Status = FALSE;
      
      CinchMotor_BrakeToGround_Status = FALSE;
      CinchMotor_BrakeToBattery_Status = FALSE;
      #endif
      
      #ifdef _CONFIG_Gen4_Board
      Sbc_Tle9562_BMODE_SetCtrl(SBC_HB3,SBC_HBMODE_PASSIVE_OFF,SBC_HB_AFW_DISABLE,SBC_HB_PWM_INACTIVE,
                                SBC_HB4,SBC_HBMODE_PASSIVE_OFF,SBC_HB_AFW_DISABLE,SBC_HB_PWM_INACTIVE);

      CinchMotor_Duty_Request = 0;
      CinchMotor_Direction_Request = Direction_No;
      CinchMotor_Working_Status = FALSE;      
    
      CinchMotor_BrakeToGround_Status = FALSE;
      CinchMotor_BrakeToBattery_Status = FALSE;
      #endif
      
      
}



/*********************************************************************************************
** Name:	  API_TurnOn_CinchMotor_Cinch
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOn_CinchMotor_Cinch(void)
{
      #ifdef _CONFIG_Gen1_Board
      Set_CINCH_INA_Port_High();
      Set_CINCH_INB_Port_Low();
      
      Set_CINCH_SEL0_Port_High();
      Set_CINCH_SEL1_Port_Low();
      
      Set_CINCH_SEN_EN_Port_High(); 
            
      CinchMotor_Direction_Request = Direction_Cinch;
      CinchMotor_Working_Status = TRUE;
      #endif
      
      #ifdef _CONFIG_Gen2_Board
      DRV8702_U5_Active();
      DRV8702_U5_StandardPWM_Control();
      CinchMotor_Direction_Request = Direction_Cinch;
      CinchMotor_Working_Status = TRUE;
      #endif
      
      #ifdef _CONFIG_Gen3_Board
      DRV8705_U5_Active();
      DRV8705_U5_H_Bridge_PWM_Control();
      CinchMotor_Direction_Request = Direction_Cinch;
      CinchMotor_Working_Status = TRUE;
      #endif
      
      #ifdef _CONFIG_Gen4_Board
      Sbc_Tle9562_FailFlag_Clear();
      
        #ifdef _CONFIG_CalibrationFile_T1X
	    #ifdef _CONFIG_LatchControl_Together
	 if(CurrentLatchType == LatchType_InginLatch)
	 {
	      Sbc_Tle9562_GenCtrl_SetCtrl(SBC_CPEN_ENABLE,SBC_PWM3,SBC_PWM3_TO_HB3); /*X1_12 to X1_5*/
	      Sbc_Tle9562_BMODE_SetCtrl(SBC_HB3,SBC_HBMODE_HS_ON,SBC_HB_AFW_ENABLE,SBC_HB_PWM_ACTIVE,
	                          SBC_HB4,SBC_HBMODE_LS_ON,SBC_HB_AFW_DISABLE,SBC_HB_PWM_INACTIVE);
	 }
	 else if(CurrentLatchType == LatchType_HuffLatch)
	 {
	      Sbc_Tle9562_GenCtrl_SetCtrl(SBC_CPEN_ENABLE,SBC_PWM3,SBC_PWM3_TO_HB4);  /*X1_5 to X1_12*/
              Sbc_Tle9562_BMODE_SetCtrl(SBC_HB3,SBC_HBMODE_LS_ON,SBC_HB_AFW_DISABLE,SBC_HB_PWM_INACTIVE,
                                        SBC_HB4,SBC_HBMODE_HS_ON,SBC_HB_AFW_ENABLE,SBC_HB_PWM_ACTIVE); 
	 }
	 else if(CurrentLatchType == LatchType_Default)
	 {
	      Sbc_Tle9562_GenCtrl_SetCtrl(SBC_CPEN_ENABLE,SBC_PWM3,SBC_PWM3_TO_HB4);  /*X1_5 to X1_12*/
              Sbc_Tle9562_BMODE_SetCtrl(SBC_HB3,SBC_HBMODE_LS_ON,SBC_HB_AFW_DISABLE,SBC_HB_PWM_INACTIVE,
                                        SBC_HB4,SBC_HBMODE_HS_ON,SBC_HB_AFW_ENABLE,SBC_HB_PWM_ACTIVE); 
	 }
	    #endif
        #else
            #ifdef _CONFIG_CinchMotor_Direction_From_2_To_1  
        Sbc_Tle9562_GenCtrl_SetCtrl(SBC_CPEN_ENABLE,SBC_PWM3,SBC_PWM3_TO_HB3); /*X1_12 to X1_5*/
	Sbc_Tle9562_BMODE_SetCtrl(SBC_HB3,SBC_HBMODE_HS_ON,SBC_HB_AFW_ENABLE,SBC_HB_PWM_ACTIVE,
	                          SBC_HB4,SBC_HBMODE_LS_ON,SBC_HB_AFW_DISABLE,SBC_HB_PWM_INACTIVE);
	    #else 
        Sbc_Tle9562_GenCtrl_SetCtrl(SBC_CPEN_ENABLE,SBC_PWM3,SBC_PWM3_TO_HB4);  /*X1_5 to X1_12*/
        Sbc_Tle9562_BMODE_SetCtrl(SBC_HB3,SBC_HBMODE_LS_ON,SBC_HB_AFW_DISABLE,SBC_HB_PWM_INACTIVE,
                                  SBC_HB4,SBC_HBMODE_HS_ON,SBC_HB_AFW_ENABLE,SBC_HB_PWM_ACTIVE);
            #endif
	#endif    
        CinchMotor_Direction_Request = Direction_Cinch;
        CinchMotor_Working_Status = TRUE;       
      #endif
}

/*********************************************************************************************
** Name:	  API_TurnOn_CinchMotor_Neutral
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOn_CinchMotor_Neutral(void)
{
      #ifdef _CONFIG_Gen1_Board
      Set_CINCH_INA_Port_Low();
      Set_CINCH_INB_Port_High();
      
      Set_CINCH_SEL0_Port_Low();
      Set_CINCH_SEL1_Port_Low();
      
      Set_CINCH_SEN_EN_Port_High(); 
      
      CinchMotor_Direction_Request = Direction_Neutral;
      CinchMotor_Working_Status = TRUE;
      #endif

      #ifdef _CONFIG_Gen2_Board
      DRV8702_U5_Active();
      DRV8702_U5_StandardPWM_Control();
      CinchMotor_Direction_Request = Direction_Neutral;
      CinchMotor_Working_Status = TRUE;
      #endif
      
      #ifdef _CONFIG_Gen3_Board
      DRV8705_U5_Active();
      DRV8705_U5_H_Bridge_PWM_Control();
      CinchMotor_Direction_Request = Direction_Neutral;
      CinchMotor_Working_Status = TRUE;
      #endif
      
      #ifdef _CONFIG_Gen4_Board
      Sbc_Tle9562_FailFlag_Clear();
      
        #ifdef _CONFIG_CalibrationFile_T1X
	     #ifdef _CONFIG_LatchControl_Together
	 if(CurrentLatchType == LatchType_InginLatch)
	 {
	      Sbc_Tle9562_GenCtrl_SetCtrl(SBC_CPEN_ENABLE,SBC_PWM3,SBC_PWM3_TO_HB4);  /*X1_5 to X1_12*/ 
              Sbc_Tle9562_BMODE_SetCtrl(SBC_HB3,SBC_HBMODE_LS_ON,SBC_HB_AFW_DISABLE,SBC_HB_PWM_INACTIVE,
                                        SBC_HB4,SBC_HBMODE_HS_ON,SBC_HB_AFW_ENABLE,SBC_HB_PWM_ACTIVE);
	 }
	 else if(CurrentLatchType == LatchType_HuffLatch)
	 {
	      Sbc_Tle9562_GenCtrl_SetCtrl(SBC_CPEN_ENABLE,SBC_PWM3,SBC_PWM3_TO_HB3);  /*X1_12 to X1_5*/
              Sbc_Tle9562_BMODE_SetCtrl(SBC_HB3,SBC_HBMODE_HS_ON,SBC_HB_AFW_ENABLE,SBC_HB_PWM_ACTIVE,
	                                SBC_HB4,SBC_HBMODE_LS_ON,SBC_HB_AFW_DISABLE,SBC_HB_PWM_INACTIVE); 
	 }
	 else if(CurrentLatchType == LatchType_Default)
	 {
	      Sbc_Tle9562_GenCtrl_SetCtrl(SBC_CPEN_ENABLE,SBC_PWM3,SBC_PWM3_TO_HB3);  /*X1_12 to X1_5*/
              Sbc_Tle9562_BMODE_SetCtrl(SBC_HB3,SBC_HBMODE_HS_ON,SBC_HB_AFW_ENABLE,SBC_HB_PWM_ACTIVE,
	                                SBC_HB4,SBC_HBMODE_LS_ON,SBC_HB_AFW_DISABLE,SBC_HB_PWM_INACTIVE);
	 }
	    #endif
       #else
            #ifdef _CONFIG_CinchMotor_Direction_From_2_To_1  
         Sbc_Tle9562_GenCtrl_SetCtrl(SBC_CPEN_ENABLE,SBC_PWM3,SBC_PWM3_TO_HB4);  /*X1_5 to X1_12*/ 
         Sbc_Tle9562_BMODE_SetCtrl(SBC_HB3,SBC_HBMODE_LS_ON,SBC_HB_AFW_DISABLE,SBC_HB_PWM_INACTIVE,
                                 SBC_HB4,SBC_HBMODE_HS_ON,SBC_HB_AFW_ENABLE,SBC_HB_PWM_ACTIVE);
	    #else      
         Sbc_Tle9562_GenCtrl_SetCtrl(SBC_CPEN_ENABLE,SBC_PWM3,SBC_PWM3_TO_HB3);  /*X1_12 to X1_5*/
         Sbc_Tle9562_BMODE_SetCtrl(SBC_HB3,SBC_HBMODE_HS_ON,SBC_HB_AFW_ENABLE,SBC_HB_PWM_ACTIVE,
	                         SBC_HB4,SBC_HBMODE_LS_ON,SBC_HB_AFW_DISABLE,SBC_HB_PWM_INACTIVE);	
            #endif      
       #endif
       CinchMotor_Direction_Request = Direction_Neutral;
       CinchMotor_Working_Status = TRUE;
     #endif
}

#if defined(_CONFIG_BTS5030) || defined(_CONFIG_BTS7040)
/*********************************************************************************************
** Name:	  API_TurnOn_BTS_IN0_CurrentSensor
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOn_BTS_IN0_CurrentSensor(void)
{
      #ifdef _CONFIG_Gen1_Board 	
      Set_HS_SENSE_EN_0_Port_High(); 
      Set_HS_SENSE_SEL_0_Port_Low();
   
      BTS_IN0_CurrentSensor_Status = TRUE;
      BTS_IN1_CurrentSensor_Status = FALSE;
      #endif
      
      #ifdef _CONFIG_Gen2_Board 	
      Set_U6_DEN_U1_47_Port_High(); 
      Set_U6_DSEL_U1_48_Port_Low();
   
      BTS_IN0_CurrentSensor_Status = TRUE;
      BTS_IN1_CurrentSensor_Status = FALSE;
      #endif
      
      #ifdef _CONFIG_Gen3_Board
      Set_7040_DEN_P10_5_Port_High();
      Set_7040_DSEL_P8_7_Port_Low();
   
      BTS_IN0_CurrentSensor_Status = TRUE;
      BTS_IN1_CurrentSensor_Status = FALSE;  
      #endif
      
      #ifdef _CONFIG_Gen4_Board
      Set_7040_DEN_P10_5_Port_High();      
      Set_7040_DSEL_P0_12_Port_Low();
      
      BTS_IN0_CurrentSensor_Status = TRUE;
      BTS_IN1_CurrentSensor_Status = FALSE; 
      #endif
      
}

/*********************************************************************************************
** Name:	  API_TurnOn_BTS_IN1_CurrentSensor
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOn_BTS_IN1_CurrentSensor(void)
{    
      #ifdef _CONFIG_Gen1_Board	
      Set_HS_SENSE_EN_0_Port_High(); 
      Set_HS_SENSE_SEL_0_Port_High();

      BTS_IN0_CurrentSensor_Status = FALSE;
      BTS_IN1_CurrentSensor_Status = TRUE;
      #endif
      
      #ifdef _CONFIG_Gen2_Board
      Set_U6_DEN_U1_47_Port_High(); 
      Set_U6_DSEL_U1_48_Port_High();

      BTS_IN0_CurrentSensor_Status = FALSE;
      BTS_IN1_CurrentSensor_Status = TRUE;
      #endif
      
      #ifdef _CONFIG_Gen3_Board
      Set_7040_DEN_P10_5_Port_High();
      Set_7040_DSEL_P8_7_Port_High();
      
      BTS_IN0_CurrentSensor_Status = FALSE;
      BTS_IN1_CurrentSensor_Status = TRUE;
      #endif
      
      #ifdef _CONFIG_Gen4_Board	
      Set_7040_DEN_P10_5_Port_High();      
      Set_7040_DSEL_P0_12_Port_High();
 
      BTS_IN0_CurrentSensor_Status = FALSE;
      BTS_IN1_CurrentSensor_Status = TRUE;
      #endif
          
}
#endif




#ifdef _CONFIG_ReleaseMotor
/*********************************************************************************************
** Name:	  API_TurnOn_ReleaseMotor
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOn_ReleaseMotor(void)
{    
     ReleaseMotor_Direction_Request = Direction_Release;
     ReleaseMotor_Working_Status = TRUE;
}
#endif

#if defined(_CONFIG_Clutch) || defined(_CONFIG_ClutchHold)
/*********************************************************************************************
** Name:	  API_TurnOn_Clutch
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOn_Clutch(void)
{
     Clutch_Direction_Request = Direction_ClutchOn;
     Clutch_Working_Status = TRUE;
}
#endif
#ifdef _CONFIG_ReleaseMotor
/*********************************************************************************************
** Name:	  API_TurnOff_ReleaseMotor
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOff_ReleaseMotor(void)
{     
     ReleaseMotor_Duty_Request = 0;
     ReleaseMotor_Direction_Request = Direction_No;
     ReleaseMotor_Working_Status = FALSE;
     
}
#endif
#if defined(_CONFIG_Clutch) || defined(_CONFIG_ClutchHold)
/*********************************************************************************************
** Name:	  API_TurnOff_Clutch
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOff_Clutch(void)
{    
     Clutch_Duty_Request = 0;
     Clutch_Direction_Request = Direction_No;
     Clutch_Working_Status = FALSE;
     
}
#endif

/*********************************************************************************************
** Name:	  API_TurnOn_Speaker
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOn_Speaker(void)
{
     if(FALSE == Speaker_Working_Status)
     {	
       #ifdef _CONFIG_Buzzer_ActiveType	
           #ifdef _CONFIG_Gen1_Board	
           #ifdef _CONFIG_Buzzer_BTS_IN0   
           Set_MCU_ODH_1_Port_High();   
           #endif
     
           #ifdef _CONFIG_Buzzer_BTS_IN1;    
           Set_MCU_ODH_2_Port_High();   
           #endif
    
           #ifdef _CONFIG_Buzzer_SBC_HS4 
           API_TurnOn_SBC_HS4();
           #endif   
           #endif
    
           #ifdef _CONFIG_Gen2_Board	
           #ifdef _CONFIG_Buzzer_BTS_IN0    
           Set_U6_IN0_U1_50_Port_High();   
           #endif
     
           #ifdef _CONFIG_Buzzer_BTS_IN1    
           Set_U6_IN1_U1_49_Port_High();   
           #endif
    
           #ifdef _CONFIG_Buzzer_SBC_HS4
           API_TurnOn_SBC_HS4();
           #endif  
           #endif
    
           #ifdef _CONFIG_Gen3_Board	
           #ifdef _CONFIG_Buzzer_BTS_IN0    
           Set_7040_IN0_P8_9_Port_High();   
           #endif
     
           #ifdef _CONFIG_Buzzer_BTS_IN1   
           Set_7040_IN1_P8_8_Port_High();   
           #endif
    
           #ifdef _CONFIG_Buzzer_SBC_HS4 
           API_TurnOn_SBC_HS4();
           #endif
    
           #ifdef _CONFIG_Buzzer_PNP_DRV   
           Set_Speaker_PWM_P10_15_Port_High(); 
           #endif
           #endif
	   
	   #ifdef _CONFIG_Gen4_Board	
           #ifdef _CONFIG_Buzzer_BTS_IN0    
           Set_7040_IN0_P10_9_Port_High();   
           #endif
     
           #ifdef _CONFIG_Buzzer_BTS_IN1   
           Set_7040_IN1_P0_11_Port_High();   
           #endif
    
           #ifdef _CONFIG_Buzzer_SBC_HS4 
           API_TurnOn_SBC_HS4();
           #endif
    
           #ifdef _CONFIG_Buzzer_PNP_DRV   
	      #ifdef _CONFIG_Gen4_Board_003_004 
	   Set_Speaker_PWM_P10_4_Port_High();
	      #endif
           #endif
           #endif
       #else   	     
          #ifdef _CONFIG_Buzzer_BTS_IN0
          Enable_Speaker_PWM();
          Set_Speaker_PercentDuty(50);    
          #endif
     
          #ifdef _CONFIG_Buzzer_BTS_IN1
          Enable_Speaker_PWM();
          Set_Speaker_PercentDuty(50);    
          #endif
     
          #ifdef _CONFIG_Buzzer_SBC_HS4
          Enable_Speaker_PWM();
          Set_Speaker_PercentDuty(50);    
          #endif
     
          #ifdef _CONFIG_Buzzer_PNP_DRV
          Enable_Speaker_PWM();
          Set_Speaker_PercentDuty(50); 
          #endif   
       #endif
     
     Speaker_Working_Status = TRUE;
     }
     

}

/*********************************************************************************************
** Name:	  API_TurnOff_Speaker
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOff_Speaker(void)
{  
    if(TRUE == Speaker_Working_Status)
    {
    #ifdef _CONFIG_Gen1_Board	
    #ifdef _CONFIG_Buzzer_BTS_IN0
    Disable_Speaker_PWM(); 
    Set_Speaker_PercentDuty(0);    
    Set_MCU_ODH_1_Port_Low();   
    #endif
     
    #ifdef _CONFIG_Buzzer_BTS_IN1
    Disable_Speaker_PWM(); 
    Set_Speaker_PercentDuty(0);    
    Set_MCU_ODH_2_Port_Low();   
    #endif
    
    #ifdef _CONFIG_Buzzer_SBC_HS4
    Disable_Speaker_PWM(); 
    Set_Speaker_PercentDuty(0); 
    API_TurnOff_SBC_HS4();
    #endif   
    #endif
    
    #ifdef _CONFIG_Gen2_Board	
    #ifdef _CONFIG_Buzzer_BTS_IN0
    Disable_Speaker_PWM(); 
    Set_Speaker_PercentDuty(0);    
    Set_U6_IN0_U1_50_Port_Low();   
    #endif
     
    #ifdef _CONFIG_Buzzer_BTS_IN1
    Disable_Speaker_PWM(); 
    Set_Speaker_PercentDuty(0);    
    Set_U6_IN1_U1_49_Port_Low();   
    #endif
    
    #ifdef _CONFIG_Buzzer_SBC_HS4
    Disable_Speaker_PWM(); 
    Set_Speaker_PercentDuty(0);  
    API_TurnOff_SBC_HS4();
    #endif
    
    #endif
    
    #ifdef _CONFIG_Gen3_Board	
    #ifdef _CONFIG_Buzzer_BTS_IN0
    Disable_Speaker_PWM(); 
    Set_Speaker_PercentDuty(0);    
    Set_7040_IN0_P8_9_Port_Low();   
    #endif
     
    #ifdef _CONFIG_Buzzer_BTS_IN1
    Disable_Speaker_PWM(); 
    Set_Speaker_PercentDuty(0);    
    Set_7040_IN1_P8_8_Port_Low();   
    #endif
    
    #ifdef _CONFIG_Buzzer_SBC_HS4
    Disable_Speaker_PWM(); 
    Set_Speaker_PercentDuty(0);  
    API_TurnOff_SBC_HS4();
    #endif
    
    #ifdef _CONFIG_Buzzer_PNP_DRV
    Disable_Speaker_PWM(); 
    Set_Speaker_PercentDuty(0);    
    Set_Speaker_PWM_P10_15_Port_Low(); 
    #endif    
    #endif
    
    #ifdef _CONFIG_Gen4_Board	
    #ifdef _CONFIG_Buzzer_BTS_IN0
    Disable_Speaker_PWM(); 
    Set_Speaker_PercentDuty(0);    
    Set_7040_IN0_P10_9_Port_Low();   
    #endif
     
    #ifdef _CONFIG_Buzzer_BTS_IN1
    Disable_Speaker_PWM(); 
    Set_Speaker_PercentDuty(0);    
    Set_7040_IN1_P0_11_Port_Low();   
    #endif
    
    #ifdef _CONFIG_Buzzer_SBC_HS4
    Disable_Speaker_PWM(); 
    Set_Speaker_PercentDuty(0);  
    API_TurnOff_SBC_HS4();
    #endif
    
    #ifdef _CONFIG_Buzzer_PNP_DRV
    Disable_Speaker_PWM(); 
    Set_Speaker_PercentDuty(0); 
        #ifdef _CONFIG_Gen4_Board_003_004
    Set_Speaker_PWM_P10_4_Port_Low(); 
        #endif
    #endif   
    #endif
    
    Speaker_Working_Status = FALSE;
    }   
}

/*********************************************************************************************
** Name:	  API_Set_Speaker_Period(uint16_t period_us)
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_Set_Speaker_Period(uint16_t period_us)
{    
    #ifdef _CONFIG_Buzzer_BTS_IN0
    Set_Speaker_Cycle(period_us);
    #endif
     
    #ifdef _CONFIG_Buzzer_BTS_IN1
    Set_Speaker_Cycle(period_us);
    #endif
     
    #ifdef _CONFIG_Buzzer_SBC_HS4
    Set_Speaker_Cycle(period_us);
    #endif
    
    #ifdef _CONFIG_Buzzer_PNP_DRV
    Set_Speaker_Cycle(period_us);
    #endif
 
}

/*********************************************************************************************
** Name:	  API_Set_Speaker_PercentDuty(uint16_t duty_percent)
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_Set_Speaker_PercentDuty(uint16_t duty_percent)
{  
    #ifdef _CONFIG_Buzzer_BTS_IN0
    if(duty_percent == 100)
    {
	 Disable_Speaker_PWM();
	 #ifdef _CONFIG_Gen2_Board
         Set_U6_IN0_U1_50_Port_High();
	 #endif
	 
	 #ifdef _CONFIG_Gen3_Board
	 Set_7040_IN0_P8_9_Port_High();
	 #endif
	 
	 #ifdef _CONFIG_Gen4_Board
	 Set_7040_IN0_P10_9_Port_High();
	 #endif
    }
    else if(duty_percent == 0)
    {
	 Disable_Speaker_PWM(); 
	 
	 #ifdef _CONFIG_Gen2_Board
         Set_U6_IN0_U1_50_Port_Low(); 
	 #endif
	 
	 #ifdef _CONFIG_Gen3_Board
	 Set_7040_IN0_P8_9_Port_Low();
	 #endif
	 
	 #ifdef _CONFIG_Gen4_Board
	 Set_7040_IN0_P10_9_Port_Low();
	 #endif
    }
    else
    {
	 Enable_Speaker_PWM();
         Set_Speaker_PercentDuty(duty_percent);
    }
    #endif
     
    #ifdef _CONFIG_Buzzer_BTS_IN1
    if(duty_percent == 100)
    {
	 Disable_Speaker_PWM();  
	 #ifdef _CONFIG_Gen2_Board
         Set_U6_IN1_U1_49_Port_High();
	 #endif
	 #ifdef _CONFIG_Gen3_Board
	 Set_7040_IN1_P8_8_Port_High();
	 #endif
	 
	 #ifdef _CONFIG_Gen4_Board
	 Set_7040_IN1_P0_11_Port_High();
	 #endif
    }
    else if(duty_percent == 0)
    {
	 Disable_Speaker_PWM();
	 #ifdef _CONFIG_Gen2_Board
         Set_U6_IN1_U1_49_Port_Low(); 
	 #endif
	 #ifdef _CONFIG_Gen3_Board
	 Set_7040_IN1_P8_8_Port_Low();
	 #endif
	 
	 #ifdef _CONFIG_Gen4_Board
	 Set_7040_IN1_P0_11_Port_Low();
	 #endif
    }
    else
    {
	 Enable_Speaker_PWM();
         Set_Speaker_PercentDuty(duty_percent);
    }
    #endif
     
    #ifdef _CONFIG_Buzzer_SBC_HS4
    if(duty_percent == 100)
    {
	 Disable_Speaker_PWM();    
         API_TurnOn_SBC_HS4();
    }
    else if(duty_percent == 0)
    {
	 Disable_Speaker_PWM();   
         API_TurnOff_SBC_HS4(); 
    }
    else
    {
	 Enable_Speaker_PWM();
         Set_Speaker_PercentDuty(duty_percent);
    }
    #endif
 
 #ifdef _CONFIG_Gen3_Board
    #ifdef _CONFIG_Buzzer_PNP_DRV
    if(duty_percent == 100)
    {
	 Disable_Speaker_PWM();    
         Set_Speaker_PWM_P10_15_Port_High();
    }
    else if(duty_percent == 0)
    {
	 Disable_Speaker_PWM();   
         Set_Speaker_PWM_P10_15_Port_Low(); 
    }
    else
    {
	 Enable_Speaker_PWM();
         Set_Speaker_PercentDuty(duty_percent);
    }
    #endif
  #endif  
  #ifdef _CONFIG_Gen4_Board_003_004
    #ifdef _CONFIG_Buzzer_PNP_DRV
    if(duty_percent == 100)
    {
	 Disable_Speaker_PWM();    
         Set_Speaker_PWM_P10_4_Port_High();
    }
    else if(duty_percent == 0)
    {
	 Disable_Speaker_PWM();   
         Set_Speaker_PWM_P10_4_Port_Low(); 
    }
    else
    {
	 Enable_Speaker_PWM();
         Set_Speaker_PercentDuty(duty_percent);
    }
    #endif
  #endif 
}

#ifdef _CONFIG_Flasher
/*********************************************************************************************
** Name:	  API_TurnOn_Flasher
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOn_Flasher(void)
{
     if(FALSE == Flasher_Working_Status)
     {
          #ifdef _CONFIG_Flasher_BTS_IN0
          Enable_Flasher_PWM();
          //Set_Flasher_PercentDuty(50);    
          #endif
     
          #ifdef _CONFIG_Flasher_BTS_IN1
          Enable_Flasher_PWM();
          //Set_Flasher_PercentDuty(50);    
          #endif
     
          #ifdef _CONFIG_Flasher_SBC_HS4
          Enable_Flasher_PWM();
          //Set_Flasher_PercentDuty(50);    
          #endif
	  
	  #ifdef _CONFIG_Flasher_PNP_DRV
          Enable_Flasher_PWM();
          //Set_Flasher_PercentDuty(50);    
          #endif
     
          Flasher_Working_Status = TRUE;
     }
}

/*********************************************************************************************
** Name:	  API_TurnOff_Flasher
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOff_Flasher(void)
{
    if(TRUE == Flasher_Working_Status)
    {
         #ifdef _CONFIG_Gen1_Board	
         #ifdef _CONFIG_Flasher_BTS_IN0
         Disable_Flasher_PWM(); 
         Set_Flasher_PercentDuty(0);    
         Set_MCU_ODH_1_Port_Low();   
         #endif
     
         #ifdef _CONFIG_Flasher_BTS_IN1
         Disable_Flasher_PWM(); 
         Set_Flasher_PercentDuty(0);    
         Set_MCU_ODH_2_Port_Low();   
         #endif
    
         #ifdef _CONFIG_Flasher_SBC_HS4
         Disable_Flasher_PWM(); 
         Set_Flasher_PercentDuty(0); 
         API_TurnOff_SBC_HS4();
         #endif
    
         #endif
    
        #ifdef _CONFIG_Gen2_Board	
        #ifdef _CONFIG_Flasher_BTS_IN0
        Disable_Flasher_PWM(); 
        Set_Flasher_PercentDuty(0);    
        Set_U6_IN0_U1_50_Port_Low();   
        #endif
     
        #ifdef _CONFIG_Flasher_BTS_IN1
        Disable_Flasher_PWM(); 
        Set_Flasher_PercentDuty(0);    
        Set_U6_IN1_U1_49_Port_Low();   
        #endif
    
        #ifdef _CONFIG_Flasher_SBC_HS4
        Disable_Flasher_PWM(); 
        Set_Flasher_PercentDuty(0);  
        API_TurnOff_SBC_HS4();
        #endif
    
        #endif
	
	#ifdef _CONFIG_Gen3_Board	
        #ifdef _CONFIG_Flasher_BTS_IN0
        Disable_Flasher_PWM(); 
        Set_Flasher_PercentDuty(0);    
        Set_7040_IN0_P8_9_Port_Low();   
        #endif
     
        #ifdef _CONFIG_Flasher_BTS_IN1
        Disable_Flasher_PWM(); 
        Set_Flasher_PercentDuty(0);    
        Set_7040_IN1_P8_8_Port_Low();   
        #endif
    
        #ifdef _CONFIG_Flasher_SBC_HS4
        Disable_Flasher_PWM(); 
        Set_Flasher_PercentDuty(0);  
        API_TurnOff_SBC_HS4();
        #endif
	
	#ifdef _CONFIG_Flasher_PNP_DRV
        Disable_Flasher_PWM(); 
        Set_Flasher_PercentDuty(0);    
        Set_Speaker_PWM_P10_15_Port_Low();   
        #endif
    
        #endif
	
	#ifdef _CONFIG_Gen4_Board	
        #ifdef _CONFIG_Flasher_BTS_IN0
        Disable_Flasher_PWM(); 
        Set_Flasher_PercentDuty(0);    
        Set_7040_IN0_P10_9_Port_Low();   
        #endif
     
        #ifdef _CONFIG_Flasher_BTS_IN1
        Disable_Flasher_PWM(); 
        Set_Flasher_PercentDuty(0);    
        Set_7040_IN1_P0_11_Port_Low();   
        #endif
    
        #ifdef _CONFIG_Flasher_SBC_HS4
        Disable_Flasher_PWM(); 
        Set_Flasher_PercentDuty(0);  
        API_TurnOff_SBC_HS4();
        #endif
	
	#ifdef _CONFIG_Flasher_PNP_DRV
        Disable_Flasher_PWM(); 
        Set_Flasher_PercentDuty(0);    
	    #ifdef _CONFIG_Gen4_Board_003_004
	Set_Speaker_PWM_P10_4_Port_Low(); 
	    #endif
        #endif
    
        #endif
    
        Flasher_Working_Status = FALSE;
    }   	

}

/*********************************************************************************************
** Name:	  API_Set_Flasher_Period(uint16_t period_us)
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_Set_Flasher_Period(uint16_t period_us)
{
    #ifdef _CONFIG_Flasher_BTS_IN0
    Set_Flasher_Cycle(period_us);
    #endif
     
    #ifdef _CONFIG_Flasher_BTS_IN1
    Set_Flasher_Cycle(period_us);
    #endif
     
    #ifdef _CONFIG_Flasher_SBC_HS4
    Set_Flasher_Cycle(period_us);
    #endif
    
    #ifdef _CONFIG_Flasher_PNP_DRV
    Set_Flasher_Cycle(period_us);
    #endif
}

/*********************************************************************************************
** Name:	  API_Set_Flasher_Duty(uint16_t duty)
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_Set_Flasher_Duty(uint16_t duty)
{
    #ifdef _CONFIG_Flasher_BTS_IN0
    Set_Flasher_Duty(duty);
    #endif
     
    #ifdef _CONFIG_Flasher_BTS_IN1
    Set_Flasher_Duty(duty);
    #endif
     
    #ifdef _CONFIG_Flasher_SBC_HS4
    Set_Flasher_Duty(duty);
    #endif
    
    #ifdef _CONFIG_Flasher_PNP_DRV
    Set_Flasher_Duty(duty);
    #endif
}
/*********************************************************************************************
** Name:	  API_Set_Flasher_PercentDuty(uint16_t duty_percent)
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_Set_Flasher_PercentDuty(uint16_t duty_percent)
{
    #ifdef _CONFIG_Flasher_BTS_IN0
    if(duty_percent == 100)
    {
	 Disable_Flasher_PWM();    
         Set_U6_IN0_U1_50_Port_High();
    }
    else if(duty_percent == 0)
    {
	 Disable_Flasher_PWM();   
         Set_U6_IN0_U1_50_Port_Low(); 
    }
    else
    {
	 Enable_Flasher_PWM();
         Set_Flasher_PercentDuty(duty_percent);
    }
    #endif
     
    #ifdef _CONFIG_Flasher_BTS_IN1
    if(duty_percent == 100)
    {
	 Disable_Flasher_PWM();    
         Set_U6_IN1_U1_49_Port_High();
    }
    else if(duty_percent == 0)
    {
	 Disable_Flasher_PWM();   
         Set_U6_IN1_U1_49_Port_Low(); 
    }
    else
    {
	 Enable_Flasher_PWM();
         Set_Flasher_PercentDuty(duty_percent);
    }
    #endif
     
    #ifdef _CONFIG_Flasher_SBC_HS4
    if(duty_percent == 100)
    {
	 Disable_Flasher_PWM();    
         API_TurnOn_SBC_HS4();
    }
    else if(duty_percent == 0)
    {
	 Disable_Flasher_PWM();   
         API_TurnOff_SBC_HS4(); 
    }
    else
    {
	 Enable_Flasher_PWM();
         Set_Flasher_PercentDuty(duty_percent);
    }
    #endif
    
    #ifdef _CONFIG_Flasher_PNP_DRV
    if(duty_percent == 100)
    {
	 Disable_Flasher_PWM();    
         Set_Speaker_PWM_P10_15_Port_High();
    }
    else if(duty_percent == 0)
    {
	 Disable_Flasher_PWM();   
         Set_Speaker_PWM_P10_15_Port_Low(); 
    }
    else
    {
	 Enable_Flasher_PWM();
         Set_Flasher_PercentDuty(duty_percent);
    }
    #endif
}
#endif

#ifdef _CONFIG_Buzzer
/*********************************************************************************************
** Name:	  API_TurnOn_Buzzer
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOn_Buzzer(void)
{   
    #ifdef _CONFIG_Buzzer_ActiveType	
       #ifdef _CONFIG_TLE9263
    Sbc_Tle9263_Hsd_SetCtrl(SBC_HSD4,SBC_HSD_ON); 	
       #endif
       #ifdef _CONFIG_TLE9562
    Sbc_Tle9562_Hsd_SetCtrl(SBC_HSD4,SBC_HSD_ON); 	
       #endif
    #else	
    Buzzer_Duty_Request = K_Buzzer_Base_Duty * Buzzer_OnePercentPWM_Value;
    //Set_ODH_2_CTN_Duty(K_Buzzer_Base_Duty);
    Buzzer_Working_Status = TRUE;
    #endif
    
}

/*********************************************************************************************
** Name:	  API_TurnOff_Buzzer
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOff_Buzzer(void)
{
     #ifdef _CONFIG_Buzzer_ActiveType
       #ifdef _CONFIG_TLE9263
    Sbc_Tle9263_Hsd_SetCtrl(SBC_HSD4,SBC_HSD_OFF); 	
       #endif
       #ifdef _CONFIG_TLE9562
    Sbc_Tle9562_Hsd_SetCtrl(SBC_HSD4,SBC_HSD_OFF);	
       #endif     
     #else
     Buzzer_Duty_Request = 0 * Buzzer_OnePercentPWM_Value;
     //Set_ODH_2_CTN_Duty(0);
     Buzzer_Working_Status = FALSE;
     #endif
}

/*********************************************************************************************
** Name:	  void API_Set_Buzzer_Period(uint16_t period)
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_Set_Buzzer_Period(uint16_t period)
{
}
/*********************************************************************************************
** Name:	  API_Set_Buzzer_PercentDuty(uint16_t duty_percent)
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_Set_Buzzer_PercentDuty(uint16_t duty_percent)
{
}
#endif

#ifdef _CONFIG_Gen1_Board
/*********************************************************************************************
** Name:	  API_TurnOn_LowSideOutput
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOn_LowSideOutput(void)
{
     #ifdef _CONFIG_Gen1_Board
     Set_ODL_0_CTN_Port_High();
	
    //Set_ODL_0_CTN_Cycle(100);      /*Template 100us*/ 
    //Set_ODL_0_CTN_PercentDuty(100);
     #endif
     
}

/*********************************************************************************************
** Name:	  API_TurnOff_LowSideOutput
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOff_LowSideOutput(void)
{
     #ifdef _CONFIG_Gen1_Board
     Set_ODL_0_CTN_Port_Low();
     //Set_ODL_0_CTN_Cycle(100);       
     //Set_ODL_0_CTN_PercentDuty(0);
     #endif
}
#endif
#if defined(_CONFIG_Gen3_Board) || defined(_CONFIG_Gen4_Board)
/*********************************************************************************************
** Name:	  API_TurnOn_LSD
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOn_LSD(void)
{
    #ifdef _CONFIG_Gen3_Board
    Set_LSD_OUT_P10_14_Port_High();
    #endif
    #ifdef _CONFIG_Gen4_Board
    Set_LSD_OUT_P11_7_Port_High();
    #endif
}
/*********************************************************************************************
** Name:	  API_TurnOff_LSD
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOff_LSD(void)
{
    #ifdef _CONFIG_Gen3_Board
    Set_LSD_OUT_P10_14_Port_Low();
    #endif
    #ifdef _CONFIG_Gen4_Board
    Set_LSD_OUT_P11_7_Port_Low();
    #endif
}
#endif
#ifdef _CONFIG_Gen3_Board
/*********************************************************************************************
** Name:	  API_TurnOn_LSD2
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOn_LSD2(void)
{
    Set_LSD2_PWM_P8_6_Port_High();
}
/*********************************************************************************************
** Name:	  API_TurnOff_LSD2
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOff_LSD2(void)
{
    Set_LSD2_PWM_P8_6_Port_Low();
}
#endif

/*********************************************************************************************
** Name:	  API_Set_Motor1_PWMPeriod
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_Set_Motor1_PWMPeriod(uint16_t period)
{
      #ifdef _CONFIG_Gen1_Board
      Set_ODH_3_CTN_Cycle(period);
      Set_ODH_4_CTN_Cycle(period);
      #endif
      
      #ifdef _CONFIG_Gen2_Board
      Set_U3_IN1_PH_U1_85_Cycle(period);
      Set_U3_IN2_EN_U1_86_Cycle(period);
      #endif
      
      #ifdef _CONFIG_Gen3_Board
      Set_M1_IN1_P10_11_Cycle(period);
      Set_M1_IN2_P10_12_Cycle(period);
      #endif
      
      #ifdef _CONFIG_Gen4_Board
      Set_M1_PWM1_P10_11_Cycle(period);
      //Set_M1_PWM2_P10_12_Cycle(period);
      #endif
}
/*********************************************************************************************
** Name:	  API_Set_Motor2_PWMPeriod
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_Set_Motor2_PWMPeriod(uint16_t period)
{
      #ifdef _CONFIG_Gen1_Board
      Set_ODH_5_CTN_Cycle(period);
      Set_ODH_6_CTN_Cycle(period);
      #endif
      
      #ifdef _CONFIG_Gen2_Board
      Set_U4_IN2_EN_U1_82_Cycle(period);
      Set_U4_IN1_PH_U1_81_Cycle(period);
      #endif
      
      #if defined(_CONFIG_Gen3_Board) || defined(_CONFIG_Gen4_Board)
      Set_M2_IN2_P10_8_Cycle(period);
      Set_M2_IN1_P10_7_Cycle(period);
      #endif
}

/*********************************************************************************************
** Name:	  API_Set_CinchMotor_PWMPeriod
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_Set_CinchMotor_PWMPeriod(uint16_t period)
{
     #ifdef _CONFIG_Gen1_Board
     Set_CINCH_PWM_Cycle(period);
     #endif
     
     #ifdef _CONFIG_Gen2_Board
     Set_U5_IN1_PH_U1_89_Cycle(period);
     Set_U5_IN2_EN_U1_1_Cycle(period);
     #endif
     
     #ifdef _CONFIG_Gen3_Board
     Set_M3_IN1_P11_1_Cycle(period);
     Set_M3_IN2_P10_3_Cycle(period);
     #endif
     
     #ifdef _CONFIG_Gen4_Board
     Set_M3_PWM3_P11_1_Cycle(period);
     //Set_M3_PWM4_P10_3_Cycle(period);
     #endif
}




#ifdef _CONFIG_HighSideOutputControl
/*High Side Output Control*/
/*********************************************************************************************
** Name:	  API_TurnOn_HS_Output_J2_1
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOn_HS_Output_J2_1(void)
{
      #ifdef _CONFIG_Gen1_Board
      Set_CINCH_INA_Port_Low();
      Set_CINCH_INB_Port_High();
      
      Set_CINCH_SEL0_Port_Low();
      Set_CINCH_SEL1_Port_Low();
      
      Set_CINCH_SEN_EN_Port_High(); 
            
      //CinchMotor_Duty_Request = 0;     
      CinchMotor_Duty_Request = 100 * CinchMotor_OnePercentPWM_Value;
      Output_J2_1_Work_Status = TRUE;
      #endif
      
      #ifdef _CONFIG_Gen2_Board
      DRV8702_U5_Active();
      DRV8702_U5_IndependentPWM_Control();
      Set_U5_IN1_PH_U1_89_PercentDuty(100);
      Output_J2_1_Work_Status = TRUE;
      #endif	
}

/*********************************************************************************************
** Name:	  API_TurnOn_HS_Output_J2_2
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOn_HS_Output_J2_2(void)
{
      #ifdef _CONFIG_Gen1_Board
      Set_CINCH_INA_Port_High();
      Set_CINCH_INB_Port_Low();
      
      Set_CINCH_SEL0_Port_High();
      Set_CINCH_SEL1_Port_Low();
      
      Set_CINCH_SEN_EN_Port_High(); 
      //CinchMotor_Duty_Request = 0;
      CinchMotor_Duty_Request = 100 * CinchMotor_OnePercentPWM_Value;
      Output_J2_2_Work_Status = TRUE;
      #endif
      
      #ifdef _CONFIG_Gen2_Board
      DRV8702_U5_Active();
      DRV8702_U5_IndependentPWM_Control();
      Set_U5_IN2_EN_U1_1_PercentDuty(100);
      Output_J2_2_Work_Status = TRUE;
      #endif
      
      
}

/*********************************************************************************************
** Name:	  API_TurnOn_HS_Output_J3_1
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOn_HS_Output_J3_1(void)
{
     #ifdef _CONFIG_Gen2_Board
      DRV8702_U3_Active();
      DRV8702_U3_IndependentPWM_Control();
      Set_U3_IN1_PH_U1_85_PercentDuty(100);
      Output_J3_1_Work_Status = TRUE;
      #endif
}

/*********************************************************************************************
** Name:	  API_TurnOn_HS_Output_J3_2
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOn_HS_Output_J3_2(void)
{
      #ifdef _CONFIG_Gen2_Board
      DRV8702_U3_Active();
      DRV8702_U3_IndependentPWM_Control();
      Set_U3_IN2_EN_U1_86_PercentDuty(100);
      Output_J3_2_Work_Status = TRUE;
      #endif
}

/*********************************************************************************************
** Name:	  API_TurnOn_HS_Output_J3_3
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOn_HS_Output_J3_3(void)
{
    #ifdef _CONFIG_Gen2_Board
      DRV8702_U4_Active();
      DRV8702_U4_IndependentPWM_Control();
      Set_U4_IN1_PH_U1_81_PercentDuty(100);
      Output_J3_3_Work_Status = TRUE;
      #endif
}

/*********************************************************************************************
** Name:	  API_TurnOn_HS_Output_J3_4
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOn_HS_Output_J3_4(void)
{
    #ifdef _CONFIG_Gen2_Board
      DRV8702_U4_Active();
      DRV8702_U4_IndependentPWM_Control();
      Set_U4_IN2_EN_U1_82_PercentDuty(100);
      Output_J3_4_Work_Status = TRUE;
      #endif
}
/*********************************************************************************************
** Name:	  API_TurnOff_HS_Output_J2_1
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOff_HS_Output_J2_1(void)
{
      #ifdef _CONFIG_Gen1_Board
      Set_CINCH_INA_Port_Low();
      Set_CINCH_INB_Port_Low();
      
      Set_CINCH_SEL0_Port_Low();
      Set_CINCH_SEL1_Port_Low();
      
      Set_CINCH_SEN_EN_Port_Low();
      //Set_CINCH_PWM_PercentDuty(0);
      CinchMotor_Duty_Request = 0;
      #endif
      
      #ifdef _CONFIG_Gen2_Board
      Set_U5_IN1_PH_U1_89_PercentDuty(0);
      
      Output_J2_1_Work_Status = FALSE;
      if((FALSE == Output_J2_1_Work_Status) && (FALSE == Output_J2_2_Work_Status))
      {
          DRV8702_U5_Inactive();
      }
      
      #endif
       
}
/*********************************************************************************************
** Name:	  API_TurnOff_HS_Output_J2_2
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOff_HS_Output_J2_2(void)
{
      #ifdef _CONFIG_Gen1_Board
      Set_CINCH_INA_Port_Low();
      Set_CINCH_INB_Port_Low();
      
      Set_CINCH_SEL0_Port_Low();
      Set_CINCH_SEL1_Port_Low();
      
      Set_CINCH_SEN_EN_Port_Low();
      //Set_CINCH_PWM_PercentDuty(0);
      CinchMotor_Duty_Request = 0;
      #endif
      
      #ifdef _CONFIG_Gen2_Board
      Set_U5_IN2_EN_U1_1_PercentDuty(0);
      Output_J2_2_Work_Status = FALSE;
      if((FALSE == Output_J2_1_Work_Status) && (FALSE == Output_J2_2_Work_Status))
      {
          DRV8702_U5_Inactive();
      }
      #endif
      
}
/*********************************************************************************************
** Name:	  API_TurnOff_HS_Output_J3_1
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOff_HS_Output_J3_1(void)
{
     #ifdef _CONFIG_Gen2_Board
     Set_U3_IN1_PH_U1_85_PercentDuty(0);
     Output_J3_1_Work_Status = FALSE;
      if((FALSE == Output_J3_1_Work_Status) && (FALSE == Output_J3_2_Work_Status))
      {
          DRV8702_U3_Inactive();
      }
     #endif
}
/*********************************************************************************************
** Name:	  API_TurnOff_HS_Output_J3_2
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOff_HS_Output_J3_2(void)
{
     #ifdef _CONFIG_Gen2_Board
     Set_U3_IN2_EN_U1_86_PercentDuty(0);
     Output_J3_2_Work_Status = FALSE;
      if((FALSE == Output_J3_1_Work_Status) && (FALSE == Output_J3_2_Work_Status))
      {
          DRV8702_U3_Inactive();
      }
     #endif
}
/*********************************************************************************************
** Name:	  API_TurnOff_HS_Output_J3_3
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOff_HS_Output_J3_3(void)
{
     #ifdef _CONFIG_Gen2_Board
     Set_U4_IN1_PH_U1_81_PercentDuty(0);
     Output_J3_3_Work_Status = FALSE;
      if((FALSE == Output_J3_3_Work_Status) && (FALSE == Output_J3_4_Work_Status))
      {
          DRV8702_U3_Inactive();
      }
     #endif
}
/*********************************************************************************************
** Name:	  API_TurnOff_HS_Output_J3_4
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOff_HS_Output_J3_4(void)
{
     #ifdef _CONFIG_Gen2_Board
     Set_U4_IN2_EN_U1_82_PercentDuty(0);
     Output_J3_4_Work_Status = FALSE;
      if((FALSE == Output_J3_3_Work_Status) && (FALSE == Output_J3_4_Work_Status))
      {
          DRV8702_U3_Inactive();
      }
     #endif
}
/*********************************************************************************************
** Name:	  API_TurnOn_LS_Output_J2_1
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOn_LS_Output_J2_1(void)
{
      #ifdef _CONFIG_Gen2_Board
      DRV8702_U5_Active();
      DRV8702_U5_IndependentPWM_Control();
      Set_U5_IN1_PH_U1_89_PercentDuty(0);
      Output_J2_1_Work_Status = TRUE;
      #endif
}
/*********************************************************************************************
** Name:	  API_TurnOn_LS_Output_J2_2
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOn_LS_Output_J2_2(void)
{
      #ifdef _CONFIG_Gen2_Board
      DRV8702_U5_Active();
      DRV8702_U5_IndependentPWM_Control();
      Set_U5_IN2_EN_U1_1_PercentDuty(0);
      Output_J2_2_Work_Status = TRUE;
      #endif
}
/*********************************************************************************************
** Name:	  API_TurnOn_LS_Output_J3_1
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOn_LS_Output_J3_1(void)
{
     #ifdef _CONFIG_Gen2_Board
      DRV8702_U3_Active();
      DRV8702_U3_IndependentPWM_Control();
      Set_U3_IN1_PH_U1_85_PercentDuty(0);
      Output_J3_1_Work_Status = TRUE;
      #endif
}
/*********************************************************************************************
** Name:	  API_TurnOn_LS_Output_J3_2
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOn_LS_Output_J3_2(void)
{
      #ifdef _CONFIG_Gen2_Board
      DRV8702_U3_Active();
      DRV8702_U3_IndependentPWM_Control();
      Set_U3_IN2_EN_U1_86_PercentDuty(0);
      Output_J3_2_Work_Status = TRUE;
      #endif
}
/*********************************************************************************************
** Name:	  API_TurnOn_LS_Output_J3_3
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOn_LS_Output_J3_3(void)
{
     #ifdef _CONFIG_Gen2_Board
      DRV8702_U4_Active();
      DRV8702_U4_IndependentPWM_Control();
      Set_U4_IN1_PH_U1_81_PercentDuty(0);
      Output_J3_3_Work_Status = TRUE;
      #endif
      
}
/*********************************************************************************************
** Name:	  API_TurnOn_LS_Output_J3_4
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOn_LS_Output_J3_4(void)
{
     #ifdef _CONFIG_Gen2_Board
      DRV8702_U4_Active();
      DRV8702_U4_IndependentPWM_Control();
      Set_U4_IN2_EN_U1_82_PercentDuty(0);
      Output_J3_4_Work_Status = TRUE;
      #endif
}

/*********************************************************************************************
** Name:	  API_TurnOff_LS_Output_J2_1
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOff_LS_Output_J2_1(void)
{
     #ifdef _CONFIG_Gen2_Board
     Set_U5_IN1_PH_U1_89_PercentDuty(100);
      
      Output_J2_1_Work_Status = FALSE;
      if((FALSE == Output_J2_1_Work_Status) && (FALSE == Output_J2_2_Work_Status))
      {
          DRV8702_U5_Inactive();
	  Set_U5_IN1_PH_U1_89_PercentDuty(0);
      }
     #endif
}
/*********************************************************************************************
** Name:	  API_TurnOff_LS_Output_J2_2
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOff_LS_Output_J2_2(void)
{
      #ifdef _CONFIG_Gen2_Board
      Set_U5_IN2_EN_U1_1_PercentDuty(100);
      Output_J2_2_Work_Status = FALSE;
      if((FALSE == Output_J2_1_Work_Status) && (FALSE == Output_J2_2_Work_Status))
      {
          DRV8702_U5_Inactive();
	  Set_U5_IN2_EN_U1_1_PercentDuty(0);
      }
     #endif
}
/*********************************************************************************************
** Name:	  API_TurnOff_LS_Output_J3_1
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOff_LS_Output_J3_1(void)
{
     #ifdef _CONFIG_Gen2_Board
     Set_U3_IN1_PH_U1_85_PercentDuty(100);
     Output_J3_1_Work_Status = FALSE;
      if((FALSE == Output_J3_1_Work_Status) && (FALSE == Output_J3_2_Work_Status))
      {
          DRV8702_U3_Inactive();
	  Set_U3_IN1_PH_U1_85_PercentDuty(0);
      }
     #endif
}
/*********************************************************************************************
** Name:	  API_TurnOff_LS_Output_J3_2
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOff_LS_Output_J3_2(void)
{
     #ifdef _CONFIG_Gen2_Board
     Set_U3_IN2_EN_U1_86_PercentDuty(100);
     Output_J3_2_Work_Status = FALSE;
      if((FALSE == Output_J3_1_Work_Status) && (FALSE == Output_J3_2_Work_Status))
      {
          DRV8702_U3_Inactive();
	  Set_U3_IN2_EN_U1_86_PercentDuty(0);
      }
     #endif
}

/*********************************************************************************************
** Name:	  API_TurnOff_LS_Output_J3_3
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOff_LS_Output_J3_3(void)
{
     #ifdef _CONFIG_Gen2_Board
     Set_U4_IN1_PH_U1_81_PercentDuty(100);
     Output_J3_3_Work_Status = FALSE;
      if((FALSE == Output_J3_3_Work_Status) && (FALSE == Output_J3_4_Work_Status))
      {
          DRV8702_U3_Inactive();
	  Set_U4_IN1_PH_U1_81_PercentDuty(0);
      }
     #endif
}

/*********************************************************************************************
** Name:	  API_TurnOff_LS_Output_J3_4
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void API_TurnOff_LS_Output_J3_4(void)
{
     #ifdef _CONFIG_Gen2_Board
     Set_U4_IN2_EN_U1_82_PercentDuty(100);
     Output_J3_4_Work_Status = FALSE;
      if((FALSE == Output_J3_3_Work_Status) && (FALSE == Output_J3_4_Work_Status))
      {
          DRV8702_U3_Inactive();
	  Set_U4_IN2_EN_U1_82_PercentDuty(0);
      }
     #endif
}

void API_Output_J2_1_PWMDuty(uint16_t pecentduty,tD_H_Bridge_Side side)
{
    #ifdef _CONFIG_Gen2_Board
 
    DRV8702_U5_Active();
    DRV8702_U5_IndependentPWM_Control(); 
    Output_J2_1_Work_Status = TRUE;
    	
    if(side == High_Side)
    {
	 Set_U5_IN1_PH_U1_89_PercentDuty(pecentduty);
    }
    else if(side == Low_Side)
    {
	 Set_U5_IN1_PH_U1_89_PercentDuty(100 - pecentduty);
    }
    #endif
}

void API_Output_J2_2_PWMDuty(uint16_t pecentduty,tD_H_Bridge_Side side)
{
    #ifdef _CONFIG_Gen2_Board

    DRV8702_U5_Active();
    DRV8702_U5_IndependentPWM_Control();
    Output_J2_2_Work_Status = TRUE;
    	
    if(side == High_Side)
    {
	 Set_U5_IN2_EN_U1_1_PercentDuty(pecentduty);
    }
    else if(side == Low_Side)
    {
	 Set_U5_IN2_EN_U1_1_PercentDuty(100 - pecentduty);
    }
    #endif
}

void API_Output_J3_1_PWMDuty(uint16_t pecentduty,tD_H_Bridge_Side side)
{
    #ifdef _CONFIG_Gen2_Board

    DRV8702_U3_Active();
    DRV8702_U3_IndependentPWM_Control();
    Output_J3_1_Work_Status = TRUE;
    if(side == High_Side)
    {
	 Set_U3_IN1_PH_U1_85_PercentDuty(pecentduty);
    }
    else if(side == Low_Side)
    {
	 Set_U3_IN1_PH_U1_85_PercentDuty(100 - pecentduty);
    }
    #endif
}
void API_Output_J3_2_PWMDuty(uint16_t pecentduty,tD_H_Bridge_Side side)
{
    #ifdef _CONFIG_Gen2_Board  
    DRV8702_U3_Active();
    DRV8702_U3_IndependentPWM_Control();
    Output_J3_2_Work_Status = TRUE;
    if(side == High_Side)
    {
	 Set_U3_IN2_EN_U1_86_PercentDuty(pecentduty);
    }
    else if(side == Low_Side)
    {
	 Set_U3_IN2_EN_U1_86_PercentDuty(100 - pecentduty);
    }
    #endif
}

void API_Output_J3_3_PWMDuty(uint16_t pecentduty,tD_H_Bridge_Side side)
{
    #ifdef _CONFIG_Gen2_Board
    DRV8702_U4_Active();
    DRV8702_U4_IndependentPWM_Control();
    Output_J3_3_Work_Status = TRUE; 
    if(side == High_Side)
    {
	 Set_U4_IN1_PH_U1_81_PercentDuty(pecentduty);
    }
    else if(side == Low_Side)
    {
	 Set_U4_IN1_PH_U1_81_PercentDuty(100 - pecentduty);
    }
    #endif
}

void API_Output_J3_4_PWMDuty(uint16_t pecentduty,tD_H_Bridge_Side side)
{
    #ifdef _CONFIG_Gen2_Board
    DRV8702_U4_Active();
    DRV8702_U4_IndependentPWM_Control();
    Output_J3_4_Work_Status = TRUE; 
    if(side == High_Side)
    {
	 Set_U4_IN2_EN_U1_82_PercentDuty(pecentduty);
    }
    else if(side == Low_Side)
    {
	 Set_U4_IN2_EN_U1_82_PercentDuty(100 - pecentduty);
    }
    #endif
}

void API_Set_Output_J2_1_PWMPeriod(uint16_t period)
{
    #ifdef _CONFIG_Gen2_Board
    Set_U5_IN1_PH_U1_89_Cycle(period);
    #endif
}
void API_Set_Output_J2_2_PWMPeriod(uint16_t period)
{
    #ifdef _CONFIG_Gen2_Board
    Set_U5_IN2_EN_U1_1_Cycle(period);
    #endif
}
void API_Set_Output_J3_1_PWMPeriod(uint16_t period)
{
    #ifdef _CONFIG_Gen2_Board
    Set_U3_IN1_PH_U1_85_Cycle(period);
    #endif
}
void API_Set_Output_J3_2_PWMPeriod(uint16_t period)
{
    #ifdef _CONFIG_Gen2_Board
    Set_U3_IN2_EN_U1_86_Cycle(period);
    #endif
}
void API_Set_Output_J3_3_PWMPeriod(uint16_t period)
{
    #ifdef _CONFIG_Gen2_Board
    Set_U4_IN1_PH_U1_81_Cycle(period);
    #endif
}
void API_Set_Output_J3_4_PWMPeriod(uint16_t period)
{
    #ifdef _CONFIG_Gen2_Board
    Set_U4_IN2_EN_U1_82_Cycle(period);
    #endif
}
#endif


#ifdef _CONFIG_MOSFET_Connection
/*Power Side Latch Motor Control*/
void API_TurnOn_CinchMotor1_Cinch(void)
{
    #ifdef _CONFIG_Gen2_Board
    if(FALSE == CinchMotor1_Cinch_Disable)
    {
        DRV8702_U5_Active();
        DRV8702_U5_IndependentPWM_Control();
    
        CinchMotor1_H_Bridge = High_Side;
        CinchMotor1_Direction_Request = Direction_Cinch;
        CinchMotor1_Working_Status = TRUE; 

    }
    #endif
}

void API_TurnOn_CinchMotor1_Neutral(void)
{
    #ifdef _CONFIG_Gen2_Board
    if(FALSE == CinchMotor1_Neutral_Disable)
    {        
        DRV8702_U5_Active();
        DRV8702_U5_IndependentPWM_Control();
    
        CinchMotor1_H_Bridge = Low_Side;
        CinchMotor1_Direction_Request = Direction_Neutral;
        CinchMotor1_Working_Status = TRUE;

    }
    #endif
}

void API_TurnOn_ReleaseMotor1_Release(void)
{
    #ifdef _CONFIG_Gen2_Board
    if(FALSE == ReleaseMotor1_Release_Disable)
    {               
        DRV8702_U5_Active();
        DRV8702_U5_IndependentPWM_Control();
        DRV8702_U3_Active();
        DRV8702_U3_IndependentPWM_Control();
    
        ReleaseMotor1_H_Bridge = Low_Side;
        ReleaseMotor1_Direction_Request = Direction_Release;
        ReleaseMotor1_Working_Status = TRUE;

    }
    #endif
}

void API_TurnOn_ReleaseMotor1_Findhome(void)
{
    #ifdef _CONFIG_Gen2_Board
    if(FALSE == ReleaseMotor1_Findhome_Disable)
    {                       
        DRV8702_U5_Active();
        DRV8702_U5_IndependentPWM_Control();
        DRV8702_U3_Active();
        DRV8702_U3_IndependentPWM_Control();
    
        ReleaseMotor1_H_Bridge = High_Side;
        ReleaseMotor1_Direction_Request = Direction_Findhome;
        ReleaseMotor1_Working_Status = TRUE;
    	
    }
    #endif
}

void API_TurnOn_CinchMotor2_Cinch(void)
{
    #ifdef _CONFIG_Gen2_Board
    if(FALSE == CinchMotor2_Cinch_Disable)
    {            
        DRV8702_U4_Active();
        DRV8702_U4_IndependentPWM_Control();
    
        CinchMotor2_H_Bridge = High_Side;
        CinchMotor2_Direction_Request = Direction_Cinch;
        CinchMotor2_Working_Status = TRUE; 

    }    
    #endif
}
void API_TurnOn_CinchMotor2_Neutral(void)
{
    #ifdef _CONFIG_Gen2_Board
    if(FALSE == CinchMotor2_Neutral_Disable)
    {               
        DRV8702_U4_Active();
        DRV8702_U4_IndependentPWM_Control();
    
        CinchMotor2_H_Bridge = Low_Side;
        CinchMotor2_Direction_Request = Direction_Neutral;
        CinchMotor2_Working_Status = TRUE; 

    }    
    #endif
}
void API_TurnOn_ReleaseMotor2_Release(void)
{
    #ifdef _CONFIG_Gen2_Board
    if(FALSE == ReleaseMotor2_Release_Disable)
    {               
        
        DRV8702_U4_Active();
        DRV8702_U4_IndependentPWM_Control();
        DRV8702_U3_Active();
        DRV8702_U3_IndependentPWM_Control();
    
        ReleaseMotor2_H_Bridge = Low_Side;
        ReleaseMotor2_Direction_Request = Direction_Release;
        ReleaseMotor2_Working_Status = TRUE;
    	
    }
    
    #endif
}
void API_TurnOn_ReleaseMotor2_Findhome(void)
{
    #ifdef _CONFIG_Gen2_Board
    if(FALSE == ReleaseMotor2_Findhome_Disable)
    {                               
        DRV8702_U4_Active();
        DRV8702_U4_IndependentPWM_Control();
        DRV8702_U3_Active();
        DRV8702_U3_IndependentPWM_Control();
    
        ReleaseMotor2_H_Bridge = High_Side;
        ReleaseMotor2_Direction_Request = Direction_Findhome;
        ReleaseMotor2_Working_Status = TRUE; 

    }
    #endif
}

void API_TurnOff_CinchMotor1(void)
{
    #ifdef _CONFIG_Gen2_Board
    CinchMotor1_Working_Status = FALSE;
    CinchMotor1_Duty_Request = 0;
    if((FALSE == CinchMotor1_Working_Status) && (FALSE == ReleaseMotor1_Working_Status))
    {
        DRV8702_U5_Inactive();
    }
    CinchMotor1_Cinch_Disable = FALSE;
    CinchMotor2_Neutral_Disable = FALSE;
    
    #endif
}
void API_TurnOff_CinchMotor2(void)
{
    #ifdef _CONFIG_Gen2_Board
    CinchMotor2_Working_Status = FALSE;
    CinchMotor2_Duty_Request = 0;
    
    if((FALSE == CinchMotor2_Working_Status) && (FALSE == ReleaseMotor2_Working_Status))
    {
        DRV8702_U4_Inactive();
    }
    CinchMotor2_Cinch_Disable = FALSE;
    CinchMotor2_Neutral_Disable = FALSE;
    
    #endif
}
void API_TurnOff_ReleaseMotor1(void)
{
    #ifdef _CONFIG_Gen2_Board
    ReleaseMotor1_Working_Status = FALSE;
    ReleaseMotor1_Duty_Request = 0;
    
    if((FALSE == CinchMotor1_Working_Status) && (FALSE == ReleaseMotor1_Working_Status))
    {
        DRV8702_U5_Inactive();
    }
    
    if((FALSE == ReleaseMotor1_Working_Status) && (FALSE == ReleaseMotor2_Working_Status))
    {
        DRV8702_U3_Inactive();
    }
    ReleaseMotor1_Release_Disable = FALSE;
    ReleaseMotor1_Findhome_Disable = FALSE;
    
    #endif
}
void API_TurnOff_ReleaseMotor2(void)
{
    #ifdef _CONFIG_Gen2_Board
    ReleaseMotor1_Working_Status = FALSE;
    ReleaseMotor1_Duty_Request = 0;
    
    if((FALSE == CinchMotor2_Working_Status) && (FALSE == ReleaseMotor2_Working_Status))
    {
        DRV8702_U4_Inactive();
    }
    
    if((FALSE == ReleaseMotor1_Working_Status) && (FALSE == ReleaseMotor2_Working_Status))
    {
        DRV8702_U3_Inactive();
    }
    ReleaseMotor2_Release_Disable = FALSE;
    ReleaseMotor2_Findhome_Disable = FALSE;
    #endif
}

void API_CinchMotor1_PWMDuty_Update(uint16_t duty,uint16_t direction)
{
    if(direction == Direction_Cinch)
    {
	  Set_U5_IN1_PH_U1_89_Duty(duty);       
	  Set_U5_IN2_EN_U1_1_Duty(0);                           /*J2_1 to J2_2*/
    }
    else if(direction == Direction_Neutral)
    {	  
	  Set_U5_IN1_PH_U1_89_Duty(CinchMotor1_Period - duty);  /*J2_2 to J2_1*/
	  Set_U5_IN2_EN_U1_1_Duty(CinchMotor1_Period);
    }

}
void API_CinchMotor2_PWMDuty_Update(uint16_t duty,uint16_t direction)
{
    if(direction == Direction_Cinch)
    {
	  Set_U4_IN2_EN_U1_82_Duty(duty);       
	  Set_U4_IN1_PH_U1_81_Duty(0);                          /*J3_4 to J3_3*/
    }
    else if(direction == Direction_Neutral)
    {	  
	  Set_U4_IN2_EN_U1_82_Duty(CinchMotor2_Period - duty);  /*J3_3 to J3_4*/
	  Set_U4_IN1_PH_U1_81_Duty(CinchMotor2_Period);
    }
}
void API_ReleaseMotor1_PWMDuty_Update(uint16_t duty,uint16_t direction)
{
    if(direction == Direction_Release)
    {
	  Set_U3_IN1_PH_U1_85_Duty(ReleaseMotor1_Period - duty);       
	  Set_U5_IN2_EN_U1_1_Duty(ReleaseMotor1_Period);        /*J2_2 to J3_1*/
    }
    else if(direction == Direction_Findhome)
    {	  
	  Set_U3_IN1_PH_U1_85_Duty(duty);                       /*J3_1 to J2_2*/
	  Set_U5_IN2_EN_U1_1_Duty(0);
    }
}
void API_ReleaseMotor2_PWMDuty_Update(uint16_t duty,uint16_t direction)
{
    if(direction == Direction_Release)
    {
	  Set_U3_IN2_EN_U1_86_Duty(ReleaseMotor2_Period - duty);       
	  Set_U4_IN1_PH_U1_81_Duty(ReleaseMotor2_Period);        /*J3_3 to J3_2*/
    }
    else if(direction == Direction_Findhome)
    {	  
	  Set_U3_IN2_EN_U1_86_Duty(duty);                       /*J3_2 to J2_3*/
	  Set_U4_IN1_PH_U1_81_Duty(0);
    }
}

void API_CinchMotor1_BrakeToGround(void)
{
}

void API_CinchMotor1_BrakeToBattery(void)
{
}

void API_CinchMotor2_BrakeToGround(void)
{
}
void API_CinchMotor2_BrakeToBattery(void)
{
}

void API_ReleaseMotor1_BrakeToGround(void)
{
}

void API_ReleaseMotor1_BrakeToBattery(void)
{
}

void API_ReleaseMotor2_BrakeToGround(void)
{
}

void API_ReleaseMotor2_BrakeToBattery(void)
{
}
#endif

#ifdef _CONFIG_DIAG_Hall_StaticDiag
/*********************************************************************************************
** Name:	  API_Set_HallA1_IO_Port
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        100ms
*********************************************************************************************/
void API_Set_HallA1_IO_Port(void)
{
     /*Input Port*/
     PORT.PIBC8 |= _PORT_SET_BIT0; 
     PORT.PMC8 &= _PORT_CLEAR_BIT0; 
}

void API_Set_HallA1_InputCapture_Port(void)
{
     /*Input AUJ0I0*/
     PORT.PIBC8 &= _PORT_CLEAR_BIT0;
     PORT.PMC8 |= _PORT_SET_BIT0;  
}

/*********************************************************************************************
** Name:	  API_Set_HallA2_IO_Port
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        100ms
*********************************************************************************************/
void API_Set_HallA2_IO_Port(void)
{
     /*Input Port*/
     PORT.PIBC8 |= _PORT_SET_BIT3; 
     PORT.PMC8 &= _PORT_CLEAR_BIT3; 
}

void API_Set_HallA2_InputCapture_Port(void)
{
     /*Input AUJ0I0*/
     PORT.PIBC8 &= _PORT_CLEAR_BIT3;
     PORT.PMC8 |= _PORT_SET_BIT3;  
}

/*********************************************************************************************
** Name:	  API_Set_HallB1_IO_Port
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        100ms
*********************************************************************************************/
void API_Set_HallB1_IO_Port(void)
{
     /*Input Port*/
     PORT.PIBC8 |= _PORT_SET_BIT4; 
     PORT.PMC8 &= _PORT_CLEAR_BIT4; 
}

void API_Set_HallB1_InputCapture_Port(void)
{
     /*Input AUJ0I0*/
     PORT.PIBC8 &= _PORT_CLEAR_BIT4;
     PORT.PMC8 |= _PORT_SET_BIT4;  
}

/*********************************************************************************************
** Name:	  API_Set_HallB2_IO_Port
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        100ms
*********************************************************************************************/
void API_Set_HallB2_IO_Port(void)
{
     /*Input Port*/
     PORT.PIBC8 |= _PORT_SET_BIT5; 
     PORT.PMC8 &= _PORT_CLEAR_BIT5; 
}

void API_Set_HallB2_InputCapture_Port(void)
{
     /*Input AUJ0I0*/
     PORT.PIBC8 &= _PORT_CLEAR_BIT5;
     PORT.PMC8 |= _PORT_SET_BIT5;  
}
#endif
/*********************************************************************************************
** End of file
*********************************************************************************************/
