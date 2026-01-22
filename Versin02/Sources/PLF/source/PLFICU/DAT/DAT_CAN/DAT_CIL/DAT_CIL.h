

//------------------------------------------------------------------------------
//    Includes non re entry
//------------------------------------------------------------------------------
#ifndef I_DAT_CIL_H
#define I_DAT_CIL_H

//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//
// #include <system_file_name.h>
// #include "project_file_name.h"
//------------------------------------------------------------------------------
#include "ARCH_CFG.h"

#ifdef cHeadIncludeType_Directly
#include "DAT_CTL.H"
#include "DAT_CILp.H"
#else
#include ".\..\DAT_CTL\DAT_CTL.H"
#include ".\..\..\..\SCC2Gen\GEN\DAT_CILp.h"
#endif
#define cDAT_CIL_SELFINCLUDE
#include "DAT_CIL_INCLUDE.h"
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

#define cDATCilSourceInvalide      ((tDATCilSourceHandle)0xFFUL)
#define cDATCilI_TxHandleInvalide  ((tDATCilI_ASSHandle)0xFFUL)
#define cDATCilI_RxHandleInvalide  ((tDATCilI_ASSHandle)0xFFUL)
#define cDATCilI_MessageHandleInvalide  ((tDATCilI_MessageHandle)0xFFUL)

#define cDATCilNbTotalHandleASDTEnCorrespondanceTx  ((U8)(cDATCtlNbASTx*cDATCilNbMaxTrameTxParSource))
#define cDATCilNbTotalHandleASDTEnCorrespondanceRx  ((U8)(cDATCtlNbASRx*cDATCilNbMaxTrameRxParSource))

#ifdef cDATCtlNbASTx
  #if cDATCtlNbASTx!=0
    #ifndef DAT_CTL_SESSION_ON
      #error "DAT_CTL must be active if the ASDT interaction layer is used"
    #endif
    #define ASDT_INTERACTION_LAYER_ON
    #define cDATCilNbASTx cDATCtlNbASTx
  #endif
#endif

#ifdef cDATCtlNbASRx
  #if(cDATCtlNbASRx != 0)
    #ifndef DAT_CTL_SESSION_ON
      #error "DAT_CTL must be active if the ASDT interaction layer is used"
    #endif
    #define ASDT_INTERACTION_LAYER_ON
    #define cDATCilNbASRx cDATCtlNbASRx
  #endif
#endif


#ifdef cDATCil_NbEcu
  #if(cDATCil_NbEcu != 0)
    #ifndef DAT_CTL_SESSION_ON
      #error "DAT_CTL must be active if the ASDT presentation layer is used"
    #endif

    #ifndef ASDT_INTERACTION_LAYER_ON
      #error "DAT_CTL must be active if the ASDT presentation layer is used"
    #endif

    #define ASDT_PRESENTATION_LAYER_ON

  #endif
#endif


#ifdef ASDT_INTERACTION_LAYER_ON
  #define cDAT_CilMsgStatus_E_COM_NOMSG                   ((tDATCilMsgStatus)0x01UL)
  #define cDAT_CilMsgStatus_E_COM_LOCKED                  ((tDATCilMsgStatus)0x02UL)
  #define cDAT_CilMsgStatus_E_COM_SYS_NOTINITIALISED      ((tDATCilMsgStatus)0x04UL)
  #define cDAT_CilMsgStatus_E_COM_SYS_CONNECTING          ((tDATCilMsgStatus)0x08UL)
  #define cDAT_CilMsgStatus_E_COM_SYS_ERROR               ((tDATCilMsgStatus)0x10UL)
  #define cDAT_CilMsgStatus_E_COM_SYS_CONNECTERROR        ((tDATCilMsgStatus)0x20UL)
  #ifdef DISCONNECTION_AUTHORIZED
  #define cDAT_CilMsgStatus_E_COM_SYS_DISCONNECTING       ((tDATCilMsgStatus)0x40UL)
  #endif

  #define  cDATCil_NbMessage ((U8)(cDATCtlNbASTx + cDATCtlNbASRx))
#endif

#ifdef ASDT_PRESENTATION_LAYER_ON
  #define cDATCilEcuStatusNotInitialised     ((tDATCilEcuStatus) 0x01UL)
  #define cDATCilEcuStatusConnecting         ((tDATCilEcuStatus) 0x02UL)
  #define cDATCilEcuStatusConnected          ((tDATCilEcuStatus) 0x04UL)
  #define cDATCilEcuStatusDisconnected       ((tDATCilEcuStatus) 0x08UL)
  #ifdef DISCONNECTION_AUTHORIZED
    #define  cDATCilEcuStatusDisconnecting   ((tDATCilEcuStatus) 0x10UL)
  #endif
#endif


#ifdef M_MULTIBUS_CAN
#define cDATCil_NbCanauxCan (cDATCdl_NbCanauxCan)
#endif

//------------------------------------------------------------------------------
// Exported Macros
//
// #define LAYCmpMacroName(...)   (MacroDefinition)
//------------------------------------------------------------------------------
#define mDATCilDeclarerTx(PeriodeMs,PhaseMs,NomSource) \
{(PeriodeMs)/cDATCdlTickMs,(PhaseMs)/cDATCdlTickMs,cDATCilSource##NomSource}

//#define mDATCilDeclarerRx(Timeout,NomSource) \
//        {mTOSConvMsInTimerTick(Timeout),cDATCilSource##NomSource}

//这里有两层超时判断，我们用第二层，故第一层写死为100ms,注意诊断超时用到了第一层的100ms
#define mDATCilDeclarerRx(Timeout,NomSource) \
        {mTOSConvMsInTimerTick(100),cDATCilSource##NomSource}


#define mDATCilDeclarerASDTTx(NomTrame) \
        cDATCilI_MessageHandle##NomTrame

#define mDATCilDeclarerASDTRx(NomTrame) \
        cDATCilI_MessageHandle##NomTrame

#ifdef M_MULTIBUS_CAN
#define mDATCilDeclarerCanalCan(NomTrame, IdCanalCan) (IdCanalCan)
#endif

#define mDATCilConvertTimeIntick(Time)  ((U16)(((Time)/cDATCdlTickMs) + ((U16)1U) ))

//------------------------------------------------------------------------------
// Exported type
//
// typedef Expression tLAYCmpTypeName;
//------------------------------------------------------------------------------
typedef U8 tDATCilI_TxHandle;  //Handles of Tx frames
typedef U8 tDATCilI_RxHandle;  //Handles of Rx frames
typedef U8 tDATCilI_ASHandle;  //Handles of ASDT frame
typedef U8 tDATCilI_ASSHandle; //Handles of ASDT session frame

typedef U8 tDATCilSourceHandle; //Supervised sources
typedef U8 tDATCilNbTramesASDT; //Number of ASDT frames

//typedef U8 tDATCdlD_UURxHandle;  //add by zjb
typedef U8 tDATCilI_EcuHandle;     //ECU using ASDT channel
typedef U8 tDATCilI_MessageHandle; //ASDT channel message ID

typedef U8 tDATCilMsgStatus;
typedef U8 tDATCilEcuStatus;


//Tx frame information
typedef struct
{
    // Tx period (0 = non periodic)
    tPeriode                   Periode;
    // Time shift during start of DAT_CIL and first periodic sending
    U8                   Phase;
    // ECU handle to supervised (cDATCilSourceInvalide: no ECU supervised)
    tDATCilSourceHandle         Source;
} tDATCilTxMessage;

//Rx frame information
typedef struct
{
    // Timeout (0 = no timeout)
    tTOSTimer                   Timeout;
    // ECU handle to supervised (cDATCilSourceInvalide: no ECU supervised)
    tDATCilSourceHandle         Source;
} tDATCilRxMessage;

#ifdef M_MULTIBUS_CAN
typedef tDATCdlIdCanalCan tDATCilIdCanalCan;
#endif

//------------------------------------------------------------------------------
// Exported data
//
// extern  tType   u8LAYCmpVariableName;
// extern  tType*  ps32LAYCmpVariableName;
//------------------------------------------------------------------------------
extern U8 DATCplTableMsgReceivedFlg[];

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

extern void DATCilSendMessage(tDATCilI_TxHandle ITxHandle);

// Call-Back DAT_CPL
extern void DATCplI_USDataCon( tDATCilI_TxHandle TxHandle, BOOL EmissionOk );
extern void DATCplI_UUDataCon( tDATCilI_TxHandle TxHandle, BOOL EmissionOk );

#ifdef COMPOSANT_DAT_CTL_ON
extern void DATCplI_ASDataCon( tDATCilI_TxHandle TxHandle, BOOL EmissionOk );
  #ifdef DAT_CTL_SESSION_ON
extern void DATCplI_ASSDataCon( tDATCilI_TxHandle TxHandle, BOOL EmissionOk );

//Call-Back DAT_CTL
extern void DATCilS_ConnectInd( tDATCtlT_ASRxHandle SRxHandle );
extern void DATCilS_ConnectCon( tDATCtlS_ASHandle TTxHandle ,BOOL EmissionOk);
extern void DATCilS_DisconnectInd( tDATCtlT_ASRxHandle SRxHandle );

    #ifdef ASDT_INTERACTION_LAYER_ON
extern tDATCilMsgStatus  DATCilGetMessageStatus(tDATCilI_MessageHandle DATCil_ASDTHandle);
      #ifndef ASDT_PRESENTATION_LAYER_ON
extern void DATCilCloseMessage(tDATCilI_MessageHandle DATCil_ASDTHandle);
extern void DATCilInitMessage(tDATCilI_MessageHandle DATCil_ASDTHandle);
      #else
extern void DATCilCloseEcu(tDATCilI_EcuHandle DATCil_NumeroEcu);
extern void DATCilInitEcu(tDATCilI_EcuHandle DATCil_NumeroEcu);
extern tDATCilEcuStatus  DATCilGetEcuStatus(tDATCilI_EcuHandle DATCil_NumeroEcu);
      #endif
    #endif

  #endif

#endif

// Call-Back DAT_CPL
extern BOOL        DATCplPreparerEmission( tDATCilI_TxHandle TxHandle );
extern void        DATCplTraiterReception( tDATCilI_RxHandle RxHandle, BOOL Timeout );


// call by DAT_CNM
extern void DATCilInit(void);
extern void DATCilTick(void);

#ifdef M_MULTIBUS_CAN
extern void DATCil_I_Init(tDATCilIdCanalCan IdCanalCan);
extern void DATCil_I_Stop(tDATCilIdCanalCan IdCanalCan);
#else
extern void DATCil_I_Init(void);
extern void DATCil_I_Stop(void);
#endif

#ifdef SUPERVISION_SURVEILLANCE_COMMANDEES
// call by DAT_CPL
extern void DATCilInitSurveillance(tDATCilI_RxHandle IRxHandle, BOOL bReLaunch);
extern void DATCilInitSupervision(U8 SourceHandle);
#endif

#ifndef SUPERVISION_OFF
// Call-Back DAT_CNM
extern void DATCnmNetworkInfos(tDATCilSourceHandle SourceHandle, BOOL StatutOk);
#endif

extern void DATCilInitTransmission(void);
extern void DATCilFramRxSurveyRestart(void);
extern void DATCilFramRxSurveyRestartByHandle(tDATCdlD_UURxHandle DRxHandle);
#endif/* I_DAT_CIL_H */

