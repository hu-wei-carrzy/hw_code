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

#ifndef _CANNM_CALLOUT_H_
#define _CANNM_CALLOUT_H_

/*******************************************************************************
*   Includes 
*******************************************************************************/
#include "CanNm_Lcfg.h"

#define CANNM_START_SEC_CODE
//#include "MemMap.h"

extern FUNC(void, CANNM_CODE) CanNm_SetUserDataCall
(
    P2VAR(uint8, AUTOMATIC, CANNM_APPL_DATA) dataBuffPtr,
    P2CONST(uint8, AUTOMATIC, CANNM_APPL_DATA) nmUserDataPtr
);


extern FUNC(void, CANNM_CODE) CanNm_GetUserDataCall
(
    P2CONST(uint8, AUTOMATIC, CANNM_APPL_DATA) dataBuffPtr,
    P2VAR(uint8, AUTOMATIC, CANNM_APPL_DATA) nmUserDataPtr
);


#define CANNM_STOP_SEC_CODE
//#include "MemMap.h"

#endif

