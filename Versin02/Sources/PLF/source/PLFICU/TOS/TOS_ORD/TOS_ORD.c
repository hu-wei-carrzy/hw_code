
//------------------------------------------------------------------------------
// Body Identification
//------------------------------------------------------------------------------
#define TOS_ORD "TOS_ORD"

//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//------------------------------------------------------------------------------
#ifdef cHeadIncludeType_Directly
#include "tos_ord.h"
#include "ldb_tos.h"
#include "LDB.h"
#include "LIB.h"
#ifdef TOS_PERF_CNT_ENABLE
 #include "TOS_PerfCnt.h"
#endif

#else
#include "tos_ord.h"
#include ".\..\..\LDB\LDB_API\ldb_tos.h"
#include ".\..\..\LDB\LDB_API\LDB.h"
#include ".\..\..\LIB\LIB_API\LIB.h"

#ifdef TOS_PERF_CNT_ENABLE
 #include ".\..\TOS_PERFCNT\TOS_PerfCnt.h"
#endif

#endif

#if cTOSNbMode >= 2
 #error "This TOS_ORD version do not support TOS mode management"
#endif

//------------------------------------------------------------------------------
// Local constants
//------------------------------------------------------------------------------
// Most prioritary task mask
#define cMaxTaskID    (((tTOSTaskID) 0x01UL) << (cTOSNbTask - ((tTOSTaskID)2UL) ))

//------------------------------------------------------------------------------
// Local macros
//------------------------------------------------------------------------------
#ifndef NO_DYNAMIC_DATA
  #define DATA_TYPE
#else
  #define DATA_TYPE static
//----- Scheduler stack management -----
  #define mClearSchedulerStack()                                         \
    (s8SchedulerStackLevel = ((S8)-1))

// Scheduler stack treat only tSchedulerStack type
  #define mPushToSchedulerStack(Type,Data)                               \
    {                                                                    \
        mLIBassert(sizeof(Type) == sizeof(tTOSTaskID));                  \
        s8SchedulerStackLevel++;                                           \
        mLIBassert(s8SchedulerStackLevel < (S8)(cTOSSchedulerStackSize));  \
        SchedulerStack[s8SchedulerStackLevel] = ((Type)(Data));            \
    }

  #define mPopFromSchedulerStack(Type,Data)                              \
    {                                                                    \
        mLIBassert(s8SchedulerStackLevel >= 0);                            \
        (Data) = ((Type)SchedulerStack[s8SchedulerStackLevel]);            \
        s8SchedulerStackLevel--;                                           \
    }

  #define cTOSSchedulerStackSize (cTOSMaxTaskNumber + cTOSOffsetSchedulerStackSize)
#endif

//------------------------------------------------------------------------------
// Local types
//------------------------------------------------------------------------------
#ifdef NO_DYNAMIC_DATA
typedef tTOSTaskID tSchedulerStack[cTOSSchedulerStackSize];
#endif

// -----------------------------------------------------------------------------
// Local data
//------------------------------------------------------------------------------
// List of ready tasks
#define	ListeTachesPretes    ListOfReadyTasks
static volatile tTOSTaskID ListOfReadyTasks;

//List of all selectable tasks
#define ListeTachesEligibles   ListOfSelectableTasks
static tTOSTaskID ListOfSelectableTasks;

static    BOOL          bSuspFlagOS;
//NOTE:the __istate_t is compiler related

static BOOL    ITStateOS;

#ifdef USE_DISABLE_ALL_INTERRUPTS
static    BOOL          bSuspFlagAll;
static    tTOSItState   ITStateAll;
#endif

#ifdef NO_DYNAMIC_DATA
//QACJ 3218: amanevm: This is the place where statics are defined 
static    tSchedulerStack SchedulerStack;
static    S8              s8SchedulerStackLevel;
#endif

//------------------------------------------------------------------------------
// Constant local data
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Exported data
//------------------------------------------------------------------------------

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
void TOSActivateTask(const tTOSTaskID TaskId)
{
    TOSSuspendOSInterrupts();
    ListOfReadyTasks |= TaskId;
    TOSResumeOSInterrupts();
}

//==============================================================================
// DESCRIPTION:         See component header file
//==============================================================================
void TOSOrdSuspendTask(const tTOSTaskID TaskId)
{
    ListOfReadyTasks &= (tTOSTaskID)(~TaskId);
}

//==============================================================================
// DESCRIPTION:         See component header file
//==============================================================================
void TOSSuspendOSInterrupts(void)
{
	//**********this function is　MCU　related.****************
    TOSInternalGetAndDisableOSInterrupts(ITStateOS);
    // This assert will fail if you have called twice TOSSuspendOSInterrupts()
    //QACJ 3326: amanevm: operation can't be split. This is an assert. Nothing has to be done in Release
    //QACJ 3416: amanevm: operation can't be split. This is an assert. Nothing has to be done in Release
    mLIBassert((bSuspFlagOS = !bSuspFlagOS) == cTrue);
}

//==============================================================================
// DESCRIPTION:         See component header file
//==============================================================================
void TOSResumeOSInterrupts(void)
{
	//**********this function is　MCU　related.****************
    // This assert will fail if you have called twice TOSResumeOSInterrupts()
    //QACJ 3326: amanevm: operation can't be split. This is an assert. Nothing has to be done in Release
    //QACJ 3416: amanevm: operation can't be split. This is an assert. Nothing has to be done in Release
    mLIBassert((bSuspFlagOS = !bSuspFlagOS) == cFalse);
    TOSInternalSetOSInterruptsState(ITStateOS);

    ITStateOS = ITStateOS;
}

#ifdef USE_DISABLE_ALL_INTERRUPTS
//==============================================================================
// DESCRIPTION:         See component header file
//==============================================================================
void TOSSuspendAllInterrupts(void)
{
    TOSInternalGetAndDisableAllInterrupts(ITStateAll);
    // This assert will fail if you have called twice TOSSuspendAllInterrupts()
    mLIBassert((bSuspFlagAll = !bSuspFlagAll) == cTrue);
}

//==============================================================================
// DESCRIPTION:         See component header file
//==============================================================================
void TOSResumeAllInterrupts(void)
{
    // This assert fail if you have called twice TOSResumeAllInterrupts()
    mLIBassert((bSuspFlagAll = !bSuspFlagAll) == cFalse);
    TOSInternalSetAllInterruptsState(ITStateAll);
}
#endif

//==============================================================================
// DESCRIPTION:         See component header file
//==============================================================================
void TOSShutdown(const U16 u16ErrorCode)
{
    TOSSuspendOSInterrupts();
    // In case of fatal error LAPShutdownHook() must provoke a reset.
    LAPShutdownHook(u16ErrorCode);
    TOSResumeOSInterrupts();
}

//==============================================================================
// DESCRIPTION:         See component header file
//==============================================================================

extern void LDBRefreshWatchDog(void);
extern void BusoffRecoverClose(void);

 volatile   static U32 u32CPSR = 0;
void TOSInternalStart(void)
{
    bSuspFlagOS                      = cFalse;
    

#ifdef USE_DISABLE_ALL_INTERRUPTS
    bSuspFlagAll                     = cFalse;
	//CCOV: amanevm: bSuspFlagAll is used in asserts. Following line is to avoid warning in release
    //where asserts are expanded to nothing.
    //QACJ 3356: amanevm: added only to avoid warnings in Release
    //QACJ 3359: amanevm: added only to avoid warnings in Release
    //QACJ 3201: amanevm: added only to avoid warnings in Release
	if(bSuspFlagAll != cFalse){} //to avoid a warning in release mode
#endif
	//CCOV: amanevm: bSuspFlagOS is used in asserts. Following line is to avoid warning in release
    //where asserts are expanded to nothing.
    //QACJ 3356: amanevm: added only to avoid warnings in Release
    //QACJ 3359: amanevm: added only to avoid warnings in Release
    //QACJ 3201: amanevm: added only to avoid warnings in Release
    if(bSuspFlagOS != cFalse){} //to avoid a warning in release mode

    ListOfReadyTasks     = 0;
    ListOfSelectableTasks  = (tTOSTaskID)(((cMaxTaskID-((tTOSTaskID)1U))<< ((tTOSTaskID)1U)) + ((tTOSTaskID)1U));
    
#ifdef NO_DYNAMIC_DATA
    mClearSchedulerStack();
#endif
    
    // Application initialization (TOS, LAP, DAT and LDB)
    LAPStartupHook();


    // Interrupts authorization
    TOSEnableOSInterrupts();

    mLDBInitCPUTrace(cLDBCPUTraceMainLoop);

    //Infinite loop
    // Polyspace justification: amanevm: This is main loop of program.
    for(;;)
    {

        // Idle task execution
        {
#ifdef TOS_NO_IDLE_TASK_TRACE
            // before the idle task execution a scheduling is made too
            // execute the pending task
            TOSSchedule();
            // Polyspace justification: amanevm: 
            // There is at least one task - idle task. TOSTaskList is initialized with valid pointers at link time
            TOSTaskList[0]();
#else
    #ifndef	TOS_NO_TOSSchedule_TRACE
            // before the idle task execution a scheduling is made too
            // execute the pending task
            TOSSchedule();
    #endif
            mLDBEnterCPUTrace(cLDBCPUTraceIdleTask);
    #ifdef	TOS_NO_TOSSchedule_TRACE
            // before the idle task execution a scheduling is made too
            // execute the pending task
            TOSSchedule();
    #endif
            // Polyspace justification: amanevm: 
            // There is at least one task - idle task. TOSTaskList is initialized with valid pointers at link time
            TOSTaskList[0]();

            //u32CPSR = __get_CPSR();

           
            LDBRefreshWatchDog();
            mLDBExitCPUTrace();
#ifdef DEBUG

			BusoffRecoverClose();
#endif
#if defined(TRACE_CPU_ACTIVE) || (defined(COMPILATION_NATIVE) && !defined(UTEST))
            SRV_CpuMetrics_Task();
#endif //defined(TRACE_CPU_ACTIVE) || (defined(COMPILATION_NATIVE) && !defined(UTEST))
#endif
        }
    }
}

//==============================================================================
// DESCRIPTION:         See component header file
//==============================================================================
void TOSSchedule(void)
{
    #ifndef	TOS_NO_TOSSchedule_TRACE
	static U8 su8IdleTaskCounter;

    mLDBEnterCPUTrace(cLDBCPUTraceScheduler);
    #endif
    while( (ListOfReadyTasks & ListOfSelectableTasks) != ((tTOSTaskID)0U) )
    {

        //QACJ 3223: amanevm: The idea is to have this variable static
        DATA_TYPE tTOSTaskID PreviousListOfSelectableTasks;
        
		U8 u8TaskID;

        //QACJ 3223: amanevm: The idea is to have this variable static
        DATA_TYPE tTOSTaskID          TOSTaskID;
        // save selectable task list
        PreviousListOfSelectableTasks = ListOfSelectableTasks;

        // search most priority pending task
        
		u8TaskID = cTOSNbTask - (U8)1U;

        TOSTaskID = cMaxTaskID;

        while( (TOSTaskID & ListOfReadyTasks) == ((tTOSTaskID)0U) )
        {
			u8TaskID--;

            TOSTaskID >>= 1U;
        }

        // Suppress task from the pending task list
        TOSSuspendOSInterrupts();
        ListOfReadyTasks -=  TOSTaskID;
        TOSResumeOSInterrupts();

        // update selectable task list
        TOSTaskID <<= 1U;
        TOSTaskID --;
        ListOfSelectableTasks = (tTOSTaskID)~TOSTaskID;

#ifdef NO_DYNAMIC_DATA      // Save context before call new task
        mPushToSchedulerStack(tTOSTaskID,PreviousListOfSelectableTasks)
#endif
        // task function calling
        {
			mLDBEnterCPUTrace((U8)(u8TaskID + cLDBCPUTraceIdleTask));

			// Polyspace justification: amanevm:
            // u8TaskID is initialiazed with cTOSNbTask - 1 - index of last element in TOSTaskList.
            // After that it is only decreased. cTOSNbTask can't become lower then 0 because 
            // ListOfReadyTasks is different from 0 which means there is at least one 1 at bit 0 to  cTOSNbTask - 1
            // TOSTaskList is initialized with valid function pointers at link time
            (TOSTaskList[u8TaskID])();

            mLDBExitCPUTrace();
        }
#ifdef NO_DYNAMIC_DATA
        // Restore context
        mPopFromSchedulerStack(tTOSTaskID,PreviousListOfSelectableTasks)
#endif

        // restore selectable task list
        ListOfSelectableTasks = PreviousListOfSelectableTasks;


        /*如果一直有任务，则隔一段时间执行一次DATAnaSwitchScan，防止高速任务一直得不到执行而出现异常，比如AD通道切换，
         * 目前这个值设定成5,太小可能导致占用CPU过多，太多可能执行周期过长,这里不能调IdleTask，因为IdleTask还会调用这个函数*/
/*        su8IdleTaskCounter ++;
        if (su8IdleTaskCounter >= 1)
        {
        	su8IdleTaskCounter = 0;
extern void DATAnaSwitchScan(void);
        	DATAnaSwitchScan();
        }*/
    }
    #ifndef	TOS_NO_TOSSchedule_TRACE
    mLDBExitCPUTrace();
    #endif
}

//==============================================================================
// DESCRIPTION:         See component header file
//==============================================================================
void TOSHalt(void)
{
    //Use intermediate variable for QAC due to volatile type
    tTOSTaskID TaskList;

    //Disable interrupt using TOS service
    TOSDisableOSInterrupts();

    #ifndef TOS_NO_IDLE_MODE_TRACE
    mLDBEnterCPUTrace(cLDBCPUTraceIdleState);
    #endif

    TaskList = ListOfReadyTasks;

    while(TaskList == (tTOSTaskID)0UL)
    {
        //No pending task: go to halt mode
        LDBWaitForCallBack();

        //IT are executed
        TOSToggleOSInterrupts();

        //Re evaluate TaskList, because the interrupt can have activated a task
        TaskList = ListOfReadyTasks;
    }
    #ifndef TOS_NO_IDLE_MODE_TRACE
    mLDBExitCPUTrace();
    #endif

    //Enable interrupt using TOS service
    TOSEnableOSInterrupts();
}
