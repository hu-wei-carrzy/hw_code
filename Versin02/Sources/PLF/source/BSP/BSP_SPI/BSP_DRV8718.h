//******************************************************************************
// Company:      Chery Controls Inc.
// -----------------------------------------------------------------------------
// Copyright:    This software is Chery property.
//               Duplication or disclosure without Chery written authorization
//               is prohibited.
// -----------------------------------------------------------------------------
// Project:      DCZY
// Language:     ANSI-C
// -----------------------------------------------------------------------------
// Component:    DAT_BSDC
//
// -----------------------------------------------------------------------------
// $Date:   July 18 2025 18:14:10  $
// $Archive:
// $Revision:   1.0  $
// -----------------------------------------------------------------------------
/* $Log:      $
 *
 *    July 18 2025 18:14:10
 * Initial revision.
 //
*/
//******************************************************************************

#ifndef BSP_DRV8718_H_
#define BSP_DRV8718_H_

//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//
// #include <system_file_name.h>
// #include "project_file_name.h"
//------------------------------------------------------------------------------
#include "BSP_SPI.h"
//#include ".\..\BSP_PWM\BSP_PWM.h"
//#include ".\..\BSP_ICU\BSP_ICU.h"

//------------------------------------------------------------------------------
// Data prefix for constant & data
//
// unsigned int {u8,u16,u32} / signed int {s8,s16,s32}
// register size unsigned int {r} / float {f32,f64}  / s for struct
// no prefix for other types.
//
//------------------------------------------------------------------------------
// Constant data
//
// #define cu16LAYCmpConstantName   ((U16) ConstantValueUL)
//------------------------------------------------------------------------------
#define	IC_STAT1 	(uint8_t)(0x00)
#define VDS_STAT1	(uint8_t)(0x01)
#define VDS_STAT2	(uint8_t)(0x02)
#define VGS_STAT1	(uint8_t)(0x03)
#define VGS_STAT2	(uint8_t)(0x04)
#define IC_STAT2	(uint8_t)(0x05)
#define IC_STAT3	(uint8_t)(0x06)
#define IC_CTRL1	(uint8_t)(0x07)
#define IC_CTRL2	(uint8_t)(0x08)
#define BRG_CTRL1	(uint8_t)(0x09)
#define BRG_CTRL2	(uint8_t)(0x0A)
#define PWM_CTRL1	(uint8_t)(0x0B)
#define PWM_CTRL2	(uint8_t)(0x0C)
#define PWM_CTRL3	(uint8_t)(0x0D)
#define PWM_CTRL4	(uint8_t)(0x0E)
#define IDRV_CTRL1	(uint8_t)(0x0F)
#define IDRV_CTRL2	(uint8_t)(0x10)
#define IDRV_CTRL3	(uint8_t)(0x11)
#define IDRV_CTRL4	(uint8_t)(0x12)
#define IDRV_CTRL5	(uint8_t)(0x13)
#define IDRV_CTRL6	(uint8_t)(0x14)
#define IDRV_CTRL7	(uint8_t)(0x15)
#define IDRV_CTRL8	(uint8_t)(0x16)
#define IDRV_CTRL9	(uint8_t)(0x17)
#define DRV_CTRL1	(uint8_t)(0x18)
#define DRV_CTRL2	(uint8_t)(0x19)
#define DRV_CTRL3	(uint8_t)(0x1A)
#define DRV_CTRL4	(uint8_t)(0x1B)
#define DRV_CTRL5	(uint8_t)(0x1C)
#define DRV_CTRL6	(uint8_t)(0x1D)
#define DRV_CTRL7	(uint8_t)(0x1E)
#define VDS_CTRL1	(uint8_t)(0x1F)
#define VDS_CTRL2	(uint8_t)(0x20)
#define VDS_CTRL3	(uint8_t)(0x21)
#define VDS_CTRL4	(uint8_t)(0x22)
#define OLSC_CTRL1	(uint8_t)(0x23)
#define OLSC_CTRL2	(uint8_t)(0x24)
#define	UVOV_CTRL	(uint8_t)(0x25)
#define CSA_CTRL1	(uint8_t)(0x26)
#define CSA_CTRL2	(uint8_t)(0x27)
#define CSA_CTRL3	(uint8_t)(0x28)
#define RSVD_CTRL	(uint8_t)(0x29)

#define Write 	0
#define Read  	1
#define TIMEOUT 1

#define Motor1	1
#define Motor2	2
#define Motor3	3
#define	Motor4	4

#define motor_free      0
#define motor_forward   1
#define motor_reverse   2
#define motor_halt     	3

#define MotorMaxSpeed	23000

#define MotorMaxDuty	100


//------------------------------------------------------------------------------
// Exported type
//
// typedef Expression tLAYCmpTypeName;
//------------------------------------------------------------------------------
typedef union
{
	uint16_t TxData;
	struct
	{
		uint8_t Byte;
		struct
		{
			uint8_t Address    :6; //¼Ä´æÆ÷µØÖ·
			uint8_t B14        :1; //¶ÁÐ´ÃüÁî£¬¶ÁÎª1£¬Ð´Îª0
			uint8_t B15        :1; //Ê¼ÖÕÎª0
		}CMD;
	}F;
}DRV8718_TxFrame_u; //·¢ËÍÊý¾ÝÖ¡

typedef union
{
	uint8_t Byte;
	struct
	{
		uint8_t OT_WD_AGD   :1;
		uint8_t OV          :1;
		uint8_t UV          :1;
		uint8_t DS_GS       :1;
		uint8_t WARN        :1;
		uint8_t FAULT       :1;
		uint8_t B14         :1;
		uint8_t B15         :1;
	}B;

}DRV8718_Global_status_t;  //SDO·µ»Ø×´Ì¬Î»

typedef union
{
	uint16_t RxData;
	struct
	{
		uint8_t Byte;            			//·µ»ØÊý¾Ý
		DRV8718_Global_status_t status;     //·µ»Ø×´Ì¬
	}F;
}DRV8718_RxFrame_u; //½ÓÊÜÊý¾Ý

typedef struct
{
	DRV8718_TxFrame_u TxFrame;
	DRV8718_RxFrame_u RxFrame;
}DRV8718_Infos_t;

typedef struct
{
	uint8_t nSleep;
}DRV8718_State_t;

//°ëÇÅ¿ØÖÆÁªºÏÌå
typedef union
{
    uint8_t BRG_CTRL1_CMD;
    struct
    {
        uint8_t half_bridge4    :2;
        uint8_t half_bridge3    :2;
        uint8_t half_bridge2    :2;
        uint8_t half_bridge1    :2;
    }half_bridge;
}MOTOR1_2;

typedef union
{
	uint8_t BRG_CTRL2_CMD;
	struct
	{
        uint8_t half_bridge8    :2;
        uint8_t half_bridge7    :2;
        uint8_t half_bridge6    :2;
        uint8_t half_bridge5    :2;
	}half_bridge;
}MOTOR3_4;

// DRV8718 Ô¤Çý´íÎó×´Ì¬Ã¶¾Ù
typedef enum {
    DRV8718_ERROR_NONE = 0,          // ÎÞ´íÎó
    DRV8718_ERROR_SPI_COMM,          // SPIÍ¨ÐÅ´íÎó£¨Èç¼Ä´æÆ÷¶ÁÐ´Ê§°Ü£©
    DRV8718_ERROR_POR,               // Ô¤Çý³õÊ¼»¯´íÎó
    DRV8718_ERROR_WARN,              // Ô¤Çý¾¯±¨´íÎó
    DRV8718_ERROR_DSGS,              // Ô¤ÇýDSGS´íÎó
    DRV8718_ERROR_UV,                // Ô¤ÇýUV´íÎó
    DRV8718_ERROR_OV,                // Ô¤ÇýUV´íÎó
    DRV8718_ERROR_OTWD,              // Ô¤ÇýOTWD´íÎó
    DRV8718_ERROR_FAULT              // Ô¤Çý¹ÊÕÏ´íÎó
} eDRV8718_ErrorStatus;


//------------------------------------------------------------------------------
// Exported data
//
// extern  tType   u8LAYCmpVariableName;
// extern  tType*  ps32LAYCmpVariableName;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Constant exported data
//
// extern const tType  s8LAYCmpVariableName;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Exported Macros
//
// #define LAYCmpMacroName(...)   (MacroDefinition)
//------------------------------------------------------------------------------



//------------------------------------------------------------------------------
// Exported functions
//
// extern tReturnType LAYCmpFunctionName(tTypeArgument1 ArgumentName1, ... );
//------------------------------------------------------------------------------
extern void DRV8718_Init(void);
extern void DRV8718_Awake(void);
extern void DRV8718_Sleep(void);
extern uint8_t Motor_Direction(uint8_t motor,uint8_t direction);
extern uint8_t Motor_Set_Direction(uint8_t channel, int8_t dir);
extern void BSP_Clear_DRV8718Fault(void);
extern eDRV8718_ErrorStatus BSP_Drv8718_FaultCk(void);



#endif /* BSP_DRV8718_H_ */
