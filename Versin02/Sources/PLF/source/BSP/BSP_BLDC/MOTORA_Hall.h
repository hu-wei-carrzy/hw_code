/*
 * Hall_Pro.h
 *
 *  Created on: 2016年10月31日
 *      Author: shenhua
 */

#ifndef FWS_HALL_PRO_H_
#define FWS_HALL_PRO_H_

#include "Platform_Types.h"
#include "SWLIBS_Typedefs.h"

#define CLOCKWISE				1
#define ANTICLOCKWISE			-1

#define EANGLE_36			360.0

#define EANGLE_0			0.0
#define EANGLE_6			60.0
#define EANGLE_12			120.0
#define EANGLE_18			180.0
#define EANGLE_24			240.0
#define EANGLE_30			300.0

//#define EANGLE_0			300.0
//#define EANGLE_6			0.0
//#define EANGLE_12			60.0
//#define EANGLE_18			120.0
//#define EANGLE_24			180.0
//#define EANGLE_30			240.0
//
//
//#define EANGLE_0			240.0
//#define EANGLE_6			300.0
//#define EANGLE_12			0.0
//#define EANGLE_18			60.0
//#define EANGLE_24			120.0
//#define EANGLE_30			180.0
//
//#define EANGLE_0			180.0
//#define EANGLE_6			240.0
//#define EANGLE_12			300.0
//#define EANGLE_18			0.0
//#define EANGLE_24			60.0
//#define EANGLE_30			120.0
//
//#define EANGLE_0			120.0
//#define EANGLE_6			180.0
//#define EANGLE_12			240.0
//#define EANGLE_18			300.0
//#define EANGLE_24			0.0
//#define EANGLE_30			60.0
//
//#define EANGLE_0			60.0
//#define EANGLE_6			120.0
//#define EANGLE_12			180.0
//#define EANGLE_18			240.0
//#define EANGLE_24			300.0
//#define EANGLE_30			0.0


#define EANGLE_LR_SCOPE		30.0
#define HALL_DEFAULT        {1,1,1,1,1,1,1,1,0,0,0,0}

#define cHALL_TIME_MAX			0xFFFFFFFF

#define HALL_ERROR_NUM_DELAY_TIMES 		3U    // 30ms

enum HALL_STATE
{
	HALLSTATE_1 = 1,
	HALLSTATE_2,
	HALLSTATE_3,
	HALLSTATE_4,
	HALLSTATE_5,
	HALLSTATE_6,
	HALLSTATE_NUM_ERROR,
	HALLSTATE_ORDER_ERROR
};


typedef struct _HALL3_
{
	uint16 hall_state;		/*当前霍尔状态*/
	uint16 pre_hall_state;	/*之前的状态*/
	uint16 bak_hall_state;	/*前一个状态*/
	sint16 direction;		/*1: clockwise, -1: anticlockwise*/
	float32 e_angle;			/*电角度*/
	uint16 hall_state_sin;
	uint16 pre_hall_state_sin;
	sint16 direction_sin;
	float32 e_angle_sin;
	uint32 pre_hall_state_time;
	uint32 hall_state_time;
	uint16 error_num;		/*数值错误*/
	uint16 error_order;		/*数值错误*/
}HALL3;


typedef struct _tSensorHall_
{
	uint8 InA;
	uint8 InB;
	uint8 InC;
	uint8 InABC;
	uint8 Sector;
	uint16 Period[6];
    uint16 Ftm2HallCnt;
}tSensorHall;



#define ROTATION_DIR_CW         		0
#define ROTATION_DIR_CCW        		1

extern void get_HallState(void);
extern void get_hallnum(void);
extern void get_Speed_Value(void);
extern void init_hall(void);
extern void clear_fault_hall(void);
extern void pre_hall_init(void);
extern void dia_hallA(void);
extern HALL3 hall3;
extern float32 Speed_calc_Fb;
extern uint8  rotationDir;
extern tSensorHall 	SensorHall;

#endif /* FWS_HALL_PRO_H_ */
