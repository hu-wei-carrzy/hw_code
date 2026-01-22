#ifndef I_DAT_CPU_DATAEXPORT_H
#define I_DAT_CPU_DATAEXPORT_H

extern U32 DATCpuGetResetCause(void);

#define mSERReadU32BitResetCauseDefault()       DATCpuGetResetCause()


#endif