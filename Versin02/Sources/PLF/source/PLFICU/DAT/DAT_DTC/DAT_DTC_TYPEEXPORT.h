#ifndef I_DAT_DTC_TYPEEXPORT_H
#define I_DAT_DTC_TYPEEXPORT_H

#include "DAT_DTC_efuncom.h"



typedef enum
{

    #define DTC_DEFINE_DTC_ID_ENUM
    #include".\DAT_DDB\DAT_DDB_descr.h"
    #undef DTC_DEFINE_DTC_ID_ENUM
    eDTCIDCount
} eDTCIds;




typedef struct sDTCQuery_tag
{
    U8* pu8QueryBuffer;
    U8 u8QueryBufferSize;    
	// this variable stands for the lowest byte of a DTC code
    U8 u8QueryType;
    U8 u8QueryFaultType;
    U8 u8QueryMask;
	// this variable stands for the higher two bytes of a DTC code, which has 3 bytes
	U16 u16QueryDTCCode;
} sDTCQuery;

typedef enum
{
    eDTCRequestByStatusMask,
    eDTCRequestByDefect,
    eDTCRequestBySupportedDTCs,
    eDTCNumberOfSupportedRequests
} tDTCRequestTypes;


#define cDATDtcQueryNotCorrect      (U8)0xFEU
#define cDATDtcQueryFailed          (U8)0xFFU

#define cDTCEDRNOccurCNt            ((U8)0x01U)   //扩展数据编号，发送次数 0x01
#define cDTCEDRNRequestAll          ((U8)0xFFU)   //请求所有扩展数据

#define cu8DTCMaskTestFailed                            ((U8)0x01U)
#define cu8DTCMaskTestFailedThisOperationCycle           ((U8)0x02U)
#define cu8DTCMaskPendingDTC                             ((U8)0x04U)
#define cu8DTCMaskConfirmedDTC                           ((U8)0x08U)
#define cu8DTCMaskTestNotCompletedSinceLastClear         ((U8)0x10U)
#define cu8DTCMaskTestFailedSinceLastClear               ((U8)0x20U)
#define cu8DTCMaskTestNotCompletedThisOperationCycle     ((U8)0x40U)
#define cu8DTCMaskWarningIndicatorRequested              ((U8)0x80U)




#define cDTCSAM			    (U8)(cu8DTCMaskTestFailed                           |  \
	                                                    cu8DTCMaskTestFailedThisOperationCycle         |  \
							    cu8DTCMaskTestNotCompletedSinceLastClear       |  \
							    cu8DTCMaskTestFailedSinceLastClear             |  \
	                                                    cu8DTCMaskConfirmedDTC |\
	                                                    cu8DTCMaskTestNotCompletedThisOperationCycle)
//cu8DTCMaskPendingDTC                                    not support 
//        not support 




#endif
