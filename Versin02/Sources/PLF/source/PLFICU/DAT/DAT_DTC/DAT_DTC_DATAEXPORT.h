#ifndef I_DAT_DTC_DATAEXPORT_H
#define I_DAT_DTC_DATAEXPORT_H

extern U8      DATDdiGetQueryResult(void);
extern U16     DATDdiGetQueryDTCCount();
extern BOOL    DATDdbIsDTCCodeExist();
extern U8      DATDdbGetDTCIndexByDTCCode();
extern U32     DATDdbReadDeltedDTCCode(void);
extern void    DATDdbWriteDeltedDTCCode(U32 u32DTCCode);
extern void    DATDiiSetControlDTCSettingValue(BOOL u8Value);
extern void    DATDtcControlMonitoringCycle(const U8 u8Category, const U1 u1Activate);
extern BOOL    DATDtcGetDTCStatus(U8 u8DTCId);



#define mSERReadU8BitDTCQueryResultDefault()                                   \
    DATDdiGetQueryResult()


#define mSERReadU16BitQueryDTCCountDefault()                                   \
    DATDdiGetQueryDTCCount()
	


#define mSERReadU1BitIsDTCCodeExistDefault()            DATDdbIsDTCCodeExist()
#define mSERReadU8BitGetDTCIndexByDTCCodeDefault()      DATDdbGetDTCIndexByDTCCode()

#define mSERReadU32BitDeletedDTCCodeDefualt()          DATDdbReadDeltedDTCCode()
#define mSERWriteU32BitDeletedDTCCodeDefault(value)    DATDdbWriteDeltedDTCCode(value)


#define mSERWriteU1BitControlDTCSettingDefault(value)                   \
        DATDiiSetControlDTCSettingValue(value)


#define mSERWriteTableU1BitDTCMonitoringCyclesDefault(Func, Value)          \
    DATDtcControlMonitoringCycle((Func), (Value))


#define mSERWriteU1BitDTCFuncEnableDefault(Func)   \
        DATDtcControlMonitoringCycle((Func), (1))

#define mSERWriteU1BitDTCFuncDisableDefault(Func) \
        DATDtcControlMonitoringCycle((Func), (0))

//导出DTC状态,新增DTC项需要手动在这里添加，可以考虑利用DTC表格自动生成
#define mSERReadU1BitIsSpeedMsgLostOccurDefault()  DATDtcGetDTCStatus(eDTCFunCom_SpeedMsgLost)
#define mSERReadU1BitIsTachoMsgLostOccurDefault()  DATDtcGetDTCStatus(eDTCFunCom_TachoMsgLost)
#define mSERReadU1BitIsWaterTempMsgLostOccurDefault()  DATDtcGetDTCStatus(eDTCFunCom_WaterTempMsgLost)
#define mSERReadU1BitIsOilPrsMsgLostOccurDefault()  DATDtcGetDTCStatus(eDTCFunCom_OilPrsMsgLost)
#define mSERReadU1BitIsTrumpetMsgLostOccurDefault()  DATDtcGetDTCStatus(eDTCFunCom_TrumpetMsgLost)
#define mSERReadU1BitIsClkMsgLostOccurDefault()  DATDtcGetDTCStatus(eDTCFunCom_ClkMsgLost)
#define mSERReadU1BitIsSpeedMsgOverOccurDefault()  DATDtcGetDTCStatus(eDTCFunCom_SpeedMsgOver)
#define mSERReadU1BitIsTachoMsgOverOccurDefault()  DATDtcGetDTCStatus(eDTCFunCom_TachoMsgOver)
#define mSERReadU1BitIsWaterTempMsgOverOccurDefault()  DATDtcGetDTCStatus(eDTCFunCom_WaterTempMsgOver)
#define mSERReadU1BitIsTrumpetMsgOverOccurDefault()  DATDtcGetDTCStatus(eDTCFunCom_TrumpetMsgOver)
#define mSERReadU1BitIsClkMsgOverOccurDefault()  DATDtcGetDTCStatus(eDTCFunCom_ClkMsgOver)
#define mSERReadU1BitIsOilPrsMsgOverOccurDefault()  DATDtcGetDTCStatus(eDTCFunCom_OilPrsMsgOver)
#define mSERReadU1BitIsSpeedSigAbnormalOccurDefault()  DATDtcGetDTCStatus(eDTCFunCom_SpeedSigAbnormal)
#define mSERReadU1BitIsTachoSigOverOccurDefault()  DATDtcGetDTCStatus(eDTCFunCom_TachoSigOver)
#define mSERReadU1BitIsFuelLvlSigOverOccurDefault()  DATDtcGetDTCStatus(eDTCFunCom_FuelLvlSigOver)
#define mSERReadU1BitIsOilPrsSigOverOccurDefault()  DATDtcGetDTCStatus(eDTCFunCom_OilPrsSigOver)
#define mSERReadU1BitIsAirPrs1OverHighOccurDefault()  DATDtcGetDTCStatus(eDTCFunCom_AirPrs1OverHigh)
#define mSERReadU1BitIsAirPrs1OverLowOccurDefault()  DATDtcGetDTCStatus(eDTCFunCom_AirPrs1OverLow)
#define mSERReadU1BitIsAirPrs2OverHighOccurDefault()  DATDtcGetDTCStatus(eDTCFunCom_AirPrs2OverHigh)
#define mSERReadU1BitIsAirPrs2OverLowOccurDefault()  DATDtcGetDTCStatus(eDTCFunCom_AirPrs2OverLow)
#define mSERReadU1BitIsBrkLmpShortPrtctOccurDefault()  DATDtcGetDTCStatus(eDTCFunCom_BrkLmpShortPrtct)
#define mSERReadU1BitIsBrkLmpShortToPwrOccurDefault()  DATDtcGetDTCStatus(eDTCFunCom_BrkLmpShortToPwr)
#define mSERReadU1BitIsAirCndtrPnlShortPrtctOccurDefault()  DATDtcGetDTCStatus(eDTCFunCom_AirCndtrPnlShortPrtct)
#define mSERReadU1BitIsAirCndtrPnlShortToPwrOccurDefault()  DATDtcGetDTCStatus(eDTCFunCom_AirCndtrPnlShortToPwr)
#define mSERReadU1BitIsRetarderShortPrtctOccurDefault()  DATDtcGetDTCStatus(eDTCFunCom_RetarderShortPrtct)
#define mSERReadU1BitIsRetarderShortToPwrOccurDefault()  DATDtcGetDTCStatus(eDTCFunCom_RetarderShortToPwr)
#define mSERReadU1BitIsDoorPumpShortPrtctOccurDefault()  DATDtcGetDTCStatus(eDTCFunCom_DoorPumpShortPrtct)
#define mSERReadU1BitIsDoorPumpShortToPwrOccurDefault()  DATDtcGetDTCStatus(eDTCFunCom_DoorPumpShortToPwr)
#define mSERReadU1BitIsDRLShortPrtctOccurDefault()  DATDtcGetDTCStatus(eDTCFunCom_DRLShortPrtct)
#define mSERReadU1BitIsDRLShortToPwrOccurDefault()  DATDtcGetDTCStatus(eDTCFunCom_DRLShortToPwr)
#define mSERReadU1BitIsThirdAxleShortPrtctOccurDefault()  DATDtcGetDTCStatus(eDTCFunCom_ThirdAxleShortPrtct)
#define mSERReadU1BitIsThirdAxleShortToPwrOccurDefault()  DATDtcGetDTCStatus(eDTCFunCom_ThirdAxleShortToPwr)
#define mSERReadU1BitIsTraceableEEPAbnormalOccurDefault()  DATDtcGetDTCStatus(eDTCFunCom_TraceableEEPAbnormal)
#define mSERReadU1BitIsPlantEEPAbnormalOccurDefault()  DATDtcGetDTCStatus(eDTCFunCom_PlantEEPAbnormal)
#define mSERReadU1BitIsCarCfgEEPAbnormalOccurDefault()  DATDtcGetDTCStatus(eDTCFunCom_CarCfgEEPAbnormal)
#define mSERReadU1BitIsCustomCfgEEPAbnormalOccurDefault()  DATDtcGetDTCStatus(eDTCFunCom_CustomCfgEEPAbnormal)
#define mSERReadU1BitIsOdoEEPAbnormalOccurDefault()  DATDtcGetDTCStatus(eDTCFunCom_OdoEEPAbnormal)
#define mSERReadU1BitIsProcessEEPAbnormalOccurDefault()  DATDtcGetDTCStatus(eDTCFunCom_ProcessEEPAbnormal)
#define mSERReadU1BitIsResetEEPAbnormalOccurDefault()  DATDtcGetDTCStatus(eDTCFunCom_ResetEEPAbnormal)
#define mSERReadU1BitIsDTCEEPAbnormalOccurDefault()  DATDtcGetDTCStatus(eDTCFunCom_DTCEEPAbnormal)
#define mSERReadU1BitIsMUXDTCEEPAbnormalOccurDefault()  DATDtcGetDTCStatus(eDTCFunCom_MUXDTCEEPAbnormal)
#define mSERReadU1BitIsMUXCfgEEPAbnormalOccurDefault()  DATDtcGetDTCStatus(eDTCFunCom_MUXCfgEEPAbnormal)
#define mSERReadU1BitIsPDBCfgEEPAbnormalOccurDefault()  DATDtcGetDTCStatus(eDTCFunCom_PDBCfgEEPAbnormal)
#define mSERReadU1BitIsPDBDTCEEPAbnormalOccurDefault()  DATDtcGetDTCStatus(eDTCFunCom_PDBDTCEEPAbnormal)
#define mSERReadU1BitIsAbroadDTCEEPAbnormalOccurDefault()  DATDtcGetDTCStatus(eDTCFunCom_AbroadDTCEEPAbnormal)
#define mSERReadU1BitIsPCANComFaultOccurDefault()  DATDtcGetDTCStatus(eDTCFunCom_PCANComFault)
#define mSERReadU1BitIsMCANComFaultOccurDefault()  DATDtcGetDTCStatus(eDTCFunCom_MCANComFault)
#define mSERReadU1BitIsVoltageOverHighOccurDefault()  DATDtcGetDTCStatus(eDTCFunCom_VoltageOverHigh)
#define mSERReadU1BitIsVoltageOverLowOccurDefault()  DATDtcGetDTCStatus(eDTCFunCom_VoltageOverLow)
#define mSERReadU1BitIsTrumpetShortPrtctOccurDefault()  DATDtcGetDTCStatus(eDTCFunCom_TrumpetShortPrtct)
#define mSERReadU1BitIsTrumpetShortToPwrOccurDefault()  DATDtcGetDTCStatus(eDTCFunCom_TrumpetShortToPwr)

#endif
