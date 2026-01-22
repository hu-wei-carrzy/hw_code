

#define dat_ddb  "dat_ddb"


//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//
// #include <system_file_name.h>
// #include "project_file_name.h"
//------------------------------------------------------------------------------

#define cDAT_DDB_SELFINCLUDE
#include "DAT_DDB.h"



//------------------------------------------------------------------------------
// Local constants
//
// #define cConstantName   ((tType) ConstantValue)
//------------------------------------------------------------------------------
// EEPROM stores only the last ten (memorized) defects
#define cDTCRecords                             ((U8)23U) //now only 21 is used
#define cEEPDTCBufferLen                        (U8)(cDTCRecords*cDTCRecordSize)
#define cDTCRecordSize                          ((U8)2U)//5)
#define cInvalidDTCId                           ((U8)0xFFU)

// EEPROM DTC offset constants
//#define cDTCIdOffset                            ((U8)0x00U)
//#define cOccurrenceKmOffset                     ((U8)0x02U)
//不在eep存储Id与故障发生时里程，只存储状态与发送次数
#define cStatusOffset                           ((U8)0x00U)
#define cFaultOccurCntOffset                         ((U8)0x01U)


//------------------------------------------------------------------------------
// Local macros
//
// #define mMacroName   (MacroDefinition)
//------------------------------------------------------------------------------
//#define mSERWriteTableU8BitEEP_DTCDatabaseDefault( Index, ValueToWrite )  0
//#define mSERWriteTableU8BitEEP_DTCDatabaseImmediate( Index, ValueToWrite )  0
//#define mSERReadTableU8BitEEP_DTCDatabaseDefault( Index )   0

//------------------------------------------------------------------------------
// Local types
//
// typedef Expression    tTypeName;
//------------------------------------------------------------------------------
typedef struct sDTCInfo_tag
{
	//note: this is only an index used in au16DTCDefectCodes[].
	//the real DTCcode is in au16DTCDefectCodes[].
	U8	u8DTCFunCom;
	//the is value is the lowest byte of DTCcode referring to fault type
	U8	u8DTCType;
	U16 u16DTCDefectCodes; //将故障码高两个字节也移到这个结构体中，去掉单独的数组，便于统一管理
	U16	u16DTCTriggerValue;
	U8  u8DTCConfirmedStep;
	U8  u8DTCHealedStep;
} sDTCInfo;

typedef struct sDTCStorage_tag
{
	//this status is a combination which has the same meaning with csDAM
    U8  u8DTCStatus;
    U8  u8FaultOccurCnt;//故障发生次数
} sDTCStorage;
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
//
static sDTCStorage asDTCStorage[eDTCIDCount];


//the two variables is to stand for the DTC to be deleted
static U32  u32SpecificDTCCodeToCleared;
static U8   u8SpecificDTCIdToCleared;
//------------------------------------------------------------------------------
// Constant local data
//
// static const tType  VariableName;
//------------------------------------------------------------------------------
//this array stores all the DTC info
static const sDTCInfo asDTCInfo[eDTCIDCount] =
{
	//the content of dat_ddb_descr.h is macro defination like this:
	//DTC_DEFINE(eDTCFuelOpenCircuit,  eDTCFunCom_Fuel, 0x13U, 6, 6,4)
	//the content of the struct sDTCInfor is :eDTCFunCom_Fuel, 0x13U, 6, 6,4
	//and eDTCFuelOpenCircuit is a index for au16DTCDefectCodes[]
    #define DTC_DEFINE_STRUCT
    #include "dat_ddb_descr.h"
    #undef DTC_DEFINE_STRUCT
};
//because there is only 2 message on the index 2 and 3, so there is no need to list all the relationship between
//eDTCID and message handler
#if 0
static const U8 u8eDTCIDToMsgHandler[] =
{
//0XFF means there is no corresponding message handler
		0XFF,                                          //eDTCIDLimpHome,
		0XFF,                                          //eDTCIDDimmerCircuit,
		//cDATCdlD_UURxHandlePEPS_0x320,                 //eDTCIDPEPSFrameLost,
		//cDATCdlD_UURxHandleBCM_0x310                   //eDTCIDBCMFrameLost,
};
#endif
//DTC code has 3 bytes. And this array contains the higher two bytes
//note:the sequence should be line with sequence in eDTCFunCom_Count
#if 0
static const U16 au16DTCDefectCodes[eDTCFunCom_Count] =
{
    (U16)0xa00,
    (U16)0xa00,
    (U16)0xa00,
    (U16)0x806,
    (U16)0x800,
    (U16)0x300,
    (U16)0x300,
    (U16)0x300,
    (U16)0x300,
    (U16)0xe6e0,
    (U16)0xe3e0,
    (U16)0xe6e0,
    (U16)0xe3e0,
    (U16)0xe6e0,
    (U16)0xe3e0,
    (U16)0xe6e0,
    (U16)0xe3e0,
    (U16)0xe3e0,
    (U16)0xe4e0,
    (U16)0xf3e0,

    (U16)0xf3e1,
    (U16)0xf3e2,
    (U16)0xf3e3,
    (U16)0xf3e4,
    (U16)0xf3e5,
    (U16)0xf3e6,
    (U16)0xf3e7,
    (U16)0xf3e8,
    (U16)0xf3e9,
    (U16)0xf3e10,
    (U16)0xf3e11,
    (U16)0xf3e12,
    (U16)0xf3e13

};
#endif

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
static U8 GetFaultOccurCntAdd(const U8 u8DTCId);
//==============================================================================
//=========================== LOCAL FUNCTIONS ==================================
//==============================================================================


//==============================================================================
// DESCRIPTION         : Find the place to store the current defect
//
// PARAMETERS          : u8DTCId - Defect Id
//
// RETURN VALUE        : the EEPROM DTC database index
//
// DESIGN INFORMATION  : Refer to Detailed Design Document
//==============================================================================
#if 0   //221不在eep中存储故障ID，所以此函数无用
static U8 GetEEPDefectIndex(const U8 u8DTCId)
{
    U8 u8DTCIdIndex;
    U8 u8TargetSlot;
    U8 u8CurrentDTCId;
    BOOL bPositionFound = cFalse;

    mLIBassert(u8DTCId < eDTCIDCount);

    u8TargetSlot = cInvalidDTCId;

    for (u8DTCIdIndex = 0;
         ((u8DTCIdIndex < cEEPDTCBufferLen) && (bPositionFound == cFalse));
         (u8DTCIdIndex += cDTCRecordSize))
    {
          u8CurrentDTCId = mSERReadTable( U8Bit,
                                          EEP_DTCDatabase,
                                          (U8)(u8DTCIdIndex + cDTCIdOffset),
                                          Default );

        //u8DTCId == u8CurrentDTCId means this DTC has been storted in eep previously
        //u8CurrentDTCId == cInvalidDTCId means finding a empty position which can be
        //store current DTC information

        //note:there may be a empty position between two DTC information in eeprom,
        //therefore, when you get DTC information by diagnostic service, you should
        //skip the empty position.
          if (u8DTCId == u8CurrentDTCId)
          {     // found out the old location
              bPositionFound = cTrue;
              u8TargetSlot = u8DTCIdIndex;
          }
          else if(u8CurrentDTCId == cInvalidDTCId)
          {
              if(cInvalidDTCId == u8TargetSlot)
              {
                  u8TargetSlot = u8DTCIdIndex;  // update it to the first free position
              }
              else
              {
                  // do nothing, as the free position is ready
              }
          }
          else
          {
              // continue...
          }
    }

    // If none was found (all 20 DTC slots are full, no such DTC has been
    // stored before), overwrite the oldest record

    // NOTE: SW now have enough slot.
    //zjb error find by debug. assert failed
    //mLIBassert((cTrue==bPositionFound) || (u8TargetSlot!=cInvalidDTCId));

    return u8TargetSlot;
}
#endif
static U8 GetFaultOccurCntAdd(const U8 u8DTCId)
{
    U8 u8OccurCnt = 0U;
    u8OccurCnt = DATDdbGetDTCOccurCnt(u8DTCId);
    if(cU8DtcValueMax > u8OccurCnt)
    {
        u8OccurCnt ++;
    }

    return u8OccurCnt;
}

//==============================================================================
//=========================== EXPORTED FUNCTIONS ===============================
//==============================================================================

//==============================================================================
// DESCRIPTION         : Reads the status of given DTC (type and defect)
//
// PARAMETERS          : u8DTC - the DTC type and defect
//
// RETURN VALUE        : Status of requested DTC
//
// DESIGN INFORMATION  : Refer to Detailed Design Document
//==============================================================================
U8 DATDdbGetDTCStatus(const U8 u8DTC)
{
	mLIBassert(u8DTC < eDTCIDCount);

    return (asDTCStorage[u8DTC].u8DTCStatus);

}

//==============================================================================
// DESCRIPTION         : Reads on which Km (according to the odometer) the
// 					     given DTC has occurred
//
// PARAMETERS          : u8DTC - the DTC type and defect
//
// RETURN VALUE        : Last Km value when the DTC has occurred
//
// DESIGN INFORMATION  : Refer to Detailed Design Document
//==============================================================================
U8 DATDdbGetDTCOccurCnt(const U8 u8DTC)
{
	mLIBassert(u8DTC < eDTCIDCount);

    return (asDTCStorage[u8DTC].u8FaultOccurCnt);
}

//==============================================================================
// DESCRIPTION         : Sets status on a DTC
//
// PARAMETERS          : u8DTC - the DTC type and defect
//                       u8Status - status to be set
//
// RETURN VALUE        : None
//
// DESIGN INFORMATION  : Refer to Detailed Design Document
//==============================================================================
void DATDdbSetDTCStatus(const U8 u8DTC, const U8 u8Status)
{
    mLIBassert(u8DTC < eDTCIDCount);

    asDTCStorage[u8DTC].u8DTCStatus = u8Status;
}

//==============================================================================
// DESCRIPTION         : Stores the data for given DTC into the EEPROM
//
// PARAMETERS          : u8DTC - the DTC type and defect
//
// RETURN VALUE        : None
//
// DESIGN INFORMATION  : Refer to Detailed Design Document
//==============================================================================
void DATDdbSaveDTC(const U8 u8DTCId)
{
    U8 u8DtcIndex = 0U;
    U8 u8FaultOccurCnt = 0U;

    mLIBassert(u8DTCId < eDTCIDCount);

    u8DtcIndex = cDTCRecordSize * u8DTCId;//ID换算成eep存储位置

    //存储故障发生次数+1
    u8FaultOccurCnt = GetFaultOccurCntAdd(u8DTCId);
    //更新asDTCStorage数组发生次数
    mDDBWriteRecordField(u8DTCId, OccurCnt, u8FaultOccurCnt);

    //存储到eep
    mSERWriteTable(U8Bit, EEP_DTCDatabase, u8DtcIndex + cStatusOffset, asDTCStorage[u8DTCId].u8DTCStatus, Default);
    mSERWriteTable(U8Bit, EEP_DTCDatabase, u8DtcIndex + cFaultOccurCntOffset, u8FaultOccurCnt, Default);

}


//==============================================================================
// DESCRIPTION         : Sets occurrence Km on a DTC
//
// PARAMETERS          : u8DTC - the DTC type and defect
// 					     u32Km - km
//
// RETURN VALUE        : None
//
// DESIGN INFORMATION  : Refer to Detailed Design Document
//==============================================================================
void DATDdbSetDTCOccurCnt(const U8 u8DTC, const U8 u8OccurCnt)
{
	mLIBassert(u8DTC < eDTCIDCount);

    asDTCStorage[u8DTC].u8FaultOccurCnt = u8OccurCnt;
}

//==============================================================================
// DESCRIPTION         : Clears the DTC info in EEP
//
// PARAMETERS          : None
//
// RETURN VALUE        : None
//
// DESIGN INFORMATION  : Refer to Detailed Design Document
//==============================================================================
void DATDdbClearAllEEPRecords(void)
{
	U8 u8i = 0U;
	U8 u8Pos = 0U;

	for (u8i = 0U; u8i < eDTCIDCount; u8i ++)
    {
	    u8Pos = u8i * cDTCRecordSize;//一个DTC在eep中占据两个U8位置，注意DTC个数不要超过127
        mSERWriteTable(U8Bit, EEP_DTCDatabase, (U8)(u8Pos + cStatusOffset), (cu8DTCMaskTestNotCompletedSinceLastClear
            | cu8DTCMaskTestNotCompletedThisOperationCycle), Default);
        mSERWriteTable(U8Bit, EEP_DTCDatabase, (U8)(u8Pos + cFaultOccurCntOffset), (U8 )0U, Default);

    }
}

//==============================================================================
// DESCRIPTION         : Clears the DTC info in asStorage in RAM
//
// PARAMETERS          : None
//
// RETURN VALUE        : None
//
// DESIGN INFORMATION  : Refer to Detailed Design Document
//==============================================================================
void DATDdbClearAllDTCRAMStorage(void)
{
	U8 u8i = 0U;
	// The RAM database is gone too
    for ( u8i = 0U; u8i < eDTCIDCount; u8i++ )
    {
        asDTCStorage[u8i].u8DTCStatus = cu8DTCMaskTestNotCompletedSinceLastClear | cu8DTCMaskTestNotCompletedThisOperationCycle;
        asDTCStorage[u8i].u8FaultOccurCnt  = 0U;
    }
}
//==============================================================================
// DESCRIPTION         : Gets the defect code against the DTC enumerator number
//
// PARAMETERS          : u8DTC - the DTC type and defect
//
// RETURN VALUE        : Renault Defect code
//
// DESIGN INFORMATION  : Refer to Detailed Design Document
//==============================================================================
U16 DATDdbGetDTCDefectCodeByFault(const U8 u8DTCId)
{
	mLIBassert(u8DTCId < eDTCIDCount);
	//asDTCInfo[u8DTCId].u8DTCFunCom] is a enum value, which is defined in DAT_DII.h
	//its format is like this: eDTCFunCom_Dimmer
	//return au16DTCDefectCodes[asDTCInfo[u8DTCId].u8DTCFunCom];
	return asDTCInfo[u8DTCId].u16DTCDefectCodes;
}

//==============================================================================
// DESCRIPTION         : Gets the defect type against the DTC enumerator number
//
// PARAMETERS          : u8DTC - the DTC type and defect
//
// RETURN VALUE        : Renault Defect type code
//
// DESIGN INFORMATION  : Refer to Detailed Design Document
//==============================================================================
U8 DATDdbGetDTCDefectType(const U8 u8DTCId)
{
	mLIBassert(u8DTCId < eDTCIDCount);

	return asDTCInfo[u8DTCId].u8DTCType;
}

//==============================================================================
// DESCRIPTION         : Gets trigger value(means debouncing value)
// PARAMETERS          : u8DTC - the DTC type and defect
//
// RETURN VALUE        : the deboucing value
//
// DESIGN INFORMATION  : Refer to Detailed Design Document
//==============================================================================
U16 DATDdbGetDTCTriggerValue(const U8 u8DTC)
{
	mLIBassert(u8DTC < eDTCIDCount);

	return asDTCInfo[u8DTC].u16DTCTriggerValue;
}

//==============================================================================
// DESCRIPTION         : DATDdbGetDTCConfirmedStep
// PARAMETERS          : u8DTC - the DTC type and defect
//
// RETURN VALUE        : the confirmed step value
//
// DESIGN INFORMATION  : Refer to Detailed Design Document
//==============================================================================
U8 DATDdbGetDTCConfirmedStep(const U8 u8DTC)
{
	mLIBassert(u8DTC < eDTCIDCount);

	return asDTCInfo[u8DTC].u8DTCConfirmedStep;
}

//==============================================================================
// DESCRIPTION         : DATDdbGetDTCHealedStep
// PARAMETERS          : u8DTC - the DTC type and defect
//
// RETURN VALUE        : the healed step value
//
// DESIGN INFORMATION  : Refer to Detailed Design Document
//==============================================================================
U8 DATDdbGetDTCHealedStep(const U8 u8DTC)
{
	mLIBassert(u8DTC < eDTCIDCount);

	return asDTCInfo[u8DTC].u8DTCHealedStep;
}
//==============================================================================
// DESCRIPTION         : Gets the defect code enumerator number
//
// PARAMETERS          : u8DTC - the DTC type and defect
//
// RETURN VALUE        : Defect enumerator value
//
// DESIGN INFORMATION  : Refer to Detailed Design Document
//==============================================================================
U8 DATDdbGetDTCFunCom(const U8 u8DTC)
{
	mLIBassert(u8DTC < eDTCIDCount);
	//asDTCInfo[u8DTC].u8DTCFunCom is index for array  au16DTCDefectCodes[]
	return asDTCInfo[u8DTC].u8DTCFunCom;
}

//==============================================================================
// DESCRIPTION         : Handle diagnostic session closing event
//                       Function is called also when entering active state in
//                       order to initialize bInDiagnosticSession
//
// PARAMETERS          : None
//
// RETURN VALUE        : None
//
// DESIGN INFORMATION  : Refer to Detailed Design Document
//==============================================================================
void DATDdbCloseDiagnosticSession(void)
{

}

//==============================================================================
// DESCRIPTION         : Handle diagnostic session opening event
//
// PARAMETERS          : None
//
// RETURN VALUE        : None
//
// DESIGN INFORMATION  : Refer to Detailed Design Document
//==============================================================================
void DATDdbOpenDiagnosticSession(void)
{

}

//==============================================================================
// DESCRIPTION         : Initialize the RAM DTC storage
//
// PARAMETERS          : None
//
// RETURN VALUE        : None
//
// DESIGN INFORMATION  : Refer to Detailed Design Document
//==============================================================================
void DATDdbInitialize(void)
{
    U8 u8Index = 0U;
    U8 u8DTCId = 0U;

    // Just for any case, initialize the DTC RAM storage to zero
    for ( u8Index = 0U; u8Index < eDTCIDCount; u8Index++ )
    {
        //asDTCStorage[u8Index].u8DTCStatus = cu8DTCMaskTestNotCompletedSinceLastClear;
        //asDTCStorage[u8Index].u32OccurKm = (U32)0;
        mDDBClearDTCRAMStorage(u8Index);
    }

    // Read the memorized faults and add them to the RAM storage
    for(u8DTCId = 0U; u8DTCId < eDTCIDCount ; u8DTCId++ )
    {
        u8Index = cDTCRecordSize * u8DTCId;//ID换算成eep存储位置

        asDTCStorage[u8DTCId].u8DTCStatus =
            mSERReadTable(U8Bit, EEP_DTCDatabase, (U8)(u8Index + cStatusOffset), Default);

        asDTCStorage[u8DTCId].u8FaultOccurCnt =
            (U32)mSERReadTable(U8Bit, EEP_DTCDatabase, (U8 )(u8Index + cFaultOccurCntOffset), Default);
    }

}

//==============================================================================
// DESCRIPTION         : get DTC position index by DTC value
//
// PARAMETERS          : None
//
// RETURN VALUE        : None
//
// DESIGN INFORMATION  : Refer to Detailed Design Document
//==============================================================================
U8 DATDdbGetClearedDTCIndexInEep(const U8 u8DTCId)
{
#if 0
	U8 u8PosIndex;
	U8 u8CurrentDTCId;
	U8 u8TargetSlot=0XFF;
	BOOL bPositionFound=cFalse;
    for(u8PosIndex = 0;
        ((u8PosIndex < cEEPDTCBufferLen ) && (bPositionFound == cFalse));
        (u8PosIndex += cDTCRecordSize))
    {
        u8CurrentDTCId =
            mSERReadTable(U8Bit, EEP_DTCDatabase, (U8)(u8PosIndex + cDTCIdOffset), Default);
        if(u8DTCId == u8CurrentDTCId)
        {
            bPositionFound = cTrue;
            u8TargetSlot = u8PosIndex;
        }
    }

	return u8TargetSlot;
#endif
	return 0U;
}

//==============================================================================
// DESCRIPTION         : Delete DTC info in EEPROM
//
// PARAMETERS          : None
//
// RETURN VALUE        : None
//
// DESIGN INFORMATION  : Refer to Detailed Design Document
//==============================================================================
void DATDdbClearDTCByIndexInEEP(const U8 u8DTCIndexInEEP)
{
#if 0   //存储DTC方式改变，暂时不用
	if(u8DTCIndexInEEP < cDTCRecords*cDTCRecordSize)
	{
		mSERWriteTable(U8Bit, EEP_DTCDatabase,
				(U8)(u8DTCIndexInEEP + cDTCIdOffset), cInvalidDTCId, Default);
		mSERWriteTable(U8Bit, EEP_DTCDatabase,
				(U8)(u8DTCIndexInEEP + cStatusOffset), (cu8DTCMaskTestNotCompletedSinceLastClear|cu8DTCMaskTestNotCompletedThisOperationCycle), Default);
		mSERWriteTable(U8Bit, EEP_DTCDatabase,
				(U8)(u8DTCIndexInEEP + cOccurrenceKmOffset), (U8)0, Default);
		mSERWriteTable(U8Bit, EEP_DTCDatabase,
				(U8)(u8DTCIndexInEEP + cOccurrenceKmOffset + 1), (U8)0, Default);
		mSERWriteTable(U8Bit, EEP_DTCDatabase,
				(U8)(u8DTCIndexInEEP + cOccurrenceKmOffset + 2), (U8)0, Default);

	}
#endif
}
#ifdef Coverity_Not_Kill_DATDdbReadDeltedDTCCode
//==============================================================================
// DESCRIPTION         : Get the deleted DTC code
//
// PARAMETERS          : None
//
// RETURN VALUE        : None
//
// DESIGN INFORMATION  : Refer to Detailed Design Document
//==============================================================================
U32 DATDdbReadDeltedDTCCode(void)
{
	return u32SpecificDTCCodeToCleared;
}
#endif
//==============================================================================
// DESCRIPTION         : Set the deleted DTC code
//
// PARAMETERS          : None
//
// RETURN VALUE        : None
//
// DESIGN INFORMATION  : Refer to Detailed Design Document
//==============================================================================
void DATDdbWriteDeltedDTCCode(U32 u32DTCCode)
{
	u32SpecificDTCCodeToCleared=u32DTCCode;
}

//==============================================================================
// DESCRIPTION         : Check the existence of the deleted DTC code
//
// PARAMETERS          : None
//
// RETURN VALUE        : None
//
// DESIGN INFORMATION  : Refer to Detailed Design Document
//==============================================================================
BOOL DATDdbIsDTCCodeExist(void)
{
	U8 u8DTCIdIndex;
	BOOL bReturn=cFalse;
	u8SpecificDTCIdToCleared = 0U;
	for(u8DTCIdIndex = 0U;u8DTCIdIndex<eDTCIDCount;u8DTCIdIndex++)
	{
		if(((U32)(((mDDBGetDefectCodeByFault(u8DTCIdIndex))<<8) | (mDDBGetDefectType(u8DTCIdIndex))))==u32SpecificDTCCodeToCleared)
		{
			bReturn=cTrue;
			u8SpecificDTCIdToCleared=u8DTCIdIndex;
			break;
		}
	}

	return bReturn;
}
//==============================================================================
// DESCRIPTION         : Delete DTC info in eeprom by DTC Code
//
// PARAMETERS          : None
//
// RETURN VALUE        : None
//
// DESIGN INFORMATION  : Refer to Detailed Design Document
//=============================================================================
void DATDdbClearDTCByDTCCode(void )
{
	//u8DTCEEPIndex is index for DTC in eeprom
	//u8SpecificDTCIdToCleared is index for the RAM variables, like asDTCStorage[]
	U8 u8DTCEEPIndex;

	//get the DTC eeprom index from DTC index in RAM variables
	u8DTCEEPIndex=DATDdbGetClearedDTCIndexInEep(u8SpecificDTCIdToCleared);

	if (u8DTCEEPIndex!= 0XFFU)
	{
		//clear the storage info in RAM
		//asDTCStorage[u8SpecificDTCIdToCleared].u8DTCStatus = cu8DTCMaskTestNotCompletedSinceLastClear;
		//asDTCStorage[u8SpecificDTCIdToCleared].u32OccurKm = (U32)0;
		mDDBClearDTCRAMStorage(u8SpecificDTCIdToCleared);

		//clear the memory in RAM
		mDIIClearTestCounterByDTCCode(u8SpecificDTCIdToCleared);

		//clear eeprom DTC info
		DATDdbClearDTCByIndexInEEP(u8DTCEEPIndex);
		DATDdbResetTimerByClearSpecificDTC(u8SpecificDTCIdToCleared);
	}
}


//==============================================================================
// DESCRIPTION         : Clear the DTC info in asDTCStorage
//
// PARAMETERS          : None
//
// RETURN VALUE        : None
//
// DESIGN INFORMATION  : Refer to Detailed Design Document
//=============================================================================
void DATDdbClearDTCRAMStroage(U8 u8DTCId)
{
	mLIBassert(u8DTCId < eDTCIDCount);
	asDTCStorage[u8DTCId].u8DTCStatus = (cu8DTCMaskTestNotCompletedSinceLastClear|cu8DTCMaskTestNotCompletedThisOperationCycle);
	asDTCStorage[u8DTCId].u8FaultOccurCnt = (U8)0;
}
//==============================================================================
// DESCRIPTION         : DATDdbStopAllTimrByClearAllDTC
//
// PARAMETERS          : None
//
// RETURN VALUE        : None
//
// DESIGN INFORMATION  : Restart all DTC related timer by clearing all DTC info
//=============================================================================
//=============================================================================
void DATDdbResetAllTimrByClearAllDTC(void)
{
	//note:here should add some action for the limp home state
	//DATPanDimmerResetTimerByClearSpecificDTC();
	//DATBatVoltageResetTimerByClearSpecificDTC();
	DATCilFramRxSurveyRestart();
}
//==============================================================================
// DESCRIPTION         : DATDdbStopTimerByClearSpecificDTC
//
// PARAMETERS          : None
//
// RETURN VALUE        : None
//
// DESIGN INFORMATION  : Restart specific DTC related timer by clearing specific DTC info
//=============================================================================
//=============================================================================
void DATDdbResetTimerByClearSpecificDTC(U8 u8DTCIndex)
{
	//U8 u8MsgHandler = 0XFFU;
	//here stop the timer
		switch(u8DTCIndex)
		{
			//case eDTCIDSpeedMsgLost:
				//to be continue, ZJB
				//here should notify the NM to do something
				//break;
			//case eDTCIDTachoMsgLost:
				//DATPanDimmerResetTimerByClearSpecificDTC();
				//break;
			//case eDTCIDWaterTempMsgLost:
			//case eDTCIDOilPrsMsgLost:
				//DATBatVoltageResetTimerByClearSpecificDTC();
						//break;
			//case eDTCIDTrumpetMsgLost:
				//do nothing because there is no timer for BusOff
						//break;
			//case eDTCIDClkMsgLost:
			//case eDTCIDSpeedMsgOver:
				//message related timer
				//u8MsgHandler = u8eDTCIDToMsgHandler[u8DTCIndex];
				//DATCilFramRxSurveyRestartByHandle(u8MsgHandler);
						//break;
			//case eDTCIDTachoMsgOver:
				//TOSSendControl(cTOSControlTTResetDtcTimer);
				//break;
			default:
				;//error value
				break;
     }
}


//==============================================================================
// DESCRIPTION        : Performs clear DTC database regarding
//                      ClearDiagnosticInformation requirements
//
// PARAMETERS         : None
//
// RETURN VALUE       : None
//
// DESIGN INFORMATION : Refer to Detailed Design Document
//==============================================================================
void DATDdbClearAllDTCInfo(void)
{
    mDDBClearAllEEPRecords();
    mDDBClearAllRAMStorage();
    mDIIClearDTCTestCounter();
    mDDBStopAllTimerByClearAllDTC();
}
