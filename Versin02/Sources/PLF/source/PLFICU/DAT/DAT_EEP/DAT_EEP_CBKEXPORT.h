/**
 * @file DAT_EEP_CBKEXPORT.h
 * @brief
 * @version V1.0.0
 * @date 2015Äê11ÔÂ12ÈÕ
 * @note
 */

#ifndef SOURCE_PLFICU_DAT_DAT_EEP_DAT_EEP_CBKEXPORT_H_
#define SOURCE_PLFICU_DAT_DAT_EEP_DAT_EEP_CBKEXPORT_H_

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
#define mLDBEEPCallBackRxWithAddr(Address, Status)  DATEepCallBackRxWithAddr(Address, Status)
#define mLDBEEPCallBackTxWithAddr(Address, Status)  DATEepCallBackTxWithAddr(Address, Status)
#define mLDBEEPCallBackEndControl(Ctrl, Status)     DATEepCallBackEndCtrl(Ctrl, Status)

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
extern void DATEepCallBackRxWithAddr(tAddress Unused, tStatus Status);
extern void DATEepCallBackTxWithAddr(tAddress Unused, tStatus Status);
extern void DATEepCallBackEndCtrl(tCtrl Ctrl, tStatus Statut);

#ifdef __cplusplus
}
#endif
#endif /* SOURCE_PLFICU_DAT_DAT_EEP_DAT_EEP_CBKEXPORT_H_ */
