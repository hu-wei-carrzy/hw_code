

#ifndef I_HAL_CFG_H
#define I_HAL_CFG_H (1)


/*-------------------------------------------------------------------------
  Included files to resolve specific definitions in this file

  #include <system_file_name.h>
  #include "project_file_name.h"

#ifndef COMPILATION_NATIVE	// Target specific file name
  #include <system_file_name.h>
  #include "project_file_name.h"
#endif
  -------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
  Constant data

  #define cCMPConstantName   ((tType) ConstantValue)
  -------------------------------------------------------------------------*/
#include "ARCH_CFG.h"

#ifdef cHeadIncludeType_Directly
#include "LDBTYPES.h"
#include "HAL_LDB_INCLUDE.h"
#include "HAL_DATCBK_INCLUDE.h"
#else
#include ".\..\LDB\LDB_API\LDBTYPES.h"
#include "HAL_LDB_INCLUDE.h"
#include "HAL_DATCBK_INCLUDE.h"
#endif

/*-------------------------------------------------------------------------
    LDB Timer Management
  -------------------------------------------------------------------------*/
#ifdef COMPILATION_NATIVE
  #define cLDBTick            ((U32)1000L)       // Duration in nanosecond
  #define cLDBSleepTick       ((U32)1000L)       // Duration in nanosecond
#else
  #define cLDBTick            ((U32)1250000U)   // Duration in nanosecond
  #define cLDBSleepTick       ((U32)1250000U)   // Duration in nanosecond
#endif



// Tempo identifier
#define cLDBTimer1      ((tTimerRef)0x00U)
#define cLDBTimer2      ((tTimerRef)0x01U)
#define cLDBTimer3      ((tTimerRef)0x02U)
#define cLDBTimer4      ((tTimerRef)0x03U)
#define cLDBTimer5      ((tTimerRef)0x04U)





/*-------------------------------------------------------------------------
  Exported Macro

  #define mCMPMacroName   (MacroDefinition)
  -------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
  Exported type

  struct  sCMPStructureName { ... };
  union   uCMPUnionName { ... };
  enum    eCMPEnumerationName { ... };
  typedef Expression tCMPTypeName;

  -------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
  Exported data

  extern  tType   CMPVariableName;
  extern  tType*  pCMPVariableName;
  -------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
  Constant exported data

  extern const tType  CMPVariableName;
  -------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
  Exported functions

  extern tReturnType CMPFunctionName(tTypeArgument1 ArgumentName1, ... );
  -------------------------------------------------------------------------*/


//---------------------- Channel Functions Callback ----------------------

// --------------------------------------------------------------
//      Definition of Xxx Callback channel (with address)
// --------------------------------------------------------------
#ifdef cLDBCanalXxx

extern void    DATXxxCallBackEndCtrl    (tCtrl,    tStatus);
extern void    DATXxxCallBackCtrl       (tCtrl);
extern void    DATXxxCallBackTxWithAddr (tAddress, tStatus);
extern void    DATXxxCallBackRxWithAddr (tAddress, tStatus);
extern const   tRxSpontWithAddr          DATXxxRxSpontTable[];
extern const   U16                   DATXxxRxSpontNbr;

#endif // cLDBCanalXxx

// --------------------------------------------------------------
//      Definition of Yyy Callback channel (without address)
// --------------------------------------------------------------
#ifdef cLDBCanalYyy

extern void    DATYyyCallBackRxWithoutAddr(tStatus);
extern void    DATYyyCallBackTxWithoutAddr(tStatus);

#endif // cLDBCanalYyy


#if defined(__cplusplus)
#undef extern
#endif


/*-------------------------------------------------------------------------
  End of includes non re entry
  -------------------------------------------------------------------------*/
#endif   /* I_LDBPARAM_H */
