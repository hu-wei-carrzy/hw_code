/*
 * BSP_SPI.h
 *
 *  Created on: 2025Äê1ÔÂ9ÈÕ
 *      Author: 00361759
 */

#ifndef BSP_SPI_H_
#define BSP_SPI_H_

#include "Cpu.h"

#define BLDC_spi		0
#define flash_spi		1
#define DC_spi			2
#define GYROSCOPE_spi	3

#define TIMEOUT 100

extern uint16_t Data[2];

extern void SPI_Init(void);
extern uint32_t SPI_writeRegister(uint8_t SPINum,uint8_t * sendBuffer);
extern uint32_t SPI_readRegister(uint8_t SPINum,uint8_t * sendBuffer,uint16_t * receiveBuffer);
#endif /* BSP_SPI_H_ */
