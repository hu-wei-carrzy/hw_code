

/*-------------------------------------------------------------------------
  Includes non re entry
  -------------------------------------------------------------------------*/
#ifndef I_LDB_TOS_H
#define I_LDB_TOS_H (1)

#if defined(__cplusplus)
#define extern extern "C"
#endif

/*-------------------------------------------------------------------------
  Included files to resolve specific definitions in this file

  #include <system_file_name.h>
  #include "project_file_name.h"

#ifndef COMPILATION_NATIVE	// Target specific file name
  #include <system_file_name.h>
  #include "project_file_name.h"
#endif
  -------------------------------------------------------------------------*/
#include "ARCH_CFG.h"

#ifdef cHeadIncludeType_Directly
#include "deftypes.h"
#include "TOSPARAM.H"

#ifdef TOS_PREEMPTIVE
#include "tos_ord.h"
#endif

#ifdef TOS_PERF_CNT_ENABLE
#include "TOS_PerfCnt.h"
#endif


#else

#include ".\..\..\LIB\LIB_API\deftypes.h"
#include ".\..\..\TOS\TOS_CONFIG\TOSPARAM.H"

#ifdef TOS_PREEMPTIVE
#include ".\..\..\TOS\TOS_ORD\tos_ord.h"
#endif

#ifdef TOS_PERF_CNT_ENABLE
#include ".\..\..\TOS\TOS_PERFCNT\TOS_PerfCnt.h"
#endif
#endif


/*-------------------------------------------------------------------------
  Constant data

  #define cCMPConstantName   ((tType) ConstantValue)
  -------------------------------------------------------------------------*/
/*
#define cLDBCPUTraceIdleTask    10
#define cLDBCPUTraceMainLoop    0
#define cLDBCPUTraceScheduler   1
#define cLDBCPUTraceIdleState   2

#if defined(TRACE_CPU_ACTIVE) || (defined(COMPILATION_NATIVE) && !defined(UTEST))
#define cu8CPUTraceExitHandle           ((U8) 255)
#endif 
*/

/*-------------------------------------------------------------------------
  Exported Macro

  #define mCMPMacroName   (MacroDefinition)
  -------------------------------------------------------------------------*/ 
//----- Interrupt routines -----
#ifdef TOS_PREEMPTIVE
  #define mLDBEnterInterrupt(Handle)  mLDBEnterCPUTrace(Handle);  \
                                      TOSEnterISR()

  #define mLDBLeaveInterrupt()        mLDBExitCPUTrace();         \
                                      TOSLeaveISR()
#else
  #define mLDBEnterInterrupt(Handle)  mLDBEnterCPUTrace(Handle)
  #define mLDBLeaveInterrupt()        mLDBExitCPUTrace()
#endif

//----- Trace CPU -----
// You can trace the CPU load by define TRACE_CPU_ACTIVE in your project compilation options.
#if defined(TRACE_CPU_ACTIVE) || (defined(COMPILATION_NATIVE) && !defined(UTEST))

#include ".\..\..\LAP\LAP_CPULOAD\SRV_CpuMetrics_OutputMacros.h"

/*
// Measure Trace execution time
#define mLDBInitCPUTrace(Handle)                                               \
    SRV_CpuMetrics_Init()

#define mLDBEnterCPUTrace(Handle)                                              \
    SRV_CpuMetrics_LogTrace(Handle)

#define mLDBExitCPUTrace()                                                     \
    SRV_CpuMetrics_LogTrace(cu8CPUTraceExitHandle)
    */

#elif defined(TOS_PERF_CNT_ENABLE)
  #define mLDBInitCPUTrace(Handle) 

  #define mLDBEnterCPUTrace(Handle) mTOSPerfCntEnter(Handle)

  #define mLDBExitCPUTrace()        mTOSPerfCntExit()

#elif defined(_QAC_)
extern void NOP(void);
  #define mLDBInitCPUTrace(Handle)    NOP()
  #define mLDBEnterCPUTrace(Handle)   NOP()
  #define mLDBExitCPUTrace()          NOP()
#else
  #define mLDBInitCPUTrace(Handle)
  #define mLDBEnterCPUTrace(Handle)
  #define mLDBExitCPUTrace()
#endif

/*-------------------------------------------------------------------------
  Exported type

  struct  sCMPStructureName { ... };
  union   uCMPUnionName { ... };
  enum    eCMPEnumerationName { ... };
  typedef Expression tCMPTypeName;

  -------------------------------------------------------------------------*/
// You can trace the CPU load by define TRACE_CPU_ACTIVE in your project compilation options.
#ifdef TRACE_CPU_ACTIVE
// We use a type with size of data registers of the micro
typedef REG tLDBHandleCPU;
#endif

/*-------------------------------------------------------------------------
  Exported data

  extern  tType   CMPVariableName;
  extern  tType*  pCMPVariableName; 
  -------------------------------------------------------------------------*/ 
// You can trace the CPU load by define TRACE_CPU_ACTIVE in your project compilation options.
#ifdef TRACE_CPU_ACTIVE
// This data must be defined by LDB
extern volatile tLDBHandleCPU LDBHandleCPU;
#endif

/*-------------------------------------------------------------------------
  Constant exported data

  extern const tType  CMPVariableName;
  -------------------------------------------------------------------------*/ 

/*-------------------------------------------------------------------------
  Exported functions

  extern tReturnType CMPFunctionName(tTypeArgument1 ArgumentName1, ... );
  -------------------------------------------------------------------------*/ 
#if defined(__cplusplus)
  #undef extern //extern "C"
#endif

/*-------------------------------------------------------------------------
  End of includes non re entry
  -------------------------------------------------------------------------*/
#endif /* I_LDB_TOS_H */

