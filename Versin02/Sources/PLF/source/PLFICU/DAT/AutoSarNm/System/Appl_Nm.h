#ifndef _APPL_BUSOFF_H_
#define  _APPL_BUSOFF_H_
#include "../CanIf/CanIf_Cbk.h"
#include "CanNm_lcfg.h"
#include "message_process.h"

/*******************************************************************************
* Name:    nmStateType
* Used by: NmGetCurState() (return type)
*          CanNm_SetNxtState() (parameter)
* Description:
*******************************************************************************/
typedef uint8 nmStateType;
/*******************************************************************************
* Name:        nmIndexType
* Description: This type is used for the Index counter.
* Note:        
*******************************************************************************/
typedef uint16 nmIndexType;

typedef uint16 nmTimerCntType;


#define NM_CANIF_USED_CONTROLLER_NUM           (1)
#define NM_NUMBER_OF_CHANNELS                  (1)


//extern void CAN_BusOffHook(uint8_t controlID);
extern void CAN_WakeupHook(void);

void BusOff_MainFunction(void);

/*******************************************************************************
*   Macro definitions 
*******************************************************************************/
#define DATA_INIT                        ((uint8)0x00u)
#define NM_BIT_SET                       (1)
#define NM_BIT_CLEAR                     (0)

#define NM_EXTENDED_CALLBACK_ENABLE 1

extern uint8 nmStatusTxCfm; 
extern uint8_t CANBus_Fault_Status;

/*******************************************************************************
* Name:    nmAlarmType
* Used by: NmSetAlarm() (parameter)
*******************************************************************************/

typedef enum
{
    /* nmAlarm=0, Timer TTyp */
    NM_TIMER_TYP = 0
    /* nmAlarm=1, Timer TMax */
    , NM_TIMER_MAX = 1
    /* nmAlarm=2, Timer TErr */
    , NM_TIMER_ERR = 2
    /* nmAlarm=3, Timer TWbs */
    , NM_TIMER_WBS = 3
    /* nmAlarm=4, Timer TTx */
    , NM_TIMER_TX = 4
    /* nmAlarm=5, fast Timer Tbusoff,OsekNm_006*/
    , NM_FAST_TIMER_TBUSOFF = 5
    /* nmAlarm=6, Slow Timer Tbusoff,OsekNm_008*/
    , NM_SLOW_TIMER_TBUSOFF = 6
    /* nmAlarm=9, All Timer*/
    , NM_TIMER_All = 9
} nmAlarmType;

#define NM_MAINFUNCTION_PERIOD                 (5)

#define NM_COUNT_FAST_TBUSOFF   \
    (nmCountBusoffFastTimerAry[nmCurChannel]/NM_MAINFUNCTION_PERIOD)
#define NM_COUNT_SLOW_TBUSOFF   \
    (nmCountBusoffSlowTimerAry[nmCurChannel]/NM_MAINFUNCTION_PERIOD)
    

#define nmTimerCntTbusoff  nmTimerCntTbusoffAry[nmCurChannel]

#define NM_BUSOFF_FAST_RECOVERY_TIMES     nmBusOffFastRecoveryAry[nmCurChannel]
#define NM_BUSOFF_SLOW_RECOVERY_TIMES     nmBusOffSlowRecoveryAry[nmCurChannel]

extern void clearnubNmBusOffCnt(void);
extern void NM_Wakeup_Source_Monitor(void);


#ifdef _CHERY_COM
#ifdef _CHERY_COM_PLG
typedef struct
{
    uint8_t IGNITION_WAKEUP    	  : 1; /* 0x01,*/
    uint8_t RESET_WAKEUP          : 1; /* 0x02,*/
    uint8_t NETWORK_WAKEUP    	  : 1; /* 0x04,*/
    uint8_t ECUSPEC_WAKEUP        : 1; /* 0x08,*/
    uint8_t NETWORK_AWAKE         : 1; /* 0x10,*/
    uint8_t IGNITION_AWAKE        : 1; /* 0x20,*/
    uint8_t DIAGNOSTIC_AWAKE      : 1; /* 0x40,*/
    uint8_t ECUSPEC_AWAKE         : 1; /* 0x80,*/
    
} tD_NM_Userdata1_Bit_Definition;
typedef union 
{
    tD_NM_Userdata1_Bit_Definition bits;
    uint8_t Byte;
} tD_NM_Userdata1;

extern tD_NM_Userdata1 NM_Userdata1;
#endif


#ifdef _CHERY_COM_PD
// typedef struct
// {
//     uint8_t Wakeup_Poweron    	  : 1; /* 0x01,*/
//     uint8_t Wakeup_NM             : 1; /* 0x02,*/
//     uint8_t Wakeup_Diag    	  : 1; /* 0x04,*/
//     uint8_t Wakeup_Hoaresignal    : 1; /* 0x08,*/
//     uint8_t Wakeup_Unused1        : 1; /* 0x10,*/
//     uint8_t Wakeup_Unused2        : 1; /* 0x20,*/
//     uint8_t Wakeup_Unused3        : 1; /* 0x40,*/
//     uint8_t Wakeup_Unused4        : 1; /* 0x80,*/
    
// } tD_NM_Userdata0_Bit_Definition;

//hw修改，为了符合网络帧
typedef struct
{
    uint8_t Wakeup_Poweron    	  : 1; /* 0x01,点火没用*/
    uint8_t Wakeup_Diag            : 1; /* 0x02, reset没用*/
    uint8_t Wakeup_NM    	  : 1; /* 0x04, 网络报文唤醒  */
    uint8_t Wakeup_Hoaresignal    : 1; /* 0x08,按键唤醒*/
    uint8_t Awake_NM        : 1; /* 0x10,网络报文唤醒保持没用*/
    uint8_t Awake_Poweron        : 1; /* 0x20,点火保持，没有*/
    uint8_t Awake_Diag        : 1; /* 0x40,诊断唤醒保持*/
    uint8_t Awake_Hoaresignal        : 1; /* 0x80,按键唤醒保持*/
    
} tD_NM_Userdata0_Bit_Definition;
typedef union 
{
    tD_NM_Userdata0_Bit_Definition bits;
    uint8_t Byte;
} tD_NM_Userdata0;


typedef struct
{
    uint8_t Awake_Poweron    	   : 1; /* 0x01,*/
    uint8_t Awake_NM               : 1; /* 0x02,*/
    uint8_t Awake_Diag    	   : 1; /* 0x04,*/
    uint8_t Awake_Hoaresignal      : 1; /* 0x08,*/
    uint8_t Awake_DoorSwitchChange : 1; /* 0x10,*/
    uint8_t Awake_Unused2          : 1; /* 0x20,*/
    uint8_t Awake_Unused3          : 1; /* 0x40,*/
    uint8_t Awake_Unused4          : 1; /* 0x80,*/
    
} tD_NM_Userdata3_Bit_Definition;
typedef union 
{
    tD_NM_Userdata3_Bit_Definition bits;
    uint8_t Byte;
} tD_NM_Userdata3;

extern tD_NM_Userdata0 NM_Userdata0;
extern tD_NM_Userdata3 NM_Userdata3;

#endif
#endif





#endif

