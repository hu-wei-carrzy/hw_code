/**
 * @file BSP_RES_ICU.h
 * @brief
 * @version V1.0.0
 * @date 2016Äê1ÔÂ13ÈÕ
 * @note
 */

#include "ARCH_CFG.h"
//#include "BSP_DRV_INCLUDE.h"

#ifndef SOURCE_BSP_BSP_COMMON_BSP_RES_ICU_H_
#define SOURCE_BSP_BSP_COMMON_BSP_RES_ICU_H_

/*****************************************************************************/
/* Include files (NOT RECOMMENDED, if needed SHOULD be out of "extern C" )   */
/*****************************************************************************/

#ifdef __cplusplus
extern "C"
{
#endif

#define cCfgEnableSpeedSmpl
//#define cCfgEnableTachoSmpl

/*****************************************************************************/
/* Global pre-processor symbols/macros ('#define')                           */
/*****************************************************************************/

#define cICU_ICU6_InputResID    117
#define cICU_ICU7_InputResID    117
#define cICU_ICU8_InputResID    119
#define cICU_ICU9_InputResID    119
#define cICU_ICU10_InputResID   123
#define cICU_ICU11_InputResID   123

#define cICU_IN6_InputResID    118
#define cICU_IN7_InputResID    119
#define cICU_IN8_InputResID    121
#define cICU_IN9_InputResID    122
#define cICU_IN10_InputResID   124
#define cICU_IN11_InputResID   125


#define cICU_Bind_FRT0        PortInputSourceA    
#define cICU_Bind_FRT1        PortInputSourceB 
#define cICU_Bind_FRT2        PortInputSourceC  
#define cICU_Bind_FRT3        PortInputSourceD  
#define cICU_Bind_FRT4        PortInputSourceE  
#define cICU_Bind_FRT5        PortInputSourceF  


#ifdef cCfgEnableSpeedSmpl
#define ICU_CV_PORT  cPort_0_Num
#define ICU_CV_PIN   cPin_05_Offset
#endif

#ifdef cCfgEnableTachoSmpl
#define ICU_CT_PORT cPort_0_Num
#define ICU_CT_PIN  cPin_06_Offset
#endif

#ifdef cCfgEnableSpeedSmpl
#define ICU_CV MAKE_PORTPINCFG(ICU_CV_PORT, ICU_CV_PIN, PortOutputResourceGPIO, PortOutputDriveA, PortInputLevelCmosA)
#endif

#ifdef cCfgEnableTachoSmpl
#define ICU_CT MAKE_PORTPINCFG(ICU_CT_PORT, ICU_CT_PIN, PortOutputResourceGPIO, PortOutputDriveA, PortInputLevelCmosA)
#endif


#define cCfgSpeedResICU      cICU_ICU6_InputResID
#define cCfgSpeedResPin       cICU_IN6_InputResID

/*****************************************************************************/
/* Global type definitions ('typedef')                                       */
/*****************************************************************************/

/*****************************************************************************/
/* Global constant declarations ('extern', definition & comment in C source) */
/*****************************************************************************/

/*****************************************************************************/
/* Global variable declarations ('extern', definition & comment in C source) */
/*****************************************************************************/

/*****************************************************************************/
/* Global function prototypes ('extern', definition & comment in C source)   */
/*****************************************************************************/

#ifdef __cplusplus
}
#endif
#endif /* SOURCE_BSP_BSP_COMMON_BSP_RES_ICU_H_ */
