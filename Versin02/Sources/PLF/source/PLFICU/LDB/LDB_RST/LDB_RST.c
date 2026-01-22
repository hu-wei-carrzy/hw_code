
//-------------------------------------------------------------------------
//  Body Identification
//-------------------------------------------------------------------------


//-------------------------------------------------------------------------
//  Included files
//
//  #include <nom_du_ficher_systeme.h>
//  #include "nom_du_ficher_utilisateur.h"
//-------------------------------------------------------------------------
#include "ARCH_CFG.h"

#include "LDB_RST.h"

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
static  U32  u32MCUResetCause;

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
//=========================== EXPORTED FUNCTIONS ===============================
//==============================================================================

//==============================================================================
// DESCRIPTION : LDB RST initialization
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void LDBRstInit(void)
{
    // Read reset causes - register cleared when read
    u32MCUResetCause = BSPRstGetResetCause();
}
//==============================================================================
// DESCRIPTION : reset function
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void LDBRstReceiveWithoutAddr(tMsg * pMsg)
{
    if(((tMsg *)NULL != pMsg)&&((U8*)NULL != pMsg->pBuffer))
    {
        pMsg->pBuffer[0U] = (U8)(u32MCUResetCause>>0U);
        pMsg->pBuffer[1U] = (U8)(u32MCUResetCause>>8U);
        pMsg->pBuffer[2U] = (U8)(u32MCUResetCause>>16U);
        pMsg->pBuffer[3U] = (U8)(u32MCUResetCause>>24U);
    }
    else
    {
        mLIBassert(cFalse);
    }
}

