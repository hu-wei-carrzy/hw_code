
#ifndef  I_LDB_EEP_LIFE_H_
#define  I_LDB_EEP_LIFE_H_

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


// --------------------------------------------------------------
//     Channel EEP
// --------------------------------------------------------------

// -- DAT Controls --

// LDB status codes for EEP
#define cLDBEepControlInProgress       (cLDBCorrect + 1U)

// -- Controls --
// Controls Value for EEPROM Locking\Unlocking

// EEPROM lock control value
#define cLDBEepLock   ((tCtrl)0x00U)
// EEPROM unlock control value
#define cLDBEepUnLock ((tCtrl)0x01U)
// EEPROM check the completion of the write command
#define cLDBEepCheckWriteCompletion ((tCtrl)0x02U)

// EEPROM Size
#define cLDBEepSize       0x0800U
//you can add your new control here,for example:
//#define cLDBDinEnableWakeUpInterrupt    ((tCtrl)0x03U)

// -- LDB Controls --
//you can add your new control here,for example:
//#define cLDBDinWakeUp                   ((tCtrl)0x04U)

// --------------------------------------------------------------
//      Definition of Ent Callback channel (without address)
// --------------------------------------------------------------
//you can enable the following call back functions if necessary
//and if necessary, you can add new call back function .
//extern void    DATEEPCallBackRxWithoutAddr(tStatus);
//extern void    DATEEPCallBackEndCtrl      (tCtrl,tStatus);
//extern void    DATEEPCallBackCtrl         (tCtrl);
//extern void	 DATEEPCallBackRxWithAddr(tAddress sAddr, tStatus Status);

#endif
