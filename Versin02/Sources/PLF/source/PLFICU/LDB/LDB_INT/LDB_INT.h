

#ifndef I_LDB_INT_H
#define I_LDB_INT_H

#ifdef _QAC_
#include "deftypes.h"
#endif // #ifdef _QAC_

//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//
// #include <system_file_name.h>
// #include "project_file_name.h"
//------------------------------------------------------------------------------
#include "ARCH_CFG.h"

#ifdef cHeadIncludeType_Directly
#include "LDB_INT_CFG.h"
#include "ldb.h"
#else
#include "LDB_INT_CFG.h"
#include ".\..\LDB\LDB_API\ldb.h"
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

// Parameters for mLDBIocSetEdgeDetection
#define cLDBIntLowLevelDetection    ((U8)0x00UL)
#define cLDBIntHighLevelDetection   ((U8)0x01UL)
#define cLDBIntRisingEdge           ((U8)0x02UL)
#define cLDBIntFallingEdge          ((U8)0x03UL)

#define cLDBIntMinLevel ((U8)7UL)
#define cLDBIntMaxLevel ((U8)0UL)


//the I flag(interrupt enabe /disable flag) and F flag(fast interrupt enable / disabel flag)
//are different for each MCU, so you have to change the value by each MCU.
#ifdef cLIBStkARMSpanish
#define cLDBIntIFlagPos    ((U32)0X07)
#define cLDBIntFFlagPos    ((U32)0X06)

#define cLDBIntIFlagMask   ((U32)(1<<cLDBIntIFlagPos))
#define cLDBIntFFlagMask   ((U32)(1<<cLDBIntFFlagPos))

#define cLDBIntAllIntFlagMask (cLDBIntIFlagMask | cLDBIntFFlagMask)

#else
//define other CPU flag pos
#endif

//------------------------------------------------------------------------------
// Exported Macros
//
// #define LAYCmpMacroName(...)   (MacroDefinition)
//------------------------------------------------------------------------------

// Interrupt manager services
#define mLDBIntEnterCriticalSection(Level)                  \
            mLIBassert(LDBIntGetInterruptLevel() > Level ); \
            mLIBassert( LDBIntReadItEnable() != cFalse );   \
            LDBIntInternalEnterCriticalSection(Level)

#define mLDBIntLeaveCriticalSection()      LDBIntInternalLeaveCriticalSection()
#define mLDBIntGetMaxLevel(Level1,Level2)  (((Level1) < (Level2)) ? (Level1) : (Level2))

#define mLDBIntEnableAllIts()    __EI()
#define mLDBIntDisableAllIts()   __DI()



//------------------------------------------------------------------------------
// Exported type
//
// typedef Expression tLAYCmpTypeName;
//------------------------------------------------------------------------------
typedef U32 tLDBIntLevel;

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
// Exported functions
//
// extern tReturnType LAYCmpFunctionName(tTypeArgument1 ArgumentName1, ... );
//------------------------------------------------------------------------------
//extern void __interrupt LDBIntUnexpectedInterrupt(void);

extern U8 LDBIntGetInterruptLevel(void);
extern BOOL GetIsrRequestFlag(U8 ICRReg);
extern U8 LDBIntInternalGetIsrCurrentLevelFunction (U8 IndexICR);
extern BOOL LDBIntReadItEnable(void);
extern void LDBIntInternalEnterCriticalSection(U8 Level);
extern void LDBIntInternalLeaveCriticalSection(void);
extern void LDBIntInit(void);
#endif   /* I_LDB_INT_H */
