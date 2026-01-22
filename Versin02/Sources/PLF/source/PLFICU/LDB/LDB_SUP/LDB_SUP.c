

//------------------------------------------------------------------------------
// Body Identification
//------------------------------------------------------------------------------

#define ldb_sup   "ldb_sup"


//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//
// #include <system_file_name.h>
// #include "project_file_name.h"
//------------------------------------------------------------------------------

#include "ARCH_CFG.h"

#ifdef cHeadIncludeType_Directly
#include "TOS.h"
#include "LDB_SUP.h"
#include "LDB_SUP_CFG.h"
#else
#include ".\..\..\TOS\TOS.h"
#include "LDB_SUP.h"
#include "LDB_SUP_CFG.h"
#endif

//------------------------------------------------------------------------------
// Local constants
//
// #define cConstantName   ((tType) ConstantValue)
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Local macros
//
// #define mMacroName   (MacroDefinition)
//------------------------------------------------------------------------------

#define	mMCUStroll()   __asm ("nop");__asm ("nop");__asm ("nop");__asm ("nop");\
	                   __asm ("nop");__asm ("nop");__asm ("nop");__asm ("nop");
//------------------------------------------------------------------------------
// Local types
//
// typedef Expression    tTypeName;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Data prefix
//
// unsigned int {u8,u16,u32} / signed int {s8,s16,s32} 
// register size unsigned int {r} / float {f32,f64}  / s for struct 
//
// -----------------------------------------------------------------------------
// Local data
//
// static  tType   u8VariableName;  
// static  tType*  pu8VariableName; 
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Constant local data
//
// static const tType  VariableName;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Exported data
//
// tType   u8LAYCmpVariableName; (LAY: 3 characters to identify the layer)
// tType*  pu8LAYCmpVariableName;(Cmp: 3 characters to identify the component)
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Constant exported data
//
//             (LAY: 3 characters to identify the layer)
//             (Cmp: 3 characters to identify this component)
// 
// const tType   LAYCmpVariableName;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Local function prototypes
// 
// static tTypeRetour FunctionName(tTypeArgument1 ArgumentName1, ... );
//------------------------------------------------------------------------------
static void ClearHWWatchdog(void)
{
	// Clear hardware watchdog
	IRQ_DISABLE_LOCAL();

	IRQ_RESTORE();
}
//==============================================================================
//=========================== LOCAL FUNCTIONS ==================================
//==============================================================================



//==============================================================================
//=========================== EXPORTED FUNCTIONS ===============================
//==============================================================================

//==============================================================================
// DESCRIPTION : prepare action before LDB SUP initialization
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void LDBSupPreInit(void)
{

}

//==============================================================================
// DESCRIPTION : LDB SUP initialization
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void LDBSupInit(void)
{   

    //Unlock Watchdog sequence
    //mLDBRegWrite16BitRegister(*((volatile U16 *)&WDTC_), (U16)0x6980);
    //mLDBRegWrite16BitRegister(*((volatile U16 *)&WDTC_), (U16)0x9680);

    //Watchdog unlocked
    //Configure Watchdog
#ifndef cLIBMCUWDT_Unused
    //WDTC_ = cLDBSupWDTCConfigValue;
    //WDTEC = cLDBSupWDTECConfigValue;
#else
	//  WDTC_ = cLDBSupWDTCDisableValue;
#endif

    //Activate configuration - write in WDTCP pattern
  //  WDTCP_ = 0x00;
    //Watchdog active configuration locked until next Reset -> 
    // - it is not possible to change it
    BSPSUPPinCfg();
    BSPWdgInit();
}

//==============================================================================
// DESCRIPTION : end action after LDB SUP initialization
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void LDBSupEndInit(void)
{

}

//==============================================================================
// DESCRIPTION : sleep mode entering routine
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void LDBSupEnterSleepMode(void)
{
	BOOL bIsWake = cFalse;

	__DI();
	//发送信号，其实就是控制着其它模块
	//的动作。目前只有DAT_ANA和DAT_BAt响应，另外，DAT_COM也要响应，
	//其通信也要停止
    TOSSendControl(cTOSControlMCUWillEnterSleepState);
    //停止定时器
    BSPTimSysTickStop();

    //调用WFI指令，进入休眠
    BSPSupEnterSleep();
    mMCUStroll();
    mMCUStroll();
    mMCUStroll();
    //......
    //......sleeping
    //......

    while(1)
    {
    	//先禁止中断,防止中断多次发生，造成无效的响应。
    	//因为GPIO的中断唤醒，中断引脚可能波形振荡，造成
    	//中断的多次响应
    	//__DI();
    	//这里判断是否有中断设置了信号值
    	bIsWake = TOSReadSignal(cTOSSignalMCUWakeUpRequested);
    	if(!bIsWake)
    	{
    		//这里只是预留，实际不会走这里
    		//这里是假唤醒
    	    mMCUStroll();
    	    mMCUStroll();
    	    mMCUStroll();
    	    //继续休眠
    	    //sleep.....
    	    //sleep.....


    	    //从这里醒来，
    	    //__EI();
    		//有中断到来，退出循环
    		break;
    	}
    	else
    	{
    		//唤醒时，从这里醒来
    		__EI();
    		break;
    	}
    }

    //刷新看门狗
    BSPWdgRefresh();
    //如果有中断唤醒，则会持续运行到这里来
    BSPSupLeaveSleep();
    //使能定时器，开始运行程序
    BSPTimSysTickStart();
    TOSSendControl(cTOSControlMCUWillLeaveSleepState);
}
//==============================================================================
// DESCRIPTION : sleep mode leaving routine
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void LDBSupLeaveSleepMode(void)
{
}

//==============================================================================
// DESCRIPTION : Wait for call back function
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : enter CPU into power saving mode
//==============================================================================
void LDBWaitForCallBack( void )
{
    //go to sleep mode
/*    SMCR = 0x01;
    while (SMCR != 0x00)
    {
        //wait for return from sleep mode
        //see note into 礐 datasheet page 279:
        //"To make sure instructions following the SMS write instruction are executed after wakeup from Sleep
        //mode (and not before transition to Sleep mode), poll the SMS bits after setting to "01". Branch to the next
        //instruction only when the SMS bits are cleared to "00". Reading "01" means that the transition to the
        //Sleep mode has not been performed yet (transition request is still pending)."
    }*/
}

//==============================================================================
// DESCRIPTION : reset function
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void LDBReset(void)
{
    BSPRstRriggerSWReset();
}
//==============================================================================
// DESCRIPTION : reset function
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void LDBSWReset(void)
{
	//SRSTG bit read only,so only write this bit single!!!
	//It is better that not update the byte.
//	RCR_SRSTG = 0x01;/* write 1 to SRSTG to generate sw reset*/
}
//==============================================================================
// DESCRIPTION : refresh the watchdog
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void LDBRefreshWatchDog(void)
{
	extern void BSPWdgRefresh(void);
	BSPWdgRefresh();
}
//==============================================================================
// DESCRIPTION : main function
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : Start TOS
//==============================================================================

void LDBSupStart(void)
{
	LDBSupInit();

	TOSStart(0);
}

