#ifndef _QAC_
//**********************************************************************************************************************
// Company:      Johnson Controls Inc.
// ---------------------------------------------------------------------------------------------------------------------
// Copyright:    This software is JCI property.
//               Duplication or disclosure without JCI written authorization  is prohibited.
// ---------------------------------------------------------------------------------------------------------------------
// Project:      STANDARD
// Language:     ANSI-C
// ---------------------------------------------------------------------------------------------------------------------
// Component:    LAP_SUP.h
//               <Comments about the component (role, algorithm, structure, limitations, defined tasks and events...)>
// ---------------------------------------------------------------------------------------------------------------------
//
//**********************************************************************************************************************
#endif

#ifndef I_LAP_SUP_H
#define I_LAP_SUP_H (1)

//----------------------------------------------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//----------------------------------------------------------------------------------------------------------------------
#include "ARCH_CFG.h"


#include "LAP_SUP_INCLUDE.h"


//----------------------------------------------------------------------------------------------------------------------
// Constant data
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
// Exported type
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
// Exported data
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
// Constant exported data
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
// Exported Macros
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
// Exported functions
//----------------------------------------------------------------------------------------------------------------------

extern void LAPSupActiveSleepRequest( void );
extern void LAPSupWakeUpRequest( void );

#endif   // I_LAP_SUP_H
extern BOOL LAPSupActiveSleepRequested(void);
extern void LAPSupControlDATEnterActiveState(void);extern void LAPSupControlEnterStartingStepState(void);extern void LAPSupControlLAPEnterActiveState(void);extern void LAPSupControlLeaveActiveState(void);extern void LAPSupControlLeaveStartingStepState(void);extern void LAPSupEnterSleep(void);extern BOOL LAPSupIsSysStable(void);
extern void LAPSupMinimumActiveTime(void);extern BOOL LAPSupMinimumActiveTimeIsElapsed(void);
extern BOOL LAPSupNobodyMaintainActiveSleepState(void);
extern BOOL LAPSupNobodyMaintainActiveState(void);
extern BOOL LAPSupNobodyMaintainStartingStepState(void);
extern BOOL LAPSupWakeUpRequested(void);
extern void TOSSeqNoAction(void);extern BOOL TOSSeqTrueEval(void);
