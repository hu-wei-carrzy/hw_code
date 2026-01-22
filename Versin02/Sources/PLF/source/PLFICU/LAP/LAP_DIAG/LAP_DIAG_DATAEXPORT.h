#ifndef  I_LAP_DIAG_DATAEXPORT_H
#define  I_LAP_DIAG_DATAEXPORT_H

#include "ARCH_CFG.h"
#ifdef cHeadIncludeType_Directly
#include "LAP_DIA_TYPECOMMON.h"
#else
#include ".\LAP_DIA\LAP_DIA_TYPECOMMON.h"
#endif



extern BOOL LAPDiaGetCurDiagSt(void);
extern void LAPDiaSetTestMode(BOOL mode);
extern BOOL LAPDiaGetTestMode(void);

#define mSERReadU1BitIsDiagModeDefault()                       LAPDiaGetCurDiagSt()
#define mSERWriteU8BitTestModeDEFAULT(a)					   LAPDiaSetTestMode(a)
#define mSERReadU1BitIsTestModeDefault()					   LAPDiaGetTestMode()

#define mSERReadU8BitTestEnableFlagDefault()					LAPDiaGetTestEnableflag()

#define mSERWriteU8BitTestEnableFlagDefault(Sta)				LAPDiaSetTestEnableflag(Sta)


#endif


