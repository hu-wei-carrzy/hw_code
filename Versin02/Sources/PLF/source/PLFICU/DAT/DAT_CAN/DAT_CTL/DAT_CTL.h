
/*-------------------------------------------------------------------------
  Non-reentrance des inclusions
  -------------------------------------------------------------------------*/
#ifndef I_DAT_CTL_H
#define I_DAT_CTL_H

/*-------------------------------------------------------------------------
  Fichiers inclus

  #include <nom_du_ficher_systeme>
  #include "nom_du_ficher_utilisateur"
  -------------------------------------------------------------------------*/
#include "ARCH_CFG.h"

#ifdef cHeadIncludeType_Directly
#include "DAT_CNL.H"
#include "DAT_CTLp.H"
#else
#include ".\..\DAT_CNL\DAT_CNL.h"
#include ".\..\..\..\SCC2Gen\GEN\DAT_CTLp.h"
#endif


#define cDATCtl_NbASNonType  cDATCnl_NbASNonType
#define cDATCtl_NbAS  cDATCnl_NbAS

#ifdef cDATCtl_NbASNonType
  #if cDATCtl_NbASNonType >= 1
    #define COMPOSANT_DAT_CTL_ON
  #endif
#endif



#ifdef cDATCtl_NbSession
  #if cDATCtl_NbSession == 0 
    #define DAT_CTL_SESSION_OFF
  #else
    #define DAT_CTL_SESSION_ON
  #endif

#endif

/*-------------------------------------------------------------------------
  Constantes exportees

  #define cCOMNomConstante   ValeurDeLaConstante
  -------------------------------------------------------------------------*/


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
// Definition des differents Handles
typedef U8 tDATCtlT_ASTxHandle;
typedef U8 tDATCtlT_ASRxHandle;
typedef U8 tDATCtlT_ASHandle;

typedef U8 tDATCtlS_ASHandle;

// gestion de la session
typedef U8 tDATCTLSessionMode;
// gestion de l'acquittement
typedef U8 tMode;

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
// fonctions utilisees par DAT_CPL



#ifdef COMPOSANT_DAT_CTL_ON

// fonctions utilisees par DAT_CNM
extern void DATCtlInit(void);
extern void DATCtlTick(void);
extern void DATCtl_T_Init(void);
extern void DATCtl_T_Stop(void);

// fonctions utilisees par DAT_CIL
  #ifdef DAT_CTL_SESSION_ON

extern void DATCtlS_DisconnectReq( tDATCtlS_ASHandle TTxHandle);
  #ifdef DISCONNECTION_AUTHORIZED
extern void DATCilS_DisconnectCon( tDATCtlS_ASHandle TTxHandle ,BOOL EmissionOk);
  #endif  

extern void DATCtlS_ConnectReq( tDATCtlT_ASTxHandle TTxHandle );
extern void DATCilS_ConnectInd( tDATCtlT_ASRxHandle SRxHandle );
extern void DATCilS_ConnectCon( tDATCtlS_ASHandle TTxHandle ,BOOL EmissionOk);

extern void DATCilS_DisconnectInd( tDATCtlT_ASRxHandle SRxHandle );

extern tDATCTLSessionMode DATCilS_LireEtatSession( tDATCtlS_ASHandle SHandle);

    #endif


  #define DATCtlT_UUDataReq(TxHandle) (DATCnlN_UUDataReq(TxHandle))
  #define DATCtlT_USDataReq(TxHandle) (DATCnlN_USDataReq(TxHandle))
extern void DATCtlT_ASDataReq( tDATCtlT_ASTxHandle TTxHandle );

  #ifdef DAT_CTL_SESSION_ON
extern void DATCtlS_ASDataReq( tDATCtlS_ASHandle TTxHandle );
  #endif

// callbacks
extern void DATCilT_UUDataInd(tDATCdlD_UURxHandle DRxHandle);
extern void DATCilT_USDataInd(tDATCnlN_USHandle NRxHandle);
extern void DATCilT_ASDataInd(tDATCtlT_ASRxHandle TRxHandle);
  #ifdef DAT_CTL_SESSION_ON
extern void DATCilS_ASDataInd( tDATCtlS_ASHandle SRxHandle );
  #endif

extern void DATCilT_UUDataCon(tDATCdlD_UURxHandle DTxHandle, BOOL EmissionOk );
extern void DATCilT_USDataCon(tDATCnlN_USHandle   NTxHandle, BOOL EmissionOk );
extern void DATCilT_ASDataCon(tDATCtlT_ASRxHandle TTxHandle, BOOL EmissionOk );
  #ifdef DAT_CTL_SESSION_ON
extern void DATCilS_ASDataCon(tDATCtlS_ASHandle STxHandle, BOOL EmissionOk );
  #endif



#else

// fonctions utilisees par DAT_CNM
  #define DATCtlInit()
  #define DATCtlTick()
  #define DATCtl_T_Init()
  #define DATCtl_T_Stop()


// fonctions utilisees par DAT_CIL
  #define DATCtlT_UUDataReq(TxHandle) (DATCnlN_UUDataReq(TxHandle))
  #define DATCtlT_USDataReq(TxHandle) (DATCnlN_USDataReq(TxHandle))

// callbacks
  #define DATCilT_UUDataInd(DRxHandle) (DATCtlN_UUDataInd(DRxHandle))
  #define DATCilT_USDataInd(TRxHandle) (DATCtlN_USDataInd(TRxHandle))

  #define DATCilT_UUDataCon(DTxHandle,EmissionOk) (DATCtlN_UUDataCon(DTxHandle,EmissionOk))
  #define DATCilT_USDataCon(NTxHandle,EmissionOk ) (DATCtlN_USDataCon(NTxHandle,EmissionOk))

#endif
/*-------------------------------------------------------------------------
  Fin de la non-reentrance des inclusions
  -------------------------------------------------------------------------*/
#endif

