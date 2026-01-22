/*
 * DAT_BAT_FORMULA.h
 *
 *  Created on: 2017年4月6日
 *      Author: liswc
 */

#ifndef SOURCE_PLFICU_DAT_DAT_BAT_DAT_BAT_FORMULA_H_
#define SOURCE_PLFICU_DAT_DAT_BAT_DAT_BAT_FORMULA_H_


/**
voltage = adc * ((10+100)/10)(分压比）*4.763v /1024  +0.485v 校准
//2017年12月7日 16:18:24，zjb,添加LIBGetADBaseVol防止遗漏AD基准电压
voltage = adc * ((10+100)/10)(分压比）*(LIBGetADBaseVol()/1000)v /1024  +0.485v 校准
 */
#define mBatAdcToVoltage(adc) ((U32)((((adc) * 55000U) / 1024U) + 485U))


#endif /* SOURCE_PLFICU_DAT_DAT_BAT_DAT_BAT_FORMULA_H_ */
