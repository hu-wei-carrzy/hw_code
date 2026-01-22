/**
 * @file I2C_SIM_CFG.h
 * @brief 模拟I2C驱动配置
 * @version V1.0.0
 * @date 2015年12月23日
 * @note
 */
 
 //log
 //2016-09-19 09:28:30
 //add code for init the WP pin.
//log:
//2016-9-23 11:51:20
// change the simulation I2c pin 适应新板子

#ifndef SOURCE_BSP_BSP_I2C_I2C_SIM_CFG_H_
#define SOURCE_BSP_BSP_I2C_I2C_SIM_CFG_H_
#include ".\..\BSP_COMMON\BSP_RES_PIN.h"
#include ".\..\BSP_COMMON\BSP_COMMON.h"
#include ".\..\BSP_DIO\BSP_DIO_EXPORT.h"
#include ".\..\BSP_DIO\BSP_DIO_CFG_GEN.h"
/*****************************************************************************/
/* Include files (NOT RECOMMENDED, if needed SHOULD be out of "extern C" )   */
/*****************************************************************************/

#ifdef __cplusplus
extern "C"
{
#endif

/*****************************************************************************/
/* Global pre-processor symbols/macros ('#define')                           */
/*****************************************************************************/
#define I2C_SPEED I2C_SPEED_400KPBS     // I2C总线速度

#define I2C_ANTI_DEADLOCK_MAX   (400u)  // I2C解锁尝试次数

//NOTE: here must be 0x50 not 0XA0.
#define I2C_EEP_SLAVE_ADDR   (0X50U)


/**
 * 时间基准
 */
#define CORE_NOP()      __asm("nop")  // Delay 12.5ns (1/80MHz)
#define DELAY_50ns()    CORE_NOP(); \
                        CORE_NOP(); \
                        CORE_NOP(); \
                        CORE_NOP()
/**
 * Set SDA as input(if need) and return current level of line, 0 or 1
 */


    //SDA=P313
//#define READ_SDA()      (GPIO_PIDR3_PID13)
#define READ_SDA()        BSP_Get_I2C_SDA_Pin_InputState()  //mBSPCOMGetPortPinValue(cCfg_UsedAsI2CSimSDA_Port,cCfg_UsedAsI2CSimSDA_Offset)


/**
 * Actively drive SDA signal high
 */
//#define SET_SDA()   (GPIO_PODR3_POD13 = 1u)
#define SET_SDA()     BSP_I2C_SDA_Ctr(TurnON) //mBSPCOMWritePin(cCfg_UsedAsI2CSimSDA_Port,cCfg_UsedAsI2CSimSDA_Offset, 1)


/**
 * Actively drive SDA signal low
 */
//#define CLEAR_SDA() (GPIO_PODR3_POD13 = 0u)
#define CLEAR_SDA()     BSP_I2C_SDA_Ctr(TurnOFF) //mBSPCOMWritePin(cCfg_UsedAsI2CSimSDA_Port, cCfg_UsedAsI2CSimSDA_Offset, 0)

//P312=WP
//#define WRITE_DISABLE()        (GPIO_PODR3_POD12 = 1u)
#define WRITE_DISABLE()        BSPOutputCtr(OUT_I2C_WC, TurnON)			//mBSPCOMWritePin(cCfg_UsedAsI2CSimWP_Port, cCfg_UsedAsI2CSimWP_Offset, 1)



//#define WRITE_ENABLE()        (GPIO_PODR3_POD12 = 0u)
#define WRITE_ENABLE()          BSPOutputCtr(OUT_I2C_WC, TurnOFF)  		//mBSPCOMWritePin(cCfg_UsedAsI2CSimWP_Port, cCfg_UsedAsI2CSimWP_Offset, 0)

//#define SWITCH_WP_TO_OUTPUT()  Port_SetPortPinDirection(3,12,PortGpioOutput)
#define SWITCH_WP_TO_OUTPUT()   // Port_SetPortPinDirection(cCfg_UsedAsI2CSimWP_Port,cCfg_UsedAsI2CSimWP_Offset,PortGpioOutput)

    /**
 * Switch SDA to input direction, before reading from slave
 */
//#define SWITCH_SDA_TO_INPUT()   Port_SetPortPinDirection(3,13,PortGpioInput)
#define SWITCH_SDA_TO_INPUT()  BSP_I2C_SDA_Pin_IOChange(DIO_INPUT)		// Port_SetPortPinDirection(cCfg_UsedAsI2CSimSDA_Port,cCfg_UsedAsI2CSimSDA_Offset,PortGpioInput)

/**
 * Switch SDA to output direction, after reading from slave
 */
//#define SWITCH_SDA_TO_OUTPUT()  Port_SetPortPinDirection(3,13,PortGpioOutput)
#define SWITCH_SDA_TO_OUTPUT()   BSP_I2C_SDA_Pin_IOChange(DIO_OUTPUT)//BSP_I2C_SDA_Ctr(TurnON)  // Port_SetPortPinDirection(cCfg_UsedAsI2CSimSDA_Port,cCfg_UsedAsI2CSimSDA_Offset,PortGpioOutput)
/**
 * Actively drive SCL signal high
 */
//SCL = P314
//#define SET_SCL()   (GPIO_PODR3_POD14 = 1u)
#define SET_SCL()      BSPOutputCtr(OUT_I2C_SCL, TurnON) //mBSPCOMWritePin(cCfg_UsedAsI2CSimSCL_Port, cCfg_UsedAsI2CSimSCL_Offset,1)
/**
 * Actively drive SCL signal low
 */
//#define CLEAR_SCL() (GPIO_PODR3_POD14 = 0u)
#define CLEAR_SCL()    BSPOutputCtr(OUT_I2C_SCL, TurnOFF)  //mBSPCOMWritePin(cCfg_UsedAsI2CSimSCL_Port, cCfg_UsedAsI2CSimSCL_Offset,0)
/*****************************************************************************/
/* Global type definitions ('typedef')                                       */
/*****************************************************************************/

/*****************************************************************************/
/* Global constant declarations ('extern', definition & comment in C source) */
/*****************************************************************************/

/*****************************************************************************/
/* Global variable declarations ('extern', definition & comment in C source) */
/*****************************************************************************/

/*****************************************************************************/
/* Global function prototypes ('extern', definition & comment in C source)   */
/*****************************************************************************/

#ifdef __cplusplus
}
#endif
#endif /* SOURCE_BSP_BSP_I2C_I2C_SIM_CFG_H_ */
