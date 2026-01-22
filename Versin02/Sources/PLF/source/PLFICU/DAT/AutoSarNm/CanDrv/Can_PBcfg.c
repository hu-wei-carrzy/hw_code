/*BEGIN_FILE_HDR
*********************************************************************************
*   NOTICE                              
*   This software is the property of HiRain Technologies. Any information 
*   contained in this doc should not be reproduced, or used, or disclosed 
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : Can_PBcfg.c
*
********************************************************************************
*   Project/Product : AUTOSAR 4.0
*   Title           : CAN Driver(MSCAN) module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : This file contains the post-build time configurable 
*                     parameters of CAN Driver                       
*
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
********************************************************************************
*   Revision History:
* 
*   Version     Date          Initials      CR#          Descriptions
*   ---------   ----------    ------------  ----------   ---------------
*   01.00.00    24/07/2013    wenrui.li    N/A          Original
*
********************************************************************************
* END_FILE_HDR*/


/*******************************************************************************
*   Includes 
*******************************************************************************/
#include "Can.h"
#include "Can_Cfg.h"   //add by zjb
#include "Can_Pl.h"    //add by zjb

/*******************************************************************************
*   Config Parameters   
*******************************************************************************/
#define CAN_START_SEC_CONFIG_DATA_UNSPECIFIED
//#include "MemMap.h"
//#include ".\..\J1939_INCLUDE\MemMap_Proxy.h"

CONST(uint8, CAN_CONFIG_CONST) CanControllerIDtoPhys[CAN_USED_CONTROLLER_NUM]=
{
    #if (CAN_USED_CONTROLLER_NUM >= 1)
        0,
    #endif
    #if (CAN_USED_CONTROLLER_NUM >= 2)
        1,
    #endif
};


CONST(Can_RegInitType, CAN_CONFIG_CONST) CanRegInit[CAN_USED_CONTROLLER_NUM] =
{
//    #if (CAN_USED_CONTROLLER_NUM >= 1)
//    {
//        0x00u,
//        CANE|CAN0_CLKSRC_CFG|BORM,
//        0x01u,           /*8M 500K 0x01;16M 0x03*/
//        0x14u,
//        CAN0_WAKEUP_INT_CFG|CAN0_BUSOFF_INT_CFG|CAN0_RX_INT_CFG|CSCIE,
//        CAN0_TX_INT_CFG,
//
//        0x10u,
//
//        0x43u,      /*CanInitIDAR0;*/
//        0x00u,      /*CanInitIDAR1;*/
//        0xf4u,      /*CanInitIDAR2;*/
//        0x00u,      /*CanInitIDAR3;*/
//
//        0xffu,      /*CanInitIDMR0*/
//        0xffu,      /*CanInitIDMR1*/
//        0xffu,      /*CanInitIDMR2*/
//        0xffu,      /*CanInitIDMR3*/
//
//        0xe0u,      /*CanInitIDAR4;*/
//        0x60u,      /*CanInitIDAR5;*/
//        0x90u,      /*CanInitIDAR6;*/
//        0x20u,      /*CanInitIDAR7;*/
//
//        0xffu,      /*CanInitIDMR4*/
//        0xffu,      /*CanInitIDMR5*/
//        0xffu,      /*CanInitIDMR6*/
//        0xffu,      /*CanInitIDMR7*/
//
//    },
//    #endif
//    #if (CAN_USED_CONTROLLER_NUM >= 2)
//    {
//        0x00u,
//        CANE|CAN1_CLKSRC_CFG|BORM,
//        0x01u,           /*8M 500K 0x01;16M 0x03*/
//        0x14u,
//        CAN1_WAKEUP_INT_CFG|CAN1_BUSOFF_INT_CFG|CAN1_RX_INT_CFG|CSCIE,
//        CAN1_TX_INT_CFG,
//
//        0x10u,
//
//        0x43u,      /*CanInitIDAR0;*/
//        0x00u,      /*CanInitIDAR1;*/
//        0xf4u,      /*CanInitIDAR2;*/
//        0x00u,      /*CanInitIDAR3;*/
//
//        0xffu,      /*CanInitIDMR0*/
//        0xffu,      /*CanInitIDMR1*/
//        0xffu,      /*CanInitIDMR2*/
//        0xffu,      /*CanInitIDMR3*/
//
//        0xe0u,      /*CanInitIDAR4;*/
//        0x60u,      /*CanInitIDAR5;*/
//        0x90u,      /*CanInitIDAR6;*/
//        0x20u,      /*CanInitIDAR7;*/
//
//        0xffu,      /*CanInitIDMR4*/
//        0xffu,      /*CanInitIDMR5*/
//        0xffu,      /*CanInitIDMR6*/
//        0xffu,      /*CanInitIDMR7*/
//    },
//    #endif
};

//这个数组如果使用CANDriver驱动，就有意义，如果没买就没有意义，并且会给集成带来干扰。
//然后，还要自己实现这个数组，
CONST(Can_HardwareObjectConfigType, CAN_CONFIG_CONST)
                                     CanHardwareObjectConfig[CAN_USED_HOH_NUM] =
{
//   {
//        /* CanObjectId0*/
//        0,  //这个是ControlRef，是个逻辑通道号。如果添加了多个通道，这个值还人修改。修改原则是：这个报文是哪个通道，就改成哪个通道号
//        0, //一个Can_HardwareObjectConfigType元素就是一个报文，这个报文是定义DBC中的，且在Driver有映射。但是没有买Driver
//        CAN_HOH_RX_MASK|CAN_HOH_BASIC_MASK,
//    },
//   {//全部将第一个元素都改正为0
//        /* CanObjectId1*/
//        0,
//        0,
//        CAN_HOH_RX_MASK|CAN_HOH_BASIC_MASK,
//    },
//   {
//        /* CanObjectId2*/
//        0,
//        0,
//        CAN_HOH_TX_MASK|CAN_HOH_BASIC_MASK,
//    },
//   {
//        /* CanObjectId3*/
//        0,
//        1,
//        CAN_HOH_TX_MASK|CAN_HOH_BASIC_MASK,
//    },
//   {
//        /* CanObjectId4*/
//        0,
//        2,
//        CAN_HOH_TX_MASK|CAN_HOH_BASIC_MASK,
//    },
//    {
//        /* CanObjectId5*/
//        0,
//        0,
//        CAN_HOH_TX_MASK|CAN_HOH_BASIC_MASK,
//    },
//   {
//        /* CanObjectId6*/
//        0,
//        1,
//        CAN_HOH_TX_MASK|CAN_HOH_BASIC_MASK,
//    },
//   {
//        /* CanObjectId7*/
//        0,
//        2,
//        CAN_HOH_TX_MASK|CAN_HOH_BASIC_MASK,
//    },
//
//	{
//		/* CanObjectId8*/
//		0,
//		1,
//		CAN_HOH_TX_MASK|CAN_HOH_BASIC_MASK,
//   },
//
//	{
//		/* CanObjectId9*/
//		0,
//		2,
//		CAN_HOH_TX_MASK|CAN_HOH_BASIC_MASK,
//  },
//  {
//		/* CanObjectId10*/
//		0,
//		3,
//		CAN_HOH_TX_MASK|CAN_HOH_BASIC_MASK,
//  },
//  {
//		/* CanObjectId11*/
//		0,
//		4,
//		CAN_HOH_TX_MASK|CAN_HOH_BASIC_MASK,
//  },
};

CONST(Can_HwHandleType, CAN_CONFIG_CONST)
                                 CanControllerIDtoHRH[CAN_USED_CONTROLLER_NUM] =
{
    0,
    1,
};

#define CAN_STOP_SEC_CONFIG_DATA_UNSPECIFIED
//#include "MemMap.h"
//#include ".\..\J1939_INCLUDE\MemMap_Proxy.h"
