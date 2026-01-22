
//------------------------------------------------------------------------------
// Body Identification
//------------------------------------------------------------------------------
#define LAP_RWA   "LAP_RWA"

//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//
// #include <system_file_name.h>
// #include "project_file_name.h"
//------------------------------------------------------------------------------


#define cLAP_RWA_SELFINCLUDE //must be set before include LAP_RWA.h
#include "LAP_RWA.h"



//------------------------------------------------------------------------------
// Local types
//
// typedef Expression    tTypeName;
//------------------------------------------------------------------------------
#if (cSizeOfMemoryAddressInBytes == 3) || (cSizeOfMemoryAddressInBytes == 4)
    typedef U32 tMemoryAddress;
#else
    #error cSizeOfMemoryAddressInBytes should be 3 or 4 bytes
#endif


#if (cSizeOfMemorySizeInBytes==1)
    typedef U8     tMemorySize;
#else
    #if (cSizeOfMemorySizeInBytes==2)
        typedef U16     tMemorySize;
    #else
        #error cSizeOfMemorySizeInBytes should be 1 or 2 bytes
    #endif
#endif


//------------------------------------------------------------------------------
// Local constants
//
// #define cConstantName   ((tType) ConstantValue)
//------------------------------------------------------------------------------
#define cLngMinReqReadMemoryByAddress   ((U8)(1 + 1))
#define cLngMinReqWriteMemoryByAddress   ((U8)(1 + 1)) // We write at least 1 byte => the request length is 9 bytes at least
#define cLngMinRepWriteMemoryByAddress   ((U8)(1 + 1)) // We write at least 1 byte => the request length is 8 bytes at least
#define cResponseRamReadDataOffset            ((U8)0X05U)

#define cLngRdMemData                      ((U8)0x0AU)
#define cRespDataStartIndex                ((U8)0x01U)

#define cReqAddrAndLngFrmtIDIndex           ((U8)0x01U)
#define cReqMemAddrHHIndex                     ((U8)0x02U)
#define cReqMemAddrHLIndex                      ((U8)0x03U)
#define cReqMemAddrLHIndex                      ((U8)0x04U)
#define cReqMemAddrLLIndex                       ((U8)0x05U)

#define cReqMemSizeHHIndex                       ((U8)0x06U)
#define cReqMemSizeHLIndex                        ((U8)0x07U)
#define cReqMemSizeLHIndex                        ((U8)0x08U)
#define cReqMemSizeLLIndex                         ((U8)0x09U)

#define cReqWrMemDataStartIndex                ((U8)0x0AU)

#define cRWMemAddrAndLngFrmt                 ((U8)0X44U)

//------------------------------------------------------------------------------
// Local macros
//
// #define mMacroName   (MacroDefinition)
//------------------------------------------------------------------------------
#define mGetSizeMemorySize() ((U8)(LAPDiaMemorizedRequest.Buffer[1] >> 4))
#define mGetSizeMemoryAddress() ((U8)(LAPDiaMemorizedRequest.Buffer[1] & (U8)0x0FU))

//------------------------------------------------------------------------------
// Local types
//
// typedef Expression    tTypeName;
//------------------------------------------------------------------------------

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
#ifdef LOCK_FUNCTION_ENABLE
    static BOOL bWritingIsLocked;
#endif


//------------------------------------------------------------------------------
// Constant local data
//
// static const tType  VariableName;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Exported data
//
// tType   u8LAYCmpVariableName; (LAY: 3 characters to identify the layer)
// tType*  pu8LAYCmpVariableName;(Cmp: 3 characters to identify the component)
//------------------------------------------------------------------------------
#ifdef LOCK_FUNCTION_ENABLE
    // This is the code to unlock the memory writing
    const tLockCode cLockCode = ((U32)0x1234UL);
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


//==============================================================================
//=========================== LOCAL FUNCTIONS ==================================
//==============================================================================
//==============================================================================
// DESCRIPTION :LAPRwa_EepRw_ValidCheck
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
static  BOOL    LAPRwa_EepRw_ValidCheck(U32 u32Addr,U32 u32Len)
{
    BOOL    bValid = cFalse;

    if((u32Addr >= cDATDeaSizeEeprom)|| (u32Len > cDATDeaMaxByte)
        || ((u32Addr + u32Len) > cDATDeaSizeEeprom))                             /*check eep chip    */
    { /* outof the max address of eep chip */
        LAPDiaResponse.NegativeCode = cLAPDiaRequestOutOfRange;
    }
    else if((0x01 == (u32Addr & 0x01)) || (0x01 == (u32Len & 0x01)))             /*check addr&len    */
    {
        LAPDiaResponse.NegativeCode = cLAPDiaRequestOutOfRange;
    }
    else if((u32Len > cDATDeaMaxByte)||
        (u32Len > (cLAPDiaLngBufferResponse-cResponseRamReadDataOffset)))        /*check buffer      */
    { /* the max read&write len is 16 */
        LAPDiaResponse.NegativeCode = cLAPDiaRequestOutOfRange;
    }
    else if(cTrue != mSERRead(U8Bit,DATDeaActionIsFinished,Default))            /*check eep module  */
    { /* the previous action is not finished*/
        LAPDiaResponse.NegativeCode = cLAPDiaConditionsNotCorrect;
    }
    else                                                                        /*pass the check    */
    { /* pass the check */
        bValid = cTrue;
    }

    return(bValid);
}

#define FLASH_READ
static  BOOL    LAPRwa_ChipAddrRw_ValidCheck(U32 u32Addr,U32 u32Len)
{

    BOOL    bValid = cFalse;

    if(((u32Addr < cDATRamStartAddr) || ((u32Addr + u32Len) > cDATRamEndAddr))
#ifdef FLASH_READ
    		&& ((u32Addr < cDATFlashStartAddr) || ((u32Addr + u32Len) > cDATFlashEndAddr))
#endif
		)
    { /* the address should larger than EEP size and smaller than RAM size*/
        LAPDiaResponse.NegativeCode = cLAPDiaRequestOutOfRange;
    }
    else if((u32Len > (cLAPDiaLngBufferResponse-cResponseRamReadDataOffset)))        /*check buffer      */
    { /* larger than buffer size */
        LAPDiaResponse.NegativeCode = cLAPDiaRequestOutOfRange;
    }
    else                                                                        /*pass the check    */
    { /* pass the check */
        bValid = cTrue;
    }

    return(bValid);

}

//==============================================================================
//=========================== EXPORTED FUNCTIONS ===============================
//==============================================================================

//==============================================================================
// DESCRIPTION : LAPRwaReadMemoryByAddress
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
    //#ifdef cReadMemoryByAddress_Used
void LAPRwaReadMemoryByAddress(void)
{
    U32 u32Addr = 0U;
    U32 u32Len = 0U;
    U8  u8Cnt = 0U;
    U8  u8RespSize = 2U;
    U8  u8Frmt = 0U;
    BOOL bIsEEPReadOverAndOK = cFalse;
    U8   u8Loop = 0U;


    // By default, we consider the request invalid (for optimization)
    LAPDiaResponse.NegativeCode = cLAPDiaIncorrectMessageLengthOrInvalidFormat;

    u8Frmt = LAPDiaMemorizedRequest.Buffer[cReqAddrAndLngFrmtIDIndex];

    if(0)//if(mSERRead(U1Bit, AD_IGOn, Default) == cFalse)
    {
    	LAPDiaResponse.NegativeCode = cLAPDiaConditionsNotCorrect;
    }
    else if ((cLngRdMemData != LAPDiaMemorizedRequest.Length) || cRWMemAddrAndLngFrmt != u8Frmt )
	{
    	//negative response code is already set
	}
    else
	{

		u32Addr =  ((U32)(LAPDiaMemorizedRequest.Buffer[cReqMemAddrHHIndex]) << 24U)
					   + ((U32)(LAPDiaMemorizedRequest.Buffer[cReqMemAddrHLIndex]) << 16U)
					   + ((U32)(LAPDiaMemorizedRequest.Buffer[cReqMemAddrLHIndex]) <<8U)
					   + ((U32)(LAPDiaMemorizedRequest.Buffer[cReqMemAddrLLIndex]) ) ;

		u32Len =   ((U32)(LAPDiaMemorizedRequest.Buffer[cReqMemSizeHHIndex]) << 24U)
					   + ((U32)(LAPDiaMemorizedRequest.Buffer[cReqMemSizeHLIndex]) << 16U)
					   + ((U32)(LAPDiaMemorizedRequest.Buffer[cReqMemSizeLHIndex]) <<8U)
					   + ((U32)(LAPDiaMemorizedRequest.Buffer[cReqMemSizeLLIndex]) ) ;


		if(LAPRwa_EepRw_ValidCheck(u32Addr,u32Len))
		{
			u32Addr -= cDATEEpBaseAddr;				/* 减去偏移地址 */
			mSERWrite( U16Bit, DATDeaAddressInByte, (U16)u32Addr,  Default);
			mSERWrite( U8Bit, DATDeaSizeBufferInByte,u32Len,Default);
			mSERControl(DATDea, StartReadEepromByAddress);

			extern void DATEepTask(void);

			while(cTrue)
			{
				//这里直接调用DATEepTask任务，因为其优先级比较低，如果通过SceduleTask的方式，
				//则是其很可能是没有机会得到运行的，所以这里直接调用。
				{
					DATEepTask();
					u8Cnt++;

					//如果EEP读操作完成，就退出循环
					if((cTrue == mSERRead(U8Bit,DATDeaActionIsFinished,Default)) && (cTrue == mSERRead(U8Bit,DATDeaReadIsOk,Default)))
					{
						bIsEEPReadOverAndOK = cTrue;
						break;
					}

					//>15表示超时，退出循环,同时设置错误标志
					if(u8Cnt > cU8MaxEEPTaskCalling)
					{
						LAPDiaResponse.NegativeCode = cLAPDiaConditionsNotCorrect;
						break;
					}

				}
			}

			//如果读操作完成，则返回正确响应，否则返回否定响应
			if(bIsEEPReadOverAndOK)
			{
				for (u8Loop=0; u8Loop < u32Len; u8Loop++)
				{
					LAPDiaResponse.Buffer[cRespDataStartIndex + u8Loop] = mSERReadBuffer(DATDeaBufferU8Bit, u8Loop, Default);
				}
				LAPDiaResponse.NegativeCode = cLAPDiaServiceIsCorrect;

				//这里加1表示服务ID=0X63
				u8RespSize = 1U + u32Len;
			}
			else
			{
				LAPDiaResponse.NegativeCode = cLAPDiaResponseTooLong;
			}

		}
		else
		{
			//这里添加代码实现RAM的读取，因为RAM大小为48KB，且前面的是栈区间。这里为了简单起见，只要地址是大于2048的，都可以读取。
			if(LAPRwa_ChipAddrRw_ValidCheck(u32Addr,u32Len))
			{
				for (u8Loop=0; u8Loop < u32Len; u8Loop++)
				{
					LAPDiaResponse.Buffer[cRespDataStartIndex + u8Loop] = *(((U8*)(u32Addr  + u8Loop)));
				}
				LAPDiaResponse.NegativeCode = cLAPDiaServiceIsCorrect;
				u8RespSize = 1U + u32Len;
			}
			else
			{
				//否定响应
				LAPDiaResponse.NegativeCode = cLAPDiaIncorrectMessageLengthOrInvalidFormat;
			}
		}
	}


    if (LAPDiaResponse.NegativeCode != cLAPDiaServiceIsCorrect)
    {
        LAPDiaPrepareNegativeResponse(LAPDiaResponse.NegativeCode);
    }
    else
    {
        LAPDiaPreparePositiveResponseSimple(u8RespSize);
    }
}



//==============================================================================
// DESCRIPTION : LAPRwaWriteMemoryByAddress
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
//#ifdef cWriteMemoryByAddress_Used
void LAPRwaWriteMemoryByAddress(void)
{
    U8 u8SizeMemAddr = 0;
    U8 u8SizeMemSize = 0;
    U8 *pu8Databuf = (U8*)0U;
    U8 u32Len = 0U;
    U8 u8Loop = 0U;
    U8 u8Frmt = 0U;
    U32 u32Addr = 0U;

    // By default, we consider the request invalid (for optimization)
    LAPDiaResponse.NegativeCode = cLAPDiaIncorrectMessageLengthOrInvalidFormat;


    u8Frmt = LAPDiaMemorizedRequest.Buffer[cReqAddrAndLngFrmtIDIndex];

    //now only support write EEP address,so the address should be smaller than 2048Byte
    if ((LAPDiaMemorizedRequest.Length < cReqWrMemDataStartIndex) || (cRWMemAddrAndLngFrmt != u8Frmt))
    {
        // Do nothing
        // error code is already loaded
    }
    else
    {
        u8SizeMemAddr = (u8Frmt & 0XF0)>>4U;

        u8SizeMemSize = (u8Frmt & 0X0F);

        u32Addr = ((U32)(LAPDiaMemorizedRequest.Buffer[cReqMemAddrHHIndex]) << 24U)
                       + ((U32)(LAPDiaMemorizedRequest.Buffer[cReqMemAddrHLIndex])    << 16U)
                       + ((U32)(LAPDiaMemorizedRequest.Buffer[cReqMemAddrLHIndex]) <<8U)
                       + ((U32)(LAPDiaMemorizedRequest.Buffer[cReqMemAddrLLIndex]) ) ;

        u32Len = ((U32)(LAPDiaMemorizedRequest.Buffer[cReqMemSizeHHIndex]) << 24U)
                       + ((U32)(LAPDiaMemorizedRequest.Buffer[cReqMemSizeHLIndex])    << 16U)
                       + ((U32)(LAPDiaMemorizedRequest.Buffer[cReqMemSizeLHIndex]) <<8U)
                       + ((U32)(LAPDiaMemorizedRequest.Buffer[cReqMemSizeLLIndex]) ) ;



        if(LAPRwa_EepRw_ValidCheck(u32Addr,u32Len))
        {
            pu8Databuf = &LAPDiaMemorizedRequest.Buffer[cReqWrMemDataStartIndex];
            for(u8Loop=0; u8Loop < u32Len; u8Loop++)                                    /* Set data    */
            {
                mSERWriteBuffer(DATDeaBufferU8Bit,u8Loop,pu8Databuf[u8Loop], Default);
            }
            mSERWrite(  U16Bit, DATDeaAddressInByte, (U16)u32Addr, Default);     /* Set address  */
            mSERWrite(  U8Bit, DATDeaSizeBufferInByte, u32Len,Default);              /* Set size     */
            mSERControl(DATDea, StartWriteEepromByAddress);                         /* Start action */

            LAPDiaResponse.NegativeCode = cLAPDiaServiceIsCorrect;
        }
        else
        {
            //negative response code already set in LAPRwa_EepRw_ValidCheck.
        }

    }


    if (LAPDiaResponse.NegativeCode == cLAPDiaServiceIsCorrect)
    {
        mLIBmemcpy(&(LAPDiaResponse.Buffer[cReqAddrAndLngFrmtIDIndex]),
                                           &(LAPDiaMemorizedRequest.Buffer[cReqAddrAndLngFrmtIDIndex]),
                                           u8SizeMemAddr + u8SizeMemSize);

        LAPDiaPreparePositiveResponse((U8)(cLngMinRepWriteMemoryByAddress + (u8SizeMemAddr + u8SizeMemSize)));
    }
    else
    {
        LAPDiaPrepareNegativeResponse(LAPDiaResponse.NegativeCode);
    }
}



//==============================================================================
// DESCRIPTION : LAPRwaOpenSession
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void LAPRwaOpenSession (void)
{
    //Example on a session except default session
    //if (LAPDiaActiveSession.SessionIdentifier != cLAPDiaIdDefaultSession)
    //{
    //}
}


//==============================================================================
// DESCRIPTION : LAPRwaCloseSession
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void LAPRwaCloseSession (void)
{
    #ifdef LOCK_FUNCTION_ENABLE
        bWritingIsLocked = cTrue;
    #endif

    //Example on a session except default session
    //if (LAPDiaActiveSession.SessionIdentifier != cLAPDiaIdDefaultSession)
    //{
    //}
}
