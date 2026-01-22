/**
 * @file I2C_SIM.h
 * @brief 模拟I2C驱动
 * @version V1.0.0
 * @date 2015年12月23日
 * @note
 */

#ifndef SOURCE_BSP_BSP_I2C_I2C_SIM_H_
#define SOURCE_BSP_BSP_I2C_I2C_SIM_H_

/*****************************************************************************/
/* Include files (NOT RECOMMENDED, if needed SHOULD be out of "extern C" )   */
/*****************************************************************************/
#include "deftypes.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*****************************************************************************/
/* Global pre-processor symbols/macros ('#define')                           */
/*****************************************************************************/
#define I2C_SPEED_100KPBS   100
#define I2C_SPEED_400KPBS   400

/*****************************************************************************/
/* Global type definitions ('typedef')                                       */
/*****************************************************************************/
/**
 * I2C接口返回结果，同DRV包中的en_result
 */
typedef en_result_t i2c_sim_result_t;

/*****************************************************************************/
/* Global constant declarations ('extern', definition & comment in C source) */
/*****************************************************************************/

/*****************************************************************************/
/* Global variable declarations ('extern', definition & comment in C source) */
/*****************************************************************************/

/*****************************************************************************/
/* Global function prototypes ('extern', definition & comment in C source)   */
/*****************************************************************************/
extern void I2C_Init(void);
extern i2c_sim_result_t I2C_Receive(
    uint32_t addr, uint8_t *data, uint32_t num, boolean_t xfer_pending);
extern i2c_sim_result_t I2C_Transmit(
    uint32_t addr, const uint8_t *data, uint32_t num, boolean_t xfer_pending);
extern int32_t I2C_GetDataCount(void);
extern boolean_t I2C_IsLocked(void);

#ifdef __cplusplus
}
#endif
#endif /* SOURCE_BSP_BSP_I2C_I2C_SIM_H_ */
