//******************************************************************************
// Copyright:    This software is JYD property.
//               Duplication or disclosure without JYD written authorization
//               is prohibited.
// -----------------------------------------------------------------------------
// Project:      BCM313
// Language:     C
// -----------------------------------------------------------------------------
// Component:  init the EEP content with default values
//                       
// -----------------------------------------------------------------------------
//******************************************************************************
// This line is used to separate code and file header.This is begin.
//*****************************BEGIN_NOMOVE*************************************
// Time:2016-09-19 09:31:07
// 1: change the group name
//*****************************END_NOMOVE***************************************
// This line is used to separate code and file header. This is last line.
//******************************************************************************


//------------------------------------------------------------------------------
// Body Identification
//------------------------------------------------------------------------------
#define lap_eep  "lap_eep"

//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//
// #include <system_file_name.h>
// #include "project_file_name.h"
//------------------------------------------------------------------------------

#include "LAP_EEP.h"
#include "LAP_EEP.hgr"

//------------------------------------------------------------------------------
// Local constants
//
// #define cConstantName   ((tType) ConstantValue)
//------------------------------------------------------------------------------


#define cU16EepInitDelay        (U16)3000U   //60s
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
#ifdef cU8EnableEEPInit
static U16  su16EEPInitSetp;
static BOOL sbIsEnableEEPInit;
#endif

static  U16  su16EepInitDelayCnt;
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

/* [LOCAL_FUNCTIONS_END] */


/****************************************************************************
*...........................................................................*
*........................... EXPORTED FUNCTIONS.............................*
*...........................................................................*
****************************************************************************/

//==============================================================================
// DESCRIPTION :
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void LAPEepEnterActiveState(void)
{
#ifdef cU8EnableEEPInit
    sbIsEnableEEPInit = cFalse;
    TOSSeqActivateGraph( cTOSSeqGraphIdLAPEepManager);



#endif
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
void LAPEepLeaveActiveState(void)
{
    //here should not stop the graph task
	//because there is no chance to arrive here:
	//if EEP inited:reset ECU
	//if EEP not inited:the graph task will not start.
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
void LAPEepInitEEPIng(void)
{
#ifdef cU8EnableEEPInit
    //this function will be called every 20ms,so I can
    //calculate time depending on the cycle.

    //later ,the rebuilding sequence of all groups may be changed
    //according to real situation
    mLIBassert(cU16SetpTimeMs > 100);
    mLIBassert(cU16EEPInitStep_ECUReset > cU16EEPInitSetp_SetInitFlag);


    switch(su16EEPInitSetp)
    {
        //here user should add all the necessary groups which will be
        //necessary for being rebuilding. user can refer to the LAP_EEP_INIT_GEN_h
        //for help
        case    cU16EEPInitSetp_Begin:
            //do nothing
            break;

        //fist rebuild the odogroup because the aging program will
        //read the odo data used as entering condition for aging test.
        //that is to say the aging test program should delay at least 2s
        //before start.
        case    cU16EEPInitStep_1:
                mSERWrite(U32Bit,EEP_OdoTotal,0,Default);
                mSERWrite(U32Bit,EEP_OdoTripBase,0,Default);
                mSERControlEepGlobalUpDateEepGroupGroupOdo();
            break;


            mEEPGroupInit()


            //set the exit condition, must not call rebuild function.
        case    cU16EEPInitSetp_SetInitFlag:
            mSERWrite(U16Bit, EEP_EEPInitCondition_1,  cU16EEPInitCondition1, Default);
            mSERWrite(U16Bit, EEP_EEPInitCondition_2,  cU16EEPInitCondition2, Default);
            mSERWrite(U8Bit,  EEP_EEPInitCondition_3,  cU8EEPInitCondition3, Default);
            mSERWrite(U8Bit,  EEP_ODOClearCountBackup,  0U, Default);
            mSERWrite(U8Bit,  EEP_ODOClearCountBackup1,  0U, Default);
            break;

        default:
            break;
    }

    su16EEPInitSetp++;

#endif
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
void LAPEepInitEEPOver(void)
{

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
BOOL LAPEepIsExitNow(void)
{
    return cFalse;
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
BOOL LAPEepIsInitEEPOver(void)
{
#ifdef cU8EnableEEPInit
    BOOL bRet = cFalse;
    //NOTE:----DO NOT SET Equal condition-----
    if(su16EEPInitSetp > cU16EEPInitSetp_SetInitFlag)
    {
        bRet = cTrue;
    }
    else
    {
        //do nothing
    }

    return bRet;
#else
    return cTrue;
#endif
}

//==============================================================================
// DESCRIPTION : 
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none 
//
// DESIGN INFORMATION : EEP是否需要初始化，这里添加初始化条件，这里条件一定要注意要
//					设置的严格一点，否则如果程序EE被异常初始化会导致严重后果
//==============================================================================
BOOL LAPEepIsNeedInitEEP(void)
{

#ifdef cU8EnableEEPInit
    if ( (cFalse == sbIsEnableEEPInit) &&	(cTrue == LAPEEPCfgIsNeedInitEEP()) )
    {
        LAPEEPCfgStopSomeTask();
    	sbIsEnableEEPInit = cTrue;
    }

    return sbIsEnableEEPInit;
#else
   return cFalse;
#endif

//   return cTrue;
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
void LAPEepWaitForExit(void)
{
#ifdef cU8EnableEEPInit
    //make sure all reset action is after rebuilding error group
    mLIBassert(cU16EEPInitStep_ECUReset > cU16EEPInitSetp_SetInitFlag);
    mLIBassert(cU16EEPInitStep_ECUReset > cU16EEPInitSetp_RebuildErrorGroup);

    switch(su16EEPInitSetp)
    {

    case cU16EEPInitSetp_RebuildErrorGroup:
        DATPeeRebuildSingleBank(cDATSbkHandleErrorGroup);
        mSERControl(Eep,UpDateEepGroupErrorGroup);
    break;


    case cU16EEPInitStep_ECUReset:
        //add code to reset ECU
        mSERControl(Cpu, Reset);
        break;

    default:
        break;
    }

    su16EEPInitSetp++;
#endif
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
BOOL LAPEepInitDelay60s(void)
{
	BOOL bRet = cFalse;
	if(su16EepInitDelayCnt < cU16EepInitDelay)
	{
		su16EepInitDelayCnt ++;
	}
	else
	{
		bRet = cTrue;
	}

  return bRet;
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
void LAPEepGraphInit(void)
{
	su16EepInitDelayCnt = 0U;
}
/* [EXPORTED_FUNCTIONS_END] */
