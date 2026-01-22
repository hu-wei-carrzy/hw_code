#ifndef I_DAT_BLDC_EXPORTTYPE_H
#define I_DAT_BLDC_EXPORTTYPE_H


enum
{
	eMotorSta_Stop,				//停机
	eMotorSta_FWD,              //正转（推杆伸出）
	eMotorSta_REV,              //反转（推杆缩回）
	eMotorSta_FWD_Locked,       //正转（推杆伸出）堵转
	eMotorSta_REV_Locked,       //反转（推杆缩回）堵转
	eMotorSta_Warning,          //轻微故障（可自恢复，应用层可忽略）
	eMotorSta_Alarm             //严重故障（需处理后（如延时后）恢复）
};

#endif
