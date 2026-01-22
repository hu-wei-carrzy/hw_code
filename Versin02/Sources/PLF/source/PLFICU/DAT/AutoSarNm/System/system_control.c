

/*********************************************************************************************
** Header Files
*********************************************************************************************/



#include "typedefs.h"
//#include "iodefine.h"
//#include "os_timer.h"
//#include "r_cg_adc.h"
//#include "r_cg_stbc.h"
//#include "latch_control.h"
#include "system_control.h"
//#include "system_calibration.h"
//#include "project_calibration.h"
//#include "com_calibration.h"
//#include "speed_control.h"
//#include "obstacle_detect.h"
//#include "fault_process.h"
//#include "message_process.h"
//#include "request_process.h"
//#include "api_interface.h"
//#include "pinout_manage.h"
//#include "spindle_control.h"
//#include "mode_control.h"
//#include "buzzer_control.h"
//#include "memory_manage.h"
//#include "sleep_manage.h"
//#include "command_process.h"
//#include "operate_process.h"
//#include "did_process.h"
//#include "uds_calibrate.h"
//#include "config_process.h"
//#include "incline_detect.h"
//#include "manual_control.h"
//#include "motorhold_control.h"
//#include "gate_calibration.h"
//#include "gate_calibrationfile.h"
//#include "door_calibration.h"
//#include "door_calibrationfile.h"



#ifdef _CONFIG_PowerHandle
#include "handle_control.h"
#endif
#ifdef _CONFIG_PowerSpoiler
#include "spoiler_control.h"
#endif

#ifdef _CONFIG_PowerWindow
#include "window_control.h"
#endif

//#include "clutch_control.h"
//#include "shiftfork_control.h"
//#include "clutchhold_control.h"
//#include "motorhold_control.h"
//#include "sonic_radar.h"
//#include "mmw_radar.h"
//#include "adas_radar.h"

/*********************************************************************************************
** Global Variables Definitions
*********************************************************************************************/
uint8_t System_AfterWakeup_Status;
uint8_t System_AfterPowerUp_Status;
uint8_t System_FromReset_Status;

uint8_t Latch_AfterWakeup_Status;
uint8_t Latch_AfterPowerUp_Status;
uint8_t Latch_FromReset_Status;

uint8_t SBC_WakeUp_Status;
uint8_t SBC_PowerOn_Status;

uint8_t DisableMode_AfterPowerUp_Status;
uint8_t Message_AfterPowerUp_Status;
uint8_t Message_AfterWakeup_Status;
uint8_t Message_FromReset_Status;
uint8_t NM_AfterPowerUp_Status;
uint8_t NM_AfterWakeup_Status;
uint8_t NM_FromReset_Status;
uint8_t NM_FromSleepProcess_Status;

#ifdef _CONFIG_LIN_Master
uint8_t LIN_AfterPowerUp_Status;
uint8_t LIN_AfterWakeup_Status;
uint8_t LIN_FromReset_Status;
#endif

uint8_t MessageTx_AfterWakeup_Status;

uint8_t FastCycle_AfterPowerUp_Status;
uint8_t FastCycle_AfterWakeup_Status;
uint8_t FastCycle_FromReset_Status;

#ifdef _CONFIG_SmallAngle
uint8_t SmallAngle_AfterPowerUp_Status;
#endif

#ifdef _CONFIG_DefaultClose_AfterPowerUp
uint8_t DefaultClose_AfterPowerUp_Status;
#endif
uint8_t DefaultClose_AfterWakeup_Status;

#ifdef _CONFIG_SystemClosedFully_AfterWakeup
uint8_t SystemClosedFullyAfterWakeup_Status;
#endif

#ifdef _CONFIG_Brake_StartInOpen_Disable
uint8_t Break_AfterPowerUp_Status; 
uint8_t Break_AfterWakeup_Status; 
#endif


uint8_t ReleaseToPowerOpen_Start_Status;
uint8_t ReleaseToPowerOpen_End_Status;
uint16_t ReleaseToPowerOpen_End_Timer;
int16_t ReleaseToPowerOpen_Duty_Adder_LowTemp;

uint16_t ReleaseToPowerOpen_ManualOperate_Timer;
uint16_t ReleaseToPowerOpen_ManualOperate_RealSpeed;
uint8_t ReleaseToPowerOpen_ManualOperate_Status;

uint8_t ReleaseToPowerOpen_PowerPull_Start_Status;
uint8_t ReleaseToPowerOpen_PowerPull_End_Status;
uint8_t LatchPowerReleasing_Delay_Status;
uint8_t LatchPowerReleasing_Request_Status;
uint8_t LatchPowerReleasing_DuringCinchToPowerOpen_Request;

uint8_t SystemPowerMode_Timeout_Status;
uint8_t CinchHold_Timeout_Status;

uint8_t SystemPowerCinching_ChangeDuty_Status;
uint8_t SystemPowerCinching_DecreaseDuty_Timer;

uint8_t Motor2_SystemPowerCinching_ChangeDuty_Status;
uint8_t Motor2_SystemPowerCinching_DecreaseDuty_Timer;

uint8_t GarageLearnedSucessful_Status;
uint8_t SystemLearnedSucessful_Status;

uint8_t GarageLearnedFailure_Status;
uint8_t SystemLearnedFailure_Status;

uint8_t StopBeforePowerOpening_Status;
uint8_t StopBeforePowerClosing_Status;

uint8_t StopSoftThenReverse_FromOpening_Status;
uint8_t StopSoftThenReverse_FromClosing_Status;

uint8_t System_StartFromHomePosition_Status;
//uint8_t GateMotion
tD_SystemMode ActiveSystemMode;
tD_SystemMode LastSystemMode;
tD_SystemMode PreSystemState;
tD_SystemMode LastPowerState_ForReversal;
tD_SystemMode LastPowerState_ForCrank;

tD_System_Information Mem_System_Information;

uint8_t SystemLearned_Status;
uint16_t SystemLearned_Position;

uint8_t GarageLearned_Status;
uint16_t GarageLearned_Position;

tD_Learn_Information Mem_Learn_Information;
tD_FET_Information Mem_FET_Information;

uint16_t MaxTravel_HallCount;

uint8_t System_ReLearn_Request_Status;

uint8_t LearnProcess_Timeout_Status;
uint8_t LearnProcess_PowerOpen_Status;
uint8_t LearnProcess_PowerClose_Status;

uint8_t Motor1_LearnProcess_OpenFinish_Status;
uint8_t Motor2_LearnProcess_OpenFinish_Status;

uint8_t Motor1_LearnProcess_CloseFinish_Status;
uint8_t Motor2_LearnProcess_CloseFinish_Status;

uint8_t LearnProcess_PowerOpen_Ready;
uint8_t LearnProcess_PowerClose_Ready;

uint8_t LearnProcess_OpenFinish_Status;
uint8_t LearnProcess_CloseFinish_Status;
uint8_t LearnProcess_PowerOpen_Failure;
uint8_t LearnProcess_PowerClose_Failure;

uint8_t NormalProcess_PowerOpen_Status;
uint8_t NormalProcess_PowerClose_Status;

uint8_t Motor1_NormalProcess_OpenFinish_Status;
uint8_t Motor2_NormalProcess_OpenFinish_Status;
uint8_t Motor1_NormalProcess_CloseFinish_Status;
uint8_t Motor2_NormalProcess_CloseFinish_Status;

uint8_t SystemBraking_Status;
uint8_t SystemBraking_Request;
uint8_t DisableBrake_ObstacleStop_Request;
uint8_t DisableBrake_SmallOpenMode_Request;
uint8_t DisableBrake_PowerOpenDisable_Request;
uint8_t DisableBrake_Radar_Request;

uint8_t ReleaseToPowerOpen_FromClosedFully_Status;
uint8_t ReleaseToPowerOpen_PowerClosingObstacle_Status;

/*For Debug*/

uint8_t Flag_SystemClosedFully;          
uint8_t Flag_SystemReleaseToPowerOpen;   
uint8_t Flag_SystemReleaseOnly;          
uint8_t Flag_SystemReleased;            
uint8_t Flag_SystemOpenClutchEngage;      
uint8_t Flag_SystemPowerOpening;         
uint8_t Flag_SystemOpenClutchDisengage;  
uint8_t Flag_SystemOpenedFully;          
uint8_t Flag_SystemCloseClutchEngage ;   
uint8_t Flag_SystemPowerClosing;         
uint8_t Flag_SystemPowerCinching;        
uint8_t Flag_SystemPowerParking;         
uint8_t Flag_SystemCloseClutchDisengage; 
uint8_t Flag_SystemMechFailure;             
uint8_t Flag_SystemManualCinching;       
uint8_t Flag_SystemManualParking;         
uint8_t Flag_SystemCrankWait;  
 
uint8_t Flag_SystemPropUpRecovery;
uint8_t Flag_SystemManualRelease;

#ifdef _CONFIG_ReleaseToPowerClose
uint8_t Flag_SystemReleaseToPowerClose;
#endif

uint8_t Flag_LastPowerState_ForReversal;
/*********************************************************************************************
** Variables at File Scope
*********************************************************************************************/
uint8_t Motor1_CinchHold_Status;
uint8_t Motor2_CinchHold_Status;

uint8_t SystemPowerOnFinish;
uint16_t SystemPowerOn_Timer;

uint8_t SystemWakeUpFinish;
uint16_t SystemWakeUp_Timer;

uint8_t SystemResetFinish;
uint16_t SystemReset_Timer;

uint16_t ShortDistanceInOpening_Motor1_PositionDelta;
uint16_t ShortDistanceInOpening_Motor2_PositionDelta;
uint16_t ShortDistanceInClosing_Motor1_PositionDelta;
uint16_t ShortDistanceInClosing_Motor2_PositionDelta;

int8_t DriveMotor_Duty;
/*********************************************************************************************
** Functions with Global Scope
*********************************************************************************************/
void PE10ms_SystemControl_Master(void);
void SystemStateMachine_Init(void);

/*********************************************************************************************
** Functions with Local Scope
*********************************************************************************************/
static void SystemStateMachine(void);

static void SystemState_InitDefault(void);

static void SystemState_ClosedFully(void);
static void SystemState_ReleaseToPowerOpen(void);
static void SystemState_ReleaseOnly(void);
static void SystemState_Released(void);
static void SystemState_OpenClutchEngage(void);
static void SystemState_PowerOpening(void);
static void SystemState_OpenClutchDisengage(void);
static void SystemState_OpenedFully(void);
static void SystemState_CloseClutchEngage(void);
static void SystemState_PowerClosing(void);
static void SystemState_PowerCinching(void);
static void SystemState_PowerParking(void);
static void SystemState_CloseClutchDisengage(void);

static void SystemState_ManualCinching(void);
static void SystemState_ManualParking(void);
static void SystemState_CrankWait(void);
static void SystemState_MechFailure(void);
static void SystemState_PropUpRecovery(void);
static void SystemState_ManualRelease(void);

#ifdef _CONFIG_ReleaseToPowerClose
static void SystemState_ReleaseToPowerClose(void);
#endif

static void LastPowerState_ForReversal_Monitor(void);

static void API_DriveMotor_Duty(void);
static void API_TurnOn_DriveMotor_Open(void);
static void API_TurnOn_DriveMotor_Close(void);
static void API_TurnOff_DriveMotor(void);
static void API_Brake_DriveMotor(void);

static void API_DriveMotor_BrakeToGround(void);
static void API_DriveMotor_BrakeToBattery(void);
static void API_DriveMotor_BrakeToHold(uint16_t duty);

static void API_DriveMotor_Position_Clear(void);
static void API_DriveMotor_Location_Clear(void);
static void API_DriveMotor_HallCounter_Clear(void);
static void API_TurnOn_DriveMotor_HallPower(void);

/*********************************************************************************************
** Name:	  SystemStateMachine_Init
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
void SystemStateMachine_Init(void)
{

}
/*********************************************************************************************
** Name:	  PE10ms_SystemControl_Master
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
void PE10ms_SystemControl_Master(void)
{     

}

/*********************************************************************************************
** Name:	  SystemStateMachine
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/                 
static void SystemStateMachine(void)
{
   switch(ActiveSystemMode)
   {
      case SystemClosedFully:    
	   SystemState_ClosedFully();
	   break;
      
      case SystemReleaseToPowerOpen:
	   SystemState_ReleaseToPowerOpen();
	   break;
			
      case SystemReleaseOnly:
	   SystemState_ReleaseOnly();
	   break;
		
      case SystemReleased:
	   SystemState_Released();
	   break;
	    
      case SystemOpenClutchEngage:
	   SystemState_OpenClutchEngage();
	   break;
	  	
      case SystemPowerOpening:
           SystemState_PowerOpening();
	   break;
	   
      case SystemOpenClutchDisengage:
	   SystemState_OpenClutchDisengage();
	   break;
	    
      case SystemOpenedFully:
	   SystemState_OpenedFully();
	   break;
	   
      case SystemCloseClutchEngage:
	   SystemState_CloseClutchEngage();
	   break;
	     
      case SystemPowerClosing:
	   SystemState_PowerClosing();
	   break;
	   
      case SystemPowerCinching:
	   SystemState_PowerCinching();
	   break;
	
      case SystemPowerParking:
	   SystemState_PowerParking();
	   break;
	   
      case SystemCloseClutchDisengage:
	   SystemState_CloseClutchDisengage();
	   break;
	   
      case SystemManualCinching:
	   SystemState_ManualCinching();
	   break;
	
      case SystemManualParking:
	   SystemState_ManualParking();
	   break;

      case SystemCrankWait:
	   SystemState_CrankWait();
	   break;
	   
      case SystemPropUpRecovery:   
	   SystemState_PropUpRecovery();
	   break;
      
      #ifdef _CONFIG_ReleaseToPowerClose	   
      case SystemReleaseToPowerClose:   
	   SystemState_ReleaseToPowerClose();
	   break;
      #endif	
	   
      case SystemManualRelease:   
	   SystemState_ManualRelease();
	   break;
	   
      case SystemInitDefault:
           SystemState_InitDefault();
           break;
	  
      default:
	   SystemState_MechFailure();
	   break;
   }
}


/*********************************************************************************************
** Name:	  SystemState_InitDefault
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void SystemState_InitDefault(void)
{

}

/*********************************************************************************************
** Name:	  SystemState_ClosedFully
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void SystemState_ClosedFully(void)
{

}

/*********************************************************************************************
** Name:	  SystemState_ReleaseToPowerOpen
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void SystemState_ReleaseToPowerOpen(void)
{
  
   
}

/*********************************************************************************************
** Name:	  SystemState_PowerOpening
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void SystemState_PowerOpening(void)
{ 

}

/*********************************************************************************************
** Name:	  SystemState_ReleaseOnly
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void SystemState_ReleaseOnly(void)
{ 

}

/*********************************************************************************************
** Name:	  SystemState_ManualRelease
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void SystemState_ManualRelease(void)
{ 

}

/*********************************************************************************************
** Name:	  SystemState_Released
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void SystemState_Released(void)
{ 

}

/*********************************************************************************************
** Name:	  SystemState_OpenClutchEngage
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void SystemState_OpenClutchEngage(void)
{ 
   if(ActiveSystemMode != LastSystemMode)
   {
        PreSystemState = LastSystemMode;
        LastSystemMode = ActiveSystemMode;
   }
/* PLG Command Implement*/  

/* Latch Mode Machine Reference*/  

/* Running System Mode is timeout*/ 
}



/*********************************************************************************************
** Name:	  SystemState_OpenClutchDisengage
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void SystemState_OpenClutchDisengage(void)
{ 
   if(ActiveSystemMode != LastSystemMode)
   {
        PreSystemState = LastSystemMode;
        LastSystemMode = ActiveSystemMode;
   }
   
/* PLG Command Implement*/  

/* Latch Mode Machine Reference*/  

/* Running System Mode is timeout*/ 
}

/*********************************************************************************************
** Name:	  SystemState_OpenedFully
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void SystemState_OpenedFully(void)
{ 

}

/*********************************************************************************************
** Name:	  SystemState_CloseClutchEngage
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void SystemState_CloseClutchEngage(void)
{ 
   if(ActiveSystemMode != LastSystemMode)
   {
       PreSystemState = LastSystemMode;
       LastSystemMode = ActiveSystemMode;
   }
   
/* PLG Command Implement*/  

/* Latch Mode Machine Reference*/    

/* Running System Mode is timeout*/ 
	
}

#ifdef _CONFIG_ReleaseToPowerClose
uint8_t ReleaseToPowerClose_Work_Status;
/*********************************************************************************************
** Name:	  SystemState_ReleaseToPowerClose
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void SystemState_ReleaseToPowerClose(void)
{
   if(ActiveSystemMode != LastSystemMode)
   {
       PreSystemState = LastSystemMode;
       LastSystemMode = ActiveSystemMode;
 
       DecreaseTimer01ms[Timer_SystemMode] = K_SystemReleaseToPowerClose_Timeout;  
       DecreaseTimer01ms[Timer_ReleaseToClose] = K_ReleaseToPowerClose_Delay_Time;
       
       if(ActiveLatchMode != LatchInitDefault)
       {
            ActiveLatchMode = LatchPowerReleasing;
            Flag_LatchPowerReleasing = 2; 
            ReleaseToPowerClose_Work_Status = FALSE;
       }
   }	
        
/* PLG Command Implement*/  
   if((FALSE == ReleaseToPowerClose_Work_Status) && (DecreaseTimer01ms[Timer_ReleaseToClose] == 0))
   {
        ReleaseToPowerClose_Work_Status = TRUE;

	DriveMotor_Duty = API_ReferTo12Voltage_Duty(K_ReleaseToPowerClose_Duty)
			  + API_ReferTo20Degree_Adder(K_ReleaseToPowerClose_Duty_Adder_HighTemp,K_ReleaseToPowerClose_Duty_Adder_LowTemp) 
	                  #ifdef _CONFIG_Incline
			  + API_ReferTo0Incline_Close_Adder(K_ReleaseToPowerClose_Duty_Adder_CloseUpgrade,K_ReleaseToPowerClose_Duty_Adder_CloseDowngrade) 
			  #endif
	if(DriveMotor_Duty < 0)
	{
             DriveMotor_Duty = 0;
	}
        API_TurnOn_DriveMotor_Close();
	API_DriveMotor_Duty();
	
        DecreaseTimer01ms[Timer_ReleaseToClose] = K_ReleaseToPowerClose_Work_Time;			      
   }

/* Latch Mode Machine Reference*/
   if(TRUE == ReleaseToPowerClose_Work_Status)
   {
        if(ActiveLatchMode == LatchPreReleased)
        {
              ActiveSystemMode = SystemPowerClosing;
              Flag_SystemPowerClosing = 7;
        }
	else if(DecreaseTimer01ms[Timer_ReleaseToClose] == 0)
	{
	      ActiveSystemMode = SystemPowerClosing;
              Flag_SystemPowerClosing = 8;
	}
   }
   
   if(FALSE == HoldOpenLatch_Position_Status)
   {
	 ActiveSystemMode = SystemPowerClosing;
         Flag_SystemPowerClosing = 9;
   }
   
/* Running System Mode is timeout*/ 
   if(DecreaseTimer01ms[Timer_SystemMode] == 0)
   {
        ActiveSystemMode = SystemMechFailure;
        Flag_SystemMechFailure = 27;      
        SystemPowerMode_Timeout_Status = TRUE;
   }
}
#endif
/*********************************************************************************************
** Name:	  SystemState_PowerClosing
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void SystemState_PowerClosing(void)
{ 

}

/*********************************************************************************************
** Name:	  SystemState_PowerCinching
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void SystemState_PowerCinching(void)
{ 

}

/*********************************************************************************************
** Name:	  SystemState_PowerParking
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void SystemState_PowerParking(void)
{ 

}

/*********************************************************************************************
** Name:	  SystemState_CloseClutchDisengage
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void SystemState_CloseClutchDisengage(void)
{ 
   if(ActiveSystemMode != LastSystemMode)
   {
       PreSystemState = LastSystemMode;
       LastSystemMode = ActiveSystemMode;
   }
   
/* PLG Command Implement*/  

/* Latch Mode Machine Reference*/    

/* Running System Mode is timeout*/ 
	
}

/*********************************************************************************************
** Name:	  SystemState_ManualCinching
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void SystemState_ManualCinching(void)
{ 

}

/*********************************************************************************************
** Name:	  SystemState_ManualParking
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void SystemState_ManualParking(void)
{ 
   
}

/*********************************************************************************************
** Name:	  SystemState_CrankWait
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void SystemState_CrankWait(void)
{ 
   
}

/*********************************************************************************************
** Name:	  SystemState_MechFailure
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void SystemState_MechFailure(void)
{

}

/*********************************************************************************************
** Name:	  SystemState_PropUpRecovery
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void SystemState_PropUpRecovery(void)
{
   
}




/*********************************************************************************************
** Name:	  LastPowerState_ForReversal_Monitor
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void LastPowerState_ForReversal_Monitor(void)
{

}


/*********************************************************************************************
** Name:	  API_TurnOn_DriveMotor_Open
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void API_TurnOn_DriveMotor_Open(void)
{

}

/*********************************************************************************************
** Name:	  API_TurnOn_DriveMotor_Close
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void API_TurnOn_DriveMotor_Close(void)
{

}

/*********************************************************************************************
** Name:	  API_DriveMotor_Duty
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void API_DriveMotor_Duty(void)
{

}

/*********************************************************************************************
** Name:	  API_TurnOff_DriveMotor
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void API_TurnOff_DriveMotor(void)
{

}

/*********************************************************************************************
** Name:	  API_Brake_DriveMotor
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void API_Brake_DriveMotor(void)
{
      API_DriveMotor_BrakeToGround();
}

/*********************************************************************************************
** Name:	  API_DriveMotor_BrakeToGround
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void API_DriveMotor_BrakeToGround(void)
{

}

/*********************************************************************************************
** Name:	  API_DriveMotor_BrakeToBattery
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void API_DriveMotor_BrakeToBattery(void)
{

}

/*********************************************************************************************
** Name:	  API_DriveMotor_BrakeToHold
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void API_DriveMotor_BrakeToHold(uint16_t duty)
{
 
}


/*********************************************************************************************
** Name:	  API_DriveMotor_Position_Clear
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void API_DriveMotor_Position_Clear(void)
{

}

/*********************************************************************************************
** Name:	  API_DriveMotor_Location_Clear
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void API_DriveMotor_Location_Clear(void)
{

}

/*********************************************************************************************
** Name:	  API_DriveMotor_HallCounter_Clear
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void API_DriveMotor_HallCounter_Clear(void)
{

}

/*********************************************************************************************
** Name:	  API_TurnOn_DriveMotor_HallPower
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        10ms
*********************************************************************************************/
static void API_TurnOn_DriveMotor_HallPower(void)
{

}

/*********************************************************************************************
** End of file
*********************************************************************************************/
