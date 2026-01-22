

#ifndef I_DAT_CNL_H
#define I_DAT_CNL_H

//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//
// #include <system_file_name.h>
// #include "project_file_name.h"
//------------------------------------------------------------------------------

#include "ARCH_CFG.h"

#ifdef cHeadIncludeType_Directly
#include "DAT_CDL.h"
#include "DAT_CNLp.h"
#else
#include ".\..\DAT_CDL\DAT_CDL.h"
#include ".\..\..\..\SCC2Gen\GEN\DAT_CNLp.h"
#endif

//-------------------------------------------------------------------------
//Consistency test on the compilation option choice
//-------------------------------------------------------------------------

#ifdef REPRISE_ERREUR
#error'if the number of retry is equal to 0 you must not use this option'
#error'this functionnality is not integrated, you must not use it, if need ask for the technology group support'
#endif

#ifdef PARAM_DIFF_ASDT
  #ifndef LAYER_CTL_ON
    #error "do not define PARAM_DIFF_ASDT if LAYER_CTL_ON is not defined"
  #endif
#endif

#ifdef DISCONNECTION_AUTHORIZED
  #ifndef LAYER_CTL_ON
    #error "do not define DISCONNECTION_AUTHORIZED if LAYER_CTL_ON is not defined"
  #endif
#endif


#ifdef EMISSION_OVERFLOW_AUTHORIZED
  #ifndef DAT_CNL_OVERFLOW
    #error "do not define EMISSION_OVERFLOW_AUTHORIZED if DAT_CNL_OVERFLOW is not defined"
  #endif
#endif

//------------------------------------------------------------------------------
// Constant data
//
// #define cu16LAYCmpConstantName   ((U16) ConstantValueUL)
//------------------------------------------------------------------------------

//If SF_DL = 0 Single Frame are not treated
#define cTailleMinMessageSingleFrame ((U8)0UL) //Minimum value for SF_DL Single Frame parameter

#define cTailleMaxMessageSingleFrame ((U8)7UL) //Maximum value for SF_DL Single Frame parameter
//Cm053883:FF_DL=7 is only available in extended or mexed addressing. Now the addressing type is normal.
//so the corresponding valid FF_DL is 8-FFF.
#define cTailleMinMessageFirstFrame  ((U8)8UL) //Minimum value for FF_DL of First Frame parameter

//Message channel status
#define cModeZero      ((U8)0x01UL)
#define cModeEmission  ((U8)0x02UL)
#define cModeReception ((U8)0x04UL)
#define cDATCnlMessageTermineEtSegmentationEnCours ((U8)0x08UL)


#define cDATCnlSTminMaxInTickCan mCNLConvertInTickCanRoundUpValue(cDATCnlSTminMax)

// definition of ucNbWaitRestant (member of structure structure tDATCnl_Ident)
//
// | b7   b6 b5 b4 b3 b2 b1 b0 |
//    ^   ^^^^^^^^^^^^^^^^^^^^
//    |            |__ counter of remaining wait
//    |
//    |__ Flag indicator of wait request
//
#define cDATMaskDemandeDeWait     ((U8) 0x80UL)
#define cDATMaskComplementNbWait  ((U8) 0x7FUL)
#define cPositionDemandeWaitEnBit ((U8) 7UL)

// Definition of EtatMessage for the network exchange
#define cDATCnlMessageAttenteFirstFC        ((U16)0x0001UL) // Waiting for first Flow Control reception
#define cDATCnlMessageAttenteFC             ((U16)0x0002UL) // Waiting for other Flow Control reception
#define cDATCnlMessageAttenteCF             ((U16)0x0004UL) // Waiting for Consecutive Frame reception
#define cDATCnlMessageAttenteST             ((U16)0x0008UL) // Waiting for Separation Time delay
#define cDATCnlMessageAttenteProchainWait   ((U16)0x0010UL) // Waiting for new Flow Control Wait
#define cDATCnlMessageAttenteReemission     ((U16)0x0020UL) // Waiting for re transmission
#define cDATCnlMessageLibre                 ((U16)0x0040UL) // No activity on this handle
#define cDATCnlMessageConfirmation          ((U16)0x0080UL) // Confirmation of message transmission
#define cDATCnlMessageAttenteConfFF         ((U16)0x0100UL) // Waiting for First Frame transmission confirmation
#define cDATCnlMessageAttenteConfFC         ((U16)0x0200UL) // Waiting for Flow Control transmission confirmation
#define cDATCnlMessageAttenteConfCF         ((U16)0x0400UL) // Waiting for Consecutive Frame transmission confirmation
#define cDATCnlMessageAttenteConfFin        ((U16)0x0800UL) // Last transmission of frame from a message
#define cDATCnlMessageAttenteConfFCWait     ((U16)0x1000UL) // Waiting for Flow Control Wait transmission confirmation
#define cDATCnlMessageAttenteEnvoiWait      ((U16)0x2000UL) // Waiting for Flow Control Wait transmission
#define cDATCnlMessageAttenteConfFCOverflow ((U16)0x4000UL) // Waiting for Flow Control Overflow transmission confirmation

//------------------------------------------------------------------------------
// Exported Macros
//
// #define LAYCmpMacroName(...)   (MacroDefinition)
//------------------------------------------------------------------------------

//pointer of the buffer of the message
#define mDATCnlBufferHandle(MessageHandle)(DATCnlTableROM[MessageHandle].pBuffer)

//Length of the received message (in overflow case this is the length of the data treatable by the application)
#define mDATCnlLngHandle(MessageHandle)(DATCnlTable[MessageHandle].TailleMessage)

//Full length of the received message (in overflow case this is the length of the message sent by the sender)
#define mDATCnlLngTotaleHandle(MessageHandle)(DATCnlTable[MessageHandle].Taille)

//message buffer length
#define mDATCnlLengthBufferUS(MessageHandle)(cDATCnlN_USTaille##MessageHandle)

//to detect an overflow case (usefull for diagnostic request):
// if mDATCnlLngTotaleHandle(MessageHandle)>mDATCnlLngHandle(MessageHandle)
// OR: if mDATCnlLngHandle(MessageHandle)>mTailleBufferUS(MessageHandle)

//redirection of DAT_Cnl service to DAT_Cdl services for UUDT frame
#define DATCnlN_UUDataReq(TrameHandle)(DATCdlD_UUDataReq(TrameHandle))

//------------------------------------------------------------------------------
// Exported type
//
// typedef Expression tLAYCmpTypeName;
//------------------------------------------------------------------------------

typedef U8 tDATCnlN_USHandle;

//typedef U8 tDATCdlD_UURxHandle;//add by zjb
//typedef U8 tDATCdlD_UUTxHandle;//add by zjb

//Type of the temporization converted into Tick CAN,
typedef U16 tTempoInTickCan;
//Warning: the tick counter are on 16 bit to take into account the case Tick CAN = 1 ms and STmin = 255 ->256 Tick CAN


#ifdef cDATCnl_NbUSNonType
    #if cDATCnl_NbUSNonType > 0
        #define DAT_CNL_LAYER_ON
    #else
        #define DAT_CNL_LAYER_OFF

        #if cDATCnl_NbASNonType > 0
        #error 'ASDT frames must be USDT defined'
        #endif

        #if cDATCnl_NbMSNonType > 0
        #error 'MSDT frames must be USDT defined'
        #endif
    #endif
#endif

typedef struct
{
    U8* pBufferSuivant;      //position where the next frame will be copy
    U16 Taille;              //Length of the received message
    U16 TailleMessage;       //Length of the data useable for the application (Tx or Rx)
    U16 OctetsDejaCopies;    //Number of copied byte
    U16 NbTramesConsecutives;//Number of CF frame to transmit between FC reception
    U16 NbTrameAvantFC;      //Number of frame CF to receive before FC transmission
    U16 TempsDeSeparation;   //StMin time in tick CAN
    U16 EtatHandle;           //Message state
    tTempoInTickCan Tempo;       //Temporization variable for segmentation management
    U8  Mode;                //Channel message state
    U8 NumeroTrame;          //Segment number parameter
    #ifdef WAIT
    U8 ucNbWaitRestant;     //Number of remaining FC Wait and Wait flag request
    #endif
    #ifdef MSDT_FRAME_RETRANSMISSION
    U8 ucRetransmitAttempt;
    U16 PreviousEtatHandle;           //Previous message state
    #endif
} tDATCnl_Ident;


//------------------------------------------------------------------------------
// Exported data
//
// extern  tType   u8LAYCmpVariableName;
// extern  tType*  ps32LAYCmpVariableName; 
//------------------------------------------------------------------------------

#ifdef DAT_CNL_LAYER_ON
// RAM table
extern tDATCnl_Ident      DATCnlTable [cDATCnl_NbUS];
extern tDATCnlBuffersUS   DATCnlBuffersUS;

// ROM table
extern const tDATCnl_IdentROM DATCnlTableROM [cDATCnl_NbUS];

//Local frame memorization ROM table
extern const tDATCnl_IdentByteMemoryROM DATCnlByteMemoryTableROM [cDATCnl_NbUS];
#endif

//------------------------------------------------------------------------------
// Constant exported data
//
// extern const tType  s8LAYCmpVariableName;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Exported functions
//
// extern tReturnType LAYCmpFunctionName(tTypeArgument1 ArgumentName1, ... );
//------------------------------------------------------------------------------

#ifdef DAT_CNL_LAYER_ON

extern void DATCnlN_USDataReq(tDATCnlN_USHandle MessageHandle);
  #ifdef LAYER_CTL_ON
extern void DATCnlN_USDataReqAcq(tDATCnlN_USHandle MessageHandle) ;
extern void DATCnlN_USDataReqCS(tDATCnlN_USHandle MessageHandle) ;

  #ifdef DISCONNECTION_AUTHORIZED
extern void DATCnlN_USDataReqDS(tDATCnlN_USHandle MessageHandle) ;
  #endif

  #endif

//extern void DATCnlN_UUDataReq(tDATCdlD_UUTxHandle TrameHandle); -> macro

extern void DATCnl_N_Init(void);
extern void DATCnl_N_Stop(void);

extern void DATCnlInit(void);
extern void DATCnlTick(void);

  #ifdef WAIT
extern U8 DATCnlN_ucRequeteWait(tDATCnlN_USHandle TrameRxHandle );
extern void   DATCnlN_ucRequeteCTS(tDATCnlN_USHandle TrameRxHandle );
extern U8 DATCnlN_ucWaitRestant(tDATCnlN_USHandle TrameRxHandle );
  #endif

//External Callback
extern void DATCtlN_USDataInd(tDATCnlN_USHandle TRxHandle);
extern void DATCtlN_UUDataInd(tDATCdlD_UURxHandle DRxHandle);

#ifdef LAYER_CTL_ON
extern void DATCtlN_ASDataInd(tDATCnlN_USHandle TRxHandle);
#endif

extern void DATCtlN_USDataCon(tDATCnlN_USHandle NTxHandle, BOOL EmissionOK);
extern void DATCtlN_UUDataCon(tDATCdlD_UUTxHandle DTxHandle, BOOL EmissionOK);

#else

#ifdef LAYER_CTL_ON
#error 'DAT_CTL can be active only if DAT_CNL is active'
#endif

// Exported services
#define DATCnl_N_Init()
#define DATCnl_N_Stop()
#define DATCnlInit()
#define DATCnlTick()

#ifdef WAIT
#error 'Flow control Wait management can be active only if DAT_CNL is active'
#endif

// callbacks
#define DATCtlN_UUDataInd(DRxHandle) (DATCnlD_UUDataInd(DRxHandle))
#define DATCtlN_UUDataCon( DTxHandle, EmissionOK) (DATCnlD_UUDataCon( (DTxHandle), (EmissionOK)))
#endif

#endif /* I_DAT_CNL_H */
