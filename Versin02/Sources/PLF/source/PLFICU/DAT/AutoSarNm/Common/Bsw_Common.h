/*<WLEGHead>
|---------------------------------------------------------------------------------------------
| Project Name:     SAIC MIFA PLG
| File Name:       
|
|  Description:     
|
|---------------------------------------------------------------------------------------------
|                          All rights reserved
|---------------------------------------------------------------------------------------------
|
|                            CONFIDENTIAL
|
|
|---------------------------------------------------------------------------------------------
|                       R E V I S I O N   H I S T O R Y
|---------------------------------------------------------------------------------------------
| Date        Version   Author  Description
|                               Why                 What
| --------------------------------------------------------------------------------------------
| 02-12-2016  01.00      William Wei     Creation            First Version      
|---------------------------------------------------------------------------------------------
<WLEGHead>*/

#ifndef _BSW_COMMON_H_
#define _BSW_COMMON_H_
/*******************************************************************************
 *   Includes 
 *******************************************************************************/
#include "Std_Types.h"

#define BSW_START_SEC_CODE
//#include "MemMap.h"
/*******************************************************************************
 *   Declare 
 *******************************************************************************/
extern FUNC(void, BSW_CODE) Bsw_MemCpy(
CONSTP2VAR(uint8, AUTOMATIC,BSW_APPL_DATA) dest,
CONSTP2CONST(uint8, AUTOMATIC,BSW_APPL_DATA) src,
const uint32 size
);
extern FUNC(void, BSW_CODE) Bsw_MemSet(
CONSTP2VAR(uint8, AUTOMATIC,BSW_APPL_DATA) dest,
const uint8 src,
const uint32 size
);
#define BSW_STOP_SEC_CODE
//#include "MemMap.h"

#endif
