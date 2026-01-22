/*
 * BSP_DRV8305.h
 *
 *  Created on: 2025年5月26日
 *      Author: lenovo
 */

#ifndef PLF_SOURCE_BSP_BSP_SPI_BSP_DRV8305_H_
#define PLF_SOURCE_BSP_BSP_SPI_BSP_DRV8305_H_

#include "BSP_SPI.h"

#define DRV8305_Write 	0
#define DRV8305_Read  	1
#define DRV8305_TIMEOUT 1

#define	WARN_STAT1 			(uint8_t)(0x01)
#define OV_FAULT			(uint8_t)(0x02)
#define IC_FAULT			(uint8_t)(0x03)
#define VGS_FAULT			(uint8_t)(0x04)
#define HSGATE_CTRL			(uint8_t)(0x05)
#define LSGATE_CTRL			(uint8_t)(0x06)
#define GATEDRV_CTRL		(uint8_t)(0x07)
#define IC_OPERATION		(uint8_t)(0x09)
#define SHUNTAMP_CTRL		(uint8_t)(0x0A)
#define VOLTAGREG_CTRL		(uint8_t)(0x0B)
#define VDSSENSOR_CTRL		(uint8_t)(0x0C)

typedef union
{
	uint16_t TxData;
	struct
	{
		uint16_t Byte		:11;
		uint16_t Address    	:4; //寄存器地址
		uint16_t B15        	:1; //始终为0
	}CMD;
}DRV8305_TxFrame_u; //发送数据帧


typedef union
{
	uint16_t RxData;
	struct
	{
		uint16_t Byte0		 :8;
		uint16_t Byte1		 :4;
		uint16_t B12         :1;
		uint16_t B13         :1;
		uint16_t B14         :1;
		uint16_t B15         :1;
	}STA;
}DRV8305_RxFrame_u; //接受数据



typedef struct
{
	DRV8305_TxFrame_u TxFrame;
	DRV8305_RxFrame_u RxFrame;
}DRV8305_Infos_t;


#endif /* PLF_SOURCE_BSP_BSP_SPI_BSP_DRV8305_H_ */
