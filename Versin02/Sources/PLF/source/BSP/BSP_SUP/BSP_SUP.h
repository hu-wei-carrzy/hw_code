#ifndef I_BSP_SUP_H
#define I_BSP_SUP_H

//2018年5月30日 15:47:13
//添加屏幕类型标定，这时添加头文件引用



#include "ARCH_CFG.h"

#ifdef cHeadIncludeType_Directly
#include "BSP_COMMON.h"
#include "I2C_REAL_EXPORT.h"
#include "BSP_DIO_EXPORT.h"
#include "BSP_PWM_EXPORT.h"
#include "BSP_MPU_EXPORT.h"
#include "BSP_CAN_EXPORT.h"
#include "BSP_EEP.h"
#include "LDBTYPES.h"
#else
#include ".\..\BSP_COMMON\BSP_COMMON.h"
//这里是包含I2C资源
#include ".\..\BSP_I2C\I2C_REAL_EXPORT.h"
#include ".\..\BSP_DIO\BSP_DIO_EXPORT.h"
#include ".\..\BSP_MPU\BSP_MPU_EXPORT.h"
#include ".\..\BSP_CAN\BSP_CAN_EXPORT.h"
#include ".\..\BSP_EEP\BSP_EEP.h"
#endif


extern void BSPSUPPinCfg(void);
extern void BSPSUPPinEnable(void);
#endif
