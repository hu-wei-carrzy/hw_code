/*  BEGIN_FILE_HDR
************************************************************************************************
*   NOTICE
*   This software is the property of Chery Technologies. Any information contained in this
*   doc should not be reproduced, or used, or disclosed without the written authorization from
*   HiRain Technologies.
************************************************************************************************
*   File Name       : BSP_DIO.c
************************************************************************************************
*   Project/Product :
*   Title           :
*   Author          :
************************************************************************************************
*   Description     : This file is used to implement the callback function.
*
************************************************************************************************
*   Limitations     :
*
************************************************************************************************
*
************************************************************************************************
*   Revision History:
*
*   Version     Date          Initials      CR#                    Descriptions
*   ---------   ----------    ------------  ----------             ---------------
*   1.0         2024/1/1      zhaojiangbo     N/A                    Original
*   1.1         2025/10/28    Na.hu           N/A                    �޸�DIN���ļ���ʽ
************************************************************************************************
* END_FILE_HDR*/
//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//
// #include <system_file_name.h>
// #include "project_file_name.h"
//------------------------------------------------------------------------------
#define BSP_DIO  "BSP_DIO"
//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//------------------------------------------------------------------------------
#include"BSP_DIO.h"
#include"deftypes.h"

#include "BSP_DIO_EXPORT.h"
#include "BSP_DIO_CFG_GEN.h"

//------------------------------------------------------------------------------
// Local constants
// #define cMinDuty					((U8)0)
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Local macros
// #define BSPxxx TOSxxx()
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Local data
// static unit8  tDATxxx_TaskAlarm;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Exported data
// unit8 u8Exportxxx;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Local function prototypes
//
// static tTypeRetour FunctionName(tTypeArgument1 ArgumentName1, ... );
//------------------------------------------------------------------------------


//==============================================================================
//=========================== LOCAL FUNCTIONS ==================================
//==============================================================================
/***************************************************************************
 ���ƣ�BSP_PORTA_IRQManage
 ���ã�PDC101��Ŀ��ʹ�ã���Ҫ��Ӳ�߻��ѣ�Ŀǰ��Ŀʹ�ò���
  ���룺��
 ���أ���
 ������
****************************************************************************/
/*
void BSP_PORTA_IRQManage (void)
{
	if(((((PORTA->ISFR) >>(in_put_cfg_arr[IN_DI_WakeUp_N_W].Gpio_Base.pinPortIdx)) & 0x00000001)==0x00000001))//�����IN_DI_WakeUp_N_W�ж�
	{
		PORTA->PCR[in_put_cfg_arr[IN_DI_WakeUp_N_W].Gpio_Base.pinPortIdx]=	PORTA->PCR[in_put_cfg_arr[IN_DI_WakeUp_N_W].Gpio_Base.pinPortIdx];//���жϱ�־λ
		FALLING_EDG_WKE_IRQManage();			//A12���½�����Ч����ܽ��жϴ�������
		LDBDinDIWakeUpIsr();
		PORTC->PCR[in_put_cfg_arr[IN_DI_WakeUp_P_W].Gpio_Base.pinPortIdx]=	PORTC->PCR[in_put_cfg_arr[IN_DI_WakeUp_P_W].Gpio_Base.pinPortIdx];//���жϱ�־λ
	}
}

void BSP_PORTC_IRQManage (void)
{
	if(((((PORTC->ISFR) >>(in_put_cfg_arr[IN_DI_WakeUp_P_W].Gpio_Base.pinPortIdx)) & 0x00000001)==0x00000001))//�����IN_DI_WakeUp_P_W�ж�
	{
		PORTC->PCR[in_put_cfg_arr[IN_DI_WakeUp_P_W].Gpio_Base.pinPortIdx]=	PORTC->PCR[in_put_cfg_arr[IN_DI_WakeUp_P_W].Gpio_Base.pinPortIdx];//���жϱ�־λ
//		RISING_EDGE_WKE_IRQManage();//C08����������Ч����ܽ��жϴ�������
        LDBDinDIWakeUpIsr();
    }
}


extern volatile U8 gu8WakeUp;
void PORTB_IRQHandler (void)
{
    gu8WakeUp = 1u;
	__asm volatile ("sev");
	
	PORTB->PCR[9] |= 0x1000000;
	PORTB->PCR[12] |= 0x1000000;
    LDBDinDIWakeUpIsr();
}

void PORTD_IRQHandler (void)
{
    gu8WakeUp = 1u;
	__asm volatile ("sev");
	PORTD->PCR[3] |= 0x1000000;
	PORTD->PCR[4] |= 0x1000000;
    LDBDinDIWakeUpIsr();
}
#endif
*/
extern volatile U8 gu8WakeUp;
void BSP_PORTB_IRQManage (void)
{
	// if(((((PORTB->ISFR) >>(in_put_cfg_arr[IN_HALL5].Gpio_Base.pinPortIdx)) & 0x00000001)==0x00000001))//如果是IN_DI_WakeUp_N_W中断
	// {
	// 	PORTB->PCR[in_put_cfg_arr[IN_HALL5].Gpio_Base.pinPortIdx]=	PORTB->PCR[in_put_cfg_arr[IN_HALL5].Gpio_Base.pinPortIdx];//清中断标志位
	// 	//FALLING_EDG_WKE_IRQManage();			//A12，下降沿有效激活管脚中断处理函数
	// 	LDBDinDIWakeUpIsr();
	// }
    gu8WakeUp = 1u;
    __asm volatile ("sev");
    PORTB->PCR[14] |= 0x1000000;  // 清除PORTB[14]中断标志
    LDBDinDIWakeUpIsr();
}


/***************************************************************************
 名称：BSPGpioIRQInit
 作用：GPIO中断初始化函数
  输入：无
 返回：无
 描述：
****************************************************************************/
void BSPGpioIRQInit ()
{
#if 0	//TODO:XXX
    //WakeUpCode
    //�жϱ�ſ������ж�������IRQn_Type�в�ѯ
    INT_SYS_DisableIRQ(PORTA_IRQn);	//ʹ���ж�
    INT_SYS_DisableIRQ(PORTC_IRQn);	//ʹ���ж�
    INT_SYS_InstallHandler(PORTA_IRQn, BSP_PORTA_IRQManage, (isr_t *) 0);	//��PORTA�˿ڵ��жϴ�������
    INT_SYS_InstallHandler(PORTC_IRQn, BSP_PORTC_IRQManage, (isr_t *) 0);	//��PORTC�˿ڵ��жϴ�������
#endif

    INT_SYS_DisableIRQ(PORTB_IRQn);	//使能中断
    INT_SYS_InstallHandler(PORTB_IRQn, BSP_PORTB_IRQManage, (isr_t *) 0);	//绑定PORTB端口的中断处理函数

    return;
}
/***************************************************************************
 ���ƣ�BSPDioEnableDIOInt
 ���ã�GPIO�ж�ʹ�ܺ���
  ���룺��
 ���أ���
 ������
****************************************************************************/
void BSPDioEnableDIOInt (void)
{
    // 将 PORTB[14] 从 FTM 功能 (ALT2) 切换到 GPIO 模式
    PORTB->PCR[14] = PORT_PCR_MUX(1u) | PORT_PCR_IRQC(10u);  // GPIO + 下降沿中断
    
    // 使能 PORTB 中断
    INT_SYS_SetPriority(PORTB_IRQn, 0xF0u);
    INT_SYS_ClearPending(PORTB_IRQn);
    INT_SYS_EnableIRQ(PORTB_IRQn);
}
/***************************************************************************
 ���ƣ�BSPDioDisableDIOInt
 ���ã�GPIO�ж����κ���
  ���룺��
 ���أ���
 ������
****************************************************************************/
void BSPDioDisableDIOInt (void)
{
    // 禁用 PORTB 中断
    INT_SYS_DisableIRQ(PORTB_IRQn);
    
    // 恢复 PORTB[14] 为 FTM 功能 (ALT2)
    PORTB->PCR[14] = PORT_PCR_MUX(2u);  // ALT2 模式

}
/***************************************************************************
 ���ƣ�BSPGetInputState
 ���ã�GPIO��������״̬���ж��Ǹߵ�ƽ���ǵ͵�ƽ
  ���룺��
 ���أ���
 ������
****************************************************************************/
input_state BSPGetInputState (gpio_input_index Index)
{
    input_state Input_State = INPUTOFF;
    const GPIO_Type * const base = in_put_cfg_arr[Index].Gpio_Base.base;
    pins_channel_type_t pin = in_put_cfg_arr[Index].Gpio_Base.pinPortIdx;
    /*****************************
     * �����Ƿ���Ҫ�������ͨ���ŵĺϷ������жϣ���Ҫ��ȷ��
     *
     * *********************************/
    if ((((base->PDIR) >> pin) & 0x01u) == 1u)
    {
        Input_State = INPUTON;
    }
    else
    {
        Input_State = INPUTOFF;
    }

    return Input_State;
}
/***************************************************************************
 ���ƣ�BSPGpioCtr
 ���ã�GPIO������ƺ���
  ���룺��
 ���أ���
 ������
****************************************************************************/
void BSPGpioCtr (gpio_output_index Index, out_put_ctr_cmd Cmd)
{
    GPIO_Type * const base = out_put_cfg_arr[Index].Gpio_Base.base;
    pins_channel_type_t pin = out_put_cfg_arr[Index].Gpio_Base.pinPortIdx;
//	pins_level_type_t 				value		=(pins_level_type_t)Cmd;
    /*****************************
     * �����Ƿ���Ҫ�������ͨ���ŵĺϷ������жϣ���Ҫ��ȷ��
     * �Ƿ���Ҫ�Թܽ�����״̬����һ���жϣ��Է�������Ϊ����ĹܽŽ����������
     * *********************************/
    pins_channel_type_t pinsValues = (pins_channel_type_t) base->PDOR;
    pinsValues &= (pins_channel_type_t) (~((pins_channel_type_t) 1U << pin));
    pinsValues |= (pins_channel_type_t) ((pins_channel_type_t) Cmd << pin);

    base->PDOR = GPIO_PDOR_PDO(pinsValues);
}



//==============================================================================
//=========================== EXPORTED FUNCTIONS ===============================
//==============================================================================
/***************************************************************************
 ���ƣ�BSPGpioInit
 ���ã�GPIO���ܳ�ʼ��������ʹ���°��SDK
  ���룺��
 ���أ���
 ������
****************************************************************************/
void BSPGpioInit (void)
{
    unsigned char Loop;
    unsigned char pinCount = NUM_OF_CONFIGURED_PINS;

    for (Loop = 0U; Loop < pinCount; Loop++)
    {
        (void) PINS_Init(&g_pin_mux_InitConfigArr[Loop]);
    }

    BSPGpioIRQInit();
}
/***************************************************************************
 ���ƣ�BSPOutputCtr
 ���ã�GPIO���ܳ�ʼ��������ʹ���°��SDK
  ���룺��
 ���أ���
 ������
****************************************************************************/
void BSPOutputCtr (gpio_output_index Index, out_put_ctr_cmd Cmd)
{

	switch (Cmd)
    {
        case TurnON:
            BSPGpioCtr(Index, TurnON);

            break;
        case TurnOFF:
            BSPGpioCtr(Index, TurnOFF);

            break;
        default:
            break;
    }
}

/***************************************************************************
 ���ƣ�BSP_I2C_SDA_Pin_IOChange
 ���ã�GPIO��Ϊģ��IIC�Ĺ��ܣ�����Ϊ���ģʽ����
  ���룺��
 ���أ���
 ������
****************************************************************************/
void BSP_I2C_SDA_Pin_IOChange (io_state Sta)
{
    uint32_t directions = 0;

    //I2C_SDA �ܽ���A02,���Ӳ���ܽŸ��ģ�������Ҫͬ���޸�

    directions = (uint32_t) (i2c_sda_pin_cfg.base->PDDR);
    switch (Sta)
    {
        case DIO_INPUT:
            directions &= ~(1UL << (i2c_sda_pin_cfg.pinPortIdx));
            break;
        case DIO_OUTPUT:
            directions |= (1UL << (i2c_sda_pin_cfg.pinPortIdx));
            break;
        default:
            break;
    }
    i2c_sda_pin_cfg.base->PDDR = GPIO_PDDR_PDD(directions);

}
/***************************************************************************
 ���ƣ�BSP_I2C_SDA_Ctr
 ���ã�GPIO��Ϊģ��IIC�Ĺ��ܣ���������ĸߵ��ƽ
  ���룺��
 ���أ���
 ������
****************************************************************************/
void BSP_I2C_SDA_Ctr (out_put_ctr_cmd Cmd)
{
    pins_channel_type_t pinsValues;
    //I2C_SDA �ܽ���A02,���Ӳ���ܽŸ��ģ�������Ҫͬ���޸�

    if (DIO_OUTPUT == BSP_Get_I2C_SDA_Pin_IO_CfState())	//����������ڴ˹ܽű�����ΪOUTʱ���ܵ���
    {
        pinsValues = (pins_channel_type_t) i2c_sda_pin_cfg.base->PDOR;
        pinsValues &= (pins_channel_type_t) (~((pins_channel_type_t) 1U << (i2c_sda_pin_cfg.pinPortIdx)));
        pinsValues |= (pins_channel_type_t) ((pins_channel_type_t) Cmd << (i2c_sda_pin_cfg.pinPortIdx));

        i2c_sda_pin_cfg.base->PDOR = GPIO_PDOR_PDO(pinsValues);
    }
    else
    {
        ;	//do nothing
    }
}
/***************************************************************************
 ���ƣ�BSP_I2C_SDA_Ctr
 ���ã�GPIO��Ϊģ��IIC�Ĺ��ܣ���������ĸߵ��ƽ
  ���룺��
 ���أ���
 ������
****************************************************************************/
input_state BSP_Get_I2C_SDA_Pin_InputState (void)
{
    input_state I2C_SDA_INPUT_STATE = INPUTOFF;

    if ((((i2c_sda_pin_cfg.base->PDIR) >> (i2c_sda_pin_cfg.pinPortIdx)) & 0x01u) == 1u)
    {
        I2C_SDA_INPUT_STATE = INPUTON;
    }
    else
    {
        I2C_SDA_INPUT_STATE = INPUTOFF;
    }

    return I2C_SDA_INPUT_STATE;
}
/***************************************************************************
 ���ƣ�BSP_Get_I2C_SDA_Pin_IO_CfState
 ���ã�GPIO��Ϊģ��IIC�Ĺ��ܣ��ж�IIC������������빦��
  ���룺��
 ���أ���
 ������
****************************************************************************/
io_state BSP_Get_I2C_SDA_Pin_IO_CfState (void)
{
    uint32_t directions = 0;
    io_state I2C_IO_STATE;

    //I2C_SDA �ܽ���A02,���Ӳ���ܽŸ��ģ�������Ҫͬ���޸�
    directions = (uint32_t) (i2c_sda_pin_cfg.base->PDDR);
    directions = ((directions >> (i2c_sda_pin_cfg.pinPortIdx)) & 0x00000001);
    switch (directions)
    {
        case 0:
            I2C_IO_STATE = DIO_INPUT;
            break;

        case 1:
            I2C_IO_STATE = DIO_OUTPUT;
            break;

        default:
            break;
    }

    return I2C_IO_STATE;
}

/***************************************************************************
 ���ƣ�BSP_OUT ctrls
 ���ã�GPIOֱ�ӿ�����ؽӿڵ����
  ���룺��
 ���أ���
 ������
****************************************************************************/
void BSPDioOUT_IO_LEDCtrl(out_put_ctr_cmd Cmd)
{
	BSPOutputCtr(OUT_IO_LED,Cmd);
}

void BSPDioOUT_A3G4250D_MCU_CSCtrl(out_put_ctr_cmd Cmd)
{
	BSPOutputCtr(OUT_A3G4250D_MCU_CS,Cmd);
}

void BSPDioOUT_A3G4250D_OECtrl(out_put_ctr_cmd Cmd)
{
	BSPOutputCtr(OUT_A3G4250D_OE,Cmd);
}

void BSPDioOUT_MCU_FLASH_SPI_WPCtrl(out_put_ctr_cmd Cmd)
{
	BSPOutputCtr(OUT_MCU_FLASH_SPI_WP,Cmd);
}

void BSPDioOUT_DRV_MOTOR_nSLEEPCtrl(out_put_ctr_cmd Cmd)
{
	BSPOutputCtr(OUT_DRV_MOTOR_nSLEEP,Cmd);
}

void BSPDioOUT_5V_SENSOR_ENCtrl(out_put_ctr_cmd Cmd)
{
	BSPOutputCtr(OUT_5V_SENSOR_EN,Cmd);
}

void BSPDioOUT_HDO_DSEN12Ctrl(out_put_ctr_cmd Cmd)
{
	BSPOutputCtr(OUT_HDO_DSEN12,Cmd);
}

void BSPDioOUT_CTL3408_IN_F2Ctrl(out_put_ctr_cmd Cmd)
{
	BSPOutputCtr(OUT_CTL3408_IN_F2,Cmd);
}

void BSPDioOUT_CTL3408_IN_F1Ctrl(out_put_ctr_cmd Cmd)
{
	BSPOutputCtr(OUT_CTL3408_IN_F1,Cmd);
}

void BSPDioOUT_HDO_DSEN34Ctrl(out_put_ctr_cmd Cmd)
{
	//BSPOutputCtr(OUT_HDO_DSEN34,Cmd);
}

void BSPDioOUT_HDO_IN4Ctrl(out_put_ctr_cmd Cmd)
{
	BSPOutputCtr(OUT_MOTOR_MCU_SPI_CS,Cmd);
}

void BSPDioOUT_HDO_IN3Ctrl(out_put_ctr_cmd Cmd)
{
	BSPOutputCtr(OUT_HDO_IN3,Cmd);
}

void BSPDioOUT_HDO_IN2Ctrl(out_put_ctr_cmd Cmd)
{
	BSPOutputCtr(OUT_HDO_IN2,Cmd);
}

void BSPDioOUT_HDO_IN1Ctrl(out_put_ctr_cmd Cmd)
{
	BSPOutputCtr(OUT_HDO_IN1,Cmd);
}

void BSPDioOUT_I2C_WCCtrl(out_put_ctr_cmd Cmd)
{
	BSPOutputCtr(OUT_I2C_WC,Cmd);
}

void BSPDioOUT_MCU_FLASH_SPI_OECtrl(out_put_ctr_cmd Cmd)
{
	BSPOutputCtr(OUT_MCU_FLASH_SPI_OE,Cmd);
}
