/*  BEGIN_FILE_HDR
************************************************************************************************
*   NOTICE                              
*   This software is the property of HiRain Technologies. Any information contained in this 
*   doc should not be reproduced, or used, or disclosed without the written authorization from 
*   HiRain Technologies.
************************************************************************************************
*   File Name       : App_Boot.c
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
************************************************************************************************
* END_FILE_HDR*/
#include "App_Boot.h"
//#include "bl_typedefs.h"
typedef unsigned char   U8;
typedef unsigned char   U1;
typedef signed   char   S8;
typedef unsigned short  U16;
typedef signed   short  S16;
typedef unsigned long   U32;
typedef signed   int   S32;


static void Boot_SetFlag(U8 flagId);
static void Boot_Reset(void);
static void Boot_MemSet(U32 * des, U32 src);

/* BEGIN_FUNCTION_HDR
************************************************************************************************
* Function Name : Boot_ReprogramCallBack
*
* Description   : Set the reprogramming flag and reset the ECU.
*
* Inputs        : none
*
* Outputs       : none
* 
* Limitations   : Only for Bootloader
*                 
************************************************************************************************
END_FUNCTION_HDR */
void Boot_ReprogramCallBack(void)
{
    /*set reprogram flag*/
    Boot_SetFlag(FLAG_REPROGRAM_ID);
    /*reset ECU*/
    Boot_Reset();
}


//2018年2月1日 16:02:36
//zjb
//新加一个函数接口，只设置跳转标志，不执行具体的复位动作
//具体的复位动作由其它函数实现。解决连续下载时，屏幕变黑
//的问题
void Boot_SetFlagCallBack(void)
{
    /*set reprogram flag*/
    Boot_SetFlag(FLAG_REPROGRAM_ID);
}

/* BEGIN_FUNCTION_HDR
************************************************************************************************
* Function Name : Boot_SetFlag
*
* Description   : Set the reprogramming flag.
*
* Inputs        : none
*
* Outputs       : none
* 
* Limitations   : Only for Bootloader
*                 
************************************************************************************************
END_FUNCTION_HDR */

static void Boot_SetFlag(U8 flagId)
{
    U32 addr = 0xFFFFFFFFUL;
    U32 data = 0xFFFFFFFFUL;

    if(flagId == FLAG_REPROGRAM_ID)
    {
    	// jy add 修改进入loader的地址。 20190221
        addr = FLAG_REPROGRAM_ADDR;
        data = FLAG_REPROGRAM_DATA;
    }

      if (addr != 0xFFFFFFFFUL)
      {
            Boot_MemSet((U32*)addr,data);
      }
}

/* BEGIN_FUNCTION_HDR
************************************************************************************************
* Function Name : Boot_MemSet
* Description   : This function is used for copying data.
*                  
* Inputs        : none
* 
* Outputs       : none
* 
* Limitations   :  
*                                  
************************************************************************************************
END_FUNCTION_HDR */
static void Boot_MemSet(U32 * des, U32 src)
{
    if (des != ((void *)0) )
    {  
        *des = src;
    }

    return ;
}


/* BEGIN_FUNCTION_HDR
************************************************************************************************
* Function Name : Boot_Reset
*
* Description   : Reset the ECU.
*
* Inputs        : none
*
* Outputs       : none
* 
* Limitations   : Only for Bootloader
*                 
************************************************************************************************
END_FUNCTION_HDR */


static void Boot_Reset(void)
{
    Wdg_FastReset();

}

