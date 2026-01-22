//******************************************************************************
// Copyright:    This software is JYD property.
//               Duplication or disclosure without JYD written authorization
//               is prohibited.
// -----------------------------------------------------------------------------
// Project:      BCM313
// Language:     C
// -----------------------------------------------------------------------------
// Component:  superior to control all the code running and stop.
// -----------------------------------------------------------------------------
//******************************************************************************
// This line is used to separate code and file header.This is begin.
//*****************************BEGIN_NOMOVE*************************************
// Time:2016-08-30 16:32:09
// 1:remove power lock from LAPIsSysStable() to LAPStartupHook()
// 2:
// Time:2016-09-19 09:36:00
// 1:enable the starting step wating check because now the EEP is OK.
// Time:2016-09-22 15:26:20
// 1:bug fix about power lock. Add power lock when enter active state.
//*****************************END_NOMOVE***************************************
// This line is used to separate code and file header. This is last line.
//******************************************************************************

//----------------------------------------------------------------------------------------------------------------------
// Body Identification
//----------------------------------------------------------------------------------------------------------------------

#define lap_sup  "lap_sup"

//----------------------------------------------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//----------------------------------------------------------------------------------------------------------------------

//#include "lib.h"
//#include "dat.h"
#include "ARCH_CFG.h"

#ifdef cHeadIncludeType_Directly
#include "lap_sup.h"
#include "lap_sup.hgr"
#include "LAP_SUP_CFG.h"
#else
#include "lap_sup.h"
#include "lap_sup.hgr"
#include "LAP_SUP_CFG.h"
#endif

// Local constants
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
// Local macros
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
// Local types
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
// Local data
//----------------------------------------------------------------------------------------------------------------------

static  BOOL  SleepMode;
static tTOSTimer  MinActiveTimer;
static  tTOSTimer   stStartDelayTimer;		/*启动延时2.2s*/

//----------------------------------------------------------------------------------------------------------------------
// Constant local data
// ---------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
// Exported data
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
// Constant exported data
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
// Local function prototypes
//----------------------------------------------------------------------------------------------------------------------

//======================================================================================================================
// LOCAL FUNCTIONS
//======================================================================================================================

//======================================================================================================================
// DESCRIPTION:         Send a Control to Enter in Starting step State.
//
// PARAMETERS:          none
//
// RETURN VALUE:        none
//
// DESIGN INFORMATION:  refer to Detailed Design Document
//======================================================================================================================
void LAPSupControlEnterStartingStepState( void )
{
    TOSSendControl(cTOSControlEnterStartingStepState);
}

//======================================================================================================================
// DESCRIPTION:         Send a Control Leave from the Starting Step State
//
// PARAMETERS:          none
//
// RETURN VALUE:        none
//
// DESIGN INFORMATION:  refer to Detailed Design Document
//======================================================================================================================
void LAPSupControlLeaveStartingStepState( void )
{
    TOSSendControl(cTOSControlLeaveStartingStepState);
}

//======================================================================================================================
// DESCRIPTION:         Send a Control to enter in DAT Active State.
//
// PARAMETERS:          none
//
// RETURN VALUE:        none
//
// DESIGN INFORMATION:  refer to Detailed Design Document
//======================================================================================================================
void LAPSupControlDATEnterActiveState( void )
{
    TOSSendControl(cTOSControlDATEnterActiveState);
}

//======================================================================================================================
// DESCRIPTION:         Send a Control to enter in LAP Active State.
//
// PARAMETERS:          none
//
// RETURN VALUE:        none
//
// DESIGN INFORMATION:  refer to Detailed Design Document
//======================================================================================================================
void LAPSupControlLAPEnterActiveState( void )
{
    TOSSendControl(cTOSControlLAPEnterActiveState);
}

//======================================================================================================================
// DESCRIPTION:         Send Controls to leave LAP and DAT Active State.
//
// PARAMETERS:          none
//
// RETURN VALUE:        none
//
// DESIGN INFORMATION:  refer to Detailed Design Document
//======================================================================================================================
void LAPSupControlLeaveActiveState( void )
{
    TOSSendControl(cTOSControlLAPLeaveActiveState);
    TOSSendControl(cTOSControlDATLeaveActiveState);
}

//======================================================================================================================
// DESCRIPTION:         Read the Signal to check if an Active Sleep is Requested.
//
// PARAMETERS:          none
//
// RETURN VALUE:        cTrue if somebody send a cTOSSignalActiveSleepRequested signal, otherwise cFalse.
//
// DESIGN INFORMATION:  refer to Detailed Design Document
//======================================================================================================================
BOOL LAPSupActiveSleepRequested( void )
{
    return (TOSReadSignal(cTOSSignalActiveSleepRequested));
}

//======================================================================================================================
// DESCRIPTION:         Read the Signal to check if an wake up is Requested.
//
// PARAMETERS:          none
//
// RETURN VALUE:        cTrue if somebody send a cTOSSignalWakeUpRequested signal, otherwise cFalse.
//
// DESIGN INFORMATION:  refer to Detailed Design Document
//======================================================================================================================
BOOL LAPSupWakeUpRequested( void )
{
   return (TOSReadSignal(cTOSSignalWakeUpRequested));
}

//======================================================================================================================
// DESCRIPTION:         Ask to the subscriber components if anyone maintain the starting step.
//
// PARAMETERS:          none
//
// RETURN VALUE:        cTrue if somebody send a cTOSSignalSomebodyMaintainStartingStepState signal, otherwise cFalse.
//
// DESIGN INFORMATION:  refer to Detailed Design Document
//======================================================================================================================
BOOL LAPSupNobodyMaintainStartingStepState( void )
{
    BOOL bSomebodyMaintainStartingStepState;

    TOSSendControl(cTOSControlIsAnybodyMaintainStartingStepState);

    bSomebodyMaintainStartingStepState = TOSReadSignal(cTOSSignalSomebodyMaintainStartingStepState);

    return(bSomebodyMaintainStartingStepState == cFalse);
    //return cTrue;
}

//======================================================================================================================
// DESCRIPTION:         Ask to the subscriber components if anyone maintain the ActiveSleep State.
//
// PARAMETERS:          none
//
// RETURN VALUE:        cTrue if somebody send a cTOSSignalSomebodyMaintainActiveSleepState signal, otherwise cFalse.
//
// DESIGN INFORMATION:  refer to Detailed Design Document
//======================================================================================================================
BOOL LAPSupNobodyMaintainActiveSleepState( void )
{
    BOOL bSomebodyMaintainActiveSleepState = cFalse;

    TOSSendControl(cTOSControlIsAnybodyMaintainActiveSleepState);

    bSomebodyMaintainActiveSleepState = TOSReadSignal(cTOSSignalSomebodyMaintainActiveSleepState);

    return(bSomebodyMaintainActiveSleepState == cFalse);
}

//======================================================================================================================
// DESCRIPTION:         Ask to the subscriber components if anyone maintain the Active State.
//
// PARAMETERS:          none
//
// RETURN VALUE:        cTrue if somebody send a cTOSSignalSomebodyMaintainActiveState signal, otherwise cFalse.
//
// DESIGN INFORMATION:  refer to Detailed Design Document
//======================================================================================================================
BOOL LAPSupNobodyMaintainActiveState( void )
{
    BOOL bSomebodyMaintainActiveState;
    TOSSendControl(cTOSControlIsAnybodyMaintainActiveState);

    bSomebodyMaintainActiveState = TOSReadSignal(cTOSSignalSomebodyMaintainActiveState);

    return(bSomebodyMaintainActiveState == cFalse);
}

//======================================================================================================================
// EXPORTED FUNCTIONS
//======================================================================================================================

//======================================================================================================================
// DESCRIPTION:         Request an Active Sleep State.
//
// PARAMETERS:          none
//
// RETURN VALUE:        none
//
// DESIGN INFORMATION:  refer to Detailed Design Document
//======================================================================================================================
void LAPSupActiveSleepRequest( void )
{
    if (SleepMode != cFalse)
    {
        mSERControl( Cpu, LeaveSleep );
        SleepMode = cFalse;
    }

    TOSWriteSignal(cTOSSignalActiveSleepRequested);
}

//======================================================================================================================
// DESCRIPTION:         Request a Wake Up.
//
// PARAMETERS:          none
//
// RETURN VALUE:        none
//
// DESIGN INFORMATION:  refer to Detailed Design Document
//======================================================================================================================
void LAPSupWakeUpRequest( void )
{
	if(SleepMode != cFalse)
    {
        mSERControl( Cpu, LeaveSleep);
        SleepMode = cFalse;
    }

    TOSWriteSignal(cTOSSignalWakeUpRequested);
}

//======================================================================================================================
// DESCRIPTION:         Enter in sleep state.
//
// PARAMETERS:          none
//
// RETURN VALUE:        none
//
// DESIGN INFORMATION:  refer to Detailed Design Document
//======================================================================================================================
void LAPSupEnterSleep( void )
{
    /* PON URD42 DEV 1104 / PON URD42 BODY_SW 338 */
    (void)TOSReadSignal(cTOSSignalActiveSleepRequested);

    #ifdef TOS_PREEMPTIVE
    // Tm118140:  Wakeup condition during Sleep sequence in preemptive TOS.
    // Get Resource to not execute activated by wakeup interrupt Task. This Task 
    // will send: TOSSendControl(cTOSControlWakeUpRequest) -> LAPSupWakeUpRequest.
    // This Task will be executed, after exit LDBSupEnterSleepMode and TOSHalt, 
    // because of pending Task (LDBWaitForCallBack-> "Halt" will not be executed on this reason too)
    // and after exit LAPSupEnterSleep, because of TOSReleaseResource(cTOSResourceScheduler).
    // So, after exit LAPSupEnterSleep, because of wakeup request, LAPSupWakeUpRequest
    // will be started and treating of variable "SleepMode" will be right.
    TOSGetResource(cTOSResourceScheduler); 
    #endif

    //设置为休眠模式
    SleepMode = cTrue;

    mSERControl( Cpu, EnterSleep );

    TOSSendControl(cTOSControlEnterSleep);

    #ifdef TOS_PREEMPTIVE
    TOSReleaseResource(cTOSResourceScheduler);
    #endif
}

//======================================================================================================================
// DESCRIPTION:         Check if the minimun time to stay in active state is elapse.
//
// PARAMETERS:          none
//
// RETURN VALUE:        cTrue if time is elapsed, otherwise cFalse.
//
// DESIGN INFORMATION:  refer to Detailed Design Document
//======================================================================================================================
BOOL LAPSupMinimumActiveTimeIsElapsed( void )
{
    return(TOSIsTimerElapsed(&MinActiveTimer, cLAPSupMinActiveTimerMs / (tTOSTimer)cTOSTimerTickMs));
}

//======================================================================================================================
// DESCRIPTION:         Stay Active during cLAPSupMinActiveTimerMs after a entering in active state or a wake up Request
//
// PARAMETERS:          none
//
// RETURN VALUE:        cTrue if somebody send a cTOSSignalSomebodyMaintainActiveState signal, otherwise cFalse.
//
// DESIGN INFORMATION:  refer to Detailed Design Document
//======================================================================================================================
void LAPSupMinimumActiveTime(void)
{
    TOSStartTimer(&MinActiveTimer);
}

//======================================================================================================================
// DESCRIPTION:         The Application stop.
//
// PARAMETERS:          none
//
// RETURN VALUE:        none
//
// DESIGN INFORMATION:  refer to Detailed Design Document
//======================================================================================================================
//QACJ 3206: amanevm: for future use
void LAPShutdownHook(U16 u16ErrorCode)
{
    // We enter this function only for target test.
    // Place a breackpoint on this function. Coderreur parameter indicates
    // errors number detected during the test.
#ifndef UTEST
    LDBReset();
#endif
}

//======================================================================================================================
// DESCRIPTION:         The Application start.
//
// PARAMETERS:          none
//
// RETURN VALUE:        none
//
// DESIGN INFORMATION:  refer to Detailed Design Document
//======================================================================================================================

void LAPStartupHook( void )
{
    // Components init
    LDBInit();

    TOSInit();

    // TODO : Component init calls
    TOSSendControl(cTOSControlDATInitialize);
    TOSSendControl(cTOSControlLAPInitialize);

    // Alarm authorization
    //periodical task ready
    TOSStartAlarm();

    //all graph task(without LAP_SUP graph)task ready
    mSERControl( Cpu, LeaveSleep );

    SleepMode = cFalse;

    //supervisor graph(LAP_SUP graph )task ready.
    TOSSeqActivateGraph( cTOSSeqGraphIdSupervisor );

    //NOTE:just ready, not running, because the tick timer interrupt
    //is not enabled here

    //register system chekc task, now only DATAna and DATBat task
    TOSSendControl(cTOSControlLAPRegistSysCheckTask);

}

//==============================================================================
// DESCRIPTION : 
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none 
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================

BOOL LAPSupIsSysStable(void)
{

   BOOL bRet = cFalse;
   if(!(TOSIsTimerStarted(&stStartDelayTimer)))
   {
	   TOSStartTimer(&stStartDelayTimer);
   }

   if((mSERRead(U1Bit, IsStartupBatStable, Default)) || \
	  (TOSIsTimerElapsed(&stStartDelayTimer,mTOSConvMsInTimerTick(10UL))))
   {
       bRet = cTrue;
       TOSStopTimer(&stStartDelayTimer);
       //设置唤醒信号，后面要对这个信号读取，表示系统被唤醒
       TOSWriteSignal(cTOSSignalWakeUpRequested);
       mSERWrite(U1Bit, SysStartState, cTrue, Default);
   }
   else
   {
       bRet = cFalse;
   }

   return bRet;
}

