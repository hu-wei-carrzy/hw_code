//2017年8月4日 08:46:22
//文件定义一些配置函数，用于提供给用户接口
//保证主体文件不变
//
//

#include "LAP_EEP_CFG.h"

BOOL LAPEEPCfgIsNeedInitEEP(void)
{

#ifdef cU8EnableEEPInit
	BOOL bRet = cFalse;
	//当前项目是全液晶项目，要根据实际情况，决定哪些条件控制EEP的初始化功能
	     if ((cU16EEPInitCondition1 !=  mSERRead(U16Bit, EEP_EEPInitCondition_1,Default)) &&
         (cU16EEPInitCondition2 !=  mSERRead(U16Bit, EEP_EEPInitCondition_2,Default)) &&
         (cU8EEPInitCondition3  !=  mSERRead(U8Bit, EEP_EEPInitCondition_3,Default)))
	{
		bRet = cTrue;
	}

	bRet = cFalse;

	return bRet;			 //删除EE离线初始化功能，EE永远不初始化
#else
	return cFalse;
#endif

//    return cTrue;
}



void LAPEEPCfgStopSomeTask(void)
{
#ifdef cU8EnableEEPInit
		tTOSAlarm tAlarmTaskNeedStop;

    	//这里停止一些相关任务，
        //停止DTC写入EEP的任务，防止故障码写入EEP中
    	tAlarmTaskNeedStop.TaskID = cTOSTaskID_DATDtcTask;
    	TOSSetRelAlarm(&tAlarmTaskNeedStop, 0, mTOSConvMsInAlarmTick(40));
    	TOSCancelAlarm(&tAlarmTaskNeedStop);

#if 0	//TODO:XXX
    	//停止里程计算任务，防止里程写入EEP中
    	tAlarmTaskNeedStop.TaskID = cTOSTaskID_DATCVTTask;
    	TOSSetRelAlarm(&tAlarmTaskNeedStop, 0, mTOSConvMsInAlarmTick(20));
    	TOSCancelAlarm(&tAlarmTaskNeedStop);
#endif

#endif
}









