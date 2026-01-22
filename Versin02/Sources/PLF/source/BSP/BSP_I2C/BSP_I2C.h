/**
 * @file BSP_I2C.h
 * @brief
 * @version V1.0.0
 * @date 2015年11月23日
 * @note
 */

#ifndef SOURCE_BSP_BSP_I2C_BSP_I2C_H_
#define SOURCE_BSP_BSP_I2C_BSP_I2C_H_

/*****************************************************************************/
/* Include files (NOT RECOMMENDED, if needed SHOULD be out of "extern C" )   */
/*****************************************************************************/
#include "I2C_SIM.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*****************************************************************************/
/* Global pre-processor symbols/macros ('#define')                           */
/*****************************************************************************/

/*****************************************************************************/
/* Global type definitions ('typedef')                                       */
/*****************************************************************************/
/**
 * I2C接口返回结果，同模拟I2C驱动中i2c_sim_result_t
 */
typedef i2c_sim_result_t bsp_i2c_result_t;

/**
 * I2C配置参数，同DRV包中的stc_hsspi_config
 */
typedef struct bsp_i2c_config
{
    uint8_t DUMMY;  // 暂无
} bsp_i2c_config_t;

/**
 * I2C状态位
 */
typedef struct bsp_i2c_status {
  uint32_t arbitration_lost : 1;        ///< Master lost arbitration (cleared on start of next Master operation)
} bsp_i2c_status_t;

/**
 * I2C通道数
 */
typedef enum bsp_i2c_chn
{
    BSP_I2C_CHN_SIM,

    /**
     * DRV层支持的通道数。
     */
    BSP_I2C_CHN_MAX
} bsp_i2c_chn_t;
/*****************************************************************************/
/* Global constant declarations ('extern', definition & comment in C source) */
/*****************************************************************************/

/*****************************************************************************/
/* Global variable declarations ('extern', definition & comment in C source) */
/*****************************************************************************/

/*****************************************************************************/
/* Global function prototypes ('extern', definition & comment in C source)   */
/*****************************************************************************/
extern bsp_i2c_result_t BSP_I2C_Init(bsp_i2c_chn_t i2c_chn, bsp_i2c_config_t* i2c_cfg);
extern bsp_i2c_result_t BSP_I2C_MasterReceive(bsp_i2c_chn_t i2c_chn,
    uint32_t addr, uint8_t *data, uint32_t num, boolean_t xfer_pending);
extern bsp_i2c_result_t BSP_I2C_MasterTransmit(bsp_i2c_chn_t i2c_chn,
    uint32_t addr, const uint8_t *data, uint32_t num, boolean_t xfer_pending);
extern int32_t BSP_I2C_GetDataCount(bsp_i2c_chn_t i2c_chn);
extern bsp_i2c_result_t BSP_I2C_GetStatus(bsp_i2c_chn_t i2c_chn,
    bsp_i2c_status_t *i2c_status);

#ifdef __cplusplus
}
#endif
#endif /* SOURCE_BSP_BSP_I2C_BSP_I2C_H_ */
