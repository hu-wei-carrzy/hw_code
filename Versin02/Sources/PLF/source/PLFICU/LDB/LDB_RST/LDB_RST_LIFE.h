
#ifndef  I_LDB_BUZ_LIFE_H
#define  I_LDB_BUZ_LIFE_H

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
//     Channel BUZ
// --------------------------------------------------------------

// -- DAT Controls --
//#define cLDBBUZEnterNominalMode         ((tCtrl)0x01U)
//#define cLDBBUZEnterSleepMode           ((tCtrl)0x02U)
//#define cLDBBUZCheckBuzINTSt            ((tCtrl)0x03U)

// --------------------------------------------------------------
//      Definition of Ent Callback channel (without address)
// --------------------------------------------------------------
//you can enable the following call back functions if necessary
//and if necessary, you can add new call back function .
//extern void    DATBUZCallBackRxWithoutAddr(tStatus);
//extern void    DATBUZCallBackEndCtrl      (tCtrl,tStatus);
//extern void    DATBUZCallBackCtrl         (tCtrl);
//extern void	 DATBUZCallBackRxWithAddr(tAddress sAddr, tStatus Status);

#endif
