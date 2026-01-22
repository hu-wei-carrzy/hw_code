#ifndef I_LAP_SUP_INCLUDE_H
#define I_LAP_SUP_INCLUDE_H

#include "ARCH_CFG.h"


#define cTOS_INCLUDE
#define cDAT_BAT_DATAINCLUDE
#define cDAT_DOU_FUNCINCLUDE
#define cDAT_CPU_FUNCINCLUDE

#define cDAT_BAT_FUNCINCLUDE
#define cDAT_EEP_DATAINCLUDE
#define cDAT_AD_DATAINCLUDE


#ifdef cHeadIncludeType_Directly
#include "LAP_DEPENDCY.h"
#else
#include ".\..\LAP_DEPENDCY.h"
#endif





#endif
