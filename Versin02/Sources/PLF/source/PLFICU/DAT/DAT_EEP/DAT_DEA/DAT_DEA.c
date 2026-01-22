

//-------------------------------------------------------------------------
//  Identification du corps
//-------------------------------------------------------------------------
#define dat_dea  "dat_dea"

//-------------------------------------------------------------------------
//  Fichiers inclus
//
//  #include <nom_du_ficher_systeme.h>
//  #include "nom_du_ficher_utilisateur.h"
//------------------------------------------------------------------------- 

#include "DAT_DEA.h"

//-------------------------------------------------------------------------
//  Constantes locales
//
//  #define cNomConstante   ValeurDeLaConstante
//-------------------------------------------------------------------------  

//-------------------------------------------------------------------------
//  Macro locales
//
//  #define mNomMacro   (DefinitionDeLaMacro)
//-------------------------------------------------------------------------  
#define mConvAdress8ToAdr16( Adr8 ) (U16)((Adr8) >> 1U)
#define mConvNumberByteToNumberWord( NumberByte ) (tDATEepOffset)((NumberByte) >> 1U)

//-------------------------------------------------------------------------
//  Types locaux
//
//  struct  sNomStructure { ... };
//  union   uNomUnion { ... };
//  enum    eNomEnumeration { ... };
//  typedef Expression tNomType;
//-------------------------------------------------------------------------
typedef enum
{
    cProcessRequest=0U,
    cActionRequest
} tCallBackRequest;

typedef enum
{
    cWriteByAddress=0U,
    cReadByAddress
} tActionRequest;

//-------------------------------------------------------------------------
//  Variables locales
//
//  static  tType   NomVariable;
//  static  tType*  pNomVariable; 
//-------------------------------------------------------------------------

static tCallBackRequest   CallBackRequest;
static tActionRequest     ActionRequest;
static BOOL           WriteToEEPROM;
static BOOL           ProcessSupervisorIsActive;
//-------------------------------------------------------------------------
//  Donnees constantes locales
//
//  static const tType  NomVariable;
//-------------------------------------------------------------------------  

//-------------------------------------------------------------------------
//  Variables exportees
//
//  tType   COMNomVariable;          (COM: 3 lettres identifiant ce composant)
//  tType*  pCOMNomVariable;         (COM: 3 lettres identifiant ce composant)
//-------------------------------------------------------------------------

U8    DATDeaBufferU8Bit[cDATDeaMaxByte];
U16   DATDeaAddressInByte;
U8    DATDeaSizeBufferInByte;
BOOL  DATDeaWriteIsOk;
BOOL  DATDeaReadIsOk;
BOOL  DATDeaActionIsFinished;

//-------------------------------------------------------------------------
//  Donnees constantes exportees
// 
//  const tType   COMNomVariable;    (COM: 3 lettres identifiant ce composant)
//------------------------------------------------------------------------- 

//-------------------------------------------------------------------------
//  Prototypes des fonctions locales
//
//  static tTypeRetour NomFonction(tTypeArgument1 NomArgument1, ... );
//-------------------------------------------------------------------------
static BOOL AddressAndNumberOfByteIsEven(void);
static void StartAction(void);
static BOOL CheckConditionBeforeStartAction(void);


//.........................................................................
//........................... FONCTIONS LOCALES ...........................
//.........................................................................
//****************************************************************************
//   Function Name :
//     static BOOL AddressAndNumberOfByteIsEven(void)
//****************************************************************************
// This function is only used in an assert call.
// So, this function cannot be covered by the unitary test.
static BOOL AddressAndNumberOfByteIsEven(void)
{
    BOOL  Even;

    Even = (BOOL)(((DATDeaAddressInByte    & (U16)0x0001U) == 0U) &&
                  ((DATDeaSizeBufferInByte & (U8)0x01U) == 0U));

    return Even;
}

//****************************************************************************
//   Function Name :
//     static BOOL CheckConditionBeforeStartAction(void)
//****************************************************************************
static BOOL CheckConditionBeforeStartAction(void)
{
    BOOL Status;

    Status = AddressAndNumberOfByteIsEven();

    if(  Status
       &&((U16)((U16)DATDeaSizeBufferInByte+DATDeaAddressInByte)<=cDATDeaSizeEeprom)
       &&(DATDeaActionIsFinished == cTrue)
       &&(DATDeaSizeBufferInByte != 0U))
    {
        // Check that the address and the number of byte are even
        // Check that the Eeprom area to access is OK
        // Check that the previous action is finished
        // Check that the Length is not null
        Status = cTrue;
    }
    else
    {
        mLIBassert(cFalse);
        Status = cFalse;
    }

    return(Status);
}

//****************************************************************************
//   Function Name :
//     static void StartAction(void)
//****************************************************************************
static void StartAction(void)
{
    CallBackRequest=cActionRequest;

    if (ActionRequest==cWriteByAddress)
    {
        // Intialize the Eeprom work Buffer
       (void)mLIBmemcpy( (U8*)DATEepBuffer, DATDeaBufferU8Bit, DATDeaSizeBufferInByte);
        DATEepAbsoluteWrite (DATEepBuffer, mConvAdress8ToAdr16(DATDeaAddressInByte),mConvNumberByteToNumberWord(DATDeaSizeBufferInByte));
    }
    else
    {
        DATEepAbsoluteRead (DATEepBuffer, mConvAdress8ToAdr16(DATDeaAddressInByte), mConvNumberByteToNumberWord(DATDeaSizeBufferInByte));
    }
}

//.........................................................................
//........................... FONCTIONS EXPORTEES .........................
//.........................................................................

//****************************************************************************
//   Function Name :
//     void DATDeaStartWriteEepromByAddress (void)
//****************************************************************************
void DATDeaStartWriteEepromByAddress (void)
{
    BOOL bCheck;

    bCheck = CheckConditionBeforeStartAction();
    if(bCheck != cFalse)
    {
        // Init of flags
        ActionRequest=cWriteByAddress;
        DATDeaActionIsFinished=cFalse;

        if (ProcessSupervisorIsActive==cFalse)
        {
            // Open the supervisor process
            CallBackRequest=cProcessRequest;
            DATEepProcessRequest (cDATEepProcessSupervisor);
        }
        else
        {
            StartAction();
        }
    }
    else
    {
        DATDeaWriteIsOk=cFalse;
    }
}


//****************************************************************************
//   Function Name :
//     void DATDeaStartReadEepromByAddress (void)
//****************************************************************************
void DATDeaStartReadEepromByAddress (void)
{
    BOOL bCheck;

    bCheck = CheckConditionBeforeStartAction();
    if (bCheck != cFalse)
    {
        // Init of flags
        ActionRequest=cReadByAddress;
        DATDeaActionIsFinished=cFalse;

        if (ProcessSupervisorIsActive==cFalse)
        {
            CallBackRequest=cProcessRequest;
            // Open the supervisor process
            DATEepProcessRequest (cDATEepProcessSupervisor);
        }
        else
        {
            StartAction();
        }
    }
    else
    {
        DATDeaReadIsOk=cFalse;
    }
}

//****************************************************************************
//   Function Name :
//     void DATDeaCallBackEep (tDATEepProcessHandle ProcessHandle, BOOL StatusOk)
//****************************************************************************
void DATDeaCallBackEep(tDATEepProcessHandle ProcessHandle, BOOL StatusOk)
{
    switch (CallBackRequest)
    {
    case cProcessRequest :
        // End of the request opening
        ProcessSupervisorIsActive=cTrue;
        StartAction();
        break;

    case cActionRequest :
        // End of the action (writing or reading)
        DATDeaActionIsFinished=cTrue;

        if (ActionRequest==cWriteByAddress)
        {
            if (StatusOk==cFalse)
            {
                DATDeaWriteIsOk=cFalse;
            }
            else
            {
                DATDeaWriteIsOk=cTrue;
            }
            WriteToEEPROM=cTrue;
            // The supervisor process is never closed after a writing
        }
        else
        {
            DATDeaReadIsOk = cTrue;

            // Copy the result of reading to DATDeaBufferU8Bit
            (void)mLIBmemcpy(DATDeaBufferU8Bit, (U8*)DATEepBuffer, DATDeaSizeBufferInByte);

            if (WriteToEEPROM==cFalse)
            {
                // Close the supervisor process if no writing have been done before
                DATEepTerminateProcess();
                ProcessSupervisorIsActive=cFalse;
            }
            else
            {
                // The supervisor process is never closed after a writing
            }
        }
        break;

    //CCOV: amanevm: CallBackRequest takes only valus handled in cases above
    //QACJ 2018: amanevm: CallBackRequest takes only valus handled in cases above
    default :
        // impossible
        mLIBassert( cFalse );
        break;
    }
}

//****************************************************************************
//   Function Name :
//    void DATDeaInitialize (void)
//****************************************************************************
void DATDeaInitialize (void)
{
    mLIBassert( sizeof(DATDeaBufferU8Bit) <= sizeof(DATEepBuffer) );

    DATDeaWriteIsOk=cTrue;
    DATDeaReadIsOk=cTrue;
    DATDeaActionIsFinished=cTrue;
    WriteToEEPROM=cFalse;
    ProcessSupervisorIsActive=cFalse;
}
