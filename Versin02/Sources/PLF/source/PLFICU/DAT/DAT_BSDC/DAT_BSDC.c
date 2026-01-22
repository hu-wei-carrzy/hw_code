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
#define DAT_BSDC  "DAT_BSDC"

//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//------------------------------------------------------------------------------
#include "DAT_BSDC.h"

//------------------------------------------------------------------------------
// Local constants
//------------------------------------------------------------------------------
#define cDATBSDC_TaskPeriodMs		((U8)10)

#define cRampControl				((U8)1)
#define cMaxDuty					((U8)100)
#define cMinDuty					((U8)0)

//------------------------------------------------------------------------------
// Local macros
//------------------------------------------------------------------------------
#define DATBSDCSuspendIT() TOSSuspendOSInterrupts()
#define DATBSDCResumeIT() TOSResumeOSInterrupts()

//------------------------------------------------------------------------------
// Local data
//------------------------------------------------------------------------------
static tTOSAlarm  tDATBSDC_TaskAlarm;

eDRV8718_ErrorStatus u8DrvCurrentState = 0;
eDRV8718_ErrorStatus u8DrvOldState = 0;

static uint16_t DRVStateArry[10] ;


//------------------------------------------------------------------------------
// Exported data
//------------------------------------------------------------------------------
tDCMotor tDC_motor[eDCMOTOR_COUNT];


//------------------------------------------------------------------------------
// Local function prototypes
//
// static tTypeRetour FunctionName(tTypeArgument1 ArgumentName1, ... );
//------------------------------------------------------------------------------
static void Duty_control(tDCMotor *P);
static uint8_t Motor_Get_Info(int8_t channel);


//==============================================================================
//=========================== LOCAL FUNCTIONS ==================================
//==============================================================================

/***************************************************************************
 名称：Duty_control
 作用：占空比控制
  输入：
 返回：无
 描述：
****************************************************************************/
void Duty_control(tDCMotor *P)
{
	int8_t temp = P->SetDuty - P->StepDuty;
	int8_t step = cRampControl;

	if( fabs(temp) >= step)
	{
		if( P->SetDuty >= P->StepDuty )
		{
			P->StepDuty += step;
		}
		else
		{
			P->StepDuty -= step;
		}
		if(P->StepDuty > MaxDuty)
		{
			P->StepDuty = MaxDuty;
		}
		if(P->StepDuty < MinDuty)
		{
			P->StepDuty = MinDuty;
		}
	}
	else
	{
		P->StepDuty = P->SetDuty;
	}
}
/***************************************************************************
 名称：Duty_Stopping
 作用：占空比停止
  输入：
 返回：无
 描述：
****************************************************************************/
void Duty_Stopping(tDCMotor *P)
{
	int8_t temp = P->SetDuty - 0;
	int8_t step = cRampControl;

	if( fabs(temp) >= step)
	{
		P->SetDuty -= step;

		if(P->SetDuty < MinDuty)
		{
			P->SetDuty = MinDuty;
		}
	}
	else
	{
		P->SetDuty = 0;
	}
}


/***************************************************************************
 名称：Motor_Get_Info
 作用：设置电机的运行方向
  输入：无
 返回：无
 描述：
****************************************************************************/
uint8_t Motor_Get_Info(int8_t channel)
{
	if(channel == 1)
	{
		tDC_motor[channel].FdkCur = DATBSDC_GetMaxCur_A();
		tDC_motor[channel].Fdkspeed = DATBSDC_GET_SpeedA();
		tDC_motor[channel].FdkDir = DATBSDC_A_DualHall_Direction();
	}
	else if(channel == 2)
	{
		tDC_motor[channel].FdkCur = DATBSDC_GetMaxCur_B();
		tDC_motor[channel].Fdkspeed = DATBSDC_GET_SpeedB();
		tDC_motor[channel].FdkDir = DATBSDC_B_DualHall_Direction();
	}
	else if(channel == 3)
	{
		tDC_motor[channel].FdkCur = DATBSDC_GetMaxCur_C();
		tDC_motor[channel].Fdkspeed = DATBSDC_GET_SpeedC();
		tDC_motor[channel].FdkDir = DATBSDC_C_DualHall_Direction();
	}
	else if(channel == 4)
	{
		tDC_motor[channel].FdkCur = DATBSDC_GetMaxCur_D();
		tDC_motor[channel].Fdkspeed = DATBSDC_GET_SpeedD();
		tDC_motor[channel].FdkDir = DATBSDC_D_DualHall_Direction();
	}

}
/***************************************************************************
 名称：DATBSDC_JudgeDrvState
 作用：设置电机的运
  输入：无
 返回：无
 描述：
****************************************************************************/
static bool DATBSDC_JudgeDrvState(void)
{
	bool ret = false;

	u8DrvCurrentState = BSP_Drv8718_FaultCk();

	if(u8DrvCurrentState)
	{
		memset(&tDC_motor[1], 0, sizeof(tDCMotor));
		memset(&tDC_motor[2], 0, sizeof(tDCMotor));
		memset(&tDC_motor[3], 0, sizeof(tDCMotor));
		memset(&tDC_motor[4], 0, sizeof(tDCMotor));

		tDC_motor[1].Status = eError;
		tDC_motor[2].Status = eError;
		tDC_motor[3].Status = eError;
		tDC_motor[4].Status = eError;

		BSP_Clear_DRV8718Fault();

		ret = true;
	}
	else if ((!u8DrvCurrentState) && (u8DrvOldState))
	{
		tDC_motor[1].Status = eInit;
		tDC_motor[2].Status = eInit;
		tDC_motor[3].Status = eInit;
		tDC_motor[4].Status = eInit;

		ret = false;
	}

	u8DrvOldState = u8DrvCurrentState;

	return ret;
}

/***************************************************************************
 名称：DATBSDC_TestCmd
 作用：测试电机程序
  输入：无
 返回：无
 描述：
****************************************************************************/
static void DATBSDC_TestCmd(void)
{
	static uint16_t TestSpeed;
	static uint8_t TestSpeedL;
	static uint8_t TestSpeedH;

	static uint8_t TestSigCmd;
	static uint8_t TestDuty;


	static uint16_t  u16Loop;
	static uint16_t  u16Loop1;


	//	TestSigCmd = mSERRead(U8Bit,Sig_CMD,Delayed);
	//	TestDuty = mSERRead(U8Bit,Sig_Duty,Delayed);
	//TestDuty = mSERRead(U8Bit,BCM_4_ArmingSts,Delayed);
	//	tDC_motor[2].TargetDuty = TestDuty;
	//	tDC_motor[2].TargetDir = TestSigCmd;

	static uint8_t TestCmd;
	static uint8_t TestLastCmd;

	//	TestCmd = mSERRead(U1Bit,DI_IN_DIO11,Delayed);
	//
	//	if((TestCmd == 0)&&(TestLastCmd == 1))
	//	{
	//		u16Loop1++;
	//		tDC_motor[3].Status = 0;
	//	}
	//
	//	if(TestCmd == 0)
	//	{
	//		TestLastCmd = 0;
	//	}
	//	else
	//	{
	//		TestLastCmd = 1;
	//	}
	//
	//
	//    if((u16Loop1 % 4) == 0)
	//    {
	//    	tDC_motor[1].TargetDuty = 0;
	//    	tDC_motor[1].TargetDir = 0;
	//
	//    }
	//    else if((u16Loop1 % 4) == 1)
	//    {
	//    	tDC_motor[1].TargetDuty = 50;
	//    	tDC_motor[1].TargetDir = 1;
	//    }
	//    else if((u16Loop1 % 4) == 2)
	//    {
	//     	tDC_motor[1].TargetDuty = 0;
	//		tDC_motor[1].TargetDir = 0;
	//    }
	//    else if((u16Loop1 % 4) == 3)
	//    {
	//    	tDC_motor[1].TargetDuty = 50;
	//    	tDC_motor[1].TargetDir = 2;
	//    }

	// 	tDC_motor[1].TargetDuty = 20;
	//	tDC_motor[1].TargetDir = 1;

//	if (u16Loop1 >= 100)
//	{
//		tDC_motor[1].TargetDuty = 20;
//		tDC_motor[1].TargetDir = 1; //2：收回；1：伸出
//		//u16Loop1 = 0;
//		u16Loop1 = 1000;
//	}
//	else
//	{
//		u16Loop1++;
//	}


		tDC_motor[1].TargetDuty = 30;
		tDC_motor[1].TargetDir = 2;

//	 	tDC_motor[2].TargetDuty = 0;
//		tDC_motor[2].TargetDir = 0;



    if( u16Loop < 100)
    {
    	mSERWrite(U1Bit,LED,1,Default);
    }
    else if (( u16Loop >= 100)&&( u16Loop < 200))
    {
    	mSERWrite(U1Bit,LED,0,Default);
    }
    else
    {
    	u16Loop = 0;
    }
    u16Loop++;


}

//==============================================================================
//=========================== EXPORTED FUNCTIONS ===============================
//==============================================================================


/**************************************************************************************************
 锟斤拷锟狡ｏ拷DATANAEnterActiveState
 锟斤拷锟矫ｏ拷锟斤拷锟诫激锟斤拷状态
  锟斤拷锟诫：锟斤拷
 锟斤拷锟截ｏ拷锟斤拷
 锟斤拷锟斤拷锟斤拷锟斤拷BSP_SUP.c锟斤拷BSPSUPPinCfg锟斤拷锟窖撅拷锟斤拷4051锟斤拷锟斤拷锟斤拷选锟斤拷丝锟斤拷锟斤拷锟轿�0锟斤拷也锟斤拷锟斤拷选锟斤拷锟斤拷锟斤拷4051锟侥碉拷0通锟斤拷锟斤拷
                锟斤拷锟紹SPSUPPinCfg()锟斤拷锟斤拷锟斤拷锟斤拷main锟斤拷锟斤拷锟襟，碉拷一锟斤拷执锟叫的ｏ拷锟斤拷执锟叫碉拷锟斤拷锟斤拷时锟斤拷锟斤拷锟斤拷锟剿很讹拷锟斤拷耄拷锟窖褂︼拷锟�
	     锟窖撅拷锟饺讹拷锟剿ｏ拷锟斤拷锟绞憋拷锟斤拷锟斤拷锟矫碉拷为24ms锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟紸D转锟斤拷
**************************************************************************************************/
void DATBSDCInit()
{
	uint8_t i;

	for(i=1;i<eDCMOTOR_COUNT;i++)
	{
		tDC_motor[i].Status = eInit;
	}

}

/**************************************************************************************************
 锟斤拷锟狡ｏ拷DATANAEnterActiveState
 锟斤拷锟矫ｏ拷锟斤拷锟诫激锟斤拷状态
  锟斤拷锟诫：锟斤拷
 锟斤拷锟截ｏ拷锟斤拷
 锟斤拷锟斤拷锟斤拷锟斤拷锟诫激锟斤拷状态要锟斤拷锟斤拷锟斤拷锟斤拷模式为false
**************************************************************************************************/
void DATBSDCEnterActiveState(void)
{
    //To permit to the input to be stabilized before going into sleep mode,
    //and avoid to miss a wake up condition (IT are not authorized)
	tDATBSDC_TaskAlarm.TaskID = cTOSTaskID_DATBSDCTask;
	TOSSetRelAlarm(&tDATBSDC_TaskAlarm, 0, mTOSConvMsInAlarmTick(cDATBSDC_TaskPeriodMs));

//	extern void BSP_PDB1_ISREnable(void);
//	BSP_PDB1_ISREnable();
}
/**************************************************************************************************
 锟斤拷锟狡ｏ拷DATANAEnterActiveState
 锟斤拷锟矫ｏ拷锟斤拷锟诫激锟斤拷状态
  锟斤拷锟诫：锟斤拷
 锟斤拷锟截ｏ拷锟斤拷
 锟斤拷锟斤拷锟斤拷锟斤拷锟诫激锟斤拷状态要锟斤拷锟斤拷锟斤拷锟斤拷模式为false
**************************************************************************************************/
void DATBSDCIsMaintainActiveState(void)
{

}

/**************************************************************************************************
 锟斤拷锟狡ｏ拷DATANALeaveActiveState
 锟斤拷锟矫ｏ拷
  锟斤拷锟诫：
 锟斤拷锟截ｏ拷锟斤拷
 锟斤拷锟斤拷锟斤拷AD转锟斤拷要锟斤拷锟斤拷锟斤拷锟斤拷
**************************************************************************************************/
void DATBSDCLeaveActiveState(void)
{
    // TOSWriteSignal(cTOSSignalSomebodyMaintainActiveState);
}


uint16_t  u16Loop;
uint16_t  u16Loop1;
/**************************************************************************************************
 锟斤拷锟狡ｏ拷DATBSDCTask
 锟斤拷锟矫ｏ拷AD转锟斤拷锟斤拷锟捷达拷锟斤拷锟斤拷锟斤拷
  锟斤拷锟诫：锟斤拷
 锟斤拷锟截ｏ拷锟斤拷
 锟斤拷锟斤拷锟斤拷锟斤拷锟诫激锟斤拷状态要锟斤拷锟斤拷锟斤拷锟斤拷模式为false
**************************************************************************************************/

void DATBSDCTask(void)
{
	uint8_t tmpchl;
	bool tmpdrvstate;

	DATBSDC_TestCmd();

	tmpdrvstate = DATBSDC_JudgeDrvState();

	for(tmpchl = 1;tmpchl<eDCMOTOR_COUNT;tmpchl++)
	{
		if (tDC_motor[tmpchl].Status == eInit)
		{
			if (tmpdrvstate == false)
			{
				memset(&tDC_motor[tmpchl], 0, sizeof(tDCMotor));

				if (BSPBSDC_InitCur_Chn(tmpchl, &tDC_motor[tmpchl].BaseCur))
					tDC_motor[tmpchl].Status = eIdle;
			}
		}
		else 
		{
			switch (tDC_motor[tmpchl].Status)
			{
				case eIdle:
					// 空闲状态处理
					if ((tDC_motor[tmpchl].TargetDuty != 0) && (tDC_motor[tmpchl].TargetDir == 1))
					{
						tDC_motor[tmpchl].SetDir = tDC_motor[tmpchl].TargetDir;
						tDC_motor[tmpchl].SetDuty = tDC_motor[tmpchl].TargetDuty;
						tDC_motor[tmpchl].Status = eCWRun;
					}
					else if ((tDC_motor[tmpchl].TargetDuty != 0) && (tDC_motor[tmpchl].TargetDir == 2))
					{
						tDC_motor[tmpchl].SetDir = tDC_motor[tmpchl].TargetDir;
						tDC_motor[tmpchl].SetDuty = tDC_motor[tmpchl].TargetDuty;
						tDC_motor[tmpchl].Status = eCCWRun;
					}
					else if ((tDC_motor[tmpchl].TargetDuty == 0) && (tDC_motor[tmpchl].TargetDir == 3))
					{
						tDC_motor[tmpchl].SetDir = tDC_motor[tmpchl].TargetDir;
						tDC_motor[tmpchl].SetDuty = tDC_motor[tmpchl].TargetDuty;
						tDC_motor[tmpchl].Status = eBrake;
					}
					else
					{
					}
					break;
				case eCWRun:
					// 正转运行
					if (tDC_motor[tmpchl].TargetDir != 1)
					{
						tDC_motor[tmpchl].SetDir = 0;
						tDC_motor[tmpchl].SetDuty = 0;
						tDC_motor[tmpchl].Status = eStoping;
					}
					else
					{
						tDC_motor[tmpchl].SetDuty = tDC_motor[tmpchl].TargetDuty;
					}
					break;
				case eCCWRun:
					// 反转运行
					if (tDC_motor[tmpchl].TargetDir != 2)
					{
						tDC_motor[tmpchl].SetDir = 0;
						tDC_motor[tmpchl].SetDuty = 0;
						tDC_motor[tmpchl].Status = eStoping;
					}
					else
					{
						tDC_motor[tmpchl].SetDuty = tDC_motor[tmpchl].TargetDuty;
					}
					break;
				case eStoping:
					// 减速逻辑
					if (tDC_motor[tmpchl].TargetDir == 0)
					{
	//					if((tDC_motor[tmpchl].Fdkspeed <= 50)&&(tDC_motor[tmpchl].FdkCur < 200))
	//					{
							tDC_motor[tmpchl].SetDir = tDC_motor[tmpchl].TargetDir;
						tDC_motor[tmpchl].SetDuty = 0;
							tDC_motor[tmpchl].Status = eStop;
	//					}
					}
					else if (tDC_motor[tmpchl].TargetDir == 3)
					{
	//					if((tDC_motor[tmpchl].Fdkspeed <= 50)&&(tDC_motor[tmpchl].FdkCur < 200))
	//					{
							tDC_motor[tmpchl].SetDir = tDC_motor[tmpchl].TargetDir;
						tDC_motor[tmpchl].SetDuty = 0;
							tDC_motor[tmpchl].Status = eBrake;
	//					}
					}
					else
					{
	//					if((tDC_motor[tmpchl].Fdkspeed <= 300)&&(tDC_motor[tmpchl].FdkCur < 200))
	//					{
						tDC_motor[tmpchl].SetDir = tDC_motor[tmpchl].TargetDir;
						tDC_motor[tmpchl].SetDuty = 0;
						tDC_motor[tmpchl].Status = eStop;
//					}
				}

					break;
				case eStop:
					// 停止逻辑
					//memset(tDC_motor,0,sizeof(tDCMotor)*4);
					tDC_motor[tmpchl].Status = eIdle;
					break;
				case eBrake:
					// 制动逻辑
					//memset(tDC_motor,0,sizeof(tDCMotor)*4);
					if (tDC_motor[tmpchl].TargetDir != 3)
					{
						tDC_motor[tmpchl].SetDir = tDC_motor[tmpchl].TargetDir;
						tDC_motor[tmpchl].SetDuty = 0;
						tDC_motor[tmpchl].Status = eIdle;
					}
					break;
				case eError:
					// 错误处理（故障检测、报警）
					break;
				default:
					// 异常状态处理
					break;
			}
		}

		Motor_Get_Info(tmpchl);

		Motor_Set_Direction(tmpchl, tDC_motor[tmpchl].SetDir);

		Motor_DutyStep_control(tmpchl, tDC_motor[tmpchl].SetDuty);
	}
}



//==============================================================================
// DESCRIPTION : DATBSDC_A_SetDuty()
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void DATBSDC_A_SetDuty(uint8_t duty)
{
	if((duty >= cMinDuty)&&(duty <= cMaxDuty))
	{
		tDC_motor[1].TargetDuty = duty;
	}
	else if (duty >= cMaxDuty)
	{
		tDC_motor[1].TargetDuty = cMaxDuty;
	}
	else
	{
		tDC_motor[1].TargetDuty = cMinDuty;
	}
}
void DATBSDC_B_SetDuty(uint8_t duty)
{
	if((duty >= cMinDuty)&&(duty <= cMaxDuty))
	{
		tDC_motor[2].TargetDuty = duty;
	}
	else if (duty >= cMaxDuty)
	{
		tDC_motor[2].TargetDuty = cMaxDuty;
	}
	else
	{
		tDC_motor[2].TargetDuty = cMinDuty;
	}
}
void DATBSDC_C_SetDuty(uint8_t duty)
{
	if((duty >= cMinDuty)&&(duty <= cMaxDuty))
	{
		tDC_motor[3].TargetDuty = duty;
	}
	else if (duty >= cMaxDuty)
	{
		tDC_motor[3].TargetDuty = cMaxDuty;
	}
	else
	{
		tDC_motor[3].TargetDuty = cMinDuty;
	}
}
void DATBSDC_D_SetDuty(uint8_t duty)
{
	if((duty >= cMinDuty)&&(duty <= cMaxDuty))
	{
		tDC_motor[4].TargetDuty = duty;
	}
	else if (duty >= cMaxDuty)
	{
		tDC_motor[4].TargetDuty = cMaxDuty;
	}
	else
	{
		tDC_motor[4].TargetDuty = cMinDuty;
	}
}
//==============================================================================
// DESCRIPTION : DATBSDC_A_SetDirection()
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void DATBSDC_A_SetDirection(int8_t direction)
{
	tDC_motor[1].TargetDir = direction;
}
void DATBSDC_B_SetDirection(int8_t direction)
{
	tDC_motor[2].TargetDir = direction;
}
void DATBSDC_C_SetDirection(int8_t direction)
{
	tDC_motor[3].TargetDir = direction;
}
void DATBSDC_D_SetDirection(int8_t direction)
{
	tDC_motor[4].TargetDir = direction;
}
//==============================================================================
// DESCRIPTION :获取A项DC电机在一定时间内最大电流
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
U16 DATBSDC_GetMaxCur_A(void)
{
    S16 s16Cur;
	float flag;
	U16 initVolA;

    DATBSDCSuspendIT();
    flag = GetBSDCAvgCurA();

    if((flag >= tDC_motor[1].BaseCur)&&(tDC_motor[1].BaseCur != 0))
    {
    	s16Cur = (int)(((((flag-tDC_motor[1].BaseCur)/1024)*5*1000)/20/3)*1000);
    }
    else
    {
    	s16Cur = 0;
    }
    DATBSDCResumeIT();
    return s16Cur;
}
U16 DATBSDC_GetMaxCur_B(void)
{
	S16 s16Cur;
    float flag;

    DATBSDCSuspendIT();
    flag = GetBSDCAvgCurB();

    if((flag >= tDC_motor[2].BaseCur))
    {
    	s16Cur = (int)(((((flag-tDC_motor[2].BaseCur)/1024)*5*1000)/20/50)*1000);
    }
    else
    {
    	s16Cur = 0;
    }
    DATBSDCResumeIT();
    return s16Cur;
}
U16 DATBSDC_GetMaxCur_C(void)
{
    S16 s16Cur;
	float flag;

    DATBSDCSuspendIT();
    flag = GetBSDCAvgCurC();
    if((flag >= tDC_motor[3].BaseCur)&&(tDC_motor[3].BaseCur != 0))
    {
    	s16Cur = (int)((((flag-tDC_motor[3].BaseCur)/1024)*5*1000/20/20)*1000);
    }
    else
    {
    	s16Cur = 0;
    }
    DATBSDCResumeIT();
    return s16Cur;
}
U16 DATBSDC_GetMaxCur_D(void)
{
    S16 s16Cur;
 	float flag;

    DATBSDCSuspendIT();
    flag = GetBSDCAvgCurD();
    if((flag >= tDC_motor[4].BaseCur)&&(tDC_motor[4].BaseCur != 0))
    {
    	s16Cur = (int)(((((flag-tDC_motor[4].BaseCur)/1024)*5*1000)/3/50)*1000);
    }
    else
    {
    	s16Cur = 0;
    }
    DATBSDCResumeIT();
    return s16Cur;
}
//==============================================================================
// DESCRIPTION :获取A项DC电机在10ms时间内的hall数
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
U16 DATBSDC_GetHall1_A(void)
{
    U16 u16Hall;

    DATBSDCSuspendIT();
    u16Hall = BSP_GetHallA_CH0();
    DATBSDCResumeIT();

    return u16Hall;
}
U16 DATBSDC_GetHall2_A(void)
{
    U16 u16Hall;

    DATBSDCSuspendIT();
    u16Hall = BSP_GetHallB_CH0();
    DATBSDCResumeIT();

    return u16Hall;
}
U16 DATBSDC_GetHall1_B(void)
{
    U16 u16Hall;

    DATBSDCSuspendIT();
	u16Hall = BSP_GetHallA_CH1();
    DATBSDCResumeIT();

    return u16Hall;
}
U16 DATBSDC_GetHall2_B(void)
{
    U16 u16Hall;

    DATBSDCSuspendIT();
	u16Hall = BSP_GetHallB_CH1();
    DATBSDCResumeIT();

    return u16Hall;
}
U16 DATBSDC_GetHall1_C(void)
{
    U16 u16Hall;

    DATBSDCSuspendIT();
    u16Hall = BSP_GetHallA_CH2();
    DATBSDCResumeIT();

    return u16Hall;
}
U16 DATBSDC_GetHall2_C(void)
{
    U16 u16Hall;

    DATBSDCSuspendIT();
    u16Hall = BSP_GetHallB_CH2();
    DATBSDCResumeIT();

    return u16Hall;
}
U16 DATBSDC_GetHall1_D(void)
{
    U16 u16Hall;

    DATBSDCSuspendIT();
    u16Hall = BSP_GetHallA_CH3();
    DATBSDCResumeIT();

    return u16Hall;
}
U16 DATBSDC_GetHall2_D(void)
{
    U16 u16Hall;

    DATBSDCSuspendIT();
    u16Hall = BSP_GetHallB_CH3();
    DATBSDCResumeIT();

    return u16Hall;
}
//==============================================================================
// DESCRIPTION :获取电机的方向
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
U8 DATBSDC_A_DualHall_Direction(void)
{
	U8 u8Dir;

	DATBSDCSuspendIT();
	u8Dir = BSP_ICU_Direction_CH0();
	DATBSDCResumeIT();
	return u8Dir;
}
//==============================================================================
// DESCRIPTION :获取电机的方向
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
U8 DATBSDC_B_DualHall_Direction(void)
{
	U8 u8Dir;

	DATBSDCSuspendIT();
	u8Dir = BSP_ICU_Direction_CH1();
	DATBSDCResumeIT();
	return u8Dir;
}
//==============================================================================
// DESCRIPTION :获取电机的方向
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
U8 DATBSDC_C_DualHall_Direction(void)
{
	U8 u8Dir;

	DATBSDCSuspendIT();
	u8Dir = BSP_ICU_Direction_CH2();
	DATBSDCResumeIT();
	return u8Dir;
}
//==============================================================================
// DESCRIPTION :获取电机的方向
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
U8 DATBSDC_D_DualHall_Direction(void)
{
	U8 u8Dir;

	DATBSDCSuspendIT();
	u8Dir = BSP_ICU_Direction_CH3();
	DATBSDCResumeIT();
	return u8Dir;
}
//==============================================================================
// DESCRIPTION :获取电机的方向
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
uint16_t DATBSDC_GET_SpeedA(void)
{
	uint16_t tmpSpeed;
	DATBSDCSuspendIT();
	tmpSpeed = GetBSDCAvgSpeedA();
	DATBSDCResumeIT();

	return tmpSpeed;
}
//==============================================================================
// DESCRIPTION :获取电机的方向
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
uint16_t DATBSDC_GET_SpeedB(void)
{
	uint16_t tmpSpeed;
	DATBSDCSuspendIT();
	tmpSpeed = GetBSDCAvgSpeedB();
	DATBSDCResumeIT();

	return tmpSpeed;
}
//==============================================================================
// DESCRIPTION :获取电机的方向
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
uint16_t DATBSDC_GET_SpeedC(void)
{
	uint16_t tmpSpeed;
	DATBSDCSuspendIT();
	tmpSpeed = GetBSDCAvgSpeedC();
	DATBSDCResumeIT();

	return tmpSpeed;
}
//==============================================================================
// DESCRIPTION :获取电机的方向
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
uint16_t DATBSDC_GET_SpeedD(void)
{
	uint16_t tmpSpeed;
	DATBSDCSuspendIT();
	tmpSpeed = GetBSDCAvgSpeedD();
	DATBSDCResumeIT();

	return tmpSpeed;
}

//==============================================================================
// DESCRIPTION :锟斤拷取锟斤拷锟斤拷姆锟斤拷锟�
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
int8_t DATBSDC_A_DutyFd(void)
{
	int8_t tmpDuty;
	DATBSDCSuspendIT();
	tmpDuty = tDC_motor[1].SetDuty;
	DATBSDCResumeIT();

	return tmpDuty;
}

//==============================================================================
// DESCRIPTION :锟斤拷取锟斤拷锟斤拷姆锟斤拷锟�
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
int8_t DATBSDC_B_DutyFd(void)
{
	int8_t tmpDuty;
	DATBSDCSuspendIT();
	tmpDuty = tDC_motor[2].SetDuty;
	DATBSDCResumeIT();

	return tmpDuty;
}

//==============================================================================
// DESCRIPTION :锟斤拷取锟斤拷锟斤拷姆锟斤拷锟�
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
int8_t DATBSDC_C_DutyFd(void)
{
	int8_t tmpDuty;
	DATBSDCSuspendIT();
	tmpDuty = tDC_motor[3].SetDuty;
	DATBSDCResumeIT();

	return tmpDuty;
}

//==============================================================================
// DESCRIPTION :锟斤拷取锟斤拷锟斤拷姆锟斤拷锟�
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
int8_t DATBSDC_D_DutyFd(void)
{
	int8_t tmpDuty;
	DATBSDCSuspendIT();
	tmpDuty = tDC_motor[4].SetDuty;
	DATBSDCResumeIT();

	return tmpDuty;
}

//==============================================================================
// DESCRIPTION :锟斤拷取锟斤拷锟斤拷姆锟斤拷锟�
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
bool DATBSDC_DRV_StateFd(void)
{
	bool tmpflag = false;
	if(u8DrvCurrentState)
	{
		tmpflag = true;
	}
	return tmpflag;
}



