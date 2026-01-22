#ifndef I_LAP_EEP_INCLUDE_H
#define I_LAP_EEP_INCLUDE_H

#include "ARCH_CFG.h"


#define cTOS_INCLUDE
#define cDAT_EEP_DATAINCLUDE
#define cDAT_CAN_FUNCINCLUDE
#define cDAT_CPU_FUNCINCLUDE

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
#include ".\..\LAP_DEPENDCY.h"
#endif





#endif
