#include "DAT_MOD.h"

#include "CanNm.h"

#define cDATMod_TaskPeriodMs		((U8)10)
// The time is almost the same as Twbs of NM
#define	cDATMod_Sleep_DelayTime	 	((U16)200-20)

#define	mIsDiagMode	(mSERRead(U1Bit, IsDiagMode, Default))
static	tTOSAlarm  tDATMod_TaskAlarm;
static  tTOSTimer tDATMod_ConfirmTimer;

static tTOSTimer tDATMod_SelfChkTimer;
static U8 u8DATMOD_Mode;
static BOOL bIsSelfChkOccur;		//锟皆检发锟斤拷锟斤拷志锟斤拷锟斤拷为cTrue锟斤拷锟皆检发锟斤拷锟斤拷锟斤拷锟斤拷锟劫斤拷锟斤拷锟皆硷拷
static BOOL bDATMod_IsSelfChecking;	//锟皆硷拷状态

void DATModStartupInit(void)
{
	u8DATMOD_Mode = eSysMod_Run;

	bIsSelfChkOccur = cFalse;
	bDATMod_IsSelfChecking = cFalse;
	TOSStopTimer(&tDATMod_SelfChkTimer);
}

void DATModEnterActiveState(void)
{
	TOSStopTimer(&tDATMod_ConfirmTimer);

	tDATMod_TaskAlarm.TaskID = cTOSTaskID_DATModTask;
	TOSSetRelAlarm(&tDATMod_TaskAlarm, 0, mTOSConvMsInAlarmTick(cDATMod_TaskPeriodMs));
}
uint16_t  u16TestCount;

void DATModLeaveActiveState(void)
{
	TOSCancelAlarm(&tDATMod_TaskAlarm);
	bDATMod_IsSelfChecking = cFalse;

	// u16TestCount=0;
}



void DATModTask(void)
{
	u16TestCount++;

	U8 Tmp;
	BOOL bSpeedValid = cFalse;

#if 0
	if((cTrue == mSERRead(U1Bit,DI_OnPowerSig,Default)) && (cFalse == mSERRead(U1Bit, DI_SpeedSig,Default)))
	{
		bSpeedValid = cTrue;
	}
	else
	{
		bSpeedValid = cFalse;
	}

	if(eSysMod_Run== u8DATMOD_Mode)
	{
		Tmp = mSERRead(U8Bit,BatVolState,Default);

		if(cTrue == mIsDiagMode)
		{
			u8DATMOD_Mode = cSysMod_Diag;
		}
/*		else if(cTrue == mSERRead(U1Bit,IsStudyMod,Default))
		{
			if((eBAT_Vol_Sts_Under != Tmp) && (eBAT_Vol_Sts_Over != Tmp) && (cFalse == bSpeedValid))
			{
				u8DATMOD_Mode = eSysMod_Study;
			}
		}*/
	}
	else if(cSysMod_Diag == u8DATMOD_Mode)
	{
	    if(cTrue == mIsDiagMode)
	    {
	        if(cTrue == bSpeedValid)
            {   //锟斤拷锟劫达拷锟斤拷5km锟斤拷锟斤拷锟斤拷锟剿讹拷要锟剿筹拷锟疥定模式
                TOSSendControl(cTOSControlOverSpeedInDiagnosticMode);
                u8DATMOD_Mode = eSysMod_Run;
            }
	    }
	    else
	    {
	    	u8DATMOD_Mode = eSysMod_Run;
	    }
	}
	else if(eSysMod_Study == u8DATMOD_Mode)
	{
/*		Tmp = mSERRead(U8Bit,StudyState,Default);
		if(eStudySta_Fail == Tmp)
		{
			u8DATMOD_Mode = eSysMod_Run;
		}
		else if(eStudySta_Success == Tmp)
		{   //锟斤拷位
		    if(cFalse == mSERRead(U1Bit,IsEepProcessing,Default))
		    {
		        mSERControl(Cpu, Reset);
		    }
		}
		else
		{
		    no statement
		}*/
	}
	else
	{
	    /*no statement*/
	}
#endif

}

void DATModIsMaintainActiveState(void)
{
//	if (eSysMod_Sleep != u8DATMOD_Mode)
//	{
//		TOSWriteSignal(cTOSSignalSomebodyMaintainActiveState);
//	}
//    if(eSysMod_Run != u8DATMOD_Mode)
//    {   //只锟杰达拷锟斤拷锟斤拷状态锟斤拷锟斤拷锟斤拷锟斤拷
 // TOSWriteSignal(cTOSSignalSomebodyMaintainActiveState);
 //   }
//绛夐渶瑕佷紤鐪犳椂娉ㄩ噴锛屽惁鍒欎笉浼氫紤鐪�
//wangluo
	if(NM_MODE_BUS_SLEEP != CanNm_Mode[0])
	{
	    TOSWriteSignal(cTOSSignalSomebodyMaintainActiveState);
	}
       
	//缁欎笂鐢电儳褰曠暀鐐规椂闂�
 	if(u16TestCount < 1000)
	{
	    TOSWriteSignal(cTOSSignalSomebodyMaintainActiveState);
	}
	else
	{
		u16TestCount = 1100;
	}
}

void DATModIsMaintainActiveSleepState(void)
{
//	if (eSysMod_Sleep != u8DATMOD_Mode)
//	{
//		TOSWriteSignal(cTOSSignalSomebodyMaintainActiveSleepState);
//	}
    if(eSysMod_Run != u8DATMOD_Mode)
    {   //只锟杰达拷锟斤拷锟斤拷状态锟斤拷锟斤拷锟斤拷锟斤拷
        TOSWriteSignal(cTOSSignalSomebodyMaintainActiveSleepState);
    }
}

U8	DATModGetSysMod(void)
{
	return(u8DATMOD_Mode);
}
