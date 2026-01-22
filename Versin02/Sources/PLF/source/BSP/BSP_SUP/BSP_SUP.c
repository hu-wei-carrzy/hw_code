//******************************************************************************
// Copyright:    This software is JYD property.
//               Duplication or disclosure without JYD written authorization
//               is prohibited.
// -----------------------------------------------------------------------------
// Project:      BCM313
// Language:     C
// -----------------------------------------------------------------------------
// Component:  superior to control all the Pin init .
// -----------------------------------------------------------------------------
//******************************************************************************
// This line is used to separate code and file header.This is begin.
//*****************************BEGIN_NOMOVE*************************************

//*****************************END_NOMOVE***************************************
// This line is used to separate code and file header. This is last line.
//************************************************************************************
#include "BSP_SUP.h"

void BSPSUPPinCfg(void)
{

   BSPCanCfgPins();
   BSPSUPPinEnable();
}

void BSPSUPPinEnable(void)
{
}

void disable_clock_monitors(void)
{
    /* Disable Clock monitor for System Oscillator */
    SCG->SOSCCSR &= ~(SCG_SOSCCSR_SOSCCM_MASK);
    /* Disable Clock monitor for System PLL */
    SCG->SPLLCSR &= ~(SCG_SPLLCSR_SPLLCM_MASK);
}

void scg_vlps_configuration (void)
{
    uint32_t tempSIRC = SCG->SIRCCSR;
    /* Disable in VLPS */
    tempSIRC &= ~(SCG_SIRCCSR_SIRCLPEN_MASK |
                SCG_SIRCCSR_SIRCSTEN_MASK);
#if SCG_ENABLE_SIRC_IN_VLPS
    /* Enable in VLPS */
    tempSIRC |= SCG_SIRCCSR_SIRCLPEN_MASK |
                SCG_SIRCCSR_SIRCSTEN_MASK;
#endif
    SCG->SIRCCSR = tempSIRC;
}

volatile U8 gu8WakeUp = 0u;
void BSPSupEnterSleep(void)
{
	gu8WakeUp = 0u;
	__asm volatile ("cpsie i" : : : "memory");

	disable_clock_monitors();

	scg_vlps_configuration();

	SMC->PMPROT |= 0x20ul;              		   /* 使能低功耗模式 VLPR and VLPS are allowed */

	PMC->REGSC |= PMC_REGSC_BIASEN_MASK
#if (0 == SCG_ENABLE_SIRC_IN_VLPS)
	            | PMC_REGSC_CLKBIASDIS_MASK
#endif
	;

	SMC->PMCTRL &= ~(SMC_PMCTRL_STOPM_MASK);       /* 第一步设置清空休眠模式控制数据  */
    SMC->PMCTRL |= SMC_PMCTRL_STOPM(2) + SMC_PMCTRL_RUNM(0);            /* 第二步设置VLPS模式  */
                                                   /* 上面两步仅用于设置，用于告诉MCU做好准备，并不能真正起作用，下面的设置才可以 */
    //SMC->STOPCTRL = SMC_STOPCTRL_STOPO(0U);
    S32_SCB->SCR |= S32_SCB_SCR_SLEEPDEEP_MASK;    /* 设置进入深度睡眠掩码，也是告诉MCU做好准备，并不会立即降低功耗 */

    while (0 == gu8WakeUp)
    {
    	__asm volatile ("wfe"); /* cortexM4内核执行WFI指令后，进入等待唤醒模式，上面的设置在此处起作用，如果不进行上面设置，也可以进入休眠，只是功耗会多很多。WFI为wait for interrupt，中断来了后，直接回到工作状态，直到再次执行WFI指令 */
    }
}

void BSPSupLeaveSleep(void)
{
	//将工作模式恢复过来
	//WakeUpCode
}
