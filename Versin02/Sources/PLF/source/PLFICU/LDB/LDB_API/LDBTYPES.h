

#ifndef I_LDBTYPES_H
#define I_LDBTYPES_H


/*-------------------------------------------------------------------------
  Included files to resolve specific definitions in this file

  #include <system_file_name.h>
  #include "project_file_name.h"
  -------------------------------------------------------------------------*/
#include "ARCH_CFG.h"

#ifdef cHeadIncludeType_Directly
#include "DefTypes.h"
#include "lib.h"
#else
#include ".\..\..\LIB\LIB_API\DefTypes.h"
#include ".\..\..\LIB\LIB_API\lib.h"
#endif


#if defined(__cplusplus)
#define extern extern "C"
#endif


/*-------------------------------------------------------------------------
  Constant data

  #define cCMPConstantName   ((tType) ConstantValue)
  -------------------------------------------------------------------------*/

// Choose the PC access memory format for E_CAR
#ifdef COMPILATION_NATIVE
#define cFormatIntel
#else
// Choose the target access memory format
#define cFormatIntel
#endif

// Type configuration
#define LDBPARAM_RESOURCE_TYPE   U8
#define LDBPARAM_CHANNEL_TYPE    U8
#define LDBPARAM_ADDRESS_TYPE  U32//U16 change for extend CAN ID
#define LDBPARAM_CTRL_TYPE     U8
#define LDBPARAM_STATUS_TYPE   U8
#define LDBPARAM_TIMERREF_TYPE U8
#define LDBPARAM_TYPE_LNGMSG   U16

#if(defined(COMPILATION_NATIVE) && (!defined(_QAC_)) && (!defined(ATTOL_COV)))

		#define LDBPARAM_DELAY_TYPE    unsigned __int64
#else
		#define LDBPARAM_DELAY_TYPE    U32
#endif


/*-------------------------------------------------------------------------
  Exported Macro

  #define mCMPMacroName   (MacroDefinition)
  -------------------------------------------------------------------------*/ 
#ifdef COMPILATION_NATIVE
	#define mLDBPARAM_SIMULATE_PROCESSING_TIME_MACRO(x) LDBSimulerTempsTraitement((x))
	#define mLDBPARAM_TRACE_MACRO( Texte )       LDBPcTrace( (Texte) )
#else
	#define mLDBPARAM_SIMULATE_PROCESSING_TIME_MACRO(x) 
	#define mLDBPARAM_TRACE_MACRO( Texte )       
#endif
/*-------------------------------------------------------------------------
  Exported type

  struct  sCMPStructureName { ... };
  union   uCMPUnionName { ... };
  enum    eCMPEnumerationName { ... };
  typedef Expression tCMPTypeName;

  -------------------------------------------------------------------------*/
typedef LDBPARAM_RESOURCE_TYPE tRescID;
typedef LDBPARAM_CHANNEL_TYPE  tChannel;
typedef LDBPARAM_ADDRESS_TYPE  tAddress;
typedef LDBPARAM_CTRL_TYPE     tCtrl;
typedef LDBPARAM_STATUS_TYPE   tStatus;
typedef LDBPARAM_DELAY_TYPE    tDelay;
typedef LDBPARAM_TIMERREF_TYPE tTimerRef;

typedef struct
{
    U8*              pBuffer;         // Message buffer
    LDBPARAM_TYPE_LNGMSG Lng;            // Message lenght
} tMsg;

//------------------------- CallBacks types  ---------------------------

typedef void  (*tpCallBackCtrl       )( tCtrl                   );
typedef void  (*tpCallBackStatusCtrl )( tCtrl,    tStatus       );
typedef void  (*tpCallBackStatusAddr  )( tAddress, tStatus       );
typedef void  (*tpCallBackRxWithAddr )( tAddress, tStatus, tMsg*);

//---------------- Spontaneous Rx & Tx --------------
typedef struct
{
    tpCallBackRxWithAddr  pCallBackRx;
    tAddress              Address;
} tRxSpontWithAddr;

typedef struct
{
    tpCallBackStatusAddr   pCallBackStatus;
    tAddress              Address;
} tTxSpontWithAddr;

typedef tAddress    tTxSpontWithIdx;
typedef tAddress    tRxSpontWithIdx;

typedef void(*tpFunct)(void);

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

/*-------------------------------------------------------------------------
  End of includes non re entry
  -------------------------------------------------------------------------*/
#endif   /* I_LDBTYPES_H */
