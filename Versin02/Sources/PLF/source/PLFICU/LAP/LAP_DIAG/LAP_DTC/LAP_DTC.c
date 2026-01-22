
//------------------------------------------------------------------------------
// Body Identification
//------------------------------------------------------------------------------
#define LAP_DTC   "LAP_DTC"


//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//
// #include <system_file_name.h>
// #include "project_file_name.h"
//------------------------------------------------------------------------------
#define cLAP_DTC_SELFINCLUDE
#include "LAP_DTC.h"

//------------------------------------------------------------------------------
// Local constants
//
// #define cConstantName   ((tType) ConstantValue)
//------------------------------------------------------------------------------
/////////////////////////////////////////////////////////////
// Constants for this component
/////////////////////////////////////////////////////////////
#define cAllFailureGroups                               ((U32)0xFFFFFFUL)
#define cU32BodyGroup                                      ((U32)0x000103UL)


/////////////////////////////////////////////////////////////
// Constants for ReadDTCInformation
/////////////////////////////////////////////////////////////
#define cReportNumberOfDTCByStatusMask                  ((U8)0x01U)
#define cReportDTCByStatusMask                          ((U8)0x02U)
#define cReportSupportedDTCs                               ((U8)0X0AU)
#define cReportDTCExtendedDataRecordsByDTCNumber           ((U8)0X06U)

//------------------------------------------------------------------------------
// Length of ReadDTCInformation request / response
#define cLngReqReadDTCInformation                          ((U8)3UL)
#define cLngRepReadDTCInformation                          ((U8)6UL)
#define cLngReqReadSupportedDTC                            ((U8)2UL)
#define cLngReqReadEDRNbyDTCNumber                  ((U8)6UL)//DTC拓展数据


/////////////////////////////////////////////////////////////
// Constants for ClearDiagnosticInformation
/////////////////////////////////////////////////////////////

//------------------------------------------------------------------------------
// Length of ClearDiagnosticInformation request / response
#define cLngReqClearDiagnosticInformation               ((U8)4UL)
#define cLngRepClearDiagnosticInformation               ((U8)1UL)


/////////////////////////////////////////////////////////////
// Constants for ControlDTCSetting
/////////////////////////////////////////////////////////////

#define cLocalEnableDTCStoring  ((U8)0x01U)
#define cLocalDisableDTCStoring ((U8)0x02U)

#define cLngReqControlDTCSetting   ((U8)2)
#define cLngRepControlDTCSetting   ((U8)2)

//DTC format define
#define cISO14229_1DTCFormat        ((U8)1)
#define cISO15031_6DTCFormat        ((U8)0)
#define cSAEJ1939_73DTCFormat       ((U8)2)
#define cISO11992_4DTCFormat        ((U8)3)

//------------------------------------------------------------------------------
// Local macros
//
// #define mMacroName   (MacroDefinition)
//------------------------------------------------------------------------------
#define mGetDTCSettingType() ((U8)(LAPDiaMemorizedRequest.Buffer[(U8)1] & (U8)0x7FU))
#define mStopDTCRecroding() mSERWrite(U1Bit,ControlDTCSetting,cTrue,Default)
#define mStartDTCRecroding() mSERWrite(U1Bit,ControlDTCSetting,cFalse,Default)

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

//==============================================================================
//=========================== LOCAL FUNCTIONS ==================================
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
// static type FunctionName(...)


//==============================================================================
//=========================== EXPORTED FUNCTIONS ===============================
//==============================================================================

//==============================================================================
// DESCRIPTION : LAPDtcReadDTCInformation
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : Read Status Of DTC Service
//==============================================================================
#ifdef cReadDTCInformation_Used
void LAPDtcReadDTCInformation(void)
{  
	sDTCQuery tmpDTCQuery; 
	U16  u16QueryDTCCount;
	U8 u8LenghtL;

	tmpDTCQuery.pu8QueryBuffer=&(LAPDiaResponse.Buffer[2]);//注意：buffer[2]->buffer[0]
	tmpDTCQuery.u8QueryBufferSize=(U8)(cLAPDiaLngBufferResponse-2);
	
    if (mLAPDiaReadLengthOfRequest() < 2)
    {
        // Wrong length
        // GEN-VHL-ST-UDS.1120(0)
        LAPDiaPrepareNegativeResponse(cLAPDiaIncorrectMessageLengthOrInvalidFormat);
    }
    else
    {
        switch (mGetDTCSettingType())
        {

			case cReportNumberOfDTCByStatusMask:
			{
				if (LAPDiaMemorizedRequest.Length == cLngReqReadDTCInformation)
				{
					tmpDTCQuery.u8QueryType=eDTCRequestByStatusMask;
					//specify the query mask  请求掩码DTCStatusMask，	诊断仪请求"查询哪些状态的DTC"
					tmpDTCQuery.u8QueryMask=LAPDiaMemorizedRequest.Buffer[2] & cDTCSAM;;	
					
					mSERControl(DTCInfoRead,tmpDTCQuery);

					//check the result
					if((mSERRead(U8Bit,DTCQueryResult,Default)!=cDATDtcQueryFailed) &&
					   (mSERRead(U8Bit,DTCQueryResult,Default)!=cDATDtcQueryNotCorrect))
					{
						u16QueryDTCCount=mSERRead(U16Bit,QueryDTCCount,Default);
						//LAPDiaResponse.Buffer[2]  is the DTCStatusAvailabilityMask 
						//DTCFormatIdentifier
                    	LAPDiaResponse.Buffer[3] = cSAEJ1939_73DTCFormat;//221使用SAE_J1939-73_DTCFormat
                    	LAPDiaResponse.Buffer[4] = (U8)(u16QueryDTCCount >> 8);
                    	LAPDiaResponse.Buffer[5] = (U8)(u16QueryDTCCount & (U8)0xFFU);
						
						LAPDiaPreparePositiveResponse(cLngRepReadDTCInformation);
					}
					else
					{
						LAPDiaPrepareNegativeResponse(cLAPDiaNoResponseFromSubnetComponent);
					}
				}
				else
				{
                    // Wrong length
                    LAPDiaPrepareNegativeResponse(cLAPDiaIncorrectMessageLengthOrInvalidFormat);
                }
				
					
			}
			break;

			case cReportDTCByStatusMask: //return detailed DTC information
			{
				if (LAPDiaMemorizedRequest.Length == cLngReqReadDTCInformation)
				{
					U8 u8QueryResult;
					tmpDTCQuery.u8QueryType=eDTCRequestByStatusMask;
						
					//specify the query mask
					tmpDTCQuery.u8QueryMask=LAPDiaMemorizedRequest.Buffer[2] & cDTCSAM;;	
					
					mSERControl(DTCInfoRead, tmpDTCQuery);

					//check the result
					u8QueryResult = mSERRead(U8Bit,DTCQueryResult,Default);
					if((u8QueryResult!=cDATDtcQueryFailed) &&
					   (u8QueryResult!=cDATDtcQueryNotCorrect))
					{
						u8LenghtL = u8QueryResult;

						//here the number 2 means two bytes, one for response service ID, one for reportDTCByStatusMask
						LAPDiaPreparePositiveResponse((U8)(2+u8LenghtL));
					}
					else
					{
						LAPDiaPrepareNegativeResponse(cLAPDiaNoResponseFromSubnetComponent);
					}
				}
				else
				{
                    // Wrong length
                    LAPDiaPrepareNegativeResponse(cLAPDiaIncorrectMessageLengthOrInvalidFormat);
				}
				
			}
			break;
			
			case cReportSupportedDTCs: //get the supported DTCs
				if (LAPDiaMemorizedRequest.Length == cLngReqReadSupportedDTC)
				{
					U8 u8QueryResult;
					tmpDTCQuery.u8QueryType=eDTCRequestBySupportedDTCs;
					mSERControl(DTCInfoRead,tmpDTCQuery);

					u8QueryResult = mSERRead(U8Bit,DTCQueryResult,Default);
					if( (u8QueryResult!=cDATDtcQueryFailed) &&
						(u8QueryResult!=cDATDtcQueryNotCorrect))
					{
						u8LenghtL = u8QueryResult;
						LAPDiaPreparePositiveResponse((U8)(2+u8LenghtL));
					}
					else
					{
						LAPDiaPrepareNegativeResponse(cLAPDiaNoResponseFromSubnetComponent);
					}
				}
				else
				{
                    LAPDiaPrepareNegativeResponse(cLAPDiaIncorrectMessageLengthOrInvalidFormat);
				}
				break;

			case cReportDTCExtendedDataRecordsByDTCNumber:
			    if (LAPDiaMemorizedRequest.Length == cLngReqReadEDRNbyDTCNumber)
			    {
			        if((LAPDiaMemorizedRequest.Buffer[5] == cDTCEDRNOccurCNt) ||
			            (LAPDiaMemorizedRequest.Buffer[5] == cDTCEDRNRequestAll))
			            //扩展数据编号等于0x01表示发送次数或请求所有扩展数据，现在只有一个扩展数据，所以处理一样
                        //如果将来加扩展数据，此处要修改
			        {
                        U8 u8QueryResult;
                        tmpDTCQuery.u8QueryType = eDTCRequestByDefect;
                        //类型为通过故障码查找，下面将故障码取出
                        tmpDTCQuery.u16QueryDTCCode = ((U16)LAPDiaMemorizedRequest.Buffer[2] << 8) + LAPDiaMemorizedRequest.Buffer[3];
                        tmpDTCQuery.u8QueryFaultType = LAPDiaMemorizedRequest.Buffer[4];

                        mSERControl(DTCInfoRead,tmpDTCQuery);

                        u8QueryResult = mSERRead(U8Bit,DTCQueryResult,Default);
                        if( (u8QueryResult!=cDATDtcQueryFailed) &&
                            (u8QueryResult!=cDATDtcQueryNotCorrect))
                        {
                            u8LenghtL = u8QueryResult;
                            LAPDiaPreparePositiveResponse((U8)(2+u8LenghtL));
                        }
                        else
                        {
                            LAPDiaPrepareNegativeResponse(cLAPDiaRequestOutOfRange);
                        }
			        }
			        else
			        {
			            LAPDiaPrepareNegativeResponse(cLAPDiaRequestOutOfRange);
			        }
			    }
                else
                {
                    LAPDiaPrepareNegativeResponse(cLAPDiaIncorrectMessageLengthOrInvalidFormat);
                }
			    break;

            default:
                // Not supported sub service
                // GEN-VHL-ST-UDS.1120(0)
                LAPDiaPrepareNegativeResponse(cLAPDiaSubFunctionNotSupported);
                break;
        }
    }

}
#endif //cReadDTCInformation_Used


//==============================================================================
// DESCRIPTION : LAPDtcClearDiagnosticInformation
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : Clear Diagnostic Information Service
//==============================================================================
#ifdef cClearDiagnosticInformation_Used
void LAPDtcClearDiagnosticInformation(void)
{ 
	U32 u32DTCCode = 0U;

	u32DTCCode = u32DTCCode;

	if (LAPDiaMemorizedRequest.Length != cLngReqClearDiagnosticInformation)
    {
        // Prepare negative reponse: invalid length
        // GEN-VHL-ST-UDS.0800(0)
        LAPDiaPrepareNegativeResponse(cLAPDiaIncorrectMessageLengthOrInvalidFormat);
    }
    else
    {
        if ((((LAPDiaMemorizedRequest.Buffer[1] == ((U8)(cAllFailureGroups >> 16)))
            && (LAPDiaMemorizedRequest.Buffer[2] == ((U8)(cAllFailureGroups >> 8))) 
            && (LAPDiaMemorizedRequest.Buffer[3] == ((U8) cAllFailureGroups)))) ||

            ((LAPDiaMemorizedRequest.Buffer[1] == ((U8)(cU32BodyGroup >> 16)))
            && (LAPDiaMemorizedRequest.Buffer[2] == ((U8)(cU32BodyGroup >> 8)))
            && (LAPDiaMemorizedRequest.Buffer[3] == ((U8)cU32BodyGroup))))
            //因为只有一个组，所以清除该组与清除所有组处理一致

        {
            #if (defined(cLIBStkDatEepSbk_Used) || defined(cLIBStkDatEepDbk_Used))
            if (LAPDiaActiveService.Step == cLAPDiaStartOfService)
            #endif
            {
            	
#if defined(cLIBStkDef_Used)
                mSERControl(Def, ClearDefects);
#else
               //this control clear:au8Memorizations[],MemorizationTimersForDTCTessFail[]
			   //eeprom,asDTCStorage[]
				mSERControl(DTCInfoClear,ClearAllDTCInfo);
				//this control clear:Can default flag  in eeprom
				//TODO: zjb, whether delete the CAN DTC info in EEP depending on
				//EEP layout.
				//mSERControl(Can, RAZFaultCounter);
				//this control clear:can fault info in RAM
				//TODO: zjb , whether delete CAN management info depending on
				//multiply can design
		        //mSERControl(Can,ManagementReinitialization);
		    
#endif
            #if (defined(cLIBStkDatEepSbk_Used) || defined(cLIBStkDatEepDbk_Used))
                //Waiting for the end of EEPROM access, the graph will re launch the treatement
                LAPDiaActiveService.Step = cLAPDiaFirstStep;
            }
            else // if (LAPDiaActiveService.Step != cLAPDiaStartOfService)
            {
                //  waiting for the end of EEPROM access
                //Note:here we should read the speical bank busy flag-IsEepGroupGroupDTCProcessing, not the 
                //whole EEP flag-IsEepProcess, because the latter indicate the eep is process,
                //may the being processed thing is odo, or some thing like this.
                //if(mSERRead(U1Bit, IsEepProcessing, Default) == cFalse)
                if(mSERRead(U1Bit, IsEepGroupGroupDTCProcessing, Default) == cFalse )
            #endif
                {
                    #if (defined(cLIBStkDatEepSbk_Used) || defined(cLIBStkDatEepDbk_Used))
                    if (mSERRead(U1Bit, IsEepGroupGroupDTCWriteOk, Default) != cFalse)
                    {
                    #endif
		
                        // GEN-VHL-ST-UDS.0790(0)
                        LAPDiaPreparePositiveResponseSimple(cLngRepClearDiagnosticInformation);
                    #if (defined(cLIBStkDatEepSbk_Used) || defined(cLIBStkDatEepDbk_Used))
                    }
                    else
                    {
                    
                        // Prepare negative reponse: conditions not corerct 
                        // GEN-VHL-ST-UDS.0800(0)
                        LAPDiaPrepareNegativeResponse(cLAPDiaConditionsNotCorrect);
                    }
                    #endif
                }
            #if (defined(cLIBStkDatEepSbk_Used) || defined(cLIBStkDatEepDbk_Used))
                else //if(mSERRead(U1Bit, IsEepGroupGroupDTCProcessing, Default) != cFalse)
                {
                    // EEPROM writing is not finished => nothing to do => we wait
                }
            #endif
            }

        }
        else //clear the specific DTC.
        {	
            LAPDiaPrepareNegativeResponse(cLAPDiaRequestOutOfRange);

#if 0   //BCM313支持GroupOfDTC0xFFFFFF、0x000103，其余返回0x31NRC
        		if((LAPDiaGetActiveSession()==cLAPDiaIdEXTDSSession))
	        	{
				//get the DTC code
				u32DTCCode=(U32)((LAPDiaMemorizedRequest.Buffer[1]<<16) | (LAPDiaMemorizedRequest.Buffer[2]<<8) |(LAPDiaMemorizedRequest.Buffer[3]));
				//first write the DTC Code into DAT_DDB module to check the validation
				mSERWrite(U32Bit,DeletedDTCCode,u32DTCCode,Default);
				
				//check whether the DTC code is valid
				//only in client session(0X03) delete the specific DTC is allowed
				if( mSERRead(U1Bit,IsDTCCodeExist,Default))
				{					
					#if (defined(cLIBStkDatEepSbk_Used) || defined(cLIBStkDatEepDbk_Used))
					if (LAPDiaActiveService.Step == cLAPDiaStartOfService)
					#endif
					{
						
		#if defined(cLIBStkDef_Used)
						mSERControl(Def, ClearDefects);
		#else			
						//clear the specific DTC
						mSERControl(DTCInfoClear,ClearDTCByDTCCode);
		#endif
					#if (defined(cLIBStkDatEepSbk_Used) || defined(cLIBStkDatEepDbk_Used))
						//Waiting for the end of EEPROM access, the graph will re launch the treatement
						LAPDiaActiveService.Step = cLAPDiaFirstStep;
					}
					else // if (LAPDiaActiveService.Step != cLAPDiaStartOfService)
					{
						//  waiting for the end of EEPROM access
						 //Note:here we should read the speical bank busy flag-IsEepGroupGroupDTCProcessing, not the 
	                			//whole EEP flag-IsEepProcess, because the latter indicate the eep is process,
	                			//may the being processed thing is odo, or some thing like this.
						//if(mSERRead(U1Bit, IsEepProcessing, Default) == cFalse)
						if(mSERRead(U1Bit, IsEepGroupGroupDTCProcessing, Default) == cFalse)
						#endif
						{
								#if (defined(cLIBStkDatEepSbk_Used) || defined(cLIBStkDatEepDbk_Used))
								if (mSERRead(U1Bit, IsEepGroupGroupDTCWriteOk, Default) != cFalse)
								{
								#endif
								
									// GEN-VHL-ST-UDS.0790(0)
									LAPDiaPreparePositiveResponseSimple(cLngRepClearDiagnosticInformation);
								#if (defined(cLIBStkDatEepSbk_Used) || defined(cLIBStkDatEepDbk_Used))
								}
								else
								{
		
									// Prepare negative reponse: conditions not corerct 
									// GEN-VHL-ST-UDS.0800(0)
									LAPDiaPrepareNegativeResponse(cLAPDiaConditionsNotCorrect);
								}
								#endif
							}
							#if (defined(cLIBStkDatEepSbk_Used) || defined(cLIBStkDatEepDbk_Used))
							else //if(mSERRead(U1Bit, IsEepGroupGroupDTCProcessing, Default) != cFalse)
							{
								// EEPROM writing is not finished => nothing to do => we wait
							}
							#endif
						}			
				}
				else
				{
					//DTC does not exist,therefore return the negative response
					LAPDiaPrepareNegativeResponse(cLAPDiaRequestOutOfRange);
				}
			}
			else
			{
				LAPDiaPrepareNegativeResponse(cLAPDiaRequestOutOfRange);
			}
#endif
        }
    }
}
#endif //cClearDiagnosticInformation_Used

//==============================================================================
// DESCRIPTION : LAPDtcControlDTCSetting
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : Control Diagnostic Information Service
//==============================================================================
#ifdef cControlDTCSetting_Used
void LAPDtcControlDTCSetting(void)
{
	if (mLAPDiaReadLengthOfRequest() < cLngReqControlDTCSetting)
	{
		// Wrong length
		LAPDiaPrepareNegativeResponse(cLAPDiaIncorrectMessageLengthOrInvalidFormat);
	}
	else
	{
		if ((mGetDTCSettingType() != cLocalEnableDTCStoring) &&
			(mGetDTCSettingType() != cLocalDisableDTCStoring))
		{
			// Wrong sub-service
			LAPDiaPrepareNegativeResponse(cLAPDiaSubFunctionNotSupported);
		}
		else
		{
			if (mLAPDiaReadLengthOfRequest() == cLngReqControlDTCSetting)
			{
				if(mGetDTCSettingType() == cLocalDisableDTCStoring)
				{
				    mSERWrite(U1Bit, ControlDTCSetting, cTrue, Default);
				}
				else
				{
					mSERWrite(U1Bit, ControlDTCSetting, cFalse, Default);
				}
				
				LAPDiaPreparePositiveResponse(cLngRepControlDTCSetting);
			}
			else
			{
				LAPDiaPrepareNegativeResponse(cLAPDiaIncorrectMessageLengthOrInvalidFormat);
			}
		}
	}
}
#endif

//==============================================================================
// DESCRIPTION : LAPDtcOpenSession
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION :
//==============================================================================
void LAPDtcOpenSession (void)
{
	// SysRs_11_CustomerDiagnosis_120
    ///Example on a session except default session,
	//when from non-default session enter non-default session, DDTCControlSetting is not influenced.
	if( (pLAPDiaActiveSession != (tLAPDiaParamOfSession*)NULL) && 
		(pLAPDiaActiveSession->SessionIdentifier == cLAPDiaIdDefaultSession) )
    {
    	//when enter default session, enable the DTC recording
    	mSERWrite(U1Bit,ControlDTCSetting,cFalse,Default);
    }
}


//==============================================================================
// DESCRIPTION : LAPDtcCloseSession
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION :
//==============================================================================
void LAPDtcCloseSession (void)
{
    
}
