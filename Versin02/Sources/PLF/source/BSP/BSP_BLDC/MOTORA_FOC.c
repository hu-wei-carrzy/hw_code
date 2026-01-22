#include "MOTORA_FOC.h"

float32 step_test = 0.15;
void RC_MACRO1(RMPCNTL *v)
{
    float32 rc_tmp;
    float32 step;
	rc_tmp = v->TargetValue - v->SetpointValue;
/*  ADC中断 每秒增加30 */
	step = step_test;
	if(fabs(rc_tmp) >= step)
	{
		if (v->TargetValue >= v->SetpointValue)
			v->SetpointValue += step;
		else
			v->SetpointValue -= step;

		if(v->SetpointValue >= v->RampHighLimit)
		{
			v->SetpointValue = v->RampHighLimit;
		}
		if(v->SetpointValue <= v->RampLowLimit)
		{
			v->SetpointValue = v->RampLowLimit;
		}
	}
}



void PI_MACRO1(PI_CONTROLLER *v)
{
	/* proportional term */
	v->up = v->Ref - v->Fbk;

	if((v->Out > v->Umin)&&(v->Out < v->Umax))
	{
		/* integral term */
		v->ui = (v->Out == v->v1)?((v->Ki*v->up)+ v->i1) : v->i1;

		if(v->ui > v->viUmax)
		{
			v->ui = v->viUmax;
		}
		else if(v->ui < v->viUmin)
		{
			v->ui = v->viUmin;
		}
	}

	v->i1 = v->ui;

	/* control output */
	v->v1 = (v->Kp*(v->up + v->ui));

	v->Out = v->v1;

	if(v->v1 >= v->Umax)
	{
		v->v1 = v->Umax;
		v->Out = v->Umax;
	}
	if(v->v1 <= v->Umin)
	{
		v->v1 = v->Umin;
		v->Out = v->Umin;
	}
}



