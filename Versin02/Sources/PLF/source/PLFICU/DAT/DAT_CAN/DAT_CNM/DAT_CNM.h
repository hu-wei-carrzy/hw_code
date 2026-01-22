
#ifndef I_DAT_CNM_H
#define I_DAT_CNM_H

//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//
// #include <system_file_name.h>
// #include "project_file_name.h"
//------------------------------------------------------------------------------

#include "ARCH_CFG.h"

#ifdef cHeadIncludeType_Directly
#include "DAT_CDL.h"
#include "DAT_CNL.h"
#include "DAT_CTL.h"
#include "DAT_CIL.h"
#include "DAT_CPL.h"
#include "DAT_CNMp.h"
#include "DAT_DTC_DATAEXPORT.h"
#include "DAT_DTC_FUNCEXPORT.h"
#include "DAT_DTC_TYPEEXPORT.h"
#include "DAT_CAN_INCLUDE.h"
#else
#include ".\..\DAT_CDL\DAT_CDL.h"
#include ".\..\DAT_CNL\DAT_CNL.h"
#include ".\..\DAT_CTL\DAT_CTL.h"
#include ".\..\DAT_CIL\DAT_CIL.h"
#include ".\..\DAT_CPL\DAT_CPL.h"

#include ".\..\..\DAT_DTC\DAT_DTC_DATAEXPORT.h"
#include ".\..\..\DAT_DTC\DAT_DTC_FUNCEXPORT.h"
#include ".\..\..\DAT_DTC\DAT_DTC_TYPEEXPORT.h"

#include ".\..\..\..\SCC2Gen\GEN\DAT_CNMp.h"

#include ".\..\DAT_CAN_INCLUDE.h"

#endif

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
// The number of CAN status is equal to the number of source plus the BusOff Status
#ifndef M_MULTIBUS_CAN
#ifndef SUPERVISION_OFF
#define cDATCnmBusOff                           ((tDATCnmSourceHandle)cDATCil_NbSources)
#define cDATCnmNbrCANStatus                     ((tDATCnmSourceHandle)cDATCil_NbSources + 1)
#endif

#else

//One supervised CAN bus
#define cDATCnmBusOff                           ((tDATCnmSourceHandle)cDATCil_NbSources)

  #ifndef SUPERVISION_OFF
#define cDATCnmPeriodical ((U8)0x00UL) //Do not used if there is no supervised frame
  #endif
#define cDATCnmUnique     ((U8)0x01UL)

  #ifndef SUPERVISION_OFF
//One supervised CAN bus, but bus off is always manage for all bus
#define cDATCnmNbrCANStatus                     ((tDATCnmSourceHandle)cDATCil_NbSources+cDATCdl_NbCanauxCan)
  #endif
#endif

#ifndef SUPERVISION_OFF
//0x80 provoks a QAC warning with ~ operator
//#define cMaskCurrentFaultStatus                 ((tDATCnmFlagStatus)0x80UL)
#define cMaskCurrentFaultStatus                 ((tDATCnmFlagStatus)0x04UL)
#define cMaskConfirmedFaultStatus               ((tDATCnmFlagStatus)0x40UL)
#define cMaskMonitoringStatus                   ((tDATCnmFlagStatus)0x20UL)
#define cMaskJudgementTime2CounterStatus        ((tDATCnmFlagStatus)0x10UL)
#define cMaskCounterDecreaseInThisTripStatus    ((tDATCnmFlagStatus)0x08UL)
#endif

//Network states
#define cDATCmnNotInitialized    ((tDATCnmStatus)0x00UL)
#define cDATCmnStopped           ((tDATCnmStatus)0x01UL)
#define cDATCmnStarted           ((tDATCnmStatus)0x02UL)
#define cDATCmnStopInProgress    ((tDATCnmStatus)0x04UL)
#define cDATCmnStoppedError      ((tDATCnmStatus)0x08UL)
#ifdef WAKE_BY_CAN
#define cDATCmnWakeUpRequest     ((tDATCnmStatus)0x10UL)
#endif

#define cDATCnmStopTimeoutInTick   ((tDATCnmStopTimeoutInTick)(((cDATCnmStopTimeout / cDATCdlTickMs) < 1) ? (2) : ((cDATCnmStopTimeout / cDATCdlTickMs)+1)))

#define cCAN0BusOffRecoveryMs     ((U16)0U)
#define cCAN1BusOffRecoveryMs     ((U16)0U)
#define cCAN2BusOffRecoveryMs     ((U16)0U)
#define cCAN3BusOffRecoveryMs     ((U16)0U)
#define cCAN4BusOffRecoveryMs     ((U16)0U)
#define cCAN5BusOffRecoveryMs     ((U16)0U)
#define cCAN6BusOffRecoveryMs     ((U16)0U)
#define cCAN7BusOffRecoveryMs     ((U16)0U)
//------------------------------------------------------------------------------
// Exported Macros
//
// #define LAYCmpMacroName(...)   (MacroDefinition)
//------------------------------------------------------------------------------
#define mDATCnmConvertTimeMsToTickCAN(TimeMs)  ((U16)( ((U16)(TimeMs)/cDATCdlTickMs) + 1 ))

#ifndef SUPERVISION_OFF
#define mDATCnmSetCurrentFaultStatus(CANFaultHandle ) \
          ( DATCnmCANFaultStatus[CANFaultHandle].DATFlagStatus |= cMaskCurrentFaultStatus )

#define mDATCnmClearCurrentFaultStatus(CANFaultHandle ) \
          (DATCnmCANFaultStatus[CANFaultHandle].DATFlagStatus &= ((tDATCnmFlagStatus)~cMaskCurrentFaultStatus) )

#define mDATCnmReadCurrentFaultStatus(CANFaultHandle ) \
      (( DATCnmCANFaultStatus[CANFaultHandle].DATFlagStatus & cMaskCurrentFaultStatus ) != 0 )


#define mDATCnmSetConfirmedFaultStatus(CANFaultHandle ) \
          ( DATCnmCANFaultStatus[CANFaultHandle].DATFlagStatus |= cMaskConfirmedFaultStatus )

#define mDATCnmClearConfirmedFaultStatus(CANFaultHandle ) \
          ( DATCnmCANFaultStatus[CANFaultHandle].DATFlagStatus &= ((tDATCnmFlagStatus)~cMaskConfirmedFaultStatus) )

#define mDATCnmReadConfirmedFaultStatus(CANFaultHandle ) \
      (( DATCnmCANFaultStatus[CANFaultHandle].DATFlagStatus & cMaskConfirmedFaultStatus ) != 0 )

#define mDATCnmSetMonitoringStatus(CANFaultHandle ) \
          ( DATCnmCANFaultStatus[CANFaultHandle].DATFlagStatus |= cMaskMonitoringStatus )

#define mDATCnmClearMonitoringStatus(CANFaultHandle ) \
          ( DATCnmCANFaultStatus[CANFaultHandle].DATFlagStatus &= ((tDATCnmFlagStatus)~cMaskMonitoringStatus) )

#define mDATCnmReadMonitoringStatus(CANFaultHandle ) \
      (( DATCnmCANFaultStatus[CANFaultHandle].DATFlagStatus & cMaskMonitoringStatus ) != 0 )


#define mDATCnmSetJudgementTime2CounterStatus(CANFaultHandle ) \
          ( DATCnmCANFaultStatus[CANFaultHandle].DATFlagStatus |= cMaskJudgementTime2CounterStatus )

#define mDATCnmClearJudgementTime2CounterStatus(CANFaultHandle ) \
          ( DATCnmCANFaultStatus[CANFaultHandle].DATFlagStatus &= ((tDATCnmFlagStatus)~cMaskJudgementTime2CounterStatus) )

#define mDATCnmReadJudgementTime2CounterStatus(CANFaultHandle ) \
      (( DATCnmCANFaultStatus[CANFaultHandle].DATFlagStatus & cMaskJudgementTime2CounterStatus ) != 0 )


#define mDATCnmSetCounterDecreaseInThisTripStatus(CANFaultHandle ) \
          ( DATCnmCANFaultStatus[CANFaultHandle].DATFlagStatus |= cMaskCounterDecreaseInThisTripStatus )

#define mDATCnmClearCounterDecreaseInThisTripStatus(CANFaultHandle ) \
          ( DATCnmCANFaultStatus[CANFaultHandle].DATFlagStatus &= ((tDATCnmFlagStatus)~cMaskCounterDecreaseInThisTripStatus) )

#define mDATCnmReadCounterDecreaseInThisTripStatus(CANFaultHandle ) \
      (( DATCnmCANFaultStatus[CANFaultHandle].DATFlagStatus & cMaskCounterDecreaseInThisTripStatus ) != 0 )

#endif

#ifdef _QAC_
#define mDATControlCan(Action)        (mDATControlCan##Action())
#define mDATControlCanInit()          (DATCnmInit())
#else
#define mDATControlCan(Action)        mDATControlCan##Action()
#define mDATControlCanInit()          DATCnmInit()
#endif


  #ifdef LAYER_CTL_ON
  #if cDATCnl_NbASNonType >0

  //Start and stop transport layer services
  #ifdef _QAC_
  #define mDATControlCanStartComMultimedia()     (DATCtl_T_Init())
  #define mDATControlCanStopComMultimedia()      (DATCtl_T_Stop())
  #else
  #define mDATControlCanStartComMultimedia()     DATCtl_T_Init()
  #define mDATControlCanStopComMultimedia()      DATCtl_T_Stop()
  #endif

  #endif
  #endif

#ifndef M_MULTIBUS_CAN
  #ifdef _QAC_
  #define mDATControlCanStartCom()      (DATCnmStartCom())
  #define mDATControlCanStopCom()       (DATCnmStopCom())
  #define mDATControlCanSelfDiag()      (LDBControl(cLDBChannelCan, cLDBCanSelfDiag))
  #define mDATControlCanStartTransmission() (DATCnmStartTrasmission())
  #else
  #define mDATControlCanStartCom()      DATCnmStartCom()
  #define mDATControlCanStopCom()       DATCnmStopCom()
  #define mDATControlCanSelfDiag()      LDBControl(cLDBChannelCan, cLDBCanSelfDiag)
  #define mDATControlCanStartTransmission() DATCnmStartTrasmission()
  #endif

#define mDATReadU1BitIsCanBusWakeUpRequestDefault()\
        (DATCnmGetNetworkState() == cDATCmnWakeUpRequest)
#define mDATReadU1BitIsCanBusStartedDefault()\
        (DATCnmGetNetworkState() == cDATCmnStarted)
#define mDATReadU1BitIsCanBusStopProcessingDefault()\
        (DATCnmGetNetworkState() == cDATCmnStopInProgress)
#define mDATReadU1BitIsCanBusStoppedDefault()\
        (DATCnmGetNetworkState() == cDATCmnStopped)
#define mDATReadU1BitIsCanBusStopErrorDefault()\
        (DATCnmGetNetworkState() == cDATCmnStoppedError)
#define mDATReadU1BitIsCanBusNotInitialyzedDefault()\
        (DATCnmGetNetworkState() == cDATCmnNotInitialized)

  #ifndef SUPERVISION_OFF
#ifdef _QAC_
  #define mDATControlCanManagementReinitialization()\
        (DATCnmManagementReinitialization())

  #define mDATControlCanDecreaseIsAuthorized()\
            (DATCnmDecreaseIsAuthorized())

  #define mDATControlCanDecreaseIsNotAuthorized()\
            (DATCnmDecreaseIsNotAuthorized())
  #define mDATControlCanRAZFaultCounter() (DATCnmRAZFaultCounter())
#else
  #define mDATControlCanManagementReinitialization()\
        DATCnmManagementReinitialization()

  #define mDATControlCanDecreaseIsAuthorized()\
            DATCnmDecreaseIsAuthorized()

  #define mDATControlCanDecreaseIsNotAuthorized()\
            DATCnmDecreaseIsNotAuthorized()
  #define mDATControlCanRAZFaultCounter() DATCnmRAZFaultCounter()
#endif
  #endif

#endif

// one supervised bus
//else:
//  #define mDATCnmClearCurrentFaultStatusBusOff(IdCan)\
//          ( DATCnmCANFaultStatus[IdCan+cDATCil_NbSources].DATFlagStatus |= cMaskCurrentFaultStatus)
//  #define mDATCnmClearConfirmedFaultStatusBusOff(IdCan)\
//          ( DATCnmCANFaultStatus[IdCan+cDATCil_NbSources].DATFlagStatus &= ~cMaskCurrentFaultStatus)
//  #define mDATCnmClearJudgementTime2CounterStatusBusOff(IdCan)\
//        (( DATCnmCANFaultStatus[IdCan+cDATCil_NbSources].DATFlagStatus & cMaskCurrentFaultStatus ) != 0 )

#ifdef M_MULTIBUS_CAN

#define mDATCnmReadTimeToTreatABusOffInTick(IdCan)\
        (DATCnmTableROMTimeToTreatABusOffInTick[IdCan])

// one supervised bus
#define mDATCnmLireCanalCan(SourceHandle) (cDATCdlIdCanalCan0)
//else:
//  #define mDATCnmLireCanalCan(SourceHandle) DATCnmTableCanauxCan[SourceHandle]
#endif

//------------------------------------------------------------------------------
// Exported type
//
// typedef Expression tLAYCmpTypeName;
//------------------------------------------------------------------------------

//typedef tDATCilSourceHandle tDATCnmSourceHandle;
typedef U8 tDATCnmSourceHandle;
typedef U8 tDATCnmStopTimeoutInTick;
typedef U8 tDATCnmStatus;
#ifndef SUPERVISION_OFF
typedef U8 tDATCnmFlagStatus;
typedef U16 tJudgementTime2Counter;

typedef struct
{
    tDATCnmFlagStatus      DATFlagStatus;
    tJudgementTime2Counter JudgementTime2Counter;
} tCANFaultStucture;
#endif
// The structure of the byte DATFlagStatus is as following :
//  Bit 7 : Current_FaultStatus
//  Bit 6 : Confirmed_FaultStauts
//  Bit 5 : SourceIsMonitored
//  Bit 4 : Judgement Time T2 counter is activated
//  Bit 3 : Fault Counter can decreased
//  Bit 2 : not used
//  Bit 1 : not used
//  Bit 0 : not used

//------------------------------------------------------------------------------
// Exported data
//
// extern  tType   u8LAYCmpVariableName;
// extern  tType*  ps32LAYCmpVariableName; 
//------------------------------------------------------------------------------
#ifndef SUPERVISION_OFF
extern tCANFaultStucture DATCnmCANFaultStatus[cDATCnmNbrCANStatus];
#endif

#ifdef M_MULTIBUS_CAN
extern tDATCdlIdCanalCan volatile DATCnmBusOffDetected;
#else
extern BOOL volatile DATCnmBusOffDetected;
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
#ifdef M_MULTIBUS_CAN

extern void DATCnmStopCom(tDATCdlIdCanalCan IdCanalCan);
extern void DATCnmStartCom(tDATCdlIdCanalCan IdCanalCan);
extern void DATCnmRAZFaultCounter(tDATCdlIdCanalCan IdCanalCan);
  #ifndef SUPERVISION_OFF
extern void DATCnmManagementReinitialization(tDATCdlIdCanalCan IdCanalCan);
extern void DATCnmDecreaseIsAuthorized(tDATCdlIdCanalCan IdCanalCan);
extern void DATCnmDecreaseIsNotAuthorized(tDATCdlIdCanalCan IdCanalCan);
  #endif
extern tDATCnmStatus DATCnmGetNetworkState(tDATCdlIdCanalCan IdCanalCan);

#else

extern void DATCnmStopCom(void);
extern void DATCnmStartCom(void);
extern void DATCnmRAZFaultCounter(void);
  #ifndef SUPERVISION_OFF
extern void DATCnmManagementReinitialization(void);
extern void DATCnmDecreaseIsAuthorized(void);
extern void DATCnmDecreaseIsNotAuthorized(void);
  #endif
extern tDATCnmStatus DATCnmGetNetworkState(void);

extern void DATCnmStartTrasmission(void);

#endif

extern void DATCnmTick(void);
extern void DATCnmInit (void);
extern void DATCnmIsMaintainActiveSleepState(void);

extern	U8	DATCnmGetCANControllerStatus(void);

#endif

