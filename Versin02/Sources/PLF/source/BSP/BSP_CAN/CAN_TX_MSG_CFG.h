/*
 * CAN_TX_MSG_CFG.h
 *
 *  Created on: 2018年10月29日
 *      Author: zhanghjq
 */

#ifndef CAN_TX_MSG_CFG_H_
#define CAN_TX_MSG_CFG_H_

typedef struct
{
    uint32_t u32MsgID;
    uint8_t u8MsgHandle; //这个Handle在编码时就已经内置了通道信息了
    uint8_t u8CANCh;

} tTxMsgForGeno;

//#define cTxMsgForGenoNum    2//jjq
#define cTxMsgForGenoNum    7//jjq
//发送消息用
static tTxMsgForGeno guArrTxMsgForCanIf [cTxMsgForGenoNum] = //这里的ID是从DBC中导出的，因为在DBC中规定了要发送什么ID，生成的CANIf.c中已经包含了部分ID的值
{
//    {0x18ffa0aa,0,0},
//    {0x1cec33aa,1,1}
		{0x2C2, 0, 0},
		{0x38E, 1, 1},
		{0x40E, 2, 0},
		{0x572, 3, 0},
		{0x633, 4, 1},
		{0x702, 5, 1},
		{0x780, 6, 1}
};

#endif /* CAN_TX_MSG_CFG_H_ */
