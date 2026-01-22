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
#include "Bsw_Common.h"

#define BSW_START_SEC_CODE
//#include "MemMap.h"

/*******************************************************************************
*   Functions 
*******************************************************************************/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Bsw_MemCpy  
*                
* Description:   This service copy data from src to dest  
*
* Inputs:        dest, src, size
*                
* Outputs:       None
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSW_CODE) Bsw_MemCpy
(
    CONSTP2VAR(uint8, AUTOMATIC,BSW_APPL_DATA) dest,
    CONSTP2CONST(uint8, AUTOMATIC,BSW_APPL_DATA) src, 
    const uint32 size
)
{
    uint32 i;
    
    for(i = 0; i < size; i++)
    {
        dest[i] = src[i];
    }
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Bsw_MemSet  
*                
* Description:   This service set fix data to  dest  
*
* Inputs:        dest, src, size 
*                
* Outputs:       None
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSW_CODE) Bsw_MemSet
(
    CONSTP2VAR(uint8, AUTOMATIC,BSW_APPL_DATA) dest,
    const uint8 src,
    const uint32 size
)
{
    uint32 i;
    
    for(i = 0; i < size; i++)
    {
        dest[i] = src;
    }
}

#define BSW_STOP_SEC_CODE
//#include "MemMap.h"






