
//---- Definition pour mono-inclusion -----
#ifndef I_DAT_OBK
#define I_DAT_OBK

#include "ARCH_CFG.h"

#include "DAT_OBK_CFG.h"


#ifdef cHeadIncludeType_Directly
#include "DAT_EEP.h"
#include "DAT_EEP_TYPE.h"
#else
#include ".\..\DAT_EEP\DAT_EEP.h"
#include ".\..\DAT_EEP_TYPE.h"
#endif


//-------------------------------------------------------------------------
//-------  Declaration des constantes exportees par ce composant  ---------
//-------------------------------------------------------------------------
// (Com: 3 lettres identifiant ce composant)
// #define cComNomConstante   ValeurDeLaConstante
#define cOneBank  1

//--------------------------------------------------------------------------
//-------  Declaration des macros exportees par ce composant  --------------
//--------------------------------------------------------------------------
// (Com: 3 lettres identifiant ce composant)
// #define mComNomMacro   (DefinitionDeLaMacro)


//--------------------------------------------------------------------------
//-------  Definition des types exportes par ce composant  -----------------
//--------------------------------------------------------------------------
// (Com: 3 lettres identifiant ce composant)
// typedef ...   tComNomType;
typedef struct
{
    U16 *AddBlockRam;
    tDATEepOffset SizeBlockRam;
} tDATObkTableBankRom;

typedef enum
{
    cDATObkErrorReading,
    cDATObkErrorWriting
} tDATObkErrorHandle;


//--------------------------------------------------------------------------
//-------  Declaration des variables exportees par ce composant  -----------
//--------------------------------------------------------------------------
// (Com: 3 lettres identifiant ce composant)
// extern tType   ComNomVariable;
// extern tType*  pComNomVariable;
#ifndef COMPILATION_NATIVE
//#pragma memory = dataseg(ERAM)
#endif
extern tDATObkMirrors DATObkMirrors;
#ifndef COMPILATION_NATIVE
//#pragma memory = default
#endif

// Spécifie le nombre de banques ?écrire
// Specify the number of banks to write
extern U8 DATObkNbBanksToWrite[cNbObk];

//--------------------------------------------------------------------------
//-------  Donnees Constantes exportees par ce composant  ------------------
//--------------------------------------------------------------------------
// (Com: 3 lettres identifiant ce composant)
// extern const  tType   ComNomVariable;


// Nota:
// Pour les variables qui peuvent être modifiees par CE_COMPOSANT mais non
//   par les composants utilisateurs, on utilisera une definition conditionnel
//
// #ifdef CE_COMPOSANT
// extern tType ComNomVariable;
// #else
// extern const tType ComNomVariable;
// #endif


//--------------------------------------------------------------------------
//-------  Fonctions exportees  --------------------------------------------
//--------------------------------------------------------------------------
// extern tTypeRetour NomFonction(tTypeArgument NomArgument,  ...);

// Init function
extern void DATObkInit(void);

// RAM to EEPROM update functions
extern void DATObkStartUpdate( tDATObkOdometerBankHandle HandleObk );
extern BOOL DATObkIsWriteOk( tDATObkOdometerBankHandle HandleObk );

// EEPROM to RAM reading functions
extern void DATObkStartReadingAllBanks( void );
extern void DATObkStartReading( tDATObkOdometerBankHandle HandleObk );

// common functions
extern BOOL DATObkIsBankProcessing( tDATObkOdometerBankHandle HandleObk );
extern BOOL DATObkIsProcessing( void );

// Callback functions
extern void DATPeeRebuildOdometerBank( tDATObkOdometerBankHandle HandleObk );
extern void DATPeeOdometerBankErrorIndication( tDATObkOdometerBankHandle HandleObk, tDATObkErrorHandle ObkErrorHandle );
extern BOOL DATPeeOdometerBankIsGreater( tDATObkOdometerBankHandle HandleObk );

#endif   // fin de l'inclusion conditionnelle de CE_COMPOSANT.h
