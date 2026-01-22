/* =================================================================================
File name:  BLDC_FOC_Settings.H

Originator:	Digital Control Systems Group
			Texas Instruments

Description:
Incremental Build Level control file.
=====================================================================================
 History:
-------------------------------------------------------------------------------------
 04-15-2010	Version 1.1
=================================================================================  */
#ifndef __PROJ_SETTINGS_H__
#define __PROJ_SETTINGS_H__

#include "MOTORA_FOC.h"
#include "MOTORA_Hall.h"
#include "MOTORA_control.h"
#include "MOTORA_SVPWM.h"

#define TRUE 1
#define FALSE 0

#define PI 3.14159265358979
#define SYSTEM_FREQUENCY 60U
#define FREQUENCY_10	10U
#define FREQUENCY_15	15U

// Define the ISR frequency (kHz)
#define ISR_FREQUENCY  FREQUENCY_15

//uint16 Tprioed;
//uint8 u8_motor_type = 8U;	//电机类型
//#define POLES               4
#define VDCBUS				36.3						// [(100+10)/10]*3.3 = 36.3V
#define BASE_VOLTAGE    	20.9578		    			// Base peak phase voltage (volt), maximum measurable DC Bus(66.32V)/sqrt(3)
#define BASE_CURRENT        16.5
#define BASE_FREQ 			(BASE_SPEED/60) * (POLES/2)	//YS: 200：3000rpm    240： 3600rpm      280:4200
                                                        //HC: 250: 3000rpm    300: 3600rpm      350:4200
#define BASE_SPEED 			3600



#endif

