
#ifndef I_DAT_BAT_H
#define I_DAT_BAT_H

#include "DAT_BAT_INCLUDE.h"
#include "DAT_BAT_CFG.h"

//typedef enum
//{
//	eBAT_Vol_Sts_Under = 0u,
//	eBAT_Vol_Sts_Low ,
//	eBAT_Vol_Sts_Normal,
//	eBAT_Vol_Sts_High,
//	eBAT_Vol_Sts_Over,
//	eBAT_Vol_Sts_Max
//}PowerStateTyp;

typedef enum
{
	eMinVoltageEN = 0u,
	eMaxVoltageEN 
}PowerThresholdTyp;

typedef enum
{
	eVoltageReduce	=0u,
	eVoltageUnchanged,
	eVoltageIncrease
	
}PowerChangeTrend;

/* 电源故障状态：正常无故障/故障 */
typedef enum
{
	eBAT_NORMAL,
	eBAT_FAULT,
}EmBatFaultStaTyp;

/* 故障诊断类型：电压过高、电压过低 */
typedef enum
{
	eVoltageOverHigh,
	eVoltageOverLow,

	eVoltageFaultMax,
}EmBatFaultTyp;

/* 电源故障诊断配置结构体 */
typedef struct
{
	EmBatNoTyp BatNo;
	EmBatFaultTyp BatFaultType;
	U16 FaultValue;
	U16 FaultTime;
	U16 RecoverValue;
	U16 RecoverTime;
	U16 DTCNum;
}stBatFaultCheckTyp;

/* 诊断通道数 */
#define MAX_CHECK_CHN (eVoltageFaultMax * eBAT_MAX)

/* 电源故障诊断状态结构体 */
typedef struct
{
	EmBatFaultStaTyp cur_state;			/*当前电池故障状态状态：正常无故障/故障*/
	U8 sta_change_cdn_time;				/*当前状态计时：计次，与运行时间有关*/
}stBatStatyp;

//LVP →LowVoltageProtect
#define cLowVoltageProtectMinVol		0U//mV
#define cLowVoltageProtectMaxVol		9500U//mV

#define cLowVoltageWorkMinVol			9000U
#define cLowVoltageWorkMaxVol			17500U

#define cVoltageNormalMinVol			16000U
#define cVoltageNormalMaxVol			32500U

#define	cHighVoltageWorkMinVol			31500U
#define	cHighVoltageWorkMaxVol			36500U

#define	cHighVoltageProtectMinVol		35500U
#define	cHighVoltageProtectMaxVol		0xFFFFU

#define cReduceBAT_Vol_Sts_UnderMaxVol		9000U//mV
#define cReduceBAT_Vol_Sts_LowMaxVol		16000U//mV
#define cReduceNormalMaxVol					32000U
#define cReduceBAT_Vol_Sts_HighMaxVol		36000

#define cInreaseBAT_Vol_Sts_LowMinVol		9000//mV
#define cIncreaseNormalMinVol				16000U//mV
#define cIncreaseBAT_Vol_Sts_HighMinVol		32000U
#define cIncreaseBAT_Vol_Sts_OverMinVol		36000U

#define cPowerVoltageChangeTime		13U//   500ms/40ms

#define	cNumberOfPowerTape			5U

typedef struct
{	PowerStateTyp PSt;     	/*电源状态*/
    U32 MinVoltageST;   	/*下阈值*/
    U32 MaxVoltageST;		/*上阈值*/
}PowerStateConfig;

extern void PowerManage(void);//50ms被周期调用
extern PowerStateTyp	GetPowerState(void);//获取当前电压状态
extern U32 GetCurrentBat2Voltage(void);	//外部提供的获取当前电压值的函数。
extern U32 GetCurrentBat3Voltage(void);	//外部提供的获取当前电压值的函数。
extern void PowerStateInit(void);

extern PowerStateTyp tPowerCurrentState;
extern U32 DatBatVoltageTb[eBAT_MAX];

#endif /*__BAT_H__*/
