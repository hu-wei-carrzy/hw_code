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
// Time��2016-09-19 10:18:25
// 1: add code to get averaged AD value
// 2: add task scheduler for low time consumption of AD task.
// Time:2016-09-22 14:55:31
// 1:bug fix about the 6200 channel switch.
//*****************************END_NOMOVE***************************************
// This line is used to separate code and file header. This is last line.
//******************************************************************************

#define LAP_LOCK  "LAP_LOCK"
#include "LAP_LOCK.h"

#include "network_manage.h"
#define cLAPLOCK_TaskPeriodMs		((U8)10)
static	tTOSAlarm  tLAPLOCK_TaskAlarm;

/**************************************************************************************************
 ���ƣ�LAPLOCKEnterActiveState
 ���ã����뼤��״̬
  ���룺��
 ���أ���
 ������
**************************************************************************************************/
void LAPLOCKInit()
{

}

/**************************************************************************************************
 ���ƣ�LAPLOCKEnterActiveState
 ���ã����뼤��״̬
  ���룺��
 ���أ���
 ���������뼤��״̬Ҫ��������ģʽΪfalse
**************************************************************************************************/
void LAPLOCKEnterActiveState(void)
{
    //To permit to the input to be stabilized before going into sleep mode,
    //and avoid to miss a wake up condition (IT are not authorized)
	tLAPLOCK_TaskAlarm.TaskID = cTOSTaskID_LAPLOCKTask;
	TOSSetRelAlarm(&tLAPLOCK_TaskAlarm, 0, mTOSConvMsInAlarmTick(cLAPLOCK_TaskPeriodMs));
}

/**************************************************************************************************
 ���ƣ�LAPLOCKLeaveActiveState
 ���ã�
  ���룺
 ���أ���
 ������
**************************************************************************************************/
void LAPLOCKLeaveActiveState(void)
{

}

/**************************************************************************************************
 ���ƣ�LAPLOCKTask
 ���ã�
  ���룺��
 ���أ���
 ������
**************************************************************************************************/


void LAPLOCKTask(void)
{
    static uint16_t TestSpeed;
	static uint8_t TestSpeedL;
	static uint8_t TestSpeedH;
	//PE10ms_ProjectDoor_Main();
    test_mag.test_mag1=mSERRead(U8Bit,RL_DoorCloseStatus,Delayed);//RLDCM_1_0x3AE
    test_mag.test_mag2=mSERRead(U8Bit,RCM_3_RLRadarAngle,Delayed);//RCM_3_0x2DB
    test_mag.test_mag3=mSERRead(U8Bit,BCM_4_ArmingSts,Delayed);//BCM_4_0x392
    test_mag.test_mag4=mSERRead(U8Bit,RLDCM_1_CRC1,Delayed);//RLDCM_1_0x3AE
    test_mag.test_mag5=mSERRead(U8Bit,RCM_1_LRadarVoltageStatus,Delayed);//RCM_1_0x2D1
    test_mag.test_mag7=mSERRead(U8Bit,FRWinPosn,Delayed);//FRZCU_1_0x2AB
    test_mag.test_mag8=mSERRead(U8Bit,FLZCU_9_PowerMode,Delayed);//FLZCU_9_0x49D
    test_mag.test_mag9=mSERRead(U8Bit,HandleSwitchStsRL,Delayed);//FLZCU_5_0x35B
    test_mag.test_mag10=mSERRead(U8Bit,FLWinPosn,Delayed);//FLZCU_1_0x23B
    test_mag.test_mag11=mSERRead(U8Bit,ExternalTemperature_C,Delayed);//TMS_1_0x494
    test_mag.test_mag12=mSERRead(U8Bit,RLDCM_2_CRC1,Delayed);//RLDCM_2_0x2C8
    test_mag.test_mag13=mSERRead(U8Bit,RLDCM_3_CRC1,Delayed);//RLDCM_3_0x2C9
    test_mag.test_mag14=mSERRead(U8Bit,RLDRM_1_DRMAngle,Delayed);//RLDRM_1_0x2C0
    test_mag.test_mag15=mSERRead(U8Bit,RR_DoorCloseStatus,Delayed);//RRDCM_1_0x3BE
    test_mag.test_mag16=mSERRead(U8Bit,RLCR_1_SysSt,Delayed);//RLCR_1_0x447
    test_mag.test_mag17=mSERRead(U8Bit,RLCR_2_DOWONOFFSts,Delayed);//RLCR_2_0x448
    test_mag.test_mag18=mSERRead(U8Bit,CurrentTimeYear,Delayed);//ICC_COM_8_0x510

    test_mag.test_mag6=mSERRead(U1Bit,IN_HALL5,Immediate);
}







