/*
 * 名称：DAT_BAT.c
 * 作用：用于电源电压值转换、电源管理、故障检测等
 * 作者：电源模式管理：chengwga，其他：zhanghjq
 * 时间：2019.3.19
 * 版本：V0.1
 * */
#include  "DAT_BAT.h"

#define cU16DATBat_TaskPeriodMs             ((U16)40U)    

PowerStateTyp tPowerCurrentState = eBAT_Vol_Sts_Normal;
#ifdef UNIT_TEST
U32 DatBatVoltageTb[eBAT_MAX] = {24000U, 24000, 24000};
#else
U32 DatBatVoltageTb[eBAT_MAX];
#endif

static BOOL sbIsV16Stable;				//上电稳定标志
//static U8 su8DATBat_Sts_Confirmed;		/*confirmed voltage status*/
static tTOSAlarm stDATBat_TaskAlarm;	//用于启动或关闭DAT_BAT周期任务
static  U16  su16WaitVolStableCount;	//上电等待计时器，单位10ms

const static PowerStateConfig cPowerConfig_tab[eBAT_Vol_Sts_Max] =
{
	{eBAT_Vol_Sts_Under   	, cLowVoltageProtectMinVol		, cLowVoltageProtectMaxVol	},//00 8500
	{eBAT_Vol_Sts_Low		, cLowVoltageWorkMinVol			, cLowVoltageWorkMaxVol	 	},//7500 9500
	{eBAT_Vol_Sts_Normal   		, cVoltageNormalMinVol			, cVoltageNormalMaxVol	 	},//8500 32500
	{eBAT_Vol_Sts_High   	, cHighVoltageWorkMinVol		, cHighVoltageWorkMaxVol	},//31500 36500
	{eBAT_Vol_Sts_Over 	, cHighVoltageProtectMinVol		, cHighVoltageProtectMaxVol	},//35500 0xffff
};

static void DATBatFaultCheckTask(void);					/* 电源故障检测任务，实际需求为DTC诊断 */
static void DATBatFaultCheckInit(void);					/* 电源故障检测任务初始化，主要是初始化打开诊断功能 */
static U32 GetCurrentVoltage(EmBatNoTyp eBatNo);		/* 获取当前电压 */

static U8 cPowerStateTimer[eBAT_Vol_Sts_Max] =
{
	0x00,0x00,0x00,0x00,0x00,
};

/****************************************************************************
 * 名称：DATBatStartupInit
 * 参数：无
 * 返回：无
 * 作用：电源电压的初始化
 * 描述：
 *	*************************************************************************/
void DATBatStartupInit(void)
{
	DatBatVoltageTb[eBATNo1] = 24000u;
	tPowerCurrentState = eBAT_Vol_Sts_Normal;
}
/****************************************************************************
 * 名称：DATBatEnterSleepStop
 * 参数：无
 * 返回：无
 * 作用：电源的休眠状态
 * 描述：
 *	*************************************************************************/
void DATBatEnterSleepStop(void)
{
	TOSCancelAlarm(&stDATBat_TaskAlarm);
}
/****************************************************************************
 * 名称：ReadVoltageThreshold
 * 参数：无
 * 返回：无
 * 作用：读取不同电源工作模式下，电压的最小，最大阈值
 * 描述：
 *	*************************************************************************/
U32	ReadVoltageThreshold(PowerStateTyp Powerst,PowerThresholdTyp PT)
{
	if(eMinVoltageEN == PT)
	{
		return cPowerConfig_tab[Powerst].MinVoltageST;
	}
	else
	{
		return cPowerConfig_tab[Powerst].MaxVoltageST;
	}
}
/****************************************************************************
 * 名称：GetPowerState
 * 参数：无
 * 返回：无
 * 作用：读取电源的工作模式
 * 描述：
 *	*************************************************************************/
PowerStateTyp GetPowerState(void)
{
	return tPowerCurrentState;
}

/****************************************************************************
 * 名称：GetVoltageChangeTrend
 * 参数：无
 * 返回：无
 * 作用：电源电压的变化趋势，分别为减小，增加，不变三种状态
 * 描述：
 *	*************************************************************************/
U8 GetVoltageChangeTrend(U32 u32CurVol)
{
	PowerStateTyp tCurrertPowerSt=eBAT_Vol_Sts_Normal;
	
	U32	MinVoltage=0x0000;
	U32	MaxVoltage=0xFFFF;
	
	tCurrertPowerSt = GetPowerState();								//读取工作模式
	MinVoltage=ReadVoltageThreshold(tCurrertPowerSt,eMinVoltageEN);	//读取工作模式
	MaxVoltage=ReadVoltageThreshold(tCurrertPowerSt,eMaxVoltageEN);
	if(u32CurVol < MinVoltage)
	{
		return eVoltageReduce;
	}
	else if(u32CurVol >= MaxVoltage)
	{
		return eVoltageIncrease;
	}
	else
	{
		return eVoltageUnchanged;
	}
}
/****************************************************************************
 * 名称：ClearOtherPowerStateTime
 * 参数：无
 * 返回：无
 * 作用：电源在相应模式时，需要将其他模式的是时间清0
 * 描述：
 *	*************************************************************************/
void ClearOtherPowerStateTime(PowerStateTyp Powerst)
{
	U8 Loop=0;
	for(Loop=0 ; Loop<eBAT_Vol_Sts_Max ; Loop++ )
	{
		if(Loop != Powerst)
		{
			cPowerStateTimer[Loop]=0x00;
		}
		else
		{

		}
	}
}
/****************************************************************************
 * 名称：PowerVoltageReduceChangeTime
 * 参数：无
 * 返回：无
 * 作用：根据电源电压的变化修正cPowerStateTimer的值
 * 描述：
 *	*************************************************************************/
void PowerVoltageReduceChangeTime(U32 CurVol)
{
	if(CurVol < cReduceBAT_Vol_Sts_UnderMaxVol)
	{
		cPowerStateTimer[eBAT_Vol_Sts_Under]++;
		ClearOtherPowerStateTime(eBAT_Vol_Sts_Under);
	}
	else if(CurVol < cReduceBAT_Vol_Sts_LowMaxVol)
	{
		cPowerStateTimer[eBAT_Vol_Sts_Low]++;
		ClearOtherPowerStateTime(eBAT_Vol_Sts_Low);
	}
	else if(CurVol < cReduceNormalMaxVol)
	{
		cPowerStateTimer[eBAT_Vol_Sts_Normal]++;
		ClearOtherPowerStateTime(eBAT_Vol_Sts_Normal);
	}
	else if(CurVol < cReduceBAT_Vol_Sts_HighMaxVol)
	{
		cPowerStateTimer[eBAT_Vol_Sts_High]++;
		ClearOtherPowerStateTime(eBAT_Vol_Sts_High);
	}
	else 
	{
		cPowerStateTimer[eBAT_Vol_Sts_Over]++;
		ClearOtherPowerStateTime(eBAT_Vol_Sts_Over);
	}	
}
/****************************************************************************
 * 名称：PowerVoltageIncreaseChangeTime
 * 参数：无
 * 返回：无
 * 作用：根据电源电压的变化修正cPowerStateTimer的值
 * 描述：
 *	*************************************************************************/
void PowerVoltageIncreaseChangeTime(U32 u32CurVol)
{
	
	if(u32CurVol >= cIncreaseBAT_Vol_Sts_OverMinVol)
	{
		cPowerStateTimer[eBAT_Vol_Sts_Over]++;
		ClearOtherPowerStateTime(eBAT_Vol_Sts_Over);
	}
	else if(u32CurVol >= cIncreaseBAT_Vol_Sts_HighMinVol)
	{
		cPowerStateTimer[eBAT_Vol_Sts_High]++;
		ClearOtherPowerStateTime(eBAT_Vol_Sts_High);
	}
	else if(u32CurVol >= cIncreaseNormalMinVol)
	{
		cPowerStateTimer[eBAT_Vol_Sts_Normal]++;
		ClearOtherPowerStateTime(eBAT_Vol_Sts_Normal);
	}
	else if(u32CurVol >= cInreaseBAT_Vol_Sts_LowMinVol)
	{
		cPowerStateTimer[eBAT_Vol_Sts_Low]++;
		ClearOtherPowerStateTime(eBAT_Vol_Sts_Low);
	}
	else 
	{
		cPowerStateTimer[eBAT_Vol_Sts_Under]++;
		ClearOtherPowerStateTime(eBAT_Vol_Sts_Under);
	}	
}
/****************************************************************************
 * 名称：PowerStateJudge
 * 参数：无
 * 返回：无
 * 作用：根据电源状态的计时器状态，修正电源状态
 * 描述：
 *	*************************************************************************/
void PowerStateJudge(void)
{
	U8 Loop=0;
	for(Loop=0;Loop<eBAT_Vol_Sts_Max;Loop++)
	{
		if(cPowerVoltageChangeTime == cPowerStateTimer[Loop])
		{
			tPowerCurrentState=cPowerConfig_tab[Loop].PSt;
			cPowerStateTimer[Loop]=0x00;
		}
		else
		{

		}
	}
}
#define TASK_RUN_TIME	40		/* BAT任务运行周期 */
#define FAULT_TASK_RUN 	120		/* 故障诊断运行周期  */


/****************************************************************************
 * 名称：DATBatTask
 * 参数：无
 * 返回：无
 * 作用：电源模块的主函数
 * 描述：
 *	*************************************************************************/
void DATBatTask(void)//40ms
{
	static U8 u8FaultTaskRun;

#ifdef UNIT_TEST
	
#else
	DatBatVoltageTb[eBATNo1] = GetCurrentVoltage(eBATNo1);	// 作用是将AD值转换为电压值
#endif

	if(su16WaitVolStableCount < cU16DATBAT_WaitVolStableTime)
	{
		su16WaitVolStableCount ++;		//上电等待cDATBAT_WaitVolStableTime时间
	}
	else if((cFalse == sbIsV16Stable) && (DatBatVoltageTb[eBATNo1] < cU16DATBAT_VolStableLowerLimit))
	{
		//do nothing，维持sbIsV16Stable = cFalse
	}
	else
	{
		sbIsV16Stable = cTrue;//上电稳定，进行电源管理的逻辑处理
	}

	if(cTrue == sbIsV16Stable)
	{
		if(eVoltageReduce == GetVoltageChangeTrend(DatBatVoltageTb[eBATNo1]))
		{
			PowerVoltageReduceChangeTime(DatBatVoltageTb[eBATNo1]);
		}
		else if(eVoltageIncrease == GetVoltageChangeTrend(DatBatVoltageTb[eBATNo1]))
		{
			PowerVoltageIncreaseChangeTime(DatBatVoltageTb[eBATNo1]);
		}
		else
		{

		}
		PowerStateJudge();
	}

	/* 以下是电源故障检测任务 */
	u8FaultTaskRun ++;
	if (u8FaultTaskRun >= (FAULT_TASK_RUN / TASK_RUN_TIME))
	{
		u8FaultTaskRun = 0;
		DATBatFaultCheckTask();				/* 电源故障检测任务 */
	}
}

/****************************************************************************
 * 名称：DATBatRegistSysCheckTask
 * 参数：无
 * 返回：无
 * 作用：系统的调用问题
 * 描述：
 *	*************************************************************************/
void DATBatRegistSysCheckTask(void)
{
    //enter active state
    stDATBat_TaskAlarm.TaskID = cTOSTaskID_DATBatTask;
    TOSSetRelAlarm(&stDATBat_TaskAlarm, 0U, mTOSConvMsInAlarmTick(cU16DATBat_TaskPeriodMs));
}

/****************************************************************************
 * 名称：DATBatEnterActiveState
 * 参数：无
 * 返回：无
 * 作用：休眠唤醒后的模块
 * 描述：
 *	*************************************************************************/
void DATBatEnterActiveState(void)
{
	DATBatRegistSysCheckTask();

	DATBatFaultCheckInit();
}

/******************************************************************************
 * 名称：GetCurrentVoltage
 * 参数：当前获取的电源通道
 * 返回：无
 * 作用：通过读取AD通道，转换出电源电压值进
 * 描述：
 * 	***************************************************************************/
U32 GetCurrentVoltage(EmBatNoTyp eBatNo)
{
	U32 u32Dat;
	U32 u32Vol;
	//将AD值转换为电压值

	//u32Dat = mSERRead(U16Bit, AD_BAT_P_ADC, Immediate);

	//u32Vol = mBatAdcToVoltage(u32Dat);

	return u32Vol;
}

/****************************************************************************
 * 名称：DATBATGetAlarmVolLowSt
 * 参数：无
 * 返回：无
 * 作用：主要用于获取电源低电压保护状态
 * 描述：
 *	*************************************************************************/
BOOL DATBATGetAlarmVolLowSt(void)
{
	BOOL bRet;

//	if (tPowerCurrentState == eBAT_Vol_Sts_Under)
//	{
//		bRet = TRUE;
//	}
//	else
//	{
		bRet = FALSE;
//	}

	return bRet;
}

/***************************************************************************
 * 名称：DATBATGetAlarmVolHighSt
 * 参数：无
 * 返回：无
 * 作用：主要用于获取电源高电压保护状态
 * 描述：
 * 	**********************************************************************/
BOOL DATBATGetAlarmVolHighSt(void)
{
	BOOL bRet;

	if (tPowerCurrentState == eBAT_Vol_Sts_Over)
	{
		bRet = TRUE;
	}
	else
	{
		bRet = FALSE;
	}

	return bRet;
}

/**************************************************************************
 * 名称：DATBATGetBatVolAbNormalSt
 * 参数：bat_num：电源序号
 * 返回：无
 * 作用：主要用于获取电源非正常状态
 * 描述：	1.系统电源24V按照系统的电压进行电源管理，返回状态为非正常工作区间状态；
 * 		2.电源1和2按照电源电压>8V为正常进行处理
 * 	***********************************************************************/
#define VOLTAGE_LOW_VALUE	8000u		/*BAT1，BAT2异常电压，由于BAT1、BAT2只负责功率输出，所以只检测低压，不检测高压*/

BOOL DATBATGetBatVolAbNormalSt(EmBatNoTyp bat_num)
{
	BOOL bRet;

	if (tPowerCurrentState != eBAT_Vol_Sts_Normal)
	{
		bRet = TRUE;
	}
	else
	{
		bRet = FALSE;
	}

	return bRet;
}

/**************************************************************************
 * 名称：DATBAT_IsAppBatProtect
 * 参数：无
 * 返回：无
 * 作用：
 * 描述：
 * 	***********************************************************************/
BOOL  DATBAT_IsAppBatProtect(void)
{
	BOOL bRet = cFalse;

	if(cTrue == sbIsV16Stable)
	{
		//bRet = (eBAT_Vol_Sts_LowS2 == su8DATBat_Sts_Confirmed);
	}
	else
	{
		bRet = cFalse;//如果没上电稳定，直接返回cFalse
	}

	return bRet;
}
//TODO：上电启动稳定未处理
/**************************************************************************
 * 名称：DATBatIsStartupBatStable
 * 参数：无
 * 返回：无
 * 作用：
 * 描述：
 * 	***********************************************************************/
BOOL DATBatIsStartupBatStable(void)
{
	BOOL bRet = cFalse;

	bRet = sbIsV16Stable && (!DATBAT_IsAppBatProtect());

	return bRet;
}
/**************************************************************************
 * 名称：DATBat_SetSysStartState
 * 参数：无
 * 返回：无
 * 作用：
 * 描述：
 * 	***********************************************************************/
void DATBat_SetSysStartState(BOOL bStartState)
{
	sbIsV16Stable = bStartState;
}
/**************************************************************************
 * 名称：DATBAT_GetConfirmedBatVoltage
 * 参数：无
 * 返回：无
 * 作用：
 * 描述：
 * 	***********************************************************************/
U16 DATBAT_GetConfirmedBatVoltage()
{
	return (DatBatVoltageTb[eBATNo1]); 			//resolution:0.001 v
}
/**************************************************************************
 * 名称：DATBAT_IsDiagBatVoltageNormal
 * 参数：无
 * 返回：无
 * 作用：
 * 描述：
 * 	***********************************************************************/
BOOL DATBAT_IsDiagBatVoltageNormal(void)
{
	BOOL bReturn = cFalse;

	if((eBAT_Vol_Sts_Normal == tPowerCurrentState) || (eBAT_Vol_Sts_Low == tPowerCurrentState) || (eBAT_Vol_Sts_High == tPowerCurrentState)|| (eBAT_Vol_Sts_Over == tPowerCurrentState))
	{
		bReturn = cTrue; //Battery normal
	}
	else
	{
		bReturn = cFalse; //Battery abnormal
	}

	return bReturn;
}
/**************************************************************************
 * 名称：DATBAT_IsAppBatVoltageNormal
 * 参数：无
 * 返回：无
 * 作用：
 * 描述：
 * 	***********************************************************************/
BOOL DATBAT_IsAppBatVoltageNormal(void)
{
	BOOL bReturn = cFalse;

	if((eBAT_Vol_Sts_Normal == tPowerCurrentState) || (eBAT_Vol_Sts_Low == tPowerCurrentState) || (eBAT_Vol_Sts_High == tPowerCurrentState)|| (eBAT_Vol_Sts_Over == tPowerCurrentState))
	{
		bReturn = cTrue; //Battery normal
	}
	else
	{
		bReturn = cFalse; //Battery abnormal
	}

	return bReturn;
}

U8 DATBAT_GetConfirmedBatSts()
{
	return tPowerCurrentState;
}

/* 电源故障状态，与故障诊断配置表使用相同序列 */
static stBatStatyp CurBatSta[MAX_CHECK_CHN] = {};

/* 电源故障诊断配置表 */
static const stBatFaultCheckTyp cFaultCheck[MAX_CHECK_CHN] =
{
	{eBATNo1,	eVoltageOverHigh,	36500u,		500u/FAULT_TASK_RUN, 35500u, 500u/FAULT_TASK_RUN, eDTCFunCom_BatOverVol },
	{eBATNo1,	eVoltageOverLow,	8500u,		500u/FAULT_TASK_RUN, 9500u,  500u/FAULT_TASK_RUN, eDTCFunCom_BatUnderVol},
};

/**************************************************************************************
 * 名称：DATBatFaultCheckInit
 * 参数：无
 * 返回：无
 * 作用：主要用于初始化电源电压故障监测功能
 * 描述： 	1. 初始化诊断功能为打开
 * 		2. 初始化当前故障诊断状态和时间
 * 	***********************************************************************************/
void DATBatFaultCheckInit(void)
{
	U8 u8Loop;

	for(u8Loop = (U8)0; u8Loop <= MAX_CHECK_CHN; u8Loop ++)
	{
		mSERWrite(U1Bit,DTCFuncEnable, cFaultCheck[u8Loop].DTCNum, Default);

		CurBatSta[u8Loop].cur_state = eBAT_NORMAL;		/* 初始化当前故障状态为正常 */
		CurBatSta[u8Loop].sta_change_cdn_time = 0;		/* 初始化当前故障计时时间为0 */
	}
}

/*************************************************************************************
 * 名称：DATBatFaultCheckTask
 * 参数：无
 * 返回：无
 * 作用：主要用于电源电压故障监测功能
 * 描述：需求见BCM313诊断数据库，目前实现如下功能：
 *  名称					触发条件					故障恢复条件				清除条件
 *
	电源24V过电压	VBAT0>36.5V，持续500ms	      VBAT0<35.5V，持续500ms	can清除命令
	电源24V低电压	VBAT0≤8.5V，持续500ms	     	  VBAT0>9.5V，持续500ms	can清除命令
 * **********************************************************************************/

static void DATBatFaultCheckTask(void)
{
	U8 u8Loop;
	const stBatFaultCheckTyp *p;

	for (u8Loop=0u; u8Loop<MAX_CHECK_CHN; u8Loop++)
	{
		p = &cFaultCheck[u8Loop];
		switch(CurBatSta[u8Loop].cur_state)
		{
			case eBAT_NORMAL:
				/* 当前通道为电压高检测时，如果当前电压比故障阈值要高，则进行计时；或者当前通道为电压低检测时，如果当前电压比故障阈值低，则进行故障及时；前两者不满足，清空计数 */
				if (((p->BatFaultType == eVoltageOverHigh) && (DatBatVoltageTb[p->BatNo] > p->FaultValue))
					|| ((p->BatFaultType == eVoltageOverLow) && (DatBatVoltageTb[p->BatNo] <= p->FaultValue)))
				{
					CurBatSta[u8Loop].sta_change_cdn_time ++;
					if (CurBatSta[u8Loop].sta_change_cdn_time >= (p->FaultTime))
					{
						CurBatSta[u8Loop].sta_change_cdn_time = 0u;
						CurBatSta[u8Loop].cur_state = eBAT_FAULT;
						mSERControl(DTCOccur, p->DTCNum);
					}
				}
				else
				{
					CurBatSta[u8Loop].sta_change_cdn_time = 0;
				}
				break;

			case eBAT_FAULT:
				if (((p->BatFaultType == eVoltageOverHigh) && (DatBatVoltageTb[p->BatNo] < p->RecoverValue))
					|| ((p->BatFaultType == eVoltageOverLow) && (DatBatVoltageTb[p->BatNo] > p->RecoverValue)))
				{
					CurBatSta[u8Loop].sta_change_cdn_time ++;
					if (CurBatSta[u8Loop].sta_change_cdn_time >= p->RecoverTime)
					{
						CurBatSta[u8Loop].sta_change_cdn_time = 0u;
						CurBatSta[u8Loop].cur_state = eBAT_NORMAL;

						mSERControl(DTCDisappear, p->DTCNum);
					}
				}
				else
				{
					CurBatSta[u8Loop].sta_change_cdn_time = 0u;
				}

				break;
			default:
				break;
		}
	}
}
