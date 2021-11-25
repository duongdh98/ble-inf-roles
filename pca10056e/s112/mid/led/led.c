/**
  **************************************************************************************************
  * @file   led.c
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

#include "led.h"
#include "delay.h"
#include "led_bsp.h"

/* Global configuration. */
/* C standard library. */
/* RTOS. */
/* Application. */
/* Midlleware. */
/* MS46SF1 */

/* Private macros --------------------------------------------------------------------------------*/

/* Private data types ----------------------------------------------------------------------------*/

/* Private variables -----------------------------------------------------------------------------*/

/* Private function prototypes -------------------------------------------------------------------*/

/* Public function bodies ------------------------------------------------------------------------*/

void turn_on(uint32_t pin_id){ // turn on led.
    led_init(pin_id);
    led_up(pin_id);
}

void turn_off(uint32_t pin_id){ // turn off led.
  led_init(pin_id);
  led_down(pin_id);
}

void led_together(uint32_t led_id, int time_delay) // funtion together led
{
  turn_on(led_id);
  delay_m_second(time_delay);
  turn_off(led_id);
  delay_m_second(time_delay);
}

/* Private function bodies -----------------------------------------------------------------------*/

// === END FILE ==================================================================================== //