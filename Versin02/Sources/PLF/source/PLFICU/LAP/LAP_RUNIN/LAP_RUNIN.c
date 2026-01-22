//******************************************************************************
// Copyright:    This software is JYD property.
//               Duplication or disclosure without JYD written authorization
//               is prohibited.
// -----------------------------------------------------------------------------
// Project:      ICU511
// Language:     C
// -----------------------------------------------------------------------------
// Component:  老化功能
// -----------------------------------------------------------------------------
//******************************************************************************
// This line is used to separate code and file header.This is begin.
//*****************************BEGIN_NOMOVE*************************************
// Time: 2017年11月23日 16:10:55
//zjb
//时间记录中一个Bug，多记录了2次时间，
//添加代码停止MOTCTRL任务
//*****************************END_NOMOVE***************************************
// This line is used to separate code and file header. This is last line.
//******************************************************************************

#include "LAP_RUNIN.h"


#define cU8Step(v)              ((U8)(v))

//任务周期ms
#define cU8TaskPeriodMs         ((U8)40U)

//此周期要和DAT_CVT的任务周期保持一致
//CVT 任务周期，进入老化后要关闭该任务
#define cU8CVT_TaskPeriodMs		((U8)20U)

//MOTCTRL任务周期，进入老化后要关闭此任务
#define cDATMOTCTRL_TaskPeriodMs ((U8)10U)

#define cU8RunInSt_Invalid      cU8Step(0)
#define cU8RunInSt_Pre          cU8Step(1)
#define cU8RunInSt_Bgn          cU8Step(2)
#define cU8RunInSt_Ing          cU8Step(3)
#define cU8RunInSt_Exit         cU8Step(4)

#define cU32RunInTimeOut		(4U * 60U *60U)

#define cU32RunInValidFlag           (U32)0x55AA5A5AU
#define mTim_Xs(Xs)             ((((Xs)*1000U)/cU8TaskPeriodMs))
#define mTim_Xs_Yms(Xs, Yms)    ((((Xs)*1000U) + (Yms))/cU8TaskPeriodMs)

#define cU8C3OutRunInFreq       ((U8)2U)
#define cU16CANChnRunInPeriod   ((U16)500U)

static U32 su32RunInTimCnt = 0U;
static U8   su8RunInSt = 0U;
static U32  su32LogRunInTimCnt = 0U;
static U32  su32PwrOutRunInTimCnt = 0U;
static BOOL sbIsSysInRunInMod = cFalse;//导出的应该是这个标志，给其他模块进行判断。
static U32  su32RunInFlagWRDID = 0U;
static	tTOSAlarm	stAlarmRunIn;
static U32 su32MsgRunInTimCnt = 0U;
static BOOL sbRunInTimeOut = cFalse;


static void C3OutRunIn(void )
{

}

static  void PwrOutRunIn(void )
{
	su32PwrOutRunInTimCnt ++;
	switch(su32PwrOutRunInTimCnt)
	{
	case mTim_Xs_Yms(cU8Cfg_PwrOut_RunIN_Step1,0U * cU8TaskPeriodMs):
		mSERControl(6200Close, 3U);
		mSERControl(6200Close, 2U);
		mSERControl(6200Close, 1U);
		mSERControl(6200Open, 0U);
		break;

	case mTim_Xs_Yms(cU8Cfg_PwrOut_RunIN_Step2,0U * cU8TaskPeriodMs):
		mSERControl(6200Close, 3U);
		mSERControl(6200Close, 2U);
		mSERControl(6200Close, 0U);
		mSERControl(6200Open, 1U);
		break;


	case mTim_Xs_Yms(cU8Cfg_PwrOut_RunIN_Step3,0U * cU8TaskPeriodMs):
		mSERControl(6200Close, 3U);
		mSERControl(6200Close, 0U);
		mSERControl(6200Close, 1U);
		mSERControl(6200Open, 2U);
		break;

	case mTim_Xs_Yms(cU8Cfg_PwrOut_RunIN_Step4,0U * cU8TaskPeriodMs):
		mSERControl(6200Close, 0U);
		mSERControl(6200Close, 2U);
		mSERControl(6200Close, 1U);
		mSERControl(6200Open, 3U);
		su32PwrOutRunInTimCnt = 0U;
		break;

	default:
		break;
	}

}

static void StopSomeTask(void)
{
#if 0	//TODO:XXX
	tTOSAlarm   stAlarmCVT;
	//这里停止一些必要的任务，集中精力进行老化，包括TT，蜂鸣器，背光
	//TOSSeqDeactivateGraph(cTOSSeqGraphIdLAPBcmCommuMgr);


	//停止车速和转速计算任务
	stAlarmCVT.TaskID = cTOSTaskID_DATCVTTask;
	TOSSetRelAlarm(&stAlarmCVT, 0, mTOSConvMsInAlarmTick(cU8CVT_TaskPeriodMs));
	TOSCancelAlarm(&stAlarmCVT);
#endif

}
static void StopTXMsg(void )
{


}

static void PrepareForRunIn(void)
{
	//停掉不相关的外发报文
    StopTXMsg();
	//停止一些任务
	StopSomeTask();
}

static void BgnRunIn(void)
{

}

static void LAPRunInLog(void)
{
	//U16 u16RunInTim = 0U;

	su32LogRunInTimCnt++;

	switch(su32LogRunInTimCnt)
	{
	//每10s记录一次时间，时间单位为s
	case mTim_Xs_Yms(10U,  0U * cU8TaskPeriodMs):
		//u16RunInTim = mSERRead(U16Bit, EEP_AgeTime, Default);
		//mSERWrite(U16Bit, EEP_AgeTime, u16RunInTim + 1U , Default);
		su32LogRunInTimCnt = 0U;
		break;
	default:
		break;
	}

}

static void LAPRunInOutputMsg(void)
{
	U32 u32RunInTim1 = 0U;
	U32 u32RunInTim2 = 0U;
	//U16 u16Data = 0U;

	su32MsgRunInTimCnt++;
	u32RunInTim1 = su32MsgRunInTimCnt / (mTim_Xs_Yms(1U,  0U * cU8TaskPeriodMs)); /*对1s求模*/
	u32RunInTim2 = su32MsgRunInTimCnt % (mTim_Xs_Yms(1U,  0U * cU8TaskPeriodMs)); /*对1s求余*/
	//每1s上报一次时间，时间单位为s
	if(0U == u32RunInTim2)
	{
	    //mSERWrite(U8Bit, Sig_TDLL, (U8)(u32RunInTim1 & 0xFFU), Default);
	    //mSERWrite(U8Bit, Sig_TDLH, (U8)((u32RunInTim1 >> 8U) & 0xFFU), Default);
	    //mSERWrite(U8Bit, Sig_TDHL, (U8)((u32RunInTim1 >> 16U) & 0xFFU), Default);
	}

	if(u32RunInTim1 >= cU32RunInTimeOut)
	{
		sbRunInTimeOut = cTrue;

	}
}

static void LAPRunInPro(void)
{
	PwrOutRunIn();
	C3OutRunIn();
	//记录老化时间
	LAPRunInLog();
	//上报老化时间
	LAPRunInOutputMsg();
}

static BOOL IsRunInAllowed(void)
{
	//这里定义允许的条件。
	//bCndit1 : IGON, bCndit2: 老化模式标志有效，bCndit3 : 里程小于3km, bCndit4: 没有接收到应用报文
	BOOL bCndit1 = cFalse;
	BOOL bCndit2 = cFalse;
	BOOL bCndit3 = cFalse;
	BOOL bCndit4 = cFalse;
	BOOL bCndit5 = cFalse;

	BOOL bRet = cFalse;

	//IGOn
	bCndit1 = 0;

	if(cU32RunInValidFlag == su32RunInFlagWRDID)
	{
		bCndit2 = cTrue;
	}

	//if(mSERRead(U32Bit, EEP_OdoTotal, Default) < 30U)
	{
		bCndit3 = cTrue;
	}

	if(cTrue == mSERRead(U1Bit,NoMsgToClusterOnCAN,Default))
	{
		bCndit4 = cTrue;
	}

	//启动后时间大于10，主要是等自检完成
	if(su32RunInTimCnt > mTim_Xs(cU8Cfg_RunIn_AllwStartTim))
	{
		bCndit5 = cTrue;
	}

	if(cTrue == (bCndit1 && bCndit2 && bCndit3 && bCndit4 && bCndit5))
	{
		sbIsSysInRunInMod = cTrue;
	}
	else
	{
		sbIsSysInRunInMod = cFalse;
	}

	bRet = sbIsSysInRunInMod;

	return bRet;
}



//*******************************************************



void LAPRunInStartupInit(void)
{
	su32RunInTimCnt = 0;
}

void LAPRunInInit(void)
{

	su32RunInTimCnt = 0;

	su8RunInSt = cU8RunInSt_Invalid;

	//清除相关计数器
	su32PwrOutRunInTimCnt = 0U;
	sbIsSysInRunInMod = cFalse;
    su32LogRunInTimCnt = 0U;
	su32MsgRunInTimCnt = 0U;
}



void LAPRunInEnterActiveState(void)
{
	LAPRunInInit();
	//仅初始化一次
	su32RunInFlagWRDID = 0U;

	//启动任务
	stAlarmRunIn.TaskID = cTOSTaskID_LAPRunInTask;
	TOSSetRelAlarm(&stAlarmRunIn, 0, mTOSConvMsInAlarmTick(cU8TaskPeriodMs));
}


void LAPRunInLeaveActiveState(void)
{
	//这里不再添加停止任务的代码，因为没有机会停止老化任务的运行，如果是老化，则老化一直进行，不会停止
	//如果不是老化，则此任务会自动停止。
}

void LAPRunInTask(void)
{
	//U16 u16Data = 0U;

	su32RunInTimCnt++;

	switch(su8RunInSt)
	{
	case cU8RunInSt_Invalid:
		//规定上电后，60s内要进入老化，否则再无机会.此任务将会停止，不再响应老化请求
		if(IsRunInAllowed())
		{
			su8RunInSt = cU8RunInSt_Pre;

		}
		else if(su32RunInTimCnt >= mTim_Xs(cU8Cfg_RunIn_AllwEndTim))
		{
			//停止任务执行，不再给进入老化的机会，下次此任务不会再运行。
			TOSCancelAlarm(&stAlarmRunIn);
			su8RunInSt = cU8RunInSt_Invalid;
		}
		else
		{
			//60s内，允许进入老化
		}

		break;


	case cU8RunInSt_Pre:
		PrepareForRunIn();
		su8RunInSt = cU8RunInSt_Bgn;
		break;

	case cU8RunInSt_Bgn:
		BgnRunIn();
		su8RunInSt = cU8RunInSt_Ing;
		break;


	case cU8RunInSt_Ing:
		if(IsRunInAllowed())
		{
			LAPRunInPro();
		}
		else
		{
			su8RunInSt = cU8RunInSt_Exit;
		}
		break;

	case cU8RunInSt_Exit:
		mSERControl(Cpu, Reset);
		break;
	default:
		break;

	}
}


//************************************************
BOOL LAPRunInIsRunInMod(void)
{
	return sbIsSysInRunInMod;
}

void LAPRunInFlagFromDiag(U32 u32RunInFlag)
{
	su32RunInFlagWRDID = u32RunInFlag;
}

BOOL LAPRunInIsRunInTimeOut(void)
{
	return sbRunInTimeOut;
}
