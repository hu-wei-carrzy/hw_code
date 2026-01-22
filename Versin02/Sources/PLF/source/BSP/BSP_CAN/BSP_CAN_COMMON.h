/*
 * BSP_CAN_COMMON.h
 *
 *  Created on: 2018年10月29日
 *      Author: zhanghjq
 */

#ifndef BSP_CAN_COMMON_H_
#define BSP_CAN_COMMON_H_

//export function related
#define cEnableTransceiver      0U
#define cDisableTransceiver     1U

#define cINTCtrlType_RX   0
#define cINTCtrlType_TX   1
#define cINTCtrlType_Err  2

#define cINTStEnable    1
#define cINTStDisabe    0

#define cMaxMCUCANChaNum           3

#define cMCUCANCh0               0
#define cMCUCANCh1               1
#define cMCUCANCh2               2

typedef struct
{
    unsigned int u32MsgID;
    unsigned char u8IsEntended;
    unsigned char u8MCUCANCh;
    unsigned char u8CANErrCode;
} tBSPCanErrCBK;

typedef struct
{
    unsigned int u32MsgID;
    unsigned int u32Data0;
    unsigned int u32Data1;
    unsigned char u8IsEntended;
    unsigned char u8MsgHandle;
    unsigned char u8CANCh;
    unsigned char u8IsForCanIf;
    unsigned char MsgBufId;
} tBSPCanRxCBK;

typedef struct
{
    unsigned int u32MsgID;
    unsigned char u8IsEntended;
    unsigned char u8MCUCANCh;
} tBSPCanTxCBK;

typedef void (*pfBSPCanTxCallback) (tBSPCanTxCBK*);
typedef void (*pfBSPCanRxCallback) (tBSPCanRxCBK*);
typedef void (*pfBSPCanErrCallback) (tBSPCanErrCBK*);

typedef struct
{
    pfBSPCanTxCallback pfnTxCallback;
    pfBSPCanRxCallback pfnRxCallback;
    pfBSPCanErrCallback pfnErrCallback;
} tBSPCanCallback;

typedef struct
{
    unsigned int u32MsgID;
    unsigned int u32Data0;
    unsigned int u32Data1;
    unsigned char u8IsExtended;
    unsigned char u8Source;
    unsigned char u8Len;
} tBSPCanSendMsg;

typedef struct
{
    uint8_t u8MsgBufId;
    uint8_t u8handleIndex;
    uint32_t u32MsgID;
    uint8_t u8Path; /* 0到LDB，1到Canif */
} MsgBufHdlMap_Type;

typedef struct
{
    uint8_t u8MsgBufPos;
    uint8_t u8handleIndex;
    uint32_t u32MsgID;
    uint32_t u32IdMask;
    uint8_t u8Path;
} MsgFilterBufHdlMap_Type;

#endif /* BSP_CAN_COMMON_H_ */
