//******************************************************************************
// Company:      Johnson Controls Inc.
// -----------------------------------------------------------------------------
// Copyright:    This software is JCI property.
//               Duplication or disclosure without JCI written authorization
//               is prohibited.
// -----------------------------------------------------------------------------
// Project:      <PROJECT>
// Language:     ANSI-C
// -----------------------------------------------------------------------------
// Component:    <Comments about the component (role, algorithm, structure, 
//               limitations, defined tasks and events...)>
// -----------------------------------------------------------------------------
// $Date:   Jan 17 2014 18:20:38  $
// $Archive:   //DI_JMC_N330_IC/archives/1016282/DEV/BUILD/SOURCES/LAP_RWI.h-arc  $
// $Revision:   1.0  $
// -----------------------------------------------------------------------------
/* $Log:   //DI_JMC_N330_IC/archives/1016282/DEV/BUILD/SOURCES/LAP_RWI.h-arc  $
 * 
 *    Rev 1.0   Jan 17 2014 18:20:38   aluant
 * Initial revision.
 // 
 //    Rev 1.0   Dec 30 2010 16:29:16   aliuz0
 // Initial revision.
 * 
 *    Rev 1.0   Apr 22 2008 11:36:44   amonniy
 * Initial revision.
 * 
*/
//******************************************************************************

#ifndef I_LAP_RWI_H
#define I_LAP_RWI_H (1)

//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//
// #include <system_file_name.h>
// #include "project_file_name.h"
//------------------------------------------------------------------------------
#include "ARCH_CFG.h"

#include "LAP_RWI_INCLUDE.h"

#ifdef cHeadIncludeType_Directly
#include "LAP_DIA.h"
#ifdef BOOTLOADER_IS_SUPPORTED
#include "LIB_BOO.h"
#endif
#else
#include ".\..\LAP_DIA\LAP_DIA.h"
#ifdef BOOTLOADER_IS_SUPPORTED
#include ".\..\..\..\LIB\LIB_BOO\LIB_BOO.h"
#endif
#endif

//2017年11月23日 15:29:13
//zjb
//添加文件用于表示数据有效范围
#include "LAP_RWI_CFG.h"


//------------------------------------------------------------------------------
// Data prefix for constant & data: see coding guideline
//
//------------------------------------------------------------------------------
// Constant data
//
// #define cu16LAYCmpConstantName   ((U16) ConstantValueUL)
//------------------------------------------------------------------------------
#define cU8NbConvPointFG  5
#define cNbConvPointCV  5
#define cNbConvPointEngTG 5

#define cCfgU8ReqDataStartPos                                                ((U8)3U)


//将来如下宏要自动生成的，则JIL文件中导出
#define cU8AppDataFingerPintLength                               ((U8)13U)
#define cU8AppSoftFingerPrintLength                               ((U8)13U)
#define cU8AppVerLength                                                  ((U8)16U)
#define cU8AppDataLength										((U8)8U)
#define cU8ECUSerialNumberLegnth                                 ((U8)16U)
#define cU8ECUManufacturingDateLength                        ((U8)6U)
#define cU8SystemSupplierIDLength                            (U8)5U
#define cU8ProductModelDataLength                            (U8)16U
//2017年11月7日 16:22:35
//ICU511规定零件号为10个字节，Hex格式，但是BCM313是5个字节，使用BCD码
#define cU8ECUPartNumberDataLength                           ((U8)10U)
#define cU8ECUHWVersionDataLength                            ((U8)8U)
//Limit values
#define cCfgU16SpeedRatioLimit                                               ((U16)6000U)
#define cCfgU8ODOClearCountLimit                                         ((U8)255U)
#define cCfgU16SpeedWarningLimit                                            ((U8)140U)
#define cCfgU16TachoWarningLimit                                            ((U16)4000U)
#define cCfgU8OilPrsLowWarningLimit                                        ((U8)250)
#define cCfgU32AFCOdoBaseLimit                                             ((U32)9999999U)
#define cCfgU32AFCFuelLimit                                                     ((U32)0XFAFFFFFFU)
#define cCfgU32OdoTotalLimit                                                   ((U32)99999990U)
#define cCfgU8CoolWaterTemWarningValueOffset                 ((U8)40)
#define cCfgU8CoolWaterTemWarningValueHighLimit           ((U8)250)
#define cCfgU8CoolWaterTemWarningValueLowLimit           ((U8)0)

#define cCfgU8PwrDwnNrml                                                      ((U8)0U)
#define cCfgU8PwrDwnAbnrml                                                  ((U8)0X55U)

#define cCfgU8TyreNum_NoFunc                                              ((U8)0U)
#define cCfgU8TyreNum_4NoBackup                                        ((U8)1U)
#define cCfgU8TyreNum_4WithBackup                                     ((U8)2U)
#define cCfgU8TyreNum_6NoBackup                                        ((U8)3U)
#define cCfgU8TyreNum_6WithBackup                                     ((U8)4U)

#define cCfgU8ABSYllwSrc_EBSYllw                                             ((U8)0x00U)
#define cCfgU8ABSYllwSrc_ABSHardWire                                   ((U8)0x01U)
#define cCfgU8ABSYllwSrc_ABSCAN                                           ((U8)0x02U)

#define cCfgU8RadarSt_Opened                                                   ((U8)0x01U)
#define cCfgU8RadarSt_Closed                                                      ((U8)0x00U)

#define cCfgU8InsFCDisplay_Exist                                                  ((U8)0x01U)
#define cCfgU8InsFCDisplay_NoExist                                             ((U8)0x00U)

#define cCfgU16SruplusSpeedPulseLimit                                      ((U16)0XFFFE)

#define cCfgU32TotalWeightLimit                                      ((U32)0XFAFFFF)
#define cCfgU32TotalWeightNoWarn                                     ((U32)0XFFFFFF)

#define cCfgU16FuelR15DataLimitHigh                                        ((U16)1800)
#define cCfgU16FuelR15DataLimitLow                                        ((U16)100)
#define cCfgU16FuelChangeLimit                                             ((U16)1000U)//诊断更改最大限值
#define cCfgU16FuelFullScaleInit                                          ((U16)15500U)//油量满量程初始值

#define cCfgU8DIInputChannelNum                           (U8)57U
#define cu8SparePinNum									  (U8)0U
#define cCalSWVerAddr                                 (0x009F2000U)



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
extern void LAPRwiReadDataByIdentifier(void);
extern void LAPRwiWriteDataByIdentifier(void);

extern void LAPRwiOpenSession (void);
extern void LAPRwiCloseSession(void);

extern U8 LAP_RWI_CANComOutChn(void);

#endif   /* I_LAP_RWI_H */
