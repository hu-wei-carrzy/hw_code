#ifndef I_LAP_SRI_INCLUDE_H
#define I_LAP_SRI_INCLUDE_H




#include "ARCH_CFG.h"


#ifdef cLAP_SRI_SELFINCLUDE
#define cTOS_INCLUDE
#define cDAT_BAT_DATAINCLUDE
#define cDAT_MOD_DATAINCLUDE
#define cDAT_EEP_DATAINCLUDE
#define cDAT_CPU_FUNCINCLUDE
#define cLAP_DIAG_DATAINCLUDE

#ifndef cCfg_SpdTacho_From_Hardware
#define cDAT_MOTCTRL_FUNCINCLUDE
#define cDAT_MOTCTRL_DATAINCLUDE
#else
#define cDAT_CVT_FUNCINCLUDE
#define cDAT_CVT_DATAINCLUDE
#endif



#define cDAT_AD_DATAINCLUDE
#define cDAT_CAN_DATAINCLUDE
#define cDAT_CAN_FUNCINCLUDE

#ifdef   cHeadIncludeType_Directly
#include "LAP_DEPENDCY.h"
#else
#include ".\..\..\LAP_DEPENDCY.h"
#endif
#endif



#endif
