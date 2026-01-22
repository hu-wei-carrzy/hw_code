#ifndef I_DAT_PAN_PIN_TYPE_H
#define I_DAT_PAN_PIN_TYPE_H

#include "DAT_PAN_INCLUDE.h"

typedef struct
{
	U8 u8PinIndex;
	U8 u8PinType;
	U8 u8ADIndex;
}tPinCfg;

#define cU8AI        		((U8)0U)
#define cU8Pstv      		((U8)2U)
#define cU8PstvAct   		((U8)3U)
#define cU8NegAct    		((U8)4U)
#define cU8Neg6MADI    		((U8)7U)

#define cU8PinMaxNum         ((U8)57U)
#define cU16DICalValueMax    ((U16)64256U)

extern const tPinCfg  mtPinCfgArr[cU8PinMaxNum] ;
#endif
