#ifndef I_DAT_CAN_DATAEXPORT_H
#define I_DAT_CAN_DATAEXPORT_H


#include "DAT_CAN_TYPEEXPORT.h"

extern  BOOL  DATCnmGetCanBusOffState(U8 IdCan  );
extern  BOOL  DATCnmGetCanBusOffRecoveringState(U8 IdCan );
#define mSERReadU1BitIsCan0BusStarted()    (DATCnmGetNetworkState(0) == cDATCmnStarted)
#define mSERReadU1BitIsCan1BusStarted()    (DATCnmGetNetworkState(1) == cDATCmnStarted)
#define msERReadU1BitIsCan2BusStarted()    (DATCnmGetNetworkState(2) == cDATCmnStarted)

#define mSERReadU1BitIsCanBusStarted()   mSERReadU1BitIsCan0BusStarted() || \
                                         mSERReadU1BitIsCan1BusStarted() || \
                                         msERReadU1BitIsCan2BusStarted()


#define mSERReadU1BitIsCan0BusOffDefault()   DATCnmGetCanBusOffState(0U)
#define mSERReadU1BitIsCan1BusOffDefault()   DATCnmGetCanBusOffState(1U)
#define mSERReadU1BitIsCan2BusOffDefault()   DATCnmGetCanBusOffState(2U)

#define mSERReadU1BitIsCan0BusOffRecoveringDefault()   DATCnmGetCanBusOffRecoveringState(0U)
#define mSERReadU1BitIsCan1BusOffRecoveringDefault()   DATCnmGetCanBusOffRecoveringState(1U)
#define mSERReadU1BitIsCan2BusOffRecoveringDefault()   DATCnmGetCanBusOffRecoveringState(2U)


#endif
