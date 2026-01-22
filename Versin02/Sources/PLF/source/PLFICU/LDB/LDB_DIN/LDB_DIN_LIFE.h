
#ifndef  I_LDB_DIN_LIFE_H
#define  I_LDB_DIN_LIFE_H

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
//     Channel Din
// --------------------------------------------------------------

// -- DAT Controls --
#define cLDBDinEnterNominalMode         ((tCtrl)0x01U)
#define cLDBDinEnterSleepMode           ((tCtrl)0x02U)
#define cLDBDinEnableWakeUpInterrupt    ((tCtrl)0x03U)

// -- LDB Controls --
#define cLDBDinWakeUp                   ((tCtrl)0x04U)


//--Addr define--

#define cLDBDIDirectInput_Addr              ((tAddress)0x08U)



#endif
