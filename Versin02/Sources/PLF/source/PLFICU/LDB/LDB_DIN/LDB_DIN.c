
/*--------------------------------------------------------------------------
Body Identification
--------------------------------------------------------------------------*/

#define ldb_din "ldb_din"

/*-------------------------------------------------------------------------
Included files

  #include <system_file_name.h>
  #include "project_file_name.h"
--------------------------------------------------------------------------*/

#include "LDB_DIN.h"
#include ".\..\..\TOS\TOS.h"

/*--------------------------------------------------------------------------
Local constants

  #define cConstantName   ((tType) ConstantValue)
--------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------
Local macros

  #define mMacroName   (MacroDefinition)
--------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------
Local types

  struct  sStructureName { ... };
  union   uUnionName { ... };
  enum    eEnumerationName { ... };
  typedef Expression tTypeName;
--------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------
Local data

  static  tType   VariableName;
  static  tType*  pVariableName; 
--------------------------------------------------------------------------*/

static BOOL SleepMode;

/*--------------------------------------------------------------------------
Constant local data

  static const tType  VariableName;
--------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------
Exported data

  tType   CMPVariableName;      (CMP: 3 characters to identify this component)
  tType*  pCMPVariableName;     (CMP: 3 characters to identify this component)
--------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------
Constant exported data

  const tType   CMPVariableName;(CMP: 3 characters to identify this component)
--------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------
Local function prototypes

  static tTypeRetour FunctionName(tTypeArgument1 ArgumentName1, ... );
--------------------------------------------------------------------------*/
static void DisableInterrupts(void);

/*============================================================================
=========================== LOCAL FUNCTIONS ================================
==========================================================================*/

/*============================================================================
  DESCRIPTION : DisableInterrupts

  PARAMETERS (Type,Name,Min,Max) :   none
  
  RETURN VALUE :   none
    
  DESIGN INFORMATION :   refer to Detailed Design Document
==========================================================================*/
static void DisableInterrupts(void)
{
	BSPDioDisableDIOInt();
}

/*============================================================================
  DESCRIPTION : NotifyWakeUp

  PARAMETERS (Type,Name,Min,Max) :   none
  
  RETURN VALUE :   none
    
  DESIGN INFORMATION :   refer to Detailed Design Document
==========================================================================*/

static void NotifyWakeUp(void)
{
    DisableInterrupts();
    //启动ReadLogicalTask,得到端口输入值，确认是否是真正唤醒
    mLDBDINCallBackControl(cLDBDinEnterNominalMode, cLDBDinWakeUp );
}

/*============================================================================
=========================== EXPORTED FUNCTIONS =============================
==========================================================================*/

/*============================================================================
  DESCRIPTION : 

  PARAMETERS (Type,Name,Min,Max) :  none
  
  RETURN VALUE :  none
    
  DESIGN INFORMATION :  refer to Detailed Design Document
============================================================================*/
void LDBDinInit(void)
{
    mLDBDinConfigureDIPorts();

    // If external interrupt are used. The dection is realized on 
    // the both edge. 
    // The detection don't wake-up the entire system but just retart
    // the deboucing alorithm.
    // Even if the wake-up is only required on rising edge we need to 
    // detect the falling edge. This detection allows to let the filter
    // reach the 0 value. Then, the wake request is send is sent by DAT_PIN
    // when the filtered value goes from 0 to 1.

    /*
    #ifdef cLDBDinInterruptWakeUpDigitalInput0
    mLDBIntConfigureIsr(cLDBDinInterruptWakeUpDigitalInput0, EachEdge);
    #endif

    #ifdef cLDBDinInterruptWakeUpDigitalInput1
    mLDBIntConfigureIsr(cLDBDinInterruptWakeUpDigitalInput1, EachEdge);
    #endif

    #ifdef cLDBDinInterruptWakeUpDigitalInput2
    mLDBIntConfigureIsr(cLDBDinInterruptWakeUpDigitalInput2, EachEdge);
    #endif
    */
extern void BSPGpioInit(void);
    BSPGpioInit();

    SleepMode = cTrue;
}

/*============================================================================
  DESCRIPTION : 

  PARAMETERS (Type,Name,Min,Max) :  none
  
  RETURN VALUE :  none
    
  DESIGN INFORMATION :  refer to Detailed Design Document
============================================================================*/
void LDBDinReceiveWithoutAddr(tMsg* pMsg)
{
    U8* pBuffer = pMsg->pBuffer;

    if (SleepMode == cFalse)
    {
        //Input used for wake up must be put at the beginging of the pBuffer
    	mSetDigitalInputDirect(pBuffer);
    }
    else
    {
        // When the control cLDBDinEnableWakeUpInterrupt is send
        // the interrupts are not cleared.
        // In sleep mode, the interrupt are clear before an input
        // readind.
        // This way allows :
        // - To ignore the edges detection that occur before the reading.
        //   Because in this case the DAT layer already knows the last value
        // - To signal the edges detects after the last reading if the DAT 
        //   required the notification mode.

       mSetDigitalInputDirect(pBuffer);
    }
}

/*============================================================================
  DESCRIPTION :

  PARAMETERS (Type,Name,Min,Max) :  none

  RETURN VALUE :  none

  DESIGN INFORMATION :  refer to Detailed Design Document
============================================================================*/
void LDBDinReceiveWithAddr(tAddress addr, tMsg* pMsg)
{
    U8* pBuffer = pMsg->pBuffer;

    if(SleepMode == cFalse)
    {
        //Input used for wake up must be put at the beginging of the pBuffer

        //Just for example
        //mLDBDinFillSleepModeMessage(pBuffer);
        //mLDBDinFillNominalModeMessage(pBuffer);
    	switch((U8)addr)
    	{
			case cLDBDIDirectInput_Addr:
				mSetDigitalInputDirect(pBuffer);
				break;
			default:
			    ;
			    break;
    	}
    }
    else
    {
        // When the control cLDBDinEnableWakeUpInterrupt is send
        // the interrupts are not cleared.
        // In sleep mode, the interrupt are clear before an input
        // readind.
        // This way allows :
        // - To ignore the edges detection that occur before the reading.
        //   Because in this case the DAT layer already knows the last value
        // - To signal the edges detects after the last reading if the DAT
        //   required the notification mode.

        switch((U8)addr)
		{
			case cLDBDIDirectInput_Addr:
				mSetDigitalInputDirect(pBuffer);
				break;
			default:
			    ;
			    break;
		}
    }
}

/*============================================================================
  DESCRIPTION : 

  PARAMETERS (Type,Name,Min,Max) :  none
  
  RETURN VALUE :  none
    
  DESIGN INFORMATION :  refer to Detailed Design Document
============================================================================*/
void LDBDinControl(tCtrl Ctrl)
{
    switch(Ctrl)
    {
        case cLDBDinEnterNominalMode :
            SleepMode = cFalse;
			mLDBDinFillNominalModeMessage();
			BSPDioDisableDIOInt();
			//BSPOutputCtr(OUT_VCC_SW_CTRL, TurnOFF);
            break;

       case cLDBDinEnterSleepMode :
            SleepMode = cTrue;
			mLDBDinFillSleepModeMessage();
			//BSPOutputCtr(OUT_VCC_SW_CTRL, TurnON);

            break;

       //当进入Sleep时，会使能中断功能
       case cLDBDinEnableWakeUpInterrupt :
		   SleepMode = cTrue;

		   //这里进入了休眠状态，这里要使能端口的中断功能，并读取信号值，
		   //读取信号值就是将信号清0
			(void)TOSReadSignal(cTOSSignalMCUWakeUpRequested);
			//使能中断
			BSPDioEnableDIOInt();
            break;

       default :
            mLIBassert(cFalse);
            break;
   }
}

/*============================================================================
  DESCRIPTION : 
  
  PARAMETERS (Type,Name,Min,Max) :  none

  RETURN VALUE :  none
 
  DESIGN INFORMATION :  refer to Detailed Design Document
============================================================================*/
void LDBDinLeaveSleepMode(void)
{
	LDBDinControl(cLDBDinEnterNominalMode);
}


/*============================================================================
  DESCRIPTION : 
  
  PARAMETERS (Type,Name,Min,Max) :  none

  RETURN VALUE :  none
 
  DESIGN INFORMATION :  refer to Detailed Design Document
============================================================================*/
void LDBDinEnterSleepMode(void)
{
	LDBDinControl(cLDBDinEnableWakeUpInterrupt);
}

/*============================================================================
  DESCRIPTION :

  PARAMETERS (Type,Name,Min,Max) :  none
  
  RETURN VALUE :  none
    
  DESIGN INFORMATION :  refer to Detailed Design Document
============================================================================*/
//唤醒中断响应函数都定义在LDB层，方便编程
void LDBDinDIWakeUpIsr(void)
{
	//确认下这里是否要清除中断标志位
	NotifyWakeUp();
	TOSWriteSignal(cTOSSignalMCUWakeUpRequested);
	TOSSendControl(cTOSControlWakeUpRequest);          //start CPU
}


