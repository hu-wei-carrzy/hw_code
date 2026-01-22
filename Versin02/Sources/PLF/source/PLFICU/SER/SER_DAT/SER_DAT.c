#include "SER_DAT.h"



#define mSERDATIsSetFlag(Tab, Pos)\
        ((BOOL)(Tab[ ((U8)Pos>>3)] & (((U8)1)<<( (U8)(Pos & (U8)0x07)))) != 0)

#define mSERDATIsClearFlag(Tab, Pos)\
        ((BOOL)(Tab[ ((U8)Pos>>3)] & (((U8)1)<<( (U8)(Pos & (U8)0x07)))) == 0)

#define mSERDATSetFlag(Tab, Pos)\
        Tab[ ((U8)Pos>>3)] |= (((U8)1)<<( (U8)(Pos & (U8)0x07)))

#define mSERDATClearFlag(Tab, Pos)\
        Tab[ ((U8)Pos>>3)] &= ~(((U8)1)<<( (U8)(Pos & (U8)0x07)))

#define mSERDATClearAllFlag(Tab)        \
        mLIBmemset(Tab, 0, sizeof(Tab))

#define cIOControlBitNum   (32+16)

#define cIOControlFlagLength (U8)((cIOControlBitNum-1)/8 + 1)





//================================================
//RunIn Mode
static	BOOL			gbRunInMode;
static  BOOL            gbSleepCtrlFlag;
static  U8              gu8FuelTTSts;
static  U16             gu16SpeedKmph;
static  BOOL            gbIsSelfCheckTimeEnd;






void SERDATInit(void)
{
	gbRunInMode = cFalse;
    gbSleepCtrlFlag = cFalse;
    gu8FuelTTSts = 0;
    gu16SpeedKmph = 0;
    gbIsSelfCheckTimeEnd = cTrue;

    //gbIsDiagMode = cFalse;

}



void    SERDAT_SetSelfCheckTimeEnd(BOOL bVal)
{
	gbIsSelfCheckTimeEnd = bVal;
}

BOOL    SERDAT_GetSelfCheckTimeEnd(void)
{
	return gbIsSelfCheckTimeEnd;
}

void    SERDAT_SetSpeedKmph(U16 u16Speed)
{
	gu16SpeedKmph = u16Speed;
}

U16    SERDAT_GetSpeedKmph(void)
{
	return gu16SpeedKmph;
}


void	SERDAT_SetRunInMode(BOOL bVal)
{
	gbRunInMode = bVal; //cTrue:Runin mode
}
BOOL	SERDAT_GetRunInMode(void)
{
	return(gbRunInMode); //cTrue:Runin mode
}

void SERDAT_SetSleepCtrlFlag(BOOL bvalue)
{
	gbSleepCtrlFlag = (BOOL)bvalue;
}

BOOL SERDAT_GetSleepCtrlFlag(void)
{
	return gbSleepCtrlFlag;
}


void SERDAT_WriteU8BitFuelTTSts(U8 u8Val)
{
	gu8FuelTTSts = u8Val;//cTTSts_Off,cTTSts_On,cTTSts_Blink
}
U8	SERDAT_ReadU8BitFuelTTSts(void)
{
	return(gu8FuelTTSts);//cTTSts_Off,cTTSts_On,cTTSts_Blink
}












