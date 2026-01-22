
#define Dat_obk "Dat_obk"

//--------------------------------------------------------------------------
//-------  Inclusion de fichiers (systeme et librairies)  ------------------
//--------------------------------------------------------------------------

#include "DAT_OBK.h"




//--------------------------------------------------------------------------
//-------  Inclusion des definitions des autres composants utiles  ---------
//--------------------------------------------------------------------------
// #include <AUTRE_COMPOSANT.h>


//--------------------------------------------------------------------------
//-------  Declaration des constantes locales ?ce composant  --------------
//--------------------------------------------------------------------------
// #define cNomConstante   ValeurDeLaConstante

///////////////////////////////////////
// Bank flags : Mask definitions
///////////////////////////////////////

// ModeFlag ? WriteMode : ReadMode
#define   cFlag_ModeFlag          ((U8) 0x01U)

// ErrorFlag ? WritingError : NoError
#define   cFlag_ErrorFlag         ((U8) 0x02U)


//--------------------------------------------------------------------------
//-------  Declaration des macros locales ?ce composant  ------------------
//--------------------------------------------------------------------------
// #define mNomMacro   (DefinitionDeLaMacro)

///////////////////////////////////////
// Handle conversions (between DAT_OBK and DAT_EEP)
///////////////////////////////////////

#define mConv_DatObkHandle_To_DatEepHandle(HandleObk)        \
            ((tDATEepProcessHandle)     ((HandleObk) + cDATObkFirstProcessHandle))

#define mConv_DatEepHandle_To_DatObkHandle(HandleEep)        \
            ((tDATObkOdometerBankHandle)  ((HandleEep) - cDATObkFirstProcessHandle))


///////////////////////////////////////
// Bank flag acces
///////////////////////////////////////

// Macro for "Mode" acces
#define   mBankFlag_SetReadMode(BANK_HANDLE)                   \
            { OdometerBankFlags[(BANK_HANDLE)] &= ~cFlag_ModeFlag; } /* Reset    "cFlag_ModeFlag"  */

#define   mBankFlag_SetWriteMode(BANK_HANDLE)                  \
            { OdometerBankFlags[(BANK_HANDLE)] |=  cFlag_ModeFlag; }  /* Set      "cFlag_ModeFlag"  */

// Macro for "Mode" tests
#define   mBankFlag_IsReadMode(BANK_HANDLE)                    \
            ( mBankFlag_IsWriteMode(BANK_HANDLE) == cFalse)       /* !"cFlag_ModeFlag" ?        */  

#define   mBankFlag_IsWriteMode(BANK_HANDLE)                   \
            ( (OdometerBankFlags[(BANK_HANDLE)] & cFlag_ModeFlag)!=0 )    /* "cFlag_ModeFlag" ?         */

// Macro for "Error" acces
#define   mBankFlag_SetNoError(BANK_HANDLE)                    \
            { OdometerBankFlags[(BANK_HANDLE)] &= ~cFlag_ErrorFlag; }  /* Reset  "cFlag_ErrorFlag" */

#define   mBankFlag_SetWritingError(BANK_HANDLE)               \
            { OdometerBankFlags[(BANK_HANDLE)] |=  cFlag_ErrorFlag; }  /* Set    "cFlag_ErrorFlag" */

// Macro for "Error" test
#define   mBankFlag_IsWritingError(BANK_HANDLE)                  \
            ( (OdometerBankFlags[(BANK_HANDLE)] & cFlag_ErrorFlag)!=0 )     /* "cFlag_ErrorFlag" ?      */


//--------------------------------------------------------------------------
//-------  Definition des types locaux ?ce composant  ---------------------
//--------------------------------------------------------------------------
// typedef ...   tNomType;


//--------------------------------------------------------------------------
//-------  Variables locales ?ce composant  -------------------------------
//--------------------------------------------------------------------------
// static  tType   NomVariable;
// static  tType*  pNomVariable;

// StateChart State's ...
typedef enum
{
    cChartState_Wait,
    cChartState_Writing,
    cChartState_Reading,
    cChartState_CompareAfterReading
} S8tState;

static U8 OdometerBankInUse[cNbObk];
static U8 OdometerBankFlags[cNbObk];
static U8 OdometerBankOk[cNbObk];
static U8 OdometerBankNumberOfBrokenBank[cNbObk];
static S8tState ChartState;
static U8 CurrentNumberOfReadingRetry;
static tDATEepOffset SizeObkChkInUse;
static BOOL RamBankInitialized;


//--------------------------------------------------------------------------
//-------  Donnees Constantes locales ?ce composant  ----------------------
//--------------------------------------------------------------------------
// static const  tType   NomVariable;


//--------------------------------------------------------------------------
//-------  Variables exportees par ce composant  ---------------------------
//--------------------------------------------------------------------------
// tType   ComNomVariable;       (Com: 3 lettres identifiant ce composant)
// tType*  pComNomVariable;
#ifndef COMPILATION_NATIVE
//#pragma memory = dataseg(ERAM)
#endif
tDATObkMirrors DATObkMirrors;
#ifndef COMPILATION_NATIVE
//#pragma memory = default
#endif

// Spécifie le nombre de banques ?écrire
// Specify the number of banks to write
U8 DATObkNbBanksToWrite[cNbObk];


//--------------------------------------------------------------------------
//-------  Donnees Constantes exportees par ce composant  ------------------
//--------------------------------------------------------------------------
// const  tType   ComNomVariable;  (Com: 3 lettres identifiant ce composant)
const tDATObkTableBankRom DATObkTableBankRom[cNbObk] =
    {
        mSERObkInitTableBankROM()
    };


//--------------------------------------------------------------------------
//-------  Fonctions locales (par ordre alphabetique)  ---------------------
//--------------------------------------------------------------------------


//--------------------------------------------------------------------------
//
// Description de la procedure ou fonction:
// ----------------------------------------
//
// Type et signification des parametres:
// -------------------------------------
//
// Type et signification du resultat si c'est une fonction:
// --------------------------------------------------------
//
// Description de l'algorithme (pseudo code) en commentaire:
// ---------------------------------------------------------
//
//--------------------------------------------------------------------------
U16 ObkChecksumCalculation ( tDATEepOffset BlockSize )
{
    U16 Checksum;

    // used in debug mode to check param
    // permet de faire en mode debug des verif des param
    // si la condition n'est pas bonne un message d'erreur est genere
    mLIBassert( BlockSize > 1 );

    Checksum = 0U;
    BlockSize --;
    // boucle de calcul du checksum
    while ( BlockSize > 0U )
    {
        Checksum += DATEepBuffer [ BlockSize ];
        BlockSize --;
    }
    // inverse la valeur du checksum
    Checksum = ~Checksum;

    return Checksum;
}


//--------------------------------------------------------------------------
//-------  Fonctions exportees (par ordre alphabetique)  -------------------
//--------------------------------------------------------------------------


//--------------------------------------------------------------------------
//
// Description de la procedure ou fonction:
// ----------------------------------------
//
// Type et signification des parametres:
// -------------------------------------
//
// Type et signification du resultat si c'est une fonction:
// --------------------------------------------------------
//
// Description de l'algorithme (pseudo code) en commentaire:
// ---------------------------------------------------------
//
//--------------------------------------------------------------------------
void DATObkInit(void)
{
    // StateChart Reset (very important)
    ChartState = cChartState_Wait;

    // Current reading retry reset (not important)
    CurrentNumberOfReadingRetry = 0U;

    // Odometer Bank flags reset (not important)
    (void)mLIBmemset(OdometerBankInUse, 0x00, sizeof(OdometerBankInUse));
    (void)mLIBmemset(OdometerBankFlags, 0x00, sizeof(OdometerBankFlags));
    (void)mLIBmemset(OdometerBankNumberOfBrokenBank, 0x00, sizeof(OdometerBankNumberOfBrokenBank));


    // Par défaut, on écrit dans une seule banque (tournante)
    // We write on one bank by default
    (void)mLIBmemset(DATObkNbBanksToWrite, cOneBank, sizeof(DATObkNbBanksToWrite));
}


//--------------------------------------------------------------------------
//
// Description de la procedure ou fonction:
// ----------------------------------------
//
// Type et signification des parametres:
// -------------------------------------
//
// Type et signification du resultat si c'est une fonction:
// --------------------------------------------------------
//
// Description de l'algorithme (pseudo code) en commentaire:
// ---------------------------------------------------------
//
//--------------------------------------------------------------------------
void DATObkStartUpdate( tDATObkOdometerBankHandle HandleObk )
{
    // Used in debug mode to check param  
    mLIBassert( HandleObk < cNbObk );

    // If a write request occurs during a read operation,
    // this request is ignored.
    // This test is a robustness test. The else branch can'not be
    // covered in unitary test.
    if(  (DATObkIsBankProcessing(HandleObk) == cFalse) ||
         (mBankFlag_IsReadMode  (HandleObk) == cFalse)    )
    {
        // Starting Writing process ...
        mBankFlag_SetWriteMode(HandleObk);
        DATEepProcessRequest(mConv_DatObkHandle_To_DatEepHandle(HandleObk));
    }
    else
    {
        // The EEPROM users can'not request to write during the reading.
        mLIBassert( cFalse );
    }
}

//--------------------------------------------------------------------------
//
// Description de la procedure ou fonction:
// ----------------------------------------
//
// Type et signification des parametres:
// -------------------------------------
//
// Type et signification du resultat si c'est une fonction:
// --------------------------------------------------------
//
// Description de l'algorithme (pseudo code) en commentaire:
// ---------------------------------------------------------
//
//--------------------------------------------------------------------------
BOOL DATObkIsWriteOk( tDATObkOdometerBankHandle HandleObk )
{
    BOOL IsWriteOk = cFalse;

    // Used in debug mode to check param  //
    mLIBassert( HandleObk < cNbObk );

    // Check error flag ...
    if (mBankFlag_IsWritingError(HandleObk) == cFalse)
    {
        // ok
        IsWriteOk = cTrue;
    }

    // Return
    return IsWriteOk;
}

//--------------------------------------------------------------------------
//
// Description de la procedure ou fonction:
// ----------------------------------------
//
// Type et signification des parametres:
// -------------------------------------
//
// Type et signification du resultat si c'est une fonction:
// --------------------------------------------------------
//
// Description de l'algorithme (pseudo code) en commentaire:
// ---------------------------------------------------------
//
//--------------------------------------------------------------------------
void DATObkStartReadingAllBanks( void )
{
    tDATObkOdometerBankHandle HandleObk;

    // Reading request for all banks ...
    for (HandleObk = 0U; HandleObk < cNbObk; HandleObk++)
    {
        DATObkStartReading (HandleObk);
    }
}

//--------------------------------------------------------------------------
//
// Description de la procedure ou fonction:
// ----------------------------------------
//
// Type et signification des parametres:
// -------------------------------------
//
// Type et signification du resultat si c'est une fonction:
// --------------------------------------------------------
//
// Description de l'algorithme (pseudo code) en commentaire:
// ---------------------------------------------------------
//
//--------------------------------------------------------------------------
void DATObkStartReading( tDATObkOdometerBankHandle HandleObk )
{
    // Used in debug mode to check param  //
    mLIBassert( HandleObk < cNbObk );

    // This assert check that this single-bank is'nt processing yet //
    mLIBassert(DATObkIsBankProcessing(HandleObk) == cFalse);

    // Starting Reading process ...
    mBankFlag_SetReadMode(HandleObk);
    DATEepProcessRequest(mConv_DatObkHandle_To_DatEepHandle(HandleObk));
}

//--------------------------------------------------------------------------
//
// Description de la procedure ou fonction:
// ----------------------------------------
//
// Type et signification des parametres:
// -------------------------------------
//
// Type et signification du resultat si c'est une fonction:
// --------------------------------------------------------
//
// Description de l'algorithme (pseudo code) en commentaire:
// ---------------------------------------------------------
//
//--------------------------------------------------------------------------
BOOL DATObkIsBankProcessing( tDATObkOdometerBankHandle HandleObk )
{
    /// Used in debug mode to check param  //
    mLIBassert( HandleObk < cNbObk );

    // Return ("HandleObk" Bank is processing ?)
    return DATEepIsActivate (mConv_DatObkHandle_To_DatEepHandle(HandleObk));
}

//--------------------------------------------------------------------------
//
// Description de la procedure ou fonction:
// ----------------------------------------
//
// Type et signification des parametres:
// -------------------------------------
//
// Type et signification du resultat si c'est une fonction:
// --------------------------------------------------------
//
// Description de l'algorithme (pseudo code) en commentaire:
// ---------------------------------------------------------
//
//--------------------------------------------------------------------------
BOOL DATObkIsProcessing( void )
{
    tDATObkOdometerBankHandle HandleObk;
    BOOL IsProcessing = cFalse;

    // Check all banks ...
    for (HandleObk = 0U; HandleObk < cNbObk; HandleObk++)
    {
        if (DATObkIsBankProcessing(HandleObk) == cTrue)
        {
            // ok
            IsProcessing = cTrue;

            // Force "End of checking"
            HandleObk = cNbObk;         // <=> break; (in order to avoid a QAC warning)
        }
    }

    // Return
    return IsProcessing;
}

//--------------------------------------------------------------------------
//
// Description de la procedure ou fonction:
// ----------------------------------------
//
// Type et signification des parametres:
// -------------------------------------
//
// Type et signification du resultat si c'est une fonction:
// --------------------------------------------------------
//
// Description de l'algorithme (pseudo code) en commentaire:
// ---------------------------------------------------------
//
//--------------------------------------------------------------------------
void DATObkCallBackEep ( tDATEepProcessHandle DATEepProcessHandle, BOOL DATEepCallBackStatusIsOk )
{
    tDATObkOdometerBankHandle     HandleObk;

    U16*                      Obk_AddBlockRam;
    tDATEepOffset                 Obk_SizeBlockRam;

    // Get the current Obk Handle
    HandleObk = mConv_DatEepHandle_To_DatObkHandle(DATEepProcessHandle);

    // Used in debug mode to check param  //
    mLIBassert(HandleObk < cNbObk);

    // Get information on current Obk bank
    Obk_AddBlockRam   = DATObkTableBankRom[HandleObk].AddBlockRam;
    Obk_SizeBlockRam  = DATObkTableBankRom[HandleObk].SizeBlockRam;
    SizeObkChkInUse   = (tDATEepOffset)(DATObkTableBankRom[HandleObk].SizeBlockRam+(U8)1);

    /////////////////////////////////////
    // State Mate :)
    // (Continue treatment routine ...)
    /////////////////////////////////////
    switch (ChartState)
    {

        /////////////////////////////////////
        // Waiting for the activated process ?
        /////////////////////////////////////
    case cChartState_Wait:

        //////////////////////////
        // Performe a writing operation ?
        //////////////////////////
        if (mBankFlag_IsWriteMode(HandleObk) == cTrue)
        {
            // >>> Get ready for "Writing" <<<
            ChartState = cChartState_Writing;

            // Store data into DAT_EEP buffer
            // (keep one 16bits-word for check-sum at the buffer'top)
            (void)mLIBmemcpy ((U8 *) (DATEepBuffer + 1U),
                        (U8 *) (Obk_AddBlockRam), Obk_SizeBlockRam * sizeof(U16));

            // Compute the 16bits check-sum (of DAT_EEP)
            // and store it at the DAT_EEP buffer'top
            DATEepBuffer[0] = ObkChecksumCalculation(SizeObkChkInUse);

            // Now, let's go for writing operation by the way of DAT_EEP
            DATEepWrite (DATEepBuffer, (tDATEepOffset)(OdometerBankInUse[HandleObk]*SizeObkChkInUse), SizeObkChkInUse);
        }
        else
            //////////////////////////
            // or Performe a reading operation ?
            //////////////////////////
        {
            // >>> Get ready for "Reading" state <<<
            ChartState = cChartState_Reading;

            // Reset "current number of reading retry"
            CurrentNumberOfReadingRetry = 0U;

            // Initialize bank number
            OdometerBankInUse[HandleObk] = 0U;

            OdometerBankNumberOfBrokenBank[HandleObk] = 0U;
            RamBankInitialized = cFalse;

            // Now, let's go for reading operation by the way of DAT_EEP
            DATEepRead(DATEepBuffer, (tDATEepOffset)0U, SizeObkChkInUse);
        }

        break;


        /////////////////////////////////////
        // Waiting for the terminated writing process ?
        /////////////////////////////////////
    case cChartState_Writing:

        // Writing process is done (bye bye)
        ChartState = cChartState_Wait;

        // Check for error reporting
        if (DATEepCallBackStatusIsOk == cTrue)
        {
            // No error detected
            mBankFlag_SetNoError(HandleObk);
            // Change bank
            OdometerBankInUse[HandleObk]++;
            //if ( OdometerBankInUse[HandleObk] == (cDATObkNumberOfBankCopy-1) )
            if ( OdometerBankInUse[HandleObk] == (cDATObkNumberOfBankCopy) )
            {
                OdometerBankInUse[HandleObk] = 0U;
            }
        }
        else
        {
            // Write Error detected !
            mBankFlag_SetWritingError(HandleObk);
            DATPeeOdometerBankErrorIndication(HandleObk, cDATObkErrorWriting);
        }

        //  Teste si la donnée doit etre écrite sur une autre banque
        //  Check if we must write de value on another bank
        if (DATObkNbBanksToWrite[HandleObk] > cOneBank)
        {
            DATObkNbBanksToWrite[HandleObk]--;
            // Lancement de l'écriture sur la banque suivante
            // writing operation by the way of DAT_EEP on the next bank
            DATEepWrite (DATEepBuffer, (tDATEepOffset)(OdometerBankInUse[HandleObk]*SizeObkChkInUse), SizeObkChkInUse);
        }
        else
        {
            DATEepTerminateProcess();
        }


        break;


        /////////////////////////////////////
        // Waiting for the terminated reading process ?
        /////////////////////////////////////
    case cChartState_Reading:

        // If RAM image of the bank has not yet been initialized
        if ( RamBankInitialized == cFalse )
        {
            // Make a copy of DAT_EEP buffer into DAT_OBK current ram buffer (without the 16bits check-sum)...
            (void)mLIBmemcpy ((U8 *) (Obk_AddBlockRam),
                        (U8 *) (DATEepBuffer + 1U), Obk_SizeBlockRam * sizeof(U16));
        }

        // Check the 16bits check-sum (locate at the bank'top) ...
        if (ObkChecksumCalculation(SizeObkChkInUse) == DATEepBuffer[0U])
        {
            // If bank in DATEepBuffer greater than the one in RAM or first bank read
            if ( (RamBankInitialized==cFalse) || (DATPeeOdometerBankIsGreater(HandleObk)==cTrue) )
            {
                // Make a copy of DAT_EEP buffer into DAT_OBK current ram buffer (without the 16bits check-sum)...
            	(void)mLIBmemcpy ((U8 *) (Obk_AddBlockRam),
                            (U8 *) (DATEepBuffer + 1U), Obk_SizeBlockRam * sizeof(U16));
                // RAM image initialized
                RamBankInitialized = cTrue;
                // Number of the good Eeprom bank
                OdometerBankOk[HandleObk] = OdometerBankInUse[HandleObk];
            }

            // If current bank is the last one
            if ( OdometerBankInUse[HandleObk] == (cDATObkNumberOfBankCopy-1) )
            {
                if ( OdometerBankOk[HandleObk] == (cDATObkNumberOfBankCopy-1) )
                {
                    OdometerBankInUse[HandleObk] = 0U;
                }
                else
                {
                    OdometerBankInUse[HandleObk] = OdometerBankOk[HandleObk] + 1U;
                }
                // The Reading process is done (bye bye)
                ChartState = cChartState_Wait;
                DATEepTerminateProcess();
            }
            else
            {
                // Read next bank
                OdometerBankInUse[HandleObk]++;
                DATEepRead(DATEepBuffer, (tDATEepOffset)(OdometerBankInUse[HandleObk]*SizeObkChkInUse), SizeObkChkInUse);
            }
        }
        else  // Error detected, start "Compare" process
        {
            // >>> Get ready for "Compare" state <<<
            ChartState = cChartState_CompareAfterReading;

            // Now, let's go for compare operation by the way of DAT_EEP
            DATEepCompare(DATEepBuffer, (tDATEepOffset)(OdometerBankInUse[HandleObk]*SizeObkChkInUse), SizeObkChkInUse);
        }

        break;


        /////////////////////////////////////
        // Waiting for the terminated "Compare After Reading" process ?
        /////////////////////////////////////
    case cChartState_CompareAfterReading:

        // Check compare error status (Compare Ok ?)
        if (DATEepCallBackStatusIsOk == cTrue)
        {
            // The bank is broken
            OdometerBankNumberOfBrokenBank[HandleObk] ++;

            // If current bank is the last one
            if ( OdometerBankInUse[HandleObk] == (cDATObkNumberOfBankCopy-1) )
            {
                if ( (RamBankInitialized==cFalse) || (OdometerBankOk[HandleObk]==(cDATObkNumberOfBankCopy-1)) )
                {
                    OdometerBankInUse[HandleObk] = 0U;
                }
                else
                {
                    OdometerBankInUse[HandleObk] = OdometerBankOk[HandleObk] + 1U;
                }
                // The Reading process is done (bye bye)
                ChartState = cChartState_Wait;
                DATEepTerminateProcess();

                if (OdometerBankNumberOfBrokenBank[HandleObk] == cDATObkNumberOfBankCopy )
                {
                    // Compare Ok => all banks are broken (this bank must be rebuild par DAT_PEE)
                    DATPeeRebuildOdometerBank(HandleObk);
                }
            }
            else
            {
                // >>> Get ready for "Reading" state <<<
                ChartState = cChartState_Reading;
                // Reset "current number of reading retry"
                CurrentNumberOfReadingRetry = 0U;
                // Read next bank
                OdometerBankInUse[HandleObk]++;
                DATEepRead(DATEepBuffer, (tDATEepOffset)(OdometerBankInUse[HandleObk]*SizeObkChkInUse), SizeObkChkInUse);
            }
        }
        else  // Noisy reading => re-start reading process !
        {
            // Can we re-start reading process ?
            if (CurrentNumberOfReadingRetry < cObk_NbRetryReadDatEepMax)
            {
                // >>> Get ready for "Reading" state <<<
                ChartState = cChartState_Reading;

                // Now, let's go for retry reading operation
                CurrentNumberOfReadingRetry++;
                DATEepRead(DATEepBuffer, (tDATEepOffset)(OdometerBankInUse[HandleObk]*SizeObkChkInUse), SizeObkChkInUse);

            } else  // Max retry reached !
            {
                // Compare process is done (bye bye)
                ChartState = cChartState_Wait;
                DATEepTerminateProcess();

                // Write Error reporting (external only) and
                //   Inform the DAT_PEE compoment in order to rebuild the current bank
                DATPeeOdometerBankErrorIndication(HandleObk, cDATObkErrorReading);
                DATPeeRebuildOdometerBank(HandleObk);
            }
        }

        break;


        /////////////////////////////////////
        // Default/Error State
        /////////////////////////////////////
    default:
        mLIBassert(cFalse);    // error report
        break;
    }
}
