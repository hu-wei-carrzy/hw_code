#ifndef I_BSP_RST_H
#define I_BSP_RST_H


#include "ARCH_CFG.h"
#include ".\..\BSP_COMMON\BSP_COMMON.h"

#define cRstRegUnlockKey       0X5CACCE55
#define cRstTriggerSWValue     0XA5



extern uint32_t BSPRstGetResetCause(void);
extern void BSPRstRriggerSWReset(void);

#endif
