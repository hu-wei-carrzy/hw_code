#ifndef __API_INTERFACE_H
#define __API_INTERFACE_H

/*********************************************************************************************
** Global Structures' Definition
*********************************************************************************************/
//typedef signed char int8_t;
//typedef unsigned char uint8_t;
//typedef signed short int16_t;
//typedef unsigned short uint16_t;
//typedef signed int int32_t;
//typedef unsigned int uint32_t;
/*********************************************************************************************
** MACROS
**********************************************************************************************/

/* _CONFIG_Gen1_Board*/
#ifdef _CONFIG_Gen1_Board
#define Set_ODH_4_CTN_Duty(duty)   do{ TAUB0.CDR1 = duty; }while(0)
#define Set_ODH_3_CTN_Duty(duty)   do{ TAUB0.CDR3 = duty; }while(0)

#define Set_CINCH_PWM_Duty(duty)   do{ TAUB0.CDR13 = duty; }while(0)

#define Set_ODH_5_CTN_Duty(duty)   do{ TAUD0.CDR10 = duty; }while(0)
#define Set_ODH_6_CTN_Duty(duty)   do{ TAUD0.CDR15 = duty; }while(0)

#define Set_ODL_0_CTN_Duty(duty)   do{ TAUD0.CDR7 = duty; }while(0)

#define Set_ODH_1_CTN_Duty(duty)   do{ PWGA41.CSDR = (PWGA41.CRDR - duty); \
                                  PWGA41.RDT = 0x01; \
                                }while(0)
					  
#define Set_ODH_2_CTN_Duty(duty)   do{ PWGA40.CSDR =(PWGA40.CRDR - duty); \
                                  PWGA40.RDT = 0x01; \
                                }while(0)
#endif

/* _CONFIG_Gen2_Board*/
#ifdef _CONFIG_Gen2_Board
#define Set_U3_IN1_PH_U1_85_Duty(duty)   do{ TAUB0.CDR1 = duty; }while(0)
#define Set_U3_IN2_EN_U1_86_Duty(duty)   do{ TAUB0.CDR3 = duty; }while(0)

#define Set_U4_IN1_PH_U1_81_Duty(duty)   do{ TAUD0.CDR15 = duty; }while(0)
#define Set_U4_IN2_EN_U1_82_Duty(duty)   do{ TAUD0.CDR10 = duty; }while(0)

#define Set_U5_IN1_PH_U1_89_Duty(duty)   do{ TAUB0.CDR13 = duty; }while(0)
#define Set_U5_IN2_EN_U1_1_Duty(duty)   do{ TAUD0.CDR7 = duty; }while(0)


#define Set_U6_IN0_U1_50_Duty(duty)   do{ PWGA41.CSDR = (PWGA41.CRDR - duty); \
                                  PWGA41.RDT = 0x01; \
                                }while(0)
					  
#define Set_U6_IN1_U1_49_Duty(duty)   do{ PWGA40.CSDR =(PWGA40.CRDR - duty); \
                                  PWGA40.RDT = 0x01; \
                                }while(0)
				
#define Set_Speaker_Duty(duty)     do{ TAUB0.CDR6 = duty; }while(0)
#define Set_Flasher_Duty(duty)     do{ TAUB0.CDR6 = duty; }while(0)
#endif

/* _CONFIG_Gen3_Board*/
#ifdef _CONFIG_Gen3_Board
#define Set_M1_IN1_P10_11_Duty(duty)   do{ TAUB0.CDR1 = duty; }while(0)
#define Set_M1_IN2_P10_12_Duty(duty)   do{ TAUB0.CDR3 = duty; }while(0)

#define Set_M2_IN1_P10_7_Duty(duty)   do{ TAUD0.CDR15 = duty; }while(0)
#define Set_M2_IN2_P10_8_Duty(duty)   do{ TAUD0.CDR10 = duty; }while(0)

#define Set_M3_IN1_P11_1_Duty(duty)   do{ TAUB0.CDR13 = duty; }while(0)
#define Set_M3_IN2_P10_3_Duty(duty)   do{ TAUD0.CDR7 = duty; }while(0)

#define Set_M4_IN1_P10_2_Duty(duty)   do{ TAUD0.CDR5 = duty; }while(0)
#define Set_M4_IN2_P10_1_Duty(duty)   do{ TAUD0.CDR3 = duty; }while(0)

#define Set_7040_IN0_P8_9_Duty(duty)   do{ PWGA41.CSDR = (PWGA41.CRDR - duty); \
                                           PWGA41.RDT = 0x01; \
                                         }while(0)
					  
#define Set_7040_IN1_P8_8_Duty(duty)   do{ PWGA40.CSDR =(PWGA40.CRDR - duty); \
                                           PWGA40.RDT = 0x01; \
                                         }while(0)
				
#define Set_Speaker_Duty(duty)     do{ TAUB0.CDR6 = duty; }while(0)
#define Set_Flasher_Duty(duty)     do{ TAUB0.CDR6 = duty; }while(0)
#endif		

/* _CONFIG_Gen4_Board*/
#ifdef _CONFIG_Gen4_Board
#define Set_M1_IN1_P10_11_Duty(duty)   do{ TAUB0.CDR1 = duty; }while(0)
#define Set_M1_IN2_P10_12_Duty(duty)   do{ TAUB0.CDR3 = duty; }while(0)

#define Set_M2_IN1_P10_7_Duty(duty)   do{ TAUD0.CDR15 = duty; }while(0)
#define Set_M2_IN2_P10_8_Duty(duty)   do{ TAUD0.CDR10 = duty; }while(0)

#define Set_M3_IN1_P11_1_Duty(duty)   do{ TAUB0.CDR13 = duty; }while(0)
#define Set_M3_IN2_P10_3_Duty(duty)   do{ TAUD0.CDR7 = duty; }while(0)

#define Set_M4_IN1_P10_2_Duty(duty)   do{ TAUD0.CDR5 = duty; }while(0)
#define Set_M4_IN2_P10_1_Duty(duty)   do{ TAUD0.CDR3 = duty; }while(0)

#define Set_7040_IN0_P10_9_Duty(duty)   do{ PWGA6.CSDR = (PWGA6.CRDR - duty); \
                                           PWGA6.RDT = 0x01; \
                                         }while(0)
					  
#define Set_7040_IN1_P0_11_Duty(duty)   do{ TAUB0.CDR8 = duty; }while(0)

				
#define Set_Speaker_Duty(duty)     do{ TAUB0.CDR6 = duty; }while(0)
#define Set_Flasher_Duty(duty)     do{ TAUB0.CDR6 = duty; }while(0)
#endif
				
typedef enum
{
   Direction_No = 0,     /* 0 */
   Direction_Open,       /* 1 */
   Direction_Close,      /* 2 */
   Direction_Cinch,      /* 3 */
   Direction_Neutral,    /* 4 */
   Direction_Release,    /* 5 */
   Direction_Findhome,   /* 6 */
   Direction_ClutchOn,   /* 7 */
   Direction_Unlock      /* 8 */
   
}tD_Direction_Request;

typedef enum
{
   High_Side = 0,     /* 0 */
   Low_Side           /* 1 */
   
}tD_H_Bridge_Side;

typedef enum
{
    NMSource_NoSource,    /*00*/
    NMSource_PowerUp,     /*01*/	
    NMSource_Igntion,     /*02*/
    NMSource_Reset,       /*03*/	      				
    NMSource_NMFrame,     /*04*/
    NMSource_AppFrame,    /*05*/
    NMSource_UDSFrame,    /*06*/
    NMSource_Button,      /*07*/
    NMSource_Latch,       /*08*/
    NMSource_Spindle,     /*09*/
    NMSource_ECU,         /*10*/
    NMSource_GateOpen    /*11*/
    
}tD_NM_Source;

/*********************************************************************************************
** Global Variables Declarations
**********************************************************************************************/

extern uint8_t Motor1_SoftStop_Enable;
extern uint8_t Motor2_SoftStop_Enable;
extern uint8_t Motor1_SoftStop_Finish_Status;
extern uint8_t Motor2_SoftStop_Finish_Status;
extern uint8_t SoftStop_Working_Status;
extern uint8_t SoftStart_Working_Status;
extern uint8_t SoftStop_Finish_Status;

extern uint8_t Motor1_BrakeToGround_Status;
extern uint8_t Motor2_BrakeToGround_Status;
extern uint8_t CinchMotor_BrakeToGround_Status;

extern uint8_t Motor1_BrakeToBattery_Status;
extern uint8_t Motor2_BrakeToBattery_Status;
extern uint8_t CinchMotor_BrakeToBattery_Status;

extern uint8_t BTS_IN0_CurrentSensor_Status;
extern uint8_t BTS_IN1_CurrentSensor_Status;

extern uint8_t Motor1_Direction_Request;
extern uint8_t Motor2_Direction_Request; 
extern uint8_t CinchMotor_Direction_Request;
extern uint8_t Motor4_Direction_Request; 
extern uint8_t ReleaseMotor_Direction_Request;

extern uint8_t CinchMotor1_Direction_Request;
extern uint8_t CinchMotor2_Direction_Request;
extern uint8_t ReleaseMotor1_Direction_Request;
extern uint8_t ReleaseMotor2_Direction_Request;

extern uint8_t Motor1_Working_Status;
extern uint8_t Motor2_Working_Status;
extern uint8_t Motor4_Working_Status;
extern uint8_t CinchMotor_Working_Status;
extern uint8_t ReleaseMotor_Working_Status;
extern uint8_t Clutch_Working_Status;

extern uint8_t Motor1_Working_LastStatus;
extern uint8_t Motor2_Working_LastStatus;
extern uint8_t Motor4_Working_LastStatus;
extern uint8_t CinchMotor_Working_LastStatus;
extern uint8_t ReleaseMotor_Working_LastStatus;

extern uint8_t CinchMotor_Direction_Status;
extern uint8_t ReleaseMotor_Direction_Status;

extern uint8_t Buzzer_Working_Status;
extern uint8_t Speaker_Working_Status;

#ifdef _CONFIG_Flasher
extern uint8_t Flasher_Working_Status;
#endif

extern uint16_t HallA1_Low_Pluse_Timer;
extern uint16_t HallA2_Low_Pluse_Timer;
extern uint16_t HallB1_Low_Pluse_Timer;
extern uint16_t HallB2_Low_Pluse_Timer;

extern uint16_t HallA1_High_Pluse_Timer;
extern uint16_t HallA2_High_Pluse_Timer;
extern uint16_t HallB1_High_Pluse_Timer;
extern uint16_t HallB2_High_Pluse_Timer;

extern uint16_t HallA1_HallCounter;
extern uint16_t HallA2_HallCounter;
extern uint16_t HallB1_HallCounter;
extern uint16_t HallB2_HallCounter;

#ifdef _CONFIG_Motor4
extern uint16_t Motor4_HallCounter;
extern uint16_t Motor4_HallPluse1Width_Timer;
extern uint16_t Motor4_HallPluse2Width_Timer;
extern uint8_t Motor4_Working_Status;
extern tD_Direction_Request Motor4_Direction_Status;

extern uint16_t Motor4_Position;
extern int16_t Motor4_Location;
#endif

#ifdef _CONFIG_HallC
extern uint16_t HallC_Accumulator;
extern uint16_t HallC1_DynamicDiag_HallCounter;
extern uint16_t HallC2_DynamicDiag_HallCounter;
extern uint16_t HallC1_HallCounter;
extern uint16_t HallC2_HallCounter;
extern uint8_t HallC1_Status;
extern uint8_t HallC2_Status;

extern uint16_t HallC1_Low_Pluse_Timer;
extern uint16_t HallC2_Low_Pluse_Timer;
extern uint16_t HallC1_High_Pluse_Timer;
extern uint16_t HallC2_High_Pluse_Timer;

extern uint8_t HallC1_Diagnostic_Working_Status;
extern uint8_t HallC2_Diagnostic_Working_Status;

extern uint8_t HallPower3_Status;
#endif

#ifdef _CONFIG_HallD
extern uint16_t HallD_Accumulator;
extern uint16_t HallD1_DynamicDiag_HallCounter;
extern uint16_t HallD2_DynamicDiag_HallCounter;
extern uint16_t HallD1_HallCounter;
extern uint16_t HallD2_HallCounter;
extern uint8_t HallD1_Status;
extern uint8_t HallD2_Status;

extern uint16_t HallD1_Low_Pluse_Timer;
extern uint16_t HallD2_Low_Pluse_Timer;
extern uint16_t HallD1_High_Pluse_Timer;
extern uint16_t HallD2_High_Pluse_Timer;

extern uint8_t HallD1_Diagnostic_Working_Status;
extern uint8_t HallD2_Diagnostic_Working_Status;
#endif

#ifdef _CONFIG_DIAG_Hall_StaticDiag
extern uint8_t HallA1_Diagnostic_Working_Status;
extern uint8_t HallA2_Diagnostic_Working_Status;
extern uint8_t HallB1_Diagnostic_Working_Status;
extern uint8_t HallB2_Diagnostic_Working_Status;
#endif


extern tD_Direction_Request Motor1_Direction_Status;
extern tD_Direction_Request Motor2_Direction_Status;

extern uint8_t HallPower_Status;

//#ifdef _CONFIG_Gen3_Board
extern uint8_t HallPower1_Status;
extern uint8_t HallPower2_Status;
extern uint8_t LatchSwitchPower_Status;
//#endif


extern uint8_t VBATT1_SW_Feed_Status;
extern uint8_t VCC2_5V_Feed_Status;
extern uint8_t VCC3_5V_Feed_Status;
extern uint8_t SBC_HS3_OUT_Output_Status;
extern uint8_t HS4_Output_Status;

/* Test API, Need to remove in production */

extern uint8_t Flag_ShutFaceSwitch_RiseEdge;
extern uint8_t Flag_ShutFaceSwitch_FallEdge;
extern uint8_t Flag_ShutFaceSwitch_ShortPress;
extern uint8_t Flag_ShutFaceSwitch_LongPress;

extern uint16_t Flag_Motor1_Duty_Request;
     
extern uint16_t Time_Test1;
extern uint16_t Time_Test2;
extern uint16_t Time_Test_Delta;
extern uint8_t SBC_Reset_Reason;


/*********************************************************************************************
** Function Prototypes with Global Scope
*********************************************************************************************/

extern void API_Motor2_SoftStart_Trigger(void);
extern void API_Motor2_SoftStop_Trigger(void);


extern void API_ECU_Soft_Reset(void);
extern void API_CinchMotor_BrakeToGround(void);
extern void API_CinchMotor_BrakeToBattery(void);

extern void API_Motor1_BrakeToGround(void);
extern void API_Motor1_BrakeToBattery(void);

extern void API_Motor2_BrakeToGround(void);
extern void API_Motor2_BrakeToBattery(void);

extern void API_TurnOn_HallPower(void);
extern void API_TurnOff_HallPower(void);

extern void API_TurnOn_VBATT1_SW(void);
extern void API_TurnOff_VBATT1_SW(void);

extern void API_TurnOn_VCC2_5V(void);
extern void API_TurnOff_VCC2_5V(void);


extern void API_TurnOn_Batt_AD_EN(void);
extern void API_TurnOff_Batt_AD_EN(void);


extern void API_HallA1_Interrupt(void);
extern void API_HallA2_Interrupt(void);
extern void API_HallB1_Interrupt(void);
extern void API_HallB2_Interrupt(void);

extern void API_TurnOff_Motor1(void);
extern void API_TurnOff_Motor2(void);
extern void API_TurnOff_Motor4(void);

extern void API_TurnOn_Motor1_Open(void);
extern void API_TurnOn_Motor2_Open(void);
extern void API_TurnOn_Motor4_Open(void);

extern void API_TurnOn_Motor1_Close(void);
extern void API_TurnOn_Motor2_Close(void);
extern void API_TurnOn_Motor4_Close(void);

extern void API_TurnOff_CinchMotor(void);   /* Cinch motor*/
extern void API_TurnOff_ReleaseMotor(void); /* Release motor*/
extern void API_TurnOff_Clutch(void);

extern void API_TurnOn_CinchMotor_Cinch(void);
extern void API_TurnOn_CinchMotor_Neutral(void);
extern void API_TurnOn_ReleaseMotor(void);
extern void API_TurnOn_Clutch(void);

extern void API_TurnOn_Buzzer(void);
extern void API_TurnOff_Buzzer(void);

extern void API_TurnOn_BTS_IN0_CurrentSensor(void);
extern void API_TurnOn_BTS_IN1_CurrentSensor(void);

extern void API_TurnOn_LowSideOutput(void);
extern void API_TurnOff_LowSideOutput(void);

extern void API_Motor1_PWMDuty_Update(uint16_t duty,uint16_t direction);
extern void API_Motor2_PWMDuty_Update(uint16_t duty,uint16_t direction);
extern void API_Motor4_PWMDuty_Update(uint16_t duty,uint16_t direction);
extern void API_CinchMotor_PWMDuty_Update(uint16_t duty,uint16_t direction);
extern void API_ReleaseMotor_PWMDuty_Update(uint16_t duty);
extern void API_Buzzer_PWMDuty_Update(uint16_t duty);
extern void API_Clutch_PWMDuty_Update(uint16_t duty);

extern void API_Set_Motor1_PWMPeriod(uint16_t period);
extern void API_Set_Motor2_PWMPeriod(uint16_t period);
extern void API_Set_CinchMotor_PWMPeriod(uint16_t period);
extern void API_Set_Motor4_PWMPeriod(uint16_t period);


/*High Side Output Control*/
extern void API_TurnOn_HS_Output_J2_1(void);
extern void API_TurnOn_HS_Output_J2_2(void);
extern void API_TurnOn_HS_Output_J3_1(void);
extern void API_TurnOn_HS_Output_J3_2(void);
extern void API_TurnOn_HS_Output_J3_3(void);
extern void API_TurnOn_HS_Output_J3_4(void);

extern void API_TurnOff_HS_Output_J2_1(void);
extern void API_TurnOff_HS_Output_J2_2(void);
extern void API_TurnOff_HS_Output_J3_1(void);
extern void API_TurnOff_HS_Output_J3_2(void);
extern void API_TurnOff_HS_Output_J3_3(void);
extern void API_TurnOff_HS_Output_J3_4(void);


extern void API_Task_Scheduler_Test(void);
extern void API_ManualCurrentCalibrate(void);

#ifdef  _CONFIG_IncreaseStepDuty
extern uint16_t API_IncreaseStepDuty_Control(uint16_t Duty_Request,uint16_t OnePercentPWM_Value,uint16_t IncreaseStep_Duty,uint16_t IncreaseStep_Time);
#endif
#ifdef _CONFIG_DecreaseStepDuty
extern uint16_t API_DecreaseStepDuty_Control(uint16_t Duty_Request,uint16_t Duty_Target,uint16_t OnePercentPWM_Value,uint16_t DecreaseStep_Duty);
#endif
extern uint16_t API_ReferTo12Voltage_Duty(uint16_t vol_12v_duty);
extern uint16_t API_ReferTo12Voltage_Current(uint16_t vol_12v_current);
extern uint16_t API_ReferTo12Voltage_Data(uint16_t vol_12v_data);
extern int16_t API_ReferTo20Degree_Adder(int16_t temp_80_degree_data, int16_t temp_n40_degree_data);

#endif /* __API_INTERFACE_H*/
/*********************************************************************************************
** End of file
*********************************************************************************************/
