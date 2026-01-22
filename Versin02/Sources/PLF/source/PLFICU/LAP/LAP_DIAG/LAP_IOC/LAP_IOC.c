
//******************************************************************************
// Copyright:    This software is JYD property.
//               Duplication or disclosure without JYD written authorization
//               is prohibited.
// -----------------------------------------------------------------------------
// Project:      ICU511
// Language:     C
// -----------------------------------------------------------------------------
// Component:    IOC
// -----------------------------------------------------------------------------
//******************************************************************************
// This line is used to separate code and file header.This is begin.
//*****************************BEGIN_NOMOVE*************************************
//2017年11月27日 15:27:13
//3356, zjb
//1：在退出诊断时，发送0x74 0x01 0x01 指示图形板，退出诊断模式
//2：修改图形内容显示控制的最大值
//3：修改电机转速的最大值
//4：禁止C3输出，返回否定响应（因为没有硬线信号输入）
//*****************************END_NOMOVE***************************************
// This line is used to separate code and file header. This is last line.
//******************************************************************************
//------------------------------------------------------------------------------
// Body Identification
//------------------------------------------------------------------------------
#define LAP_IOC   "LAP_IOC"

//
//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//
// #include <system_file_name.h>
// #include "project_file_name.h"
//------------------------------------------------------------------------------
#define cLAP_IOC_SELFINCLUDE
#include "LAP_IOC.h"



//------------------------------------------------------------------------------
// Local constants
//
// #define cConstantName   ((tType) ConstantValue)
//------------------------------------------------------------------------------
//InputOutputControlParamenter
#define cReqIOCtrlReturnControlToECU        ((U8)0x00)
#define cReqIOCtrlFreezeCurrentState        ((U8)0x02)
#define    cReqIOCtrlShortTermAdjustment        ((U8)0x03)
#define IOControlParameter                    (LAPDiaMemorizedRequest.Buffer[3])

//DID service length is dynamic,so STK const length table not used
#define cLngIOCtrlReturnControlToECU        ((U8)4 )








//LCD display type
#define cIOCCtrlLCDPlant_MaxVal        ((U8)0x08U)

//PowerLock
#define cIOCtrlPowerLock_Lock               ((U8)0x00U)
#define cIOCtrlPowerLock_Release            ((U8)0x01U)




#define cIOControlBitNum   (32+16)

#define cIOControlFlagLength (U8)((cIOControlBitNum-1)/8 + 1)
//------------------------------------------------------------------------------
// Local macros
//
// #define mMacroName   (MacroDefinition)
//------------------------------------------------------------------------------
#define mLAPIOCIsSetFlag(Tab, Pos)\
        ((BOOL)(Tab[ ((U8)Pos>>3)] & (((U8)1)<<( (U8)(Pos & (U8)0x07)))) != 0)

#define mLAPIOCIsClearFlag(Tab, Pos)\
        ((BOOL)(Tab[ ((U8)Pos>>3)] & (((U8)1)<<( (U8)(Pos & (U8)0x07)))) == 0)

#define mLAPIOCSetFlag(Tab, Pos)\
        Tab[ ((U8)Pos>>3)] |= (((U8)1)<<( (U8)(Pos & (U8)0x07)))

#define mLAPIOCClearFlag(Tab, Pos)\
        Tab[ ((U8)Pos>>3)] &= ~(((U8)1)<<( (U8)(Pos & (U8)0x07)))

#define mLAPIOCClearAllFlag(Tab)        \
        mLIBmemset(Tab, 0, sizeof(Tab))
//------------------------------------------------------------------------------
// Local types
//
// typedef Expression    tTypeName;
//------------------------------------------------------------------------------
typedef void (*tLapDiaIOCUnLockCallback)(void);




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


//------------------------------------------------------------------------------
// Constant local data
//
// static const tType  VariableName;
//------------------------------------------------------------------------------

mLAPDiaIOCBIConstantsInitializaion()

//caution:the following table item id must be the same as IOCBIDidCallbacks item

static  void    IOCTestMod_UnLock(void );
static U8   IOC_CtrlOptRecordPro(U32 u32DIDIndex);
static void IOCDID_Pout_IOCtrl_UnLock( void);


//各IOClock状态记录列表
static  U8       su8ArrCurIOControlSt[cIOControlFlagLength];

// TODO:
//!!!!this array must has the same sequence with the IOCBIDidCallbacks!!!!
//!!!!when you add new IOControl ID, you should first check the sequence!!!!
static const tLapDiaIOCUnLockCallback IOCUnLockCallbacks_Flag[cLAPDiaIOCBIDidsCount] =
{
	IOCTestMod_UnLock,
	IOCDID_Pout_IOCtrl_UnLock,
};

static const tLapDiaIOCUnLockCallback IOCUnLockCallbacks_Action[cLAPDiaIOCBIDidsCount] =
{
	IOCTestMod_UnLock,
	IOCDID_Pout_IOCtrl_UnLock,
};

/*TODO: 由于目前的标定策略：标定完成会初始化session，所以此处不进行标定*/
static  void    IOCTestMod_UnLock(void )
{
	//mSERWrite(U8Bit, TestMode, 0u, DEFAULT);
}

static void IOCDID_Pout_IOCtrl_UnLock( void)
{
#if 0	//TODO:XXX
	mSERWrite(U8Bit, SetPoutLockState, 0, Default);
#endif
}

static U8 IOCTestMode_IOCtrlCallback( void)
{
	U8 u8TestCtl;

	u8TestCtl = LAPDiaMemorizedRequest.Buffer[0U + 4U];

	if (u8TestCtl == 0x01u)
	{
		mSERWrite(U8Bit, TestMode, 1u, DEFAULT);
	}
	else
	{
		mSERWrite(U8Bit, TestMode, 0u, DEFAULT);
	}

	return 0U;
}

static U8 IOCDID_Pout_IOCtrlCallback( void)
{
#if 0	//TODO:XXX
	U8 data[cIOCtlChnByte];
	U8 u8loop;

	mSERWrite(U8Bit, SetPoutLockState, 1, Default);
	for(u8loop=0; u8loop<=cIOCtlChnByte; u8loop++)
	{
		data[u8loop] = LAPDiaMemorizedRequest.Buffer[0U + 4U + u8loop];
	}

	mSERWriteStruct(LAPPout, ChnIoCtl, data, Default);
#endif
	return 0U;
}

//==============================================================================
// DESCRIPTION:
//
// PARAMETERS:
//
// RETURN VALUE:
//
// DESIGN INFORMATION:
//==============================================================================
static U8 IOC_CtrlOptRecordPro(U32 u32DIDIndex)
{
    U8    u8NRC;

    switch(IOControlParameter)
    {
        case cReqIOCtrlReturnControlToECU:
            if(cLngIOCtrlReturnControlToECU != LAPDiaMemorizedRequest.Length)
            {
                u8NRC = cLAPDiaIncorrectMessageLengthOrInvalidFormat;
            }
            else
            {
                u8NRC = cLAPDiaServiceIsCorrect;
                IOCUnLockCallbacks_Action[u32DIDIndex]();   // do action before unlock the flag
                IOCUnLockCallbacks_Flag[u32DIDIndex]();
            }
            break;

        case cReqIOCtrlFreezeCurrentState:
            if(4 != LAPDiaMemorizedRequest.Length)		/* 冻结帧数据长度固定 */
            {
                u8NRC = cLAPDiaIncorrectMessageLengthOrInvalidFormat;
            }
            else
            {
                u8NRC = cLAPDiaServiceIsCorrect;
            }
            break;

        case cReqIOCtrlShortTermAdjustment:
            if(IOCBIDidReqLength[u32DIDIndex] != LAPDiaMemorizedRequest.Length)
            {
                u8NRC = cLAPDiaIncorrectMessageLengthOrInvalidFormat;
            }
            else
            {
                u8NRC = IOCBIDidCallbacks[u32DIDIndex]();
            }
            break;

        default:
            u8NRC = cLAPDiaRequestOutOfRange;
            break;
    }

    return(u8NRC);
}

static BOOL IsIOCCnditOk(void)
{
    BOOL bRet = cTrue;
   
    return bRet;
}

//==============================================================================
//=========================== EXPORTED FUNCTIONS ===============================
//==============================================================================
//==============================================================================
// DESCRIPTION : LAPIocInputOutputControlByIdentifier
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
#ifdef cInputOutputControlByIdentifier_Used
void LAPIocInputOutputControlByIdentifier(void)
{
    U32    DIDIndex;
    U16 DataIdentifier;

    LAPDiaResponse.NegativeCode = cLAPDiaIncorrectMessageLengthOrInvalidFormat;

    LAPDiaResponseBegin();

    if(cFalse == LAPDiaIsPhysicalAddress())    //PhyAddress check
    {
        LAPDiaResponse.NegativeCode = cLAPDiaServiceNotSupported;
    }
    else
    {
        if(LAPDiaMemorizedRequest.Length < 4) //basic len NOK
        {
            LAPDiaResponse.NegativeCode = cLAPDiaIncorrectMessageLengthOrInvalidFormat;
        }
        else //basic maybe ok
        {
            DataIdentifier = ((U16)LAPDiaMemorizedRequest.Buffer[1] << 8) + LAPDiaMemorizedRequest.Buffer[2]; //Get the DID
            DIDIndex = LAPDiaFindDIDIndex( IOCBIDids, DataIdentifier, cLAPDiaIOCBIDidsCount); // find index of DID
            if( DIDIndex >= (U32)cLAPDiaIOCBIDidsCount) //DID is unknown
            {
                LAPDiaResponse.NegativeCode = cLAPDiaRequestOutOfRange;
            }
            else //DID is known
            {
                if(0 == (pLAPDiaActiveSession->SessionMask & IOCBIDidBySession[DIDIndex])) //DID is not support in current session
                {
                    LAPDiaResponse.NegativeCode = cLAPDiaRequestOutOfRange;
                }
                else //DID is OK in current session
                {
                    if(IsIOCCnditOk())
                    {
                        //check if length of request is correct (if needed)
                        //length is difficult to check because the same DID req length can be different!
                        //specification required above!!!!
                        //so the length is checked by each DID service function
                        LAPDiaResponse.NegativeCode = IOC_CtrlOptRecordPro(DIDIndex);

                        if(cLAPDiaServiceIsCorrect == LAPDiaResponse.NegativeCode) //!NCR
                        {
                            // copy DID to response
                            LAPDiaResponseWriteByte( LAPDiaMemorizedRequest.Buffer[1]);
                            LAPDiaResponseWriteByte( LAPDiaMemorizedRequest.Buffer[2]);

                            // copy IOCP to response
                            LAPDiaResponseWriteByte( LAPDiaMemorizedRequest.Buffer[3]);
                        }
                        else
                        {
                            //NRC is set
                        }
                    }
                    else
                    {
                        LAPDiaResponse.NegativeCode = cLAPDiaConditionsNotCorrect;
                    }

                }
            }

        }
    }

    if( LAPDiaResponse.NegativeCode != cLAPDiaServiceIsCorrect)
    {
        LAPDiaPrepareNegativeResponse( LAPDiaResponse.NegativeCode);
    }
    else
    {
        // prepare response
        LAPDiaPreparePositiveResponseSimple( LAPDiaResponse.Length);
    }

}
#endif //cInputOutputControlByIdentifier_Used


//==============================================================================
// DESCRIPTION : LAPIocOpenSession
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void LAPIocOpenSession (void)
{
    U8 u8Loop = 0;

    //Example on a session except default session
    // if( (pLAPDiaActiveSession != NULL) &&
    //     (pLAPDiaActiveSession->SessionIdentifier != cLAPDiaIdDefaultSession) )
    // {
    //
    // }
    for(u8Loop=0;u8Loop<cIOControlFlagLength;u8Loop++)
    {
        su8ArrCurIOControlSt[u8Loop] = 0;
    }

}


//==============================================================================
// DESCRIPTION : LAPIocCloseSession
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void LAPIocCloseSession (void)
{
    U8    u8Loop = 0U;

    //1st exit from mot diag.if not,for MOT unlock "return to zero" action will not be done.
//    mSERControl(MotDiag,DeInit);

    //2nd unlock IOC.
    for(u8Loop = 0;u8Loop < cLAPDiaIOCBIDidsCount;u8Loop++)
    {
        IOCUnLockCallbacks_Action[u8Loop]();    // do action before unlock the flag
        IOCUnLockCallbacks_Flag[u8Loop]();
    }



}
//==============================================================================
// DESCRIPTION : LAPIocUnLockCtrl
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : 在任意条件不满足的时候，都要释放控制权
//==============================================================================
void LAPIocUnLockCtrl(void)
{
    U8    u8Loop;

    for(u8Loop = 0;u8Loop < cLAPDiaIOCBIDidsCount;u8Loop++)
    {
        IOCUnLockCallbacks_Action[u8Loop]();    // do action before unlock the flag
        IOCUnLockCallbacks_Flag[u8Loop]();
    }
}



//==============================================================================
// DESCRIPTION:DATCOM_ReadTelltaleIOControlSt
//
// PARAMETERS:
//
// RETURN VALUE:
//
// DESIGN INFORMATION:
//==============================================================================
void    LAPIOC_LockUnlockIOCbyId(BOOL bLock,U8 u8LockId)
{
    if(bLock)
    {
        mLAPIOCSetFlag(su8ArrCurIOControlSt, u8LockId);
    }
    else
    {
        mLAPIOCClearFlag(su8ArrCurIOControlSt, u8LockId);
    }
}


