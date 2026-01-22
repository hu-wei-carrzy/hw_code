
//------------------------------------------------------------------------------
// Body Identification
//------------------------------------------------------------------------------
#define dat_cil  "dat_cil"


//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//
// #include <system_file_name.h>
// #include "project_file_name.h"
//------------------------------------------------------------------------------

#include "DAT_CIL.h"

#include "DAT_CIL.hgr"




#ifdef SUPERVISION_OFF
#ifdef SUPERVISION_SURVEILLANCE_COMMANDEES
#error 'if there is no network supervision do not declared different timer for supervision and survey'
#endif
#endif

//------------------------------------------------------------------------------
// Local constants
//
// #define cConstantName   ((tType) ConstantValue)
//------------------------------------------------------------------------------

#define cDATCil_NbTx (cDATCdl_NbUUTx)
#define cDATCil_NbRx (cDATCdl_NbUURx)

#define cTempsEnTickTempsExclusion  mDATCilConvertTimeIntick(cDATTempsEnmsTempsExclusion)

//------------------------------------------------------------------------------
// Local macros
//
// #define mMacroName   (MacroDefinition)
//------------------------------------------------------------------------------

#ifdef M_MULTIBUS_CAN
#define mDATCilLireNumCan(IRxHandle) DATCdlTableCanauxCanRx[IRxHandle]

//Restriction: on multibus mode only the CAN1 is multimedia
#define mDATCilLireNumCanForUCEASDT(NumUCE) cDATCdlIdCanalCan1
//To update this restriction SCC2 must generate a table linkin UCE and nb of the CAN for each UCE ASDT

#define mDATCplSetFlag(Tab, Handle)\
        Tab[ ((U8)Handle>>3)] |= (((U8)1)<<( (U8)(Handle & (U8)0x07)))

#ifdef SUPERVISION_SURVEILLANCE_COMMANDEES
#error 'option SUPERVISION_SURVEILLANCE_COMMANDEES is not compatible in multi channel version'
#error 'La commande des tempos de supervision n est pas compatible avec une configuration multibus'
//missing table of const to link supervised Rx Frame handle and Can channel number
//mDATCilLireNumCanSourceSupervisee(IRxHandle) DATCilTableSourcesRx[IRxHandle]
#endif

#endif

//------------------------------------------------------------------------------
// Local types
//
// typedef Expression    tTypeName;
//------------------------------------------------------------------------------

typedef struct
{
    U8 CompteurTick; // Exclusion time
    BOOL FlagEnvoiDiffereRecalage;
} tTempsExclusionTx;

//------------------------------------------------------------------------------
// Data prefix
//
// unsigned int {u8,u16,u32} / signed int {s8,s16,s32} 
// register size unsigned int {r} / float {f32,f64}  / s for struct 
//
// -----------------------------------------------------------------------------
// Local data
//
// static  tType   u8VariableName;  
// static  tType*  pu8VariableName; 
//------------------------------------------------------------------------------
static tPeriode CompteurTickTx[cDATCil_NbTx];

#ifdef SUPERVISION_SURVEILLANCE_COMMANDEES
static tTOSPeriodicTimer TemposRx[cDATCil_NbRx + cDATCil_NbSources - 1];
//QACJ 3218: amanevm: this is the place where statics are defined
static BOOL TempoElapsed[cDATCil_NbRx + cDATCil_NbSources - 1];
#else
static tTOSPeriodicTimer TemposRx[cDATCil_NbRx];
//QACJ 3218: amanevm: this is the place where statics are defined
static BOOL TempoElapsed[cDATCil_NbRx];
#endif

#ifdef TEMPS_EXCLUSION
static tTempsExclusionTx TempsExclusionTx[cDATCil_NbTx];
#endif

#ifdef ASDT_INTERACTION_LAYER_ON
static tDATCilMsgStatus ASDTMessageStatus[cDATCil_NbMessage];  //ASDT message status
#endif

#ifdef ASDT_PRESENTATION_LAYER_ON
static tDATCilEcuStatus DATCilASDTIPLayer[cDATCil_NbEcu];  //ASDT message session status
#endif

#ifdef M_MULTIBUS_CAN
//started CAN channel table
static tDATCilIdCanalCan DATCilCanXDemarre;
#endif

//------------------------------------------------------------------------------
// Constant local data
//
// static const tType  VariableName;
//------------------------------------------------------------------------------

#ifdef DAT_CNL_LAYER_ON
static const tDATCilTxMessage TxMessages[cDATCil_NbTx] =
    {
        mDATCilUSTxMessages(),
        mDATCilUUTxMessages()
    } ;

#ifdef SUPERVISION_SURVEILLANCE_COMMANDEES
static const tDATCilRxMessage RxMessages[cDATCil_NbRx + cDATCil_NbSources - 1] =
    {
        mDATCilUURxMessagesSupervises(),
        mDATCilUSRxMessages(),
        mDATCilUURxMessages()
    } ;

//Evol vers multibus avec une commande separree de l'activation des tempos de surveillance et de supervision
//(config PSA body multibus par exemple)
//#ifdef M_MULTIBUS_CAN
//static const tDATCilIdCanalCan DATCilTableSourcesRx[cDATCil_NbSources - cDATCil_NbCanauxCan] =;
//    {
//         mDATCilInitTableSource()
//    }
//#endif


#else
static const tDATCilRxMessage RxMessages[cDATCil_NbRx] =
{
    mDATCilUSRxMessages(),
    mDATCilUURxMessages()
} ;
#endif
#else
static const tDATCilTxMessage TxMessages[cDATCil_NbTx] =
    {
        mDATCilUUTxMessages()
    } ;

#ifdef SUPERVISION_SURVEILLANCE_COMMANDEES
static const tDATCilRxMessage RxMessages[cDATCil_NbRx + cDATCil_NbSources - 1] =
    {
        mDATCilUURxMessagesSupervises(),
        mDATCilUURxMessages()
    } ;
#else
static const tDATCilRxMessage RxMessages[cDATCil_NbRx] =
{
    mDATCilUURxMessages()
} ;
#endif
#endif


#ifdef ASDT_PRESENTATION_LAYER_ON

static const tDATCilI_ASSHandle ASTxMessages[((U8)(cDATCil_NbEcu*cDATCilNbMaxTrameTxParSource))] =
    {
        mDATCilASTxMessages(),
    } ;

static const tDATCilI_ASSHandle ASRxMessages[((U8)(cDATCil_NbEcu*cDATCilNbMaxTrameRxParSource))] =
    {
        mDATCilASRxMessages(),
    } ;

#endif

#ifdef TEMPS_EXCLUSION_SETTINGS
//QACJ 3218: amanevm: this is the place where statics are defined
static const  tTempsExclusionTxParam TempsExclusionTxParam[cDATCil_NbTx] = 
    {
        mDATCilInitTempsExclusionTxParam(),
    } ;
#endif

//------------------------------------------------------------------------------
// Exported data
//
// tType   u8LAYCmpVariableName; (LAY: 3 characters to identify the layer)
// tType*  pu8LAYCmpVariableName;(Cmp: 3 characters to identify the component)
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Constant exported data
//
//             (LAY: 3 characters to identify the layer)
//             (Cmp: 3 characters to identify this component)
// 
// const tType   LAYCmpVariableName;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Local function prototypes
// 
// static tTypeRetour FunctionName(tTypeArgument1 ArgumentName1, ... );
//------------------------------------------------------------------------------
#ifndef SUPERVISION_OFF
static void TraiterDiagSource( tDATCilSourceHandle SourceHandle, BOOL StatutOk);
#endif

#ifdef TEMPS_EXCLUSION
static void TraiterConfirmationEmission(tDATCilSourceHandle TxHandle, BOOL EmissionOk);
#endif

#ifdef ASDT_PRESENTATION_LAYER_ON

static void DATCilCloseMessage(tDATCilI_MessageHandle DATCil_ASDTHandle);
static void DATCilInitMessage(tDATCilI_MessageHandle DATCil_ASDTHandle);

static void CheckSessionOpened(tDATCilI_EcuHandle ASDT_Layer);
static void CheckRxSessionClosed(tDATCilI_EcuHandle ASDT_Layer);

  #ifdef DISCONNECTION_AUTHORIZED
static void CheckTxSessionClosed(tDATCilI_EcuHandle ASDT_Layer);
  #endif
#endif


//==============================================================================
//=========================== LOCAL FUNCTIONS ==================================
//==============================================================================

//==============================================================================
// DESCRIPTION :
//
// PARAMETERS (Type,Name,Min,Max) :   none
// tDATCilSourceHandle SourceHandle          0           cDATCil_NbSources-1
// BOOL                StatutOk              cFalse       cTrue
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
#ifdef TEMPS_EXCLUSION
static void TraiterConfirmationEmission(tDATCilSourceHandle TxHandle, BOOL EmissionOk)
{
#ifdef TEMPS_EXCLUSION_SETTINGS
    if(TempsExclusionTxParam[TxHandle] != 0)
    {
        TempsExclusionTx[TxHandle].CompteurTick = TempsExclusionTxParam[TxHandle];
    }
    else
    {
        //Let default value 0
    }
#else
    //Start exclusion time, even if the Tx is Nok
    TempsExclusionTx[TxHandle].CompteurTick = cTempsEnTickTempsExclusion;
#endif
}
#endif

//==============================================================================
// DESCRIPTION :
//
// PARAMETERS (Type,Name,Min,Max) :
// tDATCilSourceHandle SourceHandle          0           cDATCil_NbSources-1
// BOOL                StatutOk              cFalse       cTrue
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
#ifndef SUPERVISION_OFF
static void TraiterDiagSource( tDATCilSourceHandle SourceHandle, BOOL StatutOk)
{
    #ifdef SUPERVISION_SURVEILLANCE_COMMANDEES
    tTOSPeriodicTimer* pTempo;
    tDATCilRxMessage const* pRxMsg;
    #endif

    if( SourceHandle != cDATCilSourceInvalide )
    {

        #ifdef cDATCil_NbSourcesNonType
            #if(cDATCil_NbSourcesNonType!=0)
            mLIBassert( SourceHandle < cDATCil_NbSources );
            #endif
        #endif

        DATCnmNetworkInfos(SourceHandle,StatutOk);
        #ifdef SUPERVISION_SURVEILLANCE_COMMANDEES
        if( (SourceHandle != (tDATCilSourceHandle)0x00U)&&(StatutOk != cFalse) )
        {
            pRxMsg = &RxMessages[SourceHandle - 1];
            pTempo = &TemposRx[SourceHandle - 1];
            TOSStartPeriodicTimer( pTempo, pRxMsg->Timeout, pRxMsg->Timeout);
        }
        else
        {
            //For QAC
        }
        #endif
    }
    else
    {
        //This frame is not a supervised one
    }
}
#endif

#ifdef ASDT_PRESENTATION_LAYER_ON
//==============================================================================
// DESCRIPTION : check if the ASDT session is opened
//
// PARAMETERS (Type,Name,Min,Max) :
// tDATCilSourceASDT   ASDT_Layer
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
static void CheckSessionOpened(tDATCilI_EcuHandle ASDT_Layer)
{

    BOOL SessionOuverte;
    U8 i;
    tDATCilI_ASSHandle NumHandle;

    mLIBassert(ASDT_Layer < cDATCil_NbEcu);

    SessionOuverte = cTrue;

    for(i = 0; i < cDATCilNbMaxTrameTxParSource; i++)
    {

        NumHandle = ASTxMessages[(U8)(((U8)(ASDT_Layer * cDATCilNbMaxTrameTxParSource)) + i)];

        if (NumHandle != cDATCilI_TxHandleInvalide)
        {
            if(ASDTMessageStatus[NumHandle] != cDAT_CilMsgStatus_E_COM_NOMSG)
            {
                SessionOuverte = cFalse;
            }
            else
            {
                //For QAC
            }
        }
        else
        {
            //For QAC
        }
    }

    for(i = 0; i < cDATCilNbMaxTrameRxParSource; i++)
    {

        NumHandle = ASRxMessages[(U8)(((U8)(ASDT_Layer * cDATCilNbMaxTrameRxParSource)) + i)];

        if (NumHandle != cDATCilI_RxHandleInvalide)
        {
            if(ASDTMessageStatus[NumHandle] != cDAT_CilMsgStatus_E_COM_NOMSG)
            {
                SessionOuverte = cFalse;
            }
            else
            {
                //For QAC
            }
        }
        else
        {
            //For QAC
        }
    }

    if(SessionOuverte == cTrue)
    {
        DATCilASDTIPLayer[ASDT_Layer] = cDATCilEcuStatusConnected;
    }
    else
    {
        //For QAC
    }
}

//==============================================================================
// DESCRIPTION : check if the session with the ECU Id "ASDT_Layer" is closed if
// all channel Tx are disconnected
//
// PARAMETERS (Type,Name,Min,Max) :
// tDATCilSourceASDT   ASDT_Layer
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
#ifdef DISCONNECTION_AUTHORIZED
static void CheckTxSessionClosed(tDATCilI_EcuHandle ASDT_Layer)
{
    //One ECU is "disconnected" if all Tx channel OR all Rx channel are closed
    BOOL SessionFermee;
    U8 i;
    tDATCilI_ASSHandle NumHandle;

    mLIBassert(ASDT_Layer < cDATCil_NbEcu);

    SessionFermee = cTrue;

    for(i = 0; i < cDATCilNbMaxTrameTxParSource; i++)
    {
        NumHandle = ASTxMessages[((U8)((U8)(ASDT_Layer * cDATCilNbMaxTrameTxParSource)) + i)];

        if (NumHandle != cDATCilI_TxHandleInvalide)
        {
            if(ASDTMessageStatus[NumHandle] != cDAT_CilMsgStatus_E_COM_SYS_NOTINITIALISED)
            {
                SessionFermee = cFalse;
            }
            else
            {
                //For QAC
            }
        }
        else
        {
            //For QAC
        }
    }

    if(SessionFermee != cFalse)
    {
        DATCilASDTIPLayer[ASDT_Layer] = cDATCilEcuStatusDisconnected;
    }
    else
    {
        //For QAC
    }
}
#endif

//==============================================================================
// DESCRIPTION : check if the session with the ECU Id "ASDT_Layer" is closed if
// all channel Rx are disconnected
//
// PARAMETERS (Type,Name,Min,Max) :
// tDATCilSourceASDT   ASDT_Layer
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
static void CheckRxSessionClosed(tDATCilI_EcuHandle ASDT_Layer)
{
    BOOL SessionFermee;
    U8 i;
    tDATCilI_ASSHandle NumHandle;

    mLIBassert(ASDT_Layer < cDATCil_NbEcu);

    SessionFermee = cTrue;

    for(i = 0; i < cDATCilNbMaxTrameRxParSource; i++)
    {
        NumHandle = ASRxMessages[((U8)((U8)(ASDT_Layer * cDATCilNbMaxTrameRxParSource)) + i)];

        if (NumHandle != cDATCilI_RxHandleInvalide)
        {
            if(ASDTMessageStatus[NumHandle] != cDAT_CilMsgStatus_E_COM_SYS_NOTINITIALISED)
            {
                SessionFermee = cFalse;
            }
            else
            {
                //For QAC
            }
        }
        else
        {
            //For QAC
        }
    }

    if(SessionFermee != cFalse)
    {
        DATCilASDTIPLayer[ASDT_Layer] = cDATCilEcuStatusDisconnected;
    }
    else
    {
        //For QAC
    }

}

#endif

//==============================================================================
//=========================== EXPORTED FUNCTIONS ===============================
//==============================================================================

//==============================================================================
// DESCRIPTION : Initialize local data
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void DATCilInit(void)
{
    #ifdef M_MULTIBUS_CAN
    tDATCilIdCanalCan IdCan;

    DATCilCanXDemarre = (tDATCilIdCanalCan)0;
    // A l'init les emission periodiques ne sont pas activees.
    // On appelle la fonction d'arret de la communication.
    for(IdCan = 0; IdCan< cDATCil_NbCanauxCan; IdCan++)
    {
        DATCil_I_Stop(IdCan);
    }
    #else
    DATCil_I_Stop();
    #endif
}


//==============================================================================
// DESCRIPTION : Send a frame/message if the conditions are correct
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void DATCilSendMessage(tDATCilI_TxHandle ITxHandle)
{
    #ifdef ASDT_PRESENTATION_LAYER_ON
    BOOL MessageTrouve;
    tDATCilI_EcuHandle i;
    tDATCilI_MessageHandle j;

    #endif
    BOOL bPrepareEmision;

    bPrepareEmision = DATCplPreparerEmission(ITxHandle);

    mLIBassert( ITxHandle < cDATCil_NbTx );

    #ifdef TEMPS_EXCLUSION
    if(bPrepareEmision != cFalse)
    {
        if (TempsExclusionTx[ITxHandle].CompteurTick == 0 )
        {
            #ifdef RECALAGE
            tDATCilTxMessage const* pTxMsg = &TxMessages[ITxHandle];
            #endif

            //Check if it's an ASDT, USDT or UUDT message
            #ifdef DAT_CTL_SESSION_ON
            if( ITxHandle < cDATCtl_NbSession)
            {
                #ifdef ASDT_INTERACTION_LAYER_ON
                if( ITxHandle < cDATCilNbASTx)
                {
                    #ifdef ASDT_PRESENTATION_LAYER_ON
                    MessageTrouve = cFalse;
                    i=0;
                    j=0;
                    while( (i<cDATCil_NbEcu)&&(MessageTrouve != cTrue))
                    {
                        #ifdef DISCONNECTION_AUTHORIZED
                        if((DATCilASDTIPLayer[i] & (cDATCilEcuStatusConnected|cDATCilEcuStatusDisconnecting) ) != (tDATCilEcuStatus)0)
                            //L'etat courant cDATCilEcuStatusDisconnecting signifie qu'une deconnection est en cours
                            //ou a rendue Nok pour un des canaux en transmission: la communication doit etre possible
                        #else
                        if(DATCilASDTIPLayer[i] == cDATCilEcuStatusConnected)
                        #endif

                        {
                            while( (j < cDATCilNbMaxTrameTxParSource)&&(ASTxMessages[(U8)(cDATCilNbMaxTrameTxParSource*i) + j]!=cDATCilI_TxHandleInvalide)&&(MessageTrouve != cTrue))
                            {
                                if( (ASTxMessages[(U8)(cDATCilNbMaxTrameTxParSource*i) + j] == ITxHandle)
                                        &&((ASDTMessageStatus[ITxHandle] == cDAT_CilMsgStatus_E_COM_NOMSG) != cFalse ))
                                {
                                    MessageTrouve = cTrue;
                                }
                                j++;
                            }
                            j=0;
                        }
                        i++;
                    }
                    if(MessageTrouve==cTrue)
                    #else
                    if(ASDTMessageStatus[ITxHandle] == cDAT_CilMsgStatus_E_COM_NOMSG)
                    #endif
                    {
                        //Tx request
                        ASDTMessageStatus[ITxHandle] = cDAT_CilMsgStatus_E_COM_LOCKED;
                        DATCtlS_ASDataReq(ITxHandle);
                        #ifdef TEMPS_EXCLUSION
                        TraiterConfirmationEmission(ITxHandle, cTrue);
                        #endif
                    }
                    else
                    {
                        // The channel or UCE is not connected or a Tx is in progress
                        DATCplI_ASSDataCon( ITxHandle, cFalse );
                    }
                }
                else
                {
            #endif
                DATCtlS_ASDataReq(ITxHandle);
                #ifdef TEMPS_EXCLUSION
                TraiterConfirmationEmission(ITxHandle, cTrue);
                #endif

                #ifdef ASDT_INTERACTION_LAYER_ON
                }
                #endif
            }
            else
            {
        #endif

        #ifdef COMPOSANT_DAT_CTL_ON
                if(ITxHandle < cDATCtl_NbAS)
                {
                    DATCtlT_ASDataReq(ITxHandle);
                    #ifdef TEMPS_EXCLUSION
                    TraiterConfirmationEmission(ITxHandle, cTrue);
                    #endif
                }
                else
                {
        #endif
                    #ifdef DAT_CNL_LAYER_ON
                    if( (ITxHandle < cDATCnl_NbUS) )
                    {
                        DATCtlT_USDataReq(ITxHandle);
                        #ifdef TEMPS_EXCLUSION
                        TraiterConfirmationEmission(ITxHandle, cTrue);
                        #endif
                    }
                    else
                    {
                        // handle Tx is for a frame
                        DATCtlT_UUDataReq(ITxHandle);
                        #ifdef TEMPS_EXCLUSION
                        TraiterConfirmationEmission(ITxHandle, cTrue);
                        #endif
                    }
                    #else
                    DATCtlT_UUDataReq(ITxHandle);
                    #ifdef TEMPS_EXCLUSION
                    TraiterConfirmationEmission(ITxHandle, cTrue);
                    #endif
                    #endif

        #ifdef COMPOSANT_DAT_CTL_ON
                }
        #endif
        #ifdef DAT_CTL_SESSION_ON
            }
        #endif

        #ifdef RECALAGE
            CompteurTickTx[ITxHandle] = ((tPeriode)((pTxMsg->Periode)- ((tPeriode) 1)));
        #endif
        }
        else
        {
            //Tx request during an exclusion time or waiting for Tx confirmation
            TempsExclusionTx[ITxHandle].FlagEnvoiDiffereRecalage = cTrue;
        }
    }

    #else

    //Before sending frame ask to DAT_CPL if the condition are correct
    //it permits to block some periodic Tx for optionnal ECU
    if(bPrepareEmision != cFalse)
    {
        #ifdef DAT_CTL_SESSION_ON
        if( ITxHandle <  cDATCtl_NbSession)
        {
            #ifdef ASDT_INTERACTION_LAYER_ON
            if( ITxHandle < cDATCilNbASTx)
            {   //ASDT frame
                #ifdef ASDT_PRESENTATION_LAYER_ON
                MessageTrouve = cFalse;
                i=0;
                j=0;

                while( (i<cDATCil_NbEcu)&&(MessageTrouve != cTrue))
                {
                    #ifdef DISCONNECTION_AUTHORIZED
                    if((DATCilASDTIPLayer[i] & (cDATCilEcuStatusConnected|cDATCilEcuStatusDisconnecting) ) != (tDATCilEcuStatus)0)
                        //L'etat courant cDATCilEcuStatusDisconnecting signifie qu'une deconnection est en cours
                        //ou a rendue Nok pour un des canaux en transmission: la communication doit etre possible
                    #else
                    if(DATCilASDTIPLayer[i] == cDATCilEcuStatusConnected)
                    #endif
                    {
                        while( (j < cDATCilNbMaxTrameTxParSource)&&(ASTxMessages[(U8)(cDATCilNbMaxTrameTxParSource*i) + j]!=cDATCilI_TxHandleInvalide)&&(MessageTrouve != cTrue))
                        {
                            if( (ASTxMessages[(U8)(cDATCilNbMaxTrameTxParSource*i) + j] == ITxHandle)
                                    &&((ASDTMessageStatus[ITxHandle] == cDAT_CilMsgStatus_E_COM_NOMSG) != cFalse ))
                            {
                                MessageTrouve = cTrue;
                            }
                            j++;
                        }
                        j=0;
                    }
                    i++;
                }

                if(MessageTrouve==cTrue)
                #else
                if((ASDTMessageStatus[ITxHandle] == cDAT_CilMsgStatus_E_COM_NOMSG) != cFalse )
                #endif
                {
                    //Tx request
                    ASDTMessageStatus[ITxHandle] = cDAT_CilMsgStatus_E_COM_LOCKED;
                    DATCtlS_ASDataReq(ITxHandle);
                    #ifdef TEMPS_EXCLUSION
                    TraiterConfirmationEmission(ITxHandle, cTrue);
                    #endif
                }
                else
                {
                    // The channal or UCE is not connected or a Tx is in progress
                    DATCplI_ASSDataCon( ITxHandle, cFalse );
                }
            }
            else
            #endif
            {
                DATCtlS_ASDataReq(ITxHandle);
                #ifdef TEMPS_EXCLUSION
                TraiterConfirmationEmission(ITxHandle, cTrue);
                #endif
            }
        }
        else
        #endif
            #ifdef COMPOSANT_DAT_CTL_ON
            if(ITxHandle < cDATCtl_NbAS)
            {
                //ASDT Tx handle
                DATCtlT_ASDataReq(ITxHandle);
                #ifdef TEMPS_EXCLUSION
                TraiterConfirmationEmission(ITxHandle, cTrue);
                #endif
            }
            else
            #endif
            {
                #ifdef DAT_CNL_LAYER_ON
                if( (ITxHandle < cDATCnl_NbUS) )
                {
                    // USDT handle
                    DATCtlT_USDataReq(ITxHandle);
                    #ifdef TEMPS_EXCLUSION
                    TraiterConfirmationEmission(ITxHandle, cTrue);
                    #endif
                }
                else
                {
                    // UUDT handle
                    DATCtlT_UUDataReq(ITxHandle);
                    #ifdef TEMPS_EXCLUSION
                    TraiterConfirmationEmission(ITxHandle, cTrue);
                    #endif
                }
                #else
                DATCtlT_UUDataReq(ITxHandle);
                #ifdef TEMPS_EXCLUSION
                TraiterConfirmationEmission(ITxHandle, cTrue);
                #endif
                #endif
            }
    }
    #endif
}


//==============================================================================
// DESCRIPTION : DAT_CIL periodic treatments
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void DATCilTick(void)
{
    tDATCilI_TxHandle ITxHandle;

    for( ITxHandle=0; ITxHandle < cDATCil_NbTx; ITxHandle++ )
    {
        tDATCilTxMessage const* pTxMsg = &TxMessages[ITxHandle];

        #ifdef TEMPS_EXCLUSION  

        // periodic message and non periodic
        if (TempsExclusionTx[ITxHandle].CompteurTick > 0 )
        {
            TempsExclusionTx[ITxHandle].CompteurTick--;
        }

        //End of exclusion time and a Tx request is pending
        if (  (TempsExclusionTx[ITxHandle].CompteurTick == 0)
            &&(TempsExclusionTx[ITxHandle].FlagEnvoiDiffereRecalage != cFalse))
        {
            DATCilSendMessage(ITxHandle);

            #ifdef RECALAGE
            // Set it again even if it is set in DATCilSendMessage
            CompteurTickTx[ITxHandle] = (pTxMsg->Periode);
            #endif

            TempsExclusionTx[ITxHandle].FlagEnvoiDiffereRecalage = cFalse;
        }

        if( pTxMsg->Periode != 0 )
        {
            if( CompteurTickTx[ITxHandle] == 0 )
            {
                #ifdef RECALAGE
                if (TempsExclusionTx[ITxHandle].CompteurTick == 0)
                #endif
                {
                    DATCilSendMessage(ITxHandle);
                    CompteurTickTx[ITxHandle] = ((tPeriode)((pTxMsg->Periode)- ((tPeriode) 1)));
                }

                #ifdef RECALAGE
                else
                {
                    TempsExclusionTx[ITxHandle].FlagEnvoiDiffereRecalage = cTrue;
                }
                #endif
            }
            else
            {
                CompteurTickTx[ITxHandle]--;
            }
        }

        #else

        if( pTxMsg->Periode != 0 )
        {
            if( CompteurTickTx[ITxHandle] == 0 )
            {
                DATCilSendMessage(ITxHandle);
                CompteurTickTx[ITxHandle] = pTxMsg->Periode;
            }
            CompteurTickTx[ITxHandle] --;
        }
        #endif
    }
}

//==============================================================================
// DESCRIPTION : Reception timeout treatments
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void DATCilSurveillanceReception(void)
{
    tDATCilI_RxHandle IRxHandle;

    // First only collect information for elapsed timers
    #ifdef SUPERVISION_SURVEILLANCE_COMMANDEES
    for( IRxHandle=0; IRxHandle < (cDATCil_NbRx + (cDATCil_NbSources - 1)); IRxHandle++ )
    #else
    for( IRxHandle=0; IRxHandle < cDATCil_NbRx ; IRxHandle++ )
    #endif
    {
        tTOSPeriodicTimer*   pTempo = &TemposRx[IRxHandle];
        tDATCilRxMessage const* pRxMsg = &RxMessages[ IRxHandle];

        TempoElapsed[IRxHandle] = cFalse;
        // Ci cette trame est surveillee ou supervisee
        if( pRxMsg->Timeout != ((tTOSTimer) 0) )
        {
            BOOL bTimerStarted = TOSIsPeriodicTimerStarted(pTempo);
            if (bTimerStarted != cFalse)
            {
                BOOL bTimerElapsed = TOSIsPeriodicTimerElapsed(pTempo);
                if (bTimerElapsed != cFalse)
                {
                    TempoElapsed[IRxHandle] = cTrue;
                }
            }
        }
    }

    //Each Rx handle is linked to a periodical timer
    #ifdef SUPERVISION_SURVEILLANCE_COMMANDEES
    for( IRxHandle=0; IRxHandle < (cDATCil_NbRx + (cDATCil_NbSources - 1)); IRxHandle++ )
    #else
    for( IRxHandle=0; IRxHandle < cDATCil_NbRx ; IRxHandle++ )
    #endif
    {
        #ifndef SUPERVISION_SURVEILLANCE_COMMANDEES
        #ifndef SUPERVISION_OFF
        tDATCilRxMessage const* pRxMsg = &RxMessages[ IRxHandle];
        tDATCilSourceHandle     SourceHandle = pRxMsg->Source;
        #endif
        #endif

        //This deviation from the standard rules is to permit to the task
        //and other graph to run, because here treatments are to long for little CPU

        TOSSchedule();
        if (TempoElapsed[IRxHandle] != cFalse)
        {
            //Call back to DAT_CNM if the frame is supervised
            #ifdef SUPERVISION_SURVEILLANCE_COMMANDEES
            if(IRxHandle <  (cDATCil_NbSources - 1))
            {
                TraiterDiagSource( ((tDATCilSourceHandle) (IRxHandle +1)), cFalse);
            }
            else
            {
                //Call back to DAT_CPL for Rx timeout treatments
                DATCplTraiterReception(((tDATCilI_RxHandle) (IRxHandle - (cDATCil_NbSources - 1))),cTrue);
            }

            #else
            #ifndef SUPERVISION_OFF
            TraiterDiagSource( SourceHandle, cFalse);
            #endif
            DATCplTraiterReception(IRxHandle,cTrue);
            #endif
        }
    }
}


//==============================================================================
// DESCRIPTION : Start of DAT_CIL component
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
#ifdef M_MULTIBUS_CAN
void DATCil_I_Init(tDATCilIdCanalCan IdCanalCan)
#else
void DATCil_I_Init(void)
#endif
{
    tDATCilI_TxHandle ITxHandle;
    tDATCilI_RxHandle IRxHandle;

    #ifdef M_MULTIBUS_CAN
    if( DATCilCanXDemarre == (tDATCilIdCanalCan)0 )
    #endif
    {
    TOSSeqActiverGraphe( cTOSSeqGrapheSurveillanceReceptionCan );
    }

    #ifdef M_MULTIBUS_CAN
    DATCilCanXDemarre |= (tDATCilIdCanalCan)(((tDATCilIdCanalCan)1)<< IdCanalCan);
    #endif

    // Initialization of periodic Tx counter
    for( ITxHandle=0; ITxHandle < cDATCil_NbTx; ITxHandle++ )
    {
        tDATCilTxMessage const* pTxMsg = &TxMessages[ITxHandle];
        CompteurTickTx[ITxHandle] = pTxMsg->Phase;
    #ifdef TEMPS_EXCLUSION
        TempsExclusionTx[ITxHandle].FlagEnvoiDiffereRecalage = cFalse;
        TempsExclusionTx[ITxHandle].CompteurTick = 0;
    #endif
    }

    #ifndef SUPERVISION_SURVEILLANCE_COMMANDEES
    // Start frame Rx survey
    for( IRxHandle=0; IRxHandle < cDATCil_NbRx; IRxHandle++ )
    {
        tTOSPeriodicTimer*    pTempo = &TemposRx[IRxHandle];
        tDATCilRxMessage const* pRxMsg = &RxMessages[IRxHandle];

        #ifdef M_MULTIBUS_CAN
        if(  (mDATCilLireNumCan(IRxHandle) == IdCanalCan)
           &&( pRxMsg->Timeout != 0 ) )
        #else
        if( pRxMsg->Timeout != 0 )
        #endif
        {
            TOSStartPeriodicTimer( pTempo, pRxMsg->Timeout, pRxMsg->Timeout);
        }
    }
    #else

//Evol vers multibus avec une commande separree de l'activation des tempos de surveillance et de supervision
//(config PSA body multibus par exemple)

//    #ifdef M_MULTIBUS_CAN
//    for( IRxHandle = 0; IRxHandle < ( cDATCil_NbSources - cDATCil_NbCanauxCan); IRxHandle++ )
//    {//Tempos de supervision
//        tTOSPeriodicTimer*    pTempo = &TemposRx[IRxHandle];
//
//        if(mDATCilLireNumCanSourceSupervisee(IRxHandle) == IdCanalCan)
//        {
//            pTempo->DateArmement = 0;
//        }
//    }
//
//    for( IRxHandle = cDATCil_NbSources - cDATCil_NbCanauxCan; IRxHandle < (cDATCil_NbRx + cDATCil_NbSources - cDATCdl_NbCanauxCan); IRxHandle++ )
//    {//Tempos de surveillance
//        tTOSPeriodicTimer*    pTempo = &TemposRx[IRxHandle];
//
//        if(mDATCilLireNumCan(IRxHandle) == IdCanalCan)
//        {
//            pTempo->DateArmement = 0;
//        }
//    }
//
//    #else
    for( IRxHandle = 0; IRxHandle < (cDATCil_NbRx + (cDATCil_NbSources - 1)); IRxHandle++ )
    {
        tTOSPeriodicTimer*    pTempo = &TemposRx[IRxHandle];

        pTempo->StartDate = 0;
    }

//    #endif
    #endif

    #ifdef ASDT_INTERACTION_LAYER_ON

    for(ITxHandle=0; ITxHandle<cDATCil_NbMessage; ITxHandle++)
    {
        #ifdef M_MULTIBUS_CAN
        if(mDATCilLireNumCan(ITxHandle) == IdCanalCan)
        #endif
        {
        ASDTMessageStatus[ITxHandle] = cDAT_CilMsgStatus_E_COM_SYS_NOTINITIALISED;
        }
    }
    #endif

    #ifdef ASDT_PRESENTATION_LAYER_ON

    for(ITxHandle=0; ITxHandle<cDATCil_NbEcu; ITxHandle++)
    {
        #ifdef M_MULTIBUS_CAN
        if(mDATCilLireNumCanForUCEASDT(ITxHandle) == IdCanalCan)
        #endif
        {
        DATCilASDTIPLayer[ITxHandle] = cDATCilEcuStatusNotInitialised;
        }
    }
    #endif
}


//==============================================================================
// DESCRIPTION : Start Tx channel connection
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
#ifdef ASDT_INTERACTION_LAYER_ON

#ifndef ASDT_PRESENTATION_LAYER_ON
void DATCilInitMessage(tDATCilI_MessageHandle DATCil_ASDTHandle)
#else
static void DATCilInitMessage(tDATCilI_MessageHandle DATCil_ASDTHandle)
#endif
{
    mLIBassert(DATCil_ASDTHandle<cDATCilNbASTx);

    if(ASDTMessageStatus[DATCil_ASDTHandle] == cDAT_CilMsgStatus_E_COM_SYS_NOTINITIALISED)
    {
        //Deviation from RNO spec because there is no "connection in progress" state
        ASDTMessageStatus[DATCil_ASDTHandle] = cDAT_CilMsgStatus_E_COM_SYS_CONNECTING;
        DATCtlS_ConnectReq(DATCil_ASDTHandle);
    }//Allready connected channel or connection in progress
}
#endif

//==============================================================================
// DESCRIPTION : Start channel connection with the ECU hanlde "DATCil_NumeroEcu"
//
// PARAMETERS (Type,Name,Min,Max) :   none
// tDATCilI_EcuHandle DATCil_NumeroEcu          0             255
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
#ifdef ASDT_PRESENTATION_LAYER_ON
void DATCilInitEcu(tDATCilI_EcuHandle DATCil_NumeroEcu)
{
    U8 i;
    tDATCilI_MessageHandle NumHandle;

    mLIBassert(DATCil_NumeroEcu < cDATCil_NbEcu);

    #ifdef DISCONNECTION_AUTHORIZED
    mLIBassert((DATCilASDTIPLayer[DATCil_NumeroEcu] & (cDATCilEcuStatusNotInitialised|cDATCilEcuStatusDisconnected|cDATCilEcuStatusDisconnecting)) != (tDATCilEcuStatus)0);
    #else
    mLIBassert(DATCilASDTIPLayer[DATCil_NumeroEcu] == cDATCilEcuStatusNotInitialised);
    #endif
    DATCilASDTIPLayer[DATCil_NumeroEcu] = cDATCilEcuStatusConnecting;

    for(i = 0; i < cDATCilNbMaxTrameTxParSource; i++)
    {
        NumHandle = ASTxMessages[(U8)(((U8)(DATCil_NumeroEcu*cDATCilNbMaxTrameTxParSource)) + i)];

        if (NumHandle != cDATCilI_TxHandleInvalide)
        {
            DATCilInitMessage(NumHandle);
        }
    }
}
#endif

//==============================================================================
// DESCRIPTION : Disconnect the Tx channel
//
// PARAMETERS (Type,Name,Min,Max) :   none
// tDATCilI_TxHandle DATCil_ASDTHandle          0             255
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
#ifdef ASDT_INTERACTION_LAYER_ON

#ifndef ASDT_PRESENTATION_LAYER_ON
void DATCilCloseMessage(tDATCilI_MessageHandle DATCil_ASDTHandle)
#else
static void DATCilCloseMessage(tDATCilI_MessageHandle DATCil_ASDTHandle)
#endif
{
    mLIBassert(DATCil_ASDTHandle<cDATCil_NbMessage);
    if(DATCil_ASDTHandle<cDATCilNbASTx)
    {
        #ifdef DISCONNECTION_AUTHORIZED
        if(  (ASDTMessageStatus[DATCil_ASDTHandle] != cDAT_CilMsgStatus_E_COM_SYS_NOTINITIALISED)
                &&(ASDTMessageStatus[DATCil_ASDTHandle] != cDAT_CilMsgStatus_E_COM_SYS_CONNECTERROR) )
        {
            ASDTMessageStatus[DATCil_ASDTHandle] = cDAT_CilMsgStatus_E_COM_SYS_DISCONNECTING;
        }
        else  //Disconnect channel in connection in progress
        #endif
        {
            ASDTMessageStatus[DATCil_ASDTHandle] = cDAT_CilMsgStatus_E_COM_SYS_NOTINITIALISED;
        }

        DATCtlS_DisconnectReq(DATCil_ASDTHandle);
    }
    else
    {   //Internal disiconnection of Rx message
        ASDTMessageStatus[DATCil_ASDTHandle] = cDAT_CilMsgStatus_E_COM_SYS_NOTINITIALISED;
    }
}
#endif

//==============================================================================
// DESCRIPTION : Disconnect all channel from the ECU handle "DATCil_NumeroEcu"
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
#ifdef ASDT_PRESENTATION_LAYER_ON
void DATCilCloseEcu(tDATCilI_EcuHandle DATCil_NumeroEcu)
{
    U8 i;
    tDATCilI_MessageHandle  NumHandle;

    mLIBassert(DATCil_NumeroEcu<cDATCil_NbEcu);

    #ifdef DISCONNECTION_AUTHORIZED
    DATCilASDTIPLayer[DATCil_NumeroEcu] = cDATCilEcuStatusDisconnecting;
    #else
    DATCilASDTIPLayer[DATCil_NumeroEcu] = cDATCilEcuStatusNotInitialised;
    #endif

    for(i = 0; i < cDATCilNbMaxTrameTxParSource; i++)
    {
        NumHandle = ASTxMessages[(U8)(((U8)(DATCil_NumeroEcu*cDATCilNbMaxTrameTxParSource)) + i)];

        if (NumHandle != cDATCilI_TxHandleInvalide)
        {
            DATCilCloseMessage(NumHandle);
        }
    }

    #ifndef DISCONNECTION_AUTHORIZED
    for(i = 0; i < cDATCilNbMaxTrameRxParSource; i++)
    {
        NumHandle = ASRxMessages[(U8)(((U8)(DATCil_NumeroEcu*cDATCilNbMaxTrameRxParSource)) + i)];

        if (NumHandle != cDATCilI_RxHandleInvalide)
        {
            DATCilCloseMessage(NumHandle);
        }
    }
    #else
    CheckTxSessionClosed(DATCil_NumeroEcu);
    #endif
}
#endif

//==============================================================================
// DESCRIPTION : Start the supervision management for the ECU Id "SourceHandle"
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
#ifdef SUPERVISION_SURVEILLANCE_COMMANDEES
void DATCilInitSupervision(U8 SourceHandle)
{
    // Start the Rx survey
    tTOSPeriodicTimer*    pTempo = &TemposRx[SourceHandle - 1];
    tDATCilRxMessage const* pRxMsg = &RxMessages[SourceHandle - 1];

    mLIBassert( SourceHandle < cDATCil_NbSources );
    mLIBassert( pRxMsg->Timeout != ((tTOSTimer) 0) );
    mLIBassert( SourceHandle != 0 );

    TOSStartPeriodicTimer( pTempo, pRxMsg->Timeout, pRxMsg->Timeout);
}
#endif

//==============================================================================
// DESCRIPTION : initialize the Rx frame survey
//
// PARAMETERS (Type,Name,Min,Max) :
// tDATCilI_RxHandle IRxHandle
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
#ifdef SUPERVISION_SURVEILLANCE_COMMANDEES
void DATCilInitSurveillance(tDATCilI_RxHandle IRxHandle, BOOL bReLaunch)
{
    // Demarrage de la surveillance des receptions
    tTOSPeriodicTimer*    pTempo = &TemposRx[(cDATCil_NbSources - 1) + IRxHandle];
    tDATCilRxMessage const* pRxMsg = &RxMessages[(cDATCil_NbSources - 1) + IRxHandle];

    mLIBassert( IRxHandle < cDATCdl_NbUURx );
    if( pRxMsg->Timeout != ((tTOSTimer) 0) )
    {
        BOOL bTimerStarted = TOSIsPeriodicTimerStarted(pTempo);
        if ((bReLaunch != cFalse) || (bTimerStarted == cFalse))
        {
            TOSStartPeriodicTimer( pTempo, pRxMsg->Timeout, pRxMsg->Timeout);
        }
    }
}
#endif

//==============================================================================
// DESCRIPTION : Stop DAT_CIL component
//
// PARAMETERS (Type,Name,Min,Max) 
// tDATCilIdCanalCan IdCanalCan
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
#ifdef M_MULTIBUS_CAN
void DATCil_I_Stop(tDATCilIdCanalCan IdCanalCan)
#else
void DATCil_I_Stop(void)
#endif
{

    tDATCilI_RxHandle IRxHandle;

    #ifdef TEMPS_EXCLUSION
    tDATCilI_TxHandle ITxHandle;
    #endif

    #ifdef ASDT_INTERACTION_LAYER_ON
    tDATCilI_ASSHandle i;
    #ifdef ASDT_PRESENTATION_LAYER_ON
    tDATCilI_EcuHandle j;
    #endif
    #endif

    #ifdef M_MULTIBUS_CAN
    DATCilCanXDemarre &= (tDATCilIdCanalCan)~((tDATCilIdCanalCan)(((tDATCilIdCanalCan)1)<< IdCanalCan));
    #endif

    #ifdef M_MULTIBUS_CAN
    if( DATCilCanXDemarre == (tDATCilIdCanalCan)0 )
    #endif
    {
    TOSSeqDesactiverGraphe( cTOSSeqGrapheSurveillanceReceptionCan );
    }

    #ifdef M_MULTIBUS_CAN
    #ifndef SUPERVISION_SURVEILLANCE_COMMANDEES
    // Arret de la surveillance et de la supervision des receptions
    for( IRxHandle=0; IRxHandle < cDATCil_NbRx; IRxHandle++ )
    {
        tTOSPeriodicTimer*   pTempo = &TemposRx[IRxHandle];
        if( mDATCilLireNumCan(IRxHandle) == IdCanalCan )
        {
            TOSStopPeriodicTimer(pTempo);
        }
    }
//    #else

      // Arret de la surveillance des receptions
//    for( IRxHandle = 0; IRxHandle < ( cDATCil_NbSources - cDATCil_NbCanauxCan); IRxHandle++ )
//    {//Tempos de supervision
//        tTOSPeriodicTimer*    pTempo = &TemposRx[IRxHandle];
//
//        if(mDATCilLireNumCanSourceSupervisee(IRxHandle) == IdCanalCan)
//        {
//        TOSStopPeriodicTimer(pTempo);
//        }
//    }
//
//    for( IRxHandle = cDATCil_NbSources - cDATCil_NbCanauxCan; IRxHandle < (cDATCil_NbRx + cDATCil_NbSources - cDATCdl_NbCanauxCan); IRxHandle++ )
//    {//Tempos de surveillance
//        tTOSPeriodicTimer*    pTempo = &TemposRx[IRxHandle];
//
//        if(mDATCilLireNumCan(IRxHandle) == IdCanalCan)
//        {
//        TOSStopPeriodicTimer(pTempo);
//        }
//    }

    #endif

    #else

    //Config monobus
    #ifndef SUPERVISION_SURVEILLANCE_COMMANDEES
    // Stop frame survey
    for( IRxHandle=0; IRxHandle < cDATCil_NbRx; IRxHandle++ )
    {
        tTOSPeriodicTimer*   pTempo = &TemposRx[IRxHandle];

        TOSStopPeriodicTimer(pTempo);
    }
    #else
    // Stop frame survey
    for( IRxHandle=0; IRxHandle < (cDATCil_NbRx + (cDATCil_NbSources - 1)); IRxHandle++ )
    {
        tTOSPeriodicTimer*   pTempo = &TemposRx[IRxHandle];

        TOSStopPeriodicTimer(pTempo);
    }
    #endif
    #endif

    #ifdef TEMPS_EXCLUSION
    for( ITxHandle=0; ITxHandle < cDATCil_NbTx; ITxHandle++ )
    {
        TempsExclusionTx[ITxHandle].CompteurTick = 0;
        TempsExclusionTx[ITxHandle].FlagEnvoiDiffereRecalage = cFalse;
    }
    #endif

    #ifdef ASDT_INTERACTION_LAYER_ON

    for (i=0; i<cDATCil_NbMessage; i++)
    {
        #ifdef M_MULTIBUS_CAN
        if(mDATCilLireNumCan(i) == IdCanalCan)
        #endif
        {
        ASDTMessageStatus[i] = cDAT_CilMsgStatus_E_COM_SYS_NOTINITIALISED;
        }
    }

    #ifdef ASDT_PRESENTATION_LAYER_ON

    for (j=0; j<cDATCil_NbEcu; j++)
    {
        #ifdef M_MULTIBUS_CAN
        if(mDATCilLireNumCanForUCEASDT(j) == IdCanalCan)
        #endif
        {
        DATCilASDTIPLayer[j] = cDATCilEcuStatusNotInitialised;
        }
    }
    #endif

    #endif
}

//==============================================================================
// DESCRIPTION : Frame reception call back
//
// PARAMETERS (Type,Name,Min,Max) :
// tDATCdlD_UURxHandle DRxHandle
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void DATCilT_UUDataInd( tDATCdlD_UURxHandle DRxHandle )
{
    //CCOV: amanevm: assert is generated in case of next check is cFalse
    if (DRxHandle < cDATCdl_NbUURx)
    {
        //add by zc 报文收到过标志
        mDATCplSetFlag(DATCplTableMsgReceivedFlg, DRxHandle);

        #ifdef SUPERVISION_SURVEILLANCE_COMMANDEES
        tDATCilRxMessage const* pRxMsg = &RxMessages[DRxHandle + (cDATCil_NbSources - 1)];
        #else
        tDATCilRxMessage const* pRxMsg = &RxMessages[DRxHandle];
        #endif    

        #ifndef SUPERVISION_OFF
        tDATCilSourceHandle     SourceHandle = pRxMsg->Source;
        #endif    

        #ifdef DAT_CNL_LAYER_ON
        mLIBassert(DRxHandle>=cDATCnl_NbUS);
        #endif

        // Frame recption, re launch the timeout
        if( pRxMsg->Timeout != ((tTOSTimer) 0) )
        {
            #ifdef SUPERVISION_SURVEILLANCE_COMMANDEES
            tTOSPeriodicTimer* pTempo = &TemposRx[DRxHandle + (cDATCil_NbSources - 1)];
            #else
            tTOSPeriodicTimer* pTempo = &TemposRx[DRxHandle];
            #endif    

            TOSStartPeriodicTimer( pTempo, pRxMsg->Timeout, pRxMsg->Timeout);
        }

        #ifndef SUPERVISION_OFF
        TraiterDiagSource(SourceHandle,cTrue);
        #endif
        DATCplTraiterReception(DRxHandle,cFalse);
    }
    else
    {
        mLIBassert(cFalse);
    }
}

//==============================================================================
// DESCRIPTION : USDT message reception call back
//
// PARAMETERS (Type,Name,Min,Max) :
// tDATCnlN_USHandle NRxHandle
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
#ifdef DAT_CNL_LAYER_ON
void DATCilT_USDataInd( tDATCnlN_USHandle NRxHandle )
{
    //CCOV: amanevm: assert is generated in case of next check is cFalse
    if ( NRxHandle < cDATCnl_NbUS)
    {
        #ifdef SUPERVISION_SURVEILLANCE_COMMANDEES
        tDATCilRxMessage const* pRxMsg = &RxMessages[NRxHandle + (cDATCil_NbSources - 1)];
        #else
        tDATCilRxMessage const* pRxMsg = &RxMessages[NRxHandle];
        #endif    

        #ifndef SUPERVISION_OFF
        tDATCilSourceHandle     SourceHandle = pRxMsg->Source;
        #endif    

        // Message reception, re launch timeout
        if( pRxMsg->Timeout != ((tTOSTimer) 0) )
        {
            #ifdef SUPERVISION_SURVEILLANCE_COMMANDEES
            tTOSPeriodicTimer* pTempo = &TemposRx[NRxHandle + (cDATCil_NbSources - 1)];
            #else
            tTOSPeriodicTimer* pTempo = &TemposRx[NRxHandle];
            #endif    

            TOSStartPeriodicTimer( pTempo, pRxMsg->Timeout, pRxMsg->Timeout);
        }

        #ifndef SUPERVISION_OFF
        TraiterDiagSource(SourceHandle,cTrue);
        #endif
        DATCplTraiterReception(NRxHandle,cFalse);
    }
    else
    {
        mLIBassert(cFalse);
    }
}
#endif

//==============================================================================
// DESCRIPTION : ASDT message reception
//
// PARAMETERS (Type,Name,Min,Max) :
// tDATCilI_ASHandle TRxHandle
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
#ifdef COMPOSANT_DAT_CTL_ON
void DATCilT_ASDataInd( tDATCilI_ASHandle TRxHandle )
{
    //CCOV: amanevm: assert is generated in case of next check is cFalse
    if (TRxHandle < cDATCtl_NbAS)
    {
        #ifdef SUPERVISION_SURVEILLANCE_COMMANDEES
        tDATCilRxMessage const* pRxMsg = &RxMessages[TRxHandle + (cDATCil_NbSources - 1)];
        #else
        tDATCilRxMessage const* pRxMsg = &RxMessages[TRxHandle];
        #endif    

        #ifndef SUPERVISION_OFF
        tDATCilSourceHandle     SourceHandle = pRxMsg->Source;
        #endif    

        // Message reception, re launch timeout
        if( pRxMsg->Timeout != ((tTOSTimer) 0) )
        {
            #ifdef SUPERVISION_SURVEILLANCE_COMMANDEES
            tTOSPeriodicTimer* pTempo = &TemposRx[TRxHandle + (cDATCil_NbSources - 1)];
            #else
            tTOSPeriodicTimer* pTempo = &TemposRx[TRxHandle];
            #endif    

            TOSStartPeriodicTimer( pTempo, pRxMsg->Timeout, pRxMsg->Timeout);
        }

        #ifndef SUPERVISION_OFF
        TraiterDiagSource(SourceHandle,cTrue);
        #endif
        DATCplTraiterReception(TRxHandle,cFalse);
    }
    else
    {
        mLIBassert(cFalse);
    }
}
#endif

//==============================================================================
// DESCRIPTION : ASDT + session message reception
//
// PARAMETERS (Type,Name,Min,Max) :
// tDATCilI_ASSHandle SRxHandle
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
#ifdef DAT_CTL_SESSION_ON
void DATCilS_ASDataInd( tDATCilI_ASSHandle SRxHandle )
{

    #ifdef ASDT_PRESENTATION_LAYER_ON
    tDATCilI_EcuHandle i;
    tDATCilI_MessageHandle j;
    BOOL MessageTrouve;
    #endif

    #ifdef SUPERVISION_SURVEILLANCE_COMMANDEES
    tDATCilRxMessage const* pRxMsg = &RxMessages[SRxHandle + (cDATCil_NbSources - 1)];
    #else
    tDATCilRxMessage const* pRxMsg = &RxMessages[SRxHandle];
    #endif    

    #ifndef SUPERVISION_OFF
    tDATCilSourceHandle     SourceHandle = pRxMsg->Source;
    #endif    

    mLIBassert( SRxHandle < cDATCtl_NbSession );

    // Message reception, re launch timeout
    if( pRxMsg->Timeout != 0 )
    {
        #ifdef SUPERVISION_SURVEILLANCE_COMMANDEES
        tTOSPeriodicTimer* pTempo = &TemposRx[SRxHandle + (cDATCil_NbSources - 1)];
        #else
        tTOSPeriodicTimer* pTempo = &TemposRx[SRxHandle];
        #endif

        TOSStartPeriodicTimer( pTempo, pRxMsg->Timeout, pRxMsg->Timeout);
    }

    #ifndef SUPERVISION_OFF
    TraiterDiagSource(SourceHandle,cTrue);
    #endif

    #ifdef ASDT_INTERACTION_LAYER_ON
    if(SRxHandle< (U8)(cDATCilNbASTx+cDATCilNbASRx))
    {
        mLIBassert(SRxHandle>=cDATCilNbASTx);

        if(ASDTMessageStatus[SRxHandle] == cDAT_CilMsgStatus_E_COM_NOMSG)
        {
            #ifdef ASDT_PRESENTATION_LAYER_ON

            i=0;
            j=0;
            MessageTrouve = cFalse;

            while( (i< cDATCil_NbEcu)&&(MessageTrouve != cTrue))
            {
                if( DATCilASDTIPLayer[i] == cDATCilEcuStatusConnected)
                {
                    while( (j < cDATCilNbMaxTrameRxParSource)&&(ASRxMessages[(U8)(cDATCilNbMaxTrameRxParSource*i) + j]!=cDATCilI_RxHandleInvalide)&&(MessageTrouve != cTrue))
                    {
                        if (ASRxMessages[(U8)(cDATCilNbMaxTrameRxParSource*i) + j] == SRxHandle)
                        {
                            DATCplTraiterReception(SRxHandle,cFalse);
                            MessageTrouve = cTrue;
                        }
                        j++;
                    }
                    j=0;
                }
                i++;
            }
            #else
            DATCplTraiterReception(SRxHandle,cFalse);
            #endif
        }
    }
    else
    #endif
    {
        DATCplTraiterReception(SRxHandle,cFalse);
    }
}
#endif


#ifdef DAT_CTL_SESSION_ON
//==============================================================================
// DESCRIPTION : reception of connection request for ASDT message
//
// PARAMETERS (Type,Name,Min,Max) :
//tDATCtlT_ASRxHandle SRxHandle
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void DATCilS_ConnectInd( tDATCtlT_ASRxHandle SRxHandle )
{
    #ifdef ASDT_PRESENTATION_LAYER_ON
    tDATCilI_EcuHandle i;
    tDATCilI_MessageHandle j;
    BOOL MessageTrouve;
    #endif

    #ifdef ASDT_INTERACTION_LAYER_ON

    if(SRxHandle< (U8)(cDATCilNbASTx+cDATCilNbASRx))
    {

        mLIBassert(SRxHandle>=cDATCilNbASTx);

        ASDTMessageStatus[SRxHandle] = cDAT_CilMsgStatus_E_COM_NOMSG;

        #ifdef ASDT_PRESENTATION_LAYER_ON

        i=0;
        j=0;
        MessageTrouve = cFalse;

        while( (i< cDATCil_NbEcu)&&(MessageTrouve != cTrue))
        {
            if ( (DATCilASDTIPLayer[i] == cDATCilEcuStatusConnecting) )
            {
                while( (j < cDATCilNbMaxTrameRxParSource)&&(ASRxMessages[(U8)(cDATCilNbMaxTrameRxParSource*i) + j]!=cDATCilI_RxHandleInvalide)&&(MessageTrouve != cTrue))
                {
                    if (ASRxMessages[(U8)(cDATCilNbMaxTrameRxParSource*i) + j] == SRxHandle)
                    {
                        CheckSessionOpened(i);
                        MessageTrouve = cTrue;
                    }
                    j++;
                }
                j=0;
            }
            i++;
        }
    #endif
    }
    #else
    SRxHandle = SRxHandle;

    #endif
}
#endif

#ifdef DAT_CTL_SESSION_ON
//==============================================================================
// DESCRIPTION : reception of disconnection request for ASDT message
//
// PARAMETERS (Type,Name,Min,Max) :
// tDATCtlT_ASRxHandle SRxHandle
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void DATCilS_DisconnectInd( tDATCtlT_ASRxHandle SRxHandle )
{

  #ifdef ASDT_PRESENTATION_LAYER_ON
    tDATCilI_EcuHandle i;
    tDATCilI_MessageHandle j;
    BOOL MessageTrouve;
  #endif

  #ifdef ASDT_INTERACTION_LAYER_ON

    if(SRxHandle< (U8)(cDATCilNbASTx+cDATCilNbASRx))
    {
        if(SRxHandle>=cDATCilNbASTx)
        {
            ASDTMessageStatus[SRxHandle] = cDAT_CilMsgStatus_E_COM_SYS_NOTINITIALISED;

            #ifdef ASDT_PRESENTATION_LAYER_ON

            i=0;
            j=0;
            MessageTrouve = cFalse;

            while( (i< cDATCil_NbEcu)&&(MessageTrouve != cTrue))
            {
                #ifdef DISCONNECTION_AUTHORIZED
                if ( (DATCilASDTIPLayer[i] & (cDATCilEcuStatusConnected|cDATCilEcuStatusConnecting|cDATCilEcuStatusDisconnected|cDATCilEcuStatusDisconnecting)) != (tDATCilEcuStatus)0)
                #else
                if ( (DATCilASDTIPLayer[i] & (cDATCilEcuStatusConnected|cDATCilEcuStatusConnecting)) != (tDATCilEcuStatus)0)
                #endif
                {
                    while( (j < cDATCilNbMaxTrameRxParSource)&&(ASRxMessages[(U8)(cDATCilNbMaxTrameRxParSource*i) + j]!=cDATCilI_RxHandleInvalide)&&(MessageTrouve != cTrue))
                    {
                        if (ASRxMessages[(U8)(cDATCilNbMaxTrameRxParSource*i) + j] == SRxHandle)
                        {
                            CheckRxSessionClosed(i);
                            MessageTrouve = cTrue;
                        }
                        j++;
                    }
                    j=0;
                }
                i++;
            }
        #endif
        }//Disconnection on a Tx channel
    }
    #else
    SRxHandle = SRxHandle;
    #endif
}
#endif


//==============================================================================
// DESCRIPTION : UUDT Tx frame confirmation
//
// PARAMETERS (Type,Name,Min,Max) :
// tDATCnlN_USHandle NRxHandle
// BOOL            EmissionOk 
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void DATCilT_UUDataCon( tDATCdlD_UUTxHandle DTxHandle, BOOL EmissionOk )
{
    //CCOV: amanevm: assert is generated in case of next check is cFalse
    if (DTxHandle < cDATCdl_NbUUTx)
    {
        #ifndef SUPERVISION_OFF
        tDATCilTxMessage const* pTxMsg       = &TxMessages[DTxHandle];

        tDATCilSourceHandle     SourceHandle = pTxMsg->Source;
        #endif

        #ifdef DAT_CNL_LAYER_ON
        mLIBassert(DTxHandle>=cDATCnl_NbUS);
        #endif

        #ifdef TEMPS_EXCLUSION
        TraiterConfirmationEmission(DTxHandle, EmissionOk);
        #endif

        #ifndef SUPERVISION_OFF
        TraiterDiagSource(SourceHandle,EmissionOk);
        #endif
        DATCplI_UUDataCon( DTxHandle,EmissionOk );
    }
    else
    {
        mLIBassert(cFalse);
    }
}

//==============================================================================
// DESCRIPTION : USDT Tx frame confirmation
//
// PARAMETERS (Type,Name,Min,Max) :
// tDATCnlN_USHandle NRxHandle
// BOOL            EmissionOk 
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
#ifdef DAT_CNL_LAYER_ON
void DATCilT_USDataCon( tDATCnlN_USHandle NTxHandle, BOOL EmissionOk )
{
    //CCOV: amanevm: assert is generated in case of next check is cFalse
    if (NTxHandle < cDATCnl_NbUS)
    {
        #ifndef SUPERVISION_OFF
        tDATCilTxMessage const* pTxMsg       = &TxMessages[NTxHandle];

        tDATCilSourceHandle     SourceHandle = pTxMsg->Source;
        #endif

        #ifdef TEMPS_EXCLUSION
        TraiterConfirmationEmission(NTxHandle, EmissionOk);
        #endif

        #ifndef SUPERVISION_OFF
        TraiterDiagSource(SourceHandle,EmissionOk);
        #endif
        DATCplI_USDataCon( NTxHandle,EmissionOk );
    }
    else
    {
        mLIBassert(cFalse);
    }
}
#endif

//==============================================================================
// DESCRIPTION : ASDT Tx frame confirmation
//
// PARAMETERS (Type,Name,Min,Max) :
// tDATCnlN_USHandle NRxHandle
// BOOL            EmissionOk 
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
#ifdef COMPOSANT_DAT_CTL_ON
void DATCilT_ASDataCon( tDATCtlT_ASHandle TTxHandle, BOOL EmissionOk )
{
    #ifndef SUPERVISION_OFF
    tDATCilTxMessage const* pTxMsg       = &TxMessages[TTxHandle];

    tDATCilSourceHandle     SourceHandle = pTxMsg->Source;
    #endif

    mLIBassert( TTxHandle < cDATCtl_NbAS );

    #ifdef TEMPS_EXCLUSION
    TraiterConfirmationEmission(TTxHandle, EmissionOk);
    #endif

    #ifndef SUPERVISION_OFF
    TraiterDiagSource(SourceHandle,EmissionOk);
    #endif
    DATCplI_ASDataCon( TTxHandle,EmissionOk );
}
#endif


//==============================================================================
// DESCRIPTION : ASDT Tx frame confirmation for session layer
//
// PARAMETERS (Type,Name,Min,Max) :
// tDATCnlN_USHandle NRxHandle
// BOOL            EmissionOk 
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
#ifdef DAT_CTL_SESSION_ON
void DATCilS_ASDataCon( tDATCtlS_ASHandle STxHandle, BOOL EmissionOk )
{
    #ifdef ASDT_PRESENTATION_LAYER_ON
    tDATCilI_EcuHandle i;
    tDATCilI_MessageHandle j;
    BOOL MessageTrouve;
    #endif

    #ifndef SUPERVISION_OFF
    tDATCilTxMessage const* pTxMsg       = &TxMessages[STxHandle];

    tDATCilSourceHandle     SourceHandle = pTxMsg->Source;
    #endif

    mLIBassert( STxHandle < cDATCtl_NbSession );

    #ifdef TEMPS_EXCLUSION
    TraiterConfirmationEmission(STxHandle, EmissionOk);
    #endif

    #ifndef SUPERVISION_OFF
    TraiterDiagSource(SourceHandle,EmissionOk);
    #endif

    #ifdef ASDT_INTERACTION_LAYER_ON
    if(STxHandle<cDATCilNbASTx)
    {
        if(EmissionOk != cFalse)
        {
            if(ASDTMessageStatus[STxHandle] == cDAT_CilMsgStatus_E_COM_LOCKED)
            {
                ASDTMessageStatus[STxHandle] = cDAT_CilMsgStatus_E_COM_NOMSG;
            }
            // else the confirmation comes too late (channel has been diconnected or is disconnecting
        }
        else
        {
            #ifdef ASDT_PRESENTATION_LAYER_ON
            i=0;
            j=0;
            MessageTrouve = cFalse;

            DATCilCloseMessage(STxHandle);

            while( (i< cDATCil_NbEcu)&&(MessageTrouve != cTrue))
            {
                if(DATCilASDTIPLayer[i] == cDATCilEcuStatusConnected)
                {
                    while( (j < cDATCilNbMaxTrameTxParSource)&&(ASTxMessages[(U8)(cDATCilNbMaxTrameTxParSource*i) + j]!=cDATCilI_TxHandleInvalide)&&(MessageTrouve != cTrue))
                    {
                        if (ASTxMessages[(U8)(cDATCilNbMaxTrameTxParSource*i) + j] == STxHandle)
                        {
                            DATCilASDTIPLayer[i] = cDATCilEcuStatusDisconnected;
                            MessageTrouve = cTrue;
                        }
                        j++;
                    }
                    j=0;
                }
                i++;
            }
            #else
            ASDTMessageStatus[STxHandle] = cDAT_CilMsgStatus_E_COM_SYS_ERROR;
            #endif
        }
    }
    #endif
    DATCplI_ASSDataCon( STxHandle, EmissionOk );
}
#endif


//==============================================================================
// DESCRIPTION : Disconnection request Tx confirmation
//
// PARAMETERS (Type,Name,Min,Max) :
// tDATCtlS_ASHandle  TTxHandle
// BOOL           EmissionOk
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
#ifdef DISCONNECTION_AUTHORIZED
void DATCilS_DisconnectCon( tDATCtlS_ASHandle TTxHandle ,BOOL EmissionOk)
{
    #ifdef ASDT_INTERACTION_LAYER_ON

    #ifdef ASDT_PRESENTATION_LAYER_ON
    tDATCilI_EcuHandle i;
    tDATCilI_MessageHandle j;
    #endif

    if((TTxHandle<cDATCilNbASTx)&&(ASDTMessageStatus[TTxHandle] == cDAT_CilMsgStatus_E_COM_SYS_DISCONNECTING))
    {
        #ifdef ASDT_PRESENTATION_LAYER_ON

        i=0;
        j=0;
        while(i< cDATCil_NbEcu)
        {
            if((DATCilASDTIPLayer[i] & (cDATCilEcuStatusConnected|cDATCilEcuStatusDisconnecting|cDATCilEcuStatusDisconnected)) != (tDATCilEcuStatus)0)
            {//Pas d'etat cDATCilEcuStatusConnecting car dans ce cas il n'y pas de trame DS emise en cas d'echec de la connection
                while( (j < cDATCilNbMaxTrameTxParSource)&&(ASTxMessages[(U8)(cDATCilNbMaxTrameTxParSource*i) + j]!=cDATCilI_TxHandleInvalide))
                {
                    if (ASTxMessages[((U8)cDATCilNbMaxTrameTxParSource*i) + j] == TTxHandle)
                    {
                        if(EmissionOk != cFalse)
                        {
                            CheckTxSessionClosed(i);
                        }
                        //if the disconnection is Nok the re connection must stay possible
                        ASDTMessageStatus[TTxHandle] = cDAT_CilMsgStatus_E_COM_SYS_NOTINITIALISED;
                    }
                    j++;
                }
                j=0;
            }
            i++;
        }
        #else
        if(EmissionOk != cFalse)
        {
            ASDTMessageStatus[TTxHandle] = cDAT_CilMsgStatus_E_COM_SYS_NOTINITIALISED;
        }
    #endif
    }
    #else
    TTxHandle = TTxHandle;
    EmissionOk = EmissionOk;
    #endif

}
#endif


#ifdef DAT_CTL_SESSION_ON
//==============================================================================
// DESCRIPTION : Disconnection request Tx confirmation for session layer
//
// PARAMETERS (Type,Name,Min,Max) :
// tDATCtlS_ASHandle  TTxHandle
// BOOL           EmissionOk
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void DATCilS_ConnectCon( tDATCtlS_ASHandle TTxHandle ,BOOL EmissionOk)
{
    #ifdef ASDT_INTERACTION_LAYER_ON

    #ifdef ASDT_PRESENTATION_LAYER_ON
    tDATCilI_EcuHandle i;
    tDATCilI_MessageHandle j;
    BOOL MessageTrouve;
    #endif

    if((TTxHandle<cDATCilNbASTx)&&(ASDTMessageStatus[TTxHandle] == cDAT_CilMsgStatus_E_COM_SYS_CONNECTING))
    {
        if(EmissionOk != cFalse)
        {
            ASDTMessageStatus[TTxHandle] = cDAT_CilMsgStatus_E_COM_NOMSG;
        }
        else
        {
            ASDTMessageStatus[TTxHandle] = cDAT_CilMsgStatus_E_COM_SYS_CONNECTERROR;
        }

        #ifdef ASDT_PRESENTATION_LAYER_ON
        i=0;
        j=0;
        MessageTrouve = cFalse;

        while( (i< cDATCil_NbEcu)&&(MessageTrouve != cTrue))
        {
            if(DATCilASDTIPLayer[i] == cDATCilEcuStatusConnecting)
            {
                while( (j < cDATCilNbMaxTrameTxParSource)&&(ASTxMessages[(U8)(cDATCilNbMaxTrameTxParSource*i) + j] != cDATCilI_TxHandleInvalide)&&(MessageTrouve != cTrue))
                {
                    if (ASTxMessages[(U8)(cDATCilNbMaxTrameTxParSource*i) + j] == TTxHandle)
                    {
                        if(EmissionOk != cFalse)
                        {
                            CheckSessionOpened(i);
                        }
                        else
                        {
                            DATCilASDTIPLayer[i] = cDATCilEcuStatusDisconnected;
                            //connection is Nok, go to degraded mode
                        }
                        MessageTrouve = cTrue;
                    }
                    j++;
                }
                j=0;
            }
            i++;
        }
        #endif
    }
    #else
    TTxHandle = TTxHandle;
    EmissionOk = EmissionOk;
    #endif
}
#endif


//==============================================================================
// DESCRIPTION : Return the communciation state with an ECU
//
// PARAMETERS (Type,Name,Min,Max) :
// tDATCilSourceASDT  NumeroSourceASDT              
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
#ifdef ASDT_PRESENTATION_LAYER_ON
tDATCilEcuStatus  DATCilGetEcuStatus(tDATCilI_EcuHandle DATCil_NumeroEcu)
{
    mLIBassert(DATCil_NumeroEcu<cDATCil_NbEcu);

    return(DATCilASDTIPLayer[DATCil_NumeroEcu]);
}
#endif


//==============================================================================
// DESCRIPTION : Get ASDT channel message state
//
// PARAMETERS (Type,Name,Min,Max) :
// tDATCilI_ASSHandle  DATCil_ASDTHandle
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
#ifdef ASDT_INTERACTION_LAYER_ON
tDATCilMsgStatus  DATCilGetMessageStatus(tDATCilI_MessageHandle DATCil_ASDTHandle)
{
    mLIBassert(DATCil_ASDTHandle<cDATCil_NbMessage);
    return(ASDTMessageStatus[DATCil_ASDTHandle]);
}
#endif


//==============================================================================
// DESCRIPTION : Initialize transmit messages
//
// PARAMETERS (Type,Name,Min,Max) : none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void DATCilInitTransmission(void)
{
    tDATCilI_TxHandle ITxHandle;

    // Initialization of periodic Tx counter
    for( ITxHandle=0; ITxHandle < cDATCil_NbTx; ITxHandle++ )
    {
        tDATCilTxMessage const* pTxMsg = &TxMessages[ITxHandle];
        CompteurTickTx[ITxHandle] = pTxMsg->Phase;
    #ifdef TEMPS_EXCLUSION
        TempsExclusionTx[ITxHandle].FlagEnvoiDiffereRecalage = cFalse;
        TempsExclusionTx[ITxHandle].CompteurTick = 0;
    #endif
    }

}
//==============================================================================
// DESCRIPTION :  DATCilFramRxSurveyRestartByHandle
//
// PARAMETERS (Type,Name,Min,Max) : none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void DATCilFramRxSurveyRestartByHandle(tDATCdlD_UURxHandle DRxHandle)
{
    if (DRxHandle < cDATCdl_NbUURx)
    {
        #ifdef SUPERVISION_SURVEILLANCE_COMMANDEES
        tDATCilRxMessage const* pRxMsg = &RxMessages[DRxHandle + (cDATCil_NbSources - 1)];
        #else
        tDATCilRxMessage const* pRxMsg = &RxMessages[DRxHandle];
        #endif
        #ifndef SUPERVISION_OFF
        //tDATCilSourceHandle     SourceHandle = pRxMsg->Source;
        #endif
        #ifdef DAT_CNL_LAYER_ON
        mLIBassert(DRxHandle>=cDATCnl_NbUS);
        #endif
        if( pRxMsg->Timeout != ((tTOSTimer) 0) )
        {
            #ifdef SUPERVISION_SURVEILLANCE_COMMANDEES
            tTOSPeriodicTimer* pTempo = &TemposRx[DRxHandle + (cDATCil_NbSources - 1)];
            #else
            tTOSPeriodicTimer* pTempo = &TemposRx[DRxHandle];
            #endif
             if(TOSIsPeriodicTimerStarted(pTempo))
			 {
			     TOSStartPeriodicTimer( pTempo, pRxMsg->Timeout, pRxMsg->Timeout);
			 }
			 else
			 {
				 //timer no in working state, no operation
			 }
        }
    }
}
//==============================================================================
// DESCRIPTION :DATCilFramRxSurveyRestart
//
// PARAMETERS (Type,Name,Min,Max) : none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void DATCilFramRxSurveyRestart(void)
{
	tDATCdlD_UURxHandle DRxHandle = 0;
    while (DRxHandle < cDATCdl_NbUURx)
    {
    	if(1)//if((DRxHandle  == cDATCdlD_UURxHandlePEPS_0x320)  ||  (DRxHandle == cDATCdlD_UURxHandleBCM_0x310))
    	{
				#ifdef SUPERVISION_SURVEILLANCE_COMMANDEES
				tDATCilRxMessage const* pRxMsg = &RxMessages[DRxHandle + (cDATCil_NbSources - 1)];
				#else
				tDATCilRxMessage const* pRxMsg = &RxMessages[DRxHandle];
				#endif
				#ifndef SUPERVISION_OFF
				//tDATCilSourceHandle     SourceHandle = pRxMsg->Source;
				#endif
				#ifdef DAT_CNL_LAYER_ON
				mLIBassert(DRxHandle>=cDATCnl_NbUS);
				#endif
				if( pRxMsg->Timeout != ((tTOSTimer) 0) )
				{
					#ifdef SUPERVISION_SURVEILLANCE_COMMANDEES
					tTOSPeriodicTimer* pTempo = &TemposRx[DRxHandle + (cDATCil_NbSources - 1)];
					#else
					tTOSPeriodicTimer* pTempo = &TemposRx[DRxHandle];
					#endif
					if(TOSIsPeriodicTimerStarted(pTempo))
					{
						TOSStartPeriodicTimer( pTempo, pRxMsg->Timeout, pRxMsg->Timeout);
					}
					else
					{
						//timer no in working state, no operation
					 }
				}
    	}
        DRxHandle++;
    }
}
