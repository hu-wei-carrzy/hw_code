#ifndef I_SRV_CPUMETRICS_TIMERDRIVER_H
#define I_SRV_CPUMETRICS_TIMERDRIVER_H


#include   "SRV_CpuMetrics_TypeInclude.h"

#ifdef TRACE_CPU_ACTIVE
extern void LAPCpuLoadTimerInit();

extern void LAPCpuLoadTimerStart();

extern void LAPCpuLoadTimerStop();



extern unsigned int LAPCpuLoadReadCounter(void);

extern unsigned char LAPCpuLoadIsOverFlow();

extern void LAPCpuLoadClearOverFlowFlag();



extern void LAPCpuLoadEnterCriticalSection(void);

extern void LAPCpuLoadLeaveCriticalSection(void);

#endif



#endif
