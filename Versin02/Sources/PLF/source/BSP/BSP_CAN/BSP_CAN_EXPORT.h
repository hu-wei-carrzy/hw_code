/*
 * BSP_CAN_EXPORT.h
 *
 *  Created on: 2018Äê10ÔÂ29ÈÕ
 *      Author: zhanghjq
 */

#ifndef BSP_CAN_EXPORT_H_
#define BSP_CAN_EXPORT_H_

#include "BSP_CAN_COMMON.h"

//export macro
#define BSPCanEnableRXINT(u8MCUCANCh)           BSPCanControlINT((u8MCUCANCh),cINTCtrlType_RX,cINTStEnable)
#define BSPCanDisableRXINT(u8MCUCANCh)          BSPCanControlINT((u8MCUCANCh),cINTCtrlType_RX,cINTStDisabe)

#define BSPCanEnableTXINT(u8MCUCANCh)           BSPCanControlINT((u8MCUCANCh),cINTCtrlType_TX,cINTStEnable)
#define BSPCanDisableTXINT(u8MCUCANCh)          BSPCanControlINT((u8MCUCANCh),cINTCtrlType_TX,cINTStDisabe)

#define BSPCanEnableBusOffINT(u8MCUCANCh)       BSPCanControlINT((u8MCUCANCh),cINTCtrlType_Err,cINTStEnable)
#define BSPCanDisableBusOffINT(u8MCUCANCh)      BSPCanControlINT((u8MCUCANCh),cINTCtrlType_Err,cINTStDisabe)

//export functions
extern void BSPCanCancelTransmission (unsigned char u8MCUCANCh);
extern void BSPCanInit (unsigned char u8MCUCANCh);
extern void BSPCanControlINT (unsigned char u8MCUCANCh, unsigned char u8CtrlType, unsigned char u8INTSt);
extern void BSPCanStartCom (uint8_t u8MCUCANCh);
extern void BSPCanStopCom (uint8_t u8MCUCANCh);
extern void BSPCanCfgPins (void);
extern uint8_t BSPCanSendMsg (uint8_t u8MCUCANCh, tBSPCanSendMsg* ptSendMsg);
extern unsigned short BSPCanGetCANStatus (uint8_t u8MCUCANCh);
extern void BSPCanBusOffRecovery (uint8_t u8MCUCANCh);
extern void BSPCanCfgPins (void);
extern void BSPCanPinAsCANRx (void);
extern void BSPCanPinAsDIN_DisableINT (void);
extern void BSPCanPinAsDIN (void);

extern void BSPCanPinAsDIN_EnableINT(void);

#endif /* BSP_CAN_EXPORT_H_ */
