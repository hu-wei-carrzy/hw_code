//******************************************************************************
// Copyright:    This software is JYD property.
//               Duplication or disclosure without JYD written authorization
//               is prohibited.
// -----------------------------------------------------------------------------
// Project:      BCM313
// Language:     C
// -----------------------------------------------------------------------------
// Component:  define the EEP interface with MCU related function.
//                       
// -----------------------------------------------------------------------------
//******************************************************************************
// This line is used to separate code and file header.This is begin.
//*****************************BEGIN_NOMOVE*************************************
// Time:2016-09-19 09:31:07
// 1: add write completion check macro
//2018年5月30日 15:51:22
//zjb
//去除EEP初始化动作，因为这个初始化动作在BSP_SUP.c中执行过了。
//*****************************END_NOMOVE***************************************
// This line is used to separate code and file header. This is last line.
//******************************************************************************



/*--------------------------------------------------------------------------
Body Identification
--------------------------------------------------------------------------*/

#define LDB_EEP "LDB_EEP"

/*-------------------------------------------------------------------------
Included files

  #include <system_file_name.h>
  #include "project_file_name.h"
--------------------------------------------------------------------------*/
//#include "ldbtypes.h"
//#include "ldb.h"
//#include "ldb_int.h"

#include "LDB_EEP.h"
#include "LDB_EEP_CFG.h"
#ifdef cHeadIncludeType_Directly
#include "BSP_EEP.h"
#else
#include "..\..\..\BSP\BSP_EEP\BSP_EEP.h"
#endif
/*--------------------------------------------------------------------------
Local constants

  #define cConstantName   ((tType) ConstantValue)
--------------------------------------------------------------------------*/



/*--------------------------------------------------------------------------
Local macros

  #define mMacroName   (MacroDefinition)
--------------------------------------------------------------------------*/
#define mReadEEPBusyState() ((TRUE == BSP_EEP_IsWriteInProcess()) ? 0u : 1u)


/*--------------------------------------------------------------------------
Local types

  struct  sStructureName { ... };
  union   uUnionName { ... };
  enum    eEnumerationName { ... };
  typedef Expression tTypeName;
--------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------
Local data

  static  tType   VariableName;
  static  tType*  pVariableName; 
--------------------------------------------------------------------------*/

static  tAddress  WriteAddress;
static  BOOL  IsWriteProcessing;

/*--------------------------------------------------------------------------
Constant local data

  static const tType  VariableName;
--------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------
Exported data

  tType   CMPVariableName;      (CMP: 3 characters to identify this component)
  tType*  pCMPVariableName;     (CMP: 3 characters to identify this component)
--------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------
Constant exported data

  const tType   CMPVariableName;(CMP: 3 characters to identify this component)
--------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------
  Local function prototypes

  static tTypeRetour FunctionName(tTypeArgument1 ArgumentName1, ... );
  --------------------------------------------------------------------------*/

static BOOL IsWriteFinished (void);

/*============================================================================
  =========================== LOCAL FUNCTIONS ================================
  ==========================================================================*/

/*============================================================================
  DESCRIPTION : static BOOL IsWriteFinished(void)
            Check if write operation is finished

  PARAMETERS (Type,Name,Min,Max) :  none

  RETURN VALUE :  none

  DESIGN INFORMATION :  refer to Detailed Design Document
============================================================================*/
static BOOL IsWriteFinished(void)
{
#if 0 //this is for SPI
    U8 SecuredStatusRegister;
    U8 StatusRegister = 0;
    U8 ReadRetryCounter = 0;
    U8 IdenticalReadingsCounter = 0;

#if 0
    //  Select
    mSelectEEPChip();
    //Temporization to ensure the status validity (tSHQV value)
    mLDBHarActiveWaitUs(1);
#endif

    //Tm073077 - EEPROM Read Status Register - secured read in
    //case of SPI signals perturbation, but how long might be these perturbations?
    //Execute filtering of this signal!

    SecuredStatusRegister = mReadEEPBusyState();
    //read until data of two consecutive readings are identical
    while(ReadRetryCounter < cLDBEepMaxReadRetryNumber)
    {
        // The maximum number of retry is not reached
        // A read cycle has to be done again if data are not identical
        //move data from last reading to SecuredStatusRegister and read again
        StatusRegister = mReadEEPBusyState();

        if(SecuredStatusRegister == StatusRegister)
        {   //data are identical, increase counter
            IdenticalReadingsCounter++;
            if(IdenticalReadingsCounter == cLDBEepMaxIdenticalReadingsNumber)
            {   //data are identical, cycle has to be breaked
                ReadRetryCounter = cLDBEepMaxReadRetryNumber;
            }
            else
            {
                ReadRetryCounter++;
            }
        }
        else
        {
            SecuredStatusRegister = StatusRegister;
            ReadRetryCounter++;
            IdenticalReadingsCounter = 0; //to have identical consecutive readings
        }

    }
    //If reading is not identical set StatusRegister to writing in progress state!
    //StatusRegister = 0   -> writing in progress
    if(SecuredStatusRegister != StatusRegister)
    {
        StatusRegister = 0;
    }

#if 0
    //  UnSelect
    mUnselectEEPChip();
#endif

    return ((StatusRegister == 1));
    //upper for SPI
#endif
    BOOL bRet = cFalse;

    bRet = BSP_EEP_IsWriteInProcess();

    return !bRet;
}

/*============================================================================
  =========================== EXPORTED FUNCTIONS =============================
  ==========================================================================*/

/*============================================================================
  DESCRIPTION : void LDBEepInit(void)
              Initialize LDB Eep

  PARAMETERS (Type,Name,Min,Max) :  none

  RETURN VALUE :  none

  DESIGN INFORMATION :  refer to Detailed Design Document
============================================================================*/
void LDBEepInit(void)
{
    IsWriteProcessing = cFalse;
#if 0
    mLDBEepSelectMemoryOrganization();
    mUnselectEEPChip();
#endif

    BSP_EEP_Init();
}

/*============================================================================
  DESCRIPTION : LDBEepSendWithAddr
        Write pMsg->Lng bytes in eeprom

  PARAMETERS (Type,Name,Min,Max) :  none

  RETURN VALUE :  none

  DESIGN INFORMATION :  refer to Detailed Design Document
============================================================================*/
void  LDBEepSendWithAddr(tAddress Address,tMsg* pMsg)
{
#if (defined(cLDBHarEep93Org_16Bits))
    U8 u8Index;
#endif

    // check if the data size goes beyond the current EEPROM page
    mLIBassert( ((Address + pMsg->Lng) <= cNbByte) &&
        (((Address % cEEPROMPageSize) + pMsg->Lng) <= cEEPROMPageSize) );

    WriteAddress = Address;

#if 0
    //  Select eep
    mSelectEEPChip();
    // send WRITE instruction
    mLDBEepSendBitsToSPI(cInstructionWRITE, 3);
#endif

    // write data
    BSP_EEP_WriteData(WriteAddress, pMsg->pBuffer, pMsg->Lng);

#if 0
    //  Unselect eep
    mLDBEepPutSPIInIdleMode();
    mUnselectEEPChip();
#endif

    //!!!!!!!zjb: must set true.!!!!!!!
    IsWriteProcessing = cTrue;
}

/*============================================================================
  DESCRIPTION : LDBEepReceiveWithAddr
          Read pMsg->Lng bytes from eeprom

  PARAMETERS (Type,Name,Min,Max) :  none

  RETURN VALUE :  none

  DESIGN INFORMATION :  refer to Detailed Design Document
============================================================================*/
void  LDBEepReceiveWithAddr(tAddress Address,tMsg* pMsg)
{
    U8 u8Index = 0U;

    u8Index = u8Index;

    // check if the data size goes beyond the current EEPROM page
    mLIBassert( ((Address + pMsg->Lng) <= cNbByte) &&
        (((Address % cEEPROMPageSize) + pMsg->Lng) <= cEEPROMPageSize) );

    IsWriteProcessing = cFalse;

#if 0
    //select eep
    mSelectEEPChip();
    // send READ instruction
    mLDBEepSendBitsToSPI(cInstructionREAD, 3);
#endif

    // read data
    BSP_EEP_ReadData(Address, pMsg->pBuffer, pMsg->Lng);

#if 0
    //unselect eep
    mLDBEepPutSPIInIdleMode();
    mUnselectEEPChip();
#endif

#if 0
    DATEepCallBackRxWithAddr(Address, cLDBCorrect);
#endif
    LDBCallBackRxWithAddr(cLDBChannelLDB_EEP, Address, cLDBCorrect);
}

/*============================================================================
  DESCRIPTION :void LDBEepControl(tCtrl Ctrl)
            Lock and unlock eeprom

  PARAMETERS (Type,Name,Min,Max) :  none

  RETURN VALUE :  none

  DESIGN INFORMATION :  refer to Detailed Design Document
============================================================================*/
void LDBEepControl(tCtrl Ctrl)
{
    //  Command evaluation
    switch(Ctrl)
    {
    case cLDBEepUnLock:
#if 0
        //  Select eep
        mSelectEEPChip();
        // send EWEN instruction
        mLDBEepSendBitsToSPI(cInstructionEWEN, 3);
        //  Unselect eep
        mLDBEepPutSPIInIdleMode();
        mUnselectEEPChip();
#endif
        BSP_EEP_Unlock();
        break;
    case cLDBEepLock:
#if 0
        //  Select eep
        mSelectEEPChip();
        // send EWDS instruction
        mLDBEepSendBitsToSPI(cInstructionEWDS, 3);
        //  Unselect eep
        mLDBEepPutSPIInIdleMode();
        mUnselectEEPChip();
#endif
        BSP_EEP_Lock();
        break;

#ifdef cLDBEepCheckWriteCompletion
    case cLDBEepCheckWriteCompletion:
        if(IsWriteProcessing != cFalse)
        {
            // There is no timeout in the LDB.
            // The timeout is managed by the DAT Layer
            if(IsWriteFinished() == cTrue)
            {
                // If the write operation is finished
#if 0
                DATEepCallBackTxWithAddr(WriteAddress, cLDBCorrect);
#endif
                LDBCallBackTxWithAddr(cLDBChannelLDB_EEP, WriteAddress, cLDBCorrect);
                IsWriteProcessing = cFalse;
            }
        }
        break;
#endif


    default:
        mLIBassert(cFalse);
        break;

    }
#if 0
    DATEepCallBackEndCtrl(Ctrl,cLDBCorrect);
#endif
    LDBCallBackEndControl(cLDBChannelLDB_EEP, Ctrl, cLDBCorrect);

}

