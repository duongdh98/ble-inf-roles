/**
  **************************************************************************************************
  * @file   ztrace.h
  * @brief  Trace facilities for all modules.
  * @by     khanhcq | 06-May-2014 | Launch for ZenBee-FWCore.
  *         khanhcq | 22-May-2019 | Modify for ZenLight-FWCore.
  **************************************************************************************************
  *
  * Copyright (C) 2014 Leanwell Technology Co.,Ltd. All rights reserved.
  *
  * All information contained herein is the property of Leanwell Technology Co.,Ltd. The intellectual
  * and technical concepts contained herein are proprietary to Leanwell Technology Co.,Ltd and are
  * protected by trade secret or copyright law. Dissemination of this information or reproduction of
  * this material is strictly forbidden unless prior written permission is obtained from Leanwell
  * Technology Co.,Ltd.
  *
  * This file is part of ZenLight-FWCore.
  **************************************************************************************************
  */

/*  Indent using spaces
    Tab width   : 4 spaces
    Line width  : 100 characters
    Line ending : LF (0x0A) */

#ifndef _ZTRACE_H
#define _ZTRACE_H

/* Middleware. */
//#include "led.h"
//#include "zlog.h"
#include "zcfg.h""

#ifdef __cplusplus
extern "C" {
#endif

/* Public macros ---------------------------------------------------------------------------------*/

#if defined (ZASSERT)
#define ZTRACE_ASSERT(expr)     if ((expr) == 0) { ztrace_assert(); }
#else   /* ZASSERT */
#define ZTRACE_ASSERT(expr)
#endif  /* ZASSERT */

#define ZTRACE_ON       0x80
#define ZTRACE_OFF      0x00

#if defined (ZERROR)
/* If "expr" isn't true, then print "msg" and execute "hdl" expression. */
#define ZTRACE_ERR(dbg, msg, expr, hdl)     do {                                                \
                                                if (!(expr))                                    \
                                                {                                               \
                                                    if ((dbg) & ZTRACE_ON)                      \
                                                    {                                           \
                                                        printf msg;                        \
                                                    }                                           \
                                                    hdl;                                        \
                                                }                                               \
                                            } while (0);
#else   /* ZERROR */
/* If "expr" isn't true, then execute "hdl" expression. */
#define ZTRACE_ERR(dbg, msg, expr, hdl)     do {                                                \
                                                if (!(expr))                                    \
                                                {                                               \
                                                    hdl;                                        \
                                                }                                               \
                                            } while (0);
#endif  /* ZERROR */


#if defined (ZDEBUG)
/* If "dbg" flag is ZTRACE_ON, then print "msg". */
#define ZTRACE_DBG(dbg, msg)    do {                                                            \
                                    if ((dbg) & ZTRACE_ON)                                      \
                                    {                                                           \
                                        printf msg;                                        \
                                    }                                                           \
                                } while (0);

/* If "dbg" flag is ZTRACE_ON, then print "msg", use in isr context. */
#define ZTRACE_DBG_ISR(dbg, msg)    do {                                                        \
                                        if ((dbg) & ZTRACE_ON)                                  \
                                        {                                                       \
                                            printf msg;                                \
                                        }                                                       \
                                    } while (0);
#else   /* ZDEBUG */
#define ZTRACE_DBG(dbg, msg)
#define ZTRACE_DBG_ISR(dbg, msg)
#endif  /* ZDEBUG */

/* Public data types -----------------------------------------------------------------------------*/

/* Public function prototypes --------------------------------------------------------------------*/

/**
  * @brief  Initialize ztrace module.
  * @param  None.
  * @retval zerr_t.
  */
zerr_t
ztrace_open (void);

/**
  * @brief  This function is called by ZTRACE_ASSERT() macro throughout the source files to check
  *         how the application is using FreeRTOS. It is highly recommended to develop FreeRTOS
  *         applications with ZTRACE_ASSERT() defined. An assertion is triggered if the parameter
  *         passed into ZTRACE_ASSERT() is zero. It is normal to define ZTRACE_ASSERT() in such a
  *         way that it will prevent the application from executing any further. This if for
  *         two reasons; stopping the application at the point of the assertion allows the cause of
  *         the assertion to be debugged, and executing past a triggered assertion will probably
  *         result in a crash anyway.
  * @note   Defining ZTRACE_ASSERT() will increase both the application code size and execution
  *         time. When the application is stable the additional overhead can be removed by
  *         simply modify the ZASSERT macro to 0 in zcfg.h.
  * @param  None.
  * @retval None.
  */
void
ztrace_assert (void);

/**
  * @brief  Run time malloc fail checking is performed if ZMALLOC is set to 1 in zcfg.h. This hook
  *         function will get called if a call to pvPortMalloc() fails. pvPortMalloc() is called
  *         internally by the kernel whenever a task, queue, timer or semaphore is created. It is
  *         called by various parts of the demo application. If heap_1.c, heap_2.c or heap_4.c are
  *         used, then the size of the heap available to pvPortMalloc() is defined by
  *         configTOTAL_HEAP_SIZE in FreeRTOSConfig.h, and the xPortGetFreeHeapSize() API function
  *         can be used to query the size of free heap space that remains (although it does not
  *         provide information on how the remaining heap might be fragmented).
  * @param  None.
  * @retval None.
  */
void
vApplicationMallocFailedHook (void);

/**
  * @brief  Run time stack overflow checking is performed if ZSTACK is set to 1 in zcfg.h. This hook
  *         function is called if a stack overflow is detected. Note that these options are only
  *         available on architectures where the memory map is not segmented. Also, some processors
  *         could generate a fault or exception in response to a stack corruption before the RTOS
  *         kernel overflow check can occur.
  *         Stack overflow checking introduces a context switch overhead so its use is only
  *         recommended during the development or testing phases.
  * @param  None.
  * @retval None.
  */
void
vApplicationStackOverflowHook (TaskHandle_t pxTask, char* pcTaskName);

/**
  * @brief  The tick interrupt can optionally call an application defined hook (or callback)
  *         function - the tick hook. The tick hook provides a convenient place to implement timer
  *         functionality. vApplicationTickHook() executes from within an ISR so must be very short,
  *         not use much stack, and not call any API functions that don't end in "FromISR" or
  *         "FROM_ISR".
  * @param  None.
  * @retval None.
  */
void
vApplicationTickHook (void);

#ifdef __cplusplus
}
#endif

#endif /* _ZTRACE_H */

/* END OF FILE ************************************************************************************/
