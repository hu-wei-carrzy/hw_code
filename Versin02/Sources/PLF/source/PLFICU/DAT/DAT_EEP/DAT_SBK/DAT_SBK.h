


/*-------------------------------------------------------------------------
  Includes non re entry
  -------------------------------------------------------------------------*/
#ifndef I_DAT_SBK
#define I_DAT_SBK

/*-------------------------------------------------------------------------
Included files

  #include <nom_du_ficher_systeme>
  #include "nom_du_ficher_utilisateur"
-------------------------------------------------------------------------*/
#include "ARCH_CFG.h"

#include "DAT_SBK_CFG.h"       // paramétrage

#ifdef cHeadIncludeType_Directly
#include "DAT_EEP.h"
#include "DAT_EEP_TYPE.h"
#else
#include ".\..\DAT_EEP\DAT_EEP.h"
#include ".\..\DAT_EEP_TYPE.h"
#endif
/*-------------------------------------------------------------------------
Constant data

  #define cCOMNomConstante   ValeurDeLaConstante
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
Exported Macro

  #define mCOMNomMacro   (DefinitionDeLaMacro)
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
Exported type

struct sCOMNomStructure { ... };
union  uCOMNomUnion { ... };
enum   eCOMNomEnumeration { ... };
typedef ...  tCOMNomType;
-------------------------------------------------------------------------*/


// Structure qui définit les adresses utilisées par les SBK
// Allou?en ROM
typedef struct
{
    U16*            AddBlockRam;
    tDATEepOffset   SizeBlockRam;
} tDATSbkTableBankRom;

typedef enum
{
    cDATSbkErrorReading,
    cDATSbkErrorWriting
} tDATSbkErrorHandle;

/*-------------------------------------------------------------------------
Exported data

extern  tType   COMNomVariable;
extern  tType*  pCOMNomVariable;
-------------------------------------------------------------------------*/
// Structure en RAM qui permet d'accéder ?l'image RAM de la SBK
extern tDATSbkMirrors DATSbkMirrors;

/*-------------------------------------------------------------------------
Constant exported data

extern const tType  COMNomVariable;
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
Exported funcions prototype

extern tTypeRetour COMNomFonction(tTypeArgument1 NomArgument1, ... );
-------------------------------------------------------------------------*/

// Init function
extern void     DATSbkInit (void);

// RAM to EEPROM update functions
extern void     DATSbkStartUpdate           ( tDATSbkSingleBankHandle HandleSbk );
extern BOOL DATSbkIsWriteOk             ( tDATSbkSingleBankHandle HandleSbk );

// EEPROM to RAM reading functions
extern void     DATSbkStartReadingAllBanks  ( void );
extern void     DATSbkStartReading          ( tDATSbkSingleBankHandle HandleSbk );

// common functions
extern BOOL DATSbkIsBankProcessing      ( tDATSbkSingleBankHandle HandleSbk );
extern BOOL DATSbkIsProcessing          ( void );

// Callback functions
extern void     DATPeeRebuildSingleBank         ( tDATSbkSingleBankHandle HandleSbk );
extern void     DATPeeSingleBankErrorIndication ( tDATSbkSingleBankHandle HandleSbk, tDATSbkErrorHandle SbkErrorHandle );

/*-------------------------------------------------------------------------
End of includes non re entry
-------------------------------------------------------------------------*/
#endif   /* fin de l'inclusion conditionnelle de DAT_SBK.h */
