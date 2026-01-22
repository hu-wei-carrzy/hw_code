#ifndef  I_LAP_DIAG_FUNCEXPORT_H
#define  I_LAP_DIAG_FUNCEXPORT_H

#include "ARCH_CFG.h"
#ifdef cHeadIncludeType_Directly
#include "LAP_DIA_TYPECOMMON.h"
#else
#include ".\LAP_DIA\LAP_DIA_TYPECOMMON.h"
#endif

extern void ResetFactorySet(void);
extern void ResetAsmblLineSet(void);

#define mSERControlResetSet(Ctrl)       mSERControlResetSet##Ctrl()
#define mSERControlResetSetFacotry()    ResetFactorySet()
#define mSERControlResetSetAsmblLine()  ResetAsmblLineSet()


#endif


