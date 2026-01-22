
#ifndef  I_LDB_TIM_LIFE_H_
#define  I_LDB_TIM_LIFE_H_

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
//     Channel CVT
// --------------------------------------------------------------

// -- DAT Controls --

//you can add your new control here,for example:
//#define cLDBDinEnableWakeUpInterrupt    ((tCtrl)0x03U)

// -- LDB Controls --
//you can add your new control here,for example:
//#define cLDBDinWakeUp                   ((tCtrl)0x04U)
#define cLDBTimStartADC            ((tCtrl)0x01U)
#define cLDBTimStopADC             ((tCtrl)0x02U)

// --------------------------------------------------------------
//      Definition of Ent Callback channel (without address)
// --------------------------------------------------------------
//you can enable the following call back functions if necessary
//and if necessary, you can add new call back function .
//extern void    DATCVTCallBackRxWithoutAddr(tStatus);
//extern void    DATCVTCallBackEndCtrl      (tCtrl,tStatus);
//extern void    DATCVTCallBackCtrl         (tCtrl);
//extern void	 DATCVTCallBackRxWithAddr(tAddress sAddr, tStatus Status);

#endif
