/**
  **************************************************************************************************
  * @file   ztrace.c
  * @brief  Global trace handling.
  * @by     khanhcq | 07-March-2017 | Launch for ZenBee-Boot.
  *         khanhcq | 21-May-2019 | Modify for ZenLight-FWCore.
  **************************************************************************************************
  *
  * Copyright (C) 2017 Leanwell Technology Co.,Ltd. All rights reserved.
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

/* Includes --------------------------------------------------------------------------------------*/

/* Global configuration. */
#include "zcfg.h"

/* Private macros --------------------------------------------------------------------------------*/

/* Private data types ----------------------------------------------------------------------------*/

/* Private variables -----------------------------------------------------------------------------*/

/* Private function prototypes -------------------------------------------------------------------*/

/* Public function bodies ------------------------------------------------------------------------*/

/**
  * @brief  Initialize ztrace module.
  * @param  None.
  * @retval zerr_t.
  */
zerr_t
ztrace_open (void)
{
    return zlog_open();
}

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
  *         simply modify the ZASSERT macro to 0 value in zcfg.h.
  * @param  None.
  * @retval None.
  */
void
ztrace_assert (void)
{
//    volatile uint32_t b_loop = 1;

//    taskDISABLE_INTERRUPTS();
//    led_on(LED_HEARTBEAT);
//    led_on(LED_ERROR);
    
//    //rester device
//    HAL_NVIC_SystemReset();
////    while (1 == b_loop)
////    {
////        /* Set the b_loop variable to a zero value in the debugger to step out of this function to
////        the point that caused the assertion. */
////    }
}

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
vApplicationMallocFailedHook (void)
{
//    taskDISABLE_INTERRUPTS();
//    led_on(LED_HEARTBEAT);
//    led_on(LED_ERROR);
//    //rester device
//    HAL_NVIC_SystemReset();
////    for (;;);
}

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
vApplicationStackOverflowHook (TaskHandle_t pxTask, char* pcTaskName)
{
//    (void) pcTaskName;  /* Make compiler happy. */
//    (void) pxTask;

//    taskDISABLE_INTERRUPTS();
//    led_on(LED_HEARTBEAT);
//    led_on(LED_ERROR);
//    //rester device
//    HAL_NVIC_SystemReset();
////    for (;;);
}

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
vApplicationTickHook (void)
{
    ZTRACE_DBG(TR_ZAPP, ("%s: TICK\n",__FUNCTION__));
    //static uint32_t num_tick = 0u;
    //static uint32_t b_on = 0u;
    //uint32_t num_ms = 0u;

    //num_ms = (++num_tick) * portTICK_PERIOD_MS; /* Convert tick(s) to millisecond(s). */
    //if (b_on)
    //{
    //    if (num_ms >= 100u)
    //    {
    //        led_off(LED_HEARTBEAT);
    //        num_tick = 0u; /* Reset for the next run. */
    //        b_on = 0;
    //    }
    //}
    //else /* Off */
    //{
    //    if (num_ms >= 1500u)
    //    {
    //        led_on(LED_HEARTBEAT);
    //        num_tick = 0u; /* Reset for the next run. */
    //        b_on = 1;
    //    }
    //}
}

/**
  * @brief  vApplicationIdleHook() will only be called if configUSE_IDLE_HOOK is set to 1 in
  *         FreeRTOSConfig.h.  It will be called on each iteration of the idle task. It is essential
  *         that code added to this hook function never attempts to block in any way (for example,
  *         call xQueueReceive() with a block time specified, or call vTaskDelay()). If the
  *         application makes use of the vTaskDelete() API function then it is also important that
  *         vApplicationIdleHook() is permitted to return to its calling function, because it is the
  *         responsibility of the idle task to clean up memory allocated by the kernel to any task
  *         that has since been deleted.
  * @param  None.
  * @retval None.
  */
void
vApplicationIdleHook (void)
{
}

/* Private function bodies -----------------------------------------------------------------------*/

/* END OF FILE ************************************************************************************/
