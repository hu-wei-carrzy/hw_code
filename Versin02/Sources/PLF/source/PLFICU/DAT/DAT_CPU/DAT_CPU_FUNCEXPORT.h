#ifndef I_DAT_CPU_FUNCEXPORT_H
#define I_DAT_CPU_FUNCEXPORT_H



extern void DATCpuLeaveSleep(void);
extern void DATCpuEnterSleep(void);
extern void LDBReset(void) ;
extern void LDBSWReset(void);
extern void DATCpuWillReset(void);

#define mSERControlCpu(CTRL)            mSERControlCpu##CTRL()
#define mSERControlGraphEngine(CTRL)    mSERControlCpu##CTRL()
#define mSERControlCpuLeaveSleep()           (DATCpuLeaveSleep())
#define mSERControlCpuEnterSleep()            (DATCpuEnterSleep())
#define mSERControlCpuReset()           DATCpuWillReset(); LDBReset();
#define mSERControlCpuSWReset()			(LDBSWReset())

#endif
