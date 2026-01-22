/**
 * @file BSP_RES_SMC.h
 * @brief
 * @version V1.0.0
 * @date 2016Äê1ÔÂ13ÈÕ
 * @note
 */

#ifndef SOURCE_BSP_BSP_COMMON_BSP_RES_SMC_H_
#define SOURCE_BSP_BSP_COMMON_BSP_RES_SMC_H_

/*****************************************************************************/
/* Include files (NOT RECOMMENDED, if needed SHOULD be out of "extern C" )   */
/*****************************************************************************/

#ifdef __cplusplus
extern "C"
{
#endif

/*****************************************************************************/
/* Global pre-processor symbols/macros ('#define')                           */
/*****************************************************************************/
//#define cCfgMotor

#ifdef cCfgMotor
    //  STEP MOTOR (SMC0/SMC100)
    #define CLUSTER_SMC0_SMC1P_PORT        2
    #define CLUSTER_SMC0_SMC1M_PORT        2
    #define CLUSTER_SMC0_SMC2P_PORT        2
    #define CLUSTER_SMC0_SMC2M_PORT        3

    #define CLUSTER_SMC0_SMC1P_PIN         29
    #define CLUSTER_SMC0_SMC1M_PIN         30
    #define CLUSTER_SMC0_SMC2P_PIN         31
    #define CLUSTER_SMC0_SMC2M_PIN         0

    //  STEP MOTOR (SMC1/SMC101)
    #define CLUSTER_SMC1_SMC1P_PORT         3
    #define CLUSTER_SMC1_SMC1M_PORT         3
    #define CLUSTER_SMC1_SMC2P_PORT         3
    #define CLUSTER_SMC1_SMC2M_PORT         3

    #define CLUSTER_SMC1_SMC1P_PIN          1
    #define CLUSTER_SMC1_SMC1M_PIN          2
    #define CLUSTER_SMC1_SMC2P_PIN          4
    #define CLUSTER_SMC1_SMC2M_PIN          5

    //  STEP MOTOR (SMC2/SMC102)
    #define CLUSTER_SMC2_SMC1P_PORT         3
    #define CLUSTER_SMC2_SMC1M_PORT         3
    #define CLUSTER_SMC2_SMC2P_PORT         3
    #define CLUSTER_SMC2_SMC2M_PORT         3

    #define CLUSTER_SMC2_SMC1P_PIN          7
    #define CLUSTER_SMC2_SMC1M_PIN          8
    #define CLUSTER_SMC2_SMC2P_PIN          9
    #define CLUSTER_SMC2_SMC2M_PIN          12

    //  STEP MOTOR (SMC3/SMC103)
    #define CLUSTER_SMC3_SMC1P_PORT         3
    #define CLUSTER_SMC3_SMC1M_PORT         3
    #define CLUSTER_SMC3_SMC2P_PORT         3
    #define CLUSTER_SMC3_SMC2M_PORT         3

    #define CLUSTER_SMC3_SMC1P_PIN          13
    #define CLUSTER_SMC3_SMC1M_PIN          14
    #define CLUSTER_SMC3_SMC2P_PIN          15
    #define CLUSTER_SMC3_SMC2M_PIN          17

    #define SMC00       MAKE_PORTPINCFG(CLUSTER_SMC0_SMC1P_PORT, CLUSTER_SMC0_SMC1P_PIN, PortOutputResourceG, PortOutputDriveC, PortInputLevelCmosA)
    #define SMC01       MAKE_PORTPINCFG(CLUSTER_SMC0_SMC1M_PORT, CLUSTER_SMC0_SMC1M_PIN, PortOutputResourceG, PortOutputDriveC, PortInputLevelCmosA)
    #define SMC02       MAKE_PORTPINCFG(CLUSTER_SMC0_SMC2P_PORT, CLUSTER_SMC0_SMC2P_PIN, PortOutputResourceG, PortOutputDriveC, PortInputLevelCmosA)
    #define SMC03       MAKE_PORTPINCFG(CLUSTER_SMC0_SMC2M_PORT, CLUSTER_SMC0_SMC2M_PIN, PortOutputResourceG, PortOutputDriveC, PortInputLevelCmosA)

    #define SMC10       MAKE_PORTPINCFG(CLUSTER_SMC1_SMC1P_PORT, CLUSTER_SMC1_SMC1P_PIN, PortOutputResourceG, PortOutputDriveC, PortInputLevelCmosA)
    #define SMC11       MAKE_PORTPINCFG(CLUSTER_SMC1_SMC1M_PORT, CLUSTER_SMC1_SMC1M_PIN, PortOutputResourceG, PortOutputDriveC, PortInputLevelCmosA)
    #define SMC12       MAKE_PORTPINCFG(CLUSTER_SMC1_SMC2P_PORT, CLUSTER_SMC1_SMC2P_PIN, PortOutputResourceG, PortOutputDriveC, PortInputLevelCmosA)
    #define SMC13       MAKE_PORTPINCFG(CLUSTER_SMC1_SMC2M_PORT, CLUSTER_SMC1_SMC2M_PIN, PortOutputResourceG, PortOutputDriveC, PortInputLevelCmosA)

    #define SMC20       MAKE_PORTPINCFG(CLUSTER_SMC2_SMC1P_PORT, CLUSTER_SMC2_SMC1P_PIN, PortOutputResourceG, PortOutputDriveC, PortInputLevelCmosA)
    #define SMC21       MAKE_PORTPINCFG(CLUSTER_SMC2_SMC1M_PORT, CLUSTER_SMC2_SMC1M_PIN, PortOutputResourceG, PortOutputDriveC, PortInputLevelCmosA)
    #define SMC22       MAKE_PORTPINCFG(CLUSTER_SMC2_SMC2P_PORT, CLUSTER_SMC2_SMC2P_PIN, PortOutputResourceG, PortOutputDriveC, PortInputLevelCmosA)
    #define SMC23       MAKE_PORTPINCFG(CLUSTER_SMC2_SMC2M_PORT, CLUSTER_SMC2_SMC2M_PIN, PortOutputResourceG, PortOutputDriveC, PortInputLevelCmosA)

    #define SMC30       MAKE_PORTPINCFG(CLUSTER_SMC3_SMC1P_PORT, CLUSTER_SMC3_SMC1P_PIN, PortOutputResourceG, PortOutputDriveC, PortInputLevelCmosA)
    #define SMC31       MAKE_PORTPINCFG(CLUSTER_SMC3_SMC1M_PORT, CLUSTER_SMC3_SMC1M_PIN, PortOutputResourceG, PortOutputDriveC, PortInputLevelCmosA)
    #define SMC32       MAKE_PORTPINCFG(CLUSTER_SMC3_SMC2P_PORT, CLUSTER_SMC3_SMC2P_PIN, PortOutputResourceG, PortOutputDriveC, PortInputLevelCmosA)
    #define SMC33       MAKE_PORTPINCFG(CLUSTER_SMC3_SMC2M_PORT, CLUSTER_SMC3_SMC2M_PIN, PortOutputResourceG, PortOutputDriveC, PortInputLevelCmosA)
#endif




/*****************************************************************************/
/* Global type definitions ('typedef')                                       */
/*****************************************************************************/

/*****************************************************************************/
/* Global constant declarations ('extern', definition & comment in C source) */
/*****************************************************************************/

/*****************************************************************************/
/* Global variable declarations ('extern', definition & comment in C source) */
/*****************************************************************************/

/*****************************************************************************/
/* Global function prototypes ('extern', definition & comment in C source)   */
/*****************************************************************************/

#ifdef __cplusplus
}
#endif
#endif /* SOURCE_BSP_BSP_COMMON_BSP_RES_SMC_H_ */
