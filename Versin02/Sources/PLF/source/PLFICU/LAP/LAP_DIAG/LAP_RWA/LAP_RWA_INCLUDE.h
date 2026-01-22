#ifndef I_LAP_RWA_INCLUDE_H
#define I_LAP_RWA_INCLUDE_H

#include "ARCH_CFG.h"


#ifdef cLAP_RWA_SELFINCLUDE
#define cTOS_INCLUDE
#define cDAT_EEP_DATAINCLUDE
#define cDAT_AD_DATAINCLUDE

#ifdef   cHeadIncludeType_Directly
#include "LAP_DEPENDCY.h"
#else
#include ".\..\..\LAP_DEPENDCY.h"
#endif


#endif


#endif
