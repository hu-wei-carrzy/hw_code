//******************************************************************************
// Copyright:    This software is chery property.
//               Duplication or disclosure without chery written authorization
//               is prohibited.
// -----------------------------------------------------------------------------
// Project:      DCZY
// Language:     C
// -----------------------------------------------------------------------------
// Component:  
//                       
// -----------------------------------------------------------------------------
//******************************************************************************
// This line is used to separate code and file header.This is begin.
//*****************************BEGIN_NOMOVE*************************************
//Log:
//*****************************END_NOMOVE***************************************
// This line is used to separate code and file header. This is last line.
//******************************************************************************
 //------------------------------------------------------------------------------
 // Body Identification
 //------------------------------------------------------------------------------
#define BSP_DRV8718  "BSP_DRV8718"

//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//
// #include <system_file_name.h>
// #include "project_file_name.h"
//------------------------------------------------------------------------------
#include "BSP_DRV8718.h"

//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Local constants
//------------------------------------------------------------------------------
#define True 1
#define False 0

//------------------------------------------------------------------------------
// Local macros
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Local data
//------------------------------------------------------------------------------
static DRV8718_Infos_t DRV_8718;
static DRV8718_State_t DRV_8718_State;

static uint16_t ReadData1[2] = { 0 };
static uint16_t ReadData2[2] = { 0 };
static uint16_t Read_Value[6] = { 0 };

static MOTOR1_2 motor1_2;
static MOTOR3_4 motor3_4;



//------------------------------------------------------------------------------
// Exported data
//------------------------------------------------------------------------------



//------------------------------------------------------------------------------
// Local function prototypes
//------------------------------------------------------------------------------
static void SPI_Delay(uint32_t delay);
static void DRV8718_Write_Reg(DRV8718_Infos_t* P_DRV8718,uint8_t Address,uint8_t Command);
static uint8_t DRV8718_Read_Reg(DRV8718_Infos_t* P_DRV8718,uint8_t Address,uint16_t* rx_data);

static bool BSP_Check_Spi_Err(void);
static bool BSP_Check_AnyErr(void);
static bool BSP_Check_OTWD_Err(void);
static bool BSP_Check_OV_Err(void);
static bool BSP_Check_UV_Err(void);
static bool BSP_Check_DSGS_Err(void);


//==============================================================================
// LOCAL FUNCTIONS
//==============================================================================
/***************************************************************************
 ??:SPI_Delay
 ??:SPI?????
 ??:
 ??:?
 ??:
****************************************************************************/
static void SPI_Delay (uint32_t delay)
{
	while(delay --);
}

/***************************************************************************
 ??:DRV8718_Write_Reg
 ??:????
  ??:??????8????8???
 ??:?
 ??:
****************************************************************************/
static void DRV8718_Write_Reg(DRV8718_Infos_t *P_DRV8718,uint8_t Address,uint8_t Command)
{
	uint32_t ret;
	P_DRV8718->TxFrame.F.CMD.B14 = Write;
	P_DRV8718->TxFrame.F.CMD.B15 = 0;
	P_DRV8718->TxFrame.F.CMD.Address = Address;
	P_DRV8718->TxFrame.F.Byte  = Command;

	PINS_DRV_WritePin(PTB,2,0);
	ret = SPI_writeRegister(DC_spi,&(P_DRV8718->TxFrame.TxData));
	SPI_Delay(200);
	PINS_DRV_WritePin(PTB,2,1);
}

/***************************************************************************
 ??:DRV8718_Read_Reg
 ??:????
  ??:??????8??????????
 ??:?
 ??:
****************************************************************************/
static uint8_t DRV8718_Read_Reg(DRV8718_Infos_t *P_DRV8718,uint8_t Address,uint16_t *rx_data)
{
	uint32_t tempflag;

	P_DRV8718->TxFrame.F.CMD.B14 = Read;
	P_DRV8718->TxFrame.F.CMD.B15 = 0;
	P_DRV8718->TxFrame.F.CMD.Address = Address;
	P_DRV8718->TxFrame.F.Byte = 0x00;

	PINS_DRV_WritePin(PTB,2,0);
	tempflag = SPI_readRegister(DC_spi,&(P_DRV8718->TxFrame.TxData),&(P_DRV8718->RxFrame.RxData));
	SPI_Delay(200);
	PINS_DRV_WritePin(PTB,2,1);

	rx_data[0] = P_DRV8718->RxFrame.F.status.Byte;	//?????8-15
	rx_data[1] = P_DRV8718->RxFrame.F.Byte;

	return P_DRV8718->RxFrame.F.Byte;				//??????? 0-7?
}

/***************************************************************************
 ??:BSP_Check_Spi_Err
 ??:??SPI????
  ??:?
 ??:?
 ??:true????,false????
****************************************************************************/
static bool BSP_Check_Spi_Err(void)
{
	uint16_t Temp_Value[2];
	DRV8718_Read_Reg(&DRV_8718, IC_STAT1, Temp_Value);
	if ((Temp_Value[1] & (1 << 7)) == 0x80)
	{
		return false;  // SPI????
	}
	else
	{
		return true;   // ???SPI??
	}
}

/***************************************************************************
 ??:BSP_Check_POR_Err
 ??:????????????
  ??:?
 ??:?
 ??:true????,false????
****************************************************************************/
static bool BSP_Check_POR_Err(void)
{
	uint16_t Temp_Value[2];
	DRV8718_Read_Reg(&DRV_8718, IC_STAT1, Temp_Value);
	if ((Temp_Value[1] & (1 << 6)) == 0x40)
	{
		return true;  // ???????????
	}
	else
	{
		return false;   // ???????
	}
}

/***************************************************************************
 ??:BSP_Check_Fault_Err
 ??:????????
  ??:?
 ??:?
 ??:true????,false????
****************************************************************************/
static bool BSP_Check_Fault_Err(void)
{
	uint16_t Temp_Value[2];
	DRV8718_Read_Reg(&DRV_8718, IC_STAT1, Temp_Value);
	if ((Temp_Value[1] & (1 << 5)) == 0x20)
	{
		return true;  // ???????
	}
	else
	{
		return false;   // ?fault??
	}
}
/***************************************************************************
 ??:BSP_Check_Warn_Err
 ??:??????
  ??:?
 ??:?
 ??:true????,false????
****************************************************************************/
static bool BSP_Check_Warn_Err(void)
{
	uint16_t Temp_Value[2];
	DRV8718_Read_Reg(&DRV_8718, IC_STAT1, Temp_Value);
	if ((Temp_Value[1] & (1 << 4)) == 0x10)
	{
		return true;  // ??????
	}
	else
	{
		return false;   // ??
	}
}
/***************************************************************************
 ??:BSP_Check_DSGS_Err
 ??:??VDS&VGS????
  ??:?
 ??:?
 ??:true????,false????
****************************************************************************/
static bool BSP_Check_DSGS_Err(void)
{
	uint16_t Temp_Value[2];
	DRV8718_Read_Reg(&DRV_8718, IC_STAT1, Temp_Value);
	if ((Temp_Value[1] & (1 << 3)) == 0x08)
	{
		return true;  // ???VDS&VGS??
	}
	else
	{
		return false;   // VDS&VGS??
	}
}

/***************************************************************************
 ??:BSP_Check_UV_Err
 ??:??UV????
  ??:?
 ??:?
 ??:true????,false????
****************************************************************************/
static bool BSP_Check_UV_Err(void)
{
	uint16_t Temp_Value[2];
	DRV8718_Read_Reg(&DRV_8718, IC_STAT1, Temp_Value);
	if ((Temp_Value[1] & (1 << 2)) == 0x04)
	{
		return true;  // ???UV??
	}
	else
	{
		return false;   // ??
	}
}

/***************************************************************************
 ??:BSP_Check_OV_Err
 ??:??UV????
  ??:?
 ??:?
 ??:true????,false????
****************************************************************************/
static bool BSP_Check_OV_Err(void)
{
	uint16_t Temp_Value[2];
	DRV8718_Read_Reg(&DRV_8718, IC_STAT1, Temp_Value);
	if ((Temp_Value[1] & (1 << 1)) == 0x02)
	{
		return true;  // ???UV??
	}
	else
	{
		return false;   // ??
	}
}

/***************************************************************************
 ??:BSP_Check_OTWD_Err
 ??:Logic OR of OTW, OTSD, WD_FLT, IDIR_WARN, PCHR_WARN, PDCHR_WARN, and STC_WARN indicators
 ??:?
 ??:?
 ??:?????????,??PWM??
****************************************************************************/
static bool BSP_Check_OTWD_Err(void)
{
	uint16_t Temp_Value[2];
	DRV8718_Read_Reg(&DRV_8718, IC_STAT1, Temp_Value);
	if ((Temp_Value[1] & 0x01 ) == 0x02)
	{
		return true;  // ??OTWD??
	}
	else
	{
		return false;   // ??
	}
}




//==============================================================================
// EXPORTED FUNCTIONS
//==============================================================================

/***************************************************************************
 ??:DRV8718_Init
 ??:?????
  ??:?
 ??:?
 ??:
****************************************************************************/
void DRV8718_Init(void)
{
	DRV8718_Write_Reg(&DRV_8718, IC_CTRL1, 0x07);
	//DRV8718_Write_Reg(&DRV_8718, IC_CTRL2, 0x40);			//Sets nFLT function pin mode.

	DRV8718_Write_Reg(&DRV_8718, IC_CTRL1, 0x86);

	DRV8718_Write_Reg(&DRV_8718, IDRV_CTRL1, 0xAA);        //??1    ??48mA,48mA
	DRV8718_Write_Reg(&DRV_8718, IDRV_CTRL2, 0xAA);        //??2        48mA,48mA
	DRV8718_Write_Reg(&DRV_8718, IDRV_CTRL3, 0xAA);        //??3        48mA,48mA
	DRV8718_Write_Reg(&DRV_8718, IDRV_CTRL4, 0xAA);        //??4        48mA,48mA
	DRV8718_Write_Reg(&DRV_8718, IDRV_CTRL5, 0xAA);        //??5        48mA,48mA
	DRV8718_Write_Reg(&DRV_8718, IDRV_CTRL6, 0xAA);        //??6        48mA,48mA
	DRV8718_Write_Reg(&DRV_8718, IDRV_CTRL7, 0xAA);        //??7        48mA,48mA
	DRV8718_Write_Reg(&DRV_8718, IDRV_CTRL8, 0xAA);        //??8        48mA,48mA

	DRV8718_Write_Reg(&DRV_8718, VDS_CTRL1, 0xFF);        //??1?2  ??????0.18V 2V
	DRV8718_Write_Reg(&DRV_8718, VDS_CTRL2, 0xFF);        //??3?4  ??????2V
	DRV8718_Write_Reg(&DRV_8718, VDS_CTRL3, 0xFF);        //??5?6  ??????0.18V 2V
	DRV8718_Write_Reg(&DRV_8718, VDS_CTRL4, 0xFF);        //??7?8  ??????2V

	DRV8718_Write_Reg(&DRV_8718, DRV_CTRL2, 0x12);          //VGS1-4 drive and VDS monitor blanking time 8us
	DRV8718_Write_Reg(&DRV_8718, DRV_CTRL3, 0x12);          //VGS5-8 drive and VDS monitor blanking time 8us
	DRV8718_Write_Reg(&DRV_8718, DRV_CTRL4, 0x55);          //Insertable digital dead-time 2us
	DRV8718_Write_Reg(&DRV_8718, DRV_CTRL5, 0x00);        	//VDS overcurrent monitor deglitch time 1us

//	DRV8718_Write_Reg(&DRV_8718, DRV_CTRL1, 0xC6);          //??VGS?VDS??
	DRV8718_Write_Reg(&DRV_8718, DRV_CTRL1, 0x00);          //??VGS?VDS??

	DRV8718_Write_Reg(&DRV_8718, PWM_CTRL1, 0x05);        //??1?2??IN1??,??3?4??IN2??
	DRV8718_Write_Reg(&DRV_8718, PWM_CTRL2, 0xAF);        //??3?4??IN3??,??7?8??IN4??

	DRV8718_Write_Reg(&DRV_8718, PWM_CTRL4, 0x00);        //??Actice??,???Freedom

	DRV8718_Write_Reg(&DRV_8718, CSA_CTRL1, 0x09);		//????????
}

/***************************************************************************
 ??:Motor_Set_Direction
 ??:?????????
  ??:?
 ??:?
 ??:
****************************************************************************/
uint8_t Motor_Set_Direction(uint8_t channel , int8_t dir)
{
	switch (channel)
	{
	case Motor1:
	{
		if (dir == motor_forward)
		{
			motor1_2.half_bridge.half_bridge1 = 3;
			motor1_2.half_bridge.half_bridge2 = 1;
		}
		else if (dir == motor_reverse)
		{
			motor1_2.half_bridge.half_bridge1 = 1;
			motor1_2.half_bridge.half_bridge2 = 3;
		}
		else if (dir == motor_halt)
		{
			motor1_2.half_bridge.half_bridge1 = 1;
			motor1_2.half_bridge.half_bridge2 = 1;
		}
		else if (dir == motor_free)
		{
			motor1_2.half_bridge.half_bridge1 = 0;
			motor1_2.half_bridge.half_bridge2 = 0;
		}
		else
		{

		}
		break;
	}
	case Motor2:
	{
		if (dir == motor_forward)
		{
			motor1_2.half_bridge.half_bridge3 = 3;
			motor1_2.half_bridge.half_bridge4 = 1;
		}
		else if (dir == motor_reverse)
		{
			motor1_2.half_bridge.half_bridge3 = 1;
			motor1_2.half_bridge.half_bridge4 = 3;
		}
		else if (dir == motor_halt)
		{
			motor1_2.half_bridge.half_bridge3 = 1;
			motor1_2.half_bridge.half_bridge4 = 1;
		}
		else if (dir == motor_free)
		{
			motor1_2.half_bridge.half_bridge3 = 0;
			motor1_2.half_bridge.half_bridge4 = 0;
		}
		break;
	}
	case Motor3:
	{
		if (dir == motor_forward)
		{
			motor3_4.half_bridge.half_bridge5 = 3;
			motor3_4.half_bridge.half_bridge6 = 1;
		}
		else if (dir == motor_reverse)
		{
			motor3_4.half_bridge.half_bridge5 = 1;
			motor3_4.half_bridge.half_bridge6 = 3;
		}
		else if (dir == motor_halt)
		{
			motor3_4.half_bridge.half_bridge5 = 1;
			motor3_4.half_bridge.half_bridge6 = 1;
		}
		else if (dir == motor_free)
		{
			motor3_4.half_bridge.half_bridge5 = 0;
			motor3_4.half_bridge.half_bridge6 = 0;
		}
		break;
	}
	case Motor4:
	{
		if (dir == motor_forward)
		{
			motor3_4.half_bridge.half_bridge7 = 3;
			motor3_4.half_bridge.half_bridge8 = 1;
		}
		else if (dir == motor_reverse)
		{
			motor3_4.half_bridge.half_bridge7 = 1;
			motor3_4.half_bridge.half_bridge8 = 3;
		}
		else if (dir == motor_halt)
		{
			motor3_4.half_bridge.half_bridge7 = 1;
			motor3_4.half_bridge.half_bridge8 = 1;
		}
		else if (dir == motor_free)
		{
			motor3_4.half_bridge.half_bridge7 = 0;
			motor3_4.half_bridge.half_bridge8 = 0;
		}
		break;
	}
	default:
		break;
	}

//	DRV8718_Read_Reg(&DRV_8718,BRG_CTRL1,ReadData1);
//	DRV8718_Read_Reg(&DRV_8718,BRG_CTRL2,ReadData2);

	if (channel == Motor1 || channel == Motor2)
	{
//		if (ReadData1[1] != motor1_2.BRG_CTRL1_CMD )
//		{
			DRV8718_Write_Reg(&DRV_8718, BRG_CTRL1, motor1_2.BRG_CTRL1_CMD);
			return False;
//		}
//		else
//		{
//			return True;
//		}
	}
	else if (channel == Motor3 || channel == Motor4)
	{
//		if (ReadData2[1] != motor3_4.BRG_CTRL2_CMD)
//		{
			DRV8718_Write_Reg(&DRV_8718, BRG_CTRL2, motor3_4.BRG_CTRL2_CMD);
			return False;
//		}
//		else
//		{
//			return True;
//		}
	}
}


/***************************************************************************
 名称：
 作用：设置电机速度
  输入：无
 返回：无
 描述：将速度转换为占空比，控制PWM输出
****************************************************************************/
void BSP_Clear_DRV8718Fault(void)
{
	uint16_t Temp_Value = 0x01;
	DRV8718_Write_Reg(&DRV_8718, IC_CTRL1, Temp_Value);
	Temp_Value = 0x80;
	DRV8718_Write_Reg(&DRV_8718, IC_CTRL1, Temp_Value);
}

/***************************************************************************
 ??:DRV8718_Awake
 ??:????
  ??:?
 ??:?
 ??:nsleep????
****************************************************************************/
void DRV8718_Awake(void)
{
	DRV_8718_State.nSleep = 1;
	PINS_DRV_WritePin(PTD, 15, 1);
}

/***************************************************************************
 ??:DRV8718_Sleep
 ??:????
  ??:?
 ??:?
 ??:nsleep????
****************************************************************************/
void DRV8718_Sleep(void)
{
	DRV_8718_State.nSleep = 0;
	PINS_DRV_WritePin(PTD, 15, 0);
}
/***************************************************************************
 ??:BSP_Drv8718_FaultCk
 ??:??drv8718???
  ??:?
 ??:?
 ??:?????????,??PWM??
****************************************************************************/
eDRV8718_ErrorStatus BSP_Drv8718_FaultCk(void) {
	// ????SPI??????
	if (BSP_Check_Spi_Err()) {
		return DRV8718_ERROR_SPI_COMM;
	}
	else
	{
		if (BSP_Check_Fault_Err())
		{
			if (BSP_Check_DSGS_Err())
			{
				return DRV8718_ERROR_DSGS;
			}
			else if (BSP_Check_UV_Err())
			{
				return DRV8718_ERROR_UV;
			}
			else if (BSP_Check_OV_Err())
			{
				return DRV8718_ERROR_OV;
			}
			else if (BSP_Check_OTWD_Err())
			{
				return DRV8718_ERROR_OTWD;
			}
			return DRV8718_ERROR_FAULT;
		}
		else if (BSP_Check_POR_Err())
		{
			return DRV8718_ERROR_POR;
		}
		else if (BSP_Check_Warn_Err())
		{
			return DRV8718_ERROR_WARN;
		}
		return DRV8718_ERROR_NONE;
	}
}
