#ifndef I_DAT_BSDC_INCLUDE_H
#define I_DAT_BSDC_INCLUDE_H

#define cTOS_INCLUDE
#define cDAT_DIN_DATAINCLUDE
#define cDAT_DOU_DATAINCLUDE
#define cDAT_EEP_DATAINCLUDE
#define cDAT_CAN_FUNCINCLUDE

#ifdef cHeadIncludeType_Directly
#include "DAT_DEPENDCY.h"
#else
#include ".\..\DAT_DEPENDCY.h"
#endif


#ifdef cHeadIncludeType_Directly
#include "./../NATIVE/TEST_INCLUDE.h"
#endif

#endif
