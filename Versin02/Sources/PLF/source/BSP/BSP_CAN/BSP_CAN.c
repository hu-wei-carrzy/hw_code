/*
 * BSP_CAN.c
 *
 *  Created on: 2018骞�10鏈�29鏃�
 *      Author: zhanghjq
 */

#include  "BSP_CAN.h"
#include "BSP_CAN_CFG.h"
#include "s32_core_cm4.h"
#include "../CANIf/CanIf_Cbk.h"
#include "./../BSP_DIO/BSP_DIO.h"

uint8 RxHrh;
uint32 RxCanId;
uint8 RxCanDlc;
const uint8 *RxCanSduPtr;

#define cTxSource_Geno      0U
#define cTxSource_LDB       1U
#define cTxSource_Invalid   (uint8)0XFFU

static uint8_t su8ModuleID = 0u;
#define ThisModuleId 	su8ModuleID
/*瀹氫箟澶氭ā鍧楃殑婧愬湴鍧�*/
const uint8_t cu8ModuleSrcId[] =
{
	0xE7,
};

const tCanChnAddrMbMax cstCanChnAdddrMbMaxCfg[CAN_CHN_END] =
{
	{ CAN0, CAN0_MAX_MB, PCC_FlexCAN0_INDEX },
	{ CAN1, CAN1_MAX_MB, PCC_FlexCAN1_INDEX },
	{ CAN2, CAN2_MAX_MB, PCC_FlexCAN2_INDEX },
};

typedef struct
{
    PduIdType u16TxedMsgIndex;
    uint8_t u8TxSource;
} tTxedMsgRecord;

static tTxedMsgRecord tTxMsg =
{
	.u16TxedMsgIndex =   0XFFFFU,
	.u8TxSource = cTxSource_Invalid
};

//baudrate define
static const uint16_t gu16Arr_Baudrate [CAN_CHN_END] =
{
    500U, 500U, 500U,
};

static const tBSPCanBitRateCfg arrBitRateCfgArray[cMaxBaudrateSelNum] =
{   //baudrate driver clock is 8M
    //u16BaudRateValue  u16Prescaler    u8ProgSegment, u8TimeSegment1   u8TimeSegment2   u8SyncJumpWidth
    { 500U,              0U,             6U,           5U,                 1U,             3U },
    { 250U,              1U,             6U,           5U,                 1U,             3U },
    { 125U,              2U,             6U,           5U,                 1U,             3U },
    { 1000U,             2U,             6U,           8U,                 2U,             3U }
};

#define mBSPCanChToReg(u8MCUCANCh)      				(cstCanChnAdddrMbMaxCfg[(u8MCUCANCh)].Addr)
#define mBSPCanChGetMaxMB(u8MCUCANCh)      				(cstCanChnAdddrMbMaxCfg[(u8MCUCANCh)].u8MaxMb)
#define mBSPCanChGetClkSet(u8MCUCANCh) 					(cstCanChnAdddrMbMaxCfg[(u8MCUCANCh)].u8ClkSel)

#define mBSPCanErrCANChPro(u8MCUCANCh)               	\
if ((u8MCUCANCh) >= CAN_CHN_END)                     	\
    { return;/*mLIBassert(cFalse);*/}                	\

#define mCanCallBackDeclare(MCUCANCh)											\
static void Router_MCUCANCh##MCUCANCh##_TxCBK(tBSPCanTxCBK*  pTxCBK);			\
static void Router_MCUCANCh##MCUCANCh##_RxCBK(tBSPCanRxCBK* ptBSPCanRxCBK);		\
static void Router_MCUCANCh##MCUCANCh##_BusOffCBK(tBSPCanErrCBK* pErrCBK);		\

#ifdef cMCUCANCh0
mCanCallBackDeclare(0)
#endif

#ifdef cMCUCANCh1
mCanCallBackDeclare(1)
#endif

#ifdef cMCUCANCh2
mCanCallBackDeclare(2)
#endif

#define mCanCallBackObj(MCUCANCh)                                                                                        \
tBSPCanCallback BSPCan_MCUCANCh##MCUCANCh##_CallBackObj =                                                                \
{                                                                                                                        \
    .pfnTxCallback = (pfBSPCanTxCallback)Router_MCUCANCh##MCUCANCh##_TxCBK         /* LDBCan_MCUCANCh0_TxCBK */,         \
    .pfnRxCallback = Router_MCUCANCh##MCUCANCh##_RxCBK                             /* LDBCan_MCUCANCh0_RxCBK */,         \
    .pfnErrCallback = (pfBSPCanErrCallback)Router_MCUCANCh##MCUCANCh##_BusOffCBK  /* LDBCan_MCUCANCh0_BusOffCBK */       \
};                                                                                                                       \

uint8_t CanIf_TxConfirmationflag = 0;
uint8_t CanIf_RxIndication_flag;

#ifdef cMCUCANCh0
mCanCallBackObj(0)
#endif

#ifdef cMCUCANCh1
mCanCallBackObj(1)
#endif

#ifdef cMCUCANCh2
mCanCallBackObj(2)
#endif

static void BSPCanCfgClk (uint8_t u8MCUCANCh);
static void BSPCanBeginInit (uint8_t u8MCUCANCh);
static void BSPCanResetReg (uint8_t u8MCUCANCh);
static void BSPCanCommonRegInit (uint8_t u8MCUCANCh);
static void BSPCanSetBaudrate (uint8_t u8MCUCANCh);
static void BSPCanINTInit (uint8_t u8MCUCANCh);
static void BSPCanEndInit (uint8_t u8MCUCANCh);
static void BSPCanSetRxMb (uint8_t u8MCUCANCh, TypCanMBEm mb, uint32_t id, uint32_t mask);
static uint8_t BSPGetChPos (uint8_t u8MCUCANCh, uint8_t ch_pos);
static uint8_t BSPGetChPosByID (tBSPCanRxCBK* ptBSPCanRxCBK,uint8_t *pu8handleIndex);
static void BSPCanDefineMsgRx (uint8_t u8MCUCANCh);
static void BSPCanControlTransceiver (uint8_t u8MCUCANCh, uint8_t u8Level);
static void BSPCanRecMsgProcess (uint8_t u8MCUCANCh, TypCanMBEm mb, tBSPCanRxCBK * msg);
static void BSPCAN_RxTxIntProcess (uint8_t u8MCUCANCh);
static void BSPCanErrProcess (uint8_t u8MCUCANCh);
/***************************************************************************************************
 鍐呴儴鍑芥暟鍏ュ彛
 ***************************************************************************************************/
void BSPCanPinAsDIN_EnableINT (void)
{
    //浣胯兘杈撳叆涓柇
    //WakeUpCode
	// INT_SYS_SetPriority(PORTE_IRQn, 0xF0u);		// 浼樺厛绾ф渶浣�
    // INT_SYS_ClearPending(PORTE_IRQn);
    // INT_SYS_EnableIRQ(PORTE_IRQn);
    INT_SYS_SetPriority(PORTA_IRQn, 0xF0u);		// 优先级最低
    INT_SYS_ClearPending(PORTA_IRQn);
    INT_SYS_EnableIRQ(PORTA_IRQn);

}
void LDBDinCANWakeUpIsr(void);

extern volatile U8 gu8WakeUp;
// PORTE_IRQHandler
/**
 * @brief PORTA中断服务程序，处理唤醒事件
 * 
 * 当PORTA产生中断时，设置唤醒标志并触发事件信号。
 * 清除PORTA[12]的中断标志并调用CAN唤醒中断处理函数。
 * 
 * @note 该函数为中断服务程序，不应被直接调用
 * @note 函数内部使用汇编指令"sev"触发事件信号
 */
void PORTA_IRQHandler (void)
{
	gu8WakeUp = 1u;
	__asm volatile ("sev");
	//PORTE->PCR[4] |= 0x1000000;
    //LDBDinCANWakeUpIsr();

    // PORTE->PCR[9] |= 0x1000000;
	PORTA->PCR[12] |= 0x1000000;
    LDBDinCANWakeUpIsr();

}

void BSPCanPinAsDIN (void)
{
    //将一路CAN的接收管脚设置为GPIO的输入，
    //WakeUpCode
    //PORTE->PCR[4] = PORT_PCR_MUX(1u);
    //PORTE->PCR[4] |= PORT_PCR_IRQC(10u);	// 配置下降沿中断
    PORTA->PCR[12] = PORT_PCR_MUX(1u);
    PORTA->PCR[12] |= PORT_PCR_IRQC(10u);	// 配置下降沿中断
    
}

void BSPCanPinAsCANRx (void)
{
    //WakeUpCode
    //灏嗕竴璺疌AN鐨勬帴鏀剁鑴氳缃负GPIO鐨勮緭鍏ワ紝涓斾娇鑳借緭鍏ヤ腑鏂�
    //PORTE->PCR[4] |= PORT_PCR_MUX(5);
    //PORTE->PCR[4] |= PORT_PCR_IRQC(0u);	// 閰嶇疆涓嬮檷娌夸腑鏂�
    //将一路CAN的接收管脚设置为GPIO的输入，且使能输入中断
    PORTA->PCR[12] |= PORT_PCR_MUX(3);
    PORTA->PCR[12] |= PORT_PCR_IRQC(0u);	// 配置下降沿中断
}

void BSPCanPinAsDIN_DisableINT (void)
{
    //WakeUpCode
    // INT_SYS_DisableIRQ(PORTE_IRQn);
    INT_SYS_DisableIRQ(PORTA_IRQn);
}

void BSPCanCfgPins (void)
{
    PORTA->PCR[12] |= PORT_PCR_MUX(3); /* Port E4: MUX = ALT5, CAN0_RX */
    PORTA->PCR[13] |= PORT_PCR_MUX(3); /* Port E5: MUX = ALT5, CAN0_TX */
    //PORTE->PCR[13] |= PORT_PCR_MUX(1);           /* Port E4: MUX = ALT5, CAN0_RX */
}

void delay (U16 u16delay)
{
    U8 u8Loop;

	while(u16delay --)
	{
		for (u8Loop=0; u8Loop<200; u8Loop++);
	}
}

U8 GetCanIdSelSta (void)
{
    return su8ModuleID;
}

void BspCanIdSelInit (void)
{
    U8 u8id0;
    U8 u8id1;
    U8 u8id2;
    U8 u8idsel;
    U8 u8idselnow;
    static U8 u8RetryCnt;
    /*
    extern input_state BSPGetInputState (gpio_input_index Index);
    do
    {

        u8id0 = (BSPGetInputState(IN_ID0_IN) == 0U) ? 1U : 0U;		// 璐熸帶
        u8id1 = (BSPGetInputState(IN_DIO1) == 0U) ? 1U : 0U;		// 璐熸帶
        u8id2 = (BSPGetInputState(IN_DIO1) == 0U) ? 1U : 0U;		// 璐熸帶

        u8idsel = u8id0 + (u8id1 << 1u) + (u8id2 << 2u);
        delay(2000);				// 杩欎釜鏃堕棿闇�瑕佽皟璇曞悗纭畾

        u8id0 = (BSPGetInputState(IN_ID0_IN) == 0U) ? 1U : 0U;		// 璐熸帶
        u8id1 = (BSPGetInputState(IN_DIO1) == 0U) ? 1U : 0U;		// 璐熸帶
        u8id2 = (BSPGetInputState(IN_DIO1) == 0U) ? 1U : 0U;		// 璐熸帶

        u8idselnow = u8id0 + (u8id1 << 1u) + (u8id2 << 2u);
    }while ((u8idselnow != u8idsel) && (u8RetryCnt < 5u));		// 娆℃暟闇�瑕佽皟璇曞悗纭畾
*/
   u8idselnow = 0u;
    /* 鐢变簬绯荤粺闇�姹傚苟涓嶆槸鎸夋甯搁『搴忔潵锛屾墍浠ユ澶勯渶瑕佽浆鎹㈠嚱鏁� */
/*
    switch (u8idselnow)
    {
        case 1:
            su8ModuleID = 0u;
            break;
        case 2:
            su8ModuleID = 1u;
            break;
        case 3:
            su8ModuleID = 3u;
            break;
        case 4:
            su8ModuleID = 2u;
            break;
        case 5:
            su8ModuleID = 4u;
            break;
        case 6:
            su8ModuleID = 5u;
            break;
        case 0:
            su8ModuleID = 6u;
            break;
        case 7:
            su8ModuleID = 7u;
            break;

        default:
            break;
    }
*/
}

/* 閰嶇疆鎺у埗鏃堕挓 */
static void BSPCanCfgClk (uint8_t u8MCUCANCh)
{
    uint8_t t_clk;

    mBSPCanErrCANChPro(u8MCUCANCh);
    t_clk = mBSPCanChGetClkSet(u8MCUCANCh);

    PCC->PCCn[t_clk] |= PCC_PCCn_CGC_MASK; /* 閫夋嫨鎺у埗鏃堕挓 */
}

static void BSPCanBeginInit (uint8_t u8MCUCANCh)
{
    volatile CAN_Type * p;

    mBSPCanErrCANChPro(u8MCUCANCh);
    p = mBSPCanChToReg(u8MCUCANCh);

    p->MCR &= ~CAN_MCR_MDIS_MASK; /* 浣胯兘CAN妯″潡 */

	p->MCR = (p->MCR & ~CAN_MCR_FRZ_MASK) | CAN_MCR_FRZ(1U);
	p->MCR = (p->MCR & ~CAN_MCR_HALT_MASK) | CAN_MCR_HALT(1U);
	/* Wait for entering the freeze mode */
	while (((p->MCR & CAN_MCR_FRZACK_MASK) >> CAN_MCR_FRZACK_SHIFT) == 0U) {}
}

static void BSPCanResetReg (uint8_t u8MCUCANCh)
{
    volatile CAN_Type * p;

    mBSPCanErrCANChPro(u8MCUCANCh);
    p = mBSPCanChToReg(u8MCUCANCh);

    p->MCR |= CAN_MCR_SOFTRST_MASK;             /* 澶嶄綅CAN妯″潡瀵勫瓨鍣� */
    while(p->MCR & CAN_MCR_SOFTRST_MASK);       /* 绛夊緟澶嶄綅瀹屾垚锛屽浣嶅畬鎴愯繘鍏ュ喕缁撴ā寮� */
}

static void BSPCanCommonRegInit (uint8_t u8MCUCANCh)
{
    volatile CAN_Type * p;
    U8 max_mb;
    U8 i;

    mBSPCanErrCANChPro(u8MCUCANCh);
    p = mBSPCanChToReg(u8MCUCANCh);
    max_mb = mBSPCanChGetMaxMB(u8MCUCANCh);

    p->CTRL1 &= ~CAN_CTRL1_CLKSRC_MASK; /* 閫夋嫨妯″潡鏃堕挓涓烘櫠鎸椂閽�8m */

    p->MCR |= CAN_MCR_IRMQ_MASK; /* 浣胯兘鍗曢�氶亾鎺╃爜鍔熻兘 */
    //p->MCR &= ~CAN_MCR_WRNEN_MASK;            /* Disable the warning interrupts */
    p->MCR |= CAN_MCR_SRXDIS_MASK; /* disable frame self reception by setting the SRXDIS bit */
    p->MCR &= ~CAN_MCR_RFEN_MASK; /* Disable the Rx FIFO by clear the RFEN bit */
    p->MCR &= ~CAN_MCR_DMA_MASK; /* Rx FIFO is disabled and DMA is not required, clear DMA bit */
    p->MCR &= ~CAN_MCR_PNET_EN_MASK; /* 鏆傛椂涓嶉渶瑕佷娇鐢≒retended Networking mode */
    p->MCR |= CAN_MCR_AEN_MASK; /* 闇�瑕佷娇鐢╝bort mechanism */
    p->MCR &= ~CAN_MCR_LPRIOEN_MASK; /* 鏆傛椂涓嶉渶瑕佷娇鐢╨ocal priority feature */

    for (i = 0u; i < 16u; i++) /* 鍒濆鍖栨墍鏈夌殑CAN鎺ユ敹鎺╃爜涓哄叏閮紝鍏ㄩ儴绂佹 */
    {
        p->RXIMR[i] = 0xFFFFFFFFu;
    }

    for (i = 0; i <= max_mb; i++) /* 鍒濆鍖栨墍鏈夌殑MB鍖哄煙 */
    {
        p->RAMn[GET_MB_POS(i, MB_CTL_POS)] = 0x00u;
        p->RAMn[GET_MB_POS(i, MB_ID_POS)] = 0x00u;
        p->RAMn[GET_MB_POS(i, MB_DAT1_POS)] = 0x00u;
        p->RAMn[GET_MB_POS(i, MB_DAT2_POS)] = 0x00u;
    }

    p->MCR |= max_mb; /* 鏈�鍚庝竴涓帴鏀堕偖绠辨槸31 */
}

static void BSPCanSetBaudrate (uint8_t u8MCUCANCh)
{
    volatile CAN_Type * p;
    const tBSPCanBitRateCfg* pstcConfig = (tBSPCanBitRateCfg*) 0;
    uint16_t u16BaudRateValue;
    uint8_t u8Loop;

    mBSPCanErrCANChPro(u8MCUCANCh)
    p = mBSPCanChToReg(u8MCUCANCh);

    u16BaudRateValue = gu16Arr_Baudrate[u8MCUCANCh];

    if (u16BaudRateValue > 0U)
    {
        for (u8Loop = 0U; u8Loop < cMaxBaudrateSelNum; u8Loop++)
        {
            if (arrBitRateCfgArray[u8Loop].u16BaudRateValue == u16BaudRateValue)
            {
                pstcConfig = (&(arrBitRateCfgArray[u8Loop]));
                break;
            }
        }

        if (u8Loop == cMaxBaudrateSelNum)
        { // 閿欒鐨勬尝鐗圭巼鏁板�硷紝娌℃湁鎵惧埌
            return;
        }
    }

    p->CTRL1 &= ~(CAN_CTRL1_PROPSEG_MASK + CAN_CTRL1_PSEG2_MASK
                  + CAN_CTRL1_PRESDIV_MASK + CAN_CTRL1_PSEG1_MASK + CAN_CTRL1_RJW_MASK);     /* 鍏堟竻闆讹紝鍐嶇疆浣� */

    p->CTRL1 |= CAN_CTRL1_PROPSEG(pstcConfig->u8ProgSegment) + CAN_CTRL1_PSEG2(pstcConfig->u8TimeSegment2)
    				+ CAN_CTRL1_PRESDIV(pstcConfig->u16Prescaler) + CAN_CTRL1_PSEG1(pstcConfig->u8TimeSegment1)
					+ CAN_CTRL1_RJW(pstcConfig->u8SyncJumpWidth);

}

static void BSPCanINTInit (uint8_t u8MCUCANCh)
{
    volatile CAN_Type * p;

    mBSPCanErrCANChPro(u8MCUCANCh);
    p = mBSPCanChToReg(u8MCUCANCh);

    p->MCR &= ~CAN_MCR_WRNEN_MASK; /* Disable the warning interrupts */
    p->CTRL1 &= ~CAN_CTRL1_TWRNMSK_MASK;
    p->CTRL1 &= ~CAN_CTRL1_TWRNMSK_MASK;

    p->CTRL1 |= CAN_CTRL1_BOFFREC_MASK; /* 鍏抽棴BUSOFF鑷姩鎭㈠鏈哄埗 */
    p->CTRL1 |= CAN_CTRL1_BOFFMSK_MASK; /* 鎵撳紑BUSOFF涓柇 */
}

static void BSPCanEndInit (uint8_t u8MCUCANCh)
{
    volatile CAN_Type * p;

    mBSPCanErrCANChPro(u8MCUCANCh)
    p = mBSPCanChToReg(u8MCUCANCh);

	p->MCR &= ~(CAN_MCR_FRZ_MASK);              /* 娓呴櫎鍐荤粨鏍囧織浣� */
    while (p->MCR & CAN_MCR_FRZACK_MASK);       /* 绛夊緟閫�鍑哄喕缁撴ā寮� */
}

static void BSPCanSetRxMb (uint8_t u8MCUCANCh, TypCanMBEm mb, uint32_t id, uint32_t mask)
{
    volatile CAN_Type * p;

    mBSPCanErrCANChPro(u8MCUCANCh);
    p = mBSPCanChToReg(u8MCUCANCh);
    if ((u8MCUCANCh > 0) && (mb > EM_MB15)) /* 閿欒鎯呭喌 */
    {

    }

    if (mb <= EM_MB15)
    {
        p->RXIMR[mb] = mask;
    }
    else if (mask != 0xFFFFFFFFu)	// 閿欒鎯呭喌
    {
    	// p->RXIMR[mb] = mask;
    }

    if(id < 0x7FF)
    {
        p->RAMn[GET_MB_POS(mb, MB_ID_POS)] = (id<<STANDARD_POS);
        p->RAMn[GET_MB_POS(mb, MB_CTL_POS)] = (CODE_REC_ACTIVE << MB_CTL_CODE_POS) + (IDE_STANDARD << MB_CTL_IDE_POS);
    }
    else
    {
        p->RAMn[GET_MB_POS(mb, MB_ID_POS)] = id;
        p->RAMn[GET_MB_POS(mb, MB_CTL_POS)] = (CODE_REC_ACTIVE << MB_CTL_CODE_POS) + (IDE_EXTEND << MB_CTL_IDE_POS);
    }


    p->IMASK1 |= (1u << mb); /* 鎵撳紑鎺ユ敹涓柇鎺╃爜锛屽厑璁稿搴旈偖绠变腑鏂� */
}

static uint8_t BSPGetChPos (uint8_t u8MCUCANCh, uint8_t ch_pos)
{
    uint8_t u8lg_pos;

    //mBSPCanErrCANChPro(u8MCUCANCh);

    if (u8MCUCANCh == 0u)
    {
        u8lg_pos = ch_pos;
    }
    else
    {
        u8lg_pos = (u8MCUCANCh - 1) * 15u + 31u + ch_pos;
    }

    return u8lg_pos;
}

/**
 * @brief 通过 CAN ID 获取对应的 handleIndex
 * @param u32MsgID 要查询的 CAN 报文 ID
 * @param pu8handleIndex 输出参数，返回对应的 handleIndex
 * @return uint8_t 返回 0 表示成功，返回 1 表示未找到匹配
 */
static uint8_t BSPGetChPosByID (tBSPCanRxCBK* ptBSPCanRxCBK,uint8_t *pu8handleIndex)
{
    uint8_t u8Ret = 1u;

    Can_IdType CanId;
    if(ptBSPCanRxCBK->u8IsEntended == 0) 
    {
        ptBSPCanRxCBK->u32MsgID = (ptBSPCanRxCBK->u32MsgID>>18);
    }
    // 遍历 MsgBufHdlMap 数组，匹配 u32MsgID
    for (uint16_t i = 0u; i < 60; i++)
    {
        if (MsgBufHdlMap[i].u32MsgID == ptBSPCanRxCBK->u32MsgID)
        {
            *pu8handleIndex = MsgBufHdlMap[i].u8handleIndex;
            u8Ret = 0u;  // 成功找到
            break;
        }
    }
    return u8Ret;
}

static void BSPCanDefineMsgRx (uint8_t u8MCUCANCh)
{
    uint8_t u8max_mb = 0U;
    uint8_t u8mb_pos;
    uint8_t u8cfg_pos;
    uint32_t u32msg_id;

    mBSPCanErrCANChPro(u8MCUCANCh);
    u8max_mb = mBSPCanChGetMaxMB(u8MCUCANCh);

    /* 鐢ㄤ簬璁剧疆杩囨护鎺ユ敹 */
    for (u8mb_pos = 0u; u8mb_pos <= (u8max_mb - 1u); u8mb_pos++) /* 鏈�鍚庝竴涓偖绠辩敤浜庡彂閫� */
    {
		u8cfg_pos = BSPGetChPos(u8MCUCANCh, u8mb_pos);
		if (0xFFFFFFFFu != MsgFilterBufHdlMap[u8cfg_pos].u32MsgID)
		{
			BSPCanSetRxMb(u8MCUCANCh, u8mb_pos, MsgFilterBufHdlMap[u8cfg_pos].u32MsgID, MsgFilterBufHdlMap[u8cfg_pos].u32IdMask);
		}
		else
		{
			break;
		}
	}

    /* 鐢ㄤ簬璁剧疆绮剧‘鎺ユ敹 */
    // for (; u8mb_pos <= (u8max_mb - 1u); u8mb_pos++)
    // {
    //     u8cfg_pos = BSPGetChPos(u8MCUCANCh, u8mb_pos);
    //     if (0xFFFFFFFFu != MsgBufHdlMap[u8cfg_pos].u32MsgID)
    //     {
    //         u32msg_id = MsgBufHdlMap[u8cfg_pos].u32MsgID;
    //         //if (u32msg_id == 0x18FF2117u) /*璁剧疆澶氭ā鍧楁帴鏀禝D*/
    //         //{
    //         //    u32msg_id = 0x18FF0017u | (cu8ModuleSrcId[ThisModuleId] << 8u);
    //         //}
    //         //else if (u32msg_id == 0x1CEC2117u)
    //         //{
    //         //    u32msg_id = 0x1CEC0017u | (cu8ModuleSrcId[ThisModuleId] << 8u);
    //         //}
    //         //else if (u32msg_id == 0x1CEB2117u)
    //         //{
    //         //    u32msg_id = 0x1CEB0017u | (cu8ModuleSrcId[ThisModuleId] << 8u);
    //         //}
    //         //else if (u32msg_id == 0x18DAECF9u)
    //         //{
    //         //    u32msg_id = 0x18DA00F9u | (cu8ModuleSrcId[ThisModuleId] << 8u);
    //         //}

    //         BSPCanSetRxMb(u8MCUCANCh, u8mb_pos, u32msg_id, 0xFFFFFFFF);
    //     }
    //     else
    //     {
    //         break;
    //     }
    // }
}

static void BSPCanControlTransceiver (uint8_t u8MCUCANCh, uint8_t u8Level)
{
    mBSPCanErrCANChPro(u8MCUCANCh);

    extern void BSPOutputCtr (gpio_output_index Index, out_put_ctr_cmd Cmd);

    switch (u8MCUCANCh)
    {
#ifdef cMCUCANCh0
        case cMCUCANCh0:
            //Set STB0
            //mBSPCOMWritePin(cCfg_UsedAsCAN0STB_Output_Port, cCfg_UsedAsCAN0STB_Output_Offset,u8Level);
            //BSPOutputCtr(OUT_CAN_STB, u8Level);
            break;
#endif

#ifdef cMCUCANCh1
        case cMCUCANCh1:
            //Set STB0
            //mBSPCOMWritePin(cCfg_UsedAsCAN1STB_Output_Port, cCfg_UsedAsCAN0STB_Output_Offset,u8Level);
            break;
#endif

#ifdef cMCUCANCh2
        case cMCUCANCh2:
            //Set STB
            //mBSPCOMWritePin(cCfg_UsedAsCAN2STB_Output_Port, cCfg_UsedAsCAN2STB_Output_Offset,u8Level);
            break;
#endif
        default:
            ;
            break;
    }
}

/***************************************************************************************************
 澶栭儴璋冪敤鍑芥暟鍏ュ彛
 ***************************************************************************************************/
void BSPCanInit (uint8_t u8MCUCANCh)
{
    volatile CAN_Type * p;

    BspCanIdSelInit();
    mBSPCanErrCANChPro(u8MCUCANCh);

    p = mBSPCanChToReg(u8MCUCANCh);
    BSPCanCfgClk(u8MCUCANCh);
    BSPCanBeginInit(u8MCUCANCh);
    BSPCanResetReg(u8MCUCANCh);
    BSPCanCommonRegInit(u8MCUCANCh);
    BSPCanSetBaudrate(u8MCUCANCh);
    BSPCanINTInit(u8MCUCANCh);
    BSPCanDefineMsgRx(u8MCUCANCh);
    //BSPCanDefineMsgTx(u8MCUCANCh, CAN_TX_MB);
    BSPCanEndInit(u8MCUCANCh);

	p->MCR |= CAN_MCR_FRZ_MASK;            /* 鎵撳紑鍐荤粨妯″紡浣胯兘  */
	p->MCR |= CAN_MCR_MDIS_MASK;            /* 绂佹CAN妯″潡 */
	while(!(p->MCR & CAN_MCR_LPMACK_MASK)); /* 绛夊緟杩涘叆浣庡姛鑰楁ā寮�*/

    BSPCanControlTransceiver(u8MCUCANCh, cDisableTransceiver);		// 绂佹鍙戦�佹姤鏂�
}

void BSPCanCancelTransmission (uint8_t u8MCUCANCh)
{
    volatile CAN_Type * p;
    uint8_t can_mb_pos;
    uint32_t can_ram_bak;

    can_mb_pos = GET_MB_POS(CAN_TX_MB(u8MCUCANCh), MB_CTL_POS);
    mBSPCanErrCANChPro(u8MCUCANCh);
    p = mBSPCanChToReg(u8MCUCANCh);

    can_ram_bak = p->RAMn[can_mb_pos];
    can_ram_bak = (can_ram_bak & (~MB_CTL_CODE_MASK)) | (MB_CTL_CODE_ABORT << MB_CTL_CODE_POS);
    p->RAMn[can_mb_pos] = can_ram_bak;
}

void BSPCanControlINT (uint8_t u8MCUCANCh, uint8_t u8CtrlType, uint8_t u8INTSt)
{
    volatile CAN_Type * p;
    uint8_t u8loop;
    uint8_t max_mb;
    uint32_t int_mask_flag;

    mBSPCanErrCANChPro(u8MCUCANCh);
    p = mBSPCanChToReg(u8MCUCANCh);
    max_mb = mBSPCanChGetMaxMB(u8MCUCANCh);

    if ((u8INTSt == cINTStEnable) || (u8INTSt == cINTStDisabe))
    {
        switch (u8CtrlType)
        {
            case cINTCtrlType_RX:
                int_mask_flag = p->IMASK1;
                if (u8INTSt == cINTStEnable)
                {
                    for (u8loop = CAN_RX_MB_BG; u8loop < max_mb; u8loop++)
                    {
                        int_mask_flag |= (1u << u8loop);
                    }
                }
                else
                {
                    for (u8loop = CAN_RX_MB_BG; u8loop < max_mb; u8loop++)
                    {
                        int_mask_flag &= ~(1u << u8loop);
                    }
                }
                p->IMASK1 = int_mask_flag;
                break;

            case cINTCtrlType_TX:
                int_mask_flag = p->IMASK1;
                if (u8INTSt == cINTStEnable)
                {
                    int_mask_flag |= (1u << CAN_TX_MB(u8MCUCANCh));
                }
                else
                {
                    int_mask_flag &= ~(1u << CAN_TX_MB(u8MCUCANCh));
                }
                p->IMASK1 = int_mask_flag;
                break;

            case cINTCtrlType_Err:
                if (u8INTSt == cINTStEnable)
                {
                    p->CTRL1 |= CAN_CTRL1_BOFFMSK_MASK;
                }
                else
                {
                    p->CTRL1 &= ~CAN_CTRL1_BOFFMSK_MASK;
                }
                break;
            default:
                break;
        }
    }
}

void BSPCanStartCom (uint8_t u8MCUCANCh)
{
    volatile CAN_Type * p;

    mBSPCanErrCANChPro(u8MCUCANCh);
    p = mBSPCanChToReg(u8MCUCANCh);

    //p->CTRL1 |= CAN_CTRL1_BOFFREC_MASK;         /* 鍏抽棴BUSOFF鑷姩鎭㈠鏈哄埗 */
    //p->CTRL1 |= CAN_CTRL1_BOFFMSK_MASK;         /* 鎵撳紑BUSOFF涓柇 */
    if (u8MCUCANCh == 0u)
    {
        INT_SYS_EnableIRQ(CAN0_ORed_0_15_MB_IRQn);
        INT_SYS_EnableIRQ(CAN0_ORed_16_31_MB_IRQn);
        INT_SYS_EnableIRQ(CAN0_ORed_IRQn);
    }
    else if (u8MCUCANCh == 1u)
    {
        INT_SYS_EnableIRQ(CAN1_ORed_0_15_MB_IRQn);
        INT_SYS_EnableIRQ(CAN1_ORed_IRQn);
    }
    else if (u8MCUCANCh == 2u)
    {
        INT_SYS_EnableIRQ(CAN2_ORed_0_15_MB_IRQn);
        INT_SYS_EnableIRQ(CAN2_ORed_IRQn);
    }

    p->IMASK1 = 0xFFFFFFFFU; /* 鎵撳紑鎵�鏈夐偖绠变腑鏂� */

    p->MCR &= ~CAN_MCR_HALT_MASK;				/* 閫�鍑虹瓑寰呮ā寮� */
    p->MCR &= ~CAN_MCR_FRZ_MASK;                /* 閫�鍑篊AN鍐荤粨妯″紡  */
    while((p->MCR & CAN_MCR_FRZACK_MASK));		/* 绛夊緟閫�鍑哄喕缁撴ā寮�  */

    p->MCR &= ~CAN_MCR_MDIS_MASK;               /* 浣胯兘CAN妯″潡锛屾墦寮�閫氫俊 */
    while((p->MCR & CAN_MCR_LPMACK_MASK)); 		/* 绛夊緟閫�鍑轰綆鍔熻�楁ā寮� */

    BSPCanControlTransceiver(u8MCUCANCh, cEnableTransceiver);

    BSPCanPinAsDIN_DisableINT();
    BSPCanPinAsCANRx();
}

void BSPCanStopCom (uint8_t u8MCUCANCh)
{
    volatile CAN_Type * p;

    mBSPCanErrCANChPro(u8MCUCANCh);
    p = mBSPCanChToReg(u8MCUCANCh);

    //p->CTRL1 |= CAN_CTRL1_BOFFREC_MASK;         /* 鍏抽棴BUSOFF鑷姩鎭㈠鏈哄埗 */
    //p->CTRL1 &= ~CAN_CTRL1_BOFFMSK_MASK;        /* 鎵撳紑BUSOFF涓柇 */
    if (u8MCUCANCh == 0u)
    {
        INT_SYS_DisableIRQ(CAN0_ORed_0_15_MB_IRQn);
        INT_SYS_DisableIRQ(CAN0_ORed_16_31_MB_IRQn);
        INT_SYS_DisableIRQ(CAN0_ORed_IRQn);
    }
    else if (u8MCUCANCh == 1u)
    {
        INT_SYS_DisableIRQ(CAN1_ORed_0_15_MB_IRQn);
        INT_SYS_DisableIRQ(CAN1_ORed_IRQn);
    }
    else if (u8MCUCANCh == 2u)
    {
        INT_SYS_DisableIRQ(CAN2_ORed_0_15_MB_IRQn);
        INT_SYS_DisableIRQ(CAN2_ORed_IRQn);
    }

    p->IMASK1 = 0x0U; /* 鍏抽棴鎵�鏈夐偖绠变腑鏂� */

    BSPCanBeginInit(u8MCUCANCh);
	p->MCR |= CAN_MCR_HALT_MASK;            /* HALT鏍囧織浣� */
	p->MCR |= CAN_MCR_MDIS_MASK;			/* 绂佹CAN妯″潡 */
	while(!(p->MCR & CAN_MCR_LPMACK_MASK)); /*绛夊緟杩涘叆浣庡姛鑰楁ā寮�*/

#if 0
    BSPCanEndInit(u8MCUCANCh);

    t_clk = mBSPCanChGetClkSet(u8MCUCANCh);
    PCC->PCCn[t_clk] &= ~PCC_PCCn_CGC_MASK; /* 鍋滄鎺у埗鏃堕挓 */
#endif
    BSPCanControlTransceiver(u8MCUCANCh, cDisableTransceiver);

}

typedef union
{
    uint32_t u32_data;
    uint8_t u8_data[4];
} tU32SwitchTerminal;

static void BSPCanTerminalSwitch (tU32SwitchTerminal * source, tU32SwitchTerminal * dest)
{
    dest->u8_data[0] = source->u8_data[3];
    dest->u8_data[1] = source->u8_data[2];
    dest->u8_data[2] = source->u8_data[1];
    dest->u8_data[3] = source->u8_data[0];
}

void can_delay (uint32_t delay)
{
	while(delay --);
}

uint8_t BSPCanSendMsg (uint8_t u8MCUCANCh, tBSPCanSendMsg* ptSendMsg)
{
    volatile CAN_Type * p;
    uint32_t code;
    uint32_t u32msg_id;
    uint8_t err_count = 0u;

    //mBSPCanErrCANChPro(u8MCUCANCh);
    p = mBSPCanChToReg(u8MCUCANCh);

    code = (p->RAMn[GET_MB_POS(CAN_TX_MB(u8MCUCANCh), MB_CTL_POS)] >> MB_CTL_CODE_POS) & 0x0Fu;

    if ((code != MB_CTL_CODE_INACTIVE) && (code != 0u))
    {
        do
        {
            can_delay(100);
            code = (p->RAMn[GET_MB_POS(CAN_TX_MB(u8MCUCANCh), MB_CTL_POS)] >> MB_CTL_CODE_POS) & 0x0Fu;
            err_count++;
            if (err_count > 100U)
            {
                break;
            }
        }while ((code != MB_CTL_CODE_INACTIVE) && (code != 0u));
    }

    if ((code != MB_CTL_CODE_INACTIVE) && (code != 0u))
    {
        BSPCanCancelTransmission(u8MCUCANCh);
    }

    if(ptSendMsg->u32MsgID < 0x7FF)
    {
        u32msg_id = ptSendMsg->u32MsgID <<STANDARD_POS;
    }
    else
    {
        u32msg_id = ptSendMsg->u32MsgID;
    }

//    if (u32msg_id == 0x18FF1721u) /* 妯″潡id杞崲锛�18FF1721鍙戦�佹姤鏂囪浆鎹负瀵瑰簲妯″潡鐨刬d */
//    {
//        u32msg_id = 0x18FF1700u | (cu8ModuleSrcId[ThisModuleId]);
//    }
//    else if (u32msg_id == 0x18DAF921) /* 璇婃柇id杞崲锛�18DAF921杞崲涓哄搴旀ā鍧楃殑id */
//    {
//        u32msg_id = 0x18DAF900u | (cu8ModuleSrcId[ThisModuleId]);
//    }

    p->RAMn[GET_MB_POS(CAN_TX_MB(u8MCUCANCh), MB_ID_POS)] = u32msg_id;

    BSPCanTerminalSwitch((tU32SwitchTerminal *)&(ptSendMsg->u32Data0), (tU32SwitchTerminal *)&(p->RAMn[GET_MB_POS(CAN_TX_MB(u8MCUCANCh), MB_DAT1_POS)]));
    BSPCanTerminalSwitch((tU32SwitchTerminal *)&(ptSendMsg->u32Data1), (tU32SwitchTerminal *)&(p->RAMn[GET_MB_POS(CAN_TX_MB(u8MCUCANCh), MB_DAT2_POS)]));

    p->IMASK1 |= (1u << CAN_TX_MB(u8MCUCANCh)); /* 鎵撳紑鎺ユ敹涓柇鎺╃爜锛屽厑璁稿搴旈偖绠变腑鏂� */

    tTxMsg.u8TxSource = ptSendMsg->u8Source;

    p->RAMn[GET_MB_POS(CAN_TX_MB(u8MCUCANCh), MB_CTL_POS)] = (CODE_SEND_ACTIVE << MB_CTL_CODE_POS) + (ptSendMsg->u8IsExtended << MB_CTL_IDE_POS) + (ptSendMsg->u8Len << MB_CTL_DLC_POS);

    return 0;
}

/* 娉ㄦ剰姝ゅ闇�瑕佹矡閫氾紝杩斿洖鐘舵�佺殑鏍囧噯鏍煎紡 */
unsigned short BSPCanGetCANStatus (uint8_t u8MCUCANCh)
{
    volatile CAN_Type * p;

    mBSPCanErrCANChPro(u8MCUCANCh);
    p = mBSPCanChToReg(u8MCUCANCh);

    return (p->ESR1);
}

void BSPCanBusOffRecovery (uint8_t u8MCUCANCh)
{
    volatile CAN_Type * p;

    mBSPCanErrCANChPro(u8MCUCANCh);
    p = mBSPCanChToReg(u8MCUCANCh);

    p->CTRL1 &= ~CAN_CTRL1_BOFFREC_MASK; /* 鎵撳紑鑷姩鍥炴仮澶� */
    p->ESR1 |= CAN_ESR1_BOFFINT_MASK; /* 娓呴櫎BUSOFF涓柇鐨勬帺鐮� */
    p->CTRL1 |= CAN_CTRL1_BOFFMSK_MASK; /* 鎵撳紑busoff涓柇 */
}

#define mRouterMcuCanTxCBK(MCUCANCh)                                                \
static void Router_MCUCANCh##MCUCANCh##_TxCBK(tBSPCanTxCBK*  pTxCBK)                \
{                                                                                   \
	switch(tTxMsg.u8TxSource)                                                       \
	{                                                                               \
        case cTxSource_Geno:                                                        \
            CanIf_TxConfirmation(tTxMsg.u16TxedMsgIndex);                           \
            break;                                                                  \
        case cTxSource_LDB:                                                         \
            LDBCan_MCUCANCh##MCUCANCh##_TxCBK(pTxCBK);                              \
            break;                                                                  \
        default:                                                                    \
            mLIBassert(cFalse);                                                     \
            break;                                                                  \
	}                                                                               \
}                                                                                   \


#define mRouterMcuCanRxCBK(MCUCANCh)                                               \
static void Router_MCUCANCh##MCUCANCh##_RxCBK(tBSPCanRxCBK* ptBSPCanRxCBK)         \
{                                                                                  \
	Can_HwHandleType Hrh;                                                          \
	Can_IdType CanId;                                                              \
	unsigned char CanDlc;                                                          \
	uint8_t u8LgBufId;                                                             \
	uint8_t u8ArrForCanIf[8];                                                      \
    uint8_t u8max_mb;                                                       \
    uint8_t res;                                                            \
                                                                                   \
    mBSPCanErrCANChPro(ptBSPCanRxCBK->u8CANCh);                                    \
	u8max_mb = mBSPCanChGetMaxMB(ptBSPCanRxCBK->u8CANCh);                          \
                                                                                   \
    *((unsigned int *)&u8ArrForCanIf [0]) = ptBSPCanRxCBK->u32Data0;               \
    *((unsigned int *)&u8ArrForCanIf [4]) = ptBSPCanRxCBK->u32Data1;               \
                                                                                   \
    u8LgBufId = BSPGetChPos(ptBSPCanRxCBK->u8CANCh, ptBSPCanRxCBK->MsgBufId);      \
                                                                                   \
    if((ptBSPCanRxCBK->MsgBufId) <= ((uint8_t)u8max_mb))                           \
    {                                                                              \
           /* Hrh: 瀵瑰簲CanIfHrhFirstRxPduID 涓殑鍏冪礌浣嶇疆*/                           \
           /* CanIfHrhFirstRxPduID 涓厓绱犲搴擟anIfRxPduConfig 涓殑鍏冪礌浣嶇疆*/          \
                                                                                   \
                                                                                   \
        /* Hrh = MsgBufHdlMap[u8LgBufId].u8handleIndex; */                         \
        CanId = (ptBSPCanRxCBK->u32MsgID>>18);                                     \
        CanDlc = 0x08U;                                                            \
                                                                                   \
            /* 鏁版嵁娴佺▼CanIf */                                                  \
            if (MsgFilterBufHdlMap[u8LgBufId].u8Path == 1U)                         \
            {                                                                       \
                /* CanIf_RxIndication(Hrh, CanId, CanDlc, u8ArrForCanIf);*/              \
                CanIf_RxIndication(0, CanId, CanDlc, u8ArrForCanIf);              \
            }                                                                       \
            else if (MsgFilterBufHdlMap[u8LgBufId].u8Path == 0U)                    \
            {                                                                       \
                /* 鏁版嵁娴佸悜LDB */                                                \
                res=BSPGetChPosByID(ptBSPCanRxCBK,&Hrh); \
                ptBSPCanRxCBK->u8MsgHandle = Hrh;                            \
                if(res==0)                                                          \
                {                                                                   \
                    LDBCan_MCUCANCh##MCUCANCh##_RxCBK(ptBSPCanRxCBK);;              \
                }                                                                   \
            }                                                                      \
            else                                                                   \
            {                                                                      \
            }                                                                      \
                                                                                  \
    }                                                                              \
}                                                                                  \

#define mRouterMcuCanBusOffCBK(MCUCANCh)					                        \
static void Router_MCUCANCh##MCUCANCh##_BusOffCBK(tBSPCanErrCBK* pErrCBK)	        \
{										                                            \
	/* 浜х敓BusOff鍚庯紝涓嶅啀浼犻�佺粰J1939鍗忚鏍堬紝鍙湁LDB澶勭悊BusOff锛岃繖鏍峰仛姣旇緝绠�鍗� */	        \
	/* 鍚﹀垯涓や釜鍗忚鏍堟悈鍜屽湪涓�璧峰鐞嗭紝寰堥夯鐑� */						                    \
    LDBCan_MCUCANCh##MCUCANCh##_BusOffCBK(pErrCBK);				                    \
}										                                            \

/* 鍑芥暟浣撳疄鐜� */
#ifdef cMCUCANCh0
mRouterMcuCanBusOffCBK(0)
mRouterMcuCanRxCBK(0)
mRouterMcuCanTxCBK(0)
#endif

#ifdef cMCUCANCh1
mRouterMcuCanBusOffCBK(1)
mRouterMcuCanRxCBK(1)
mRouterMcuCanTxCBK(1)
#endif

#ifdef cMCUCANCh2
mRouterMcuCanBusOffCBK(2)
mRouterMcuCanRxCBK(2)
mRouterMcuCanTxCBK(2)
#endif

FUNC(Can_ReturnType, CAN_PUBLIC_CODE) Can_Write
(
    Can_HwHandleType Hth, /*杩欎釜鍙傛暟鐢ㄤ笉鍒帮紝鍥犱负搴曞眰涓嶉�傞厤*/
    P2CONST(Can_PduType, AUTOMATIC, CAN_APPL_DATA) PduInfo/**/
)
{
	//杩欓噷瑕佽皟鐢ㄥ彂閫佸嚱鏁帮紝鍐欏叆鍙戦�佺殑鏁版嵁鍙奍D
	//娉ㄦ剰鍙戦�佹椂瑕佹敞鎰忛�氶亾鍙�
	//uint8_t BSPCanSendMsg(uint8_t u8MCUCANCh, tBSPCanSendMsg* ptSendMsg);
	uint8_t u8CANCh = 0U;
	uint8_t u8Loop  = 0U;
	uint8_t u8MsgLng = 8U;
	uint8_t u8MsgBuffer[8] = {0,0,0,0,0,0,0,0};
	tBSPCanSendMsg  tSendMsgObj;
	uint32_t u32msg_id;

    u8CANCh = guArrTxMsgForCanIf[PduInfo->swPduHandle].u8CANCh;

    u8MsgLng = PduInfo->length;
    for(u8Loop=0U; u8Loop<u8MsgLng; u8Loop++)
    {
        u8MsgBuffer[u8Loop] = PduInfo->sdu[u8Loop];
    }

    tSendMsgObj.u8Len = u8MsgLng;

    u32msg_id = PduInfo->id;
    //if (u32msg_id == 0x1CEC1721u) /* 妯″潡id杞崲锛�18FF1721鍙戦�佹姤鏂囪浆鎹负瀵瑰簲妯″潡鐨刬d */
    //{
    //    u32msg_id = 0x1CEC1700u | (cu8ModuleSrcId[ThisModuleId]);
    //}
    tSendMsgObj.u32MsgID = u32msg_id;

    tSendMsgObj.u8IsExtended = 0; //always set 1 as extend message
    // tSendMsgObj.u8IsExtended = (u32msg_id > 0x7FFU) ? 1U : 0U;//涓嶭DBCanSendWithAddrStub涓殑鍒ゆ柇淇濇寔涓�鑷达紵锛�
    tSendMsgObj.u32Data0 = *((unsigned int*)(&(u8MsgBuffer[0])));
    tSendMsgObj.u32Data1 = *((unsigned int*)(&(u8MsgBuffer[4])));
    tSendMsgObj.u8Source = cTxSource_Geno;

    tTxMsg.u16TxedMsgIndex = PduInfo->swPduHandle;

    (void)BSPCanSendMsg(u8CANCh, (tBSPCanSendMsg*)&tSendMsgObj);

    return CAN_OK;
}

/***************************************************************************************************
 涓柇鐨勫墠鏈熷鐞�
 ***************************************************************************************************/
static void BSPCanRecMsgProcess (uint8_t u8MCUCANCh, TypCanMBEm mb, tBSPCanRxCBK * msg)
{
    volatile CAN_Type * p;
    uint32_t dummy;
    uint32_t u32msg_id;
    uint8_t u8DestId;

    mBSPCanErrCANChPro(u8MCUCANCh);
    p = mBSPCanChToReg(u8MCUCANCh);

    u32msg_id = p->RAMn[GET_MB_POS(mb, MB_ID_POS)];
    u8DestId = (U8) (u32msg_id >> 18u);//实际没用

    //if (u8DestId == cu8ModuleSrcId[su8ModuleID])
    //{
    //	u32msg_id &= 0x1FFF00FFU;
    //	if ((u32msg_id  == 0x18FF0017u)	/* 妯″潡id杞崲锛屾帴鏀舵姤鏂囪浆鎹负鐩殑鍦板潃涓�0x21鐨勬ā鍧楋紝涓婂眰鍙瘑鍒鍊� */
	//	 || (u32msg_id == 0x1CEC0017u)
	//	 || (u32msg_id == 0x1CEB0017u)
	//	 || (u32msg_id == 0x18DA00F9u))
	//	{
    //		u32msg_id |= 0xEC00UL;
	//	}
    //}

//    u32msg_id &= 0x18000000UL;

    msg->u32MsgID = u32msg_id;
    msg->MsgBufId = mb;
    msg->u8CANCh = u8MCUCANCh;
    msg->u8IsEntended = (p->RAMn[GET_MB_POS(mb, MB_CTL_POS)] >> MB_CTL_IDE_POS) & 0x01;

    BSPCanTerminalSwitch((tU32SwitchTerminal *)&(p->RAMn[GET_MB_POS(mb, MB_DAT1_POS)]), (tU32SwitchTerminal *)&(msg->u32Data0));
    BSPCanTerminalSwitch((tU32SwitchTerminal *)&(p->RAMn[GET_MB_POS(mb, MB_DAT2_POS)]), (tU32SwitchTerminal *)&(msg->u32Data1));
    //msg->u32Data0 = p->RAMn[GET_MB_POS(mb, MB_DAT1_POS)];           /* 鏈�鍚庨渶瑕佺‘璁ら『搴忔槸鍚︽纭� */
    //msg->u32Data1 = p->RAMn[GET_MB_POS(mb, MB_DAT2_POS)];

    dummy = p->TIMER; /* 姝ゅ鎵嬪唽鏈夊啓锛岃В閿侀偖绠遍渶瑕佽timer鎴栬�呭叾浠朚B锛氬惁鍒欐棤娉曟帴鏀舵柊鐨勬暟鎹紝Read TIMER to unlock message buffers */
}

static void BSPCanTxMsgProcess (uint8_t u8MCUCANCh, TypCanMBEm mb, tBSPCanTxCBK * msg)
{
    volatile CAN_Type * p;
    uint32_t dummy;

    mBSPCanErrCANChPro(u8MCUCANCh);
    p = mBSPCanChToReg(u8MCUCANCh);

    msg->u32MsgID = p->RAMn[GET_MB_POS(mb, MB_ID_POS)];
    msg->u8MCUCANCh = u8MCUCANCh;
    msg->u8IsEntended = (p->RAMn[GET_MB_POS(mb, MB_CTL_POS)] >> MB_CTL_IDE_POS) & 0x00;

    dummy = p->TIMER;
}

static void BSPCAN_RxTxIntProcess (uint8_t u8MCUCANCh)
{
    uint8_t u8Loop;
    volatile CAN_Type * p;
    tBSPCanRxCBK rx_msg;
    tBSPCanTxCBK tx_msg;

    mBSPCanErrCANChPro(u8MCUCANCh);
    p = mBSPCanChToReg(u8MCUCANCh);

    if (p->IFLAG1 & (1u << CAN_TX_MB(u8MCUCANCh)))
    {
        //p->CTRL1 |= CAN_CTRL1_BOFFREC_MASK;     /* 鍙戦�佹垚鍔熷叧闂嚜鍔ㄦ仮澶嶆満鍒� */
        BSPCanTxMsgProcess(u8MCUCANCh, CAN_TX_MB(u8MCUCANCh), &tx_msg);
#ifdef cMCUCANCh0
        if (u8MCUCANCh == 0u)
        {
            BSPCan_MCUCANCh0_CallBackObj.pfnTxCallback(&tx_msg);
        }
#endif
#ifdef cMCUCANCh1
        if (u8MCUCANCh == 1u)
        {
            BSPCan_MCUCANCh1_CallBackObj.pfnTxCallback(&tx_msg);
        }
#endif
#ifdef cMCUCANCh2
        if (u8MCUCANCh == 2u)
        {
            BSPCan_MCUCANCh2_CallBackObj.pfnTxCallback(&tx_msg);
        }
#endif
        p->IFLAG1 |= (1u << CAN_TX_MB(u8MCUCANCh));
    }
    else
    {
        for (u8Loop = CAN_RX_MB_BG; u8Loop < CAN0_MAX_MB; u8Loop++)
        {
            if (p->IFLAG1 & (1u << u8Loop))
            {
                break;
            }
        }

        BSPCanRecMsgProcess(u8MCUCANCh, u8Loop, &rx_msg);
#ifdef cMCUCANCh0
        if (u8MCUCANCh == 0u)
        {
            BSPCan_MCUCANCh0_CallBackObj.pfnRxCallback(&rx_msg);
        }
#endif
#ifdef cMCUCANCh1
        if (u8MCUCANCh == 1u)
        {
            BSPCan_MCUCANCh1_CallBackObj.pfnRxCallback(&rx_msg);
        }
#endif
#ifdef cMCUCANCh2
        if (u8MCUCANCh == 2u)
        {
            BSPCan_MCUCANCh2_CallBackObj.pfnRxCallback(&rx_msg);
        }
#endif
        p->IFLAG1 |= (1u << u8Loop);
    }
}

void BusoffRecoverClose (void)
{
    if ((*(U8 *) (0x4002401C)) > 128)		/* 鍙傜収鏁版嵁鎵嬪唽涓湴鍧� */
    {
        CAN0->CTRL1 |= CAN_CTRL1_BOFFREC_MASK; /* 鍏抽棴鑷姩鍥炴仮澶� */
    }
}
static void BSPCanErrProcess (uint8_t u8MCUCANCh)
{
    tBSPCanErrCBK tmptErrCBK;
    en_canfd_error_t eErrCode;
    volatile CAN_Type * p;

    mBSPCanErrCANChPro(u8MCUCANCh);
    p = mBSPCanChToReg(u8MCUCANCh);

    if (0u == (p->CTRL1 & CAN_CTRL1_BOFFREC_MASK))
    {
        //p->CTRL1 |= CAN_CTRL1_BOFFREC_MASK;     /* BUSOFF鎭㈠鎴愬姛鍏抽棴鑷姩鎭㈠鏈哄埗 */

        p->CTRL1 |= CAN_CTRL1_BOFFREC_MASK; /* 鍏抽棴鑷姩鍥炴仮澶� */
    }
    if (p->ESR1 & CAN_ESR1_BOFFINT_MASK)
    {
        eErrCode = CanFDBusOff;
        p->ESR1 |= CAN_ESR1_BOFFINT_MASK;
    }
    else if ((p->ESR1 & CAN_ESR1_RXWRN_MASK) || ((p->ESR1 & CAN_ESR1_TXWRN_MASK)))
    {
        eErrCode = CanFDWarning;
        p->ESR1 = (CAN_ESR1_RXWRN_MASK + CAN_ESR1_TXWRN_MASK);
    }
    p->CTRL1 &= ~CAN_CTRL1_BOFFMSK_MASK;
    tmptErrCBK.u8MCUCANCh = u8MCUCANCh;
    tmptErrCBK.u32MsgID = 0U; /*Not used now*/
    tmptErrCBK.u8IsEntended = 0U; /*Not used now*/
    tmptErrCBK.u8CANErrCode = (uint8_t) eErrCode;
#ifdef cMCUCANCh0
    if (u8MCUCANCh == 0u)
    {
        BSPCan_MCUCANCh0_CallBackObj.pfnErrCallback(&tmptErrCBK);
    }
#endif
#ifdef cMCUCANCh1
    if (u8MCUCANCh == 1u)
    {
        BSPCan_MCUCANCh1_CallBackObj.pfnErrCallback(&tmptErrCBK);
    }
#endif
#ifdef cMCUCANCh2
    if (u8MCUCANCh == 2u)
    {
        BSPCan_MCUCANCh2_CallBackObj.pfnErrCallback(&tmptErrCBK);
    }
#endif
}

/***************************************************************************************************
 绯荤粺鐨勪腑鏂叆鍙�
 ***************************************************************************************************/
#ifdef cMCUCANCh0
void CAN0_ORed_0_15_MB_IRQHandler (void)
{
    BSPCAN_RxTxIntProcess(CAN_CHN0);
}

void CAN0_ORed_16_31_MB_IRQHandler (void)
{
    BSPCAN_RxTxIntProcess(CAN_CHN0);
}

void CAN0_ORed_IRQHandler (void)
{
    BSPCanErrProcess(CAN_CHN0);
}

void CAN0_Error_IRQHandler (void)
{
}

void CAN0_Wake_Up_IRQHandler (void)
{
}
#endif

#ifdef cMCUCANCh1
void CAN1_ORed_0_15_MB_IRQHandler (void)
{
    BSPCAN_RxTxIntProcess(CAN_CHN1);
}

void CAN1_ORed_IRQHandler (void)
{
    BSPCanErrProcess(CAN_CHN1);
}

void CAN1_Error_IRQHandler ()
{
}
#endif

#ifdef cMCUCANCh2
void CAN2_ORed_0_15_MB_IRQHandler (void)
{
    BSPCAN_RxTxIntProcess(CAN_CHN2);
}

void CAN2_ORed_IRQHandler (void)
{
    BSPCanErrProcess(CAN_CHN2);
}

void CAN2_Error_IRQHandler ()
{
}
#endif
