//******************************************************************************
// Company:      Johnson Controls Inc.
// -----------------------------------------------------------------------------
// Copyright:    This software is JCI property.
//               Duplication or disclosure without JCI written authorization
//               is prohibited.
// -----------------------------------------------------------------------------
// Project:      STK
// Language:     ANSI-C
// -----------------------------------------------------------------------------
// Component:    TOS_PerfCnt
//
// -----------------------------------------------------------------------------
// $Date:   May 08 2014 16:34:34  $
// $Archive:   //DI_SGM_358_HUD/archives/SGM358_1017957/Dev/APP/BUILD/SOURCES/TOS/TOS_PERFCNT/TOS_PERFCNT.C-arc  $
// $Revision:   1.0  $
// -----------------------------------------------------------------------------
/* $Log:   //DI_SGM_358_HUD/archives/SGM358_1017957/Dev/APP/BUILD/SOURCES/TOS/TOS_PERFCNT/TOS_PERFCNT.C-arc  $
//
//   Rev 1.0   May 08 2014 16:34:34   amiaot
//Initial revision.
// 
//    Rev 1.0   20 Jan 2014 14:37:38   amollos
// Initial revision.
// 
//    Rev 1.0   20 Jan 2014 12:20:36   amollos
// Initial revision.
 * 
 *    Rev 1.2   Jul 18 2006 15:43:44   aminkov
 * PON URD47 DEV 959 / PON URD45 BODY_SW 477 - Improve TOS_PerfCnt integration
 * 
 *    Rev 1.1   Jul 12 2006 14:23:38   arozdik
 * PON URD42 DEV 3861 / PON URD45 BODY_SW 493 : Coding Guidelines PONAEHNT044227 applying
 * 
 *    Rev 1.0   Apr 14 2006 14:57:54   aminkov
 * Initial revision.
 * 
 *    Rev 1.2   Apr 13 2006 15:57:06   aminkov
 * u32ProcessStartExecutionTime and u32TOSPerfProcessCallCount in both Cycle and Exec time
 * 
 *    Rev 1.1   Apr 05 2006 09:41:46   aminkov
 * u32ProcessStartExecutionTime should be defined in both Cycle and Execution time configurations
 * 
 *    Rev 1.0   Mar 22 2006 15:54:44   aminkov
 * Initial revision.
 * 
 *    Rev 1.1   Mar 21 2006 18:40:00   aminkov
 * fix QAC warnings
 * 
 *    Rev 1.0   Mar 21 2006 17:40:30   aminkov
 * Initial revision.
*/
//******************************************************************************

//------------------------------------------------------------------------------
// Body Identification
//------------------------------------------------------------------------------
#define tos_perf   "tos_perf"

//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//------------------------------------------------------------------------------
#include "ARCH_CFG.h"

#ifdef cHeadIncludeType_Directly
#include "LIB.h"
#include "tos.h"

#include "ldb_tos.h"
#include "Tos_PerfCnt.h"
#else
#include ".\..\..\LIB\LIB_API\LIB.h"
#include ".\..\tos.h"

#include ".\..\..\LDB\LDB_API\ldb_tos.h"
#include "Tos_PerfCnt.h"


#endif

#ifdef TOS_PERF_CNT_ENABLE

//------------------------------------------------------------------------------
// Local constants
//------------------------------------------------------------------------------
#define cMaxU32             ((U32)0xffffffffu)
#define cIndexOfUnknownHandles  0

//------------------------------------------------------------------------------
// Local macros
//------------------------------------------------------------------------------
#define mMemSetArray(ArrayName,Value)                       \
    ( mLIBmemset((ArrayName),(Value),sizeof(ArrayName)) )

//------------------------------------------------------------------------------
// Local types
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Local data
//------------------------------------------------------------------------------

// Common Local data
static U32 u32ExecutionPrescaleCounter;
static U32 u32ProcessStartExecutionTime[cTOSPerfProcessNumber];
#ifdef TOS_PERF_CNT_ENABLE_EXEC_TIME
    // Local data for execution time measurement
    static U8 u8ProcessIndexStack[cTOSPerfProcessStackSize];
    static U32 u32ProcessAdjustedStartTimeStack[cTOSPerfProcessStackSize];
    static volatile REG rTopOfProcessStack;
#endif

//------------------------------------------------------------------------------
// Constant local data
//------------------------------------------------------------------------------
static const U8 cu8HandleToIndexConversionTable[cTOSPerfHandleToIndexTableSize] = 
    mTOSPerfHandleToIndexConversionTable();

//------------------------------------------------------------------------------
// Exported data
//------------------------------------------------------------------------------

// Common exported data
volatile BOOL bTOSPerfWorkingState;
U32 u32TOSPerfExecutionTotalTime;
U32 u32TOSPerfProcessCallCount[cTOSPerfProcessNumber];
#ifdef TOS_PERF_CNT_ENABLE_EXEC_TIME
    // Exported data for execution time measurement
	U32 u32TOSPerfProcessTotalExecutionTime[cTOSPerfProcessNumber];
	U32 u32TOSPerfProcessMaximumExecutionTime[cTOSPerfProcessNumber];
	U32 u32TOSPerfProcessMinimumExecutionTime[cTOSPerfProcessNumber];
    // used for debugging purpose only. this number should not become too big
    U8 u8TOSPerfStackUnderflowNumber;
	U16 u16TOSPerfEnterTime;
	U16 u16TOSPerfExitTime;
#endif

#ifdef TOS_PERF_CNT_ENABLE_CYCLE_TIME
    // Exported data for execution cycle measurement
	U32 u32TOSPerfProcessMaximumCycleTime[cTOSPerfProcessNumber];
	U32 u32TOSPerfProcessMinimumCycleTime[cTOSPerfProcessNumber];
#endif

//------------------------------------------------------------------------------
// Constant exported data
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Local function prototypes
//------------------------------------------------------------------------------

//==============================================================================
//=========================== LOCAL FUNCTIONS ==================================
//==============================================================================

//==============================================================================
//=========================== EXPORTED FUNCTIONS ===============================
//==============================================================================

//==============================================================================
// DESCRIPTION:         See component header file
//==============================================================================
void TOSPerfCntStart(void)
{
    REG I;
#ifdef TOS_PERF_CNT_ENABLE_EXEC_TIME
	U32 u32StartTime;
#endif
#ifdef TOS_PERF_CNT_ENABLE_EXEC_TIME
    mTOSPerfDisableInterrupts();
	    bTOSPerfWorkingState = cTrue;
        u32StartTime = LDBTimPerfCntGetTime();
        TOSPerfCntEnter(0);
        TOSPerfCntEnter(0);
        TOSPerfCntEnter(0);
        TOSPerfCntEnter(0);
	    u16TOSPerfEnterTime = (U16)((LDBTimPerfCntGetTime() - u32StartTime)>>2);
        u32StartTime = LDBTimPerfCntGetTime();
	    TOSPerfCntExit();
	    TOSPerfCntExit();
	    TOSPerfCntExit();
	    TOSPerfCntExit();
	    u16TOSPerfExitTime = (U16)((LDBTimPerfCntGetTime() - u32StartTime)>>2);
	    bTOSPerfWorkingState = cFalse;
	mTOSPerfEnableInterrupts();
    mMemSetArray(u32TOSPerfProcessTotalExecutionTime,0);
    mMemSetArray(u32TOSPerfProcessMaximumExecutionTime,0);
    for(I=0;I<cTOSPerfProcessNumber;++I)
    {
        u32TOSPerfProcessMinimumExecutionTime[I] = cMaxU32;
    }
    u8TOSPerfStackUnderflowNumber = 0;
	rTopOfProcessStack = 0;
#endif 
#ifdef TOS_PERF_CNT_ENABLE_CYCLE_TIME
    mMemSetArray(u32TOSPerfProcessMaximumCycleTime,0);
    for(I=0;I<cTOSPerfProcessNumber;++I)
    {
        u32TOSPerfProcessMinimumCycleTime[I] = cMaxU32;
    }
#endif
    mMemSetArray(u32TOSPerfProcessCallCount,0);
    u32TOSPerfExecutionTotalTime = 0;
    u32ExecutionPrescaleCounter = LDBTimPerfCntGetTime();
    bTOSPerfWorkingState = cTrue;
}

//==============================================================================
// DESCRIPTION:         See component header file
//==============================================================================
void TOSPerfCntEnter(const REG rProcessHandle)
{
    REG rProcessIndex;
	U32 u32Time;
    U32 u32Tmp;
#ifdef TOS_PERF_CNT_ENABLE_EXEC_TIME
    REG rStackIndex;
#endif
    if( cTrue==bTOSPerfWorkingState )
    {
        mTOSPerfSuspendInterrupts();
        u32Time = LDBTimPerfCntGetTime();
        u32Tmp = u32Time-u32ExecutionPrescaleCounter;
        if( u32Tmp>=cTOSPerfTotalTimePassedPrescalerValue )
        {
            u32TOSPerfExecutionTotalTime += u32Tmp>>cTOSPerfTotalTimePassedPrescalerLog2;
            u32ExecutionPrescaleCounter += u32Tmp & ~(cTOSPerfTotalTimePassedPrescalerValue-(U32)1);
        }
        if( rProcessHandle<cTOSPerfHandleToIndexTableSize )
        {
            rProcessIndex = cu8HandleToIndexConversionTable[rProcessHandle];
            mLIBassert(rProcessIndex<cTOSPerfProcessNumber);
        }
        else
        {
            rProcessIndex = cIndexOfUnknownHandles;
        }
#ifdef TOS_PERF_CNT_ENABLE_EXEC_TIME
        mLIBassert(rTopOfProcessStack<cTOSPerfProcessStackSize);
        rStackIndex = rTopOfProcessStack;
        ++rTopOfProcessStack;
        u8ProcessIndexStack[rStackIndex] = (U8)rProcessIndex;
        u32ProcessAdjustedStartTimeStack[rStackIndex] = u32Time + u16TOSPerfEnterTime;
#endif
        mTOSPerfResumeInterrupts();
#ifdef TOS_PERF_CNT_ENABLE_CYCLE_TIME
		if (u32TOSPerfProcessCallCount[rProcessIndex] > (U32)0)
		{
			u32Tmp = u32Time - u32ProcessStartExecutionTime[rProcessIndex];
		    if (u32Tmp > u32TOSPerfProcessMaximumCycleTime[rProcessIndex])
		    {
			    u32TOSPerfProcessMaximumCycleTime[rProcessIndex] = u32Tmp;
		    }
		    if (u32Tmp < u32TOSPerfProcessMinimumCycleTime[rProcessIndex])
		    {
			    u32TOSPerfProcessMinimumCycleTime[rProcessIndex] = u32Tmp;
		    }
		}
#endif
        u32ProcessStartExecutionTime[rProcessIndex] = u32Time;
        ++u32TOSPerfProcessCallCount[rProcessIndex];
	}
}

//==============================================================================
// DESCRIPTION:         See component header file
//==============================================================================
void TOSPerfCntExit(void)
{
#ifdef TOS_PERF_CNT_ENABLE_EXEC_TIME
	U32 u32ProcessExecTime;
	REG rProcessIndex;
	REG rStackIndex;
	U32 u32Time;
	if ( cTrue==bTOSPerfWorkingState )
	{
        mTOSPerfSuspendInterrupts();
        if(rTopOfProcessStack==(REG)0)
        {
            // do not allow return to MainLoop before TOSPerfCntStop() call
            ++u8TOSPerfStackUnderflowNumber;
            mLIBassert(u8TOSPerfStackUnderflowNumber<cTOSPerfProcessStackSize);
        }
        else
        {
    	    mLIBassert(rTopOfProcessStack<=cTOSPerfProcessNumber);
            u32Time = LDBTimPerfCntGetTime();
            rStackIndex = --rTopOfProcessStack;
            rProcessIndex = u8ProcessIndexStack[rStackIndex];
            if( rStackIndex>(U32)0 )
            {
                u32ProcessAdjustedStartTimeStack[rStackIndex-(U32)1] += 
                    ((U32)u16TOSPerfExitTime + u32Time) - u32ProcessStartExecutionTime[rProcessIndex] ;
            }
            u32ProcessExecTime = u32Time - u32ProcessAdjustedStartTimeStack[rStackIndex];
            if( (S32)u32ProcessExecTime < (S32)1 )
            {
                u32ProcessExecTime = 1;
            }
            u32TOSPerfProcessTotalExecutionTime[rProcessIndex] += u32ProcessExecTime;
		    if (u32ProcessExecTime > u32TOSPerfProcessMaximumExecutionTime[rProcessIndex])
		    {
			    u32TOSPerfProcessMaximumExecutionTime[rProcessIndex] = u32ProcessExecTime;
		    }
		    if (u32ProcessExecTime < u32TOSPerfProcessMinimumExecutionTime[rProcessIndex])
		    {
			    u32TOSPerfProcessMinimumExecutionTime[rProcessIndex] = u32ProcessExecTime;
		    }
        }
        mTOSPerfResumeInterrupts();
    }
#endif
}

//==============================================================================
// DESCRIPTION:         See component header file
//==============================================================================
void TOSPerfCntStop(void)
{
	bTOSPerfWorkingState = cFalse;
#ifdef TOS_PERF_CNT_ENABLE_EXEC_TIME
    u32TOSPerfExecutionTotalTime += 
        (LDBTimPerfCntGetTime()-u32ExecutionPrescaleCounter)>>cTOSPerfTotalTimePassedPrescalerLog2;
#endif
}

//==============================================================================
// DESCRIPTION:         See component header file
//==============================================================================
U8 TOSPerfIndexToHandle(U8 u8Index)
{
    U8 I;
    for(I=0;I<cTOSPerfHandleToIndexTableSize;++I)
    {
        if( cu8HandleToIndexConversionTable[I]==u8Index )
        {
            break;
        }
    }
    if( I==cTOSPerfHandleToIndexTableSize )
    {
        I = cTOSPerfInvalidHandle;
    }
    return I;
}

#endif // PERF_CNT_ENABLE

