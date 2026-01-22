
//------------------------------------------------------------------------------
// Body Identification
//------------------------------------------------------------------------------
#define DAT_CNM  "DAT_CNM"

//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//
// #include <system_file_name.h>
// #include "project_file_name.h"
//------------------------------------------------------------------------------

#include "DAT_CNM.h"

//------------------------------------------------------------------------------
// Local constants
//
// #define cConstantName   ((tType) ConstantValue)
//------------------------------------------------------------------------------
#ifndef SUPERVISION_OFF
#define cNbrCANNode cDATCil_NbSources

#define cDATCnmTimeToTreatABusOff  ((U16)5000)//because this macro can not generated automatically, so I add it by hand

#define cResetAfterBusOffCounterInTick mDATCnmConvertTimeMsToTickCAN(cDATCnmTimeToTreatABusOff)
#endif

//------------------------------------------------------------------------------
// Local macros
//
// #define mMacroName   (MacroDefinition)
//------------------------------------------------------------------------------
#ifdef _QAC_
  #define mDATCnmDisableIT() (NOP())
  #define mDATCnmEnableIT()  (NOP())
#else

#ifdef TOSDisableOSInterrupts
  #define mDATCnmDisableIT()\
  TOSDisableOSInterrupts() // New version of TOS_ORD (TOS.h Rev 1.13)
#else
  #define mDATCnmDisableIT()\
  TOSDisableAllInterupts() // Old version of TOS_ORD (TOS.h Rev 1.12)
#endif

#ifdef TOSEnableOSInterrupts
  #define mDATCnmEnableIT()\
  TOSEnableOSInterrupts() // New version of TOS_ORD (TOS.h Rev 1.13)
#else
  #define mDATCnmEnableIT()\
  TOSEnableAllInterupts() // Old version of TOS_ORD (TOS.h Rev 1.12)
#endif
#endif

//------------------------------------------------------------------------------
// Local types
//
// typedef Expression    tTypeName;
//------------------------------------------------------------------------------
#ifndef cDATCdl_NbCanauxCanNonType
  #define cDATCdl_NbCanauxCanNonType cDATCdl_NbCanauxCan
#endif
#if cDATCdl_NbCanauxCanNonType <= 8 
typedef U8 tDATCnmFlagIdCanalCan;
#else
    #if cDATCdl_NbCanauxCanNonType <= 16
typedef U16 tDATCnmFlagIdCanalCan;
    #else
        #if cDATCdl_NbCanauxCanNonType <= 32
typedef U32 tDATCnmFlagIdCanalCan;
        #else
            #error "Nombre de bus CAN trop important"
        #endif
    #endif
#endif

// -----------------------------------------------------------------------------
// Local data
//
// static  tType   u8VariableName;  
// static  tType*  pu8VariableName; 
//------------------------------------------------------------------------------
static tTOSAlarm  AlarmCANTreatment;

#ifdef WAKE_BY_CAN
#ifdef M_MULTIBUS_CAN
static tDATCdlIdCanalCan  DATCnmWakeUpRequest;
#else
static BOOL  DATCnmWakeUpRequest;
#endif
#endif

#ifdef M_MULTIBUS_CAN

#ifndef SUPERVISION_OFF
static tDATCdlIdCanalCan   DecreaseIsAuthorized;
// The Max Time between each Reset is 255*cDATCdlTickMs
static U16 ResetAfterBusOffCounter[cDATCdl_NbCanauxCan];
#endif
#if cDATCdl_NbCanauxCanNonType == 2
static U16 ResetAfterBusOffCounter[cDATCdl_NbCanauxCan] = {cCAN0BusOffRecoveryMs, cCAN1BusOffRecoveryMs};
#elif cDATCdl_NbCanauxCanNonType == 3
static U16 ResetAfterBusOffCounter[cDATCdl_NbCanauxCan] = {cCAN0BusOffRecoveryMs, cCAN1BusOffRecoveryMs, cCAN2BusOffRecoveryMs};
static U16 BusOffRecoverTime[cDATCdl_NbCanauxCan];
static U8 BusOffRecovering[cDATCdl_NbCanauxCan];		/* 总线恢复中 */
static U8 BusOffRecoveringTime[cDATCdl_NbCanauxCan];	/* 总线恢复时间 */
#elif cDATCdl_NbCanauxCanNonType == 4
static U16 ResetAfterBusOffCounter[cDATCdl_NbCanauxCan] = {cCAN0BusOffRecoveryMs, cCAN1BusOffRecoveryMs, cCAN2BusOffRecoveryMs, cCAN3BusOffRecoveryMs};
#elif cDATCdl_NbCanauxCanNonType == 5
static U16 ResetAfterBusOffCounter[cDATCdl_NbCanauxCan] = {cCAN0BusOffRecoveryMs, cCAN1BusOffRecoveryMs, cCAN2BusOffRecoveryMs, cCAN3BusOffRecoveryMs, cCAN4BusOffRecoveryMs};
#elif cDATCdl_NbCanauxCanNonType == 6
static U16 ResetAfterBusOffCounter[cDATCdl_NbCanauxCan] = {cCAN0BusOffRecoveryMs, cCAN1BusOffRecoveryMs, cCAN2BusOffRecoveryMs, cCAN3BusOffRecoveryMs, cCAN4BusOffRecoveryMs, cCAN5BusOffRecoveryMs};
#elif cDATCdl_NbCanauxCanNonType == 7
static U16 ResetAfterBusOffCounter[cDATCdl_NbCanauxCan] = {cCAN0BusOffRecoveryMs, cCAN1BusOffRecoveryMs, cCAN2BusOffRecoveryMs, cCAN3BusOffRecoveryMs, cCAN4BusOffRecoveryMs, cCAN5BusOffRecoveryMs, cCAN6BusOffRecoveryMs};
#elif cDATCdl_NbCanauxCanNonType == 8
static U16 ResetAfterBusOffCounter[cDATCdl_NbCanauxCan] = {cCAN0BusOffRecoveryMs, cCAN1BusOffRecoveryMs, cCAN2BusOffRecoveryMs, cCAN3BusOffRecoveryMs, cCAN4BusOffRecoveryMs, cCAN5BusOffRecoveryMs, cCAN6BusOffRecoveryMs, cCAN7BusOffRecoveryMs};

#endif



static tDATCnmStatus DATCnmStatus[cDATCdl_NbCanauxCan];

//Started CAN channel table
static tDATCdlIdCanalCan DATCnmCanXDemarre;
static tDATCnmStopTimeoutInTick DATCnmStopTimeout[cDATCdl_NbCanauxCan];

#else

#ifndef SUPERVISION_OFF
static BOOL   DecreaseIsAuthorized;
// The Max Time between each Reset is 255*cDATCdlTickMs
#ifndef ResetOnBusOffUnique
static U16     ResetAfterBusOffCounter;
#endif
#endif

static tDATCnmStatus DATCnmStatus;
static tDATCnmStopTimeoutInTick  DATCnmStopTimeout;
#endif

#ifdef M_MULTIBUS_CAN
static volatile U8 u8ResetOnBusOff;
//Multibus will use bResetOnBusOff, I have to add it by hand
static volatile BOOL bResetOnBusOff;
#else
#ifndef SUPERVISION_OFF
static volatile BOOL bResetOnBusOff;
#endif
#endif

static volatile	U8  CANControllerStatusBuf[cMaxMCUCANChaNum];		//this var is modified by interrupt and read by lap can;init is needed or not?

BOOL   sbIsBatProtect;//是否使能电源管理，如果仪表进入电源管理状态，则停止CAN模块，冻结所有当前报文值。banfy
//------------------------------------------------------------------------------
// Constant local data
//
// static const tType  VariableName;
//------------------------------------------------------------------------------
#ifndef SUPERVISION_OFF
static const U16  InitValueOfJudgementTime2InMs[cDATCnmNbrCANStatus] = mDATCnmInitJudgementTime2InTick();
#endif

#ifdef M_MULTIBUS_CAN
//Restriction: for the moment this component is able to supervise only one CAN Bus
// (identified by bus number "0" in DAT_Cdl
//static const tDATCdlIdCanalCan DATCnmTableCanauxCan[cDATCil_NbSources+cDATCdl_NbCanauxCan] = mDATCnmInitTableROMChannelCan();
  #ifndef SUPERVISION_OFF

static const U8 TypeResetBusOff[cDATCdl_NbCanauxCan] = mDATCnmInitTableTypeResetBusOff();

static const U8 DATCnmTableROMTimeToTreatABusOffInTick[cDATCdl_NbCanauxCan] = mDATCdlInitTableROMTimeToTreatABusOff();
  #endif
#endif

//------------------------------------------------------------------------------
// Exported data
//
// tType   u8LAYCmpVariableName; (LAY: 3 characters to identify the layer)
// tType*  pu8LAYCmpVariableName;(Cmp: 3 characters to identify the component)
//------------------------------------------------------------------------------
#ifndef SUPERVISION_OFF
tCANFaultStucture DATCnmCANFaultStatus[cDATCnmNbrCANStatus];
#endif

#ifdef M_MULTIBUS_CAN
tDATCdlIdCanalCan volatile DATCnmBusOffDetected;
#else
BOOL volatile DATCnmBusOffDetected;
#endif
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
static void TreatmentSucceededAction(tDATCilSourceHandle SourceHandle);
static void TreatmentFailedAction(tDATCilSourceHandle SourceHandle);
#endif

#ifdef M_MULTIBUS_CAN
  #ifndef SUPERVISION_OFF
static void SetUpDefaultValues(tDATCdlIdCanalCan IdCanalCan);
  #endif
#else
  #ifndef SUPERVISION_OFF
static void SetUpDefaultValues(void);
  #endif
#endif

#ifndef SUPERVISION_OFF
static void FaultStoring (tDATCilSourceHandle SourceHandle, BOOL StatutOk);
#endif

//==============================================================================
//=========================== LOCAL FUNCTIONS ==================================
//==============================================================================

// ***************************************************************************
//==============================================================================
// DESCRIPTION : Management of the fault storing
//
// PARAMETERS (Type,Name,Min,Max) : tDATCilSourceHandle : Handle of a key frame (source identifier)
//                                  BOOL : status of the source
//            SourceHandle          Handle of a key frame
//            StatutOk              if StatutOK = cTrue then the fault counter is decreased
//                                  if StatutOK = cFalse then the fault counter is increased
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
#ifndef SUPERVISION_OFF
static void FaultStoring (tDATCilSourceHandle SourceHandle, BOOL StatutOk)
{
    U8  CounterValue;

    #ifdef M_MULTIBUS_CAN
    tDATCdlIdCanalCan IdCan;
    IdCan = mDATCnmLireCanalCan(SourceHandle);
    #endif

    if (StatutOk == cTrue)
    {
        #ifdef M_MULTIBUS_CAN
        if ( (DecreaseIsAuthorized & ((tDATCdlIdCanalCan)(((tDATCdlIdCanalCan)0x01UL)<< IdCan ))) != ((tDATCdlIdCanalCan)0))
        #else
        if (DecreaseIsAuthorized == cTrue)
        #endif
        {
            if (mDATCnmReadCounterDecreaseInThisTripStatus(SourceHandle) == cFalse)
            {
            #ifdef M_MULTIBUS_CAN
                mDATCnmReadNVM(IdCan, SourceHandle);
            #else
                CounterValue = mDATCnmReadNVM(SourceHandle);
            #endif
                if ( CounterValue > cDATCnmDecThres)
                {
                    #ifdef M_MULTIBUS_CAN
                    mDATCnmWriteNVM(IdCan, (CounterValue - cDATCnmDecM), SourceHandle);
                    #else
                    mDATCnmWriteNVM((CounterValue - cDATCnmDecM), SourceHandle);
                    #endif
                    // The counter shall be permitted only once per trip
                    mDATCnmSetCounterDecreaseInThisTripStatus(SourceHandle);
                }
                else
                {
                    // The Counter can not be decreased down to the threshold value DecThres
                }
            }
            else
            {
                // The fault counter has been already decreased in this trip
                // So the fault counter does not change
            }
        }
        else
        {
            // Level 3 is NOT active
            // The fault counter can not be decreased
        }
    }
    else
    {
        // The fault is detected

        // Set the confirmed fault status
        mDATCnmSetConfirmedFaultStatus(SourceHandle);

        // The fault counter is set to VAlMax
        #ifdef M_MULTIBUS_CAN
        mDATCnmWriteNVM(IdCan, cDATCnmValMax, SourceHandle);
        #else
        mDATCnmWriteNVM(cDATCnmValMax, SourceHandle);
        #endif
        // The counter shall be permitted only once per trip
        mDATCnmSetCounterDecreaseInThisTripStatus(SourceHandle);
    }
}
#endif

//==============================================================================
// DESCRIPTION : Treatment of a succeded action (transmission or reception of a key frame)
//
// PARAMETERS (Type,Name,Min,Max) : tDATCilSourceHandle :  Handle of a key frame (source identifier)
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
#ifndef SUPERVISION_OFF
static void TreatmentSucceededAction (tDATCilSourceHandle SourceHandle)
{
    // Reset the falg concerning the Bus Off statuts
    #ifdef M_MULTIBUS_CAN

    tDATCdlD_UUTxHandle BusOffHandle;

    BusOffHandle = ((tDATCdlD_UUTxHandle)(cDATCil_NbSources + mDATCnmLireCanalCan(SourceHandle)));

    //Check if at least one CAN cell reset has been done on bus off event

    //Disable Bus off Interrupt to avoid real time issue
    LDBControl(cLDBChannelCan0, cLDBCanDisableBus_offCallBack);
    LDBControl(cLDBChannelCan1, cLDBCanDisableBus_offCallBack);

    if( (u8ResetOnBusOff & ((tDATCdlIdCanalCan)(((tDATCdlIdCanalCan)0x01UL)<<mDATCnmLireCanalCan(SourceHandle)))) == 0)
    { 
        mDATCnmClearCurrentFaultStatus(BusOffHandle);
        mDATCnmClearConfirmedFaultStatus(BusOffHandle);
        mDATCnmClearJudgementTime2CounterStatus(BusOffHandle);
        //reset the Judgement Time 2 BusOff Counter

        DATCnmCANFaultStatus[BusOffHandle].JudgementTime2Counter = InitValueOfJudgementTime2InMs[BusOffHandle];
        // Reset the Restart CAN communication hardware timer
    #else
    //Check if at least one CAN cell reset has been done on bus off event

    //Disable Bus off Interrupt to avoid real time issue
    LDBControl(cLDBChannelCan, cLDBCanDisableBus_offCallBack);

    if(bResetOnBusOff == cFalse)
    {
        mDATCnmClearCurrentFaultStatus(cDATCnmBusOff);
        mDATCnmClearConfirmedFaultStatus(cDATCnmBusOff);
        mDATCnmClearJudgementTime2CounterStatus(cDATCnmBusOff);
        //reset the Judgement Time 2 BusOff Counter
        DATCnmCANFaultStatus[cDATCnmBusOff].JudgementTime2Counter = InitValueOfJudgementTime2InMs[cDATCnmBusOff];
        // Reset the Restart CAN communication hardware timer
    #endif

    // Management of the fault storing for the Bus Off Status
    // The Bus Off is always monitored
    #ifdef M_MULTIBUS_CAN
        ResetAfterBusOffCounter[mDATCnmLireCanalCan(SourceHandle)] = cResetAfterBusOffCounterInTick;

        DATCnmBusOffDetected &= ((tDATCdlIdCanalCan)~(((tDATCdlIdCanalCan)0x01UL)<<(mDATCnmLireCanalCan(SourceHandle))));

        FaultStoring( ((tDATCilSourceHandle)(cDATCil_NbSources + mDATCnmLireCanalCan(SourceHandle))), cTrue);
    #else
    #ifndef ResetOnBusOffUnique
        ResetAfterBusOffCounter = cResetAfterBusOffCounterInTick;
    #endif
        FaultStoring(cDATCnmBusOff, cTrue);

        DATCnmBusOffDetected = cFalse;
    #endif
    }
    else
    {
        //For QAC
    }

    //Enable Bus off Interrupt
    #ifdef M_MULTIBUS_CAN
    LDBControl(cLDBChannelCan0, cLDBCanEnableBus_offCallBack);
    LDBControl(cLDBChannelCan1, cLDBCanEnableBus_offCallBack);
    #else
    LDBControl(cLDBChannelCan, cLDBCanEnableBus_offCallBack);
    #endif

    // Reset the Fault Flag concerning the ECU defined by the SourceHandle
    mDATCnmClearCurrentFaultStatus(SourceHandle);
    mDATCnmClearConfirmedFaultStatus(SourceHandle);
    mDATCnmClearJudgementTime2CounterStatus(SourceHandle);
    // Reset the Judgement Time 2 Source Counter
    DATCnmCANFaultStatus[SourceHandle].JudgementTime2Counter = InitValueOfJudgementTime2InMs[SourceHandle];

    // Management of the fault storing for the source defined by SourceHandle
    FaultStoring (SourceHandle, cTrue);
}
#endif

//==============================================================================
// DESCRIPTION : Treatment of a failed action (transmission or reception of a key frame)
//
// PARAMETERS (Type,Name,Min,Max) : tDATCilSourceHandle :  Handle of a key frame (source identifier)
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
#ifndef SUPERVISION_OFF
static void TreatmentFailedAction (tDATCilSourceHandle SourceHandle)
{
    // The current fault status is set
    mDATCnmSetCurrentFaultStatus(SourceHandle);

    //Warning : new RNO 36-02-030/--A specification
    //the confirmed fault status is set only if the fault is not masked
    if (mDATCnmReadMonitoringStatus(SourceHandle) == cTrue)
    {
        // The source is monitored
        // Set the signal indicated that the Judgement Time 2 Tempo is launched
        mDATCnmSetJudgementTime2CounterStatus(SourceHandle);
    }
    else
    {
        // The source is NOT monitored
        // The fault counter will not change
    }
}
#endif

//==============================================================================
// DESCRIPTION : Initialize the Fault status  when the ECU enters
//               in "applivative state" ( when StartCom is activated)
//
// PARAMETERS (Type,Name,Min,Max) : tDATCdlIdCanalCan : Can Channel identifier
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
#ifndef SUPERVISION_OFF
#ifdef M_MULTIBUS_CAN
static void SetUpDefaultValues(tDATCdlIdCanalCan IdCanalCan)
#else
static void SetUpDefaultValues(void)
#endif
{
    U8  I;

    #ifdef M_MULTIBUS_CAN
    U8 BusOffSourceHanlde;
    
    BusOffSourceHanlde = cDATCil_NbSources + IdCanalCan;
    
    //Only one CAN bus can be supervised for the moment!
    mLIBassert(IdCanalCan == cDATCdlIdCanalCan0);

    //reset the Judgement Time 2 BusOff Counter
    DATCnmCANFaultStatus[BusOffSourceHanlde].JudgementTime2Counter = InitValueOfJudgementTime2InMs[BusOffSourceHanlde];
    ResetAfterBusOffCounter[IdCanalCan] = cResetAfterBusOffCounterInTick;

    mDATCnmClearCurrentFaultStatus(BusOffSourceHanlde);
    mDATCnmClearConfirmedFaultStatus(BusOffSourceHanlde);
    mDATCnmClearJudgementTime2CounterStatus(BusOffSourceHanlde);
    // The Bus Off Status is monitored
    mDATCnmSetMonitoringStatus(BusOffSourceHanlde);
    DATCnmManagementReinitialization(IdCanalCan);
    #else

    //reset the Judgement Time 2 BusOff Counter
    DATCnmCANFaultStatus[cDATCnmBusOff].JudgementTime2Counter = InitValueOfJudgementTime2InMs[cDATCnmBusOff];
    #ifndef ResetOnBusOffUnique
    ResetAfterBusOffCounter = cResetAfterBusOffCounterInTick;
    #endif
    mDATCnmClearCurrentFaultStatus(cDATCnmBusOff);
    mDATCnmClearConfirmedFaultStatus(cDATCnmBusOff);
    mDATCnmClearJudgementTime2CounterStatus(cDATCnmBusOff);
    // The Bus Off Status is monitored
    mDATCnmSetMonitoringStatus(cDATCnmBusOff);
    DATCnmManagementReinitialization();

    #endif

    // The current and confirmed flag of bus node are set
    // No CAN nodes are monitored
    for (I=0 ; I< cNbrCANNode; I++)
    {

        //if(IdCan == mDATCnmLireCanalCan(I))
        //{
        //  mDATCnmSetCurrentFaultStatus(I);
        //  mDATCnmSetConfirmedFaultStatus(I);
        //  mDATCnmClearMonitoringStatus(I);
        //}

        //Un seul bus supervise:
        mDATCnmSetCurrentFaultStatus(I);
        mDATCnmClearConfirmedFaultStatus(I);
        mDATCnmClearMonitoringStatus(I);
    }

    //Mute defect linked to this bus
    //  mDATCnmSetCurrentFaultStatus(IdCan);
    //  mDATCnmSetConfirmedFaultStatus(IdCan);
    //  mDATCnmClearMonitoringStatus(IdCan);


}
#endif


//==============================================================================
//=========================== EXPORTED FUNCTIONS ===============================
//==============================================================================

//==============================================================================
// DESCRIPTION : Treatment of the network information from Interaction-Presentation Layer
//
// PARAMETERS (Type,Name,Min,Max) : tDATCilSourceHandle : Defined the monitored source
//                                  BOOL : Defined the status of action (transmission
//                                  or reception of a key frame)
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
#ifndef SUPERVISION_OFF
void DATCnmNetworkInfos(tDATCilSourceHandle SourceHandle, BOOL StatutOk)
{
    if (StatutOk == cTrue)
    {
        // an action has been succeeded before the end of the judgement time 1 associated
        // to this source
        TreatmentSucceededAction(SourceHandle);
    }
    else
    {
        // The transmission judgement time 1 associated to this source has expired without
        // a succeeded action (transmission or reception)
        TreatmentFailedAction(SourceHandle);
    }
}
#endif

//==============================================================================
// DESCRIPTION : Initialize the fault status before enabling a fault category
//
// PARAMETERS (Type,Name,Min,Max) : tDATCdlIdCanalCan : CAN channel identifier
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
#ifndef SUPERVISION_OFF

#ifdef M_MULTIBUS_CAN
void DATCnmManagementReinitialization(tDATCdlIdCanalCan IdCanalCan)
#else
void DATCnmManagementReinitialization(void)
#endif
{
    tDATCnmSourceHandle  I;

    // The current status do not change

    // The confirmed status of CAN Nodes is reinitialized
    // The judgement time 2 counters of CAN Nodes are cleared and desactivated
    #ifdef M_MULTIBUS_CAN
    IdCanalCan = IdCanalCan; //to avoid a warning
    //One supervised bus for the moment

    for (I=0; I < (cDATCnmNbrCANStatus); I++)
    {
        mDATCnmClearConfirmedFaultStatus(I);
        mDATCnmClearJudgementTime2CounterStatus(I);
        DATCnmCANFaultStatus[I].JudgementTime2Counter = InitValueOfJudgementTime2InMs[I];
    }

    //for (I= (cDATCdl_NbCanauxCan -1); I < (cDATCnmNbrCANStatus-cDATCdl_NbCanauxCan); I++)
    //{
    //if(IdCanalCan==mDATCnmLireCanalCan(I))
    //{
    //  mDATCnmClearConfirmedFaultStatus(I);
    //  mDATCnmClearJudgementTime2CounterStatus(I);
    //  DATCnmCANFaultStatus[I].JudgementTime2Counter = InitValueOfJudgementTime2InMs[I];
    //}
    //}
    //Mute defect linked to this bus
    //  mDATCnmClearConfirmedFaultStatus(IdCanalCan);
    //  mDATCnmClearJudgementTime2CounterStatus(IdCanalCan);
    //  DATCnmCANFaultStatus[IdCanalCan].JudgementTime2Counter = InitValueOfJudgementTime2InMs[IdCanalCan];

    #else
    for (I=0; I < (cDATCnmNbrCANStatus); I++)
    {
        mDATCnmClearConfirmedFaultStatus(I);
        mDATCnmClearJudgementTime2CounterStatus(I);
        DATCnmCANFaultStatus[I].JudgementTime2Counter = InitValueOfJudgementTime2InMs[I];
    }
    #endif
    // The Bus Off Status does not change
}

#endif

//==============================================================================
// DESCRIPTION : define the Tick CAN for the other CAN software components
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void DATCnmTick(void)
{

    #ifndef SUPERVISION_OFF
    tDATCnmSourceHandle I;
    #endif

    #ifdef M_MULTIBUS_CAN
    tDATCnmFlagIdCanalCan IdCan;
    #ifdef WAKE_BY_CAN
    tDATCnmFlagIdCanalCan Mask;
    #endif
    #endif

    #ifndef SUPERVISION_OFF
    // Management of the Judgement Time 2 Counters
    for( I = 0; I < cDATCnmNbrCANStatus; I++)
    {
        if (  (mDATCnmReadJudgementTime2CounterStatus(I) == cTrue) &&
                (DATCnmCANFaultStatus[I].JudgementTime2Counter != ((U8)0x00UL)) )
        {
            DATCnmCANFaultStatus[I].JudgementTime2Counter --;
            if (DATCnmCANFaultStatus[I].JudgementTime2Counter == ((U8)0x00UL) )
            {
                // Management of the fault storing
                FaultStoring ( (tDATCilSourceHandle) I, cFalse);
                // Stop the Judgement time 2 counter.
                mDATCnmClearJudgementTime2CounterStatus((tDATCilSourceHandle) I);
            }
            else
            {
                // The Judgement Time 2 is not finished
            }
        }
        else
        {
            // The Judgement Time 2 Counter is not activated
        }
    }
    #endif

    #ifdef WAKE_BY_CAN
    #ifdef M_MULTIBUS_CAN
    if(DATCnmWakeUpRequest != 0)
    {
        IdCan = ((tDATCnmFlagIdCanalCan) (cDATCdl_NbCanauxCan - ((tDATCnmFlagIdCanalCan)0x01UL)));
        Mask  = ((tDATCnmFlagIdCanalCan)(((tDATCnmFlagIdCanalCan)1)<< ( (tDATCnmFlagIdCanalCan) (cDATCdl_NbCanauxCan-((tDATCnmFlagIdCanalCan)1))) ));
        //Search Id CAN
        while ( ( (DATCnmWakeUpRequest) & Mask) == 0  )
        {
            Mask >>= 1;
            IdCan--;
        }
        //Limit to 8 can channel, and protect against overflow
        mLIBassert(IdCan < 8);

        mDATCnmDisableIT();
        DATCnmWakeUpRequest &= ((tDATCnmFlagIdCanalCan)(~(Mask))); // Clear the request
        mDATCnmEnableIT();
        if(DATCnmStatus[IdCan] != cDATCmnStarted)
        {
            DATCnmStatus[IdCan] = cDATCmnWakeUpRequest;
            //2019年1月10日 14:59:20，这里是发送控制，表示接收到唤醒报文，激活LAP_CAN模块
            TOSSendControl(cTOSControlLAPCanNotify);
        }
    }
    #else
    if(DATCnmWakeUpRequest != cFalse)
    {
        mDATCnmDisableIT();
        DATCnmWakeUpRequest = cFalse;
        mDATCnmEnableIT();

        if(DATCnmStatus != cDATCmnStarted)
        {
            DATCnmStatus = cDATCmnWakeUpRequest;
            //zjb add. error find by debug. because there is no NM .so not necessary to start LAP_CAN
            //Wake Up Request notify to the LAP
        //    TOSSendControl(cTOSControlLAPCanNotify);
        }
    }
    #endif
    else
    {
    #endif
        // Bus Off Recovery
        #ifdef M_MULTIBUS_CAN
        //Disable Bus off Interrupt to avoid real time issue
        //LDBControl(cLDBChannelCan0, cLDBCanDisableBus_offCallBack);
        //LDBControl(cLDBChannelCan1, cLDBCanDisableBus_offCallBack);

        for(IdCan = 0; IdCan < cDATCdl_NbCanauxCan ; IdCan++)
        {
            #ifndef SUPERVISION_OFF
            if(TypeResetBusOff[IdCan] == cDATCnmUnique)
            {
            #endif

            //zjb add 2017.01.21 multiply can process
			if( (DATCnmBusOffDetected & (((tDATCdlIdCanalCan)0x01UL)<<IdCan)) != (tDATCdlIdCanalCan)0)
			{
				switch(IdCan)
				{

				case 0U:
					#ifdef cLDBChannelCan0
					LDBControl(cLDBChannelCan0, cLDBCanDisableBus_offCallBack);
					mSERControl(DTCOccur, eDTCFunCom_CanFault);
                    #endif
					break;

				case 1U:
					#ifdef cLDBChannelCan1
					LDBControl(cLDBChannelCan1, cLDBCanDisableBus_offCallBack);
					//mSERControl(DTCOccur, eDTCFunCom_DCANComFault);
					#endif
					break;

				case 2U:
					#ifdef cLDBChannelCan2
					LDBControl(cLDBChannelCan2, cLDBCanDisableBus_offCallBack);
					//mSERControl(DTCOccur, eDTCFunCom_ICANComFault);
					#endif
					break;

				case 3U:
					#ifdef cLDBChannelCan3
					LDBControl(cLDBChannelCan3, cLDBCanDisableBus_offCallBack);
					#endif
					break;

				case 4U:
					#ifdef cLDBChannelCan4
					LDBControl(cLDBChannelCan4, cLDBCanDisableBus_offCallBack);
					#endif
					break;

				case 5U:
					#ifdef cLDBChannelCan5
					LDBControl(cLDBChannelCan5, cLDBCanDisableBus_offCallBack);
					#endif
					break;

				case 6U:
					#ifdef cLDBChannelCan6
					LDBControl(cLDBChannelCan6, cLDBCanDisableBus_offCallBack);
					#endif
					break;

				case 7U:
					#ifdef cLDBChannelCan7
					LDBControl(cLDBChannelCan7, cLDBCanDisableBus_offCallBack);
					#endif
					break;


				default:
					break;
				}

				if (ResetAfterBusOffCounter[IdCan] == 0U)
				{
					DATCnmBusOffDetected &= ((tDATCdlIdCanalCan)~(((tDATCdlIdCanalCan)0x01UL)<<IdCan));
					u8ResetOnBusOff &= ((tDATCdlIdCanalCan)~(((tDATCdlIdCanalCan)0x01UL)<<IdCan));
					DATCdl_D_Reset(IdCan);
					BusOffRecovering[IdCan] = 1u;			/* 总线恢复中 */
					BusOffRecoveringTime[IdCan] = 0;		/* 总线恢复中清零 */
					if (BusOffRecoverTime[IdCan] < 5)		/* 总线恢复次数<5 */
					{
						BusOffRecoverTime[IdCan] ++;
						ResetAfterBusOffCounter[IdCan] = 10U;
					}
					else
					{
						ResetAfterBusOffCounter[IdCan] = 100U;
					}
				}
			}
			else
			{
			    switch(IdCan)
                {
                case 0U:
                    #ifdef cLDBChannelCan0
                    mSERControl(DTCDisappear, eDTCFunCom_CanFault);
                    #endif
                    break;

                default:
                    //其他can通道故障暂时不报DTC
                    break;
                }
			}

			if (BusOffRecovering[IdCan] == 1u)
			{
				BusOffRecoveringTime[IdCan] ++;
				if (BusOffRecoveringTime[IdCan] > 10)
				{
					BusOffRecovering[IdCan] = 0u;		/* 100ms后，busoff 认为本次恢复成功*/
					BusOffRecoverTime[IdCan] = 0;		/* 恢复成功后初始化恢复次数 */
				}
			}

			if(ResetAfterBusOffCounter[IdCan] != 0U)
			{
				ResetAfterBusOffCounter[IdCan]--;
			}
			else
			{
				//
			}
            #ifndef SUPERVISION_OFF
            }
            else
            {
            	/*
                if (ResetAfterBusOffCounter[IdCan] == 0)
                {
                    if( (DATCnmBusOffDetected & (((tDATCdlIdCanalCan)0x01UL)<<IdCan)) != (tDATCdlIdCanalCan)0)
                    {
                        if (mDATCnmReadCurrentFaultStatus((cDATCil_NbSources+IdCan)) == cFalse)
                            // No bus off treatment in progress
                        {
                            // Set the current fault status
                            mDATCnmSetCurrentFaultStatus((cDATCil_NbSources+IdCan));
                            // Activate the judgement Time 2 BusOff counter
                            mDATCnmSetJudgementTime2CounterStatus( (cDATCil_NbSources+IdCan) ); // il est initialise
                        }
                        // init of the Timer
                        ResetAfterBusOffCounter[IdCan] = mDATCnmReadTimeToTreatABusOffInTick(IdCan);

                        DATCnmBusOffDetected &= ((tDATCdlIdCanalCan)~(((tDATCdlIdCanalCan)0x01UL)<<IdCan));
                        // Reconfigure and restart the CAN communcition hardware through the Data Link Layer
                        u8ResetOnBusOff &= ((tDATCdlIdCanalCan)~(((tDATCdlIdCanalCan)0x01UL)<<IdCan));
                        DATCdl_D_Reset(IdCan);

                    }
                }
                else
                {
                    ResetAfterBusOffCounter[IdCan]--;
                }
				*/

                if( (DATCnmBusOffDetected & (((tDATCdlIdCanalCan)0x01UL)<<IdCan)) != (tDATCdlIdCanalCan)0)
                {
                    if (ResetAfterBusOffCounter[IdCan] == 0)
	                {
                        if (mDATCnmReadCurrentFaultStatus((cDATCil_NbSources+IdCan)) == cFalse)
                            // No bus off treatment in progress
                        {
                            // Set the current fault status
                            mDATCnmSetCurrentFaultStatus((cDATCil_NbSources+IdCan));
                            // Activate the judgement Time 2 BusOff counter
                            mDATCnmSetJudgementTime2CounterStatus( (cDATCil_NbSources+IdCan) ); // il est initialise
                        }
                        // init of the Timer
                        ResetAfterBusOffCounter[IdCan] = mDATCnmReadTimeToTreatABusOffInTick(IdCan);

                        DATCnmBusOffDetected &= ((tDATCdlIdCanalCan)~(((tDATCdlIdCanalCan)0x01UL)<<IdCan));
                        // Reconfigure and restart the CAN communcition hardware through the Data Link Layer
                        u8ResetOnBusOff &= ((tDATCdlIdCanalCan)~(((tDATCdlIdCanalCan)0x01UL)<<IdCan));
                        DATCdl_D_Reset(IdCan);

                    }
					else
	                {
	                    ResetAfterBusOffCounter[IdCan]--;
	                }
                }
				
            }
            #endif

            if( DATCnmStopTimeout[IdCan] != (tDATCnmStopTimeoutInTick)0 )
            {
                DATCnmStopTimeout[IdCan]--;

                if( DATCnmStopTimeout[IdCan] == (tDATCnmStopTimeoutInTick)0 )
                { //The CAN Cell can not be stopped
                    DATCnm_D_Confirm(IdCan, cDATCdlCtrlArreter, cFalse);
                }
            }
        }

        //LDBControl(cLDBChannelCan0, cLDBCanEnableBus_offCallBack);
        //LDBControl(cLDBChannelCan1, cLDBCanEnableBus_offCallBack);

        #else //===============================================================sigle CAN

        //Disable Bus off Interrupt to avoid real time issue
        LDBControl(cLDBChannelCan, cLDBCanDisableBus_offCallBack);
        #ifndef SUPERVISION_OFF
        #ifdef ResetOnBusOffUnique
        if(DATCnmBusOffDetected != cFalse)
        {
            DATCnmBusOffDetected = cFalse;
            bResetOnBusOff = cFalse;
            DATCdl_D_Reset();
        }
        #else
/*
//bus off recovery is not satisfied the spec,modified.

        if (ResetAfterBusOffCounter == 0)
        {
            if(DATCnmBusOffDetected != cFalse)
            {
                if (mDATCnmReadCurrentFaultStatus(cDATCnmBusOff) == cFalse)
                // No bus off treatment in progress
                {
                    // Set the current fault status
                    mDATCnmSetCurrentFaultStatus(cDATCnmBusOff);
                    // Activate the judgement Time 2 BusOff counter
                    mDATCnmSetJudgementTime2CounterStatus(cDATCnmBusOff);
                }
                // init of the Timer
                ResetAfterBusOffCounter = cResetAfterBusOffCounterInTick;
                DATCnmBusOffDetected = cFalse;
                // Reconfigure and restart the CAN communcition hardware through the Data Link Layer
                bResetOnBusOff = cFalse;
                DATCdl_D_Reset();
            }
        }
        else
        {
            ResetAfterBusOffCounter--;
        }
*/
		if(DATCnmBusOffDetected != cFalse)
		{		
			if (ResetAfterBusOffCounter == 0)
			{
				if (mDATCnmReadCurrentFaultStatus(cDATCnmBusOff) == cFalse)
				// No bus off treatment in progress
				{
					// Set the current fault status
					mDATCnmSetCurrentFaultStatus(cDATCnmBusOff);
					// Activate the judgement Time 2 BusOff counter
					mDATCnmSetJudgementTime2CounterStatus(cDATCnmBusOff);
				}
				// init of the Timer
				ResetAfterBusOffCounter = cResetAfterBusOffCounterInTick;
				#ifdef COMPILATION_NATIVE
				DATCnmBusOffDetected = cFalse; // For Simulation purpose only
				#endif
				//DATCnmBusOffDetected = cFalse; caution:only can be set to false when recovery sucess
				// Reconfigure and restart the CAN communcition hardware through the Data Link Layer
				//bResetOnBusOff = cFalse; caution:only can be set to false when recovery sucess
				DATCdl_D_Reset();
			}
			else
			{
				ResetAfterBusOffCounter--;
			}
			// can bus off notify
			if(TOSReadSignal(cTOSSignalCanBusOff))
			{
			    TOSSendControl(cTOSControlCanBusOff);
			}
			else
			{

			}
		}


        #endif

        #else
        if(DATCnmBusOffDetected != cFalse)
        {
            DATCnmBusOffDetected = cFalse;
            DATCdl_D_Reset();
        }
        #endif

        LDBControl(cLDBChannelCan, cLDBCanEnableBus_offCallBack);

        if( DATCnmStopTimeout != (tDATCnmStopTimeoutInTick)0 )
        {
            DATCnmStopTimeout--;

            if( DATCnmStopTimeout == (tDATCnmStopTimeoutInTick)0 )
            {   //The CAN Cell can not be stopped
                DATCnm_D_Confirm(cDATCdlCtrlArreter, cFalse);
            }
        }
        #endif

        DATCdlTick();
        DATCnlTick();
        #ifdef COMPOSANT_DAT_CTL_ON
        DATCtlTick();
        #endif
        DATCilTick();
        DATCplTick();

    #ifdef WAKE_BY_CAN
    }
    #endif

}



//==============================================================================
// DESCRIPTION : Start the CAN communication
//
// PARAMETERS (Type,Name,Min,Max) : tDATCdlIdCanalCan : CAN channel identifier
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
#ifdef M_MULTIBUS_CAN
void DATCnmStartCom(tDATCdlIdCanalCan IdCanalCan)
#else
void DATCnmStartCom(void)
#endif
{
    #ifdef M_MULTIBUS_CAN
    mLIBassert(DATCnmStatus[IdCanalCan] != cDATCmnNotInitialized);
        #ifndef SUPERVISION_OFF

        //One CAN bus can be supervised
        if( IdCanalCan == cDATCdlIdCanalCan0)
        {
            SetUpDefaultValues(cDATCdlIdCanalCan0);
            // Decrease of Fault Counter is not authorized
            DATCnmDecreaseIsNotAuthorized(cDATCdlIdCanalCan0);
        }
        #endif
    DATCpl_P_Init(IdCanalCan);
    DATCil_I_Init(IdCanalCan);
    #else
    mLIBassert(DATCnmStatus != cDATCmnNotInitialized);
    #ifndef SUPERVISION_OFF
    SetUpDefaultValues();

    // Decrease of Fault Counter is not authorized
    DATCnmDecreaseIsNotAuthorized();
    #endif
    DATCpl_P_Init();
    DATCil_I_Init();
    #endif

    #ifdef M_MULTIBUS_CAN
    if(DATCnmCanXDemarre == (tDATCdlIdCanalCan)0)
    {
        //  DATCtl_T_Init(); :To be call by ASDT management component
        //  (to active transport layer management)
        DATCnl_N_Init();
    }
    #else
        //  DATCtl_T_Init(); :To be call by ASDT management component
        //  (to active transport layer management)
    DATCnl_N_Init();
    #endif

    #ifdef M_MULTIBUS_CAN
    DATCdl_D_Init(IdCanalCan);
    DATCnmStopTimeout[IdCanalCan] = (tDATCnmStopTimeoutInTick)0;


    mDATCnmDisableIT();
    DATCnmBusOffDetected &= ((tDATCdlIdCanalCan)~(((tDATCdlIdCanalCan)0x01UL)<<IdCanalCan));
    u8ResetOnBusOff &= ((tDATCdlIdCanalCan)~(((tDATCdlIdCanalCan)0x01UL)<<IdCanalCan));
    mDATCnmEnableIT();
    #else
    DATCdl_D_Init();

    mDATCnmDisableIT();
    DATCnmBusOffDetected = cFalse;
    #ifndef SUPERVISION_OFF
    bResetOnBusOff = cFalse;
    #endif
    mDATCnmEnableIT();

    DATCnmStopTimeout = (tDATCnmStopTimeoutInTick)0;
    #endif

    #ifdef M_MULTIBUS_CAN
    if( DATCnmCanXDemarre == (tDATCdlIdCanalCan)0)
    {
    #endif

        //Start Com must be precedeed by an Init or Stop control
        // Activate the CAN Alarm
        AlarmCANTreatment.TaskID = cTOSTaskID_CanTraitements;

        TOSSetRelAlarm( &AlarmCANTreatment, ((U8)0UL), mTOSConvMsEnTickAlarm(cDATCdlTickMs) );

    #ifdef M_MULTIBUS_CAN
    }
    DATCnmCanXDemarre  |= ((tDATCdlIdCanalCan)(((tDATCdlIdCanalCan)0x01UL)<<IdCanalCan));
    #endif

    mSERWrite(U1Bit,DTCFuncEnable, eDTCFunCom_CanFault, Default);
}

//==============================================================================
// DESCRIPTION : Stop the CAN communication
//
// PARAMETERS (Type,Name,Min,Max) : tDATCdlIdCanalCan : CAN channel identifier
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
#ifdef M_MULTIBUS_CAN
void DATCnmStopCom(tDATCdlIdCanalCan IdCanalCan)
#else
void DATCnmStopCom(void)
#endif
{
    #ifdef M_MULTIBUS_CAN
    //DAT_CAN must be started, otherwise the Tick do not run and the DAT_CAN state will
    //stay in cDATCmnStopInProgress state and DAT_CAN will maintain the ECU asleep for always
    mLIBassert(DATCnmStatus[IdCanalCan] == cDATCmnStarted);
    DATCpl_P_Stop(IdCanalCan);
    DATCil_I_Stop(IdCanalCan);
    #else
    //DAT_CAN must be started, otherwise the Tick do not run and the DAT_CAN state will
    //stay in cDATCmnStopInProgress state and DAT_CAN will maintain the ECU asleep for always
    mLIBassert(DATCnmStatus == cDATCmnStarted);
    DATCpl_P_Stop();
    DATCil_I_Stop();
    //  DATCtl_T_Stop(); : To be call by ASDT management component
    //  (to deactive transport layer management)
    DATCnl_N_Stop();
    #endif

    #ifdef M_MULTIBUS_CAN
    DATCdl_D_Stop(IdCanalCan);

    mDATCnmDisableIT();
    DATCnmBusOffDetected &= ((tDATCdlIdCanalCan)~(((tDATCdlIdCanalCan)0x01UL)<<IdCanalCan));
    u8ResetOnBusOff &= ((tDATCdlIdCanalCan)~(((tDATCdlIdCanalCan)0x01UL)<<IdCanalCan));
    mDATCnmEnableIT();
    DATCnmStatus[IdCanalCan] = cDATCmnStopInProgress;

    DATCnmStopTimeout[IdCanalCan] = cDATCnmStopTimeoutInTick;
    #ifndef SUPERVISION_OFF
    if( IdCanalCan == cDATCdlIdCanalCan0)
    {
        SetUpDefaultValues(cDATCdlIdCanalCan0);
        // Decrease of Fault Counter is not authorized
        DATCnmDecreaseIsNotAuthorized(cDATCdlIdCanalCan0);
    }
    #endif
    #else
    DATCdl_D_Stop();

    mDATCnmDisableIT();
    DATCnmBusOffDetected = cFalse;
    #ifndef SUPERVISION_OFF
    bResetOnBusOff = cFalse;
    #endif
    mDATCnmEnableIT();
    DATCnmStatus = cDATCmnStopInProgress;

    DATCnmStopTimeout = cDATCnmStopTimeoutInTick;
    #ifndef SUPERVISION_OFF
    SetUpDefaultValues();
    #endif
    #endif
}

//==============================================================================
// DESCRIPTION : Initialization of the component
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void DATCnmInit (void)
{
    #ifdef M_MULTIBUS_CAN
    tDATCdlIdCanalCan IdCan;
    #endif

    #ifdef WAKE_BY_CAN
    mDATCnmDisableIT();
    #ifndef M_MULTIBUS_CAN
    DATCnmWakeUpRequest = cFalse;
    #ifndef SUPERVISION_OFF
    bResetOnBusOff = cFalse;
    #endif
    #else
    DATCnmWakeUpRequest = 0;
    u8ResetOnBusOff = 0;
    #endif

    mDATCnmEnableIT();
    #endif

    DATCplInit();
    DATCilInit();
    #ifdef COMPOSANT_DAT_CTL_ON
    DATCtlInit();
    #endif
    DATCnlInit();
    DATCdlInit();

    #ifdef M_MULTIBUS_CAN
        // Init of the Fault Status
    for(IdCan = 0; IdCan< cDATCdl_NbCanauxCan; IdCan++)
    {
        //one init for all the can bus
        DATCnmCanXDemarre &= (tDATCdlIdCanalCan)0;

        mDATCnmDisableIT();
        DATCnmBusOffDetected  = (tDATCdlIdCanalCan)0;
        mDATCnmEnableIT();
        DATCnmStatus[IdCan] = cDATCmnStopped;

        DATCnmStopTimeout[IdCan] = (tDATCnmStopTimeoutInTick)0;
        //Other CAN channel are not supervised for the moment
        //#ifndef SUPERVISION_OFF
        //SetUpDefaultValues(IdCan);
        //#endif
    }

    #ifndef SUPERVISION_OFF
    SetUpDefaultValues(cDATCdlIdCanalCan0);
    #endif

    #else

    mDATCnmDisableIT();
    DATCnmBusOffDetected = cFalse;
	u8CANControllerStatus = cNM_ErrAct;
    mDATCnmEnableIT();
    DATCnmStatus = cDATCmnStopped;

    DATCnmStopTimeout = (tDATCnmStopTimeoutInTick)0;
    #ifndef SUPERVISION_OFF
    SetUpDefaultValues();
    #endif
    #endif

    sbIsBatProtect = cFalse;
}

//==============================================================================
// DESCRIPTION : RAZ the fault counter
//
// PARAMETERS (Type,Name,Min,Max) : tDATCdlIdCanalCan : CAN channel identifier
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
#ifdef M_MULTIBUS_CAN
void DATCnmRAZFaultCounter (tDATCdlIdCanalCan IdCanalCan)
#else
void DATCnmRAZFaultCounter (void)
#endif
{
    #ifdef M_MULTIBUS_CAN
    #ifdef  SELF_DIAGNOSTIC
    U8 Value;
    #endif
    #endif

    #ifndef SUPERVISION_OFF
    tDATCnmSourceHandle Index;

    // RAZ the fault counter and the DTC self diag
    for( Index = 0; Index < cDATCnmNbrCANStatus; Index++)
    {
        #ifdef M_MULTIBUS_CAN
        //CAN 1 is not supervised, there is no CAN 1 default in a Non-Volatile Memory.
        mLIBassert(IdCanalCan == cDATCdlIdCanalCan0);
        mDATCnmWriteNVM(IdCanalCan, ((U8)0x00UL), Index);
        #else
        mDATCnmWriteNVM(((U8)0x00UL), Index);
        #endif
    }
    #endif

    #ifdef  SELF_DIAGNOSTIC
    #ifdef M_MULTIBUS_CAN
    mDATCnmWriteNVMSelfDiag(IdCanalCan, cFalse);
    #else
    mDATCnmWriteNVMSelfDiag(cFalse);
    #endif
    #endif
}

//==============================================================================
// DESCRIPTION : API with the Data Link Layer (DAT_CDL) : an event has occured
//
// PARAMETERS (Type,Name,Min,Max) : tDATCdlIdCanalCan : CAN channel identifier
//                                  tDATCdlStatus : Event identifier
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : Here we are into an interrupt context
//==============================================================================
#ifdef M_MULTIBUS_CAN
void DATCnm_D_Status(tDATCdlIdCanalCan IdCan, tDATCdlStatus Statut)
#else
void DATCnm_D_Status(tDATCdlStatus Statut)
#endif
{
    switch( Statut )
    {
        case( cDATCdlStatusBusOn ) :
            //这里处理有问题：要分多路CAN分别处理
			// Bus On is detected by a reception or an emission of a key frame

			if(cNM_BusOff == CANControllerStatusBuf[IdCan]) //old sts is bus off
			{
				DATCilFramRxSurveyRestart(); //bus off recovery
			}
            CANControllerStatusBuf[IdCan] = cNM_ErrAct;

            DATCnmBusOffDetected &= ((tDATCdlIdCanalCan)~(((tDATCdlIdCanalCan)0x01UL)<<IdCan));

			#ifndef SUPERVISION_OFF
			bResetOnBusOff        = cFalse;
			#endif
             break;


        case( cDATCdlStatusBusOff ) :

        	BusOffRecovering[IdCan] = 0u;
            #ifdef M_MULTIBUS_CAN
            DATCnmBusOffDetected |= (((tDATCdlIdCanalCan)0x01UL)<<IdCan);
            u8ResetOnBusOff |= (((tDATCdlIdCanalCan)0x01UL)<<IdCan);
            if(IdCan == 0)
            {
                TOSWriteSignal(cTOSSignalCan0BusOff);
            }else if(IdCan == 1)
            {
                TOSWriteSignal(cTOSSignalCan1BusOff);
            }else if(IdCan == 2)
            {
                TOSWriteSignal(cTOSSignalCan2BusOff);
            }
            else if(IdCan == 3)
            {
                TOSWriteSignal(cTOSSignalCan3BusOff);
            }
            else if(IdCan == 4)
            {
                TOSWriteSignal(cTOSSignalCan4BusOff);
            }
            else
            {
                ;
            }

            #else
            DATCnmBusOffDetected = cTrue;
            TOSWriteSignal(cTOSSignalCanBusOff);
            #ifndef SUPERVISION_OFF
			bResetOnBusOff = cTrue;
            #endif
            #endif

			CANControllerStatusBuf[IdCan] = cNM_BusOff;
            break;


        case( cDATCdlStatusPassiveError ) :
            CANControllerStatusBuf[IdCan] = cNM_ErrPassive;
        	//要根据不同的CAN路设置各个不同的标志位
            DATCnmBusOffDetected &= ((tDATCdlIdCanalCan)~(((tDATCdlIdCanalCan)0x01UL)<<IdCan));
			#ifndef SUPERVISION_OFF
			bResetOnBusOff        = cFalse;
			#endif
            break;


        #ifdef WAKE_BY_CAN
        case( cDATCdlStatusWakeUp ) :
            // Wake up condition detected
            #ifndef M_MULTIBUS_CAN
            DATCnmWakeUpRequest = cTrue;
            #else
            DATCnmWakeUpRequest |= (((tDATCnmFlagIdCanalCan)1)<<IdCan);
            #endif
            //Sortie du contexte de l'IT: le flag sera trait?par le Tick
            TOSActivateTask(cTOSTaskID_CanTraitements);			
            break;
        #endif


        case( cDATCdlStatusNerrOff )://cLIBStkDatCanConfig_PsaBody
			break;


		case( cDATCdlStatusNerrOn )://cLIBStkDatCanConfig_PsaBody
			break;


        default :
            mLIBassert(cFalse);
            break;
    }
}

//==============================================================================
// DESCRIPTION : API with the Data Link Layer (DAT_CDL):confirm the CAN cell is stopped
//
// PARAMETERS (Type,Name,Min,Max) : tDATCdlIdCanalCan : CAN channel identifier
//                                  tDATCdlCtrl : control which is confirm
//                                  BOOL : Status of the control
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
#ifdef M_MULTIBUS_CAN
void DATCnm_D_Confirm(tDATCdlIdCanalCan IdCanalCan, tDATCdlCtrl Ctrl, BOOL Status)
#else
void DATCnm_D_Confirm(tDATCdlCtrl Ctrl, BOOL Status)
#endif
{
    #ifdef M_MULTIBUS_CAN
    #ifdef  SELF_DIAGNOSTIC
    U8 Value;
    #endif
    #endif

    #ifdef  SELF_DIAGNOSTIC
    mLIBassert((Ctrl == cDATCdlCtrlArreter)||(Ctrl == cDATCdlCtrlStart)||(Ctrl == cDATCdlCtrlSelfDiag));
    #else
    mLIBassert((Ctrl == cDATCdlCtrlArreter)||(Ctrl == cDATCdlCtrlStart));
    #endif

    #ifdef M_MULTIBUS_CAN
    if(Ctrl == cDATCdlCtrlArreter)
    {
        if(DATCnmStatus[IdCanalCan] == cDATCmnStopInProgress)
        { // Cancel the CAN Alarm
            //At least one bus has been started
            mLIBassert((BOOL)(DATCnmCanXDemarre != 0));

            DATCnmCanXDemarre  &= ((tDATCdlIdCanalCan)~(((tDATCdlIdCanalCan)0x01UL)<<IdCanalCan));

            if(DATCnmCanXDemarre == (tDATCdlIdCanalCan)0)
            {
                //  DATCtl_T_Stop(); : a effectuer par la gestion ASDT
                DATCnl_N_Stop();

                // Cancel the CAN Alarm
                TOSCancelAlarm( &AlarmCANTreatment);
                #ifdef WAKE_BY_CAN
                if ((DATCnmWakeUpRequest &= (((tDATCnmFlagIdCanalCan)1)<<IdCanalCan)) != (tDATCnmFlagIdCanalCan)0)
                {
                    TOSActivateTask(cTOSTaskID_CanTraitements);
                }
                #endif
            }

            if(Status != cFalse)
            {
                DATCnmStatus[IdCanalCan] = cDATCmnStopped;
                DATCnmStopTimeout[IdCanalCan] = (tDATCnmStopTimeoutInTick)0;
            }
            else
            {
                DATCnmStatus[IdCanalCan] = cDATCmnStoppedError;
            }
        }
    }
    else if(Ctrl == cDATCdlCtrlStart)
    {
        mLIBassert(Status == cTrue);
        DATCnmStatus[IdCanalCan] = cDATCmnStarted;
    }
    else
    {
        #ifdef  SELF_DIAGNOSTIC
        if(Status == cFalse)
        {
            //Memorization of the defect into a Non-Volatile Memory
            mDATCnmWriteNVMSelfDiag(IdCanalCan, cTrue);
        }
        else
        {
            mLIBassert(cTrue); //for QAC
            //Do nothing
        }
        #endif
    }
    #else
    if(Ctrl == cDATCdlCtrlArreter)
    {
        if(DATCnmStatus == cDATCmnStopInProgress)
        {   // Cancel the CAN Alarm
            TOSCancelAlarm( &AlarmCANTreatment);
            #ifdef WAKE_BY_CAN
            if (DATCnmWakeUpRequest != cFalse)
            {
                TOSActivateTask(cTOSTaskID_CanTraitements);
            }
            #endif
            if(Status != cFalse)
            {
                DATCnmStatus = cDATCmnStopped;
                DATCnmStopTimeout = (tDATCnmStopTimeoutInTick)0;
            }
            else
            {
                DATCnmStatus = cDATCmnStoppedError;
            }
        }
    }
    else if(Ctrl == cDATCdlCtrlStart)
    {
        mLIBassert(Status == cTrue);
        DATCnmStatus = cDATCmnStarted;
    }
    else
    {
        #ifdef  SELF_DIAGNOSTIC
        if(Status == cFalse)
        {
            //Memorization of the defect into Non-Volatile Memory
            mDATCnmWriteNVMSelfDiag(cTrue);
        }
        else
        {
            mLIBassert(cTrue); //for QAC
            //Do nothing
        }
        #endif
    }
    #endif
}

//==============================================================================
// DESCRIPTION : Authorize the decrease of the Non-Volatile Memory fault counter
//
// PARAMETERS (Type,Name,Min,Max) : tDATCdlIdCanalCan : CAN channel identifier
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
#ifndef SUPERVISION_OFF
#ifdef M_MULTIBUS_CAN
void DATCnmDecreaseIsAuthorized(tDATCdlIdCanalCan IdCanalCan)
#else
void DATCnmDecreaseIsAuthorized(void)
#endif
{
    tDATCnmSourceHandle SourceId;

    #ifdef M_MULTIBUS_CAN
    DecreaseIsAuthorized |= (((tDATCdlIdCanalCan)0x01UL)<<IdCanalCan);
    //Un seul CAN est supervisable
    mLIBassert(IdCanalCan == cDATCdlIdCanalCan0);
    #else
    DecreaseIsAuthorized = cTrue;
    #endif

    for( SourceId = 0; SourceId < cDATCnmNbrCANStatus; SourceId++)
    {
        mDATCnmClearCounterDecreaseInThisTripStatus(SourceId);
    }
}
#endif

//==============================================================================
// DESCRIPTION : Forbid the decrease of the Non-Volatile Memory faults counter
//
// PARAMETERS (Type,Name,Min,Max) : tDATCdlIdCanalCan : CAN channel identifier
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
#ifndef SUPERVISION_OFF
#ifdef M_MULTIBUS_CAN
void DATCnmDecreaseIsNotAuthorized(tDATCdlIdCanalCan IdCanalCan)
#else
void DATCnmDecreaseIsNotAuthorized(void)
#endif
{
    #ifdef M_MULTIBUS_CAN
    //Un seul CAN est supervisable
    mLIBassert(IdCanalCan == cDATCdlIdCanalCan0);

    DecreaseIsAuthorized &= ((tDATCdlIdCanalCan)~((tDATCdlIdCanalCan)((tDATCdlIdCanalCan)0x01UL)<<IdCanalCan));
    #else
    DecreaseIsAuthorized = cFalse;
    #endif
}
#endif

//==============================================================================
// DESCRIPTION : CallBack defined in DAT_CPL to know the confirmed status of
//               the CAN Source
//
// PARAMETERS (Type,Name,Min,Max) : tDATCilSourceHandle : CAN source identifier
//
// RETURN VALUE : BOOL : Confirmed defect status
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
#ifndef SUPERVISION_OFF
BOOL DATCnmSourceIsConfirmedMute(tDATCilSourceHandle SourceHandle)
{
    mLIBassert(SourceHandle<cDATCil_NbSources);
    return (mDATCnmReadConfirmedFaultStatus(SourceHandle));
}
#endif

//==============================================================================
// DESCRIPTION : return the status of the CAN network
//
// PARAMETERS (Type,Name,Min,Max) : tDATCdlIdCanalCan : CAN channel identifier
//
// RETURN VALUE : tDATCnmStatus : CAN network state
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
#ifdef M_MULTIBUS_CAN
tDATCnmStatus DATCnmGetNetworkState(tDATCdlIdCanalCan IdCanalCan)
{
    return(DATCnmStatus[IdCanalCan]);
}
#else
tDATCnmStatus DATCnmGetNetworkState(void)
{
    return(DATCnmStatus);
}
#endif

//==============================================================================
// DESCRIPTION : Maintain application in ActiveSleep State until all the Can
//               bus are sleeping
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : Call by the standard supervisor LAP_SUP
//==============================================================================
void DATCnmIsMaintainActiveSleepState(void)
{
#ifdef M_MULTIBUS_CAN

    tDATCdlIdCanalCan IdCan;

    for(IdCan = 0; IdCan< cDATCdl_NbCanauxCan; IdCan++)
    {
        if(DATCnmStatus[IdCan] == cDATCmnStopInProgress)
        {
            TOSWriteSignal(cTOSSignalSomebodyMaintainActiveSleepState);
        }
    }
    #else
    if(DATCnmStatus == cDATCmnStopInProgress)
    {
        TOSWriteSignal(cTOSSignalSomebodyMaintainActiveSleepState);
    }
    #endif
}

//==============================================================================
// DESCRIPTION : Frame transmission synchronization service . The function 
// reinits frame transmission counters in the interaction layer
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : CAN service. Must be called ONLY ONCE at the beginning
// when frame transmission is launched!!!
//==============================================================================
void DATCnmStartTrasmission(void)
{
    DATCilInitTransmission();
}
//==============================================================================
// DESCRIPTION : 
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : CAN Bus state:ErrAct,PassiveAct,BusOff
//==============================================================================
U8	DATCnmGetCANControllerStatus(void)
{
	U8	u8Return;

	mDATCnmDisableIT();
	u8Return = 0;//u8CANControllerStatus;
	mDATCnmEnableIT();

	return(u8Return);
}

BOOL  DATCnmGetCanBusOffState(U8 IdCan )
{
	BOOL bIsBusOff = cFalse;

	if( (DATCnmBusOffDetected & (((tDATCdlIdCanalCan)0x01UL)<<IdCan)) != (tDATCdlIdCanalCan)0)
	{
		bIsBusOff = cTrue;
	}
	return bIsBusOff;
}

BOOL  DATCnmGetCanBusOffRecoveringState(U8 IdCan )
{
	BOOL bIsBusOffRecovering = cFalse;

	if (BusOffRecovering[IdCan] == 1u)
	{
		bIsBusOffRecovering = cTrue;
	}

	return bIsBusOffRecovering;
}

void DATCnmBatProtectEn(void )
{
	TOSCancelAlarm(&AlarmCANTreatment);
	sbIsBatProtect = cTrue;
};

void DATCnmBatProtectDis(void )
{
	TOSSetRelAlarm( &AlarmCANTreatment, ((U8)0UL), mTOSConvMsEnTickAlarm(cDATCdlTickMs) );
	sbIsBatProtect = cFalse;
};
