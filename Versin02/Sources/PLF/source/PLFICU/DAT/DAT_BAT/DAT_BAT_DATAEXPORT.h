#ifndef I_DAT_BAT_DATAEXPORT_H
#define I_DAT_BAT_DATAEXPORT_H
//------------------------------------------------------------------------------
// Exported Macros
//------------------------------------------------------------------------------
// #define LAYCmpMacroName(...)   (MacroDefinition)

#include "DAT_BAT_FORMULA.h"

typedef enum
{
	eBATNo1,		/* 电源1 */

	eBAT_MAX,
}EmBatNoTyp;

typedef enum
{
	eBAT_Vol_Sts_Under = 0u,
	eBAT_Vol_Sts_Low ,
	eBAT_Vol_Sts_Normal,
	eBAT_Vol_Sts_High,
	eBAT_Vol_Sts_Over,
	eBAT_Vol_Sts_Max
}PowerStateTyp;

extern U16     DATBAT_GetConfirmedBatVoltage(void);
extern U8      DATBAT_GetConfirmedBatSts(void);
extern BOOL	   DATBAT_IsAppBatVoltageNormal(void);
extern BOOL	   DATBAT_IsDiagBatVoltageNormal(void);
extern BOOL    DATBatIsStartupBatStable(void);

#define	mSERReadU1BitIsBatNormalDefault()				DATBAT_IsAppBatVoltageNormal()
#define	mSERReadU1BitIsDiagBatNormalDefault()			DATBAT_IsDiagBatVoltageNormal()
#define mSERReadU1BitIsStartupBatStableDefault()		DATBatIsStartupBatStable()
#define mSERReadU8BitBatVolStateDefault()				DATBAT_GetConfirmedBatSts()
#define	mSERReadU16BitBatVoltageDefault()				DATBAT_GetConfirmedBatVoltage()

//导出电压报警相关标志位
#define mSERReadU1BitIsCanVolLowDefault()				DATBATGetAlarmVolLowSt()

#define mSERReadU1BitIsSysBatAbNormalDefault()				DATBATGetBatVolAbNormalSt(eBATNo1)			// BAT3作为系统供电

//导出当前是否稳定的接口，因为除bat模块自己判定外，lap_sup模块会有计时，当电压不满足但计时满足时，任然判定稳定。banfy
extern void DATBat_SetSysStartState(BOOL bStartState);
#define mSERWriteU1BitSysStartStateDefault(v)     			DATBat_SetSysStartState(v)


#endif

#if bijk
extern U16     DATBat_GetWaitVolStableTime(void);	//TODO：函数未实现

extern BOOL    DATBAT_IsAppBatProtect(void);

extern BOOL    DATBATGetAlarmVolHighSt(void);
extern BOOL    DATBATGetAlarmVolLowSt(void);
extern BOOL    DATBATGetBatVolAbNormalSt(EmBatNoTyp bat_num);


#define	mSERReadS8BitBatStsDefault()		    			DATBAT_GetConfirmedBatSts()//DATBAT_GetConfirmedBatVoltage()
#define	mSERReadU16BitWaitVolStableTimeDefault()		 	DATBat_GetWaitVolStableTime()
#define	mSERReadU1BitIsBatNormalDefault()					DATBAT_IsAppBatVoltageNormal()
#define	mSERReadU1BitIsDiagBatNormalDefault()				((~DATBATGetBatVolAbNormalSt(eBATNo1)) & 0x01U)
#define mSERReadU1BitIsAppBatProtectDefault()    			DATBAT_IsAppBatProtect()
#define mSERReadU1BitIsStartupBatStableDefault()       		DATBatIsStartupBatStable()

#define	mSERReadU8BitBatVolStateDefault()					DATBAT_GetConfirmedBatSts()

#define mSERReadU1BitIsPwrVolLowDefault()					DATBATGetAlarmVolLowSt()
#define mSERReadU1BitIsPwrVolHighDefault()					DATBATGetAlarmVolHighSt()

#define mSERReadU1BitIsBat3AbNormalDefault()				DATBATGetBatVolAbNormalSt(eBATNo1)

#define mSERReadU1BitIsBat3NormalDefault()					((~DATBATGetBatVolAbNormalSt(eBATNo1)) & 0x01U)

#endif
