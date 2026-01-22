/*
 * BSP_GPIO_EXPORT.h
 *
 *  Created on: 2018年11月23日
 *      Author: chengwga
 */

#ifndef BSP_DIO_EXPORT_H_
#define BSP_DIO_EXPORT_H_

#include"BSP_DIO.h"

extern BOOL BSPSetGpioCfgState(U8 u8chn,GPIOOUTMODEL mod);

extern void BSPGpioInit(void);
extern void BSPOutputCtr(gpio_output_index Index,out_put_ctr_cmd Cmd);	// 输出控制
extern input_state  BSPGetInputState(gpio_input_index Index);			// 获取输入通道开/关状态

extern io_state BSP_Get_I2C_SDA_Pin_IO_CfState(void);		// 获取I2C_SDA管脚性质配置状态
extern input_state BSP_Get_I2C_SDA_Pin_InputState(void);	// 获取I2C_SDA管脚的输入状态
extern void BSP_I2C_SDA_Ctr(out_put_ctr_cmd Cmd);			// I2C管脚输出控制
extern void BSP_I2C_SDA_Pin_IOChange(io_state Sta);			// I2C管脚输入输出切换

extern void BSPDioEnableDIOInt(void);
extern void BSPDioDisableDIOInt(void);

#endif 			/* PLF_SOURCE_BSP_BSP_GPIO_BSP_GPIO_EXPORT_H_ */
