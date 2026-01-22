/*
 * BSP_DRV8305.c
 *
 *  Created on: 2025年5月26日
 *      Author: lenovo
 */

#include "BSP_DRV8305.h"

DRV8305_Infos_t DRV_8305;

uint16_t DRV8305_Read_Value[10] = {0};

void DRV8305_Init(void);



/***************************************************************************
 名称：DRV8305_Read_Reg
 作用：读取数据
  输入：芯片结构体、8位地址、数据存放地址
 返回：无
 描述：
****************************************************************************/
uint16_t DRV8305_Read_Reg(DRV8305_Infos_t *P_DRV8305,uint8_t Address,uint16_t *rx_data)
{
	uint32_t tempflag;

	P_DRV8305->TxFrame.CMD.B15 = DRV8305_Read;
	P_DRV8305->TxFrame.CMD.Address = Address;
	P_DRV8305->TxFrame.CMD.Byte = 0x00;

	tempflag = SPI_readRegister(BLDC_spi,&(P_DRV8305->TxFrame.TxData),&(P_DRV8305->RxFrame.RxData));

	rx_data[0] = P_DRV8305->RxFrame.STA.Byte0;	//返回状态位8-15
	rx_data[1] = P_DRV8305->RxFrame.STA.Byte1;

	return  P_DRV8305->RxFrame.RxData;				//返回读取的数据 0-7位
}

/***************************************************************************
 名称：DRV8305_Write_Reg
 作用：写入命令
  输入：芯片结构体、8位地址、8位命令
 返回：无
 描述：
****************************************************************************/
void DRV8305_Write_Reg(DRV8305_Infos_t *P_DRV8305,uint8_t Address,uint16_t Command)
{
	uint32_t ret;
	P_DRV8305->TxFrame.CMD.B15 = DRV8305_Write;
	P_DRV8305->TxFrame.CMD.Address = Address;
	P_DRV8305->TxFrame.CMD.Byte  = Command;

//	PINS_DRV_WritePin(PTB,5,0);
	ret = SPI_writeRegister(BLDC_spi,&(P_DRV8305->TxFrame.TxData));
//	SPI_Delay(200);
//	PINS_DRV_WritePin(PTB,5,1);

}


/***************************************************************************
 名称：DRV8305_Enable
 作用：芯片唤醒
  输入：无
 返回：无
 描述：nsleep引脚拉高
****************************************************************************/
void DRV8305_Enable(void)
{
	//DRV_8718_State.nSleep = 1;
	PINS_DRV_WritePin(PTC,14,1);
	PINS_DRV_WritePin(PTD,14,1);

}

/***************************************************************************
 名称：DRV8305_Disable
 作用：芯片唤醒
  输入：无
 返回：无
 描述：nsleep引脚拉高
****************************************************************************/
void DRV8305_Disable(void)
{
	//DRV_8718_State.nSleep = 1;
	PINS_DRV_WritePin(PTC,14,0);
}


/***************************************************************************
 名称：DRV8305_Init
 作用：芯片初始化
  输入：无
 返回：无
 描述：
****************************************************************************/
void DRV8305_Init(void)
{
	DRV8305_Enable();
	DRV8305_Read_Reg(&DRV_8305,WARN_STAT1,&(DRV8305_Read_Value[0]));
	DRV8305_Read_Reg(&DRV_8305,OV_FAULT,&(DRV8305_Read_Value[2]));
	DRV8305_Read_Reg(&DRV_8305,IC_OPERATION,&(DRV8305_Read_Value[4]));

	DRV8305_Write_Reg(&DRV_8305,GATEDRV_CTRL,0x296);
	DRV8305_Read_Reg(&DRV_8305,GATEDRV_CTRL,&(DRV8305_Read_Value[4]));

	DRV8305_Write_Reg(&DRV_8305,IC_OPERATION,0x720);
	DRV8305_Read_Reg(&DRV_8305,IC_OPERATION,&(DRV8305_Read_Value[4]));
	DRV8305_Write_Reg(&DRV_8305,IC_OPERATION,0x22);
}
/***************************************************************************
 名称：DRV8305_Init
 作用：芯片初始化
  输入：无
 返回：无
 描述：
****************************************************************************/
void DRV8305_ReadReg(void)
{
	DRV8305_Enable();
	DRV8305_Read_Reg(&DRV_8305,WARN_STAT1,&(DRV8305_Read_Value[0]));
	DRV8305_Read_Reg(&DRV_8305,OV_FAULT,&(DRV8305_Read_Value[2]));
	DRV8305_Read_Reg(&DRV_8305,IC_FAULT,&(DRV8305_Read_Value[4]));

	DRV8305_Write_Reg(&DRV_8305,IC_OPERATION,0x22);
	DRV8305_Read_Reg(&DRV_8305,IC_OPERATION,&(DRV8305_Read_Value[6]));

}

