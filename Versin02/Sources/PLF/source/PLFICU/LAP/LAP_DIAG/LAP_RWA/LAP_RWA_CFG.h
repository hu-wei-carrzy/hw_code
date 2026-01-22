//******************************************************************************
// Company:      Johnson Controls Inc.
// -----------------------------------------------------------------------------
// Copyright:    This software is JCI property.
//               Duplication or disclosure without JCI written authorization
//               is prohibited.
// -----------------------------------------------------------------------------
// Project:      <PROJECT>
// Language:     ANSI-C
// -----------------------------------------------------------------------------
// Component:    <Comments about the component (role, algorithm, structure, 
//               limitations, defined tasks and events...)>
// -----------------------------------------------------------------------------
// $Date:   Jan 17 2014 18:20:34  $
// $Archive:   //DI_JMC_N330_IC/archives/1016282/DEV/BUILD/SOURCES/LAP_RWAP.h-arc  $
// $Revision:   1.0  $
// -----------------------------------------------------------------------------
/* $Log:   //DI_JMC_N330_IC/archives/1016282/DEV/BUILD/SOURCES/LAP_RWAP.h-arc  $
 * 
 *    Rev 1.0   Jan 17 2014 18:20:34   aluant
 * Initial revision.
 // 
 //    Rev 1.0   Dec 30 2010 16:29:08   aliuz0
 // Initial revision.
 * 
 *    Rev 1.0   Apr 17 2008 10:35:00   amonniy
 * Initial revision.
 * 
*/
//******************************************************************************

#ifndef I_LAP_RWAp_H
#define I_LAP_RWAp_H (1)

//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//
// #include <system_file_name.h>
// #include "project_file_name.h"
//------------------------------------------------------------------------------
#include "ARCH_CFG.h"
#ifdef cHeadIncludeType_Directly
#include "LAP_DEPENDCY.h"
#else
#include ".\..\..\LAP_DEPENDCY.h"
#endif

//------------------------------------------------------------------------------
// Data prefix for constant & data: see coding guideline
//
//------------------------------------------------------------------------------
// Constant data
//
// #define cu16LAYCmpConstantName   ((U16) ConstantValueUL)
//------------------------------------------------------------------------------
// For the writing locking function, LOCK_FUNCTION_ENABLE must be defined
// else LOCK_FUNCTION_ENABLE must be commented
#ifdef I_ENV_DIA_H /*for UTEST*/
    #define LOCK_FUNCTION_ENABLE
#else
    //#define LOCK_FUNCTION_ENABLE
#endif


// defined the size of MemoryAddress = 24 or 32 bits => 3 or 4 bytes
#ifdef cLIBStkDatCanConfig_PsaBody
#define cSizeOfMemoryAddressInBytes   4
#else
#define cSizeOfMemoryAddressInBytes   4
#endif


// defined the size of MemorySize = 1 or 2 bytes
#ifdef cLIBStkDatCanConfig_PsaBody
#define cSizeOfMemorySizeInBytes   2
#else
#define cSizeOfMemorySizeInBytes   2
#endif

#define cU16RAMSize           ((U16)0XC000)
#define cU8MaxEEPTaskCalling  ((U8)20U)

//------------------------------------------------------------------------------
// Exported type
//
// typedef Expression tLAYCmpTypeName;
//------------------------------------------------------------------------------
#ifdef LOCK_FUNCTION_ENABLE
    typedef U32 tLockCode;
#endif

//------------------------------------------------------------------------------
// Exported data
//
// extern  tType   u8LAYCmpVariableName;
// extern  tType*  ps32LAYCmpVariableName; 
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Constant exported data
//
// extern const tType  s8LAYCmpVariableName;
//------------------------------------------------------------------------------
#ifdef LOCK_FUNCTION_ENABLE
    // This is the code to unlock the memory writing
    extern const tLockCode cLockCode;
#endif


//------------------------------------------------------------------------------
// Exported Macros
//
// #define LAYCmpMacroName(...)   (MacroDefinition)
//------------------------------------------------------------------------------
#ifdef LOCK_FUNCTION_ENABLE
    // This is the data of the request to compare with cLockCode
    #define mUnlockData()                                                                                                   \
        ( ((tLockCode)(LAPDiaMemorizedRequest.Buffer[6 + 1]) << 24)    \
        + ((tLockCode)(LAPDiaMemorizedRequest.Buffer[6 + 2]) << 16)    \
        + ((tLockCode)(LAPDiaMemorizedRequest.Buffer[6 + 3]) <<  8)    \
        + ((tLockCode)(LAPDiaMemorizedRequest.Buffer[6 + 4])      )  )
#endif



// Macro which filter the address on reading
// This is an address filter to avoid incidents
#ifdef I_ENV_DIA_H /*for UTEST*/
    // This is only for testing the condition on UTEST
    #define mIsAddressAuthorizedInReading() (LAPDiaMemorizedRequest.Buffer[2] != (U8)0xFFUL) 
#else
    #define mIsAddressAuthorizedInReading() cTrue
#endif


// Macro which filter the address on writing
#ifdef I_ENV_DIA_H /*for UTEST*/
    #define mIsAddressAuthorizedInWriting() (LAPDiaMemorizedRequest.Buffer[2] != (U8)0xFFUL)
#else
    #define mIsAddressAuthorizedInWriting() cTrue
#endif



//------------------------------------------------------------------------------
// Exported functions
//
// extern tReturnType LAYCmpFunctionName(tTypeArgument1 ArgumentName1, ... );
//------------------------------------------------------------------------------

#endif   /* I_LAP_RWAp_H */
