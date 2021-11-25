/**
  **************************************************************************************************
  * @file   gpio_pin_configure.h
  * @brief  function of file.
  * @by     duongdh | 1-dec-2020 | Launch for CouterSensor-FWCore.
  **************************************************************************************************
  *
  * Copyright (C) 2020 Leanwell Technology Co.,Ltd. All rights reserved.
  *
  * All information contained herein is the property of Leanwell Technology Co.,Ltd. The intellectual
  * and technical concepts contained herein are proprietary to Leanwell Technology Co.,Ltd and are
  * protected by trade secret or copyright law. Dissemination of this information or reproduction of
  * this material is strictly forbidden unless prior written permission is obtained from Leanwell
  * Technology Co.,Ltd.
  *
  * This file is part of CouterSensor-FWCore.
  **************************************************************************************************
  */

/*  Indent using spaces
    Tab width   : 4 spaces
    Line width  : 100 characters
    Line ending : LF (0x0A) */

/* Includes --------------------------------------------------------------------------------------*/

#include <stdint.h>
#include <stdbool.h>
#include "nrf_gpio.h"

/* Global configuration. */
/* C standard library. */
/* RTOS. */
/* Application. */
/* Driverware. */
/* MS46SF1 */

// Configure GPIO pin for ms46fs11

#ifndef GPIO_1
#define GPIO_1          NRF_GPIO_PIN_MAP(0,12)
#endif

#ifndef GPIO_2
#define GPIO_2          NRF_GPIO_PIN_MAP(0,16)
#endif

#ifndef GPIO_3
#define GPIO_3          NRF_GPIO_PIN_MAP(0,04)
#endif

#ifndef GPIO_4
#define GPIO_4          NRF_GPIO_PIN_MAP(0,05)
#endif

#ifndef GPIO_5
#define GPIO_5          NRF_GPIO_PIN_MAP(0,18)
#endif

#ifndef GPIO_6
#define GPIO_6          NRF_GPIO_PIN_MAP(0,21)
#endif

// @ ............................................................ @ //

#ifndef SPI0_MOSI_PIN         // SPI Master Out Slave In GPIO pin number
#define SPI0_MOSI_PIN GPIO_1
#endif

#ifndef SPI0_SCK_PIN          // SPI clock GPIO pin number.
#define SPI0_SCK_PIN  GPIO_2
#endif

#ifndef SPI0_SS_PIN           // SPI Slave Select GPIO pin number
#define SPI0_SS_PIN   GPIO_3
#endif

#ifndef SPI_IRQ_PRIORITY
#define SPI_IRQ_PRIORITY 6
#endif

// @ ............................................................ @ //

// Configure for sn04p

#ifndef   INPUT_SN04_P
#define   INPUT_SN04_P GPIO_4
#endif

// Configure for ht1621

#ifndef   INPUT_SENSOR
#define   INPUT_SENSOR GPIO_4
#endif

// Configure reset buttom

#ifndef  RESET_BUTTOM 
#define  RESET_BUTTOM GPIO_6
#endif 

// Configure for Encoder

#ifndef  IN_ENCODER
#define  IN_ENCODER GPIO_6
#endif

// Configure for 

#ifndef  INF_SENSOR_START
#define  INF_SENSOR_START GPIO_2
#endif

#ifndef  INF_SENSOR_STOP
#define  INF_SENSOR_STOP GPIO_3
#endif

// Configure GPIO for LED Notification for input up of sensor
#ifndef LED_NOTIFICATION
#define LED_NOTIFICATION GPIO_5
#endif

/* Global configuration. */

/* RTOS. */

/* Middleware. */

/* Public macros ---------------------------------------------------------------------------------*/

/* Public data types -----------------------------------------------------------------------------*/

/* Public function prototypes --------------------------------------------------------------------*/

void pin_init_out(uint32_t pin_id);

void pin_up(uint32_t pin_id);

void pin_down(uint32_t pin_id);

/* ======= END FILE ==============================================================================*/
