#ifndef I_BSP_CAN_IMPORT_H
#define I_BSP_CAN_IMPORT_H

//#include "BSP_CAN_COMMON.h"

#ifdef cMCUCANCh0
extern void LDBCan_MCUCANCh0_RxCBK(tBSPCanRxCBK* ptBSPCanRxCBK);
extern void LDBCan_MCUCANCh0_TxCBK(tBSPCanTxCBK* ptBSPCanTxCBK);
extern void LDBCan_MCUCANCh0_BufOffCBK(tBSPCanErrCBK* pErrCBK);
#endif

#ifdef cMCUCANCh1
extern void LDBCan_MCUCANCh1_RxCBK(tBSPCanRxCBK* ptBSPCanRxCBK);
extern void LDBCan_MCUCANCh1_TxCBK(tBSPCanTxCBK* ptBSPCanTxCBK);
extern void LDBCan_MCUCANCh1_BufOffCBK(tBSPCanErrCBK* pErrCBK);
#endif

#ifdef cMCUCANCh2
extern void LDBCan_MCUCANCh2_RxCBK(tBSPCanRxCBK* ptBSPCanRxCBK);
extern void LDBCan_MCUCANCh2_TxCBK(tBSPCanTxCBK* ptBSPCanTxCBK);
extern void LDBCan_MCUCANCh2_BufOffCBK(tBSPCanErrCBK* pErrCBK);
#endif

#endif
