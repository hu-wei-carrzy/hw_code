#ifndef I_LAP_CAN_CFG_H
#define I_LAP_CAN_CFG_H

//读到的数据为U16，每位表示0.01%,实际发送要求为0.4 %/bit，故除以40
#define cU16FuelPercentRate     ((U16)40U)
//2017年10月16日 14:27:31
//根据系统需求，外发里程有最大值限制
//分辨率：5 m/bit, 偏移量 0，范围：0 to 21,055,406 km
//这里的单位为km
#define cU32InvalidMileKm 		(21055406U)

#define cU16AirPresMax				(1000U)

#endif
