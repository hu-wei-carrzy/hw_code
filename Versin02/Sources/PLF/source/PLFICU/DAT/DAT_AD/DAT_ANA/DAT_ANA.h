//******************************************************************************
// Copyright:    This software is JYD property.
//               Duplication or disclosure without JYD written authorization
//               is prohibited.
// -----------------------------------------------------------------------------
// Project:      BCM313
// Language:     C
// -----------------------------------------------------------------------------
// Component:  each 1.1*8ms finish a list of AD conversion and output the
//                       digital input values.
// -----------------------------------------------------------------------------
//******************************************************************************
// This line is used to separate code and file header.This is begin.
//*****************************BEGIN_NOMOVE*************************************
// Time£º2016-09-19 10:18:25
// 1: change the filtered AD value source
//*****************************END_NOMOVE***************************************
// This line is used to separate code and file header. This is last line.
//******************************************************************************
#ifndef I_DAT_ANA_H
#define I_DAT_ANA_H

#include "ARCH_CFG.h"
#include "DAT_ANA_CFG.h"
#include "DAT_ANA_INCLUDE.h"

#ifdef cHeadIncludeType_Directly
#include "DAT_ANAx.h"
#include "DAT_PANx.h"
#include "DAT_PAN.h"
#else
#include ".\..\..\..\SCC2Gen\GEN\DAT_ANAx.h"
#include ".\..\..\..\SCC2Gen\GEN\DAT_PANx.h"
#include ".\..\DAT_PAN\DAT_PAN.h"
#endif

#define cDATADC0ChnMax 				16U
#define cDATADC1ChnMax 				11U
#define cDATADCALLChnMax 			18U



#define cU8DATAnaAveragedCount   			((U8)6U)
#define mDATAnaGetFilteredValue(Channel) 	((tDATAnaValue)(ADSumVal[Channel] / (cU8DATAnaAveragedCount - 1U)))
#define mDATAnaGetValue(Channel)      		((tDATAnaValue)(DATAnaBufferFromLDB[Channel]))

typedef U16 tDATAnaValue;
typedef U16 tDATAnaCalculationSize;

extern U16  ADSumVal[cDATAnaNumberOfChanels];
extern tDATAnaValue DATAnaBufferFromLDB[cDATAnaNumberOfChanels];

extern void DATANAInit(void);
extern void DATANAEnterActiveState(void);
extern void DATANALeaveActiveState(void);
extern void DATANATask(void);

extern U16 DATAnaGetValue(U8 u8ADIndex);


#endif /* I_DAT_ANA_H */
