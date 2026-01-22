#ifndef __SYSTEM_CONTROL_H 
#define __SYSTEM_CONTROL_H 

/*********************************************************************************************
** MACROS
**********************************************************************************************/
//#define _CONFIG_LastPowerState_ReverseToShortDistance
//#define _CONFIG_LastPowerState_PowerOpenToMiniAngle

/*********************************************************************************************
** Global Structures' Definition
*********************************************************************************************/

//#include "latch_control.h"
//#include "spindle_control.h"

/* System Mode */
typedef enum
{
    SystemInitDefault = 0,      /*0U*/
    SystemClosedFully,          /*1U*/
    SystemReleaseToPowerOpen,   /*2U*/
    SystemReleaseOnly,          /*3U*/
    SystemReleased,             /*4U*/
    SystemOpenClutchEngage,     /*5U*/   /*Used for PSD*/
    SystemReserve1,             /*6U*/
    SystemPowerOpening,         /*7U*/
    SystemOpenClutchDisengage,  /*8U*/   /*Used for PSD*/
    SystemOpenedFully,          /*9U*/
    SystemCloseClutchEngage ,   /*10U*/   /*Used for PSD*/
    SystemReleaseToPowerClose,  /*11U*/   /*Used for PSD*/
    SystemPowerClosing,         /*12U*/
    SystemPowerCinching,        /*13U*/
    SystemPowerParking,         /*14U*/
    SystemCloseClutchDisengage, /*15U*/   /*Used for PSD*/
    SystemMechFailure,          /*16U*/
    
    SystemManualCinching,       /*17U*/
    SystemManualParking,        /*18U*/
    
    SystemCrankWait,            /*19U*/
    SystemPropUpRecovery,       /*20U*/
    SystemManualRelease,        /*21U*/ /*Used for ER31 Side Latch*/
    
    SystemMachineEnd            /*22U*/
    
} tD_SystemMode;

/*Mem_Learn_Information*/
#define Learn_Information_BuffLen       7
typedef struct
{
    uint16_t SystemLearned_Position;    		          
    uint16_t GarageLearned_Position;
    uint8_t SystemLearned_Status;    		        
    uint8_t GarageLearned_Status; 
    uint8_t CPIDLearnSucceed_Status;
}tD_Learn_Information_Struct;

typedef union 
{
    tD_Learn_Information_Struct element;
    uint8_t array[Learn_Information_BuffLen];
}tD_Learn_Information;

extern tD_Learn_Information Mem_Learn_Information;

#define Mem_SystemLearned_Status        Mem_Learn_Information.element.SystemLearned_Status
#define Mem_SystemLearned_Position      Mem_Learn_Information.element.SystemLearned_Position
#define Mem_GarageLearned_Status        Mem_Learn_Information.element.GarageLearned_Status
#define Mem_GarageLearned_Position      Mem_Learn_Information.element.GarageLearned_Position
#define Mem_CPIDLearnSucceed_Status      Mem_Learn_Information.element.CPIDLearnSucceed_Status

/*Mem_FET_Information*/
#define FET_Information_BuffLen       20
typedef struct
{
    uint16_t Motor1_FET_Cal_Ratio_Value;
    uint16_t Motor2_FET_Cal_Ratio_Value;
    uint16_t CinchMotor_FET_Cal_Ratio_Value;
    uint16_t Motor1_FET_Base_Offset_Value;
    uint16_t Motor2_FET_Base_Offset_Value;
    uint16_t CinchMotor_FET_Base_Offset_Value;   
    uint8_t Motor1_FET_Cal_Status;
    uint8_t Motor2_FET_Cal_Status;
    uint8_t CinchMotor_FET_Cal_Status;
    uint8_t Motor4_FET_Cal_Status;
    uint16_t Motor4_FET_Cal_Ratio_Value;
    uint16_t Motor4_FET_Base_Offset_Value;
           
}tD_FET_Information_Struct;

typedef union 
{
    tD_FET_Information_Struct element;
    uint8_t array[FET_Information_BuffLen];
}tD_FET_Information;

extern tD_FET_Information Mem_FET_Information;

#define Mem_Motor1_FET_Cal_Status              Mem_FET_Information.element.Motor1_FET_Cal_Status
#define Mem_Motor2_FET_Cal_Status              Mem_FET_Information.element.Motor2_FET_Cal_Status
#define Mem_CinchMotor_FET_Cal_Status          Mem_FET_Information.element.CinchMotor_FET_Cal_Status
#define Mem_Motor1_FET_Cal_Ratio_Value         Mem_FET_Information.element.Motor1_FET_Cal_Ratio_Value
#define Mem_Motor2_FET_Cal_Ratio_Value         Mem_FET_Information.element.Motor2_FET_Cal_Ratio_Value
#define Mem_CinchMotor_FET_Cal_Ratio_Value     Mem_FET_Information.element.CinchMotor_FET_Cal_Ratio_Value
#define Mem_Motor1_FET_Base_Offset_Value       Mem_FET_Information.element.Motor1_FET_Base_Offset_Value
#define Mem_Motor2_FET_Base_Offset_Value       Mem_FET_Information.element.Motor2_FET_Base_Offset_Value
#define Mem_CinchMotor_FET_Base_Offset_Value   Mem_FET_Information.element.CinchMotor_FET_Base_Offset_Value

#define Mem_Motor4_FET_Cal_Status              Mem_FET_Information.element.Motor4_FET_Cal_Status
#define Mem_Motor4_FET_Cal_Ratio_Value         Mem_FET_Information.element.Motor4_FET_Cal_Ratio_Value
#define Mem_Motor4_FET_Base_Offset_Value       Mem_FET_Information.element.Motor4_FET_Base_Offset_Value

/*Mem_System_Information*/
#define System_Information_BuffLen       14
typedef struct
{
     uint16_t Motor1_Position;
     uint16_t Motor2_Position;
     uint8_t ActiveSystemMode;
     uint8_t LastSystemMode;
     uint8_t PreSystemState;
     uint8_t LastPowerState_ForReversal;    
     uint8_t ActiveLatchMode;
     uint8_t LastLatchMode;
     uint8_t PreLatchState;     
     uint8_t ObstacleTimes_Total_Counter;
     uint8_t PlayTimes_Counter; 
     uint8_t DisableMode_AfterPowerUp_Status;
}tD_System_Information_Struct;

typedef union 
{
    tD_System_Information_Struct element;
    uint8_t array[System_Information_BuffLen];
}tD_System_Information;

extern tD_System_Information Mem_System_Information;

#define Mem_Motor1_Position                 Mem_System_Information.element.Motor1_Position
#define Mem_Motor2_Position                 Mem_System_Information.element.Motor2_Position
#define Mem_ActiveSystemMode                Mem_System_Information.element.ActiveSystemMode
#define Mem_LastSystemMode                  Mem_System_Information.element.LastSystemMode
#define Mem_PreSystemState                  Mem_System_Information.element.PreSystemState
#define Mem_LastPowerState_ForReversal      Mem_System_Information.element.LastPowerState_ForReversal
#define Mem_ActiveLatchMode                 Mem_System_Information.element.ActiveLatchMode
#define Mem_LastLatchMode                   Mem_System_Information.element.LastLatchMode
#define Mem_PreLatchState                   Mem_System_Information.element.PreLatchState
#define Mem_ObstacleTimes_Total_Counter  Mem_System_Information.element.ObstacleTimes_Total_Counter
#define Mem_PlayTimes_Counter        Mem_System_Information.element.PlayTimes_Counter
#define Mem_DisableMode_AfterPowerUp_Status  Mem_System_Information.element.DisableMode_AfterPowerUp_Status

/*********************************************************************************************
** MACROS
**********************************************************************************************/




/*********************************************************************************************
** Global Variables Declarations
**********************************************************************************************/

extern uint8_t System_AfterWakeup_Status;
extern uint8_t System_AfterPowerUp_Status;
extern uint8_t System_FromReset_Status;

extern uint8_t Latch_AfterWakeup_Status;
extern uint8_t Latch_AfterPowerUp_Status;
extern uint8_t Latch_FromReset_Status;

extern uint8_t SBC_WakeUp_Status;
extern uint8_t SBC_PowerOn_Status;

extern uint8_t DisableMode_AfterPowerUp_Status;
extern uint8_t Message_AfterPowerUp_Status;
extern uint8_t Message_AfterWakeup_Status;
extern uint8_t Message_FromReset_Status;
extern uint8_t NM_AfterPowerUp_Status;
extern uint8_t NM_AfterWakeup_Status;
extern uint8_t NM_FromReset_Status;
extern uint8_t NM_FromSleepProcess_Status;

extern uint8_t LIN_AfterPowerUp_Status;
extern uint8_t LIN_AfterWakeup_Status;
extern uint8_t LIN_FromReset_Status;

extern uint8_t MessageTx_AfterWakeup_Status;

#ifdef _CONFIG_SmallAngle
extern uint8_t SmallAngle_AfterPowerUp_Status;
#endif

#ifdef _CONFIG_DefaultClose_AfterPowerUp
extern uint8_t DefaultClose_AfterPowerUp_Status;
#endif
extern uint8_t DefaultClose_AfterWakeup_Status;
#ifdef _CONFIG_SystemClosedFully_AfterWakeup
extern uint8_t SystemClosedFullyAfterWakeup_Status;
#endif

#ifdef _CONFIG_Brake_StartInOpen_Disable
extern uint8_t Break_AfterPowerUp_Status; 
extern uint8_t Break_AfterWakeup_Status; 
#endif

extern uint8_t FastCycle_AfterPowerUp_Status;
extern uint8_t FastCycle_AfterWakeup_Status;
extern uint8_t FastCycle_FromReset_Status;

extern uint8_t SystemPowerMode_Timeout_Status;

extern uint8_t SystemLearned_Status;
extern uint8_t GarageLearned_Status;

extern uint8_t GarageLearnedSucessful_Status;
extern uint8_t SystemLearnedSucessful_Status;

extern uint8_t GarageLearnedFailure_Status;
extern uint8_t SystemLearnedFailure_Status;

extern uint16_t SystemLearned_Position;
extern uint16_t GarageLearned_Position;
extern uint16_t MaxTravel_HallCount;

extern uint8_t System_ReLearn_Request_Status;

extern uint8_t LearnProcess_Timeout_Status;
extern uint8_t LearnProcess_PowerOpen_Status;
extern uint8_t LearnProcess_PowerClose_Status;

extern uint8_t LearnProcess_PowerOpen_Ready;
extern uint8_t LearnProcess_PowerClose_Ready;

extern uint8_t LearnProcess_OpenFinish_Status;
extern uint8_t LearnProcess_CloseFinish_Status;
extern uint8_t LearnProcess_PowerOpen_Failure;
extern uint8_t LearnProcess_PowerClose_Failure;

extern uint8_t Motor1_LearnProcess_OpenFinish_Status;
extern uint8_t Motor2_LearnProcess_OpenFinish_Status;

extern uint8_t Motor1_LearnProcess_CloseFinish_Status;
extern uint8_t Motor2_LearnProcess_CloseFinish_Status;

extern uint8_t NormalProcess_PowerOpen_Status;
extern uint8_t NormalProcess_PowerClose_Status;

extern uint8_t Motor1_NormalProcess_OpenFinish_Status;
extern uint8_t Motor2_NormalProcess_OpenFinish_Status;
extern uint8_t Motor1_NormalProcess_CloseFinish_Status;
extern uint8_t Motor2_NormalProcess_CloseFinish_Status;

extern tD_SystemMode ActiveSystemMode;
extern tD_SystemMode LastSystemMode; 
extern tD_SystemMode PreSystemState;
extern tD_SystemMode LastPowerState_ForReversal;
extern tD_SystemMode LastPowerState_ForBraking;
extern tD_SystemMode LastPowerState_ForCrank;

extern uint8_t Motor1_CinchHold_Status;
extern uint8_t Motor2_CinchHold_Status;

extern uint8_t Flag_LastPowerState_ForReversal;
extern uint8_t SystemBraking_Status;
extern uint8_t SystemBraking_Request;
extern uint8_t DisableBrake_ObstacleStop_Request;
extern uint8_t DisableBrake_SmallOpenMode_Request;
extern uint8_t DisableBrake_PowerOpenDisable_Request;
extern uint8_t DisableBrake_Radar_Request;

#ifdef _CONFIG_CloseSpeed_SmallPosition
extern uint8_t CloseSpeed_SmallPosition_Status;
#endif
extern uint8_t LatchPowerReleasing_DuringCinchToPowerOpen_Request;
/*********************************************************************************************
** Function Prototypes with Global Scope
*********************************************************************************************/
extern void PE10ms_SystemControl_Master(void);
extern void SystemStateMachine_Init(void);

#endif /* __SYSTEM_CONTROL_H */
/*********************************************************************************************
** EOF
*********************************************************************************************/

