#ifndef I_SRV_CPUMETRICS_MACROS_H
#define I_SRV_CPUMETRICS_MACROS_H

#include "SRV_CpuMetrics_TypeInclude.h"

#if defined(TRACE_CPU_ACTIVE)
#define cLDBCPUTraceIdleTask    10
#define cLDBCPUTraceMainLoop    0
#define cLDBCPUTraceScheduler   1
#define cLDBCPUTraceIdleState   2

//#if defined(TRACE_CPU_ACTIVE) || (defined(COMPILATION_NATIVE) && !defined(UTEST))
#define cu8CPUTraceExitHandle           ((unsigned char) 255)
//#endif

#endif


#if defined(TRACE_CPU_ACTIVE)
extern Std_ReturnType SRV_CpuMetrics_Init(void);
// Measure Trace execution time
#define mLDBInitCPUTrace(Handle)                                               \
    SRV_CpuMetrics_Init()
	
extern Std_ReturnType SRV_CpuMetrics_LogTrace(const uint8 u8TaskIdP);

#define mLDBEnterCPUTrace(Handle)                                              \
    SRV_CpuMetrics_LogTrace(Handle)

#define mLDBExitCPUTrace()                                                     \
    SRV_CpuMetrics_LogTrace(cu8CPUTraceExitHandle)
#else
#define mLDBInitCPUTrace(Handle)
#define mLDBEnterCPUTrace(Handle)
#define mLDBExitCPUTrace()

#endif

#endif
