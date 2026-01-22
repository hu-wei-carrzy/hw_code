//******************************************************************************
// Copyright:    This software is JYD property.
//               Duplication or disclosure without JYD written authorization
//               is prohibited.
// -----------------------------------------------------------------------------
// Project:      BCM313
// Language:     C
// -----------------------------------------------------------------------------
// Component:  init the EEP content with default values
//                       
// -----------------------------------------------------------------------------
//******************************************************************************
// This line is used to separate code and file header.This is begin.
//*****************************BEGIN_NOMOVE*************************************
// Time:2016-09-19 09:31:07
// 1: change cEEPInitSetpSize:0x09->0x12 because use the simulation
//    I2c, its speed is slow.
//*****************************END_NOMOVE***************************************
// This line is used to separate code and file header. This is last line.
//******************************************************************************
#ifndef I_LAP_EEP_CFG_H
#define I_LAP_EEP_CFG_H

#include "LAP_EEP_INCLUDE.h"

#define cU16EEPInitCondition1    0XCA55
#define cU16EEPInitCondition2    0X55BA
#define cU8EEPInitCondition3     0X55

//one step time =  cEEPInitSetpSize*20ms
//one step time = initialize one EEP group
#define cEEPInitSetpSize       ((U8)(0X60))

#define mU16EEPInitSetp(value)   ((U16)(((U16)value)*cEEPInitSetpSize))
#define cU16SetpTimeMs           cEEPInitSetpSize*20


#define cU16EEPInitStep_0        mU16EEPInitSetp(0)
#define cU16EEPInitStep_1        mU16EEPInitSetp(1)
#define cU16EEPInitStep_2        mU16EEPInitSetp(2)
#define cU16EEPInitStep_3        mU16EEPInitSetp(3)
#define cU16EEPInitStep_4        mU16EEPInitSetp(4)
#define cU16EEPInitStep_5        mU16EEPInitSetp(5)
#define cU16EEPInitStep_6        mU16EEPInitSetp(6)
#define cU16EEPInitStep_7        mU16EEPInitSetp(7)
#define cU16EEPInitStep_8        mU16EEPInitSetp(8)
#define cU16EEPInitStep_9        mU16EEPInitSetp(9)
#define cU16EEPInitStep_10        mU16EEPInitSetp(10)
#define cU16EEPInitStep_11        mU16EEPInitSetp(11)
#define cU16EEPInitStep_12        mU16EEPInitSetp(12)
#define cU16EEPInitStep_13        mU16EEPInitSetp(13)
#define cU16EEPInitStep_14        mU16EEPInitSetp(14)
#define cU16EEPInitStep_15        mU16EEPInitSetp(15)
#define cU16EEPInitStep_16        mU16EEPInitSetp(16)
#define cU16EEPInitStep_17        mU16EEPInitSetp(17)
#define cU16EEPInitStep_18        mU16EEPInitSetp(18)
#define cU16EEPInitStep_19        mU16EEPInitSetp(19)
#define cU16EEPInitStep_20        mU16EEPInitSetp(20)
#define cU16EEPInitStep_21        mU16EEPInitSetp(21)
#define cU16EEPInitStep_22        mU16EEPInitSetp(22)
#define cU16EEPInitStep_23        mU16EEPInitSetp(23)
#define cU16EEPInitStep_24        mU16EEPInitSetp(24)
#define cU16EEPInitStep_25        mU16EEPInitSetp(25)
#define cU16EEPInitStep_26        mU16EEPInitSetp(26)
#define cU16EEPInitStep_27        mU16EEPInitSetp(27)
#define cU16EEPInitStep_28        mU16EEPInitSetp(28)
#define cU16EEPInitStep_29        mU16EEPInitSetp(29)
#define cU16EEPInitStep_30        mU16EEPInitSetp(30)
#define cU16EEPInitStep_31        mU16EEPInitSetp(31)
#define cU16EEPInitStep_32        mU16EEPInitSetp(32)
#define cU16EEPInitStep_33        mU16EEPInitSetp(33)
#define cU16EEPInitStep_34        mU16EEPInitSetp(34)
#define cU16EEPInitStep_35        mU16EEPInitSetp(35)
#define cU16EEPInitStep_36        mU16EEPInitSetp(36)
#define cU16EEPInitStep_37        mU16EEPInitSetp(37)
#define cU16EEPInitStep_38        mU16EEPInitSetp(38)
#define cU16EEPInitStep_39        mU16EEPInitSetp(39)
#define cU16EEPInitStep_40        mU16EEPInitSetp(40)
#define cU16EEPInitStep_41        mU16EEPInitSetp(41)
#define cU16EEPInitStep_42        mU16EEPInitSetp(42)
#define cU16EEPInitStep_43        mU16EEPInitSetp(43)
#define cU16EEPInitStep_44        mU16EEPInitSetp(44)
#define cU16EEPInitStep_45        mU16EEPInitSetp(45)
#define cU16EEPInitStep_46        mU16EEPInitSetp(46)
#define cU16EEPInitStep_47        mU16EEPInitSetp(47)
#define cU16EEPInitStep_48        mU16EEPInitSetp(48)
#define cU16EEPInitStep_49        mU16EEPInitSetp(49)
#define cU16EEPInitStep_50        mU16EEPInitSetp(50)
#define cU16EEPInitStep_51        mU16EEPInitSetp(51)
#define cU16EEPInitStep_52        mU16EEPInitSetp(52)

//NOTE:ECUReset > RebuildErrorGroup > SetInitFlag > LastGrup > Begin
#define cU16EEPInitSetp_Begin             cU16EEPInitStep_0

#include "LAP_EEP_INIT_GEN.h"



#define cU8EnableEEPInit

extern BOOL LAPEEPCfgIsNeedInitEEP(void);
extern void LAPEEPCfgStopSomeTask(void);

#endif
