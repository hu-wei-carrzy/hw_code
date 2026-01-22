#ifndef I_LAP_CAN_DATAEXPORT_H
#define I_LAP_CAN_DATAEXPORT_H


extern void LAPCanSetNMOnSt(BOOL bNMOnSt);
extern BOOL LAPCanGetNMOnSt(void);
extern BOOL LAPCanGetBusOffSt(void);
extern BOOL LAPRunInIsRunInTimeOut(void);

#define mSERWriteU1BitIsNMOnDefault(v)                         LAPCanSetNMOnSt((v))
#define mSERReadU1BitIsNMOnDefault()                           LAPCanGetNMOnSt()

#define mSERReadU1BitIsBusOffDefault()                         LAPCanGetBusOffSt()
#define mSERReadU1BitIsRunInTimeOutDefault()  				   LAPRunInIsRunInTimeOut()


#endif
