
#ifndef I_BSP_MPU_H
#define I_BSP_MPU_H

#ifdef cHeadIncludeType_Directly
#include "BSP_COMMON.h"
#else
#include ".\..\BSP_COMMON\BSP_COMMON.h"
#endif



#define cU8EnableMPU

#ifdef cU8EnableMPU


#define cU8Reg_Num0_4GB                  0
#define cU8Reg_Num1_TCRAM        1
#define cU8Reg_Num2_BootCode             2
#define cU8Reg_Num3_Rsrvd2            3
#define cU8Reg_Num4_AppCode        4
#define cU8Reg_Num5_EBI                  5
#define cU8Reg_Num6_MCUBootCode      6
#define cU8Reg_Num7_BuRAM          7
#define cU8Reg_Num8_Periph            8
#endif







#endif
