/**
 * @file BSP_EEP.h
 * @brief EEPROM适配器：从LDB_EEP中抽出的功能接口，根据所选的EEPROM芯片型号，调用BSP中的驱动实现。
 * @version V1.0.0
 * @date 2015年11月16日
 * @note
 */

#ifndef SOURCE_BSP_BSP_EEP_BSP_EEP_H_
#define SOURCE_BSP_BSP_EEP_BSP_EEP_H_

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

/*****************************************************************************/
/* Global type definitions ('typedef')                                       */
/*****************************************************************************/
#define EEPROM_PAGE_SIZE    (16u)   // Page size in bytes

/*****************************************************************************/
/* Global constant declarations ('extern', definition & comment in C source) */
/*****************************************************************************/

/*****************************************************************************/
/* Global variable declarations ('extern', definition & comment in C source) */
/*****************************************************************************/

/*****************************************************************************/
/* Global function prototypes ('extern', definition & comment in C source)   */
/*****************************************************************************/
extern void BSP_EEP_Init(void);
extern void BSP_EEP_ReadData(uint32_t address, uint8_t* pU8Data, uint32_t data_length);
extern void BSP_EEP_WriteData(uint32_t u32Addr, const uint8_t* pu8Data, uint32_t data_length);
extern void BSP_EEP_Unlock(void);
extern void BSP_EEP_Lock(void);
extern boolean_t BSP_EEP_IsWriteInProcess(void);

#ifdef __cplusplus
}
#endif
#endif /* SOURCE_BSP_BSP_EEP_BSP_EEP_H_ */
