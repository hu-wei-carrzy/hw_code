#ifndef _LDB_TIM_CFG_H_
#define _LDB_TIM_CFG_H_

//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//
// #include <system_file_name.h>
// #include "project_file_name.h"
//------------------------------------------------------------------------------
#include "ARCH_CFG.h"

#ifdef cHeadIncludeType_Directly
#include "LDB.h"
#else
#include ".\..\LDB_API\LDB.h"
#endif
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

//************************
//  Timer configuration  
//************************

// The value of cLDBTick must be defined in HAL_CFG.h

// You must define this value with accordance to your Timer running period

//#define cLDBTimerSource  BT29_RT



//************************
//  TimeOut definitions  
//************************

/* EXTERNAL TIME OUT */
#define cLDBTimerNbr        ((U8)5UL)           // Number of timers
// number of TimeOut use by the DAT or TOS layer
#define cLDBTimNbOfExternalTimeOut cLDBTimerNbr
#define cLDBTimNbOfLocalTimeOut 0
// List of TimeOut
// the timeout must be defined in ldb_param.h

/* LOCAL TIME OUT */
// Number of TimeOut used by LDB layer

// List of TimeOut
//  #define cLDBTimLocalTimeOut1 ((tTimerRef)0x00)
//   #define cLDBTimLocalTimeOut2 ((tTimerRef)0x01)

// Startup initialisation parameters for RLT
//#define RLT_RELOAD_VALUE     6250 // 0.2us*6250=1.25ms



// LIST OF CALLBACK ON TIMEOUT
extern void TOSAlaCallBackTimer(void);
/* define the external callback and next the LDB callback */
#define cLDBTimTimeOutCallBackList   \
            {                      \
             /*define here the callback used by the TOS*/     \
            TOSAlaCallBackTimer , /* reserved for the TOS Tick*/    \
            /*define here the callback used by the DAT layer*/\
            /*LDBMtxStateMachine*/     \
            /*define here the callback used by the LDB layer*/\
            \
            }

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

//************************
//  Timer configuration  
//************************

// For customisation of LDB_TIM, see LDB_TIM documentation

#define mLDBTimSelectFastClock() mLDBIocSetDefaultConfiguration(cLDBHarRealTimeTimer)
#define cLDBTimFastClockTickNs   mLDBIocGetDefaultTickNs(cLDBHarRealTimeTimer)

// Let or remove this define :
//#define LDBTIM_USECHANGETIMEBASE

// Let or remove this define :
//#define LDBTIM_USE_SLOW_CLOCK

#ifdef LDBTIM_USE_SLOW_CLOCK
    #define mLDBTimSelectSlowClock() mLDBIocSetTickNs(cLDBHarRealTimeTimer,cLDBTimSlowClockTickNs)
    #define cLDBTimSlowClockTickNs  10000 // 10 us

    // Let or remove this define :
    //#define LDBTIM_USE_SLOW_CLOCK_CALIBRATION

    #ifdef LDBTIM_USE_SLOW_CLOCK_CALIBRATION
        #define cLDBTimCalibrationTimer T1
        #define cLDBTimCalibrationDurationNs 20000000UL // 100 ms
        #define cLDBTimMaxDeviation 150 // Max calibration deviation in %
        #define cLDBTimMinDeviation 67  // Min calibration deviation in %
        #define cLDBTimCalibrationTimerTickInNs 2500 // 2.5 us

        // Let or remove this define :
        //#define LDBTIM_CALIBRATION_ON_FAST_CLOCK_MODE
    #endif
#endif


//------------------------------------------------------------------------------
// Exported functions
//
// extern tReturnType LAYCmpFunctionName(tTypeArgument1 ArgumentName1, ... );
//------------------------------------------------------------------------------


extern void TOSAlaCallBackTimer(void);
extern void DATAnaGetADValAndSwitchChannel(void);


#endif   /* I_LDB_TIMP_H */
