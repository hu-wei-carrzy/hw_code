
#ifndef I_DAT_CDL_H 
#define I_DAT_CDL_H (1)

//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//
// #include <system_file_name.h>
// #include "project_file_name.h"
//------------------------------------------------------------------------------
#include "ARCH_CFG.h"




#ifdef cHeadIncludeType_Directly
#include "DAT_LIB.h"
#include "DAT_CDLp.h"
#else
#include ".\..\..\DAT_LIB.h"
#include ".\..\..\..\SCC2Gen\GEN\DAT_CDLp.h"
#include ".\..\LDB\LDB_CAN\LDB_CAN_LIFE.h"
#endif

//#include "DAT_CDL_GEN.h"
#include "DAT_CDL_INCLUDE.h"

//------------------------------------------------------------------------------
// Data prefix for constant & data
//
// unsigned int {u8,u16,u32} / signed int {s8,s16,s32} 
// register size unsigned int {r} / float {f32,f64}  / s for struct 
// no prefix for other types.
//
//------------------------------------------------------------------------------
// Constant data
//
// #define cu16LAYCmpConstantName   ((U16) ConstantValueUL)
//------------------------------------------------------------------------------
#define DAT_Cdl2

//Check if there is several CAN channel
#ifdef cDATCdl_NbCanauxCan
  #ifndef cDATCdl_NbCanauxCanNonType
    #define cDATCdl_NbCanauxCanNonType cDATCdl_NbCanauxCan
  #endif
  #if cDATCdl_NbCanauxCanNonType > 1
    #define M_MULTIBUS_CAN
  #endif
#endif

#ifndef M_MULTIBUS_CAN
//Constant definition in mono bus case
#ifndef cDATCdl_NbCanauxCan
  #define cDATCdl_NbCanauxCanNonType  1
  #define cDATCdl_NbCanauxCan         ((U8)1UL)
#endif
#define cDATCdlIdCanalCan ((tDATCdlIdCanalCan) 0UL )

#ifndef cDATCdl_NbUUTx
  #define cDATCdl_NbUUTx cDATCdl_NbUUTx_Can
#endif

#ifndef cDATCdl_NbUURx
  #define cDATCdl_NbUURx cDATCdl_NbUURx_Can
#endif

#endif

//LDB Call back Status
#define cDATCdlStatusBusOn           ((tDATCdlStatus)cLDBCanBusOn)
#define cDATCdlStatusBusOff          ((tDATCdlStatus)cLDBCanBusOff)
#define cDATCdlStatusPassiveError    ((tDATCdlStatus)cLDBCanPassiveError)
#define cDATCdlStatusWakeUp          ((tDATCdlStatus)cLDBCanWakeUp)
#define cDATCdlStatusNerrOff         ((tDATCdlStatus)cLDBCanNerrOff)
#define cDATCdlStatusNerrOn          ((tDATCdlStatus)cLDBCanNerrOn)
#define cDATCdlStatusSelfDiagError   ((tDATCdlStatus)cLDBCanSelfDiagError)
#define cDATCdlStatusSelfDiagNoError ((tDATCdlStatus)cLDBCanSelfDiagNoError)

//LDB Ctrl
#define cDATCdlCtrlArreter           ((tDATCdlCtrl)cLDBCanStop)
#define cDATCdlCtrlStart             ((tDATCdlCtrl)cLDBCanStart)
#define cDATCdlCtrlSelfDiag          ((tDATCdlCtrl)cLDBCanSelfDiag)

//Maximum length of a CAN frame
#define cDATCdlTailleMaxBufferCAN (8)

//------------------------------------------------------------------------------
// Exported Macros
//
// #define LAYCmpMacroName(...)   (MacroDefinition)
//------------------------------------------------------------------------------

#define mDATCdlConvertirEnTickCAN(NomConstante)\
  ((((NomConstante) / cDATCdlTickMs) < ((U8)1UL) ) ? ((U8)1UL) : ((U8)(((NomConstante) / cDATCdlTickMs) + ((U8)1UL) )))


// pointer on the transmitted data
#define mDATCdlBufferTxHandle(TrameHandle) (DATCdlTableROMTx[TrameHandle].pBuffer)

// Length of the transmitted frame
#define mDATCdlLngTxHandle(TrameHandle) (DATCdlTableLngTx[TrameHandle])


//Minimum length of the received frame
#define mDATCdlLngMinStatiqueRxHandle(TrameHandle) (DATCdlTableLngMinStatique[TrameHandle])

//Maximum length of the received frame
#define mDATCdlLngMaxStatiqueRxHandle(TrameHandle) (DATCdlTableLngMaxStatique[TrameHandle])

//pointer on the received data
#define mDATCdlBufferRxHandle(TrameHandle) \
  (DATCdlMsgQueueRx[DATCdlParamQueueRx.NextToRead].Buffer)

//Length of the received frame
#define mDATCdlLngRxHandle(TrameHandle) \
  (DATCdlMsgQueueRx[DATCdlParamQueueRx.NextToRead].Lng)

//Address of the received frame
#define mDATCdlAddressRxHandle(TrameHandle) \
  (DATCdlMsgQueueRx[DATCdlParamQueueRx.NextToRead].Address)

//Macros for the parameterization

#define mDATCdlDclEltTableROMRx(NomTrame) \
     {CallBackReception##NomTrame, cDATCdlIdentRx##NomTrame}

// element definition of the transmission ROM tables
// ===+---Buffer---+---size---+---Identifiert frame---+--Channel-Can-
#define mDATCdlDclEltTableROMTx(NomTrame, CanalCan) \
    {DATCdlBuffersUUTx.NomTrame, cDATCdlTaille##NomTrame, cDATCdlIdentTx##NomTrame , (CanalCan)}

#define mDATCdlConvertTimeoutTxToTickCan(TimeOutTxMs) \
  ((tDATCdlNbTick)((( (TimeOutTxMs) / cDATCdlTickMs) < 1UL) ? (((U8)2UL)) : (((TimeOutTxMs) / cDATCdlTickMs)+((U8)1UL))))

#define mDATCdlDeclarerTableParamRx(NomCanal)                   \
  {                                                             \
     ((U8)mDATCdlConvertirEnTickCAN(cDATCdlDureeCritique_##NomCanal)),\
     ((U8)cDATCdlNbTrameMax_##NomCanal),                              \
     ((U8)mDATCdlConvertirEnTickCAN(cDATCdlDureeReessai_##NomCanal))  \
  }

#define mDATCdlDeclarerCanalCan(NomTrame, IdCanalCan) (IdCanalCan)

//Tx timeout conversion into CAN Tick, no type because used in #if test
#define cDATCdlTimeOutTxEnNbCdlTickNonType \
    ((( (cTimeOutTxMs + cDATCdlTickMs) - 1UL) / cDATCdlTickMs) + 1UL)

#define cDATCdlTimeOutTxEnNbCdlTick \
    ((tDATCdlNbTick) ( ((tDATCdlNbTick)( ((tDATCdlNbTick)((tDATCdlNbTick)(cTimeOutTxMs + cDATCdlTickMs) - 1UL)) / cDATCdlTickMs)) + 1UL))

//------------------------------------------------------------------------------
// Exported type
//
// typedef Expression tLAYCmpTypeName;
//------------------------------------------------------------------------------
#ifdef ANTISATURATION
typedef U8 tDATCdlDate;
typedef U8 tDATCdlCmptTrames;
#endif

typedef struct
{
    U8  cDATCdlDureeCritiqueEnTick;
    U8  cDATCdlNbTrameMax;
    U8  cDATCdlDureeReessaiEnTick;
}tDATCdlParamAntisaturation;

typedef U8 tDATCdlFlag;

typedef U8 tDATCdlD_UUTxHandle;
typedef U8 tDATCdlD_UURxHandle;

//Transmission state
typedef U8 tPhaseEmission;

// Status
typedef U8 tDATCdlStatus;

// Ctrl
typedef U8 tDATCdlCtrl;

// Identifier DAT_CDL for a channel CAN
typedef U8 tDATCdlIdCanalCan;

//buffer of the received data
typedef U8 tBufferRx [cDATCdlTailleMaxBufferCAN];

//Received message
typedef struct
{
    tBufferRx Buffer;
    tDATCdlD_UURxHandle Handle;
    tAddress Address;
    U8   Lng;
} tDATCdlMsgUURx;

//Rolling buffer
typedef tDATCdlMsgUURx tDATCdlMsgQueueRx [cDATCdl_NbBufferRx];

//Rolling buffer parameter, parameter Nb must be volatile because it's modify
//into an Interrupt context and into the reception task
typedef struct
{
    U8 NextToRead;
    volatile U8 Nb;
} tDATCdlParamQueue;

//ROM data for a tranmitted frame
typedef struct
{
    U8*   pBuffer ;                //buffer
    U8    Lng;                     //Length of the pBuffer
    tAddress  Id;                  //Frame ID CAN
    tDATCdlIdCanalCan CDLCanalId;  //CAN channel identifier
} tDATCdl_IdentTx;


#if cDATCdlTimeOutTxEnNbCdlTickNonType <= 0xFFU
typedef U8 tDATCdlNbTick;
#else
  #if cDATCdlTimeOutTxEnNbCdlTickNonType <= 0xFFFFU
typedef U16 tDATCdlNbTick;
  #else
    #if cDATCdlTimeOutTxEnNbCdlTickNonType <= 0xFFFFFFFFU
typedef U32 tDATCdlNbTick;
    #else
      #error "timeout N_as too high"
    #endif
  #endif
#endif

//------------------------------------------------------------------------------
// Exported data
//
// extern  tType   u8LAYCmpVariableName;
// extern  tType*  ps32LAYCmpVariableName; 
//------------------------------------------------------------------------------

//Length of the transmitted frame
extern U8 DATCdlTableLngTx [cDATCdl_NbUUTx];

// Buffer for the transmitted frame
extern tDATCdlBuffersUUTx DATCdlBuffersUUTx;

//Rolling buffer for the received frame
extern tDATCdlMsgQueueRx DATCdlMsgQueueRx;

//Parameters of the rollin buffer
extern tDATCdlParamQueue DATCdlParamQueueRx;

//------------------------------------------------------------------------------
// Constant exported data
//
// extern const tType  s8LAYCmpVariableName;
//------------------------------------------------------------------------------
//LDB_CAN channel number table
extern const tDATCdlIdCanalCan DATCdlTableCanauxCanRx[cDATCdl_NbUURx];

// Transmitted frame data
extern const tDATCdl_IdentTx DATCdlTableROMTx [cDATCdl_NbUUTx];

//Minimal length of the received frame
extern const U8 DATCdlTableLngMinStatique[cDATCdl_NbUURx];

//Maximum length of the received frame
extern const U8 DATCdlTableLngMaxStatique[cDATCdl_NbUURx];

//------------------------------------------------------------------------------
// Exported functions
//
// extern tReturnType LAYCmpFunctionName(tTypeArgument1 ArgumentName1, ... );
//------------------------------------------------------------------------------

extern void DATCdlReceptionMessageCAN (tAddress Address,tDATCdlD_UURxHandle RxHandle, tMsg* Msg);

#ifndef M_MULTIBUS_CAN   
void DATCanCallBackCtrl (tCtrl Ctrl );
#else
void DATMultiCanCallBackCtrl (tDATCdlIdCanalCan IdCan, tCtrl Ctrl);
#endif

#ifdef M_MULTIBUS_CAN
void DATMultiCanCallBackEndCtrl(tCtrl Ctrl, tStatus Statut, tDATCdlIdCanalCan IdCanalCan);
#else
void DATCanCallBackEndCtrl(tCtrl Ctrl, tStatus Statut);
#endif

#ifndef M_MULTIBUS_CAN
void DATCanCallBackTxWithAddr (tAddress Adresse, tStatus Statut);
#else 
void DATMultiCanCallBackTxWithAddr (tDATCdlIdCanalCan IdCan, tAddress Adresse, tStatus Statut);
#endif

extern void DATCdlCANTransmissionTask(void);
extern void DATCdlCANReceptionTask(void);
extern void DATCdlD_UUDataReq(tDATCdlD_UUTxHandle TrameHandle);

#ifndef M_MULTIBUS_CAN
extern void DATCnm_D_Status(tDATCdlStatus Statut);
#else
extern void DATCnm_D_Status(tDATCdlIdCanalCan IdCan,tDATCdlStatus Statut);
#endif

#ifndef M_MULTIBUS_CAN
extern void DATCnm_D_Confirm(tDATCdlCtrl Ctrl, BOOL Status);
#else
extern void DATCnm_D_Confirm(tDATCdlIdCanalCan IdCanalCan, tDATCdlCtrl Ctrl, BOOL Status);
#endif

#ifdef cLIBStkDatCanConfig_PsaBody
extern void DATCplIncrementN_AsCounter(void);
#endif

extern void DATCdlInit (void);
extern void DATCdlTick(void);
extern void DATCnlD_UUDataInd(tDATCdlD_UURxHandle TrameRxHandle);
extern void DATCnlD_UUDataCon(tDATCdlD_UUTxHandle TrameTxHandle, BOOL EmissionOK);

#ifndef M_MULTIBUS_CAN
extern void DATCdl_D_Init(void);
extern void DATCdl_D_Stop(void);
extern void DATCdl_D_Reset(void);
#else
extern void DATCdl_D_Init(tDATCdlIdCanalCan IdCan);
extern void DATCdl_D_Stop(tDATCdlIdCanalCan IdCan);
extern void DATCdl_D_Reset(tDATCdlIdCanalCan IdCan);
#endif

#endif /* I_DAT_CDL_H */

