#ifndef I_DAT_EEP_DATAEXPORT_H
#define I_DAT_EEP_DATAEXPORT_H

#include "ARCH_CFG.h"

#ifdef cHeadIncludeType_Directly
#include "DAT_PEE.h"
#else
#include ".\DAT_PEE\DAT_PEE.h"
#endif

//for compatibility 
//the key word "mDAT" in all EEP generated files 
//has been replaced by "mSER", so here define just for 
//compatibility
#define mDATPeeResetEEPErrorTable mSERPeeResetEEPErrorTable



#endif
