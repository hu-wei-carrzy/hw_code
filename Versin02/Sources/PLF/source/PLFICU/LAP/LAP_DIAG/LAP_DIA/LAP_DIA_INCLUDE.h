#ifndef I_LAP_DIA_INCLUDE_H
#define I_LAP_DIA_INCLUDE_H

#include "ARCH_CFG.h"


#ifdef cLAP_DIA_SELFINCLUDE
#define cTOS_INCLUDE

#define cDAT_BAT_DATAINCLUDE
#define cDAT_AD_DATAINCLUDE
#define cLAP_DIAG_DATAINCLUDE
#define cDAT_PWM_FUNCINCLUDE
#define cDAT_CPU_FUNCINCLUDE
#define cDAT_EEP_DATAINCLUDE

#define cDAT_BUZ_FUNCINCLUDE
#define cDAT_BLK_TYPEINCLUDE
#define cDAT_CAN_FUNCINCLUDE
#define cDAT_COM_DATAINCLUDE
#define cDAT_COM_TYPEINCLUDE
#define cDAT_BAT_DATAINCLUDE

#define cLAP_WARN_DATAINCLUDE

#ifndef cCfg_SpdTacho_From_Hardware
#define cDAT_MOTCTRL_FUNCINCLUDE
#define cDAT_MOTCTRL_DATAINCLUDE
#else
#define cDAT_CVT_FUNCINCLUDE
#define cDAT_CVT_DATAINCLUDE
#endif




#ifdef cHeadIncludeType_Directly
#include "LAP_DEPENDCY.h"
#else
#include ".\..\..\LAP_DEPENDCY.h"
#endif


#endif


#endif
