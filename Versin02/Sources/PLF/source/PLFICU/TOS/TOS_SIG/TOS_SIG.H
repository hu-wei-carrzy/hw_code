

#ifndef I_TOS_SIG_H
#define I_TOS_SIG_H

//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//------------------------------------------------------------------------------
#include "ARCH_CFG.h"

#ifdef cHeadIncludeType_Directly
#include "tos.h"
#else
#include ".\..\tos.h"
#endif

//------------------------------------------------------------------------------
// Constant data
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Exported type
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Exported data
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Constant exported data
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Exported Macros
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Exported functions
//------------------------------------------------------------------------------

//==============================================================================
// DESCRIPTION:         Initializes the TOS_SIG component
//
// PARAMETERS:          None
//
// RETURN VALUE:        None
//
// DESIGN INFORMATION:  Resets all events
//                      Refer to Detailed Design Document
//==============================================================================
void TOSSigInitialize( void );

//==============================================================================
// DESCRIPTION:         Reads a specific signal
//
// PARAMETERS:          SignalId    - Signal to be read
//
// RETURN VALUE:        cTrue when the given signal is set, else cFalse
//
// DESIGN INFORMATION:  Reads the state of requested signal in events' table.
//                      If signal's value is TRUE returns TRUE and resets it,
//                      otherwise returns FALSE.
//                      Refer to Detailed Design Document
//==============================================================================
BOOL TOSReadSignal(const tTOSSignalID SignalId );

//==============================================================================
// DESCRIPTION:         Writes a specific signal
//
// PARAMETERS:          SignalId    - Signal to be written
//
// RETURN VALUE:        None
//
// DESIGN INFORMATION:  Sets the state of requested signal in events' table.
//                      Refer to Detailed Design Document
//==============================================================================
void TOSWriteSignal(const tTOSSignalID SignalId );

#endif // I_TOS_SIG_H
