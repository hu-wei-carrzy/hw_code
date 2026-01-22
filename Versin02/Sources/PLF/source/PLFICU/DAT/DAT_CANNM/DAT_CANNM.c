//******************************************************************************
// Copyright:    This software is JYD property.
//               Duplication or disclosure without JYD written authorization
//               is prohibited.
// -----------------------------------------------------------------------------
// Project:      BCM313
// Language:     C
// -----------------------------------------------------------------------------
// Component:  each 5ms finish a list of AD conversion and output the
//                       digital input values.
// -----------------------------------------------------------------------------
//******************************************************************************
// This line is used to separate code and file header.This is begin.
//*****************************BEGIN_NOMOVE*************************************
// Time:2016-08-31 08:55:33
// 1:comment the code in DATBatLeaveActiveState to continue the AD conversion.
//   after leaving active state and MCU release power lock.
//Time:2016-09-04 13:44:40
//1: change the AD conversion strategy for the  new added capacitance on 4051 output.
// Time：2016-09-19 10:18:25
// 1: add code to get averaged AD value
// 2: add task scheduler for low time consumption of AD task.
// Time:2016-09-22 14:55:31
// 1:bug fix about the 6200 channel switch.
//*****************************END_NOMOVE***************************************
// This line is used to separate code and file header. This is last line.
//******************************************************************************


//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//
// #include <system_file_name.h>
// #include "project_file_name.h"
//------------------------------------------------------------------------------
#define DAT_CANNM  "DAT_CANNM"

//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//------------------------------------------------------------------------------
#include "DAT_CANNM.h"

#include "CanNm.h"
//------------------------------------------------------------------------------
// Local constants
//------------------------------------------------------------------------------
#define cDATCANNM_TaskPeriodMs		((U8)10)



//------------------------------------------------------------------------------
// Local macros
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Local data
//------------------------------------------------------------------------------
static tTOSAlarm  tDATCANNM_TaskAlarm;


//------------------------------------------------------------------------------
// Exported data
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


/**************************************************************************************************
 名称：DATCANNMInit
 作用：进入激活状态
  输入：无
 返回：无
 描述：
**************************************************************************************************/
void DATCANNMInit()
{
	CanIf_Init();
    CanNm_Init(NULL_PTR);
    Com_Init();
}

/**************************************************************************************************
 名称：DATCANNMEnterActiveState
 作用：进入激活状态
  输入：无
 返回：无
 描述：进入激活状态要设置休眠模式为false
**************************************************************************************************/
void DATCANNMEnterActiveState(void)
{

	tDATCANNM_TaskAlarm.TaskID = cTOSTaskID_DATCANNMTask;
	TOSSetRelAlarm(&tDATCANNM_TaskAlarm, 0, mTOSConvMsInAlarmTick(cDATCANNM_TaskPeriodMs));
}

/**************************************************************************************************
 名称：DATCANNMLeaveActiveState
 作用：
  输入：
 返回：无
 描述： 是 退出活跃状态的回调函数，让各个模块在 ECU 准备进入休眠前进行必要的清理工作。
**************************************************************************************************/
void DATCANNMLeaveActiveState(void)
{
	// TOSWriteSignal(cTOSSignalSomebodyMaintainActiveState);
}

/**************************************************************************************************
 名称：DATCANNMTask
 作用：AD转换数据处理任务
  输入：无
 返回：无
 描述：进入激活状态要设置休眠模式为false
**************************************************************************************************/

void DATCANNMTask(void)
{
	RTI_Function();
	PE10ms_Network_Manage_Master();
	NM_Wakeup_Source_Monitor();
	CanNm_MainFunction();
}



