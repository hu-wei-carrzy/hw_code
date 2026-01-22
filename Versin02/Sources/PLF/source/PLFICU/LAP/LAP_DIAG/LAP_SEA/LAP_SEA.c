#ifndef _QAC_

#endif

//------------------------------------------------------------------------------
// Body Identification
//------------------------------------------------------------------------------
#define LAP_SEA   "LAP_SEA"


//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//
// #include <system_file_name.h>
// #include "project_file_name.h"
//------------------------------------------------------------------------------
#define cLAP_SEA_SELFINCLUDE
#include "LAP_SEA.h"




//------------------------------------------------------------------------------
// Local constants
//
// #define cConstantName   ((tType) ConstantValue)
//------------------------------------------------------------------------------

/////////////////////////////////////////////////////////////
// Constants for LAPSeaSecurityAccess1
/////////////////////////////////////////////////////////////

//------------------------------------------------------------------------------
// Length of LAPSeaSecurityAccess1 request / response
//Extended session
//客户端发送请求，长度仅为2字节
#define cLng_Extd_Seed_Client_to_Srv					((U8)0x02)
//数据长度，因为当前seed为8字节，因此长度为0x0A
#define cLng_Extd_Seed_Srv_to_Client					((U8)0x0A)
//数据长度，因为当前Key为8字节，因此长度为0x0A
#define cLng_Extd_Key_Client_to_Srv						((U8)0x0A)
//服务器发送key响应，长度仅为2字节
#define cLng_Extd_Key_Srv_to_Client						((U8)0x02)

//PRGS  session
//客户端发送请求，长度仅为2字节
#define cLng_PRGS_Seed_Client_to_Srv 					((U8)0x02)
//数据长度，因为当前seed为8字节，因此长度为0x0A
#define cLng_PRGS_Seed_Srv_to_Client					((U8)0x0A)
//数据长度，因为当前Key为8字节，因此长度为0x0A
#define cLng_PRGS_Key_Client_to_Srv 					((U8)0x0A)
//服务器发送key响应，长度仅为2字节
#define cLng_PRGS_Key_Srv_to_Client						((U8)0x02)

//SSS session
#define cLng_SSS_Seed_Client_to_Srv						((U8)0x02)
#define cLng_SSS_Seed_Srv_to_Client						((U8)0x06)

#define cLng_SSS_Key_Client_to_Srv						((U8)0x06)
#define cLng_SSS_Key_Srv_to_Client						((U8)0x02)



/* securityAccessType LEV_*/
/* Default session : 0x01     Default session                  */
/* PRGS session    : 0x02     Programming session              */
/* EXTDS session   : 0x03     Extended diagnostic session      */
/* SSS session     : 0x60     System supplier specific         */

#define cReqSeed_Level_EXTDS                            ((U8)0x01) /*Used for session$03:Extended diagnostic session */
#define cSendKey_Level_EXTDS                            ((U8)0x02)

//N351 No defination for programming session， but in BCM313, this session had been defined, add by banfy
#define cReqSeed_Level_PRGS                             ((U8)0x03) // Programming session
#define cSendKey_Level_PRGS                             ((U8)0x04)

//BCM313 No defination for programming session
#define cReqSeed_Level_JCI                              ((U8)0x05) /*Used for session$60:System supplier specific */
#define cSendKey_Level_JCI                              ((U8)0x06)


//positive response is sent by the bootloader
//SA2 is implemented by the bootloader only

#define cSeaStep_Client_ReqSeed							((U8)0x01) /* odo  value*/
#define cSeaStep_Client_ResKey							((U8)0x00) /* even value*/


#define	cSeaStep_Server_Idle							((U8)0x00)
#define	cSeaStep_Server_SentSeed						((U8)0x01)

// Mask for SeedToKey Algorithm 1 and 2
#define cKey1Mask 										(U32)0x8E9ABA8E			// For EXTDS
#define cKey2Mask 										(U32)0x8EACBA9F			// For PRGS

#define cKey2SeedMask 									(U32)0xDEADBEEF			// For random key generator

#define	cLock_Lock_All									((U8)0x00) /*maybe always using cLock_Lock_All_But_Default*/
#define	cLock_Lock_All_But_Default						((U8)0x01)

#define	cLock_Sts_Locked								((U8)0x00)
#define	cLock_Sts_UnLocked								((U8)0x01)

#define	cAndMsk_Unlock_Default							((U8)0x01)
#define	cAndMsk_Unlock_EXTDS							((U8)0x02)
#define	cAndMsk_Unlock_PRGS								((U8)0x04)
#define	cAndMsk_Unlock_JCI								((U8)0x08)

#define	cAndMsk_Getlock_Default							((U8)0x01)
#define	cAndMsk_Getlock_EXTDS							((U8)0x02)
#define	cAndMsk_Getlock_PRGS							((U8)0x04)
#define	cAndMsk_Getlock_JCI								((U8)0x08)



#define	cFailAccessTryTimesMax							((U8)0x03)

//------------------------------------------------------------------------------
// Local macros
//
// #define mMacroName   (MacroDefinition)
//------------------------------------------------------------------------------
#define mGetActiveSessionType()  ((U8)(pLAPDiaActiveSession->SessionIdentifier))

#define mGetSecurityAccessType() ((U8)(LAPDiaMemorizedRequest.Buffer[(U8)1] & (U8)0x7FU))
#define mGetSecurityAccessStep() ((U8)(LAPDiaMemorizedRequest.Buffer[(U8)1] & (U8)0x01U))


/*customer algorithm*/
#define mCalcSecurityAccessKey_1(v1,v2) (U16)(( ((U32)(v1)) * 0x55 + 1234 )				\
                                          	 ^( ((U32)(v2)) * 0xAA + 1234 )				\
                                          	 ^(0x4321)									\
                                          	 )
/*assemblyline algorithm*/
#define mCalcSecurityAccessKey_2(v1,v2) (U32)(( ((U32)(v1)) * 36125 + 12344 )			\
                                         	  ^( ((U32)(v2)) * 32125 + 12344 )			\
                                         	  ^(0x87654321)								\
                                         	  )
/*10s延时时间*/
#define  cU16FailAccessDelay		((U16)10000U)/*10s延时*/
#define  cSeaPowerOnTime            ((U32)800U)  /*10s = 800*1.25ms*/
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
static	U8	u8LAPSea_Seed_H_HH;
static	U8	u8LAPSea_Seed_H_HL;
static	U8	u8LAPSea_Seed_H_LH;
static	U8	u8LAPSea_Seed_H_LL;

static  U8  u8LAPSea_Seed_L_HH;//add by banfy,当前种子及密钥长度为8个字节
static  U8  u8LAPSea_Seed_L_HL;
static	U8	u8LAPSea_Seed_L_LH;
static	U8	u8LAPSea_Seed_L_LL;



static	U8	u8LAPSea_SeqStep;
static	U8	u8LAPSea_FailAccessTime;


static	U8	u8LAPSea_Lock; /* xxxx,xxxx*//*1:unlocked.0:Locked*/
/*10s延时*/
//static	tTOSTimer	stFailAccessTimer;
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
static  U32     SeedToKeyH(const U32 u32Mask);
static	void	LAPSeaGenRandomSeed(void);
static	BOOL	LAPSeaSecurityAccess_ValidCheck(void);
static	void	LAPSeaSubFunNotSupportedResponse(void);

//==============================================================================
//=========================== LOCAL FUNCTIONS ==================================
//==============================================================================
//==============================================================================
// DESCRIPTION : Seed to Key Algorithm
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
static U32 SeedToKeyH(const U32 u32Mask)
{
	U32 u32KeyH;

	u32KeyH = ((U32)u8LAPSea_Seed_H_HH << 24) + ((U32)u8LAPSea_Seed_H_HL << 16) +((U32)u8LAPSea_Seed_H_LH << 8) + (U32)u8LAPSea_Seed_H_LL;

	u32KeyH = ~(u32KeyH) + 0x5A5AAA55U;
#if 0
	//original expression is for (u16Loop = 0; u16Loop < 35; u16Loop++), change by banfy
	for (u16Loop = 0; u16Loop < 32; u16Loop++)
	{
		if (u32KeyH & 0x80000000)
		{
			u32KeyH = u32KeyH << 1;
			//按位异或
			u32KeyH = u32KeyH ^ u32Mask;
		}
		else
		{
			u32KeyH = u32KeyH << 1;
		}
	}
#endif
	return u32KeyH;
}
static U32 SeedToKeyL(const U32 u32Mask)
{
	U32 u32KeyL;

	u32KeyL = ((U32)u8LAPSea_Seed_L_HH << 24) + ((U32)u8LAPSea_Seed_L_HL << 16) +((U32)u8LAPSea_Seed_L_LH << 8) + (U32)u8LAPSea_Seed_L_LL;
	u32KeyL = ~(u32KeyL) + 0x5A5AAA55U;
	#if 0
	for (u16Loop = 0; u16Loop < 32; u16Loop++)
	{
		if (u32KeyL & 0x80000000)
		{
			u32KeyL = u32KeyL << 1;
			u32KeyL = u32KeyL ^ u32Mask;
		}
		else
		{
			u32KeyL = u32KeyL << 1;
		}
	}
#endif
	return u32KeyL;
}

//==============================================================================
// DESCRIPTION :
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
static	void	LAPSeaSubFunNotSupportedResponse(void)
{
	if(LAPDiaMemorizedRequest.Length >= 2 )
	{
		if( (cReqSeed_Level_EXTDS  != mGetSecurityAccessType())&&
			(cSendKey_Level_EXTDS  != mGetSecurityAccessType())&&
			(cReqSeed_Level_PRGS   != mGetSecurityAccessType())&&
			(cSendKey_Level_PRGS   != mGetSecurityAccessType()))
		{
			LAPDiaPrepareNegativeResponse(cLAPDiaSubFunctionNotSupported);
		}
		else
		{
			LAPDiaPrepareNegativeResponse(cLAPDiaSubFunctionNotSupportedInActiveSession);
		}
	}
	else
	{
		LAPDiaPrepareNegativeResponse(cLAPDiaIncorrectMessageLengthOrInvalidFormat);
	}
}

//==============================================================================
// DESCRIPTION :
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : generate pseudo random seed by linear congruential method
//==============================================================================
static	void	LAPSeaGenRandomSeed(void)
{
#if 1
    u8LAPSea_Seed_H_HH = (U8)((((U16)u8LAPSea_Seed_H_HH) << 1) & 0x00FF); /* ( 2 * x ) mod 256 */
    u8LAPSea_Seed_H_HL = (U8)((((U16)u8LAPSea_Seed_H_HL) << 1) & 0x00FF); /* ( 2 * x ) mod 256 */
    u8LAPSea_Seed_H_LH = (U8)((((U16)u8LAPSea_Seed_H_LH) << 1) & 0x00FF); /* ( 2 * x ) mod 256 */
    u8LAPSea_Seed_H_LL = (U8)((((U16)u8LAPSea_Seed_H_LL) << 1) & 0x00FF); /* ( 2 * x ) mod 256 */
#else
    // yeah, SeedToKey used to generate the random seed, perfect
    // test on MinGW, 100000 seeds generated are all different.
    //在这里生成随机种子，当种子为FFFFFFFF或为00000000时，重新生成，直到不全为当前。
	//U32 u32Key = SeedToKeyH(cKey2SeedMask);
	BOOL bIsGenSeedValid = cFalse;
	U32 u32SeedH = 0U;
	U32 u32SeedL = 0U;

	U32  u32RandomNum = 0U;

	U8   u8ThrByte = 0U;
	U8   u8SecByte = 0U;
	U8   u8FirByte = 0U;
	do{
		u32RandomNum = LIBGetCurTime();
		u8FirByte = (u32RandomNum & 0xFF);
		u8SecByte = ((u32RandomNum & 0xFF00) >> 8U);
		u8ThrByte = ((u32RandomNum & 0xFF0000) >> 16U);

		u8LAPSea_Seed_H_HH = u8FirByte;
		u8LAPSea_Seed_H_LH = ((u8SecByte & 0xF0) >> 4U) + ((u8SecByte & 0x0F) << 4U);
		u8LAPSea_Seed_H_LL = (u8FirByte + 0x5AU) * 0xA5U;
		u8LAPSea_Seed_H_HL = ((~(u8SecByte + 1U)) * 0x0B);

		u8LAPSea_Seed_L_HH = (u8FirByte * 0x0D) ;
		u8LAPSea_Seed_L_LH = (u8SecByte * 0x07) + 0x33U;

		u8LAPSea_Seed_L_LL = (u8SecByte * 0x05 + 0xA6U) ;
		u8LAPSea_Seed_L_HL = ((~u8FirByte) * 0x09 + 0x6AU) ;

		u32SeedH = (U32)u8LAPSea_Seed_H_HH << 24U + (U32)u8LAPSea_Seed_H_HL << 16U + (U32)u8LAPSea_Seed_H_LH << 8U + (U32)u8LAPSea_Seed_H_LL;
		u32SeedL = (U32)u8LAPSea_Seed_L_HH << 24U + (U32)u8LAPSea_Seed_L_HL << 16U + (U32)u8LAPSea_Seed_L_LH << 8U + (U32)u8LAPSea_Seed_L_LL;
		if((u32SeedH != 0xFFFFU || u32SeedL != 0xFFFF) &&
		   (u32SeedH != 0U || u32SeedL != 0U))
		{
			bIsGenSeedValid = cTrue;
		}
		else
		{
			//
		}

	}while(bIsGenSeedValid == cTrue);
/*
	u8LAPSea_Seed_H_LH = (U8)((u32Key >> 24) & 0xFF);
	u8LAPSea_Seed_H_LL = (U8)((u32Key >> 16) & 0xFF);
	u8LAPSea_Seed_H_HH = (U8)((u32Key >>  8) & 0xFF);
	u8LAPSea_Seed_H_HL = (U8)((u32Key >>  0) & 0xFF);

	u8LAPSea_Seed_L_HH = (U8)((u32Key >> 24) & 0xFF);
	u8LAPSea_Seed_L_HL = (U8)((u32Key >> 24) & 0xFF);
	u8LAPSea_Seed_L_LH = (U8)((u32Key >> 24) & 0xFF);
	u8LAPSea_Seed_L_LL = (U8)((u32Key >> 24) & 0xFF);
*/
#endif
#if 0
	if((0 == u8LAPSea_Seed_H_HH) && (0 == u8LAPSea_Seed_H_HL))
	{
        u8LAPSea_Seed_H_HH = 0xA0;
        u8LAPSea_Seed_H_HL = 0x05;
	}
	else
	{
        /* no statement */
	}
	if((0 == u8LAPSea_Seed_H_LH) && (0 == u8LAPSea_Seed_H_LL))
	{
        u8LAPSea_Seed_H_LH = 0xA0;
        u8LAPSea_Seed_H_LL = 0x05;
	}	
	else
	{
        /* no statement */
	}
#endif
}
//==============================================================================
// DESCRIPTION :
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
static	BOOL	LAPSeaSecurityAccess_ValidCheck(void)
{
	BOOL	bValid;

	bValid = cTrue;
	/*==============PhyAddress check==========*/
	if(cFalse == LAPDiaIsPhysicalAddress())
	{
		LAPDiaPrepareNegativeResponse(cLAPDiaServiceNotSupported);
		bValid = cFalse;
	}

	/*==============Battery check==============*//*将电压检测提前,之前在length check之后， banfy*/
	if((bValid)
		&&(cFalse == mSERRead(U1Bit,IsDiagBatNormal,Default)))
	{
		LAPDiaPrepareNegativeResponse(cLAPDiaConditionsNotCorrect);
		bValid = cFalse;
	}

	/*==============sub fun check==============*/

	if((bValid)
		&&(cLAPDiaIdPRGSSession  == mGetActiveSessionType())
		&&(cReqSeed_Level_PRGS   != mGetSecurityAccessType())
		&&(cSendKey_Level_PRGS   != mGetSecurityAccessType()))
	{
		LAPSeaSubFunNotSupportedResponse();
		bValid = cFalse;
	}

	if((bValid)
		&&(cLAPDiaIdEXTDSSession == mGetActiveSessionType())
		&&(cReqSeed_Level_EXTDS  != mGetSecurityAccessType())
		&&(cSendKey_Level_EXTDS  != mGetSecurityAccessType()))
	{
		LAPSeaSubFunNotSupportedResponse();
		bValid = cFalse;
	}
	/*==============length check===============*/
	//这里要check服务器接收到的数据长度，确认是否正常。
	if((bValid)
		&&(cLAPDiaIdEXTDSSession == mGetActiveSessionType())
		&&(cSeaStep_Client_ReqSeed == mGetSecurityAccessStep())
		&&(cLng_Extd_Seed_Client_to_Srv != LAPDiaMemorizedRequest.Length))
	{
		LAPDiaPrepareNegativeResponse(cLAPDiaIncorrectMessageLengthOrInvalidFormat);
		bValid = cFalse;
	}
	if((bValid)
		&&(cLAPDiaIdEXTDSSession == mGetActiveSessionType())
		&&(cSeaStep_Client_ResKey == mGetSecurityAccessStep())
		&&(cLng_Extd_Key_Client_to_Srv != LAPDiaMemorizedRequest.Length))
	{
		LAPDiaPrepareNegativeResponse(cLAPDiaIncorrectMessageLengthOrInvalidFormat);
		bValid = cFalse;
	}

	if((bValid)
		&&(cLAPDiaIdPRGSSession == mGetActiveSessionType())
		&&(cSeaStep_Client_ReqSeed == mGetSecurityAccessStep())
		&&(cLng_PRGS_Seed_Client_to_Srv != LAPDiaMemorizedRequest.Length))
	{
		LAPDiaPrepareNegativeResponse(cLAPDiaIncorrectMessageLengthOrInvalidFormat);
		bValid = cFalse;
	}
	if((bValid)
		&&(cLAPDiaIdPRGSSession == mGetActiveSessionType())
		&&(cSeaStep_Client_ResKey == mGetSecurityAccessStep())
		&&(cLng_PRGS_Key_Client_to_Srv != LAPDiaMemorizedRequest.Length))
	{
		LAPDiaPrepareNegativeResponse(cLAPDiaIncorrectMessageLengthOrInvalidFormat);
		bValid = cFalse;
	}

	/*==============timer check  ==============*/
	if( (bValid)
		&&(cSeaStep_Server_Idle == u8LAPSea_SeqStep)
		&&(cTOSSeqInactiveGraph != TOSSeqGraphState(cTOSSeqLAPDiaSeaDTMgr))
		&&( (cLAPDiaIdPRGSSession == mGetActiveSessionType()) ||
			(cLAPDiaIdEXTDSSession == mGetActiveSessionType()) ) )
	{
		if(cSeaStep_Client_ResKey == mGetSecurityAccessStep())
		{
			LAPDiaPrepareNegativeResponse(cLAPDiaExceedNumberOfAttempts);
		}
		else
		{
			LAPDiaPrepareNegativeResponse(cLAPDiaRequiredTimeDelayNotExpired);
		}
		bValid = cFalse;
	}
    /*==============sequence check==============*/
    if((bValid)
        &&(cSeaStep_Server_Idle == u8LAPSea_SeqStep)
        &&(cSeaStep_Client_ResKey == mGetSecurityAccessStep()))
    {
        if(cTrue == LAPSeaIsServiceUnLocked())
        {// unlocked
            LAPDiaPrepareNegativeResponse(cLAPDiaRequestSequenceError);
        }
        else
        {// locked
            LAPDiaPrepareNegativeResponse(cLAPDiaConditionsNotCorrect);
        }
        bValid = cFalse;
    }

	return(bValid);
	
}
//==============================================================================
// DESCRIPTION :
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
static	void	LAPSeaUnlock_BySession(void)
{
	if(cLAPDiaIdPRGSSession  == mGetActiveSessionType())
	{
		u8LAPSea_Lock |= cAndMsk_Unlock_PRGS;
	}
	else if(cLAPDiaIdEXTDSSession == mGetActiveSessionType())
	{
		u8LAPSea_Lock |= cAndMsk_Unlock_EXTDS;
	}
	else
	{
		/*no statement*/
	}

	u8LAPSea_FailAccessTime = 0;
}

//==============================================================================
//=========================== EXPORTED FUNCTIONS ===============================
//==============================================================================

//==============================================================================
// DESCRIPTION : LAPSeaInit
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void LAPSeaInit(void)
{
	u8LAPSea_SeqStep = cSeaStep_Server_Idle;

	if(TOSReadSignal(cTOSSignalLAPDiaEcuPowerOnReset))
	{
		//u8LAPSea_FailAccessTime = mSERRead(U8Bit,NVM_SecurityAccessTimes,Default);
		if( u8LAPSea_FailAccessTime != 0)
		{
			TOSSeqActivateGraph(cTOSSeqLAPDiaSeaDTMgr);
		}
	}
//  by test on MinGW, don't do it to make sure more random ability
//	u8LAPSea_Seed_H_LH = (u8LAPSea_Seed_H_LH >> 2) | 0xA0;
//	u8LAPSea_Seed_H_LL = (u8LAPSea_Seed_H_LL << 3) | 0x05;
//	u8LAPSea_Seed_H_HH = (u8LAPSea_Seed_H_HH >> 2) | 0xB0;
//	u8LAPSea_Seed_H_HL = (u8LAPSea_Seed_H_HL << 3) | 0xFC;
	u8LAPSea_FailAccessTime = 0U;
	u8LAPSea_Lock = cLock_Lock_All_But_Default;
}
//==============================================================================
// DESCRIPTION : LAPSeaStart
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void LAPSeaStart(void)
{
	u8LAPSea_SeqStep = cSeaStep_Server_Idle;
	//u8LAPSea_FailAccessTime = mSERRead(U8Bit,NVM_SecurityAccessTimes,Default);
	u8LAPSea_Lock = cLock_Lock_All_But_Default;
}
//==============================================================================
// DESCRIPTION : LAPSeaStop
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void LAPSeaStop(void)
{
	TOSSeqDeactivateGraph(cTOSSeqLAPDiaSeaDTMgr);
	u8LAPSea_Lock = cLock_Lock_All_But_Default;
}
//==============================================================================
// DESCRIPTION : LAPSeaSecurityAccess
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : Read Status Of SEA Service
//==============================================================================
#ifdef cSecurityAccess_Used
void LAPSeaSecurityAccess(void)
{
	BOOL  bValidCheck;
	U32   u32Key_H_Srv;
	U32   u32Key_L_Srv;

	U8    u8Key_Srv_H_HH;
	U8    u8Key_Srv_H_HL;
	U8    u8Key_Srv_H_LH;
	U8    u8Key_Srv_H_LL;
	
	U8    u8Key_Srv_L_HH;
	U8    u8Key_Srv_L_HL;
	U8    u8Key_Srv_L_LH;
	U8    u8Key_Srv_L_LL;
	
	bValidCheck = LAPSeaSecurityAccess_ValidCheck();
	if(cTrue == bValidCheck)
	{
		if(cSeaStep_Client_ReqSeed == mGetSecurityAccessStep())
		{ /* client request seed*/
			if(LAPSeaIsServiceUnLocked()) //positive response with seed = 0
			{
				u8LAPSea_SeqStep = cSeaStep_Server_Idle;
				LAPDiaResponse.Buffer[2] = 0;
				LAPDiaResponse.Buffer[3] = 0;
				LAPDiaResponse.Buffer[4] = 0;
				LAPDiaResponse.Buffer[5] = 0;
				LAPDiaResponse.Buffer[6] = 0;
				LAPDiaResponse.Buffer[7] = 0;
				LAPDiaResponse.Buffer[8] = 0;
				LAPDiaResponse.Buffer[9] = 0;
				if(cLAPDiaIdEXTDSSession == mGetActiveSessionType())
				{
					LAPDiaPreparePositiveResponse(cLng_Extd_Seed_Srv_to_Client);
				}
				else //if(cLAPDiaIdPRGSSession == mGetActiveSessionType())
				{
					LAPDiaPreparePositiveResponse(cLng_PRGS_Seed_Srv_to_Client);
				}
				//else
				{
					//LAPDiaPreparePositiveResponse(cLng_PRGS_Seed_Srv_to_Client);
				}
			}
			else
			{
				u8LAPSea_SeqStep = cSeaStep_Server_SentSeed;
				LAPSeaGenRandomSeed(); /* Generate seed if two sucessive req without key,the last is final seed*/

				LAPDiaResponse.Buffer[2] = u8LAPSea_Seed_H_HH;
				LAPDiaResponse.Buffer[3] = u8LAPSea_Seed_H_HL;
				LAPDiaResponse.Buffer[4] = u8LAPSea_Seed_H_LH;
				LAPDiaResponse.Buffer[5] = u8LAPSea_Seed_H_LL;

				LAPDiaResponse.Buffer[6] = u8LAPSea_Seed_L_HH;
				LAPDiaResponse.Buffer[7] = u8LAPSea_Seed_L_HL;
				LAPDiaResponse.Buffer[8] = u8LAPSea_Seed_L_LH;
				LAPDiaResponse.Buffer[9] = u8LAPSea_Seed_L_LL;

				if(cLAPDiaIdEXTDSSession == mGetActiveSessionType())
				{
					LAPDiaPreparePositiveResponse(cLng_Extd_Seed_Srv_to_Client);
				}
				else//if(cLAPDiaIdPRGSSession == mGetActiveSessionType())
			    {
					LAPDiaPreparePositiveResponse(cLng_PRGS_Seed_Srv_to_Client);
				}
			}
		}
		else
		{ /* client response key*/
			u8LAPSea_SeqStep = cSeaStep_Server_Idle;

			//if(cLAPDiaIdEXTDSSession == mGetActiveSessionType()) //customer
			{
				u32Key_H_Srv = SeedToKeyH(cKey1Mask);
				u32Key_L_Srv = SeedToKeyL(cKey2Mask);
			}
			//else if(cLAPDiaIdPRGSSession == mGetActiveSessionType())
			{
				//u32Key_H_Srv = SeedToKeyH(cKey2Mask);
						//mCalcSecurityAccessKey_2(	((((U16)u8LAPSea_Seed_H_HH) << 8) + u8LAPSea_Seed_H_HL),
														//((((U16)u8LAPSea_Seed_H_LH) << 8) + u8LAPSea_Seed_H_LL));
			}
			//else
			{
				//
			}
#if defined(COMPILATION_NATIVE)
			mLDBprintf("SEA:key = %X",u32Key_H_Srv);
#endif
			u8Key_Srv_H_HH = (U8)((u32Key_H_Srv & 0xFF000000) >> 24);
			u8Key_Srv_H_HL = (U8)((u32Key_H_Srv & 0x00FF0000) >> 16);
			u8Key_Srv_H_LH = (U8)((u32Key_H_Srv & 0x0000FF00) >> 8 );
			u8Key_Srv_H_LL = (U8)((u32Key_H_Srv & 0x000000FF)      );

			u8Key_Srv_L_HH = (U8)((u32Key_L_Srv & 0xFF000000) >> 24);
			u8Key_Srv_L_HL = (U8)((u32Key_L_Srv & 0x00FF0000) >> 16);
			u8Key_Srv_L_LH = (U8)((u32Key_L_Srv & 0x0000FF00) >> 8 );
			u8Key_Srv_L_LL = (U8)((u32Key_L_Srv & 0x000000FF)      );
			// all key is 8 bytes long
			if((u8Key_Srv_H_HH == LAPDiaMemorizedRequest.Buffer[2])
				&&(u8Key_Srv_H_HL == LAPDiaMemorizedRequest.Buffer[3])
				&&(u8Key_Srv_H_LH == LAPDiaMemorizedRequest.Buffer[4])
				&&(u8Key_Srv_H_LL == LAPDiaMemorizedRequest.Buffer[5])
				&&(u8Key_Srv_L_HH == LAPDiaMemorizedRequest.Buffer[6])
				&&(u8Key_Srv_L_HL == LAPDiaMemorizedRequest.Buffer[7])
				&&(u8Key_Srv_L_LH == LAPDiaMemorizedRequest.Buffer[8])
				&&(u8Key_Srv_L_LL == LAPDiaMemorizedRequest.Buffer[9])
				)
			{ /* Key is ok,unlock */
				LAPSeaUnlock_BySession();
				switch(mGetActiveSessionType())
				{
				case cLAPDiaIdPRGSSession:
					LAPDiaResponse.Buffer[1] = cSendKey_Level_PRGS;
					LAPDiaPreparePositiveResponseSimple(cLng_PRGS_Seed_Srv_to_Client);
					break;
				case cLAPDiaIdEXTDSSession:
					LAPDiaResponse.Buffer[1] = cSendKey_Level_EXTDS;
					LAPDiaPreparePositiveResponseSimple(cLng_Extd_Key_Srv_to_Client);
					break;
				default:
					break;
				}
				u8LAPSea_FailAccessTime = 0;
				//mDATWrite(U8Bit,NVM_SecurityAccessTimes,u8LAPSea_FailAccessTime,Default);
			}
			else
			{ /* Key is NG */
				u8LAPSea_FailAccessTime++;
				//mDATWrite(U8Bit,NVM_SecurityAccessTimes,u8LAPSea_FailAccessTime,Default);
				if(u8LAPSea_FailAccessTime >= cFailAccessTryTimesMax)
				{
					u8LAPSea_FailAccessTime = cFailAccessTryTimesMax;

					//mDATWrite(U8Bit,NVM_SecurityAccessTimes,u8LAPSea_FailAccessTime,Default);
					if(cTOSSeqInactiveGraph == TOSSeqGraphState(cTOSSeqLAPDiaSeaDTMgr))
					{
						mLDBTrace("SEA:Start DiaSeaDTMgr.");
						TOSSeqActivateGraph(cTOSSeqLAPDiaSeaDTMgr); /*start DT*/
					}
					LAPDiaPrepareNegativeResponse(cLAPDiaExceedNumberOfAttempts);
					//当错误计数器大于等于3时，首先返回否定响应ExceedNumberOfAttempts，然后启动一个10s定时器，在10s内，任意的种子请求，
					//返回0x37（Required time delay not expired），当延时超时，安全访问计数器减1，成功解锁后计数器清零。
					//TOSStartTimer(&stFailAccessTimer);
				}
				else
				{
					LAPDiaPrepareNegativeResponse(cLAPDiaInvalidKey);
				}
			}
		}
	}
	else
	{
		/*no statement,NRC_ have been processed in Valid check fun*/
		u8LAPSea_SeqStep = cSeaStep_Server_Idle;
	}    
}
#endif //cSecurityAccess_Used


//==============================================================================
// DESCRIPTION : LAPSeacRequestDownLoad
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : Read Status Of SEA Service
//==============================================================================
#ifdef cRequestDownLoad_Used
void LAPSeaRequestDownLoad(void)
{  
    LAPDiaPrepareNegativeResponse(cLAPDiaSecurityAccessDenied);
}
#endif //cRequestDownLoad_Used


//==============================================================================
// DESCRIPTION : LAPSeaRequestUpLoad
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : Read Status Of SEA Service
//==============================================================================
#ifdef cRequestUpLoad_Used
void LAPSeaRequestUpLoad(void)
{  
    LAPDiaPrepareNegativeResponse(cLAPDiaSecurityAccessDenied);
}
#endif //cRequestUpLoad_Used


//==============================================================================
// DESCRIPTION : LAPSeaTransferData
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : Read Status Of SEA Service
//==============================================================================
#ifdef cTransferData_Used
void LAPSeaTransferData(void)
{  
    LAPDiaPrepareNegativeResponse(cLAPDiaRequestSequenceError);
}
#endif //cTransferData_Used


//==============================================================================
// DESCRIPTION : LAPSeaRequestTransferExit
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : Read Status Of SEA Service
//==============================================================================
#ifdef cRequestTransferExit_Used
void LAPSeaRequestTransferExit(void)
{  
    LAPDiaPrepareNegativeResponse(cLAPDiaRequestSequenceError);
}
#endif //cRequestTransferExit_Used


//==============================================================================
// DESCRIPTION : LAPSeaOpenSession
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION :
//==============================================================================
void LAPSeaOpenSession (void)
{
	LAPSeaInit();
}


//==============================================================================
// DESCRIPTION : LAPSeaCloseSession
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION :
//==============================================================================
void LAPSeaCloseSession (void)
{
	LAPSeaInit();
}

//==============================================================================
// DESCRIPTION :LAPSeaIsServiceUnLocked
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
BOOL	LAPSeaIsServiceUnLocked(void)
{
	BOOL	bUnLocked;

	if(cLAPDiaIdPRGSSession  == mGetActiveSessionType())
	{
		bUnLocked = (cAndMsk_Getlock_PRGS == (u8LAPSea_Lock & cAndMsk_Getlock_PRGS));
	}
	else if(cLAPDiaIdEXTDSSession == mGetActiveSessionType())
	{
		bUnLocked = (cAndMsk_Getlock_EXTDS == (u8LAPSea_Lock & cAndMsk_Getlock_EXTDS));
	}
	else
	{
		/*no statement*/
		bUnLocked = cTrue;
	}

	return(bUnLocked);
}



//==============================================================================
// DESCRIPTION :
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void LAPSeaDTElapsed(void)
{
	mLDBTrace("SEA:DiaSeaDTMgr Elapsed.");
	if(u8LAPSea_FailAccessTime > 0)
	{
		u8LAPSea_FailAccessTime --;
		//mDATWrite(U8Bit,NVM_SecurityAccessTimes,u8LAPSea_FailAccessTime,Default);
	}
}
