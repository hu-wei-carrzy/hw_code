#ifndef I_DAT_COMMON_H
#define I_DAT_COMMON_H

#include "ARCH_CFG.h"

#ifdef cHeadIncludeType_Directly
#include "DAT_LIB.h"

#ifdef cTOS_INCLUDE
#include "TOS.h"
#endif

#include "SER.h"
#include "SER_TYPEEXPORT_INCLUDE.h"
#include "SER_DATAEXPORT_INCLUDE.h"
#include "SER_FUNCEXPORT_INCLUDE.h"
#include "HAL.h"
#else
#include "DAT_LIB.h"

#ifdef cTOS_INCLUDE
#include ".\..\TOS\TOS.h"
#endif

#include ".\..\SER\SER.h"
#include ".\..\SER\SER_INCLUDE\SER_TYPEEXPORT_INCLUDE.h"    
#include ".\..\SER\SER_INCLUDE\SER_DATAEXPORT_INCLUDE.h"
#include ".\..\SER\SER_INCLUDE\SER_FUNCEXPORT_INCLUDE.h"

#include ".\..\HAL\HAL.h"
#endif

#endif
