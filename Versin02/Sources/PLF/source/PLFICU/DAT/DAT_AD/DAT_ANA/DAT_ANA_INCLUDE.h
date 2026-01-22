#ifndef I_DAT_ANA_INCLUDE_H
#define I_DAT_ANA_INCLUDE_H

#include "ARCH_CFG.h"

#define cTOS_INCLUDE
#define cDAT_EEP_DATAINCLUDE
#define  cLAP_POUT_DATAINCLUDE
#define  cDAT_DIN_DATAINCLUDE

#ifdef cHeadIncludeType_Directly
#include "DAT_DEPENDCY.h"
#else
#include ".\..\..\DAT_DEPENDCY.h"
#endif

#endif
