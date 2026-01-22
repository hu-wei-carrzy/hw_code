#ifndef I_LDB_COMMON_H
#define I_LDB_COMMON_H


//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//
// #include <system_file_name.h>
// #include "project_file_name.h"
//------------------------------------------------------------------------------
#include "ARCH_CFG.h"

#ifdef cHeadIncludeType_Directly
#include "HAL_CHANNELS.h"
#include "HAL.h"
#else

//used for LDB callback
#include ".\..\..\HAL\HAL_CHANNELS.h"
#include ".\..\..\HAL\HAL.h"
#endif

/*------------------------------------------------------------------------
  Constant data

  #define cCMPConstantName   ((tType) ConstantValue)
-------------------------------------------------------------------------*/


#define cLDBGPIOGroup_0              0
#define cLDBGPIOGroup_1              1
#define cLDBGPIOGroup_2              2
#define cLDBGPIOGroup_3              3
#define cLDBGPIOGroup_4              4

#define cLDBInput                    0
#define cLDBOutput                   1

#define cLDBDOHigh                   1
#define cLDBDOLow                    0

















#endif
