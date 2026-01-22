#ifndef _LDB_INT_CFG_
#define _LDB_INT_CFG_


#include "ARCH_CFG.h"
//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//
// #include <system_file_name.h>
// #include "project_file_name.h"
//------------------------------------------------------------------------------
#ifdef cHeadIncludeType_Directly

#else

#endif
//------------------------------------------------------------------------------
// Constant data
//
// #define cu16LAYCmpConstantName   ((U16) ConstantValueUL)
//------------------------------------------------------------------------------
#ifdef cLIBStkARMSpanish
#define __DI()                        __asm volatile ("cpsid i" : : : "memory");
#define __EI()                        __asm volatile ("cpsie i" : : : "memory");

#else 
#ifdef ( cLIBStkFujitsuSeries_Used)
//__EI() and __DI() will be recognized by compiler
#endif

#endif
//------------------------------------------------------------------------------
// Exported Macros
//
// #define LAYCmpMacroName(...)   (MacroDefinition)
//------------------------------------------------------------------------------

// -----------------------------
// Critical Isr Definition
// -----------------------------
// One interrupt is used by LDB_INT
// this interrupt allows to manages critical section
// choose an unused It

//#define cLDBIntCriticalIsr    INTKR

//Define also this lexeme to avoid multiple IT vector declaration

//#define cLDBIntCriticalIsrINTKR


// -----------------------------
// Custom Isr Priority
// -----------------------------
// They are already defined in the generated file ldb_intx.h
// but the value can be changed here.
// By default all priority are set to 6 (lower)
// Example : #define cLDBIntINTP0_Level    0

// By default all priority are set to 6
// Example :
//#define cLDBIntCAN0_Level    0
//->Put IT pririty for CAN 0 to 0 (max)

// Interrupt level for OS critical section
// In general this level is the higest level.
// If one interrupt must not be disable by OS critical section
// then, change the OSLevel. In this case, the interrupt must 
// not call OS services.
#define cLDBIntOSLevel  0

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
// Exported functions
//
// extern tReturnType LAYCmpFunctionName(tTypeArgument1 ArgumentName1, ... );
//------------------------------------------------------------------------------

#endif    /* I_LDB_INTP */
