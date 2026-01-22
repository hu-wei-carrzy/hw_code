#ifndef I_DAT_DOU_DATAEXPORT_H
#define I_DAT_DOU_DATAEXPORT_H


#include ".\..\DAT_POU\DAT_POU.h"
#include ".\..\..\..\SCC2Gen\GEN\DAT_POUx.h"
#include ".\..\DAT_DOU\DAT_DOU.h"

extern BOOL DATDouGetKeyMCULockSt(void);

#define mSERReadU1BitIsKeyPowerLockOnDefault()          DATDouGetKeyMCULockSt()

#define mSERWriteU1BitLEDDefault(Value)          			DATDou_WriteMCU_LEDCtrol(Value)
#define mSERWriteU1BitA3G4250DCSDefault(Value)          	DATDou_WriteMCU_A3G4250D_CSCtrol(Value)
#define mSERWriteU1BitA3G4250DOEDefault(Value)          	DATDou_WriteMCU_A3G4250D_OECtrol(Value)
#define mSERWriteU1BitFLASHSPIWPDefault(Value)          	DATDou_WriteMCU_FLASH_SPI_WPCtrol(Value)
#define mSERWriteU1BitDRVMOTORnSLEEPDefault(Value)          DATDou_WriteMCU_DRV_MOTOR_nSLEEPCtrol(Value)
#define mSERWriteU1Bit5VSENSORENDefault(Value)          	DATDou_WriteMCU_5V_SENSOR_ENCtrol(Value)
#define mSERWriteU1BitHDODSEN12Default(Value)          		DATDou_WriteMCU_HDO_DSEN12Ctrol(Value)
#define mSERWriteU1BitINF2Default(Value)          			DATDou_WriteMCU_CTL3408_IN_F2Ctrol(Value)
#define mSERWriteU1BitINF1Default(Value)          			DATDou_WriteMCU_CTL3408_IN_F1Ctrol(Value)
#define mSERWriteU1BitHDODSEN34Default(Value)          		DATDou_WriteMCU_HDO_DSEN34Ctrol(Value)
#define mSERWriteU1BitHDOIN4Default(Value)          		DATDou_WriteMCU_HDO_IN4Ctrol(Value)
#define mSERWriteU1BitHDOIN3Default(Value)          		DATDou_WriteMCU_HDO_IN3Ctrol(Value)
#define mSERWriteU1BitHDOIN2Default(Value)          		DATDou_WriteMCU_HDO_IN2Ctrol(Value)
#define mSERWriteU1BitHDOIN1Default(Value)          		DATDou_WriteMCU_HDO_IN1Ctrol(Value)
#define mSERWriteU1BitI2CWCDefault(Value)          			DATDou_WriteMCU_I2C_WCCtrol(Value)
#define mSERWriteU1BitFLASHSPIOEDefault(Value)          	DATDou_WriteFLASH_SPI_OECtrol(Value)

#endif

