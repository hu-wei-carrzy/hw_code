
#ifndef I_LDB_TIM_H
#define I_LDB_TIM_H (1)

//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//
// #include <system_file_name.h>
// #include "project_file_name.h"
//------------------------------------------------------------------------------
//#include "ldb.h"
#include "ARCH_CFG.h"

#ifdef cHeadIncludeType_Directly
#include "LDB.h"
#include "BSP_TIM.h"
#else
#include ".\..\LDB_API\LDB.h"
#include ".\..\..\..\BSP\BSP_TIM\BSP_TIM.h"
#endif

#include "LDB_TIM_LIFE.h"

//------------------------------------------------------------------------------
// Data prefix for constant & data
//
// unsigned int {u8,u16,u32} / signed int {s8,s16,s32} 
// register size unsigned int {r} / float {f32,f64}  / s for struct 
// no prefix for other types.
//
//------------------------------------------------------------------------------
// Constant data
//
// #define cu16LAYCmpConstantName   ((U16) ConstantValueUL)
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Exported type
//
// typedef Expression tLAYCmpTypeName;
//------------------------------------------------------------------------------

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
#define mLDBTimConvUsInTick(Tps)  (((U32)(Tps) * 1000UL) / cLDBTick)
#define mLDBTimConvMsInTick(Tps)  (((U32)(Tps) * 1000000UL) / cLDBTick)

#define mLDBTIMInit()             LDBTimInit()

#define mLDBTIMControl(Ctrl)   LDBTimControl((Ctrl))
//------------------------------------------------------------------------------
// Exported functions
//
// extern tReturnType LAYCmpFunctionName(tTypeArgument1 ArgumentName1, ... );
//------------------------------------------------------------------------------
// Initialisation
extern void LDBTimInit(void);
extern void LDBTimControl(tCtrl);

#ifdef TOS_PERF_CNT_ENABLE
extern void LDBTimpInit(void);
#endif
// Time out management
//extern void LDBTimStart(void);
//extern void LDBTimStop(void);

extern void LDBTimStartLocalTimeOut(tTimerRef TimeOutRef, tDelay Duree);
extern void LDBTimStopLocalTimeOut(tTimerRef TimeOutRef);

#ifdef LDBTIM_USECHANGETIMEBASE
    // Stop LDB_TIM before calling this service
    extern void LDBTimChangeTimeBase(U8 u8TimeBase);
#endif

#ifdef LDBTIM_USE_SLOW_CLOCK
    // Stop LDB_TIM before calling this service
    extern void LDBTimChangeClock(BOOL bLocalUseFastClock);

    #ifdef LDBTIM_USE_SLOW_CLOCK_CALIBRATION
        extern void     LDBTimStartCalibration(void);
        extern void     LDBTimCancelCalibration(void);
        extern BOOL LDBTimIsCalibrationRunning(void);

        // This service returns the current correction in %
        // Warning : the correction is opposite of the error 
        // Example : when error is 75%, correction is 1/75% = 133,3 %
        extern U8   LDBTimGetCalibrationCorrectionPerCent(void);

        // Call-back
        extern void LDBSupCalibrationFinished(BOOL bCalibrationOk);
    #endif
#endif

//QACJ 0862: arozdik: contents of ldb_timp.h is used in files which include ldb_tim.h
#endif   /* I_LDB_TIM_H */
