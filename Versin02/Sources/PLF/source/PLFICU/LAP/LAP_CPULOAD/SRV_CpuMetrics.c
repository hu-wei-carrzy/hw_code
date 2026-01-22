

//#include "lib.h"
#include ".\..\LAP_LIB.h"
#include ".\INCLUDE\LIB_MEM_I.h"

#if defined(TRACE_CPU_ACTIVE) || defined(COMPILATION_NATIVE)

//==============================================================================
// Component trace identification
//==============================================================================
#define SRV_CpuMetrics   "SRV_CpuMetrics"


//==============================================================================
// INCLUDED FILES
//==============================================================================
#include ".\INCLUDE\basedef.h"
#include ".\INCLUDE\LIB_Mem_I.h"
#include "SRV_CpuMetrics.h"
#include "SRV_CpuMetrics_RI.h"
#include "SRV_CpuMetrics_Cfg.h"

//==============================================================================
// PRIVATE MACROS
//==============================================================================

#define cu8TraceHandle              (uint8)254

//==============================================================================
// PRIVATE TYPES
//==============================================================================
struct sCpuTraceEntry
{
    tTimeStamp Timestamp;
    uint8 u8Overflow;
    uint8 u8TaskId;
};
typedef struct sCpuTraceEntry tCpuTraceEntry;

struct sTaskMetrics
{
    uint32 u32MinCallPeriod;
    uint32 u32MaxCallPeriod;
    uint32 u32AvgCallPeriod;
    uint32 u32TotalExecutionTime;
    uint32 u32Executions;
    uint32 u32MinExecutionTime;
    uint32 u32MaxExecutionTime;
    tTimeStamp LastTimestampOccurrence;
    uint8 u8LastOverflowOccurrence;
    uint8 u8TaskId;
};

typedef struct sTaskMetrics tTaskMetrics;

//==============================================================================
// FORWARD DECLARATIONS OF PRIVATE FUNCTIONS
//==============================================================================

static void NextTraceEntry(void);
static void PeriodStatistics(const uint8 u8TaskIdP, const tTimeStamp TimestampP,
                             const uint8 u8OverflowNumP);
static void DurationStatistics(const uint8 u8TaskIdP, const uint32 u32DurationP);
static uint32 AnalyseTrace(void);

//==============================================================================
// PRIVATE DATA
//==============================================================================
//这里表示共可以记录这么多条记录，其中每条记录是一个任务和中断的执行情况。
static tCpuTraceEntry TraceBuffer[cMaxTraceBuffer];

static tTaskMetrics TaskMetrics[cu8TasksNumberInSystem];

static tCpuTraceEntry* pTraceUnderAnalysis;
static tCpuTraceEntry* pTraceUnderCollection;
static tCpuTraceEntry* pTraceStart;
static tCpuTraceEntry* pTraceEnd;

static uint32 u32TraceTotalTime;

static uint16 u16TimerOverflows;

static uint8 u8TasksLookupTable[256];
static uint8 u8NumberOfTasksTraced;

static boolean bTraceTriggered = cFalse;

static uint16 u16TraceEntries = 0;

//==============================================================================
// CONSTANT PRIVATE DATA
//==============================================================================

static const tCpuTraceEntry* pTraceAbsStart = &(TraceBuffer[0]);
static const tCpuTraceEntry* pTraceAbsEnd = &(TraceBuffer[cMaxTraceBuffer - 1]);

//==============================================================================
// PRIVATE FUNCTIONS
//==============================================================================

static void NextTraceEntry(void)
{
    if (pTraceUnderAnalysis != pTraceEnd)
    {
        pTraceUnderAnalysis++;
        if (pTraceUnderAnalysis > (tCpuTraceEntry*)pTraceAbsEnd)
        {
            pTraceUnderAnalysis = (tCpuTraceEntry*)pTraceAbsStart;
        }
    }
}

static void PeriodStatistics(const uint8 u8TaskIdP, const tTimeStamp TimestampP,
                               const uint8 u8OverflowNumP)
{
    uint32 u32Period;
    uint16 u16OverflowDiff;
    tTaskMetrics* pTaskMetrics;

    RI_LocalAssert(u8TaskIdP < cu8EmptyTaskSlot);

    if (u8TasksLookupTable[u8TaskIdP] == cu8EmptyTaskSlot)
    {
        //new task to be logged for statistics...

        //mark task slot as used...
        u8TasksLookupTable[u8TaskIdP] = u8NumberOfTasksTraced;

        pTaskMetrics = &(TaskMetrics[u8NumberOfTasksTraced]);
        pTaskMetrics->u8TaskId = u8TaskIdP;

        u8NumberOfTasksTraced++;
    }
    else
    {
        //task already has statistics history...

        pTaskMetrics = &(TaskMetrics[u8TasksLookupTable[u8TaskIdP]]);

        RI_LocalAssert(u8TaskIdP == pTaskMetrics->u8TaskId);

        if (u8OverflowNumP >= pTaskMetrics->u8LastOverflowOccurrence)
        {
            u16OverflowDiff = (uint16)0;
        }
        else
        {
            u16OverflowDiff = (uint16)256;
        }

        u16OverflowDiff += (uint16)u8OverflowNumP;
        u16OverflowDiff -= (uint16)pTaskMetrics->u8LastOverflowOccurrence;

#ifdef INCREMENTING_uC_TIMER
        if (TimestampP < pTaskMetrics->LastTimestampOccurrence)
        {
            if (u16OverflowDiff > (uint16)0)
            {
                u16OverflowDiff--;
            }

            u32Period = (uint32)u16OverflowDiff << cTimestampBase;
            u32Period += (cu32TimerRange + (uint32)TimestampP) - (uint32)pTaskMetrics->LastTimestampOccurrence;
        }
        else
        {
            u32Period = (uint32)u16OverflowDiff << cTimestampBase;
            u32Period += (uint32)TimestampP - (uint32)pTaskMetrics->LastTimestampOccurrence;
        }
#else
        if (TimestampP > pTaskMetrics->LastTimestampOccurrence)
        {
            if (u16OverflowDiff > (uint16)0)
            {
                u16OverflowDiff--;
            }

            u32Period = (uint32)u16OverflowDiff << cTimestampBase;
            u32Period += (cu32TimerRange + (uint32)pTaskMetrics->LastTimestampOccurrence) - (uint32)TimestampP;
        }
        else
        {
            u32Period = (uint32)u16OverflowDiff << cTimestampBase;
            u32Period += (uint32)(pTaskMetrics->LastTimestampOccurrence - TimestampP);
        }
#endif

        if (u32Period < pTaskMetrics->u32MinCallPeriod)
        {
            pTaskMetrics->u32MinCallPeriod = u32Period;
        }

        if (u32Period > pTaskMetrics->u32MaxCallPeriod)
        {
            pTaskMetrics->u32MaxCallPeriod = u32Period;
        }

        if (pTaskMetrics->u32AvgCallPeriod == (uint32)-1)
        {
            pTaskMetrics->u32AvgCallPeriod = u32Period;
        }
        else
        {
            pTaskMetrics->u32AvgCallPeriod =
                (uint32)((pTaskMetrics->u32AvgCallPeriod + u32Period) >> 1);
        }
    }

    pTaskMetrics->LastTimestampOccurrence = TimestampP;
    pTaskMetrics->u8LastOverflowOccurrence = u8OverflowNumP;
}

static void DurationStatistics(const uint8 u8TaskIdP, const uint32 u32DurationP)
{
    tTaskMetrics* pTaskMetrics;

    RI_LocalAssert( (u8TaskIdP < cu8EmptyTaskSlot) &&
                    (u8TasksLookupTable[u8TaskIdP] != cu8EmptyTaskSlot) );

    pTaskMetrics = &(TaskMetrics[u8TasksLookupTable[u8TaskIdP]]);

    if (u32DurationP < pTaskMetrics->u32MinExecutionTime)
    {
        pTaskMetrics->u32MinExecutionTime = u32DurationP;
    }

    if (u32DurationP > pTaskMetrics->u32MaxExecutionTime)
    {
        pTaskMetrics->u32MaxExecutionTime = u32DurationP;
    }

    //check for overflow...
    if ((pTaskMetrics->u32TotalExecutionTime + u32DurationP) >= pTaskMetrics->u32TotalExecutionTime)
    {
        pTaskMetrics->u32TotalExecutionTime += (uint32)u32DurationP;
        pTaskMetrics->u32Executions++;
    }
    else
    {
        RI_LocalAssert(cFalse);
    }
}

//------------------------------------------------------------------------------
// DESCRIPTION:         Recursive analysis of trace
//
// PARAMETERS:          None
//
// RETURN VALUE:        Total time spent in current task/interrupt (including
//                      nested tasks/interrupts)
//------------------------------------------------------------------------------
static uint32 AnalyseTrace(void)
{
    uint32 u32TimePreemptedL = 0;
    uint32 u32TimeTotalL;
    tTimeStamp StartTimestampL;
    uint8 u8TaskIdL;

    u8TaskIdL = pTraceUnderAnalysis->u8TaskId;
    StartTimestampL = pTraceUnderAnalysis->Timestamp;

    PeriodStatistics(u8TaskIdL, StartTimestampL, pTraceUnderAnalysis->u8Overflow);

    NextTraceEntry();

    while ( (pTraceUnderAnalysis != pTraceEnd) && (pTraceUnderAnalysis->u8TaskId != cu8ExitHandle) )
    {
        u32TimePreemptedL += AnalyseTrace();

        NextTraceEntry();
    }

    RI_LocalAssert( !((pTraceUnderAnalysis == pTraceEnd) && (pTraceUnderAnalysis->u8TaskId != cu8ExitHandle)) );

#ifdef INCREMENTING_uC_TIMER
    if (pTraceUnderAnalysis->Timestamp >= StartTimestampL)
    {
        u32TimeTotalL = (uint32)pTraceUnderAnalysis->Timestamp - (uint32)StartTimestampL;
    }
    else
    {
        //handle timer overflow...
        u32TimeTotalL = (uint32)((cu32TimerRange + (uint32)pTraceUnderAnalysis->Timestamp) - (uint32)StartTimestampL);
    }
#else //INCREMENTING_uC_TIMER
    if (StartTimestampL >= pTraceUnderAnalysis->Timestamp)
    {
        u32TimeTotalL = (uint32)StartTimestampL - (uint32)pTraceUnderAnalysis->Timestamp;
    }
    else
    {
        //handle timer overflow...
        u32TimeTotalL = (uint32)((cu32TimerRange + (uint32)StartTimestampL) - (uint32)pTraceUnderAnalysis->Timestamp);
    }
#endif //INCREMENTING_uC_TIMER

    RI_LocalAssert(u32TimeTotalL >= u32TimePreemptedL);

    DurationStatistics(u8TaskIdL, (uint32)(u32TimeTotalL - u32TimePreemptedL));

    return u32TimeTotalL;
}

//==============================================================================
// PUBLIC FUNCTIONS
//==============================================================================

//------------------------------------------------------------------------------
// DESCRIPTION:         Component initialization
//
// PARAMETERS:          None
//
// RETURN VALUE:        standard result codes apply
//------------------------------------------------------------------------------
Std_ReturnType SRV_CpuMetrics_Init(void)
{
    uint8 u8TaskIndexLndex;

    bTraceTriggered = cFalse;

    u16TraceEntries = 0;

    u32TraceTotalTime = 0;
    u16TimerOverflows = 0;

    u8NumberOfTasksTraced = 0;
    //设置为0XFF表示当前没有被占用
    LIB_Mem_MemSet(u8TasksLookupTable, cu8EmptyTaskSlot, sizeof(u8TasksLookupTable));

    LIB_Mem_MemSet(TaskMetrics, 0, sizeof(TaskMetrics));
    for (u8TaskIndexLndex = 0; u8TaskIndexLndex < cu8TasksNumberInSystem; u8TaskIndexLndex++)
    {
        TaskMetrics[u8TaskIndexLndex].u32MinCallPeriod = (uint32)-1;
        TaskMetrics[u8TaskIndexLndex].u32MaxCallPeriod = (uint32)0;
        TaskMetrics[u8TaskIndexLndex].u32MinExecutionTime = (uint32)-1;
        TaskMetrics[u8TaskIndexLndex].u32MaxExecutionTime = (uint32)0;
        TaskMetrics[u8TaskIndexLndex].u32AvgCallPeriod = (uint32)-1;
    }

    //将当前要分析的记录指针指向队列开头
    pTraceUnderCollection = (tCpuTraceEntry*)pTraceAbsStart;
    pTraceUnderAnalysis = (tCpuTraceEntry*)pTraceAbsEnd;

    pTraceStart = pTraceUnderCollection;
    pTraceEnd = NULL;

    return S_OK;
}

//------------------------------------------------------------------------------
// DESCRIPTION:         Used to execute the main functionality of the component.
//                      The task call is done from the OS/System StateManager.
//                      The scheduling mechanism is defined by the OS
//                      configuration dependent on the needs of
//                      the individual components.
//
// PARAMETERS:          None
//
// RETURN VALUE:        None
//------------------------------------------------------------------------------
void SRV_CpuMetrics_Task(void)
{
    uint16 u16CritSection;

    if (bTraceTriggered != cFalse)
    {
#if cProcessingThreshold > 0
        if (u16TraceEntries >= (uint16)cProcessingThreshold )
#endif
        {
            RI_EnterCriticalSection(&u16CritSection);

            u16TraceEntries = (uint16)0;

            pTraceUnderAnalysis = pTraceStart;

            pTraceStart = pTraceUnderCollection;
            if (pTraceUnderCollection > (tCpuTraceEntry*)pTraceAbsStart)
            {
                pTraceEnd = pTraceUnderCollection - 1;
            }
            else
            {
                pTraceEnd = (tCpuTraceEntry*)pTraceAbsEnd;
            }
            RI_LeaveCriticalSection(u16CritSection);

            SRV_CpuMetrics_LogTrace(cu8TraceHandle);
            while (pTraceUnderAnalysis != pTraceEnd)
            {
                u32TraceTotalTime += AnalyseTrace();

                NextTraceEntry();

                RI_ScheduleSystemTasks();
            }
            SRV_CpuMetrics_LogTrace(cu8ExitHandle);
        }
    }
    else
    {
        bTraceTriggered = RI_TraceAuthorized();
    }
}

//------------------------------------------------------------------------------
// DESCRIPTION:         Trace logging. It's called upon entry & exit of each
//                      interrupt or task
//
// PARAMETERS:          u8TaskIdP - task Id to be traced; 0xFF - end marker
//
// RETURN VALUE:        standard result codes apply
//------------------------------------------------------------------------------
Std_ReturnType SRV_CpuMetrics_LogTrace(const uint8 u8TaskIdP)
{
    uint16 u16CritSection;
    tTimeStamp Timestamp;

    if (bTraceTriggered != cFalse)
    {
        RI_EnterCriticalSection(&u16CritSection);

        Timestamp = RI_GetTimerTimestamp();

        if (RI_GetTimerOverflow() != 0)
        {
            RI_ClearTimerOverflow();
            u16TimerOverflows++;

            //in case of overflow read again the timestamp. it is necessary
            //in order to avoid inconsistency if 0 is read (in case of decrementing
            //timer) and just after an overflow occurs
            Timestamp = RI_GetTimerTimestamp();
        }

        //check for cyclic buffer full...
        if (pTraceUnderCollection == pTraceUnderAnalysis)
        {
            //yes -> trigger assert...
            RI_LocalAssert(cFalse);
        }

        //log the trace entry...
        pTraceUnderCollection->Timestamp = Timestamp;
        pTraceUnderCollection->u8TaskId = u8TaskIdP;
        pTraceUnderCollection->u8Overflow = (uint8)u16TimerOverflows;

        //find place for next entry to be logged...
        if (pTraceUnderCollection < (tCpuTraceEntry*)pTraceAbsEnd)
        {
            //如果没有到达结尾，转向下一条记录
            pTraceUnderCollection++;
        }
        else
        {
            //如果到达结尾，那就从头开始，因为总数量有限，所以只能记录固定个数的任务和中断的记录。
            pTraceUnderCollection = (tCpuTraceEntry*)pTraceAbsStart;
        }

        //update total number of entries logged...
        u16TraceEntries++;

        RI_LeaveCriticalSection(u16CritSection);

        return S_OK;
    }

    return S_FALSE;
}

//------------------------------------------------------------------------------
// DESCRIPTION:         Get the list of traced runables (tasks, interrupts, etc.)
//
// PARAMETERS:          pu8ListP - buffer to fill the list
//                      u8SizeP - size of the buffer
//
// RETURN VALUE:        standard result codes apply
//------------------------------------------------------------------------------
Std_ReturnType SRV_CpuMetrics_GetTracedRunablesList(uint8* pu8ListP, const uint8 u8SizeP)
{
    Std_ReturnType ResultL = S_OK;
    uint8 u8TaskIndexL;
    uint8 u8ListIndexL;

    if ( (pu8ListP != NULL) && (u8SizeP > 0) )
    {
        u8ListIndexL = 1;

        for (u8TaskIndexL = 0; (u8TaskIndexL <= cu8TraceHandle) && (u8ListIndexL < u8SizeP); u8TaskIndexL++)
        {
            if (u8TasksLookupTable[u8TaskIndexL] != cu8EmptyTaskSlot)
            {
                pu8ListP[u8ListIndexL++] = u8TaskIndexL;
            }
        }

        if (u8ListIndexL >= u8SizeP)
        {
            ResultL = E_FAIL;
        }
        else
        {
            pu8ListP[0] = u8ListIndexL;
        }
    }
    else
    {
        ResultL = E_FAIL;
    }

    return ResultL;
}

//------------------------------------------------------------------------------
// DESCRIPTION:         Get metrics for a runable
//
// PARAMETERS:          u8IdP - runable id [0..254]
//                      pu8BufferP - buffer to store the metrics
//                      u8SizeP - size of the buffer
//
// RETURN VALUE:        standard result codes apply
//------------------------------------------------------------------------------
Std_ReturnType SRV_CpuMetrics_GetRunableMetrics(const uint8 u8IdP, uint8* pu8BufferP,
                                                const uint8 u8SizeP)
{
    Std_ReturnType ResultL = S_OK;

    if ( (pu8BufferP != NULL) &&
         (u8SizeP >= (sizeof(tTaskMetrics) + sizeof(u32TraceTotalTime) + 1)) &&
         (u8IdP <= cu8TraceHandle) )
    {
        if (u8TasksLookupTable[u8IdP] != cu8EmptyTaskSlot)
        {
            LIB_Mem_MemCpy(&(pu8BufferP[1 + sizeof(u32TraceTotalTime)]),
                           &(TaskMetrics[u8TasksLookupTable[u8IdP]]),
                           sizeof(tTaskMetrics));

            *((uint32*)&(pu8BufferP[1])) = u32TraceTotalTime;

            pu8BufferP[0] = sizeof(tTaskMetrics) + sizeof(u32TraceTotalTime);
        }
        else
        {
            ResultL = E_FAIL;
        }
    }
    else
    {
        ResultL = E_FAIL;
    }

    return ResultL;
}


#endif //TRACE_CPU_ACTIVE

#ifdef _QAC_
//QACJ 0862: adimiten: Include of all headers is required by
//                     SWA component template
#endif
