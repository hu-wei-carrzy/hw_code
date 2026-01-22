/**
 * @file BSP_EEP.c
 * @brief
 * @version V1.0.0
 * @date 2015?11?16?
 * @note
 */

//log
//2016-09-19 09:19:09
//chagne the code for using the siulation I2c EEP

/*****************************************************************************/
/* Include files                                                             */
/*****************************************************************************/
#include "..\..\PLFICU\LIB\LIB_API\LIB.h"
#include "..\BSP_COMMON\BSP_COMMON.h"
#include "BSP_EEP.h"
#include ".\..\BSP_I2C\BSP_I2C.h"
#include ".\..\BSP_I2C\I2C_REAL_EXPORT.h"
#include ".\..\BSP_I2C\I2C_SIM_CFG.h"
/*****************************************************************************/
/* Private pre-processor symbols/macros ('#define')                          */
/*****************************************************************************/

/**
 * Configuration for Microchip 25LC160C EEPROM
 */

/**
 * Clock Frequency
 *
 * Min.     Max.     Test Conditions
 * ?        10MHz    4.5V <= VCC <= 5.5V
 * ?        5MHz     2.5V <= VCC <= 4.5V
 * ?        3MHz     1.8V <= VCC <= 2.5V
 */
#define EEPROM_CLOCK_DIV    HsspiClkDividerDiv8 // Device clock 2.5MHz = HSSPI clock(20MHz) / 8

/**
 * CS Setup Time
 *
 * Min.     Max.    Test Conditions
 * 50ns     ?       4.5V <= VCC <= 5.5V
 * 100ns    ?       2.5V <= VCC <= 4.5V
 * 150ns    ?       1.8V <= VCC <= 2.5V
 */
#define EEPROM_CLOCK_DELAY  HsspiClkStart1ClkAfterSlaveSelect   // CS delay 400ns = 1 / Device clock(2.5Mhz)

/**
 * Serial clock low during idle, data output set with falling clock edge,
 * data input sampling with rising clock edge, ACES = 0.
 */
#define EEPROM_CLOCK_MODE   HsspiClkLowOutFallingInRising

#define EEPROM_DEVICE_ID    BSP_SPI_DEVICE_0    // Device on CS0

#define EEPROM_WIP_MASK     (0x01u) // 0000 000x Get WIP bit
                                    // (1: write in progress 0: no write)

#define EEPROM_WEL_MASK     (0x02u) // 0000 00x0 Get WEL bit
                                    // (1: write enable 0: write disable)

#define EEPROM_INST_SIZE    (1u)    // Instruction size in bytes

#define EEPROM_ADDR_SIZE    (2u)    // Address size in bytes

/**
 * Instruction set
 */
#define EEPROM_READ  (0x03u) // 0000 0011 Read data from memory array beginning at selected address
#define EEPROM_WRITE (0x02u) // 0000 0010 Write data to memory array beginning at selected address
#define EEPROM_WRDI  (0x04u) // 0000 0100 Reset the write enable latch (disable write operations)
#define EEPROM_WREN  (0x06u) // 0000 0110 Set the write enable latch (enable write operations)
#define EEPROM_RDSR  (0x05u) // 0000 0101 Read Status Register
#define EEPROM_WRSR  (0x01u) // 0000 0001 Write Status Register

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
static boolean_t BSP_EEP_IsWriteEnable(void);

static uint8_t BSP_EPP_ReadStatusReg(void);
static void BSP_EEP_EnableWrite(void);
static void BSP_EEP_DisableWrite(void);

/*****************************************************************************/
/* Global function definitions                                               */
/*****************************************************************************/
/**
 * ???
 */
void BSP_EEP_Init(void)
{
#if 0
    // spi configuration
    bsp_spi_config_t stcHsspiConfig =
    {
        .enClockSelection = HsspiClockAhb,               // USELESS
        .u8TxFifoThresholdLow = 8u,                      // Possible values from 0 to 15 (maximum fifo length is 16).
        .pfnTxStatusCallback = NULL,                     // USELESS
        .enMemoryBankSize = HsspiBankSize8kB,            // See description of #en_hsspin_bank_size_t.
        .enDirectModeProtocol = HsspiProtocolModeLegacy, // See description of #en_hsspi_protocol_mode_t.
        .enDirectModeDatarate = HsspiSDR,                // See description of #en_hsspi_datarate_mode_t.
        .enCommandSequencerModeProtocol = HsspiProtocolModeLegacy, // See description of #en_hsspi_protocol_mode_t.
        .enCommandSequencerModeDatarate = HsspiSDR,      // See description of #en_hsspi_datarate_mode_t.
        .enMemoryType = HsspiFlash,                      // USELESS
        .u16IdleTimeOut = 0xFFFFu,                       // The idle timeout interval is in terms of the AHB clock period.
        .enFifoWidth    = HsspiFifoWidth8                // 8-bit
    };
#ifdef DEBUG
    mLIBassert(Ok == BSP_SPI_Init(&stcHsspiConfig));
#else
    (void)BSP_SPI_Init(&stcHsspiConfig);
#endif

    bsp_spi_device_config_t stcExtDeviceConfig =
    {
        .enClockDivider = EEPROM_CLOCK_DIV,
        .enClockDelay   = EEPROM_CLOCK_DELAY,
        .enClockMode    = EEPROM_CLOCK_MODE,
        .u16DeAssertionTime = 31u,
    };

    // device configuration
#ifdef DEBUG
    mLIBassert(Ok == BSP_SPI_CfgDevice(EEPROM_DEVICE_ID, &stcExtDeviceConfig));
#else
    (void)BSP_SPI_CfgDevice(EEPROM_DEVICE_ID, &stcExtDeviceConfig);
#endif

    // lock eeprom
    BSP_EEP_Lock();

    // ??HOLD?
    Port_SetPortPinLevel(EEPROM_HOLD_PORT, EEPROM_HOLD_PIN, PortGpioHigh);
#endif

#if 0
    //this for I2c controller
    I2CRealInit();
#endif


    bsp_i2c_config_t i2c_config = {0};

    (void)BSP_I2C_Init(BSP_I2C_CHN_SIM, &i2c_config);



}

/**
 * ???
 * @param address ??
 * @param data ????
 * @param data_length ??????(????:@ref EEPROM_PAGE_SIZE)
 */
void BSP_EEP_ReadData(uint32_t address, uint8_t* pU8Data, uint32_t data_length)
{
    uint8_t  u8ReadBuf[5] = {0, 0, 0, 0,  0};
    uint16_t u16PagAddr = (uint16_t)(address % ((uint32_t)256U));
    uint8_t  u8Ret = 0U;

    uint8_t  u8DevAddr = (uint8_t)((uint32_t)I2C_EEP_SLAVE_ADDR | (address / (uint32_t)256U));
    bsp_i2c_result_t i2c_result = 0U;

    u8ReadBuf[0] = (uint8_t)u16PagAddr;

    i2c_result = BSP_I2C_MasterTransmit(BSP_I2C_CHN_SIM, u8DevAddr, u8ReadBuf, 1U, TRUE);
    if(i2c_result == 0U)
    {
        i2c_result = BSP_I2C_MasterReceive(BSP_I2C_CHN_SIM, u8DevAddr, pU8Data, data_length, FALSE);
        if(Ok == i2c_result)
        {
            if(data_length == BSP_I2C_GetDataCount(BSP_I2C_CHN_SIM))
            {
                //Read OK
                u8Ret = 0U;
            }
            else
            {
                u8Ret = 1U;
            }
        }
        else
        {
            u8Ret = 2U;
        }
    }

#if 0
    uint8_t u8TxFifo[EEPROM_INST_SIZE + EEPROM_ADDR_SIZE];

    if(data_length <= EEPROM_PAGE_SIZE)
    {
        u8TxFifo[0] = EEPROM_READ;
        u8TxFifo[1] = (uint8_t)(address >> 8u);
        u8TxFifo[2] = (uint8_t)address;

#ifdef DEBUG
        mLIBassert(Ok == BSP_SPI_TransferHalfDuplex(
            EEPROM_DEVICE_ID, u8TxFifo, sizeof(u8TxFifo), pU8Data, data_length));
#else
        (void)BSP_SPI_TransferHalfDuplex(
            EEPROM_DEVICE_ID, u8TxFifo, sizeof(u8TxFifo), pU8Data, data_length);
#endif
    }

#endif

#if 0
    //this for I2c controller
    uint8_t u8ReadBuf[2] = {0, 0};
    I2CAntiBusLock();
    I2CRealEEPBufRead(address,  u8ReadBuf ,  data_length);

    pU8Data[0] = u8ReadBuf[0];
    pU8Data[1] = u8ReadBuf[1];
#endif

}

/**
 * ???
 * @param address ??
 * @param data ????
 * @param data_length ??????(????:@ref EEPROM_PAGE_SIZE)
 */
void BSP_EEP_WriteData(uint32_t u32Addr, const uint8_t* pu8Data, uint32_t data_length)
{
    uint8_t  u8PagAddr = (uint8_t)(u32Addr % ((uint32_t)256U));
    uint8_t  u8DevAddr = (uint8_t)((uint32_t)I2C_EEP_SLAVE_ADDR | (u32Addr / (uint32_t)256U));
    uint8_t  u8WriteDataBuf[5] = {0, 0, 0, 0, 0};
    uint8_t  u8Loop = 0U;
    u8WriteDataBuf[0] = u8PagAddr;

    bsp_i2c_result_t i2c_result = 0U;

    for(u8Loop = 0U; (uint32_t)u8Loop < data_length;  u8Loop++ )
    {
        u8WriteDataBuf[u8Loop+1] = pu8Data[u8Loop];
    }

    i2c_result = BSP_I2C_MasterTransmit(BSP_I2C_CHN_SIM, u8DevAddr, u8WriteDataBuf, (data_length + 1U), FALSE);
      if(Ok == i2c_result)
      {
          if((data_length + 1U) == BSP_I2C_GetDataCount(BSP_I2C_CHN_SIM))
          {

          }
          else
          {

          }
      }
      else
      {

      }


#if 0
    //???EEP SPI ??
    uint8_t u8TxFifo[EEPROM_PAGE_SIZE + EEPROM_INST_SIZE + EEPROM_ADDR_SIZE];

    if(data_length <= EEPROM_PAGE_SIZE)
    {
        if(FALSE == BSP_EEP_IsWriteEnable())
        {
            BSP_EEP_EnableWrite();
        }

        u8TxFifo[0] = EEPROM_WRITE;
        u8TxFifo[1] = (uint8_t)(u32Addr >> 8u);
        u8TxFifo[2] = (uint8_t)u32Addr;

        mLIBmemcpy(&u8TxFifo[(EEPROM_INST_SIZE + EEPROM_ADDR_SIZE)], pu8Data, data_length);

#ifdef DEBUG
        mLIBassert(Ok == BSP_SPI_TransferHalfDuplex(
            EEPROM_DEVICE_ID, u8TxFifo, data_length + EEPROM_INST_SIZE + EEPROM_ADDR_SIZE, NULL, 0u));
#else
        (void)BSP_SPI_TransferHalfDuplex(
            EEPROM_DEVICE_ID, u8TxFifo, data_length + EEPROM_INST_SIZE + EEPROM_ADDR_SIZE, NULL, 0u);
#endif
    }
#endif

#if 0
    //this for I2c controller
    mLIBassert(data_length < 16);

    uint8_t u8Buf[2] = {0, 0};
    uint8_t u8Loop = 0;
    if(data_length <= 16)
    {
        for(u8Loop = 0;u8Loop<data_length; u8Loop++)
        {
           u8Buf[u8Loop] =  *pu8Data;
           pu8Data++;
        }

        I2CAntiBusLock();
        I2CRealEEPBufWrite(u32Addr , u8Buf ,  data_length);
    }
#endif


}

/**
 * ??EEP??
 * @details ???WP?
 */
void BSP_EEP_Unlock(void)
{
#if 0
    //this for I2c controller
    BSP_EEP_EnableWrite();
#endif

    WRITE_ENABLE();

#if 0
    //???SPI EEP ??
    Port_SetPortPinLevel(EEPROM_WP_PORT, EEPROM_WP_PIN, PortGpioHigh);
#endif
}

/**
 * ??EEP??
 * @details ???????;??WP?
 */
void BSP_EEP_Lock(void)
{
    WRITE_DISABLE();
#if 0
    //this for I2c controller
    BSP_EEP_DisableWrite();
#endif

#if 0
    //???SPI EEP??
    Port_SetPortPinLevel(EEPROM_WP_PORT, EEPROM_WP_PIN, PortGpioLow);
#endif

}

/**
 * ????????
 * @return TRUE: ??? FALSE: ???
 */
boolean_t BSP_EEP_IsWriteInProcess(void)
{
#if 0
    //this for I2c controller
    boolean_t bRet = FALSE;

   if (  I2CIsInWriting())
   {
       bRet = TRUE;
   }
    return bRet;
#endif

    return FALSE;


#if 0
    //?????SPI EEP
    uint8_t status;

    status = BSP_EPP_ReadStatusReg();

    return (boolean_t)(((status & EEPROM_WIP_MASK) == EEPROM_WIP_MASK) ? TRUE : FALSE);
#endif

}

/*****************************************************************************/
/* Private function definitions ('static')                                   */
/*****************************************************************************/
/**
 * ???????
 * @return TRUE: ??? FALSE: ???
 */
static boolean_t BSP_EEP_IsWriteEnable(void)
{
#if 0
    uint8_t status;

    status = BSP_EPP_ReadStatusReg();

    return (boolean_t)(((status & EEPROM_WEL_MASK) == EEPROM_WEL_MASK) ? TRUE : FALSE);
#endif


#if 0
    //this for I2c controller
    boolean_t bRet = FALSE;
    if(I2CRealIsWriteEnable())
    {
        bRet = TRUE;
    }
    else
    {
        bRet = FALSE;
    }

    return bRet;

#endif
    return 0;
}

/**
 * ??EEP????????
 * @return ???????
 */
#if 0
//????SPI EEP??
static uint8_t BSP_EPP_ReadStatusReg(void)
{
    uint8_t u8RxFifo[1];
    uint8_t u8TxFifo[1];

    u8RxFifo[0] = 0u;
    u8TxFifo[0] = EEPROM_RDSR;

#ifdef DEBUG
    mLIBassert(Ok == BSP_SPI_TransferHalfDuplex(
        EEPROM_DEVICE_ID, u8TxFifo, sizeof(u8TxFifo), u8RxFifo, sizeof(u8RxFifo)));
#else
    (void)BSP_SPI_TransferHalfDuplex(
        EEPROM_DEVICE_ID, u8TxFifo, sizeof(u8TxFifo), u8RxFifo, sizeof(u8RxFifo));
#endif

    return u8RxFifo[0];
}
#endif


/**
 * ?????
 */
static void BSP_EEP_EnableWrite(void)
{
#if 0
    //????SPI EEP??
    uint8_t u8TxFifo[EEPROM_INST_SIZE];

    u8TxFifo[0] = EEPROM_WREN;

#ifdef DEBUG
    mLIBassert(Ok == BSP_SPI_TransferHalfDuplex(
        EEPROM_DEVICE_ID, u8TxFifo, sizeof(u8TxFifo), NULL, 0u));
#else
    (void)BSP_SPI_TransferHalfDuplex(
        EEPROM_DEVICE_ID, u8TxFifo, sizeof(u8TxFifo), NULL, 0u);
#endif

#endif

#if 0
    //this for I2c controller
    I2CRealEnableWrite();
#endif
}

/**
 * ?????
 */
static void BSP_EEP_DisableWrite(void)
{
#if 0
    //????SPI EEP??
    uint8_t u8TxFifo[EEPROM_INST_SIZE];

    u8TxFifo[0] = EEPROM_WREN;

#ifdef DEBUG
    mLIBassert(Ok == BSP_SPI_TransferHalfDuplex(
        EEPROM_DEVICE_ID, u8TxFifo, sizeof(u8TxFifo), NULL, 0u));
#else
    (void)BSP_SPI_TransferHalfDuplex(
        EEPROM_DEVICE_ID, u8TxFifo, sizeof(u8TxFifo), NULL, 0u);
#endif

#endif

#if 0
    //this for I2c controller
    I2CRealDisableWrite();
#endif
}

#if 0
boolean_t BSP_EEP_Test(void)
{
    uint32_t address;
    uint8_t r_data[2];
    uint8_t w_data[2];

    address = 0u;

    w_data[0] = 0x33u;
    w_data[1] = 0x11u;

    BSP_EEP_Unlock();

    BSP_EEP_WriteData(address, w_data, sizeof(w_data));

    while(TRUE == BSP_EEP_IsWriteInProcess())
    {
        ;   /* wait for completed */
    }

    BSP_EEP_ReadData(address, r_data, sizeof(r_data));

    BSP_EEP_Lock();

    return (boolean_t)((0 == mLIBmemcmp(r_data, w_data, sizeof(w_data))) ? TRUE : FALSE);
}
#endif
