//******************************************************************************
// Copyright:    This software is CHERY property.
//               Duplication or disclosure without JYD written authorization
//               is prohibited.
// -----------------------------------------------------------------------------
// Project:      BCM313
// Language:     C
// -----------------------------------------------------------------------------
// Component:  sample the active line inputs to maintain the system active
// -----------------------------------------------------------------------------
//******************************************************************************
// This line is used to separate code and file header.This is begin.
//*****************************BEGIN_NOMOVE*************************************
// Time:2016-08-31 09:24:09
// 1: add code to sample the active line inputs after power lock release
// 2:

//*****************************END_NOMOVE***************************************
// This line is used to separate code and file header. This is last line.
//******************************************************************************

//------------------------------------------------------------------------------
// Body Identification
//------------------------------------------------------------------------------
#define DAT_ANA  "DAT_ANA"

//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//
// #include <system_file_name.h>
// #include "project_file_name.h"
//------------------------------------------------------------------------------
#include "DAT_ANA.h"

//------------------------------------------------------------------------------
// Local constants
//
// #define cConstantName   ((tType) ConstantValue)
//------------------------------------------------------------------------------
#define cDATANA_AlarmUs                       10UL

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
static tTOSAlarm stDATANA_TaskAlarm;	//用于启动或关闭DAT_BAT周期任务

static tDATAnaValue DATAnaBufferForMsg[cDATAnaS32K144GroupNum];			// 当前轮次转换的源数据
static const tMsg cstMsgADValue = {((U8 *) DATAnaBufferForMsg), (cDATAnaS32K144GroupNum)};

static const U8 cu8DATPanInitialization[cDATPanSizeAnaGeneratorMessage]=cDATPanDefaultBufferAnaGeneratorMessage;

static BOOL sbFirstConversion;			// 是否首次AD转换
static BOOL sbIfEnterSleepMode;   		// 该静态变量用来进入、离开休眠模式用。
//static BOOL sbPoutIsChnSel = 0u;		// 功率输出通道选择

//新加递推平均值滤波，得到最近10次AD值，然后取其平均作为FilteredBuffer的输出。
static tDATAnaCalculationSize stDATAnaAvgBuffer[cDATAnaNumberOfChanels][cU8DATAnaAveragedCount];
static U8 su8CurAvgIndex;

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
tDATAnaValue DATAnaBufferFromLDB[cDATAnaNumberOfChanels];		// AD转换完成的源数据
U16 ADSumVal[cDATAnaNumberOfChanels];

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
static void DATAnaSetEnterSleepModeFlag(BOOL bPara);			// 函数声明
void DATAnaSwitchScan(void);

//==============================================================================
//=========================== LOCAL FUNCTIONS ==================================
//==============================================================================

/**************************************************************************************************
 名称：DATAnaSetEnterSleepModeFlag
 作用：设置休眠模式标志
  输入：bPara——设置的状态：0——不休眠，1——休眠
 返回：无
 描述：主要用于AD转换的使能，如果状态为休眠，则不再进行转换
**************************************************************************************************/
static void DATAnaSetEnterSleepModeFlag(BOOL bPara)
{
	sbIfEnterSleepMode = bPara;
}

/**************************************************************************************************
 名称：DATAnaReadADvalFromLDBbuff
 作用：直接从缓存读取AD值
  输入：index——缓存索引，注意这里是U8的，所以缓存不能超过255
 返回：无
 描述：如果超过最大的channel数量，则返回0Xffff，即错误
**************************************************************************************************/
U16 DATAnaReadADvalFromLDBbuff(U8 index)
{
	if(index < cDATAnaNumberOfChanels)
	{
	   return DATAnaBufferFromLDB[index];
	}
	else
	{
		return 0xFFFF;
	}
}
/**************************************************************************************************
 名称：DATAnaSwitchScan
 作用：AD转换扫描及处理
  输入：无
 返回：无
 描述：非休眠模式下：
 	 1.每次进来读取一下，看是否转换完成，转换完成就对数据进行处理，然后启动一次新的转换
 	 2.AD模块错误的时候，重新初始化模块以保证其正常运行
**************************************************************************************************/
void DATAnaSwitchScan(void)
{
	if(cFalse == sbIfEnterSleepMode)   //首先检查休眠模式状态
	{
		LDBControl(cLDBChannelLDB_AD, cLDBADStartADScan);    //开始AD扫描
		LDBReceiveWithAddr(cLDBChannelLDB_AD, cLDBADAdrIsScanOver, (tMsg *)&cstMsgADValue );   //接收AD转换模块的返回信号，cstMsgADValue用于接受AD转换的结果值
		if(cstMsgADValue.pBuffer[0])
		{
			DATAnaGetADVal();
		}
	}
}
/**************************************************************************************************
 名称：DATAnaGetADValAndSwitchChannel
 作用：获取AD值并切换通道
  输入：无
 返回：无
 描述：获取AD值，存储到AD缓冲区；
 	 注意：通道5~9和25~29因为是功率芯片的双通道，所以进行了特殊处理；即选择为0的时候将5~9通道
**************************************************************************************************/
void DATAnaGetADVal(void)
{
	U8 u8Loop = 0U;

	LDBReceiveWithAddr(cLDBChannelLDB_AD, cLDBADReadAdValues, (tMsg *)&cstMsgADValue);//接受AD转换值，cstMsgADValue接受数据

	for(u8Loop=0U; u8Loop < cDATADCALLChnMax; u8Loop++)
	{
		DATAnaBufferFromLDB[u8Loop] = DATAnaBufferForMsg[u8Loop];
	}
}

//==============================================================================
//=========================== EXPORTED FUNCTIONS ===============================
//==============================================================================
/**************************************************************************************************
 名称：DATANAInit
 作用：初始化函数
  输入：无
 返回：无
 描述：无
**************************************************************************************************/
void DATANAInit()
{
    U8 u8Loop;

    for (u8Loop = 0U; u8Loop < cDATAnaNumberOfChanels; u8Loop++)
    {
        DATAnaBufferFromLDB[u8Loop] = cu8DATPanInitialization[u8Loop];    //把从LDB层数据缓存数组清0
        ADSumVal[u8Loop] = 0U;    //ADSumVal是需要传到上层的DATA源数据，初始化清0
    }

    sbFirstConversion = cTrue;//跟踪是否第一次AD转换
    su8CurAvgIndex = 0U;

    LDBControl(cLDBChannelLDB_AD, cLDBADEnterActiveMode);//向AD转换相关的LDB通道发送命令，进入激活模式，为后续的AD转换做准备
}

/**************************************************************************************************
 名称：DATANAEnterActiveState
 作用：进入激活状态
  输入：无
 返回：无
 描述：进入激活状态要设置休眠模式为false
**************************************************************************************************/
void DATANAEnterActiveState(void)
{
	DATAnaSetEnterSleepModeFlag(cFalse);

    stDATANA_TaskAlarm.TaskID = cTOSTaskID_TacheANA;
    TOSSetRelAlarm(&stDATANA_TaskAlarm, 0U, mTOSConvMsInAlarmTick(cDATANA_AlarmUs));
}

/**************************************************************************************************
 名称：DATANALeaveActiveState
 作用：
  输入：
 返回：无
 描述：AD转换要持续进行
**************************************************************************************************/
void DATANALeaveActiveState(void)
{
}

/**************************************************************************************************
 名称：DATANALeaveActiveState
 作用：
  输入：
 返回：无
 描述：这里停止Ad转换任务，通过设置一个标志位，停止在休眠任务中的AD切换
**************************************************************************************************/
void DATAnaEnterSleepStop(void)
{
	DATAnaSetEnterSleepModeFlag(cTrue);

	LDBControl(cLDBChannelLDB_AD, cLDBADEnterSleepMode);
}

/**************************************************************************************************
 名称：DATAnaWakeUpStart
 作用：唤醒时候启动AD转换
  输入：
 返回：无
 描述：此处和上面相反，使能AD转换
**************************************************************************************************/
void DATAnaWakeUpStart(void)
{
	DATAnaSetEnterSleepModeFlag(cFalse);

	LDBControl(cLDBChannelLDB_AD, cLDBADEnterActiveMode);
}

/**************************************************************************************************
 名称：DATANATask
 作用：AD转换数据处理任务
  输入：无
 返回：无
 描述：进入激活状态要设置休眠模式为false
**************************************************************************************************/
void DATANA_Task(void)
{
    U8 InputIndex  = (U8)0;

    if (sbFirstConversion  == cFalse)//表示系统初始化完成，可以开始正常的AD转换任务
    {
        for (InputIndex = 0U; InputIndex < cDATADCALLChnMax; InputIndex++)		// 遍历所有通道
        {
            ADSumVal[InputIndex] += DATAnaBufferFromLDB[InputIndex];          //累计每个通道的AD转换值到ADSumVal数组
            stDATAnaAvgBuffer[InputIndex][su8CurAvgIndex] = DATAnaBufferFromLDB[InputIndex];     //将当前AD转换值存入stDATAnaAvgBuffer中，按照索引su8CurAvgIndex存放
            ADSumVal[InputIndex] -= stDATAnaAvgBuffer[InputIndex][(1U + su8CurAvgIndex) % cU8DATAnaAveragedCount];    //从stDATAnaAvgBuffer中减去旧值

        }
        su8CurAvgIndex ++;    //更新平均值索引
        su8CurAvgIndex = su8CurAvgIndex % cU8DATAnaAveragedCount;

    }
    else
    {
        sbFirstConversion = cFalse;//
    }

    DATAnaSwitchScan();
}
