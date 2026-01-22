/**
 * @file I2C_SIM.c
 * @brief 模拟I2C驱动
 * @version V1.0.0
 * @date 2015年12月23日
 * @note
 */
 
 //log
 //2016-09-19 09:28:30
 //add code for init the WP pin.

/*****************************************************************************/
/* Include files                                                             */
/*****************************************************************************/
#include "I2C_SIM.h"
#include "I2C_SIM_CFG.h"

/*****************************************************************************/
/* Private pre-processor symbols/macros ('#define')                          */
/*****************************************************************************/
#define I2C_ACK     (0u)
#define I2C_NO_ACK  (1u)

#ifndef I2C_ANTI_DEADLOCK_MAX
#define I2C_ANTI_DEADLOCK_MAX   (400u)  // I2C解锁尝试默认次数
#endif

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
/**
 * 模拟I2C通道属性
 */
static struct i2c_chn_atrributes
{
    boolean_t started;  //TRUE：已发送Start位且未发送Stop位，FALSE：未发送Start位
    boolean_t locked;   //TRUE：已死锁；FASLE：未死锁
    int32_t data_count; //已传输数据长度; -1 Slave地址未发送成功
} s_sim_chn_atrributes;

/*****************************************************************************/
/* Private function prototypes ('static', comment on the definitions)        */
/*****************************************************************************/
#define DELAY_100ns()   DELAY_50ns();   \
                        DELAY_50ns()

#define DELAY_200ns()   DELAY_100ns();  \
                        DELAY_100ns()

#define DELAY_500ns()   DELAY_200ns();  \
                        DELAY_200ns();  \
                        DELAY_100ns()

#define DELAY_1000ns()  DELAY_500ns();  \
                        DELAY_500ns()

#define DELAY_2000ns()  DELAY_1000ns(); \
                        DELAY_1000ns()

#if (I2C_SPEED == I2C_SPEED_100KPBS)
/**
 * tHD;STA: hold time (repeated) START condition
 * MIN: 4000ns
 * MAX: -
 */
#define DELAY_T_HD_STA()    DELAY_1000ns(); \
                            DELAY_200ns();  \
                            DELAY_100ns()

/**
 * tLOW: LOW period of the SCL clock
 * MIN: 4700ns
 * MAX: -
 */
#define DELAY_T_LOW_BEFORE_UPDATE_SDA() DELAY_2000ns(); \
                                        DELAY_500ns()
#define DELAY_T_LOW_AFTER_UPDATE_SDA()  DELAY_2000ns(); \
                                        DELAY_200ns()
#define DELAY_T_LOW()   DELAY_T_LOW_BEFORE_UPDATE_SDA();    \
                        DELAY_T_LOW_AFTER_UPDATE_SDA()

/**
 * tHIGH: HIGH period of the SCL clock
 * MIN: 4000ns
 * MAX: -
 */
#define DELAY_T_HIGH_BEFORE_READ_SDA()  DELAY_2000ns()
#define DELAY_T_HIGH_AFTER_READ_SDA()   DELAY_2000ns()
#define DELAY_T_HIGH()  DELAY_T_HIGH_BEFORE_READ_SDA(); \
                        DELAY_T_HIGH_AFTER_READ_SDA()

/**
 * tSU;STA: set-up time for a repeated START condition
 * MIN: 4700ns
 * MAX: -
 */
#define DELAY_T_SU_STA()    DELAY_2000ns(); \
                            DELAY_2000ns(); \
                            DELAY_500ns();  \
                            DELAY_200ns()

/**
 * tHD;DAT: data hold time
 * MIN: 0ns
 * MAX: -
 */
#define DELAY_T_HD_DAT()

/**
 * tSU;DAT: data set-up time
 * MIN: 250ns
 * MAX: -
 */
#define DELAY_T_SU_DAT()    DELAY_200ns();  \
                            DELAY_50ns()

/**
 * tr: rise time of both SDA and SCL
 * MIN: -
 * MAX: 1000ns
 */
#define DELAY_T_R()     DELAY_1000ns()

/**
 * tf: fall time of both SDA and SCL
 * MIN: -
 * MAX: 300ns
 */
#define DELAY_T_F()     DELAY_200ns();  \
                        DELAY_100ns()

/**
 * tSU;STO: set-up time for STOP condition
 * MIN: 4000ns
 * MAX: -
 */
#define DELAY_T_SU_STO()    DELAY_2000ns(); \
                            DELAY_2000ns()

/**
 * tBUF: bus free time between a STOP and START condition
 * MIN: 4700ns
 * MAX: -
 */
#define DELAY_T_BUF()   DELAY_2000ns(); \
                        DELAY_2000ns(); \
                        DELAY_500ns();  \
                        DELAY_200ns()

#elif (I2C_SPEED == I2C_SPEED_400KPBS)
/**
 * tHD;STA: hold time (repeated) START condition
 * MIN: 600ns
 * MAX: -
 */
#define DELAY_T_HD_STA()    DELAY_500ns();  \
                            DELAY_100ns()

/**
 * tLOW: LOW period of the SCL clock
 * MIN: 1300ns
 * MAX: -
 */
#define DELAY_T_LOW_BEFORE_UPDATE_SDA() DELAY_500ns()
#define DELAY_T_LOW_AFTER_UPDATE_SDA()  DELAY_500ns();  \
                                        DELAY_200ns();  \
                                        DELAY_100ns()
#define DELAY_T_LOW()   DELAY_T_LOW_BEFORE_UPDATE_SDA();    \
                        DELAY_T_LOW_AFTER_UPDATE_SDA()

/**
 * tHIGH: HIGH period of the SCL clock
 * MIN: 600ns
 * MAX: -
 */
#define DELAY_T_HIGH_BEFORE_READ_SDA()  DELAY_200ns();  \
                                        DELAY_100ns()
#define DELAY_T_HIGH_AFTER_READ_SDA()   DELAY_200ns();  \
                                        DELAY_100ns()
#define DELAY_T_HIGH()  DELAY_T_HIGH_BEFORE_READ_SDA(); \
                        DELAY_T_HIGH_AFTER_READ_SDA()

/**
 * tSU;STA: set-up time for a repeated START condition
 * MIN: 600ns
 * MAX: -
 */
#define DELAY_T_SU_STA()    DELAY_500ns(); \
                            DELAY_100ns()

/**
 * tHD;DAT: data hold time
 * MIN: 0ns
 * MAX: -
 */
#define DELAY_T_HD_DAT()

/**
 * tSU;DAT: data set-up time
 * MIN: 100ns
 * MAX: -
 */
#define DELAY_T_SU_DAT()    DELAY_100ns()

/**
 * tr: rise time of both SDA and SCL
 * MIN: -
 * MAX: 300ns
 */
#define DELAY_T_R()     DELAY_200ns();  \
                        DELAY_100ns()

/**
 * tf: fall time of both SDA and SCL
 * MIN: -
 * MAX: 300ns
 */
#define DELAY_T_F()     DELAY_200ns();  \
                        DELAY_100ns()

/**
 * tSU;STO: set-up time for STOP condition
 * MIN: 600ns
 * MAX: -
 */
#define DELAY_T_SU_STO()    DELAY_500ns(); \
                            DELAY_100ns()

/**
 * tBUF: bus free time between a STOP and START condition
 * MIN: 1300ns
 * MAX: -
 */
#define DELAY_T_BUF()   DELAY_1000ns(); \
                        DELAY_200ns();  \
                        DELAY_100ns()

#else
#error "I2C_SPEED is invalid !"
#endif

static inline void I2C_Start(void);
static inline void I2C_Stop(void);
static inline void I2C_WriteBit(uint8_t bit);
static inline uint8_t I2C_ReadBit(void);
static uint8_t I2C_WriteByte(uint8_t byte);
static uint8_t I2C_ReadByte(uint8_t nack);
static boolean_t I2C_AntiDeadlock(void);

/*****************************************************************************/
/* Global function definitions                                               */
/*****************************************************************************/
/**
 * 模拟I2C：初始化
 */
void I2C_Init(void)
{
    s_sim_chn_atrributes.started = FALSE;
    s_sim_chn_atrributes.data_count = -1;
    s_sim_chn_atrributes.locked = FALSE;

    SWITCH_SDA_TO_OUTPUT();
    SET_SDA();
    DELAY_T_R();
    SET_SCL();
    DELAY_T_R();

    SWITCH_WP_TO_OUTPUT();
    WRITE_DISABLE();
}


/**
 * 模拟I2C：接收数据
 * @param addr Slave地址(7-bit)
 * @param data 接收数据
 * @param num 数据长度
 * @param xfer_pending 传输后挂起：即不发送STOP位
 * @return Ok: 成功
 *         Error：失败（I2C死锁）
 */
i2c_sim_result_t I2C_Receive(
    uint32_t addr, uint8_t *data, uint32_t num, boolean_t xfer_pending)
{
    i2c_sim_result_t result;
    uint8_t nack;
    uint32_t offset;
    uint32_t data_count;

    if(TRUE == s_sim_chn_atrributes.locked) // if locked, try unlock
    {
        s_sim_chn_atrributes.locked = (I2C_AntiDeadlock() == TRUE) ? FALSE : TRUE;
    }

    I2C_Start();

    nack = I2C_WriteByte(((addr << 1u) | 0x01u));   // slave address with 1 ('read')

    if(I2C_NO_ACK == nack)
    {
        data_count = -1;    // When the Slave is not yet addressed by the Master
    }
    else
    {
        data_count = 0;

        for(offset = 0u; offset < num; offset++)
        {
            if((offset + 1u) == num)
            {
                data[offset] = I2C_ReadByte(I2C_NO_ACK);    // last byte with No ACK
            }
            else
            {
                data[offset] = I2C_ReadByte(I2C_ACK);    // ACK
            }

            data_count++;
        }
    }

    if(FALSE == xfer_pending)
    {
        I2C_Stop();
    }

    s_sim_chn_atrributes.data_count = data_count;

    if(FALSE == s_sim_chn_atrributes.locked)
    {
        result = Ok;
    }
    else
    {
        result = Error;
    }

    return result;
}

/**
 * 模拟I2C：发送数据
 * @param addr Slave地址(7-bit)
 * @param data 发送数据
 * @param num 数据长度
 * @param xfer_pending 传输后挂起：即不发送STOP位
 * @return Ok: 成功
 *         Error：失败（I2C死锁）
 */
i2c_sim_result_t I2C_Transmit(
    uint32_t addr, const uint8_t *data, uint32_t num, boolean_t xfer_pending)
{
    i2c_sim_result_t result;
    uint8_t nack;
    uint8_t byte;
    uint32_t offset;
    uint32_t data_count;

    if(TRUE == s_sim_chn_atrributes.locked) // if locked, try unlock
    {
        s_sim_chn_atrributes.locked = (I2C_AntiDeadlock() == TRUE) ? FALSE : TRUE;
    }

    I2C_Start();

    nack = I2C_WriteByte(((addr << 1u) & 0xFEu));   // slave address with 0 ('write')

    if(I2C_NO_ACK == nack)
    {
        data_count = -1;    // When the Slave is not yet addressed by the Master
    }
    else
    {
        data_count = 0;

        for(offset = 0u; offset < num; offset++)
        {
            byte = data[offset];
            nack = I2C_WriteByte(byte);
            if((I2C_ACK == nack)
                || ((offset + 1u) == num))  // last byte maybe with No ACK
            {
                data_count++;
            }
        }
    }

    if(FALSE == xfer_pending)
    {
        I2C_Stop();
    }

    s_sim_chn_atrributes.data_count = data_count;

    if(FALSE == s_sim_chn_atrributes.locked)
    {
        result = Ok;
    }
    else
    {
        result = Error;
    }

    return result;
}

/**
 * 模拟I2C：获取已传输的数据长度
 * @return 已传输的数据长度; -1 Slave地址未发送成功
 */
int32_t I2C_GetDataCount(void)
{
    return s_sim_chn_atrributes.data_count;
}

/**
 * 模拟I2C：总线是否死锁
 * @return TRUE: 已死锁
 *         FALSE: 未死锁
 */
boolean_t I2C_IsLocked(void)
{
    return s_sim_chn_atrributes.locked;
}

/*****************************************************************************/
/* Private function definitions ('static')                                   */
/*****************************************************************************/

/**
 * 模拟I2C：发送Start位
 */
static inline void I2C_Start(void)
{
    if(FALSE == s_sim_chn_atrributes.locked)
    {
        if(TRUE == s_sim_chn_atrributes.started)
        {
            SET_SDA();
            DELAY_T_R();
            SET_SCL();
            DELAY_T_R();

            // Repeated start setup time
            DELAY_T_SU_STA();
        }

        if(0u == READ_SDA())
        {
            s_sim_chn_atrributes.locked = TRUE; // arbitration lost
        }
        else
        {
            CLEAR_SDA();    // START: when SCL is high, SDA change form high to low
            DELAY_T_F();

            DELAY_T_HD_STA();

            CLEAR_SCL();    // hold scl line, prepare to transmit data
            DELAY_T_F();

            s_sim_chn_atrributes.started = TRUE;
        }
    }
}

/**
 * 模拟I2C：发送Stop位
 */
static inline void I2C_Stop(void)
{
    if(FALSE == s_sim_chn_atrributes.locked)
    {
        CLEAR_SDA();
        DELAY_T_F();

        DELAY_T_SU_DAT();   // MIN(tLOW, tSU;DAT)

        SET_SCL();
        DELAY_T_R();

        DELAY_T_SU_STO();   // Stop bit setup time

        // SDA had been switched to output
        SET_SDA();  // SCL is high, set SDA from 0 to 1
        DELAY_T_R();

        if(0u == READ_SDA())
        {
            s_sim_chn_atrributes.locked = TRUE; // arbitration lost
        }
        else
        {
            DELAY_T_BUF();

            s_sim_chn_atrributes.started = FALSE;
        }
    }
}

/**
 * 模拟I2C：发送数据位
 * @param bit 发给Slave的数据位
 */
static inline void I2C_WriteBit(uint8_t bit)
{
    if(FALSE == s_sim_chn_atrributes.locked)
    {
        DELAY_T_LOW_BEFORE_UPDATE_SDA();

        if(1u == bit)
        {
            SET_SDA();
            DELAY_T_R();
        }
        else
        {
            CLEAR_SDA();
            DELAY_T_F();
        }

        DELAY_T_LOW_AFTER_UPDATE_SDA();

        SET_SCL();
        DELAY_T_R();

        // SCL is high, now data is valid
        // If SDA is high, check that nobody else is driving SDA
        if((1u == bit) && (0u == READ_SDA()))
        {
            s_sim_chn_atrributes.locked = TRUE; // arbitration lost
        }
        else
        {
            DELAY_T_HIGH();

            CLEAR_SCL();
            DELAY_T_F();
        }
    }
}

/**
 * 模拟I2C：接收数据位
 * @return 从Slave收到的数据位
 * @attention 此函数调用前SDA管脚必须切换为 输入状态；调用后切回输出状态。
 */
static inline uint8_t I2C_ReadBit(void)
{
    uint8_t bit = 0u;

    if(FALSE == s_sim_chn_atrributes.locked)
    {
        DELAY_T_LOW();

        SET_SCL();
        DELAY_T_R();

        DELAY_T_HIGH_BEFORE_READ_SDA();

        // SDA had been switched to input before calling this function
        // and will switch to output when calling back
        bit = READ_SDA();   // SCL is high, now data is valid

        DELAY_T_HIGH_AFTER_READ_SDA();

        CLEAR_SCL();
        DELAY_T_F();
    }

    return bit;
}

/**
 * 模拟I2C：发送字节数据
 * @param byte 发给Slave的字节数据
 * @return 从Slave收到的ACK位
 */
static uint8_t I2C_WriteByte(uint8_t byte)
{
    uint8_t bit;
    uint8_t nack;

    for(bit = 0u; bit < 8u; bit++)
    {
        I2C_WriteBit(((byte & 0x80u) == 0u) ? 0u : 1u);
        byte <<= 1u;
    }

    SWITCH_SDA_TO_INPUT();  // Set SDA as input before reading

    nack = I2C_ReadBit();

    SWITCH_SDA_TO_OUTPUT();  // Set SDA as output after reading

    return nack;
}

/**
 * 模拟I2C：接收字节数据
 * @param nack 发给Slave的ACK位
 * @return 从Slave收到的字节数据
 */
static uint8_t I2C_ReadByte(uint8_t nack)
{
    uint8_t bit;
    uint8_t byte = 0u;

    SWITCH_SDA_TO_INPUT();  // Set SDA as input before reading

    for(bit = 0u; bit < 8u; bit++)
    {
        byte = (byte << 1u) | I2C_ReadBit();
    }

    SWITCH_SDA_TO_OUTPUT();  // Set SDA as output after reading

    I2C_WriteBit(nack);

    return byte;
}

/**
 * 模拟I2C：解死锁
 * @return 是否成功
 */
static boolean_t I2C_AntiDeadlock(void)
{
    uint32_t i;
    boolean_t result = FALSE;

    for(i = 0u; i < I2C_ANTI_DEADLOCK_MAX; i++)
    {
        if(1u == READ_SDA())
        {
            result = TRUE;
            break;
        }
        else
        {
            /*低电平，SCK发一个CLK后再次判断SDA电平*/
            CLEAR_SCL();
            DELAY_T_F();
            DELAY_T_LOW();

            SET_SCL();
            DELAY_T_R();
            DELAY_T_HIGH();
        }
    }

    return result;
}
