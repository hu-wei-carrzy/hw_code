/*********************************************************************************************
** Header Files
*********************************************************************************************/

#include "typedefs.h"
#include "os_timer.h"
//#include "r_cg_adc.h"
//#include "latch_control.h"
#include "system_control.h"
#include "system_calibration.h"
//#include "project_calibration.h"
//#include "com_calibration.h"
//#include "speed_control.h"
//#include "obstacle_detect.h"
//#include "fault_process.h"
#include "message_process.h"
//#include "request_process.h"
#include "api_interface.h"
//#include "pinout_manage.h"
//#include "spindle_control.h"
//#include "command_process.h"
//#include "dtc_report.h"
//#include "telltales_report.h"
//#include "sleep_manage.h"
//#include "buzzer_control.h"
#include "network_manage.h"
//#include "config_process.h"
//#include "did_process.h"
//#include "factory_data.h"
//#include "follow_control.h"
//#include "manual_control.h"
//#include "motorhold_control.h"
//#include "incline_detect.h"
//#include "sonic_radar.h"
//#include "mmw_radar.h"
//#include "adas_radar.h"
//#include "gate_calibration.h"
//#include "gate_calibrationfile.h"
//#include "door_calibration.h"
//#include "door_calibrationfile.h"
#include "S32K144Types.h"

/*********************************************************************************************
** Global Variables Definitions
*********************************************************************************************/

/*Transmit message*/ 

#ifdef _CONFIG_MessageTx_Information
tD_MessageTx_Information Mem_MessageTx_Information;
uint8_t MessageTx_MessageCounter;
uint8_t MessageTx_Reserved;
#endif


#ifdef _CHERY_COM
#ifdef _CHERY_COM_PD
uint8_t MessageTx_LearnedStatus;
uint8_t MessageTx_CurrentOpenPosition;
uint8_t MessageTx_SetOpenAngleFb;
uint8_t MessageTx_SystemMotionStatus;
uint8_t MessageTx_LatchMotionStatus;
uint8_t MessageTx_ResetSwitch;
uint8_t MessageTx_DoorCloseStatus;
uint8_t MessageTx_MotorFaultStatus;
uint8_t MessageTx_AntipinchEvent;
uint8_t MessageTx_PSDModeControlFb;
uint8_t MessageTx_Reminder;
uint8_t MessageTx_RadarDetectRequirement;
uint8_t MessageTx_ADASDetectRequirement;
uint8_t MessageTx_ClutchStatus;
uint8_t MessageTx_Inhibition;
uint8_t MessageTx_ReleaseLatch;
uint8_t MessageTx_Warning;
	
uint8_t MessageTx_DCM_2_DRMDetectRequirement;
uint8_t MessageTx_DCM_2_RCMDetectRequirement;
uint8_t MessageTx_DCM_2_SystemMotionStatus;
uint8_t MessageTx_DCM_2_CurrentOpenPosition;
uint8_t MessageTx_DCM_2_SetOpenAngleFb;
uint8_t MessageTx_DCM_2_DCMAngularSpeed;
uint8_t MessageTx_DoorCurrentoperation;
uint8_t MessageTx_DoorFunctionInhibit;

uint8_t MessageTx_DCM_3_BLEOpenDriverDoorFB;
uint8_t MessageTx_DCM_3_PedalCloseDriverDoorFB;
uint8_t MessageTx_DCM_3_DoorRemoteKeyControlFB;
uint8_t MessageTx_DCM_3_DoorVoiceControlFB;
uint8_t MessageTx_DCM_3_ParkDoorControlNotice;
uint8_t MessageTx_DoorMotionDirection;

uint8_t MessageTx_DCM_TotalFaultNum;	
uint8_t MessageTx_DCM_FrameIndex;
uint8_t MessageTx_DCM_SupplierNum;	
uint16_t MessageTx_DCM_FaultNum1;
uint16_t MessageTx_DCM_FaultNum2;
uint16_t MessageTx_DCM_FaultNum3;
uint16_t MessageTx_DCM_FaultNum4;

uint8_t MessageTx_DCM_1_RollgCntr1;
uint8_t MessageTx_DCM_2_RollgCntr1;
uint8_t MessageTx_DCM_3_RollgCntr1;

#ifdef _CONFIG_LatchSignal_Transmit
uint8_t MessageTx_LatchSignal;
#endif
#endif
#endif

tD_PowerMode BusPowerMode;
tD_PowerMode VehiclePowerMode;
tD_AntiTheft VehicleAntiTheft;
tD_GearLever VehicleGearLever;

#ifdef _CONFIG_VehicleMode
tD_VehicleMode VehicleMode;
#endif
#ifdef _CONFIG_LatchSignal
tD_LatchSignal LatchSignal;
#endif

uint8_t VehiclePowerMode_ON_Status;
uint8_t VehiclePowerMode_ON_LastStatus;
uint8_t VehiclePowerMode_ON_FallEdge_Active;
uint8_t VehiclePowerMode_ON_RiseEdge_Active;

uint8_t MessageTx_GateOpenAngle_Valid;

uint8_t MessageTx_ChimeRemind;
uint8_t MessageTx_FlashRemind;
uint8_t MessageTx_DisplayRemind;

uint8_t MessageTx_PawlSwitch;
uint8_t MessageTx_SecondarySwitch;
uint8_t MessageTx_PositonSwitch;
uint8_t MessageTx_PrimarySwitch;

uint8_t MessageTx_SnowLoadSignal;

uint16_t MessageTx_GateOpenAngle;

uint16_t MessageTx_GaragePosition;
uint8_t MessageTx_SystemLearnedStatus;
uint8_t MessageTx_SystemLearnFailure;
uint8_t MessageTx_GarageLearnedStatus;
uint8_t MessageTx_GarageLearnAction;
uint8_t MessageTx_CurrentPLGMode;

uint16_t MessageTx_GaragePosition_Remainder;

uint8_t MessageTx_CommandActive;
uint8_t MessageTx_VehicleGearLever;

uint8_t MessageTx_GearMotorFault;
uint8_t MessageTx_Motor1Fault;
uint8_t MessageTx_Motor2Fault;
uint8_t MessageTx_LatchMotorFault;
uint8_t MessageTx_TapeSwitchFault;
uint8_t MessageTx_HallFault;

/*Tx Command Signal to Bus*/
uint8_t MessageTx_RemoteKey;
uint8_t MessageTx_KickSensor;
uint8_t MessageTx_PKETrunkButton;

uint8_t MessageTx_OpenCloseSwitch;
uint8_t MessageTx_OutsideHandleSwitch;
uint8_t MessageTx_ShutFaceSwitch;
uint8_t MessageTx_ShutFaceLockSwitch;
uint8_t MessageTx_HandFreeSwitch;

/*Condition Failure*/
uint8_t MessageTx_ObstacleDetected;
uint8_t MessageTx_AntiPinch;
uint8_t MessageTx_VoltageFailure;
uint8_t MessageTx_TemperatureFailure;
uint8_t MessageTx_SpeedFailure;
uint8_t MessageTx_ParkFailure;
uint8_t MessageTx_CrankFailure;
uint8_t MessageTx_LockFailure;

uint8_t MessageTx_TimeoutFailure;
uint8_t MessageTx_PlayoffFailure;
uint8_t MessageTx_GateMotorStallFailure;
uint8_t MessageTx_LatchMotorStallFailure;
uint8_t MessageTx_GateThermalProtectionFailure;
uint8_t MessageTx_LatchThermalProtectionFailure;

/*Receive message*/
#ifdef _CONFIG_TimeInformation	 
uint8_t MessageRx_TimeInformation_Ind;
uint8_t MessageRx_TimeInformation_Valid;
uint8_t MessageRx_TimeMode;
uint8_t MessageRx_Week;
uint8_t MessageRx_Year;
uint8_t MessageRx_Month;
uint8_t MessageRx_Day;
uint8_t MessageRx_Hour;
uint8_t MessageRx_Minute;
uint8_t MessageRx_Second;
uint8_t TimeInformation_Real_Status;
#endif

#ifdef _CONFIG_Odometer
uint8_t MessageRx_Odometer_Ind;
uint8_t MessageRx_Odometer_Valid;
uint32_t MessageRx_Odometer;
uint8_t Odometer_Real_Status;
#endif

uint8_t MessageRx_VehiclePowerMode;
uint8_t MessageRx_VehiclePowerMode_Engine;

uint8_t MessageRx_GateLockUnlock;
uint8_t MessageRx_GateLockUnlock_Ind;

uint8_t MessageRx_RestoreRequest;
uint8_t MessageRx_RestoreRequestStatus;

uint8_t MessageRx_GarageHeight;
uint8_t MessageRx_SlidePosition;
uint8_t MessageRx_BusTemperature;

uint8_t MessageRx_VehiclePowerMode_Ind;
uint8_t MessageRx_VehicleAntiTheft_Ind;
uint8_t MessageRx_RestoreRequest_Ind;

uint8_t MessageRx_SlidePosition_Ind;
uint8_t MessageRx_GarageHeight_Ind;
uint8_t MessageRx_BusTemperature_Ind;

uint16_t MessageRx_GarageHeight_Counter;
uint16_t MessageRx_SlidePosition_Counter;
uint16_t MessageRx_GarageHeight_Value;
uint16_t MessageRx_GarageHeight_LastValue;

uint16_t MessageRx_SlidePosition_Value;
uint16_t MessageRx_SlidePosition_LastValue;
uint8_t MessageRx_VehicleGearLever_Valid;

uint8_t MessageRx_GarageHeight_Valid;
uint8_t MessageRx_VehiclePowerMode_Valid;   


uint16_t MessageRx_VehicleSpeed;
uint8_t MessageRx_VehicleSpeed_Ind;
uint8_t MessageRx_VehicleSpeed_Valid; 
uint8_t VehicleSpeed_E2E_Status;
uint8_t MessageRx_VehicleSpeed_E2E;

uint8_t VehicleSpeed_Valid_Status;
uint16_t VehicleSpeedLimit_DataStream;
uint8_t VehicleSpeedLimit_Status;  
uint8_t VehicleSpeedLimit_LastStatus;
uint8_t VehicleSpeedLimit_RiseEdge_Active;  
uint8_t VehicleSpeedLimit_FallEdge_Active;

#ifdef _CONFIG_VehicleSpeedStop
uint16_t VehicleSpeedStop_DataStream;
uint8_t VehicleSpeedStop_Status;  
uint8_t VehicleSpeedStop_LastStatus;
uint8_t VehicleSpeedStop_RiseEdge_Active;  
uint8_t VehicleSpeedStop_FallEdge_Active;
#endif




#ifdef _CONFIG_ModeStatus_NormalMode
uint16_t NormalMode_DataStream;
uint8_t NormalMode_Status;
uint8_t NormalMode_LastStatus;
uint8_t NormalMode_FallEdge_Active;
uint8_t NormalMode_RiseEdge_Active;
uint8_t NormalMode_Real_Status;
uint8_t NormalMode_SingleEvent_Enable;
uint8_t MessageRx_NormalMode;
uint8_t MessageRx_NormalMode_Valid;
uint8_t MessageRx_NormalMode_Ind;
#endif

#ifdef _CONFIG_ModeStatus_ManualMode
uint16_t ManualMode_DataStream;
uint8_t ManualMode_Status;
uint8_t ManualMode_LastStatus;
uint8_t ManualMode_FallEdge_Active;
uint8_t ManualMode_RiseEdge_Active;
uint8_t ManualMode_Real_Status;
uint8_t ManualMode_SingleEvent_Enable;
uint8_t MessageRx_ManualMode;
uint8_t MessageRx_ManualMode_Valid;
uint8_t MessageRx_ManualMode_Ind;
#endif

#ifdef _CONFIG_AutoOpenEnable
uint16_t AutoOpenEnable_DataStream;
uint8_t AutoOpenEnable_Status;
uint8_t AutoOpenEnable_Real_Status;
uint8_t AutoOpenEnable_SingleEvent_Enable;
uint8_t MessageRx_AutoOpenEnable;
uint8_t MessageRx_AutoOpenEnable_Valid;
uint8_t MessageRx_AutoOpenEnable_Ind;
#endif

#ifdef _CONFIG_VoiceEnable
uint16_t VoiceEnable_DataStream;
uint8_t VoiceEnable_Status;
uint8_t VoiceEnable_Real_Status;
uint8_t VoiceEnable_SingleEvent_Enable;
uint8_t MessageRx_VoiceEnable;
uint8_t MessageRx_VoiceEnable_Valid;
uint8_t MessageRx_VoiceEnable_Ind;
#endif

#ifdef _CONFIG_BrakeEnable
uint16_t BrakeEnable_DataStream;
uint8_t BrakeEnable_Status;
uint8_t BrakeEnable_Real_Status;
uint8_t BrakeEnable_SingleEvent_Enable;
uint8_t MessageRx_BrakeEnable;
uint8_t MessageRx_BrakeEnable_Valid;
uint8_t MessageRx_BrakeEnable_Ind;
#endif

#ifdef _CONFIG_RKEEnable
uint16_t RKEEnable_DataStream;
uint8_t RKEEnable_Status;
uint8_t RKEEnable_Real_Status;
uint8_t RKEEnable_SingleEvent_Enable;
uint8_t MessageRx_RKEEnable;
uint8_t MessageRx_RKEEnable_Valid;
uint8_t MessageRx_RKEEnable_Ind;
#endif


#ifdef _CONFIG_DoorPowerMode
uint16_t DoorPowerMode_DataStream;
uint8_t DoorPowerMode_Status;
uint8_t DoorPowerMode_Real_Status;
uint8_t DoorPowerMode_SingleEvent_Enable;
uint8_t MessageRx_DoorPowerMode;
uint8_t MessageRx_DoorPowerMode_Valid;
uint8_t MessageRx_DoorPowerMode_Ind;
#endif

#ifdef _CONFIG_ConfigurationTrigger
uint16_t ConfigurationTrigger_DataStream;
uint8_t ConfigurationTrigger_Status;
uint8_t ConfigurationTrigger_LastStatus;
uint8_t ConfigurationTrigger_RiseEdge_Active;  
uint8_t ConfigurationTrigger_FallEdge_Active;
uint8_t ConfigurationTrigger_Real_Status;
uint8_t ConfigurationTrigger_SingleEvent_Enable;
uint8_t MessageRx_ConfigurationTrigger;
uint8_t MessageRx_ConfigurationTrigger_Valid;
uint8_t MessageRx_ConfigurationTrigger_Ind;

uint8_t ConfigurationTrigger_E2E_Status;
uint8_t MessageRx_ConfigurationTrigger_E2E;
#endif
#ifdef _CONFIG_SideDoorOpeningMode
uint16_t SideDoorOpeningMode_DataStream;
uint8_t SideDoorOpeningMode_Status;
uint8_t SideDoorOpeningMode_Real_Status;
uint8_t SideDoorOpeningMode_SingleEvent_Enable;
uint8_t MessageRx_SideDoorOpeningMode;
uint8_t MessageRx_SideDoorOpeningMode_Valid;
uint8_t MessageRx_SideDoorOpeningMode_Ind;

uint8_t SideDoorOpeningMode_E2E_Status;
uint8_t MessageRx_SideDoorOpeningMode_E2E;
#endif
#ifdef _CONFIG_LeftAndRightRudder
uint16_t LeftAndRightRudder_DataStream;
uint8_t LeftAndRightRudder_Status;
uint8_t LeftAndRightRudder_Real_Status;
uint8_t LeftAndRightRudder_SingleEvent_Enable;
uint8_t MessageRx_LeftAndRightRudder;
uint8_t MessageRx_LeftAndRightRudder_Valid;
uint8_t MessageRx_LeftAndRightRudder_Ind;

uint8_t LeftAndRightRudder_E2E_Status;
uint8_t MessageRx_LeftAndRightRudder_E2E;
#endif
#ifdef _CONFIG_BNCM
uint16_t BNCM_DataStream;
uint8_t BNCM_Status;
uint8_t BNCM_Real_Status;
uint8_t BNCM_SingleEvent_Enable;
uint8_t MessageRx_BNCM;
uint8_t MessageRx_BNCM_Valid;
uint8_t MessageRx_BNCM_Ind;

uint8_t BNCM_E2E_Status;
uint8_t MessageRx_BNCM_E2E;
#endif


uint8_t VehicleCrank_Status; 
#ifdef _CONFIG_VehiclePowerMode
uint16_t VehicleCrank_DataStream;   
uint8_t VehicleCrank_Real_Status;
uint8_t VehicleCrank_LastStatus;
uint8_t VehicleCrank_RiseEdge_Active;
uint8_t VehicleCrank_FallEdge_Active;
#endif

#ifdef _CONFIG_VehicleLock
uint16_t VehicleLock_DataStream;
uint8_t VehicleLock_Status;
uint8_t VehicleLock_LastStatus;
uint8_t VehicleLock_RiseEdge_Active;
uint8_t VehicleLock_FallEdge_Active;
uint8_t VehicleLock_Real_Status;
uint8_t MessageRx_VehicleLock;
uint8_t MessageRx_VehicleLock_Valid;
uint8_t MessageRx_VehicleLock_Ind;
#endif

#ifdef _CONFIG_VehicleChildLock
uint16_t VehicleChildLock_DataStream;
uint8_t VehicleChildLock_Status;
uint8_t VehicleChildLock_LastStatus;
uint8_t VehicleChildLock_RiseEdge_Active;
uint8_t VehicleChildLock_FallEdge_Active;
uint8_t VehicleChildLock_Real_Status;
uint8_t MessageRx_VehicleChildLock;
uint8_t MessageRx_VehicleChildLock_Valid;
uint8_t MessageRx_VehicleChildLock_Ind;
#endif

#ifdef _CONFIG_VehicleGearLever
uint8_t VehicleGearLever_Valid_Status;
uint16_t VehicleGearLever_DataStream;
uint8_t VehicleGearLever_Status;
uint8_t VehicleGearLever_LastStatus;
uint8_t VehicleGearLever_RiseEdge_Active;
uint8_t VehicleGearLever_FallEdge_Active;
uint8_t VehicleGearLever_Real_Status;
uint8_t MessageRx_VehicleGearLever;
uint8_t MessageRx_VehicleGearLever_Ind;

uint8_t VehicleGearLever_E2E_Status;
uint8_t MessageRx_VehicleGearLever_E2E;
#endif

#ifdef _CONFIG_VehicleMode
uint8_t VehicleMode_Valid_Status;
uint16_t VehicleMode_DataStream;
uint8_t VehicleMode_Status;
uint8_t VehicleMode_LastStatus;
uint8_t VehicleMode_RiseEdge_Active;
uint8_t VehicleMode_FallEdge_Active;
uint8_t VehicleMode_Real_Status;
uint8_t MessageRx_VehicleMode;
uint8_t MessageRx_VehicleMode_Valid;
uint8_t MessageRx_VehicleMode_Ind;
#endif

#ifdef _CONFIG_VehicleAntiTheft
uint8_t MessageRx_VehicleAntiTheft;
uint8_t MessageRx_VehicleAntiTheft_Valid;
uint8_t VehicleAntiTheft_Real_Status;
uint16_t VehicleAntiTheft_DataStream;
uint16_t VehicleAntiTheft_Status;
#endif

uint8_t VehicleSpeed_Real_Status;
uint8_t RestoreRequest_Real_Status;
uint8_t BusPowerMode_Real_Status;

#ifdef _CONFIG_DoorStatus
uint8_t MessageRx_DriverDoor;
uint8_t MessageRx_DriverDoor_Valid;
uint8_t MessageRx_DriverDoor_Ind;
uint8_t DriverDoor_Real_Status;
uint16_t DriverDoor_DataStream;
uint8_t DriverDoor_Status;  

uint8_t MessageRx_PassengerDoor;
uint8_t MessageRx_PassengerDoor_Valid;
uint8_t MessageRx_PassengerDoor_Ind;
uint8_t PassengerDoor_Real_Status;
uint16_t PassengerDoor_DataStream;
uint8_t PassengerDoor_Status;  

uint8_t MessageRx_RearLeftDoor;
uint8_t MessageRx_RearLeftDoor_Valid;
uint8_t MessageRx_RearLeftDoor_Ind;
uint8_t RearLeftDoor_Real_Status;
uint16_t RearLeftDoor_DataStream;
uint8_t RearLeftDoor_Status;  

uint8_t MessageRx_RearRightDoor;
uint8_t MessageRx_RearRightDoor_Valid;
uint8_t MessageRx_RearRightDoor_Ind;
uint8_t RearRightDoor_Real_Status;
uint16_t RearRightDoor_DataStream;
uint8_t RearRightDoor_Status;  

#ifdef _CONFIG_DoorStatus_TrunkDoor
uint8_t MessageRx_TrunkDoor;
uint8_t MessageRx_TrunkDoor_Valid;
uint8_t MessageRx_TrunkDoor_Ind;
uint8_t TrunkDoor_Real_Status;
uint16_t TrunkDoor_DataStream;
uint8_t TrunkDoor_Status; 
#endif
#endif

#ifdef _CONFIG_WindowsPosition
uint8_t MessageRx_DriverWindow;
uint8_t MessageRx_PassengerWindow;
uint8_t MessageRx_RearLeftWindow;
uint8_t MessageRx_RearRightWindow;

uint8_t MessageRx_DriverWindow_Ind;
uint8_t MessageRx_PassengerWindow_Ind;
uint8_t MessageRx_RearLeftWindow_Ind;
uint8_t MessageRx_RearRightWindow_Ind;

uint8_t DriverWindow_Status;
uint8_t PassengerWindow_Status;
uint8_t RearLeftWindow_Status;
uint8_t RearRightWindow_Status;

uint8_t DriverWindow_Real_Status;
uint8_t PassengerWindow_Real_Status;
uint8_t RearLeftWindow_Real_Status;
uint8_t RearRightWindow_Real_Status;

uint16_t DriverWindow_DataStream;
uint16_t PassengerWindow_DataStream;
uint16_t RearLeftWindow_DataStream;
uint16_t RearRightWindow_DataStream;
#endif
#ifdef _CONFIG_BlowerSpeed
uint8_t MessageRx_FrontBlowerSpeed;
uint8_t MessageRx_FrontBlowerSpeed_Direction;
uint8_t MessageRx_FrontBlowerSpeed_Valid;
uint8_t MessageRx_FrontBlowerSpeed_Ind;
uint8_t FrontBlowerSpeed_Real_Status;

uint8_t FrontBlowerSpeedHigh_Status;
uint8_t FrontBlowerSpeedLow_Status;
uint16_t FrontBlowerSpeedHigh_DataStream;
uint16_t FrontBlowerSpeedLow_DataStream;

uint8_t MessageRx_RearBlowerSpeed;
uint8_t MessageRx_RearBlowerSpeed_Valid;
uint8_t MessageRx_RearBlowerSpeed_Ind;
uint8_t RearBlowerSpeed_Real_Status;

uint8_t RearBlowerSpeedHigh_Status;
uint8_t RearBlowerSpeedLow_Status;
uint16_t RearBlowerSpeedHigh_DataStream;
uint16_t RearBlowerSpeedLow_DataStream;
#endif

#ifdef _CONFIG_BusTemperature
uint8_t MessageRx_BusTemperature_Valid;
uint8_t Bus_Temperature_Real_Status;
uint8_t Bus_Temperature_Valid;

uint8_t BusTemperatureOutOfRange_Status;
uint8_t BusTemperatureOutOfRange_Real_Status;
uint16_t BusTemperatureOutOfRange_DataStream;
#endif

uint8_t SupportControl_Status;
uint8_t StepControl_Request;



#ifdef _CONFIG_VehicleBrake
uint16_t VehicleBrake_DataStream;
uint8_t VehicleBrake_Status;
uint8_t VehicleBrake_LastStatus;
uint8_t VehicleBrake_RiseEdge_Active;
uint8_t VehicleBrake_FallEdge_Active;
uint8_t VehicleBrake_Real_Status;
uint8_t VehicleBrake_SingleEvent_Enable;
uint8_t MessageRx_VehicleBrake;
uint8_t MessageRx_VehicleBrake_Valid;
uint8_t MessageRx_VehicleBrake_Ind;

uint8_t VehicleBrake_E2E_Status;
uint8_t MessageRx_VehicleBrake_E2E;

#ifdef _CONFIG_VehicleBrake_LongPress
uint8_t VehicleBrake_LongPress_Status;
uint8_t VehicleBrake_LongPress_LastStatus;
uint8_t VehicleBrake_LongPress_Active;
#endif
#endif

#ifdef _CONFIG_VehicleCrash
uint16_t VehicleCrash_DataStream;
uint8_t VehicleCrash_Status;
uint8_t VehicleCrash_LastStatus;
uint8_t VehicleCrash_RiseEdge_Active;
uint8_t VehicleCrash_FallEdge_Active;
uint8_t VehicleCrash_Real_Status;
uint8_t VehicleCrash_SingleEvent_Enable;
uint8_t MessageRx_VehicleCrash;
uint8_t MessageRx_VehicleCrash_Valid;
uint8_t MessageRx_VehicleCrash_Ind;

uint8_t VehicleCrash_E2E_Status;
uint8_t MessageRx_VehicleCrash_E2E;
#endif

#ifdef _CONFIG_VehicleClean
uint16_t VehicleClean_DataStream;
uint8_t VehicleClean_Status;
uint8_t VehicleClean_LastStatus;
uint8_t VehicleClean_RiseEdge_Active;
uint8_t VehicleClean_FallEdge_Active;
uint8_t VehicleClean_Real_Status;
uint8_t VehicleClean_SingleEvent_Enable;
uint8_t MessageRx_VehicleClean;
uint8_t MessageRx_VehicleClean_Valid;
uint8_t MessageRx_VehicleClean_Ind;

uint8_t VehicleClean_E2E_Status;
uint8_t MessageRx_VehicleClean_E2E;
#endif

#ifdef _CONFIG_SonicRadar
#ifdef _CONFIG_SonicRadar_Error
uint8_t SonicRadar_Error_Real_Status;
uint8_t MessageRx_SonicRadar_Error;
uint8_t MessageRx_SonicRadar_Error1;
uint8_t MessageRx_SonicRadar_Error2;
uint8_t MessageRx_SonicRadar_Error3;
uint8_t MessageRx_SonicRadar_Error4;
uint8_t MessageRx_SonicRadar_Error_Valid;
uint8_t MessageRx_SonicRadar_Error_Ind;
#endif
#ifdef _CONFIG_SonicRadar_Obstacle
uint8_t SonicRadar_Obstacle_Real_Status;
uint8_t MessageRx_SonicRadar_Obstacle;
uint8_t MessageRx_SonicRadar_Obstacle_Valid;
uint8_t MessageRx_SonicRadar_Obstacle_Ind;
#endif
#ifdef _CONFIG_SonicRadar_Angle
uint8_t SonicRadar_Angle_Real_Status;
uint16_t MessageRx_SonicRadar_Angle;
uint8_t MessageRx_SonicRadar_Angle_Valid;
uint8_t MessageRx_SonicRadar_Angle_Ind;
#endif
#ifdef _CONFIG_SonicRadar1_Distance
uint8_t SonicRadar1_Distance_Real_Status;
uint16_t MessageRx_SonicRadar1_Distance;
uint8_t MessageRx_SonicRadar1_Distance_Valid;
uint8_t MessageRx_SonicRadar1_Distance_Ind;
#endif
#ifdef _CONFIG_SonicRadar2_Distance
uint8_t SonicRadar2_Distance_Real_Status;
uint16_t MessageRx_SonicRadar2_Distance;
uint8_t MessageRx_SonicRadar2_Distance_Valid;
uint8_t MessageRx_SonicRadar2_Distance_Ind;
#endif
#ifdef _CONFIG_SonicRadar3_Distance
uint8_t SonicRadar3_Distance_Real_Status;
uint16_t MessageRx_SonicRadar3_Distance;
uint8_t MessageRx_SonicRadar3_Distance_Valid;
uint8_t MessageRx_SonicRadar3_Distance_Ind;
#endif
#endif

#ifdef _CONFIG_MmwRadar
#ifdef _CONFIG_MmwRadar_Error
uint8_t MmwRadar_Error_Real_Status;
uint8_t MessageRx_MmwRadar_Error;
uint8_t MessageRx_MmwRadar_Error1;
uint8_t MessageRx_MmwRadar_Error2;
uint8_t MessageRx_MmwRadar_Error3;
uint8_t MessageRx_MmwRadar_Error4;
uint8_t MessageRx_MmwRadar_Error5;
uint8_t MessageRx_MmwRadar_Error6;
uint8_t MessageRx_MmwRadar_Error_Valid;
uint8_t MessageRx_MmwRadar_Error_Ind;
#endif
#ifdef _CONFIG_MmwRadar_Obstacle
uint8_t MmwRadar_Obstacle_Real_Status;
uint8_t MessageRx_MmwRadar_Obstacle;
uint8_t MessageRx_MmwRadar_Obstacle_Valid;
uint8_t MessageRx_MmwRadar_Obstacle_Ind;
#endif
#ifdef _CONFIG_MmwRadar_Angle
uint8_t MmwRadar_Angle_Real_Status;
uint16_t MessageRx_MmwRadar_Angle;
uint8_t MessageRx_MmwRadar_Angle_Valid;
uint8_t MessageRx_MmwRadar_Angle_Ind;
#endif
#ifdef _CONFIG_MmwRadarX_Distance
uint8_t MmwRadarX_Distance_Real_Status;
uint16_t MessageRx_MmwRadarX_Distance;
uint8_t MessageRx_MmwRadarX_Distance_Valid;
uint8_t MessageRx_MmwRadarX_Distance_Ind;
#endif
#ifdef _CONFIG_MmwRadarY_Distance
uint8_t MmwRadarY_Distance_Real_Status;
uint16_t MessageRx_MmwRadarY_Distance;
uint8_t MessageRx_MmwRadarY_Distance_Valid;
uint8_t MessageRx_MmwRadarY_Distance_Ind;
#endif
#ifdef _CONFIG_MmwRadarZ_Distance
uint8_t MmwRadarZ_Distance_Real_Status;
uint16_t MessageRx_MmwRadarZ_Distance;
uint8_t MessageRx_MmwRadarZ_Distance_Valid;
uint8_t MessageRx_MmwRadarZ_Distance_Ind;
#endif
#endif

#ifdef _CONFIG_AdasRadar
#ifdef _CONFIG_AdasRadar_RearCorner_Error
uint8_t AdasRadar_RearCorner_Error_Real_Status;
uint8_t MessageRx_AdasRadar_RearCorner_Error;
uint8_t MessageRx_AdasRadar_RearCorner_Error_Valid;
uint8_t MessageRx_AdasRadar_RearCorner_Error_Ind;
#endif
#ifdef _CONFIG_AdasRadar_RearCorner_Obstacle
uint8_t AdasRadar_RearCorner_Obstacle_Real_Status;
uint8_t MessageRx_AdasRadar_RearCorner_Obstacle;
uint8_t MessageRx_AdasRadar_RearCorner_Obstacle_Valid;
uint8_t MessageRx_AdasRadar_RearCorner_Obstacle_Ind;
#endif
#ifdef _CONFIG_AdasRadar_RearCorner_Enable
uint8_t AdasRadar_RearCorner_Enable_Real_Status;
uint8_t MessageRx_AdasRadar_RearCorner_Enable;
uint8_t MessageRx_AdasRadar_RearCorner_Enable_Valid;
uint8_t MessageRx_AdasRadar_RearCorner_Enable_Ind;
#endif

#ifdef _CONFIG_AdasRadar_RearCornerX_Distance
uint8_t AdasRadar_RearCornerX_Distance_Real_Status;
uint16_t MessageRx_AdasRadar_RearCornerX_Distance;
uint8_t MessageRx_AdasRadar_RearCornerX_Distance_Valid;
uint8_t MessageRx_AdasRadar_RearCornerX_Distance_Ind;
#endif
#ifdef _CONFIG_AdasRadar_RearCornerY_Distance
uint8_t AdasRadar_RearCornerY_Distance_Real_Status;
uint16_t MessageRx_AdasRadar_RearCornerY_Distance;
uint8_t MessageRx_AdasRadar_RearCornerY_Distance_Valid;
uint8_t MessageRx_AdasRadar_RearCornerY_Distance_Ind;
#endif
#ifdef _CONFIG_AdasRadar_RearCornerZ_Distance
uint8_t AdasRadar_RearCornerZ_Distance_Real_Status;
uint16_t MessageRx_AdasRadar_RearCornerZ_Distance;
uint8_t MessageRx_AdasRadar_RearCornerZ_Distance_Valid;
uint8_t MessageRx_AdasRadar_RearCornerZ_Distance_Ind;
#endif
#endif

#ifdef _CONFIG_PKEAuthorize
uint16_t PKEAuthorize_DataStream;
uint8_t PKEAuthorize_Status;
uint8_t PKEAuthorize_LastStatus;
uint8_t PKEAuthorize_RiseEdge_Active;
uint8_t PKEAuthorize_FallEdge_Active;
uint8_t PKEAuthorize_Real_Status;
uint8_t MessageRx_PKEAuthorize;
uint8_t MessageRx_PKEAuthorize_Valid;
uint8_t MessageRx_PKEAuthorize_Ind;
uint8_t MessageTx_PKEAuthorize_Status;
#endif

#ifdef _CONFIG_TouchPad
uint32_t TouchPad_DataStream;
uint8_t TouchPad_Status;
uint8_t TouchPad_LastStatus;
uint8_t TouchPad_RiseEdge_Active;
uint8_t TouchPad_FallEdge_Active;
uint8_t TouchPad_Real_Status;
uint8_t TouchPad_SingleEvent_Enable;
uint8_t MessageRx_TouchPad;
uint8_t MessageRx_TouchPad_Valid;
uint8_t MessageRx_TouchPad_Ind;
#endif

#ifdef _CONFIG_TouchPad_2nd
uint32_t TouchPad_2nd_DataStream;
uint8_t TouchPad_2nd_Status;
uint8_t TouchPad_2nd_LastStatus;
uint8_t TouchPad_2nd_RiseEdge_Active;
uint8_t TouchPad_2nd_FallEdge_Active;
uint8_t TouchPad_2nd_Real_Status;
uint8_t TouchPad_2nd_SingleEvent_Enable;
uint8_t MessageRx_TouchPad_2nd;
uint8_t MessageRx_TouchPad_2nd_Valid;
uint8_t MessageRx_TouchPad_2nd_Ind;

#endif




#ifdef _CONFIG_PKETrunkButton
uint32_t PKETrunkButton_DataStream;
uint8_t PKETrunkButton_Status;
uint8_t PKETrunkButton_LastStatus;
uint8_t PKETrunkButton_RiseEdge_Active;
uint8_t PKETrunkButton_FallEdge_Active;
uint8_t PKETrunkButton_Real_Status;
uint8_t PKETrunkButton_SingleEvent_Enable;
uint8_t MessageRx_PKETrunkButton;
uint8_t MessageRx_PKETrunkButton_Valid;
uint8_t MessageRx_PKETrunkButton_Ind;
#endif

#ifdef _CONFIG_VirtualButton
uint32_t VirtualButton_DataStream;
uint8_t VirtualButton_Status;
uint8_t VirtualButton_LastStatus;
uint8_t VirtualButton_RiseEdge_Active;
uint8_t VirtualButton_FallEdge_Active;
uint8_t VirtualButton_Real_Status;
uint8_t VirtualButton_SingleEvent_Enable;
uint8_t MessageRx_VirtualButton;
uint8_t MessageRx_VirtualButton_Valid;
uint8_t MessageRx_VirtualButton_Ind;

#endif

#ifdef _CONFIG_VoiceOpen
uint32_t VoiceOpen_DataStream;
uint8_t VoiceOpen_Status;
uint8_t VoiceOpen_LastStatus;
uint8_t VoiceOpen_RiseEdge_Active;
uint8_t VoiceOpen_FallEdge_Active;
uint8_t VoiceOpen_Real_Status;
uint8_t VoiceOpen_SingleEvent_Enable;
uint8_t MessageRx_VoiceOpen;
uint8_t MessageRx_VoiceOpen_Valid;
uint8_t MessageRx_VoiceOpen_Ind;
#endif

#ifdef _CONFIG_VoiceClose
uint32_t VoiceClose_DataStream;
uint8_t VoiceClose_Status;
uint8_t VoiceClose_LastStatus;
uint8_t VoiceClose_RiseEdge_Active;
uint8_t VoiceClose_FallEdge_Active;
uint8_t VoiceClose_Real_Status;
uint8_t VoiceClose_SingleEvent_Enable;
uint8_t MessageRx_VoiceClose;
uint8_t MessageRx_VoiceClose_Valid;
uint8_t MessageRx_VoiceClose_Ind;
#endif

#ifdef _CONFIG_VoiceStop
uint32_t VoiceStop_DataStream;
uint8_t VoiceStop_Status;
uint8_t VoiceStop_LastStatus;
uint8_t VoiceStop_RiseEdge_Active;
uint8_t VoiceStop_FallEdge_Active;
uint8_t VoiceStop_Real_Status;
uint8_t VoiceStop_SingleEvent_Enable;
uint8_t MessageRx_VoiceStop;
uint8_t MessageRx_VoiceStop_Valid;
uint8_t MessageRx_VoiceStop_Ind;
#endif

#ifdef _CONFIG_VRClose
uint32_t VRClose_DataStream;
uint8_t VRClose_Status;
uint8_t VRClose_LastStatus;
uint8_t VRClose_RiseEdge_Active;
uint8_t VRClose_FallEdge_Active;
uint8_t VRClose_Real_Status;
uint8_t VRClose_SingleEvent_Enable;
uint8_t MessageRx_VRClose;
uint8_t MessageRx_VRClose_Valid;
uint8_t MessageRx_VRClose_Ind;
#endif




#ifdef _CONFIG_AutoOpen
uint32_t AutoOpen_DataStream;
uint8_t AutoOpen_Status;
uint8_t AutoOpen_LastStatus;
uint8_t AutoOpen_RiseEdge_Active;
uint8_t AutoOpen_FallEdge_Active;
uint8_t AutoOpen_Real_Status;
uint8_t AutoOpen_SingleEvent_Enable;
uint8_t MessageRx_AutoOpen;
uint8_t MessageRx_AutoOpen_Valid;
uint8_t MessageRx_AutoOpen_Ind;
#endif


#ifdef _CONFIG_BLEClose
uint32_t BLEClose_DataStream;
uint8_t BLEClose_Status;
uint8_t BLEClose_LastStatus;
uint8_t BLEClose_RiseEdge_Active;
uint8_t BLEClose_FallEdge_Active;
uint8_t BLEClose_Real_Status;
uint8_t BLEClose_SingleEvent_Enable;
uint8_t MessageRx_BLEClose;
uint8_t MessageRx_BLEClose_Valid;
uint8_t MessageRx_BLEClose_Ind;
#endif

#ifdef _CONFIG_BLEButton
uint32_t BLEButton_DataStream;
uint8_t BLEButton_Status;
uint8_t BLEButton_LastStatus;
uint8_t BLEButton_RiseEdge_Active;
uint8_t BLEButton_FallEdge_Active;
uint8_t BLEButton_Real_Status;
uint8_t BLEButton_SingleEvent_Enable;
uint8_t MessageRx_BLEButton;
uint8_t MessageRx_BLEButton_Valid;
uint8_t MessageRx_BLEButton_Ind;
#endif

#ifdef _CONFIG_RKEOpen
uint32_t RKEOpen_DataStream;
uint8_t RKEOpen_Status;
uint8_t RKEOpen_LastStatus;
uint8_t RKEOpen_RiseEdge_Active;
uint8_t RKEOpen_FallEdge_Active;
uint8_t RKEOpen_Real_Status;
uint8_t RKEOpen_SingleEvent_Enable;
uint8_t MessageRx_RKEOpen;
uint8_t MessageRx_RKEOpen_Valid;
uint8_t MessageRx_RKEOpen_Ind;
#endif
#ifdef _CONFIG_RKEClose
uint32_t RKEClose_DataStream;
uint8_t RKEClose_Status;
uint8_t RKEClose_LastStatus;
uint8_t RKEClose_RiseEdge_Active;
uint8_t RKEClose_FallEdge_Active;
uint8_t RKEClose_Real_Status;
uint8_t RKEClose_SingleEvent_Enable;
uint8_t MessageRx_RKEClose;
uint8_t MessageRx_RKEClose_Valid;
uint8_t MessageRx_RKEClose_Ind;
#endif
#ifdef _CONFIG_RKEStopOpen
uint32_t RKEStopOpen_DataStream;
uint8_t RKEStopOpen_Status;
uint8_t RKEStopOpen_LastStatus;
uint8_t RKEStopOpen_RiseEdge_Active;
uint8_t RKEStopOpen_FallEdge_Active;
uint8_t RKEStopOpen_Real_Status;
uint8_t RKEStopOpen_SingleEvent_Enable;
uint8_t MessageRx_RKEStopOpen;
uint8_t MessageRx_RKEStopOpen_Valid;
uint8_t MessageRx_RKEStopOpen_Ind;
#endif
#ifdef _CONFIG_RKEStopClose
uint32_t RKEStopClose_DataStream;
uint8_t RKEStopClose_Status;
uint8_t RKEStopClose_LastStatus;
uint8_t RKEStopClose_RiseEdge_Active;
uint8_t RKEStopClose_FallEdge_Active;
uint8_t RKEStopClose_Real_Status;
uint8_t RKEStopClose_SingleEvent_Enable;
uint8_t MessageRx_RKEStopClose;
uint8_t MessageRx_RKEStopClose_Valid;
uint8_t MessageRx_RKEStopClose_Ind;
#endif


#ifdef _CONFIG_InsideButton
uint32_t InsideButton_DataStream;
uint8_t InsideButton_Status;
uint8_t InsideButton_LastStatus;
uint8_t InsideButton_RiseEdge_Active;
uint8_t InsideButton_FallEdge_Active;
uint8_t InsideButton_Real_Status;
uint8_t InsideButton_SingleEvent_Enable;
uint8_t MessageRx_InsideButton;
uint8_t MessageRx_InsideButton_Valid;
uint8_t MessageRx_InsideButton_Ind;

#endif

#ifdef _CONFIG_DriverButton
uint32_t DriverButton_DataStream;
uint8_t DriverButton_Status;
uint8_t DriverButton_LastStatus;
uint8_t DriverButton_RiseEdge_Active;
uint8_t DriverButton_FallEdge_Active;
uint8_t DriverButton_Real_Status;
uint8_t DriverButton_SingleEvent_Enable;
uint8_t MessageRx_DriverButton;
uint8_t MessageRx_DriverButton_Valid;
uint8_t MessageRx_DriverButton_Ind;

#endif


#ifdef _CONFIG_GarageHeightRequest
uint16_t GarageHeightRequest_DataStream;
uint8_t GarageHeightRequest_Status;
uint8_t GarageHeightRequest_LastStatus;
uint8_t GarageHeightRequest_RiseEdge_Active;
uint8_t GarageHeightRequest_FallEdge_Active;
uint8_t GarageHeightRequest_SingleEvent_Enable;
uint8_t GarageHeightRequest_Real_Status;
uint8_t MessageRx_GarageHeightRequest;
uint8_t MessageRx_GarageHeightRequest_Ind;
#endif
uint8_t GarageHeightRequest_Process_Status;

#ifdef _CONFIG_LatchSignal
uint16_t LatchSignal_DataStream;
uint8_t LatchSignal_Status;
uint8_t LatchSignal_LastStatus;
uint8_t LatchSignal_RiseEdge_Active;
uint8_t LatchSignal_FallEdge_Active;
uint8_t LatchSignal_Real_Status;
uint8_t LatchSignal_SingleEvent_Enable;
uint8_t MessageRx_LatchSignal;
uint8_t MessageRx_LatchSignal_Valid;
uint8_t MessageRx_LatchSignal_Ind;
#endif

#ifdef _CONFIG_LatchReleaseState
uint8_t LatchReleaseState_Valid_Status;
uint16_t LatchReleaseState_DataStream;
uint8_t LatchReleaseState_Status;
uint8_t LatchReleaseState_LastStatus;
uint8_t LatchReleaseState_RiseEdge_Active;
uint8_t LatchReleaseState_FallEdge_Active;
uint8_t LatchReleaseState_Real_Status;
uint8_t MessageRx_LatchReleaseState;
uint8_t MessageRx_LatchReleaseState_Valid;
uint8_t MessageRx_LatchReleaseState_Ind;
#endif
#ifdef _CONFIG_CentralLockSignal
uint16_t CentralLockSignal_DataStream;
uint8_t CentralLockSignal_Status;
uint8_t CentralLockSignal_LastStatus;
uint8_t CentralLockSignal_RiseEdge_Active;
uint8_t CentralLockSignal_FallEdge_Active;
uint8_t CentralLockSignal_Real_Status;
uint8_t CentralLockSignal_SingleEvent_Enable;
uint8_t MessageRx_CentralLockSignal;
uint8_t MessageRx_CentralLockSignal_Valid;
uint8_t MessageRx_CentralLockSignal_Ind;
#endif
#ifdef _CONFIG_ChildLockSignal
uint16_t ChildLockSignal_DataStream;
uint8_t ChildLockSignal_Status;
uint8_t ChildLockSignal_LastStatus;
uint8_t ChildLockSignal_RiseEdge_Active;
uint8_t ChildLockSignal_FallEdge_Active;
uint8_t ChildLockSignal_Real_Status;
uint8_t ChildLockSignal_SingleEvent_Enable;
uint8_t MessageRx_ChildLockSignal;
uint8_t MessageRx_ChildLockSignal_Valid;
uint8_t MessageRx_ChildLockSignal_Ind;
#endif



/*Save data before sleep*/
tD_Message_Information Mem_Message_Information;

#ifdef _CONFIG_FunctionEnable_KeepAfterWakeup
tD_FunctionEnable Mem_FunctionEnable;
#endif


/*********************************************************************************************
** Variables at File Scope
*********************************************************************************************/




/*********************************************************************************************
** Functions with Global Scope
*********************************************************************************************/

void PE10ms_MessageDebounce_Master(void);
void MessageDebounce_Init(void);


/*********************************************************************************************
** Functions with Lcobal Scope
*********************************************************************************************/

static void MessageCommand_Update(void);
static void MessageCondition_Update(void);
static void MessageTransmit_Update(void);

/* MessageConditionUpdate */
#ifdef _CONFIG_VehiclePowerMode
static void MessageDebounce_VehiclePowerMode(void);
#endif
#ifdef _CONFIG_VehicleGearLever
static void MessageDebounce_VehicleGearLever(void);
#endif
#ifdef _CONFIG_VehicleLock
static void MessageDebounce_VehicleLock(void);
#endif
#ifdef _CONFIG_VehicleChildLock
static void MessageDebounce_VehicleChildLock(void);
#endif
#ifdef _CONFIG_VehicleAntiTheft
static void MessageDebounce_VehicleAntiTheft(void);
#endif
#ifdef _CONFIG_VehicleHandBrake
static void MessageDebounce_VehicleHandBrake(void);
#endif
#ifdef _CONFIG_VehicleMode
static void MessageDebounce_VehicleMode(void);
#endif
#ifdef _CONFIG_VehicleRemoteMode
static void MessageDebounce_VehicleRemoteMode(void);
#endif

#ifdef _CONFIG_CommandDelay_Cancel_ByFobLock
static void MessageDebounce_FobLock(void);
#endif

#ifdef _CONFIG_LatchSignal
static void MessageDebounce_LatchSignal(void);
#endif 
#ifdef _CONFIG_PawlSignal
static void MessageDebounce_PawlSignal(void);
#endif     
#ifdef _CONFIG_SecondarySignal
static void MessageDebounce_SecondarySignal(void);
#endif
#ifdef _CONFIG_AjarSignal
static void MessageDebounce_AjarSignal(void);
#endif
#ifdef _CONFIG_PositionSignal
static void MessageDebounce_PositionSignal(void);
#endif
#ifdef _CONFIG_CentralLockSignal
static void MessageDebounce_CentralLockSignal(void);
#endif
#ifdef _CONFIG_ChildLockSignal
static void MessageDebounce_ChildLockSignal(void);
#endif

#ifdef _CONFIG_LatchReleaseState
static void MessageDebounce_LatchReleaseState(void);
#endif

#ifdef _CONFIG_VehicleDriveMode
static void MessageDebounce_VehicleDriveMode(void);
#endif
#ifdef _CONFIG_KeyOpenMode
static void MessageDebounce_KeyOpenMode(void);
#endif
#ifdef _CONFIG_KeyCloseMode
static void MessageDebounce_KeyCloseMode(void);
#endif

#ifdef _CONFIG_AppAuthorize
static void MessageDebounce_AppAuthorize(void);
#endif
#ifdef _CONFIG_BLEAuthorize
static void MessageDebounce_BLEAuthorize(void);
#endif
#ifdef _CONFIG_FobAuthorize
static void MessageDebounce_FobAuthorize(void);
#endif
#ifdef _CONFIG_PKEAuthorize
static void MessageDebounce_PKEAuthorize(void);
#endif
#ifdef _CONFIG_AntiLockAuthorize
static void MessageDebounce_AntiLockAuthorize(void);
#endif

#ifdef _CONFIG_VehicleSpeed
static void MessageDebounce_VehicleSpeed(void);
#endif

#ifdef _CONFIG_VehicleBrake
static void MessageDebounce_VehicleBrake(void);
#endif

#ifdef _CONFIG_VehicleCrash
static void MessageDebounce_VehicleCrash(void);
#endif
#ifdef _CONFIG_VehicleRain
static void MessageDebounce_VehicleRain(void);
#endif
#ifdef _CONFIG_VehicleClean
static void MessageDebounce_VehicleClean(void);
#endif

#ifdef _CONFIG_SonicRadar
#ifdef _CONFIG_SonicRadar_Error
static void MessageDebounce_SonicRadar_Error(void);
#endif
#ifdef _CONFIG_SonicRadar_Obstacle
static void MessageDebounce_SonicRadar_Obstacle(void);
#endif
#ifdef _CONFIG_SonicRadar_Angle
static void MessageDebounce_SonicRadar_Angle(void);
#endif
#ifdef _CONFIG_SonicRadar1_Distance
static void MessageDebounce_SonicRadar1_Distance(void);
#endif
#ifdef _CONFIG_SonicRadar2_Distance
static void MessageDebounce_SonicRadar2_Distance(void);
#endif
#ifdef _CONFIG_SonicRadar3_Distance
static void MessageDebounce_SonicRadar3_Distance(void);
#endif
#endif

#ifdef _CONFIG_MmwRadar
#ifdef _CONFIG_MmwRadar_Error
static void MessageDebounce_MmwRadar_Error(void);
#endif
#ifdef _CONFIG_MmwRadar_Obstacle
static void MessageDebounce_MmwRadar_Obstacle(void);
#endif
#ifdef _CONFIG_MmwRadar_Angle
static void MessageDebounce_MmwRadar_Angle(void);
#endif
#ifdef _CONFIG_MmwRadarX_Distance
static void MessageDebounce_MmwRadarX_Distance(void);
#endif
#ifdef _CONFIG_MmwRadarY_Distance
static void MessageDebounce_MmwRadarY_Distance(void);
#endif
#ifdef _CONFIG_MmwRadarZ_Distance
static void MessageDebounce_MmwRadarZ_Distance(void);
#endif
#ifdef _CONFIG_MmwRadarD_Distance
static void MessageDebounce_MmwRadarD_Distance(void);
#endif
#endif

#ifdef _CONFIG_AdasRadar
#ifdef _CONFIG_AdasRadar_RearCorner_Error
static void MessageDebounce_AdasRadar_RearCorner_Error(void);
#endif
#ifdef _CONFIG_AdasRadar_RearCorner_Obstacle
static void MessageDebounce_AdasRadar_RearCorner_Obstacle(void);
#endif
#ifdef _CONFIG_AdasRadar_RearCorner_Angle
static void MessageDebounce_AdasRadar_RearCorner_Angle(void);
#endif
#ifdef _CONFIG_AdasRadar_RearCorner_Enable
static void MessageDebounce_AdasRadar_RearCorner_Enable(void);
#endif

#ifdef _CONFIG_AdasRadar_RearCornerX_Distance
static void MessageDebounce_AdasRadar_RearCornerX_Distance(void);
#endif
#ifdef _CONFIG_AdasRadar_RearCornerY_Distance
static void MessageDebounce_AdasRadar_RearCornerY_Distance(void);
#endif
#ifdef _CONFIG_AdasRadar_RearCornerZ_Distance
static void MessageDebounce_AdasRadar_RearCornerZ_Distance(void);
#endif
#endif



#ifdef _CONFIG_BusIncline
#ifdef _CONFIG_InclineX_Direction
static void MessageDebounce_BusInclineX(void);
#endif
#ifdef _CONFIG_InclineY_Direction
static void MessageDebounce_BusInclineY(void);
#endif
#ifdef _CONFIG_InclineZ_Direction
static void MessageDebounce_BusInclineZ(void);
#endif
#endif

#ifdef _CONFIG_EngineSpeed
static void MessageDebounce_EngineSpeed(void);
#endif
#ifdef _CONFIG_Odometer
static void MessageDebounce_Odometer(void);
#endif
#ifdef _CONFIG_TimeInformation
static void MessageDebounce_TimeInformation(void);
#endif
#ifdef _CONFIG_VehicleSOC
static void MessageDebounce_VehicleSOC(void);
#endif
#ifdef _CONFIG_VehicleVoltage
static void MessageDebounce_VehicleVoltage(void);
#endif

#ifdef _CONFIG_DoorStatus
static void MessageDebounce_DoorStatus(void);
#endif
#ifdef _CONFIG_WindowsPosition
static void MessageDebounce_WindowsPosition(void);
#endif
#ifdef _CONFIG_BlowerSpeed
static void MessageDebounce_BlowerSpeed(void);
#endif
#ifdef _CONFIG_RearWiperStatus
static void MessageDebounce_RearWiperStatus(void);
#endif
#ifdef _CONFIG_BusTemperature
static void MessageDebounce_BusTemperature(void);
#endif
#ifdef _CONFIG_SunRoofPosition
static void MessageDebounce_SunRoofPosition(void);
#endif

#ifdef _CONFIG_OpenSpeedLevel
static void MessageDebounce_OpenSpeedLevel(void);
#endif
#ifdef _CONFIG_CloseSpeedLevel
static void MessageDebounce_CloseSpeedLevel(void);
#endif

#ifdef _CONFIG_VehicleChargeState
static void MessageDebounce_VehicleChargeState(void);
#endif



#ifdef _CONFIG_ModeStatus_NormalMode
static void MessageDebounce_NormalMode(void);
#endif
#ifdef _CONFIG_ModeStatus_GarageMode
static void MessageDebounce_GarageMode(void);
#endif
#ifdef _CONFIG_ModeStatus_ManualMode
static void MessageDebounce_ManualMode(void);
#endif
#ifdef _CONFIG_KickSensorEnable
static void MessageDebounce_KickSensorEnable(void);
#endif
#ifdef _CONFIG_FlasherEnable
static void MessageDebounce_FlasherEnable(void);
#endif
#ifdef _CONFIG_BuzzerEnable
static void MessageDebounce_BuzzerEnable(void);
#endif
#ifdef _CONFIG_AutoOpenEnable
static void MessageDebounce_AutoOpenEnable(void);
#endif
#ifdef _CONFIG_ObstcalAlarmEnable
static void MessageDebounce_ObstcalAlarmEnable(void);
#endif

#ifdef _CONFIG_BLEEnable
static void MessageDebounce_BLEEnable(void);
#endif
#ifdef _CONFIG_VoiceEnable
static void MessageDebounce_VoiceEnable(void);
#endif
#ifdef _CONFIG_BrakeEnable
static void MessageDebounce_BrakeEnable(void);
#endif
#ifdef _CONFIG_RKEEnable
static void MessageDebounce_RKEEnable(void);
#endif

#ifdef _CONFIG_ManualOperateEnable
static void MessageDebounce_ManualOperateEnable(void);
#endif
#ifdef _CONFIG_MotorHoldEnable
static void MessageDebounce_MotorHoldEnable(void);
#endif
#ifdef _CONFIG_DoorPowerMode
static void MessageDebounce_DoorPowerMode(void);
#endif

#ifdef _CONFIG_CinchEnable
static void MessageDebounce_CinchEnable(void);
#endif
#ifdef _CONFIG_BeltEnable
static void MessageDebounce_BeltEnable(void);
#endif
#ifdef _CONFIG_WindEnable
static void MessageDebounce_WindEnable(void);
#endif
#ifdef _CONFIG_SpeedMode
static void MessageDebounce_SpeedMode(void);
#endif


#ifdef _CONFIG_ConfigurationTrigger
static void MessageDebounce_ConfigurationTrigger(void);
#endif
#ifdef _CONFIG_SideDoorOpeningMode
static void MessageDebounce_SideDoorOpeningMode(void);
#endif
#ifdef _CONFIG_LeftAndRightRudder
static void MessageDebounce_LeftAndRightRudder(void);
#endif
#ifdef _CONFIG_BNCM
static void MessageDebounce_BNCM(void);
#endif




/* MessageCommandUpdate */
#ifdef _CONFIG_RemoteKey
static void MessageDebounce_RemoteKey(void);
#endif
#ifdef _CONFIG_FobLongPress
static void MessageDebounce_FobLongPress(void);
#endif
#ifdef _CONFIG_FobShortPress
static void MessageDebounce_FobShortPress(void);
#endif

#ifdef _CONFIG_KickSensor
static void MessageDebounce_KickSensor(void);
#endif

#ifdef _CONFIG_ComfortClose
static void MessageDebounce_ComfortClose(void);
#endif
#ifdef _CONFIG_TouchPad
static void MessageDebounce_TouchPad(void);  
#endif
#ifdef _CONFIG_TouchPad_2nd
static void MessageDebounce_TouchPad_2nd(void);  
#endif


#ifdef _CONFIG_RemindStart
static void MessageDebounce_RemindStart(void);
#endif
#ifdef _CONFIG_RemindStop
static void MessageDebounce_RemindStop(void);
#endif

#ifdef _CONFIG_AppOpen
static void MessageDebounce_AppOpen(void);
#endif
#ifdef _CONFIG_AppClose
static void MessageDebounce_AppClose(void);
#endif
#ifdef _CONFIG_AppStop
static void MessageDebounce_AppStop(void);
#endif

#ifdef _CONFIG_AppButton
static void MessageDebounce_AppButton(void);
#endif
#ifdef _CONFIG_AppEnable
static void MessageDebounce_AppEnable(void);
#endif
#ifdef _CONFIG_AppReset
static void MessageDebounce_AppReset(void);
#endif
#ifdef _CONFIG_AppDemoMode
static void MessageDebounce_AppDemoMode(void);
#endif

#ifdef _CONFIG_VROpen
static void MessageDebounce_VROpen(void);
#endif
#ifdef _CONFIG_VRClose
static void MessageDebounce_VRClose(void);
#endif
#ifdef _CONFIG_VRStop
static void MessageDebounce_VRStop(void);
#endif
#ifdef _CONFIG_VRStopDirectly
static void MessageDebounce_VRStopDirectly(void);
#endif
#ifdef _CONFIG_VRSmallOpen
static void MessageDebounce_VRSmallOpen(void);
#endif

#ifdef _CONFIG_VoiceOpen
static void MessageDebounce_VoiceOpen(void);
#endif
#ifdef _CONFIG_VoiceClose
static void MessageDebounce_VoiceClose(void);
#endif
#ifdef _CONFIG_VoiceStop
static void MessageDebounce_VoiceStop(void);
#endif

#ifdef _CONFIG_AppStepOpen
static void MessageDebounce_AppStepOpen(void);
#endif
#ifdef _CONFIG_AppStepClose
static void MessageDebounce_AppStepClose(void);
#endif
#ifdef _CONFIG_VRStepOpen
static void MessageDebounce_VRStepOpen(void);
#endif
#ifdef _CONFIG_VRStepClose
static void MessageDebounce_VRStepClose(void);
#endif

#ifdef _CONFIG_AutoOpen
static void MessageDebounce_AutoOpen(void);
#endif
#ifdef _CONFIG_AutoClose
static void MessageDebounce_AutoClose(void);
#endif
#ifdef _CONFIG_AutoStop
static void MessageDebounce_AutoStop(void);
#endif
#ifdef _CONFIG_AutoStepOpen
static void MessageDebounce_AutoStepOpen(void);
#endif
#ifdef _CONFIG_AutoStepClose
static void MessageDebounce_AutoStepClose(void);
#endif
      
#ifdef _CONFIG_BLEOpen
static void MessageDebounce_BLEOpen(void);
#endif
#ifdef _CONFIG_BLEClose
static void MessageDebounce_BLEClose(void);
#endif
#ifdef _CONFIG_BLEStop
static void MessageDebounce_BLEStop(void);
#endif
#ifdef _CONFIG_BLEStepOpen
static void MessageDebounce_BLEStepOpen(void);
#endif
#ifdef _CONFIG_BLEStepClose
static void MessageDebounce_BLEStepClose(void);
#endif
#ifdef _CONFIG_BLEButton
static void MessageDebounce_BLEButton(void);
#endif

#ifdef _CONFIG_RKEOpen
static void MessageDebounce_RKEOpen(void);
#endif
#ifdef _CONFIG_RKEClose
static void MessageDebounce_RKEClose(void);
#endif
#ifdef _CONFIG_RKEStopOpen
static void MessageDebounce_RKEStopOpen(void);
#endif
#ifdef _CONFIG_RKEStopClose
static void MessageDebounce_RKEStopClose(void);
#endif
#ifdef _CONFIG_RKEStepOpen
static void MessageDebounce_RKEStepOpen(void);
#endif
#ifdef _CONFIG_RKEStepClose
static void MessageDebounce_RKEStepClose(void);
#endif

#ifdef _CONFIG_InsideButton
static void MessageDebounce_InsideButton(void);
#endif
#ifdef _CONFIG_DriverButton
static void MessageDebounce_DriverButton(void);
#endif
#ifdef _CONFIG_DriverButtonStop
static void MessageDebounce_DriverButtonStop(void);
#endif
#ifdef _CONFIG_SeatOccupied
static void MessageDebounce_SeatOccupied(void);
#endif
#ifdef _CONFIG_SeatBelt
static void MessageDebounce_SeatBelt(void);
#endif
#ifdef _CONFIG_DelayClose
static void MessageDebounce_DelayClose(void);
#endif

#ifdef _CONFIG_ManualRelease
static void MessageDebounce_ManualRelease(void);
#endif
#ifdef _CONFIG_GarageHeightRequest
static void MessageDebounce_GarageHeightRequest(void);
#endif
#ifdef _CONFIG_RestoreRequest
static void MessageDebounce_RestoreRequest(void);
#endif

#ifdef _CONFIG_TargetPositionOpen
static void MessageDebounce_TargetPositionOpen(void);
#endif
#ifdef _CONFIG_TargetPositionClose
static void MessageDebounce_TargetPositionClose(void);
#endif

#ifdef _CONFIG_SlidePosition
static void MessageDebounce_SlidePosition(void);
#endif

#ifdef _CONFIG_AntiFalseLock
static void MessageDebounce_AntiFalseLock(void);
#endif

#ifdef _CONFIG_MusicControl
static void MessageDebounce_MusicControl(void);
#endif

#ifdef _CONFIG_FOBMode
static void MessageDebounce_FOBModeA(void);
static void MessageDebounce_FOBModeB(void);
static void MessageDebounce_FOBModeC(void);
#endif

/*MessageTransmitUpdate*/
#ifdef _CHERY_COM 
#ifdef _CHERY_COM_PLG
static void MessageTransmit_PLG_PositionSts(void);
static void MessageTransmit_PLG_Set_MaxPosition(void);
static void MessageTransmit_PLG_LatchSts(void);
static void MessageTransmit_PLG_PinchEvent(void);
static void MessageTransmit_PLG_OperateSts(void);
static void MessageTransmit_PLG_GlobalSW(void);
static void MessageTransmit_PLG_ECUtemp(void);            
static void MessageTransmit_PLG_OperateStsValidData(void);  
static void MessageTransmit_PLG_UnLockInformation(void);
static void MessageTransmit_PLG_OperateInd(void);
static void MessageTransmit_PLG_ECUFailSts(void); 
#ifdef _CONFIG_LIN_Master
static void MessageTransmit_TowHookEnd_position(void);  
static void MessageTransmit_KSEnable(void); 
static void MessageTransmit_TailgatePosition(void); 
static void MessageTransmit_VehicleType(void); 
static void MessageTransmit_TailgateMovementCloseState(void); 
static void MessageTransmit_TailgateMovemntOpenState(void); 
static void MessageTransmit_CatchBoltStatus(void); 
static void MessageTransmit_PawlStatus(void); 
#endif
#endif 
#ifdef _CHERY_COM_PD
static void MessageTransmit_DoorMotionDirection(void);

static void MessageTransmit_DCM_RemoteDiag(void);

#ifdef _CONFIG_LatchSignal_Transmit
static void MessageTransmit_LatchSignal(void);
#endif
#endif
#endif











 
/*********************************************************************************************
** Name:	  PE10ms_MessageDebounce_Master
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
 void PE10ms_MessageDebounce_Master(void)
 {
       //MessageCommand_Update();
       //MessageCondition_Update();
 }


/*********************************************************************************************
** Name:	  MessageCondition_Update
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/

 void MessageCondition_Update(void)
 {     
     #ifdef _CONFIG_VehiclePowerMode
     MessageDebounce_VehiclePowerMode();
     #endif
     #ifdef _CONFIG_VehicleGearLever
     MessageDebounce_VehicleGearLever();
     #endif
     #ifdef _CONFIG_VehicleLock
     MessageDebounce_VehicleLock();
     #endif
     #ifdef _CONFIG_VehicleChildLock
     MessageDebounce_VehicleChildLock();
     #endif
     #ifdef _CONFIG_VehicleAntiTheft
     MessageDebounce_VehicleAntiTheft();
     #endif
     #ifdef _CONFIG_VehicleHandBrake
     MessageDebounce_VehicleHandBrake();
     #endif
     #ifdef _CONFIG_VehicleMode
     MessageDebounce_VehicleMode();
     #endif
     
     #ifdef _CONFIG_VehicleRemoteMode
     MessageDebounce_VehicleRemoteMode();
     #endif

     #ifdef _CONFIG_FOBMode
     MessageDebounce_FOBModeA();
     MessageDebounce_FOBModeB();
     MessageDebounce_FOBModeC();
     #endif

     #ifdef _CONFIG_VehicleDriveMode
     MessageDebounce_VehicleDriveMode();
     #endif
     #ifdef _CONFIG_KeyOpenMode
     MessageDebounce_KeyOpenMode();
     #endif
     #ifdef _CONFIG_KeyCloseMode
     MessageDebounce_KeyCloseMode();
     #endif
     
     #ifdef _CONFIG_AppAuthorize
     MessageDebounce_AppAuthorize();
     #endif
     #ifdef _CONFIG_BLEAuthorize
     MessageDebounce_BLEAuthorize();
     #endif
     #ifdef _CONFIG_FobAuthorize
     MessageDebounce_FobAuthorize();
     #endif
     #ifdef _CONFIG_PKEAuthorize
     MessageDebounce_PKEAuthorize();
     #endif
     #ifdef _CONFIG_AntiLockAuthorize
     MessageDebounce_AntiLockAuthorize();
     #endif

     #ifdef _CONFIG_VehicleSpeed
     MessageDebounce_VehicleSpeed();
     #endif
     #ifdef _CONFIG_VehicleBrake
     MessageDebounce_VehicleBrake();
     #endif
     #ifdef _CONFIG_VehicleCrash
     MessageDebounce_VehicleCrash();
     #endif
     #ifdef _CONFIG_VehicleRain
     MessageDebounce_VehicleRain();
     #endif
     #ifdef _CONFIG_VehicleClean
     MessageDebounce_VehicleClean();
     #endif
     
     
     #ifdef _CONFIG_SonicRadar
     #ifdef _CONFIG_SonicRadar_Error
     MessageDebounce_SonicRadar_Error();
     #endif
     #ifdef _CONFIG_SonicRadar_Obstacle
     MessageDebounce_SonicRadar_Obstacle();
     #endif
     #ifdef _CONFIG_SonicRadar_Angle
     MessageDebounce_SonicRadar_Angle();
     #endif
     #ifdef _CONFIG_SonicRadar1_Distance
     MessageDebounce_SonicRadar1_Distance();
     #endif
     #ifdef _CONFIG_SonicRadar2_Distance
     MessageDebounce_SonicRadar2_Distance();
     #endif
     #ifdef _CONFIG_SonicRadar3_Distance
     MessageDebounce_SonicRadar3_Distance();
     #endif
     #endif
     
     #ifdef _CONFIG_MmwRadar
     #ifdef _CONFIG_MmwRadar_Error
     MessageDebounce_MmwRadar_Error();
     #endif
     #ifdef _CONFIG_MmwRadar_Obstacle
     MessageDebounce_MmwRadar_Obstacle();
     #endif
     #ifdef _CONFIG_MmwRadar_Angle
     MessageDebounce_MmwRadar_Angle();
     #endif
     #ifdef _CONFIG_MmwRadarX_Distance
     MessageDebounce_MmwRadarX_Distance();
     #endif
     #ifdef _CONFIG_MmwRadarY_Distance
     MessageDebounce_MmwRadarY_Distance();
     #endif
     #ifdef _CONFIG_MmwRadarZ_Distance
     MessageDebounce_MmwRadarZ_Distance();
     #endif
     #ifdef _CONFIG_MmwRadarD_Distance
     MessageDebounce_MmwRadarD_Distance();
     #endif
     #endif
     
     
     #ifdef _CONFIG_AdasRadar
     #ifdef _CONFIG_AdasRadar_RearCorner_Error
     MessageDebounce_AdasRadar_RearCorner_Error();
     #endif
     #ifdef _CONFIG_AdasRadar_RearCorner_Obstacle
     MessageDebounce_AdasRadar_RearCorner_Obstacle();
     #endif
     #ifdef _CONFIG_AdasRadar_RearCorner_Angle
     MessageDebounce_AdasRadar_RearCorner_Angle();
     #endif
     
     #ifdef _CONFIG_AdasRadar_RearCorner_Enable
     MessageDebounce_AdasRadar_RearCorner_Enable();
     #endif

     #ifdef _CONFIG_AdasRadar_RearCornerX_Distance
     MessageDebounce_AdasRadar_RearCornerX_Distance();
     #endif
     #ifdef _CONFIG_AdasRadar_RearCornerY_Distance
     MessageDebounce_AdasRadar_RearCornerY_Distance();
     #endif
     #ifdef _CONFIG_AdasRadar_RearCornerZ_Distance
     MessageDebounce_AdasRadar_RearCornerZ_Distance();
     #endif
     #endif

     
     #ifdef _CONFIG_BusIncline
     #ifdef _CONFIG_InclineX_Direction
     MessageDebounce_BusInclineX();
     #endif
     #ifdef _CONFIG_InclineY_Direction
     MessageDebounce_BusInclineY();
     #endif
     #ifdef _CONFIG_InclineZ_Direction
     MessageDebounce_BusInclineZ();
     #endif
     #endif
     
     #ifdef _CONFIG_EngineSpeed
     MessageDebounce_EngineSpeed();
     #endif
     #ifdef _CONFIG_Odometer
     MessageDebounce_Odometer();
     #endif
     #ifdef _CONFIG_TimeInformation
     MessageDebounce_TimeInformation();
     #endif
     #ifdef _CONFIG_VehicleSOC
     MessageDebounce_VehicleSOC();
     #endif
     
     #ifdef _CONFIG_VehicleVoltage
     MessageDebounce_VehicleVoltage();
     #endif
     
     #ifdef _CONFIG_RearWiperStatus
     MessageDebounce_RearWiperStatus();
     #endif
     #ifdef _CONFIG_DoorStatus
     MessageDebounce_DoorStatus();
     #endif
     #ifdef _CONFIG_WindowsPosition
     MessageDebounce_WindowsPosition();
     #endif
     #ifdef _CONFIG_BlowerSpeed
     MessageDebounce_BlowerSpeed();
     #endif
     #ifdef _CONFIG_BusTemperature
     MessageDebounce_BusTemperature();
     #endif
     #ifdef _CONFIG_SunRoofPosition
     MessageDebounce_SunRoofPosition();
     #endif
     
     #ifdef _CONFIG_OpenSpeedLevel
     MessageDebounce_OpenSpeedLevel();
     #endif
     #ifdef _CONFIG_CloseSpeedLevel
     MessageDebounce_CloseSpeedLevel();
     #endif
     
     #ifdef _CONFIG_VehicleChargeState
     MessageDebounce_VehicleChargeState();
     #endif
     
     #ifdef _CONFIG_ModeStatus_NormalMode
     MessageDebounce_NormalMode();
     #endif
     #ifdef _CONFIG_ModeStatus_GarageMode
     MessageDebounce_GarageMode();
     #endif
     #ifdef _CONFIG_ModeStatus_ManualMode
     MessageDebounce_ManualMode();
     #endif 
     
     #ifdef _CONFIG_KickSensorEnable
     MessageDebounce_KickSensorEnable();
     #endif
     #ifdef _CONFIG_FlasherEnable
     MessageDebounce_FlasherEnable();
     #endif
     #ifdef _CONFIG_BuzzerEnable
     MessageDebounce_BuzzerEnable();
     #endif
     #ifdef _CONFIG_AutoOpenEnable
     MessageDebounce_AutoOpenEnable();
     #endif
     #ifdef _CONFIG_ObstcalAlarmEnable
     MessageDebounce_ObstcalAlarmEnable();
     #endif
     
     #ifdef _CONFIG_BLEEnable
     MessageDebounce_BLEEnable();
     #endif
     #ifdef _CONFIG_VoiceEnable
     MessageDebounce_VoiceEnable();
     #endif
     #ifdef _CONFIG_BrakeEnable
     MessageDebounce_BrakeEnable();
     #endif
     #ifdef _CONFIG_RKEEnable
     MessageDebounce_RKEEnable();
     #endif
     
     #ifdef _CONFIG_ManualOperateEnable
     MessageDebounce_ManualOperateEnable();
     #endif
     #ifdef _CONFIG_MotorHoldEnable
     MessageDebounce_MotorHoldEnable();
     #endif
     #ifdef _CONFIG_DoorPowerMode
     MessageDebounce_DoorPowerMode();
     #endif
     
     #ifdef _CONFIG_CinchEnable
     MessageDebounce_CinchEnable();
     #endif
     #ifdef _CONFIG_BeltEnable
     MessageDebounce_BeltEnable();
     #endif
     #ifdef _CONFIG_WindEnable
     MessageDebounce_WindEnable();
     #endif
     #ifdef _CONFIG_SpeedMode
     MessageDebounce_SpeedMode();
     #endif
     
     #ifdef _CONFIG_ConfigurationTrigger
     MessageDebounce_ConfigurationTrigger();
     #endif
     #ifdef _CONFIG_SideDoorOpeningMode
     MessageDebounce_SideDoorOpeningMode();
     #endif
     #ifdef _CONFIG_LeftAndRightRudder
     MessageDebounce_LeftAndRightRudder();
     #endif
     #ifdef _CONFIG_BNCM
     MessageDebounce_BNCM();
     #endif
     
     #ifdef _CONFIG_LatchReleaseState
     MessageDebounce_LatchReleaseState();
     #endif
 }                   


 /*********************************************************************************************
** Name:	  MessageCommand_Update
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/

 void MessageCommand_Update(void)
 {

      
      #ifdef _CONFIG_RemindStart
      MessageDebounce_RemindStart();
      #endif
      #ifdef _CONFIG_RemindStop
      MessageDebounce_RemindStop();
      #endif
      
      #ifdef _CONFIG_AppEnable
      MessageDebounce_AppEnable();
      #endif
      #ifdef _CONFIG_AppReset
      MessageDebounce_AppReset();
      #endif
      
      #ifdef _CONFIG_AppOpen
      MessageDebounce_AppOpen();
      #endif
      #ifdef _CONFIG_AppClose
      MessageDebounce_AppClose();
      #endif
      #ifdef _CONFIG_AppStop
      MessageDebounce_AppStop();
      #endif   
      
      #ifdef _CONFIG_AppButton
      MessageDebounce_AppButton();
      #endif     
      #ifdef _CONFIG_AppDemoMode
      MessageDebounce_AppDemoMode();
      #endif
      
      #ifdef _CONFIG_VROpen
      MessageDebounce_VROpen();
      #endif
      #ifdef _CONFIG_VRClose
      MessageDebounce_VRClose();
      #endif
      #ifdef _CONFIG_VRStop
      MessageDebounce_VRStop();
      #endif    
      #ifdef _CONFIG_VRStopDirectly
      MessageDebounce_VRStopDirectly();
      #endif
      #ifdef _CONFIG_VRSmallOpen
      MessageDebounce_VRSmallOpen();
      #endif
      
      #ifdef _CONFIG_VoiceOpen
      MessageDebounce_VoiceOpen();
      #endif
      #ifdef _CONFIG_VoiceClose
      MessageDebounce_VoiceClose();
      #endif
      #ifdef _CONFIG_VoiceStop
      MessageDebounce_VoiceStop();
      #endif
      
      #ifdef _CONFIG_AppStepOpen
      MessageDebounce_AppStepOpen();
      #endif
      #ifdef _CONFIG_AppStepClose
      MessageDebounce_AppStepClose();
      #endif
      #ifdef _CONFIG_VRStepOpen
      MessageDebounce_VRStepOpen();
      #endif
      #ifdef _CONFIG_VRStepClose
      MessageDebounce_VRStepClose();
      #endif
      
      #ifdef _CONFIG_AutoOpen
      MessageDebounce_AutoOpen();
      #endif
      #ifdef _CONFIG_AutoClose
      MessageDebounce_AutoClose();
      #endif
      #ifdef _CONFIG_AutoStop
      MessageDebounce_AutoStop();
      #endif
      #ifdef _CONFIG_AutoStepOpen
      MessageDebounce_AutoStepOpen();
      #endif
      #ifdef _CONFIG_AutoStepClose
      MessageDebounce_AutoStepClose();
      #endif
      
      #ifdef _CONFIG_BLEOpen
      MessageDebounce_BLEOpen();
      #endif
      #ifdef _CONFIG_BLEClose
      MessageDebounce_BLEClose();
      #endif
      #ifdef _CONFIG_BLEStop
      MessageDebounce_BLEStop();
      #endif
      #ifdef _CONFIG_BLEStepOpen
      MessageDebounce_BLEStepOpen();
      #endif
      #ifdef _CONFIG_BLEStepClose
      MessageDebounce_BLEStepClose();
      #endif
      #ifdef _CONFIG_BLEButton
      MessageDebounce_BLEButton();
      #endif
      
      #ifdef _CONFIG_RKEOpen
      MessageDebounce_RKEOpen();
      #endif
      #ifdef _CONFIG_RKEClose
      MessageDebounce_RKEClose();
      #endif
      #ifdef _CONFIG_RKEStopOpen
      MessageDebounce_RKEStopOpen();
      #endif
      #ifdef _CONFIG_RKEStopClose
      MessageDebounce_RKEStopClose();
      #endif
      #ifdef _CONFIG_RKEStepOpen
      MessageDebounce_RKEStepOpen();
      #endif
      #ifdef _CONFIG_RKEStepClose
      MessageDebounce_RKEStepClose();
      #endif
      
      #ifdef _CONFIG_InsideButton
      MessageDebounce_InsideButton();
      #endif
      #ifdef _CONFIG_DriverButton
      MessageDebounce_DriverButton();
      #endif
      #ifdef _CONFIG_DriverButtonStop
      MessageDebounce_DriverButtonStop();
      #endif
      #ifdef _CONFIG_SeatOccupied
      MessageDebounce_SeatOccupied();
      #endif
      #ifdef _CONFIG_SeatBelt
      MessageDebounce_SeatBelt();
      #endif
      #ifdef _CONFIG_DelayClose
      MessageDebounce_DelayClose();
      #endif
      #ifdef _CONFIG_ManualRelease
      MessageDebounce_ManualRelease();
      #endif
      
      #ifdef _CONFIG_GarageHeightRequest     
      MessageDebounce_GarageHeightRequest();
      #endif
      
      #ifdef _CONFIG_RestoreRequest
      MessageDebounce_RestoreRequest();
      #endif
      
      #ifdef _CONFIG_TargetPositionOpen
      MessageDebounce_TargetPositionOpen();
      #endif
      #ifdef _CONFIG_TargetPositionClose
      MessageDebounce_TargetPositionClose();
      #endif
      
      #ifdef _CONFIG_SlidePosition
      MessageDebounce_SlidePosition();
      #endif

      #ifdef _CONFIG_AntiFalseLock
      MessageDebounce_AntiFalseLock();
      #endif
      
      #ifdef _CONFIG_MusicControl
      MessageDebounce_MusicControl();
      #endif
      
      #ifdef _CONFIG_CommandDelay_Cancel_ByFobLock
      MessageDebounce_FobLock();
      #endif
      
      #ifdef _CONFIG_LatchSignal
      MessageDebounce_LatchSignal();
      #endif

      #ifdef _CONFIG_PawlSignal
      MessageDebounce_PawlSignal();
      #endif     
      #ifdef _CONFIG_SecondarySignal
      MessageDebounce_SecondarySignal();
      #endif
      #ifdef _CONFIG_AjarSignal
      MessageDebounce_AjarSignal();
      #endif
      #ifdef _CONFIG_PositionSignal
      MessageDebounce_PositionSignal();
      #endif
      #ifdef _CONFIG_CentralLockSignal
      MessageDebounce_CentralLockSignal();
      #endif
      #ifdef _CONFIG_ChildLockSignal
      MessageDebounce_ChildLockSignal();
      #endif
 } 
 
/*********************************************************************************************
** Name:	  MessageDebounce_Init(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/ 
 void MessageDebounce_Init(void)
 {
      if((TRUE == Message_AfterPowerUp_Status) || (TRUE == Message_FromReset_Status))
      {
	  Message_AfterPowerUp_Status = FALSE;
	  Message_FromReset_Status = FALSE;
	  
          #ifdef _SGMW_COM	 
          MessageRx_VehiclePowerMode = K_MessageRx_VehiclePowerMode_Default;
	  MessageRx_VehiclePowerMode_Ind = TRUE;
          MessageRx_VehicleGearLever =  K_MessageRx_VehicleGearLever_Default;
	  MessageRx_VehicleGearLever_Ind = TRUE;
          MessageRx_VehicleAntiTheft = K_MessageRx_VehicleAntiTheft_Default; 
	  MessageRx_VehicleAntiTheft_Ind = TRUE;
          MessageRx_VehicleLock = K_MessageRx_VehicleLock_Default;
          MessageRx_VehicleLock_Ind = TRUE;
	  MessageRx_GarageHeight_Value = K_GarageLearned_Position_Default;
	  MessageRx_GarageHeight_Ind = TRUE;
          #endif
	  #ifdef _SGM_COM	 
          MessageRx_VehiclePowerMode = K_MessageRx_VehiclePowerMode_Default;
	  MessageRx_VehiclePowerMode_Ind = TRUE;
          MessageRx_VehicleGearLever =  K_MessageRx_VehicleGearLever_Default;
	  MessageRx_VehicleGearLever_Ind = TRUE;
          MessageRx_VehicleAntiTheft = K_MessageRx_VehicleAntiTheft_Default; 
	  MessageRx_VehicleAntiTheft_Ind = TRUE;
          MessageRx_VehicleLock = K_MessageRx_VehicleLock_Default;
          MessageRx_VehicleLock_Ind = TRUE;
	  MessageRx_GarageHeight_Value = K_GarageLearned_Position_Default;
	  MessageRx_GarageHeight_Ind = TRUE;
          #endif
          
          #ifdef _DEARCC_COM	 
          MessageRx_VehiclePowerMode = K_MessageRx_VehiclePowerMode_Default;
	  MessageRx_VehiclePowerMode_Ind = TRUE;
          MessageRx_VehicleGearLever =  K_MessageRx_VehicleGearLever_Default;
	  MessageRx_VehicleGearLever_Ind = TRUE;
          MessageRx_VehicleAntiTheft = K_MessageRx_VehicleAntiTheft_Default; 
	  MessageRx_VehicleAntiTheft_Ind = TRUE;
          MessageRx_VehicleLock = K_MessageRx_VehicleLock_Default;  
	  MessageRx_VehicleLock_Ind = TRUE;
	  /*MessageRx_GarageHeight_Value = K_GarageLearned_Position_Default;
	  MessageRx_GarageHeight_Ind = TRUE;*/
          #endif
	  #ifdef _XIAOPENG_COM	 
          MessageRx_VehiclePowerMode = K_MessageRx_VehiclePowerMode_Default;
	  MessageRx_VehiclePowerMode_Ind = TRUE;
          MessageRx_VehicleGearLever =  K_MessageRx_VehicleGearLever_Default;
	  MessageRx_VehicleGearLever_Ind = TRUE;
          MessageRx_VehicleAntiTheft = K_MessageRx_VehicleAntiTheft_Default; 
	  MessageRx_VehicleAntiTheft_Ind = TRUE;
          MessageRx_VehicleLock = K_MessageRx_VehicleLock_Default;  
	  MessageRx_VehicleLock_Ind = TRUE;
	  /*MessageRx_GarageHeight_Value = K_GarageLearned_Position_Default;
	  MessageRx_GarageHeight_Ind = TRUE;*/
          #endif
	  
	  #ifdef _CHERY_COM
	     #ifdef _CHERY_COM_PLG
	  MessageRx_VehiclePowerMode = K_MessageRx_VehiclePowerMode_Default;
	  MessageRx_VehiclePowerMode_Ind = TRUE;
          MessageRx_VehicleGearLever =  K_MessageRx_VehicleGearLever_Default;
	  MessageRx_VehicleGearLever_Ind = TRUE;
          MessageRx_VehicleAntiTheft = K_MessageRx_VehicleAntiTheft_Default;
	  MessageRx_VehicleAntiTheft_Ind = TRUE;
          MessageRx_VehicleLock = K_MessageRx_VehicleLock_Default; 
	  MessageRx_VehicleLock_Ind = TRUE;
	  MessageRx_VehicleHandBrake = K_MessageRx_VehicleHandBrake_Default;
	  MessageRx_VehicleHandBrake_Ind = TRUE;	  
	  /*MessageRx_GarageHeight_Value = K_GarageLearned_Position_Default;
	  MessageRx_GarageHeight_Ind = TRUE;*/
	      #endif
	  #endif
	  
	  #ifdef _CTCS_COM
	  MessageRx_VehiclePowerMode = K_MessageRx_VehiclePowerMode_Default;
	  MessageRx_VehiclePowerMode_Ind = TRUE;
          MessageRx_VehicleGearLever =  K_MessageRx_VehicleGearLever_Default;
	  MessageRx_VehicleGearLever_Ind = TRUE;
          MessageRx_VehicleAntiTheft = K_MessageRx_VehicleAntiTheft_Default;  
	  MessageRx_VehicleAntiTheft_Ind = TRUE;
          MessageRx_VehicleLock = K_MessageRx_VehicleLock_Default;
	  MessageRx_VehicleLock_Ind = TRUE;
	  /*MessageRx_GarageHeight_Value = K_GarageLearned_Position_Default;
	  MessageRx_GarageHeight_Ind = TRUE;*/
	  #endif
	  
	  #ifdef _MAXUS_COM
	  MessageRx_VehiclePowerMode = K_MessageRx_VehiclePowerMode_Default;
	  MessageRx_VehiclePowerMode_Ind = TRUE;
          MessageRx_VehicleGearLever =  K_MessageRx_VehicleGearLever_Default;
	  MessageRx_VehicleGearLever_Valid = _TrCrntShftLvrPosV_Valid;
	  MessageRx_VehicleGearLever_Ind = TRUE;
          MessageRx_VehicleAntiTheft = K_MessageRx_VehicleAntiTheft_Default; 
	  MessageRx_VehicleAntiTheft_Ind = TRUE;
          MessageRx_VehicleLock = K_MessageRx_VehicleLock_Default;  
	  MessageRx_VehicleLock_Ind = TRUE;
	  /*MessageRx_GarageHeight_Value = K_GarageLearned_Position_Default;
	  MessageRx_GarageHeight_Ind = TRUE;*/
	  #endif
	  
	  #ifdef _DFMC_COM
	  MessageRx_VehiclePowerMode = K_MessageRx_VehiclePowerMode_Default;
	  MessageRx_VehiclePowerMode_Ind = TRUE;
          MessageRx_VehicleGearLever =  K_MessageRx_VehicleGearLever_Default;
	  MessageRx_VehicleGearLever_Valid = _PDCM_actualGearValid_VALID;
	  MessageRx_VehicleGearLever_Ind = TRUE;
          MessageRx_VehicleAntiTheft = K_MessageRx_VehicleAntiTheft_Default; 
	  MessageRx_VehicleAntiTheft_Ind = TRUE;
          MessageRx_VehicleLock = K_MessageRx_VehicleLock_Default;  
	  MessageRx_VehicleLock_Ind = TRUE;
	  MessageRx_VehicleHandBrake = K_MessageRx_VehicleHandBrake_Default;
	  MessageRx_VehicleHandBrake_Ind = TRUE;
	  MessageRx_VehicleChargeState = K_MessageRx_VehicleChargeState_Default;
	  MessageRx_VehicleChargeState_Ind = TRUE;
	  
	  MessageRx_VehicleSpeed_Valid = _IPB_vehicleSpeedValid_VALID;
	  /*MessageRx_GarageHeight_Value = K_GarageLearned_Position_Default;
	  MessageRx_GarageHeight_Ind = TRUE;*/
	  #endif
	  
	  #ifdef _BAIC_COM
	  MessageRx_VehiclePowerMode = K_MessageRx_VehiclePowerMode_Default;
	  MessageRx_VehiclePowerMode_Ind = TRUE;
          MessageRx_VehicleGearLever =  K_MessageRx_VehicleGearLever_Default;
	  #ifdef _BAIC_COM_C52X
	  MessageRx_VehicleGearLever_Valid == _TcuActGearVld_Valid;
	  #endif
	  #ifdef _BAIC_COM_C62X
	  MessageRx_VehicleGearLever_Valid == _VALID_ACTUAL_GEAR_TCU_Value_OK;
	  #endif
	  MessageRx_VehicleGearLever_Ind = TRUE;
          MessageRx_VehicleAntiTheft = K_MessageRx_VehicleAntiTheft_Default; 
	  MessageRx_VehicleAntiTheft_Ind = TRUE;
          MessageRx_VehicleLock = K_MessageRx_VehicleLock_Default;  
	  MessageRx_VehicleLock_Ind = TRUE;
	  /*MessageRx_GarageHeight_Value = K_GarageLearned_Position_Default;
	  MessageRx_GarageHeight_Ind = TRUE;*/
	  #endif
	  
	  #ifdef _DFLZM_COM
	  MessageRx_VehiclePowerMode = K_MessageRx_VehiclePowerMode_Default;
	  MessageRx_VehiclePowerMode_Ind = TRUE;
          MessageRx_VehicleGearLever =  K_MessageRx_VehicleGearLever_Default;
	  MessageRx_VehicleGearLever_Ind = TRUE;
          MessageRx_VehicleAntiTheft = K_MessageRx_VehicleAntiTheft_Default; 
	  MessageRx_VehicleAntiTheft_Ind = TRUE;
          MessageRx_VehicleLock = K_MessageRx_VehicleLock_Default;  
	  MessageRx_VehicleLock_Ind = TRUE;
	  /*MessageRx_GarageHeight_Value = K_GarageLearned_Position_Default;
	  MessageRx_GarageHeight_Ind = TRUE;*/
	  #endif
	  
	  #ifdef _NIU_COM
	  MessageRx_VehiclePowerMode = K_MessageRx_VehiclePowerMode_Default;
	  MessageRx_VehiclePowerMode_Ind = TRUE;
          MessageRx_VehicleGearLever =  K_MessageRx_VehicleGearLever_Default;
	  MessageRx_VehicleGearLever_Ind = TRUE;
          MessageRx_VehicleAntiTheft = K_MessageRx_VehicleAntiTheft_Default; 
	  MessageRx_VehicleAntiTheft_Ind = TRUE;
          MessageRx_VehicleLock = K_MessageRx_VehicleLock_Default;  
	  MessageRx_VehicleLock_Ind = TRUE;
	  /*MessageRx_GarageHeight_Value = K_GarageLearned_Position_Default;
	  MessageRx_GarageHeight_Ind = TRUE;*/
	  #endif
	  
	  #ifdef _FAW_COM
	  MessageRx_VehiclePowerMode = K_MessageRx_VehiclePowerMode_Default;
	  MessageRx_VehiclePowerMode_Ind = TRUE;
          MessageRx_VehicleGearLever =  K_MessageRx_VehicleGearLever_Default;
	  MessageRx_VehicleGearLever_Ind = TRUE;
          MessageRx_VehicleAntiTheft = K_MessageRx_VehicleAntiTheft_Default; 
	  MessageRx_VehicleAntiTheft_Ind = TRUE;
          MessageRx_VehicleLock = K_MessageRx_VehicleLock_Default;  
	  MessageRx_VehicleLock_Ind = TRUE;
	  /*MessageRx_GarageHeight_Value = K_GarageLearned_Position_Default;
	  MessageRx_GarageHeight_Ind = TRUE;*/
	  #endif
	  
	  #ifdef _CHANGAN_COM
	  MessageRx_VehiclePowerMode = K_MessageRx_VehiclePowerMode_Default;
	  MessageRx_VehiclePowerMode_Ind = TRUE;
          MessageRx_VehicleGearLever =  K_MessageRx_VehicleGearLever_Default;
	  MessageRx_VehicleGearLever_Ind = TRUE;
          MessageRx_VehicleAntiTheft = K_MessageRx_VehicleAntiTheft_Default; 
	  MessageRx_VehicleAntiTheft_Ind = TRUE;
          MessageRx_VehicleLock = K_MessageRx_VehicleLock_Default; 
	  MessageRx_VehicleLock_Ind = TRUE;
	  //MessageRx_GarageHeight_Value = K_GarageLearned_Position_Default;
	  //MessageRx_GarageHeight_Ind = TRUE;
	  #endif
      }  
      else if(TRUE == Message_AfterWakeup_Status)
      {
	  Message_AfterWakeup_Status = FALSE;
	  
          #ifdef _SGMW_COM	 
	  MessageRx_VehiclePowerMode_Ind = TRUE;
	  MessageRx_VehicleGearLever_Ind = TRUE;
	  MessageRx_VehicleAntiTheft_Ind = TRUE;
          MessageRx_VehicleLock_Ind = TRUE;
	  //MessageRx_GarageHeight_Ind = TRUE;
          #endif
	  #ifdef _SGM_COM	 
	  MessageRx_VehiclePowerMode_Ind = TRUE;
	  MessageRx_VehicleGearLever_Ind = TRUE;
	  MessageRx_VehicleAntiTheft_Ind = TRUE;
          MessageRx_VehicleLock_Ind = TRUE;
	  //MessageRx_GarageHeight_Ind = TRUE;
          #endif
          
          #ifdef _DEARCC_COM	 
	  MessageRx_VehiclePowerMode_Ind = TRUE;
	  MessageRx_VehicleGearLever_Ind = TRUE; 
	  MessageRx_VehicleAntiTheft_Ind = TRUE;  
	  MessageRx_VehicleLock_Ind = TRUE;
	  //MessageRx_GarageHeight_Ind = TRUE;
          #endif
	  #ifdef _XIAOPENG_COM	 
	  MessageRx_VehiclePowerMode_Ind = FALSE;//TRUE;
	  MessageRx_VehicleGearLever_Ind = TRUE; 
	  MessageRx_VehicleAntiTheft_Ind = TRUE;  
	  MessageRx_VehicleLock_Ind = TRUE;
	  //MessageRx_GarageHeight_Ind = TRUE;
          #endif
	  
	  #ifdef _CHERY_COM
	      #ifdef _CHERY_COM_PLG
	  #ifdef _CONFIG_CAN_Bus
	  MessageRx_VehiclePowerMode_Ind = TRUE;
	  MessageRx_VehicleGearLever_Ind = TRUE;
	  MessageRx_VehicleAntiTheft_Ind = TRUE; 
	  MessageRx_VehicleLock_Ind = TRUE;
	  MessageRx_VehicleHandBrake_Ind = TRUE;
	  //MessageRx_GarageHeight_Ind = TRUE;
	  #endif
	  #ifdef _CONFIG_LIN_Slave
	  MessageRx_VehiclePowerMode_Ind = TRUE;
	  MessageRx_VehicleGearLever_Ind = TRUE;
	  MessageRx_VehicleAntiTheft_Ind = TRUE; 
	  MessageRx_VehicleLock_Ind = TRUE; 
	  //MessageRx_GarageHeight_Ind = TRUE;
	  #endif
	      #endif
	  #endif
	  
	  #ifdef _CTCS_COM
	  //MessageRx_VehiclePowerMode_Ind = TRUE;
	  MessageRx_VehicleGearLever_Ind = TRUE;  
	  //MessageRx_VehicleAntiTheft_Ind = TRUE;
	  //MessageRx_VehicleLock_Ind = TRUE;
	  //MessageRx_GarageHeight_Ind = TRUE;
	  #endif
	  
	  #ifdef _MAXUS_COM
	  MessageRx_VehiclePowerMode_Ind = TRUE;
	  MessageRx_VehicleGearLever_Ind = TRUE;
	  MessageRx_VehicleAntiTheft_Ind = TRUE; 
	  MessageRx_VehicleLock_Ind = TRUE;
	  //MessageRx_GarageHeight_Ind = TRUE;
	  #endif
	  
	  #ifdef _DFMC_COM
	  MessageRx_VehiclePowerMode_Ind = TRUE;
	  MessageRx_VehicleGearLever_Ind = TRUE;
	  MessageRx_VehicleAntiTheft_Ind = TRUE; 
	  MessageRx_VehicleLock_Ind = TRUE;
	  //MessageRx_GarageHeight_Ind = TRUE;
	  #endif
	  
	  #ifdef _BAIC_COM
	  MessageRx_VehiclePowerMode_Ind = TRUE;
	  MessageRx_VehicleGearLever_Ind = TRUE;
	  MessageRx_VehicleAntiTheft_Ind = TRUE; 
	  MessageRx_VehicleLock_Ind = TRUE;
	  //MessageRx_GarageHeight_Ind = TRUE;
	  #endif
	  
	  #ifdef _DFLZM_COM
	  MessageRx_VehiclePowerMode_Ind = TRUE;
	  MessageRx_VehicleGearLever_Ind = TRUE;
	  MessageRx_VehicleAntiTheft_Ind = TRUE; 
	  MessageRx_VehicleLock_Ind = TRUE;
	  //MessageRx_GarageHeight_Ind = TRUE;
	  #endif
	  
	  #ifdef _NIU_COM
	  MessageRx_VehiclePowerMode_Ind = TRUE;
	  MessageRx_VehicleGearLever_Ind = TRUE;
	  MessageRx_VehicleAntiTheft_Ind = TRUE; 
	  MessageRx_VehicleLock_Ind = TRUE;
	  //MessageRx_GarageHeight_Ind = TRUE;
	  #endif
	  
	  #ifdef _FAW_COM
	  MessageRx_VehiclePowerMode_Ind = TRUE;
	  MessageRx_VehicleGearLever_Ind = TRUE;
	  MessageRx_VehicleAntiTheft_Ind = TRUE; 
	  MessageRx_VehicleLock_Ind = TRUE;
	  //MessageRx_GarageHeight_Ind = TRUE;
	  #endif
	  
	  #ifdef _CHANGAN_COM
	  MessageRx_VehiclePowerMode_Ind = TRUE;
	  MessageRx_VehicleGearLever_Ind = TRUE;
	  MessageRx_VehicleAntiTheft_Ind = TRUE;
	  MessageRx_VehicleLock_Ind = TRUE;
	  //MessageRx_GarageHeight_Ind = TRUE;
	  #endif
      }
 }

 
#ifdef _AUDI_COM
#ifdef _AUDI_COM_PLG
#endif   

#ifdef _AUDI_COM_PD
/* CAN_Bus*/

/*********************************************************************************************
** Name:	  MessageTransmit_SDD_DoorPos(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_SDD_DoorPos(void)
{
      MessageTx_SDD_DoorPos = (CurrentPosition_Angle * 100); 
}
/*********************************************************************************************
** Name:	  MessageTransmit_SDD_DoorAngSpd(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_SDD_DoorAngSpd(void)
{
}
/*********************************************************************************************
** Name:	  MessageTransmit_SDD_ReqREDSMode(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_SDD_ReqREDSMode(void)
{
      static uint8_t MessageTx_SDD_ReqREDSMode_Status;
      static uint16_t MessageTx_SDD_ReqREDSMode_Timer;

      #define K_MessageTx_SDD_ReqREDSMode_Sleep_Timeout  90
      #define K_MessageTx_SDD_ReqREDSMode_Standy_Timeout 70
      #define K_MessageTx_SDD_ReqREDSMode_Fast_Timeout   50
 
      if(TRUE == MmwRadar_Detect_Status)
      {
            MessageTx_SDD_ReqREDSMode = SDD_ReqREDSMode_FAST_MEASUREMENT;
            Com_TxStart();
      }
      else    
      {
            if(TRUE == MmwRadar_Detect_RiseEdge_Active)
            {
                  MessageTx_SDD_ReqREDSMode_Status = TRUE;
                  MessageTx_SDD_ReqREDSMode_Timer = 0;
            }
	    
            if(TRUE == MessageTx_SDD_ReqREDSMode_Status)
            {
		   MessageTx_SDD_ReqREDSMode_Timer ++; 
		  
		  if(MessageTx_SDD_ReqREDSMode_Timer > K_MessageTx_SDD_ReqREDSMode_Sleep_Timeout)
		  {	
                        MessageTx_SDD_ReqREDSMode_Status = FALSE;
			Com_TxStop();
		  }
		  else if(MessageTx_SDD_ReqREDSMode_Timer > K_MessageTx_SDD_ReqREDSMode_Fast_Timeout)
		  {
			MessageTx_SDD_ReqREDSMode = SDD_ReqREDSMode_STANDBY;
		  }
		  else if(MessageTx_SDD_ReqREDSMode_Timer > K_MessageTx_SDD_ReqREDSMode_Standy_Timeout)
		  {
			MessageTx_SDD_ReqREDSMode = SDD_ReqREDSMode_SLEEP;
		  } 
	    }
      }
}
/*********************************************************************************************
** Name:	  MessageTransmit_SDD_DoorMovement(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_SDD_DoorMovement(void)
{
}
/*********************************************************************************************
** Name:	  MessageTransmit_SDD_DoorAddress(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_SDD_DoorAddress(void)
{
}
/*********************************************************************************************
** Name:	  MessageTransmit_SDD_VehSpeed(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_SDD_VehSpeed(void)
{
}
/*********************************************************************************************
** Name:	  MessageTransmit_SDD_VehPitchAngle(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_SDD_VehPitchAngle(void)
{
}
/*********************************************************************************************
** Name:	  MessageTransmit_SDD_VehRollAngle(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_SDD_VehRollAngle(void)
{
}

/*LIN_Slave*/
/*********************************************************************************************
** Name:	  MessageTransmit_DduStatus_DoorPos(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_DduStatus_DoorPos(void)
{
     MessageTx_DduStatus_DoorPos = (CurrentPosition_Percent * 2);
     
}
/*********************************************************************************************
** Name:	  MessageTransmit_DduStatus_StopNotif(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_DduStatus_StopNotif(void)
{
     static uint16_t MessageTx_DduStatus_StopNotif_Timer;
     #define K_MessageTx_DduStatus_StopNotif_Timeout 500
/*      
#define DduStatus_StopNotif_NoStop             0U             
#define DduStatus_StopNotif_StopCmd            1U         
#define DduStatus_StopNotif_FuncReleaseOff     2U  
#define DduStatus_StopNotif_MotionProhibited   3U  
#define DduStatus_StopNotif_VehSpeedAboveLim   4U  
#define DduStatus_StopNotif_Crash              5U
#define DduStatus_StopNotif_ChildLock          6U      
#define DduStatus_StopNotif_LatchLocked        7U      
#define DduStatus_StopNotif_PosRangeMismatch   8U   
#define DduStatus_StopNotif_CrankTimeout       9U  
#define DduStatus_StopNotif_UserInteraction    10U  */ 

      if(TRUE == MmwRadar_RequestStop_Command_Active)
      {
	    MessageTx_DduStatus_StopNotif = DduStatus_StopNotif_AntiCollision;
      }
/*
#define DduStatus_StopNotif_AntiTrap           12U 
#define DduStatus_StopNotif_ThermoProt         13U      
#define DduStatus_StopNotif_DoorMotStall       14U   
#define DduStatus_StopNotif_DoorMotTimeout     15U  
#define DduStatus_StopNotif_PosSensorFault     16U 
#define DduStatus_StopNotif_DoorMotHallFault   17U   
#define DduStatus_StopNotif_DoorMotFault       18U   
#define DduStatus_StopNotif_LatchFault         19U 
#define DduStatus_StopNotif_LatchNotReached    20U 
#define DduStatus_StopNotif_DenormPosInvalid   21U     
#define DduStatus_StopNotif_BusFault           22U  
#define DduStatus_StopNotif_FuncDisabled       23U 
#define DduStatus_StopNotif_ParamSetInvalid    24U
#define DduStatus_StopNotif_MemFault           25U  
#define DduStatus_StopNotif_TargetPosReached   26U 
#define DduStatus_StopNotif_TargetPosInvalid   27U  
#define DduStatus_StopNotif_DiagMode           28U 
#define DduStatus_StopNotif_RadarFault         29U
#define DduStatus_StopNotif_VehSpeedUnknown    30U
#define DduStatus_StopNotif_VehInclUnknown     31U
#define DduStatus_StopNotif_AmbTempUnknown     32U
#define DduStatus_StopNotif_LatchOpenFault     33U
#define DduStatus_StopNotif_EolDataInvalid     34U
#define DduStatus_StopNotif_DenormLatchFault   35U
#define DduStatus_StopNotif_DenormSensorVoltageRange   36U
#define DduStatus_StopNotif_DenormSensorDir            37U
#define DduStatus_StopNotif_DenormHallSbcSupply        38U
#define DduStatus_StopNotif_DenormFctCall              39U
#define DduStatus_StopNotif_DenormPowerLoss            40U
#define DduStatus_StopNotif_DenormClutchSlip           41U
#define DduStatus_StopNotif_DenormZoneInvalid          42U
#define DduStatus_AppRejectedCommand                   43U
#define DduStatus_DenormHallRangeFault                 44U
#define DduStatus_Unknown                              45U*/

     
      if(((ActiveSystemMode == SystemPowerOpening) && (LastSystemMode != SystemPowerOpening))
         ||((ActiveSystemMode == SystemReleaseToPowerOpen) && (LastSystemMode != SystemReleaseToPowerOpen))
         ||((ActiveSystemMode == SystemPowerClosing) && (LastSystemMode != SystemPowerClosing)))
      {
	    MessageTx_DduStatus_StopNotif = DduStatus_StopNotif_NoStop;
	    MessageTx_DduStatus_StopNotif_Timer = 0;
      }
      
      if(MessageTx_DduStatus_StopNotif != DduStatus_StopNotif_NoStop)
      {
	    if(MessageTx_DduStatus_StopNotif_Timer >= K_MessageTx_DduStatus_StopNotif_Timeout)
	    {
		  MessageTx_DduStatus_StopNotif = DduStatus_StopNotif_NoStop;		  
	          MessageTx_DduStatus_StopNotif_Timer = 0;
	    }
	    else
	    {
		  MessageTx_DduStatus_StopNotif_Timer ++;
	    }
      }

}
/*********************************************************************************************
** Name:	  MessageTransmit_DduStatus_DriveCurrent(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_DduStatus_DriveCurrent(void)
{
}
/*********************************************************************************************
** Name:	  MessageTransmit_DduStatus_DriveSpeed(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_DduStatus_DriveSpeed(void)
{
}
/*********************************************************************************************
** Name:	  MessageTransmit_DduStatus_DoorState(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_DduStatus_DoorState(void)
{
      if((ActiveSystemMode == SystemOpenedFully) 
         || (ActiveSystemMode == SystemReleased) 
         || (ActiveSystemMode == SystemMechFailure))
      {
            if(ActiveManualOperateMode == ManualOperateOpening)
            {
                   MessageTx_DduStatus_DoorState = DduStatus_DoorState_ManOpen;
            }
            else if(ActiveManualOperateMode == ManualOperateClosing)
            { 
                   MessageTx_DduStatus_DoorState = DduStatus_DoorState_ManClose;
            }
            else
            {
		   if((ActiveMotorHoldMode == MotorHoldOpening) || (ActiveMotorHoldMode == MotorHoldClosing))
		   {
			 MessageTx_DduStatus_DoorState = DduStatus_DoorState_HoldEl; 
		   }
		   else if(ActiveMotorHoldMode == MotorHoldReleased)
		   {
                         MessageTx_DduStatus_DoorState = DduStatus_DoorState_HoldMech; 
		   }
            }
     }
     else if(ActiveSystemMode == SystemClosedFully)
     {
            MessageTx_DduStatus_DoorState = DduStatus_DoorState_Closed;
     }
     else if(SystemReleaseToPowerOpen)
     {
	    MessageTx_DduStatus_DoorState = DduStatus_DoorState_ElecOpen;
     }
     else if(ActiveSystemMode == SystemPowerOpening)
     {
            MessageTx_DduStatus_DoorState = DduStatus_DoorState_ElecOpen;
     }
     else if(ActiveSystemMode == SystemPowerClosing)
     {
            MessageTx_DduStatus_DoorState = DduStatus_DoorState_ElecClose;
     }

     //#define DduStatus_DoorState_Reversing  0x05U
     //#define DduStatus_DoorState_Diag       0x09U
     //DduStatus_DoorState_PrepMovent
}
/*********************************************************************************************
** Name:	  MessageTransmit_DduStatus_ObwRequest(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_DduStatus_ObwRequest(void)
{
      static uint16_t MessageTx_DduStatus_ObwRequest_Timer;
      static uint8_t MessageTx_DduStatus_ObwRequest_Status;
      
      #define K_MessageTx_DduStatus_ObwRequest_Time 30
 
      /*if(TRUE == MmwRadar_Detect_FallEdge_Active)
      {
	    MessageTx_DduStatus_ObwRequest_Status = TRUE;
	    MessageTx_DduStatus_ObwRequest_Timer = 0;
      }*/
      
      if(((ActiveLatchMode == LatchPowerReleasing) && (LastLatchMode == LatchFullyCinched))
         ||((ActiveLatchMode == LatchPowerReleasing) && (LastLatchMode == LatchMechFailure))
	 ||((ActiveLatchMode == LatchPowerReleasing) && (LastLatchMode == LatchPreReleasing)))
      {
	    MessageTx_DduStatus_ObwRequest = TRUE;
	    
	    MessageTx_DduStatus_ObwRequest_Status = TRUE;
	    MessageTx_DduStatus_ObwRequest_Timer = 0;
      }

      if(TRUE == MessageTx_DduStatus_ObwRequest_Status)
      {
	    if(MessageTx_DduStatus_ObwRequest_Timer >= K_MessageTx_DduStatus_ObwRequest_Time)
	    {
		  MessageTx_DduStatus_ObwRequest = FALSE;
		  
		  MessageTx_DduStatus_ObwRequest_Status = FALSE;
	          MessageTx_DduStatus_ObwRequest_Timer = 0;
	    }
	    else
	    {
		  MessageTx_DduStatus_ObwRequest_Timer ++;
	    }
      }
      
      
}
/*********************************************************************************************
** Name:	  MessageTransmit_DduStatus_OperationState(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_DduStatus_OperationState(void)
{
      MessageTx_DduStatus_OperationState = DduStatus_OperationState_NORMAL;
/*   
#define DduStatus_OperationState_NORMAL                           0x00U
#define DduStatus_OperationState_DERATED_VOLTAGE                  0x01U
#define DduStatus_OperationState_DERATED_TEMPERATURE              0x02U
#define DduStatus_OperationState_DERATED_INCLINATION              0x03U
#define DduStatus_OperationState_VEHICLE_DRIVING                  0x04U
#define DduStatus_OperationState_PROHIBITED_VOLTAGE               0x05U
#define DduStatus_OperationState_PROHIBITED_TEMPERATURE           0x06U
#define DduStatus_OperationState_PROHIBITED_INCLINATION           0x07U
#define DduStatus_OperationState_PROHIBITED_SEVERAL_DERATED_COND  0x08U*/

}
/*********************************************************************************************
** Name:	  MessageTransmit_DduStatus_HardHoldFuncState(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_DduStatus_HardHoldFuncState(void)
{
      MessageTx_DduStatus_HardHoldFuncState = DduStatus_HardHoldFuncState_enabled;
/*     
#define DduStatus_HardHoldFuncState_inactive           0x00U
#define DduStatus_HardHoldFuncState_enabled            0x01U
#define DduStatus_HardHoldFuncState_active             0x02U*/
}
/*********************************************************************************************
** Name:	  MessageTransmit_DduStatus_EmergCloseFuncState(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_DduStatus_EmergCloseFuncState(void)
{
/*	
#define DduStatus_EmergCloseFuncState_inactive           0x00U
#define DduStatus_EmergCloseFuncState_prep_movement      0x01U
#define DduStatus_EmergCloseFuncState_movement_ongoing   0x02U*/
}
/*********************************************************************************************
** Name:	  MessageTransmit_DduStatus_PosRange(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_DduStatus_PosRange(void)
{
     if(CurrentPosition_Percent == 0)
     {
            MessageTx_DduStatus_PosRange = DduStatus_PosRange_Closed;
     }
     else if(CurrentPosition_Percent < 5)
     {
            MessageTx_DduStatus_PosRange = DduStatus_PosRange_OpenOnly;
     }
     else if(CurrentPosition_Percent < 90)
     {
            MessageTx_DduStatus_PosRange = DduStatus_PosRange_Intermediate;
     }
     else if(CurrentPosition_Percent < 95)
     {
            MessageTx_DduStatus_PosRange = DduStatus_PosRange_CloseOnly;
     }
     else
     {
            MessageTx_DduStatus_PosRange = DduStatus_PosRange_FullOpen;
     }
}
/*********************************************************************************************
** Name:	  MessageTransmit_DduStatus_LatchState(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_DduStatus_LatchState(void)
{
      if((FALSE == PawlSwitch_Status) && (FALSE == SecondarySwitch_Status))
      {
             MessageTx_DduStatus_LatchState = DduStatus_LatchState_Closed;
      }
      else if((TRUE == PawlSwitch_Status) && (FALSE == SecondarySwitch_Status))
      {
	     MessageTx_DduStatus_LatchState = DduStatus_LatchState_HalfClosed;
      }
      else if((TRUE == PawlSwitch_Status) && (TRUE == SecondarySwitch_Status))
      {
	     MessageTx_DduStatus_LatchState = DduStatus_LatchState_Open;
      }
      else
      {
             MessageTx_DduStatus_LatchState = DduStatus_LatchState_Unknown;
      }
}
/*********************************************************************************************
** Name:	  MessageTransmit_DduStatus_ServoDisReason(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_DduStatus_ServoDisReason(void)
{
}
/*********************************************************************************************
** Name:	  MessageTransmit_DtcStat_ResponseError(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_DtcStat_ResponseError(void)
{
}
/*********************************************************************************************
** Name:	  MessageTransmit_DtcStat_Normalization(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_DtcStat_Normalization(void)
{
}
/*********************************************************************************************
** Name:	  MessageTransmit_DtcStat_ThermoProtWarn(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_DtcStat_ThermoProtWarn(void)
{
}
/*********************************************************************************************
** Name:	  MessageTransmit_DtcStat_ThermoProtHot(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_DtcStat_ThermoProtHot(void)
{
}
/*********************************************************************************************
** Name:	  MessageTransmit_DtcStat_VoltageErrOV(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_DtcStat_VoltageErrOV(void)
{
}
/*********************************************************************************************
** Name:	  MessageTransmit_DtcStat_VoltageErrUV(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_DtcStat_VoltageErrUV(void)
{
}
/*********************************************************************************************
** Name:	  MessageTransmit_DtcStat_HallErr(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_DtcStat_HallErr(void)
{
}
/*********************************************************************************************
** Name:	  MessageTransmit_DtcStat_LatchErr(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_DtcStat_LatchErr(void)
{
}
/*********************************************************************************************
** Name:	  MessageTransmit_DtcStat_SensorFault(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_DtcStat_SensorFault(void)
{
}
/*********************************************************************************************
** Name:	  MessageTransmit_DtcStat_CurrMeasFault(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_DtcStat_CurrMeasFault(void)
{
}
/*********************************************************************************************
** Name:	  MessageTransmit_DtcStat_DoorMotFaultOC(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_DtcStat_DoorMotFaultOC(void)
{
}
/*********************************************************************************************
** Name:	  MessageTransmit_DtcStat_DoorMotFaultOL(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_DtcStat_DoorMotFaultOL(void)
{
}
/*********************************************************************************************
** Name:	  MessageTransmit_DtcStat_DoorMotFaultSC(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_DtcStat_DoorMotFaultSC(void)
{
}
/*********************************************************************************************
** Name:	  MessageTransmit_DtcStat_WrongDirErr(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_DtcStat_WrongDirErr(void)
{
}
/*********************************************************************************************
** Name:	  MessageTransmit_DtcStat_ParaFault(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_DtcStat_ParaFault(void)
{
}
/*********************************************************************************************
** Name:	  MessageTransmit_DtcStat_ParaMismatch(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_DtcStat_ParaMismatch(void)
{
}
/*********************************************************************************************
** Name:	  MessageTransmit_DtcStat_MemErr(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_DtcStat_MemErr(void)
{
}
/*********************************************************************************************
** Name:	  MessageTransmit_DtcStat_RadarCommErr(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_DtcStat_RadarCommErr(void)
{
}
/*********************************************************************************************
** Name:	  MessageTransmit_RedsStat_FaultOvervoltage(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_RedsStat_FaultOvervoltage(void)
{
}
/*********************************************************************************************
** Name:	  MessageTransmit_RedsStat_FaultUndervoltage(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_RedsStat_FaultUndervoltage(void)
{
}
/*********************************************************************************************
** Name:	  MessageTransmit_RedsStat_FaultRamFault(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_RedsStat_FaultRamFault(void)
{
}
/*********************************************************************************************
** Name:	  MessageTransmit_RedsStat_FaultOvertemp(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_RedsStat_FaultOvertemp(void)
{
}
/*********************************************************************************************
** Name:	  MessageTransmit_RedsStat_FaultCalibData(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_RedsStat_FaultCalibData(void)
{
}
/*********************************************************************************************
** Name:	  MessageTransmit_RedsStat_FaultFunctionDegrad(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_RedsStat_FaultFunctionDegrad(void)
{
}
/*********************************************************************************************
** Name:	  MessageTransmit_RedsStat_StopAngle(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_RedsStat_StopAngle(void)
{
     if(TRUE == MmwRadar_Angle_Real_Status)
     {
           MessageTx_RedsStat_StopAngle = MessageRx_MmwRadar_Angle;
     }
     else
     {
	   MessageTx_RedsStat_StopAngle = K_MmwRadar_Angle_Max_Default;
     }
}
/*********************************************************************************************
** Name:	  MessageTransmit_RedsStat_ActFuncMode(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_RedsStat_ActFuncMode(void)
{
}
/*********************************************************************************************
** Name:	  MessageTransmit_RedsStat_SysState(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_RedsStat_SysState(void)
{  
      if(TRUE == MmwRadar_Error_Real_Status)
      {
            MessageTx_RedsStat_SysState = MessageRx_MmwRadar_Error;
      }
      else
      {
	    MessageTx_RedsStat_SysState = 0;
      }
}
/*********************************************************************************************
** Name:	  MessageTransmit_Reds_ObjectPosX(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_Reds_ObjectPosX(void)
{
}
/*********************************************************************************************
** Name:	  MessageTransmit_Reds_ObjectPosY(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_Reds_ObjectPosY(void)
{
}
/*********************************************************************************************
** Name:	  MessageTransmit_Reds_ObjectPosZ(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_Reds_ObjectPosZ(void)
{
}
/*********************************************************************************************
** Name:	  MessageTransmit_Reds_ObjectDoorDstnc(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_Reds_ObjectDoorDstnc(void)
{
}
/*********************************************************************************************
** Name:	  MessageTransmit_InclInfoFromSDDtoGW_RollAngleValidF(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_InclInfoFromSDDtoGW_RollAngleValidF(void)
{
}
/*********************************************************************************************
** Name:	  MessageTransmit_InclInfoFromSDDtoGW_RollAngle(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_InclInfoFromSDDtoGW_RollAngle(void)
{
      MessageTx_InclInfoFromSDDtoGW_RollAngle = (InclineY_Degree- 500);
}
/*********************************************************************************************
** Name:	  MessageTransmit_InclInfoFromSDDtoGW_PitchAngleValidF(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_InclInfoFromSDDtoGW_PitchAngleValidF(void)
{
}
/*********************************************************************************************
** Name:	  MessageTransmit_InclInfoFromSDDtoGW_PitchAngle(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_InclInfoFromSDDtoGW_PitchAngle(void)
{
      MessageTx_InclInfoFromSDDtoGW_PitchAngle = (InclineX_Degree- 500);
}
#endif
#endif



#ifdef _VOYAH_COM
#ifdef _VOYAH_COM_PD
/*********************************************************************************************
** Name:	  MessageTransmit_POD_DoorReleaseLatch(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_POD_DoorReleaseLatch(void)
{
      static uint16_t MessageTx_POD_DoorReleaseLatch_Timer;
      static uint8_t MessageTx_POD_DoorReleaseLatch_Status;
      
      #define K_MessageTx_POD_DoorReleaseLatch_Time 30
      #define K_LatchPowerReleasing_ObstacleInClosingStop_Position 10

      if(TRUE ==LatchPowerReleasing_CPIDLearnPowerOpen_Request)
      {
	    LatchPowerReleasing_CPIDLearnPowerOpen_Request = FALSE;
	    
	    MessageTx_POD_DoorReleaseLatch = _POD_DoorReleaseLatch_Request;	    
	    MessageTx_POD_DoorReleaseLatch_Status = TRUE;
	    MessageTx_POD_DoorReleaseLatch_Timer = 0;
      }
      else if(TRUE == LatchPowerReleasing_DuringCinchToPowerOpen_Request)
      {
	    LatchPowerReleasing_DuringCinchToPowerOpen_Request = FALSE;
	    
	    MessageTx_POD_DoorReleaseLatch = _POD_DoorReleaseLatch_Request;	    
	    MessageTx_POD_DoorReleaseLatch_Status = TRUE;
	    MessageTx_POD_DoorReleaseLatch_Timer = 0;
      }
      else if(TRUE == LatchPowerReleasing_ObstacleInClosingStop_Request)
      {
	    LatchPowerReleasing_ObstacleInClosingStop_Request = FALSE;
	    if(StartFromHalfLatch_Position <= K_LatchPowerReleasing_ObstacleInClosingStop_Position)
	    {    
	          MessageTx_POD_DoorReleaseLatch = _POD_DoorReleaseLatch_Request;	    
	          MessageTx_POD_DoorReleaseLatch_Status = TRUE;
	          MessageTx_POD_DoorReleaseLatch_Timer = 0;
	    }
      }
      
      if(TRUE == MessageTx_POD_DoorReleaseLatch_Status)
      {
	    if(MessageTx_POD_DoorReleaseLatch_Timer >= K_MessageTx_POD_DoorReleaseLatch_Time)
	    {
		  MessageTx_POD_DoorReleaseLatch = _POD_DoorReleaseLatch_No_Request;
		  
		  MessageTx_POD_DoorReleaseLatch_Status = FALSE;
	          MessageTx_POD_DoorReleaseLatch_Timer = 0;
	    }
	    else
	    {
		  MessageTx_POD_DoorReleaseLatch_Timer ++;
	    }
      }

}
/*********************************************************************************************
** Name:	  MessageTransmit_POD_DoorFLSts(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_POD_DoorFLSts(void)
{
      if(ActiveSystemMode == SystemOpenedFully)
      {
	   MessageTx_POD_DoorSts = _POD_DoorSts_Fully_opened;
      }
      else if(ActiveSystemMode == SystemClosedFully)
      {
	   MessageTx_POD_DoorSts = _POD_DoorSts_Fully_closed;
      }
      else if(ActiveSystemMode == SystemPowerOpening)
      {
	   MessageTx_POD_DoorSts = _POD_DoorSts_Opening;
      }
      else if(ActiveSystemMode == SystemPowerClosing)
      {
	   MessageTx_POD_DoorSts = _POD_DoorSts_Closing;
      }
      else if((ActiveSystemMode == SystemReleased))
      {
	   MessageTx_POD_DoorSts = _POD_DoorSts_POD_stopped;
      }    
      else if((ActiveSystemMode == SystemReleaseToPowerOpen)) //(ActiveSystemMode == SystemReleaseOnly)
      {
	   /*if(TRUE == Motor1_Working_Status)
	   {
	        MessageTx_POD_DoorSts = _POD_DoorSts_Opening;
	   }
	   else
	   {    
		if((FALSE == PawlSwitch_Status) && (FALSE == SecondarySwitch_Status))
		{
		      MessageTx_POD_DoorSts = _POD_DoorSts_Fully_closed;
		}
		else
	        {
                      MessageTx_POD_DoorSts = _POD_DoorSts_POD_stopped;
		}
	   }*/
	   
	   MessageTx_POD_DoorSts = _POD_DoorSts_Latch_releasing;
      }
      else if((ActiveSystemMode == SystemPowerCinching) || (ActiveSystemMode == SystemPowerParking)
             ||(ActiveSystemMode == SystemManualCinching) || (ActiveSystemMode == SystemManualParking))
      {
	   /*if(TRUE == Motor1_Working_Status)
	   {
	         MessageTx_POD_DoorSts = _POD_DoorSts_Closing;
	   }
	   else
	   {
		 MessageTx_POD_DoorSts = _POD_DoorSts_POD_stopped;
	   }*/
	   
	   MessageTx_POD_DoorSts = _POD_DoorSts_Latch_cinching;
	   
      }
      else if(ActiveSystemMode == SystemMechFailure)
      {
	   MessageTx_POD_DoorSts = _POD_DoorSts_POD_stopped;
      } 
      else if(ActiveSystemMode == SystemInitDefault)
      {
	   MessageTx_POD_DoorSts = _POD_DoorSts_POD_stopped;
      }
      else
      {
	   MessageTx_POD_DoorSts = _POD_DoorSts_POD_stopped;
      }
}
/*********************************************************************************************
** Name:	  MessageTransmit_POD_DoorAssistantSts(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_POD_DoorAssistantSts(void)
{
      if((ActiveSystemMode == SystemOpenedFully) 
         || (ActiveSystemMode == SystemReleased) 
         || (ActiveSystemMode == SystemMechFailure))
      {
	
	    if(ActiveManualOperateMode == ManualOperateOpening)
            {
                   MessageTx_POD_DoorAssistantSts = _POD_DoorAssistantSts_Open;
            }
            else if(ActiveManualOperateMode == ManualOperateClosing)
            { 
                   MessageTx_POD_DoorAssistantSts = _POD_DoorAssistantSts_Close;
            }
	    else
	    {
		   MessageTx_POD_DoorAssistantSts = _POD_DoorAssistantSts_NoInput;
	    }
      }
      else
      {
	     MessageTx_POD_DoorAssistantSts = _POD_DoorAssistantSts_NoInput;
      }
}
/*********************************************************************************************
** Name:	  MessageTransmit_POD_ElectricDoorCtlSts(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_POD_ElectricDoorCtlSts(void)
{
	if(CinchEnable_Status ==_Function_Enable)
	{
	       MessageTx_POD_ElectricDoorCtlSts = _POD_ElectricDoorCtlSts_ON;
	}
	else if(CinchEnable_Status ==_Function_Disable)
	{
	       MessageTx_POD_ElectricDoorCtlSts = _POD_ElectricDoorCtlSts_OFF;
	}
	else
	{
	       MessageTx_POD_ElectricDoorCtlSts = _POD_ElectricDoorCtlSts_Default;
	}
}
/*********************************************************************************************
** Name:	  MessageTransmit_POD_DoorOpenSpdSts(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_POD_DoorOpenSpdSts(void)
{
	if(SpeedMode_Status == _SpeedMode_Normal)
	{
	       MessageTx_POD_DoorOpenSpdSts = _POD_DoorOpenSpdSts_normal;
	}
	else if(SpeedMode_Status == _SpeedMode_Fast)
	{
	       MessageTx_POD_DoorOpenSpdSts = _POD_DoorOpenSpdSts_fast;
	}
	else
	{
	       MessageTx_POD_DoorOpenSpdSts = _POD_DoorOpenSpdSts_Default;
	}
}
/*********************************************************************************************
** Name:	  MessageTransmit_POD_PowerDoorAntiWindSts(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_POD_PowerDoorAntiWindSts(void)
{	
	if(WindEnable_Status == _Function_Enable)
	{
	       MessageTx_POD_PowerDoorAntiWindSts = _POD_PowerDoorAntiWindSts_ON;
	}
	else if(WindEnable_Status == _Function_Disable)
	{
	       MessageTx_POD_PowerDoorAntiWindSts = _POD_PowerDoorAntiWindSts_OFF;
	}
	else
	{
	       MessageTx_POD_PowerDoorAntiWindSts = _POD_PowerDoorAntiWindSts_Default;
	}
}
/*********************************************************************************************
** Name:	  MessageTransmit_POD_PowerDoorSafeBeltSts(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_POD_PowerDoorSafeBeltSts(void)
{
	if(BeltEnable_Status == _Function_Enable)
	{
	       MessageTx_POD_PowerDoorSafeBeltSts = _POD_PowerDoorSafeBeltSts_ON;
	}
	else if(BeltEnable_Status == _Function_Disable)
	{
	       MessageTx_POD_PowerDoorSafeBeltSts = _POD_PowerDoorSafeBeltSts_OFF;
	}
	else
	{
	       MessageTx_POD_PowerDoorSafeBeltSts = _POD_PowerDoorSafeBeltSts_Default;
	}
}
/*********************************************************************************************
** Name:	  MessageTransmit_POD_DoorPositionSts(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_POD_DoorPositionSts(void)
{
      if(SetOpenPosition_Percent >= 98)
      {
	    MessageTx_POD_DoorPositionSts = _POD_DoorPositionSts_DOORPosSetS_100p;
      }
      else if((SetOpenPosition_Percent >= 73) && (SetOpenPosition_Percent <= 83))
      {
	    MessageTx_POD_DoorPositionSts = _POD_DoorPositionSts_DOORPosSetS_80p;
      }
      else if((SetOpenPosition_Percent >= 57) && (SetOpenPosition_Percent <= 63))
      {
	    MessageTx_POD_DoorPositionSts = _POD_DoorPositionSts_DOORPosSetS_60p;
      }
      else
      {
	    MessageTx_POD_DoorPositionSts = _POD_DoorPositionSts_DOORPosSetS_Default;
      }
}
/*********************************************************************************************
** Name:	  MessageTransmit_POD_OpenValueSts(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_POD_OpenValueSts(void)
{
      MessageTx_POD_OpenValueSts = CurrentPosition_Percent;
}

/*********************************************************************************************
** Name:	  MessageTransmit_POD_FaultStatus(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_POD_FaultStatus(void)
{
     if((TRUE == DTCData_Table.table.Motor1_STG.DTCData.data.DTCStatus.bits.TestFailed) 
        ||(TRUE == DTCData_Table.table.Motor1_STB.DTCData.data.DTCStatus.bits.TestFailed)
	||(TRUE == DTCData_Table.table.Motor1_OC.DTCData.data.DTCStatus.bits.TestFailed))
     {
	   MessageTx_POD_FaultStatus = _POD_FaultStatus_Actuator_Motor_Fault;
     }
     else if(TRUE == DTCData_Table.table.BatteryVoltage_VolAbove.DTCData.data.DTCStatus.bits.TestFailed)
     {
	   MessageTx_POD_FaultStatus = _POD_FaultStatus_Over_Voltage;
     }
     else if(TRUE == DTCData_Table.table.BatteryVoltage_VolBelow.DTCData.data.DTCStatus.bits.TestFailed)
     {
	   MessageTx_POD_FaultStatus = _POD_FaultStatus_Under_Voltage;
     }
     else if(TRUE == DTCData_Table.table.HallA1_NoHall.DTCData.data.DTCStatus.bits.TestFailed)
     {
	   MessageTx_POD_FaultStatus = _POD_FaultStatus_Lost_Hall_A1;
     }
     else if(TRUE == DTCData_Table.table.HallA2_NoHall.DTCData.data.DTCStatus.bits.TestFailed)
     {
	   MessageTx_POD_FaultStatus = _POD_FaultStatus_Lost_Hall_A2;
     }
     else
     {
	   MessageTx_POD_FaultStatus = _POD_FaultStatus_No_Fault;
     }
}
/*********************************************************************************************
** Name:	  MessageTransmit_POD_ODRCDetectRequirement(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_POD_ODRCDetectRequirement(void)
{
     #ifdef _CONFIG_SonicRadar_Detect_Event
     if(TRUE == SonicRadar_Detect_Status)
     {
	   MessageTx_POD_ODRCDetectRequirement = _POD_ODRCDetectRequirement_Active;
     }
     else
     {
	   MessageTx_POD_ODRCDetectRequirement = _POD_ODRCDetectRequirement_Not_Active;
     }
     #endif
     #ifdef _CONFIG_SonicRadar_Detect_Cyclic
     if(ActiveSystemMode == SystemInitDefault)
     {
	   MessageTx_POD_ODRCDetectRequirement = _POD_ODRCDetectRequirement_Not_Active;
     }
     else
     {
	   MessageTx_POD_ODRCDetectRequirement = _POD_ODRCDetectRequirement_Active;
     }
     #endif
}
/*********************************************************************************************
** Name:	  MessageTransmit_POD_PowerDoorBrakeSts(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_POD_PowerDoorBrakeSts(void)
{
     if(_Function_Enable == BrakeEnable_Status)
     {
           MessageTx_POD_PowerDoorBrakeSts = _POD_PowerDoorBrakeSts_ON;
     }
     else
     {
	   MessageTx_POD_PowerDoorBrakeSts = _POD_PowerDoorBrakeSts_OFF;
     }
}
/*********************************************************************************************
** Name:	  MessageTransmit_POD_DoorProtectResult(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_POD_DoorProtectResult(void)
{
     static uint16_t MessageTx_POD_DoorProtectResult_Timer;
     #define K_MessageTx_POD_DoorProtectResult_Time 16
	
     if(DynamicDisplayRequest.bits.Motor1Obstacle == TRUE) 
     {
	  DynamicDisplayRequest.bits.Motor1Obstacle = FALSE;
	  MessageTx_POD_DoorProtectResult = _POD_DoorProtectResult_Anti_Pinch;	  
	  MessageTx_POD_DoorProtectResult_Timer = 0;
     }
     else if(DynamicDisplayRequest.bits.Radar == TRUE) 
     {
	  DynamicDisplayRequest.bits.Radar = FALSE;
	  MessageTx_POD_DoorProtectResult = _POD_DoorProtectResult_Outer_Obstacle;	  
	  MessageTx_POD_DoorProtectResult_Timer = 0;
     }
     else if(DynamicDisplayRequest.bits.Spindle1ThermalOver == TRUE) 
     {
	  DynamicDisplayRequest.bits.Spindle1ThermalOver = FALSE;
	  MessageTx_POD_DoorProtectResult = _POD_DoorProtectResult_OverHeat;	  
	  MessageTx_POD_DoorProtectResult_Timer = 0;
     }

     if(MessageTx_POD_DoorProtectResult_Timer >= K_MessageTx_POD_DoorProtectResult_Time)
     {
	  MessageTx_POD_DoorProtectResult = _POD_DoorProtectResult_Normal; 
     }
     else
     {
	  MessageTx_POD_DoorProtectResult_Timer ++;
     }
}
/*********************************************************************************************
** Name:	  MessageTransmit_POD_DoorCurrentValue(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_POD_DoorCurrentValue(void)
{
       MessageTx_POD_DoorCurrentValue = Motor1_Current;
}
/*********************************************************************************************
** Name:	  MessageTransmit_POD_DoorHallValue(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_POD_DoorHallValue(void)
{
       MessageTx_POD_DoorHallValue = Motor1_Position;
}
/*********************************************************************************************
** Name:	  MessageTransmit_POD_DoorVoltageValue(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_POD_DoorVoltageValue(void)
{
	MessageTx_POD_DoorVoltageValue = (Motor1_Duty_Request/40);
}

/*********************************************************************************************
** Name:	  MessageTransmit_POD_DoorInhibition(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_POD_DoorInhibition(void)
{
#define _POD_DoorInhibition_No_Inhibition               0x0U
#define _POD_DoorInhibition_Vehicle_Mode_Inhibit        0x1U
#define _POD_DoorInhibition_Crash_Inhibit               0x2U
#define _POD_DoorInhibition_Anti_Play_Inhibit           0x3U
#define _POD_DoorInhibition_Thermal_Protection_Inhibit  0x4U


     static uint16_t MessageTx_POD_DoorInhibition_Timer;
     static uint8_t MessageTx_POD_DoorInhibition_Status;
     static uint16_t POD_DoorInhibition_Check_Timer;
     static uint8_t POD_DoorInhibition_Check_Status;
      
     #define K_MessageTx_POD_DoorInhibition_Time 16
     #define K_POD_DoorInhibition_Check_Time 20
    
     if((ActiveSystemMode == SystemOpenedFully) 
        ||(ActiveSystemMode == SystemClosedFully) 
        ||(ActiveSystemMode == SystemReleased)
	||(ActiveSystemMode == SystemMechFailure))
     {
          if((TRUE == VROpen_FallEdge_Active)
	     ||(TRUE == VRClose_FallEdge_Active)
	     //||(TRUE == FollowOperate_FollowClose_Command_Active)
	     ||(TRUE == SonicRadar_PauseOpen_Command_Active)
	     #ifdef _CONFIG_CPID_Learn
             ||(TRUE == CPIDLearn_Command_Active) 
	     #endif
	     #ifdef _CONFIG_CPID_LearnPowerOpenClose
             ||(TRUE == CPIDLearnPowerOpen_Command_Active) 
	     #endif
	     #ifdef _CONFIG_OpenCloseSwitch
	     ||(TRUE == OpenCloseSwitch_ShortPress_Active)
	     #endif
	     #ifdef _CONFIG_OutsideHandleSwitch
	     ||(TRUE == OutsideHandleSwitch_ShortPress_Active)
	     #endif
	     #ifdef _CONFIG_ShutFaceSwitch
	     ||(TRUE == ShutFaceSwitch_ShortPress_Active)
	     #endif
	     )
          {
	       POD_DoorInhibition_Check_Status = TRUE;
	       POD_DoorInhibition_Check_Timer = 0;
          }
     }
     
     if(TRUE == POD_DoorInhibition_Check_Status)
     {
	  if(POD_DoorInhibition_Check_Timer >= K_POD_DoorInhibition_Check_Time)
	  {
		POD_DoorInhibition_Check_Status = FALSE;
	        if(TRUE == Motor1_ThermalProtection_Status)
		{
		      MessageTx_POD_DoorInhibition = _POD_DoorInhibition_Thermal_Protection_Inhibit;
		      
		      MessageTx_POD_DoorInhibition_Status = TRUE;
		      MessageTx_POD_DoorInhibition_Timer = 0;
		}
		else if((TRUE == PlayTimes_Status) && (ActiveSystemMode == SystemReleased))
		{
		      MessageTx_POD_DoorInhibition = _POD_DoorInhibition_Anti_Play_Inhibit;
		      
		      MessageTx_POD_DoorInhibition_Status = TRUE;
		      MessageTx_POD_DoorInhibition_Timer = 0;
		}
		else if(TRUE == VehicleCrash_MechanicalMode_Status)
		{
		      MessageTx_POD_DoorInhibition = _POD_DoorInhibition_Vehicle_Mode_Inhibit;
		      
		      MessageTx_POD_DoorInhibition_Status = TRUE;
		      MessageTx_POD_DoorInhibition_Timer = 0;
		}
		else if(TRUE == VehicleMode_MechanicalMode_Status)
		{
		      MessageTx_POD_DoorInhibition = _POD_DoorInhibition_Crash_Inhibit;
		      
		      MessageTx_POD_DoorInhibition_Status = TRUE;
		      MessageTx_POD_DoorInhibition_Timer = 0;
		}
		else
		{
		      MessageTx_POD_DoorInhibition = _POD_DoorInhibition_No_Inhibition;
		}
	  }
	  else
	  {
	       POD_DoorInhibition_Check_Timer ++;
	  }
     }
     
     if(TRUE == MessageTx_POD_DoorInhibition_Status)
     {
	   if(MessageTx_POD_DoorInhibition_Timer >= K_MessageTx_POD_DoorInhibition_Time)
	   {
		  MessageTx_POD_DoorInhibition_Status = FALSE;
		  MessageTx_POD_DoorInhibition = _POD_DoorInhibition_No_Inhibition;
	   }
	   else
	   {
		  MessageTx_POD_DoorInhibition_Timer ++;
	   }
     }

}
#endif
#endif


 
#ifdef _CHERY_COM 
    #ifdef _CHERY_COM_PD


/*********************************************************************************************
** Name:	  MessageTransmit_DCM_RemoteDiag(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/


#ifdef _CONFIG_LatchSignal_Transmit
/*********************************************************************************************
** Name:	  MessageTransmit_LatchSignal(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_LatchSignal(void)
{
     #define _LatchSignal_Close       0x0
     #define _LatchSignal_Ajar        0x1
     #define _LatchSignal_full_open   0x2
     #define _LatchSignal_Reserved    0x3
     
     if((FALSE == SecondarySwitch_Status) && (FALSE == PawlSwitch_Status))
     {
	    MessageTx_LatchSignal = _LatchSignal_Close;
     }
     else if((TRUE == SecondarySwitch_Status) && (TRUE == PawlSwitch_Status))
     {
	    MessageTx_LatchSignal = _LatchSignal_Open;
     }
     else if((FALSE == SecondarySwitch_Status) && (TRUE == PawlSwitch_Status))
     {
	    MessageTx_LatchSignal = _LatchSignal_Ajar;
     }
     else
     {
	    MessageTx_LatchSignal = _LatchSignal_Reserved;
     }
}
#endif
    #endif
    
    #ifdef _CHERY_COM_PLG
static void MessageTransmit_PLG_PositionSts(void)
{
}

static void MessageTransmit_PLG_Set_MaxPosition(void)
{
}

/*********************************************************************************************
** Name:	  MessageTransmit_PLG_LatchSts(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_PLG_LatchSts(void)
{
     if((TRUE == PawlSwitch_Status) && (TRUE == SecondarySwitch_Status))
     {
	   MessageTx_PLG_LatchSts = _PLG_LatchSts_Open;
     }
     else if((TRUE == PawlSwitch_Status) && (FALSE == SecondarySwitch_Status))
     {
	   MessageTx_PLG_LatchSts = _PLG_LatchSts_Secondary;
     }
     else if((FALSE == PawlSwitch_Status) && (FALSE == SecondarySwitch_Status))
     {
	   MessageTx_PLG_LatchSts = _PLG_LatchSts_Latched;
     }
     else
     {
	   MessageTx_PLG_LatchSts = _PLG_LatchSts_Initializing;
     }

     /* if(ActiveLatchMode == LatchFullyCinched)
      {
	   MessageTx_PLG_LatchSts = _PLG_LatchSts_Latched;
      }
      else if((ActiveLatchMode == LatchPreCinchCheck) || (ActiveLatchMode == LatchPowerCinching)
            || (ActiveLatchMode == LatchFindHomeAfterCinch))
      {
	   MessageTx_PLG_LatchSts = _PLG_LatchSts_Secondary;
      }
      else if((ActiveLatchMode == LatchPreReleasing)|| (ActiveLatchMode == LatchPowerReleasing)
             || (ActiveLatchMode == LatchFindHomeAfterRelease) || (ActiveLatchMode == LatchPreReleased))
      {
	   MessageTx_PLG_LatchSts = _PLG_LatchSts_Secondary;
      }
      else if(ActiveLatchMode == LatchFullyReleased)
      {
	   MessageTx_PLG_LatchSts = _PLG_LatchSts_Open;
      }
      else
      {
	   MessageTx_PLG_LatchSts = _PLG_LatchSts_Initializing;
      }*/

}


/*********************************************************************************************
** Name:	  MessageTransmit_PLG_PinchEvent(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_PLG_PinchEvent(void)
{
    static uint16_t MessageTx_PLG_PinchEvent_Timer;
    #define K_MessageTx_PLG_PinchEvent_Time 30

     if(DynamicDisplayRequest.bits.Motor1Obstacle == TRUE) 
     {
	  DynamicDisplayRequest.bits.Motor1Obstacle = FALSE;
	  MessageTx_PLG_PinchEvent = TRUE;
	  
	  MessageTx_PLG_PinchEvent_Timer = 0;
     }
     else if(DynamicDisplayRequest.bits.Motor2Obstacle == TRUE) 
     {
	  DynamicDisplayRequest.bits.Motor2Obstacle = FALSE;
	  MessageTx_PLG_PinchEvent = TRUE;
	  
	  MessageTx_PLG_PinchEvent_Timer = 0;
     }
     else if(DynamicDisplayRequest.bits.AntipinchPressed == TRUE) 
     {
	  DynamicDisplayRequest.bits.AntipinchPressed = FALSE;
	  MessageTx_PLG_PinchEvent = TRUE;
	  
	  MessageTx_PLG_PinchEvent_Timer = 0;
     }
     else if(DynamicDisplayRequest.bits.AntipinchPressedLeft == TRUE) 
     {
	  DynamicDisplayRequest.bits.AntipinchPressedLeft = FALSE;
	  MessageTx_PLG_PinchEvent = TRUE;
	  
	  MessageTx_PLG_PinchEvent_Timer = 0;
     }

     if(MessageTx_PLG_PinchEvent_Timer >= K_MessageTx_PLG_PinchEvent_Time)
     {
	  MessageTx_PLG_PinchEvent = FALSE; 
     }
     else
     {
	  MessageTx_PLG_PinchEvent_Timer ++;
     }
}

/*********************************************************************************************
** Name:	  MessageTransmit_PLG_OperateSts(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_PLG_OperateSts(void)
{
      if(ActiveSystemMode == SystemOpenedFully)
      {
	   MessageTx_PLG_OperateSts = _PLG_OperateSts_Open;
      }
      else if(ActiveSystemMode == SystemClosedFully)
      {
	   MessageTx_PLG_OperateSts = _PLG_OperateSts_Close;
      }
      else if(ActiveSystemMode == SystemPowerOpening)
      {
	   MessageTx_PLG_OperateSts = _PLG_OperateSts_Opening;
      }
      else if(ActiveSystemMode == SystemPowerClosing)
      {
	   MessageTx_PLG_OperateSts = _PLG_OperateSts_Closing;
      }
      else if((ActiveSystemMode == SystemReleased))
      {
	   MessageTx_PLG_OperateSts = _PLG_OperateSts_Stop;
      }    
      else if((ActiveSystemMode == SystemReleaseOnly) || (ActiveSystemMode == SystemReleaseToPowerOpen))
      {
	   MessageTx_PLG_OperateSts = _PLG_OperateSts_Opening;
      }
      else if((ActiveSystemMode == SystemPowerCinching) || (ActiveSystemMode == SystemPowerParking))
             //||(ActiveSystemMode == SystemManualCinching) || (ActiveSystemMode == SystemManualParking))
      {
	   MessageTx_PLG_OperateSts = _PLG_OperateSts_Closing;
      }
      else if(ActiveSystemMode == SystemMechFailure)
      {
	   MessageTx_PLG_OperateSts = _PLG_OperateSts_Stop;
      } 
}


 /*********************************************************************************************
** Name:	  MessageTransmit_PLG_GlobalSW(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_PLG_GlobalSW(void)
{
      static uint16_t MessageTx_PLG_GlobalSW_Start_Timer;
      static uint8_t MessageTx_PLG_GlobalSW_Start_Status;
      #define K_MessageTx_PLG_GlobalSW_Start_Time 30
      
      static uint16_t MessageTx_PLG_GlobalSW_Detect_Timer;
      static uint8_t MessageTx_PLG_GlobalSW_Detect_Status;
      
      #define K_MessageTx_PLG_GlobalSW_Detect_Time 10
      
      #ifdef _CHERY_COM_PLG
      if(TRUE == ShutFaceLockSwitch_ShortPress_Active)
      {
	    if((ActiveSystemMode == SystemOpenedFully) || (ActiveSystemMode == SystemReleased))
            {
                  MessageTx_PLG_GlobalSW_Detect_Status = TRUE;
		  MessageTx_PLG_GlobalSW_Detect_Timer = 0;
	    }
      }
      #endif
      
      if(TRUE == MessageTx_PLG_GlobalSW_Detect_Status)
      {
          if(MessageTx_PLG_GlobalSW_Detect_Timer >= K_MessageTx_PLG_GlobalSW_Detect_Time)
          {
	       MessageTx_PLG_GlobalSW_Detect_Status = FALSE;
	       if((ActiveSystemMode == SystemPowerClosing) 
                  || (ActiveSystemMode == SystemPowerCinching)
	          || (ActiveSystemMode == SystemPowerParking))
               {
	           MessageTx_PLG_GlobalSW = _PLG_GlobalSW_Close;
		   
		   MessageTx_PLG_GlobalSW_Start_Status = TRUE;
		   MessageTx_PLG_GlobalSW_Start_Timer = 0;
	
               }
	  }
          else
          {
	       MessageTx_PLG_GlobalSW_Detect_Timer ++;
          }
      }
      
      if(TRUE == MessageTx_PLG_GlobalSW_Start_Status)
      {
	    if(MessageTx_PLG_GlobalSW_Start_Timer >= K_MessageTx_PLG_GlobalSW_Start_Time)
	    {
		 MessageTx_PLG_GlobalSW = _PLG_GlobalSW_Not_active;
	    }
	    else
	    {
		 MessageTx_PLG_GlobalSW_Start_Timer ++;
	    }    
      }
      
      /*if((TRUE == ShutFaceLockSwitch_Status) && (TRUE == Configuration_T1X_ShutFaceLockSwitch_Enable))
      {
            if((ActiveSystemMode == SystemOpenedFully) || (ActiveSystemMode == SystemReleased))
            {
	          MessageTx_PLG_GlobalSW = _PLG_GlobalSW_Close;
            }
      }
      else
      {
	    MessageTx_PLG_GlobalSW = _PLG_GlobalSW_Not_active;
      }*/
}
 /*********************************************************************************************
** Name:	  MessageTransmit_PLG_ECUtemp(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_PLG_ECUtemp(void)
{
      MessageTx_PLG_ECUtemp = Board_Temperature - 10;     
      //MessageTx_PLG_ECUtemp = Vehicle_Temperature - 10;

}

/*********************************************************************************************
** Name:	  MessageTransmit_PLG_OperateStsValidData(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_PLG_OperateStsValidData(void)
{
    if(TRUE == SystemLearned_Status)
    {
	 MessageTx_PLG_OperateStsValidData = _PLG_OperateStsValidData_Valid;
    }
    else
    {
	 MessageTx_PLG_OperateStsValidData = _PLG_OperateStsValidData_Not_Valid;
    }
}
/*********************************************************************************************
** Name:	  MessageTransmit_PLG_UnLockInformation(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_PLG_UnLockInformation(void)
{
     #define K_MessageTx_PLG_UnLockInformation_Time 30
     #define K_PEUnlock_Start_Time 10
     #define K_KnickUnlock_Start_Time 2
     
     static uint16_t MessageTx_PLG_UnLockInformation_Timer;    
     static uint8_t PEUnlock_Start_Status;
     static uint16_t PEUnlock_Start_Timer;
     static uint8_t KnickUnlock_Start_Status;
     static uint16_t KnickUnlock_Start_Timer;
     
     if(TRUE == OutsideHandleSwitch_ShortPress_Active) 
     {
	  PEUnlock_Start_Status = TRUE;
	  PEUnlock_Start_Timer = 0;
     }
     else if(TRUE == KickSensor_FallEdge_Active)
     {
	  KnickUnlock_Start_Status = TRUE;
	  KnickUnlock_Start_Timer = 0;
     }
     
     
     if(TRUE == PEUnlock_Start_Status)
     {
	  if(PEUnlock_Start_Timer >= K_PEUnlock_Start_Time)
	  {
		PEUnlock_Start_Status = FALSE;
	        PEUnlock_Start_Timer = 0;
		
		if((ActiveSystemMode == SystemClosedFully) && (ActiveSystemMode == SystemClosedFully)
		  &&(TRUE == VehicleLock_Status))
	        {
	              MessageTx_PLG_UnLockInformation = _PLG_UnLockInformation_PEUnlock;	  
	              MessageTx_PLG_UnLockInformation_Timer = 0;
	        }
	  }
	  else
	  {
		PEUnlock_Start_Timer ++;
	  }
     }
     
     
     if(TRUE == KnickUnlock_Start_Status)
     {
	  if(KnickUnlock_Start_Timer >= K_KnickUnlock_Start_Time)
	  {
		KnickUnlock_Start_Status = FALSE;
	        KnickUnlock_Start_Timer = 0;
		
		if((ActiveSystemMode == SystemClosedFully) && (ActiveSystemMode == SystemClosedFully))
		   //&&(TRUE == VehicleLock_Status))
		{
	              MessageTx_PLG_UnLockInformation = _PLG_UnLockInformation_KnickUnlock;	  
	              MessageTx_PLG_UnLockInformation_Timer = 0;
		}
	  }
	  else
	  {
		KnickUnlock_Start_Timer ++;
	  }
     }  

     if(MessageTx_PLG_UnLockInformation_Timer >= K_MessageTx_PLG_UnLockInformation_Time)
     {
	  MessageTx_PLG_UnLockInformation = _PLG_UnLockInformation_Not_Active; 
     }
     else
     {
	  MessageTx_PLG_UnLockInformation_Timer ++;
     }
}

/*********************************************************************************************
** Name:	  MessageTransmit_PLG_OperateInd(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_PLG_OperateInd(void)
{
     #define K_MessageTx_PLG_OperateInd_Time 30
     static uint16_t MessageTx_PLG_OperateInd_Timer;  
     
     if(FlashRemind_Request != No_Remind)
     {
	  if(FlashRemind_Request == Remind_2)
	  {
	        FlashRemind_Request = No_Remind;
	        MessageTx_PLG_OperateInd = _PLG_OperateInd_Case2;
	        MessageTx_PLG_OperateInd_Timer = 0;
	  }
	  else if(FlashRemind_Request == Remind_3)
	  {
	        FlashRemind_Request = No_Remind;
	        MessageTx_PLG_OperateInd = _PLG_OperateInd_Case3;
	        MessageTx_PLG_OperateInd_Timer = 0;
	  }       
     }
        
     if(MessageTx_PLG_OperateInd_Timer >= K_MessageTx_PLG_OperateInd_Time)
     {
	       MessageTx_PLG_OperateInd = _PLG_OperateInd_Case1;
     }
     else
     {
	       MessageTx_PLG_OperateInd_Timer ++;
     }
}
 /*********************************************************************************************
** Name:	  MessageTransmit_PLG_ECUFailSts(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_PLG_ECUFailSts(void)
{
}

/*********************************************************************************************
** Name:	  MessageTransmit_LatchSwitch(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_LatchSwitch(void)
{
      #ifdef _CONFIG_PawlSwitch
      MessageTx_PawlSwitch = PawlSwitch_Status;
      #endif
      #ifdef _CONFIG_SecondarySwitch
      MessageTx_SecondarySwitch = SecondarySwitch_Status;
      #endif
      #ifdef _CONFIG_PositionSwitch
      MessageTx_PositonSwitch = PositionSwitch_Status;
      #endif
      #ifdef _CONFIG_PrimarySwitch
      MessageTx_PrimarySwitch = PrimarySwitch_Status;
      #endif
}
/*********************************************************************************************
** Name:	  MessageTransmit_GateOpenAngle(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_GateOpenAngle(void)
{
     if(TRUE == SystemLearned_Status)
     {
          MessageTx_GateOpenAngle = (uint16_t)((uint32_t)(Motor1_Position * 100) / SystemLearned_Position);
	   
     }
     else
     {
	  MessageTx_GateOpenAngle = (uint16_t)((uint32_t)(Motor1_Position * 100) / K_SystemLearned_Position_Default);
     }
     
     if(MessageTx_GateOpenAngle > K_MessageTx_GateOpenAngle_Max)
     {
	  MessageTx_GateOpenAngle = K_MessageTx_GateOpenAngle_Max;
     }
}
 
 
 /*********************************************************************************************
** Name:	  MessageTransmit_GaragePosition(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_GaragePosition(void)
{ 
    if(FALSE == GarageHeightRequest_Process_Status)
    {
        if(TRUE == SystemLearned_Status)
        {
            /*if(TRUE == GarageLearned_Status)
            {*/
                 MessageTx_GaragePosition = (uint16_t)((uint32_t)(GarageLearned_Position * 100) / SystemLearned_Position);
	         MessageTx_GaragePosition_Remainder = (uint16_t)((uint32_t)(GarageLearned_Position * 100) % SystemLearned_Position);
            /*}
            else
            {
	         MessageTx_GaragePosition = (uint16_t)((uint32_t)(K_GarageLearned_Position_Default * 100) / SystemLearned_Position);	       
            }*/
        }
        else
        {
	    if(TRUE == GarageLearned_Status)
            {
                 MessageTx_GaragePosition = (uint16_t)((uint32_t)(GarageLearned_Position * 100) / K_SystemLearned_Position_Default);
	         MessageTx_GaragePosition_Remainder = (uint16_t)((uint32_t)(GarageLearned_Position * 100) % K_SystemLearned_Position_Default);                        
            }
            else
            {
	         MessageTx_GaragePosition = (uint16_t)((uint32_t)(K_GarageLearned_Position_Default * 100) / K_SystemLearned_Position_Default);
	       
            }
        }
    
        if(MessageTx_GaragePosition_Remainder > 0)
        {
	     MessageTx_GaragePosition += K_GaragePosition_Precision_Compensation;
        }
    
        if(MessageTx_GaragePosition > K_MessageTx_GateOpenAngle_Max)
        {
	     MessageTx_GaragePosition = K_MessageTx_GateOpenAngle_Max;
        } 
    }
    else
    {
	 MessageTx_GaragePosition = MessageRx_GarageHeight;
    }
} 
/*********************************************************************************************
** Name:	  MessageTransmit_LearnStatus(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_LearnStatus(void)
{
       MessageTx_SystemLearnedStatus = SystemLearned_Status;
       MessageTx_GarageLearnedStatus = GarageLearned_Status;
       MessageTx_GarageLearnAction = ShutFaceSwitch_LongPress_Status;     
       MessageTx_SystemLearnFailure = System_Learn_Failure;
}


#ifdef _CONFIG_LIN_Master
/*********************************************************************************************
** Name:	  MessageTransmit_TowHookEnd_position(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_TowHookEnd_position(void)
{
}

/*********************************************************************************************
** Name:	  MessageTransmit_KSEnable(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_KSEnable(void)
{
      if((VehiclePowerMode == PowerMode_OFF) ||(TRUE == VehicleRemoteMode_Status))
      {
	    MessageTx_KSEnable = TRUE;
      }
      else
      {
	    MessageTx_KSEnable = FALSE;
      }
}
/*********************************************************************************************
** Name:	  MessageTransmit_TailgatePosition(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_TailgatePosition(void)
{
}

/*********************************************************************************************
** Name:	  MessageTransmit_VehicleType(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_VehicleType(void)
{
     MessageTx_VehicleType = TRUE;
}

/*********************************************************************************************
** Name:	  MessageTransmit_TailgateMovementCloseState(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_TailgateMovementCloseState(void)
{
     if(ActiveSystemMode == SystemPowerClosing) 
     {
	   MessageTx_TailgateMovementCloseState = TRUE;
     }
     else
     {
	   MessageTx_TailgateMovementCloseState = FALSE;
     }
     
}

/*********************************************************************************************
** Name:	  MessageTransmit_TailgateMovemntOpenState(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_TailgateMovemntOpenState(void)
{
     if(ActiveSystemMode == SystemPowerOpening) 
     {
           MessageTx_TailgateMovementOpenState = TRUE;
     }
     else
     {
	   MessageTx_TailgateMovementOpenState = FALSE;
     }
}

/*********************************************************************************************
** Name:	  MessageTransmit_CatchBoltStatus(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_CatchBoltStatus(void)
{
     MessageTx_CatchBoltStatus = SecondarySwitch_Status;
}

/*********************************************************************************************
** Name:	  MessageTransmit_PawlStatus(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_PawlStatus(void)
{
     MessageTx_PawlStatus = PawlSwitch_Status;
}
#endif
   #endif
#endif
 




#ifdef _DEARCC_COM 
/*********************************************************************************************
** Name:	  MessageTransmit_PLGMode(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_PLGMode(void)
{
   if(TRUE == SpindleDisableMode_Status)
   {
	MessageTx_CurrentPLGMode = _PLGMODE_MANUAL;
   }
   else if(TRUE == SpindleGarageMode_Status)
   {
	MessageTx_CurrentPLGMode = _PLGMODE_GARAGE;
   }
   else
   {
	MessageTx_CurrentPLGMode = _PLGMODE_NORMAL;
   }
}

/*********************************************************************************************
** Name:	  MessageTransmit_GateMotion(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/ 
 static void MessageTransmit_GateMotion(void)
 {
      if(ActiveSystemMode == SystemOpenedFully)
      {
	   MessageTx_GateMotion = Fully_Opened;
      }
      else if(ActiveSystemMode == SystemClosedFully)
      {
	   MessageTx_GateMotion = Fully_Closed;
      }
      else if(ActiveSystemMode == SystemPowerOpening)
      {
	   MessageTx_GateMotion = Opening;
      }
      else if(ActiveSystemMode == SystemPowerClosing)
      {
	   MessageTx_GateMotion = Closing;
      }
      else if(ActiveSystemMode == SystemReleased)
      {
	   MessageTx_GateMotion = PLG_Stopped;
      } 
      else if((ActiveSystemMode == SystemReleaseOnly) || (ActiveSystemMode == SystemReleaseToPowerOpen))
      {
	   MessageTx_GateMotion = Latch_Releasing;
      }
      else if((ActiveSystemMode == SystemPowerCinching) || (ActiveSystemMode == SystemPowerParking)
             ||(ActiveSystemMode == SystemManualCinching) || (ActiveSystemMode == SystemManualParking))
      {
	   MessageTx_GateMotion = Latch_Cinching;
      }
      else if(ActiveSystemMode == SystemMechFailure)
      {
	   MessageTx_GateMotion = PLG_Unknown;
      }
      
 }
 
/*********************************************************************************************
** Name:	  MessageTransmit_LatchSwitch(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_LatchSwitch(void)
{
      MessageTx_PawlSwitch = PawlSwitch_Status;
      MessageTx_SecondarySwitch = SecondarySwitch_Status;
      MessageTx_PositonSwitch = PositionSwitch_Status;
      MessageTx_ShutFaceSwitch = ShutFaceSwitch_Status;
}

/*********************************************************************************************
** Name:	  MessageTransmit_GateOpenAngle(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_GateOpenAngle(void)
{
     if(TRUE == SystemLearned_Status)
     {
           MessageTx_GateOpenAngle = (uint16_t)((uint32_t)(Motor1_Position * 100) / SystemLearned_Position);
	   MessageTx_GateOpenAngle_Valid = _OPEN_ANG_VALID;
     }
     else
     {
	   MessageTx_GateOpenAngle = (uint16_t)((uint32_t)(Motor1_Position * 100) / K_SystemLearned_Position_Default);
	   MessageTx_GateOpenAngle_Valid = _OPEN_ANG_VALID;
     }
     
     if(MessageTx_GateOpenAngle > K_MessageTx_GateOpenAngle_Max)
     {
	  MessageTx_GateOpenAngle = K_MessageTx_GateOpenAngle_Max;
     }
}
 
 
 /*********************************************************************************************
** Name:	  MessageTransmit_DiagInformation(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
 static void MessageTransmit_DiagInformation(void)
 {
      /*Motor1*/ 
       if((FALSE == Motor1_STG_DTCStatus.bits.TestFailed) 
          &&(FALSE == Motor1_STB_DTCStatus.bits.TestFailed)
	  &&(FALSE == Motor1_OC_DTCStatus.bits.TestFailed))
       {
	     MessageTx_Motor1Fault = _OK;
       }
       else if(TRUE == Motor1_STG_DTCStatus.bits.TestFailed)
       {
	     MessageTx_Motor1Fault = _SHORT_GROUND;
       }
       else if(TRUE == Motor1_STB_DTCStatus.bits.TestFailed)
       {
	     MessageTx_Motor1Fault = _SHORT_BATTERY;
       }
       else
       {
	     MessageTx_Motor1Fault = _SIGNAL_INVALID;
       }
       
       /*Motor2*/ 
       if((FALSE == Motor2_STG_DTCStatus.bits.TestFailed) 
          &&(FALSE == Motor2_STB_DTCStatus.bits.TestFailed)
	  &&(FALSE == Motor2_OC_DTCStatus.bits.TestFailed))
       {
	     MessageTx_Motor2Fault = _OK;
       }
       else if(TRUE == Motor1_STG_DTCStatus.bits.TestFailed)
       {
	     MessageTx_Motor2Fault = _SHORT_GROUND;
       }
       else if(TRUE == Motor2_STB_DTCStatus.bits.TestFailed)
       {
	     MessageTx_Motor2Fault = _SHORT_BATTERY;
       }
       else
       {
	     MessageTx_Motor2Fault = _SIGNAL_INVALID;
       }
       
        /*LatchMotor*/ 
       if((FALSE == CinchMotor_STG_DTCStatus.bits.TestFailed)
           &&(FALSE == CinchMotor_STB_DTCStatus.bits.TestFailed)
           &&(FALSE == CinchMotor_OC_DTCStatus.bits.TestFailed))
       {
	     MessageTx_LatchMotorFault = _OK;
       }
       else if(TRUE == CinchMotor_STG_DTCStatus.bits.TestFailed)
       {
	     MessageTx_LatchMotorFault = _SHORT_GROUND;
       }
       else if(TRUE == CinchMotor_STB_DTCStatus.bits.TestFailed)
       {
	     MessageTx_LatchMotorFault = _SHORT_BATTERY;
       }
       else
       {
	     MessageTx_LatchMotorFault = _SIGNAL_INVALID;
       }
       
       /*Tape Switch*/ 
       if((FALSE == AntiPinch_STG_DTCStatus.bits.TestFailed) 
          &&(FALSE == AntiPinch_STBorOC_DTCStatus.bits.TestFailed))
       {
	     MessageTx_TapeSwitchFault = _OK;
       }
       else if(TRUE == AntiPinch_STG_DTCStatus.bits.TestFailed)
       {
	     MessageTx_TapeSwitchFault = _SHORT_GROUND;
       }
       else if(TRUE == AntiPinch_STBorOC_DTCStatus.bits.TestFailed)
       {
	     MessageTx_TapeSwitchFault = _SHORT_BATTERY;
       }
       else
       {
	     MessageTx_TapeSwitchFault = _SIGNAL_INVALID;
       }
       
 /* Hall Sensor Switch*/ 
       if((FALSE == HallA2_NoHall_DTCStatus.bits.TestFailed) && (FALSE == HallB2_NoHall_DTCStatus.bits.TestFailed)
          &&(FALSE == HallA1_NoHall_DTCStatus.bits.TestFailed) && (FALSE == HallB1_NoHall_DTCStatus.bits.TestFailed))
       {
	     MessageTx_HallFault = _OK;
       }
       else if((TRUE == HallA1_NoHall_DTCStatus.bits.TestFailed) || (TRUE == HallB1_NoHall_DTCStatus.bits.TestFailed)
               ||(TRUE == HallA2_NoHall_DTCStatus.bits.TestFailed) || (TRUE == HallB2_NoHall_DTCStatus.bits.TestFailed))
       {
	     MessageTx_HallFault = _SHORT_BATTERY;
       }
       else
       {
	     MessageTx_HallFault = _SIGNAL_INVALID;
       }	 
	 
 }
 
/*********************************************************************************************
** Name:	  MessageTransmit_GaragePosition(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_GaragePosition(void)
{
    if(FALSE == GarageHeightRequest_Process_Status)
    {      
        if(TRUE == SystemLearned_Status)
        {
            if(TRUE == GarageLearned_Status)
            {
                 MessageTx_GaragePosition = (uint16_t)((uint32_t)(GarageLearned_Position * 100) / SystemLearned_Position);
	         MessageTx_GaragePosition_Remainder = (uint16_t)((uint32_t)(GarageLearned_Position * 100) % SystemLearned_Position);
            }
            else
            {
	         MessageTx_GaragePosition = (uint16_t)((uint32_t)(SystemLearned_Position * 100) / SystemLearned_Position);	       
            }
        }
        else
        {
	    if(TRUE == GarageLearned_Status)
            {
                 MessageTx_GaragePosition = (uint16_t)((uint32_t)(GarageLearned_Position * 100) / K_SystemLearned_Position_Default);
	         MessageTx_GaragePosition_Remainder = (uint16_t)((uint32_t)(GarageLearned_Position * 100) % K_SystemLearned_Position_Default);                        
            }
            else
            {
	         MessageTx_GaragePosition = (uint16_t)((uint32_t)(SystemLearned_Position * 100) / K_SystemLearned_Position_Default);
	       
            }
        }
    
        if(MessageTx_GaragePosition_Remainder > 0)
        {
	     MessageTx_GaragePosition += K_GaragePosition_Precision_Compensation;
        }
    
        if(MessageTx_GaragePosition > K_MessageTx_GateOpenAngle_Max)
        {
	     MessageTx_GaragePosition = K_MessageTx_GateOpenAngle_Max;
        }
    }
    /*else
    {
	 MessageTx_GaragePosition = MessageRx_GarageHeight;
    }*/
    
}

/*********************************************************************************************
** Name:	  MessageTransmit_AppControlEnableStatus(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/ 
static void MessageTransmit_AppControlEnableStatus(void)
{    
     MessageTx_AppAuthorize_Status = AppAuthorize_Status;
}

/*********************************************************************************************
** Name:	  MessageTransmit_PLGKickActiveReq(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_PLGKickActiveReq(void)
{	
     static uint16_t MessageTx_HandFreeSwitch_Timer;

     if(TRUE == HandFreeSwitch_FallEdge_Active) 
     {
	  if((ActiveSystemMode == SystemReleased) 
            ||(ActiveSystemMode == SystemClosedFully)
	    ||(ActiveSystemMode == SystemOpenedFully))
	  {
	       MessageTx_HandFreeSwitch = TRUE;	  
	       MessageTx_HandFreeSwitch_Timer = 0;
	  }
     }

     if(MessageTx_HandFreeSwitch_Timer >= K_MessageTx_HandFreeSwitch_Time)
     {
	  MessageTx_HandFreeSwitch = FALSE; 
     }
     else
     {
	  MessageTx_HandFreeSwitch_Timer ++;
     }
}

/*********************************************************************************************
** Name:	  MessageTransmit_PLGConditionFault(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/ 
static void MessageTransmit_PLGConditionFault(void)
{
    static uint16_t MessageTx_PLGConditionFault_Timer;   
    static uint8_t MessageTx_PLGConditionFault_Check_Status;
    static uint16_t MessageTx_PLGConditionFault_Check_Timer;

    
      if((TRUE == ShutFaceSwitch_FallEdge_Command_Active)
	||(TRUE == OpenCloseSwitch_FallEdge_Command_Active)
        ||(TRUE == OutsideHandleSwitch_FallEdge_Command_Active)
        ||(TRUE == TouchPad_FallEdge_Command_Active)
	||(TRUE == HandFreeSwitch_FallEdge_Command_Active)
        //||(TRUE == PKETrunkButton_FallEdge_Command_Active)
	#ifdef _CONFIG_AppOpen
	||(TRUE == AppOpen_FallEdge_Command_Active)
	#endif
	#ifdef _CONFIG_AppOpen
	||(TRUE == AppClose_FallEdge_Command_Active)
	#endif
	||(TRUE == DriverButton_FallEdge_Command_Active)
	||(TRUE == Motor1_FollowClose_Command_Active)
	||(TRUE == Motor1_FollowOpen_Command_Active))
     {
	   MessageTx_PLGConditionFault_Check_Status = TRUE;
	   MessageTx_PLGConditionFault_Check_Timer = 0;
     }
     
     if(TRUE == MessageTx_PLGConditionFault_Check_Status)
     {
	  if(MessageTx_PLGConditionFault_Check_Timer >= K_MessageTx_PLGConditionFault_Check_Time)
	  {
               
	       if(StaticDisplayRequest.bits.VehicleSpeed == TRUE) 
               {
	            StaticDisplayRequest.bits.VehicleSpeed = FALSE;
	            MessageTx_PLGConditionFault = VehicleSpeedIsHigh;
	  
	            MessageTx_PLGConditionFault_Status = TRUE;
	            MessageTx_PLGConditionFault_Timer = 0;
               }
	       else if((StaticDisplayRequest.bits.Locked == TRUE) 
	              &&(ActiveSystemMode == SystemClosedFully))
               {
	            StaticDisplayRequest.bits.Locked = FALSE;
	            MessageTx_PLGConditionFault = VehicleIsLocked;
	  
	            MessageTx_PLGConditionFault_Status = TRUE;
	            MessageTx_PLGConditionFault_Timer = 0;
               }	       
               else if(StaticDisplayRequest.bits.Voltage == TRUE) 
               {
	            StaticDisplayRequest.bits.Voltage = FALSE;
	            MessageTx_PLGConditionFault = BatteryVoltageIsOutofRange;
	  
	            MessageTx_PLGConditionFault_Status = TRUE;
	            MessageTx_PLGConditionFault_Timer = 0;
               } 
	       else if(StaticDisplayRequest.bits.OverObstacleTimes == TRUE) 
               {
	            StaticDisplayRequest.bits.OverObstacleTimes = FALSE;
	            MessageTx_PLGConditionFault = PinchIsTriggered;
	  
	            MessageTx_PLGConditionFault_Status = TRUE;
	            MessageTx_PLGConditionFault_Timer = 0;
               } 
               else if(StaticDisplayRequest.bits.PlayProtected == TRUE) 
               {
	            StaticDisplayRequest.bits.PlayProtected = FALSE;
	            MessageTx_PLGConditionFault = PlayOffIsTriggered;
	  
	            MessageTx_PLGConditionFault_Status = TRUE;
	            MessageTx_PLGConditionFault_Timer = 0;
               }
	       else if(StaticDisplayRequest.bits.Temperature == TRUE)
               {
	            StaticDisplayRequest.bits.Temperature = FALSE;
	            MessageTx_PLGConditionFault = EnvironmentTemperatureIsOutofRange;
	  
	            MessageTx_PLGConditionFault_Status = TRUE;
	            MessageTx_PLGConditionFault_Timer = 0;
               }
               else if(StaticDisplayRequest.bits.DisableMode == TRUE)
               {
	            StaticDisplayRequest.bits.DisableMode = FALSE;
	            MessageTx_PLGConditionFault = PowerFunctionIsDisable;
	  
	            MessageTx_PLGConditionFault_Status = TRUE;
	            MessageTx_PLGConditionFault_Timer = 0;
               }
               	   
	       MessageTx_PLGConditionFault_Check_Status = FALSE;
	       MessageTx_PLGConditionFault_Check_Timer = 0;
	  }
	  else
	  {
	       MessageTx_PLGConditionFault_Check_Timer ++;
	  }
     }

     
     if(MessageTx_PLGConditionFault_Timer >= K_MessageTx_PLGConditionFault_Time)
     {
	  MessageTx_PLGConditionFault = No_Condition_Fault; 
	  MessageTx_PLGConditionFault_Status = FALSE;
     }
     else
     {
	  MessageTx_PLGConditionFault_Timer ++;
     }
     
} 
/*********************************************************************************************
** Name:	  MessageTransmit_LearnStatus(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_LearnStatus(void)
{
       MessageTx_SystemLearnedStatus = SystemLearned_Status;
       MessageTx_GarageLearnedStatus = GarageLearned_Status;
       MessageTx_GarageLearnAction = ShutFaceSwitch_LongPress_Status;
       MessageTx_SystemLearnFailure = System_Learn_Failure;
}
#endif

#ifdef _XIAOPENG_COM 
/*********************************************************************************************
** Name:	  MessageTransmit_MoveReq(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_MoveReq(void)
{
     static uint16_t MessageTx_SCU_MoveReq_Timer;

     if (((ActiveSystemMode == SystemClosedFully) 
            ||((ActiveSystemMode == SystemReleased) && (FALSE == GarageEnd_SoftStop_Position_Status))
	    ||((ActiveSystemMode == SystemPowerOpening) && (TRUE == SoftStop_Working_Status))
            ||(ActiveSystemMode == SystemMechFailure))
           //|| (ActiveSystemMode == SystemPowerCinching) || (ActiveSystemMode == SystemPowerParking))
	 && (TRUE == SystemLearned_Status)  
         && ((TRUE == Motor1_FollowOpen_FallEdge_Active)
              //||(TRUE == OutsideHandleSwitch_LongPress_Active)
	      //||((TRUE == OutsideHandleSwitch_ShortPress_Active) && (LastPowerState_ForReversal == SystemPowerClosing) && (ActiveSystemMode == SystemReleased))
	      ||((TRUE == OutsideHandleSwitch_ShortPress_Active))
              //||((TRUE == OutsideHandleSwitch_FallEdge_Active))
	      #ifdef _CONFIG_HandleOpenSwitch
              //||(TRUE == HandleOpenSwitch_LongPress_Active)
	      ||(TRUE == HandleOpenSwitch_ShortPress_Active)
              //||(TRUE == HandleOpenSwitch_FallEdge_Active)
	      #endif
              //||(TRUE == RKEStepOpen_FallEdge_Active)
            ||(TRUE == RKEOpen_FallEdge_Active)
              //||(TRUE == VRStepOpen_FallEdge_Active)
            ||(TRUE == VROpen_FallEdge_Active)
              //||(TRUE == AppStepOpen_FallEdge_Active)
            ||(TRUE == AppOpen_FallEdge_Active)
              //||(TRUE == BLEStepOpen_FallEdge_Active)
            ||(TRUE == BLEOpen_FallEdge_Active)
	      //||(TRUE == AutoStepOpen_FallEdge_Active)
	    ||(TRUE == AutoOpen_FallEdge_Active)
	    ||(TRUE == MechanicalHandle_FallEdge_Active)))
	       
     {	  
	  MessageTx_SCU_MoveReq = TRUE;
	  MessageTx_SCU_MoveReq_Timer = 0;	  
	  SonicRadar_Detect_Status = TRUE; /*XIAOPENG_TEST_ON_PLG_FIXTURE*/
     }
     else if(((ActiveSystemMode == SystemReleaseToPowerOpen)
             ||(ActiveSystemMode == SystemPowerOpening))
	     &&(FALSE == StepControl_Request)
	     &&(TRUE == SystemLearned_Status))
	     /*&&((FALSE == OutsideHandleSwitch_Status) 
	     #ifdef _CONFIG_HandleOpenSwitch
	     && (FALSE == HandleOpenSwitch_Status)
	     #endif
	     ))*/
     {
	   MessageTx_SCU_MoveReq = TRUE;
	   MessageTx_SCU_MoveReq_Timer = 0;
	   SonicRadar_Detect_Status = TRUE; /*XIAOPENG_TEST_ON_PLG_FIXTURE*/
     }
     
     if(TRUE == MessageTx_SCU_MoveReq)
     {
          /*if(((ActiveSystemMode == SystemReleased)
               || (ActiveSystemMode == SystemOpenedFully)
	       || (ActiveSystemMode == SystemMechFailure)
	       || (ActiveSystemMode == SystemClosedFully)
	       || (ActiveSystemMode == SystemPowerClosing))
	     && ((LastSystemMode == SystemPowerOpening) 
	       || (LastSystemMode == SystemReleaseToPowerOpen)))
          {
	        MessageTx_SCU_MoveReq = FALSE;
		SonicRadar_Detect_Status = FALSE;
          }*/         
	  
	  if(MessageTx_SCU_MoveReq_Timer >= K_MessageTx_SCU_MoveReq_Time)
          {
	        MessageTx_SCU_MoveReq = FALSE;
		SonicRadar_Detect_Status = FALSE;
          }
          else
          {
	        MessageTx_SCU_MoveReq_Timer ++;
          }
     }
}
/*********************************************************************************************
** Name:	  MessageTransmit_DenormalizeSt(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_DenormalizeSt(void)
{
     /*if(TRUE == System_AfterPowerUp_Status)
     {
	  MessageTx_DenormalizeSt = FALSE;
     }
     else
     {
	  MessageTx_DenormalizeSt = TRUE;
     }*/
     if(TRUE == SystemLearned_Status)
     {
	  MessageTx_DenormalizeSt = TRUE;
     }
     else
     {
	  MessageTx_DenormalizeSt = FALSE;
     }
}
/*********************************************************************************************
** Name:	  MessageTransmit_AntipintchSt(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_AntipintchSt(void)
{
     static uint16_t MessageTx_AntipintchSt_Timer;

     if(((ActiveSystemMode == SystemReleased) && (LastSystemMode == SystemReleased))
         || ((ActiveSystemMode == SystemOpenedFully) && (LastSystemMode == SystemOpenedFully))
	 || ((ActiveSystemMode == SystemMechFailure) && (LastSystemMode == SystemMechFailure)))
     {
          if(DynamicDisplayRequest.bits.Motor1Obstacle == TRUE) 
          {
	       DynamicDisplayRequest.bits.Motor1Obstacle = FALSE;
	  
	       MessageTx_AntipintchSt = TRUE;
	       MessageTx_AntipintchSt_Timer = 0;
          }
	  else if(DynamicDisplayRequest.bits.Motor2Obstacle == TRUE) 
          {
	       DynamicDisplayRequest.bits.Motor2Obstacle = FALSE;
	  
	       MessageTx_AntipintchSt = TRUE;
	       MessageTx_AntipintchSt_Timer = 0;
          }
  
	  
	  
     }
 
     if(MessageTx_AntipintchSt_Timer >= K_MessageTx_AntipintchSt_Time)
     {
	  MessageTx_AntipintchSt = FALSE; 
     }
     else
     {
	  MessageTx_AntipintchSt_Timer ++;
     }
}
/*********************************************************************************************
** Name:	  MessageTransmit_SysErr(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_SysErr(void)
{      
     if((Motor1_Static_Fault == FaultType_NoFault)
        &&(Motor2_Static_Fault == FaultType_NoFault)
        &&(CinchMotor_Static_Fault == FaultType_NoFault)
        &&(Motor1_Dynamic_Fault == FaultType_NoFault)
        &&(Motor2_Dynamic_Fault == FaultType_NoFault)
        &&(CinchMotor_Dynamic_Fault == FaultType_NoFault)
         &&(HallA1_Dynamic_Fault == FaultType_NoFault)
         &&(HallA2_Dynamic_Fault == FaultType_NoFault))
     {	     
	  MessageTx_SysErr = FALSE;
     }
     else
     {
	  MessageTx_SysErr = TRUE;
     }
}	
	
/*********************************************************************************************
** Name:	  MessageTransmit_SwitchesStatus(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_SwitchesStatus(void)
{   
      MessageTx_PawlSWSt = PawlSwitch_Status;
      MessageTx_FulLockSt = AjarSwitch_Status;
      MessageTx_HafLockSt = UnlatchSwitch_Status;
      MessageTx_LVRSt = PositionSwitch_Status;
      
      MessageTx_DoorHandleSW = OutsideHandleSwitch_Status;
      #ifdef _CONFIG_HandleCloseSwitch
      MessageTx_InDoorCloseSWSt = HandleCloseSwitch_Status;
      #endif
      #ifdef _CONFIG_HandleOpenSwitch
      MessageTx_InDoorOpenSWSt = HandleOpenSwitch_Status;
      #endif
}

/*********************************************************************************************
** Name:	  MessageTransmit_CloserMotorSt(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_CloserMotorSt(void)
{   
     if(TRUE ==  CinchMotor_Working_Status)
     {
	  if(CinchMotor_Direction_Request == Direction_Neutral)
	  {
		MessageTx_CloserMotorSt = _CloserMotorSt_Opening;
	  }
	  else if(CinchMotor_Direction_Request == Direction_Cinch)
	  {
		MessageTx_CloserMotorSt = _CloserMotorSt_Closing;
	  }
	  else
	  {
		MessageTx_CloserMotorSt = _CloserMotorSt_Not_Move;
	  }
     }
     else
     {
	  MessageTx_CloserMotorSt = _CloserMotorSt_Not_Move;
     }
     
      /*if((ActiveLatchMode == LatchPowerCinching))
      {
	   MessageTx_CloserMotorSt = _CloserMotorSt_Closing;
      }
      else if(ActiveLatchMode == LatchFindHomeAfterCinch)
      {
	   MessageTx_CloserMotorSt = _CloserMotorSt_Opening;
      }
      else
      {
	   MessageTx_CloserMotorSt = _CloserMotorSt_Not_Move;
      }*/
}	
/*********************************************************************************************
** Name:	  MessageTransmit_ReleaseLockMotorSt(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_ReleaseLockMotorSt(void)
{ 
     if(TRUE ==  Motor2_Working_Status)
     {
	  if(Motor2_Direction_Request == Direction_Open)
	  {
		MessageTx_ReleaseLockMotorSt = _ReleaseLockMotorSt_Releasing;
	  }
	  else if(Motor2_Direction_Request == Direction_Close)
	  {
		MessageTx_ReleaseLockMotorSt = _ReleaseLockMotorSt_Closing;
	  }
	  else
	  {
		MessageTx_ReleaseLockMotorSt = _ReleaseLockMotorSt_Not_Move;
	  }
     }
     else
     {
	  MessageTx_ReleaseLockMotorSt = _ReleaseLockMotorSt_Not_Move;
     }
     
      /*if(ActiveLatchMode == LatchPowerReleasing)
      {
	   MessageTx_ReleaseLockMotorSt = _ReleaseLockMotorSt_Releasing;
      }
      else if(ActiveLatchMode == LatchFindHomeAfterRelease)
      {
	   MessageTx_ReleaseLockMotorSt = _ReleaseLockMotorSt_Closing;
      }
      else
      {
	   MessageTx_ReleaseLockMotorSt = _ReleaseLockMotorSt_Not_Move;
      }*/
}
/*********************************************************************************************
** Name:	  MessageTransmit_PSDMotorSt(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_PSDMotorSt(void)
{   
     if(TRUE ==  Motor1_Working_Status)
     {
	  if(Motor1_Direction_Request == Direction_Open)
	  {
		if(TRUE == HoldBySmallCurrentStall_Open_Status)
	        {
		      MessageTx_PSDMotorSt = _PSDMotorSt_Hovering;
	        }
		else
		{
		      MessageTx_PSDMotorSt = _PSDMotorSt_Opening;
		}
	  }
	  else if(Motor1_Direction_Request == Direction_Close)
	  {
		MessageTx_PSDMotorSt = _PSDMotorSt_Closing;
	  }
	  else
	  {
		MessageTx_PSDMotorSt = _PSDMotorSt_Not_Move;
	  }
     }
     else
     {
	  MessageTx_PSDMotorSt = _PSDMotorSt_Not_Move;
     }   
}
/*********************************************************************************************
** Name:	  MessageTransmit_DoorStatus(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_DoorStatus(void)
{	
      if((ActiveSystemMode == SystemClosedFully)
         || (ActiveSystemMode == SystemInitDefault))
      {
	   MessageTx_DoorStatus = _DoorStatus_Closed;
      }
      else
      {
	   MessageTx_DoorStatus = _DoorStatus_Opened;
      }
      
}
/*********************************************************************************************
** Name:	  MessageTransmit_KeyModeCtrlCfgFB(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_KeyModeCtrlCfgFB(void)
{
     MessageTx_KeyOpenModeCtrlCfgFB = Vehicle_KeyOpenMode;
     MessageTx_KeyCloseModeCtrlCfgFB = Vehicle_KeyCloseMode;
}
/*********************************************************************************************
** Name:	  MessageTransmit_HazzardReq(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_HazzardReq(void)
{
     static uint16_t MessageTx_ChimeRemind_Timer;    
     if(ChimeRemind_Request != No_Remind)
     {
	  if(ChimeRemind_Request == Remind_1)
	  {
	       ChimeRemind_Request = No_Remind;
	       MessageTx_ChimeRemind = _HazzardReq_Request_1;
	  }
	  else if(ChimeRemind_Request == Remind_2)
	  {
	       ChimeRemind_Request = No_Remind;
	       MessageTx_ChimeRemind = _HazzardReq_Request_2;
	  }
	  else if(ChimeRemind_Request == Remind_3)
	  {
	       ChimeRemind_Request = No_Remind;
	       MessageTx_ChimeRemind = _HazzardReq_Request_3;
	  }
	  
	  MessageTx_ChimeRemind_Timer = 0;
           
     }
        
     if(MessageTx_ChimeRemind_Timer >= K_MessageTx_ChimeRemind_Time)
     {
	  MessageTx_ChimeRemind = _HazzardReq_No_Command;
     }
     else
     {
	  MessageTx_ChimeRemind_Timer ++;
     }
}

/*********************************************************************************************
** Name:	  MessageTransmit_CloseRes(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_CloseRes(void)
{
     static uint16_t MessageTx_CloseRes_Timer;
     static uint8_t MessageTx_CloseRes_Status;
     static uint8_t MessageTx_CloseRes_Source;

     if(((ActiveSystemMode == SystemReleased) && (LastSystemMode == SystemReleased))
       ||((ActiveSystemMode == SystemMechFailure) && (LastSystemMode == SystemMechFailure))
       ||((ActiveSystemMode == SystemOpenedFully) && (LastSystemMode == SystemOpenedFully)))
     {
          if(TRUE == OutsideHandleSwitch_ShortPress_Active) 
          {
	       MessageTx_CloseRes_Source = _CloseRes_outdoorSW_shortpress;
	       MessageTx_CloseRes_Status = TRUE;
	       MessageTx_CloseRes_Timer = 0;	  
	       TriggerSource_Temporary = _TriggerSource_outdoorSW_shortpress_Close;
          }
          #ifdef _CONFIG_FollowOperate_FollowClose
          else if(TRUE == Motor1_FollowClose_FallEdge_Active) 
          {
	       MessageTx_CloseRes_Source = _CloseRes_Follow_down;
	       MessageTx_CloseRes_Status = TRUE;
	       MessageTx_CloseRes_Timer = 0;
	       TriggerSource_Temporary = _TriggerSource_Follow_down;
          }
          #endif
          #ifdef _CONFIG_HandleCloseSwitch
          else if(TRUE == HandleCloseSwitch_LongPress_Active) 
          {
	       MessageTx_CloseRes_Source = _CloseRes_IndoorcloseSW_longpress;
	       MessageTx_CloseRes_Status = TRUE;
	       MessageTx_CloseRes_Timer = 0;
	       TriggerSource_Temporary = _TriggerSource_IndoorcloseSW_longpress;
          }
          else if(TRUE == HandleCloseSwitch_ShortPress_Active) 
          {
	       MessageTx_CloseRes_Source = _CloseRes_IndoorcloseSW_shortpress;
	       MessageTx_CloseRes_Status = TRUE;
	       MessageTx_CloseRes_Timer = 0;
	       TriggerSource_Temporary = _TriggerSource_IndoorcloseSW_shortpress;
          }
          #endif
          else if(TRUE == RKEStepClose_FallEdge_Active) 
          {
	       MessageTx_CloseRes_Source = _CloseRes_RKEclose_longpress;
	       MessageTx_CloseRes_Status = TRUE;
	       MessageTx_CloseRes_Timer = 0;
	       TriggerSource_Temporary = _TriggerSource_RKEclose_longpress;
          }
          else if(TRUE == RKEClose_FallEdge_Active) 
          {
	       MessageTx_CloseRes_Source = _CloseRes_RKEclose_doublepress;
	       MessageTx_CloseRes_Status = TRUE;
	       MessageTx_CloseRes_Timer = 0;
	       TriggerSource_Temporary = _TriggerSource_RKEclose_doublepress;
          }    
          else if(TRUE == VRStepClose_FallEdge_Active) 
          {
	       MessageTx_CloseRes_Source = _CloseRes_CDU_ManualcloseSW;
	       MessageTx_CloseRes_Status = TRUE;
	       MessageTx_CloseRes_Timer = 0;
	       TriggerSource_Temporary = _TriggerSource_CDU_ManualcloseSW;
          }
          else if(TRUE == VRClose_FallEdge_Active) 
          {
	       MessageTx_CloseRes_Source = _CloseRes_CDU_AutocloseSW;
	       MessageTx_CloseRes_Status = TRUE;
	       MessageTx_CloseRes_Timer = 0;
	       TriggerSource_Temporary = _TriggerSource_CDU_AutocloseSW;
          }   
          else if(TRUE == AppStepClose_FallEdge_Active) 
          {
	       MessageTx_CloseRes_Source = _CloseRes_APP_4G_ManualcloseSW;
	       MessageTx_CloseRes_Status = TRUE;
	       MessageTx_CloseRes_Timer = 0;
	       TriggerSource_Temporary = _TriggerSource_APP_4G_ManualcloseSW;
          }
          else if(TRUE == AppClose_FallEdge_Active) 
          {
	       MessageTx_CloseRes_Source = _CloseRes_APP_4G_AutocloseSW;
	       MessageTx_CloseRes_Status = TRUE;
	       MessageTx_CloseRes_Timer = 0;
	       TriggerSource_Temporary = _TriggerSource_APP_4G_AutocloseSW;
          }
          else if(TRUE == BLEStepClose_FallEdge_Active) 
          {
	       MessageTx_CloseRes_Source = _CloseRes_APP_BLE_ManualcloseSW;	 
	       MessageTx_CloseRes_Status = TRUE;
	       MessageTx_CloseRes_Timer = 0;
	       TriggerSource_Temporary = _TriggerSource_APP_BLE_ManualcloseSW;
          }
          else if(TRUE == BLEClose_FallEdge_Active) 
          {
	       MessageTx_CloseRes_Source = _CloseRes_APP_BLE_AutocloseSW;
	       MessageTx_CloseRes_Status = TRUE;
	       MessageTx_CloseRes_Timer = 0;
	       TriggerSource_Temporary = _TriggerSource_APP_BLE_AutocloseSW;
          }
	  #ifdef _CONFIG_VehicleBrake
          else if(TRUE == VehicleBrake_FallEdge_Active) 
          {
	       MessageTx_CloseRes_Source = _CloseRes_Brkpedal;
	       MessageTx_CloseRes_Status = TRUE;
	       MessageTx_CloseRes_Timer = 0;
	       TriggerSource_Temporary = _TriggerSource_Brkpedal;
          }
	  #endif
	  else if(TRUE == AutoStepClose_FallEdge_Active) 
          {
	       MessageTx_CloseRes_Source = _CloseRes_SCU;	 
	       MessageTx_CloseRes_Status = TRUE;
	       MessageTx_CloseRes_Timer = 0;
	       TriggerSource_Temporary = _TriggerSource_SCU_ManualcloseSW;
          }
          else if(TRUE == AutoClose_FallEdge_Active) 
          {
	       MessageTx_CloseRes_Source = _CloseRes_SCU;
	       MessageTx_CloseRes_Status = TRUE;
	       MessageTx_CloseRes_Timer = 0;
	       TriggerSource_Temporary = _TriggerSource_SCU_AutocloseSW;
          }
     }
     
     if(((ActiveSystemMode == SystemPowerOpening) || (ActiveSystemMode == SystemPowerClosing))&&(TRUE == SoftStop_Working_Status))
     {
	  if(TRUE == OutsideHandleSwitch_FallEdge_Active) 
          {
	       MessageTx_CloseRes_Source = _CloseRes_outdoorSW_shortpress;
	       MessageTx_CloseRes_Status = TRUE;
	       MessageTx_CloseRes_Timer = 0;	  
	       TriggerSource_Temporary = _TriggerSource_outdoorSW_shortpress_Close;
          }
	  else if(TRUE == HandleCloseSwitch_FallEdge_Active) 
          {
	       MessageTx_CloseRes_Source = _CloseRes_IndoorcloseSW_shortpress;
	       MessageTx_CloseRes_Status = TRUE;
	       MessageTx_CloseRes_Timer = 0;
	       TriggerSource_Temporary = _TriggerSource_IndoorcloseSW_shortpress;
          } 
     }

     if(TRUE == MessageTx_CloseRes_Status)
     {
          if(MessageTx_CloseRes_Timer >= K_MessageTx_CloseRes_Time)
          {
	      MessageTx_CloseRes_Status = FALSE;
	       if((ActiveSystemMode == SystemPowerClosing) 
                  || (ActiveSystemMode == SystemPowerCinching)
	          || (ActiveSystemMode == SystemPowerParking))
               {
	           MessageTx_CloseRes = MessageTx_CloseRes_Source;
		   
		   TriggerSource = TriggerSource_Temporary;
		   TriggerSource_Active = TRUE;
               }
	  }
          else
          {
	       MessageTx_CloseRes_Timer ++;
          }
     }
}

/*********************************************************************************************
** Name:	  MessageTransmit_OpenRes(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_OpenRes(void)
{
     static uint16_t MessageTx_OPenRes_Timer;
     static uint8_t MessageTx_OPenRes_Status;
     static uint8_t MessageTx_OPenRes_Source;
     
     if(((ActiveSystemMode == SystemReleased) && (LastSystemMode == SystemReleased))
       ||((ActiveSystemMode == SystemMechFailure) && (LastSystemMode == SystemMechFailure))
       ||((ActiveSystemMode == SystemClosedFully) && (LastSystemMode == SystemClosedFully))
       ||((ActiveSystemMode == SystemPowerCinching) && (LastSystemMode == SystemPowerCinching))
       ||((ActiveSystemMode == SystemPowerParking) && (LastSystemMode == SystemPowerParking)))
     {
     if(TRUE == MechanicalHandle_FallEdge_Active)
     {
	  MessageTx_OPenRes_Source = _OPenRes_mechanical_handle;
	  MessageTx_OPenRes_Status = TRUE;
	  MessageTx_OPenRes_Timer = 0;
	  TriggerSource_Temporary = _TriggerSource_mechanical_handle;
     }
     else if(TRUE == OutsideHandleSwitch_LongPress_Active) 
     {
	  MessageTx_OPenRes_Source = _OPenRes_outdoorSW_longpress;
	  MessageTx_OPenRes_Status = TRUE;
	  MessageTx_OPenRes_Timer = 0;
	  TriggerSource_Temporary = _TriggerSource_outdoorSW_longpress;
     }
     else if(TRUE == OutsideHandleSwitch_ShortPress_Active) 
     {
	  MessageTx_OPenRes_Source = _OPenRes_outdoorSW_shortpress;
	  MessageTx_OPenRes_Status = TRUE;
	  MessageTx_OPenRes_Timer = 0;
	  TriggerSource_Temporary = _TriggerSource_outdoorSW_shortpress_Open;
     }
     #ifdef _CONFIG_HandleOpenSwitch
     else if(TRUE == HandleOpenSwitch_LongPress_Active) 
     {
	  MessageTx_OPenRes_Source = _OPenRes_IndooropenSW_longpress;
	  MessageTx_OPenRes_Status = TRUE;
	  MessageTx_OPenRes_Timer = 0;
	  TriggerSource_Temporary = _TriggerSource_IndooropenSW_longpress;
     }
     else if(TRUE == HandleOpenSwitch_ShortPress_Active) 
     {
	  MessageTx_OPenRes_Source = _OPenRes_IndooropenSW_shortpress;	
	  MessageTx_OPenRes_Status = TRUE;
	  MessageTx_OPenRes_Timer = 0;
	  TriggerSource_Temporary = _TriggerSource_IndooropenSW_shortpress;
     }
     #endif
     else if(TRUE == RKEStepOpen_FallEdge_Active) 
     {
	  MessageTx_OPenRes_Source = _OPenRes_RKEopen_longpress;
	  MessageTx_OPenRes_Status = TRUE;
	  MessageTx_OPenRes_Timer = 0;
	  TriggerSource_Temporary = _TriggerSource_RKEopen_longpress;
     }
     else if(TRUE == RKEOpen_FallEdge_Active) 
     {
	  MessageTx_OPenRes_Source = _OPenRes_RKEopen_doublepress;
	  MessageTx_OPenRes_Status = TRUE;
	  MessageTx_OPenRes_Timer = 0;
	  TriggerSource_Temporary = _TriggerSource_RKEopen_doublepress;
     }    
     else if(TRUE == VRStepOpen_FallEdge_Active) 
     {
	  MessageTx_OPenRes_Source = _OPenRes_CDU_ManualopenSW;	
	  MessageTx_OPenRes_Status = TRUE;
	  MessageTx_OPenRes_Timer = 0;
	  TriggerSource_Temporary = _TriggerSource_CDU_ManualopenSW;
     }
     else if(TRUE == VROpen_FallEdge_Active) 
     {
	  MessageTx_OPenRes_Source = _OPenRes_CDU_AutoopenSW;	 
	  MessageTx_OPenRes_Status = TRUE;
	  MessageTx_OPenRes_Timer = 0;
	  TriggerSource_Temporary = _TriggerSource_CDU_AutoopenSW;
     }
     
     else if(TRUE == AppStepOpen_FallEdge_Active) 
     {
	  MessageTx_OPenRes_Source = _OPenRes_APP_4G_ManualopenSW;
	  MessageTx_OPenRes_Status = TRUE;
	  MessageTx_OPenRes_Timer = 0;
	  TriggerSource_Temporary = _TriggerSource_APP_4G_ManualopenSW;
     }
     else if(TRUE == AppOpen_FallEdge_Active) 
     {
	  MessageTx_OPenRes_Source = _OPenRes_APP_4G_AutoopenSW;
	  MessageTx_OPenRes_Status = TRUE;
	  MessageTx_OPenRes_Timer = 0;
	  TriggerSource_Temporary = _TriggerSource_APP_4G_AutoopenSW;
     }
     else if(TRUE == BLEStepOpen_FallEdge_Active) 
     {
	  MessageTx_OPenRes_Source = _OPenRes_APP_BLE_ManualopenSW;
	  MessageTx_OPenRes_Status = TRUE;
	  MessageTx_OPenRes_Timer = 0;
	  TriggerSource_Temporary = _TriggerSource_APP_BLE_ManualopenSW;
     }
     else if(TRUE == BLEOpen_FallEdge_Active) 
     {
	  MessageTx_OPenRes_Source = _OPenRes_APP_BLE_AutoopenSW;
	  MessageTx_OPenRes_Status = TRUE;
	  MessageTx_OPenRes_Timer = 0;
	  TriggerSource_Temporary = _TriggerSource_APP_BLE_AutoopenSW;
     }
          #ifdef _CONFIG_FollowOperate_FollowOpen
          else if(TRUE == Motor1_FollowOpen_FallEdge_Active) 
          {
	       MessageTx_OPenRes_Source = _OPenRes_Follow_up;
	       MessageTx_OPenRes_Status = TRUE;
	       MessageTx_OPenRes_Timer = 0;
	       TriggerSource_Temporary = _TriggerSource_Follow_up;
          }
          #endif
          else if(TRUE == AutoStepOpen_FallEdge_Active) 
          {
	       MessageTx_OPenRes_Source = _OPenRes_SCU;	 
	       MessageTx_OPenRes_Status = TRUE;
	       MessageTx_OPenRes_Timer = 0;
	       TriggerSource_Temporary = _TriggerSource_SCU_ManualopenSW;
          }
          else if(TRUE == AutoOpen_FallEdge_Active) 
          {
	       MessageTx_OPenRes_Source = _OPenRes_SCU;
	       MessageTx_OPenRes_Status = TRUE;
	       MessageTx_OPenRes_Timer = 0;
	       TriggerSource_Temporary = _TriggerSource_SCU_AutoopenSW;
          }
     }
     
     if(((ActiveSystemMode == SystemPowerOpening) || (ActiveSystemMode == SystemPowerClosing))&&(TRUE == SoftStop_Working_Status))
     {
	  if(TRUE == OutsideHandleSwitch_FallEdge_Active) 
          {
	       MessageTx_OPenRes_Source = _OPenRes_outdoorSW_shortpress;
	       MessageTx_OPenRes_Status = TRUE;
	       MessageTx_OPenRes_Timer = 0;
	       TriggerSource_Temporary = _TriggerSource_outdoorSW_shortpress_Open;
          }
	  else if(TRUE == HandleOpenSwitch_FallEdge_Active) 
          {
	       MessageTx_OPenRes_Source = _OPenRes_IndooropenSW_shortpress;	
	       MessageTx_OPenRes_Status = TRUE;
	       MessageTx_OPenRes_Timer = 0;
	       TriggerSource_Temporary = _TriggerSource_IndooropenSW_shortpress;
          }
     }
     
     if(TRUE == MessageTx_OPenRes_Status)
     {	  
          if(MessageTx_OPenRes_Timer >= K_MessageTx_OPenRes_Time)
          {
	       MessageTx_OPenRes_Status = FALSE;
	       if((ActiveSystemMode == SystemPowerOpening) 
                  || (ActiveSystemMode == SystemReleaseToPowerOpen))
               {
	           MessageTx_OPenRes = MessageTx_OPenRes_Source;
		   
		   TriggerSource = TriggerSource_Temporary;
		   TriggerSource_Active = TRUE;

               }
	  }
          else
          {
	       MessageTx_OPenRes_Timer ++;
          }
     }
}

/*********************************************************************************************
** Name:	  MessageTransmit_SysRuningSt(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_SysRuningSt(void)
{
      static uint16_t MessageTx_SysRuningSt_Timer;
      
      if(ActiveSystemMode == SystemOpenedFully)
      {
	   MessageTx_SysRuningSt = _SysRuningSt_Open_finished;
	   MessageTx_SysRuningSt_Timer = 0;
      }
      else if(ActiveSystemMode == SystemClosedFully)
      {
	   MessageTx_SysRuningSt = _SysRuningSt_Closed;
	   MessageTx_SysRuningSt_Timer = 0;
      }
      else if((ActiveSystemMode == SystemPowerOpening) 
            || (ActiveSystemMode == SystemReleaseToPowerOpen)
	    || (ActiveSystemMode == SystemReleaseOnly))
      {
	   MessageTx_SysRuningSt = _SysRuningSt_Opening;
	   MessageTx_SysRuningSt_Timer = 0;
      }
      else if((ActiveSystemMode == SystemPowerClosing) 
            || (ActiveSystemMode == SystemPowerCinching)
	    || (ActiveSystemMode == SystemPowerParking)
	    || (ActiveSystemMode == SystemManualCinching)
	    || (ActiveSystemMode == SystemManualParking))
      {
	   MessageTx_SysRuningSt = _SysRuningSt_Closing;
	   MessageTx_SysRuningSt_Timer = 0;
      }
       else if((ActiveSystemMode == SystemMechFailure)
              || (ActiveLatchMode == LatchMechFailure)
              || ((ActiveLatchMode == LatchFullyCinched) && ((FALSE == LatchCinch_Position_Status))))
      {
	   if(MessageTx_SysRuningSt_Timer >= K_MessageTx_SysRuningSt_Time)
	   {
	        MessageTx_SysRuningSt = _SysRuningSt_Lock_status_error;
	   }
	   else
	   {
		MessageTx_SysRuningSt_Timer ++;
	   }
      }
      else if(ActiveSystemMode == SystemReleased)
      {
	   MessageTx_SysRuningSt_Timer = 0;
			 
	   if((TRUE == PlayTimes_Status) || (TRUE == ObstacleTimes_Total_Status))
	   {
	         MessageTx_SysRuningSt = _SysRuningSt_Prevent_playing_mode;
	   }
	   else
	   {
		if((TRUE == GarageEnd_SoftStop_Position_Status) && (TRUE == GarageLearned_Status))
		 {
		      MessageTx_SysRuningSt = _SysRuningSt_Open_finished;
		 }
		 else
	         {
		      MessageTx_SysRuningSt = _SysRuningSt_Pause;
	         }
	   }
      }
      else if(ActiveSystemMode == SystemInitDefault)
      {
	   MessageTx_SysRuningSt = _SysRuningSt_Initial;
	   MessageTx_SysRuningSt_Timer = 0;
      }
      else
      {
	   MessageTx_SysRuningSt_Timer = 0;
      }

}
/*********************************************************************************************
** Name:	  MessageTransmit_PSDMotorFR(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_PSDMotorFR(void)
{
     static uint16_t MessageTx_PSDMotorFR_Timer;
     static uint8_t MessageTx_PSDMotorFR_Status;
     
     if((TRUE == HallA1_NoHall_DTCStatus.bits.TestFailed)
	 ||(TRUE == HallA2_NoHall_DTCStatus.bits.TestFailed))
     {
	  MessageTx_PSDMotorFR = _PSDMotorFR_Hall_Error;
	  
	  MessageTx_PSDMotorFR_Status = TRUE;
	  MessageTx_PSDMotorFR_Timer = 0;
     }
     else if((TRUE == Motor1_STG_DTCStatus.bits.TestFailed) 
           ||(TRUE == Motor1_STB_DTCStatus.bits.TestFailed)
	   ||(TRUE == Motor1_OC_DTCStatus.bits.TestFailed))
     {
	  MessageTx_PSDMotorFR = _PSDMotorFR_PSDMotor_Error;
	  
	  MessageTx_PSDMotorFR_Status = TRUE;
	  MessageTx_PSDMotorFR_Timer = 0;
     }
     else if(TRUE == Motor1_WorkingTimeout_Status)
     {
	  MessageTx_PSDMotorFR = _PSDMotorFR_Overtime_Error;
	  
	  MessageTx_PSDMotorFR_Status = TRUE;
	  MessageTx_PSDMotorFR_Timer = 0;
     }
     else if(TRUE == DynamicDisplayRequest.bits.Spindle1MotorStall)
     {
	  DynamicDisplayRequest.bits.Spindle1MotorStall = FALSE;
	  MessageTx_PSDMotorFR = _PSDMotorFR_Stall_Error;
	  
	  MessageTx_PSDMotorFR_Status = TRUE;
	  MessageTx_PSDMotorFR_Timer = 0;
     }
     else if(TRUE == Motor1_ThermalProtection_Status)
     {
	  MessageTx_PSDMotorFR = _PSDMotorFR_Overheating_Error;
	  
	  MessageTx_PSDMotorFR_Status = TRUE;
	  MessageTx_PSDMotorFR_Timer = 0;
     }
     else if(TRUE == Latch_Cinch_Fault_Status)
     {
	  MessageTx_PSDMotorFR = _PSDMotorFR_CloseMotor_Error;
	  
	  MessageTx_PSDMotorFR_Status = TRUE;
	  MessageTx_PSDMotorFR_Timer = 0;
     }
     else if(TRUE == CurrentDynamicTelltales.bits.Motor1Obstacle)//(TRUE == MessageTx_AntipintchSt)
     {
	  MessageTx_PSDMotorFR = _PSDMotorFR_AntipintchSt_Error;
	  
	  MessageTx_PSDMotorFR_Status = TRUE;
	  MessageTx_PSDMotorFR_Timer = 0;
     }
     
     if(TRUE == MessageTx_PSDMotorFR_Status)
     {	  
          if(MessageTx_PSDMotorFR_Timer >= K_MessageTx_PSDMotorFR_Time)
          {
	       MessageTx_PSDMotorFR = _PSDMotorFR_No_Error;
	       
	       MessageTx_PSDMotorFR_Status = FALSE;
	       MessageTx_PSDMotorFR_Timer = 0;
	  }
          else
          {
	       MessageTx_PSDMotorFR_Timer ++;
          }
     }

}
/*********************************************************************************************
** Name:	  MessageTransmit_CloserMotorFR(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_CloserMotorFR(void)
{
     static uint16_t MessageTx_CloserMotorFR_Timer;
     static uint8_t MessageTx_CloserMotorFR_Status;
     
     if((CinchMotor_StopCause == StopCause_MotorFault)
       ||(TRUE == CinchMotor_STG_DTCStatus.bits.TestFailed) 
       ||(TRUE == CinchMotor_STB_DTCStatus.bits.TestFailed)
       ||(TRUE == CinchMotor_OC_DTCStatus.bits.TestFailed))
     {
	  MessageTx_CloserMotorFR = _CloserMotorFR_CloserMotor_Error;
	  
	  MessageTx_CloserMotorFR_Status = TRUE;
	  MessageTx_CloserMotorFR_Timer = 0;
     }
     else if(CinchMotor_StopCause == StopCause_Timeout)
     {
	  MessageTx_CloserMotorFR = _CloserMotorFR_Overtime_Error;
	  
	  MessageTx_CloserMotorFR_Status = TRUE;
	  MessageTx_CloserMotorFR_Timer = 0;
     }
     else if(CinchMotor_StopCause == StopCause_MotorStall)
     {
	  MessageTx_CloserMotorFR = _CloserMotorFR_Stall_Error;
	  
	  MessageTx_CloserMotorFR_Status = TRUE;
	  MessageTx_CloserMotorFR_Timer = 0;
     }
     /*else if(CinchMotor_StopCause == StopCause_Thermal)
     {
	  MessageTx_CloserMotorFR = ;
	  
	  MessageTx_CloserMotorFR_Status = TRUE;
	  MessageTx_CloserMotorFR_Timer = 0;
     }*/
     else if(CinchMotor_StopCause == StopCause_OutofLatch)
     {
	  MessageTx_CloserMotorFR = _CloserMotorFR_Abnormal_Open_Error;
	  
	  MessageTx_CloserMotorFR_Status = TRUE;
	  MessageTx_CloserMotorFR_Timer = 0;
     }
     
     
     if(TRUE == MessageTx_CloserMotorFR_Status)
     {	  
          if(MessageTx_CloserMotorFR_Timer >= K_MessageTx_CloserMotorFR_Time)
          {
	       MessageTx_CloserMotorFR = _CloserMotorFR_No_Error;
	       
	       MessageTx_CloserMotorFR_Status = FALSE;
	       MessageTx_CloserMotorFR_Timer = 0;
	  }
          else
          {
	       MessageTx_CloserMotorFR_Timer ++;
          }
     }
}
/*********************************************************************************************
** Name:	  MessageTransmit_ReleaseLockMotorFR(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_ReleaseLockMotorFR(void)
{
     static uint16_t MessageTx_ReleaseLockMotorFR_Timer;
     static uint8_t MessageTx_ReleaseLockMotorFR_Status;
     
     if((ReleaseMotor_StopCause == StopCause_MotorFault)
       ||(TRUE == Motor2_STG_DTCStatus.bits.TestFailed) 
       ||(TRUE == Motor2_STB_DTCStatus.bits.TestFailed)
       ||(TRUE == Motor2_OC_DTCStatus.bits.TestFailed))
     {
	  MessageTx_ReleaseLockMotorFR = _ReleaseLockMotorFR_ReleaseLockMotor_Error;
	  
	  MessageTx_ReleaseLockMotorFR_Status = TRUE;
	  MessageTx_ReleaseLockMotorFR_Timer = 0;
     }
     else if(ReleaseMotor_StopCause == StopCause_Timeout)
     {
	  MessageTx_ReleaseLockMotorFR = _ReleaseLockMotorFR_Overtime_Error;
	  
	  MessageTx_ReleaseLockMotorFR_Status = TRUE;
	  MessageTx_ReleaseLockMotorFR_Timer = 0;
     }
     else if(ReleaseMotor_StopCause == StopCause_MotorStall)
     {
	  MessageTx_ReleaseLockMotorFR = _ReleaseLockMotorFR_Stall_Error;
	  
	  MessageTx_ReleaseLockMotorFR_Status = TRUE;
	  MessageTx_ReleaseLockMotorFR_Timer = 0;
     }
     /*else if(ReleaseMotor_StopCause == StopCause_Thermal)
     {
	  MessageTx_ReleaseLockMotorFR = ;
	  
	  MessageTx_ReleaseLockMotorFR_Status = TRUE;
	  MessageTx_ReleaseLockMotorFR_Timer = 0;
     }*/
     
     
     if(TRUE == MessageTx_ReleaseLockMotorFR_Status)
     {	  
          if(MessageTx_ReleaseLockMotorFR_Timer >= K_MessageTx_ReleaseLockMotorFR_Time)
          {
	       MessageTx_ReleaseLockMotorFR = _ReleaseLockMotorFR_No_Error;
	       
	       MessageTx_ReleaseLockMotorFR_Status = FALSE;
	       MessageTx_ReleaseLockMotorFR_Timer = 0;
	  }
          else
          {
	       MessageTx_ReleaseLockMotorFR_Timer ++;
          }
     }
}

/*********************************************************************************************
** Name:	  MessageTransmit_AA(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_AA(void)
{
     MessageTx_AA = Motor1_Current/50;
}
/*********************************************************************************************
** Name:	  MessageTransmit_PWMSt(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_PWMSt(void)
{   
     MessageTx_PWMSt = Motor1_Duty_Request/40;
}

/*********************************************************************************************
** Name:	  MessageTransmit_DataUpload_St(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_DataUpload_St(void)
{
     static uint16_t MessageTx_DataUpload_St_Timer;
     static uint8_t MessageTx_DataUpload_St_Status;
     static uint8_t MessageTx_DataUpload_St_LastStatus;
     
     MessageTx_DataUpload_St_LastStatus = MessageTx_DataUpload_St_Status;
     
     if((MessageTx_SysErr == TRUE)
        ||(MessageTx_SysRuningSt == _SysRuningSt_Lock_status_error)
	||(MessageTx_SysRuningSt == _SysRuningSt_Prevent_playing_mode)
	||(MessageTx_ReleaseLockMotorFR != _ReleaseLockMotorFR_No_Error)
	||(MessageTx_CloserMotorFR != _CloserMotorFR_No_Error)
	||(MessageTx_PSDMotorFR != _PSDMotorFR_No_Error))
     {	  
	  MessageTx_DataUpload_St_Status = TRUE;
     }
     else
     {
	  MessageTx_DataUpload_St_Status = FALSE;
     }
     
     if((TRUE == MessageTx_DataUpload_St_Status) && (FALSE == MessageTx_DataUpload_St_LastStatus))
     {
	  MessageTx_DataUpload_St = TRUE;
	  MessageTx_DataUpload_St_Status = TRUE;
	  MessageTx_DataUpload_St_Timer = 0;
     }
     
     if(TRUE == MessageTx_DataUpload_St_Status)
     {	  
          if(MessageTx_DataUpload_St_Timer >= K_MessageTx_DataUpload_St_Time)
          {
	       MessageTx_DataUpload_St = FALSE;	       
	  }
          else
          {
	       MessageTx_DataUpload_St_Timer ++;
          }
     }
}
/*********************************************************************************************
** Name:	  MessageTransmit_LatchSwitch(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_LatchSwitch(void)
{
      MessageTx_PawlSwitch = PawlSwitch_Status;
      MessageTx_SecondarySwitch = SecondarySwitch_Status;
      MessageTx_PositonSwitch = PositionSwitch_Status;
      #ifdef _CONFIG_ShutFaceSwitch
      MessageTx_ShutFaceSwitch = ShutFaceSwitch_Status;
      #endif
}

/*********************************************************************************************
** Name:	  MessageTransmit_GateOpenAngle(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_GateOpenAngle(void)
{
     if(TRUE == SystemLearned_Status)
     {
           MessageTx_GateOpenAngle = (uint16_t)((uint32_t)(Motor1_Position * 100) / SystemLearned_Position);
	   MessageTx_GateOpenAngle_Valid = TRUE;
     }
     else
     {
	   MessageTx_GateOpenAngle = (uint16_t)((uint32_t)(Motor1_Position * 100) / K_SystemLearned_Position_Default);
	   MessageTx_GateOpenAngle_Valid = TRUE;
     }
     
     if(MessageTx_GateOpenAngle > K_MessageTx_GateOpenAngle_Max)
     {
	  MessageTx_GateOpenAngle = K_MessageTx_GateOpenAngle_Max;
     }	
     
     MessageTx_LPoleHALLCounter = (Motor1_Position/2);
     //MessageTx_LPoleHALLCounter_raw = Motor1_Position;
	
}
/*********************************************************************************************
** Name:	  MessageTransmit_GaragePosition(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_GaragePosition(void)
{
    if(FALSE == GarageHeightRequest_Process_Status)
    {      
        if(TRUE == SystemLearned_Status)
        {
            if(TRUE == GarageLearned_Status)
            {
                 MessageTx_GaragePosition = (uint16_t)((uint32_t)(GarageLearned_Position * 100) / SystemLearned_Position);
	         MessageTx_GaragePosition_Remainder = (uint16_t)((uint32_t)(GarageLearned_Position * 100) % SystemLearned_Position);
            }
            else
            {
	         MessageTx_GaragePosition = (uint16_t)((uint32_t)(SystemLearned_Position * 100) / SystemLearned_Position);	       
            }
        }
        else
        {
	    if(TRUE == GarageLearned_Status)
            {
                 MessageTx_GaragePosition = (uint16_t)((uint32_t)(GarageLearned_Position * 100) / K_SystemLearned_Position_Default);
	         MessageTx_GaragePosition_Remainder = (uint16_t)((uint32_t)(GarageLearned_Position * 100) % K_SystemLearned_Position_Default);                        
            }
            else
            {
	         MessageTx_GaragePosition = (uint16_t)((uint32_t)(SystemLearned_Position * 100) / K_SystemLearned_Position_Default);
	       
            }
        }
    
        if(MessageTx_GaragePosition_Remainder > 0)
        {
	     MessageTx_GaragePosition += K_GaragePosition_Precision_Compensation;
        }
    
        if(MessageTx_GaragePosition > K_MessageTx_GateOpenAngle_Max)
        {
	     MessageTx_GaragePosition = K_MessageTx_GateOpenAngle_Max;
        }
    }
    /*else
    {
	 MessageTx_GaragePosition = MessageRx_GarageHeight;
    }*/
    
}
/*********************************************************************************************
** Name:	  MessageTransmit_LearnStatus(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_LearnStatus(void)
{
       MessageTx_SystemLearnedStatus = SystemLearned_Status;
       MessageTx_GarageLearnedStatus = GarageLearned_Status;
       #ifdef _CONFIG_ShutFaceSwitch
       MessageTx_GarageLearnAction = ShutFaceSwitch_LongPress_Status;
       #endif
       MessageTx_SystemLearnFailure = System_Learn_Failure;
}
#endif

#ifdef _SGM_COM 
/*********************************************************************************************
** Name:	  MessageTransmit_EventMessage_Monitor(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_EventMessage_Monitor(void)
{
     static uint8_t MessageTx_EventMessage_Timer_Status;
     static uint16_t MessageTx_EventMessage_Timer;

     if((TRUE == OutsideHandleSwitch_FallEdge_Command_Active)
        ||(TRUE == OpenCloseSwitch_FallEdge_Command_Active)
        ||(TRUE == ShutFaceSwitch_FallEdge_Command_Active)
	||(TRUE == HandFreeSwitch_FallEdge_Command_Active)
        ||(TRUE == TouchPad_FallEdge_Command_Active)
        ||(TRUE == FobLongPress_FallEdge_Command_Active) 	
        ||(TRUE == FobShortPress_FallEdge_Command_Active)
        ||(TRUE == ComfortClose_FallEdge_Command_Active)
	||(TRUE == RemoteKey_FallEdge_Command_Active)
        ||(TRUE == VirtualButton_FallEdge_Command_Active))
     {	  
	  MessageTx_EventMessage_Timer_Status = TRUE;
	  MessageTx_EventMessage_Timer = 0;
	  
	  Com_ActiveSig(COM_TXSIGPwrLftgtMotStat);
          Com_SetSendRequest(COM_TXSIGPwrLftgtMotStat);
     }
     else if((TRUE == PositionSwitch_FallEdge_Active)
            ||(TRUE == PawlSwitch_FallEdge_Active)
            ||(TRUE == SecondarySwitch_FallEdge_Active))
     {
	  MessageTx_EventMessage_Timer_Status = TRUE;
	  MessageTx_EventMessage_Timer = 0;
	  
	  Com_ActiveSig(COM_TXSIGPwrLftgtMotStat);
	  Com_SetSendRequest(COM_TXSIGPwrLftgtMotStat);
     }
     else if((TRUE == Motor1_FollowClose_Command_Active)
            ||(TRUE == FollowOperate_SlamClose_Command_Active)
	    ||(TRUE == Motor1_ManualMoving_FallEdge_Active))
     {
	  MessageTx_EventMessage_Timer_Status = TRUE;
	  MessageTx_EventMessage_Timer = 0;
	  
	  Com_ActiveSig(COM_TXSIGPwrLftgtMotStat);
	  Com_SetSendRequest(COM_TXSIGPwrLftgtMotStat);
     }
     else if((ActiveSystemMode == SystemReleaseToPowerOpen)
             ||(ActiveSystemMode == SystemPowerOpening)
	     ||(ActiveSystemMode == SystemPowerClosing) 
             ||(ActiveSystemMode == SystemPowerCinching)
	     ||(ActiveSystemMode == SystemPowerParking)
	     ||(ActiveSystemMode == SystemManualCinching)
	     ||(ActiveSystemMode == SystemManualParking)
	     ||(TRUE == Motor1_ManualMoving_Status))
     {
	  MessageTx_EventMessage_Timer_Status = TRUE;
	  MessageTx_EventMessage_Timer = 0;
	  
	  Com_ActiveSig(COM_TXSIGPwrLftgtMotStat);
	  Com_SetSendRequest(COM_TXSIGPwrLftgtMotStat);
     }

     if(TRUE == MessageTx_EventMessage_Timer_Status)
     {
         if(MessageTx_EventMessage_Timer >= K_MessageTx_EventMessage_Time)
         {
	       MessageTx_EventMessage_Timer_Status = FALSE; 
	       MessageTx_EventMessage_Timer = 0;
	       
	       Com_DisactiveSig(COM_TXSIGPwrLftgtMotStat);
	       Com_SetSendRequest(COM_TXSIGPwrLftgtMotStat);
         }
         else
         {
	       MessageTx_EventMessage_Timer ++;
         }
     }
}
/*********************************************************************************************
** Name:	  MessageTransmit_PwrLftgtMotStat(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_PwrLftgtMotStat(void)
{     		
      if(ActiveSystemMode == SystemOpenedFully)
      {
	   MessageTx_PwrLftgtMotStat = _PwrLftgtMotStat_Full_Open;
      }
      else if(ActiveSystemMode == SystemClosedFully)
      {
	   MessageTx_PwrLftgtMotStat = _PwrLftgtMotStat_Closed;
      }
      else if((ActiveSystemMode == SystemPowerOpening) 
            || (ActiveSystemMode == SystemReleaseToPowerOpen))
      {
	   MessageTx_PwrLftgtMotStat = _PwrLftgtMotStat_Opening;
      }
      else if((ActiveSystemMode == SystemPowerClosing) 
            || (ActiveSystemMode == SystemPowerCinching)
	    || (ActiveSystemMode == SystemPowerParking))
      {
	   MessageTx_PwrLftgtMotStat = _PwrLftgtMotStat_Closing;
      }
      else if(ActiveSystemMode == SystemReleased) 
      {
	   MessageTx_PwrLftgtMotStat = _PwrLftgtMotStat_Stopped;
      }
      else if(ActiveSystemMode == SystemMechFailure)
      {
	   MessageTx_PwrLftgtMotStat = _PwrLftgtMotStat_Unknown;
      }
}

/*********************************************************************************************
** Name:	  MessageTransmit_RrClsrObstclDtctd(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_RrClsrObstclDtctd(void)
{
             /**/
     static uint16_t MessageTx_RrClsrObstclDtctd_Timer;

     if(TRUE == VehicleLock_Status)
     {
          if(DynamicDisplayRequest.bits.Motor1Obstacle == TRUE)
          {
	       DynamicDisplayRequest.bits.Motor1Obstacle = FALSE;
	  
	       MessageTx_RrClsrObstclDtctd = TRUE;
	       MessageTx_RrClsrObstclDtctd_Timer = 0;
	       
	       Com_ActiveSig(COM_TXSIGRrClsrObstclDtctd);
	       Com_SetSendRequest(COM_TXSIGRrClsrObstclDtctd);
          }
          else if(StaticDisplayRequest.bits.AntipinchPressed == TRUE) 
          {
	       StaticDisplayRequest.bits.AntipinchPressed = FALSE;
	  
	       MessageTx_RrClsrObstclDtctd = TRUE;
	       MessageTx_RrClsrObstclDtctd_Timer = 0;
	       
	       Com_ActiveSig(COM_TXSIGRrClsrObstclDtctd);
	       Com_SetSendRequest(COM_TXSIGRrClsrObstclDtctd);
         }
     }
 
     if(MessageTx_RrClsrObstclDtctd_Timer >= K_MessageTx_RrClsrObstclDtctd_Time)
     {
	  MessageTx_RrClsrObstclDtctd = FALSE; 
	  Com_DisactiveSig(COM_TXSIGRrClsrObstclDtctd);
	  Com_SetSendRequest(COM_TXSIGRrClsrObstclDtctd);
     }
     else
     {
	  MessageTx_RrClsrObstclDtctd_Timer ++;
     }
}
/*********************************************************************************************
** Name:	  MessageTransmit_RrClosOpenSwAct(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_RrClosOpenSwAct(void)
{
     /**/
     if(TRUE == OutsideHandleSwitch_Status)
     {	  
	   MessageTx_RrClosOpenSwAct = TRUE;
     }
     else if(FALSE == OutsideHandleSwitch_Status)
     {
	   MessageTx_RrClosOpenSwAct = FALSE;
     }
}

/*********************************************************************************************
** Name:	  MessageTransmit_RrClsrInMtn(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_RrClsrInMtn(void)
{
      if((ActiveSystemMode == SystemPowerOpening) 
         || (ActiveSystemMode == SystemReleaseToPowerOpen))
      {
	    MessageTx_RrClsrInMtn = TRUE;
      }
      else if((ActiveSystemMode == SystemPowerClosing) 
            || (ActiveSystemMode == SystemPowerCinching)
	    || (ActiveSystemMode == SystemPowerParking))
      {
	    MessageTx_RrClsrInMtn = TRUE;
      }
      else
      {
	    MessageTx_RrClsrInMtn = FALSE;
      }
}

/*********************************************************************************************
** Name:	  MessageTransmit_RrClosRelSwAct(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_RrClosRelSwAct(void)
{
     static uint8_t MessageTx_RrClosRelSwAct_Timer_Status;
     static uint16_t MessageTx_RrClosRelSwAct_Timer;
     
     if((TRUE == OutsideHandleSwitch_Status) ||(TRUE == TouchPad_Status))
     {	  
	   MessageTx_RrClosRelSwAct = TRUE;
     }
     else if((FALSE == OutsideHandleSwitch_Status) && (FALSE == TouchPad_Status))
     {
	   MessageTx_RrClosRelSwAct = FALSE;
     }
     
     if((TRUE == OutsideHandleSwitch_FallEdge_Active) ||(TRUE == TouchPad_FallEdge_Active)
       ||(TRUE == OutsideHandleSwitch_RiseEdge_Active) ||(TRUE == TouchPad_RiseEdge_Active))
     {
	  Com_ActiveSig(COM_TXSIGRrClosRelSwAct);
	  Com_SetSendRequest(COM_TXSIGRrClosRelSwAct);
	  
	  MessageTx_RrClosRelSwAct_Timer_Status = TRUE;
          MessageTx_RrClosRelSwAct_Timer = 0;
     }
     
     if(TRUE == MessageTx_RrClosRelSwAct_Timer_Status)
     {
	  if(MessageTx_RrClosRelSwAct_Timer >= K_MessageTx_RrClosRelSwAct_Time)
	  {
		 MessageTx_RrClosRelSwAct_Timer_Status = FALSE;
		
		 Com_DisactiveSig(COM_TXSIGRrClosRelSwAct);
	         Com_SetSendRequest(COM_TXSIGRrClosRelSwAct);
	  }
	  else
	  {
		 MessageTx_RrClosRelSwAct_Timer ++;
	  }
     }
}

/*********************************************************************************************
** Name:	  MessageTransmit_RrClosAjarSwActPLG(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_RrClosAjarSwActPLG(void)
{   
     static uint8_t MessageTx_RrClosAjarSwActPLG_Timer_Status;
     static uint16_t MessageTx_RrClosAjarSwActPLG_Timer;
     
     #ifdef _CONFIG_InginLatch	
     if(TRUE == PawlSwitch_Status)
     {	  
	   MessageTx_RrClosAjarSwActPLG = TRUE;
     }
     else if(FALSE == PawlSwitch_Status)
     {
	   MessageTx_RrClosAjarSwActPLG = FALSE;
     }
     
     if((TRUE == PawlSwitch_FallEdge_Active)
       ||(TRUE == PawlSwitch_RiseEdge_Active))
     {
	   Com_ActiveSig(COM_TXSIGRrClosAjarSwActPLG);
	   Com_SetSendRequest(COM_TXSIGRrClosAjarSwActPLG);
	   
	   MessageTx_RrClosAjarSwActPLG_Timer_Status = TRUE;
	   MessageTx_RrClosAjarSwActPLG_Timer = 0;
     }
     #endif
     #ifdef _CONFIG_WitteLatch_SGM	
     if(TRUE == AjarSwitch_Status)
     {	  
	   MessageTx_RrClosAjarSwActPLG = TRUE;
     }
     else if(FALSE == AjarSwitch_Status)
     {
	   MessageTx_RrClosAjarSwActPLG = FALSE;
     }
     
     if((TRUE == PrimarySwitch_FallEdge_Active)
       ||(TRUE == PrimarySwitch_RiseEdge_Active))
     {
	  Com_ActiveSig(COM_TXSIGRrClosAjarSwActPLG);
	  Com_SetSendRequest(COM_TXSIGRrClosAjarSwActPLG);
	  
	  MessageTx_RrClosAjarSwActPLG_Timer_Status = TRUE;
	  MessageTx_RrClosAjarSwActPLG_Timer = 0;
     }
     #endif
     
     if(TRUE == MessageTx_RrClosAjarSwActPLG_Timer_Status)
     {
	  if(MessageTx_RrClosAjarSwActPLG_Timer >= K_MessageTx_RrClosAjarSwActPLG_Time)
	  {
		 MessageTx_RrClosAjarSwActPLG_Timer_Status = FALSE;
		
		 Com_DisactiveSig(COM_TXSIGRrClosAjarSwActPLG);
	         Com_SetSendRequest(COM_TXSIGRrClosAjarSwActPLG);
	  }
	  else
	  {
		 MessageTx_RrClosAjarSwActPLG_Timer ++;
	  }
     }
}

/*********************************************************************************************
** Name:	  MessageTransmit_RrClsrSnwLdIO(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_RrClsrSnwLdIO(void)
{
     if(TRUE == LatchSnowLoad_Status)
     {	  
	   MessageTx_RrClsrSnwLdIO = TRUE;
     }
     else if(FALSE == LatchSnowLoad_Status)
     {
	   MessageTx_RrClsrSnwLdIO = FALSE;
     }

}

/*********************************************************************************************
** Name:	  MessageTransmit_Alarm_1_Request(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_Alarm_1_Request(void)
{
}

/*********************************************************************************************
** Name:	  MessageTransmit_Chime_Command_PLG(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_Chime_Command_PLG(void)
{ 
     static uint8_t MessageTx_Chime_Command_PLG_Timer_Status;
     static uint16_t MessageTx_Chime_Command_PLG_Timer;
     
     static uint8_t MessageTx_Chime_Command_PLG_Start_Timer_Status;
     static uint16_t MessageTx_Chime_Command_PLG_Start_Timer;
	
     if(ChimeRemind_Request != No_Remind)
     {
	  if(ChimeRemind_Request == Remind_1)
	  {
	       ChimeRemind_Request = No_Remind;
	       MessageTx_ChimeRemind = _Chime_Comand_PLG_1;
	       
	      TxIpduPLG_0x2A4.Ipdu.SC_SndTne = 0x06;
	      TxIpduPLG_0x2A4.Ipdu.SndLocRtRr = 0x01;
	      TxIpduPLG_0x2A4.Ipdu.SndLocLftRr = 0x01;
	      TxIpduPLG_0x2A4.Ipdu.SndLocPasFr = 0x01;
	      TxIpduPLG_0x2A4.Ipdu.SndLocDrFr = 0x01;
	      TxIpduPLG_0x2A4.Ipdu.SC_SndCdnPrd = 0x3C;
	      TxIpduPLG_0x2A4.Ipdu.SC_NmofRp = 0x0F;
	      TxIpduPLG_0x2A4.Ipdu.SC_SndDutCyc = 0xFF;
	      TxIpduPLG_0x2A4.Ipdu.SndPriority = 0x78;
	      
	      MessageTx_Chime_Command_PLG_Start_Timer_Status = TRUE;
	      MessageTx_Chime_Command_PLG_Start_Timer = 0;
	       
	       //Com_ActiveSig(COM_TXSIGSC_NmofRp);
	       //Com_SetSendRequest(COM_TXSIGSC_NmofRp);
	       
	       //MessageTx_Chime_Command_PLG_Timer_Status = TRUE;
               //MessageTx_Chime_Command_PLG_Timer = 0;
	  }
	  else if(ChimeRemind_Request == Remind_2)
	  {
	       ChimeRemind_Request = No_Remind;
	       MessageTx_ChimeRemind = _Chime_Comand_PLG_2;
	       
	      TxIpduPLG_0x2A4.Ipdu.SC_SndTne = 0x06;
	      TxIpduPLG_0x2A4.Ipdu.SndLocRtRr = 0x01;
	      TxIpduPLG_0x2A4.Ipdu.SndLocLftRr = 0x01;
	      TxIpduPLG_0x2A4.Ipdu.SndLocPasFr = 0x01;
	      TxIpduPLG_0x2A4.Ipdu.SndLocDrFr = 0x01;
	      TxIpduPLG_0x2A4.Ipdu.SC_SndCdnPrd = 0x3C;
	      TxIpduPLG_0x2A4.Ipdu.SC_NmofRp = 0x00;
	      TxIpduPLG_0x2A4.Ipdu.SC_SndDutCyc = 0xFF;
	      TxIpduPLG_0x2A4.Ipdu.SndPriority = 0x78;
	      
	      MessageTx_Chime_Command_PLG_Start_Timer_Status = TRUE;
	      MessageTx_Chime_Command_PLG_Start_Timer = 0;
	       
	       //Com_ActiveSig(COM_TXSIGSC_NmofRp);
	       //Com_SetSendRequest(COM_TXSIGSC_NmofRp);
	       
	       //MessageTx_Chime_Command_PLG_Timer_Status = TRUE;
               //MessageTx_Chime_Command_PLG_Timer = 0;
	  }
	  else if(ChimeRemind_Request == Remind_3)
	  {
	       ChimeRemind_Request = No_Remind;
	       MessageTx_ChimeRemind = _Chime_Comand_PLG_3;
	       
	      TxIpduPLG_0x2A4.Ipdu.SC_SndTne = 0x06;
	      TxIpduPLG_0x2A4.Ipdu.SndLocRtRr = 0x01;
	      TxIpduPLG_0x2A4.Ipdu.SndLocLftRr = 0x01;
	      TxIpduPLG_0x2A4.Ipdu.SndLocPasFr = 0x01;
	      TxIpduPLG_0x2A4.Ipdu.SndLocDrFr = 0x01;
	      TxIpduPLG_0x2A4.Ipdu.SC_SndCdnPrd = 0x3C;
	      TxIpduPLG_0x2A4.Ipdu.SC_NmofRp = 0x00;
	      TxIpduPLG_0x2A4.Ipdu.SC_SndDutCyc = 0xFF;
	      TxIpduPLG_0x2A4.Ipdu.SndPriority = 0x78;
	      
	      MessageTx_Chime_Command_PLG_Start_Timer_Status = TRUE;
	      MessageTx_Chime_Command_PLG_Start_Timer = 0;
	       
	       //Com_ActiveSig(COM_TXSIGSC_NmofRp);
	       //Com_SetSendRequest(COM_TXSIGSC_NmofRp);
	       
	       //MessageTx_Chime_Command_PLG_Timer_Status = TRUE;
               //MessageTx_Chime_Command_PLG_Timer = 0;
	  }
	  else if(ChimeRemind_Request == Remind_4)
	  {
	       ChimeRemind_Request = No_Remind;
	       MessageTx_ChimeRemind = _Chime_Comand_PLG_4;
	       
	      TxIpduPLG_0x2A4.Ipdu.SC_SndTne = 0x06;
	      TxIpduPLG_0x2A4.Ipdu.SndLocRtRr = 0x01;
	      TxIpduPLG_0x2A4.Ipdu.SndLocLftRr = 0x01;
	      TxIpduPLG_0x2A4.Ipdu.SndLocPasFr = 0x01;
	      TxIpduPLG_0x2A4.Ipdu.SndLocDrFr = 0x01;
	      TxIpduPLG_0x2A4.Ipdu.SC_SndCdnPrd = 0x3C;
	      TxIpduPLG_0x2A4.Ipdu.SC_NmofRp = 0x02;
	      TxIpduPLG_0x2A4.Ipdu.SC_SndDutCyc = 0xFF;
	      TxIpduPLG_0x2A4.Ipdu.SndPriority = 0x78;
	      
	      MessageTx_Chime_Command_PLG_Start_Timer_Status = TRUE;
	      MessageTx_Chime_Command_PLG_Start_Timer = 0;
	       
	       //Com_ActiveSig(COM_TXSIGSC_NmofRp);
	       //Com_SetSendRequest(COM_TXSIGSC_NmofRp);
	       
	       //MessageTx_Chime_Command_PLG_Timer_Status = TRUE;
               //MessageTx_Chime_Command_PLG_Timer = 0;
	  }
     }
     
     
     if(TRUE == MessageTx_Chime_Command_PLG_Start_Timer_Status)
     {
	   if(MessageTx_Chime_Command_PLG_Start_Timer >= 20)
	   {
		Com_ActiveSig(COM_TXSIGSC_NmofRp);
	        Com_SetSendRequest(COM_TXSIGSC_NmofRp);
	       
		MessageTx_Chime_Command_PLG_Timer_Status = TRUE;
                MessageTx_Chime_Command_PLG_Timer = 0;
	       
	       MessageTx_Chime_Command_PLG_Start_Timer_Status = FALSE;
               MessageTx_Chime_Command_PLG_Start_Timer = 0;
	   }
	   else
	   {
		MessageTx_Chime_Command_PLG_Start_Timer ++;
	   }
     }
     
     
     if(TRUE == MessageTx_Chime_Command_PLG_Timer_Status)
     {
	  if(MessageTx_Chime_Command_PLG_Timer >= K_MessageTx_Chime_Command_PLG_Time)
	  {
		 MessageTx_Chime_Command_PLG_Timer_Status = FALSE;
		
		 Com_DisactiveSig(COM_TXSIGSC_NmofRp);
	         Com_SetSendRequest(COM_TXSIGSC_NmofRp);
	  }
	  else
	  {
		 MessageTx_Chime_Command_PLG_Timer ++;
	  }
     }
        
}
/*********************************************************************************************
** Name:	  MessageTransmit_GateOpenAngle(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_GateOpenAngle(void)
{
     if(TRUE == SystemLearned_Status)
     {
          MessageTx_GateOpenAngle = (uint16_t)((uint32_t)(Motor1_Position * 100) / SystemLearned_Position);
	   
     }
     else
     {
	  MessageTx_GateOpenAngle = (uint16_t)((uint32_t)(Motor1_Position * 100) / K_SystemLearned_Position_Default);
     }
     
     if(MessageTx_GateOpenAngle > K_MessageTx_GateOpenAngle_Max)
     {
	  MessageTx_GateOpenAngle = K_MessageTx_GateOpenAngle_Max;
     }
}
 
 /*********************************************************************************************
** Name:	  MessageTransmit_GaragePosition(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_GaragePosition(void)
{ 
    if(FALSE == GarageHeightRequest_Process_Status)
    {
        if(TRUE == SystemLearned_Status)
        {
            if(TRUE == GarageLearned_Status)
            {
                 MessageTx_GaragePosition = (uint16_t)((uint32_t)(GarageLearned_Position * 100) / SystemLearned_Position);
	         MessageTx_GaragePosition_Remainder = (uint16_t)((uint32_t)(GarageLearned_Position * 100) % SystemLearned_Position);
            }
            else
            {
	         MessageTx_GaragePosition = (uint16_t)((uint32_t)(K_GarageLearned_Position_Default * 100) / SystemLearned_Position);	       
            }
        }
        else
        {
	    if(TRUE == GarageLearned_Status)
            {
                 MessageTx_GaragePosition = (uint16_t)((uint32_t)(GarageLearned_Position * 100) / K_SystemLearned_Position_Default);
	         MessageTx_GaragePosition_Remainder = (uint16_t)((uint32_t)(GarageLearned_Position * 100) % K_SystemLearned_Position_Default);                        
            }
            else
            {
	         MessageTx_GaragePosition = (uint16_t)((uint32_t)(K_GarageLearned_Position_Default * 100) / K_SystemLearned_Position_Default);
	       
            }
        }
    
        if(MessageTx_GaragePosition_Remainder > 0)
        {
	     MessageTx_GaragePosition += K_GaragePosition_Precision_Compensation;
        }
    
        if(MessageTx_GaragePosition > K_MessageTx_GateOpenAngle_Max)
        {
	     MessageTx_GaragePosition = K_MessageTx_GateOpenAngle_Max;
        } 
    }
    else
    {
	 MessageTx_GaragePosition = MessageRx_GarageHeight;
    }
} 
/*********************************************************************************************
** Name:	  MessageTransmit_LearnStatus(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_LearnStatus(void)
{
       MessageTx_SystemLearnedStatus = SystemLearned_Status;
       MessageTx_GarageLearnedStatus = GarageLearned_Status;
       MessageTx_GarageLearnAction = ShutFaceSwitch_LongPress_Status;
       MessageTx_SystemLearnFailure = System_Learn_Failure;
}
/*********************************************************************************************
** Name:	  MessageTransmit_LatchSwitch(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_LatchSwitch(void)
{
      #ifdef _CONFIG_PawlSwitch
      MessageTx_PawlSwitch = PawlSwitch_Status;
      #endif
      #ifdef _CONFIG_SecondarySwitch
      MessageTx_SecondarySwitch = SecondarySwitch_Status;
      #endif
      #ifdef _CONFIG_PositionSwitch
      MessageTx_PositonSwitch = PositionSwitch_Status;
      #endif
      #ifdef _CONFIG_PrimarySwitch
      MessageTx_PrimarySwitch = PrimarySwitch_Status;
      #endif  
}
#endif

#ifdef _SGMW_COM 
/*********************************************************************************************
** Name:	  MessageTransmit_GateMotion(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/ 
 static void MessageTransmit_GateMotion(void)
 {
      if(ActiveSystemMode == SystemOpenedFully)
      {
	   MessageTx_GateMotion = FullOpen;
      }
      else if(ActiveSystemMode == SystemClosedFully)
      {
	   MessageTx_GateMotion = Closed;
      }
      else if((ActiveSystemMode == SystemPowerOpening) 
            || (ActiveSystemMode == SystemReleaseToPowerOpen))
      {
	   MessageTx_GateMotion = Opening;
      }
      else if((ActiveSystemMode == SystemPowerClosing) 
            || (ActiveSystemMode == SystemPowerCinching)
	    || (ActiveSystemMode == SystemPowerParking))
      {
	   MessageTx_GateMotion = Closing;
      }
      else if(ActiveSystemMode == SystemReleased) 
      {
	   MessageTx_GateMotion = Stopped;
      }
      else if(ActiveSystemMode == SystemMechFailure)
      {
	   MessageTx_GateMotion = Unknown;
      }
 }
 /*********************************************************************************************
** Name:	  MessageTransmit_LatchMotion(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_LatchMotion(void)
{
      if(ActiveLatchMode == LatchFullyCinched)
      {
	   MessageTx_LatchMotion = Cinched;
      }
      else if((ActiveLatchMode == LatchPreCinchCheck) || (ActiveLatchMode == LatchPowerCinching)
            || (ActiveLatchMode == LatchFindHomeAfterCinch))
      {
	   MessageTx_LatchMotion = Cinching;
      }
      else if((ActiveLatchMode == LatchPreReleasing)|| (ActiveLatchMode == LatchPowerReleasing)
             || (ActiveLatchMode == LatchFindHomeAfterRelease) || (ActiveLatchMode == LatchPreReleased))
      {
	   MessageTx_LatchMotion = Releasing;
      }
      else if(ActiveLatchMode == LatchFullyReleased)
      {
	   MessageTx_LatchMotion = Released;
      }
      else
      {
	   MessageTx_LatchMotion = Default;
      }
}
/*********************************************************************************************
** Name:	  MessageTransmit_CommandActive(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_CommandActive(void)
{
      if((TRUE == DriverButton_Status) || (TRUE == OpenCloseSwitch_Status))
      {
	    MessageTx_CommandActive = _COCKPIT_SWITCH_ACTIVE;
      }
      else if((TRUE == PKETrunkButton_Status) || (TRUE == TouchPad_Status) || (TRUE == OutsideHandleSwitch_Status))
      {
	    MessageTx_CommandActive = _HANDLE_SWITCH_ACTIVE;
      }
      else if(TRUE == ShutFaceSwitch_Status)
      {
	    MessageTx_CommandActive = _SHUTFACE_SWITCH_ACTIVE;
      }
      else if(TRUE == KickSensor_Status)
      {
	    MessageTx_CommandActive = _KICK_SENSOR_ACTIVE;
      }
      else if((TRUE == FobLongPress_Status) || (TRUE == FobShortPress_Status))
      {
	    MessageTx_CommandActive = _REMOTE_KEY_ACTIVE;
      }
      else if(TRUE == AutoOpen_Status)
      {
	    MessageTx_CommandActive = _PEPS_SENSORLESS_AUTOMATIC_TRUNK_OPEN;
      }
      else
      {
	    MessageTx_CommandActive = _NO_COMMAND;  
      }
		
}
/*********************************************************************************************
** Name:	  MessageTransmit_PLGDspMsgReq(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_PLGDspMsgReq(void)
{
     static uint16_t MessageTx_VehicleGearLever_Timer; 
     /*if(TRUE == VehicleGearLever_Status)
     {
         MessageTx_VehicleGearLever = _VEHICLE_IS_NOT_IN_PARK;
     }
     else
     {
	 MessageTx_VehicleGearLever = _NO_DISPLAY;
     }*/
        
     if(StaticDisplayRequest.bits.PRNDL == TRUE) 
     {
	  StaticDisplayRequest.bits.PRNDL = FALSE;
	  //MessageTx_VehicleGearLever = _VEHICLE_IS_NOT_IN_PARK;
	  MessageTx_VehicleGearLever_Timer = 0;
     }
     
     if(MessageTx_VehicleGearLever_Timer >= K_MessageTx_VehicleGearLever_Time)
     {
	  MessageTx_VehicleGearLever = _NO_DISPLAY;
     }
     else
     {
	  MessageTx_VehicleGearLever_Timer ++;
     }

}

/*********************************************************************************************
** Name:	  MessageTransmit_LatchSwitch(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_LatchSwitch(void)
{
      #ifdef _CONFIG_PawlSwitch
      MessageTx_PawlSwitch = PawlSwitch_Status;
      #endif
      #ifdef _CONFIG_SecondarySwitch
      MessageTx_SecondarySwitch = SecondarySwitch_Status;
      #endif
      #ifdef _CONFIG_PositionSwitch
      MessageTx_PositonSwitch = PositionSwitch_Status;
      #endif
      #ifdef _CONFIG_PrimarySwitch
      MessageTx_PrimarySwitch = PrimarySwitch_Status;
      #endif
      MessageTx_SnowLoadSignal = LatchSnowLoad_Status;
}

/*********************************************************************************************
** Name:	  MessageTransmit_GateOpenAngle(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_GateOpenAngle(void)
{
     if(TRUE == SystemLearned_Status)
     {
           MessageTx_GateOpenAngle = (uint16_t)((uint32_t)(Motor1_Position * 100) / SystemLearned_Position);
	   MessageTx_GateOpenAngle_Valid = _ANGLE_VALID;
     }
     else
     {
	   MessageTx_GateOpenAngle = (uint16_t)((uint32_t)(Motor1_Position * 100) / K_MaxPosition_HallCount_Default);
	   MessageTx_GateOpenAngle_Valid = _ANGLE_VALID;
     }
     
     if(MessageTx_GateOpenAngle > K_GateOpenAngle_Precision_Compensation)
     {
          MessageTx_GateOpenAngle -= K_GateOpenAngle_Precision_Compensation;
     }
     
     if(MessageTx_GateOpenAngle > K_MessageTx_GateOpenAngle_Max)
     {
	  MessageTx_GateOpenAngle = K_MessageTx_GateOpenAngle_Max;
     }
}

/*********************************************************************************************
** Name:	  MessageTransmit_GaragePosition(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_GaragePosition(void)
{
    if(TRUE == SystemLearned_Status)
    {
         if(TRUE == GarageLearned_Status)
         {
               MessageTx_GaragePosition = (uint16_t)((uint32_t)(GarageLearned_Position * 100) / SystemLearned_Position);
	       MessageTx_GaragePosition_Remainder = (uint16_t)((uint32_t)(GarageLearned_Position * 100) % SystemLearned_Position);
         }
         else
         {
	       MessageTx_GaragePosition = (uint16_t)((uint32_t)(K_GarageLearned_Position_Default * 100) / SystemLearned_Position);	       
         }
    }
    else
    {
	 if(TRUE == GarageLearned_Status)
         {
               MessageTx_GaragePosition = (uint16_t)((uint32_t)(GarageLearned_Position * 100) / K_SystemLearned_Position_Default);
	       MessageTx_GaragePosition_Remainder = (uint16_t)((uint32_t)(GarageLearned_Position * 100) % K_SystemLearned_Position_Default);                        
         }
         else
         {
	       MessageTx_GaragePosition = (uint16_t)((uint32_t)(K_GarageLearned_Position_Default * 100) / K_SystemLearned_Position_Default);
	       
         }
    }
    
     if(MessageTx_GaragePosition_Remainder > 0)
     {
	  MessageTx_GaragePosition += K_GaragePosition_Precision_Compensation;
     }
    
     if(MessageTx_GaragePosition > K_MessageTx_GateOpenAngle_Max)
     {
	  MessageTx_GaragePosition = K_MessageTx_GateOpenAngle_Max;
     }
     
     if(FALSE == GarageLearned_Status)
     {
	  MessageTx_GaragePosition = K_MessageTx_GaragePosition_100Percent;
     }
    
}
/*********************************************************************************************
** Name:	  MessageTransmit_LearnStatus(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_LearnStatus(void)
{
       MessageTx_SystemLearnedStatus = SystemLearned_Status;
       MessageTx_GarageLearnedStatus = GarageLearned_Status;
       MessageTx_GarageLearnAction = ShutFaceSwitch_LongPress_Status;
       MessageTx_SystemLearnFailure = System_Learn_Failure;
}
#endif

#ifdef _NIU_COM
/*********************************************************************************************
** Name:	  MessageTransmit_LearnStatus(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_RDM1_SystemFaultSts(void)
{
       if((TRUE == DTCData_Table.table.Motor1_STG.DTCData.data.DTCStatus.bits.TestFailed) 
        ||(TRUE == DTCData_Table.table.Motor1_STB.DTCData.data.DTCStatus.bits.TestFailed)
	||(TRUE == DTCData_Table.table.Motor1_OC.DTCData.data.DTCStatus.bits.TestFailed)
	||(TRUE == DTCData_Table.table.Motor2_STG.DTCData.data.DTCStatus.bits.TestFailed) 
        ||(TRUE == DTCData_Table.table.Motor2_STB.DTCData.data.DTCStatus.bits.TestFailed)
	||(TRUE == DTCData_Table.table.Motor2_OC.DTCData.data.DTCStatus.bits.TestFailed)
	||(TRUE == DTCData_Table.table.CinchMotor_STG.DTCData.data.DTCStatus.bits.TestFailed)
        ||(TRUE == DTCData_Table.table.CinchMotor_STB.DTCData.data.DTCStatus.bits.TestFailed)
        ||(TRUE == DTCData_Table.table.CinchMotor_OC.DTCData.data.DTCStatus.bits.TestFailed)
	
	||(TRUE == DTCData_Table.table.HallA1_NoHall.DTCData.data.DTCStatus.bits.TestFailed)
        ||(TRUE == DTCData_Table.table.HallA2_NoHall.DTCData.data.DTCStatus.bits.TestFailed)
        ||(TRUE == DTCData_Table.table.HallB1_NoHall.DTCData.data.DTCStatus.bits.TestFailed)
	||(TRUE == DTCData_Table.table.HallB1_NoHall.DTCData.data.DTCStatus.bits.TestFailed)
	)
     {
	   MessageTx_RDM1_SystemFaultSts = _RDM1_SystemFaultSts_Fault;
     }
     else
     {
	   MessageTx_RDM1_SystemFaultSts = _RDM1_SystemFaultSts_No_Fault;
     }
}
/*********************************************************************************************
** Name:	  MessageTransmit_RDM1_InitSt(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_RDM1_InitSt(void)
{
      if(TRUE == SystemLearned_Status)
      {
	    MessageTx_RDM1_InitSt = _RDM1_RearDoorTherProSts_Active;
      }
      else
      {
	    MessageTx_RDM1_InitSt = _RDM1_RearDoorTherProSts_Inactive;
      }
}
/*********************************************************************************************
** Name:	  MessageTransmit_RDM1_RearDoorTherProSts(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_RDM1_RearDoorTherProSts(void)
{
     if(TRUE == CurrentStaticTelltales.bits.ThermalProtected)
     {
	  MessageTx_RDM1_RearDoorTherProSts = _RDM1_RearDoorTherProSts_Active;
     }
     else
     {
	  MessageTx_RDM1_RearDoorTherProSts = _RDM1_RearDoorTherProSts_Inactive;
     }
}
/*********************************************************************************************
** Name:	  MessageTransmit_RDM1_HalfLockSt(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_RDM1_HalfLockSt(void)
{
      if(TRUE == SecondarySwitch_Status)
      {
	    MessageTx_RDM1_HalfLockSt = FALSE;
      }
      else
      {
	    MessageTx_RDM1_HalfLockSt = TRUE;
      }
}
/*********************************************************************************************
** Name:	  MessageTransmit_RDM1_FullLockSt(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_RDM1_FullLockSt(void)
{
      if(TRUE == PawlSwitch_Status)
      {
	    MessageTx_RDM1_FullLockSt = FALSE;
      }
      else
      {
	    MessageTx_RDM1_FullLockSt = TRUE;
      }
}
/*********************************************************************************************
** Name:	  MessageTransmit_RDM1_InsideSwitchSts(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_RDM1_InsideSwitchSts(void)
{
     if(TRUE == ShutFaceSwitch_Status)
     {
	  MessageTx_RDM1_InsideSwitchSts = TRUE;
     }
     else
     {
	  MessageTx_RDM1_InsideSwitchSts = FALSE;
     }
}
/*********************************************************************************************
** Name:	  MessageTransmit_RDM1_RearDoorPos(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_RDM1_RearDoorPos(void)
{
     MessageTx_RDM1_RearDoorPos = MessageTx_GaragePosition - 50;
}
/*********************************************************************************************
** Name:	  MessageTransmit_RDM1_RearDoorSts(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_RDM1_RearDoorSts(void)
{
      if(ActiveSystemMode == SystemOpenedFully)
      {
	   MessageTx_RDM1_RearDoorSts = _RDM1_RearDoorSts_Opened;
      }
      else if(ActiveSystemMode == SystemClosedFully)
      {
	   MessageTx_RDM1_RearDoorSts = _RDM1_RearDoorSts_Closed;
      }
      else if((ActiveSystemMode == SystemPowerOpening) 
            || (ActiveSystemMode == SystemReleaseToPowerOpen))
      {
	   MessageTx_RDM1_RearDoorSts = _RDM1_RearDoorSts_Opening;
      }
      else if((ActiveSystemMode == SystemPowerClosing) 
            || (ActiveSystemMode == SystemPowerCinching)
	    || (ActiveSystemMode == SystemPowerParking))
      {
	   MessageTx_RDM1_RearDoorSts = _RDM1_RearDoorSts_Closing;
      }
      else if(ActiveSystemMode == SystemReleased) 
      {
	   MessageTx_RDM1_RearDoorSts = _RDM1_RearDoorSts_Pause;
      }
      else
      {
	   MessageTx_RDM1_RearDoorSts = _RDM1_RearDoorSts_Pause;
      }
}
/*********************************************************************************************
** Name:	  MessageTransmit_RDM1_CentralLockingSwSts(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_RDM1_CentralLockingSwSts(void)
{
     if(TRUE == ShutFaceLockSwitch_Status)
     {
	  MessageTx_RDM1_CentralLockingSwSts = _RDM1_CentralLockingSwSts_Press;
     }
     else
     {
	  MessageTx_RDM1_CentralLockingSwSts = _RDM1_CentralLockingSwSts_Not_Press;
     }
}
/*********************************************************************************************
** Name:	  MessageTransmit_RDM1_RearDoorAntiPinchSts(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_RDM1_RearDoorAntiPinchSts(void)
{
     static uint16_t MessageTx_RDM1_RearDoorAntiPinchSts_Timer;
     #define K_MessageTx_RDM1_RearDoorAntiPinchSts_Time 30

     if(DynamicDisplayRequest.bits.Motor1Obstacle == TRUE) 
     {
	  DynamicDisplayRequest.bits.Motor1Obstacle = FALSE;
	  
	  MessageTx_RDM1_RearDoorAntiPinchSts = _RDM1_RearDoorAntiPinchSts_Active;
	  MessageTx_RDM1_RearDoorAntiPinchSts_Timer = 0;
     }
     else if(DynamicDisplayRequest.bits.Motor2Obstacle == TRUE) 
     {
	  DynamicDisplayRequest.bits.Motor2Obstacle = FALSE;
	  
	  MessageTx_RDM1_RearDoorAntiPinchSts = _RDM1_RearDoorAntiPinchSts_Active;
	  MessageTx_RDM1_RearDoorAntiPinchSts_Timer = 0;
     }
     
 
     if(MessageTx_RDM1_RearDoorAntiPinchSts_Timer >= K_MessageTx_RDM1_RearDoorAntiPinchSts_Time)
     {
	  MessageTx_RDM1_RearDoorAntiPinchSts = _RDM1_RearDoorAntiPinchSts_Inactive; 
     }
     else
     {
	  MessageTx_RDM1_RearDoorAntiPinchSts_Timer ++;
     }
}
/*********************************************************************************************
** Name:	  MessageTransmit_RDM1_VechicleAlarmReq(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_RDM1_VechicleAlarmReq(void)
{ 
     if((VehicleAntiTheft != AntiTheft_Disarm)
       &&(MessageTx_RDM1_RearDoorAntiPinchSts == _RDM1_RearDoorAntiPinchSts_Active)
       &&(TRUE == ObstcalAlarmEnable_Status))
     {
	  MessageTx_RDM1_VechicleAlarmReq = _RDM1_VechicleAlarmReq_Request;
     }
     else
     {
	  MessageTx_RDM1_VechicleAlarmReq = _RDM1_VechicleAlarmReq_Not_Request; 
     }
}
/*********************************************************************************************
** Name:	  MessageTransmit_RDM1_AntiPinchAlarmSts(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_RDM1_AntiPinchAlarmSts(void)
{
     if(TRUE == ObstcalAlarmEnable_Status)
     {
	  MessageTx_RDM1_AntiPinchAlarmSts = _RDM1_AntiPinchAlarmSts_On;
     }
     else
     {
	  MessageTx_RDM1_AntiPinchAlarmSts = _RDM1_AntiPinchAlarmSts_Off;
     }
}

/*********************************************************************************************
** Name:	  MessageTransmit_LatchSwitch(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_LatchSwitch(void)
{
      #ifdef _CONFIG_PawlSwitch
      MessageTx_PawlSwitch = PawlSwitch_Status;
      #endif
      #ifdef _CONFIG_SecondarySwitch
      MessageTx_SecondarySwitch = SecondarySwitch_Status;
      #endif
      #ifdef _CONFIG_PositionSwitch
      MessageTx_PositonSwitch = PositionSwitch_Status;
      #endif
      #ifdef _CONFIG_PrimarySwitch
      MessageTx_PrimarySwitch = PrimarySwitch_Status;
      #endif
}
/*********************************************************************************************
** Name:	  MessageTransmit_GateOpenAngle(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_GateOpenAngle(void)
{
     if(TRUE == SystemLearned_Status)
     {
          MessageTx_GateOpenAngle = (uint16_t)((uint32_t)(Motor1_Position * 100) / SystemLearned_Position);
	   
     }
     else
     {
	  MessageTx_GateOpenAngle = (uint16_t)((uint32_t)(Motor1_Position * 100) / K_SystemLearned_Position_Default);
     }
     
     if(MessageTx_GateOpenAngle > K_MessageTx_GateOpenAngle_Max)
     {
	  MessageTx_GateOpenAngle = K_MessageTx_GateOpenAngle_Max;
     }
}
 
 
 /*********************************************************************************************
** Name:	  MessageTransmit_GaragePosition(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_GaragePosition(void)
{ 
    if(FALSE == GarageHeightRequest_Process_Status)
    {
        if(TRUE == SystemLearned_Status)
        {
            if(TRUE == GarageLearned_Status)
            {
                 MessageTx_GaragePosition = (uint16_t)((uint32_t)(GarageLearned_Position * 100) / SystemLearned_Position);
	         MessageTx_GaragePosition_Remainder = (uint16_t)((uint32_t)(GarageLearned_Position * 100) % SystemLearned_Position);
            }
            else
            {
	         MessageTx_GaragePosition = (uint16_t)((uint32_t)(K_GarageLearned_Position_Default * 100) / SystemLearned_Position);	       
            }
        }
        else
        {
	    if(TRUE == GarageLearned_Status)
            {
                 MessageTx_GaragePosition = (uint16_t)((uint32_t)(GarageLearned_Position * 100) / K_SystemLearned_Position_Default);
	         MessageTx_GaragePosition_Remainder = (uint16_t)((uint32_t)(GarageLearned_Position * 100) % K_SystemLearned_Position_Default);                        
            }
            else
            {
	         MessageTx_GaragePosition = (uint16_t)((uint32_t)(K_GarageLearned_Position_Default * 100) / K_SystemLearned_Position_Default);
	       
            }
        }
    
        if(MessageTx_GaragePosition_Remainder > 0)
        {
	     MessageTx_GaragePosition += K_GaragePosition_Precision_Compensation;
        }
    
        if(MessageTx_GaragePosition > K_MessageTx_GateOpenAngle_Max)
        {
	     MessageTx_GaragePosition = K_MessageTx_GateOpenAngle_Max;
        } 
    }
    else
    {
	 MessageTx_GaragePosition = MessageRx_GarageHeight;
    }
} 
/*********************************************************************************************
** Name:	  MessageTransmit_LearnStatus(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_LearnStatus(void)
{
       MessageTx_SystemLearnedStatus = SystemLearned_Status;
       MessageTx_GarageLearnedStatus = GarageLearned_Status;
       MessageTx_GarageLearnAction = ShutFaceSwitch_LongPress_Status;
       MessageTx_SystemLearnFailure = System_Learn_Failure;
}
#endif

#ifdef _BAIC_COM
/*********************************************************************************************
** Name:	  MessageTransmit_PtmPosnSts(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_PtmPosnSts(void)
{
     if(TRUE == SystemLearned_Status)
     {
           MessageTx_PtmPosnSts = (uint16_t)((uint32_t)(Motor1_Position * 100) / SystemLearned_Position);	   
     }
     else
     {
	   MessageTx_PtmPosnSts = (uint16_t)((uint32_t)(Motor1_Position * 100) / K_MaxPosition_HallCount_Default);
     }
     
     if(MessageTx_PtmPosnSts > K_MessageTx_GateOpenAngle_Max)
     {
	  MessageTx_PtmPosnSts = K_MessageTx_GateOpenAngle_Max;
     }
}


/*********************************************************************************************
** Name:	  MessageTransmit_PtmSetMaxPosn(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_PtmSetMaxPosn(void)
{

}

/*********************************************************************************************
** Name:	  MessageTransmit_LatchSwitch(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_PtmLtchSts(void)
{
      if(ActiveLatchMode == LatchFullyCinched)
      {
	   MessageTx_PtmLtchSts = _PtmLtchSts_Latched;
      }
      /*else if((ActiveLatchMode == LatchPreCinchCheck) || (ActiveLatchMode == LatchPowerCinching)
            || (ActiveLatchMode == LatchFindHomeAfterCinch))
      {
	   MessageTx_PtmLtchSts = _PtmLtchSts_Cinching;
      }
      else if((ActiveLatchMode == LatchPreReleasing)|| (ActiveLatchMode == LatchPowerReleasing)
             || (ActiveLatchMode == LatchFindHomeAfterRelease) || (ActiveLatchMode == LatchPreReleased))
      {
	   MessageTx_PtmLtchSts = _PtmLtchSts_Releasing;
      }*/
      else if(ActiveLatchMode == LatchFullyReleased)
      {
	   MessageTx_PtmLtchSts = _PtmLtchSts_Open;
      }
      else if(ActiveLatchMode == LatchInitDefault)
      {
	   MessageTx_PtmLtchSts = _PtmLtchSts_Initializing;
      }
      else
      {
	   MessageTx_PtmLtchSts = _PtmLtchSts_Secondary;
      }
}



/*********************************************************************************************
** Name:	  MessageTransmit_PtmOperSts(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_PtmOperSts(void)
{
      if(ActiveSystemMode == SystemOpenedFully)
      {
	   MessageTx_PtmOperSts = _PtmOperSts_Open;
      }
      else if(ActiveSystemMode == SystemClosedFully)
      {
	   MessageTx_PtmOperSts = _PtmOperSts_close;
      }
      else if((ActiveSystemMode == SystemPowerOpening) 
            || (ActiveSystemMode == SystemReleaseToPowerOpen))
	    //|| (ActiveSystemMode == SystemReleaseOnly))
      {
	   MessageTx_PtmOperSts = _PtmOperSts_opening;

      }
      else if((ActiveSystemMode == SystemPowerClosing) 
            || (ActiveSystemMode == SystemPowerCinching)
	    || (ActiveSystemMode == SystemPowerParking))
	    //|| (ActiveSystemMode == SystemManualCinching)
	    //|| (ActiveSystemMode == SystemManualParking))
      {
	   MessageTx_PtmOperSts = _PtmOperSts_Closing;
      }
      else if((ActiveSystemMode == SystemReleased))
      {
	   if((TRUE == GarageEnd_SoftStop_Position_Status) && (TRUE == GarageLearned_Status))
	   {
		MessageTx_PtmOperSts = _PtmOperSts_Open;
	   }
	   else
	   {
	        MessageTx_PtmOperSts = _PtmOperSts_Stop;
	   }	   
      }
      else if(ActiveSystemMode == SystemMechFailure)
      {
	   MessageTx_PtmOperSts = _PtmOperSts_Stop;
      }
      else
      {
          MessageTx_PtmOperSts = _PtmOperSts_close;
      }
}

/*********************************************************************************************
** Name:	  MessageTransmit_PtmOperIndcnLi(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_PtmOperIndcnLi(void)
{     
     static uint16_t MessageTx_PtmOperIndcnLi_Timer;
     
     if(TRUE == FlasherEnable_Status)
     {
          if(FlashRemind_Request == Remind_1)
          {
	        FlashRemind_Request = No_Remind; 
		MessageTx_PtmOperIndcnLi = _PtmOperIndcnLi_PTM_closing_light_indication;
		MessageTx_PtmOperIndcnLi_Timer = 0;
	  }   
	  else if(FlashRemind_Request == Remind_2)
          {
	        FlashRemind_Request = No_Remind; 
		MessageTx_PtmOperIndcnLi = _PtmOperIndcnLi_PTM_opening_light_indication;
		MessageTx_PtmOperIndcnLi_Timer = 0;
	  } 
          else if(FlashRemind_Request == Remind_3)
          {
	        FlashRemind_Request = No_Remind; 
                MessageTx_PtmOperIndcnLi = _PtmOperIndcnLi_PTM_pinch_event_light_indication;
	        MessageTx_PtmOperIndcnLi_Timer = 0;
          }
	  else if(FlashRemind_Request == Remind_4)
	  {
		FlashRemind_Request = No_Remind; 
                MessageTx_PtmOperIndcnLi = _PtmOperIndcnLi_PTM_delay_close_event_light_indication;
	        MessageTx_PtmOperIndcnLi_Timer = 0;
	  }
	  else if(FlashRemind_Request == Remind_5)
	  {
		FlashRemind_Request = No_Remind; 
                MessageTx_PtmOperIndcnLi = _PtmOperIndcnLi_PTM_position_reset_successful;
	        MessageTx_PtmOperIndcnLi_Timer = 0;
	  }
     }
     else
     {
	   FlashRemind_Request = No_Remind; 
     }
     
     if(MessageTx_PtmOperIndcnLi_Timer >= K_MessageTx_PtmOperIndcnLi_Time)
     {
	  MessageTx_PtmOperIndcnLi = _PtmOperIndcnLi_NO_Indication; 
     }
     else
     {
	  MessageTx_PtmOperIndcnLi_Timer ++;
     }
	
}

/*********************************************************************************************
** Name:	  MessageTransmit_PtmEcuFailSts(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_PtmEcuFailSts(void)
{
     if((TRUE == DTCData_Table.table.Motor1_STG.DTCData.data.DTCStatus.bits.TestFailed) 
        ||(TRUE == DTCData_Table.table.Motor1_STB.DTCData.data.DTCStatus.bits.TestFailed)
	||(TRUE == DTCData_Table.table.Motor1_OC.DTCData.data.DTCStatus.bits.TestFailed)
	||(TRUE == DTCData_Table.table.CinchMotor_STG.DTCData.data.DTCStatus.bits.TestFailed)
        ||(TRUE == DTCData_Table.table.CinchMotor_STB.DTCData.data.DTCStatus.bits.TestFailed)
        ||(TRUE == DTCData_Table.table.CinchMotor_OC.DTCData.data.DTCStatus.bits.TestFailed)
	||(TRUE == DTCData_Table.table.Buzzer_STG.DTCData.data.DTCStatus.bits.TestFailed)
        ||(TRUE == DTCData_Table.table.Buzzer_STB.DTCData.data.DTCStatus.bits.TestFailed)
        ||(TRUE == DTCData_Table.table.Buzzer_OC.DTCData.data.DTCStatus.bits.TestFailed)
	||(TRUE == DTCData_Table.table.HallA1_NoHall.DTCData.data.DTCStatus.bits.TestFailed)
        ||(TRUE == DTCData_Table.table.HallA2_NoHall.DTCData.data.DTCStatus.bits.TestFailed)
       #ifdef _CONFIG_DIAG_Motor2	
	||(TRUE == DTCData_Table.table.Motor2_STG.DTCData.data.DTCStatus.bits.TestFailed) 
        ||(TRUE == DTCData_Table.table.Motor2_STB.DTCData.data.DTCStatus.bits.TestFailed)
	||(TRUE == DTCData_Table.table.Motor2_OC.DTCData.data.DTCStatus.bits.TestFailed)
        ||(TRUE == DTCData_Table.table.HallB1_NoHall.DTCData.data.DTCStatus.bits.TestFailed)
	||(TRUE == DTCData_Table.table.HallB1_NoHall.DTCData.data.DTCStatus.bits.TestFailed)
       #endif
	)
     {
	   MessageTx_PtmEcuFailSts = _PtmEcuFailSts_PTM_ECU_FAIL;
     }
     else
     {
	   MessageTx_PtmEcuFailSts = _PtmEcuFailSts_Normal;
     }
}
	

/*********************************************************************************************
** Name:	  MessageTransmit_PtmFotKicReq(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_PtmFotKicReq(void)
{
     if(TRUE == KickSensor_Status)//MessageRx_KickSensor;
     {
	   MessageTx_PtmFotKicReq = _PtmFotKicReq_active;
     }
     else
     {
	   MessageTx_PtmFotKicReq = _PtmFotKicReq_Inactive;
     }
}

/*********************************************************************************************
** Name:	  MessageTransmit_PtmPwrEnaSts(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_PtmPwrEnaSts(void)
{
     if(CurrentSpindleMode == SpindleDisableMode)
     {
	   MessageTx_PtmPwrEnaSts = _PtmPwrEnaSts_Disable;
     }
     else
     {
	   MessageTx_PtmPwrEnaSts = _PtmPwrEnaSts_Enable;
     }
}

/*********************************************************************************************
** Name:	  MessageTransmit_PtmFotKicEnaSts(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_PtmFotKicEnaSts(void)
{
     MessageTx_PtmFotKicEnaSts = FALSE;//KickSensorEnable_Status;  /*No APS Configuration*/
}

/*********************************************************************************************
** Name:	  MessageTransmit_PtmWarnMsg(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_PtmWarnMsg(void)
{
     static uint8_t MessageTx_PtmWarnMsg_Timer; 
     static uint8_t MessageTx_PtmWarnMsg_Check_Status; 
     static uint8_t MessageTx_PtmWarnMsg_Check_Timer; 
     #define K_MessageTx_PtmWarnMsg_Check_Time 30
     
     if(((VehiclePowerMode == PowerMode_ON) && (TRUE == BusPowerMode_Real_Status))
        &&((ActiveSystemMode == SystemClosedFully) 
          ||((ActiveSystemMode == SystemReleased)
	    &&(((TRUE == SpindleGarageMode_Status) && (FALSE == GarageEnd_SoftStop_Position_Status))||(TRUE == SpindleNormalMode_Status)))))
	 
     {
	   if((TRUE == TouchPad_FallEdge_Command_Active)
	      ||(TRUE == KickSensor_FallEdge_Command_Active)
	      #ifdef _CONFIG_DriverButton
	      ||(TRUE == DriverButton_FallEdge_Command_Active)
	      #endif
	      #ifdef _CONFIG_VoiceOpen
	      ||(TRUE == VoiceOpen_FallEdge_Command_Active)
	      #endif
	      #ifdef _CONFIG_VROpen
	      ||(TRUE == VROpen_FallEdge_Command_Active)
	      #endif
	      #ifdef _CONFIG_VirtualButton
	      ||(TRUE == VirtualButton_FallEdge_Command_Active)
	      #endif	      
	      ||(TRUE == AppOpen_FallEdge_Command_Active)
	      ||(TRUE == BLEOpen_FallEdge_Command_Active)
	      ||(TRUE == AutoOpen_FallEdge_Command_Active)
	      ||(TRUE == RemoteKey_FallEdge_Command_Active)
	      ||(TRUE == CPIDLearnPowerOpen_Command_Active)
	      ||(TRUE == OpenCloseSwitch_FallEdge_Command_Active)
	      #ifdef _CONFIG_OutsideHandleSwitch
	      ||(TRUE == OutsideHandleSwitch_FallEdge_Command_Active)
	       #endif
	     )
	   {
		 MessageTx_PtmWarnMsg_Check_Status = TRUE;
		 MessageTx_PtmWarnMsg_Check_Timer = 0;
	   }
     }
     
     if(TRUE == MessageTx_PtmWarnMsg_Check_Status)
     {
	   if(MessageTx_PtmWarnMsg_Check_Timer >= K_MessageTx_PtmWarnMsg_Check_Time)
	   {
		 MessageTx_PtmWarnMsg_Check_Status = FALSE;
		 if((ActiveSystemMode == SystemClosedFully) || (ActiveSystemMode == SystemReleased))
		 {
		      if(StaticDisplayRequest.bits.PRNDL == TRUE) 
                      {
	                    StaticDisplayRequest.bits.PRNDL = FALSE;
	  
	                    MessageTx_PtmWarnMsg = _PtmWarnMsg_Please_shift_to_P;
	                    MessageTx_PtmWarnMsg_Timer = 0;
                      }
		 }
	   }
	   else
	   {
		 MessageTx_PtmWarnMsg_Check_Timer ++;
	   }
     }
        
     
     
     if(MessageTx_PtmWarnMsg_Timer >= K_MessageTx_PtmWarnMsg_Time)
     {
	  MessageTx_PtmWarnMsg = _PtmWarnMsg_off;
     }
     else
     {
	  MessageTx_PtmWarnMsg_Timer ++;
     }
}

/*********************************************************************************************
** Name:	  MessageTransmit_PtmPncEve(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_PtmPncEve(void)
{
     static uint16_t MessageTx_PtmPncEve_Timer;

     if(DynamicDisplayRequest.bits.Motor1Obstacle == TRUE) 
     {
	  DynamicDisplayRequest.bits.Motor1Obstacle = FALSE;
	  
	  MessageTx_PtmPncEve = _PtmPncEve_Antipinch_event;
	  MessageTx_PtmPncEve_Timer = 0;
     }
     else if(DynamicDisplayRequest.bits.Motor2Obstacle == TRUE) 
     {
	  DynamicDisplayRequest.bits.Motor2Obstacle = FALSE;
	  
	  MessageTx_PtmPncEve = _PtmPncEve_Antipinch_event;
	  MessageTx_PtmPncEve_Timer = 0;
     }
 
     if(MessageTx_PtmPncEve_Timer >= K_MessageTx_PtmPncEve_Time)
     {
	  MessageTx_PtmPncEve = _PtmPncEve_Normal; 
     }
     else
     {
	  MessageTx_PtmPncEve_Timer ++;
     }
}

/*********************************************************************************************
** Name:	  MessageTransmit_PtmMod(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_PtmMod(void)
{
     if(TRUE == DelayCloseMode_Status)
     {
	   MessageTx_PtmMod = _PtmMod_delay_close;
     }
     else
     {
	   MessageTx_PtmMod = _PtmMod_Normal;
     }
}

/*********************************************************************************************
** Name:	  MessageTransmit_PtmOperIndcnSound(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_PtmOperIndcnSound(void)
{
     static uint16_t MessageTx_PtmOperIndcnSound_Timer;
     
     if(TRUE == BuzzerEnable_Status)
     {
          if(ChimeRemind_Request == Remind_1)
          {
	        ChimeRemind_Request = No_Remind; 
		MessageTx_PtmOperIndcnSound = _PtmOperIndcnSound_PTM_closing_sound;
		MessageTx_PtmOperIndcnSound_Timer = 0;
	  }   
	  else if(ChimeRemind_Request == Remind_2)
          {
	        ChimeRemind_Request = No_Remind; 
		MessageTx_PtmOperIndcnSound = _PtmOperIndcnSound_PTM_opening_sound;
		MessageTx_PtmOperIndcnSound_Timer = 0;
	  } 
          else if(ChimeRemind_Request == Remind_3)
          {
	        ChimeRemind_Request = No_Remind; 
                MessageTx_PtmOperIndcnSound = _PtmOperIndcnSound_PTM_PINCH_EVENT_sound;
	        MessageTx_PtmOperIndcnSound_Timer = 0;
          }
	  else if(ChimeRemind_Request == Remind_4)
	  {
		ChimeRemind_Request = No_Remind; 
                MessageTx_PtmOperIndcnSound = _PtmOperIndcnSound_PTM_delay_close_event_sound;
	        MessageTx_PtmOperIndcnSound_Timer = 0;
	  }
	  else if(ChimeRemind_Request == Remind_5)
	  {
		ChimeRemind_Request = No_Remind; 
                MessageTx_PtmOperIndcnSound = _PtmOperIndcnSound_PTM_position_reset_successful;
	        MessageTx_PtmOperIndcnSound_Timer = 0;
	  }
     }
     else
     {
	   ChimeRemind_Request = No_Remind; 
     }
     
     if(MessageTx_PtmOperIndcnSound_Timer >= K_MessageTx_PtmOperIndcnSound_Time)
     {
	  MessageTx_PtmOperIndcnSound = _PtmOperIndcnSound_NO_Sound; 
     }
     else
     {
	  MessageTx_PtmOperIndcnSound_Timer ++;
     }
}

/*********************************************************************************************
** Name:	  MessageTransmit_PtmSoundEnaSts(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_PtmSoundEnaSts(void)
{
     MessageTx_PtmSoundEnaSts = BuzzerEnable_Status;

}

/*********************************************************************************************
** Name:	  MessageTransmit_PtmLiEnaSts(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_PtmLiEnaSts(void)
{
     MessageTx_PtmLiEnaSts = FlasherEnable_Status;
}


/*********************************************************************************************
** Name:	  MessageTransmit_PtmLrnSts(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_PtmLrnSts(void)
{
     if(TRUE == SystemLearned_Status)
     {
	   MessageTx_PtmLrnSts = _PtmLrnSts_Set_success;
     }
     else
     {
	   MessageTx_PtmLrnSts = _PtmLrnSts_Failed;
     }
}

#if defined(_BAIC_COM_C52X) || defined(_BAIC_COM_C62X)
/*********************************************************************************************
** Name:	  MessageTransmit_InsidSwt(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_InsidSwt(void)
{
    #define K_MessageTx_InsidSwt_Time 15	
    static uint16_t MessageTx_InsidSwt_Timer;
    static uint8_t MessageTx_InsidSwt_Timer_Status;
  
    #ifdef _CONFIG_ShutFaceSwitch
    if((((ActiveSystemMode == SystemReleased) && (LastSystemMode == SystemReleased))
         ||((ActiveSystemMode == SystemOpenedFully) && (LastSystemMode == SystemOpenedFully)))
       &&(FALSE == SpindleDisableMode_Status))
    {
	 if(TRUE == ShutFaceSwitch_DoublePress_Active)
         {
	       MessageTx_InsidSwt = _InsidSwt_request_delay_close;
	       MessageTx_InsidSwt_Timer_Status = TRUE;
	       MessageTx_InsidSwt_Timer = 0;
         }
    }
    
    if(TRUE == MessageTx_InsidSwt_Timer_Status)
    {	    
	  if(MessageTx_InsidSwt_Timer >= K_MessageTx_InsidSwt_Time)
	  {
		MessageTx_InsidSwt_Timer_Status = FALSE;
	  }
	  else
	  {
		MessageTx_InsidSwt_Timer ++;
	  }
    }
    else
    {    
         if(TRUE == ShutFaceSwitch_Status)
         {
	       MessageTx_InsidSwt = _InsidSwt_active;
         }
         else
         {
	      MessageTx_InsidSwt = _InsidSwt_inactive;
         }
    }
    #endif
}
#endif

#if defined(_BAIC_COM_C46DB) || defined(_BAIC_COM_B30X) || defined(_BAIC_COM_N51AB)
/*********************************************************************************************
** Name:	  MessageTransmit_InsidSwt(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_InsidSwt(void)
{
    #define K_MessageTx_InsidSwt_Time 15	
    static uint16_t MessageTx_InsidSwt_Timer;
    static uint8_t MessageTx_InsidSwt_Timer_Status;
    
    #define _PLGM_TrInnrSwtSts_Inactive               0x0U
#define _PLGM_TrInnrSwtSts_ShortPressed           0x1U
#define _PLGM_TrInnrSwtSts_LongPressed            0x2U

  
    #ifdef _CONFIG_ShutFaceSwitch
    if((((ActiveSystemMode == SystemReleased) && (LastSystemMode == SystemReleased))
         ||((ActiveSystemMode == SystemOpenedFully) && (LastSystemMode == SystemOpenedFully)))
       &&(FALSE == SpindleDisableMode_Status))
    {
	 if(TRUE == ShutFaceSwitch_DoublePress_Active)
         {
	       MessageTx_InsidSwt = _PLGM_TrInnrSwtSts_request_delay_close;
	       MessageTx_InsidSwt_Timer_Status = TRUE;
	       MessageTx_InsidSwt_Timer = 0;
         }
    }
    else if(TRUE == ShutFaceSwitch_ShortPress_Active)
    {
	  MessageTx_InsidSwt = _PLGM_TrInnrSwtSts_ShortPressed;
	  MessageTx_InsidSwt_Timer_Status = TRUE;
	  MessageTx_InsidSwt_Timer = 0;
    }
    else if(TRUE == ShutFaceSwitch_LongPress_Active)
    {
	  MessageTx_InsidSwt = _PLGM_TrInnrSwtSts_LongPressed;
	  MessageTx_InsidSwt_Timer_Status = TRUE;
	  MessageTx_InsidSwt_Timer = 0;
    }
      
    if(TRUE == MessageTx_InsidSwt_Timer_Status)
    {	    
	  if(MessageTx_InsidSwt_Timer >= K_MessageTx_InsidSwt_Time)
	  {
		MessageTx_InsidSwt_Timer_Status = FALSE;
	  }
	  else
	  {
		MessageTx_InsidSwt_Timer ++;
	  }
    }
    else
    {    
	  MessageTx_InsidSwt = _InsidSwt_inactive;
    }
    #endif
}
#endif

/*********************************************************************************************
** Name:	  MessageTransmit_PtmMaxPosnSts(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_PtmMaxPosnSts(void)
{
}

/*********************************************************************************************
** Name:	  MessageTransmit_SecSwt(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_SecSwt(void)
{
}

/*********************************************************************************************
** Name:	  MessageTransmit_LtchSwt(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_LtchSwt(void)
{
}


/*********************************************************************************************
** Name:	  MessageTransmit_LatchSwitch(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_LatchSwitch(void)
{
      #ifdef _CONFIG_PawlSwitch
      MessageTx_PawlSwitch = PawlSwitch_Status;
      #endif
      #ifdef _CONFIG_SecondarySwitch
      MessageTx_SecondarySwitch = SecondarySwitch_Status;
      #endif
      #ifdef _CONFIG_PositionSwitch
      MessageTx_PositonSwitch = PositionSwitch_Status;
      #endif
      #ifdef _CONFIG_PrimarySwitch
      MessageTx_PrimarySwitch = PrimarySwitch_Status;
      #endif
      #ifdef _CONFIG_ShutFaceSwitch
      MessageTx_ShutFaceSwitch = ShutFaceSwitch_Status;
      #endif
      #ifdef _CONFIG_OpenCloseSwitch
      MessageTx_OpenCloseSwitch = OpenCloseSwitch_Status;
      #endif    
}


/*********************************************************************************************
** Name:	  MessageTransmit_GateOpenAngle(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_GateOpenAngle(void)
{
     if(TRUE == SystemLearned_Status)
     {
           MessageTx_GateOpenAngle = (uint16_t)((uint32_t)(Motor1_Position * 100) / SystemLearned_Position);	   
     }
     else
     {
	   MessageTx_GateOpenAngle = (uint16_t)((uint32_t)(Motor1_Position * 100) / K_MaxPosition_HallCount_Default);
     }
     
     if(MessageTx_GateOpenAngle > K_MessageTx_GateOpenAngle_Max)
     {
	  MessageTx_GateOpenAngle = K_MessageTx_GateOpenAngle_Max;
     }
}

/*********************************************************************************************
** Name:	  MessageTransmit_GaragePosition(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_GaragePosition(void)
{
    if(TRUE == SystemLearned_Status)
    {
         if(TRUE == GarageLearned_Status)
         {
               MessageTx_GaragePosition = (uint16_t)((uint32_t)(GarageLearned_Position * 100) / SystemLearned_Position);
	       MessageTx_GaragePosition_Remainder = (uint16_t)((uint32_t)(GarageLearned_Position * 100) % SystemLearned_Position);
         }
         else
         {
	       MessageTx_GaragePosition = (uint16_t)((uint32_t)(K_GarageLearned_Position_Default * 100) / SystemLearned_Position);	       
         }
    }
    else
    {
	 if(TRUE == GarageLearned_Status)
         {
               MessageTx_GaragePosition = (uint16_t)((uint32_t)(GarageLearned_Position * 100) / K_SystemLearned_Position_Default);
	       MessageTx_GaragePosition_Remainder = (uint16_t)((uint32_t)(GarageLearned_Position * 100) % K_SystemLearned_Position_Default);                        
         }
         else
         {
	       MessageTx_GaragePosition = (uint16_t)((uint32_t)(K_GarageLearned_Position_Default * 100) / K_SystemLearned_Position_Default);
	       
         }
    }
    
     if(MessageTx_GaragePosition_Remainder > 0)
     {
	  MessageTx_GaragePosition += K_GaragePosition_Precision_Compensation;
     }
    
     if(MessageTx_GaragePosition > K_MessageTx_GateOpenAngle_Max)
     {
	  MessageTx_GaragePosition = K_MessageTx_GateOpenAngle_Max;
     }
     
     if(FALSE == GarageLearned_Status)
     {
	  MessageTx_GaragePosition = K_MessageTx_GaragePosition_100Percent;
     }
    
}

/*********************************************************************************************
** Name:	  MessageTransmit_LearnStatus(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_LearnStatus(void)
{
       MessageTx_SystemLearnedStatus = SystemLearned_Status;
       MessageTx_GarageLearnedStatus = GarageLearned_Status;
       #ifdef _CONFIG_ShutFaceSwitch
       MessageTx_GarageLearnAction = ShutFaceSwitch_LongPress_Status;
       #endif
       MessageTx_SystemLearnFailure = System_Learn_Failure;
}

#ifdef _BAIC_COM_C46DB
/*********************************************************************************************
** Name:	  MessageTransmit_PLGM_TrActnHandCmd(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_PLGM_TrActnHandCmd(void)
{
     #define K_MessageTx_PLGM_TrActnHandCmd_Time 30	
     static uint16_t MessageTx_PLGM_TrActnHandCmd_Timer;
     static uint8_t MessageTx_PLGM_TrActnHandCmd_Status;
    
     if(TRUE == Motor1_FollowOpen_Command_Active)
     {
           MessageTx_PLGM_TrActnHandCmd = _PLGM_TrActnHandCmd_Open_Request_Pulling_Up_By_Hand;
	   MessageTx_PLGM_TrActnHandCmd_Timer = 0;
	   MessageTx_PLGM_TrActnHandCmd_Status = TRUE;
     }
     else if(TRUE == Motor1_FollowClose_Command_Active)
     {
	   MessageTx_PLGM_TrActnHandCmd = _PLGM_TrActnHandCmd_Close_Request_Pulling_Down_By_Hand;
	   MessageTx_PLGM_TrActnHandCmd_Timer = 0;
	   MessageTx_PLGM_TrActnHandCmd_Status = TRUE;
     }
     
     if(TRUE == MessageTx_PLGM_TrActnHandCmd_Status)
     {
	   if(MessageTx_PLGM_TrActnHandCmd_Timer >= K_MessageTx_PLGM_TrActnHandCmd_Time)
	   {
		 MessageTx_PLGM_TrActnHandCmd_Status = FALSE;
		 MessageTx_PLGM_TrActnHandCmd = _PLGM_TrActnHandCmd_Inactive;
	   }
	   else
	   {
		 MessageTx_PLGM_TrActnHandCmd_Timer ++;
	   }
     }   

}
/*********************************************************************************************
** Name:	  MessageTransmit_PLGM_OperMod(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_PLGM_OperMod(void)
{	      
     if(VehicleMode == VehicleMode_Normal)
     {
           MessageTx_PLGM_OperMod = _PLGM_OperMod_Normal_mode;
     }
     else if(VehicleMode == VehicleMode_Transport)
     {
	   MessageTx_PLGM_OperMod = _PLGM_OperMod_Transport_mode;
     }
     else if(VehicleMode == VehicleMode_Exhibition)
     {
	   MessageTx_PLGM_OperMod = _PLGM_OperMod_Exhibition_mode;
     }

}

/*********************************************************************************************
** Name:	  MessageTransmit_PLGM_UsrSetTrMaxHeiResFb(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_PLGM_UsrSetTrMaxHeiResFb(void)
{	
     static uint16_t  PLGM_UsrSetTrMaxHeiResFb_Timer;
     static uint8_t  PLGM_UsrSetTrMaxHeiResFb_Status;
     static uint16_t  PLGM_UsrSetTrMaxHeiResFb_Start_Timer;
     static uint8_t  PLGM_UsrSetTrMaxHeiResFb_Start_Status;
     
     #define K_PLGM_UsrSetTrMaxHeiResFb_Time 30
     #define K_PLGM_UsrSetTrMaxHeiResFb_Start_Time 30
     
     if((TRUE == GarageHeightRequest_FallEdge_Command_Active)
       ||((TRUE == ShutFaceSwitch_LongPress_Command_Active) 
          && ((ActiveSystemMode == SystemReleased) || (ActiveSystemMode == SystemOpenedFully))))
     {
	   PLGM_UsrSetTrMaxHeiResFb_Start_Status = TRUE;
	   PLGM_UsrSetTrMaxHeiResFb_Start_Timer = 0;
     }
     
     if(TRUE == PLGM_UsrSetTrMaxHeiResFb_Start_Status)
     {
	   if(PLGM_UsrSetTrMaxHeiResFb_Start_Timer >= K_PLGM_UsrSetTrMaxHeiResFb_Start_Time)
	   {
		 PLGM_UsrSetTrMaxHeiResFb_Start_Status = FALSE;
		 
		 if(TRUE == GarageLearnedSucessful_Status)
		 {
		        GarageLearnedSucessful_Status = FALSE;
			
			TxIpduPLGM_0x64.Ipdu.PLGM_UsrSetTrMaxHeiResFb = _PLGM_UsrSetTrMaxHeiResFb_Successful_Setting;
			Com_ActiveSig(COM_TXSIGPLGM_UsrSetTrMaxHeiResFb);
	                Com_SetSendRequest(COM_TXSIGPLGM_UsrSetTrMaxHeiResFb);
			
			PLGM_UsrSetTrMaxHeiResFb_Status = TRUE;
			PLGM_UsrSetTrMaxHeiResFb_Timer = 0;
		 }
		 else
		 {
			TxIpduPLGM_0x64.Ipdu.PLGM_UsrSetTrMaxHeiResFb = _PLGM_UsrSetTrMaxHeiResFb_Failed_Setting;
			Com_ActiveSig(COM_TXSIGPLGM_UsrSetTrMaxHeiResFb);
	                Com_SetSendRequest(COM_TXSIGPLGM_UsrSetTrMaxHeiResFb);
			
			PLGM_UsrSetTrMaxHeiResFb_Status = TRUE;
			PLGM_UsrSetTrMaxHeiResFb_Timer = 0;
		 }
	   }
	   else
	   {
		 PLGM_UsrSetTrMaxHeiResFb_Start_Timer ++;
	   }
     }
     
     if(TRUE == PLGM_UsrSetTrMaxHeiResFb_Status)
     {
	   if(PLGM_UsrSetTrMaxHeiResFb_Timer >= K_PLGM_UsrSetTrMaxHeiResFb_Time)
	   {
		 PLGM_UsrSetTrMaxHeiResFb_Status = FALSE;
		 
		 Com_DisactiveSig(COM_TXSIGPLGM_UsrSetTrMaxHeiResFb);
	         Com_SetSendRequest(COM_TXSIGPLGM_UsrSetTrMaxHeiResFb);
	   }
	   else
	   {
		 PLGM_UsrSetTrMaxHeiResFb_Timer ++;
	   }
     }
}
#endif

#endif

#ifdef _DFLZM_COM
/*********************************************************************************************
** Name:	  MessageTransmit_PLG1_RQ_HazardRemind_Mode(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_PLG1_RQ_HazardRemind_Mode(void)
{
     static uint16_t MessageTx_PLG1_RQ_HazardRemind_Mode_Timer;
     #define K_MessageTx_PLG1_RQ_HazardRemind_Mode_Time 60
     
     if(FlashRemind_Request != Flasher_Mode_Idle)
     {
          if(FlashRemind_Request == Remind_1)
          {
	        FlashRemind_Request = No_Remind; 
		MessageTx_PLG1_RQ_HazardRemind_Mode = _PLG1_RQ_HazardRemind_Mode_Anti_pinch_reverse;
		MessageTx_PLG1_RQ_HazardRemind_Mode_Timer = 0;
	  }   
	  else if(FlashRemind_Request == Remind_2)
          {
	        FlashRemind_Request = No_Remind; 
		MessageTx_PLG1_RQ_HazardRemind_Mode = _PLG1_RQ_HazardRemind_Mode_Forced_stop;
		MessageTx_PLG1_RQ_HazardRemind_Mode_Timer = 0;
	  } 
          else if(FlashRemind_Request == Remind_3)
          {
	        FlashRemind_Request = No_Remind; 
		MessageTx_PLG1_RQ_HazardRemind_Mode = _PLG1_RQ_HazardRemind_Mode_Warning;
		MessageTx_PLG1_RQ_HazardRemind_Mode_Timer = 0;
	  }
	  else if(FlashRemind_Request == Remind_4)
          {
	        FlashRemind_Request = No_Remind; 
		MessageTx_PLG1_RQ_HazardRemind_Mode = _PLG1_RQ_HazardRemind_Mode_Memory_position;
		MessageTx_PLG1_RQ_HazardRemind_Mode_Timer = 0;
	  }
	  else if(FlashRemind_Request == Remind_5)
          {
	        FlashRemind_Request = No_Remind; 
		MessageTx_PLG1_RQ_HazardRemind_Mode = _PLG1_RQ_HazardRemind_Mode_User_Operation_Accepted;
		MessageTx_PLG1_RQ_HazardRemind_Mode_Timer = 0;
	  }
	  else if(FlashRemind_Request == Remind_6)
          {
	        FlashRemind_Request = No_Remind; 
		MessageTx_PLG1_RQ_HazardRemind_Mode = _PLG1_RQ_HazardRemind_Mode_User_Operation_Denied;
		MessageTx_PLG1_RQ_HazardRemind_Mode_Timer = 0;
	  }
     }

     if(MessageTx_PLG1_RQ_HazardRemind_Mode_Timer >= K_MessageTx_PLG1_RQ_HazardRemind_Mode_Time)
     {
	  MessageTx_PLG1_RQ_HazardRemind_Mode = _PLG1_RQ_HazardRemind_Mode_Off; 
     }
     else
     {
	  MessageTx_PLG1_RQ_HazardRemind_Mode_Timer ++;
     }
 

}
/*********************************************************************************************
** Name:	  MessageTransmit_PLG1_Status_CurrentState_Mode(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_PLG1_Status_CurrentState_Mode(void)
{
    
     if(ActiveSystemMode == SystemInitDefault)
     {
	   MessageTx_PLG1_Status_CurrentState_Mode = _PLG1_Status_CurrentState_Mode_Abnormality;
     }
     else if((TRUE == DTCData_Table.table.Motor1_STG.DTCData.data.DTCStatus.bits.TestFailed) 
        ||(TRUE == DTCData_Table.table.Motor1_STB.DTCData.data.DTCStatus.bits.TestFailed)
	||(TRUE == DTCData_Table.table.Motor1_OC.DTCData.data.DTCStatus.bits.TestFailed)
	||(TRUE == DTCData_Table.table.Motor2_STG.DTCData.data.DTCStatus.bits.TestFailed) 
        ||(TRUE == DTCData_Table.table.Motor2_STB.DTCData.data.DTCStatus.bits.TestFailed)
	||(TRUE == DTCData_Table.table.Motor2_OC.DTCData.data.DTCStatus.bits.TestFailed)
	||(TRUE == DTCData_Table.table.CinchMotor_STG.DTCData.data.DTCStatus.bits.TestFailed)
        ||(TRUE == DTCData_Table.table.CinchMotor_STB.DTCData.data.DTCStatus.bits.TestFailed)
        ||(TRUE == DTCData_Table.table.CinchMotor_OC.DTCData.data.DTCStatus.bits.TestFailed)
	
	||(TRUE == DTCData_Table.table.HallA1_NoHall.DTCData.data.DTCStatus.bits.TestFailed)
        ||(TRUE == DTCData_Table.table.HallA2_NoHall.DTCData.data.DTCStatus.bits.TestFailed)
        ||(TRUE == DTCData_Table.table.HallB1_NoHall.DTCData.data.DTCStatus.bits.TestFailed)
	||(TRUE == DTCData_Table.table.HallB1_NoHall.DTCData.data.DTCStatus.bits.TestFailed)
	)
     {
	   MessageTx_PLG1_Status_CurrentState_Mode = _PLG1_Status_CurrentState_Mode_Abnormality;
     }
     else
     {
	   MessageTx_PLG1_Status_CurrentState_Mode = _PLG1_Status_CurrentState_Mode_Normal;
     }
     

}
/*********************************************************************************************
** Name:	  MessageTransmit_PLG1_Fdbk_PLGSystemMotion(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_PLG1_Fdbk_PLGSystemMotion (void)
{
     if(ActiveSystemMode == SystemOpenedFully)
      {
	   MessageTx_PLG1_Fdbk_PLGSystemMotion = _PLG1_Fdbk_PLGSystemMotion_Full_Open;
      }
      else if(ActiveSystemMode == SystemClosedFully)
      {
	   MessageTx_PLG1_Fdbk_PLGSystemMotion = _PLG1_Fdbk_PLGSystemMotion_Full_Close;
      }
      else if((ActiveSystemMode == SystemPowerOpening) 
            || (ActiveSystemMode == SystemReleaseToPowerOpen))
	    //|| (ActiveSystemMode == SystemReleaseOnly))
      {
	   MessageTx_PLG1_Fdbk_PLGSystemMotion = _PLG1_Fdbk_PLGSystemMotion_Opening;

      }
      else if((ActiveSystemMode == SystemPowerClosing) 
            || (ActiveSystemMode == SystemPowerCinching)
	    || (ActiveSystemMode == SystemPowerParking))
	    //|| (ActiveSystemMode == SystemManualCinching)
	    //|| (ActiveSystemMode == SystemManualParking))
      {
	   MessageTx_PLG1_Fdbk_PLGSystemMotion = _PLG1_Fdbk_PLGSystemMotion_Closing;
      }
      else if((ActiveSystemMode == SystemReleased))
      {
	   if((TRUE == GarageEnd_SoftStop_Position_Status) && (TRUE == GarageLearned_Status))
	   {
		MessageTx_PLG1_Fdbk_PLGSystemMotion = _PLG1_Fdbk_PLGSystemMotion_Full_Open;
	   }
	   else
	   {
	        MessageTx_PLG1_Fdbk_PLGSystemMotion = _PLG1_Fdbk_PLGSystemMotion_Stopped;
	   }	   
      }
      else if(ActiveSystemMode == SystemMechFailure)
      {
	   MessageTx_PLG1_Fdbk_PLGSystemMotion = _PLG1_Fdbk_PLGSystemMotion_Invalid;
      }
}
/*********************************************************************************************
** Name:	  MessageTransmit_PLG1_Status_PLGLearing(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_PLG1_Status_PLGLearing(void)
{
      if(TRUE == SystemLearned_Status)
      {
            MessageTx_PLG1_Status_PLGLearing = _PLG1_Status_PLGLearing_Learned;
      }
      else
      {
	    MessageTx_PLG1_Status_PLGLearing = _PLG1_Status_PLGLearing_Unlearn;
      }
}
/*********************************************************************************************
** Name:	  MessageTransmit_PLG1_Fdbk_PLGOpen_Lvl(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_PLG1_Fdbk_PLGOpen_Lvl(void)
{
       static uint16_t  MessageTx_GaragePosition_Pecent;
       
       #define _PLG1_Fdbk_PLGOpen_Lvl_Level_1_Pecent    27
       #define _PLG1_Fdbk_PLGOpen_Lvl_Level_2_Pecent    43
       #define _PLG1_Fdbk_PLGOpen_Lvl_Level_3_Pecent    59
       #define _PLG1_Fdbk_PLGOpen_Lvl_Level_4_Pecent    75
       #define _PLG1_Fdbk_PLGOpen_Lvl_Level_5_Pecent    92
      
        if(TRUE == SystemLearned_Status)
	{
	      if(TRUE == GarageLearned_Status)
	      {
		    MessageTx_GaragePosition_Pecent = (uint16_t)((uint32_t)(GarageLearned_Position * 100) / SystemLearned_Position);
		    
		    if((MessageTx_GaragePosition_Pecent > _PLG1_Fdbk_PLGOpen_Lvl_Level_1_Pecent) 
		      &&(MessageTx_GaragePosition_Pecent < _PLG1_Fdbk_PLGOpen_Lvl_Level_2_Pecent))
		    {
			  MessageTx_PLG1_Fdbk_PLGOpen_Lvl = _PLG1_Fdbk_PLGOpen_Lvl_Level_1;
		    }
		    else if((MessageTx_GaragePosition_Pecent > _PLG1_Fdbk_PLGOpen_Lvl_Level_2_Pecent) 
		      &&(MessageTx_GaragePosition_Pecent < _PLG1_Fdbk_PLGOpen_Lvl_Level_3_Pecent)) 
		    {
			  MessageTx_PLG1_Fdbk_PLGOpen_Lvl = _PLG1_Fdbk_PLGOpen_Lvl_Level_2;
		    }
		    else if((MessageTx_GaragePosition_Pecent > _PLG1_Fdbk_PLGOpen_Lvl_Level_3_Pecent) 
		      &&(MessageTx_GaragePosition_Pecent < _PLG1_Fdbk_PLGOpen_Lvl_Level_4_Pecent)) 
		    {
			  MessageTx_PLG1_Fdbk_PLGOpen_Lvl = _PLG1_Fdbk_PLGOpen_Lvl_Level_3;
		    }
		    else if((MessageTx_GaragePosition_Pecent > _PLG1_Fdbk_PLGOpen_Lvl_Level_4_Pecent) 
		      &&(MessageTx_GaragePosition_Pecent < _PLG1_Fdbk_PLGOpen_Lvl_Level_5_Pecent)) 
		    {
			  MessageTx_PLG1_Fdbk_PLGOpen_Lvl = _PLG1_Fdbk_PLGOpen_Lvl_Level_4;
		    }
		    else if((MessageTx_GaragePosition_Pecent > _PLG1_Fdbk_PLGOpen_Lvl_Level_5_Pecent))
		    {
			  MessageTx_PLG1_Fdbk_PLGOpen_Lvl = _PLG1_Fdbk_PLGOpen_Lvl_Level_5;
		    }
	      }
	      else
	      {
		    MessageTx_PLG1_Fdbk_PLGOpen_Lvl = _PLG1_Fdbk_PLGOpen_Lvl_Level_5;
	      }
	}
	else
	{
              MessageTx_PLG1_Fdbk_PLGOpen_Lvl = _PLG1_Fdbk_PLGOpen_Lvl_Invalid;
	}

}
/*********************************************************************************************
** Name:	  MessageTransmit_PLG1_Status_Secondary_Pos(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_PLG1_Status_Secondary_Pos(void)
{
}
/*********************************************************************************************
** Name:	  MessageTransmit_PLG1_Status_LatchReset(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_PLG1_Status_LatchReset(void)
{
}
/*********************************************************************************************
** Name:	  MessageTransmit_PLG1_Status_LatchPawl(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_PLG1_Status_LatchPawl(void)
{
}
/*********************************************************************************************
** Name:	  MessageTransmit_PLG1_Status_MotorStall(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_PLG1_Status_MotorStall(void)
{
}
/*********************************************************************************************
** Name:	  MessageTransmit_PLG1_Status_DoorOpenRatio_Value(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_PLG1_Status_DoorOpenRatio_Value(void)
{
}
/*********************************************************************************************
** Name:	  MessageTransmit_PLG1_Status_BackDoorMicSW(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_PLG1_Status_BackDoorMicSW(void)
{
      MessageTx_PLG1_Status_BackDoorMicSW = OutsideHandleSwitch_Status;
}
/*********************************************************************************************
** Name:	  MessageTransmit_PLG1_Status_PLGClosingSW(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_PLG1_Status_PLGClosingSW(void)
{
	MessageTx_PLG1_Status_PLGClosingSW = ShutFaceSwitch_Status;
}
/*********************************************************************************************
** Name:	  MessageTransmit_PLG1_Status_DriverSideSW(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_PLG1_Status_DriverSideSW(void)
{
	MessageTx_PLG1_Status_DriverSideSW = OpenCloseSwitch_Status;
}
/*********************************************************************************************
** Name:	  MessageTransmit_LatchSwitch(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_LatchSwitch(void)
{
      #ifdef _CONFIG_PawlSwitch
      MessageTx_PawlSwitch = PawlSwitch_Status;
      #endif
      #ifdef _CONFIG_SecondarySwitch
      MessageTx_SecondarySwitch = SecondarySwitch_Status;
      #endif
      #ifdef _CONFIG_PositionSwitch
      MessageTx_PositonSwitch = PositionSwitch_Status;
      #endif
      #ifdef _CONFIG_PrimarySwitch
      MessageTx_PrimarySwitch = PrimarySwitch_Status;
      #endif
}
/*********************************************************************************************
** Name:	  MessageTransmit_GateOpenAngle(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_GateOpenAngle(void)
{
     if(TRUE == SystemLearned_Status)
     {
          MessageTx_GateOpenAngle = (uint16_t)((uint32_t)(Motor1_Position * 100) / SystemLearned_Position);
	   
     }
     else
     {
	  MessageTx_GateOpenAngle = (uint16_t)((uint32_t)(Motor1_Position * 100) / K_SystemLearned_Position_Default);
     }
     
     if(MessageTx_GateOpenAngle > K_MessageTx_GateOpenAngle_Max)
     {
	  MessageTx_GateOpenAngle = K_MessageTx_GateOpenAngle_Max;
     }
}
 
 
 /*********************************************************************************************
** Name:	  MessageTransmit_GaragePosition(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_GaragePosition(void)
{ 
    if(FALSE == GarageHeightRequest_Process_Status)
    {
        if(TRUE == SystemLearned_Status)
        {
            if(TRUE == GarageLearned_Status)
            {
                 MessageTx_GaragePosition = (uint16_t)((uint32_t)(GarageLearned_Position * 100) / SystemLearned_Position);
	         MessageTx_GaragePosition_Remainder = (uint16_t)((uint32_t)(GarageLearned_Position * 100) % SystemLearned_Position);
            }
            else
            {
	         MessageTx_GaragePosition = (uint16_t)((uint32_t)(K_GarageLearned_Position_Default * 100) / SystemLearned_Position);	       
            }
        }
        else
        {
	    if(TRUE == GarageLearned_Status)
            {
                 MessageTx_GaragePosition = (uint16_t)((uint32_t)(GarageLearned_Position * 100) / K_SystemLearned_Position_Default);
	         MessageTx_GaragePosition_Remainder = (uint16_t)((uint32_t)(GarageLearned_Position * 100) % K_SystemLearned_Position_Default);                        
            }
            else
            {
	         MessageTx_GaragePosition = (uint16_t)((uint32_t)(K_GarageLearned_Position_Default * 100) / K_SystemLearned_Position_Default);
	       
            }
        }
    
        if(MessageTx_GaragePosition_Remainder > 0)
        {
	     MessageTx_GaragePosition += K_GaragePosition_Precision_Compensation;
        }
    
        if(MessageTx_GaragePosition > K_MessageTx_GateOpenAngle_Max)
        {
	     MessageTx_GaragePosition = K_MessageTx_GateOpenAngle_Max;
        } 
    }
    else
    {
	 MessageTx_GaragePosition = MessageRx_GarageHeight;
    }
} 
/*********************************************************************************************
** Name:	  MessageTransmit_LearnStatus(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_LearnStatus(void)
{
       MessageTx_SystemLearnedStatus = SystemLearned_Status;
       MessageTx_GarageLearnedStatus = GarageLearned_Status;
       MessageTx_GarageLearnAction = ShutFaceSwitch_LongPress_Status;
       MessageTx_SystemLearnFailure = System_Learn_Failure;
}
#endif

#ifdef _DFMC_COM
/*********************************************************************************************
** Name:	  MessageTransmit_LatchSwitch(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_LatchSwitch(void)
{
      #ifdef _CONFIG_PawlSwitch
      MessageTx_PawlSwitch = PawlSwitch_Status;
      #endif
      #ifdef _CONFIG_SecondarySwitch
      MessageTx_SecondarySwitch = SecondarySwitch_Status;
      #endif
      #ifdef _CONFIG_PositionSwitch
      MessageTx_PositonSwitch = PositionSwitch_Status;
      #endif
      #ifdef _CONFIG_PrimarySwitch
      MessageTx_PrimarySwitch = PrimarySwitch_Status;
      #endif
      #ifdef _CONFIG_ShutFaceSwitch
      MessageTx_ShutFaceSwitch = ShutFaceSwitch_Status;
      #endif
      #ifdef _CONFIG_OpenCloseSwitch
      MessageTx_OpenCloseSwitch = OpenCloseSwitch_Status;
      #endif
      #ifdef _CONFIG_OutsideHandleSwitch
      MessageTx_OutsideHandleSwitch = OutsideHandleSwitch_Status;
      #endif
      
}

/*********************************************************************************************
** Name:	  MessageTransmit_GateOpenAngle(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_GateOpenAngle(void)
{
     static uint8_t GateOpenAngle_Accuracy_Status;
     static uint16_t GateOpenAngle_Accuracy_Timer;
     static uint8_t GateOpenAngle_Real_Disable;
     static uint16_t GateOpenAngle_Accuracy_Position;
     static uint16_t GateOpenAngle_Accuracy_Position_Delta;
     
     static uint16_t MessageTx_GateOpenAngle_Remainder;
     
     #define K_GateOpenAngle_Accuracy_Time 100
     #define K_GateOpenAngle_Accuracy_Position_Delta 10
     
     if(FALSE == GateOpenAngle_Real_Disable)
     {
           if(TRUE == SystemLearned_Status)
           {
                  MessageTx_GateOpenAngle = (uint16_t)((uint32_t)(Motor1_Position * 100) / SystemLearned_Position);	
		  MessageTx_GateOpenAngle_Remainder = (uint16_t)((uint32_t)(Motor1_Position * 100) % SystemLearned_Position);
           }
           else
           {
	          MessageTx_GateOpenAngle = (uint16_t)((uint32_t)(Motor1_Position * 100) / K_MaxPosition_HallCount_Default);
           }
     
           /*if(MessageTx_GateOpenAngle > K_GateOpenAngle_Precision_Compensation)
           {
                  MessageTx_GateOpenAngle -= K_GateOpenAngle_Precision_Compensation;
           }*/
           
	   if(MessageTx_GateOpenAngle_Remainder > 0)
	   {
                  MessageTx_GateOpenAngle = MessageTx_GateOpenAngle + 1;
	   }
     
           if(MessageTx_GateOpenAngle > K_MessageTx_GateOpenAngle_Max)
           {
	         MessageTx_GateOpenAngle = K_MessageTx_GateOpenAngle_Max;
           }
     }
     
     
     /*Accuracy if stop by itself*/    
     if((TRUE == Motor1_NormalEnd_Command_Active)
       ||(TRUE == Motor2_NormalEnd_Command_Active)
       ||(TRUE == Motor1_GarageEnd_Command_Active)
       ||(TRUE == Motor2_GarageEnd_Command_Active))      
     {
	  GateOpenAngle_Accuracy_Status = TRUE;
	  GateOpenAngle_Accuracy_Timer = 0;
     }
     
     if(TRUE == GateOpenAngle_Accuracy_Status)
     {
	  if(MessageTx_GateOpenAngle >= MessageTx_GaragePosition)
	  {
		MessageTx_GateOpenAngle = MessageTx_GaragePosition;
	  }
	  
	  if(((ActiveSystemMode == SystemOpenedFully) && (LastSystemMode == SystemOpenedFully))
	     || ((ActiveSystemMode == SystemReleased) && (LastSystemMode == SystemReleased)))
	  {
	        if(MessageTx_GateOpenAngle < MessageTx_GaragePosition)
	        {
		     MessageTx_GateOpenAngle = MessageTx_GaragePosition;
	        }
		
		GateOpenAngle_Accuracy_Position = Motor1_Position;
		GateOpenAngle_Accuracy_Status = FALSE;		
		GateOpenAngle_Real_Disable = TRUE;
	  }

	  if(GateOpenAngle_Accuracy_Timer >= K_GateOpenAngle_Accuracy_Time)
	  {
		GateOpenAngle_Accuracy_Status = FALSE;
	  }
	  else
	  {
	        GateOpenAngle_Accuracy_Timer ++;
	  }
     }
     
     if(TRUE == GateOpenAngle_Real_Disable)
     {
	  if(Motor1_Position >= GateOpenAngle_Accuracy_Position)
	  {
	        GateOpenAngle_Accuracy_Position_Delta = Motor1_Position - GateOpenAngle_Accuracy_Position;
	  }
	  else
	  {
	        GateOpenAngle_Accuracy_Position_Delta = GateOpenAngle_Accuracy_Position - Motor1_Position;
	  }
	  
	  if(GateOpenAngle_Accuracy_Position_Delta > K_GateOpenAngle_Accuracy_Position_Delta)
	  {
		GateOpenAngle_Real_Disable = FALSE;
	  }
     }
}
/*********************************************************************************************
** Name:	  MessageTransmit_GaragePosition(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_GaragePosition(void)
{
    if(TRUE == SystemLearned_Status)
    {
         if(TRUE == GarageLearned_Status)
         {
               MessageTx_GaragePosition = (uint16_t)((uint32_t)(GarageLearned_Position * 100) / SystemLearned_Position);
	       MessageTx_GaragePosition_Remainder = (uint16_t)((uint32_t)(GarageLearned_Position * 100) % SystemLearned_Position);
         }
         else
         {
	       MessageTx_GaragePosition = (uint16_t)((uint32_t)(K_GarageLearned_Position_Default * 100) / SystemLearned_Position);	       
         }
    }
    else
    {
	 if(TRUE == GarageLearned_Status)
         {
               MessageTx_GaragePosition = (uint16_t)((uint32_t)(GarageLearned_Position * 100) / K_SystemLearned_Position_Default);
	       MessageTx_GaragePosition_Remainder = (uint16_t)((uint32_t)(GarageLearned_Position * 100) % K_SystemLearned_Position_Default);                        
         }
         else
         {
	       MessageTx_GaragePosition = (uint16_t)((uint32_t)(K_GarageLearned_Position_Default * 100) / K_SystemLearned_Position_Default);	       
         }
    }
    
     if(MessageTx_GaragePosition_Remainder > 0)
     {
	  MessageTx_GaragePosition += K_GaragePosition_Precision_Compensation;
     }
    
     if(MessageTx_GaragePosition > K_MessageTx_GateOpenAngle_Max)
     {
	  MessageTx_GaragePosition = K_MessageTx_GateOpenAngle_Max;
     }
     
     if(FALSE == GarageLearned_Status)
     {
	  MessageTx_GaragePosition = K_MessageTx_GaragePosition_100Percent;
     }
    
}

/*********************************************************************************************
** Name:	  MessageTransmit_LearnStatus(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_LearnStatus(void)
{
       MessageTx_SystemLearnedStatus = SystemLearned_Status;
       MessageTx_GarageLearnedStatus = GarageLearned_Status;
       MessageTx_GarageLearnAction = ShutFaceSwitch_LongPress_Status;
       MessageTx_SystemLearnFailure = System_Learn_Failure;
}

/*********************************************************************************************
** Name:	  MessageTransmit_pot_tailgateOpenFailWarning(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_pot_tailgateOpenFailWarning(void)
{
    static uint16_t pot_tailgateOpenFailWarning_Timer; 
    static uint8_t pot_tailgateOpenFailWarning_Status;
    static uint16_t pot_tailgateOpenFailWarning_Check_Timer;
    static uint8_t pot_tailgateOpenFailWarning_Check_Status;
    
    #define K_pot_tailgateOpenFailWarning_Check_Time  10
    #define K_pot_tailgateOpenFailWarning_Time  35
    
    uint8 i;
    
     if((TRUE == BLEOpen_FallEdge_Command_Active)        
	||(TRUE == AppOpen_FallEdge_Command_Active)
	||(TRUE == AutoOpen_FallEdge_Command_Active)
	||(TRUE == VROpen_FallEdge_Command_Active)
	||(TRUE == Motor1_FollowOpen_Command_Active)
	||(TRUE == Motor2_FollowOpen_Command_Active)	
	||((((TRUE == ShutFaceSwitch_FallEdge_Command_Active)&&(ActiveSystemMode == SystemReleased))	
           ||(TRUE == TouchPad_FallEdge_Command_Active)
	   ||(TRUE == DriverButton_FallEdge_Command_Active)
	   ||(TRUE == KickSensor_FallEdge_Command_Active)
	   ||(TRUE == FobLongPress_FallEdge_Command_Active)
	   ||(TRUE == FobShortPress_FallEdge_Command_Active)
	   #ifdef _CONFIG_OpenCloseSwitch
	   ||(TRUE == OpenCloseSwitch_FallEdge_Command_Active)
	   #endif
	  ) && ((ActiveSystemMode == SystemClosedFully) 
	       ||((LastPowerState_ForReversal == SystemPowerClosing) 
	           &&((ActiveSystemMode == SystemReleased)
	              &&(((TRUE == SpindleGarageMode_Status) && (FALSE == GarageEnd_SoftStop_Position_Status))
			 ||(TRUE == SpindleNormalMode_Status)))))))
     {
	   pot_tailgateOpenFailWarning_Check_Status = TRUE;
	   pot_tailgateOpenFailWarning_Check_Timer = 0;
     }
     
     if(TRUE == pot_tailgateOpenFailWarning_Check_Status)
     {
	  if(pot_tailgateOpenFailWarning_Check_Timer >= K_pot_tailgateOpenFailWarning_Check_Time)
	  { 	                     	   
	       pot_tailgateOpenFailWarning_Check_Status = FALSE;
	       pot_tailgateOpenFailWarning_Check_Timer = 0;
	       
	       for(i=0;i<K_StaticTelltales_BuffLen;i++)
               {
	            if(StaticDisplayRequest.array[i] != 0) 
                    {	
		         MessageTx_pot_tailgateOpenFailWarning = _pot_tailgateOpenFailWarning_WARNING;    
	                 pot_tailgateOpenFailWarning_Status = TRUE;
	                 pot_tailgateOpenFailWarning_Timer = 0;
                    }
	       }
	  }
	  else
	  {
	       pot_tailgateOpenFailWarning_Check_Timer ++;
	  }
     }

     if(TRUE == pot_tailgateOpenFailWarning_Status)
     {
          if(pot_tailgateOpenFailWarning_Timer >= K_pot_tailgateOpenFailWarning_Time)
          {
	        MessageTx_pot_tailgateOpenFailWarning = _pot_tailgateOpenFailWarning_NO_WARNING; 
	        pot_tailgateOpenFailWarning_Status = FALSE;
          }
          else
          {
	        pot_tailgateOpenFailWarning_Timer ++;
          }
     }    
}
/*********************************************************************************************
** Name:	  MessageTransmit_pot_tailgateCloseFailWarning(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_pot_tailgateCloseFailWarning(void)
{
    static uint16_t pot_tailgateCloseFailWarning_Timer; 
    static uint8_t pot_tailgateCloseFailWarning_Status;
    static uint16_t pot_tailgateCloseFailWarning_Check_Timer;
    static uint8_t pot_tailgateCloseFailWarning_Check_Status;
    
    #define K_pot_tailgateCloseFailWarning_Check_Time  10
    #define K_pot_tailgateCloseFailWarning_Time  35
    
    uint8_t i;
    
     if((TRUE == BLEClose_FallEdge_Command_Active)        
	||(TRUE == AppClose_FallEdge_Command_Active)
	||(TRUE == AutoClose_FallEdge_Command_Active)
	||(TRUE == VRClose_FallEdge_Command_Active)
	||(TRUE == Motor1_FollowClose_Command_Active)
	||(TRUE == Motor2_FollowClose_Command_Active)	
	||(((TRUE == ShutFaceSwitch_FallEdge_Command_Active)	
           ||(TRUE == TouchPad_FallEdge_Command_Active)
	   ||(TRUE == DriverButton_FallEdge_Command_Active)
	   ||(TRUE == KickSensor_FallEdge_Command_Active)
	   ||(TRUE == FobLongPress_FallEdge_Command_Active)
	   ||(TRUE == FobShortPress_FallEdge_Command_Active)
	   #ifdef _CONFIG_OpenCloseSwitch
	   ||(TRUE == OpenCloseSwitch_FallEdge_Command_Active)
	   #endif
	  ) && (((ActiveSystemMode == SystemOpenedFully) || ((TRUE == SpindleGarageMode_Status) && (TRUE == GarageEnd_SoftStop_Position_Status)))
	       ||((LastPowerState_ForReversal == SystemPowerOpening) && (ActiveSystemMode == SystemReleased)))))
     {
	   pot_tailgateCloseFailWarning_Check_Status = TRUE;
	   pot_tailgateCloseFailWarning_Check_Timer = 0;
     }
     
     if(TRUE == pot_tailgateCloseFailWarning_Check_Status)
     {
	  if(pot_tailgateCloseFailWarning_Check_Timer >= K_pot_tailgateCloseFailWarning_Check_Time)
	  { 	                     	   
	       pot_tailgateCloseFailWarning_Check_Status = FALSE;
	       pot_tailgateCloseFailWarning_Check_Timer = 0;
	       
	       for(i=0;i<K_StaticTelltales_BuffLen;i++)
               {
	            if(StaticDisplayRequest.array[i] != 0) 
                    {	       
		         MessageTx_pot_tailgateCloseFailWarning = _pot_tailgateCloseFailWarning_WARNING;
	                 pot_tailgateCloseFailWarning_Status = TRUE;
	                 pot_tailgateCloseFailWarning_Timer = 0;
		    }
               }
	  }
	  else
	  {
	       pot_tailgateCloseFailWarning_Check_Timer ++;
	  }
     }

     if(TRUE == pot_tailgateCloseFailWarning_Status)
     {
          if(pot_tailgateCloseFailWarning_Timer >= K_pot_tailgateCloseFailWarning_Time)
          {
	        MessageTx_pot_tailgateCloseFailWarning = _pot_tailgateCloseFailWarning_NO_WARNING; 
	        pot_tailgateCloseFailWarning_Status = FALSE;
          }
          else
          {
	        pot_tailgateCloseFailWarning_Timer ++;
          }
     }  
}
/*********************************************************************************************
** Name:	  MessageTransmit_pot_tailgateOpenSts(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_pot_tailgateOpenSts(void)
{
      if(ActiveSystemMode == SystemOpenedFully)
      {
	   MessageTx_pot_tailgateOpenSts = _pot_tailgateOpenSts_Fully_opened;
      }
      else if(ActiveSystemMode == SystemClosedFully)
      {
	   MessageTx_pot_tailgateOpenSts = _pot_tailgateOpenSts_Fully_closed;
      }
      else if(ActiveSystemMode == SystemPowerOpening)
      {
	   MessageTx_pot_tailgateOpenSts = _pot_tailgateOpenSts_Opening;
      }
      else if(ActiveSystemMode == SystemPowerClosing)
      {
	   MessageTx_pot_tailgateOpenSts = _pot_tailgateOpenSts_Closing;
      }
      else if(ActiveSystemMode == SystemReleased)
      {
	   MessageTx_pot_tailgateOpenSts = _pot_tailgateOpenSts_PLG_stopped;
	   
	   /*if((TRUE == GarageEnd_SoftStop_Position_Status) && (TRUE == GarageLearned_Status))
	   {
		MessageTx_pot_tailgateOpenSts = _pot_tailgateOpenSts_Fully_opened;
	   }
	   else
	   {
	        MessageTx_pot_tailgateOpenSts = _pot_tailgateOpenSts_PLG_stopped;
	   }*/
      } 
      else if((ActiveSystemMode == SystemReleaseOnly) || (ActiveSystemMode == SystemReleaseToPowerOpen))
      {
	   MessageTx_pot_tailgateOpenSts = _pot_tailgateOpenSts_Latch_releasing;
      }
      else if((ActiveSystemMode == SystemPowerCinching) || (ActiveSystemMode == SystemPowerParking)
             ||(ActiveSystemMode == SystemManualCinching) || (ActiveSystemMode == SystemManualParking))
      {
	   MessageTx_pot_tailgateOpenSts = _pot_tailgateOpenSts_Latch_cinching;
      }
      else if(ActiveSystemMode == SystemMechFailure)
      {
	   MessageTx_pot_tailgateOpenSts = _pot_tailgateOpenSts_PLG_stopped;
      }
      else
      {
	   MessageTx_pot_tailgateOpenSts = _pot_tailgateOpenSts_Fully_closed;
      }
}
/*********************************************************************************************
** Name:	  MessageTransmit_pot_doorMemoryPosEnb(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_pot_doorMemoryPosEnb(void)
{
     static uint16_t  pot_doorMemoryPosEnb_Timer;
     static uint8_t  pot_doorMemoryPosEnb_Timer_Status;
     
     #define K_pot_doorMemoryPosEnb_Time 35
     
     if(TRUE == GarageLearnedSucessful_Status)
     {
	   GarageLearnedSucessful_Status = FALSE;
	   
	   MessageTx_pot_doorMemoryPosEnb = _pot_doorMemoryPosEnb_Success;
	   
	   pot_doorMemoryPosEnb_Timer_Status = TRUE;
	   pot_doorMemoryPosEnb_Timer = 0;
     }
     
     if(TRUE == pot_doorMemoryPosEnb_Timer_Status)
     {
	   if(pot_doorMemoryPosEnb_Timer >= K_pot_doorMemoryPosEnb_Time)
	   {
		 MessageTx_pot_doorMemoryPosEnb = _pot_doorMemoryPosEnb_No_request;
		 pot_doorMemoryPosEnb_Timer_Status = FALSE;
	   }
	   else
	   {
		 pot_doorMemoryPosEnb_Timer ++;
	   }
     }

}
/*********************************************************************************************
** Name:	  MessageTransmit_pot_antiPlayWarning(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_pot_antiPlayWarning(void)
{
     if(TRUE == PlayTimes_Status)//PlayObstacleTimes_Total_Status)
     {
	   MessageTx_pot_antiPlayWarning = _pot_tailgateOpenFailWarning_WARNING;
     }
     else
     {
	   MessageTx_pot_antiPlayWarning = _pot_tailgateOpenFailWarning_NO_WARNING;
     }
}
/*********************************************************************************************
** Name:	  MessageTransmit_pot_tailgateCloseSwSts(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_pot_tailgateCloseSwSts(void)
{
     if(ShutFaceSwitch_Static_Fault == FaultType_STG)
     {
	   MessageTx_pot_tailgateCloseSwSts = _pot_tailgateCloseSwSts_Stuck;
     }
     else if(TRUE == ShutFaceSwitch_LongPress_Status)
     {
	   MessageTx_pot_tailgateCloseSwSts = _pot_tailgateCloseSwSts_Long_Press;
     }
     else if(TRUE == ShutFaceSwitch_Status)
     {
	   MessageTx_pot_tailgateCloseSwSts = _pot_tailgateCloseSwSts_Press;
     }
     else
     {
	   MessageTx_pot_tailgateCloseSwSts = _pot_tailgateCloseSwSts_Release;
     }
}
/*********************************************************************************************
** Name:	  MessageTransmit_pot_workingSts(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_pot_workingSts(void)
{   
     if(TRUE == SystemLearned_Status)
     {
	  if((TRUE == DTCData_Table.table.Motor1_STG.DTCData.data.DTCStatus.bits.TestFailed) 
             ||(TRUE == DTCData_Table.table.Motor1_STB.DTCData.data.DTCStatus.bits.TestFailed)
	     ||(TRUE == DTCData_Table.table.Motor1_OC.DTCData.data.DTCStatus.bits.TestFailed)
	     ||(TRUE == DTCData_Table.table.Motor2_STG.DTCData.data.DTCStatus.bits.TestFailed) 
             ||(TRUE == DTCData_Table.table.Motor2_STB.DTCData.data.DTCStatus.bits.TestFailed)
	     ||(TRUE == DTCData_Table.table.Motor2_OC.DTCData.data.DTCStatus.bits.TestFailed)
	     ||(TRUE == DTCData_Table.table.CinchMotor_STG.DTCData.data.DTCStatus.bits.TestFailed)
             ||(TRUE == DTCData_Table.table.CinchMotor_STB.DTCData.data.DTCStatus.bits.TestFailed)
             ||(TRUE == DTCData_Table.table.CinchMotor_OC.DTCData.data.DTCStatus.bits.TestFailed)
	     ||(TRUE == DTCData_Table.table.HallA1_NoHall.DTCData.data.DTCStatus.bits.TestFailed)
             ||(TRUE == DTCData_Table.table.HallA2_NoHall.DTCData.data.DTCStatus.bits.TestFailed)
	     ||(TRUE == DTCData_Table.table.HallB1_NoHall.DTCData.data.DTCStatus.bits.TestFailed)
             ||(TRUE == DTCData_Table.table.HallB2_NoHall.DTCData.data.DTCStatus.bits.TestFailed)
             ||(TRUE == DTCData_Table.table.BatteryVoltage_VolAbove.DTCData.data.DTCStatus.bits.TestFailed)
	     ||(TRUE == DTCData_Table.table.BatteryVoltage_VolBelow.DTCData.data.DTCStatus.bits.TestFailed)
	    )  
          {
	       MessageTx_pot_workingSts = _pot_workingSts_Abnormality;
          }
          else
          {
	        MessageTx_pot_workingSts = _pot_workingSts_Normal;
          }
     }
     else
     {
	  MessageTx_pot_workingSts = _pot_workingSts_Initializing;
     }
}
/*********************************************************************************************
** Name:	  MessageTransmit_pot_OpenTurnIndicator(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_pot_OpenTurnIndicator(void)
{
     static uint16_t  pot_OpenTurnIndicator_Timer;
     static uint8_t  pot_OpenTurnIndicator_Timer_Status;
     #define K_pot_OpenTurnIndicator_Time   35
     
     if(FlashRemind_Request == Remind_1)	       
     {
	    FlashRemind_Request = No_Remind;
	    
	    MessageTx_pot_OpenTurnIndicator = _pot_OpenTurnIndicator_UserOperationAcception;
	    pot_OpenTurnIndicator_Timer_Status = TRUE;
	    pot_OpenTurnIndicator_Timer = 0;
     }
     else if(FlashRemind_Request == Remind_2)	       
     {
	    FlashRemind_Request = No_Remind;
	    
	    MessageTx_pot_OpenTurnIndicator = _pot_OpenTurnIndicator_MemoryPosition;
	    pot_OpenTurnIndicator_Timer_Status = TRUE;
	    pot_OpenTurnIndicator_Timer = 0;
     }
     else if(FlashRemind_Request == Remind_3)	       
     {
	    FlashRemind_Request = No_Remind;
	    
	    MessageTx_pot_OpenTurnIndicator = _pot_OpenTurnIndicator_UserOperationDenid;
	    pot_OpenTurnIndicator_Timer_Status = TRUE;
	    pot_OpenTurnIndicator_Timer = 0;
     }
     else if(FlashRemind_Request == Remind_4)	       
     {
	    FlashRemind_Request = No_Remind;
	    
	    MessageTx_pot_OpenTurnIndicator = _pot_OpenTurnIndicator_AntiPinchReverse;
	    pot_OpenTurnIndicator_Timer_Status = TRUE;
	    pot_OpenTurnIndicator_Timer = 0;
     }
     else if(FlashRemind_Request == Remind_5)	       
     {
	    FlashRemind_Request = No_Remind;
	    
	    MessageTx_pot_OpenTurnIndicator = _pot_OpenTurnIndicator_ForceStop;
	    pot_OpenTurnIndicator_Timer_Status = TRUE;
	    pot_OpenTurnIndicator_Timer = 0;
     }  
     else if(FlashRemind_Request == Remind_6)	       
     {
	    FlashRemind_Request = No_Remind;
	    
	    MessageTx_pot_OpenTurnIndicator = _pot_OpenTurnIndicator_MemoryPositionFault;
	    pot_OpenTurnIndicator_Timer_Status = TRUE;
	    pot_OpenTurnIndicator_Timer = 0;
     }
     else if(FlashRemind_Request == Remind_7)	       
     {
	    FlashRemind_Request = No_Remind;
	    
	    MessageTx_pot_OpenTurnIndicator = _pot_OpenTurnIndicator_Warning;
	    pot_OpenTurnIndicator_Timer_Status = TRUE;
	    pot_OpenTurnIndicator_Timer = 0;
     }
     
     if(TRUE == pot_OpenTurnIndicator_Timer_Status)
     {
	    if(pot_OpenTurnIndicator_Timer >= K_pot_OpenTurnIndicator_Time)
	    {
		   MessageTx_pot_OpenTurnIndicator = _pot_OpenTurnIndicator_Off;
		   pot_OpenTurnIndicator_Timer_Status = FALSE;
		   pot_OpenTurnIndicator_Timer = 0;
	    }
	    else
	    {
		   pot_OpenTurnIndicator_Timer ++;
	    }
     }
}
/*********************************************************************************************
** Name:	  MessageTransmit_pot_NeutralSWSts(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_pot_NeutralSWSts(void)
{
}
/*********************************************************************************************
** Name:	  MessageTransmit_pot_MotorOverTempProtection(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_pot_MotorOverTempProtection(void)
{
     if(TRUE == SystemTemperatureProtection_Status)
     {
	   MessageTx_pot_MotorOverTempProtection = _pot_MotorOverTempProtection_Protecting_mode;
     }
     else
     {
	   MessageTx_pot_MotorOverTempProtection = _pot_MotorOverTempProtection_Normal_mode;
     }
}
/*********************************************************************************************
** Name:	  MessageTransmit_pot_delayClosingPotReq(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_pot_delayClosingPotReq(void)
{
}
#endif

#ifdef _MAXUS_COM
#ifdef _MAXUS_COM_PLG
#ifdef _CONFIG_DTCPush_DTCStatusAllBit_Cycles
/*********************************************************************************************
** Name:	  MessageTransmit_PLG_ErrPush(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_PLG_ErrPush(void)
{
   uint8_t i;
   
   static uint8_t Tx_PLG_ErrPush_Timer;
   
   static uint8_t Tx_Index_Max;   
   static uint8 Tx_DTC_Index[NUM_OF_DTC];
   static uint8 Tx_DTC_Index_Last[NUM_OF_DTC];
   static uint8_t Tx_Index; 
   
   static uint8_t PLGDTC_Start_Status;
   static uint8_t PLGDTC_New_Start_Status;
   static uint8_t Com_SetSendRequest_Status;
   
   static uint8_t DTCDisplayEnable_Bit;
   static uint8_t DTCDisplayEnable_Byte;

   #define K_Tx_PLG_ErrPush_Time 100
   #define K_Tx_PLG_ErrPush_Time_1st_Compensation 10

      
   if(Tx_PLG_ErrPush_Timer >= K_Tx_PLG_ErrPush_Time)
   {
	Tx_PLG_ErrPush_Timer = 0;
	
	/*Tx_DTC_Index_Last*/
	for(i=0;i<NUM_OF_DTC;i++)
        {
	     Tx_DTC_Index_Last[i] = Tx_DTC_Index[i];
	}
	/*Looking for Current DTC*/
	Tx_Index_Max = 0;
	for(i=0;i<NUM_OF_DTC;i++)
        {
	    DTCDisplayEnable_Bit = i%8;
            DTCDisplayEnable_Byte = i/8;
	    
	    if((MAXUSCAN_DTCDisplayEnable[DTCDisplayEnable_Byte]&(0x01<<(7-DTCDisplayEnable_Bit))) != 0x00)
	    {
                 if((DTCStatus[i] & 0x02) == 0x02)
                 {    	    
                      Tx_DTC_Index[Tx_Index_Max] = i;
	              Tx_Index_Max ++;
                 }
	    }
	}
	for(i=Tx_Index_Max;i<NUM_OF_DTC;i++)
        {
            Tx_DTC_Index[i] = 0;
	}
	
	if(Tx_Index_Max > 0)
	{
	     PLGDTC_Start_Status = TRUE;
	}
	else
	{
             PLGDTC_Start_Status = FALSE;
	}
	
	/*Compare PLGDTC*/
	for(i=0;i<NUM_OF_DTC;i++)
        {
	     if(Tx_DTC_Index_Last[i] != Tx_DTC_Index[i])
	     {
		  PLGDTC_New_Start_Status = TRUE;
	     }
	}
	
	if(TRUE == PLGDTC_Start_Status)
        {     
	     if(TRUE == PLGDTC_New_Start_Status)
	     {
		  Tx_Index = 0;
		  PLGDTC_New_Start_Status = FALSE;
	     }	     
	     
	     if((Tx_DTC_Index[Tx_Index] == 0) || (Tx_DTC_Index[Tx_Index] == 1))
	     {
	          TxIpduPLG_ErrPush.Ipdu.PLGDTCSeriousLvl = 0x01;
		  
		  //Tx_Index = 0;
	     }
	     else if((Tx_DTC_Index[Tx_Index] >= 16) && (Tx_DTC_Index[Tx_Index] <= 28))
	     {
		  TxIpduPLG_ErrPush.Ipdu.PLGDTCSeriousLvl = 0x02;  
	     }
	     else
	     {
		  TxIpduPLG_ErrPush.Ipdu.PLGDTCSeriousLvl = 0x03;
	     }
	     
	     TxIpduPLG_ErrPush.Ipdu.PLGDTCHiByte = (SupportedDTC[Tx_DTC_Index[Tx_Index]] >> 16);
	     TxIpduPLG_ErrPush.Ipdu.PLGDTCLowByte = (SupportedDTC[Tx_DTC_Index[Tx_Index]] >> 8);
	     TxIpduPLG_ErrPush.Ipdu.PLGDTCFlrTypByte = SupportedDTC[Tx_DTC_Index[Tx_Index]];
	     TxIpduPLG_ErrPush.Ipdu.PLGDTCSts = DTCStatus[Tx_DTC_Index[Tx_Index]];
	     TxIpduPLG_ErrPush.Ipdu.PLGDTCTyp = _PLGDTCTyp_Tpye_E;
	     
	     if(Tx_Index >= (Tx_Index_Max - 1))
	     {
		  Tx_Index  = 0;
	     }
	     else
	     {
	          Tx_Index ++;
	     }
	     
	     /*Adjust Message Period*/
	     if(FALSE == Com_SetSendRequest_Status)
	     {
		  Com_SetSendRequest_Status = TRUE;
		  Com_ActiveSig(COM_TXSIGPLGDTCTyp);
	          Com_SetSendRequest(COM_TXSIGPLGDTCTyp);
		  
		  Tx_PLG_ErrPush_Timer = K_Tx_PLG_ErrPush_Time_1st_Compensation;
	     }   
        }
	else
	{
	     if(TRUE == Com_SetSendRequest_Status)
	     {
		  Com_SetSendRequest_Status = FALSE;
	          Com_DisactiveSig(COM_TXSIGPLGDTCTyp);
	          Com_SetSendRequest(COM_TXSIGPLGDTCTyp);
	     }   
	}
   }
   else
   {
	Tx_PLG_ErrPush_Timer ++;
   } 	  
}
#endif

#ifdef _CONFIG_DTCPush_DTCStatusBit1_OneTime
/*********************************************************************************************
** Name:	  MessageTransmit_PLG_ErrPush(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_PLG_ErrPush(void)
{
     uint8_t i;
   
     static uint16_t Tx_PLG_ErrPush_Start_Timer;
     
     static uint8_t Last_DTCStatus[NUM_OF_DTC];
     static uint8_t DTC_PushStatus[NUM_OF_DTC];
     static uint8_t CurrentPushIndex;
     static uint8_t CurrentPushIndex_Status;    
     static uint8_t Tx_CurrentPush_Status;
     static uint16_t Tx_CurrentPush_Timer;
     static uint8_t Tx_Condtion_Bus_Off;
     
     static uint8_t Com_SetSendRequest_Status;
   
     static uint8_t DTCDisplayEnable_Bit;
     static uint8_t DTCDisplayEnable_Byte;

     #define K_Tx_PLG_ErrPush_Start_Time 10
     #define K_Tx_CurrentPush_Time 100
     #define K_Tx_CurrentPush_Time_1st_Delay 10
     
     if(Tx_PLG_ErrPush_Start_Timer >= K_Tx_PLG_ErrPush_Start_Time)
     {	
	  /*Looking for Current DTC*/
          for(i=0;i<NUM_OF_DTC;i++)
          {
	       DTCDisplayEnable_Bit = i%8;
               DTCDisplayEnable_Byte = i/8;
	    
	       if((MAXUSCAN_DTCDisplayEnable[DTCDisplayEnable_Byte]&(0x01<<(7-DTCDisplayEnable_Bit))) != 0x00)
	       {
                    if(((DTCStatus[i]&0x02) == 0x02) && ((Last_DTCStatus[i]&0x02) == FALSE))
                    {    	    
                         DTC_PushStatus[i] = TRUE;
                    }
	    
	            Last_DTCStatus[i] = DTCStatus[i];
	       }
          }
	  
	  /*Bus_Off Tx_Condtion*/
	  if((DTCStatus[16]&0x01) != TRUE )
	  {
	       Tx_Condtion_Bus_Off = TRUE;
	  }
	  else
	  {
	       Tx_Condtion_Bus_Off = FALSE;
	  }
	  
	  /*Looking for CurrentPushIndex*/
	  if((FALSE == Tx_CurrentPush_Status) && (TRUE == Tx_Condtion_Bus_Off))
	  {
	       CurrentPushIndex_Status = FALSE;
	       for(i=0;i<NUM_OF_DTC;i++)
               {
	            if((DTC_PushStatus[i] == TRUE) && (FALSE == CurrentPushIndex_Status))
	            {
		          CurrentPushIndex_Status = TRUE;
		          CurrentPushIndex = i;
	            } 	       
	       }
	  }
	  
	  /*PLG_ErrPush 3 Frames*/	  
	  if((TRUE == CurrentPushIndex_Status) && (TRUE == Tx_Condtion_Bus_Off))
	  {
	       if(FALSE == Tx_CurrentPush_Status)
	       {
		    Tx_CurrentPush_Status = TRUE;
		    Tx_CurrentPush_Timer = 0;
		    
		    DTC_PushStatus[CurrentPushIndex] = FALSE;
		    
	            if((CurrentPushIndex == 0) || (CurrentPushIndex == 1))
	            {
	                  TxIpduPLG_ErrPush.Ipdu.PLGDTCSeriousLvl = 0x01;
	            }
		    else if((CurrentPushIndex >= 16) && (CurrentPushIndex <= 28))
	     	    {
		          TxIpduPLG_ErrPush.Ipdu.PLGDTCSeriousLvl = 0x02;  
	            }
	            else
	            {
		          TxIpduPLG_ErrPush.Ipdu.PLGDTCSeriousLvl = 0x03;
	            }
	     
	            TxIpduPLG_ErrPush.Ipdu.PLGDTCHiByte = (SupportedDTC[CurrentPushIndex] >> 16);
	            TxIpduPLG_ErrPush.Ipdu.PLGDTCLowByte = (SupportedDTC[CurrentPushIndex] >> 8);
	            TxIpduPLG_ErrPush.Ipdu.PLGDTCFlrTypByte = SupportedDTC[CurrentPushIndex];
	            TxIpduPLG_ErrPush.Ipdu.PLGDTCSts = 0x0b;//DTCStatus[CurrentPushIndex];
	            TxIpduPLG_ErrPush.Ipdu.PLGDTCTyp = _PLGDTCTyp_Tpye_E;
	       }
	     
	       if(FALSE == Com_SetSendRequest_Status)
	       {
		    Com_SetSendRequest_Status = TRUE;
		  
		    Com_ActiveSig(COM_TXSIGPLGDTCTyp);
	            Com_SetSendRequest(COM_TXSIGPLGDTCTyp);
		    
		    Tx_CurrentPush_Timer = K_Tx_CurrentPush_Time_1st_Delay;
	       } 
	       
	       if(TRUE == Tx_CurrentPush_Status)
	       {
		    if(Tx_CurrentPush_Timer >= K_Tx_CurrentPush_Time)
		    {
			  Tx_CurrentPush_Status = FALSE;
			  Tx_CurrentPush_Timer = 0;
		    }
		    else
		    {
			  Tx_CurrentPush_Timer ++;
		    }
	       }
	  } 
	  else
	  {
	       if((TRUE == Com_SetSendRequest_Status) && (TRUE == Tx_Condtion_Bus_Off))
	       {
		    Com_SetSendRequest_Status = FALSE;
	            Com_DisactiveSig(COM_TXSIGPLGDTCTyp);
	            Com_SetSendRequest(COM_TXSIGPLGDTCTyp);
	       }   
	  }
     }
     else
     {
	  Tx_PLG_ErrPush_Start_Timer ++;
     } 	  
}
#endif

/*********************************************************************************************
** Name:	  MessageTransmit_DiagSession(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_DiagSession(void)
{
     if(gSesCtrlType == DCM_SESSION_DEFAULT)
     {
           MessageTx_DiagSession = _PLG_MCUDiagSession_DefaultSessioninApp;
     }
     else if(gSesCtrlType == DCM_SESSION_EXTENDED_DIAGNOSTIC)
     {
           MessageTx_DiagSession = _PLG_MCUDiagSession_ExtendedSessioninApp;
     }

}
/*********************************************************************************************
** Name:	  MessageTransmit_FastCycle_Monitor(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_FastCycle_Monitor(void)
{
     static uint8_t MessageTx_FastCycle_Timer_Status;
     static uint16_t MessageTx_FastCycle_Timer;
     static uint16_t MessageTx_FastCycle_Delay_Timer;

        if((TRUE == ShutFaceSwitch_FallEdge_Active)
        ||(TRUE == ShutFaceSwitch_LongPress_Active)
        ||(TRUE == OpenCloseSwitch_FallEdge_Active)
        //||(TRUE == OutsideHandleSwitch_FallEdge_Active)
        ||(TRUE == TouchPad_FallEdge_Active)
        //||(TRUE == RemoteKey_FallEdge_Active)
	||(TRUE == FobLongPress_FallEdge_Active)
	||(TRUE == FobShortPress_FallEdge_Active)
        ||(TRUE == KickSensor_FallEdge_Active)	
	||(TRUE == AntiFalseLock_FallEdge_Active)
        //||(TRUE == AppOpen_FallEdge_Active)
        //||(TRUE == AppClose_FallEdge_Active)
        ||(TRUE == VROpen_FallEdge_Active)
        ||(TRUE == VRClose_FallEdge_Active)
	||(TRUE == DriverButton_FallEdge_Active)
        ||(TRUE == ManualRelease_FallEdge_Active)
	//||(TRUE == Motor1_FollowClose_Command_Active)
	//||(TRUE == Motor1_FollowOpen_Command_Active)
	)
     {	  
	  MessageTx_FastCycle_Timer_Status = TRUE;
	  MessageTx_FastCycle_Timer = 0;
	  
	  Com_ActiveSig(0);
	  Com_SetSendRequest(0);
     }
     else if((TRUE == PositionSwitch_FallEdge_Active)
            ||(TRUE == PawlSwitch_FallEdge_Active)
            ||(TRUE == SecondarySwitch_FallEdge_Active))
     {
	  MessageTx_FastCycle_Timer_Status = TRUE;
	  MessageTx_FastCycle_Timer = 0;
	  
	  Com_ActiveSig(0);
	  Com_SetSendRequest(0);
     }
     else if((TRUE == Motor1_FollowClose_Command_Active)
            ||(TRUE == FollowOperate_SlamClose_Command_Active)
	    ||(TRUE == Motor1_ManualMoving_FallEdge_Active))
     {
	  MessageTx_FastCycle_Timer_Status = TRUE;
	  MessageTx_FastCycle_Timer = 0;
	  
	  Com_ActiveSig(0);
	  Com_SetSendRequest(0);
     }
     else if(((TRUE == FastCycle_AfterPowerUp_Status)
            ||(TRUE == FastCycle_AfterWakeup_Status)
	    ||(TRUE == FastCycle_FromReset_Status))
	    &&(TRUE == Com_TxStart_Start_Status))
     {
	  if(MessageTx_FastCycle_Delay_Timer >= K_MessageTx_FastCycle_Delay_Time)
	  {
	        FastCycle_AfterPowerUp_Status = FALSE;
                FastCycle_AfterWakeup_Status = FALSE;
                FastCycle_FromReset_Status = FALSE;
	  
	        MessageTx_FastCycle_Timer_Status = TRUE;
	        MessageTx_FastCycle_Timer = 0;
	  
	        Com_ActiveSig(0);
	        Com_SetSendRequest(0);
	  }
	  else
	  {
	       	MessageTx_FastCycle_Delay_Timer ++;
	  }

     }
     else if((ActiveSystemMode == SystemReleaseToPowerOpen)
             ||(ActiveSystemMode == SystemPowerOpening)
	     ||(ActiveSystemMode == SystemPowerClosing) 
             ||(ActiveSystemMode == SystemPowerCinching)
	     ||(ActiveSystemMode == SystemPowerParking)
	     ||(ActiveSystemMode == SystemManualCinching)
	     ||(ActiveSystemMode == SystemManualParking)
	     ||(TRUE == Motor1_ManualMoving_Status))
     {
	  MessageTx_FastCycle_Timer_Status = TRUE;
	  MessageTx_FastCycle_Timer = 0;
	  
	  Com_ActiveSig(0);
	  Com_SetSendRequest(0);
     }

     if(TRUE == MessageTx_FastCycle_Timer_Status)
     {
         if(MessageTx_FastCycle_Timer >= K_MessageTx_FastCycle_Time)
         {
	       MessageTx_FastCycle_Timer_Status = FALSE; 
	       
	       Com_DisactiveSig(0);
	       Com_SetSendRequest(0);
         }
         else
         {
	       MessageTx_FastCycle_Timer ++;
         }
     }
}
/*********************************************************************************************
** Name:	  MessageTransmit_LatchSwitch(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_LatchSwitch(void)
{
      #ifdef _CONFIG_PawlSwitch
      MessageTx_PawlSwitch = PawlSwitch_Status;
      #endif
      #ifdef _CONFIG_SecondarySwitch
      MessageTx_SecondarySwitch = SecondarySwitch_Status;
      #endif
      #ifdef _CONFIG_PositionSwitch
      MessageTx_PositonSwitch = PositionSwitch_Status;
      #endif
      #ifdef _CONFIG_PrimarySwitch
      MessageTx_PrimarySwitch = PrimarySwitch_Status;
      #endif
      #ifdef _CONFIG_ShutFaceSwitch
      MessageTx_ShutFaceSwitch = ShutFaceSwitch_Status;
      #endif
      #ifdef _CONFIG_OpenCloseSwitch
      MessageTx_OpenCloseSwitch = OpenCloseSwitch_Status;
      #endif
      
}

/*********************************************************************************************
** Name:	  MessageTransmit_PLGECUSts(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_PLGECUSts(void)
{
     /*if(TRUE == System_AfterPowerUp_Status)
     {
	  MessageTx_PLGECUSts = _PLGECUSts_Init;
     }
     else
     {
	  MessageTx_PLGECUSts = _PLGECUSts_Normal;
     }*/
     
     if(TRUE == SystemLearned_Status)
     {
	  MessageTx_PLGECUSts = _PLGECUSts_Normal;
     }
     else
     {
	  MessageTx_PLGECUSts = _PLGECUSts_Init;
     }
}
/*********************************************************************************************
** Name:	  MessageTransmit_TlgtOprt(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_TlgtOprt(void)
{
     if(TRUE ==  Motor1_Working_Status)
     {
	  if(Motor1_Direction_Request == Direction_Open)
	  {
		MessageTx_TlgtOprt = _TlgtOprt_Opening;
	  }
	  else if(Motor1_Direction_Request == Direction_Close)
	  {
		MessageTx_TlgtOprt = _TlgtOprt_Closing;
	  }
	  else
	  {
		MessageTx_TlgtOprt = _TlgtOprt_Hold;
	  }
     }
     else
     {
	  MessageTx_TlgtOprt = _TlgtOprt_Hold;
     }	
      /*if((ActiveSystemMode == SystemPowerOpening) 
            || (ActiveSystemMode == SystemReleaseToPowerOpen))
      {
	   MessageTx_TlgtOprt = _TlgtOprt_Opening;
      }
      else if((ActiveSystemMode == SystemPowerClosing) 
            || (ActiveSystemMode == SystemPowerCinching)
	    || (ActiveSystemMode == SystemPowerParking))
      {
	   MessageTx_TlgtOprt = _TlgtOprt_Closing;
      }
      else if((ActiveSystemMode == SystemReleased) 
            || (ActiveSystemMode == SystemOpenedFully)
            || (ActiveSystemMode == SystemMechFailure)
	    || (ActiveSystemMode == SystemClosedFully)
	    || (ActiveSystemMode == SystemReleaseOnly))
      {
	   MessageTx_TlgtOprt = _TlgtOprt_Hold;
      }
      else
      {
	   MessageTx_TlgtOprt = _TlgtOprt_Status_Unkown;
      }*/
}
/*********************************************************************************************
** Name:	  MessageTransmit_TlgtPosSts(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_TlgtPosSts(void)
{
     if((TRUE == PawlSwitch_Status) && (TRUE == SecondarySwitch_Status))
     {
	   MessageTx_TlgtPosSts = _TlgtPosSts_Open;
     }
     else if((TRUE == PawlSwitch_Status) && (FALSE == SecondarySwitch_Status))
     {
	   MessageTx_TlgtPosSts = _TlgtPosSts_HalfLocked;
     }
     else if((FALSE == PawlSwitch_Status) && (FALSE == SecondarySwitch_Status))
     {
	   MessageTx_TlgtPosSts = _TlgtPosSts_FullyClosed;
     }
     else
     {
	   MessageTx_TlgtPosSts = _TlgtPosSts_Status_Unkown;
     }
      
      /*if(ActiveLatchMode == LatchFullyCinched)
      {
	   MessageTx_TlgtPosSts = _TlgtPosSts_FullyClosed;
      }
      else if((ActiveLatchMode == LatchPreCinchCheck) || (ActiveLatchMode == LatchPowerCinching)
            || (ActiveLatchMode == LatchFindHomeAfterCinch))
      {
	   MessageTx_TlgtPosSts = _TlgtPosSts_HalfLocked;
      }
      else if((ActiveLatchMode == LatchPreReleasing)|| (ActiveLatchMode == LatchPowerReleasing)
             || (ActiveLatchMode == LatchFindHomeAfterRelease) || (ActiveLatchMode == LatchPreReleased))
      {
	   MessageTx_TlgtPosSts = _TlgtPosSts_HalfLocked;
      }
      else if(ActiveLatchMode == LatchFullyReleased)
      {
	   MessageTx_TlgtPosSts = _TlgtPosSts_Open;
      }
      else
      {
	   MessageTx_TlgtPosSts = _TlgtPosSts_Status_Unkown;
      }*/
}
/*********************************************************************************************
** Name:	  MessageTransmit_TlgtPinchRvsEvt  (void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_TlgtPinchRvsEvt(void)
{
     static uint16_t MessageTx_TlgtPinchRvsEvt_Timer;

     if(DynamicDisplayRequest.bits.AntipinchPressedLeft == TRUE) 
     {
	  DynamicDisplayRequest.bits.AntipinchPressedLeft = FALSE;
	  
	  MessageTx_TlgtPinchRvsEvt = _TlgtPinchRvsEvt_Pinch_Occurred;
	  MessageTx_TlgtPinchRvsEvt_Timer = 0;
     }
     else if(DynamicDisplayRequest.bits.AntipinchPressed == TRUE) 
     {
	  DynamicDisplayRequest.bits.AntipinchPressed = FALSE;
	  
	  MessageTx_TlgtPinchRvsEvt = _TlgtPinchRvsEvt_Pinch_Occurred;
	  MessageTx_TlgtPinchRvsEvt_Timer = 0;
     }
 
     if(MessageTx_TlgtPinchRvsEvt_Timer >= K_MessageTx_TlgtPinchRvsEvt_Time)
     {
	  MessageTx_TlgtPinchRvsEvt = _TlgtPinchRvsEvt_Normal; 
     }
     else
     {
	  MessageTx_TlgtPinchRvsEvt_Timer ++;
     }
}
/*********************************************************************************************
** Name:	  MessageTransmit_TlgtStlEvt(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_TlgtStlEvt(void)
{
     static uint16_t MessageTx_TlgtStlEvt_Timer;

     if(DynamicDisplayRequest.bits.Motor1Obstacle == TRUE) 
     {
	  DynamicDisplayRequest.bits.Motor1Obstacle = FALSE;
	  
	  MessageTx_TlgtStlEvt = _TlgtStlEvt_Stall_Occurred;
	  MessageTx_TlgtStlEvt_Timer = 0;
     }
 
     if(MessageTx_TlgtStlEvt_Timer >= K_MessageTx_TlgtStlEvt_Time)
     {
	  MessageTx_TlgtStlEvt = _TlgtStlEvt_Normal; 
     }
     else
     {
	  MessageTx_TlgtStlEvt_Timer ++;
     }
}
/*********************************************************************************************
** Name:	  MessageTransmit_TlgtLtchSts(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_TlgtLtchSts(void)
{
      if(ActiveLatchMode == LatchFullyCinched)
      {
	   MessageTx_TlgtLtchSts = _TlgtLtchSts_Latch_Locked;
      }
      else if((ActiveLatchMode == LatchPreCinchCheck) || (ActiveLatchMode == LatchPowerCinching))
      {
	   MessageTx_TlgtLtchSts = _TlgtLtchSts_Latch_Cinching;
      }
      else if(ActiveLatchMode == LatchFindHomeAfterCinch)
      {
	   MessageTx_TlgtLtchSts = _TlgtLtchSts_LatchReseting_After_Cinching;
      }
      else if((ActiveLatchMode == LatchPreReleasing)|| (ActiveLatchMode == LatchPowerReleasing))
      {
	   MessageTx_TlgtLtchSts = _TlgtLtchSts_Latch_Releasing;
      }
      else if(ActiveLatchMode == LatchFindHomeAfterRelease)
      {
	   MessageTx_TlgtLtchSts = _TlgtLtchSts_LatchReseting_After_Releasing;
      }
      else if(ActiveLatchMode == LatchPreReleased)
      {
	   MessageTx_TlgtLtchSts = _TlgtLtchSts_Latch_HalfLocked;
      }
      else if(ActiveLatchMode == LatchFullyReleased)
      {
	   MessageTx_TlgtLtchSts = _TlgtLtchSts_Latch_UnLocked;
      }
      else
      {
	   MessageTx_TlgtLtchSts = _TlgtLtchSts_Status_Unkown;
      }
}
/*********************************************************************************************
** Name:	  MessageTransmit_TlgtOprtMd(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_TlgtOprtMd(void)
{
     if(FALSE == SystemLearned_Status)
     {
	    MessageTx_TlgtOprtMd =_TlgtOprtMd_SelfLearning_Unfinished;
     }
     else if(TRUE == SpindleDisableMode_Status)
     {
	   MessageTx_TlgtOprtMd = _TlgtOprtMd_Manual;
     }
     else if(TRUE == SpindleGarageMode_Status)
     {
	   MessageTx_TlgtOprtMd = _TlgtOprtMd_Park;
     }
     else
     {
	   MessageTx_TlgtOprtMd = _TlgtOprtMd_Norm;
     }
}
/*********************************************************************************************
** Name:	  MessageTransmit_TlgtLtchOvht(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_TlgtLtchOvht(void)
{
     MessageTx_TlgtLtchOvht = CinchMotor_ThermalProtection_Status;
}
/*********************************************************************************************
** Name:	  MessageTransmit_TlgtSpdlOvht(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_TlgtSpdlOvht(void)
{
     MessageTx_TlgtSpdlOvht = Motor1_ThermalProtection_Status;
}
/*********************************************************************************************
** Name:	  MessageTransmit_TlgtAPSSts_L(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_TlgtAPSSts_L(void)
{     
     if(AntiPinchLeft_Static_Fault == FaultType_STG)
     {
	   MessageTx_TlgtAPSSts_L = _TlgtAPSSts_Error_Short;
     }
     else if(AntiPinchLeft_Static_Fault == FaultType_STBorOC)
     {
	   MessageTx_TlgtAPSSts_L = _TlgtAPSSts_Error_Open;
     }
     else if(AntiPinchLeft_Static_Fault == FaultType_NoFault)
     {
	   MessageTx_TlgtAPSSts_L = _TlgtAPSSts_Normal;
     }
     else if(AntiPinchLeft_Static_Fault == FaultType_APSActive)
     {
	   MessageTx_TlgtAPSSts_L = _TlgtAPSSts_Sampling_Error;
     }
  
}
/*********************************************************************************************
** Name:	  MessageTransmit_TlgtAPSSts_R(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_TlgtAPSSts_R(void)
{
     if(AntiPinchRight_Static_Fault == FaultType_STG)
     {
	   MessageTx_TlgtAPSSts_R = _TlgtAPSSts_Error_Short;
     }
     else if(AntiPinchRight_Static_Fault == FaultType_STBorOC)
     {
	   MessageTx_TlgtAPSSts_R = _TlgtAPSSts_Error_Open;
     }
     else if(AntiPinchRight_Static_Fault == FaultType_NoFault)
     {
	   MessageTx_TlgtAPSSts_R = _TlgtAPSSts_Normal;
     }
     else if(AntiPinchRight_Static_Fault == FaultType_APSActive)
     {
	   MessageTx_TlgtAPSSts_R = _TlgtAPSSts_Sampling_Error;
     }
}
/*********************************************************************************************
** Name:	  MessageTransmit_TlgtSpdlMtrSts(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_TlgtCnchMtrSts(void)
{
     if((CinchMotor_Static_Fault == FaultType_STG)
       ||(CinchMotor_Static_Fault == FaultType_STB)
       ||(CinchMotor_Static_Fault == FaultType_OC))
     {
	   MessageTx_TlgtCnchMtrSts = _MtrSts_Error;
     }
     else
     {
	   MessageTx_TlgtCnchMtrSts = _MtrSts_Normal;
     }
}
/*********************************************************************************************
** Name:	  MessageTransmit_TlgtSpdlMtrSts(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_TlgtSpdlMtrSts(void)
{
     if((Motor1_Static_Fault == FaultType_STG) || (Motor1_Dynamic_Fault == FaultType_STG)
       ||(Motor1_Static_Fault == FaultType_STB) || (Motor1_Dynamic_Fault == FaultType_STB)
       ||(Motor1_Static_Fault == FaultType_OC) || (Motor1_Dynamic_Fault == FaultType_OC))
     {
	   MessageTx_TlgtSpdlMtrSts = _MtrSts_Error;
     }
     else
     {
	   MessageTx_TlgtSpdlMtrSts = _MtrSts_Normal;
     }
}

/*********************************************************************************************
** Name:	  MessageTransmit_TlgtBuzReq(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_TlgtBuzReq(void)
{
    static uint16_t MessageTx_TlgtBuzReq_Timer;    
     if(ChimeRemind_Request != No_Remind)
     {
	  if(ChimeRemind_Request == Remind_1)
	  {
	       ChimeRemind_Request = No_Remind;
	       MessageTx_TlgtBuzReq = _TlgtBuzReq_LongBeep_1_Time;
	  }
	  else if(ChimeRemind_Request == Remind_2)
	  {
	       ChimeRemind_Request = No_Remind;
	       MessageTx_TlgtBuzReq = _TlgtBuzReq_LongBeep_2_Times;
	  }
	  else if(ChimeRemind_Request == Remind_3)
	  {
	       ChimeRemind_Request = No_Remind;
	       MessageTx_TlgtBuzReq = _TlgtBuzReq_ShortBeep_2_Times;
	  }
	  else if(ChimeRemind_Request == Remind_4)
	  {
	       ChimeRemind_Request = No_Remind;
	       MessageTx_TlgtBuzReq = _TlgtBuzReq_ShortBeep_3_Times;
	  }
	  
	  MessageTx_TlgtBuzReq_Timer = 0;
           
     }
        
     if(MessageTx_TlgtBuzReq_Timer >= K_MessageTx_TlgtBuzReq_Time)
     {
	  MessageTx_TlgtBuzReq = _TlgtBuzReq_No_Request;
     }
     else
     {
	  MessageTx_TlgtBuzReq_Timer ++;
     }	
}

/*********************************************************************************************
** Name:	  MessageTransmit_TlgtFlshReq(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_TlgtFlshReq(void)
{
     static uint16_t MessageTx_TlgtFlshReq_Timer;    
     if(FlashRemind_Request != No_Remind)
     {
	  if(FlashRemind_Request == Remind_1)
	  {
	       FlashRemind_Request = No_Remind;
	       MessageTx_TlgtFlshReq = _TlgtFlshReq_Flash_Once;
	  }
	  else if(FlashRemind_Request == Remind_2)
	  {
	       FlashRemind_Request = No_Remind;
	       MessageTx_TlgtFlshReq = _TlgtFlshReq_Flash_Twice;
	  }
	  
	  MessageTx_TlgtFlshReq_Timer = 0;       
     }
        
     if(MessageTx_TlgtFlshReq_Timer >= K_MessageTx_TlgtFlshReq_Time)
     {
	  MessageTx_TlgtFlshReq = _TlgtFlshReq_No_Request;
     }
     else
     {
	  MessageTx_TlgtFlshReq_Timer ++;
     }
}

/*********************************************************************************************
** Name:	  MessageTransmit_TlgtAbsAlrm(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_TlgtAbsAlrm(void)
{
    static uint16_t MessageTx_TlgtAbsAlrm_Timer; 
    static uint8_t MessageTx_TlgtAbsAlrm_Status;
    static uint16_t MessageTx_TlgtAbsAlrm_Check_Timer;
    static uint8_t MessageTx_TlgtAbsAlrm_Check_Status;
    static uint8_t MessageTx_TlgtAbsAlrm_OutOfCondition_Status;

     if((ActiveSystemMode == SystemOpenedFully) || (ActiveSystemMode == SystemClosedFully) || (ActiveSystemMode == SystemReleased))
     {
          if((TRUE == ShutFaceSwitch_FallEdge_Active)
             ||(TRUE == OpenCloseSwitch_FallEdge_Active)
             ||(TRUE == TouchPad_FallEdge_Active)
	     ||(TRUE == FobLongPress_FallEdge_Active)
	     ||(TRUE == FobShortPress_FallEdge_Active)
	     ||(TRUE == AntiFalseLock_FallEdge_Active)
             //||(TRUE == AppOpen_FallEdge_Active)
             //||(TRUE == AppClose_FallEdge_Active)
             ||(TRUE == VROpen_FallEdge_Active)
             ||(TRUE == VRClose_FallEdge_Active)
	     ||(TRUE == DriverButton_FallEdge_Active)
             ||(TRUE == ManualRelease_FallEdge_Active)
	    )
          {
	       	 MessageTx_TlgtAbsAlrm_Check_Status = TRUE;
	         MessageTx_TlgtAbsAlrm_Check_Timer = 0;
          }
	  else if(TRUE == KickSensor_FallEdge_Command_Active)
	  {
		 if(TRUE == KickSensor_OnlyVehicleNotPark_Status)
		 {
		      MessageTx_TlgtAbsAlrm_Check_Status = TRUE;
	              MessageTx_TlgtAbsAlrm_Check_Timer = 0;
		 }
		 if((TRUE == VehicleCrash_PreCondition_Status)
                   &&(TRUE == VehicleCrank_PreCondition_Status)
                   &&(TRUE == VehicleSpeed_PreCondition_Status)
	           &&(TRUE == PKEAuthorize_PreCondition_Status)
	           &&((VehiclePowerMode == PowerMode_ON))
		 &&((StaticDisplayRequest.bits.ThermalProtected == TRUE)
		  ||(StaticDisplayRequest.bits.OverObstacleTimes == TRUE)
		  ||(StaticDisplayRequest.bits.PlayProtected == TRUE)))
		 {
		      MessageTx_TlgtAbsAlrm_Check_Status = TRUE;
	              MessageTx_TlgtAbsAlrm_Check_Timer = 0;
		 }
	  }
     }    
     /*else if(ActiveSystemMode == SystemPowerOpening)
     {
	  if(((TRUE == VehicleSpeedStop_FallEdge_Active)
	      ||(TRUE == VehicleNoParking_FallEdge_Active))
	     && (VehiclePowerMode == PowerMode_ON))
	  {
	       MessageTx_TlgtAbsAlrm_Check_Status = TRUE;
	       MessageTx_TlgtAbsAlrm_Check_Timer = 0;
	       
	       MessageTx_TlgtAbsAlrm_OutOfCondition_Status = TRUE;
	  }
     }*/
     
     if(TRUE == MessageTx_TlgtAbsAlrm_Check_Status)
     {
	  if(MessageTx_TlgtAbsAlrm_Check_Timer >= K_MessageTx_TlgtAbsAlrm_Check_Timer)
	  {   
	       if((ActiveSystemMode == SystemOpenedFully) || (ActiveSystemMode == SystemClosedFully) || (ActiveSystemMode == SystemReleased))      
	       {
	            if((StaticDisplayRequest.bits.PRNDL == TRUE) && (VehiclePowerMode == PowerMode_ON))
                    {
		         StaticDisplayRequest.bits.PRNDL = FALSE;
	                 MessageTx_TlgtAbsAlrm = _TlgtAbsAlrm_In_Abuse_Mode_3; 
		
	                 MessageTx_TlgtAbsAlrm_Status = TRUE;
		         MessageTx_TlgtAbsAlrm_Timer = 0;
                    } 
	            else if(StaticDisplayRequest.bits.ThermalProtected == TRUE) 
                    {
	                 StaticDisplayRequest.bits.ThermalProtected = FALSE;
	                 MessageTx_TlgtAbsAlrm = _TlgtAbsAlrm_In_Abuse_Mode_2; 
		
	                 MessageTx_TlgtAbsAlrm_Status = TRUE;
		         MessageTx_TlgtAbsAlrm_Timer = 0;
                    }
	            else if(StaticDisplayRequest.bits.OverObstacleTimes == TRUE) 
                    {
	                 StaticDisplayRequest.bits.OverObstacleTimes = FALSE;
	                 MessageTx_TlgtAbsAlrm = _TlgtAbsAlrm_In_Abuse_Mode_1; 
		
	                 MessageTx_TlgtAbsAlrm_Status = TRUE;
		         MessageTx_TlgtAbsAlrm_Timer = 0;
                    } 
                    else if(StaticDisplayRequest.bits.PlayProtected == TRUE) 
                    {
	                 StaticDisplayRequest.bits.PlayProtected = FALSE;
	                 MessageTx_TlgtAbsAlrm = _TlgtAbsAlrm_In_Abuse_Mode_1; 
		
	                 MessageTx_TlgtAbsAlrm_Status = TRUE;
		         MessageTx_TlgtAbsAlrm_Timer = 0;
                    }
                    /*else if(StaticDisplayRequest.bits.DisableMode == TRUE)
                    {
	                 StaticDisplayRequest.bits.DisableMode = FALSE;
	                 MessageTx_TlgtAbsAlrm = _TlgtAbsAlrm_In_Abuse_Mode_3; 
		
	                 MessageTx_TlgtAbsAlrm_Status = TRUE;
		         MessageTx_TlgtAbsAlrm_Timer = 0;
                    }*/
	       }
               	   
	       MessageTx_TlgtAbsAlrm_Check_Status = FALSE;
	       MessageTx_TlgtAbsAlrm_Check_Timer = 0;
	  }
	  else
	  {
	       MessageTx_TlgtAbsAlrm_Check_Timer ++;
	  }
     }

     if(TRUE == MessageTx_TlgtAbsAlrm_Status)
     {
          if(MessageTx_TlgtAbsAlrm_Timer >= K_MessageTx_TlgtAbsAlrm_Time)
          {
	        MessageTx_TlgtAbsAlrm = _TlgtAbsAlrm_No_Request; 
		
	        MessageTx_TlgtAbsAlrm_Status = FALSE;
		MessageTx_TlgtAbsAlrm_Timer = 0;
          }
          else
          {
	        MessageTx_TlgtAbsAlrm_Timer ++;
          }
     }
     
}

/*********************************************************************************************
** Name:	  MessageTransmit_GateOpenAngle(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_GateOpenAngle(void)
{
     if(TRUE == SystemLearned_Status)
     {
           MessageTx_GateOpenAngle = (uint16_t)((uint32_t)(Motor1_Position * 100) / SystemLearned_Position);	   
     }
     else
     {
	   MessageTx_GateOpenAngle = (uint16_t)((uint32_t)(Motor1_Position * 100) / K_MaxPosition_HallCount_Default);
     }
     
     /*if(MessageTx_GateOpenAngle > K_GateOpenAngle_Precision_Compensation)
     {
          MessageTx_GateOpenAngle -= K_GateOpenAngle_Precision_Compensation;
     }*/
     
     if(MessageTx_GateOpenAngle > K_MessageTx_GateOpenAngle_Max)
     {
	  MessageTx_GateOpenAngle = K_MessageTx_GateOpenAngle_Max;
     }
}

/*********************************************************************************************
** Name:	  MessageTransmit_GaragePosition(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_GaragePosition(void)
{
    if(TRUE == SystemLearned_Status)
    {
         if(TRUE == GarageLearned_Status)
         {
               MessageTx_GaragePosition = (uint16_t)((uint32_t)(GarageLearned_Position * 100) / SystemLearned_Position);
	       MessageTx_GaragePosition_Remainder = (uint16_t)((uint32_t)(GarageLearned_Position * 100) % SystemLearned_Position);
         }
         else
         {
	       MessageTx_GaragePosition = (uint16_t)((uint32_t)(K_GarageLearned_Position_Default * 100) / SystemLearned_Position);	       
         }
    }
    else
    {
	 if(TRUE == GarageLearned_Status)
         {
               MessageTx_GaragePosition = (uint16_t)((uint32_t)(GarageLearned_Position * 100) / K_SystemLearned_Position_Default);
	       MessageTx_GaragePosition_Remainder = (uint16_t)((uint32_t)(GarageLearned_Position * 100) % K_SystemLearned_Position_Default);                        
         }
         else
         {
	       MessageTx_GaragePosition = (uint16_t)((uint32_t)(K_GarageLearned_Position_Default * 100) / K_SystemLearned_Position_Default);
	       
         }
    }
    
     if(MessageTx_GaragePosition_Remainder > 0)
     {
	  MessageTx_GaragePosition += K_GaragePosition_Precision_Compensation;
     }
    
     if(MessageTx_GaragePosition > K_MessageTx_GateOpenAngle_Max)
     {
	  MessageTx_GaragePosition = K_MessageTx_GateOpenAngle_Max;
     }
     
     if(FALSE == GarageLearned_Status)
     {
	  MessageTx_GaragePosition = K_MessageTx_GaragePosition_100Percent;
     }
    
}

/*********************************************************************************************
** Name:	  MessageTransmit_LearnStatus(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_LearnStatus(void)
{
       MessageTx_SystemLearnedStatus = SystemLearned_Status;
       MessageTx_GarageLearnedStatus = GarageLearned_Status;
       MessageTx_GarageLearnAction = ShutFaceSwitch_LongPress_Status;
       MessageTx_SystemLearnFailure = System_Learn_Failure;
}
/*Debug_Msg*/
/*********************************************************************************************
** Name:	  MessageTransmit_Debug_Msg_0x711(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_Debug_Msg_0x711(void)
{
     static uint16_t MessageTx_Debug_Msg_0x711_Status;
     
     if((TRUE == Configuration_SPX1_DebugMessage) && (FALSE == MessageTx_Debug_Msg_0x711_Status))
     {
	   InterMsgTransEnable(0);
	   u8InterInfoCheckStart = 1;
	   
	   MessageTx_Debug_Msg_0x711_Status = TRUE;
     }
     else if ((FALSE == Configuration_SPX1_DebugMessage) && (TRUE == MessageTx_Debug_Msg_0x711_Status))
     {
	   InterMsgTransDisable(0);
	   u8InterInfoCheckStart = 0;
	   
	   MessageTx_Debug_Msg_0x711_Status = FALSE;
     }

     if(TRUE == Configuration_SPX1_DebugMessage)
     {
          MessageTx_BATT1 = VBATT1_Voltage/10;
          MessageTx_BATT2 = VBATT2_Voltage/10;

	  if(TRUE == Motor1_Working_Status)
	  {
	        MessageTx_SpindleCurrent = Motor1_Current;
		MessageTx_SpindleCurrentOffset = Motor1_Current_Threshold;
                MessageTx_SpindlePWM = Motor1_Duty_Request/40;
	  }
	  else
	  {
		MessageTx_SpindleCurrent = 0;
		MessageTx_SpindleCurrentOffset = 0;
                MessageTx_SpindlePWM = 0;
	  }
	  
	  if(TRUE == CinchMotor_Working_Status)
	  {
	        MessageTx_LatchCurrent = CinchMotor_Current;	  
                MessageTx_LatchPWM = CinchMotor_Duty_Request/40;
	  }
	  else
	  {
		MessageTx_LatchCurrent = 0;	  
                MessageTx_LatchPWM = 0;
	  }
     }
     else
     {
	  MessageTx_BATT1 = 0;
	  MessageTx_BATT2 = 0;
	  MessageTx_SpindleCurrent = 0;
	  MessageTx_SpindleCurrentOffset = 0;
	  MessageTx_SpindlePWM = 0;
	  MessageTx_LatchCurrent = 0;
	  MessageTx_LatchPWM = 0;
     }

}

/*********************************************************************************************
** Name:	  MessageTransmit_Debug_Msg_0x712(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_Debug_Msg_0x712(void)
{
    static uint16_t MessageTx_Debug_Msg_0x712_Status;
    
     static uint16_t MessageTx_StallEventSpindle_Timer;
     static uint16_t MessageTx_StallEventSpindle_Status;
     
     if((TRUE == Configuration_SPX1_DebugMessage) && (FALSE == MessageTx_Debug_Msg_0x712_Status))
     {
	   InterMsgTransEnable(1);
	   u8InterInfoCheckStart = 1;
	   
	   MessageTx_Debug_Msg_0x712_Status = TRUE;
     }
     else if ((FALSE == Configuration_SPX1_DebugMessage) && (TRUE == MessageTx_Debug_Msg_0x712_Status))
     {
	   InterMsgTransDisable(1);
	   u8InterInfoCheckStart = 0;
	   
	   MessageTx_Debug_Msg_0x712_Status = FALSE;
     }

     if(TRUE == Configuration_SPX1_DebugMessage)
     {   
          MessageTx_SpindleMovingSection = Motor1_SpeedZoneIndex;
	  	  
          MessageTx_HallSpeedReal = Motor1_RealSpeed;
          MessageTx_HallSpeedSet = Motor1_DesiredSpeed_Request;
          MessageTx_HallReal = Motor1_Position;
          MessageTx_HallMaxSet = SystemLearned_Position;
	  
	  if(Motor1_ObstacleType == EnhancedCurrentObstacle)
	  {
	       MessageTx_StallEventSpindle = _StallEventSpindle_EnhancedCurrentStall;
	  }
	  else if(Motor1_ObstacleType == FixedCurrentObstacle)
	  {
	       MessageTx_StallEventSpindle = _StallEventSpindle_TopLimitCurrentStall;
	  }
	  else if(Motor1_ObstacleType == HallPluseObstacle)
	  {
	       MessageTx_StallEventSpindle = _StallEventSpindle_HallStall;
	  }
	  else if(CurrentDynamicTelltales.bits.AntipinchPressedLeft == TRUE)
	  {
	       MessageTx_StallEventSpindle = _StallEventSpindle_LeftAPSTriggered;
	  }
	  else if(CurrentDynamicTelltales.bits.AntipinchPressed == TRUE)
	  {
	       MessageTx_StallEventSpindle = _StallEventSpindle_RightAPSTriggered;

	  } 
	  else
	  {
	       MessageTx_StallEventSpindle = _StallEventSpindle_Normal;
	  }
	  
	  if((MessageTx_StallEventSpindle != _StallEventSpindle_Normal) && (FALSE == MessageTx_StallEventSpindle_Status))
	  {
	       MessageTx_StallEventSpindle_Timer = 0;
	       MessageTx_StallEventSpindle_Status = TRUE;
	  }
	   
	  if(TRUE == MessageTx_StallEventSpindle_Status)
	  {
	       if(MessageTx_StallEventSpindle_Timer >= K_MessageTx_StallEventSpindle_Time)
	       {
	            MessageTx_StallEventSpindle = _StallEventSpindle_Normal;
	       }
	       else
	       {
	            MessageTx_StallEventSpindle_Timer ++;
	       }
	       
	       if(((ActiveSystemMode == SystemPowerOpening) && ((LastSystemMode == SystemReleased) || (LastSystemMode == SystemOpenedFully) ||(LastSystemMode == SystemMechFailure)))
                  || ((ActiveSystemMode == SystemPowerClosing) && ((LastSystemMode == SystemReleased) || (LastSystemMode == SystemOpenedFully) ||(LastSystemMode == SystemMechFailure))))
               {
	             MessageTx_StallEventSpindle_Status = FALSE;  
               }
	  }

     }
     else
     {
	  MessageTx_SpindleMovingSection = 0;	  
          MessageTx_HallSpeedReal = 0;
          MessageTx_HallSpeedSet = 0;
          MessageTx_HallReal = 0;
          MessageTx_HallMaxSet = 0;
	  MessageTx_StallEventSpindle = 0;
     }

}

/*********************************************************************************************
** Name:	  MessageTransmit_Debug_Msg_0x713(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_Debug_Msg_0x713(void)
{
     static uint16_t MessageTx_Debug_Msg_0x713_Status;
     
     if((TRUE == Configuration_SPX1_DebugMessage) && (FALSE == MessageTx_Debug_Msg_0x713_Status))
     {
	   InterMsgTransEnable(2);
	   u8InterInfoCheckStart = 1;
	   
	   MessageTx_Debug_Msg_0x713_Status = TRUE;
     }
     else if ((FALSE == Configuration_SPX1_DebugMessage) && (TRUE == MessageTx_Debug_Msg_0x713_Status))
     {
	   InterMsgTransDisable(2);
	   u8InterInfoCheckStart = 0;
	   
	   MessageTx_Debug_Msg_0x713_Status = FALSE;
     }

     if(TRUE == Configuration_SPX1_DebugMessage)
     {   
           MessageTx_HallParkSet = GarageLearned_Position;
           MessageTx_HallMaxAngle = SystemLearned_Position + K_StopFromMaxTravel_HallCount;
     }
     else
     {
	   MessageTx_HallParkSet = 0;
           MessageTx_HallMaxAngle = 0;
     }
}

/*********************************************************************************************
** Name:	  MessageTransmit_Debug_Msg_0x714(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_Debug_Msg_0x714(void)
{
     static uint16_t MessageTx_Debug_Msg_0x714_Status;
     
     if((TRUE == Configuration_SPX1_DebugMessage) && (FALSE == MessageTx_Debug_Msg_0x714_Status))
     {
	   InterMsgTransEnable(3);
	   u8InterInfoCheckStart = 1;
	   
	   MessageTx_Debug_Msg_0x714_Status = TRUE;
     }
     else if ((FALSE == Configuration_SPX1_DebugMessage) && (TRUE == MessageTx_Debug_Msg_0x714_Status))
     {
	   InterMsgTransDisable(3);
	   u8InterInfoCheckStart = 0;
	   
	   MessageTx_Debug_Msg_0x714_Status = FALSE;
     }
}
#endif
#ifdef _MAXUS_COM_PSD
/*********************************************************************************************
** Name:	  MessageTransmit_SldDrPos(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/ 
static void MessageTransmit_SldDrPos(void)
{
}
/*********************************************************************************************
** Name:	  MessageTransmit_SldDrOhpSts(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/ 
static void MessageTransmit_SldDrOhpSts(void)
{
      MessageTx_SldDrOhpSts = Motor1_ThermalProtection_Status;
}
/*********************************************************************************************
** Name:	  MessageTransmit_SldDrOprtSts(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/ 
static void MessageTransmit_SldDrOprtSts(void)
{
     if(TRUE == Motor1_Working_Status)
     {
	  if(Motor1_Direction_Request == Direction_Open)
	  {
		MessageTx_SldDrOprtSts = _SldDrOprtSts_Opening;
	  }
	  else if(Motor1_Direction_Request == Direction_Close)
	  {
		MessageTx_SldDrOprtSts = _SldDrOprtSts_Closing;
	  }
	  else
	  {
		MessageTx_SldDrOprtSts = _SldDrOprtSts_Idle;
	  }
     }
     else
     {
	  MessageTx_SldDrOprtSts = _SldDrOprtSts_Idle;
     }	
}
/*********************************************************************************************
** Name:	  MessageTransmit_PSDErrSts(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/ 
static void MessageTransmit_PSDErrSts(void)
{
	
    if((TRUE == DTCData_Table.table.Motor1_STG.DTCData.data.DTCStatus.bits.TestFailed) 
        ||(TRUE == DTCData_Table.table.Motor1_STB.DTCData.data.DTCStatus.bits.TestFailed)
        ||(TRUE == DTCData_Table.table.Motor1_OC.DTCData.data.DTCStatus.bits.TestFailed)
        ||(TRUE == DTCData_Table.table.Motor2_STG.DTCData.data.DTCStatus.bits.TestFailed) /*Clutch Motor*/
        ||(TRUE == DTCData_Table.table.Motor2_STB.DTCData.data.DTCStatus.bits.TestFailed) /*Clutch Motor*/
        ||(TRUE == DTCData_Table.table.Motor2_OC.DTCData.data.DTCStatus.bits.TestFailed)  /*Clutch Motor*/
        ||(TRUE == DTCData_Table.table.CinchMotor_STG.DTCData.data.DTCStatus.bits.TestFailed)
        ||(TRUE == DTCData_Table.table.CinchMotor_STB.DTCData.data.DTCStatus.bits.TestFailed)
        ||(TRUE == DTCData_Table.table.CinchMotor_OC.DTCData.data.DTCStatus.bits.TestFailed)
        ||(TRUE == DTCData_Table.table.AntiPinch_APSActive.DTCData.data.DTCStatus.bits.TestFailed)
        ||(TRUE == DTCData_Table.table.AntiPinch_STG.DTCData.data.DTCStatus.bits.TestFailed)
        ||(TRUE == DTCData_Table.table.AntiPinch_STBorOC.DTCData.data.DTCStatus.bits.TestFailed)
        ||(TRUE == DTCData_Table.table.HallA1_NoHall.DTCData.data.DTCStatus.bits.TestFailed)
        ||(TRUE == DTCData_Table.table.HallA2_NoHall.DTCData.data.DTCStatus.bits.TestFailed)
        ||(TRUE == DTCData_Table.table.BatteryVoltage_VolAbove.DTCData.data.DTCStatus.bits.TestFailed)
        ||(TRUE == DTCData_Table.table.BatteryVoltage_VolBelow.DTCData.data.DTCStatus.bits.TestFailed)
       )  
     {	
	   MessageTx_PSDErrSts = _PSDErrSts_Error;
     }
     else
     {
	   MessageTx_PSDErrSts = _PSDErrSts_Normal;
     }
 
}
/*********************************************************************************************
** Name:	  MessageTransmit_SldDrOprtMd(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/ 
static void MessageTransmit_SldDrOprtMd(void)
{
     if(TRUE == SpindleDisableMode_Status)
     {
	   MessageTx_SldDrOprtMd = _SldDrOprtMd_Manual;
     }
     else if(TRUE == SpindleGarageMode_Status)
     {
	   MessageTx_SldDrOprtMd = _SldDrOprtMd_Auto;
     }
     else
     {
	   MessageTx_SldDrOprtMd = _SldDrOprtMd_Auto;
     }

}
/*********************************************************************************************
** Name:	  MessageTransmit_Ajr_FulBx(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/ 
static void MessageTransmit_Ajr_FulBx(void)
{
}
/*********************************************************************************************
** Name:	  MessageTransmit_SldDrPosSts(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/ 
static void MessageTransmit_SldDrPosSts(void)
{
     if((TRUE == PawlSwitch_Status) && (TRUE == SecondarySwitch_Status))
     {
	   MessageTx_SldDrPosSts = _SldDrPosSts_Door_Open;
     }
     else if((TRUE == PawlSwitch_Status) && (FALSE == SecondarySwitch_Status))
     {
	   MessageTx_SldDrPosSts = _SldDrPosSts_Half_Locked;
     }
     else if((FALSE == PawlSwitch_Status) && (FALSE == SecondarySwitch_Status))
     {
	   MessageTx_SldDrPosSts = _SldDrPosSts_Fully_Closed;
     }
     else
     {
	   MessageTx_SldDrPosSts = _SldDrPosSts_Status_Unkown;
     }
 
}
/*********************************************************************************************
** Name:	  MessageTransmit_SldDrTchPdSw(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/ 
static void MessageTransmit_SldDrTchPdSw(void)
{
     if(TRUE == OutsideHandleSwitch_Status)
     {
           MessageTx_SldDrTchPdSw = _SldDrTchPdSw_Pressed;
     }
     else
     {
	   MessageTx_SldDrTchPdSw = _SldDrTchPdSw_No_Pressed;
     }

}
/*********************************************************************************************
** Name:	  MessageTransmit_ChldLckSts(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/ 
static void MessageTransmit_ChldLckSts(void)
{
     if(TRUE == ChildLockSwitch_Status)
     {
           MessageTx_ChldLckSts = _ChldLckSts_Lock;
     }
     else
     {
	   MessageTx_ChldLckSts = _ChldLckSts_Unlock;
     }
}
/*********************************************************************************************
** Name:	  MessageTransmit_SldDrIntSw(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/ 
static void MessageTransmit_SldDrIntSw(void)
{
     if(TRUE == HandleOpenSwitch_Status)
     {
           MessageTx_SldDrIntSw = _SldDrIntSw_Open;
     }
     else if(TRUE == HandleCloseSwitch_Status)
     {
           MessageTx_SldDrIntSw = _SldDrIntSw_Close;
     }
     else
     {
	   MessageTx_SldDrIntSw = _SldDrIntSw_Not_Pressed;
     }
     
}
/*********************************************************************************************
** Name:	  MessageTransmit_SldDrDrSw(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/ 
static void MessageTransmit_SldDrDrSw(void)
{
     if(TRUE == OpenCloseSwitch_Status)
     {
           MessageTx_SldDrDrSw = _SldDrDrSw_Pressed;
     }
     else
     {
	   MessageTx_SldDrDrSw = _SldDrDrSw_No_Pressed;
     }
	
}
/*********************************************************************************************
** Name:	  MessageTransmit_SldDrLckSts(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/ 
static void MessageTransmit_SldDrLckSts(void)
{
     if((TRUE == PawlSwitch_Status) && (TRUE == SecondarySwitch_Status))
     {
	   MessageTx_SldDrLckSts = _SldDrLckSts_Unlocked;
     }
     else if((FALSE == PawlSwitch_Status) && (FALSE == SecondarySwitch_Status))
     {
	   MessageTx_SldDrLckSts = _SldDrLckSts_Locked;
     }
     else if((TRUE == PawlSwitch_Status) && (FALSE == SecondarySwitch_Status))
     {
	   MessageTx_SldDrLckSts = _SldDrLckSts_Unlocked;
     }
     else
     {
	   MessageTx_SldDrLckSts = _TlgtPosSts_Status_Unkown;
     }
}
/*********************************************************************************************
** Name:	  MessageTransmit_PSDObsSts(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/ 
static void MessageTransmit_PSDObsSts(void)
{
     static uint16_t MessageTx_PSDObsSts_Timer;
     #define K_MessageTx_PSDObsSts_Time 30
     
     if(DynamicDisplayRequest.bits.AntipinchPressed == TRUE) 
     {
	  DynamicDisplayRequest.bits.AntipinchPressed = FALSE;
	  
	  MessageTx_PSDObsSts = _PSDObsSts_Pinch;
	  MessageTx_PSDObsSts_Timer = 0;
     }
     else if(DynamicDisplayRequest.bits.Motor1Obstacle == TRUE) 
     {
	  DynamicDisplayRequest.bits.Motor1Obstacle = FALSE;
	  
	  MessageTx_PSDObsSts = _PSDObsSts_Stall;
	  MessageTx_PSDObsSts_Timer = 0;
     }
 
     if(MessageTx_PSDObsSts_Timer >= K_MessageTx_PSDObsSts_Time)
     {
	  MessageTx_PSDObsSts = _PSDObsSts_Normal; 
     }
     else
     {
	  MessageTx_PSDObsSts_Timer ++;
     }

}
/*********************************************************************************************
** Name:	  MessageTransmit_SldDrLtcSts(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/ 
static void MessageTransmit_SldDrLtcSts(void)
{
      if(ActiveLatchMode == LatchFullyCinched)
      {
	   MessageTx_SldDrLtcSts = _SldDrLtcSts_Latch_Locked;
      }
      else if((ActiveLatchMode == LatchPreCinchCheck) || (ActiveLatchMode == LatchPowerCinching))
      {
	   MessageTx_SldDrLtcSts = _SldDrLtcSts_Latch_Cinching;
      }
      else if(ActiveLatchMode == LatchFindHomeAfterCinch)
      {
	   MessageTx_SldDrLtcSts = _SldDrLtcSts_LatchReseting_After_Cinching;
      }
      else if((ActiveLatchMode == LatchPreReleasing)|| (ActiveLatchMode == LatchPowerReleasing))
      {
	   MessageTx_SldDrLtcSts = _SldDrLtcSts_Latch_Releasing;
      }
      else if(ActiveLatchMode == LatchFindHomeAfterRelease)
      {
	   MessageTx_SldDrLtcSts = _SldDrLtcSts_LatchReseting_After_Releasing;
      }
      else if(ActiveLatchMode == LatchPreReleased)
      {
	   MessageTx_SldDrLtcSts = _SldDrLtcSts_Latch_HalfLocked;
      }
      else if(ActiveLatchMode == LatchFullyReleased)
      {
	   MessageTx_SldDrLtcSts = _SldDrLtcSts_Latch_UnLocked;
      }
      else
      {
	   MessageTx_SldDrLckSts = _SldDrLtcSts_Status_Unkown;
      }

}
/*********************************************************************************************
** Name:	  MessageTransmit_SldDrAbsAlrm(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/ 
static void MessageTransmit_SldDrAbsAlrm(void)
{
     MessageTx_SldDrAbsAlrm = _SldDrAbsAlrm_No_Abuse;
     //MessageTx_SldDrAbsAlrm = _SldDrAbsAlrm_Abuse_1;
     //MessageTx_SldDrAbsAlrm = _SldDrAbsAlrm_Abuse_2;
     //MessageTx_SldDrAbsAlrm = _SldDrAbsAlrm_Abuse_3;

}


#ifdef _CONFIG_DTCPush_DTCStatusBit1_OneTime
/*********************************************************************************************
** Name:	  MessageTransmit_PSD_ErrPush(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_PSD_ErrPush(void)
{
     uint8_t i;
   
     static uint16_t Tx_PSD_ErrPush_Start_Timer;
     
     static uint8_t Last_DTCStatus[NUM_OF_DTC];
     static uint8_t DTC_PushStatus[NUM_OF_DTC];
     static uint8_t CurrentPushIndex;
     static uint8_t CurrentPushIndex_Status;    
     static uint8_t Tx_CurrentPush_Status;
     static uint16_t Tx_CurrentPush_Timer;
     static uint8_t Tx_Condtion_Bus_Off;
     
     static uint8_t Com_SetSendRequest_Status;
   
     static uint8_t DTCDisplayEnable_Bit;
     static uint8_t DTCDisplayEnable_Byte;

     #define K_Tx_PSD_ErrPush_Start_Time 10
     #define K_Tx_CurrentPush_Time 100
     #define K_Tx_CurrentPush_Time_1st_Delay 10
     
     if(Tx_PSD_ErrPush_Start_Timer >= K_Tx_PSD_ErrPush_Start_Time)
     {	
	  /*Looking for Current DTC*/
          for(i=0;i<NUM_OF_DTC;i++)
          {
	       DTCDisplayEnable_Bit = i%8;
               DTCDisplayEnable_Byte = i/8;
	    
	       if((MAXUSCAN_DTCDisplayEnable[DTCDisplayEnable_Byte]&(0x01<<(7-DTCDisplayEnable_Bit))) != 0x00)
	       {
                    if(((DTCStatus[i]&0x02) == 0x02) && ((Last_DTCStatus[i]&0x02) == FALSE))
                    {    	    
                         DTC_PushStatus[i] = TRUE;
                    }
	    
	            Last_DTCStatus[i] = DTCStatus[i];
	       }
          }
	  
	  /*Bus_Off Tx_Condtion*/
	  if((DTCStatus[16]&0x01) != TRUE )
	  {
	       Tx_Condtion_Bus_Off = TRUE;
	  }
	  else
	  {
	       Tx_Condtion_Bus_Off = FALSE;
	  }
	  
	  /*Looking for CurrentPushIndex*/
	  if((FALSE == Tx_CurrentPush_Status) && (TRUE == Tx_Condtion_Bus_Off))
	  {
	       CurrentPushIndex_Status = FALSE;
	       for(i=0;i<NUM_OF_DTC;i++)
               {
	            if((DTC_PushStatus[i] == TRUE) && (FALSE == CurrentPushIndex_Status))
	            {
		          CurrentPushIndex_Status = TRUE;
		          CurrentPushIndex = i;
	            } 	       
	       }
	  }
	  
	  /*PSD_ErrPush 3 Frames*/	  
	  if((TRUE == CurrentPushIndex_Status) && (TRUE == Tx_Condtion_Bus_Off))
	  {
	       if(FALSE == Tx_CurrentPush_Status)
	       {
		    Tx_CurrentPush_Status = TRUE;
		    Tx_CurrentPush_Timer = 0;
		    
		    DTC_PushStatus[CurrentPushIndex] = FALSE;
		    
	            if((CurrentPushIndex == 0) || (CurrentPushIndex == 1))
	            {
			  #ifdef _MAXUS_COM_PSD_R
	                  TxIpduPSD_ErrPush.Ipdu.PSD_RDTCSeriousLvl = 0x01;
			  #endif
			  #ifdef _MAXUS_COM_PSD_L
	                  TxIpduPSD_ErrPush.Ipdu.PSD_LDTCSeriousLvl = 0x01;
			  #endif
	            }
		    else if((CurrentPushIndex >= 16) && (CurrentPushIndex <= 28))
	     	    {
			  #ifdef _MAXUS_COM_PSD_R
	                  TxIpduPSD_ErrPush.Ipdu.PSD_RDTCSeriousLvl = 0x02; 
			  #endif
			  #ifdef _MAXUS_COM_PSD_L
	                  TxIpduPSD_ErrPush.Ipdu.PSD_LDTCSeriousLvl = 0x02; 
			  #endif	           
	            }
	            else
	            {
			  #ifdef _MAXUS_COM_PSD_R
	                  TxIpduPSD_ErrPush.Ipdu.PSD_RDTCSeriousLvl = 0x03; 
			  #endif
			  #ifdef _MAXUS_COM_PSD_L
	                  TxIpduPSD_ErrPush.Ipdu.PSD_LDTCSeriousLvl = 0x03; 
			  #endif
	            }
	            
		    #ifdef _MAXUS_COM_PSD_R
	            TxIpduPSD_ErrPush.Ipdu.PSD_RDTCHiByte = (SupportedDTC[CurrentPushIndex] >> 16);
	            TxIpduPSD_ErrPush.Ipdu.PSD_RDTCLowByte = (SupportedDTC[CurrentPushIndex] >> 8);
	            TxIpduPSD_ErrPush.Ipdu.PSD_RDTCFlrTypByte = SupportedDTC[CurrentPushIndex];
	            TxIpduPSD_ErrPush.Ipdu.PSD_RDTCSts = 0x0b;//DTCStatus[CurrentPushIndex];
	            TxIpduPSD_ErrPush.Ipdu.PSD_RDTCTyp = _PLGDTCTyp_Tpye_E; 
		    #endif
		    #ifdef _MAXUS_COM_PSD_L
	            TxIpduPSD_ErrPush.Ipdu.PSD_LDTCHiByte = (SupportedDTC[CurrentPushIndex] >> 16);
	            TxIpduPSD_ErrPush.Ipdu.PSD_LDTCLowByte = (SupportedDTC[CurrentPushIndex] >> 8);
	            TxIpduPSD_ErrPush.Ipdu.PSD_LDTCFlrTypByte = SupportedDTC[CurrentPushIndex];
	            TxIpduPSD_ErrPush.Ipdu.PSD_LDTCSts = 0x0b;//DTCStatus[CurrentPushIndex];
	            TxIpduPSD_ErrPush.Ipdu.PSD_LDTCTyp = _PLGDTCTyp_Tpye_E; 
		    #endif
	            
	       }
	     
	       if(FALSE == Com_SetSendRequest_Status)
	       {
		    Com_SetSendRequest_Status = TRUE;
		    
	            Com_ActiveSig(COM_TXSIGPSD_DTCTyp);
	            Com_SetSendRequest(COM_TXSIGPSD_DTCTyp);
		    		    
		    Tx_CurrentPush_Timer = K_Tx_CurrentPush_Time_1st_Delay;
	       } 
	       
	       if(TRUE == Tx_CurrentPush_Status)
	       {
		    if(Tx_CurrentPush_Timer >= K_Tx_CurrentPush_Time)
		    {
			  Tx_CurrentPush_Status = FALSE;
			  Tx_CurrentPush_Timer = 0;
		    }
		    else
		    {
			  Tx_CurrentPush_Timer ++;
		    }
	       }
	  } 
	  else
	  {
	       if((TRUE == Com_SetSendRequest_Status) && (TRUE == Tx_Condtion_Bus_Off))
	       {
		    Com_SetSendRequest_Status = FALSE;
	            Com_DisactiveSig(COM_TXSIGPSD_DTCTyp);
	            Com_SetSendRequest(COM_TXSIGPSD_DTCTyp);
	            
	       }   
	  }
     }
     else
     {
	  Tx_PSD_ErrPush_Start_Timer ++;
     } 	  
}
#endif

/*********************************************************************************************
** Name:	  MessageTransmit_FastCycle_Monitor(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_FastCycle_Monitor(void)
{
     static uint8_t MessageTx_FastCycle_Timer_Status;
     static uint16_t MessageTx_FastCycle_Timer;
     static uint16_t MessageTx_FastCycle_Delay_Timer;

     if((TRUE == HandleOpenSwitch_FallEdge_Active)
        ||(TRUE == HandleCloseSwitch_FallEdge_Active)
        ||(TRUE == OpenCloseSwitch_FallEdge_Active)
        ||(TRUE == OutsideHandleSwitch_FallEdge_Active)
	||(TRUE == FobLongPress_FallEdge_Active)
	||(TRUE == FobShortPress_FallEdge_Active)
        ||(TRUE == KickSensor_FallEdge_Active)
        ||(TRUE == AppOpen_FallEdge_Active)
        ||(TRUE == AppClose_FallEdge_Active)
        ||(TRUE == VROpen_FallEdge_Active)
        ||(TRUE == VRClose_FallEdge_Active)
	||(TRUE == BLEOpen_FallEdge_Active)
        ||(TRUE == BLEClose_FallEdge_Active)
	)
     {	  
	  MessageTx_FastCycle_Timer_Status = TRUE;
	  MessageTx_FastCycle_Timer = 0;
	  
	  Com_ActiveSig(0);
	  Com_SetSendRequest(0);
     }
     else if((TRUE == PositionSwitch_FallEdge_Active)
            ||(TRUE == PawlSwitch_FallEdge_Active)
            ||(TRUE == SecondarySwitch_FallEdge_Active))
     {
	  MessageTx_FastCycle_Timer_Status = TRUE;
	  MessageTx_FastCycle_Timer = 0;
	  
	  Com_ActiveSig(0);
	  Com_SetSendRequest(0);
     }
     else if((TRUE == Motor1_FollowClose_Command_Active)
            ||(TRUE == FollowOperate_SlamClose_Command_Active)
	    ||(TRUE == Motor1_ManualMoving_FallEdge_Active))
     {
	  MessageTx_FastCycle_Timer_Status = TRUE;
	  MessageTx_FastCycle_Timer = 0;
	  
	  Com_ActiveSig(0);
	  Com_SetSendRequest(0);
     }
     else if(((TRUE == FastCycle_AfterPowerUp_Status)
            ||(TRUE == FastCycle_AfterWakeup_Status)
	    ||(TRUE == FastCycle_FromReset_Status))
	    &&(TRUE == Com_TxStart_Start_Status))
     {
	  if(MessageTx_FastCycle_Delay_Timer >= K_MessageTx_FastCycle_Delay_Time)
	  {
	        FastCycle_AfterPowerUp_Status = FALSE;
                FastCycle_AfterWakeup_Status = FALSE;
                FastCycle_FromReset_Status = FALSE;
	  
	        MessageTx_FastCycle_Timer_Status = TRUE;
	        MessageTx_FastCycle_Timer = 0;
	  
	        Com_ActiveSig(0);
	        Com_SetSendRequest(0);
	  }
	  else
	  {
	       	MessageTx_FastCycle_Delay_Timer ++;
	  }

     }
     else if((ActiveSystemMode == SystemReleaseToPowerOpen)
             ||(ActiveSystemMode == SystemPowerOpening)
	     ||(ActiveSystemMode == SystemPowerClosing) 
             ||(ActiveSystemMode == SystemPowerCinching)
	     ||(ActiveSystemMode == SystemPowerParking)
	     ||(ActiveSystemMode == SystemManualCinching)
	     ||(ActiveSystemMode == SystemManualParking)
	     ||(TRUE == Motor1_ManualMoving_Status))
     {
	  MessageTx_FastCycle_Timer_Status = TRUE;
	  MessageTx_FastCycle_Timer = 0;
	  
	  Com_ActiveSig(0);
	  Com_SetSendRequest(0);
     }

     if(TRUE == MessageTx_FastCycle_Timer_Status)
     {
         if(MessageTx_FastCycle_Timer >= K_MessageTx_FastCycle_Time)
         {
	       MessageTx_FastCycle_Timer_Status = FALSE; 
	       
	       Com_DisactiveSig(0);
	       Com_SetSendRequest(0);
         }
         else
         {
	       MessageTx_FastCycle_Timer ++;
         }
     }
}

/*********************************************************************************************
** Name:	  MessageTransmit_GateOpenAngle(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_GateOpenAngle(void)
{
     if(TRUE == SystemLearned_Status)
     {
           MessageTx_GateOpenAngle = (uint16_t)((uint32_t)(Motor1_Position * 100) / SystemLearned_Position);	   
     }
     else
     {
	   MessageTx_GateOpenAngle = (uint16_t)((uint32_t)(Motor1_Position * 100) / K_MaxPosition_HallCount_Default);
     }
     
     /*if(MessageTx_GateOpenAngle > K_GateOpenAngle_Precision_Compensation)
     {
          MessageTx_GateOpenAngle -= K_GateOpenAngle_Precision_Compensation;
     }*/
     
     if(MessageTx_GateOpenAngle > K_MessageTx_GateOpenAngle_Max)
     {
	  MessageTx_GateOpenAngle = K_MessageTx_GateOpenAngle_Max;
     }
}

/*********************************************************************************************
** Name:	  MessageTransmit_GaragePosition(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_GaragePosition(void)
{
    if(TRUE == SystemLearned_Status)
    {
         if(TRUE == GarageLearned_Status)
         {
               MessageTx_GaragePosition = (uint16_t)((uint32_t)(GarageLearned_Position * 100) / SystemLearned_Position);
	       MessageTx_GaragePosition_Remainder = (uint16_t)((uint32_t)(GarageLearned_Position * 100) % SystemLearned_Position);
         }
         else
         {
	       MessageTx_GaragePosition = (uint16_t)((uint32_t)(K_GarageLearned_Position_Default * 100) / SystemLearned_Position);	       
         }
    }
    else
    {
	 if(TRUE == GarageLearned_Status)
         {
               MessageTx_GaragePosition = (uint16_t)((uint32_t)(GarageLearned_Position * 100) / K_SystemLearned_Position_Default);
	       MessageTx_GaragePosition_Remainder = (uint16_t)((uint32_t)(GarageLearned_Position * 100) % K_SystemLearned_Position_Default);                        
         }
         else
         {
	       MessageTx_GaragePosition = (uint16_t)((uint32_t)(K_GarageLearned_Position_Default * 100) / K_SystemLearned_Position_Default);
	       
         }
    }
    
     if(MessageTx_GaragePosition_Remainder > 0)
     {
	  MessageTx_GaragePosition += K_GaragePosition_Precision_Compensation;
     }
    
     if(MessageTx_GaragePosition > K_MessageTx_GateOpenAngle_Max)
     {
	  MessageTx_GaragePosition = K_MessageTx_GateOpenAngle_Max;
     }
     
     if(FALSE == GarageLearned_Status)
     {
	  MessageTx_GaragePosition = K_MessageTx_GaragePosition_100Percent;
     }
    
}

/*********************************************************************************************
** Name:	  MessageTransmit_LearnStatus(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_LearnStatus(void)
{
       MessageTx_SystemLearnedStatus = SystemLearned_Status;
       MessageTx_GarageLearnedStatus = GarageLearned_Status;
      // MessageTx_GarageLearnAction = ShutFaceSwitch_LongPress_Status;
       MessageTx_SystemLearnFailure = System_Learn_Failure;
}
/*Debug_Msg*/
/*********************************************************************************************
** Name:	  MessageTransmit_Debug_Msg_0x711(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_Debug_Msg_0x711(void)
{
     static uint16_t MessageTx_Debug_Msg_0x711_Status;
     
     if((TRUE == Configuration_SPX1_DebugMessage) && (FALSE == MessageTx_Debug_Msg_0x711_Status))
     {
	   InterMsgTransEnable(0);
	   u8InterInfoCheckStart = 1;
	   
	   MessageTx_Debug_Msg_0x711_Status = TRUE;
     }
     else if ((FALSE == Configuration_SPX1_DebugMessage) && (TRUE == MessageTx_Debug_Msg_0x711_Status))
     {
	   InterMsgTransDisable(0);
	   u8InterInfoCheckStart = 0;
	   
	   MessageTx_Debug_Msg_0x711_Status = FALSE;
     }

     if(TRUE == Configuration_SPX1_DebugMessage)
     {
          MessageTx_BATT1 = VBATT1_Voltage/10;
          MessageTx_BATT2 = VBATT2_Voltage/10;

	  if(TRUE == Motor1_Working_Status)
	  {
	        MessageTx_SpindleCurrent = Motor1_Current;
		MessageTx_SpindleCurrentOffset = Motor1_Current_Threshold;
                MessageTx_SpindlePWM = Motor1_Duty_Request/40;
	  }
	  else
	  {
		MessageTx_SpindleCurrent = 0;
		MessageTx_SpindleCurrentOffset = 0;
                MessageTx_SpindlePWM = 0;
	  }
	  
	  if(TRUE == CinchMotor_Working_Status)
	  {
	        MessageTx_LatchCurrent = CinchMotor_Current;	  
                MessageTx_LatchPWM = CinchMotor_Duty_Request/40;
	  }
	  else
	  {
		MessageTx_LatchCurrent = 0;	  
                MessageTx_LatchPWM = 0;
	  }
     }
     else
     {
	  MessageTx_BATT1 = 0;
	  MessageTx_BATT2 = 0;
	  MessageTx_SpindleCurrent = 0;
	  MessageTx_SpindleCurrentOffset = 0;
	  MessageTx_SpindlePWM = 0;
	  MessageTx_LatchCurrent = 0;
	  MessageTx_LatchPWM = 0;
     }

}

/*********************************************************************************************
** Name:	  MessageTransmit_Debug_Msg_0x712(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_Debug_Msg_0x712(void)
{
    static uint16_t MessageTx_Debug_Msg_0x712_Status;
    
     static uint16_t MessageTx_StallEventSpindle_Timer;
     static uint16_t MessageTx_StallEventSpindle_Status;
     
     if((TRUE == Configuration_SPX1_DebugMessage) && (FALSE == MessageTx_Debug_Msg_0x712_Status))
     {
	   InterMsgTransEnable(1);
	   u8InterInfoCheckStart = 1;
	   
	   MessageTx_Debug_Msg_0x712_Status = TRUE;
     }
     else if ((FALSE == Configuration_SPX1_DebugMessage) && (TRUE == MessageTx_Debug_Msg_0x712_Status))
     {
	   InterMsgTransDisable(1);
	   u8InterInfoCheckStart = 0;
	   
	   MessageTx_Debug_Msg_0x712_Status = FALSE;
     }

     if(TRUE == Configuration_SPX1_DebugMessage)
     {   
          MessageTx_SpindleMovingSection = Motor1_SpeedZoneIndex;
	  	  
          MessageTx_HallSpeedReal = Motor1_RealSpeed;
          MessageTx_HallSpeedSet = Motor1_DesiredSpeed_Request;
          MessageTx_HallReal = Motor1_Position;
          MessageTx_HallMaxSet = SystemLearned_Position;
	  
	  if(Motor1_ObstacleType == EnhancedCurrentObstacle)
	  {
	       MessageTx_StallEventSpindle = _StallEventSpindle_EnhancedCurrentStall;
	  }
	  else if(Motor1_ObstacleType == FixedCurrentObstacle)
	  {
	       MessageTx_StallEventSpindle = _StallEventSpindle_TopLimitCurrentStall;
	  }
	  else if(Motor1_ObstacleType == HallPluseObstacle)
	  {
	       MessageTx_StallEventSpindle = _StallEventSpindle_HallStall;
	  }
	  else if(CurrentDynamicTelltales.bits.AntipinchPressedLeft == TRUE)
	  {
	       MessageTx_StallEventSpindle = _StallEventSpindle_LeftAPSTriggered;
	  }
	  else if(CurrentDynamicTelltales.bits.AntipinchPressed == TRUE)
	  {
	       MessageTx_StallEventSpindle = _StallEventSpindle_RightAPSTriggered;

	  } 
	  else
	  {
	       MessageTx_StallEventSpindle = _StallEventSpindle_Normal;
	  }
	  
	  if((MessageTx_StallEventSpindle != _StallEventSpindle_Normal) && (FALSE == MessageTx_StallEventSpindle_Status))
	  {
	       MessageTx_StallEventSpindle_Timer = 0;
	       MessageTx_StallEventSpindle_Status = TRUE;
	  }
	   
	  if(TRUE == MessageTx_StallEventSpindle_Status)
	  {
	       if(MessageTx_StallEventSpindle_Timer >= K_MessageTx_StallEventSpindle_Time)
	       {
	            MessageTx_StallEventSpindle = _StallEventSpindle_Normal;
	       }
	       else
	       {
	            MessageTx_StallEventSpindle_Timer ++;
	       }
	       
	       if(((ActiveSystemMode == SystemPowerOpening) && ((LastSystemMode == SystemReleased) || (LastSystemMode == SystemOpenedFully) ||(LastSystemMode == SystemMechFailure)))
                  || ((ActiveSystemMode == SystemPowerClosing) && ((LastSystemMode == SystemReleased) || (LastSystemMode == SystemOpenedFully) ||(LastSystemMode == SystemMechFailure))))
               {
	             MessageTx_StallEventSpindle_Status = FALSE;  
               }
	  }

     }
     else
     {
	  MessageTx_SpindleMovingSection = 0;	  
          MessageTx_HallSpeedReal = 0;
          MessageTx_HallSpeedSet = 0;
          MessageTx_HallReal = 0;
          MessageTx_HallMaxSet = 0;
	  MessageTx_StallEventSpindle = 0;
     }

}

/*********************************************************************************************
** Name:	  MessageTransmit_Debug_Msg_0x713(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_Debug_Msg_0x713(void)
{
     static uint16_t MessageTx_Debug_Msg_0x713_Status;
     
     if((TRUE == Configuration_SPX1_DebugMessage) && (FALSE == MessageTx_Debug_Msg_0x713_Status))
     {
	   InterMsgTransEnable(2);
	   u8InterInfoCheckStart = 1;
	   
	   MessageTx_Debug_Msg_0x713_Status = TRUE;
     }
     else if ((FALSE == Configuration_SPX1_DebugMessage) && (TRUE == MessageTx_Debug_Msg_0x713_Status))
     {
	   InterMsgTransDisable(2);
	   u8InterInfoCheckStart = 0;
	   
	   MessageTx_Debug_Msg_0x713_Status = FALSE;
     }

     if(TRUE == Configuration_SPX1_DebugMessage)
     {   
           MessageTx_HallParkSet = GarageLearned_Position;
           MessageTx_HallMaxAngle = SystemLearned_Position + K_StopFromMaxTravel_HallCount;
     }
     else
     {
	   MessageTx_HallParkSet = 0;
           MessageTx_HallMaxAngle = 0;
     }
}

/*********************************************************************************************
** Name:	  MessageTransmit_Debug_Msg_0x714(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_Debug_Msg_0x714(void)
{
     static uint16_t MessageTx_Debug_Msg_0x714_Status;
     
     if((TRUE == Configuration_SPX1_DebugMessage) && (FALSE == MessageTx_Debug_Msg_0x714_Status))
     {
	   InterMsgTransEnable(3);
	   u8InterInfoCheckStart = 1;
	   
	   MessageTx_Debug_Msg_0x714_Status = TRUE;
     }
     else if ((FALSE == Configuration_SPX1_DebugMessage) && (TRUE == MessageTx_Debug_Msg_0x714_Status))
     {
	   InterMsgTransDisable(3);
	   u8InterInfoCheckStart = 0;
	   
	   MessageTx_Debug_Msg_0x714_Status = FALSE;
     }
}
#endif
#endif

#ifdef _FAW_COM 
/*********************************************************************************************
** Name:	  MessageTransmit_LuggageDoorWorkingSt(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/ 
 static void MessageTransmit_LuggageDoorWorkingSt(void)
 {
      if(ActiveSystemMode == SystemOpenedFully)
      {
	   MessageTx_LuggageDoorWorkingSt = _LuggageDoorWorkingSt_Top;
      }
      else if(ActiveSystemMode == SystemClosedFully)
      {
	   MessageTx_LuggageDoorWorkingSt = _LuggageDoorWorkingSt_Bottom;
      }
      else if((ActiveSystemMode == SystemPowerOpening) 
            || (ActiveSystemMode == SystemReleaseToPowerOpen))
      {
	   MessageTx_LuggageDoorWorkingSt = _LuggageDoorWorkingSt_Upping;
      }
      else if((ActiveSystemMode == SystemPowerClosing) 
            || (ActiveSystemMode == SystemPowerCinching)
	    || (ActiveSystemMode == SystemPowerParking))
      {
	   MessageTx_LuggageDoorWorkingSt = _LuggageDoorWorkingSt_Downing;
      }
      else if(ActiveSystemMode == SystemReleased) 
      {
	   if((TRUE == GarageEnd_SoftStop_Position_Status) && (TRUE == GarageLearned_Status))
	   {
		MessageTx_LuggageDoorWorkingSt = _LuggageDoorWorkingSt_Top;
	   }
	   else
	   {
	        MessageTx_LuggageDoorWorkingSt = _LuggageDoorWorkingSt_Hovering;
	   }
      }
      else if(ActiveSystemMode == SystemMechFailure)
      {
	   MessageTx_LuggageDoorWorkingSt = _LuggageDoorWorkingSt_Unknown;
      }
 }
/*********************************************************************************************
** Name:	  MessageTransmit_LuggageDoorPreviousMovement(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_LuggageDoorPreviousMovement(void)
{
     if(MessageTx_LuggageDoorWorkingSt == _LuggageDoorWorkingSt_Hovering) 
     {
          if(LastPowerState_ForReversal == SystemPowerOpening) 
          {
	        MessageTx_LuggageDoorPreviousMovement = _LuggageDoorPreviousMovement_Opening;
          }
          else if(LastPowerState_ForReversal == SystemPowerClosing) 
          {
	        MessageTx_LuggageDoorPreviousMovement = _LuggageDoorPreviousMovement_Closing;
          }
          else
          {
	        MessageTx_LuggageDoorPreviousMovement = _LuggageDoorPreviousMovement_Inactive;
          }
     }
     else
     {
	  MessageTx_LuggageDoorPreviousMovement = _LuggageDoorPreviousMovement_Inactive;
     }
} 
/*********************************************************************************************
** Name:	  MessageTransmit_LuggageDoorSt(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_LuggageDoorSt(void)
{
     if((ActiveSystemMode == SystemClosedFully) || (ActiveSystemMode == SystemInitDefault))
     {
	  MessageTx_LuggageDoorSt = _LuggageDoorSt_Close;
     }
     else
     {
	  MessageTx_LuggageDoorSt = _LuggageDoorSt_Open;
     }
     /*if((FALSE == PawlSwitch_Status) && (FALSE == SecondarySwitch_Status))
     {
          MessageTx_LuggageDoorSt = _LuggageDoorSt_Close;
     }
     else if((TRUE == PawlSwitch_Status) && (TRUE == SecondarySwitch_Status))
     {
	  MessageTx_LuggageDoorSt = _LuggageDoorSt_Open;
     }*/
}
/*********************************************************************************************
** Name:	  MessageTransmit_LuggageLockSt(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_LuggageLockSt(void)
{
     if((ActiveSystemMode == SystemClosedFully) || (ActiveSystemMode == SystemInitDefault))
     {
	  MessageTx_LuggageLockSt = _LuggageLockSt_Lock;
     }
     else
     {
	  MessageTx_LuggageLockSt = _LuggageLockSt_Unlock;
     }
     
     /*if((FALSE == PawlSwitch_Status) && (FALSE == SecondarySwitch_Status))
     {
          MessageTx_LuggageLockSt = _LuggageLockSt_Lock;
     }
     else
     {
	  MessageTx_LuggageLockSt = _LuggageLockSt_Unlock;
     }*/
}
/*********************************************************************************************
** Name:	  MessageTransmit_LuggageSwitch_Inside(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_LuggageSwitch_Inside(void)
{
     static uint16_t MessageTx_LuggageSwitch_Inside_Timer;
     
     if(TRUE == ShutFaceSwitch_ShortPress_Active)
     {
	   MessageTx_LuggageSwitch_Inside = _LuggageSwitch_Inside_Pressed;	   
	   MessageTx_LuggageSwitch_Inside_Timer = 0;
     }
        
     if(MessageTx_LuggageSwitch_Inside_Timer >= K_MessageTx_LuggageSwitch_Inside_Time)
     {
	   MessageTx_LuggageSwitch_Inside = _LuggageSwitch_Inside_Not_Pressed;
     }
     else
     {
	   MessageTx_LuggageSwitch_Inside_Timer ++;
     }
}
/*********************************************************************************************
** Name:	  MessageTransmit_LatchSwitch(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_LatchSwitch(void)
{
      #ifdef _CONFIG_PawlSwitch
      MessageTx_PawlSwitch = PawlSwitch_Status;
      #endif
      #ifdef _CONFIG_SecondarySwitch
      MessageTx_SecondarySwitch = SecondarySwitch_Status;
      #endif
      #ifdef _CONFIG_PositionSwitch
      MessageTx_PositonSwitch = PositionSwitch_Status;
      #endif
      #ifdef _CONFIG_PrimarySwitch
      MessageTx_PrimarySwitch = PrimarySwitch_Status;
      #endif
      
      MessageTx_ShutFaceSwitch = ShutFaceSwitch_Status;
}

/*********************************************************************************************
** Name:	  MessageTransmit_GateOpenAngle(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_GateOpenAngle(void)
{
     if(TRUE == SystemLearned_Status)
     {
           MessageTx_GateOpenAngle = (uint16_t)((uint32_t)(Motor1_Position * 100) / SystemLearned_Position);	   
     }
     else
     {
	   MessageTx_GateOpenAngle = (uint16_t)((uint32_t)(Motor1_Position * 100) / K_MaxPosition_HallCount_Default);
     }
     
     if(MessageTx_GateOpenAngle > K_GateOpenAngle_Precision_Compensation)
     {
          MessageTx_GateOpenAngle -= K_GateOpenAngle_Precision_Compensation;
     }
     
     if(MessageTx_GateOpenAngle > K_MessageTx_GateOpenAngle_Max)
     {
	  MessageTx_GateOpenAngle = K_MessageTx_GateOpenAngle_Max;
     }
}

/*********************************************************************************************
** Name:	  MessageTransmit_GaragePosition(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_GaragePosition(void)
{
    if(TRUE == SystemLearned_Status)
    {
         if(TRUE == GarageLearned_Status)
         {
               MessageTx_GaragePosition = (uint16_t)((uint32_t)(GarageLearned_Position * 100) / SystemLearned_Position);
	       MessageTx_GaragePosition_Remainder = (uint16_t)((uint32_t)(GarageLearned_Position * 100) % SystemLearned_Position);
         }
         else
         {
	       MessageTx_GaragePosition = (uint16_t)((uint32_t)(K_GarageLearned_Position_Default * 100) / SystemLearned_Position);	       
         }
    }
    else
    {
	 if(TRUE == GarageLearned_Status)
         {
               MessageTx_GaragePosition = (uint16_t)((uint32_t)(GarageLearned_Position * 100) / K_SystemLearned_Position_Default);
	       MessageTx_GaragePosition_Remainder = (uint16_t)((uint32_t)(GarageLearned_Position * 100) % K_SystemLearned_Position_Default);                        
         }
         else
         {
	       MessageTx_GaragePosition = (uint16_t)((uint32_t)(K_GarageLearned_Position_Default * 100) / K_SystemLearned_Position_Default);
	       
         }
    }
    
     if(MessageTx_GaragePosition_Remainder > 0)
     {
	  MessageTx_GaragePosition += K_GaragePosition_Precision_Compensation;
     }
    
     if(MessageTx_GaragePosition > K_MessageTx_GateOpenAngle_Max)
     {
	  MessageTx_GaragePosition = K_MessageTx_GateOpenAngle_Max;
     }
     
     if(FALSE == GarageLearned_Status)
     {
	  MessageTx_GaragePosition = K_MessageTx_GaragePosition_100Percent;
     } 
}
/*********************************************************************************************
** Name:	  MessageTransmit_LearnStatus(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_LearnStatus(void)
{
       MessageTx_SystemLearnedStatus = SystemLearned_Status;
       MessageTx_GarageLearnedStatus = GarageLearned_Status;
       MessageTx_GarageLearnAction = ShutFaceSwitch_LongPress_Status;
       MessageTx_SystemLearnFailure = System_Learn_Failure;
}
#endif

#ifdef _CTCS_COM 
/*********************************************************************************************
** Name:	  MessageTransmit_GateMotion(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/ 
 static void MessageTransmit_GateMotion(void)
 {
      if(ActiveSystemMode == SystemOpenedFully)
      {
	   MessageTx_GateMotion = FullyOpened;
      }
      else if(ActiveSystemMode == SystemClosedFully)
      {
	   MessageTx_GateMotion = FullyClosed;
      }
      else if(ActiveSystemMode == SystemPowerOpening)
      {
	   MessageTx_GateMotion = Opening;
      }
      else if(ActiveSystemMode == SystemPowerClosing)
      {
	   MessageTx_GateMotion = Closing;
      }
      else if(ActiveSystemMode == SystemReleased)
      {
	   MessageTx_GateMotion = PLGStopped;
      }
      else if((ActiveSystemMode == SystemReleaseOnly) || (ActiveSystemMode == SystemReleaseToPowerOpen))
      {
	   MessageTx_GateMotion = LatchReleasing;
      }
      else if((ActiveSystemMode == SystemPowerCinching) || (ActiveSystemMode == SystemPowerParking)
             ||(ActiveSystemMode == SystemManualCinching) || (ActiveSystemMode == SystemManualParking))
      {
	   MessageTx_GateMotion = LatchCinching;
      }
      #ifdef _CONFIG_CAN_Bus
      else if((TRUE == Motor1_ManualMoving_Status) && (TRUE == Motor2_ManualMoving_Status))
      {
	   MessageTx_GateMotion = MovingByManual;
      }
      #endif
      else
      {
	   MessageTx_GateMotion = PLGStopped;
      }
      
 }
 
/*********************************************************************************************
** Name:	  MessageTransmit_GateOpenAngle(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_GateOpenAngle(void)
{
     if(TRUE == SystemLearned_Status)
     {
           MessageTx_GateOpenAngle = (uint16_t)((uint32_t)(Motor1_Position * 254) / SystemLearned_Position);
	   
     }
     else
     {
	   MessageTx_GateOpenAngle = (uint16_t)((uint32_t)(Motor1_Position * 254) / K_MaxPosition_HallCount_Default);
     }
     
     if(MessageTx_GateOpenAngle >= K_MessageTx_GateOpenAngle_Max)
     {
	  MessageTx_GateOpenAngle = K_MessageTx_GateOpenAngle_Max - 1;
     }
}

/*********************************************************************************************
** Name:	  MessageTransmit_GaragePosition(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_GaragePosition(void)
{
    if(FALSE == GarageHeightRequest_Process_Status)
    {        
        if(TRUE == SystemLearned_Status)
        {
            if(TRUE == GarageLearned_Status)
            {
                 MessageTx_GaragePosition = (uint16_t)((uint32_t)(GarageLearned_Position * 254) / SystemLearned_Position);
	         MessageTx_GaragePosition_Remainder = (uint16_t)((uint32_t)(GarageLearned_Position * 254) % SystemLearned_Position);
            }
            else
            {
	         MessageTx_GaragePosition = (uint16_t)((uint32_t)(SystemLearned_Position * 254) / SystemLearned_Position);	       
            }
        }
        else
        {
	    if(TRUE == GarageLearned_Status)
            {
                 MessageTx_GaragePosition = (uint16_t)((uint32_t)(GarageLearned_Position * 254) / K_SystemLearned_Position_Default);
	         MessageTx_GaragePosition_Remainder = (uint16_t)((uint32_t)(GarageLearned_Position * 254) % K_SystemLearned_Position_Default);                        
            }
            else
            {
	         MessageTx_GaragePosition = (uint16_t)((uint32_t)(SystemLearned_Position * 254) / K_SystemLearned_Position_Default);
	       
            }
        }
    
        if(MessageTx_GaragePosition_Remainder > 0)
        {
	     MessageTx_GaragePosition += K_GaragePosition_Precision_Compensation;
        }
    
        if(MessageTx_GaragePosition >= K_MessageTx_GateOpenAngle_Max)
        {
	     MessageTx_GaragePosition = K_MessageTx_GateOpenAngle_Max - 1;
        }
    }
    else
    {
	 MessageTx_GaragePosition = MessageRx_GarageHeight;
    }    
}

/*********************************************************************************************
** Name:	  MessageTransmit_PLG_AutoOperation(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_PLG_AutoOperation(void)
{  
    static uint16_t MessageTx_PLG_AutoOperation_Timer;	
    static uint8_t PLG_Operation_Inhibition_Check_Status;
    static uint16_t PLG_Operation_Inhibition_Check_Timer;
    static uint8_t PLG_Operation_Inhibition_Status;
    #define K_PLG_Operation_Inhibition_Check_Time 20
    #define K_MessageTx_PLG_Height_Set_Successful_Time 25
    #define K_MessageTx_PLG_Operation_Inhibition_Time 600
    
     if((ActiveSystemMode == SystemOpenedFully) || (ActiveSystemMode == SystemClosedFully) || (ActiveSystemMode == SystemReleased))
     {
          if((TRUE == ShutFaceSwitch_FallEdge_Active)
            //||(TRUE == ShutFaceLockSwitch_FallEdge_Active)
	    //||(TRUE == OpenCloseSwitch_FallEdge_Active)
            //||(TRUE == OutsideHandleSwitch_FallEdge_Active)
            //||(TRUE == TouchPad_FallEdge_Active)
            //||(TRUE == RemoteKey_FallEdge_Active)
            ||(TRUE == FobLongPress_FallEdge_Active)
            ||(TRUE == PKETrunkButton_FallEdge_Active)
            //||(TRUE == HMIVirtualButton_FallEdge_Active)
	    ||(TRUE == AppOpen_FallEdge_Active)
	    ||(TRUE == AppClose_FallEdge_Active)
	    ||(TRUE == VROpen_FallEdge_Active)
	    ||(TRUE == VRClose_FallEdge_Active)
	    ||(TRUE == AutoOpen_FallEdge_Active)
	    //||(TRUE == AutoClose_FallEdge_Active)
	    ||(TRUE == DriverButton_FallEdge_Active)
	    ||(TRUE == Motor1_FollowClose_Command_Active)
	    ||(TRUE == Motor1_FollowOpen_Command_Active))
          {
	       PLG_Operation_Inhibition_Check_Status = TRUE;
	       PLG_Operation_Inhibition_Check_Timer = 0;
          }
     }
     
     if(TRUE == PLG_Operation_Inhibition_Check_Status)
     {
	  if(PLG_Operation_Inhibition_Check_Timer >= K_PLG_Operation_Inhibition_Check_Time)
	  {
		if((TRUE == CurrentStaticTelltales.bits.Voltage)
                   ||(TRUE == CurrentStaticTelltales.bits.Temperature)
                   ||((TRUE == CurrentStaticTelltales.bits.PlayProtected) && (ActiveSystemMode == SystemReleased))
                   //||(TRUE == CurrentStaticTelltales.bits.AntipinchPressed)
                   //||(TRUE == CurrentStaticTelltales.bits.SpindleMotorFault)
                   //||(TRUE == CurrentStaticTelltales.bits.LatchMotorFault)
                   ||((TRUE == CurrentStaticTelltales.bits.OverObstacleTimes) && (ActiveSystemMode == SystemReleased))
	           //||(TRUE == CurrentStaticTelltales.bits.VehicleSpeed)
	           //||(TRUE == CurrentStaticTelltales.bits.DisableMode)
	           ||((TRUE == CurrentStaticTelltales.bits.SystemUnlearned) && (ActiveSystemMode == SystemReleased))
	           )
		   {
			PLG_Operation_Inhibition_Status = TRUE;
		   }
		   else
		   {
			PLG_Operation_Inhibition_Status = FALSE;
		   }
		   
		   PLG_Operation_Inhibition_Check_Status = FALSE;
		   PLG_Operation_Inhibition_Check_Timer = 0;
	  }
	  else
	  {
	       PLG_Operation_Inhibition_Check_Timer ++;
	  }
     }
    
    /*Update MessageTx_PLG_AutoOperation*/
    if(ActiveSystemMode == SystemPowerOpening)
    {
	MessageTx_PLG_AutoOperation = _PLG_RUNNINING_OPERATION;//_PLG_OPEN_OPERATION;
    }  
    else if(ActiveSystemMode == SystemPowerClosing)
    {
	MessageTx_PLG_AutoOperation = _PLG_RUNNINING_OPERATION;//_PLG_CLOSE_OPERATION;
    }
    else if(TRUE == GarageLearnedSucessful_Status)
    {	
	MessageTx_PLG_AutoOperation = _PLG_HEIGHT_MEMORY_SET_SUCCESSFUL;
	
	MessageTx_PLG_AutoOperation_Timer ++;
	if(MessageTx_PLG_AutoOperation_Timer > K_MessageTx_PLG_Height_Set_Successful_Time)
	{
	    GarageLearnedSucessful_Status = FALSE;
	    MessageTx_PLG_AutoOperation_Timer = 0;
	}
    }	
    else if(TRUE == PLG_Operation_Inhibition_Status) 
    {
	 MessageTx_PLG_AutoOperation = _PLG_OPERATION_INHIBITION;
	 MessageTx_PLG_AutoOperation_Timer ++;
	 if(MessageTx_PLG_AutoOperation_Timer > K_MessageTx_PLG_Operation_Inhibition_Time)
	 {
	    PLG_Operation_Inhibition_Status = FALSE;
	    MessageTx_PLG_AutoOperation_Timer = 0;
	 }
    }
    else
    {
	 MessageTx_PLG_AutoOperation = _NO_OPERATION;
    }
	
}

#ifdef _CONFIG_CAN_Bus
/*********************************************************************************************
** Name:	  MessageTransmit_WarnMsg_PLG(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_WarnMsg_PLG(void)
{  
     static uint8_t MessageTx_WarnMsg_Inhibition_Start_Status; 
     static uint8_t MessageTx_WarnMsg_Failure_Start_Status; 
     static uint16_t MessageTx_WarnMsg_Counter; 
     static uint16_t MessageTx_WarnMsg_Timer; 
     static uint16_t MessageTx_WarnMsg_Inhibition_Check_Timer;
     static uint8_t MessageTx_WarnMsg_Inhibition_Check_Status;
     
     static uint16_t MessageTx_WarnMsg_Failure_Check_Timer;
     static uint8_t MessageTx_WarnMsg_Failure_Check_Status;

     static uint8_t MessageTx_WarnMsg_Failure_Status;
     static uint8_t MessageTx_WarnMsg_Failure_LastStatus;
     
     #define K_MessageTx_WarnMsg_Failure_Check_Time 20    
     #define K_MessageTx_WarnMsg_Inhibition_Check_Time 20
     #define K_MessageTx_WarnMsg_Count 6
     #define K_MessageTx_WarnMsg_Cycle_Time 100
       
     if((ActiveSystemMode == SystemOpenedFully) || (ActiveSystemMode == SystemClosedFully) || (ActiveSystemMode == SystemReleased))
     {
          if((TRUE == ShutFaceSwitch_FallEdge_Active)
            //||(TRUE == ShutFaceLockSwitch_FallEdge_Active)
	    //||(TRUE == OpenCloseSwitch_FallEdge_Active)
            //||(TRUE == OutsideHandleSwitch_FallEdge_Active)
            //||(TRUE == TouchPad_FallEdge_Active)
            //||(TRUE == RemoteKey_FallEdge_Active)
            ||(TRUE == FobLongPress_FallEdge_Active)
            ||(TRUE == PKETrunkButton_FallEdge_Active)
            //||(TRUE == HMIVirtualButton_FallEdge_Active)
	    ||(TRUE == AppOpen_FallEdge_Active)
	    ||(TRUE == AppClose_FallEdge_Active)
	    ||(TRUE == VROpen_FallEdge_Active)
	    ||(TRUE == VRClose_FallEdge_Active)
	    ||(TRUE == AutoOpen_FallEdge_Active)
	    //||(TRUE == AutoClose_FallEdge_Active)
	    ||(TRUE == DriverButton_FallEdge_Active)
	    ||(TRUE == Motor1_FollowClose_Command_Active)
	    ||(TRUE == Motor1_FollowOpen_Command_Active))
          {
	       	 MessageTx_WarnMsg_Inhibition_Check_Status = TRUE;
	         MessageTx_WarnMsg_Inhibition_Check_Timer = 0;
	   	   
                 MessageTx_WarnMsg_Failure_Check_Status = TRUE;
	         MessageTx_WarnMsg_Failure_Check_Timer = 0;
          }
     }
     
     if(TRUE == MessageTx_WarnMsg_Inhibition_Check_Status)
     {
	  if(MessageTx_WarnMsg_Inhibition_Check_Timer >= K_MessageTx_WarnMsg_Inhibition_Check_Time)
	  {
		if((TRUE == CurrentStaticTelltales.bits.Voltage)
                   ||(TRUE == CurrentStaticTelltales.bits.Temperature)
                   ||((TRUE == CurrentStaticTelltales.bits.PlayProtected) && (ActiveSystemMode == SystemReleased))
                   //||(TRUE == CurrentStaticTelltales.bits.AntipinchPressed)
                   //||(TRUE == CurrentStaticTelltales.bits.SpindleMotorFault)
                   //||(TRUE == CurrentStaticTelltales.bits.LatchMotorFault)
                   ||((TRUE == CurrentStaticTelltales.bits.OverObstacleTimes) && (ActiveSystemMode == SystemReleased))
	           //||(TRUE == CurrentStaticTelltales.bits.VehicleSpeed)
	           //||(TRUE == CurrentStaticTelltales.bits.DisableMode)
	           ||((TRUE == CurrentStaticTelltales.bits.SystemUnlearned) && (ActiveSystemMode == SystemReleased))
	           )
		   {			
			MessageTx_WarnMsg_Inhibition_Start_Status = TRUE;
	                MessageTx_WarningMessageID_PLG = _WARNING_INHIBITION;
	                MessageTx_BitStatus_PLG = _BITSTATUS_SET;
		   }		   
		   MessageTx_WarnMsg_Inhibition_Check_Status = FALSE;
		   MessageTx_WarnMsg_Inhibition_Check_Timer = 0;
	  }
	  else
	  {
	       MessageTx_WarnMsg_Inhibition_Check_Timer ++;
	  }
     }

         /*MessageTx_WarnMsg_Failure_Start_Status*/
     MessageTx_WarnMsg_Failure_LastStatus = MessageTx_WarnMsg_Failure_Status;
     
     if(TRUE == MessageTx_WarnMsg_Failure_Check_Status)
     {
	  if(MessageTx_WarnMsg_Failure_Check_Timer >= K_MessageTx_WarnMsg_Failure_Check_Time)
	  {
                 if((TRUE == DTCData_Table.table.Motor1_STG.DTCData.data.DTCStatus.bits.TestFailed)
                   ||(TRUE == DTCData_Table.table.Motor1_STB.DTCData.data.DTCStatus.bits.TestFailed)
	           ||(TRUE == DTCData_Table.table.Motor1_OC.DTCData.data.DTCStatus.bits.TestFailed)
	           ||(TRUE == DTCData_Table.table.CinchMotor_STG.DTCData.data.DTCStatus.bits.TestFailed)
                   ||(TRUE == DTCData_Table.table.CinchMotor_STB.DTCData.data.DTCStatus.bits.TestFailed)
                   ||(TRUE == DTCData_Table.table.CinchMotor_OC.DTCData.data.DTCStatus.bits.TestFailed)
	           ||(TRUE == DTCData_Table.table.AntiPinchRight_STG.DTCData.data.DTCStatus.bits.TestFailed) 
                   ||(TRUE == DTCData_Table.table.AntiPinchRight_STBorOC.DTCData.data.DTCStatus.bits.TestFailed)
	           ||(TRUE == DTCData_Table.table.AntiPinchLeft_STG.DTCData.data.DTCStatus.bits.TestFailed) 
                   ||(TRUE == DTCData_Table.table.AntiPinchLeft_STBorOC.DTCData.data.DTCStatus.bits.TestFailed)
	           )
                  {	     
	                 MessageTx_WarnMsg_Failure_Status = TRUE;
	                 MessageTx_WarningMessageID_PLG = _WARNING_FAILURE;
	                 MessageTx_BitStatus_PLG = _BITSTATUS_SET;
                  }
		  
		  MessageTx_WarnMsg_Failure_Check_Status = FALSE;
		  MessageTx_WarnMsg_Failure_Check_Timer = 0;
	  }
	  else
	  {
	       MessageTx_WarnMsg_Failure_Check_Timer ++;
	  }
     }
     else if((TRUE == DTCData_Table.table.HallA1_NoHall.DTCData.data.DTCStatus.bits.TestFailed)
	    ||(TRUE == DTCData_Table.table.HallA2_NoHall.DTCData.data.DTCStatus.bits.TestFailed))
     {
	   MessageTx_WarnMsg_Failure_Status = TRUE;
	   MessageTx_WarningMessageID_PLG = _WARNING_FAILURE;
	   MessageTx_BitStatus_PLG = _BITSTATUS_SET;
     }    
     
     
     if((FALSE == DTCData_Table.table.Motor1_STG.DTCData.data.DTCStatus.bits.TestFailed) 
        &&(FALSE == DTCData_Table.table.Motor1_STB.DTCData.data.DTCStatus.bits.TestFailed)
	&&(FALSE == DTCData_Table.table.Motor1_OC.DTCData.data.DTCStatus.bits.TestFailed)
	&&(FALSE == DTCData_Table.table.CinchMotor_STG.DTCData.data.DTCStatus.bits.TestFailed)
        &&(FALSE == DTCData_Table.table.CinchMotor_STB.DTCData.data.DTCStatus.bits.TestFailed)
        &&(FALSE == DTCData_Table.table.CinchMotor_OC.DTCData.data.DTCStatus.bits.TestFailed)
	&&(FALSE == DTCData_Table.table.AntiPinchRight_STG.DTCData.data.DTCStatus.bits.TestFailed) 
        &&(FALSE == DTCData_Table.table.AntiPinchRight_STBorOC.DTCData.data.DTCStatus.bits.TestFailed)
	&&(FALSE == DTCData_Table.table.AntiPinchLeft_STG.DTCData.data.DTCStatus.bits.TestFailed) 
        &&(FALSE == DTCData_Table.table.AntiPinchLeft_STBorOC.DTCData.data.DTCStatus.bits.TestFailed)
	&&(FALSE == DTCData_Table.table.HallA1_NoHall.DTCData.data.DTCStatus.bits.TestFailed)
	&&(FALSE == DTCData_Table.table.HallA2_NoHall.DTCData.data.DTCStatus.bits.TestFailed))
     {	     
	     MessageTx_WarnMsg_Failure_Status = FALSE;
     }
	  
     
     if((TRUE == MessageTx_WarnMsg_Failure_Status) && (FALSE == MessageTx_WarnMsg_Failure_LastStatus))
     {
	  MessageTx_WarnMsg_Failure_Start_Status = TRUE;
	  MessageTx_WarnMsg_Timer = 0;
	  
     }
     else if((FALSE == MessageTx_WarnMsg_Failure_Status) && (TRUE == MessageTx_WarnMsg_Failure_LastStatus))
     {
	 MessageTx_WarningMessageID_PLG = _WARNING_INIT;
	 MessageTx_BitStatus_PLG = _BITSTATUS_RESET;
     } 

    /*Event and Period Message Tramsmit Times*/
    if((TRUE == MessageTx_WarnMsg_Inhibition_Start_Status) && (FALSE == MessageTx_WarnMsg_Failure_Start_Status) && (CurrentSleepState == SleepState_Wakeup))
    {
	 if(MessageTx_WarnMsg_Timer == 0)
	 {
	      IlPutTxWarningMessageID_PLG(MessageTx_WarningMessageID_PLG);
	      IlPutTxBitStatus_PLG(MessageTx_BitStatus_PLG);
              IlPutTxID2_PLG(0x32);
              IlPutTxBitRefreshRate_PLG(0x01);
	      
	      MessageTx_WarnMsg_Counter ++;
	      
	      if(MessageTx_WarnMsg_Counter == (K_MessageTx_WarnMsg_Count - 1))
	      {
		   MessageTx_BitStatus_PLG = _BITSTATUS_RESET;
	      }
		  
	      if(MessageTx_WarnMsg_Counter < K_MessageTx_WarnMsg_Count)
	      {
		   MessageTx_WarnMsg_Timer = K_MessageTx_WarnMsg_Cycle_Time - 1;
	      }
	      else
	      {
		   MessageTx_WarnMsg_Inhibition_Start_Status = FALSE;
		   MessageTx_WarnMsg_Timer = 0;
		   MessageTx_WarnMsg_Counter = 0;
	      }
	  }
	  else
	  {
	      MessageTx_WarnMsg_Timer --;
	  }
     }
     else if((TRUE == MessageTx_WarnMsg_Failure_Start_Status) && (CurrentSleepState == SleepState_Wakeup))
     {
	 if(MessageTx_WarnMsg_Timer == 0)
	 {    
	      IlPutTxWarningMessageID_PLG(MessageTx_WarningMessageID_PLG);
	      IlPutTxBitStatus_PLG(MessageTx_BitStatus_PLG);
              IlPutTxID2_PLG(0x32);
              IlPutTxBitRefreshRate_PLG(0x01);
	      
	      if(TRUE == MessageTx_WarnMsg_Failure_Status)
	      {
                   MessageTx_WarnMsg_Timer = K_MessageTx_WarnMsg_Cycle_Time - 1;
	      }
              else
	      {
		   MessageTx_WarnMsg_Failure_Start_Status = FALSE;
		   MessageTx_WarnMsg_Timer = 0;
	      }
	  }
	  else
	  {
	      MessageTx_WarnMsg_Timer --;
	  }
     }
     else
     {
	  MessageTx_WarnMsg_Timer = 0;
	  MessageTx_WarnMsg_Counter = 0;
     }  
}


/*********************************************************************************************
** Name:	  MessageTransmit_PLG_RemoteCtrlFailReason(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_PLG_RemoteCtrlFailReason(void)
{
     static uint16_t MessageTx_PLG_RemoteCtrlFailReason_Timer; 
     #define K_PLG_RemoteCtrlFailReason_Check_Time 10
     #define K_MessageTx_PLG_RemoteCtrlFailReason_Time 32
     
     if((TRUE == AppOpen_FallEdge_Active) || (TRUE == AppClose_FallEdge_Active))
     {
	   PLG_RemoteCtrlFailReason_Check_Status = TRUE;
	   PLG_RemoteCtrlFailReason_Check_Timer = 0;
     }
     
     if(TRUE == PLG_RemoteCtrlFailReason_Check_Status)
     {
	  if(PLG_RemoteCtrlFailReason_Check_Timer >= K_PLG_RemoteCtrlFailReason_Check_Time)
	  {
	       if(TRUE == CurrentStaticTelltales.bits.Voltage)
	       {		     
		     MessageTx_PLG_RemoteCtrlFailReason = _FAIL_BY_VOLTAGE;
		     MessageTx_PLG_RemoteCtrlFailReason_Timer = 0;
	       }
	       else if(TRUE == CurrentStaticTelltales.bits.Temperature)
	       {		     
		     MessageTx_PLG_RemoteCtrlFailReason = _FAIL_BY_TEMPERATURE;
		     MessageTx_PLG_RemoteCtrlFailReason_Timer = 0;
	       }
	       else if(TRUE == CurrentStaticTelltales.bits.PlayProtected)
	       {		     
		     MessageTx_PLG_RemoteCtrlFailReason = _FAIL_BY_PLAY_PROTECTION;
		     MessageTx_PLG_RemoteCtrlFailReason_Timer = 0;
	       }
	       else if(TRUE == CurrentStaticTelltales.bits.AntipinchPressed)
	       {		     
		     MessageTx_PLG_RemoteCtrlFailReason = _FAIL_BY_OBSTRUCTER;
		     MessageTx_PLG_RemoteCtrlFailReason_Timer = 0;
	       }
	       else if(TRUE == CurrentStaticTelltales.bits.SystemFailure)
	       {	     
		     MessageTx_PLG_RemoteCtrlFailReason = _FAIL_BY_SYSTEM_ERROR;
		     MessageTx_PLG_RemoteCtrlFailReason_Timer = 0;
	       }
	       else if(TRUE == CurrentStaticTelltales.bits.SpindleMotorFault)
	       {		     
		     MessageTx_PLG_RemoteCtrlFailReason = _FAIL_BY_SYSTEM_ERROR;
		     MessageTx_PLG_RemoteCtrlFailReason_Timer = 0;
	       }
	       else if(TRUE == CurrentStaticTelltales.bits.LatchMotorFault)
	       {		     
		     MessageTx_PLG_RemoteCtrlFailReason = _FAIL_BY_SYSTEM_ERROR;
		     MessageTx_PLG_RemoteCtrlFailReason_Timer = 0;
	       }
	       /*else if(TRUE == CurrentStaticTelltales.bits.SystemFailure)
	       {	     
		     MessageTx_PLG_RemoteCtrlFailReason = _FAIL_BY_LOCAL_OPERATION;
		     MessageTx_PLG_RemoteCtrlFailReason_Timer = 0;
	       }*/
	       else
	       {
		     MessageTx_PLG_RemoteCtrlFailReason = _NO_FAIL_REASON;
	       }
	       
	       PLG_RemoteCtrlFailReason_Check_Status = FALSE;
	  }
	  else
	  {
	       PLG_RemoteCtrlFailReason_Check_Timer ++;
	  }
     }
        
     if(MessageTx_PLG_RemoteCtrlFailReason_Timer >= K_MessageTx_PLG_RemoteCtrlFailReason_Time)
     {
	  MessageTx_PLG_RemoteCtrlFailReason = _NO_FAIL_REASON;
     }
     else
     {
	  MessageTx_PLG_RemoteCtrlFailReason_Timer ++;
     }
}
#endif
#ifdef _CONFIG_LIN_Slave
/*********************************************************************************************
** Name:	  MessageTransmit_PLGMalfunction(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_PLGMalfunction(void)
{
     static uint16_t MessageTx_PLGMalfunction_Check_Timer;
     static uint8_t MessageTx_PLGMalfunction_Check_Status;
     
     #define K_MessageTx_PLGMalfunction_Check_Time 20
     
     if((ActiveSystemMode == SystemOpenedFully) || (ActiveSystemMode == SystemClosedFully) || (ActiveSystemMode == SystemReleased))
     {
          if((TRUE == ShutFaceSwitch_FallEdge_Active)
            //||(TRUE == ShutFaceLockSwitch_FallEdge_Active)
	    //||(TRUE == OpenCloseSwitch_FallEdge_Active)
            //||(TRUE == OutsideHandleSwitch_FallEdge_Active)
            //||(TRUE == TouchPad_FallEdge_Active)
            //||(TRUE == RemoteKey_FallEdge_Active)
            ||(TRUE == FobLongPress_FallEdge_Active)
            ||(TRUE == PKETrunkButton_FallEdge_Active)
            //||(TRUE == HMIVirtualButton_FallEdge_Active)
	    ||(TRUE == AppOpen_FallEdge_Active)
	    ||(TRUE == AppClose_FallEdge_Active)
	    ||(TRUE == VROpen_FallEdge_Active)
	    ||(TRUE == VRClose_FallEdge_Active)
	    ||(TRUE == AutoOpen_FallEdge_Active)
	    //||(TRUE == AutoClose_FallEdge_Active)
	    ||(TRUE == DriverButton_FallEdge_Active)
	    ||(TRUE == Motor1_FollowClose_Command_Active)
	    ||(TRUE == Motor1_FollowOpen_Command_Active))
          {
	       	 MessageTx_PLGMalfunction_Check_Timer = 0;
                 MessageTx_PLGMalfunction_Check_Status = TRUE;
          }
     }
     
     if(TRUE == MessageTx_PLGMalfunction_Check_Status)
     {
	  if(MessageTx_PLGMalfunction_Check_Timer >= K_MessageTx_PLGMalfunction_Check_Time)
	  {
                 if((TRUE == Motor1_STG_DTCStatus.bits.TestFailed) 
                   ||(TRUE == Motor1_STB_DTCStatus.bits.TestFailed)
	           ||(TRUE == Motor1_OC_DTCStatus.bits.TestFailed)
	           ||(TRUE == CinchMotor_STG_DTCStatus.bits.TestFailed)
                   ||(TRUE == CinchMotor_STB_DTCStatus.bits.TestFailed)
                   ||(TRUE == CinchMotor_OC_DTCStatus.bits.TestFailed)
	           ||(TRUE == AntiPinch_STG_DTCStatus.bits.TestFailed) 
                   ||(TRUE == AntiPinch_STBorOC_DTCStatus.bits.TestFailed))
                  {	     
	                 MessageTx_PLGMalfunction = TRUE;
                  }
		  
		  MessageTx_PLGMalfunction_Check_Status = FALSE;
		  MessageTx_PLGMalfunction_Check_Timer = 0;
	  }
	  else
	  {
	       MessageTx_PLGMalfunction_Check_Timer ++;
	  }
     }
     else if((TRUE == HallA1_NoHall_DTCStatus.bits.TestFailed)
	    ||(TRUE == HallA2_NoHall_DTCStatus.bits.TestFailed))
     {
	  MessageTx_PLGMalfunction = TRUE;
     }
     
     if((FALSE == Motor1_STG_DTCStatus.bits.TestFailed) 
        &&(FALSE == Motor1_STB_DTCStatus.bits.TestFailed)
	&&(FALSE == Motor1_OC_DTCStatus.bits.TestFailed)
	&&(FALSE == CinchMotor_STG_DTCStatus.bits.TestFailed)
        &&(FALSE == CinchMotor_STB_DTCStatus.bits.TestFailed)
        &&(FALSE == CinchMotor_OC_DTCStatus.bits.TestFailed)
	&&(FALSE == AntiPinch_STG_DTCStatus.bits.TestFailed) 
        &&(FALSE == AntiPinch_STBorOC_DTCStatus.bits.TestFailed)
	&&(FALSE == HallA1_NoHall_DTCStatus.bits.TestFailed)
	&&(FALSE == HallA2_NoHall_DTCStatus.bits.TestFailed))
     {	     
	     MessageTx_PLGMalfunction = FALSE;
     }
}
/*********************************************************************************************
** Name:	  MessageTransmit_PLG_RspError(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_PLG_RspError(void)
{	
     /*static uint16_t MessageTx_PLG_RspError_Check_Timer;
     static uint8_t MessageTx_PLG_RspError_Check_Status;
     
     static uint8_t MessageTx_PLG_RspError_Start_Status;
     static uint16_t MessageTx_PLG_RspError_Timer;
     
     #define K_MessageTx_PLG_RspError_Check_Time 5
     #define K_MessageTx_PLG_RspError_Time 500
     
     if((ActiveSystemMode == SystemOpenedFully) || (ActiveSystemMode == SystemClosedFully) || (ActiveSystemMode == SystemReleased))
     {
          if((TRUE == ShutFaceSwitch_FallEdge_Active)
            //||(TRUE == ShutFaceLockSwitch_FallEdge_Active)
	    //||(TRUE == OpenCloseSwitch_FallEdge_Active)
            //||(TRUE == OutsideHandleSwitch_FallEdge_Active)
            //||(TRUE == TouchPad_FallEdge_Active)
            //||(TRUE == RemoteKey_FallEdge_Active)
            ||(TRUE == FobLongPress_FallEdge_Active)
            ||(TRUE == PKETrunkButton_FallEdge_Active)
            //||(TRUE == HMIVirtualButton_FallEdge_Active)
	    ||(TRUE == AppOpen_FallEdge_Active)
	    ||(TRUE == AppClose_FallEdge_Active)
	    ||(TRUE == VROpen_FallEdge_Active)
	    ||(TRUE == VRClose_FallEdge_Active)
	    ||(TRUE == AutoOpen_FallEdge_Active)
	    //||(TRUE == AutoClose_FallEdge_Active)
	    ||(TRUE == DriverButton_FallEdge_Active)
	    ||(TRUE == Motor1_FollowClose_Command_Active)
	    ||(TRUE == Motor1_FollowOpen_Command_Active))
          {
	       	 MessageTx_PLG_RspError_Check_Status = 0;
	         MessageTx_PLG_RspError_Check_Timer = TRUE;
          }
     }
     
     if(TRUE == MessageTx_PLG_RspError_Check_Status)
     {
	  if(MessageTx_PLG_RspError_Check_Timer >= K_MessageTx_PLG_RspError_Check_Time)
	  {
		if((TRUE == CurrentStaticTelltales.bits.Voltage)
                   ||(TRUE == CurrentStaticTelltales.bits.Temperature)
                   ||((TRUE == CurrentStaticTelltales.bits.PlayProtected) && (ActiveSystemMode == SystemReleased))
                   //||(TRUE == CurrentStaticTelltales.bits.AntipinchPressed)
                   //||(TRUE == CurrentStaticTelltales.bits.SpindleMotorFault)
                   //||(TRUE == CurrentStaticTelltales.bits.LatchMotorFault)
                   ||((TRUE == CurrentStaticTelltales.bits.OverObstacleTimes) && (ActiveSystemMode == SystemReleased))
	           //||(TRUE == CurrentStaticTelltales.bits.VehicleSpeed)
	           //||(TRUE == CurrentStaticTelltales.bits.DisableMode)
	           ||((TRUE == CurrentStaticTelltales.bits.SystemUnlearned) && (ActiveSystemMode == SystemReleased))
	           )
		   {			
			MessageTx_PLG_RspError = TRUE;
			MessageTx_PLG_RspError_Start_Status = TRUE;
			MessageTx_PLG_RspError_Timer = 0;
		   }		   
		   MessageTx_PLG_RspError_Check_Status = FALSE;
		   MessageTx_PLG_RspError_Check_Timer = 0;
	  }
	  else
	  {
	       MessageTx_PLG_RspError_Check_Timer ++;
	  }
     }
     
     if(TRUE == MessageTx_PLG_RspError_Start_Status)
     {
	  if(MessageTx_PLG_RspError_Timer >= K_MessageTx_PLG_RspError_Time)
	  {
		MessageTx_PLG_RspError = FALSE;
		MessageTx_PLG_RspError_Start_Status = FALSE;
	  }
	  else
	  {
	        MessageTx_PLG_RspError_Timer ++;
	  }
     }
     else
     {
	  MessageTx_PLG_RspError_Timer = 0;
     }*/
     
     MessageTx_PLG_RspError = 0;
}

#endif

/*********************************************************************************************
** Name:	  MessageTransmit_LearnStatus(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_LearnStatus(void)
{
       if(TRUE == SystemLearned_Status)
       {
            MessageTx_SystemLearnedStatus = _PLG_CAL_LEARNED;
       }
       else
       {
	    MessageTx_SystemLearnedStatus = _PLG_CAL_UNLEARNED;
       }
       MessageTx_GarageLearnedStatus = GarageLearned_Status;
       MessageTx_GarageLearnAction = ShutFaceSwitch_LongPress_Status;
       MessageTx_SystemLearnFailure = System_Learn_Failure;
}
/*********************************************************************************************
** Name:	  MessageTransmit_LatchSwitch(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_LatchSwitch(void)
{
      #ifdef _CONFIG_PawlSwitch
      if(TRUE == PawlSwitch_Status)
      {
           MessageTx_PawlSwitch = _SWITCH_CLOSED;
      }
      else
      {
	   MessageTx_PawlSwitch = _SWITCH_OPEN;
      }
      #endif
      #ifdef _CONFIG_SecondarySwitch
      if(TRUE == SecondarySwitch_Status)
      {
           MessageTx_SecondarySwitch = _SWITCH_CLOSED;
      }
      else
      {
	   MessageTx_SecondarySwitch = _SWITCH_OPEN;
      }
      #endif
      #ifdef _CONFIG_PositionSwitch
      MessageTx_PositonSwitch = PositionSwitch_Status;
      #endif
      #ifdef _CONFIG_PrimarySwitch
      MessageTx_PrimarySwitch = PrimarySwitch_Status;
      #endif
}

#endif

#ifdef _CHANGAN_COM 
/*********************************************************************************************
** Name:	  MessageTransmit_GateMotion(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/ 
 static void MessageTransmit_GateMotion(void)
 {
      if(ActiveSystemMode == SystemOpenedFully)
      {
	   MessageTx_GateMotion = FullyOpened;
      }
      else if(ActiveSystemMode == SystemClosedFully)
      {
	   MessageTx_GateMotion = FullyClosed;
      }
      else if((ActiveSystemMode == SystemPowerOpening) 
            || (ActiveSystemMode == SystemReleaseToPowerOpen))
      {
	   MessageTx_GateMotion = Opening;
      }
      else if((ActiveSystemMode == SystemPowerClosing) 
            || (ActiveSystemMode == SystemPowerCinching)
	    || (ActiveSystemMode == SystemPowerParking))
      {
	   MessageTx_GateMotion = Closing;
      }
      else if(ActiveSystemMode == SystemReleased) 
      {
	   MessageTx_GateMotion = Stop;
      }
      else if(ActiveSystemMode == SystemMechFailure)
      {
	   MessageTx_GateMotion = Unknown;
      }
 }
 /*********************************************************************************************
** Name:	  MessageTransmit_LatchMotion(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_LatchMotion(void)
{
      if(ActiveLatchMode == LatchFullyCinched)
      {
	   MessageTx_LatchMotion = Cinched;
      }
      else if((ActiveLatchMode == LatchPreCinchCheck) || (ActiveLatchMode == LatchPowerCinching)
            || (ActiveLatchMode == LatchFindHomeAfterCinch))
      {
	   MessageTx_LatchMotion = Cinching;
      }
      else if((ActiveLatchMode == LatchPreReleasing)|| (ActiveLatchMode == LatchPowerReleasing)
             || (ActiveLatchMode == LatchFindHomeAfterRelease) || (ActiveLatchMode == LatchPreReleased))
      {
	   MessageTx_LatchMotion = Releasing;
      }
      else if(ActiveLatchMode == LatchFullyReleased)
      {
	   MessageTx_LatchMotion = Released;
      }
      else
      {
	   MessageTx_LatchMotion = Default;
      }
}

/*********************************************************************************************
** Name:	  MessageTransmit_LatchSwitch(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_LatchSwitch(void)
{
      #ifdef _CONFIG_PawlSwitch
      MessageTx_PawlSwitch = PawlSwitch_Status;
      #endif
      #ifdef _CONFIG_SecondarySwitch
      MessageTx_SecondarySwitch = SecondarySwitch_Status;
      #endif
      #ifdef _CONFIG_PositionSwitch
      MessageTx_PositonSwitch = PositionSwitch_Status;
      #endif
      #ifdef _CONFIG_PrimarySwitch
      MessageTx_PrimarySwitch = PrimarySwitch_Status;
      #endif  
}
/*********************************************************************************************
** Name:	  MessageTransmit_CommandActive(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_CommandActive(void)
{
      #ifdef _CONFIG_OpenCloseSwitch
      MessageTx_OpenCloseSwitch = OpenCloseSwitch_Status;
      #endif
      MessageTx_PKETrunkButton = PKETrunkButton_Status;
      MessageTx_RemoteKey = RemoteKey_Status;
      MessageTx_ShutFaceSwitch = ShutFaceSwitch_Status;
      MessageTx_KickSensor = KickSensor_Status;
      
}
/*********************************************************************************************
** Name:	  MessageTransmit_GateOpenAngle(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_GateOpenAngle(void)
{
     if(TRUE == SystemLearned_Status)
     {
           MessageTx_GateOpenAngle = (uint16_t)((uint32_t)(Motor1_Position * 255) / SystemLearned_Position);
     }
     else
     {
	   MessageTx_GateOpenAngle = (uint16_t)((uint32_t)(Motor1_Position * 255) / K_MaxPosition_HallCount_Default);
     }
     
     if(MessageTx_GateOpenAngle > K_GateOpenAngle_Precision_Compensation)
     {
          MessageTx_GateOpenAngle -= K_GateOpenAngle_Precision_Compensation;
     }
     
     if(MessageTx_GateOpenAngle > K_MessageTx_GateOpenAngle_Max)
     {
	  MessageTx_GateOpenAngle = K_MessageTx_GateOpenAngle_Max;
     }
}

/*********************************************************************************************
** Name:	  MessageTransmit_GaragePosition(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_GaragePosition(void)
{
    if(TRUE == SystemLearned_Status)
    {
         if(TRUE == GarageLearned_Status)
         {
               MessageTx_GaragePosition = (uint16_t)((uint32_t)(GarageLearned_Position * 100) / SystemLearned_Position);
	       MessageTx_GaragePosition_Remainder = (uint16_t)((uint32_t)(GarageLearned_Position * 100) % SystemLearned_Position);
         }
         else
         {
	       MessageTx_GaragePosition = (uint16_t)((uint32_t)(K_GarageLearned_Position_Default * 100) / SystemLearned_Position);	       
         }
    }
    else
    {
	 if(TRUE == GarageLearned_Status)
         {
               MessageTx_GaragePosition = (uint16_t)((uint32_t)(GarageLearned_Position * 100) / K_SystemLearned_Position_Default);
	       MessageTx_GaragePosition_Remainder = (uint16_t)((uint32_t)(GarageLearned_Position * 100) % K_SystemLearned_Position_Default);                        
         }
         else
         {
	       MessageTx_GaragePosition = (uint16_t)((uint32_t)(K_GarageLearned_Position_Default * 100) / K_SystemLearned_Position_Default);
	       
         }
    }
    
     if(MessageTx_GaragePosition_Remainder > 0)
     {
	  MessageTx_GaragePosition += K_GaragePosition_Precision_Compensation;
     }
    
     if(MessageTx_GaragePosition > K_MessageTx_GateOpenAngle_Max)
     {
	  MessageTx_GaragePosition = K_MessageTx_GateOpenAngle_Max;
     }
     
     if(FALSE == GarageLearned_Status)
     {
	  MessageTx_GaragePosition = K_MessageTx_GaragePosition_100Percent;
     }
    
}

/*********************************************************************************************
** Name:	  MessageTransmit_PLGConditionFault(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/ 
static void MessageTransmit_PLGConditionFault(void)
{
    if((Motor1_ObstacleType != NoObstacleDetected) || (Motor2_ObstacleType != NoObstacleDetected))
    {
	 MessageTx_ObstacleDetected = TRUE;   
    }
    else
    {
	 MessageTx_ObstacleDetected = FALSE; 
    }
    
    #ifdef _CONFIG_AntiPinch
    MessageTx_AntiPinch = AntiPinch_Status; 
    #endif

    if(TRUE == CurrentStaticTelltales.bits.PRNDL)
    {
	MessageTx_ParkFailure = TRUE; 
    }
    else
    {
	MessageTx_ParkFailure = FALSE; 
    }
    
    if(TRUE == CurrentStaticTelltales.bits.Crank)
    {
	MessageTx_CrankFailure = TRUE;
    }
    else
    {
	MessageTx_CrankFailure = FALSE; 
    }
	
    if(TRUE == CurrentStaticTelltales.bits.VehicleSpeed)
    {
	 MessageTx_SpeedFailure = TRUE; 

    }
    else
    {
	MessageTx_SpeedFailure = FALSE; 
    }
    
    if(TRUE == CurrentStaticTelltales.bits.Locked)
    {
	 MessageTx_LockFailure = TRUE;
    }
    else
    {
	MessageTx_LockFailure = FALSE; 
    }
    
    if(TRUE == CurrentStaticTelltales.bits.Voltage)
    {
	 MessageTx_VoltageFailure = TRUE;
    }
    else
    {
	MessageTx_VoltageFailure = FALSE; 
    }
    
    if((TRUE == CurrentStaticTelltales.bits.PlayProtected) || (TRUE == CurrentStaticTelltales.bits.OverObstacleTimes))
    {
	 MessageTx_PlayoffFailure = TRUE;
    }
    else
    {
	MessageTx_PlayoffFailure = FALSE; 
    }    
    
    if(TRUE == CurrentStaticTelltales.bits.Temperature)
    {
	 MessageTx_TemperatureFailure = TRUE;
    }
    else
    {
	MessageTx_TemperatureFailure = FALSE; 
    }
    
    if((TRUE == CurrentDynamicTelltales.bits.Spindle1WorkTimeout) || (TRUE == CurrentDynamicTelltales.bits.Spindle2WorkTimeout))
    {
	 MessageTx_TimeoutFailure = TRUE;
    }
    else
    {
	MessageTx_TimeoutFailure = FALSE; 
    }
    
    if((TRUE == Motor1_ThermalProtection_Status) || (TRUE == Motor2_ThermalProtection_Status))
    {
         MessageTx_GateThermalProtectionFailure = TRUE;
    }
    else
    {
	 MessageTx_GateThermalProtectionFailure = FALSE;
    }
    
    if(TRUE == CinchMotor_ThermalProtection_Status) 
    {
         MessageTx_LatchThermalProtectionFailure = TRUE;
    }
    else
    {
	 MessageTx_LatchThermalProtectionFailure = FALSE;
    }
    
    if(FALSE)
    {
         MessageTx_GateMotorStallFailure = TRUE;
    }
    else
    {
	 MessageTx_GateMotorStallFailure = FALSE;
    }
    
    if(TRUE == CinchMotorSoftStall_Status)
    {
	 MessageTx_LatchMotorStallFailure = TRUE;
    }
    else
    {
	 MessageTx_LatchMotorStallFailure = FALSE;
    }
}

/*********************************************************************************************
** Name:	  MessageTransmit_LearnStatus(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageTransmit_LearnStatus(void)
{
       MessageTx_SystemLearnedStatus = SystemLearned_Status;
       MessageTx_GarageLearnedStatus = GarageLearned_Status;
       MessageTx_GarageLearnAction = ShutFaceSwitch_LongPress_Status;
       MessageTx_SystemLearnFailure = System_Learn_Failure;
}

#endif



#ifdef _CONFIG_EngineSpeed
/*********************************************************************************************
** Name:	  MessageDebounce_EngineSpeed(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_EngineSpeed(void)
{
    static uint16_t EngineSpeed_Real_Timer = 0;
    
    if(TRUE == MessageRx_EngineSpeed_Ind)
    {  
	MessageRx_EngineSpeed_Ind = FALSE;

        /*Real-time Monitor*/	
	EngineSpeed_Real_Status = TRUE;
	EngineSpeed_Real_Timer = K_EngineSpeed_Real_Timeout;  
    }        
    /*Real-time Monitor*/
    if(TRUE == EngineSpeed_Real_Status)
    {
         if(EngineSpeed_Real_Timer == 0)
         {
	      EngineSpeed_Real_Status = FALSE;   
         }
         else
         {
	      EngineSpeed_Real_Timer --;
         }
    }
    
}
#endif
#ifdef _CONFIG_Odometer
/*********************************************************************************************
** Name:	  MessageDebounce_Odometer(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_Odometer(void)
{

}
#endif
#ifdef _CONFIG_TimeInformation
/*********************************************************************************************
** Name:	  MessageDebounce_TimeInformation(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_TimeInformation(void)
{

}
#endif

#ifdef _CONFIG_VehicleSOC
/*********************************************************************************************
** Name:	  MessageDebounce_VehicleSOC(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_VehicleSOC(void)
{
    static uint16_t VehicleSOC_Real_Timer = 0;
    
    if(TRUE == MessageRx_VehicleSOC_Ind)
    {  
	MessageRx_VehicleSOC_Ind = FALSE;

        /*Real-time Monitor*/	
	VehicleSOC_Real_Status = TRUE;
	VehicleSOC_Real_Timer = K_VehicleSOC_Real_Timeout;  
    }        
    /*Real-time Monitor*/
    if(TRUE == VehicleSOC_Real_Status)
    {
         if(VehicleSOC_Real_Timer == 0)
         {
	      VehicleSOC_Real_Status = FALSE;   
         }
         else
         {
	      VehicleSOC_Real_Timer --;
         }
    }
}
#endif

#ifdef _CONFIG_VehicleVoltage
/*********************************************************************************************
** Name:	  MessageDebounce_VehicleVoltage(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_VehicleVoltage(void)
{
    static uint16_t VehicleVoltage_Real_Timer = 0;
    
    if(TRUE == MessageRx_VehicleVoltage_Ind)
    {  
	MessageRx_VehicleVoltage_Ind = FALSE;

        /*Real-time Monitor*/	
	VehicleVoltage_Real_Status = TRUE;
	VehicleVoltage_Real_Timer = K_VehicleVoltage_Real_Timeout;  
    }        
    /*Real-time Monitor*/
    if(TRUE == VehicleVoltage_Real_Status)
    {
         if(VehicleVoltage_Real_Timer == 0)
         {
	      VehicleVoltage_Real_Status = FALSE;   
         }
         else
         {
	      VehicleVoltage_Real_Timer --;
         }
    }
}
#endif


#ifdef _CONFIG_VehicleChargeState
/*********************************************************************************************
** Name:	  MessageDebounce_VehicleChargeState(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_VehicleChargeState(void)
{
    static uint16_t VehicleChargeState_Timer = 0;
    static uint16_t VehicleChargeState_Real_Timer;

    VehicleChargeState_LastStatus = VehicleChargeState_Status;
    
    if(TRUE == MessageRx_VehicleChargeState_Ind)
    {  
	MessageRx_VehicleChargeState_Ind = FALSE;
    
        #ifdef _CHERY_COM
        if(MessageRx_VehicleChargeState == TRUE)
	#endif
	#ifdef _SGMW_COM
        if(MessageRx_VehicleChargeState == TRUE)
	#endif
	#ifdef _SGM_COM
        if(MessageRx_VehicleChargeState == TRUE)
	#endif
	#ifdef _CTCS_COM
        if(MessageRx_VehicleChargeState == TRUE)
	#endif
	#ifdef _DEARCC_COM
        if(MessageRx_VehicleChargeState == TRUE)
	#endif
	#ifdef _MAXUS_COM
        if((MessageRx_VehicleChargeState == TRUE)
	#endif
	#ifdef _DFMC_COM
        if(MessageRx_VehicleChargeState == TRUE)
	#endif
	#ifdef _BAIC_COM
        if(MessageRx_VehicleChargeState == TRUE)
	#endif
	#ifdef _DFLZM_COM
        if(MessageRx_VehicleChargeState == TRUE)
	#endif
	#ifdef _NIU_COM
        if(MessageRx_VehicleChargeState == TRUE)
	#endif
	#ifdef _CHANGAN_COM
        if(MessageRx_VehicleChargeState == TRUE)
	#endif
	{
	     VehicleChargeState_DataStream |= 0x0001;
        }
        if((MASK01BIT & VehicleChargeState_DataStream) == MASK01BIT)	 
        {    
             VehicleChargeState_Status = TRUE;
	     /*Timeout Monitor*/
	     VehicleChargeState_Timer = 0;
        }
        else if((MASK01BIT & VehicleChargeState_DataStream) == 0)
        {    
    	     VehicleChargeState_Status = FALSE;
        }       
    
        VehicleChargeState_DataStream <<=1;
         /*Real-time Monitor*/	
	VehicleChargeState_Real_Status = TRUE;
	VehicleChargeState_Real_Timer = K_VehicleChargeState_Real_Timeout;  
		
    }
         /*Real-time Monitor*/
    if(TRUE == VehicleChargeState_Real_Status)
    {
         if(VehicleChargeState_Real_Timer == 0)
         {
	      VehicleChargeState_Real_Status = FALSE; 
	      if(TRUE == K_VehicleChargeState_SingleEvent_Enable) /*10,1110 is MultiEvent, 1,111 is SingleEvent */
	      {
		   VehicleChargeState_SingleEvent_Enable = TRUE;
	      }
	      if(TRUE == VehicleChargeState_SingleEvent_Enable) 
	      {
		   VehicleChargeState_SingleEvent_Enable = FALSE;
		   VehicleChargeState_Status = FALSE;
	      }
         }
         else
         {
	      VehicleChargeState_Real_Timer --;
         }
    }
    
    /* VehicleChargeState RiseEdge and FallEdge Active monitor */  
    if((FALSE == VehicleChargeState_Status) && (TRUE == VehicleChargeState_LastStatus))
    {
    	 VehicleChargeState_RiseEdge_Active = TRUE;
    } 
    else
    {
    	 VehicleChargeState_RiseEdge_Active = FALSE;
    }
 
    if((TRUE == VehicleChargeState_Status) && (FALSE == VehicleChargeState_LastStatus))
    {
	 VehicleChargeState_FallEdge_Active = TRUE;

    }	 
    else
    {
	 VehicleChargeState_FallEdge_Active = FALSE;
    }	
}
#endif

#ifdef _CONFIG_VehicleBrake
/*********************************************************************************************
** Name:	  MessageDebounce_VehicleBrake(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_VehicleBrake(void)
{

}
#endif

#ifdef _CONFIG_VehicleCrash
/*********************************************************************************************
** Name:	  MessageDebounce_VehicleCrash(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_VehicleCrash(void)
{

}
#endif
#ifdef _CONFIG_VehicleRain
/*********************************************************************************************
** Name:	  MessageDebounce_VehicleRain(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_VehicleRain(void)
{
    static uint16_t VehicleRain_Real_Timer;
    static uint16_t VehicleRain_Timer;
    static uint8_t VehicleRain_Timer_Status;
    
    VehicleRain_LastStatus = VehicleRain_Status;
    
    if(TRUE == MessageRx_VehicleRain_Ind)
    {  
	MessageRx_VehicleRain_Ind = FALSE;
    
        #ifdef _CHERY_COM
	if(MessageRx_VehicleRain == TRUE)
	#endif
	#ifdef _VOYAH_COM
            #ifdef _VOYAH_COM_PD
        if(MessageRx_VehicleRain >= _RLS_RainfallLevel_Level3)
	    #endif
	#endif
	#ifdef _SGM_COM
        if((MessageRx_VehicleRain == TRUE))
	#endif
	#ifdef _CTCS_COM
        if(MessageRx_VehicleRain == TRUE)
	#endif
	#ifdef _DEARCC_COM
        if(MessageRx_VehicleRain == TRUE)
	#endif
	#ifdef _MAXUS_COM
        if(MessageRx_VehicleRain == TRUE)
	#endif
	#ifdef _DFMC_COM
        if(MessageRx_VehicleRain == TRUE)
	#endif
	#ifdef _BAIC_COM
        if(MessageRx_VehicleRain == TRUE)
	#endif
	#ifdef _DFLZM_COM
        if(MessageRx_VehicleRain == TRUE)
	#endif
	#ifdef _NIU_COM
        if(MessageRx_VehicleRain == TRUE)
	#endif
	#ifdef _CHANGAN_COM
        if(MessageRx_VehicleRain == TRUE)
	#endif
	{
	     VehicleRain_DataStream |= 0x0001;
        }
        if((MASK01BIT & VehicleRain_DataStream) == MASK01BIT)	 
        {    
             VehicleRain_Status = TRUE;
	     /*Timeout Monitor*/
	     VehicleRain_Timer = 0;
        }
        else if(((MASK01BIT & VehicleRain_DataStream) == 0) && (FALSE == VehicleRain_Timer_Status))
        {    
    	     VehicleRain_Status = FALSE;
        }       
    
        VehicleRain_DataStream <<=1;
         /*Real-time Monitor*/	
	VehicleRain_Real_Status = TRUE;
	VehicleRain_Real_Timer = K_VehicleRain_Real_Timeout;  
	
	/*E2E_Status Monitor*/
	if(TRUE == MessageRx_VehicleRain_E2E)
	{
	      VehicleRain_E2E_Status = TRUE;
	}
	else
	{
              VehicleRain_E2E_Status = FALSE;
	}
		
    }
         /*Real-time Monitor*/
    if(TRUE == VehicleRain_Real_Status)
    {
         if(VehicleRain_Real_Timer == 0)
         {
	      VehicleRain_Real_Status = FALSE; 
	      if(TRUE == K_VehicleRain_SingleEvent_Enable) /*10,1110 is MultiEvent, 1,111 is SingleEvent */
	      {
		   VehicleRain_SingleEvent_Enable = TRUE;
	      }
	      if(TRUE == VehicleRain_SingleEvent_Enable) 
	      {
		   VehicleRain_SingleEvent_Enable = FALSE;
		   VehicleRain_Status = FALSE;
	      }
         }
         else
         {
	      VehicleRain_Real_Timer --;
         }
    }
    
    /* VehicleRain RiseEdge and FallEdge Active monitor */  
    if((FALSE == VehicleRain_Status) && (TRUE == VehicleRain_LastStatus))
    {
    	 VehicleRain_RiseEdge_Active = TRUE;
    } 
    else
    {
    	 VehicleRain_RiseEdge_Active = FALSE;
    }
 
    if((TRUE == VehicleRain_Status) && (FALSE == VehicleRain_LastStatus))
    {
	 VehicleRain_FallEdge_Active = TRUE;

    }	 
    else
    {
	 VehicleRain_FallEdge_Active = FALSE;
    }	
    	
}
#endif
#ifdef _CONFIG_VehicleClean
/*********************************************************************************************
** Name:	  MessageDebounce_VehicleClean(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_VehicleClean(void)
{

}
#endif

#ifdef _CONFIG_BusIncline
#ifdef _CONFIG_InclineX_Direction
/*********************************************************************************************
** Name:	  MessageDebounce_BusInclineX(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_BusInclineX(void)
{
    static uint16_t BusInclineX_Real_Timer;

    if(TRUE == MessageRx_BusInclineX_Ind)
    {  
	MessageRx_BusInclineX_Ind = FALSE;
    
        #ifdef _CHERY_COM
        if(MessageRx_BusInclineX == TRUE)
        #endif
        #ifdef _SGMW_COM
        if(MessageRx_BusInclineX == TRUE)
        #endif
	#ifdef _SGM_COM
        if(MessageRx_BusInclineX == TRUE)
        #endif
        #ifdef _CTCS_COM
        if(MessageRx_BusInclineX == TRUE)
        #endif
        #ifdef _DEARCC_COM
        if(MessageRx_BusInclineX == TRUE)
        #endif
	#ifdef _XIAOPENG_COM
        if(MessageRx_BusInclineX TRUE)
        #endif
	#ifdef _MAXUS_COM
        if(((MessageRx_BusInclineX < K_N03_Incline) || (MessageRx_BusInclineX > K_03_Incline))
	   &&(MessageRx_BusInclineX_Valid == _Incline_Valid))
        #endif
	#ifdef _DFMC_COM
        if(((MessageRx_BusInclineX < K_N03_Incline) || (MessageRx_BusInclineX > K_03_Incline))
	   &&(MessageRx_BusInclineX_Valid == _Incline_Valid))
        #endif
	#ifdef _BAIC_COM
        if(((MessageRx_BusInclineX < K_N03_Incline) || (MessageRx_BusInclineX > K_03_Incline))
	   &&(MessageRx_BusInclineX_Valid == _Incline_Valid))
        #endif
	#ifdef _DFLZM_COM
        if(((MessageRx_BusInclineX < K_N03_Incline) || (MessageRx_BusInclineX > K_03_Incline))
	   &&(MessageRx_BusInclineX_Valid == _Incline_Valid))
        #endif
	#ifdef _NIU_COM
        if(MessageRx_BusInclineX == TRUE)
        #endif
	#ifdef _FAW_COM
        if(MessageRx_BusInclineX == TRUE)
        #endif
	#ifdef _CHANGAN_COM
        if(MessageRx_BusInclineX == TRUE)
        #endif
        {
	     BusInclineX_DataStream |= 0x0001;
        }
        if((MASK01BIT & BusInclineX_DataStream) == MASK01BIT)	 
        {    
             BusInclineX_Status = TRUE;
        }
        else if((MASK01BIT & BusInclineX_DataStream) == 0)
        {
    	     BusInclineX_Status = FALSE;
        }
    
        BusInclineX_DataStream <<=1;
         /*Real-time Monitor*/	
	BusInclineX_Real_Status = TRUE;
	BusInclineX_Real_Timer = K_BusInclineX_Real_Timeout;  
	
	/*E2E_Status Monitor*/
	if(TRUE == MessageRx_BusInclineX_E2E)
	{
	      BusInclineX_E2E_Status = TRUE;
	}
	else
	{
              BusInclineX_E2E_Status = FALSE;
	}
    }
        /*Real-time Monitor*/
    if(TRUE == BusInclineX_Real_Status)
    {
         if(BusInclineX_Real_Timer == 0)
         {
	      BusInclineX_Real_Status = FALSE; 
	      if(TRUE == K_BusInclineX_SingleEvent_Enable) /*10,1110 is MultiEvent, 1,111 is SingleEvent */
	      {
		   BusInclineX_SingleEvent_Enable = TRUE;
	      }
	      if(TRUE == BusInclineX_SingleEvent_Enable) 
	      {
		   BusInclineX_SingleEvent_Enable = FALSE;
		   BusInclineX_Status = FALSE;
	      }
         }
         else
         {
	      BusInclineX_Real_Timer --;
         }
    }
   
}
#endif
#ifdef _CONFIG_InclineY_Direction
/*********************************************************************************************
** Name:	  MessageDebounce_BusInclineY(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_BusInclineY(void)
{
    static uint16_t BusInclineY_Real_Timer;
 
    if(TRUE == MessageRx_BusInclineY_Ind)
    {  
	MessageRx_BusInclineY_Ind = FALSE;
    
        #ifdef _CHERY_COM
        if(MessageRx_BusInclineY == TRUE)
        #endif
        #ifdef _SGMW_COM
        if(MessageRx_BusInclineY == TRUE)
        #endif
	#ifdef _SGM_COM
        if(MessageRx_BusInclineY == TRUE)
        #endif
        #ifdef _CTCS_COM
        if(MessageRx_BusInclineY == TRUE)
        #endif
        #ifdef _DEARCC_COM
        if(MessageRx_BusInclineY == TRUE)
        #endif
	#ifdef _XIAOPENG_COM
        if(MessageRx_BusInclineX TRUE)
        #endif
	#ifdef _MAXUS_COM
        if(MessageRx_BusInclineY == TRUE)
        #endif
	#ifdef _DFMC_COM
        if(MessageRx_BusInclineY == TRUE)
        #endif
	#ifdef _BAIC_COM
        if(MessageRx_BusInclineY == TRUE)
        #endif
	#ifdef _DFLZM_COM
        if(MessageRx_BusInclineY == TRUE)
        #endif
	#ifdef _NIU_COM
        if(MessageRx_BusInclineY == TRUE)
        #endif
	#ifdef _FAW_COM
        if(MessageRx_BusInclineY == TRUE)
        #endif
	#ifdef _CHANGAN_COM
        if(MessageRx_BusInclineY == TRUE)
        #endif
        {
	     BusInclineY_DataStream |= 0x0001;
        }
        if((MASK01BIT & BusInclineY_DataStream) == MASK01BIT)	 
        {    
             BusInclineY_Status = TRUE;
        }
        else if((MASK01BIT & BusInclineY_DataStream) == 0)
        {
    	     BusInclineY_Status = FALSE;
        }
    
        BusInclineY_DataStream <<=1;
         /*Real-time Monitor*/	
	BusInclineY_Real_Status = TRUE;
	BusInclineY_Real_Timer = K_BusInclineY_Real_Timeout;  
	
	/*E2E_Status Monitor*/
	if(TRUE == MessageRx_BusInclineY_E2E)
	{
	      BusInclineY_E2E_Status = TRUE;
	}
	else
	{
              BusInclineY_E2E_Status = FALSE;
	}
    }
        /*Real-time Monitor*/
    if(TRUE == BusInclineY_Real_Status)
    {
         if(BusInclineY_Real_Timer == 0)
         {
	      BusInclineY_Real_Status = FALSE; 
	      if(TRUE == K_BusInclineY_SingleEvent_Enable) /*10,1110 is MultiEvent, 1,111 is SingleEvent */
	      {
		   BusInclineY_SingleEvent_Enable = TRUE;
	      }
	      if(TRUE == BusInclineY_SingleEvent_Enable) 
	      {
		   BusInclineY_SingleEvent_Enable = FALSE;
		   BusInclineY_Status = FALSE;
	      }
         }
         else
         {
	      BusInclineY_Real_Timer --;
         }
    }	
}
#endif
#ifdef _CONFIG_InclineZ_Direction
/*********************************************************************************************
** Name:	  MessageDebounce_BusInclineZ(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_BusInclineZ(void)
{
    static uint16_t BusInclineZ_Real_Timer;

    if(TRUE == MessageRx_BusInclineZ_Ind)
    {  
	MessageRx_BusInclineZ_Ind = FALSE;
    
        #ifdef _CHERY_COM
        if(MessageRx_BusInclineZ == TRUE)
        #endif
        #ifdef _SGMW_COM
        if(MessageRx_BusInclineZ == TRUE)
        #endif
	#ifdef _SGM_COM
        if(MessageRx_BusInclineZ == TRUE)
        #endif
        #ifdef _CTCS_COM
        if(MessageRx_BusInclineZ == TRUE)
        #endif
        #ifdef _DEARCC_COM
        if(MessageRx_BusInclineZ == TRUE)
        #endif
	#ifdef _XIAOPENG_COM
        if(MessageRx_BusInclineX TRUE)
        #endif
	#ifdef _MAXUS_COM
        if(MessageRx_BusInclineZ == TRUE)
        #endif
	#ifdef _DFMC_COM
        if(MessageRx_BusInclineZ == TRUE)
        #endif
	#ifdef _BAIC_COM
        if(MessageRx_BusInclineZ == TRUE)
        #endif
	#ifdef _DFLZM_COM
        if(MessageRx_BusInclineZ == TRUE)
        #endif
	#ifdef _NIU_COM
        if(MessageRx_BusInclineZ == TRUE)
        #endif
	#ifdef _FAW_COM
        if(MessageRx_BusInclineZ == TRUE)
        #endif
	#ifdef _CHANGAN_COM
        if(MessageRx_BusInclineZ == TRUE)
        #endif
        {
	     BusInclineZ_DataStream |= 0x0001;
        }
        if((MASK01BIT & BusInclineZ_DataStream) == MASK01BIT)	 
        {    
             BusInclineZ_Status = TRUE;
        }
        else if((MASK01BIT & BusInclineZ_DataStream) == 0)
        {
    	     BusInclineZ_Status = FALSE;
        }
    
        BusInclineZ_DataStream <<=1;
         /*Real-time Monitor*/	
	BusInclineZ_Real_Status = TRUE;
	BusInclineZ_Real_Timer = K_BusInclineZ_Real_Timeout;  
    }
        /*Real-time Monitor*/
    if(TRUE == BusInclineZ_Real_Status)
    {
         if(BusInclineZ_Real_Timer == 0)
         {
	      BusInclineZ_Real_Status = FALSE; 
	      if(TRUE == K_BusInclineZ_SingleEvent_Enable) /*10,1110 is MultiEvent, 1,111 is SingleEvent */
	      {
		   BusInclineZ_SingleEvent_Enable = TRUE;
	      }
	      if(TRUE == BusInclineZ_SingleEvent_Enable) 
	      {
		   BusInclineZ_SingleEvent_Enable = FALSE;
		   BusInclineZ_Status = FALSE;
	      }
         }
         else
         {
	      BusInclineZ_Real_Timer --;
         }
    }
}
#endif
#endif
#ifdef _CONFIG_SonicRadar
#ifdef _CONFIG_SonicRadar_Error
/*********************************************************************************************
** Name:	  MessageDebounce_SonicRadar_Error(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_SonicRadar_Error(void)
{
	
}
#endif
#ifdef _CONFIG_SonicRadar_Obstacle
/*********************************************************************************************
** Name:	  MessageDebounce_SonicRadar_Obstacle(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_SonicRadar_Obstacle(void)
{

}
#endif
#ifdef _CONFIG_SonicRadar_Angle
/*********************************************************************************************
** Name:	  MessageDebounce_SonicRadar_Angle(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_SonicRadar_Angle(void)
{

}
#endif

#ifdef _CONFIG_SonicRadar1_Distance
/*********************************************************************************************
** Name:	  MessageDebounce_SonicRadar1_Distance(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_SonicRadar1_Distance(void)
{

}
#endif
#ifdef _CONFIG_SonicRadar2_Distance
/*********************************************************************************************
** Name:	  MessageDebounce_SonicRadar2_Distance(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_SonicRadar2_Distance(void)
{

}
#endif
#ifdef _CONFIG_SonicRadar3_Distance
/*********************************************************************************************
** Name:	  MessageDebounce_SonicRadar3_Distance(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_SonicRadar3_Distance(void)
{

}
#endif
#endif


#ifdef _CONFIG_MmwRadar
#ifdef _CONFIG_MmwRadar_Error
/*********************************************************************************************
** Name:	  MessageDebounce_MmwRadar_Error(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_MmwRadar_Error(void)
{

}
#endif
#ifdef _CONFIG_MmwRadar_Obstacle
/*********************************************************************************************
** Name:	  MessageDebounce_MmwRadar_Obstacle(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_MmwRadar_Obstacle(void)
{
 
}
#endif
#ifdef _CONFIG_MmwRadar_Angle
/*********************************************************************************************
** Name:	  MessageDebounce_MmwRadar_Angle(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_MmwRadar_Angle(void)
{

}
#endif

#ifdef _CONFIG_MmwRadarX_Distance
/*********************************************************************************************
** Name:	  MessageDebounce_MmwRadarX_Distance(void);
** Function:
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_MmwRadarX_Distance(void)
{

}
#endif
#ifdef _CONFIG_MmwRadarY_Distance
/*********************************************************************************************
** Name:	  MessageDebounce_MmwRadarY_Distance(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_MmwRadarY_Distance(void)
{

}
#endif
#ifdef _CONFIG_MmwRadarZ_Distance
/*********************************************************************************************
** Name:	  MessageDebounce_MmwRadarZ_Distance(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_MmwRadarZ_Distance(void)
{
  
}
#endif
#ifdef _CONFIG_MmwRadarD_Distance
/*********************************************************************************************
** Name:	  MessageDebounce_MmwRadarD_Distance(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_MmwRadarD_Distance(void)
{
    static uint16_t MmwRadarD_Distance_Real_Timer;
  
    if(TRUE == MessageRx_MmwRadarD_Distance_Ind)
    {  
	MessageRx_MmwRadarD_Distance_Ind = FALSE;

         /*Real-time Monitor*/	
	MmwRadarD_Distance_Real_Status = TRUE;
	MmwRadarD_Distance_Real_Timer = K_MmwRadarD_Distance_Real_Timeout;  
    }
        /*Real-time Monitor*/
    if(TRUE == MmwRadarD_Distance_Real_Status)
    {
         if(MmwRadarD_Distance_Real_Timer == 0)
         {
	      MmwRadarD_Distance_Real_Status = FALSE; 
         }
         else
         {
	      MmwRadarD_Distance_Real_Timer --;
         }
    }	
}
#endif
#endif

#ifdef _CONFIG_AdasRadar
#ifdef _CONFIG_AdasRadar_RearCorner_Error
/*********************************************************************************************
** Name:	  MessageDebounce_AdasRadar_RearCorner_Error(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_AdasRadar_RearCorner_Error(void)
{

}
#endif
#ifdef _CONFIG_AdasRadar_RearCorner_Obstacle
/*********************************************************************************************
** Name:	  MessageDebounce_AdasRadar_RearCorner_Obstacle(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_AdasRadar_RearCorner_Obstacle(void)
{

}
#endif
#ifdef _CONFIG_AdasRadar_RearCorner_Angle
/*********************************************************************************************
** Name:	  MessageDebounce_AdasRadar_RearCorner_Angle(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_AdasRadar_RearCorner_Angle(void)
{
    static uint16_t AdasRadar_RearCorner_Angle_Real_Timer;
 
    if(TRUE == MessageRx_AdasRadar_RearCorner_Angle_Ind)
    {  
	MessageRx_AdasRadar_RearCorner_Angle_Ind = FALSE;

         /*Real-time Monitor*/	
	AdasRadar_RearCorner_Angle_Real_Status = TRUE;
	AdasRadar_RearCorner_Angle_Real_Timer = K_AdasRadar_RearCorner_Angle_Real_Timeout;  
    }
        /*Real-time Monitor*/
    if(TRUE == AdasRadar_RearCorner_Angle_Real_Status)
    {
         if(AdasRadar_RearCorner_Angle_Real_Timer == 0)
         {
	      AdasRadar_RearCorner_Angle_Real_Status = FALSE; 
         }
         else
         {
	      AdasRadar_RearCorner_Angle_Real_Timer --;
         }
    }	
}
#endif
#ifdef _CONFIG_AdasRadar_RearCorner_Enable
/*********************************************************************************************
** Name:	  MessageDebounce_AdasRadar_RearCorner_Enable(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_AdasRadar_RearCorner_Enable(void)
{
 
}
#endif


#ifdef _CONFIG_AdasRadar_RearCornerX_Distance
/*********************************************************************************************
** Name:	  MessageDebounce_AdasRadar_RearCornerX_Distance(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_AdasRadar_RearCornerX_Distance(void)
{

}
#endif
#ifdef _CONFIG_AdasRadar_RearCornerY_Distance
/*********************************************************************************************
** Name:	  MessageDebounce_AdasRadar_RearCornerY_Distance(void);
** Function:
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_AdasRadar_RearCornerY_Distance(void)
{

}
#endif
#ifdef _CONFIG_AdasRadar_RearCornerZ_Distance
/*********************************************************************************************
** Name:	  MessageDebounce_AdasRadar_RearCornerZ_Distance(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_AdasRadar_RearCornerZ_Distance(void)
{

}
#endif
#endif












#ifdef _CONFIG_VehicleSpeed
/*********************************************************************************************
** Name:	  MessageDebounce_VehicleSpeed(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_VehicleSpeed(void)
{

}
#endif
#ifdef _CONFIG_VehiclePowerMode
/*********************************************************************************************
** Name:	  MessageDebounce_VehiclePowerMode(void);
** Function:
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_VehiclePowerMode(void)
{

}
#endif

#ifdef _CONFIG_VehicleGearLever
/*********************************************************************************************
** Name:	  MessageDebounce_VehicleGearLever(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_VehicleGearLever(void)
{

}
#endif

#ifdef _CONFIG_VehicleHandBrake
/*********************************************************************************************
** Name:	  MessageDebounce_VehicleHandBrake(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_VehicleHandBrake(void)
{
    static uint16_t VehicleHandBrake_Real_Timer;
     	
    VehicleHandBrake_LastStatus = VehicleHandBrake_Status;
    
    if(TRUE == MessageRx_VehicleHandBrake_Ind)
    {  
	MessageRx_VehicleHandBrake_Ind = FALSE;
   
        #ifdef _CHERY_COM
        if(MessageRx_VehicleHandBrake == _HandBrakeSystemSts_Applied)
        #endif   
        #ifdef _SGMW_COM
        if(MessageRx_VehicleHandBrake == TRUE)
        #endif
	#ifdef _SGM_COM
        if(MessageRx_VehicleHandBrake == TRUE)
        #endif
        #ifdef _CTCS_COM
	if(MessageRx_VehicleHandBrake == TRUE)
        #endif
        #ifdef _DEARCC_COM
        if(MessageRx_VehicleHandBrake == TRUE)
        #endif
	#ifdef _XIAOPENG_COM
        if(MessageRx_VehicleHandBrake == TRUE)
        #endif
	#ifdef _MAXUS_COM
	    #ifdef _MAXUS_COM_PSD
	if(MessageRx_VehicleHandBrake == _EPBAppcnSts_Closed)
	    #endif
        #endif
	#ifdef _DFMC_COM
        if(MessageRx_VehicleHandBrake == TRUE)
        #endif
	#ifdef _BAIC_COM
	    #ifdef _BAIC_COM_C46DB
	if(MessageRx_VehicleHandBrake == _ETRS_PBtnSts_Pressed)
	    #endif
        #endif
	#ifdef _DFLZM_COM
        if(MessageRx_VehicleHandBrake == TRUE)
        #endif
	#ifdef _FAW_COM
        if(MessageRx_VehicleHandBrake == TRUE)
        #endif
	#ifdef _NIU_COM
        if(MessageRx_VehicleHandBrake == TRUE)
        #endif
	#ifdef _CHANGAN_COM
        if(MessageRx_VehicleHandBrake == TRUE)
        #endif
        {
	     VehicleHandBrake_DataStream |= 0x0001;
        }
        if((MASK01BIT & VehicleHandBrake_DataStream) == MASK01BIT)	 
        {    
             VehicleHandBrake_Status = TRUE;
        }
        else if((MASK01BIT & VehicleHandBrake_DataStream) == 0)
        {
    	     VehicleHandBrake_Status = FALSE;
        }
    
        VehicleHandBrake_DataStream <<=1;
         /*Real-time Monitor*/	
	VehicleHandBrake_Real_Status = TRUE;
	VehicleHandBrake_Real_Timer = K_VehicleHandBrake_Real_Timeout;  
	
    }
        /*Real-time Monitor*/
    if(TRUE == VehicleHandBrake_Real_Status)
    {
         if(VehicleHandBrake_Real_Timer == 0)
         {
	      VehicleHandBrake_Real_Status = FALSE;   
         }
         else
         {
	      VehicleHandBrake_Real_Timer --;
         }
    }
    
     /* VehicleHandBrake RiseEdge and FallEdge Active monitor */  
    if((FALSE == VehicleHandBrake_Status) && (TRUE == VehicleHandBrake_LastStatus))
    {
    	 VehicleHandBrake_RiseEdge_Active = TRUE;
    } 
    else
    {
    	 VehicleHandBrake_RiseEdge_Active = FALSE;
    }
 
    if((TRUE == VehicleHandBrake_Status) && (FALSE == VehicleHandBrake_LastStatus))
    {
	 VehicleHandBrake_FallEdge_Active = TRUE;

    }	 
    else
    {
	 VehicleHandBrake_FallEdge_Active = FALSE;
    }	
}
#endif

#ifdef _CONFIG_VehicleMode
/*********************************************************************************************
** Name:	  MessageDebounce_VehicleMode(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_VehicleMode(void)
{

}
#endif

#ifdef _CONFIG_VehicleRemoteMode
/*********************************************************************************************
** Name:	  MessageDebounce_VehicleRemoteMode(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_VehicleRemoteMode(void)
{
    static uint16_t VehicleRemoteMode_Real_Timer;
     	
    VehicleRemoteMode_LastStatus = VehicleRemoteMode_Status;
    
    if(TRUE == MessageRx_VehicleRemoteMode_Ind)
    {  
	MessageRx_VehicleRemoteMode_Ind = FALSE;
   
        #ifdef _CHERY_COM
        if(MessageRx_VehicleRemoteMode == _RVSMode_Active)
        #endif   
        #ifdef _SGMW_COM
        if(MessageRx_VehicleRemoteMode == TRUE)
        #endif
	#ifdef _SGM_COM
        if(MessageRx_VehicleRemoteMode == TRUE)
        #endif
        #ifdef _CTCS_COM
	if(MessageRx_VehicleRemoteMode == TRUE)
        #endif
        #ifdef _DEARCC_COM
        if(MessageRx_VehicleRemoteMode == TRUE)
        #endif
	#ifdef _XIAOPENG_COM
        if(MessageRx_VehicleRemoteMode == TRUE)
        #endif
	#ifdef _MAXUS_COM
	if(MessageRx_VehicleRemoteMode == TRUE)
        #endif
	#ifdef _DFMC_COM
        if(MessageRx_VehicleRemoteMode == TRUE)
        #endif
	#ifdef _BAIC_COM
	if(MessageRx_VehicleRemoteMode == TRUE)
        #endif
	#ifdef _DFLZM_COM
	if(MessageRx_VehicleRemoteMode == TRUE)
        #endif
	#ifdef _FAW_COM
        if(MessageRx_VehicleRemoteMode == TRUE)
        #endif
	#ifdef _NIU_COM
        if(MessageRx_VehicleRemoteMode == TRUE)
        #endif
	#ifdef _CHANGAN_COM
        if(MessageRx_VehicleRemoteMode == TRUE)
        #endif
        {
	     VehicleRemoteMode_DataStream |= 0x0001;
        }
        if((MASK01BIT & VehicleRemoteMode_DataStream) == MASK01BIT)	 
        {    
             VehicleRemoteMode_Status = TRUE;
        }
        else if((MASK01BIT & VehicleRemoteMode_DataStream) == 0)
        {
    	     VehicleRemoteMode_Status = FALSE;
        }
    
        VehicleRemoteMode_DataStream <<=1;
         /*Real-time Monitor*/	
	VehicleRemoteMode_Real_Status = TRUE;
	VehicleRemoteMode_Real_Timer = K_VehicleRemoteMode_Real_Timeout;  
	
    }
        /*Real-time Monitor*/
    if(TRUE == VehicleRemoteMode_Real_Status)
    {
         if(VehicleRemoteMode_Real_Timer == 0)
         {
	      VehicleRemoteMode_Real_Status = FALSE;   
         }
         else
         {
	      VehicleRemoteMode_Real_Timer --;
         }
    }
    
     /* VehicleRemoteMode RiseEdge and FallEdge Active monitor */  
    if((FALSE == VehicleRemoteMode_Status) && (TRUE == VehicleRemoteMode_LastStatus))
    {
    	 VehicleRemoteMode_RiseEdge_Active = TRUE;
    } 
    else
    {
    	 VehicleRemoteMode_RiseEdge_Active = FALSE;
    }
 
    if((TRUE == VehicleRemoteMode_Status) && (FALSE == VehicleRemoteMode_LastStatus))
    {
	 VehicleRemoteMode_FallEdge_Active = TRUE;

    }	 
    else
    {
	 VehicleRemoteMode_FallEdge_Active = FALSE;
    }	
}
#endif


#ifdef _CONFIG_LatchReleaseState
/*********************************************************************************************
** Name:	  MessageDebounce_LatchReleaseState(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_LatchReleaseState(void)
{
 
}
#endif



#ifdef _CONFIG_CommandDelay_Cancel_ByFobLock
/*********************************************************************************************
** Name:	  MessageDebounce_FobLock(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_FobLock(void)
{
    static uint16_t FobLock_Real_Timer;
    
    FobLock_LastStatus = FobLock_Status;
    
    if(TRUE == MessageRx_FobLock_Ind)
    {  
	MessageRx_FobLock_Ind = FALSE;
    
        #ifdef _CHERY_COM
        if(MessageRx_FobLock == _OrderInformation_Lock)
        #endif
        #ifdef _SGMW_COM
        if(MessageRx_FobLock == TRUE)
        #endif
	#ifdef _SGM_COM
        if(MessageRx_FobLock == TRUE)
        #endif
        #ifdef _CTCS_COM
        if(MessageRx_FobLock == TRUE)
        #endif
        #ifdef _DEARCC_COM
        if(MessageRx_FobLock == TRUE)
        #endif
	#ifdef _XIAOPENG_COM
        if(MessageRx_FobLock == TRUE)
        #endif
	#ifdef _MAXUS_COM
        if(MessageRx_FobLock == TRUE)
        #endif
	#ifdef _DFMC_COM
        if(MessageRx_FobLock == TRUE)
        #endif
	#ifdef _BAIC_COM
        if(MessageRx_FobLock == TRUE)
        #endif
	#ifdef _DFLZM_COM
        if(MessageRx_FobLock == TRUE)
        #endif
	#ifdef _NIU_COM
        if(MessageRx_FobLock == TRUE)
        #endif
	#ifdef _FAW_COM
        if(MessageRx_FobLock == TRUE)
        #endif
	#ifdef _CHANGAN_COM
        if(MessageRx_FobLock == _DRIVER_DOOR_LOCK)
        #endif
        {
	     FobLock_DataStream |= 0x0001;
        }
        if((MASK01BIT & FobLock_DataStream) == MASK01BIT)	 
        {    
             FobLock_Status = TRUE;
        }
        else if((MASK01BIT & FobLock_DataStream) == 0)
        {
    	     FobLock_Status = FALSE;
        }
    
        FobLock_DataStream <<=1;
         /*Real-time Monitor*/	
	FobLock_Real_Status = TRUE;
	FobLock_Real_Timer = K_FobLock_Real_Timeout;  
    }
        /*Real-time Monitor*/
    if(TRUE == FobLock_Real_Status)
    {
         if(FobLock_Real_Timer == 0)
         {
	      FobLock_Real_Status = FALSE;   
         }
         else
         {
	      FobLock_Real_Timer --;
         }
    }
         /* FobLock RiseEdge and FallEdge Active monitor */  
    if((FALSE == FobLock_Status) && (TRUE == FobLock_LastStatus))
    {
    	 FobLock_RiseEdge_Active = TRUE;
    } 
    else
    {
    	 FobLock_RiseEdge_Active = FALSE;
    }
 
    if((TRUE == FobLock_Status) && (FALSE == FobLock_LastStatus))
    {
	 FobLock_FallEdge_Active = TRUE;

    }	 
    else
    {
	 FobLock_FallEdge_Active = FALSE;
    }	
}
#endif

#ifdef _CONFIG_VehicleChildLock
/*********************************************************************************************
** Name:	  MessageDebounce_VehicleChildLock(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_VehicleChildLock(void)
{

}
#endif

#ifdef _CONFIG_VehicleLock
/*********************************************************************************************
** Name:	  MessageDebounce_VehicleLock(void);
** Function:
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_VehicleLock(void)
{
 
}
#endif

#ifdef _CONFIG_VehicleAntiTheft
/*********************************************************************************************
** Name:	  MessageDebounce_VehicleAntiTheft(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_VehicleAntiTheft(void)
{  

}
#endif


#ifdef _CONFIG_VehicleDriveMode
/*********************************************************************************************
** Name:	  MessageDebounce_VehicleDriveMode(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_VehicleDriveMode(void)
{  
    static uint16_t VehicleDriveMode_Real_Timer;
    
    if(TRUE == MessageRx_VehicleDriveMode_Ind)
    {  
	MessageRx_VehicleDriveMode_Ind = FALSE;
        #ifdef _CHERY_COM
        if(MessageRx_VehicleDriveMode == TRUE)
        #endif
        #ifdef _SGMW_COM
        if(MessageRx_VehicleDriveMode == TRUE)
        #endif
	#ifdef _SGM_COM
        if(MessageRx_VehicleDriveMode == TRUE)
        #endif
        #ifdef _CTCS_COM
        if(MessageRx_VehicleDriveMode == TRUE)
        #endif
        #ifdef _DEARCC_COM
        if(MessageRx_VehicleDriveMode == TRUE)
        #endif
	#ifdef _XIAOPENG_COM
        if((MessageRx_VehicleDriveMode == _iBCM_CurMode_auto_drive_mode_enter_success) || (MessageRx_VehicleDriveMode == _iBCM_CurMode_auto_drive_mode_enter_fail))
        #endif
	#ifdef _MAXUS_COM
        if(MessageRx_VehicleDriveMode == TRUE)
        #endif
	#ifdef _DFMC_COM
        if(MessageRx_VehicleDriveMode == TRUE)
        #endif
	#ifdef _BAIC_COM
        if(MessageRx_VehicleDriveMode == _PDCM_DriveReady_Fault)
        #endif
	#ifdef _DFLZM_COM
        if(MessageRx_VehicleDriveMode == TRUE)
        #endif
	#ifdef _NIU_COM
        if(MessageRx_VehicleDriveMode == TRUE)
        #endif
	#ifdef _FAW_COM
        if(MessageRx_VehicleDriveMode == TRUE)
        #endif
	#ifdef _CHANGAN_COM
        if(MessageRx_VehicleDriveMode == TRUE)
        #endif
        {
	     VehicleDriveMode_DataStream |= 0x0001;
        }
        if((MASK01BIT & VehicleDriveMode_DataStream) == MASK01BIT)	 
        {    
             VehicleDriveMode_Status = TRUE;
        }
        else if((MASK01BIT & VehicleDriveMode_DataStream) == 0)
        {
    	     VehicleDriveMode_Status = FALSE;
        }
    
        VehicleDriveMode_DataStream <<=1;
         /*Real-time Monitor*/	
	VehicleDriveMode_Real_Status = TRUE;
	VehicleDriveMode_Real_Timer = K_VehicleDriveMode_Real_Timeout;  
    }
    /*Real-time Monitor*/
    if(TRUE == VehicleDriveMode_Real_Status)
    {
         if(VehicleDriveMode_Real_Timer == 0)
         {
	      VehicleDriveMode_Real_Status = FALSE;   
         }
         else
         {
	      VehicleDriveMode_Real_Timer --;
         }
    }
    
     /* VehicleDriveMode RiseEdge and FallEdge Active monitor */  
    if((FALSE == VehicleDriveMode_Status) && (TRUE == VehicleDriveMode_LastStatus))
    {
    	 VehicleDriveMode_RiseEdge_Active = TRUE;
    } 
    else
    {
    	 VehicleDriveMode_RiseEdge_Active = FALSE;
    }
 
    if((TRUE == VehicleDriveMode_Status) && (FALSE == VehicleDriveMode_LastStatus))
    {
	 VehicleDriveMode_FallEdge_Active = TRUE;

    }	 
    else
    {
	 VehicleDriveMode_FallEdge_Active = FALSE;
    }
}
#endif

#ifdef _CONFIG_KeyOpenMode
/*********************************************************************************************
** Name:	  MessageDebounce_KeyOpenMode(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_KeyOpenMode(void)
{  
    static uint16_t KeyOpenMode_Real_Timer;
    
    if(TRUE == MessageRx_KeyOpenMode_Ind)
    {  
	MessageRx_KeyOpenMode_Ind = FALSE;
        #ifdef _CHERY_COM
        if(MessageRx_KeyOpenMode == TRUE)
        #endif
        #ifdef _SGMW_COM
        if(MessageRx_KeyOpenMode == TRUE)
        #endif
	#ifdef _SGM_COM
        if(MessageRx_KeyOpenMode == TRUE)
        #endif
        #ifdef _CTCS_COM
        if(MessageRx_KeyOpenMode == TRUE)
        #endif
        #ifdef _DEARCC_COM
        if(MessageRx_KeyOpenMode == TRUE)
        #endif
	#ifdef _XIAOPENG_COM
	if(MessageRx_KeyOpenMode == _KeyModeCtrlCfg_Driver_Door)
	{
	      Vehicle_KeyOpenMode = _KeyModeCtrlCfgFB_Driver_Door;
	}
	else if(MessageRx_KeyOpenMode == _KeyModeCtrlCfg_Front_Door)
	{
	      Vehicle_KeyOpenMode = _KeyModeCtrlCfgFB_Front_Door;
	}
        if((MessageRx_KeyOpenMode == _KeyModeCtrlCfg_Driver_Door) || (MessageRx_KeyOpenMode == _KeyModeCtrlCfg_Front_Door))
        #endif
	#ifdef _MAXUS_COM
        if(MessageRx_KeyOpenMode == TRUE)
        #endif
	#ifdef _DFMC_COM
        if(MessageRx_KeyOpenMode == TRUE)
        #endif
	#ifdef _BAIC_COM
        if(MessageRx_KeyOpenMode == TRUE)
        #endif
	#ifdef _DFLZM_COM
        if(MessageRx_KeyOpenMode == TRUE)
        #endif
	#ifdef _NIU_COM
        if(MessageRx_KeyOpenMode == TRUE)
        #endif
	#ifdef _FAW_COM
        if(MessageRx_KeyOpenMode == TRUE)
        #endif
	#ifdef _CHANGAN_COM
        if(MessageRx_KeyOpenMode == TRUE)
        #endif
        {
	     KeyOpenMode_DataStream |= 0x0001;
        }
        if((MASK01BIT & KeyOpenMode_DataStream) == MASK01BIT)	 
        {    
             KeyOpenMode_Status = TRUE;
        }
        else if((MASK01BIT & KeyOpenMode_DataStream) == 0)
        {
    	     KeyOpenMode_Status = FALSE;
        }
    
        KeyOpenMode_DataStream <<=1;
         /*Real-time Monitor*/	
	KeyOpenMode_Real_Status = TRUE;
	KeyOpenMode_Real_Timer = K_KeyOpenMode_Real_Timeout;  
    }
    /*Real-time Monitor*/
    if(TRUE == KeyOpenMode_Real_Status)
    {
         if(KeyOpenMode_Real_Timer == 0)
         {
	      KeyOpenMode_Real_Status = FALSE;   
         }
         else
         {
	      KeyOpenMode_Real_Timer --;
         }
    }
    
     /* KeyOpenMode RiseEdge and FallEdge Active monitor */  
    if((FALSE == KeyOpenMode_Status) && (TRUE == KeyOpenMode_LastStatus))
    {
    	 KeyOpenMode_RiseEdge_Active = TRUE;
    } 
    else
    {
    	 KeyOpenMode_RiseEdge_Active = FALSE;
    }
 
    if((TRUE == KeyOpenMode_Status) && (FALSE == KeyOpenMode_LastStatus))
    {
	 KeyOpenMode_FallEdge_Active = TRUE;

    }	 
    else
    {
	 KeyOpenMode_FallEdge_Active = FALSE;
    }
}
#endif
#ifdef _CONFIG_KeyCloseMode
/*********************************************************************************************
** Name:	  MessageDebounce_KeyCloseMode(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_KeyCloseMode(void)
{  
    static uint16_t KeyCloseMode_Real_Timer;
    
    if(TRUE == MessageRx_KeyCloseMode_Ind)
    {  
	MessageRx_KeyCloseMode_Ind = FALSE;
        #ifdef _CHERY_COM
        if(MessageRx_KeyCloseMode == TRUE)
        #endif
        #ifdef _SGMW_COM
        if(MessageRx_KeyCloseMode == TRUE)
        #endif
	#ifdef _SGM_COM
        if(MessageRx_KeyCloseMode == TRUE)
        #endif
        #ifdef _CTCS_COM
        if(MessageRx_KeyCloseMode == TRUE)
        #endif
        #ifdef _DEARCC_COM
        if(MessageRx_KeyCloseMode == TRUE)
        #endif
	#ifdef _XIAOPENG_COM
        if(MessageRx_KeyCloseMode == _KeyModeCtrlCfg_Driver_Door)
	{
	      Vehicle_KeyCloseMode = _KeyModeCtrlCfgFB_Driver_Door;
	}
	else if(MessageRx_KeyCloseMode == _KeyModeCtrlCfg_Front_Door)
	{
	      Vehicle_KeyCloseMode = _KeyModeCtrlCfgFB_Front_Door;
	}
        if((MessageRx_KeyCloseMode == _KeyModeCtrlCfg_Driver_Door) || (MessageRx_KeyCloseMode == _KeyModeCtrlCfg_Front_Door))
        #endif
	#ifdef _MAXUS_COM
        if(MessageRx_KeyCloseMode == TRUE)
        #endif
	#ifdef _DFMC_COM
        if(MessageRx_KeyCloseMode == TRUE)
        #endif
	#ifdef _BAIC_COM
        if(MessageRx_KeyCloseMode == TRUE)
        #endif
	#ifdef _DFLZM_COM
        if(MessageRx_KeyCloseMode == TRUE)
        #endif
	#ifdef _NIU_COM
        if(MessageRx_KeyCloseMode == TRUE)
        #endif
	#ifdef _FAW_COM
        if(MessageRx_KeyCloseMode == TRUE)
        #endif
	#ifdef _CHANGAN_COM
        if(MessageRx_KeyCloseMode == TRUE)
        #endif
        {
	     KeyCloseMode_DataStream |= 0x0001;
        }
        if((MASK01BIT & KeyCloseMode_DataStream) == MASK01BIT)	 
        {    
             KeyCloseMode_Status = TRUE;
        }
        else if((MASK01BIT & KeyCloseMode_DataStream) == 0)
        {
    	     KeyCloseMode_Status = FALSE;
        }
    
        KeyCloseMode_DataStream <<=1;
         /*Real-time Monitor*/	
	KeyCloseMode_Real_Status = TRUE;
	KeyCloseMode_Real_Timer = K_KeyCloseMode_Real_Timeout;  
    }
    /*Real-time Monitor*/
    if(TRUE == KeyCloseMode_Real_Status)
    {
         if(KeyCloseMode_Real_Timer == 0)
         {
	      KeyCloseMode_Real_Status = FALSE;   
         }
         else
         {
	      KeyCloseMode_Real_Timer --;
         }
    }
    
     /* KeyCloseMode RiseEdge and FallEdge Active monitor */  
    if((FALSE == KeyCloseMode_Status) && (TRUE == KeyCloseMode_LastStatus))
    {
    	 KeyCloseMode_RiseEdge_Active = TRUE;
    } 
    else
    {
    	 KeyCloseMode_RiseEdge_Active = FALSE;
    }
 
    if((TRUE == KeyCloseMode_Status) && (FALSE == KeyCloseMode_LastStatus))
    {
	 KeyCloseMode_FallEdge_Active = TRUE;

    }	 
    else
    {
	 KeyCloseMode_FallEdge_Active = FALSE;
    }
}
#endif

#ifdef _CONFIG_RestoreRequest
/*********************************************************************************************
** Name:	  MessageDebounce_RestoreRequest(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_RestoreRequest(void)
{
    static uint16_t RestoreRequest_Real_Timer;
  
    /* RestoreRequest Status Active monitor */ 
    RestoreRequest_LastStatus = RestoreRequest_Status;
    
    if(TRUE == MessageRx_RestoreRequest_Ind)
    {  
	MessageRx_RestoreRequest_Ind = FALSE;
        
        #ifdef _SGMW_COM
        if((MessageRx_RestoreRequest == TRUE) && (MessageRx_RestoreRequestStatus == TRUE)) /* TRUE or Active, based on Message define */
        #endif
	#ifdef _SGM_COM
        if((MessageRx_RestoreRequest == TRUE) && (MessageRx_RestoreRequestStatus == TRUE)) /* TRUE or Active, based on Message define */
        #endif
        #ifdef _CHERY_COM
        if(MessageRx_RestoreRequest == TRUE) /* TRUE or Active, based on Message define*/
        #endif
        #ifdef _CTCS_COM
        if((MessageRx_RestoreRequest == _SET_VEHICLE_TO_DEFAULT) || (MessageRx_RestoreRequest == _SET_ALL_TO_DEFAULT)) /* TRUE or Active, based on Message define*/
        #endif
        #ifdef _DEARCC_COM
        if(MessageRx_RestoreRequest == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _XIAOPENG_COM
        if(MessageRx_RestoreRequest == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _MAXUS_COM
        if(MessageRx_RestoreRequest == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _DFMC_COM
        if(MessageRx_RestoreRequest == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _BAIC_COM
        if(MessageRx_RestoreRequest == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _DFLZM_COM
        if(MessageRx_RestoreRequest == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _NIU_COM
        if(MessageRx_RestoreRequest == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _FAW_COM
        if(MessageRx_RestoreRequest == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _CHANGAN_COM
        if(MessageRx_RestoreRequest == TRUE) /* TRUE or Active, based on Message define*/
        #endif
        {
	     RestoreRequest_DataStream |= 0x0001;
        }
        if((MASK01BIT & RestoreRequest_DataStream) == MASK01BIT)	 
        {    
             RestoreRequest_Status = TRUE;
        }
        else if((MASK01BIT & RestoreRequest_DataStream) == 0)
        {
    	     RestoreRequest_Status = FALSE;
        }
    
        RestoreRequest_DataStream <<=1;
    	RestoreRequest_Real_Status = TRUE;
	RestoreRequest_Real_Timer = K_RestoreRequest_Real_Timeout;  
    }
    /*Real-time Monitor*/
    if(TRUE == RestoreRequest_Real_Status)
    {
         if(RestoreRequest_Real_Timer == 0)
         {
	      RestoreRequest_Real_Status = FALSE; 
	      if(TRUE == K_RestoreRequest_SingleEvent_Enable) /*10,1110 is MultiEvent, 1,111 is SingleEvent */
	      {
		   RestoreRequest_SingleEvent_Enable = TRUE;
	      }
	      if(TRUE == RestoreRequest_SingleEvent_Enable) 
	      {
		   RestoreRequest_SingleEvent_Enable = FALSE;
		   RestoreRequest_Status = FALSE;
	      }
         }
         else
         {
	      RestoreRequest_Real_Timer --;
         }
    } 
  
    /* RestoreRequest RiseEdge and FallEdge Active monitor */  
    if((FALSE == RestoreRequest_Status) && (TRUE == RestoreRequest_LastStatus))
    {
    	 RestoreRequest_RiseEdge_Active = TRUE;
    } 
    else
    {
    	 RestoreRequest_RiseEdge_Active = FALSE;
    }
 
    if((TRUE == RestoreRequest_Status) && (FALSE == RestoreRequest_LastStatus))
    {
	 RestoreRequest_FallEdge_Active = TRUE;

    }	 
    else
    {
	 RestoreRequest_FallEdge_Active = FALSE;
    }
}
#endif
#ifdef _CONFIG_AppAuthorize
/*********************************************************************************************
** Name:	  MessageDebounce_AppAuthorize(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_AppAuthorize(void)
{
    static uint16_t AppAuthorize_Real_Timer;
    static uint16_t AppAuthorize_Timer;
    static uint8_t AppAuthorize_Timer_Status;
    static uint16_t AppAuthorize_Complete_Timer;
    static uint8_t AppAuthorize_Complete_Timer_Status;
    
    AppAuthorize_LastStatus = AppAuthorize_Status;
    
    if(TRUE == MessageRx_AppAuthorize_Ind)
    {  
	MessageRx_AppAuthorize_Ind = FALSE;
    
        #ifdef _CHERY_COM
        if(MessageRx_AppAuthorize == TRUE)
	#endif
	#ifdef _SGMW_COM
        if((MessageRx_AppAuthorize == TRUE) && (MessageRx_AppAuthorize_Valid == _AUTHORIZE_VALID))
	#endif
	#ifdef _SGM_COM
        if((MessageRx_AppAuthorize == TRUE) && (MessageRx_AppAuthorize_Valid == _AUTHORIZE_VALID))
	#endif
	#ifdef _CTCS_COM
        if(MessageRx_AppAuthorize == TRUE)
	#endif
	#ifdef _DEARCC_COM
	if(MessageRx_AppAuthorize == _TBOX_PLG_LOCK)
	{
             AppAuthorize_Status = FALSE;
	}
        else if(MessageRx_AppAuthorize == _TBOX_PLG_UNLOCK)
	#endif
	#ifdef _MAXUS_COM
        if(MessageRx_AppAuthorize == _TlgtCtrlReq_Open)
	#endif
	#ifdef _DFMC_COM
        if(MessageRx_AppAuthorize == _bcm_tbox_response_Anti_theft_authentication_success)//_bcm_remoteMode_REMOTE)
	#endif
	#ifdef _BAIC_COM
        if(MessageRx_AppAuthorize == _RemAuthentRes_IAnthentication_success)       
	#endif
	#ifdef _DFLZM_COM
        if(MessageRx_AppAuthorize == TRUE)
	#endif
	#ifdef _NIU_COM
        if(MessageRx_AppAuthorize == TRUE)
	#endif
	#ifdef _CHANGAN_COM
        if(MessageRx_AppAuthorize == TRUE)
	#endif
	{
	     AppAuthorize_DataStream |= 0x0001;
        }
        if((MASK01BIT & AppAuthorize_DataStream) == MASK01BIT)	 
        {    
             AppAuthorize_Status = TRUE;
	     /*Timeout Monitor*/
	     AppAuthorize_Timer = 0;
	     AppAuthorize_Timer_Status = TRUE;
        } 
	else if(((MASK01BIT & AppAuthorize_DataStream) == 0)
	        #ifdef _CONFIG_AppAuthorize_Clear_Timeout
	        && (FALSE == AppAuthorize_Timer_Status)
	        #endif
	        )
        {
    	     AppAuthorize_Status = FALSE;
        }
    
        AppAuthorize_DataStream <<=1;
         /*Real-time Monitor*/	
	AppAuthorize_Real_Status = TRUE;
	AppAuthorize_Real_Timer = K_AppAuthorize_Real_Timeout;  
		
    }
        /*Real-time Monitor*/
    if(TRUE == AppAuthorize_Real_Status)
    {
         if(AppAuthorize_Real_Timer == 0)
         {
	      AppAuthorize_Real_Status = FALSE;  
         }
         else
         {
	      AppAuthorize_Real_Timer --;
         }
    }
    
     /* AppAuthorize_Complete Monitor*/    
    if(TRUE == AppAuthorize_Status)
    {
	 #ifdef _CONFIG_AppAuthorize_Clear_InClosed
         if((ActiveSystemMode == SystemClosedFully) && (LastSystemMode != SystemClosedFully) && (LastSystemMode != SystemInitDefault))
         {
	      AppAuthorize_Complete_Timer = 0;
	      AppAuthorize_Complete_Timer_Status = TRUE;
         }
         else if(TRUE == AppAuthorize_Complete_Timer_Status)
         {
	      if(AppAuthorize_Complete_Timer >= K_AppAuthorize_Complete_Time)
	      {
	           AppAuthorize_Complete_Timer_Status = FALSE;
		   AppAuthorize_Status = FALSE;
	      }
	      else
	      {
	           AppAuthorize_Complete_Timer ++;
	      }
         }
	 #endif
    
	 #ifdef _CONFIG_AppAuthorize_Clear_Timeout
    /*AppAuthorize Timeout Monitor*/
         if(TRUE == AppAuthorize_Timer_Status)
         {
	      if(AppAuthorize_Timer >= K_AppAuthorize_Timeout)
	      {
	           AppAuthorize_Timer_Status = FALSE;
		   #ifdef _CONFIG_AppAuthorize_Clear_Timeout
		   #ifndef _CONFIG_AppAuthorize_Clear_InClosed
		   AppAuthorize_Status = FALSE;
		   #endif
		   #endif
	      }
	      else
	      {
	           AppAuthorize_Timer ++;
	      }
         }
	 #ifdef _CONFIG_AppAuthorize_Clear_InClosed
         else if((FALSE == AppAuthorize_Timer_Status) && (ActiveSystemMode == SystemClosedFully) && (FALSE == AppAuthorize_Complete_Timer_Status))
         {
	      AppAuthorize_Status = FALSE;
         }
	 #endif
	 #endif
    }

}
#endif
#ifdef _CONFIG_BLEAuthorize
/*********************************************************************************************
** Name:	  MessageDebounce_BLEAuthorize(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_BLEAuthorize(void)
{
    static uint16_t BLEAuthorize_Real_Timer;
    static uint16_t BLEAuthorize_Timer;
    static uint8_t BLEAuthorize_Timer_Status;
    static uint16_t BLEAuthorize_Complete_Timer;
    static uint8_t BLEAuthorize_Complete_Timer_Status;
    
    BLEAuthorize_LastStatus = BLEAuthorize_Status;
    
    if(TRUE == MessageRx_BLEAuthorize_Ind)
    {  
	MessageRx_BLEAuthorize_Ind = FALSE;
    
        #ifdef _CHERY_COM
        if(MessageRx_BLEAuthorize == TRUE)
	#endif
	#ifdef _SGMW_COM
        if((MessageRx_BLEAuthorize == TRUE) && (MessageRx_BLEAuthorize_Valid == _AUTHORIZE_VALID))
	#endif
	#ifdef _SGM_COM
        if((MessageRx_BLEAuthorize == TRUE) && (MessageRx_BLEAuthorize_Valid == _AUTHORIZE_VALID))
	#endif
	#ifdef _CTCS_COM
        if(MessageRx_BLEAuthorize == TRUE)
	#endif
	#ifdef _DEARCC_COM
	if(MessageRx_BLEAuthorize == _TBOX_PTRUEG_LOCK)
	#endif
	#ifdef _MAXUS_COM
        if(MessageRx_BLEAuthorize == TRUE)
	#endif
	#ifdef _DFMC_COM
        if(MessageRx_BLEAuthorize == _bcm_ble_response_Anti_theft_authentication_success)
	#endif
	#ifdef _BAIC_COM
        if(MessageRx_BLEAuthorize == _BleAuthentRes_IAnthentication_success)
	#endif
	#ifdef _DFLZM_COM
        if(MessageRx_BLEAuthorize == TRUE)
	#endif
	#ifdef _NIU_COM
        if(MessageRx_BLEAuthorize == TRUE)
	#endif
	#ifdef _CHANGAN_COM
        if(MessageRx_BLEAuthorize == TRUE)
	#endif
	{
	     BLEAuthorize_DataStream |= 0x0001;
        }
        if((MASK01BIT & BLEAuthorize_DataStream) == MASK01BIT)	 
        {    
             BLEAuthorize_Status = TRUE;
	     /*Timeout Monitor*/
	     BLEAuthorize_Timer = 0;
	     BLEAuthorize_Timer_Status = TRUE;
        } 
	else if(((MASK01BIT & BLEAuthorize_DataStream) == 0)
	        #ifdef _CONFIG_BLEAuthorize_Clear_Timeout
	        && (FALSE == BLEAuthorize_Timer_Status)
	        #endif
	        )
        {
    	     BLEAuthorize_Status = FALSE;
        }
    
        BLEAuthorize_DataStream <<=1;
         /*Real-time Monitor*/	
	BLEAuthorize_Real_Status = TRUE;
	BLEAuthorize_Real_Timer = K_BLEAuthorize_Real_Timeout;  
		
    }
        /*Real-time Monitor*/
    if(TRUE == BLEAuthorize_Real_Status)
    {
         if(BLEAuthorize_Real_Timer == 0)
         {
	      BLEAuthorize_Real_Status = FALSE;  
         }
         else
         {
	      BLEAuthorize_Real_Timer --;
         }
    }
    
     /* BLEAuthorize_Complete Monitor*/    
    if(TRUE == BLEAuthorize_Status)
    {
	 #ifdef _CONFIG_BLEAuthorize_Clear_InClosed
         if((ActiveSystemMode == SystemClosedFully) && (LastSystemMode != SystemClosedFully) && (LastSystemMode != SystemInitDefault))
         {
	      BLEAuthorize_Complete_Timer = 0;
	      BLEAuthorize_Complete_Timer_Status = TRUE;
         }
         else if(TRUE == BLEAuthorize_Complete_Timer_Status)
         {
	      if(BLEAuthorize_Complete_Timer >= K_BLEAuthorize_Complete_Time)
	      {
	           BLEAuthorize_Complete_Timer_Status = FALSE;
		   BLEAuthorize_Status = FALSE;
	      }
	      else
	      {
	           BLEAuthorize_Complete_Timer ++;
	      }
         }
	 #endif
    
	 #ifdef _CONFIG_BLEAuthorize_Clear_Timeout
    /*BLEAuthorize Timeout Monitor*/
         if(TRUE == BLEAuthorize_Timer_Status)
         {
	      if(BLEAuthorize_Timer >= K_BLEAuthorize_Timeout)
	      {
	           BLEAuthorize_Timer_Status = FALSE;
		   #ifdef _CONFIG_BLEAuthorize_Clear_Timeout
		   #ifndef _CONFIG_BLEAuthorize_Clear_InClosed
		   BLEAuthorize_Status = FALSE;
		   #endif
		   #endif
	      }
	      else
	      {
	           BLEAuthorize_Timer ++;
	      }
         }
	 #ifdef _CONFIG_BLEAuthorize_Clear_InClosed
         else if((FALSE == BLEAuthorize_Timer_Status) && (ActiveSystemMode == SystemClosedFully) && (FALSE == BLEAuthorize_Complete_Timer_Status))
         {
	      BLEAuthorize_Status = FALSE;
         }
	 #endif
	 #endif
    }

}
#endif
#ifdef _CONFIG_FobAuthorize
/*********************************************************************************************
** Name:	  MessageDebounce_FobAuthorize(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_FobAuthorize(void)
{
    static uint16_t FobAuthorize_Real_Timer;
    static uint16_t FobAuthorize_Timer;
    static uint8_t FobAuthorize_Timer_Status;
    static uint16_t FobAuthorize_Complete_Timer;
    static uint8_t FobAuthorize_Complete_Timer_Status;
    
    FobAuthorize_LastStatus = FobAuthorize_Status;
    
    if(TRUE == MessageRx_FobAuthorize_Ind)
    {  
	MessageRx_FobAuthorize_Ind = FALSE;
    
        #ifdef _CHERY_COM
        if(MessageRx_FobAuthorize == _PEPS_PLGUnlockReq_UnLock)
	#endif
	#ifdef _SGMW_COM
        if((MessageRx_FobAuthorize == TRUE) && (MessageRx_FobAuthorize_Valid == TRUE))
	#endif
	#ifdef _SGM_COM
        if((MessageRx_FobAuthorize == TRUE) && (MessageRx_FobAuthorize_Valid == TRUE))
	#endif
	#ifdef _CTCS_COM
        if(MessageRx_FobAuthorize == TRUE)
	#endif
	#ifdef _DEARCC_COM
        if(MessageRx_FobAuthorize == _RKE_TRUNK_UNLOCK)
	#endif
	#ifdef _MAXUS_COM
        if(MessageRx_FobAuthorize == TRUE)
	#endif
	#ifdef _DFMC_COM
        if(MessageRx_FobAuthorize == TRUE)
	#endif
	#ifdef _BAIC_COM
        if(MessageRx_FobAuthorize == _BleAuthentRes_IAnthentication_success)
	#endif
	#ifdef _DFLZM_COM
        if(MessageRx_FobAuthorize == TRUE)
	#endif
	#ifdef _NIU_COM
        if(MessageRx_FobAuthorize == TRUE)
	#endif
	#ifdef _CHANGAN_COM
        if(MessageRx_FobAuthorize == TRUE)
	#endif
	{
	     FobAuthorize_DataStream |= 0x0001;
        }
        if((MASK01BIT & FobAuthorize_DataStream) == MASK01BIT)	 
        {    
             FobAuthorize_Status = TRUE;
	     /*Timeout Monitor*/
	     FobAuthorize_Timer = 0;
	     FobAuthorize_Timer_Status = TRUE;
        }  
	else if(((MASK01BIT & FobAuthorize_DataStream) == 0)
	        #ifdef _CONFIG_FobAuthorize_Clear_Timeout
	        && (FALSE == FobAuthorize_Timer_Status)
	        #endif
	        )
        {
    	     FobAuthorize_Status = FALSE;
        }
    
        FobAuthorize_DataStream <<=1;
         /*Real-time Monitor*/	
	FobAuthorize_Real_Status = TRUE;
	FobAuthorize_Real_Timer = K_FobAuthorize_Real_Timeout;  
		
    }
        /*Real-time Monitor*/
    if(TRUE == FobAuthorize_Real_Status)
    {
         if(FobAuthorize_Real_Timer == 0)
         {
	      FobAuthorize_Real_Status = FALSE;  
         }
         else
         {
	      FobAuthorize_Real_Timer --;
         }
    }
    
     /* FobAuthorize_Complete Monitor*/    
    if(TRUE == FobAuthorize_Status)
    {
	 #ifdef _CONFIG_FobAuthorize_Clear_InClosed
         if((ActiveSystemMode == SystemClosedFully) && (LastSystemMode != SystemClosedFully) && (LastSystemMode != SystemInitDefault))
         {
	      FobAuthorize_Complete_Timer = 0;
	      FobAuthorize_Complete_Timer_Status = TRUE;
         }
         else if(TRUE == FobAuthorize_Complete_Timer_Status)
         {
	      if(FobAuthorize_Complete_Timer >= K_FobAuthorize_Complete_Time)
	      {
	           FobAuthorize_Complete_Timer_Status = FALSE;
		   FobAuthorize_Status = FALSE;
	      }
	      else
	      {
	           FobAuthorize_Complete_Timer ++;
	      }
         }
         #endif
	 #ifdef _CONFIG_FobAuthorize_Clear_Timeout
    /*FobAuthorize Timeout Monitor*/
         if(TRUE == FobAuthorize_Timer_Status)
         {
	      if(FobAuthorize_Timer >= K_FobAuthorize_Timeout)
	      {
	           FobAuthorize_Timer_Status = FALSE;
		   #ifdef _CONFIG_FobAuthorize_Clear_Timeout
		   #ifndef _CONFIG_FobAuthorize_Clear_InClosed
		   FobAuthorize_Status = FALSE;
		   #endif
		   #endif
	      }
	      else
	      {
	           FobAuthorize_Timer ++;
	      }
         }
	 #ifdef _CONFIG_FobAuthorize_Clear_InClosed
         else if((FALSE == FobAuthorize_Timer_Status) && (ActiveSystemMode == SystemClosedFully) && (FALSE == FobAuthorize_Complete_Timer_Status))
         {
	      FobAuthorize_Status = FALSE;
         }
	 #endif
	 #endif
    }
}
#endif
#ifdef _CONFIG_PKEAuthorize
/*********************************************************************************************
** Name:	  MessageDebounce_PKEAuthorize(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_PKEAuthorize(void)
{

}
#endif
#ifdef _CONFIG_AntiLockAuthorize
/*********************************************************************************************
** Name:	  MessageDebounce_AntiLockAuthorize(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_AntiLockAuthorize(void)
{
    static uint16_t AntiLockAuthorize_Real_Timer;
    static uint16_t AntiLockAuthorize_Timer;
    static uint8_t AntiLockAuthorize_Timer_Status;
    static uint16_t AntiLockAuthorize_Complete_Timer;
    static uint8_t AntiLockAuthorize_Complete_Timer_Status;
    
    AntiLockAuthorize_LastStatus = AntiLockAuthorize_Status;
    
    if(TRUE == MessageRx_AntiLockAuthorize_Ind)
    {  
	MessageRx_AntiLockAuthorize_Ind = FALSE;
    
        #ifdef _CHERY_COM
        if((MessageRx_AntiLockAuthorize == TRUE) && (MessageRx_AntiLockAuthorize_Valid == TRUE))
	#endif
	#ifdef _SGMW_COM
        if((MessageRx_AntiLockAuthorize == TRUE) && (MessageRx_AntiLockAuthorize_Valid == TRUE))
	#endif
	#ifdef _SGM_COM
        if((MessageRx_AntiLockAuthorize == TRUE) && (MessageRx_AntiLockAuthorize_Valid == TRUE))
	#endif
	#ifdef _CTCS_COM
        if(MessageRx_AntiLockAuthorize == TRUE)
	#endif
	#ifdef _DEARCC_COM
        if(MessageRx_AntiLockAuthorize == _PEPS_REQUEST_2)
	#endif
	#ifdef _MAXUS_COM
        if(MessageRx_AntiLockAuthorize == TRUE)
	#endif
	#ifdef _DFMC_COM
        if(MessageRx_AntiLockAuthorize == _bcm_keyInPotRemind_Warning)
	#endif
	#ifdef _BAIC_COM
        if(MessageRx_AntiLockAuthorize == TRUE)
	#endif
	#ifdef _DFLZM_COM
        if(MessageRx_AntiLockAuthorize == TRUE)
	#endif
	#ifdef _NIU_COM
        if(MessageRx_AntiLockAuthorize == TRUE)
	#endif
	#ifdef _CHANGAN_COM
        if(MessageRx_AntiLockAuthorize == TRUE)
	#endif
	{
	     AntiLockAuthorize_DataStream |= 0x0001;
        }
        if((MASK01BIT & AntiLockAuthorize_DataStream) == MASK01BIT)	 
        {    
             AntiLockAuthorize_Status = TRUE;
	     /*Timeout Monitor*/
	     AntiLockAuthorize_Timer = 0;
	     AntiLockAuthorize_Timer_Status = TRUE;
        }
	else if(((MASK01BIT & AntiLockAuthorize_DataStream) == 0)
	        #ifdef _CONFIG_AntiLockAuthorize_Clear_Timeout
	        && (FALSE == AntiLockAuthorize_Timer_Status)
	        #endif
	        )
        {
    	     AntiLockAuthorize_Status = FALSE;
        }
    
        AntiLockAuthorize_DataStream <<=1;
         /*Real-time Monitor*/	
	AntiLockAuthorize_Real_Status = TRUE;
	AntiLockAuthorize_Real_Timer = K_AntiLockAuthorize_Real_Timeout;  
		
    }
        /*Real-time Monitor*/
    if(TRUE == AntiLockAuthorize_Real_Status)
    {
         if(AntiLockAuthorize_Real_Timer == 0)
         {
	      AntiLockAuthorize_Real_Status = FALSE;  
         }
         else
         {
	      AntiLockAuthorize_Real_Timer --;
         }
    }
    
     /* AntiLockAuthorize_Complete Monitor*/    
    if(TRUE == AntiLockAuthorize_Status)
    {
	 #ifdef _CONFIG_AntiLockAuthorize_Clear_InClosed
         if((ActiveSystemMode == SystemClosedFully) && (LastSystemMode != SystemClosedFully) && (LastSystemMode != SystemInitDefault))
         {
	      AntiLockAuthorize_Complete_Timer = 0;
	      AntiLockAuthorize_Complete_Timer_Status = TRUE;
         }
         else if(TRUE == AntiLockAuthorize_Complete_Timer_Status)
         {
	      if(AntiLockAuthorize_Complete_Timer >= K_AntiLockAuthorize_Complete_Time)
	      {
	           AntiLockAuthorize_Complete_Timer_Status = FALSE;
		   AntiLockAuthorize_Status = FALSE;
	      }
	      else
	      {
	           AntiLockAuthorize_Complete_Timer ++;
	      }
         }
	 #endif
         
	 #ifdef _CONFIG_AntiLockAuthorize_Clear_Timeout
    /*AntiLockAuthorize Timeout Monitor*/
         if(TRUE == AntiLockAuthorize_Timer_Status)
         {
	      if(AntiLockAuthorize_Timer >= K_AntiLockAuthorize_Timeout)
	      {
	           AntiLockAuthorize_Timer_Status = FALSE;
		   #ifdef _CONFIG_AntiLockAuthorize_Clear_Timeout
		   #ifndef _CONFIG_AntiLockAuthorize_Clear_InClosed
		   AntiLockAuthorize_Status = FALSE;
		   #endif
		   #endif
	      }
	      else
	      {
	           AntiLockAuthorize_Timer ++;
	      }
         }
	 #ifdef _CONFIG_AntiLockAuthorize_Clear_InClosed
         else if((FALSE == AntiLockAuthorize_Timer_Status) && (ActiveSystemMode == SystemClosedFully) && (FALSE == AntiLockAuthorize_Complete_Timer_Status))
         {
	      AntiLockAuthorize_Status = FALSE;
         }
	 #endif
	 #endif
    }
}
#endif

#ifdef _CONFIG_RearWiperStatus
/*********************************************************************************************
** Name:	  MessageDebounce_RearWiperStatus(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_RearWiperStatus(void)
{
    static uint16_t RearWiper_Real_Timer = 0;
    
    RearWiper_LastStatus = RearWiper_Status;
    
    if(TRUE == MessageRx_RearWiper_Ind)
    {  
	MessageRx_RearWiper_Ind = FALSE;
        /*RearWiperStatus*/
        #ifdef _CHERY_COM
        if(MessageRx_RearWiper == TRUE)
        #endif
        #ifdef _SGMW_COM
        if(MessageRx_RearWiper == TRUE)
        #endif
	#ifdef _SGM_COM
        if(MessageRx_RearWiper == TRUE)
        #endif
        #ifdef _CTCS_COM
        if(MessageRx_RearWiper == TRUE)
        #endif
        #ifdef _DEARCC_COM
        if(MessageRx_RearWiper == TRUE)
        #endif
	#ifdef _XIAOPENG_COM
        if(MessageRx_RearWiper == TRUE)
        #endif
	#ifdef _MAXUS_COM
        if(MessageRx_RearWiper == _WIPER_LOW_SPEED)
        #endif
	#ifdef _DFMC_COM
        if(MessageRx_RearWiper == TRUE)
        #endif
	#ifdef _BAIC_COM
        if(MessageRx_RearWiper == TRUE)
        #endif
	#ifdef _DFLZM_COM
        if(MessageRx_RearWiper == TRUE)
        #endif
	#ifdef _NIU_COM
        if(MessageRx_RearWiper == TRUE)
        #endif
	#ifdef _FAW_COM
        if(MessageRx_RearWiper == _WIPER_LOW_SPEED)
        #endif
	#ifdef _CHANGAN_COM
        if(MessageRx_RearWiper == TRUE)
        #endif
        {
	     RearWiper_DataStream |= 0x0001;
        }
        if((MASK30MS & RearWiper_DataStream) == MASK30MS)	 
        {    
             RearWiper_Status = TRUE;
        }
        else if((MASK30MS & RearWiper_DataStream) == 0)
        {
    	     RearWiper_Status = FALSE;
        }    
        RearWiper_DataStream <<=1;	

        /*Real-time Monitor*/	
	RearWiper_Real_Status = TRUE;
	RearWiper_Real_Timer = K_RearWiper_Real_Timeout;  
	
    }        
    /*Real-time Monitor*/
    if(TRUE == RearWiper_Real_Status)
    {
         if(RearWiper_Real_Timer == 0)
         {
	      RearWiper_Real_Status = FALSE;   
         }
         else
         {
	      RearWiper_Real_Timer --;
         }
    }
    
    /* RearWiper RiseEdge and FallEdge Active monitor */ 
    if(( FALSE == RearWiper_Status) && ( TRUE == RearWiper_LastStatus))
    {
    	 RearWiper_RiseEdge_Active = TRUE;
    }
    else
    {
    	 RearWiper_RiseEdge_Active = FALSE;
    }
 
    if((TRUE == RearWiper_Status) && ( FALSE == RearWiper_LastStatus))
    {
	 RearWiper_FallEdge_Active = TRUE;
    }
    else
    {
	 RearWiper_FallEdge_Active = FALSE;
    }
}
#endif

#ifdef _CONFIG_DoorStatus
/*********************************************************************************************
** Name:	  MessageDebounce_DoorStatus(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_DoorStatus(void)
{  

}
#endif

#ifdef _CONFIG_WindowsPosition
/*********************************************************************************************
** Name:	  MessageDebounce_WindowsPosition(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_WindowsPosition(void)
{

}
#endif

#ifdef _CONFIG_BlowerSpeed
/*********************************************************************************************
** Name:	  MessageDebounce_BlowerSpeed(void);
** Function:
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_BlowerSpeed(void)
{

}
#endif

#ifdef _CONFIG_BusTemperature
/*********************************************************************************************
** Name:	  MessageDebounce_BusTemperature(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_BusTemperature(void)
{

}
#endif

#ifdef _CONFIG_SunRoofPosition
/*********************************************************************************************
** Name:	  MessageDebounce_SunRoofPosition(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_SunRoofPosition(void)
{
    static uint16_t SunRoofPosition_Real_Timer;
    
    if(TRUE == MessageRx_SunRoofPosition_Ind)
    {  
	MessageRx_SunRoofPosition_Ind = FALSE;
	
        #ifdef _CHERY_COM
        if(MessageRx_SunRoofPosition == TRUE)
        #endif
        #ifdef _SGMW_COM
        if(MessageRx_SunRoofPosition == TRUE)
        #endif
	#ifdef _SGM_COM
        if(MessageRx_SunRoofPosition == TRUE)
        #endif
        #ifdef _CTCS_COM
        if(MessageRx_SunRoofPosition == _SUNROOF_FULLY_CLOSED)
        #endif
        #ifdef _DEARCC_COM
        if(MessageRx_SunRoofPosition <= K_SunRoof_Closed_Position)
        #endif
	#ifdef _XIAOPENG_COM
        if(MessageRx_SunRoofPosition == TRUE)
        #endif
	#ifdef _MAXUS_COM
        if((MessageRx_SunRoofPosition <= _SRFSts_12Percent) || (MessageRx_SunRoofPosition == _SRFSts_Position_Unknown))
        #endif
	#ifdef _DFMC_COM
        if(MessageRx_SunRoofPosition <= _srm_srMovement_reserved)
        #endif
	#ifdef _BAIC_COM 
	  #ifdef _BAIC_COM_C52X
        if((MessageRx_SunRoofPosition <= _BDCRptSunRPosn_10_Pecent) || (MessageRx_SunRoofPosition == _BDCRptSunRPosn_Fully_close))
	  #endif
	  #ifdef _BAIC_COM_C62X
	if(MessageRx_SunRoofPosition <= _BCM_SUNROOF_POS_Open_10Percent)  
	  #endif
        #endif
	#ifdef _DFLZM_COM
        if(MessageRx_SunRoofPosition <= _BCM3_Status_SrPos_Vent_area)
        #endif
	#ifdef _NIU_COM
        if(MessageRx_SunRoofPosition == TRUE)
        #endif
	#ifdef _FAW_COM
        if(MessageRx_SunRoofPosition <= _SunroofSt_FullClosed)
        #endif
	#ifdef _CHANGAN_COM
        if(MessageRx_SunRoofPosition == TRUE)
        #endif
        {
	     SunRoofPosition_DataStream |= 0x0001;
        }
        if((MASK01BIT & SunRoofPosition_DataStream) == MASK01BIT)	 
        {    
             SunRoofPosition_Status = TRUE;
        }
        else if((MASK01BIT & SunRoofPosition_DataStream) == 0)
        {
    	     SunRoofPosition_Status = FALSE;
        }
    
        SunRoofPosition_DataStream <<=1;
    	SunRoofPosition_Real_Status = TRUE;
	SunRoofPosition_Real_Timer = K_SunRoofPosition_Real_Timeout;  
    }
    /*Real-time Monitor*/
    if(TRUE == SunRoofPosition_Real_Status)
    {
         if(SunRoofPosition_Real_Timer == 0)
         {
	      SunRoofPosition_Real_Status = FALSE;   
         }
         else
         {
	      SunRoofPosition_Real_Timer --;
         }
    } 
    
    /* AllWindowClosed_Status Filter*/
    if(TRUE == SunRoofPosition_Status)
    {
	 AllSunRoofClosed_Status = TRUE;
    }
    #ifdef _CONFIG_SunRoofPosition_Closed_Default
    else if(FALSE == SunRoofPosition_Real_Status)
    {
	 AllSunRoofClosed_Status = TRUE;
    }
    #endif
    else
    {
	 AllSunRoofClosed_Status = FALSE;
    }
}
#endif

#ifdef _CONFIG_OpenSpeedLevel
/*********************************************************************************************
** Name:	  MessageDebounce_OpenSpeedLevel(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_OpenSpeedLevel(void)
{
    static uint16_t OpenSpeedLevel_Real_Timer;
    static uint8_t OpenSpeedLevel_SingleEvent_Enable;
   
    #define K_OpenSpeedLevel_Real_Timeout 30
    #define K_OpenSpeedLevel_SingleEvent_Enable TRUE
    
    OpenSpeedLevel_LastStatus = OpenSpeedLevel_Status;
    if(TRUE == MessageRx_OpenSpeedLevel_Ind)
    {  
	MessageRx_OpenSpeedLevel_Ind = FALSE;
	
        #ifdef _CHERY_COM
        if(MessageRx_OpenSpeedLevel == TRUE)
        #endif
        #ifdef _SGMW_COM
        if(MessageRx_OpenSpeedLevel == TRUE)
        #endif
	#ifdef _SGM_COM
        if(MessageRx_OpenSpeedLevel == TRUE)
        #endif
        #ifdef _CTCS_COM
        if(MessageRx_OpenSpeedLevel == TRUE)
        #endif
        #ifdef _DEARCC_COM
        if(MessageRx_OpenSpeedLevel == TRUE)
        #endif
	#ifdef _XIAOPENG_COM
        if(MessageRx_OpenSpeedLevel == TRUE)
        #endif
	#ifdef _MAXUS_COM
        if(MessageRx_OpenSpeedLevel == TRUE)
        #endif
	#ifdef _BAIC_COM
        if(MessageRx_OpenSpeedLevel == TRUE)
        #endif
	#ifdef _DFLZM_COM
        if(MessageRx_OpenSpeedLevel == TRUE)
        #endif
	#ifdef _NIU_COM
        if(MessageRx_OpenSpeedLevel == TRUE)
        #endif
	#ifdef _FAW_COM
        if(MessageRx_OpenSpeedLevel == TRUE)
        #endif
	#ifdef _CHANGAN_COM
        if(MessageRx_OpenSpeedLevel == TRUE)
        #endif
        {
	     OpenSpeedLevel_DataStream |= 0x0001;
        }
        if((MASK01BIT & OpenSpeedLevel_DataStream) == MASK01BIT)	 
        {    
             OpenSpeedLevel_Status = TRUE;
        }
        else if((MASK01BIT & OpenSpeedLevel_DataStream) == 0)
        {
    	     OpenSpeedLevel_Status = FALSE;
        }
    
        OpenSpeedLevel_DataStream <<=1;
    	OpenSpeedLevel_Real_Status = TRUE;
	OpenSpeedLevel_Real_Timer = K_OpenSpeedLevel_Real_Timeout;  
    }
    /*Real-time Monitor*/
    if(TRUE == OpenSpeedLevel_Real_Status)
    {
         if(OpenSpeedLevel_Real_Timer == 0)
         {
	      OpenSpeedLevel_Real_Status = FALSE;   
	      if(TRUE == K_OpenSpeedLevel_SingleEvent_Enable) /*10,1110 is MultiEvent, 1,111 is SingleEvent */
	      {
		   OpenSpeedLevel_SingleEvent_Enable = TRUE;
	      }
	      if(TRUE == OpenSpeedLevel_SingleEvent_Enable) 
	      {
		   OpenSpeedLevel_SingleEvent_Enable = FALSE;
		   OpenSpeedLevel_Status = FALSE;
	      }
         }
         else
         {
	      OpenSpeedLevel_Real_Timer --;
         }
    }
    
         /* OpenSpeedLevel RiseEdge and FallEdge Active monitor */  
    if((FALSE == OpenSpeedLevel_Status) && (TRUE == OpenSpeedLevel_LastStatus))
    {
    	 OpenSpeedLevel_RiseEdge_Active = TRUE;
    } 
    else
    {
    	 OpenSpeedLevel_RiseEdge_Active = FALSE;
    }
 
    if((TRUE == OpenSpeedLevel_Status) && (FALSE == OpenSpeedLevel_LastStatus))
    {
	 OpenSpeedLevel_FallEdge_Active = TRUE;

    }	 
    else
    {
	 OpenSpeedLevel_FallEdge_Active = FALSE;
    }
}
#endif
#ifdef _CONFIG_CloseSpeedLevel
/*********************************************************************************************
** Name:	  MessageDebounce_CloseSpeedLevel(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_CloseSpeedLevel(void)
{
    static uint16_t CloseSpeedLevel_Real_Timer;
    static uint8_t CloseSpeedLevel_SingleEvent_Enable;
    
    #define K_CloseSpeedLevel_Real_Timeout 30   
    #define K_CloseSpeedLevel_SingleEvent_Enable TRUE
    
    CloseSpeedLevel_LastStatus = CloseSpeedLevel_Status;
    
    if(TRUE == MessageRx_CloseSpeedLevel_Ind)
    {  
	MessageRx_CloseSpeedLevel_Ind = FALSE;
	
        #ifdef _CHERY_COM
        if(MessageRx_CloseSpeedLevel == TRUE)
        #endif
        #ifdef _SGMW_COM
        if(MessageRx_CloseSpeedLevel == TRUE)
        #endif
	#ifdef _SGM_COM
        if(MessageRx_CloseSpeedLevel == TRUE)
        #endif
        #ifdef _CTCS_COM
        if(MessageRx_CloseSpeedLevel == TRUE)
        #endif
        #ifdef _DEARCC_COM
        if(MessageRx_CloseSpeedLevel == TRUE)
        #endif
	#ifdef _XIAOPENG_COM
        if(MessageRx_CloseSpeedLevel == _SDCCloseSpdCfg_Spd_1)
	{
	     CloseSpeedLevel = _SpeedLevel_1;
	}
	else if(MessageRx_CloseSpeedLevel == _SDCCloseSpdCfg_Spd_2)
	{
	     CloseSpeedLevel = _SpeedLevel_2;
	}
	else if(MessageRx_CloseSpeedLevel == _SDCCloseSpdCfg_Spd_3)
	{
	     CloseSpeedLevel = _SpeedLevel_3;
	}
	else if(MessageRx_CloseSpeedLevel == _SDCCloseSpdCfg_Spd_4)
	{
	     CloseSpeedLevel = _SpeedLevel_Default;
	}
	else if(MessageRx_CloseSpeedLevel == _SDCCloseSpdCfg_Spd_5)
	{
	     CloseSpeedLevel = _SpeedLevel_5;
	}
	else if(MessageRx_CloseSpeedLevel == _SDCCloseSpdCfg_Spd_6)
	{
	     CloseSpeedLevel = _SpeedLevel_6;
	}	
        if((MessageRx_CloseSpeedLevel >= _SDCCloseSpdCfg_Spd_1) && (MessageRx_CloseSpeedLevel <= _SDCCloseSpdCfg_Spd_6))
        #endif
	#ifdef _MAXUS_COM
        if(MessageRx_CloseSpeedLevel == TRUE)
        #endif
	#ifdef _BAIC_COM
        if(MessageRx_CloseSpeedLevel == TRUE)
        #endif
	#ifdef _DFLZM_COM
        if(MessageRx_CloseSpeedLevel == TRUE)
        #endif
	#ifdef _NIU_COM
        if(MessageRx_CloseSpeedLevel == TRUE)
        #endif
	#ifdef _FAW_COM
        if(MessageRx_CloseSpeedLevel == TRUE)
        #endif
	#ifdef _CHANGAN_COM
        if(MessageRx_CloseSpeedLevel == TRUE)
        #endif
        {
	     CloseSpeedLevel_DataStream |= 0x0001;
        }
        if((MASK01BIT & CloseSpeedLevel_DataStream) == MASK01BIT)	 
        {    
             CloseSpeedLevel_Status = TRUE;
        }
        else if((MASK01BIT & CloseSpeedLevel_DataStream) == 0)
        {
    	     CloseSpeedLevel_Status = FALSE;
        }
    
        CloseSpeedLevel_DataStream <<=1;
    	CloseSpeedLevel_Real_Status = TRUE;
	CloseSpeedLevel_Real_Timer = K_CloseSpeedLevel_Real_Timeout;  
    }
    /*Real-time Monitor*/
    if(TRUE == CloseSpeedLevel_Real_Status)
    {
         if(CloseSpeedLevel_Real_Timer == 0)
         {
	      CloseSpeedLevel_Real_Status = FALSE; 
	      if(TRUE == K_CloseSpeedLevel_SingleEvent_Enable) /*10,1110 is MultiEvent, 1,111 is SingleEvent */
	      {
		   CloseSpeedLevel_SingleEvent_Enable = TRUE;
	      }
	      if(TRUE == CloseSpeedLevel_SingleEvent_Enable) 
	      {
		   CloseSpeedLevel_SingleEvent_Enable = FALSE;
		   CloseSpeedLevel_Status = FALSE;
	      }
         }
         else
         {
	      CloseSpeedLevel_Real_Timer --;
         }
    }
    
    
     /* CloseSpeedLevel RiseEdge and FallEdge Active monitor */  
    if((FALSE == CloseSpeedLevel_Status) && (TRUE == CloseSpeedLevel_LastStatus))
    {
    	 CloseSpeedLevel_RiseEdge_Active = TRUE;
    } 
    else
    {
    	 CloseSpeedLevel_RiseEdge_Active = FALSE;
    }
 
    if((TRUE == CloseSpeedLevel_Status) && (FALSE == CloseSpeedLevel_LastStatus))
    {
	 CloseSpeedLevel_FallEdge_Active = TRUE;

    }	 
    else
    {
	 CloseSpeedLevel_FallEdge_Active = FALSE;
    }
}
#endif

#ifdef _CONFIG_ModeStatus_NormalMode
/*********************************************************************************************
** Name:	  MessageDebounce_NormalMode(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_NormalMode(void)
{
 
}
#endif
#ifdef _CONFIG_ModeStatus_GarageMode
/*********************************************************************************************
** Name:	  MessageDebounce_GarageMode(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_GarageMode(void)
{	
    static uint16_t GarageMode_Real_Timer;
    
    GarageMode_LastStatus = GarageMode_Status;

    if(TRUE == MessageRx_GarageMode_Ind)
    {  
	 MessageRx_GarageMode_Ind = FALSE;
	  
        #ifdef _DEARCC_COM
        if(MessageRx_GarageMode == _PLGMODE_REQUEST_GARAGE)
        #endif
	#ifdef _MAXUS_COM
        if(MessageRx_GarageMode == _TlgtOprtMdSt_Park)
        #endif
	#ifdef _BAIC_COM
        if(MessageRx_GarageMode == _PtmEna_ON)
        #endif
        {
	     GarageMode_DataStream |= 0x0001;
        }
        if((MASK01BIT & GarageMode_DataStream) == MASK01BIT)	 
        {    
             GarageMode_Status = TRUE;
        }
        else if((MASK01BIT & GarageMode_DataStream) == 0)
        {
    	     GarageMode_Status = FALSE;
        }
    
        GarageMode_DataStream <<=1;
    	GarageMode_Real_Status = TRUE;
	GarageMode_Real_Timer = K_GarageMode_Real_Timeout;
    }
    
        /*Real-time Monitor*/
    if(TRUE == GarageMode_Real_Status)
    {
         if(GarageMode_Real_Timer == 0)
         {
	      GarageMode_Real_Status = FALSE;   
	      if(TRUE == K_GarageMode_SingleEvent_Enable) /*10,1110 is MultiEvent, 1,111 is SingleEvent */
	      {
		   GarageMode_SingleEvent_Enable = TRUE;
	      }
	      if(TRUE == GarageMode_SingleEvent_Enable) 
	      {
		   GarageMode_SingleEvent_Enable = FALSE;
		   GarageMode_Status = FALSE;
	      }
         }
         else
         {
	      GarageMode_Real_Timer --;
         }
    } 
    
        /* GarageMode RiseEdge and FallEdge Active monitor */  
    if((FALSE == GarageMode_Status) && (TRUE == GarageMode_LastStatus))
    {
    	 GarageMode_RiseEdge_Active = TRUE;
    } 
    else
    {
    	 GarageMode_RiseEdge_Active = FALSE;
    }
 
    if((TRUE == GarageMode_Status) && (FALSE == GarageMode_LastStatus))
    {
	 GarageMode_FallEdge_Active = TRUE;

    }	 
    else
    {
	 GarageMode_FallEdge_Active = FALSE;
    }
}
#endif
#ifdef _CONFIG_ModeStatus_ManualMode
/*********************************************************************************************
** Name:	  MessageDebounce_ManualMode(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_ManualMode(void)
{

}
#endif

#ifdef _CONFIG_KickSensorEnable
/*********************************************************************************************
** Name:	  MessageDebounce_KickSensorEnable(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_KickSensorEnable(void)
{
    static uint16_t KickSensorEnable_Real_Timer;
    
    if(TRUE == MessageRx_KickSensorEnable_Ind)
    {  
	 MessageRx_KickSensorEnable_Ind = FALSE; 
    
        #ifdef _CHERY_COM
        if(MessageRx_KickSensorEnable == TRUE)
        #endif
        #ifdef _SGMW_COM
        if(MessageRx_KickSensorEnable == TRUE)
        #endif
	#ifdef _SGM_COM
        if(MessageRx_KickSensorEnable == TRUE)
        #endif
        #ifdef _CTCS_COM
        if(MessageRx_KickSensorEnable == TRUE)
        #endif
        #ifdef _DEARCC_COM
        if(MessageRx_KickSensorEnable == TRUE)
        #endif
	#ifdef _XIAOPENG_COM
        if(MessageRx_KickSensorEnable == TRUE)
        #endif
	#ifdef _MAXUS_COM
        if(MessageRx_KickSensorEnable == TRUE)
        #endif
	#ifdef _DFMC_COM
        if(MessageRx_KickSensorEnable == TRUE)
        #endif
	#ifdef _BAIC_COM
        if((MessageRx_KickSensorEnable == _PtmFootKickSwt_ON)
	   || ((TRUE == KickSensorEnable_Status) && (MessageRx_KickSensorEnable != _PtmFootKickSwt_OFF)))
        #endif
	#ifdef _DFLZM_COM
        if(MessageRx_KickSensorEnable == TRUE)
        #endif
	#ifdef _NIU_COM
        if(MessageRx_KickSensorEnable == TRUE)
        #endif
	#ifdef _FAW_COM
        if(MessageRx_KickSensorEnable == TRUE)
        #endif
	#ifdef _CHANGAN_COM
        if(MessageRx_KickSensorEnable == TRUE)
        #endif
        {
	     KickSensorEnable_DataStream |= 0x0001;
        }
        if((MASK01BIT & KickSensorEnable_DataStream) == MASK01BIT)	 
        {    
             KickSensorEnable_Status = TRUE;
        }
        else if((MASK01BIT & KickSensorEnable_DataStream) == 0)
        {
    	     KickSensorEnable_Status = FALSE;
        }
    
        KickSensorEnable_DataStream <<=1;
    	KickSensorEnable_Real_Status = TRUE;
	KickSensorEnable_Real_Timer = K_KickSensorEnable_Real_Timeout;  
    }

    /*Real-time Monitor*/
    if(TRUE == KickSensorEnable_Real_Status)
    {
         if(KickSensorEnable_Real_Timer == 0)
         {
	      KickSensorEnable_Real_Status = FALSE;   
         }
         else
         {
	      KickSensorEnable_Real_Timer --;
         }
    } 

}
#endif
#ifdef _CONFIG_FlasherEnable
/*********************************************************************************************
** Name:	  MessageDebounce_FlasherEnable(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_FlasherEnable(void)
{
    static uint16_t FlasherEnable_Real_Timer;
    
    if(TRUE == MessageRx_FlasherEnable_Ind)
    {  
	 MessageRx_FlasherEnable_Ind = FALSE; 
    
        #ifdef _CHERY_COM
        if(MessageRx_FlasherEnable == TRUE)
        {    
             FlasherEnable_Status = TRUE;
        }
        else
        {
    	     FlasherEnable_Status = FALSE;
        }
        #endif
        #ifdef _SGMW_COM
        if(MessageRx_FlasherEnable == TRUE)
	{    
             FlasherEnable_Status = TRUE;
        }
        else
        {
    	     FlasherEnable_Status = FALSE;
        }
        #endif
	#ifdef _SGM_COM
        if(MessageRx_FlasherEnable == TRUE)
	{    
             FlasherEnable_Status = TRUE;
        }
        else
        {
    	     FlasherEnable_Status = FALSE;
        }
        #endif
        #ifdef _CTCS_COM
        if(MessageRx_FlasherEnable == TRUE)
	{    
             FlasherEnable_Status = TRUE;
        }
        else
        {
    	     FlasherEnable_Status = FALSE;
        }
        #endif
        #ifdef _DEARCC_COM
        if(MessageRx_FlasherEnable == TRUE)
	{    
             FlasherEnable_Status = TRUE;
        }
        else
        {
    	     FlasherEnable_Status = FALSE;
        }
        #endif
	#ifdef _XIAOPENG_COM
        if(MessageRx_FlasherEnable == TRUE)
	{    
             FlasherEnable_Status = TRUE;
        }
        else
        {
    	     FlasherEnable_Status = FALSE;
        }
        #endif
	#ifdef _MAXUS_COM
        if(MessageRx_FlasherEnable == TRUE)
	{    
             FlasherEnable_Status = TRUE;
        }
        else
        {
    	     FlasherEnable_Status = FALSE;
        }
        #endif
	#ifdef _DFMC_COM
        if(MessageRx_FlasherEnable == TRUE)
	{    
             FlasherEnable_Status = TRUE;
        }
        else
        {
    	     FlasherEnable_Status = FALSE;
        }
        #endif
	#ifdef _BAIC_COM
        if(MessageRx_FlasherEnable == _PtmLiWarmSwt_ON)
	{    
             FlasherEnable_Status = TRUE;
        }
        else if(MessageRx_FlasherEnable == _PtmLiWarmSwt_OFF)
        {
    	     FlasherEnable_Status = FALSE;
        }   
        #endif
	#ifdef _NIU_COM
        if(MessageRx_FlasherEnable == TRUE)
	{    
             FlasherEnable_Status = TRUE;
        }
        else
        {
    	     FlasherEnable_Status = FALSE;
        }
        #endif
	#ifdef _DFLZM_COM
        if(MessageRx_FlasherEnable == TRUE)
	{    
             FlasherEnable_Status = TRUE;
        }
        else
        {
    	     FlasherEnable_Status = FALSE;
        }
        #endif
	#ifdef _FAW_COM
        if(MessageRx_FlasherEnable == TRUE)
	{    
             FlasherEnable_Status = TRUE;
        }
        else
        {
    	     FlasherEnable_Status = FALSE;
        }
        #endif
	#ifdef _CHANGAN_COM
        if(MessageRx_FlasherEnable == TRUE)
	{    
             FlasherEnable_Status = TRUE;
        }
        else
        {
    	     FlasherEnable_Status = FALSE;
        }
        #endif
       
    
        FlasherEnable_DataStream <<=1;
    	FlasherEnable_Real_Status = TRUE;
	FlasherEnable_Real_Timer = K_FlasherEnable_Real_Timeout;  
    }

    /*Real-time Monitor*/
    if(TRUE == FlasherEnable_Real_Status)
    {
         if(FlasherEnable_Real_Timer == 0)
         {
	      FlasherEnable_Real_Status = FALSE;   
         }
         else
         {
	      FlasherEnable_Real_Timer --;
         }
    } 
}
#endif
#ifdef _CONFIG_BuzzerEnable
/*********************************************************************************************
** Name:	  MessageDebounce_BuzzerEnable(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_BuzzerEnable(void)
{
    static uint16_t BuzzerEnable_Real_Timer;
    
    if(TRUE == MessageRx_BuzzerEnable_Ind)
    {  
	 MessageRx_BuzzerEnable_Ind = FALSE; 
    
        #ifdef _CHERY_COM
        if(MessageRx_BuzzerEnable == TRUE)
	{    
             BuzzerEnable_Status = TRUE;
        }
        else
        {
    	     BuzzerEnable_Status = FALSE;
        }
        #endif
        #ifdef _SGMW_COM
        if(MessageRx_BuzzerEnable == TRUE)
	{    
             BuzzerEnable_Status = TRUE;
        }
        else
        {
    	     BuzzerEnable_Status = FALSE;
        }
        #endif
	#ifdef _SGM_COM
        if(MessageRx_BuzzerEnable == TRUE)
	{    
             BuzzerEnable_Status = TRUE;
        }
        else
        {
    	     BuzzerEnable_Status = FALSE;
        }
        #endif
        #ifdef _CTCS_COM
        if(MessageRx_BuzzerEnable == TRUE)
	{    
             BuzzerEnable_Status = TRUE;
        }
        else
        {
    	     BuzzerEnable_Status = FALSE;
        }
        #endif
        #ifdef _DEARCC_COM
        if(MessageRx_BuzzerEnable == TRUE)
	{    
             BuzzerEnable_Status = TRUE;
        }
        else
        {
    	     BuzzerEnable_Status = FALSE;
        }
        #endif
	#ifdef _XIAOPENG_COM
        if(MessageRx_BuzzerEnable == TRUE)
	{    
             BuzzerEnable_Status = TRUE;
        }
        else
        {
    	     BuzzerEnable_Status = FALSE;
        }
        #endif
	#ifdef _MAXUS_COM
        if(MessageRx_BuzzerEnable == TRUE)
	{    
             BuzzerEnable_Status = TRUE;
        }
        else
        {
    	     BuzzerEnable_Status = FALSE;
        }
        #endif
	#ifdef _DFMC_COM
        if(MessageRx_BuzzerEnable == TRUE)
	{    
             BuzzerEnable_Status = TRUE;
        }
        else
        {
    	     BuzzerEnable_Status = FALSE;
        }
        #endif
	#ifdef _BAIC_COM
        if(MessageRx_BuzzerEnable == _PtmSoundSwt_ON)
	{    
             BuzzerEnable_Status = TRUE;
        }
        else if(MessageRx_BuzzerEnable == _PtmSoundSwt_OFF)
        {
    	     BuzzerEnable_Status = FALSE;
        }  
        #endif
	#ifdef _NIU_COM
        if(MessageRx_BuzzerEnable == TRUE)
	{    
             BuzzerEnable_Status = TRUE;
        }
        else
        {
    	     BuzzerEnable_Status = FALSE;
        }
        #endif
	#ifdef _DFLZM_COM
        if(MessageRx_BuzzerEnable == TRUE)
	{    
             BuzzerEnable_Status = TRUE;
        }
        else
        {
    	     BuzzerEnable_Status = FALSE;
        }
        #endif
	#ifdef _FAW_COM
        if(MessageRx_BuzzerEnable == TRUE)
	{    
             BuzzerEnable_Status = TRUE;
        }
        else
        {
    	     BuzzerEnable_Status = FALSE;
        }
        #endif
	#ifdef _CHANGAN_COM
        if(MessageRx_BuzzerEnable == TRUE)
	{    
             BuzzerEnable_Status = TRUE;
        }
        else
        {
    	     BuzzerEnable_Status = FALSE;
        }
        #endif
    
        BuzzerEnable_DataStream <<=1;
    	BuzzerEnable_Real_Status = TRUE;
	BuzzerEnable_Real_Timer = K_BuzzerEnable_Real_Timeout;  
    }

    /*Real-time Monitor*/
    if(TRUE == BuzzerEnable_Real_Status)
    {
         if(BuzzerEnable_Real_Timer == 0)
         {
	      BuzzerEnable_Real_Status = FALSE;   
         }
         else
         {
	      BuzzerEnable_Real_Timer --;
         }
    } 
}
#endif
#ifdef _CONFIG_AutoOpenEnable
/*********************************************************************************************
** Name:	  MessageDebounce_AutoOpenEnable(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_AutoOpenEnable(void)
{

}
#endif

#ifdef _CONFIG_ObstcalAlarmEnable
/*********************************************************************************************
** Name:	  MessageDebounce_ObstcalAlarmEnable(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_ObstcalAlarmEnable(void)
{
    static uint16_t ObstcalAlarmEnable_Real_Timer;
    
    if(TRUE == MessageRx_ObstcalAlarmEnable_Ind)
    {  
	 MessageRx_ObstcalAlarmEnable_Ind = FALSE; 
    
        #ifdef _CHERY_COM
        if(MessageRx_ObstcalAlarmEnable == TRUE)
        #endif
        #ifdef _SGMW_COM
        if(MessageRx_ObstcalAlarmEnable == TRUE)
        #endif
	#ifdef _SGM_COM
        if(MessageRx_ObstcalAlarmEnable == TRUE)
        #endif
        #ifdef _CTCS_COM
        if(MessageRx_ObstcalAlarmEnable == TRUE)
        #endif
        #ifdef _DEARCC_COM
        if(MessageRx_ObstcalAlarmEnable == TRUE)
        #endif
	#ifdef _XIAOPENG_COM
        if(MessageRx_ObstcalAlarmEnable == TRUE)
        #endif
	#ifdef _MAXUS_COM
        if(MessageRx_ObstcalAlarmEnable == TRUE)
        #endif
	#ifdef _DFMC_COM
        if(MessageRx_ObstcalAlarmEnable == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _BAIC_COM
        if(MessageRx_ObstcalAlarmEnable == TRUE)
        #endif
	#ifdef _DFLZM_COM
        if(MessageRx_ObstcalAlarmEnable == TRUE)
        #endif
	#ifdef _NIU_COM
        if(MessageRx_ObstcalAlarmEnable == _MMI3_RDMAntiPinchAlarmSet_On)
        #endif
	#ifdef _FAW_COM
        if(MessageRx_ObstcalAlarmEnable == TRUE)
        #endif
	#ifdef _CHANGAN_COM
        if(MessageRx_ObstcalAlarmEnable == TRUE)
        #endif
        {
	     ObstcalAlarmEnable_DataStream |= 0x0001;
        }
        if((MASK01BIT & ObstcalAlarmEnable_DataStream) == MASK01BIT)	 
        {    
             ObstcalAlarmEnable_Status = TRUE;
        }
        else if((MASK01BIT & ObstcalAlarmEnable_DataStream) == 0)
        {
    	     ObstcalAlarmEnable_Status = FALSE;
        }
    
        ObstcalAlarmEnable_DataStream <<=1;
    	ObstcalAlarmEnable_Real_Status = TRUE;
	ObstcalAlarmEnable_Real_Timer = K_ObstcalAlarmEnable_Real_Timeout;  
    }

    /*Real-time Monitor*/
    if(TRUE == ObstcalAlarmEnable_Real_Status)
    {
         if(ObstcalAlarmEnable_Real_Timer == 0)
         {
	      ObstcalAlarmEnable_Real_Status = FALSE;   
         }
         else
         {
	      ObstcalAlarmEnable_Real_Timer --;
         }
    } 
}
#endif


#ifdef _CONFIG_BLEEnable
/*********************************************************************************************
** Name:	  MessageDebounce_BLEEnable(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_BLEEnable(void)
{
    static uint16_t BLEEnable_Real_Timer;

    if(TRUE == MessageRx_BLEEnable_Ind)
    {  
	 MessageRx_BLEEnable_Ind = FALSE; 
    
        #ifdef _CHERY_COM
	    #ifdef _CHERY_COM_PD
        if(MessageRx_BLEEnable == _FLZCU_9_BLEOpenDriverDoorSts_Enable)//_ICC_BLEOpenDriverDoorEnable_Enable)
	{    
             BLEEnable_Status = _Function_Enable;
        }
        else if(MessageRx_BLEEnable == _FLZCU_9_BLEOpenDriverDoorSts_Disable)//_ICC_BLEOpenDriverDoorEnable_Disable)
        {
    	     BLEEnable_Status = _Function_Disable;
        } 
	    #endif
        #endif
        
    
        BLEEnable_DataStream <<=1;
    	BLEEnable_Real_Status = TRUE;
	BLEEnable_Real_Timer = K_BLEEnable_Real_Timeout;  
    }

    /*Real-time Monitor*/
    if(TRUE == BLEEnable_Real_Status)
    {
         if(BLEEnable_Real_Timer == 0)
         {
	      BLEEnable_Real_Status = FALSE;   
         }
         else
         {
	      BLEEnable_Real_Timer --;
         }
    } 
}
#endif
#ifdef _CONFIG_VoiceEnable
/*********************************************************************************************
** Name:	  MessageDebounce_VoiceEnable(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_VoiceEnable(void)
{

}
#endif
#ifdef _CONFIG_BrakeEnable
/*********************************************************************************************
** Name:	  MessageDebounce_BrakeEnable(void);
** Function:
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_BrakeEnable(void)
{

}
#endif
#ifdef _CONFIG_RKEEnable
/*********************************************************************************************
** Name:	  MessageDebounce_RKEEnable(void);
** Function:
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_RKEEnable(void)
{

}
#endif


#ifdef _CONFIG_DoorPowerMode
/*********************************************************************************************
** Name:	  MessageDebounce_DoorPowerMode(void);
** Function:
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_DoorPowerMode(void)
{

}
#endif


#ifdef _CONFIG_ManualOperateEnable
/*********************************************************************************************
** Name:	  MessageDebounce_ManualOperateEnable(void);
** Function:
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_ManualOperateEnable(void)
{
    static uint16_t ManualOperateEnable_Real_Timer;

    if(TRUE == MessageRx_ManualOperateEnable_Ind)
    {  
	 MessageRx_ManualOperateEnable_Ind = FALSE;
    
        #ifdef _CHERY_COM
	    #ifdef _CHERY_COM_PD
        if(MessageRx_ManualOperateEnable == _ICC_DoorRemoteKeyControlEnable_Enable)
	{
             ManualOperateEnable_Status = _Function_Enable;
        }
        else if(MessageRx_ManualOperateEnable == _ICC_DoorRemoteKeyControlEnable_Disable)
        {
    	     ManualOperateEnable_Status = _Function_Disable;
        }
	    #endif
        #endif

	#ifdef _AUDI_COM
	    #ifdef _AUDI_COM_PD
        if(MessageRx_ManualOperateEnable == MasterCmd_ServoRelease_enable)
	{    
             ManualOperateEnable_Status = TRUE;
        }
        else if(MessageRx_ManualOperateEnable == MasterCmd_ServoRelease_disable)
        {
    	     ManualOperateEnable_Status = FALSE;
        } 
	    #endif
        #endif
        
    	ManualOperateEnable_Real_Status = TRUE;
	ManualOperateEnable_Real_Timer = K_ManualOperateEnable_Real_Timeout;
    }

    /*Real-time Monitor*/
    if(TRUE == ManualOperateEnable_Real_Status)
    {
         if(ManualOperateEnable_Real_Timer == 0)
         {
	      ManualOperateEnable_Real_Status = FALSE;
         }
         else
         {
	      ManualOperateEnable_Real_Timer --;
         }
    } 
}
#endif

#ifdef _CONFIG_MotorHoldEnable
/*********************************************************************************************
** Name:	  MessageDebounce_MotorHoldEnable(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_MotorHoldEnable(void)
{
    static uint16_t MotorHoldEnable_Real_Timer;

    if(TRUE == MessageRx_MotorHoldEnable_Ind)
    {  
	 MessageRx_MotorHoldEnable_Ind = FALSE;
    
        #ifdef _CHERY_COM
	    #ifdef _CHERY_COM_PD
        if(MessageRx_MotorHoldEnable == _ICC_DoorRemoteKeyControlEnable_Enable)
	{    
             MotorHoldEnable_Status = _Function_Enable;
        }
        else if(MessageRx_MotorHoldEnable == _ICC_DoorRemoteKeyControlEnable_Disable)
        {
    	     MotorHoldEnable_Status = _Function_Disable;
        } 
	    #endif
        #endif
	#ifdef _AUDI_COM
	    #ifdef _AUDI_COM_PD
        if(MessageRx_MotorHoldEnable == MasterCmd_HoldRelease_enable)
	{    
             MotorHoldEnable_Status = TRUE;
        }
        else if(MessageRx_MotorHoldEnable == MasterCmd_HoldRelease_disable)
        {
    	     MotorHoldEnable_Status = FALSE;
        } 
	    #endif
        #endif

    	MotorHoldEnable_Real_Status = TRUE;
	MotorHoldEnable_Real_Timer = K_MotorHoldEnable_Real_Timeout;
    }

    /*Real-time Monitor*/
    if(TRUE == MotorHoldEnable_Real_Status)
    {
         if(MotorHoldEnable_Real_Timer == 0)
         {
	      MotorHoldEnable_Real_Status = FALSE;
         }
         else
         {
	      MotorHoldEnable_Real_Timer --;
         }
    } 
}
#endif


#ifdef _CONFIG_CinchEnable
/*********************************************************************************************
** Name:	  MessageDebounce_CinchEnable(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_CinchEnable(void)
{
    static uint16_t CinchEnable_Real_Timer;

    if(TRUE == MessageRx_CinchEnable_Ind)
    {  
	 MessageRx_CinchEnable_Ind = FALSE;
    
        #ifdef _VOYAH_COM
	    #ifdef _VOYAH_COM_PD
        if(MessageRx_CinchEnable == _BCM_ElectricRelseCtlSet_ON)
	{    
             CinchEnable_Status = _Function_Enable;
        }
        else if(MessageRx_CinchEnable == _BCM_ElectricRelseCtlSet_OFF)
        {
    	     CinchEnable_Status = _Function_Disable;
        } 
	    #endif
        #endif

    	CinchEnable_Real_Status = TRUE;
	CinchEnable_Real_Timer = K_CinchEnable_Real_Timeout;
    }

    /*Real-time Monitor*/
    if(TRUE == CinchEnable_Real_Status)
    {
         if(CinchEnable_Real_Timer == 0)
         {
	      CinchEnable_Real_Status = FALSE;
         }
         else
         {
	      CinchEnable_Real_Timer --;
         }
    } 
}
#endif
#ifdef _CONFIG_BeltEnable
/*********************************************************************************************
** Name:	  MessageDebounce_BeltEnable(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_BeltEnable(void)
{
static uint16_t BeltEnable_Real_Timer;

    if(TRUE == MessageRx_BeltEnable_Ind)
    {  
	 MessageRx_BeltEnable_Ind = FALSE;
    
        #ifdef _VOYAH_COM
	    #ifdef _VOYAH_COM_PD
        if(MessageRx_BeltEnable == _POD_PowerDoorSetingSafeBelt_ON)
	{    
             BeltEnable_Status = _Function_Enable;
        }
        else if(MessageRx_BeltEnable == _POD_PowerDoorSetingSafeBelt_OFF)
        {
    	     BeltEnable_Status = _Function_Disable;
        } 
	    #endif
        #endif
	
    	BeltEnable_Real_Status = TRUE;
	BeltEnable_Real_Timer = K_BeltEnable_Real_Timeout;
    }

    /*Real-time Monitor*/
    if(TRUE == BeltEnable_Real_Status)
    {
         if(BeltEnable_Real_Timer == 0)
         {
	      BeltEnable_Real_Status = FALSE;
         }
         else
         {
	      BeltEnable_Real_Timer --;
         }
    } 
}
#endif
#ifdef _CONFIG_WindEnable
/*********************************************************************************************
** Name:	  MessageDebounce_WindEnable(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_WindEnable(void)
{
static uint16_t WindEnable_Real_Timer;

    if(TRUE == MessageRx_WindEnable_Ind)
    {  
	 MessageRx_WindEnable_Ind = FALSE;
    
        #ifdef _VOYAH_COM
	    #ifdef _VOYAH_COM_PD
        if(MessageRx_WindEnable == _POD_PowerDoorSetingAntiWind_ON)
	{    
             WindEnable_Status = _Function_Enable;
        }
        else if(MessageRx_WindEnable == _POD_PowerDoorSetingAntiWind_OFF)
        {
    	     WindEnable_Status = _Function_Disable;
        } 
	    #endif
        #endif
	
    	WindEnable_Real_Status = TRUE;
	WindEnable_Real_Timer = K_WindEnable_Real_Timeout;
    }

    /*Real-time Monitor*/
    if(TRUE == WindEnable_Real_Status)
    {
         if(WindEnable_Real_Timer == 0)
         {
	      WindEnable_Real_Status = FALSE;
         }
         else
         {
	      WindEnable_Real_Timer --;
         }
    } 
}
#endif
#ifdef _CONFIG_SpeedMode
/*********************************************************************************************
** Name:	  MessageDebounce_SpeedMode(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_SpeedMode(void)
{
static uint16_t SpeedMode_Real_Timer;

    if(TRUE == MessageRx_SpeedMode_Ind)
    {  
	 MessageRx_SpeedMode_Ind = FALSE;
    
        #ifdef _VOYAH_COM
	    #ifdef _VOYAH_COM_PD
        if(MessageRx_SpeedMode == _POD_DoorOpenSpdSet_fast)
	{    
             SpeedMode_Status = _SpeedMode_Fast;
        }
        else if(MessageRx_SpeedMode == _POD_DoorOpenSpdSet_normal)
        {
    	     SpeedMode_Status = _SpeedMode_Normal;
        } 
	    #endif
        #endif
	
    	SpeedMode_Real_Status = TRUE;
	SpeedMode_Real_Timer = K_SpeedMode_Real_Timeout;
    }

    /*Real-time Monitor*/
    if(TRUE == SpeedMode_Real_Status)
    {
         if(SpeedMode_Real_Timer == 0)
         {
	      SpeedMode_Real_Status = FALSE;
         }
         else
         {
	      SpeedMode_Real_Timer --;
         }
    } 
}
#endif










#ifdef _CONFIG_ConfigurationTrigger
/*********************************************************************************************
** Name:	  MessageDebounce_ConfigurationTrigger(void);
** Function:
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_ConfigurationTrigger(void)
{

}
#endif
#ifdef _CONFIG_SideDoorOpeningMode
/*********************************************************************************************
** Name:	  MessageDebounce_SideDoorOpeningMode(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_SideDoorOpeningMode(void)
{

}
#endif
#ifdef _CONFIG_LeftAndRightRudder
/*********************************************************************************************
** Name:	  MessageDebounce_LeftAndRightRudder(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_LeftAndRightRudder(void)
{

}
#endif
#ifdef _CONFIG_BNCM
/*********************************************************************************************
** Name:	  MessageDebounce_BNCM(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_BNCM(void)
{

}
#endif

#ifdef _CONFIG_FOBMode
/*********************************************************************************************
** Name:	  MessageDebounce_FOBModeA(void);
** Function:
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_FOBModeA(void)
{
     static uint16_t MessageRx_FOBModeA_1_Signal_Timer;
     static uint8_t MessageRx_FOBModeA_1_Signal_Timer_Status;
     static uint16_t MessageRx_FOBModeA_2_Signal_Timer;
     static uint8_t MessageRx_FOBModeA_2_Signal_Timer_Status;

     if(TRUE == MessageRx_FOBModeA_1_Signal_Ind)
     {
	  MessageRx_FOBModeA_1_Signal_Ind = FALSE;
	  if((MessageRx_FOBModeA_1_Signal == _CLRAF_Unl_Lk_Unlock)
	     && (TRUE == MessageRx_FOBModeA_1_Signal_Valid))
	  {
	       MessageRx_FOBModeA_1_Signal_Timer_Status = TRUE;
	       MessageRx_FOBModeA_1_Signal_Timer = 0;
	  }
     }

     if(TRUE == MessageRx_FOBModeA_1_Signal_Timer_Status)
     {
	  if(MessageRx_FOBModeA_1_Signal_Timer >= K_MessageRx_FOBModeA_1_Signal_Time)
	  {
		MessageRx_FOBModeA_1_Signal_Timer_Status = FALSE;
		MessageRx_FOBModeA_1_Signal_Timer = 0;
	  }
	  else
	  {
		MessageRx_FOBModeA_1_Signal_Timer ++;
	  }

	  if(TRUE == MessageRx_FOBModeA_2_Signal_Ind)
	  {
	        MessageRx_FOBModeA_2_Signal_Ind = FALSE;

		#ifdef _FOBMode_No_Activation_EngineStop
		if(((MessageRx_FOBModeA_2_Signal == _PwrLftgtMotStat_Fob_1) ||(MessageRx_FOBModeA_2_Signal == _PwrLftgtMotStat_Fob_2))
		   && (MessageRx_FOBModeA_2_Signal_Valid == _RFRmtCntrlFobFnc_No_Activation))
		{
		     MessageRx_FOBModeA_2_Signal_Timer_Status = TRUE;
	             MessageRx_FOBModeA_2_Signal_Timer = 0;

		     MessageRx_FOBModeA_1_Signal_Timer_Status = FALSE;
		     MessageRx_FOBModeA_1_Signal_Timer = 0;
		}
		#endif

		#ifdef _FOBMode_EngineStop
		if(((MessageRx_FOBModeA_2_Signal == _PwrLftgtMotStat_Fob_1) ||(MessageRx_FOBModeA_2_Signal == _PwrLftgtMotStat_Fob_2))
		   && (MessageRx_FOBModeA_2_Signal_Valid == _RFRmtCntrlFobFnc_Engine_Stop))
		{
                      FOBModeA_Status = TRUE;
		      MessageRx_FOBModeA_1_Signal_Timer_Status = FALSE;
		      MessageRx_FOBModeA_1_Signal_Timer = 0;
		}
		#endif
	  }
     }
     else if(TRUE == MessageRx_FOBModeA_2_Signal_Timer_Status)
     {
	  if(MessageRx_FOBModeA_2_Signal_Timer >= K_MessageRx_FOBModeA_2_Signal_Time)
	  {
		MessageRx_FOBModeA_2_Signal_Timer_Status = FALSE;
		MessageRx_FOBModeA_2_Signal_Timer = 0;
	  }
	  else
	  {
		MessageRx_FOBModeA_2_Signal_Timer ++;
	  }

	  if(TRUE == MessageRx_FOBModeA_2_Signal_Ind)
	  {
	        MessageRx_FOBModeA_2_Signal_Ind = FALSE;

		if(((MessageRx_FOBModeA_2_Signal == _PwrLftgtMotStat_Fob_1) ||(MessageRx_FOBModeA_2_Signal == _PwrLftgtMotStat_Fob_2))
		   && (MessageRx_FOBModeA_2_Signal_Valid == _RFRmtCntrlFobFnc_Engine_Stop))
		{
                      FOBModeA_Status = TRUE;
		      MessageRx_FOBModeA_2_Signal_Timer_Status = FALSE;
		      MessageRx_FOBModeA_2_Signal_Timer = 0;
		}
	  }
     }
     else if(TRUE == MessageRx_FOBModeA_2_Signal_Ind)
     {
	   MessageRx_FOBModeA_2_Signal_Ind = FALSE;
     }

     if(TRUE == FOBModeA_Status)
     {
	  FOBModeA_Status = FALSE;

	  if(Vehicle_FOBModeA == TRUE)
	  {
	       MessageRx_RemoteKey = TRUE;
	       MessageRx_RemoteKey_Ind = TRUE;
	  }
     }
}

/*********************************************************************************************
** Name:	  MessageDebounce_FOBModeC(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_FOBModeC(void)
{
     static uint16_t MessageRx_FOBModeC_1_Signal_Timer;
     static uint8_t MessageRx_FOBModeC_1_Signal_Timer_Status;
     static uint16_t MessageRx_FOBModeC_2_Signal_Timer;
     static uint8_t MessageRx_FOBModeC_2_Signal_Timer_Status;

     if((TRUE == MessageRx_FOBModeC_1_Signal_Ind)
        && (FALSE == MessageRx_FOBModeC_1_Signal_Timer_Status)
	&& (FALSE == MessageRx_FOBModeC_2_Signal_Timer_Status))
     {
	  MessageRx_FOBModeC_1_Signal_Ind = FALSE;
	  if((MessageRx_FOBModeC_1_Signal == _CLRAF_Unl_Lk_Unlock)
	     && (TRUE == MessageRx_FOBModeC_1_Signal_Valid))
	  {
	       MessageRx_FOBModeC_1_Signal_Timer_Status = TRUE;
	       MessageRx_FOBModeC_1_Signal_Timer = 0;
	  }
     }

     if(TRUE == MessageRx_FOBModeC_1_Signal_Timer_Status)
     {
	  if(MessageRx_FOBModeC_1_Signal_Timer >= K_MessageRx_FOBModeC_1_Signal_Time)
	  {
		MessageRx_FOBModeC_1_Signal_Timer_Status = FALSE;
		MessageRx_FOBModeC_1_Signal_Timer = 0;
	  }
	  else
	  {
		MessageRx_FOBModeC_1_Signal_Timer ++;
	  }

	  if(TRUE == MessageRx_FOBModeC_1_Signal_Ind)
	  {
	        MessageRx_FOBModeC_1_Signal_Ind = FALSE;

		if((MessageRx_FOBModeC_1_Signal == _CLRAF_Unl_Lk_Lock)
	          && (TRUE == MessageRx_FOBModeC_1_Signal_Valid))
	        {
		      MessageRx_FOBModeC_2_Signal_Timer_Status = TRUE;
	              MessageRx_FOBModeC_2_Signal_Timer = 0;

	              MessageRx_FOBModeC_1_Signal_Timer_Status = FALSE;
	              MessageRx_FOBModeC_1_Signal_Timer = 0;
	        }
	  }
     }
     else if(TRUE == MessageRx_FOBModeC_2_Signal_Timer_Status)
     {
	  if(MessageRx_FOBModeC_2_Signal_Timer >= K_MessageRx_FOBModeC_2_Signal_Time)
	  {
		MessageRx_FOBModeC_2_Signal_Timer_Status = FALSE;
		MessageRx_FOBModeC_2_Signal_Timer = 0;
	  }
	  else
	  {
		MessageRx_FOBModeC_2_Signal_Timer ++;
	  }

	  if(TRUE == MessageRx_FOBModeC_1_Signal_Ind)
	  {
	        MessageRx_FOBModeC_1_Signal_Ind = FALSE;

		if((MessageRx_FOBModeC_1_Signal == _CLRAF_Unl_Lk_Unlock)
	          && (TRUE == MessageRx_FOBModeC_1_Signal_Valid))
	        {
		      FOBModeC_Status = TRUE;

		      MessageRx_FOBModeC_2_Signal_Timer_Status = TRUE;
	              MessageRx_FOBModeC_2_Signal_Timer = 0;

	              MessageRx_FOBModeC_1_Signal_Timer_Status = FALSE;
	              MessageRx_FOBModeC_1_Signal_Timer = 0;
	        }
	  }
     }
     /*Reset Ind*/
     else if(TRUE == MessageRx_FOBModeC_1_Signal_Ind)
     {
	   MessageRx_FOBModeC_1_Signal_Ind = FALSE;
     }

     if(TRUE == FOBModeC_Status)
     {
	  FOBModeC_Status = FALSE;

	  if(Vehicle_FOBModeC == TRUE)
	  {
	       MessageRx_RemoteKey = TRUE;
	       MessageRx_RemoteKey_Ind = TRUE;
	  }
     }
}
/*********************************************************************************************
** Name:	  MessageDebounce_FOBModeB(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_FOBModeB(void)
{
     static uint16_t MessageRx_FOBModeB_1_Signal_Timer;
     static uint8_t MessageRx_FOBModeB_1_Signal_Timer_Status;
     static uint16_t MessageRx_FOBModeB_2_Signal_Timer;
     static uint8_t MessageRx_FOBModeB_2_Signal_Timer_Status;
     static uint16_t MessageRx_FOBModeB_3_Signal_Timer;
     static uint8_t MessageRx_FOBModeB_3_Signal_Timer_Status;

     if(TRUE == MessageRx_FOBModeB_1_Signal_Ind)
     {
	  MessageRx_FOBModeB_1_Signal_Ind = FALSE;
	  if((MessageRx_FOBModeB_1_Signal == _CLRAF_Unl_Lk_Unlock)
	     && (TRUE == MessageRx_FOBModeB_1_Signal_Valid))
	  {
	       MessageRx_FOBModeB_1_Signal_Timer_Status = TRUE;
	       MessageRx_FOBModeB_1_Signal_Timer = 0;
	  }
     }

     if(TRUE == MessageRx_FOBModeB_1_Signal_Timer_Status)
     {
	  if(MessageRx_FOBModeB_1_Signal_Timer >= K_MessageRx_FOBModeB_1_Signal_Time)
	  {
		MessageRx_FOBModeB_1_Signal_Timer_Status = FALSE;
		MessageRx_FOBModeB_1_Signal_Timer = 0;
	  }
	  else
	  {
		MessageRx_FOBModeB_1_Signal_Timer ++;
	  }

	  if(TRUE == MessageRx_FOBModeB_2_Signal_Ind)
	  {
	        MessageRx_FOBModeB_2_Signal_Ind = FALSE;

		if(((MessageRx_FOBModeB_2_Signal == _PwrLftgtMotStat_Fob_1) ||(MessageRx_FOBModeB_2_Signal == _PwrLftgtMotStat_Fob_2))
		   && (MessageRx_FOBModeB_2_Signal_Valid == _RFRmtCntrlFobFnc_No_Activation))
		{
		     MessageRx_FOBModeB_2_Signal_Timer_Status = TRUE;
	             MessageRx_FOBModeB_2_Signal_Timer = 0;
		     
		     MessageRx_FOBModeB_1_Signal_Timer_Status = FALSE;
		     MessageRx_FOBModeB_1_Signal_Timer = 0;
		}
	  }
     }
     else if(TRUE == MessageRx_FOBModeB_2_Signal_Timer_Status)
     {
	  if(MessageRx_FOBModeB_2_Signal_Timer >= K_MessageRx_FOBModeB_2_Signal_Time)
	  {
		MessageRx_FOBModeB_2_Signal_Timer_Status = FALSE;
		MessageRx_FOBModeB_2_Signal_Timer = 0;
	  }
	  else
	  {
		MessageRx_FOBModeB_2_Signal_Timer ++;
	  }

	  if(TRUE == MessageRx_FOBModeB_2_Signal_Ind)
	  {
	        MessageRx_FOBModeB_2_Signal_Ind = FALSE;

		if(((MessageRx_FOBModeB_2_Signal == _PwrLftgtMotStat_Fob_1) ||(MessageRx_FOBModeB_2_Signal == _PwrLftgtMotStat_Fob_2))
		   && (MessageRx_FOBModeB_2_Signal_Valid == _RFRmtCntrlFobFnc_No_Activation))
		{
                      //FOBModeB_Status = TRUE;
		      MessageRx_FOBModeB_2_Signal_Timer_Status = FALSE;
		      MessageRx_FOBModeB_2_Signal_Timer = 0;

		      MessageRx_FOBModeB_3_Signal_Timer_Status = TRUE;
	              MessageRx_FOBModeB_3_Signal_Timer = 0;
		}
	  }
     }
     /*Short Press and Long Press is forbidden*/
     else if(TRUE == MessageRx_FOBModeB_3_Signal_Timer_Status)
     {
	  if(MessageRx_FOBModeB_3_Signal_Timer >= K_MessageRx_FOBModeB_3_Signal_Time)
	  {
		MessageRx_FOBModeB_3_Signal_Timer_Status = FALSE;
		MessageRx_FOBModeB_3_Signal_Timer = 0;

		if(FALSE == MessageRx_FOBModeB_2_Signal_Ind)
		{
		      FOBModeB_Status = TRUE;
		}
	  }
	  else
	  {
		MessageRx_FOBModeB_3_Signal_Timer ++;
	  }
     }
     /*Reset Ind*/
     else if(TRUE == MessageRx_FOBModeB_2_Signal_Ind)
     {
	   MessageRx_FOBModeB_2_Signal_Ind = FALSE;
     }

     if(TRUE == FOBModeB_Status)
     {
	  FOBModeB_Status = FALSE;

	  if(Vehicle_FOBModeB == TRUE)
	  {
	       MessageRx_RemoteKey = TRUE;
	       MessageRx_RemoteKey_Ind = TRUE;
	  }
     }
}
#endif

#ifdef _CONFIG_RemoteKey
/*********************************************************************************************
** Name:	  MessageDebounce_RemoteKey(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_RemoteKey(void)
{
     static uint16_t RemoteKey_Timer = 0;
     static uint16_t RemoteKey_LongPress_Status = 0;
     static uint16_t RemoteKey_LongPress_LastStatus = 0;
     static uint16_t RemoteKey_Real_Timer;

    /* RemoteKey Status Active monitor */
    RemoteKey_LastStatus = RemoteKey_Status;
    
    if(TRUE == MessageRx_RemoteKey_Ind)
    {  
	MessageRx_RemoteKey_Ind = FALSE;
        
        #ifdef _SGMW_COM
        if(MessageRx_RemoteKey == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _SGM_COM
        if(MessageRx_RemoteKey == TRUE) /* TRUE or Active, based on Message define*/
        #endif
        #ifdef _CHERY_COM
        if(MessageRx_RemoteKey == TRUE) /* TRUE or Active, based on Message define*/
        #endif
        #ifdef _CTCS_COM
        if(MessageRx_RemoteKey == TRUE) /* TRUE or Active, based on Message define*/
        #endif
        #ifdef _DEARCC_COM
        if(MessageRx_RemoteKey == _RKE_TRUNK_UNLOCK) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _XIAOPENG_COM
        if(MessageRx_RemoteKey == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _MAXUS_COM
        if(MessageRx_RemoteKey == _RKECmd_Tailgate) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _DFMC_COM
        if(MessageRx_RemoteKey == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _BAIC_COM
	    #if defined(_BAIC_COM_C52X) || defined(_BAIC_COM_C62X)
        if(MessageRx_RemoteKey == _RemKeyFctForLock_TailgateRelease) /* TRUE or Active, based on Message define*/
	    #endif
	    #if defined(_BAIC_COM_C46DB) || defined(_BAIC_COM_B30X)
        if(MessageRx_RemoteKey == _KeyFctCmdCod_TailgateRelease) /* TRUE or Active, based on Message define*/
	    #endif
        #endif
	#ifdef _DFLZM_COM
        if(MessageRx_RemoteKey == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _NIU_COM
        if(MessageRx_RemoteKey == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _FAW_COM
        if(MessageRx_RemoteKey == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _CHANGAN_COM
        if(MessageRx_RemoteKey == TRUE) /* TRUE or Active, based on Message define*/
        #endif
        {
	     RemoteKey_DataStream |= 0x0001;
        }
        if((MASK01BIT & RemoteKey_DataStream) == MASK01BIT)
        {    
             RemoteKey_Status = TRUE;
        }
        else if((MASK01BIT & RemoteKey_DataStream) == 0)
        {
    	     RemoteKey_Status = FALSE;
        }
    
        RemoteKey_DataStream <<=1;
    	RemoteKey_Real_Status = TRUE;
	RemoteKey_Real_Timer = K_RemoteKey_Real_Timeout;
    }
    /*Real-time Monitor*/
    if(TRUE == RemoteKey_Real_Status)
    {
         if(RemoteKey_Real_Timer == 0)
         {
	      RemoteKey_Real_Status = FALSE;
	      if(TRUE == K_RemoteKey_SingleEvent_Enable) /*10,1110 is MultiEvent, 1,111 is SingleEvent */
	      {
		   RemoteKey_SingleEvent_Enable = TRUE;
	      }
	      if(TRUE == RemoteKey_SingleEvent_Enable)
	      {
		   RemoteKey_SingleEvent_Enable = FALSE;
		   RemoteKey_Status = FALSE;
		   MessageRx_RemoteKey = FALSE;
	      }
         }
         else
         {
	      RemoteKey_Real_Timer --;
         }
    } 
  
    /* RemoteKey RiseEdge and FallEdge Active monitor */
    if((FALSE == RemoteKey_Status) && (TRUE == RemoteKey_LastStatus))
    {
    	 RemoteKey_RiseEdge_Active = TRUE;
    } 
    else
    {
    	 RemoteKey_RiseEdge_Active = FALSE;
    }
 
    if((TRUE == RemoteKey_Status) && (FALSE == RemoteKey_LastStatus))
    {
	 RemoteKey_FallEdge_Active = TRUE;

    }	 
    else
    {
	 RemoteKey_FallEdge_Active = FALSE;
    }	

    /* RemoteKey_ShortPress_Active monitor */
    RemoteKey_ShortPress_LastStatus = RemoteKey_ShortPress_Status;
    if((RemoteKey_Timer >= K_RemoteKey_ShortPress_LowLimit_Time)
      && (RemoteKey_Timer < K_RemoteKey_ShortPress_HighLimit_Time))
    {
	 RemoteKey_ShortPress_Status = TRUE;
    }
    else
    {
	 RemoteKey_ShortPress_Status = FALSE;
    }

    if((TRUE == RemoteKey_RiseEdge_Active) && (TRUE == RemoteKey_ShortPress_Status))
    {
	 RemoteKey_ShortPress_Active = TRUE;

    }
    else
    {
	 RemoteKey_ShortPress_Active = FALSE;
    }
	
   /* RemoteKey_LongPress_Active monitor */
    RemoteKey_LongPress_LastStatus = RemoteKey_LongPress_Status;
    if((RemoteKey_Timer >= K_RemoteKey_LongPress_LowLimit_Time)
      && (RemoteKey_Timer < K_RemoteKey_LongPress_HighLimit_Time))
    {
	 RemoteKey_LongPress_Status = TRUE;
    }
    else
    {
	 RemoteKey_LongPress_Status = FALSE;
    }

    if((TRUE == RemoteKey_LongPress_Status) && (FALSE == RemoteKey_LongPress_LastStatus))
    {
	 RemoteKey_LongPress_Active = TRUE;
    }
    else
    {
	 RemoteKey_LongPress_Active = FALSE;
    }

    /* Reset RemoteKey_Timer */
    if(TRUE == RemoteKey_Status)
    {
	 if(RemoteKey_Timer < MAXVALUE16BIT)
	 {
              RemoteKey_Timer ++;
	 }
    }
    if(FALSE == RemoteKey_Status)
    {
         RemoteKey_Timer = 0;
    }
}
#endif
#ifdef _CONFIG_FobShortPress
/*********************************************************************************************
** Name:	  MessageDebounce_FobShortPress(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_FobShortPress(void)
{
    static uint16_t FobShortPress_Real_Timer;
    
  /* FobShortPress Status Active monitor */
    FobShortPress_LastStatus = FobShortPress_Status;
    
    if(TRUE == MessageRx_FobShortPress_Ind)
    {  
	MessageRx_FobShortPress_Ind = FALSE;
        
        #ifdef _CHERY_COM
	    #ifdef _CHERY_COM_PLG
        if(MessageRx_FobShortPress == _RKE_TrunkSts_Short_Press)
	    #endif
	    #ifdef _CHERY_COM_PD
        if(((MessageRx_FobShortPress == _BNCM_14_UnLockButtAct_UnLockButt_SinglePress)
	    ||(MessageRx_FobShortPress == _BNCM_14_LockButtAct_LockButt_SinglePress)) && (_Function_Enable == RKEEnable_Status))// || (MessageRx_RKEStopOpen == _BNCM_14_UnLockButtAct_UnLockButt_DoublePress)
	    #endif
        #endif
        #ifdef _SGMW_COM
        if(MessageRx_FobShortPress == _FOB_TRUNK_OPEN_SHORT_PRESS)
        #endif
	#ifdef _SGM_COM
        if(MessageRx_FobShortPress == _RFRmtCntrlFobFnc_Pwr_Rr_Closure_Stop_Motion_Control) /* TRUE or Active, based on Message define*/
        #endif
        #ifdef _CTCS_COM
	      #ifdef _CONFIG_CAN_Bus
              if(MessageRx_FobShortPress == _RKE_TRUNK_STOP)
	      #endif
	      #ifdef _CONFIG_LIN_Slave
	      if(MessageRx_FobShortPress == _FOB_STOP)
	      #endif
        #endif
        #ifdef _DEARCC_COM
        if(MessageRx_FobShortPress == _FOB_SHORT_PRESSED)
        #endif
	#ifdef _XIAOPENG_COM
        if(MessageRx_FobShortPress == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _MAXUS_COM
            #ifdef _MAXUS_COM_PLG
        if(MessageRx_FobShortPress == _RKELckCmd_Tailgate)
	    #endif
	    #ifdef _MAXUS_COM_PSD
	        #ifdef _MAXUS_COM_PSD_R
        if(MessageRx_FobShortPress == _RKELckCmd_Sliding_Door_Right)
	        #endif
		#ifdef _MAXUS_COM_PSD_L
        if(MessageRx_FobShortPress == _RKELckCmd_Sliding_Door_Left)
	        #endif
	    #endif
	#endif
	#ifdef _DFMC_COM
        if(MessageRx_FobShortPress == _bcm_rkeTailgateCtrlCmd_Pressed_Once) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _BAIC_COM
        if(MessageRx_FobShortPress == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _DFLZM_COM
        if(MessageRx_FobShortPress == _PEPS1_Statue_RKE_BackDoorKey_Short_Press) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _NIU_COM
        if(MessageRx_FobShortPress == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _FAW_COM
        if(MessageRx_FobShortPress == _RKE_STOP) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _CHANGAN_COM
        if(MessageRx_FobShortPress == TRUE) /* TRUE or Active, based on Message define*/
        #endif
        {
	    FobShortPress_DataStream |= 0x0001;
        }
        if((MASK01BIT & FobShortPress_DataStream) == MASK01BIT)
        {    
            FobShortPress_Status = TRUE;
        }
        else if((MASK01BIT & FobShortPress_DataStream) == 0)
        {
    	    FobShortPress_Status = FALSE;
        }
    
        FobShortPress_DataStream <<=1;
    	FobShortPress_Real_Status = TRUE;
	FobShortPress_Real_Timer = K_FobShortPress_Real_Timeout;
    }
    /*Real-time Monitor*/
    if(TRUE == FobShortPress_Real_Status)
    {
         if(FobShortPress_Real_Timer == 0)
         {
	      FobShortPress_Real_Status = FALSE;
	      if(TRUE == K_FobShortPress_SingleEvent_Enable) /*10,1110 is MultiEvent, 1,111 is SingleEvent */
	      {
		   FobShortPress_SingleEvent_Enable = TRUE;
	      }
	      if(TRUE == FobShortPress_SingleEvent_Enable)
	      {
		   FobShortPress_SingleEvent_Enable = FALSE;
		   FobShortPress_Status = FALSE;
		   MessageRx_FobShortPress = FALSE;
	      }
         }
         else
         {
	      FobShortPress_Real_Timer --;
         }
    } 
    /* FobShortPress RiseEdge and FallEdge Active monitor */
    if((FALSE == FobShortPress_Status) && (TRUE == FobShortPress_LastStatus))
    {
    	 FobShortPress_RiseEdge_Active = TRUE;
    } 
    else
    {
    	 FobShortPress_RiseEdge_Active = FALSE;
    }
 
    if((TRUE == FobShortPress_Status) && (FALSE == FobShortPress_LastStatus))
    {
	 FobShortPress_FallEdge_Active = TRUE;

    }	 
    else
    {
	 FobShortPress_FallEdge_Active = FALSE;
    }
}
#endif
#ifdef _CONFIG_FobLongPress
/*********************************************************************************************
** Name:	  MessageDebounce_FobLongPress(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_FobLongPress(void)
{
    static uint16_t FobLongPress_Real_Timer;
    
  /* FobLongPress Status Active monitor */
    FobLongPress_LastStatus = FobLongPress_Status;
    if(TRUE == MessageRx_FobLongPress_Ind)
    {  
	MessageRx_FobLongPress_Ind = FALSE;
        
        #ifdef _CHERY_COM
	    #ifdef _CHERY_COM_PLG
        if(MessageRx_FobLongPress == _RKE_TrunkSts_Long_Press)
	    #endif
	    #ifdef _CHERY_COM_PD
        if(MessageRx_FobLongPress == TRUE)
	    #endif
        #endif
        #ifdef _SGMW_COM
        if(MessageRx_FobLongPress == _FOB_TRUNK_OPEN_LONG_PRESS)
        #endif
	#ifdef _SGM_COM
        if(MessageRx_FobLongPress == _RFRmtCntrlFobFnc_Pwr_Rr_Closure_Start_Motion_Control) /* TRUE or Active, based on Message define*/
        #endif
        #ifdef _CTCS_COM
	      #ifdef _CONFIG_CAN_Bus
              if(MessageRx_FobLongPress == _RKE_TRUNK_UNLOCK)
	      #endif
	      #ifdef _CONFIG_LIN_Slave
	      if(MessageRx_FobLongPress == _FOB_ACTION)
	      #endif
        #endif
        #ifdef _DEARCC_COM
        if(MessageRx_FobLongPress == _RKE_DOOR_UNLOCK)
        #endif
	#ifdef _XIAOPENG_COM
        if(MessageRx_FobLongPress == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _MAXUS_COM
	    #ifdef _MAXUS_COM_PLG
        if(MessageRx_FobLongPress == _RKELckCmd_Tailgate_Long_Pressed) /* TRUE or Active, based on Message define*/
	    #endif
	    #ifdef _MAXUS_COM_PSD
	        #ifdef _MAXUS_COM_PSD_R
        if(MessageRx_FobLongPress == _RKELckCmd_Sliding_Door_Right_Long_Pressed) /* TRUE or Active, based on Message define*/
	        #endif
		#ifdef _MAXUS_COM_PSD_L
        if(MessageRx_FobLongPress == _RKELckCmd_Sliding_Door_Left_Long_Pressed) /* TRUE or Active, based on Message define*/
	        #endif
	    #endif
        #endif
	#ifdef _DFMC_COM
        if(MessageRx_FobLongPress == _bcm_rkeTailgateCtrlCmd_Pressed_LongerThan2Second) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _BAIC_COM
        if(MessageRx_FobLongPress == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _DFLZM_COM
        if(MessageRx_FobLongPress == _PEPS1_Statue_RKE_BackDoorKey_Long_Press) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _NIU_COM
        if(MessageRx_FobLongPress == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _FAW_COM
        if(MessageRx_FobLongPress == _RKE_ACTION) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _CHANGAN_COM
        if(MessageRx_FobLongPress == TRUE) /* TRUE or Active, based on Message define*/
        #endif
        {
	     FobLongPress_DataStream |= 0x0001;
        }
        if((MASK01BIT & FobLongPress_DataStream) == MASK01BIT)
        {    
             FobLongPress_Status = TRUE;
        }
        else if((MASK01BIT & FobLongPress_DataStream) == 0)
        {
    	     FobLongPress_Status = FALSE;
        }
    
        FobLongPress_DataStream <<=1;
    	FobLongPress_Real_Status = TRUE;
	FobLongPress_Real_Timer = K_FobLongPress_Real_Timeout;
    }
    /*Real-time Monitor*/
    if(TRUE == FobLongPress_Real_Status)
    {
         if(FobLongPress_Real_Timer == 0)
         {
	      FobLongPress_Real_Status = FALSE;
	      if(TRUE == K_FobLongPress_SingleEvent_Enable) /*10,1110 is MultiEvent, 1,111 is SingleEvent */
	      {
		   FobLongPress_SingleEvent_Enable = TRUE;
	      }
	      if(TRUE == FobLongPress_SingleEvent_Enable)
	      {
		   FobLongPress_SingleEvent_Enable = FALSE;
		   FobLongPress_Status = FALSE;
		   MessageRx_FobLongPress = FALSE;
	      }
         }
         else
         {
	      FobLongPress_Real_Timer --;
         }
    } 
  
    /* FobLongPress RiseEdge and FallEdge Active monitor */
    if((FALSE == FobLongPress_Status) && (TRUE == FobLongPress_LastStatus))
    {
    	 FobLongPress_RiseEdge_Active = TRUE;
    } 
    else
    {
    	 FobLongPress_RiseEdge_Active = FALSE;
    }
 
    if((TRUE == FobLongPress_Status) && (FALSE == FobLongPress_LastStatus))
    {
	 FobLongPress_FallEdge_Active = TRUE;

    }	 
    else
    {
	 FobLongPress_FallEdge_Active = FALSE;
    }

}
#endif
#ifdef _CONFIG_KickSensor
/*********************************************************************************************
** Name:	  MessageDebounce_KickSensor(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_KickSensor(void)
{
    static uint16_t KickSensor_Real_Timer;
    
  /* KickSensor Status Active monitor */
    KickSensor_LastStatus = KickSensor_Status;

    if(TRUE == MessageRx_KickSensor_Ind)
    {  
	MessageRx_KickSensor_Ind = FALSE;
        
        #ifdef _SGMW_COM
	if(ActiveSystemMode == SystemClosedFully)
	{
           if(MessageRx_KickSensor == _DOOR_PEPS_KICKSNS)
	   {
	       KickSensor_DataStream |= 0x0001;
           }
	}
	else
	{
	   if(MessageRx_KickSensor == TRUE)
	   {
	       KickSensor_DataStream |= 0x0001;
           }
	}
        #endif
	#ifdef _SGM_COM
        if(MessageRx_KickSensor == TRUE) /* TRUE or Active, based on Message define*/
	{
	     KickSensor_DataStream |= 0x0001;
        }
	#endif
        #ifdef _CHERY_COM
        if((MessageRx_KickSensor == TRUE) && ((VehiclePowerMode == PowerMode_OFF) || (TRUE == VehicleRemoteMode_Status))) /* TRUE or Active, based on Message define*/
	{
	     KickSensor_DataStream |= 0x0001;
        }
        #endif
        #ifdef _CTCS_COM
        if(MessageRx_KickSensor == _RKE_TRUNK_STOP) /* TRUE or Active, based on Message define*/
	{
	     KickSensor_DataStream |= 0x0001;
        }
        #endif
        #ifdef _DEARCC_COM
        if(MessageRx_KickSensor == TRUE) /* TRUE or Active, based on Message define*/
	{
	     KickSensor_DataStream |= 0x0001;
        }
        #endif
	#ifdef _XIAOPENG_COM
        if(MessageRx_KickSensor == TRUE) /* TRUE or Active, based on Message define*/
	{
	     KickSensor_DataStream |= 0x0001;
        }
        #endif
	#ifdef _MAXUS_COM
        if(MessageRx_KickSensor == TRUE) /* TRUE or Active, based on Message define*/
	{
	     KickSensor_DataStream |= 0x0001;
        }
        #endif
	#ifdef _DFMC_COM
        if(MessageRx_KickSensor == _bcm_kickActiveReq_KICK_MOVEMENT_DETECTED) /* TRUE or Active, based on Message define*/
	{
	     KickSensor_DataStream |= 0x0001;
        }
        #endif
	#ifdef _BAIC_COM
        if(MessageRx_KickSensor == TRUE) /* TRUE or Active, based on Message define*/
	{
	     KickSensor_DataStream |= 0x0001;
        }
        #endif
	#ifdef _DFLZM_COM
        if(MessageRx_KickSensor == _PEPS2_Status_KS_ActvInactv_Active) /* TRUE or Active, based on Message define*/
	{
	     KickSensor_DataStream |= 0x0001;
        }
        #endif
	#ifdef _NIU_COM
        if(MessageRx_KickSensor == TRUE) /* TRUE or Active, based on Message define*/
	{
	     KickSensor_DataStream |= 0x0001;
        }
	#endif
	#ifdef _FAW_COM
        if(MessageRx_KickSensor == TRUE) /* TRUE or Active, based on Message define*/
	{
	     KickSensor_DataStream |= 0x0001;
        }
        #endif
	#ifdef _CHANGAN_COM
        if(MessageRx_KickSensor == _PEPS_EASY_OPEN_ACTIVE) /* TRUE or Active, based on Message define*/
	{
	     KickSensor_DataStream |= 0x0001;
        }
        #endif
        if((MASK01BIT & KickSensor_DataStream) == MASK01BIT)
        {    
             KickSensor_Status = TRUE;
        }
        else if((MASK01BIT & KickSensor_DataStream) == 0)
        {
    	     KickSensor_Status = FALSE;
        }
    
        KickSensor_DataStream <<=1;
    	KickSensor_Real_Status = TRUE;
	KickSensor_Real_Timer = K_KickSensor_Real_Timeout;
    }
    /*Real-time Monitor*/
    if(TRUE == KickSensor_Real_Status)
    {
         if(KickSensor_Real_Timer == 0)
         {
	      KickSensor_Real_Status = FALSE;
	      if(TRUE == K_KickSensor_SingleEvent_Enable) /*10,1110 is MultiEvent, 1,111 is SingleEvent */
	      {
		   KickSensor_SingleEvent_Enable = TRUE;
	      }
	      if(TRUE == KickSensor_SingleEvent_Enable)
	      {
		   KickSensor_SingleEvent_Enable = FALSE;
		   KickSensor_Status = FALSE;
		   MessageRx_KickSensor = FALSE;
	      }
         }
         else
         {
	      KickSensor_Real_Timer --;
         }
    } 
  
    /* KickSensor RiseEdge and FallEdge Active monitor */
    if((FALSE == KickSensor_Status) && (TRUE == KickSensor_LastStatus))
    {
    	 KickSensor_RiseEdge_Active = TRUE;
    } 
    else
    {
    	 KickSensor_RiseEdge_Active = FALSE;
    }
 
    if((TRUE == KickSensor_Status) && (FALSE == KickSensor_LastStatus))
    {
	 KickSensor_FallEdge_Active = TRUE;

    }	 
    else
    {
	 KickSensor_FallEdge_Active = FALSE;
    }

}
#endif

#ifdef _CONFIG_RemindStart
/*********************************************************************************************
** Name:	  MessageDebounce_RemindStart(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_RemindStart(void)
{
    static uint16_t RemindStart_Real_Timer;

  /* RemindStart Status Active monitor */
    RemindStart_LastStatus = RemindStart_Status;
    
    if(TRUE == MessageRx_RemindStart_Ind)
    {  
	MessageRx_RemindStart_Ind = FALSE;
        
        #ifdef _SGMW_COM
        if(MessageRx_RemindStart == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _SGM_COM
        if(MessageRx_RemindStart == TRUE) /* TRUE or Active, based on Message define*/
        #endif
        #ifdef _CHERY_COM
        if(MessageRx_RemindStart == TRUE) /* TRUE or Active, based on Message define*/
        #endif
        #ifdef _CTCS_COM
        if(MessageRx_RemindStart == _SATO_REMIND_START) /* TRUE or Active, based on Message define*/
        #endif
        #ifdef _DEARCC_COM
        if(MessageRx_RemindStart == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _XIAOPENG_COM
        if(MessageRx_RemindStart == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _MAXUS_COM
        if(MessageRx_RemindStart == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _DFMC_COM
        if(MessageRx_RemindStart == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _BAIC_COM
        if(MessageRx_RemindStart == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _DFLZM_COM
        if(MessageRx_RemindStart == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _NIU_COM
        if(MessageRx_RemindStart == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _FAW_COM
        if(MessageRx_RemindStart == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _CHANGAN_COM
        if(MessageRx_RemindStart == TRUE) /* TRUE or Active, based on Message define*/
        #endif
        {
	     RemindStart_DataStream |= 0x0001;
        }
        if((MASK01BIT & RemindStart_DataStream) == MASK01BIT)
        {    
             RemindStart_Status = TRUE;
        }
        else if((MASK01BIT & RemindStart_DataStream) == 0)
        {
    	     RemindStart_Status = FALSE;
        }
    
        RemindStart_DataStream <<=1;
    	RemindStart_Real_Status = TRUE;
	RemindStart_Real_Timer = K_RemindStart_Real_Timeout;
    }
    /*Real-time Monitor*/
    if(TRUE == RemindStart_Real_Status)
    {
         if(RemindStart_Real_Timer == 0)
         {
	      RemindStart_Real_Status = FALSE;
	      if(TRUE == K_RemindStart_SingleEvent_Enable) /*10,1110 is MultiEvent, 1,111 is SingleEvent */
	      {
		   RemindStart_SingleEvent_Enable = TRUE;
	      }
	      if(TRUE == RemindStart_SingleEvent_Enable)
	      {
		   RemindStart_SingleEvent_Enable = FALSE;
		   RemindStart_Status = FALSE;
		   MessageRx_RemindStart = FALSE;
	      }
         }
         else
         {
	      RemindStart_Real_Timer --;
         }
    } 
  
    /* RemindStart RiseEdge and FallEdge Active monitor */
    if((FALSE == RemindStart_Status) && (TRUE == RemindStart_LastStatus))
    {
    	 RemindStart_RiseEdge_Active = TRUE;
    } 
    else
    {
    	 RemindStart_RiseEdge_Active = FALSE;
    }
 
    if((TRUE == RemindStart_Status) && (FALSE == RemindStart_LastStatus))
    {
	 RemindStart_FallEdge_Active = TRUE;

    }	 
    else
    {
	 RemindStart_FallEdge_Active = FALSE;
    }
}
#endif
#ifdef _CONFIG_RemindStop
/*********************************************************************************************
** Name:	  MessageDebounce_RemindStop(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_RemindStop(void)
{
    static uint16_t RemindStop_Real_Timer;

    /* RemindStop Status Active monitor */
    RemindStop_LastStatus = RemindStop_Status;
    
    if(TRUE == MessageRx_RemindStop_Ind)
    {  
	MessageRx_RemindStop_Ind = FALSE;
        
        #ifdef _SGMW_COM
        if(MessageRx_RemindStop == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _SGM_COM
        if(MessageRx_RemindStop == TRUE) /* TRUE or Active, based on Message define*/
        #endif
        #ifdef _CHERY_COM
        if(MessageRx_RemindStop == TRUE) /* TRUE or Active, based on Message define*/
        #endif
        #ifdef _CTCS_COM
        if(MessageRx_RemindStop == _SATO_REMIND_STOP) /* TRUE or Active, based on Message define*/
        #endif
        #ifdef _DEARCC_COM
        if(MessageRx_RemindStop == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _XIAOPENG_COM
        if(MessageRx_RemindStop == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _MAXUS_COM
        if(MessageRx_RemindStop == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _DFMC_COM
        if(MessageRx_RemindStop == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _BAIC_COM
        if(MessageRx_RemindStop == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _DFLZM_COM
        if(MessageRx_RemindStop == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _NIU_COM
        if(MessageRx_RemindStop == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _FAW_COM
        if(MessageRx_RemindStop == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _CHANGAN_COM
        if(MessageRx_RemindStop == TRUE) /* TRUE or Active, based on Message define*/
        #endif
        {
	     RemindStop_DataStream |= 0x0001;
        }
        if((MASK01BIT & RemindStop_DataStream) == MASK01BIT)
        {    
             RemindStop_Status = TRUE;
        }
        else if((MASK01BIT & RemindStop_DataStream) == 0)
        {
    	     RemindStop_Status = FALSE;
        }
    
        RemindStop_DataStream <<=1;
    	RemindStop_Real_Status = TRUE;
	RemindStop_Real_Timer = K_RemindStop_Real_Timeout;
    }
    /*Real-time Monitor*/
    if(TRUE == RemindStop_Real_Status)
    {
         if(RemindStop_Real_Timer == 0)
         {
	      RemindStop_Real_Status = FALSE;
	      if(TRUE == K_RemindStop_SingleEvent_Enable) /*10,1110 is MultiEvent, 1,111 is SingleEvent */
	      {
		   RemindStop_SingleEvent_Enable = TRUE;
	      }
	      if(TRUE == RemindStop_SingleEvent_Enable)
	      {
		   RemindStop_SingleEvent_Enable = FALSE;
		   RemindStop_Status = FALSE;
		   MessageRx_RemindStop = FALSE;
	      }
         }
         else
         {
	      RemindStop_Real_Timer --;
         }
    } 
  
    /* RemindStop RiseEdge and FallEdge Active monitor */
    if((FALSE == RemindStop_Status) && (TRUE == RemindStop_LastStatus))
    {
    	 RemindStop_RiseEdge_Active = TRUE;
    } 
    else
    {
    	 RemindStop_RiseEdge_Active = FALSE;
    }
 
    if((TRUE == RemindStop_Status) && (FALSE == RemindStop_LastStatus))
    {
	 RemindStop_FallEdge_Active = TRUE;

    }	 
    else
    {
	 RemindStop_FallEdge_Active = FALSE;
    }

}
#endif
#ifdef _CONFIG_ComfortClose
/*********************************************************************************************
** Name:	  MessageDebounce_ComfortClose(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_ComfortClose(void)
{
    static uint16_t ComfortClose_Real_Timer;

  /* ComfortClose Status Active monitor */
    ComfortClose_LastStatus = ComfortClose_Status;
    
    if(TRUE == MessageRx_ComfortClose_Ind)
    {  
	MessageRx_ComfortClose_Ind = FALSE;
        
        #ifdef _SGMW_COM
        if(MessageRx_ComfortClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _SGM_COM
        if(MessageRx_ComfortClose == _RFRmtCntrlFobFnc_Comfort_Close) /* TRUE or Active, based on Message define*/
        #endif
        #ifdef _CHERY_COM
        if(MessageRx_ComfortClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif
        #ifdef _CTCS_COM
        if(MessageRx_ComfortClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif
        #ifdef _DEARCC_COM
        if(MessageRx_ComfortClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _XIAOPENG_COM
        if(MessageRx_ComfortClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _MAXUS_COM
        if(MessageRx_ComfortClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _DFMC_COM
        if(MessageRx_ComfortClose == _bcm_delayTimingReq_ON) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _BAIC_COM
        if(MessageRx_ComfortClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _DFLZM_COM
        if(MessageRx_ComfortClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _NIU_COM
        if(MessageRx_ComfortClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _FAW_COM
        if(MessageRx_ComfortClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _CHANGAN_COM
        if(MessageRx_ComfortClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif
        {
	     ComfortClose_DataStream |= 0x0001;
        }
        if((MASK01BIT & ComfortClose_DataStream) == MASK01BIT)
        {    
             ComfortClose_Status = TRUE;
        }
        else if((MASK01BIT & ComfortClose_DataStream) == 0)
        {
    	     ComfortClose_Status = FALSE;
        }
    
        ComfortClose_DataStream <<=1;
    	ComfortClose_Real_Status = TRUE;
	ComfortClose_Real_Timer = K_ComfortClose_Real_Timeout;
    }
    /*Real-time Monitor*/
    if(TRUE == ComfortClose_Real_Status)
    {
         if(ComfortClose_Real_Timer == 0)
         {
	      ComfortClose_Real_Status = FALSE;
	      if(TRUE == K_ComfortClose_SingleEvent_Enable) /*10,1110 is MultiEvent, 1,111 is SingleEvent */
	      {
		   ComfortClose_SingleEvent_Enable = TRUE;
	      }
	      if(TRUE == ComfortClose_SingleEvent_Enable)
	      {
		   ComfortClose_SingleEvent_Enable = FALSE;
		   ComfortClose_Status = FALSE;
		   MessageRx_ComfortClose = FALSE;
	      }
         }
         else
         {
	      ComfortClose_Real_Timer --;
         }
    } 
  
    /* ComfortClose RiseEdge and FallEdge Active monitor */
    if((FALSE == ComfortClose_Status) && (TRUE == ComfortClose_LastStatus))
    {
    	 ComfortClose_RiseEdge_Active = TRUE;
    } 
    else
    {
    	 ComfortClose_RiseEdge_Active = FALSE;
    }
 
    if((TRUE == ComfortClose_Status) && (FALSE == ComfortClose_LastStatus))
    {
	 ComfortClose_FallEdge_Active = TRUE;

    }	 
    else
    {
	 ComfortClose_FallEdge_Active = FALSE;
    }
}
#endif


#ifdef _CONFIG_AppOpen
/*********************************************************************************************
** Name:	  MessageDebounce_AppOpen(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_AppOpen(void)
{
     /*static uint16_t AppOpen_Timer = 0;
     static uint16_t AppOpen_ShortPress_Status = 0;
     static uint16_t AppOpen_ShortPress_LastStatus = 0;
     static uint16_t AppOpen_LongPress_Status = 0;
     static uint16_t AppOpen_LongPress_LastStatus = 0;*/
     static uint16_t AppOpen_Real_Timer;
     
  /* AppOpen Status Active monitor */
    AppOpen_LastStatus = AppOpen_Status;

    if(TRUE == MessageRx_AppOpen_Ind)
    {
	MessageRx_AppOpen_Ind = FALSE;

        #ifdef _CHERY_COM
	    #ifdef _CHERY_COM_PLG
        if(MessageRx_AppOpen == _TBOX_TrunkCmd_Open) /* TRUE or Active, based on Message define*/
	    #endif
	    #ifdef _CHERY_COM_PD
        if((MessageRx_AppOpen == _AllDoorOpen_AutoOpen) /* TRUE or Active, based on Message define*/
	    #ifdef _CONFIG_DoorPadMode
	    &&(DoorPadMode_Status == TRUE)
	    #endif
	    #ifdef _CONFIG_DoorDemoMode
	    &&(DoorDemoMode_Status == FALSE)
	    #endif
	    )
	    #endif
        #endif
        #ifdef _CTCS_COM
        if(MessageRx_AppOpen == _TAILGATE_OPEN) /* TRUE or Active, based on Message define*/
        #endif
        #ifdef _DEARCC_COM
        if(MessageRx_AppOpen == _TBOX_PLG_OPEN) /* TRUE or Active, based on Message define*/
        #endif 
	#ifdef _XIAOPENG_COM
        if(MessageRx_AppOpen == _Sw_Auto_Open) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _MAXUS_COM
	     #ifdef _MAXUS_COM_PLG
        if(MessageRx_AppOpen == _TlgtCtrlReq_Open) /* TRUE or Active, based on Message define*/
	     #endif
	     #ifdef _MAXUS_COM_PSD
        if(MessageRx_AppOpen == _OutsideCarCtrlReq_iCGM_Open) /* TRUE or Active, based on Message define*/
	     #endif
        #endif
	#ifdef _DFMC_COM
        if(MessageRx_AppOpen == _tbox_remoteTailgateCtrlReq_OPEN) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _BAIC_COM
	     #if defined(_BAIC_COM_C52X) || defined(_BAIC_COM_C62X)
        if((MessageRx_AppOpen == _TmPtmOperCmd_Open) && (VehiclePowerMode == PowerMode_OFF)) /* TRUE or Active, based on Message define*/
	     #endif
	     #if defined(_BAIC_COM_C46DB) || defined(_BAIC_COM_B30X)
        if(MessageRx_AppOpen == _TmPtmOperCmd_Open) /* TRUE or Active, based on Message define*/
	     #endif
        #endif
	#ifdef _DFLZM_COM
        if(MessageRx_AppOpen == _SBM1_CMD_LuggageDoor_Switch_On) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _FAW_COM
        if(MessageRx_AppOpen == _REMOTE_OPEN) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _CHANGAN_COM
        //if(MessageRx_AppOpen == _TBOX_REMOTETRUNK_OPEN) /* TRUE or Active, based on Message define*/
	if(MessageRx_AppOpen == _TboxRemLgUnlckReq_Open)
        #endif
        {
	     AppOpen_DataStream |= 0x0001;
        }
        if((MASK01BIT & AppOpen_DataStream) == MASK01BIT)
        {    
             AppOpen_Status = TRUE;
        }
        else if((MASK01BIT & AppOpen_DataStream) == 0)
        {
    	     AppOpen_Status = FALSE;
        }
    
        AppOpen_DataStream <<=1;
    	AppOpen_Real_Status = TRUE;
	AppOpen_Real_Timer = K_AppOpen_Real_Timeout;
    }
    /*Real-time Monitor*/
    if(TRUE == AppOpen_Real_Status)
    {
         if(AppOpen_Real_Timer == 0)
         {
	      AppOpen_Real_Status = FALSE;
	      if(TRUE == K_AppOpen_SingleEvent_Enable) /*10,1110 is MultiEvent, 1,111 is SingleEvent */
	      {
		   AppOpen_SingleEvent_Enable = TRUE;
	      }
	      if(TRUE == AppOpen_SingleEvent_Enable)
	      {
		   AppOpen_SingleEvent_Enable = FALSE;
		   AppOpen_Status = FALSE;
		   MessageRx_AppOpen = FALSE;
	      }
         }
         else
         {
	      AppOpen_Real_Timer --;
         }
    } 
  
    /* AppOpen RiseEdge and FallEdge Active monitor */
    if((FALSE == AppOpen_Status) && (TRUE == AppOpen_LastStatus))
    {
    	 AppOpen_RiseEdge_Active = TRUE;
    } 
    else
    {
    	 AppOpen_RiseEdge_Active = FALSE;
    }
 
    if((TRUE == AppOpen_Status) && (FALSE == AppOpen_LastStatus))
    {
	 AppOpen_FallEdge_Active = TRUE;

    }	 
    else
    {
	 AppOpen_FallEdge_Active = FALSE;
    }
}
#endif
#ifdef _CONFIG_AppClose
/*********************************************************************************************
** Name:	  MessageDebounce_AppClose(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_AppClose(void)
{
     /*static uint16_t AppClose_Timer = 0;
     static uint16_t AppClose_ShortPress_Status = 0;
     static uint16_t AppClose_ShortPress_LastStatus = 0;
     static uint16_t AppClose_LongPress_Status = 0;
     static uint16_t AppClose_LongPress_LastStatus = 0;*/
     static uint16_t AppClose_Real_Timer;
     
  /* AppClose Status Active monitor */
    AppClose_LastStatus = AppClose_Status;

    if(TRUE == MessageRx_AppClose_Ind)
    {
	MessageRx_AppClose_Ind = FALSE;

        #ifdef _CHERY_COM
	    #ifdef _CHERY_COM_PLG
        if(MessageRx_AppClose == _TBOX_TrunkCmd_Close) /* TRUE or Active, based on Message define*/
	    #endif
	    #ifdef _CHERY_COM_PD
        if((MessageRx_AppClose == _AllDoorClose_AutoClose) /* TRUE or Active, based on Message define*/
	    #ifdef _CONFIG_DoorPadMode
	    &&(DoorPadMode_Status == TRUE)
	    #endif
	    #ifdef _CONFIG_DoorDemoMode
	    &&(DoorDemoMode_Status == FALSE)
	    #endif
	    )
	    #endif
        #endif
        #ifdef _CTCS_COM
        if(MessageRx_AppClose == _TAILGATE_CLOSE) /* TRUE or Active, based on Message define*/
        #endif
        #ifdef _DEARCC_COM
        if(MessageRx_AppClose == _TBOX_PLG_CLOSE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _XIAOPENG_COM
        if(MessageRx_AppClose == _Sw_Auto_Close) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _MAXUS_COM
	     #ifdef _MAXUS_COM_PLG
        if(MessageRx_AppClose == _TlgtCtrlReq_Close) /* TRUE or Active, based on Message define*/
	     #endif
	     #ifdef _MAXUS_COM_PSD
        if(MessageRx_AppClose == _OutsideCarCtrlReq_iCGM_Close) /* TRUE or Active, based on Message define*/
	     #endif
        #endif
	#ifdef _DFMC_COM
        if(MessageRx_AppClose == _tbox_remoteTailgateCtrlReq_CLOSE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _BAIC_COM
	     #if defined(_BAIC_COM_C52X) || defined(_BAIC_COM_C62X)
        if((MessageRx_AppClose == _TmPtmOperCmd_close) && (VehiclePowerMode == PowerMode_OFF)) /* TRUE or Active, based on Message define*/
	     #endif
	     #if defined(_BAIC_COM_C46DB) || defined(_BAIC_COM_B30X)
        if(MessageRx_AppClose == _TmPtmOperCmd_close) /* TRUE or Active, based on Message define*/
	     #endif
        #endif
	#ifdef _DFLZM_COM
        if(MessageRx_AppClose == _SBM1_CMD_LuggageDoor_Switch_Off) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _FAW_COM
        if(MessageRx_AppClose == _REMOTE_CLOSE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _CHANGAN_COM
        //if(MessageRx_AppClose == _TBOX_REMOTETRUNK_CLOSE) /* TRUE or Active, based on Message define*/
	if(MessageRx_AppClose == _TboxRemLgUnlckReq_Close)  /* TRUE or Active, based on Message define*/
        #endif
        {
	     AppClose_DataStream |= 0x0001;
        }
        if((MASK01BIT & AppClose_DataStream) == MASK01BIT)
        {    
             AppClose_Status = TRUE;
        }
        else if((MASK01BIT & AppClose_DataStream) == 0)
        {
    	     AppClose_Status = FALSE;
        }
    
        AppClose_DataStream <<=1;
    	AppClose_Real_Status = TRUE;
	AppClose_Real_Timer = K_AppClose_Real_Timeout;
    }
    /*Real-time Monitor*/
    if(TRUE == AppClose_Real_Status)
    {
         if(AppClose_Real_Timer == 0)
         {
	      AppClose_Real_Status = FALSE;
	      if(TRUE == K_AppClose_SingleEvent_Enable) /*10,1110 is MultiEvent, 1,111 is SingleEvent */
	      {
		   AppClose_SingleEvent_Enable = TRUE;
	      }
	      if(TRUE == AppClose_SingleEvent_Enable)
	      {
		   AppClose_SingleEvent_Enable = FALSE;
		   AppClose_Status = FALSE;
		   MessageRx_AppClose = FALSE;
	      }
         }
         else
         {
	      AppClose_Real_Timer --;
         }
    } 
  
    /* AppClose RiseEdge and FallEdge Active monitor */
    if((FALSE == AppClose_Status) && (TRUE == AppClose_LastStatus))
    {
    	 AppClose_RiseEdge_Active = TRUE;
    } 
    else
    {
    	 AppClose_RiseEdge_Active = FALSE;
    }
 
    if((TRUE == AppClose_Status) && (FALSE == AppClose_LastStatus))
    {
	 AppClose_FallEdge_Active = TRUE;

    }	 
    else
    {
	 AppClose_FallEdge_Active = FALSE;
    }
}
#endif
#ifdef _CONFIG_AppStop
/*********************************************************************************************
** Name:	  MessageDebounce_AppStop(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_AppStop(void)
{
     /*static uint16_t AppStop_Timer = 0;
     static uint16_t AppStop_ShortPress_Status = 0;
     static uint16_t AppStop_ShortPress_LastStatus = 0;
     static uint16_t AppStop_LongPress_Status = 0;
     static uint16_t AppStop_LongPress_LastStatus = 0;*/
     static uint16_t AppStop_Real_Timer;
     
  /* AppStop Status Active monitor */
    AppStop_LastStatus = AppStop_Status;
    
    if(TRUE == MessageRx_AppStop_Ind)
    {  
	MessageRx_AppStop_Ind = FALSE;
        
        #ifdef _CHERY_COM
        if((MessageRx_AppStop == _Stop_Stop) /* TRUE or Active, based on Message define*/
	    #ifdef _CONFIG_DoorPadMode
	    &&(DoorPadMode_Status == TRUE)
	    #endif
	    )
        #endif 
	#ifdef _XIAOPENG_COM
        if(MessageRx_AppStop == _Sw_Stop) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _MAXUS_COM
	     #ifdef _MAXUS_COM_PLG
        if(MessageRx_AppStop == _TlgtCtrlReq_Hold) /* TRUE or Active, based on Message define*/
	     #endif
	     #ifdef _MAXUS_COM_PSD
        if(MessageRx_AppStop == _OutsideCarCtrlReq_iCGM_Hold) /* TRUE or Active, based on Message define*/
	     #endif
        #endif
	#ifdef _BAIC_COM
	     #if defined(_BAIC_COM_C52X) || defined(_BAIC_COM_C62X)
        if((MessageRx_AppStop == _TmPtmOperCmd_stop) && (VehiclePowerMode == PowerMode_OFF)) /* TRUE or Active, based on Message define*/
	     #endif
	     #if defined(_BAIC_COM_C46DB) || defined(_BAIC_COM_B30X)
        if(MessageRx_AppStop == _TmPtmOperCmd_stop) /* TRUE or Active, based on Message define*/
	     #endif
        #endif
	#ifdef _FAW_COM
        if(MessageRx_AppStop == _REMOTE_STOP) /* TRUE or Active, based on Message define*/
        #endif
        {
	     AppStop_DataStream |= 0x0001;
        }
        if((MASK01BIT & AppStop_DataStream) == MASK01BIT)
        {    
             AppStop_Status = TRUE;
        }
        else if((MASK01BIT & AppStop_DataStream) == 0)
        {
    	     AppStop_Status = FALSE;
        }
    
        AppStop_DataStream <<=1;
    	AppStop_Real_Status = TRUE;
	AppStop_Real_Timer = K_AppStop_Real_Timeout;
    }
    /*Real-time Monitor*/
    if(TRUE == AppStop_Real_Status)
    {
         if(AppStop_Real_Timer == 0)
         {
	      AppStop_Real_Status = FALSE;
	      if(TRUE == K_AppStop_SingleEvent_Enable) /*10,1110 is MultiEvent, 1,111 is SingleEvent */
	      {
		   AppStop_SingleEvent_Enable = TRUE;
	      }
	      if(TRUE == AppStop_SingleEvent_Enable)
	      {
		   AppStop_SingleEvent_Enable = FALSE;
		   AppStop_Status = FALSE;
		   MessageRx_AppStop = FALSE;
	      }
         }
         else
         {
	      AppStop_Real_Timer --;
         }
    } 

    /* AppStop RiseEdge and FallEdge Active monitor */
    if((FALSE == AppStop_Status) && (TRUE == AppStop_LastStatus))
    {
    	 AppStop_RiseEdge_Active = TRUE;
    } 
    else
    {
    	 AppStop_RiseEdge_Active = FALSE;
    }
 
    if((TRUE == AppStop_Status) && (FALSE == AppStop_LastStatus))
    {
	 AppStop_FallEdge_Active = TRUE;

    }	 
    else
    {
	 AppStop_FallEdge_Active = FALSE;
    }
}
#endif

#ifdef _CONFIG_AppButton
/*********************************************************************************************
** Name:	  MessageDebounce_AppButton(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_AppButton(void)
{
     /*static uint16_t AppButton_Timer = 0;
     static uint16_t AppButton_ShortPress_Status = 0;
     static uint16_t AppButton_ShortPress_LastStatus = 0;
     static uint16_t AppButton_LongPress_Status = 0;
     static uint16_t AppButton_LongPress_LastStatus = 0;*/
     static uint16_t AppButton_Real_Timer;
     
  /* AppButton Status Active monitor */
    AppButton_LastStatus = AppButton_Status;
    
    if(TRUE == MessageRx_AppButton_Ind)
    {  
	MessageRx_AppButton_Ind = FALSE;
        
        #ifdef _CHERY_COM
        if((MessageRx_AppButton == _DoorCtrl_Action) /* TRUE or Active, based on Message define*/
	    #ifdef _CONFIG_DoorPadMode
	    &&(DoorPadMode_Status == TRUE)
	    #endif
	    #ifdef _CONFIG_DoorDemoMode
	    &&(DoorDemoMode_Status == FALSE)
	    #endif
	    )
        #endif 
        {
	     AppButton_DataStream |= 0x0001;
        }
        if((MASK01BIT & AppButton_DataStream) == MASK01BIT)
        {    
             AppButton_Status = TRUE;
        }
        else if((MASK01BIT & AppButton_DataStream) == 0)
        {
    	     AppButton_Status = FALSE;
        }
    
        AppButton_DataStream <<=1;
    	AppButton_Real_Status = TRUE;
	AppButton_Real_Timer = K_AppButton_Real_Timeout;
    }
    /*Real-time Monitor*/
    if(TRUE == AppButton_Real_Status)
    {
         if(AppButton_Real_Timer == 0)
         {
	      AppButton_Real_Status = FALSE;
	      if(TRUE == K_AppButton_SingleEvent_Enable) /*10,1110 is MultiEvent, 1,111 is SingleEvent */
	      {
		   AppButton_SingleEvent_Enable = TRUE;
	      }
	      if(TRUE == AppButton_SingleEvent_Enable)
	      {
		   AppButton_SingleEvent_Enable = FALSE;
		   AppButton_Status = FALSE;
		   MessageRx_AppButton = FALSE;
	      }
         }
         else
         {
	      AppButton_Real_Timer --;
         }
    } 

    /* AppButton RiseEdge and FallEdge Active monitor */
    if((FALSE == AppButton_Status) && (TRUE == AppButton_LastStatus))
    {
    	 AppButton_RiseEdge_Active = TRUE;
    } 
    else
    {
    	 AppButton_RiseEdge_Active = FALSE;
    }
 
    if((TRUE == AppButton_Status) && (FALSE == AppButton_LastStatus))
    {
	 AppButton_FallEdge_Active = TRUE;

    }	 
    else
    {
	 AppButton_FallEdge_Active = FALSE;
    }
}
#endif
#ifdef _CONFIG_AppEnable
/*********************************************************************************************
** Name:	  MessageDebounce_AppEnable(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_AppEnable(void)
{
     /*static uint16_t AppEnable_Timer = 0;
     static uint16_t AppEnable_ShortPress_Status = 0;
     static uint16_t AppEnable_ShortPress_LastStatus = 0;
     static uint16_t AppEnable_LongPress_Status = 0;
     static uint16_t AppEnable_LongPress_LastStatus = 0;*/
     static uint16_t AppEnable_Real_Timer;
     
  /* AppEnable Status Active monitor */
    AppEnable_LastStatus = AppEnable_Status;
    
    if(TRUE == MessageRx_AppEnable_Ind)
    {  
	MessageRx_AppEnable_Ind = FALSE;
        
        #ifdef _CHERY_COM
        if(MessageRx_AppEnable == _Enable_Enable) /* TRUE or Active, based on Message define*/
        #endif 
        {
	     AppEnable_DataStream |= 0x0001;
        }
        if((MASK01BIT & AppEnable_DataStream) == MASK01BIT)
        {    
             AppEnable_Status = TRUE;
        }
        else if((MASK01BIT & AppEnable_DataStream) == 0)
        {
    	     AppEnable_Status = FALSE;
        }
    
        AppEnable_DataStream <<=1;
    	AppEnable_Real_Status = TRUE;
	AppEnable_Real_Timer = K_AppEnable_Real_Timeout;
    }
    /*Real-time Monitor*/
    if(TRUE == AppEnable_Real_Status)
    {
         if(AppEnable_Real_Timer == 0)
         {
	      AppEnable_Real_Status = FALSE;
	      if(TRUE == K_AppEnable_SingleEvent_Enable) /*10,1110 is MultiEvent, 1,111 is SingleEvent */
	      {
		   AppEnable_SingleEvent_Enable = TRUE;
	      }
	      if(TRUE == AppEnable_SingleEvent_Enable)
	      {
		   AppEnable_SingleEvent_Enable = FALSE;
		   AppEnable_Status = FALSE;
		   MessageRx_AppEnable = FALSE;
	      }
         }
         else
         {
	      AppEnable_Real_Timer --;
         }
    } 
  
    /* AppEnable RiseEdge and FallEdge Active monitor */
    if((FALSE == AppEnable_Status) && (TRUE == AppEnable_LastStatus))
    {
    	 AppEnable_RiseEdge_Active = TRUE;
    } 
    else
    {
    	 AppEnable_RiseEdge_Active = FALSE;
    }
 
    if((TRUE == AppEnable_Status) && (FALSE == AppEnable_LastStatus))
    {
	 AppEnable_FallEdge_Active = TRUE;

    }	 
    else
    {
	 AppEnable_FallEdge_Active = FALSE;
    }
}
#endif
#ifdef _CONFIG_AppReset
/*********************************************************************************************
** Name:	  MessageDebounce_AppReset(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_AppReset(void)
{
/*static uint16_t AppReset_Timer = 0;
     static uint16_t AppReset_ShortPress_Status = 0;
     static uint16_t AppReset_ShortPress_LastStatus = 0;
     static uint16_t AppReset_LongPress_Status = 0;
     static uint16_t AppReset_LongPress_LastStatus = 0;*/
     static uint16_t AppReset_Real_Timer;
     
  /* AppReset Status Active monitor */
    AppReset_LastStatus = AppReset_Status;
    
    if(TRUE == MessageRx_AppReset_Ind)
    {  
	MessageRx_AppReset_Ind = FALSE;
        
        #ifdef _CHERY_COM
        if(MessageRx_AppReset == _Reset_Reset) /* TRUE or Active, based on Message define*/
        #endif 
        {
	     AppReset_DataStream |= 0x0001;
        }
        if((MASK01BIT & AppReset_DataStream) == MASK01BIT)
        {    
             AppReset_Status = TRUE;
        }
        else if((MASK01BIT & AppReset_DataStream) == 0)
        {
    	     AppReset_Status = FALSE;
        }
    
        AppReset_DataStream <<=1;
    	AppReset_Real_Status = TRUE;
	AppReset_Real_Timer = K_AppReset_Real_Timeout;
    }
    /*Real-time Monitor*/
    if(TRUE == AppReset_Real_Status)
    {
         if(AppReset_Real_Timer == 0)
         {
	      AppReset_Real_Status = FALSE;
	      if(TRUE == K_AppReset_SingleEvent_Enable) /*10,1110 is MultiEvent, 1,111 is SingleEvent */
	      {
		   AppReset_SingleEvent_Enable = TRUE;
	      }
	      if(TRUE == AppReset_SingleEvent_Enable)
	      {
		   AppReset_SingleEvent_Enable = FALSE;
		   AppReset_Status = FALSE;
		   MessageRx_AppReset = FALSE;
	      }
         }
         else
         {
	      AppReset_Real_Timer --;
         }
    } 
  
    /* AppReset RiseEdge and FallEdge Active monitor */
    if((FALSE == AppReset_Status) && (TRUE == AppReset_LastStatus))
    {
    	 AppReset_RiseEdge_Active = TRUE;
    } 
    else
    {
    	 AppReset_RiseEdge_Active = FALSE;
    }
 
    if((TRUE == AppReset_Status) && (FALSE == AppReset_LastStatus))
    {
	 AppReset_FallEdge_Active = TRUE;

    }	 
    else
    {
	 AppReset_FallEdge_Active = FALSE;
    }
}
#endif
#ifdef _CONFIG_AppDemoMode
/*********************************************************************************************
** Name:	  MessageDebounce_AppDemoMode(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_AppDemoMode(void)
{
/*static uint16_t AppDemoMode_Timer = 0;
     static uint16_t AppDemoMode_ShortPress_Status = 0;
     static uint16_t AppDemoMode_ShortPress_LastStatus = 0;
     static uint16_t AppDemoMode_LongPress_Status = 0;
     static uint16_t AppDemoMode_LongPress_LastStatus = 0;*/
     static uint16_t AppDemoMode_Real_Timer;

  /* AppDemoMode Status Active monitor */
    AppDemoMode_LastStatus = AppDemoMode_Status;

    if(TRUE == MessageRx_AppDemoMode_Ind)
    {
	MessageRx_AppDemoMode_Ind = FALSE;

        #ifdef _CHERY_COM
        if((MessageRx_AppDemoMode == _Demo_Mode_Demo_Mode) /* TRUE or Active, based on Message define*/
	    #ifdef _CONFIG_DoorPadMode
	    &&(DoorPadMode_Status == TRUE)
	    #endif
	    )
        #endif
        {
	     AppDemoMode_DataStream |= 0x0001;
        }
        if((MASK01BIT & AppDemoMode_DataStream) == MASK01BIT)
        {    
             AppDemoMode_Status = TRUE;
        }
        else if((MASK01BIT & AppDemoMode_DataStream) == 0)
        {
    	     AppDemoMode_Status = FALSE;
        }
    
        AppDemoMode_DataStream <<=1;
    	AppDemoMode_Real_Status = TRUE;
	AppDemoMode_Real_Timer = K_AppDemoMode_Real_Timeout;
    }
    /*Real-time Monitor*/
    if(TRUE == AppDemoMode_Real_Status)
    {
         if(AppDemoMode_Real_Timer == 0)
         {
	      AppDemoMode_Real_Status = FALSE;
	      if(TRUE == K_AppDemoMode_SingleEvent_Enable) /*10,1110 is MultiEvent, 1,111 is SingleEvent */
	      {
		   AppDemoMode_SingleEvent_Enable = TRUE;
	      }
	      if(TRUE == AppDemoMode_SingleEvent_Enable)
	      {
		   AppDemoMode_SingleEvent_Enable = FALSE;
		   AppDemoMode_Status = FALSE;
		   MessageRx_AppDemoMode = FALSE;
	      }
         }
         else
         {
	      AppDemoMode_Real_Timer --;
         }
    } 

    /* AppDemoMode RiseEdge and FallEdge Active monitor */
    if((FALSE == AppDemoMode_Status) && (TRUE == AppDemoMode_LastStatus))
    {
    	 AppDemoMode_RiseEdge_Active = TRUE;
    } 
    else
    {
    	 AppDemoMode_RiseEdge_Active = FALSE;
    }
 
    if((TRUE == AppDemoMode_Status) && (FALSE == AppDemoMode_LastStatus))
    {
	 AppDemoMode_FallEdge_Active = TRUE;

    }	 
    else
    {
	 AppDemoMode_FallEdge_Active = FALSE;
    }
}
#endif

#ifdef _CONFIG_AppStepOpen
/*********************************************************************************************
** Name:	  MessageDebounce_AppStepOpen(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_AppStepOpen(void)
{
     /*static uint16_t AppStepOpen_Timer = 0;
     static uint16_t AppStepOpen_ShortPress_Status = 0;
     static uint16_t AppStepOpen_ShortPress_LastStatus = 0;
     static uint16_t AppStepOpen_LongPress_Status = 0;
     static uint16_t AppStepOpen_LongPress_LastStatus = 0;*/
     static uint16_t AppStepOpen_Real_Timer;
     
  /* AppStepOpen Status Active monitor */
    AppStepOpen_LastStatus = AppStepOpen_Status;
    
    if(TRUE == MessageRx_AppStepOpen_Ind)
    {  
	MessageRx_AppStepOpen_Ind = FALSE;
        
        #ifdef _CHERY_COM
        if(MessageRx_AppStepOpen == TRUE) /* TRUE or Active, based on Message define*/
        #endif
        #ifdef _CTCS_COM
        if(MessageRx_AppStepOpen == TRUE) /* TRUE or Active, based on Message define*/
        #endif 
        #ifdef _SGMW_COM
        if(MessageRx_AppStepOpen == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _SGM_COM
        if(MessageRx_AppStepOpen == TRUE) /* TRUE or Active, based on Message define*/
        #endif
        #ifdef _DEARCC_COM
        if(MessageRx_AppStepOpen == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _XIAOPENG_COM
        if(MessageRx_AppStepOpen == _Sw_Manual_Open) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _MAXUS_COM
        if(MessageRx_AppStepOpen == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _DFMC_COM
        if(MessageRx_AppStepOpen == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _BAIC_COM
        if(MessageRx_AppStepOpen == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _DFLZM_COM
        if(MessageRx_AppStepOpen == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _FAW_COM
        if(MessageRx_AppStepOpen == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _NIU_COM
        if(MessageRx_AppStepOpen == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _CHANGAN_COM
        if(MessageRx_AppStepOpen == TRUE) /* TRUE or Active, based on Message define*/
        #endif
        {
	     AppStepOpen_DataStream |= 0x0001;
        }
        if((MASK01BIT & AppStepOpen_DataStream) == MASK01BIT)
        {    
             AppStepOpen_Status = TRUE;
        }
        else if((MASK01BIT & AppStepOpen_DataStream) == 0)
        {
    	     AppStepOpen_Status = FALSE;
        }
    
        AppStepOpen_DataStream <<=1;
    	AppStepOpen_Real_Status = TRUE;
	AppStepOpen_Real_Timer = K_AppStepOpen_Real_Timeout;
    }
    /*Real-time Monitor*/
    if(TRUE == AppStepOpen_Real_Status)
    {
         if(AppStepOpen_Real_Timer == 0)
         {
	      AppStepOpen_Real_Status = FALSE;
	      if(TRUE == K_AppStepOpen_SingleEvent_Enable) /*10,1110 is MultiEvent, 1,111 is SingleEvent */
	      {
		   AppStepOpen_SingleEvent_Enable = TRUE;
	      }   
	      if(TRUE == AppStepOpen_SingleEvent_Enable)
	      {
		   AppStepOpen_SingleEvent_Enable = FALSE;
		   AppStepOpen_Status = FALSE;
		   MessageRx_AppStepOpen = FALSE;
	      }
         }
         else
         {
	      AppStepOpen_Real_Timer --;
         }
    } 
    
    /* AppStepOpen RiseEdge and FallEdge Active monitor */
    if((FALSE == AppStepOpen_Status) && (TRUE == AppStepOpen_LastStatus))
    {
    	 AppStepOpen_RiseEdge_Active = TRUE;
    } 
    else
    {
    	 AppStepOpen_RiseEdge_Active = FALSE;
    }
 
    if((TRUE == AppStepOpen_Status) && (FALSE == AppStepOpen_LastStatus))
    {
	 AppStepOpen_FallEdge_Active = TRUE;

    }	 
    else
    {
	 AppStepOpen_FallEdge_Active = FALSE;
    }
}
#endif
#ifdef _CONFIG_AppStepClose
/*********************************************************************************************
** Name:	  MessageDebounce_AppStepClose(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_AppStepClose(void)
{
     /*static uint16_t AppStepClose_Timer = 0;
     static uint16_t AppStepClose_ShortPress_Status = 0;
     static uint16_t AppStepClose_ShortPress_LastStatus = 0;
     static uint16_t AppStepClose_LongPress_Status = 0;
     static uint16_t AppStepClose_LongPress_LastStatus = 0;*/
     static uint16_t AppStepClose_Real_Timer;
     
  /* AppStepClose Status Active monitor */
    AppStepClose_LastStatus = AppStepClose_Status;
    
    if(TRUE == MessageRx_AppStepClose_Ind)
    {  
	MessageRx_AppStepClose_Ind = FALSE;
        
        #ifdef _CHERY_COM
        if(MessageRx_AppStepClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif
        #ifdef _CTCS_COM
        if(MessageRx_AppStepClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif 
        #ifdef _SGMW_COM
        if(MessageRx_AppStepClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _SGM_COM
        if(MessageRx_AppStepClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif
        #ifdef _DEARCC_COM
        if(MessageRx_AppStepClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _XIAOPENG_COM
        if(MessageRx_AppStepClose == _Sw_Manual_Close) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _MAXUS_COM
        if(MessageRx_AppStepClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _DFMC_COM
        if(MessageRx_AppStepClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _BAIC_COM
        if(MessageRx_AppStepClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _DFLZM_COM
        if(MessageRx_AppStepClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _FAW_COM
        if(MessageRx_AppStepClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _NIU_COM
        if(MessageRx_AppStepClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _CHANGAN_COM
        if(MessageRx_AppStepClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif
        {
	     AppStepClose_DataStream |= 0x0001;
        }
        if((MASK01BIT & AppStepClose_DataStream) == MASK01BIT)
        {    
             AppStepClose_Status = TRUE;
        }
        else if((MASK01BIT & AppStepClose_DataStream) == 0)
        {
    	     AppStepClose_Status = FALSE;
        }
    
        AppStepClose_DataStream <<=1;
    	AppStepClose_Real_Status = TRUE;
	AppStepClose_Real_Timer = K_AppStepClose_Real_Timeout;
    }
    /*Real-time Monitor*/
    if(TRUE == AppStepClose_Real_Status)
    {
         if(AppStepClose_Real_Timer == 0)
         {
	      AppStepClose_Real_Status = FALSE;
	      if(TRUE == K_AppStepClose_SingleEvent_Enable) /*10,1110 is MultiEvent, 1,111 is SingleEvent */
	      {
		   AppStepClose_SingleEvent_Enable = TRUE;
	      }   
	      if(TRUE == AppStepClose_SingleEvent_Enable)
	      {
		   AppStepClose_SingleEvent_Enable = FALSE;
		   AppStepClose_Status = FALSE;
		   MessageRx_AppStepClose = FALSE;
	      }
         }
         else
         {
	      AppStepClose_Real_Timer --;
         }
    } 
    
    /* AppStepClose RiseEdge and FallEdge Active monitor */
    if((FALSE == AppStepClose_Status) && (TRUE == AppStepClose_LastStatus))
    {
    	 AppStepClose_RiseEdge_Active = TRUE;
    } 
    else
    {
    	 AppStepClose_RiseEdge_Active = FALSE;
    }
 
    if((TRUE == AppStepClose_Status) && (FALSE == AppStepClose_LastStatus))
    {
	 AppStepClose_FallEdge_Active = TRUE;

    }	 
    else
    {
	 AppStepClose_FallEdge_Active = FALSE;
    }
}
#endif
#ifdef _CONFIG_VROpen
/*********************************************************************************************
** Name:	  MessageDebounce_VROpen(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_VROpen(void)
{
     /*static uint16_t VROpen_Timer = 0;
     static uint16_t VROpen_ShortPress_Status = 0;
     static uint16_t VROpen_ShortPress_LastStatus = 0;
     static uint16_t VROpen_LongPress_Status = 0;
     static uint16_t VROpen_LongPress_LastStatus = 0;*/
     static uint16_t VROpen_Real_Timer;
     
  /* VROpen Status Active monitor */
    VROpen_LastStatus = VROpen_Status;
    
    if(TRUE == MessageRx_VROpen_Ind)
    {  
	MessageRx_VROpen_Ind = FALSE;
        
        #ifdef _CHERY_COM
	    #ifdef _CHERY_COM_PLG
        if(MessageRx_VROpen == _DVD_TrunkCmd_Open) /* TRUE or Active, based on Message define*/
	    #endif
	    #ifdef _CHERY_COM_PD
        if(MessageRx_VROpen == TRUE) /* TRUE or Active, based on Message define*/
	    #endif
        #endif
	#ifdef _AUDI_COM
        if(MessageRx_VROpen == MasterCmd_DoorCmd_AutoOpenCmd) /* TRUE or Active, based on Message define*/
        #endif
        #ifdef _CTCS_COM
        if(MessageRx_VROpen == _PLG_OPEN_REQUEST)
        #endif 
        #ifdef _VOYAH_COM
        if(MessageRx_VROpen == _BCM_DoorCtrlReq_Open) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _SGM_COM
        if(MessageRx_VROpen == TRUE) /* TRUE or Active, based on Message define*/
        #endif
        #ifdef _DEARCC_COM
        if(MessageRx_VROpen == _HU_PLG_OPEN_REQUEST)
        #endif
	#ifdef _XIAOPENG_COM
        if(MessageRx_VROpen == _Sw_Auto_Open) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _MAXUS_COM
	   #ifdef _MAXUS_COM_PLG
        if(MessageRx_VROpen == _TlgtOprtReq_Open) /* TRUE or Active, based on Message define*/
	   #endif
	   #ifdef _MAXUS_COM_PSD
        if(MessageRx_VROpen == _SldDrCtrlReq_Open) /* TRUE or Active, based on Message define*/
	   #endif
        #endif
	#ifdef _DFMC_COM
        if(MessageRx_VROpen == _ivi_potOnOffSet_OPEN) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _BAIC_COM
        if(MessageRx_VROpen == _PtmOperSwt_ON) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _DFLZM_COM
        if(MessageRx_VROpen == _ICE22_Set_PLG_OnOff_PLG_On) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _NIU_COM
        if(MessageRx_VROpen == _MMI5_RearDoorCtrlReq_Open) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _FAW_COM
        if(MessageRx_VROpen == _LuggageDoorCtrCmd_Open) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _CHANGAN_COM
        if(MessageRx_VROpen == _CdcTrDoorOpenReq_On) /* TRUE or Active, based on Message define*/
        #endif
        {
	     VROpen_DataStream |= 0x0001;
        }
        if((MASK01BIT & VROpen_DataStream) == MASK01BIT)
        {    
             VROpen_Status = TRUE;
        }
        else if((MASK01BIT & VROpen_DataStream) == 0)
        {
    	     VROpen_Status = FALSE;
        }
    
        VROpen_DataStream <<=1;
    	VROpen_Real_Status = TRUE;
	VROpen_Real_Timer = K_VROpen_Real_Timeout;
    }
    /*Real-time Monitor*/
    if(TRUE == VROpen_Real_Status)
    {
         if(VROpen_Real_Timer == 0)
         {
	      VROpen_Real_Status = FALSE;
	      if(TRUE == K_VROpen_SingleEvent_Enable) /*10,1110 is MultiEvent, 1,111 is SingleEvent */
	      {
		   VROpen_SingleEvent_Enable = TRUE;
	      }
	      if(TRUE == VROpen_SingleEvent_Enable)
	      {
		   VROpen_SingleEvent_Enable = FALSE;
		   VROpen_Status = FALSE;
		   MessageRx_VROpen = FALSE;
	      }
         }
         else
         {
	      VROpen_Real_Timer --;
         }
    } 

    /* VROpen RiseEdge and FallEdge Active monitor */
    if((FALSE == VROpen_Status) && (TRUE == VROpen_LastStatus))
    {
    	 VROpen_RiseEdge_Active = TRUE;
    } 
    else
    {
    	 VROpen_RiseEdge_Active = FALSE;
    }
 
    if((TRUE == VROpen_Status) && (FALSE == VROpen_LastStatus))
    {
	 VROpen_FallEdge_Active = TRUE;

    }	 
    else
    {
	 VROpen_FallEdge_Active = FALSE;
    }
}
#endif
#ifdef _CONFIG_VRClose
/*********************************************************************************************
** Name:	  MessageDebounce_VRClose(void);
** Function:
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_VRClose(void)
{

}
#endif
#ifdef _CONFIG_VRStop
/*********************************************************************************************
** Name:	  MessageDebounce_VRStop(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_VRStop(void)
{
     /*static uint16_t VRStop_Timer = 0;
     static uint16_t VRStop_ShortPress_Status = 0;
     static uint16_t VRStop_ShortPress_LastStatus = 0;
     static uint16_t VRStop_LongPress_Status = 0;
     static uint16_t VRStop_LongPress_LastStatus = 0;*/
     static uint16_t VRStop_Real_Timer;
     
  /* VRStop Status Active monitor */
    VRStop_LastStatus = VRStop_Status;
    
    if(TRUE == MessageRx_VRStop_Ind)
    {  
	MessageRx_VRStop_Ind = FALSE;
        
        #ifdef _CHERY_COM
        if(MessageRx_VRStop == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _AUDI_COM
        if(MessageRx_VRStop == MasterCmd_DoorCmd_StopMoveElecCmd) /* TRUE or Active, based on Message define*/
        #endif
        #ifdef _CTCS_COM
        if(MessageRx_VRStop == _PLG_STOP_REQUEST) /* TRUE or Active, based on Message define*/
        #endif 
        #ifdef _VOYAH_COM
        if(MessageRx_VRStop == _BCM_DoorCtrlReq_Stop) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _SGM_COM
        if(MessageRx_VRStop == TRUE) /* TRUE or Active, based on Message define*/
        #endif
        #ifdef _DEARCC_COM
        if(MessageRx_VRStop == _HU_PLG_STOP_REQUEST) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _XIAOPENG_COM
        if(MessageRx_VRStop == _Sw_Stop) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _MAXUS_COM
	   #ifdef _MAXUS_COM_PLG
        if(MessageRx_VRStop == _TlgtOprtReq_Hold) /* TRUE or Active, based on Message define*/
	   #endif
	   #ifdef _MAXUS_COM_PSD
        if(MessageRx_VRStop == _SldDrCtrlReq_Hold) /* TRUE or Active, based on Message define*/
	   #endif
        #endif
	#ifdef _DFMC_COM
        if(MessageRx_VRStop == _ivi_potOnOffSet_STOP) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _BAIC_COM
        if(MessageRx_VRStop == _PtmOperSwt_Stop) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _DFLZM_COM
        if(MessageRx_VRStop == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _NIU_COM
        if(MessageRx_VRStop == _MMI5_RearDoorCtrlReq_Pause) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _FAW_COM
        if(MessageRx_VRStop == _LuggageDoorCtrCmd_Stop) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _CHANGAN_COM
        if(MessageRx_VRStop == TRUE) /* TRUE or Active, based on Message define*/
        #endif
        {
	     VRStop_DataStream |= 0x0001;
        }
        if((MASK01BIT & VRStop_DataStream) == MASK01BIT)
        {    
             VRStop_Status = TRUE;
        }
        else if((MASK01BIT & VRStop_DataStream) == 0)
        {
    	     VRStop_Status = FALSE;
        }
    
        VRStop_DataStream <<=1;
    	VRStop_Real_Status = TRUE;
	VRStop_Real_Timer = K_VRStop_Real_Timeout;
    }
    /*Real-time Monitor*/
    if(TRUE == VRStop_Real_Status)
    {
         if(VRStop_Real_Timer == 0)
         {
	      VRStop_Real_Status = FALSE;
	      if(TRUE == K_VRStop_SingleEvent_Enable) /*10,1110 is MultiEvent, 1,111 is SingleEvent */
	      {
		   VRStop_SingleEvent_Enable = TRUE;
	      }   
	      if(TRUE == VRStop_SingleEvent_Enable)
	      {
		   VRStop_SingleEvent_Enable = FALSE;
		   VRStop_Status = FALSE;
		   MessageRx_VRStop = FALSE;
	      }
         }
         else
         {
	      VRStop_Real_Timer --;
         }
    } 
    
    /* VRStop RiseEdge and FallEdge Active monitor */
    if((FALSE == VRStop_Status) && (TRUE == VRStop_LastStatus))
    {
    	 VRStop_RiseEdge_Active = TRUE;
    } 
    else
    {
    	 VRStop_RiseEdge_Active = FALSE;
    }
 
    if((TRUE == VRStop_Status) && (FALSE == VRStop_LastStatus))
    {
	 VRStop_FallEdge_Active = TRUE;

    }	 
    else
    {
	 VRStop_FallEdge_Active = FALSE;
    }
}
#endif
#ifdef _CONFIG_VRStopDirectly
/*********************************************************************************************
** Name:	  MessageDebounce_VRStopDirectly(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_VRStopDirectly(void)
{
     /*static uint16_t VRStopDirectly_Timer = 0;
     static uint16_t VRStopDirectly_ShortPress_Status = 0;
     static uint16_t VRStopDirectly_ShortPress_LastStatus = 0;
     static uint16_t VRStopDirectly_LongPress_Status = 0;
     static uint16_t VRStopDirectly_LongPress_LastStatus = 0;*/
     static uint16_t VRStopDirectly_Real_Timer;
     
  /* VRStopDirectly Status Active monitor */
    VRStopDirectly_LastStatus = VRStopDirectly_Status;
    
    if(TRUE == MessageRx_VRStopDirectly_Ind)
    {  
	MessageRx_VRStopDirectly_Ind = FALSE;
        
        #ifdef _CHERY_COM
        if(MessageRx_VRStopDirectly == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _AUDI_COM
        if(MessageRx_VRStopDirectly == MasterCmd_DoorCmd_EmergencyStopCmd) /* TRUE or Active, based on Message define*/
        #endif
        #ifdef _CTCS_COM
        if(MessageRx_VRStopDirectly == TRUE) /* TRUE or Active, based on Message define*/
        #endif 
        #ifdef _SGMW_COM
        if(MessageRx_VRStopDirectly == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _SGM_COM
        if(MessageRx_VRStopDirectly == TRUE) /* TRUE or Active, based on Message define*/
        #endif
        #ifdef _DEARCC_COM
        if(MessageRx_VRStopDirectly == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _XIAOPENG_COM
        if(MessageRx_VRStopDirectly == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _MAXUS_COM
	   #ifdef _MAXUS_COM_PLG
        if(MessageRx_VRStopDirectly == TRUE) /* TRUE or Active, based on Message define*/
	   #endif
	   #ifdef _MAXUS_COM_PSD
        if(MessageRx_VRStopDirectly == TRUE) /* TRUE or Active, based on Message define*/
	   #endif
        #endif
	#ifdef _DFMC_COM
        if(MessageRx_VRStopDirectly == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _BAIC_COM
        if(MessageRx_VRStopDirectly == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _DFLZM_COM
        if(MessageRx_VRStopDirectly == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _NIU_COM
        if(MessageRx_VRStopDirectly == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _FAW_COM
        if(MessageRx_VRStopDirectly == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _CHANGAN_COM
        if(MessageRx_VRStopDirectly == TRUE) /* TRUE or Active, based on Message define*/
        #endif
        {
	     VRStopDirectly_DataStream |= 0x0001;
        }
        if((MASK01BIT & VRStopDirectly_DataStream) == MASK01BIT)
        {    
             VRStopDirectly_Status = TRUE;
        }
        else if((MASK01BIT & VRStopDirectly_DataStream) == 0)
        {
    	     VRStopDirectly_Status = FALSE;
        }
    
        VRStopDirectly_DataStream <<=1;
    	VRStopDirectly_Real_Status = TRUE;
	VRStopDirectly_Real_Timer = K_VRStopDirectly_Real_Timeout;
    }
    /*Real-time Monitor*/
    if(TRUE == VRStopDirectly_Real_Status)
    {
         if(VRStopDirectly_Real_Timer == 0)
         {
	      VRStopDirectly_Real_Status = FALSE;
	      if(TRUE == K_VRStopDirectly_SingleEvent_Enable) /*10,1110 is MultiEvent, 1,111 is SingleEvent */
	      {
		   VRStopDirectly_SingleEvent_Enable = TRUE;
	      }
	      if(TRUE == VRStopDirectly_SingleEvent_Enable)
	      {
		   VRStopDirectly_SingleEvent_Enable = FALSE;
		   VRStopDirectly_Status = FALSE;
		   MessageRx_VRStopDirectly = FALSE;
	      }
         }
         else
         {
	      VRStopDirectly_Real_Timer --;
         }
    } 

    /* VRStopDirectly RiseEdge and FallEdge Active monitor */
    if((FALSE == VRStopDirectly_Status) && (TRUE == VRStopDirectly_LastStatus))
    {
    	 VRStopDirectly_RiseEdge_Active = TRUE;
    } 
    else
    {
    	 VRStopDirectly_RiseEdge_Active = FALSE;
    }
 
    if((TRUE == VRStopDirectly_Status) && (FALSE == VRStopDirectly_LastStatus))
    {
	 VRStopDirectly_FallEdge_Active = TRUE;

    }	 
    else
    {
	 VRStopDirectly_FallEdge_Active = FALSE;
    }
}
#endif

#ifdef _CONFIG_VRSmallOpen
/*********************************************************************************************
** Name:	  MessageDebounce_VRSmallOpen(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_VRSmallOpen(void)
{
     /*static uint16_t VRSmallOpen_Timer = 0;
     static uint16_t VRSmallOpen_ShortPress_Status = 0;
     static uint16_t VRSmallOpen_ShortPress_LastStatus = 0;
     static uint16_t VRSmallOpen_LongPress_Status = 0;
     static uint16_t VRSmallOpen_LongPress_LastStatus = 0;*/
     static uint16_t VRSmallOpen_Real_Timer;
     
  /* VRSmallOpen Status Active monitor */
    VRSmallOpen_LastStatus = VRSmallOpen_Status;
    
    if(TRUE == MessageRx_VRSmallOpen_Ind)
    {  
	MessageRx_VRSmallOpen_Ind = FALSE;
        
        #ifdef _CHERY_COM
        if(MessageRx_VRSmallOpen == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _AUDI_COM
        if(MessageRx_VRSmallOpen == MasterCmd_DoorCmd_StopMoveElecCmd) /* TRUE or Active, based on Message define*/
        #endif
        #ifdef _CTCS_COM
        if(MessageRx_VRSmallOpen == _PLG_STOP_REQUEST) /* TRUE or Active, based on Message define*/
        #endif 
        #ifdef _VOYAH_COM
        if(MessageRx_VRSmallOpen == _BCM_DoorCtrlReq_Relese) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _SGM_COM
        if(MessageRx_VRSmallOpen == TRUE) /* TRUE or Active, based on Message define*/
        #endif
        #ifdef _DEARCC_COM
        if(MessageRx_VRSmallOpen == _HU_PLG_STOP_REQUEST) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _XIAOPENG_COM
        if(MessageRx_VRSmallOpen == _Sw_Stop) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _MAXUS_COM
	   #ifdef _MAXUS_COM_PLG
        if(MessageRx_VRSmallOpen == _TlgtOprtReq_Hold) /* TRUE or Active, based on Message define*/
	   #endif
	   #ifdef _MAXUS_COM_PSD
        if(MessageRx_VRSmallOpen == _SldDrCtrlReq_Hold) /* TRUE or Active, based on Message define*/
	   #endif
        #endif
	#ifdef _DFMC_COM
        if(MessageRx_VRSmallOpen == _ivi_potOnOffSet_STOP) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _BAIC_COM
        if(MessageRx_VRSmallOpen == _PtmOperSwt_Stop) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _DFLZM_COM
        if(MessageRx_VRSmallOpen == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _NIU_COM
        if(MessageRx_VRSmallOpen == _MMI5_RearDoorCtrlReq_Pause) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _FAW_COM
        if(MessageRx_VRSmallOpen == _LuggageDoorCtrCmd_Stop) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _CHANGAN_COM
        if(MessageRx_VRSmallOpen == TRUE) /* TRUE or Active, based on Message define*/
        #endif
        {
	     VRSmallOpen_DataStream |= 0x0001;
        }
        if((MASK01BIT & VRSmallOpen_DataStream) == MASK01BIT)
        {    
             VRSmallOpen_Status = TRUE;
        }
        else if((MASK01BIT & VRSmallOpen_DataStream) == 0)
        {
    	     VRSmallOpen_Status = FALSE;
        }
    
        VRSmallOpen_DataStream <<=1;
    	VRSmallOpen_Real_Status = TRUE;
	VRSmallOpen_Real_Timer = K_VRSmallOpen_Real_Timeout;
    }
    /*Real-time Monitor*/
    if(TRUE == VRSmallOpen_Real_Status)
    {
         if(VRSmallOpen_Real_Timer == 0)
         {
	      VRSmallOpen_Real_Status = FALSE;
	      if(TRUE == K_VRSmallOpen_SingleEvent_Enable) /*10,1110 is MultiEvent, 1,111 is SingleEvent */
	      {
		   VRSmallOpen_SingleEvent_Enable = TRUE;
	      }
	      if(TRUE == VRSmallOpen_SingleEvent_Enable)
	      {
		   VRSmallOpen_SingleEvent_Enable = FALSE;
		   VRSmallOpen_Status = FALSE;
		   MessageRx_VRSmallOpen = FALSE;
	      }
         }
         else
         {
	      VRSmallOpen_Real_Timer --;
         }
    } 

    /* VRSmallOpen RiseEdge and FallEdge Active monitor */
    if((FALSE == VRSmallOpen_Status) && (TRUE == VRSmallOpen_LastStatus))
    {
    	 VRSmallOpen_RiseEdge_Active = TRUE;
    } 
    else
    {
    	 VRSmallOpen_RiseEdge_Active = FALSE;
    }
 
    if((TRUE == VRSmallOpen_Status) && (FALSE == VRSmallOpen_LastStatus))
    {
	 VRSmallOpen_FallEdge_Active = TRUE;

    }	 
    else
    {
	 VRSmallOpen_FallEdge_Active = FALSE;
    }
}
#endif

#ifdef _CONFIG_VRStepOpen
/*********************************************************************************************
** Name:	  MessageDebounce_VRStepOpen(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_VRStepOpen(void)
{
     /*static uint16_t VRStepOpen_Timer = 0;
     static uint16_t VRStepOpen_ShortPress_Status = 0;
     static uint16_t VRStepOpen_ShortPress_LastStatus = 0;
     static uint16_t VRStepOpen_LongPress_Status = 0;
     static uint16_t VRStepOpen_LongPress_LastStatus = 0;*/
     static uint16_t VRStepOpen_Real_Timer;
     
  /* VRStepOpen Status Active monitor */
    VRStepOpen_LastStatus = VRStepOpen_Status;
    
    if(TRUE == MessageRx_VRStepOpen_Ind)
    {  
	MessageRx_VRStepOpen_Ind = FALSE;
        
        #ifdef _CHERY_COM
        if(MessageRx_VRStepOpen == TRUE) /* TRUE or Active, based on Message define*/
        #endif
        #ifdef _CTCS_COM
        if(MessageRx_VRStepOpen == TRUE) /* TRUE or Active, based on Message define*/
        #endif 
        #ifdef _SGMW_COM
        if(MessageRx_VRStepOpen == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _SGM_COM
        if(MessageRx_VRStepOpen == TRUE) /* TRUE or Active, based on Message define*/
        #endif
        #ifdef _DEARCC_COM
        if(MessageRx_VRStepOpen == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _XIAOPENG_COM
        if(MessageRx_VRStepOpen == _Sw_Manual_Open) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _MAXUS_COM
        if(MessageRx_VRStepOpen == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _DFMC_COM
        if(MessageRx_VRStepOpen == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _BAIC_COM
        if(MessageRx_VRStepOpen == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _DFLZM_COM
        if(MessageRx_VRStepOpen == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _FAW_COM
        if(MessageRx_VRStepOpen == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _NIU_COM
        if(MessageRx_VRStepOpen == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _CHANGAN_COM
        if(MessageRx_VRStepOpen == TRUE) /* TRUE or Active, based on Message define*/
        #endif
        {
	     VRStepOpen_DataStream |= 0x0001;
        }
        if((MASK01BIT & VRStepOpen_DataStream) == MASK01BIT)
        {    
             VRStepOpen_Status = TRUE;
        }
        else if((MASK01BIT & VRStepOpen_DataStream) == 0)
        {
    	     VRStepOpen_Status = FALSE;
        }
    
        VRStepOpen_DataStream <<=1;
    	VRStepOpen_Real_Status = TRUE;
	VRStepOpen_Real_Timer = K_VRStepOpen_Real_Timeout;
    }
    /*Real-time Monitor*/
    if(TRUE == VRStepOpen_Real_Status)
    {
         if(VRStepOpen_Real_Timer == 0)
         {
	      VRStepOpen_Real_Status = FALSE;
	      if(TRUE == K_VRStepOpen_SingleEvent_Enable) /*10,1110 is MultiEvent, 1,111 is SingleEvent */
	      {
		   VRStepOpen_SingleEvent_Enable = TRUE;
	      }   
	      if(TRUE == VRStepOpen_SingleEvent_Enable)
	      {
		   VRStepOpen_SingleEvent_Enable = FALSE;
		   VRStepOpen_Status = FALSE;
		   MessageRx_VRStepOpen = FALSE;
	      }
         }
         else
         {
	      VRStepOpen_Real_Timer --;
         }
    } 
    
    /* VRStepOpen RiseEdge and FallEdge Active monitor */
    if((FALSE == VRStepOpen_Status) && (TRUE == VRStepOpen_LastStatus))
    {
    	 VRStepOpen_RiseEdge_Active = TRUE;
    } 
    else
    {
    	 VRStepOpen_RiseEdge_Active = FALSE;
    }
 
    if((TRUE == VRStepOpen_Status) && (FALSE == VRStepOpen_LastStatus))
    {
	 VRStepOpen_FallEdge_Active = TRUE;

    }	 
    else
    {
	 VRStepOpen_FallEdge_Active = FALSE;
    }
}
#endif
#ifdef _CONFIG_VRStepClose
/*********************************************************************************************
** Name:	  MessageDebounce_VRStepClose(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_VRStepClose(void)
{
     /*static uint16_t VRStepClose_Timer = 0;
     static uint16_t VRStepClose_ShortPress_Status = 0;
     static uint16_t VRStepClose_ShortPress_LastStatus = 0;
     static uint16_t VRStepClose_LongPress_Status = 0;
     static uint16_t VRStepClose_LongPress_LastStatus = 0;*/
     static uint16_t VRStepClose_Real_Timer;

  /* VRStepClose Status Active monitor */
    VRStepClose_LastStatus = VRStepClose_Status;
    
    if(TRUE == MessageRx_VRStepClose_Ind)
    {  
	MessageRx_VRStepClose_Ind = FALSE;
        
        #ifdef _CHERY_COM
        if(MessageRx_VRStepClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif
        #ifdef _CTCS_COM
        if(MessageRx_VRStepClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif
        #ifdef _SGMW_COM
        if(MessageRx_VRStepClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _SGM_COM
        if(MessageRx_VRStepClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif
        #ifdef _DEARCC_COM
        if(MessageRx_VRStepClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _XIAOPENG_COM
        if(MessageRx_VRStepClose == _Sw_Manual_Close) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _MAXUS_COM
        if(MessageRx_VRStepClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _DFMC_COM
        if(MessageRx_VRStepClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _BAIC_COM
        if(MessageRx_VRStepClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _DFLZM_COM
        if(MessageRx_VRStepClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _NIU_COM
        if(MessageRx_VRStepClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _FAW_COM
        if(MessageRx_VRStepClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _CHANGAN_COM
        if(MessageRx_VRStepClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif
        {
	     VRStepClose_DataStream |= 0x0001;
        }
        if((MASK01BIT & VRStepClose_DataStream) == MASK01BIT)
        {    
             VRStepClose_Status = TRUE;
        }
        else if((MASK01BIT & VRStepClose_DataStream) == 0)
        {
    	     VRStepClose_Status = FALSE;
        }
    
        VRStepClose_DataStream <<=1;
    	VRStepClose_Real_Status = TRUE;
	VRStepClose_Real_Timer = K_VRStepClose_Real_Timeout;
    }
    /*Real-time Monitor*/
    if(TRUE == VRStepClose_Real_Status)
    {
         if(VRStepClose_Real_Timer == 0)
         {
	      VRStepClose_Real_Status = FALSE;
	      if(TRUE == K_VRStepClose_SingleEvent_Enable) /*10,1110 is MultiEvent, 1,111 is SingleEvent */
	      {
		   VRStepClose_SingleEvent_Enable = TRUE;
	      }
	      if(TRUE == VRStepClose_SingleEvent_Enable)
	      {
		   VRStepClose_SingleEvent_Enable = FALSE;
		   VRStepClose_Status = FALSE;
		   MessageRx_VRStepClose = FALSE;
	      }
         }
         else
         {
	      VRStepClose_Real_Timer --;
         }
    } 

    /* VRStepClose RiseEdge and FallEdge Active monitor */
    if((FALSE == VRStepClose_Status) && (TRUE == VRStepClose_LastStatus))
    {
    	 VRStepClose_RiseEdge_Active = TRUE;
    }
    else
    {
    	 VRStepClose_RiseEdge_Active = FALSE;
    }

    if((TRUE == VRStepClose_Status) && (FALSE == VRStepClose_LastStatus))
    {
	 VRStepClose_FallEdge_Active = TRUE;

    }
    else
    {
	 VRStepClose_FallEdge_Active = FALSE;
    }
}
#endif

#ifdef _CONFIG_VoiceOpen
/*********************************************************************************************
** Name:	  MessageDebounce_VoiceOpen(void);
** Function:
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_VoiceOpen(void)
{
  
}
#endif
#ifdef _CONFIG_VoiceClose
/*********************************************************************************************
** Name:	  MessageDebounce_VoiceClose(void);
** Function:
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_VoiceClose(void)
{

}
#endif
#ifdef _CONFIG_VoiceStop
/*********************************************************************************************
** Name:	  MessageDebounce_VoiceStop(void);
** Function:
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_VoiceStop(void)
{
 
}
#endif

#ifdef _CONFIG_AutoOpen
/*********************************************************************************************
** Name:	  MessageDebounce_AutoOpen(void);
** Function:
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_AutoOpen(void)
{

}
#endif
#ifdef _CONFIG_AutoClose
/*********************************************************************************************
** Name:	  MessageDebounce_AutoClose(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_AutoClose(void)
{
    static uint16_t AutoClose_Real_Timer;
    
    /* AutoClose Status Active monitor */ 
    AutoClose_LastStatus = AutoClose_Status;
    
    if(TRUE == MessageRx_AutoClose_Ind)
    {  
	MessageRx_AutoClose_Ind = FALSE;
        
        #ifdef _SGMW_COM
        if(MessageRx_AutoClose == TRUE) /* TRUE or Active, based on Message define*/ 
        #endif
	#ifdef _SGM_COM
        if(MessageRx_AutoClose == TRUE) /* TRUE or Active, based on Message define*/ 
        #endif
        #ifdef _CHERY_COM
        if(MessageRx_AutoClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif
        #ifdef _CTCS_COM
        if(MessageRx_AutoClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif
        #ifdef _DEARCC_COM
        if(MessageRx_AutoClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _XIAOPENG_COM
        if(MessageRx_AutoClose == _Sw_Auto_Close) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _MAXUS_COM
        if(MessageRx_AutoClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _DFMC_COM
        if(MessageRx_AutoClose == _ivi_pot_SpeechCtrlOnOffSts_CLOSE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _BAIC_COM
        if(MessageRx_AutoClose == _SmtEntryFctCmd_lock_all_doors) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _DFLZM_COM
        if(MessageRx_AutoClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _NIU_COM
        if(MessageRx_AutoClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _FAW_COM
        if(MessageRx_AutoClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _CHANGAN_COM
        if(MessageRx_AutoClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif
        {
	     AutoClose_DataStream |= 0x0001;
        }
        if((MASK01BIT & AutoClose_DataStream) == MASK01BIT)	 
        {    
             AutoClose_Status = TRUE;
        }
        else if((MASK01BIT & AutoClose_DataStream) == 0)
        {
    	     AutoClose_Status = FALSE;
        }
    
        AutoClose_DataStream <<=1;
    	AutoClose_Real_Status = TRUE;
	AutoClose_Real_Timer = K_AutoClose_Real_Timeout;  
    }
    /*Real-time Monitor*/
    if(TRUE == AutoClose_Real_Status)
    {
         if(AutoClose_Real_Timer == 0)
         {
	      AutoClose_Real_Status = FALSE; 
	      if(TRUE == K_AutoClose_SingleEvent_Enable) /*10,1110 is MultiEvent, 1,111 is SingleEvent */
	      {
		   AutoClose_SingleEvent_Enable = TRUE;
	      }
	      if(TRUE == AutoClose_SingleEvent_Enable)
	      {
		   AutoClose_SingleEvent_Enable = FALSE;
		   AutoClose_Status = FALSE;
		   MessageRx_AutoClose = FALSE;
	      }
         }
         else
         {
	      AutoClose_Real_Timer --;
         }
    } 
  
    /* AutoClose RiseEdge and FallEdge Active monitor */  
    if((FALSE == AutoClose_Status) && (TRUE == AutoClose_LastStatus))
    {
    	 AutoClose_RiseEdge_Active = TRUE;
    } 
    else
    {
    	 AutoClose_RiseEdge_Active = FALSE;
    }
 
    if((TRUE == AutoClose_Status) && (FALSE == AutoClose_LastStatus))
    {
	 AutoClose_FallEdge_Active = TRUE;

    }	 
    else
    {
	 AutoClose_FallEdge_Active = FALSE;
    }		
}
#endif
#ifdef _CONFIG_AutoStop
/*********************************************************************************************
** Name:	  MessageDebounce_AutoStop(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_AutoStop(void)
{
     /*static uint16_t AutoStop_Timer = 0;
     static uint16_t AutoStop_ShortPress_Status = 0;
     static uint16_t AutoStop_ShortPress_LastStatus = 0;
     static uint16_t AutoStop_LongPress_Status = 0;
     static uint16_t AutoStop_LongPress_LastStatus = 0;*/
     static uint16_t AutoStop_Real_Timer;
     
  /* AutoStop Status Active monitor */  
    AutoStop_LastStatus = AutoStop_Status;
    
    if(TRUE == MessageRx_AutoStop_Ind)
    {  
	MessageRx_AutoStop_Ind = FALSE;
        
        #ifdef _CHERY_COM
        if(MessageRx_AutoStop == TRUE) /* TRUE or Active, based on Message define*/
        #endif
        #ifdef _CTCS_COM
        if(MessageRx_AutoStop == TRUE) /* TRUE or Active, based on Message define*/
        #endif 
        #ifdef _SGMW_COM
        if(MessageRx_AutoStop == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _SGM_COM
        if(MessageRx_AutoStop == TRUE) /* TRUE or Active, based on Message define*/
        #endif
        #ifdef _DEARCC_COM
        if(MessageRx_AutoStop == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _XIAOPENG_COM
        if(MessageRx_AutoStop == _Sw_Stop) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _MAXUS_COM
        if(MessageRx_AutoStop == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _DFMC_COM
        if(MessageRx_AutoStop == _ivi_pot_SpeechCtrlOnOffSts_STOP) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _BAIC_COM
        if(MessageRx_AutoStop == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _NIU_COM
        if(MessageRx_AutoStop == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _DFLZM_COM
        if(MessageRx_AutoStop == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _FAW_COM
        if(MessageRx_AutoStop == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _CHANGAN_COM
        if(MessageRx_AutoStop == TRUE) /* TRUE or Active, based on Message define*/
        #endif
        {
	     AutoStop_DataStream |= 0x0001;
        }
        if((MASK01BIT & AutoStop_DataStream) == MASK01BIT)	 
        {    
             AutoStop_Status = TRUE;
        }
        else if((MASK01BIT & AutoStop_DataStream) == 0)
        {
    	     AutoStop_Status = FALSE;
        }
    
        AutoStop_DataStream <<=1;
    	AutoStop_Real_Status = TRUE;
	AutoStop_Real_Timer = K_AutoStop_Real_Timeout;  
    }
    /*Real-time Monitor*/
    if(TRUE == AutoStop_Real_Status)
    {
         if(AutoStop_Real_Timer == 0)
         {
	      AutoStop_Real_Status = FALSE;
	      if(TRUE == K_AutoStop_SingleEvent_Enable) /*10,1110 is MultiEvent, 1,111 is SingleEvent */
	      {
		   AutoStop_SingleEvent_Enable = TRUE;
	      }   
	      if(TRUE == AutoStop_SingleEvent_Enable) 
	      {
		   AutoStop_SingleEvent_Enable = FALSE;
		   AutoStop_Status = FALSE;
		   MessageRx_AutoStop = FALSE;
	      }
         }
         else
         {
	      AutoStop_Real_Timer --;
         }
    } 
    
    /* AutoStop RiseEdge and FallEdge Active monitor */  
    if((FALSE == AutoStop_Status) && (TRUE == AutoStop_LastStatus))
    {
    	 AutoStop_RiseEdge_Active = TRUE;
    } 
    else
    {
    	 AutoStop_RiseEdge_Active = FALSE;
    }
 
    if((TRUE == AutoStop_Status) && (FALSE == AutoStop_LastStatus))
    {
	 AutoStop_FallEdge_Active = TRUE;

    }	 
    else
    {
	 AutoStop_FallEdge_Active = FALSE;
    }
}
#endif
#ifdef _CONFIG_AutoStepOpen
/*********************************************************************************************
** Name:	  MessageDebounce_AutoStepOpen(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_AutoStepOpen(void)
{
     /*static uint16_t AutoStepOpen_Timer = 0;
     static uint16_t AutoStepOpen_ShortPress_Status = 0;
     static uint16_t AutoStepOpen_ShortPress_LastStatus = 0;
     static uint16_t AutoStepOpen_LongPress_Status = 0;
     static uint16_t AutoStepOpen_LongPress_LastStatus = 0;*/
     static uint16_t AutoStepOpen_Real_Timer;
     
  /* AutoStepOpen Status Active monitor */  
    AutoStepOpen_LastStatus = AutoStepOpen_Status;
    
    if(TRUE == MessageRx_AutoStepOpen_Ind)
    {  
	MessageRx_AutoStepOpen_Ind = FALSE;
        
        #ifdef _CHERY_COM
        if(MessageRx_AutoStepOpen == TRUE) /* TRUE or Active, based on Message define*/
        #endif
        #ifdef _CTCS_COM
        if(MessageRx_AutoStepOpen == TRUE) /* TRUE or Active, based on Message define*/
        #endif 
        #ifdef _SGMW_COM
        if(MessageRx_AutoStepOpen == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _SGM_COM
        if(MessageRx_AutoStepOpen == TRUE) /* TRUE or Active, based on Message define*/
        #endif
        #ifdef _DEARCC_COM
        if(MessageRx_AutoStepOpen == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _XIAOPENG_COM
        if(MessageRx_AutoStepOpen == _Sw_Manual_Open) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _MAXUS_COM
        if(MessageRx_AutoStepOpen == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _DFMC_COM
        if(MessageRx_AutoStepOpen == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _BAIC_COM
        if(MessageRx_AutoStepOpen == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _NIU_COM
        if(MessageRx_AutoStepOpen == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _DFLZM_COM
        if(MessageRx_AutoStepOpen == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _FAW_COM
        if(MessageRx_AutoStepOpen == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _CHANGAN_COM
        if(MessageRx_AutoStepOpen == TRUE) /* TRUE or Active, based on Message define*/
        #endif
        {
	     AutoStepOpen_DataStream |= 0x0001;
        }
        if((MASK01BIT & AutoStepOpen_DataStream) == MASK01BIT)	 
        {    
             AutoStepOpen_Status = TRUE;
        }
        else if((MASK01BIT & AutoStepOpen_DataStream) == 0)
        {
    	     AutoStepOpen_Status = FALSE;
        }
    
        AutoStepOpen_DataStream <<=1;
    	AutoStepOpen_Real_Status = TRUE;
	AutoStepOpen_Real_Timer = K_AutoStepOpen_Real_Timeout;  
    }
    /*Real-time Monitor*/
    if(TRUE == AutoStepOpen_Real_Status)
    {
         if(AutoStepOpen_Real_Timer == 0)
         {
	      AutoStepOpen_Real_Status = FALSE;
	      if(TRUE == K_AutoStepOpen_SingleEvent_Enable) /*10,1110 is MultiEvent, 1,111 is SingleEvent */
	      {
		   AutoStepOpen_SingleEvent_Enable = TRUE;
	      }   
	      if(TRUE == AutoStepOpen_SingleEvent_Enable) 
	      {
		   AutoStepOpen_SingleEvent_Enable = FALSE;
		   AutoStepOpen_Status = FALSE;
		   MessageRx_AutoStepOpen = FALSE;
	      }
         }
         else
         {
	      AutoStepOpen_Real_Timer --;
         }
    } 
    
    /* AutoStepOpen RiseEdge and FallEdge Active monitor */  
    if((FALSE == AutoStepOpen_Status) && (TRUE == AutoStepOpen_LastStatus))
    {
    	 AutoStepOpen_RiseEdge_Active = TRUE;
    } 
    else
    {
    	 AutoStepOpen_RiseEdge_Active = FALSE;
    }
 
    if((TRUE == AutoStepOpen_Status) && (FALSE == AutoStepOpen_LastStatus))
    {
	 AutoStepOpen_FallEdge_Active = TRUE;

    }	 
    else
    {
	 AutoStepOpen_FallEdge_Active = FALSE;
    }
}
#endif
#ifdef _CONFIG_AutoStepClose
/*********************************************************************************************
** Name:	  MessageDebounce_AutoStepClose(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_AutoStepClose(void)
{
     /*static uint16_t AutoStepClose_Timer = 0;
     static uint16_t AutoStepClose_ShortPress_Status = 0;
     static uint16_t AutoStepClose_ShortPress_LastStatus = 0;
     static uint16_t AutoStepClose_LongPress_Status = 0;
     static uint16_t AutoStepClose_LongPress_LastStatus = 0;*/
     static uint16_t AutoStepClose_Real_Timer;
     
  /* AutoStepClose Status Active monitor */  
    AutoStepClose_LastStatus = AutoStepClose_Status;
    
    if(TRUE == MessageRx_AutoStepClose_Ind)
    {  
	MessageRx_AutoStepClose_Ind = FALSE;
        
        #ifdef _CHERY_COM
        if(MessageRx_AutoStepClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif
        #ifdef _CTCS_COM
        if(MessageRx_AutoStepClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif 
        #ifdef _SGMW_COM
        if(MessageRx_AutoStepClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _SGM_COM
        if(MessageRx_AutoStepClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif
        #ifdef _DEARCC_COM
        if(MessageRx_AutoStepClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _XIAOPENG_COM
        if(MessageRx_AutoStepClose == _Sw_Manual_Close) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _MAXUS_COM
        if(MessageRx_AutoStepClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _DFMC_COM
        if(MessageRx_AutoStepClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _BAIC_COM
        if(MessageRx_AutoStepClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _NIU_COM
        if(MessageRx_AutoStepClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _DFLZM_COM
        if(MessageRx_AutoStepClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _FAW_COM
        if(MessageRx_AutoStepClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _CHANGAN_COM
        if(MessageRx_AutoStepClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif
        {
	     AutoStepClose_DataStream |= 0x0001;
        }
        if((MASK01BIT & AutoStepClose_DataStream) == MASK01BIT)	 
        {    
             AutoStepClose_Status = TRUE;
        }
        else if((MASK01BIT & AutoStepClose_DataStream) == 0)
        {
    	     AutoStepClose_Status = FALSE;
        }
    
        AutoStepClose_DataStream <<=1;
    	AutoStepClose_Real_Status = TRUE;
	AutoStepClose_Real_Timer = K_AutoStepClose_Real_Timeout;  
    }
    /*Real-time Monitor*/
    if(TRUE == AutoStepClose_Real_Status)
    {
         if(AutoStepClose_Real_Timer == 0)
         {
	      AutoStepClose_Real_Status = FALSE;
	      if(TRUE == K_AutoStepClose_SingleEvent_Enable) /*10,1110 is MultiEvent, 1,111 is SingleEvent */
	      {
		   AutoStepClose_SingleEvent_Enable = TRUE;
	      }   
	      if(TRUE == AutoStepClose_SingleEvent_Enable) 
	      {
		   AutoStepClose_SingleEvent_Enable = FALSE;
		   AutoStepClose_Status = FALSE;
		   MessageRx_AutoStepClose = FALSE;
	      }
         }
         else
         {
	      AutoStepClose_Real_Timer --;
         }
    } 
    
    /* AutoStepClose RiseEdge and FallEdge Active monitor */  
    if((FALSE == AutoStepClose_Status) && (TRUE == AutoStepClose_LastStatus))
    {
    	 AutoStepClose_RiseEdge_Active = TRUE;
    } 
    else
    {
    	 AutoStepClose_RiseEdge_Active = FALSE;
    }
 
    if((TRUE == AutoStepClose_Status) && (FALSE == AutoStepClose_LastStatus))
    {
	 AutoStepClose_FallEdge_Active = TRUE;

    }	 
    else
    {
	 AutoStepClose_FallEdge_Active = FALSE;
    }
}
#endif
      
#ifdef _CONFIG_BLEOpen
/*********************************************************************************************
** Name:	  MessageDebounce_BLEOpen(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_BLEOpen(void)
{
     /*static uint16_t BLEOpen_Timer = 0;
     static uint16_t BLEOpen_ShortPress_Status = 0;
     static uint16_t BLEOpen_ShortPress_LastStatus = 0;
     static uint16_t BLEOpen_LongPress_Status = 0;
     static uint16_t BLEOpen_LongPress_LastStatus = 0;*/
     static uint16_t BLEOpen_Real_Timer;
     
  /* BLEOpen Status Active monitor */  
    BLEOpen_LastStatus = BLEOpen_Status;
    
    if(TRUE == MessageRx_BLEOpen_Ind)
    {  
	MessageRx_BLEOpen_Ind = FALSE;
        
        #ifdef _CHERY_COM
	    #ifdef _CHERY_COM_PD 
        if(MessageRx_BLEOpen == TRUE) /* TRUE or Active, based on Message define*/
	    #endif
        #endif
        #ifdef _CTCS_COM
        if(MessageRx_BLEOpen == TRUE) /* TRUE or Active, based on Message define*/
        #endif 
        #ifdef _SGMW_COM
        if(MessageRx_BLEOpen == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _SGM_COM
        if(MessageRx_BLEOpen == TRUE) /* TRUE or Active, based on Message define*/
        #endif
        #ifdef _DEARCC_COM
        if(MessageRx_BLEOpen == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _XIAOPENG_COM
        if(MessageRx_BLEOpen == _Sw_Auto_Open) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _MAXUS_COM
	    #ifdef _MAXUS_COM_PSD
        if(MessageRx_BLEOpen == _InCarCtrlReq_iCGM_Open) /* TRUE or Active, based on Message define*/
	    #endif
        #endif
	#ifdef _DFMC_COM
        if(MessageRx_BLEOpen == _ble_rke_tailgateCtrlReq_Open) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _BAIC_COM
	     #if defined(_BAIC_COM_C52X) || defined(_BAIC_COM_C62X)
        if((MessageRx_BLEOpen == _BlePtmOperCmd_Open) && (VehiclePowerMode == PowerMode_OFF)) /* TRUE or Active, based on Message define*/
	     #endif
	     #if defined(_BAIC_COM_C46DB) || defined(_BAIC_COM_B30X)
        if(MessageRx_BLEOpen == _BlePtmOperCmd_Open) /* TRUE or Active, based on Message define*/
	     #endif
        #endif
	#ifdef _NIU_COM
        if(MessageRx_BLEOpen == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _DFLZM_COM
        if(MessageRx_BLEOpen == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _FAW_COM
        if(MessageRx_BLEOpen == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _CHANGAN_COM
        if(MessageRx_BLEOpen == TRUE) /* TRUE or Active, based on Message define*/
        #endif
        {
	     BLEOpen_DataStream |= 0x0001;
        }
        if((MASK01BIT & BLEOpen_DataStream) == MASK01BIT)	 
        {    
             BLEOpen_Status = TRUE;
        }
        else if((MASK01BIT & BLEOpen_DataStream) == 0)
        {
    	     BLEOpen_Status = FALSE;
        }
    
        BLEOpen_DataStream <<=1;
    	BLEOpen_Real_Status = TRUE;
	BLEOpen_Real_Timer = K_BLEOpen_Real_Timeout;  
    }
    /*Real-time Monitor*/
    if(TRUE == BLEOpen_Real_Status)
    {
         if(BLEOpen_Real_Timer == 0)
         {
	      BLEOpen_Real_Status = FALSE;
	      if(TRUE == K_BLEOpen_SingleEvent_Enable) /*10,1110 is MultiEvent, 1,111 is SingleEvent */
	      {
		   BLEOpen_SingleEvent_Enable = TRUE;
	      }   
	      if(TRUE == BLEOpen_SingleEvent_Enable) 
	      {
		   BLEOpen_SingleEvent_Enable = FALSE;
		   BLEOpen_Status = FALSE;
		   MessageRx_BLEOpen = FALSE;
	      }
         }
         else
         {
	      BLEOpen_Real_Timer --;
         }
    } 
    
    /* BLEOpen RiseEdge and FallEdge Active monitor */  
    if((FALSE == BLEOpen_Status) && (TRUE == BLEOpen_LastStatus))
    {
    	 BLEOpen_RiseEdge_Active = TRUE;
    } 
    else
    {
    	 BLEOpen_RiseEdge_Active = FALSE;
    }
 
    if((TRUE == BLEOpen_Status) && (FALSE == BLEOpen_LastStatus))
    {
	 BLEOpen_FallEdge_Active = TRUE;

    }	 
    else
    {
	 BLEOpen_FallEdge_Active = FALSE;
    }
}
#endif
#ifdef _CONFIG_BLEClose
/*********************************************************************************************
** Name:	  MessageDebounce_BLEClose(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_BLEClose(void)
{

}
#endif
#ifdef _CONFIG_BLEStop
/*********************************************************************************************
** Name:	  MessageDebounce_BLEStop(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_BLEStop(void)
{
     /*static uint16_t BLEStop_Timer = 0;
     static uint16_t BLEStop_ShortPress_Status = 0;
     static uint16_t BLEStop_ShortPress_LastStatus = 0;
     static uint16_t BLEStop_LongPress_Status = 0;
     static uint16_t BLEStop_LongPress_LastStatus = 0;*/
     static uint16_t BLEStop_Real_Timer;
     
  /* BLEStop Status Active monitor */  
    BLEStop_LastStatus = BLEStop_Status;
    
    if(TRUE == MessageRx_BLEStop_Ind)
    {  
	MessageRx_BLEStop_Ind = FALSE;
        
        #ifdef _CHERY_COM
        if(MessageRx_BLEStop == TRUE) /* TRUE or Active, based on Message define*/
        #endif
        #ifdef _CTCS_COM
        if(MessageRx_BLEStop == TRUE) /* TRUE or Active, based on Message define*/
        #endif 
        #ifdef _SGMW_COM
        if(MessageRx_BLEStop == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _SGM_COM
        if(MessageRx_BLEStop == TRUE) /* TRUE or Active, based on Message define*/
        #endif
        #ifdef _DEARCC_COM
        if(MessageRx_BLEStop == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _XIAOPENG_COM
        if(MessageRx_BLEStop == _Sw_Stop) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _MAXUS_COM
	    #ifdef _MAXUS_COM
        if(MessageRx_BLEStop == _InCarCtrlReq_iCGM_Hold) /* TRUE or Active, based on Message define*/
	    #endif
        #endif
	#ifdef _DFMC_COM
        if(MessageRx_BLEStop == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _BAIC_COM
	     #if defined(_BAIC_COM_C52X) || defined(_BAIC_COM_C62X)
        if((MessageRx_BLEStop == _BlePtmOperCmd_stop) && (VehiclePowerMode == PowerMode_OFF)) /* TRUE or Active, based on Message define*/
	     #endif
	     #if defined(_BAIC_COM_C46DB) || defined(_BAIC_COM_B30X)
        if(MessageRx_BLEStop == _BlePtmOperCmd_stop) /* TRUE or Active, based on Message define*/
	     #endif
        #endif
	#ifdef _DFLZM_COM
        if(MessageRx_BLEStop == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _NIU_COM
        if(MessageRx_BLEStop == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _FAW_COM
        if(MessageRx_BLEStop == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _CHANGAN_COM
        if(MessageRx_BLEStop == TRUE) /* TRUE or Active, based on Message define*/
        #endif
        {
	     BLEStop_DataStream |= 0x0001;
        }
        if((MASK01BIT & BLEStop_DataStream) == MASK01BIT)	 
        {    
             BLEStop_Status = TRUE;
        }
        else if((MASK01BIT & BLEStop_DataStream) == 0)
        {
    	     BLEStop_Status = FALSE;
        }
    
        BLEStop_DataStream <<=1;
    	BLEStop_Real_Status = TRUE;
	BLEStop_Real_Timer = K_BLEStop_Real_Timeout;  
    }
    /*Real-time Monitor*/
    if(TRUE == BLEStop_Real_Status)
    {
         if(BLEStop_Real_Timer == 0)
         {
	      BLEStop_Real_Status = FALSE;
	      if(TRUE == K_BLEStop_SingleEvent_Enable) /*10,1110 is MultiEvent, 1,111 is SingleEvent */
	      {
		   BLEStop_SingleEvent_Enable = TRUE;
	      }   
	      if(TRUE == BLEStop_SingleEvent_Enable) 
	      {
		   BLEStop_SingleEvent_Enable = FALSE;
		   BLEStop_Status = FALSE;
		   MessageRx_BLEStop = FALSE;
	      }
         }
         else
         {
	      BLEStop_Real_Timer --;
         }
    } 
    
    /* BLEStop RiseEdge and FallEdge Active monitor */  
    if((FALSE == BLEStop_Status) && (TRUE == BLEStop_LastStatus))
    {
    	 BLEStop_RiseEdge_Active = TRUE;
    } 
    else
    {
    	 BLEStop_RiseEdge_Active = FALSE;
    }
 
    if((TRUE == BLEStop_Status) && (FALSE == BLEStop_LastStatus))
    {
	 BLEStop_FallEdge_Active = TRUE;

    }	 
    else
    {
	 BLEStop_FallEdge_Active = FALSE;
    }
}
#endif
#ifdef _CONFIG_BLEStepOpen
/*********************************************************************************************
** Name:	  MessageDebounce_BLEStepOpen(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_BLEStepOpen(void)
{
     /*static uint16_t BLEStepOpen_Timer = 0;
     static uint16_t BLEStepOpen_ShortPress_Status = 0;
     static uint16_t BLEStepOpen_ShortPress_LastStatus = 0;
     static uint16_t BLEStepOpen_LongPress_Status = 0;
     static uint16_t BLEStepOpen_LongPress_LastStatus = 0;*/
     static uint16_t BLEStepOpen_Real_Timer;
     
  /* BLEStepOpen Status Active monitor */  
    BLEStepOpen_LastStatus = BLEStepOpen_Status;
    
    if(TRUE == MessageRx_BLEStepOpen_Ind)
    {  
	MessageRx_BLEStepOpen_Ind = FALSE;
        
        #ifdef _CHERY_COM
        if(MessageRx_BLEStepOpen == TRUE) /* TRUE or Active, based on Message define*/
        #endif
        #ifdef _CTCS_COM
        if(MessageRx_BLEStepOpen == TRUE) /* TRUE or Active, based on Message define*/
        #endif 
        #ifdef _SGMW_COM
        if(MessageRx_BLEStepOpen == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _SGM_COM
        if(MessageRx_BLEStepOpen == TRUE) /* TRUE or Active, based on Message define*/
        #endif
        #ifdef _DEARCC_COM
        if(MessageRx_BLEStepOpen == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _XIAOPENG_COM
        if(MessageRx_BLEStepOpen == _Sw_Manual_Open) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _MAXUS_COM
        if(MessageRx_BLEStepOpen == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _DFMC_COM
        if(MessageRx_BLEStepOpen == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _BAIC_COM
        if(MessageRx_BLEStepOpen == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _DFLZM_COM
        if(MessageRx_BLEStepOpen == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _NIU_COM
        if(MessageRx_BLEStepOpen == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _FAW_COM
        if(MessageRx_BLEStepOpen == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _CHANGAN_COM
        if(MessageRx_BLEStepOpen == TRUE) /* TRUE or Active, based on Message define*/
        #endif
        {
	     BLEStepOpen_DataStream |= 0x0001;
        }
        if((MASK01BIT & BLEStepOpen_DataStream) == MASK01BIT)	 
        {    
             BLEStepOpen_Status = TRUE;
        }
        else if((MASK01BIT & BLEStepOpen_DataStream) == 0)
        {
    	     BLEStepOpen_Status = FALSE;
        }
    
        BLEStepOpen_DataStream <<=1;
    	BLEStepOpen_Real_Status = TRUE;
	BLEStepOpen_Real_Timer = K_BLEStepOpen_Real_Timeout;  
    }
    /*Real-time Monitor*/
    if(TRUE == BLEStepOpen_Real_Status)
    {
         if(BLEStepOpen_Real_Timer == 0)
         {
	      BLEStepOpen_Real_Status = FALSE;
	      if(TRUE == K_BLEStepOpen_SingleEvent_Enable) /*10,1110 is MultiEvent, 1,111 is SingleEvent */
	      {
		   BLEStepOpen_SingleEvent_Enable = TRUE;
	      }   
	      if(TRUE == BLEStepOpen_SingleEvent_Enable) 
	      {
		   BLEStepOpen_SingleEvent_Enable = FALSE;
		   BLEStepOpen_Status = FALSE;
		   MessageRx_BLEStepOpen = FALSE;
	      }
         }
         else
         {
	      BLEStepOpen_Real_Timer --;
         }
    } 
    
    /* BLEStepOpen RiseEdge and FallEdge Active monitor */  
    if((FALSE == BLEStepOpen_Status) && (TRUE == BLEStepOpen_LastStatus))
    {
    	 BLEStepOpen_RiseEdge_Active = TRUE;
    } 
    else
    {
    	 BLEStepOpen_RiseEdge_Active = FALSE;
    }
 
    if((TRUE == BLEStepOpen_Status) && (FALSE == BLEStepOpen_LastStatus))
    {
	 BLEStepOpen_FallEdge_Active = TRUE;

    }	 
    else
    {
	 BLEStepOpen_FallEdge_Active = FALSE;
    }
}
#endif
#ifdef _CONFIG_BLEStepClose
/*********************************************************************************************
** Name:	  MessageDebounce_BLEStepClose(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_BLEStepClose(void)
{
     /*static uint16_t BLEStepClose_Timer = 0;
     static uint16_t BLEStepClose_ShortPress_Status = 0;
     static uint16_t BLEStepClose_ShortPress_LastStatus = 0;
     static uint16_t BLEStepClose_LongPress_Status = 0;
     static uint16_t BLEStepClose_LongPress_LastStatus = 0;*/
     static uint16_t BLEStepClose_Real_Timer;
     
  /* BLEStepClose Status Active monitor */  
    BLEStepClose_LastStatus = BLEStepClose_Status;
    
    if(TRUE == MessageRx_BLEStepClose_Ind)
    {  
	MessageRx_BLEStepClose_Ind = FALSE;
        
        #ifdef _CHERY_COM
        if(MessageRx_BLEStepClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif
        #ifdef _CTCS_COM
        if(MessageRx_BLEStepClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif 
        #ifdef _SGMW_COM
        if(MessageRx_BLEStepClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _SGM_COM
        if(MessageRx_BLEStepClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif
        #ifdef _DEARCC_COM
        if(MessageRx_BLEStepClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _XIAOPENG_COM
        if(MessageRx_BLEStepClose == _Sw_Manual_Close) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _MAXUS_COM
        if(MessageRx_BLEStepClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _DFMC_COM
        if(MessageRx_BLEStepClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _BAIC_COM
        if(MessageRx_BLEStepClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _DFLZM_COM
        if(MessageRx_BLEStepClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _NIU_COM
        if(MessageRx_BLEStepClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _FAW_COM
        if(MessageRx_BLEStepClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _CHANGAN_COM
        if(MessageRx_BLEStepClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif
        {
	     BLEStepClose_DataStream |= 0x0001;
        }
        if((MASK01BIT & BLEStepClose_DataStream) == MASK01BIT)	 
        {    
             BLEStepClose_Status = TRUE;
        }
        else if((MASK01BIT & BLEStepClose_DataStream) == 0)
        {
    	     BLEStepClose_Status = FALSE;
        }
    
        BLEStepClose_DataStream <<=1;
    	BLEStepClose_Real_Status = TRUE;
	BLEStepClose_Real_Timer = K_BLEStepClose_Real_Timeout;  
    }
    /*Real-time Monitor*/
    if(TRUE == BLEStepClose_Real_Status)
    {
         if(BLEStepClose_Real_Timer == 0)
         {
	      BLEStepClose_Real_Status = FALSE;
	      if(TRUE == K_BLEStepClose_SingleEvent_Enable) /*10,1110 is MultiEvent, 1,111 is SingleEvent */
	      {
		   BLEStepClose_SingleEvent_Enable = TRUE;
	      }   
	      if(TRUE == BLEStepClose_SingleEvent_Enable) 
	      {
		   BLEStepClose_SingleEvent_Enable = FALSE;
		   BLEStepClose_Status = FALSE;
		   MessageRx_BLEStepClose = FALSE;
	      }
         }
         else
         {
	      BLEStepClose_Real_Timer --;
         }
    } 
    
    /* BLEStepClose RiseEdge and FallEdge Active monitor */  
    if((FALSE == BLEStepClose_Status) && (TRUE == BLEStepClose_LastStatus))
    {
    	 BLEStepClose_RiseEdge_Active = TRUE;
    } 
    else
    {
    	 BLEStepClose_RiseEdge_Active = FALSE;
    }
 
    if((TRUE == BLEStepClose_Status) && (FALSE == BLEStepClose_LastStatus))
    {
	 BLEStepClose_FallEdge_Active = TRUE;

    }	 
    else
    {
	 BLEStepClose_FallEdge_Active = FALSE;
    }
}
#endif
#ifdef _CONFIG_BLEButton
/*********************************************************************************************
** Name:	  MessageDebounce_BLEButton(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_BLEButton(void)
{

}
#endif

#ifdef _CONFIG_RKEOpen
/*********************************************************************************************
** Name:	  MessageDebounce_RKEOpen(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_RKEOpen(void)
{

}
#endif
#ifdef _CONFIG_RKEClose
/*********************************************************************************************
** Name:	  MessageDebounce_RKEClose(void);
** Function:
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_RKEClose(void)
{

}
#endif
#ifdef _CONFIG_RKEStopOpen
/*********************************************************************************************
** Name:	  MessageDebounce_RKEStopOpen(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_RKEStopOpen(void)
{

}
#endif
#ifdef _CONFIG_RKEStopClose
/*********************************************************************************************
** Name:	  MessageDebounce_RKEStopClose(void);
** Function:
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_RKEStopClose(void)
{
 
}
#endif
#ifdef _CONFIG_RKEStepOpen
/*********************************************************************************************
** Name:	  MessageDebounce_RKEStepOpen(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_RKEStepOpen(void)
{
     /*static uint16_t RKEStepOpen_Timer = 0;
     static uint16_t RKEStepOpen_ShortPress_Status = 0;
     static uint16_t RKEStepOpen_ShortPress_LastStatus = 0;
     static uint16_t RKEStepOpen_LongPress_Status = 0;
     static uint16_t RKEStepOpen_LongPress_LastStatus = 0;*/
     static uint16_t RKEStepOpen_Real_Timer;
     
  /* RKEStepOpen Status Active monitor */  
    RKEStepOpen_LastStatus = RKEStepOpen_Status;
    
    if(TRUE == MessageRx_RKEStepOpen_Ind)
    {  
	MessageRx_RKEStepOpen_Ind = FALSE;
        
        #ifdef _CHERY_COM
        if(MessageRx_RKEStepOpen == TRUE) /* TRUE or Active, based on Message define*/
        #endif
        #ifdef _CTCS_COM
        if(MessageRx_RKEStepOpen == TRUE) /* TRUE or Active, based on Message define*/
        #endif 
        #ifdef _SGMW_COM
        if(MessageRx_RKEStepOpen == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _SGM_COM
        if(MessageRx_RKEStepOpen == TRUE) /* TRUE or Active, based on Message define*/
        #endif
        #ifdef _DEARCC_COM
        if(MessageRx_RKEStepOpen == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _XIAOPENG_COM
	if((MessageRx_RKEStepOpen == _KEY_LONG_PRESS) /* TRUE or Active, based on Message define*/
	   #ifdef _XIAOPENG_SDCR
	   &&(Vehicle_KeyOpenMode == _KeyModeCtrlCfgFB_Front_Door)
	   #endif
	   )
        #endif
	#ifdef _MAXUS_COM
        if(MessageRx_RKEStepOpen == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _DFMC_COM
        if(MessageRx_RKEStepOpen == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _BAIC_COM
        if(MessageRx_RKEStepOpen == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _DFLZM_COM
        if(MessageRx_RKEStepOpen == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _NIU_COM
        if(MessageRx_RKEStepOpen == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _FAW_COM
        if(MessageRx_RKEStepOpen == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _CHANGAN_COM
        if(MessageRx_RKEStepOpen == TRUE) /* TRUE or Active, based on Message define*/
        #endif
        {
	     RKEStepOpen_DataStream |= 0x0001;
        }
        if((MASK01BIT & RKEStepOpen_DataStream) == MASK01BIT)	 
        {    
             RKEStepOpen_Status = TRUE;
        }
        else if((MASK01BIT & RKEStepOpen_DataStream) == 0)
        {
    	     RKEStepOpen_Status = FALSE;
        }
    
        RKEStepOpen_DataStream <<=1;
    	RKEStepOpen_Real_Status = TRUE;
	RKEStepOpen_Real_Timer = K_RKEStepOpen_Real_Timeout;  
    }
    /*Real-time Monitor*/
    if(TRUE == RKEStepOpen_Real_Status)
    {
         if(RKEStepOpen_Real_Timer == 0)
         {
	      RKEStepOpen_Real_Status = FALSE;
	      if(TRUE == K_RKEStepOpen_SingleEvent_Enable) /*10,1110 is MultiEvent, 1,111 is SingleEvent */
	      {
		   RKEStepOpen_SingleEvent_Enable = TRUE;
	      }   
	      if(TRUE == RKEStepOpen_SingleEvent_Enable) 
	      {
		   RKEStepOpen_SingleEvent_Enable = FALSE;
		   RKEStepOpen_Status = FALSE;
		   MessageRx_RKEStepOpen = FALSE;
	      }
         }
         else
         {
	      RKEStepOpen_Real_Timer --;
         }
    } 
    
    /* RKEStepOpen RiseEdge and FallEdge Active monitor */  
    if((FALSE == RKEStepOpen_Status) && (TRUE == RKEStepOpen_LastStatus))
    {
    	 RKEStepOpen_RiseEdge_Active = TRUE;
    } 
    else
    {
    	 RKEStepOpen_RiseEdge_Active = FALSE;
    }
 
    if((TRUE == RKEStepOpen_Status) && (FALSE == RKEStepOpen_LastStatus))
    {
	 RKEStepOpen_FallEdge_Active = TRUE;

    }	 
    else
    {
	 RKEStepOpen_FallEdge_Active = FALSE;
    }
}
#endif
#ifdef _CONFIG_RKEStepClose
/*********************************************************************************************
** Name:	  MessageDebounce_RKEStepClose(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_RKEStepClose(void)
{
     /*static uint16_t RKEStepClose_Timer = 0;
     static uint16_t RKEStepClose_ShortPress_Status = 0;
     static uint16_t RKEStepClose_ShortPress_LastStatus = 0;
     static uint16_t RKEStepClose_LongPress_Status = 0;
     static uint16_t RKEStepClose_LongPress_LastStatus = 0;*/
     static uint16_t RKEStepClose_Real_Timer;
     
  /* RKEStepClose Status Active monitor */  
    RKEStepClose_LastStatus = RKEStepClose_Status;
    
    if(TRUE == MessageRx_RKEStepClose_Ind)
    {  
	MessageRx_RKEStepClose_Ind = FALSE;
        
        #ifdef _CHERY_COM
        if(MessageRx_RKEStepClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif
        #ifdef _CTCS_COM
        if(MessageRx_RKEStepClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif 
        #ifdef _SGMW_COM
        if(MessageRx_RKEStepClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _SGM_COM
        if(MessageRx_RKEStepClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif
        #ifdef _DEARCC_COM
        if(MessageRx_RKEStepClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _XIAOPENG_COM
	if((MessageRx_RKEStepClose == _KEY_LONG_PRESS) /* TRUE or Active, based on Message define*/
	   #ifdef _XIAOPENG_SDCR
	   &&(Vehicle_KeyCloseMode == _KeyModeCtrlCfgFB_Front_Door)
	   #endif
	   )
        #endif
	#ifdef _MAXUS_COM
        if(MessageRx_RKEStepClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _DFMC_COM
        if(MessageRx_RKEStepClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _BAIC_COM
        if(MessageRx_RKEStepClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _DFLZM_COM
        if(MessageRx_RKEStepClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _NIU_COM
        if(MessageRx_RKEStepClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _FAW_COM
        if(MessageRx_RKEStepClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _CHANGAN_COM
        if(MessageRx_RKEStepClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif
        {
	     RKEStepClose_DataStream |= 0x0001;
        }
        if((MASK01BIT & RKEStepClose_DataStream) == MASK01BIT)
        {    
             RKEStepClose_Status = TRUE;
        }
        else if((MASK01BIT & RKEStepClose_DataStream) == 0)
        {
    	     RKEStepClose_Status = FALSE;
        }
    
        RKEStepClose_DataStream <<=1;
    	RKEStepClose_Real_Status = TRUE;
	RKEStepClose_Real_Timer = K_RKEStepClose_Real_Timeout;
    }
    /*Real-time Monitor*/
    if(TRUE == RKEStepClose_Real_Status)
    {
         if(RKEStepClose_Real_Timer == 0)
         {
	      RKEStepClose_Real_Status = FALSE;
	      if(TRUE == K_RKEStepClose_SingleEvent_Enable) /*10,1110 is MultiEvent, 1,111 is SingleEvent */
	      {
		   RKEStepClose_SingleEvent_Enable = TRUE;
	      }
	      if(TRUE == RKEStepClose_SingleEvent_Enable)
	      {
		   RKEStepClose_SingleEvent_Enable = FALSE;
		   RKEStepClose_Status = FALSE;
		   MessageRx_RKEStepClose = FALSE;
	      }
         }
         else
         {
	      RKEStepClose_Real_Timer --;
         }
    } 

    /* RKEStepClose RiseEdge and FallEdge Active monitor */
    if((FALSE == RKEStepClose_Status) && (TRUE == RKEStepClose_LastStatus))
    {
    	 RKEStepClose_RiseEdge_Active = TRUE;
    } 
    else
    {
    	 RKEStepClose_RiseEdge_Active = FALSE;
    }
 
    if((TRUE == RKEStepClose_Status) && (FALSE == RKEStepClose_LastStatus))
    {
	 RKEStepClose_FallEdge_Active = TRUE;

    }	 
    else
    {
	 RKEStepClose_FallEdge_Active = FALSE;
    }
}
#endif


#ifdef _CONFIG_InsideButton
/*********************************************************************************************
** Name:	  MessageDebounce_InsideButton(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_InsideButton(void)
{
 
}
#endif
#ifdef _CONFIG_DriverButton
/*********************************************************************************************
** Name:	  MessageDebounce_DriverButton(void);
** Function:
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_DriverButton(void)
{

}
#endif
#ifdef _CONFIG_DriverButtonStop
/*********************************************************************************************
** Name:	  MessageDebounce_DriverButtonStop(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_DriverButtonStop(void)
{
    static uint16_t DriverButtonStop_Real_Timer;
    
  /* DriverButtonStop Status Active monitor */ 
    DriverButtonStop_LastStatus = DriverButtonStop_Status;
    
    if(TRUE == MessageRx_DriverButtonStop_Ind)
    {  
	MessageRx_DriverButtonStop_Ind = FALSE;
        
        #ifdef _CHERY_COM
        if(MessageRx_DriverButtonStop == TRUE) /* TRUE or Active, based on Message define*/
        #endif
        #ifdef _SGMW_COM
        if(MessageRx_DriverButtonStop == TRUE)/* TRUE or Active, based on Message define*/
        #endif
	#ifdef _SGM_COM
        if(MessageRx_DriverButtonStop == TRUE)/* TRUE or Active, based on Message define*/
        #endif
        #ifdef _CTCS_COM
        if(MessageRx_DriverButtonStop == _COCKPIT_STOP)/* TRUE or Active, based on Message define*/
        #endif
        #ifdef _DEARCC_COM
        if(MessageRx_DriverButtonStop == TRUE) /* TRUE or Active, based on Message define*/
        #endif 
	#ifdef _XIAOPENG_COM
        if(MessageRx_DriverButtonStop == TRUE) /* TRUE or Active, based on Message define*/
        #endif 
	#ifdef _MAXUS_COM
        if(MessageRx_DriverButtonStop == TRUE) /* TRUE or Active, based on Message define*/
	#endif
	#ifdef _DFMC_COM
        if(MessageRx_DriverButtonStop == TRUE) /* TRUE or Active, based on Message define*/
	#endif
	#ifdef _BAIC_COM
        if(MessageRx_DriverButtonStop == TRUE) /* TRUE or Active, based on Message define*/
	#endif
	#ifdef _DFLZM_COM
        if(MessageRx_DriverButtonStop == TRUE) /* TRUE or Active, based on Message define*/
	#endif
	#ifdef _NIU_COM
        if(MessageRx_DriverButtonStop == TRUE) /* TRUE or Active, based on Message define*/
	#endif
	#ifdef _FAW_COM
        if(MessageRx_DriverButtonStop == TRUE) /* TRUE or Active, based on Message define*/
	#endif
	#ifdef _CHANGAN_COM
        if(MessageRx_DriverButtonStop == TRUE) /* TRUE or Active, based on Message define*/
        #endif
        {
	     DriverButtonStop_DataStream |= 0x0001;
        }
	if((MASK01BIT & DriverButtonStop_DataStream) == MASK01BIT)
        {    
             DriverButtonStop_Status = TRUE;
        }
        else if((MASK01BIT & DriverButtonStop_DataStream) == 0)
        {
    	     DriverButtonStop_Status = FALSE;
        }
    
        DriverButtonStop_DataStream <<=1;
    	DriverButtonStop_Real_Status = TRUE;
	DriverButtonStop_Real_Timer = K_DriverButtonStop_Real_Timeout;  
    }
    /*Real-time Monitor*/
    if(TRUE == DriverButtonStop_Real_Status)
    {
         if(DriverButtonStop_Real_Timer == 0)
         {
	      DriverButtonStop_Real_Status = FALSE; 
	      if(TRUE == K_DriverButtonStop_SingleEvent_Enable) /*10,1110 is Multi Event, 1,111 is */
	      {
		   DriverButtonStop_SingleEvent_Enable = TRUE;
	      }
	      if(TRUE == DriverButtonStop_SingleEvent_Enable)
	      {
		   DriverButtonStop_SingleEvent_Enable = FALSE;
		   DriverButtonStop_Status = FALSE;
		   MessageRx_DriverButtonStop = FALSE;
	      }
         }
         else
         {
	      DriverButtonStop_Real_Timer --;
         }
    } 
  
    /* DriverButtonStop RiseEdge and FallEdge Active monitor */  
    if((FALSE == DriverButtonStop_Status) && (TRUE == DriverButtonStop_LastStatus))
    {
    	 DriverButtonStop_RiseEdge_Active = TRUE;
    } 
    else
    {
    	 DriverButtonStop_RiseEdge_Active = FALSE;
    }
 
    if((TRUE == DriverButtonStop_Status) && (FALSE == DriverButtonStop_LastStatus))
    {
	 DriverButtonStop_FallEdge_Active = TRUE;

    }	 
    else
    {
	 DriverButtonStop_FallEdge_Active = FALSE;
    }	
}
#endif
#ifdef _CONFIG_SeatOccupied
/*********************************************************************************************
** Name:	  MessageDebounce_SeatOccupied(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_SeatOccupied(void)
{
    static uint16_t SeatOccupied_Real_Timer;
    
  /* SeatOccupied Status Active monitor */ 
    SeatOccupied_LastStatus = SeatOccupied_Status;
    
    if(TRUE == MessageRx_SeatOccupied_Ind)
    {  
	MessageRx_SeatOccupied_Ind = FALSE;
        
        #ifdef _CHERY_COM
        if(MessageRx_SeatOccupied == _SeatOccupiedSts_Active) /* TRUE or Active, based on Message define*/
        #endif
        #ifdef _SGMW_COM
        if(MessageRx_SeatOccupied == TRUE)/* TRUE or Active, based on Message define*/
        #endif
	#ifdef _SGM_COM
        if(MessageRx_SeatOccupied == TRUE)/* TRUE or Active, based on Message define*/
        #endif
        #ifdef _CTCS_COM
        if(MessageRx_SeatOccupied == TRUE)/* TRUE or Active, based on Message define*/
        #endif
        #ifdef _DEARCC_COM
        if(MessageRx_SeatOccupied == TRUE) /* TRUE or Active, based on Message define*/
        #endif 
	#ifdef _XIAOPENG_COM
        if(MessageRx_SeatOccupied == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _MAXUS_COM
        if(MessageRx_SeatOccupied == TRUE) /* TRUE or Active, based on Message define*/
	#endif
	#ifdef _DFMC_COM
        if(MessageRx_SeatOccupied == TRUE) /* TRUE or Active, based on Message define*/
	#endif
	#ifdef _BAIC_COM
        if(MessageRx_SeatOccupied == TRUE) /* TRUE or Active, based on Message define*/
	#endif
	#ifdef _DFLZM_COM
        if(MessageRx_SeatOccupied == TRUE) /* TRUE or Active, based on Message define*/
	#endif
	#ifdef _NIU_COM
        if(MessageRx_SeatOccupied == TRUE) /* TRUE or Active, based on Message define*/
	#endif
	#ifdef _FAW_COM
        if(MessageRx_SeatOccupied == TRUE) /* TRUE or Active, based on Message define*/
	#endif
	#ifdef _CHANGAN_COM
        if(MessageRx_SeatOccupied == TRUE) /* TRUE or Active, based on Message define*/
        #endif
        {
	     SeatOccupied_DataStream |= 0x0001;
        }

	if((MASK01BIT & SeatOccupied_DataStream) == MASK01BIT)
        {    
             SeatOccupied_Status = TRUE;
        }
        else if((MASK01BIT & SeatOccupied_DataStream) == 0)
        {
    	     SeatOccupied_Status = FALSE;
        }
    
        SeatOccupied_DataStream <<=1;
    	SeatOccupied_Real_Status = TRUE;
	SeatOccupied_Real_Timer = K_SeatOccupied_Real_Timeout;  
    }
    /*Real-time Monitor*/
    if(TRUE == SeatOccupied_Real_Status)
    {
         if(SeatOccupied_Real_Timer == 0)
         {
	      SeatOccupied_Real_Status = FALSE; 
	      if(TRUE == K_SeatOccupied_SingleEvent_Enable) /*10,1110 is Multi Event, 1,111 is */
	      {
		   SeatOccupied_SingleEvent_Enable = TRUE;
	      }
	      if(TRUE == SeatOccupied_SingleEvent_Enable)
	      {
		   SeatOccupied_SingleEvent_Enable = FALSE;
		   SeatOccupied_Status = FALSE;
		   MessageRx_SeatOccupied = FALSE;
	      }
         }
         else
         {
	      SeatOccupied_Real_Timer --;
         }
    } 
  
    /* SeatOccupied RiseEdge and FallEdge Active monitor */  
    if((FALSE == SeatOccupied_Status) && (TRUE == SeatOccupied_LastStatus))
    {
    	 SeatOccupied_RiseEdge_Active = TRUE;
    } 
    else
    {
    	 SeatOccupied_RiseEdge_Active = FALSE;
    }
 
    if((TRUE == SeatOccupied_Status) && (FALSE == SeatOccupied_LastStatus))
    {
	 SeatOccupied_FallEdge_Active = TRUE;

    }	 
    else
    {
	 SeatOccupied_FallEdge_Active = FALSE;
    }	
}
#endif



#ifdef _CONFIG_TargetPositionClose
/*********************************************************************************************
** Name:	  MessageDebounce_TargetPositionClose(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_TargetPositionClose(void)
{
    static uint16_t TargetPositionClose_Real_Timer;
    
  /* TargetPositionClose Status Active monitor */ 
    TargetPositionClose_LastStatus = TargetPositionClose_Status;
    
    if(TRUE == MessageRx_TargetPositionClose_Ind)
    {  
	MessageRx_TargetPositionClose_Ind = FALSE;
        
        #ifdef _CHERY_COM
        if(MessageRx_TargetPositionClose == TRUE) /* TRUE or Active, based on Message define*/
        #endif
        #ifdef _AUDI_COM
	if(MessageRx_TargetPositionClose <= MasterCmd_TargetPosClosing_100Pecent)
	{
	      TargetPositionClose_StopPosition = (uint16_t)((uint32_t)(MessageRx_TargetPositionClose * SystemLearned_Position) 
	                                                              / MasterCmd_TargetPosClosing_100Pecent);
	}
	else
	{
	      TargetPositionClose_StopPosition = 0;
	}
        if(MessageRx_TargetPositionClose <= MasterCmd_TargetPosClosing_100Pecent)/* TRUE or Active, based on Message define*/
        #endif 
        {
	     TargetPositionClose_DataStream |= 0x0001;
        }
	if((MASK01BIT & TargetPositionClose_DataStream) == MASK01BIT)
        {    
             TargetPositionClose_Status = TRUE;
        }
        else if((MASK01BIT & TargetPositionClose_DataStream) == 0)
        {
    	     TargetPositionClose_Status = FALSE;
        }
    
        TargetPositionClose_DataStream <<=1;
    	TargetPositionClose_Real_Status = TRUE;
	TargetPositionClose_Real_Timer = K_TargetPositionClose_Real_Timeout;  
    }
    /*Real-time Monitor*/
    if(TRUE == TargetPositionClose_Real_Status)
    {
         if(TargetPositionClose_Real_Timer == 0)
         {
	      TargetPositionClose_Real_Status = FALSE; 
	      if(TRUE == K_TargetPositionClose_SingleEvent_Enable) /*10,1110 is Multi Event, 1,111 is */
	      {
		   TargetPositionClose_SingleEvent_Enable = TRUE;
	      }
	      if(TRUE == TargetPositionClose_SingleEvent_Enable)
	      {
		   TargetPositionClose_SingleEvent_Enable = FALSE;
		   TargetPositionClose_Status = FALSE;
		   MessageRx_TargetPositionClose = FALSE;
	      }
         }
         else
         {
	      TargetPositionClose_Real_Timer --;
         }
    } 
  
    /* TargetPositionClose RiseEdge and FallEdge Active monitor */  
    if((FALSE == TargetPositionClose_Status) && (TRUE == TargetPositionClose_LastStatus))
    {
    	 TargetPositionClose_RiseEdge_Active = TRUE;
    } 
    else
    {
    	 TargetPositionClose_RiseEdge_Active = FALSE;
    }
 
    if((TRUE == TargetPositionClose_Status) && (FALSE == TargetPositionClose_LastStatus))
    {
	 TargetPositionClose_FallEdge_Active = TRUE;

    }	 
    else
    {
	 TargetPositionClose_FallEdge_Active = FALSE;
    }

}
#endif


#ifdef _CONFIG_SlidePosition
#ifdef _CONFIG_SlidePosition_SinglePosition
/*********************************************************************************************
** Name:	  MessageDebounce_SlidePosition(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_SlidePosition(void)
{
    static uint16_t SlidePosition_Real_Timer;
    
  /* SlidePosition Status Active monitor */ 
    SlidePosition_LastStatus = SlidePosition_Status;
    
    if(TRUE == MessageRx_SlidePosition_Ind)
    {  
	MessageRx_SlidePosition_Ind = FALSE;
        
        #ifdef _CHERY_COM
        if(MessageRx_SlidePosition == TRUE) /* TRUE or Active, based on Message define*/
        #endif
        #ifdef _SGMW_COM
        if(MessageRx_SlidePosition == TRUE)/* TRUE or Active, based on Message define*/
        #endif
        #ifdef _CTCS_COM
        if(MessageRx_SlidePosition == TRUE)/* TRUE or Active, based on Message define*/
        #endif
        #ifdef _DEARCC_COM
        if(MessageRx_SlidePosition == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _XIAOPENG_COM
        SlidePosition_StopPosition = (uint16_t)((uint32_t)(MessageRx_SlidePosition * SystemLearned_Position) / 100);	
	if(MessageRx_SlidePosition <= 100)
        #endif 
	#ifdef _MAXUS_COM
	if(MessageRx_SlidePosition <= 100)
	{	     	
	     SlidePosition_StopPosition = (uint16_t)((uint32_t)(MessageRx_SlidePosition * SystemLearned_Position) / 100);
	     
	     if(SlidePosition_StopPosition > Motor1_Position)
	     {
                   if((SlidePosition_StopPosition - Motor1_Position) < (SystemLearned_Position / 20))
		   {
			 if(((SystemLearned_Position / 20) + Motor1_Position) < SystemLearned_Position)
			 {
			      SlidePosition_StopPosition = (SystemLearned_Position / 20) + Motor1_Position;
			 }
			 else
			 {
			      SlidePosition_StopPosition = SystemLearned_Position;
			 }
		   }
	     }
	     else if(SlidePosition_StopPosition < Motor1_Position)
	     {
		   if(SlidePosition_StopPosition >= (SystemLearned_Position / 10))
		   {
                         if((Motor1_Position - SlidePosition_StopPosition) < (SystemLearned_Position / 20))
		         {
			       SlidePosition_StopPosition = Motor1_Position - (SystemLearned_Position / 20);
		         }
		   }
		   else
		   {
			 SlidePosition_StopPosition = 0;
		   }
	     }	     
	}	
        if(MessageRx_SlidePosition <= 100) /* TRUE or Active, based on Message define*/
	#endif
	#ifdef _DFMC_COM
        if(MessageRx_SlidePosition == TRUE) /* TRUE or Active, based on Message define*/
	#endif
	#ifdef _BAIC_COM
        if(MessageRx_SlidePosition == TRUE) /* TRUE or Active, based on Message define*/
	#endif
	#ifdef _DFLZM_COM
        if(MessageRx_SlidePosition == TRUE) /* TRUE or Active, based on Message define*/
	#endif
	#ifdef _NIU_COM
        if(MessageRx_SlidePosition == TRUE) /* TRUE or Active, based on Message define*/
	#endif
	#ifdef _FAW_COM
        if(MessageRx_SlidePosition == TRUE) /* TRUE or Active, based on Message define*/
	#endif
	#ifdef _CHANGAN_COM
        if(MessageRx_SlidePosition == TRUE) /* TRUE or Active, based on Message define*/
        #endif
        {
	     SlidePosition_DataStream |= 0x0001;
        }
	if((MASK01BIT & SlidePosition_DataStream) == MASK01BIT)
        {    
             SlidePosition_Status = TRUE;
        }
        else if((MASK01BIT & SlidePosition_DataStream) == 0)
        {
    	     SlidePosition_Status = FALSE;
        }
    
        SlidePosition_DataStream <<=1;
    	SlidePosition_Real_Status = TRUE;
	SlidePosition_Real_Timer = K_SlidePosition_Real_Timeout;  
    }
    /*Real-time Monitor*/
    if(TRUE == SlidePosition_Real_Status)
    {
         if(SlidePosition_Real_Timer == 0)
         {
	      SlidePosition_Real_Status = FALSE; 
	      if(TRUE == K_SlidePosition_SingleEvent_Enable) /*10,1110 is Multi Event, 1,111 is */
	      {
		   SlidePosition_SingleEvent_Enable = TRUE;
	      }
	      if(TRUE == SlidePosition_SingleEvent_Enable)
	      {
		   SlidePosition_SingleEvent_Enable = FALSE;
		   SlidePosition_Status = FALSE;
		   MessageRx_SlidePosition = FALSE;
	      }
         }
         else
         {
	      SlidePosition_Real_Timer --;
         }
    } 
  
    /* SlidePosition RiseEdge and FallEdge Active monitor */  
    if((FALSE == SlidePosition_Status) && (TRUE == SlidePosition_LastStatus))
    {
    	 SlidePosition_RiseEdge_Active = TRUE;
    } 
    else
    {
    	 SlidePosition_RiseEdge_Active = FALSE;
    }
 
    if((TRUE == SlidePosition_Status) && (FALSE == SlidePosition_LastStatus))
    {
	 SlidePosition_FallEdge_Active = TRUE;

    }	 
    else
    {
	 SlidePosition_FallEdge_Active = FALSE;
    }

}
#endif
#ifdef _CONFIG_SlidePosition_MultPosition
/*********************************************************************************************
** Name:	  MessageDebounce_SlidePosition(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_SlidePosition(void)
{
    static uint16_t SlidePosition_Timer = 0;
    static uint8_t SlidePosition_Timer_Status = 0;
    static uint16_t SlidePosition_Real_Timer;
    
  /* SlidePosition Status Active monitor */   
    SlidePosition_LastStatus = SlidePosition_Status;
    
    if(TRUE == MessageRx_SlidePosition_Ind)
    {  
	 MessageRx_SlidePosition_Ind = FALSE;

	 MessageRx_SlidePosition_LastValue = MessageRx_SlidePosition_Value;
         if(MessageRx_SlidePosition <= 100)
         {
              MessageRx_SlidePosition_Value = (uint16_t)((uint32_t)(MessageRx_SlidePosition * SystemLearned_Position) / 100);
         }
	 
	 if(MessageRx_SlidePosition_Counter >= 0xFFFF)
	 {
	      MessageRx_SlidePosition_Counter = 2;
	 }
	 else
	 {
	      MessageRx_SlidePosition_Counter ++;
	 }
	 
         if((MessageRx_SlidePosition_Value != MessageRx_SlidePosition_LastValue)
	    &&(MessageRx_SlidePosition_Counter >= 2))    
         {
	      SlidePosition_DataStream |= 0x0001;
         }	 
         if((MASK01BIT & SlidePosition_DataStream) == MASK01BIT)	 
         {    
              SlidePosition_Status = TRUE;
         }
         else if((MASK01BIT & SlidePosition_DataStream) == 0)
         {
    	      SlidePosition_Status = FALSE;
         }   
         SlidePosition_DataStream <<=1;
	 SlidePosition_Real_Status = TRUE;
	 SlidePosition_Real_Timer = K_SlidePosition_Real_Timeout;  
    }
    /*Real-time Monitor*/
    if(TRUE == SlidePosition_Real_Status)
    {
         if(SlidePosition_Real_Timer == 0)
         {
	      SlidePosition_Real_Status = FALSE; 
         }
         else
         {
	      SlidePosition_Real_Timer --;
         }
    } 
    
    /* SlidePosition RiseEdge and FallEdge Active monitor */     
    if((TRUE == SlidePosition_Status) && (FALSE == SlidePosition_LastStatus))
    {
         SlidePosition_StartPosition = MessageRx_SlidePosition_LastValue;
    } 
    
    if((FALSE == SlidePosition_Status) && (TRUE == SlidePosition_LastStatus))
    {
	 SlidePosition_Timer = 0;
	 SlidePosition_Timer_Status = TRUE;
    } 
   
    if(TRUE == SlidePosition_Timer_Status)
    {
	 SlidePosition_Timer ++;	 
	 if(SlidePosition_Timer >= K_SlidePosition_Confirm_Time)
	 {
	       SlidePosition_Timer = 0;
	       SlidePosition_Timer_Status = FALSE;
	       SlidePosition_StopPosition = MessageRx_SlidePosition_Value;
	       
	       if(SlidePosition_StartPosition > SlidePosition_StopPosition)
	       {
	            SlidePosition_DeltaPosition = SlidePosition_StartPosition - SlidePosition_StopPosition;
	       }
	       else
	       {
		    SlidePosition_DeltaPosition = SlidePosition_StopPosition - SlidePosition_StartPosition;
	       }
	       
	       if(SlidePosition_DeltaPosition >= K_SlidePosition_DeltaPosition_Min)
	       {
	             SlidePosition_FallEdge_Active = TRUE;
	       }	       
	 }
	 else
	 {
	       SlidePosition_FallEdge_Active = FALSE;
	 }
    }
    else
    {
	 SlidePosition_Timer = 0;	 
	 SlidePosition_FallEdge_Active = FALSE;
	 SlidePosition_DeltaPosition = 0;
    }	
}
#endif
#ifdef _CONFIG_SlidePosition_MultPosition_BackToDefaultValue
/*********************************************************************************************
** Name:	  MessageDebounce_SlidePosition(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_SlidePosition(void)
{
    static uint16_t SlidePosition_Timer = 0;
    static uint8_t SlidePosition_Timer_Status = 0;
    static uint16_t SlidePosition_Real_Timer;
    
  /* SlidePosition Status Active monitor */ 
    SlidePosition_LastStatus = SlidePosition_Status;
    
    if(TRUE == MessageRx_SlidePosition_Ind)
    {  
	MessageRx_SlidePosition_Ind = FALSE;
	
	if(MessageRx_SlidePosition_Counter >= 2)
	{
	      MessageRx_SlidePosition_Counter = 2;
	}
	else
	{
	      MessageRx_SlidePosition_Counter ++;
        }
        
        #ifdef _CHERY_COM
        if(MessageRx_SlidePosition == TRUE) /* TRUE or Active, based on Message define*/
        #endif
        #ifdef _SGMW_COM
        if(MessageRx_SlidePosition == TRUE)/* TRUE or Active, based on Message define*/
        #endif
        #ifdef _CTCS_COM
        if(MessageRx_SlidePosition == TRUE)/* TRUE or Active, based on Message define*/
        #endif
        #ifdef _DEARCC_COM
        if(MessageRx_SlidePosition == TRUE) /* TRUE or Active, based on Message define*/
        #endif
	#ifdef _XIAOPENG_COM
        SlidePosition_StopPosition = (uint16_t)((uint32_t)(MessageRx_SlidePosition * SystemLearned_Position) / 100);	
	if(MessageRx_SlidePosition <= 100)
        #endif 
	#ifdef _MAXUS_COM
	if(MessageRx_SlidePosition <= 100)
	{
	     SlidePosition_StopPosition = (uint16_t)((uint32_t)(MessageRx_SlidePosition * SystemLearned_Position) / 100);
	}	
        if((MessageRx_SlidePosition <= 100) && (MessageRx_SlidePosition_Counter >= 2))
	#endif
	#ifdef _BAIC_COM
        if(MessageRx_SlidePosition == TRUE) /* TRUE or Active, based on Message define*/
	#endif
	#ifdef _DFLZM_COM
        if(MessageRx_SlidePosition == TRUE) /* TRUE or Active, based on Message define*/
	#endif
	#ifdef _FAW_COM
        if(MessageRx_SlidePosition == TRUE) /* TRUE or Active, based on Message define*/
	#endif
	#ifdef _CHANGAN_COM
        if(MessageRx_SlidePosition == TRUE) /* TRUE or Active, based on Message define*/
        #endif
        {
	     SlidePosition_DataStream |= 0x0001;
        }
	if((MASK01BIT & SlidePosition_DataStream) == MASK01BIT)
        {    
             SlidePosition_Status = TRUE;
        }
        else if((MASK01BIT & SlidePosition_DataStream) == 0)
        {
    	     SlidePosition_Status = FALSE;
        }
    
        SlidePosition_DataStream <<=1;
    	SlidePosition_Real_Status = TRUE;
	SlidePosition_Real_Timer = K_SlidePosition_Real_Timeout;  
    }
    /*Real-time Monitor*/
    if(TRUE == SlidePosition_Real_Status)
    {
         if(SlidePosition_Real_Timer == 0)
         {
	      SlidePosition_Real_Status = FALSE; 
         }
         else
         {
	      SlidePosition_Real_Timer --;
         }
    } 
    
    /* SlidePosition RiseEdge and FallEdge Active monitor */     
    if((TRUE == SlidePosition_Status) && (FALSE == SlidePosition_LastStatus))
    {
         SlidePosition_StartPosition = Motor1_Position;
	 SlidePosition_Timer = 0;
	 SlidePosition_Timer_Status = FALSE;
    } 
    
    if((FALSE == SlidePosition_Status) && (TRUE == SlidePosition_LastStatus))
    {
	 SlidePosition_Timer = 0;
	 SlidePosition_Timer_Status = TRUE;
    } 
   
    if(TRUE == SlidePosition_Timer_Status)
    {
	 SlidePosition_Timer ++;	 
	 if(SlidePosition_Timer >= K_SlidePosition_Confirm_Time)
	 {
	       SlidePosition_Timer = 0;
	       SlidePosition_Timer_Status = FALSE;
	       
	       if(SlidePosition_StartPosition > SlidePosition_StopPosition)
	       {
	            SlidePosition_DeltaPosition = SlidePosition_StartPosition - SlidePosition_StopPosition;
	       }
	       else
	       {
		    SlidePosition_DeltaPosition = SlidePosition_StopPosition - SlidePosition_StartPosition;
	       }
	       
	       if(SlidePosition_DeltaPosition >= K_SlidePosition_DeltaPosition_Min)
	       {
	             SlidePosition_FallEdge_Active = TRUE;
	       }

	       SlidePosition_FallEdge_Active = TRUE;	       
	 }
	 else
	 {
	       SlidePosition_FallEdge_Active = FALSE;
	 }
    }
    else
    {
	 SlidePosition_Timer = 0;	 
	 SlidePosition_FallEdge_Active = FALSE;
	 SlidePosition_DeltaPosition = 0;
    }	
}
#endif
#endif
#ifdef _CHERY_COM
#ifdef _CHERY_COM_PLG
#ifdef _CONFIG_GarageHeightRequest
/*********************************************************************************************
** Name:	  MessageDebounce_GarageHeightRequest(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_GarageHeightRequest(void)
{
    static uint16_t GarageHeightRequest_DataStream = 0; 
    static uint8_t GarageHeightRequest_Timer_Status = 0;
    static uint16_t GarageHeightRequest_Real_Timer;
    
  /* GarageHeightRequest Status Active monitor */  
    GarageHeightRequest_LastStatus = GarageHeightRequest_Status;
    
    if(TRUE == MessageRx_GarageHeight_Ind)
    {  
	 MessageRx_GarageHeight_Ind = FALSE;
         	 
	 MessageRx_GarageHeight_LastValue = MessageRx_GarageHeight_Value;   	 
	 if((MessageRx_GarageHeight >= _DVD_Set_PLGPositionSts_50_Pecent) && (MessageRx_GarageHeight <= _DVD_Set_PLGPositionSts_100_Pecent))
	 {
              MessageRx_GarageHeight_Value = (uint16_t)((uint32_t)(MessageRx_GarageHeight * SystemLearned_Position) / 100);
	 	 
           if((MessageRx_GarageHeight_Value != MessageRx_GarageHeight_LastValue)
               &&((MessageRx_GarageHeight_Value >= K_GarageLearned_Position_Min)
	       &&(MessageRx_GarageHeight_Value <= K_GarageLearned_Position_Max)))
           {
	        GarageHeightRequest_DataStream |= 0x0001;
           }
	 }
	 else
	 {
	      MessageRx_GarageHeight_Value = 0;
	 }
         if((MASK01BIT & GarageHeightRequest_DataStream) == MASK01BIT)	 
         {    
              GarageHeightRequest_Status = TRUE;
         }
         else if((MASK01BIT & GarageHeightRequest_DataStream) == 0)
         {
    	      GarageHeightRequest_Status = FALSE;
         }   
         GarageHeightRequest_DataStream <<=1;
    	 GarageHeightRequest_Real_Status = TRUE;
	 GarageHeightRequest_Real_Timer = K_GarageHeightRequest_Real_Timeout;  
    }
    /*Real-time Monitor*/
    if(TRUE == GarageHeightRequest_Real_Status)
    {
         if(GarageHeightRequest_Real_Timer == 0)
         {
	      GarageHeightRequest_Real_Status = FALSE; 
	      if(TRUE == K_GarageHeightRequest_SingleEvent_Enable) /*10,1110 is MultiEvent, 1,111 is SingleEvent */
	      {
		   GarageHeightRequest_Status = FALSE;
		   MessageRx_GarageHeight_Value = 0;
		   
	      } 
         }
         else
         {
	      GarageHeightRequest_Real_Timer --;
         }
    }  
  
    /* GarageHeightRequest RiseEdge and FallEdge Active monitor */  
    if((FALSE == GarageHeightRequest_Status) && (TRUE == GarageHeightRequest_LastStatus))
    {
    	 GarageHeightRequest_RiseEdge_Active = TRUE;
    } 
    else
    {
    	 GarageHeightRequest_RiseEdge_Active = FALSE;
    }
 
    if((TRUE == GarageHeightRequest_Status) && (FALSE == GarageHeightRequest_LastStatus))
    {
	 GarageHeightRequest_FallEdge_Active = TRUE;

    }	 
    else
    {
	 GarageHeightRequest_FallEdge_Active = FALSE;
    }	
}
#endif
#endif
#ifdef _CHERY_COM_PD
#ifdef _CONFIG_GarageHeightRequest
/*********************************************************************************************
** Name:	  MessageDebounce_GarageHeightRequest(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_GarageHeightRequest(void)
{

}
#endif
#endif
#endif


#ifdef _VOYAH_COM
#ifdef _VOYAH_COM_PD
#ifdef _CONFIG_GarageHeightRequest
/*********************************************************************************************
** Name:	  MessageDebounce_GarageHeightRequest(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_GarageHeightRequest(void)
{
    static uint16_t GarageHeightRequest_DataStream = 0; 
    static uint16_t GarageHeightRequest_Real_Timer;
    
    #define MessageRx_GarageHeight_60_Percent 60
    #define MessageRx_GarageHeight_80_Percent 80
    #define MessageRx_GarageHeight_100_Percent 100
    
  /* GarageHeightRequest Status Active monitor */  
    GarageHeightRequest_LastStatus = GarageHeightRequest_Status;
    
    if(TRUE == MessageRx_GarageHeight_Ind)
    {  
	 MessageRx_GarageHeight_Ind = FALSE;
         	 
	 MessageRx_GarageHeight_LastValue = MessageRx_GarageHeight_Value;   	 
	 if(MessageRx_GarageHeight == _POD_DoorPositionStsSet_DOORPosSetS_60p)
	 {
              MessageRx_GarageHeight_Value = (uint16_t)((uint32_t)(MessageRx_GarageHeight_60_Percent * SystemLearned_Position) / 100);
	 }
	 else if(MessageRx_GarageHeight == _POD_DoorPositionStsSet_DOORPosSetS_80p)
	 {
              MessageRx_GarageHeight_Value = (uint16_t)((uint32_t)(MessageRx_GarageHeight_80_Percent * SystemLearned_Position) / 100);
	 }
	 else if(MessageRx_GarageHeight == _POD_DoorPositionStsSet_DOORPosSetS_100p)
	 {
              MessageRx_GarageHeight_Value = (uint16_t)((uint32_t)(MessageRx_GarageHeight_100_Percent * SystemLearned_Position) / 100);
	 }
	 else
	 {
	      MessageRx_GarageHeight_Value = 0;
	 }
	 
         if(((MessageRx_GarageHeight == _POD_DoorPositionStsSet_DOORPosSetS_60p) 
	    ||(MessageRx_GarageHeight == _POD_DoorPositionStsSet_DOORPosSetS_80p)
	    ||(MessageRx_GarageHeight == _POD_DoorPositionStsSet_DOORPosSetS_100p))
	   &&(MessageRx_GarageHeight_Value != 0))
	   //&&(MessageRx_GarageHeight_LastValue != MessageRx_GarageHeight_Value))
         {
	        GarageHeightRequest_DataStream |= 0x0001;
         }
	 
         if((MASK01BIT & GarageHeightRequest_DataStream) == MASK01BIT)	 
         {    
              GarageHeightRequest_Status = TRUE;
         }
         else if((MASK01BIT & GarageHeightRequest_DataStream) == 0)
         {
    	      GarageHeightRequest_Status = FALSE;
         }   
         GarageHeightRequest_DataStream <<=1;
    	 GarageHeightRequest_Real_Status = TRUE;
	 GarageHeightRequest_Real_Timer = K_GarageHeightRequest_Real_Timeout;  
    }
    /*Real-time Monitor*/
    if(TRUE == GarageHeightRequest_Real_Status)
    {
         if(GarageHeightRequest_Real_Timer == 0)
         {
	      GarageHeightRequest_Real_Status = FALSE; 
	      if(TRUE == K_GarageHeightRequest_SingleEvent_Enable) /*10,1110 is MultiEvent, 1,111 is SingleEvent */
	      {
		   GarageHeightRequest_Status = FALSE;
		   MessageRx_GarageHeight_Value = 0;   
	      } 
         }
         else
         {
	      GarageHeightRequest_Real_Timer --;
         }
    }  
  
    /* GarageHeightRequest RiseEdge and FallEdge Active monitor */  
    if((FALSE == GarageHeightRequest_Status) && (TRUE == GarageHeightRequest_LastStatus))
    {
    	 GarageHeightRequest_RiseEdge_Active = TRUE;
    } 
    else
    {
    	 GarageHeightRequest_RiseEdge_Active = FALSE;
    }
 
    if((TRUE == GarageHeightRequest_Status) && (FALSE == GarageHeightRequest_LastStatus))
    {
	 GarageHeightRequest_FallEdge_Active = TRUE;

    }	 
    else
    {
	 GarageHeightRequest_FallEdge_Active = FALSE;
    }	
}
#endif
#endif
#endif


#ifdef _AUDI_COM
#ifdef _AUDI_COM_PD
#ifdef _CONFIG_GarageHeightRequest
/*********************************************************************************************
** Name:	  MessageDebounce_GarageHeightRequest(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_GarageHeightRequest(void)
{
    static uint16_t GarageHeightRequest_DataStream = 0; 
    static uint16_t GarageHeightRequest_Real_Timer;
    
    #define MessageRx_GarageHeight_50_Percent 50
    #define MessageRx_GarageHeight_75_Percent 75
    #define MessageRx_GarageHeight_100_Percent 100
    
  /* GarageHeightRequest Status Active monitor */  
    GarageHeightRequest_LastStatus = GarageHeightRequest_Status;
    
    if(TRUE == MessageRx_GarageHeight_Ind)
    {  
	 MessageRx_GarageHeight_Ind = FALSE;
         	 
	 MessageRx_GarageHeight_LastValue = MessageRx_GarageHeight_Value;   	 
	 /*if(MessageRx_GarageHeight == _ICC_SetOpenAngle_50_Percent)
	 {
              MessageRx_GarageHeight_Value = (uint16_t)((uint32_t)(MessageRx_GarageHeight_50_Percent * SystemLearned_Position) / 100);
	 }
	 else if(MessageRx_GarageHeight == _ICC_SetOpenAngle_75_Percent)
	 {
              MessageRx_GarageHeight_Value = (uint16_t)((uint32_t)(MessageRx_GarageHeight_75_Percent * SystemLearned_Position) / 100);
	 }
	 else if(MessageRx_GarageHeight == _ICC_SetOpenAngle_100_Percent)
	 {
              MessageRx_GarageHeight_Value = (uint16_t)((uint32_t)(MessageRx_GarageHeight_100_Percent * SystemLearned_Position) / 100);
	 }
	 else
	 {
	      MessageRx_GarageHeight_Value = 0;
	 }
	 
         if(((MessageRx_GarageHeight == _ICC_SetOpenAngle_50_Percent) 
	    ||(MessageRx_GarageHeight == _ICC_SetOpenAngle_75_Percent)
	    ||(MessageRx_GarageHeight == _ICC_SetOpenAngle_100_Percent))
	   &&(MessageRx_GarageHeight_Value != 0))
	   //&&(MessageRx_GarageHeight_LastValue != MessageRx_GarageHeight_Value))
         {
	        GarageHeightRequest_DataStream |= 0x0001;
         }*/
	 
         if((MASK01BIT & GarageHeightRequest_DataStream) == MASK01BIT)	 
         {    
              GarageHeightRequest_Status = TRUE;
         }
         else if((MASK01BIT & GarageHeightRequest_DataStream) == 0)
         {
    	      GarageHeightRequest_Status = FALSE;
         }   
         GarageHeightRequest_DataStream <<=1;
    	 GarageHeightRequest_Real_Status = TRUE;
	 GarageHeightRequest_Real_Timer = K_GarageHeightRequest_Real_Timeout;  
    }
    /*Real-time Monitor*/
    if(TRUE == GarageHeightRequest_Real_Status)
    {
         if(GarageHeightRequest_Real_Timer == 0)
         {
	      GarageHeightRequest_Real_Status = FALSE; 
	      if(TRUE == K_GarageHeightRequest_SingleEvent_Enable) /*10,1110 is MultiEvent, 1,111 is SingleEvent */
	      {
		   GarageHeightRequest_Status = FALSE;
		   MessageRx_GarageHeight_Value = 0;   
	      } 
         }
         else
         {
	      GarageHeightRequest_Real_Timer --;
         }
    }  
  
    /* GarageHeightRequest RiseEdge and FallEdge Active monitor */  
    if((FALSE == GarageHeightRequest_Status) && (TRUE == GarageHeightRequest_LastStatus))
    {
    	 GarageHeightRequest_RiseEdge_Active = TRUE;
    } 
    else
    {
    	 GarageHeightRequest_RiseEdge_Active = FALSE;
    }
 
    if((TRUE == GarageHeightRequest_Status) && (FALSE == GarageHeightRequest_LastStatus))
    {
	 GarageHeightRequest_FallEdge_Active = TRUE;

    }	 
    else
    {
	 GarageHeightRequest_FallEdge_Active = FALSE;
    }	
}
#endif
#endif
#endif

#ifdef _CTCS_COM
#ifdef _CONFIG_GarageHeightRequest
/*********************************************************************************************
** Name:	  MessageDebounce_GarageHeightRequest(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_GarageHeightRequest(void)
{
    static uint16_t GarageHeightRequest_Timer = 0;
    static uint8_t GarageHeightRequest_Timer_Status = 0;
    static uint16_t GarageHeightRequest_Real_Timer;
    
  /* GarageHeightRequest Status Active monitor */   
    GarageHeightRequest_LastStatus = GarageHeightRequest_Status;
    
    if(TRUE == MessageRx_GarageHeight_Ind)
    {  
	 MessageRx_GarageHeight_Ind = FALSE;
	 
	 MessageRx_GarageHeight_LastValue = MessageRx_GarageHeight_Value;
         MessageRx_GarageHeight_Value = (uint16_t)((uint32_t)(MessageRx_GarageHeight * SystemLearned_Position) / 254); 
	 
         #ifdef _CONFIG_CAN_Bus
         if((MessageRx_GarageHeight_Value >= K_GarageLearned_Position_Min)
	    &&(MessageRx_GarageHeight_Value <= K_GarageLearned_Position_Max)
	    &&(MessageRx_GarageHeight >= _GARAGE_HEIGHT_70_DEGREE )
	    &&(MessageRx_GarageHeight <= _GARAGE_HEIGHT_100_DEGREE)
	    &&(MessageRx_RestoreRequest == _SET_IGNORE))
	 #endif  
	 #ifdef _CONFIG_LIN_Slave
	 if(MessageRx_GarageHeight_Counter >= 0xFFFF)
	 {
	      MessageRx_GarageHeight_Counter = 2;
	 }
	 else
	 {
	      MessageRx_GarageHeight_Counter ++;
	 }
	 
         if((MessageRx_GarageHeight_Value != MessageRx_GarageHeight_LastValue)
            &&((MessageRx_GarageHeight_Value >= K_GarageLearned_Position_Min) 
	    &&(MessageRx_GarageHeight_Value <= K_GarageLearned_Position_Max))
	    &&(MessageRx_GarageHeight >= _GARAGE_HEIGHT_70_DEGREE )
	    &&(MessageRx_GarageHeight <= _GARAGE_HEIGHT_100_DEGREE)
	    &&(MessageRx_GarageHeight_Counter >= 2))
	  #endif
         {
	      GarageHeightRequest_DataStream |= 0x0001;
         }
         if((MASK01BIT & GarageHeightRequest_DataStream) == MASK01BIT)	 
         {    
              GarageHeightRequest_Status = TRUE;
         }
         else if((MASK01BIT & GarageHeightRequest_DataStream) == 0)
         {
    	      GarageHeightRequest_Status = FALSE;
         }   
         GarageHeightRequest_DataStream <<=1;
    	 GarageHeightRequest_Real_Status = TRUE;
	 GarageHeightRequest_Real_Timer = K_GarageHeightRequest_Real_Timeout;  
    }
    /*Real-time Monitor*/
    if(TRUE == GarageHeightRequest_Real_Status)
    {
         if(GarageHeightRequest_Real_Timer == 0)
         {
	      GarageHeightRequest_Real_Status = FALSE; 
	      if(TRUE == K_GarageHeightRequest_SingleEvent_Enable) /*10,1110 is MultiEvent, 1,111 is SingleEvent */
	      {
		   GarageHeightRequest_Status = FALSE;
	      } 
         }
         else
         {
	      GarageHeightRequest_Real_Timer --;
         }
    }  
  
    /* GarageHeightRequest RiseEdge and FallEdge Active monitor */  
    if((FALSE == GarageHeightRequest_Status) && (TRUE == GarageHeightRequest_LastStatus))
    {
    	 GarageHeightRequest_RiseEdge_Active = TRUE;
    } 
    else
    {
    	 GarageHeightRequest_RiseEdge_Active = FALSE;
    }
 
    if((TRUE == GarageHeightRequest_Status) && (FALSE == GarageHeightRequest_LastStatus))
    {
	 GarageHeightRequest_FallEdge_Active = TRUE;

    }	 
    else
    {
	 GarageHeightRequest_FallEdge_Active = FALSE;
    }	
}
#endif
#endif

#ifdef _DEARCC_COM 
#ifdef _CONFIG_GarageHeightRequest
/*********************************************************************************************
** Name:	  MessageDebounce_GarageHeightRequest(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_GarageHeightRequest(void)
{
    static uint16_t GarageHeightRequest_Timer = 0;
    static uint8_t GarageHeightRequest_Timer_Status = 0;
    static uint16_t GarageHeightRequest_Real_Timer;
    
  /* GarageHeightRequest Status Active monitor */  
    GarageHeightRequest_LastStatus = GarageHeightRequest_Status;
    
    if(TRUE == MessageRx_GarageHeight_Ind)
    {  
	 MessageRx_GarageHeight_Ind = FALSE;
         	 
	 MessageRx_GarageHeight_LastValue = MessageRx_GarageHeight_Value;    
         //if(MessageRx_GarageHeight <= 35)
         //{
              MessageRx_GarageHeight_Value = (uint16_t)((uint32_t)((30 + (MessageRx_GarageHeight * 2)) * SystemLearned_Position) / 100);
         //}
	 
	 if(MessageRx_GarageHeight_Counter >= 0xFFFF)
	 {
	      MessageRx_GarageHeight_Counter = 2;
	 }
	 else
	 {
	      MessageRx_GarageHeight_Counter ++;
	 }
	 
         if((MessageRx_GarageHeight_Value != MessageRx_GarageHeight_LastValue)
            &&((MessageRx_GarageHeight_Value >= K_GarageLearned_Position_Min) 
	    &&(MessageRx_GarageHeight_Value <= K_GarageLearned_Position_Max))
	    &&(MessageRx_GarageHeight_Counter >= 2)
	    &&(MessageRx_GarageHeight <= 35))
         {
	      GarageHeightRequest_DataStream |= 0x0001;
         }
         if((MASK01BIT & GarageHeightRequest_DataStream) == MASK01BIT)	 
         {    
              GarageHeightRequest_Status = TRUE;
         }
         else if((MASK01BIT & GarageHeightRequest_DataStream) == 0)
         {
    	      GarageHeightRequest_Status = FALSE;
         }    
         GarageHeightRequest_DataStream <<=1;
	 GarageHeightRequest_Real_Status = TRUE;
	 GarageHeightRequest_Real_Timer = K_GarageHeightRequest_Real_Timeout;  
    }
    /*Real-time Monitor*/
    if(TRUE == GarageHeightRequest_Real_Status)
    {
         if(GarageHeightRequest_Real_Timer == 0)
         {
	      GarageHeightRequest_Real_Status = FALSE; 
	      if(TRUE == K_GarageHeightRequest_SingleEvent_Enable) /*10,1110 is MultiEvent, 1,111 is SingleEvent */
	      {
		   GarageHeightRequest_Status = FALSE;
	      }
         }
         else
         {
	      GarageHeightRequest_Real_Timer --;
         }
    } 
  
    /* GarageHeightRequest RiseEdge and FallEdge Active monitor */  
    if((FALSE == GarageHeightRequest_Status) && (TRUE == GarageHeightRequest_LastStatus))
    {
     	 GarageHeightRequest_RiseEdge_Active = TRUE;
	 GarageHeightRequest_Timer = 0;
	 GarageHeightRequest_Timer_Status = TRUE;
	 GarageHeightRequest_Process_Status = TRUE;  
    } 

    
    if(TRUE == GarageHeightRequest_Timer_Status)
    {
	 GarageHeightRequest_Timer ++;
	 
	 if(GarageHeightRequest_Timer >= K_GarageHeightRequest_Confirm_Time)
	 {
	       GarageHeightRequest_FallEdge_Active = TRUE;
	       
	       GarageHeightRequest_Timer = 0;
	       GarageHeightRequest_Timer_Status = FALSE;
	 }
	 else
	 {
	       GarageHeightRequest_FallEdge_Active = FALSE;
	 }
    }
    else
    {
	 GarageHeightRequest_Timer = 0;	 
	 GarageHeightRequest_FallEdge_Active = FALSE;
    }	
}
#endif
#endif

#ifdef _XIAOPENG_COM 
#ifdef _CONFIG_GarageHeightRequest
/*********************************************************************************************
** Name:	  MessageDebounce_GarageHeightRequest(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_GarageHeightRequest(void)
{
        static uint16_t GarageHeightRequest_DataStream = 0; 
    static uint8_t GarageHeightRequest_Timer_Status = 0;
    static uint16_t GarageHeightRequest_Real_Timer;
    
  /* GarageHeightRequest Status Active monitor */  
    GarageHeightRequest_LastStatus = GarageHeightRequest_Status;
    
    if(TRUE == MessageRx_GarageHeight_Ind)
    {  
	 MessageRx_GarageHeight_Ind = FALSE;
         	 
	 MessageRx_GarageHeight_LastValue = MessageRx_GarageHeight_Value;           
         MessageRx_GarageHeight_Value = (uint16_t)((uint32_t)(MessageRx_GarageHeight * SystemLearned_Position) / 100);
	 
         if((MessageRx_GarageHeight_Value != MessageRx_GarageHeight_LastValue)
             &&((MessageRx_GarageHeight_Value >= K_GarageLearned_Position_Min)
	     &&(MessageRx_GarageHeight_Value <= K_GarageLearned_Position_Max))
	     &&(MessageRx_GarageHeight >= _GARAGE_HEIGHT_0_DEGREE)
	     &&(MessageRx_GarageHeight <= _GARAGE_HEIGHT_100_DEGREE))
         {
	      GarageHeightRequest_DataStream |= 0x0001;
         }
         if((MASK01BIT & GarageHeightRequest_DataStream) == MASK01BIT)	 
         {    
              GarageHeightRequest_Status = TRUE;
         }
         else if((MASK01BIT & GarageHeightRequest_DataStream) == 0)
         {
    	      GarageHeightRequest_Status = FALSE;
         }   
         GarageHeightRequest_DataStream <<=1;
    	 GarageHeightRequest_Real_Status = TRUE;
	 GarageHeightRequest_Real_Timer = K_GarageHeightRequest_Real_Timeout;  
    }
    /*Real-time Monitor*/
    if(TRUE == GarageHeightRequest_Real_Status)
    {
         if(GarageHeightRequest_Real_Timer == 0)
         {
	      GarageHeightRequest_Real_Status = FALSE;  
	      if(TRUE == K_GarageHeightRequest_SingleEvent_Enable) /*10,1110 is Multi Event, 1,111 is */
	      {
		   GarageHeightRequest_SingleEvent_Enable = TRUE;
	      }
	      if(TRUE == GarageHeightRequest_SingleEvent_Enable)
	      {
		   GarageHeightRequest_SingleEvent_Enable = FALSE;
		   GarageHeightRequest_Status = FALSE;
		   MessageRx_GarageHeight_Value = 0;
		   MessageRx_GarageHeight = FALSE;
	      }
         }
         else
         {
	      GarageHeightRequest_Real_Timer --;
         }
    }  
  
    /* GarageHeightRequest RiseEdge and FallEdge Active monitor */  
    if((FALSE == GarageHeightRequest_Status) && (TRUE == GarageHeightRequest_LastStatus))
    {
    	 GarageHeightRequest_RiseEdge_Active = TRUE;
    } 
    else
    {
    	 GarageHeightRequest_RiseEdge_Active = FALSE;
    }
 
    if((TRUE == GarageHeightRequest_Status) && (FALSE == GarageHeightRequest_LastStatus))
    {
	 GarageHeightRequest_FallEdge_Active = TRUE;

    }	 
    else
    {
	 GarageHeightRequest_FallEdge_Active = FALSE;
    }
}
#endif
#endif

#ifdef _SGMW_COM 
#ifdef _CONFIG_GarageHeightRequest
/*********************************************************************************************
** Name:	  MessageDebounce_GarageHeightRequest(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_GarageHeightRequest(void)
{	
    static uint16_t GarageHeightRequest_Timer = 0;
    static uint8_t GarageHeightRequest_Timer_Status = 0;
    static uint16_t GarageHeightRequest_Real_Timer;
    
  /* GarageHeightRequest Status Active monitor */  
    GarageHeightRequest_LastStatus = GarageHeightRequest_Status;
    
    if(TRUE == MessageRx_GarageHeight_Ind)
    {  
	 MessageRx_GarageHeight_Ind = FALSE;
         	 
	 MessageRx_GarageHeight_LastValue = MessageRx_GarageHeight_Value;    
         if(MessageRx_GarageHeight <= 70)
         {
              MessageRx_GarageHeight_Value = (uint16_t)((uint32_t)((30 + MessageRx_GarageHeight) * SystemLearned_Position) / 100);
         }
	 else
	 {
	       MessageRx_GarageHeight_Value = 0;
	 }
         if((MessageRx_GarageHeight_Value != MessageRx_GarageHeight_LastValue)
            &&((MessageRx_GarageHeight_Value >= K_GarageLearned_Position_Min) 
	    &&(MessageRx_GarageHeight_Value <= K_GarageLearned_Position_Max)))
         {
	      GarageHeightRequest_DataStream |= 0x0001;
         }
         if((MASK01BIT & GarageHeightRequest_DataStream) == MASK01BIT)	 
         {    
              GarageHeightRequest_Status = TRUE;
         }
         else if((MASK01BIT & GarageHeightRequest_DataStream) == 0)
         {
    	      GarageHeightRequest_Status = FALSE;
         }    
         GarageHeightRequest_DataStream <<=1;
	 GarageHeightRequest_Real_Status = TRUE;
	 GarageHeightRequest_Real_Timer = K_GarageHeightRequest_Real_Timeout;  
    }
    /*Real-time Monitor*/
    if(TRUE == GarageHeightRequest_Real_Status)
    {
         if(GarageHeightRequest_Real_Timer == 0)
         {
	      GarageHeightRequest_Real_Status = FALSE; 
	      if(TRUE == K_GarageHeightRequest_SingleEvent_Enable) /*10,1110 is MultiEvent, 1,111 is SingleEvent */
	      {
		   GarageHeightRequest_Status = FALSE;
	      }
         }
         else
         {
	      GarageHeightRequest_Real_Timer --;
         }
    } 
    
      /* GarageHeightRequest RiseEdge and FallEdge Active monitor */  
    if((FALSE == GarageHeightRequest_Status) && (TRUE == GarageHeightRequest_LastStatus))
    {
    	 GarageHeightRequest_RiseEdge_Active = TRUE;
    } 
    else
    {
    	 GarageHeightRequest_RiseEdge_Active = FALSE;
    }
 
    if((TRUE == GarageHeightRequest_Status) && (FALSE == GarageHeightRequest_LastStatus))
    {
	 GarageHeightRequest_FallEdge_Active = TRUE;

    }	 
    else
    {
	 GarageHeightRequest_FallEdge_Active = FALSE;
    }
}
#endif
#endif
#ifdef _MAXUS_COM 
#ifdef _CONFIG_GarageHeightRequest
/*********************************************************************************************
** Name:	  MessageDebounce_GarageHeightRequest(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_GarageHeightRequest(void)
{	
    static uint16_t GarageHeightRequest_DataStream = 0; 
    static uint8_t GarageHeightRequest_Timer_Status = 0;
    static uint16_t GarageHeightRequest_Real_Timer;
    
  /* GarageHeightRequest Status Active monitor */  
    GarageHeightRequest_LastStatus = GarageHeightRequest_Status;
    
    if(TRUE == MessageRx_GarageHeight_Ind)
    {  
	 MessageRx_GarageHeight_Ind = FALSE;
	 
	 if(MessageRx_GarageHeight_Counter >= 3)
	 {
	      MessageRx_GarageHeight_Counter = 3;
	 }
	 else
	 {
	      MessageRx_GarageHeight_Counter ++;
	 }
         	 
	 MessageRx_GarageHeight_LastValue = MessageRx_GarageHeight_Value;           
	     
	 if(MessageRx_GarageHeight <= 100)
	 {
               MessageRx_GarageHeight_Value = (uint16_t)((uint32_t)(MessageRx_GarageHeight * SystemLearned_Position) / 100);
	 }
	 
         if(//(MessageRx_GarageHeight_Value != MessageRx_GarageHeight_LastValue)
             ((MessageRx_GarageHeight_Value >= K_GarageLearned_Position_Min)
	       &&(MessageRx_GarageHeight_Value <= K_GarageLearned_Position_Max))
	     &&(MessageRx_GarageHeight_Counter >= 3)
	     &&(MessageRx_GarageHeight <= 100))    
         {
	      GarageHeightRequest_DataStream |= 0x0001;
         }
         if((MASK01BIT & GarageHeightRequest_DataStream) == MASK01BIT)	 
         {    
              GarageHeightRequest_Status = TRUE;
         }
         else if((MASK01BIT & GarageHeightRequest_DataStream) == 0)
         {
    	      GarageHeightRequest_Status = FALSE;
         }   
         GarageHeightRequest_DataStream <<=1;
    	 GarageHeightRequest_Real_Status = TRUE;
	 GarageHeightRequest_Real_Timer = K_GarageHeightRequest_Real_Timeout;  
    }
    /*Real-time Monitor*/
    if(TRUE == GarageHeightRequest_Real_Status)
    {
         if(GarageHeightRequest_Real_Timer == 0)
         {
	      GarageHeightRequest_Real_Status = FALSE; 
	      if(TRUE == K_GarageHeightRequest_SingleEvent_Enable) /*10,1110 is MultiEvent, 1,111 is SingleEvent */
	      {
		   GarageHeightRequest_Status = FALSE;
	      } 
         }
         else
         {
	      GarageHeightRequest_Real_Timer --;
         }
    }  
  
    /* GarageHeightRequest RiseEdge and FallEdge Active monitor */  
    if((FALSE == GarageHeightRequest_Status) && (TRUE == GarageHeightRequest_LastStatus))
    {
    	 GarageHeightRequest_RiseEdge_Active = TRUE;
    } 
    else
    {
    	 GarageHeightRequest_RiseEdge_Active = FALSE;
    }
 
    if((TRUE == GarageHeightRequest_Status) && (FALSE == GarageHeightRequest_LastStatus))
    {
	 GarageHeightRequest_FallEdge_Active = TRUE;

    }	 
    else
    {
	 GarageHeightRequest_FallEdge_Active = FALSE;
    }
}
#endif
#endif
#ifdef _DFMC_COM 
#ifdef _CONFIG_GarageHeightRequest
/*********************************************************************************************
** Name:	  MessageDebounce_GarageHeightRequest(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_GarageHeightRequest(void)
{	
    static uint16_t GarageHeightRequest_DataStream = 0; 
    static uint8_t GarageHeightRequest_Timer_Status = 0;
    static uint16_t GarageHeightRequest_Real_Timer;
    
  /* GarageHeightRequest Status Active monitor */  
    GarageHeightRequest_LastStatus = GarageHeightRequest_Status;
    
    if(TRUE == MessageRx_GarageHeight_Ind)
    {  
	 MessageRx_GarageHeight_Ind = FALSE;
         	 
	 MessageRx_GarageHeight_LastValue = MessageRx_GarageHeight_Value;   	 
	 if((MessageRx_GarageHeight >= _ivi_potPositionStsSet_40_percent) && (MessageRx_GarageHeight <= _ivi_potPositionStsSet_100_percent))
	 {
              MessageRx_GarageHeight_Value = (uint16_t)((uint32_t)((MessageRx_GarageHeight + 3) * SystemLearned_Position) / 10);
	 }
	 else
	 {
	      MessageRx_GarageHeight_Value = 0;
	 }
	 
         if((MessageRx_GarageHeight_Value != MessageRx_GarageHeight_LastValue)
             &&((MessageRx_GarageHeight_Value >= K_GarageLearned_Position_Min)
	       &&(MessageRx_GarageHeight_Value <= K_GarageLearned_Position_Max)))
         {
	      GarageHeightRequest_DataStream |= 0x0001;
         }
         if((MASK01BIT & GarageHeightRequest_DataStream) == MASK01BIT)	 
         {    
              GarageHeightRequest_Status = TRUE;
         }
         else if((MASK01BIT & GarageHeightRequest_DataStream) == 0)
         {
    	      GarageHeightRequest_Status = FALSE;
         }   
         GarageHeightRequest_DataStream <<=1;
    	 GarageHeightRequest_Real_Status = TRUE;
	 GarageHeightRequest_Real_Timer = K_GarageHeightRequest_Real_Timeout;  
    }
    /*Real-time Monitor*/
    if(TRUE == GarageHeightRequest_Real_Status)
    {
         if(GarageHeightRequest_Real_Timer == 0)
         {
	      GarageHeightRequest_Real_Status = FALSE; 
	      if(TRUE == K_GarageHeightRequest_SingleEvent_Enable) /*10,1110 is MultiEvent, 1,111 is SingleEvent */
	      {
		   GarageHeightRequest_Status = FALSE;
		   MessageRx_GarageHeight_Value = 0;
	      } 
         }
         else
         {
	      GarageHeightRequest_Real_Timer --;
         }
    }  
  
    /* GarageHeightRequest RiseEdge and FallEdge Active monitor */  
    if((FALSE == GarageHeightRequest_Status) && (TRUE == GarageHeightRequest_LastStatus))
    {
    	 GarageHeightRequest_RiseEdge_Active = TRUE;
    } 
    else
    {
    	 GarageHeightRequest_RiseEdge_Active = FALSE;
    }
 
    if((TRUE == GarageHeightRequest_Status) && (FALSE == GarageHeightRequest_LastStatus))
    {
	 GarageHeightRequest_FallEdge_Active = TRUE;

    }	 
    else
    {
	 GarageHeightRequest_FallEdge_Active = FALSE;
    }
}
#endif
#endif

#ifdef _DFLZM_COM 
#ifdef _CONFIG_GarageHeightRequest
/*********************************************************************************************
** Name:	  MessageDebounce_GarageHeightRequest(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_GarageHeightRequest(void)
{	
    static uint16_t GarageHeightRequest_DataStream = 0; 
    static uint16_t GarageHeightRequest_Real_Timer;
    
  /* GarageHeightRequest Status Active monitor */  
    GarageHeightRequest_LastStatus = GarageHeightRequest_Status;
    
    if(TRUE == MessageRx_GarageHeight_Ind)
    {  
	 MessageRx_GarageHeight_Ind = FALSE;
	 
	 if(MessageRx_GarageHeight == _ICE1_Set_PLGOpen_Lvl_Level_1)
	 {
	      MessageRx_GarageHeight_Value = (uint16_t)((uint32_t)(30 * SystemLearned_Position) / 100);
	 }
	 else if(MessageRx_GarageHeight == _ICE1_Set_PLGOpen_Lvl_Level_2)
	 {
	      MessageRx_GarageHeight_Value = (uint16_t)((uint32_t)(46 * SystemLearned_Position) / 100);
	 } 
	 else if(MessageRx_GarageHeight == _ICE1_Set_PLGOpen_Lvl_Level_3)
	 {
	      MessageRx_GarageHeight_Value = (uint16_t)((uint32_t)(62 * SystemLearned_Position) / 100);
	 }
	 else if(MessageRx_GarageHeight == _ICE1_Set_PLGOpen_Lvl_Level_4)
	 {
	      MessageRx_GarageHeight_Value = (uint16_t)((uint32_t)(78 * SystemLearned_Position) / 100);
	 }
	 else if(MessageRx_GarageHeight == _ICE1_Set_PLGOpen_Lvl_Level_5)
	 {
	      MessageRx_GarageHeight_Value = (uint16_t)((uint32_t)(95 * SystemLearned_Position) / 100);
	 }	 
	 
         if((MessageRx_GarageHeight == _ICE1_Set_PLGOpen_Lvl_Level_1) 
	    || (MessageRx_GarageHeight == _ICE1_Set_PLGOpen_Lvl_Level_2)
	    || (MessageRx_GarageHeight == _ICE1_Set_PLGOpen_Lvl_Level_3)
	    || (MessageRx_GarageHeight == _ICE1_Set_PLGOpen_Lvl_Level_4)
	    || (MessageRx_GarageHeight == _ICE1_Set_PLGOpen_Lvl_Level_5))
         {
	      GarageHeightRequest_DataStream |= 0x0001;
         }
         if((MASK01BIT & GarageHeightRequest_DataStream) == MASK01BIT)	 
         {    
              GarageHeightRequest_Status = TRUE;
         }
         else if((MASK01BIT & GarageHeightRequest_DataStream) == 0)
         {
    	      GarageHeightRequest_Status = FALSE;
         }   
         GarageHeightRequest_DataStream <<=1;
    	 GarageHeightRequest_Real_Status = TRUE;
	 GarageHeightRequest_Real_Timer = K_GarageHeightRequest_Real_Timeout;  
    }
    /*Real-time Monitor*/
    if(TRUE == GarageHeightRequest_Real_Status)
    {
         if(GarageHeightRequest_Real_Timer == 0)
         {
	      GarageHeightRequest_Real_Status = FALSE; 
	      if(TRUE == K_GarageHeightRequest_SingleEvent_Enable) /*10,1110 is MultiEvent, 1,111 is SingleEvent */
	      {
		   GarageHeightRequest_Status = FALSE;
	      } 
         }
         else
         {
	      GarageHeightRequest_Real_Timer --;
         }
    }  
  
    /* GarageHeightRequest RiseEdge and FallEdge Active monitor */  
    if((FALSE == GarageHeightRequest_Status) && (TRUE == GarageHeightRequest_LastStatus))
    {
    	 GarageHeightRequest_RiseEdge_Active = TRUE;
    } 
    else
    {
    	 GarageHeightRequest_RiseEdge_Active = FALSE;
    }
 
    if((TRUE == GarageHeightRequest_Status) && (FALSE == GarageHeightRequest_LastStatus))
    {
	 GarageHeightRequest_FallEdge_Active = TRUE;

    }	 
    else
    {
	 GarageHeightRequest_FallEdge_Active = FALSE;
    }
}
#endif
#endif


#ifdef _BAIC_COM 
#ifdef _CONFIG_GarageHeightRequest
/*********************************************************************************************
** Name:	  MessageDebounce_GarageHeightRequest(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_GarageHeightRequest(void)
{	
    static uint16_t GarageHeightRequest_DataStream = 0; 
    static uint8_t GarageHeightRequest_Timer_Status = 0;
    static uint16_t GarageHeightRequest_Real_Timer;
    
  /* GarageHeightRequest Status Active monitor */  
    GarageHeightRequest_LastStatus = GarageHeightRequest_Status;
    
    if(TRUE == MessageRx_GarageHeight_Ind)
    {  
	 MessageRx_GarageHeight_Ind = FALSE;
	 
	 if(MessageRx_GarageHeight_Counter >= 3)
	 {
	      MessageRx_GarageHeight_Counter = 3;
	 }
	 else
	 {
	      MessageRx_GarageHeight_Counter ++;
	 }
         	 
	 MessageRx_GarageHeight_LastValue = MessageRx_GarageHeight_Value; 
	 
	 if((MessageRx_GarageHeight >= 51) && (MessageRx_GarageHeight <= 101))
	 {
              MessageRx_GarageHeight_Value = (uint16_t)((uint32_t)((MessageRx_GarageHeight-1) * SystemLearned_Position) / 100);
	 }
	 
         if(((MessageRx_GarageHeight >= 51) && (MessageRx_GarageHeight <= 101))
	     &&(MessageRx_GarageHeight_Counter >= 3))
         {
	      GarageHeightRequest_DataStream |= 0x0001;
         }
         if((MASK01BIT & GarageHeightRequest_DataStream) == MASK01BIT)	 
         {    
              GarageHeightRequest_Status = TRUE;
         }
         else if((MASK01BIT & GarageHeightRequest_DataStream) == 0)
         {
    	      GarageHeightRequest_Status = FALSE;
         }   
         GarageHeightRequest_DataStream <<=1;
    	 GarageHeightRequest_Real_Status = TRUE;
	 GarageHeightRequest_Real_Timer = K_GarageHeightRequest_Real_Timeout;  
    }
    /*Real-time Monitor*/
    if(TRUE == GarageHeightRequest_Real_Status)
    {
         if(GarageHeightRequest_Real_Timer == 0)
         {
	      GarageHeightRequest_Real_Status = FALSE; 
	      if(TRUE == K_GarageHeightRequest_SingleEvent_Enable) /*10,1110 is MultiEvent, 1,111 is SingleEvent */
	      {
		   GarageHeightRequest_Status = FALSE;
	      } 
         }
         else
         {
	      GarageHeightRequest_Real_Timer --;
         }
    }  
  
    /* GarageHeightRequest RiseEdge and FallEdge Active monitor */  
    if((FALSE == GarageHeightRequest_Status) && (TRUE == GarageHeightRequest_LastStatus))
    {
    	 GarageHeightRequest_RiseEdge_Active = TRUE;
    } 
    else
    {
    	 GarageHeightRequest_RiseEdge_Active = FALSE;
    }
 
    if((TRUE == GarageHeightRequest_Status) && (FALSE == GarageHeightRequest_LastStatus))
    {
	 GarageHeightRequest_FallEdge_Active = TRUE;

    }	 
    else
    {
	 GarageHeightRequest_FallEdge_Active = FALSE;
    }
}
#endif
#endif
#ifdef _NIU_COM 
#ifdef _CONFIG_GarageHeightRequest
/*********************************************************************************************
** Name:	  MessageDebounce_GarageHeightRequest(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_GarageHeightRequest(void)
{	
    static uint16_t GarageHeightRequest_DataStream = 0; 
    static uint8_t GarageHeightRequest_Timer_Status = 0;
    static uint16_t GarageHeightRequest_Real_Timer;
    
  /* GarageHeightRequest Status Active monitor */  
    GarageHeightRequest_LastStatus = GarageHeightRequest_Status;
    
    if(TRUE == MessageRx_GarageHeight_Ind)
    {  
	 MessageRx_GarageHeight_Ind = FALSE;
         	 
	 MessageRx_GarageHeight_LastValue = MessageRx_GarageHeight_Value;   	 
	 if((MessageRx_GarageHeight >= _MMI2_RearDoorPosSet_50_percent) && (MessageRx_GarageHeight <= _MMI2_RearDoorPosSet_100_percent))
	 {
              MessageRx_GarageHeight_Value = (uint16_t)((uint32_t)((MessageRx_GarageHeight + 50) * SystemLearned_Position) / 100);
	 }
	 else
	 {
	      MessageRx_GarageHeight_Value = 0;
	 }
	 
         if((MessageRx_GarageHeight_Value != MessageRx_GarageHeight_LastValue)
             &&((MessageRx_GarageHeight_Value >= K_GarageLearned_Position_Min)
	       &&(MessageRx_GarageHeight_Value <= K_GarageLearned_Position_Max)))
         {
	      GarageHeightRequest_DataStream |= 0x0001;
         }
         if((MASK01BIT & GarageHeightRequest_DataStream) == MASK01BIT)	 
         {    
              GarageHeightRequest_Status = TRUE;
         }
         else if((MASK01BIT & GarageHeightRequest_DataStream) == 0)
         {
    	      GarageHeightRequest_Status = FALSE;
         }   
         GarageHeightRequest_DataStream <<=1;
    	 GarageHeightRequest_Real_Status = TRUE;
	 GarageHeightRequest_Real_Timer = K_GarageHeightRequest_Real_Timeout;  
    }
    /*Real-time Monitor*/
    if(TRUE == GarageHeightRequest_Real_Status)
    {
         if(GarageHeightRequest_Real_Timer == 0)
         {
	      GarageHeightRequest_Real_Status = FALSE; 
	      if(TRUE == K_GarageHeightRequest_SingleEvent_Enable) /*10,1110 is MultiEvent, 1,111 is SingleEvent */
	      {
		   GarageHeightRequest_Status = FALSE;
	      } 
         }
         else
         {
	      GarageHeightRequest_Real_Timer --;
         }
    }  
  
    /* GarageHeightRequest RiseEdge and FallEdge Active monitor */  
    if((FALSE == GarageHeightRequest_Status) && (TRUE == GarageHeightRequest_LastStatus))
    {
    	 GarageHeightRequest_RiseEdge_Active = TRUE;
    } 
    else
    {
    	 GarageHeightRequest_RiseEdge_Active = FALSE;
    }
 
    if((TRUE == GarageHeightRequest_Status) && (FALSE == GarageHeightRequest_LastStatus))
    {
	 GarageHeightRequest_FallEdge_Active = TRUE;

    }	 
    else
    {
	 GarageHeightRequest_FallEdge_Active = FALSE;
    }
}
#endif
#endif
#ifdef _FAW_COM 
#ifdef _CONFIG_GarageHeightRequest
/*********************************************************************************************
** Name:	  MessageDebounce_GarageHeightRequest(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_GarageHeightRequest(void)
{	
    static uint16_t GarageHeightRequest_DataStream = 0; 
    static uint16_t GarageHeightRequest_Real_Timer;
    
  /* GarageHeightRequest Status Active monitor */ 
    GarageHeightRequest_LastStatus = GarageHeightRequest_Status;
    
    if(TRUE == MessageRx_GarageHeightRequest_Ind)
    {  
	 MessageRx_GarageHeightRequest_Ind = FALSE; 
         
         MessageRx_GarageHeight_Value = (uint16_t)((uint32_t)(MessageRx_GarageHeight * SystemLearned_Position) / 100);
  
         if((MessageRx_GarageHeightRequest == TRUE) /* TRUE or Active, based on Message define*/
             &&((MessageRx_GarageHeight_Value >= K_GarageLearned_Position_Min)
	       &&(MessageRx_GarageHeight_Value <= K_GarageLearned_Position_Max)))
         {
	      GarageHeightRequest_DataStream |= 0x0001;
         }
         if((MASK01BIT & GarageHeightRequest_DataStream) == MASK01BIT)	 
         {    
              GarageHeightRequest_Status = TRUE;
         }
         else if((MASK01BIT & GarageHeightRequest_DataStream) == 0)
         {
    	      GarageHeightRequest_Status = FALSE;
         }   
         GarageHeightRequest_DataStream <<=1;
    	 GarageHeightRequest_Real_Status = TRUE;
	 GarageHeightRequest_Real_Timer = K_GarageHeightRequest_Real_Timeout;  
    }
    /*Real-time Monitor*/
    if(TRUE == GarageHeightRequest_Real_Status)
    {
         if(GarageHeightRequest_Real_Timer == 0)
         {
	      GarageHeightRequest_Real_Status = FALSE; 
	      if(TRUE == K_GarageHeightRequest_SingleEvent_Enable) /*10,1110 is MultiEvent, 1,111 is SingleEvent */
	      {
		   GarageHeightRequest_Status = FALSE;
	      } 
         }
         else
         {
	      GarageHeightRequest_Real_Timer --;
         }
    }  
  
    /* GarageHeightRequest RiseEdge and FallEdge Active monitor */  
    if((FALSE == GarageHeightRequest_Status) && (TRUE == GarageHeightRequest_LastStatus))
    {
    	 GarageHeightRequest_RiseEdge_Active = TRUE;
    } 
    else
    {
    	 GarageHeightRequest_RiseEdge_Active = FALSE;
    }
 
    if((TRUE == GarageHeightRequest_Status) && (FALSE == GarageHeightRequest_LastStatus))
    {
	 GarageHeightRequest_FallEdge_Active = TRUE;

    }	 
    else
    {
	 GarageHeightRequest_FallEdge_Active = FALSE;
    }
}
#endif
#endif

#ifdef _CHANGAN_COM 
#ifdef _CONFIG_GarageHeightRequest
/*********************************************************************************************
** Name:	  MessageDebounce_GarageHeightRequest(void);
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void MessageDebounce_GarageHeightRequest(void)
{	
    static uint16_t GarageHeightRequest_DataStream = 0; 
    static uint16_t GarageHeightRequest_Real_Timer;
    
  /* GarageHeightRequest Status Active monitor */ 
    GarageHeightRequest_LastStatus = GarageHeightRequest_Status;
    
    if(TRUE == MessageRx_GarageHeightRequest_Ind)
    {  
	 MessageRx_GarageHeightRequest_Ind = FALSE; 
         
         MessageRx_GarageHeight_Value = (uint16_t)((uint32_t)(MessageRx_GarageHeight * SystemLearned_Position) / 100);
  
         if((MessageRx_GarageHeightRequest == TRUE) /* TRUE or Active, based on Message define*/
             &&((MessageRx_GarageHeight_Value >= K_GarageLearned_Position_Min)
	       &&(MessageRx_GarageHeight_Value <= K_GarageLearned_Position_Max)))
         {
	      GarageHeightRequest_DataStream |= 0x0001;
         }
         if((MASK01BIT & GarageHeightRequest_DataStream) == MASK01BIT)	 
         {    
              GarageHeightRequest_Status = TRUE;
         }
         else if((MASK01BIT & GarageHeightRequest_DataStream) == 0)
         {
    	      GarageHeightRequest_Status = FALSE;
         }   
         GarageHeightRequest_DataStream <<=1;
    	 GarageHeightRequest_Real_Status = TRUE;
	 GarageHeightRequest_Real_Timer = K_GarageHeightRequest_Real_Timeout;  
    }
    /*Real-time Monitor*/
    if(TRUE == GarageHeightRequest_Real_Status)
    {
         if(GarageHeightRequest_Real_Timer == 0)
         {
	      GarageHeightRequest_Real_Status = FALSE; 
	      if(TRUE == K_GarageHeightRequest_SingleEvent_Enable) /*10,1110 is MultiEvent, 1,111 is SingleEvent */
	      {
		   GarageHeightRequest_Status = FALSE;
	      } 
         }
         else
         {
	      GarageHeightRequest_Real_Timer --;
         }
    }  
  
    /* GarageHeightRequest RiseEdge and FallEdge Active monitor */  
    if((FALSE == GarageHeightRequest_Status) && (TRUE == GarageHeightRequest_LastStatus))
    {
    	 GarageHeightRequest_RiseEdge_Active = TRUE;
    } 
    else
    {
    	 GarageHeightRequest_RiseEdge_Active = FALSE;
    }
 
    if((TRUE == GarageHeightRequest_Status) && (FALSE == GarageHeightRequest_LastStatus))
    {
	 GarageHeightRequest_FallEdge_Active = TRUE;

    }	 
    else
    {
	 GarageHeightRequest_FallEdge_Active = FALSE;
    }
}
#endif
#endif


/*********************************************************************************************
** End of file
*********************************************************************************************/
