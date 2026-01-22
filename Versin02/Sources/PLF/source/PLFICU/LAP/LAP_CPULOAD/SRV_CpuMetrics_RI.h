#ifndef SRV_CpuMetrics_RI_H
#define SRV_CpuMetrics_RI_H

#ifndef _QAC_
//******************************************************************************
// Company:      Johnson Controls Inc.
// -----------------------------------------------------------------------------
// Copyright:    This software is JCI property.
//               Duplication or disclosure without JCI written authorization
//               is prohibited.
// -----------------------------------------------------------------------------
// Project:      Entry Platform
// Language:     ANSI-C
// -----------------------------------------------------------------------------
// Component:    SRV_CpuMetrics - Declaration of required interfaces
//
// -----------------------------------------------------------------------------
// $Date:   May 14 2014 10:01:40  $
// $Archive:   //DI_JMC_N330_IC/archives/1016282/DEV/BUILD/SOURCES/SRV_CpuMetrics_RI.h-arc  $
// $Revision:   1.3  $
// -----------------------------------------------------------------------------
/* $Log:   //DI_JMC_N330_IC/archives/1016282/DEV/BUILD/SOURCES/SRV_CpuMetrics_RI.h-arc  $
 * 
 *    Rev 1.3   May 14 2014 10:01:40   awan1106
 * Cm068492: Step Motor Update from ER
 * 
 *    Rev 1.2   Feb 12 2014 16:35:14   azhao26
 * Cm065183:modify the generated comment error
 * 
 *    Rev 1.1   Feb 12 2014 16:28:52   azhao26
 * Cm065183:add code to implement CPU load test
 * 
 *    Rev 1.0   Feb 12 2014 12:45:12   azhao26
 * Initial revision.
 */ 

 //******************************************************************************
#endif  // #ifndef _QAC_
 
 
#if !((defined UTEST) || (defined _QAC_))
 
#ifdef AUTOSAR_BUILD
 
//==============================================================================
//   BEGIN OF AUTOSAR
//==============================================================================

//TODO: Include the headers of all external components required by your implementation


//TODO: Define your own macros (ones that cannot be generated) to make a mapping
//      between the symbol names used in your implementation to their actual names


//DO NOT remove comments bellow!
//DO NOT edit content between tags! It is automatically generated.
//<BEGIN AUTOSAR MACROS DECLARATION SECTION>

//<END AUTOSAR MACROS DECLARATION SECTION>

//==============================================================================
//   END OF AUTOSAR
//==============================================================================
#else

//==============================================================================
//   BEGIN OF STK
//==============================================================================

//#include "ldb.h"
//#include "dat.h"
#include "SRV_CpuMetrics_Cfg.h"

#if defined(TRACE_CPU_ACTIVE)

//#include "ldb_ioc.h"
//#include "ldb_har.h"

#elif defined(COMPILATION_NATIVE)

#include "tos.h"

#endif

//TODO: Include the headers of all external components required by your implementation

//TODO: Define your own macros (ones that cannot be generated) to make a mapping
//      between the symbol names used in your implementation to their actual names

//DO NOT remove comments bellow!
//DO NOT edit content between tags! It is automatically generated.
//<BEGIN STK MACROS DECLARATION SECTION>

//<END STK MACROS DECLARATION SECTION>

#define RI_TraceAuthorized()    1//mDATRead(U1Bit, MilLampOn, Default)

extern void       TOSSchedule(void);
#define RI_ScheduleSystemTasks()                                               \
    TOSSchedule()

#if defined(TRACE_CPU_ACTIVE)

#ifdef RESET_ON_ERROR
extern void LDBReset(void);
#define RI_LocalAssert(Condition)                                              \
    if ( (Condition) == cFalse ) LDBReset();
#else
#define RI_LocalAssert(Condition)
#endif


extern void LAPCpuLoadEnterCriticalSection(void);
extern void LAPCpuLoadLeaveCriticalSection(void);

#define RI_EnterCriticalSection(CritSection)                                   \
    LAPCpuLoadEnterCriticalSection()
#define RI_LeaveCriticalSection(CritSection)                                   \
    LAPCpuLoadLeaveCriticalSection()

extern unsigned int LAPCpuLoadReadCounter(void);
#define RI_GetTimerTimestamp()                                                 \
    LAPCpuLoadReadCounter()
//mLDBIocReadCounter(cLDBHarCPUTraceTimer)
extern unsigned char LAPCpuLoadIsOverFlow(void);
#define RI_GetTimerOverflow()                                                  \
    LAPCpuLoadIsOverFlow()
//mLDBIocGetIF(cLDBHarCPUTraceTimer)

extern void LAPCpuLoadClearOverFlowFlag();
#define RI_ClearTimerOverflow()                                                \
    LAPCpuLoadClearOverFlowFlag()
//mLDBIocClearIF(cLDBHarCPUTraceTimer)

#elif defined(COMPILATION_NATIVE)

#define RI_LocalAssert(Condition)                                              \
    mLIBassert(Condition)

#define RI_EnterCriticalSection(CritSection)                                   \
    (void)CritSection

#define RI_LeaveCriticalSection(CritSection)                                   \
    (void)CritSection

#define RI_GetTimerTimestamp()                                                 \
    RI_GetCpuTimerValue()

#define RI_GetTimerOverflow()                                                  \
    RI_GetCpuTimerOverflow()

#define RI_ClearTimerOverflow()                                                \
    RI_ClearCpuTimerOverflow()

extern tTimeStamp RI_GetCpuTimerValue(void);
extern uint8 RI_GetCpuTimerOverflow(void);
extern void RI_ClearCpuTimerOverflow(void);

#endif //TRACE_CPU_ACTIVE


//==============================================================================
//   END OF STK
//==============================================================================
#endif //#ifdef AUTOSAR_BUILD

#else //UTEST

#include "basedef.h"

//UTEST or QAC
//==============================================================================
//   BEGIN OF UNIT TEST
//==============================================================================


//TODO: Include the headers of all external components required by your implementation

//TODO: Define your own macros (ones that cannot be generated) to make a mapping
//      between the symbol names used in your implementation to their actual names



//DO NOT remove comments bellow!
//DO NOT edit content between tags! It is generated.
//<BEGIN TYPES DECLARATION>


//<END TYPES DECLARATION>

//DO NOT remove comments bellow!
//DO NOT edit content between tags! It is generated.
//<BEGIN UNIT TEST MACROS DECLARATION SECTION>

//<END UNIT TEST MACROS DECLARATION SECTION>

typedef struct tENVData
{
    //DO NOT remove comments bellow!
    //DO NOT edit content between tags! It is generated.
    //<BEGIN ENVDATA DECLARATION>

    //<END ENVDATA DECLARATION>

    //Define custom environment data if needed
    uint8 u8Dummy;
}sENVData;

extern sENVData ENVData;

extern void ENVDataInit(void);

//==============================================================================
//   END OF UNIT TEST
//==============================================================================
#endif //#ifndef UTEST


#endif // #ifndef APP_Cmp_RI_H
