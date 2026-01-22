
#ifndef I_DAT_DII
#define I_DAT_DII

//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//
// #include <system_file_name.h>
// #include "project_file_name.h"
//------------------------------------------------------------------------------


#include "ARCH_CFG.h"


#ifdef cHeadIncludeType_Directly
#include "DAT_LIB.h"
#include "DAT_DDB.h"
#else
#include ".\..\..\DAT_LIB.h"
#include ".\..\DAT_DDB\DAT_DDB.h"
#endif


#include "DAT_DII_INCLUDE.h"

//------------------------------------------------------------------------------
// Data prefix for constant & data: see coding guideline
//
//------------------------------------------------------------------------------
// Constant data
//
// #define cu16DATCmpConstantName   ((U16) ConstantValueUL)
//------------------------------------------------------------------------------
#define cDATDtcFailed               cTrue
#define cDATDtcPassed               cFalse

//constant indicating that there is no DTC to report if
//mDATControl(Dtc, ReportDTCStatus) is called
#define cu8NoDTCToReport              (U8)0xFFU

//------------------------------------------------------------------------------
// Exported Macros
//
// #define DATCmpMacroName(...)   (MacroDefinition)
//------------------------------------------------------------------------------

#define mDATWriteTableU1BitDTCMonitoringCyclesDefault(Func, Value)          \
    (DATDtcControlMonitoringCycle((Func), (Value)))
#define mDATWriteTableU1BitDTCFaultsDefault(DTC, Status)                    \
    (DATDiiPrepareDTC((DTC), (Status)))
#define mDATControlDtc(Ctrl)                                                \
    (DATDtc##Ctrl())
#define DATDtcReportDTCStatus()                                             \
    (DATDiiReportDTCStatus())
#define mDATReadU8BitDTCForReportingDefault()                               \
    (DATDiiGetDTCForReporting())



//------------------------------------------------------------------------------
// Exported Macros inside DAT_DTC component
//
// #define DATCmpMacroName(...)   (MacroDefinition)
//------------------------------------------------------------------------------

#define mDIIClearDTCTestCounter()                                          \
   (DATDiiClearDTCTestCounter())

#define mDIIClearTestCounterByDTCCode(DTC)                                \
   (DATDiiClearTestCounterByDTCCode((DTC)))
//------------------------------------------------------------------------------
// Exported types
//
// typedef Expression    tTypeName;
//------------------------------------------------------------------------------
#define mDATDiiIsSetFlag(Tab,Handle)\
        ((BOOL)(Tab[ ((U8)(Handle)>>3U)] & (((U8)1U)<<( (U8)((Handle) & (U8)0x07U)))) != 0U)

#define mDATDiiSetFlag(Tab, Handle)\
        (Tab[ ((U8)(Handle)>>3U)] |= (((U8)1U)<<( (U8)((Handle) & (U8)0x07U))))

#define mDATDiiClearFlag(Tab, Handle)\
        (Tab[ ((U8)(Handle)>>3U)] &= ~(((U8)1U)<<( (U8)((Handle) & (U8)0x07U))))

#define cMAXDTCDeletedDrivingCycles                         ((U8)40U)
#define mDATGetDTCOccurredInCurrentIGCycleFlag(DTC)			(asDTCDeletedInfo[(DTC)].u8DTCOccurredInCurrentDrivingCycleFlag)
#define mDATClearDTCOccurredInCurrentIGCycleFlag(DTC)		(asDTCDeletedInfo[(DTC)].u8DTCOccurredInCurrentDrivingCycleFlag = cFalse)
#define mDATClearDTCOccurredFlag(DTC)                       (asDTCDeletedInfo[(DTC)].u8DTCOccurredFlag = cFalse)
#define mDATSetDTCOccurredInCurrentIGCycleFlag(DTC)			(asDTCDeletedInfo[(DTC)].u8DTCOccurredInCurrentDrivingCycleFlag=cTrue)
#define mDATSetDTCOccurredFlag(DTC)							(asDTCDeletedInfo[(DTC)].u8DTCOccurredFlag = cTrue)
#define mDATSetDTCDeletedDrivingCycles(DTC,NUM)             (asDTCDeletedInfo[(DTC)].u8DrivingCyclesSinceNoDTCOccur = (NUM ))
#define mDATGetDTCDeletedDrivingCycles(DTC)					(asDTCDeletedInfo[(DTC)].u8DrivingCyclesSinceNoDTCOccur)
#define mDATGetDTCOccurredFlag(DTC)							(asDTCDeletedInfo[(DTC)].u8DTCOccurredFlag)
#define mDATIncreaseDTCDeletedDrivingCycles(DTC)					\
	if(mDATGetDTCDeletedDrivingCycles(DTC)<cMAXDTCDeletedDrivingCycles)	\
		asDTCDeletedInfo[(DTC)].u8DrivingCyclesSinceNoDTCOccur++


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

extern void DATDiiInit(void);
extern void DATDiiEnterActiveState(void);
extern void DATDiiLeaveActiveState(void);
extern void DATDiiTask(void);

extern void DATDiiPrepareDTC(const U8 u8DTC, const BOOL bFailed);
extern void DATDiiReportDTCStatus(void);
extern void DATDtcControlMonitoringCycle(const U8 u8Category, const U1 u1Activate);
extern U8   DATDiiGetDTCForReporting(void);



extern void DATDiiClearTestCounterByDTCCode(U8 u8DTC);
extern void DATDiiClearDTCTestCounter(void);


#endif  //I_DAT_DII

