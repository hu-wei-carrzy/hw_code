/*********************************************************************************************
** Header Files
*********************************************************************************************/
//#include "task_schedule.h"
#include "typedefs.h"
#include "os_timer.h"
#include "system_control.h"
#include "system_calibration.h"
//#include "project_calibration.h"
//#include "com_calibration.h"
//#include "speed_control.h"
//#include "obstacle_detect.h"
//#include "fault_process.h"
//#include "request_process.h"
#include "api_interface.h"
//#include "pinout_manage.h"
//#include "r_cg_taub.h"
//#include "r_cg_taud.h"
//#include "BTN8962.h"
//#include "BTS5030.h"
//#include "VNH7040.h"
//#include "Sbc_Tle9263.h"
//#include "Sbc_Tle9562.h"
//#include "r_cg_tauj.h"
//#include "r_cg_adc.h"
//#include "r_cg_wdt.h"
//#include "sleep_manage.h"
//#include "spindle_control.h"
#include "message_process.h"
#include "network_manage.h"
#include "network_manage.h"
#include "S32K144Types.h"

#ifdef _INGIN_AUTOSAR_NM
#include "Nm_Cbk.h"
#include "CanNm.h"
#include "CanNm_Lcfg.h"
#include "Appl_Nm.h"
#endif

#ifdef _CONFIG_LIN_Slave
#include "lin_schedule.h"
#include "lin_appl.h"
#endif

#ifdef _CONFIG_LIN_Master
#include "lin.h"
#endif

#ifdef _CONFIG_CAN_Bus
#include "CAN.h"
#include "Platform_Types.h"
#include "Comstack_Types.h"
#include "CanIf.h"
//#include "Appl_Proc.h"

#ifdef _INGIN_STACK
#include "Com_Cfg.h"
#include "Com.h"
//#include "CanTp_Cfg.h"
//#include "CanTp.h"
//#include "Dcm.h"
//#include "CanIf_Type.h"
//#include "CAN_Drv.h"
  #ifdef _AUDI_COM
#include "AppDesc_Cfg.h"
  #endif
#endif

#ifdef _VECTOR_STACK
#include "NmStack_Types.h"
#include "CanNm_Cfg.h"
#include "AppDesc_Cfg.h"
#endif

#ifdef _OSEK_NM
#include "OsekNm.h"
#endif
#endif

// #include "../../DAT/DAT_BSDC/DAT_BSDC_DATAEXPORT.h"
// #include "./../../DAT/DAT_BSDC/DAT_BSDC.h"
// #include "./../../DAT/DAT_BSDC/DAT_BSDC_INCLUDE.h"

/*********************************************************************************************
** Global Variables Definitions
*********************************************************************************************/
uint8_t NM_WakeupFromBusSleep_Status;
uint8_t Network_Sleep_Flag;
uint8_t NM_NMRemoteEvent_NetworkRequest_Status;

#ifdef _SGMW_NM
/*SGMWNM*/
tD_SGMWNM_State Current_SGMWNM_State;
tD_SGMWNM_State Last_SGMWNM_State;
#endif

tD_NM_Source NM_EventSource;
tD_NM_Source NM_WakeupSource;


uint8_t App_RxIndication_Status;
uint8_t NM_RxIndication_Status;
uint8_t UDS_RxIndication_Status;
uint8_t NM_RxIndication_Status_For_WakeupFromPrepareBusSleepOnly;

uint8_t NM_LocalEvent_Status;
uint8_t NM_LocalEvent_LastStatus;
uint8_t NM_LocalEvent_RiseEdge_Active;
uint8_t NM_LocalEvent_FallEdge_Active;

uint8_t NM_RemoteEvent_Status;
uint8_t NM_RemoteEvent_LastStatus;
uint8_t NM_RemoteEvent_RiseEdge_Active;
uint8_t NM_RemoteEvent_FallEdge_Active;


uint8_t CAN_Tx_Start_Status;
uint8_t CAN_Rx_Start_Status;

uint8_t CAN_Tx_Stop_Status;

uint16_t NM_Continue_Message_Timer;

/*AutosarNM*/
uint8_t CanNm_NetworkRelease_Status;
uint8_t CanNm_NetworkRequest_Status;

uint8_t NM_LocalEvent_Ind;
uint8_t NM_RemoteEvent_Ind;

uint8_t Flag_LocalEvent;
uint8_t Flag_RemoteEvent;
/*OsekNM*/
uint8_t CanNm_Start_Status;
uint8_t CanNm_Stop_Status;
uint8_t CanNm_GotoAwake_Status;
uint8_t CanNm_GotoSleep_Status;

uint8_t NM_AnyRx_ISR_Status;

uint8_t NM_CAN_Initialization_Status;
uint8_t NM_BusOffRecoveryMsgSend_Status;

uint8_t Send_NM_Initialize_BusOffDelay_Status;
uint16_t Send_NM_Initialize_BusOffDelay_Timer;

uint8_t Com_TxStart_Request_Status;
uint16_t Com_TxStart_Request_Timer;
uint8_t Com_TxStart_Start_Status;

uint8_t NM_LocalEvent_Delay_Status;
uint32_t NM_LocalEvent_Delay_Timer;

#ifdef _INGIN_AUTOSAR_NM
VAR(Nm_StateType, CANNM_VAR_NOINIT) CanNm_LastState[CANNM_NUMBER_OF_CHANNELS];
VAR(Nm_StateType, CANNM_VAR_NOINIT) CanNm_PreState[CANNM_NUMBER_OF_CHANNELS];
#endif

#ifdef _CONFIG_NMRemoteEvent_NetworkRequest
uint8_t NMRemoteEvent_NetworkRequest_Status;
uint8_t NM_RemoteEvent_Start_Status;
uint8_t NM_RemoteEvent_Start_Timer;
#define K_NM_RemoteEvent_Start_Time 1
#endif

#ifdef _CONFIG_LIN_Master
uint8_t LIN_Schedule_Null_Status;
uint8_t LIN_Schedule_Null_Timer;
uint8_t LIN_GoToSleep_Delay_Status;
uint8_t LIN_GoToSleep_Delay_Timer;
#endif

test_mag_c test_mag; 

/*********************************************************************************************
** Variables at File Scope
*********************************************************************************************/


/*********************************************************************************************
** Functions with Global Scope
*********************************************************************************************/

void PE10ms_Network_Manage_Master(void);
void Network_Manage_Init(void);

void CAN_Tx_Stop(void);
void CAN_Sleep(void);
void CAN_Start(void);
void CAN_Rx_Start(void);
void CAN_Tx_Start(void);
void CAN_Stop(void);


/*********************************************************************************************
** Functions with Local Scope
*********************************************************************************************/

static void NetworkManage_Monitor(void);

static void NM_RemoteEvent_Monitor(void);
static void NM_LocalEvent_Monitor(void);
static void NM_AfterWakeup_Clear(void);
static void NM_NetWakeupSource_Monitor(void);
static void NM_EventSource_Clear(void);

static void NM_Userdata_Monitor(void);
/*********************************************************************************************
** Name:	  Network_Manage_Init
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void Network_Manage_Init(void)
{

}


/*********************************************************************************************
** Name:	  PE10ms_Network_Manage_Master
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
void PE10ms_Network_Manage_Master(void)
{     
     NM_RemoteEvent_Monitor();
     NM_LocalEvent_Monitor();
     
     NM_AfterWakeup_Clear();
     NM_NetWakeupSource_Monitor();
     NM_EventSource_Clear();

     #ifdef _INGIN_AUTOSAR_NM
     NetworkManage_Monitor();
     #endif
     
     NM_Userdata_Monitor();

}

/*********************************************************************************************
** Name:	  NM_AfterWakeup_Clear
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
static void NM_AfterWakeup_Clear(void)
{
    static uint16_t NM_AfterWakeup_Timer = 0;
    
    /*NM_AfterWakeup_Status Clear*/
    if(TRUE == NM_AfterWakeup_Status)
    {
	 if(NM_AfterWakeup_Timer >= K_NM_AfterWakeup_Time)
	 {		 
	     NM_AfterWakeup_Status = FALSE;
	     NM_AfterWakeup_Timer = 0;
	 }
	 else
	 {
             NM_AfterWakeup_Timer ++;
	 }
    }
    else
    {
	 NM_AfterWakeup_Timer = 0;
    }
}
/*********************************************************************************************
** Name:	  NM_RemoteEvent_Monitor
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
static void NM_RemoteEvent_Monitor(void)
{
     NM_RemoteEvent_LastStatus = NM_RemoteEvent_Status;
	
    
    #ifdef _INGIN_AUTOSAR_NM
     #ifdef _CHERY_COM 
	 //这是收到网络报文NM_RxIndication_Status = TRUE; 网络报文唤醒
     if(TRUE == NM_RxIndication_Status)
     {
		  NM_RemoteEvent_Status = TRUE;

		  NM_RxIndication_Status = FALSE;

		  DecreaseTimer10ms[Timer_NMRemoteEvent] = K_NM_RemoteEvent_Timeout;

		  NM_EventSource = NMSource_NMFrame;
     }
     #endif
     else if(DecreaseTimer10ms[Timer_NMRemoteEvent] == 0)
     {
	  NM_RemoteEvent_Status = FALSE;
     }   
     #endif  

   /* NM_RemoteEvent RiseEdge and FallEdge Active monitor */  
    if((FALSE == NM_RemoteEvent_Status) && (TRUE == NM_RemoteEvent_LastStatus))
    {
    	  NM_RemoteEvent_RiseEdge_Active = TRUE;
    } 
    else
    {
    	  NM_RemoteEvent_RiseEdge_Active = FALSE;
    }
 
    if((TRUE == NM_RemoteEvent_Status) && (FALSE == NM_RemoteEvent_LastStatus))
    {
		 #ifdef _CONFIG_NMRemoteEvent_NetworkRequest
		 NM_RemoteEvent_Start_Status = TRUE;
		 NM_RemoteEvent_Start_Timer = 0;
		 #else
		 NM_RemoteEvent_FallEdge_Active = TRUE;
		 #endif
    }	 
    else
    {
		 #ifndef _CONFIG_NMRemoteEvent_NetworkRequest
		 NM_RemoteEvent_FallEdge_Active = FALSE;
		 #endif
    }
    
    
}

/*********************************************************************************************
** Name:	  NM_LocalEvent_Monitor
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
static void NM_LocalEvent_Monitor(void)
{
     NM_LocalEvent_LastStatus = NM_LocalEvent_Status;
     
     /*Active LocalEvent*/
     if(FALSE)
     {
     }

     #ifdef _CHERY_COM
	 //test_mag.test_mag1==3,测试用报文唤醒，其实没用
	 else if((test_mag.test_mag1==3)
            #ifdef _CONFIG_NMWakeupByIgntion_Disable
             &&((CanNm_State[0] == NM_STATE_READY_SLEEP)
	         ||(CanNm_State[0] == NM_STATE_NORMAL_OPERATION)
	         ||(CanNm_State[0] == NM_STATE_REPEAT_MESSAGE))
            #endif		 
	     )
     {
	   NM_LocalEvent_Status = TRUE;
	   
	   DecreaseTimer10ms[Timer_NMLocalEvent] = K_Igntion_KeepEvent_Timeout;
	   Flag_LocalEvent = 1;
	   NM_EventSource = NMSource_Button;
	   
	   NM_LocalEvent_Delay_Status = FALSE;
       NM_LocalEvent_Delay_Timer = 0;
	   DecreaseTimer10ms[Timer_IgntionKeepEvent] = K_Igntion_KeepEvent_Timeout;
     }
	 //test_mag.test_mag6 == 0,测试用按键唤醒 Wakeup_Hoaresignal
	 else if(test_mag.test_mag6 == 0)
     {
	   NM_LocalEvent_Status = TRUE;

		DecreaseTimer10ms[Timer_NMLocalEvent] = K_NM_LocalEvent_Long_Timeout;
	   Flag_LocalEvent = 2;
	   
	   NM_EventSource = NMSource_Button;
	   DecreaseTimer10ms[Timer_LocalKeepEvent] = K_NM_LocalEvent_Short_Timeout;
	   
	   NM_LocalEvent_Delay_Status = FALSE;
	   NM_LocalEvent_Delay_Timer = 0;
     }


	 //===================================
	 
	 //诊断保持
     else if((TRUE == UDS_RxIndication_Status)
            #ifdef _CONFIG_NMWakeupByIgntion_Disable
	      &&((CanNm_State[0] == NM_STATE_READY_SLEEP)
	         ||(CanNm_State[0] == NM_STATE_NORMAL_OPERATION)
	         ||(CanNm_State[0] == NM_STATE_REPEAT_MESSAGE))
            #endif		 
	)
     {
    	 UDS_RxIndication_Status = FALSE;
	   
		 NM_LocalEvent_Status = TRUE;		 
		 DecreaseTimer10ms[Timer_NMLocalEvent] = K_UDS_KeepEvent_Timeout;
	     Flag_LocalEvent = 3;
		 NM_EventSource = NMSource_UDSFrame;
	     DecreaseTimer10ms[Timer_UDSKeepEvent] = K_UDS_KeepEvent_Timeout;
		 
		 NM_LocalEvent_Delay_Status = FALSE;
		 NM_LocalEvent_Delay_Timer = 0;
     }
	 
    //  //这个就是点火-保持唤醒？，但是没找到VehiclePowerMode怎么赋值
    //  else if((VehiclePowerMode == PowerMode_ON)
    //         #ifdef _CONFIG_NMWakeupByIgntion_Disable
    //          &&((CanNm_State[0] == NM_STATE_READY_SLEEP)
	//          ||(CanNm_State[0] == NM_STATE_NORMAL_OPERATION)
	//          ||(CanNm_State[0] == NM_STATE_REPEAT_MESSAGE))
    //         #endif		 
	//      )
    //  {
	//    NM_LocalEvent_Status = TRUE;
	   
	//    DecreaseTimer10ms[Timer_NMLocalEvent] = K_Igntion_KeepEvent_Timeout;
	//    Flag_LocalEvent = 4;
	//    NM_EventSource = NMSource_Igntion;
	   
	//    NM_LocalEvent_Delay_Status = FALSE;
    //    NM_LocalEvent_Delay_Timer = 0;
	//    DecreaseTimer10ms[Timer_IgntionKeepEvent] = K_Igntion_KeepEvent_Timeout;
    //  }
     #endif

     /*Set Back LocalEvent */
     if((DecreaseTimer10ms[Timer_NMLocalEvent] == 0)
            &&(DecreaseTimer10ms[Timer_UDSKeepEvent] == 0)
	    &&(DecreaseTimer10ms[Timer_IgntionKeepEvent] == 0)
	    &&(DecreaseTimer10ms[Timer_LocalKeepEvent] == 0)
            #ifdef _CONFIG_NMLocalEvent_MinTime
	    &&(DecreaseTimer10ms[Timer_NMLocalEvent_MinTime] == 0)
	    #endif
            )
     {
	   NM_LocalEvent_Status = FALSE;
     }
	 
      /* NM_LocalEvent RiseEdge and FallEdge Active monitor */  
    if((FALSE == NM_LocalEvent_Status) && (TRUE == NM_LocalEvent_LastStatus))
    {
    	 NM_LocalEvent_RiseEdge_Active = TRUE;
    } 
    else
    {
    	 NM_LocalEvent_RiseEdge_Active = FALSE;
    }
 
    if((TRUE == NM_LocalEvent_Status) && (FALSE == NM_LocalEvent_LastStatus))
    {
		 #ifndef _CONFIG_EMC_Test
		 NM_LocalEvent_FallEdge_Active = TRUE;
		 #endif

		 #ifdef _CONFIG_NMLocalEvent_MinTime
		 if(CanNm_State[0] == NM_STATE_BUS_SLEEP)
		 {
			 DecreaseTimer10ms[Timer_NMLocalEvent_MinTime] = K_NM_LocalEvent_MinTime;

		 }
		 #endif
    }	 
    else
    {
    	NM_LocalEvent_FallEdge_Active = FALSE;
    }
}

#ifdef _INGIN_AUTOSAR_NM
/*********************************************************************************************
** Name:	  NetworkManage_Monitor
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
uint16 NM_RequestToRelease_Timer = 0;
static void NetworkManage_Monitor(void)
{	  
	// 用于测试=== 
//	if((NM_RequestToRelease_Timer < 2000) && (FALSE == CanNm_NetworkRequest_Status))
//	{
//			CanNm_NetworkRequest(0);
//		 	CanNm_NetworkRelease_Status = FALSE;
//		 	CanNm_NetworkRequest_Status = TRUE;
//
//			NM_RemoteEvent_Ind = TRUE;
//
//		  	Com_TxStart_Request_Status = TRUE;
//		  	Com_TxStart_Request_Timer = 0;
//
//
//	}
//	NM_RequestToRelease_Timer++;
//	if((NM_RequestToRelease_Timer > 2000) && (FALSE == CanNm_NetworkRelease_Status))
//	{
//			#ifndef VOYAH_SIMULATE_DCU
//	  			CanNm_NetworkRelease(0);
//	  		#endif
//	  		CanNm_NetworkRelease_Status = TRUE;
//	  		CanNm_NetworkRequest_Status = FALSE;
//
//	  		NM_LocalEvent_Ind = FALSE;
//	}
	//================

    if((TRUE == NM_LocalEvent_FallEdge_Active) && (FALSE == CanNm_NetworkRequest_Status))
    {	
		  CanNm_NetworkRequest(0);
		  CanNm_NetworkRelease_Status = FALSE;
		  CanNm_NetworkRequest_Status = TRUE;
		 
		  NM_LocalEvent_Ind = TRUE;
	 
		  Com_TxStart_Request_Status = TRUE;
          Com_TxStart_Request_Timer = 0;
    } 
    
    if((TRUE == NM_RemoteEvent_FallEdge_Active) && (FALSE == CanNm_NetworkRequest_Status))
    {	 
		 #ifndef _CONFIG_NMRemoteEvent_NetworkRequest
		 CanNm_PassiveStartUp(0);
		 #endif
	 
		 //CanNm_NetworkRequest(0);
		 //CanNm_NetworkRelease_Status = FALSE;
		 //CanNm_NetworkRequest_Status = TRUE;
	  
		 NM_RemoteEvent_Ind = TRUE;
	  
		  Com_TxStart_Request_Status = TRUE;
		  Com_TxStart_Request_Timer = 0;
    }

    if((TRUE == NM_LocalEvent_RiseEdge_Active) && (FALSE == CanNm_NetworkRelease_Status))
    {
	  #ifndef VOYAH_SIMULATE_DCU
	  CanNm_NetworkRelease(0);
	  #endif
	  CanNm_NetworkRelease_Status = TRUE;
	  CanNm_NetworkRequest_Status = FALSE;
	 
	  NM_LocalEvent_Ind = FALSE;
    }
    
     /*To Start Com_TxStart*/
    if(TRUE == Com_TxStart_Request_Status)
    {
		 if(Com_TxStart_Request_Timer > K_Com_TxStart_Request_Time)
		 {
			  Com_TxStart();
			  Com_TxStart_Request_Status = FALSE;
			  Com_TxStart_Request_Timer = 0;
			  Com_TxStart_Start_Status = TRUE;
		 }
		 else
		 {
			  Com_TxStart_Request_Timer ++;
		 }
    }
    
//    CAN_ReadyToSleep_LastStatus = CAN_ReadyToSleep_Status;
    
    #ifdef _CONFIG_LIN_Master
    LIN_ReadyToSleep_LastStatus = LIN_ReadyToSleep_Status;
    #endif
    
//    if(((CanNm_State[0] == NM_STATE_BUS_SLEEP) && (CanNm_Mode[0] == NM_MODE_BUS_SLEEP))
//    /*#ifdef _MAXUS_COM
//    &&(DecreaseTimer10ms[Timer_UDSKeepEvent] == 0)
//    #endif*/
//    )
//    {
//         CAN_ReadyToSleep_Status = TRUE;
//	 #ifdef _CONFIG_LIN_Master
//	 LIN_ReadyToSleep_Status = TRUE;
//	 #endif
//    }
//    else
//    {
//	 CAN_ReadyToSleep_Status = FALSE;
//	 #ifdef _CONFIG_LIN_Master
//	 LIN_ReadyToSleep_Status = FALSE;
//	 #endif
//    }
//
//    if((FALSE == CAN_ReadyToSleep_Status) && (TRUE == CAN_ReadyToSleep_LastStatus))
//    {
//    	 CAN_ReadyToSleep_RiseEdge_Active = TRUE;
//    }
//    else
//    {
//    	 CAN_ReadyToSleep_RiseEdge_Active = FALSE;
//    }
//
//    if((TRUE == CAN_ReadyToSleep_Status) && (FALSE == CAN_ReadyToSleep_LastStatus))
//    {
//	 CAN_ReadyToSleep_FallEdge_Active = TRUE;
//
//    }
//    else
//    {
//	 CAN_ReadyToSleep_FallEdge_Active = FALSE;
//    }

}
#endif



/*********************************************************************************************
** Name:	  NM_NetWakeupSource_Monitor
** Function:	  
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
static void NM_NetWakeupSource_Monitor(void)
{
     #ifdef _INGIN_AUTOSAR_NM
     if((CanNm_State[0] == NM_STATE_BUS_SLEEP) && (CanNm_Mode[0] == NM_MODE_BUS_SLEEP))
     #endif     
     {
	  /*if((TRUE == NM_LocalEvent_FallEdge_Active) && (FALSE == NM_RemoteEvent_Status))
          {
	        NM_WakeupSource = NM_EventSource;
          }
	  else if((TRUE == NM_RemoteEvent_FallEdge_Active) && (FALSE == NM_LocalEvent_Status))
	  {
		NM_WakeupSource = NM_EventSource;
	  }*/
	  //只有在网络睡眠状态下发生的第一个事件才会被记录为唤醒源
	  if(TRUE == NM_LocalEvent_FallEdge_Active)
	  {
		NM_WakeupSource = NM_EventSource;
	  }
	  else if(TRUE == NM_RemoteEvent_FallEdge_Active)
	  {
		NM_WakeupSource = NM_EventSource;
	  }
	  
     }
   
}


/*********************************************************************************************
** Name:	  NM_EventSource_Clear
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
static void NM_EventSource_Clear(void)
{
     #ifdef _INGIN_AUTOSAR_NM
     if((CanNm_State[0] == NM_STATE_BUS_SLEEP) && (CanNm_Mode[0] == NM_MODE_BUS_SLEEP))
     #endif     
     {
        if((FALSE == NM_RemoteEvent_Status) && (FALSE == NM_LocalEvent_Status))
        {
	    NM_EventSource = NMSource_NoSource;
	    NM_WakeupSource = NMSource_NoSource;
        }
     }      
}

/*********************************************************************************************
** Name:	  NM_Userdata_Monitor
** Function:	  
** Scope:         Local
** Parameters:    void
** Return:	  void
** Remark:        
*********************************************************************************************/
static void NM_Userdata_Monitor(void)
{
     #ifdef _CHERY_COM    
     static uint8_t NMRemoteEvent_Delay_Timer;
     static uint8_t IgntionKeepEvent_Delay_Timer;
     static uint8_t UDSKeepEvent_Delay_Timer;
     static uint8_t LocalKeepEvent_Delay_Timer;
     static uint8_t SwitchKeepEvent_Delay_Timer;
     
     #define K_NMRemoteEvent_Delay_Time 2
     #define K_IgntionKeepEvent_Delay_Time 2
     #define K_UDSKeepEvent_Delay_Time 2
     #define K_LocalKeepEvent_Delay_Time 2
     #define K_SwitchKeepEvent_Delay_Time 2
     
     if(CanNm_LastState[0] != CanNm_State[0])
     {
	  CanNm_PreState[0] = CanNm_LastState[0];
          CanNm_LastState[0] = CanNm_State[0];
     }
     
     #ifdef _CHERY_COM_PD
     if(((CanNm_State[0] == NM_STATE_READY_SLEEP) && (CanNm_LastState != NM_STATE_READY_SLEEP))
	||((CanNm_State[0] == NM_STATE_PREPARE_BUS_SLEEP) && (CanNm_LastState != NM_STATE_PREPARE_BUS_SLEEP))
	||((CanNm_State[0] == NM_STATE_BUS_SLEEP) && (CanNm_LastState[0] != NM_STATE_BUS_SLEEP)))
     {
	   NM_Userdata0.bits.Wakeup_Poweron = FALSE;
	   NM_Userdata0.bits.Wakeup_NM = FALSE;
	   NM_Userdata0.bits.Wakeup_Diag = FALSE;
	   NM_Userdata0.bits.Wakeup_Hoaresignal = FALSE;
	   
	   NM_Userdata0.bits.Awake_Poweron = FALSE;
	   NM_Userdata0.bits.Awake_NM = FALSE;
	   NM_Userdata0.bits.Awake_Diag = FALSE;
	   NM_Userdata0.bits.Awake_Hoaresignal = FALSE;
     }
     //唤醒源设置  网络报文唤醒 0x04
     if(TRUE == NM_RemoteEvent_FallEdge_Active) 
     {
	   if(CanNm_State[0] == NM_STATE_BUS_SLEEP) 
        {
	        if((NM_EventSource == NMSource_NMFrame)
		    #ifndef _CONFIG_NMAppWakeup_Disable
                   ||(NM_EventSource == NMSource_AppFrame)
		    #endif
		    )
                {
	              NM_Userdata0.bits.Wakeup_NM = TRUE;
                }

	   }	   
        else if((CanNm_State[0] == NM_STATE_PREPARE_BUS_SLEEP)
	          ||(CanNm_PreState[0] == NM_STATE_PREPARE_BUS_SLEEP))
        {
	        if(NM_EventSource == NMSource_NMFrame)
                {
	              NM_Userdata0.bits.Wakeup_NM = TRUE;
                }
	   }
     }
     //唤醒源设置 按键唤醒 0x08
     if(TRUE == NM_LocalEvent_FallEdge_Active) 
     {
	  	if((CanNm_State[0] == NM_STATE_READY_SLEEP)
	     ||(CanNm_State[0] == NM_STATE_PREPARE_BUS_SLEEP)
	     ||(CanNm_State[0] == NM_STATE_BUS_SLEEP))
		{
		 
	        if((NM_EventSource == NMSource_Button) 
                   ||(NM_EventSource == NMSource_Spindle)
                   //||(NM_EventSource == NMSource_Latch)
	           ||(NM_EventSource == NMSource_GateOpen)
	           ||(NM_EventSource == NMSource_Reset)
	           ||(NM_EventSource == NMSource_PowerUp))
            {
	               NM_Userdata0.bits.Wakeup_Hoaresignal = TRUE;
            }
	    }
     }



  //电平触发状态，延时释放防抖设计，确保唤醒源信号稳定后才关闭唤醒标志。
     if((CanNm_State[0] == NM_STATE_NORMAL_OPERATION)
	||(CanNm_State[0] == NM_STATE_REPEAT_MESSAGE)
	||(TRUE == NM_LocalEvent_FallEdge_Active)
	||(TRUE == NM_RemoteEvent_FallEdge_Active))
     {
           if(DecreaseTimer10ms[Timer_IgntionKeepEvent] == 0)
           {
	         if(IgntionKeepEvent_Delay_Timer >= K_IgntionKeepEvent_Delay_Time)
	         {
                       NM_Userdata0.bits.Awake_Poweron = FALSE;
	         }
	         else
	         {
		       IgntionKeepEvent_Delay_Timer ++;
	         }
           }
           else
           {
                NM_Userdata0.bits.Awake_Poweron = TRUE;	   
	        IgntionKeepEvent_Delay_Timer = 0;
           }
		   //0x40,诊断唤醒保持
           if(DecreaseTimer10ms[Timer_UDSKeepEvent] == 0)
           {
	        if(UDSKeepEvent_Delay_Timer >= K_UDSKeepEvent_Delay_Time)
	        {
                      NM_Userdata0.bits.Awake_Diag = FALSE;
	        }
	        else
	        {
		      UDSKeepEvent_Delay_Timer ++;
	        }
           }
           else
           {
                NM_Userdata0.bits.Awake_Diag = TRUE;	   
	        UDSKeepEvent_Delay_Timer = 0;
           }
	   
	//    if(DecreaseTimer10ms[Timer_SwitchKeepEvent] == 0)
    //        {
	//         if(SwitchKeepEvent_Delay_Timer >= K_SwitchKeepEvent_Delay_Time)
	//         {
    //                   NM_Userdata3.bits.Awake_DoorSwitchChange = FALSE;
	//         }
	//         else
	//         {
	// 	      SwitchKeepEvent_Delay_Timer ++;
	//         }
    //        }
    //        else
    //        {
    //             NM_Userdata3.bits.Awake_DoorSwitchChange = TRUE;	   
	//         SwitchKeepEvent_Delay_Timer = 0;
    //        }
		   //0x80,按键唤醒保持*
           if(DecreaseTimer10ms[Timer_LocalKeepEvent] == 0)
           {    
	        if(DecreaseTimer10ms[Timer_NMLocalEvent_MinTime] == 0)
	        {
	              if(LocalKeepEvent_Delay_Timer >= K_LocalKeepEvent_Delay_Time)
	              {
                            NM_Userdata0.bits.Awake_Hoaresignal = FALSE;
	              }
	              else
	              {
		            LocalKeepEvent_Delay_Timer ++;
	              }
	        }
           }
           else
           {     
                NM_Userdata0.bits.Awake_Hoaresignal = TRUE;	   
	        LocalKeepEvent_Delay_Timer = 0;
           }
	   
	   
     }
     #endif
     #endif

}

/*********************************************************************************************
** End of file
*********************************************************************************************/
