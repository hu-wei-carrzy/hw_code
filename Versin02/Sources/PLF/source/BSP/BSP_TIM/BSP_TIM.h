#ifndef  I_BSP_TIM_H
#define  I_BSP_TIM_H

#include "ARCH_CFG.h"

#ifdef cHeadIncludeType_Directly
#include "BSP_COMMON.h"
#else
#include ".\..\BSP_COMMON\BSP_COMMON.h"
#endif



extern void SysTickUnderflowCallback(void);

extern void ADCTriggerCallback(void);

extern void BSPTimInit(void);
extern void BSPTimSysTickStop(void);
extern void BSPTimSysTickStart(void);
extern void BSPTimADCStart(void);
extern void BSPTimADCStop(void);



#endif













