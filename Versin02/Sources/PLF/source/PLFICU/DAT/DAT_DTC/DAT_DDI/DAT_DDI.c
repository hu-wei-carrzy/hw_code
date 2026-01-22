

#define dat_ddi  "dat_ddi"

//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//
// #include <system_file_name.h>
// #include "project_file_name.h"
//------------------------------------------------------------------------------
#include "DAT_DDI.h"
//------------------------------------------------------------------------------
// Local constants
//
// #define cConstantName   ((tType) ConstantValue)
//------------------------------------------------------------------------------

#define cInvalidDTC		    (U8)0xFFU
//#define cDTCEDRNKm		    (U8)0x80U

//------------------------------------------------------------------------------
// Local macros
//
// #define mMacroName   (MacroDefinition)
//------------------------------------------------------------------------------
#define mN330SupportedMask()                               (cu8DTCMaskTestFailed|cu8DTCMaskConfirmedDTC)
#define mN330SupportedMaskSetting(u8OldStatus)             (mN330SupportedMask() &  (u8OldStatus))
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
static sDTCQuery* pDTCQuery;//ÓÉLap_Dtc mSERControl(DTCInfoRead,tmpDTCQuery)´«Èë
static U8 u8QueryResult;
//return the number of the DTC confirmed with the check station
static U16 u16QueryDTCCount;
//------------------------------------------------------------------------------
// Constant local data
//
// static const tType  VariableName;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Exported data
//
// tType   u8DATCmpVariableName; (DAT: 3 characters to identify the layer)
// tType*  pu8DATCmpVariableName;(Cmp: 3 characters to identify the component)
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Constant exported data
//
//             (DAT: 3 characters to identify the layer)
//             (Cmp: 3 characters to identify this component)
//
// const tType   DATCmpVariableName;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Local function prototypes
//
// static tReturnType FunctionName(tTypeArgument1 ArgumentName1, ... );
//------------------------------------------------------------------------------
static U8 GetDTCNum(const U16 u16Defect, const U8 u8Type);
static U8 GetQueryBySupportedDTCs(void);
static U8 GetQueryByStatus(void);
static U8 GetQueryByDefect(void);
//==============================================================================
//=========================== LOCAL FUNCTIONS ==================================
//==============================================================================

//==============================================================================
// DESCRIPTION         : Verifies if the given DTC defect & fault codes given
//                       are supported
// 
// PARAMETERS          : u16Defect - DTC defect code regarding RENAULT specification
//                       u8Type - DTC fault code regarding RENAULT specification
// 
// RETURN VALUE        : DTC value regarding eDTCIds enumeration in DAT_DDB
// 
// DESIGN INFORMATION  : Refer to Detailed Design Document
//==============================================================================
static U8 GetDTCNum(const U16 u16Defect, const U8 u8Type)
{
	U16 u16DTCDefect;
	U8 u8DTCType;
	U8 u8Result;
	U8 u8i;

	u8Result = cInvalidDTC;
	u8i = (U8)0;

	while ( (u8Result != u8i) && (u8i < eDTCIDCount) )
	{
		//get the U16 vaule(the higher two byte of DTC code) from au16DTCDefectCodes[]
		u16DTCDefect = mDDBGetDefectCodeByFault(u8i);
		//the lowest byte of DTC code 
		u8DTCType = mDDBGetDefectType(u8i);

		//this means the DTC code is the same
		if ( (u16DTCDefect == u16Defect) && (u8DTCType == u8Type) )
		{
			u8Result = u8i;
		}
		else
		{
			u8i++;
		}
	}

	return u8Result;
}

//==============================================================================
// DESCRIPTION        : Request by status mask
// 
// PARAMETERS         : None
// 
// RETURN VALUE       : cDATDtcQueryFailed if request cannot be executed.
//                      Otherwise return value is the number of bytes filled in
//                      the query buffer
// 
// DESIGN INFORMATION : Refer to Detailed Design Document
//==============================================================================
static U8 GetQueryBySupportedDTCs(void)
{
	U16 u16Defect;
	U8 u8DTCId;
	U8 u8DTCStatus;
	U8 u8Pos;
	BOOL bBufferInsuf;
    
    u8Pos = 0U;
    bBufferInsuf = cFalse;

    pDTCQuery->pu8QueryBuffer[u8Pos++] = (mN330SupportedMask()) & cDTCSAM ;
	
	//fill other DTC with their statuses
	u8DTCId = 0U;

	//clear the DTC count
	u16QueryDTCCount=0U;
	
	while ( (u8DTCId < eDTCIDCount) && (bBufferInsuf == cFalse) )
	{
		u8DTCStatus = mDDBReadRecordField(u8DTCId, Status); 
		u8DTCStatus =mN330SupportedMaskSetting(u8DTCStatus);
		if (cTrue)  //this is the only difference with  the GetQueryByStatus()
		{
			if ((pDTCQuery->u8QueryBufferSize) < (u8Pos + 4U) )
			{
				bBufferInsuf = cTrue;
				u8Pos = cDATDtcQueryFailed;
			}
			else
			{         
				u16QueryDTCCount++;
				u16Defect = mDDBGetDefectCodeByFault(u8DTCId);
			    pDTCQuery->pu8QueryBuffer[u8Pos++] = (U8)(u16Defect >> 8U);
				pDTCQuery->pu8QueryBuffer[u8Pos++] = (U8)(u16Defect);
				pDTCQuery->pu8QueryBuffer[u8Pos++] = mDDBGetDefectType(u8DTCId);
				pDTCQuery->pu8QueryBuffer[u8Pos++] = u8DTCStatus;
			}
		}
		u8DTCId++;
	}    
	return u8Pos;
}
//==============================================================================
// DESCRIPTION        : Request by status mask
//
// PARAMETERS         : None
//
// RETURN VALUE       : cDATDtcQueryFailed if request cannot be executed.
//                      Otherwise return value is the number of bytes filled in
//                      the query buffer
//
// DESIGN INFORMATION : Refer to Detailed Design Document
//==============================================================================
static U8 GetQueryByStatus(void)
{
	U16 u16Defect = 0U;
	U8 u8DTCId;
	U8 u8DTCStatus;
	U8 u8Pos;
	BOOL bBufferInsuf;
    u8Pos = 0U;
    bBufferInsuf = cFalse;
    pDTCQuery->pu8QueryBuffer[u8Pos++] = (mN330SupportedMask()) & cDTCSAM ;
	u8DTCId = 0U;
	u16QueryDTCCount=0U;
	while ( (u8DTCId < eDTCIDCount) && (bBufferInsuf == cFalse) )
	{
		u8DTCStatus = mDDBReadRecordField(u8DTCId, Status);
		u8DTCStatus =mN330SupportedMaskSetting(u8DTCStatus);
		if ( (u8DTCStatus & pDTCQuery->u8QueryMask) != 0U)
		{
			if ((pDTCQuery->u8QueryBufferSize) < (u8Pos + 4U) )
			{
				//in case that the buffer is not sufficient we return error
				bBufferInsuf = cTrue;
				u8Pos = cDATDtcQueryFailed;
			}
			else
			{         
				u16QueryDTCCount++;
				//here get the higher two bytes of  DTCcode
				u16Defect = mDDBGetDefectCodeByFault(u8DTCId);
                
			    pDTCQuery->pu8QueryBuffer[u8Pos++] = (U8)(u16Defect >> 8U);
				pDTCQuery->pu8QueryBuffer[u8Pos++] = (U8)(u16Defect);
				//this is the lowest byte of DTCcode
				pDTCQuery->pu8QueryBuffer[u8Pos++] = mDDBGetDefectType(u8DTCId);
				pDTCQuery->pu8QueryBuffer[u8Pos++] = u8DTCStatus;
			}
		}
		u8DTCId++;
	}    

	return u8Pos;
}

//==============================================================================
// DESCRIPTION        : Request by defect
// 
// PARAMETERS         : None
// 
// RETURN VALUE       : cDATDtcQueryFailed if request cannot be executed.
//                      Otherwise return value is the number of bytes filled in
//                      the query buffer
// 
// DESIGN INFORMATION : Refer to Detailed Design Document
//==============================================================================
static U8 GetQueryByDefect(void)
{
	U32 u8OccurCnt;
	U8 u8Index;
	U8 u8Status;
	U8 u8Pos;

    if (pDTCQuery->u8QueryBufferSize < (U8)8U)
    {
        u8Pos = cDATDtcQueryFailed;
    }
    else
    {
        //get DTC index
        u8Index = GetDTCNum(pDTCQuery->u16QueryDTCCode, 
            pDTCQuery->u8QueryFaultType);
    
        if (u8Index != cInvalidDTC)
        {
            u8Pos = 0U;
        
            //fill in the DTC code, totally 3 bytes
            pDTCQuery->pu8QueryBuffer[u8Pos++] = 
                (U8)((pDTCQuery->u16QueryDTCCode) >> 8U);
            pDTCQuery->pu8QueryBuffer[u8Pos++] = 
                (U8)((pDTCQuery->u16QueryDTCCode));
            pDTCQuery->pu8QueryBuffer[u8Pos++] = 
                pDTCQuery->u8QueryFaultType;
                
        
            //get DTC status and put it into the buffer
            u8Status = mDDBReadRecordField(u8Index, Status);
		    u8Status =mN330SupportedMaskSetting(u8Status);
            pDTCQuery->pu8QueryBuffer[u8Pos++] = u8Status;
        
            if ( (u8Status & cu8DTCMaskConfirmedDTC) != 0U )
            {
                pDTCQuery->pu8QueryBuffer[u8Pos++] = cDTCEDRNOccurCNt;
                u8OccurCnt = mDDBReadRecordField(u8Index, OccurCnt);
                pDTCQuery->pu8QueryBuffer[u8Pos++] = (U8)(u8OccurCnt);
            }
        }
        else
        { //requested DTC is not found
            u8Pos = cDATDtcQueryNotCorrect;
        }
    }    
	
	return u8Pos;
}


//==============================================================================
//=========================== EXPORTED FUNCTIONS ===============================
//==============================================================================


//==============================================================================
// DESCRIPTION        : Prepare DTC query
// 
// PARAMETERS         : u32QueryAddress - the address of prepared DTC query
// 
// RETURN VALUE       : None
// 
// DESIGN INFORMATION : Refer to Detailed Design Document
//==============================================================================
void DATDdiPrepareQuery(const U32 u32QueryAddress)
{
    pDTCQuery = (sDTCQuery*)u32QueryAddress;
}

//==============================================================================
// DESCRIPTION        : Returns the result value of previously executed query
// 
// PARAMETERS         : None
// 
// RETURN VALUE       : Value of u8QueryResult
// 
// DESIGN INFORMATION : Refer to Detailed Design Document
//==============================================================================
U8 DATDdiGetQueryResult(void)
{
    return u8QueryResult;
}

//==============================================================================
// DESCRIPTION        : Execute DTC query
// 
// PARAMETERS         : None
// 
// RETURN VALUE       : None
// 
// DESIGN INFORMATION : Refer to Detailed Design Document
//==============================================================================
void DATDdiReadDTCInformation(void)
{
    u8QueryResult = cDATDtcQueryFailed;

    if (
         (pDTCQuery != (sDTCQuery*)NULL) && 
         (pDTCQuery->pu8QueryBuffer != (U8*)NULL) &&
         (pDTCQuery->u8QueryBufferSize > 0U) &&
         (pDTCQuery->u8QueryBufferSize < cDATDtcQueryNotCorrect)
       )
    {
        switch ( (tDTCRequestTypes)pDTCQuery->u8QueryType)
        {
            case eDTCRequestByStatusMask:
                u8QueryResult = GetQueryByStatus();
                break;

            case eDTCRequestByDefect:
                u8QueryResult = GetQueryByDefect();
                break;

            case eDTCRequestBySupportedDTCs:
            	u8QueryResult  = GetQueryBySupportedDTCs();
            	break;
            default:
                mLIBassert(cFalse);
                break;
        }
    }
    else
    {
        u8QueryResult = cDATDtcQueryNotCorrect;
    }

    pDTCQuery = (sDTCQuery*)NULL;
}

//==============================================================================
// DESCRIPTION         : Handle entering in active state event
// 
// PARAMETERS          : None
// 
// RETURN VALUE        : None
// 
// DESIGN INFORMATION  : Refer to Detailed Design Document
//==============================================================================
void DATDdiEnterActiveState(void)
{
    pDTCQuery = (sDTCQuery*)NULL;
    u8QueryResult = cDATDtcQueryFailed;
}

//==============================================================================
// DESCRIPTION         : DATDdiGetQueryDTCCount()
// 
// PARAMETERS          : None
// 
// RETURN VALUE        : None
// 
// DESIGN INFORMATION  : Refer to Detailed Design Document
//==============================================================================
U16  DATDdiGetQueryDTCCount(void)
{
	return u16QueryDTCCount;
}
