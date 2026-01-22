//******************************************************************************
// Copyright:    This software is JYD property.
//               Duplication or disclosure without JYD written authorization
//               is prohibited.
// -----------------------------------------------------------------------------
// Project:      BCM313
// Language:     C
// -----------------------------------------------------------------------------
// Component:  Digital output, including Power IC and TT and Power lock
// -----------------------------------------------------------------------------
//******************************************************************************
// This line is used to separate code and file header.This is begin.
//*****************************BEGIN_NOMOVE*************************************
//  Time:2016-09-18 13:34:03
// 1:add code for 5T050 and 6200 ouput
//*****************************END_NOMOVE***************************************
// This line is used to separate code and file header. This is last line.
//******************************************************************************

/*--------------------------------------------------------------------------
  Body Identification
  --------------------------------------------------------------------------*/
#define dat_Dou  "dat_Dou"

/*--------------------------------------------------------------------------
  Included files

  #include <system_file_name.h>
  #include "project_file_name.h"
  --------------------------------------------------------------------------*/
#include "dat_Dou.h"

/*--------------------------------------------------------------------------
  Local constants

  #define cConstantName   ((tType) ConstantValue)
  --------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------
  Local macros

  #define mMacroName   (MacroDefinition)
  --------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------
  Local types

  struct  sStructureName { ... };
  union   uUnionName { ... };
  enum    eEnumerationName { ... };
  typedef Expression tTypeName;
  --------------------------------------------------------------------------*/

#define    cSleepState             ( (tDATDouState)0U)
#define    cWakeUpState             ((tDATDouState)1U)

/*--------------------------------------------------------------------------
  Local data

  static  tType   VariableName;
  static  tType*  pVariableName; 
  --------------------------------------------------------------------------*/
#ifdef cCfg_SerialoutputByHC59X
static tTOSAlarm  PeriodicAlarm;
#endif

static tDATDouState     Status;
#ifdef cCfg_SerialoutputByHC59X
static const tMsg       OutputMsg = {DATDouOutputBuffer,cDATDouOutputBufferSizeInBytes};
#endif
static BOOL bVirtualKeyPowerLock;
/*--------------------------------------------------------------------------
  Constant local Data

  static const tType  VariableName;
  --------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------
  Exported data

  tType   CMPVariableName;      (CMP: 3 characters to identify this component)
  tType*  pCMPVariableName;     (CMP: 3 characters to identify this component)
  --------------------------------------------------------------------------*/
U8 DATDouOutputBuffer[cDATDouOutputBufferSizeInBytes];

/*--------------------------------------------------------------------------
  Constant exported data
 
  const tType   CMPVariableName;(CMP: 3 characters to identify this component)
  --------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------
  Local function prototypes
  
  static tTypeRetour FunctionName(tTypeArgument1 ArgumentName1, ... );
  --------------------------------------------------------------------------*/

/****************************************************************************
*...........................................................................*
*............................ LOCAL FUNCTIONS ..............................*
*...........................................................................*
****************************************************************************/

/****************************************************************************
*...........................................................................*
*........................... EXPORTED FUNCTIONS.............................*
*...........................................................................*
****************************************************************************/
/*============================================================================
  DESCRIPTION : Initialise DAT_SOR component
  
  PARAMETERS (Type,Name,Min,Max) :  none

  RETURN VALUE :  none
 
  DESIGN INFORMATION :  refer to Detailed Design Document
============================================================================*/
void DATDouInit(const U8*pBuffer)
{
     mLIBmemcpy(DATDouOutputBuffer, pBuffer, cDATDouOutputBufferSizeInBytes);

    Status      = cSleepState;
    if(Status){} //to avoid a warning in release mode
    bVirtualKeyPowerLock = cFalse;
}

/*============================================================================
  DESCRIPTION : Write the lgical output buffer
  
  PARAMETERS (Type,Name,Min,Max) :  none

  RETURN VALUE :  none
 
  DESIGN INFORMATION :  refer to Detailed Design Document
============================================================================*/
void DATDouRefreshOutputTask(void)
{
#ifdef cCfg_SerialoutputByHC59X
    DATPouPrepareRefresh();

    LDBSendWithoutAddr(cLDBChannelLDB_DOU,(tMsg*)&OutputMsg);

#endif
}

/*============================================================================
  DESCRIPTION : This function is the call back called from 
                the LDB after writing logical output
  
  PARAMETERS (Type,Name,Min,Max) :  none

  RETURN VALUE :  none
 
  DESIGN INFORMATION :  refer to Detailed Design Document
============================================================================*/
void DATDouCallBackTxWithoutAddr(tStatus Statut)
{
    mLIBassert(Statut == cLDBCorrect);
    Statut = Statut;  // pour eviter un warning a la compilation sur cible
}

/*============================================================================
  DESCRIPTION : 提前启动

  PARAMETERS (Type,Name,Min,Max) :  none

  RETURN VALUE :  none

  DESIGN INFORMATION :
============================================================================*/
void DATDouRegistSysCheckTask(void)
{
    mLIBassert(Status != cWakeUpState);
    Status = cWakeUpState;
//至少要59X输出，这里才启动此任务，否则没有
//意义，2017年8月4日 19:04:50
#ifdef cCfg_SerialoutputByHC59X
    PeriodicAlarm.TaskID = cTOSTaskID_WriteLogical;
    TOSSetRelAlarm(&PeriodicAlarm, 0, mTOSConvMsEnTickAlarm(cDATDouWritingPeriodeValueMs));
#endif
    LDBControl(cLDBChannelLDB_DOU,cLDBDouEnterNominalMode);

}

/*============================================================================
  DESCRIPTION : 
  
  PARAMETERS (Type,Name,Min,Max) :  none

  RETURN VALUE :  none
 
  DESIGN INFORMATION :  refer to Detailed Design Document
============================================================================*/
void DATDouEnterActiveState(void)
{
    mLIBassert(Status != cWakeUpState);
    Status = cWakeUpState;
#ifdef cCfg_SerialoutputByHC59X
    PeriodicAlarm.TaskID = cTOSTaskID_WriteLogical;
    TOSSetRelAlarm(&PeriodicAlarm, 0, mTOSConvMsEnTickAlarm(cDATDouWritingPeriodeValueMs));
#endif
    LDBControl(cLDBChannelLDB_DOU,cLDBDouEnterNominalMode);
}

/*============================================================================
  DESCRIPTION : Start the output alarm
  
  PARAMETERS (Type,Name,Min,Max) :  none

  RETURN VALUE :  none
 
  DESIGN INFORMATION :  refer to Detailed Design Document
============================================================================*/
void DATDouEnterSleepMode(void)
{
    mLIBassert(Status == cWakeUpState);

#ifdef cCfg_SerialoutputByHC59X
    TOSCancelAlarm(&PeriodicAlarm);

#ifdef DATDOU_UPDATE_OUTPUT_BEFORE_SLEEPING
    DATDouRefreshOutputTask();
#endif

#endif

    Status = cSleepState;
    LDBControl(cLDBChannelLDB_DOU,cLDBDouEnterSleepMode);
}

/*============================================================================
  DESCRIPTION : Control callback
  
  PARAMETERS (Type,Name,Min,Max) :  none

  RETURN VALUE :  none
 
  DESIGN INFORMATION :  refer to Detailed Design Document
============================================================================*/
void DATDouCallBackEndCtrl(tCtrl Ctrl, tStatus Statut)
{
    mLIBassert(Statut == cLDBCorrect);
    Statut = Statut;  // pour eviter un warning a la compilation sur cible
    Ctrl = Ctrl;      // pour eviter un warning a la compilation sur cible
}


void DATDouCtrl(tCtrl Ctrl)
{
    LDBControl(cLDBChannelLDB_DOU,Ctrl);

    switch(Ctrl)
    {
        case cLDBDouPowerRelease:
            bVirtualKeyPowerLock = cFalse;
            break;
        case cLDBDouPowerLock:
            bVirtualKeyPowerLock = cTrue;
            break;
        default:
            break;
    }
}

BOOL DATDouGetKeyMCULockSt(void)
{
    return  bVirtualKeyPowerLock;
}

void DATDouOutPut(tAddress tLDBDouAdr,U8 u8Par)
{
    U8 u8Data = 0U;

     tMsg msgPwrICCfg =
    {
        &u8Data, 1U
    };

     u8Data = u8Par;

    LDBSendWithAddr(cLDBChannelLDB_DOU, tLDBDouAdr, (tMsg*)&msgPwrICCfg);
}


void DATDou_WriteMCU_LEDCtrol(U8 u8Par)
{
    U8 u8Data = 0U;

     tMsg msgPwrICCfg =
    {
        &u8Data, 1U
    };

     u8Data = u8Par;

    LDBSendWithAddr(cLDBChannelLDB_DOU, cLDBDouAdrMCU_OUT_IO_LED, (tMsg*)&msgPwrICCfg);
}

void DATDou_WriteMCU_A3G4250D_CSCtrol(U8 u8Par)
{
    U8 u8Data = 0U;

     tMsg msgPwrICCfg =
    {
        &u8Data, 1U
    };

     u8Data = u8Par;

    LDBSendWithAddr(cLDBChannelLDB_DOU, cLDBDouAdrMCU_OUT_A3G4250D_MCU_CS, (tMsg*)&msgPwrICCfg);
}

void DATDou_WriteMCU_A3G4250D_OECtrol(U8 u8Par)
{
    U8 u8Data = 0U;

     tMsg msgPwrICCfg =
    {
        &u8Data, 1U
    };

     u8Data = u8Par;

    LDBSendWithAddr(cLDBChannelLDB_DOU, cLDBDouAdrMCU_OUT_A3G4250D_OE, (tMsg*)&msgPwrICCfg);
}

void DATDou_WriteMCU_FLASH_SPI_WPCtrol(U8 u8Par)
{
    U8 u8Data = 0U;

     tMsg msgPwrICCfg =
    {
        &u8Data, 1U
    };

     u8Data = u8Par;

    LDBSendWithAddr(cLDBChannelLDB_DOU, cLDBDouAdrMCU_OUT_MCU_FLASH_SPI_WP, (tMsg*)&msgPwrICCfg);
}


void DATDou_WriteMCU_DRV_MOTOR_nSLEEPCtrol(U8 u8Par)
{
    U8 u8Data = 0U;

     tMsg msgPwrICCfg =
    {
        &u8Data, 1U
    };

     u8Data = u8Par;

    LDBSendWithAddr(cLDBChannelLDB_DOU, cLDBDouAdrMCU_OUT_DRV_MOTOR_nSLEEP, (tMsg*)&msgPwrICCfg);
}


void DATDou_WriteMCU_5V_SENSOR_ENCtrol(U8 u8Par)
{
    U8 u8Data = 0U;

     tMsg msgPwrICCfg =
    {
        &u8Data, 1U
    };

     u8Data = u8Par;

    LDBSendWithAddr(cLDBChannelLDB_DOU, cLDBDouAdrMCU_OUT_5V_SENSOR_EN, (tMsg*)&msgPwrICCfg);
}


void DATDou_WriteMCU_HDO_DSEN12Ctrol(U8 u8Par)
{
    U8 u8Data = 0U;

     tMsg msgPwrICCfg =
    {
        &u8Data, 1U
    };

     u8Data = u8Par;

    LDBSendWithAddr(cLDBChannelLDB_DOU, cLDBDouAdrMCU_OUT_HDO_DSEN12, (tMsg*)&msgPwrICCfg);
}

void DATDou_WriteMCU_CTL3408_IN_F2Ctrol(U8 u8Par)
{
    U8 u8Data = 0U;

     tMsg msgPwrICCfg =
    {
        &u8Data, 1U
    };

     u8Data = u8Par;

    LDBSendWithAddr(cLDBChannelLDB_DOU, cLDBDouAdrMCU_OUT_CTL3408_IN_F2, (tMsg*)&msgPwrICCfg);
}

void DATDou_WriteMCU_CTL3408_IN_F1Ctrol(U8 u8Par)
{
    U8 u8Data = 0U;

     tMsg msgPwrICCfg =
    {
        &u8Data, 1U
    };

     u8Data = u8Par;

    LDBSendWithAddr(cLDBChannelLDB_DOU, cLDBDouAdrMCU_OUT_CTL3408_IN_F1, (tMsg*)&msgPwrICCfg);
}

void DATDou_WriteMCU_HDO_DSEN34Ctrol(U8 u8Par)
{
    U8 u8Data = 0U;

     tMsg msgPwrICCfg =
    {
        &u8Data, 1U
    };

     u8Data = u8Par;

    LDBSendWithAddr(cLDBChannelLDB_DOU, cLDBDouAdrMCU_OUT_HDO_DSEN34, (tMsg*)&msgPwrICCfg);
}

void DATDou_WriteMCU_HDO_IN4Ctrol(U8 u8Par)
{
    U8 u8Data = 0U;

     tMsg msgPwrICCfg =
    {
        &u8Data, 1U
    };

     u8Data = u8Par;

    LDBSendWithAddr(cLDBChannelLDB_DOU, cLDBDouAdrMCU_OUT_HDO_IN4, (tMsg*)&msgPwrICCfg);
}

void DATDou_WriteMCU_HDO_IN3Ctrol(U8 u8Par)
{
    U8 u8Data = 0U;

     tMsg msgPwrICCfg =
    {
        &u8Data, 1U
    };

     u8Data = u8Par;

    LDBSendWithAddr(cLDBChannelLDB_DOU, cLDBDouAdrMCU_OUT_HDO_IN3, (tMsg*)&msgPwrICCfg);
}

void DATDou_WriteMCU_HDO_IN2Ctrol(U8 u8Par)
{
    U8 u8Data = 0U;

     tMsg msgPwrICCfg =
    {
        &u8Data, 1U
    };

     u8Data = u8Par;

    LDBSendWithAddr(cLDBChannelLDB_DOU, cLDBDouAdrMCU_OUT_HDO_IN2, (tMsg*)&msgPwrICCfg);
}


void DATDou_WriteMCU_HDO_IN1Ctrol(U8 u8Par)
{
    U8 u8Data = 0U;

     tMsg msgPwrICCfg =
    {
        &u8Data, 1U
    };

     u8Data = u8Par;

    LDBSendWithAddr(cLDBChannelLDB_DOU, cLDBDouAdrMCU_OUT_HDO_IN1, (tMsg*)&msgPwrICCfg);
}

void DATDou_WriteMCU_I2C_WCCtrol(U8 u8Par)
{
    U8 u8Data = 0U;

     tMsg msgPwrICCfg =
    {
        &u8Data, 1U
    };

     u8Data = u8Par;

    LDBSendWithAddr(cLDBChannelLDB_DOU, cLDBDouAdrMCU_OUT_I2C_WC, (tMsg*)&msgPwrICCfg);
}


void DATDou_WriteFLASH_SPI_OECtrol(U8 u8Par)
{
    U8 u8Data = 0U;

     tMsg msgPwrICCfg =
    {
        &u8Data, 1U
    };

     u8Data = u8Par;

    LDBSendWithAddr(cLDBChannelLDB_DOU, cLDBDouAdrMCU_OUT_MCU_FLASH_SPI_OE, (tMsg*)&msgPwrICCfg);
}
