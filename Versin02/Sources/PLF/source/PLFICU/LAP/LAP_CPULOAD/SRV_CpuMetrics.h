#ifndef SRV_CpuMetrics_H
#define SRV_CpuMetrics_H
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
// Component:    SRV_CpuMetrics
//               
// -----------------------------------------------------------------------------
// $Date:   Feb 12 2014 16:52:40  $
// $Archive:   //DI_JMC_N330_IC/archives/1016282/DEV/BUILD/SOURCES/SRV_CpuMetrics.h-arc  $
// $Revision:   1.1  $
// -----------------------------------------------------------------------------
/* $Log:   //DI_JMC_N330_IC/archives/1016282/DEV/BUILD/SOURCES/SRV_CpuMetrics.h-arc  $
 * 
 *    Rev 1.1   Feb 12 2014 16:52:40   azhao26
 * Cm065183:modify the generated comment error when implement the CPU load test
* 
*    Rev 1.0   Feb 12 2014 12:45:06   azhao26
* Initial revision.
*/

//******************************************************************************
#endif  // #ifndef _QAC_

#include ".\INCLUDE\basedef.h"

extern Std_ReturnType SRV_CpuMetrics_Init(void);
extern void SRV_CpuMetrics_Task(void);
extern Std_ReturnType SRV_CpuMetrics_LogTrace(const uint8 u8TaskIdP);

extern Std_ReturnType SRV_CpuMetrics_GetTracedRunablesList(uint8* pu8ListP, 
                                                           const uint8 u8SizeP);
extern Std_ReturnType SRV_CpuMetrics_GetRunableMetrics(const uint8 u8IdP, 
                                                       uint8* pu8BufferP, 
                                                       const uint8 u8SizeP);

//QACJ 0862: adimiten: Include of all headers is required by 
//                     SWA component template
#endif // #ifndef APP_Cmp_H
