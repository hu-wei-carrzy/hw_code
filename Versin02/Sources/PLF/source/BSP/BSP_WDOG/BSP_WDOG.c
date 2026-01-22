/*
 * BSP_WDOG.c
 *
 *  Created on: 2018年11月21日
 *      Author: chengwga
 */
#include"BSP_WDOG.h"



/*static const wdog_user_config_t watchdog_Config = {
      .clkSource = WDOG_LPO_CLOCK,//计时驱动的时钟选择
      .opMode = {
          false,  Wait Mode
          false,  Stop Mode
          false  Debug Mode
      },
      .updateEnable = false,
      .intEnable = false,
      .winEnable = false,
      .windowValue = 0,
      .timeoutValue = 64000,
	  //超时时间，超时后8ms内触发单片机复位
	  //LPOCLKSEL是选择LPO时钟的频率的，有128K、32K、1K
	  //不同频率下，这个值配位0-65536时，对应的延时分别是1ms-65.5s/128,1ms-65.5s/32，和1ms-65.5s
	  //当前的选择是32K，最大延时是，2047.9ms，1000ms对应的数值是1000*32=32000
      .prescalerEnable = false
  };
*/


  /*FUNCTION**********************************************************************
   *
   * Function Name : WDOG_DRV_Init
   * Description   : initialize the WDOG driver
   *
   * Implements    : WDOG_DRV_Init_Activity
   *END**************************************************************************/
  void  BSPWdgInit(void)
  {
	 /* const wdog_user_config_t * wdogUserConfig = &watchdog_Config;

	  	 WDOG_Type * const base=WDOG;
	  	 uint32_t cs = base->CS;

		  if ((WDOG_IsUpdateEnabled(base)) && (wdogUserConfig->timeoutValue > FEATURE_WDOG_MINIMUM_TIMEOUT_VALUE))
		  {
		         Clear the bits used for configuration
		        cs &= ~(WDOG_CS_WIN_MASK | WDOG_CS_PRES_MASK | WDOG_CS_CLK_MASK | WDOG_CS_INT_MASK |
		                WDOG_CS_UPDATE_MASK | WDOG_CS_DBG_MASK | WDOG_CS_WAIT_MASK | WDOG_CS_STOP_MASK);
		         Construct CS register new value
		        cs |= WDOG_CS_WIN(wdogUserConfig->winEnable ? 1UL : 0UL);
		        cs |= WDOG_CS_PRES(wdogUserConfig->prescalerEnable ? 1UL : 0UL);
		        cs |= WDOG_CS_CLK(wdogUserConfig->clkSource);
		        cs |= WDOG_CS_INT(wdogUserConfig->intEnable ? 1UL : 0UL);
		        cs |= WDOG_CS_UPDATE(wdogUserConfig->updateEnable ? 1UL : 0UL);
		        if (wdogUserConfig->opMode.debug)
		        {
		            cs |= WDOG_CS_DBG_MASK;
		        }
		        if (wdogUserConfig->opMode.wait)
		        {
		            cs |= WDOG_CS_WAIT_MASK;
		        }
		        if (wdogUserConfig->opMode.stop)
		        {
		            cs |= WDOG_CS_STOP_MASK;
		        }
		         Reset interrupt flags
		        cs |= WDOG_CS_FLG_MASK;
		         Enable WDOG in 32-bit mode
		        cs |= WDOG_CS_EN_MASK | WDOG_CS_CMD32EN_MASK;

		        WDOG_UNLOCK(base);

		        while (!WDOG_IsUnlocked(base))
		        {
		           Wait until registers are unlocked
		        }
		        base->CS = cs;
		        base->TOVAL = wdogUserConfig->timeoutValue;
		        if (wdogUserConfig->winEnable)
		        {
		            base->WIN = wdogUserConfig->windowValue;
		        }
		        while (WDOG_IsUnlocked(base))
		        {
		           Wait until the unlock window closes
		        }
		  }
*/
  }

  /*FUNCTION**********************************************************************
   *
   * Function Name : WDOG_DRV_Trigger
   * Description   : Refreshes the WDOG counter
   *
   * Implements    : WDOG_DRV_Trigger_Activity
   *END**************************************************************************/
   void BSPWdgRefresh(void)
  {
     //WDOG_Trigger(WDOG);
  }

   /*FUNCTION**********************************************************************
    *
 * Function Name : WDOG_GetCounter
 * Description   : Get the value of the WDOG counter.
 *
 * Implements    : WDOG_GetCounter_Activity
    *END**************************************************************************/
/*   uint16_t WDOG_GetCounter(void)
   {
        const WDOG_Type  * base = WDOG;

        return (uint16_t)base->CNT;
   }*/

   /*FUNCTION**********************************************************************
    *
    * Function Name : WDOG_DRV_Deinit
    * Description   : De-initialize the WDOG driver
    *
    * Implements    : WDOG_DRV_Deinit_Activity
    *END**************************************************************************/
   void  BSPWdgDeinit(void)
   {
/*
	   //WDOG_Type * const base=WDOG;

	    INT_SYS_DisableIRQGlobal();
	     Disable WDOG
	    WDOG_Disable(WDOG);

	    INT_SYS_EnableIRQGlobal();

	     Disable WDOG timeout interrupt
	    INT_SYS_DisableIRQ(WDOG_EWM_IRQn);

//	   WDOG_Disable();
*/

   }


