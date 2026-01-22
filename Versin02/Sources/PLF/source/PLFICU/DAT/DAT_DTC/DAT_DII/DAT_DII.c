
#define dat_dii  "dat_dii"

//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//
// #include <system_file_name.h>
// #include "project_file_name.h"
//------------------------------------------------------------------------------

#define cDAT_DII_SELFINCLUDE  //(1U)//change by zc
#include "DAT_DII.h"

//------------------------------------------------------------------------------
// Local constants
//
// #define cConstantName   ((tType) ConstantValue)
//------------------------------------------------------------------------------

//TOS task period in ms
//#define cDatDiiTaskPeriod           (tTOSTickAlarm)40
#define cDatDiiTaskPeriod           (40U)

//number of bytes needed to store the monitoring cycle state for each DTC  
#define cFunctionalitiesBufSize     (U8)((eDTCFunCom_Count + 7U) / 8U)

#define cMemorizationBufSize        (U8)((eDTCIDCount + 7U) / 8U)

#define		mIsIGOn					  1 //((mSERRead(U1Bit, AD_IGOn, Default)))

//invalid value for DistanceTotalizer
#define cInvalidDistanceTotalizer   (U32)0x0FFFFFFFU //28bits
#define cControlDTCSettingStopCheck       (cTrue)
#define cControlDTCSettingStartCheck      (cFalse )

#define cTestFailed                       (cTrue)
#define cTestPassed                       (cFalse)

#define cTestFailedCntValue              ((S8)(1))  //positive
#define cTestPassedCntValue              ((S8)(-1)) //minus 

#define cDATDiiLastStatusLength  ((U8)((eDTCIDCount-1U)/8U + 1U))

// define struct used to delete DTC 
typedef struct
{
	//how many driving cycles has experience since no DTC occuring
	U8 u8DrivingCyclesSinceNoDTCOccur;
	//DTC has occured, no matter its happening time
	BOOL u8DTCOccurredFlag;
	//DTC has occured in current driving cycle
	BOOL u8DTCOccurredInCurrentDrivingCycleFlag;
} stDTCDeletedInfo;

//struct array for deleting DTC
static stDTCDeletedInfo asDTCDeletedInfo[eDTCIDCount];

static U8 u8DiiState;

//------------------------------------------------------------------------------
// Local macros
//
// #define mMacroName   (MacroDefinition)
//------------------------------------------------------------------------------
#define mSetDTCBit(Status, Bitmask)	    									\
	((Status) |= (Bitmask))

#define mClearDTCBit(Status, Bitmask)										\
	((Status) &= (U8)(~(Bitmask)))

#define mIsBitSet(Status, Bitmask)											\
	((BOOL)( ((Status) & (Bitmask)) != 0U))

//monitoring cycles macros
#define mActivateFunComMonitoring(DTC)                                       \
    (au8EnabledFunComMonitoring[(DTC) >> 3U] |= (U8)(1U << ((DTC) & 7U)))

#define mDeactivateFunComMonitoring(DTC)                                     \
    (au8EnabledFunComMonitoring[(DTC) >> 3U] &= (U8)~(U8)(1U << ((DTC) & 7U)))

#define mIsFunComMonitored(DTC)                                       \
    ((au8EnabledFunComMonitoring[(DTC) >> 3U] & (U8)(1U << ((DTC) & 7U))) != 0U)

#define mSetDTCTestFailedCounter(DTC)           \
	(as16DTCDetectionCounter[(DTC)]++)

#define mGetDTCTestCounter(DTC)                  \
	(as16DTCDetectionCounter[(DTC)])

#define mSetDTCTestCounter(DTC,num)              \
	(as16DTCDetectionCounter[(DTC)]=(num))

#define mSetDTCTestPassedCounter(DTC)            \
	(as16DTCDetectionCounter[(DTC)]--)


//------------------------------------------------------------------------------
// Local types
//
// typedef Expression    tTypeName;
//------------------------------------------------------------------------------
enum
{
    eDiiStateIgOffing, eDiiStateIgOff2On, eDiiStateIgOning, eDiiStateIgOn2Off, eDiiStateInvalid
};
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

static U8 sau8IsLastStatusDefected[cDATDiiLastStatusLength] ;//存放上次DTC状态，亦用于当前DTC状态的导出



//component task alarm
static tTOSAlarm DATDiiTaskAlarm;

//occur times of an DTC, which can be used as testPassed and testFailed
static S16 as16DTCDetectionCounter[eDTCIDCount];

//whether the func com is monitored or not :1--monitored, 0--not monitored
//this byte is to control the starting time of each component. For example
//when IGOff and car enters sleep status, the speed sensor should not report
//any DTC ,so you can call mDATWriteTable(U1Bit,DTCMonitoringCycles,eSpeedFunc,cFalse,Default)
//and then the speed sensor component is disabled.
//Besides that, when IGOn and IGOff, some functions should be enabled or disabled 
//according to the real situation. So in each component, the programer should consider
//the starting and the stopping time for DTC monitoring
static U8 au8EnabledFunComMonitoring[cFunctionalitiesBufSize ];

//contains the enum value of the DTC fault to be reported. additionally this
//variable is used for DTCs that need special conditions for confirming the 
//memorization
static U8 su8DTCForReporting;
//contains information if defect is present or not
static BOOL sbIsDTCFailed;
//if this variable equals to cTrue, stop DTC check
//if this variable equals to cFalse, begin DTC check as normal
static BOOL bControlDTCSetting;
//------------------------------------------------------------------------------
// Constant local data
//
// static const tType  VariableName;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Exported data
//
// tType   u8DATCmpVariableName; (DAT: 3 characters to identify the layer)
// tType*  pu8DATCmpVariableName;(Cmp: 3 characters to identify the component)
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Constant exported data
//
//             (DAT: 3 characters to identify the layer)
//             (Cmp: 3 characters to identify this component)
//
// const tType   DATCmpVariableName;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Local function prototypes
//
// static tReturnType FunctionName(tTypeArgument1 ArgumentName1, ... );
//------------------------------------------------------------------------------
static void ProcessDTC(const U8 u8DTCId, const BOOL bFailed);
//==============================================================================
//=========================== LOCAL FUNCTIONS ==================================
//==============================================================================
#ifdef Coverity_Not_Kill_DATDiiIncreaseDTCDeletedDrivingCycles
//==============================================================================
// DESCRIPTION         :  Increase the deleted cycle counter if DTC has occured 
//                        before and not occured in current driving cycle
//
// PARAMETERS          : None
// (Type,Name,Min,Max) 
//
// RETURN VALUE        : 
//
// DESIGN INFORMATION  : Refer to Detailed Design Document
//==============================================================================
void DATDiiIncreaseDTCDeletedDrivingCycles(void)
{
	U8 u8DTC;
	for (u8DTC = 0; u8DTC < eDTCIDCount; u8DTC++)
	{
		//DTC occured before,but not occured in current drivring cycle
		if ((mDATGetDTCOccurredFlag(u8DTC)==cTrue) && (mDATGetDTCOccurredInCurrentIGCycleFlag(u8DTC)==cFalse))
		{
			mDATIncreaseDTCDeletedDrivingCycles(u8DTC);
		}
	}

}
#endif
//==============================================================================
// DESCRIPTION         : Retrieve the value of DistanceTotalized from 
//                       BRAKE_CANHS_R_01 CAN frame
//
// PARAMETERS          : None
// (Type,Name,Min,Max) 
//
// RETURN VALUE        : 
//
// DESIGN INFORMATION  : Refer to Detailed Design Document
//==============================================================================

//==============================================================================
// DESCRIPTION         : DTC reporting
//
// PARAMETERS          : u8DTC - enum for DTC fault regarding the enum eDTCIds
//                       bFailed - TRUE if defect was detected, otherwise FALSE
// (Type,Name,Min,Max) 
//
// RETURN VALUE        : None
//
// DESIGN INFORMATION  : Refer to Detailed Design Document
//==============================================================================
static void ProcessDTC(const U8 u8DTCId, const BOOL bFailed)
{
	BOOL bSaveDTC;
	U8 u8CurStatus;
	S16 s16DTCCounter;

	bSaveDTC = cFalse;

    if ((bControlDTCSetting == cControlDTCSettingStopCheck) && (mSERRead(U1Bit, IsDiagMode, Default)))
	{
		// do nothing
	}
	else
	{
		//first get the status from DAT_DDB.c (asDTCStorage[u8DTC].u8DTCStatus)
		u8CurStatus = mDDBReadRecordField(u8DTCId, Status);
		//since there is a fault reported or a fault repaired, so clear corresponding bits 
		mClearDTCBit(u8CurStatus, cu8DTCMaskTestNotCompletedThisOperationCycle);
		mClearDTCBit(u8CurStatus, cu8DTCMaskTestNotCompletedSinceLastClear);
		//(bFailed == cTestFailed)
		if (bFailed == cTestFailed)
		{
			//DTC test fail area
			//if DTC occurs, set occurred flag and assign 0 to deleted driving cycles 
			mDATSetDTCDeletedDrivingCycles(u8DTCId, 0U);
			mDATSetDTCOccurredFlag(u8DTCId);
			mDATSetDTCOccurredInCurrentIGCycleFlag(u8DTCId);

			s16DTCCounter = mGetDTCTestCounter(u8DTCId);
			if (s16DTCCounter < ((S16)mDDBGetDTCTriggerValue(u8DTCId)))
			{
				s16DTCCounter += mDDBGetDTCConfirmedStep(u8DTCId);
				if (s16DTCCounter > ((S16)mDDBGetDTCTriggerValue(u8DTCId)))
				{
					s16DTCCounter = mDDBGetDTCTriggerValue(u8DTCId);
				}
			}
			mSetDTCTestCounter(u8DTCId, s16DTCCounter);
			if (s16DTCCounter == ((S16)mDDBGetDTCTriggerValue(u8DTCId)))
			{
				mSetDTCBit(u8CurStatus, cu8DTCMaskConfirmedDTC);
				if(cFalse == mDATDiiIsSetFlag(sau8IsLastStatusDefected,u8DTCId))
				{
				    bSaveDTC = cTrue;//只有故障第一次发生时进行保存

				    mDATDiiSetFlag(sau8IsLastStatusDefected,u8DTCId);
				}
			}
			mSetDTCBit(u8CurStatus, cu8DTCMaskTestFailed);
			//Only when IGOn it is allowed to set cu8DTCMaskTestFailedThisOperationCycle
			//because IGOff is not in operationcycle 
			if (mIsIGOn)
			{
				mSetDTCBit(u8CurStatus, cu8DTCMaskTestFailedThisOperationCycle);
			}
			mSetDTCBit(u8CurStatus, cu8DTCMaskTestFailedSinceLastClear);

		}
		else
		{
			s16DTCCounter = mGetDTCTestCounter(u8DTCId);
			if (s16DTCCounter > 0)
			{
				s16DTCCounter -= mDDBGetDTCHealedStep(u8DTCId);
				if (s16DTCCounter <= 0)
				{
					s16DTCCounter = 0;

					mDATDiiClearFlag(sau8IsLastStatusDefected,u8DTCId);
				}
			}
			else
			{
				mDATDiiClearFlag(sau8IsLastStatusDefected,u8DTCId);
			}

			mSetDTCTestCounter(u8DTCId, s16DTCCounter);
			mClearDTCBit(u8CurStatus, cu8DTCMaskTestFailed);
		}

		//status must be updated at the end!
		mDDBWriteRecordField(u8DTCId, Status, u8CurStatus);

		if (bSaveDTC != cFalse)
		{
			//save DTC data into the non-volatile memory...
			//this is only for the DTC which requires immediate comfirmation
			mDDBSaveDTC(u8DTCId);
		}
	}
}

//==============================================================================
//=========================== EXPORTED FUNCTIONS ===============================
//==============================================================================

//==============================================================================
// DESCRIPTION         : 导出DTC状态
//
// PARAMETERS          : DTC ID
// (Type,Name,Min,Max)
//
// RETURN VALUE        : TURE:Occur  False:not Occur
//
// DESIGN INFORMATION  : Refer to Detailed Design Document
//==============================================================================
BOOL DATDtcGetDTCStatus(U8 u8DTCId)
{
    BOOL bRet = cFalse;

    if(u8DTCId < eDTCFunCom_Count)
    {
        bRet = mDATDiiIsSetFlag(sau8IsLastStatusDefected,u8DTCId);
    }

    return bRet;
}

//==============================================================================
// DESCRIPTION         : Manage activation of monitoring cycles
//
// PARAMETERS          : u8Category - DTC category regarding the enum eDTCCategory
//                       u1Activate - 1 - activate monitoring cycle
//                                    0 - deactivate monitoring cycle
// (Type,Name,Min,Max)
//
// RETURN VALUE        : None
//
// DESIGN INFORMATION  : Refer to Detailed Design Document
//==============================================================================
void DATDtcControlMonitoringCycle(const U8 u8Category, const U1 u1Activate)
{
	if (u8Category < eDTCFunCom_Count)
	{
		if (u1Activate != (U1) 0)
		{
			if (mIsFunComMonitored(u8Category) == cFalse)
			{
				mActivateFunComMonitoring(u8Category);
			}
			else
			{
				//do nothing...
			}
		}
		else
		{
			if (mIsFunComMonitored(u8Category) == cTrue)
			{
				mDeactivateFunComMonitoring(u8Category);
			}
			else
			{
				//do nothing...
			}
		}
	}
	else
	{
		mLIBassert(cFalse);
	}
}

//==============================================================================
// DESCRIPTION         : Initialization of memorization flags
//
// PARAMETERS          : None
// (Type,Name,Min,Max) 
//
// RETURN VALUE        : None
//
// DESIGN INFORMATION  : Refer to Detailed Design Document
//==============================================================================
void DATDiiInit(void)
{
	U8 u8DTCID;

	for (u8DTCID = 0U; u8DTCID < (U8) eDTCIDCount; u8DTCID++)
	{
		mDATClearDTCOccurredInCurrentIGCycleFlag(u8DTCID);
		mDATClearDTCOccurredFlag(u8DTCID);
		mDATSetDTCDeletedDrivingCycles(u8DTCID, 0U);
	}

    u8DiiState = eDiiStateIgOffing;	// by default, assume not IG on, so not Driving Cycle Begin
	(void)mLIBmemset(as16DTCDetectionCounter, 0U, sizeof(as16DTCDetectionCounter));
	//write 0X00 means disabling all the components
	(void)mLIBmemset(au8EnabledFunComMonitoring, 0U, sizeof(au8EnabledFunComMonitoring));

    //初始化上次是否故障状态位
	(void)mLIBmemset(sau8IsLastStatusDefected, 0U, sizeof(sau8IsLastStatusDefected));
}

//==============================================================================
// DESCRIPTION         : Component initialization and task start upon
//                       entering active state (DATEnterActiveState)
//
// PARAMETERS          : None
// (Type,Name,Min,Max) 
//
// RETURN VALUE        : None
//
// DESIGN INFORMATION  : Refer to Detailed Design Document
//==============================================================================
void DATDiiEnterActiveState(void)
{
	DATDiiTaskAlarm.TaskID = cTOSTaskID_DATDtcTask;
    TOSSetRelAlarm(&DATDiiTaskAlarm, 0U, mTOSConvMsEnTickAlarm(cDatDiiTaskPeriod));
}

//==============================================================================
// DESCRIPTION         : Task stop upon leaving active state (DATLeaveActiveState)
//
// PARAMETERS          : None
// (Type,Name,Min,Max) 
//
// RETURN VALUE        : None
//
// DESIGN INFORMATION  : Refer to Detailed Design Document
//==============================================================================
void DATDiiLeaveActiveState(void)
{
	TOSCancelAlarm(&DATDiiTaskAlarm);
}

//==============================================================================
// DESCRIPTION         : Component task: management of memorization timers and
//                       actions for DTC memorization when timer elapses
//
// PARAMETERS          : None
// (Type,Name,Min,Max) 
//
// RETURN VALUE        : None
//
// DESIGN INFORMATION  : Refer to Detailed Design Document
//==============================================================================
void DATDiiTask(void)
{
	U8 u8DTCID;
	U8 u8Status;
	U8 u8DeletedDTCIndexInEEP;
	//U8 u8DTCFunc;

    switch (u8DiiState)
	{
        case eDiiStateIgOffing:
            if (cFalse == mIsIGOn)
            {
                break;	// do nothing as Ig Off, stay in this state
            }
            else
            {
                u8DiiState = eDiiStateIgOff2On;
                // parai: no break here, fall to state eDiiStateIgOff2On
            }
        case eDiiStateIgOff2On:
            // driving cycle begin
            for (u8DTCID = 0U; u8DTCID < (U8) eDTCIDCount; u8DTCID++)
            {
                u8Status = mDDBReadRecordField(u8DTCID, Status);

                //operation cycle is IGOn and then IGOff, so you have to initialize the
                //cu8DTCMaskTestNotCompletedThisOperationCycle
                //when IGOn
                //now the cu8DTCMaskTestNotCompletedThisOperationCycle is supported
                mSetDTCBit(u8Status, cu8DTCMaskTestNotCompletedThisOperationCycle);
                mClearDTCBit(u8Status, cu8DTCMaskTestFailedThisOperationCycle);
                mDDBWriteRecordField(u8DTCID, Status, u8Status);
			}
            u8DiiState = eDiiStateIgOning;
            // parai: no break here, fall to state eDiiStateIgOning
        case eDiiStateIgOning:
            if (cTrue == mIsIGOn)
            {
                break;	// do nothing as Ig On, stay in this state
            }
            else
            {
                u8DiiState = eDiiStateIgOn2Off;
                // parai: no break here, fall to state eDiiStateIgOn2Off
            }
        case eDiiStateIgOn2Off:
            if ((bControlDTCSetting == cControlDTCSettingStopCheck)
                    && (mSERRead(U1Bit, IsDiagMode, Default)))
            {
                //do nothing, this ig cycle will be ignored
            }
            else
            {	//driving cycle end
                for (u8DTCID = 0U; u8DTCID < (U8) eDTCIDCount; u8DTCID++)
                {
                    u8Status = mDDBReadRecordField(u8DTCID, Status);
                    //u8DTCFunc = mDDBGetDTCFunCom(u8DTCID);
                    // TODO: mIsFunComMonitored(u8DTCFunc), this is not OK, for each DTC its operation cycle may not be
                    // synchronous with Ig Cycle
                    // with in an IG operation cycle, it has been completed and the DTC is confirmed and the DTC does not occur
                    // in current driving cycle until now
                    if ( /* mIsFunComMonitored(u8DTCFunc) && */
                         (mIsBitSet(u8Status,cu8DTCMaskTestNotCompletedThisOperationCycle) == cFalse) &&
                         mIsBitSet(u8Status,cu8DTCMaskTestFailedSinceLastClear) &&
                         (mIsBitSet(u8Status,cu8DTCMaskTestFailedThisOperationCycle) == cFalse))
                    {
                        mDATIncreaseDTCDeletedDrivingCycles(u8DTCID);
                    }
                }
                //check every DTC, enumerate all the possibilities: DTC to be confirmed,DTC to be repaired,DTC to be deleted
                for (u8DTCID = 0U; u8DTCID < (U8) eDTCIDCount; u8DTCID++)
                {
                    //DTC to be deleted
                    //delete DTC in EEPROM and clear the related info
                    if (cMAXDTCDeletedDrivingCycles == mDATGetDTCDeletedDrivingCycles(u8DTCID))
                    {
                        u8DeletedDTCIndexInEEP=mDDBGetClearedDTCIndexInEep(u8DTCID);
                        //delete DTC in EEPOM
                        mDDBClearDTCByIndexInEEP(u8DeletedDTCIndexInEEP);

                        //clear the DTC occur flag
                        mDATClearDTCOccurredFlag(u8DTCID);

                        //clear the DTC occur in current IG cycle flag
                        mDATClearDTCOccurredInCurrentIGCycleFlag(u8DTCID);

                        //clear the DTC deleted cycles value
                        mDATSetDTCDeletedDrivingCycles(u8DTCID,0U);

                        mSetDTCTestCounter(u8DTCID,0U);

                        //get the DTC status
                        u8Status = mDDBReadRecordField(u8DTCID, Status);
                        //u8Status = 0;//change by zc 2017-6-19 与闫松涛沟通确认此处有误
                        mSetDTCBit(u8Status, cu8DTCMaskTestNotCompletedSinceLastClear);
                        mSetDTCBit(u8Status, cu8DTCMaskTestNotCompletedThisOperationCycle);

                        //status must be updated at the end!
                        mDDBWriteRecordField(u8DTCID, Status, u8Status);
                    }
                }
            }
            u8DiiState = eDiiStateIgOffing;
            break;
        default:
            u8DiiState = eDiiStateIgOffing;				// restart for safety.
            mLIBassert(0);
            break;
        }
}

//==============================================================================
// DESCRIPTION         : Prepare the data when DTC has to be reported. Interface
//                       for other components 
//
// PARAMETERS          : u8DTC - enum for DTC fault regarding the enum eDTCIds
//                       bFailed - TRUE if defect was detected, otherwise FALSE
// (Type,Name,Min,Max) 
//
// RETURN VALUE        : None
//
// DESIGN INFORMATION  : Refer to Detailed Design Document
//==============================================================================
void DATDiiPrepareDTC(const U8 u8DTC, const BOOL bFailed)
{

	if (u8DTC < eDTCIDCount)
	{
		su8DTCForReporting = u8DTC;
		sbIsDTCFailed = bFailed;
	}
	else
	{
		//mLIBassert(cFalse);
		su8DTCForReporting = cu8NoDTCToReport;
	}
}

//==============================================================================
// DESCRIPTION         : Report a previously prepared data for DTC. Interface
//                       function for other components
//
// PARAMETERS          : None
// (Type,Name,Min,Max) 
//
// RETURN VALUE        : None
//
// DESIGN INFORMATION  : Refer to Detailed Design Document
//==============================================================================
void DATDiiReportDTCStatus(void)
{
	U8 u8DTCDefectCode;

	if (su8DTCForReporting != cu8NoDTCToReport) //zjb error find by debug
	{
		u8DTCDefectCode = mDDBGetDTCFunCom(su8DTCForReporting);
		if (mIsFunComMonitored(u8DTCDefectCode) != cFalse)//判断是否使能
		{
			ProcessDTC(su8DTCForReporting, sbIsDTCFailed);
		}
		su8DTCForReporting = cu8NoDTCToReport;
	}
	else
	{
		//zjb error find by debug. assert failed
		//reporting a DTC is called without preparing the data first
		mLIBassert(cFalse);
	}
}

//==============================================================================
// DESCRIPTION         : This function is intended to be used for DTCs that
//                       require special confirmation conditions. with it,
//                       components that report DTCs can determine which DTC 
//                       is being processed at the moment. like this, DTC reporting
//                       components will know if DTC under verification is their
//                       or not
//
// PARAMETERS          : None
// (Type,Name,Min,Max) 
//
// RETURN VALUE        : None
//
// DESIGN INFORMATION  : Refer to Detailed Design Document
//==============================================================================
U8 DATDiiGetDTCForReporting(void)
{
	return su8DTCForReporting;
}

//==============================================================================
// DESCRIPTION         :  clear the DTC debouncing counter
//                        
//
// PARAMETERS          : None
// (Type,Name,Min,Max) 
//
// RETURN VALUE        : None
//
// DESIGN INFORMATION  : Refer to Detailed Design Document
//==============================================================================
void DATDiiClearDTCTestCounter(void)
{
	mLIBmemset(as16DTCDetectionCounter, 0U, sizeof(as16DTCDetectionCounter));
}

//==============================================================================
// DESCRIPTION         : Clears a specific DTC memorization flags. 
//                       
//
// PARAMETERS          : None
// (Type,Name,Min,Max) 
//
// RETURN VALUE        : None
//
// DESIGN INFORMATION  : Refer to Detailed Design Document
//==============================================================================
void DATDiiClearTestCounterByDTCCode(U8 u8DTC)
{
	mSetDTCTestCounter(u8DTC, 0U);
}
//==============================================================================
// DESCRIPTION         : 
//
// PARAMETERS          : None
// (Type,Name,Min,Max) 
//
// RETURN VALUE        : None
//
// DESIGN INFORMATION  : Refer to Detailed Design Document
//==============================================================================
void DATDiiSetControlDTCSettingValue(BOOL bValue)
{
	bControlDTCSetting = bValue;
}



void DATDiiReportDTC(tDTCFunCom tDTCType, BOOL bIsDTCOccur)
{
    DATDiiPrepareDTC((tDTCType), (bIsDTCOccur));//此处参数类型与原型不符
    DATDiiReportDTCStatus();
}
