
//------------------------------------------------------------------------------
// Body Identification
//------------------------------------------------------------------------------
#define TOS_TPO2 "TOS_TPO2"

//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//------------------------------------------------------------------------------
#include "ARCH_CFG.h"

#ifdef cHeadIncludeType_Directly
#include "tos_tpo.h"
#include "tos.h"
#include "LIB.h"
#else
#include "tos_tpo.h"
#include ".\..\tos.h"
#include ".\..\..\LIB\LIB_API\LIB.h"
#endif
//------------------------------------------------------------------------------
// Local constants
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Local macros
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Local types
//------------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Local data
//------------------------------------------------------------------------------

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
void TOSStartPeriodicTimer_Internal (tTOSPeriodicTimer* const pTimer,const tTOSTimer Delay)
{
    if (pTimer != NULL)
    {
#ifdef TOS_PREEMPTIVE
        TOSGetSchedulerResource(); //if TOS is preemptive - disable preemption 
#endif
        
        // A delay value equal to 0 means that the first "Elapsed event" 
        // will occurs at the first call of TOSIsPeriodicTimerElapsed(). 
        // In this case the delay beetwen the first and second "Elapsed event"
        // will not be exactly equal to the Period.
        // So it is advise to set Delay to a value not equal to 0.
        
        // This implementation don't manage cases when Delay is greater than
        // Period
        mLIBassert( Delay <= pTimer->Period );
        
        pTimer->StartDate = (tTOSClock)(TOSClock + (Delay - pTimer->Period) );
        
        // The value 0 is not used and must be "jumped".
        // If the value 0 is between pTimer->StartDate and TOSClock
        // then : StartDate must shifted of 1
        if( (tTOSClock)(pTimer->StartDate-1) > TOSClock )
        {
            pTimer->StartDate --;
        }
#ifdef TOS_PREEMPTIVE
        TOSReleaseSchedulerResource(); //if TOS is preemptive - release the resource 
#endif
    }
}

//==============================================================================
// DESCRIPTION:         See component header file
//==============================================================================
void TOSStopPeriodicTimer (tTOSPeriodicTimer* const pTimer)
{
    if (pTimer != NULL)
    {
#ifdef TOS_PREEMPTIVE
        TOSGetSchedulerResource(); //if TOS is preemptive - disable preemption 
#endif
    
        pTimer->StartDate = 0;
    
#ifdef TOS_PREEMPTIVE
        TOSReleaseSchedulerResource(); //if TOS is preemptive - release the resource 
#endif
    }
}

//==============================================================================
// DESCRIPTION:         See component header file
//==============================================================================
BOOL TOSIsPeriodicTimerStarted ( const tTOSPeriodicTimer* const pTimer)
{
    BOOL bPeriodicTimerStarted  = cFalse;

    if (pTimer != NULL)
    {
        // This function must not be called in an interrupt context.
#ifdef TOS_PREEMPTIVE
        TOSGetSchedulerResource(); //if TOS is preemptive - disable preemption 
#endif

        // A timer is never equal to 0
        // The 0 value is reserved to the timer stoped
        if (pTimer->StartDate != 0)
        {
            bPeriodicTimerStarted = cTrue;
        }

#ifdef TOS_PREEMPTIVE
        TOSReleaseSchedulerResource(); //if TOS is preemptive - release the resource 
#endif
    }

    return bPeriodicTimerStarted;
}

//==============================================================================
// DESCRIPTION:         See component header file
//==============================================================================
BOOL TOSIsPeriodicTimerElapsed (tTOSPeriodicTimer* const pTimer)
{
    BOOL bPeriodicTimerElapsed = cFalse;
    tTOSTimer Delay;

    if (pTimer != NULL)
    {
        // This function must not be called in an interrupt context.
#ifdef TOS_PREEMPTIVE
        TOSGetSchedulerResource(); //if TOS is preemptive - disable preemption
#endif
        // A timer is never equal to 0
        // The 0 value is reserved to the timer stoped
        if( pTimer->StartDate != 0 )
        {
            Delay = (tTOSTimer)(TOSClock - pTimer->StartDate);
            
            if( TOSClock < pTimer->StartDate )
            {
                // The 0 value had been "jump" so we must substact 1 to the delay
                Delay -- ;
            }
            
            if( Delay >= pTimer->Period )
            {
                // If timer is elapsed it must be re-started
                tTOSTimer LocalStartDate;
                LocalStartDate = (tTOSTimer)(pTimer->StartDate + pTimer->Period);
                if( LocalStartDate < pTimer->StartDate )
                {
                    LocalStartDate++;
                }
                pTimer->StartDate = LocalStartDate;
                bPeriodicTimerElapsed = cTrue;
            }
        }

#ifdef TOS_PREEMPTIVE
        TOSReleaseSchedulerResource(); //if TOS is preemptive - release the resource 
#endif
    }

    return bPeriodicTimerElapsed;
}

