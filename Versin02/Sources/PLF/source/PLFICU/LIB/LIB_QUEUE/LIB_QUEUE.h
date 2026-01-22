/**
 * @file os_queue.h
 * @brief
 * @version V1.0.0
 * @date 2015-6-8
 * @note
 */

#ifndef OS_Q_H_
#define OS_Q_H_

/*****************************************************************************/
/* Include files (NOT RECOMMENDED, if needed SHOULD be out of "extern C" )   */
/*****************************************************************************/
#ifdef cHeadIncludeType_Directly
#include "deftypes.h"
#else
#include ".\..\LIB_API\deftypes.h"
#endif

#ifdef __cplusplus
extern "C"
{
#endif

/*****************************************************************************/
/* Global pre-processor symbols/macros ('#define')                           */
/*****************************************************************************/
/*#define  OS_CRITICAL_METHOD     3u               //½øÈëÁÙ½ç¶Î                                                          */
#define OS_Q_EN                   1u   /* Enable (1) or Disable (0) code generation for QUEUES   */
#define OS_Q_ACCEPT_EN            1u   /*     Include code for OSQAccept()                       */
#define OS_Q_FLUSH_EN             1u   /*     Include code for OSQFlush()                        */
#define OS_Q_POST_EN              1u   /*     Include code for OSQPost()                         */
#define OS_Q_POST_FRONT_EN        1u   /*     Include code for OSQPostFront()                    */

#define OS_ERR_NONE                0u
#define OS_ERR_Q_FULL              1u
#define OS_ERR_Q_EMPTY             2u
/*****************************************************************************/
/* Global type definitions ('typedef')                                       */
/*****************************************************************************/
typedef struct os_q
{                       /* QUEUE CONTROL BLOCK                                         */
    void **OSQStart;    /* Pointer to start of queue data                              */
    void **OSQEnd;      /* Pointer to end   of queue data                              */
    void **OSQIn;       /* Pointer to where next message will be inserted  in   the Q  */
    void **OSQOut;      /* Pointer to where next message will be extracted from the Q  */
    U16 OSQSize;        /* Size of queue (maximum number of entries)                   */
    U16 OSQEntries;     /* Current number of entries in the queue                      */
} OS_Q;
/*****************************************************************************/
/* Global constant declarations ('extern', definition & comment in C source) */
/*****************************************************************************/

/*****************************************************************************/
/* Global variable declarations ('extern', definition & comment in C source) */
/*****************************************************************************/
extern  OS_Q  *Str_Q;
/*****************************************************************************/
/* Global function prototypes ('extern', definition & comment in C source)   */
/*****************************************************************************/

extern void       TOSSuspendOSInterrupts(void);
extern void       TOSResumeOSInterrupts(void);

#if (OS_Q_EN > 0u)

void OSQCreate(OS_Q *pq, void **start, U16 size);

#if (OS_Q_ACCEPT_EN > 0u)
void *OSQAccept(OS_Q *pq, U8 *perr);
#endif

#if (OS_Q_FLUSH_EN > 0u)
U8 OSQFlush(OS_Q *pq);
#endif

#if (OS_Q_POST_EN > 0u)
U8 OSQPost(OS_Q *pq, void *pmsg);
#endif

#if (OS_Q_POST_FRONT_EN > 0u)
U8 OSQPostFront(OS_Q *pq, void *pmsg);
#endif

U16 Get_OSQ_Entries(OS_Q *pq);

#endif
#ifdef __cplusplus
}
#endif
#endif /* OS_Q_H_ */
