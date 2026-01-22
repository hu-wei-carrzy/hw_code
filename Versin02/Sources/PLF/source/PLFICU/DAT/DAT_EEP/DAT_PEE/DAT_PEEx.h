/*---------------------------------------------------------------------------

                This software is JCI property
                -----------------------------

    Duplication or disclosure is prohibited without JCI
    written permission.
    This file has been automatically generated with an excel file,
    by a visual basic macro.

 File                        : DAT_PEEx.h
 Project                     : STK
 Fonction                    : EEP
 Author                      : Author
 Automatically generated on  : 2025/9/1 a 16:05:43 
 Source file                 : DAT_EEP_CFG.XLS
 Macro version               : 01.43
 Configuration version       : 01.00

---------------------------------------------------------------------------*/

#ifndef I_PEE_PARAM_H
#define I_PEE_PARAM_H (1)

//--------------------------------------------------------------------------
//----  Declaration of constants and macros exported by this component  ----
//--------------------------------------------------------------------------
//
// (Com: 3 letters identifying this component)
// #define cDATPeeNomConstante   ValeurDeLaConstante
//
// (Com: 3 letters identifying this component)
// #define mSERPeeNomMacro   (DefinitionDeLaMacro)


//--------------------------------------------------------------------------
//  Global Declaration
//--------------------------------------------------------------------------

#define mSERControlEep(Command)\
    mSERControlEep##Command();     

#define mSERControlEepInit()\
    DATEepInit();   \
    DATSbkInit();   \
    DATDbkInit();   \
    DATObkInit();   \
    DATPeeInit();   \

#define mSERControlEepRestore()\
    DATDbkStartRestoringBrokenBanks();     \

#define mSERControlEepReadEep()\
    DATSbkStartReadingAllBanks();     \
    DATDbkStartReadingAllBanks();     \
    DATObkStartReadingAllBanks();     \


//--------------------------------------------------------------------------
// Groups declarations
//--------------------------------------------------------------------------

// Information on the Group ErrorGroup
#define cDATPeeNumberOfDataErrorGroup         1 
#define cDATPeeSizeErrorGroup         22 
#ifdef cFormatMotorola
#define mSERPeeResetBufferErrorGroup()        {0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0  \
     ,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0 }
#else
#define mSERPeeResetBufferErrorGroup()        {0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0  \
     ,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0 }
#endif

#define mSERControlEepReadEepGroupErrorGroup()\
    DATSbkStartReading(cDATSbkHandleErrorGroup)

#define mSERReadU1BitIsEepGroupErrorGroupProcessingDefault() \
    DATSbkIsBankProcessing(cDATSbkHandleErrorGroup)

#define mSERControlEepUpDateEepGroupErrorGroup()\
    DATSbkStartUpdate(cDATSbkHandleErrorGroup)

#define mSERReadU1BitIsEepGroupErrorGroupWriteOkDefault() \
    DATSbkIsWriteOk(cDATSbkHandleErrorGroup)

// Information on the Group GroupTraceability
#define cDATPeeNumberOfDataGroupTraceability         22 
#define cDATPeeSizeGroupTraceability         125 
#ifdef cFormatMotorola
#define mSERPeeResetBufferGroupTraceability()        {0x3,0x82,0x0,0x22,0x95,0x0,0x0  \
     ,0x0,0x0,0x0,0x0,0x0,0x0,0x71,0x20,0x20,0x0,0x1,0x1,0x0,0x0,0x31,0x32,0x33,0x34  \
     ,0x35,0x36,0x37,0x38,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x20,0x20,0x20,0x20,0x20  \
     ,0x20,0x20,0x20,0x56,0x30,0x31,0x42,0x0,0x0,0x0,0x0,0x0,0x20,0x0,0x1,0x1,0x0  \
     ,0x0,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x20,0x0,0x1,0x1,0x0,0x0,0xFF,0xFF,0xFF  \
     ,0xFF,0xFF,0xFF,0xFF,0x1,0x0,0x0,0x0,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20  \
     ,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x0,0x0,0x1,0x20,0x20,0x20,0x20,0x20  \
     ,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x1,0x2C,0x0,0x0  \
     ,0x0 }
#else
#define mSERPeeResetBufferGroupTraceability()        {0x3,0x82,0x0,0x22,0x95,0x0,0x0  \
     ,0x0,0x0,0x0,0x0,0x0,0x0,0x71,0x20,0x20,0x0,0x1,0x1,0x0,0x0,0x31,0x32,0x33,0x34  \
     ,0x35,0x36,0x37,0x38,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x20,0x20,0x20,0x20,0x20  \
     ,0x20,0x20,0x20,0x56,0x30,0x31,0x42,0x0,0x0,0x0,0x0,0x0,0x20,0x0,0x1,0x1,0x0  \
     ,0x0,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x20,0x0,0x1,0x1,0x0,0x0,0xFF,0xFF,0xFF  \
     ,0xFF,0xFF,0xFF,0xFF,0x1,0x0,0x0,0x0,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20  \
     ,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x0,0x0,0x1,0x20,0x20,0x20,0x20,0x20  \
     ,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x2C,0x1,0x0,0x0  \
     ,0x0 }
#endif

#define mSERControlEepReadEepGroupGroupTraceability()\
    DATSbkStartReading(cDATSbkHandleGroupTraceability)

#define mSERReadU1BitIsEepGroupGroupTraceabilityProcessingDefault() \
    DATSbkIsBankProcessing(cDATSbkHandleGroupTraceability)

#define mSERControlEepUpDateEepGroupGroupTraceability()\
    DATSbkStartUpdate(cDATSbkHandleGroupTraceability)

#define mSERReadU1BitIsEepGroupGroupTraceabilityWriteOkDefault() \
    DATSbkIsWriteOk(cDATSbkHandleGroupTraceability)

// Information on the Group GroupPlantTraceability
#define cDATPeeNumberOfDataGroupPlantTraceability         13 
#define cDATPeeSizeGroupPlantTraceability         45 
#ifdef cFormatMotorola
#define mSERPeeResetBufferGroupPlantTraceability()        {0x0,0x0,0x0,0x0,0x0,0x0  \
     ,0x0,0x0,0x0,0x0,0x0,0x0,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF  \
     ,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xFF,0xFF,0xFF  \
     ,0x0,0x0,0x0,0x0,0x0 }
#else
#define mSERPeeResetBufferGroupPlantTraceability()        {0x0,0x0,0x0,0x0,0x0,0x0  \
     ,0x0,0x0,0x0,0x0,0x0,0x0,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF  \
     ,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xFF,0xFF,0xFF  \
     ,0x0,0x0,0x0,0x0,0x0 }
#endif

#define mSERControlEepReadEepGroupGroupPlantTraceability()\
    DATSbkStartReading(cDATSbkHandleGroupPlantTraceability)

#define mSERReadU1BitIsEepGroupGroupPlantTraceabilityProcessingDefault() \
    DATSbkIsBankProcessing(cDATSbkHandleGroupPlantTraceability)

#define mSERControlEepUpDateEepGroupGroupPlantTraceability()\
    DATSbkStartUpdate(cDATSbkHandleGroupPlantTraceability)

#define mSERReadU1BitIsEepGroupGroupPlantTraceabilityWriteOkDefault() \
    DATSbkIsWriteOk(cDATSbkHandleGroupPlantTraceability)

// Information on the Group GroupDiagReserved
#define cDATPeeNumberOfDataGroupDiagReserved         1 
#define cDATPeeSizeGroupDiagReserved         8 
#ifdef cFormatMotorola
#define mSERPeeResetBufferGroupDiagReserved()        {0x0,0x0,0x0,0x0,0x0,0x0,0x0  \
     ,0x0 }
#else
#define mSERPeeResetBufferGroupDiagReserved()        {0x0,0x0,0x0,0x0,0x0,0x0,0x0  \
     ,0x0 }
#endif

#define mSERControlEepReadEepGroupGroupDiagReserved()\
    DATSbkStartReading(cDATSbkHandleGroupDiagReserved)

#define mSERReadU1BitIsEepGroupGroupDiagReservedProcessingDefault() \
    DATSbkIsBankProcessing(cDATSbkHandleGroupDiagReserved)

#define mSERControlEepUpDateEepGroupGroupDiagReserved()\
    DATSbkStartUpdate(cDATSbkHandleGroupDiagReserved)

#define mSERReadU1BitIsEepGroupGroupDiagReservedWriteOkDefault() \
    DATSbkIsWriteOk(cDATSbkHandleGroupDiagReserved)

// Information on the Group GroupOdo
#define cDATPeeNumberOfDataGroupOdo         2 
#define cDATPeeSizeGroupOdo         8 
#ifdef cFormatMotorola
#define mSERPeeResetBufferGroupOdo()        {0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0 }
#else
#define mSERPeeResetBufferGroupOdo()        {0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0 }
#endif

#define mSERControlEepReadEepGroupGroupOdo()\
    DATObkStartReading(cDATObkHandleGroupOdo)

#define mSERReadU1BitIsEepGroupGroupOdoProcessingDefault() \
    DATObkIsBankProcessing(cDATObkHandleGroupOdo)

#define mSERControlEepUpDateEepGroupGroupOdo()\
    DATObkStartUpdate(cDATObkHandleGroupOdo)

#define mSERReadU1BitIsEepGroupGroupOdoWriteOkDefault() \
    DATObkIsWriteOk(cDATObkHandleGroupOdo)

#define mSERControlEepGlobalUpDateEepGroupGroupOdo()\
    DATObkNbBanksToWrite[cDATObkHandleGroupOdo] = cDATObkNumberOfBankCopy;\
    DATObkStartUpdate(cDATObkHandleGroupOdo)

// Information on the Group GroupPlantCalibiration
#define cDATPeeNumberOfDataGroupPlantCalibiration         8 
#define cDATPeeSizeGroupPlantCalibiration         8 
#ifdef cFormatMotorola
#define mSERPeeResetBufferGroupPlantCalibiration()        {0x0,0x0,0x0,0x0,0x0,0x0  \
     ,0x0,0x0 }
#else
#define mSERPeeResetBufferGroupPlantCalibiration()        {0x0,0x0,0x0,0x0,0x0,0x0  \
     ,0x0,0x0 }
#endif

#define mSERControlEepReadEepGroupGroupPlantCalibiration()\
    DATSbkStartReading(cDATSbkHandleGroupPlantCalibiration)

#define mSERReadU1BitIsEepGroupGroupPlantCalibirationProcessingDefault() \
    DATSbkIsBankProcessing(cDATSbkHandleGroupPlantCalibiration)

#define mSERControlEepUpDateEepGroupGroupPlantCalibiration()\
    DATSbkStartUpdate(cDATSbkHandleGroupPlantCalibiration)

#define mSERReadU1BitIsEepGroupGroupPlantCalibirationWriteOkDefault() \
    DATSbkIsWriteOk(cDATSbkHandleGroupPlantCalibiration)

// Information on the Group GroupSTKDTC
#define cDATPeeNumberOfDataGroupSTKDTC         6 
#define cDATPeeSizeGroupSTKDTC         24 
#ifdef cFormatMotorola
#define mSERPeeResetBufferGroupSTKDTC()        {0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0  \
     ,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1 }
#else
#define mSERPeeResetBufferGroupSTKDTC()        {0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0  \
     ,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1 }
#endif

#define mSERControlEepReadEepGroupGroupSTKDTC()\
    DATDbkStartReading(cDATDbkHandleGroupSTKDTC)

#define mSERReadU1BitIsEepGroupGroupSTKDTCProcessingDefault() \
    DATDbkIsBankProcessing(cDATDbkHandleGroupSTKDTC)

#define mSERControlEepUpDateEepGroupGroupSTKDTC()\
    DATDbkStartUpdate(cDATDbkHandleGroupSTKDTC)

#define mSERReadU1BitIsEepGroupGroupSTKDTCWriteOkDefault() \
    DATDbkIsWriteOk(cDATDbkHandleGroupSTKDTC)

// Information on the Group GroupDTC
#define cDATPeeNumberOfDataGroupDTC         1 
#define cDATPeeSizeGroupDTC         80 
#ifdef cFormatMotorola
#define mSERPeeResetBufferGroupDTC()        {0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0  \
     ,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0  \
     ,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0  \
     ,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0  \
     ,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0 }
#else
#define mSERPeeResetBufferGroupDTC()        {0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0  \
     ,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0  \
     ,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0  \
     ,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0  \
     ,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0 }
#endif

#define mSERControlEepReadEepGroupGroupDTC()\
    DATDbkStartReading(cDATDbkHandleGroupDTC)

#define mSERReadU1BitIsEepGroupGroupDTCProcessingDefault() \
    DATDbkIsBankProcessing(cDATDbkHandleGroupDTC)

#define mSERControlEepUpDateEepGroupGroupDTC()\
    DATDbkStartUpdate(cDATDbkHandleGroupDTC)

#define mSERReadU1BitIsEepGroupGroupDTCWriteOkDefault() \
    DATDbkIsWriteOk(cDATDbkHandleGroupDTC)

// Information on the Group GroupDIUpperLimit
#define cDATPeeNumberOfDataGroupDIUpperLimit         1 
#define cDATPeeSizeGroupDIUpperLimit         120 
#ifdef cFormatMotorola
#define mSERPeeResetBufferGroupDIUpperLimit()        {0xB,0xB8,0xB,0xB8,0xB,0xB8,0xB  \
     ,0xB8,0xB,0xB8,0xB,0xB8,0xB,0xB8,0xB,0xB8,0xB,0xB8,0xB,0xB8,0xB,0xB8,0xB,0xB8  \
     ,0xB,0xB8,0xB,0xB8,0x3,0x84,0x3E,0x80,0x3,0x84,0x0,0x2D,0x2E,0xE0,0x3,0x84,0x3  \
     ,0x84,0x3,0x84,0x3,0x84,0x3E,0x80,0x3,0x84,0x0,0xA0,0x2E,0xE0,0x3,0x84,0x3,0x84  \
     ,0x3,0x84,0x3,0x84,0x3E,0x80,0x0,0x2D,0x0,0xA0,0x3,0x84,0x3,0x84,0x3,0x84,0x3E  \
     ,0x80,0x2E,0xE0,0x3,0x84,0x3,0x84,0x3,0x84,0x3,0x84,0x3,0x84,0x3E,0x80,0x3,0x84  \
     ,0x3,0x84,0x3,0x84,0x3E,0x80,0x2E,0xE0,0x3,0x84,0x3,0x84,0x3,0x84,0x3,0x84,0x3  \
     ,0x84,0x3E,0x80,0x2E,0xE0,0x2E,0xE0,0x2E,0xE0,0x2E,0xE0 }
#else
#define mSERPeeResetBufferGroupDIUpperLimit()        {0xB8,0xB,0xB8,0xB,0xB8,0xB,0xB8  \
     ,0xB,0xB8,0xB,0xB8,0xB,0xB8,0xB,0xB8,0xB,0xB8,0xB,0xB8,0xB,0xB8,0xB,0xB8,0xB  \
     ,0xB8,0xB,0xB8,0xB,0x84,0x3,0x80,0x3E,0x84,0x3,0x2D,0x0,0xE0,0x2E,0x84,0x3,0x84  \
     ,0x3,0x84,0x3,0x84,0x3,0x80,0x3E,0x84,0x3,0xA0,0x0,0xE0,0x2E,0x84,0x3,0x84,0x3  \
     ,0x84,0x3,0x84,0x3,0x80,0x3E,0x2D,0x0,0xA0,0x0,0x84,0x3,0x84,0x3,0x84,0x3,0x80  \
     ,0x3E,0xE0,0x2E,0x84,0x3,0x84,0x3,0x84,0x3,0x84,0x3,0x84,0x3,0x80,0x3E,0x84,0x3  \
     ,0x84,0x3,0x84,0x3,0x80,0x3E,0xE0,0x2E,0x84,0x3,0x84,0x3,0x84,0x3,0x84,0x3,0x84  \
     ,0x3,0x80,0x3E,0xE0,0x2E,0xE0,0x2E,0xE0,0x2E,0xE0,0x2E }
#endif

#define mSERControlEepReadEepGroupGroupDIUpperLimit()\
    DATDbkStartReading(cDATDbkHandleGroupDIUpperLimit)

#define mSERReadU1BitIsEepGroupGroupDIUpperLimitProcessingDefault() \
    DATDbkIsBankProcessing(cDATDbkHandleGroupDIUpperLimit)

#define mSERControlEepUpDateEepGroupGroupDIUpperLimit()\
    DATDbkStartUpdate(cDATDbkHandleGroupDIUpperLimit)

#define mSERReadU1BitIsEepGroupGroupDIUpperLimitWriteOkDefault() \
    DATDbkIsWriteOk(cDATDbkHandleGroupDIUpperLimit)

// Information on the Group GroupDILowerLimit
#define cDATPeeNumberOfDataGroupDILowerLimit         1 
#define cDATPeeSizeGroupDILowerLimit         120 
#ifdef cFormatMotorola
#define mSERPeeResetBufferGroupDILowerLimit()        {0x2,0x58,0x2,0x58,0x2,0x58,0x2  \
     ,0x58,0x2,0x58,0x2,0x58,0x2,0x58,0x2,0x58,0x2,0x58,0x2,0x58,0x2,0x58,0x2,0x58  \
     ,0x2,0x58,0x2,0x58,0x1,0xF4,0x2E,0xE0,0x1,0xF4,0x0,0x2C,0x2A,0xF8,0x1,0xF4,0x1  \
     ,0xF4,0x1,0xF4,0x1,0xF4,0x2E,0xE0,0x1,0xF4,0x0,0x9F,0x2A,0xF8,0x1,0xF4,0x1,0xF4  \
     ,0x1,0xF4,0x1,0xF4,0x2E,0xE0,0x0,0x2C,0x0,0x9F,0x1,0xF4,0x1,0xF4,0x1,0xF4,0x2E  \
     ,0xE0,0x2A,0xF8,0x1,0xF4,0x1,0xF4,0x1,0xF4,0x1,0xF4,0x1,0xF4,0x2A,0xF8,0x1,0xF4  \
     ,0x1,0xF4,0x1,0xF4,0x2A,0xF8,0x2A,0xF8,0x1,0xF4,0x1,0xF4,0x1,0xF4,0x1,0xF4,0x1  \
     ,0xF4,0x2E,0xE0,0x2A,0xF8,0x2A,0xF8,0x2A,0xF8,0x2A,0xF8 }
#else
#define mSERPeeResetBufferGroupDILowerLimit()        {0x58,0x2,0x58,0x2,0x58,0x2,0x58  \
     ,0x2,0x58,0x2,0x58,0x2,0x58,0x2,0x58,0x2,0x58,0x2,0x58,0x2,0x58,0x2,0x58,0x2  \
     ,0x58,0x2,0x58,0x2,0xF4,0x1,0xE0,0x2E,0xF4,0x1,0x2C,0x0,0xF8,0x2A,0xF4,0x1,0xF4  \
     ,0x1,0xF4,0x1,0xF4,0x1,0xE0,0x2E,0xF4,0x1,0x9F,0x0,0xF8,0x2A,0xF4,0x1,0xF4,0x1  \
     ,0xF4,0x1,0xF4,0x1,0xE0,0x2E,0x2C,0x0,0x9F,0x0,0xF4,0x1,0xF4,0x1,0xF4,0x1,0xE0  \
     ,0x2E,0xF8,0x2A,0xF4,0x1,0xF4,0x1,0xF4,0x1,0xF4,0x1,0xF4,0x1,0xF8,0x2A,0xF4,0x1  \
     ,0xF4,0x1,0xF4,0x1,0xF8,0x2A,0xF8,0x2A,0xF4,0x1,0xF4,0x1,0xF4,0x1,0xF4,0x1,0xF4  \
     ,0x1,0xE0,0x2E,0xF8,0x2A,0xF8,0x2A,0xF8,0x2A,0xF8,0x2A }
#endif

#define mSERControlEepReadEepGroupGroupDILowerLimit()\
    DATDbkStartReading(cDATDbkHandleGroupDILowerLimit)

#define mSERReadU1BitIsEepGroupGroupDILowerLimitProcessingDefault() \
    DATDbkIsBankProcessing(cDATDbkHandleGroupDILowerLimit)

#define mSERControlEepUpDateEepGroupGroupDILowerLimit()\
    DATDbkStartUpdate(cDATDbkHandleGroupDILowerLimit)

#define mSERReadU1BitIsEepGroupGroupDILowerLimitWriteOkDefault() \
    DATDbkIsWriteOk(cDATDbkHandleGroupDILowerLimit)

// Information on the Group GroupDIType
#define cDATPeeNumberOfDataGroupDIType         1 
#define cDATPeeSizeGroupDIType         15 
#ifdef cFormatMotorola
#define mSERPeeResetBufferGroupDIType()        {0x0,0x5,0x0,0x2D,0x1,0x0,0x36,0x37  \
     ,0x1,0x0,0x36,0x37,0xF,0x0,0x0 }
#else
#define mSERPeeResetBufferGroupDIType()        {0x0,0x5,0x0,0x2D,0x1,0x0,0x36,0x37  \
     ,0x1,0x0,0x36,0x37,0xF,0x0,0x0 }
#endif

#define mSERControlEepReadEepGroupGroupDIType()\
    DATDbkStartReading(cDATDbkHandleGroupDIType)

#define mSERReadU1BitIsEepGroupGroupDITypeProcessingDefault() \
    DATDbkIsBankProcessing(cDATDbkHandleGroupDIType)

#define mSERControlEepUpDateEepGroupGroupDIType()\
    DATDbkStartUpdate(cDATDbkHandleGroupDIType)

#define mSERReadU1BitIsEepGroupGroupDITypeWriteOkDefault() \
    DATDbkIsWriteOk(cDATDbkHandleGroupDIType)

// Information on the Group GroupSensorCal
#define cDATPeeNumberOfDataGroupSensorCal         16 
#define cDATPeeSizeGroupSensorCal         136 
#ifdef cFormatMotorola
#define mSERPeeResetBufferGroupSensorCal()        {0xD,0xAC,0xD,0xAC,0x0,0x87,0x0  \
     ,0x64,0xF,0xA0,0xF,0xA0,0x3,0xE8,0x3,0xE8,0xA,0xA,0xA,0xA,0xA,0xA,0xA,0xA,0xA  \
     ,0xA,0xA,0xA,0xA,0xA,0xA,0xA,0xA,0xA,0xA,0xA,0x0,0x50,0x0,0x50,0x0,0x50,0x0,0x50  \
     ,0x0,0x50,0x0,0x50,0x0,0x50,0x0,0x50,0x0,0x50,0x0,0x50,0x0,0x50,0x0,0x50,0x0  \
     ,0x50,0x0,0x50,0x0,0x50,0x0,0x50,0x0,0x50,0x0,0x50,0x0,0x50,0x0,0x50,0xA,0xA  \
     ,0xA,0xA,0xA,0xA,0xA,0xA,0xA,0xA,0xA,0xA,0xA,0xA,0xA,0xA,0xA,0xA,0xA,0xA,0x0  \
     ,0x50,0x0,0x50,0x0,0x50,0x0,0x50,0x0,0x50,0x0,0x50,0x0,0x50,0x0,0x50,0x0,0x50  \
     ,0x0,0x50,0x0,0x50,0x0,0x50,0x0,0x50,0x0,0x50,0x0,0x50,0x0,0x50,0x0,0x50,0x0  \
     ,0x50,0x0,0x50,0x0,0x50 }
#else
#define mSERPeeResetBufferGroupSensorCal()        {0xAC,0xD,0xAC,0xD,0x87,0x0,0x64  \
     ,0x0,0xA0,0xF,0xA0,0xF,0xE8,0x3,0xE8,0x3,0xA,0xA,0xA,0xA,0xA,0xA,0xA,0xA,0xA  \
     ,0xA,0xA,0xA,0xA,0xA,0xA,0xA,0xA,0xA,0xA,0xA,0x50,0x0,0x50,0x0,0x50,0x0,0x50  \
     ,0x0,0x50,0x0,0x50,0x0,0x50,0x0,0x50,0x0,0x50,0x0,0x50,0x0,0x50,0x0,0x50,0x0  \
     ,0x50,0x0,0x50,0x0,0x50,0x0,0x50,0x0,0x50,0x0,0x50,0x0,0x50,0x0,0x50,0x0,0xA  \
     ,0xA,0xA,0xA,0xA,0xA,0xA,0xA,0xA,0xA,0xA,0xA,0xA,0xA,0xA,0xA,0xA,0xA,0xA,0xA  \
     ,0x50,0x0,0x50,0x0,0x50,0x0,0x50,0x0,0x50,0x0,0x50,0x0,0x50,0x0,0x50,0x0,0x50  \
     ,0x0,0x50,0x0,0x50,0x0,0x50,0x0,0x50,0x0,0x50,0x0,0x50,0x0,0x50,0x0,0x50,0x0  \
     ,0x50,0x0,0x50,0x0,0x50,0x0 }
#endif

#define mSERControlEepReadEepGroupGroupSensorCal()\
    DATDbkStartReading(cDATDbkHandleGroupSensorCal)

#define mSERReadU1BitIsEepGroupGroupSensorCalProcessingDefault() \
    DATDbkIsBankProcessing(cDATDbkHandleGroupSensorCal)

#define mSERControlEepUpDateEepGroupGroupSensorCal()\
    DATDbkStartUpdate(cDATDbkHandleGroupSensorCal)

#define mSERReadU1BitIsEepGroupGroupSensorCalWriteOkDefault() \
    DATDbkIsWriteOk(cDATDbkHandleGroupSensorCal)

// Information on the Group GroupSensorCal1
#define cDATPeeNumberOfDataGroupSensorCal1         60 
#define cDATPeeSizeGroupSensorCal1         120 
#ifdef cFormatMotorola
#define mSERPeeResetBufferGroupSensorCal1()        {0x1,0x2C,0x0,0x64,0x0,0x64,0x1  \
     ,0xF4,0x1,0x2C,0x0,0xC8,0x40,0x74,0x1,0x2C,0x0,0xC8,0x4,0xB0,0x1,0x2C,0x0,0xC8  \
     ,0x0,0x64,0x1,0x2C,0x0,0xC8,0x40,0x74,0x1,0x2C,0x0,0xC8,0x1,0x2C,0x0,0xC8,0x0  \
     ,0x64,0x4,0xB0,0x1,0x2C,0x0,0xC8,0x40,0x74,0x1,0x2C,0x0,0xC8,0x4,0xB0,0x1,0x2C  \
     ,0x0,0xC8,0x0,0x64,0x1,0x2C,0x0,0xC8,0x40,0x74,0x1,0x2C,0x0,0xC8,0x4,0xB0,0x1  \
     ,0x2C,0x0,0xC8,0x0,0x64,0x1,0x2C,0x0,0xC8,0x40,0x74,0x1,0x2C,0x0,0xC8,0x4,0xB0  \
     ,0x1,0x2C,0x0,0xC8,0x0,0x64,0x1,0x2C,0x0,0xC8,0x40,0x74,0x1,0x2C,0x0,0xC8,0x4  \
     ,0xB0,0x1,0x2C,0x0,0xC8,0x0,0x64,0x1,0x2C,0x0,0xC8 }
#else
#define mSERPeeResetBufferGroupSensorCal1()        {0x2C,0x1,0x64,0x0,0x64,0x0,0xF4  \
     ,0x1,0x2C,0x1,0xC8,0x0,0x74,0x40,0x2C,0x1,0xC8,0x0,0xB0,0x4,0x2C,0x1,0xC8,0x0  \
     ,0x64,0x0,0x2C,0x1,0xC8,0x0,0x74,0x40,0x2C,0x1,0xC8,0x0,0x2C,0x1,0xC8,0x0,0x64  \
     ,0x0,0xB0,0x4,0x2C,0x1,0xC8,0x0,0x74,0x40,0x2C,0x1,0xC8,0x0,0xB0,0x4,0x2C,0x1  \
     ,0xC8,0x0,0x64,0x0,0x2C,0x1,0xC8,0x0,0x74,0x40,0x2C,0x1,0xC8,0x0,0xB0,0x4,0x2C  \
     ,0x1,0xC8,0x0,0x64,0x0,0x2C,0x1,0xC8,0x0,0x74,0x40,0x2C,0x1,0xC8,0x0,0xB0,0x4  \
     ,0x2C,0x1,0xC8,0x0,0x64,0x0,0x2C,0x1,0xC8,0x0,0x74,0x40,0x2C,0x1,0xC8,0x0,0xB0  \
     ,0x4,0x2C,0x1,0xC8,0x0,0x64,0x0,0x2C,0x1,0xC8,0x0 }
#endif

#define mSERControlEepReadEepGroupGroupSensorCal1()\
    DATDbkStartReading(cDATDbkHandleGroupSensorCal1)

#define mSERReadU1BitIsEepGroupGroupSensorCal1ProcessingDefault() \
    DATDbkIsBankProcessing(cDATDbkHandleGroupSensorCal1)

#define mSERControlEepUpDateEepGroupGroupSensorCal1()\
    DATDbkStartUpdate(cDATDbkHandleGroupSensorCal1)

#define mSERReadU1BitIsEepGroupGroupSensorCal1WriteOkDefault() \
    DATDbkIsWriteOk(cDATDbkHandleGroupSensorCal1)

// Information on the Group GroupSensorCal2
#define cDATPeeNumberOfDataGroupSensorCal2         67 
#define cDATPeeSizeGroupSensorCal2         157 
#ifdef cFormatMotorola
#define mSERPeeResetBufferGroupSensorCal2()        {0x40,0x74,0x1,0x2C,0x0,0xC8,0x4  \
     ,0xB0,0x1,0x2C,0x0,0xC8,0x0,0x64,0x1,0x2C,0x0,0xC8,0x40,0x74,0x1,0x2C,0x0,0xC8  \
     ,0x4,0xB0,0x1,0x2C,0x0,0xC8,0x0,0x64,0x1,0x2C,0x0,0xC8,0x1,0x2C,0x0,0xC8,0x1  \
     ,0x2C,0x0,0xC8,0x40,0x74,0x4,0xB0,0x0,0x64,0x1,0x2C,0x0,0xC8,0x1,0x2C,0x0,0xC8  \
     ,0x1,0x2C,0x0,0xC8,0x40,0x74,0x4,0xB0,0x0,0x64,0x1,0x2C,0x0,0xC8,0x1,0x2C,0x0  \
     ,0xC8,0x1,0x2C,0x0,0xC8,0x40,0x74,0x4,0xB0,0x0,0x64,0x1,0x2C,0x0,0xC8,0x1,0x2C  \
     ,0x0,0xC8,0x1,0x2C,0x0,0xC8,0x40,0x74,0x4,0xB0,0x0,0x64,0x0,0x1,0x78,0x1E,0x0  \
     ,0xA,0xA,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0  \
     ,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0  \
     ,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0 }
#else
#define mSERPeeResetBufferGroupSensorCal2()        {0x74,0x40,0x2C,0x1,0xC8,0x0,0xB0  \
     ,0x4,0x2C,0x1,0xC8,0x0,0x64,0x0,0x2C,0x1,0xC8,0x0,0x74,0x40,0x2C,0x1,0xC8,0x0  \
     ,0xB0,0x4,0x2C,0x1,0xC8,0x0,0x64,0x0,0x2C,0x1,0xC8,0x0,0x2C,0x1,0xC8,0x0,0x2C  \
     ,0x1,0xC8,0x0,0x74,0x40,0xB0,0x4,0x64,0x0,0x2C,0x1,0xC8,0x0,0x2C,0x1,0xC8,0x0  \
     ,0x2C,0x1,0xC8,0x0,0x74,0x40,0xB0,0x4,0x64,0x0,0x2C,0x1,0xC8,0x0,0x2C,0x1,0xC8  \
     ,0x0,0x2C,0x1,0xC8,0x0,0x74,0x40,0xB0,0x4,0x64,0x0,0x2C,0x1,0xC8,0x0,0x2C,0x1  \
     ,0xC8,0x0,0x2C,0x1,0xC8,0x0,0x74,0x40,0xB0,0x4,0x64,0x0,0x0,0x1,0x78,0x1E,0x0  \
     ,0xA,0xA,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0  \
     ,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0  \
     ,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0 }
#endif

#define mSERControlEepReadEepGroupGroupSensorCal2()\
    DATDbkStartReading(cDATDbkHandleGroupSensorCal2)

#define mSERReadU1BitIsEepGroupGroupSensorCal2ProcessingDefault() \
    DATDbkIsBankProcessing(cDATDbkHandleGroupSensorCal2)

#define mSERControlEepUpDateEepGroupGroupSensorCal2()\
    DATDbkStartUpdate(cDATDbkHandleGroupSensorCal2)

#define mSERReadU1BitIsEepGroupGroupSensorCal2WriteOkDefault() \
    DATDbkIsWriteOk(cDATDbkHandleGroupSensorCal2)

// Information on the Group GroupReset
#define cDATPeeNumberOfDataGroupReset         5 
#define cDATPeeSizeGroupReset         5 
#ifdef cFormatMotorola
#define mSERPeeResetBufferGroupReset()        {0x0,0x0,0x0,0x0,0x0 }
#else
#define mSERPeeResetBufferGroupReset()        {0x0,0x0,0x0,0x0,0x0 }
#endif

#define mSERControlEepReadEepGroupGroupReset()\
    DATSbkStartReading(cDATSbkHandleGroupReset)

#define mSERReadU1BitIsEepGroupGroupResetProcessingDefault() \
    DATSbkIsBankProcessing(cDATSbkHandleGroupReset)

#define mSERControlEepUpDateEepGroupGroupReset()\
    DATSbkStartUpdate(cDATSbkHandleGroupReset)

#define mSERReadU1BitIsEepGroupGroupResetWriteOkDefault() \
    DATSbkIsWriteOk(cDATSbkHandleGroupReset)

// Information on the Group GroupSbkReadOnly1
#define cDATPeeNumberOfDataGroupSbkReadOnly1         20 
#define cDATPeeSizeGroupSbkReadOnly1         80 
#ifdef cFormatMotorola
#define mSERPeeResetBufferGroupSbkReadOnly1()        {0x0,0x0,0x0,0x0,0x0,0x0,0x0  \
     ,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0  \
     ,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0  \
     ,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0  \
     ,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0 }
#else
#define mSERPeeResetBufferGroupSbkReadOnly1()        {0x0,0x0,0x0,0x0,0x0,0x0,0x0  \
     ,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0  \
     ,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0  \
     ,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0  \
     ,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0 }
#endif

#define mSERControlEepReadEepGroupGroupSbkReadOnly1()\
    DATSbkStartReading(cDATSbkHandleGroupSbkReadOnly1)

#define mSERReadU1BitIsEepGroupGroupSbkReadOnly1ProcessingDefault() \
    DATSbkIsBankProcessing(cDATSbkHandleGroupSbkReadOnly1)

#define mSERControlEepUpDateEepGroupGroupSbkReadOnly1()\
    DATSbkStartUpdate(cDATSbkHandleGroupSbkReadOnly1)

#define mSERReadU1BitIsEepGroupGroupSbkReadOnly1WriteOkDefault() \
    DATSbkIsWriteOk(cDATSbkHandleGroupSbkReadOnly1)

// Information on the Group GroupSbkReadOnly2
#define cDATPeeNumberOfDataGroupSbkReadOnly2         1 
#define cDATPeeSizeGroupSbkReadOnly2         4 
#ifdef cFormatMotorola
#define mSERPeeResetBufferGroupSbkReadOnly2()        {0x0,0x0,0x0,0x0 }
#else
#define mSERPeeResetBufferGroupSbkReadOnly2()        {0x0,0x0,0x0,0x0 }
#endif

#define mSERControlEepReadEepGroupGroupSbkReadOnly2()\
    DATSbkStartReading(cDATSbkHandleGroupSbkReadOnly2)

#define mSERReadU1BitIsEepGroupGroupSbkReadOnly2ProcessingDefault() \
    DATSbkIsBankProcessing(cDATSbkHandleGroupSbkReadOnly2)

#define mSERControlEepUpDateEepGroupGroupSbkReadOnly2()\
    DATSbkStartUpdate(cDATSbkHandleGroupSbkReadOnly2)

#define mSERReadU1BitIsEepGroupGroupSbkReadOnly2WriteOkDefault() \
    DATSbkIsWriteOk(cDATSbkHandleGroupSbkReadOnly2)

// Information on the Group GroupBCMCfg0
#define cDATPeeNumberOfDataGroupBCMCfg0         1 
#define cDATPeeSizeGroupBCMCfg0         1 
#ifdef cFormatMotorola
#define mSERPeeResetBufferGroupBCMCfg0()        {0x0 }
#else
#define mSERPeeResetBufferGroupBCMCfg0()        {0x0 }
#endif

#define mSERControlEepReadEepGroupGroupBCMCfg0()\
    DATSbkStartReading(cDATSbkHandleGroupBCMCfg0)

#define mSERReadU1BitIsEepGroupGroupBCMCfg0ProcessingDefault() \
    DATSbkIsBankProcessing(cDATSbkHandleGroupBCMCfg0)

#define mSERControlEepUpDateEepGroupGroupBCMCfg0()\
    DATSbkStartUpdate(cDATSbkHandleGroupBCMCfg0)

#define mSERReadU1BitIsEepGroupGroupBCMCfg0WriteOkDefault() \
    DATSbkIsWriteOk(cDATSbkHandleGroupBCMCfg0)

// Information on the Group GroupBCMCfg1
#define cDATPeeNumberOfDataGroupBCMCfg1         1 
#define cDATPeeSizeGroupBCMCfg1         1 
#ifdef cFormatMotorola
#define mSERPeeResetBufferGroupBCMCfg1()        {0x0 }
#else
#define mSERPeeResetBufferGroupBCMCfg1()        {0x0 }
#endif

#define mSERControlEepReadEepGroupGroupBCMCfg1()\
    DATSbkStartReading(cDATSbkHandleGroupBCMCfg1)

#define mSERReadU1BitIsEepGroupGroupBCMCfg1ProcessingDefault() \
    DATSbkIsBankProcessing(cDATSbkHandleGroupBCMCfg1)

#define mSERControlEepUpDateEepGroupGroupBCMCfg1()\
    DATSbkStartUpdate(cDATSbkHandleGroupBCMCfg1)

#define mSERReadU1BitIsEepGroupGroupBCMCfg1WriteOkDefault() \
    DATSbkIsWriteOk(cDATSbkHandleGroupBCMCfg1)

// Information on the Group GroupBCMCfg2
#define cDATPeeNumberOfDataGroupBCMCfg2         1 
#define cDATPeeSizeGroupBCMCfg2         1 
#ifdef cFormatMotorola
#define mSERPeeResetBufferGroupBCMCfg2()        {0x0 }
#else
#define mSERPeeResetBufferGroupBCMCfg2()        {0x0 }
#endif

#define mSERControlEepReadEepGroupGroupBCMCfg2()\
    DATSbkStartReading(cDATSbkHandleGroupBCMCfg2)

#define mSERReadU1BitIsEepGroupGroupBCMCfg2ProcessingDefault() \
    DATSbkIsBankProcessing(cDATSbkHandleGroupBCMCfg2)

#define mSERControlEepUpDateEepGroupGroupBCMCfg2()\
    DATSbkStartUpdate(cDATSbkHandleGroupBCMCfg2)

#define mSERReadU1BitIsEepGroupGroupBCMCfg2WriteOkDefault() \
    DATSbkIsWriteOk(cDATSbkHandleGroupBCMCfg2)

// Information on the Group GroupBCMCfg3
#define cDATPeeNumberOfDataGroupBCMCfg3         1 
#define cDATPeeSizeGroupBCMCfg3         1 
#ifdef cFormatMotorola
#define mSERPeeResetBufferGroupBCMCfg3()        {0x0 }
#else
#define mSERPeeResetBufferGroupBCMCfg3()        {0x0 }
#endif

#define mSERControlEepReadEepGroupGroupBCMCfg3()\
    DATSbkStartReading(cDATSbkHandleGroupBCMCfg3)

#define mSERReadU1BitIsEepGroupGroupBCMCfg3ProcessingDefault() \
    DATSbkIsBankProcessing(cDATSbkHandleGroupBCMCfg3)

#define mSERControlEepUpDateEepGroupGroupBCMCfg3()\
    DATSbkStartUpdate(cDATSbkHandleGroupBCMCfg3)

#define mSERReadU1BitIsEepGroupGroupBCMCfg3WriteOkDefault() \
    DATSbkIsWriteOk(cDATSbkHandleGroupBCMCfg3)

// Information on the Group GroupEEPInitCtrl
#define cDATPeeNumberOfDataGroupEEPInitCtrl         6 
#define cDATPeeSizeGroupEEPInitCtrl         8 
#ifdef cFormatMotorola
#define mSERPeeResetBufferGroupEEPInitCtrl()        {0x0,0x0,0xCA,0x55,0x55,0xBA,0x55  \
     ,0x0 }
#else
#define mSERPeeResetBufferGroupEEPInitCtrl()        {0x0,0x0,0x55,0xCA,0xBA,0x55,0x55  \
     ,0x0 }
#endif

#define mSERControlEepReadEepGroupGroupEEPInitCtrl()\
    DATSbkStartReading(cDATSbkHandleGroupEEPInitCtrl)

#define mSERReadU1BitIsEepGroupGroupEEPInitCtrlProcessingDefault() \
    DATSbkIsBankProcessing(cDATSbkHandleGroupEEPInitCtrl)

#define mSERControlEepUpDateEepGroupGroupEEPInitCtrl()\
    DATSbkStartUpdate(cDATSbkHandleGroupEEPInitCtrl)

#define mSERReadU1BitIsEepGroupGroupEEPInitCtrlWriteOkDefault() \
    DATSbkIsWriteOk(cDATSbkHandleGroupEEPInitCtrl)


//--------------------------------------------------------------------------
// Functionnal data declaration
//--------------------------------------------------------------------------

// EEPErrorTable -- Group ErrorGroup, Byte  0  , Bit (MSB)  7  , SizeInBit  176 
#ifdef EEPErrorTable
  #error "Do not define EEPErrorTable, because this is a lexem used for concatenation."
#endif
#define mSERPeeResetEEPErrorTable()     \
{                                                     \
   mSERPeeWriteTable(U8Bit,Sbk,ErrorGroup,  0 ,  0, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,ErrorGroup,  0 ,  1, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,ErrorGroup,  0 ,  2, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,ErrorGroup,  0 ,  3, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,ErrorGroup,  0 ,  4, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,ErrorGroup,  0 ,  5, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,ErrorGroup,  0 ,  6, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,ErrorGroup,  0 ,  7, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,ErrorGroup,  0 ,  8, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,ErrorGroup,  0 ,  9, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,ErrorGroup,  0 ,  10, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,ErrorGroup,  0 ,  11, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,ErrorGroup,  0 ,  12, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,ErrorGroup,  0 ,  13, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,ErrorGroup,  0 ,  14, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,ErrorGroup,  0 ,  15, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,ErrorGroup,  0 ,  16, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,ErrorGroup,  0 ,  17, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,ErrorGroup,  0 ,  18, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,ErrorGroup,  0 ,  19, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,ErrorGroup,  0 ,  20, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,ErrorGroup,  0 ,  21, 0, Delayed) \
}
#define mSERReadTableU1BitEEPErrorTableDefaultValueDefault( Index ) \
      mSERPeeReadDefaultTable(U1Bit,Sbk, ErrorGroup,  0 , Index, Delayed)

#define mSERReadTableU8BitEEPErrorTableDefault( Index ) \
      mSERPeeReadTable(U8Bit,Sbk, ErrorGroup,  0 , Index, Delayed)
#define mSERWriteTableU8BitEEPErrorTableDelayed( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Sbk, ErrorGroup,  0 , Index, (ValueToWrite), Delayed)
#define mSERWriteTableU8BitEEPErrorTableImmediate( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Sbk, ErrorGroup,  0 , Index, (ValueToWrite), Immediate)
#define mSERWriteTableU8BitEEPErrorTableDefault( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Sbk, ErrorGroup,  0 , Index, (ValueToWrite), Immediate)

// EEP_ECUPartNumber -- Group GroupTraceability, Byte  0  , Bit (MSB)  7  , SizeInBit  80 
#ifdef EEP_ECUPartNumber
  #error "Do not define EEP_ECUPartNumber, because this is a lexem used for concatenation."
#endif
#define mSERPeeResetEEP_ECUPartNumber()     \
{                                                     \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  0 ,  0, 3, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  0 ,  1, 130, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  0 ,  2, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  0 ,  3, 34, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  0 ,  4, 149, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  0 ,  5, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  0 ,  6, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  0 ,  7, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  0 ,  8, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  0 ,  9, 0, Delayed) \
}
#define mSERReadTableU1BitEEP_ECUPartNumberDefaultValueDefault( Index ) \
      mSERPeeReadDefaultTable(U1Bit,Sbk, GroupTraceability,  0 , Index, Delayed)

#define mSERReadTableU8BitEEP_ECUPartNumberDefault( Index ) \
      mSERPeeReadTable(U8Bit,Sbk, GroupTraceability,  0 , Index, Delayed)
#define mSERWriteTableU8BitEEP_ECUPartNumberDelayed( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Sbk, GroupTraceability,  0 , Index, (ValueToWrite), Delayed)
#define mSERWriteTableU8BitEEP_ECUPartNumberImmediate( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Sbk, GroupTraceability,  0 , Index, (ValueToWrite), Immediate)
#define mSERWriteTableU8BitEEP_ECUPartNumberDefault( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Sbk, GroupTraceability,  0 , Index, (ValueToWrite), Immediate)

// EEP_SystemSupplierID -- Group GroupTraceability, Byte  10  , Bit (MSB)  7  , SizeInBit  40 
#ifdef EEP_SystemSupplierID
  #error "Do not define EEP_SystemSupplierID, because this is a lexem used for concatenation."
#endif
#define mSERPeeResetEEP_SystemSupplierID()     \
{                                                     \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  10 ,  0, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  10 ,  1, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  10 ,  2, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  10 ,  3, 113, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  10 ,  4, 32, Delayed) \
}
#define mSERReadTableU1BitEEP_SystemSupplierIDDefaultValueDefault( Index ) \
      mSERPeeReadDefaultTable(U1Bit,Sbk, GroupTraceability,  10 , Index, Delayed)

#define mSERReadTableU8BitEEP_SystemSupplierIDDefault( Index ) \
      mSERPeeReadTable(U8Bit,Sbk, GroupTraceability,  10 , Index, Delayed)
#define mSERWriteTableU8BitEEP_SystemSupplierIDDelayed( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Sbk, GroupTraceability,  10 , Index, (ValueToWrite), Delayed)
#define mSERWriteTableU8BitEEP_SystemSupplierIDImmediate( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Sbk, GroupTraceability,  10 , Index, (ValueToWrite), Immediate)
#define mSERWriteTableU8BitEEP_SystemSupplierIDDefault( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Sbk, GroupTraceability,  10 , Index, (ValueToWrite), Immediate)

// EEP_ECUManufacturingDate -- Group GroupTraceability, Byte  15  , Bit (MSB)  7  , SizeInBit  48 
#ifdef EEP_ECUManufacturingDate
  #error "Do not define EEP_ECUManufacturingDate, because this is a lexem used for concatenation."
#endif
#define mSERPeeResetEEP_ECUManufacturingDate()     \
{                                                     \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  15 ,  0, 32, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  15 ,  1, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  15 ,  2, 1, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  15 ,  3, 1, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  15 ,  4, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  15 ,  5, 0, Delayed) \
}
#define mSERReadTableU1BitEEP_ECUManufacturingDateDefaultValueDefault( Index ) \
      mSERPeeReadDefaultTable(U1Bit,Sbk, GroupTraceability,  15 , Index, Delayed)

#define mSERReadTableU8BitEEP_ECUManufacturingDateDefault( Index ) \
      mSERPeeReadTable(U8Bit,Sbk, GroupTraceability,  15 , Index, Delayed)
#define mSERWriteTableU8BitEEP_ECUManufacturingDateDelayed( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Sbk, GroupTraceability,  15 , Index, (ValueToWrite), Delayed)
#define mSERWriteTableU8BitEEP_ECUManufacturingDateImmediate( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Sbk, GroupTraceability,  15 , Index, (ValueToWrite), Immediate)
#define mSERWriteTableU8BitEEP_ECUManufacturingDateDefault( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Sbk, GroupTraceability,  15 , Index, (ValueToWrite), Immediate)

// EEP_ECUSerialNumber -- Group GroupTraceability, Byte  21  , Bit (MSB)  7  , SizeInBit  128 
#ifdef EEP_ECUSerialNumber
  #error "Do not define EEP_ECUSerialNumber, because this is a lexem used for concatenation."
#endif
#define mSERPeeResetEEP_ECUSerialNumber()     \
{                                                     \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  21 ,  0, 49, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  21 ,  1, 50, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  21 ,  2, 51, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  21 ,  3, 52, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  21 ,  4, 53, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  21 ,  5, 54, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  21 ,  6, 55, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  21 ,  7, 56, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  21 ,  8, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  21 ,  9, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  21 ,  10, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  21 ,  11, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  21 ,  12, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  21 ,  13, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  21 ,  14, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  21 ,  15, 0, Delayed) \
}
#define mSERReadTableU1BitEEP_ECUSerialNumberDefaultValueDefault( Index ) \
      mSERPeeReadDefaultTable(U1Bit,Sbk, GroupTraceability,  21 , Index, Delayed)

#define mSERReadTableU8BitEEP_ECUSerialNumberDefault( Index ) \
      mSERPeeReadTable(U8Bit,Sbk, GroupTraceability,  21 , Index, Delayed)
#define mSERWriteTableU8BitEEP_ECUSerialNumberDelayed( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Sbk, GroupTraceability,  21 , Index, (ValueToWrite), Delayed)
#define mSERWriteTableU8BitEEP_ECUSerialNumberImmediate( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Sbk, GroupTraceability,  21 , Index, (ValueToWrite), Immediate)
#define mSERWriteTableU8BitEEP_ECUSerialNumberDefault( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Sbk, GroupTraceability,  21 , Index, (ValueToWrite), Immediate)

// EEP_SystemSupplierECUHardwareNumber -- Group GroupTraceability, Byte  37  , Bit (MSB)  7  , SizeInBit  64 
#ifdef EEP_SystemSupplierECUHardwareNumber
  #error "Do not define EEP_SystemSupplierECUHardwareNumber, because this is a lexem used for concatenation."
#endif
#define mSERPeeResetEEP_SystemSupplierECUHardwareNumber()     \
{                                                     \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  37 ,  0, 32, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  37 ,  1, 32, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  37 ,  2, 32, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  37 ,  3, 32, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  37 ,  4, 32, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  37 ,  5, 32, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  37 ,  6, 32, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  37 ,  7, 32, Delayed) \
}
#define mSERReadTableU1BitEEP_SystemSupplierECUHardwareNumberDefaultValueDefault( Index ) \
      mSERPeeReadDefaultTable(U1Bit,Sbk, GroupTraceability,  37 , Index, Delayed)

#define mSERReadTableU8BitEEP_SystemSupplierECUHardwareNumberDefault( Index ) \
      mSERPeeReadTable(U8Bit,Sbk, GroupTraceability,  37 , Index, Delayed)
#define mSERWriteTableU8BitEEP_SystemSupplierECUHardwareNumberDelayed( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Sbk, GroupTraceability,  37 , Index, (ValueToWrite), Delayed)
#define mSERWriteTableU8BitEEP_SystemSupplierECUHardwareNumberImmediate( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Sbk, GroupTraceability,  37 , Index, (ValueToWrite), Immediate)
#define mSERWriteTableU8BitEEP_SystemSupplierECUHardwareNumberDefault( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Sbk, GroupTraceability,  37 , Index, (ValueToWrite), Immediate)

// EEP_HWVersion -- Group GroupTraceability, Byte  45  , Bit (MSB)  7  , SizeInBit  64 
#ifdef EEP_HWVersion
  #error "Do not define EEP_HWVersion, because this is a lexem used for concatenation."
#endif
#define mSERPeeResetEEP_HWVersion()     \
{                                                     \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  45 ,  0, 86, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  45 ,  1, 48, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  45 ,  2, 49, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  45 ,  3, 66, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  45 ,  4, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  45 ,  5, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  45 ,  6, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  45 ,  7, 0, Delayed) \
}
#define mSERReadTableU1BitEEP_HWVersionDefaultValueDefault( Index ) \
      mSERPeeReadDefaultTable(U1Bit,Sbk, GroupTraceability,  45 , Index, Delayed)

#define mSERReadTableU8BitEEP_HWVersionDefault( Index ) \
      mSERPeeReadTable(U8Bit,Sbk, GroupTraceability,  45 , Index, Delayed)
#define mSERWriteTableU8BitEEP_HWVersionDelayed( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Sbk, GroupTraceability,  45 , Index, (ValueToWrite), Delayed)
#define mSERWriteTableU8BitEEP_HWVersionImmediate( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Sbk, GroupTraceability,  45 , Index, (ValueToWrite), Immediate)
#define mSERWriteTableU8BitEEP_HWVersionDefault( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Sbk, GroupTraceability,  45 , Index, (ValueToWrite), Immediate)

// EEP_HWRevision -- Group GroupTraceability, Byte  53  , Bit (MSB)  7  , SizeInBit  8 
#ifdef EEP_HWRevision
  #error "Do not define EEP_HWRevision, because this is a lexem used for concatenation."
#endif
#define cDATEEP_HWRevisionPositionByte      53 
#define cDATEEP_HWRevisionPositionBit        0xFF
#define mSERPeeResetU8BitEEP_HWRevision()     \
      mSERPeeWriteU8Bit(Sbk, GroupTraceability,  53 ,  7 ,  8 , 0, Delayed)
#define mSERReadU8BitEEP_HWRevisionDefaultValueDefault() ((U8)0)
#define mSERReadU8BitEEP_HWRevisionDefault() \
      mSERPeeReadU8Bit(Sbk, GroupTraceability,  53 ,  7 ,  8 , Delayed)
#define mSERWriteU8BitEEP_HWRevisionDelayed(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupTraceability,  53 ,  7 ,  8 , (ValueToWrite), Delayed)
#define mSERWriteU8BitEEP_HWRevisionImmediate(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupTraceability,  53 ,  7 ,  8 , (ValueToWrite), Immediate)
#define mSERWriteU8BitEEP_HWRevisionDefault(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupTraceability,  53 ,  7 ,  8 , (ValueToWrite), Immediate)

// EEP_SWFingerPrintDataID -- Group GroupTraceability, Byte  54  , Bit (MSB)  7  , SizeInBit  104 
#ifdef EEP_SWFingerPrintDataID
  #error "Do not define EEP_SWFingerPrintDataID, because this is a lexem used for concatenation."
#endif
#define mSERPeeResetEEP_SWFingerPrintDataID()     \
{                                                     \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  54 ,  0, 32, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  54 ,  1, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  54 ,  2, 1, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  54 ,  3, 1, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  54 ,  4, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  54 ,  5, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  54 ,  6, 255, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  54 ,  7, 255, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  54 ,  8, 255, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  54 ,  9, 255, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  54 ,  10, 255, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  54 ,  11, 255, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  54 ,  12, 255, Delayed) \
}
#define mSERReadTableU1BitEEP_SWFingerPrintDataIDDefaultValueDefault( Index ) \
      mSERPeeReadDefaultTable(U1Bit,Sbk, GroupTraceability,  54 , Index, Delayed)

#define mSERReadTableU8BitEEP_SWFingerPrintDataIDDefault( Index ) \
      mSERPeeReadTable(U8Bit,Sbk, GroupTraceability,  54 , Index, Delayed)
#define mSERWriteTableU8BitEEP_SWFingerPrintDataIDDelayed( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Sbk, GroupTraceability,  54 , Index, (ValueToWrite), Delayed)
#define mSERWriteTableU8BitEEP_SWFingerPrintDataIDImmediate( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Sbk, GroupTraceability,  54 , Index, (ValueToWrite), Immediate)
#define mSERWriteTableU8BitEEP_SWFingerPrintDataIDDefault( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Sbk, GroupTraceability,  54 , Index, (ValueToWrite), Immediate)

// EEP_DataFingerPrintDataID -- Group GroupTraceability, Byte  67  , Bit (MSB)  7  , SizeInBit  104 
#ifdef EEP_DataFingerPrintDataID
  #error "Do not define EEP_DataFingerPrintDataID, because this is a lexem used for concatenation."
#endif
#define mSERPeeResetEEP_DataFingerPrintDataID()     \
{                                                     \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  67 ,  0, 32, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  67 ,  1, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  67 ,  2, 1, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  67 ,  3, 1, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  67 ,  4, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  67 ,  5, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  67 ,  6, 255, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  67 ,  7, 255, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  67 ,  8, 255, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  67 ,  9, 255, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  67 ,  10, 255, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  67 ,  11, 255, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  67 ,  12, 255, Delayed) \
}
#define mSERReadTableU1BitEEP_DataFingerPrintDataIDDefaultValueDefault( Index ) \
      mSERPeeReadDefaultTable(U1Bit,Sbk, GroupTraceability,  67 , Index, Delayed)

#define mSERReadTableU8BitEEP_DataFingerPrintDataIDDefault( Index ) \
      mSERPeeReadTable(U8Bit,Sbk, GroupTraceability,  67 , Index, Delayed)
#define mSERWriteTableU8BitEEP_DataFingerPrintDataIDDelayed( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Sbk, GroupTraceability,  67 , Index, (ValueToWrite), Delayed)
#define mSERWriteTableU8BitEEP_DataFingerPrintDataIDImmediate( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Sbk, GroupTraceability,  67 , Index, (ValueToWrite), Immediate)
#define mSERWriteTableU8BitEEP_DataFingerPrintDataIDDefault( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Sbk, GroupTraceability,  67 , Index, (ValueToWrite), Immediate)

// EEP_EEPROMVersion -- Group GroupTraceability, Byte  80  , Bit (MSB)  7  , SizeInBit  8 
#ifdef EEP_EEPROMVersion
  #error "Do not define EEP_EEPROMVersion, because this is a lexem used for concatenation."
#endif
#define cDATEEP_EEPROMVersionPositionByte      80 
#define cDATEEP_EEPROMVersionPositionBit        0xFF
#define mSERPeeResetU8BitEEP_EEPROMVersion()     \
      mSERPeeWriteU8Bit(Sbk, GroupTraceability,  80 ,  7 ,  8 , 1, Delayed)
#define mSERReadU8BitEEP_EEPROMVersionDefaultValueDefault() ((U8)1)
#define mSERReadU8BitEEP_EEPROMVersionDefault() \
      mSERPeeReadU8Bit(Sbk, GroupTraceability,  80 ,  7 ,  8 , Delayed)
#define mSERWriteU8BitEEP_EEPROMVersionDelayed(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupTraceability,  80 ,  7 ,  8 , (ValueToWrite), Delayed)
#define mSERWriteU8BitEEP_EEPROMVersionImmediate(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupTraceability,  80 ,  7 ,  8 , (ValueToWrite), Immediate)
#define mSERWriteU8BitEEP_EEPROMVersionDefault(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupTraceability,  80 ,  7 ,  8 , (ValueToWrite), Immediate)

// EEP_EEPROMRevision -- Group GroupTraceability, Byte  81  , Bit (MSB)  7  , SizeInBit  8 
#ifdef EEP_EEPROMRevision
  #error "Do not define EEP_EEPROMRevision, because this is a lexem used for concatenation."
#endif
#define cDATEEP_EEPROMRevisionPositionByte      81 
#define cDATEEP_EEPROMRevisionPositionBit        0xFF
#define mSERPeeResetU8BitEEP_EEPROMRevision()     \
      mSERPeeWriteU8Bit(Sbk, GroupTraceability,  81 ,  7 ,  8 , 0, Delayed)
#define mSERReadU8BitEEP_EEPROMRevisionDefaultValueDefault() ((U8)0)
#define mSERReadU8BitEEP_EEPROMRevisionDefault() \
      mSERPeeReadU8Bit(Sbk, GroupTraceability,  81 ,  7 ,  8 , Delayed)
#define mSERWriteU8BitEEP_EEPROMRevisionDelayed(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupTraceability,  81 ,  7 ,  8 , (ValueToWrite), Delayed)
#define mSERWriteU8BitEEP_EEPROMRevisionImmediate(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupTraceability,  81 ,  7 ,  8 , (ValueToWrite), Immediate)
#define mSERWriteU8BitEEP_EEPROMRevisionDefault(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupTraceability,  81 ,  7 ,  8 , (ValueToWrite), Immediate)

// EEP_ManfactureSerialNumL -- Group GroupTraceability, Byte  82  , Bit (MSB)  7  , SizeInBit  8 
#ifdef EEP_ManfactureSerialNumL
  #error "Do not define EEP_ManfactureSerialNumL, because this is a lexem used for concatenation."
#endif
#define cDATEEP_ManfactureSerialNumLPositionByte      82 
#define cDATEEP_ManfactureSerialNumLPositionBit        0xFF
#define mSERPeeResetU8BitEEP_ManfactureSerialNumL()     \
      mSERPeeWriteU8Bit(Sbk, GroupTraceability,  82 ,  7 ,  8 , 0, Delayed)
#define mSERReadU8BitEEP_ManfactureSerialNumLDefaultValueDefault() ((U8)0)
#define mSERReadU8BitEEP_ManfactureSerialNumLDefault() \
      mSERPeeReadU8Bit(Sbk, GroupTraceability,  82 ,  7 ,  8 , Delayed)
#define mSERWriteU8BitEEP_ManfactureSerialNumLDelayed(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupTraceability,  82 ,  7 ,  8 , (ValueToWrite), Delayed)
#define mSERWriteU8BitEEP_ManfactureSerialNumLImmediate(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupTraceability,  82 ,  7 ,  8 , (ValueToWrite), Immediate)
#define mSERWriteU8BitEEP_ManfactureSerialNumLDefault(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupTraceability,  82 ,  7 ,  8 , (ValueToWrite), Immediate)

// EEP_ManfactureSerialNumH -- Group GroupTraceability, Byte  83  , Bit (MSB)  7  , SizeInBit  8 
#ifdef EEP_ManfactureSerialNumH
  #error "Do not define EEP_ManfactureSerialNumH, because this is a lexem used for concatenation."
#endif
#define cDATEEP_ManfactureSerialNumHPositionByte      83 
#define cDATEEP_ManfactureSerialNumHPositionBit        0xFF
#define mSERPeeResetU8BitEEP_ManfactureSerialNumH()     \
      mSERPeeWriteU8Bit(Sbk, GroupTraceability,  83 ,  7 ,  8 , 0, Delayed)
#define mSERReadU8BitEEP_ManfactureSerialNumHDefaultValueDefault() ((U8)0)
#define mSERReadU8BitEEP_ManfactureSerialNumHDefault() \
      mSERPeeReadU8Bit(Sbk, GroupTraceability,  83 ,  7 ,  8 , Delayed)
#define mSERWriteU8BitEEP_ManfactureSerialNumHDelayed(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupTraceability,  83 ,  7 ,  8 , (ValueToWrite), Delayed)
#define mSERWriteU8BitEEP_ManfactureSerialNumHImmediate(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupTraceability,  83 ,  7 ,  8 , (ValueToWrite), Immediate)
#define mSERWriteU8BitEEP_ManfactureSerialNumHDefault(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupTraceability,  83 ,  7 ,  8 , (ValueToWrite), Immediate)

// EEP_ProductModelType -- Group GroupTraceability, Byte  84  , Bit (MSB)  7  , SizeInBit  128 
#ifdef EEP_ProductModelType
  #error "Do not define EEP_ProductModelType, because this is a lexem used for concatenation."
#endif
#define mSERPeeResetEEP_ProductModelType()     \
{                                                     \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  84 ,  0, 32, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  84 ,  1, 32, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  84 ,  2, 32, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  84 ,  3, 32, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  84 ,  4, 32, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  84 ,  5, 32, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  84 ,  6, 32, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  84 ,  7, 32, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  84 ,  8, 32, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  84 ,  9, 32, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  84 ,  10, 32, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  84 ,  11, 32, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  84 ,  12, 32, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  84 ,  13, 32, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  84 ,  14, 32, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  84 ,  15, 32, Delayed) \
}
#define mSERReadTableU1BitEEP_ProductModelTypeDefaultValueDefault( Index ) \
      mSERPeeReadDefaultTable(U1Bit,Sbk, GroupTraceability,  84 , Index, Delayed)

#define mSERReadTableU8BitEEP_ProductModelTypeDefault( Index ) \
      mSERPeeReadTable(U8Bit,Sbk, GroupTraceability,  84 , Index, Delayed)
#define mSERWriteTableU8BitEEP_ProductModelTypeDelayed( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Sbk, GroupTraceability,  84 , Index, (ValueToWrite), Delayed)
#define mSERWriteTableU8BitEEP_ProductModelTypeImmediate( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Sbk, GroupTraceability,  84 , Index, (ValueToWrite), Immediate)
#define mSERWriteTableU8BitEEP_ProductModelTypeDefault( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Sbk, GroupTraceability,  84 , Index, (ValueToWrite), Immediate)

// EEP_GroupTraceabilityReservedData2 -- Group GroupTraceability, Byte  100  , Bit (MSB)  7  , SizeInBit  8 
#ifdef EEP_GroupTraceabilityReservedData2
  #error "Do not define EEP_GroupTraceabilityReservedData2, because this is a lexem used for concatenation."
#endif
#define cDATEEP_GroupTraceabilityReservedData2PositionByte      100 
#define cDATEEP_GroupTraceabilityReservedData2PositionBit        0xFF
#define mSERPeeResetU8BitEEP_GroupTraceabilityReservedData2()     \
      mSERPeeWriteU8Bit(Sbk, GroupTraceability,  100 ,  7 ,  8 , 0, Delayed)
#define mSERReadU8BitEEP_GroupTraceabilityReservedData2DefaultValueDefault() ((U8)0)
#define mSERReadU8BitEEP_GroupTraceabilityReservedData2Default() \
      mSERPeeReadU8Bit(Sbk, GroupTraceability,  100 ,  7 ,  8 , Delayed)
#define mSERWriteU8BitEEP_GroupTraceabilityReservedData2Delayed(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupTraceability,  100 ,  7 ,  8 , (ValueToWrite), Delayed)
#define mSERWriteU8BitEEP_GroupTraceabilityReservedData2Immediate(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupTraceability,  100 ,  7 ,  8 , (ValueToWrite), Immediate)
#define mSERWriteU8BitEEP_GroupTraceabilityReservedData2Default(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupTraceability,  100 ,  7 ,  8 , (ValueToWrite), Immediate)

// EEP_ProductModelOutLookFuncCode -- Group GroupTraceability, Byte  101  , Bit (MSB)  7  , SizeInBit  8 
#ifdef EEP_ProductModelOutLookFuncCode
  #error "Do not define EEP_ProductModelOutLookFuncCode, because this is a lexem used for concatenation."
#endif
#define cDATEEP_ProductModelOutLookFuncCodePositionByte      101 
#define cDATEEP_ProductModelOutLookFuncCodePositionBit        0xFF
#define mSERPeeResetU8BitEEP_ProductModelOutLookFuncCode()     \
      mSERPeeWriteU8Bit(Sbk, GroupTraceability,  101 ,  7 ,  8 , 0, Delayed)
#define mSERReadU8BitEEP_ProductModelOutLookFuncCodeDefaultValueDefault() ((U8)0)
#define mSERReadU8BitEEP_ProductModelOutLookFuncCodeDefault() \
      mSERPeeReadU8Bit(Sbk, GroupTraceability,  101 ,  7 ,  8 , Delayed)
#define mSERWriteU8BitEEP_ProductModelOutLookFuncCodeDelayed(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupTraceability,  101 ,  7 ,  8 , (ValueToWrite), Delayed)
#define mSERWriteU8BitEEP_ProductModelOutLookFuncCodeImmediate(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupTraceability,  101 ,  7 ,  8 , (ValueToWrite), Immediate)
#define mSERWriteU8BitEEP_ProductModelOutLookFuncCodeDefault(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupTraceability,  101 ,  7 ,  8 , (ValueToWrite), Immediate)

// EEP_ProductModelOutLookFuncNum -- Group GroupTraceability, Byte  102  , Bit (MSB)  7  , SizeInBit  8 
#ifdef EEP_ProductModelOutLookFuncNum
  #error "Do not define EEP_ProductModelOutLookFuncNum, because this is a lexem used for concatenation."
#endif
#define cDATEEP_ProductModelOutLookFuncNumPositionByte      102 
#define cDATEEP_ProductModelOutLookFuncNumPositionBit        0xFF
#define mSERPeeResetU8BitEEP_ProductModelOutLookFuncNum()     \
      mSERPeeWriteU8Bit(Sbk, GroupTraceability,  102 ,  7 ,  8 , 1, Delayed)
#define mSERReadU8BitEEP_ProductModelOutLookFuncNumDefaultValueDefault() ((U8)1)
#define mSERReadU8BitEEP_ProductModelOutLookFuncNumDefault() \
      mSERPeeReadU8Bit(Sbk, GroupTraceability,  102 ,  7 ,  8 , Delayed)
#define mSERWriteU8BitEEP_ProductModelOutLookFuncNumDelayed(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupTraceability,  102 ,  7 ,  8 , (ValueToWrite), Delayed)
#define mSERWriteU8BitEEP_ProductModelOutLookFuncNumImmediate(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupTraceability,  102 ,  7 ,  8 , (ValueToWrite), Immediate)
#define mSERWriteU8BitEEP_ProductModelOutLookFuncNumDefault(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupTraceability,  102 ,  7 ,  8 , (ValueToWrite), Immediate)

// EEP_VINCode -- Group GroupTraceability, Byte  103  , Bit (MSB)  7  , SizeInBit  136 
#ifdef EEP_VINCode
  #error "Do not define EEP_VINCode, because this is a lexem used for concatenation."
#endif
#define mSERPeeResetEEP_VINCode()     \
{                                                     \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  103 ,  0, 32, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  103 ,  1, 32, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  103 ,  2, 32, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  103 ,  3, 32, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  103 ,  4, 32, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  103 ,  5, 32, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  103 ,  6, 32, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  103 ,  7, 32, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  103 ,  8, 32, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  103 ,  9, 32, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  103 ,  10, 32, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  103 ,  11, 32, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  103 ,  12, 32, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  103 ,  13, 32, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  103 ,  14, 32, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  103 ,  15, 32, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupTraceability,  103 ,  16, 32, Delayed) \
}
#define mSERReadTableU1BitEEP_VINCodeDefaultValueDefault( Index ) \
      mSERPeeReadDefaultTable(U1Bit,Sbk, GroupTraceability,  103 , Index, Delayed)

#define mSERReadTableU8BitEEP_VINCodeDefault( Index ) \
      mSERPeeReadTable(U8Bit,Sbk, GroupTraceability,  103 , Index, Delayed)
#define mSERWriteTableU8BitEEP_VINCodeDelayed( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Sbk, GroupTraceability,  103 , Index, (ValueToWrite), Delayed)
#define mSERWriteTableU8BitEEP_VINCodeImmediate( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Sbk, GroupTraceability,  103 , Index, (ValueToWrite), Immediate)
#define mSERWriteTableU8BitEEP_VINCodeDefault( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Sbk, GroupTraceability,  103 , Index, (ValueToWrite), Immediate)

// EEP_MsgTmOutSleepDelay -- Group GroupTraceability, Byte  120  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_MsgTmOutSleepDelay
  #error "Do not define EEP_MsgTmOutSleepDelay, because this is a lexem used for concatenation."
#endif
#define cDATEEP_MsgTmOutSleepDelayPositionByte      120 
#define cDATEEP_MsgTmOutSleepDelayPositionBit        0xFF
#define mSERPeeResetU16BitEEP_MsgTmOutSleepDelay()     \
      mSERPeeWriteU16Bit(Sbk, GroupTraceability,  120 ,  7 ,  16 , 300, Delayed)
#define mSERReadU16BitEEP_MsgTmOutSleepDelayDefaultValueDefault() ((U16)300)
#define mSERReadU16BitEEP_MsgTmOutSleepDelayDefault() \
      mSERPeeReadU16Bit(Sbk, GroupTraceability,  120 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_MsgTmOutSleepDelayDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Sbk, GroupTraceability,  120 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_MsgTmOutSleepDelayImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Sbk, GroupTraceability,  120 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_MsgTmOutSleepDelayDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Sbk, GroupTraceability,  120 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_ODOClearCountMain -- Group GroupTraceability, Byte  122  , Bit (MSB)  7  , SizeInBit  8 
#ifdef EEP_ODOClearCountMain
  #error "Do not define EEP_ODOClearCountMain, because this is a lexem used for concatenation."
#endif
#define cDATEEP_ODOClearCountMainPositionByte      122 
#define cDATEEP_ODOClearCountMainPositionBit        0xFF
#define mSERPeeResetU8BitEEP_ODOClearCountMain()     \
      mSERPeeWriteU8Bit(Sbk, GroupTraceability,  122 ,  7 ,  8 , 0, Delayed)
#define mSERReadU8BitEEP_ODOClearCountMainDefaultValueDefault() ((U8)0)
#define mSERReadU8BitEEP_ODOClearCountMainDefault() \
      mSERPeeReadU8Bit(Sbk, GroupTraceability,  122 ,  7 ,  8 , Delayed)
#define mSERWriteU8BitEEP_ODOClearCountMainDelayed(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupTraceability,  122 ,  7 ,  8 , (ValueToWrite), Delayed)
#define mSERWriteU8BitEEP_ODOClearCountMainImmediate(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupTraceability,  122 ,  7 ,  8 , (ValueToWrite), Immediate)
#define mSERWriteU8BitEEP_ODOClearCountMainDefault(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupTraceability,  122 ,  7 ,  8 , (ValueToWrite), Immediate)

// EEP_GroupTraceabilityReservedData0 -- Group GroupTraceability, Byte  123  , Bit (MSB)  7  , SizeInBit  8 
#ifdef EEP_GroupTraceabilityReservedData0
  #error "Do not define EEP_GroupTraceabilityReservedData0, because this is a lexem used for concatenation."
#endif
#define cDATEEP_GroupTraceabilityReservedData0PositionByte      123 
#define cDATEEP_GroupTraceabilityReservedData0PositionBit        0xFF
#define mSERPeeResetU8BitEEP_GroupTraceabilityReservedData0()     \
      mSERPeeWriteU8Bit(Sbk, GroupTraceability,  123 ,  7 ,  8 , 0, Delayed)
#define mSERReadU8BitEEP_GroupTraceabilityReservedData0DefaultValueDefault() ((U8)0)
#define mSERReadU8BitEEP_GroupTraceabilityReservedData0Default() \
      mSERPeeReadU8Bit(Sbk, GroupTraceability,  123 ,  7 ,  8 , Delayed)
#define mSERWriteU8BitEEP_GroupTraceabilityReservedData0Delayed(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupTraceability,  123 ,  7 ,  8 , (ValueToWrite), Delayed)
#define mSERWriteU8BitEEP_GroupTraceabilityReservedData0Immediate(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupTraceability,  123 ,  7 ,  8 , (ValueToWrite), Immediate)
#define mSERWriteU8BitEEP_GroupTraceabilityReservedData0Default(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupTraceability,  123 ,  7 ,  8 , (ValueToWrite), Immediate)

// EEP_GroupTraceabilityReservedData1 -- Group GroupTraceability, Byte  124  , Bit (MSB)  7  , SizeInBit  8 
#ifdef EEP_GroupTraceabilityReservedData1
  #error "Do not define EEP_GroupTraceabilityReservedData1, because this is a lexem used for concatenation."
#endif
#define cDATEEP_GroupTraceabilityReservedData1PositionByte      124 
#define cDATEEP_GroupTraceabilityReservedData1PositionBit        0xFF
#define mSERPeeResetU8BitEEP_GroupTraceabilityReservedData1()     \
      mSERPeeWriteU8Bit(Sbk, GroupTraceability,  124 ,  7 ,  8 , 0, Delayed)
#define mSERReadU8BitEEP_GroupTraceabilityReservedData1DefaultValueDefault() ((U8)0)
#define mSERReadU8BitEEP_GroupTraceabilityReservedData1Default() \
      mSERPeeReadU8Bit(Sbk, GroupTraceability,  124 ,  7 ,  8 , Delayed)
#define mSERWriteU8BitEEP_GroupTraceabilityReservedData1Delayed(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupTraceability,  124 ,  7 ,  8 , (ValueToWrite), Delayed)
#define mSERWriteU8BitEEP_GroupTraceabilityReservedData1Immediate(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupTraceability,  124 ,  7 ,  8 , (ValueToWrite), Immediate)
#define mSERWriteU8BitEEP_GroupTraceabilityReservedData1Default(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupTraceability,  124 ,  7 ,  8 , (ValueToWrite), Immediate)

// EEP_StationTraceability -- Group GroupPlantTraceability, Byte  0  , Bit (MSB)  7  , SizeInBit  64 
#ifdef EEP_StationTraceability
  #error "Do not define EEP_StationTraceability, because this is a lexem used for concatenation."
#endif
#define mSERPeeResetEEP_StationTraceability()     \
{                                                     \
   mSERPeeWriteTable(U8Bit,Sbk,GroupPlantTraceability,  0 ,  0, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupPlantTraceability,  0 ,  1, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupPlantTraceability,  0 ,  2, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupPlantTraceability,  0 ,  3, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupPlantTraceability,  0 ,  4, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupPlantTraceability,  0 ,  5, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupPlantTraceability,  0 ,  6, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupPlantTraceability,  0 ,  7, 0, Delayed) \
}
#define mSERReadTableU1BitEEP_StationTraceabilityDefaultValueDefault( Index ) \
      mSERPeeReadDefaultTable(U1Bit,Sbk, GroupPlantTraceability,  0 , Index, Delayed)

#define mSERReadTableU8BitEEP_StationTraceabilityDefault( Index ) \
      mSERPeeReadTable(U8Bit,Sbk, GroupPlantTraceability,  0 , Index, Delayed)
#define mSERWriteTableU8BitEEP_StationTraceabilityDelayed( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Sbk, GroupPlantTraceability,  0 , Index, (ValueToWrite), Delayed)
#define mSERWriteTableU8BitEEP_StationTraceabilityImmediate( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Sbk, GroupPlantTraceability,  0 , Index, (ValueToWrite), Immediate)
#define mSERWriteTableU8BitEEP_StationTraceabilityDefault( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Sbk, GroupPlantTraceability,  0 , Index, (ValueToWrite), Immediate)

// EEP_RunInTestModeConfiguration -- Group GroupPlantTraceability, Byte  8  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_RunInTestModeConfiguration
  #error "Do not define EEP_RunInTestModeConfiguration, because this is a lexem used for concatenation."
#endif
#define mSERPeeResetEEP_RunInTestModeConfiguration()     \
{                                                     \
   mSERPeeWriteTable(U8Bit,Sbk,GroupPlantTraceability,  8 ,  0, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupPlantTraceability,  8 ,  1, 0, Delayed) \
}
#define mSERReadTableU1BitEEP_RunInTestModeConfigurationDefaultValueDefault( Index ) \
      mSERPeeReadDefaultTable(U1Bit,Sbk, GroupPlantTraceability,  8 , Index, Delayed)

#define mSERReadTableU8BitEEP_RunInTestModeConfigurationDefault( Index ) \
      mSERPeeReadTable(U8Bit,Sbk, GroupPlantTraceability,  8 , Index, Delayed)
#define mSERWriteTableU8BitEEP_RunInTestModeConfigurationDelayed( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Sbk, GroupPlantTraceability,  8 , Index, (ValueToWrite), Delayed)
#define mSERWriteTableU8BitEEP_RunInTestModeConfigurationImmediate( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Sbk, GroupPlantTraceability,  8 , Index, (ValueToWrite), Immediate)
#define mSERWriteTableU8BitEEP_RunInTestModeConfigurationDefault( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Sbk, GroupPlantTraceability,  8 , Index, (ValueToWrite), Immediate)

// EEP_RunInTestModeResult -- Group GroupPlantTraceability, Byte  10  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_RunInTestModeResult
  #error "Do not define EEP_RunInTestModeResult, because this is a lexem used for concatenation."
#endif
#define mSERPeeResetEEP_RunInTestModeResult()     \
{                                                     \
   mSERPeeWriteTable(U8Bit,Sbk,GroupPlantTraceability,  10 ,  0, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupPlantTraceability,  10 ,  1, 0, Delayed) \
}
#define mSERReadTableU1BitEEP_RunInTestModeResultDefaultValueDefault( Index ) \
      mSERPeeReadDefaultTable(U1Bit,Sbk, GroupPlantTraceability,  10 , Index, Delayed)

#define mSERReadTableU8BitEEP_RunInTestModeResultDefault( Index ) \
      mSERPeeReadTable(U8Bit,Sbk, GroupPlantTraceability,  10 , Index, Delayed)
#define mSERWriteTableU8BitEEP_RunInTestModeResultDelayed( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Sbk, GroupPlantTraceability,  10 , Index, (ValueToWrite), Delayed)
#define mSERWriteTableU8BitEEP_RunInTestModeResultImmediate( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Sbk, GroupPlantTraceability,  10 , Index, (ValueToWrite), Immediate)
#define mSERWriteTableU8BitEEP_RunInTestModeResultDefault( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Sbk, GroupPlantTraceability,  10 , Index, (ValueToWrite), Immediate)

// EEP_PCBAReferenceAndRevisionWithSwE2P -- Group GroupPlantTraceability, Byte  12  , Bit (MSB)  7  , SizeInBit  72 
#ifdef EEP_PCBAReferenceAndRevisionWithSwE2P
  #error "Do not define EEP_PCBAReferenceAndRevisionWithSwE2P, because this is a lexem used for concatenation."
#endif
#define mSERPeeResetEEP_PCBAReferenceAndRevisionWithSwE2P()     \
{                                                     \
   mSERPeeWriteTable(U8Bit,Sbk,GroupPlantTraceability,  12 ,  0, 255, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupPlantTraceability,  12 ,  1, 255, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupPlantTraceability,  12 ,  2, 255, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupPlantTraceability,  12 ,  3, 255, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupPlantTraceability,  12 ,  4, 255, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupPlantTraceability,  12 ,  5, 255, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupPlantTraceability,  12 ,  6, 255, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupPlantTraceability,  12 ,  7, 255, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupPlantTraceability,  12 ,  8, 255, Delayed) \
}
#define mSERReadTableU1BitEEP_PCBAReferenceAndRevisionWithSwE2PDefaultValueDefault( Index ) \
      mSERPeeReadDefaultTable(U1Bit,Sbk, GroupPlantTraceability,  12 , Index, Delayed)

#define mSERReadTableU8BitEEP_PCBAReferenceAndRevisionWithSwE2PDefault( Index ) \
      mSERPeeReadTable(U8Bit,Sbk, GroupPlantTraceability,  12 , Index, Delayed)
#define mSERWriteTableU8BitEEP_PCBAReferenceAndRevisionWithSwE2PDelayed( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Sbk, GroupPlantTraceability,  12 , Index, (ValueToWrite), Delayed)
#define mSERWriteTableU8BitEEP_PCBAReferenceAndRevisionWithSwE2PImmediate( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Sbk, GroupPlantTraceability,  12 , Index, (ValueToWrite), Immediate)
#define mSERWriteTableU8BitEEP_PCBAReferenceAndRevisionWithSwE2PDefault( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Sbk, GroupPlantTraceability,  12 , Index, (ValueToWrite), Immediate)

// EEP_JCIProductReferenceAndRevision -- Group GroupPlantTraceability, Byte  21  , Bit (MSB)  7  , SizeInBit  64 
#ifdef EEP_JCIProductReferenceAndRevision
  #error "Do not define EEP_JCIProductReferenceAndRevision, because this is a lexem used for concatenation."
#endif
#define mSERPeeResetEEP_JCIProductReferenceAndRevision()     \
{                                                     \
   mSERPeeWriteTable(U8Bit,Sbk,GroupPlantTraceability,  21 ,  0, 255, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupPlantTraceability,  21 ,  1, 255, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupPlantTraceability,  21 ,  2, 255, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupPlantTraceability,  21 ,  3, 255, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupPlantTraceability,  21 ,  4, 255, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupPlantTraceability,  21 ,  5, 255, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupPlantTraceability,  21 ,  6, 255, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupPlantTraceability,  21 ,  7, 255, Delayed) \
}
#define mSERReadTableU1BitEEP_JCIProductReferenceAndRevisionDefaultValueDefault( Index ) \
      mSERPeeReadDefaultTable(U1Bit,Sbk, GroupPlantTraceability,  21 , Index, Delayed)

#define mSERReadTableU8BitEEP_JCIProductReferenceAndRevisionDefault( Index ) \
      mSERPeeReadTable(U8Bit,Sbk, GroupPlantTraceability,  21 , Index, Delayed)
#define mSERWriteTableU8BitEEP_JCIProductReferenceAndRevisionDelayed( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Sbk, GroupPlantTraceability,  21 , Index, (ValueToWrite), Delayed)
#define mSERWriteTableU8BitEEP_JCIProductReferenceAndRevisionImmediate( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Sbk, GroupPlantTraceability,  21 , Index, (ValueToWrite), Immediate)
#define mSERWriteTableU8BitEEP_JCIProductReferenceAndRevisionDefault( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Sbk, GroupPlantTraceability,  21 , Index, (ValueToWrite), Immediate)

// EEP_PCBASerialNumber -- Group GroupPlantTraceability, Byte  29  , Bit (MSB)  7  , SizeInBit  32 
#ifdef EEP_PCBASerialNumber
  #error "Do not define EEP_PCBASerialNumber, because this is a lexem used for concatenation."
#endif
#define mSERPeeResetEEP_PCBASerialNumber()     \
{                                                     \
   mSERPeeWriteTable(U8Bit,Sbk,GroupPlantTraceability,  29 ,  0, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupPlantTraceability,  29 ,  1, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupPlantTraceability,  29 ,  2, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupPlantTraceability,  29 ,  3, 0, Delayed) \
}
#define mSERReadTableU1BitEEP_PCBASerialNumberDefaultValueDefault( Index ) \
      mSERPeeReadDefaultTable(U1Bit,Sbk, GroupPlantTraceability,  29 , Index, Delayed)

#define mSERReadTableU8BitEEP_PCBASerialNumberDefault( Index ) \
      mSERPeeReadTable(U8Bit,Sbk, GroupPlantTraceability,  29 , Index, Delayed)
#define mSERWriteTableU8BitEEP_PCBASerialNumberDelayed( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Sbk, GroupPlantTraceability,  29 , Index, (ValueToWrite), Delayed)
#define mSERWriteTableU8BitEEP_PCBASerialNumberImmediate( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Sbk, GroupPlantTraceability,  29 , Index, (ValueToWrite), Immediate)
#define mSERWriteTableU8BitEEP_PCBASerialNumberDefault( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Sbk, GroupPlantTraceability,  29 , Index, (ValueToWrite), Immediate)

// EEP_SMDManufacturingDate -- Group GroupPlantTraceability, Byte  33  , Bit (MSB)  7  , SizeInBit  32 
#ifdef EEP_SMDManufacturingDate
  #error "Do not define EEP_SMDManufacturingDate, because this is a lexem used for concatenation."
#endif
#define mSERPeeResetEEP_SMDManufacturingDate()     \
{                                                     \
   mSERPeeWriteTable(U8Bit,Sbk,GroupPlantTraceability,  33 ,  0, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupPlantTraceability,  33 ,  1, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupPlantTraceability,  33 ,  2, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupPlantTraceability,  33 ,  3, 0, Delayed) \
}
#define mSERReadTableU1BitEEP_SMDManufacturingDateDefaultValueDefault( Index ) \
      mSERPeeReadDefaultTable(U1Bit,Sbk, GroupPlantTraceability,  33 , Index, Delayed)

#define mSERReadTableU8BitEEP_SMDManufacturingDateDefault( Index ) \
      mSERPeeReadTable(U8Bit,Sbk, GroupPlantTraceability,  33 , Index, Delayed)
#define mSERWriteTableU8BitEEP_SMDManufacturingDateDelayed( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Sbk, GroupPlantTraceability,  33 , Index, (ValueToWrite), Delayed)
#define mSERWriteTableU8BitEEP_SMDManufacturingDateImmediate( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Sbk, GroupPlantTraceability,  33 , Index, (ValueToWrite), Immediate)
#define mSERWriteTableU8BitEEP_SMDManufacturingDateDefault( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Sbk, GroupPlantTraceability,  33 , Index, (ValueToWrite), Immediate)

// EEP_SMDPlantNumber -- Group GroupPlantTraceability, Byte  37  , Bit (MSB)  7  , SizeInBit  24 
#ifdef EEP_SMDPlantNumber
  #error "Do not define EEP_SMDPlantNumber, because this is a lexem used for concatenation."
#endif
#define mSERPeeResetEEP_SMDPlantNumber()     \
{                                                     \
   mSERPeeWriteTable(U8Bit,Sbk,GroupPlantTraceability,  37 ,  0, 255, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupPlantTraceability,  37 ,  1, 255, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupPlantTraceability,  37 ,  2, 255, Delayed) \
}
#define mSERReadTableU1BitEEP_SMDPlantNumberDefaultValueDefault( Index ) \
      mSERPeeReadDefaultTable(U1Bit,Sbk, GroupPlantTraceability,  37 , Index, Delayed)

#define mSERReadTableU8BitEEP_SMDPlantNumberDefault( Index ) \
      mSERPeeReadTable(U8Bit,Sbk, GroupPlantTraceability,  37 , Index, Delayed)
#define mSERWriteTableU8BitEEP_SMDPlantNumberDelayed( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Sbk, GroupPlantTraceability,  37 , Index, (ValueToWrite), Delayed)
#define mSERWriteTableU8BitEEP_SMDPlantNumberImmediate( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Sbk, GroupPlantTraceability,  37 , Index, (ValueToWrite), Immediate)
#define mSERWriteTableU8BitEEP_SMDPlantNumberDefault( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Sbk, GroupPlantTraceability,  37 , Index, (ValueToWrite), Immediate)

// EEP_TestOKCount -- Group GroupPlantTraceability, Byte  40  , Bit (MSB)  7  , SizeInBit  8 
#ifdef EEP_TestOKCount
  #error "Do not define EEP_TestOKCount, because this is a lexem used for concatenation."
#endif
#define cDATEEP_TestOKCountPositionByte      40 
#define cDATEEP_TestOKCountPositionBit        0xFF
#define mSERPeeResetU8BitEEP_TestOKCount()     \
      mSERPeeWriteU8Bit(Sbk, GroupPlantTraceability,  40 ,  7 ,  8 , 0, Delayed)
#define mSERReadU8BitEEP_TestOKCountDefaultValueDefault() ((U8)0)
#define mSERReadU8BitEEP_TestOKCountDefault() \
      mSERPeeReadU8Bit(Sbk, GroupPlantTraceability,  40 ,  7 ,  8 , Delayed)
#define mSERWriteU8BitEEP_TestOKCountDelayed(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupPlantTraceability,  40 ,  7 ,  8 , (ValueToWrite), Delayed)
#define mSERWriteU8BitEEP_TestOKCountImmediate(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupPlantTraceability,  40 ,  7 ,  8 , (ValueToWrite), Immediate)
#define mSERWriteU8BitEEP_TestOKCountDefault(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupPlantTraceability,  40 ,  7 ,  8 , (ValueToWrite), Immediate)

// EEP_GroupPlantTraceabilityReservedData0 -- Group GroupPlantTraceability, Byte  41  , Bit (MSB)  7  , SizeInBit  8 
#ifdef EEP_GroupPlantTraceabilityReservedData0
  #error "Do not define EEP_GroupPlantTraceabilityReservedData0, because this is a lexem used for concatenation."
#endif
#define cDATEEP_GroupPlantTraceabilityReservedData0PositionByte      41 
#define cDATEEP_GroupPlantTraceabilityReservedData0PositionBit        0xFF
#define mSERPeeResetU8BitEEP_GroupPlantTraceabilityReservedData0()     \
      mSERPeeWriteU8Bit(Sbk, GroupPlantTraceability,  41 ,  7 ,  8 , 0, Delayed)
#define mSERReadU8BitEEP_GroupPlantTraceabilityReservedData0DefaultValueDefault() ((U8)0)
#define mSERReadU8BitEEP_GroupPlantTraceabilityReservedData0Default() \
      mSERPeeReadU8Bit(Sbk, GroupPlantTraceability,  41 ,  7 ,  8 , Delayed)
#define mSERWriteU8BitEEP_GroupPlantTraceabilityReservedData0Delayed(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupPlantTraceability,  41 ,  7 ,  8 , (ValueToWrite), Delayed)
#define mSERWriteU8BitEEP_GroupPlantTraceabilityReservedData0Immediate(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupPlantTraceability,  41 ,  7 ,  8 , (ValueToWrite), Immediate)
#define mSERWriteU8BitEEP_GroupPlantTraceabilityReservedData0Default(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupPlantTraceability,  41 ,  7 ,  8 , (ValueToWrite), Immediate)

// EEP_GroupPlantTraceabilityReservedData1 -- Group GroupPlantTraceability, Byte  42  , Bit (MSB)  7  , SizeInBit  8 
#ifdef EEP_GroupPlantTraceabilityReservedData1
  #error "Do not define EEP_GroupPlantTraceabilityReservedData1, because this is a lexem used for concatenation."
#endif
#define cDATEEP_GroupPlantTraceabilityReservedData1PositionByte      42 
#define cDATEEP_GroupPlantTraceabilityReservedData1PositionBit        0xFF
#define mSERPeeResetU8BitEEP_GroupPlantTraceabilityReservedData1()     \
      mSERPeeWriteU8Bit(Sbk, GroupPlantTraceability,  42 ,  7 ,  8 , 0, Delayed)
#define mSERReadU8BitEEP_GroupPlantTraceabilityReservedData1DefaultValueDefault() ((U8)0)
#define mSERReadU8BitEEP_GroupPlantTraceabilityReservedData1Default() \
      mSERPeeReadU8Bit(Sbk, GroupPlantTraceability,  42 ,  7 ,  8 , Delayed)
#define mSERWriteU8BitEEP_GroupPlantTraceabilityReservedData1Delayed(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupPlantTraceability,  42 ,  7 ,  8 , (ValueToWrite), Delayed)
#define mSERWriteU8BitEEP_GroupPlantTraceabilityReservedData1Immediate(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupPlantTraceability,  42 ,  7 ,  8 , (ValueToWrite), Immediate)
#define mSERWriteU8BitEEP_GroupPlantTraceabilityReservedData1Default(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupPlantTraceability,  42 ,  7 ,  8 , (ValueToWrite), Immediate)

// EEP_GroupPlantTraceabilityReservedData2 -- Group GroupPlantTraceability, Byte  43  , Bit (MSB)  7  , SizeInBit  8 
#ifdef EEP_GroupPlantTraceabilityReservedData2
  #error "Do not define EEP_GroupPlantTraceabilityReservedData2, because this is a lexem used for concatenation."
#endif
#define cDATEEP_GroupPlantTraceabilityReservedData2PositionByte      43 
#define cDATEEP_GroupPlantTraceabilityReservedData2PositionBit        0xFF
#define mSERPeeResetU8BitEEP_GroupPlantTraceabilityReservedData2()     \
      mSERPeeWriteU8Bit(Sbk, GroupPlantTraceability,  43 ,  7 ,  8 , 0, Delayed)
#define mSERReadU8BitEEP_GroupPlantTraceabilityReservedData2DefaultValueDefault() ((U8)0)
#define mSERReadU8BitEEP_GroupPlantTraceabilityReservedData2Default() \
      mSERPeeReadU8Bit(Sbk, GroupPlantTraceability,  43 ,  7 ,  8 , Delayed)
#define mSERWriteU8BitEEP_GroupPlantTraceabilityReservedData2Delayed(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupPlantTraceability,  43 ,  7 ,  8 , (ValueToWrite), Delayed)
#define mSERWriteU8BitEEP_GroupPlantTraceabilityReservedData2Immediate(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupPlantTraceability,  43 ,  7 ,  8 , (ValueToWrite), Immediate)
#define mSERWriteU8BitEEP_GroupPlantTraceabilityReservedData2Default(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupPlantTraceability,  43 ,  7 ,  8 , (ValueToWrite), Immediate)

// EEP_GroupPlantTraceabilityReservedData3 -- Group GroupPlantTraceability, Byte  44  , Bit (MSB)  7  , SizeInBit  8 
#ifdef EEP_GroupPlantTraceabilityReservedData3
  #error "Do not define EEP_GroupPlantTraceabilityReservedData3, because this is a lexem used for concatenation."
#endif
#define cDATEEP_GroupPlantTraceabilityReservedData3PositionByte      44 
#define cDATEEP_GroupPlantTraceabilityReservedData3PositionBit        0xFF
#define mSERPeeResetU8BitEEP_GroupPlantTraceabilityReservedData3()     \
      mSERPeeWriteU8Bit(Sbk, GroupPlantTraceability,  44 ,  7 ,  8 , 0, Delayed)
#define mSERReadU8BitEEP_GroupPlantTraceabilityReservedData3DefaultValueDefault() ((U8)0)
#define mSERReadU8BitEEP_GroupPlantTraceabilityReservedData3Default() \
      mSERPeeReadU8Bit(Sbk, GroupPlantTraceability,  44 ,  7 ,  8 , Delayed)
#define mSERWriteU8BitEEP_GroupPlantTraceabilityReservedData3Delayed(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupPlantTraceability,  44 ,  7 ,  8 , (ValueToWrite), Delayed)
#define mSERWriteU8BitEEP_GroupPlantTraceabilityReservedData3Immediate(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupPlantTraceability,  44 ,  7 ,  8 , (ValueToWrite), Immediate)
#define mSERWriteU8BitEEP_GroupPlantTraceabilityReservedData3Default(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupPlantTraceability,  44 ,  7 ,  8 , (ValueToWrite), Immediate)

// EEP_DiagReservedData -- Group GroupDiagReserved, Byte  0  , Bit (MSB)  7  , SizeInBit  64 
#ifdef EEP_DiagReservedData
  #error "Do not define EEP_DiagReservedData, because this is a lexem used for concatenation."
#endif
#define mSERPeeResetEEP_DiagReservedData()     \
{                                                     \
   mSERPeeWriteTable(U8Bit,Sbk,GroupDiagReserved,  0 ,  0, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupDiagReserved,  0 ,  1, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupDiagReserved,  0 ,  2, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupDiagReserved,  0 ,  3, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupDiagReserved,  0 ,  4, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupDiagReserved,  0 ,  5, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupDiagReserved,  0 ,  6, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Sbk,GroupDiagReserved,  0 ,  7, 0, Delayed) \
}
#define mSERReadTableU1BitEEP_DiagReservedDataDefaultValueDefault( Index ) \
      mSERPeeReadDefaultTable(U1Bit,Sbk, GroupDiagReserved,  0 , Index, Delayed)

#define mSERReadTableU8BitEEP_DiagReservedDataDefault( Index ) \
      mSERPeeReadTable(U8Bit,Sbk, GroupDiagReserved,  0 , Index, Delayed)
#define mSERWriteTableU8BitEEP_DiagReservedDataDelayed( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Sbk, GroupDiagReserved,  0 , Index, (ValueToWrite), Delayed)
#define mSERWriteTableU8BitEEP_DiagReservedDataImmediate( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Sbk, GroupDiagReserved,  0 , Index, (ValueToWrite), Immediate)
#define mSERWriteTableU8BitEEP_DiagReservedDataDefault( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Sbk, GroupDiagReserved,  0 , Index, (ValueToWrite), Immediate)

// EEP_OdoTotal -- Group GroupOdo, Byte  0  , Bit (MSB)  7  , SizeInBit  32 
#ifdef EEP_OdoTotal
  #error "Do not define EEP_OdoTotal, because this is a lexem used for concatenation."
#endif
#define cDATEEP_OdoTotalPositionByte      0 
#define cDATEEP_OdoTotalPositionBit        0xFF
#define mSERPeeResetU32BitEEP_OdoTotal()     \
      mSERPeeWriteU32Bit(Obk, GroupOdo,  0 ,  7 ,  32 , 0, Delayed)
#define mSERReadU32BitEEP_OdoTotalDefaultValueDefault() ((U32)0)
#define mSERReadU32BitEEP_OdoTotalDefault() \
      mSERPeeReadU32Bit(Obk, GroupOdo,  0 ,  7 ,  32 , Delayed)
#define mSERWriteU32BitEEP_OdoTotalDelayed(ValueToWrite) \
      mSERPeeWriteU32Bit(Obk, GroupOdo,  0 ,  7 ,  32 , (ValueToWrite), Delayed)
#define mSERWriteU32BitEEP_OdoTotalImmediate(ValueToWrite) \
      mSERPeeWriteU32Bit(Obk, GroupOdo,  0 ,  7 ,  32 , (ValueToWrite), Immediate)
#define mSERWriteU32BitEEP_OdoTotalDefault(ValueToWrite) \
      mSERPeeWriteU32Bit(Obk, GroupOdo,  0 ,  7 ,  32 , (ValueToWrite), Immediate)

// EEP_OdoTripBase -- Group GroupOdo, Byte  4  , Bit (MSB)  7  , SizeInBit  32 
#ifdef EEP_OdoTripBase
  #error "Do not define EEP_OdoTripBase, because this is a lexem used for concatenation."
#endif
#define cDATEEP_OdoTripBasePositionByte      4 
#define cDATEEP_OdoTripBasePositionBit        0xFF
#define mSERPeeResetU32BitEEP_OdoTripBase()     \
      mSERPeeWriteU32Bit(Obk, GroupOdo,  4 ,  7 ,  32 , 0, Delayed)
#define mSERReadU32BitEEP_OdoTripBaseDefaultValueDefault() ((U32)0)
#define mSERReadU32BitEEP_OdoTripBaseDefault() \
      mSERPeeReadU32Bit(Obk, GroupOdo,  4 ,  7 ,  32 , Delayed)
#define mSERWriteU32BitEEP_OdoTripBaseDelayed(ValueToWrite) \
      mSERPeeWriteU32Bit(Obk, GroupOdo,  4 ,  7 ,  32 , (ValueToWrite), Delayed)
#define mSERWriteU32BitEEP_OdoTripBaseImmediate(ValueToWrite) \
      mSERPeeWriteU32Bit(Obk, GroupOdo,  4 ,  7 ,  32 , (ValueToWrite), Immediate)
#define mSERWriteU32BitEEP_OdoTripBaseDefault(ValueToWrite) \
      mSERPeeWriteU32Bit(Obk, GroupOdo,  4 ,  7 ,  32 , (ValueToWrite), Immediate)

// EEP_GroupPlantCalibirationReservedData1 -- Group GroupPlantCalibiration, Byte  0  , Bit (MSB)  7  , SizeInBit  8 
#ifdef EEP_GroupPlantCalibirationReservedData1
  #error "Do not define EEP_GroupPlantCalibirationReservedData1, because this is a lexem used for concatenation."
#endif
#define cDATEEP_GroupPlantCalibirationReservedData1PositionByte      0 
#define cDATEEP_GroupPlantCalibirationReservedData1PositionBit        0xFF
#define mSERPeeResetU8BitEEP_GroupPlantCalibirationReservedData1()     \
      mSERPeeWriteU8Bit(Sbk, GroupPlantCalibiration,  0 ,  7 ,  8 , 0, Delayed)
#define mSERReadU8BitEEP_GroupPlantCalibirationReservedData1DefaultValueDefault() ((U8)0)
#define mSERReadU8BitEEP_GroupPlantCalibirationReservedData1Default() \
      mSERPeeReadU8Bit(Sbk, GroupPlantCalibiration,  0 ,  7 ,  8 , Delayed)
#define mSERWriteU8BitEEP_GroupPlantCalibirationReservedData1Delayed(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupPlantCalibiration,  0 ,  7 ,  8 , (ValueToWrite), Delayed)
#define mSERWriteU8BitEEP_GroupPlantCalibirationReservedData1Immediate(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupPlantCalibiration,  0 ,  7 ,  8 , (ValueToWrite), Immediate)
#define mSERWriteU8BitEEP_GroupPlantCalibirationReservedData1Default(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupPlantCalibiration,  0 ,  7 ,  8 , (ValueToWrite), Immediate)

// EEP_GroupPlantCalibirationReservedData2 -- Group GroupPlantCalibiration, Byte  1  , Bit (MSB)  7  , SizeInBit  8 
#ifdef EEP_GroupPlantCalibirationReservedData2
  #error "Do not define EEP_GroupPlantCalibirationReservedData2, because this is a lexem used for concatenation."
#endif
#define cDATEEP_GroupPlantCalibirationReservedData2PositionByte      1 
#define cDATEEP_GroupPlantCalibirationReservedData2PositionBit        0xFF
#define mSERPeeResetU8BitEEP_GroupPlantCalibirationReservedData2()     \
      mSERPeeWriteU8Bit(Sbk, GroupPlantCalibiration,  1 ,  7 ,  8 , 0, Delayed)
#define mSERReadU8BitEEP_GroupPlantCalibirationReservedData2DefaultValueDefault() ((U8)0)
#define mSERReadU8BitEEP_GroupPlantCalibirationReservedData2Default() \
      mSERPeeReadU8Bit(Sbk, GroupPlantCalibiration,  1 ,  7 ,  8 , Delayed)
#define mSERWriteU8BitEEP_GroupPlantCalibirationReservedData2Delayed(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupPlantCalibiration,  1 ,  7 ,  8 , (ValueToWrite), Delayed)
#define mSERWriteU8BitEEP_GroupPlantCalibirationReservedData2Immediate(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupPlantCalibiration,  1 ,  7 ,  8 , (ValueToWrite), Immediate)
#define mSERWriteU8BitEEP_GroupPlantCalibirationReservedData2Default(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupPlantCalibiration,  1 ,  7 ,  8 , (ValueToWrite), Immediate)

// EEP_GroupPlantCalibirationReservedData3 -- Group GroupPlantCalibiration, Byte  2  , Bit (MSB)  7  , SizeInBit  8 
#ifdef EEP_GroupPlantCalibirationReservedData3
  #error "Do not define EEP_GroupPlantCalibirationReservedData3, because this is a lexem used for concatenation."
#endif
#define cDATEEP_GroupPlantCalibirationReservedData3PositionByte      2 
#define cDATEEP_GroupPlantCalibirationReservedData3PositionBit        0xFF
#define mSERPeeResetU8BitEEP_GroupPlantCalibirationReservedData3()     \
      mSERPeeWriteU8Bit(Sbk, GroupPlantCalibiration,  2 ,  7 ,  8 , 0, Delayed)
#define mSERReadU8BitEEP_GroupPlantCalibirationReservedData3DefaultValueDefault() ((U8)0)
#define mSERReadU8BitEEP_GroupPlantCalibirationReservedData3Default() \
      mSERPeeReadU8Bit(Sbk, GroupPlantCalibiration,  2 ,  7 ,  8 , Delayed)
#define mSERWriteU8BitEEP_GroupPlantCalibirationReservedData3Delayed(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupPlantCalibiration,  2 ,  7 ,  8 , (ValueToWrite), Delayed)
#define mSERWriteU8BitEEP_GroupPlantCalibirationReservedData3Immediate(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupPlantCalibiration,  2 ,  7 ,  8 , (ValueToWrite), Immediate)
#define mSERWriteU8BitEEP_GroupPlantCalibirationReservedData3Default(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupPlantCalibiration,  2 ,  7 ,  8 , (ValueToWrite), Immediate)

// EEP_GroupPlantCalibirationReservedData4 -- Group GroupPlantCalibiration, Byte  3  , Bit (MSB)  7  , SizeInBit  8 
#ifdef EEP_GroupPlantCalibirationReservedData4
  #error "Do not define EEP_GroupPlantCalibirationReservedData4, because this is a lexem used for concatenation."
#endif
#define cDATEEP_GroupPlantCalibirationReservedData4PositionByte      3 
#define cDATEEP_GroupPlantCalibirationReservedData4PositionBit        0xFF
#define mSERPeeResetU8BitEEP_GroupPlantCalibirationReservedData4()     \
      mSERPeeWriteU8Bit(Sbk, GroupPlantCalibiration,  3 ,  7 ,  8 , 0, Delayed)
#define mSERReadU8BitEEP_GroupPlantCalibirationReservedData4DefaultValueDefault() ((U8)0)
#define mSERReadU8BitEEP_GroupPlantCalibirationReservedData4Default() \
      mSERPeeReadU8Bit(Sbk, GroupPlantCalibiration,  3 ,  7 ,  8 , Delayed)
#define mSERWriteU8BitEEP_GroupPlantCalibirationReservedData4Delayed(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupPlantCalibiration,  3 ,  7 ,  8 , (ValueToWrite), Delayed)
#define mSERWriteU8BitEEP_GroupPlantCalibirationReservedData4Immediate(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupPlantCalibiration,  3 ,  7 ,  8 , (ValueToWrite), Immediate)
#define mSERWriteU8BitEEP_GroupPlantCalibirationReservedData4Default(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupPlantCalibiration,  3 ,  7 ,  8 , (ValueToWrite), Immediate)

// EEP_GroupPlantCalibirationReservedData5 -- Group GroupPlantCalibiration, Byte  4  , Bit (MSB)  7  , SizeInBit  8 
#ifdef EEP_GroupPlantCalibirationReservedData5
  #error "Do not define EEP_GroupPlantCalibirationReservedData5, because this is a lexem used for concatenation."
#endif
#define cDATEEP_GroupPlantCalibirationReservedData5PositionByte      4 
#define cDATEEP_GroupPlantCalibirationReservedData5PositionBit        0xFF
#define mSERPeeResetU8BitEEP_GroupPlantCalibirationReservedData5()     \
      mSERPeeWriteU8Bit(Sbk, GroupPlantCalibiration,  4 ,  7 ,  8 , 0, Delayed)
#define mSERReadU8BitEEP_GroupPlantCalibirationReservedData5DefaultValueDefault() ((U8)0)
#define mSERReadU8BitEEP_GroupPlantCalibirationReservedData5Default() \
      mSERPeeReadU8Bit(Sbk, GroupPlantCalibiration,  4 ,  7 ,  8 , Delayed)
#define mSERWriteU8BitEEP_GroupPlantCalibirationReservedData5Delayed(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupPlantCalibiration,  4 ,  7 ,  8 , (ValueToWrite), Delayed)
#define mSERWriteU8BitEEP_GroupPlantCalibirationReservedData5Immediate(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupPlantCalibiration,  4 ,  7 ,  8 , (ValueToWrite), Immediate)
#define mSERWriteU8BitEEP_GroupPlantCalibirationReservedData5Default(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupPlantCalibiration,  4 ,  7 ,  8 , (ValueToWrite), Immediate)

// EEP_GroupPlantCalibirationReservedData6 -- Group GroupPlantCalibiration, Byte  5  , Bit (MSB)  7  , SizeInBit  8 
#ifdef EEP_GroupPlantCalibirationReservedData6
  #error "Do not define EEP_GroupPlantCalibirationReservedData6, because this is a lexem used for concatenation."
#endif
#define cDATEEP_GroupPlantCalibirationReservedData6PositionByte      5 
#define cDATEEP_GroupPlantCalibirationReservedData6PositionBit        0xFF
#define mSERPeeResetU8BitEEP_GroupPlantCalibirationReservedData6()     \
      mSERPeeWriteU8Bit(Sbk, GroupPlantCalibiration,  5 ,  7 ,  8 , 0, Delayed)
#define mSERReadU8BitEEP_GroupPlantCalibirationReservedData6DefaultValueDefault() ((U8)0)
#define mSERReadU8BitEEP_GroupPlantCalibirationReservedData6Default() \
      mSERPeeReadU8Bit(Sbk, GroupPlantCalibiration,  5 ,  7 ,  8 , Delayed)
#define mSERWriteU8BitEEP_GroupPlantCalibirationReservedData6Delayed(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupPlantCalibiration,  5 ,  7 ,  8 , (ValueToWrite), Delayed)
#define mSERWriteU8BitEEP_GroupPlantCalibirationReservedData6Immediate(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupPlantCalibiration,  5 ,  7 ,  8 , (ValueToWrite), Immediate)
#define mSERWriteU8BitEEP_GroupPlantCalibirationReservedData6Default(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupPlantCalibiration,  5 ,  7 ,  8 , (ValueToWrite), Immediate)

// EEP_GroupPlantCalibirationReservedData7 -- Group GroupPlantCalibiration, Byte  6  , Bit (MSB)  7  , SizeInBit  8 
#ifdef EEP_GroupPlantCalibirationReservedData7
  #error "Do not define EEP_GroupPlantCalibirationReservedData7, because this is a lexem used for concatenation."
#endif
#define cDATEEP_GroupPlantCalibirationReservedData7PositionByte      6 
#define cDATEEP_GroupPlantCalibirationReservedData7PositionBit        0xFF
#define mSERPeeResetU8BitEEP_GroupPlantCalibirationReservedData7()     \
      mSERPeeWriteU8Bit(Sbk, GroupPlantCalibiration,  6 ,  7 ,  8 , 0, Delayed)
#define mSERReadU8BitEEP_GroupPlantCalibirationReservedData7DefaultValueDefault() ((U8)0)
#define mSERReadU8BitEEP_GroupPlantCalibirationReservedData7Default() \
      mSERPeeReadU8Bit(Sbk, GroupPlantCalibiration,  6 ,  7 ,  8 , Delayed)
#define mSERWriteU8BitEEP_GroupPlantCalibirationReservedData7Delayed(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupPlantCalibiration,  6 ,  7 ,  8 , (ValueToWrite), Delayed)
#define mSERWriteU8BitEEP_GroupPlantCalibirationReservedData7Immediate(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupPlantCalibiration,  6 ,  7 ,  8 , (ValueToWrite), Immediate)
#define mSERWriteU8BitEEP_GroupPlantCalibirationReservedData7Default(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupPlantCalibiration,  6 ,  7 ,  8 , (ValueToWrite), Immediate)

// EEP_GroupPlantCalibirationReservedData8 -- Group GroupPlantCalibiration, Byte  7  , Bit (MSB)  7  , SizeInBit  8 
#ifdef EEP_GroupPlantCalibirationReservedData8
  #error "Do not define EEP_GroupPlantCalibirationReservedData8, because this is a lexem used for concatenation."
#endif
#define cDATEEP_GroupPlantCalibirationReservedData8PositionByte      7 
#define cDATEEP_GroupPlantCalibirationReservedData8PositionBit        0xFF
#define mSERPeeResetU8BitEEP_GroupPlantCalibirationReservedData8()     \
      mSERPeeWriteU8Bit(Sbk, GroupPlantCalibiration,  7 ,  7 ,  8 , 0, Delayed)
#define mSERReadU8BitEEP_GroupPlantCalibirationReservedData8DefaultValueDefault() ((U8)0)
#define mSERReadU8BitEEP_GroupPlantCalibirationReservedData8Default() \
      mSERPeeReadU8Bit(Sbk, GroupPlantCalibiration,  7 ,  7 ,  8 , Delayed)
#define mSERWriteU8BitEEP_GroupPlantCalibirationReservedData8Delayed(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupPlantCalibiration,  7 ,  7 ,  8 , (ValueToWrite), Delayed)
#define mSERWriteU8BitEEP_GroupPlantCalibirationReservedData8Immediate(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupPlantCalibiration,  7 ,  7 ,  8 , (ValueToWrite), Immediate)
#define mSERWriteU8BitEEP_GroupPlantCalibirationReservedData8Default(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupPlantCalibiration,  7 ,  7 ,  8 , (ValueToWrite), Immediate)

// EEPFaultCounterNetworkMgt -- Group GroupSTKDTC, Byte  0  , Bit (MSB)  7  , SizeInBit  80 
#ifdef EEPFaultCounterNetworkMgt
  #error "Do not define EEPFaultCounterNetworkMgt, because this is a lexem used for concatenation."
#endif
#define mSERPeeResetEEPFaultCounterNetworkMgt()     \
{                                                     \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSTKDTC,  0 ,  0, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSTKDTC,  0 ,  1, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSTKDTC,  0 ,  2, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSTKDTC,  0 ,  3, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSTKDTC,  0 ,  4, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSTKDTC,  0 ,  5, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSTKDTC,  0 ,  6, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSTKDTC,  0 ,  7, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSTKDTC,  0 ,  8, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSTKDTC,  0 ,  9, 0, Delayed) \
}
#define mSERReadTableU1BitEEPFaultCounterNetworkMgtDefaultValueDefault( Index ) \
      mSERPeeReadDefaultTable(U1Bit,Dbk, GroupSTKDTC,  0 , Index, Delayed)

#define mSERReadTableU8BitEEPFaultCounterNetworkMgtDefault( Index ) \
      mSERPeeReadTable(U8Bit,Dbk, GroupSTKDTC,  0 , Index, Delayed)
#define mSERWriteTableU8BitEEPFaultCounterNetworkMgtDelayed( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Dbk, GroupSTKDTC,  0 , Index, (ValueToWrite), Delayed)
#define mSERWriteTableU8BitEEPFaultCounterNetworkMgtImmediate( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Dbk, GroupSTKDTC,  0 , Index, (ValueToWrite), Immediate)
#define mSERWriteTableU8BitEEPFaultCounterNetworkMgtDefault( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Dbk, GroupSTKDTC,  0 , Index, (ValueToWrite), Immediate)

// EEPFlagsDefautSourcesCan0 -- Group GroupSTKDTC, Byte  10  , Bit (MSB)  7  , SizeInBit  80 
#ifdef EEPFlagsDefautSourcesCan0
  #error "Do not define EEPFlagsDefautSourcesCan0, because this is a lexem used for concatenation."
#endif
#define mSERPeeResetEEPFlagsDefautSourcesCan0()     \
{                                                     \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSTKDTC,  10 ,  0, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSTKDTC,  10 ,  1, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSTKDTC,  10 ,  2, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSTKDTC,  10 ,  3, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSTKDTC,  10 ,  4, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSTKDTC,  10 ,  5, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSTKDTC,  10 ,  6, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSTKDTC,  10 ,  7, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSTKDTC,  10 ,  8, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSTKDTC,  10 ,  9, 0, Delayed) \
}
#define mSERReadTableU1BitEEPFlagsDefautSourcesCan0DefaultValueDefault( Index ) \
      mSERPeeReadDefaultTable(U1Bit,Dbk, GroupSTKDTC,  10 , Index, Delayed)

#define mSERReadTableU8BitEEPFlagsDefautSourcesCan0Default( Index ) \
      mSERPeeReadTable(U8Bit,Dbk, GroupSTKDTC,  10 , Index, Delayed)
#define mSERWriteTableU8BitEEPFlagsDefautSourcesCan0Delayed( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Dbk, GroupSTKDTC,  10 , Index, (ValueToWrite), Delayed)
#define mSERWriteTableU8BitEEPFlagsDefautSourcesCan0Immediate( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Dbk, GroupSTKDTC,  10 , Index, (ValueToWrite), Immediate)
#define mSERWriteTableU8BitEEPFlagsDefautSourcesCan0Default( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Dbk, GroupSTKDTC,  10 , Index, (ValueToWrite), Immediate)

// EEPFlagsDefautSourcesCan1 -- Group GroupSTKDTC, Byte  20  , Bit (MSB)  7  , SizeInBit  8 
#ifdef EEPFlagsDefautSourcesCan1
  #error "Do not define EEPFlagsDefautSourcesCan1, because this is a lexem used for concatenation."
#endif
#define mSERPeeResetEEPFlagsDefautSourcesCan1()     \
{                                                     \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSTKDTC,  20 ,  0, 0, Delayed) \
}
#define mSERReadTableU1BitEEPFlagsDefautSourcesCan1DefaultValueDefault( Index ) \
      mSERPeeReadDefaultTable(U1Bit,Dbk, GroupSTKDTC,  20 , Index, Delayed)

#define mSERReadTableU8BitEEPFlagsDefautSourcesCan1Default( Index ) \
      mSERPeeReadTable(U8Bit,Dbk, GroupSTKDTC,  20 , Index, Delayed)
#define mSERWriteTableU8BitEEPFlagsDefautSourcesCan1Delayed( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Dbk, GroupSTKDTC,  20 , Index, (ValueToWrite), Delayed)
#define mSERWriteTableU8BitEEPFlagsDefautSourcesCan1Immediate( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Dbk, GroupSTKDTC,  20 , Index, (ValueToWrite), Immediate)
#define mSERWriteTableU8BitEEPFlagsDefautSourcesCan1Default( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Dbk, GroupSTKDTC,  20 , Index, (ValueToWrite), Immediate)

// EEPFlagsDefautSourcesCan -- Group GroupSTKDTC, Byte  21  , Bit (MSB)  7  , SizeInBit  8 
#ifdef EEPFlagsDefautSourcesCan
  #error "Do not define EEPFlagsDefautSourcesCan, because this is a lexem used for concatenation."
#endif
#define cDATEEPFlagsDefautSourcesCanPositionByte      21 
#define cDATEEPFlagsDefautSourcesCanPositionBit        0xFF
#define mSERPeeResetU8BitEEPFlagsDefautSourcesCan()     \
      mSERPeeWriteU8Bit(Dbk, GroupSTKDTC,  21 ,  7 ,  8 , 0, Delayed)
#define mSERReadU8BitEEPFlagsDefautSourcesCanDefaultValueDefault() ((U8)0)
#define mSERReadU8BitEEPFlagsDefautSourcesCanDefault() \
      mSERPeeReadU8Bit(Dbk, GroupSTKDTC,  21 ,  7 ,  8 , Delayed)
#define mSERWriteU8BitEEPFlagsDefautSourcesCanDelayed(ValueToWrite) \
      mSERPeeWriteU8Bit(Dbk, GroupSTKDTC,  21 ,  7 ,  8 , (ValueToWrite), Delayed)
#define mSERWriteU8BitEEPFlagsDefautSourcesCanImmediate(ValueToWrite) \
      mSERPeeWriteU8Bit(Dbk, GroupSTKDTC,  21 ,  7 ,  8 , (ValueToWrite), Immediate)
#define mSERWriteU8BitEEPFlagsDefautSourcesCanDefault(ValueToWrite) \
      mSERPeeWriteU8Bit(Dbk, GroupSTKDTC,  21 ,  7 ,  8 , (ValueToWrite), Immediate)

// EEPFlagsDefectLin -- Group GroupSTKDTC, Byte  22  , Bit (MSB)  7  , SizeInBit  8 
#ifdef EEPFlagsDefectLin
  #error "Do not define EEPFlagsDefectLin, because this is a lexem used for concatenation."
#endif
#define cDATEEPFlagsDefectLinPositionByte      22 
#define cDATEEPFlagsDefectLinPositionBit        0xFF
#define mSERPeeResetU8BitEEPFlagsDefectLin()     \
      mSERPeeWriteU8Bit(Dbk, GroupSTKDTC,  22 ,  7 ,  8 , 0, Delayed)
#define mSERReadU8BitEEPFlagsDefectLinDefaultValueDefault() ((U8)0)
#define mSERReadU8BitEEPFlagsDefectLinDefault() \
      mSERPeeReadU8Bit(Dbk, GroupSTKDTC,  22 ,  7 ,  8 , Delayed)
#define mSERWriteU8BitEEPFlagsDefectLinDelayed(ValueToWrite) \
      mSERPeeWriteU8Bit(Dbk, GroupSTKDTC,  22 ,  7 ,  8 , (ValueToWrite), Delayed)
#define mSERWriteU8BitEEPFlagsDefectLinImmediate(ValueToWrite) \
      mSERPeeWriteU8Bit(Dbk, GroupSTKDTC,  22 ,  7 ,  8 , (ValueToWrite), Immediate)
#define mSERWriteU8BitEEPFlagsDefectLinDefault(ValueToWrite) \
      mSERPeeWriteU8Bit(Dbk, GroupSTKDTC,  22 ,  7 ,  8 , (ValueToWrite), Immediate)

// EEPDtcSelfDiag -- Group GroupSTKDTC, Byte  23  , Bit (MSB)  0  , SizeInBit  1 
#ifdef EEPDtcSelfDiag
  #error "Do not define EEPDtcSelfDiag, because this is a lexem used for concatenation."
#endif
#define cDATEEPDtcSelfDiagPositionByte      23 
#define cDATEEPDtcSelfDiagPositionBit       0 
#define mSERPeeResetU1BitEEPDtcSelfDiag()     \
      mSERPeeWriteU1Bit(Dbk, GroupSTKDTC,  23 ,  0 , 1, Delayed)
#define mSERReadU1BitEEPDtcSelfDiagDefaultValueDefault() ((BOOL)1)
#define mSERReadU1BitEEPDtcSelfDiagDefault() \
      mSERPeeReadU1Bit(Dbk, GroupSTKDTC,  23 ,  0 , Delayed)
#define mSERWriteU1BitEEPDtcSelfDiagDelayed(ValueToWrite) \
      mSERPeeWriteU1Bit(Dbk, GroupSTKDTC,  23 ,  0  , (ValueToWrite), Delayed)
#define mSERWriteU1BitEEPDtcSelfDiagImmediate(ValueToWrite) \
      mSERPeeWriteU1Bit(Dbk, GroupSTKDTC,  23 ,  0  , (ValueToWrite), Immediate)
#define mSERWriteU1BitEEPDtcSelfDiagDefault(ValueToWrite) \
      mSERPeeWriteU1Bit(Dbk, GroupSTKDTC,  23 ,  0  , (ValueToWrite), Immediate)

// EEP_DTCDatabase -- Group GroupDTC, Byte  0  , Bit (MSB)  7  , SizeInBit  640 
#ifdef EEP_DTCDatabase
  #error "Do not define EEP_DTCDatabase, because this is a lexem used for concatenation."
#endif
#define mSERPeeResetEEP_DTCDatabase()     \
{                                                     \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  0, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  1, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  2, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  3, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  4, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  5, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  6, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  7, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  8, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  9, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  10, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  11, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  12, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  13, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  14, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  15, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  16, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  17, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  18, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  19, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  20, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  21, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  22, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  23, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  24, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  25, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  26, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  27, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  28, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  29, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  30, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  31, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  32, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  33, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  34, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  35, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  36, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  37, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  38, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  39, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  40, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  41, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  42, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  43, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  44, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  45, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  46, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  47, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  48, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  49, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  50, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  51, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  52, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  53, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  54, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  55, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  56, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  57, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  58, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  59, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  60, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  61, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  62, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  63, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  64, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  65, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  66, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  67, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  68, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  69, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  70, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  71, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  72, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  73, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  74, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  75, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  76, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  77, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  78, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDTC,  0 ,  79, 0, Delayed) \
}
#define mSERReadTableU1BitEEP_DTCDatabaseDefaultValueDefault( Index ) \
      mSERPeeReadDefaultTable(U1Bit,Dbk, GroupDTC,  0 , Index, Delayed)

#define mSERReadTableU8BitEEP_DTCDatabaseDefault( Index ) \
      mSERPeeReadTable(U8Bit,Dbk, GroupDTC,  0 , Index, Delayed)
#define mSERWriteTableU8BitEEP_DTCDatabaseDelayed( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Dbk, GroupDTC,  0 , Index, (ValueToWrite), Delayed)
#define mSERWriteTableU8BitEEP_DTCDatabaseImmediate( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Dbk, GroupDTC,  0 , Index, (ValueToWrite), Immediate)
#define mSERWriteTableU8BitEEP_DTCDatabaseDefault( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Dbk, GroupDTC,  0 , Index, (ValueToWrite), Immediate)

// EEP_DIUpperLimit -- Group GroupDIUpperLimit, Byte  0  , Bit (MSB)  7  , SizeInBit  960 
#ifdef EEP_DIUpperLimit
  #error "Do not define EEP_DIUpperLimit, because this is a lexem used for concatenation."
#endif
#define mSERPeeResetEEP_DIUpperLimit()     \
{                                                     \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDIUpperLimit,  0 ,  0, 3000, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDIUpperLimit,  0 ,  1, 3000, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDIUpperLimit,  0 ,  2, 3000, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDIUpperLimit,  0 ,  3, 3000, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDIUpperLimit,  0 ,  4, 3000, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDIUpperLimit,  0 ,  5, 3000, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDIUpperLimit,  0 ,  6, 3000, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDIUpperLimit,  0 ,  7, 3000, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDIUpperLimit,  0 ,  8, 3000, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDIUpperLimit,  0 ,  9, 3000, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDIUpperLimit,  0 ,  10, 3000, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDIUpperLimit,  0 ,  11, 3000, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDIUpperLimit,  0 ,  12, 3000, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDIUpperLimit,  0 ,  13, 3000, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDIUpperLimit,  0 ,  14, 900, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDIUpperLimit,  0 ,  15, 16000, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDIUpperLimit,  0 ,  16, 900, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDIUpperLimit,  0 ,  17, 45, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDIUpperLimit,  0 ,  18, 12000, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDIUpperLimit,  0 ,  19, 900, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDIUpperLimit,  0 ,  20, 900, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDIUpperLimit,  0 ,  21, 900, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDIUpperLimit,  0 ,  22, 900, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDIUpperLimit,  0 ,  23, 16000, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDIUpperLimit,  0 ,  24, 900, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDIUpperLimit,  0 ,  25, 160, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDIUpperLimit,  0 ,  26, 12000, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDIUpperLimit,  0 ,  27, 900, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDIUpperLimit,  0 ,  28, 900, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDIUpperLimit,  0 ,  29, 900, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDIUpperLimit,  0 ,  30, 900, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDIUpperLimit,  0 ,  31, 16000, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDIUpperLimit,  0 ,  32, 45, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDIUpperLimit,  0 ,  33, 160, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDIUpperLimit,  0 ,  34, 900, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDIUpperLimit,  0 ,  35, 900, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDIUpperLimit,  0 ,  36, 900, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDIUpperLimit,  0 ,  37, 16000, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDIUpperLimit,  0 ,  38, 12000, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDIUpperLimit,  0 ,  39, 900, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDIUpperLimit,  0 ,  40, 900, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDIUpperLimit,  0 ,  41, 900, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDIUpperLimit,  0 ,  42, 900, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDIUpperLimit,  0 ,  43, 900, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDIUpperLimit,  0 ,  44, 16000, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDIUpperLimit,  0 ,  45, 900, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDIUpperLimit,  0 ,  46, 900, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDIUpperLimit,  0 ,  47, 900, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDIUpperLimit,  0 ,  48, 16000, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDIUpperLimit,  0 ,  49, 12000, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDIUpperLimit,  0 ,  50, 900, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDIUpperLimit,  0 ,  51, 900, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDIUpperLimit,  0 ,  52, 900, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDIUpperLimit,  0 ,  53, 900, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDIUpperLimit,  0 ,  54, 900, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDIUpperLimit,  0 ,  55, 16000, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDIUpperLimit,  0 ,  56, 12000, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDIUpperLimit,  0 ,  57, 12000, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDIUpperLimit,  0 ,  58, 12000, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDIUpperLimit,  0 ,  59, 12000, Delayed) \
}
#define mSERReadTableU1BitEEP_DIUpperLimitDefaultValueDefault( Index ) \
      mSERPeeReadDefaultTable(U1Bit,Dbk, GroupDIUpperLimit,  0 , Index, Delayed)

#define mSERReadTableU16BitEEP_DIUpperLimitDefault( Index ) \
      mSERPeeReadTable(U16Bit,Dbk, GroupDIUpperLimit,  0 , Index, Delayed)
#define mSERWriteTableU16BitEEP_DIUpperLimitDelayed( Index, ValueToWrite ) \
      mSERPeeWriteTable(U16Bit,Dbk, GroupDIUpperLimit,  0 , Index, (ValueToWrite), Delayed)
#define mSERWriteTableU16BitEEP_DIUpperLimitImmediate( Index, ValueToWrite ) \
      mSERPeeWriteTable(U16Bit,Dbk, GroupDIUpperLimit,  0 , Index, (ValueToWrite), Immediate)
#define mSERWriteTableU16BitEEP_DIUpperLimitDefault( Index, ValueToWrite ) \
      mSERPeeWriteTable(U16Bit,Dbk, GroupDIUpperLimit,  0 , Index, (ValueToWrite), Immediate)

// EEP_DILowerLimit -- Group GroupDILowerLimit, Byte  0  , Bit (MSB)  7  , SizeInBit  960 
#ifdef EEP_DILowerLimit
  #error "Do not define EEP_DILowerLimit, because this is a lexem used for concatenation."
#endif
#define mSERPeeResetEEP_DILowerLimit()     \
{                                                     \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDILowerLimit,  0 ,  0, 600, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDILowerLimit,  0 ,  1, 600, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDILowerLimit,  0 ,  2, 600, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDILowerLimit,  0 ,  3, 600, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDILowerLimit,  0 ,  4, 600, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDILowerLimit,  0 ,  5, 600, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDILowerLimit,  0 ,  6, 600, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDILowerLimit,  0 ,  7, 600, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDILowerLimit,  0 ,  8, 600, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDILowerLimit,  0 ,  9, 600, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDILowerLimit,  0 ,  10, 600, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDILowerLimit,  0 ,  11, 600, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDILowerLimit,  0 ,  12, 600, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDILowerLimit,  0 ,  13, 600, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDILowerLimit,  0 ,  14, 500, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDILowerLimit,  0 ,  15, 12000, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDILowerLimit,  0 ,  16, 500, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDILowerLimit,  0 ,  17, 44, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDILowerLimit,  0 ,  18, 11000, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDILowerLimit,  0 ,  19, 500, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDILowerLimit,  0 ,  20, 500, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDILowerLimit,  0 ,  21, 500, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDILowerLimit,  0 ,  22, 500, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDILowerLimit,  0 ,  23, 12000, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDILowerLimit,  0 ,  24, 500, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDILowerLimit,  0 ,  25, 159, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDILowerLimit,  0 ,  26, 11000, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDILowerLimit,  0 ,  27, 500, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDILowerLimit,  0 ,  28, 500, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDILowerLimit,  0 ,  29, 500, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDILowerLimit,  0 ,  30, 500, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDILowerLimit,  0 ,  31, 12000, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDILowerLimit,  0 ,  32, 44, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDILowerLimit,  0 ,  33, 159, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDILowerLimit,  0 ,  34, 500, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDILowerLimit,  0 ,  35, 500, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDILowerLimit,  0 ,  36, 500, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDILowerLimit,  0 ,  37, 12000, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDILowerLimit,  0 ,  38, 11000, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDILowerLimit,  0 ,  39, 500, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDILowerLimit,  0 ,  40, 500, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDILowerLimit,  0 ,  41, 500, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDILowerLimit,  0 ,  42, 500, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDILowerLimit,  0 ,  43, 500, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDILowerLimit,  0 ,  44, 11000, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDILowerLimit,  0 ,  45, 500, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDILowerLimit,  0 ,  46, 500, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDILowerLimit,  0 ,  47, 500, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDILowerLimit,  0 ,  48, 11000, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDILowerLimit,  0 ,  49, 11000, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDILowerLimit,  0 ,  50, 500, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDILowerLimit,  0 ,  51, 500, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDILowerLimit,  0 ,  52, 500, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDILowerLimit,  0 ,  53, 500, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDILowerLimit,  0 ,  54, 500, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDILowerLimit,  0 ,  55, 12000, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDILowerLimit,  0 ,  56, 11000, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDILowerLimit,  0 ,  57, 11000, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDILowerLimit,  0 ,  58, 11000, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupDILowerLimit,  0 ,  59, 11000, Delayed) \
}
#define mSERReadTableU1BitEEP_DILowerLimitDefaultValueDefault( Index ) \
      mSERPeeReadDefaultTable(U1Bit,Dbk, GroupDILowerLimit,  0 , Index, Delayed)

#define mSERReadTableU16BitEEP_DILowerLimitDefault( Index ) \
      mSERPeeReadTable(U16Bit,Dbk, GroupDILowerLimit,  0 , Index, Delayed)
#define mSERWriteTableU16BitEEP_DILowerLimitDelayed( Index, ValueToWrite ) \
      mSERPeeWriteTable(U16Bit,Dbk, GroupDILowerLimit,  0 , Index, (ValueToWrite), Delayed)
#define mSERWriteTableU16BitEEP_DILowerLimitImmediate( Index, ValueToWrite ) \
      mSERPeeWriteTable(U16Bit,Dbk, GroupDILowerLimit,  0 , Index, (ValueToWrite), Immediate)
#define mSERWriteTableU16BitEEP_DILowerLimitDefault( Index, ValueToWrite ) \
      mSERPeeWriteTable(U16Bit,Dbk, GroupDILowerLimit,  0 , Index, (ValueToWrite), Immediate)

// EEP_DIType -- Group GroupDIType, Byte  0  , Bit (MSB)  7  , SizeInBit  120 
#ifdef EEP_DIType
  #error "Do not define EEP_DIType, because this is a lexem used for concatenation."
#endif
#define mSERPeeResetEEP_DIType()     \
{                                                     \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDIType,  0 ,  0, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDIType,  0 ,  1, 5, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDIType,  0 ,  2, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDIType,  0 ,  3, 45, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDIType,  0 ,  4, 1, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDIType,  0 ,  5, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDIType,  0 ,  6, 54, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDIType,  0 ,  7, 55, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDIType,  0 ,  8, 1, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDIType,  0 ,  9, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDIType,  0 ,  10, 54, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDIType,  0 ,  11, 55, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDIType,  0 ,  12, 15, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDIType,  0 ,  13, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupDIType,  0 ,  14, 0, Delayed) \
}
#define mSERReadTableU1BitEEP_DITypeDefaultValueDefault( Index ) \
      mSERPeeReadDefaultTable(U1Bit,Dbk, GroupDIType,  0 , Index, Delayed)

#define mSERReadTableU8BitEEP_DITypeDefault( Index ) \
      mSERPeeReadTable(U8Bit,Dbk, GroupDIType,  0 , Index, Delayed)
#define mSERWriteTableU8BitEEP_DITypeDelayed( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Dbk, GroupDIType,  0 , Index, (ValueToWrite), Delayed)
#define mSERWriteTableU8BitEEP_DITypeImmediate( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Dbk, GroupDIType,  0 , Index, (ValueToWrite), Immediate)
#define mSERWriteTableU8BitEEP_DITypeDefault( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Dbk, GroupDIType,  0 , Index, (ValueToWrite), Immediate)

// EEP_OpenTime -- Group GroupSensorCal, Byte  0  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_OpenTime
  #error "Do not define EEP_OpenTime, because this is a lexem used for concatenation."
#endif
#define cDATEEP_OpenTimePositionByte      0 
#define cDATEEP_OpenTimePositionBit        0xFF
#define mSERPeeResetU16BitEEP_OpenTime()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal,  0 ,  7 ,  16 , 3500, Delayed)
#define mSERReadU16BitEEP_OpenTimeDefaultValueDefault() ((U16)3500)
#define mSERReadU16BitEEP_OpenTimeDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal,  0 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_OpenTimeDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal,  0 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_OpenTimeImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal,  0 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_OpenTimeDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal,  0 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_CloseTime -- Group GroupSensorCal, Byte  2  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_CloseTime
  #error "Do not define EEP_CloseTime, because this is a lexem used for concatenation."
#endif
#define cDATEEP_CloseTimePositionByte      2 
#define cDATEEP_CloseTimePositionBit        0xFF
#define mSERPeeResetU16BitEEP_CloseTime()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal,  2 ,  7 ,  16 , 3500, Delayed)
#define mSERReadU16BitEEP_CloseTimeDefaultValueDefault() ((U16)3500)
#define mSERReadU16BitEEP_CloseTimeDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal,  2 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_CloseTimeDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal,  2 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_CloseTimeImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal,  2 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_CloseTimeDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal,  2 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_FrontPumpRunDistance -- Group GroupSensorCal, Byte  4  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_FrontPumpRunDistance
  #error "Do not define EEP_FrontPumpRunDistance, because this is a lexem used for concatenation."
#endif
#define cDATEEP_FrontPumpRunDistancePositionByte      4 
#define cDATEEP_FrontPumpRunDistancePositionBit        0xFF
#define mSERPeeResetU16BitEEP_FrontPumpRunDistance()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal,  4 ,  7 ,  16 , 135, Delayed)
#define mSERReadU16BitEEP_FrontPumpRunDistanceDefaultValueDefault() ((U16)135)
#define mSERReadU16BitEEP_FrontPumpRunDistanceDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal,  4 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_FrontPumpRunDistanceDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal,  4 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_FrontPumpRunDistanceImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal,  4 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_FrontPumpRunDistanceDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal,  4 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_BackPumpRunDistance -- Group GroupSensorCal, Byte  6  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_BackPumpRunDistance
  #error "Do not define EEP_BackPumpRunDistance, because this is a lexem used for concatenation."
#endif
#define cDATEEP_BackPumpRunDistancePositionByte      6 
#define cDATEEP_BackPumpRunDistancePositionBit        0xFF
#define mSERPeeResetU16BitEEP_BackPumpRunDistance()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal,  6 ,  7 ,  16 , 100, Delayed)
#define mSERReadU16BitEEP_BackPumpRunDistanceDefaultValueDefault() ((U16)100)
#define mSERReadU16BitEEP_BackPumpRunDistanceDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal,  6 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_BackPumpRunDistanceDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal,  6 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_BackPumpRunDistanceImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal,  6 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_BackPumpRunDistanceDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal,  6 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_FrontOpenSensorVol -- Group GroupSensorCal, Byte  8  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_FrontOpenSensorVol
  #error "Do not define EEP_FrontOpenSensorVol, because this is a lexem used for concatenation."
#endif
#define cDATEEP_FrontOpenSensorVolPositionByte      8 
#define cDATEEP_FrontOpenSensorVolPositionBit        0xFF
#define mSERPeeResetU16BitEEP_FrontOpenSensorVol()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal,  8 ,  7 ,  16 , 4000, Delayed)
#define mSERReadU16BitEEP_FrontOpenSensorVolDefaultValueDefault() ((U16)4000)
#define mSERReadU16BitEEP_FrontOpenSensorVolDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal,  8 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_FrontOpenSensorVolDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal,  8 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_FrontOpenSensorVolImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal,  8 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_FrontOpenSensorVolDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal,  8 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_BackOpenSensorVol -- Group GroupSensorCal, Byte  10  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_BackOpenSensorVol
  #error "Do not define EEP_BackOpenSensorVol, because this is a lexem used for concatenation."
#endif
#define cDATEEP_BackOpenSensorVolPositionByte      10 
#define cDATEEP_BackOpenSensorVolPositionBit        0xFF
#define mSERPeeResetU16BitEEP_BackOpenSensorVol()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal,  10 ,  7 ,  16 , 4000, Delayed)
#define mSERReadU16BitEEP_BackOpenSensorVolDefaultValueDefault() ((U16)4000)
#define mSERReadU16BitEEP_BackOpenSensorVolDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal,  10 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_BackOpenSensorVolDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal,  10 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_BackOpenSensorVolImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal,  10 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_BackOpenSensorVolDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal,  10 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_FrontCloseSensorVol -- Group GroupSensorCal, Byte  12  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_FrontCloseSensorVol
  #error "Do not define EEP_FrontCloseSensorVol, because this is a lexem used for concatenation."
#endif
#define cDATEEP_FrontCloseSensorVolPositionByte      12 
#define cDATEEP_FrontCloseSensorVolPositionBit        0xFF
#define mSERPeeResetU16BitEEP_FrontCloseSensorVol()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal,  12 ,  7 ,  16 , 1000, Delayed)
#define mSERReadU16BitEEP_FrontCloseSensorVolDefaultValueDefault() ((U16)1000)
#define mSERReadU16BitEEP_FrontCloseSensorVolDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal,  12 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_FrontCloseSensorVolDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal,  12 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_FrontCloseSensorVolImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal,  12 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_FrontCloseSensorVolDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal,  12 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_BackCloseSensorVol -- Group GroupSensorCal, Byte  14  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_BackCloseSensorVol
  #error "Do not define EEP_BackCloseSensorVol, because this is a lexem used for concatenation."
#endif
#define cDATEEP_BackCloseSensorVolPositionByte      14 
#define cDATEEP_BackCloseSensorVolPositionBit        0xFF
#define mSERPeeResetU16BitEEP_BackCloseSensorVol()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal,  14 ,  7 ,  16 , 1000, Delayed)
#define mSERReadU16BitEEP_BackCloseSensorVolDefaultValueDefault() ((U16)1000)
#define mSERReadU16BitEEP_BackCloseSensorVolDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal,  14 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_BackCloseSensorVolDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal,  14 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_BackCloseSensorVolImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal,  14 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_BackCloseSensorVolDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal,  14 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_FrontOpenGradePercent -- Group GroupSensorCal, Byte  16  , Bit (MSB)  7  , SizeInBit  80 
#ifdef EEP_FrontOpenGradePercent
  #error "Do not define EEP_FrontOpenGradePercent, because this is a lexem used for concatenation."
#endif
#define mSERPeeResetEEP_FrontOpenGradePercent()     \
{                                                     \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal,  16 ,  0, 10, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal,  16 ,  1, 10, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal,  16 ,  2, 10, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal,  16 ,  3, 10, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal,  16 ,  4, 10, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal,  16 ,  5, 10, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal,  16 ,  6, 10, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal,  16 ,  7, 10, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal,  16 ,  8, 10, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal,  16 ,  9, 10, Delayed) \
}
#define mSERReadTableU1BitEEP_FrontOpenGradePercentDefaultValueDefault( Index ) \
      mSERPeeReadDefaultTable(U1Bit,Dbk, GroupSensorCal,  16 , Index, Delayed)

#define mSERReadTableU8BitEEP_FrontOpenGradePercentDefault( Index ) \
      mSERPeeReadTable(U8Bit,Dbk, GroupSensorCal,  16 , Index, Delayed)
#define mSERWriteTableU8BitEEP_FrontOpenGradePercentDelayed( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Dbk, GroupSensorCal,  16 , Index, (ValueToWrite), Delayed)
#define mSERWriteTableU8BitEEP_FrontOpenGradePercentImmediate( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Dbk, GroupSensorCal,  16 , Index, (ValueToWrite), Immediate)
#define mSERWriteTableU8BitEEP_FrontOpenGradePercentDefault( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Dbk, GroupSensorCal,  16 , Index, (ValueToWrite), Immediate)

// EEP_BackOpenGradePercent -- Group GroupSensorCal, Byte  26  , Bit (MSB)  7  , SizeInBit  80 
#ifdef EEP_BackOpenGradePercent
  #error "Do not define EEP_BackOpenGradePercent, because this is a lexem used for concatenation."
#endif
#define mSERPeeResetEEP_BackOpenGradePercent()     \
{                                                     \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal,  26 ,  0, 10, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal,  26 ,  1, 10, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal,  26 ,  2, 10, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal,  26 ,  3, 10, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal,  26 ,  4, 10, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal,  26 ,  5, 10, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal,  26 ,  6, 10, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal,  26 ,  7, 10, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal,  26 ,  8, 10, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal,  26 ,  9, 10, Delayed) \
}
#define mSERReadTableU1BitEEP_BackOpenGradePercentDefaultValueDefault( Index ) \
      mSERPeeReadDefaultTable(U1Bit,Dbk, GroupSensorCal,  26 , Index, Delayed)

#define mSERReadTableU8BitEEP_BackOpenGradePercentDefault( Index ) \
      mSERPeeReadTable(U8Bit,Dbk, GroupSensorCal,  26 , Index, Delayed)
#define mSERWriteTableU8BitEEP_BackOpenGradePercentDelayed( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Dbk, GroupSensorCal,  26 , Index, (ValueToWrite), Delayed)
#define mSERWriteTableU8BitEEP_BackOpenGradePercentImmediate( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Dbk, GroupSensorCal,  26 , Index, (ValueToWrite), Immediate)
#define mSERWriteTableU8BitEEP_BackOpenGradePercentDefault( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Dbk, GroupSensorCal,  26 , Index, (ValueToWrite), Immediate)

// EEP_FrontOpenGradeLimitTime -- Group GroupSensorCal, Byte  36  , Bit (MSB)  7  , SizeInBit  160 
#ifdef EEP_FrontOpenGradeLimitTime
  #error "Do not define EEP_FrontOpenGradeLimitTime, because this is a lexem used for concatenation."
#endif
#define mSERPeeResetEEP_FrontOpenGradeLimitTime()     \
{                                                     \
   mSERPeeWriteTable(U16Bit,Dbk,GroupSensorCal,  36 ,  0, 80, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupSensorCal,  36 ,  1, 80, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupSensorCal,  36 ,  2, 80, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupSensorCal,  36 ,  3, 80, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupSensorCal,  36 ,  4, 80, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupSensorCal,  36 ,  5, 80, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupSensorCal,  36 ,  6, 80, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupSensorCal,  36 ,  7, 80, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupSensorCal,  36 ,  8, 80, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupSensorCal,  36 ,  9, 80, Delayed) \
}
#define mSERReadTableU1BitEEP_FrontOpenGradeLimitTimeDefaultValueDefault( Index ) \
      mSERPeeReadDefaultTable(U1Bit,Dbk, GroupSensorCal,  36 , Index, Delayed)

#define mSERReadTableU16BitEEP_FrontOpenGradeLimitTimeDefault( Index ) \
      mSERPeeReadTable(U16Bit,Dbk, GroupSensorCal,  36 , Index, Delayed)
#define mSERWriteTableU16BitEEP_FrontOpenGradeLimitTimeDelayed( Index, ValueToWrite ) \
      mSERPeeWriteTable(U16Bit,Dbk, GroupSensorCal,  36 , Index, (ValueToWrite), Delayed)
#define mSERWriteTableU16BitEEP_FrontOpenGradeLimitTimeImmediate( Index, ValueToWrite ) \
      mSERPeeWriteTable(U16Bit,Dbk, GroupSensorCal,  36 , Index, (ValueToWrite), Immediate)
#define mSERWriteTableU16BitEEP_FrontOpenGradeLimitTimeDefault( Index, ValueToWrite ) \
      mSERPeeWriteTable(U16Bit,Dbk, GroupSensorCal,  36 , Index, (ValueToWrite), Immediate)

// EEP_BackOpenGradeLimitTime -- Group GroupSensorCal, Byte  56  , Bit (MSB)  7  , SizeInBit  160 
#ifdef EEP_BackOpenGradeLimitTime
  #error "Do not define EEP_BackOpenGradeLimitTime, because this is a lexem used for concatenation."
#endif
#define mSERPeeResetEEP_BackOpenGradeLimitTime()     \
{                                                     \
   mSERPeeWriteTable(U16Bit,Dbk,GroupSensorCal,  56 ,  0, 80, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupSensorCal,  56 ,  1, 80, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupSensorCal,  56 ,  2, 80, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupSensorCal,  56 ,  3, 80, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupSensorCal,  56 ,  4, 80, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupSensorCal,  56 ,  5, 80, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupSensorCal,  56 ,  6, 80, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupSensorCal,  56 ,  7, 80, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupSensorCal,  56 ,  8, 80, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupSensorCal,  56 ,  9, 80, Delayed) \
}
#define mSERReadTableU1BitEEP_BackOpenGradeLimitTimeDefaultValueDefault( Index ) \
      mSERPeeReadDefaultTable(U1Bit,Dbk, GroupSensorCal,  56 , Index, Delayed)

#define mSERReadTableU16BitEEP_BackOpenGradeLimitTimeDefault( Index ) \
      mSERPeeReadTable(U16Bit,Dbk, GroupSensorCal,  56 , Index, Delayed)
#define mSERWriteTableU16BitEEP_BackOpenGradeLimitTimeDelayed( Index, ValueToWrite ) \
      mSERPeeWriteTable(U16Bit,Dbk, GroupSensorCal,  56 , Index, (ValueToWrite), Delayed)
#define mSERWriteTableU16BitEEP_BackOpenGradeLimitTimeImmediate( Index, ValueToWrite ) \
      mSERPeeWriteTable(U16Bit,Dbk, GroupSensorCal,  56 , Index, (ValueToWrite), Immediate)
#define mSERWriteTableU16BitEEP_BackOpenGradeLimitTimeDefault( Index, ValueToWrite ) \
      mSERPeeWriteTable(U16Bit,Dbk, GroupSensorCal,  56 , Index, (ValueToWrite), Immediate)

// EEP_FrontCloseGradePercent -- Group GroupSensorCal, Byte  76  , Bit (MSB)  7  , SizeInBit  80 
#ifdef EEP_FrontCloseGradePercent
  #error "Do not define EEP_FrontCloseGradePercent, because this is a lexem used for concatenation."
#endif
#define mSERPeeResetEEP_FrontCloseGradePercent()     \
{                                                     \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal,  76 ,  0, 10, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal,  76 ,  1, 10, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal,  76 ,  2, 10, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal,  76 ,  3, 10, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal,  76 ,  4, 10, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal,  76 ,  5, 10, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal,  76 ,  6, 10, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal,  76 ,  7, 10, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal,  76 ,  8, 10, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal,  76 ,  9, 10, Delayed) \
}
#define mSERReadTableU1BitEEP_FrontCloseGradePercentDefaultValueDefault( Index ) \
      mSERPeeReadDefaultTable(U1Bit,Dbk, GroupSensorCal,  76 , Index, Delayed)

#define mSERReadTableU8BitEEP_FrontCloseGradePercentDefault( Index ) \
      mSERPeeReadTable(U8Bit,Dbk, GroupSensorCal,  76 , Index, Delayed)
#define mSERWriteTableU8BitEEP_FrontCloseGradePercentDelayed( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Dbk, GroupSensorCal,  76 , Index, (ValueToWrite), Delayed)
#define mSERWriteTableU8BitEEP_FrontCloseGradePercentImmediate( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Dbk, GroupSensorCal,  76 , Index, (ValueToWrite), Immediate)
#define mSERWriteTableU8BitEEP_FrontCloseGradePercentDefault( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Dbk, GroupSensorCal,  76 , Index, (ValueToWrite), Immediate)

// EEP_BackCloseGradePercent -- Group GroupSensorCal, Byte  86  , Bit (MSB)  7  , SizeInBit  80 
#ifdef EEP_BackCloseGradePercent
  #error "Do not define EEP_BackCloseGradePercent, because this is a lexem used for concatenation."
#endif
#define mSERPeeResetEEP_BackCloseGradePercent()     \
{                                                     \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal,  86 ,  0, 10, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal,  86 ,  1, 10, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal,  86 ,  2, 10, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal,  86 ,  3, 10, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal,  86 ,  4, 10, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal,  86 ,  5, 10, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal,  86 ,  6, 10, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal,  86 ,  7, 10, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal,  86 ,  8, 10, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal,  86 ,  9, 10, Delayed) \
}
#define mSERReadTableU1BitEEP_BackCloseGradePercentDefaultValueDefault( Index ) \
      mSERPeeReadDefaultTable(U1Bit,Dbk, GroupSensorCal,  86 , Index, Delayed)

#define mSERReadTableU8BitEEP_BackCloseGradePercentDefault( Index ) \
      mSERPeeReadTable(U8Bit,Dbk, GroupSensorCal,  86 , Index, Delayed)
#define mSERWriteTableU8BitEEP_BackCloseGradePercentDelayed( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Dbk, GroupSensorCal,  86 , Index, (ValueToWrite), Delayed)
#define mSERWriteTableU8BitEEP_BackCloseGradePercentImmediate( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Dbk, GroupSensorCal,  86 , Index, (ValueToWrite), Immediate)
#define mSERWriteTableU8BitEEP_BackCloseGradePercentDefault( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Dbk, GroupSensorCal,  86 , Index, (ValueToWrite), Immediate)

// EEP_FrontCloseGradeLimitTime -- Group GroupSensorCal, Byte  96  , Bit (MSB)  7  , SizeInBit  160 
#ifdef EEP_FrontCloseGradeLimitTime
  #error "Do not define EEP_FrontCloseGradeLimitTime, because this is a lexem used for concatenation."
#endif
#define mSERPeeResetEEP_FrontCloseGradeLimitTime()     \
{                                                     \
   mSERPeeWriteTable(U16Bit,Dbk,GroupSensorCal,  96 ,  0, 80, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupSensorCal,  96 ,  1, 80, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupSensorCal,  96 ,  2, 80, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupSensorCal,  96 ,  3, 80, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupSensorCal,  96 ,  4, 80, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupSensorCal,  96 ,  5, 80, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupSensorCal,  96 ,  6, 80, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupSensorCal,  96 ,  7, 80, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupSensorCal,  96 ,  8, 80, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupSensorCal,  96 ,  9, 80, Delayed) \
}
#define mSERReadTableU1BitEEP_FrontCloseGradeLimitTimeDefaultValueDefault( Index ) \
      mSERPeeReadDefaultTable(U1Bit,Dbk, GroupSensorCal,  96 , Index, Delayed)

#define mSERReadTableU16BitEEP_FrontCloseGradeLimitTimeDefault( Index ) \
      mSERPeeReadTable(U16Bit,Dbk, GroupSensorCal,  96 , Index, Delayed)
#define mSERWriteTableU16BitEEP_FrontCloseGradeLimitTimeDelayed( Index, ValueToWrite ) \
      mSERPeeWriteTable(U16Bit,Dbk, GroupSensorCal,  96 , Index, (ValueToWrite), Delayed)
#define mSERWriteTableU16BitEEP_FrontCloseGradeLimitTimeImmediate( Index, ValueToWrite ) \
      mSERPeeWriteTable(U16Bit,Dbk, GroupSensorCal,  96 , Index, (ValueToWrite), Immediate)
#define mSERWriteTableU16BitEEP_FrontCloseGradeLimitTimeDefault( Index, ValueToWrite ) \
      mSERPeeWriteTable(U16Bit,Dbk, GroupSensorCal,  96 , Index, (ValueToWrite), Immediate)

// EEP_BackCloseGradeLimitTime -- Group GroupSensorCal, Byte  116  , Bit (MSB)  7  , SizeInBit  160 
#ifdef EEP_BackCloseGradeLimitTime
  #error "Do not define EEP_BackCloseGradeLimitTime, because this is a lexem used for concatenation."
#endif
#define mSERPeeResetEEP_BackCloseGradeLimitTime()     \
{                                                     \
   mSERPeeWriteTable(U16Bit,Dbk,GroupSensorCal,  116 ,  0, 80, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupSensorCal,  116 ,  1, 80, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupSensorCal,  116 ,  2, 80, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupSensorCal,  116 ,  3, 80, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupSensorCal,  116 ,  4, 80, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupSensorCal,  116 ,  5, 80, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupSensorCal,  116 ,  6, 80, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupSensorCal,  116 ,  7, 80, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupSensorCal,  116 ,  8, 80, Delayed) \
   mSERPeeWriteTable(U16Bit,Dbk,GroupSensorCal,  116 ,  9, 80, Delayed) \
}
#define mSERReadTableU1BitEEP_BackCloseGradeLimitTimeDefaultValueDefault( Index ) \
      mSERPeeReadDefaultTable(U1Bit,Dbk, GroupSensorCal,  116 , Index, Delayed)

#define mSERReadTableU16BitEEP_BackCloseGradeLimitTimeDefault( Index ) \
      mSERPeeReadTable(U16Bit,Dbk, GroupSensorCal,  116 , Index, Delayed)
#define mSERWriteTableU16BitEEP_BackCloseGradeLimitTimeDelayed( Index, ValueToWrite ) \
      mSERPeeWriteTable(U16Bit,Dbk, GroupSensorCal,  116 , Index, (ValueToWrite), Delayed)
#define mSERWriteTableU16BitEEP_BackCloseGradeLimitTimeImmediate( Index, ValueToWrite ) \
      mSERPeeWriteTable(U16Bit,Dbk, GroupSensorCal,  116 , Index, (ValueToWrite), Immediate)
#define mSERWriteTableU16BitEEP_BackCloseGradeLimitTimeDefault( Index, ValueToWrite ) \
      mSERPeeWriteTable(U16Bit,Dbk, GroupSensorCal,  116 , Index, (ValueToWrite), Immediate)

// EEP_StartTime -- Group GroupSensorCal1, Byte  0  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_StartTime
  #error "Do not define EEP_StartTime, because this is a lexem used for concatenation."
#endif
#define cDATEEP_StartTimePositionByte      0 
#define cDATEEP_StartTimePositionBit        0xFF
#define mSERPeeResetU16BitEEP_StartTime()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  0 ,  7 ,  16 , 300, Delayed)
#define mSERReadU16BitEEP_StartTimeDefaultValueDefault() ((U16)300)
#define mSERReadU16BitEEP_StartTimeDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal1,  0 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_StartTimeDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  0 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_StartTimeImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  0 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_StartTimeDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  0 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_FrontPinchDistance -- Group GroupSensorCal1, Byte  2  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_FrontPinchDistance
  #error "Do not define EEP_FrontPinchDistance, because this is a lexem used for concatenation."
#endif
#define cDATEEP_FrontPinchDistancePositionByte      2 
#define cDATEEP_FrontPinchDistancePositionBit        0xFF
#define mSERPeeResetU16BitEEP_FrontPinchDistance()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  2 ,  7 ,  16 , 100, Delayed)
#define mSERReadU16BitEEP_FrontPinchDistanceDefaultValueDefault() ((U16)100)
#define mSERReadU16BitEEP_FrontPinchDistanceDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal1,  2 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_FrontPinchDistanceDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  2 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_FrontPinchDistanceImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  2 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_FrontPinchDistanceDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  2 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_BackPinchDistance -- Group GroupSensorCal1, Byte  4  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_BackPinchDistance
  #error "Do not define EEP_BackPinchDistance, because this is a lexem used for concatenation."
#endif
#define cDATEEP_BackPinchDistancePositionByte      4 
#define cDATEEP_BackPinchDistancePositionBit        0xFF
#define mSERPeeResetU16BitEEP_BackPinchDistance()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  4 ,  7 ,  16 , 100, Delayed)
#define mSERReadU16BitEEP_BackPinchDistanceDefaultValueDefault() ((U16)100)
#define mSERReadU16BitEEP_BackPinchDistanceDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal1,  4 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_BackPinchDistanceDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  4 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_BackPinchDistanceImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  4 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_BackPinchDistanceDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  4 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_AirBagMaxValidDistance -- Group GroupSensorCal1, Byte  6  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_AirBagMaxValidDistance
  #error "Do not define EEP_AirBagMaxValidDistance, because this is a lexem used for concatenation."
#endif
#define cDATEEP_AirBagMaxValidDistancePositionByte      6 
#define cDATEEP_AirBagMaxValidDistancePositionBit        0xFF
#define mSERPeeResetU16BitEEP_AirBagMaxValidDistance()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  6 ,  7 ,  16 , 500, Delayed)
#define mSERReadU16BitEEP_AirBagMaxValidDistanceDefaultValueDefault() ((U16)500)
#define mSERReadU16BitEEP_AirBagMaxValidDistanceDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal1,  6 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_AirBagMaxValidDistanceDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  6 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_AirBagMaxValidDistanceImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  6 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_AirBagMaxValidDistanceDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  6 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_OpenValueShortPowDelayTime -- Group GroupSensorCal1, Byte  8  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_OpenValueShortPowDelayTime
  #error "Do not define EEP_OpenValueShortPowDelayTime, because this is a lexem used for concatenation."
#endif
#define cDATEEP_OpenValueShortPowDelayTimePositionByte      8 
#define cDATEEP_OpenValueShortPowDelayTimePositionBit        0xFF
#define mSERPeeResetU16BitEEP_OpenValueShortPowDelayTime()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  8 ,  7 ,  16 , 300, Delayed)
#define mSERReadU16BitEEP_OpenValueShortPowDelayTimeDefaultValueDefault() ((U16)300)
#define mSERReadU16BitEEP_OpenValueShortPowDelayTimeDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal1,  8 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_OpenValueShortPowDelayTimeDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  8 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_OpenValueShortPowDelayTimeImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  8 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_OpenValueShortPowDelayTimeDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  8 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_OpenValueShortPowKeepTime -- Group GroupSensorCal1, Byte  10  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_OpenValueShortPowKeepTime
  #error "Do not define EEP_OpenValueShortPowKeepTime, because this is a lexem used for concatenation."
#endif
#define cDATEEP_OpenValueShortPowKeepTimePositionByte      10 
#define cDATEEP_OpenValueShortPowKeepTimePositionBit        0xFF
#define mSERPeeResetU16BitEEP_OpenValueShortPowKeepTime()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  10 ,  7 ,  16 , 200, Delayed)
#define mSERReadU16BitEEP_OpenValueShortPowKeepTimeDefaultValueDefault() ((U16)200)
#define mSERReadU16BitEEP_OpenValueShortPowKeepTimeDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal1,  10 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_OpenValueShortPowKeepTimeDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  10 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_OpenValueShortPowKeepTimeImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  10 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_OpenValueShortPowKeepTimeDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  10 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_OpenValueShortPowVol -- Group GroupSensorCal1, Byte  12  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_OpenValueShortPowVol
  #error "Do not define EEP_OpenValueShortPowVol, because this is a lexem used for concatenation."
#endif
#define cDATEEP_OpenValueShortPowVolPositionByte      12 
#define cDATEEP_OpenValueShortPowVolPositionBit        0xFF
#define mSERPeeResetU16BitEEP_OpenValueShortPowVol()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  12 ,  7 ,  16 , 16500, Delayed)
#define mSERReadU16BitEEP_OpenValueShortPowVolDefaultValueDefault() ((U16)16500)
#define mSERReadU16BitEEP_OpenValueShortPowVolDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal1,  12 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_OpenValueShortPowVolDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  12 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_OpenValueShortPowVolImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  12 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_OpenValueShortPowVolDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  12 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_OpenValueShortGndDelayTime -- Group GroupSensorCal1, Byte  14  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_OpenValueShortGndDelayTime
  #error "Do not define EEP_OpenValueShortGndDelayTime, because this is a lexem used for concatenation."
#endif
#define cDATEEP_OpenValueShortGndDelayTimePositionByte      14 
#define cDATEEP_OpenValueShortGndDelayTimePositionBit        0xFF
#define mSERPeeResetU16BitEEP_OpenValueShortGndDelayTime()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  14 ,  7 ,  16 , 300, Delayed)
#define mSERReadU16BitEEP_OpenValueShortGndDelayTimeDefaultValueDefault() ((U16)300)
#define mSERReadU16BitEEP_OpenValueShortGndDelayTimeDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal1,  14 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_OpenValueShortGndDelayTimeDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  14 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_OpenValueShortGndDelayTimeImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  14 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_OpenValueShortGndDelayTimeDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  14 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_OpenValueShortGndKeepTime -- Group GroupSensorCal1, Byte  16  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_OpenValueShortGndKeepTime
  #error "Do not define EEP_OpenValueShortGndKeepTime, because this is a lexem used for concatenation."
#endif
#define cDATEEP_OpenValueShortGndKeepTimePositionByte      16 
#define cDATEEP_OpenValueShortGndKeepTimePositionBit        0xFF
#define mSERPeeResetU16BitEEP_OpenValueShortGndKeepTime()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  16 ,  7 ,  16 , 200, Delayed)
#define mSERReadU16BitEEP_OpenValueShortGndKeepTimeDefaultValueDefault() ((U16)200)
#define mSERReadU16BitEEP_OpenValueShortGndKeepTimeDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal1,  16 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_OpenValueShortGndKeepTimeDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  16 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_OpenValueShortGndKeepTimeImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  16 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_OpenValueShortGndKeepTimeDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  16 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_OpenValueShortGndCur -- Group GroupSensorCal1, Byte  18  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_OpenValueShortGndCur
  #error "Do not define EEP_OpenValueShortGndCur, because this is a lexem used for concatenation."
#endif
#define cDATEEP_OpenValueShortGndCurPositionByte      18 
#define cDATEEP_OpenValueShortGndCurPositionBit        0xFF
#define mSERPeeResetU16BitEEP_OpenValueShortGndCur()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  18 ,  7 ,  16 , 1200, Delayed)
#define mSERReadU16BitEEP_OpenValueShortGndCurDefaultValueDefault() ((U16)1200)
#define mSERReadU16BitEEP_OpenValueShortGndCurDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal1,  18 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_OpenValueShortGndCurDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  18 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_OpenValueShortGndCurImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  18 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_OpenValueShortGndCurDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  18 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_OpenValueOpenPowDelayTime -- Group GroupSensorCal1, Byte  20  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_OpenValueOpenPowDelayTime
  #error "Do not define EEP_OpenValueOpenPowDelayTime, because this is a lexem used for concatenation."
#endif
#define cDATEEP_OpenValueOpenPowDelayTimePositionByte      20 
#define cDATEEP_OpenValueOpenPowDelayTimePositionBit        0xFF
#define mSERPeeResetU16BitEEP_OpenValueOpenPowDelayTime()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  20 ,  7 ,  16 , 300, Delayed)
#define mSERReadU16BitEEP_OpenValueOpenPowDelayTimeDefaultValueDefault() ((U16)300)
#define mSERReadU16BitEEP_OpenValueOpenPowDelayTimeDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal1,  20 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_OpenValueOpenPowDelayTimeDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  20 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_OpenValueOpenPowDelayTimeImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  20 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_OpenValueOpenPowDelayTimeDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  20 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_OpenValueOpenPowKeepTime -- Group GroupSensorCal1, Byte  22  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_OpenValueOpenPowKeepTime
  #error "Do not define EEP_OpenValueOpenPowKeepTime, because this is a lexem used for concatenation."
#endif
#define cDATEEP_OpenValueOpenPowKeepTimePositionByte      22 
#define cDATEEP_OpenValueOpenPowKeepTimePositionBit        0xFF
#define mSERPeeResetU16BitEEP_OpenValueOpenPowKeepTime()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  22 ,  7 ,  16 , 200, Delayed)
#define mSERReadU16BitEEP_OpenValueOpenPowKeepTimeDefaultValueDefault() ((U16)200)
#define mSERReadU16BitEEP_OpenValueOpenPowKeepTimeDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal1,  22 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_OpenValueOpenPowKeepTimeDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  22 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_OpenValueOpenPowKeepTimeImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  22 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_OpenValueOpenPowKeepTimeDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  22 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_OpenValueOpenCur -- Group GroupSensorCal1, Byte  24  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_OpenValueOpenCur
  #error "Do not define EEP_OpenValueOpenCur, because this is a lexem used for concatenation."
#endif
#define cDATEEP_OpenValueOpenCurPositionByte      24 
#define cDATEEP_OpenValueOpenCurPositionBit        0xFF
#define mSERPeeResetU16BitEEP_OpenValueOpenCur()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  24 ,  7 ,  16 , 100, Delayed)
#define mSERReadU16BitEEP_OpenValueOpenCurDefaultValueDefault() ((U16)100)
#define mSERReadU16BitEEP_OpenValueOpenCurDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal1,  24 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_OpenValueOpenCurDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  24 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_OpenValueOpenCurImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  24 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_OpenValueOpenCurDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  24 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_CloseValueShortPowDelayTime -- Group GroupSensorCal1, Byte  26  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_CloseValueShortPowDelayTime
  #error "Do not define EEP_CloseValueShortPowDelayTime, because this is a lexem used for concatenation."
#endif
#define cDATEEP_CloseValueShortPowDelayTimePositionByte      26 
#define cDATEEP_CloseValueShortPowDelayTimePositionBit        0xFF
#define mSERPeeResetU16BitEEP_CloseValueShortPowDelayTime()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  26 ,  7 ,  16 , 300, Delayed)
#define mSERReadU16BitEEP_CloseValueShortPowDelayTimeDefaultValueDefault() ((U16)300)
#define mSERReadU16BitEEP_CloseValueShortPowDelayTimeDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal1,  26 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_CloseValueShortPowDelayTimeDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  26 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_CloseValueShortPowDelayTimeImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  26 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_CloseValueShortPowDelayTimeDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  26 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_CloseValueShortPowKeepTime -- Group GroupSensorCal1, Byte  28  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_CloseValueShortPowKeepTime
  #error "Do not define EEP_CloseValueShortPowKeepTime, because this is a lexem used for concatenation."
#endif
#define cDATEEP_CloseValueShortPowKeepTimePositionByte      28 
#define cDATEEP_CloseValueShortPowKeepTimePositionBit        0xFF
#define mSERPeeResetU16BitEEP_CloseValueShortPowKeepTime()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  28 ,  7 ,  16 , 200, Delayed)
#define mSERReadU16BitEEP_CloseValueShortPowKeepTimeDefaultValueDefault() ((U16)200)
#define mSERReadU16BitEEP_CloseValueShortPowKeepTimeDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal1,  28 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_CloseValueShortPowKeepTimeDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  28 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_CloseValueShortPowKeepTimeImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  28 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_CloseValueShortPowKeepTimeDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  28 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_CloseValueShortPowVol -- Group GroupSensorCal1, Byte  30  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_CloseValueShortPowVol
  #error "Do not define EEP_CloseValueShortPowVol, because this is a lexem used for concatenation."
#endif
#define cDATEEP_CloseValueShortPowVolPositionByte      30 
#define cDATEEP_CloseValueShortPowVolPositionBit        0xFF
#define mSERPeeResetU16BitEEP_CloseValueShortPowVol()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  30 ,  7 ,  16 , 16500, Delayed)
#define mSERReadU16BitEEP_CloseValueShortPowVolDefaultValueDefault() ((U16)16500)
#define mSERReadU16BitEEP_CloseValueShortPowVolDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal1,  30 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_CloseValueShortPowVolDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  30 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_CloseValueShortPowVolImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  30 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_CloseValueShortPowVolDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  30 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_CloseValueShortGndDelayTime -- Group GroupSensorCal1, Byte  32  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_CloseValueShortGndDelayTime
  #error "Do not define EEP_CloseValueShortGndDelayTime, because this is a lexem used for concatenation."
#endif
#define cDATEEP_CloseValueShortGndDelayTimePositionByte      32 
#define cDATEEP_CloseValueShortGndDelayTimePositionBit        0xFF
#define mSERPeeResetU16BitEEP_CloseValueShortGndDelayTime()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  32 ,  7 ,  16 , 300, Delayed)
#define mSERReadU16BitEEP_CloseValueShortGndDelayTimeDefaultValueDefault() ((U16)300)
#define mSERReadU16BitEEP_CloseValueShortGndDelayTimeDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal1,  32 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_CloseValueShortGndDelayTimeDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  32 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_CloseValueShortGndDelayTimeImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  32 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_CloseValueShortGndDelayTimeDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  32 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_CloseValueShortGndKeepTime -- Group GroupSensorCal1, Byte  34  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_CloseValueShortGndKeepTime
  #error "Do not define EEP_CloseValueShortGndKeepTime, because this is a lexem used for concatenation."
#endif
#define cDATEEP_CloseValueShortGndKeepTimePositionByte      34 
#define cDATEEP_CloseValueShortGndKeepTimePositionBit        0xFF
#define mSERPeeResetU16BitEEP_CloseValueShortGndKeepTime()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  34 ,  7 ,  16 , 200, Delayed)
#define mSERReadU16BitEEP_CloseValueShortGndKeepTimeDefaultValueDefault() ((U16)200)
#define mSERReadU16BitEEP_CloseValueShortGndKeepTimeDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal1,  34 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_CloseValueShortGndKeepTimeDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  34 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_CloseValueShortGndKeepTimeImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  34 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_CloseValueShortGndKeepTimeDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  34 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_CloseValueOpenPowDelayTime -- Group GroupSensorCal1, Byte  36  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_CloseValueOpenPowDelayTime
  #error "Do not define EEP_CloseValueOpenPowDelayTime, because this is a lexem used for concatenation."
#endif
#define cDATEEP_CloseValueOpenPowDelayTimePositionByte      36 
#define cDATEEP_CloseValueOpenPowDelayTimePositionBit        0xFF
#define mSERPeeResetU16BitEEP_CloseValueOpenPowDelayTime()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  36 ,  7 ,  16 , 300, Delayed)
#define mSERReadU16BitEEP_CloseValueOpenPowDelayTimeDefaultValueDefault() ((U16)300)
#define mSERReadU16BitEEP_CloseValueOpenPowDelayTimeDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal1,  36 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_CloseValueOpenPowDelayTimeDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  36 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_CloseValueOpenPowDelayTimeImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  36 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_CloseValueOpenPowDelayTimeDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  36 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_CloseValueOpenPowKeepTime -- Group GroupSensorCal1, Byte  38  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_CloseValueOpenPowKeepTime
  #error "Do not define EEP_CloseValueOpenPowKeepTime, because this is a lexem used for concatenation."
#endif
#define cDATEEP_CloseValueOpenPowKeepTimePositionByte      38 
#define cDATEEP_CloseValueOpenPowKeepTimePositionBit        0xFF
#define mSERPeeResetU16BitEEP_CloseValueOpenPowKeepTime()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  38 ,  7 ,  16 , 200, Delayed)
#define mSERReadU16BitEEP_CloseValueOpenPowKeepTimeDefaultValueDefault() ((U16)200)
#define mSERReadU16BitEEP_CloseValueOpenPowKeepTimeDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal1,  38 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_CloseValueOpenPowKeepTimeDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  38 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_CloseValueOpenPowKeepTimeImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  38 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_CloseValueOpenPowKeepTimeDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  38 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_CloseValueOpenCur -- Group GroupSensorCal1, Byte  40  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_CloseValueOpenCur
  #error "Do not define EEP_CloseValueOpenCur, because this is a lexem used for concatenation."
#endif
#define cDATEEP_CloseValueOpenCurPositionByte      40 
#define cDATEEP_CloseValueOpenCurPositionBit        0xFF
#define mSERPeeResetU16BitEEP_CloseValueOpenCur()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  40 ,  7 ,  16 , 100, Delayed)
#define mSERReadU16BitEEP_CloseValueOpenCurDefaultValueDefault() ((U16)100)
#define mSERReadU16BitEEP_CloseValueOpenCurDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal1,  40 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_CloseValueOpenCurDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  40 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_CloseValueOpenCurImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  40 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_CloseValueOpenCurDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  40 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_CloseValueShortGndCur -- Group GroupSensorCal1, Byte  42  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_CloseValueShortGndCur
  #error "Do not define EEP_CloseValueShortGndCur, because this is a lexem used for concatenation."
#endif
#define cDATEEP_CloseValueShortGndCurPositionByte      42 
#define cDATEEP_CloseValueShortGndCurPositionBit        0xFF
#define mSERPeeResetU16BitEEP_CloseValueShortGndCur()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  42 ,  7 ,  16 , 1200, Delayed)
#define mSERReadU16BitEEP_CloseValueShortGndCurDefaultValueDefault() ((U16)1200)
#define mSERReadU16BitEEP_CloseValueShortGndCurDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal1,  42 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_CloseValueShortGndCurDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  42 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_CloseValueShortGndCurImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  42 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_CloseValueShortGndCurDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  42 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_MiddleValueShortPowDelayTime -- Group GroupSensorCal1, Byte  44  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_MiddleValueShortPowDelayTime
  #error "Do not define EEP_MiddleValueShortPowDelayTime, because this is a lexem used for concatenation."
#endif
#define cDATEEP_MiddleValueShortPowDelayTimePositionByte      44 
#define cDATEEP_MiddleValueShortPowDelayTimePositionBit        0xFF
#define mSERPeeResetU16BitEEP_MiddleValueShortPowDelayTime()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  44 ,  7 ,  16 , 300, Delayed)
#define mSERReadU16BitEEP_MiddleValueShortPowDelayTimeDefaultValueDefault() ((U16)300)
#define mSERReadU16BitEEP_MiddleValueShortPowDelayTimeDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal1,  44 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_MiddleValueShortPowDelayTimeDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  44 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_MiddleValueShortPowDelayTimeImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  44 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_MiddleValueShortPowDelayTimeDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  44 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_MiddleValueShortPowKeepTime -- Group GroupSensorCal1, Byte  46  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_MiddleValueShortPowKeepTime
  #error "Do not define EEP_MiddleValueShortPowKeepTime, because this is a lexem used for concatenation."
#endif
#define cDATEEP_MiddleValueShortPowKeepTimePositionByte      46 
#define cDATEEP_MiddleValueShortPowKeepTimePositionBit        0xFF
#define mSERPeeResetU16BitEEP_MiddleValueShortPowKeepTime()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  46 ,  7 ,  16 , 200, Delayed)
#define mSERReadU16BitEEP_MiddleValueShortPowKeepTimeDefaultValueDefault() ((U16)200)
#define mSERReadU16BitEEP_MiddleValueShortPowKeepTimeDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal1,  46 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_MiddleValueShortPowKeepTimeDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  46 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_MiddleValueShortPowKeepTimeImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  46 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_MiddleValueShortPowKeepTimeDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  46 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_MiddleValueShortPowVol -- Group GroupSensorCal1, Byte  48  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_MiddleValueShortPowVol
  #error "Do not define EEP_MiddleValueShortPowVol, because this is a lexem used for concatenation."
#endif
#define cDATEEP_MiddleValueShortPowVolPositionByte      48 
#define cDATEEP_MiddleValueShortPowVolPositionBit        0xFF
#define mSERPeeResetU16BitEEP_MiddleValueShortPowVol()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  48 ,  7 ,  16 , 16500, Delayed)
#define mSERReadU16BitEEP_MiddleValueShortPowVolDefaultValueDefault() ((U16)16500)
#define mSERReadU16BitEEP_MiddleValueShortPowVolDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal1,  48 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_MiddleValueShortPowVolDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  48 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_MiddleValueShortPowVolImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  48 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_MiddleValueShortPowVolDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  48 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_MiddleValueShortGndDelayTime -- Group GroupSensorCal1, Byte  50  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_MiddleValueShortGndDelayTime
  #error "Do not define EEP_MiddleValueShortGndDelayTime, because this is a lexem used for concatenation."
#endif
#define cDATEEP_MiddleValueShortGndDelayTimePositionByte      50 
#define cDATEEP_MiddleValueShortGndDelayTimePositionBit        0xFF
#define mSERPeeResetU16BitEEP_MiddleValueShortGndDelayTime()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  50 ,  7 ,  16 , 300, Delayed)
#define mSERReadU16BitEEP_MiddleValueShortGndDelayTimeDefaultValueDefault() ((U16)300)
#define mSERReadU16BitEEP_MiddleValueShortGndDelayTimeDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal1,  50 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_MiddleValueShortGndDelayTimeDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  50 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_MiddleValueShortGndDelayTimeImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  50 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_MiddleValueShortGndDelayTimeDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  50 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_MiddleValueShortGndKeepTime -- Group GroupSensorCal1, Byte  52  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_MiddleValueShortGndKeepTime
  #error "Do not define EEP_MiddleValueShortGndKeepTime, because this is a lexem used for concatenation."
#endif
#define cDATEEP_MiddleValueShortGndKeepTimePositionByte      52 
#define cDATEEP_MiddleValueShortGndKeepTimePositionBit        0xFF
#define mSERPeeResetU16BitEEP_MiddleValueShortGndKeepTime()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  52 ,  7 ,  16 , 200, Delayed)
#define mSERReadU16BitEEP_MiddleValueShortGndKeepTimeDefaultValueDefault() ((U16)200)
#define mSERReadU16BitEEP_MiddleValueShortGndKeepTimeDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal1,  52 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_MiddleValueShortGndKeepTimeDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  52 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_MiddleValueShortGndKeepTimeImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  52 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_MiddleValueShortGndKeepTimeDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  52 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_MiddleValueShortGndCur -- Group GroupSensorCal1, Byte  54  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_MiddleValueShortGndCur
  #error "Do not define EEP_MiddleValueShortGndCur, because this is a lexem used for concatenation."
#endif
#define cDATEEP_MiddleValueShortGndCurPositionByte      54 
#define cDATEEP_MiddleValueShortGndCurPositionBit        0xFF
#define mSERPeeResetU16BitEEP_MiddleValueShortGndCur()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  54 ,  7 ,  16 , 1200, Delayed)
#define mSERReadU16BitEEP_MiddleValueShortGndCurDefaultValueDefault() ((U16)1200)
#define mSERReadU16BitEEP_MiddleValueShortGndCurDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal1,  54 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_MiddleValueShortGndCurDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  54 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_MiddleValueShortGndCurImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  54 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_MiddleValueShortGndCurDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  54 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_MiddleValueOpenPowDelayTime -- Group GroupSensorCal1, Byte  56  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_MiddleValueOpenPowDelayTime
  #error "Do not define EEP_MiddleValueOpenPowDelayTime, because this is a lexem used for concatenation."
#endif
#define cDATEEP_MiddleValueOpenPowDelayTimePositionByte      56 
#define cDATEEP_MiddleValueOpenPowDelayTimePositionBit        0xFF
#define mSERPeeResetU16BitEEP_MiddleValueOpenPowDelayTime()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  56 ,  7 ,  16 , 300, Delayed)
#define mSERReadU16BitEEP_MiddleValueOpenPowDelayTimeDefaultValueDefault() ((U16)300)
#define mSERReadU16BitEEP_MiddleValueOpenPowDelayTimeDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal1,  56 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_MiddleValueOpenPowDelayTimeDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  56 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_MiddleValueOpenPowDelayTimeImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  56 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_MiddleValueOpenPowDelayTimeDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  56 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_MiddleValueOpenPowKeepTime -- Group GroupSensorCal1, Byte  58  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_MiddleValueOpenPowKeepTime
  #error "Do not define EEP_MiddleValueOpenPowKeepTime, because this is a lexem used for concatenation."
#endif
#define cDATEEP_MiddleValueOpenPowKeepTimePositionByte      58 
#define cDATEEP_MiddleValueOpenPowKeepTimePositionBit        0xFF
#define mSERPeeResetU16BitEEP_MiddleValueOpenPowKeepTime()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  58 ,  7 ,  16 , 200, Delayed)
#define mSERReadU16BitEEP_MiddleValueOpenPowKeepTimeDefaultValueDefault() ((U16)200)
#define mSERReadU16BitEEP_MiddleValueOpenPowKeepTimeDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal1,  58 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_MiddleValueOpenPowKeepTimeDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  58 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_MiddleValueOpenPowKeepTimeImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  58 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_MiddleValueOpenPowKeepTimeDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  58 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_MiddleValueOpenCur -- Group GroupSensorCal1, Byte  60  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_MiddleValueOpenCur
  #error "Do not define EEP_MiddleValueOpenCur, because this is a lexem used for concatenation."
#endif
#define cDATEEP_MiddleValueOpenCurPositionByte      60 
#define cDATEEP_MiddleValueOpenCurPositionBit        0xFF
#define mSERPeeResetU16BitEEP_MiddleValueOpenCur()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  60 ,  7 ,  16 , 100, Delayed)
#define mSERReadU16BitEEP_MiddleValueOpenCurDefaultValueDefault() ((U16)100)
#define mSERReadU16BitEEP_MiddleValueOpenCurDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal1,  60 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_MiddleValueOpenCurDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  60 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_MiddleValueOpenCurImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  60 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_MiddleValueOpenCurDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  60 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_RestrainValueShortPowDelayTime -- Group GroupSensorCal1, Byte  62  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_RestrainValueShortPowDelayTime
  #error "Do not define EEP_RestrainValueShortPowDelayTime, because this is a lexem used for concatenation."
#endif
#define cDATEEP_RestrainValueShortPowDelayTimePositionByte      62 
#define cDATEEP_RestrainValueShortPowDelayTimePositionBit        0xFF
#define mSERPeeResetU16BitEEP_RestrainValueShortPowDelayTime()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  62 ,  7 ,  16 , 300, Delayed)
#define mSERReadU16BitEEP_RestrainValueShortPowDelayTimeDefaultValueDefault() ((U16)300)
#define mSERReadU16BitEEP_RestrainValueShortPowDelayTimeDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal1,  62 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_RestrainValueShortPowDelayTimeDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  62 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_RestrainValueShortPowDelayTimeImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  62 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_RestrainValueShortPowDelayTimeDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  62 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_RestrainValueShortPowKeepTime -- Group GroupSensorCal1, Byte  64  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_RestrainValueShortPowKeepTime
  #error "Do not define EEP_RestrainValueShortPowKeepTime, because this is a lexem used for concatenation."
#endif
#define cDATEEP_RestrainValueShortPowKeepTimePositionByte      64 
#define cDATEEP_RestrainValueShortPowKeepTimePositionBit        0xFF
#define mSERPeeResetU16BitEEP_RestrainValueShortPowKeepTime()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  64 ,  7 ,  16 , 200, Delayed)
#define mSERReadU16BitEEP_RestrainValueShortPowKeepTimeDefaultValueDefault() ((U16)200)
#define mSERReadU16BitEEP_RestrainValueShortPowKeepTimeDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal1,  64 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_RestrainValueShortPowKeepTimeDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  64 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_RestrainValueShortPowKeepTimeImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  64 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_RestrainValueShortPowKeepTimeDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  64 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_RestrainValueShortPowVol -- Group GroupSensorCal1, Byte  66  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_RestrainValueShortPowVol
  #error "Do not define EEP_RestrainValueShortPowVol, because this is a lexem used for concatenation."
#endif
#define cDATEEP_RestrainValueShortPowVolPositionByte      66 
#define cDATEEP_RestrainValueShortPowVolPositionBit        0xFF
#define mSERPeeResetU16BitEEP_RestrainValueShortPowVol()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  66 ,  7 ,  16 , 16500, Delayed)
#define mSERReadU16BitEEP_RestrainValueShortPowVolDefaultValueDefault() ((U16)16500)
#define mSERReadU16BitEEP_RestrainValueShortPowVolDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal1,  66 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_RestrainValueShortPowVolDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  66 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_RestrainValueShortPowVolImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  66 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_RestrainValueShortPowVolDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  66 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_RestrainValueShortGndDelayTime -- Group GroupSensorCal1, Byte  68  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_RestrainValueShortGndDelayTime
  #error "Do not define EEP_RestrainValueShortGndDelayTime, because this is a lexem used for concatenation."
#endif
#define cDATEEP_RestrainValueShortGndDelayTimePositionByte      68 
#define cDATEEP_RestrainValueShortGndDelayTimePositionBit        0xFF
#define mSERPeeResetU16BitEEP_RestrainValueShortGndDelayTime()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  68 ,  7 ,  16 , 300, Delayed)
#define mSERReadU16BitEEP_RestrainValueShortGndDelayTimeDefaultValueDefault() ((U16)300)
#define mSERReadU16BitEEP_RestrainValueShortGndDelayTimeDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal1,  68 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_RestrainValueShortGndDelayTimeDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  68 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_RestrainValueShortGndDelayTimeImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  68 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_RestrainValueShortGndDelayTimeDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  68 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_RestrainValueShortGndKeepTime -- Group GroupSensorCal1, Byte  70  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_RestrainValueShortGndKeepTime
  #error "Do not define EEP_RestrainValueShortGndKeepTime, because this is a lexem used for concatenation."
#endif
#define cDATEEP_RestrainValueShortGndKeepTimePositionByte      70 
#define cDATEEP_RestrainValueShortGndKeepTimePositionBit        0xFF
#define mSERPeeResetU16BitEEP_RestrainValueShortGndKeepTime()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  70 ,  7 ,  16 , 200, Delayed)
#define mSERReadU16BitEEP_RestrainValueShortGndKeepTimeDefaultValueDefault() ((U16)200)
#define mSERReadU16BitEEP_RestrainValueShortGndKeepTimeDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal1,  70 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_RestrainValueShortGndKeepTimeDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  70 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_RestrainValueShortGndKeepTimeImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  70 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_RestrainValueShortGndKeepTimeDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  70 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_RestrainValueShortGndCur -- Group GroupSensorCal1, Byte  72  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_RestrainValueShortGndCur
  #error "Do not define EEP_RestrainValueShortGndCur, because this is a lexem used for concatenation."
#endif
#define cDATEEP_RestrainValueShortGndCurPositionByte      72 
#define cDATEEP_RestrainValueShortGndCurPositionBit        0xFF
#define mSERPeeResetU16BitEEP_RestrainValueShortGndCur()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  72 ,  7 ,  16 , 1200, Delayed)
#define mSERReadU16BitEEP_RestrainValueShortGndCurDefaultValueDefault() ((U16)1200)
#define mSERReadU16BitEEP_RestrainValueShortGndCurDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal1,  72 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_RestrainValueShortGndCurDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  72 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_RestrainValueShortGndCurImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  72 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_RestrainValueShortGndCurDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  72 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_RestrainValueOpenPowDelayTime -- Group GroupSensorCal1, Byte  74  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_RestrainValueOpenPowDelayTime
  #error "Do not define EEP_RestrainValueOpenPowDelayTime, because this is a lexem used for concatenation."
#endif
#define cDATEEP_RestrainValueOpenPowDelayTimePositionByte      74 
#define cDATEEP_RestrainValueOpenPowDelayTimePositionBit        0xFF
#define mSERPeeResetU16BitEEP_RestrainValueOpenPowDelayTime()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  74 ,  7 ,  16 , 300, Delayed)
#define mSERReadU16BitEEP_RestrainValueOpenPowDelayTimeDefaultValueDefault() ((U16)300)
#define mSERReadU16BitEEP_RestrainValueOpenPowDelayTimeDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal1,  74 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_RestrainValueOpenPowDelayTimeDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  74 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_RestrainValueOpenPowDelayTimeImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  74 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_RestrainValueOpenPowDelayTimeDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  74 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_RestrainValueOpenPowKeepTime -- Group GroupSensorCal1, Byte  76  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_RestrainValueOpenPowKeepTime
  #error "Do not define EEP_RestrainValueOpenPowKeepTime, because this is a lexem used for concatenation."
#endif
#define cDATEEP_RestrainValueOpenPowKeepTimePositionByte      76 
#define cDATEEP_RestrainValueOpenPowKeepTimePositionBit        0xFF
#define mSERPeeResetU16BitEEP_RestrainValueOpenPowKeepTime()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  76 ,  7 ,  16 , 200, Delayed)
#define mSERReadU16BitEEP_RestrainValueOpenPowKeepTimeDefaultValueDefault() ((U16)200)
#define mSERReadU16BitEEP_RestrainValueOpenPowKeepTimeDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal1,  76 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_RestrainValueOpenPowKeepTimeDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  76 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_RestrainValueOpenPowKeepTimeImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  76 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_RestrainValueOpenPowKeepTimeDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  76 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_RestrainValueOpenCur -- Group GroupSensorCal1, Byte  78  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_RestrainValueOpenCur
  #error "Do not define EEP_RestrainValueOpenCur, because this is a lexem used for concatenation."
#endif
#define cDATEEP_RestrainValueOpenCurPositionByte      78 
#define cDATEEP_RestrainValueOpenCurPositionBit        0xFF
#define mSERPeeResetU16BitEEP_RestrainValueOpenCur()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  78 ,  7 ,  16 , 100, Delayed)
#define mSERReadU16BitEEP_RestrainValueOpenCurDefaultValueDefault() ((U16)100)
#define mSERReadU16BitEEP_RestrainValueOpenCurDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal1,  78 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_RestrainValueOpenCurDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  78 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_RestrainValueOpenCurImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  78 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_RestrainValueOpenCurDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  78 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_DoorLightShortPowDelayTime -- Group GroupSensorCal1, Byte  80  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_DoorLightShortPowDelayTime
  #error "Do not define EEP_DoorLightShortPowDelayTime, because this is a lexem used for concatenation."
#endif
#define cDATEEP_DoorLightShortPowDelayTimePositionByte      80 
#define cDATEEP_DoorLightShortPowDelayTimePositionBit        0xFF
#define mSERPeeResetU16BitEEP_DoorLightShortPowDelayTime()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  80 ,  7 ,  16 , 300, Delayed)
#define mSERReadU16BitEEP_DoorLightShortPowDelayTimeDefaultValueDefault() ((U16)300)
#define mSERReadU16BitEEP_DoorLightShortPowDelayTimeDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal1,  80 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_DoorLightShortPowDelayTimeDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  80 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_DoorLightShortPowDelayTimeImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  80 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_DoorLightShortPowDelayTimeDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  80 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_DoorLightShortPowKeepTime -- Group GroupSensorCal1, Byte  82  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_DoorLightShortPowKeepTime
  #error "Do not define EEP_DoorLightShortPowKeepTime, because this is a lexem used for concatenation."
#endif
#define cDATEEP_DoorLightShortPowKeepTimePositionByte      82 
#define cDATEEP_DoorLightShortPowKeepTimePositionBit        0xFF
#define mSERPeeResetU16BitEEP_DoorLightShortPowKeepTime()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  82 ,  7 ,  16 , 200, Delayed)
#define mSERReadU16BitEEP_DoorLightShortPowKeepTimeDefaultValueDefault() ((U16)200)
#define mSERReadU16BitEEP_DoorLightShortPowKeepTimeDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal1,  82 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_DoorLightShortPowKeepTimeDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  82 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_DoorLightShortPowKeepTimeImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  82 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_DoorLightShortPowKeepTimeDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  82 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_DoorLightShortPowVol -- Group GroupSensorCal1, Byte  84  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_DoorLightShortPowVol
  #error "Do not define EEP_DoorLightShortPowVol, because this is a lexem used for concatenation."
#endif
#define cDATEEP_DoorLightShortPowVolPositionByte      84 
#define cDATEEP_DoorLightShortPowVolPositionBit        0xFF
#define mSERPeeResetU16BitEEP_DoorLightShortPowVol()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  84 ,  7 ,  16 , 16500, Delayed)
#define mSERReadU16BitEEP_DoorLightShortPowVolDefaultValueDefault() ((U16)16500)
#define mSERReadU16BitEEP_DoorLightShortPowVolDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal1,  84 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_DoorLightShortPowVolDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  84 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_DoorLightShortPowVolImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  84 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_DoorLightShortPowVolDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  84 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_DoorLightShortGndDelayTime -- Group GroupSensorCal1, Byte  86  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_DoorLightShortGndDelayTime
  #error "Do not define EEP_DoorLightShortGndDelayTime, because this is a lexem used for concatenation."
#endif
#define cDATEEP_DoorLightShortGndDelayTimePositionByte      86 
#define cDATEEP_DoorLightShortGndDelayTimePositionBit        0xFF
#define mSERPeeResetU16BitEEP_DoorLightShortGndDelayTime()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  86 ,  7 ,  16 , 300, Delayed)
#define mSERReadU16BitEEP_DoorLightShortGndDelayTimeDefaultValueDefault() ((U16)300)
#define mSERReadU16BitEEP_DoorLightShortGndDelayTimeDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal1,  86 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_DoorLightShortGndDelayTimeDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  86 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_DoorLightShortGndDelayTimeImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  86 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_DoorLightShortGndDelayTimeDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  86 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_DoorLightShortGndKeepTime -- Group GroupSensorCal1, Byte  88  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_DoorLightShortGndKeepTime
  #error "Do not define EEP_DoorLightShortGndKeepTime, because this is a lexem used for concatenation."
#endif
#define cDATEEP_DoorLightShortGndKeepTimePositionByte      88 
#define cDATEEP_DoorLightShortGndKeepTimePositionBit        0xFF
#define mSERPeeResetU16BitEEP_DoorLightShortGndKeepTime()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  88 ,  7 ,  16 , 200, Delayed)
#define mSERReadU16BitEEP_DoorLightShortGndKeepTimeDefaultValueDefault() ((U16)200)
#define mSERReadU16BitEEP_DoorLightShortGndKeepTimeDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal1,  88 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_DoorLightShortGndKeepTimeDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  88 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_DoorLightShortGndKeepTimeImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  88 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_DoorLightShortGndKeepTimeDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  88 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_DoorLightShortGndCur -- Group GroupSensorCal1, Byte  90  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_DoorLightShortGndCur
  #error "Do not define EEP_DoorLightShortGndCur, because this is a lexem used for concatenation."
#endif
#define cDATEEP_DoorLightShortGndCurPositionByte      90 
#define cDATEEP_DoorLightShortGndCurPositionBit        0xFF
#define mSERPeeResetU16BitEEP_DoorLightShortGndCur()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  90 ,  7 ,  16 , 1200, Delayed)
#define mSERReadU16BitEEP_DoorLightShortGndCurDefaultValueDefault() ((U16)1200)
#define mSERReadU16BitEEP_DoorLightShortGndCurDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal1,  90 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_DoorLightShortGndCurDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  90 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_DoorLightShortGndCurImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  90 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_DoorLightShortGndCurDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  90 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_DoorLightOpenPowDelayTime -- Group GroupSensorCal1, Byte  92  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_DoorLightOpenPowDelayTime
  #error "Do not define EEP_DoorLightOpenPowDelayTime, because this is a lexem used for concatenation."
#endif
#define cDATEEP_DoorLightOpenPowDelayTimePositionByte      92 
#define cDATEEP_DoorLightOpenPowDelayTimePositionBit        0xFF
#define mSERPeeResetU16BitEEP_DoorLightOpenPowDelayTime()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  92 ,  7 ,  16 , 300, Delayed)
#define mSERReadU16BitEEP_DoorLightOpenPowDelayTimeDefaultValueDefault() ((U16)300)
#define mSERReadU16BitEEP_DoorLightOpenPowDelayTimeDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal1,  92 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_DoorLightOpenPowDelayTimeDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  92 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_DoorLightOpenPowDelayTimeImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  92 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_DoorLightOpenPowDelayTimeDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  92 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_DoorLightOpenPowKeepTime -- Group GroupSensorCal1, Byte  94  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_DoorLightOpenPowKeepTime
  #error "Do not define EEP_DoorLightOpenPowKeepTime, because this is a lexem used for concatenation."
#endif
#define cDATEEP_DoorLightOpenPowKeepTimePositionByte      94 
#define cDATEEP_DoorLightOpenPowKeepTimePositionBit        0xFF
#define mSERPeeResetU16BitEEP_DoorLightOpenPowKeepTime()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  94 ,  7 ,  16 , 200, Delayed)
#define mSERReadU16BitEEP_DoorLightOpenPowKeepTimeDefaultValueDefault() ((U16)200)
#define mSERReadU16BitEEP_DoorLightOpenPowKeepTimeDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal1,  94 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_DoorLightOpenPowKeepTimeDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  94 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_DoorLightOpenPowKeepTimeImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  94 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_DoorLightOpenPowKeepTimeDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  94 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_DoorLightOpenCur -- Group GroupSensorCal1, Byte  96  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_DoorLightOpenCur
  #error "Do not define EEP_DoorLightOpenCur, because this is a lexem used for concatenation."
#endif
#define cDATEEP_DoorLightOpenCurPositionByte      96 
#define cDATEEP_DoorLightOpenCurPositionBit        0xFF
#define mSERPeeResetU16BitEEP_DoorLightOpenCur()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  96 ,  7 ,  16 , 100, Delayed)
#define mSERReadU16BitEEP_DoorLightOpenCurDefaultValueDefault() ((U16)100)
#define mSERReadU16BitEEP_DoorLightOpenCurDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal1,  96 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_DoorLightOpenCurDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  96 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_DoorLightOpenCurImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  96 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_DoorLightOpenCurDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  96 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_Sleep24VShortPowDelayTime -- Group GroupSensorCal1, Byte  98  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_Sleep24VShortPowDelayTime
  #error "Do not define EEP_Sleep24VShortPowDelayTime, because this is a lexem used for concatenation."
#endif
#define cDATEEP_Sleep24VShortPowDelayTimePositionByte      98 
#define cDATEEP_Sleep24VShortPowDelayTimePositionBit        0xFF
#define mSERPeeResetU16BitEEP_Sleep24VShortPowDelayTime()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  98 ,  7 ,  16 , 300, Delayed)
#define mSERReadU16BitEEP_Sleep24VShortPowDelayTimeDefaultValueDefault() ((U16)300)
#define mSERReadU16BitEEP_Sleep24VShortPowDelayTimeDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal1,  98 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_Sleep24VShortPowDelayTimeDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  98 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_Sleep24VShortPowDelayTimeImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  98 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_Sleep24VShortPowDelayTimeDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  98 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_Sleep24VShortPowKeepTime -- Group GroupSensorCal1, Byte  100  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_Sleep24VShortPowKeepTime
  #error "Do not define EEP_Sleep24VShortPowKeepTime, because this is a lexem used for concatenation."
#endif
#define cDATEEP_Sleep24VShortPowKeepTimePositionByte      100 
#define cDATEEP_Sleep24VShortPowKeepTimePositionBit        0xFF
#define mSERPeeResetU16BitEEP_Sleep24VShortPowKeepTime()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  100 ,  7 ,  16 , 200, Delayed)
#define mSERReadU16BitEEP_Sleep24VShortPowKeepTimeDefaultValueDefault() ((U16)200)
#define mSERReadU16BitEEP_Sleep24VShortPowKeepTimeDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal1,  100 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_Sleep24VShortPowKeepTimeDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  100 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_Sleep24VShortPowKeepTimeImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  100 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_Sleep24VShortPowKeepTimeDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  100 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_Sleep24VShortPowVol -- Group GroupSensorCal1, Byte  102  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_Sleep24VShortPowVol
  #error "Do not define EEP_Sleep24VShortPowVol, because this is a lexem used for concatenation."
#endif
#define cDATEEP_Sleep24VShortPowVolPositionByte      102 
#define cDATEEP_Sleep24VShortPowVolPositionBit        0xFF
#define mSERPeeResetU16BitEEP_Sleep24VShortPowVol()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  102 ,  7 ,  16 , 16500, Delayed)
#define mSERReadU16BitEEP_Sleep24VShortPowVolDefaultValueDefault() ((U16)16500)
#define mSERReadU16BitEEP_Sleep24VShortPowVolDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal1,  102 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_Sleep24VShortPowVolDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  102 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_Sleep24VShortPowVolImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  102 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_Sleep24VShortPowVolDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  102 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_Sleep24VShortGndDelayTime -- Group GroupSensorCal1, Byte  104  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_Sleep24VShortGndDelayTime
  #error "Do not define EEP_Sleep24VShortGndDelayTime, because this is a lexem used for concatenation."
#endif
#define cDATEEP_Sleep24VShortGndDelayTimePositionByte      104 
#define cDATEEP_Sleep24VShortGndDelayTimePositionBit        0xFF
#define mSERPeeResetU16BitEEP_Sleep24VShortGndDelayTime()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  104 ,  7 ,  16 , 300, Delayed)
#define mSERReadU16BitEEP_Sleep24VShortGndDelayTimeDefaultValueDefault() ((U16)300)
#define mSERReadU16BitEEP_Sleep24VShortGndDelayTimeDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal1,  104 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_Sleep24VShortGndDelayTimeDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  104 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_Sleep24VShortGndDelayTimeImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  104 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_Sleep24VShortGndDelayTimeDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  104 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_Sleep24VShortGndKeepTime -- Group GroupSensorCal1, Byte  106  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_Sleep24VShortGndKeepTime
  #error "Do not define EEP_Sleep24VShortGndKeepTime, because this is a lexem used for concatenation."
#endif
#define cDATEEP_Sleep24VShortGndKeepTimePositionByte      106 
#define cDATEEP_Sleep24VShortGndKeepTimePositionBit        0xFF
#define mSERPeeResetU16BitEEP_Sleep24VShortGndKeepTime()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  106 ,  7 ,  16 , 200, Delayed)
#define mSERReadU16BitEEP_Sleep24VShortGndKeepTimeDefaultValueDefault() ((U16)200)
#define mSERReadU16BitEEP_Sleep24VShortGndKeepTimeDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal1,  106 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_Sleep24VShortGndKeepTimeDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  106 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_Sleep24VShortGndKeepTimeImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  106 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_Sleep24VShortGndKeepTimeDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  106 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_Sleep24VShortGndCur -- Group GroupSensorCal1, Byte  108  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_Sleep24VShortGndCur
  #error "Do not define EEP_Sleep24VShortGndCur, because this is a lexem used for concatenation."
#endif
#define cDATEEP_Sleep24VShortGndCurPositionByte      108 
#define cDATEEP_Sleep24VShortGndCurPositionBit        0xFF
#define mSERPeeResetU16BitEEP_Sleep24VShortGndCur()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  108 ,  7 ,  16 , 1200, Delayed)
#define mSERReadU16BitEEP_Sleep24VShortGndCurDefaultValueDefault() ((U16)1200)
#define mSERReadU16BitEEP_Sleep24VShortGndCurDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal1,  108 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_Sleep24VShortGndCurDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  108 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_Sleep24VShortGndCurImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  108 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_Sleep24VShortGndCurDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  108 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_Sleep24VOpenPowDelayTime -- Group GroupSensorCal1, Byte  110  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_Sleep24VOpenPowDelayTime
  #error "Do not define EEP_Sleep24VOpenPowDelayTime, because this is a lexem used for concatenation."
#endif
#define cDATEEP_Sleep24VOpenPowDelayTimePositionByte      110 
#define cDATEEP_Sleep24VOpenPowDelayTimePositionBit        0xFF
#define mSERPeeResetU16BitEEP_Sleep24VOpenPowDelayTime()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  110 ,  7 ,  16 , 300, Delayed)
#define mSERReadU16BitEEP_Sleep24VOpenPowDelayTimeDefaultValueDefault() ((U16)300)
#define mSERReadU16BitEEP_Sleep24VOpenPowDelayTimeDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal1,  110 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_Sleep24VOpenPowDelayTimeDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  110 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_Sleep24VOpenPowDelayTimeImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  110 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_Sleep24VOpenPowDelayTimeDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  110 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_Sleep24VOpenPowKeepTime -- Group GroupSensorCal1, Byte  112  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_Sleep24VOpenPowKeepTime
  #error "Do not define EEP_Sleep24VOpenPowKeepTime, because this is a lexem used for concatenation."
#endif
#define cDATEEP_Sleep24VOpenPowKeepTimePositionByte      112 
#define cDATEEP_Sleep24VOpenPowKeepTimePositionBit        0xFF
#define mSERPeeResetU16BitEEP_Sleep24VOpenPowKeepTime()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  112 ,  7 ,  16 , 200, Delayed)
#define mSERReadU16BitEEP_Sleep24VOpenPowKeepTimeDefaultValueDefault() ((U16)200)
#define mSERReadU16BitEEP_Sleep24VOpenPowKeepTimeDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal1,  112 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_Sleep24VOpenPowKeepTimeDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  112 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_Sleep24VOpenPowKeepTimeImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  112 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_Sleep24VOpenPowKeepTimeDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  112 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_Sleep24VOpenCur -- Group GroupSensorCal1, Byte  114  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_Sleep24VOpenCur
  #error "Do not define EEP_Sleep24VOpenCur, because this is a lexem used for concatenation."
#endif
#define cDATEEP_Sleep24VOpenCurPositionByte      114 
#define cDATEEP_Sleep24VOpenCurPositionBit        0xFF
#define mSERPeeResetU16BitEEP_Sleep24VOpenCur()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  114 ,  7 ,  16 , 100, Delayed)
#define mSERReadU16BitEEP_Sleep24VOpenCurDefaultValueDefault() ((U16)100)
#define mSERReadU16BitEEP_Sleep24VOpenCurDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal1,  114 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_Sleep24VOpenCurDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  114 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_Sleep24VOpenCurImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  114 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_Sleep24VOpenCurDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  114 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_LowPressuraShortPowDelayTime -- Group GroupSensorCal1, Byte  116  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_LowPressuraShortPowDelayTime
  #error "Do not define EEP_LowPressuraShortPowDelayTime, because this is a lexem used for concatenation."
#endif
#define cDATEEP_LowPressuraShortPowDelayTimePositionByte      116 
#define cDATEEP_LowPressuraShortPowDelayTimePositionBit        0xFF
#define mSERPeeResetU16BitEEP_LowPressuraShortPowDelayTime()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  116 ,  7 ,  16 , 300, Delayed)
#define mSERReadU16BitEEP_LowPressuraShortPowDelayTimeDefaultValueDefault() ((U16)300)
#define mSERReadU16BitEEP_LowPressuraShortPowDelayTimeDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal1,  116 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_LowPressuraShortPowDelayTimeDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  116 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_LowPressuraShortPowDelayTimeImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  116 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_LowPressuraShortPowDelayTimeDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  116 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_LowPressuraShortPowKeepTime -- Group GroupSensorCal1, Byte  118  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_LowPressuraShortPowKeepTime
  #error "Do not define EEP_LowPressuraShortPowKeepTime, because this is a lexem used for concatenation."
#endif
#define cDATEEP_LowPressuraShortPowKeepTimePositionByte      118 
#define cDATEEP_LowPressuraShortPowKeepTimePositionBit        0xFF
#define mSERPeeResetU16BitEEP_LowPressuraShortPowKeepTime()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  118 ,  7 ,  16 , 200, Delayed)
#define mSERReadU16BitEEP_LowPressuraShortPowKeepTimeDefaultValueDefault() ((U16)200)
#define mSERReadU16BitEEP_LowPressuraShortPowKeepTimeDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal1,  118 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_LowPressuraShortPowKeepTimeDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  118 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_LowPressuraShortPowKeepTimeImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  118 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_LowPressuraShortPowKeepTimeDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal1,  118 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_LowPressuraShortPowVol -- Group GroupSensorCal2, Byte  0  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_LowPressuraShortPowVol
  #error "Do not define EEP_LowPressuraShortPowVol, because this is a lexem used for concatenation."
#endif
#define cDATEEP_LowPressuraShortPowVolPositionByte      0 
#define cDATEEP_LowPressuraShortPowVolPositionBit        0xFF
#define mSERPeeResetU16BitEEP_LowPressuraShortPowVol()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  0 ,  7 ,  16 , 16500, Delayed)
#define mSERReadU16BitEEP_LowPressuraShortPowVolDefaultValueDefault() ((U16)16500)
#define mSERReadU16BitEEP_LowPressuraShortPowVolDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal2,  0 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_LowPressuraShortPowVolDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  0 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_LowPressuraShortPowVolImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  0 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_LowPressuraShortPowVolDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  0 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_LowPressuraShortGndDelayTime -- Group GroupSensorCal2, Byte  2  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_LowPressuraShortGndDelayTime
  #error "Do not define EEP_LowPressuraShortGndDelayTime, because this is a lexem used for concatenation."
#endif
#define cDATEEP_LowPressuraShortGndDelayTimePositionByte      2 
#define cDATEEP_LowPressuraShortGndDelayTimePositionBit        0xFF
#define mSERPeeResetU16BitEEP_LowPressuraShortGndDelayTime()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  2 ,  7 ,  16 , 300, Delayed)
#define mSERReadU16BitEEP_LowPressuraShortGndDelayTimeDefaultValueDefault() ((U16)300)
#define mSERReadU16BitEEP_LowPressuraShortGndDelayTimeDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal2,  2 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_LowPressuraShortGndDelayTimeDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  2 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_LowPressuraShortGndDelayTimeImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  2 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_LowPressuraShortGndDelayTimeDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  2 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_LowPressuraShortGndKeepTime -- Group GroupSensorCal2, Byte  4  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_LowPressuraShortGndKeepTime
  #error "Do not define EEP_LowPressuraShortGndKeepTime, because this is a lexem used for concatenation."
#endif
#define cDATEEP_LowPressuraShortGndKeepTimePositionByte      4 
#define cDATEEP_LowPressuraShortGndKeepTimePositionBit        0xFF
#define mSERPeeResetU16BitEEP_LowPressuraShortGndKeepTime()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  4 ,  7 ,  16 , 200, Delayed)
#define mSERReadU16BitEEP_LowPressuraShortGndKeepTimeDefaultValueDefault() ((U16)200)
#define mSERReadU16BitEEP_LowPressuraShortGndKeepTimeDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal2,  4 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_LowPressuraShortGndKeepTimeDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  4 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_LowPressuraShortGndKeepTimeImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  4 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_LowPressuraShortGndKeepTimeDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  4 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_LowPressuraShortGndCur -- Group GroupSensorCal2, Byte  6  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_LowPressuraShortGndCur
  #error "Do not define EEP_LowPressuraShortGndCur, because this is a lexem used for concatenation."
#endif
#define cDATEEP_LowPressuraShortGndCurPositionByte      6 
#define cDATEEP_LowPressuraShortGndCurPositionBit        0xFF
#define mSERPeeResetU16BitEEP_LowPressuraShortGndCur()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  6 ,  7 ,  16 , 1200, Delayed)
#define mSERReadU16BitEEP_LowPressuraShortGndCurDefaultValueDefault() ((U16)1200)
#define mSERReadU16BitEEP_LowPressuraShortGndCurDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal2,  6 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_LowPressuraShortGndCurDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  6 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_LowPressuraShortGndCurImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  6 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_LowPressuraShortGndCurDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  6 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_LowPressuraOpenPowDelayTime -- Group GroupSensorCal2, Byte  8  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_LowPressuraOpenPowDelayTime
  #error "Do not define EEP_LowPressuraOpenPowDelayTime, because this is a lexem used for concatenation."
#endif
#define cDATEEP_LowPressuraOpenPowDelayTimePositionByte      8 
#define cDATEEP_LowPressuraOpenPowDelayTimePositionBit        0xFF
#define mSERPeeResetU16BitEEP_LowPressuraOpenPowDelayTime()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  8 ,  7 ,  16 , 300, Delayed)
#define mSERReadU16BitEEP_LowPressuraOpenPowDelayTimeDefaultValueDefault() ((U16)300)
#define mSERReadU16BitEEP_LowPressuraOpenPowDelayTimeDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal2,  8 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_LowPressuraOpenPowDelayTimeDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  8 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_LowPressuraOpenPowDelayTimeImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  8 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_LowPressuraOpenPowDelayTimeDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  8 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_LowPressuraOpenPowKeepTime -- Group GroupSensorCal2, Byte  10  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_LowPressuraOpenPowKeepTime
  #error "Do not define EEP_LowPressuraOpenPowKeepTime, because this is a lexem used for concatenation."
#endif
#define cDATEEP_LowPressuraOpenPowKeepTimePositionByte      10 
#define cDATEEP_LowPressuraOpenPowKeepTimePositionBit        0xFF
#define mSERPeeResetU16BitEEP_LowPressuraOpenPowKeepTime()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  10 ,  7 ,  16 , 200, Delayed)
#define mSERReadU16BitEEP_LowPressuraOpenPowKeepTimeDefaultValueDefault() ((U16)200)
#define mSERReadU16BitEEP_LowPressuraOpenPowKeepTimeDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal2,  10 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_LowPressuraOpenPowKeepTimeDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  10 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_LowPressuraOpenPowKeepTimeImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  10 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_LowPressuraOpenPowKeepTimeDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  10 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_LowPressuraOpenCur -- Group GroupSensorCal2, Byte  12  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_LowPressuraOpenCur
  #error "Do not define EEP_LowPressuraOpenCur, because this is a lexem used for concatenation."
#endif
#define cDATEEP_LowPressuraOpenCurPositionByte      12 
#define cDATEEP_LowPressuraOpenCurPositionBit        0xFF
#define mSERPeeResetU16BitEEP_LowPressuraOpenCur()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  12 ,  7 ,  16 , 100, Delayed)
#define mSERReadU16BitEEP_LowPressuraOpenCurDefaultValueDefault() ((U16)100)
#define mSERReadU16BitEEP_LowPressuraOpenCurDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal2,  12 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_LowPressuraOpenCurDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  12 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_LowPressuraOpenCurImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  12 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_LowPressuraOpenCurDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  12 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_Reserve1ShortPowDelayTime -- Group GroupSensorCal2, Byte  14  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_Reserve1ShortPowDelayTime
  #error "Do not define EEP_Reserve1ShortPowDelayTime, because this is a lexem used for concatenation."
#endif
#define cDATEEP_Reserve1ShortPowDelayTimePositionByte      14 
#define cDATEEP_Reserve1ShortPowDelayTimePositionBit        0xFF
#define mSERPeeResetU16BitEEP_Reserve1ShortPowDelayTime()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  14 ,  7 ,  16 , 300, Delayed)
#define mSERReadU16BitEEP_Reserve1ShortPowDelayTimeDefaultValueDefault() ((U16)300)
#define mSERReadU16BitEEP_Reserve1ShortPowDelayTimeDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal2,  14 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_Reserve1ShortPowDelayTimeDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  14 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_Reserve1ShortPowDelayTimeImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  14 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_Reserve1ShortPowDelayTimeDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  14 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_Reserve1ShortPowKeepTime -- Group GroupSensorCal2, Byte  16  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_Reserve1ShortPowKeepTime
  #error "Do not define EEP_Reserve1ShortPowKeepTime, because this is a lexem used for concatenation."
#endif
#define cDATEEP_Reserve1ShortPowKeepTimePositionByte      16 
#define cDATEEP_Reserve1ShortPowKeepTimePositionBit        0xFF
#define mSERPeeResetU16BitEEP_Reserve1ShortPowKeepTime()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  16 ,  7 ,  16 , 200, Delayed)
#define mSERReadU16BitEEP_Reserve1ShortPowKeepTimeDefaultValueDefault() ((U16)200)
#define mSERReadU16BitEEP_Reserve1ShortPowKeepTimeDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal2,  16 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_Reserve1ShortPowKeepTimeDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  16 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_Reserve1ShortPowKeepTimeImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  16 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_Reserve1ShortPowKeepTimeDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  16 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_Reserve1ShortPowVol -- Group GroupSensorCal2, Byte  18  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_Reserve1ShortPowVol
  #error "Do not define EEP_Reserve1ShortPowVol, because this is a lexem used for concatenation."
#endif
#define cDATEEP_Reserve1ShortPowVolPositionByte      18 
#define cDATEEP_Reserve1ShortPowVolPositionBit        0xFF
#define mSERPeeResetU16BitEEP_Reserve1ShortPowVol()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  18 ,  7 ,  16 , 16500, Delayed)
#define mSERReadU16BitEEP_Reserve1ShortPowVolDefaultValueDefault() ((U16)16500)
#define mSERReadU16BitEEP_Reserve1ShortPowVolDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal2,  18 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_Reserve1ShortPowVolDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  18 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_Reserve1ShortPowVolImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  18 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_Reserve1ShortPowVolDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  18 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_Reserve1ShortGndDelayTime -- Group GroupSensorCal2, Byte  20  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_Reserve1ShortGndDelayTime
  #error "Do not define EEP_Reserve1ShortGndDelayTime, because this is a lexem used for concatenation."
#endif
#define cDATEEP_Reserve1ShortGndDelayTimePositionByte      20 
#define cDATEEP_Reserve1ShortGndDelayTimePositionBit        0xFF
#define mSERPeeResetU16BitEEP_Reserve1ShortGndDelayTime()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  20 ,  7 ,  16 , 300, Delayed)
#define mSERReadU16BitEEP_Reserve1ShortGndDelayTimeDefaultValueDefault() ((U16)300)
#define mSERReadU16BitEEP_Reserve1ShortGndDelayTimeDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal2,  20 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_Reserve1ShortGndDelayTimeDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  20 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_Reserve1ShortGndDelayTimeImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  20 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_Reserve1ShortGndDelayTimeDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  20 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_Reserve1ShortGndKeepTime -- Group GroupSensorCal2, Byte  22  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_Reserve1ShortGndKeepTime
  #error "Do not define EEP_Reserve1ShortGndKeepTime, because this is a lexem used for concatenation."
#endif
#define cDATEEP_Reserve1ShortGndKeepTimePositionByte      22 
#define cDATEEP_Reserve1ShortGndKeepTimePositionBit        0xFF
#define mSERPeeResetU16BitEEP_Reserve1ShortGndKeepTime()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  22 ,  7 ,  16 , 200, Delayed)
#define mSERReadU16BitEEP_Reserve1ShortGndKeepTimeDefaultValueDefault() ((U16)200)
#define mSERReadU16BitEEP_Reserve1ShortGndKeepTimeDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal2,  22 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_Reserve1ShortGndKeepTimeDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  22 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_Reserve1ShortGndKeepTimeImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  22 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_Reserve1ShortGndKeepTimeDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  22 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_Reserve1ShortGndCur -- Group GroupSensorCal2, Byte  24  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_Reserve1ShortGndCur
  #error "Do not define EEP_Reserve1ShortGndCur, because this is a lexem used for concatenation."
#endif
#define cDATEEP_Reserve1ShortGndCurPositionByte      24 
#define cDATEEP_Reserve1ShortGndCurPositionBit        0xFF
#define mSERPeeResetU16BitEEP_Reserve1ShortGndCur()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  24 ,  7 ,  16 , 1200, Delayed)
#define mSERReadU16BitEEP_Reserve1ShortGndCurDefaultValueDefault() ((U16)1200)
#define mSERReadU16BitEEP_Reserve1ShortGndCurDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal2,  24 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_Reserve1ShortGndCurDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  24 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_Reserve1ShortGndCurImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  24 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_Reserve1ShortGndCurDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  24 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_Reserve1OpenPowDelayTime -- Group GroupSensorCal2, Byte  26  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_Reserve1OpenPowDelayTime
  #error "Do not define EEP_Reserve1OpenPowDelayTime, because this is a lexem used for concatenation."
#endif
#define cDATEEP_Reserve1OpenPowDelayTimePositionByte      26 
#define cDATEEP_Reserve1OpenPowDelayTimePositionBit        0xFF
#define mSERPeeResetU16BitEEP_Reserve1OpenPowDelayTime()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  26 ,  7 ,  16 , 300, Delayed)
#define mSERReadU16BitEEP_Reserve1OpenPowDelayTimeDefaultValueDefault() ((U16)300)
#define mSERReadU16BitEEP_Reserve1OpenPowDelayTimeDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal2,  26 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_Reserve1OpenPowDelayTimeDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  26 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_Reserve1OpenPowDelayTimeImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  26 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_Reserve1OpenPowDelayTimeDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  26 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_Reserve1OpenPowKeepTime -- Group GroupSensorCal2, Byte  28  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_Reserve1OpenPowKeepTime
  #error "Do not define EEP_Reserve1OpenPowKeepTime, because this is a lexem used for concatenation."
#endif
#define cDATEEP_Reserve1OpenPowKeepTimePositionByte      28 
#define cDATEEP_Reserve1OpenPowKeepTimePositionBit        0xFF
#define mSERPeeResetU16BitEEP_Reserve1OpenPowKeepTime()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  28 ,  7 ,  16 , 200, Delayed)
#define mSERReadU16BitEEP_Reserve1OpenPowKeepTimeDefaultValueDefault() ((U16)200)
#define mSERReadU16BitEEP_Reserve1OpenPowKeepTimeDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal2,  28 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_Reserve1OpenPowKeepTimeDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  28 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_Reserve1OpenPowKeepTimeImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  28 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_Reserve1OpenPowKeepTimeDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  28 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_Reserve1OpenCur -- Group GroupSensorCal2, Byte  30  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_Reserve1OpenCur
  #error "Do not define EEP_Reserve1OpenCur, because this is a lexem used for concatenation."
#endif
#define cDATEEP_Reserve1OpenCurPositionByte      30 
#define cDATEEP_Reserve1OpenCurPositionBit        0xFF
#define mSERPeeResetU16BitEEP_Reserve1OpenCur()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  30 ,  7 ,  16 , 100, Delayed)
#define mSERReadU16BitEEP_Reserve1OpenCurDefaultValueDefault() ((U16)100)
#define mSERReadU16BitEEP_Reserve1OpenCurDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal2,  30 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_Reserve1OpenCurDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  30 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_Reserve1OpenCurImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  30 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_Reserve1OpenCurDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  30 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_Reserve2ShortPowDelayTime -- Group GroupSensorCal2, Byte  32  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_Reserve2ShortPowDelayTime
  #error "Do not define EEP_Reserve2ShortPowDelayTime, because this is a lexem used for concatenation."
#endif
#define cDATEEP_Reserve2ShortPowDelayTimePositionByte      32 
#define cDATEEP_Reserve2ShortPowDelayTimePositionBit        0xFF
#define mSERPeeResetU16BitEEP_Reserve2ShortPowDelayTime()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  32 ,  7 ,  16 , 300, Delayed)
#define mSERReadU16BitEEP_Reserve2ShortPowDelayTimeDefaultValueDefault() ((U16)300)
#define mSERReadU16BitEEP_Reserve2ShortPowDelayTimeDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal2,  32 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_Reserve2ShortPowDelayTimeDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  32 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_Reserve2ShortPowDelayTimeImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  32 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_Reserve2ShortPowDelayTimeDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  32 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_Reserve2ShortPowKeepTime -- Group GroupSensorCal2, Byte  34  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_Reserve2ShortPowKeepTime
  #error "Do not define EEP_Reserve2ShortPowKeepTime, because this is a lexem used for concatenation."
#endif
#define cDATEEP_Reserve2ShortPowKeepTimePositionByte      34 
#define cDATEEP_Reserve2ShortPowKeepTimePositionBit        0xFF
#define mSERPeeResetU16BitEEP_Reserve2ShortPowKeepTime()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  34 ,  7 ,  16 , 200, Delayed)
#define mSERReadU16BitEEP_Reserve2ShortPowKeepTimeDefaultValueDefault() ((U16)200)
#define mSERReadU16BitEEP_Reserve2ShortPowKeepTimeDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal2,  34 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_Reserve2ShortPowKeepTimeDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  34 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_Reserve2ShortPowKeepTimeImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  34 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_Reserve2ShortPowKeepTimeDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  34 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_Reserve2ShortGndDelayTime -- Group GroupSensorCal2, Byte  36  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_Reserve2ShortGndDelayTime
  #error "Do not define EEP_Reserve2ShortGndDelayTime, because this is a lexem used for concatenation."
#endif
#define cDATEEP_Reserve2ShortGndDelayTimePositionByte      36 
#define cDATEEP_Reserve2ShortGndDelayTimePositionBit        0xFF
#define mSERPeeResetU16BitEEP_Reserve2ShortGndDelayTime()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  36 ,  7 ,  16 , 300, Delayed)
#define mSERReadU16BitEEP_Reserve2ShortGndDelayTimeDefaultValueDefault() ((U16)300)
#define mSERReadU16BitEEP_Reserve2ShortGndDelayTimeDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal2,  36 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_Reserve2ShortGndDelayTimeDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  36 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_Reserve2ShortGndDelayTimeImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  36 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_Reserve2ShortGndDelayTimeDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  36 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_Reserve2ShortGndKeepTime -- Group GroupSensorCal2, Byte  38  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_Reserve2ShortGndKeepTime
  #error "Do not define EEP_Reserve2ShortGndKeepTime, because this is a lexem used for concatenation."
#endif
#define cDATEEP_Reserve2ShortGndKeepTimePositionByte      38 
#define cDATEEP_Reserve2ShortGndKeepTimePositionBit        0xFF
#define mSERPeeResetU16BitEEP_Reserve2ShortGndKeepTime()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  38 ,  7 ,  16 , 200, Delayed)
#define mSERReadU16BitEEP_Reserve2ShortGndKeepTimeDefaultValueDefault() ((U16)200)
#define mSERReadU16BitEEP_Reserve2ShortGndKeepTimeDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal2,  38 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_Reserve2ShortGndKeepTimeDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  38 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_Reserve2ShortGndKeepTimeImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  38 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_Reserve2ShortGndKeepTimeDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  38 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_Reserve2OpenPowDelayTime -- Group GroupSensorCal2, Byte  40  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_Reserve2OpenPowDelayTime
  #error "Do not define EEP_Reserve2OpenPowDelayTime, because this is a lexem used for concatenation."
#endif
#define cDATEEP_Reserve2OpenPowDelayTimePositionByte      40 
#define cDATEEP_Reserve2OpenPowDelayTimePositionBit        0xFF
#define mSERPeeResetU16BitEEP_Reserve2OpenPowDelayTime()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  40 ,  7 ,  16 , 300, Delayed)
#define mSERReadU16BitEEP_Reserve2OpenPowDelayTimeDefaultValueDefault() ((U16)300)
#define mSERReadU16BitEEP_Reserve2OpenPowDelayTimeDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal2,  40 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_Reserve2OpenPowDelayTimeDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  40 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_Reserve2OpenPowDelayTimeImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  40 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_Reserve2OpenPowDelayTimeDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  40 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_Reserve2OpenPowKeepTime -- Group GroupSensorCal2, Byte  42  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_Reserve2OpenPowKeepTime
  #error "Do not define EEP_Reserve2OpenPowKeepTime, because this is a lexem used for concatenation."
#endif
#define cDATEEP_Reserve2OpenPowKeepTimePositionByte      42 
#define cDATEEP_Reserve2OpenPowKeepTimePositionBit        0xFF
#define mSERPeeResetU16BitEEP_Reserve2OpenPowKeepTime()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  42 ,  7 ,  16 , 200, Delayed)
#define mSERReadU16BitEEP_Reserve2OpenPowKeepTimeDefaultValueDefault() ((U16)200)
#define mSERReadU16BitEEP_Reserve2OpenPowKeepTimeDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal2,  42 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_Reserve2OpenPowKeepTimeDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  42 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_Reserve2OpenPowKeepTimeImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  42 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_Reserve2OpenPowKeepTimeDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  42 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_Reserve2ShortPowVol -- Group GroupSensorCal2, Byte  44  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_Reserve2ShortPowVol
  #error "Do not define EEP_Reserve2ShortPowVol, because this is a lexem used for concatenation."
#endif
#define cDATEEP_Reserve2ShortPowVolPositionByte      44 
#define cDATEEP_Reserve2ShortPowVolPositionBit        0xFF
#define mSERPeeResetU16BitEEP_Reserve2ShortPowVol()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  44 ,  7 ,  16 , 16500, Delayed)
#define mSERReadU16BitEEP_Reserve2ShortPowVolDefaultValueDefault() ((U16)16500)
#define mSERReadU16BitEEP_Reserve2ShortPowVolDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal2,  44 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_Reserve2ShortPowVolDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  44 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_Reserve2ShortPowVolImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  44 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_Reserve2ShortPowVolDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  44 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_Reserve2ShortGndCur -- Group GroupSensorCal2, Byte  46  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_Reserve2ShortGndCur
  #error "Do not define EEP_Reserve2ShortGndCur, because this is a lexem used for concatenation."
#endif
#define cDATEEP_Reserve2ShortGndCurPositionByte      46 
#define cDATEEP_Reserve2ShortGndCurPositionBit        0xFF
#define mSERPeeResetU16BitEEP_Reserve2ShortGndCur()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  46 ,  7 ,  16 , 1200, Delayed)
#define mSERReadU16BitEEP_Reserve2ShortGndCurDefaultValueDefault() ((U16)1200)
#define mSERReadU16BitEEP_Reserve2ShortGndCurDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal2,  46 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_Reserve2ShortGndCurDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  46 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_Reserve2ShortGndCurImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  46 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_Reserve2ShortGndCurDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  46 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_Reserve2OpenCur -- Group GroupSensorCal2, Byte  48  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_Reserve2OpenCur
  #error "Do not define EEP_Reserve2OpenCur, because this is a lexem used for concatenation."
#endif
#define cDATEEP_Reserve2OpenCurPositionByte      48 
#define cDATEEP_Reserve2OpenCurPositionBit        0xFF
#define mSERPeeResetU16BitEEP_Reserve2OpenCur()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  48 ,  7 ,  16 , 100, Delayed)
#define mSERReadU16BitEEP_Reserve2OpenCurDefaultValueDefault() ((U16)100)
#define mSERReadU16BitEEP_Reserve2OpenCurDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal2,  48 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_Reserve2OpenCurDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  48 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_Reserve2OpenCurImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  48 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_Reserve2OpenCurDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  48 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_Reserve3ShortPowDelayTime -- Group GroupSensorCal2, Byte  50  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_Reserve3ShortPowDelayTime
  #error "Do not define EEP_Reserve3ShortPowDelayTime, because this is a lexem used for concatenation."
#endif
#define cDATEEP_Reserve3ShortPowDelayTimePositionByte      50 
#define cDATEEP_Reserve3ShortPowDelayTimePositionBit        0xFF
#define mSERPeeResetU16BitEEP_Reserve3ShortPowDelayTime()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  50 ,  7 ,  16 , 300, Delayed)
#define mSERReadU16BitEEP_Reserve3ShortPowDelayTimeDefaultValueDefault() ((U16)300)
#define mSERReadU16BitEEP_Reserve3ShortPowDelayTimeDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal2,  50 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_Reserve3ShortPowDelayTimeDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  50 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_Reserve3ShortPowDelayTimeImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  50 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_Reserve3ShortPowDelayTimeDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  50 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_Reserve3ShortPowKeepTime -- Group GroupSensorCal2, Byte  52  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_Reserve3ShortPowKeepTime
  #error "Do not define EEP_Reserve3ShortPowKeepTime, because this is a lexem used for concatenation."
#endif
#define cDATEEP_Reserve3ShortPowKeepTimePositionByte      52 
#define cDATEEP_Reserve3ShortPowKeepTimePositionBit        0xFF
#define mSERPeeResetU16BitEEP_Reserve3ShortPowKeepTime()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  52 ,  7 ,  16 , 200, Delayed)
#define mSERReadU16BitEEP_Reserve3ShortPowKeepTimeDefaultValueDefault() ((U16)200)
#define mSERReadU16BitEEP_Reserve3ShortPowKeepTimeDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal2,  52 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_Reserve3ShortPowKeepTimeDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  52 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_Reserve3ShortPowKeepTimeImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  52 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_Reserve3ShortPowKeepTimeDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  52 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_Reserve3ShortGndDelayTime -- Group GroupSensorCal2, Byte  54  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_Reserve3ShortGndDelayTime
  #error "Do not define EEP_Reserve3ShortGndDelayTime, because this is a lexem used for concatenation."
#endif
#define cDATEEP_Reserve3ShortGndDelayTimePositionByte      54 
#define cDATEEP_Reserve3ShortGndDelayTimePositionBit        0xFF
#define mSERPeeResetU16BitEEP_Reserve3ShortGndDelayTime()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  54 ,  7 ,  16 , 300, Delayed)
#define mSERReadU16BitEEP_Reserve3ShortGndDelayTimeDefaultValueDefault() ((U16)300)
#define mSERReadU16BitEEP_Reserve3ShortGndDelayTimeDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal2,  54 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_Reserve3ShortGndDelayTimeDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  54 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_Reserve3ShortGndDelayTimeImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  54 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_Reserve3ShortGndDelayTimeDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  54 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_Reserve3ShortGndKeepTime -- Group GroupSensorCal2, Byte  56  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_Reserve3ShortGndKeepTime
  #error "Do not define EEP_Reserve3ShortGndKeepTime, because this is a lexem used for concatenation."
#endif
#define cDATEEP_Reserve3ShortGndKeepTimePositionByte      56 
#define cDATEEP_Reserve3ShortGndKeepTimePositionBit        0xFF
#define mSERPeeResetU16BitEEP_Reserve3ShortGndKeepTime()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  56 ,  7 ,  16 , 200, Delayed)
#define mSERReadU16BitEEP_Reserve3ShortGndKeepTimeDefaultValueDefault() ((U16)200)
#define mSERReadU16BitEEP_Reserve3ShortGndKeepTimeDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal2,  56 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_Reserve3ShortGndKeepTimeDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  56 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_Reserve3ShortGndKeepTimeImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  56 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_Reserve3ShortGndKeepTimeDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  56 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_Reserve3OpenPowDelayTime -- Group GroupSensorCal2, Byte  58  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_Reserve3OpenPowDelayTime
  #error "Do not define EEP_Reserve3OpenPowDelayTime, because this is a lexem used for concatenation."
#endif
#define cDATEEP_Reserve3OpenPowDelayTimePositionByte      58 
#define cDATEEP_Reserve3OpenPowDelayTimePositionBit        0xFF
#define mSERPeeResetU16BitEEP_Reserve3OpenPowDelayTime()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  58 ,  7 ,  16 , 300, Delayed)
#define mSERReadU16BitEEP_Reserve3OpenPowDelayTimeDefaultValueDefault() ((U16)300)
#define mSERReadU16BitEEP_Reserve3OpenPowDelayTimeDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal2,  58 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_Reserve3OpenPowDelayTimeDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  58 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_Reserve3OpenPowDelayTimeImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  58 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_Reserve3OpenPowDelayTimeDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  58 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_Reserve3OpenPowKeepTime -- Group GroupSensorCal2, Byte  60  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_Reserve3OpenPowKeepTime
  #error "Do not define EEP_Reserve3OpenPowKeepTime, because this is a lexem used for concatenation."
#endif
#define cDATEEP_Reserve3OpenPowKeepTimePositionByte      60 
#define cDATEEP_Reserve3OpenPowKeepTimePositionBit        0xFF
#define mSERPeeResetU16BitEEP_Reserve3OpenPowKeepTime()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  60 ,  7 ,  16 , 200, Delayed)
#define mSERReadU16BitEEP_Reserve3OpenPowKeepTimeDefaultValueDefault() ((U16)200)
#define mSERReadU16BitEEP_Reserve3OpenPowKeepTimeDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal2,  60 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_Reserve3OpenPowKeepTimeDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  60 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_Reserve3OpenPowKeepTimeImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  60 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_Reserve3OpenPowKeepTimeDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  60 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_Reserve3ShortPowVol -- Group GroupSensorCal2, Byte  62  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_Reserve3ShortPowVol
  #error "Do not define EEP_Reserve3ShortPowVol, because this is a lexem used for concatenation."
#endif
#define cDATEEP_Reserve3ShortPowVolPositionByte      62 
#define cDATEEP_Reserve3ShortPowVolPositionBit        0xFF
#define mSERPeeResetU16BitEEP_Reserve3ShortPowVol()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  62 ,  7 ,  16 , 16500, Delayed)
#define mSERReadU16BitEEP_Reserve3ShortPowVolDefaultValueDefault() ((U16)16500)
#define mSERReadU16BitEEP_Reserve3ShortPowVolDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal2,  62 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_Reserve3ShortPowVolDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  62 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_Reserve3ShortPowVolImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  62 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_Reserve3ShortPowVolDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  62 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_Reserve3ShortGndCur -- Group GroupSensorCal2, Byte  64  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_Reserve3ShortGndCur
  #error "Do not define EEP_Reserve3ShortGndCur, because this is a lexem used for concatenation."
#endif
#define cDATEEP_Reserve3ShortGndCurPositionByte      64 
#define cDATEEP_Reserve3ShortGndCurPositionBit        0xFF
#define mSERPeeResetU16BitEEP_Reserve3ShortGndCur()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  64 ,  7 ,  16 , 1200, Delayed)
#define mSERReadU16BitEEP_Reserve3ShortGndCurDefaultValueDefault() ((U16)1200)
#define mSERReadU16BitEEP_Reserve3ShortGndCurDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal2,  64 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_Reserve3ShortGndCurDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  64 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_Reserve3ShortGndCurImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  64 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_Reserve3ShortGndCurDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  64 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_Reserve3OpenCur -- Group GroupSensorCal2, Byte  66  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_Reserve3OpenCur
  #error "Do not define EEP_Reserve3OpenCur, because this is a lexem used for concatenation."
#endif
#define cDATEEP_Reserve3OpenCurPositionByte      66 
#define cDATEEP_Reserve3OpenCurPositionBit        0xFF
#define mSERPeeResetU16BitEEP_Reserve3OpenCur()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  66 ,  7 ,  16 , 100, Delayed)
#define mSERReadU16BitEEP_Reserve3OpenCurDefaultValueDefault() ((U16)100)
#define mSERReadU16BitEEP_Reserve3OpenCurDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal2,  66 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_Reserve3OpenCurDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  66 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_Reserve3OpenCurImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  66 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_Reserve3OpenCurDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  66 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_Reserve4ShortPowDelayTime -- Group GroupSensorCal2, Byte  68  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_Reserve4ShortPowDelayTime
  #error "Do not define EEP_Reserve4ShortPowDelayTime, because this is a lexem used for concatenation."
#endif
#define cDATEEP_Reserve4ShortPowDelayTimePositionByte      68 
#define cDATEEP_Reserve4ShortPowDelayTimePositionBit        0xFF
#define mSERPeeResetU16BitEEP_Reserve4ShortPowDelayTime()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  68 ,  7 ,  16 , 300, Delayed)
#define mSERReadU16BitEEP_Reserve4ShortPowDelayTimeDefaultValueDefault() ((U16)300)
#define mSERReadU16BitEEP_Reserve4ShortPowDelayTimeDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal2,  68 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_Reserve4ShortPowDelayTimeDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  68 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_Reserve4ShortPowDelayTimeImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  68 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_Reserve4ShortPowDelayTimeDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  68 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_Reserve4ShortPowKeepTime -- Group GroupSensorCal2, Byte  70  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_Reserve4ShortPowKeepTime
  #error "Do not define EEP_Reserve4ShortPowKeepTime, because this is a lexem used for concatenation."
#endif
#define cDATEEP_Reserve4ShortPowKeepTimePositionByte      70 
#define cDATEEP_Reserve4ShortPowKeepTimePositionBit        0xFF
#define mSERPeeResetU16BitEEP_Reserve4ShortPowKeepTime()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  70 ,  7 ,  16 , 200, Delayed)
#define mSERReadU16BitEEP_Reserve4ShortPowKeepTimeDefaultValueDefault() ((U16)200)
#define mSERReadU16BitEEP_Reserve4ShortPowKeepTimeDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal2,  70 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_Reserve4ShortPowKeepTimeDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  70 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_Reserve4ShortPowKeepTimeImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  70 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_Reserve4ShortPowKeepTimeDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  70 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_Reserve4ShortGndDelayTime -- Group GroupSensorCal2, Byte  72  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_Reserve4ShortGndDelayTime
  #error "Do not define EEP_Reserve4ShortGndDelayTime, because this is a lexem used for concatenation."
#endif
#define cDATEEP_Reserve4ShortGndDelayTimePositionByte      72 
#define cDATEEP_Reserve4ShortGndDelayTimePositionBit        0xFF
#define mSERPeeResetU16BitEEP_Reserve4ShortGndDelayTime()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  72 ,  7 ,  16 , 300, Delayed)
#define mSERReadU16BitEEP_Reserve4ShortGndDelayTimeDefaultValueDefault() ((U16)300)
#define mSERReadU16BitEEP_Reserve4ShortGndDelayTimeDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal2,  72 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_Reserve4ShortGndDelayTimeDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  72 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_Reserve4ShortGndDelayTimeImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  72 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_Reserve4ShortGndDelayTimeDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  72 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_Reserve4ShortGndKeepTime -- Group GroupSensorCal2, Byte  74  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_Reserve4ShortGndKeepTime
  #error "Do not define EEP_Reserve4ShortGndKeepTime, because this is a lexem used for concatenation."
#endif
#define cDATEEP_Reserve4ShortGndKeepTimePositionByte      74 
#define cDATEEP_Reserve4ShortGndKeepTimePositionBit        0xFF
#define mSERPeeResetU16BitEEP_Reserve4ShortGndKeepTime()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  74 ,  7 ,  16 , 200, Delayed)
#define mSERReadU16BitEEP_Reserve4ShortGndKeepTimeDefaultValueDefault() ((U16)200)
#define mSERReadU16BitEEP_Reserve4ShortGndKeepTimeDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal2,  74 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_Reserve4ShortGndKeepTimeDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  74 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_Reserve4ShortGndKeepTimeImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  74 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_Reserve4ShortGndKeepTimeDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  74 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_Reserve4OpenPowDelayTime -- Group GroupSensorCal2, Byte  76  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_Reserve4OpenPowDelayTime
  #error "Do not define EEP_Reserve4OpenPowDelayTime, because this is a lexem used for concatenation."
#endif
#define cDATEEP_Reserve4OpenPowDelayTimePositionByte      76 
#define cDATEEP_Reserve4OpenPowDelayTimePositionBit        0xFF
#define mSERPeeResetU16BitEEP_Reserve4OpenPowDelayTime()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  76 ,  7 ,  16 , 300, Delayed)
#define mSERReadU16BitEEP_Reserve4OpenPowDelayTimeDefaultValueDefault() ((U16)300)
#define mSERReadU16BitEEP_Reserve4OpenPowDelayTimeDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal2,  76 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_Reserve4OpenPowDelayTimeDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  76 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_Reserve4OpenPowDelayTimeImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  76 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_Reserve4OpenPowDelayTimeDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  76 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_Reserve4OpenPowKeepTime -- Group GroupSensorCal2, Byte  78  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_Reserve4OpenPowKeepTime
  #error "Do not define EEP_Reserve4OpenPowKeepTime, because this is a lexem used for concatenation."
#endif
#define cDATEEP_Reserve4OpenPowKeepTimePositionByte      78 
#define cDATEEP_Reserve4OpenPowKeepTimePositionBit        0xFF
#define mSERPeeResetU16BitEEP_Reserve4OpenPowKeepTime()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  78 ,  7 ,  16 , 200, Delayed)
#define mSERReadU16BitEEP_Reserve4OpenPowKeepTimeDefaultValueDefault() ((U16)200)
#define mSERReadU16BitEEP_Reserve4OpenPowKeepTimeDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal2,  78 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_Reserve4OpenPowKeepTimeDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  78 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_Reserve4OpenPowKeepTimeImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  78 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_Reserve4OpenPowKeepTimeDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  78 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_Reserve4ShortPowVol -- Group GroupSensorCal2, Byte  80  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_Reserve4ShortPowVol
  #error "Do not define EEP_Reserve4ShortPowVol, because this is a lexem used for concatenation."
#endif
#define cDATEEP_Reserve4ShortPowVolPositionByte      80 
#define cDATEEP_Reserve4ShortPowVolPositionBit        0xFF
#define mSERPeeResetU16BitEEP_Reserve4ShortPowVol()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  80 ,  7 ,  16 , 16500, Delayed)
#define mSERReadU16BitEEP_Reserve4ShortPowVolDefaultValueDefault() ((U16)16500)
#define mSERReadU16BitEEP_Reserve4ShortPowVolDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal2,  80 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_Reserve4ShortPowVolDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  80 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_Reserve4ShortPowVolImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  80 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_Reserve4ShortPowVolDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  80 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_Reserve4ShortGndCur -- Group GroupSensorCal2, Byte  82  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_Reserve4ShortGndCur
  #error "Do not define EEP_Reserve4ShortGndCur, because this is a lexem used for concatenation."
#endif
#define cDATEEP_Reserve4ShortGndCurPositionByte      82 
#define cDATEEP_Reserve4ShortGndCurPositionBit        0xFF
#define mSERPeeResetU16BitEEP_Reserve4ShortGndCur()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  82 ,  7 ,  16 , 1200, Delayed)
#define mSERReadU16BitEEP_Reserve4ShortGndCurDefaultValueDefault() ((U16)1200)
#define mSERReadU16BitEEP_Reserve4ShortGndCurDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal2,  82 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_Reserve4ShortGndCurDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  82 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_Reserve4ShortGndCurImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  82 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_Reserve4ShortGndCurDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  82 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_Reserve4OpenCur -- Group GroupSensorCal2, Byte  84  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_Reserve4OpenCur
  #error "Do not define EEP_Reserve4OpenCur, because this is a lexem used for concatenation."
#endif
#define cDATEEP_Reserve4OpenCurPositionByte      84 
#define cDATEEP_Reserve4OpenCurPositionBit        0xFF
#define mSERPeeResetU16BitEEP_Reserve4OpenCur()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  84 ,  7 ,  16 , 100, Delayed)
#define mSERReadU16BitEEP_Reserve4OpenCurDefaultValueDefault() ((U16)100)
#define mSERReadU16BitEEP_Reserve4OpenCurDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal2,  84 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_Reserve4OpenCurDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  84 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_Reserve4OpenCurImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  84 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_Reserve4OpenCurDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  84 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_Reserve5ShortPowDelayTime -- Group GroupSensorCal2, Byte  86  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_Reserve5ShortPowDelayTime
  #error "Do not define EEP_Reserve5ShortPowDelayTime, because this is a lexem used for concatenation."
#endif
#define cDATEEP_Reserve5ShortPowDelayTimePositionByte      86 
#define cDATEEP_Reserve5ShortPowDelayTimePositionBit        0xFF
#define mSERPeeResetU16BitEEP_Reserve5ShortPowDelayTime()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  86 ,  7 ,  16 , 300, Delayed)
#define mSERReadU16BitEEP_Reserve5ShortPowDelayTimeDefaultValueDefault() ((U16)300)
#define mSERReadU16BitEEP_Reserve5ShortPowDelayTimeDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal2,  86 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_Reserve5ShortPowDelayTimeDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  86 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_Reserve5ShortPowDelayTimeImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  86 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_Reserve5ShortPowDelayTimeDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  86 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_Reserve5ShortPowKeepTime -- Group GroupSensorCal2, Byte  88  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_Reserve5ShortPowKeepTime
  #error "Do not define EEP_Reserve5ShortPowKeepTime, because this is a lexem used for concatenation."
#endif
#define cDATEEP_Reserve5ShortPowKeepTimePositionByte      88 
#define cDATEEP_Reserve5ShortPowKeepTimePositionBit        0xFF
#define mSERPeeResetU16BitEEP_Reserve5ShortPowKeepTime()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  88 ,  7 ,  16 , 200, Delayed)
#define mSERReadU16BitEEP_Reserve5ShortPowKeepTimeDefaultValueDefault() ((U16)200)
#define mSERReadU16BitEEP_Reserve5ShortPowKeepTimeDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal2,  88 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_Reserve5ShortPowKeepTimeDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  88 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_Reserve5ShortPowKeepTimeImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  88 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_Reserve5ShortPowKeepTimeDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  88 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_Reserve5ShortGndDelayTime -- Group GroupSensorCal2, Byte  90  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_Reserve5ShortGndDelayTime
  #error "Do not define EEP_Reserve5ShortGndDelayTime, because this is a lexem used for concatenation."
#endif
#define cDATEEP_Reserve5ShortGndDelayTimePositionByte      90 
#define cDATEEP_Reserve5ShortGndDelayTimePositionBit        0xFF
#define mSERPeeResetU16BitEEP_Reserve5ShortGndDelayTime()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  90 ,  7 ,  16 , 300, Delayed)
#define mSERReadU16BitEEP_Reserve5ShortGndDelayTimeDefaultValueDefault() ((U16)300)
#define mSERReadU16BitEEP_Reserve5ShortGndDelayTimeDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal2,  90 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_Reserve5ShortGndDelayTimeDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  90 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_Reserve5ShortGndDelayTimeImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  90 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_Reserve5ShortGndDelayTimeDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  90 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_Reserve5ShortGndKeepTime -- Group GroupSensorCal2, Byte  92  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_Reserve5ShortGndKeepTime
  #error "Do not define EEP_Reserve5ShortGndKeepTime, because this is a lexem used for concatenation."
#endif
#define cDATEEP_Reserve5ShortGndKeepTimePositionByte      92 
#define cDATEEP_Reserve5ShortGndKeepTimePositionBit        0xFF
#define mSERPeeResetU16BitEEP_Reserve5ShortGndKeepTime()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  92 ,  7 ,  16 , 200, Delayed)
#define mSERReadU16BitEEP_Reserve5ShortGndKeepTimeDefaultValueDefault() ((U16)200)
#define mSERReadU16BitEEP_Reserve5ShortGndKeepTimeDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal2,  92 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_Reserve5ShortGndKeepTimeDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  92 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_Reserve5ShortGndKeepTimeImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  92 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_Reserve5ShortGndKeepTimeDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  92 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_Reserve5OpenPowDelayTime -- Group GroupSensorCal2, Byte  94  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_Reserve5OpenPowDelayTime
  #error "Do not define EEP_Reserve5OpenPowDelayTime, because this is a lexem used for concatenation."
#endif
#define cDATEEP_Reserve5OpenPowDelayTimePositionByte      94 
#define cDATEEP_Reserve5OpenPowDelayTimePositionBit        0xFF
#define mSERPeeResetU16BitEEP_Reserve5OpenPowDelayTime()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  94 ,  7 ,  16 , 300, Delayed)
#define mSERReadU16BitEEP_Reserve5OpenPowDelayTimeDefaultValueDefault() ((U16)300)
#define mSERReadU16BitEEP_Reserve5OpenPowDelayTimeDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal2,  94 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_Reserve5OpenPowDelayTimeDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  94 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_Reserve5OpenPowDelayTimeImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  94 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_Reserve5OpenPowDelayTimeDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  94 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_Reserve5OpenPowKeepTime -- Group GroupSensorCal2, Byte  96  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_Reserve5OpenPowKeepTime
  #error "Do not define EEP_Reserve5OpenPowKeepTime, because this is a lexem used for concatenation."
#endif
#define cDATEEP_Reserve5OpenPowKeepTimePositionByte      96 
#define cDATEEP_Reserve5OpenPowKeepTimePositionBit        0xFF
#define mSERPeeResetU16BitEEP_Reserve5OpenPowKeepTime()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  96 ,  7 ,  16 , 200, Delayed)
#define mSERReadU16BitEEP_Reserve5OpenPowKeepTimeDefaultValueDefault() ((U16)200)
#define mSERReadU16BitEEP_Reserve5OpenPowKeepTimeDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal2,  96 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_Reserve5OpenPowKeepTimeDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  96 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_Reserve5OpenPowKeepTimeImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  96 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_Reserve5OpenPowKeepTimeDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  96 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_Reserve5ShortPowVol -- Group GroupSensorCal2, Byte  98  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_Reserve5ShortPowVol
  #error "Do not define EEP_Reserve5ShortPowVol, because this is a lexem used for concatenation."
#endif
#define cDATEEP_Reserve5ShortPowVolPositionByte      98 
#define cDATEEP_Reserve5ShortPowVolPositionBit        0xFF
#define mSERPeeResetU16BitEEP_Reserve5ShortPowVol()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  98 ,  7 ,  16 , 16500, Delayed)
#define mSERReadU16BitEEP_Reserve5ShortPowVolDefaultValueDefault() ((U16)16500)
#define mSERReadU16BitEEP_Reserve5ShortPowVolDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal2,  98 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_Reserve5ShortPowVolDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  98 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_Reserve5ShortPowVolImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  98 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_Reserve5ShortPowVolDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  98 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_Reserve5ShortGndCur -- Group GroupSensorCal2, Byte  100  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_Reserve5ShortGndCur
  #error "Do not define EEP_Reserve5ShortGndCur, because this is a lexem used for concatenation."
#endif
#define cDATEEP_Reserve5ShortGndCurPositionByte      100 
#define cDATEEP_Reserve5ShortGndCurPositionBit        0xFF
#define mSERPeeResetU16BitEEP_Reserve5ShortGndCur()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  100 ,  7 ,  16 , 1200, Delayed)
#define mSERReadU16BitEEP_Reserve5ShortGndCurDefaultValueDefault() ((U16)1200)
#define mSERReadU16BitEEP_Reserve5ShortGndCurDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal2,  100 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_Reserve5ShortGndCurDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  100 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_Reserve5ShortGndCurImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  100 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_Reserve5ShortGndCurDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  100 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_Reserve5OpenCur -- Group GroupSensorCal2, Byte  102  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_Reserve5OpenCur
  #error "Do not define EEP_Reserve5OpenCur, because this is a lexem used for concatenation."
#endif
#define cDATEEP_Reserve5OpenCurPositionByte      102 
#define cDATEEP_Reserve5OpenCurPositionBit        0xFF
#define mSERPeeResetU16BitEEP_Reserve5OpenCur()     \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  102 ,  7 ,  16 , 100, Delayed)
#define mSERReadU16BitEEP_Reserve5OpenCurDefaultValueDefault() ((U16)100)
#define mSERReadU16BitEEP_Reserve5OpenCurDefault() \
      mSERPeeReadU16Bit(Dbk, GroupSensorCal2,  102 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_Reserve5OpenCurDelayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  102 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_Reserve5OpenCurImmediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  102 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_Reserve5OpenCurDefault(ValueToWrite) \
      mSERPeeWriteU16Bit(Dbk, GroupSensorCal2,  102 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_StudyFlag -- Group GroupSensorCal2, Byte  104  , Bit (MSB)  7  , SizeInBit  8 
#ifdef EEP_StudyFlag
  #error "Do not define EEP_StudyFlag, because this is a lexem used for concatenation."
#endif
#define cDATEEP_StudyFlagPositionByte      104 
#define cDATEEP_StudyFlagPositionBit        0xFF
#define mSERPeeResetU8BitEEP_StudyFlag()     \
      mSERPeeWriteU8Bit(Dbk, GroupSensorCal2,  104 ,  7 ,  8 , 0, Delayed)
#define mSERReadU8BitEEP_StudyFlagDefaultValueDefault() ((U8)0)
#define mSERReadU8BitEEP_StudyFlagDefault() \
      mSERPeeReadU8Bit(Dbk, GroupSensorCal2,  104 ,  7 ,  8 , Delayed)
#define mSERWriteU8BitEEP_StudyFlagDelayed(ValueToWrite) \
      mSERPeeWriteU8Bit(Dbk, GroupSensorCal2,  104 ,  7 ,  8 , (ValueToWrite), Delayed)
#define mSERWriteU8BitEEP_StudyFlagImmediate(ValueToWrite) \
      mSERPeeWriteU8Bit(Dbk, GroupSensorCal2,  104 ,  7 ,  8 , (ValueToWrite), Immediate)
#define mSERWriteU8BitEEP_StudyFlagDefault(ValueToWrite) \
      mSERPeeWriteU8Bit(Dbk, GroupSensorCal2,  104 ,  7 ,  8 , (ValueToWrite), Immediate)

// EEP_StudyError -- Group GroupSensorCal2, Byte  105  , Bit (MSB)  7  , SizeInBit  8 
#ifdef EEP_StudyError
  #error "Do not define EEP_StudyError, because this is a lexem used for concatenation."
#endif
#define cDATEEP_StudyErrorPositionByte      105 
#define cDATEEP_StudyErrorPositionBit        0xFF
#define mSERPeeResetU8BitEEP_StudyError()     \
      mSERPeeWriteU8Bit(Dbk, GroupSensorCal2,  105 ,  7 ,  8 , 1, Delayed)
#define mSERReadU8BitEEP_StudyErrorDefaultValueDefault() ((U8)1)
#define mSERReadU8BitEEP_StudyErrorDefault() \
      mSERPeeReadU8Bit(Dbk, GroupSensorCal2,  105 ,  7 ,  8 , Delayed)
#define mSERWriteU8BitEEP_StudyErrorDelayed(ValueToWrite) \
      mSERPeeWriteU8Bit(Dbk, GroupSensorCal2,  105 ,  7 ,  8 , (ValueToWrite), Delayed)
#define mSERWriteU8BitEEP_StudyErrorImmediate(ValueToWrite) \
      mSERPeeWriteU8Bit(Dbk, GroupSensorCal2,  105 ,  7 ,  8 , (ValueToWrite), Immediate)
#define mSERWriteU8BitEEP_StudyErrorDefault(ValueToWrite) \
      mSERPeeWriteU8Bit(Dbk, GroupSensorCal2,  105 ,  7 ,  8 , (ValueToWrite), Immediate)

// EEP_SleepTime -- Group GroupSensorCal2, Byte  106  , Bit (MSB)  7  , SizeInBit  8 
#ifdef EEP_SleepTime
  #error "Do not define EEP_SleepTime, because this is a lexem used for concatenation."
#endif
#define cDATEEP_SleepTimePositionByte      106 
#define cDATEEP_SleepTimePositionBit        0xFF
#define mSERPeeResetU8BitEEP_SleepTime()     \
      mSERPeeWriteU8Bit(Dbk, GroupSensorCal2,  106 ,  7 ,  8 , 120, Delayed)
#define mSERReadU8BitEEP_SleepTimeDefaultValueDefault() ((U8)120)
#define mSERReadU8BitEEP_SleepTimeDefault() \
      mSERPeeReadU8Bit(Dbk, GroupSensorCal2,  106 ,  7 ,  8 , Delayed)
#define mSERWriteU8BitEEP_SleepTimeDelayed(ValueToWrite) \
      mSERPeeWriteU8Bit(Dbk, GroupSensorCal2,  106 ,  7 ,  8 , (ValueToWrite), Delayed)
#define mSERWriteU8BitEEP_SleepTimeImmediate(ValueToWrite) \
      mSERPeeWriteU8Bit(Dbk, GroupSensorCal2,  106 ,  7 ,  8 , (ValueToWrite), Immediate)
#define mSERWriteU8BitEEP_SleepTimeDefault(ValueToWrite) \
      mSERPeeWriteU8Bit(Dbk, GroupSensorCal2,  106 ,  7 ,  8 , (ValueToWrite), Immediate)

// EEP_StartDistance -- Group GroupSensorCal2, Byte  107  , Bit (MSB)  7  , SizeInBit  8 
#ifdef EEP_StartDistance
  #error "Do not define EEP_StartDistance, because this is a lexem used for concatenation."
#endif
#define cDATEEP_StartDistancePositionByte      107 
#define cDATEEP_StartDistancePositionBit        0xFF
#define mSERPeeResetU8BitEEP_StartDistance()     \
      mSERPeeWriteU8Bit(Dbk, GroupSensorCal2,  107 ,  7 ,  8 , 30, Delayed)
#define mSERReadU8BitEEP_StartDistanceDefaultValueDefault() ((U8)30)
#define mSERReadU8BitEEP_StartDistanceDefault() \
      mSERPeeReadU8Bit(Dbk, GroupSensorCal2,  107 ,  7 ,  8 , Delayed)
#define mSERWriteU8BitEEP_StartDistanceDelayed(ValueToWrite) \
      mSERPeeWriteU8Bit(Dbk, GroupSensorCal2,  107 ,  7 ,  8 , (ValueToWrite), Delayed)
#define mSERWriteU8BitEEP_StartDistanceImmediate(ValueToWrite) \
      mSERPeeWriteU8Bit(Dbk, GroupSensorCal2,  107 ,  7 ,  8 , (ValueToWrite), Immediate)
#define mSERWriteU8BitEEP_StartDistanceDefault(ValueToWrite) \
      mSERPeeWriteU8Bit(Dbk, GroupSensorCal2,  107 ,  7 ,  8 , (ValueToWrite), Immediate)

// EEP_HallType -- Group GroupSensorCal2, Byte  108  , Bit (MSB)  7  , SizeInBit  8 
#ifdef EEP_HallType
  #error "Do not define EEP_HallType, because this is a lexem used for concatenation."
#endif
#define cDATEEP_HallTypePositionByte      108 
#define cDATEEP_HallTypePositionBit        0xFF
#define mSERPeeResetU8BitEEP_HallType()     \
      mSERPeeWriteU8Bit(Dbk, GroupSensorCal2,  108 ,  7 ,  8 , 0, Delayed)
#define mSERReadU8BitEEP_HallTypeDefaultValueDefault() ((U8)0)
#define mSERReadU8BitEEP_HallTypeDefault() \
      mSERPeeReadU8Bit(Dbk, GroupSensorCal2,  108 ,  7 ,  8 , Delayed)
#define mSERWriteU8BitEEP_HallTypeDelayed(ValueToWrite) \
      mSERPeeWriteU8Bit(Dbk, GroupSensorCal2,  108 ,  7 ,  8 , (ValueToWrite), Delayed)
#define mSERWriteU8BitEEP_HallTypeImmediate(ValueToWrite) \
      mSERPeeWriteU8Bit(Dbk, GroupSensorCal2,  108 ,  7 ,  8 , (ValueToWrite), Immediate)
#define mSERWriteU8BitEEP_HallTypeDefault(ValueToWrite) \
      mSERPeeWriteU8Bit(Dbk, GroupSensorCal2,  108 ,  7 ,  8 , (ValueToWrite), Immediate)

// EEP_OpenGradeNum -- Group GroupSensorCal2, Byte  109  , Bit (MSB)  7  , SizeInBit  8 
#ifdef EEP_OpenGradeNum
  #error "Do not define EEP_OpenGradeNum, because this is a lexem used for concatenation."
#endif
#define cDATEEP_OpenGradeNumPositionByte      109 
#define cDATEEP_OpenGradeNumPositionBit        0xFF
#define mSERPeeResetU8BitEEP_OpenGradeNum()     \
      mSERPeeWriteU8Bit(Dbk, GroupSensorCal2,  109 ,  7 ,  8 , 10, Delayed)
#define mSERReadU8BitEEP_OpenGradeNumDefaultValueDefault() ((U8)10)
#define mSERReadU8BitEEP_OpenGradeNumDefault() \
      mSERPeeReadU8Bit(Dbk, GroupSensorCal2,  109 ,  7 ,  8 , Delayed)
#define mSERWriteU8BitEEP_OpenGradeNumDelayed(ValueToWrite) \
      mSERPeeWriteU8Bit(Dbk, GroupSensorCal2,  109 ,  7 ,  8 , (ValueToWrite), Delayed)
#define mSERWriteU8BitEEP_OpenGradeNumImmediate(ValueToWrite) \
      mSERPeeWriteU8Bit(Dbk, GroupSensorCal2,  109 ,  7 ,  8 , (ValueToWrite), Immediate)
#define mSERWriteU8BitEEP_OpenGradeNumDefault(ValueToWrite) \
      mSERPeeWriteU8Bit(Dbk, GroupSensorCal2,  109 ,  7 ,  8 , (ValueToWrite), Immediate)

// EEP_CloseGradeNum -- Group GroupSensorCal2, Byte  110  , Bit (MSB)  7  , SizeInBit  8 
#ifdef EEP_CloseGradeNum
  #error "Do not define EEP_CloseGradeNum, because this is a lexem used for concatenation."
#endif
#define cDATEEP_CloseGradeNumPositionByte      110 
#define cDATEEP_CloseGradeNumPositionBit        0xFF
#define mSERPeeResetU8BitEEP_CloseGradeNum()     \
      mSERPeeWriteU8Bit(Dbk, GroupSensorCal2,  110 ,  7 ,  8 , 10, Delayed)
#define mSERReadU8BitEEP_CloseGradeNumDefaultValueDefault() ((U8)10)
#define mSERReadU8BitEEP_CloseGradeNumDefault() \
      mSERPeeReadU8Bit(Dbk, GroupSensorCal2,  110 ,  7 ,  8 , Delayed)
#define mSERWriteU8BitEEP_CloseGradeNumDelayed(ValueToWrite) \
      mSERPeeWriteU8Bit(Dbk, GroupSensorCal2,  110 ,  7 ,  8 , (ValueToWrite), Delayed)
#define mSERWriteU8BitEEP_CloseGradeNumImmediate(ValueToWrite) \
      mSERPeeWriteU8Bit(Dbk, GroupSensorCal2,  110 ,  7 ,  8 , (ValueToWrite), Immediate)
#define mSERWriteU8BitEEP_CloseGradeNumDefault(ValueToWrite) \
      mSERPeeWriteU8Bit(Dbk, GroupSensorCal2,  110 ,  7 ,  8 , (ValueToWrite), Immediate)

// EEP_5kmphValid -- Group GroupSensorCal2, Byte  111  , Bit (MSB)  7  , SizeInBit  8 
#ifdef EEP_5kmphValid
  #error "Do not define EEP_5kmphValid, because this is a lexem used for concatenation."
#endif
#define cDATEEP_5kmphValidPositionByte      111 
#define cDATEEP_5kmphValidPositionBit        0xFF
#define mSERPeeResetU8BitEEP_5kmphValid()     \
      mSERPeeWriteU8Bit(Dbk, GroupSensorCal2,  111 ,  7 ,  8 , 0, Delayed)
#define mSERReadU8BitEEP_5kmphValidDefaultValueDefault() ((U8)0)
#define mSERReadU8BitEEP_5kmphValidDefault() \
      mSERPeeReadU8Bit(Dbk, GroupSensorCal2,  111 ,  7 ,  8 , Delayed)
#define mSERWriteU8BitEEP_5kmphValidDelayed(ValueToWrite) \
      mSERPeeWriteU8Bit(Dbk, GroupSensorCal2,  111 ,  7 ,  8 , (ValueToWrite), Delayed)
#define mSERWriteU8BitEEP_5kmphValidImmediate(ValueToWrite) \
      mSERPeeWriteU8Bit(Dbk, GroupSensorCal2,  111 ,  7 ,  8 , (ValueToWrite), Immediate)
#define mSERWriteU8BitEEP_5kmphValidDefault(ValueToWrite) \
      mSERPeeWriteU8Bit(Dbk, GroupSensorCal2,  111 ,  7 ,  8 , (ValueToWrite), Immediate)

// EEP_Study_Button_Flag -- Group GroupSensorCal2, Byte  112  , Bit (MSB)  7  , SizeInBit  8 
#ifdef EEP_Study_Button_Flag
  #error "Do not define EEP_Study_Button_Flag, because this is a lexem used for concatenation."
#endif
#define cDATEEP_Study_Button_FlagPositionByte      112 
#define cDATEEP_Study_Button_FlagPositionBit        0xFF
#define mSERPeeResetU8BitEEP_Study_Button_Flag()     \
      mSERPeeWriteU8Bit(Dbk, GroupSensorCal2,  112 ,  7 ,  8 , 0, Delayed)
#define mSERReadU8BitEEP_Study_Button_FlagDefaultValueDefault() ((U8)0)
#define mSERReadU8BitEEP_Study_Button_FlagDefault() \
      mSERPeeReadU8Bit(Dbk, GroupSensorCal2,  112 ,  7 ,  8 , Delayed)
#define mSERWriteU8BitEEP_Study_Button_FlagDelayed(ValueToWrite) \
      mSERPeeWriteU8Bit(Dbk, GroupSensorCal2,  112 ,  7 ,  8 , (ValueToWrite), Delayed)
#define mSERWriteU8BitEEP_Study_Button_FlagImmediate(ValueToWrite) \
      mSERPeeWriteU8Bit(Dbk, GroupSensorCal2,  112 ,  7 ,  8 , (ValueToWrite), Immediate)
#define mSERWriteU8BitEEP_Study_Button_FlagDefault(ValueToWrite) \
      mSERPeeWriteU8Bit(Dbk, GroupSensorCal2,  112 ,  7 ,  8 , (ValueToWrite), Immediate)

// EEP_Cancel_Button_Flag -- Group GroupSensorCal2, Byte  113  , Bit (MSB)  7  , SizeInBit  8 
#ifdef EEP_Cancel_Button_Flag
  #error "Do not define EEP_Cancel_Button_Flag, because this is a lexem used for concatenation."
#endif
#define cDATEEP_Cancel_Button_FlagPositionByte      113 
#define cDATEEP_Cancel_Button_FlagPositionBit        0xFF
#define mSERPeeResetU8BitEEP_Cancel_Button_Flag()     \
      mSERPeeWriteU8Bit(Dbk, GroupSensorCal2,  113 ,  7 ,  8 , 0, Delayed)
#define mSERReadU8BitEEP_Cancel_Button_FlagDefaultValueDefault() ((U8)0)
#define mSERReadU8BitEEP_Cancel_Button_FlagDefault() \
      mSERPeeReadU8Bit(Dbk, GroupSensorCal2,  113 ,  7 ,  8 , Delayed)
#define mSERWriteU8BitEEP_Cancel_Button_FlagDelayed(ValueToWrite) \
      mSERPeeWriteU8Bit(Dbk, GroupSensorCal2,  113 ,  7 ,  8 , (ValueToWrite), Delayed)
#define mSERWriteU8BitEEP_Cancel_Button_FlagImmediate(ValueToWrite) \
      mSERPeeWriteU8Bit(Dbk, GroupSensorCal2,  113 ,  7 ,  8 , (ValueToWrite), Immediate)
#define mSERWriteU8BitEEP_Cancel_Button_FlagDefault(ValueToWrite) \
      mSERPeeWriteU8Bit(Dbk, GroupSensorCal2,  113 ,  7 ,  8 , (ValueToWrite), Immediate)

// EEP_OpenPinchErr -- Group GroupSensorCal2, Byte  114  , Bit (MSB)  7  , SizeInBit  160 
#ifdef EEP_OpenPinchErr
  #error "Do not define EEP_OpenPinchErr, because this is a lexem used for concatenation."
#endif
#define mSERPeeResetEEP_OpenPinchErr()     \
{                                                     \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal2,  114 ,  0, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal2,  114 ,  1, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal2,  114 ,  2, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal2,  114 ,  3, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal2,  114 ,  4, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal2,  114 ,  5, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal2,  114 ,  6, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal2,  114 ,  7, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal2,  114 ,  8, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal2,  114 ,  9, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal2,  114 ,  10, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal2,  114 ,  11, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal2,  114 ,  12, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal2,  114 ,  13, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal2,  114 ,  14, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal2,  114 ,  15, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal2,  114 ,  16, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal2,  114 ,  17, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal2,  114 ,  18, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal2,  114 ,  19, 0, Delayed) \
}
#define mSERReadTableU1BitEEP_OpenPinchErrDefaultValueDefault( Index ) \
      mSERPeeReadDefaultTable(U1Bit,Dbk, GroupSensorCal2,  114 , Index, Delayed)

#define mSERReadTableU8BitEEP_OpenPinchErrDefault( Index ) \
      mSERPeeReadTable(U8Bit,Dbk, GroupSensorCal2,  114 , Index, Delayed)
#define mSERWriteTableU8BitEEP_OpenPinchErrDelayed( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Dbk, GroupSensorCal2,  114 , Index, (ValueToWrite), Delayed)
#define mSERWriteTableU8BitEEP_OpenPinchErrImmediate( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Dbk, GroupSensorCal2,  114 , Index, (ValueToWrite), Immediate)
#define mSERWriteTableU8BitEEP_OpenPinchErrDefault( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Dbk, GroupSensorCal2,  114 , Index, (ValueToWrite), Immediate)

// EEP_ClosePinchErr -- Group GroupSensorCal2, Byte  134  , Bit (MSB)  7  , SizeInBit  160 
#ifdef EEP_ClosePinchErr
  #error "Do not define EEP_ClosePinchErr, because this is a lexem used for concatenation."
#endif
#define mSERPeeResetEEP_ClosePinchErr()     \
{                                                     \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal2,  134 ,  0, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal2,  134 ,  1, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal2,  134 ,  2, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal2,  134 ,  3, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal2,  134 ,  4, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal2,  134 ,  5, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal2,  134 ,  6, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal2,  134 ,  7, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal2,  134 ,  8, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal2,  134 ,  9, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal2,  134 ,  10, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal2,  134 ,  11, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal2,  134 ,  12, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal2,  134 ,  13, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal2,  134 ,  14, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal2,  134 ,  15, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal2,  134 ,  16, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal2,  134 ,  17, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal2,  134 ,  18, 0, Delayed) \
   mSERPeeWriteTable(U8Bit,Dbk,GroupSensorCal2,  134 ,  19, 0, Delayed) \
}
#define mSERReadTableU1BitEEP_ClosePinchErrDefaultValueDefault( Index ) \
      mSERPeeReadDefaultTable(U1Bit,Dbk, GroupSensorCal2,  134 , Index, Delayed)

#define mSERReadTableU8BitEEP_ClosePinchErrDefault( Index ) \
      mSERPeeReadTable(U8Bit,Dbk, GroupSensorCal2,  134 , Index, Delayed)
#define mSERWriteTableU8BitEEP_ClosePinchErrDelayed( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Dbk, GroupSensorCal2,  134 , Index, (ValueToWrite), Delayed)
#define mSERWriteTableU8BitEEP_ClosePinchErrImmediate( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Dbk, GroupSensorCal2,  134 , Index, (ValueToWrite), Immediate)
#define mSERWriteTableU8BitEEP_ClosePinchErrDefault( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Dbk, GroupSensorCal2,  134 , Index, (ValueToWrite), Immediate)

// EEP_ErrOpenNum -- Group GroupSensorCal2, Byte  154  , Bit (MSB)  7  , SizeInBit  8 
#ifdef EEP_ErrOpenNum
  #error "Do not define EEP_ErrOpenNum, because this is a lexem used for concatenation."
#endif
#define cDATEEP_ErrOpenNumPositionByte      154 
#define cDATEEP_ErrOpenNumPositionBit        0xFF
#define mSERPeeResetU8BitEEP_ErrOpenNum()     \
      mSERPeeWriteU8Bit(Dbk, GroupSensorCal2,  154 ,  7 ,  8 , 0, Delayed)
#define mSERReadU8BitEEP_ErrOpenNumDefaultValueDefault() ((U8)0)
#define mSERReadU8BitEEP_ErrOpenNumDefault() \
      mSERPeeReadU8Bit(Dbk, GroupSensorCal2,  154 ,  7 ,  8 , Delayed)
#define mSERWriteU8BitEEP_ErrOpenNumDelayed(ValueToWrite) \
      mSERPeeWriteU8Bit(Dbk, GroupSensorCal2,  154 ,  7 ,  8 , (ValueToWrite), Delayed)
#define mSERWriteU8BitEEP_ErrOpenNumImmediate(ValueToWrite) \
      mSERPeeWriteU8Bit(Dbk, GroupSensorCal2,  154 ,  7 ,  8 , (ValueToWrite), Immediate)
#define mSERWriteU8BitEEP_ErrOpenNumDefault(ValueToWrite) \
      mSERPeeWriteU8Bit(Dbk, GroupSensorCal2,  154 ,  7 ,  8 , (ValueToWrite), Immediate)

// Self_LearnData -- Group GroupSensorCal2, Byte  155  , Bit (MSB)  7  , SizeInBit  8 
#ifdef Self_LearnData
  #error "Do not define Self_LearnData, because this is a lexem used for concatenation."
#endif
#define cDATSelf_LearnDataPositionByte      155 
#define cDATSelf_LearnDataPositionBit        0xFF
#define mSERPeeResetU8BitSelf_LearnData()     \
      mSERPeeWriteU8Bit(Dbk, GroupSensorCal2,  155 ,  7 ,  8 , 0, Delayed)
#define mSERReadU8BitSelf_LearnDataDefaultValueDefault() ((U8)0)
#define mSERReadU8BitSelf_LearnDataDefault() \
      mSERPeeReadU8Bit(Dbk, GroupSensorCal2,  155 ,  7 ,  8 , Delayed)
#define mSERWriteU8BitSelf_LearnDataDelayed(ValueToWrite) \
      mSERPeeWriteU8Bit(Dbk, GroupSensorCal2,  155 ,  7 ,  8 , (ValueToWrite), Delayed)
#define mSERWriteU8BitSelf_LearnDataImmediate(ValueToWrite) \
      mSERPeeWriteU8Bit(Dbk, GroupSensorCal2,  155 ,  7 ,  8 , (ValueToWrite), Immediate)
#define mSERWriteU8BitSelf_LearnDataDefault(ValueToWrite) \
      mSERPeeWriteU8Bit(Dbk, GroupSensorCal2,  155 ,  7 ,  8 , (ValueToWrite), Immediate)

// EEP_EEInitEndFlag -- Group GroupSensorCal2, Byte  156  , Bit (MSB)  7  , SizeInBit  8 
#ifdef EEP_EEInitEndFlag
  #error "Do not define EEP_EEInitEndFlag, because this is a lexem used for concatenation."
#endif
#define cDATEEP_EEInitEndFlagPositionByte      156 
#define cDATEEP_EEInitEndFlagPositionBit        0xFF
#define mSERPeeResetU8BitEEP_EEInitEndFlag()     \
      mSERPeeWriteU8Bit(Dbk, GroupSensorCal2,  156 ,  7 ,  8 , 0, Delayed)
#define mSERReadU8BitEEP_EEInitEndFlagDefaultValueDefault() ((U8)0)
#define mSERReadU8BitEEP_EEInitEndFlagDefault() \
      mSERPeeReadU8Bit(Dbk, GroupSensorCal2,  156 ,  7 ,  8 , Delayed)
#define mSERWriteU8BitEEP_EEInitEndFlagDelayed(ValueToWrite) \
      mSERPeeWriteU8Bit(Dbk, GroupSensorCal2,  156 ,  7 ,  8 , (ValueToWrite), Delayed)
#define mSERWriteU8BitEEP_EEInitEndFlagImmediate(ValueToWrite) \
      mSERPeeWriteU8Bit(Dbk, GroupSensorCal2,  156 ,  7 ,  8 , (ValueToWrite), Immediate)
#define mSERWriteU8BitEEP_EEInitEndFlagDefault(ValueToWrite) \
      mSERPeeWriteU8Bit(Dbk, GroupSensorCal2,  156 ,  7 ,  8 , (ValueToWrite), Immediate)

// EEP_ResetTimes_Total -- Group GroupReset, Byte  0  , Bit (MSB)  7  , SizeInBit  8 
#ifdef EEP_ResetTimes_Total
  #error "Do not define EEP_ResetTimes_Total, because this is a lexem used for concatenation."
#endif
#define cDATEEP_ResetTimes_TotalPositionByte      0 
#define cDATEEP_ResetTimes_TotalPositionBit        0xFF
#define mSERPeeResetU8BitEEP_ResetTimes_Total()     \
      mSERPeeWriteU8Bit(Sbk, GroupReset,  0 ,  7 ,  8 , 0, Delayed)
#define mSERReadU8BitEEP_ResetTimes_TotalDefaultValueDefault() ((U8)0)
#define mSERReadU8BitEEP_ResetTimes_TotalDefault() \
      mSERPeeReadU8Bit(Sbk, GroupReset,  0 ,  7 ,  8 , Delayed)
#define mSERWriteU8BitEEP_ResetTimes_TotalDelayed(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupReset,  0 ,  7 ,  8 , (ValueToWrite), Delayed)
#define mSERWriteU8BitEEP_ResetTimes_TotalImmediate(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupReset,  0 ,  7 ,  8 , (ValueToWrite), Immediate)
#define mSERWriteU8BitEEP_ResetTimes_TotalDefault(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupReset,  0 ,  7 ,  8 , (ValueToWrite), Immediate)

// EEP_ResetTimes_PwrExt -- Group GroupReset, Byte  1  , Bit (MSB)  7  , SizeInBit  8 
#ifdef EEP_ResetTimes_PwrExt
  #error "Do not define EEP_ResetTimes_PwrExt, because this is a lexem used for concatenation."
#endif
#define cDATEEP_ResetTimes_PwrExtPositionByte      1 
#define cDATEEP_ResetTimes_PwrExtPositionBit        0xFF
#define mSERPeeResetU8BitEEP_ResetTimes_PwrExt()     \
      mSERPeeWriteU8Bit(Sbk, GroupReset,  1 ,  7 ,  8 , 0, Delayed)
#define mSERReadU8BitEEP_ResetTimes_PwrExtDefaultValueDefault() ((U8)0)
#define mSERReadU8BitEEP_ResetTimes_PwrExtDefault() \
      mSERPeeReadU8Bit(Sbk, GroupReset,  1 ,  7 ,  8 , Delayed)
#define mSERWriteU8BitEEP_ResetTimes_PwrExtDelayed(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupReset,  1 ,  7 ,  8 , (ValueToWrite), Delayed)
#define mSERWriteU8BitEEP_ResetTimes_PwrExtImmediate(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupReset,  1 ,  7 ,  8 , (ValueToWrite), Immediate)
#define mSERWriteU8BitEEP_ResetTimes_PwrExtDefault(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupReset,  1 ,  7 ,  8 , (ValueToWrite), Immediate)

// EEP_ResetTimes_WatchDog -- Group GroupReset, Byte  2  , Bit (MSB)  7  , SizeInBit  8 
#ifdef EEP_ResetTimes_WatchDog
  #error "Do not define EEP_ResetTimes_WatchDog, because this is a lexem used for concatenation."
#endif
#define cDATEEP_ResetTimes_WatchDogPositionByte      2 
#define cDATEEP_ResetTimes_WatchDogPositionBit        0xFF
#define mSERPeeResetU8BitEEP_ResetTimes_WatchDog()     \
      mSERPeeWriteU8Bit(Sbk, GroupReset,  2 ,  7 ,  8 , 0, Delayed)
#define mSERReadU8BitEEP_ResetTimes_WatchDogDefaultValueDefault() ((U8)0)
#define mSERReadU8BitEEP_ResetTimes_WatchDogDefault() \
      mSERPeeReadU8Bit(Sbk, GroupReset,  2 ,  7 ,  8 , Delayed)
#define mSERWriteU8BitEEP_ResetTimes_WatchDogDelayed(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupReset,  2 ,  7 ,  8 , (ValueToWrite), Delayed)
#define mSERWriteU8BitEEP_ResetTimes_WatchDogImmediate(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupReset,  2 ,  7 ,  8 , (ValueToWrite), Immediate)
#define mSERWriteU8BitEEP_ResetTimes_WatchDogDefault(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupReset,  2 ,  7 ,  8 , (ValueToWrite), Immediate)

// EEP_ResetTimes_SWReset -- Group GroupReset, Byte  3  , Bit (MSB)  7  , SizeInBit  8 
#ifdef EEP_ResetTimes_SWReset
  #error "Do not define EEP_ResetTimes_SWReset, because this is a lexem used for concatenation."
#endif
#define cDATEEP_ResetTimes_SWResetPositionByte      3 
#define cDATEEP_ResetTimes_SWResetPositionBit        0xFF
#define mSERPeeResetU8BitEEP_ResetTimes_SWReset()     \
      mSERPeeWriteU8Bit(Sbk, GroupReset,  3 ,  7 ,  8 , 0, Delayed)
#define mSERReadU8BitEEP_ResetTimes_SWResetDefaultValueDefault() ((U8)0)
#define mSERReadU8BitEEP_ResetTimes_SWResetDefault() \
      mSERPeeReadU8Bit(Sbk, GroupReset,  3 ,  7 ,  8 , Delayed)
#define mSERWriteU8BitEEP_ResetTimes_SWResetDelayed(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupReset,  3 ,  7 ,  8 , (ValueToWrite), Delayed)
#define mSERWriteU8BitEEP_ResetTimes_SWResetImmediate(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupReset,  3 ,  7 ,  8 , (ValueToWrite), Immediate)
#define mSERWriteU8BitEEP_ResetTimes_SWResetDefault(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupReset,  3 ,  7 ,  8 , (ValueToWrite), Immediate)

// EEP_ResetTimes_CLK -- Group GroupReset, Byte  4  , Bit (MSB)  7  , SizeInBit  8 
#ifdef EEP_ResetTimes_CLK
  #error "Do not define EEP_ResetTimes_CLK, because this is a lexem used for concatenation."
#endif
#define cDATEEP_ResetTimes_CLKPositionByte      4 
#define cDATEEP_ResetTimes_CLKPositionBit        0xFF
#define mSERPeeResetU8BitEEP_ResetTimes_CLK()     \
      mSERPeeWriteU8Bit(Sbk, GroupReset,  4 ,  7 ,  8 , 0, Delayed)
#define mSERReadU8BitEEP_ResetTimes_CLKDefaultValueDefault() ((U8)0)
#define mSERReadU8BitEEP_ResetTimes_CLKDefault() \
      mSERPeeReadU8Bit(Sbk, GroupReset,  4 ,  7 ,  8 , Delayed)
#define mSERWriteU8BitEEP_ResetTimes_CLKDelayed(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupReset,  4 ,  7 ,  8 , (ValueToWrite), Delayed)
#define mSERWriteU8BitEEP_ResetTimes_CLKImmediate(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupReset,  4 ,  7 ,  8 , (ValueToWrite), Immediate)
#define mSERWriteU8BitEEP_ResetTimes_CLKDefault(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupReset,  4 ,  7 ,  8 , (ValueToWrite), Immediate)

// EEP_SbkReadOnly1_0 -- Group GroupSbkReadOnly1, Byte  0  , Bit (MSB)  7  , SizeInBit  32 
#ifdef EEP_SbkReadOnly1_0
  #error "Do not define EEP_SbkReadOnly1_0, because this is a lexem used for concatenation."
#endif
#define cDATEEP_SbkReadOnly1_0PositionByte      0 
#define cDATEEP_SbkReadOnly1_0PositionBit        0xFF
#define mSERPeeResetU32BitEEP_SbkReadOnly1_0()     \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  0 ,  7 ,  32 , 0, Delayed)
#define mSERReadU32BitEEP_SbkReadOnly1_0DefaultValueDefault() ((U32)0)
#define mSERReadU32BitEEP_SbkReadOnly1_0Default() \
      mSERPeeReadU32Bit(Sbk, GroupSbkReadOnly1,  0 ,  7 ,  32 , Delayed)
#define mSERWriteU32BitEEP_SbkReadOnly1_0Delayed(ValueToWrite) \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  0 ,  7 ,  32 , (ValueToWrite), Delayed)
#define mSERWriteU32BitEEP_SbkReadOnly1_0Immediate(ValueToWrite) \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  0 ,  7 ,  32 , (ValueToWrite), Immediate)
#define mSERWriteU32BitEEP_SbkReadOnly1_0Default(ValueToWrite) \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  0 ,  7 ,  32 , (ValueToWrite), Immediate)

// EEP_SbkReadOnly1_1 -- Group GroupSbkReadOnly1, Byte  4  , Bit (MSB)  7  , SizeInBit  32 
#ifdef EEP_SbkReadOnly1_1
  #error "Do not define EEP_SbkReadOnly1_1, because this is a lexem used for concatenation."
#endif
#define cDATEEP_SbkReadOnly1_1PositionByte      4 
#define cDATEEP_SbkReadOnly1_1PositionBit        0xFF
#define mSERPeeResetU32BitEEP_SbkReadOnly1_1()     \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  4 ,  7 ,  32 , 0, Delayed)
#define mSERReadU32BitEEP_SbkReadOnly1_1DefaultValueDefault() ((U32)0)
#define mSERReadU32BitEEP_SbkReadOnly1_1Default() \
      mSERPeeReadU32Bit(Sbk, GroupSbkReadOnly1,  4 ,  7 ,  32 , Delayed)
#define mSERWriteU32BitEEP_SbkReadOnly1_1Delayed(ValueToWrite) \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  4 ,  7 ,  32 , (ValueToWrite), Delayed)
#define mSERWriteU32BitEEP_SbkReadOnly1_1Immediate(ValueToWrite) \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  4 ,  7 ,  32 , (ValueToWrite), Immediate)
#define mSERWriteU32BitEEP_SbkReadOnly1_1Default(ValueToWrite) \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  4 ,  7 ,  32 , (ValueToWrite), Immediate)

// EEP_SbkReadOnly1_2 -- Group GroupSbkReadOnly1, Byte  8  , Bit (MSB)  7  , SizeInBit  32 
#ifdef EEP_SbkReadOnly1_2
  #error "Do not define EEP_SbkReadOnly1_2, because this is a lexem used for concatenation."
#endif
#define cDATEEP_SbkReadOnly1_2PositionByte      8 
#define cDATEEP_SbkReadOnly1_2PositionBit        0xFF
#define mSERPeeResetU32BitEEP_SbkReadOnly1_2()     \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  8 ,  7 ,  32 , 0, Delayed)
#define mSERReadU32BitEEP_SbkReadOnly1_2DefaultValueDefault() ((U32)0)
#define mSERReadU32BitEEP_SbkReadOnly1_2Default() \
      mSERPeeReadU32Bit(Sbk, GroupSbkReadOnly1,  8 ,  7 ,  32 , Delayed)
#define mSERWriteU32BitEEP_SbkReadOnly1_2Delayed(ValueToWrite) \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  8 ,  7 ,  32 , (ValueToWrite), Delayed)
#define mSERWriteU32BitEEP_SbkReadOnly1_2Immediate(ValueToWrite) \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  8 ,  7 ,  32 , (ValueToWrite), Immediate)
#define mSERWriteU32BitEEP_SbkReadOnly1_2Default(ValueToWrite) \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  8 ,  7 ,  32 , (ValueToWrite), Immediate)

// EEP_SbkReadOnly1_3 -- Group GroupSbkReadOnly1, Byte  12  , Bit (MSB)  7  , SizeInBit  32 
#ifdef EEP_SbkReadOnly1_3
  #error "Do not define EEP_SbkReadOnly1_3, because this is a lexem used for concatenation."
#endif
#define cDATEEP_SbkReadOnly1_3PositionByte      12 
#define cDATEEP_SbkReadOnly1_3PositionBit        0xFF
#define mSERPeeResetU32BitEEP_SbkReadOnly1_3()     \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  12 ,  7 ,  32 , 0, Delayed)
#define mSERReadU32BitEEP_SbkReadOnly1_3DefaultValueDefault() ((U32)0)
#define mSERReadU32BitEEP_SbkReadOnly1_3Default() \
      mSERPeeReadU32Bit(Sbk, GroupSbkReadOnly1,  12 ,  7 ,  32 , Delayed)
#define mSERWriteU32BitEEP_SbkReadOnly1_3Delayed(ValueToWrite) \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  12 ,  7 ,  32 , (ValueToWrite), Delayed)
#define mSERWriteU32BitEEP_SbkReadOnly1_3Immediate(ValueToWrite) \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  12 ,  7 ,  32 , (ValueToWrite), Immediate)
#define mSERWriteU32BitEEP_SbkReadOnly1_3Default(ValueToWrite) \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  12 ,  7 ,  32 , (ValueToWrite), Immediate)

// EEP_SbkReadOnly1_4 -- Group GroupSbkReadOnly1, Byte  16  , Bit (MSB)  7  , SizeInBit  32 
#ifdef EEP_SbkReadOnly1_4
  #error "Do not define EEP_SbkReadOnly1_4, because this is a lexem used for concatenation."
#endif
#define cDATEEP_SbkReadOnly1_4PositionByte      16 
#define cDATEEP_SbkReadOnly1_4PositionBit        0xFF
#define mSERPeeResetU32BitEEP_SbkReadOnly1_4()     \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  16 ,  7 ,  32 , 0, Delayed)
#define mSERReadU32BitEEP_SbkReadOnly1_4DefaultValueDefault() ((U32)0)
#define mSERReadU32BitEEP_SbkReadOnly1_4Default() \
      mSERPeeReadU32Bit(Sbk, GroupSbkReadOnly1,  16 ,  7 ,  32 , Delayed)
#define mSERWriteU32BitEEP_SbkReadOnly1_4Delayed(ValueToWrite) \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  16 ,  7 ,  32 , (ValueToWrite), Delayed)
#define mSERWriteU32BitEEP_SbkReadOnly1_4Immediate(ValueToWrite) \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  16 ,  7 ,  32 , (ValueToWrite), Immediate)
#define mSERWriteU32BitEEP_SbkReadOnly1_4Default(ValueToWrite) \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  16 ,  7 ,  32 , (ValueToWrite), Immediate)

// EEP_SbkReadOnly1_5 -- Group GroupSbkReadOnly1, Byte  20  , Bit (MSB)  7  , SizeInBit  32 
#ifdef EEP_SbkReadOnly1_5
  #error "Do not define EEP_SbkReadOnly1_5, because this is a lexem used for concatenation."
#endif
#define cDATEEP_SbkReadOnly1_5PositionByte      20 
#define cDATEEP_SbkReadOnly1_5PositionBit        0xFF
#define mSERPeeResetU32BitEEP_SbkReadOnly1_5()     \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  20 ,  7 ,  32 , 0, Delayed)
#define mSERReadU32BitEEP_SbkReadOnly1_5DefaultValueDefault() ((U32)0)
#define mSERReadU32BitEEP_SbkReadOnly1_5Default() \
      mSERPeeReadU32Bit(Sbk, GroupSbkReadOnly1,  20 ,  7 ,  32 , Delayed)
#define mSERWriteU32BitEEP_SbkReadOnly1_5Delayed(ValueToWrite) \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  20 ,  7 ,  32 , (ValueToWrite), Delayed)
#define mSERWriteU32BitEEP_SbkReadOnly1_5Immediate(ValueToWrite) \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  20 ,  7 ,  32 , (ValueToWrite), Immediate)
#define mSERWriteU32BitEEP_SbkReadOnly1_5Default(ValueToWrite) \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  20 ,  7 ,  32 , (ValueToWrite), Immediate)

// EEP_SbkReadOnly1_6 -- Group GroupSbkReadOnly1, Byte  24  , Bit (MSB)  7  , SizeInBit  32 
#ifdef EEP_SbkReadOnly1_6
  #error "Do not define EEP_SbkReadOnly1_6, because this is a lexem used for concatenation."
#endif
#define cDATEEP_SbkReadOnly1_6PositionByte      24 
#define cDATEEP_SbkReadOnly1_6PositionBit        0xFF
#define mSERPeeResetU32BitEEP_SbkReadOnly1_6()     \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  24 ,  7 ,  32 , 0, Delayed)
#define mSERReadU32BitEEP_SbkReadOnly1_6DefaultValueDefault() ((U32)0)
#define mSERReadU32BitEEP_SbkReadOnly1_6Default() \
      mSERPeeReadU32Bit(Sbk, GroupSbkReadOnly1,  24 ,  7 ,  32 , Delayed)
#define mSERWriteU32BitEEP_SbkReadOnly1_6Delayed(ValueToWrite) \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  24 ,  7 ,  32 , (ValueToWrite), Delayed)
#define mSERWriteU32BitEEP_SbkReadOnly1_6Immediate(ValueToWrite) \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  24 ,  7 ,  32 , (ValueToWrite), Immediate)
#define mSERWriteU32BitEEP_SbkReadOnly1_6Default(ValueToWrite) \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  24 ,  7 ,  32 , (ValueToWrite), Immediate)

// EEP_SbkReadOnly1_7 -- Group GroupSbkReadOnly1, Byte  28  , Bit (MSB)  7  , SizeInBit  32 
#ifdef EEP_SbkReadOnly1_7
  #error "Do not define EEP_SbkReadOnly1_7, because this is a lexem used for concatenation."
#endif
#define cDATEEP_SbkReadOnly1_7PositionByte      28 
#define cDATEEP_SbkReadOnly1_7PositionBit        0xFF
#define mSERPeeResetU32BitEEP_SbkReadOnly1_7()     \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  28 ,  7 ,  32 , 0, Delayed)
#define mSERReadU32BitEEP_SbkReadOnly1_7DefaultValueDefault() ((U32)0)
#define mSERReadU32BitEEP_SbkReadOnly1_7Default() \
      mSERPeeReadU32Bit(Sbk, GroupSbkReadOnly1,  28 ,  7 ,  32 , Delayed)
#define mSERWriteU32BitEEP_SbkReadOnly1_7Delayed(ValueToWrite) \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  28 ,  7 ,  32 , (ValueToWrite), Delayed)
#define mSERWriteU32BitEEP_SbkReadOnly1_7Immediate(ValueToWrite) \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  28 ,  7 ,  32 , (ValueToWrite), Immediate)
#define mSERWriteU32BitEEP_SbkReadOnly1_7Default(ValueToWrite) \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  28 ,  7 ,  32 , (ValueToWrite), Immediate)

// EEP_SbkReadOnly1_8 -- Group GroupSbkReadOnly1, Byte  32  , Bit (MSB)  7  , SizeInBit  32 
#ifdef EEP_SbkReadOnly1_8
  #error "Do not define EEP_SbkReadOnly1_8, because this is a lexem used for concatenation."
#endif
#define cDATEEP_SbkReadOnly1_8PositionByte      32 
#define cDATEEP_SbkReadOnly1_8PositionBit        0xFF
#define mSERPeeResetU32BitEEP_SbkReadOnly1_8()     \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  32 ,  7 ,  32 , 0, Delayed)
#define mSERReadU32BitEEP_SbkReadOnly1_8DefaultValueDefault() ((U32)0)
#define mSERReadU32BitEEP_SbkReadOnly1_8Default() \
      mSERPeeReadU32Bit(Sbk, GroupSbkReadOnly1,  32 ,  7 ,  32 , Delayed)
#define mSERWriteU32BitEEP_SbkReadOnly1_8Delayed(ValueToWrite) \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  32 ,  7 ,  32 , (ValueToWrite), Delayed)
#define mSERWriteU32BitEEP_SbkReadOnly1_8Immediate(ValueToWrite) \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  32 ,  7 ,  32 , (ValueToWrite), Immediate)
#define mSERWriteU32BitEEP_SbkReadOnly1_8Default(ValueToWrite) \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  32 ,  7 ,  32 , (ValueToWrite), Immediate)

// EEP_SbkReadOnly1_9 -- Group GroupSbkReadOnly1, Byte  36  , Bit (MSB)  7  , SizeInBit  32 
#ifdef EEP_SbkReadOnly1_9
  #error "Do not define EEP_SbkReadOnly1_9, because this is a lexem used for concatenation."
#endif
#define cDATEEP_SbkReadOnly1_9PositionByte      36 
#define cDATEEP_SbkReadOnly1_9PositionBit        0xFF
#define mSERPeeResetU32BitEEP_SbkReadOnly1_9()     \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  36 ,  7 ,  32 , 0, Delayed)
#define mSERReadU32BitEEP_SbkReadOnly1_9DefaultValueDefault() ((U32)0)
#define mSERReadU32BitEEP_SbkReadOnly1_9Default() \
      mSERPeeReadU32Bit(Sbk, GroupSbkReadOnly1,  36 ,  7 ,  32 , Delayed)
#define mSERWriteU32BitEEP_SbkReadOnly1_9Delayed(ValueToWrite) \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  36 ,  7 ,  32 , (ValueToWrite), Delayed)
#define mSERWriteU32BitEEP_SbkReadOnly1_9Immediate(ValueToWrite) \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  36 ,  7 ,  32 , (ValueToWrite), Immediate)
#define mSERWriteU32BitEEP_SbkReadOnly1_9Default(ValueToWrite) \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  36 ,  7 ,  32 , (ValueToWrite), Immediate)

// EEP_SbkReadOnly1_10 -- Group GroupSbkReadOnly1, Byte  40  , Bit (MSB)  7  , SizeInBit  32 
#ifdef EEP_SbkReadOnly1_10
  #error "Do not define EEP_SbkReadOnly1_10, because this is a lexem used for concatenation."
#endif
#define cDATEEP_SbkReadOnly1_10PositionByte      40 
#define cDATEEP_SbkReadOnly1_10PositionBit        0xFF
#define mSERPeeResetU32BitEEP_SbkReadOnly1_10()     \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  40 ,  7 ,  32 , 0, Delayed)
#define mSERReadU32BitEEP_SbkReadOnly1_10DefaultValueDefault() ((U32)0)
#define mSERReadU32BitEEP_SbkReadOnly1_10Default() \
      mSERPeeReadU32Bit(Sbk, GroupSbkReadOnly1,  40 ,  7 ,  32 , Delayed)
#define mSERWriteU32BitEEP_SbkReadOnly1_10Delayed(ValueToWrite) \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  40 ,  7 ,  32 , (ValueToWrite), Delayed)
#define mSERWriteU32BitEEP_SbkReadOnly1_10Immediate(ValueToWrite) \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  40 ,  7 ,  32 , (ValueToWrite), Immediate)
#define mSERWriteU32BitEEP_SbkReadOnly1_10Default(ValueToWrite) \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  40 ,  7 ,  32 , (ValueToWrite), Immediate)

// EEP_SbkReadOnly1_11 -- Group GroupSbkReadOnly1, Byte  44  , Bit (MSB)  7  , SizeInBit  32 
#ifdef EEP_SbkReadOnly1_11
  #error "Do not define EEP_SbkReadOnly1_11, because this is a lexem used for concatenation."
#endif
#define cDATEEP_SbkReadOnly1_11PositionByte      44 
#define cDATEEP_SbkReadOnly1_11PositionBit        0xFF
#define mSERPeeResetU32BitEEP_SbkReadOnly1_11()     \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  44 ,  7 ,  32 , 0, Delayed)
#define mSERReadU32BitEEP_SbkReadOnly1_11DefaultValueDefault() ((U32)0)
#define mSERReadU32BitEEP_SbkReadOnly1_11Default() \
      mSERPeeReadU32Bit(Sbk, GroupSbkReadOnly1,  44 ,  7 ,  32 , Delayed)
#define mSERWriteU32BitEEP_SbkReadOnly1_11Delayed(ValueToWrite) \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  44 ,  7 ,  32 , (ValueToWrite), Delayed)
#define mSERWriteU32BitEEP_SbkReadOnly1_11Immediate(ValueToWrite) \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  44 ,  7 ,  32 , (ValueToWrite), Immediate)
#define mSERWriteU32BitEEP_SbkReadOnly1_11Default(ValueToWrite) \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  44 ,  7 ,  32 , (ValueToWrite), Immediate)

// EEP_SbkReadOnly1_12 -- Group GroupSbkReadOnly1, Byte  48  , Bit (MSB)  7  , SizeInBit  32 
#ifdef EEP_SbkReadOnly1_12
  #error "Do not define EEP_SbkReadOnly1_12, because this is a lexem used for concatenation."
#endif
#define cDATEEP_SbkReadOnly1_12PositionByte      48 
#define cDATEEP_SbkReadOnly1_12PositionBit        0xFF
#define mSERPeeResetU32BitEEP_SbkReadOnly1_12()     \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  48 ,  7 ,  32 , 0, Delayed)
#define mSERReadU32BitEEP_SbkReadOnly1_12DefaultValueDefault() ((U32)0)
#define mSERReadU32BitEEP_SbkReadOnly1_12Default() \
      mSERPeeReadU32Bit(Sbk, GroupSbkReadOnly1,  48 ,  7 ,  32 , Delayed)
#define mSERWriteU32BitEEP_SbkReadOnly1_12Delayed(ValueToWrite) \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  48 ,  7 ,  32 , (ValueToWrite), Delayed)
#define mSERWriteU32BitEEP_SbkReadOnly1_12Immediate(ValueToWrite) \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  48 ,  7 ,  32 , (ValueToWrite), Immediate)
#define mSERWriteU32BitEEP_SbkReadOnly1_12Default(ValueToWrite) \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  48 ,  7 ,  32 , (ValueToWrite), Immediate)

// EEP_SbkReadOnly1_13 -- Group GroupSbkReadOnly1, Byte  52  , Bit (MSB)  7  , SizeInBit  32 
#ifdef EEP_SbkReadOnly1_13
  #error "Do not define EEP_SbkReadOnly1_13, because this is a lexem used for concatenation."
#endif
#define cDATEEP_SbkReadOnly1_13PositionByte      52 
#define cDATEEP_SbkReadOnly1_13PositionBit        0xFF
#define mSERPeeResetU32BitEEP_SbkReadOnly1_13()     \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  52 ,  7 ,  32 , 0, Delayed)
#define mSERReadU32BitEEP_SbkReadOnly1_13DefaultValueDefault() ((U32)0)
#define mSERReadU32BitEEP_SbkReadOnly1_13Default() \
      mSERPeeReadU32Bit(Sbk, GroupSbkReadOnly1,  52 ,  7 ,  32 , Delayed)
#define mSERWriteU32BitEEP_SbkReadOnly1_13Delayed(ValueToWrite) \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  52 ,  7 ,  32 , (ValueToWrite), Delayed)
#define mSERWriteU32BitEEP_SbkReadOnly1_13Immediate(ValueToWrite) \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  52 ,  7 ,  32 , (ValueToWrite), Immediate)
#define mSERWriteU32BitEEP_SbkReadOnly1_13Default(ValueToWrite) \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  52 ,  7 ,  32 , (ValueToWrite), Immediate)

// EEP_SbkReadOnly1_14 -- Group GroupSbkReadOnly1, Byte  56  , Bit (MSB)  7  , SizeInBit  32 
#ifdef EEP_SbkReadOnly1_14
  #error "Do not define EEP_SbkReadOnly1_14, because this is a lexem used for concatenation."
#endif
#define cDATEEP_SbkReadOnly1_14PositionByte      56 
#define cDATEEP_SbkReadOnly1_14PositionBit        0xFF
#define mSERPeeResetU32BitEEP_SbkReadOnly1_14()     \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  56 ,  7 ,  32 , 0, Delayed)
#define mSERReadU32BitEEP_SbkReadOnly1_14DefaultValueDefault() ((U32)0)
#define mSERReadU32BitEEP_SbkReadOnly1_14Default() \
      mSERPeeReadU32Bit(Sbk, GroupSbkReadOnly1,  56 ,  7 ,  32 , Delayed)
#define mSERWriteU32BitEEP_SbkReadOnly1_14Delayed(ValueToWrite) \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  56 ,  7 ,  32 , (ValueToWrite), Delayed)
#define mSERWriteU32BitEEP_SbkReadOnly1_14Immediate(ValueToWrite) \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  56 ,  7 ,  32 , (ValueToWrite), Immediate)
#define mSERWriteU32BitEEP_SbkReadOnly1_14Default(ValueToWrite) \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  56 ,  7 ,  32 , (ValueToWrite), Immediate)

// EEP_SbkReadOnly1_15 -- Group GroupSbkReadOnly1, Byte  60  , Bit (MSB)  7  , SizeInBit  32 
#ifdef EEP_SbkReadOnly1_15
  #error "Do not define EEP_SbkReadOnly1_15, because this is a lexem used for concatenation."
#endif
#define cDATEEP_SbkReadOnly1_15PositionByte      60 
#define cDATEEP_SbkReadOnly1_15PositionBit        0xFF
#define mSERPeeResetU32BitEEP_SbkReadOnly1_15()     \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  60 ,  7 ,  32 , 0, Delayed)
#define mSERReadU32BitEEP_SbkReadOnly1_15DefaultValueDefault() ((U32)0)
#define mSERReadU32BitEEP_SbkReadOnly1_15Default() \
      mSERPeeReadU32Bit(Sbk, GroupSbkReadOnly1,  60 ,  7 ,  32 , Delayed)
#define mSERWriteU32BitEEP_SbkReadOnly1_15Delayed(ValueToWrite) \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  60 ,  7 ,  32 , (ValueToWrite), Delayed)
#define mSERWriteU32BitEEP_SbkReadOnly1_15Immediate(ValueToWrite) \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  60 ,  7 ,  32 , (ValueToWrite), Immediate)
#define mSERWriteU32BitEEP_SbkReadOnly1_15Default(ValueToWrite) \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  60 ,  7 ,  32 , (ValueToWrite), Immediate)

// EEP_SbkReadOnly1_16 -- Group GroupSbkReadOnly1, Byte  64  , Bit (MSB)  7  , SizeInBit  32 
#ifdef EEP_SbkReadOnly1_16
  #error "Do not define EEP_SbkReadOnly1_16, because this is a lexem used for concatenation."
#endif
#define cDATEEP_SbkReadOnly1_16PositionByte      64 
#define cDATEEP_SbkReadOnly1_16PositionBit        0xFF
#define mSERPeeResetU32BitEEP_SbkReadOnly1_16()     \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  64 ,  7 ,  32 , 0, Delayed)
#define mSERReadU32BitEEP_SbkReadOnly1_16DefaultValueDefault() ((U32)0)
#define mSERReadU32BitEEP_SbkReadOnly1_16Default() \
      mSERPeeReadU32Bit(Sbk, GroupSbkReadOnly1,  64 ,  7 ,  32 , Delayed)
#define mSERWriteU32BitEEP_SbkReadOnly1_16Delayed(ValueToWrite) \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  64 ,  7 ,  32 , (ValueToWrite), Delayed)
#define mSERWriteU32BitEEP_SbkReadOnly1_16Immediate(ValueToWrite) \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  64 ,  7 ,  32 , (ValueToWrite), Immediate)
#define mSERWriteU32BitEEP_SbkReadOnly1_16Default(ValueToWrite) \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  64 ,  7 ,  32 , (ValueToWrite), Immediate)

// EEP_SbkReadOnly1_17 -- Group GroupSbkReadOnly1, Byte  68  , Bit (MSB)  7  , SizeInBit  32 
#ifdef EEP_SbkReadOnly1_17
  #error "Do not define EEP_SbkReadOnly1_17, because this is a lexem used for concatenation."
#endif
#define cDATEEP_SbkReadOnly1_17PositionByte      68 
#define cDATEEP_SbkReadOnly1_17PositionBit        0xFF
#define mSERPeeResetU32BitEEP_SbkReadOnly1_17()     \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  68 ,  7 ,  32 , 0, Delayed)
#define mSERReadU32BitEEP_SbkReadOnly1_17DefaultValueDefault() ((U32)0)
#define mSERReadU32BitEEP_SbkReadOnly1_17Default() \
      mSERPeeReadU32Bit(Sbk, GroupSbkReadOnly1,  68 ,  7 ,  32 , Delayed)
#define mSERWriteU32BitEEP_SbkReadOnly1_17Delayed(ValueToWrite) \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  68 ,  7 ,  32 , (ValueToWrite), Delayed)
#define mSERWriteU32BitEEP_SbkReadOnly1_17Immediate(ValueToWrite) \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  68 ,  7 ,  32 , (ValueToWrite), Immediate)
#define mSERWriteU32BitEEP_SbkReadOnly1_17Default(ValueToWrite) \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  68 ,  7 ,  32 , (ValueToWrite), Immediate)

// EEP_SbkReadOnly1_18 -- Group GroupSbkReadOnly1, Byte  72  , Bit (MSB)  7  , SizeInBit  32 
#ifdef EEP_SbkReadOnly1_18
  #error "Do not define EEP_SbkReadOnly1_18, because this is a lexem used for concatenation."
#endif
#define cDATEEP_SbkReadOnly1_18PositionByte      72 
#define cDATEEP_SbkReadOnly1_18PositionBit        0xFF
#define mSERPeeResetU32BitEEP_SbkReadOnly1_18()     \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  72 ,  7 ,  32 , 0, Delayed)
#define mSERReadU32BitEEP_SbkReadOnly1_18DefaultValueDefault() ((U32)0)
#define mSERReadU32BitEEP_SbkReadOnly1_18Default() \
      mSERPeeReadU32Bit(Sbk, GroupSbkReadOnly1,  72 ,  7 ,  32 , Delayed)
#define mSERWriteU32BitEEP_SbkReadOnly1_18Delayed(ValueToWrite) \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  72 ,  7 ,  32 , (ValueToWrite), Delayed)
#define mSERWriteU32BitEEP_SbkReadOnly1_18Immediate(ValueToWrite) \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  72 ,  7 ,  32 , (ValueToWrite), Immediate)
#define mSERWriteU32BitEEP_SbkReadOnly1_18Default(ValueToWrite) \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  72 ,  7 ,  32 , (ValueToWrite), Immediate)

// EEP_SbkReadOnly1_19 -- Group GroupSbkReadOnly1, Byte  76  , Bit (MSB)  7  , SizeInBit  32 
#ifdef EEP_SbkReadOnly1_19
  #error "Do not define EEP_SbkReadOnly1_19, because this is a lexem used for concatenation."
#endif
#define cDATEEP_SbkReadOnly1_19PositionByte      76 
#define cDATEEP_SbkReadOnly1_19PositionBit        0xFF
#define mSERPeeResetU32BitEEP_SbkReadOnly1_19()     \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  76 ,  7 ,  32 , 0, Delayed)
#define mSERReadU32BitEEP_SbkReadOnly1_19DefaultValueDefault() ((U32)0)
#define mSERReadU32BitEEP_SbkReadOnly1_19Default() \
      mSERPeeReadU32Bit(Sbk, GroupSbkReadOnly1,  76 ,  7 ,  32 , Delayed)
#define mSERWriteU32BitEEP_SbkReadOnly1_19Delayed(ValueToWrite) \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  76 ,  7 ,  32 , (ValueToWrite), Delayed)
#define mSERWriteU32BitEEP_SbkReadOnly1_19Immediate(ValueToWrite) \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  76 ,  7 ,  32 , (ValueToWrite), Immediate)
#define mSERWriteU32BitEEP_SbkReadOnly1_19Default(ValueToWrite) \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly1,  76 ,  7 ,  32 , (ValueToWrite), Immediate)

// EEP_SbkReadOnly2_0 -- Group GroupSbkReadOnly2, Byte  0  , Bit (MSB)  7  , SizeInBit  32 
#ifdef EEP_SbkReadOnly2_0
  #error "Do not define EEP_SbkReadOnly2_0, because this is a lexem used for concatenation."
#endif
#define cDATEEP_SbkReadOnly2_0PositionByte      0 
#define cDATEEP_SbkReadOnly2_0PositionBit        0xFF
#define mSERPeeResetU32BitEEP_SbkReadOnly2_0()     \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly2,  0 ,  7 ,  32 , 0, Delayed)
#define mSERReadU32BitEEP_SbkReadOnly2_0DefaultValueDefault() ((U32)0)
#define mSERReadU32BitEEP_SbkReadOnly2_0Default() \
      mSERPeeReadU32Bit(Sbk, GroupSbkReadOnly2,  0 ,  7 ,  32 , Delayed)
#define mSERWriteU32BitEEP_SbkReadOnly2_0Delayed(ValueToWrite) \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly2,  0 ,  7 ,  32 , (ValueToWrite), Delayed)
#define mSERWriteU32BitEEP_SbkReadOnly2_0Immediate(ValueToWrite) \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly2,  0 ,  7 ,  32 , (ValueToWrite), Immediate)
#define mSERWriteU32BitEEP_SbkReadOnly2_0Default(ValueToWrite) \
      mSERPeeWriteU32Bit(Sbk, GroupSbkReadOnly2,  0 ,  7 ,  32 , (ValueToWrite), Immediate)

// EEP_BCMCfg0 -- Group GroupBCMCfg0, Byte  0  , Bit (MSB)  7  , SizeInBit  8 
#ifdef EEP_BCMCfg0
  #error "Do not define EEP_BCMCfg0, because this is a lexem used for concatenation."
#endif
#define mSERPeeResetEEP_BCMCfg0()     \
{                                                     \
   mSERPeeWriteTable(U8Bit,Sbk,GroupBCMCfg0,  0 ,  0, 0, Delayed) \
}
#define mSERReadTableU1BitEEP_BCMCfg0DefaultValueDefault( Index ) \
      mSERPeeReadDefaultTable(U1Bit,Sbk, GroupBCMCfg0,  0 , Index, Delayed)

#define mSERReadTableU8BitEEP_BCMCfg0Default( Index ) \
      mSERPeeReadTable(U8Bit,Sbk, GroupBCMCfg0,  0 , Index, Delayed)
#define mSERWriteTableU8BitEEP_BCMCfg0Delayed( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Sbk, GroupBCMCfg0,  0 , Index, (ValueToWrite), Delayed)
#define mSERWriteTableU8BitEEP_BCMCfg0Immediate( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Sbk, GroupBCMCfg0,  0 , Index, (ValueToWrite), Immediate)
#define mSERWriteTableU8BitEEP_BCMCfg0Default( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Sbk, GroupBCMCfg0,  0 , Index, (ValueToWrite), Immediate)

// EEP_BCMCfg1 -- Group GroupBCMCfg1, Byte  0  , Bit (MSB)  7  , SizeInBit  8 
#ifdef EEP_BCMCfg1
  #error "Do not define EEP_BCMCfg1, because this is a lexem used for concatenation."
#endif
#define mSERPeeResetEEP_BCMCfg1()     \
{                                                     \
   mSERPeeWriteTable(U8Bit,Sbk,GroupBCMCfg1,  0 ,  0, 0, Delayed) \
}
#define mSERReadTableU1BitEEP_BCMCfg1DefaultValueDefault( Index ) \
      mSERPeeReadDefaultTable(U1Bit,Sbk, GroupBCMCfg1,  0 , Index, Delayed)

#define mSERReadTableU8BitEEP_BCMCfg1Default( Index ) \
      mSERPeeReadTable(U8Bit,Sbk, GroupBCMCfg1,  0 , Index, Delayed)
#define mSERWriteTableU8BitEEP_BCMCfg1Delayed( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Sbk, GroupBCMCfg1,  0 , Index, (ValueToWrite), Delayed)
#define mSERWriteTableU8BitEEP_BCMCfg1Immediate( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Sbk, GroupBCMCfg1,  0 , Index, (ValueToWrite), Immediate)
#define mSERWriteTableU8BitEEP_BCMCfg1Default( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Sbk, GroupBCMCfg1,  0 , Index, (ValueToWrite), Immediate)

// EEP_BCMCfg2 -- Group GroupBCMCfg2, Byte  0  , Bit (MSB)  7  , SizeInBit  8 
#ifdef EEP_BCMCfg2
  #error "Do not define EEP_BCMCfg2, because this is a lexem used for concatenation."
#endif
#define mSERPeeResetEEP_BCMCfg2()     \
{                                                     \
   mSERPeeWriteTable(U8Bit,Sbk,GroupBCMCfg2,  0 ,  0, 0, Delayed) \
}
#define mSERReadTableU1BitEEP_BCMCfg2DefaultValueDefault( Index ) \
      mSERPeeReadDefaultTable(U1Bit,Sbk, GroupBCMCfg2,  0 , Index, Delayed)

#define mSERReadTableU8BitEEP_BCMCfg2Default( Index ) \
      mSERPeeReadTable(U8Bit,Sbk, GroupBCMCfg2,  0 , Index, Delayed)
#define mSERWriteTableU8BitEEP_BCMCfg2Delayed( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Sbk, GroupBCMCfg2,  0 , Index, (ValueToWrite), Delayed)
#define mSERWriteTableU8BitEEP_BCMCfg2Immediate( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Sbk, GroupBCMCfg2,  0 , Index, (ValueToWrite), Immediate)
#define mSERWriteTableU8BitEEP_BCMCfg2Default( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Sbk, GroupBCMCfg2,  0 , Index, (ValueToWrite), Immediate)

// EEP_BCMCfg3 -- Group GroupBCMCfg3, Byte  0  , Bit (MSB)  7  , SizeInBit  8 
#ifdef EEP_BCMCfg3
  #error "Do not define EEP_BCMCfg3, because this is a lexem used for concatenation."
#endif
#define mSERPeeResetEEP_BCMCfg3()     \
{                                                     \
   mSERPeeWriteTable(U8Bit,Sbk,GroupBCMCfg3,  0 ,  0, 0, Delayed) \
}
#define mSERReadTableU1BitEEP_BCMCfg3DefaultValueDefault( Index ) \
      mSERPeeReadDefaultTable(U1Bit,Sbk, GroupBCMCfg3,  0 , Index, Delayed)

#define mSERReadTableU8BitEEP_BCMCfg3Default( Index ) \
      mSERPeeReadTable(U8Bit,Sbk, GroupBCMCfg3,  0 , Index, Delayed)
#define mSERWriteTableU8BitEEP_BCMCfg3Delayed( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Sbk, GroupBCMCfg3,  0 , Index, (ValueToWrite), Delayed)
#define mSERWriteTableU8BitEEP_BCMCfg3Immediate( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Sbk, GroupBCMCfg3,  0 , Index, (ValueToWrite), Immediate)
#define mSERWriteTableU8BitEEP_BCMCfg3Default( Index, ValueToWrite ) \
      mSERPeeWriteTable(U8Bit,Sbk, GroupBCMCfg3,  0 , Index, (ValueToWrite), Immediate)

// EEP_ODOClearCountBackup -- Group GroupEEPInitCtrl, Byte  0  , Bit (MSB)  7  , SizeInBit  8 
#ifdef EEP_ODOClearCountBackup
  #error "Do not define EEP_ODOClearCountBackup, because this is a lexem used for concatenation."
#endif
#define cDATEEP_ODOClearCountBackupPositionByte      0 
#define cDATEEP_ODOClearCountBackupPositionBit        0xFF
#define mSERPeeResetU8BitEEP_ODOClearCountBackup()     \
      mSERPeeWriteU8Bit(Sbk, GroupEEPInitCtrl,  0 ,  7 ,  8 , 0, Delayed)
#define mSERReadU8BitEEP_ODOClearCountBackupDefaultValueDefault() ((U8)0)
#define mSERReadU8BitEEP_ODOClearCountBackupDefault() \
      mSERPeeReadU8Bit(Sbk, GroupEEPInitCtrl,  0 ,  7 ,  8 , Delayed)
#define mSERWriteU8BitEEP_ODOClearCountBackupDelayed(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupEEPInitCtrl,  0 ,  7 ,  8 , (ValueToWrite), Delayed)
#define mSERWriteU8BitEEP_ODOClearCountBackupImmediate(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupEEPInitCtrl,  0 ,  7 ,  8 , (ValueToWrite), Immediate)
#define mSERWriteU8BitEEP_ODOClearCountBackupDefault(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupEEPInitCtrl,  0 ,  7 ,  8 , (ValueToWrite), Immediate)

// EEP_ODOClearCountBackup1 -- Group GroupEEPInitCtrl, Byte  1  , Bit (MSB)  7  , SizeInBit  8 
#ifdef EEP_ODOClearCountBackup1
  #error "Do not define EEP_ODOClearCountBackup1, because this is a lexem used for concatenation."
#endif
#define cDATEEP_ODOClearCountBackup1PositionByte      1 
#define cDATEEP_ODOClearCountBackup1PositionBit        0xFF
#define mSERPeeResetU8BitEEP_ODOClearCountBackup1()     \
      mSERPeeWriteU8Bit(Sbk, GroupEEPInitCtrl,  1 ,  7 ,  8 , 0, Delayed)
#define mSERReadU8BitEEP_ODOClearCountBackup1DefaultValueDefault() ((U8)0)
#define mSERReadU8BitEEP_ODOClearCountBackup1Default() \
      mSERPeeReadU8Bit(Sbk, GroupEEPInitCtrl,  1 ,  7 ,  8 , Delayed)
#define mSERWriteU8BitEEP_ODOClearCountBackup1Delayed(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupEEPInitCtrl,  1 ,  7 ,  8 , (ValueToWrite), Delayed)
#define mSERWriteU8BitEEP_ODOClearCountBackup1Immediate(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupEEPInitCtrl,  1 ,  7 ,  8 , (ValueToWrite), Immediate)
#define mSERWriteU8BitEEP_ODOClearCountBackup1Default(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupEEPInitCtrl,  1 ,  7 ,  8 , (ValueToWrite), Immediate)

// EEP_EEPInitCondition_1 -- Group GroupEEPInitCtrl, Byte  2  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_EEPInitCondition_1
  #error "Do not define EEP_EEPInitCondition_1, because this is a lexem used for concatenation."
#endif
#define cDATEEP_EEPInitCondition_1PositionByte      2 
#define cDATEEP_EEPInitCondition_1PositionBit        0xFF
#define mSERPeeResetU16BitEEP_EEPInitCondition_1()     \
      mSERPeeWriteU16Bit(Sbk, GroupEEPInitCtrl,  2 ,  7 ,  16 , 51797, Delayed)
#define mSERReadU16BitEEP_EEPInitCondition_1DefaultValueDefault() ((U16)51797)
#define mSERReadU16BitEEP_EEPInitCondition_1Default() \
      mSERPeeReadU16Bit(Sbk, GroupEEPInitCtrl,  2 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_EEPInitCondition_1Delayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Sbk, GroupEEPInitCtrl,  2 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_EEPInitCondition_1Immediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Sbk, GroupEEPInitCtrl,  2 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_EEPInitCondition_1Default(ValueToWrite) \
      mSERPeeWriteU16Bit(Sbk, GroupEEPInitCtrl,  2 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_EEPInitCondition_2 -- Group GroupEEPInitCtrl, Byte  4  , Bit (MSB)  7  , SizeInBit  16 
#ifdef EEP_EEPInitCondition_2
  #error "Do not define EEP_EEPInitCondition_2, because this is a lexem used for concatenation."
#endif
#define cDATEEP_EEPInitCondition_2PositionByte      4 
#define cDATEEP_EEPInitCondition_2PositionBit        0xFF
#define mSERPeeResetU16BitEEP_EEPInitCondition_2()     \
      mSERPeeWriteU16Bit(Sbk, GroupEEPInitCtrl,  4 ,  7 ,  16 , 21946, Delayed)
#define mSERReadU16BitEEP_EEPInitCondition_2DefaultValueDefault() ((U16)21946)
#define mSERReadU16BitEEP_EEPInitCondition_2Default() \
      mSERPeeReadU16Bit(Sbk, GroupEEPInitCtrl,  4 ,  7 ,  16 , Delayed)
#define mSERWriteU16BitEEP_EEPInitCondition_2Delayed(ValueToWrite) \
      mSERPeeWriteU16Bit(Sbk, GroupEEPInitCtrl,  4 ,  7 ,  16 , (ValueToWrite), Delayed)
#define mSERWriteU16BitEEP_EEPInitCondition_2Immediate(ValueToWrite) \
      mSERPeeWriteU16Bit(Sbk, GroupEEPInitCtrl,  4 ,  7 ,  16 , (ValueToWrite), Immediate)
#define mSERWriteU16BitEEP_EEPInitCondition_2Default(ValueToWrite) \
      mSERPeeWriteU16Bit(Sbk, GroupEEPInitCtrl,  4 ,  7 ,  16 , (ValueToWrite), Immediate)

// EEP_EEPInitCondition_3 -- Group GroupEEPInitCtrl, Byte  6  , Bit (MSB)  7  , SizeInBit  8 
#ifdef EEP_EEPInitCondition_3
  #error "Do not define EEP_EEPInitCondition_3, because this is a lexem used for concatenation."
#endif
#define cDATEEP_EEPInitCondition_3PositionByte      6 
#define cDATEEP_EEPInitCondition_3PositionBit        0xFF
#define mSERPeeResetU8BitEEP_EEPInitCondition_3()     \
      mSERPeeWriteU8Bit(Sbk, GroupEEPInitCtrl,  6 ,  7 ,  8 , 85, Delayed)
#define mSERReadU8BitEEP_EEPInitCondition_3DefaultValueDefault() ((U8)85)
#define mSERReadU8BitEEP_EEPInitCondition_3Default() \
      mSERPeeReadU8Bit(Sbk, GroupEEPInitCtrl,  6 ,  7 ,  8 , Delayed)
#define mSERWriteU8BitEEP_EEPInitCondition_3Delayed(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupEEPInitCtrl,  6 ,  7 ,  8 , (ValueToWrite), Delayed)
#define mSERWriteU8BitEEP_EEPInitCondition_3Immediate(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupEEPInitCtrl,  6 ,  7 ,  8 , (ValueToWrite), Immediate)
#define mSERWriteU8BitEEP_EEPInitCondition_3Default(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupEEPInitCtrl,  6 ,  7 ,  8 , (ValueToWrite), Immediate)

// EEP_EEPInitCondition_4 -- Group GroupEEPInitCtrl, Byte  7  , Bit (MSB)  7  , SizeInBit  8 
#ifdef EEP_EEPInitCondition_4
  #error "Do not define EEP_EEPInitCondition_4, because this is a lexem used for concatenation."
#endif
#define cDATEEP_EEPInitCondition_4PositionByte      7 
#define cDATEEP_EEPInitCondition_4PositionBit        0xFF
#define mSERPeeResetU8BitEEP_EEPInitCondition_4()     \
      mSERPeeWriteU8Bit(Sbk, GroupEEPInitCtrl,  7 ,  7 ,  8 , 0, Delayed)
#define mSERReadU8BitEEP_EEPInitCondition_4DefaultValueDefault() ((U8)0)
#define mSERReadU8BitEEP_EEPInitCondition_4Default() \
      mSERPeeReadU8Bit(Sbk, GroupEEPInitCtrl,  7 ,  7 ,  8 , Delayed)
#define mSERWriteU8BitEEP_EEPInitCondition_4Delayed(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupEEPInitCtrl,  7 ,  7 ,  8 , (ValueToWrite), Delayed)
#define mSERWriteU8BitEEP_EEPInitCondition_4Immediate(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupEEPInitCtrl,  7 ,  7 ,  8 , (ValueToWrite), Immediate)
#define mSERWriteU8BitEEP_EEPInitCondition_4Default(ValueToWrite) \
      mSERPeeWriteU8Bit(Sbk, GroupEEPInitCtrl,  7 ,  7 ,  8 , (ValueToWrite), Immediate)


//--------------------------------------------------------------------------
// Groups to define in the component DAT_Pee
//--------------------------------------------------------------------------

// mSERPeeReadTable(TypeDonnee, Strategy, Group, Byte, Bit, Index, TreatmentType)
// mSERPeeReadDefaultTable(TypeDonnee, Strategy, Group, Byte, Bit, Index)
// mSERPeeWriteTable(TypeDonnee, Strategy, Group, Byte, Bit, Index, ValueToWrite, TreatmentType)
// mSERPeeReadU8Bit(Strategy, Group, Byte, Bit, BitSize, TreatmentType)
// mSERPeeWriteU8Bit(Strategy, Group, Byte, Bit, BitSize, ValueToWrite, TreatmentType)
// mSERPeeReadU16Bit(Strategy, Group, Byte, Bit, BitSize, TreatmentType)
// mSERPeeWriteU16Bit(Strategy, Group, Byte, Bit, BitSize, ValueToWrite, TreatmentType)
// mSERPeeReadU32Bit(Strategy, Group, Byte, Bit, BitSize, TreatmentType)
// mSERPeeWriteU32Bit(Strategy, Group, Byte, Bit, BitSize, ValueToWrite, TreatmentType)
// mSERPeeReadU1Bit(Strategy, Group, Byte, Bit, TreatmentType)
// mSERPeeWriteU1Bit(Strategy, Group, Byte, Bit, Etat, TreatmentType)

#endif    //  I_PEE_PARAM_H
