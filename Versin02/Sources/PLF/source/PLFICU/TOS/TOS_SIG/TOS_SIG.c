
//------------------------------------------------------------------------------
// Body Identification
//------------------------------------------------------------------------------
#define TOS_SIG "TOS_SIG"

//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//------------------------------------------------------------------------------
#include "ARCH_CFG.h"

#ifdef cHeadIncludeType_Directly
#include "tos_sig.h"
#include "LIB.h"
#include "JIL.h"
#else
#include "tos_sig.h"
#include ".\..\..\LIB\LIB_API\LIB.h"
#include ".\..\..\SCC2Gen\Gen\JIL.h"
#endif
//------------------------------------------------------------------------------
// Local constants
//------------------------------------------------------------------------------
#define cSizeEventTable         ((cTOSSigMaxSignalNumber + 7UL) / 8UL)
#define cNoEvent                0

//------------------------------------------------------------------------------
// Local macros
//------------------------------------------------------------------------------
#define mGetIndex( SignalID )   ( (SignalID) >> 3 )
#define mGetMask( SignalID )    ( (U8) ( (U8)1 << ((SignalID) & 7) ) )

//------------------------------------------------------------------------------
// Local types
//------------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Local data
//------------------------------------------------------------------------------
static U8 u8EventTable[cSizeEventTable];    // container for events

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
void TOSSigInitialize( void )
{
    mLIBmemset( u8EventTable, cNoEvent, sizeof(u8EventTable) );
}

//==============================================================================
// DESCRIPTION:         See component header file
//==============================================================================
BOOL TOSReadSignal(const tTOSSignalID SignalId )
{
    BOOL bActiveSignal;

    if (SignalId < (tTOSSignalID)cTOSSigMaxSignalNumber)
    {
        U16 u16Index = mGetIndex(SignalId);
        U8 u8Mask  = mGetMask(SignalId);
        U8 u8MaskInv = (U8)~u8Mask;

        TOSSuspendOSInterrupts();
        if( (u8EventTable[ u16Index ] & u8Mask) != 0 )
        {
            u8EventTable[ u16Index ] &= u8MaskInv;
            bActiveSignal = cTrue;
        }
        else
        {
            bActiveSignal = cFalse;
        }
        TOSResumeOSInterrupts();
    }
    else
    {
        mLIBassert(cFalse);
        bActiveSignal = cFalse;
    }

    return bActiveSignal;
}

//==============================================================================
// DESCRIPTION:         See component header file
//==============================================================================
void TOSWriteSignal(const tTOSSignalID SignalId )
{
    if (SignalId < (tTOSSignalID)cTOSSigMaxSignalNumber)
    {
        U16 u16Index = mGetIndex(SignalId);
        U8 u8Mask  = mGetMask(SignalId);

        TOSSuspendOSInterrupts();
        u8EventTable[ u16Index ] |= u8Mask;
        TOSResumeOSInterrupts();
    }
    else
    {
        mLIBassert(cFalse);
    }
}
