


//#define TOS_PERF_CNT_ENABLE

//------------------------------------------------------------------------------
// Body Identification
//------------------------------------------------------------------------------
#define LAP_SRI   "LAP_SRI"

//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//
// #include <system_file_name.h>
// #include "project_file_name.h"
//------------------------------------------------------------------------------

#define cLAP_SRI_SELFINCLUDE //must be set before include LAP_SRI.h

#include "LAP_SRI.h"
#if defined(cLIBStkTosPerfCnt_Used) && defined(TOS_PERF_CNT_ENABLE)
#include "TOS_PERFCNT.H"
#endif



//------------------------------------------------------------------------------
// Local constants
//
// #define cConstantName   ((tType) ConstantValue)
//------------------------------------------------------------------------------

#define	RoutineDefineBySTK		0
#define	RoutineDefineBySMRS		1


///////////////////////////////////////////////////////////////////////////////
// CONSTANTS FOR RoutineControl
///////////////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------------------

#define cStartRoutine                                       ((U8)0x01U)
#define cStopRoutine                                        ((U8)0x02U)
#define cRequestRoutineResult                               ((U8)0x03U)


//Define ID for routine control
//当前的routine control 在应用程序中能做的只有：     add by Banfy
#define cRIDCheckProgrammingPrecondition					((U16)0xFF02UL)

//Define ID for routine control
#define cRIDWriteMemoryRoutineByAddress                     ((U16)0x0000UL)//((U16)0xF0FAUL)
#define cRIDReadMemoryRoutineByAddress                      ((U16)0x0001UL)//((U16)0xF0FBUL)
#define cRIDStandardUpdateEepRom							((U16)0x0002UL)//((U16)0xF0FCUL)
#define cRIDMotHighLowCalibration							((U16)0x0003UL)//((U16)0xF104UL)
#define cRIDSleepControl									((U16)0x0004UL)//((U16)0xF103UL)
#define cRIDEraseOdometer									((U16)0x0005UL)//((U16)0xFE00UL)
#define cRIDEraseEEPErrBank									((U16)0x0006UL)//((U16)0xFE01UL)
#define cRIDAnalogCalibration								((U16)0x0007UL)//((U16)0xFE02UL)


#if defined(cLIBStkTosPerfCnt_Used) && defined(TOS_PERF_CNT_ENABLE)
#define cRIDPerfCnt                                         ((U16)0xF0FDUL)
#endif
//------------------------------------------------------------------------------
// Length of RoutineControl request
//当前的routine control 在应用程序中能做的只有：     add by Banfy
#define cLngReqCheckProgrammingPrecondition                 ((U8)4U)

#define cLngReqStatusAndStopRequest							((U8)4)
#define cMinLngReqReadWriteMemoryRoutineByAddress			((U8)9 )
#define cLngReqStandardUpdateEepRom							((U8)5 )
#define cLngReqMotHighLowCalibration						((U8)5 )
#define cLngReqSleepControl									((U8)4 )
#define cLngReqEraseOdometer								((U8)4 )
#define cLngReqEraseEEPErrBank								((U8)4 )
#define cLngReqAnalogCalibration							((U8)4 )
#if defined(cLIBStkTosPerfCnt_Used) && defined(TOS_PERF_CNT_ENABLE)
#define cLngReqStartPerfCntData                             ((U8)4 )
#endif

#define cRequestMinLength                                   2			//kept STK defination


//------------------------------------------------------------------------------
// Length of RoutineControl response
#define cMinLngRepRoutineControl                            ((U8)5)

#if RoutineDefineBySTK
#define cLngResMotHighLowCalibration						((U8)5 )
#define cLngResSleepControl									((U8)5 )
#define cLngResEraseOdometer								((U8)5 )
#define cLngResEraseEEPErrBank								((U8)5 )
#define cLngResAnalogCalibration							((U8)5 )
#define cLngResAnalogCalibrationRslt						((U8)5 )
#endif
#if RoutineDefineBySMRS
#define cLngResCheckProgrammingPrecondition                 ((U8)5U)

#define cLngResMotHighLowCalibration						((U8)4 )
#define cLngResSleepControl									((U8)4 )
#define cLngResEraseOdometer								((U8)4 )
#define cLngResEraseEEPErrBank								((U8)4 )
#define cLngResAnalogCalibration							((U8)5 )
#define cLngResAnalogCalibrationRslt						((U8)5 )
#endif

//------------------------------------------------------------------------------
// routineEntryStatus :
#define cRoutineNotActivated                                ((U8)0x00UL)
#define cRoutineInProgress                                  ((U8)0x01UL)
#define cRoutineCompleted                                   ((U8)0x02UL)
#define cRoutineCompletedAndNotOK                           ((U8)0x03UL)
#define cRoutineCanceled                                    ((U8)0x04UL)


//routine response status      add  by  banfy
#define cProgrammingPreconditionCorrect    ((U8)0U)
#define cProgrammingPreconditionInCorrect  ((U8)1U)
//------------------------------------------------------------------------------
// List of u8RoutineStatus[]
enum{
	cRIDCheckProgrammingPreconditionHandle,
//#if 0
	cWriteMemoryRoutineHandle		,
	cReadMemoryRoutineHandle		,
	cStandardUpdateEepRomHandle		,
	cMotHighLowCalibrationHandle	,
	cSleepControlHandle				,
	cEraseOdometerHandle			,
	cEraseEEPErrBankHandle		 	,
	cAnalogCalibrationHandle		,
//#endif
	#if defined(cLIBStkTosPerfCnt_Used) && defined(TOS_PERF_CNT_ENABLE)
	cPerfCntHandle					,
	#endif
	cNbOfControledRoutines
};

#define cInvalidRoutineHandle                               255



//------------------------------------------------------------------------------
// cRIDReadMemoryRoutineByAddress and cRIDWriteMemoryRoutineByAddress
#define cDirectAccesRAM                                     ((U8)0x01UL)
#define cDirectAccesRAMImageOfEEPROM                        ((U8)0x02UL)
#define cDirectAccesFLASH_ROM                               ((U8)0x03UL)
#define cDirectAccesRegister                                ((U8)0x04UL)
#define cDirectAccesEEPROM                                  ((U8)0x05UL)
#define cDirectAccesIndirectAccess                          ((U8)0xFFUL)

///////////////////////////////////////////////////////////////////////////////
// CONSTANTS FOR ECUReset
///////////////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------------------
// Length of ECUReset request / response
#define cLngReqECUReset                                     ((U8)2UL)
#define cLngRepECUReset                                     ((U8)2UL)

#define cHardReset                                          ((U8)0x01U)
#define cKeyOffOnReset                                      ((U8)0x02U)
#define cSoftReset                                          ((U8)0x03U)

///////////////////////////////////////////////////////////////////////////////
// CONSTANTS FOR REQUEST PARAMETERS
///////////////////////////////////////////////////////////////////////////////
#define cRequestType                                        1
#define cRequestRoutineLocalID                              2
#define cRequestRoutineEntryOption                          3
#define cRequestMemoryType                                  4
#define cRequestMemoryAddressMSB                            5
#define cRequestMemoryAddress                               6
#define cRequestMemoryAddressLSB                            7
#define cRequestNumberOfBytes                               8
#define cRequestWriteRamDataOffset                          9


//-------------------------
//Mot High/Low calibration
#define	cLIDHighCalibrationForStepperMotor					((U8)(0x00))
#define	cLIDLowCalibrationForStepperMotor					((U8)(0x01))


///////////////////////////////////////////////////////////////////////////////
// CONSTANTS FOR RESPONSE PARAMETERS
///////////////////////////////////////////////////////////////////////////////
#define cResponseLocalID                                    2
#define cResponseEntryOption                                3
#define cResponseStatus                                     4
#define cResponseRamReadDataOffset                          5


///////////////////////////////////////////////////////////////////////////////
// CONSTANTS FOR CALLBACKS
///////////////////////////////////////////////////////////////////////////////
#if defined(cLIBStkDatEepDea_Used) || defined(cLIBStkDFA_Used)
  #define cNbOfServiceSteps                                 ((U8)2UL)
#else // cLIBStkDatEepDea_Used || cLIBStkDFA_Used
  #define cNbOfServiceSteps                                 ((U8)1UL)
#endif

#define cStartRoutineState                                  ((U8)0)
#define cStopRoutineState                                   ((U8)1)
#define cResultRoutineState                                 ((U8)2)
#define cNbOfRoutineStates                                  ((U8)3)
#define cNotSupportedRoutineState                           ((U8)255)

///////////////////////////////////////////////////////////////////////////////
// CONSTANTS FOR OFFSET IN BYTES
///////////////////////////////////////////////////////////////////////////////
#define c8Bits                                              8
#define c16Bits                                             16

///////////////////////////////////////////////////////////////////////////////
// CONSTANTS FOR OFFSET IN RAM OF NECFxDxSx3
///////////////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------------------
// Local macros
//
// #define mMacroName   (MacroDefinition)
//------------------------------------------------------------------------------
#define mGetRequestedResetType()                ((U8)(LAPDiaMemorizedRequest.Buffer[cRequestType] & (U8)0x7FU))
//获得请求RC类型
#define mGetRequestedRoutineControlType()       ((U8)(LAPDiaMemorizedRequest.Buffer[cRequestType] & (U8)0x7FU))

#define mGetSuppresPosRspMsgIndicationBit()     ((U8)((U8)(LAPDiaMemorizedRequest.Buffer[cRequestType] & (U8)0x80U) >> 7))
#define mGetRequestedRoutine()                  ((U16)((U16)((U16)LAPDiaMemorizedRequest.Buffer[cRequestRoutineLocalID] << 8) + \
                                                       (U16)((U16)LAPDiaMemorizedRequest.Buffer[cRequestRoutineEntryOption] << 0)))

//------------------------------------------------------------------------------
// Local types
//
// typedef Expression    tTypeName;
//------------------------------------------------------------------------------
// Routine ID
typedef U8 (*tLapSriRtnIDCallback)( void );
// Routine states
typedef U8 (*tLapSriRtnStateCallback)( void );

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
static U8  u8RoutineStatus[cNbOfControledRoutines];
static U8  u8ServHandle;

#define	cSriGuardTime		((U16)(1000))	//1s
static tTOSTimer tSriGuardTimer;


//------------------------------------------------------------------------------
// Constant local data
//
// static const tType  VariableName;
//------------------------------------------------------------------------------
static const U16 u16RoutineIdentifiers[cNbOfControledRoutines] =
{
	cRIDCheckProgrammingPrecondition,

	cRIDWriteMemoryRoutineByAddress	,
	cRIDReadMemoryRoutineByAddress  ,
	cRIDStandardUpdateEepRom		,
	cRIDMotHighLowCalibration		,
	cRIDSleepControl				,
	cRIDEraseOdometer				,
	cRIDEraseEEPErrBank				,
	cRIDAnalogCalibration
#if defined(cLIBStkTosPerfCnt_Used) && defined(TOS_PERF_CNT_ENABLE)
    , cRIDPerfCnt
#endif
};

static const U8 u8RoutineSteps[cNbOfRoutineStates] =
{
    cStartRoutine			,	//cStartRoutineState
    cStopRoutine			,	//cStopRoutineState
	cRequestRoutineResult 		//cResultRoutineState
};

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
//=============================================STK Fun declaration
static	U8		GetRoutineHandle(const U16 u16RiP);
static	U8		GetRoutineState(const U8 u8RsP);
static	U8		LAPSriRoutineStart_Cbk(void);
static	U8		LAPSriRoutineStatus_Cbk(void);
static	U8		LAPSriRoutineStop_Cbk(void);
//=============================================Code optimize fun
static	BOOL	LAPSri_EepRw_ValidCheck(U32 u32Addr,U8 u8Len);
static	void	LAPSri_RoutineStatusUpdate(U8 u8RoutineSts,U8 u8NCR);
static	void	LAPSri_ResponsePro(U8 u8LngRepStart);

//=============================================Service declaration
//Routine Start
static  U8      LAPSriCheckProgrammingPrecondition_Cbk(void );

static	U8		LAPSriWriteMemoryByAddress_Cbk(void);
static	U8		LAPSriReadMemoryByAddress_Cbk(void);
static	U8		LAPSriStandardUpdateEepRom_Cbk(void);
static	U8		LAPSriMotHighLowCalibration_Cbk(void);
static	U8		LAPSriSleepControl_Cbk(void);
static	U8		LAPSriEraseOdometer_Cbk(void);
static	U8		LAPSriEraseEEPErrBank_Cbk(void);
static	U8		LAPSriAnalogCalibration_Cbk(void);
#if defined(cLIBStkTosPerfCnt_Used) && defined(TOS_PERF_CNT_ENABLE)
static	U8		LAPSriStartPerfCnt_Cbk(void);
#endif
//Routine Result
static  U8      LAPSriRsltCheckProgrammingPrecondition_Cbk(void );

static	U8		LAPSriRsltWriteMemoryByAddress_Cbk(void);
static	U8		LAPSriRsltReadMemoryByAddress_Cbk(void);
static	U8		LAPSriRsltStandardUpdateEepRom_Cbk(void);
static	U8		LAPSriRsltMotHighLowCalibration_Cbk(void);
static	U8		LAPSriRsltSleepControl_Cbk(void);
static	U8		LAPSriRsltEraseOdometer_Cbk(void);
static	U8		LAPSriRsltEraseEEPErrBank_Cbk(void);
static	U8		LAPSriRsltAnalogCalibration_Cbk(void);
#if defined(cLIBStkTosPerfCnt_Used) && defined(TOS_PERF_CNT_ENABLE)
static	U8		LAPSriRsltStartPerfCnt_Cbk(void);
#endif
//Routine Stop
//All not support except stop LAPSriRsltStartPerfCnt_Cbk

//=============================================

static const tLapSriRtnIDCallback pStartSRIRidCallbacks[cNbOfControledRoutines] =
{
	LAPSriCheckProgrammingPrecondition_Cbk,

    LAPSriWriteMemoryByAddress_Cbk	,
    LAPSriReadMemoryByAddress_Cbk	,
    LAPSriStandardUpdateEepRom_Cbk	,
    LAPSriMotHighLowCalibration_Cbk	,
    LAPSriSleepControl_Cbk			,
    LAPSriEraseOdometer_Cbk			,
    LAPSriEraseEEPErrBank_Cbk		,
	LAPSriAnalogCalibration_Cbk
#if defined(cLIBStkTosPerfCnt_Used) && defined(TOS_PERF_CNT_ENABLE)
    ,LAPSriStartPerfCnt_Cbk
#endif
};

static const tLapSriRtnIDCallback pResultSRIRidCallbacks[cNbOfControledRoutines] =
{
	LAPSriRsltCheckProgrammingPrecondition_Cbk,

    LAPSriRsltWriteMemoryByAddress_Cbk	,
    LAPSriRsltReadMemoryByAddress_Cbk	,
    LAPSriRsltStandardUpdateEepRom_Cbk	,
    LAPSriRsltMotHighLowCalibration_Cbk	,
    LAPSriRsltSleepControl_Cbk			,
    LAPSriRsltEraseOdometer_Cbk			,
    LAPSriRsltEraseEEPErrBank_Cbk		,
	LAPSriRsltAnalogCalibration_Cbk
#if defined(cLIBStkTosPerfCnt_Used) && defined(TOS_PERF_CNT_ENABLE)
    ,LAPSriRsltStartPerfCnt_Cbk
#endif
};

static const tLapSriRtnStateCallback pSRIRtnStateCallbacks[cNbOfRoutineStates] =
{
    LAPSriRoutineStart_Cbk		,	//cStartRoutineState
    LAPSriRoutineStop_Cbk		,	//cStopRoutineState
    LAPSriRoutineStatus_Cbk			//cResultRoutineState
};



//==============================================================================
//=========================== LOCAL FUNCTIONS 0=================================
//==============================================================================
//==============================================================================
// DESCRIPTION :LAPSri_EepRw_ValidCheck
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
static	BOOL	LAPSri_RoutineSupportChkStatus(void)
{
	BOOL	bReturn = cFalse;

	switch(mGetRequestedRoutine())
	{
		case cRIDCheckProgrammingPrecondition :
			bReturn = cTrue;
			break;
#if 0
		case cRIDWriteMemoryRoutineByAddress:
			bReturn = cTrue;
			break;
		case cRIDAnalogCalibration:
			bReturn = cTrue;
			break;
#endif
		default:
			bReturn = cFalse;
			break;
	}

	return(bReturn);
}
//==============================================================================
// DESCRIPTION :LAPSri_EepRw_ValidCheck
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
static	BOOL	LAPSri_EepRw_ValidCheck(U32 u32Addr,U8 u8Len)
{
	BOOL	bValid = cFalse;

	if((u32Addr >= cDATDeaSizeEeprom)|| (u8Len > cDATDeaMaxByte)
		|| ((u32Addr + u8Len) > cDATDeaSizeEeprom))								/*check eep chip	*/
	{ /* outof the max address of eep chip */
		LAPDiaResponse.NegativeCode = cLAPDiaRequestOutOfRange;
	}
	else if((0x01 == (u32Addr & 0x01)) || (0x01 == (u8Len & 0x01)))				/*check addr&len	*/
	{
		LAPDiaResponse.NegativeCode = cLAPDiaRequestOutOfRange;
	}
	else if((u8Len > cDATDeaMaxByte)||
		(u8Len > (cLAPDiaLngBufferResponse-cResponseRamReadDataOffset)))		/*check buffer		*/
	{ /* the max read&write len is 16 */
		LAPDiaResponse.NegativeCode = cLAPDiaRequestOutOfRange;
	}
	else if(cTrue != mSERRead(U8Bit,DATDeaActionIsFinished,Default))			/*check eep module	*/
	{ /* the previous action is not finished*/
		LAPDiaResponse.NegativeCode = cLAPDiaConditionsNotCorrect;
	}
	else																		/*pass the check	*/
	{ /* pass the check */
		bValid = cTrue;
	}

	return(bValid);
}
//==============================================================================
// DESCRIPTION : LAPSri_RoutineStatusUpdate
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
static	void	LAPSri_RoutineStatusUpdate(U8 u8RoutineSts,U8 u8NCR)
{
	u8RoutineStatus[u8ServHandle] = u8RoutineSts;
	LAPDiaResponse.Buffer[cResponseLocalID] = LAPDiaMemorizedRequest.Buffer[cRequestRoutineLocalID];
	LAPDiaResponse.Buffer[cResponseEntryOption] = LAPDiaMemorizedRequest.Buffer[cRequestRoutineEntryOption];
	LAPDiaResponse.Buffer[cResponseStatus] = u8RoutineSts;
	LAPDiaResponse.NegativeCode = u8NCR;
}
//==============================================================================
// DESCRIPTION : LAPSri_ResponsePro
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
static	void	LAPSri_ResponsePro(U8 u8LngRepStart)
{
	if (LAPDiaResponse.NegativeCode != cLAPDiaServiceIsCorrect)
	{
		LAPDiaPrepareNegativeResponse(LAPDiaResponse.NegativeCode);
		TOSStopTimer(&tSriGuardTimer); // Stop guard timer
	}
	else
	{
		if(cRoutineInProgress != u8RoutineStatus[u8ServHandle])
		{
			LAPDiaPreparePositiveResponse(u8LngRepStart);
			TOSStopTimer(&tSriGuardTimer); // Stop guard timer
		}
		else if (LAPDiaActiveService.Step != cLAPDiaStartOfService)
		{
			// No positive answer yet, we wait the 2nd step
		}
		else
		{
			LAPDiaPreparePositiveResponse(u8LngRepStart);
			TOSStopTimer(&tSriGuardTimer); // Stop guard timer
		}
	}
}

//==============================================================================
//=========================== LOCAL FUNCTIONS 1=================================
//==============================================================================
//==============================================================================
// DESCRIPTION : Get routine state - start, stop, status and etc.
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
static U8 GetRoutineState(const U8 u8RsP)
{
    U8 u8State;
    BOOL bFound = cFalse;

    for (u8State = 0; (u8State < cNbOfRoutineStates) && (bFound == cFalse); u8State ++)
    {
        if (u8RoutineSteps[u8State] == u8RsP)
        {
            bFound = cTrue;
        }
    }

    if (bFound != cFalse)
    {
        u8State --;
    }
    else
    {
        u8State = cNotSupportedRoutineState;
    }

    return (u8State);
}
//==============================================================================
// DESCRIPTION : Get routine handle
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
static U8 GetRoutineHandle(const U16 u16RiP)
{
    U8 u8Handle;
    BOOL bFound = cFalse;

    for (u8Handle = 0; (u8Handle < cNbOfControledRoutines) && (bFound == cFalse); u8Handle ++)
    {
        if (u16RoutineIdentifiers[u8Handle] == u16RiP)
        {
            bFound = cTrue;
        }
    }

    if (bFound != cFalse)
    {
        u8Handle --;
    }
    else
    {
        u8Handle = cInvalidRoutineHandle;
    }

    return (u8Handle);
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
static U8 LAPSriRoutineStart_Cbk(void)
{
    U8 u8LngRepStart = 0;

    if (LAPDiaMemorizedRequest.Length < cLngReqStatusAndStopRequest)
    {
        // Do nothing
        // error code is already loaded
    }
    else
    {
        if (u8ServHandle < cNbOfControledRoutines) //(u8ServHandle != cInvalidRoutineHandle)-->(u8ServHandle < cNbOfControledRoutines)
        {
            u8LngRepStart = pStartSRIRidCallbacks[u8ServHandle]();
        }
        else
        {
            // Negative response
            // Not supported RID
            LAPDiaResponse.NegativeCode = cLAPDiaRequestOutOfRange; //routineIdentifier is not supported
        }
    }
    return (u8LngRepStart);
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
static U8 LAPSriRoutineStop_Cbk(void)
{
//Caution:
//This fun is blocked in the caller,for stop routine not used
//
	U8 u8LngRepStart = 0;

	if (cLngReqStatusAndStopRequest != LAPDiaMemorizedRequest.Length)
	{
		// Do nothing
		// error code is already loaded
	}
	else
	{
		if (u8ServHandle < cNbOfControledRoutines) //(u8ServHandle != cInvalidRoutineHandle)-->(u8ServHandle < cNbOfControledRoutines)
		{
			if (u8RoutineStatus[u8ServHandle] != cRoutineInProgress)
			{
				// Wrong sequence
				LAPDiaResponse.NegativeCode = cLAPDiaRequestSequenceError;
			}
			else
			{
				u8RoutineStatus[u8ServHandle] = cRoutineCanceled;
#if defined(cLIBStkTosPerfCnt_Used) && defined(TOS_PERF_CNT_ENABLE)
				if (u8ServHandle == cPerfCntHandle)
				{
					 mTOSPerfCntStop();
				}
#endif
				LAPDiaResponse.NegativeCode = cLAPDiaServiceIsCorrect;
			}
		}
		else
		{
			// Negative response
			// Not supported RID
			LAPDiaResponse.NegativeCode = cLAPDiaRequestOutOfRange; //routineIdentifier is not supported;
		}
	}
	return (u8LngRepStart);
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
static U8 LAPSriRoutineStatus_Cbk(void)
{
    U8 u8LngRepStart = 0;

	if(cLngReqStatusAndStopRequest != LAPDiaMemorizedRequest.Length)
	{
        // Do nothing
        // error code is already loaded
	}
    else
    {
        if (u8ServHandle < cNbOfControledRoutines) //(u8ServHandle != cInvalidRoutineHandle) --> (u8ServHandle < cNbOfControledRoutines)
        {
        	if(LAPSri_RoutineSupportChkStatus())
        	{
	            if((u8RoutineStatus[u8ServHandle] == cRoutineNotActivated))
	            {
	                // Wrong sequence
	                LAPDiaResponse.NegativeCode = cLAPDiaRequestSequenceError;
	            }
	            else
	            {
					u8LngRepStart = pResultSRIRidCallbacks[u8ServHandle]();
	            }
        	}
        	else
        	{
				LAPDiaResponse.NegativeCode = cLAPDiaSubFunctionNotSupported;
        	}
        }
        else
        {
            // Negative response
            // Not supported RID
            LAPDiaResponse.NegativeCode = cLAPDiaRequestOutOfRange; //routineIdentifier is not supported;
        }
    }

    return (u8LngRepStart);
}
//==============================================================================
//====================== LOCAL FUNCTIONS 2_1 Routine Start =====================
//==============================================================================
//==============================================================================
// DESCRIPTION :LAPSriWriteMemoryByAddress_Cbk
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
static  U8      LAPSriCheckProgrammingPrecondition_Cbk(void )
{
	U8 u8LngRepStart = 0;

	if(cLngReqSleepControl != LAPDiaMemorizedRequest.Length)
	{
		// Do nothing
		// error code is already loaded
	}
	else
	{
		LAPSri_RoutineStatusUpdate(cRoutineCompleted,cLAPDiaServiceIsCorrect);
		u8LngRepStart = cLngResCheckProgrammingPrecondition;
	}

	return(u8LngRepStart);
}

static U8 LAPSriWriteMemoryByAddress_Cbk(void)
{
	U32 u32Address;
	U8 *pu8databuf;
	U8 u8Cpt;
	U8 u8Len;

	U8 u8LngRepStart = 0;

	u32Address = ((U32)(LAPDiaMemorizedRequest.Buffer[cRequestMemoryAddressMSB]) << c16Bits)
			   + ((U32)(LAPDiaMemorizedRequest.Buffer[cRequestMemoryAddress])	 << c8Bits)
			   + ((U32)(LAPDiaMemorizedRequest.Buffer[cRequestMemoryAddressLSB]) );

	u8Len =  LAPDiaMemorizedRequest.Buffer[cRequestNumberOfBytes];
	if (LAPDiaMemorizedRequest.Length != ((U16)cMinLngReqReadWriteMemoryRoutineByAddress + (U16)u8Len))
	{
		// Do nothing
		// error code is already loaded
	}
	else
	{
		if(cDirectAccesEEPROM == LAPDiaMemorizedRequest.Buffer[cRequestMemoryType])
		{
			if(LAPSri_EepRw_ValidCheck(u32Address,u8Len))
			{
				pu8databuf = &LAPDiaMemorizedRequest.Buffer[cMinLngReqReadWriteMemoryRoutineByAddress];
				for(u8Cpt=0; u8Cpt < u8Len; u8Cpt++)									/* Set data    */
				{
					mSERWriteBuffer(DATDeaBufferU8Bit,u8Cpt,pu8databuf[u8Cpt], Default);
				}
				mSERWrite(	U16Bit, DATDeaAddressInByte, (U16)u32Address, Default); 	/* Set address	*/
				mSERWrite(	U8Bit, DATDeaSizeBufferInByte, u8Len,Default);				/* Set size 	*/
				mSERControl(DATDea, StartWriteEepromByAddress); 						/* Start action */

#if(RoutineDefineBySTK)
				//LAPDiaActiveService.Step = cLAPDiaFirstStep;
				LAPSri_RoutineStatusUpdate(cRoutineInProgress,cLAPDiaServiceIsCorrect);
				u8LngRepStart = cMinLngRepRoutineControl;
#endif
#if(RoutineDefineBySMRS)
				//LAPDiaActiveService.Step = cLAPDiaFirstStep;
				LAPSri_RoutineStatusUpdate(cRoutineInProgress,cLAPDiaServiceIsCorrect);
				u8LngRepStart = cMinLngRepRoutineControl;
#endif
			}
		}
		else
		{
			LAPDiaResponse.NegativeCode = cLAPDiaRequestOutOfRange;
		}
	}

	return (u8LngRepStart);
}
//==============================================================================
// DESCRIPTION :LAPSriReadMemoryByAddress_Cbk
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
static U8 LAPSriReadMemoryByAddress_Cbk(void)
{
	U32 u32Address;
	U8	u8Len;
	U8	u8LngRepStart = 0;

	u32Address = ((U32)(LAPDiaMemorizedRequest.Buffer[cRequestMemoryAddressMSB]) << c16Bits)
			   + ((U32)(LAPDiaMemorizedRequest.Buffer[cRequestMemoryAddress])	 << c8Bits)
			   + ((U32)(LAPDiaMemorizedRequest.Buffer[cRequestMemoryAddressLSB]) );
	u8Len = LAPDiaMemorizedRequest.Buffer[cRequestNumberOfBytes];

	if (LAPDiaMemorizedRequest.Length != cMinLngReqReadWriteMemoryRoutineByAddress)
	{
		// Do nothing
		// error code is already loaded
	}
	else
	{
		if(cDirectAccesEEPROM == LAPDiaMemorizedRequest.Buffer[cRequestMemoryType])
		{
			if(LAPSri_EepRw_ValidCheck(u32Address,u8Len))
			{
				mSERWrite( U16Bit, DATDeaAddressInByte, (U16)u32Address,  Default);
				mSERWrite( U8Bit, DATDeaSizeBufferInByte,u8Len,Default);
				mSERControl(DATDea, StartReadEepromByAddress);


#if(RoutineDefineBySTK)
				LAPDiaActiveService.Step = cLAPDiaFirstStep;
				LAPSri_RoutineStatusUpdate(cRoutineInProgress,cLAPDiaServiceIsCorrect);
				u8LngRepStart = cMinLngRepRoutineControl;
#endif
#if(RoutineDefineBySMRS)
				LAPDiaActiveService.Step = cLAPDiaFirstStep;
				LAPSri_RoutineStatusUpdate(cRoutineInProgress,cLAPDiaServiceIsCorrect);
				u8LngRepStart = cMinLngRepRoutineControl;
#endif
			}
			else
			{
				/* no statement,error code is already loaded in if condition check */
			}
		}
		else
		{
			LAPDiaResponse.NegativeCode = cLAPDiaSubFunctionNotSupported;
		}
	}

	return (u8LngRepStart);
}
//==============================================================================
// DESCRIPTION :LAPSriReadMemoryByAddress_Cbk
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
static U8 LAPSriStandardUpdateEepRom_Cbk(void)
{
	U8	u8LngRepStart = 0;

	if(cLngReqStandardUpdateEepRom != LAPDiaMemorizedRequest.Length)
	{
		// Do nothing
		// error code is already loaded
	}
	else
	{
		LAPSri_RoutineStatusUpdate(cRoutineCompleted,cLAPDiaServiceIsCorrect);
		u8LngRepStart = cMinLngRepRoutineControl;
	}

	return(u8LngRepStart);
}
//==============================================================================
// DESCRIPTION : LAPSriMotHighLowCalibration_Cbk
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
static U8 LAPSriMotHighLowCalibration_Cbk(void)
{
    U8 u8LngRepStart = 0;

    if (LAPDiaMemorizedRequest.Length != cLngReqMotHighLowCalibration )
    {
        // Do nothing
        // error code is already loaded
    }
    else
    {
		switch(LAPDiaMemorizedRequest.Buffer[4])
		{
			case cLIDHighCalibrationForStepperMotor: //High calibration
				//mSERControl(MotDiag,Init);
				//mSERWrite(U8Bit, DATMotRequestDiagCalibration,cLDBMotHighCalibrationCode,Default);
#if(RoutineDefineBySTK)
				LAPSri_RoutineStatusUpdate(cRoutineInProgress,cLAPDiaServiceIsCorrect);
				u8LngRepStart = cLngResMotHighLowCalibration;
#endif
#if(RoutineDefineBySMRS)
				LAPSri_RoutineStatusUpdate(cRoutineCompleted,cLAPDiaServiceIsCorrect);
				u8LngRepStart = cLngResMotHighLowCalibration;
#endif
				break;
			case cLIDLowCalibrationForStepperMotor: //Low calibration
				//mSERControl(MotDiag,Init);
				//mSERWrite(U8Bit, DATMotRequestDiagCalibration,cLDBMotLowCalibrationCode,Default);
#if(RoutineDefineBySTK)
				LAPSri_RoutineStatusUpdate(cRoutineInProgress,cLAPDiaServiceIsCorrect);
				u8LngRepStart = cLngResMotHighLowCalibration;
#endif
#if(RoutineDefineBySMRS)
				LAPSri_RoutineStatusUpdate(cRoutineCompleted,cLAPDiaServiceIsCorrect);
				u8LngRepStart = cLngResMotHighLowCalibration;
#endif
				break;
			default:
				LAPDiaResponse.NegativeCode = cLAPDiaRequestOutOfRange;
				break;
		}

    }
    return(u8LngRepStart);
}
//==============================================================================
// DESCRIPTION : LAPSriSleepControl_Cbk
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
static U8 LAPSriSleepControl_Cbk(void)
{
    U8 u8LngRepStart = 0;

	if(cLngReqSleepControl != LAPDiaMemorizedRequest.Length)
	{
		// Do nothing
		// error code is already loaded
	}
	else
	{
	    //è?éè±??ì?ù??è?DY??×′ì?
		//mSERWrite(U1Bit, ICGoToSleep, cTrue, Default);
		LAPSri_RoutineStatusUpdate(cRoutineCompleted,cLAPDiaServiceIsCorrect);
		u8LngRepStart = cLngResSleepControl;
	}

	return(u8LngRepStart);
}
//==============================================================================
// DESCRIPTION : LAPSriEraseOdometer_Cbk
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
static U8 LAPSriEraseOdometer_Cbk(void)
{
	U8 u8LngRepStart = 0;

	if (cLngReqEraseOdometer != LAPDiaMemorizedRequest.Length)
	{
		// Do nothing
		// error code is already loaded
	}
	else
	{
		//===============================Clear Odo Information
		//mSERControl(OdoTotal,Clear);
		//mSERControl(OdoTrip,Clear);
		//mSERWrite(U8Bit, EEP_Odo_Reset_Counter,mSERRead(U8Bit,EEP_Odo_Reset_CounterDefaultValue,Default), Default);
		//===============================Clear AFC Information
		#if(cSW_Ver_AT)
		TOSSendControl(cTOSControlResetFactorySetting);
		#endif
		//===============================Clear Reset Information
		DATPeeRebuildSingleBank(cDATSbkHandleGroupReset);
		mSERControl(Eep,UpDateEepGroupGroupReset);




#if(RoutineDefineBySTK)
		//LAPDiaActiveService.Step = cLAPDiaFirstStep;
		LAPSri_RoutineStatusUpdate(cRoutineInProgress,cLAPDiaServiceIsCorrect);
		u8LngRepStart = cLngResEraseOdometer;
#endif
#if(RoutineDefineBySMRS)
		//LAPDiaActiveService.Step = cLAPDiaFirstStep;
		LAPSri_RoutineStatusUpdate(cRoutineCompleted,cLAPDiaServiceIsCorrect);
		u8LngRepStart = cLngResEraseOdometer;
#endif
	}

	return (u8LngRepStart);
}
//==============================================================================
// DESCRIPTION : LAPSriEraseEEPErrBank_Cbk
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
static U8 LAPSriEraseEEPErrBank_Cbk(void)
{
	U8 u8LngRepStart = 0;

	if (cLngReqEraseEEPErrBank != LAPDiaMemorizedRequest.Length)
	{
		// Do nothing
		// error code is already loaded
	}
	else
	{
		mDATPeeResetEEPErrorTable();
		mSERControl(Eep,UpDateEepGroupErrorGroup);

#if(RoutineDefineBySTK)
		//LAPDiaActiveService.Step = cLAPDiaFirstStep;
		LAPSri_RoutineStatusUpdate(cRoutineInProgress,cLAPDiaServiceIsCorrect);
		u8LngRepStart = cLngResEraseEEPErrBank;
#endif
#if(RoutineDefineBySMRS)
		//LAPDiaActiveService.Step = cLAPDiaFirstStep;
		LAPSri_RoutineStatusUpdate(cRoutineCompleted,cLAPDiaServiceIsCorrect);
		u8LngRepStart = cLngResEraseEEPErrBank;
#endif
	}

	return (u8LngRepStart);
}
//==============================================================================
// DESCRIPTION : LAPSriAnalogCalibration_Cbk
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
static U8 LAPSriAnalogCalibration_Cbk(void)
{
	U8 u8LngRepStart = 0;

	if (cLngReqAnalogCalibration != LAPDiaMemorizedRequest.Length)
	{
		// Do nothing
		// error code is already loaded
	}
	else
	{
		//TOSSendControl(cTOSControlLAPCompLaunchAnalogCalibration);

#if(RoutineDefineBySTK)
		//LAPDiaActiveService.Step = cLAPDiaFirstStep;
		LAPSri_RoutineStatusUpdate(cRoutineInProgress,cLAPDiaServiceIsCorrect);
		u8LngRepStart = cLngResAnalogCalibration;
#endif
#if(RoutineDefineBySMRS)
		//LAPDiaActiveService.Step = cLAPDiaFirstStep; //caution:must not set to 1st step,see SMRS
		LAPSri_RoutineStatusUpdate(cRoutineInProgress,cLAPDiaServiceIsCorrect);
		u8LngRepStart = cLngResAnalogCalibration;
#endif
	}

	return (u8LngRepStart);
}
#if defined(cLIBStkTosPerfCnt_Used) && defined(TOS_PERF_CNT_ENABLE)
//==============================================================================
// DESCRIPTION :
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
static U8 LAPSriStartPerfCnt_Cbk(void)
{
    U8 u8LngRepStart = 0;

	if(cLngReqStartPerfCntData != LAPDiaMemorizedRequest.Length)
	{
		// Do nothing
		// error code is already loaded
	}
	else
	{
        if( mTOSPerfCntIsWorking()==cFalse )
        {
            mTOSPerfCntStart();
            u8RoutineStatus[u8ServHandle] = cRoutineInProgress;
            LAPDiaResponse.Buffer[cResponseLocalID] = LAPDiaMemorizedRequest.Buffer[cRequestRoutineLocalID];
            LAPDiaResponse.Buffer[cResponseEntryOption] = LAPDiaMemorizedRequest.Buffer[cRequestRoutineEntryOption];
            LAPDiaResponse.Buffer[cResponseStatus] = cRoutineInProgress;
            LAPDiaResponse.NegativeCode = cLAPDiaServiceIsCorrect;
            u8LngRepStart = cMinLngRepRoutineControl;
        }
        else
        {
            LAPDiaResponse.NegativeCode = cLAPDiaConditionsNotCorrect;
        }

	}

    return (u8LngRepStart);
}
#endif


//==============================================================================
//====================== LOCAL FUNCTIONS 2_2 Routine Sts =======================
//==============================================================================
//==============================================================================
// DESCRIPTION : routine status setting,
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
static  U8      LAPSriRsltCheckProgrammingPrecondition_Cbk(void )
{
	U8 u8LngRepStart;
	//TODO
	if(1)//if((1U == (mSERRead(U8Bit, Sig_IOU_IN30, Default)))    )
	{
		//当前所有的条件都满足，返回为正确
		LAPSri_RoutineStatusUpdate(cProgrammingPreconditionCorrect,cLAPDiaServiceIsCorrect);
		u8LngRepStart = cMinLngRepRoutineControl;
	}
	else
	{
		//某一条件不满足，则返回错误
		//但是当前服务以正确完成
		LAPSri_RoutineStatusUpdate(cProgrammingPreconditionInCorrect,cLAPDiaServiceIsCorrect);
		u8LngRepStart = cMinLngRepRoutineControl;
	}
	return(u8LngRepStart);
}

static	U8	LAPSriRsltWriteMemoryByAddress_Cbk(void)
{
	//Caution:
	//this fun has two entrance
	//1 is sts request,the length is protected in caller
	//another is start request,this condition,no need to check legth

	U8 u8LngRepStart;

	if(cTrue != mSERRead(U8Bit,DATDeaActionIsFinished,Default)) /* action is not finished */
	{
		/* no statement *//* waiting for the end of EEPROM access */
		LAPSri_RoutineStatusUpdate(cRoutineInProgress,cLAPDiaServiceIsCorrect);
		u8LngRepStart = cMinLngRepRoutineControl;
	}
	else if(cTrue == mSERRead(U8Bit,DATDeaWriteIsOk,Default)) /* action is finished and sucess */
	{
		LAPSri_RoutineStatusUpdate(cRoutineCompleted,cLAPDiaServiceIsCorrect);
		u8LngRepStart = cMinLngRepRoutineControl;
	}
	else /* action is finished but fail */
	{
		LAPSri_RoutineStatusUpdate(cRoutineCompletedAndNotOK,cLAPDiaGeneralProgrammingFailure);
		u8LngRepStart = 0;
	}

	return(u8LngRepStart);
}
//==============================================================================
// DESCRIPTION : routine status setting,
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
static	U8	LAPSriRsltReadMemoryByAddress_Cbk(void)
{
	//Caution:
	//this fun has two entrance
	//1 is sts request,the length is protected in caller
	//another is start request,this condition,no need to check legth

	U8	u8Cpt;
	U8	u8LngRepStart;

	if(cTrue != mSERRead(U8Bit,DATDeaActionIsFinished,Default)) /* action is not finished */
	{
		/* no statement *//* waiting for the end of EEPROM access */
		LAPSri_RoutineStatusUpdate(cRoutineInProgress,cLAPDiaServiceIsCorrect);
		u8LngRepStart = cMinLngRepRoutineControl;
	}
	else if(cTrue == mSERRead(U8Bit,DATDeaReadIsOk,Default)) /* action is finished and sucess */
	{
		for (u8Cpt=0; u8Cpt < LAPDiaMemorizedRequest.Buffer[cRequestNumberOfBytes]; u8Cpt++)
		{
			LAPDiaResponse.Buffer[cMinLngRepRoutineControl + u8Cpt] = mSERReadBuffer(DATDeaBufferU8Bit, u8Cpt, Default);
		}
		LAPSri_RoutineStatusUpdate(cRoutineCompleted,cLAPDiaServiceIsCorrect);
		u8LngRepStart = (cMinLngRepRoutineControl + u8Cpt);
	}
	else /* action is finished but fail */
	{
		LAPSri_RoutineStatusUpdate(cRoutineCompletedAndNotOK,cLAPDiaGeneralProgrammingFailure);
		u8LngRepStart = 0;
	}

	return(u8LngRepStart);
}
//==============================================================================
// DESCRIPTION : routine status setting,
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
static	U8	LAPSriRsltStandardUpdateEepRom_Cbk(void)
{
	U8	u8LngRepStart;

	LAPSri_RoutineStatusUpdate(cRoutineCompleted,cLAPDiaServiceIsCorrect);
	u8LngRepStart = 0;

	return(u8LngRepStart);
}
//==============================================================================
// DESCRIPTION : routine status setting,
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
static	U8	LAPSriRsltMotHighLowCalibration_Cbk(void)
{
	U8	u8LngRepStart;

#if(RoutineDefineBySTK)
	if(mSERRead(U1Bit,DATMotDiagCalibrationProcessing,Default))
	{
		LAPSri_RoutineStatusUpdate(cRoutineInProgress,cLAPDiaServiceIsCorrect);
		u8LngRepStart = cMinLngRepRoutineControl;
	}
	else
	{
		LAPSri_RoutineStatusUpdate(cRoutineCompleted,cLAPDiaServiceIsCorrect);
		u8LngRepStart = cMinLngRepRoutineControl;
	}
#endif
#if(RoutineDefineBySMRS)
	//Not support this fun
	LAPDiaResponse.NegativeCode = cLAPDiaSubFunctionNotSupported;
	u8LngRepStart = 0;
#endif

	return(u8LngRepStart);
}
//==============================================================================
// DESCRIPTION : routine status setting,
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
static	U8	LAPSriRsltSleepControl_Cbk(void)
{
	//Start fun must set routine to completed
	//Not support this fun
	LAPDiaResponse.NegativeCode = cLAPDiaSubFunctionNotSupported;

	return(0);
}
//==============================================================================
// DESCRIPTION : routine status setting,
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
static U8 LAPSriRsltEraseOdometer_Cbk(void)
{
	//Caution:
	//this fun has two entrance
	//1 is sts request,the length is protected in caller
	//another is start request,this condition,no need to check legth
	//must set to processing and 1st step

	U8 u8LngRepStart;

#if(RoutineDefineBySTK)
	if( mSERRead(U1Bit,IsEepGroupGroupOdoProcessing,Default) ||
		mSERRead(U1Bit,IsEepGroupGroupOdoParametersProcessing,Default))
	{
		if(TOSIsTimerElapsed(&tSriGuardTimer,mTOSConvMsInTimerTick(cSriGuardTime))) /*guard timer elpased,no need to wait*/
		{
			LAPSri_RoutineStatusUpdate(cRoutineCompletedAndNotOK,cLAPDiaServiceIsCorrect);
			u8LngRepStart = cLngResEraseOdometer;
		}
		else /*continue to wait*/
		{
			LAPSri_RoutineStatusUpdate(cRoutineInProgress,cLAPDiaServiceIsCorrect);
			u8LngRepStart = cLngResEraseOdometer;
		}
	}
	else
	{
		if( mSERRead(U1Bit,IsEepGroupGroupOdoWriteOk,Default)&&
			mSERRead(U1Bit,IsEepGroupGroupOdoParametersWriteOk,Default))
		{
			LAPSri_RoutineStatusUpdate(cRoutineCompleted,cLAPDiaServiceIsCorrect);
			u8LngRepStart = cLngResEraseOdometer;
		}
		else
		{
			LAPSri_RoutineStatusUpdate(cRoutineCompletedAndNotOK,cLAPDiaServiceIsCorrect);
			u8LngRepStart = cLngResEraseOdometer;
		}
	}
#endif
#if(RoutineDefineBySMRS)
	//Not support this fun
	LAPDiaResponse.NegativeCode = cLAPDiaSubFunctionNotSupported;
	u8LngRepStart = 0;
#endif

	return(u8LngRepStart);
}
//==============================================================================
// DESCRIPTION : routine status setting,
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
static U8 LAPSriRsltEraseEEPErrBank_Cbk(void)
{
	//Caution:
	//this fun has two entrance
	//1 is sts request,the length is protected in caller
	//another is start request,this condition,no need to check legth
	//must set to processing and 1st step

	U8 u8LngRepStart;

#if(RoutineDefineBySTK)
	if(mSERRead(U1Bit,IsEepGroupErrorGroupProcessing,Default))
	{
		if(TOSIsTimerElapsed(&tSriGuardTimer,mTOSConvMsInTimerTick(cSriGuardTime))) /*guard timer elpased,no need to wait*/
		{
			LAPSri_RoutineStatusUpdate(cRoutineCompletedAndNotOK,cLAPDiaServiceIsCorrect);
			u8LngRepStart = cLngResEraseEEPErrBank;
		}
		else /*continue to wait*/
		{
			LAPSri_RoutineStatusUpdate(cRoutineInProgress,cLAPDiaServiceIsCorrect);
			u8LngRepStart = cLngResEraseEEPErrBank;
		}
	}
	else
	{
		if(mSERRead(U1Bit,IsEepGroupErrorGroupWriteOk,Default))
		{
			LAPSri_RoutineStatusUpdate(cRoutineCompleted,cLAPDiaServiceIsCorrect);
			u8LngRepStart = cLngResEraseEEPErrBank;
		}
		else
		{
			LAPSri_RoutineStatusUpdate(cRoutineCompletedAndNotOK,cLAPDiaServiceIsCorrect);
			u8LngRepStart = cLngResEraseEEPErrBank;
		}
	}
#endif
#if(RoutineDefineBySMRS)
	//Not support this fun
	LAPDiaResponse.NegativeCode = cLAPDiaSubFunctionNotSupported;
	u8LngRepStart = 0;
#endif

	return(u8LngRepStart);
}
//==============================================================================
// DESCRIPTION : routine status setting,
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
static U8 LAPSriRsltAnalogCalibration_Cbk(void)
{
#if 0
	//Caution:
	//this fun has two entrance
	//1 is sts request,the length is protected in caller
	//another is start request,this condition,no need to check legth
	//must set to complete(un really complete,but have to done,see SMRS)

	U8 u8LngRepStart = 0;

	switch(mSERRead(U8Bit,AnalogCalibrationSts,Default))
	{
		case cAnalogCalibrationInProgress:
			LAPSri_RoutineStatusUpdate(cRoutineInProgress, cLAPDiaServiceIsCorrect);
			u8LngRepStart = cLngResAnalogCalibrationRslt;
			break;
		case cAnalogCalibrationCompleted:
			LAPSri_RoutineStatusUpdate(cRoutineCompleted, cLAPDiaServiceIsCorrect);
			u8LngRepStart = cLngResAnalogCalibrationRslt;
			break;
		case cAnalogCalibrationCompletedAndNotOK:
			LAPSri_RoutineStatusUpdate(cRoutineCompletedAndNotOK, cLAPDiaServiceIsCorrect);
			u8LngRepStart = cLngResAnalogCalibrationRslt;
			break;
		default:
			LAPDiaResponse.NegativeCode = cLAPDiaRequestSequenceError;
			break;
	}

	return(u8LngRepStart);
#endif
	return 0;
}
//==============================================================================
// DESCRIPTION : routine status setting,
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
#if defined(cLIBStkTosPerfCnt_Used) && defined(TOS_PERF_CNT_ENABLE)
static U8 LAPSriRsltStartPerfCnt_Cbk(void)
{
	//Start fun must set routine to completed
	//Not support this fun
	LAPDiaResponse.NegativeCode = cLAPDiaConditionsNotCorrect;

	return(0);
}
#endif




//==============================================================================
//=========================== EXPORTED FUNCTIONS ===============================
//==============================================================================

//==============================================================================
// DESCRIPTION : LAPSriRoutineControl
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
#ifdef cRoutineControl_Used
//当前routine control 仅支持扩展会话和编程会话
void LAPSriRoutineControl(void)
{
	U8 u8LngRepStart;
	U8 u8RtnState;
	if(LAPDiaIsPhysicalAddress()==cFalse)
	{
		LAPDiaResponse.NegativeCode = cLAPDiaServiceNotSupported;
		LAPDiaPrepareNegativeResponse( LAPDiaResponse.NegativeCode);
	}
	else
	{
		// By default, we define :
		LAPDiaResponse.NegativeCode = cLAPDiaIncorrectMessageLengthOrInvalidFormat;

		u8ServHandle = GetRoutineHandle(mGetRequestedRoutine());


		if (LAPDiaActiveService.Step == cLAPDiaStartOfService)
		{
			u8LngRepStart = 0;
			TOSStartTimer(&tSriGuardTimer); // Start guard timer

			if (LAPDiaMemorizedRequest.Length < cRequestMinLength)
			{
				// Do nothing
				// error code is already loaded
			}
			else
			{
				u8RtnState = GetRoutineState(mGetRequestedRoutineControlType());

				if((u8RtnState < cNbOfRoutineStates) && (cStopRoutineState != u8RtnState)) //(u8RtnState != cNotSupportedRoutineState) --> (u8RtnState < cNbOfRoutineStates)
				{
					// Switch between requested routines
					u8LngRepStart = pSRIRtnStateCallbacks[u8RtnState]();
				}
				else
				{
					// Sub function not supported
					LAPDiaResponse.NegativeCode = cLAPDiaSubFunctionNotSupported;
				}
			}
			LAPSri_ResponsePro(u8LngRepStart);
		}
		else
		{
			//Other request treatments called by the graph
			if(u8ServHandle < cNbOfControledRoutines)
			{
				u8LngRepStart = pResultSRIRidCallbacks[u8ServHandle]();
				LAPSri_ResponsePro(u8LngRepStart);
			}
			else
			{
				LAPDiaResponse.NegativeCode = cLAPDiaRequestOutOfRange;
				LAPDiaPrepareNegativeResponse( LAPDiaResponse.NegativeCode);
			}
		}
	}
}
#endif //cRoutineControl_Used
//==============================================================================
// DESCRIPTION : LAPSriEcuReset
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
#ifdef cEcuReset_Used
void LAPSriEcuReset(void)
{
#ifndef I_ENV_DIA_H /*UTEST*/
	mLDBTrace("DIAG : EcuReset");
#endif

	// By default, we define :
	LAPDiaResponse.NegativeCode = cLAPDiaIncorrectMessageLengthOrInvalidFormat;

	if(cLngReqECUReset != LAPDiaMemorizedRequest.Length)
	{
		// Bad size. Already done
	}
	else
	{
		if (mGetRequestedResetType() == cSoftReset)
		{
			if(mSERRead(U1Bit,IsDiagBatNormal,Default))
			{
				if (mGetSuppresPosRspMsgIndicationBit() == cFalse)
				{
					if((pLAPDiaActiveSession->SessionIdentifier == cLAPDiaIdEXTDSSession) &&
						(LAPSeaIsServiceUnLocked() == cFalse)	)
					{
						//在此处验证安全访问，如果在安全访问下，则可以进行CPU复位，否则
						LAPDiaResponse.NegativeCode = cLAPDiaSecurityAccessDenied;
					}
					else
					{
						if (mSERRead(U1Bit, IsTestMode, Default) == 0U)			/*TODO: 诊断测试模式不响应复位*/
						{
							TOSWriteSignal(cTOSSignalResetAfterDiagMessageSent);
						}

						// Reset allowed
						LAPDiaResponse.NegativeCode = cLAPDiaServiceIsCorrect;
					}
				}
				else
				{
					if (mSERRead(U1Bit,IsTestMode, Default) == 0U)	/*TODO: 诊断测试模式不响应复位*/
					{
						mSERControl(Cpu, Reset);
					}
					LAPDiaResponse.NegativeCode = cLAPDiaServiceIsCorrect;
				}
			}
			else
			{
				LAPDiaResponse.NegativeCode = cLAPDiaConditionsNotCorrect;
			}
		}
		else
		{
			// Out of range
			LAPDiaResponse.NegativeCode = cLAPDiaSubFunctionNotSupported;
		}
	}


	if (LAPDiaResponse.NegativeCode != cLAPDiaServiceIsCorrect)
	{
		LAPDiaPrepareNegativeResponse(LAPDiaResponse.NegativeCode);
	}
	else
	{
		if (mGetSuppresPosRspMsgIndicationBit() == cFalse)
		{
			LAPDiaPreparePositiveResponse(cLngRepECUReset);
		}
	}
}
#endif //cEcuReset_Used
//==============================================================================
// DESCRIPTION : LAPSriEcuResetCallBackDiagFrameSending
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void LAPSriEcuResetCallBackDiagFrameSending(void)
{
#ifdef cEcuReset_Used
    BOOL bSignal;

    bSignal = TOSReadSignal(cTOSSignalResetAfterDiagMessageSent);
    if (bSignal != cFalse)
    {
        mSERControl(Cpu, Reset);
    }

#endif //cEcuReset_Used
}
//==============================================================================
// DESCRIPTION : LAPSriOpenSession
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void LAPSriOpenSession (void)
{
    //QACJ 2201: adimovvl: Standard using of LIB functions
    mLIBmemset(&u8RoutineStatus[0], cRoutineNotActivated, cNbOfControledRoutines);

	TOSStopTimer(&tSriGuardTimer); 	// Stop the timer
}
//==============================================================================
// DESCRIPTION : LAPSriCloseSession
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void LAPSriCloseSession (void)
{
    // example
    //if (pLAPDiaActiveSession->SessionIdentifier != cLAPDiaIdDefaultSession)
    //{
    //}
}



//恢复出厂设置，用于界面操作，恢复部分EEP数据
void ResetFactorySet(void)
{
	//数组类型变量恢复默认设置
	///恢复用户设置的位置
	//mSERPeeResetEEP_UserPrefSet();
	//恢复Wifi密码
	//mSERPeeResetEEP_WIFIPwd();
}


//恢复产线设置
//这里设置的内容要远远大于恢复出厂设置内容
void ResetAsmblLineSet(void)
{

}


