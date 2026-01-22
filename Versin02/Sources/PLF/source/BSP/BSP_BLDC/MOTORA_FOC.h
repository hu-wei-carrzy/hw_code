/* =================================================================================
File name:       CLARKE.H  (IQ version)

Originator:	Digital Control Systems Group
			Texas Instruments

Description:
Header file containing constants, data type, and macro definition for the CLARKE.
=====================================================================================
 History:
-------------------------------------------------------------------------------------
 04-15-2010	Version 1.1
------------------------------------------------------------------------------*/
#ifndef __BSP_FOCA_H__
#define __BSP_FOCA_H__

#include "Platform_Types.h"

/*-----------------------------------------------------------------------------
Default initalizer for the PARK object.
-----------------------------------------------------------------------------*/
typedef struct {  float32  Ref;   			// Input: reference set-point
				  float32  Fbk;   			// Input: feedback
				  float32  Out;   			// Output: controller output
				  float32  c1;   			// Internal: derivative filter coefficient 1
				  float32  c2;   			// Internal: derivative filter coefficient 2
				} PID_GRANDO_TERMINALS;
				// note: c1 & c2 placed here to keep structure size under 8 words

typedef struct {  float32  Kr;				// Parameter: reference set-point weighting
				  float32  Kp;				// Parameter: proportional loop gain
				  float32  Ki;			    // Parameter: integral gain
				  float32  Kd; 		        // Parameter: derivative gain
				  float32  Km; 		        // Parameter: derivative weighting
				  float32  Umax;			// Parameter: upper saturation limit
				  float32  Umin;			// Parameter: lower saturation limit
				} PID_GRANDO_PARAMETERS;

typedef struct {  float32  up;				// Data: proportional term
				  float32  ui;				// Data: integral term
				  float32  ud;				// Data: derivative term
				  float32  v1;				// Data: pre-saturated controller output
				  float32  i1;				// Data: integrator storage: ui(k-1)
				  float32  d1;				// Data: differentiator storage: ud(k-1)
				  float32  d2;				// Data: differentiator storage: d2(k-1)
				  float32  w1;				// Data: saturation record: [u(k-1) - v(k-1)]
				} PID_GRANDO_DATA;


typedef struct {  PID_GRANDO_TERMINALS	term;
				  PID_GRANDO_PARAMETERS param;
				  PID_GRANDO_DATA		data;
				} PID_GRANDO_CONTROLLER;

typedef struct {  float32  Ref;   			// Input: reference set-point
				  float32  Fbk;   			// Input: feedback
				  float32  Out;   			// Output: controller output
				  float32  Kp;				// Parameter: proportional loop gain
				  float32  Ki;			    // Parameter: integral gain
				  float32  viUmax;			// Parameter: upper integral limit
				  float32  viUmin;			// Parameter: lower integral limit
				  float32  Umax;			// Parameter: upper saturation limit
				  float32  Umin;			// Parameter: lower saturation limit
				  float32  up;				// Data: proportional term
				  float32  ui;				// Data: integral term
				  float32  v1;				// Data: pre-saturated controller output
				  float32  i1;				// Data: integrator storage: ui(k-1)
				  float32  w1;				// Data: saturation record: [u(k-1) - v(k-1)]
				} PI_CONTROLLER;

typedef PID_GRANDO_CONTROLLER	*PID_handle;


/*-----------------------------------------------------------------------------
Default initalisation values for the PID_GRANDO objects
-----------------------------------------------------------------------------*/
#define PI_CONTROLLER_DEFAULTS {	\
						   0.0, 	\
                           0.0, 	\
						   0.0, 	\
                           2.0,	\
                           0.0,	\
						   2.0,	\
                           -2.0, 	\
						   2.0,	\
                           -2.0, 	\
                           0.0,	\
                           0.0, 	\
                           0.0,	\
                           0.0,	\
						   2.0 	\
              			  }
/*------------------------------------------------------------------------------
 	PID_GRANDO Macro Definition
------------------------------------------------------------------------------*/


/*------------------------------------------------------------------------------
	RAMP(Sawtooh) Generator Macro Definition
------------------------------------------------------------------------------*/
typedef struct { float32    TargetValue; 	// Input: Target input (pu)
				 uint32     RampDelayMax;	// Parameter: Maximum delay rate (Q0) - independently with global Q
		 	 	 float32    RampLowLimit;	// Parameter: Minimum limit (pu)
				 float32    RampHighLimit;	// Parameter: Maximum limit (pu)
				 uint32     RampDelayCount; // Variable: Incremental delay (Q0) - independently with global Q
				 float32    SetpointValue;	// Output: Target output (pu)
				 uint32     EqualFlag;		// Output: Flag output (Q0) - independently with global Q
		  	   } RMPCNTL;

typedef RMPCNTL *RMPCNTL_handle;
/*-----------------------------------------------------------------------------
Default initalizer for the RMPCNTL object.
-----------------------------------------------------------------------------*/
#define RMPCNTL_DEFAULTS {  0.0, 	 \
                            5,		 \
                           -3500.0,  \
                           3500.0,   \
                            0,       \
                          	0.0,       \
                          	0,       \
                          	0.0,       \
                   		  }
/*------------------------------------------------------------------------------
 	RAMP Controller Macro Definition
------------------------------------------------------------------------------*/



extern void RC_MACRO1(RMPCNTL *v);
extern void PI_MACRO1(PI_CONTROLLER *v);


#endif // __BSP_FOCA_H__

