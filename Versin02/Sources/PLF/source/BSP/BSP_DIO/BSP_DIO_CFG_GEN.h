
#ifndef BSP_DIO_CFG_GEN_H_
#define BSP_DIO_CFG_GEN_H_

#include "pin_mux.h"


typedef enum
{
      IN_BLDC_DRV_PWRGD,
    IN_DIO2,
    IN_3408_FAULT,
    IN_DIO3,
    IN_DIO1,
    IN_DIO13,
    IN_HALL3,
    IN_DIO11,
    IN_DIO6,
    IN_DIO8,
    IN_DIO5,
    IN_HALL5,
    IN_DIO4,
    IN_DIO7,

 INPUTNUMBER
}gpio_input_index;


typedef enum
{
     OUT_IO_LED,
    OUT_A3G4250D_MCU_CS,
    OUT_A3G4250D_OE,
    OUT_MCU_FLASH_SPI_WP,
    OUT_DRV_MOTOR_nSLEEP,
    OUT_5V_SENSOR_EN,
    OUT_HDO_DSEN12,
    OUT_CTL3408_IN_F2,
    OUT_CTL3408_IN_F1,
    OUT_MOTOR_MCU_SPI_CS,
    OUT_HDO_IN3,
    OUT_HDO_IN2,
    OUT_HDO_IN1,
    OUT_I2C_SCL,
    OUT_I2C_SDA,
    OUT_I2C_WC,
    OUT_MCU_FLASH_SPI_OE,

 OUTPUTNUMBER
} gpio_output_index;




typedef enum
{
 TurnOFF=0u,
 TurnON
}out_put_ctr_cmd;

typedef enum
{
 INPUTOFF=0u,
 INPUTON
}input_state;

typedef enum
{
 DIO_INPUT=0u,
 DIO_OUTPUT
}io_state;

typedef struct
{
  GPIO_Type       *       base;
     uint32_t                pinPortIdx;
}gpio_base;

typedef struct
{
 gpio_output_index OutPutIndex;
 gpio_base Gpio_Base;
}gpio_output_cfg;

typedef struct
{
 gpio_input_index InPutIndex;
 gpio_base Gpio_Base;
}gpio_input_cfg;


#endif
