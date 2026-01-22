#include   ".\..\SRV_CpuMetrics_TypeInclude.h"
#include   ".\..\SRV_CpuMetrics_OutputMacros.h"

#include "LDBInclude.h"


#ifdef TRACE_CPU_ACTIVE

#define cCPULoadTimerSource  BT28_RT
#define RLT_RELOAD_VALUE     64999 // unit=0.2us, overflow time=65000*0.2 =13ms

/*****************************************************************************/
/* Function implementation - global ('extern') and local ('static')          */
/*****************************************************************************/



//==============================================================================
// DESCRIPTION : Real time interrupt
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : Refer to Detailed Design Document
//==============================================================================

void LAPCpuLoadTimerInit()
{
    // RLT - configuration
    //From CLK_LCP0A=20MHz
    //20MHz/4=5MHz-->0.2Us
    //NOTE:not used interrupt
	stc_rlt_config_t stcRltConfig = { .enPrescaler            = RltDiv4,                   // Clock further divided by 4
									  .enOperationMode        = RltSoftwareTriggerOnly,     // Trigger with Software
									  .b32bitTimerModeEnable  = FALSE,                      // 16bit mode
									  .bOutputPolarityInverse = FALSE,                      // normal polarity
									  .bOneshotEnable         = FALSE,                      // run cyclic
									  .bGateInputEnable       = FALSE,                      // trigger input
									  .pfnTriggerCallback     = 0,         // use callback for interrupt
									  .pfnUnderflowCallback   = 0};      // use callback for interrupt

    // Init Timer with above configuration
    Rlt_Init ((stc_btn_rt_t*)&cCPULoadTimerSource, &stcRltConfig);

}

void LAPCpuLoadTimerStart(void)
{
    LAPCpuLoadTimerInit();
	Rlt_Start ((stc_btn_rt_t*)&cCPULoadTimerSource, 0, (uint32_t) RLT_RELOAD_VALUE, TRUE);
}


void LAPCpuLoadTimerStop()
{
    //Rlt_Stop函数本身中已经包含了禁止中断的代码
    Rlt_Stop((stc_btn_rt_t*)&cCPULoadTimerSource);
}



unsigned int LAPCpuLoadReadCounter(void)
{

    unsigned int u32TimerCount = (unsigned int )BT28_RT_TMR;
    return u32TimerCount;
}

unsigned char LAPCpuLoadIsOverFlow()
{
    return (unsigned char)BT28_RT_STC_UDIR;
}


void LAPCpuLoadClearOverFlowFlag()
{
    BT28_RT_STCC_UDIRC = 1;
}


void LAPCpuLoadEnterCriticalSection(void)
{
    __disable_interrupt();
}

void LAPCpuLoadLeaveCriticalSection(void)
{
    __enable_interrupt();
}



//Interrupt Related Function
#define cIntEnterCPUTrace(IntName,IntHandle)             \
void LAPCpuLoad_##IntName##_Int_EnterCPUTrace(void)      \
{                                                        \
    SRV_CpuMetrics_LogTrace(IntHandle);                  \
}                                                        \

#define cIntLeaveCPUTrace(IntName)                       \
void LAPCpuLoad_##IntName##_Int_LeaveCPUTrace(void)      \
{                                                        \
    SRV_CpuMetrics_LogTrace(cu8CPUTraceExitHandle);      \
}                                                        \


//extern void LAPCpuLoad_##IntName##_Int_EnterCPUTrace;
//extern void LAPCpuLoad_##IntName##_Int_LeaveCPUTrace(void);

cIntEnterCPUTrace(CAN0Rx,  100)
cIntLeaveCPUTrace(CAN0Rx)

cIntEnterCPUTrace(CAN1Rx,  101)
cIntLeaveCPUTrace(CAN1Rx)

cIntEnterCPUTrace(RTC,  102)
cIntLeaveCPUTrace(RTC)

//FRT1
cIntEnterCPUTrace(MOTOR,  103)
cIntLeaveCPUTrace(MOTOR)

//Speed
cIntEnterCPUTrace(Speed,  104)
cIntLeaveCPUTrace(Speed)

//Tacho
cIntEnterCPUTrace(Tacho,  105)
cIntLeaveCPUTrace(Tacho)

//CVTTimeout--FRT0
cIntEnterCPUTrace(CVTTimeout,  106)
cIntLeaveCPUTrace(CVTTimeout)

#endif
