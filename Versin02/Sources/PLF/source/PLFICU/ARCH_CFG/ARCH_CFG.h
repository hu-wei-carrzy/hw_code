//this file should be include in compiler searching path .
#ifndef _ARCH_CFG_H_
#define _ARCH_CFG_H_

#define cLIBStkCpu_Fujitsu
#define cLIBStkHarK0_Unused
#define cLIBStkHarM16C6N_Unused
#define cLIBStkHarM32C_Unused
#define cLIBStkARMSpanish//cLIBStkFujitsuType_16FxS
#define cLIBStkFujitsuSeries_Unused
#define cLIBStkFujitsu16FxMB96V300Reference_Unused
#define cLIBStkFujitsu16FxMB96F31xReference_Unused
#define cLIBStkFujitsu16FxMB96F32xReference_Unused
#define cLIBStkFujitsu16FxMB96F33xReference_Unused
#define cLIBStkFujitsu16FxMB96F34xReference_Unused
#define cLIBStkFujitsu16FxMB96F35xReference_Unused
#define cLIBStkFujitsu16FxMB96F37xReference_Unused
#define cLIBStkFujitsu16FxMB96F38xReference_Unused
#define cLIBStkFujitsu16FxMB96F39xReference_Unused
#define cLIBStkHar16Fx_EVAL
#define cLIBStkARMSpanish_S6J3128HAA//cLIBStkFujitsuSSeries_MB96F6Ax
#define cLIBStkFujitsu16FxSMB96F6CxReference_Unused
#define cLIBStkFujitsu16FxSMB96F6BxReference_Unused
#define cLIBStkFujitsu16FxSMB96F6AxReference_MB96F6A6RA
#define cLIBStkFujitsu16FxSMB96F69xReference_Unused
#define cLIBStkFujitsu16FxSMB96F68xReference_Unused
#define cLIBStkFujitsu16FxSMB96F67xReference_Unused
#define cLIBStkFujitsu16FxSMB96F65xReference_Unused
#define cLIBStkFujitsu16FxSMB96F64xReference_Unused
#define cLIBStkFujitsu16FxSMB96F63xReference_Unused
#define cLIBStkFujitsu16FxSMB96F62xReference_Unused
#define cLIBStkFujitsu16FxSMB96F61xReference_Unused
#define cLIBStkHar16FxS_EVAL
#define cLIBStkHarNecV850FxDx_Unused
#define cLIBStkHarNecV850FxDxSx3Type_Unused
#define cLIBStkHarMicroV850ESFx3_Unused
#define cLIBStkHarNecV850FxDxSx3_Unused
#define cLIBStkHarMicroV850ESDx3_Unused
#define cLIBStkHarNecV850Dx3_Unused
#define cLIBStkHarMicroV850ESSx3_Unused
#define cLIBStkHarMicroV850E2Dx4_Unused
#define cLIBStkHarNecV850E2Dx4_Unused
#define cLIBStkBoleroType_Unused
#define cLIBStkHarBolero_Unused
#define cLIBStkBoot_Used
#define cLIBStkBootstrap_Unused
#define cLIBStkSbc_Used
#define cLIBStkCan_Used
#define cLIBStkDef_Unused
#define cLIBStkLin_Unused
#define cLIBStkDatLinMaster_Unused
#define cLIBStkDatLinSlave_Unused
#define cLIBStkEep_Used  //old is Unused
#define cLIBStkDFA_Unused
#define cLIBStkDatDfaDfl_Used
#define cLIBStkMot_Used
#define cLIBStkDin_Used
#define cLIBStkDou_Used

#define cLIBStkAna_Used

#define cLIBStkScc2_Used
#define cLIBStkSafety_Unused
#define cLIBStkCarBoot_Unused
#define cLIBStkEepType_STM93Cx6  //old  is Unused
#define cLIBStkSpi_Soft
#define cLIBStkEepReinitSpiComm_Unused
#define cLIBStkLibImmo_Unused
#define cLIBStkLibRnd_Unused
#define cLIBStkLibInterpolation_Used
#define cLIBStkTosPreemption_Unused
#define cLIBStkTosTpoPeriodicTimeout_Used
#define cLIBStkTosPerfCnt_Unused
#define cLIBStkDatCanConfig_Rno
#define cLIBStkBootCompression_Unused
#define cLIBStkBootRNOLightSpecifications_Unused
#define cLIBStkRamLoader_Unused
#define cLIBStkBootSFM_Unused
#define cLIBStkBootSfmManager_Unused
#define cLIBStkBootEEPROM_Unused
#define cLIBStkBootPlatformManager_Unused
#define cLIBStkTasking_Unused
#define cLIBStkRAMRoutine_Unused
#define cLIBStkRamSecondaryLoader_Unused
#define cLIBStkDiagOnCan_Used
#define cLIBStkDiagOnCanProtocol_Kwp
#define cLIBStkDiagOnCanDiffRequ_Used
#define cLIBStkDatCanRNOType_Slave
#define cLIBStkDatCanPsaBodyMultimedia_Unused
#define cLIBStkDatCanCdl_Cdl2
#define cLIBStkDatCanPSA_Unused
#define cLIBStkDatCanPSAType4_Unused
#define cLIBStkDatEepSbk_Used //old is Unused
#define cLIBStkDatEepDbk_Used //old is Unused
#define cLIBStkDatEepObk_Used //old is Unused
#define cLIBStkDatEepDea_Used //old is Unused
#define cLIBStkUnprotect_Unused
#define cLIBStkOutputSharedAccess_Used
// Obsolete #define cLIBStkHarFx3_Unused
#define cLIBStk_Used
//#define cLIBMCUWDT_Unused
#define cLIBStkCarBoot_VW


////////////////////////////////////////////////////////
//NOTE**************************************
//PLease not delete cHeadIncludeType_Directly define
//#define cHeadIncludeType_Directly
//#define cLIBStkLDBUseLDBTimer



//#define cLIBDIDirectBy4051
#define cLIBDIByADAnd4051
/////////////////////////////////////////////////
//define macro to control evaluation board and real cluster board
////////////////////////////////////////////////


#include "FUNC_CFG.h"



#endif
