
//******************************************************************************

//------------------------------------------------------------------------------
// Body Identification
//------------------------------------------------------------------------------
#define ldb_tim   "ldb_tim"

//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//
// #include <system_file_name.h>
// #include "project_file_name.h"
//------------------------------------------------------------------------------


#include "LDB_TIM.h"
#include "LDB_TIM_CFG.h"
#include "LIB.h"


#ifdef cLIBStkTosPerfCnt_Used
#ifdef TOS_PERF_CNT_ENABLE
 #include "TOS_PerfCnt.h"
#endif
#endif


//------------------------------------------------------------------------------
// Local constants
//
// #define cConstantName   ((tType) ConstantValue)
//------------------------------------------------------------------------------
#define cNumberOfTempo (cLDBTimNbOfExternalTimeOut + cLDBTimNbOfLocalTimeOut)

#ifndef cLIBStkCpu_MitsuM16C6
    #define cMainTriggerID  mLDBIocGetIntervalTimerTriggerID(cLDBHarRealTimeTimer)
    #define cInterruptID    mLDBIocGetInterruptID(cMainTriggerID)
#else
    #define cMainTriggerID  cLDBHarRealTimeTrigger
    #define cInterruptID    cLDBHarInterruptRealTimeIt
#endif

// definition of cMaxMainTimerValue
#define cMaxMainTimerValue 0xFFFFFFFFUL


#ifdef LDBTIM_USE_SLOW_CLOCK_CALIBRATION
// definition of cMaxMainTimerValue
#if (mLDBIocGetType(cLDBTimCalibrationTimer) == 8)
    // timer 8 bits
    #define cMaxCalibrationTimerValue 0xFFUL
#elif (mLDBIocGetType(cLDBTimCalibrationTimer) == 16)
    // timer 16 bits
    #define cMaxCalibrationTimerValue 0xFFFFUL
#elif (mLDBIocGetType(cLDBTimCalibrationTimer) == 32)
    // timer 32 bits
    #define cMaxCalibrationTimerValue 0xFFFFFFFFUL
#else
  #error "Bad definition of mLDBIocGetType(cLDBTimCalibrationTimer)"
#endif
#endif

// u8CalibrationState values
#define cCalibrationStopped         ((U8)0UL)
#define cCalibrationWaitFirstTick   ((U8)1UL)
#define cCalibrationWaitLastTick    ((U8)2UL)
#define cPerCent 100UL

// The maximum calibration duration is :
// ( Expected Duration + Interrupt period + Interrupt latency )
// The time unit is LDBTick :
//   Expected Duration is < (1 + cLDBTimCalibrationDurationNs/cLDBTick) 
//   Interrupt period = mGetTimeBase()
//   Interrupt latency is < to LDBTick  
// So Max Duration in LDB tick  < to (1 + 1 + (cLDBTimCalibrationDurationNs/cLDBTick) + mGetTimeBase() )
#define cMaxCalibDurationInLdbTick (U16)(2 + (cLDBTimCalibrationDurationNs/cLDBTick) + mGetTimeBase() )


#ifndef cLDBTimMaxPrioriryLevel
    #define cLDBTimMaxPrioriryLevel //mLDBIntGetIsrLevel(cInterruptID)
#endif



//------------------------------------------------------------------------------
// Local macros
//
// #define mMacroName   (MacroDefinition)
//------------------------------------------------------------------------------

#define mGetFastClockTrigger() (cLDBTick / cLDBTimFastClockTickNs)

// Slow clock macros
#ifdef LDBTIM_USE_SLOW_CLOCK
    #define mInitSlowClock() (bUseFastClock=cTrue)
#else
    #define mInitSlowClock()
#endif

#define mSuspendAllIts()                    \
    {                                       \
        BOOL IsItEnabled;               \
        IsItEnabled = mLDBIntIsItsEnabled();\
        mLDBIntDisableAllIts();


#define mResumeAllIts()                     \
        if(IsItEnabled != cFalse)           \
        {                                   \
            mLDBIntEnableAllIts();          \
        }                                   \
    }                               \


// Calibration macros
#ifdef LDBTIM_USE_SLOW_CLOCK_CALIBRATION
    #ifndef LDBTIM_USE_SLOW_CLOCK
        #error LDBTIM_USE_SLOW_CLOCK_CALIBRATION needs LDBTIM_USE_SLOW_CLOCK
    #endif

    #define mGetMaxSlowClockTrigger()  ( ((cLDBTick/(U32)cLDBTimSlowClockTickNs) * (U32)cLDBTimMinDeviation) / (U32)cPerCent )
    #define mGetSlowClockTrigger()    (SlowClockTrigger)
    #define mCancelCalibration()    (u8CalibrationState = cCalibrationStopped)
    #define mInitCalibration()\
                SlowClockTrigger = (tMainTimerCounter)(cLDBTick / (U32)cLDBTimSlowClockTickNs);\
                u8CalibrationState = cCalibrationStopped;

#else
    #define mGetMaxSlowClockTrigger()  (cLDBTick / cLDBTimSlowClockTickNs)
    #define mGetSlowClockTrigger()     (cLDBTick / cLDBTimSlowClockTickNs)
    #define mCancelCalibration()   
    #define mInitCalibration()
#endif

// Change time base macros
#ifdef LDBTIM_USECHANGETIMEBASE
    #define mInitTimeBase()    (u8InternalTimeBase = 1)
    #define mGetTimeBase()     (u8InternalTimeBase)
#else
    #define mInitTimeBase()    
    #define mGetTimeBase()     ((U8)1U)
#endif  

//#if( cLDBTimMaxPrioriryLevel == mLDBIntGetMaxLevel(cLDBTimMaxPrioriryLevel,mLDBIntGetIsrLevel(cInterruptID) ))
    // MaxPriority is lower or equal to LDB_TIM interrupt level
    // The critical section is not requested.
//    #define mEnterCritical()
//    #define mLeaveCritical()
//#else
//添加其它代码实现临界区功能
    #define mEnterCritical() //mLDBIntEnterCriticalSection(cLDBTimMaxPrioriryLevel)
    #define mLeaveCritical() //mLDBIntLeaveCriticalSection()
//#endif

//------------------------------------------------------------------------------
// Local types
//
// typedef Expression    tTypeName;
//------------------------------------------------------------------------------

// definition of tMainTimerCounter
typedef U32 tMainTimerCounter;


#ifdef LDBTIM_USE_SLOW_CLOCK_CALIBRATION
// definition of tCalibrationTimerCounter
#if (mLDBIocGetType(cLDBTimCalibrationTimer) == 8)
    // timer 8 bits
    typedef U8 tCalibrationTimerCounter;
#elif (mLDBIocGetType(cLDBTimCalibrationTimer) == 16)
    // timer 16 bits
    typedef U16 tCalibrationTimerCounter;
#elif (mLDBIocGetType(cLDBTimCalibrationTimer) == 32)
    // timer 32 bits
    typedef U32 tCalibrationTimerCounter;
#else
  #error "Bad definition of mLDBIocGetType(cLDBTimCalibrationTimer)"
#endif
#endif

//------------------------------------------------------------------------------
// Data prefix
//
// unsigned int {u8,u16,u32} / signed int {s8,s16,s32} 
// register size unsigned int {r} / float {f32,f64}  / s for struct 
//
// -----------------------------------------------------------------------------
// Local data
//
// static  tType   u8VariableName;  
// static  tType*  pu8VariableName; 
//------------------------------------------------------------------------------
//QACJ 2200: arozdik: Reading of the code is more convenient. There is conditional compilation above.
static tDelay volatile CounterTempoList[cNumberOfTempo];
static tDelay volatile PeriodTempoList [cLDBTimNbOfExternalTimeOut];

#ifdef LDBTIM_USECHANGETIMEBASE
static U8 u8InternalTimeBase;
#endif

#ifdef LDBTIM_USE_SLOW_CLOCK
static BOOL bUseFastClock;
#endif

#ifdef LDBTIM_USE_SLOW_CLOCK_CALIBRATION
static U8 u8CalibrationState;
static tMainTimerCounter SlowClockTrigger;
static tCalibrationTimerCounter CalibrationTimerInitialCounter;

#ifndef LDBTIM_CALIBRATION_DONT_READ_MAIN_TIMER_COUNTER
static tMainTimerCounter MainTimerInitialCounter;
#else
static tMainTimerCounter ElapsedTimeOnMainTimer;
#endif

#endif

//------------------------------------------------------------------------------
// Constant local data
//
// static const tType  VariableName;
//------------------------------------------------------------------------------
//QACJ 3635: arozdik: Functions are used as a pointer in the generated by SCC2 macro
//QACJ 3111: arozdik: Other Functions can be added in this CallBackList
static const tpFunct pCallBackTimoutList[cNumberOfTempo] = cLDBTimTimeOutCallBackList;

//------------------------------------------------------------------------------
// Exported data
//
// tType   u8LAYCmpVariableName; (LAY: 3 characters to identify the layer)
// tType*  pu8LAYCmpVariableName;(Cmp: 3 characters to identify the component)
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Constant exported data
//
//             (LAY: 3 characters to identify the layer)
//             (Cmp: 3 characters to identify this component)
// 
// const tType   LAYCmpVariableName;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Local function prototypes
// 
// static tTypeRetour FunctionName(tTypeArgument1 ArgumentName1, ... );
//------------------------------------------------------------------------------
/*****************************************************************************/
/* Function implementation - global ('extern') and local ('static')          */
/*****************************************************************************/
U32 u32Random1p25Ms;
U32 u32SysRunCount = 0u;
void ADCTriggerCallback(void)
{
    //do nothing
}
//==============================================================================
// DESCRIPTION : Real time interrupt
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION :
//==============================================================================
void SysTickUnderflowCallback(void)
{
    tTimerRef TimeOutRef;
    static U16 u16ms1p25Count1s;
    u32Random1p25Ms ++;

    IRQ_DISABLE_LOCAL();

     
    // Calculate Tempos
    //QACJ 2465: arozdik: cNumberOfTempo may be more than 1
    for (TimeOutRef = 0U ;TimeOutRef < cNumberOfTempo; TimeOutRef++)
    {
         if (CounterTempoList[TimeOutRef] != (tDelay)0U)      // Tempo is set
        {

            CounterTempoList[TimeOutRef]--;
            if (CounterTempoList[TimeOutRef] == (tDelay)0U)    // Tempo is elapsed
            {
                //QACJ 3355: arozdik: Loop is until (TimeOutRef < cNumberOfTempo) -> Not Local tempo
                //QACJ 3358: arozdik: cNumberOfTempo = (cLDBTimNbOfExternalTimeOut + cLDBTimNbOfLocalTimeOut) -> Not Local tempo
                if(TimeOutRef<cLDBTimNbOfExternalTimeOut)
                {   // Not Local tempo
                    //QACJ 3345: arozdik: no problem, Tempo is elapsed, set CounterTempoList to the corresponding period.
                    CounterTempoList[TimeOutRef] = PeriodTempoList[TimeOutRef];
                }

                pCallBackTimoutList[TimeOutRef]();        // Call callback


            }
        }

    }
#define MS_1P25_COUNT_1S 800U
    u16ms1p25Count1s ++;
    if (u16ms1p25Count1s > MS_1P25_COUNT_1S)
    {
    	u16ms1p25Count1s = 0U;
    	u32SysRunCount ++;
    }
#if 0	//TODO:XXX
    void LDBSimuPwmCBK(void);
    LDBSimuPwmCBK();
#endif
    if (0u == (u32Random1p25Ms % 4u))
    {
#if 0	//TODO:XXX
    	void HighSpeedPwmDutyChangeCBK(void);
    	HighSpeedPwmDutyChangeCBK();
#endif
    }

    IRQ_RESTORE();
    
}

//==============================================================================
//=========================== LOCAL FUNCTIONS ==================================
//==============================================================================


//==============================================================================
//=========================== EXPORTED FUNCTIONS ===============================
//==============================================================================

//==============================================================================
// DESCRIPTION : Start ldb_tim component
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : Refer to Detailed Design Document
//==============================================================================
void LDBTimStart(void)
{
	BSPTimSysTickStart();
}


//==============================================================================
// DESCRIPTION : Initialize timer
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : Refer to Detailed Design Document
//==============================================================================
void LDBTimInit(void)
{

    mLIBassert( cLDBTimNbOfExternalTimeOut > 0U);
    (void)mLIBmemset((U8*)&CounterTempoList,0U,(cNumberOfTempo*sizeof(tDelay)));
    u32Random1p25Ms = 0U;
    BSPTimInit();
    // RLT - configuration
//	stc_rlt_config_t stcRltConfig = { .enPrescaler            = RltDiv4,                   // Clock further divided by 16
//									  .enOperationMode        = RltSoftwareTriggerOnly,     // Trigger with Software
//									  .b32bitTimerModeEnable  = FALSE,                      // 16bit mode
//									  .bOutputPolarityInverse = FALSE,                      // normal polarity
//									  .bOneshotEnable         = FALSE,                      // run cyclic
//									  .bGateInputEnable       = FALSE,                      // trigger input
//									  .pfnTriggerCallback     = RLTTriggerCallback,         // use callback for interrupt
//									  .pfnUnderflowCallback   = RLTUnderflowCallback};      // use callback for interrupt
//
//    // Init Timer with above configuration
//    Rlt_Init ((stc_btn_rt_t*)&cLDBTimerSource, &stcRltConfig);
    LDBTimStart();
}


//==============================================================================
// DESCRIPTION : Stop ldb_tim component
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : Refer to Detailed Design Document
//==============================================================================
void LDBTimStop(void)
{
	BSPTimSysTickStop();
}

//==============================================================================
// DESCRIPTION : Start Tempo TimeOutRef
// 
// PARAMETERS  : tTimerRef TimeOutRef : timout reference number (0 to cLDBTimNbOfExternalTimeOut-1)
//               tDelay Duree         : duration in cLDBTick 
//               tpFunc pFunc         : function called a the time out expiration 
//               BOOL Periodique  : Automatic Reload of the timeout(cTrue or cFalse) 
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : Refer to Detailed Design Document
//==============================================================================
//QACJ 3672: arozdik:  Parameter is not modified, but is used not const in other components
void LDBStartTimer( tTimerRef TimeOutRef, tpFunct pFunc, tDelay Duree, BOOL bPeriodic )
{
    //To avoid a LDBStopTimer call into interrupt context during
    //the start timer is performing
    //QACJ 3220: arozdik: definition in macro block {}
    //mSuspendAllIts();
	IRQ_DISABLE_LOCAL();

    // Verify that tempo exist
    mLIBassert(TimeOutRef < cLDBTimNbOfExternalTimeOut);

    // Verify that tempo is not currently set
    //QACJ 3441: arozdik: mLIBassert is empty in Release mode. No side effects.
    mLIBassert(CounterTempoList[TimeOutRef] == (tDelay)0U);

    // Save callback function pointer
    mLIBassert(pCallBackTimoutList[TimeOutRef] == pFunc);

    // Save period if periodic
    if (bPeriodic != cFalse)
    {
        PeriodTempoList[TimeOutRef] = Duree;
    }
    else
    {
        PeriodTempoList[TimeOutRef] = (tDelay)0U;
    }
    // Initialize count
    CounterTempoList[TimeOutRef] = Duree + (tDelay)1;  // +1 for ensure that tempo is upper that duree

    //mResumeAllIts();
    IRQ_RESTORE();
}




//==============================================================================
// DESCRIPTION  : Stop Tempo TimeOutRef
// 
// PARAMETERS   : tTimerRef TimeOutRef : timout reference number (0 to cLDBTimNbOfExternalTimeOut-1)
//
// RETURN VALUE :   tDelay : counter value
//
// DESIGN INFORMATION : Refer to Detailed Design Document
//==============================================================================
tDelay LDBStopTimer( tTimerRef TimeOutRef )
{
    tDelay CounterValue;

    //To avoid a LDBStartTimer call into interrupt context during
    //the stop timer is performing
    //QACJ 3220: arozdik: definition in macro block {}
    //mSuspendAllIts();
    IRQ_DISABLE_LOCAL();
    // Verify that tempo exist
    mLIBassert(TimeOutRef < cLDBTimNbOfExternalTimeOut);

    // Read Counter
    CounterValue = CounterTempoList[TimeOutRef];
    // Clear counter
    CounterTempoList[TimeOutRef] = (tDelay)0U;

    //mResumeAllIts();
    IRQ_RESTORE();
    return (CounterValue);
}

void LDBTimControl(tCtrl Ctrl)
{
    switch(Ctrl)
    {
    case cLDBTimStartADC:
        BSPTimADCStart();
        break;
    case cLDBTimStopADC:
        // now this no chance to stop ADC timer after start it.
        break;
    }
}


#if cLDBTimNbOfLocalTimeOut !=0
//==============================================================================
// DESCRIPTION  : void LDBTimStartLocalTempo( tTimerRef TimeOutRef, tDelay Duree )
//                Start local Tempo 
// 
// PARAMETERS   :  tTimerRef TimeOutRef : timout reference number (0 to cLDBTimNbOfLocalTimeOut-1)
//                 tDelay Duree         : duration in cLDBTick 
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : Refer to Detailed Design Document
//==============================================================================
void LDBTimStartLocalTimeOut(tTimerRef TimeOutRef, tDelay Duree)
{
    //To avoid a LDBStopTimer call into interrupt context during
    //the start timer is performing
    mSuspendAllIts();

    // Verify that tempo exist
    mLIBassert(TimeOutRef < cLDBTimNbOfLocalTimeOut);

    // Verify that tempo is not currently set
    mLIBassert(CounterTempoList[TimeOutRef+cLDBTimNbOfExternalTimeOut] == (tDelay)0);

    // Initialize count
    CounterTempoList[TimeOutRef+cLDBTimNbOfExternalTimeOut] = Duree + (tDelay)1;  // +1 for ensure that tempo is upper that duree

    mResumeAllIts();
}

//==============================================================================
// DESCRIPTION : Stop Local Tempo TimeOutRef
//
// PARAMETERS (Type,Name,Min,Max) : tTimerRef TimeOutRef : timout reference number
//                                  (0 to cLDBTimNbOfLocalTimeOut-1)
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : Refer to Detailed Design Document
//==============================================================================
void LDBTimStopLocalTimeOut(tTimerRef TimeOutRef )
{
    //To avoid a LDBStopTimer call into interrupt context during
    //the start timer is performing
    mSuspendAllIts();

    // Verify that tempo exist
    mLIBassert(TimeOutRef < cLDBTimNbOfLocalTimeOut);

    // Clear count
    CounterTempoList[TimeOutRef+cLDBTimNbOfExternalTimeOut] = (tDelay)0;

    mResumeAllIts();
}
#endif



