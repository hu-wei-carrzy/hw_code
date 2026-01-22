

//==============================================================================
// BODY IDENTIFICATION
//==============================================================================
#define SRV_CpuMetrics_RI_C   "SRV_CpuMetrics_RI_C"

//==============================================================================
// INCLUDED FILES
//==============================================================================
#include ".\INCLUDE\basedef.h"
#include "SRV_CpuMetrics_Cfg.h"
#include "SRV_CpuMetrics_RI.h"

//==============================================================================
// PRIVATE MACROS
//==============================================================================

//==============================================================================
// PRIVATE TYPES
//==============================================================================

//==============================================================================
// PRIVATE DATA
//==============================================================================

//==============================================================================
// CONSTANT PRIVATE DATA
//==============================================================================

#define cTimerMaxValue              cTimerMask

//==============================================================================
// FORWARD DECLARATIONS OF PRIVATE FUNCTIONS
//==============================================================================

//==============================================================================
// PRIVATE FUNCTIONS
//==============================================================================

//==============================================================================
// PUBLIC DATA
//==============================================================================
#ifdef AUTOSAR_BUILD
//DO NOT remove comments bellow!
//DO NOT edit content between tags! It is generated.
//<BEGIN AS ADAPTER IMPLEMENTATION SECTION>

//<END AS ADAPTER IMPLEMENTATION SECTION>

static uint8 u8Overflow = 0;

tTimeStamp RI_GetCpuTimerValue(void)
{
    static boolean bFirstPass = cTrue;

    tTimeStamp TimerValue;

#ifdef INCREMENTING_uC_TIMER
    static tTimeStamp TimerValuePrev = (tTimeStamp)0;
#else
    static tTimeStamp TimerValuePrev = (tTimeStamp)cTimerMaxValue;
#endif

    TimerValue = (tTimeStamp)((OS_HwtRead(OS_counter[SystemTimer].hwt) / (cOSTMCLOCK / 1000000)) & (uint32)cTimerMask);

    if (bFirstPass != cFalse)
    {
        TimerValuePrev = TimerValue;
        bFirstPass = cFalse;
    }
    
#ifdef INCREMENTING_uC_TIMER
    if (TimerValuePrev > TimerValue)
    {
        u8Overflow = 1;
    }
#else
    if (TimerValuePrev < TimerValue)
    {
        u8Overflow = 1;
    }
#endif

    TimerValuePrev = TimerValue;

    return TimerValue;
}

uint8 RI_GetCpuTimerOverflow(void)
{
    return u8Overflow;
}

void RI_ClearCpuTimerOverflow(void)
{
    u8Overflow = 0;
}

#endif

//==============================================================================
// PUBLIC FUNCTIONS
//==============================================================================

#ifdef UTEST

sENVData ENVData;

void ENVDataInit(void)
{
    //DO NOT remove comments bellow!
    //DO NOT edit content between tags! It is generated.
    //<BEGIN ENVDATA INITIALIZATION>

    //<END ENVDATA INITIALIZATION>

    //Write custom initialization if needed
}

//DO NOT remove comments bellow!
//DO NOT edit content between tags! Content is generated.
//<BEGIN UTEST MACROS IMPLEMENTATION>

//<END UTEST MACROS IMPLEMENTATION>

#endif //#ifdef UTEST

#ifdef COMPILATION_NATIVE

static uint8 u8Overflow = 0;

tTimeStamp RI_GetCpuTimerValue(void)
{
    tMsg Msg;
    tTimeStamp TimerValue;
    uint16 u16SystemTimerValue;

    static boolean bFirstPass = cTrue;

#ifdef INCREMENTING_uC_TIMER
    static tTimeStamp TimerValuePrev = (tTimeStamp)0;
#else
    static tTimeStamp TimerValuePrev = (tTimeStamp)cTimerMaxValue;
#endif

    Msg.Lng = sizeof(u16SystemTimerValue);
    Msg.pBuffer = (U8*)(&u16SystemTimerValue);
    LDBReceiveWithoutAddr(cLDBChannelCpuMetrics, &Msg);

    TimerValue = (tTimeStamp)u16SystemTimerValue & (tTimeStamp)cTimerMask;

    if (bFirstPass != cFalse)
    {
        TimerValuePrev = TimerValue;
        bFirstPass = cFalse;
    }

#ifdef INCREMENTING_uC_TIMER
    if (TimerValuePrev > TimerValue)
    {
        u8Overflow = 1;
    }
#else
    if (TimerValuePrev < TimerValue)
    {
        u8Overflow = 1;
    }
#endif
    TimerValuePrev = TimerValue;

    return TimerValue;
}

uint8 RI_GetCpuTimerOverflow(void)
{
    return u8Overflow;
}

void RI_ClearCpuTimerOverflow(void)
{
    u8Overflow = 0;
}

#endif

#ifdef _QAC_
//QACJ 0862: adimiten: Include of all headers is required by 
//                     SWA component template
#endif

