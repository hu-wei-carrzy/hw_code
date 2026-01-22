
/*-------------------------------------------------------------------------
  Identification du corps
  -------------------------------------------------------------------------*/
#define dat_ctl  "dat_ctl"

/*-------------------------------------------------------------------------
  Fichiers inclus

  #include <nom_du_ficher_systeme.h>
  #include "nom_du_ficher_utilisateur.h"
  -------------------------------------------------------------------------*/ 
#include "DAT_CTL.h"



/*-------------------------------------------------------------------------
  Macro locales

  #define mNomMacro   (DefinitionDeLaMacro)
  -------------------------------------------------------------------------*/  

// ITX   TTX   NTX   DTX
//                      _                        _                  _
//  0 --> 0 --> 0 --> 0 _| cDATCtl_NbSession = 1  |                  |
//  1 --> 1 --> 1 --> 1                          _| cDATCtl_NbAS = 2 | cDATCnl_NbUS =3
//  2 --> 2 --> 2 --> 2                                             _|(parametrage dans CNLP.h)
//  3 --------> 3 --> 0
//  4 --------> 4 --> 0

// Le Handle ITx  0 est associe au message de Handle NTX = 0, ce message
// (segmente acquitte avec session) utilise la trame de Handle DTX = 0
// Le Handle ITx  1 est associe au message de Handle NTX = 1, ce message
// (segmente acquitte SANS session) utilise la trame de Handle DTX = 1
// Le Handle ITx  2 est associe au message de Handle NTX = 2, ce message
// (segmente) utilise la trame de Handle DTX = 2
// Le Handle ITx 3 est associe a la trame DTX 0.
// Le Handle NTX 3 n'existe pas.

/*-------------------------------------------------------------------------
  Types locaux

  struct  sNomStructure { ... };
  union   uNomUnion { ... };
  enum    eNomEnumeration { ... };
  typedef Expression tNomType;
  -------------------------------------------------------------------------*/

#ifdef COMPOSANT_DAT_CTL_ON
//Pour les tests #if
#define cTimeOutAcquittementEnTick_NonType    ((cDATCtlTimeOutEnMsT_A/cDATCdlTickMs)+1)
#define cTimeOutEnTickT_B_NonType             ((cDATCtlTimeOutEnMsT_B/cDATCdlTickMs)+1)

#if (cTimeOutEnTickT_B_NonType<255) 
typedef U8 tCptTimeoutT_B_EnTick;
#else
typedef U16 tCptTimeoutT_B_EnTick;
#endif

#if (cTimeOutAcquittementEnTick_NonType<255) 
typedef U8 tCptTimeoutT_A_EnTick;
#else
typedef U16 tCptTimeoutT_A_EnTick;
#endif


//Etat de la couche transport (l'etat de la couche session est le même, le filtrage n'est fait qu'au niveau transport pour le moment)
//Une seule couche est définie (pas de multi CAN au niveau transport/session) pour l'instant
typedef U8 tTransportSessionLayer;

// Structure contenant les informations sur un message en reception
typedef struct
{
    tCptTimeoutT_A_EnTick        T_A_CompteurTick; // Timeout/ delai sur acquittement
    tCptTimeoutT_B_EnTick        T_B_CompteurTick; // Timeout sur confirmation emission
    U8        T_Trial;          // nb d'essais
    tMode         Mode;             // Mode de fonctionnement
} tAkMessage;
#endif // COMPOSANT_DAT_CTL_ON
/*-------------------------------------------------------------------------
  Constantes locales

  #define cNomConstante   ValeurDeLaConstante
  -------------------------------------------------------------------------*/  

#define cPciCS ((U8) (0x70))
#define cPciDS ((U8) (0x72))
#define cPciAK ((U8) (0x74))
// l'octet ci dessous est different de cPciCS, cPciDS, cPciAK
#define cOctetDeConnectionNonUtilise ((U8) (0x00))

#define cTranportSessionLayerIsNotActived ((U8) (0x00))
#define cTranportSessionLayerIsActived    ((U8) (0x01))

#define cTimeOutAcquittementEnTick    ((tCptTimeoutT_A_EnTick)  ((cDATCtlTimeOutEnMsT_A/cDATCdlTickMs)+1))
#define cTimeOutEnTickT_B             ((tCptTimeoutT_B_EnTick)  ((cDATCtlTimeOutEnMsT_B/cDATCdlTickMs)+1))

//Gestion des sessions
#define cSessionNonInitialisee  ((tDATCTLSessionMode)0x00)
#define cSessionFermee  ((tDATCTLSessionMode)0x01)
#define cSessionOuverte  ((tDATCTLSessionMode)0x02)
#define cTransmission  ((tDATCTLSessionMode)0x04)
#define cConnectionSetUp  ((tDATCTLSessionMode)0x08)
#define cDeconnectionSetUp  ((tDATCTLSessionMode)0x10)

// gestion de l'ASDT
#define cNonInitialisee  ((tMode)0x00)
#define cAttenteRxTx  ((tMode)0x01)
#define cAttenteAcquittement  ((tMode)0x02)
#define cEmission  ((tMode)0x04)
#define cReception  ((tMode)0x08)
#define cAttenteReemission  ((tMode)0x10)

/*-------------------------------------------------------------------------
  Variables locales

  static  tType   NomVariable;
  static  tType*  pNomVariable; 
  -------------------------------------------------------------------------*/
#ifdef COMPOSANT_DAT_CTL_ON

static tAkMessage AkMessages[cDATCtl_NbAS];
static U8 SaveFirstByteInRxBuffer[cDATCtl_NbAS];
static tTransportSessionLayer TransportSessionState;
#ifdef DAT_CTL_SESSION_ON
static tDATCTLSessionMode  EtatSession[cDATCtl_NbSession];
#endif
/*-------------------------------------------------------------------------
  Donnees constantes locales

  static const tType  NomVariable;
  -------------------------------------------------------------------------*/  

/*-------------------------------------------------------------------------
  Variables exportees

  tType   COMNomVariable;          (COM: 3 lettres identifiant ce composant)
  tType*  pCOMNomVariable;         (COM: 3 lettres identifiant ce composant)
  -------------------------------------------------------------------------*/ 

/*-------------------------------------------------------------------------
  Donnees constantes exportees
 
  const tType   COMNomVariable;    (COM: 3 lettres identifiant ce composant)
  -------------------------------------------------------------------------*/ 



/*-------------------------------------------------------------------------
  Prototypes des fonctions locales

  static tTypeRetour NomFonction(tTypeArgument1 NomArgument1, ... );
  -------------------------------------------------------------------------*/
static void DATCtlS_ASDataInd( tDATCtlS_ASHandle SRxHandle );
static void DATCtlS_ASDataCon( tDATCtlS_ASHandle STxHandle , BOOL EmissionOk);
static void EnvoiMessageSelonSession( tDATCtlT_ASTxHandle TTxHandle );
static void InitialiseAkMessage( tDATCtlT_ASTxHandle THandle );
#ifdef DAT_CTL_SESSION_ON
static void InitialiseSession( tDATCtlS_ASHandle SHandle );
#endif
/*.........................................................................
  ........................... FONCTIONS LOCALES ...........................
  .........................................................................*/

/*=========================================================================
! Fonction ......... InitialiseSession
!--------------------------------------------------------------------------
!
!--------------------------------------------------------------------------
! Precondition (parametres):
!
! Type            Nom                           Min          Max
! -------------------------------------------------------------------------
!
!--------------------------------------------------------------------------
! Postcondition (valeur de retour):
!
! Type            Nom                           Min          Max
!==========================================================================*/
#ifdef DAT_CTL_SESSION_ON
static void InitialiseSession( tDATCtlS_ASHandle SHandle )
{
    EtatSession[SHandle] = cSessionFermee;
}
#endif

/*=========================================================================
! Fonction ......... InitialiseAkMessage
!--------------------------------------------------------------------------
!
!--------------------------------------------------------------------------
! Precondition (parametres):
!
! Type            Nom                           Min          Max
! -------------------------------------------------------------------------
!
!--------------------------------------------------------------------------
! Postcondition (valeur de retour):
!
! Type            Nom                           Min          Max
!==========================================================================*/
static void InitialiseAkMessage( tDATCtlT_ASTxHandle THandle )
{

    tAkMessage *pMessage = &AkMessages[THandle];

    pMessage->T_A_CompteurTick = ((tCptTimeoutT_A_EnTick)0);

    pMessage->T_B_CompteurTick = ((tCptTimeoutT_B_EnTick)0);

    pMessage->Mode             = cAttenteRxTx;

    pMessage->T_Trial          = ((U8)0);
}

/*=========================================================================
! Fonction ......... EnvoiMessageSelonSession
!--------------------------------------------------------------------------
! Role de la fonction: Envoi un message acquitt?: 
! Connection / Deconnection / normal
!--------------------------------------------------------------------------
! Precondition (parametres):
!
! Type            Nom                           Min          Max
! -------------------------------------------------------------------------
!
!--------------------------------------------------------------------------
! Postcondition (valeur de retour):
!
! Type            Nom                           Min          Max
!==========================================================================*/

static void EnvoiMessageSelonSession( tDATCtlT_ASTxHandle TTxHandle )
{
    mLIBassert( TTxHandle < cDATCdl_NbUUTx );

    #ifdef DAT_CTL_SESSION_ON
    // pour des messages acquites en session
    if (TTxHandle < cDATCtl_NbSession)
    {
        switch( EtatSession[TTxHandle])
        {
        case cConnectionSetUp: // demande de connection
            {
                DATCnlN_USDataReqCS(TTxHandle) ;
            }
            break;

        #ifdef DISCONNECTION_AUTHORIZED
        case cDeconnectionSetUp: // demande de deconnection
            {
                DATCnlN_USDataReqDS(TTxHandle) ;
            }
            break;
        #endif

        default : // cas nominal
            DATCnlN_USDataReq(TTxHandle) ;
            break;
        }
    }
    else
    {
    #endif

        DATCnlN_USDataReq(TTxHandle) ;

    #ifdef DAT_CTL_SESSION_ON
    }
    #endif
}


/*.........................................................................
  ........................... FONCTIONS EXPORTEES .........................
  .........................................................................*/

/*=========================================================================
! Fonction ......... DATCilInit
!--------------------------------------------------------------------------
! Role de la fonction:
!  Cette fonction initialise ce composant, elle doit être appele a l'init
!  du calculateur. 
!--------------------------------------------------------------------------
! Precondition (parametres):
!
! Type            Nom                           Min          Max
! -------------------------------------------------------------------------
!
!--------------------------------------------------------------------------
! Postcondition (valeur de retour):
!
! Type            Nom                           Min          Max
!==========================================================================*/
void DATCtlInit(void)
{
    tDATCtlS_ASHandle THandle;
    mLIBassert(cDATCtl_NbSession<=cDATCtl_NbAS );

    TransportSessionState = cTranportSessionLayerIsNotActived;

    for( THandle=0; THandle < cDATCtl_NbAS; THandle++ )
    {
        InitialiseAkMessage(THandle);
        AkMessages[THandle].Mode = cNonInitialisee;
    }

    #ifdef DAT_CTL_SESSION_ON
    for( THandle=0; THandle < cDATCtl_NbSession; THandle++ )
    {
        EtatSession[ THandle ] = cSessionNonInitialisee;
    }
    #endif
}


/*=========================================================================
! Fonction ......... DATCtlTick
!--------------------------------------------------------------------------
! Role de la fonction:
!
!--------------------------------------------------------------------------
! Precondition (parametres):
!
! Type              Nom                       Min          Max
! -------------------------------------------------------------------------
!
!--------------------------------------------------------------------------
! Postcondition (valeur de retour):
!
! Type            Nom                           Min          Max
!==========================================================================*/
void DATCtlTick(void)
{
    tDATCtlT_ASHandle THandle;

    for( THandle=0; THandle < cDATCtlNbASTx; THandle++ )
    {
        tAkMessage *pMessage = &AkMessages[THandle];

        if (pMessage->T_B_CompteurTick != ((tCptTimeoutT_B_EnTick)0) )
        {
            pMessage->T_B_CompteurTick--;

            if(pMessage->T_B_CompteurTick == ((tCptTimeoutT_B_EnTick)0))
            {
                // incremente le compteur de reemission
                pMessage->T_Trial++;
                // M.G. modif 13/05/02 : force pour le cas ou l'acquittement tombe entre TA et TA+TB
                pMessage->Mode = cEmission;
                // on reemet
                EnvoiMessageSelonSession(THandle) ;
            }
        }

        if (pMessage->T_A_CompteurTick != ((tCptTimeoutT_A_EnTick)0) )
        {
            pMessage->T_A_CompteurTick--;

            if(pMessage->T_A_CompteurTick == ((tCptTimeoutT_A_EnTick)0))
            {
                // nombre de reemission < nb de reemission max
                if ( pMessage->T_Trial < ((U8)cDATCtlT_TrialMax))
                {
                    pMessage->T_B_CompteurTick = cTimeOutEnTickT_B;
                    // M.G. modif 13/05/02 : cas ou l'acquittement tombe entre TA et TA+TB
                    pMessage->Mode = cAttenteReemission;
                }
                else // on a atteint le nb max de reemission
                {
                    // avertir les couches superieures de la non reception
                    DATCtlS_ASDataCon(THandle,cFalse );
                    // Raz du flag d'attente de la trame d'acquittement
                    pMessage->Mode = cAttenteRxTx;
                }
            }
        }
    }
}



/*=========================================================================
! Fonction ......... DATCtl_T_Init
!--------------------------------------------------------------------------
! Role de la fonction:
!--------------------------------------------------------------------------
! Precondition (parametres):
!
! Type              Nom                       Min          Max
! -------------------------------------------------------------------------
!
!--------------------------------------------------------------------------
! Postcondition (valeur de retour):
!
! Type            Nom                           Min          Max
!==========================================================================*/
void DATCtl_T_Init(void)
{

    tDATCtlT_ASTxHandle THandle;

    TransportSessionState = cTranportSessionLayerIsActived;

    for( THandle=0; THandle < cDATCtl_NbAS; THandle++ )
    {
        InitialiseAkMessage(THandle);
        SaveFirstByteInRxBuffer[THandle] = cOctetDeConnectionNonUtilise;
    }

    #ifdef DAT_CTL_SESSION_ON  

    mLIBassert(cDATCtl_NbSession<=cDATCtl_NbAS );
    for( THandle=0; THandle < cDATCtl_NbSession; THandle++ )
    {
        InitialiseSession(THandle);
    }
    #endif

}

/*=========================================================================
! Fonction ......... DATCtl_T_Stop
!--------------------------------------------------------------------------
! Role de la fonction:
!--------------------------------------------------------------------------
! Precondition (parametres):
!
! Type              Nom                       Min          Max
! -------------------------------------------------------------------------
!
!--------------------------------------------------------------------------
! Postcondition (valeur de retour):
!
! Type            Nom                           Min          Max
!==========================================================================*/
void DATCtl_T_Stop(void)
{
    tDATCtlS_ASHandle THandle;
    mLIBassert(cDATCtl_NbSession<=cDATCtl_NbAS );

    TransportSessionState = cTranportSessionLayerIsNotActived;

    for( THandle=0; THandle < cDATCtl_NbAS; THandle++ )
    {
        AkMessages[THandle].Mode = cNonInitialisee;
        //Arret de la gestion des erreurs
        AkMessages[THandle].T_B_CompteurTick = ((tCptTimeoutT_B_EnTick)0);
        AkMessages[THandle].T_A_CompteurTick = ((tCptTimeoutT_A_EnTick)0);
        AkMessages[THandle].T_Trial = 0;
    }

    mLIBassert(cDATCtl_NbSession<=cDATCtl_NbAS );

    #ifdef DAT_CTL_SESSION_ON
    for( THandle=0; THandle < cDATCtl_NbSession; THandle++ )
    {
        EtatSession[ THandle ] = cSessionNonInitialisee;
    }
    #endif
}

/*=========================================================================
! Fonction ......... DATCtlN_UUDataInd
!--------------------------------------------------------------------------
! Role de la fonction:
!  Cette fonction signale la reception d'une trame
!--------------------------------------------------------------------------
! Precondition (parametres):
!
! Type                Nom                    Min          Max
! tDATCdlD_UURxHandle DRxHandle              
! -------------------------------------------------------------------------
!
!--------------------------------------------------------------------------
! Postcondition (valeur de retour):
!
! Type            Nom                           Min          Max
!==========================================================================*/
void DATCtlN_UUDataInd( tDATCdlD_UURxHandle DRxHandle )
{

    mLIBassert( DRxHandle < cDATCdl_NbUURx );

    DATCilT_UUDataInd(DRxHandle );
}


/*=========================================================================
! Fonction ......... DATCtlN_UUDataCon
!--------------------------------------------------------------------------
! Role de la fonction:
!  Cette fonction signale la confirmation d'une emission de trame
!--------------------------------------------------------------------------
! Precondition (parametres):
!
! Type                Nom                    Min          Max
! tDATCnlN_USHandle NRxHandle              
! BOOL            EmissionOk 
! -------------------------------------------------------------------------
!
!--------------------------------------------------------------------------
! Postcondition (valeur de retour):
!
! Type            Nom                           Min          Max
!==========================================================================*/
void DATCtlN_UUDataCon( tDATCdlD_UUTxHandle DTxHandle, BOOL EmissionOk )
{
    mLIBassert( DTxHandle < cDATCdl_NbUUTx );

    DATCilT_UUDataCon(DTxHandle,EmissionOk );
}

/*=========================================================================
! Fonction ......... DATCtlT_UUDataReq
!--------------------------------------------------------------------------
! Role de la fonction:
!--------------------------------------------------------------------------
! Precondition (parametres):
!
! Type                Nom                    Min          Max
! tDATCnlN_USHandle NRxHandle              
! -------------------------------------------------------------------------
!
!--------------------------------------------------------------------------
! Postcondition (valeur de retour):
!
! Type            Nom                           Min          Max
!==========================================================================*/
/*
void DATCtlT_UUDataReq( tDATCtlT_ASHandle TxHandle)
{
  mLIBassert( TxHandle < cDATCdl_NbUUTx );

  DATCnlN_UUDataReq( mConvertirTTxHandleEnDTx( TxHandle ) );  
}
*/

/*=========================================================================
! Fonction ......... DATCtlN_ASDataInd
!--------------------------------------------------------------------------
! Role de la fonction:
!  Cette fonction signale la reception d'un NPCI transport
!--------------------------------------------------------------------------
! Precondition (parametres):
!
! Type                Nom                    Min          Max
! tDATCtlT_ASHandle TRxHandle              
! -------------------------------------------------------------------------
!
!--------------------------------------------------------------------------
! Postcondition (valeur de retour):
!
! Type            Nom                           Min          Max
!
!
!==========================================================================*/
void DATCtlN_ASDataInd( tDATCnlN_USHandle TRxHandle )
{
    // reception d'un PCI concernant la couche CTL

    //Il ne faut pas qu'un 7x sur un ID USDT soit trait?
    mLIBassert( TRxHandle < cDATCnl_NbAS );

    if(TransportSessionState != cTranportSessionLayerIsNotActived)
    {// cas des handles correspondant a des receptions de messages AS et couche Transport activée

        tAkMessage *pMessage = &AkMessages[TRxHandle];

        SaveFirstByteInRxBuffer[TRxHandle] = DATCnlByteMemoryTableROM[TRxHandle].pBuffer[0];

        switch (SaveFirstByteInRxBuffer[TRxHandle])
        {
        case cPciAK :
            {
                if(TRxHandle < cDATCtlNbASTx)
                {
                    if((pMessage->Mode == cAttenteAcquittement))
                    {// si la trame d'acquittement arrive bien apres le message segmente

                        // raz attente time out acquittement
                        pMessage->T_A_CompteurTick = ((tCptTimeoutT_A_EnTick)0);

                        pMessage->Mode = cAttenteRxTx;

                        // confirmation a la couche superieure que l'emission est OK ou NOK
                        DATCtlS_ASDataCon(TRxHandle,cTrue );
                    }
                    else if(pMessage->Mode == cTransmission)
                    {//Un Ack non attendu arrive et le canal est en émission: il faut r?emettre le message
                        DATCtlN_USDataCon(TRxHandle,cFalse );
                    }
                    //Sinon on l'Ack arrive entre les timeout TA et TA+TB
                }//Un ack recu sur un canal en réception n'est pas trait?
                break;
            }

        case cPciCS :
        case cPciDS :
            {
                if(TRxHandle >= cDATCtlNbASTx)
                {
                    pMessage->Mode = cReception;
                    DATCnlN_USDataReqAcq(TRxHandle);
                }
            }
            break;

        default :
            //PCI 7x non utilis?
            break;
        }
    }
}



/*=========================================================================
! Fonction ......... DATCtlN_USDataInd
!--------------------------------------------------------------------------
! Role de la fonction:
!  Cette fonction signale la reception d'un message
!--------------------------------------------------------------------------
! Precondition (parametres):
!
! Type                Nom                    Min          Max
! tDATCtlT_USHandle NRxHandle              
! -------------------------------------------------------------------------
!
!--------------------------------------------------------------------------
! Postcondition (valeur de retour):
!
! Type            Nom                           Min          Max
!
! Modification : 
! Marc GOUVERNON le 11/03/2002 :
! - Correction : en reception ASDT, on ne recoit que si la  Session est Ouverte
!
!==========================================================================*/
void DATCtlN_USDataInd( tDATCnlN_USHandle TRxHandle )
{

    mLIBassert( TRxHandle < cDATCnl_NbUS );

    if (TRxHandle >= cDATCtl_NbAS) // cas des handles correspondant a des receptions de messages US
    {
        DATCilT_USDataInd(TRxHandle);
    }
    #ifdef DAT_CTL_SESSION_ON
    else if(  (TransportSessionState != cTranportSessionLayerIsNotActived)
              &&(TRxHandle >= cDATCtlNbASTx)
              &&((TRxHandle>=cDATCtl_NbSession)||(EtatSession[TRxHandle] == cSessionOuverte)) )
    #else
    else if(  (TransportSessionState != cTranportSessionLayerIsNotActived)
            &&(TRxHandle >= cDATCtlNbASTx))
    #endif

    {// cas des handles correspondant a des canaux en receptions de messages AS et couche Transport activée
        tAkMessage *pMessage = &AkMessages[TRxHandle];

        SaveFirstByteInRxBuffer[TRxHandle] = DATCnlByteMemoryTableROM[TRxHandle].pBuffer[0];
        pMessage->Mode = cReception;
        DATCnlN_USDataReqAcq(TRxHandle);

    }
    //La couche n'étant pas activée (services ASDT non démarrés) il ne faut pas acquitter les trames ASDT recues
    //ou le message est recu sur un canal qui n'est pas en réception
}





/*=========================================================================
! Fonction ......... DATCtlN_USDataCon
!--------------------------------------------------------------------------
! Role de la fonction:
!  Cette fonction signale la confirmation d'une emission de trame
!--------------------------------------------------------------------------
! Precondition (parametres):
!
! Type                Nom                    Min          Max
! tDATCnlN_USHandle NRxHandle              
! BOOL            EmissionOk 
! -------------------------------------------------------------------------
!
!--------------------------------------------------------------------------
! Postcondition (valeur de retour):
!
! Type            Nom                           Min          Max
!==========================================================================*/
void DATCtlN_USDataCon( tDATCnlN_USHandle NTxHandle, BOOL EmissionOk )
{

    mLIBassert( NTxHandle < cDATCnl_NbUS );

    if (NTxHandle < cDATCtl_NbAS)
    {
        // NTXHandle est AS
        if(TransportSessionState != cTranportSessionLayerIsNotActived)
        {//Couche transport active
         //(permet d'éviter le cas ou l'arret est en cours et de rearmer+traiter le timeout)
    
            tAkMessage *pMessage = &AkMessages[NTxHandle];

            switch (pMessage->Mode)
            {

            case cEmission :
                {

                    if (EmissionOk==cTrue)
                    {
                        // arme time out reception trame d'acquittement
                        pMessage->T_A_CompteurTick = cTimeOutAcquittementEnTick;

                        pMessage->Mode             = cAttenteAcquittement;

                    }
                    else // erreur d'emission
                    {
                        // on peut rejouer ...
                        if (pMessage->T_Trial < ((U8)cDATCtlT_TrialMax) )
                        {
                            pMessage->T_B_CompteurTick = cTimeOutEnTickT_B;

                        }
                        else // perdu !
                        {
                            pMessage->T_B_CompteurTick = ((tCptTimeoutT_B_EnTick)0);

                            DATCtlS_ASDataCon(NTxHandle,cFalse);
                        }
                    }

                }
                break;

            case cReception :
                {
                    pMessage->Mode = cAttenteRxTx;

                    if (EmissionOk == cTrue)
                    {
                        DATCtlS_ASDataInd(NTxHandle);
                    }

                }
                break;

            default:
                //Une émission de Ack est confirm?trop tard (une nouvelle réception a annul?la précedente)
                break;
            }
        }
        //Sinon la couche transport est désactivée: on ne traite plus les Ind, Req et Con
    }
    else // NTXHandle est US
    {
        DATCilT_USDataCon(NTxHandle,EmissionOk );
    }
}

/*=========================================================================
! Fonction ......... DATCtlT_ASDataReq
!--------------------------------------------------------------------------
! Role de la fonction:
!  Cette fonction traite une demande d'emission de trame
!--------------------------------------------------------------------------
! Precondition (parametres):
!
! Type                Nom                    Min          Max
! -------------------------------------------------------------------------
!
!--------------------------------------------------------------------------
! Postcondition (valeur de retour):
!
! Type            Nom                           Min          Max
!==========================================================================*/
void DATCtlT_ASDataReq( tDATCtlT_ASTxHandle TTxHandle )
{
    tAkMessage *pMessage = &AkMessages[TTxHandle];

    mLIBassert( TTxHandle < cDATCtlNbASTx );

    //Si la couche transport n'est pas active il ne faut pas emettre
    mLIBassert(TransportSessionState != cTranportSessionLayerIsNotActived);

    #ifdef DAT_CTL_SESSION_ON
    #ifdef DISCONNECTION_AUTHORIZED
    //Permettre l'émission de trames DS pendant une connection en cours (mais pas une émission)
    mLIBassert((pMessage->Mode & (cNonInitialisee|cAttenteReemission)) == (tMode)0);
    #else
    mLIBassert((pMessage->Mode & (cNonInitialisee|cEmission|cAttenteAcquittement|cAttenteReemission)) == (tMode)0);
    #endif
    #endif

    //EPT PON URD45 DEV 281 / PON URD45 BODY_SW 176
    InitialiseAkMessage(TTxHandle);

    pMessage->Mode = cEmission;

    EnvoiMessageSelonSession(TTxHandle);
}


/*=========================================================================
! Fonction ......... DATCtlS_ConnectReq
!--------------------------------------------------------------------------
! Role de la fonction:
!  Cette fonction signale la confirmation d'une emission de trame
!--------------------------------------------------------------------------
! Precondition (parametres):
!
! Type                Nom                    Min          Max
! -------------------------------------------------------------------------
!
!--------------------------------------------------------------------------
! Postcondition (valeur de retour):
!
! Type            Nom                           Min          Max
!==========================================================================*/
#ifdef DAT_CTL_SESSION_ON
void DATCtlS_ConnectReq( tDATCtlS_ASHandle TTxHandle )
{

    mLIBassert( TTxHandle < cDATCtl_NbSession );
    mLIBassert( TTxHandle < cDATCtlNbASTx );
    //Si la couche transport n'est pas active il ne faut pas emettre (car il n'y a pas de gestion des confirmations d'émission)
    mLIBassert(TransportSessionState != cTranportSessionLayerIsNotActived);

    InitialiseAkMessage(TTxHandle);
    EtatSession[TTxHandle] = cConnectionSetUp;

    DATCtlT_ASDataReq(TTxHandle);

}
#endif






/*=========================================================================
! Fonction ......... DATCtlS_DisconnectReq
!--------------------------------------------------------------------------
! Role de la fonction:
!  Cette fonction signale la confirmation d'une emission de trame
!--------------------------------------------------------------------------
! Precondition (parametres):
!
! Type                Nom                    Min          Max
! -------------------------------------------------------------------------
!
!--------------------------------------------------------------------------
! Postcondition (valeur de retour):
!
! Type            Nom                           Min          Max
!==========================================================================*/
#ifdef DAT_CTL_SESSION_ON
void DATCtlS_DisconnectReq( tDATCtlS_ASHandle TTxHandle )
{

    mLIBassert( TTxHandle < cDATCtl_NbSession );

    #ifdef DISCONNECTION_AUTHORIZED
    //Si la couche transport n'est pas active il ne faut pas emettre (car il n'y a pas de gestion des confirmations d'émission)
    mLIBassert(TransportSessionState != cTranportSessionLayerIsNotActived);
    #endif

    if( (EtatSession[TTxHandle] & (cConnectionSetUp|cTransmission|cSessionOuverte)) != (tDATCTLSessionMode)0)
    {
        InitialiseAkMessage(TTxHandle);

        #ifdef DISCONNECTION_AUTHORIZED
        EtatSession[TTxHandle] = cDeconnectionSetUp;
        DATCtlT_ASDataReq(TTxHandle);
        #endif

    }

}
#endif

/*=========================================================================
! Fonction ......... DATCtlS_ASDataInd
!--------------------------------------------------------------------------
! Role de la fonction:
!  Cette fonction signale la reception d'un message
!--------------------------------------------------------------------------
! Precondition (parametres):
!
! Type                Nom                    Min          Max
! tDATCtlT_USHandle NRxHandle              
! -------------------------------------------------------------------------
!
!--------------------------------------------------------------------------
! Postcondition (valeur de retour):
!
! Type            Nom                           Min          Max
!==========================================================================*/
static void DATCtlS_ASDataInd( tDATCtlS_ASHandle SRxHandle )
{

    mLIBassert( SRxHandle < cDATCtl_NbAS );
    #ifdef DAT_CTL_SESSION_ON
    if (SRxHandle < cDATCtl_NbSession)
    {

        switch ( EtatSession[SRxHandle])
        {

        case cSessionFermee :
            {
                // reception d'un PCI concernant la couche CTL
                switch (SaveFirstByteInRxBuffer[SRxHandle])
                {
                case cPciCS :
                    EtatSession[ SRxHandle ] = cSessionOuverte;
                    DATCilS_ConnectInd(SRxHandle);
                    break;

                case cPciDS :
                    DATCilS_DisconnectInd(SRxHandle);
                    break;

                default:
                    mLIBassert(0);
                    break;
                }

            }
            break;

        case cSessionOuverte :
            {
                // reception d'un PCI concernant la couche CTL
                switch(SaveFirstByteInRxBuffer[SRxHandle])
                {
                case cPciDS :
                    EtatSession[ SRxHandle ] = cSessionFermee;
                    DATCilS_DisconnectInd(SRxHandle);
                    break;

                case cPciCS :
                    DATCilS_ConnectInd(SRxHandle);
                    break;

                default :
                    // reception d'un message AS en session
                    DATCilS_ASDataInd(SRxHandle );
                    break;
                }
            }
            break;

        default :
            mLIBassert(0);
            break;
        }

        SaveFirstByteInRxBuffer[SRxHandle] = cOctetDeConnectionNonUtilise;

    }
    else
    #endif
    {
        DATCilT_ASDataInd(SRxHandle );
    }
}

/*=========================================================================
! Fonction ......... DATCtlS_ASDataReq
!--------------------------------------------------------------------------
! Role de la fonction:
!  Cette fonction traite la demande d'émission d'une trame sous session
!--------------------------------------------------------------------------
! Precondition (parametres):
!
! Type                Nom                    Min          Max
! -------------------------------------------------------------------------
!
!--------------------------------------------------------------------------
! Postcondition (valeur de retour):
!
! Type            Nom                           Min          Max
!==========================================================================*/
#ifndef DAT_CTL_SESSION_OFF
void DATCtlS_ASDataReq( tDATCtlS_ASHandle TTxHandle )
{
    mLIBassert(TTxHandle < cDATCtl_NbSession);

    //Si la couche transport n'est pas active il ne faut pas emettre (car il n'y a pas de gestion des confirmations d'émission)
    mLIBassert(TransportSessionState != cTranportSessionLayerIsNotActived);

    if( (EtatSession[ TTxHandle ] & (cSessionOuverte|cTransmission)) != (tDATCTLSessionMode)0)
    {
        EtatSession[ TTxHandle ] = cTransmission;

        DATCtlT_ASDataReq(TTxHandle );
    }
    else
    {
        DATCilT_ASDataCon(TTxHandle, cFalse);
    }
}
#endif

/*=========================================================================
! Fonction ......... DATCtlS_ASDataCon
!--------------------------------------------------------------------------
! Role de la fonction:
!  Cette fonction signale la confirmation d'une emission de trame sous session
!--------------------------------------------------------------------------
! Precondition (parametres):
!
! Type                Nom                    Min          Max
! tDATCnlN_USHandle NRxHandle              
! BOOL            EmissionOk 
! -------------------------------------------------------------------------
!
!--------------------------------------------------------------------------
! Postcondition (valeur de retour):
!
! Type            Nom                           Min          Max
!==========================================================================*/
static void DATCtlS_ASDataCon( tDATCtlS_ASHandle STxHandle, BOOL EmissionOk )
{

    mLIBassert(STxHandle < cDATCtl_NbAS);

    #ifdef DAT_CTL_SESSION_ON
    // pour les sessions :
    if (STxHandle < cDATCtl_NbSession)
    {
        switch (EtatSession[ STxHandle ])
        {

        case cConnectionSetUp:
            {

                if (EmissionOk != cFalse)
                {
                    EtatSession[ STxHandle ] = cSessionOuverte;
                }
                else
                {
                    EtatSession[ STxHandle ] = cSessionFermee;
                }

                DATCilS_ConnectCon(STxHandle,EmissionOk);
            }
            break;

        #ifdef DISCONNECTION_AUTHORIZED
        case cDeconnectionSetUp:
            {
                if (EmissionOk != cFalse)
                {
                    EtatSession[ STxHandle ] = cSessionFermee;
                }
                else
                {
                    EtatSession[ STxHandle ] = cSessionOuverte;
                }

                DATCilS_DisconnectCon(STxHandle,EmissionOk);
            }
            break;
        #endif

        case cTransmission :
            {
                if (EmissionOk != cFalse)
                {
                    EtatSession[ STxHandle ] = cSessionOuverte;
                }
                else
                {
                    EtatSession[ STxHandle ] = cSessionFermee;
                }

                DATCilS_ASDataCon( STxHandle,EmissionOk );
            }
            break;

        default:
            mLIBassert(0);
            break;

        }
    }
    else
    #endif
    {
        // pour l'ASDT sans session
        DATCilT_ASDataCon(STxHandle,EmissionOk );
    }
}

#ifdef DAT_CTL_SESSION_ON
#ifdef _DEBUG
tDATCTLSessionMode DATCilS_LireEtatSession( tDATCtlS_ASHandle SHandle)
{
    return (EtatSession[SHandle]);
}

#endif
#endif

#endif //#ifdef COMPOSANT_DAT_CTL_ON

