

//-------------------------------------------------------------------------
//  Non-reentrance des inclusions
//-------------------------------------------------------------------------
#ifndef I_DAT_DEA_H
#define I_DAT_DEA_H

//-------------------------------------------------------------------------
//  Fichiers inclus
//
//  #include <nom_du_ficher_systeme>
//  #include "nom_du_ficher_utilisateur"
//-------------------------------------------------------------------------
#include "ARCH_CFG.h"
#include "DAT_DEA_CFG.h"
#ifdef cHeadIncludeType_Directly
#include "DAT_EEP.h"
#else
#include ".\..\DAT_EEP\DAT_EEP.h"
#endif
//-------------------------------------------------------------------------
//  Constantes exportees
//
//  #define cCOMNomConstante   ValeurDeLaConstante
//-------------------------------------------------------------------------
//-------------------------------------------------------------------------
//  Macro exportees
//
//  #define mCOMNomMacro   (DefinitionDeLaMacro)
//------------------------------------------------------------------------- 

// This macro check that the number of byte is inferior to the max size of work buffer
#define mSERWriteU8BitDATDeaSizeBufferInByteDefault(ValueToWrite) \
    {                                                             \
        mLIBassert ((ValueToWrite)<=cDATDeaMaxByte);              \
	    DATDeaSizeBufferInByte=(ValueToWrite);                    \
    }



#define mSERReadU8BitDATDeaWriteIsOkDefault() \
			(DATDeaWriteIsOk)

#define mSERReadU8BitDATDeaReadIsOkDefault() \
			(DATDeaReadIsOk)

#define mSERReadU8BitDATDeaActionIsFinishedDefault() \
			(DATDeaActionIsFinished)

#define mSERControlDATDea(Treatment) \
			DATDea##Treatment ()

#define mSERReadBufferDATDeaBufferU8BitDefault(Index) \
			(DATDeaBufferU8Bit[(Index)])

#define mSERWriteBufferDATDeaBufferU8BitDefault(Index, ValueToWrite  ) \
			(DATDeaBufferU8Bit[(Index)]=(ValueToWrite))

#define mSERWriteU16BitDATDeaAddressInByteDefault(ValueToWrite) \
            (DATDeaAddressInByte=(ValueToWrite))

//-------------------------------------------------------------------------
//  Types exportes
//
//  struct sCOMNomStructure { ... };
//  union  uCOMNomUnion { ... };
//  enum   eCOMNomEnumeration { ... };
//  typedef ...  tCOMNomType;
//-------------------------------------------------------------------------

//-------------------------------------------------------------------------
//  Variables exportees
//
//  extern  tType   COMNomVariable;
//  extern  tType*  pCOMNomVariable; 
//------------------------------------------------------------------------- 
extern U8   DATDeaBufferU8Bit[cDATDeaMaxByte];
extern U16  DATDeaAddressInByte;
extern U8   DATDeaSizeBufferInByte;
extern BOOL DATDeaWriteIsOk;
extern BOOL DATDeaReadIsOk;
extern BOOL DATDeaActionIsFinished;
//-------------------------------------------------------------------------
//  Donnees constantes exportees
//
//  extern const tType  COMNomVariable;
//------------------------------------------------------------------------- 

//-------------------------------------------------------------------------
//  Prototypes des fonctions exportees
//
//  extern tTypeRetour COMNomFonction(tTypeArgument1 NomArgument1, ... );
//------------------------------------------------------------------------- 

extern void DATDeaStartWriteEepromByAddress(void);
extern void DATDeaStartReadEepromByAddress (void);
extern void DATDeaInitialize (void);

//-------------------------------------------------------------------------
//  Fin de la non-reentrance des inclusions
//-------------------------------------------------------------------------
#endif

