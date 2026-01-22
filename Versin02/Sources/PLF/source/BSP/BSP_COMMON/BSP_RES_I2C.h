/**
 * @file BSP_RES_I2C.h
 * @brief
 * @version V1.0.0
 * @date 2016年1月13日
 * @note
 */

//log:
//2016-09-19 09:04:03
// change the simulation I2c pin
//log:
//2016-9-23 11:51:20
// change the simulation I2c pin 适应新板子

#ifndef SOURCE_BSP_BSP_COMMON_BSP_RES_I2C_H_
#define SOURCE_BSP_BSP_COMMON_BSP_RES_I2C_H_

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
#define CONFIGURE_I2C_PINS

#ifdef CONFIGURE_I2C_PINS
#define I2C_SIM_SDA_PORT 3
#define I2C_SIM_SDA_PIN  13

#define I2C_SIM_SCL_PORT 3
#define I2C_SIM_SCL_PIN  14

#define I2C_SIM_SDA MAKE_PORTPINCFG(I2C_SIM_SDA_PORT, I2C_SIM_SDA_PIN, PortOutputResourceGPIO, PortOutputDriveA, PortInputLevelCmosA)
#define I2C_SIM_SCL MAKE_PORTPINCFG(I2C_SIM_SCL_PORT, I2C_SIM_SCL_PIN, PortOutputResourceGPIO, PortOutputDriveA, PortInputLevelCmosA)

#endif
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
#endif /* SOURCE_BSP_BSP_COMMON_BSP_RES_I2C_H_ */
