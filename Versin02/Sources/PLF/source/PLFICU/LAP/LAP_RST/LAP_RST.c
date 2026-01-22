

//------------------------------------------------------------------------------
// Body Identification
//------------------------------------------------------------------------------
#define lap_rst "lat_rst"

//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//------------------------------------------------------------------------------
#include "LAP_RST.h"



//------------------------------------------------------------------------------
// Local constants
//------------------------------------------------------------------------------
// #define cConstantName    ((tType)ConstantValue)
//¨¦?¦Ì??¡ä??
#define cResetOffset_Pwr            ((U32)(0U))
//¨¨¨ª?t?¡ä??1¡¤?¡ä??
#define cResetOffset_SWDR           ((U32)(12U))
//¨®2?t?¡ä??1¡¤?¡ä??
#define cResetOffset_HWDR           ((U32)(11U))
//¨¨¨ª?t¡ä£¤¡¤¡é¨®2?t?¡ä??¡ê??a¨¤?2?¨º1¨®?¡ä?¡äa¦Ì?¨¨¨ª?t?¡ä??¡ê?¨°¨°?a?a???¡ä???¡ä¨®D?¨º¨¬a¡ê??-¨°¨°¡äy2¨¦
#define cResetOffset_SHRST          ((U32)(20U))
//?¨²2?¦Ì¨ª?1?¡ä??
#define cResetOffset_LVDL1R          ((U32)(30U))
//¨ªa2?¦Ì¨ª?1?¡ä??
#define cResetOffset_LVDL2R          ((U32)(31U))

//¨º¡À?¨®?¡ä??
#define cResetOffset_CSVMOR          ((U32)(24U))
#define cResetOffset_CSVSOR          ((U32)(25U))
#define cResetOffset_CSVPR0          ((U32)(26U))
#define cResetOffset_CSVSR0          ((U32)(27U))



#define cResetCause_Pwr              (((U32)1)<<cResetOffset_Pwr)
#define cResetCause_SWDR             (((U32)1)<<cResetOffset_SWDR)
#define cResetCause_HWDR             (((U32)1)<<cResetOffset_HWDR)
#define cResetCause_SHRST            (((U32)1)<<cResetOffset_SHRST)
#define cResetCause_LVDL1R           (((U32)1)<<cResetOffset_LVDL1R)
#define cResetCause_LVDL2R           (((U32)1)<<cResetOffset_LVDL2R)

#define cResetCause_Clock            ((((U32)1)<<cResetOffset_CSVMOR)|(((U32)1)<<cResetOffset_CSVSOR)|(((U32)1)<<cResetOffset_CSVPR0)|(((U32)1)<<cResetOffset_CSVSR0))



//------------------------------------------------------------------------------
// Local macros
//------------------------------------------------------------------------------
// #define mMacroName       (MacroDefinition)
#define mRestCause_Is_Pwr(v)              (cResetCause_Pwr    == (cResetCause_Pwr & (v)))
#define mRestCause_Is_SWDR(v)             (cResetCause_SWDR   == (cResetCause_SWDR & (v)))
#define mRestCause_Is_HWDR(v)             (cResetCause_HWDR   == (cResetCause_HWDR & (v)))
#define mRestCause_Is_SHRST(v)            (cResetCause_SHRST  == (cResetCause_SHRST & (v)))
#define mRestCause_Is_LVDL1R(v)           (cResetCause_LVDL1R == (cResetCause_LVDL1R & (v)))
#define mRestCause_Is_LVDL2R(v)           (cResetCause_LVDL2R == (cResetCause_LVDL2R & (v)))
#define mRestCause_Is_Clock(v)            (cResetCause_Clock  == (cResetCause_Clock & (v)))


//------------------------------------------------------------------------------
// Local types
//------------------------------------------------------------------------------
// typedef Expression   tTypeName;


//------------------------------------------------------------------------------
// Local data
//------------------------------------------------------------------------------



//------------------------------------------------------------------------------
// Constant local data
// -----------------------------------------------------------------------------
// static const tType  cConstantName;


//------------------------------------------------------------------------------
// Exported data
//------------------------------------------------------------------------------
// Reduce to minimum the usage of extern data members!!!
// tType   LAYCmpVariableName;  //LAY: 3 characters to identify the layer
// tType*  pLAYCmpVariableName; //Cmp: 3-4 characters to identify the component
// U8      u8LAYCmpVariableName;
// U16*    pu16LAYCmpVariableName;

//------------------------------------------------------------------------------
// Constant exported data
//------------------------------------------------------------------------------
// Reduce to minimum the usage of extern constant data members!!!
// extern const tType  cLAYCmpConstantName;
// extern const U32    cu32LAYCmpConstantName;

//------------------------------------------------------------------------------
// Local function prototypes
//------------------------------------------------------------------------------
// static tType CmpFunctionName( tTypeArgument1 ArgumentName1, ... );


//==============================================================================
// LOCAL FUNCTIONS
//==============================================================================

//==============================================================================
// DESCRIPTION :
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================





//==============================================================================
// EXPORTED FUNCTIONS
//==============================================================================


/*============================================================================
  DESCRIPTION : update reset counters by Reg RCCSRC

    Bit0: Power Reset cause bit
    Bit1: External Reset cause bit
    Bit2: Main Clock stop detection Reset cause bit
    Bit3: Sub Clock stop detection Reset cause bit
    Bit4: Software Reset cause bit
    Bit5: Watchdog timer Reset cause bit
    Bit6: Main Clock Missing Flag
    Bit7: Sub Clock Missing Flag

  PARAMETERS (Type,Name,Min,Max) :  none

  RETURN VALUE :  none

  DESIGN INFORMATION :  refer to Detailed Design Document
============================================================================*/
void    LAPRstSetMCUResetTimes(void)
{
    U32  u32CPUResetCause;
    U8  u8Reset_Times;

    u32CPUResetCause = mSERRead(U32Bit,ResetCause,Default);

#if defined(COMPILATION_NATIVE)
    TOSWriteSignal(cTOSSignalLAPCanEcuPowerOnReset); // For LAP_CAN NM
    TOSWriteSignal(cTOSSignalLAPFCEcuPowerOnReset);  // For SysRS_03_LCD_Routine_464
#endif

    //TOSWriteSignal(cTOSSignalLAPDiaEcuPowerOnReset);


    if(mRestCause_Is_Pwr(u32CPUResetCause))
    {
        //TOSWriteSignal(cTOSSignalLAPCanEcuPowerOnReset); // For LAP_CAN NM
        //TOSWriteSignal(cTOSSignalLAPFCEcuPowerOnReset);  // For SysRS_03_LCD_Routine_464
        u8Reset_Times = mSERRead(U8Bit,EEP_ResetTimes_PwrExt,Default);
        if(u8Reset_Times < (U16)0xFF)
        {
            u8Reset_Times++;
        //    mSERWrite(U8Bit,EEP_ResetTimes_PwrExt,u8Reset_Times,Default);
        }
    }
    else if(mRestCause_Is_SWDR(u32CPUResetCause) || mRestCause_Is_HWDR(u32CPUResetCause))
    {
        u8Reset_Times = mSERRead(U8Bit,EEP_ResetTimes_WatchDog,Default);
        if(u8Reset_Times < (U16)0xFF)
        {
            u8Reset_Times++;
        //    mSERWrite(U8Bit,EEP_ResetTimes_WatchDog,u8Reset_Times,Default);
        }
    }
    else if(mRestCause_Is_SHRST(u32CPUResetCause)) // SW
    {
        u8Reset_Times = mSERRead(U8Bit,EEP_ResetTimes_SWReset,Default);
        if(u8Reset_Times < (U16)0xFF)
        {
            u8Reset_Times++;
        //    mSERWrite(U8Bit,EEP_ResetTimes_SWReset,u8Reset_Times,Default);
        }
    }
    else if(mRestCause_Is_Clock(u32CPUResetCause))//NVM_ResetTimes_CLK
    {
        u8Reset_Times = mSERRead(U8Bit,EEP_ResetTimes_CLK,Default);
        if(u8Reset_Times < (U16)0xFF)
        {
            u8Reset_Times++;
        //    mSERWrite(U8Bit,EEP_ResetTimes_CLK,u8Reset_Times,Default);
        }
    }
    else
    {
        //???¨¹?¡ä???-¨°¨°¡ê?¦Ì¨¨¡äy???¨®EEP????
    }

    u8Reset_Times = mSERRead(U8Bit,EEP_ResetTimes_Total,Default);
    if(u8Reset_Times < (U16)0xFF)
    {
        u8Reset_Times++;
        //mSERWrite(U8Bit,EEP_ResetTimes_Total,u8Reset_Times,Default);
    }

}






