#ifndef I_DAT_DTC_FUNCEXPORT_H
#define I_DAT_DTC_FUNCEXPORT_H

#include "DAT_DTC_TYPEEXPORT.h"

extern void DATDiiReportDTC(tDTCFunCom tDTCType, BOOL bIsDTCOccur);
extern void DATDdiReadDTCInformation(void);
extern void DATDdiPrepareQuery(const U32 u32QueryAddress);
extern void DATDdbClearDTCByDTCCode();
extern void DATDdbClearAllDTCInfo(void);


#define mSERControlDTCOccur(tDTCType)       DATDiiReportDTC(tDTCType,cTrue)
#define mSERControlDTCDisappear(tDTCType)   DATDiiReportDTC(tDTCType,cFalse)

#define mSERControlDTCInfoRead(tmpDTCQuery)  DATDdiPrepareQuery((U32)(&tmpDTCQuery));\
                                             DATDdiReadDTCInformation();

//two way for clearing DTC:
//ClearAllDTCInfo
//ClearDTCByDTCCode
#define mSERControlDTCInfoClear(WayOfClearDTC)            DATDdb##WayOfClearDTC()


#endif
