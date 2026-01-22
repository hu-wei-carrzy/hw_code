#ifndef  I_LDB_AD_LIFE_H_
#define  I_LDB_AD_LIFE_H_

#include "ARCH_CFG.h"

#ifdef cHeadIncludeType_Directly
#include "ldb.h"
#else
#include ".\..\LDB\LDB_API\ldb.h"
#endif

#define cLDBADEnterActiveMode         ((tCtrl)0x01U)
#define cLDBADEnterSleepMode          ((tCtrl)0x02U)
#define cLDBADStartAD                 ((tCtrl)0x04U)
#define cLDBADStopAD                  ((tCtrl)0x05U)
#define cLDBADStartADScan             ((tCtrl)0x06U)

// Address
#define cLDBADAdrIsScanOver           ((tAddress)0x01)
#define cLDBADReadAdValues            ((tAddress)0x02)

#endif
