
/*-------------------------------------------------------------------------
  Non-reentrance des inclusions
  -------------------------------------------------------------------------*/
#ifndef I_DAT_DEA_CFG_H
#define I_DAT_DEA_CFG_H

/*-------------------------------------------------------------------------
  Fichiers inclus

  #include <nom_du_ficher_systeme>
  #include "nom_du_ficher_utilisateur"
  -------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
  Constantes exportees

  #define cCOMNomConstante   ValeurDeLaConstante
  -------------------------------------------------------------------------*/

#define cDATDeaMaxByte			16U
// cDATDeaSizeEeprom must be defined in Byte
//2017-07-06 11:58:30, change the EEP size: 2048-->8192
#define cDATEEpBaseAddr			(0x30000000UL)
#define cDATDeaSizeEeprom		(cDATEEpBaseAddr + 2048UL)

#define cDATRamStartAddr		(0x1FFF8000UL)
#define cDATRamEndAddr			(0x20007FFFUL)

#define cDATFlashStartAddr 		(0x0UL)
#define cDATFlashEndAddr		(0x7FFFFUL)


/*-------------------------------------------------------------------------
  Macro exportees

  #define mCOMNomMacro   (DefinitionDeLaMacro)
  -------------------------------------------------------------------------*/ 
/*-------------------------------------------------------------------------
  Types exportes

  struct sCOMNomStructure { ... };
  union  uCOMNomUnion { ... };
  enum   eCOMNomEnumeration { ... };
  typedef ...  tCOMNomType;
  -------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------
  Variables exportees

  extern  tType   COMNomVariable;
  extern  tType*  pCOMNomVariable; 
  -------------------------------------------------------------------------*/ 
/*-------------------------------------------------------------------------
  Donnees constantes exportees

  extern const tType  COMNomVariable;
  -------------------------------------------------------------------------*/ 
/*-------------------------------------------------------------------------
  Prototypes des fonctions exportees

  extern tTypeRetour COMNomFonction(tTypeArgument1 NomArgument1, ... );
  -------------------------------------------------------------------------*/ 
/*-------------------------------------------------------------------------
  Fin de la non-reentrance des inclusions
  -------------------------------------------------------------------------*/
#endif

