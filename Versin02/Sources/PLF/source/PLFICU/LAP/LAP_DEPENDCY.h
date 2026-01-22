#ifndef _LAP_COMMON_H_
#define _LAP_COMMON_H_


#include "ARCH_CFG.h"

#ifdef cHeadIncludeType_Directly
#include "LAP_LIB.h"
#ifdef cTOS_INCLUDE
#include ".\..\TOS\TOS.h"
#endif
#include "SER.h"
#include "SER_DATAEXPORT_INCLUDE.h"
#include "SER_FUNCEXPORT_INCLUDE.h"
#include "SER_TYPEEXPORT_INCLUDE.h"
#else
	

#include "LAP_LIB.h"

#ifdef cTOS_INCLUDE
#include ".\..\TOS\TOS.h"
#endif

#include ".\..\SER\SER.h"

#include ".\..\SER\SER_INCLUDE\SER_DATAEXPORT_INCLUDE.h"
#include ".\..\SER\SER_INCLUDE\SER_FUNCEXPORT_INCLUDE.h"
#include ".\..\SER\SER_INCLUDE\SER_TYPEEXPORT_INCLUDE.h"

#endif


#endif
