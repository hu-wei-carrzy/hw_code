#include "BSP_DIO_CFG_GEN.h"

const gpio_base i2c_sda_pin_cfg={PTA,2u};//所有功能在PTA15上验证OK

const gpio_input_cfg in_put_cfg_arr[]=
{
    {.InPutIndex=IN_BLDC_DRV_PWRGD, .Gpio_Base={PTE,10u}     },
    {.InPutIndex=IN_DIO2, .Gpio_Base={PTE,13u}     },
    {.InPutIndex=IN_3408_FAULT, .Gpio_Base={PTE,14u}     },
    {.InPutIndex=IN_DIO3, .Gpio_Base={PTE,9u}     },
    {.InPutIndex=IN_DIO1, .Gpio_Base={PTC,0u}     },
    {.InPutIndex=IN_DIO13, .Gpio_Base={PTD,9u}     },
    {.InPutIndex=IN_HALL3, .Gpio_Base={PTB,3u}     },
    {.InPutIndex=IN_DIO11, .Gpio_Base={PTC,12u}     },
    {.InPutIndex=IN_DIO6, .Gpio_Base={PTB,1u}     },
    {.InPutIndex=IN_DIO8, .Gpio_Base={PTC,8u}     },
    {.InPutIndex=IN_DIO5, .Gpio_Base={PTA,17u}     },
    {.InPutIndex=IN_HALL5, .Gpio_Base={PTB,14u}     },
    {.InPutIndex=IN_DIO4, .Gpio_Base={PTA,15u}     },
    {.InPutIndex=IN_DIO7, .Gpio_Base={PTA,9u}     },

};
const gpio_output_cfg out_put_cfg_arr[]=
{
    {.OutPutIndex=OUT_IO_LED, .Gpio_Base={PTE,5u}     },
    {.OutPutIndex=OUT_A3G4250D_MCU_CS, .Gpio_Base={PTE,4u}     },
    {.OutPutIndex=OUT_A3G4250D_OE, .Gpio_Base={PTE,3u}     },
    {.OutPutIndex=OUT_MCU_FLASH_SPI_WP, .Gpio_Base={PTD,17u}     },
    {.OutPutIndex=OUT_DRV_MOTOR_nSLEEP, .Gpio_Base={PTD,15u}     },
    {.OutPutIndex=OUT_5V_SENSOR_EN, .Gpio_Base={PTD,14u}     },
    {.OutPutIndex=OUT_HDO_DSEN12, .Gpio_Base={PTD,7u}     },
    {.OutPutIndex=OUT_CTL3408_IN_F2, .Gpio_Base={PTD,11u}     },
    {.OutPutIndex=OUT_CTL3408_IN_F1, .Gpio_Base={PTD,10u}     },
    {.OutPutIndex=OUT_MOTOR_MCU_SPI_CS, .Gpio_Base={PTB,2u}     },
    {.OutPutIndex=OUT_HDO_IN3, .Gpio_Base={PTC,11u}     },
    {.OutPutIndex=OUT_HDO_IN2, .Gpio_Base={PTC,10u}     },
    {.OutPutIndex=OUT_HDO_IN1, .Gpio_Base={PTC,9u}     },
    {.OutPutIndex=OUT_I2C_SCL, .Gpio_Base={PTA,3u}     },
    {.OutPutIndex=OUT_I2C_SDA, .Gpio_Base={PTA,2u}     },
    {.OutPutIndex=OUT_I2C_WC, .Gpio_Base={PTA,14u}     },
    {.OutPutIndex=OUT_MCU_FLASH_SPI_OE, .Gpio_Base={PTE,1u}     },

};
