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

#include "Nm_Cbk.h"
#include "CanNm.h"
#include "CanIf.h"
#include "Com.h"

uint8 Network_Flag;

/*[SWS_CanNm_00092]*//*[SWS_CanNm_00093]*/
void Nm_NetworkMode
(
    NetworkHandleType nmNetworkHandle
)
{
    (void)nmNetworkHandle;

    CanIf_SetControllerMode(0,CANIF_CS_STARTED);

	Com_RxStart();
    //Com_TxStart();
}
/*[SWS_CanNm_00092]*//*[SWS_CanNm_00093]*/
void Nm_PrepareBusSleepMode
(
    NetworkHandleType nmNetworkHandle
)
{
    (void)nmNetworkHandle;

	Com_TxStop();
        //Com_RxStop(); /*Disable Specially for Chery T1A NM*/
}
void Nm_NetworkStartIndication
(
    NetworkHandleType nmNetworkHandle
)
{
	(void)nmNetworkHandle;

	Network_Flag = 1;

}
/*[SWS_CanNm_00092]*//*[SWS_CanNm_00093]*/
void Nm_BusSleepMode
(
    NetworkHandleType nmNetworkHandle
)
{
    (void)nmNetworkHandle;

    //CanIf_SetControllerMode(0,CANIF_CS_SLEEP);

}

/*[SWS_CanNm_00149]*/
#if(CANNM_PASSIVE_MODE_ENABLED == STD_OFF)
#if(CANNM_REMOTE_SLEEP_IND_ENABLED == STD_ON)
void Nm_RemoteSleepIndication
(
    NetworkHandleType nmNetworkHandle
)
{
    (void)nmNetworkHandle;
}
void Nm_RemoteSleepCancellation
(
    NetworkHandleType nmNetworkHandle
)
{
    (void)nmNetworkHandle;
}
#endif
#endif
/*[SWS_CanNm_00037]*/
#if(CANNM_PDU_RX_INDICATION_ENABLED == STD_ON)
void Nm_PduRxIndication
(
    NetworkHandleType nmNetworkHandle
)
{
    (void)nmNetworkHandle;
}
#endif
/*[SWS_CanNm_00166]*/
#if(CANNM_STATE_CHANGE_IND_ENABLED == STD_ON)
void Nm_StateChangeNotification
(
    NetworkHandleType nmNetworkHandle,
    Nm_StateType nmPreviousState,
    Nm_StateType nmCurrentState
)
{
    uint8 sdu[6]={0};
    (void)nmNetworkHandle;
    (void)nmPreviousState;
    
   // sdu[1] = nmCurrentState;
    
   /* if(NM_STATE_REPEAT_MESSAGE == nmCurrentState)
    {
        sdu[0] |= 0x01;
    }
    else
    {
        sdu[0] &= 0xfe;
    }
    
#if(CANNM_PASSIVE_MODE_ENABLED == STD_OFF)
    CanNm_SetUserData(0,sdu);
#endif*/
}
#endif

/*[SWS_CanNm_00073]*/
#if(CANNM_PASSIVE_MODE_ENABLED == STD_OFF)
#if(CANNM_IMMEDIATE_TXCONF_ENABLED == STD_OFF)
void Nm_TxTimeoutException
(
    NetworkHandleType nmNetworkHandle
)
{
    (void)nmNetworkHandle;
}
#endif
#endif
/*[SWS_CanNm_00014]*/
#if(CANNM_REPEAT_MSG_IND_ENABLED == STD_ON)
#if(CANNM_PASSIVE_MODE_ENABLED == STD_OFF)
#if(CANNM_NODE_DETECTION_ENABLED == STD_ON)
void Nm_RepeatMessageIndication
(
    NetworkHandleType nmNetworkHandle
)
{
    (void)nmNetworkHandle;
}
#endif
#endif
#endif

