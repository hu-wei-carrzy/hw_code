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

#ifndef NM_STACK_TYPES_H
#define NM_STACK_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"                                                                     /* Include standard types */
//#include "CanNm_Types.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/



/* Return values for NM functions */
#define NM_E_OK                       ((uint8)E_OK)      /* Function call has been successfully accomplished and
                                                            returned */
#define NM_E_NOT_OK                   ((uint8)E_NOT_OK)  /* Function call has been unsuccessfully accomplished and
                                                            returned because of an internal execution error.  */
#define NM_E_NOT_EXECUTED             ((uint8)2u)        /* Function call has been successfully accomplished and
                                                            returned since execution of a service in the current 
                                                            state is not allowed. */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/* Return type for NM functions */
typedef uint8 Nm_ReturnType;

/* State of the CanNm state machine */
typedef enum
{
  NM_STATE_UNINIT                 = 0u,   /* Uninitialized State */
  NM_STATE_BUS_SLEEP              = 1u,   /* Bus-Sleep State */
  NM_STATE_PREPARE_BUS_SLEEP      = 2u,   /* Prepare Bus-Sleep State */
  NM_STATE_READY_SLEEP            = 3u,   /* Ready Sleep State */
  NM_STATE_NORMAL_OPERATION       = 4u,   /* Normal Operation State */
  NM_STATE_REPEAT_MESSAGE         = 5u,   /* Repeat Message State */
  NM_STATE_SYNCHRONIZE            = 6u,   /* Synchronized State */
  NM_STATE_WAIT_CHECK_ACTIVATION  = 7u,   /* Wait Check Activation */
  NM_STATE_WAIT_NETWORK_STARTUP   = 8u    /* Wait Network Startup */
} Nm_StateType;
 
/* Modes of the network management state machine */
typedef enum
{
  NM_MODE_BUS_SLEEP           = 0u,   /* Bus-Sleep Mode */
  NM_MODE_PREPARE_BUS_SLEEP   = 1u,   /* Prepare Bus-Sleep Mode */
  NM_MODE_SYNCHRONIZE         = 2u,   /* Synchronized Mode */
  NM_MODE_NETWORK             = 3u    /* Network Mode */
} Nm_ModeType;




#endif  /* NM_STACK_TYPES_H */
