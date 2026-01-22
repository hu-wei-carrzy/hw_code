

#ifndef I_DAT_EEP_CFG_H
#define I_DAT_EEP_CFG_H

//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//
// #include <system_file_name.h>
// #include "project_file_name.h"
//------------------------------------------------------------------------------
#include "ARCH_CFG.h"

#ifdef cHeadIncludeType_Directly
#include "DAT_EEPX.h"
#include "DAT_EEP_TYPE.h"
#else
#include "DAT_EEPx.h"
#include ".\..\DAT_EEP_TYPE.h"
#endif


//------------------------------------------------------------------------------
// Data prefix for constant & data: see coding guideline
//
//------------------------------------------------------------------------------
// Constant data
//
// #define cu16LAYCmpConstantName   ((U16) ConstantValueUL)
//------------------------------------------------------------------------------

// Process Handle
#define cDATEepProcessSupervisor   (tDATEepProcessHandle)(cDATEepNumberOfProcess-1U)

// Check the EEPROM specification. Default value is 2.
#define cDATEepPageSize         2
//A value upper than 2 active burst mode, for example :
//#define cDATEepPageSize         32

// Maximum number of write retry
#define cDATEepMaxWriteRetryNumber  (U16)5U

// Timeout ( Read or Write of 16 Bits )
#define cDATEepTimeoutLdbMs     200UL//old is 100UL
#define cDATEepPeriodAlarmUs    5000UL//old is 5000UL

//------------------------------------------------------------------------------
// Exported type
//
// typedef Expression tLAYCmpTypeName;
//------------------------------------------------------------------------------

//Must be adapted to the maximum size of a bank
//typedef U8 tDATEepOffset;

// Don't change the type of tDATEepProcessHandle.
// It must be U8
//typedef U8 tDATEepProcessHandle;

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

//------------------------------------------------------------------------------
// Exported Macros
//
// #define LAYCmpMacroName(...)   (MacroDefinition)
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Exported functions
//
// extern tReturnType LAYCmpFunctionName(tTypeArgument1 ArgumentName1, ... );
//------------------------------------------------------------------------------

// List of user's call-back
extern void DATDbkCallBackEep(tDATEepProcessHandle ProcessHandle, BOOL StatusOk);
extern void DATDeaCallBackEep(tDATEepProcessHandle ProcessHandle, BOOL StatusOk);
extern void DATSbkCallBackEep(tDATEepProcessHandle ProcessHandle, BOOL StatusOk);
extern void DATMrcCallBackEep(tDATEepProcessHandle ProcessHandle, BOOL StatusOk);
extern void DATObkCallBackEep(tDATEepProcessHandle ProcessHandle, BOOL StatusOk);

#endif   /* I_DAT_EEP_CFG_H */
