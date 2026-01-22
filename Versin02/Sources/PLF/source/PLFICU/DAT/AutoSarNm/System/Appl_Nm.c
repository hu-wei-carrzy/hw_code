#include "Appl_Nm.h"
#include "CanNm_Cbk.h"
#include "Can.h"
#include "Nm_Cbk.h"
#include "CanNm.h"
#include "network_manage.h"
//#include "typedefs.h"
//#include "Dcm.h"
//#include "fault_process.h"
//#include "Appl_Desc.h"
//#include "os_timer.h"
//#include "dtc_report.h"

//uint8_t CANBus_Fault_Status = 0;
uint8_t nmStatusNMBusOffFlag;
uint8 nmStatusTxCfm = NM_BIT_CLEAR;
uint8 nmStatusErrRestoring = NM_BIT_CLEAR;

#ifdef _CHERY_COM
#ifdef _CHERY_COM_PLG
tD_NM_Userdata1 NM_Userdata1;
#endif
#ifdef _CHERY_COM_PD
tD_NM_Userdata0 NM_Userdata0;
tD_NM_Userdata3 NM_Userdata3;
#endif
#endif

static uint8_t nmStatusNMBusError = 0;
static uint8_t nubNmBusOffCnt = 0;
static uint8_t nmStatusSlowRecovery = 0;


CONST(nmTimerCntType,OSEKNM_CONFIG_CONST) 
    nmCountBusoffFastTimerAry[NM_NUMBER_OF_CHANNELS] = 
{
    100
};
CONST(nmTimerCntType,OSEKNM_CONFIG_CONST)  
    nmCountBusoffSlowTimerAry[NM_NUMBER_OF_CHANNELS] =
{
    1000
};
/*Fast Recover times*/
CONST(uint16,OSEKNM_CONFIG_CONST) 
    nmBusOffFastRecoveryAry[NM_NUMBER_OF_CHANNELS] =  
{
    5
};
/*Slow Recover times*/
CONST(uint16,OSEKNM_CONFIG_CONST) 
    nmBusOffSlowRecoveryAry[NM_NUMBER_OF_CHANNELS] =  
{
    255
};

/*******************************************************************************
* Name:        nmTimerCnt
* Description: NM Timer Counts.
* Values:      [0,0,0,0,0]
*******************************************************************************/
STATIC VAR(nmTimerCntType, OSEKNM_PRIVATE_DATA)
nmTimerCntTbusoffAry[NM_NUMBER_OF_CHANNELS] = {0};


/*indicate end of bus off error */
void ApplNmBusOffEnd(const nmIndexType nmChannelHandle)
{
    (void)nmChannelHandle;
    /*Add App code here*/
    Com_RxStart();
    Com_TxStart();
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NmSetAlarm
*
* Description:   Set the Counts into defaut values.
*
* Inputs:        nmAlarm
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, OSEKNM_PRIVATE_CODE) NmSetAlarm
(
    const nmIndexType nmCurChannel,
    const nmAlarmType nmAlarm
)
{
    switch(nmAlarm)
    {
        /*OsekNm_006*/
        case NM_FAST_TIMER_TBUSOFF:
            nmTimerCntTbusoff = NM_COUNT_FAST_TBUSOFF;
            break;

        /*OsekNm_006*/
        case NM_SLOW_TIMER_TBUSOFF:
            nmTimerCntTbusoff = NM_COUNT_SLOW_TBUSOFF;
            break;
        default :
            /* do nothing */
            break;

    }
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NmTerrTimeOutProc
*
* Description:   Carry out this event Function when Time-out Terr
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, OSEKNM_PRIVATE_CODE) NmTerrTimeOutProc
(
    const nmIndexType nmCurChannel
)
{
    nmStateType nmCurState_Par;
    
    /*Step 1: Get the current State*/
    nmCurState_Par = CanNm_State[nmCurChannel];
    /*Step 2: Carry Out the ralated Action*/
    if((nmCurState_Par != NM_STATE_UNINIT)/*&&(nmCurState_Par != NM_STATE_BUS_SLEEP)*/)
    {
        if(1 == nmStatusNMBusError )
        {
            nmStatusNMBusError = 0;
            /*clear CAN driver buffer*/
            CanIf_ClearTransmitBuffer(nmCurChannel);
            /*OsekNm_008 start*/
            if(1 == NM_EXTENDED_CALLBACK_ENABLE)
            {
                ApplNmBusOffEnd(nmCurChannel);
            }
            else
            {
                /* do nothing */
            }
            /* enable application communication (D_online) */
            CanIf_SetPduMode(nmCurChannel,CANIF_SET_TX_ONLINE);
            /*OsekNm_008 end*/
        }
        else
        {
            /*nothing to do*/
        }
	
       //(void)CanIf_Transmit(nmCurChannel,&CanNm_TxPdu[nmCurChannel]);
       CanIf_Transmit(CanNm_Config[nmCurChannel].CanNmTxPduRef,&CanNm_TxPdu[nmCurChannel]);

	
    }
            
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NmTbusOffRecoveryTimeOutProc
*
* Description:   BusOff recovery process
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
/*OsekNm_006*/
STATIC FUNC(void, OSEKNM_PRIVATE_CODE) NmTBusOffRecoveryTimeOutProc
(
    const nmIndexType nmCurChannel
)
{
    NmTerrTimeOutProc(nmCurChannel);
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NmTimerTTxCntFun
*
* Description:   bus-off timer function
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
/*OsekNm_006*/
STATIC FUNC(void, OSEKNM_PRIVATE_CODE) NmTimerTBusOffCntFun
(
    const nmIndexType nmCurChannel
)
{

    if(nmTimerCntTbusoff != 0)
    {
        nmTimerCntTbusoff--;

        if(0 == nmTimerCntTbusoff)
        {
            NmTBusOffRecoveryTimeOutProc(nmCurChannel);
        }
        else
        {
            /* do nothing */
        }
    }
    else
    {
        /* do nothing */
    }
}

/*indicates bus off error occured*/
void ApplNmBusOff(const nmIndexType nmChannelHandle)
{
    /*Stop Com Tx (and Rx)*/
    (void)nmChannelHandle;
    /*Add App code here*/
    Com_TxStop();
    
//    if((BusOff_Interim_Status!= BUSOFF_DETECTED)&&(gDTCSwitch == TRUE))
//    {
//      BusOff_Interim_Status = BUSOFF_DETECTED;
//      CANBus_Fault_Status = TRUE;
//      Msg_DCM_1_Confirmation = FALSE;
//    }
}

/*************************************************************/
void ApplNmCanBusOffRecoveryFail(const nmIndexType nmChannelHandle)
{
    (void)nmChannelHandle;
    /*Add App code here*/
	/*Bus Off recovery failed */
   /*Add App code here*/
}

void clearnubNmBusOffCnt(void)
{
   nubNmBusOffCnt   = 0;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NmBusErrorRecover
*
* Description:   Process the NM when BusOff.
*
* Inputs:        initMode
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, OSEKNM_PRIVATE_CODE) NmBusErrorRecover
(
    const nmIndexType nmCurChannel
)
{
    /*nmStateType nmNxtState_Par;*/
    nubNmBusOffCnt++;
    nmStatusErrRestoring = NM_BIT_SET;

    if((nubNmBusOffCnt <= NM_BUSOFF_FAST_RECOVERY_TIMES) && (0 == nmStatusSlowRecovery))
    {
        if(nubNmBusOffCnt == NM_BUSOFF_FAST_RECOVERY_TIMES)
        {
            /* 1:Fast recover will  try last one time,Slow recover will be processed*/
            nmStatusSlowRecovery = NM_BIT_SET;
            nubNmBusOffCnt = 0;
        }
        else
        {

        }

        NmSetAlarm(nmCurChannel, NM_FAST_TIMER_TBUSOFF);
        /*CallBack function, inform Application Bus off*/
        ApplNmBusOff(nmCurChannel);

    }
    else if(nubNmBusOffCnt <= NM_BUSOFF_SLOW_RECOVERY_TIMES)
    {
        /*OsekNm_006*/
        NmSetAlarm(nmCurChannel, NM_SLOW_TIMER_TBUSOFF);
        /*CallBack function, inform Application Bus off*/
        ApplNmBusOff(nmCurChannel);
    }
    else
    {
        nubNmBusOffCnt = 0;
        /*process fast recover first*/
        nmStatusSlowRecovery = NM_BIT_CLEAR;
        ApplNmCanBusOffRecoveryFail(nmCurChannel);
    }

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NmCanBusOffCheckFun
*
* Description:   bus-off
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, OSEKNM_PRIVATE_CODE) NmCanBusOffCheckFun
(
    const nmIndexType nmCurChannel
)
{
    uint16 BusOffFlg;
  
    BusOffFlg = nmStatusNMBusOffFlag;
    nmStatusNMBusOffFlag = NM_BIT_CLEAR;


    if(NM_BIT_SET == BusOffFlg)
    {
        CanIf_SetPduMode(nmCurChannel,CANIF_SET_TX_OFFLINE);

        nmStatusNMBusOffFlag = NM_BIT_CLEAR;
        nmStatusNMBusError = NM_BIT_SET;

        CanIf_ClearTransmitBuffer(nmCurChannel);
        Can_ResetController(nmCurChannel);	
        (void)CanIf_SetControllerMode(nmCurChannel,CANIF_CS_STARTED);
        /*Bus off recovery*/
        NmBusErrorRecover(nmCurChannel);

    }
    else
    {
        /*do nothing*/
    }
}


/*************************************************************/
/*This callback function is performed when busOff recovery successed.*/
void ApplNmBusOffRecoverySuccess(const nmIndexType nmChannelHandle)
{
    (void)nmChannelHandle;
    /*Add App code here*/
    
//    if(BusOff_Interim_Status == BUSOFF_DETECTED)
//    {
//      CANBus_Fault_Status = FALSE;
//    }
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Nm_TxCfm
*
* Description:   processing the case of transmiting message successfully.
*
* Inputs:        canNmTxPduId
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, OSEKNM_PUBLIC_CODE) NmTxCfmMainFunc
(
    const nmIndexType nmCurChannel
)
{
    uint16 TxCfmFlg;
    TxCfmFlg = nmStatusTxCfm;
    nmStatusTxCfm = NM_BIT_CLEAR;

    if(NM_BIT_SET == TxCfmFlg)
    {
            if(1 == nmStatusErrRestoring)
            {
                /*OsekNm_008*/
                nubNmBusOffCnt = 0;
                nmStatusSlowRecovery = NM_BIT_CLEAR;
                nmStatusErrRestoring = NM_BIT_CLEAR;
                if(1 == NM_EXTENDED_CALLBACK_ENABLE)
                {
                    ApplNmBusOffRecoverySuccess(nmCurChannel);
                }
            }
    }
}


/********************************************************************************
* Function Name: BusOff_MainFunction
*
* Description:   
*
* Inputs:        
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************/
void BusOff_MainFunction(void)
{   
    /*nmCurChannel = nmChannelHandle;*/
    nmIndexType nmCurChannel;
    
    for(nmCurChannel = 0;nmCurChannel < NM_NUMBER_OF_CHANNELS;nmCurChannel++)
    {    /*if inited,(1 == nmStatusChnInit) is syc with (STD_ON== NM_ACTIVE_SWITCH) */

            NmTxCfmMainFunc(nmCurChannel);
            /*used by OsekNm when Bus Off recovery*/
            NmTimerTBusOffCntFun(nmCurChannel);
            /*used by OsekNM when Can Bus Off*/
            NmCanBusOffCheckFun(nmCurChannel);
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: nmCanBusOff
*
* Description:   CanNm bus-off
*
* Inputs:        nmChannelHandle
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OSEKNM_PUBLIC_CODE) CanNm_BusOff
(
    const nmIndexType CanControllerId
)
{ 
    if(CanControllerId < NM_CANIF_USED_CONTROLLER_NUM)
    {
        nmStatusNMBusOffFlag = NM_BIT_SET;
    }
    else
    {

    }
}


void CAN_BusOffHook(uint8_t controlID)
{
    CanNm_BusOff(controlID);  
}

void CAN_WakeupHook(void)
{
	//CAN_Start();
}


void NM_Wakeup_Source_Monitor(void)
{
    uint8 sdu[6] ={0};	    

    #ifdef _CHERY_COM
    #ifdef _CHERY_COM_PLG
    sdu[1] = NM_Userdata1.Byte;
    #endif
    #ifdef _CHERY_COM_PD
    sdu[0] = NM_Userdata0.Byte;
    sdu[3] = NM_Userdata3.Byte;
    #endif
    #endif
   
#if(CANNM_PASSIVE_MODE_ENABLED == STD_OFF)
    CanNm_SetUserData(0,sdu);
#endif

}
