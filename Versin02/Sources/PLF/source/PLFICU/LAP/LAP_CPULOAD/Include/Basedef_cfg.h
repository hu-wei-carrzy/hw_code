#ifndef _QAC_
//******************************************************************************
// Company:      Johnson Controls Inc.
// -----------------------------------------------------------------------------
// Copyright:    This software is JCI property.
//               Duplication or disclosure without JCI written authorization
//               is prohibited.
// -----------------------------------------------------------------------------
// Project:      SZ1011
// Language:     ANSI-C
// -----------------------------------------------------------------------------
// Component:    
// -----------------------------------------------------------------------------
/* $Log:   //DI_JMC_N330_IC/archives/1016282/DEV/BUILD/SOURCES/Basedef_cfg.h-arc  $
 * 
 *    Rev 1.3   May 14 2014 10:35:34   awan1106
 * Cm068492: Step Motor Update from ER
 * 
 *    Rev 1.2   May 14 2014 09:38:54   awan1106
 * Cm068492: Step Motor Update from ER
 */
// 
//    Rev 1.1   Jun 26 2012 13:15:14   asarbip
// Tm120589:
// Stepper motors code must be clean and optimize.
// 
//    Rev 1.0   Jan 13 2010 14:19:58   asarbip
// Initial revision.
// 
//    Rev 1.0   Jul 31 2009 13:01:10   akaneva
// Initial revision.
//
//******************************************************************************
#endif

#ifndef I_LIB_BASEDEF_CFG_H
#define I_LIB_BASEDEF_CFG_H

#include "Platform_Types.h"

#define FAILED(hr)          (( E_FAIL == (Std_ReturnType)(hr)) || ( E_INVALIDARG == (Std_ReturnType)(hr) ))
//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//------------------------------------------------------------------------------
//#include "Std_Types.h"

//typedef uint8 Std_ReturnType;

typedef enum{E_OK, E_NOT_OK}Std_ReturnType;
typedef Std_ReturnType tHRESULT;

#define S_OK                ((Std_ReturnType) 0)
#define E_FAIL              ((Std_ReturnType) 1) // E_NOT_OK
#define S_FALSE             ((Std_ReturnType) 2)
#define S_WAIT              ((Std_ReturnType) 3)
#define E_INVALIDARG        ((Std_ReturnType) 4)

//------------------------------------------------------------------------------
// Constant data
//------------------------------------------------------------------------------
typedef uint8   eSystemEventType;

#define eSysEv_PowerFail                ((eSystemEventType) 0U)
#define eSysEv_PowerRecover             ((eSystemEventType) 1U)
//------------------------------------------------------------------------------
// Exported type
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Exported data
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Constant exported data
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Exported Macros
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Exported functions
//------------------------------------------------------------------------------

#endif   // I_LIB_BASEDEF_CFG_H


