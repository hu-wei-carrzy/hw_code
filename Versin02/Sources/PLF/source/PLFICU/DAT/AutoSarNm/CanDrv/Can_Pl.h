/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : Can_Pl.h
********************************************************************************
*   Project/Product : AUTOSAR 4.0
*   Title           : CAN Driver platform head File
*   Author          : HeYang
********************************************************************************
*   Description     : The header file Can_Pl.h contains type definitions and
*                      macros which relate to specific MCU .
*
********************************************************************************
*   Limitations     : only used for MSCAN
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*
*   Version     Date          Initials      CR#          Descriptions
*   ---------   ----------    ------------  ----------   ---------------
*   01.00.00    06/05/2012    HeYang        N/A          Original
*   01.01.00    12/05/2012    NingChen      N/A          first test feed back ;
*   02.00.00    29/07/2013    NingChen      N/A          DPN_MSCAN_130729_1
*   02.00.01    15/08/2013    NingChen      N/A          D10_MSCAN_130815_1
*   02.00.02    23/09/2013    NingChen      N/A          D10_MSCAN_130923_1     
********************************************************************************
* END_FILE_HDR*/
#ifndef _CAN_PL_H_
#define _CAN_PL_H_

/*******************************************************************************
*   Includes
*******************************************************************************/
//#include "ComStack_Types.h"
//#include ".\..\J1939_INCLUDE\ComStack_Types_Proxy.h"
#include "Can_Cfg.h"

/*******************************************************************************
*   Macro
*******************************************************************************/
#define CAN_HARDWARE_TIMEOUT_CHECK      STD_ON
#define CAN_ENTER_CRITICAL_SECTION()    Can_DisableGlobalInterrupts()
#define CAN_LEAVE_CRITICAL_SECTION()    Can_EnableGlobalInterrupts()
#define CAN_NOT_MATCH                   (0u)
#define CAN_MATCH                       (1u)
#define CAN_CONTROLLER_NOT_HOH          (0xffu)
#define TOTAL_CAN_MODULE_NUM            (0x5u)
#define MSK_EXT_ID_MSB                  ((uint32)(0x10000000))
#define HOH_NUM_PER_CONTROLLER          (4u)
#define HTH_NUM_PER_CONTROLLER          (3u)
#define CAN_MULTIPLEXED_HTH_MBNUM       (3u)

/*******************************************************************************
*   ISR enroll related & vetor numbers
*******************************************************************************/
#define CAN_AUTOENROLL_ISR            STD_ON

#if(CAN_AUTOENROLL_ISR == STD_OFF)
#define CAN0WAKEUP_VECTOR_NUMBER      
#define CAN0ERR_VECTOR_NUMBER         
#define CAN0RX_VECTOR_NUMBER          
#define CAN0TX_VECTOR_NUMBER          

#define CAN1WAKEUP_VECTOR_NUMBER      
#define CAN1ERR_VECTOR_NUMBER         
#define CAN1RX_VECTOR_NUMBER          
#define CAN1TX_VECTOR_NUMBER 

#define CAN2WAKEUP_VECTOR_NUMBER      
#define CAN2ERR_VECTOR_NUMBER         
#define CAN2RX_VECTOR_NUMBER          
#define CAN2TX_VECTOR_NUMBER          

#define CAN3WAKEUP_VECTOR_NUMBER      
#define CAN3ERR_VECTOR_NUMBER         
#define CAN3RX_VECTOR_NUMBER          
#define CAN3TX_VECTOR_NUMBER

#define CAN4WAKEUP_VECTOR_NUMBER      
#define CAN4ERR_VECTOR_NUMBER         
#define CAN4RX_VECTOR_NUMBER          
#define CAN4RX_VECTOR_NUMBER          

#else
/* notice: these vector numbers may be different in different MCU , here is the 
xep100 demo. When used in other MCU, pls check these vectors  */
#define CAN0WAKEUP_VECTOR_NUMBER      (36u)
#define CAN0ERR_VECTOR_NUMBER         (37u)
#define CAN0RX_VECTOR_NUMBER          (38u)
#define CAN0TX_VECTOR_NUMBER          (39u)

#define CAN1WAKEUP_VECTOR_NUMBER      (40u)
#define CAN1ERR_VECTOR_NUMBER         (41u)
#define CAN1RX_VECTOR_NUMBER          (42u)
#define CAN1TX_VECTOR_NUMBER          (43u)

#define CAN2WAKEUP_VECTOR_NUMBER      (44u)
#define CAN2ERR_VECTOR_NUMBER         (45u)
#define CAN2RX_VECTOR_NUMBER          (46u)
#define CAN2TX_VECTOR_NUMBER          (47u)

#define CAN3WAKEUP_VECTOR_NUMBER      (48u)
#define CAN3ERR_VECTOR_NUMBER         (49u)
#define CAN3RX_VECTOR_NUMBER          (50u)
#define CAN3TX_VECTOR_NUMBER          (51u)

#define CAN4WAKEUP_VECTOR_NUMBER      (52u)
#define CAN4ERR_VECTOR_NUMBER         (53u)
#define CAN4RX_VECTOR_NUMBER          (54u)
#define CAN4TX_VECTOR_NUMBER          (55u)

#endif

/*******************************************************************************
*   Typedef
*******************************************************************************/
typedef volatile struct
{
    #if (STD_ON == CAN_ENABLE_EXTERNED_ID)
    volatile uint32 Id;
    #else
    volatile uint16 Id;             /* Identifier Register 0,1                */
    volatile uint16 IdExt;          /* Identifier Register 2,3                */
    #endif
    volatile uint8  DataSeg[8];     /* Data 0 .. 7                            */
    volatile uint8  Dlc;            /* Data length reg.:  X X X X DLC3 DLC2
                                                                   DLC1 DLC0  */
    volatile uint8  Priority;       /* TxBuf priority reg.                    */
    volatile uint16 TimeStamp;
}Can_MsgBufType;

typedef volatile struct
{
    /* RXFRM RXACT  CSWAI   SYNCH   TIME    WUPE    SLPRQ  INITRQ   */
    volatile uint8      CanCTL0;
    /* CANE  CLKSRC LOOPB   LISTEN  0       WUPM    SLPAK  INITAK   */
    volatile uint8      CanCTL1;
    /* SJW1  SJW0   BRP5    BRP4    BRP3    BRP2    BRP1   BRP0     */
    volatile uint8      CanBTR0;
    /* SAMP  TSEG22 TSEG21  TSEG20  TSEG13  TSEG12  TSEG11 TSEG10   */
    volatile uint8      CanBTR1;
    /* WUPIF CSCIF  RSTAT1  RSTAT0  TSTAT1  TSTAT0  OVRIF  RXF      */
    volatile uint8      CanRFLG;
    /* WUPIE CSCIF  RSTATE1 RSTATE0 TSTATE1 TSTATE0 OVRIE  RXE      */
    volatile uint8      CanRIER;
    /* 0     0      0       0       0       TXE2    TXE1   TXE0     */
    volatile uint8      CanTFLG;
    /* 0     0      0       0       0       TXEIE2  TXEIE1 TXEIE0   */
    volatile uint8      CanTIER;
    /* 0     0      0       0       0       ABTRQ2  ABTRQ1 ABTRQ0   */
    volatile uint8      CanTARQ;
    /* 0     0      0       0       0       ABTAK2  ABTAK1 ABTAK0   */
    volatile uint8      CanTAAK;
    /* 0     0      0       0       0       TXE2    TXE1   TXE0     */
    volatile uint8      CanTBSEL;
     /* 0     0      IDAM1   IDAM0   0       0       IDHIT1 IDHIT0  */
    volatile uint8      CanIDAC;
    volatile uint8      Reserved1;
    /* 0     0      0       0       0       0       0      BOHOLD   */
    volatile uint8      CanMISC;
    volatile uint8      CanRXERR;       /* RXERR7 ... RXERR0                  */
    volatile uint8      CanTXERR;       /* TXERR7 ... TXERR0                  */
    /* Identifier Acceptance and Filter Masks 0..3*/
    volatile uint8      CanIDAR0;
    volatile uint8      CanIDAR1;
    volatile uint8      CanIDAR2;
    volatile uint8      CanIDAR3;
    volatile uint8      CanIDMR0;
    volatile uint8      CanIDMR1;
    volatile uint8      CanIDMR2;
    volatile uint8      CanIDMR3;
    /* Identifier Acceptance and Filter Masks 4..7 */
    volatile uint8      CanIDAR4;
    volatile uint8      CanIDAR5;
    volatile uint8      CanIDAR6;
    volatile uint8      CanIDAR7;
    volatile uint8      CanIDMR4;
    volatile uint8      CanIDMR5;
    volatile uint8      CanIDMR6;
    volatile uint8      CanIDMR7;
    Can_MsgBufType      CanRxBuf;        /* Rx-Msg Buffer */
    Can_MsgBufType      CanTxBuf;        /* Tx-Msg Buffer */
} Can_RegType;

typedef volatile struct
{
    /* RXFRM RXACT  CSWAI   SYNCH   TIME    WUPE    SLPRQ  INITRQ       */
    uint8      CanInitCTL0;
    /* CANE  CLKSRC LOOPB   LISTEN  0       WUPM    SLPAK  INITAK       */
    uint8      CanInitCTL1;
    /* BTR0  SJW1  SJW0   BRP5    BRP4    BRP3    BRP2    BRP1   BRP0   */
    uint8      CanInitBTR0;
    /* BTR1  SAMP  TSEG22 TSEG21  TSEG20  TSEG13  TSEG12  TSEG11 TSEG10 */
    uint8      CanInitBTR1;
    /* WUPIE CSCIF  RSTATE1 RSTATE0 TSTATE1 TSTATE0 OVRIE  RXE          */
    uint8      CanInitRIER;
    /* 0     0      0       0       0       TXEIE2  TXEIE1 TXEIE0       */
    uint8      CanInitTIER;
    /* 0     0      IDAM1   IDAM0   0       0       IDHIT1 IDHIT0       */
    uint8      CanInitIDAC;
    /* Identifier Acceptance and Filter Masks 0..3                      */
    uint8      CanInitIDAR0;
    uint8      CanInitIDAR1;
    uint8      CanInitIDAR2;
    uint8      CanInitIDAR3;
    uint8      CanInitIDMR0;
    uint8      CanInitIDMR1;
    uint8      CanInitIDMR2;
    uint8      CanInitIDMR3;
    /* Identifier Acceptance and Filter Masks 4..7 */
    uint8      CanInitIDAR4;
    uint8      CanInitIDAR5;
    uint8      CanInitIDAR6;
    uint8      CanInitIDAR7;
    uint8      CanInitIDMR4;
    uint8      CanInitIDMR5;
    uint8      CanInitIDMR6;
    uint8      CanInitIDMR7;
} Can_RegInitType;

typedef struct
{
    uint8      oldCanRIER;
    uint8      oldCanTIER;
}Can_OldIERType;

/*******************************************************************************
*  Register definitions
*******************************************************************************/


#define CAN_CONTROLLER_BASIS_ADR(controllerID)     \
                                ((Can_RegType *)(CanBasisAddress[controllerID]))
#define CTL0(controllerID)     (CAN_CONTROLLER_BASIS_ADR(controllerID)->CanCTL0)
#define CTL1(controllerID)     (CAN_CONTROLLER_BASIS_ADR(controllerID)->CanCTL1)
#define BTR0(controllerID)     (CAN_CONTROLLER_BASIS_ADR(controllerID)->CanBTR0)
#define BTR1(controllerID)     (CAN_CONTROLLER_BASIS_ADR(controllerID)->CanBTR1)
#define RFLG(controllerID)     (CAN_CONTROLLER_BASIS_ADR(controllerID)->CanRFLG)
#define RIER(controllerID)     (CAN_CONTROLLER_BASIS_ADR(controllerID)->CanRIER)
#define TFLG(controllerID)     (CAN_CONTROLLER_BASIS_ADR(controllerID)->CanTFLG)
#define TIER(controllerID)     (CAN_CONTROLLER_BASIS_ADR(controllerID)->CanTIER)
#define TARQ(controllerID)     (CAN_CONTROLLER_BASIS_ADR(controllerID)->CanTARQ)
#define TAAK(controllerID)     (CAN_CONTROLLER_BASIS_ADR(controllerID)->CanTAAK)
#define TBSEL(controllerID)   (CAN_CONTROLLER_BASIS_ADR(controllerID)->CanTBSEL)
#define IDAC(controllerID)     (CAN_CONTROLLER_BASIS_ADR(controllerID)->CanIDAC)
#define MISC(controllerID)     (CAN_CONTROLLER_BASIS_ADR(controllerID)->CanMISC)
#define RXERR(controllerID)   (CAN_CONTROLLER_BASIS_ADR(controllerID)->CanRXERR)
#define TXERR(controllerID)   (CAN_CONTROLLER_BASIS_ADR(controllerID)->CanTXERR)
#define IDAR0(controllerID)   (CAN_CONTROLLER_BASIS_ADR(controllerID)->CanIDAR0)
#define IDAR1(controllerID)   (CAN_CONTROLLER_BASIS_ADR(controllerID)->CanIDAR1)
#define IDAR2(controllerID)   (CAN_CONTROLLER_BASIS_ADR(controllerID)->CanIDAR2)
#define IDAR3(controllerID)   (CAN_CONTROLLER_BASIS_ADR(controllerID)->CanIDAR3)
#define IDMR0(controllerID)   (CAN_CONTROLLER_BASIS_ADR(controllerID)->CanIDMR0)
#define IDMR1(controllerID)   (CAN_CONTROLLER_BASIS_ADR(controllerID)->CanIDMR1)
#define IDMR2(controllerID)   (CAN_CONTROLLER_BASIS_ADR(controllerID)->CanIDMR2)
#define IDMR3(controllerID)   (CAN_CONTROLLER_BASIS_ADR(controllerID)->CanIDMR3)
#define IDAR4(controllerID)   (CAN_CONTROLLER_BASIS_ADR(controllerID)->CanIDAR4)
#define IDAR5(controllerID)   (CAN_CONTROLLER_BASIS_ADR(controllerID)->CanIDAR5)
#define IDAR6(controllerID)   (CAN_CONTROLLER_BASIS_ADR(controllerID)->CanIDAR6)
#define IDAR7(controllerID)   (CAN_CONTROLLER_BASIS_ADR(controllerID)->CanIDAR7)
#define IDMR4(controllerID)   (CAN_CONTROLLER_BASIS_ADR(controllerID)->CanIDMR4)
#define IDMR5(controllerID)   (CAN_CONTROLLER_BASIS_ADR(controllerID)->CanIDMR5)
#define IDMR6(controllerID)   (CAN_CONTROLLER_BASIS_ADR(controllerID)->CanIDMR6)
#define IDMR7(controllerID)   (CAN_CONTROLLER_BASIS_ADR(controllerID)->CanIDMR7)
#define RxBuf(controllerID)   (CAN_CONTROLLER_BASIS_ADR(controllerID)->CanRxBuf)
#define TxBuf(controllerID)   (CAN_CONTROLLER_BASIS_ADR(controllerID)->CanTxBuf)

/*******************************************************************************
*  Register Mask Value define
*******************************************************************************/

/* Bitmask of CANCTL0: */
#define INITRQ   ((uint8)0x01)    /* initialized mode request                 */
#define SLPRQ    ((uint8)0x02)    /* requests to enter sleep mode             */
#define WUPE     ((uint8)0x04)    /* wakeup enable                            */
#define TIMER    ((uint8)0x08)    /* timer enable                             */
#define SYNCH    ((uint8)0x10)    /* synchronized status                      */
#define CSWAI    ((uint8)0x20)    /* can stops in waitmode                    */
#define RXACT    ((uint8)0x40)    /* receiver active                          */
#define RXFRM    ((uint8)0x80)    /* received frame flag                      */

/* Bitmask of CANCTL1: */
#define INITAK   ((uint8)0x01u)    /* initialized mode ack                    */
#define SLPAK    ((uint8)0x02)    /* sleep mode acknowledge                   */
#define WUPM     ((uint8)0x04)    /* wakeup mode                              */
#define BORM     ((uint8)0x08)    /* bus-off Recovery upon user request       */
#define LISTEN   ((uint8)0x10)    /* listen only                              */
#define LOOPB    ((uint8)0x20)    /* loopback mode                            */
#define CLKSRC   ((uint8)0x40)    /* clocksource is bus clock                 */
#define CANE     ((uint8)0x80)    /* can enabled                              */

/* Bitmasks of CANRFLG: */
#define RXF      ((uint8)0x01)    /* receive buffer full  flag                */
#define OVRIF    ((uint8)0x02)    /* overrun  flag                            */
#define TSTAT0   ((uint8)0x04)    /* transmitter status bits TSTAT[0:1]       */
#define TSTAT1   ((uint8)0x08)    /* TSTAT[0:1] =11,bus off                   */
#define RSTAT0   ((uint8)0x10)    /* receiver status bits RSTAT[0:1]          */
#define RSTAT1   ((uint8)0x20)    /*                                          */
#define CSCIF    ((uint8)0x40)    /* can status change  flag                  */
#define WUPIF    ((uint8)0x80)    /* wake-up  flag                            */
#define BOFFIF   ((uint8)(TSTAT0|TSTAT1))  /* BusOff flag                     */


/* Bitmasks of CRIER:   */

#define RXFIE    ((uint8)0x01)    /* receive buffer full enable               */
#define OVRIE    ((uint8)0x02)    /* overrun interrupt enable                 */
#define TSTAT0E  ((uint8)0x04)    /* transmitter status change enable
                                                                  TSTAT0E[0:1]*/
#define TSTAT1E  ((uint8)0x08)    /*                                          */
#define RSTAT0E  ((uint8)0x10)    /* receiver statu change enable RSTAT0E[0:1]*/
#define RSTAT1E  ((uint8)0x20)    /*                                          */
#define CSCIE    ((uint8)0x40)    /* can status change interrupt enable       */
#define WUPIE    ((uint8)0x80)    /* wake-up interrupt enable                 */
#define BOFFIE   ((uint8)(TSTAT0E))  /* BusOff flag*/

 /* Bitmasks of CTARQ:   */
#define ABTRQ0   ((uint8)0x01)    /* abort request                            */
#define ABTRQ1   ((uint8)0x02)
#define ABTRQ2   ((uint8)0x04)

/* Bitmasks of CTAAK:    */
#define ABTAK0   ((uint8)0x01)    /* abort acknowledge                        */
#define ABTAK1   ((uint8)0x02)
#define ABTAK2   ((uint8)0x04)

/* Bitmasks of CTBSEL:   */
#define TX0           ((uint8)0x01)
#define TX1           ((uint8)0x02)
#define TX2           ((uint8)0x04)
#define TXIE          ((uint8)(TX0|TX1|TX2))
#define TXMASKALL     ((uint8)(TX0|TX1|TX2))
#define TXMASK(hth)   ((uint8)(0x01<<(hth)))

/* Bitmasks of CMISC:    */
#define BOHOLD   ((uint8)0x01)

/*******************************************************************************
*  Controller related  
*******************************************************************************/
#if (CAN_USED_CONTROLLER_NUM >= 1)

    #if (CAN0_BUSOFF_PROCESSING == CAN_INTERRUPT)
        #define CAN0_BUSOFF_INT_CFG  BOFFIE
    #elif (CAN0_BUSOFF_PROCESSING == CAN_POLLING)
        #define CAN0_BUSOFF_INT_CFG  ((uint8)0x00)
    #else
        #error "!!!ERROR FOR CAN0_BUSOFF_CFG!!!"
    #endif

    #if (CAN0_TX_PROCESSING == CAN_INTERRUPT)
        #define CAN0_TX_INT_CFG  TXIE
    #elif (CAN0_TX_PROCESSING == CAN_POLLING)
        #define CAN0_TX_INT_CFG  ((uint8)0x00)
    #else
        #error "!!!ERROR FOR CAN0_TX_CFG!!!"
    #endif

    #if (CAN0_RX_PROCESSING == CAN_INTERRUPT)
        #define CAN0_RX_INT_CFG  RXFIE
    #elif (CAN0_RX_PROCESSING == CAN_POLLING)
        #define CAN0_RX_INT_CFG  ((uint8)0x00)
    #else
        #error "!!!ERROR FOR CAN0_RX_CFG!!!"
    #endif

    #if (CAN0_WAKEUP_PROCESSING == CAN_INTERRUPT)
        #define CAN0_WAKEUP_INT_CFG  WUPIE
    #elif (CAN0_WAKEUP_PROCESSING == CAN_POLLING)
        #define CAN0_WAKEUP_INT_CFG  ((uint8)0x00)
    #else
        #error "!!!ERROR FOR CAN0_WAKEUP_CFG!!!"
    #endif

    #if (CAN0_CLKSRC_BUSCLK == STD_ON)
        #define CAN0_CLKSRC_CFG  ((uint8)0x40)
    #elif (CAN0_CLKSRC_BUSCLK == STD_OFF)
        #define CAN0_CLKSRC_CFG  ((uint8)0x00)
    #else
        #error "!!!ERROR FOR CAN0_WAKEUP_CFG!!!"
    #endif

#endif/* #if (CAN_USED_CONTROLLER_NUM>=1) */

#if (CAN_USED_CONTROLLER_NUM >= 2)

    #if (CAN1_BUSOFF_PROCESSING == CAN_INTERRUPT)
        #define CAN1_BUSOFF_INT_CFG  BOFFIE
    #elif (CAN1_BUSOFF_PROCESSING == CAN_POLLING)
        #define CAN1_BUSOFF_INT_CFG  ((uint8)0x00)
    #else
        #error "!!!ERROR FOR CAN1_BUSOFF_CFG!!!"
    #endif
    
    #if (CAN1_TX_PROCESSING == CAN_INTERRUPT)
        #define CAN1_TX_INT_CFG  TXIE
    #elif (CAN1_TX_PROCESSING == CAN_POLLING)
        #define CAN1_TX_INT_CFG  ((uint8)0x00)
    #else
        #error "!!!ERROR FOR CAN1_TX_CFG!!!"
    #endif
    
    #if (CAN1_RX_PROCESSING == CAN_INTERRUPT)
        #define CAN1_RX_INT_CFG  RXFIE
    #elif (CAN1_RX_PROCESSING == CAN_POLLING)
        #define CAN1_RX_INT_CFG  ((uint8)0x00)
    #else
        #error "!!!ERROR FOR CAN1_RX_CFG!!!"
    #endif
    
    #if (CAN1_WAKEUP_PROCESSING == CAN_INTERRUPT)
        #define CAN1_WAKEUP_INT_CFG  WUPIE
    #elif (CAN1_WAKEUP_PROCESSING == CAN_POLLING)
        #define CAN1_WAKEUP_INT_CFG  ((uint8)0x00)
    #else
        #error "!!!ERROR FOR CAN1_WAKEUP_CFG!!!"
    #endif

    #if (CAN1_CLKSRC_BUSCLK == STD_ON)
        #define CAN1_CLKSRC_CFG  ((uint8)0x40)
    #elif (CAN1_CLKSRC_BUSCLK == STD_OFF)
        #define CAN1_CLKSRC_CFG  ((uint8)0x00)
    #else
        #error "!!!ERROR FOR CAN1_WAKEUP_CFG!!!"
    #endif

#endif/* #if (CAN_USED_CONTROLLER_NUM>=2) */

#if (CAN_USED_CONTROLLER_NUM >= 3)

    #if (CAN2_BUSOFF_PROCESSING == CAN_INTERRUPT)
        #define CAN2_BUSOFF_INT_CFG  BOFFIE
    #elif (CAN2_BUSOFF_PROCESSING == CAN_POLLING)
        #define CAN2_BUSOFF_INT_CFG  ((uint8)0x00)
    #else
        #error "!!!ERROR FOR CAN2_BUSOFF_CFG!!!"
    #endif
    
    #if (CAN2_TX_PROCESSING == CAN_INTERRUPT)
        #define CAN2_TX_INT_CFG  TXIE
    #elif (CAN2_TX_PROCESSING == CAN_POLLING)
        #define CAN2_TX_INT_CFG  ((uint8)0x00)
    #else
        #error "!!!ERROR FOR CAN2_TX_CFG!!!"
    #endif
    
    #if (CAN2_RX_PROCESSING == CAN_INTERRUPT)
        #define CAN2_RX_INT_CFG  RXFIE
    #elif (CAN2_RX_PROCESSING == CAN_POLLING)
        #define CAN2_RX_INT_CFG  ((uint8)0x00)
    #else
        #error "!!!ERROR FOR CAN2_RX_CFG!!!"
    #endif
    
    #if (CAN2_WAKEUP_PROCESSING == CAN_INTERRUPT)
        #define CAN2_WAKEUP_INT_CFG  WUPIE
    #elif (CAN2_WAKEUP_PROCESSING == CAN_POLLING)
        #define CAN2_WAKEUP_INT_CFG  ((uint8)0x00)
    #else
        #error "!!!ERROR FOR CAN2_WAKEUP_CFG!!!"
    #endif

    #if (CAN2_CLKSRC_BUSCLK == STD_ON)
        #define CAN2_CLKSRC_CFG  ((uint8)0x40)
    #elif (CAN2_CLKSRC_BUSCLK == STD_OFF)
        #define CAN2_CLKSRC_CFG  ((uint8)0x00)
    #else
        #error "!!!ERROR FOR CAN2_WAKEUP_CFG!!!"
    #endif

#endif/* #if (CAN_USED_CONTROLLER_NUM>=3) */

#if (CAN_USED_CONTROLLER_NUM >= 4)

    #if (CAN3_BUSOFF_PROCESSING == CAN_INTERRUPT)
        #define CAN3_BUSOFF_INT_CFG  BOFFIE
    #elif (CAN3_BUSOFF_PROCESSING == CAN_POLLING)
        #define CAN3_BUSOFF_INT_CFG  ((uint8)0x00)
    #else
        #error "!!!ERROR FOR CAN3_BUSOFF_CFG!!!"
    #endif
    
    #if (CAN3_TX_PROCESSING == CAN_INTERRUPT)
        #define CAN3_TX_INT_CFG  TXIE
    #elif (CAN3_TX_PROCESSING == CAN_POLLING)
        #define CAN3_TX_INT_CFG  ((uint8)0x00)
    #else
        #error "!!!ERROR FOR CAN3_TX_CFG!!!"
    #endif
    
    #if (CAN3_RX_PROCESSING == CAN_INTERRUPT)
        #define CAN3_RX_INT_CFG  RXFIE
    #elif (CAN3_RX_PROCESSING == CAN_POLLING)
        #define CAN3_RX_INT_CFG  ((uint8)0x00)
    #else
        #error "!!!ERROR FOR CAN3_RX_CFG!!!"
    #endif
    
    #if (CAN3_WAKEUP_PROCESSING == CAN_INTERRUPT)
        #define CAN3_WAKEUP_INT_CFG  WUPIE
    #elif (CAN3_WAKEUP_PROCESSING == CAN_POLLING)
        #define CAN3_WAKEUP_INT_CFG  ((uint8)0x00)
    #else
        #error "!!!ERROR FOR CAN3_WAKEUP_CFG!!!"
    #endif

    #if (CAN3_CLKSRC_BUSCLK == STD_ON)
        #define CAN3_CLKSRC_CFG  ((uint8)0x40)
    #elif (CAN3_CLKSRC_BUSCLK == STD_OFF)
        #define CAN3_CLKSRC_CFG  ((uint8)0x00)
    #else
        #error "!!!ERROR FOR CAN3_WAKEUP_CFG!!!"
    #endif

#endif/* #if (CAN_USED_CONTROLLER_NUM>=4) */

#if (CAN_USED_CONTROLLER_NUM == 5)

    #if (CAN4_BUSOFF_PROCESSING == CAN_INTERRUPT)
        #define CAN4_BUSOFF_INT_CFG  BOFFIE
    #elif (CAN4_BUSOFF_PROCESSING == CAN_POLLING)
        #define CAN4_BUSOFF_INT_CFG  ((uint8)0x00)
    #else
        #error "!!!ERROR FOR CAN4_BUSOFF_CFG!!!"
    #endif
    
    #if (CAN4_TX_PROCESSING == CAN_INTERRUPT)
        #define CAN4_TX_INT_CFG  TXIE
    #elif (CAN4_TX_PROCESSING == CAN_POLLING)
        #define CAN4_TX_INT_CFG  ((uint8)0x00)
    #else
        #error "!!!ERROR FOR CAN4_TX_CFG!!!"
    #endif
    
    #if (CAN4_RX_PROCESSING == CAN_INTERRUPT)
        #define CAN4_RX_INT_CFG  RXFIE
    #elif (CAN4_RX_PROCESSING == CAN_POLLING)
        #define CAN4_RX_INT_CFG  ((uint8)0x00)
    #else
        #error "!!!ERROR FOR CAN4_RX_CFG!!!"
    #endif
    
    #if (CAN4_WAKEUP_PROCESSING == CAN_INTERRUPT)
        #define CAN4_WAKEUP_INT_CFG  WUPIE
    #elif (CAN4_WAKEUP_PROCESSING == CAN_POLLING)
        #define CAN4_WAKEUP_INT_CFG  ((uint8)0x00)
    #else
        #error "!!!ERROR FOR CAN4_WAKEUP_CFG!!!"
    #endif

    #if (CAN4_CLKSRC_BUSCLK == STD_ON)
        #define CAN4_CLKSRC_CFG  ((uint8)0x40)
    #elif (CAN4_CLKSRC_BUSCLK == STD_OFF)
        #define CAN4_CLKSRC_CFG  ((uint8)0x00)
    #else
        #error "!!!ERROR FOR CAN4_WAKEUP_CFG!!!"
    #endif

#endif/* #if (CAN_USED_CONTROLLER_NUM==5) */

/*******************************************************************************
*   Macro Fuctions definitions
*******************************************************************************/


/*Used for transmit*/
#if (STD_ON == CAN_ENABLE_EXTERNED_ID)
    #define GET_REG_STDID(id)     (((uint32)(((uint32)(id)) << 21)))
#else
    #define GET_REG_STDID(id)     ((uint16)(((uint16)(id)) << 5))
#endif


#define GET_REG_EXTID(id)         ((uint32)(((((uint32)(id)) << 3) \
                                  & ((uint32)0xFFE00000))          \
                                  |(((uint32)(id) << 1)            \
                                  &  ((uint32)0x0007FFFE))         \
                                  | ((uint32)0x00180000)))

/*Used for receive*/
#define GET_EXTID(controller)     (((uint32)(RxBuf(controller).Id  \
                                  & ((uint32)0xFFE00000)) >> 3)    \
                                  + ((uint32)(RxBuf(controller).Id \
                                  & ((uint32)0x0007FFFF)) >> 1))

#if (STD_ON == CAN_ENABLE_EXTERNED_ID)
    #define GET_STDID(controller)   ((uint16)((RxBuf(controller).Id) >> 21))
#else
    #define GET_STDID(controller)   ((uint16)(RxBuf(controller).Id) >> 5)
#endif

#if (STD_ON == CAN_ENABLE_EXTERNED_ID)
    #define GET_IDE(controller)     ((uint32)((RxBuf(controller).Id) \
                                    &((uint32)0x00080000)))
#else
    #define GET_IDE(controller)     ((uint16)((RxBuf(controller).Id) \
                                    &((uint16)0x0008)))
#endif

#define GET_DLC(controller)   ((uint8)((RxBuf(controller).Dlc) & ((uint8)0x0f)))

/*******************************************************************************
*   Loop timer define 
*******************************************************************************/
#if (STD_ON == CAN_HARDWARE_TIMEOUT_CHECK) 
    #define CAN_LOOP_BEGIN(i)      ApplTimerBegin(i)
    #define CAN_LOOP_TIMEOUT(i)    ApplTimerOutCheck(i)
    #define CAN_LOOP_END(i)        ApplTimerEnd(i) 
#else
    #define CAN_LOOP_BEGIN(i)  
    #define CAN_LOOP_TIMEOUT(i)    CAN_NOT_OK
    #define CAN_LOOP_END(i)  
#endif/* #if (STD_ON == CAN_HARDWARE_TIMEOUT_CHECK) */
        
#define INIT_ENTER_TIMEOUT        (0x0u)
#define INIT_LEAVE_TIMEOUT        (0x1u)
#define SLEEP_ENTER_TIMEOUT       (0x2u)
#define SLEEP_LEAVE_TIMEOUT       (0x3u)

#endif/* _CAN_PL_H_*/
