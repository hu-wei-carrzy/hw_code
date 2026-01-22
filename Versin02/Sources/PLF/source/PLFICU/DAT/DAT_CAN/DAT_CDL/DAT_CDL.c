
//------------------------------------------------------------------------------
// Body Identification
//------------------------------------------------------------------------------
#define dat_cdl  "dat_cdl"

//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//
// #include <system_file_name.h>
// #include "project_file_name.h"
//------------------------------------------------------------------------------//
#define cDAT_CDL_SELFINCLUDE
#include "DAT_CDL.h"
#include "RxSpontTable.h"
//#include "J1939_INCLUDE.h"

#include "CanNm.h"

//Check standard API
#ifdef M_MULTIBUS_CAN
  #ifdef LDB_MACRO_SERVICES
    #error 'Concatenation mLDBControl##Channel forbid in multibus mode'
  #endif
#endif

//------------------------------------------------------------------------------
// Local constants
//
// #define cConstantName   ((tType) ConstantValue)
//------------------------------------------------------------------------------

#define cHandleTxInvalide ((tDATCdlD_UUTxHandle)0xFFUL) // Invalid handle

//Shift value for the DAT_CDL flag
#define cDATCanFirstInit                          ((tDATCdlFlag)0UL)
#define cDATCanInit                               ((tDATCdlFlag)1UL)
#define cDATCanDemarrer                           ((tDATCdlFlag)2UL)
#define cDATCanCancelTransmissionInProgress       ((tDATCdlFlag)3UL)
#define cDATCanEmissionEnCours                    ((tDATCdlFlag)4UL)
#define cDATCanArretEnCours                       ((tDATCdlFlag)5UL)
#define cDATCanArretConfirme                      ((tDATCdlFlag)6UL)

//Flag set into Interrupt context
#define cDATCanStatusEmission                     ((tDATCdlFlag)0UL)
#ifdef ANTISATURATION
#define cDATCanAntisaturationActive               ((tDATCdlFlag)1UL)
#endif

//Max value of a counter for the Antisaturation process
#define cDATCdlDateMax  ((tDATCdlDate)0xFFUL)

//------------------------------------------------------------------------------
// Local macros
//
// #define mMacroName   (MacroDefinition)
//------------------------------------------------------------------------------

// Adress (=Identifier) of a frame
#define mAdresseCANTxHandle(TxHandle) (DATCdlTableROMTx[(TxHandle)].Id)

#ifdef M_MULTIBUS_CAN

// Id LDB for a linked CAN number (0,1...)
#define mLDBCanalCANNumCan(IdCan) (DATCdlTableParamCanalCan[(IdCan)].IdLDBCanalCan)
// Id LDB for a transmitted frame
#define mLDBCanalCANTxHandle(TxHandle) (DATCdlTableParamCanalCan[DATCdlTableROMTx[(TxHandle)].CDLCanalId].IdLDBCanalCan)
// Timeout N_As
#define mDATCdlLireTimeoutTxEnTick(TxHandle) (DATCdlTableParamCanalCan[DATCdlTableROMTx[(TxHandle)].CDLCanalId].TimeoutTxCanalCan)
#endif

#ifdef TOSDisableOSInterrupts
  #define mDisableIT()\
  TOSDisableOSInterrupts() // old version of TOS_ORD (TOS.h Rev 1.13)
#else
  #define mDisableIT()\
  TOSDisableAllInterupts() // old version of TOS_ORD (TOS.h Rev 1.12)
#endif

#ifdef TOSEnableOSInterrupts
  #define mEnableIT()\
  TOSEnableOSInterrupts() // old version of TOS_ORD (TOS.h Rev 1.13)
#else
  #define mEnableIT()\
  TOSEnableAllInterupts() // old version of TOS_ORD (TOS.h Rev 1.12)
#endif

#define  mDATCdlLireCanalCanRx(RxHandle) (DATCdlTableCanauxCanRx[(RxHandle)])
#define  mDATCdlLireCanalCanTx(TxHandle) (DATCdlTableROMTx[(TxHandle)].CDLCanalId)


#ifdef ANTISATURATION
  #ifndef M_MULTIBUS_CAN
    #define mEnableITRx()\
      LDBControl(cLDBChannelCan, cLDBCanEnableRxCallBack)
    #define mDisableITRx()\
      LDBControl(cLDBChannelCan, cLDBCanDisableRxCallBack)
  #else
    #define mEnableITRx(IdCanalCan)\
      LDBControl(DATCdlTableParamCanalCan[IdCanalCan].IdLDBCanalCan, cLDBCanEnableRxCallBack)
    #define mDisableITRx(IdCanalCan)\
      LDBControl(DATCdlTableParamCanalCan[IdCanalCan].IdLDBCanalCan, cLDBCanDisableRxCallBack)
  #endif
#endif

//Local macro for read/write the flag
#define mBitClearAllFlags(IdCan)\
  {DATCdlTableEmission[(IdCan)].DATCdlFlag = ((tDATCdlFlag)0x00UL);\
  mDisableIT();\
  DATCdlTableEmission[(IdCan)].DATCdlFlagSousIT = ((tDATCdlFlag)0x00UL);\
  mEnableIT();}

  #define mBitSetCtrlDATCanFirstInit(IdCan)     (DATCdlTableEmission[(IdCan)].DATCdlFlag |= ((tDATCdlFlag) (((tDATCdlFlag)1)<<cDATCanFirstInit)))
  #define mBitIsSetCtrlDATCanFirstInit(IdCan)   ((DATCdlTableEmission[(IdCan)].DATCdlFlag & ((tDATCdlFlag) (((tDATCdlFlag)1)<<cDATCanFirstInit))) != ((tDATCdlFlag)0x00UL))
  #define mBitClearCtrlDATCanFirstInit(IdCan)   (DATCdlTableEmission[(IdCan)].DATCdlFlag &= ((tDATCdlFlag)~(((tDATCdlFlag)1)<<cDATCanFirstInit)))
  #define mBitIsClearCtrlDATCanFirstInit(IdCan) ((DATCdlTableEmission[(IdCan)].DATCdlFlag & ((tDATCdlFlag) (((tDATCdlFlag)1)<<cDATCanFirstInit))) == ((tDATCdlFlag)0x00UL))

  #define mBitSetCtrlDATCanInit(IdCan)     (DATCdlTableEmission[(IdCan)].DATCdlFlag |= ((tDATCdlFlag) (((tDATCdlFlag)1)<<cDATCanInit)))
  #define mBitIsSetCtrlDATCanInit(IdCan)   ((DATCdlTableEmission[(IdCan)].DATCdlFlag & ((tDATCdlFlag) (((tDATCdlFlag)1)<<cDATCanInit))) != ((tDATCdlFlag)0x00UL))
  #define mBitClearCtrlDATCanInit(IdCan)   (DATCdlTableEmission[(IdCan)].DATCdlFlag &= ((tDATCdlFlag)~(((tDATCdlFlag)1)<<cDATCanInit)))
  #define mBitIsClearCtrlDATCanInit(IdCan) ((DATCdlTableEmission[(IdCan)].DATCdlFlag & ((tDATCdlFlag) (((tDATCdlFlag)1)<<cDATCanInit))) == ((tDATCdlFlag)0x00UL))

  #define mBitSetCtrlDATCanDemarrer(IdCan)     (DATCdlTableEmission[(IdCan)].DATCdlFlag |= ((tDATCdlFlag) (((tDATCdlFlag)1)<<cDATCanDemarrer)))
  #define mBitIsSetCtrlDATCanDemarrer(IdCan)   ((DATCdlTableEmission[(IdCan)].DATCdlFlag & ((tDATCdlFlag) (((tDATCdlFlag)1)<<cDATCanDemarrer))) != ((tDATCdlFlag)0x00UL))
  #define mBitClearCtrlDATCanDemarrer(IdCan)   (DATCdlTableEmission[(IdCan)].DATCdlFlag &= ((tDATCdlFlag)~(((tDATCdlFlag)1)<<cDATCanDemarrer)))
  #define mBitIsClearCtrlDATCanDemarrer(IdCan) ((DATCdlTableEmission[(IdCan)].DATCdlFlag & ((tDATCdlFlag) (((tDATCdlFlag)1)<<cDATCanDemarrer))) == ((tDATCdlFlag)0x00UL))

  #define mBitSetCtrlDATCanCancelTransmissionInProgress(IdCan)     (DATCdlTableEmission[(IdCan)].DATCdlFlag |= ((tDATCdlFlag) (((tDATCdlFlag)1)<<cDATCanCancelTransmissionInProgress)))
  #define mBitIsSetCtrlDATCanCancelTransmissionInProgress(IdCan)   ((DATCdlTableEmission[(IdCan)].DATCdlFlag & ((tDATCdlFlag) (((tDATCdlFlag)1)<<cDATCanCancelTransmissionInProgress))) != ((tDATCdlFlag)0x00UL))
  #define mBitClearCtrlDATCanCancelTransmissionInProgress(IdCan)   (DATCdlTableEmission[(IdCan)].DATCdlFlag &= ((tDATCdlFlag)~(((tDATCdlFlag)1)<<cDATCanCancelTransmissionInProgress)))
  #define mBitIsClearCtrlDATCanCancelTransmissionInProgress(IdCan) ((DATCdlTableEmission[(IdCan)].DATCdlFlag & ((tDATCdlFlag) (((tDATCdlFlag)1)<<cDATCanCancelTransmissionInProgress))) == ((tDATCdlFlag)0x00UL))

  #define mBitSetCtrlDATCanEmissionEnCours(IdCan)     (DATCdlTableEmission[(IdCan)].DATCdlFlag |= ((tDATCdlFlag) (((tDATCdlFlag)1)<<cDATCanEmissionEnCours)))
  #define mBitIsSetCtrlDATCanEmissionEnCours(IdCan)   ((DATCdlTableEmission[(IdCan)].DATCdlFlag & ((tDATCdlFlag) (((tDATCdlFlag)1)<<cDATCanEmissionEnCours))) != ((tDATCdlFlag)0x00UL))
  #define mBitClearCtrlDATCanEmissionEnCours(IdCan)   (DATCdlTableEmission[(IdCan)].DATCdlFlag &= ((tDATCdlFlag)~(((tDATCdlFlag)1)<<cDATCanEmissionEnCours)))
  #define mBitIsClearCtrlDATCanEmissionEnCours(IdCan) ((DATCdlTableEmission[(IdCan)].DATCdlFlag & ((tDATCdlFlag) (((tDATCdlFlag)1)<<cDATCanEmissionEnCours))) == ((tDATCdlFlag)0x00UL))

  #define mBitSetCtrlDATCanArretEnCours(IdCan)     (DATCdlTableEmission[(IdCan)].DATCdlFlag |= ((tDATCdlFlag) (((tDATCdlFlag)1)<<cDATCanArretEnCours)))
  #define mBitIsSetCtrlDATCanArretEnCours(IdCan)   ((DATCdlTableEmission[(IdCan)].DATCdlFlag & ((tDATCdlFlag) (((tDATCdlFlag)1)<<cDATCanArretEnCours))) != ((tDATCdlFlag)0x00UL))
  #define mBitClearCtrlDATCanArretEnCours(IdCan)   (DATCdlTableEmission[(IdCan)].DATCdlFlag &= ((tDATCdlFlag)~(((tDATCdlFlag)1)<<cDATCanArretEnCours)))
  #define mBitIsClearCtrlDATCanArretEnCours(IdCan) ((DATCdlTableEmission[(IdCan)].DATCdlFlag & ((tDATCdlFlag) (((tDATCdlFlag)1)<<cDATCanArretEnCours))) == ((tDATCdlFlag)0x00UL))

  #define mBitSetStatusDATCanArret(IdCan)     (DATCdlTableEmission[(IdCan)].DATCdlFlag |= ((tDATCdlFlag) (((tDATCdlFlag)1)<<cDATCanArretConfirme)))
  #define mBitIsSetStatusDATCanArret(IdCan)   ((DATCdlTableEmission[(IdCan)].DATCdlFlag & ((tDATCdlFlag) (((tDATCdlFlag)1)<<cDATCanArretConfirme))) != ((tDATCdlFlag)0x00UL))
  #define mBitClearStatusDATCanArret(IdCan)   (DATCdlTableEmission[(IdCan)].DATCdlFlag &= ((tDATCdlFlag)~(((tDATCdlFlag)1)<<cDATCanArretConfirme)))
  #define mBitIsClearStatusDATCanArret(IdCan) ((DATCdlTableEmission[(IdCan)].DATCdlFlag & ((tDATCdlFlag) (((tDATCdlFlag)1)<<cDATCanArretConfirme))) == ((tDATCdlFlag)0x00UL))


  #ifdef ANTISATURATION
  #define mBitSetDATCanAntisaturationActive(IdCan)     (DATCdlTableEmission[(IdCan)].DATCdlFlagSousIT |= ((tDATCdlFlag) (((tDATCdlFlag)1)<<cDATCanAntisaturationActive)))
  #define mBitIsSetDATCanAntisaturationActive(IdCan)   ((DATCdlTableEmission[(IdCan)].DATCdlFlagSousIT & ((tDATCdlFlag) (((tDATCdlFlag)1)<<cDATCanAntisaturationActive))) != ((tDATCdlFlag)0x00UL))
  #define mBitClearDATCanAntisaturationActive(IdCan)   (DATCdlTableEmission[(IdCan)].DATCdlFlagSousIT &= ((tDATCdlFlag)~(((tDATCdlFlag)1)<<cDATCanAntisaturationActive)))
  #define mBitIsClearDATCanAntisaturationActive(IdCan) ((DATCdlTableEmission[(IdCan)].DATCdlFlagSousIT & ((tDATCdlFlag) (((tDATCdlFlag)1)<<cDATCanAntisaturationActive))) == ((tDATCdlFlag)0x00UL))
  #endif

  #define mBitSetCtrlDATCanStatusEmission(IdCan)     (DATCdlTableEmission[(IdCan)].DATCdlFlagSousIT |= ((tDATCdlFlag) (((tDATCdlFlag)1)<<cDATCanStatusEmission)))
  #define mBitIsSetCtrlDATCanStatusEmission(IdCan)   ((DATCdlTableEmission[(IdCan)].DATCdlFlagSousIT & ((tDATCdlFlag) (((tDATCdlFlag)1)<<cDATCanStatusEmission))) != ((tDATCdlFlag)0x00UL))
  #define mBitClearCtrlDATCanStatusEmission(IdCan)   (DATCdlTableEmission[(IdCan)].DATCdlFlagSousIT &= ((tDATCdlFlag)~(((tDATCdlFlag)1)<<cDATCanStatusEmission)))
  #define mBitIsClearCtrlDATCanStatusEmission(IdCan) ((DATCdlTableEmission[(IdCan)].DATCdlFlagSousIT & ((tDATCdlFlag) (((tDATCdlFlag)1)<<cDATCanStatusEmission))) == ((tDATCdlFlag)0x00UL))

//Macro to check if a control or a transmission is in progress
#define mFlagCtrlTransmitNotInProgress(IdCan)                        \
     ((DATCdlTableEmission[(IdCan)].DATCdlFlag &                     \
      ((((tDATCdlFlag)1)<<cDATCanInit)                               \
      |(((tDATCdlFlag)1)<<cDATCanDemarrer)                           \
      |(((tDATCdlFlag)1)<<cDATCanArretEnCours)                       \
      |(((tDATCdlFlag)1)<<cDATCanCancelTransmissionInProgress)       \
      |(((tDATCdlFlag)1)<<cDATCanEmissionEnCours) )  )               \
    == ((tDATCdlFlag)0x00UL))


//Macro de test d'un controle en cours
#define mFlagCtrlNotInProgress(IdCan)                                \
    ((DATCdlTableEmission[(IdCan)].DATCdlFlag &                      \
      ((((tDATCdlFlag)1)<<cDATCanInit)                               \
      |(((tDATCdlFlag)1)<<cDATCanArretEnCours)                       \
      |(((tDATCdlFlag)1)<<cDATCanDemarrer)                           \
      |(((tDATCdlFlag)1)<<cDATCanCancelTransmissionInProgress) )  )  \
     == ((tDATCdlFlag)0x00UL))


#define mDATCdlIsNotStoppingOrStopped(IdCan)           \
    ((DATCdlTableEmission[(IdCan)].DATCdlFlag &        \
      ((((tDATCdlFlag)1)<<cDATCanArretConfirme)        \
      |(((tDATCdlFlag)1)<<cDATCanArretEnCours) )    )  \
     == ((tDATCdlFlag)0x00UL))

#define mDATCdlIsNotStopped(IdCan)                     \
    ((DATCdlTableEmission[(IdCan)].DATCdlFlag &        \
      (((tDATCdlFlag)1)<<cDATCanArretConfirme))        \
     == ((tDATCdlFlag)0x00UL))

#define mBitInitFlag(IdCan)                                      \
    {DATCdlTableEmission[(IdCan)].DATCdlFlag &=                  \
     ((tDATCdlFlag)~( (((tDATCdlFlag)1)<<cDATCanArretConfirme)   \
       |(((tDATCdlFlag)1)<<cDATCanArretEnCours)                  \
       |(((tDATCdlFlag)1)<<cDATCanCancelTransmissionInProgress)  \
       |(((tDATCdlFlag)1)<<cDATCanEmissionEnCours) ));           \
    DATCdlTableEmission[IdCan].DATCdlFlagSousIT &=               \
    ((tDATCdlFlag) ~( (((tDATCdlFlag)1)<<cDATCanStatusEmission) ));}
//Let the antisaturation with its state

#define cDATCdlTxFlagLength ((U8)( ((U8)( ((U8)(cDATCdl_NbUUTx-((U8)1UL) ))/((U8)8UL) )) + ((U8)1UL) ))

#ifdef M_MULTIBUS_CAN
//Access macro for bit operation on Tab flag
#define mSetFlag(IdCan, Tab, Handle)\
        (DATCdlTableEmission[(IdCan)].Tab[ ((U8)(Handle)>>3)] |= ((U8) (((U8)1)<<( (U8)((Handle) & ((U8)0x07UL))))))

#define mClearFlag(Tab, Handle)\
        (DATCdlTableEmission[(IdCan)].Tab[ ((U8)(Handle)>>3)] &= ((U8)~(((U8)1)<<( (U8)((Handle)& ((U8)0x07UL))))))

#define mIsSetFlag(Tab, Handle)\
        ((BOOL)(DATCdlTableEmission[(IdCan)].Tab[ ((U8)(Handle)>>3)] & ((U8) (((U8)1)<<( (U8)((Handle) & ((U8)0x07UL)))))) != 0)

#define mIsClearFlag(Tab, Handle)\
        ((BOOL)(DATCdlTableEmission[(IdCan)].Tab[ ((U8)(Handle)>>3)] & ((U8) (((U8)1)<<( (U8)((Handle) & ((U8)0x07UL)))))) == 0)

#define mClearAllFlag(IdCan, Tab)\
        mLIBmemset(DATCdlTableEmission[(IdCan)].Tab, 0, sizeof(DATCdlTableEmission[(IdCan)].Tab))

#else
#define mSetFlag(Tab, Handle)\
        (DATCdlTableEmission[cDATCdlIdCanalCan].Tab[ ((U8)(Handle)>>3)] |= ((U8) (((U8)1)<<( (U8)((Handle) & ((U8)0x07UL))))))

#define mClearFlag(Tab, Handle)\
        (DATCdlTableEmission[cDATCdlIdCanalCan].Tab[ ((U8)(Handle)>>3)] &= ((U8)~(((U8)1)<<( (U8)((Handle) & ((U8)0x07UL))))))

#define mIsSetFlag(Tab, Handle)\
        ((BOOL)(DATCdlTableEmission[cDATCdlIdCanalCan].Tab[ ((U8)(Handle)>>3)] & ((U8) (((U8)1)<<( (U8)((Handle) & ((U8)0x07UL)))))) != 0)

#define mIsClearFlag(Tab, Handle)\
        ((BOOL)(DATCdlTableEmission[cDATCdlIdCanalCan].Tab[ ((U8)(Handle)>>3)] & ((U8) (((U8)1)<<( (U8)((Handle) & ((U8)0x07UL)))))) == 0)

#define mClearAllFlag(Tab)        \
        mLIBmemset(DATCdlTableEmission[cDATCdlIdCanalCan].Tab, 0, sizeof(DATCdlTableEmission[cDATCdlIdCanalCan].Tab))
#endif

/* Macro for declare Call Back link to Rx frames */
/* Call Back of CAN recieved messages */
#define mDATCdlDeclarerCallBackRx(NomTrame)                                 \
    static void CallBackReception##NomTrame (tAddress Address, tStatus NonUtilise2, tMsg* pMsg) \
    {                                                                       \
        NonUtilise2 = NonUtilise2;                                          \
        DATCdlReceptionMessageCAN (Address,cDATCdlD_UURxHandle##NomTrame, pMsg);    \
    }

/* Macro for declare Call Back link to CAN buses */
#define mDATCdlDeclarerCallBackChannelCan(NomCan)                           \
    /* Call Back of CAN bus control */                                      \
    void DAT##NomCan##CallBackCtrl (tCtrl Ctrl)                             \
    {                                                                       \
        DATMultiCanCallBackCtrl (cDATCdlIdCanal##NomCan, Ctrl);             \
    }                                                                       \
    /* Call Back of CAN bus end of control */                               \
    void DAT##NomCan##CallBackEndCtrl (tCtrl Ctrl,tStatus Statut)           \
    {                                                                       \
        DATMultiCanCallBackEndCtrl (Ctrl, Statut, cDATCdlIdCanal##NomCan);  \
    }                                                                       \
    /* Call Back of CAN message transmission feed back */                   \
    void DAT##NomCan##CallBackTxWithAddr (tAddress Ad, tStatus Statut)      \
    {                                                                       \
        DATMultiCanCallBackTxWithAddr (cDATCdlIdCanal##NomCan, Ad, Statut); \
    }

#define mDATCdlDeclarerTableCallBack(NomCanal)                                      \
    const tRxSpontWithAddr DAT##NomCanal##RxSpontTable[cDATCdl_NbUURx_##NomCanal] = \
    {                                                                               \
        mDATCdlInitRxSpontTable##NomCanal()                                         \
    }

//------------------------------------------------------------------------------
// Local types
//
// typedef Expression    tTypeName;
//------------------------------------------------------------------------------

typedef tAddress tAddressCAN;

typedef struct
{
    U8 RequetesEmission[cDATCdlTxFlagLength];   // Flag for pending request
    tDATCdlD_UUTxHandle HandleEmissionEnCours;  // Handle of the transmission in progress
    tDATCdlNbTick NbTick;                             // Number of Tick before Tx timeout
    tDATCdlFlag  DATCdlFlag;                    // Flag for pending control
    tDATCdlFlag  volatile DATCdlFlagSousIT;     // Flag for pending control, flag accessed into interrupt context
}
tDATCdlInfoEmission;

#ifdef ANTISATURATION
typedef struct
{
    tDATCdlDate DATCdlDate;
    tDATCdlDate DATCdlDerniereDate;
    tDATCdlCmptTrames DATCdlCmptTrames;
}tDATCdlInfoAntisaturation;
#endif

#ifdef M_MULTIBUS_CAN
typedef struct
{
 tChannel IdLDBCanalCan;
 tDATCdlNbTick TimeoutTxCanalCan;
}tDATCdlTableParamCanalCan;
#endif

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

#ifdef QUEUE_NBMAX_SUPERVISION
static U8 QueueRxNbMax;
#endif

// data concerning the transmission in progress: one per CAN channel
static tDATCdlInfoEmission DATCdlTableEmission [cDATCdl_NbCanauxCan];

#ifdef ANTISATURATION
  #ifndef M_MULTIBUS_CAN
static tDATCdlInfoAntisaturation DATCdlTableInfoReception;
  #else
static tDATCdlInfoAntisaturation DATCdlTableInfoReception [cDATCdl_NbCanauxCan];
#endif

#endif

/* Call Backs definition linked to Rx frames */
mDATCdlDeclarerListeCallBackRx()

#ifndef M_MULTIBUS_CAN

/* Call back table of recieved message on the CAN bus For LDB Calls */
const tRxSpontWithAddr DATCanRxSpontTable[cDATCdl_NbUURx_Can] =
{
    mDATCdlInitRxSpontTable()
};

#else  /* M_MULTIBUS_CAN */

/* CAN multi bus case */

/* Call Backs Declaration linked to Rx frames */
mDATCdlDeclarerListeTableCallBackRx()

//dow
//ÊÖ¶¯Ìí¼Ó
mDATCdlDefRxSpontTable()
/*
const tRxSpontWithAddr DATCanRxSpontTable[] =
{
    {CallBackReceptionDiagOnCanPAP, ((tAddress)0x700UL)},
    {CallBackReceptionDiagOnCanDiffusion, ((tAddress)0x999UL)},

    {CallBackReceptionRPM_0x0CFF5182, ((tAddress)0x100UL)},
        {CallBackReceptionSpeed_0x18FF0824, ((tAddress)0x101UL)},
        {CallBackReceptionDIOSt_0x18FFD121, ((tAddress)0x300UL)}

       };
       */
//upper
/* Call Backs Declaration linked to CAN channels */
mDATCdlDeclarerListeCallBackChannelCan()

#endif /* M_MULTIBUS_CAN */

/* Daclare Nb CallBack Rx */
mDATCdlDeclarerConstRxSpontNbr()

//------------------------------------------------------------------------------
// Constant local data
//
// static const tType  VariableName;
//------------------------------------------------------------------------------

// ROM declaration of the identifier LDB of the CAN channel
#ifdef M_MULTIBUS_CAN
static const tDATCdlTableParamCanalCan DATCdlTableParamCanalCan[cDATCdl_NbCanauxCan] = mDATCdlInitTableROMCan();
#endif

#ifdef ANTISATURATION

#ifndef M_MULTIBUS_CAN
static const tDATCdlParamAntisaturation  DATCdlTableParamAntisaturation = mDATCdlInitTableParamRx();
#else
static const tDATCdlParamAntisaturation  DATCdlTableParamAntisaturation[cDATCdl_NbCanauxCan] = mDATCdlInitTableParamRx();

#endif

#endif


//------------------------------------------------------------------------------
// Exported data
//
// tType   u8LAYCmpVariableName; (LAY: 3 characters to identify the layer)
// tType*  pu8LAYCmpVariableName;(Cmp: 3 characters to identify the component)
//------------------------------------------------------------------------------

// RAM table for the transmitted frame
U8 DATCdlTableLngTx [cDATCdl_NbUUTx];

// Transmitted buffer containing the transmitted data
tDATCdlBuffersUUTx DATCdlBuffersUUTx;

//Rolling buffer
tDATCdlMsgQueueRx DATCdlMsgQueueRx;

//Rolling buffer parameters
tDATCdlParamQueue DATCdlParamQueueRx;

extern BOOL  sbIsBatProtect;
//------------------------------------------------------------------------------
// Constant exported data
//
//             (LAY: 3 characters to identify the layer)
//             (Cmp: 3 characters to identify this component)
// 
// const tType   LAYCmpVariableName;
//------------------------------------------------------------------------------

#ifdef M_MULTIBUS_CAN
//ROM declaration of the CAN channel identifier for each transmitted frame
const tDATCdlIdCanalCan DATCdlTableCanauxCanRx[cDATCdl_NbUURx] = mDATCdlInitTableROMChannelCan();
#endif

//ROM declaration of the data concerning the transmitted frame
const tDATCdl_IdentTx DATCdlTableROMTx[cDATCdl_NbUUTx] =
    {
        mDATCdlInitTableROMTx()
    };

//ROM declaration of the length of the received frame
const U8 DATCdlTableLngMinStatique[cDATCdl_NbUURx] =
    mDATCdlInitTableROMLngMinStatique();

const U8 DATCdlTableLngMaxStatique[cDATCdl_NbUURx] =
    mDATCdlInitTableROMLngMaxStatique();

//------------------------------------------------------------------------------
// Local function prototypes
// 
// static tTypeRetour FunctionName(tTypeArgument1 ArgumentName1, ... );
//------------------------------------------------------------------------------

static tDATCdlD_UURxHandle ChercheHandlePlusPrioritaireEtEffaceIndication(U8* Drapeaux, tDATCdlD_UURxHandle Taille);
#ifndef M_MULTIBUS_CAN
static void DATCdlInitInterne(void);
#else
static void DATCdlInitInterne(tDATCdlIdCanalCan IdCan);
#endif

//==============================================================================
//=========================== LOCAL FUNCTIONS ==================================
//==============================================================================

//==============================================================================
// DESCRIPTION : Initialization of the local data
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
#ifndef M_MULTIBUS_CAN
static void DATCdlInitInterne(void)
#else
static void DATCdlInitInterne(tDATCdlIdCanalCan IdCan)
#endif
{
    #ifndef M_MULTIBUS_CAN
    mBitClearAllFlags(cDATCdlIdCanalCan)
    DATCdlTableEmission[cDATCdlIdCanalCan].NbTick = (tDATCdlNbTick)0;
    #else
    mBitClearAllFlags(IdCan)
    DATCdlTableEmission[IdCan].NbTick = (tDATCdlNbTick)0;
    #endif


    #ifdef ANTISATURATION
    #ifndef M_MULTIBUS_CAN
    DATCdlTableInfoReception.DATCdlDate = (tDATCdlDate)0;
    DATCdlTableInfoReception.DATCdlDerniereDate = (tDATCdlDate)0;
    DATCdlTableInfoReception.DATCdlCmptTrames = (tDATCdlCmptTrames)DATCdlTableParamAntisaturation.cDATCdlNbTrameMax;
    #else
    DATCdlTableInfoReception[IdCan].DATCdlDate = (tDATCdlDate)0;
    DATCdlTableInfoReception[IdCan].DATCdlDerniereDate = (tDATCdlDate)0;
    DATCdlTableInfoReception[IdCan].DATCdlCmptTrames = (tDATCdlCmptTrames)DATCdlTableParamAntisaturation[IdCan].cDATCdlNbTrameMax;
    #endif
    #endif
}

//==============================================================================
// DESCRIPTION : return the MSB into a chain of flag
//
// PARAMETERS (Type,Name,Min,Max) : U8* Drapeaux : address of the chain of flag
//                                  U8 taille : Length of the chain of flag
//
// RETURN VALUE :   tDATCdlD_UURxHandle : position of the MSB, e.g the most prioritary handle to treat
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
static tDATCdlD_UURxHandle ChercheHandlePlusPrioritaireEtEffaceIndication(
    U8* Drapeaux, tDATCdlD_UURxHandle Taille)
{
    tDATCdlD_UURxHandle  HandleToFind;
    U8      Mask ;
    U8      Index ;
    U8      IndexSize ;
    BOOL    HandleIsFind;

    HandleIsFind = cFalse;
    IndexSize = (U8)(((U8)(Taille-((U8)1))>>3) + ((U8)1));
    HandleToFind = 0; //For QAC
    Mask = 0; //For QAC

    // GEN-RESEAU-ST-RCCANLS.0009 (1)
    Index = 0;
    while ((Index < IndexSize) && (HandleIsFind == cFalse))
    {
        HandleToFind = ((U8)0UL);
        Mask   = ((U8)0x01UL);

        while( (HandleIsFind == cFalse) && (HandleToFind < 8))
        {
            if( ((*( (Drapeaux + Index))) & Mask) != 0)
            {
                HandleIsFind = cTrue;
            }
            else
            {
                Mask <<= 1;
                HandleToFind++;
            }
        }

        if (HandleIsFind == cFalse)
        {
            Index ++;
        }
    }

    mLIBassert(HandleIsFind != cFalse);
    // Mask IT to avoid multiple access conflict
    mDisableIT();

    //Clear the request
    (*((U8*)(Drapeaux + Index))) &= ((U8)(~Mask));

    // restore IT
    mEnableIT();

    return ((U8)( ((U8)HandleToFind + ((U8)Index<<3))));
}


//==============================================================================
//=========================== EXPORTED FUNCTIONS ===============================
//==============================================================================

//==============================================================================
// DESCRIPTION : Transmission request from the upper layer
//
// PARAMETERS (Type,Name,Min,Max) : tDATCdlD_UUTxHandle : handle to send [0; cDATCdl_NbUUTx]
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void DATCdlD_UUDataReq(tDATCdlD_UUTxHandle TrameHandle)
{
    #ifdef M_MULTIBUS_CAN
    tDATCdlIdCanalCan IdCanalCan;
    IdCanalCan = mDATCdlLireCanalCanTx(TrameHandle);
    mLIBassert( IdCanalCan < cDATCdl_NbCanauxCan);
    #endif

    mLIBassert( TrameHandle<cDATCdl_NbUUTx);
    mLIBassert( mDATCdlLngTxHandle(TrameHandle) <= DATCdlTableROMTx[TrameHandle].Lng);

    #ifdef M_MULTIBUS_CAN
    if(mDATCdlIsNotStoppingOrStopped(IdCanalCan))
    #else
    if(mDATCdlIsNotStoppingOrStopped(cDATCdlIdCanalCan))
    #endif
    {
        // memorization of the transmission request
        #ifdef M_MULTIBUS_CAN
        mSetFlag(IdCanalCan, RequetesEmission, TrameHandle);
        #else
        mSetFlag(RequetesEmission, TrameHandle);
        #endif
        #ifdef M_MULTIBUS_CAN
        if(mFlagCtrlTransmitNotInProgress(IdCanalCan) != cFalse)
        {
            mBitSetCtrlDATCanEmissionEnCours(IdCanalCan);
        #else
        if(mFlagCtrlTransmitNotInProgress(cDATCdlIdCanalCan) != cFalse)
        {
            mBitSetCtrlDATCanEmissionEnCours(cDATCdlIdCanalCan);
        #endif
            TOSActivateTask( cTOSTaskID_EmissionCan );
        }
    }
    else
    {

    	TOSActivateTask( cTOSTaskID_EmissionCan );
        //DATCnlD_UUDataCon(TrameHandle, cFalse);
    }
}

//==============================================================================
// DESCRIPTION : Callback from LDB_CAN to indicate the end of a transmission.
//               activate the Transmission task to leave the interrupt context
//
// PARAMETERS (Type,Name,Min,Max) : tAddress Adresse: ID CAN of the sent frame
//                                  tStatus Statut : Status of the transmission: must be cTrue
//                                  defect of transmission are treated by timeout
//                                  tDATCdlIdCanalCan IdCan: CAN channel identifier
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
#ifndef M_MULTIBUS_CAN
void DATCanCallBackTxWithAddr (tAddress Adresse, tStatus Statut)
{
    tDATCdlInfoEmission* pCanalEmission;

    pCanalEmission = &(DATCdlTableEmission[cDATCdlIdCanalCan]);
    if(pCanalEmission != NULL) //to avoid a warning in release mode
    {
        mLIBassert (  (Adresse == mAdresseCANTxHandle(pCanalEmission->HandleEmissionEnCours))
                      ||(pCanalEmission->NbTick == (tDATCdlNbTick)0) );
    }
    
    //Status must be correct, failure are treated by timeout
    mLIBassert (Statut == cLDBCorrect);

    //Status must be correct, failure are treated by timeout
    if(Statut == cLDBCorrect)
    {
        mBitSetCtrlDATCanStatusEmission(cDATCdlIdCanalCan);
    }
    else
    {
        //to avoid to treat a false Tx frame event, which in fact has not been sent by LDB_CAN
        //DAT_CDL will try another frame after the Tx timeout
        mLIBassert (cFalse);
    }

    TOSActivateTask(cTOSTaskID_EmissionCan);
#else
void DATMultiCanCallBackTxWithAddr (tDATCdlIdCanalCan IdCan, tAddress Adresse, tStatus Statut)
{
    tDATCdlInfoEmission* pCanalEmission;

    mLIBassert (IdCan < cDATCdl_NbCanauxCan);

    pCanalEmission = &(DATCdlTableEmission[IdCan]);
    if(pCanalEmission != NULL) //to avoid a warning in release mode
    {
        mLIBassert (  (Adresse == mAdresseCANTxHandle(pCanalEmission->HandleEmissionEnCours))
                    ||(pCanalEmission->NbTick == (tDATCdlNbTick)0) );
    }
    
    //Status must be correct, failure are treated by timeout
    if(Statut == cLDBCorrect)
    {
        mBitSetCtrlDATCanStatusEmission(IdCan);
    }
    else
    {
        //to avoid to treat a false Tx frame event, which in fact has not been sent by LDB_CAN
        //DAT_CDL will try another frame after the Tx timeout
        mLIBassert (cFalse);
    }

    TOSActivateTask(cTOSTaskID_EmissionCan);
#endif
}

//==============================================================================
// DESCRIPTION : Transmission task: treat the end of transmission and the pending Tx request
//               Treat the pending LDB Control
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : FOR All Can channel
//                            IF Tx is finished
//                                Call Back to DAT_CNL
//                            END IF
//
//                            IF LDB Control is pending
//                              Treat LDB Control
//                            ELSE
//                              Treat pending Transmission request
//                            END IF
//
//==============================================================================
void DATCdlCANTransmissionTask (void)
{

    tDATCdlInfoEmission*  pCanalEmission;
    tDATCdlIdCanalCan     IdCan;
    tDATCdlD_UUTxHandle*  pHandleEmissionEncours;

    U8*  pDemandesEmission;

    tDATCdlD_UUTxHandle TxHandle;

    static tMsg Msg;

    for (IdCan = 0; IdCan < cDATCdl_NbCanauxCan; IdCan++)
    {
        pCanalEmission = &(DATCdlTableEmission[IdCan]);
        pHandleEmissionEncours = &(pCanalEmission->HandleEmissionEnCours);

        if( (mBitIsSetCtrlDATCanStatusEmission(IdCan))&&( mBitIsSetCtrlDATCanEmissionEnCours(IdCan)))
        {
            mLIBassert(*pHandleEmissionEncours != cHandleTxInvalide);
            //Robust code to avoid a RAM corruption
            if(*pHandleEmissionEncours != cHandleTxInvalide)
            {
                DATCnlD_UUDataCon(*pHandleEmissionEncours, cTrue);
            }

            mBitClearCtrlDATCanEmissionEnCours(IdCan);

            pCanalEmission->HandleEmissionEnCours  = cHandleTxInvalide;
            pCanalEmission->NbTick = (tDATCdlNbTick)0;

            mDisableIT();
            //The flag MUST be clear
            mBitClearCtrlDATCanStatusEmission(IdCan);
            mEnableIT();
        }

        if(mFlagCtrlNotInProgress(IdCan) == cFalse)
        {
            if(mBitIsSetCtrlDATCanCancelTransmissionInProgress(IdCan))
            {

                #ifndef M_MULTIBUS_CAN
                LDBControl(cLDBChannelCan,cLDBCanCancelTransmissionInProgress);
                #else
                LDBControl(mLDBCanalCANNumCan(IdCan), cLDBCanCancelTransmissionInProgress);
                #endif

                if(mBitIsClearCtrlDATCanCancelTransmissionInProgress(IdCan))
                {
                    mDisableIT();
                    mBitClearCtrlDATCanStatusEmission(IdCan);
                    mEnableIT();

                    if(pCanalEmission->HandleEmissionEnCours != cHandleTxInvalide)

                    {
                        //Remove pending request in case where the cancel come from a stop command
                        mClearFlag(RequetesEmission,pCanalEmission->HandleEmissionEnCours);
                        DATCnlD_UUDataCon(*pHandleEmissionEncours, cFalse);
                        #ifdef cLIBStkDatCanConfig_PsaBody
                        // Increment N_As counter
                        DATCplIncrementN_AsCounter();
                        #endif
                        pCanalEmission->HandleEmissionEnCours  = cHandleTxInvalide;
                    }
                    pCanalEmission->NbTick = (tDATCdlNbTick)0;
                    //Activate the task to treat other control or Tx request
                    TOSActivateTask(cTOSTaskID_EmissionCan);
                }
            }

            else if(mBitIsSetCtrlDATCanArretEnCours(IdCan))
            {
                U8 Index;
                tDATCdlD_UURxHandle HandleToFind;
                U8 Mask;

                HandleToFind = 0; //For QAC
                Mask = 0; //For QAC

                #ifndef M_MULTIBUS_CAN
                LDBControl(cLDBChannelCan,cLDBCanStop);
                #else
                LDBControl(mLDBCanalCANNumCan(IdCan), cLDBCanStop);
                #endif

                //Treat the pending Tx request
                Index = (U8)(((U8)(cDATCdl_NbUUTx- ((U8)1UL))>>3) + ((U8)1UL));

                while((Index != 0))
                {
                    HandleToFind = ((U8)8UL);
                    Mask   = ((U8)0x80UL);

                    while(HandleToFind != 0)
                    {
                        if(((*( ((&(pCanalEmission->RequetesEmission[0])) + Index) -((U8)1) )) & Mask) != 0)
                        {
                            //Clear the request flag
                            *( (&(pCanalEmission->RequetesEmission[0]) + Index)-((U8)1)) &= (((U8)~Mask));
                            //Send a Tx callback
                            DATCnlD_UUDataCon( ((U8)( ((U8)(HandleToFind - ((U8)1) )) + ((U8)(Index-((U8)1))<<3))) , cFalse);
                        }
                        Mask >>= 1;
                        HandleToFind--;
                    }
                    Index--;
                }
            }

            else if(mBitIsSetCtrlDATCanInit(IdCan))
            {
                #ifndef M_MULTIBUS_CAN
                LDBControl(cLDBChannelCan,cLDBCanInit);
                #else
                LDBControl(mLDBCanalCANNumCan(IdCan), cLDBCanInit);
                #endif
            }
            else
            {
                //It's a start control
                #ifndef M_MULTIBUS_CAN
                LDBControl(cLDBChannelCan,cLDBCanStart);
                #else
                LDBControl(mLDBCanalCANNumCan(IdCan),cLDBCanStart);
                #endif
                //Clear the start request flag
                mBitClearCtrlDATCanDemarrer(IdCan);
            }
        }
        else
        {
            //There is no end of transmission or LDB control in progress
            if (*pHandleEmissionEncours == cHandleTxInvalide)
            {
                BOOL EmissionIsPending;
                U8 i;

                pDemandesEmission = &(pCanalEmission->RequetesEmission[0]);

                //Check if there is pending transmission request
                EmissionIsPending = cFalse;
                for(i=0; (i< cDATCdlTxFlagLength)&&(EmissionIsPending == cFalse); i++)
                {
                    if(*(pDemandesEmission+i) != 0)
                    {
                        EmissionIsPending = cTrue;
                    }
                    else
                    {
                        //For QAC
                    }
                }
                if(EmissionIsPending != cFalse)
                {
                    // Look for the most prioritary frame to send (the lowest Tx pending handle value)
                    TxHandle = ChercheHandlePlusPrioritaireEtEffaceIndication (pDemandesEmission, cDATCdl_NbUUTx);

                    // prepare the message to send
                    Msg.pBuffer = mDATCdlBufferTxHandle(TxHandle);
                    Msg.Lng = mDATCdlLngTxHandle(TxHandle);

                    //Memorization of the transmitted handle
                    pCanalEmission->HandleEmissionEnCours =  TxHandle;

                    // Launch the transmission timeout
                    #ifdef M_MULTIBUS_CAN
                    pCanalEmission->NbTick = mDATCdlLireTimeoutTxEnTick(TxHandle);
                    #else
                    pCanalEmission->NbTick = ((tDATCdlNbTick)cDATCdlTimeOutTxEnNbCdlTick);
                    #endif

                    mBitSetCtrlDATCanEmissionEnCours(IdCan);

                    mDisableIT();
                    mBitClearCtrlDATCanStatusEmission(IdCan);
                    mEnableIT();

                    #ifndef M_MULTIBUS_CAN
                    LDBSendWithAddr(cLDBChannelCan,
                                      mAdresseCANTxHandle(TxHandle),
                                      &Msg);
                    #else
                    if (DATCnmGetCanBusOffState(IdCan) == FALSE)
                    {
                    	if(NM_MODE_NETWORK == CanNm_Mode[0])
                    	{
                    		LDBSendWithAddr(mLDBCanalCANTxHandle(TxHandle),mAdresseCANTxHandle(TxHandle),&Msg);
                    	}
//                    	LDBSendWithAddr(mLDBCanalCANTxHandle(TxHandle),mAdresseCANTxHandle(TxHandle),&Msg);
                    }
                    #endif

                }
                // There is no pending transmission request
                else
                {
                    mBitClearCtrlDATCanEmissionEnCours(IdCan);
                }
            }
            else
            {
                //For QAC
            }
        }
    }
}

//==============================================================================
// DESCRIPTION : Initialization of the whole component
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void DATCdlInit (void)
{
    #ifdef M_MULTIBUS_CAN
    tDATCdlIdCanalCan IdCan;
    #endif


    //J1939_Init();

    //Check the priority between the CAN task identifier (cf DAT_CDL.jil)
    mLIBassert(cTOSTaskID_CanTraitements>cTOSTaskID_EmissionCan);
    mLIBassert(cTOSTaskID_EmissionCan>cTOSTaskID_ReceptionCan);

    mLIBmemset(DATCdlTableEmission,0,((U16)cDATCdl_NbCanauxCan*sizeof(tDATCdlInfoEmission)));

    // Initialization of the rolling buffer management parameters
    DATCdlParamQueueRx.NextToRead = 0;
    DATCdlParamQueueRx.Nb = 0;

    // Initialization of the tranmitted length table
    mLIBmemset(DATCdlTableLngTx,0,cDATCdl_NbUUTx);

    #ifdef M_MULTIBUS_CAN

    //Loop for all CAN channel
    for (IdCan=0;IdCan<cDATCdl_NbCanauxCan;IdCan++)
    {
        //Local data initialization
        DATCdlInitInterne(IdCan);

        //Clear all transmission request flag
        mClearAllFlag(IdCan, RequetesEmission);

        // No transmission in progress
        DATCdlTableEmission[IdCan].HandleEmissionEnCours = cHandleTxInvalide;

        //Memorization of the first Init control in progress
        mBitSetCtrlDATCanFirstInit(IdCan);

        //Initialization of the CAN cell
        LDBControl(mLDBCanalCANNumCan(IdCan), cLDBCanInit);

        mBitSetStatusDATCanArret(IdCan);
    }
    #else

    //Local data initialization
    DATCdlInitInterne();

    //Clear all transmission request flag
    mClearAllFlag(RequetesEmission);

    // No transmission in progress
    DATCdlTableEmission[cDATCdlIdCanalCan].HandleEmissionEnCours = cHandleTxInvalide;

    //Memorization of the first Init control in progress
    mBitSetCtrlDATCanFirstInit(cDATCdlIdCanalCan);

    //Initialization of the CAN cell
    LDBControl(cLDBChannelCan, cLDBCanInit);

    mBitSetStatusDATCanArret(cDATCdlIdCanalCan);

    #endif
    #ifdef QUEUE_NBMAX_SUPERVISION
    QueueRxNbMax = 0;
    #endif
}

//==============================================================================
// DESCRIPTION : Callback from the LDB CAN to treat a CAN frame reception event
//               activate the reception task to leave the interrupt context
//
// PARAMETERS (Type,Name,Min,Max) : tDATCdlD_UURxHandle RxHandle : Handle of the received frame
//                                  tMsg* Msg : address of the standard message containing the 
//                                  received data
// RETURN VALUE :   none
//
// DESIGN INFORMATION : push the received frame into a circular buffer
//                      QUEUE_NBMAX_SUPERVISION : this compilation option activate a
//                      data "QueueRxNbMax" to measure the maximum lenth of the circular
//                      buffer used
//==============================================================================
void DATCdlReceptionMessageCAN (tAddress RxAddress,tDATCdlD_UURxHandle RxHandle, tMsg* Msg)
{
    #ifdef ANTISATURATION
    #ifdef M_MULTIBUS_CAN
    tDATCdlIdCanalCan IdCanalCan;
    #endif
    #endif

    //if(sbIsBatProtect == cFalse)
    {

#if defined(COMPILATION_NATIVE)
    // This is a special process for the purpose to test NM when simulate run on pc.
    // According to JMC NM spec, the net address range 0x400~0x4FF is only for NM
    if((RxAddress>=0x400) &&(RxAddress<=0x4ff))
    {
    	RxHandle = cDATCdlD_UURxHandleIP_RX_NM;
    }
#endif
    //There is free space into the rolling buffer
    if (DATCdlParamQueueRx.Nb < cDATCdl_NbBufferRx)
    {
        tDATCdlMsgUURx* pCdlMsg;
        U16 NextToWrite;

        //Search the buffer to push the frame
        NextToWrite = DATCdlParamQueueRx.NextToRead + DATCdlParamQueueRx.Nb;
        if (NextToWrite >= cDATCdl_NbBufferRx)
        {
            NextToWrite = (U8)(NextToWrite - (U8) cDATCdl_NbBufferRx);
        }
        pCdlMsg = &DATCdlMsgQueueRx[NextToWrite];

        // length copy
        pCdlMsg->Lng = ((U8)mMin(((U8)Msg->Lng),((U8)DATCdlTableLngMaxStatique[RxHandle])));

        // data copy
        mLIBassert((U8)Msg->Lng <= cDATCdlTailleMaxBufferCAN);

        mLIBmemcpy(pCdlMsg->Buffer, Msg->pBuffer, pCdlMsg->Lng);

        // handle copy
        mLIBassert( (RxHandle < cDATCdl_NbUURx));
        pCdlMsg->Handle = RxHandle;
        pCdlMsg->Address = RxAddress;

        DATCdlParamQueueRx.Nb++;

        //memorize the number of element pushed into the rolling buffer
        #ifdef QUEUE_NBMAX_SUPERVISION
        if (DATCdlParamQueueRx.Nb > QueueRxNbMax)
        {
            QueueRxNbMax = DATCdlParamQueueRx.Nb;
        }
        #endif

        //Reception task activation
        TOSActivateTask (cTOSTaskID_ReceptionCan);
    }
    else
    {
        //The rolling buffer is full
        // mode debug => Stop
        // mode release => The frame is lost.
        mLIBassert(cFalse);
    }

    #ifdef ANTISATURATION
    #ifdef M_MULTIBUS_CAN

    IdCanalCan = DATCdlTableCanauxCanRx[RxHandle];

    if( ((tDATCdlDate)(DATCdlTableInfoReception[IdCanalCan].DATCdlDate-DATCdlTableInfoReception[IdCanalCan].DATCdlDerniereDate)) > DATCdlTableParamAntisaturation[IdCanalCan].cDATCdlDureeCritiqueEnTick)
    {
        DATCdlTableInfoReception[IdCanalCan].DATCdlCmptTrames = DATCdlTableParamAntisaturation[IdCanalCan].cDATCdlNbTrameMax;
        DATCdlTableInfoReception[IdCanalCan].DATCdlDerniereDate = DATCdlTableInfoReception[IdCanalCan].DATCdlDate;
    }
    else
    {
        DATCdlTableInfoReception[IdCanalCan].DATCdlCmptTrames--;
        if(DATCdlTableInfoReception[IdCanalCan].DATCdlCmptTrames == 0)
        {
            mDisableITRx(IdCanalCan);
            DATCdlTableInfoReception[IdCanalCan].DATCdlDerniereDate = DATCdlTableInfoReception[IdCanalCan].DATCdlDate;
            mBitSetDATCanAntisaturationActive(IdCanalCan);
        }
    }
    #else
    if(((tDATCdlDate)(DATCdlTableInfoReception.DATCdlDate-DATCdlTableInfoReception.DATCdlDerniereDate)) > DATCdlTableParamAntisaturation.cDATCdlDureeCritiqueEnTick)
    {
        DATCdlTableInfoReception.DATCdlCmptTrames = DATCdlTableParamAntisaturation.cDATCdlNbTrameMax;
        DATCdlTableInfoReception.DATCdlDerniereDate = DATCdlTableInfoReception.DATCdlDate;
    }
    else
    {
        DATCdlTableInfoReception.DATCdlCmptTrames--;
        if(DATCdlTableInfoReception.DATCdlCmptTrames == 0)
        {
            mDisableITRx();
            DATCdlTableInfoReception.DATCdlDerniereDate = DATCdlTableInfoReception.DATCdlDate;
            mBitSetDATCanAntisaturationActive(cDATCdlIdCanalCan);
        }
    }
    #endif
    #endif
    }
}

//==============================================================================
// DESCRIPTION : Reception task: pop the received frame from the circular buffer
//               indicate to the upper layer the frame reception
//               The task re-active itself while there is other frame into the buffer
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void DATCdlCANReceptionTask(void)
{
    tDATCdlMsgUURx* pCdlMsg;
    tDATCdlD_UURxHandle HandleRx;

    #ifdef M_MULTIBUS_CAN
    tDATCdlIdCanalCan IdCanalCan;
    #endif

    // check if there is a frame to treat
    if (DATCdlParamQueueRx.Nb > 0)
    {
        pCdlMsg =  &DATCdlMsgQueueRx[DATCdlParamQueueRx.NextToRead];
        
        HandleRx = pCdlMsg->Handle;

        mLIBassert(HandleRx<cDATCdl_NbUURx);

        #ifdef M_MULTIBUS_CAN

        IdCanalCan = mDATCdlLireCanalCanRx(HandleRx);

        mLIBassert( IdCanalCan < cDATCdl_NbCanauxCan);

        //Call back to DAT_CNL
        //The frame reception is rejected if the frame length is to short
        if(  (mDATCdlLngRxHandle(HandleRx) >= mDATCdlLngMinStatiqueRxHandle(HandleRx))
           &&(mDATCdlIsNotStopped(IdCanalCan)) )
        #else
        if(  (mDATCdlLngRxHandle(HandleRx) >= mDATCdlLngMinStatiqueRxHandle(HandleRx))
           &&(mDATCdlIsNotStopped(cDATCdlIdCanalCan)) )
        #endif
        {
            //The CAN bus is not stopped
            DATCnlD_UUDataInd (HandleRx);
        }

        // Increase the parameter nextToRead and decrease Nb
        // Interrupt must be deactivated
        mDisableIT();

        DATCdlParamQueueRx.NextToRead++;
        if (DATCdlParamQueueRx.NextToRead >= (cDATCdl_NbBufferRx))
        {
            DATCdlParamQueueRx.NextToRead = 0;
        }
        DATCdlParamQueueRx.Nb--;

        mEnableIT();

        mLIBassert ( (DATCdlParamQueueRx.NextToRead < cDATCdl_NbBufferRx) );

        //Re activation of the task to pop the next frame
        TOSActivateTask (cTOSTaskID_ReceptionCan);
    }
}

//==============================================================================
// DESCRIPTION : Manage all periodic treatment for all CAN channel:
//               -Tx timeout management
//               -LDB control re attempt
//               -Antisaturation de activation
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void DATCdlTick(void)
{
    tDATCdlIdCanalCan IdCanalCan;
    tDATCdlInfoEmission*  pCanalEmission;

    //Loop for all CAN channel
    for (IdCanalCan = 0; IdCanalCan < cDATCdl_NbCanauxCan; IdCanalCan++)
    {
        #ifdef ANTISATURATION
        #ifdef M_MULTIBUS_CAN
        if(mBitIsSetDATCanAntisaturationActive(IdCanalCan))
        {
            if(((U8)(DATCdlTableInfoReception[IdCanalCan].DATCdlDate - DATCdlTableInfoReception[IdCanalCan].DATCdlDerniereDate)) >= DATCdlTableParamAntisaturation[IdCanalCan].cDATCdlDureeReessaiEnTick)
            {
                DATCdlTableInfoReception[IdCanalCan].DATCdlCmptTrames = (tDATCdlCmptTrames)DATCdlTableParamAntisaturation[IdCanalCan].cDATCdlNbTrameMax;
                DATCdlTableInfoReception[IdCanalCan].DATCdlDerniereDate = DATCdlTableInfoReception[IdCanalCan].DATCdlDate;
                mDisableIT();
                mBitClearDATCanAntisaturationActive(IdCanalCan);
                mEnableIT();
                mEnableITRx(IdCanalCan);
            }
        }
        DATCdlTableInfoReception[IdCanalCan].DATCdlDate++;

        #else
        if(mBitIsSetDATCanAntisaturationActive(cDATCdlIdCanalCan))
        {
            if(((U8)(DATCdlTableInfoReception.DATCdlDate - DATCdlTableInfoReception.DATCdlDerniereDate)) >= DATCdlTableParamAntisaturation.cDATCdlDureeReessaiEnTick)
            {
                DATCdlTableInfoReception.DATCdlCmptTrames = (tDATCdlCmptTrames)DATCdlTableParamAntisaturation.cDATCdlNbTrameMax;
                DATCdlTableInfoReception.DATCdlDerniereDate = DATCdlTableInfoReception.DATCdlDate;
                mDisableIT();
                mBitClearDATCanAntisaturationActive(cDATCdlIdCanalCan);
                mEnableIT();
                mEnableITRx();
            }
        }
        DATCdlTableInfoReception.DATCdlDate++;
        #endif
        #endif

        pCanalEmission = &(DATCdlTableEmission[IdCanalCan]);

        if( pCanalEmission->NbTick != 0 )
        {
            pCanalEmission->NbTick--;

            if( pCanalEmission->NbTick == 0 )
            {
                //Transmission timeout N_As
                mBitSetCtrlDATCanCancelTransmissionInProgress(IdCanalCan);
                //Clear the Tx in progress flag (to avoid to treat a Tx intrrupt which
                //occurs between the Timeout detection and the Tx cancellation performing
                mBitClearCtrlDATCanEmissionEnCours(IdCanalCan);
            }
        }

        // If a LDB control is in progress and it's still Nok
        if(mFlagCtrlNotInProgress(IdCanalCan) == cFalse)
        {
            TOSActivateTask( cTOSTaskID_EmissionCan );
        }
    }
}

//==============================================================================
// DESCRIPTION : Callback to signal the end of a LDB control
//
// PARAMETERS (Type,Name,Min,Max) : tCtrl Ctrl: LDB control identifier
//                                  tStatus Statut : LDB control status (cLDBError, cLDBOk)
//                                  tDATCdlIdCanalCan IdCanalCan : CAN channel identifier
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : Start control must never be cLDBError
//==============================================================================
#ifdef M_MULTIBUS_CAN
void DATMultiCanCallBackEndCtrl(tCtrl Ctrl, tStatus Statut, tDATCdlIdCanalCan IdCanalCan)
#else
void DATCanCallBackEndCtrl(tCtrl Ctrl, tStatus Statut)
#endif
{
    if(Statut != cLDBError)
    {
        switch(Ctrl)
        {
            case (cLDBCanCancelTransmissionInProgress):
                {
                    #ifndef M_MULTIBUS_CAN
                    mBitClearCtrlDATCanCancelTransmissionInProgress(cDATCdlIdCanalCan);
                    #else
                    mBitClearCtrlDATCanCancelTransmissionInProgress(IdCanalCan);
                    #endif
                    break;
                }

            case (cLDBCanInit):
                {
                    #ifndef M_MULTIBUS_CAN
                    mBitClearCtrlDATCanFirstInit(cDATCdlIdCanalCan);
                    mBitClearCtrlDATCanInit(cDATCdlIdCanalCan);
                    #else
                    mBitClearCtrlDATCanFirstInit(IdCanalCan);
                    mBitClearCtrlDATCanInit(IdCanalCan);
                    #endif
                    //To send the pending Tx frame if needed
                    TOSActivateTask(cTOSTaskID_EmissionCan);
                    break;
                }

            case (cLDBCanStop):
                {
                    #ifndef M_MULTIBUS_CAN
                    DATCnm_D_Confirm((tDATCdlCtrl)cDATCdlCtrlArreter, cTrue);
                    mBitClearCtrlDATCanArretEnCours(cDATCdlIdCanalCan);
                    mBitSetStatusDATCanArret(cDATCdlIdCanalCan);
                    #else
                    DATCnm_D_Confirm((tDATCdlIdCanalCan)IdCanalCan, (tDATCdlCtrl)cDATCdlCtrlArreter, cTrue);
                    mBitClearCtrlDATCanArretEnCours(IdCanalCan);
                    mBitSetStatusDATCanArret(IdCanalCan);
                    #endif
                    break;
                }

            case (cLDBCanStart):
                {
                    BOOL EmissionIsPending;
                    U8 i;
                    U8*  pDemandesEmission;
                    tDATCdlInfoEmission*  pCanalEmission;
                    tDATCdlIdCanalCan     IdCan;

                    // Treat the pending transmission request
                    EmissionIsPending = cFalse;
                    // loop for all CAN channel
                    for (IdCan = 0; ((IdCan < cDATCdl_NbCanauxCan)&&(EmissionIsPending == cFalse)); IdCan++)
                    {
                        pCanalEmission = &(DATCdlTableEmission[IdCan]);
                        pDemandesEmission = &(pCanalEmission->RequetesEmission[0]);

                        for(i=0; ((i< cDATCdlTxFlagLength)&&(EmissionIsPending == cFalse)); i++)
                        {
                            if(*(pDemandesEmission+i) != 0)
                            {
                                EmissionIsPending = cTrue;
                                //A Tx request has occured during the init retry, so the activation
                                //of the Tx Task was not performed
                                //Do not filter with the CAN channel
                                TOSActivateTask( cTOSTaskID_EmissionCan );
                            }
                        }
                    }
                    #ifndef M_MULTIBUS_CAN
                    DATCnm_D_Confirm((tDATCdlCtrl)cDATCdlCtrlStart, cTrue);
                    #else
                    DATCnm_D_Confirm((tDATCdlIdCanalCan)IdCanalCan, (tDATCdlCtrl)cDATCdlCtrlStart, cTrue);
                    #endif
                    break;
                }

            case (cLDBCanSelfDiag):
                {
                    #ifndef M_MULTIBUS_CAN
                    DATCnm_D_Confirm((tDATCdlCtrl)cDATCdlCtrlSelfDiag, cTrue);
                    #else
                    DATCnm_D_Confirm((tDATCdlIdCanalCan)IdCanalCan, (tDATCdlCtrl)cDATCdlCtrlSelfDiag, cTrue);
                    #endif
                    break;
                }

            default:
                mLIBassert(cTrue); //For QAC
                break;
        }
    }
    else
    {
        mLIBassert((Ctrl == cLDBCanSelfDiag)||(Ctrl == cLDBCanCancelTransmissionInProgress)||(Ctrl == cLDBCanInit)||(Ctrl == cLDBCanStop));
        if(Ctrl == cLDBCanSelfDiag)
        {
            #ifndef M_MULTIBUS_CAN
            DATCnm_D_Confirm((tDATCdlCtrl)cDATCdlCtrlSelfDiag, cFalse);
            #else
            DATCnm_D_Confirm((tDATCdlIdCanalCan)IdCanalCan, (tDATCdlCtrl)cDATCdlCtrlSelfDiag, cFalse);
            #endif
        }
    }
}

//==============================================================================
// DESCRIPTION : Spontaneous call back from the LDB to signal an event (bus off,
//               bus on, passive error, wake up by CAN)
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
#ifndef M_MULTIBUS_CAN
void DATCanCallBackCtrl (tCtrl Ctrl )
{
    DATCnm_D_Status((tDATCdlStatus)Ctrl);
}
#else
void DATMultiCanCallBackCtrl (tDATCdlIdCanalCan IdCan, tCtrl Ctrl )
{
    DATCnm_D_Status(IdCan, (tDATCdlStatus)Ctrl);
}
#endif

//==============================================================================
// DESCRIPTION : Start the LDB CAN channel and the DAT component
//
// PARAMETERS (Type,Name,Min,Max) : tDATCdlIdCanalCan IdCan: CAN channel identifier
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : If the initialization of the CAN cell has failed the re attempt
//                      process is started here
//==============================================================================
#ifndef M_MULTIBUS_CAN
void DATCdl_D_Init(void)
{
    mBitInitFlag(cDATCdlIdCanalCan)

    if(mBitIsSetCtrlDATCanFirstInit(cDATCdlIdCanalCan))
    {
        //The first init (call into DAT_CdlInit() ) has not worked
        mBitClearCtrlDATCanFirstInit(cDATCdlIdCanalCan);
        //Set the flag for re initialization try
        mBitSetCtrlDATCanInit(cDATCdlIdCanalCan);
        //Memorization of the Start request
        mBitSetCtrlDATCanDemarrer(cDATCdlIdCanalCan);
    }
    else
    {
        LDBControl(cLDBChannelCan, cLDBCanStart);
    }
#else
void DATCdl_D_Init(tDATCdlIdCanalCan IdCan)
{
    mBitInitFlag(IdCan)

    if(mBitIsSetCtrlDATCanFirstInit(IdCan))
    {   
        //The first init (call into DAT_CdlInit() ) has not worked
        mBitClearCtrlDATCanFirstInit(IdCan);
        //Set the flag for re initialization try
        mBitSetCtrlDATCanInit(IdCan);
        //Memorization of the Start request
        mBitSetCtrlDATCanDemarrer(IdCan);
    }
    else
    {
        LDBControl(mLDBCanalCANNumCan(IdCan), cLDBCanStart);
    }
#endif
}

//==============================================================================
// DESCRIPTION : Stop the CAN Channel
// 
// PARAMETERS (Type,Name,Min,Max) : tDATCdlIdCanalCan IdCan: CAN channel identifier
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
#ifndef M_MULTIBUS_CAN
void DATCdl_D_Stop(void)
{
    DATCdlInitInterne();

    mBitSetCtrlDATCanCancelTransmissionInProgress(cDATCdlIdCanalCan);

    mBitSetCtrlDATCanArretEnCours(cDATCdlIdCanalCan);
#else
void DATCdl_D_Stop(tDATCdlIdCanalCan IdCan)
{
    DATCdlInitInterne(IdCan);

    mBitSetCtrlDATCanCancelTransmissionInProgress(IdCan);

    mBitSetCtrlDATCanArretEnCours(IdCan);
#endif
}

//==============================================================================
// DESCRIPTION : Re-initialization of the CAN cell, it can occurs whenever
//
// PARAMETERS (Type,Name,Min,Max) : tDATCdlIdCanalCan IdCan: CAN channel identifier
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : Set a flag to cancel the transmission in progress and reset the CAN cell
//                      these request are treated into the transmission task
//==============================================================================
#ifndef M_MULTIBUS_CAN
void DATCdl_D_Reset(void)
{
    mBitSetCtrlDATCanInit(cDATCdlIdCanalCan);
    mBitSetCtrlDATCanCancelTransmissionInProgress(cDATCdlIdCanalCan);
#ifdef cLIBStkDatCanConfig_PsaBody
    //Clear pending request to avoid to send frame without having received COMMANDE_BSI life phase
    mClearAllFlag(RequetesEmission);
#endif
    TOSActivateTask( cTOSTaskID_EmissionCan );
}

#else
void DATCdl_D_Reset(tDATCdlIdCanalCan IdCan)
{
    mBitSetCtrlDATCanInit(IdCan);
    mBitSetCtrlDATCanCancelTransmissionInProgress(IdCan);
#ifdef cLIBStkDatCanConfig_PsaBody
    //Clear pending request to avoid to send frame without having received COMMANDE_BSI life phase
    mClearAllFlag(IdCan, RequetesEmission);
#endif
    TOSActivateTask( cTOSTaskID_EmissionCan );
}

#endif


