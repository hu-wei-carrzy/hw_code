
#ifndef I_TOS_PERF_H
#define I_TOS_PERF_H

//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//------------------------------------------------------------------------------
#include "ARCH_CFG.h"

#ifdef cHeadIncludeType_Directly
#include "deftypes.h"
#ifdef TOS_PERF_CNT_ENABLE
 #include "TOS_PERFCNTP.H"
#endif
#else
#include ".\..\..\LIB\LIB_API\deftypes.h"
#ifdef TOS_PERF_CNT_ENABLE
 #include "TOS_PERFCNTP.H"
#endif
#endif


//------------------------------------------------------------------------------
// Constant data
//------------------------------------------------------------------------------
#define cTOSPerfInvalidHandle          255

//------------------------------------------------------------------------------
// Exported type
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Exported data
//------------------------------------------------------------------------------
#ifdef TOS_PERF_CNT_ENABLE
    extern volatile BOOL bTOSPerfWorkingState;
    extern U32 u32TOSPerfExecutionTotalTime;
    extern U32 u32TOSPerfProcessCallCount[cTOSPerfProcessNumber];

#ifdef TOS_PERF_CNT_ENABLE_EXEC_TIME
    extern U32 u32TOSPerfProcessTotalExecutionTime[cTOSPerfProcessNumber];
    extern U32 u32TOSPerfProcessMaximumExecutionTime[cTOSPerfProcessNumber];
    extern U32 u32TOSPerfProcessMinimumExecutionTime[cTOSPerfProcessNumber];
    extern U8  u8TOSPerfStackUnderflowNumber;
	extern U16 u16TOSPerfEnterTime;
	extern U16 u16TOSPerfExitTime;
#endif

#ifdef TOS_PERF_CNT_ENABLE_CYCLE_TIME
    extern U32 u32TOSPerfProcessMaximumCycleTime[cTOSPerfProcessNumber];
    extern U32 u32TOSPerfProcessMinimumCycleTime[cTOSPerfProcessNumber];
#endif

#endif

//------------------------------------------------------------------------------
// Constant exported data
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Exported Macros
//------------------------------------------------------------------------------
#ifdef TOS_PERF_CNT_ENABLE
	// API macros:
    #define mTOSPerfCntStart()                  TOSPerfCntStart()
    #define mTOSPerfCntEnter(ID)                TOSPerfCntEnter(ID)
    #define mTOSPerfCntExit()                   TOSPerfCntExit()
    #define mTOSPerfCntStop()                   TOSPerfCntStop()
    #define mTOSPerfCntIsWorking()              bTOSPerfWorkingState
    #define mTOSPerfCntGetTotalExecutionTime()  u32TOSPerfExecutionTotalTime
    #define mTOSPerfCntGetProcessCallCount(Ix)  u32TOSPerfProcessCallCount[Ix]
    #ifdef TOS_PERF_CNT_ENABLE_EXEC_TIME
        #define mTOSPerfCntGetProcessTotalExecTime(Ix) u32TOSPerfProcessTotalExecutionTime[Ix]
        #define mTOSPerfCntGetProcessMaxExecTime(Ix)   u32TOSPerfProcessMaximumExecutionTime[Ix]
        #define mTOSPerfCntGetProcessMinExecTime(Ix)   u32TOSPerfProcessMinimumExecutionTime[Ix]
        #define mTOSPerfCntGetStackUnderflowNumber()   u8TOSPerfStackUnderflowNumber
	    #define mTOSPerfCntGetEnterTime()              u16TOSPerfEnterTime
	    #define mTOSPerfCntGetExitTime()               u16TOSPerfExitTime
    #else
        #define mTOSPerfCntGetProcessTotalExecTime(Ix) 0
        #define mTOSPerfCntGetProcessMaxExecTime(Ix)   0
        #define mTOSPerfCntGetProcessMinExecTime(Ix)   0
        #define mTOSPerfCntGetStackUnderflowNumber()   0
	    #define mTOSPerfCntGetEnterTime()              0
	    #define mTOSPerfCntGetExitTime()               0
    #endif
    #ifdef TOS_PERF_CNT_ENABLE_CYCLE_TIME
        #define mTOSPerfCntGetMaxCycleTime(Ix)         u32TOSPerfProcessMaximumCycleTime[Ix]
        #define mTOSPerfCntGetMinCycleTime(Ix)         u32TOSPerfProcessMinimumCycleTime[Ix]
    #else
        #define mTOSPerfCntGetMaxCycleTime(Ix)         0
        #define mTOSPerfCntGetMinCycleTime(Ix)         0
    #endif
#else // TOS_PERF_CNT_ENABLE
    #define mTOSPerfCntStart()
    #define mTOSPerfCntEnter(ID)
    #define mTOSPerfCntExit()
    #define mTOSPerfCntStop()
    #define mTOSPerfCntIsWorking() cFalse
    #define mTOSPerfCntGetTotalExecutionTime()  0
    #define mTOSPerfCntGetProcessCallCount(Ix)  0
#endif // TOS_PERF_CNT_ENABLE

//------------------------------------------------------------------------------
// Exported functions
//------------------------------------------------------------------------------

//==============================================================================
// DESCRIPTION:         Starts internal performance measurement
//
// PARAMETERS:          None
//
// RETURN VALUE:        None
//
// DESIGN INFORMATION:  Initializes all data and starts performance measurement
//==============================================================================
#ifdef TOS_PERF_CNT_ENABLE
void TOSPerfCntStart(void);
#endif

//==============================================================================
// DESCRIPTION:         Enter in process / interrupt
//
// PARAMETERS:          None
//
// RETURN VALUE:        None
//
// DESIGN INFORMATION:  This function should be called on every one enter in
//                      process/interrupt function which has to be measured
//==============================================================================
#ifdef TOS_PERF_CNT_ENABLE
void TOSPerfCntEnter(const REG rProcessHandle);
#endif

//==============================================================================
// DESCRIPTION:         Leave process / interrupt
//
// PARAMETERS:          None
//
// RETURN VALUE:        None
//
// DESIGN INFORMATION:  This function should be called on every one exit from
//                      process/interrupt function which has to be measured
//==============================================================================
#ifdef TOS_PERF_CNT_ENABLE
void TOSPerfCntExit(void);
#endif

//==============================================================================
// DESCRIPTION:         Stops internal performance measurement
//
// PARAMETERS:          None
//
// RETURN VALUE:        None
//
// DESIGN INFORMATION:  Stops performance counters 
//==============================================================================
#ifdef TOS_PERF_CNT_ENABLE
void TOSPerfCntStop(void);
#endif

//==============================================================================
// DESCRIPTION:         Convert process index to process handle
//
// PARAMETERS:          None
//
// RETURN VALUE:        Handle corresponding to given index 
//                or cTOSPerfInvalidHandle if index is not found
//
// DESIGN INFORMATION:  Stops performance counters 
//==============================================================================
#ifdef TOS_PERF_CNT_ENABLE
U8 TOSPerfIndexToHandle(U8 u8Index);
#endif

#endif // I_LAY_CMP_H
