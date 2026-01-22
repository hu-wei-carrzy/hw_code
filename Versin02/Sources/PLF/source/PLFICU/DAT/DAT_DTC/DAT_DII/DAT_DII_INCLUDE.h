#ifndef I_DAT_DII_INCLUDE_H
#define I_DAT_DII_INCLUDE_H


#ifdef cDAT_DII_SELFINCLUDE

#include "ARCH_CFG.h"

#define cTOS_INCLUDE
#define cDAT_DTC_TYPEINCLUDE
#define cDAT_MOD_DATAINCLUDE
#define cLAP_DIAG_DATAINCLUDE
#define cDAT_BAT_DATAINCLUDE
#define cDAT_AD_DATAINCLUDE


#ifdef cHeadIncludeType_Directly
#include "DAT_DEPENDCY.h"
#else
#include ".\..\..\DAT_DEPENDCY.h"
#endif

#endif

#endif








