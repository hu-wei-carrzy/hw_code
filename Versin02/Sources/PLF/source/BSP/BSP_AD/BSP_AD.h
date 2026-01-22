#ifndef I_BSP_AD_H
#define I_BSP_AD_H

#include "ARCH_CFG.h"
#include ".\..\BSP_COMMON\BSP_COMMON.h"
#include <stdint.h>
#include".\..\..\PLFICU\LDB\LDB_API\LDBTYPES.h"

#define cMaskForBit0           ((uint8_t)0X01)
#define cShiftSizeForBit0      ((uint8_t)0X00)
#define cMaskForBit1           ((uint8_t)0X02)
#define cShiftSizeForBit1      ((uint8_t)0X01)
#define cMaskForBit2           ((uint8_t)0X04)
#define cShiftSizeForBit2      ((uint8_t)0X02)
#define cMaxWaitLoopUpperLimit ((uint16_t)10000)

#define ADC0_HS0_chn1         0u;
#define ADC0_HS0_chn2         1u;
#define ADC0_HS0_chn3         2u;
#define ADC0_HS0_chn4         3u;
#define ADC0_HS1_chn5         4u;
#define ADC0_HS1_chn6         5u;
#define ADC0_HS1_chn7         6u;
#define ADC0_HS1_chn8         7u;
// export functions
extern uint8_t BSPAdReadAdc0ConversionFlg(void);
extern uint8_t BSPAdReadAdc1ConversionFlg(void);
extern uint16_t BSPAdReadAdc0Value(void);
extern uint16_t BSPAdReadAdc1Value(void);
extern void BSPAdSelectADC0chn(uint8_t hardware_chn);
extern void BSPAdSelectADC1chn(uint8_t hardware_chn);
extern void BSPAdInit(void);
extern void BSPAdStart(void);
extern void BSPAdStop(void);
extern void BSPAdAdcStart(void);
extern uint8_t BSPAdErrorStatusGet(void);
extern void BSPAdPoutSwitchChannel(uint8_t u8PoutSel);
extern void BSPAdSwitch4051Channel(uint8_t u8ChnSel);
extern void BSPAdInitEnd(void);

enum
{
	eAdHdCh0 = 0,
	eAdHdCh1,
	eAdHWCh2,
	eAdHWCh3,
	eAdHWCh4,
	eAdHWCh5,
	eAdHWCh6,
	eAdHWCh7,
	eAdHWCh8,
	eAdHWCh9,
	eAdHWCh10,
	eAdHWCh11,
	eAdHWCh12,
	eAdHWCh13,
	eAdHWCh14,
	eAdHWCh15,
};

#endif
