#ifndef I_LAP_SEA_INCLUDE_H
#define I_LAP_SEA_INCLUDE_H

#include "ARCH_CFG.h"

#ifdef cLAP_SEA_SELFINCLUDE


#define cTOS_INCLUDE
#define cDAT_BAT_DATAINCLUDE


#ifdef cHeadIncludeType_Directly
#include "LAP_DEPENDCY.h"
#else
#include ".\..\..\LAP_DEPENDCY.h"
#endif

#endif



#endif
