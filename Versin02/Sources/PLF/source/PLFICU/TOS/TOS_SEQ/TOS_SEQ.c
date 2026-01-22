
//------------------------------------------------------------------------------
// Body Identification
//------------------------------------------------------------------------------
#define TOS_SEQ "TOS_SEQ"

//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//------------------------------------------------------------------------------
#include "ARCH_CFG.h"

#ifdef cHeadIncludeType_Directly
#include "tos_seq.h"
#include "tos_ord.h"
#include "lib.h"
#include "LDB.h"
#include "HAL_CFG.h"
#else
#include "tos_seq.h"
#include ".\..\TOS_ORD\tos_ord.h"
#include ".\..\..\LIB\LIB_API\lib.h"
#include ".\..\..\LDB\LDB_API\LDB.h"
#include ".\..\..\HAL\HAL_CFG.h"
#endif
//------------------------------------------------------------------------------
// Local constants
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Local macros
//------------------------------------------------------------------------------
#ifdef COMPILATION_NATIVE
    #define mDbgSeqMotor()\
        if( pfDbgSeqMotor!=NULL) pfDbgSeqMotor()

    #define mDbgActivateGraph(ID)                   \
        if(pfDbgActivateGraph!=NULL)                \
        {                                           \
            if( pfDbgActivateGraph(ID) )            \
            {                                       \
                DbgDebugBreak();                    \
            }                                       \
        }

    #define mDbgDeactivateGraph(ID)                 \
        if(pfDbgDeactivateGraph!=NULL)              \
        {                                           \
            if( pfDbgDeactivateGraph(ID) )          \
            {                                       \
                DbgDebugBreak();                    \
            }                                       \
        }

    #define mDbgFreezeGraph(ID)                     \
        if(pfDbgFreezeGraph!=NULL)                  \
        {                                           \
            if( pfDbgFreezeGraph(ID) )              \
            {                                       \
                DbgDebugBreak();                    \
            }                                       \
        }

    #define mDbgUnfreezeGraph(ID)                   \
        if(pfDbgUnfreezeGraph!=NULL)                \
        {                                           \
            if( pfDbgUnfreezeGraph(ID) )            \
            {                                       \
                DbgDebugBreak();                    \
            }                                       \
        }

    #define mDbgChangeGrapheRule(ID,Rule)           \
        if(pfDbgChangeGrapheRule!=NULL)             \
        {                                           \
            if( pfDbgChangeGrapheRule(ID,Rule) )    \
            {                                       \
                DbgDebugBreak();                    \
            }                                       \
        }
#elif defined (_QAC_)
extern void NOP(void);
    #define mDbgInit()                          NOP()
    #define mDbgSeqMotor()                      NOP()
    #define mDbgActivateGraph(ID)               NOP()
    #define mDbgDeactivateGraph(ID)             NOP()
    #define mDbgFreezeGraph(ID)                 NOP()
    #define mDbgUnfreezeGraph(ID)               NOP()
    #define mDbgChangeGrapheRule(ID,Rule)       NOP()
#else
    #define mDbgInit()
    #define mDbgSeqMotor()
    #define mDbgActivateGraph(ID)
    #define mDbgDeactivateGraph(ID)
    #define mDbgFreezeGraph(ID)
    #define mDbgUnfreezeGraph(ID)
    #define mDbgChangeGrapheRule(ID,Rule)
#endif

//------------------------------------------------------------------------------
// Local types
//------------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Local data
//------------------------------------------------------------------------------
static tTOSSeqGraphContextType TOSSeqGraphContext[cTOSSeqGraphNumber];

//------------------------------------------------------------------------------
// Constant local data
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Exported data
//------------------------------------------------------------------------------
tTOSSeqGraphId TOSSeqGraphNumber;

//------------------------------------------------------------------------------
// Constant exported data
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Local function prototypes
//------------------------------------------------------------------------------
#ifdef COMPILATION_NATIVE
//==============================================================================
// DESCRIPTION:         Avoids masking of the last function by the debugbreak 
//                      execution.
//
// PARAMETERS:          None
//
// RETURN VALUE:        None
//
// DESIGN INFORMATION:  Calls debugbreak function.
//                      Refer to Detailed Design Document
//==============================================================================
static void DbgDebugBreak(void);
#endif

//==============================================================================
// DESCRIPTION:         Tests all sister's transitions of the graph and executes
//                      corresponding actions.
//
// PARAMETERS:          None
//
// RETURN VALUE:        None
//
// DESIGN INFORMATION:  Tests all sister's transitions of the current graph one
//                      after the other. When one returns TRUE executes the
//                      corresponding action and stops testing the other sister's
//                      rules. If there is no daughter's rule, deactivates the graph.
//                      Refer to Detailed Design Document
//==============================================================================
static void ScanGraph(void);

//==============================================================================
//=========================== LOCAL FUNCTIONS ==================================
//==============================================================================

#ifdef COMPILATION_NATIVE
static void DbgDebugBreak(void)
{
    pfDebugBreak();
}
#endif

static void ScanGraph(void)
{
    const tTOSSeqRuleType* pRule;
#ifdef COMPILATION_NATIVE         // For debug mode, save the rule number
    tTOSSeqRuleId RuleNumber;
#endif

    mLIBassert(TOSSeqGraphNumber < cTOSSeqGraphNumber);

#ifdef COMPILATION_NATIVE
    RuleNumber = TOSSeqGraphContext[TOSSeqGraphNumber].RuleNumber;
    pRule = TOSSeqGraphList[TOSSeqGraphNumber]->Rules
            //QACJ 0488: amanevm: Use of pointer arithmetic is needed 
            + TOSSeqGraphContext[TOSSeqGraphNumber].RuleNumber;
#else
    pRule = *TOSSeqGraphList[TOSSeqGraphNumber]
            //QACJ 0488: amanevm: Use of pointer arithmetic is needed 
            + TOSSeqGraphContext[TOSSeqGraphNumber].RuleNumber;
#endif
    // Polyspace justification: amanevm:
    // This loop ends because we have at least one rule and we do not have loop of rules. 
    // All pointers are valid because they are statically linked
    do
    {
        BOOL bResult = (*pRule->pTransition)();
        if ( bResult != cFalse)
        {
#ifdef COMPILATION_NATIVE
            mDbgChangeGrapheRule(TOSSeqGraphNumber,RuleNumber);
            // When GraphDesigner break the application, you are in the DLL
            // For exit to the DLL, place a breakpoint in front of (*ptRegle->ptAction)();
            // and continue the application by 'F5' key press.
            // Now you can debug your application just before execute the action.
#endif
            (*pRule->pAction)();

            if (pRule->DaughterRuleNumber != cTOSSeqInvalidRule)
            {
                TOSSeqGraphContext[TOSSeqGraphNumber].RuleNumber = pRule->DaughterRuleNumber;
            }
            else    // End of graph
            {
                mDbgDeactivateGraph(TOSSeqGraphNumber);
                TOSSeqGraphContext[TOSSeqGraphNumber].GraphState  = cTOSSeqInactiveGraph;
                TOSSeqGraphContext[TOSSeqGraphNumber].RuleNumber  = 0 ;
            }
            pRule = NULL;     // Condition for exit loop
        }
        else if ( pRule->SisterRuleNumber != cTOSSeqInvalidRule )
        {
#ifdef COMPILATION_NATIVE                   // For debug mode, save the rule number
            RuleNumber = pRule->SisterRuleNumber;
            pRule = TOSSeqGraphList[TOSSeqGraphNumber]->Rules
                    //QACJ 0488: amanevm: Use of pointer arithmetic is needed 
                    + pRule->SisterRuleNumber;
#else
            pRule = *TOSSeqGraphList[TOSSeqGraphNumber]
                    //QACJ 0488: amanevm: Use of pointer arithmetic is needed 
                    + pRule->SisterRuleNumber;
#endif
        }
        else
        {
            pRule = NULL;
        }
    }
    while(pRule != NULL);
}

//==============================================================================
//=========================== EXPORTED FUNCTIONS ===============================
//==============================================================================

//==============================================================================
// DESCRIPTION:         See component header file
//==============================================================================
void TOSSeqInitialize(void)
{
    tTOSSeqGraphId GraphNumber;

    mLIBassert(cTOSSeqGraphNumber > 0);

    for (GraphNumber = 0;GraphNumber < cTOSSeqGraphNumber; GraphNumber++)
    {
        TOSSeqGraphContext[GraphNumber].GraphState = cTOSSeqInactiveGraph;
        TOSSeqGraphContext[GraphNumber].RuleNumber = 0 ;
    }
}

//==============================================================================
// DESCRIPTION:         See component header file
//==============================================================================
void TOSSeqActivateGraph(const tTOSSeqGraphId GraphNumber)
{
    if (GraphNumber < cTOSSeqGraphNumber)
    {
        mLIBassert(TOSSeqGraphContext[GraphNumber].GraphState == cTOSSeqInactiveGraph);

        mDbgActivateGraph(GraphNumber);
        TOSSeqGraphContext[GraphNumber].GraphState = cTOSSeqActiveGraph;
        TOSSeqGraphContext[GraphNumber].RuleNumber = 0;
    }
    else
    {
        mLIBassert(cFalse);
    }
}

//==============================================================================
// DESCRIPTION:         See component header file
//==============================================================================
void TOSSeqDeactivateGraph(const tTOSSeqGraphId GraphNumber)
{
    if (GraphNumber < cTOSSeqGraphNumber)
    {
        // If graph is already deactivated, it is not a fault
        //  mLIBassert(TOSSeqGraphContext[GraphNumber].GraphState != cTOSSeqInactiveGraph);

        mDbgDeactivateGraph(GraphNumber);
        TOSSeqGraphContext[GraphNumber].GraphState = cTOSSeqInactiveGraph;
    }
    else
    {
        mLIBassert(cFalse);
    }
}

//==============================================================================
// DESCRIPTION:         See component header file
//==============================================================================
void TOSSeqFreezeGraph(const tTOSSeqGraphId GraphNumber)
{
    if (GraphNumber < cTOSSeqGraphNumber)
    {
        mLIBassert(TOSSeqGraphContext[GraphNumber].GraphState == cTOSSeqActiveGraph);

        mDbgFreezeGraph(GraphNumber);
        TOSSeqGraphContext[GraphNumber].GraphState = cTOSSeqFrozenGraph;
    }
    else
    {
        mLIBassert(cFalse);
    }
}

//==============================================================================
// DESCRIPTION:         See component header file
//==============================================================================
void TOSSeqUnfreezeGraph(const tTOSSeqGraphId GraphNumber)
{
    if (GraphNumber < cTOSSeqGraphNumber)
    {
        mLIBassert(TOSSeqGraphContext[GraphNumber].GraphState == cTOSSeqFrozenGraph);

        mDbgUnfreezeGraph(GraphNumber);
        TOSSeqGraphContext[GraphNumber].GraphState = cTOSSeqActiveGraph;
    }
    else
    {
        mLIBassert(cFalse);
    }
}

//==============================================================================
// DESCRIPTION:         See component header file
//==============================================================================
tTOSSeqGraphStateType TOSSeqGraphState(const tTOSSeqGraphId GraphNumber)
{
    tTOSSeqGraphStateType GraphStateL;

    GraphStateL = cTOSSeqInactiveGraph;
    
    if (GraphNumber < cTOSSeqGraphNumber)
    {
        GraphStateL = (TOSSeqGraphContext[GraphNumber].GraphState);
    }
    else
    {
        mLIBassert(cFalse);
    }

    return GraphStateL;
}

//==============================================================================
// DESCRIPTION:         See component header file
//==============================================================================
BOOL TOSSeqTrueEval(void)
{
    // This function must always return true
    return (cTrue);
}

//==============================================================================
// DESCRIPTION:         See component header file
//==============================================================================
void TOSSeqNoAction(void)
{
    // This function must be always empty
}

//==============================================================================
// DESCRIPTION:         See component header file
//==============================================================================
void TOSSeqMotor(const tTOSSeqGraphId StartGraph,const tTOSSeqGraphId EndGraph)
{
    tTOSSeqGraphId OldGraphNumber;

    mLIBassert(EndGraph < cTOSSeqGraphNumber);

    mDbgSeqMotor();

    OldGraphNumber = TOSSeqGraphNumber;     // Save OldGraphNumber

    // if no graph is activated -> simulation of a minimum time
    mLDBSimulateProcessingTime(cTOSSeqDureeTourGrapheSimulationNs/
                               //QACJ 3141: amanevm: statement is used only on simulation
                               (cLDBTick*(cTOSSeqGraphNumber+1)));

    // It is possible because it is not possible to have 2 graph tasks with same priority
    for (TOSSeqGraphNumber = StartGraph; TOSSeqGraphNumber<= EndGraph; TOSSeqGraphNumber++)
    {
        mLIBassert(TOSSeqGraphList[TOSSeqGraphNumber] != NULL);

        if (TOSSeqGraphContext[TOSSeqGraphNumber].GraphState == cTOSSeqActiveGraph)
        {
            // Polyspace justification: amanevm:
            // Funcion ends. See justification in ScanGraph
            ScanGraph();

            // TosSeq Call this Macro for simulate the LDB component
            // This macro is empty in the LDB embedded
            mLDBSimulateProcessingTime(cTOSSeqDureeTourGrapheSimulationNs/
                                       //QACJ 3141: amanevm: statement is used only on simulation
                                       (cLDBTick*(cTOSSeqGraphNumber+1)));

            // Call the scheduler for give the hand again
            TOSSchedule();
        }
    }

    TOSSeqGraphNumber = OldGraphNumber;     // Restore OldGraphNumber
}

