#ifndef I_LAP_EEP_INIT_GEN_H
#define I_LAP_EEP_INIT_GEN_H


#define mEEPGroupInit()        \
    case cU16EEPInitStep_2:                         \
        DATPeeRebuildSingleBank(cDATSbkHandleGroupTraceability);                         \
		mSERControl(Eep,UpDateEepGroupGroupTraceability);                                 \
        break;                                                                    \
    case cU16EEPInitStep_3:                         \
        DATPeeRebuildSingleBank(cDATSbkHandleGroupPlantTraceability);                         \
		mSERControl(Eep,UpDateEepGroupGroupPlantTraceability);                                 \
        break;                                                                    \
    case cU16EEPInitStep_4:                         \
        DATPeeRebuildSingleBank(cDATSbkHandleGroupDiagReserved);                         \
		mSERControl(Eep,UpDateEepGroupGroupDiagReserved);                                 \
        break;                                                                    \
    case cU16EEPInitStep_5:                         \
        DATPeeRebuildSingleBank(cDATSbkHandleGroupPlantCalibiration);                         \
		mSERControl(Eep,UpDateEepGroupGroupPlantCalibiration);                                 \
        break;                                                                    \
    case cU16EEPInitStep_6:                         \
        DATPeeRebuildSingleBank(cDATSbkHandleGroupReset);                         \
		mSERControl(Eep,UpDateEepGroupGroupReset);                                 \
        break;                                                                    \
    case cU16EEPInitStep_7:                         \
        DATPeeRebuildSingleBank(cDATSbkHandleGroupSbkReadOnly1);                         \
		mSERControl(Eep,UpDateEepGroupGroupSbkReadOnly1);                                 \
        break;                                                                    \
    case cU16EEPInitStep_8:                         \
        DATPeeRebuildSingleBank(cDATSbkHandleGroupSbkReadOnly2);                         \
		mSERControl(Eep,UpDateEepGroupGroupSbkReadOnly2);                                 \
        break;                                                                    \
    case cU16EEPInitStep_9:                         \
        DATPeeRebuildSingleBank(cDATSbkHandleGroupBCMCfg0);                         \
		mSERControl(Eep,UpDateEepGroupGroupBCMCfg0);                                 \
        break;                                                                    \
    case cU16EEPInitStep_10:                         \
        DATPeeRebuildSingleBank(cDATSbkHandleGroupBCMCfg1);                         \
		mSERControl(Eep,UpDateEepGroupGroupBCMCfg1);                                 \
        break;                                                                    \
    case cU16EEPInitStep_11:                         \
        DATPeeRebuildSingleBank(cDATSbkHandleGroupBCMCfg2);                         \
		mSERControl(Eep,UpDateEepGroupGroupBCMCfg2);                                 \
        break;                                                                    \
    case cU16EEPInitStep_12:                         \
        DATPeeRebuildSingleBank(cDATSbkHandleGroupBCMCfg3);                         \
		mSERControl(Eep,UpDateEepGroupGroupBCMCfg3);                                 \
        break;                                                                    \
    case cU16EEPInitStep_13:                         \
        DATPeeRebuildDoubleBank(cDATDbkHandleGroupSTKDTC);\
        mSERControl(Eep,UpDateEepGroupGroupSTKDTC);                                 \
        break;                                                                   \
    case cU16EEPInitStep_14:                         \
        DATPeeRebuildDoubleBank(cDATDbkHandleGroupDTC);\
        mSERControl(Eep,UpDateEepGroupGroupDTC);                                 \
        break;                                                                   \
    case cU16EEPInitStep_15:                         \
        DATPeeRebuildDoubleBank(cDATDbkHandleGroupDIUpperLimit);\
        mSERControl(Eep,UpDateEepGroupGroupDIUpperLimit);                                 \
        break;                                                                   \
    case cU16EEPInitStep_16:                         \
        DATPeeRebuildDoubleBank(cDATDbkHandleGroupDILowerLimit);\
        mSERControl(Eep,UpDateEepGroupGroupDILowerLimit);                                 \
        break;                                                                   \
    case cU16EEPInitStep_17:                         \
        DATPeeRebuildDoubleBank(cDATDbkHandleGroupDIType);\
        mSERControl(Eep,UpDateEepGroupGroupDIType);                                 \
        break;                                                                   \
    case cU16EEPInitStep_18:                         \
        DATPeeRebuildDoubleBank(cDATDbkHandleGroupSensorCal);\
        mSERControl(Eep,UpDateEepGroupGroupSensorCal);                                 \
        break;                                                                   \
    case cU16EEPInitStep_19:                         \
        DATPeeRebuildDoubleBank(cDATDbkHandleGroupSensorCal1);\
        mSERControl(Eep,UpDateEepGroupGroupSensorCal1);                                 \
        break;                                                                   \
    case cU16EEPInitStep_20:                         \
        DATPeeRebuildDoubleBank(cDATDbkHandleGroupSensorCal2);\
        mSERControl(Eep,UpDateEepGroupGroupSensorCal2);                                 \
        break;                                                                   \




#define cU16EEPInitSetp_SetInitFlag       cU16EEPInitStep_24
#define cU16EEPInitSetp_RebuildErrorGroup cU16EEPInitStep_26
#define cU16EEPInitStep_ECUReset          cU16EEPInitStep_28


    
#endif