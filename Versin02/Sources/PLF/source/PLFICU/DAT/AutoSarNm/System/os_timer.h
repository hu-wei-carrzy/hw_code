#ifndef __OS_TIMER_H
#define __OS_TIMER_H

/*********************************************************************************************
** Global Structures' Definition
*********************************************************************************************/
//#include "pinout_manage.h"

typedef struct 
{
    uint16_t TF1ms   : 1;		/* 1 ms Tick flag. */
    uint16_t TF2ms   : 1;		/* 2 ms Tick flag. */
    uint16_t TF5ms   : 1;		/* 5 ms Tick flag. */
    uint16_t TF10msA  : 1;              /* 10 ms A Tick flag. */
    uint16_t TF10msB  : 1;              /* 10 ms B Tick flag. */
    uint16_t TF10msC  : 1;              /* 10 ms C Tick flag. */
    uint16_t TF20ms  : 1;		/* 20 ms Tick flag. */
    uint16_t TF50ms  : 1;		/* 50 ms Tick flag. */
    uint16_t TF100ms : 1;		/* 100 ms Tick flag. */
    uint16_t TF1s    : 1;		 /* 1 second Tick flag. */      
} tD_TickFlag;

/*********************************************************************************************
** MACROS
**********************************************************************************************/

#define API_Get01msTimer(i)		DecreaseTimer01ms[i]
#define API_Set01msTimer(i,v)   	DecreaseTimer01ms[i] = (v)

#define API_Get10msTimer(i)		DecreaseTimer10ms[i]
#define API_Set10msTimer(i,v)   	DecreaseTimer10ms[i] = (v)


/*********************************************************************************************
** Global Variables Declarations
**********************************************************************************************/

/* TIMER_01MS */

typedef enum
{
    Timer_SystemMode,          /*00*/
    Timer_LatchMode,           /*01*/				
    Timer_Release,             /*02*/
    Timer_Cinch,               /*03*/				
    Timer_Speedup,             /*04*/
    Timer_CommandDelay,        /*05*/
    Timer_CommandInterval,     /*06*/
    Timer_OperateDelay,        /*07*/
    Timer_SWConfirm,           /*08*/
    Timer_CinchHold,           /*09*/
    Timer_Netrual,             /*10*/
    Timer_FindHome,            /*11*/
    Timer_CommandInhibition,   /*12*/
    Timer_SystemDelay,         /*13*/
    Timer_AfterPark,           /*14*/ 
    Timer_Netrual_2nd,         /*15*/
    Timer_Netrual_3rd,         /*16*/
    Timer_Inrush,              /*17*/
    Timer_PushDetect,          /*18*/
    Timer_Cinch_2nd,           /*19*/
    Timer_FindHome_2nd,        /*20*/
    Timer_HardStart,           /*21*/
    Timer_Beat,                /*22*/
    Timer_Duration,            /*23*/
    Timer_Motor1_CinchHold,    /*24*/
    Timer_Motor2_CinchHold,    /*25*/
    Timer_ReleaseToOpen,       /*26*/
    Timer_Stop,                /*27*/
    Timer_RiseEdge,            /*28*/
    Timer_ReleaseToClose,      /*29*/
    Timer_01ms                 /*30*/
    
} tD_Timer_01ms;

/* TIMER_10MS */

typedef enum
{
    Timer_Motor1ManualMoving,   /*00*/
    Timer_Motor2ManualMoving,   /*01*/	
    Timer_FollowOperate_Wait,   /*02*/
    Timer_FollowOperate,        /*03*/
    Timer_Motor1_OperateSmooth,     /*04*/
    Timer_Motor2_OperateSmooth,     /*05*/
    Timer_Motor1_SoftStop,      /*06*/				
    Timer_Motor2_SoftStop,      /*07*/				
    Timer_SleepState,            /*08*/
    Timer_SGMWNM,                /*09*/
    Timer_NMLocalEvent,          /*10*/
    Timer_NMRemoteEvent,         /*11*/
    Timer_NMFrame,               /*12*/
    Timer_UDSFrame,              /*13*/
    Timer_UDSKeepEvent,          /*14*/
    Timer_IgntionKeepEvent,      /*15*/
    Timer_LocalKeepEvent,        /*16*/
    Timer_SwitchKeepEvent,       /*17*/
    Timer_Motor1HallObstacle_SoftStop,  /*18*/
    Timer_Motor2HallObstacle_SoftStop,  /*19*/
    Timer_PushDetectDisable,     /*20*/
    Timer_Braking,               /*21*/
    Timer_LatchBraking,          /*22*/
    Timer_NMLocalEvent_MinTime,  /*23*/
    Timer_WarningDelay,          /*24*/
    #ifdef _CONFIG_Clutch
    Timer_ClutchControl,         /*25*/
    #endif
    #ifdef _CONFIG_Shiftfork
    Timer_ShiftforkMode,         /*25*/
    Timer_ShiftforkStop,         /*26*/
    #endif
    #ifdef _CONFIG_ClutchHold
    Timer_ClutchHoldMode,        /*25*/
    #endif
    #ifdef _CONFIG_MotorHold
    Timer_MotorHoldMode,         /*26*/
    #endif
    #ifdef _CONFIG_ManualOperate
    Timer_ManualOperateMode,     /*27*/
    #endif 
    #ifdef _CONFIG_PowerHandle
    Timer_HandleMode,            /*24*/
    Timer_HandleCommandInterval, /*25*/
    Timer_HandleCommandDelay,    /*26*/
    Timer_HandleStop,            /*27*/
    Timer_HandleInrush,          /*28*/
    Timer_HandleWork,            /*29*/
    #endif
    #ifdef _CONFIG_PowerSpoiler
    Timer_SpoilerMode,            /*24*/
    Timer_SpoilerCommandInterval, /*25*/
    Timer_SpoilerCommandDelay,    /*26*/
    Timer_SpoilerStop,            /*27*/
    Timer_SpoilerInrush,          /*28*/
    Timer_SpoilerWork,            /*29*/
    Timer_Spoiler_Speedup,        /*30*/
    Timer_Spoiler_SoftStop,       /*31*/
    Timer_SpoilerHallObstacle_SoftStop, /*32*/
    Timer_Spoiler_HardStart,            /*33*/
    Timer_SpoilerCommandInhibition,     /*34*/
    #endif
    #ifdef _CONFIG_PowerWindow
    Timer_WindowMode,            /*24*/
    Timer_WindowCommandInterval, /*25*/
    Timer_WindowCommandDelay,    /*26*/
    Timer_WindowStop,            /*27*/
    Timer_WindowInrush,          /*28*/
    Timer_WindowWork,            /*29*/
    Timer_Window_Speedup,        /*30*/
    Timer_Window_SoftStop,       /*31*/
    Timer_WindowHallObstacle_SoftStop, /*32*/
    Timer_Window_HardStart,            /*33*/
    Timer_WindowCommandInhibition,     /*34*/
    #endif
    Timer_10ms                    /*35*/
    
} tD_Timer_10ms;


extern uint16_t DecreaseTimer01ms[Timer_01ms];
extern uint16_t DecreaseTimer10ms[Timer_10ms];



/* tD_TickFlag TickFlag */

extern volatile tD_TickFlag TickFlag;				

/*********************************************************************************************
** Function Prototypes with Global Scope
*********************************************************************************************/

extern void Tick_Init(void);
extern void RTI_Function(void);



#endif /* __OS_TIMER_H*/
/*********************************************************************************************
** EOF
*********************************************************************************************/

