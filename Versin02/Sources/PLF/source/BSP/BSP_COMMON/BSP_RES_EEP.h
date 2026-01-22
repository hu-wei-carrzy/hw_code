/**
 * @file BSP_RES_EEP.h
 * @brief
 * @version V1.0.0
 * @date 2015年12月16日
 * @note
 */

//log
//2016-09-19 09:03:03
//disable the macro becuase now this is now SPI EEP



#ifndef SOURCE_BSP_BSP_COMMON_BSP_RES_EEP_H_
#define SOURCE_BSP_BSP_COMMON_BSP_RES_EEP_H_

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
//#define CONFIGURE_EEP_PINS

#ifdef CONFIGURE_EEP_PINS
 /**
 * EEPROM /HOLD Pin
 * @note GPIO，负控
 */
#define EEPROM_HOLD_PORT    cPort_2_Num
#define EEPROM_HOLD_PIN     cPin_05_Offset

/**
 * EEPROM /WP Pin
 * @note GPIO，负控
 */
#define EEPROM_WP_PORT      cPort_2_Num
#define EEPROM_WP_PIN       cPin_06_Offset

/**
 * SPISEL0 to EEPROM CS
 * @note 限选管脚：SPISELx
 */
#define EEPROM_CS_PORT      cPort_2_Num
#define EEPROM_CS_PIN       cPin_14_Offset

/**
 * SPICLK to EEPROM CLK
 * @note 固定管脚不可更改
 */
#define EEPROM_CLK_PORT     cPort_2_Num
#define EEPROM_CLK_PIN      cPin_10_Offset

/**
 * SPIDAT0 to EEPROM SI
 * @note 固定管脚不可更改
 */
#define EEPROM_SI_PORT      cPort_2_Num
#define EEPROM_SI_PIN       cPin_11_Offset

/**
 * SPIDAT1 to EEPROM SO
 * @note 固定管脚不可更改
 */
#define EEPROM_SO_PORT      cPort_2_Num
#define EEPROM_SO_PIN       cPin_13_Offset

#define EEP_HOLD MAKE_PORTPINCFG(EEPROM_HOLD_PORT, EEPROM_HOLD_PIN, PortOutputResourceGPIO, PortOutputDriveA, PortInputLevelCmosA)
#define EEP_WP   MAKE_PORTPINCFG(EEPROM_WP_PORT,   EEPROM_WP_PIN,   PortOutputResourceGPIO, PortOutputDriveA, PortInputLevelCmosA)

#define EEP_CS   MAKE_PORTPINCFG(EEPROM_CS_PORT,   EEPROM_CS_PIN,   PortOutputResourceG,    PortOutputDriveA, PortInputLevelCmosA)
#define EEP_CLK  MAKE_PORTPINCFG(EEPROM_CLK_PORT,  EEPROM_CLK_PIN,  PortOutputResourceG,    PortOutputDriveA, PortInputLevelCmosA)
#define EEP_SI   MAKE_PORTPINCFG(EEPROM_SI_PORT,   EEPROM_SI_PIN,   PortOutputResourceG,    PortOutputDriveA, PortInputLevelCmosA)
#define EEP_SO   MAKE_PORTPINCFG(EEPROM_SO_PORT,   EEPROM_SO_PIN,   PortOutputResourceG,    PortOutputDriveA, PortInputLevelCmosA)

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
#endif /* SOURCE_BSP_BSP_COMMON_BSP_RES_EEP_H_ */
