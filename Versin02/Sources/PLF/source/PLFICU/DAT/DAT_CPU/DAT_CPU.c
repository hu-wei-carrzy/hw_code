
//------------------------------------------------------------------------------
// Body Identification
//------------------------------------------------------------------------------
#define DAT_CPU   "DAT_CPU"


//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//
// #include <system_file_name.h>
// #include "project_file_name.h"
//------------------------------------------------------------------------------s
#include "DAT_CPU.h"
#include ".\..\..\..\..\..\..\include\core_cm4.h"


//------------------------------------------------------------------------------
// Local constants
//
// #define cConstantName   ((tType) ConstantValue)
//------------------------------------------------------------------------------
#define cMultiplyOf4Mask        ((U32)3U)    // for the two less significant bits
#define cMultiplyOf2Mask        ((U32)1U)    // for the less significant bit

#define cWatchDogCounterMaxValue mDiv(cWatchDogIdleTaskTimeoutMs,cRefreshWatchDogPeriodMs)

#define cfgDebugUnusedStack 1

#if defined(Debug_Output_By_Can) && (cfgDebugUnusedStack==1) && !defined(COMPILATION_NATIVE) && defined(TRACE_CPU_ACTIVE)
#define mUnusedStackDebugOnCAN(UnusedStack)									\
	do {																	\
		mDATControl(PeriodTxEnable, IC_DbgInfor);					\
		mDATWrite(U8Bit,ICDbgData0,(U8)(UnusedStack>>24)&0xFF,Default);   	\
		mDATWrite(U8Bit,ICDbgData1,(U8)(UnusedStack>>16)&0xFF,Default);   	\
		mDATWrite(U8Bit,ICDbgData2,(U8)(UnusedStack>>8 )&0xFF,Default);   	\
		mDATWrite(U8Bit,ICDbgData3,(U8)(UnusedStack>>0 )&0xFF,Default);   	\
		mDATControl(CANEmission, IC_DbgInfor);								\
	}while(0)
#else
#define mUnusedStackDebugOnCAN(UnusedStack)
#endif

//------------------------------------------------------------------------------
// Local constants
//
// #define cConstantName   ((tType) ConstantValue)
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Local macros
//
// #define mMacroName   (MacroDefinition)
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Local types
//
// typedef Expression    tTypeName;
//------------------------------------------------------------------------------

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
static tTOSAlarm GraphEngineAlarm;
//QACJ 3218: adimovvl:  This is standard place for declaration of static variables.
static tTOSAlarm RefreshWatchDogAlarm;
static BOOL  IsIdleGraphGroupEnable;
static U8    WatchDogCounter;


static BOOL  bDATCpuFirstWatermarkAssert;


#ifndef DISABLE_IDLE_MEASURE
U32 u32DATCpuUnUsedStackSize;
#endif

//------------------------------------------------------------------------------
// Constant local data
//
// static const tType  VariableName;
//------------------------------------------------------------------------------

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
static void DATCpuCheckStackWatermarks(void);
static void DATCpuSetStackWatermarks(void);
static void DATCpuSetStackContents(void);

//==============================================================================
//=========================== LOCAL FUNCTIONS ==================================
//==============================================================================

//==============================================================================
// DESCRIPTION : DATCpuCheckStackWatermarks()
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
static void DATCpuCheckStackWatermarks(void)
{

	bDATCpuFirstWatermarkAssert = bDATCpuFirstWatermarkAssert;

    tDATCpuStackWatermarkValue *pWatermark;

    //CCOV: amanevm: Depends from predefined constatnts. False case is not interested because no code is executed
    if (cDATCpuWatermarkAssertAddress != cDATCpuWatermarkDisable)
    {
        //QACJ 0306: adimovvl: Pointer arithmetic is used
        pWatermark = (tDATCpuStackWatermarkValue *)cDATCpuWatermarkAssertAddress;
        if (*pWatermark != cDATCpuWatermarkAssertValue)
        {
            if (bDATCpuFirstWatermarkAssert != cFalse)
            {
                bDATCpuFirstWatermarkAssert = cFalse;
#ifndef COMPILATION_NATIVE
                mLIBassert(cFalse);
#endif
            }
        }
    }

    //CCOV: amanevm: Depends from predefined constatnts. False case is not interested because no code is executed
    if (cDATCpuWatermarkResetAddress != cDATCpuWatermarkDisable)
    {
        //QACJ 0306: adimovvl: Pointer arithmetic is used
        pWatermark = (tDATCpuStackWatermarkValue *)cDATCpuWatermarkResetAddress;
        if (*pWatermark != cDATCpuWatermarkResetValue)
        {
            mLIBassert(cFalse);
            LDBReset();
        }
    }

}


//==============================================================================
// DESCRIPTION : DATCpuSetStackWatermarks
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
static void DATCpuSetStackWatermarks(void)
{

    tDATCpuStackWatermarkValue *pWatermark = (tDATCpuStackWatermarkValue*)0U;

    //CCOV: amanevm: Depends from predefined constatnts. False case is not interested because no code is executed
    if (cDATCpuWatermarkAssertAddress != cDATCpuWatermarkDisable)
    {
        //QACJ 0306: adimovvl: Pointer arithmetic is used
        pWatermark = (tDATCpuStackWatermarkValue *)cDATCpuWatermarkAssertAddress;
        if(pWatermark)
        {
                *pWatermark = cDATCpuWatermarkAssertValue;
        }
    }
    //CCOV: amanevm: Depends from predefined constatnts. False case is not interested because no code is executed
    if (cDATCpuWatermarkResetAddress != cDATCpuWatermarkDisable)
    {
        //QACJ 0306: adimovvl: Pointer arithmetic is used
        pWatermark = (tDATCpuStackWatermarkValue *)cDATCpuWatermarkResetAddress;
        if(pWatermark)
        {
                *pWatermark = cDATCpuWatermarkResetValue;
        }
    }

}


//==============================================================================
// DESCRIPTION : DATCpuSetStackContents
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
static void DATCpuSetStackContents(void)
{

    //CCOV: amanevm: Depends from predefined constatnts. False case is not interested because no code is executed
    if (cDATCpuWatermarkResetAddress != cDATCpuWatermarkDisable)
    {
		U8 *pu8start, *pu8stop;

		U8 u8InStack = 0U;
		U8 *pu8InStack = &u8InStack;

		// WARNING: memset() should not be used directly because it (as any function) pushes its arguments and return address in the stack and they could get overwritten!
        //QACJ 0306: adimovvl: Pointer arithmetic is used
        //QACJ 0490: adimovvl: Pointer addresses comparison
        if (((U8 *)cDATCpuWatermarkResetAddress) > pu8InStack)
        {
            // upward growing stack
			pu8start = pu8InStack;
            //QACJ 0306: adimovvl: Pointer arithmetic is used
			pu8stop = (U8 *)cDATCpuWatermarkResetAddress;
		}
        else
        {
            // downward growing stack
            //QACJ 0306: adimovvl: Pointer arithmetic is used
			pu8start = (U8 *)cDATCpuWatermarkResetAddress;
			pu8stop = pu8InStack;
        }
        //QACJ 0490: adimovvl: Pointer addresses comparison
		while (pu8start <= pu8stop)
		{
				*pu8start = cDATCpuStackContentsValue;
                //QACJ 0489: adimovvl: Pointer addresses comparison
				pu8start++;
		}
    }

}

//==============================================================================
//=========================== EXPORTED FUNCTIONS ===============================
//==============================================================================

//==============================================================================
// DESCRIPTION : DATCpuIdleTask: Idle task
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void DATCpuIdleTask(void)
{
    if( IsIdleGraphGroupEnable != cFalse )
    {
        //QACJ 3141: adimovvl: The macros is from extern component
        mTOSSeqMotorIdleGraphGroup();
    }
#ifndef DAT_CPU_ENABLE_HALT
    else
    {
        LDBWaitForCallBack();
    }
#endif

    WatchDogCounter = cWatchDogCounterMaxValue;

    DATCpuCheckStackWatermarks();

#ifndef DISABLE_IDLE_MEASURE
    //CCOV: amanevm: Depends from predefined macro. False case is not interested because no code is executed
    if (mDATCpuGetUnUsedStackSizeEnabled())
    {
        u32DATCpuUnUsedStackSize = DATCpuGetUnUsedStackSize();
        mUnusedStackDebugOnCAN(u32DATCpuUnUsedStackSize);
    }
#endif

    //jingyaa--AD   在此处使用AD切换，因为该芯片AD模块有些尴尬。
//extern void DATAnaSwitchScan(void);
//    DATAnaSwitchScan();

///#ifdef DAT_CPU_ENABLE_HALT
//    TOSHalt();
//#endif
}


//==============================================================================
// DESCRIPTION : DATCpuInit : Initialization of the component
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void DATCpuInit(void)
{
    RefreshWatchDogAlarm.TaskID = cTOSTaskIdDATCpuRefreshWatchDogTask;
    TOSSetRelAlarm( &RefreshWatchDogAlarm,0, mTOSConvMsInAlarmTick(cRefreshWatchDogPeriodMs) );
    IsIdleGraphGroupEnable = cFalse;
    WatchDogCounter = cWatchDogCounterMaxValue;

    bDATCpuFirstWatermarkAssert = cTrue;

#ifndef DISABLE_IDLE_MEASURE
    u32DATCpuUnUsedStackSize = 0U;
#endif

    if (sizeof(tDATCpuStackWatermarkValue) == 4U)
    {
        // warn that for accessing 32 bits (4 bytes) in many MCUs the address must be a multiply of 4!
        mLIBassert(((U32)cDATCpuWatermarkAssertAddress & cMultiplyOf4Mask) == (U32)0U);
        mLIBassert(((U32)cDATCpuWatermarkResetAddress & cMultiplyOf4Mask) == (U32)0U);
    }


    if (sizeof(tDATCpuStackWatermarkValue) == 2U)
    {
        // warn that for accessing 16 bits (2 bytes) in many MCUs the address must be a multiply of 2!
        mLIBassert(((U32)cDATCpuWatermarkAssertAddress & cMultiplyOf2Mask) == (U32)0U);
        mLIBassert(((U32)cDATCpuWatermarkResetAddress & cMultiplyOf2Mask) == (U32)0U);
    }

    //CCOV: amanevm: Depends from predefined macro. False case is not interested because no code is executed
    if (mDATCpuGetUnUsedStackSizeEnabled())
    {
        DATCpuSetStackContents();
    }

    //éè???????ˉ???Toí?′???T￡??ˉ???T=??ê1ó??ê3?1y90%￡??′???T￡o??íêè?±?ê1ó??￡
    DATCpuSetStackWatermarks();
}


//==============================================================================
// DESCRIPTION : DATCpuLeaveSleep : leave the sleep mode
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void DATCpuLeaveSleep(void)
{
    GraphEngineAlarm.TaskID = cTOSTaskIdGraphEngineTask;
    TOSSetRelAlarm( &GraphEngineAlarm,0, mTOSConvMsInAlarmTick(cGraphEnginePeriodMs) );
    IsIdleGraphGroupEnable = cTrue;

    #ifdef USE_DISABLE_TOSTIMER
    TOSDisableTimer();
    TOSStopAlarm();
    #endif

    LDBLeaveSleepMode();

    #ifdef USE_DISABLE_TOSTIMER
    TOSStartAlarm();
    TOSEnableTimer(1U); //Min Multiplicator Value = 1
    #endif
}


//==============================================================================
// DESCRIPTION : DATCpuEnterSleep : entering into the sleep mode
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void DATCpuEnterSleep(void)
{
    TOSCancelAlarm( &GraphEngineAlarm );
    IsIdleGraphGroupEnable = cFalse;

    #ifdef USE_DISABLE_TOSTIMER
    TOSDisableTimer();
    TOSStopAlarm();

    //USE_DISABLE_TOSTIMER definition is used to give possibility to control TOSClock period in Sleep mode.
    //In Sleep mode frequency may be reduced but TOS timer is active and new multiplier may be
    //applied to have less frequent TOSClockTask and lower power consumption in Sleep.
    //Set new TOSClock period for Sleep mode here!

    TOSStartSlowestAlarms((tTOSTickAlarm)(cLDBSleepTick / cLDBTick));
    TOSEnableTimer((tTOSTickAlarm)(cLDBSleepTick / cLDBTick));
    #endif

    LDBEnterSleepMode();
}


//==============================================================================
// DESCRIPTION : DATCpuRefreshWatchDogTask : periodical task is create in order
// to refresh watchdog
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void DATCpuRefreshWatchDogTask(void)
{
    // A periodical task is create in order to refresh watchdog.

    // This way of processing allows to:
    // - Insure that TOS time base correctly work
    // - Insure that tasks with higher priority than this task running.
    // - Get an unique mechanism in wake-up and sleep modes.

    // This way of processing does not allows to:
    // - Insure that tasks with lower priority than this task running.
    //   For example, if the graph engine run in idle task, this solution
    //   is not adjusted. In this case use a graph updating watchdog when
    //   a temporization elapse.






    if( WatchDogCounter != 0U)
    {
        // This counter allows to check that tasks of lower priority than
        // Watch dog tasks are also running.
        WatchDogCounter--;

        LDBRefreshWatchDog();
    }
}

#ifndef DISABLE_IDLE_MEASURE
//==============================================================================
// DESCRIPTION : DATCpuGetUnUsedStackSize : get the unused stack size
//
// PARAMETERS (Type,Name,Min,Max) :   U32 : unused stack size
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
// in bytes, if returned value = 0 then the measure is not performed (enabled),
//to enable it just define meaningful cDATCpuWatermarkResetAddress
//==============================================================================
U32 DATCpuGetUnUsedStackSize(void)
{
    U32 u32Size = 0;

    //CCOV: amanevm: Depends from predefined macro. False case is not interested because no code is executed
    if (mDATCpuGetUnUsedStackSizeEnabled())
    {
#ifndef COMPILATION_NATIVE
        U8 *pu8InStack = (U8 *)&u32Size;
#else
        U8 *pu8InStack = pDATCpuInStack;
#endif
        //QACJ 0306: adimovvl: Pointer arithmetic is used
        U8 *pu8StackFrom = (U8 *)cDATCpuWatermarkResetAddress;
        // always start the scan from stack end to current stack pointer!
        //QACJ 0306: adimovvl: Pointer arithmetic is used
        //QACJ 0490: adimovvl: Pointer addresses comparison
        if ((U8 *)cDATCpuWatermarkResetAddress > pu8InStack)
        {
            // upward growing stack
            //QACJ 0489: adimovvl: Pointer arithmetic is used
            pu8StackFrom--; // skip reset watermark
            //QACJ 0490: adimovvl: Pointer arithmetic is used
            while (   (pu8StackFrom > pu8InStack) && (((*pu8StackFrom) == cDATCpuStackContentsValue)
                   //QACJ 0306: adimovvl: Pointer arithmetic is used
                   //QACJ 0488: adimovvl: Pointer arithmetic is used
                   || (pu8StackFrom == (U8 *)((U8 *)cDATCpuWatermarkAssertAddress+(sizeof(tDATCpuStackWatermarkValue)-1)))))
            {
                //QACJ 0306: adimovvl: Pointer arithmetic is used
                //QACJ 0488: adimovvl: Pointer arithmetic is used
                if (pu8StackFrom == (U8 *)((U8 *)cDATCpuWatermarkAssertAddress+(sizeof(tDATCpuStackWatermarkValue)-1)))
                {
                    // take into account assert watermark
                    //QACJ 0488: adimovvl: Pointer arithmetic is used
                    pu8StackFrom -= sizeof(tDATCpuStackWatermarkValue);
                    u32Size += sizeof(tDATCpuStackWatermarkValue);
                }
                else
                {
                    u32Size++;
                    //QACJ 0489: adimovvl: Pointer arithmetic is used
                    pu8StackFrom--;
                }
            }
        }
        else
        {
            // downward growing stack
            //QACJ 0488: adimovvl: Pointer arithmetic is used
            pu8StackFrom += sizeof(tDATCpuStackWatermarkValue); // skip reset watermark
            //QACJ 0306: adimovvl: Pointer arithmetic is used
            //QACJ 0490: adimovvl: Pointer addresses comparison
            while ((pu8StackFrom < pu8InStack) && (((*(pu8StackFrom)) == cDATCpuStackContentsValue) || (((pu8StackFrom)) == (U8*)cDATCpuWatermarkAssertAddress)))
            {
                //QACJ 0306: adimovvl: Pointer arithmetic is used
                if (pu8StackFrom == (U8 *)cDATCpuWatermarkAssertAddress)
                {
                    // take into account assert watermark
                    //QACJ 0488: adimovvl: Pointer arithmetic is used
                    pu8StackFrom += sizeof(tDATCpuStackWatermarkValue);
                    u32Size += sizeof(tDATCpuStackWatermarkValue);
                }
                else
                {
                    u32Size++;
                    //QACJ 0489: adimovvl: Pointer arithmetic is used
                    pu8StackFrom++;
                }
            }
        }
    }
    else
    {
        // functionality not enabled, cDATCpuWatermarkResetAddress must be defined
        // according to actual stack location
#ifndef COMPILATION_NATIVE
        mLIBassert(cFalse);
#endif
    }

    return u32Size;
}
#endif	/* DISABLE_IDLE_MEASURE */



U32 DATCpuGetResetCause(void)
{
	U32	u32MCURestCause = 0U;
	tMsg	ptmsg;
	ptmsg.Lng = 4U;
	ptmsg.pBuffer = ((U8*)&u32MCURestCause);
	LDBReceiveWithoutAddr(cLDBChannelLDB_RST,&ptmsg);
	return(u32MCURestCause);
}

void DATCpuWillReset(void)
{
    //MCU will reset , so here send control to notify other models.
    TOSSendControl( cTOSControlMCUWillReset);
}

void DATMCUWillReset(void)
{
	__DI();
	  SCB->AIRCR  = ((0x5FA << SCB_AIRCR_VECTKEY_Pos)      |

	                 (SCB->AIRCR & SCB_AIRCR_PRIGROUP_Msk) |

	                 SCB_AIRCR_SYSRESETREQ_Msk);
	while(1);
}


