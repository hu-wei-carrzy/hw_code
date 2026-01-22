#ifndef SRV_CpuMetrics_CFG_H
#define SRV_CpuMetrics_CFG_H
//#include "DEFTYPES.h"


#ifndef _QAC_
//******************************************************************************
// Company:      Johnson Controls Inc.
// -----------------------------------------------------------------------------
// Copyright:    This software is JCI property.
//               Duplication or disclosure without JCI written authorization
//               is prohibited.
// -----------------------------------------------------------------------------
// Project:      Entry Platform
// Language:     ANSI-C
// -----------------------------------------------------------------------------
// Component:    SRV_CpuMetrics - Parameterization (public part)
//               
// -----------------------------------------------------------------------------
// $Date:   Dec 03 2014 11:14:52  $
// $Archive:   //DI_JMC_N330_IC/archives/1016282/DEV/BUILD/SOURCES/SRV_CpuMetrics_Cfg.h-arc  $
// $Revision:   1.7  $
// -----------------------------------------------------------------------------
/* $Log:   //DI_JMC_N330_IC/archives/1016282/DEV/BUILD/SOURCES/SRV_CpuMetrics_Cfg.h-arc  $
 * 
 *    Rev 1.7   Dec 03 2014 11:14:52   awan1106
 * Cm075356: for 3.00 cpu_trace
 * 
 *    Rev 1.6   Nov 18 2014 14:28:22   awan1106
 * Cm075356: for CpuTrace
 * 
 *    Rev 1.5   Aug 14 2014 11:42:12   awan1106
 * Cm065183: give it a large buffer
 * 
 *    Rev 1.4   Aug 13 2014 16:33:54   awan1106
 * Cm065183: do RESET_ON_ERROR, give it a large RAM
 * 
 *    Rev 1.3   Jul 28 2014 08:51:14   awan1106
 * SW: reduce the trace buffer
 * 
 *    Rev 1.2   Jun 04 2014 11:19:38   azhao26
 * Cm065183:add comment for selecting the right buffer size based on limited RAM space.
 * 
 *    Rev 1.1   Feb 12 2014 16:52:38   azhao26
 * Cm065183:modify the generated comment error when implement the CPU load test
* 
*    Rev 1.0   Feb 12 2014 12:45:08   azhao26
* Initial revision.
*/

//******************************************************************************
#endif  // #ifndef _QAC_

// Determine of uC timer is decrementing or incrementing. Uncomment the line
// if uC timer is incrementing. Otherwise, it is assumed that uC timer is 
// decrementing
//#define INCREMENTING_uC_TIMER

// Determine if reset shall be forced if an error is detected while analyzing the
// trace. This option works only for target compilation
#define RESET_ON_ERROR

#define cTimestampBase              16

#if cuCTimerBase > 16
#error "Only up to 16bit uC timer is supported currently!"
#endif

#define cu32TimerRange              (uint32)((uint32)1 << cTimestampBase)
#define cTimerMask                  (cu32TimerRange - (uint32)1)

#include "SRV_CpuTaskAndIntNum.h"
//#define cTOSMaxTaskNumber           22UL      //this copy from JIL.h
#define cu8EmptyTaskSlot            (uint8)0xFFU
#define cNumberTraceIds				(uint8)3
//#define cNumberUsedInterrupts		(uint8)7  //here you should change the value according to the
#define cNumberResrved              (uint8)2
//real project 
//the interrupt:
/* MC_TIMER
EXTINT4
EXTINT6
CAN0
RLT0
RLT2
RTC0
SG0
LINR0
LINT0
MAIN_FLASH
*/

#define cu8TasksNumberInSystem      (uint8)(cTOSMaxTaskNumber + cNumberTraceIds + cNumberUsedInterrupts + cNumberResrved)
//NOTE:because SRV_CpuMetrics component really consume a large RAM space,
//so if your project has very limited RAM space, you can change cMaxTraceBuffer value.
//you can get the most precise value by try and error.
#define cMaxTraceBuffer             1024
#define cProcessingThreshold        0

#define cu8ExitHandle               255

//trace timestamp type...
typedef U16 tTimeStamp;

#ifdef PRIVATE
// TODO: Put all private symbol declarations here!
#endif // #ifdef PRIVATE


#endif // #ifndef APP_Cmp_CFG_H
