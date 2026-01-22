/**************************************************************************//**
 *
 *  \copyright  This software is the property of HiRain Technologies. Any
 *              information contained in this doc should not be reproduced,
 *              or used, or disclosed without the written authorization from
 *              HiRain Technologies.
 *
 *  \brief      This is the source file of the watchdog module for mpc5643l.
 *
 *  \file       bl_watchdog.c
 *  \ingroup    driver_module
 *  \author     lele.liu <lele.liu@hirain.com>
 *
 *  \version    1.0.0
 *  \date       11/08/2015
 *
 *  \par        Changelist
 *      Version  | Date       | Authors          | CR# | Descriptions
 *      -------- | ---------- | ---------------- | --- | -------------
 *      01.00.00 | 11/08/2015 | lele.liu         | N/A | BootDrv010001
 *
 *****************************************************************************/
#include "bl_watchdog.h"
typedef unsigned char   U8;
typedef unsigned char   U1;
typedef signed   char   S8;
typedef unsigned short  U16;
typedef signed   short  S16;
typedef unsigned long   U32;
typedef signed   int   S32;


extern void LDBRefreshWatchDog(void);
extern void BSPRstRriggerSWReset(void);
/*****************************************************************************
 *  Internal Macro Definitions
 *****************************************************************************/
#define WDG_TIMEOUT_VALUE  32000u /* 250ms */

#define	WDG_EN  	0x01ul/* WDG enable bit*/
#define	WDG_FRZ  	0x02ul/* wdg stop in debug mode*/
#define	WDG_STP  	0x04ul/* wdg stop in stop mode*/
#define	WDG_CSL  	0x08ul/* system or osc clock for wdg ,only osc canbe used in 5604b*/ 
#define	WDG_WND    	0x80ul/* window watchdog enable*/
#define	WDG_ITR  	0x40ul/* wdg interrupt enable*/ 
#define WDG_HLK	    0x20ul/* hardware lock bit */
#define WDG_SLK		0x10ul/* software lock bit */
#define WDG_RIA		0x100ul/* Reset on Invalid Access */

/*****************************************************************************
 *  Function Definitions
 *****************************************************************************/
/**************************************************************************//**
 *
 *  \details Initialize watchdog module.
 *
 *  \return None.
 *
 *  \since V2.0.0
 *
 *****************************************************************************/
void Wdg_Init(void)
{

}

/**************************************************************************//**
 *
 *  \details Start watchdog module.
 *
 *  \return None.
 *
 *  \since V2.0.0
 *
 *****************************************************************************/
void Wdg_Start(void)
{

}

/**************************************************************************//**
 *
 *  \details Reset watchdog module.
 *
 *  \return None.
 *
 *  \since V2.0.0
 *
 *****************************************************************************/
void Wdg_FastReset(void)
{

	BSPRstRriggerSWReset();
	for(;;)
	{
		
	}

}

/**************************************************************************//**
 *
 *  \details Deinitialize watchdog module.
 *
 *  \return None.
 *
 *  \since V2.0.0
 *
 *****************************************************************************/
void Wdg_Deinit(void)
{

}

/**************************************************************************//**
 *
 *  \details Feed watchdog.
 *
 *  \return None.
 *
 *  \since V2.0.0
 *
 *****************************************************************************/
void Wdg_Feed(void)
{
   LDBRefreshWatchDog();
}


























