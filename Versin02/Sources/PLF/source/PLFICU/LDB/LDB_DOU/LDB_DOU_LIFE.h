//----  Mono-inclusion Definition-----
#ifndef I_LDB_DOU_LIFE_H_
#define I_LDB_DOU_LIFE_H_ 

/*-------------------------------------------------------------------------
  Included files to resolve specific definitions in this file

  #include <system_file_name.h>
  #include "project_file_name.h"
  -------------------------------------------------------------------------*/
#include "ARCH_CFG.h"

#ifdef cHeadIncludeType_Directly
#include "ldb.h"
#else
#include ".\..\LDB\LDB_API\ldb.h"
#endif
/*-------------------------------------------------------------------------
  Constant data

  #define cCMPConstantName   ((tType) ConstantValue)
  -------------------------------------------------------------------------*/
// --------------------------------------------------------------
//     Channel Dou
// --------------------------------------------------------------
#define cLDBDouEnterNominalMode ((tCtrl)0x01U)
#define cLDBDouEnterSleepMode   ((tCtrl)0x02U)

#define cLDBDouPowerLock        ((tCtrl)0x05U)
#define cLDBDouPowerRelease     ((tCtrl)0x09U)


#define cLDBDouAdrMCU_OUT_IO_LED       			 	((tCtrl)0x01U)
#define cLDBDouAdrMCU_OUT_A3G4250D_MCU_CS        	((tCtrl)0x02U)
#define cLDBDouAdrMCU_OUT_A3G4250D_OE        	 	((tCtrl)0x03U)
#define cLDBDouAdrMCU_OUT_MCU_FLASH_SPI_WP       	((tCtrl)0x04U)
#define cLDBDouAdrMCU_OUT_DRV_MOTOR_nSLEEP       	((tCtrl)0x05U)
#define cLDBDouAdrMCU_OUT_5V_SENSOR_EN        	 	((tCtrl)0x06U)
#define cLDBDouAdrMCU_OUT_HDO_DSEN12       			((tCtrl)0x07U)
#define cLDBDouAdrMCU_OUT_CTL3408_IN_F2       		((tCtrl)0x08U)
#define cLDBDouAdrMCU_OUT_CTL3408_IN_F1        		((tCtrl)0x09U)
#define cLDBDouAdrMCU_OUT_HDO_DSEN34        		((tCtrl)0x0AU)
#define cLDBDouAdrMCU_OUT_HDO_IN4        			((tCtrl)0x0BU)
#define cLDBDouAdrMCU_OUT_HDO_IN3        			((tCtrl)0x0CU)
#define cLDBDouAdrMCU_OUT_HDO_IN2        			((tCtrl)0x0EU)
#define cLDBDouAdrMCU_OUT_HDO_IN1        			((tCtrl)0x10U)
#define cLDBDouAdrMCU_OUT_I2C_WC        			((tCtrl)0x11U)
#define cLDBDouAdrMCU_OUT_MCU_FLASH_SPI_OE       	((tCtrl)0x12U)




#endif
