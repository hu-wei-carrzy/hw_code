/*
 * BSP_SPI.c
 *
 *  Created on: 2025Äê1ÔÂ9ÈÕ
 *      Author: 00361759
 */

#include "BSP_SPI.h"

uint16_t Data[2] = {0x00};

void SPI_Init(void)
{
	LPSPI_DRV_MasterInit(BLDC_FLASH_SPI,&BLDC_FLASH_SPIState,&BLDC_FLASH_SPI_MasterConfig0);
	LPSPI_DRV_MasterInit(DC_SPI,&DC_SPIState,&DC_SPI_MasterConfig0);
	//LPSPI_DRV_MasterInit(GYROSCOPE_SPI,&gyroscope_SPIState,&gyroscope_SPI_MasterConfig0);

	INT_SYS_SetPriority(LPSPI1_IRQn,0x08);
	INT_SYS_SetPriority(LPSPI0_IRQn,0x09);
}

uint32_t SPI_writeRegister(uint8_t SPINum,uint8_t * sendBuffer)
{
	uint32_t ret;
	switch(SPINum)
	{
	case BLDC_spi:
		LPSPI_DRV_SetPcs(BLDC_FLASH_SPI,LPSPI_PCS0,0);
		LPSPI_DRV_MasterTransferBlocking(BLDC_FLASH_SPI,sendBuffer,&Data,2,TIMEOUT);
		//ret = LPSPI_DRV_MasterTransfer(BLDC_FLASH_SPI,sendBuffer,Data,2);
		break;
	case flash_spi:
		//LPSPI_DRV_SetPcs(BLDC_FLASH_SPI,LPSPI_PCS2,0);
		//LPSPI_DRV_MasterTransferBlocking(BLDC_FLASH_SPI,sendBuffer,&Data,2,TIMEOUT);
		break;
	case DC_spi:
		ret = LPSPI_DRV_MasterTransfer(DC_SPI,sendBuffer,Data,2);
		break;
	case GYROSCOPE_spi:
		//LPSPI_DRV_MasterTransferBlocking(GYROSCOPE_SPI,sendBuffer,&Data,2,TIMEOUT);
		break;
	default:
		break;
	}
	return ret;
}

uint32_t SPI_readRegister(uint8_t SPINum,uint8_t * sendBuffer,uint16_t * receiveBuffer)
{
	uint32_t ret;
	switch(SPINum)
	{
	case BLDC_spi:
		LPSPI_DRV_SetPcs(BLDC_FLASH_SPI,LPSPI_PCS0,0);
		LPSPI_DRV_MasterTransferBlocking(BLDC_FLASH_SPI,sendBuffer,receiveBuffer,2,TIMEOUT);
		//ret = LPSPI_DRV_MasterTransfer(BLDC_FLASH_SPI,sendBuffer,receiveBuffer,2);
		break;
	case flash_spi:
		//LPSPI_DRV_SetPcs(BLDC_FLASH_SPI,LPSPI_PCS2,0);
		//LPSPI_DRV_MasterTransferBlocking(BLDC_FLASH_SPI,sendBuffer,&receiveBuffer,2,TIMEOUT);
		break;
	case DC_spi:
		ret = LPSPI_DRV_MasterTransfer(DC_SPI,sendBuffer,receiveBuffer,2);
		break;
	case GYROSCOPE_spi:
		//LPSPI_DRV_MasterTransferBlocking(GYROSCOPE_SPI,sendBuffer,&receiveBuffer,2,TIMEOUT);
		break;
	default:
		break;
	}

	return ret;
}



