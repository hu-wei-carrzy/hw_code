#ifndef I_DAT_BAT_INCLUDE_H
#define I_DAT_BAT_INCLUDE_H


#ifndef UNIT_TEST

#include "ARCH_CFG.h"

#define cTOS_INCLUDE
#define cDAT_BAT_DATAINCLUDE
#define cDAT_AD_DATAINCLUDE
#define cDAT_DTC_TYPEINCLUDE
#define cDAT_DTC_FUNCINCLUDE
#define cDAT_DTC_DATAINCLUDE

#define cDAT_EEP_DATAINCLUDE


#ifdef cHeadIncludeType_Directly
#include "DAT_DEPENDCY.h"
#else
#include ".\..\DAT_DEPENDCY.h"
#endif

#else

#include "./../NATIVE/TEST_INCLUDE.h"

#endif


#endif
