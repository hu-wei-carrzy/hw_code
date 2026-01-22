/********************************************************************************************/

#ifndef __SYSTEM_CALIBRATIONS_H
#define __SYSTEM_CALIBRATIONS_H

//#include "buzzer_control.h"
#include "message_process.h"
//#include "flasher_control.h"
//#include "speed_control.h"
//#include "pinout_manage.h"

#include "S32K144Types.h"

/*********************************************************************************************
** MACROS
**********************************************************************************************/

#define MASK10MS  0x0001U
#define MASK30MS  0x0007U
#define MASK60MS  0x003FU
#define MASK80MS  0x00FFU
#define MASK100MS  0x03FFU

#define MASK01BIT  0x0001U
#define MASK02BIT  0x0003U
#define MASK03BIT  0x0007U
#define MASK10BIT  0x03FFU
#define MASK16BIT  0xFFFFU
#define MASK20BIT  0xFFFFFU
#define MASK32BIT  0xFFFFFFFFU

#define MAXVALUE16BIT  0xFFFFU
#define MAXVALUE12BIT  0xFFFU
#define MAXVALUE10BIT  0x3FFU
#define MAXVALUE08BIT  0xFFU

#define K_Motor1_Current_FilterSampleSize 5
#define K_Motor2_Current_FilterSampleSize 5
#define K_CinchMotor_Current_FilterSampleSize 5
#define K_Motor4_Current_FilterSampleSize 5
#define K_ReleaseMotor_Current_FilterSampleSize 5
#define K_Buzzer_Current_FilterSampleSize 5
#define K_Clutch_Current_FilterSampleSize 5

#define K_VBATT1_FilterSampleSize 5
#define K_VBATT2_FilterSampleSize 5
#define K_Board_Temperature_FilterSampleSize 5
#define K_BoardInclineX_FilterSampleSize 5
#define K_BoardInclineY_FilterSampleSize 5
#define K_BoardInclineZ_FilterSampleSize 5

#define K_ModeSwitchInput_FilterSampleSize 5 
#define K_AntiPinchSensor_FilterSampleSize 5         

#define K_Motor1_P_FilterSampleSize 5
#define K_Motor1_N_FilterSampleSize 5       
#define K_Motor2_P_FilterSampleSize 5  
#define K_Motor2_N_FilterSampleSize 5       

#define K_CinchMotor_P_FilterSampleSize 5 
#define K_CinchMotor_N_FilterSampleSize 5   
#define K_Motor4_P_FilterSampleSize 5 
#define K_Motor4_N_FilterSampleSize 5 

#define K_HallPower1_FilterSampleSize 5 
#define K_HallPower2_FilterSampleSize 5 

#define K_ReleaseMotor_P_FilterSampleSize 5   
#define K_Buzzer_P_FilterSampleSize 5  
#define K_Clutch_P_FilterSampleSize 5 

#define K_VCC2_5V_FilterSampleSize 5                   
#define K_VBATT1_SW_FilterSampleSize 5  
/*Only GEN1_BOARD*/
#define K_PEPS_Wakeup_FilterSampleSize 5             
#define K_IGN_SW_FilterSampleSize 5
/*Only GEN2_BOARD*/
#define K_HS3_OUT_FilterSampleSize 5
#define K_Hall_Power_FilterSampleSize 5
#define K_Buzzer_Power_FilterSampleSize 5

#define K_Flag_Command_Request_TableSize 20
#define K_Flag_Warning_Request_TableSize 20

#define K_Command_Request_Source_TableSize 20
#define K_Flag_ObstacleDetected_TableSize 20
#define K_Flag_Fault_TableSize 20
#define K_Flag_StaticTelltales_TableSize 20
#define K_Flag_DynamicTelltales_TableSize 20
#define K_Flag_Operate_Request_TableSize 20
#define K_Flag_PushDetect_TableSize 20

#define K_Motor1_AverageCurrent_SamplingSize 5
#define K_Motor2_AverageCurrent_SamplingSize 5

#define K_VBATT1_Voltage_Timer 5
#define K_Board_Temperature_Compensation 10

#define K_Motor1_ObstacleIndex 10
#define K_Motor2_ObstacleIndex 10
#define K_Motor1_SpeedZoneIndex 20
#define K_Motor2_SpeedZoneIndex 20


#define K_12Bit_Max_ATD_Value 4096
#define K_10Bit_Max_ATD_Value 1024

#define K_VoltageRatio_Denominator 100

#define K_02V_ATD 200U
#define K_03V_ATD 300U
#define K_04V_ATD 400U
#define K_05V_ATD 500U
#define K_06V_ATD 600U
#define K_07V_ATD 700U
#define K_08V_ATD 800U
#define K_09V_ATD 900U  
#define K_9V5_ATD 950U
#define K_10V_ATD 1000U      
#define K_11V_ATD 1100U      
#define K_12V_ATD 1200U     
#define K_13V_ATD 1300U     
#define K_14V_ATD 1400U     
#define K_15V_ATD 1500U 
#define K_15V5_ATD 1550U 
#define K_16V_ATD 1600U 
#define K_17V_ATD 1700U
#define K_18V_ATD 1800U
#define K_19V_ATD 1900U
#define K_20V_ATD 2000U
#define K_21V_ATD 2100U
#define K_22V_ATD 2200U
#define K_23V_ATD 2300U
#define K_24V_ATD 2400U

#define K_125_Degree 175U
#define K_120_Degree 170U
#define K_115_Degree 165U
#define K_110_Degree 160U
#define K_105_Degree 155U
#define K_100_Degree 150U
#define K_95_Degree 145U
#define K_90_Degree 140U
#define K_85_Degree 135U
#define K_80_Degree 130U
#define K_75_Degree 125U
#define K_70_Degree 120U 
#define K_65_Degree 115U 
#define K_60_Degree 110U
#define K_55_Degree 105U
#define K_50_Degree 100U 
#define K_45_Degree 95U
#define K_40_Degree 90U 
#define K_35_Degree 85U  
#define K_30_Degree 80U 
#define K_25_Degree 75U 
#define K_20_Degree 70U 
#define K_15_Degree 65U 
#define K_10_Degree 60U  
#define K_05_Degree 55U  
#define K_00_Degree 50U 
#define K_N5_Degree 45U
#define K_N10_Degree 40U  
#define K_N15_Degree 35U 
#define K_N20_Degree 30U 
#define K_N25_Degree 25U  
#define K_N30_Degree 20U 
#define K_N35_Degree 15U
#define K_N40_Degree 10U 
#define K_N50_Degree 0U 

#ifdef _MAXUS_COM
#define K_N09_Incline 1894U /*-(sin(9)* 9.8 + 20.47)*100*/
#define K_N05_Incline 1962U /*-(sin(5)* 9.8 + 20.47)*100*/
#define K_N03_Incline 1996U /*-(sin(3)* 9.8 + 20.47)*100*/
#define K_0_Incline 2047U /*(sin(0)* 9.8 + 20.47)*100*/
#define K_03_Incline 2098U /*(sin(3)* 9.8 + 20.47)*100*/
#define K_05_Incline 2132U /*(sin(5)* 9.8 + 20.47)*100*/
#define K_09_Incline 2200U /*(sin(9)* 9.8 + 20.47)*100*/
#endif

#ifdef _DFMC_COM
#define K_N90_Incline 1020U /*(-sin(90)* 980 + 2000)*/
#define K_N11_Incline 1813U /*(-sin(11)* 980 + 2000)*/
#define K_N09_Incline 1847U /*(-sin(9)* 980 + 2000)*/
#define K_N06_Incline 1898U /*(-sin(6)* 980 + 2000)*/
#define K_N05_Incline 1915U /*(-sin(5)* 980 + 2000)*/
#define K_N03_Incline 1949U /*(-sin(3)* 980 + 2000)*/
#define K_N02_Incline 1966U /*(-sin(2)* 980 + 2000)*/
#define K_0_Incline 2000U /*(sin(0)* 980 + 2000)*/
#define K_02_Incline 2034U /*(sin(2)* 980 + 2000)*/
#define K_03_Incline 2051U /*(sin(3)* 980 + 2000)*/
#define K_05_Incline 2085U /*(sin(5)* 980 + 2000)*/
#define K_06_Incline 2102U /*(sin(6)* 980 + 2000)*/
#define K_09_Incline 2153U /*(sin(9)* 980 + 2000)*/
#define K_11_Incline 2187U /*(sin(11)* 980 + 2000)*/
#define K_90_Incline 2980U /*(sin(90)* 980 + 2000)*/
#endif

#ifdef _BAIC_COM
#ifdef _BAIC_COM_C52X
#define K_N90_Incline 1020U /*(-sin(90)* 980 + 2000)*/
#define K_N11_Incline 1813U /*(-sin(11)* 980 + 2000)*/
#define K_N09_Incline 1847U /*(-sin(9)* 980 + 2000)*/
#define K_N06_Incline 1898U /*(-sin(6)* 980 + 2000)*/
#define K_N05_Incline 1915U /*(-sin(5)* 980 + 2000)*/
#define K_N03_Incline 1949U /*(-sin(3)* 980 + 2000)*/
#define K_N02_Incline 1966U /*(-sin(2)* 980 + 2000)*/
#define K_0_Incline 2000U /*(sin(0)* 980 + 2000)*/
#define K_02_Incline 2034U /*(sin(2)* 980 + 2000)*/
#define K_03_Incline 2051U /*(sin(3)* 980 + 2000)*/
#define K_05_Incline 2085U /*(sin(5)* 980 + 2000)*/
#define K_06_Incline 2102U /*(sin(6)* 980 + 2000)*/
#define K_09_Incline 2153U /*(sin(9)* 980 + 2000)*/
#define K_11_Incline 2187U /*(sin(11)* 980 + 2000)*/
#define K_90_Incline 2980U /*(sin(90)* 980 + 2000)*/
#endif

#ifdef _BAIC_COM_C62X
#define K_N09_Incline 739U /*(-sin(9)* 9.8 + 21.5928)*36.86*/
#define K_N05_Incline 764U /*(-sin(5)* 9.8 + 21.5928)*36.86*/
#define K_N03_Incline 777U /*(-sin(3)* 9.8 + 21.5928)*36.86*/
#define K_0_Incline 795U /*(sin(0)* 9.8 + 21.5928)*36.86*/
#define K_03_Incline 814U /*(sin(3)* 9.8 + 21.5928)*36.86*/
#define K_05_Incline 827U /*(sin(5)* 9.8 + 21.5928)*36.86*/
#define K_09_Incline 852U /*(sin(9)* 9.8 + 21.5928)*36.86*/
#endif
#ifdef _BAIC_COM_C46DB
#define K_N90_Incline 1020U /*(-sin(90)* 980 + 2000)*/
#define K_N11_Incline 1813U /*(-sin(11)* 980 + 2000)*/
#define K_N09_Incline 1847U /*(-sin(9)* 980 + 2000)*/
#define K_N06_Incline 1898U /*(-sin(6)* 980 + 2000)*/
#define K_N05_Incline 1915U /*(-sin(5)* 980 + 2000)*/
#define K_N03_Incline 1949U /*(-sin(3)* 980 + 2000)*/
#define K_N02_Incline 1966U /*(-sin(2)* 980 + 2000)*/
#define K_0_Incline 2000U /*(sin(0)* 980 + 2000)*/
#define K_02_Incline 2034U /*(sin(2)* 980 + 2000)*/
#define K_03_Incline 2051U /*(sin(3)* 980 + 2000)*/
#define K_05_Incline 2085U /*(sin(5)* 980 + 2000)*/
#define K_06_Incline 2102U /*(sin(6)* 980 + 2000)*/
#define K_09_Incline 2153U /*(sin(9)* 980 + 2000)*/
#define K_11_Incline 2187U /*(sin(11)* 980 + 2000)*/
#define K_90_Incline 2980U /*(sin(90)* 980 + 2000)*/
#endif
#ifdef _BAIC_COM_B30X
#define K_N90_Incline 1020U /*(-sin(90)* 980 + 2000)*/
#define K_N11_Incline 1813U /*(-sin(11)* 980 + 2000)*/
#define K_N09_Incline 1847U /*(-sin(9)* 980 + 2000)*/
#define K_N06_Incline 1898U /*(-sin(6)* 980 + 2000)*/
#define K_N05_Incline 1915U /*(-sin(5)* 980 + 2000)*/
#define K_N03_Incline 1949U /*(-sin(3)* 980 + 2000)*/
#define K_N02_Incline 1966U /*(-sin(2)* 980 + 2000)*/
#define K_0_Incline 2000U /*(sin(0)* 980 + 2000)*/
#define K_02_Incline 2034U /*(sin(2)* 980 + 2000)*/
#define K_03_Incline 2051U /*(sin(3)* 980 + 2000)*/
#define K_05_Incline 2085U /*(sin(5)* 980 + 2000)*/
#define K_06_Incline 2102U /*(sin(6)* 980 + 2000)*/
#define K_09_Incline 2153U /*(sin(9)* 980 + 2000)*/
#define K_11_Incline 2187U /*(sin(11)* 980 + 2000)*/
#define K_90_Incline 2980U /*(sin(90)* 980 + 2000)*/
#endif
#ifdef _BAIC_COM_N51AB
#define K_N90_Incline 1020U /*(-sin(90)* 980 + 2000)*/
#define K_N11_Incline 1813U /*(-sin(11)* 980 + 2000)*/
#define K_N09_Incline 1847U /*(-sin(9)* 980 + 2000)*/
#define K_N06_Incline 1898U /*(-sin(6)* 980 + 2000)*/
#define K_N05_Incline 1915U /*(-sin(5)* 980 + 2000)*/
#define K_N03_Incline 1949U /*(-sin(3)* 980 + 2000)*/
#define K_N02_Incline 1966U /*(-sin(2)* 980 + 2000)*/
#define K_0_Incline 2000U /*(sin(0)* 980 + 2000)*/
#define K_02_Incline 2034U /*(sin(2)* 980 + 2000)*/
#define K_03_Incline 2051U /*(sin(3)* 980 + 2000)*/
#define K_05_Incline 2085U /*(sin(5)* 980 + 2000)*/
#define K_06_Incline 2102U /*(sin(6)* 980 + 2000)*/
#define K_09_Incline 2153U /*(sin(9)* 980 + 2000)*/
#define K_11_Incline 2187U /*(sin(11)* 980 + 2000)*/
#define K_90_Incline 2980U /*(sin(90)* 980 + 2000)*/
#endif
#endif

#ifdef _DFLZM_COM
#define K_N90_Incline 1020U /*(-sin(90)* 980 + 2000)*/
#define K_N11_Incline 1813U /*(-sin(11)* 980 + 2000)*/
#define K_N09_Incline 1847U /*(-sin(9)* 980 + 2000)*/
#define K_N06_Incline 1898U /*(-sin(6)* 980 + 2000)*/
#define K_N05_Incline 1915U /*(-sin(5)* 980 + 2000)*/
#define K_N03_Incline 1949U /*(-sin(3)* 980 + 2000)*/
#define K_N02_Incline 1966U /*(-sin(2)* 980 + 2000)*/
#define K_0_Incline 2000U /*(sin(0)* 980 + 2000)*/
#define K_02_Incline 2034U /*(sin(2)* 980 + 2000)*/
#define K_03_Incline 2051U /*(sin(3)* 980 + 2000)*/
#define K_05_Incline 2085U /*(sin(5)* 980 + 2000)*/
#define K_06_Incline 2102U /*(sin(6)* 980 + 2000)*/
#define K_09_Incline 2153U /*(sin(9)* 980 + 2000)*/
#define K_11_Incline 2187U /*(sin(11)* 980 + 2000)*/
#define K_90_Incline 2980U /*(sin(90)* 980 + 2000)*/
#endif

#ifdef _NIU_COM
#define K_N09_Incline 1894U /*-(sin(9)* 9.8 + 20.47)*100*/
#define K_N05_Incline 1962U /*-(sin(5)* 9.8 + 20.47)*100*/
#define K_N03_Incline 1996U /*-(sin(3)* 9.8 + 20.47)*100*/
#define K_0_Incline 2047U /*(sin(0)* 9.8 + 20.47)*100*/
#define K_03_Incline 2098U /*(sin(3)* 9.8 + 20.47)*100*/
#define K_05_Incline 2132U /*(sin(5)* 9.8 + 20.47)*100*/
#define K_09_Incline 2200U /*(sin(9)* 9.8 + 20.47)*100*/
#endif
#ifdef _FAW_COM
#define K_N09_Incline 1894U /*-(sin(9)* 9.8 + 20.47)*100*/
#define K_N05_Incline 1962U /*-(sin(5)* 9.8 + 20.47)*100*/
#define K_N03_Incline 1996U /*-(sin(3)* 9.8 + 20.47)*100*/
#define K_0_Incline 2047U /*(sin(0)* 9.8 + 20.47)*100*/
#define K_03_Incline 2098U /*(sin(3)* 9.8 + 20.47)*100*/
#define K_05_Incline 2132U /*(sin(5)* 9.8 + 20.47)*100*/
#define K_09_Incline 2200U /*(sin(9)* 9.8 + 20.47)*100*/
#endif


#ifdef _CHERY_COM
#define K_N90_Incline 1020U /*(-sin(90)* 980 + 2000)*/
#define K_N11_Incline 1813U /*(-sin(11)* 980 + 2000)*/
#define K_N09_Incline 1847U /*(-sin(9)* 980 + 2000)*/
#define K_N06_Incline 1898U /*(-sin(6)* 980 + 2000)*/
#define K_N05_Incline 1915U /*(-sin(5)* 980 + 2000)*/
#define K_N03_Incline 1949U /*(-sin(3)* 980 + 2000)*/
#define K_N02_Incline 1966U /*(-sin(2)* 980 + 2000)*/
#define K_0_Incline 2000U /*(sin(0)* 980 + 2000)*/
#define K_02_Incline 2034U /*(sin(2)* 980 + 2000)*/
#define K_03_Incline 2051U /*(sin(3)* 980 + 2000)*/
#define K_05_Incline 2085U /*(sin(5)* 980 + 2000)*/
#define K_06_Incline 2102U /*(sin(6)* 980 + 2000)*/
#define K_09_Incline 2153U /*(sin(9)* 980 + 2000)*/
#define K_11_Incline 2187U /*(sin(11)* 980 + 2000)*/
#define K_90_Incline 2980U /*(sin(90)* 980 + 2000)*/
#endif

#ifdef _VOYAH_COM
#define K_N90_Incline 1020U /*(-sin(90)* 980 + 2000)*/
#define K_N11_Incline 1813U /*(-sin(11)* 980 + 2000)*/
#define K_N09_Incline 1847U /*(-sin(9)* 980 + 2000)*/
#define K_N06_Incline 1898U /*(-sin(6)* 980 + 2000)*/
#define K_N05_Incline 1915U /*(-sin(5)* 980 + 2000)*/
#define K_N03_Incline 1949U /*(-sin(3)* 980 + 2000)*/
#define K_N02_Incline 1966U /*(-sin(2)* 980 + 2000)*/
#define K_0_Incline 2000U /*(sin(0)* 980 + 2000)*/
#define K_02_Incline 2034U /*(sin(2)* 980 + 2000)*/
#define K_03_Incline 2051U /*(sin(3)* 980 + 2000)*/
#define K_05_Incline 2085U /*(sin(5)* 980 + 2000)*/
#define K_06_Incline 2102U /*(sin(6)* 980 + 2000)*/
#define K_09_Incline 2153U /*(sin(9)* 980 + 2000)*/
#define K_11_Incline 2187U /*(sin(11)* 980 + 2000)*/
#define K_90_Incline 2980U /*(sin(90)* 980 + 2000)*/
#endif

#ifdef _AUDI_COM
#define K_N90_Incline 1020U /*(-sin(90)* 980 + 2000)*/
#define K_N11_Incline 1813U /*(-sin(11)* 980 + 2000)*/
#define K_N09_Incline 1847U /*(-sin(9)* 980 + 2000)*/
#define K_N06_Incline 1898U /*(-sin(6)* 980 + 2000)*/
#define K_N05_Incline 1915U /*(-sin(5)* 980 + 2000)*/
#define K_N03_Incline 1949U /*(-sin(3)* 980 + 2000)*/
#define K_N02_Incline 1966U /*(-sin(2)* 980 + 2000)*/
#define K_0_Incline 2000U /*(sin(0)* 980 + 2000)*/
#define K_02_Incline 2034U /*(sin(2)* 980 + 2000)*/
#define K_03_Incline 2051U /*(sin(3)* 980 + 2000)*/
#define K_05_Incline 2085U /*(sin(5)* 980 + 2000)*/
#define K_06_Incline 2102U /*(sin(6)* 980 + 2000)*/
#define K_09_Incline 2153U /*(sin(9)* 980 + 2000)*/
#define K_11_Incline 2187U /*(sin(11)* 980 + 2000)*/
#define K_90_Incline 2980U /*(sin(90)* 980 + 2000)*/
#endif


#define K_Incline_N90_Degree  0
#define K_Incline_N11_Degree  790
#define K_Incline_N10_Degree  800
#define K_Incline_N09_Degree  810
#define K_Incline_N08_Degree  820
#define K_Incline_N06_Degree  840
#define K_Incline_N04_Degree  860
#define K_Incline_N03_Degree  870
#define K_Incline_N02_Degree  880
#define K_Incline_0_Degree    900  /* 10 = 1 degree*/
#define K_Incline_02_Degree   920
#define K_Incline_03_Degree   930
#define K_Incline_04_Degree   940
#define K_Incline_06_Degree   960
#define K_Incline_08_Degree   980
#define K_Incline_09_Degree   990
#define K_Incline_10_Degree   1000
#define K_Incline_11_Degree   1010
#define K_Incline_90_Degree   1800

#define K_Incline_10_Degree_Delta  100
#define K_Incline_11_Degree_Delta  110

#define K_Incline_Degree_Denominator 10
#define K_Incline_Degree_Ratio_Denominator 100
#define K_Incline_Degree_Denominator 10

#define K_Sin1000Times_Denominator 1000
#define K_Cos1000Times_Denominator 1000
#define K_Incline_Degree_CosSin_Denominator 1000
#define K_DoorPosition_Angle_Denominator 10

#define K_DoorIncline_80_Force_Delta  800
#define K_DoorIncline_Force_Ratio_Denominator  100
#define K_VehicleIncline_Force_Ratio_Denominator  100
#define K_MotorHold_HallSpeedVoltage_DoorIncline_Max 4000

#define K_DoorIncline_N100_Force  9000
#define K_DoorIncline_N90_Force   9100
#define K_DoorIncline_N80_Force   9200
#define K_DoorIncline_N70_Force   9300
#define K_DoorIncline_N60_Force   9400
#define K_DoorIncline_N50_Force   9500
#define K_DoorIncline_N40_Force   9600
#define K_DoorIncline_N30_Force   9700
#define K_DoorIncline_N20_Force   9800
#define K_DoorIncline_N10_Force   9900
#define K_DoorIncline_0_Force     10000 /*100 = 1kg = 10N*/
#define K_DoorIncline_10_Force    10100
#define K_DoorIncline_20_Force    10200
#define K_DoorIncline_30_Force    10300
#define K_DoorIncline_40_Force    10400
#define K_DoorIncline_50_Force    10500
#define K_DoorIncline_60_Force    10600
#define K_DoorIncline_70_Force    10700
#define K_DoorIncline_80_Force    10800
#define K_DoorIncline_90_Force    10900
#define K_DoorIncline_100_Force   11000

#define K_BusInclineX_Default K_0_Incline
#define K_BusInclineY_Default K_0_Incline
#define K_BusInclineZ_Default K_N90_Incline

#define K_BusInclineX_Degree_Default K_Incline_0_Degree
#define K_BusInclineY_Degree_Default K_Incline_0_Degree
#define K_BusInclineZ_Degree_Default K_Incline_N90_Degree

#define K_BoardInclineX_Default K_0_Incline
#define K_BoardInclineY_Default K_0_Incline
#define K_BoardInclineZ_Default K_N90_Incline

#define K_BoardInclineX_Degree_Default K_Incline_0_Degree
#define K_BoardInclineY_Degree_Default K_Incline_0_Degree
#define K_BoardInclineZ_Degree_Default K_Incline_N90_Degree

#define K_BoardInclineX_Offset_Default 0
#define K_BoardInclineY_Offset_Default 0
#define K_BoardInclineZ_Offset_Default 0


#ifdef _CONFIG_Gen1_Board
#define K_125_Degree_Value 195U
#define K_120_Degree_Value 219U
#define K_115_Degree_Value 247U
#define K_110_Degree_Value 279U
#define K_105_Degree_Value 316U
#define K_100_Degree_Value 358U
#define K_95_Degree_Value 405U
#define K_90_Degree_Value 459U
#define K_85_Degree_Value 519U
#define K_80_Degree_Value 587U
#define K_75_Degree_Value 662U
#define K_70_Degree_Value 748U 
#define K_65_Degree_Value 844U 
#define K_60_Degree_Value 952U
#define K_55_Degree_Value 1072U
#define K_50_Degree_Value 1204U 
#define K_45_Degree_Value 1350U
#define K_40_Degree_Value 1508U 
#define K_35_Degree_Value 1678U  
#define K_30_Degree_Value 1859U 
#define K_25_Degree_Value 2048U 
#define K_20_Degree_Value 2244U 
#define K_15_Degree_Value 2440U 
#define K_10_Degree_Value 2636U  
#define K_05_Degree_Value 2827U  
#define K_00_Degree_Value 3008U 
#define K_N5_Degree_Value 3176U
#define K_N10_Degree_Value 3330U  
#define K_N15_Degree_Value 3467U 
#define K_N20_Degree_Value 3586U 
#define K_N25_Degree_Value 3689U  
#define K_N30_Degree_Value 3776U 
#define K_N35_Degree_Value 3847U
#define K_N40_Degree_Value 3906U 
#endif
#if defined(_CONFIG_Gen2_Board) || defined(_CONFIG_Gen3_Board) || defined(_CONFIG_Gen4_Board)
#define K_125_Degree_Value 105U
#define K_120_Degree_Value 119U
#define K_115_Degree_Value 133U
#define K_110_Degree_Value 150U
#define K_105_Degree_Value 168U
#define K_100_Degree_Value 190U
#define K_95_Degree_Value 215U
#define K_90_Degree_Value 244U
#define K_85_Degree_Value 277U
#define K_80_Degree_Value 315U
#define K_75_Degree_Value 360U
#define K_70_Degree_Value 410U 
#define K_65_Degree_Value 469U 
#define K_60_Degree_Value 536U
#define K_55_Degree_Value 615U
#define K_50_Degree_Value 705U 
#define K_45_Degree_Value 808U
#define K_40_Degree_Value 925U 
#define K_35_Degree_Value 1056U  
#define K_30_Degree_Value 1203U 
#define K_25_Degree_Value 1365U 
#define K_20_Degree_Value 1542U 
#define K_15_Degree_Value 1733U 
#define K_10_Degree_Value 1936U  
#define K_05_Degree_Value 2147U  
#define K_00_Degree_Value 2361U 
#define K_N5_Degree_Value 2576U
#define K_N10_Degree_Value 2785U  
#define K_N15_Degree_Value 2984U 
#define K_N20_Degree_Value 3168U 
#define K_N25_Degree_Value 3334U  
#define K_N30_Degree_Value 3482U 
#define K_N35_Degree_Value 3609U
#define K_N40_Degree_Value 3716U 
#endif







/*********************************************************************************************
**   Pinout manage
*********************************************************************************************/
extern const uint16_t K_AntiPinchATD_OnePressed_LowLimit;
extern const uint16_t K_AntiPinchATD_OnePressed_HighLimit;

extern const uint16_t K_AntiPinchATD_TwoPressed_LowLimit;
extern const uint16_t K_AntiPinchATD_TwoPressed_HighLimit;

extern const uint16_t K_AntiPinchRightATD_OnePressed_LowLimit;
extern const uint16_t K_AntiPinchRightATD_OnePressed_HighLimit;

extern const uint16_t K_AntiPinchLeftATD_OnePressed_LowLimit;
extern const uint16_t K_AntiPinchLeftATD_OnePressed_HighLimit;

extern const uint16_t K_PawlSwitch_HallEffect_Active_LowLimit;
extern const uint16_t K_PawlSwitch_HallEffect_Active_HighLimit;

extern const uint16_t K_PawlSwitch_HallEffect_Inactive_LowLimit;
extern const uint16_t K_PawlSwitch_HallEffect_Inactive_HighLimit;

extern const uint16_t K_PositionSwitch_HallEffect_Active_LowLimit;
extern const uint16_t K_PositionSwitch_HallEffect_Active_HighLimit;

extern const uint16_t K_PositionSwitch_HallEffect_Inactive_LowLimit;
extern const uint16_t K_PositionSwitch_HallEffect_Inactive_HighLimit;

extern const uint16_t K_ModeSwitchInput_Ratio_Denominator;
extern const uint16_t K_NormalSwitchRatio_LowLimit;  /* Ratio */
extern const uint16_t K_NormalSwitchRatio_HighLimit;  /* Ratio */

extern const uint16_t K_GarageSwitchRatio_LowLimit;  /* Ratio */
extern const uint16_t K_GarageSwitchRatio_HighLimit;  /* Ratio */

extern const uint16_t K_DisableSwitchRatio_LowLimit;  /* Ratio */
extern const uint16_t K_DisableSwitchRatio_HighLimit;  /* Ratio */

extern const uint16_t K_NormalSwitchInput_Voltage_LowLimit;
extern const uint16_t K_NormalSwitchInput_Voltage_HighLimit;
extern const uint16_t K_GarageSwitchInput_Voltage_LowLimit;
extern const uint16_t K_GarageSwitchInput_Voltage_HighLimit;
extern const uint16_t K_DisableSwitchInput_Voltage_LowLimit;
extern const uint16_t K_DisableSwitchInput_Voltage_HighLimit;



extern const uint16_t K_HandleHandFreeShareSwitch_ShortPress_LowLimit_Time;
extern const uint16_t K_HandleHandFreeShareSwitch_ShortPress_HighLimit_Time;
extern const uint16_t K_HandleHandFreeShareSwitch_LongPress_LowLimit_Time;
extern const uint16_t K_HandleHandFreeShareSwitch_LongPress_HighLimit_Time;

extern const uint16_t K_HandleOpenSwitch_ShortPress_LowLimit_Time;
extern const uint16_t K_HandleOpenSwitch_ShortPress_HighLimit_Time;
extern const uint16_t K_HandleOpenSwitch_LongPress_LowLimit_Time;
extern const uint16_t K_HandleOpenSwitch_LongPress_HighLimit_Time;

extern const uint16_t K_HandleCloseSwitch_ShortPress_LowLimit_Time;
extern const uint16_t K_HandleCloseSwitch_ShortPress_HighLimit_Time;
extern const uint16_t K_HandleCloseSwitch_LongPress_LowLimit_Time;
extern const uint16_t K_HandleCloseSwitch_LongPress_HighLimit_Time;

extern const uint16_t K_BrakeSwitch_ShortPress_LowLimit_Time;
extern const uint16_t K_BrakeSwitch_ShortPress_HighLimit_Time;
extern const uint16_t K_BrakeSwitch_LongPress_LowLimit_Time;
extern const uint16_t K_BrakeSwitch_LongPress_HighLimit_Time;



extern const uint16_t K_Current_Value_PerOneAmp;

extern const uint16_t K_Motor1_High_Range_Current; 
extern const uint16_t K_Motor2_High_Range_Current; 

extern const uint16_t K_Motor1_Current_Range_Count;
extern const uint16_t K_Motor2_Current_Range_Count;

extern const uint16_t K_Motor1_Low_Range_Current; 
extern const uint16_t K_Motor2_Low_Range_Current; 

extern const uint16_t K_ReleaseMotor_Buzzer_Clutch_CurrentSensor_Time;

extern const uint16_t K_Motor1_FET_Base_Offset_Value_Default;
extern const uint16_t K_Motor1_FET_Cal_Ratio_Value_Default;
extern const uint16_t K_Motor1_FET_Cal_Ratio_Denominator;

extern const uint16_t K_Motor2_FET_Base_Offset_Value_Default;
extern const uint16_t K_Motor2_FET_Cal_Ratio_Value_Default;
extern const uint16_t K_Motor2_FET_Cal_Ratio_Denominator;

extern const uint16_t K_CinchMotor_FET_Base_Offset_Value_Default;
extern const uint16_t K_CinchMotor_FET_Cal_Ratio_Value_Default;
extern const uint16_t K_CinchMotor_FET_Cal_Ratio_Denominator;

extern const uint16_t K_Motor4_FET_Base_Offset_Value_Default;
extern const uint16_t K_Motor4_FET_Cal_Ratio_Value_Default;
extern const uint16_t K_Motor4_FET_Cal_Ratio_Denominator;

extern const uint16_t K_ReleaseMotor_FET_Base_Offset_Value_Default;
extern const uint16_t K_ReleaseMotor_FET_Cal_Ratio_Value_Default;
extern const uint16_t K_ReleaseMotor_FET_Cal_Ratio_Denominator;

extern const uint16_t K_Buzzer_FET_Base_Offset_Value_Default;
extern const uint16_t K_Buzzer_FET_Cal_Ratio_Value_Default;
extern const uint16_t K_Buzzer_FET_Cal_Ratio_Denominator;

extern const uint16_t K_Clutch_FET_Base_Offset_Value_Default;
extern const uint16_t K_Clutch_FET_Cal_Ratio_Value_Default;
extern const uint16_t K_Clutch_FET_Cal_Ratio_Denominator;

extern const uint16_t K_Motor1_Current_Voltage_Value_Diagnostic_Threshold;
extern const uint16_t K_Motor2_Current_Voltage_Value_Diagnostic_Threshold;
extern const uint16_t K_CinchMotor_Current_Voltage_Value_Diagnostic_Threshold;
extern const uint16_t K_ReleaseMotor_Current_Voltage_Value_Diagnostic_Threshold;
extern const uint16_t K_Buzzer_Current_Voltage_Value_Diagnostic_Threshold;
extern const uint16_t K_Clutch_Current_Voltage_Value_Diagnostic_Threshold;

extern const uint16_t K_AnalogInputDebounce_Start_Time;
extern const uint16_t K_Pinout_Initial_End_Time;




/*********************************************************************************************
**    Latch Control
*********************************************************************************************/
extern const uint16_t K_LatchPowerOn_Time; 
extern const uint16_t K_LatchWakeUp_Time;
extern const uint16_t K_LatchReset_Time;

extern const uint16_t K_PowerCinchInSecondPosition_AfterPowerUp_Enable;
extern const uint16_t K_LatchPreCinchCheck_Timeout;
extern const uint16_t K_LatchPreCinchCheck_Timeout_LongDelay;
extern const uint16_t K_LatchPowerCinching_Timeout;
extern const uint16_t K_LatchFindHomeAfterCinch_Timeout;
extern const uint16_t K_LatchPreReleasing_Timeout;
extern const uint16_t K_LatchPowerReleasing_Timeout;
extern const uint16_t K_LatchFindHomeAfterRelease_Timeout;
extern const uint16_t K_LatchFindHomeAfterRelease_Mini_Time;

extern const uint16_t K_LatchFindHomeReleaseDirection_Timeout;
extern const uint16_t K_LatchFindHomeCinchDirection_Timeout;
extern const uint16_t K_LatchFindHomeReleaseMotor_Timeout;
extern const uint16_t K_LatchFindHomeAfterPark_Timeout;
extern const uint16_t K_LatchFindHomeAfterBlip_Timeout;

extern const uint16_t K_LatchPreReleased_Timeout; 
extern const uint16_t K_LatchPreReleased_Timeout_LongDelay;
extern const uint16_t K_LatchPreRelease_SnowLoad_Time;
extern const uint16_t K_LatchCrankWait_Timeout;
extern const uint16_t K_LatchMechFailure_Timeout;
extern const uint16_t K_LatchIceBreaking_Timeout;
extern const uint16_t K_LatchFindHomeAfterIceBreak_Timeout;
extern const uint16_t K_LatchUnlock_Timeout;
extern const uint16_t K_LatchUnlockReset_Timeout;
extern const uint16_t K_SnowLoad_Timeout_PowerCinching_Delay_Time;

extern const uint16_t K_WaitForPowerCinching_Time;
extern const uint16_t K_PreReleasing_Strike_Prework_FromHome_Time;
extern const uint16_t K_PreReleasing_Strike_Prework_FromMiddle_Time;

extern const uint16_t K_PowerCinching_Duration_Min_Time;
extern const uint16_t K_PowerCinching_Duration_Max_Time;

extern const uint16_t K_LatchPreCinchCheck_Time;
extern const uint16_t K_LatchPreCinchCheck_Time_LongDelay;
extern const uint16_t K_PowerCinching_Delay_Time;
extern const uint16_t K_PowerReleasing_PawlSwitch_Delay_Time;
extern const uint16_t K_PowerReleasing_OutofLatch_Delay_Time;
extern const uint16_t K_PreReleased_OutofLatch_Delay_Time;
extern const uint16_t K_IceBreaking_OutofLatch_Delay_Time;
extern const uint16_t K_FindHomeAfterPark_PositionSwitch_Delay_Time;
extern const uint16_t K_PreReleasing_PositionSwitch_Delay_Time;
extern const uint16_t K_PowerUnlock_UnlockSwitch_Delay_Time;
extern const uint16_t K_PowerLock_UnlockSwitch_Delay_Time;

extern const uint16_t K_CinchMotor_IncreaseStep_Duty;
extern const uint16_t K_CinchMotor_DecreaseStep_Duty;
extern const uint16_t K_ReleaseMotor_IncreaseStep_Duty;
extern const uint16_t K_ReleaseMotor_DecreaseStep_Duty;

extern const uint16_t K_StopBeforePowerReleasing_Time;
extern const uint16_t K_StopBeforePowerReleasing_CinchMotorBrake_Time;
extern const uint16_t K_StopBeforePreReleasing_Time;
extern const uint16_t K_StopBeforeFindHomeAfterRelease_Time;
extern const uint16_t K_StopBeforeFindHomeAfterPark_Time;
extern const uint16_t K_StopBeforeFindHomeAfterBlip_Time;
extern const uint16_t K_StopBeforeIceBreaking_Time;
extern const uint16_t K_StopBeforeFindHomeAfterIceBreak_Time;

extern const uint16_t K_MiniWorkingInCinchDirection_Time;
extern const uint16_t K_ContinueFindHomeAfterRelease_Time;
extern const uint16_t K_ContinueFindHomeAfterIceBreak_Time;
extern const uint16_t K_StopBeforeFindHomeReleaseMotor_Time;
extern const uint16_t K_ChangeDutyInFindHomeAfterRelease_Time;
extern const uint16_t K_ChangeDutyInFindHomeAfterRelease_Time_2nd;
extern const uint16_t K_ChangeDutyInFindHomeAfterRelease_Time_3rd;

extern const uint16_t K_StopBeforeFindHomeCinchDirection_Time;
extern const uint16_t K_StopBeforeFindHomeReleaseDirection_Time;
extern const uint16_t K_LatchFindHomeFailure_Timeout;

extern const uint16_t K_FindHomeReleaseDirection_Inrush_Time;
extern const uint16_t K_FindHomeCinchDirection_Inrush_Time;
extern const uint16_t K_FindHomeReleaseMotor_Inrush_Time;
extern const uint16_t K_PowerCinching_Inrush_Time;
extern const uint16_t K_FindHomeAfterCinch_Inrush_Time;
extern const uint16_t K_FindHomeAfterPark_Inrush_Time;
extern const uint16_t K_PreReleasing_Inrush_Time;
extern const uint16_t K_PowerReleasing_Inrush_Time;
extern const uint16_t K_FindHomeAfterRelease_Inrush_Time;
extern const uint16_t K_IceBreaking_Inrush_Time;
extern const uint16_t K_FindHomeAfterIceBreak_Inrush_Time;
extern const uint16_t K_PowerUnlock_Inrush_Time;

extern const uint16_t K_PowerReleasing_Mini_Time;
extern const uint16_t K_PreReleased_Mini_Time;
extern const uint16_t K_PowerUnlock_Mini_Time;
extern const uint16_t K_PowerUnlockReset_Mini_Time;

extern const uint16_t K_CinchMotorFindHome_Count;

extern const uint16_t K_FindHomeAfterCinch_StartDuty_Time;
extern const uint16_t K_FindHomeAfterCinch_DecreaseDuty_Time;
extern const uint16_t K_FindHomeAfterCinch_IncreaseDuty_Time;

extern const uint16_t K_CinchMotor_PowerCinching_Duty;
extern const uint16_t K_CinchMotor_PowerCinching_Duty_2nd;
extern const uint16_t K_CinchMotor_PowerCinching_Duty_2nd_LongDelay; 
extern const uint16_t K_CinchMotor_PowerCinching_Duty_3rd;

extern const uint16_t K_ChangeDutyInPowerCinching_Time;
extern const uint16_t K_ChangeDutyInPowerCinching_Time_2nd;
extern const uint16_t K_CinchMotor_FindHomeAfterCinch_Duty;
extern const uint16_t K_CinchMotor_FindHomeAfterCinch_Duty_2nd;
extern const uint16_t K_CinchMotor_FindHomeAfterCinch_Duty_3rd;
extern const uint16_t K_CinchMotor_PreReleasing_Duty;

extern const uint16_t K_CinchMotor_FindHomeAfterRelease_Duty;
extern const uint16_t K_CinchMotor_FindHomeAfterRelease_Duty_2nd;
extern const uint16_t K_CinchMotor_FindHomeAfterRelease_Duty_3rd;

extern const uint16_t K_CinchMotor_FindHomeReleaseDirection_Duty;
extern const uint16_t K_CinchMotor_FindHomeReleaseDirection_Duty_2nd;
extern const uint16_t K_CinchMotor_FindHomeCinchDirection_Duty;
extern const uint16_t K_CinchMotor_FindHomeCinchDirection_Duty_2nd;

extern const uint16_t K_CinchMotor_FindHomeAfterPark_Duty;
extern const uint16_t K_CinchMotor_FindHomeAfterBlip_Duty;

extern const uint16_t K_CinchMotor_IceBreaking_Duty;
extern const uint16_t K_CinchMotor_IceBreaking_Duty_2nd;
extern const uint16_t K_CinchMotor_IceBreaking_Duty_3rd;
extern const uint16_t K_CinchMotor_FindHomeAfterIceBreak_Duty;
extern const uint16_t K_CinchMotor_FindHomeAfterIceBreak_Duty_2nd;

extern const uint16_t K_ReleaseMotor_FindHomeAfterRelease_Duty;
extern const uint16_t K_ReleaseMotor_FindHomeAfterRelease_Duty_2nd;
extern const uint16_t K_ReleaseMotor_FindHomeAfterRelease_Duty_3rd;
extern const uint16_t K_ReleaseMotor_FindHomeAfterRelease_Duty_4th;

extern const uint16_t K_ReleaseMotor_FindHomeReleaseMotor_Duty;
extern const uint16_t K_ReleaseMotor_FindHomeReleaseMotor_Duty_2nd;

extern const uint16_t K_ContinueParking_Time;
extern const uint16_t K_ContinueParking_Time_2nd;

extern const uint16_t K_ReleaseMotor_PowerReleasing_Duty;
extern const uint16_t K_ReleaseMotor_PowerReleasing_Duty_2nd;
extern const uint16_t K_CinchMotor_PowerReleasing_Duty;
extern const uint16_t K_CinchMotor_PowerReleasing_Duty_2nd;

extern const uint16_t K_ReleaseMotor_PowerUnlock_Duty;
extern const uint16_t K_ReleaseMotor_PowerUnlock_Duty_2nd;
extern const uint16_t K_ReleaseMotor_PowerUnlockReset_Duty;
extern const uint16_t K_ReleaseMotor_PowerUnlockReset_Duty_2nd;

extern const uint16_t K_PowerReleasing_ComfirmCurrent;

extern const uint16_t K_PowerCinching_SoftStall_Current;
extern const uint16_t K_FindHomeAfterCinch_SoftStall_Current;
extern const uint16_t K_PreReleasing_SoftStall_Current;
extern const uint16_t K_PowerReleasing_SoftStall_Current;
extern const uint16_t K_FindHomeAfterRelease_SoftStall_Current;
extern const uint16_t K_FindHomeAfterPark_SoftStall_Current;

extern const uint16_t K_FindHomeReleaseDirection_SoftStall_Current;
extern const uint16_t K_FindHomeCinchDirection_SoftStall_Current;
extern const uint16_t K_FindHomeReleaseMotor_SoftStall_Current;
extern const uint16_t K_IceBreaking_SoftStall_Current;
extern const uint16_t K_FindHomeAfterIceBreak_SoftStall_Current;

extern const uint16_t K_PowerCinching_SoftStall_Time; 
extern const uint16_t K_FindHomeAfterCinch_SoftStall_Time; 
extern const uint16_t K_FindHomeReleaseMotor_SoftStall_Time;
extern const uint16_t K_PreReleasing_SoftStall_Time; 
extern const uint16_t K_PowerReleasing_SoftStall_Time; 
extern const uint16_t K_FindHomeAfterRelease_SoftStall_Time;
extern const uint16_t K_FindHomeReleaseDirection_SoftStall_Time;
extern const uint16_t K_FindHomeCinchDirection_SoftStall_Time;
extern const uint16_t K_FindHomeAfterPark_SoftStall_Time;
extern const uint16_t K_IceBreaking_SoftStall_Time;
extern const uint16_t K_FindHomeAfterIceBreak_SoftStall_Time;

extern const uint16_t K_PrimaryPositionIsArrived_Time;
extern const uint16_t K_StopBeforeFindHomeAfterCinch_Time;
extern const uint16_t K_LatchNotLeaveHomeInMiniPowerCinch_Time;
extern const uint16_t K_LatchNotLeaveHomeInMiniIceBreak_Time;

extern const uint16_t K_ChangeDutyInFindHomeAfterCinch_Time;
extern const uint16_t K_ChangeDutyInFindHomeAfterCinch_Time_2nd;
extern const uint16_t K_ChangeDutyInIceBreaking_Time;
extern const uint16_t K_ChangeDutyInIceBreaking_Time_2nd;
extern const uint16_t K_ChangeDutyInFindHomeAfterIceBreak_Time;

extern const uint16_t K_LowDutyFailFindHomeAfterCinch_Time;
extern const uint16_t K_LowDutyFailFindHomeAfterCinch_Duty; 
extern const uint16_t K_LowDutyFailPowerCinching_Time;
extern const uint16_t K_LowDutyFailPowerCinching_Duty;
extern const uint16_t K_LowDutyFailIceBreaking_Time;
extern const uint16_t K_LowDutyFailIceBreaking_Duty;
extern const uint16_t K_LowDutyFailFindHomeAfterIceBreak_Time;
extern const uint16_t K_LowDutyFailFindHomeAfterIceBreak_Duty;

extern const uint16_t K_PowerReleasing_ComfirmCurrent_Time;
extern const uint16_t K_FindHomeAfterCinch_Work_MiniTime;
extern const uint16_t K_AjarSwitchConfirm_Time;

extern const uint16_t K_ChangeDutyInFindHomeReleaseDirection_Time;
extern const uint16_t K_ChangeDutyInFindHomeCinchDirection_Time;
extern const uint16_t K_ChangeDutyInFindHomeReleaseMotor_Time;
extern const uint16_t K_LatchFullyReleased_Braking_Timeout;
extern const uint16_t K_LatchFullyCinched_Braking_Timeout;
extern const uint16_t K_LatchPreReleased_Braking_Timeout;

#ifdef _CONFIG_MagnaLatch_TwoSwitch
extern const uint16_t K_CinchMotor_EnhancedCurrent_Detect[8][8];

extern const uint16_t K_CinchMotor_EnhancedCurrent_DecreasePerTimer;
extern const uint16_t K_CinchMotor_EnhancedCurrent_Decrease_Time;
extern const uint16_t K_CinchMotor_EnhancedCurrent_IncreasePerTimer;
extern const uint16_t K_CinchMotor_EnhancedCurrent_Increase_Time;
extern const uint16_t K_CinchMotor_EnhancedCurrent_Threshold_Time;

extern const uint16_t K_LargeSpringPosition_FixedCurrent_Level_1_Cal[8][8];
extern const uint16_t K_LargeSpringPosition_FixedCurrent_Level_1_NoCal[8][8];
extern const uint16_t K_LargeSpringPosition_FixedCurrent_Level_1_Time;

extern const uint16_t K_LargeSpringPosition_FixedCurrent_Level_2_Cal[8][8];  
extern const uint16_t K_LargeSpringPosition_FixedCurrent_Level_2_NoCal[8][8]; 
extern const uint16_t K_LargeSpringPosition_FixedCurrent_Level_2_Time;

extern const uint16_t K_LargeSpringPosition_FixedCurrent_Level_3_Cal[8][8];  
extern const uint16_t K_LargeSpringPosition_FixedCurrent_Level_3_NoCal[8][8];
extern const uint16_t K_LargeSpringPosition_FixedCurrent_Level_3_Time;

extern const uint16_t K_FindHomeAfterCinch_ComfirmCurrent;
extern const uint16_t K_FindHomeAfterCinch_ComfirmCurrent_Time;
extern const uint16_t K_FindHomeAfterBlip_ComfirmCurrent;
extern const uint16_t K_FindHomeAfterBlip_ComfirmCurrent_Time;
#endif


extern const uint16_t K_ReleaseMotorHardStop_EnhancedCurrent_Detect;
extern const uint16_t K_ReleaseMotorHardStop_EnhancedCurrent_DecreasePerTimer;
extern const uint16_t K_ReleaseMotorHardStop_EnhancedCurrent_Decrease_Time;
extern const uint16_t K_ReleaseMotorHardStop_EnhancedCurrent_IncreasePerTimer;
extern const uint16_t K_ReleaseMotorHardStop_EnhancedCurrent_Increase_Time;
extern const uint16_t K_ReleaseMotorHardStop_EnhancedCurrent_Threshold_Time;

extern const uint16_t K_ReleaseMotorHardStop_FixedCurrent_Level_1_Cal;
extern const uint16_t K_ReleaseMotorHardStop_FixedCurrent_Level_1_NoCal;
extern const uint16_t K_ReleaseMotorHardStop_FixedCurrent_Level_1_Time;
extern const uint16_t K_ReleaseMotorHardStop_FixedCurrent_Level_2_Cal;  
extern const uint16_t K_ReleaseMotorHardStop_FixedCurrent_Level_2_NoCal; 
extern const uint16_t K_ReleaseMotorHardStop_FixedCurrent_Level_2_Time;
extern const uint16_t K_ReleaseMotorHardStop_FixedCurrent_Level_3_Cal;  
extern const uint16_t K_ReleaseMotorHardStop_FixedCurrent_Level_3_NoCal;
extern const uint16_t K_ReleaseMotorHardStop_FixedCurrent_Level_3_Time;

extern const uint16_t K_CinchMotorHardStop_EnhancedCurrent_Detect;
extern const uint16_t K_CinchMotorHardStop_EnhancedCurrent_DecreasePerTimer;
extern const uint16_t K_CinchMotorHardStop_EnhancedCurrent_Decrease_Time;
extern const uint16_t K_CinchMotorHardStop_EnhancedCurrent_IncreasePerTimer;
extern const uint16_t K_CinchMotorHardStop_EnhancedCurrent_Increase_Time;
extern const uint16_t K_CinchMotorHardStop_EnhancedCurrent_Threshold_Time;

extern const uint16_t K_CinchMotorHardStop_FixedCurrent_Level_1_Cal;
extern const uint16_t K_CinchMotorHardStop_FixedCurrent_Level_1_NoCal;
extern const uint16_t K_CinchMotorHardStop_FixedCurrent_Level_1_Time;
extern const uint16_t K_CinchMotorHardStop_FixedCurrent_Level_2_Cal;  
extern const uint16_t K_CinchMotorHardStop_FixedCurrent_Level_2_NoCal; 
extern const uint16_t K_CinchMotorHardStop_FixedCurrent_Level_2_Time;
extern const uint16_t K_CinchMotorHardStop_FixedCurrent_Level_3_Cal;  
extern const uint16_t K_CinchMotorHardStop_FixedCurrent_Level_3_NoCal;
extern const uint16_t K_CinchMotorHardStop_FixedCurrent_Level_3_Time;


#ifdef _CONFIG_HuffLatch
extern const uint16_t Huff_K_PowerCinchInSecondPosition_AfterPowerUp_Enable;
extern const uint16_t Huff_K_LatchPreCinchCheck_Timeout;
extern const uint16_t Huff_K_LatchPowerCinching_Timeout;
extern const uint16_t Huff_K_LatchFindHomeAfterCinch_Timeout;
extern const uint16_t Huff_K_LatchPreReleasing_Timeout;
extern const uint16_t Huff_K_LatchPowerReleasing_Timeout;
extern const uint16_t Huff_K_LatchFindHomeAfterRelease_Timeout;
extern const uint16_t Huff_K_LatchFindHomeAfterRelease_Mini_Time;

extern const uint16_t Huff_K_LatchFindHomeReleaseDirection_Timeout;
extern const uint16_t Huff_K_LatchFindHomeCinchDirection_Timeout;
extern const uint16_t Huff_K_LatchFindHomeAfterPark_Timeout;
extern const uint16_t Huff_K_LatchFindHomeAfterBlip_Timeout;

extern const uint16_t Huff_K_LatchPreReleased_Timeout; 
extern const uint16_t Huff_K_LatchPreRelease_SnowLoad_Time;
extern const uint16_t Huff_K_LatchCrankWait_Timeout;
extern const uint16_t Huff_K_LatchMechFailure_Timeout;
extern const uint16_t Huff_K_SnowLoad_Timeout_PowerCinching_Delay_Time;

extern const uint16_t Huff_K_WaitForPowerCinching_Time;
extern const uint16_t Huff_K_PreReleasing_Strike_Prework_FromHome_Time;
extern const uint16_t Huff_K_PreReleasing_Strike_Prework_FromMiddle_Time;

extern const uint16_t Huff_K_PowerCinching_Duration_Min_Time;
extern const uint16_t Huff_K_PowerCinching_Duration_Max_Time;

extern const uint16_t Huff_K_LatchPreCinchCheck_Time;
extern const uint16_t Huff_K_PowerCinching_Delay_Time;
extern const uint16_t Huff_K_PowerReleasing_PawlSwitch_Delay_Time;
extern const uint16_t Huff_K_PowerReleasing_OutofLatch_Delay_Time;
extern const uint16_t Huff_K_PreReleased_OutofLatch_Delay_Time;
extern const uint16_t Huff_K_FindHomeAfterPark_PositionSwitch_Delay_Time;
extern const uint16_t Huff_K_PreReleasing_PositionSwitch_Delay_Time;

extern const uint16_t Huff_K_CinchMotor_IncreaseStep_Duty;

extern const uint16_t Huff_K_StopBeforePowerReleasing_Time;
extern const uint16_t Huff_K_StopBeforePreReleasing_Time;
extern const uint16_t Huff_K_StopBeforeFindHomeAfterRelease_Time;
extern const uint16_t Huff_K_StopBeforeFindHomeAfterPark_Time;
extern const uint16_t Huff_K_StopBeforeFindHomeAfterBlip_Time;
extern const uint16_t Huff_K_MiniWorkingInCinchDirection_Time;
extern const uint16_t Huff_K_ContinueFindHomeAfterRelease_Time;
extern const uint16_t Huff_K_ChangeDutyInFindHomeAfterRelease_Time;
extern const uint16_t Huff_K_StopBeforeFindHomeCinchDirection_Time;
extern const uint16_t Huff_K_StopBeforeFindHomeReleaseDirection_Time;
extern const uint16_t Huff_K_LatchFindHomeFailure_Timeout;

extern const uint16_t Huff_K_FindHomeReleaseDirection_Inrush_Time;
extern const uint16_t Huff_K_FindHomeCinchDirection_Inrush_Time;
extern const uint16_t Huff_K_PowerCinching_Inrush_Time;
extern const uint16_t Huff_K_FindHomeAfterCinch_Inrush_Time;
extern const uint16_t Huff_K_FindHomeAfterPark_Inrush_Time;
extern const uint16_t Huff_K_PreReleasing_Inrush_Time;
extern const uint16_t Huff_K_PowerReleasing_Inrush_Time;
extern const uint16_t Huff_K_FindHomeAfterRelease_Inrush_Time;
extern const uint16_t Huff_K_PowerReleasing_Mini_Time;

extern const uint16_t Huff_K_CinchMotorFindHome_Count;

extern const uint16_t Huff_K_FindHomeAfterCinch_StartDuty_Time;
extern const uint16_t Huff_K_FindHomeAfterCinch_DecreaseDuty_Time;
extern const uint16_t Huff_K_FindHomeAfterCinch_IncreaseDuty_Time;

extern const uint16_t Huff_K_CinchMotor_PowerCinching_Duty;
extern const uint16_t Huff_K_CinchMotor_PowerCinching_Duty_2nd;
extern const uint16_t Huff_K_CinchMotor_PowerCinching_Duty_3rd;

extern const uint16_t Huff_K_ChangeDutyInPowerCinching_Time;
extern const uint16_t Huff_K_ChangeDutyInPowerCinching_Time_2nd;

extern const uint16_t Huff_K_CinchMotor_FindHomeAfterCinch_Duty;
extern const uint16_t Huff_K_CinchMotor_FindHomeAfterCinch_Duty_2nd;

extern const uint16_t Huff_K_CinchMotor_FindHomeAfterRelease_Duty;
extern const uint16_t Huff_K_CinchMotor_FindHomeAfterRelease_Duty_2nd;
extern const uint16_t Huff_K_CinchMotor_FindHomeAfterRelease_Duty_3rd;

extern const uint16_t Huff_K_CinchMotor_FindHomeReleaseDirection_Duty;
extern const uint16_t Huff_K_CinchMotor_FindHomeReleaseDirection_Duty_2nd;
extern const uint16_t Huff_K_CinchMotor_FindHomeCinchDirection_Duty;
extern const uint16_t Huff_K_CinchMotor_FindHomeCinchDirection_Duty_2nd;

extern const uint16_t Huff_K_CinchMotor_FindHomeAfterPark_Duty;
extern const uint16_t Huff_K_CinchMotor_FindHomeAfterBlip_Duty;

extern const uint16_t Huff_K_ReleaseMotor_FindHomeAfterRelease_Duty;
extern const uint16_t Huff_K_ReleaseMotor_FindHomeAfterRelease_Duty_2nd;

extern const uint16_t Huff_K_ContinueParking_Time;
extern const uint16_t Huff_K_ContinueParking_Time_2nd;

extern const uint16_t Huff_K_ReleaseMotor_PowerReleasing_Duty;
extern const uint16_t Huff_K_ReleaseMotor_PowerReleasing_Duty_2nd;
extern const uint16_t Huff_K_CinchMotor_PowerReleasing_Duty;
extern const uint16_t Huff_K_CinchMotor_PowerReleasing_Duty_2nd;

extern const uint16_t Huff_K_PowerReleasing_ComfirmCurrent;

extern const uint16_t Huff_K_PowerCinching_SoftStall_Current;
extern const uint16_t Huff_K_FindHomeAfterCinch_SoftStall_Current;
extern const uint16_t Huff_K_PreReleasing_SoftStall_Current;
extern const uint16_t Huff_K_PowerReleasing_SoftStall_Current;
extern const uint16_t Huff_K_FindHomeAfterRelease_SoftStall_Current;
extern const uint16_t Huff_K_FindHomeAfterPark_SoftStall_Current;
extern const uint16_t Huff_K_FindHomeReleaseDirection_SoftStall_Current;
extern const uint16_t Huff_K_FindHomeCinchDirection_SoftStall_Current;



extern const uint16_t Huff_K_PowerCinching_SoftStall_Time; 
extern const uint16_t Huff_K_FindHomeAfterCinch_SoftStall_Time; 
extern const uint16_t Huff_K_PreReleasing_SoftStall_Time; 
extern const uint16_t Huff_K_PowerReleasing_SoftStall_Time; 
extern const uint16_t Huff_K_FindHomeAfterRelease_SoftStall_Time;
extern const uint16_t Huff_K_FindHomeReleaseDirection_SoftStall_Time;
extern const uint16_t Huff_K_FindHomeCinchDirection_SoftStall_Time;
extern const uint16_t Huff_K_FindHomeAfterPark_SoftStall_Time;

extern const uint16_t Huff_K_PrimaryPositionIsArrived_Time;
extern const uint16_t Huff_K_StopBeforeFindHomeAfterCinch_Time;
extern const uint16_t Huff_K_LatchNotLeaveHomeInMiniPowerCinch_Time;
extern const uint16_t Huff_K_ChangeDutyInFindHomeAfterCinch_Time;
extern const uint16_t Huff_K_ChangeDutyInFindHomeAfterCinch_Time_2nd;

extern const uint16_t Huff_K_LowDutyFailFindHomeAfterCinch_Time;
extern const uint16_t Huff_K_LowDutyFailFindHomeAfterCinch_Duty; 
extern const uint16_t Huff_K_LowDutyFailPowerCinching_Time;
extern const uint16_t Huff_K_LowDutyFailPowerCinching_Duty;

extern const uint16_t Huff_K_PowerReleasing_ComfirmCurrent_Time;
extern const uint16_t Huff_K_FindHomeAfterCinch_Work_MiniTime;
extern const uint16_t Huff_K_AjarSwitchConfirm_Time;

extern const uint16_t Huff_K_ChangeDutyInFindHomeReleaseDirection_Time;
extern const uint16_t Huff_K_ChangeDutyInFindHomeCinchDirection_Time;
#endif

#ifdef _CONFIG_IntevaSideLatch_ES1T
extern const uint16_t IntevaSide_K_PowerCinchInSecondPosition_AfterPowerUp_Enable;
extern const uint16_t IntevaSide_K_LatchPreCinchCheck_Timeout;
extern const uint16_t IntevaSide_K_LatchPreCinchCheck_Timeout_LongDelay;

extern const uint16_t IntevaSide_K_LatchPowerCinching_Timeout;
extern const uint16_t IntevaSide_K_LatchFindHomeAfterCinch_Timeout;
extern const uint16_t IntevaSide_K_LatchPreReleasing_Timeout;
extern const uint16_t IntevaSide_K_LatchPowerReleasing_Timeout;
extern const uint16_t IntevaSide_K_LatchFindHomeAfterRelease_Timeout;
extern const uint16_t IntevaSide_K_LatchFindHomeAfterRelease_Mini_Time;

extern const uint16_t IntevaSide_K_LatchFindHomeReleaseDirection_Timeout;
extern const uint16_t IntevaSide_K_LatchFindHomeCinchDirection_Timeout;
extern const uint16_t IntevaSide_K_LatchFindHomeReleaseMotor_Timeout;
extern const uint16_t IntevaSide_K_LatchFindHomeAfterPark_Timeout;
extern const uint16_t IntevaSide_K_LatchFindHomeAfterBlip_Timeout;

extern const uint16_t IntevaSide_K_LatchPreReleased_Timeout; 
extern const uint16_t IntevaSide_K_LatchPreReleased_Timeout_LongDelay;

extern const uint16_t IntevaSide_K_LatchPreRelease_SnowLoad_Time;
extern const uint16_t IntevaSide_K_LatchCrankWait_Timeout;
extern const uint16_t IntevaSide_K_LatchMechFailure_Timeout;
extern const uint16_t IntevaSide_K_LatchIceBreaking_Timeout;
extern const uint16_t IntevaSide_K_LatchFindHomeAfterIceBreak_Timeout;
extern const uint16_t IntevaSide_K_SnowLoad_Timeout_PowerCinching_Delay_Time;

extern const uint16_t IntevaSide_K_WaitForPowerCinching_Time;
extern const uint16_t IntevaSide_K_PreReleasing_Strike_Prework_FromHome_Time;
extern const uint16_t IntevaSide_K_PreReleasing_Strike_Prework_FromMiddle_Time;

extern const uint16_t IntevaSide_K_PowerCinching_Duration_Min_Time;
extern const uint16_t IntevaSide_K_PowerCinching_Duration_Max_Time;
extern const uint16_t IntevaSide_K_LatchPreCinchCheck_Time;
extern const uint16_t IntevaSide_K_LatchPreCinchCheck_Time_LongDelay;
extern const uint16_t IntevaSide_K_PowerCinching_Delay_Time;
extern const uint16_t IntevaSide_K_PowerReleasing_PawlSwitch_Delay_Time;
extern const uint16_t IntevaSide_K_PowerReleasing_OutofLatch_Delay_Time;
extern const uint16_t IntevaSide_K_PreReleased_OutofLatch_Delay_Time;
extern const uint16_t IntevaSide_K_IceBreaking_OutofLatch_Delay_Time;
extern const uint16_t IntevaSide_K_FindHomeAfterPark_PositionSwitch_Delay_Time;
extern const uint16_t IntevaSide_K_PreReleasing_PositionSwitch_Delay_Time;

extern const uint16_t IntevaSide_K_CinchMotor_IncreaseStep_Duty;
extern const uint16_t IntevaSide_K_CinchMotor_DecreaseStep_Duty;
extern const uint16_t IntevaSide_K_ReleaseMotor_IncreaseStep_Duty;
extern const uint16_t IntevaSide_K_ReleaseMotor_DecreaseStep_Duty;

extern const uint16_t IntevaSide_K_StopBeforePowerReleasing_Time;
extern const uint16_t IntevaSide_K_StopBeforePreReleasing_Time;
extern const uint16_t IntevaSide_K_StopBeforeFindHomeAfterRelease_Time;
extern const uint16_t IntevaSide_K_StopBeforeFindHomeAfterPark_Time;
extern const uint16_t IntevaSide_K_StopBeforeFindHomeAfterBlip_Time;
extern const uint16_t IntevaSide_K_StopBeforeIceBreaking_Time;
extern const uint16_t IntevaSide_K_StopBeforeFindHomeAfterIceBreak_Time;

extern const uint16_t IntevaSide_K_MiniWorkingInCinchDirection_Time;
extern const uint16_t IntevaSide_K_ContinueFindHomeAfterRelease_Time;
extern const uint16_t IntevaSide_K_ContinueFindHomeAfterIceBreak_Time;
extern const uint16_t IntevaSide_K_StopBeforeFindHomeReleaseMotor_Time;
extern const uint16_t IntevaSide_K_ChangeDutyInFindHomeAfterRelease_Time;
extern const uint16_t IntevaSide_K_ChangeDutyInFindHomeAfterRelease_Time_2nd;
extern const uint16_t IntevaSide_K_ChangeDutyInFindHomeAfterRelease_Time_3rd;

extern const uint16_t IntevaSide_K_StopBeforeFindHomeCinchDirection_Time;
extern const uint16_t IntevaSide_K_StopBeforeFindHomeReleaseDirection_Time;
extern const uint16_t IntevaSide_K_LatchFindHomeFailure_Timeout;

extern const uint16_t IntevaSide_K_FindHomeReleaseDirection_Inrush_Time;
extern const uint16_t IntevaSide_K_FindHomeCinchDirection_Inrush_Time;
extern const uint16_t IntevaSide_K_FindHomeReleaseMotor_Inrush_Time;
extern const uint16_t IntevaSide_K_PowerCinching_Inrush_Time;
extern const uint16_t IntevaSide_K_FindHomeAfterCinch_Inrush_Time;
extern const uint16_t IntevaSide_K_FindHomeAfterPark_Inrush_Time;
extern const uint16_t IntevaSide_K_PreReleasing_Inrush_Time;
extern const uint16_t IntevaSide_K_PowerReleasing_Inrush_Time;
extern const uint16_t IntevaSide_K_FindHomeAfterRelease_Inrush_Time;
extern const uint16_t IntevaSide_K_IceBreaking_Inrush_Time;
extern const uint16_t IntevaSide_K_FindHomeAfterIceBreak_Inrush_Time;

extern const uint16_t IntevaSide_K_PowerReleasing_Mini_Time;
extern const uint16_t IntevaSide_K_PreReleased_Mini_Time;

extern const uint16_t IntevaSide_K_CinchMotorFindHome_Count;
extern const uint16_t IntevaSide_K_FindHomeAfterCinch_StartDuty_Time;
extern const uint16_t IntevaSide_K_FindHomeAfterCinch_DecreaseDuty_Time;
extern const uint16_t IntevaSide_K_FindHomeAfterCinch_IncreaseDuty_Time;

extern const uint16_t IntevaSide_K_CinchMotor_PowerCinching_Duty;
extern const uint16_t IntevaSide_K_CinchMotor_PowerCinching_Duty_2nd;
extern const uint16_t IntevaSide_K_CinchMotor_PowerCinching_Duty_2nd_LongDelay;
extern const uint16_t IntevaSide_K_CinchMotor_PowerCinching_Duty_3rd;

extern const uint16_t IntevaSide_K_ChangeDutyInPowerCinching_Time;
extern const uint16_t IntevaSide_K_ChangeDutyInPowerCinching_Time_2nd;

extern const uint16_t IntevaSide_K_CinchMotor_FindHomeAfterCinch_Duty;
extern const uint16_t IntevaSide_K_CinchMotor_FindHomeAfterCinch_Duty_2nd;
extern const uint16_t IntevaSide_K_CinchMotor_FindHomeAfterCinch_Duty_3rd;
extern const uint16_t IntevaSide_K_CinchMotor_PreReleasing_Duty;

extern const uint16_t IntevaSide_K_CinchMotor_FindHomeAfterRelease_Duty;
extern const uint16_t IntevaSide_K_CinchMotor_FindHomeAfterRelease_Duty_2nd;
extern const uint16_t IntevaSide_K_CinchMotor_FindHomeAfterRelease_Duty_3rd;

extern const uint16_t IntevaSide_K_CinchMotor_FindHomeReleaseDirection_Duty;
extern const uint16_t IntevaSide_K_CinchMotor_FindHomeReleaseDirection_Duty_2nd;
extern const uint16_t IntevaSide_K_CinchMotor_FindHomeCinchDirection_Duty;
extern const uint16_t IntevaSide_K_CinchMotor_FindHomeCinchDirection_Duty_2nd;

extern const uint16_t IntevaSide_K_CinchMotor_FindHomeAfterPark_Duty;
extern const uint16_t IntevaSide_K_CinchMotor_FindHomeAfterBlip_Duty;

extern const uint16_t IntevaSide_K_CinchMotor_IceBreaking_Duty;
extern const uint16_t IntevaSide_K_CinchMotor_IceBreaking_Duty_2nd;
extern const uint16_t IntevaSide_K_CinchMotor_IceBreaking_Duty_3rd;
extern const uint16_t IntevaSide_K_CinchMotor_FindHomeAfterIceBreak_Duty;
extern const uint16_t IntevaSide_K_CinchMotor_FindHomeAfterIceBreak_Duty_2nd;

extern const uint16_t IntevaSide_K_ReleaseMotor_FindHomeAfterRelease_Duty;
extern const uint16_t IntevaSide_K_ReleaseMotor_FindHomeAfterRelease_Duty_2nd;
extern const uint16_t IntevaSide_K_ReleaseMotor_FindHomeAfterRelease_Duty_3rd;
extern const uint16_t IntevaSide_K_ReleaseMotor_FindHomeAfterRelease_Duty_4th;

extern const uint16_t IntevaSide_K_ReleaseMotor_FindHomeReleaseMotor_Duty;
extern const uint16_t IntevaSide_K_ReleaseMotor_FindHomeReleaseMotor_Duty_2nd;

extern const uint16_t IntevaSide_K_ContinueParking_Time;
extern const uint16_t IntevaSide_K_ContinueParking_Time_2nd;

extern const uint16_t IntevaSide_K_ReleaseMotor_PowerReleasing_Duty;
extern const uint16_t IntevaSide_K_ReleaseMotor_PowerReleasing_Duty_2nd;
extern const uint16_t IntevaSide_K_CinchMotor_PowerReleasing_Duty;
extern const uint16_t IntevaSide_K_CinchMotor_PowerReleasing_Duty_2nd;

extern const uint16_t IntevaSide_K_PowerReleasing_ComfirmCurrent;

extern const uint16_t IntevaSide_K_PowerCinching_SoftStall_Current;
extern const uint16_t IntevaSide_K_FindHomeAfterCinch_SoftStall_Current;
extern const uint16_t IntevaSide_K_PreReleasing_SoftStall_Current;
extern const uint16_t IntevaSide_K_PowerReleasing_SoftStall_Current;
extern const uint16_t IntevaSide_K_FindHomeAfterRelease_SoftStall_Current;
extern const uint16_t IntevaSide_K_FindHomeAfterPark_SoftStall_Current;

extern const uint16_t IntevaSide_K_FindHomeReleaseDirection_SoftStall_Current;
extern const uint16_t IntevaSide_K_FindHomeCinchDirection_SoftStall_Current;
extern const uint16_t IntevaSide_K_FindHomeReleaseMotor_SoftStall_Current;
extern const uint16_t IntevaSide_K_IceBreaking_SoftStall_Current;
extern const uint16_t IntevaSide_K_FindHomeAfterIceBreak_SoftStall_Current;

extern const uint16_t IntevaSide_K_PowerCinching_SoftStall_Time; 
extern const uint16_t IntevaSide_K_FindHomeAfterCinch_SoftStall_Time; 
extern const uint16_t IntevaSide_K_FindHomeReleaseMotor_SoftStall_Time;
extern const uint16_t IntevaSide_K_PreReleasing_SoftStall_Time; 
extern const uint16_t IntevaSide_K_PowerReleasing_SoftStall_Time; 
extern const uint16_t IntevaSide_K_FindHomeAfterRelease_SoftStall_Time;
extern const uint16_t IntevaSide_K_FindHomeReleaseDirection_SoftStall_Time;
extern const uint16_t IntevaSide_K_FindHomeCinchDirection_SoftStall_Time;
extern const uint16_t IntevaSide_K_FindHomeAfterPark_SoftStall_Time;
extern const uint16_t IntevaSide_K_IceBreaking_SoftStall_Time;
extern const uint16_t IntevaSide_K_FindHomeAfterIceBreak_SoftStall_Time;

extern const uint16_t IntevaSide_K_PrimaryPositionIsArrived_Time;
extern const uint16_t IntevaSide_K_StopBeforeFindHomeAfterCinch_Time;
extern const uint16_t IntevaSide_K_LatchNotLeaveHomeInMiniPowerCinch_Time;
extern const uint16_t IntevaSide_K_LatchNotLeaveHomeInMiniIceBreak_Time;
extern const uint16_t IntevaSide_K_ChangeDutyInFindHomeAfterCinch_Time;
extern const uint16_t IntevaSide_K_ChangeDutyInFindHomeAfterCinch_Time_2nd;
extern const uint16_t IntevaSide_K_ChangeDutyInIceBreaking_Time;
extern const uint16_t IntevaSide_K_ChangeDutyInIceBreaking_Time_2nd;
extern const uint16_t IntevaSide_K_ChangeDutyInFindHomeAfterIceBreak_Time;

extern const uint16_t IntevaSide_K_LowDutyFailFindHomeAfterCinch_Time;
extern const uint16_t IntevaSide_K_LowDutyFailFindHomeAfterCinch_Duty; 
extern const uint16_t IntevaSide_K_LowDutyFailPowerCinching_Time;
extern const uint16_t IntevaSide_K_LowDutyFailPowerCinching_Duty;
extern const uint16_t IntevaSide_K_LowDutyFailIceBreaking_Time;
extern const uint16_t IntevaSide_K_LowDutyFailIceBreaking_Duty;
extern const uint16_t IntevaSide_K_LowDutyFailFindHomeAfterIceBreak_Time;
extern const uint16_t IntevaSide_K_LowDutyFailFindHomeAfterIceBreak_Duty;

extern const uint16_t IntevaSide_K_PowerReleasing_ComfirmCurrent_Time;
extern const uint16_t IntevaSide_K_FindHomeAfterCinch_Work_MiniTime;
extern const uint16_t IntevaSide_K_AjarSwitchConfirm_Time;

extern const uint16_t IntevaSide_K_ChangeDutyInFindHomeReleaseDirection_Time;
extern const uint16_t IntevaSide_K_ChangeDutyInFindHomeCinchDirection_Time;
extern const uint16_t IntevaSide_K_ChangeDutyInFindHomeReleaseMotor_Time;
extern const uint16_t IntevaSide_K_LatchFullyReleased_Braking_Timeout;
extern const uint16_t IntevaSide_K_LatchFullyCinched_Braking_Timeout;
extern const uint16_t IntevaSide_K_LatchPreReleased_Braking_Timeout;


extern const uint16_t IntevaSide_K_ReleaseMotorHardStop_EnhancedCurrent_Detect;
extern const uint16_t IntevaSide_K_ReleaseMotorHardStop_EnhancedCurrent_DecreasePerTimer;
extern const uint16_t IntevaSide_K_ReleaseMotorHardStop_EnhancedCurrent_Decrease_Time;
extern const uint16_t IntevaSide_K_ReleaseMotorHardStop_EnhancedCurrent_IncreasePerTimer;
extern const uint16_t IntevaSide_K_ReleaseMotorHardStop_EnhancedCurrent_Increase_Time;
extern const uint16_t IntevaSide_K_ReleaseMotorHardStop_EnhancedCurrent_Threshold_Time;

extern const uint16_t IntevaSide_K_ReleaseMotorHardStop_FixedCurrent_Level_1_Cal;
extern const uint16_t IntevaSide_K_ReleaseMotorHardStop_FixedCurrent_Level_1_NoCal;
extern const uint16_t IntevaSide_K_ReleaseMotorHardStop_FixedCurrent_Level_1_Time;
extern const uint16_t IntevaSide_K_ReleaseMotorHardStop_FixedCurrent_Level_2_Cal;  
extern const uint16_t IntevaSide_K_ReleaseMotorHardStop_FixedCurrent_Level_2_NoCal; 
extern const uint16_t IntevaSide_K_ReleaseMotorHardStop_FixedCurrent_Level_2_Time;
extern const uint16_t IntevaSide_K_ReleaseMotorHardStop_FixedCurrent_Level_3_Cal;  
extern const uint16_t IntevaSide_K_ReleaseMotorHardStop_FixedCurrent_Level_3_NoCal;
extern const uint16_t IntevaSide_K_ReleaseMotorHardStop_FixedCurrent_Level_3_Time;

extern const uint16_t IntevaSide_K_CinchMotorHardStop_EnhancedCurrent_Detect;
extern const uint16_t IntevaSide_K_CinchMotorHardStop_EnhancedCurrent_DecreasePerTimer;
extern const uint16_t IntevaSide_K_CinchMotorHardStop_EnhancedCurrent_Decrease_Time;
extern const uint16_t IntevaSide_K_CinchMotorHardStop_EnhancedCurrent_IncreasePerTimer;
extern const uint16_t IntevaSide_K_CinchMotorHardStop_EnhancedCurrent_Increase_Time;
extern const uint16_t IntevaSide_K_CinchMotorHardStop_EnhancedCurrent_Threshold_Time;

extern const uint16_t IntevaSide_K_CinchMotorHardStop_FixedCurrent_Level_1_Cal;
extern const uint16_t IntevaSide_K_CinchMotorHardStop_FixedCurrent_Level_1_NoCal;
extern const uint16_t IntevaSide_K_CinchMotorHardStop_FixedCurrent_Level_1_Time;
extern const uint16_t IntevaSide_K_CinchMotorHardStop_FixedCurrent_Level_2_Cal;  
extern const uint16_t IntevaSide_K_CinchMotorHardStop_FixedCurrent_Level_2_NoCal; 
extern const uint16_t IntevaSide_K_CinchMotorHardStop_FixedCurrent_Level_2_Time;
extern const uint16_t IntevaSide_K_CinchMotorHardStop_FixedCurrent_Level_3_Cal;  
extern const uint16_t IntevaSide_K_CinchMotorHardStop_FixedCurrent_Level_3_NoCal;
extern const uint16_t IntevaSide_K_CinchMotorHardStop_FixedCurrent_Level_3_Time;
#endif

/*********************************************************************************************
**    Diagnostic Control
*********************************************************************************************/
extern const uint16_t K_Diagnostic_PreCondition_Start_Time;
extern const uint16_t K_Diagnostic_PreCondition_Crank_Time;
extern const uint16_t K_Diagnostic_PreCondition_Voltage_Time;

extern const uint16_t K_DTCReport_PreCondition_Start_Time;
extern const uint16_t K_DTCReport_PreCondition_Crank_Time;
extern const uint16_t K_DTCReport_PreCondition_Voltage_Time;

extern const uint16_t K_CinchMotor_P_Ratio_Denominator;
extern const uint16_t K_CinchMotor_N_Ratio_Denominator;
extern const uint16_t K_ReleaseMotor_P_Ratio_Denominator;
extern const uint16_t K_Buzzer_P_Ratio_Denominator;
extern const uint16_t K_Clutch_P_Ratio_Denominator;
extern const uint16_t K_Motor1_P_Ratio_Denominator;
extern const uint16_t K_Motor1_N_Ratio_Denominator;
extern const uint16_t K_Motor2_P_Ratio_Denominator;
extern const uint16_t K_Motor2_N_Ratio_Denominator;

extern const uint16_t K_CinchMotor_STG_StaticDiag_Time;
extern const uint16_t K_ReleaseMotor_STG_StaticDiag_Time;
extern const uint16_t K_Buzzer_STG_StaticDiag_Time;
extern const uint16_t K_Clutch_STG_StaticDiag_Time;
extern const uint16_t K_Motor1_STG_StaticDiag_Time;
extern const uint16_t K_Motor2_STG_StaticDiag_Time;

extern const uint16_t K_CinchMotor_OC_StaticDiag_Time;
extern const uint16_t K_ReleaseMotor_OC_StaticDiag_Time;
extern const uint16_t K_Buzzer_OC_StaticDiag_Time;
extern const uint16_t K_Clutch_OC_StaticDiag_Time;
extern const uint16_t K_Motor1_OC_StaticDiag_Time;
extern const uint16_t K_Motor2_OC_StaticDiag_Time;

extern const uint16_t K_CinchMotor_STB_StaticDiag_Time;
extern const uint16_t K_ReleaseMotor_STB_StaticDiag_Time;
extern const uint16_t K_Buzzer_STB_StaticDiag_Time;
extern const uint16_t K_Clutch_STB_StaticDiag_Time;
extern const uint16_t K_Motor1_STB_StaticDiag_Time;
extern const uint16_t K_Motor2_STB_StaticDiag_Time;

extern const uint16_t K_CinchMotor_Error_StaticDiag_Time;
extern const uint16_t K_ReleaseMotor_Error_StaticDiag_Time;
extern const uint16_t K_Buzzer_Error_StaticDiag_Time;
extern const uint16_t K_Clutch_Error_StaticDiag_Time;
extern const uint16_t K_Motor1_Error_StaticDiag_Time;
extern const uint16_t K_Motor2_Error_StaticDiag_Time;

extern const uint16_t K_CinchMotor_Normal_StaticDiag_Time;
extern const uint16_t K_ReleaseMotor_Normal_StaticDiag_Time;
extern const uint16_t K_Buzzer_Normal_StaticDiag_Time;
extern const uint16_t K_Clutch_Normal_StaticDiag_Time;
extern const uint16_t K_Motor1_Normal_StaticDiag_Time;
extern const uint16_t K_Motor2_Normal_StaticDiag_Time;

#ifdef _CONFIG_Motor4
extern const uint16_t K_Motor4_STG_StaticDiag_Time;
extern const uint16_t K_Motor4_OC_StaticDiag_Time;
extern const uint16_t K_Motor4_STB_StaticDiag_Time;
extern const uint16_t K_Motor4_Error_StaticDiag_Time;
extern const uint16_t K_Motor4_Normal_StaticDiag_Time;
#endif

extern const uint16_t K_ReleaseMotor_P_STG_StaticDiag_Ratio_LowLimit;  
extern const uint16_t K_ReleaseMotor_P_STG_StaticDiag_Ratio_HighLimit;

extern const uint16_t K_ReleaseMotor_P_OC_StaticDiag_Ratio_LowLimit;  
extern const uint16_t K_ReleaseMotor_P_OC_StaticDiag_Ratio_HighLimit;

extern const uint16_t K_ReleaseMotor_P_STB_StaticDiag_Ratio_LowLimit;  
extern const uint16_t K_ReleaseMotor_P_STB_StaticDiag_Ratio_HighLimit;

extern const uint16_t K_ReleaseMotor_P_Normal_StaticDiag_Ratio_LowLimit;  
extern const uint16_t K_ReleaseMotor_P_Normal_StaticDiag_Ratio_HighLimit;

extern const uint16_t K_Buzzer_P_STG_StaticDiag_Ratio_LowLimit;  
extern const uint16_t K_Buzzer_P_STG_StaticDiag_Ratio_HighLimit;

extern const uint16_t K_Buzzer_P_OC_StaticDiag_Ratio_LowLimit;  
extern const uint16_t K_Buzzer_P_OC_StaticDiag_Ratio_HighLimit;

extern const uint16_t K_Buzzer_P_STB_StaticDiag_Ratio_LowLimit;  
extern const uint16_t K_Buzzer_P_STB_StaticDiag_Ratio_HighLimit;

extern const uint16_t K_Buzzer_P_Normal_StaticDiag_Ratio_LowLimit;  
extern const uint16_t K_Buzzer_P_Normal_StaticDiag_Ratio_HighLimit;

extern const uint16_t K_Clutch_P_STG_StaticDiag_Ratio_LowLimit;  
extern const uint16_t K_Clutch_P_STG_StaticDiag_Ratio_HighLimit;

extern const uint16_t K_Clutch_P_OC_StaticDiag_Ratio_LowLimit;  
extern const uint16_t K_Clutch_P_OC_StaticDiag_Ratio_HighLimit;

extern const uint16_t K_Clutch_P_STB_StaticDiag_Ratio_LowLimit;  
extern const uint16_t K_Clutch_P_STB_StaticDiag_Ratio_HighLimit;

extern const uint16_t K_Clutch_P_Normal_StaticDiag_Ratio_LowLimit;  
extern const uint16_t K_Clutch_P_Normal_StaticDiag_Ratio_HighLimit;

extern const uint16_t K_CinchMotor_P_STG_StaticDiag_Ratio_LowLimit;  
extern const uint16_t K_CinchMotor_P_STG_StaticDiag_Ratio_HighLimit;
extern const uint16_t K_CinchMotor_N_STG_StaticDiag_Ratio_LowLimit;
extern const uint16_t K_CinchMotor_N_STG_StaticDiag_Ratio_HighLimit;

extern const uint16_t K_CinchMotor_P_OC_StaticDiag_Ratio_LowLimit;  
extern const uint16_t K_CinchMotor_P_OC_StaticDiag_Ratio_HighLimit;
extern const uint16_t K_CinchMotor_N_OC_StaticDiag_Ratio_LowLimit;
extern const uint16_t K_CinchMotor_N_OC_StaticDiag_Ratio_HighLimit;

extern const uint16_t K_CinchMotor_P_STB_StaticDiag_Ratio_LowLimit;  
extern const uint16_t K_CinchMotor_P_STB_StaticDiag_Ratio_HighLimit;
extern const uint16_t K_CinchMotor_N_STB_StaticDiag_Ratio_LowLimit;
extern const uint16_t K_CinchMotor_N_STB_StaticDiag_Ratio_HighLimit;

extern const uint16_t K_CinchMotor_P_Normal_StaticDiag_Ratio_LowLimit;  
extern const uint16_t K_CinchMotor_P_Normal_StaticDiag_Ratio_HighLimit;
extern const uint16_t K_CinchMotor_N_Normal_StaticDiag_Ratio_LowLimit;
extern const uint16_t K_CinchMotor_N_Normal_StaticDiag_Ratio_HighLimit;

extern const uint16_t K_Motor1_P_STG_StaticDiag_Ratio_LowLimit;  
extern const uint16_t K_Motor1_P_STG_StaticDiag_Ratio_HighLimit;
extern const uint16_t K_Motor1_N_STG_StaticDiag_Ratio_LowLimit;
extern const uint16_t K_Motor1_N_STG_StaticDiag_Ratio_HighLimit;

extern const uint16_t K_Motor1_P_OC_StaticDiag_Ratio_LowLimit;  
extern const uint16_t K_Motor1_P_OC_StaticDiag_Ratio_HighLimit;
extern const uint16_t K_Motor1_N_OC_StaticDiag_Ratio_LowLimit;
extern const uint16_t K_Motor1_N_OC_StaticDiag_Ratio_HighLimit;

extern const uint16_t K_Motor1_P_STB_StaticDiag_Ratio_LowLimit;  
extern const uint16_t K_Motor1_P_STB_StaticDiag_Ratio_HighLimit;
extern const uint16_t K_Motor1_N_STB_StaticDiag_Ratio_LowLimit;
extern const uint16_t K_Motor1_N_STB_StaticDiag_Ratio_HighLimit;

extern const uint16_t K_Motor1_P_Normal_StaticDiag_Ratio_LowLimit;  
extern const uint16_t K_Motor1_P_Normal_StaticDiag_Ratio_HighLimit;
extern const uint16_t K_Motor1_N_Normal_StaticDiag_Ratio_LowLimit;
extern const uint16_t K_Motor1_N_Normal_StaticDiag_Ratio_HighLimit;

extern const uint16_t K_Motor2_P_STG_StaticDiag_Ratio_LowLimit;  
extern const uint16_t K_Motor2_P_STG_StaticDiag_Ratio_HighLimit;
extern const uint16_t K_Motor2_N_STG_StaticDiag_Ratio_LowLimit;
extern const uint16_t K_Motor2_N_STG_StaticDiag_Ratio_HighLimit;

extern const uint16_t K_Motor2_P_OC_StaticDiag_Ratio_LowLimit;  
extern const uint16_t K_Motor2_P_OC_StaticDiag_Ratio_HighLimit;
extern const uint16_t K_Motor2_N_OC_StaticDiag_Ratio_LowLimit;
extern const uint16_t K_Motor2_N_OC_StaticDiag_Ratio_HighLimit;

extern const uint16_t K_Motor2_P_STB_StaticDiag_Ratio_LowLimit;  
extern const uint16_t K_Motor2_P_STB_StaticDiag_Ratio_HighLimit;
extern const uint16_t K_Motor2_N_STB_StaticDiag_Ratio_LowLimit;
extern const uint16_t K_Motor2_N_STB_StaticDiag_Ratio_HighLimit;

extern const uint16_t K_Motor2_P_Normal_StaticDiag_Ratio_LowLimit;  
extern const uint16_t K_Motor2_P_Normal_StaticDiag_Ratio_HighLimit;
extern const uint16_t K_Motor2_N_Normal_StaticDiag_Ratio_LowLimit;
extern const uint16_t K_Motor2_N_Normal_StaticDiag_Ratio_HighLimit;

extern const uint16_t K_Motor4_P_STG_StaticDiag_Ratio_LowLimit;  
extern const uint16_t K_Motor4_P_STG_StaticDiag_Ratio_HighLimit;
extern const uint16_t K_Motor4_N_STG_StaticDiag_Ratio_LowLimit;
extern const uint16_t K_Motor4_N_STG_StaticDiag_Ratio_HighLimit;

extern const uint16_t K_Motor4_P_OC_StaticDiag_Ratio_LowLimit;  
extern const uint16_t K_Motor4_P_OC_StaticDiag_Ratio_HighLimit;
extern const uint16_t K_Motor4_N_OC_StaticDiag_Ratio_LowLimit;
extern const uint16_t K_Motor4_N_OC_StaticDiag_Ratio_HighLimit;

extern const uint16_t K_Motor4_P_STB_StaticDiag_Ratio_LowLimit;
extern const uint16_t K_Motor4_P_STB_StaticDiag_Ratio_HighLimit;
extern const uint16_t K_Motor4_N_STB_StaticDiag_Ratio_LowLimit;
extern const uint16_t K_Motor4_N_STB_StaticDiag_Ratio_HighLimit;

extern const uint16_t K_Motor4_P_Normal_StaticDiag_Ratio_LowLimit; 
extern const uint16_t K_Motor4_P_Normal_StaticDiag_Ratio_HighLimit;
extern const uint16_t K_Motor4_N_Normal_StaticDiag_Ratio_LowLimit;
extern const uint16_t K_Motor4_N_Normal_StaticDiag_Ratio_HighLimit;


extern const uint16_t K_CinchMotor_STG_DynamicDiag_Time;
extern const uint16_t K_ReleaseMotor_STG_DynamicDiag_Time;
extern const uint16_t K_Buzzer_STG_DynamicDiag_Time;
extern const uint16_t K_Clutch_STG_DynamicDiag_Time;
extern const uint16_t K_Motor1_STG_DynamicDiag_Time;
extern const uint16_t K_Motor2_STG_DynamicDiag_Time;

extern const uint16_t K_CinchMotor_OC_DynamicDiag_Time;
extern const uint16_t K_ReleaseMotor_OC_DynamicDiag_Time;
extern const uint16_t K_Buzzer_OC_DynamicDiag_Time;
extern const uint16_t K_Clutch_OC_DynamicDiag_Time;
extern const uint16_t K_Motor1_OC_DynamicDiag_Time;
extern const uint16_t K_Motor2_OC_DynamicDiag_Time;

extern const uint16_t K_CinchMotor_STB_DynamicDiag_Time;
extern const uint16_t K_ReleaseMotor_STB_DynamicDiag_Time;
extern const uint16_t K_Buzzer_STB_DynamicDiag_Time;
extern const uint16_t K_Clutch_STB_DynamicDiag_Time;
extern const uint16_t K_Motor1_STB_DynamicDiag_Time;
extern const uint16_t K_Motor2_STB_DynamicDiag_Time;

extern const uint16_t K_CinchMotor_SCL_DynamicDiag_Time;
extern const uint16_t K_ReleaseMotor_SCL_DynamicDiag_Time;
extern const uint16_t K_Buzzer_SCL_DynamicDiag_Time;
extern const uint16_t K_Clutch_SCL_DynamicDiag_Time;
extern const uint16_t K_Motor1_SCL_DynamicDiag_Time;
extern const uint16_t K_Motor2_SCL_DynamicDiag_Time;

extern const uint16_t K_CinchMotor_Normal_DynamicDiag_Time;
extern const uint16_t K_ReleaseMotor_Normal_DynamicDiag_Time;
extern const uint16_t K_Buzzer_Normal_DynamicDiag_Time;
extern const uint16_t K_Clutch_Normal_DynamicDiag_Time;
extern const uint16_t K_Motor1_Normal_DynamicDiag_Time;
extern const uint16_t K_Motor2_Normal_DynamicDiag_Time;

extern const uint16_t K_Motor1_STG_DynamicDiag_Duty;
extern const uint16_t K_Motor2_STG_DynamicDiag_Duty;
extern const uint16_t K_CinchMotor_STG_DynamicDiag_Duty;
extern const uint16_t K_ReleaseMotor_STG_DynamicDiag_Duty;
extern const uint16_t K_Buzzer_STG_DynamicDiag_Duty;
extern const uint16_t K_Clutch_STG_DynamicDiag_Duty;

extern const uint16_t K_Motor1_OC_DynamicDiag_Duty;
extern const uint16_t K_Motor2_OC_DynamicDiag_Duty;
extern const uint16_t K_CinchMotor_OC_DynamicDiag_Duty;
extern const uint16_t K_ReleaseMotor_OC_DynamicDiag_Duty;
extern const uint16_t K_Buzzer_OC_DynamicDiag_Duty;
extern const uint16_t K_Clutch_OC_DynamicDiag_Duty;

extern const uint16_t K_Motor1_STB_DynamicDiag_Duty;
extern const uint16_t K_Motor2_STB_DynamicDiag_Duty;
extern const uint16_t K_CinchMotor_STB_DynamicDiag_Duty;
extern const uint16_t K_ReleaseMotor_STB_DynamicDiag_Duty;
extern const uint16_t K_Buzzer_STB_DynamicDiag_Duty;
extern const uint16_t K_Clutch_STB_DynamicDiag_Duty;

extern const uint16_t K_Motor1_STB_DynamicDiag_Duty_LowLimit;
extern const uint16_t K_Motor2_STB_DynamicDiag_Duty_LowLimit;
extern const uint16_t K_CinchMotor_STB_DynamicDiag_Duty_LowLimit;
extern const uint16_t K_ReleaseMotor_STB_DynamicDiag_Duty_LowLimit;
extern const uint16_t K_Buzzer_STB_DynamicDiag_Duty_LowLimit;
extern const uint16_t K_Clutch_STB_DynamicDiag_Duty_LowLimit;

extern const uint16_t K_Motor1_SCL_DynamicDiag_Duty;
extern const uint16_t K_Motor2_SCL_DynamicDiag_Duty;
extern const uint16_t K_CinchMotor_SCL_DynamicDiag_Duty;
extern const uint16_t K_ReleaseMotor_SCL_DynamicDiag_Duty;
extern const uint16_t K_Buzzer_SCL_DynamicDiag_Duty;
extern const uint16_t K_Clutch_SCL_DynamicDiag_Duty;

extern const uint16_t K_Motor1_Current_STG_DynamicDiag_Value;
extern const uint16_t K_Motor2_Current_STG_DynamicDiag_Value;
extern const uint16_t K_CinchMotor_Current_STG_DynamicDiag_Value;
extern const uint16_t K_Motor4_Current_STG_DynamicDiag_Value;
extern const uint16_t K_ReleaseMotor_Current_STG_DynamicDiag_Value;
extern const uint16_t K_Buzzer_Current_STG_DynamicDiag_Value;
extern const uint16_t K_Clutch_Current_STG_DynamicDiag_Value;

extern const uint16_t K_ReleaseMotor_Current_STB_StaticDiag_Value;
extern const uint16_t K_Buzzer_Current_STB_StaticDiag_Value;
extern const uint16_t K_Clutch_Current_STB_StaticDiag_Value;

extern const uint16_t K_Motor1_Current_OC_DynamicDiag_Value;
extern const uint16_t K_Motor2_Current_OC_DynamicDiag_Value;
extern const uint16_t K_CinchMotor_Current_OC_DynamicDiag_Value;
extern const uint16_t K_Motor4_Current_OC_DynamicDiag_Value;
extern const uint16_t K_ReleaseMotor_Current_OC_DynamicDiag_Value;
extern const uint16_t K_Buzzer_Current_OC_DynamicDiag_Value;
extern const uint16_t K_Clutch_Current_OC_DynamicDiag_Value;

extern const uint16_t K_Motor1_Current_STB_DynamicDiag_Value;
extern const uint16_t K_Motor2_Current_STB_DynamicDiag_Value;
extern const uint16_t K_CinchMotor_Current_STB_DynamicDiag_Value;
extern const uint16_t K_Motor4_Current_STB_DynamicDiag_Value;
extern const uint16_t K_ReleaseMotor_Current_STB_DynamicDiag_Value;
extern const uint16_t K_Buzzer_Current_STB_DynamicDiag_Value;
extern const uint16_t K_Clutch_Current_STB_DynamicDiag_Value;

extern const uint16_t K_Motor1_Current_STB_DynamicDiag_Value_HighLimit;
extern const uint16_t K_Motor2_Current_STB_DynamicDiag_Value_HighLimit;
extern const uint16_t K_CinchMotor_Current_STB_DynamicDiag_Value_HighLimit;
extern const uint16_t K_Motor4_Current_STB_DynamicDiag_Value_HighLimit;
extern const uint16_t K_ReleaseMotor_Current_STB_DynamicDiag_Value_HighLimit;
extern const uint16_t K_Buzzer_Current_STB_DynamicDiag_Value_HighLimit;
extern const uint16_t K_Clutch_Current_STB_DynamicDiag_Value_HighLimit;

extern const uint16_t K_Motor1_Current_STB_DynamicDiag_Value_LowLimit;
extern const uint16_t K_Motor2_Current_STB_DynamicDiag_Value_LowLimit;
extern const uint16_t K_CinchMotor_Current_STB_DynamicDiag_Value_LowLimit;
extern const uint16_t K_Motor4_Current_STB_DynamicDiag_Value_LowLimit;
extern const uint16_t K_ReleaseMotor_Current_STB_DynamicDiag_Value_LowLimit;
extern const uint16_t K_Buzzer_Current_STB_DynamicDiag_Value_LowLimit;
extern const uint16_t K_Clutch_Current_STB_DynamicDiag_Value_LowLimit;

extern const uint16_t K_Motor1_Current_SCL_DynamicDiag_Value;
extern const uint16_t K_Motor2_Current_SCL_DynamicDiag_Value;
extern const uint16_t K_CinchMotor_Current_SCL_DynamicDiag_Value;
extern const uint16_t K_Motor4_Current_SCL_DynamicDiag_Value;
extern const uint16_t K_ReleaseMotor_Current_SCL_DynamicDiag_Value;
extern const uint16_t K_Buzzer_Current_SCL_DynamicDiag_Value;
extern const uint16_t K_Clutch_Current_SCL_DynamicDiag_Value;

extern const uint16_t K_Motor1_P_STG_DynamicDiag_Ratio_LowLimit;  
extern const uint16_t K_Motor1_P_STG_DynamicDiag_Ratio_HighLimit;
extern const uint16_t K_Motor1_N_STG_DynamicDiag_Ratio_LowLimit;
extern const uint16_t K_Motor1_N_STG_DynamicDiag_Ratio_HighLimit;

extern const uint16_t K_Motor1_P_OC_DynamicDiag_Ratio_LowLimit;  
extern const uint16_t K_Motor1_P_OC_DynamicDiag_Ratio_HighLimit;
extern const uint16_t K_Motor1_N_OC_DynamicDiag_Ratio_LowLimit;
extern const uint16_t K_Motor1_N_OC_DynamicDiag_Ratio_HighLimit;

extern const uint16_t K_Motor1_P_STB_DynamicDiag_Ratio_LowLimit;  
extern const uint16_t K_Motor1_P_STB_DynamicDiag_Ratio_HighLimit;
extern const uint16_t K_Motor1_N_STB_DynamicDiag_Ratio_LowLimit;
extern const uint16_t K_Motor1_N_STB_DynamicDiag_Ratio_HighLimit;

extern const uint16_t K_Motor1_P_Normal_DynamicDiag_Ratio_LowLimit;  
extern const uint16_t K_Motor1_P_Normal_DynamicDiag_Ratio_HighLimit;
extern const uint16_t K_Motor1_N_Normal_DynamicDiag_Ratio_LowLimit;
extern const uint16_t K_Motor1_N_Normal_DynamicDiag_Ratio_HighLimit;

extern const uint16_t K_Motor2_P_STG_DynamicDiag_Ratio_LowLimit;  
extern const uint16_t K_Motor2_P_STG_DynamicDiag_Ratio_HighLimit;
extern const uint16_t K_Motor2_N_STG_DynamicDiag_Ratio_LowLimit;
extern const uint16_t K_Motor2_N_STG_DynamicDiag_Ratio_HighLimit;

extern const uint16_t K_Motor2_P_OC_DynamicDiag_Ratio_LowLimit;  
extern const uint16_t K_Motor2_P_OC_DynamicDiag_Ratio_HighLimit;
extern const uint16_t K_Motor2_N_OC_DynamicDiag_Ratio_LowLimit;
extern const uint16_t K_Motor2_N_OC_DynamicDiag_Ratio_HighLimit;

extern const uint16_t K_Motor2_P_STB_DynamicDiag_Ratio_LowLimit;  
extern const uint16_t K_Motor2_P_STB_DynamicDiag_Ratio_HighLimit;
extern const uint16_t K_Motor2_N_STB_DynamicDiag_Ratio_LowLimit;
extern const uint16_t K_Motor2_N_STB_DynamicDiag_Ratio_HighLimit;

extern const uint16_t K_Motor2_P_Normal_DynamicDiag_Ratio_LowLimit;  
extern const uint16_t K_Motor2_P_Normal_DynamicDiag_Ratio_HighLimit;
extern const uint16_t K_Motor2_N_Normal_DynamicDiag_Ratio_LowLimit;
extern const uint16_t K_Motor2_N_Normal_DynamicDiag_Ratio_HighLimit;

extern const uint16_t K_CinchMotor_P_STG_DynamicDiag_Ratio_LowLimit;  
extern const uint16_t K_CinchMotor_P_STG_DynamicDiag_Ratio_HighLimit;
extern const uint16_t K_CinchMotor_N_STG_DynamicDiag_Ratio_LowLimit;
extern const uint16_t K_CinchMotor_N_STG_DynamicDiag_Ratio_HighLimit;

extern const uint16_t K_CinchMotor_P_OC_DynamicDiag_Ratio_LowLimit;  
extern const uint16_t K_CinchMotor_P_OC_DynamicDiag_Ratio_HighLimit;
extern const uint16_t K_CinchMotor_N_OC_DynamicDiag_Ratio_LowLimit;
extern const uint16_t K_CinchMotor_N_OC_DynamicDiag_Ratio_HighLimit;

extern const uint16_t K_CinchMotor_P_STB_DynamicDiag_Ratio_LowLimit;  
extern const uint16_t K_CinchMotor_P_STB_DynamicDiag_Ratio_HighLimit;
extern const uint16_t K_CinchMotor_N_STB_DynamicDiag_Ratio_LowLimit;
extern const uint16_t K_CinchMotor_N_STB_DynamicDiag_Ratio_HighLimit;

extern const uint16_t K_CinchMotor_P_Normal_DynamicDiag_Ratio_LowLimit;  
extern const uint16_t K_CinchMotor_P_Normal_DynamicDiag_Ratio_HighLimit;
extern const uint16_t K_CinchMotor_N_Normal_DynamicDiag_Ratio_LowLimit;
extern const uint16_t K_CinchMotor_N_Normal_DynamicDiag_Ratio_HighLimit;

extern const uint16_t K_Motor4_P_STG_DynamicDiag_Ratio_LowLimit;  
extern const uint16_t K_Motor4_P_STG_DynamicDiag_Ratio_HighLimit;
extern const uint16_t K_Motor4_N_STG_DynamicDiag_Ratio_LowLimit;
extern const uint16_t K_Motor4_N_STG_DynamicDiag_Ratio_HighLimit;

extern const uint16_t K_Motor4_P_OC_DynamicDiag_Ratio_LowLimit;  
extern const uint16_t K_Motor4_P_OC_DynamicDiag_Ratio_HighLimit;
extern const uint16_t K_Motor4_N_OC_DynamicDiag_Ratio_LowLimit;
extern const uint16_t K_Motor4_N_OC_DynamicDiag_Ratio_HighLimit;

extern const uint16_t K_Motor4_P_STB_DynamicDiag_Ratio_LowLimit;  
extern const uint16_t K_Motor4_P_STB_DynamicDiag_Ratio_HighLimit;
extern const uint16_t K_Motor4_N_STB_DynamicDiag_Ratio_LowLimit;
extern const uint16_t K_Motor4_N_STB_DynamicDiag_Ratio_HighLimit;

extern const uint16_t K_Motor4_P_Normal_DynamicDiag_Ratio_LowLimit;  
extern const uint16_t K_Motor4_P_Normal_DynamicDiag_Ratio_HighLimit;
extern const uint16_t K_Motor4_N_Normal_DynamicDiag_Ratio_LowLimit;
extern const uint16_t K_Motor4_N_Normal_DynamicDiag_Ratio_HighLimit;

extern const uint16_t K_Motor4_P_STG_DynamicDiag_Ratio_LowLimit;  
extern const uint16_t K_Motor4_P_STG_DynamicDiag_Ratio_HighLimit;
extern const uint16_t K_Motor4_N_STG_DynamicDiag_Ratio_LowLimit;
extern const uint16_t K_Motor4_N_STG_DynamicDiag_Ratio_HighLimit;

extern const uint16_t K_Motor4_P_OC_DynamicDiag_Ratio_LowLimit;  
extern const uint16_t K_Motor4_P_OC_DynamicDiag_Ratio_HighLimit;
extern const uint16_t K_Motor4_N_OC_DynamicDiag_Ratio_LowLimit;
extern const uint16_t K_Motor4_N_OC_DynamicDiag_Ratio_HighLimit;

extern const uint16_t K_Motor4_P_STB_DynamicDiag_Ratio_LowLimit;  
extern const uint16_t K_Motor4_P_STB_DynamicDiag_Ratio_HighLimit;
extern const uint16_t K_Motor4_N_STB_DynamicDiag_Ratio_LowLimit;
extern const uint16_t K_Motor4_N_STB_DynamicDiag_Ratio_HighLimit;

extern const uint16_t K_Motor4_P_Normal_DynamicDiag_Ratio_LowLimit;  
extern const uint16_t K_Motor4_P_Normal_DynamicDiag_Ratio_HighLimit;
extern const uint16_t K_Motor4_N_Normal_DynamicDiag_Ratio_LowLimit;
extern const uint16_t K_Motor4_N_Normal_DynamicDiag_Ratio_HighLimit;

extern const uint16_t K_ReleaseMotor_P_STG_DynamicDiag_Ratio_LowLimit;  
extern const uint16_t K_ReleaseMotor_P_STG_DynamicDiag_Ratio_HighLimit;

extern const uint16_t K_ReleaseMotor_P_OC_DynamicDiag_Ratio_LowLimit;  
extern const uint16_t K_ReleaseMotor_P_OC_DynamicDiag_Ratio_HighLimit;

extern const uint16_t K_ReleaseMotor_P_STB_DynamicDiag_Ratio_LowLimit;  
extern const uint16_t K_ReleaseMotor_P_STB_DynamicDiag_Ratio_HighLimit;

extern const uint16_t K_ReleaseMotor_P_Normal_DynamicDiag_Ratio_LowLimit;  
extern const uint16_t K_ReleaseMotor_P_Normal_DynamicDiag_Ratio_HighLimit;

extern const uint16_t K_Buzzer_P_STG_DynamicDiag_Ratio_LowLimit;  
extern const uint16_t K_Buzzer_P_STG_DynamicDiag_Ratio_HighLimit;

extern const uint16_t K_Buzzer_P_OC_DynamicDiag_Ratio_LowLimit;  
extern const uint16_t K_Buzzer_P_OC_DynamicDiag_Ratio_HighLimit;

extern const uint16_t K_Buzzer_P_STB_DynamicDiag_Ratio_LowLimit;  
extern const uint16_t K_Buzzer_P_STB_DynamicDiag_Ratio_HighLimit;

extern const uint16_t K_Clutch_P_Normal_DynamicDiag_Ratio_LowLimit;  
extern const uint16_t K_Clutch_P_Normal_DynamicDiag_Ratio_HighLimit;

extern const uint16_t K_Clutch_P_STG_DynamicDiag_Ratio_LowLimit;  
extern const uint16_t K_Clutch_P_STG_DynamicDiag_Ratio_HighLimit;

extern const uint16_t K_Clutch_P_OC_DynamicDiag_Ratio_LowLimit;  
extern const uint16_t K_Clutch_P_OC_DynamicDiag_Ratio_HighLimit;

extern const uint16_t K_Clutch_P_STB_DynamicDiag_Ratio_LowLimit;  
extern const uint16_t K_Clutch_P_STB_DynamicDiag_Ratio_HighLimit;

extern const uint16_t K_Clutch_P_Normal_DynamicDiag_Ratio_LowLimit;  
extern const uint16_t K_Clutch_P_Normal_DynamicDiag_Ratio_HighLimit;

extern const uint16_t K_BatteryVoltage_StaticDiag_VolAbove;
extern const uint16_t K_BatteryVoltage_StaticDiag_VolBelow;
extern const uint16_t K_BatteryVoltage_StaticDiag_Recovery_Low;
extern const uint16_t K_BatteryVoltage_StaticDiag_Recovery_High;
extern const uint16_t K_BatteryVoltage_StaticDiag_Time; 

extern const uint16_t K_BatteryVoltage_DynamicDiag_VolAbove;
extern const uint16_t K_BatteryVoltage_DynamicDiag_VolBelow;
extern const uint16_t K_BatteryVoltage_DynamicDiag_Recovery_Low;
extern const uint16_t K_BatteryVoltage_DynamicDiag_Recovery_High;
extern const uint16_t K_BatteryVoltage_DynamicDiag_Time;

extern const uint16_t K_Temperature_StaticDiag_Time;
extern const uint16_t K_LatchSwitch_StaticDiag_Time;

extern const uint16_t K_ModeSwitch_STG_StaticDiag_Ratio; 
extern const uint16_t K_ModeSwitch_OC_StaticDiag_Ratio;
extern const uint16_t K_ModeSwitch_STB_StaticDiag_Ratio;
extern const uint16_t K_ModeSwitch_StaticDiag_Time;

extern const uint16_t K_ModeSwitch_STG_StaticDiag_Value; 
extern const uint16_t K_ModeSwitch_OC_StaticDiag_Value;
extern const uint16_t K_ModeSwitch_STB_StaticDiag_Value;
extern const uint16_t K_ModeSwitch_StaticDiag_Time;

extern const uint16_t K_AntiPinch_STG_DiagValue;
extern const uint16_t K_AntiPinch_OC_DiagValue;
extern const uint16_t K_AntiPinch_STB_DiagValue;
extern const uint16_t K_AntiPinch_STG_StaticDiag_Time;
extern const uint16_t K_AntiPinch_OC_StaticDiag_Time;
extern const uint16_t K_AntiPinch_STB_StaticDiag_Time;
extern const uint16_t K_AntiPinch_Active_StaticDiag_Time;
extern const uint16_t K_AntiPinch_Normal_StaticDiag_Time;
extern const uint16_t K_AntiPinch_DynamicDiag_Time;

extern const uint16_t K_AntiPinchRight_STG_DiagValue; 
extern const uint16_t K_AntiPinchRight_OC_DiagValue;
extern const uint16_t K_AntiPinchRight_STB_DiagValue;
extern const uint16_t K_AntiPinchRight_STG_StaticDiag_Time;
extern const uint16_t K_AntiPinchRight_OC_StaticDiag_Time;
extern const uint16_t K_AntiPinchRight_STB_StaticDiag_Time;
extern const uint16_t K_AntiPinchRight_Active_StaticDiag_Time;
extern const uint16_t K_AntiPinchRight_Normal_StaticDiag_Time;
extern const uint16_t K_AntiPinchRight_DynamicDiag_Time;

extern const uint16_t K_AntiPinchLeft_STG_DiagValue; 
extern const uint16_t K_AntiPinchLeft_OC_DiagValue;
extern const uint16_t K_AntiPinchLeft_STB_DiagValue;
extern const uint16_t K_AntiPinchLeft_STG_StaticDiag_Time;
extern const uint16_t K_AntiPinchLeft_OC_StaticDiag_Time;
extern const uint16_t K_AntiPinchLeft_STB_StaticDiag_Time;
extern const uint16_t K_AntiPinchLeft_Active_StaticDiag_Time;
extern const uint16_t K_AntiPinchLeft_Normal_StaticDiag_Time;
extern const uint16_t K_AntiPinchLeft_DynamicDiag_Time; 

extern const uint16_t K_OpenCloseSwitch_STG_StaticDiag_Time;
extern const uint16_t K_OutsideHandleSwitch_STG_StaticDiag_Time;
extern const uint16_t K_ShutFaceSwitch_STG_StaticDiag_Time;  
extern const uint16_t K_ShutFaceLockSwitch_STG_StaticDiag_Time;
extern const uint16_t K_OpenCloseSwitch_Normal_StaticDiag_Time;
extern const uint16_t K_OutsideHandleSwitch_Normal_StaticDiag_Time;
extern const uint16_t K_ShutFaceSwitch_Normal_StaticDiag_Time; 
extern const uint16_t K_ShutFaceLockSwitch_Normal_StaticDiag_Time;

extern const uint16_t K_PowerSupply_Error_StaticDiag_Time;
extern const uint16_t K_PowerSupply_Normal_StaticDiag_Time;

extern const uint16_t K_DigitalSupply_Error_StaticDiag_Time;
extern const uint16_t K_DigitalSupply_Normal_StaticDiag_Time;

extern const uint16_t K_HallPower1_Normal_StaticDiag_Time;
extern const uint16_t K_HallPower2_Normal_StaticDiag_Time;
extern const uint16_t K_HallPower1_Failure_StaticDiag_Time;
extern const uint16_t K_HallPower2_Failure_StaticDiag_Time;

extern const uint16_t K_HandleOpenSwitch_StaticDiag_Time; 
extern const uint16_t K_HandleCloseSwitch_StaticDiag_Time;

extern const uint16_t K_HallA1_OverRange_DynamicDiag_HallCount;
extern const uint16_t K_HallA2_OverRange_DynamicDiag_HallCount;
extern const uint16_t K_HallB1_OverRange_DynamicDiag_HallCount;
extern const uint16_t K_HallB2_OverRange_DynamicDiag_HallCount;

extern const uint16_t K_HallA1_NoHall_DynamicDiag_HallCount;
extern const uint16_t K_HallA2_NoHall_DynamicDiag_HallCount;
extern const uint16_t K_HallB1_NoHall_DynamicDiag_HallCount;
extern const uint16_t K_HallB2_NoHall_DynamicDiag_HallCount;

extern const uint16_t K_Motor1_DynamicDiag_HallCount_Delta;
extern const uint16_t K_Motor2_DynamicDiag_HallCount_Delta;

extern const uint16_t K_HallA_DynamicDiag_Time;  
extern const uint16_t K_HallB_DynamicDiag_Time;  

extern const uint16_t K_Hall_StaticDiag_Delay_Time;
extern const uint16_t K_HallA1_StaticDiag_Time;
extern const uint16_t K_HallA2_StaticDiag_Time;
extern const uint16_t K_HallB1_StaticDiag_Time;
extern const uint16_t K_HallB2_StaticDiag_Time;
/*********************************************************************************************
**    Buzzer Control
*********************************************************************************************/

extern const uint16_t K_Buzzer_Base_Duty;

extern const uint16_t K_Mode_0_Period;
extern const uint16_t K_Mode_0_Duty; 

extern const uint16_t K_Mode_1_Period;
extern const uint16_t K_Mode_1_Duty;

extern const uint16_t K_Mode_2_Period;
extern const uint16_t K_Mode_2_Duty;

extern const uint16_t K_Mode_3_Period;
extern const uint16_t K_Mode_3_Duty;

extern const uint16_t K_Mode_4_Period;
extern const uint16_t K_Mode_4_Duty;

extern const uint16_t K_Mode_5_Period;
extern const uint16_t K_Mode_5_Duty;

extern const uint16_t K_Mode_6_Period;
extern const uint16_t K_Mode_6_Duty;

extern const uint16_t K_Speaker_Working_Time;

extern const uint16_t K_Mode_0_Speaker_Break_Time;
extern const uint16_t K_Mode_1_Speaker_Break_Time;
extern const uint16_t K_Mode_2_Speaker_Break_Time;
extern const uint16_t K_Mode_3_Speaker_Break_Time;
extern const uint16_t K_Mode_4_Speaker_Break_Time;
extern const uint16_t K_Mode_5_Speaker_Break_Time;
extern const uint16_t K_Mode_6_Speaker_Break_Time;

extern const uint16_t K_Speaker_Music_Enable;
extern const uint16_t K_Normal_Buzzer_Enable;


#ifdef _CONFIG_Flasher
extern const uint16_t K_Mode_0_Flasher_Break_Time;
extern const uint16_t K_Mode_1_Flasher_Break_Time;
extern const uint16_t K_Mode_2_Flasher_Break_Time;
extern const uint16_t K_Mode_3_Flasher_Break_Time;
extern const uint16_t K_Mode_4_Flasher_Break_Time;
extern const uint16_t K_Mode_5_Flasher_Break_Time;
extern const uint16_t K_Mode_6_Flasher_Break_Time;
#endif


 /*********************************************************************************************
**    Telltals Control
*********************************************************************************************/


/*********************************************************************************************
**    sleep_manage
*********************************************************************************************/
extern const uint16_t K_WakeupMiniTime_Time;
extern const uint16_t K_ReadyToSleep_InClose_Delay_Time;
extern const uint16_t K_ReadyToSleep_InOpen_Delay_Time;
extern const uint16_t K_DataUpdateBeforeSleep_Time;
extern const uint16_t K_SleepInOpen_LongTime_Time;

/*********************************************************************************************
**    ecu_fft_test
*********************************************************************************************/
extern const uint16_t K_FFT_Motor1_Current_Calibrate1_Duty;
extern const uint16_t K_FFT_Motor2_Current_Calibrate1_Duty;
extern const uint16_t K_FFT_CinchMotor_Current_Calibrate1_Duty;
extern const uint16_t K_FFT_ReleaseMotor_Current_Calibrate1_Duty;

extern const uint16_t K_FFT_Motor1_Current_Calibrate2_Duty;
extern const uint16_t K_FFT_Motor2_Current_Calibrate2_Duty;
extern const uint16_t K_FFT_CinchMotor_Current_Calibrate2_Duty;
extern const uint16_t K_FFT_ReleaseMotor_Current_Calibrate2_Duty;

extern const uint16_t K_Motor1_Current_Calibrate_Time; 
extern const uint16_t K_Motor2_Current_Calibrate_Time;
extern const uint16_t K_CinchMotor_Current_Calibrate_Time;
extern const uint16_t K_ReleaseMotor_Current_Calibrate_Time;

extern const uint16_t K_Motor1_Current_Calibrate_Timeout;
extern const uint16_t K_Motor2_Current_Calibrate_Timeout;
extern const uint16_t K_CinchMotor_Current_Calibrate_Timeout;
extern const uint16_t K_ReleaseMotor_Current_Calibrate_Timeout;

extern const uint16_t K_Motor1_Calibrate_Sampling_Size;
extern const uint16_t K_Motor2_Calibrate_Sampling_Size;    
extern const uint16_t K_CinchMotor_Calibrate_Sampling_Size;
extern const uint16_t K_ReleaseMotor_Calibrate_Sampling_Size;  

extern const uint16_t K_Motor1_Current_Real_Calibrate1_Value;
extern const uint16_t K_Motor2_Current_Real_Calibrate1_Value;
extern const uint16_t K_CinchMotor_Current_Real_Calibrate1_Value;
extern const uint16_t K_ReleaseMotor_Current_Real_Calibrate1_Value;

extern const uint16_t K_Motor1_Current_Real_Calibrate2_Value;
extern const uint16_t K_Motor2_Current_Real_Calibrate2_Value;
extern const uint16_t K_CinchMotor_Current_Real_Calibrate2_Value;
extern const uint16_t K_ReleaseMotor_Current_Real_Calibrate2_Value;
extern const uint16_t K_Motor4_Current_Real_Calibrate2_Value;

extern const uint16_t K_Motor1_FET_Base_Offset_Calibrate_Compensation;
extern const uint16_t K_Motor1_FET_Cal_Ratio_Calibrate_Compensation;
extern const uint16_t K_Motor2_FET_Base_Offset_Calibrate_Compensation;
extern const uint16_t K_Motor2_FET_Cal_Ratio_Calibrate_Compensation;
extern const uint16_t K_CinchMotor_FET_Base_Offset_Calibrate_Compensation;
extern const uint16_t K_CinchMotor_FET_Cal_Ratio_Calibrate_Compensation;
extern const uint16_t K_Motor4_FET_Base_Offset_Calibrate_Compensation;
extern const uint16_t K_Motor4_FET_Cal_Ratio_Calibrate_Compensation;
extern const uint16_t K_ReleaseMotor_FET_Base_Offset_Calibrate_Compensation;
extern const uint16_t K_ReleaseMotor_FET_Cal_Ratio_Calibrate_Compensation;

extern const uint16_t K_Motor1_Current_Offset_Compensation_Limit;
extern const uint16_t K_Motor2_Current_Offset_Compensation_Limit;
extern const uint16_t K_CinchMotor_Current_Offset_Compensation_Limit;
extern const uint16_t K_Motor4_Current_Offset_Compensation_Limit;
extern const uint16_t K_ReleaseMotor_Current_Offset_Compensation_Limit;

#ifdef _CONFIG_Motor4
extern const uint16_t K_FFT_Motor4_Current_Calibrate1_Duty;
extern const uint16_t K_FFT_Motor4_Current_Calibrate2_Duty;
extern const uint16_t K_Motor4_Current_Calibrate_Time;
extern const uint16_t K_Motor4_Calibrate_Sampling_Size;
extern const uint16_t K_Motor4_Current_Calibrate_Timeout;
extern const uint16_t K_Motor4_Current_Real_Calibrate1_Value;
#endif

/*********************************************************************************************
**    mgb_eol_test
*********************************************************************************************/
extern const uint16_t K_Motor1_MGB_Open_Duty;
extern const uint16_t K_Motor2_MGB_Open_Duty;

extern const uint16_t K_MGB_TestOpen_Time;
extern const uint16_t K_MGB_TestPass_Time;
extern const uint16_t K_MGB_TestFail_Time;

extern const uint16_t K_MGB_Test_HallCount;

extern const uint16_t K_MGB_TestOpen_Current_Time;
extern const uint16_t K_MGB_TestOpen_Current_Limit;

/*********************************************************************************************
**    did process
*********************************************************************************************/
extern const uint16_t K_CPID_Motor1_Open_Duty_Default;
extern const uint16_t K_CPID_Motor2_Open_Duty_Default;
extern const uint16_t K_CPID_CinchMotor_Cinch_Duty_Default;
extern const uint16_t K_CPID_ReleaseMotor_Release_Duty_Default;

extern const uint16_t K_CPID_Motor1_Close_Duty_Default;
extern const uint16_t K_CPID_Motor2_Close_Duty_Default;
extern const uint16_t K_CPID_CinchMotor_Netrual_Duty_Default;

extern const uint16_t K_CPID_SpindleMotor_Open_Timeout;
extern const uint16_t K_CPID_SpindleMotor_Close_Timeout;

extern const uint16_t K_CPID_CinchMotor_Cinch_Timeout;
extern const uint16_t K_CPID_CinchMotor_Netrual_Timeout;

extern const uint16_t K_CPID_ReleaseMotor_Release_Timeout;
extern const uint16_t K_CPID_Buzzer_Work_Timeout;

extern const uint16_t K_CPID_Clutch_Work_Timeout;
extern const uint16_t K_CPID_Backlight_Work_Timeout;
extern const uint16_t K_CPID_LSD_Work_Timeout;

extern const uint16_t K_CPID_Motor1_FET_Calibrate_Time;
extern const uint16_t K_CPID_Motor1_Current_Voltage_Value_Compensation;
extern const uint16_t K_CPID_Motor1_FET_Calibrate_Timeout;

extern const uint16_t K_CPID_Motor2_FET_Calibrate_Time;
extern const uint16_t K_CPID_Motor2_Current_Voltage_Value_Compensation;
extern const uint16_t K_CPID_Motor2_FET_Calibrate_Timeout;

extern const uint16_t K_CPID_CinchMotor_FET_Calibrate_Time;
extern const uint16_t K_CPID_CinchMotor_Current_Voltage_Value_Compensation;
extern const uint16_t K_CPID_CinchMotor_FET_Calibrate_Timeout;

extern const uint16_t K_CPID_Motor4_Open_Duty_Default;
extern const uint16_t K_CPID_Motor4_Close_Duty_Default;
extern const uint16_t K_CPID_Motor4_Open_Timeout; 
extern const uint16_t K_CPID_Motor4_Close_Timeout; 

extern const uint16_t K_CPID_Motor4_FET_Calibrate_Time;
extern const uint16_t K_CPID_Motor4_Current_Voltage_Value_Compensation;
extern const uint16_t K_CPID_Motor4_FET_Calibrate_Timeout;

extern const uint16_t K_IO_Motor1_Open_Duty_Default;
extern const uint16_t K_IO_Motor2_Open_Duty_Default;
extern const uint16_t K_IO_CinchMotor_Cinch_Duty_Default;
extern const uint16_t K_IO_ReleaseMotor_Release_Duty_Default;

extern const uint16_t K_IO_Motor1_Close_Duty_Default;
extern const uint16_t K_IO_Motor2_Close_Duty_Default;
extern const uint16_t K_IO_CinchMotor_Netrual_Duty_Default;

extern const uint16_t K_IO_SpindleMotor_Open_Timeout; /*10ms x */
extern const uint16_t K_IO_SpindleMotor_Close_Timeout; /*10ms x */
extern const uint16_t K_IO_ReleaseMotor_Release_Timeout;

extern const uint16_t K_IO_Motor1_Open_Timeout;
extern const uint16_t K_IO_Motor1_Close_Timeout;
extern const uint16_t K_IO_Motor2_Open_Timeout;
extern const uint16_t K_IO_Motor2_Close_Timeout;

extern const uint16_t K_IO_CinchMotor_Cinch_Timeout; /*10ms x */
extern const uint16_t K_IO_CinchMotor_Netrual_Timeout; /*10ms x */
extern const uint16_t K_TriggerSignal_Timeout;
extern const uint16_t K_CPIDInd_LearnPowerClose_Continue_Delay_Time;

/*********************************************************************************************
**    ecu_emc_test
*********************************************************************************************/

extern const uint16_t K_Motor1_EMC_Open_Duty;
extern const uint16_t K_Motor2_EMC_Open_Duty;
extern const uint16_t K_CinchMotor_EMC_Cinch_Duty;
extern const uint16_t K_ReleaseMotor_EMC_Release_Duty;

extern const uint16_t K_Motor1_EMC_Close_Duty;
extern const uint16_t K_Motor2_EMC_Close_Duty;
extern const uint16_t K_CinchMotor_EMC_Netrual_Duty;

#ifdef _CONFIG_Motor4
extern const uint16_t K_Motor4_EMC_Open_Duty;
extern const uint16_t K_Motor4_EMC_Close_Duty;
#endif

extern const uint16_t K_EMC_NoAction_Stop_Time;
extern const uint16_t K_EMC_CinchMotor_Neutral_Stop_Time;
extern const uint16_t K_EMC_CinchMotor_Neutral_Start_Time;

extern const uint16_t K_EMC_SpindleMotor_Open_Stop_Time;
extern const uint16_t K_EMC_SpindleMotor_Open_Start_Time;

extern const uint16_t K_EMC_SpindleMotor_Close_Stop_Time;
extern const uint16_t K_EMC_SpindleMotor_Close_Start_Time;

extern const uint16_t K_EMC_CinchMotor_Cinch_Stop_Time;
extern const uint16_t K_EMC_CinchMotor_Cinch_Start_Time;

extern const uint16_t K_EMC_ReleaseMotor_Release_Stop_Time;
extern const uint16_t K_EMC_ReleaseMotor_Release_Start_Time;
extern const uint16_t K_EMC_BrakeToGround_Delay_Time;
/*********************************************************************************************
**    Network Manage
*********************************************************************************************/
extern const uint16_t K_NM_Comm_Reset_Timeout;
extern const uint16_t K_SGMWNM_Init_Timeout;

extern const uint16_t K_NM_Continue_Message_Period_Time;
extern const uint16_t K_SGMWNM_AppTx_Delay_Time;
extern const uint16_t K_NM_Continue_Message_BusOff_Time;
extern const uint16_t K_Send_NM_Initialize_BusOffDelay_Time;

extern const uint16_t K_NM_AppTx_Stop_Delay_Time;
extern const uint16_t K_NM_RemoteEvent_Timeout;
extern const uint16_t K_NM_LocalEvent_Short_Timeout;
extern const uint16_t K_NM_LocalEvent_Long_Timeout;
extern const uint32_t K_NM_LocalEvent_MinTime;

extern const uint16_t K_NM_AfterWakeup_Time;
extern const uint16_t K_UDS_RemoteEvent_Timeout;
extern const uint16_t K_Com_TxStart_Request_Time;
extern const uint32_t K_NM_LocalEvent_Delay_Time;
extern const uint16_t K_UDS_KeepEvent_Timeout;
extern const uint16_t K_Igntion_KeepEvent_Timeout;
extern const uint16_t K_NMFrame_Timeout;
extern const uint16_t K_UDSFrame_Timeout;

/*********************************************************************************************
**    Power Manage
*********************************************************************************************/
extern const uint16_t K_VBATT1_Voltage_Dropping_Rate; 
extern const uint16_t K_VBATT1_Voltage_Rising_Rate;
extern const uint16_t K_VBATT2_Voltage_Time;
extern const uint16_t K_VBATT1_Voltage_PowerDrop_Threshold;
extern const uint16_t K_VBATT1_Voltage_Stable_Rate;
extern const uint16_t K_VBATT1_Voltage_Dropping_Time;

extern const uint16_t K_Power_Manager_Init_Time;
extern const uint16_t K_Hall_Power_OverCurrentShutDown_Voltage;
extern const uint16_t K_HallPower_Recovery_Count_HighLimit;
extern const uint16_t K_HallPower_Recovery_Timeout;
extern const uint16_t K_HallPower_Recovery_Delay_Time;

extern const uint16_t K_HallPower1_OverCurrentShutDown_Voltage;
extern const uint16_t K_HallPower1_Recovery_Count_HighLimit;
extern const uint16_t K_HallPower1_Recovery_Timeout;
extern const uint16_t K_HallPower1_Recovery_Delay_Time;

extern const uint16_t K_HallPower2_OverCurrentShutDown_Voltage;
extern const uint16_t K_HallPower2_Recovery_Count_HighLimit;
extern const uint16_t K_HallPower2_Recovery_Timeout;
extern const uint16_t K_HallPower2_Recovery_Delay_Time;


/*********************************************************************************************
**    memory_manage
*********************************************************************************************/
extern const uint16_t K_MemorySave_Delay_Time;

/*********************************************************************************************
**    dtc_report
*********************************************************************************************/
extern const uint16_t K_OperationCycle_AfterWakeup_Time;
extern const uint16_t K_DTCData_SaveImmediately_Time;

extern const uint16_t K_DTC_PendingCount;     
extern const uint16_t K_DTC_AgingCount; 
extern const uint8_t K_DTC_Mask_Bit;


/*********************************************************************************************
**    mode_control
*********************************************************************************************/
extern const uint16_t K_ECU_Reset_Delay_Time;

/*********************************************************************************************
**    handle_control
*********************************************************************************************/
#ifdef _CONFIG_PowerHandle

#define K_Flag_HandleRequest_TableSize 10
#define K_HandleRequestSource_TableSize 10

extern const uint16_t K_HandlePowerOn_Time;
extern const uint16_t K_HandleWakeUp_Time;
extern const uint16_t K_HandleReset_Time;

extern const uint16_t K_HandlePowerOpening_SoftStall_Time;
extern const uint16_t K_HandlePowerClosing_SoftStall_Time;

extern const uint16_t K_CentralLockSwitch_HandleCommandInterval_Enable;
extern const uint16_t K_HandlePowerOpening_ObstacleDetected_Reverse_Enable;
extern const uint16_t K_HandlePowerClosing_ObstacleDetected_Reverse_Enable;

extern const uint16_t K_HandleCommandInterval_Time;
extern const uint16_t K_CentralLockSwitch_HandleCommandDelay_Time;

extern const uint16_t K_HandlePowerOpening_Timeout;
extern const uint16_t K_HandlePowerClosing_Timeout;

extern const uint16_t K_HandleOpenedFully_Timeout;
extern const uint16_t K_HandleReleased_Timeout;

extern const uint16_t K_ChangeDutyInHandlePowerOpening_1st_Time;
extern const uint16_t K_ChangeDutyInHandlePowerClosing_1st_Time;

extern const uint16_t K_StopBefore_HandlePowerOpening_Time;
extern const uint16_t K_StopBefore_HandlePowerClosing_Time;

extern const uint16_t K_HandleHomePosition_Delay_Time;
extern const uint16_t K_HandleSpreadPosition_Delay_Time;

extern const uint16_t K_HandlePowerOpening_Inrush_Time;
extern const uint16_t K_HandlePowerClosing_Inrush_Time;

extern const uint16_t K_HandleMotor_EnhancedCurrent_DecreasePerTimer;
extern const uint16_t K_HandleMotor_EnhancedCurrent_Decrease_Time;
extern const uint16_t K_HandleMotor_EnhancedCurrent_IncreasePerTimer;
extern const uint16_t K_HandleMotor_EnhancedCurrent_Increase_Time;
extern const uint16_t K_HandleMotor_EnhancedCurrent_Threshold_Time;

extern const uint16_t K_HandleMotor_SoftStall_Detect_Time;
extern const uint16_t K_HandleMotor_FixedCurrent_Detect_Time;

extern const uint16_t K_HandleMotor_EnhancedCurrent_Detect[8][8];
extern const uint16_t K_HandleMotor_SoftStallCurrent_TopLimit[8][8];
extern const uint16_t K_HandleMotor_FixedCurrentStall_TopLimit[8][8];
extern const uint16_t K_HandleMotor_HandlePowerOpening_Duty[8][8];
extern const uint16_t K_HandleMotor_HandlePowerOpening_Duty_2nd[8][8];
extern const uint16_t K_HandleMotor_HandlePowerClosing_Duty[8][8];
extern const uint16_t K_HandleMotor_HandlePowerClosing_Duty_2nd[8][8];
#endif

/*********************************************************************************************
**    Spoiler_control
*********************************************************************************************/
#ifdef _CONFIG_PowerSpoiler

#define K_Flag_SpoilerRequest_TableSize 10
#define K_SpoilerRequestSource_TableSize 10
#define K_Flag_SpoilerObstacleDetected_TableSize 10

extern const uint8_t K_Spoiler_Prop_Open[20];
extern const uint8_t K_Spoiler_PropScale_Open[20];
extern const uint8_t K_Spoiler_Int_Open[20];
extern const uint8_t K_Spoiler_IntScale_Open[20];
extern const uint8_t K_Spoiler_Diff_Open[20];
extern const uint8_t K_Spoiler_DiffScale_Open[20];

extern const uint8_t K_Spoiler_Prop_Close[20];
extern const uint8_t K_Spoiler_PropScale_Close[20];
extern const uint8_t K_Spoiler_Int_Close[20];
extern const uint8_t K_Spoiler_IntScale_Close[20];
extern const uint8_t K_Spoiler_Diff_Close[20];
extern const uint8_t K_Spoiler_DiffScale_Close[20];

extern const uint8_t K_Spoiler_Prop_PushPID;
extern const uint8_t K_Spoiler_PropScale_PushPID;
extern const uint8_t K_Spoiler_Int_PushPID;
extern const uint8_t K_Spoiler_IntScale_PushPID;
extern const uint8_t K_Spoiler_Diff_PushPID;
extern const uint8_t K_Spoiler_DiffScale_PushPID;

extern const uint16_t K_Spoiler_PushPID_HallCount;
extern const uint16_t K_Spoiler_PushPIDSpeed_Tigger_Delta;
extern const uint16_t K_Spoiler_PushPIDSpeed_Quit_Delta;
extern const uint16_t K_Spoiler_PushPID_Timeout;
extern const uint16_t K_Spoiler_PushPID_ObstacleAdder_Timeout;

extern const uint16_t K_SpoilerPowerOn_Time;
extern const uint16_t K_SpoilerWakeUp_Time;
extern const uint16_t K_SpoilerReset_Time;

extern const uint16_t K_SpoilerPowerOpening_SoftStall_Time;
extern const uint16_t K_SpoilerPowerClosing_SoftStall_Time;

extern const uint16_t K_SpoilerPowerOpening_ObstacleDetected_Reverse_Enable;
extern const uint16_t K_SpoilerPowerClosing_ObstacleDetected_Reverse_Enable;

extern const uint16_t K_SpoilerSwitch_ShortPress_LowLimit_Time;
extern const uint16_t K_SpoilerSwitch_ShortPress_HighLimit_Time;
extern const uint16_t K_SpoilerSwitch_LongPress_LowLimit_Time;
extern const uint16_t K_SpoilerSwitch_LongPress_HighLimit_Time;

extern const uint16_t K_SpoilerOpenSwitch_ShortPress_LowLimit_Time;
extern const uint16_t K_SpoilerOpenSwitch_ShortPress_HighLimit_Time;
extern const uint16_t K_SpoilerOpenSwitch_LongPress_LowLimit_Time;
extern const uint16_t K_SpoilerOpenSwitch_LongPress_HighLimit_Time;

extern const uint16_t K_SpoilerCloseSwitch_ShortPress_LowLimit_Time;
extern const uint16_t K_SpoilerCloseSwitch_ShortPress_HighLimit_Time;
extern const uint16_t K_SpoilerCloseSwitch_LongPress_LowLimit_Time;
extern const uint16_t K_SpoilerCloseSwitch_LongPress_HighLimit_Time;

extern const uint16_t K_SpoilerSwitch_LongPress_ManualUnlearn_Time;

extern const uint16_t K_SpoilerCommandInterval_Time;
extern const uint16_t K_CentralLockSwitch_SpoilerCommandInterval_Enable;
extern const uint16_t K_CentralLockSwitch_SpoilerCommandDelay_Time;
extern const uint16_t K_CentralLockSwitch_Wakeup_SpoilerCommandDelay_Time;

extern const uint16_t K_SpoilerSwitch_SpoilerCommandInterval_Enable;
extern const uint16_t K_SpoilerSwitch_SpoilerCommandDelay_Time;
extern const uint16_t K_SpoilerSwitch_Wakeup_SpoilerCommandDelay_Time;

extern const uint16_t K_SpoilerOpenSwitch_SpoilerCommandInterval_Enable;
extern const uint16_t K_SpoilerOpenSwitch_SpoilerCommandDelay_Time;
extern const uint16_t K_SpoilerOpenSwitch_Wakeup_SpoilerCommandDelay_Time;

extern const uint16_t K_SpoilerCloseSwitch_SpoilerCommandInterval_Enable;
extern const uint16_t K_SpoilerCloseSwitch_SpoilerCommandDelay_Time;
extern const uint16_t K_SpoilerCloseSwitch_Wakeup_SpoilerCommandDelay_Time;

extern const uint16_t K_SpoilerCommandInhibition_Min_Time;
extern const uint16_t K_SpoilerSwitch_ShortPress_SpoilerCommandInhibition_Time;
extern const uint16_t K_SpoilerOpenSwitch_ShortPress_SpoilerCommandInhibition_Time;
extern const uint16_t K_SpoilerCloseSwitch_ShortPress_SpoilerCommandInhibition_Time;

extern const uint16_t K_SpoilerPowerOpening_Timeout;
extern const uint16_t K_SpoilerPowerClosing_Timeout;

extern const uint16_t K_Spoiler_StopFromMaxTravel_HallCount;

extern const uint16_t K_SpoilerOpenEnd_SoftStop_HallCount_Compensation;
extern const uint16_t K_SpoilerCloseEnd_SoftStop_HallCount_Compensation;
extern const uint16_t K_SpoilerMiddleEnd_SoftStop_HallCount_Compensation;

extern const uint16_t K_SpoilerOpenEnd_FullOpenSwitchPosition_Compensation;
extern const uint16_t K_SpoilerCloseEnd_FullCloseSwitchPosition_Compensation;
extern const uint16_t K_SpoilerMiddleEnd_MiddleSwitchPosition_Compensation;
extern const uint16_t K_SpoilerFullOpenPosition_Delay_Time;
extern const uint16_t K_SpoilerFullClosePosition_Delay_Time;
extern const uint16_t K_SpoilerMiddlePosition_Delay_Time;

extern const uint16_t K_SpoilerFullOpenSwitchVirtual_HallCount;
extern const uint16_t K_SpoilerFullCloseSwitchVirtual_HallCount;
extern const uint16_t K_SpoilerMiddleSwitchVirtual_HallCount;
extern const uint16_t K_SpoilerMaxPosition_HallCount_Default;
extern const uint16_t K_SpoilerLearnMiniPosition_HallCount;

extern const uint16_t K_SpoilerOpenedFully_Timeout;
extern const uint16_t K_SpoilerReleased_Timeout;
extern const uint16_t K_SpoilerMechFailure_Timeout;

extern const uint16_t K_ChangeDutyInSpoilerPowerOpening_1st_Time;
extern const uint16_t K_ChangeDutyInSpoilerPowerClosing_1st_Time;

extern const uint16_t K_StopBefore_SpoilerPowerOpening_Time;
extern const uint16_t K_StopBefore_SpoilerPowerClosing_Time;

extern const uint16_t K_SpoilerHomePosition_Delay_Time;
extern const uint16_t K_SpoilerSpreadPosition_Delay_Time;

extern const uint16_t K_SpoilerPowerOpening_Inrush_Time;
extern const uint16_t K_SpoilerPowerClosing_Inrush_Time;

extern const uint16_t K_Spoiler_ObstacleIndex;
extern const uint16_t K_Spoiler_HallCountPerObstacleZone_Min;
extern const uint16_t K_Spoiler_HallCountPerObstacleZone_Max;    
extern const uint16_t K_Spoiler_HallCountPerObstacleZone_Default;

extern const uint16_t K_Spoiler_PowerOpening_HallCount_Delta;
extern const uint16_t K_Spoiler_PowerClosing_HallCount_Delta;

extern const uint16_t K_Spoiler_EnhancedCurrent_DecreasePerTimer;
extern const uint16_t K_Spoiler_EnhancedCurrent_Decrease_Time;
extern const uint16_t K_Spoiler_EnhancedCurrent_IncreasePerTimer;
extern const uint16_t K_Spoiler_EnhancedCurrent_Increase_Time;
extern const uint16_t K_Spoiler_EnhancedCurrent_Threshold_Time;

extern const uint16_t K_Spoiler_SoftStall_Detect_Time;
extern const uint16_t K_Spoiler_FixedCurrent_Detect_Time;

extern const uint16_t K_Spoiler_EnhancedCurrent_Detect_PushPID_Open_Adder[10];
extern const uint16_t K_Spoiler_EnhancedCurrent_Detect_PushPID_Close_Adder[10];

extern const uint16_t K_Spoiler_EnhancedCurrent_Detect_Open[8][10];
extern const uint16_t K_Spoiler_EnhancedCurrent_Detect_Open_Temp[8][10];
extern const uint16_t K_Spoiler_EnhancedCurrent_Detect_Close[8][10];
extern const uint16_t K_Spoiler_EnhancedCurrent_Detect_Close_Temp[8][10];

extern const uint16_t K_Spoiler_PositionObstacle_Detect_Delta;
extern const uint16_t K_Spoiler_PositionObstacle_Detect_Open_Timer[10];
extern const uint16_t K_Spoiler_PositionObstacle_Detect_Close_Timer[10];

extern const uint16_t K_Spoiler_HallPluse1Width_Time;
extern const uint16_t K_Spoiler_HallPluse2Width_Time;

extern const uint16_t K_Spoiler_SoftStallCurrent_TopLimit[8][8];
extern const uint16_t K_Spoiler_FixedCurrentStall_TopLimit[8][8];
extern const uint16_t K_Spoiler_SpoilerPowerOpening_Duty[8][8];
extern const uint16_t K_Spoiler_SpoilerPowerClosing_Duty[8][8];

extern const uint16_t K_Spoiler_SpeedZoneIndex;
extern const uint16_t K_Spoiler_HallCountPerSpeedZone_Min;
extern const uint16_t K_Spoiler_HallCountPerSpeedZone_Max;
extern const uint16_t K_Spoiler_HallCountPerSpeedZone_Default;

extern const uint16_t K_Spoiler_Desired_Open_Speed[8][20];
extern const uint16_t K_Spoiler_Desired_Close_Speed[8][20];

extern const uint16_t K_Spoiler_FixedVoltage_Open_Enable[20];
extern const uint16_t K_Spoiler_FixedVoltage_Close_Enable[20];
extern const uint16_t K_Spoiler_FixedVoltage_Open_Duty[20];
extern const uint16_t K_Spoiler_FixedVoltage_Close_Duty[20];
extern const uint16_t K_Spoiler_FixedVoltage_Open_Timeout[20];
extern const uint16_t K_Spoiler_FixedVoltage_Close_Timeout[20];

extern const uint16_t K_Spoiler_PID_PWM_Max_PowerOpening[20];
extern const uint16_t K_Spoiler_PID_PWM_Max_PowerClosing[20];

extern const uint16_t K_Spoiler_Opening_IncreaseDuty_Time;
extern const uint16_t K_Spoiler_Opening_IncreasePerTime_Duty;
extern const uint16_t K_Spoiler_Closing_IncreaseDuty_Time;
extern const uint16_t K_Spoiler_Closing_IncreasePerTime_Duty;
extern const uint16_t K_Spoiler_Opening_Start_Duty[10];
extern const uint16_t K_Spoiler_Closing_Start_Duty[10];
extern const uint16_t K_Spoiler_SoftStop_Opening_Step_Duty;
extern const uint16_t K_Spoiler_SoftStop_Opening_Step_Time;
extern const uint16_t K_Spoiler_SoftStop_Opening_End_Duty;
extern const uint16_t K_Spoiler_SoftStop_Closing_Step_Duty;
extern const uint16_t K_Spoiler_SoftStop_Closing_Step_Time;
extern const uint16_t K_Spoiler_SoftStop_Closing_End_Duty;
extern const uint16_t K_SpoilerHallObstacle_SoftStop_Time;

extern const uint16_t K_Spoiler_SoftStart_Opening_HallCount_LowLimit; 
extern const uint16_t K_Spoiler_SoftStart_Closing_HallCount_LowLimit;
extern const uint16_t K_Spoiler_SoftStart_Opening_HallCount_HighLimit; 
extern const uint16_t K_Spoiler_SoftStart_Closing_HallCount_HighLimit;

extern const uint16_t K_SpoilerPowerOpening_Speedup_FullOpen_Time;
extern const uint16_t K_SpoilerPowerClosing_Speedup_FullClose_Time;
extern const uint16_t K_SpoilerPowerOpening_Speedup_Time;
extern const uint16_t K_SpoilerPowerClosing_Speedup_Time;
extern const uint16_t K_SpoilerPowerOpening_HardStart_Time[10];
extern const uint16_t K_SpoilerPowerClosing_HardStart_Time[10];

extern const uint16_t K_Spoiler_HardStart_Enable;
extern const uint16_t K_Spoiler_Speedup_OpenInLowZone_HallCount;
extern const uint16_t K_Spoiler_Speedup_OpenInMiddleZone_HallCount;
extern const uint16_t K_Spoiler_Speedup_OpenInHighZone_HallCount;

extern const uint16_t K_Spoiler_Speedup_CloseInLowZone_HallCount;
extern const uint16_t K_Spoiler_Speedup_CloseInMiddleZone_HallCount;
extern const uint16_t K_Spoiler_Speedup_CloseInHighZone_HallCount;

extern const uint16_t K_Spoiler_SpeedupInLowZone_HallCount;   
extern const uint16_t K_Spoiler_SpeedupInHighZone_HallCount; 

extern const uint16_t K_Spoiler_SpeedupInLowZone_Open_Duty[8][8];
extern const uint16_t K_Spoiler_SpeedupInLowZone_Close_Duty[8][8];
extern const uint16_t K_Spoiler_SpeedupInMiddleZone_Open_Duty[8][8];
extern const uint16_t K_Spoiler_SpeedupInMiddleZone_Close_Duty[8][8];
extern const uint16_t K_Spoiler_SpeedupInHighZone_Open_Duty[8][8];
extern const uint16_t K_Spoiler_SpeedupInHighZone_Close_Duty[8][8];

extern const uint16_t K_Spoiler_ShortDistanceInOpening_HallCount[10];
extern const uint16_t K_Spoiler_ShortDistanceInClosing_HallCount[10];

extern const uint16_t K_Spoiler_ObstacleTimes_Continue_Count;
extern const uint16_t K_Spoiler_ObstacleTimes_Total_Count;

extern const uint16_t K_SpoilerLearned_Position_Default;
extern const uint16_t K_SpoilerFullOpenSwitch_Position_Default;
extern const uint16_t K_SpoilerFullCloseSwitch_Position_Default;
extern const uint16_t K_SpoilerMiddleSwitch_Position_Default;
extern const uint16_t K_SpoilerMaxTravel_Position_Default;
extern const uint16_t K_SpoilerMiddlePosition_TravelHallCount_Default;

extern const uint16_t K_SpoilerFullOpenSwitch_Position_Open_Delta;
extern const uint16_t K_SpoilerFullOpenSwitch_Position_Close_Delta;
extern const uint16_t K_Spoiler_LearnNearClosePosition_HallCount;
extern const uint16_t K_Spoiler_LearnNearClosePosition_Close_Time;
extern const uint16_t K_SpoilerFullOpenSwitch_Position_LearnNearClosePosition_Compensation;
extern const uint16_t K_SpoilerFullOpenSwitch_Position_LearnFarClosePosition_Compensation;
extern const uint16_t K_SpoilerFullCloseSwitch_Position_LearnNearClosePosition_Compensation;
extern const uint16_t K_SpoilerFullCloseSwitch_Position_LearnFarClosePosition_Compensation;
extern const uint16_t K_SpoilerMiddleSwitch_Position_LearnNearClosePosition_Compensation;
extern const uint16_t K_SpoilerMiddleSwitch_Position_LearnFarClosePosition_Compensation;


extern const uint16_t K_SpoilerFullOpenSwitch_HallEffect_Active_LowLimit;
extern const uint16_t K_SpoilerFullOpenSwitch_HallEffect_Active_HighLimit;

extern const uint16_t K_SpoilerFullOpenSwitch_HallEffect_Inactive_LowLimit;
extern const uint16_t K_SpoilerFullOpenSwitch_HallEffect_Inactive_HighLimit;

extern const uint16_t K_SpoilerFullCloseSwitch_HallEffect_Active_LowLimit;
extern const uint16_t K_SpoilerFullCloseSwitch_HallEffect_Active_HighLimit;

extern const uint16_t K_SpoilerFullCloseSwitch_HallEffect_Inactive_LowLimit;
extern const uint16_t K_SpoilerFullCloseSwitch_HallEffect_Inactive_HighLimit;
#endif


/*********************************************************************************************
**    window_control
*********************************************************************************************/
#ifdef _CONFIG_PowerWindow

#define K_Flag_WindowRequest_TableSize 10
#define K_WindowRequestSource_TableSize 10
#define K_Flag_WindowObstacleDetected_TableSize 10

extern const uint8_t K_Window_Prop_Open[20];
extern const uint8_t K_Window_PropScale_Open[20];
extern const uint8_t K_Window_Int_Open[20];
extern const uint8_t K_Window_IntScale_Open[20];
extern const uint8_t K_Window_Diff_Open[20];
extern const uint8_t K_Window_DiffScale_Open[20];

extern const uint8_t K_Window_Prop_Close[20];
extern const uint8_t K_Window_PropScale_Close[20];
extern const uint8_t K_Window_Int_Close[20];
extern const uint8_t K_Window_IntScale_Close[20];
extern const uint8_t K_Window_Diff_Close[20];
extern const uint8_t K_Window_DiffScale_Close[20];

extern const uint8_t K_Window_Prop_PushPID;
extern const uint8_t K_Window_PropScale_PushPID;
extern const uint8_t K_Window_Int_PushPID;
extern const uint8_t K_Window_IntScale_PushPID;
extern const uint8_t K_Window_Diff_PushPID;
extern const uint8_t K_Window_DiffScale_PushPID;

extern const uint16_t K_Window_PushPID_HallCount;
extern const uint16_t K_Window_PushPIDSpeed_Tigger_Delta;
extern const uint16_t K_Window_PushPIDSpeed_Quit_Delta;
extern const uint16_t K_Window_PushPID_Timeout;
extern const uint16_t K_Window_PushPID_ObstacleAdder_Timeout;

extern const uint16_t K_WindowPowerOn_Time;
extern const uint16_t K_WindowWakeUp_Time;
extern const uint16_t K_WindowReset_Time;

extern const uint16_t K_WindowPowerOpening_SoftStall_Time;
extern const uint16_t K_WindowPowerClosing_SoftStall_Time;

extern const uint16_t K_WindowPowerOpening_ObstacleDetected_Reverse_Enable;
extern const uint16_t K_WindowPowerClosing_ObstacleDetected_Reverse_Enable;

extern const uint16_t K_WindowSwitch_ShortPress_LowLimit_Time;
extern const uint16_t K_WindowSwitch_ShortPress_HighLimit_Time;
extern const uint16_t K_WindowSwitch_LongPress_LowLimit_Time;
extern const uint16_t K_WindowSwitch_LongPress_HighLimit_Time;

extern const uint16_t K_WindowCommandInterval_Time;
extern const uint16_t K_CentralLockSwitch_WindowCommandInterval_Enable;
extern const uint16_t K_CentralLockSwitch_WindowCommandDelay_Time;
extern const uint16_t K_CentralLockSwitch_Wakeup_WindowCommandDelay_Time;

extern const uint16_t K_WindowSwitch_WindowCommandInterval_Enable;
extern const uint16_t K_WindowSwitch_WindowCommandDelay_Time;
extern const uint16_t K_WindowSwitch_Wakeup_WindowCommandDelay_Time;

extern const uint16_t K_WindowCommandInhibition_Min_Time;
extern const uint16_t K_WindowSwitch_ShortPress_WindowCommandInhibition_Time;

extern const uint16_t K_WindowPowerOpening_Timeout;
extern const uint16_t K_WindowPowerClosing_Timeout;

extern const uint16_t K_Window_StopFromMaxTravel_HallCount;
extern const uint16_t K_Window_OpenEnd_SoftStop_HallCount_Compensation;
extern const uint16_t K_Window_CloseEnd_SoftStop_HallCount_Compensation;

extern const uint16_t K_Window_VirtualFullOpenSwitch_HallCount;
extern const uint16_t K_Window_FullCloseSwitchVirtual_HallCount;
extern const uint16_t K_Window_MaxPosition_HallCount_Default;

extern const uint16_t K_WindowOpenedFully_Timeout;
extern const uint16_t K_WindowReleased_Timeout;

extern const uint16_t K_ChangeDutyInWindowPowerOpening_1st_Time;
extern const uint16_t K_ChangeDutyInWindowPowerClosing_1st_Time;

extern const uint16_t K_StopBefore_WindowPowerOpening_Time;
extern const uint16_t K_StopBefore_WindowPowerClosing_Time;

extern const uint16_t K_WindowHomePosition_Delay_Time;
extern const uint16_t K_WindowSpreadPosition_Delay_Time;

extern const uint16_t K_WindowPowerOpening_Inrush_Time;
extern const uint16_t K_WindowPowerClosing_Inrush_Time;

extern const uint16_t K_Window_ObstacleIndex;
extern const uint16_t K_Window_HallCountPerObstacleZone_Min;
extern const uint16_t K_Window_HallCountPerObstacleZone_Max;    
extern const uint16_t K_Window_HallCountPerObstacleZone_Default;

extern const uint16_t K_Window_PowerOpening_HallCount_Delta;
extern const uint16_t K_Window_PowerClosing_HallCount_Delta;

extern const uint16_t K_Window_EnhancedCurrent_DecreasePerTimer;
extern const uint16_t K_Window_EnhancedCurrent_Decrease_Time;
extern const uint16_t K_Window_EnhancedCurrent_IncreasePerTimer;
extern const uint16_t K_Window_EnhancedCurrent_Increase_Time;
extern const uint16_t K_Window_EnhancedCurrent_Threshold_Time;

extern const uint16_t K_Window_SoftStall_Detect_Time;
extern const uint16_t K_Window_FixedCurrent_Detect_Time;

extern const uint16_t K_Window_EnhancedCurrent_Detect_PushPID_Open_Adder[10];
extern const uint16_t K_Window_EnhancedCurrent_Detect_PushPID_Close_Adder[10];

extern const uint16_t K_Window_EnhancedCurrent_Detect_Open[8][10];
extern const uint16_t K_Window_EnhancedCurrent_Detect_Open_Temp[8][10];
extern const uint16_t K_Window_EnhancedCurrent_Detect_Close[8][10];
extern const uint16_t K_Window_EnhancedCurrent_Detect_Close_Temp[8][10];

extern const uint16_t K_Window_PositionObstacle_Detect_Delta;
extern const uint16_t K_Window_PositionObstacle_Detect_Open_Timer[10];
extern const uint16_t K_Window_PositionObstacle_Detect_Close_Timer[10];

extern const uint16_t K_Window_HallPluse1Width_Time;
extern const uint16_t K_Window_HallPluse2Width_Time;

extern const uint16_t K_Window_SoftStallCurrent_TopLimit[8][8];
extern const uint16_t K_Window_FixedCurrentStall_TopLimit[8][8];
extern const uint16_t K_Window_WindowPowerOpening_Duty[8][8];
extern const uint16_t K_Window_WindowPowerOpening_Duty_2nd[8][8];
extern const uint16_t K_Window_WindowPowerClosing_Duty[8][8];
extern const uint16_t K_Window_WindowPowerClosing_Duty_2nd[8][8];

extern const uint16_t K_Window_SpeedZoneIndex;
extern const uint16_t K_Window_HallCountPerSpeedZone_Min;
extern const uint16_t K_Window_HallCountPerSpeedZone_Max;
extern const uint16_t K_Window_HallCountPerSpeedZone_Default;

extern const uint16_t K_Window_Desired_Open_Speed[8][20];
extern const uint16_t K_Window_Desired_Close_Speed[8][20];

extern const uint16_t K_Window_FixedVoltage_Open_Enable[20];
extern const uint16_t K_Window_FixedVoltage_Close_Enable[20];
extern const uint16_t K_Window_FixedVoltage_Open_Duty[20];
extern const uint16_t K_Window_FixedVoltage_Close_Duty[20];
extern const uint16_t K_Window_FixedVoltage_Open_Timeout[20];
extern const uint16_t K_Window_FixedVoltage_Close_Timeout[20];

extern const uint16_t K_Window_PID_PWM_Max_PowerOpening[20];
extern const uint16_t K_Window_PID_PWM_Max_PowerClosing[20];

extern const uint16_t K_Window_Opening_IncreaseDuty_Time;
extern const uint16_t K_Window_Opening_IncreasePerTime_Duty;
extern const uint16_t K_Window_Closing_IncreaseDuty_Time;
extern const uint16_t K_Window_Closing_IncreasePerTime_Duty;
extern const uint16_t K_Window_Opening_Start_Duty[10];
extern const uint16_t K_Window_Closing_Start_Duty[10];
extern const uint16_t K_Window_SoftStop_Opening_Step_Duty;
extern const uint16_t K_Window_SoftStop_Opening_Step_Time;
extern const uint16_t K_Window_SoftStop_Opening_End_Duty;
extern const uint16_t K_Window_SoftStop_Closing_Step_Duty;
extern const uint16_t K_Window_SoftStop_Closing_Step_Time;
extern const uint16_t K_Window_SoftStop_Closing_End_Duty;
extern const uint16_t K_WindowHallObstacle_SoftStop_Time;

extern const uint16_t K_Window_SoftStart_Opening_HallCount_LowLimit; 
extern const uint16_t K_Window_SoftStart_Closing_HallCount_LowLimit;
extern const uint16_t K_Window_SoftStart_Opening_HallCount_HighLimit; 
extern const uint16_t K_Window_SoftStart_Closing_HallCount_HighLimit;

extern const uint16_t K_WindowPowerOpening_Speedup_Time;
extern const uint16_t K_WindowPowerClosing_Speedup_Time;

extern const uint16_t K_WindowPowerOpening_HardStart_Time[10];
extern const uint16_t K_WindowPowerClosing_HardStart_Time[10];

extern const uint16_t K_Window_HardStart_Enable;
extern const uint16_t K_Window_Speedup_OpenInLowZone_HallCount;
extern const uint16_t K_Window_Speedup_OpenInMiddleZone_HallCount;
extern const uint16_t K_Window_Speedup_OpenInHighZone_HallCount;

extern const uint16_t K_Window_Speedup_CloseInLowZone_HallCount;
extern const uint16_t K_Window_Speedup_CloseInMiddleZone_HallCount;
extern const uint16_t K_Window_Speedup_CloseInHighZone_HallCount;

extern const uint16_t K_Window_SpeedupInLowZone_HallCount;   
extern const uint16_t K_Window_SpeedupInHighZone_HallCount; 

extern const uint16_t K_Window_SpeedupInLowZone_Open_Duty[8][8];
extern const uint16_t K_Window_SpeedupInLowZone_Close_Duty[8][8];
extern const uint16_t K_Window_SpeedupInMiddleZone_Open_Duty[8][8];
extern const uint16_t K_Window_SpeedupInMiddleZone_Close_Duty[8][8];
extern const uint16_t K_Window_SpeedupInHighZone_Open_Duty[8][8];
extern const uint16_t K_Window_SpeedupInHighZone_Close_Duty[8][8];

extern const uint16_t K_Window_ShortDistanceInOpening_HallCount[10];
extern const uint16_t K_Window_ShortDistanceInClosing_HallCount[10];

extern const uint16_t K_Window_ContinueObstacle_Reversal_Count;
extern const uint16_t K_Window_TotalObstacle_Reversal_Count;

extern const uint16_t K_WindowLearned_Position_Default;
#endif



#endif /* __SYSTEM_CALIBRATIONS_H */
/*********************************************************************************************
** End of file
*********************************************************************************************/

