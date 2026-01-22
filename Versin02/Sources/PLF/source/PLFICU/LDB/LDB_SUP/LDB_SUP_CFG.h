

#ifndef  _LDB_SUP_CFG_H_
#define  _LDB_SUP_CFG_H_


//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//
// #include <system_file_name.h>
// #include "project_file_name.h"
//------------------------------------------------------------------------------

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
//WD      = 0    -> WD enabled
//RSTP    = 0    -> No WD Reset at transition to Stop
//WTCS1,0 = 00   -> CLKRC (RC clock can be changed during WD operation)
//WTI3-0  = 1110 -> ~ 2,1s (RC clock = 2MHz)
#define cLDBSupWDTCConfigValue    (U8)(0x2FU)
#define cLDBSupWDTCDisableValue   (U8)(0x80U)

//WTWE    = 0    -> WD Timer Window function disabled
//WTLI3-0 = 0000 -> lower limit interval has no sense when WTWE = 0
#define cLDBSupWDTECConfigValue   (U8)(0x00U)

//------------------------------------------------------------------------------
// Exported Macros
//
// #define LAYCmpMacroName(...)   (MacroDefinition)
//------------------------------------------------------------------------------

#if defined(SIR_METRICS) && defined(START_WAKEUP_METRICS)
#define mSupWakeupTraceBegin()                                                 \
    mLDBHarConfig(cLDBHarPinSIRMetrics, cLDBHarOutput);                        \
    mLDBHarWrite(cLDBHarPinSIRMetrics, 1)
#define mSupWakeupTraceEnd()                                                   \
    mLDBHarWrite(cLDBHarPinSIRMetrics, 0);
#define mSupStartupTraceEnd()                                                  \
    mLDBHarConfig(cLDBHarPinSIRMetrics, cLDBHarOutput);                        \
    mLDBHarWrite(cLDBHarPinSIRMetrics, 1)
#else
#define mSupWakeupTraceBegin()
#define mSupWakeupTraceEnd()
#define mSupStartupTraceEnd()
#endif // START_WAKEUP_METRICS && SIR_METRICS
#ifdef TRACE_CPU_ACTIVE
#define mSupWaitForCallback()                                                  \
    while (                                                                    \
            /* put here pending flags of all system interrupts!!! */           \
            (CAN0_INTR0 == 0) &&    /* CAN */                                  \
            (TMCSR0_UF == 0) &&     /* RLT0 */                                 \
            (TMCSR2_UF == 0) &&     /* RLT2 */                                 \
            (SG0_SGCR0_INT == 0) && /* SG0 */                                  \
            (WT_WTCR_INT1 == 0) &&  /* RTC0 */                                 \
            (UART1_SSR1_RDRF == 0) &&  /* LINR1 */                             \
            (IIC0_IBCR0_INT == 0)   /* IIC0 */                                 \
          )
#else
#define mSupWaitForCallback()
#endif
//------------------------------------------------------------------------------
// Exported functions
//
// extern tReturnType LAYCmpFunctionName(tTypeArgument1 ArgumentName1, ... );
//------------------------------------------------------------------------------

#endif   /* I_SUP_P */
