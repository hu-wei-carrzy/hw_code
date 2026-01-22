

#ifndef I_LIB_BOO_H
#define I_LIB_BOO_H (1)

//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//
// #include <system_file_name.h>
// #include "project_file_name.h"
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Constant exported data
//
// extern const tType  s8LAYCmpVariableName;
//------------------------------------------------------------------------------

//LinkTable address definition (permits to the customer softare to access to shared function)

#define   cLIBBooBootLinkTableAddress    ((U32)0xDF2004UL)
//Definition of the entry point of the customer applicative software
//MB96F6A6
#define   cLIBBooApplicationStartAddress ((U32)0xDF2020UL)

//Bootloader version. define in Bootlaoder project's MAPPING.txt 
//and START_L.ASM and LIB_VER.h
//when you update the Bootloader version,you should change the macro
//defined in LIB_VER.h
#define   cLIBBooBootLoaderVersionAddress      ((U32)0xDF201CUL)
#define   cLIBBooBootLoaderReservedAddress    ((U32)0xDF201EUL)
//------------------------------------------------------------------------------
// Exported Macros
//
// #define LAYCmpMacroName(...)   (MacroDefinition)
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Exported type
//
// typedef Expression tLAYCmpTypeName;
//------------------------------------------------------------------------------

typedef void (*tpReturnToBootLink)      (BOOL, U16);
#ifndef COMPILATION_NATIVE
typedef BOOL (*tpRetreiveLogZoneRecord) (U8  *, U8 );
typedef void (*tpRetreiveECUIdent)      (U8  *);
#else
typedef BOOL (*tpRetreiveLogZoneRecord) (U8 *, U8 );
typedef void (*tpRetreiveECUIdent)      (U8 *);
#endif
typedef BOOL (*tpInfractAttDetected)    (void );
typedef U16  (*tpRetrieveAppliKey)      (void );
typedef void (*tpVoidLink)( void );

//Interface APPLI-BOOT definition
typedef struct
{
  tpReturnToBootLink      pReturnToBootLink;
  tpRetreiveLogZoneRecord pRetreiveLogZoneRecord;
  tpRetreiveECUIdent      pRetreiveECUIdent;
  tpInfractAttDetected    pInfractAttDetected;
  tpRetrieveAppliKey      pRetrieveAppliKey;
} tBootLinkTable;


//------------------------------------------------------------------------------
// Exported data
//
// extern  tType   u8LAYCmpVariableName;
// extern  tType*  ps32LAYCmpVariableName; 
//------------------------------------------------------------------------------

extern U32 LIBBooForcedLoaderModeDetected;
extern U32 LIBBooVehicleStateDetected;
extern U16 LIBBooApplicationRandomNumber;


//------------------------------------------------------------------------------
// Constant exported data
//
// extern const tType  s8LAYCmpVariableName;
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Exported functions
//
// extern tReturnType LAYCmpFunctionName(tTypeArgument1 ArgumentName1, ... );
//------------------------------------------------------------------------------

extern BOOL LIBIsReturnToBootMode(void);
extern U16  LIBGetSeedInitialValue(void);
extern BOOL LIBIsDownloadEnable(void);
#ifdef COMPILATION_NATIVE
extern BOOL LIBIsECUFunctional(void);
#endif
extern void LIBDisableReturnToBoot(void);
extern void LIBReturnToApplication(void);
extern void LIBBooSetNoInitVar(U32 dwVal);
extern void LIBReturnToBoot(BOOL Security,U16 ApplicationRandomNumber);

#endif   /* I_LIB_BOO_H */

