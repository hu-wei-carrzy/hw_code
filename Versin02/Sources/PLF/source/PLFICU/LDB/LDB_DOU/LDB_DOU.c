/*--------------------------------------------------------------------------
  Body Identification
  --------------------------------------------------------------------------*/

#define ldb_dou "ldb_dou"

/*-------------------------------------------------------------------------
  Included files

  #include <system_file_name.h>
  #include "project_file_name.h"
  --------------------------------------------------------------------------*/
#include "ARCH_CFG.h"


#include "LDB_DOU_CFG.h"
#include "LDB_DOU.h"


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


/*============================================================================
  =========================== LOCAL FUNCTIONS ================================
  ==========================================================================*/

/*============================================================================
  DESCRIPTION :
  
  PARAMETERS (Type,Name,Min,Max) :   none

  RETURN VALUE :   none
 
  DESIGN INFORMATION :   refer to Detailed Design Document
  ==========================================================================*/
//static type FunctionName(...)


/*============================================================================
  =========================== EXPORTED FUNCTIONS =============================
  ==========================================================================*/

/*============================================================================
  DESCRIPTION : 
  
  PARAMETERS (Type,Name,Min,Max) :  none

  RETURN VALUE :  none
 
  DESIGN INFORMATION :  refer to Detailed Design Document
============================================================================*/
void LDBDouInit(void)
{  

#ifdef cCfg_SerialoutputByHC59X
	mLDBDousInit();
#endif

#ifdef cCfg_Diroutput
	mLDBDouInit();
#endif

}
/*============================================================================
  DESCRIPTION : 
  
  PARAMETERS (Type,Name,Min,Max) :  none

  RETURN VALUE :  none
 
  DESIGN INFORMATION :  refer to Detailed Design Document
============================================================================*/
void LDBDouLeaveSleepMode(void)
{
#ifdef cCfg_SerialoutputByHC59X
   mLDBDousLeaveSleepMode();
#endif

#ifdef cCfg_Diroutput
   mBSPDIOCfgDOPortsForNominalMode();
#endif
}
/*============================================================================
  DESCRIPTION : 
  
  PARAMETERS (Type,Name,Min,Max) :  none

  RETURN VALUE :  none
 
  DESIGN INFORMATION :  refer to Detailed Design Document
============================================================================*/
void LDBDouEnterSleepMode(void)
{
#ifdef cCfg_SerialoutputByHC59X
	mLDBDousInit();
#endif
#ifdef cCfg_Diroutput
	mConfigureDOPortsForSleepMode();
#endif


}
/*============================================================================
  DESCRIPTION : 

  PARAMETERS (Type,Name,Min,Max) :  none
  
  RETURN VALUE :  none
    
  DESIGN INFORMATION :  refer to Detailed Design Document
============================================================================*/
void LDBDouControl(tCtrl Ctrl)
{
   switch(Ctrl)
   {
		case cLDBDouEnterNominalMode :
			mLDBDOULeaveSleepMode();
			break;

		case cLDBDouEnterSleepMode :
			mLDBDOUEnterSleepMode();
			break;

		case cLDBDouPowerLock:
		    break;
			
		case cLDBDouPowerRelease:
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
void LDBDouSendWithoutAddr(tMsg* pMsg)
{
    U8* Buffer;

    Buffer = pMsg->pBuffer;
    

#ifdef cCfg_UARTFor59X
    //include the direct digital output and serial digital output through HC59X
    mLDBDouSetDO(Buffer);
#endif
}


void LDBDouSendWithAddr(tAddress Addr, tMsg *pMsg )
{
	U8 u8Val = 0U;
	u8Val = pMsg->pBuffer[0];

    switch(Addr)
    {
    case cLDBDouAdrMCU_OUT_IO_LED:
    	BSPDioOUT_IO_LEDCtrl(u8Val);
    	break;

    case cLDBDouAdrMCU_OUT_A3G4250D_MCU_CS:
    	BSPDioOUT_A3G4250D_MCU_CSCtrl(u8Val);
    	break;

    case cLDBDouAdrMCU_OUT_A3G4250D_OE:
    	BSPDioOUT_A3G4250D_OECtrl(u8Val);
    	break;

    case cLDBDouAdrMCU_OUT_MCU_FLASH_SPI_WP:
    	BSPDioOUT_MCU_FLASH_SPI_WPCtrl(u8Val);
    	break;

    case cLDBDouAdrMCU_OUT_DRV_MOTOR_nSLEEP:
    	BSPDioOUT_DRV_MOTOR_nSLEEPCtrl(u8Val);
    	break;

    case cLDBDouAdrMCU_OUT_5V_SENSOR_EN:
    	BSPDioOUT_5V_SENSOR_ENCtrl(u8Val);
    	break;

    case cLDBDouAdrMCU_OUT_HDO_DSEN12:
    	BSPDioOUT_HDO_DSEN12Ctrl(u8Val);
    	break;

    case cLDBDouAdrMCU_OUT_CTL3408_IN_F2:
    	BSPDioOUT_CTL3408_IN_F2Ctrl(u8Val);
    	break;

    case cLDBDouAdrMCU_OUT_CTL3408_IN_F1:
    	BSPDioOUT_CTL3408_IN_F1Ctrl(u8Val);
    	break;

    case cLDBDouAdrMCU_OUT_HDO_DSEN34:
    	BSPDioOUT_HDO_DSEN34Ctrl(u8Val);
    	break;

    case cLDBDouAdrMCU_OUT_HDO_IN4:
    	BSPDioOUT_HDO_IN4Ctrl(u8Val);
    	break;

    case cLDBDouAdrMCU_OUT_HDO_IN3:
    	BSPDioOUT_HDO_IN3Ctrl(u8Val);
    	break;

    case cLDBDouAdrMCU_OUT_HDO_IN2:
    	BSPDioOUT_HDO_IN2Ctrl(u8Val);
    	break;

    case cLDBDouAdrMCU_OUT_HDO_IN1:
    	BSPDioOUT_HDO_IN1Ctrl(u8Val);
    	break;

    case cLDBDouAdrMCU_OUT_I2C_WC:
    	BSPDioOUT_I2C_WCCtrl(u8Val);
    	break;

    case cLDBDouAdrMCU_OUT_MCU_FLASH_SPI_OE:
    	BSPDioOUT_MCU_FLASH_SPI_OECtrl(u8Val);
    	break;


    default:
        mLIBassert(cFalse);
        break;

    }
}
