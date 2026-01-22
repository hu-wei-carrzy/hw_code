/*
 * BSP_WDOG_EXPORT.h
 *
 *  Created on: 2018年11月23日
 *      Author: chengwga
 */

#ifndef PLF_SOURCE_BSP_BSP_WDOG_BSP_WDOG_EXPORT_H_
#define PLF_SOURCE_BSP_BSP_WDOG_BSP_WDOG_EXPORT_H_
#include "BSP_WDOG.h"


void  BSPWdgInit(void);//初始化
void BSPWdgRefresh(void);//喂狗
void  BSPWdgDeinit(void);//反初始化,这个功能还未调通。//20181126 chengwga
//uint16_t WDOG_GetCounter(void);//获取当前计时数

#endif /* PLF_SOURCE_BSP_BSP_WDOG_BSP_WDOG_EXPORT_H_ */
