#ifndef I_LAP_RUNIN_DATAEXPORT_H
#define I_LAP_RUNIN_DATAEXPORT_H




extern BOOL LAPRunInIsRunInMod(void);
extern void LAPRunInSetRunInFlag(BOOL bVal);
extern U8   LAPRunInGetLCDDisp(void );
extern void LAPRunInFlagFromDiag(U32 u32RunInFlag);

#define mSERReadU1BitIsRunInModeDefault()        LAPRunInIsRunInMod()
#define mSERReadU1BitIsSetSleepFlagDefault()          cFalse
#define mSERWriteU1BitIsSetSleepFlagDefault(bVal)   

#define mSERReadU8BitLCDDispTypeDefault()         LAPRunInGetLCDDisp()

#define mSERWriteU32BitRunInFlagFromDiagDefault(u32RunInFlag)  LAPRunInFlagFromDiag(u32RunInFlag)
#endif
