//******************************************************************************
// Copyright:    This software is JYD property.
//               Duplication or disclosure without JYD written authorization
//               is prohibited.
// -----------------------------------------------------------------------------
// Project:      BCM313
// Language:     C
// -----------------------------------------------------------------------------
// Component: exported header file for TOS  model.
// -----------------------------------------------------------------------------
//******************************************************************************
// This line is used to separate code and file header.This is begin.
//*****************************BEGIN_NOMOVE*************************************
// 1:add comment and change code to deal with the possible interrupt lost situation.

//*****************************END_NOMOVE***************************************
// This line is used to separate code and file header. This is last line.
//******************************************************************************
#ifndef I_TOSPARAM_H
#define I_TOSPARAM_H


// This definition determine the TOS_ORD component used
//#define TOS_PREEMPTIVE

// This definition enable the using of TOS_SIG component
#define USE_TOS_SIG

// This definition enable the using of EnableAllInterrupt services.
// In majority of case, this functions may not be used.
// You must define it only if there are interrupts of OSEK category 1.
// #define USE_DISABLE_ALL_INTERRUPTS

// This definition indicate that micro treat only a static datas
//#define NO_DYNAMIC_DATA

// This definition active services to set the timer tick and disable TOS timer
// (always disable TOS timer before set the timer tick value)
// Usefull when in sleep mode the CPU clock frequency is reduced but TOS timer
// are still active
#define USE_DISABLE_TOSTIMER

//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//------------------------------------------------------------------------------
#include "ARCH_CFG.h"
#ifdef cHeadIncludeType_Directly
#include "deftypes.h"
#include "lib.h"
#include "jil.h"
#include "LDB_INT.h"
#else
#include ".\..\..\LIB\LIB_API\deftypes.h"
#include ".\..\..\LIB\LIB_API\lib.h"
#include ".\..\..\SCC2Gen\Gen\jil.h"
#include ".\..\..\LDB\LDB_INT\LDB_INT.h"
#endif

//------------------------------------------------------------------------------
// Constant data
//------------------------------------------------------------------------------

//----- Scheduler management -----
// This definition determine the number of mode used for OSEK compatibility.
// It must be always equal 1
  #define cTOSNbMode                            1
  #define cTOSDefaultMode                       1

#if ( defined (NO_DYNAMIC_DATA) || defined(TOS_PREEMPTIVE) )
// If a scheduler stack is used, This definition adjust it.
  #define cTOSOffsetSchedulerStackSize          0UL
#endif

//----- Alarm definition -----
//This constant parameter is used to define the designed for Alarm management LDB Timer 
  #define cTOSTimerLdbDesignedForALA            cLDBTimer1

//----- Tick definition -----
  #define cTOSTickAlarmUs                       5000UL
  #define cTOSTimerTickMs                       10UL

//----  Graph scheduler parameters ----
  #define cTOSSeqMaxRuleNumber                  255   // 255 or 65535
  #define cTOSSeqDureeTourGrapheSimulationNs    3000000UL

  // -- Use for CPU Trace to avoid to trace the idle task
  //    (permit to let the trace points to others events)
  //#define TOS_NO_IDLE_TASK_TRACE

  // -- Use for CPU Trace to avoid to trace the idle mode (halt mode)
  //    (permit to let the trace points to others events)
  //#define TOS_NO_IDLE_MODE_TRACE

//------------------------------------------------------------------------------
// Exported Macros
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//                                QAC
//------------------------------------------------------------------------------
#if defined(_QAC_)
// This definition determine the size of micro bus
  #define cTOSBusInteger                        8UL      // 8UL,16UL or 32UL bits

//----- Interrupt management services -----
extern void NOP(void);
  #ifdef USE_DISABLE_ALL_INTERRUPTS
    #define TOSEnableAllInterrupts()    NOP()
    #define TOSDisableAllInterrupts()   NOP()

    #define TOSInternalGetAndDisableAllInterrupts(ITState)  ITState = 0;\
                                                            ITState = ITState
    #define TOSInternalSetAllInterruptsState(ITState)       ITState = 0;\
                                                            ITState = ITState
  #endif
  #define TOSEnableOSInterrupts()     NOP()
  #define TOSDisableOSInterrupts()    NOP()

  #define TOSInternalGetAndDisableOSInterrupts(ITState)   ITState = 0;\
                                                          ITState = ITState

  #define TOSInternalSetOSInterruptsState(ITState)        ITState = 0;\
                                                          ITState = ITState

  #define TOSToggleOSInterrupts()     TOSEnableOSInterrupts();    \
                                      NOP();                      \
                                      TOSDisableOSInterrupts()

  #ifdef TOS_PREEMPTIVE
    #define mTOSEnterISR()              NOP()
    #define mTOSLeaveISR()              NOP()
  #endif

//------------------------------------------------------------------------------
//                                POLYSPACE
//------------------------------------------------------------------------------
#elif defined(__POLYSPACE)
// This definition determine the size of micro bus
  #define cTOSBusInteger                        32UL      // 8UL,16UL or 32UL bits

//----- Interrupt management services -----
extern void NOP(void);
  #ifdef USE_DISABLE_ALL_INTERRUPTS
    #define TOSEnableAllInterrupts()
    #define TOSDisableAllInterrupts()

    #define TOSInternalGetAndDisableAllInterrupts(ITState)  ITState = 0
    #define TOSInternalSetAllInterruptsState(ITState)       ITState = 0

  #endif
  #define TOSEnableOSInterrupts()
  #define TOSDisableOSInterrupts()

  #define TOSInternalGetAndDisableOSInterrupts(ITState)   ITState = 0

  #define TOSInternalSetOSInterruptsState(ITState)        ITState = 0

  #define TOSToggleOSInterrupts()

  #ifdef TOS_PREEMPTIVE
    #define mTOSEnterISR()
    #define mTOSLeaveISR()
  #endif

//------------------------------------------------------------------------------
//                          COMPILATION NATIVE
//------------------------------------------------------------------------------
#elif defined(COMPILATION_NATIVE)
// This definition determine the size of micro bus
  #define cTOSBusInteger                        8UL      // 8UL,16UL or 32UL bits
  #define NOP()
//----- Interrupt management services -----
  #ifdef USE_DISABLE_ALL_INTERRUPTS
    #define TOSEnableAllInterrupts()
    #define TOSDisableAllInterrupts()

    #define TOSInternalGetAndDisableAllInterrupts(ITState)    ITState = 0
    #define TOSInternalSetAllInterruptsState(ITState)         ITState = 0
  #endif

  #define TOSEnableOSInterrupts()
  #define TOSDisableOSInterrupts()

  #define TOSInternalGetAndDisableOSInterrupts(ITState)     ITState = 0
  #define TOSInternalSetOSInterruptsState(ITState)          ITState = 0

  #define TOSToggleOSInterrupts()   TOSEnableOSInterrupts();    \
                                    NOP();                      \
                                    TOSDisableOSInterrupts()

  #ifdef TOS_PREEMPTIVE
    #define mTOSEnterISR()
    #define mTOSLeaveISR()
  #endif
#else 
//------------------------------------------------------------------------------
//                            MICRO H8S
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//                            MICRO NEC K0
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//                            MICRO M16C
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//                            MICRO M32C
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//                            MICRO NEC V850 Fx/Dx
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//                            MICRO Spanish ARM
//------------------------------------------------------------------------------
#if (defined(cLIBStkARMSpanish) )
    // This definition determine the size of micro bus
    #define cTOSBusInteger                        32UL      // 8UL,16UL or 32UL bits
    #define NOP()                                 __asm("nop")


    //----- Interrupt management services -----
    // This services are optional
    #ifdef USE_DISABLE_ALL_INTERRUPTS
        #define TOSEnableAllInterrupts()    __EI()
        #define TOSDisableAllInterrupts()   __DI()

        #define TOSInternalGetAndDisableAllInterrupts(ITState)  \
                    {                                           \
                        tTOSItState ITStateTmp;                 \
                        ITStateTmp = LDBIntReadItEnable();      \
                        __DI();                                 \
                    }

        #define TOSInternalSetAllInterruptsState(ITState)             \
                    {                                                 \
                        TOSDisableAllInterrupts();                    \
                        if (ITState != 0) TOSEnableAllInterrupts();   \
                    }
    #endif

    #define TOSEnableOSInterrupts()      __EI()
    #define TOSDisableOSInterrupts()     __DI()


 // here is example for implement yourself interrupt operation
//	if MCU supplier not provide interrupt function
    #define TOSInternalGetAndDisableOSInterrupts(ITState)       \
                {                                               \
                     BOOL  bIFSt;                \
                     bIFSt = LDBIntReadItEnable(); \
                     __asm volatile ("cpsid i" : : : "memory");    \
                     ITState = bIFSt;                 \
                }
  
//2016年8月30日 14:27:26
//因为以前发生过偶发性地中断停止的现象，怀疑原因可能在这里。
//ITState此值可能会在运行过程中，因为ARM流水线的问题，导
//致此值在流水线中表现不一致，导致中断被关掉而没有重启，所
//以，在目前没有使用嵌套中断的情况下，不再保存中断状态，只是
//单纯地禁止和使能中断。

    #define TOSInternalSetOSInterruptsState(ITState)             \
                {                                                                                \
    	         __asm volatile ("cpsie i" : : : "memory");      \
                }


    #define TOSToggleOSInterrupts()   TOSEnableOSInterrupts();    \
                                      NOP();                      \
                                      TOSDisableOSInterrupts()

#endif

#endif

//------------------------------------------------------------------------------
// Exported type
//------------------------------------------------------------------------------
//----- Clock management (must always be an unsigned type) -----
typedef U16 tTOSClock;

//----- Define the graph instance type -----
typedef U8 tTOSSeqGraphInstance;

//----- Define the SignalID type -----
typedef U16 tTOSSignalID;

//------------------------------------------------------------------------------
// Exported data
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Constant exported data
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Exported functions
//------------------------------------------------------------------------------

#endif // I_TOSPARAM_H
