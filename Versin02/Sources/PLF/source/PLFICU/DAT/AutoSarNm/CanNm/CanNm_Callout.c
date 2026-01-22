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


/*******************************************************************************
*   Includes 
*******************************************************************************/
#include "CanNm_Callout.h"
//#include "Bsw_Common.h"

#define CANNM_USER_DATA_LENGTH                 ((uint8)6u)

#define CANNM_START_SEC_CODE
//#include "MemMap.h"

FUNC(void, CANNM_CODE) CanNm_SetUserDataCall
(
    P2VAR(uint8, AUTOMATIC, CANNM_APPL_DATA) dataBuffPtr,
    P2CONST(uint8, AUTOMATIC, CANNM_APPL_DATA) nmUserDataPtr
)
{
    Bsw_MemCpy(&dataBuffPtr[(CANNM_PDU_LENGTH - CANNM_USER_DATA_LENGTH)], nmUserDataPtr,
               CANNM_USER_DATA_LENGTH);
}


FUNC(void, CANNM_CODE) CanNm_GetUserDataCall
(
    P2CONST(uint8, AUTOMATIC, CANNM_APPL_DATA) dataBuffPtr,
    P2VAR(uint8, AUTOMATIC, CANNM_APPL_DATA) nmUserDataPtr
)
{
    Bsw_MemCpy(nmUserDataPtr, &dataBuffPtr[(CANNM_PDU_LENGTH - CANNM_USER_DATA_LENGTH)], 
               CANNM_USER_DATA_LENGTH);
}


#define CANNM_STOP_SEC_CODE
//#include "MemMap.h"
