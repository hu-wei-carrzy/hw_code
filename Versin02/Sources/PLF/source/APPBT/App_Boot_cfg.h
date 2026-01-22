/*  BEGIN_FILE_HDR
************************************************************************************************
*   NOTICE                              
*   This software is the property of HiRain Technologies. Any information contained in this 
*   doc should not be reproduced, or used, or disclosed without the written authorization from 
*   HiRain Technologies.
************************************************************************************************
*   File Name       : App_Boot_cfg.h
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
*
************************************************************************************************
* END_FILE_HDR*/
#ifndef __APP_BOOT_CFG_H__
#define __APP_BOOT_CFG_H__

//#include "bl_ram.h"
#include "bl_watchdog.h"
/*****************************************************************************
 *  Type Declarations
 *****************************************************************************/
typedef unsigned char  bl_u8_t;      /**< This is a unsigned type for 8 bits.*/
typedef unsigned short bl_u16_t;    /**< This is a unsigned type for 16 bits.*/
typedef unsigned long  bl_u32_t;     /**< This is a unsigned type for 32 bits.*/

#define CAN_TX_ID                 0x18DAF13DU

#define FLAG_REPROGRAM_ID         0x01U
#define FLAG_RESET_ID             0x02U
#define FLAG_FINGERPRINT_ID       0x03U

#define FLAG_BASE_SIZE            0x04U


#define FLAG_REPROGRAM_ADDR        (0x40000000)
#define FLAG_RESET_ADDR            (0x40000010)
#define FLAG_FINGERPRINT_ADDR      (0xFFFFFFFF)

#define FLAG_REPROGRAM_DATA        0xA5A5A5A5UL
#define FLAG_RESET_DATA            0x55555555UL

#define ResetMCUHandle()                         Wdg_FastReset()
#if 0
#define FlagReadHandle(addr,size,buf)            Ram_Read(addr,size,buf)
#define FlagWriteHandle(addr,size,buf)           Ram_Write(addr,size,buf)
#define Boot_ComControlHandle()                  ComControl()
#define Boot_CheckProgramming()                  CheckProgramming()
#endif


extern void Boot_SendSFCanMsg(bl_u8_t * data,bl_u8_t size,bl_u16_t canId);


#endif /*__APP_BOOT_CFG_H__*/
