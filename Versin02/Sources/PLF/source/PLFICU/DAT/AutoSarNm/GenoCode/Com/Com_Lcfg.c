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
#include "Com.h"

#define COM_START_SEC_PUBLIC_CODE 
//#include "MemMap.h"


#define COM_STOP_SEC_CONFIG_DATA_UNSPECIFIED 
//#include "MemMap.h"

#if (COM_TXSIGNUM >= 1u)
CONST(Com_SendSignalType, COM_CONFIG_CONST) Com_SendSignalTable[COM_TXSIGNUM] =
{
   NULL_PTR
};
#endif

#if (COM_RXIPDUNUM >= 1u)
CONST(Com_ReceiveSignalType, COM_CONFIG_CONST) Com_ReceiveSignalTable[COM_RXSIGNUM] =
{
   NULL_PTR
};
#endif
