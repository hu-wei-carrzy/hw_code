
#ifndef _SER_DAT_H_
#define _SER_DAT_H_ (1)

/*-------------------------------------------------------------------------
  Included files to resolve specific definitions in this file

  #include <system_file_name.h>
  #include "project_file_name.h"
  -------------------------------------------------------------------------*/
#include "ARCH_CFG.h"

#ifdef cHeadIncludeType_Directly
#include "deftypes.h"
#include "SER.h"

#include "SER_DATAEXPORT_INCLUDE.h"
#else
#include ".\..\..\LIB\LIB_API\deftypes.h"
#include ".\..\SER.h"
#include ".\..\SER_INCLUDE\SER_DATAEXPORT_INCLUDE.h"
#endif

enum
{
	cTTSts_Off		,
	cTTSts_On		,
	cTTSts_Blink
};







//////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
extern void    SERDAT_SetSpeedKmph(U16 u16Speed);
extern U16    SERDAT_GetSpeedKmph(void);

#define mSERReadU16BitSpeedKmphDefault()             SERDAT_GetSpeedKmph()
#define mSERWriteU16BitSpeedKmphDefault(u16Speed)    SERDAT_SetSpeedKmph((u16Speed))


////////////////////////////////////////////////////////////////////////////
extern BOOL SERDAT_GetRunInMode();
extern void SERDAT_SetRunInMode(BOOL bVal);
//#define mSERReadU1BitIsRunInModeDefault()     SERDAT_GetRunInMode()
//#define mSERWriteU1BitIsRunInModeDefault(bVal)  SERDAT_SetRunInMode(bVal)


//////////////////////////////////////////////////////////////////////////




/////////////////////////////////////////////////////////////////////////
extern void SERDAT_SetSleepCtrlFlag(BOOL bvalue);
extern BOOL SERDAT_GetSleepCtrlFlag(void);

//#define mSERReadU1BitIsSetSleepFlagDefault()        SERDAT_GetSleepCtrlFlag()
//#define mSERWriteU1BitIsSetSleepFlagDefault(bVal)   SERDAT_SetSleepCtrlFlag(bVal)

/////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////
#ifdef cDATBATFunc

#else
//#define mSERReadU1BitIsBatStNormalDefault()         cTrue
#endif

/////////////////////////////////////////////////////////////////////////
#ifdef cDATCPUFunc
extern U32 DATCpuGetUnUsedStackSize(void);
extern	U8	DATCpuGetResetCause(void);
#define mSERReadU32BitUnUsedStackSizeDefault() 	(DATCpuGetUnUsedStackSize())
#define mSERReadU32UnUsedStackSizeDefault() 	(DATCpuGetUnUsedStackSize())
//#define mSERReadU8BitMCUResetCauseDefault() 	(DATCpuGetResetCause())

#else
#define mSERReadU32BitUnUsedStackSizeDefault()  0
#define mSERReadU32UnUsedStackSizeDefault() 	0
//#define mSERReadU8BitMCUResetCauseDefault() 	0

#endif

////////////////////////////////////////////////////////////////////////////////

#if 0

//IOControl
extern  void    SERDAT_LockUnlockIOCbyId(BOOL bLock,U8 u8LockId);
extern  BOOL    SERDAT_IsIOCLocked(U8 u8LockId);

// IOControlStatus reading and writing
//for client diagnostics
#define mSERReadU1BitIsIOCTTLockedDefault()                         SERDAT_IsIOCLocked(eIOControl_TT)
#define mSERReadU1BitIsIOCILLLockedDefault()                        SERDAT_IsIOCLocked(eIOControl_ILL)
#define mSERReadU1BitIsIOCLCDLockedDefault()                        SERDAT_IsIOCLocked(eIOControl_LCD)
//for product diagnostics
#define mSERReadU1BitIsIOCILLProductLockedDefault()                 SERDAT_IsIOCLocked(eIOControl_ILLProduct)
#define mSERReadU1BitIsIOCLCDVoltageLockedDefault()                 SERDAT_IsIOCLocked(eIOControl_LCDVoltage)
#define mSERReadU1BitIsIOCLCDFrequencyLockedDefault()               SERDAT_IsIOCLocked(eIOControl_LCDFrequency)
#define mSERReadU1BitIsIOCLCDTemperatureLockedDefault()             SERDAT_IsIOCLocked(eIOControl_LCDTemperature)
#define mSERReadU1BitIsIOCLCDProuctLockedDefault()                  SERDAT_IsIOCLocked(eIOControl_LCDProduct)
#define mSERReadU1BitIsIOCPointerMicroStepLockedDefault()           SERDAT_IsIOCLocked(eIOControl_PointerMicroStep)
#define mSERReadU1BitIsIOCPointerInVehicleLockedDefault()           SERDAT_IsIOCLocked(eIOControl_PointerInVehicle)
#define mSERReadU1BitIsIOCStepperInLowTorqueLockedDefault()         SERDAT_IsIOCLocked(eIOControl_StepperInLowTorque)
#define mSERReadU1BitIsIOCStepperInHighImpendanceLockedDefault()    SERDAT_IsIOCLocked(eIOControl_StepperInHighImpendance)
#define mSERReadU1BitIsIOCBuzLockedDefault()                        SERDAT_IsIOCLocked(eIOControl_Buz)
#define mSERReadU1BitIsIOCClockFreqLockedDefault()                  SERDAT_IsIOCLocked(eIOControl_ClockFreq)
#define mSERReadU1BitIsIOCStepperInUJumpLockedDefault()             SERDAT_IsIOCLocked(eIOControl_StepperInUJump)
#define mSERReadU1BitIsIOCATOutputLockedDefault()                   SERDAT_IsIOCLocked(eIOControl_ATOutput)

//for client diagnostics
#define mSERWriteU1BitIsIOCTTLockedDefault(v)                       SERDAT_LockUnlockIOCbyId(v,eIOControl_TT)
#define mSERWriteU1BitIsIOCILLLockedDefault(v)                      SERDAT_LockUnlockIOCbyId(v,eIOControl_ILL)
#define mSERWriteU1BitIsIOCLCDLockedDefault(v)                      SERDAT_LockUnlockIOCbyId(v,eIOControl_LCD)
//for product diagnostics
#define mSERWriteU1BitIsIOCILLProductLockedDefault(v)               SERDAT_LockUnlockIOCbyId(v,eIOControl_ILLProduct)
#define mSERWriteU1BitIsIOCLCDVoltageLockedDefault(v)               SERDAT_LockUnlockIOCbyId(v,eIOControl_LCDVoltage)
#define mSERWriteU1BitIsIOCLCDFrequencyLockedDefault(v)             SERDAT_LockUnlockIOCbyId(v,eIOControl_LCDFrequency)
#define mSERWriteU1BitIsIOCLCDTemperatureLockedDefault(v)           SERDAT_LockUnlockIOCbyId(v,eIOControl_LCDTemperature)
#define mSERWriteU1BitIsIOCLCDProuctLockedDefault(v)                SERDAT_LockUnlockIOCbyId(v,eIOControl_LCDProduct)
#define mSERWriteU1BitIsIOCPointerMicroStepLockedDefault(v)         SERDAT_LockUnlockIOCbyId(v,eIOControl_PointerMicroStep)
#define mSERWriteU1BitIsIOCPointerInVehicleLockedDefault(v)         SERDAT_LockUnlockIOCbyId(v,eIOControl_PointerInVehicle)
#define mSERWriteU1BitIsIOCStepperInLowTorqueLockedDefault(v)       SERDAT_LockUnlockIOCbyId(v,eIOControl_StepperInLowTorque)
#define mSERWriteU1BitIsIOCStepperInHighImpendanceLockedDefault(v)  SERDAT_LockUnlockIOCbyId(v,eIOControl_StepperInHighImpendance)
#define mSERWriteU1BitIsIOCBuzLockedDefault(v)                      SERDAT_LockUnlockIOCbyId(v,eIOControl_Buz)
#define mSERWriteU1BitIsIOCClockFreqLockedDefault(v)                SERDAT_LockUnlockIOCbyId(v,eIOControl_ClockFreq)
#define mSERWriteU1BitIsIOCStepperInUJumpLockedDefault(v)           SERDAT_LockUnlockIOCbyId(v,eIOControl_StepperInUJump)
#define mSERWriteU1BitIsIOCATOutputLockedDefault(v)                 SERDAT_LockUnlockIOCbyId(v,eIOControl_ATOutput)
#endif


#if 0
//diag session state setting
extern BOOL SERDAT_IsDiagSt(void);
extern BOOL SERDAT_GetDiagStBySession(U8 u8DiagSession);
extern void SERDAT_SetDiagStByDiagSession(U8 u8DiagSession,BOOL bValue);
extern BOOL SERDAT_SetDiagSt(BOOL bDiagSt);
#define mSERReadU1BitIsDiagModeDefault()                       SERDAT_IsDiagSt()
#define mSERWriteU1BitDiagModeDefault(v)                       SERDAT_SetDiagSt((v))


#define mSERReadU1BitIsProgramSessionDefault()                 SERDAT_GetDiagStBySession(eDiagSt_ProgrammingSession)
#define mSERReadU1BitIsCustomerSessionDefault()                    SERDAT_GetDiagStBySession(eDiagSt_CustomerSession)
#define mSERReadU1BitIsFactorySessionDefault()                     SERDAT_GetDiagStBySession(eDiagSt_FactorySession)

#define mSERWriteU1BitDefaultSessionDefault(v)                 SERDAT_SetDiagStByDiagSession(eDiagSt_DefaultSession,(v))
#define mSERWriteU1BitFactorySessionDefault(v)                 SERDAT_SetDiagStByDiagSession(eDiagSt_FactorySession,(v))
#define mSERWriteU1BitCustomerSessionDefault(v)                SERDAT_SetDiagStByDiagSession(eDiagSt_CustomerSession,(v))
#define mSERWriteU1BitProgramSessionDefault(v)                 SERDAT_SetDiagStByDiagSession(eDiagSt_ProgramSession,(v))
#endif







#endif   /* _SER_DAT_H_ */

