/**
 * @file os_q.c
 * @brief
 * @version V1.0.0
 * @date 2015-6-8
 * @note
 */

/*****************************************************************************/
/* Include files                                                             */
/*****************************************************************************/
#include "LIB_QUEUE.h"
/*****************************************************************************/
/* Private pre-processor symbols/macros ('#define')                          */
/*****************************************************************************/

/*****************************************************************************/
/* Private type definitions ('typedef')                                      */
/*****************************************************************************/

/*****************************************************************************/
/* Global constant definitions                                               */
/*****************************************************************************/

/*****************************************************************************/
/* Private constant definitions ('static')                                   */
/*****************************************************************************/

/*****************************************************************************/
/* Global variable definitions                                               */
/*****************************************************************************/


/*****************************************************************************/
/* Private variable definitions ('static')                                   */
/*****************************************************************************/

/*****************************************************************************/
/* Private function prototypes ('static', comment on the definitions)        */
/*****************************************************************************/

/*进入临界区*/
static void OS_ENTER_CRITICAL(void)
{
	TOSSuspendOSInterrupts();
}

/*退出临界区*/
static void OS_EXIT_CRITICAL(void)
{
	TOSResumeOSInterrupts();
}

/*****************************************************************************/
/* Global function definitions                                               */
/*****************************************************************************/

/*****************************************************************************/
/* OSQCreate function                                                            */
/*****************************************************************************/
/*
*********************************************************************************************************
*                                        CREATE A MESSAGE QUEUE
*
* Description: This function creates a message queue if free event control blocks are available.
*
* Arguments  : start         is a pointer to the base address of the message queue storage area.  The
*                            storage area MUST be declared as an array of pointers to 'void' as follows
*
*                            void *MessageStorage[size]
*
*              size          is the number of elements in the storage area
*
* Returns    : != (OS_Q *)0  is a pointer to the event control clock (OS_Q) associated with the
*                                created queue
*              == (OS_Q *)0  if no event control blocks were available or an error was detected
*********************************************************************************************************
*/
void  OSQCreate (OS_Q      *pq,
                  void    **start,
                  U16    size)
{

 #if (OS_CRITICAL_METHOD == 3u)                     /* Allocate storage for CPU status register           */
     OS_CPU_SR  cpu_sr = 0u;
 #endif

    OS_ENTER_CRITICAL();
    pq->OSQStart           = start;
    pq->OSQEnd             = &start[size];
    pq->OSQIn              = start;
    pq->OSQOut             = start;
    pq->OSQSize            = size;
    pq->OSQEntries         = 0x0000u;
    OS_EXIT_CRITICAL();

}
/*
*********************************************************************************************************
*                                      ACCEPT MESSAGE FROM QUEUE
*
* Description: This function checks the queue to see if a message is available.  Unlike OSQPend(),
*              OSQAccept() does not suspend the calling task if a message is not available.
*
* Arguments  : pevent        is a pointer to the event control block
*
*              perr          is a pointer to where an error message will be deposited.  Possible error
*                            messages are:
*
*                            OS_ERR_NONE         The call was successful and your task received a
*                                                message.
*                            OS_ERR_EVENT_TYPE   You didn't pass a pointer to a queue
*                            OS_ERR_PEVENT_NULL  If 'pevent' is a NULL pointer
*                            OS_ERR_Q_EMPTY      The queue did not contain any messages
*
* Returns    : != (void *)0  is the message in the queue if one is available.  The message is removed
*                            from the so the next time OSQAccept() is called, the queue will contain
*                            one less entry.
*              == (void *)0  if you received a NULL pointer message
*                            if the queue is empty or,
*                            if 'pevent' is a NULL pointer or,
*                            if you passed an invalid event type
*
* Note(s)    : As of V2.60, you can now pass NULL pointers through queues.  Because of this, the argument
*              'perr' has been added to the API to tell you about the outcome of the call.
*********************************************************************************************************
*/
#if OS_Q_ACCEPT_EN > 0u
void  *OSQAccept (OS_Q   *pq,
                  U8     *perr)
{
    void *pmsg;
#if (OS_CRITICAL_METHOD == 3u)                   /* Allocate storage for CPU status register           */
    OS_CPU_SR  cpu_sr = 0u;
#endif

    OS_ENTER_CRITICAL();
    if (pq->OSQEntries > 0u)                    /* See if any messages in the queue                   */
    {
        pmsg = *pq->OSQOut++;                    /* Yes, extract oldest message from the queue         */
        //这个值表示当前队列中没有处理的消息的个数
        //这里怎么得到其消息长度呢？
        pq->OSQEntries--;                        /* Update the number of entries in the queue          */
        if (pq->OSQOut == pq->OSQEnd)          /* Wrap OUT pointer if we are at the end of the queue */
        {
            pq->OSQOut = pq->OSQStart;
        }
        *perr = OS_ERR_NONE;
    }
    else
    {
        *perr = OS_ERR_Q_EMPTY;
        pmsg  = (void *)0;                       /* Queue is empty                                     */
    }
    OS_EXIT_CRITICAL();
    return (pmsg);                               /* Return message received (or NULL)                  */
}
#endif
/*
*********************************************************************************************************
*                                             FLUSH QUEUE
*
* Description : This function is used to flush the contents of the message queue.
*
* Arguments   : none
*
* Returns     : OS_ERR_NONE         upon success
*               OS_ERR_EVENT_TYPE   If you didn't pass a pointer to a queue
*               OS_ERR_PEVENT_NULL  If 'pevent' is a NULL pointer
*
* WARNING     : You should use this function with great care because, when to flush the queue, you LOOSE
*               the references to what the queue entries are pointing to and thus, you could cause
*               'memory leaks'.  In other words, the data you are pointing to that's being referenced
*               by the queue entries should, most likely, need to be de-allocated (i.e. freed).
*********************************************************************************************************
*/

#if OS_Q_FLUSH_EN > 0u
U8  OSQFlush (OS_Q      *pq)
{

#if (OS_CRITICAL_METHOD == 3u)                        /* Allocate storage for CPU status register      */
    OS_CPU_SR  cpu_sr = 0u;
#endif

    OS_ENTER_CRITICAL();
    pq->OSQIn      = pq->OSQStart;
    pq->OSQOut     = pq->OSQStart;
    pq->OSQEntries = 0u;
    OS_EXIT_CRITICAL();
    return (OS_ERR_NONE);
}
#endif
/*
*********************************************************************************************************
*                                        POST MESSAGE TO A QUEUE
*
* Description: This function sends a message to a queue
*
* Arguments  : pevent        is a pointer to the event control block associated with the desired queue
*
*              pmsg          is a pointer to the message to send.
*
* Returns    : OS_ERR_NONE           The call was successful and the message was sent
*              OS_ERR_Q_FULL         If the queue cannot accept any more messages because it is full.
*              OS_ERR_EVENT_TYPE     If you didn't pass a pointer to a queue.
*              OS_ERR_PEVENT_NULL    If 'pevent' is a NULL pointer
*
* Note(s)    : As of V2.60, this function allows you to send NULL pointer messages.
* 向消息队列发送一则消息(FIFO)
*********************************************************************************************************
*/

#if OS_Q_POST_EN > 0u
U8  OSQPost (OS_Q      *pq,
             void      *pmsg)
{

#if OS_CRITICAL_METHOD == 3u                           /* Allocate storage for CPU status register     */
    OS_CPU_SR  cpu_sr = 0u;
#endif

    OS_ENTER_CRITICAL();
    if (pq->OSQEntries >= pq->OSQSize)                /* Make sure queue is not full                  */
    {
        OS_EXIT_CRITICAL();
        return (OS_ERR_Q_FULL);
    }
    *pq->OSQIn++ = pmsg;                               /* Insert message into queue                    */
    pq->OSQEntries++;                                  /* Update the nbr of entries in the queue       */
    if (pq->OSQIn == pq->OSQEnd) {                     /* Wrap IN ptr if we are at end of queue        */
        pq->OSQIn = pq->OSQStart;
    }
    OS_EXIT_CRITICAL();
    return (OS_ERR_NONE);
}
#endif
/*
*********************************************************************************************************
*                                   POST MESSAGE TO THE FRONT OF A QUEUE
*
* Description: This function sends a message to a queue but unlike OSQPost(), the message is posted at
*              the front instead of the end of the queue.  Using OSQPostFront() allows you to send
*              'priority' messages.
*
* Arguments  : pevent        is a pointer to the event control block associated with the desired queue
*
*              pmsg          is a pointer to the message to send.
*
* Returns    : OS_ERR_NONE           The call was successful and the message was sent
*              OS_ERR_Q_FULL         If the queue cannot accept any more messages because it is full.
*              OS_ERR_EVENT_TYPE     If you didn't pass a pointer to a queue.
*              OS_ERR_PEVENT_NULL    If 'pevent' is a NULL pointer
*
* Note(s)    : As of V2.60, this function allows you to send NULL pointer messages.
* 发送消息 以LIFO后进先出的方式发送
*********************************************************************************************************
*/

#if OS_Q_POST_FRONT_EN > 0u
U8  OSQPostFront (OS_Q      *pq,
                  void      *pmsg)
{

#if OS_CRITICAL_METHOD == 3u                          /* Allocate storage for CPU status register      */
    OS_CPU_SR  cpu_sr = 0u;
#endif


    OS_ENTER_CRITICAL();
    if (pq->OSQEntries >= pq->OSQSize)               /* Make sure queue is not full                   */
    {
        OS_EXIT_CRITICAL();
        return (OS_ERR_Q_FULL);
    }
    if (pq->OSQOut == pq->OSQStart)                  /* Wrap OUT ptr if we are at the 1st queue entry */
    {
        pq->OSQOut = pq->OSQEnd;
    }
    pq->OSQOut--;
    *pq->OSQOut = pmsg;                               /* Insert message into queue                     */
    pq->OSQEntries++;                                 /* Update the nbr of entries in the queue        */
    OS_EXIT_CRITICAL();
    return (OS_ERR_NONE);
}
#endif
/**
 * Get_OSQ_Entries
 * @param pq
 * @return
 */
U16  Get_OSQ_Entries (OS_Q *pq)
{
    U16 ret;
#if (OS_CRITICAL_METHOD == 3u)                         /* Allocate storage for CPU status register      */
    OS_CPU_SR  cpu_sr = 0u;
#endif
    OS_ENTER_CRITICAL();
    ret = pq->OSQEntries;
    OS_EXIT_CRITICAL();

    return (ret);
}
/*****************************************************************************/
/* Private function definitions ('static')                                   */
/*****************************************************************************/
