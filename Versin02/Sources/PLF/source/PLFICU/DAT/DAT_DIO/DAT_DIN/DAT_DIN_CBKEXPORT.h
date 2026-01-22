#ifndef I_DAT_DIN_CBKEXPORT_H
#define I_DAT_DIN_CBKEXPORT_H



extern void   DATDinCallBackCtrl(tCtrl Ctrl,tStatus Status);
extern void   DATDinCallBackRxWithoutAddr(tStatus Statut);
extern void   DATDinCallBackEndCtrl(tCtrl Ctrl, tStatus Statut);

#define	mLDBDINCallBackControl(Ctrl,Status)				           DATDinCallBackCtrl(Ctrl,Status)
#define	mLDBDINCallBackRxWithoutAddr(Statut)			       DATDinCallBackRxWithoutAddr(Statut)
#define	mLDBDINCallBackEndCtrl(Ctrl,Statut)			       DATDinCallBackEndCtrl(Ctrl,Statut)

#endif
