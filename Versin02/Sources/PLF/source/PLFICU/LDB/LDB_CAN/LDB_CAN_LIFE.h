
#ifndef  I_LDB_CAN_LIFE_H_
#define  I_LDB_CAN_LIFE_H_

/*-------------------------------------------------------------------------
  Included files to resolve specific definitions in this file

  #include <system_file_name.h>
  #include "project_file_name.h"
  -------------------------------------------------------------------------*/
#include "ARCH_CFG.h"

#ifdef cHeadIncludeType_Directly
#include "ldb.h"
#else
#include ".\..\LDB\LDB_API\ldb.h"
#endif


// --------------------------------------------------------------
//     Channel CAN
// --------------------------------------------------------------

// -- LDB Controls --
// Bus Off Signal input controller
#define cLDBCanBusOff               ((tCtrl)0x00U)
// Bus On Signal input controller
#define cLDBCanBusOn                ((tCtrl)0x01U)
// passive error
#define cLDBCanPassiveError         ((tCtrl)0x02U)
// Wake up received
#define cLDBCanWakeUp               ((tCtrl)0x03U)
// NERR physical CAN layer defect is not present
#define cLDBCanNerrOff              ((tCtrl)0x04U)
// NERR physical CAN layer defect is present
#define cLDBCanNerrOn               ((tCtrl)0x05U)


// -- DAT Controls --
// Can cell auto diagnostic
#define cLDBCanSelfDiag          ((tCtrl)0x07U)
// Reset the controller
#define cLDBCanInit              ((tCtrl)0x08U)
// Start Hardware Layer
#define cLDBCanStart             ((tCtrl)0x09U)
// Stop Hardware Layer
#define cLDBCanStop              ((tCtrl)0x0AU)

#define cLDBCANEnterActiveMode        cLDBCanStart
#define cLDBCANEnterSleepMode         cLDBCanStop

// Wake up authorization control
#define cLDBCanAutoriserCtrlWakeUp  ((tCtrl)0x0BU)

// Cancel Transmission in progress
#define cLDBCanCancelTransmissionInProgress  ((tCtrl)0x0CU)

// Can reception interrupt authorization
#define cLDBCanEnableRxCallBack  ((tCtrl)0x0DU)
// Can reception interrupt banning
#define cLDBCanDisableRxCallBack  ((tCtrl)0x0EU)

// Can Bus_off interrupt authorization
#define cLDBCanEnableBus_offCallBack  ((tCtrl)0x0FU)
// Can Bus_off interrupt banning
#define cLDBCanDisableBus_offCallBack  ((tCtrl)0x10U)


// --------------------------------------------------------------
//      Definition of Ent Callback channel (without address)
// --------------------------------------------------------------
//you can enable the following call back functions if necessary
//and if necessary, you can add new call back function .

#ifdef cLDBChannelCan

extern void    DATCanCallBackEndCtrl   (tCtrl, tStatus);
extern void    DATCanCallBackCtrl      (tCtrl);
extern void    DATCanCallBackTxWithAddr(tAddress, tStatus);
extern const   tRxSpontWithAddr        DATCanRxSpontTable[];
extern const   U16                     DATCanRxSpontNbr;

#define cLDBCanAdrControllerSts         ((tAddress)(0x00))
extern  void    DATCanCallBackTxedCplNmMsg(U8 *pu8Data);

#endif // cLDBChannelCan

// channel 0
#if defined(cLDBChannelCan0) || defined(cLDBChannelCan1)

extern void    DATMultiCanCallBackEndCtrl   (tCtrl, tStatus,U8);
extern void    DATMultiCanCallBackCtrl (U8 ,      tCtrl);
extern void    DATMultiCanCallBackTxWithAddr (U8 ,tAddress, tStatus);


#ifdef cLDBChannelCan0
extern const   tRxSpontWithAddr         DATCan0RxSpontTable[];
//¨º1¨®?¨ª3¨°?¦Ì?RX??¦Ì¡Âo¡¥¨ºy????¡Á¨¦¨¤¡ä¡ä|¨¤¨ª?¨´¨®DCAN???¡é¡ê??a?¨´?¨ª?¨¦¨°?¨¨£¤3y??CAN¨ª¡§¦Ì¨¤¦Ì?¨°¨¤¨¤¦ÌD?¨¢?
extern const   tRxSpontWithAddr         DATCanRxSpontTable[];
extern const   U16                      DATCan0RxSpontNbr;

#define cLDBCanAdrControllerSts         ((tAddress)(0x00))
extern  void    DATCan0CallBackTxedCplNmMsg(U8 *pu8Data);
#endif

#ifdef cLDBChannelCan1
extern const   tRxSpontWithAddr         DATCan1RxSpontTable[];
extern const   U16                      DATCan1RxSpontNbr;

//#define cLDBCan1AdrControllerSts         ((tAddress)(0x00))
extern  void    DATCan1CallBackTxedCplNmMsg(U8 *pu8Data);
#endif

#endif // cLDBChannelCan1


#endif
