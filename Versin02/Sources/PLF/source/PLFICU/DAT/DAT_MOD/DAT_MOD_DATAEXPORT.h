#ifndef I_DAT_MOD_DATAEXPORT_H
#define I_DAT_MOD_DATAEXPORT_H



//extern BOOL DATModIsInDarkMod(void);
//extern BOOL DATModIsInOperMod(void);
//extern BOOL DATModIsInDiagMod(void);
extern	U8	DATModGetSysMod(void);
//extern BOOL DATModIsSelfChecking(void);

#define	mSERReadU8BitSysModeDefault()				DATModGetSysMod()

//#define mSERReadU1BitIsSelfCheckingDefault()         DATModIsSelfChecking()
//#define mSERReadU1BitIsInOperModDefault()            DATModIsInOperMod()
//#define mSERReadU1BitIsInDarkModDefault()            DATModIsInDarkMod()
//#define mSERReadU1BitIsInDiagModDefault()            DATModIsInDiagMod()

#endif

