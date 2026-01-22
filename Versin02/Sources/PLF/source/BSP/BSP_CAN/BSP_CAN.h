/*
 * BSP_CAN.h
 *
 *  Created on: 2018年10月29日
 *      Author: zhanghjq
 */

#ifndef BSP_CAN_H_
#define BSP_CAN_H_

#ifdef cHeadIncludeType_Directly
#include "BSP_COMMON.h"
#else
#include ".\..\BSP_COMMON\BSP_COMMON.h"
#include "s32k144.h"
#endif

#include "BSP_CAN_COMMON.h"
#include "BSP_CAN_IMPORT.h"

typedef struct
{
    CAN_Type * Addr;
    uint8_t u8MaxMb;
    uint8_t u8ClkSel;
} tCanChnAddrMbMax;

typedef struct
{
    uint16_t u16BaudRateValue;
    uint8_t u16Prescaler;
    uint8_t u8ProgSegment;
    uint8_t u8TimeSegment1;
    uint8_t u8TimeSegment2;
    uint8_t u8SyncJumpWidth;
} tBSPCanBitRateCfg;

typedef void (*pf_can_process) (void);

typedef struct
{
    pf_can_process can_rx_int;
    pf_can_process can_tx_int;
    pf_can_process can_busofferr_int;
} tCanIntProc;

typedef enum
{
    CAN_CHN0,
    CAN_CHN1,
    CAN_CHN2,

    CAN_CHN_END,
} TypChnEm;

typedef enum
{
    CAN_BAUD_500K,
    CAN_BAUD_250K,
    CAN_BAUD_1000K,

    CAN_BAUD_END,
} TypBaudEm;

typedef enum
{
    EM_MB0,
    EM_MB1,
    EM_MB2,
    EM_MB3,
    EM_MB4,
    EM_MB5,
    EM_MB6,
    EM_MB7,
    EM_MB8,
    EM_MB9,
    EM_MB10,
    EM_MB11,
    EM_MB12,
    EM_MB13,
    EM_MB14,
    EM_MB15,
    EM_MB16,
    EM_MB17,
    EM_MB18,
    EM_MB19,
    EM_MB20,
    EM_MB21,
    EM_MB22,
    EM_MB23,
    EM_MB24,
    EM_MB25,
    EM_MB26,
    EM_MB27,
    EM_MB28,
    EM_MB29,
    EM_MB30,
    EM_MB31,
} TypCanMBEm;

#define MB_REG_STEP      4u      /* 邮箱长度，以32bit为单位，默认为16字节，FD模式可选其他值 */
#define GET_MB_POS(mb,offset)    ((mb * MB_REG_STEP) + offset)  // 获取MB的位置
#define MB_CTL_POS      0u           /* RAM中控制信息位置 */
#define MB_ID_POS       1u           /* RAM中ID信息位置 */
#define MB_DAT1_POS     2u           /* RAM中DAT1位置 */
#define MB_DAT2_POS     3u           /* RAM中DAT2位置 */

#define MB_CTL_CODE_POS     24u     /* MB RAM CODE段的位置 */
#define MB_CTL_IDE_POS      21u     /* MB RAM CODE段的位置 */
#define MB_CTL_DLC_POS      16u     /* MB RAM DLC段的位置 */

#define IDE_EXTEND	0x01u
#define IDE_STANDARD	0x00u

#define STANDARD_POS	18u

#define CODE_SEND_ACTIVE    	0x0Cu
#define CODE_REC_ACTIVE     	0x04u
#define MB_CTL_CODE_ABORT   	0x09u      /* MB CODE命令：取消本次发送 */
#define MB_CTL_CODE_INACTIVE	0x08u

#define MB_CTL_CODE_MASK    0x0F000000  /* MB CODE 掩码 24bit ~ 27bit */

#define CAN0_MAX_MB     31u
#define CAN1_MAX_MB     15u
#define CAN2_MAX_MB     15u

#define CAN_TX_MB(ch)	((ch > 0u) ? EM_MB15:EM_MB31)

#define CAN_RX_MB_BG	(0u)

#define CAN_MAX_FILTER	16u

typedef enum en_canfd_error
{
    CanFDBusOff = 0, /*!< The CAN-FD module is in busoff state. */
    CanFDWarning = 1 /*!< At least one error counter has reached error warning. */
} en_canfd_error_t;

#define cMaxBaudrateSelNum  4U

//#define cMCUCANCh0 0

#endif /* BSP_CAN_H_ */
