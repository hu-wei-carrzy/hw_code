

//------------------------------------------------------------------------------
// Body Identification
//------------------------------------------------------------------------------
#define LDB_INT "LDB_INT"


//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//
// #include <system_file_name.h>
// #include "project_file_name.h"
//------------------------------------------------------------------------------
#include "ldb_int.h"

//------------------------------------------------------------------------------
// Local constants
//
// #define cConstantName   ((tType) ConstantValue)
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Local macros
//
// #define mMacroName   (MacroDefinition)
//------------------------------------------------------------------------------



#define cMaskILM ((U16)0xE000UL)
#define cShiftILM ((U8)13UL)

//------------------------------------------------------------------------------
// Local types
//
// typedef Expression    tTypeName;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Data prefix
//
// unsigned int {u8,u16,u32} / signed int {s8,s16,s32} 
// register size unsigned int {r} / float {f32,f64}  / s for struct 
//
// -----------------------------------------------------------------------------
// Local data
//
// static  tType   u8VariableName;  
// static  tType*  pu8VariableName; 
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Constant local data
//
// static const tType  VariableName;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Exported data
//
// tType   u8LAYCmpVariableName; (LAY: 3 characters to identify the layer)
// tType*  pu8LAYCmpVariableName;(Cmp: 3 characters to identify the component)
//------------------------------------------------------------------------------

#ifdef TRACE_CPU_ACTIVE
typedef unsigned int tLDBHandleCPU;
volatile tLDBHandleCPU  LDBHandleCPU;
#endif

//------------------------------------------------------------------------------
// Constant exported data
//
//             (LAY: 3 characters to identify the layer)
//             (Cmp: 3 characters to identify this component)
// 
// const tType   LAYCmpVariableName;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Local function prototypes
// 
// static tTypeRetour FunctionName(tTypeArgument1 ArgumentName1, ... );
//------------------------------------------------------------------------------

//==============================================================================
//=========================== LOCAL FUNCTIONS ==================================
//==============================================================================

//==============================================================================
// DESCRIPTION :
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
// static type FunctionName(...)
/*
#pragma asm
_GetPS
       PUSHW PS
       POPW (RW4)
       MOVW A, RW4
       RETP
#pragma endasm
*/

//==============================================================================
//=========================== EXPORTED FUNCTIONS ===============================
//==============================================================================


//==============================================================================
// DESCRIPTION : LDBIntGetInterruptLevel
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   U8 : Current level of the authorized interrupt
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
U8 LDBIntGetInterruptLevel(void)
{
	//TODO 更新寄存器值
    U16 RegPS_ILM = 0;//__get_CPSR();

    return ( ((U8) ((U16) (((U16)(RegPS_ILM & cMaskILM)) >> cShiftILM))));
}

//==============================================================================
// DESCRIPTION : LDBIntInit
//               Initialization of the component
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void LDBIntInit(void)
{
    //mLDBIntEnableIsr(cLDBIntCriticalIsr);
}

//==============================================================================
// DESCRIPTION : LDBIntInternalEnterCriticalSection
//               Entering into critical section, all interrupt with a lower pririty level
//               will be not serviced
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : the return of the programm pointer into the good address is
//                      realized into LDBIntInternalLeaveCriticalSection()
//==============================================================================
void LDBIntInternalEnterCriticalSection(U8 Level)
{
//#ifndef COMPILATION_NATIVE
//        Level |= ((U8)0x80UL);
//        while(1)
//        {
//            mGetIcr(cLDBIntCriticalIsr) = Level;
//        }//in case where several interrupt are pending, possible only
//        //if an interrupt with critical section occurs betwenn
//        // "Level |= ((U8)0x80UL);" and "mGetIcr(cLDBIntCriticalIsr) = Level;"
//#endif
}

//==============================================================================
// DESCRIPTION : LDBIntInternalLeaveCriticalSection
//               return into the previous interrupt priority level
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void LDBIntInternalLeaveCriticalSection(void)
{
//#ifdef _QAC_
//#else // #ifdef _QAC_
//    #pragma asm
//    stsr PSW,r2
//    di
//    ldsr r2,EIPSW
//    ldsr lp,EIPC
//    reti;
//    #pragma endasm
//#endif // #ifdef _QAC_
}


//==============================================================================
// DESCRIPTION : 
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
BOOL LDBIntReadItEnable(void)
{
    BOOL bState;
    //TODO 更新寄存器值
    U32 u32CPSR = 0;//__get_CPSR();
    
    bState = cTrue;

    if( ((u32CPSR & (cLDBIntAllIntFlagMask))) != 0)
    {
        bState = cFalse;
    }

    return (bState);
}

//==============================================================================
// DESCRIPTION : LDBIntUnexpectedInterrupt
//               Unexpected interrupt treatment
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
/*void __interrupt LDBIntUnexpectedInterrupt(void)
{
    LDBReset();
}*/


// End of ldb_int.c
