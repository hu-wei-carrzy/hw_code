/*  BEGIN_FILE_HDR
************************************************************************************************
*   NOTICE                              
*   This software is the property of HiRain Technologies. Any information contained in this 
*   doc should not be reproduced, or used, or disclosed without the written authorization from 
*   HiRain Technologies.
************************************************************************************************
*   File Name       : App_Boot.h
************************************************************************************************
*   Project/Product : Bootloader
*   Title           : Timer module Source File
*   Author          : Na.hu
************************************************************************************************
*   Description     : This file is used to implement the callback function.
*
************************************************************************************************
*   Limitations     : Only for HiBoot
*
************************************************************************************************
*
************************************************************************************************
*   Revision History:
* 
*   Version     Date          Initials      CR#                    Descriptions
*   ---------   ----------    ------------  ----------             ---------------
*   1.0         2012/10/4    Na.hu        N/A                    Original
*   1.1         2018/02/01  Jiangbo.zhao N/A                add a new function for only setting flag
*
************************************************************************************************
* END_FILE_HDR*/
#ifndef __APP_BOOT_H__
#define __APP_BOOT_H__


/*****************************************************************************
 * Macro Configuration
 *****************************************************************************/
//the following macros are for CAN¡¡UDS
#define FLAG_REPROGRAM_ID       (0x01u)
#define FLAG_REPROGRAM_ADDR     (0x20006C00UL)
#define FLAG_REPROGRAM_DATA     (0xA5A5A5A5UL)
#define FLAG_REPROGRAM_SIZE     (0x04u)

//The following macros are for UART UDS
//there are 8bytes flags for UART UDS loader.
#define FLAG_UART_REPROGRAM_ID       (0x02u)
#define FLAG_UART_REPROGRAM_ADDR_1     (0x20006C08UL)
#define FLAG_UART_REPROGRAM_DATA_1     (0xA5A5A5A5UL)
#define FLAG_UART_REPROGRAM_SIZE_1     (0x04u)

#define FLAG_UART_REPROGRAM_ADDR_2     (0x02000000+14UL)
#define FLAG_UART_REPROGRAM_DATA_2     (0xA5A5A5A5UL)
#define FLAG_UART_REPROGRAM_SIZE_2     (0x04u)

/*****************************************************************************
 * Macro Definitions
 *****************************************************************************/



/*****************************************************************************
 *  External Function Prototype Declarations
 *****************************************************************************/
extern void Boot_ReprogramCallBack(void);
extern void Boot_SetFlagCallBack(void);

extern void Wdg_FastReset(void);

#endif /* __APP_BOOT_H__ */
