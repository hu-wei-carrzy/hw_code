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
//#include "Appl_Proc.h"
//#include "Appl_Desc.h"
//#include "fault_process.h"
//#include "dtc_report.h"
#include "../System/Appl_Nm.h"

#define  APPCATION_CRC_OFFSET_POSITION  7

//#define  DATA_ID_DEFINED 

#define E2E_OFFSET      2
#define CRC_POS         0
#define COUNTER_POS     1

static unsigned int TxDataId[COM_TXIPDUNUM] = 
{
0,
0,
0,
0
};

static unsigned char TxCounter[COM_TXIPDUNUM] = 
{
0,
0,
0,
0
};

static unsigned int RxCheck_E2E_Switch[COM_RXIPDUNUM] = 
{
STD_ON, // COM_RXIPDUACU_3                  (0U)
STD_ON, // COM_RXIPDUACU_2                  (1U)
STD_ON, // COM_RXIPDUFLZCU_1                (2U)
STD_ON, // COM_RXIPDUFRZCU_2                (3U)
STD_ON, // COM_RXIPDUBNCM_14                (4U)
STD_ON, // COM_RXIPDUFRZCU_1                (5U)
STD_ON, // COM_RXIPDURZCU_2                 (6U)

#if  E0X_DCM == E0X_DCM_FL 
STD_ON, // COM_RXIPDURCM_1                  (7U)
STD_ON, // COM_RXIPDURCM_3                  (8U)
STD_ON, // COM_RXIPDUFLDRM_1                (9U)
#elif  E0X_DCM == E0X_DCM_FR 
STD_ON, // COM_RXIPDURCM_2                  (7U)
STD_ON, // COM_RXIPDURCM_4                  (8U)
STD_ON, // COM_RXIPDUFRDRM_1                (9U)
#elif  E0X_DCM == E0X_DCM_RL 
STD_ON, // COM_RXIPDURCM_1                  (7U)
STD_ON, // COM_RXIPDURCM_3                  (8U)
STD_ON, // COM_RXIPDURLDRM_1                (9U)
#elif  E0X_DCM == E0X_DCM_RR 
STD_ON, // COM_RXIPDURCM_2                  (7U)
STD_ON, // COM_RXIPDURCM_4                  (8U)
STD_ON, // COM_RXIPDURRDRM_1                (9U)
#else
#error "the define E0X_DCM is error!"
#endif 

STD_ON, // COM_RXIPDUASU_2                  (10U)
STD_ON, // COM_RXIPDUBNCM_1                 (11U)
STD_ON, // COM_RXIPDUVCC_4                  (12U)
STD_ON, // COM_RXIPDUVCC_5                  (13U)
STD_ON, // COM_RXIPDUVCC_6                  (14U)
STD_ON, // COM_RXIPDUFLZCU_5                (15U)

#if  E0X_DCM == E0X_DCM_FL 
STD_ON, // COM_RXIPDUFRDCM_1                (16U)
STD_ON, // COM_RXIPDURLDCM_1                (17U)
STD_ON, // COM_RXIPDURRDCM_1                (18U)

#elif  E0X_DCM == E0X_DCM_FR 
STD_ON, // COM_RXIPDUFLDCM_1                (16U)
STD_ON, // COM_RXIPDURLDCM_1                (17U)
STD_ON, // COM_RXIPDURRDCM_1                (18U)

#elif  E0X_DCM == E0X_DCM_RL 
STD_ON, // COM_RXIPDUFLDCM_1                (16U)
STD_ON, // COM_RXIPDUFRDCM_1                (17U)
STD_ON, // COM_RXIPDURRDCM_1                (18U)

#elif  E0X_DCM == E0X_DCM_RR 
STD_ON, // COM_RXIPDUFLDCM_1                (16U)
STD_ON, // COM_RXIPDUFRDCM_1                (17U)
STD_ON, // COM_RXIPDURLDCM_1                (18U)

#else
#error "the define E0X_DCM is error!"
#endif 

STD_ON, // COM_RXIPDUVCC_1                  (19U)
STD_ON, // COM_RXIPDUVCC_2                  (20U)
STD_ON, // COM_RXIPDURLCR_1                 (21U)
STD_ON, // COM_RXIPDURLCR_2                 (22U)
STD_ON, // COM_RXIPDUICC_BD_11              (23U)
STD_ON, // COM_RXIPDUONEBOX_1_G             (24U)
STD_ON, // COM_RXIPDURZCU_1                 (25U)
STD_ON, // COM_RXIPDUBNCM_15                (26U)
STD_ON, // COM_RXIPDUTMS_1                  (27U)
STD_ON, // COM_RXIPDUACU_1                  (28U)
STD_ON, // COM_RXIPDUFLZCU_9                (29U)
STD_ON, // COM_RXIPDUBNCM_6                 (30U)
STD_ON, // COM_RXIPDUVCU_1_G                (31U)

STD_ON, // COM_RXIPDUVCU_2_G                (32U)
STD_ON, // COM_RXIPDUASU_1                  (33U)
STD_ON, // COM_RXIPDUICC_COM_1              (34U)
STD_ON, // COM_RXIPDURRCR_1                 (35U)
STD_ON, // COM_RXIPDUPEPS_3                 (36U)
STD_ON, // COM_RXIPDUICC_COM_16             (37U)
STD_ON, // COM_RXIPDUICC_COM_8              (38U)
};

static unsigned int RxDataId[COM_RXIPDUNUM] = 
{
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0
};

static unsigned char RxCounter[COM_RXIPDUNUM] = 
{
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0
};

unsigned char E2E_ErrorCouter[COM_RXIPDUNUM] = 
{
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0
};

unsigned char E2E_RecoverCouter[COM_RXIPDUNUM] = 
{
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0
};

unsigned char E2E_Error_Status[COM_RXIPDUNUM] = 
{
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0
};

static unsigned char crc8(unsigned char *data, unsigned int length)
{
 unsigned char t_crc;
 int f, b;
 
 t_crc = 0x00;
 
 for (f = 0; f < length; f++)
  {
   t_crc ^= data[f];
   for (b = 0; b < 8; b++)
    {
     if ((t_crc & 0x80) != 0)
      {
        t_crc <<= 1;
        t_crc ^= 0x1D;
      }
     else
      {
        t_crc <<= 1;
      }
    }
  }
  
 return (t_crc^0x00); 
}

void E2E_Profile1_Calc(unsigned char MsgIndex)
{
#define MAX_LEN          10

    unsigned char u8crc = 0;  
    unsigned int u8DataLen = 0;
    unsigned char u8CalData[MAX_LEN];
    
    memset(u8CalData,0,MAX_LEN);
    
#ifdef DATA_ID_DEFINED
    u8CalData[1] = (TxDataId[MsgIndex]>>8)&0xff;
    u8CalData[0] = TxDataId[MsgIndex]&0xff; 
    u8DataLen = 2;
#endif    

    Com_TxIpduInitTable[MsgIndex].SduDataPtr[COUNTER_POS] = (TxCounter[MsgIndex]&0x0f); 
    u8DataLen += (Com_TxIpduInitTable[MsgIndex].SduLength -COUNTER_POS);
    
    /*if(u8DataLen < MAX_LEN)
    {
       memcpy(&u8CalData[u8DataLen-(Com_TxIpduInitTable[MsgIndex].SduLength -COUNTER_POS)], &Com_TxIpduInitTable[MsgIndex].SduDataPtr[COUNTER_POS],(Com_TxIpduInitTable[MsgIndex].SduLength -COUNTER_POS));
       u8crc = crc8(u8CalData,u8DataLen);
    
       Com_TxIpduInitTable[MsgIndex].SduDataPtr[CRC_POS] = u8crc;
    } */          
}

     
unsigned char E2E_Profile1_Check(unsigned char MsgIndex)
{

}

void Com_TxIpduCallout(PduIdType PduId, uint8 *DataPtr)
{

}

void Com_RxIpduCallout(PduIdType PduId, uint8 *DataPtr)
{

}

void AppIpduDCM_RemoteDiag_Conf(void)
{
 
}

void AppIpduDCM_1_Conf(void)
{
   
}

void AppIpduDCM_2_Conf(void)
{

}

void AppIpduDCM_3_Conf(void)
{

}

void AppIpduDCM_RemoteDiag_TxTOIndication(void)
{

}

void AppIpduDCM_1_TxTOIndication(void)
{
}

void AppIpduDCM_2_TxTOIndication(void)
{
}

void AppIpduDCM_3_TxTOIndication(void)
{
}

void AppIpduBNCM_14_TimeOutInd(void)
{

}

void AppIpduBNCM_15_TimeOutInd(void)
{

}

void AppIpduFLZCU_5_TimeOutInd(void)
{

}

void AppIpduASU_2_TimeOutInd(void)
{

}

void AppIpduPEPS_1_TimeOutInd(void)
{

}


void AppIpduHCU_EMS_2_G_TimeOutInd(void)
{

}
void AppIpduACU_3_TimeOutInd(void)
{

}

void AppIpduACU_2_TimeOutInd(void)
{

}


void AppIpduFLZCU_1_TimeOutInd(void)
{

}
void AppIpduFRZCU_2_TimeOutInd(void)
{

}
void AppIpduFRZCU_1_TimeOutInd(void)
{

}
void AppIpduRZCU_2_TimeOutInd(void)
{

}

#if  E0X_DCM == E0X_DCM_FL
void AppIpduRCM_1_TimeOutInd(void)
{

}
void AppIpduRCM_3_TimeOutInd(void)
{

}
void AppIpduFLDRM_1_TimeOutInd(void)
{

}
#elif  E0X_DCM == E0X_DCM_FR
void AppIpduRCM_2_TimeOutInd(void)
{
      if(Network_DiagStart_Enable_Flag == TRUE)
	 {
	   if(DTC_Timeout_Counter[NODE_MISSING_DTC_RCM_2_INDEX] != 0)
	  {
	    DTC_Timeout_Counter[NODE_MISSING_DTC_RCM_2_INDEX]--;
	    if(DTC_Timeout_Counter[NODE_MISSING_DTC_RCM_2_INDEX] == 0)
	    {
	       DTC_Msg_Timeout_Flag[NODE_MISSING_DTC_RCM_2_INDEX] = TRUE;
	       DTC_Recovery_Counter[NODE_MISSING_DTC_RCM_2_INDEX] = NODE_MISSING_DTC_RCM_2_REC_COUNT;
	    }
	  }	   
	 }
}
void AppIpduRCM_4_TimeOutInd(void)
{
      if(Network_DiagStart_Enable_Flag == TRUE)
	 {
	   if(DTC_Timeout_Counter[NODE_MISSING_DTC_RCM_4_INDEX] != 0)
	  {
	    DTC_Timeout_Counter[NODE_MISSING_DTC_RCM_4_INDEX]--;
	    if(DTC_Timeout_Counter[NODE_MISSING_DTC_RCM_4_INDEX] == 0)
	    {
	       DTC_Msg_Timeout_Flag[NODE_MISSING_DTC_RCM_4_INDEX] = TRUE;
	       DTC_Recovery_Counter[NODE_MISSING_DTC_RCM_4_INDEX] = NODE_MISSING_DTC_RCM_4_REC_COUNT;
	    }
	  }	   
	 }
}
void AppIpduFRDRM_1_TimeOutInd(void)
{
      if(Network_DiagStart_Enable_Flag == TRUE)
	 {
	   if(DTC_Timeout_Counter[NODE_MISSING_DTC_FRDRM_1_INDEX] != 0)
	  {
	    DTC_Timeout_Counter[NODE_MISSING_DTC_FRDRM_1_INDEX]--;
	    if(DTC_Timeout_Counter[NODE_MISSING_DTC_FRDRM_1_INDEX] == 0)
	    {
	       DTC_Msg_Timeout_Flag[NODE_MISSING_DTC_FRDRM_1_INDEX] = TRUE;
	       DTC_Recovery_Counter[NODE_MISSING_DTC_FRDRM_1_INDEX] = NODE_MISSING_DTC_FRDRM_1_REC_COUNT;
	    }
	  }	   
	 }
}
#elif  E0X_DCM == E0X_DCM_RL
void AppIpduRCM_1_TimeOutInd(void)
{
      if(Network_DiagStart_Enable_Flag == TRUE)
	 {
	   if(DTC_Timeout_Counter[NODE_MISSING_DTC_RCM_1_INDEX] != 0)
	  {
	    DTC_Timeout_Counter[NODE_MISSING_DTC_RCM_1_INDEX]--;
	    if(DTC_Timeout_Counter[NODE_MISSING_DTC_RCM_1_INDEX] == 0)
	    {
	       DTC_Msg_Timeout_Flag[NODE_MISSING_DTC_RCM_1_INDEX] = TRUE;
	       DTC_Recovery_Counter[NODE_MISSING_DTC_RCM_1_INDEX] = NODE_MISSING_DTC_RCM_1_REC_COUNT;
	    }
	  }	   
	 }
}
void AppIpduRCM_3_TimeOutInd(void)
{
      if(Network_DiagStart_Enable_Flag == TRUE)
	 {
	   if(DTC_Timeout_Counter[NODE_MISSING_DTC_RCM_3_INDEX] != 0)
	  {
	    DTC_Timeout_Counter[NODE_MISSING_DTC_RCM_3_INDEX]--;
	    if(DTC_Timeout_Counter[NODE_MISSING_DTC_RCM_3_INDEX] == 0)
	    {
	       DTC_Msg_Timeout_Flag[NODE_MISSING_DTC_RCM_3_INDEX] = TRUE;
	       DTC_Recovery_Counter[NODE_MISSING_DTC_RCM_3_INDEX] = NODE_MISSING_DTC_RCM_3_REC_COUNT;
	    }
	  }	   
	 }
}
void AppIpduRLDRM_1_TimeOutInd(void)
{
      if(Network_DiagStart_Enable_Flag == TRUE)
	 {
	   if(DTC_Timeout_Counter[NODE_MISSING_DTC_RLDRM_1_INDEX] != 0)
	  {
	    DTC_Timeout_Counter[NODE_MISSING_DTC_RLDRM_1_INDEX]--;
	    if(DTC_Timeout_Counter[NODE_MISSING_DTC_RLDRM_1_INDEX] == 0)
	    {
	       DTC_Msg_Timeout_Flag[NODE_MISSING_DTC_RLDRM_1_INDEX] = TRUE;
	       DTC_Recovery_Counter[NODE_MISSING_DTC_RLDRM_1_INDEX] = NODE_MISSING_DTC_RLDRM_1_REC_COUNT;
	    }
	  }	   
	 }
}
#elif  E0X_DCM == E0X_DCM_RR
void AppIpduRCM_2_TimeOutInd(void)
{
      if(Network_DiagStart_Enable_Flag == TRUE)
	 {
	   if(DTC_Timeout_Counter[NODE_MISSING_DTC_RCM_2_INDEX] != 0)
	  {
	    DTC_Timeout_Counter[NODE_MISSING_DTC_RCM_2_INDEX]--;
	    if(DTC_Timeout_Counter[NODE_MISSING_DTC_RCM_2_INDEX] == 0)
	    {
	       DTC_Msg_Timeout_Flag[NODE_MISSING_DTC_RCM_2_INDEX] = TRUE;
	       DTC_Recovery_Counter[NODE_MISSING_DTC_RCM_2_INDEX] = NODE_MISSING_DTC_RCM_2_REC_COUNT;
	    }
	  }	   
	 }
}
void AppIpduRCM_4_TimeOutInd(void)
{
      if(Network_DiagStart_Enable_Flag == TRUE)
	 {
	   if(DTC_Timeout_Counter[NODE_MISSING_DTC_RCM_4_INDEX] != 0)
	  {
	    DTC_Timeout_Counter[NODE_MISSING_DTC_RCM_4_INDEX]--;
	    if(DTC_Timeout_Counter[NODE_MISSING_DTC_RCM_4_INDEX] == 0)
	    {
	       DTC_Msg_Timeout_Flag[NODE_MISSING_DTC_RCM_4_INDEX] = TRUE;
	       DTC_Recovery_Counter[NODE_MISSING_DTC_RCM_4_INDEX] = NODE_MISSING_DTC_RCM_4_REC_COUNT;
	    }
	  }	   
	 }
}
void AppIpduRRDRM_1_TimeOutInd(void)
{
      if(Network_DiagStart_Enable_Flag == TRUE)
	 {
	   if(DTC_Timeout_Counter[NODE_MISSING_DTC_RRDRM_1_INDEX] != 0)
	  {
	    DTC_Timeout_Counter[NODE_MISSING_DTC_RRDRM_1_INDEX]--;
	    if(DTC_Timeout_Counter[NODE_MISSING_DTC_RRDRM_1_INDEX] == 0)
	    {
	       DTC_Msg_Timeout_Flag[NODE_MISSING_DTC_RRDRM_1_INDEX] = TRUE;
	       DTC_Recovery_Counter[NODE_MISSING_DTC_RRDRM_1_INDEX] = NODE_MISSING_DTC_RRDRM_1_REC_COUNT;
	    }
	  }	   
	 }
}
#else
#error "the define E0X_DCM is error!"
#endif

void AppIpduBNCM_1_TimeOutInd(void)
{

}

#if  E0X_DCM == E0X_DCM_FL 
void AppIpduFRDCM_1_TimeOutInd(void)
{

}
void AppIpduRLDCM_1_TimeOutInd(void)
{

}
void AppIpduRRDCM_1_TimeOutInd(void)
{

}
#elif  E0X_DCM == E0X_DCM_FR 
void AppIpduFLDCM_1_TimeOutInd(void)
{
      if(Network_DiagStart_Enable_Flag == TRUE)
	 {
	   if(DTC_Timeout_Counter[NODE_MISSING_DTC_FLDCM_1_INDEX] != 0)
	  {
	    DTC_Timeout_Counter[NODE_MISSING_DTC_FLDCM_1_INDEX]--;
	    if(DTC_Timeout_Counter[NODE_MISSING_DTC_FLDCM_1_INDEX] == 0)
	    {
	       DTC_Msg_Timeout_Flag[NODE_MISSING_DTC_FLDCM_1_INDEX] = TRUE;
	       DTC_Recovery_Counter[NODE_MISSING_DTC_FLDCM_1_INDEX] = NODE_MISSING_DTC_FLDCM_1_REC_COUNT;
	    }
	  }	   
	 }
}

void AppIpduRLDCM_1_TimeOutInd(void)
{
      if(Network_DiagStart_Enable_Flag == TRUE)
	 {
	   if(DTC_Timeout_Counter[NODE_MISSING_DTC_RLDCM_1_INDEX] != 0)
	  {
	    DTC_Timeout_Counter[NODE_MISSING_DTC_RLDCM_1_INDEX]--;
	    if(DTC_Timeout_Counter[NODE_MISSING_DTC_RLDCM_1_INDEX] == 0)
	    {
	       DTC_Msg_Timeout_Flag[NODE_MISSING_DTC_RLDCM_1_INDEX] = TRUE;
	       DTC_Recovery_Counter[NODE_MISSING_DTC_RLDCM_1_INDEX] = NODE_MISSING_DTC_RLDCM_1_REC_COUNT;
	    }
	  }	   
	 }
}
void AppIpduRRDCM_1_TimeOutInd(void)
{
      if(Network_DiagStart_Enable_Flag == TRUE)
	 {
	   if(DTC_Timeout_Counter[NODE_MISSING_DTC_RRDCM_1_INDEX] != 0)
	  {
	    DTC_Timeout_Counter[NODE_MISSING_DTC_RRDCM_1_INDEX]--;
	    if(DTC_Timeout_Counter[NODE_MISSING_DTC_RRDCM_1_INDEX] == 0)
	    {
	       DTC_Msg_Timeout_Flag[NODE_MISSING_DTC_RRDCM_1_INDEX] = TRUE;
	       DTC_Recovery_Counter[NODE_MISSING_DTC_RRDCM_1_INDEX] = NODE_MISSING_DTC_RRDCM_1_REC_COUNT;
	    }
	  }	   
	 }
}
#elif  E0X_DCM == E0X_DCM_RL 
void AppIpduFLDCM_1_TimeOutInd(void)
{
      if(Network_DiagStart_Enable_Flag == TRUE)
	 {
	   if(DTC_Timeout_Counter[NODE_MISSING_DTC_FLDCM_1_INDEX] != 0)
	  {
	    DTC_Timeout_Counter[NODE_MISSING_DTC_FLDCM_1_INDEX]--;
	    if(DTC_Timeout_Counter[NODE_MISSING_DTC_FLDCM_1_INDEX] == 0)
	    {
	       DTC_Msg_Timeout_Flag[NODE_MISSING_DTC_FLDCM_1_INDEX] = TRUE;
	       DTC_Recovery_Counter[NODE_MISSING_DTC_FLDCM_1_INDEX] = NODE_MISSING_DTC_FLDCM_1_REC_COUNT;
	    }
	  }	   
	 }
}
void AppIpduFRDCM_1_TimeOutInd(void)
{
      if(Network_DiagStart_Enable_Flag == TRUE)
	 {
	   if(DTC_Timeout_Counter[NODE_MISSING_DTC_FRDCM_1_INDEX] != 0)
	  {
	    DTC_Timeout_Counter[NODE_MISSING_DTC_FRDCM_1_INDEX]--;
	    if(DTC_Timeout_Counter[NODE_MISSING_DTC_FRDCM_1_INDEX] == 0)
	    {
	       DTC_Msg_Timeout_Flag[NODE_MISSING_DTC_FRDCM_1_INDEX] = TRUE;
	       DTC_Recovery_Counter[NODE_MISSING_DTC_FRDCM_1_INDEX] = NODE_MISSING_DTC_FRDCM_1_REC_COUNT;
	    }
	  }	   
	 }
}
void AppIpduRRDCM_1_TimeOutInd(void)
{
      if(Network_DiagStart_Enable_Flag == TRUE)
	 {
	   if(DTC_Timeout_Counter[NODE_MISSING_DTC_RRDCM_1_INDEX] != 0)
	  {
	    DTC_Timeout_Counter[NODE_MISSING_DTC_RRDCM_1_INDEX]--;
	    if(DTC_Timeout_Counter[NODE_MISSING_DTC_RRDCM_1_INDEX] == 0)
	    {
	       DTC_Msg_Timeout_Flag[NODE_MISSING_DTC_RRDCM_1_INDEX] = TRUE;
	       DTC_Recovery_Counter[NODE_MISSING_DTC_RRDCM_1_INDEX] = NODE_MISSING_DTC_RRDCM_1_REC_COUNT;
	    }
	  }	   
	 }
}
#elif  E0X_DCM == E0X_DCM_RR 
void AppIpduFLDCM_1_TimeOutInd(void)
{
      if(Network_DiagStart_Enable_Flag == TRUE)
	 {
	   if(DTC_Timeout_Counter[NODE_MISSING_DTC_FLDCM_1_INDEX] != 0)
	  {
	    DTC_Timeout_Counter[NODE_MISSING_DTC_FLDCM_1_INDEX]--;
	    if(DTC_Timeout_Counter[NODE_MISSING_DTC_FLDCM_1_INDEX] == 0)
	    {
	       DTC_Msg_Timeout_Flag[NODE_MISSING_DTC_FLDCM_1_INDEX] = TRUE;
	       DTC_Recovery_Counter[NODE_MISSING_DTC_FLDCM_1_INDEX] = NODE_MISSING_DTC_FLDCM_1_REC_COUNT;
	    }
	  }	   
	 }
}
void AppIpduFRDCM_1_TimeOutInd(void)
{
      if(Network_DiagStart_Enable_Flag == TRUE)
	 {
	   if(DTC_Timeout_Counter[NODE_MISSING_DTC_FRDCM_1_INDEX] != 0)
	  {
	    DTC_Timeout_Counter[NODE_MISSING_DTC_FRDCM_1_INDEX]--;
	    if(DTC_Timeout_Counter[NODE_MISSING_DTC_FRDCM_1_INDEX] == 0)
	    {
	       DTC_Msg_Timeout_Flag[NODE_MISSING_DTC_FRDCM_1_INDEX] = TRUE;
	       DTC_Recovery_Counter[NODE_MISSING_DTC_FRDCM_1_INDEX] = NODE_MISSING_DTC_FRDCM_1_REC_COUNT;
	    }
	  }	   
	 }
}

void AppIpduRLDCM_1_TimeOutInd(void)
{
      if(Network_DiagStart_Enable_Flag == TRUE)
	 {
	   if(DTC_Timeout_Counter[NODE_MISSING_DTC_RLDCM_1_INDEX] != 0)
	  {
	    DTC_Timeout_Counter[NODE_MISSING_DTC_RLDCM_1_INDEX]--;
	    if(DTC_Timeout_Counter[NODE_MISSING_DTC_RLDCM_1_INDEX] == 0)
	    {
	       DTC_Msg_Timeout_Flag[NODE_MISSING_DTC_RLDCM_1_INDEX] = TRUE;
	       DTC_Recovery_Counter[NODE_MISSING_DTC_RLDCM_1_INDEX] = NODE_MISSING_DTC_RLDCM_1_REC_COUNT;
	    }
	  }	   
	 }
}
#else
#error "the define E0X_DCM is error!"
#endif  

void AppIpduVCC_1_TimeOutInd(void)
{

}

void AppIpduVCC_2_TimeOutInd(void)
{
#if 0
	if(Network_DiagStart_Enable_Flag == TRUE)
	 {
	   if(DTC_Timeout_Counter[NODE_MISSING_DTC_VCC_2_INDEX] != 0)
	  {
	    DTC_Timeout_Counter[NODE_MISSING_DTC_VCC_2_INDEX]--;
	    if(DTC_Timeout_Counter[NODE_MISSING_DTC_VCC_2_INDEX] == 0)
	    {
	       DTC_Msg_Timeout_Flag[NODE_MISSING_DTC_VCC_2_INDEX] = TRUE;
	       DTC_Recovery_Counter[NODE_MISSING_DTC_VCC_2_INDEX] = NODE_MISSING_DTC_VCC_2_REC_COUNT;
	    }
	  }	   
	 }
#endif	 
}

void AppIpduVCC_4_TimeOutInd(void)
{
#if 0	
      if(Network_DiagStart_Enable_Flag == TRUE)
	 {
	   if(DTC_Timeout_Counter[NODE_MISSING_DTC_VCC_4_INDEX] != 0)
	  {
	    DTC_Timeout_Counter[NODE_MISSING_DTC_VCC_4_INDEX]--;
	    if(DTC_Timeout_Counter[NODE_MISSING_DTC_VCC_4_INDEX] == 0)
	    {
	       DTC_Msg_Timeout_Flag[NODE_MISSING_DTC_VCC_4_INDEX] = TRUE;
	       DTC_Recovery_Counter[NODE_MISSING_DTC_VCC_4_INDEX] = NODE_MISSING_DTC_VCC_4_REC_COUNT;
	    }
	  }	   
	 }
#endif	 
}

void AppIpduVCC_5_TimeOutInd(void)
{
#if 0	
      if(Network_DiagStart_Enable_Flag == TRUE)
	 {
	   if(DTC_Timeout_Counter[NODE_MISSING_DTC_VCC_5_INDEX] != 0)
	  {
	    DTC_Timeout_Counter[NODE_MISSING_DTC_VCC_5_INDEX]--;
	    if(DTC_Timeout_Counter[NODE_MISSING_DTC_VCC_5_INDEX] == 0)
	    {
	       DTC_Msg_Timeout_Flag[NODE_MISSING_DTC_VCC_5_INDEX] = TRUE;
	       DTC_Recovery_Counter[NODE_MISSING_DTC_VCC_5_INDEX] = NODE_MISSING_DTC_VCC_5_REC_COUNT;
	    }
	  }	   
	 }
#endif	 
}
void AppIpduVCC_6_TimeOutInd(void)
{
#if 0	
      if(Network_DiagStart_Enable_Flag == TRUE)
	 {
	   if(DTC_Timeout_Counter[NODE_MISSING_DTC_VCC_6_INDEX] != 0)
	  {
	    DTC_Timeout_Counter[NODE_MISSING_DTC_VCC_6_INDEX]--;
	    if(DTC_Timeout_Counter[NODE_MISSING_DTC_VCC_6_INDEX] == 0)
	    {
	       DTC_Msg_Timeout_Flag[NODE_MISSING_DTC_VCC_6_INDEX] = TRUE;
	       DTC_Recovery_Counter[NODE_MISSING_DTC_VCC_6_INDEX] = NODE_MISSING_DTC_VCC_6_REC_COUNT;
	    }
	  }	   
	 }
#endif 
}
void AppIpduRLCR_1_TimeOutInd(void)
{

}

void AppIpduRLCR_2_TimeOutInd(void)
{

}

void AppIpduICC_BD_11_TimeOutInd(void)
{

}

void AppIpduASU_1_TimeOutInd(void)
{

}

void AppIpduRRCR_1_TimeOutInd(void)
{

}
void AppIpduONEBOX_1_G_TimeOutInd(void)
{

}

void AppIpduRZCU_1_TimeOutInd(void)
{

}
void AppIpduTMS_1_TimeOutInd(void)
{

}

void AppIpduFLZCU_9_TimeOutInd(void)
{

}

void AppIpduBNCM_6_TimeOutInd(void)
{

}

void AppIpduVCU_1_G_TimeOutInd(void)
{

}

void AppIpduVCU_2_G_TimeOutInd(void)
{

}

void AppIpduICC_COM_1_TimeOutInd(void)
{

}

void AppIpduICC_COM_8_TimeOutInd(void)
{

}

void AppIpduICC_COM_16_TimeOutInd(void)
{

}


void AppIpduACU_1_TimeOutInd(void)
{

}


void AppIpduPEPS_3_TimeOutInd(void)
{

}

void AppIpduACU_1_Ind(void)
{  

}

void AppIpduPEPS_3_Ind(void)
{  

}

void AppIpduICC_COM_16_Ind(void)
{  
    
}

void AppIpduBNCM_14_Ind(void)
{  

}

void AppIpduBNCM_15_Ind(void)
{  

}

void AppIpduFLZCU_5_Ind(void)
{  

}

void AppIpduASU_2_Ind(void)
{  

}

void AppIpduPEPS_1_Ind(void)
{       

}

void AppIpduHCU_EMS_2_G_Ind(void)
{    

}

void AppIpduACU_3_Ind(void)
{    

}
void AppIpduACU_2_Ind(void)
{   

}

void AppIpduFLZCU_1_Ind(void)
{   

}
void AppIpduFRZCU_2_Ind(void)
{   

}
void AppIpduFRZCU_1_Ind(void)
{   
    
}
void AppIpduRZCU_2_Ind(void)
{   

}

#if  E0X_DCM == E0X_DCM_FL
void AppIpduRCM_1_Ind(void)
{   

}
void AppIpduRCM_3_Ind(void)
{   

}
void AppIpduFLDRM_1_Ind(void)
{   

}
#elif  E0X_DCM == E0X_DCM_FR
void AppIpduRCM_2_Ind(void)
{   
    if(RxCheck_E2E_Switch[COM_RXIPDURCM_2] == STD_ON)
    {
       E2E_Error_CallBack(COM_RXIPDURCM_2,E2E_Profile1_Check(COM_RXIPDURCM_2));
    }
    
    IpduRCM_2_Indicator = TRUE;
    if(DTC_Recovery_Counter[NODE_MISSING_DTC_RCM_2_INDEX] != 0)
    {
       DTC_Recovery_Counter[NODE_MISSING_DTC_RCM_2_INDEX]--;
       if(DTC_Recovery_Counter[NODE_MISSING_DTC_RCM_2_INDEX] == 0)
       {
           DTC_Msg_Timeout_Flag[NODE_MISSING_DTC_RCM_2_INDEX] = FALSE;
       }
    }	
    DTC_Timeout_Counter[NODE_MISSING_DTC_RCM_2_INDEX] = NODE_MISSING_DTC_RCM_2_TIMEOUT_COUNT;      
}
void AppIpduRCM_4_Ind(void)
{   
    if(RxCheck_E2E_Switch[COM_RXIPDURCM_4] == STD_ON)
    {
       E2E_Error_CallBack(COM_RXIPDURCM_4,E2E_Profile1_Check(COM_RXIPDURCM_4));
    }
    
    IpduRCM_4_Indicator = TRUE;
    if(DTC_Recovery_Counter[NODE_MISSING_DTC_RCM_4_INDEX] != 0)
    {
       DTC_Recovery_Counter[NODE_MISSING_DTC_RCM_4_INDEX]--;
       if(DTC_Recovery_Counter[NODE_MISSING_DTC_RCM_4_INDEX] == 0)
       {
           DTC_Msg_Timeout_Flag[NODE_MISSING_DTC_RCM_4_INDEX] = FALSE;
       }
    }	
    DTC_Timeout_Counter[NODE_MISSING_DTC_RCM_4_INDEX] = NODE_MISSING_DTC_RCM_4_TIMEOUT_COUNT;      
}
void AppIpduFRDRM_1_Ind(void)
{   
    if(RxCheck_E2E_Switch[COM_RXIPDUFRDRM_1] == STD_ON)
    {
       E2E_Error_CallBack(COM_RXIPDUFRDRM_1,E2E_Profile1_Check(COM_RXIPDUFRDRM_1));
    }
    
    IpduFRDRM_1_Indicator = TRUE;
    if(DTC_Recovery_Counter[NODE_MISSING_DTC_FRDRM_1_INDEX] != 0)
    {
       DTC_Recovery_Counter[NODE_MISSING_DTC_FRDRM_1_INDEX]--;
       if(DTC_Recovery_Counter[NODE_MISSING_DTC_FRDRM_1_INDEX] == 0)
       {
           DTC_Msg_Timeout_Flag[NODE_MISSING_DTC_FRDRM_1_INDEX] = FALSE;
       }
    }	
    DTC_Timeout_Counter[NODE_MISSING_DTC_FRDRM_1_INDEX] = NODE_MISSING_DTC_FRDRM_1_TIMEOUT_COUNT;      
}
#elif  E0X_DCM == E0X_DCM_RL
void AppIpduRCM_1_Ind(void)
{   
    if(RxCheck_E2E_Switch[COM_RXIPDURCM_1] == STD_ON)
    {
       E2E_Error_CallBack(COM_RXIPDURCM_1,E2E_Profile1_Check(COM_RXIPDURCM_1));
    }
    
    IpduRCM_1_Indicator = TRUE;
    if(DTC_Recovery_Counter[NODE_MISSING_DTC_RCM_1_INDEX] != 0)
    {
       DTC_Recovery_Counter[NODE_MISSING_DTC_RCM_1_INDEX]--;
       if(DTC_Recovery_Counter[NODE_MISSING_DTC_RCM_1_INDEX] == 0)
       {
           DTC_Msg_Timeout_Flag[NODE_MISSING_DTC_RCM_1_INDEX] = FALSE;
       }
    }	
    DTC_Timeout_Counter[NODE_MISSING_DTC_RCM_1_INDEX] = NODE_MISSING_DTC_RCM_1_TIMEOUT_COUNT;      
}
void AppIpduRCM_3_Ind(void)
{   
    if(RxCheck_E2E_Switch[COM_RXIPDURCM_3] == STD_ON)
    {
       E2E_Error_CallBack(COM_RXIPDURCM_3,E2E_Profile1_Check(COM_RXIPDURCM_3));
    }
    
    IpduRCM_3_Indicator = TRUE;
    if(DTC_Recovery_Counter[NODE_MISSING_DTC_RCM_3_INDEX] != 0)
    {
       DTC_Recovery_Counter[NODE_MISSING_DTC_RCM_3_INDEX]--;
       if(DTC_Recovery_Counter[NODE_MISSING_DTC_RCM_3_INDEX] == 0)
       {
           DTC_Msg_Timeout_Flag[NODE_MISSING_DTC_RCM_3_INDEX] = FALSE;
       }
    }	
    DTC_Timeout_Counter[NODE_MISSING_DTC_RCM_3_INDEX] = NODE_MISSING_DTC_RCM_3_TIMEOUT_COUNT;      
}
void AppIpduRLDRM_1_Ind(void)
{   
    if(RxCheck_E2E_Switch[COM_RXIPDURLDRM_1] == STD_ON)
    {
       E2E_Error_CallBack(COM_RXIPDURLDRM_1,E2E_Profile1_Check(COM_RXIPDURLDRM_1));
    }
    
    IpduRLDRM_1_Indicator = TRUE;
    if(DTC_Recovery_Counter[NODE_MISSING_DTC_RLDRM_1_INDEX] != 0)
    {
       DTC_Recovery_Counter[NODE_MISSING_DTC_RLDRM_1_INDEX]--;
       if(DTC_Recovery_Counter[NODE_MISSING_DTC_RLDRM_1_INDEX] == 0)
       {
           DTC_Msg_Timeout_Flag[NODE_MISSING_DTC_RLDRM_1_INDEX] = FALSE;
       }
    }	
    DTC_Timeout_Counter[NODE_MISSING_DTC_RLDRM_1_INDEX] = NODE_MISSING_DTC_RLDRM_1_TIMEOUT_COUNT;      
}
#elif  E0X_DCM == E0X_DCM_RR
void AppIpduRCM_2_Ind(void)
{   
    if(RxCheck_E2E_Switch[COM_RXIPDURCM_2] == STD_ON)
    {
       E2E_Error_CallBack(COM_RXIPDURCM_2,E2E_Profile1_Check(COM_RXIPDURCM_2));
    }
    
    IpduRCM_2_Indicator = TRUE;
    if(DTC_Recovery_Counter[NODE_MISSING_DTC_RCM_2_INDEX] != 0)
    {
       DTC_Recovery_Counter[NODE_MISSING_DTC_RCM_2_INDEX]--;
       if(DTC_Recovery_Counter[NODE_MISSING_DTC_RCM_2_INDEX] == 0)
       {
           DTC_Msg_Timeout_Flag[NODE_MISSING_DTC_RCM_2_INDEX] = FALSE;
       }
    }	
    DTC_Timeout_Counter[NODE_MISSING_DTC_RCM_2_INDEX] = NODE_MISSING_DTC_RCM_2_TIMEOUT_COUNT;      
}
void AppIpduRCM_4_Ind(void)
{   
    if(RxCheck_E2E_Switch[COM_RXIPDURCM_4] == STD_ON)
    {
       E2E_Error_CallBack(COM_RXIPDURCM_4,E2E_Profile1_Check(COM_RXIPDURCM_4));
    }
    
    IpduRCM_4_Indicator = TRUE;
    if(DTC_Recovery_Counter[NODE_MISSING_DTC_RCM_4_INDEX] != 0)
    {
       DTC_Recovery_Counter[NODE_MISSING_DTC_RCM_4_INDEX]--;
       if(DTC_Recovery_Counter[NODE_MISSING_DTC_RCM_4_INDEX] == 0)
       {
           DTC_Msg_Timeout_Flag[NODE_MISSING_DTC_RCM_4_INDEX] = FALSE;
       }
    }	
    DTC_Timeout_Counter[NODE_MISSING_DTC_RCM_4_INDEX] = NODE_MISSING_DTC_RCM_4_TIMEOUT_COUNT;      
}
void AppIpduRRDRM_1_Ind(void)
{   
    if(RxCheck_E2E_Switch[COM_RXIPDURRDRM_1] == STD_ON)
    {
       E2E_Error_CallBack(COM_RXIPDURRDRM_1,E2E_Profile1_Check(COM_RXIPDURRDRM_1));
    }
    
    IpduRRDRM_1_Indicator = TRUE;
    if(DTC_Recovery_Counter[NODE_MISSING_DTC_RRDRM_1_INDEX] != 0)
    {
       DTC_Recovery_Counter[NODE_MISSING_DTC_RRDRM_1_INDEX]--;
       if(DTC_Recovery_Counter[NODE_MISSING_DTC_RRDRM_1_INDEX] == 0)
       {
           DTC_Msg_Timeout_Flag[NODE_MISSING_DTC_RRDRM_1_INDEX] = FALSE;
       }
    }	
    DTC_Timeout_Counter[NODE_MISSING_DTC_RRDRM_1_INDEX] = NODE_MISSING_DTC_RRDRM_1_TIMEOUT_COUNT;      
}
#else
#error "the define E0X_DCM is error!"
#endif

void AppIpduBNCM_1_Ind(void)
{   

}
#if  E0X_DCM == E0X_DCM_FL 
void AppIpduFRDCM_1_Ind(void)
{   

}
void AppIpduRLDCM_1_Ind(void)
{   

}
void AppIpduRRDCM_1_Ind(void)
{   

}
#elif  E0X_DCM == E0X_DCM_FR 
void AppIpduFLDCM_1_Ind(void)
{   
    if(RxCheck_E2E_Switch[COM_RXIPDUFLDCM_1] == STD_ON)
    {
       E2E_Error_CallBack(COM_RXIPDUFLDCM_1,E2E_Profile1_Check(COM_RXIPDUFLDCM_1));
    }
    
    IpduFLDCM_1_Indicator = TRUE;
    if(DTC_Recovery_Counter[NODE_MISSING_DTC_FLDCM_1_INDEX] != 0)
    {
       DTC_Recovery_Counter[NODE_MISSING_DTC_FLDCM_1_INDEX]--;
       if(DTC_Recovery_Counter[NODE_MISSING_DTC_FLDCM_1_INDEX] == 0)
       {
           DTC_Msg_Timeout_Flag[NODE_MISSING_DTC_FLDCM_1_INDEX] = FALSE;
       }
    }	
    DTC_Timeout_Counter[NODE_MISSING_DTC_FLDCM_1_INDEX] = NODE_MISSING_DTC_FLDCM_1_TIMEOUT_COUNT;      
}
void AppIpduRLDCM_1_Ind(void)
{   
    if(RxCheck_E2E_Switch[COM_RXIPDURLDCM_1] == STD_ON)
    {
       E2E_Error_CallBack(COM_RXIPDURLDCM_1,E2E_Profile1_Check(COM_RXIPDURLDCM_1));
    }
    
    IpduRLDCM_1_Indicator = TRUE;
    if(DTC_Recovery_Counter[NODE_MISSING_DTC_RLDCM_1_INDEX] != 0)
    {
       DTC_Recovery_Counter[NODE_MISSING_DTC_RLDCM_1_INDEX]--;
       if(DTC_Recovery_Counter[NODE_MISSING_DTC_RLDCM_1_INDEX] == 0)
       {
           DTC_Msg_Timeout_Flag[NODE_MISSING_DTC_RLDCM_1_INDEX] = FALSE;
       }
    }	
    DTC_Timeout_Counter[NODE_MISSING_DTC_RLDCM_1_INDEX] = NODE_MISSING_DTC_RLDCM_1_TIMEOUT_COUNT;      
}
void AppIpduRRDCM_1_Ind(void)
{   
    if(RxCheck_E2E_Switch[COM_RXIPDURRDCM_1] == STD_ON)
    {
       E2E_Error_CallBack(COM_RXIPDURRDCM_1,E2E_Profile1_Check(COM_RXIPDURRDCM_1));
    }
    
    IpduRRDCM_1_Indicator = TRUE;
    if(DTC_Recovery_Counter[NODE_MISSING_DTC_RRDCM_1_INDEX] != 0)
    {
       DTC_Recovery_Counter[NODE_MISSING_DTC_RRDCM_1_INDEX]--;
       if(DTC_Recovery_Counter[NODE_MISSING_DTC_RRDCM_1_INDEX] == 0)
       {
           DTC_Msg_Timeout_Flag[NODE_MISSING_DTC_RRDCM_1_INDEX] = FALSE;
       }
    }	
    DTC_Timeout_Counter[NODE_MISSING_DTC_RRDCM_1_INDEX] = NODE_MISSING_DTC_RRDCM_1_TIMEOUT_COUNT;      
}
#elif  E0X_DCM == E0X_DCM_RL 
void AppIpduFLDCM_1_Ind(void)
{   
    if(RxCheck_E2E_Switch[COM_RXIPDUFLDCM_1] == STD_ON)
    {
       E2E_Error_CallBack(COM_RXIPDUFLDCM_1,E2E_Profile1_Check(COM_RXIPDUFLDCM_1));
    }
    
    IpduFLDCM_1_Indicator = TRUE;
    if(DTC_Recovery_Counter[NODE_MISSING_DTC_FLDCM_1_INDEX] != 0)
    {
       DTC_Recovery_Counter[NODE_MISSING_DTC_FLDCM_1_INDEX]--;
       if(DTC_Recovery_Counter[NODE_MISSING_DTC_FLDCM_1_INDEX] == 0)
       {
           DTC_Msg_Timeout_Flag[NODE_MISSING_DTC_FLDCM_1_INDEX] = FALSE;
       }
    }	
    DTC_Timeout_Counter[NODE_MISSING_DTC_FLDCM_1_INDEX] = NODE_MISSING_DTC_FLDCM_1_TIMEOUT_COUNT;      
}
void AppIpduFRDCM_1_Ind(void)
{   
    if(RxCheck_E2E_Switch[COM_RXIPDUFRDCM_1] == STD_ON)
    {
       E2E_Error_CallBack(COM_RXIPDUFRDCM_1,E2E_Profile1_Check(COM_RXIPDUFRDCM_1));
    }
    
    IpduFRDCM_1_Indicator = TRUE;
    if(DTC_Recovery_Counter[NODE_MISSING_DTC_FRDCM_1_INDEX] != 0)
    {
       DTC_Recovery_Counter[NODE_MISSING_DTC_FRDCM_1_INDEX]--;
       if(DTC_Recovery_Counter[NODE_MISSING_DTC_FRDCM_1_INDEX] == 0)
       {
           DTC_Msg_Timeout_Flag[NODE_MISSING_DTC_FRDCM_1_INDEX] = FALSE;
       }
    }	
    DTC_Timeout_Counter[NODE_MISSING_DTC_FRDCM_1_INDEX] = NODE_MISSING_DTC_FRDCM_1_TIMEOUT_COUNT;      
}
void AppIpduRRDCM_1_Ind(void)
{   
    if(RxCheck_E2E_Switch[COM_RXIPDURRDCM_1] == STD_ON)
    {
       E2E_Error_CallBack(COM_RXIPDURRDCM_1,E2E_Profile1_Check(COM_RXIPDURRDCM_1));
    }
    
    IpduRRDCM_1_Indicator = TRUE;
    if(DTC_Recovery_Counter[NODE_MISSING_DTC_RRDCM_1_INDEX] != 0)
    {
       DTC_Recovery_Counter[NODE_MISSING_DTC_RRDCM_1_INDEX]--;
       if(DTC_Recovery_Counter[NODE_MISSING_DTC_RRDCM_1_INDEX] == 0)
       {
           DTC_Msg_Timeout_Flag[NODE_MISSING_DTC_RRDCM_1_INDEX] = FALSE;
       }
    }	
    DTC_Timeout_Counter[NODE_MISSING_DTC_RRDCM_1_INDEX] = NODE_MISSING_DTC_RRDCM_1_TIMEOUT_COUNT;      
}
#elif  E0X_DCM == E0X_DCM_RR 
void AppIpduFLDCM_1_Ind(void)
{   
    if(RxCheck_E2E_Switch[COM_RXIPDUFLDCM_1] == STD_ON)
    {
       E2E_Error_CallBack(COM_RXIPDUFLDCM_1,E2E_Profile1_Check(COM_RXIPDUFLDCM_1));
    }
    
    IpduFLDCM_1_Indicator = TRUE;
    if(DTC_Recovery_Counter[NODE_MISSING_DTC_FLDCM_1_INDEX] != 0)
    {
       DTC_Recovery_Counter[NODE_MISSING_DTC_FLDCM_1_INDEX]--;
       if(DTC_Recovery_Counter[NODE_MISSING_DTC_FLDCM_1_INDEX] == 0)
       {
           DTC_Msg_Timeout_Flag[NODE_MISSING_DTC_FLDCM_1_INDEX] = FALSE;
       }
    }	
    DTC_Timeout_Counter[NODE_MISSING_DTC_FLDCM_1_INDEX] = NODE_MISSING_DTC_FLDCM_1_TIMEOUT_COUNT;      
}
void AppIpduFRDCM_1_Ind(void)
{   
    if(RxCheck_E2E_Switch[COM_RXIPDUFRDCM_1] == STD_ON)
    {
       E2E_Error_CallBack(COM_RXIPDUFRDCM_1,E2E_Profile1_Check(COM_RXIPDUFRDCM_1));
    }
    
    IpduFRDCM_1_Indicator = TRUE;
    if(DTC_Recovery_Counter[NODE_MISSING_DTC_FRDCM_1_INDEX] != 0)
    {
       DTC_Recovery_Counter[NODE_MISSING_DTC_FRDCM_1_INDEX]--;
       if(DTC_Recovery_Counter[NODE_MISSING_DTC_FRDCM_1_INDEX] == 0)
       {
           DTC_Msg_Timeout_Flag[NODE_MISSING_DTC_FRDCM_1_INDEX] = FALSE;
       }
    }	
    DTC_Timeout_Counter[NODE_MISSING_DTC_FRDCM_1_INDEX] = NODE_MISSING_DTC_FRDCM_1_TIMEOUT_COUNT;      
}
void AppIpduRLDCM_1_Ind(void)
{   
    if(RxCheck_E2E_Switch[COM_RXIPDURLDCM_1] == STD_ON)
    {
       E2E_Error_CallBack(COM_RXIPDURLDCM_1,E2E_Profile1_Check(COM_RXIPDURLDCM_1));
    }
    
    IpduRLDCM_1_Indicator = TRUE;
    if(DTC_Recovery_Counter[NODE_MISSING_DTC_RLDCM_1_INDEX] != 0)
    {
       DTC_Recovery_Counter[NODE_MISSING_DTC_RLDCM_1_INDEX]--;
       if(DTC_Recovery_Counter[NODE_MISSING_DTC_RLDCM_1_INDEX] == 0)
       {
           DTC_Msg_Timeout_Flag[NODE_MISSING_DTC_RLDCM_1_INDEX] = FALSE;
       }
    }	
    DTC_Timeout_Counter[NODE_MISSING_DTC_RLDCM_1_INDEX] = NODE_MISSING_DTC_RLDCM_1_TIMEOUT_COUNT;      
}
#else
#error "the define E0X_DCM is error!"
#endif 

void AppIpduVCC_1_Ind(void)
{  

}

void AppIpduVCC_2_Ind(void)
{  

}


void AppIpduVCC_4_Ind(void)
{  

}


void AppIpduVCC_5_Ind(void)
{  

   
}


void AppIpduVCC_6_Ind(void)
{  

  
}


void AppIpduONEBOX_1_G_Ind(void)
{  

}

void AppIpduRZCU_1_Ind(void)
{   
    
}

void AppIpduTMS_1_Ind(void)
{  
    
}

void AppIpduFLZCU_9_Ind(void)
{   

}

void AppIpduBNCM_6_Ind(void)
{   

}

void AppIpduVCU_1_G_Ind(void)
{   

}


void AppIpduVCU_2_G_Ind(void)
{   

}

void AppIpduICC_COM_1_Ind(void)
{   

}

void AppIpduICC_COM_8_Ind(void)
{   

}

void AppIpduRLCR_1_Ind(void)
{   

}

void AppIpduRLCR_2_Ind(void)
{   

}

void AppIpduICC_BD_11_Ind(void)
{   

}

void AppIpduASU_1_Ind(void)
{   

}

void AppIpduRRCR_1_Ind(void)
{   

}

