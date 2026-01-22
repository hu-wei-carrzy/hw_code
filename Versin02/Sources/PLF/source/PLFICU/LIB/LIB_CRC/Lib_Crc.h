/** 
	* @file Crc.h 
	* @brief CRC header file. 
	* @version V1.00.00 
	* @date 2015Äê5ÔÂ16ÈÕ 
	* @note  
	*/

#ifndef CRC_H_
#define CRC_H_

#include "ARCH_CFG.h"

#ifdef cHeadIncludeType_Directly
#include "deftypes.h"
#else
#include ".\..\LIB_API\deftypes.h"
#endif

#ifdef __cplusplus 
extern "C" 
{ 
#endif

/*****************************************************************************/
/* Global pre-processor symbols/macros ('#define')                           */
/*****************************************************************************/
#define CRC_16_STARTVAL             (0xFFFFu)


#define CRC_VENDOR_ID			    VENDOR_ID_JYD
#define CRC_MODULE_ID			    MODULE_ID_CRC
#define CRC_AR_MAJOR_VERSION  		1u
#define CRC_AR_MINOR_VERSION 		0u
#define CRC_AR_PATCH_VERSION		0u

#define CRC_SW_MAJOR_VERSION		1u
#define CRC_SW_MINOR_VERSION 		0u
#define CRC_SW_PATCH_VERSION		0u

/*****************************************************************************/
/* Global type definitions ('typedef')                                       */
/*****************************************************************************/


/*****************************************************************************/
/* Global function prototypes ('extern', definition & comment in C source) */
/*****************************************************************************/

extern U32 Crc_CalculateCRC32(const U8 *dataPtr, U32 len, U32 startVal );
extern U16 Crc_CalculateCRC16(	const U8* dataPtr, U32 len, U16 startVal );


#ifdef __cplusplus 
}
#endif
#endif /* CRC_H_ */
