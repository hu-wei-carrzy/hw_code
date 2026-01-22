#ifndef I_DAT_MOD_INCLUDE_H
#define I_DAT_MOD_INCLUDE_H

#ifndef UNIT_TEST

#define cTOS_INCLUDE
#define cDAT_BAT_DATAINCLUDE
#define cLAP_DIAG_DATAINCLUDE
#define cLAP_CAN_DATAINCLUDE
#define cDAT_MOD_DATAINCLUDE
#define cDAT_DOU_DATAINCLUDE
#define cDAT_DOU_FUNCINCLUDE
#define cLAP_RUNIN_DATAINCLUDE

#define cDAT_DIN_DATAINCLUDE
#define cLAP_DOOR_DATAINCLUDE
#define cLAP_DOOR_TYPEINCLUDE
#define cDAT_COM_DATAINCLUDE
#define cDAT_COM_TYPEINCLUDE
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

