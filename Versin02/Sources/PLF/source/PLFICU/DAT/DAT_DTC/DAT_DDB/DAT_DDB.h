
#ifndef I_DAT_DDB
#define I_DAT_DDB

#include "ARCH_CFG.h"
#ifdef cHeadIncludeType_Directly
#include "DAT_DII.h"

#else
#include ".\..\DAT_DII\DAT_DII.h"
#endif
#include "DAT_DDB_INCLUDE.h"




//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//
// #include <system_file_name.h>
// #include "project_file_name.h"
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Data prefix for constant & data: see coding guideline
//
//------------------------------------------------------------------------------
// Constant data
//
// #define cu16DATCmpConstantName   ((U16) ConstantValueUL)
//------------------------------------------------------------------------------



//------------------------------------------------------------------------------
// Exported type
//
// typedef Expression tDATCmpTypeName;
//------------------------------------------------------------------------------
/*
typedef enum
{

    #define DTC_DEFINE_DTC_ID_ENUM
    #include"DAT_DDB_descr.h"
    #undef DTC_DEFINE_DTC_ID_ENUM
    eDTCIDCount
} eDTCIds;
*/

//------------------------------------------------------------------------------
// Exported Macros
//
// #define DATCmpMacroName(...)   (MacroDefinition)
//------------------------------------------------------------------------------
#define cU8DtcValueMax                          ((U8)126U)

#define mDDBReadRecordField(DTC, Field)                                        \
    (DATDdbGetDTC##Field( (DTC) ))
#define mDDBWriteRecordField(DTC, Field, Val)                                  \
    (DATDdbSetDTC##Field( (DTC), (Val)))

#define mDDBSaveDTC(DTC)                                                       \
    (DATDdbSaveDTC( (DTC) ))

#define mDDBClearAllEEPRecords()                                                  \
    (DATDdbClearAllEEPRecords())
#define mDDBClearAllRAMStorage()                                                 \
	(DATDdbClearAllDTCRAMStorage())
#define mDDBClearDTCRAMStorage(DTC)                                                 \
	(DATDdbClearDTCRAMStroage((DTC)))
#define mDDBStopAllTimerByClearAllDTC()                                           \
   (DATDdbResetAllTimrByClearAllDTC())

#define mDDBGetDefectCodeByFault(DTC)                                          \
    (DATDdbGetDTCDefectCodeByFault( (DTC) ))
#define mDDBGetDefectType(DTC)                                                 \
    DATDdbGetDTCDefectType( (DTC) )
#define mDDBGetDTCTriggerValue(DTC)                                               \
    (DATDdbGetDTCTriggerValue( (DTC) ))
#define mDDBGetDTCFunCom(DTC)                                             \
    (DATDdbGetDTCFunCom( (DTC) ))
#define mDDBGetDTCConfirmedStep(DTC)                                               \
    (DATDdbGetDTCConfirmedStep( (DTC) ))
#define mDDBGetDTCHealedStep(DTC)                                               \
    (DATDdbGetDTCHealedStep( (DTC) ))

#define mDDBGetClearedDTCIndexInEep(DTC)				(DATDdbGetClearedDTCIndexInEep((DTC)))
#define mDDBClearDTCByIndexInEEP(DTC)						(DATDdbClearDTCByIndexInEEP((DTC)))

//------------------------------------------------------------------------------
// Exported data
//
// extern  tType   u8DATCmpVariableName;
// extern  tType*  ps32DATCmpVariableName;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Constant exported data
//
// extern const tType  s8DATCmpVariableName;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Exported functions
//
// extern tReturnType DATCmpFunctionName(tTypeArgument1 ArgumentName1, ... );
//------------------------------------------------------------------------------

extern U8   DATDdbGetDTCStatus(const U8 u8DTC);
extern U8 DATDdbGetDTCOccurCnt(const U8 u8DTC);

extern void DATDdbSetDTCStatus(const U8 u8DTC, const U8 u8Status);
extern void DATDdbSetDTCOccurCnt(const U8 u8DTC, const U8 u8OccurCnt);

extern void DATDdbSaveDTC(const U8 u8DTCId);
extern void DATDdbSetWarningIndicator(const U8 u8DTC);

extern void DATDdbClearAllEEPRecords(void);

extern U16 DATDdbGetDTCDefectCodeByFault(const U8 u8DTC);
extern U8 DATDdbGetDTCDefectType(const U8 u8DTC);
extern U16 DATDdbGetDTCTriggerValue(const U8 u8DTC);

extern U8 DATDdbGetDTCFunCom(const U8 u8DTC);

extern void DATDdbCloseDiagnosticSession(void);
extern void DATDdbOpenDiagnosticSession(void);
extern void DATDdbInitialize(void);

extern U8   DATDdbGetClearedDTCIndexInEep(const U8 u8DTC);
extern void DATDdbClearDTCByIndexInEEP(const U8 u8DTCIndex);



extern void DATDdbClearDTCRAMStroage(U8 u8DTCId);
extern void DATDdbClearAllDTCRAMStorage(void);

BOOL DATDdbUpdateStatusIntoEEP(const U8 u8Status, const U8 u8DTCId);
extern U8 DATDdbGetDTCConfirmedStep(const U8 u8DTC);
extern U8 DATDdbGetDTCHealedStep(const U8 u8DTC);
extern void DATDdbResetAllTimrByClearAllDTC(void);
extern void DATDdbResetTimerByClearSpecificDTC(U8 u8DTCIndex);
extern void DATBatVoltageResetTimerByClearSpecificDTC(void);
extern void DATCilFramRxSurveyRestart(void);
#endif  //I_DAT_DDB

