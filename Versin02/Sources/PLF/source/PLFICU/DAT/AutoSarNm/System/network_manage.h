/*********************************************************************************************
** MACROS
**********************************************************************************************/
#ifndef __API_NETWORKMANAGE_H
#define __API_NETWORKMANAGE_H

#include "message_process.h"

#include "api_interface.h"

#ifdef _SGMW_COM
     //#define _INGIN_AUTOSAR_NM
     #define _SGMW_NM
     //#define _OSEK_NM
     //#define _VECTOR_AUTOSAR_NM

     #define _INGIN_STACK
     //#define _VECTOR_STACK
     
     //#define _CONFIG_NMWakeupAfterPowerUp_Disable
     //#define _CONFIG_NMLocalEvent_MinTime
     //#define _CONFIG_NMRemoteEvent_NetworkRequest
#endif
#ifdef _SGM_COM
     #define _INGIN_AUTOSAR_NM
     //#define _SGMW_NM
     //#define _OSEK_NM
     //#define _VECTOR_AUTOSAR_NM

     #define _INGIN_STACK
     //#define _VECTOR_STACK
     
     //#define _CONFIG_NMWakeupAfterPowerUp_Disable
     //#define _CONFIG_NMLocalEvent_MinTime
     //#define _CONFIG_NMRemoteEvent_NetworkRequest
#endif

#ifdef _CTCS_COM
#ifdef _CONFIG_CAN_Bus
     //#define _INGIN_AUTOSAR_NM
     //#define _SGMW_NM
     //#define _OSEK_NM
     #define _VECTOR_AUTOSAR_NM

     //#define _INGIN_STACK
     #define _VECTOR_STACK    
     
     //#define _CONFIG_NMWakeupAfterPowerUp_Disable
     //#define _CONFIG_NMLocalEvent_MinTime
     //#define _CONFIG_NMRemoteEvent_NetworkRequest
#endif     
#ifdef _CONFIG_LIN_Slave
     //#define _INGIN_AUTOSAR_NM
     //#define _SGMW_NM
     //#define _OSEK_NM
     //#define _VECTOR_AUTOSAR_NM
     #define _CONFIG_LIN_Slave

     #define _INGIN_STACK
     //#define _VECTOR_STACK
     
     #define _CONFIG_NMWakeupAfterPowerUp_Disable
     //#define _CONFIG_NMLocalEvent_MinTime
     //#define _CONFIG_NMRemoteEvent_NetworkRequest
#endif
#endif

#ifdef _DEARCC_COM
     //#define _INGIN_AUTOSAR_NM
     //#define _SGMW_NM
     #define _OSEK_NM
     //#define _VECTOR_AUTOSAR_NM

     #define _INGIN_STACK
     //#define _VECTOR_STACK
     
     //#define _CONFIG_NMWakeupAfterPowerUp_Disable
     //#define _CONFIG_NMLocalEvent_MinTime
     //#define _CONFIG_NMRemoteEvent_NetworkRequest
#endif

#ifdef _BAIC_COM
  #ifdef _BAIC_COM_N51AB_AUTOSAR
     #define _INGIN_AUTOSAR_NM
  #endif   
     //#define _SGMW_NM
  #if defined(_BAIC_COM_N51AB_OSEK) || defined(_BAIC_COM_C52X) || defined(_BAIC_COM_C62X) || defined(_BAIC_COM_C46DB) || defined(_BAIC_COM_B30X)
     #define _OSEK_NM
  #endif   
     //#define _VECTOR_AUTOSAR_NM

     #define _INGIN_STACK
     //#define _VECTOR_STACK
     
     //#define _CONFIG_NMWakeupAfterPowerUp_Disable
     //#define _CONFIG_NMLocalEvent_MinTime
     //#define _CONFIG_NMRemoteEvent_NetworkRequest
#endif

#ifdef _DFLZM_COM
     //#define _INGIN_AUTOSAR_NM
     //#define _SGMW_NM
     #define _OSEK_NM
     //#define _VECTOR_AUTOSAR_NM

     #define _INGIN_STACK
     //#define _VECTOR_STACK
     
     //#define _CONFIG_NMWakeupAfterPowerUp_Disable
     //#define _CONFIG_NMLocalEvent_MinTime
     //#define _CONFIG_NMRemoteEvent_NetworkRequest
#endif

#ifdef _NIU_COM
     #define _INGIN_AUTOSAR_NM
     //#define _SGMW_NM
     //#define _OSEK_NM
     //#define _VECTOR_AUTOSAR_NM

     #define _INGIN_STACK
     //#define _VECTOR_STACK
     
     //#define _CONFIG_NMWakeupAfterPowerUp_Disable
     //#define _CONFIG_NMLocalEvent_MinTime
     //#define _CONFIG_NMRemoteEvent_NetworkRequest
#endif

#ifdef _MAXUS_COM
     #define _INGIN_AUTOSAR_NM
     //#define _SGMW_NM
     //#define _OSEK_NM
     //#define _VECTOR_AUTOSAR_NM

     #define _INGIN_STACK
     //#define _VECTOR_STACK
     
     //#define _CONFIG_NMWakeupAfterPowerUp_Disable
     //#define _CONFIG_NMLocalEvent_MinTime
     //#define _CONFIG_NMRemoteEvent_NetworkRequest
#endif

#ifdef _DFMC_COM
     #define _INGIN_AUTOSAR_NM
     //#define _SGMW_NM
     //#define _OSEK_NM
     //#define _VECTOR_AUTOSAR_NM

     #define _INGIN_STACK
     //#define _VECTOR_STACK
     
     //#define _CONFIG_NMWakeupAfterPowerUp_Disable
     //#define _CONFIG_NMLocalEvent_MinTime
     //#define _CONFIG_NMRemoteEvent_NetworkRequest
#endif

#ifdef _FAW_COM
     //#define _INGIN_AUTOSAR_NM
     //#define _SGMW_NM
     #define _OSEK_NM
     //#define _VECTOR_AUTOSAR_NM

     #define _INGIN_STACK
     //#define _VECTOR_STACK
     
     //#define _CONFIG_NMWakeupAfterPowerUp_Disable
     //#define _CONFIG_NMLocalEvent_MinTime
     //#define _CONFIG_NMRemoteEvent_NetworkRequest
#endif

#ifdef _CHANGAN_COM
     //#define _INGIN_AUTOSAR_NM
     //#define _SGMW_NM
     #define _OSEK_NM
     //#define _VECTOR_AUTOSAR_NM

     #define _INGIN_STACK
     //#define _VECTOR_STACK
     
     //#define _CONFIG_NMWakeupAfterPowerUp_Disable
     //#define _CONFIG_NMLocalEvent_MinTime
     //#define _CONFIG_NMRemoteEvent_NetworkRequest
#endif

#ifdef _CHERY_COM
         #ifdef _CHERY_COM_PLG
     #define _INGIN_AUTOSAR_NM
     //#define _SGMW_NM
     //#define _OSEK_NM
     //#define _VECTOR_AUTOSAR_NM

     #define _INGIN_STACK
     //#define _VECTOR_STACK
     
     #define _CONFIG_NMWakeupAfterPowerUp_Disable
     #define _CONFIG_NMLocalEvent_MinTime
     #define _CONFIG_NMRemoteEvent_NetworkRequest 
     //#define _CONFIG_NMAppWakeup_Disable
         #endif
	 #ifdef _CHERY_COM_PD
     #define _INGIN_AUTOSAR_NM
     //#define _SGMW_NM
     //#define _OSEK_NM
     //#define _VECTOR_AUTOSAR_NM

     #define _INGIN_STACK
     //#define _VECTOR_STACK
     
     #define _CONFIG_NMWakeupAfterPowerUp_Disable
     #define _CONFIG_NMWakeupByIgntion_Disable
     #define _CONFIG_NMWakeupByUDSFrame_Disable
     #define _CONFIG_NMLocalEvent_MinTime
     //#define _CONFIG_NMRemoteEvent_NetworkRequest 
     #define _CONFIG_NMAppWakeup_Disable
         #endif
#endif

#ifdef _VOYAH_COM
         #ifdef _VOYAH_COM_PLG
         #endif
	 #ifdef _VOYAH_COM_PD
     #define _INGIN_AUTOSAR_NM
     //#define _SGMW_NM
     //#define _OSEK_NM
     //#define _VECTOR_AUTOSAR_NM

     #define _INGIN_STACK
     //#define _VECTOR_STACK
     
     #define _CONFIG_NMWakeupAfterPowerUp_Disable
     #define _CONFIG_NMWakeupByIgntion_Disable
     #define _CONFIG_NMWakeupByUDSFrame_Disable
     #define _CONFIG_NMLocalEvent_MinTime
     //#define _CONFIG_NMRemoteEvent_NetworkRequest 
     #define _CONFIG_NMAppWakeup_Disable
         #endif
#endif


#ifdef _AUDI_COM
         #ifdef _AUDI_COM_PLG
         #endif
	 #ifdef _AUDI_COM_PD
     #define _INGIN_AUTOSAR_NM
     //#define _SGMW_NM
     //#define _OSEK_NM
     //#define _VECTOR_AUTOSAR_NM

     #define _INGIN_STACK
     //#define _VECTOR_STACK
     
     #define _CONFIG_NMWakeupAfterPowerUp_Disable
     #define _CONFIG_NMWakeupByIgntion_Disable
     #define _CONFIG_NMWakeupByUDSFrame_Disable
     #define _CONFIG_NMLocalEvent_MinTime
     //#define _CONFIG_NMRemoteEvent_NetworkRequest 
     #define _CONFIG_NMAppWakeup_Disable
         #endif
#endif


#ifdef _XIAOPENG_COM
     //#define _INGIN_AUTOSAR_NM
     //#define _SGMW_NM
     #define _OSEK_NM
     //#define _VECTOR_AUTOSAR_NM

     #define _INGIN_STACK
     //#define _VECTOR_STACK   
     
     //#define _CONFIG_NMWakeupAfterPowerUp_Disable
     //#define _CONFIG_NMLocalEvent_MinTime
     //#define _CONFIG_NMRemoteEvent_NetworkRequest
#endif

/*********************************************************************************************
** Global Structures' Definition
*********************************************************************************************/


#ifdef _SGMW_NM
typedef enum
{
    SGMWNM_Init,      /*00*/
    SGMWNM_NMActive,  /*01*/	
    SGMWNM_AppActive, /*02*/
    SGMWNM_Inactive,  /*03*/	      				
    SGMWNM_End        /*04*/
    
}tD_SGMWNM_State;
#endif

/*********************************************************************************************
** MACROS
**********************************************************************************************/

#define _PLG_NWM      0x1U
#define _CONTINUE     0x0U
#define _INITIALIZE   0x1U




/*********************************************************************************************
** Global Variables Declarations
**********************************************************************************************/

#ifdef _SGMW_NM
/*SGMWNM*/
extern tD_SGMWNM_State Current_SGMWNM_State;
extern tD_SGMWNM_State Last_SGMWNM_State;
#endif

extern tD_NM_Source NM_EventSource;
extern tD_NM_Source NM_WakeupSource;


extern uint8_t NM_NMRemoteEvent_NetworkRequest_Status;
extern uint8_t NM_WakeupFromBusSleep_Status;

extern uint8_t NM_LocalEvent_Ind;
extern uint8_t NM_RemoteEvent_Ind;

extern uint8_t App_RxIndication_Status;
extern uint8_t NM_RxIndication_Status;
extern uint8_t UDS_RxIndication_Status;
extern uint8_t NM_RxIndication_Status_For_WakeupFromPrepareBusSleepOnly;

extern uint8_t NM_LocalEvent_Status;
extern uint8_t NM_RemoteEvent_Status;

extern uint8_t NM_AnyRx_ISR_Status;
extern uint8_t NM_CAN_Initialization_Status;

/*OsekNM*/
extern uint8_t CanNm_Start_Status;
extern uint8_t CanNm_Stop_Status;
extern uint8_t CanNm_GotoAwake_Status;
extern uint8_t CanNm_GotoSleep_Status;

extern uint8_t Flag_LocalEvent;
extern uint8_t Flag_RemoteEvent;
extern uint8_t NM_BusOffRecoveryMsgSend_Status;

extern uint8_t Com_TxStart_Start_Status;

typedef struct
{
    uint8_t  test_mag1;
    uint8_t  test_mag2;
    uint8_t  test_mag3;
    uint8_t  test_mag4;
    uint8_t  test_mag5;
    uint8_t  test_mag6;
    uint8_t  test_mag7;
    uint8_t  test_mag8;
    uint8_t  test_mag9;
    uint8_t  test_mag10;
    uint8_t  test_mag11;
    uint8_t  test_mag12;
    uint8_t  test_mag13;
    uint8_t  test_mag14;
    uint8_t  test_mag15;
    uint8_t  test_mag16;
    uint8_t  test_mag17;
    uint8_t  test_mag18;
} test_mag_c;
extern test_mag_c test_mag;

/*********************************************************************************************
** Function Prototypes with Global Scope
*********************************************************************************************/

extern void PE10ms_Network_Manage_Master(void);

extern void Network_Manage_Init(void);


/*********************************************************************************************
** EOF
*********************************************************************************************/
#endif
