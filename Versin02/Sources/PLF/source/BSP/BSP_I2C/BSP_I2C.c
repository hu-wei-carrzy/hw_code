/**
 * @file BSP_I2C.c
 * @brief
 * @version V1.0.0
 * @date 2015年11月23日
 * @note
 */

/*****************************************************************************/
/* Include files                                                             */
/*****************************************************************************/
#include "BSP_I2C.h"

/*****************************************************************************/
/* Private pre-processor symbols/macros ('#define')                          */
/*****************************************************************************/

/*****************************************************************************/
/* Private type definitions ('typedef')                                      */
/*****************************************************************************/

/*****************************************************************************/
/* Global constant definitions                                               */
/*****************************************************************************/

/*****************************************************************************/
/* Private constant definitions ('static')                                   */
/*****************************************************************************/

/*****************************************************************************/
/* Global variable definitions                                               */
/*****************************************************************************/

/*****************************************************************************/
/* Private variable definitions ('static')                                   */
/*****************************************************************************/

/*****************************************************************************/
/* Private function prototypes ('static', comment on the definitions)        */
/*****************************************************************************/

/*****************************************************************************/
/* Global function definitions                                               */
/*****************************************************************************/
/**
 * 初始化I2C
 * @param i2c_chn I2C通道号
 * @param i2c_cfg I2C配置项
 * @return Ok: 成功
 *         ErrorInvalidParameter：输入参数错误
 */
bsp_i2c_result_t BSP_I2C_Init (bsp_i2c_chn_t i2c_chn, bsp_i2c_config_t* i2c_cfg)
{
    bsp_i2c_result_t result;

    if (i2c_chn < BSP_I2C_CHN_MAX)
    {
        I2C_Init();

        result = Ok;
    }
    else
    {
        result = ErrorInvalidParameter;
    }

    return result;
}

/**
 * Master从Slave接收数据
 * @param i2c_chn I2C通道号
 * @param addr Slave地址(7-bit)
 * @param data 接收数据
 * @param num 数据长度
 * @param xfer_pending 传输后挂起：即不发送STOP位
 * @return Ok: 成功
 *         Error：失败（I2C死锁）
 *         ErrorInvalidParameter：输入参数错误
 */
bsp_i2c_result_t BSP_I2C_MasterReceive(bsp_i2c_chn_t i2c_chn,
    uint32_t addr, uint8_t *data, uint32_t num, boolean_t xfer_pending)
{
    bsp_i2c_result_t result;

    if((i2c_chn < BSP_I2C_CHN_MAX)
        && (NULL != data)
        && (num < 0x10000u))
    {
        result = I2C_Receive(addr, data, num, xfer_pending);
    }
    else
    {
        result = ErrorInvalidParameter;
    }

    return result;
}

/**
 * Master向Slave发送数据
 * @param i2c_chn I2C通道号
 * @param addr Slave地址(7-bit)
 * @param data 发送数据
 * @param num 数据长度
 * @param xfer_pending 传输后挂起：即不发送STOP位
 * @return Ok: 成功
 *         Error：失败（I2C死锁）
 *         ErrorInvalidParameter：输入参数错误
 */
bsp_i2c_result_t BSP_I2C_MasterTransmit(bsp_i2c_chn_t i2c_chn,
    uint32_t addr, const uint8_t *data, uint32_t num, boolean_t xfer_pending)
{
    bsp_i2c_result_t result;

    if((i2c_chn < BSP_I2C_CHN_MAX)
        && (num < 0x10000u))
    {
        result = I2C_Transmit(addr, data, num, xfer_pending);
    }
    else
    {
        result = ErrorInvalidParameter;
    }

    return result;
}

/**
 * 获取已传输的数据长度
 * @param i2c_chn I2C通道号
 * @return 已传输的数据长度; -1 Slave地址未发送成功
 */
int32_t BSP_I2C_GetDataCount (bsp_i2c_chn_t i2c_chn)
{
    int32_t count = 0;

    if (i2c_chn < BSP_I2C_CHN_MAX)
    {
        count = I2C_GetDataCount();
    }

    return count;
}

/**
 * 获取I2C通道状态
 * @param i2c_chn I2C通道号
 * @param i2c_status 参考 @ref bsp_i2c_status_t
 * @return Ok: 成功
 *         ErrorInvalidParameter：输入参数错误
 */
bsp_i2c_result_t BSP_I2C_GetStatus(bsp_i2c_chn_t i2c_chn,
    bsp_i2c_status_t *i2c_status)
{
    bsp_i2c_result_t result;

    if((i2c_chn < BSP_I2C_CHN_MAX)
        && (NULL != i2c_status))
    {
        i2c_status->arbitration_lost = ((I2C_IsLocked() == TRUE) ? 1u : 0u);

        result = Ok;
    }
    else
    {
        result = ErrorInvalidParameter;
    }

    return result;
}

/*****************************************************************************/
/* Private function definitions ('static')                                   */
/*****************************************************************************/
