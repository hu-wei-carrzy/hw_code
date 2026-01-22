
#define dat_cnl   "dat_cnl"


//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//
// #include <system_file_name.h>
// #include "project_file_name.h"
//------------------------------------------------------------------------------

#include "DAT_CNL.h"

//------------------------------------------------------------------------------
// Local macros
//
// #define mMacroName   (MacroDefinition)
//------------------------------------------------------------------------------

    //+1 because the counter is first decreased just after his loading at T=[0, one Tick CAN value].
    #define mCNLConvertInTickCanRoundUpValue(Timeout) \
    ((tTempoInTickCan)(( ((tTempoInTickCan)((Timeout) + (cDATCdlTickMs - ((U8)1UL)))) / cDATCdlTickMs) + ((U8)1UL)))

    #define mCNLConvertInTickCanRoundDownValue(Timeout) \
    ((tTempoInTickCan)(((Timeout) / cDATCdlTickMs) + ((U8)1UL)))

    #define mDATCnlBufferHandleByteMemory(TrameHandle)\
    (DATCnlByteMemoryTableROM[TrameHandle].pBuffer)

    #define mDATCnlLngBufferHandleByteMemory(TrameHandle)\
    (DATCnlByteMemoryTableLongueur[TrameHandle])

//------------------------------------------------------------------------------
// Local constants
//
// #define cConstantName   ((tType) ConstantValue)
//------------------------------------------------------------------------------

    #define cHandleInvalide   ((tDATCdlD_UURxHandle)0xffUL)

    // Value of PCI
    #define cPciSF    ((U8)0x00UL)        //Single Frame
    #define cPciFF    ((U8)0x10UL)        //First Frame
    #define cPciCF    ((U8)0x20UL)        //Consecutive Frame
    #define cPciFC    ((U8)0x30UL)        //Flow Control
    #define cPciTransport ((U8)0x70UL)    //Transport (ASDT Multimedia Renault specific)
    #define cPciCS    ((U8)0x70UL)        //Connection Setup (ASDT Multimedia Renault specific)
    #define cPciDS    ((U8)0x72UL)        //Disconnection Setup (ASDT Multimedia Renault specific)
    #define cPciAK    ((U8)0x74UL)        //Aknowledge (ASDT Multimedia Renault specific)

    // Value of Flow Status in Flow Control frame
    #define cDATCnlFlowStatusCTS   ((U8)0x00UL)     //Clear To Send
    #define cDATCnlFlowStatusWait  ((U8)0x01UL)     //Wait
    #define cDATCnlFlowStatusOverflow  ((U8)0x02UL) //Overflow
    //If the flow status is unknown the Flow Control frame is rejected

    #ifdef REPRISE_ERREUR
    //Time in tick waiting before re transmission
    #define cTempoEnTickCanAttenteReemission mCNLConvertInTickCanRoundUpValue(cDATCnlAttenteReemisionEnMs)  // YM 19/07/02 : temps d'attente pour reemettre un USDT
    #endif

    //Segmentation temporization in tick
    #define cTempoEnTickCanAttenteFC         mCNLConvertInTickCanRoundUpValue(cDATCnlTempoAttenteFC)
    #define cTempoEnTickCanAttenteCF         mCNLConvertInTickCanRoundUpValue(cDATCnlTempoAttenteCF)
    #define cTempoEnTickCanTimeOutWait       mCNLConvertInTickCanRoundUpValue(cTempoDATCnlTimeOutWait)
    #define cTempoEnTickCanTimeOutInterWait  mCNLConvertInTickCanRoundDownValue(cTempoDATCnlTimeOutInterWait)

    #ifdef PARAM_DIFF_ASDT
    //ASDT  (Multimedia Renault specific segmentation) temporization in tick
    #define cTempoEnTickCanAttenteFCASDT         mCNLConvertInTickCanRoundUpValue(cDATCnlTempoAttenteFCASDT)
    #define cTempoEnTickCanAttenteCFASDT         mCNLConvertInTickCanRoundUpValue(cDATCnlTempoAttenteCFASDT)
    #define cTempoEnTickCanTimeOutWaitASDT       mCNLConvertInTickCanRoundUpValue(cTempoDATCnlTimeOutWaitASDT)
    #define cTempoEnTickCanTimeOutInterWaitASDT  mCNLConvertInTickCanRoundDownValue(cTempoDATCnlTimeOutInterWaitASDT)
    #endif

#ifdef MSDT_FRAME_RETRANSMISSION
#if cDATCnlNbMSTxNonType > 0
#define mIsMSDTTxHandle(x)              ((BOOL)( (x) < cDATCnlNbMSTx) )
#else
#define mIsMSDTTxHandle(x)              ((BOOL)cFalse)
#endif
#endif
#ifdef cDATCnlSeparationTimeMsMSDT
#if cDATCnlNbMSTxNonType > 0
#define mIsMSDTRxHandle(x)              ((BOOL)(((x) >= cDATCnlNbMSTx) && ((x) < cDATCnl_NbMS)))
#else
#define mIsMSDTRxHandle(x)              ((BOOL)((x) < cDATCnl_NbMS))
#endif
#endif

//------------------------------------------------------------------------------
// Local types
//
// typedef Expression    tTypeName;
//------------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Local data
//
// static  tType   u8VariableName;  
// static  tType*  pu8VariableName; 
//------------------------------------------------------------------------------
#ifdef DAT_CNL_LAYER_ON
    static tDATCnlN_USHandle ReceptionTrameSurHandle[cDATCnl_NbUS];
    static tDATCnlBuffersUSByteMemory BuffersUSByteMemory;
    static U8 DATCnlByteMemoryTableLongueur[cDATCnl_NbUS]; //Length table of memorized UUDT frame before USDT treatment
    #ifdef REPRISE_ERREUR
    static U8 ucCptRepriseSurErreur[cDATCnl_NbUS];
    #endif
#endif

//------------------------------------------------------------------------------
// Constant local data
//
// static const tType  VariableName;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Exported data
//
// tType   u8LAYCmpVariableName; (LAY: 3 characters to identify the layer)
// tType*  pu8LAYCmpVariableName;(Cmp: 3 characters to identify the component)
//------------------------------------------------------------------------------
#ifdef DAT_CNL_LAYER_ON
    tDATCnl_Ident       DATCnlTable [cDATCnl_NbUS];
    tDATCnlBuffersUS    DATCnlBuffersUS;
#endif

//------------------------------------------------------------------------------
// Constant exported data
//
//             (LAY: 3 characters to identify the layer)
//             (Cmp: 3 characters to identify this component)
// 
// const tType   LAYCmpVariableName;
//------------------------------------------------------------------------------
#ifdef DAT_CNL_LAYER_ON
    const tDATCnl_IdentROM DATCnlTableROM[cDATCnl_NbUS] =
        {
            mDATCnlInitTableROM()
        };

    const tDATCnl_IdentByteMemoryROM DATCnlByteMemoryTableROM[cDATCnl_NbUS] =
        {
            mDATCnlInitByteMemoryTableROM()
        };
#endif

//------------------------------------------------------------------------------
// Local function prototypes
// 
// static tTypeRetour FunctionName(tTypeArgument1 ArgumentName1, ... );
//------------------------------------------------------------------------------
#ifdef DAT_CNL_LAYER_ON
static void InitialiseMessage(tDATCnlN_USHandle HandleUS, BOOL Acquitte);
static U8 TrouverPciSurMessageEnReception (tDATCdlD_UURxHandle HandleRx);

static void    EmettreFC           ( tDATCnlN_USHandle HandleUSRx );
static void    EmettreCF           ( tDATCnlN_USHandle HandleUSTx );
static void    EmettreFF           ( tDATCnlN_USHandle HandleUSTx );
static void    EmettreSF           ( tDATCnlN_USHandle HandleUSTx );
    #ifdef LAYER_CTL_ON
    static void    EmettreTransport    ( U8 ucPci, tDATCnlN_USHandle HandleUSTx );
    #endif
static void    TraiterFF           ( tDATCnlN_USHandle HandleUSRx );
static void    TraiterSF           ( tDATCnlN_USHandle HandleUSTx );
static void    TraiterCF           ( tDATCnlN_USHandle HandleUSRx );
static void    TraiterFC           ( tDATCnlN_USHandle HandleUSRx );
static void    TraitementTrameEnAttente (tDATCnlN_USHandle TrameRxHandle );
#endif


//==============================================================================
//=========================== LOCAL FUNCTIONS ==================================
//==============================================================================

//==============================================================================
// DESCRIPTION : Initialization of the data structure linked to one message
//
// PARAMETERS (Type,Name,Min,Max) :   tDATCnlN_USHandle HandleUS : message handle
//                                    BOOL Acquitte : if True a callback to the upper layer is sent
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
#ifdef DAT_CNL_LAYER_ON
static void InitialiseMessage(tDATCnlN_USHandle HandleUS, BOOL Acquitte)
{
    tDATCnl_Ident* pStructIdent;

    mLIBassert( HandleUS < cDATCnl_NbUS );

    pStructIdent = &(DATCnlTable[HandleUS]);

    pStructIdent->Tempo              = (tTempoInTickCan)0;
    pStructIdent->EtatHandle         =  cDATCnlMessageLibre;
    pStructIdent->Mode               =  cModeZero;
    pStructIdent->NumeroTrame        =  ((U8)0);
    pStructIdent->OctetsDejaCopies   =  ((U16)0);
    pStructIdent->pBufferSuivant     =  DATCnlTableROM[HandleUS].pBuffer;

    //Cancel the possible memorized frame reception 
    ReceptionTrameSurHandle[HandleUS] = cHandleInvalide;

    #ifdef MSDT_FRAME_RETRANSMISSION
    pStructIdent->ucRetransmitAttempt = 0;
    pStructIdent->PreviousEtatHandle =  cDATCnlMessageLibre;
    #endif

    if (Acquitte != cFalse)
    {
        DATCtlN_USDataCon(HandleUS,cFalse);
    }
}
#endif

//==============================================================================
// DESCRIPTION : Read the first byte of a received frame
//
// PARAMETERS (Type,Name,Min,Max) :   tDATCdlD_UURxHandle : UUDT frame handle
//
// RETURN VALUE :   U8 : first byte of a received frame
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
#ifdef DAT_CNL_LAYER_ON
static U8 TrouverPciSurMessageEnReception (tDATCdlD_UURxHandle HandleRx)
{
    U8 Pci;

    // Polyspace justification: amanevm: HandleRx is checked at entry points:
    // DATCnlD_UUDataInd and DATCnlD_UUDataCon.
    // Values in array ReceptionTrameSurHandle are equal to
    // cHandleInvalide or to index.
    Pci = (U8)(mDATCnlBufferHandleByteMemory(HandleRx)[0U] & ((U8)0xf0U));
    return Pci;
}
#endif

//==============================================================================
// DESCRIPTION : Treatment of a received Single Frame
//
// PARAMETERS (Type,Name,Min,Max) :   tDATCnlN_USHandle : message handle
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
#ifdef DAT_CNL_LAYER_ON
static void TraiterSF(tDATCnlN_USHandle HandleUSTx)
{
    U8* pBufferUURx = mDATCnlBufferHandleByteMemory(HandleUSTx);
    tDATCnl_Ident* pStructIdent;
    U8 TailleCopiee;

    U8 TailleRecue;

    mLIBassert( HandleUSTx < cDATCnl_NbUS );

    pStructIdent = &(DATCnlTable[HandleUSTx]);

    TailleRecue = (pBufferUURx[0U] & ((U8)0x0FU) );

    if (  (TailleRecue <= cTailleMaxMessageSingleFrame)
        &&(TailleRecue > cTailleMinMessageSingleFrame)
        &&( (TailleRecue + ((U16)1)) <= mDATCnlLngBufferHandleByteMemory(HandleUSTx))
        &&(pStructIdent->Mode != cModeEmission))
    {   //Check the length, valid if
        //-inferior or equal to the maximum length of data in a Single Frame
        //-consistency with the DLC parameter from the CAN cell (only if the frame padding is not activated)
        //A message transmission must not be cancelled by a Single Frame reception
        //(see Osek Half-Duplex exchange)

        InitialiseMessage(HandleUSTx, cFalse);

        pStructIdent->Taille  = TailleRecue;

        // copy of the frame in the local buffer
        // only the good number of received data or the maximum lenth parameterized length of this message
        TailleCopiee = ((U8)mMin(pStructIdent->Taille, ((U16)DATCnlTableROM[HandleUSTx].Lng)) );

        //QACJ 0489: amanevm: pointer arithmetic is used and it is correct
        mLIBmemcpy (DATCnlTableROM[HandleUSTx].pBuffer,pBufferUURx+1,TailleCopiee);

        mDATCnlLngHandle(HandleUSTx)=TailleCopiee;

        // call back to DAT_Ctl
        DATCtlN_USDataInd( HandleUSTx);

        //Upper layer must not provok frame transmission in the callback: here we are in the reception task context
        // but only DS, CS or Ack ASDT transmission is authorized
        mLIBassert(pStructIdent->Mode == cModeZero);
    }
}
#endif

//==============================================================================
// DESCRIPTION : Treatment of a received First Frame
//
// PARAMETERS (Type,Name,Min,Max) :   tDATCnlN_USHandle : USDT frame handle
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
#ifdef DAT_CNL_LAYER_ON
static void TraiterFF(tDATCnlN_USHandle HandleUSRx)
{
    tDATCnl_Ident* pStructIdent;
    U16 TailleMsg;
    U8* pBufferUURx;

    mLIBassert( HandleUSRx < cDATCnl_NbUS );

    pStructIdent = &(DATCnlTable[HandleUSRx]);

    pBufferUURx  = mDATCnlBufferHandleByteMemory(HandleUSRx);

    TailleMsg =  (U16)( ( ((U16)(pBufferUURx[0]) & ((U8)0x0FUL) ) << 8)+ pBufferUURx[1] );

    //Length parameter inside the first frame must be correct
        //First Frame must be a complete frame
        //A message transmission must not be cancelled by a First Frame reception
        //(see Osek Half-Duplex exchange)
    if(  (TailleMsg >= cTailleMinMessageFirstFrame)
       &&(mDATCnlLngBufferHandleByteMemory(HandleUSRx) == (U8)8UL)
       &&(pStructIdent->Mode != cModeEmission))
    {
        InitialiseMessage(HandleUSRx, cFalse);

        pStructIdent->TailleMessage   = (U16)0;
        pStructIdent->Mode = cModeReception;
        pStructIdent->Taille = TailleMsg;
        pStructIdent->OctetsDejaCopies = ((U16)6UL);

        mLIBmemcpy(DATCnlTableROM[HandleUSRx].pBuffer, pBufferUURx+2, (mMin(((U8)6UL),((U16) DATCnlTableROM[HandleUSRx].Lng))) );
        pStructIdent->pBufferSuivant += 6;

        if(DATCnlTableROM[HandleUSRx].Lng <= ((U8)6UL))
        {
            pStructIdent->TailleMessage = DATCnlTableROM[HandleUSRx].Lng;
        }

        #ifdef WAIT
        // clear the number of wait pending and initialization of the max number of wait to send
        #ifdef PARAM_DIFF_ASDT
        if(HandleUSRx<cDATCnl_NbAS)
        {
            pStructIdent->NbTrameAvantFC = ((U16)cDATCnlBlockSizeASDT);
            pStructIdent->ucNbWaitRestant |= (cDATCnlMaxNbWaitASDT);
        }
        else
        {
        #endif

            pStructIdent->NbTrameAvantFC = ((U16)cDATCnlBlockSize);
            pStructIdent->ucNbWaitRestant |= (cDATCnlMaxNbWait);

        #ifdef PARAM_DIFF_ASDT
        }
        #endif
        #else
        pStructIdent->NbTrameAvantFC = ((U16)cDATCnlBlockSize);
        #endif

        EmettreFC(HandleUSRx);
    }
}
#endif

//==============================================================================
// DESCRIPTION : Transmission of a Flow Control frame
//
// PARAMETERS (Type,Name,Min,Max) :   tDATCnlN_USHandle : message handle
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
#ifdef DAT_CNL_LAYER_ON
static void EmettreFC( tDATCnlN_USHandle HandleUSRx )
{
    U8* pTramePourEmission;
    #if (defined(WAIT) || defined(EMISSION_OVERFLOW_AUTHORIZED))
    tDATCnl_Ident* pStructIdent;
    #ifdef WAIT
    BOOL InitMessage;

    InitMessage = cFalse;
    #endif

    pStructIdent = &(DATCnlTable[HandleUSRx]);
    #endif

    mLIBassert( HandleUSRx < cDATCnl_NbUS );
    pTramePourEmission = mDATCdlBufferTxHandle(HandleUSRx);
    #ifdef WAIT
    {
    // Wait transmission requested
    if((cDATMaskDemandeDeWait & (pStructIdent->ucNbWaitRestant)) != cFalse)
    {
        if((cDATMaskComplementNbWait & (pStructIdent->ucNbWaitRestant)) != cFalse)
        {
            pTramePourEmission[0] = (U8)(cPciFC + cDATCnlFlowStatusWait);
            pStructIdent->EtatHandle = cDATCnlMessageAttenteConfFCWait;
            pStructIdent->ucNbWaitRestant &= cDATMaskComplementNbWait;
            pStructIdent->ucNbWaitRestant--; //Decrementation of the remaining number of wait
            pStructIdent->ucNbWaitRestant |= cDATMaskDemandeDeWait;
        }
        else
        {   //The maximum of wait transmission is reached
            //Initialization of the message (cf OSEK p111):
            //-The transmitter of the message will go in timeout of FC reception
            //-a new messgae can be transmit or received on this handle
            InitMessage = cTrue;
        }
    }
    else
    {
        pTramePourEmission[0] = (U8)(cPciFC + cDATCnlFlowStatusCTS);
        pStructIdent->EtatHandle = cDATCnlMessageAttenteConfFC;

    #ifdef WAIT
        #ifdef PARAM_DIFF_ASDT
        if(HandleUSRx<cDATCnl_NbAS)
        {
            pStructIdent->ucNbWaitRestant |= (cDATCnlMaxNbWaitASDT);
        }
        else
        #endif
        {
            pStructIdent->ucNbWaitRestant |= (cDATCnlMaxNbWait);
        }
    #endif
    }
    }

    #else

    pTramePourEmission[0] = (U8)(cPciFC + cDATCnlFlowStatusCTS);
    DATCnlTable[HandleUSRx].EtatHandle = cDATCnlMessageAttenteConfFC;

    #endif

    #ifdef PARAM_DIFF_ASDT
    if(HandleUSRx < cDATCnl_NbAS)
    {
        pTramePourEmission[1] = (U8)cDATCnlBlockSizeASDT;
        pTramePourEmission[2] = (U8)cDATCnlSeparationTimeMsASDT;
    }
    else
    #endif
    {
        #ifdef cDATCnlSeparationTimeMsMSDT
        if (mIsMSDTRxHandle(HandleUSRx) != cFalse)
        {
            pTramePourEmission[1] = (U8)cDATCnlBlockSize;
            pTramePourEmission[2] = (U8)cDATCnlSeparationTimeMsMSDT;
        }
        else
        #endif
        {
            pTramePourEmission[1] = (U8)cDATCnlBlockSize;
            pTramePourEmission[2] = (U8)cDATCnlSeparationTimeMs;
        }
    }

    #ifdef EMISSION_OVERFLOW_AUTHORIZED
    if( (pStructIdent->Taille > DATCnlTableROM[HandleUSRx].Lng)
#if (cDATCnl_NbASNonType > 0)
            &&(HandleUSRx >= cDATCnl_NbAS)
#endif
      )
    {   //No Overflow transmission management for an ASDT message
        //Overflow is sent only one time, just after the First Frame reception
        pTramePourEmission[0] = (U8)(cPciFC + cDATCnlFlowStatusOverflow);
        DATCnlTable[HandleUSRx].EtatHandle = cDATCnlMessageAttenteConfFCOverflow;
    }
    #endif

    #ifdef NoPadding
    mDATCdlLngTxHandle(HandleUSRx)=((U8)3UL);
    #else
    mLIBmemset(pTramePourEmission+3, cDATCnlPadding,5);
    mDATCdlLngTxHandle((tDATCdlD_UUTxHandle)HandleUSRx)=((U8)8UL);
    #endif

    #ifdef WAIT
    if(InitMessage != cFalse)
    {
        InitialiseMessage(HandleUSRx, cFalse);
    }
    else
    #endif
    {
        //UUDT frame transmission request
        DATCdlD_UUDataReq(HandleUSRx);
    }
}
#endif

//==============================================================================
// DESCRIPTION : Consecutive frame transmission
//
// PARAMETERS (Type,Name,Min,Max) :   tDATCnlN_USHandle : message handle
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
#ifdef DAT_CNL_LAYER_ON
static void EmettreCF ( tDATCnlN_USHandle HandleUSTx )
{
    tDATCnl_Ident* pStructIdent;
    U8* pTramePourEmission;
    U8 Min;

    mLIBassert( HandleUSTx < cDATCnl_NbUS );

    //Pointer on the UUDT buffer
    pTramePourEmission = mDATCdlBufferTxHandle(HandleUSTx);
    //Pointer on the message structure
    pStructIdent = &(DATCnlTable[HandleUSTx]);

    // SN (segment Number) parameter incrementation
    pStructIdent->NumeroTrame ++;
    pStructIdent->NumeroTrame &= ((U8)0x0FUL);

    // initialization of information PCI + SN
    pTramePourEmission[0] = ((U8)( (pStructIdent->NumeroTrame & ((U8)0x0FUL)) + cPciCF ));
    // data copy
    Min = ((U8)(mMin ( ((U16)7UL), ((U16)(pStructIdent->TailleMessage - pStructIdent->OctetsDejaCopies)))));
    //QACJ 0489: amanevm: pointer arithmetic is used and it is correct
    mLIBmemcpy(pTramePourEmission+1, pStructIdent->pBufferSuivant, Min) ;
    #ifndef NoPadding
    // Add byte padding in the end of the frame
    if (Min != ((U8)7UL) )
    {
        //QACJ 0489: amanevm: pointer arithmetic is used and it is correct
        mLIBmemset(pTramePourEmission+Min+1, cDATCnlPadding, 7-Min);
    }
    #endif
    //Message stucture updating
    pStructIdent->pBufferSuivant += Min;
    pStructIdent->OctetsDejaCopies += (U16)(Min);
    pStructIdent->NbTrameAvantFC --;

    #ifdef NoPadding
    mDATCdlLngTxHandle(HandleUSTx) = ((U8)(Min + 1));
    #else
    mDATCdlLngTxHandle(HandleUSTx)=((U8)8UL);
    #endif

    if ( (pStructIdent->TailleMessage) == (pStructIdent->OctetsDejaCopies) )
    {   //The last CF is sent
        pStructIdent->EtatHandle = cDATCnlMessageAttenteConfFin;
    }
    else
    {
        pStructIdent->EtatHandle = cDATCnlMessageAttenteConfCF ;
    }
    //UUDT transmission request
    DATCdlD_UUDataReq(HandleUSTx);
}
#endif

//==============================================================================
// DESCRIPTION : First Frame transmission
//
// PARAMETERS (Type,Name,Min,Max) :   tDATCnlN_USHandle : message handle
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
#ifdef DAT_CNL_LAYER_ON
static void EmettreFF (tDATCnlN_USHandle HandleUSTx )
{
    tDATCnl_Ident* pStructIdent;
    U8* pTramePourEmission;

    mLIBassert( HandleUSTx < cDATCnl_NbUS );

    //Transmssion buffer pointer
    pTramePourEmission = mDATCdlBufferTxHandle(HandleUSTx);
    //Pointer on the message structure
    pStructIdent = &(DATCnlTable[HandleUSTx]);
    //FF_DL parameter construction
    pTramePourEmission[0] = ((U8)( cPciFF + ((U8)( pStructIdent->TailleMessage >> 8)) ));
    pTramePourEmission[1] = ((U8) pStructIdent->TailleMessage);

    //Data copy
    mLIBmemcpy(pTramePourEmission+2, DATCnlTableROM[HandleUSTx].pBuffer, 6);
    //Message stucture updating
    pStructIdent->NumeroTrame = ((U8)0UL);
    pStructIdent->OctetsDejaCopies = ((U16)6UL);
    pStructIdent->pBufferSuivant = DATCnlTableROM[HandleUSTx].pBuffer + 6;
    pStructIdent->EtatHandle = cDATCnlMessageAttenteConfFF;

    mDATCdlLngTxHandle(HandleUSTx) = ((U8)8UL);
    //UUDT transmission request
    DATCdlD_UUDataReq(HandleUSTx);
}
#endif

//==============================================================================
// DESCRIPTION : Single Frame transmission
//
// PARAMETERS (Type,Name,Min,Max) :   tDATCnlN_USHandle : message handle
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
#ifdef DAT_CNL_LAYER_ON
static void EmettreSF ( tDATCnlN_USHandle HandleUSTx )
{
    U8         Longueur;
    tDATCnl_Ident* pStructIdent;
    U8*        pTramePourEmission;

    mLIBassert( HandleUSTx < cDATCnl_NbUS );

    //Transmssion buffer pointer
    pTramePourEmission = mDATCdlBufferTxHandle(HandleUSTx);
    //Pointer on the message structure
    pStructIdent = &(DATCnlTable[HandleUSTx]);

    Longueur  =  ((U8)(pStructIdent->TailleMessage)) ;
    mLIBassert(Longueur<=7);

    pTramePourEmission[0] = ((U8)( cPciSF + Longueur ));
    //QACJ 0489: amanevm: pointer arithmetic is used and it is correct
    mLIBmemcpy(pTramePourEmission+1, DATCnlTableROM[HandleUSTx].pBuffer, Longueur);
    pStructIdent->EtatHandle = cDATCnlMessageAttenteConfFin;

    #ifdef NoPadding
    mDATCdlLngTxHandle(HandleUSTx)= ((U8)(Longueur + 1));
    #else
    mDATCdlLngTxHandle(HandleUSTx)= ((U8)8UL);
    //QACJ 0489: amanevm: pointer arithmetic is used and it is correct
    mLIBmemset(pTramePourEmission+1+Longueur, cDATCnlPadding, 7-Longueur);
    #endif

    //UUDT transmission request
    DATCdlD_UUDataReq(HandleUSTx);
}
#endif

//==============================================================================
// DESCRIPTION : ASDT specific frame transmission (CS, DS or Ack)
//
// PARAMETERS (Type,Name,Min,Max) :   U8 : ASDT PCI symbol
//                                    tDATCnlN_USHandle : Message handle
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
#ifdef DAT_CNL_LAYER_ON
#ifdef LAYER_CTL_ON
static void EmettreTransport ( U8 ucPci, tDATCnlN_USHandle HandleUSTx )
{
    tDATCnl_Ident* pStructIdent;
    U8*        pTramePourEmission;

    mLIBassert( HandleUSTx < cDATCnl_NbUS );

    //Transmssion buffer pointer
    pTramePourEmission = mDATCdlBufferTxHandle(HandleUSTx);
    //Pointer on the message structure
    pStructIdent = &(DATCnlTable[HandleUSTx]);
    pTramePourEmission[0] = ucPci;

    #ifdef NoPadding
    mDATCdlLngTxHandle(HandleUSTx)=((U8)1UL);
    #else
    //QACJ 0489: amanevm: pointer arithmetic is used and it is correct
    mLIBmemset(pTramePourEmission+1, cDATCnlPadding, 7);
    mDATCdlLngTxHandle(HandleUSTx)=((U8)8UL);
    #endif
    pStructIdent->EtatHandle = cDATCnlMessageAttenteConfFin;

    DATCdlD_UUDataReq(HandleUSTx);
}
#endif
#endif

//==============================================================================
// DESCRIPTION : Consecutive Frame treatment
//
// PARAMETERS (Type,Name,Min,Max) :   tDATCnlN_USHandle : message handle
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//                      if the frame contains error the reception is cancelled
//==============================================================================
#ifdef DAT_CNL_LAYER_ON
static void TraiterCF(tDATCnlN_USHandle HandleUSRx)
{
    U8 NumeroDeTrame ;

    tDATCnl_Ident* pStructIdent;
    U8*        pBufferUURx;
    U8         TailleACopier;

    BOOL FlagInit;
    BOOL ParamInit;

    FlagInit = cFalse;
    ParamInit = cFalse;

    mLIBassert( HandleUSRx < cDATCnl_NbUS );

    //Transmssion buffer pointer
    pBufferUURx = mDATCnlBufferHandleByteMemory(HandleUSRx);
    //Pointer on the message structure
    pStructIdent = &(DATCnlTable[HandleUSRx]);

    //Check if a CF is awaited
    if (pStructIdent->EtatHandle == cDATCnlMessageAttenteCF)
    {
        //Clear the reception timeout
        pStructIdent->Tempo = (tTempoInTickCan)0;

        NumeroDeTrame = (U8)( pBufferUURx[0] & ((U8)0x0FUL) );
        // Segment Number checking (after .0xf it must be 0x0)
        if ( ((pStructIdent->NumeroTrame + ((U8)1UL)) == NumeroDeTrame) || ((NumeroDeTrame == ((U8)0UL)) && (pStructIdent->NumeroTrame == ((U8)15UL))))
        {
            pStructIdent->NumeroTrame = NumeroDeTrame;
            //Data copy
            //if OctetsDejaCopies + 7 > maximum length of the message buffer the segmentation is processing
            //but overflowing data are not copying
            if (  ((U16)(pStructIdent->OctetsDejaCopies + ((U16)7UL)))
                >=((U16)(mMin(pStructIdent->Taille,((U16) DATCnlTableROM[HandleUSRx].Lng))))
               )
            {
                //Check if the message is allready ended or the overflowing is allready treated
                if(pStructIdent->Mode != cDATCnlMessageTermineEtSegmentationEnCours)
                {
                    pStructIdent->Mode = cDATCnlMessageTermineEtSegmentationEnCours;

                    //RAM Buffer length must be superior to 6 bytes
                    if(DATCnlTableROM[HandleUSRx].Lng > ((U8)6UL))
                    {
                        if(  (((U16)(pStructIdent->Taille-pStructIdent->OctetsDejaCopies)) <= ((U16)7UL))
                           &&((pStructIdent->Taille-pStructIdent->OctetsDejaCopies) <= (DATCnlTableROM[HandleUSRx].Lng-pStructIdent->OctetsDejaCopies) ))
                        {
                            TailleACopier = ((U8)(pStructIdent->Taille - pStructIdent->OctetsDejaCopies));
                        }
                        else
                        {
                            TailleACopier = ((U8)(DATCnlTableROM[HandleUSRx].Lng - pStructIdent->OctetsDejaCopies));
                        }

                        //QACJ 0489: amanevm: pointer arithmetic is used and it is correct
                        mLIBmemcpy(pStructIdent->pBufferSuivant, pBufferUURx+1,TailleACopier);

                        if( !( (mDATCnlLngBufferHandleByteMemory(HandleUSRx) - 1) < TailleACopier) ) // -1 car il faut tenir compte de la présence du NPCI
                        {    //check the lack of data into the last frame
                             mDATCnlLngHandle(HandleUSRx) =  ((U16)(pStructIdent->OctetsDejaCopies + TailleACopier));
                        }
                        else
                        {
                            FlagInit  = cTrue;
                            ParamInit = cFalse;
                        }
                    }//Data has been allready copying during the FF reception treatment
                }
            }
            else
            {
                //QACJ 0489: amanevm: pointer arithmetic is used and it is correct
                mLIBmemcpy(pStructIdent->pBufferSuivant, pBufferUURx+1,7);
                pStructIdent->pBufferSuivant += ((U8)7UL);
            }

            pStructIdent->NbTrameAvantFC--;
            pStructIdent->OctetsDejaCopies += ((U16)7UL);

            //Check if it's the last CF
            if ( pStructIdent->OctetsDejaCopies < pStructIdent->Taille)
            {
                if(mDATCnlLngBufferHandleByteMemory(HandleUSRx) != ((U8)8UL))
                {//the frame is not complete: reception is cancelled
                    FlagInit  = cTrue;
                    ParamInit = cFalse;
                }
                else
                {
                    if(pStructIdent->NbTrameAvantFC == ((U16)0UL))
                    {   //Flow Control transmission
                        EmettreFC(HandleUSRx) ;
                    }
                    else
                    {// wait for next CF reception
                        pStructIdent->EtatHandle = cDATCnlMessageAttenteCF;
                        #ifdef PARAM_DIFF_ASDT
                        if(HandleUSRx < cDATCnl_NbAS)
                        {
                            pStructIdent->Tempo = ((tTempoInTickCan)cTempoEnTickCanAttenteCFASDT);
                        }
                        else
                        {
                            pStructIdent->Tempo = ((tTempoInTickCan)cTempoEnTickCanAttenteCF);
                        }
                        #else
                        pStructIdent->Tempo = ((tTempoInTickCan)cTempoEnTickCanAttenteCF);
                        #endif
                    }
                }
            }
            else
            {   //Reception is finished
                if( (mDATCnlLngBufferHandleByteMemory(HandleUSRx) - ((U8)1UL)) >= ((U8)(pStructIdent->Taille - (pStructIdent->OctetsDejaCopies - ((U16)7UL)) )) )
                {   //Messahe reception is correct: callback to the upper layer
                    DATCtlN_USDataInd(HandleUSRx);
                }
                #ifdef LAYER_CTL_ON
                if(HandleUSRx >= cDATCnl_NbAS)
                #endif
                {
                    FlagInit  = cTrue;
                    ParamInit = cFalse;
                }
                //Upper layer must not provok frame transmission in the callback: here we are in the reception task context
                // but only DS, CS or Ack ASDT transmission is authorized
                mLIBassert((pStructIdent->Mode == cModeReception)||(pStructIdent->Mode == cDATCnlMessageTermineEtSegmentationEnCours));
                //Do not re initialized all because ASDT treatment need them (after Ack managment)
                pStructIdent->Mode = cModeZero;
            }
        }
        else // Error during the message reception
        {
            FlagInit  = cTrue;
            ParamInit = cFalse;

            #ifdef DAT_CTL2_MSDT_LAYER_ON
            FlagInit  = cFalse;
            InitialiseMessage(HandleUSRx, cFalse); // Init message before calling callback to CTL layer
            DATCtlN_WrongCFDataInd(HandleUSRx);
            #endif
        }
    }//Non awaited frame : to ignore

    if (FlagInit != cFalse)
    {
        InitialiseMessage(HandleUSRx, ParamInit);
    }
}
#endif

//==============================================================================
// DESCRIPTION : Flow control reception treatment
//
// PARAMETERS (Type,Name,Min,Max) : tDATCnlN_USHandle : Message handle
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//                      if the frame is not awaited the frame is rejected but
//                      message reception can continue
//==============================================================================
#ifdef DAT_CNL_LAYER_ON
static void TraiterFC ( tDATCnlN_USHandle HandleUSRx )
{
    tDATCnl_Ident* pStructIdent;
    U8*        pBufferUURx;

    U8 FlowStatus;

    mLIBassert( HandleUSRx < cDATCnl_NbUS );

    //Transmssion buffer pointer
    pBufferUURx = mDATCnlBufferHandleByteMemory(HandleUSRx);
    //Pointer on the message structure
    pStructIdent = &(DATCnlTable[HandleUSRx]);

    FlowStatus = (U8)(pBufferUURx[0] & ((U8)0x0FUL));

    // this is an awaited frame
    if( ( pStructIdent->EtatHandle & (cDATCnlMessageAttenteFirstFC |  cDATCnlMessageAttenteFC | cDATCnlMessageAttenteProchainWait ) ) != 0 )
    {
        if(  (  (FlowStatus == cDATCnlFlowStatusCTS)
                ||(FlowStatus == cDATCnlFlowStatusWait)
                ||(FlowStatus == cDATCnlFlowStatusOverflow)
             )
           &&(mDATCnlLngBufferHandleByteMemory(HandleUSRx) >= ((U8)3UL)) )
        {   //Flow Status must be defined by the Diag on Can
            #if (defined(DAT_CNL_OVERFLOW) && defined(WAIT))

            #elif defined(DAT_CNL_OVERFLOW)
            if (FlowStatus != cDATCnlFlowStatusWait)
            {
                //FS Wait is not supported : the frame can be rejected
            #elif defined(WAIT)
            if(FlowStatus != cDATCnlFlowStatusOverflow)
                //FS Overflow is not supported : the frame can be rejected
            {
            #else
            if(FlowStatus == cDATCnlFlowStatusCTS)
            {
            #endif

            if (pStructIdent->EtatHandle == cDATCnlMessageAttenteFirstFC)
            {
                tTempoInTickCan TempoInTickCan;

                //=====================================================
                //STmin parameter treatment

                if (pBufferUURx[2] >= ((U8)0x7FUL)) // 255ms temporization
                {
                    TempoInTickCan = mCNLConvertInTickCanRoundUpValue((U8)0x7FUL);
                }
                else if (pBufferUURx[2] == ((U8)0UL))
                {   //CF frame will be send at each tick CAN
                    TempoInTickCan = (tTempoInTickCan)1;
                }
                else
                {
                    TempoInTickCan = (tTempoInTickCan)mCNLConvertInTickCanRoundUpValue((U8)pBufferUURx[2]);
                }

                //STmin taking into account can be 170 ms at the maximum
                pStructIdent->TempsDeSeparation = ((tTempoInTickCan)mMin(cDATCnlSTminMaxInTickCan,TempoInTickCan));
                //=====================================================

                //=====================================================
                //BS parameter treatment
                if ( pBufferUURx[1] == ((U8)0UL) )
                {
                    pStructIdent->NbTramesConsecutives =  ((U16)( ((U16)(pStructIdent->TailleMessage - ((U16)6UL)) /((U16)7UL)) + ((U16)1UL) ) );
                    pStructIdent->NbTrameAvantFC       =  pStructIdent->NbTramesConsecutives;
                }
                else
                {
                    pStructIdent->NbTramesConsecutives = ((U16)pBufferUURx[1]);
                    pStructIdent->NbTrameAvantFC       = ((U16)pBufferUURx[1]);
                }
                //=====================================================
            }
            else
            {
                pStructIdent->NbTrameAvantFC = pStructIdent->NbTramesConsecutives;
                //Parameters are not updated if the FC is not the first one
                // cf OSEK/VDX Communication Specification page 75 paragraphes 3.1.3.3. & 3.1.3.4
            }
        #if (defined(DAT_CNL_OVERFLOW) && defined(WAIT))

        #else
        }//FS not supported
        #endif

            switch (FlowStatus)
            {
                #ifdef DAT_CNL_OVERFLOW
                case(cDATCnlFlowStatusOverflow):
                {   //No error treatment in case of overflow from the receptor
                    InitialiseMessage(HandleUSRx,cTrue);
                    break;
                }
                #endif

                #ifdef WAIT
                case(cDATCnlFlowStatusWait):
                {
                    // Temporization timeout for next FC reception
                    pStructIdent->EtatHandle = cDATCnlMessageAttenteProchainWait;
                    #ifdef PARAM_DIFF_ASDT
                    if(HandleUSRx < cDATCnl_NbAS)
                    {
                        pStructIdent->Tempo = ((tTempoInTickCan)cTempoEnTickCanTimeOutWaitASDT);
                    }
                    else
                    {
                        pStructIdent->Tempo = ((tTempoInTickCan)cTempoEnTickCanTimeOutWait);
                    }
                    #else
                    pStructIdent->Tempo = ((tTempoInTickCan)cTempoEnTickCanTimeOutWait);
                    #endif
                    break;
                }
                #endif

                case(cDATCnlFlowStatusCTS):
                {
                    #ifndef DAT_CNL_DELAY_FIRST_CF
                    EmettreCF(HandleUSRx);
                    #else
                    pStructIdent->EtatHandle = cDATCnlMessageAttenteST;
                    pStructIdent->Tempo = ((tTempoInTickCan)pStructIdent->TempsDeSeparation);
                    #endif
                    break;
                }

                //QACJ 2018: amanevm: depends on #define directives
                default:
                {   //FS non supported: the frame is ignored, the N_Bs timeout will fall after
                    mLIBassert(cTrue); //For QAC
                    break;
                }
            }
        }
        else
        {
            //If the Flow Status is unknown or the length is not correct the transmission is stopped
            #ifdef REPRISE_ERREUR
            //a re transmission will be activated
            pStructIdent->Tempo = ((tTempoInTickCan)cTempoEnTickCanAttenteReemission);
            pStructIdent->EtatHandle = cDATCnlMessageAttenteReemission;
            #else
            InitialiseMessage(HandleUSRx,cTrue);
            #endif
        }
    }
    
    //Non awaited from : ignore the frame
    //Re transmission is pending: frame is ignored
    //Length is not correct: frame is ignored
}
#endif

//==============================================================================
// DESCRIPTION : Treat a UUDT frame reception from a message switch the PCI value
//
// PARAMETERS (Type,Name,Min,Max) :   tDATCnlN_USHandle : message handle
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
#ifdef DAT_CNL_LAYER_ON
static void TraitementTrameEnAttente (tDATCnlN_USHandle TrameRxHandle )
{
    U8 Pci;

    Pci = TrouverPciSurMessageEnReception(TrameRxHandle);

    switch ( Pci )
    {
        case cPciSF : // Single Frame
            TraiterSF (TrameRxHandle);
            break;

        case cPciFF : // First Frame
            TraiterFF (TrameRxHandle);
            break;

        case cPciCF : // Consecutive Frame
            TraiterCF (TrameRxHandle);
            break;

        case cPciFC : // Flow Control
            TraiterFC (TrameRxHandle);
            #ifdef DAT_CTL2_MSDT_LAYER_ON
            DATCtlN_FCDataInd(TrameRxHandle);
            #endif
            break;

        #ifdef LAYER_CTL_ON
        case cPciTransport : //ASDT PCI
            if(TrameRxHandle < cDATCnl_NbAS)
            {
                if(mDATCnlBufferHandleByteMemory(TrameRxHandle)[0] == cPciAK)
                {   //Re-initialize the message structure in case of non awaited Ack reception
                    InitialiseMessage( TrameRxHandle, cFalse);
                }
                DATCtlN_ASDataInd(TrameRxHandle);
            }
            break;
        #endif

        default :
            //unknown PCI
            mLIBassert(cTrue); //For QAC
            break;
    }
}
#endif

//==============================================================================
//=========================== EXPORTED FUNCTIONS ===============================
//==============================================================================

//==============================================================================
// DESCRIPTION : ASDT ack transmission request
//
// PARAMETERS (Type,Name,Min,Max) : tDATCnlN_USHandle : ASDT message handle
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
#ifdef DAT_CNL_LAYER_ON
#ifdef LAYER_CTL_ON
void DATCnlN_USDataReqAcq(tDATCnlN_USHandle MessageHandle)
{
    mLIBassert(MessageHandle<cDATCnl_NbAS);
    EmettreTransport(cPciAK,MessageHandle);
}
#endif
#endif

//==============================================================================
// DESCRIPTION : ASDT DS transmission request
//
// PARAMETERS (Type,Name,Min,Max) : tDATCnlN_USHandle : ASDT message handle
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
#ifdef DAT_CNL_LAYER_ON
#ifdef LAYER_CTL_ON
  #ifdef DISCONNECTION_AUTHORIZED

void DATCnlN_USDataReqDS(tDATCnlN_USHandle MessageHandle)
{
    EmettreTransport(cPciDS,MessageHandle);
}
  #endif
#endif
#endif

//==============================================================================
// DESCRIPTION : ASDT CS transmission request
//
// PARAMETERS (Type,Name,Min,Max) : tDATCnlN_USHandle : ASDT message handle
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
#ifdef DAT_CNL_LAYER_ON
#ifdef LAYER_CTL_ON
void DATCnlN_USDataReqCS(tDATCnlN_USHandle MessageHandle)
{
    EmettreTransport(cPciCS,MessageHandle);
}
#endif
#endif

//==============================================================================
// DESCRIPTION : USDT message transmission request
//
// PARAMETERS (Type,Name,Min,Max) : tDATCnlN_USHandle : USDT message handle
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
#ifdef DAT_CNL_LAYER_ON
void DATCnlN_USDataReq(tDATCnlN_USHandle MessageHandle)
{
    mLIBassert(MessageHandle < cDATCnl_NbUS);

    // Transmit message overwrites reception - can heppen only in case of Diagnostic
    InitialiseMessage(MessageHandle, cFalse);

    //La taille du message a emettre ne doit pas depasser la taille du buffer associ?
    mLIBassert(DATCnlTable[MessageHandle].TailleMessage <= DATCnlTableROM[MessageHandle].Lng );

    DATCnlTable[MessageHandle].Mode = cModeEmission;

    if (DATCnlTable[MessageHandle].TailleMessage <= ((U16)7UL))
    {
        EmettreSF(MessageHandle);
    }
    else
    {
        mLIBassert( MessageHandle < cDATCnl_NbUS );
        EmettreFF(MessageHandle);
    }
}
#endif

//==============================================================================
// DESCRIPTION : Reception of UUDT frame management
//
// PARAMETERS (Type,Name,Min,Max) :   tDATCdlD_UURxHandle : UUDT frame handle
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//                      The case where a reception occurs while the state machine is in
//                      transmission confirmation on the previous frame sending is taking
//                      into account (see also NT 02 1878 (in french))
//==============================================================================
#ifdef DAT_CNL_LAYER_ON
void DATCnlD_UUDataInd(tDATCdlD_UURxHandle TrameRxHandle)
{
    U16 Etat;
    U8 PCIFrame;

    if (TrameRxHandle >= cDATCnl_NbUS)
    {   // Handle concerning only UUDT frame
        DATCtlN_UUDataInd(TrameRxHandle);
    }
    else
    {
        #ifndef NoPadding
        if(mDATCdlLngRxHandle(TrameRxHandle) == ((U8)8UL) )
        {
        #endif
            //Copy the frame data into a local buffer to take into account a differed treatment
            mLIBmemcpy(mDATCnlBufferHandleByteMemory(TrameRxHandle), mDATCdlBufferRxHandle(TrameRxHandle), DATCnlByteMemoryTableROM[TrameRxHandle].Lng);
            // Polyspace justification: amanevm: In case of using DAT_CDL cmponent with rolling buffer
            // DAT_CDL ensures read and write indexes are in range
            mDATCnlLngBufferHandleByteMemory(TrameRxHandle) = mDATCdlLngRxHandle(TrameRxHandle);

            //PCI value extraction (based on the local buffer content)
            PCIFrame = TrouverPciSurMessageEnReception(TrameRxHandle);

            if (  ( ReceptionTrameSurHandle[TrameRxHandle] == cHandleInvalide)
                &&(PCIFrame != cPciFF)
                &&(PCIFrame != cPciSF))
            {
                Etat = DATCnlTable[TrameRxHandle].EtatHandle;

                if( (Etat & ( cDATCnlMessageAttenteConfFF |
                              cDATCnlMessageAttenteConfFC |
                              cDATCnlMessageAttenteConfCF |
                              cDATCnlMessageAttenteConfFin ) ) != 0 )
                {
                    //Reception of a frame before the previous frame transmission
                    //confiramtion callback, memorization of the current handle
                    ReceptionTrameSurHandle[TrameRxHandle] = (TrameRxHandle);
                }
                #if (defined(EMISSION_OVERFLOW_AUTHORIZED) && defined(WAIT))
                else if((Etat & (cDATCnlMessageAttenteConfFCWait | cDATCnlMessageAttenteConfFCOverflow)) == 0)
                #elif defined(WAIT)
                else if((Etat & cDATCnlMessageAttenteConfFCWait) == 0)
                #elif defined(EMISSION_OVERFLOW_AUTHORIZED)
                else if((Etat & cDATCnlMessageAttenteConfFCOverflow) == 0)
                #else
                else
                #endif
                {
                    TraitementTrameEnAttente (TrameRxHandle);
                }
                //For QAC
                #if (defined(EMISSION_OVERFLOW_AUTHORIZED) || defined(WAIT))
                else
                {

                }
                #endif
            }
            else
            {
                TraitementTrameEnAttente (TrameRxHandle);
            }
        #ifndef NoPadding
        }
        else
        {
            //Ignore the frame
            mLIBassert(cTrue); //For QAC
        }
        #endif

    }
}
#endif

//==============================================================================
// DESCRIPTION : Callback from DAT_cdl on frame end of transmission
//
// PARAMETERS (Type,Name,Min,Max) :   tDATCdlD_UUTxHandle : Frame handle
//                                    EmissionOK :   transmission status
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
#ifdef DAT_CNL_LAYER_ON
void DATCnlD_UUDataCon(tDATCdlD_UUTxHandle TrameTxHandle, BOOL EmissionOK)
{
    if(TrameTxHandle >= cDATCnl_NbUS)
    {   //UUDT frame confirmation of transmission
        DATCtlN_UUDataCon(TrameTxHandle, EmissionOK);
    }
    else
    {
        tDATCnl_Ident* pStructIdent;

        pStructIdent = &(DATCnlTable[TrameTxHandle]);

        switch(pStructIdent->EtatHandle)
        {
            case cDATCnlMessageAttenteConfFF : //First frame message transmission
                if( EmissionOK == cFalse )
                {
                    #if defined(MSDT_FRAME_RETRANSMISSION)
                    // GEN-CRCCANLS-ST-DOC.0010(0)
                    if (mIsMSDTTxHandle(TrameTxHandle) != cFalse)
                    {
                        pStructIdent->ucRetransmitAttempt ++;
                        // GEN-CRCCANLS-ST-DOC.0012(0)
                        if (pStructIdent->ucRetransmitAttempt <= cMaxMSDTFrameRetransmitAttempts)
                        {
                            pStructIdent->Tempo = ((tTempoInTickCan)mCNLConvertInTickCanRoundUpValue(cMSDTFrameRetransmissionExclusionTimeMs));
                            pStructIdent->PreviousEtatHandle = pStructIdent->EtatHandle;
                            pStructIdent->EtatHandle = cDATCnlMessageAttenteReemission;
                        }
                        else
                        {
                            // First frame has not been sent: initilaization of the message structure
                            // and call back to the upper layer
                            InitialiseMessage(TrameTxHandle, cTrue);
                        }
                    }
                    else
                    {
                    #endif
                    #ifdef REPRISE_ERREUR
                    pStructIdent->Tempo = ((tTempoInTickCan)cTempoEnTickCanAttenteReemission);
                    pStructIdent->EtatHandle = cDATCnlMessageAttenteReemission;
                    #else
                    // First frame has not been sent: initilaization of the message structure
                    // and call back to the upper layer
                    InitialiseMessage(TrameTxHandle, cTrue);
                    #endif
                    #if defined(MSDT_FRAME_RETRANSMISSION)
                    }
                    #endif
                }
                else
                {
                    // FF transmission OK : waiting for the first Flow control
                    // from the receiver of the message
                    pStructIdent->EtatHandle = cDATCnlMessageAttenteFirstFC;
                    // Launch the FC reception timeout
                    #ifdef PARAM_DIFF_ASDT
                    if(TrameTxHandle < cDATCnl_NbAS)
                    {
                        pStructIdent->Tempo = ((tTempoInTickCan)cTempoEnTickCanAttenteFCASDT);
                    }
                    else
                    {
                        pStructIdent->Tempo = ((tTempoInTickCan)cTempoEnTickCanAttenteFC);
                    }
                    #else
                    pStructIdent->Tempo = ((tTempoInTickCan)cTempoEnTickCanAttenteFC);
                    #endif

                    #if defined(MSDT_FRAME_RETRANSMISSION)
                    // GEN-CRCCANLS-ST-DOC.0012(0)
                    if (mIsMSDTTxHandle(TrameTxHandle) && (pStructIdent->PreviousEtatHandle != cDATCnlMessageAttenteFirstFC))
                    {
                        pStructIdent->ucRetransmitAttempt = 0;
                    }
                    #endif
                }
                break;

            #ifdef EMISSION_OVERFLOW_AUTHORIZED
            case cDATCnlMessageAttenteConfFCOverflow :
                InitialiseMessage(TrameTxHandle, cFalse);
                //Overflow transmission: Ok or Nok but the reception
                //of the message is canceled
                break;
            #endif

            case cDATCnlMessageAttenteConfFC : // Flow Control has been sent
                if ( EmissionOK == cFalse  )
                {   //Transmission Nok: message reception is canceled
                    InitialiseMessage(TrameTxHandle, cFalse);
                }
                else
                {   //Waiting for reception of the next Consecutive Frame
                    //switch BS and STmin parameter sent 
                    pStructIdent->EtatHandle = cDATCnlMessageAttenteCF;
                    #ifdef PARAM_DIFF_ASDT
                    if(TrameTxHandle < cDATCnl_NbAS)
                    {
                        pStructIdent->Tempo = ((tTempoInTickCan)cTempoEnTickCanAttenteCFASDT);
                        pStructIdent->NbTrameAvantFC = ((U16)cDATCnlBlockSizeASDT);
                    }
                    else
                    {
                        pStructIdent->Tempo = ((tTempoInTickCan)cTempoEnTickCanAttenteCF);
                        pStructIdent->NbTrameAvantFC = ((U16)cDATCnlBlockSize);
                    }
                    #else
                    pStructIdent->Tempo = ((tTempoInTickCan)cTempoEnTickCanAttenteCF);
                    pStructIdent->NbTrameAvantFC = ((U16)cDATCnlBlockSize);
                    #endif
                }
                break;

            #ifdef WAIT
            case cDATCnlMessageAttenteConfFCWait :
                //Flow Contol transmission with Flow Status = Wait
                if ( EmissionOK == cFalse  )
                {
                    InitialiseMessage(TrameTxHandle, cFalse);
                }
                else
                {
                    //Launch the temporization before the next transmission of FC frame
                    //to avoid timeout on message sender part and to maintain it in
                    //waiting state
                    pStructIdent->EtatHandle = cDATCnlMessageAttenteEnvoiWait;
                    #ifdef PARAM_DIFF_ASDT
                    if(TrameTxHandle < cDATCnl_NbAS)
                    {
                        pStructIdent->Tempo = ((tTempoInTickCan)cTempoEnTickCanTimeOutInterWaitASDT);
                    }
                    else
                    {
                        pStructIdent->Tempo = ((tTempoInTickCan)cTempoEnTickCanTimeOutInterWait);
                    }
                    #else
                    pStructIdent->Tempo = ((tTempoInTickCan)cTempoEnTickCanTimeOutInterWait);
                    #endif
                }
                break;
            #endif

            case cDATCnlMessageAttenteConfCF : // Consecutive Frame transmission
                if ( EmissionOK == cFalse )
                {
                    #if defined(MSDT_FRAME_RETRANSMISSION)
                    // GEN-CRCCANLS-ST-DOC.0010(0)
                    if (mIsMSDTTxHandle(TrameTxHandle) != cFalse)
                    {
                        pStructIdent->ucRetransmitAttempt ++;
                        // GEN-CRCCANLS-ST-DOC.0012(0)
                        if (pStructIdent->ucRetransmitAttempt <= cMaxMSDTFrameRetransmitAttempts)
                        {
                            pStructIdent->Tempo = ((tTempoInTickCan)mCNLConvertInTickCanRoundUpValue(cMSDTFrameRetransmissionExclusionTimeMs));
                            pStructIdent->PreviousEtatHandle = pStructIdent->EtatHandle;
                            pStructIdent->EtatHandle = cDATCnlMessageAttenteReemission;
                        }
                        else
                        {
                            // consecutive_Frame has not been sent: initilaization of the message structure
                            // and call back to the upper layer
                            InitialiseMessage(TrameTxHandle, cTrue);
                        }
                    }
                    else
                    {
                    #endif
                    #ifdef REPRISE_ERREUR
                    pStructIdent->Tempo = ((tTempoInTickCan)cTempoEnTickCanAttenteReemission);
                    pStructIdent->EtatHandle = cDATCnlMessageAttenteReemission;
                    #else
                    InitialiseMessage(TrameTxHandle, cTrue);
                    #endif
                    #if defined(MSDT_FRAME_RETRANSMISSION)
                    }
                    #endif
                }
                else
                {
                    if ( pStructIdent->NbTrameAvantFC == ((U16)0UL)  )
                    {
                        //Waiting for the Flow Control reception
                        pStructIdent->EtatHandle = cDATCnlMessageAttenteFC;
                        #ifdef PARAM_DIFF_ASDT
                        if(TrameTxHandle < cDATCnl_NbAS)
                        {
                            pStructIdent->Tempo = ((tTempoInTickCan)cTempoEnTickCanAttenteFCASDT);
                        }
                        else
                        {
                            pStructIdent->Tempo = ((tTempoInTickCan)cTempoEnTickCanAttenteFC);
                        }
                        #else
                        pStructIdent->Tempo = ((tTempoInTickCan)cTempoEnTickCanAttenteFC);
                        #endif
                    }
                    else
                    {
                        //Next CF transmission will occur after the StMin temporization
                        pStructIdent->EtatHandle = cDATCnlMessageAttenteST;
                        pStructIdent->Tempo = ((tTempoInTickCan)pStructIdent->TempsDeSeparation);
                    }

                    #if defined(MSDT_FRAME_RETRANSMISSION)
                    // GEN-CRCCANLS-ST-DOC.0012(0)
                    if (mIsMSDTTxHandle(TrameTxHandle) != cFalse)
                    {
                        pStructIdent->ucRetransmitAttempt = 0;
                    }
                    #endif
                }
                break;

                case cDATCnlMessageAttenteConfFin : //End of transmission of USDT or ASDT message
                {
                    pStructIdent->Mode = cModeZero;
                    if ( EmissionOK == cFalse )
                    {
                        #if defined(MSDT_FRAME_RETRANSMISSION)
                        // GEN-CRCCANLS-ST-DOC.0010(0)
                        if (mIsMSDTTxHandle(TrameTxHandle) != cFalse)
                        {
                            pStructIdent->ucRetransmitAttempt ++;
                            // GEN-CRCCANLS-ST-DOC.0012(0)
                            if (pStructIdent->ucRetransmitAttempt <= cMaxMSDTFrameRetransmitAttempts)
                            {
                                pStructIdent->Tempo = ((tTempoInTickCan)mCNLConvertInTickCanRoundUpValue(cMSDTFrameRetransmissionExclusionTimeMs));
                                pStructIdent->PreviousEtatHandle = pStructIdent->EtatHandle;
                                pStructIdent->EtatHandle = cDATCnlMessageAttenteReemission;
                            }
                            else
                            {
                                // Last consecutive frame has not been sent: initilaization of the message structure
                                // and call back to the upper layer
                                InitialiseMessage(TrameTxHandle, cTrue);
                            }
                        }
                        else
                        {
                        #endif
                        #ifdef REPRISE_ERREUR
                        pStructIdent->Tempo = ((tTempoInTickCan)cTempoEnTickCanAttenteReemission);
                        pStructIdent->EtatHandle = cDATCnlMessageAttenteReemission;
                        #else
                        InitialiseMessage(TrameTxHandle, cTrue);
                        #endif
                        #if defined(MSDT_FRAME_RETRANSMISSION)
                        }
                        #endif
                    }
                    else
                    {   //Message has been sent
                        #ifdef REPRISE_ERREUR
                        ucCptRepriseSurErreur[TrameTxHandle] = cDATCnlMaxRepriseSurErreur;
                        #endif
                        pStructIdent->EtatHandle = cDATCnlMessageConfirmation;

                        #if defined(MSDT_FRAME_RETRANSMISSION)
                        // GEN-CRCCANLS-ST-DOC.0012(0)
                        if (mIsMSDTTxHandle(TrameTxHandle) != cFalse)
                        {
                            pStructIdent->ucRetransmitAttempt = 0;
                        }
                        #endif

                        //Callback to the upper layer
                        DATCtlN_USDataCon(TrameTxHandle, EmissionOK);
                    }
                }
                break;

            default:
                //Non awaited transmission confirmation: initialization of the message
                //structure to avoid to block this message channel
                InitialiseMessage(TrameTxHandle, cTrue);
                break;
        }

        //Case of a reception before the previous frame transmission
        //confirmation callback
        if (ReceptionTrameSurHandle[TrameTxHandle] != cHandleInvalide)
        {
            TraitementTrameEnAttente(ReceptionTrameSurHandle[TrameTxHandle]);
            ReceptionTrameSurHandle[TrameTxHandle] = cHandleInvalide;
        }
    }
}
#endif

//==============================================================================
// DESCRIPTION : All the periodic treatment (CAN tick context)
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
#ifdef DAT_CNL_LAYER_ON
void DATCnlTick(void)
{
    tDATCnlN_USHandle HandleUS;
    tDATCnl_Ident* pStructIdent;

    for (HandleUS=0; HandleUS < cDATCnl_NbUS; HandleUS++)
    {
        pStructIdent = &(DATCnlTable[HandleUS]);

        if(pStructIdent->Tempo != ((tTempoInTickCan)0UL))
        {
            pStructIdent->Tempo--;
            if(pStructIdent->Tempo == ((tTempoInTickCan)0UL))
            {   //The timeout is reached!
                switch (pStructIdent->EtatHandle)
                {
                    case cDATCnlMessageAttenteFirstFC : //waiting for first Flow Control reception
                    case cDATCnlMessageAttenteFC :      //waiting for next Flow Control reception
                    {
                        #if defined(MSDT_FRAME_RETRANSMISSION)
                        // GEN-CRCCANLS-ST-DOC.0011(0)
                        if (mIsMSDTTxHandle(HandleUS) && (pStructIdent->EtatHandle == cDATCnlMessageAttenteFirstFC))
                        {
                            pStructIdent->ucRetransmitAttempt ++;
                            // GEN-CRCCANLS-ST-DOC.0012(0)
                            if (pStructIdent->ucRetransmitAttempt <= cMaxMSDTFrameRetransmitAttempts)
                            {
                                pStructIdent->EtatHandle = cDATCnlMessageAttenteConfFF;
                                pStructIdent->PreviousEtatHandle = cDATCnlMessageAttenteFirstFC;
                                // retransmit without loading new data and waiting
                                DATCdlD_UUDataReq(HandleUS);
                            }
                            else
                            {
                                // First frame has not been sent: initilaization of the message structure
                                // and call back to the upper layer
                                InitialiseMessage(HandleUS, cTrue);
                            }
                        }
                        else
                        {
                        #endif
                        #ifdef REPRISE_ERREUR
                        pStructIdent->Tempo = ((tTempoInTickCan)cTempoEnTickCanAttenteReemission);
                        pStructIdent->EtatHandle = cDATCnlMessageAttenteReemission;
                        #else
                        InitialiseMessage(HandleUS,cTrue);
                        #endif
                        #if defined(MSDT_FRAME_RETRANSMISSION)
                        }
                        #endif
                    }
                    break;

                    case cDATCnlMessageAttenteCF : //waiting for Consecutive Frame reception
                    {
                        InitialiseMessage(HandleUS,cFalse);

                        #ifdef DAT_CTL2_MSDT_LAYER_ON
                        DATCtlN_WrongCFDataInd(HandleUS);
                        #endif
                    }
                    break;

                    case cDATCnlMessageAttenteST : //Message transmission : waiting STmin before next CF transmission
                    {
                        EmettreCF(HandleUS);
                    }
                    break;

                    #ifdef WAIT

                    case cDATCnlMessageAttenteProchainWait : //Message transmission : waiting next FC Wait reception
                    {
                        #ifdef REPRISE_ERREUR
                        pStructIdent->Tempo = ((tTempoInTickCan)cTempoEnTickCanAttenteReemission);
                        pStructIdent->EtatHandle = cDATCnlMessageAttenteReemission;
                        #else
                        InitialiseMessage(HandleUS, cTrue);
                        #endif
                    }
                    break;

                    case cDATCnlMessageAttenteEnvoiWait :   //Message reception: wiating for next FC wait transmission
                    {
                        EmettreFC(HandleUS);
                    }
                    break;
                    #endif
                    #if defined(REPRISE_ERREUR) || defined(MSDT_FRAME_RETRANSMISSION) 
                    case cDATCnlMessageAttenteReemission: //Waiting for next re transmission attempt
                    {
                        #ifdef MSDT_FRAME_RETRANSMISSION
                        // CCOV: amanevm: Following check is always TRUE because
                        // state cDATCnlMessageAttenteReemission is only available for MSDT transmit messages
                        if (mIsMSDTTxHandle(HandleUS) != cFalse)
                        {
                            pStructIdent->EtatHandle = pStructIdent->PreviousEtatHandle;
                            // retransmit without loading new data
                            DATCdlD_UUDataReq(HandleUS);
                        }
                        else
                        {
                        #endif
                        #ifdef REPRISE_ERREUR
                        if (ucCptRepriseSurErreur[HandleUS]!=0)
                        {
                            ucCptRepriseSurErreur[HandleUS]--;
                            DATCnlN_USDataReq(HandleUS);
                        }
                        else
                        {   //maximum number of re transmission is reached
                            ucCptRepriseSurErreur[HandleUS] = cDATCnlMaxRepriseSurErreur;
                            InitialiseMessage(HandleUS, cTrue);
                        }
                        #endif
                        #ifdef MSDT_FRAME_RETRANSMISSION
                        }
                        #endif
                    }
                    break;
                    #endif

                    // CCOV: amanevm: all checks are made in case statements
                    default:
                        mLIBassert(cTrue); //For QAC
                        break;
                }
            }
        }
    }
}
#endif

//==============================================================================
// DESCRIPTION : Initialization of the whole component (all message channel)
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
#ifdef DAT_CNL_LAYER_ON
void DATCnlInit(void)
{
    tDATCnlN_USHandle HandleUS;
    tDATCnl_Ident* pStructIdent;

    for (HandleUS=0; HandleUS < cDATCnl_NbUS; HandleUS++)
    {
        pStructIdent = &(DATCnlTable[HandleUS]);

        InitialiseMessage(HandleUS, cFalse);

        pStructIdent->NbTrameAvantFC       = ((U16)0UL);
        pStructIdent->NbTramesConsecutives = ((U16)0UL);
        pStructIdent->Taille               = ((U16)0UL);
        pStructIdent->TailleMessage        = ((U16)0UL);
        pStructIdent->Tempo                = ((tTempoInTickCan)0UL);
        pStructIdent->TempsDeSeparation    = ((U8)0UL);

        #ifdef WAIT
        pStructIdent->ucNbWaitRestant      = ((U8)0UL);
        #endif

        #ifdef REPRISE_ERREUR
        ucCptRepriseSurErreur[HandleUS] = cDATCnlMaxRepriseSurErreur;
        #endif

        ReceptionTrameSurHandle[HandleUS]  = cHandleInvalide;
    }
}
#endif

//==============================================================================
// DESCRIPTION : Start the component: here nothing to do
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
#ifdef DAT_CNL_LAYER_ON
void DATCnl_N_Init(void)
{

}
#endif

//==============================================================================
// DESCRIPTION : Stop the component : Initialization of the whole component
//               (all message channel)
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
#ifdef DAT_CNL_LAYER_ON
void DATCnl_N_Stop(void)
{
    tDATCnlN_USHandle HandleUS;
    tDATCnl_Ident* pStructIdent;

    //If reception is in progress no initialization is performed
    for (HandleUS=0; HandleUS < cDATCnl_NbUS; HandleUS++)
    {
        pStructIdent = &(DATCnlTable[HandleUS]);
        if (pStructIdent->Mode == cModeEmission)
        {
            pStructIdent->EtatHandle = cDATCnlMessageLibre ;
            pStructIdent->Mode       = cModeZero;
        }
        pStructIdent->Tempo = ((tTempoInTickCan)0UL);
    }
}
#endif

//==============================================================================
// DESCRIPTION : Put the message channel in wait state, if any First Frame is received 
// or during a message reception the next FC sendign will have its Flow Status equal to "Wait"
//
// PARAMETERS (Type,Name,Min,Max) :   tDATCnlN_USHandle : message handle
//
// RETURN VALUE :   U8 : number of wait remaining
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
#ifdef DAT_CNL_LAYER_ON
#ifdef WAIT
U8 DATCnlN_ucRequeteWait(tDATCnlN_USHandle TrameRxHandle )
{
    tDATCnl_Ident* pStructIdent;

    mLIBassert( TrameRxHandle < cDATCnl_NbUS );

    #ifdef PARAM_DIFF_ASDT
    if(TrameRxHandle>=cDATCnl_NbAS)
    {
        mLIBassert( cDATCnlMaxNbWait != ((U8)0UL) );
    }
    else
    {
        mLIBassert( cDATCnlMaxNbWaitASDT != ((U8)0UL) );
    }
    #endif

    pStructIdent = &(DATCnlTable[TrameRxHandle]);
    pStructIdent->ucNbWaitRestant |= cDATMaskDemandeDeWait;

    return ((U8)(pStructIdent->ucNbWaitRestant & cDATMaskComplementNbWait));
}
#endif
#endif

//==============================================================================
// DESCRIPTION : return the number of remaining wait for a channel message
//
// PARAMETERS (Type,Name,Min,Max) : tDATCnlN_USHandle : message handle
//
// RETURN VALUE :   U8 : number of remaining wait for a channel message
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
#ifdef DAT_CNL_LAYER_ON
#ifdef WAIT
U8 DATCnlN_ucWaitRestant(tDATCnlN_USHandle TrameRxHandle )
{
    tDATCnl_Ident* pStructIdent;

    mLIBassert( TrameRxHandle < cDATCnl_NbUS );

    pStructIdent = &(DATCnlTable[TrameRxHandle]);

    return ((U8)(pStructIdent->ucNbWaitRestant & cDATMaskComplementNbWait));
}
#endif
#endif

//==============================================================================
// DESCRIPTION : Stop the Wait transmission, FS= Clear To Send will be send
//               in the next Flow Contol frame transmission
//
// PARAMETERS (Type,Name,Min,Max) :   tDATCnlN_USHandle : message handle
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
#ifdef DAT_CNL_LAYER_ON
#ifdef WAIT
void DATCnlN_ucRequeteCTS(tDATCnlN_USHandle TrameRxHandle )
{

    tDATCnl_Ident* pStructIdent;

    mLIBassert( TrameRxHandle < cDATCnl_NbUS );

    pStructIdent = &(DATCnlTable[TrameRxHandle]);

    pStructIdent->ucNbWaitRestant = (U8)(pStructIdent->ucNbWaitRestant & (cDATMaskComplementNbWait));

}
#endif
#endif

#ifdef DAT_CNL_LAYER_ON
#ifdef DAT_CTL2_MSDT_LAYER_ON
void DATCnlN_InitialiseMessage(tDATCnlN_USHandle HandleUS)
{
    InitialiseMessage(HandleUS, cFalse);
}
#endif
#endif
