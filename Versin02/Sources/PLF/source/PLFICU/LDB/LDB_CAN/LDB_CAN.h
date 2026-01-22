//----  Mono-inclusion Definition-----
#ifndef I_LDB_CAN_H
#define I_LDB_CAN_H 1


/*-------------------------------------------------------------------------
  Included files to resolve specific definitions in this file

  #include <system_file_name.h>
  #include "project_file_name.h"
  -------------------------------------------------------------------------*/

#include "ARCH_CFG.h"

#ifdef cHeadIncludeType_Directly
#include "ldb.h"
#include "BSP_CAN_EXPORT.h"
#include "ldb_tos.h"
#else
#include ".\..\LDB\LDB_API\ldb.h"
#include ".\..\..\..\BSP\BSP_CAN\BSP_CAN_EXPORT.h"
//#include ".\..\LDB\LDB_API\ldb_tos.h"
#endif
#include "LDB_CAN_LIFE.h"
#include "LDB_CAN_CFG.h"

/*-------------------------------------------------------------------------
  Constant data

  #define cCMPConstantName   ((tType) ConstantValue)
  -------------------------------------------------------------------------*/
#ifdef cLogicCAN0Used
#define mLDBCan0Init()						LDBCANInit()
#else
#define mLDBCan0Init()
#endif

#ifdef cLogicCAN1Used
#define mLDBCan1Init()                      LDBCANInit()
#else
#define mLDBCan1Init()
#endif

#ifdef cLogicCAN2Used
#define mLDBCan2Init()                      LDBCANInit()
#else
#define mLDBCan2Init()
#endif

#define mLDBCANLeaveSleepMode()				//add your code here according to real situation
#define mLDBCANEnterSleepMode()				//add your code here according to real situation

//#define mLDBCan1Control()





/*-------------------------------------------------------------------------
  Exported Macros

  #define mCMPMacroName   (MacroDefinition)
  -------------------------------------------------------------------------*/ 
#ifdef cLogicCAN0Used
#define mLDBCan0Control(Ctrl)                      LDBCANControlStub((Ctrl),0U)
#define mLDBCan0ReceiveWithAddr(Addr,pMsg)         LDBCanReceiveWithAddrStub((Addr),(pMsg),0U)
#define mLDBCan0SendWithAddr(Addr,pMsg)            LDBCanSendWithAddrStub(0U,(Addr),(pMsg))
#else
#define mLDBCan0Control(Ctrl)
#define mLDBCan0ReceiveWithAddr(Addr,pMsg)
#define mLDBCan0SendWithAddr(Addr,pMsg)

#endif

#ifdef cLogicCAN1Used
#define mLDBCan1Control(Ctrl)                      LDBCANControlStub((Ctrl),1U)
#define mLDBCan1ReceiveWithAddr(Addr,pMsg)         LDBCanReceiveWithAddrStub((Addr),(pMsg),1U)
#define mLDBCan1SendWithAddr(Addr,pMsg)            LDBCanSendWithAddrStub(1U,(Addr),(pMsg))
#else
#define mLDBCan1Control(Ctrl)
#define mLDBCan1ReceiveWithAddr(Addr,pMsg)
#define mLDBCan1SendWithAddr(Addr,pMsg)
#endif

#ifdef cLogicCAN2Used
#define mLDBCan2Control(Ctrl)                                     LDBCANControlStub((Ctrl),2U)
#define mLDBCan2SendWithAddr(Addr,pMsg)            LDBCanSendWithAddrStub(2U,(Addr),(pMsg))
#define mLDBCan2ReceiveWithAddr(Addr,pMsg)         LDBCanReceiveWithAddrStub((Addr),(pMsg),2U)
#else
#define mLDBCan2Control(Ctrl)
#define mLDBCan2ReceiveWithAddr(Addr,pMsg)
#define mLDBCan2SendWithAddr(Addr,pMsg)
#endif


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

extern void LDBCANInit(void);
extern void LDBCANReceiveWithoutAddr(tMsg* pMsg);
extern void LDBCanReceiveWithAddrStub( tAddress Address, tMsg* pMsg , U8 u8MCUCANCh);
extern void LDBCANControlStub(tCtrl Ctrl,U8 u8MCUCANCh);
extern void LDBCanSendWithAddrStub(U8 u8MCUCANCh, tAddress Address, tMsg* pMsg );

#endif
