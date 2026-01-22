#include "BSP_TIM.h"
#include "BSP_TIM_CFG.h"
#include "core_cm4.h"

void BSPTimSysTickStart(void)
{
	//开启定时器中断，并启动定时器
	BSP_SysTick_Start();

#ifdef TRACE_CPU_ACTIVE
    extern void LAPCpuLoadTimerStart(void);
    LAPCpuLoadTimerStart();
#endif

}

void BSPTimADCStart(void)
{
}

void BSPTimSysTickStop(void)
{
	//禁止定时器中断，禁止定时器运行
	BSP_SysTick_Stop();
}

void BSPTimADCStop(void)
{
}

extern uint8_t CanIf_RxIndication_flag ;
extern uint8_t RxHrh;
extern uint32_t RxCanId;
extern uint8_t RxCanDlc;
extern const uint8_t *RxCanSduPtr;
extern uint8_t CanIf_TxConfirmationflag ;

/*
中断响应函数是在osif_baremetal.c中的SysTick_Handler中、
//                      这个函数是CM3/4内核通用的，且接口形式和位置是标准的，这里为了兼容，
//                      将此函数放在BSPTimSysTickunderflowCallback中调用。
 */
void BSPTimSysTickunderflowCallback(void)
{
	SysTickUnderflowCallback();

	//TODO  这里要注意一下，它表示了整个CanIf的接收方式， 这个做法可能有问题
    if (CanIf_RxIndication_flag == 1)
    {
    	CanIf_RxIndication_flag = 0;
    	CanIf_RxIndication(RxHrh, RxCanId, RxCanDlc, RxCanSduPtr);
    }

    if (CanIf_TxConfirmationflag == 1)
    {
    	CanIf_TxConfirmationflag = 0;
    	//CanIf_TxConfirmation(curu16TxedMsgIndex);
    }
}

void BSPTimInit(void)
{
	// SytTick使用CORE_CLK为时钟源，且不分频，则其运行时钟为80MHz，为了产生1.25ms的中断，则初始值
	// 要为100000，1.25ms = 100000/80M
#define cU32MainFreq   100000
	// 这里只是配置时钟源和设置溢出时间值和中断优先级，并没有使能中断和开启定时器
	BSP_SysTick_Config(cU32MainFreq);
}
