#ifndef I_DAT_CAN_FUNCEXPORT_H
#define I_DAT_CAN_FUNCEXPORT_H

#include ".\DAT_CNM\DAT_CNM.h"


#define mSERControlCan0(Ctrl)               mSERControlCan0##Ctrl()
#define mSERControlCan1(Ctrl)               mSERControlCan1##Ctrl()
#define mSERControlCan2(Ctrl)               mSERControlCan2##Ctrl()

#define mSERControlCan0StartCom()           DATCnmStartCom(0)
#define mSERControlCan1StartCom()           DATCnmStartCom(1)
#define mSERControlCan2StartCom()           DATCnmStartCom(2)


#define mSERControlCan0StopCom()            DATCnmStopCom(0)
#define mSERControlCan1StopCom()            DATCnmStopCom(1)
#define mSERControlCan2StopCom()            DATCnmStopCom(2)




#endif
