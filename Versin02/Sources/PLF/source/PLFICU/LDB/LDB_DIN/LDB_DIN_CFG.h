
#ifndef  I_LDB_DIN_CFG_H
#define  I_LDB_DIN_CFG_H

/*-------------------------------------------------------------------------
  Included files to resolve specific definitions in this file

  #include <system_file_name.h>
  #include "project_file_name.h"
  -------------------------------------------------------------------------*/

#include "ARCH_CFG.h"

#ifdef cHeadIncludeType_Directly
#include "ldb.h"
#include "BSP_DIO.h"
#else
#include ".\..\LDB\LDB_API\ldb.h"
#include ".\..\..\..\BSP\BSP_DIO\BSP_DIO.h"
#endif

// --------------------------------------------------------------
//     Channel Din
// --------------------------------------------------------------



/*-------------------------------------------------------------------------
  Constant data

  #define cCMPConstantName   ((tType) ConstantValue)
  -------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
  Exported Macros

  #define mCMPMacroName   (MacroDefinition)
  -------------------------------------------------------------------------*/ 

// If wake-up detection is managed with interrupts, you
// need to define the interrupts used in LDB_HARp.h
// for example :
// #define cLDBDinInterruptWakeUpDigitalInput0 xxx
// #define cLDBDinInterruptWakeUpDigitalInput1 xxx
// #define cLDBDinInterruptWakeUpDigitalInput2 xxx
// If wake-up detection is not manager with interrupts, you
// don't need to defines these constant

	//1-----------------------------------------------------
	//zjb add for can test
	//#define cLDBDinInterruptWakeUp_DI_Key1				EXTINT6
	//#define	cLDBDinInterruptWakeUp_DI_Key1_Edge			cLDBIntRisingEdge
	//-----------------------------------------------------

	//2-----------------------------------------------------
    //WakeUp ILLInput is only used in MT and now software is AT
	//#define cLDBDinInterruptWakeUp_ILLInput				EXTINT5
	//#define cLDBDinInterruptWakeUp_ILLInput_Edge		cLDBIntRisingEdge
	//-----------------------------------------------------

//Fill the sleep mode message
#define mLDBDinFillSleepModeMessage()   	\
    {                                       \
    }

// Fill the nominal mode message
// Caution : in nominal mode the two macro :
// (mLDBDinFillSleepModeMessage + mLDBDinFillNominalModeMessage )
// are called, the first bytes of the Msg are filled by mLDBDinFillSleepModeMessage()
#define mLDBDinFillNominalModeMessage()  	\
    {                                       \
    }

// Configure the ports direction, because BSP_SUP.c has configured it , so here do nothing
#define mLDBDinConfigureDIPorts()

//All keys, Pressed-->DIvalue=0,Released-->DIValue=1
//IN_DI_WakeUp_P_W		--上升沿有效激活信号  	Key1
//IN_DI_WakeUp_N_W		--下降沿有效激活信号		Key2
//IN_ID2_IN		--DI_ID2，		Key3
//IN_ID1_IN		--DI_ID1，		Key4
//IN_ID0_IN		--DI_ID0，		Key5


#define mSetDigitalInputDirect(Msg) \
{                                             \
	Msg[0U] = (((BSPGetInputState(IN_BLDC_DRV_PWRGD)) 		== 0x00U) ? (Msg[0U] & ~(0x01U)) : (Msg[0U] | 0x01U));/*IN_DIO1_Reserve*/                  \
	Msg[0U] = (((BSPGetInputState(IN_DIO2)) 				== 0x00U) ? (Msg[0U] | 0x02U)	 : (Msg[0U] & ~(0x02U)));/*IN_DIO2_Reserve*/                  \
	Msg[0U] = (((BSPGetInputState(IN_3408_FAULT))			== 0x00U) ? (Msg[0U] & ~(0x04U)) : (Msg[0U] | 0x04U));/*IN_FrontFanPosSignal1*/                  \
	Msg[0U] = (((BSPGetInputState(IN_DIO3)) 				== 0x00U) ? (Msg[0U] | 0x08U)	 : (Msg[0U] & ~(0x08U)));/*IN_FrontFanPosSignal2*/                  \
	Msg[0U] = (((BSPGetInputState(IN_DIO1)) 				== 0x00U) ? (Msg[0U] | 0x10U)	 : (Msg[0U] & ~(0x10U)));/*IN_AirPinchSigna*/                  \
	Msg[0U] = (((BSPGetInputState(IN_DIO6)) 				== 0x00U) ? (Msg[0U] | 0x20U)	 : (Msg[0U] & ~(0x20U)));/*IN_OutKeySignal*/				   \
	Msg[0U] = (((BSPGetInputState(IN_DIO8)) 				== 0x00U) ? (Msg[0U] & ~(0x40U)) : (Msg[0U] | 0x40U));/*IN_5kmhSignal*/                  \
	Msg[0U] = (((BSPGetInputState(IN_DIO5))					== 0x00U) ? (Msg[0U] | 0x80U)	 : (Msg[0U] & ~(0x80U)));/*IN_InKeyOpenSignal*/                  \
	Msg[1U] = (((BSPGetInputState(IN_DIO4))					== 0x00U) ? (Msg[1U] | 0x01U)	 : (Msg[1U] & ~(0x01U)));/*IN_InKeyCloseSignal*/				   \
	Msg[1U] = (((BSPGetInputState(IN_DIO7)) 				== 0x00U) ? (Msg[1U] & ~(0x02U)) : (Msg[1U] | 0x02U));/*IN_ONSignal*/					\
	Msg[1U] = (((BSPGetInputState(IN_DIO13)) 				== 0x00U) ? (Msg[1U] & ~(0x04U)) : (Msg[1U] | 0x04U));                     \
	Msg[1U] = (((BSPGetInputState(IN_DIO11)) 				== 0x00U) ? (Msg[1U] & ~(0x08U)) : (Msg[1U] | 0x08U));					\
	Msg[1U] = (((BSPGetInputState(IN_HALL5)) 				== 0x00U) ? (Msg[1U] & ~(0x10U)) : (Msg[1U] | 0x10U));	\
	Msg[1U] = (((BSPGetInputState(IN_HALL3)) 				== 0x00U) ? (Msg[1U] | 0x40U)	 : (Msg[1U] & ~(0x40U)));	\
  \
}

//
//for DIO4501_Bit0 from All 5 4501 chips
//Only AN0,AN1,AN2,AN4 is used
//DOIXY:X=0,1,2,4 , Y=1,2,3,4,5,6,7,8
#ifdef cLIBDIDirectBy4051
#define mSetDigitalInputFrom_DIO4051(Addr,Msg)
#endif



/*-------------------------------------------------------------------------
  Exported type

  struct  sCMPStructureName { ... };
  union   uCMPUnionName { ... };
  enum    eCMPEnumerationName { ... };
  typedef Expression tCMPTypeName;

  -------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
  Exported data

  extern  tType   CMPVariableName;
  extern  tType*  pCMPVariableName; 
  -------------------------------------------------------------------------*/ 

/*-------------------------------------------------------------------------
  Constant exported data

  extern const tType  CMPVariableName;
  -------------------------------------------------------------------------*/ 

/*-------------------------------------------------------------------------
  Exported functions

  extern tReturnType CMPFunctionName(tTypeArgument1 ArgumentName1, ... );
  -------------------------------------------------------------------------*/ 

#endif
