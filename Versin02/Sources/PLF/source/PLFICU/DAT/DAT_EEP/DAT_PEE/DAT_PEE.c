
/*--------------------------------------------------------------------------
  Body Identification
  --------------------------------------------------------------------------*/

#define dat_pee   "dat_pee"


/*-------------------------------------------------------------------------
  Included files

  #include <system_file_name.h>
  #include "project_file_name.h"
  --------------------------------------------------------------------------*/

#include "DAT_PEE.h"

#include "DAT_PEE.hgr"
/*--------------------------------------------------------------------------
  Local constants

  #define cConstantName   ((tType) ConstantValue)
  --------------------------------------------------------------------------*/

// EEPROMErrorCounter is divided is 3 parts :
//                     7  6  5  4  3  2  1  0
//                     X  X  X  X  X  X  X  X
//       Rebuild flag _|  |  |  |  |  |  |  |_
//                   _____|  |  |  |  |  |____| 
// ReadErrorCounter_|________|  |  |  |_______|-WriteErrorCouter
//                  |___________|  |__________| 
#define cMaxReadCounter   ((U8) 0x07U)
#define cMaxWriteCounter  ((U8) 0x0FU)

#define cTimerPeeMs   ((tTOSTimer) 5000U) // 5 seconds

// Number of EEP Group 
#define cNumberOfEEPGroup  (cDATEepNumberOfProcess-1)

/*--------------------------------------------------------------------------
  Local macros

  #define mMacroName   (MacroDefinition)
  --------------------------------------------------------------------------*/

// The size of EEP Error Table 
#if (cDATPeeSizeErrorGroup != cNumberOfEEPGroup)

  #error "The size of EEP Error Table is different of the number of EEP Group."

#endif

// Direct Access EEP Errors Table
#define mGetEEPErrorTable(idx) mSERReadTable(U8Bit, EEPErrorTable, (idx), Default)
#define mSetEEPErrorTable(idx, Val) mSERWriteTable(U8Bit, EEPErrorTable, (idx), (Val), Default)

// Direct Access EEP Write Error Counter
#define mGetWriteCounter(idx)        (mGetEEPErrorTable(idx) & 0x0FU)

// Direct Access EEP Read Error Counter
#define mGetReadCounter(idx)         ((mGetEEPErrorTable((idx)) >> 4U) & 0x07U)

// Direct Access EEP Rebuild Flag
#define mGetRebuildFlag(idx)        ((mGetEEPErrorTable(idx) >> 7U) & 0x01U)

// Handle EEP Write Error Counter
#define mSetWriteError(idx)                             \
  DATPeeReportDTCPro((idx));                              \
  if(mGetWriteCounter((idx)) < cMaxWriteCounter)          \
  {                                                     \
      mSetEEPErrorTable((idx), (mGetEEPErrorTable(idx) + (U8)(1<<0))); \
  }

// Handle EEP Read Error Counter
#define mSetReadError(idx)                              \
  DATPeeReportDTCPro((idx));                              \
  if(mGetReadCounter((idx)) < cMaxReadCounter)            \
  {                                                     \
      mSetEEPErrorTable((idx), (mGetEEPErrorTable((idx)) + (U8)(1U << 4U))); \
  }

// Handle EEP Rebuild Flag
#define mSetRebuildFlag(idx)                                            \
                   mSetEEPErrorTable((idx), (mGetEEPErrorTable((idx)) | 0x80U))

#define mSetDbkDefaultValue(BankName)   \
    {                                   \
    static const U8 BankName##DefaultValues[cDATPeeSize##BankName] = mSERPeeResetBuffer##BankName();\
    (void)mLIBmemcpy((U8 *)DATDbkMirrors.BankName, BankName##DefaultValues, cDATPeeSize##BankName);\
    }
#define mInitDbkBank(BankName,Val)      \
    {                                   \
    (void)mLIBmemset((U8 *)DATDbkMirrors.BankName, (Val), cDATPeeSize##BankName);\
    }

#define mSetSbkDefaultValue(BankName)   \
    {                                   \
    static const U8 BankName##DefaultValues[cDATPeeSize##BankName] = mSERPeeResetBuffer##BankName();\
    (void)mLIBmemcpy((U8 *)DATSbkMirrors.BankName, BankName##DefaultValues, cDATPeeSize##BankName);\
    }
#define mInitSbkBank(BankName,Val)      \
    {                                   \
    (void)mLIBmemset((U8 *)DATSbkMirrors.BankName, (Val), cDATPeeSize##BankName);\
    }


#define mSetObkDefaultValue(BankName)   \
    {                                   \
    static const U8 BankName##DefaultValues[cDATPeeSize##BankName] = mSERPeeResetBuffer##BankName();\
    (void)mLIBmemcpy((U8 *)DATObkMirrors.BankName, BankName##DefaultValues, cDATPeeSize##BankName);\
    }
#define mInitObkBank(BankName,Val)      \
    {                                   \
    (void)mLIBmemset((U8 *)DATObkMirrors.BankName, (Val), cDATPeeSize##BankName);\
    }

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
static	tTOSTimer	TimerPee;
static	BOOL		bIsAnyBankBroken;

#define	mPeeIsSomeBankBroken()		(cTrue == bIsAnyBankBroken)
#define	mPeeSetBankBrokenFlag()		(bIsAnyBankBroken = cTrue);
#define	mPeeClearBankBrokenFlag()	(bIsAnyBankBroken = cFalse);

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


/*============================================================================
  =========================== LOCAL FUNCTIONS ================================
  ==========================================================================*/
static void DATPeeReportDTCPro(tDATDbkDoubleBankHandle BankHandle);



/*============================================================================
  =========================== EXPORTED FUNCTIONS =============================
  ==========================================================================*/

/*============================================================================
  DESCRIPTION :
  
  PARAMETERS (Type,Name,Min,Max) :  none

  RETURN VALUE :  none
 
  DESIGN INFORMATION :  refer to Detailed Design Document
============================================================================*/
void DATPeeInit(void)
{
#ifdef cDATSbkHandleErrorGroup

    // The error bank must be the first bank read at startup.
    // If its handle is 0, it will be the case
    
    // if the error bank is not the first bank read.
    // Then, if another bank read previouly set an error,
    // the error bank read will overwrite this error flag.
    
    mLIBassert( cDATSbkHandleErrorGroup==0 );
#endif
	mPeeClearBankBrokenFlag();
}

/*============================================================================
  DESCRIPTION :
  
  PARAMETERS (Type,Name,Min,Max) :  none

  RETURN VALUE :  none
 
  DESIGN INFORMATION :  refer to Detailed Design Document
============================================================================*/
BOOL DATPeeIsEepromAccessible(void)
{
    return (cTrue);
}

/*============================================================================
  DESCRIPTION : Rebuild indication
  
  PARAMETERS (Type,Name,Min,Max) :  none

  RETURN VALUE :  none
 
  DESIGN INFORMATION :  refer to Detailed Design Document
============================================================================*/
void DATPeeRebuildDoubleBank(tDATDbkDoubleBankHandle DoubleBankHandle)
{

    mLIBassert(DoubleBankHandle < cNbDbk);
    mSetRebuildFlag(cDATDbkFirstProcessHandle + DoubleBankHandle)

	mPeeSetBankBrokenFlag();
    switch(DoubleBankHandle)
    {
    mDBKGroupsRebuild();

    default:
      break;
    }
}

/*============================================================================
  DESCRIPTION :
  
  PARAMETERS (Type,Name,Min,Max) :  none

  RETURN VALUE :  none
 
  DESIGN INFORMATION :  refer to Detailed Design Document
============================================================================*/
void DATPeeErrorIndication(tDATDbkDoubleBankHandle DoubleBankHandle
                           , tDATDbkErrorHandle DbkErrorHandle)
{
    mLIBassert(DoubleBankHandle < cNbDbk);

    if (( DbkErrorHandle == cDATDbkErrorReadingBK1) || ( DbkErrorHandle == cDATDbkErrorReadingBK2))
    {
        mSetReadError(cDATDbkFirstProcessHandle + DoubleBankHandle);
    }
    else if (( DbkErrorHandle == cDATDbkErrorWritingBK1) || ( DbkErrorHandle == cDATDbkErrorWritingBK2))
    {
        mSetWriteError(cDATDbkFirstProcessHandle + DoubleBankHandle);
    }
    else
    {
        mLIBassert(0);
    }
}


/*============================================================================
  DESCRIPTION :
  
  PARAMETERS (Type,Name,Min,Max) :  none

  RETURN VALUE :  none
 
  DESIGN INFORMATION :  refer to Detailed Design Document
============================================================================*/
void DATPeeRebuildOdometerBank( tDATObkOdometerBankHandle HandleObk )
{
    mLIBassert(HandleObk < cNbObk);
    mSetRebuildFlag(cDATObkFirstProcessHandle + HandleObk);
    
    
	mPeeSetBankBrokenFlag();
    switch(HandleObk)
    {
#ifdef cDATObkHandleGroupOdo
    case cDATObkHandleGroupOdo:
      // This bank doesn't get default value
      // mSetMrcDefaultValue(GroupOdo);
      // mInitMrcBank(GroupOdo,0);
      break;  
#endif
  
    default:
    	;//
      break;
    }
}

/*============================================================================
  DESCRIPTION :
  
  PARAMETERS (Type,Name,Min,Max) :  none

  RETURN VALUE :  none
 
  DESIGN INFORMATION :  refer to Detailed Design Document
============================================================================*/
void DATPeeOdometerBankErrorIndication( tDATObkOdometerBankHandle HandleObk,
                                        tDATObkErrorHandle ObkErrorHandle )
{
    mLIBassert(HandleObk < cNbObk);
    if (ObkErrorHandle == cDATObkErrorReading)
    {
        mSetReadError(cDATObkFirstProcessHandle + HandleObk);
    }
    else if (ObkErrorHandle == cDATObkErrorWriting)
    {
        mSetWriteError(cDATObkFirstProcessHandle + HandleObk);
    }
    else
    {
        mLIBassert(0);
    }
}

/*============================================================================
  DESCRIPTION :
  
  PARAMETERS (Type,Name,Min,Max) :  none

  RETURN VALUE :  none
 
  DESIGN INFORMATION :  refer to Detailed Design Document
============================================================================*/
BOOL DATPeeOdometerBankIsGreater( tDATObkOdometerBankHandle HandleObk )
{
  BOOL result = cFalse;
  mLIBassert(HandleObk < cNbObk);

  if (HandleObk == cDATObkHandleGroupOdo)
  {               /* DATEepBuffer[0] = Checksum */
    if (((U32)  (((U32) (((U32)DATEepBuffer[2])<< ((U8)16U))) + DATEepBuffer[1U]))
        >= mSERRead(U32Bit,EEP_OdoTotal,Default) )
    {
      result = cTrue;
    }
  }
  else
  {
      mLIBassert(0);
  }
  return (result);
}


/*============================================================================
  DESCRIPTION :
  
  PARAMETERS (Type,Name,Min,Max) :  none

  RETURN VALUE :  none
 
  DESIGN INFORMATION :  refer to Detailed Design Document
============================================================================*/
void DATPeeRebuildSingleBank( tDATSbkSingleBankHandle HandleSbk )
{

    mLIBassert(HandleSbk < cNbSbk);
    mSetRebuildFlag(cDATSbkFirstProcessHandle + HandleSbk);

	mPeeSetBankBrokenFlag();
    switch(HandleSbk)
	{
    mSBKGroupsRebuild();

		default:
			break;
	}
}

/*============================================================================
  DESCRIPTION :
  
  PARAMETERS (Type,Name,Min,Max) :  none

  RETURN VALUE :  none
 
  DESIGN INFORMATION :  refer to Detailed Design Document
============================================================================*/
void DATPeeSingleBankErrorIndication( tDATSbkSingleBankHandle HandleSbk
                                      , tDATSbkErrorHandle SbkErrorHandle )
{
    mLIBassert(HandleSbk < cNbSbk);
    if (SbkErrorHandle == cDATSbkErrorReading)
    {
        mSetReadError(cDATSbkFirstProcessHandle + HandleSbk);
    }
    else if (SbkErrorHandle == cDATSbkErrorWriting)
    {
        mSetWriteError(cDATSbkFirstProcessHandle + HandleSbk);
    }
    else
    {
        mLIBassert(0);
    }
}


/*============================================================================
  DESCRIPTION : Send a signal to maintain the Starting Step if the Reading 
                of the EEPROM is not finished.
  
  PARAMETERS (Type,Name,Min,Max) :  none

  RETURN VALUE :  none
 
  DESIGN INFORMATION :  refer to Detailed Design Document
============================================================================*/
void DATPeeIsMaintainStartingStepState( void )
{
    if(mSERRead(U1Bit,IsEepProcessing,Default))
    {
        TOSWriteSignal(cTOSSignalSomebodyMaintainStartingStepState);
    }
}

/*============================================================================
  DESCRIPTION : 5 seconds after the starting step, it's recommended 
                to restore the EEP.
  
  PARAMETERS (Type,Name,Min,Max) :   none

  RETURN VALUE :   none
 
  DESIGN INFORMATION :   refer to Detailed Design Document
  ==========================================================================*/
void DATPeeRestoreBanks(void)
{
    mSERControl(Eep, Restore);
}

/*============================================================================
  DESCRIPTION : During the Starting Step, The banks must be read.
  
  PARAMETERS (Type,Name,Min,Max) :   none

  RETURN VALUE :   none
 
  DESIGN INFORMATION :   refer to Detailed Design Document
  ==========================================================================*/
void DATPeeReadAllBanks(void)
{
    mSERControl(Eep, ReadEep);
}

/*============================================================================
  DESCRIPTION : Update the necessary banks before Enter in Sleep State
  
  PARAMETERS (Type,Name,Min,Max) :   none

  RETURN VALUE :   none
 
  DESIGN INFORMATION :   refer to Detailed Design Document
  ==========================================================================*/
void DATPeeUpdateBanks(void)
{
    // This function is called when the system leave the active state.
    // Add here the Update command of the differed EEP groups
    // mSERControl(Eep, UpdateGroupName1);
    // mSERControl(Eep, UpdateGroupName2);
    // ...
    // mSERControl(Eep, UpdateGroupName3);
}


/****************************************************************************
  DESCRIPTION         : Start a 5 seconds timer

  PARAMETERS          : None
  (Type,Name,Min,Max) 

  RETURN VALUE        : None

  DESIGN INFORMATION  : Refer to Detailed Design Document

*****************************************************************************/
void DATPeeStartTimer(void)
{
    TOSStartTimer(&TimerPee);
}

/****************************************************************************
  DESCRIPTION         : Check the end of the 5 seconds timer.

  PARAMETERS          : None
  (Type,Name,Min,Max) 

  RETURN VALUE        : cTrue if the end of the 5 seconds timer is elapsed.

  DESIGN INFORMATION  : Refer to Detailed Design Document

*****************************************************************************/
BOOL DATPeeIsTimerElapsed(void)
{
    return(TOSIsTimerElapsed(&TimerPee, cTimerPeeMs / cTOSTimerTickMs));
}

/****************************************************************************
  DESCRIPTION         : Check the end of the 5 seconds timer.

  PARAMETERS          : None
  (Type,Name,Min,Max) 

  RETURN VALUE        : cTrue if the end of the 5 seconds timer is elapsed.

  DESIGN INFORMATION  : Refer to Detailed Design Document

*****************************************************************************/
void DATPeeCanRestoreBanks(void)
{
    TOSSeqActivateGraph( cTOSSeqGraphIdEepromManager );
}

/*============================================================================
  DESCRIPTION : Update the necessary banks before Enter in Sleep State
  
  PARAMETERS (Type,Name,Min,Max) :   none

  RETURN VALUE :   none
 
  DESIGN INFORMATION :   refer to Detailed Design Document
  ==========================================================================*/
void	DATPeeDTCStart(void)
{
    //U8 u8Tmp = 0U;

    //使能eep的DTC报告
    mSERWrite(U1Bit,DTCFuncEnable,eDTCFunCom_EEPFault,Default);

	TOSSeqActivateGraph( cTOSSeqGraphIdEepromDTCManager );
}
void	DATPeeDTCStop(void)
{
	TOSSeqDeactivateGraph( cTOSSeqGraphIdEepromDTCManager );
}
/*============================================================================
  DESCRIPTION : Update the necessary banks before Enter in Sleep State
  
  PARAMETERS (Type,Name,Min,Max) :   none

  RETURN VALUE :   none
 
  DESIGN INFORMATION :   refer to Detailed Design Document
  ==========================================================================*/
void	DATPeeDTCProcess(void)
{
	//mDATWriteTable(U1Bit, DTCMonitoringCycles, eDTCFunCom_EEPROM, (U1)1, Default);

	if(mPeeIsSomeBankBroken())
	{//关系到DTC，暂时注释掉
		//mPEEDTCReport(cTrue);
	}
	else
	{
		//mPEEDTCReport(cFalse);
	}

	mPeeClearBankBrokenFlag();
}

//eep读或者写出错报告DTC函数
static void DATPeeReportDTCPro(tDATDbkDoubleBankHandle BankHandle)
{
    U8 u8DTCFunComIndex = 0U;

    //eep BankHandle 转换为DTChuandle
    u8DTCFunComIndex = eDTCFunCom_EEPFault;

    if(u8DTCFunComIndex < eDTCFunCom_Count)
    {
        mSERControl(DTCOccur, u8DTCFunComIndex);

        //由于EEP发生故障不存在确认过程及故障恢复过程，故这里接着调用故障解除报告函数
        mSERControl(DTCDisappear, u8DTCFunComIndex);
    }
}




