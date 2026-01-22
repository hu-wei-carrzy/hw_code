#ifndef I_LAP_IOC_INCLUDE_H
#define I_LAP_IOC_INCLUDE_H




#include "ARCH_CFG.h"


#ifdef cLAP_IOC_SELFINCLUDE
#define cDAT_BUZ_FUNCINCLUDE
#define cDAT_BLK_TYPEINCLUDE
#define cDAT_CPU_FUNCINCLUDE
#define cLAP_CVT_DATAINCLUDE
#define cLAP_DIAG_DATAINCLUDE
#define cDAT_BAT_DATAINCLUDE
#define cDAT_BLK_DATAINCLUDE
#define cDAT_EEP_DATAINCLUDE
#define cDAT_PWM_DATAINCLUDE
#define cDAT_BUZ_DATAINCLUDE

#define cDAT_DOU_FUNCINCLUDE

#ifndef cCfg_SpdTacho_From_Hardware
#define cDAT_MOTCTRL_FUNCINCLUDE
#define cDAT_MOTCTRL_DATAINCLUDE
#else
#define cDAT_CVT_FUNCINCLUDE
#define cDAT_CVT_DATAINCLUDE
#endif



#define cDAT_MOT_DATAINCLUDE
#define cDAT_AD_DATAINCLUDE
#define cDAT_CAN_DATAINCLUDE
#define cDAT_CAN_FUNCINCLUDE
#define cDAT_GCB_DATAINCLUDE


#ifdef   cHeadIncludeType_Directly
#include "LAP_DEPENDCY.h"
#else
#include ".\..\..\LAP_DEPENDCY.h"
#endif
#endif



#endif
