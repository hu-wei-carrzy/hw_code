

#ifndef I_LDB_H
#define I_LDB_H

/*-------------------------------------------------------------------------
  Included files to resolve specific definitions in this file

  #include <system_file_name.h>
  #include "project_file_name.h"
  -------------------------------------------------------------------------*/
#include "ARCH_CFG.h"

#ifdef cHeadIncludeType_Directly
#include "DefTypes.h"
#include "ldbtypes.h"
#include "LDB_COMMON.h"
#else
#include ".\..\..\LIB\LIB_API\DefTypes.h"
#include "ldbtypes.h"
#include ".\..\LDB_COMMON\LDB_COMMON.h"
#endif
/*-------------------------------------------------------------------------
  Constant data

  #define cCMPConstantName   ((tType) ConstantValue)
  -------------------------------------------------------------------------*/

//Status value common for all channel
#define cLDBCorrect        ((tStatus)0x00U)    // Control correctly done
#define cLDBError          ((tStatus)0x01U)    // Unknown control or not realized

/*-------------------------------------------------------------------------
  Exported Macro

  #define mCMPMacroName   (MacroDefinition)
  -------------------------------------------------------------------------*/ 

#define mLDBSimulateProcessingTime(x) mLDBPARAM_SIMULATE_PROCESSING_TIME_MACRO((x))
#define mLDBTrace( Text )            mLDBPARAM_TRACE_MACRO( (Text) )




/*-------------------------------------------------------------------------
  Exported data

  extern  tType   CMPVariableName;
  extern  tType*  pCMPVariableName; 
  -------------------------------------------------------------------------*/ 

/*-------------------------------------------------------------------------
  Constant exported data

  extern const tType  CMPVariableName;
  -------------------------------------------------------------------------*/ 

/*-------------------------------------------------------------------------
  Exported functions

  extern tReturnType CMPFunctionName(tTypeArgument1 ArgumentName1, ... );
  -------------------------------------------------------------------------*/ 


extern tDelay LDBStopTimer         ( tTimerRef );
extern void   LDBStartTimer        ( tTimerRef, tpFunct, tDelay, BOOL );


// Performance Counter high resolution timer
#ifdef TOS_PERF_CNT_ENABLE
extern U32 LDBTimPerfCntGetTime(void);
#endif

// Watch dog refresh
extern void LDBRefreshWatchDog ( void );

extern void LDBReset           ( void );
extern void LDBSWReset         ( void );
extern void LDBInit            ( void );

extern void LDBEnterSleepMode  ( void );
extern void LDBLeaveSleepMode  ( void );
extern void LDBWaitForCallBack ( void );


extern void LDBSendWithAddr      (tChannel Channel, tAddress Ad, tMsg* Msg );
extern void LDBPrepareSendWithAddr(tChannel Channel, tAddress Ad, tMsg* Msg);
extern void LDBReceiveWithAddr    (tChannel Channel, tAddress Ad, tMsg* Msg );

extern void LDBSendWithoutAddr      (tChannel Channel, tMsg* Msg );
extern void LDBPrepareSendWithoutAddr(tChannel Channel, tMsg* Msg );
extern void LDBReceiveWithoutAddr    (tChannel Channel, tMsg* Msg );

extern void LDBControl       (tChannel Channel, tCtrl Ctrl);
extern void LDBEnableCallBack(tChannel Channel, BOOL CallBackEnabled );


/*--------------------------------------------------------------------------*/
/*-------  Definitions des canaux propres a cette implementation  ----------*/
/*--------------------------------------------------------------------------*/



/*-------------------------------------------------------------------------
  End of includes non re entry
  -------------------------------------------------------------------------*/
#endif   /* I_LDB_H */

