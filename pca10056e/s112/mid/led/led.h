/**
  **************************************************************************************************
  * @file   led.h
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
#include "buttom_bsp.h"

#include "gpio_pin_config.h"

/* Global configuration. */

/* RTOS. */

/* Middleware. */

/* Public macros ---------------------------------------------------------------------------------*/

/* Public data types -----------------------------------------------------------------------------*/

/* Public function prototypes --------------------------------------------------------------------*/


void turn_on(uint32_t pin_id); // turn on led.

void turn_off(uint32_t pin_id); // turn off led.

void led_together(uint32_t led_id, int time_delay); // funtion together led

// @ ........................................................... @ //
