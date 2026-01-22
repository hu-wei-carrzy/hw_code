

#ifndef I_HAL_H
#define I_HAL_H (1)

//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//
// #include <system_file_name.h>
// #include "project_file_name.h"
//------------------------------------------------------------------------------
#include "HAL_CFG.h"

//------------------------------------------------------------------------------
// Data prefix for constant & data
//
// unsigned int {u8,u16,u32} / signed int {s8,s16,s32} 
// register size unsigned int {r} / float {f32,f64}  / s for struct 
// no prefix for other types.
//
//------------------------------------------------------------------------------
// Constant data
//
// #define cu16LAYCmpConstantName   ((U16) ConstantValueUL)
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Exported type
//
// typedef Expression tLAYCmpTypeName;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Exported data
//
// extern  tType   u8LAYCmpVariableName;
// extern  tType*  ps32LAYCmpVariableName; 
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Constant exported data
//
// extern const tType  s8LAYCmpVariableName;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Exported Macros
//
// #define LAYCmpMacroName(...)   (MacroDefinition)
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Exported functions
//
// extern tReturnType LAYCmpFunctionName(tTypeArgument1 ArgumentName1, ... );
//------------------------------------------------------------------------------
extern void LDBSendWithAddr      (tChannel Channel, tAddress Ad, tMsg* Msg );
extern void LDBPrepareSendWithAddr(tChannel Channel, tAddress Ad, tMsg* Msg );
extern void LDBReceiveWithAddr    (tChannel Channel, tAddress Ad, tMsg* Msg );

extern void LDBSendWithoutAddr      (tChannel Channel, tMsg* Msg );
extern void LDBPrepareSendWithoutAddr(tChannel Channel, tMsg* Msg );
extern void LDBReceiveWithoutAddr    (tChannel Channel, tMsg* Msg );

extern void LDBControl       (tChannel Channel, tCtrl Ctrl);
extern void LDBEnableCallBack(tChannel Channel, BOOL CallBackEnabled );
extern void LDBCallBackControl (tChannel Channel, tCtrl Ctrl,tStatus Status);
extern void LDBCallBackEndControl (tChannel Channel, tCtrl Ctrl,tStatus Status);
extern void LDBCallBackRxWithAddr (tChannel Channel, tAddress Addr, tStatus Status);
extern void LDBCallBackTxWithAddr (tChannel Channel, tAddress Addr, tStatus Status);
extern void LDBCallBackFromIrqWithAddr (tChannel Channel, tAddress Addr, tStatus Status);
extern  void    DATRtcCallBackRxWithAddr(tAddress sAddr, tStatus Status);
extern  void    DATRtcCallBackFromIrqWithAddr(tAddress sAddr, tStatus Status);
extern void LDBSupPreInit(void);
#endif   /* I_HAL_H */
