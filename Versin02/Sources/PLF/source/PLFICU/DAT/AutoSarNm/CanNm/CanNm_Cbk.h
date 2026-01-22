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

#ifndef _CANNM_CBK_H_
#define _CANNM_CBK_H_


/*******************************************************************************
*   Includes
*******************************************************************************/
#include "CanNm_Types.h"
/**********************************************************************************************************************
* Functions
*********************************************************************************************************************/
#define CANNM_START_SEC_CODE
//#include "MemMap.h"

/*[SWS_CanNm_00284]*/
#if(CANNM_IMMEDIATE_TXCONF_ENABLED == STD_OFF)
/*[SWS_CanNm_00228]*/
extern FUNC(void, CANNM_CODE) CanNm_TxConfirmation
(
    PduIdType TxPudId
);
#endif

/*[SWS_CanNm_00231]*/
extern FUNC(void, CANNM_CODE) CanNm_RxIndication 
(
    PduIdType RxPudId,
    const uint16 RxId,
    P2CONST(PduInfoType, AUTOMATIC, CANNM_APPL_DATA)PduInfoPtr 
);
#define CANNM_STOP_SEC_CODE
//#include "MemMap.h"

#endif/*_CANNM_CBK_H_*/

