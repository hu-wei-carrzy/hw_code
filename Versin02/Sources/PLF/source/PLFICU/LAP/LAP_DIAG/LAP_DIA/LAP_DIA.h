//******************************************************************************
// Company:      Johnson Controls Inc.
// -----------------------------------------------------------------------------
// Copyright:    This software is JCI property.
//               Duplication or disclosure without JCI written authorization
//               is prohibited.
// -----------------------------------------------------------------------------
// Project:      <STANDARD>
// Language:     C
// -----------------------------------------------------------------------------
// Component:    Diag On Can Management: UDS/DiagOnCAN implementation
//               this component is a template which may be modify to implement
//               project Dia requirements
//******************************************************************************

#ifndef I_LAP_DIA_H
#define I_LAP_DIA_H (1)

//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//
// #include <system_file_name.h>
// #include "project_file_name.h"
//------------------------------------------------------------------------------

#include "ARCH_CFG.h"

#ifdef cHeadIncludeType_Directly
#include "LAP_DIAx.h"

#ifdef BOOTLOADER_IS_SUPPORTED
#include "LIB_BOO.h"
#endif

#else


#include ".\..\..\..\SCC2Gen\Gen\LAP_diax.h"

#ifdef BOOTLOADER_IS_SUPPORTED
#include ".\..\..\..\LIB\LIB_BOO\LIB_BOO.h"
#endif

#endif



#include "LAP_DIA_INCLUDE.h"

#include "LAP_DIA_CFG.h"
#include "LAP_DIA_TYPECOMMON.h"
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
#define cLAPDiaService                                      ((U8) 0)

#define cLAPDiaIdDiagnosticSessionControl                   ((U8) 0x10UL)
#define cLAPDiaIdEcuReset                                   ((U8) 0x11UL)
#define cLAPDiaIdSecurityAccess                             ((U8) 0x27UL)
#define cLAPDiaIdTesterPresent                              ((U8) 0x3EUL)
#define cLAPDiaIdControlDTCSetting                          ((U8) 0x85UL)
#define cLAPDiaIdReadDataByIdentifier                       ((U8) 0x22UL)
#define cLAPDiaIdReadMemoryByAddress                        ((U8) 0x23UL)
#define cLAPDiaIdWriteDataByIdentifier                      ((U8) 0x2EUL)
#define cLAPDiaIdWriteMemoryByAddress                       ((U8) 0x3DUL)
#define cLAPDiaIdClearDiagnosticInformation                 ((U8) 0x14UL)
#define cLAPDiaIdReadDTCInformation                         ((U8) 0x19UL)
#define cLAPDiaIdInputOutputControlByIdentifier             ((U8) 0x2FUL)
#define cLAPDiaIdRoutineControl                             ((U8) 0x31UL)
#define	cLAPDiaIdRequestDownLoad                            ((U8) 0x34UL)
#define	cLAPDiaIdRequestUpLoad                              ((U8) 0x35UL)
#define	cLAPDiaIdTransferData                               ((U8) 0x36UL)
#define	cLAPDiaIdRequestTransferExit                        ((U8) 0x37UL)

#define cLAPDiaServiceIsCorrect                             ((U8) 0x00UL)
#define cLAPDiaServiceNotSupported                          ((U8) 0x11UL)
#define cLAPDiaSubFunctionNotSupported                      ((U8) 0x12UL)
#define cLAPDiaIncorrectMessageLengthOrInvalidFormat        ((U8) 0x13UL)
#define cLAPDiaResponseTooLong                              ((U8) 0x14UL)
#define cLAPDiaBusyRepeatRequest                            ((U8) 0x21UL)
#define cLAPDiaConditionsNotCorrect                         ((U8) 0x22UL)
#define cLAPDiaRequestSequenceError                         ((U8) 0x24UL)
#define cLAPDiaNoResponseFromSubnetComponent                ((U8) 0x25UL)
#define cLAPDiaFailurePreventsExecutionOfRequestedAction    ((U8) 0x26UL)
#define cLAPDiaRequestOutOfRange                            ((U8) 0x31UL)
#define cLAPDiaSecurityAccessDenied                         ((U8) 0x33UL)
#define cLAPDiaInvalidKey                                   ((U8) 0x35UL)
#define cLAPDiaExceedNumberOfAttempts                       ((U8) 0x36UL)
#define cLAPDiaRequiredTimeDelayNotExpired                  ((U8) 0x37UL)
#define cLAPDiaUploadDownloadNotAccepted                    ((U8) 0x70UL)
#define cLAPDiaTransferDataSuspended                        ((U8) 0x71UL)
#define cLAPDiaGeneralProgrammingFailure                    ((U8) 0x72UL)
#define cLAPDiaWrongBlockSequenceCounter                    ((U8) 0x73UL)
#define cLAPDiaResponsePending                              ((U8) 0x78UL)
#define cLAPDiaSubFunctionNotSupportedInActiveSession       ((U8) 0x7EUL)
#define cLAPDiaServiceNotSupportedInActiveSession           ((U8) 0x7FUL)
#define cLAPDiaVoltageTooHigh                               ((U8) 0x92UL)
#define cLAPDiaVoltageTooLow                                ((U8) 0x93UL)

#define cLAPDiaStartOfService                               ((U8) 0)
#define cLAPDiaFirstStep                                    ((U8) 1)


//------------------------------------------------------------------------------
// Exported Macros
//
// #define LAYCmpMacroName(...)   (MacroDefinition)
//------------------------------------------------------------------------------
#define mLAPDiaReadNegativeResponseCode()\
          (LAPDiaResponse.NegativeCode)

#define mLAPDiaWriteNegativeResponseCode(Valeur)\
          (LAPDiaResponse.NegativeCode = (Valeur))


#define mLAPDiaReadLengthOfRequest()\
          (LAPDiaMemorizedRequest.Length)

#define mLAPDiaReadLengthOfResponse()\
          (LAPDiaResponse.Length)

#define mLAPDiaWriteLengthOfResponse()\
          (LAPDiaResponse.Length)


#define mLAPDiaReadDIAStepActiveService() \
          (LAPDiaActiveService.Step)

#define mLAPDiaWriteDIAStepActiveService(Valeur)\
          (LAPDiaActiveService.Step = (Valeur))


#define mLAPDiaReadDiagnosticRequest(Index)\
        (LAPDiaMemorizedRequest.Buffer[Index])


#define mLAPDiaReadDiagnosticResponse(Index)\
        (LAPDiaResponse.Buffer[Index])
#define mLAPDiaWriteDiagnosticResponse(Index)\
        (LAPDiaResponse.Buffer[Index])

#define mLAPDiaGetPointerDiagnosticResponse(Index)\
        (&(LAPDiaResponse.Buffer[Index]))

//------------------------------------------------------------------------------
// Pointer protection
//------------------------------------------------------------------------------
#ifdef BROADCAST_REQUEST
    #define mCheckpReceivedRequest()                                            \
            ( (RequestInAnalyze.pReceivedRequest == &ReceivedRequestP2P)  \
                      ||(RequestInAnalyze.pReceivedRequest == &ReceivedRequestALL) )

    #define mCheckpReceivedRequestpBuffer()                                                     \
            ( (RequestInAnalyze.pReceivedRequest->pBuffer == (U8*)&BufferReceivedRequestP2P)   \
                      ||(RequestInAnalyze.pReceivedRequest->pBuffer == (U8*)&BufferReceivedRequestALL) )
#else
    #define mCheckpReceivedRequest()                                            \
            (  RequestInAnalyze.pReceivedRequest == &ReceivedRequestP2P)

    #define mCheckpReceivedRequestpBuffer()                                                 \
            (RequestInAnalyze.pReceivedRequest->pBuffer == (U8*)&BufferReceivedRequestP2P)
#endif

//------------------------------------------------------------------------------
// Exported type
//
// typedef Expression tLAYCmpTypeName;
//------------------------------------------------------------------------------
typedef void (* tLAPDiaServiceFunction)(void);

typedef struct
{
  const U8 *                        pTabIdentifierOfSupportedService;
  const tLAPDiaServiceFunction *    pTabFunctionOfSupportedService;
  U8                                NbOfSupportedService;
  U8                                SessionIdentifier;
  tLAPDiaSessionMask                SessionMask;
} tLAPDiaParamOfSession;


typedef struct
{
    U8  SessionIndex;
    U8  Step;
    BOOL bReadyToFinished;
}tLAPDiaService;


typedef struct
{
    #if (cLAPDiaLngBufferResponse >0xFFUL)
        U16 Length;
    #else
        U8  Length;
    #endif
    U8  Buffer[cLAPDiaLngBufferResponse];
    U8  NegativeCode;
    U8  From;
}tLAPDiaResponse;


typedef struct
{
    U16 Length;
    U8  Buffer[cLAPDiaLngBufferRequestP2P];
    U8  Status;
}tLAPDiaMemorizedRequest;

//------------------------------------------------------------------------------
// Exported data
//
// extern  tType   LAYCmpVariableName;
// extern  tType*  pLAYCmpVariableName; 
//------------------------------------------------------------------------------
extern tLAPDiaParamOfSession*   pLAPDiaActiveSession;
extern tLAPDiaService           LAPDiaActiveService;

extern tLAPDiaMemorizedRequest  LAPDiaMemorizedRequest;
extern tLAPDiaResponse          LAPDiaResponse;

extern U8  mu8IOC_ScaleBackLight;
extern U8  mu8IOC_LCDBackLight;
extern U8  mu8IOC_LCDDisplay;

extern U8  mu8IOC_Speed;
extern U16 mu16IOC_Tacho;
extern U32 mu32IOC_AgeFlag;

extern U8  mu8IOC_BuzType;
extern U8  mu8IOC_PwrLockType;
extern U16 mu16IOC_C3Out;
extern U32 mu32IOC_LEDOutL;
extern U16 mu16IOC_LEDOutH;
extern U16 mu16IOC_PowerOut;

extern U8 mu8IOC_VideoChn;
extern U8 mu8IOC_KeyBackLight;

#ifdef ACCESSIBILITY_UNDER_VEHICLE_PROTECTION
    extern  BOOL                bLAPDiaVehicleImmobilization;
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
extern void LAPDiaInitialize(void);
extern void LAPDiaStart(void);
extern void LAPDiaStop(void);

extern void LAPDiaReceiveRequestP2P(void);
#ifdef BROADCAST_REQUEST
extern void LAPDiaReceiveRequestALL(void);
#endif

extern void LAPDiaIsMaintainActiveState(void);

#if defined(cLIBStkCarBoot_VW)
extern U8   LAPDiaGetActiveSession( void );
#endif
extern void LAPDiaDiagnosticSessionControl(void);
extern void LAPSriEcuReset(void);
extern void LAPSeaSecurityAccess(void);
extern void LAPDiaTesterPresent(void);
extern void LAPDiaCommunicationControl(void);
extern void LAPDtcControlDTCSetting(void);
extern void LAPRwiReadDataByIdentifier(void);
extern void LAPRwaReadMemoryByAddress(void);
extern void LAPRwiWriteDataByIdentifier(void);
extern void LAPRwaWriteMemoryByAddress(void);
extern void LAPDtcClearDiagnosticInformation(void);
extern void LAPDtcReadDTCInformation(void);
extern void LAPIocInputOutputControlByIdentifier(void);
extern void LAPSriRoutineControl(void);
extern void LAPSeaRequestDownLoad(void);
extern void LAPSeaRequestUpLoad(void);
extern void LAPSeaTransferData(void);
extern void LAPSeaRequestTransferExit(void);

extern void LAPDiaPrepareNegativeResponse(U8 NRC);
extern void LAPDiaPreparePositiveResponse(U8 Length);
extern void LAPDiaPreparePositiveResponseSimple(U8 Length);
extern void LAPDiaResponseBegin( void);
extern void LAPDiaResponseWriteByte( U8 Data);
extern BOOL LAPDiaIsResponseLengthOverflow( void);

extern void LAPDiaAnalyzeRequest(void);
extern void LAPDiaExecuteService(void);
extern BOOL LAPDiaNewRequestIsReceived(void);
extern void LAPDiaSendResponse(BOOL bPositive);
extern void LAPDiaTreatCommunicationTimeOut(void);
extern BOOL LAPDiaCommunicationTimeOutIsElapsed(void);
extern BOOL LAPDiaP2TimeOutIsElapsed(void);
extern void LAPDiaSendBusyResponse(void);

extern U32 LAPDiaFindDIDIndex( const U16 *DidTable, U16 Did, U32 TableSize);

extern BOOL LAPDiaIsFunctionAddress();
extern BOOL LAPDiaIsPhysicalAddress();

extern BOOL LAPSeaIsServiceUnLocked();

extern BOOL LAPDia_IsSeaDTElapsed(void);
extern void LAPDia_StartDT(void);
#endif   /* I_LAP_DIA_H */


