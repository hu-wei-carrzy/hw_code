//******************************************************************************
// Copyright:    This software is JYD property.
//               Duplication or disclosure without JYD written authorization
//               is prohibited.
// -----------------------------------------------------------------------------
// Project:      ICU511
// Language:     C
// -----------------------------------------------------------------------------
// Component:  odo and trip and other power info calculation
// -----------------------------------------------------------------------------
//******************************************************************************
// This line is used to separate code and file header.This is begin.
//*****************************BEGIN_NOMOVE*************************************
// 2018年1月20日16:38:49
//1.新增转发18FFC119、18FFC219、18FFC319、18FF1724报文功能。banfy
//2018年1月31日 09:22:52
//zjb
//3590, 3589
//外发报文0x18FFCC17，禁止无关的几个信号设置，添加离座报警，这个实现遗漏
//
//2018年2月9日 13:34:31
//zjb
//新加两个转发报文
//*****************************END_NOMOVE***************************************
// This line is used to separate code and file header. This is last line.
//******************************************************************************

//------------------------------------------------------------------------------
// Body Identification
//------------------------------------------------------------------------------
#define LAP_CAN   "LAP_CAN"

//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//
// #include <system_file_name.h>
// #include "project_file_name.h"
//------------------------------------------------------------------------------
#include "lap_can.h"
#include "lap_can.hgr"



//------------------------------------------------------------------------------
// Local constants
//
// #define cConstantName   ((tType) ConstantValue)
//------------------------------------------------------------------------------
#define cU16LAPCANTaskPeriodMs         ((U16)20U)   //20msTASK调度周期


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




//------------------------------------------------------------------------------
// Constant local data
//
// static const tType  VariableName;
//------------------------------------------------------------------------------




//==============================================================================
// DESCRIPTION :报文发送禁止
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION :禁止所有报文发送，响应电压异常事件
//=============================================================================
static void LAPCanDisableAllTxMsg(void)
{
}

//==============================================================================
// DESCRIPTION :报文发送使能
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION :使能所有报文发送
//=============================================================================
static void LAPCanEnableDiagMsg(void)
{
    //诊断消息使能，使能后，永远不禁止
    mSERControl(PeriodTxEnable, DiagP2P_0x18DAE7F9);
}






//==============================================================================
// DESCRIPTION :响应电压异常事件
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION :
//=============================================================================
void LAPCanPowerFail(void)
{
    LAPCanDisableAllTxMsg();
}

//==============================================================================
// DESCRIPTION :响应电压恢复事件
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION :根据电压恢复时系统模式不同，进行不同的使能处理
//=============================================================================
void LAPCanPowerRecover(void)
{

}

//==============================================================================
// DESCRIPTION :响应系统状态改变
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION :使能所有报文发送，响应电压恢复事件
//=============================================================================
void LAPCANSysModeChange(void)
{
    //当模式发生切换时，设置一次这样发送功能禁止或使能
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
void LAPCanEnterActiveState(void)
{
    TOSSeqActivateGraph( cTOSSeqGraphIdLAPCANManager);
    mSERControl(Can0, StartCom);
    mSERControl(Can1, StartCom);
 //   mSERControl(Can2, StartCom);

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
void LAPCanLeaveActiveState(void)
{
    TOSSeqDeactivateGraph( cTOSSeqGraphIdLAPCANManager);
    //这里停止通信，将来可能会根据特殊需要，不停止这个任务，而是再执行一会
    mSERControl(Can0,StopCom);
    //mSERControl(Can1,StopCom);
    //mSERControl(Can2,StopCom);
}

//==============================================================================
// DESCRIPTION : 激活模式下设置背光报文
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void LAPCANActiveProcess(void)
{

}






//==============================================================================
// DESCRIPTION : 正常工作处理
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void LAPCANWorkProcess(void)
{

}

//==============================================================================
// DESCRIPTION : 电压异常
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void LAPCANBatAbnormalProcess(void)
{

}

//==============================================================================
// DESCRIPTION : 诊断处理
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void LAPCANDiagProcess(void)
{
    //Nothing
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
void LAPCanStartupInit(void)
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
void LAPCANInit(void)
{
    LAPCanEnableDiagMsg();


}

//==============================================================================
// DESCRIPTION : 判断激活模式
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none 
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
BOOL LAPCANIsActiveMod(void)
{
    //return (cTrue == mSERRead(U1Bit,IsInDarkMod,Default));//DarkMod即为ActiveMod,即IG无效，其他任一激活有效
    return 0;
}

//==============================================================================
// DESCRIPTION : 判断电压是否异常
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none 
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
BOOL LAPCANIsBatAbnormal(void)
{
    BOOL u8Return = !(mSERRead(U1Bit,IsBatNormal,Default));
    return u8Return;
}

//==============================================================================
// DESCRIPTION : 判断诊断模式
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none 
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
BOOL LAPCANIsDiagMod(void)
{
  return cFalse;
}

//==============================================================================
// DESCRIPTION : 判断老化模式
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none 
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
BOOL LAPCANIsRuninMod(void)
{
  return cFalse;
}

//==============================================================================
// DESCRIPTION : 判断自检模式
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none 
//
// DESIGN INFORMATION : 开机自检与本报文无关，故一直返回false
//==============================================================================
BOOL LAPCANIsSelfChkMod(void)
{
  return cFalse;
}

//==============================================================================
// DESCRIPTION : 判断工作模式
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none 
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
BOOL LAPCANIsWorkMod(void)
{
//TODO:XXX    return(cSysMod_Work == mSERRead(U8Bit,SysMode,Default));
	return cTrue;
}

//==============================================================================
// DESCRIPTION : 自检结束处理
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void LAPCANSelfChkEndProcess(void)
{
    //Nothing
}

//==============================================================================
// DESCRIPTION :自检处理
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void LAPCANSelfChkProcess(void)
{
    //Nothing
}


//当是CAN唤醒时，会调用到这里
void LAPCanWakeUp(void)
{
	TOSSendControl(cTOSControlActiveSleepRequest);
}

