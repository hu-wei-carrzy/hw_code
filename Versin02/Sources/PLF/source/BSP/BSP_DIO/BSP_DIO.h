/*  BEGIN_FILE_HDR
************************************************************************************************
*   NOTICE
*   This software is the property of Chery Technologies. Any information contained in this
*   doc should not be reproduced, or used, or disclosed without the written authorization from
*   HiRain Technologies.
************************************************************************************************
*   File Name       : BSP_DIO.h
************************************************************************************************
*   Project/Product :
*   Title           :
*   Author          :
************************************************************************************************
*   Description     : This file is used to implement the callback function.
*
************************************************************************************************
*   Limitations     :
*
************************************************************************************************
*
************************************************************************************************
*   Revision History:
*
*   Version     Date          Initials      CR#                    Descriptions
*   ---------   ----------    ------------  ----------             ---------------
*   1.0         2024/1/1      zhaojiangbo     N/A                    Original
*   1.1         2025/10/28    Na.hu           N/A                    修改DIN的文件格式
************************************************************************************************
* END_FILE_HDR*/
#ifndef BSP_DIO_H_
#define BSP_DIO_H_
//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//
// #include <system_file_name.h>
// #include "project_file_name.h"
//------------------------------------------------------------------------------
#include "pin_mux.h"
#include "BSP_DIO_CFG_GEN.h"
#include "interrupt_manager.h"


//------------------------------------------------------------------------------
// Data prefix for constant & data
//
// unsigned int {u8,u16,u32} / signed int {s8,s16,s32}
// register size unsigned int {r} / float {f32,f64}  / s for struct
// no prefix for other types.
//
//------------------------------------------------------------------------------
// Constant data
//
// #define cu16LAYCmpConstantName   ((U16) ConstantValueUL)
//------------------------------------------------------------------------------
extern const gpio_input_cfg in_put_cfg_arr[];
extern const gpio_output_cfg out_put_cfg_arr[];
extern const gpio_base i2c_sda_pin_cfg;

//------------------------------------------------------------------------------
// Exported type
//
// typedef Expression tLAYCmpTypeName;
//------------------------------------------------------------------------------
typedef enum
{
	eBSPNormalOutPin = 0,
	eBSPPwmOutPin

}GPIOOUTMODEL;

//------------------------------------------------------------------------------
// Exported data
//
// extern  tType   u8LAYCmpVariableName;
// extern  tType*  ps32LAYCmpVariableName;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Constant exported data
//
// extern const tType  s8LAYCmpVariableName;
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Exported Macros
//
// #define LAYCmpMacroName(...)   (MacroDefinition)
//------------------------------------------------------------------------------



//------------------------------------------------------------------------------
// Exported functions
//
// extern tReturnType LAYCmpFunctionName(tTypeArgument1 ArgumentName1, ... );
//------------------------------------------------------------------------------
void BSP_PORTC_IRQManage(void);
void BSP_PORTA_IRQManage(void);
void BSPGpioCtr(gpio_output_index Index,out_put_ctr_cmd Cmd);

//TODO: 需要修改为标准的函数声明
extern void LDBDinDIWakeUpIsr (void);
extern status_t PINS_Init(const pin_settings_config_t * config);

extern void BSPGpioInit(void);
extern void BSPOutputCtr(gpio_output_index Index,out_put_ctr_cmd Cmd);

extern void BSP_I2C_SDA_Pin_IOChange(io_state Sta);
extern io_state BSP_Get_I2C_SDA_Pin_IO_CfState(void);
extern input_state BSP_Get_I2C_SDA_Pin_InputState(void);
extern void BSP_I2C_SDA_Ctr(out_put_ctr_cmd Cmd);

extern void BSPDioOUT_IO_LEDCtrl(out_put_ctr_cmd Cmd);
extern void BSPDioOUT_A3G4250D_MCU_CSCtrl(out_put_ctr_cmd Cmd);
extern void BSPDioOUT_A3G4250D_OECtrl(out_put_ctr_cmd Cmd);
extern void BSPDioOUT_MCU_FLASH_SPI_WPCtrl(out_put_ctr_cmd Cmd);
extern void BSPDioOUT_DRV_MOTOR_nSLEEPCtrl(out_put_ctr_cmd Cmd);
extern void BSPDioOUT_5V_SENSOR_ENCtrl(out_put_ctr_cmd Cmd);
extern void BSPDioOUT_HDO_DSEN12Ctrl(out_put_ctr_cmd Cmd);
extern void BSPDioOUT_CTL3408_IN_F2Ctrl(out_put_ctr_cmd Cmd);
extern void BSPDioOUT_CTL3408_IN_F1Ctrl(out_put_ctr_cmd Cmd);
extern void BSPDioOUT_HDO_DSEN34Ctrl(out_put_ctr_cmd Cmd);
extern void BSPDioOUT_HDO_IN4Ctrl(out_put_ctr_cmd Cmd);
extern void BSPDioOUT_HDO_IN3Ctrl(out_put_ctr_cmd Cmd);
extern void BSPDioOUT_HDO_IN2Ctrl(out_put_ctr_cmd Cmd);
extern void BSPDioOUT_HDO_IN1Ctrl(out_put_ctr_cmd Cmd);
extern void BSPDioOUT_I2C_WCCtrl(out_put_ctr_cmd Cmd);
extern void BSPDioOUT_MCU_FLASH_SPI_OECtrl(out_put_ctr_cmd Cmd);


#endif   /* BSP_DIO_H_ */

