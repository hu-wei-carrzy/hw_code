

/*-------------------------------------------------------------------------
  Includes non re entry
  -------------------------------------------------------------------------*/
#ifndef I_DAT_OBK_CFG_H
#define I_DAT_OBK_CFG_H

/*-------------------------------------------------------------------------
 Included files

  #include <nom_du_ficher_systeme>
  #include "nom_du_ficher_utilisateur"
  -------------------------------------------------------------------------*/

#include "DAT_OBKx.h"

/*-------------------------------------------------------------------------
  Constant data

  #define cCOMNomConstante   ValeurDeLaConstante
  -------------------------------------------------------------------------*/
/* LES CONSTANTES DEFINIES CI DESSOUS DOIVENT ETRE MODIFIEES POUR
   CHAQUE APPLICATION */

/* CONSTANT DATA DEFINED HEREAFTER MUST BE MODIFIED FOR EACH APPLICATION */


/*  Definit le nombre d'essais de relecture
    Il est important de parametrer une grande valeur parce que si une ecriture 
    intervient aprés un cas d'echec de lecture, la banque risque d'être 
    corrompue */

/*  Define number of reading retry */
/*  It's important to configure a high value because if a writing operation
    is set after a failed reading case, the bank will be corrupted */

#define cObk_NbRetryReadDatEepMax ((U8)100UL)

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

/*  Si U8 -> jusqu'?256 blocks ;  cette déclaration doit être cohérente
    avec tDATEepProcessHandle dans DAT_EEPp.h */

/*  If U8 -> until 256 blocks ; This define must be coherent with
  tDATEepProcessHandle in DAT_EEPp.h */

typedef U8 tDATObkOdometerBankHandle;

/*-------------------------------------------------------------------------
  Exported data

  extern  tType   COMNomVariable;
  extern  tType*  pCOMNomVariable; 
  -------------------------------------------------------------------------*/ 


/*-------------------------------------------------------------------------
  Constant exported data

  extern const tType  COMNomVariable;
  -------------------------------------------------------------------------*/ 


/*-------------------------------------------------------------------------
  Exported funcions prototype

  extern tTypeRetour COMNomFonction(tTypeArgument1 NomArgument1, ... );
  -------------------------------------------------------------------------*/ 


/*-------------------------------------------------------------------------
  End of includes non re entry
  -------------------------------------------------------------------------*/
#endif

