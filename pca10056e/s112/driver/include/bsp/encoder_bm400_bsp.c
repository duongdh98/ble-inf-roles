/**
  **************************************************************************************************
  * @file   encoder_bm400 _bsp.c
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

#include "nrf_gpio.h"
#include "gpio_pin_config.h"
#include "encoder_bm400_bsp.h"

/* Global configuration. */
/* C standard library. */
/* RTOS. */
/* Application. */
/* Driverware. */
/* MS46SF1 */
// Define function for buttoms.


/* Private macros --------------------------------------------------------------------------------*/

/* Private data types ----------------------------------------------------------------------------*/

/* Private variables -----------------------------------------------------------------------------*/

/* Private function prototypes -------------------------------------------------------------------*/

/* Public function bodies ------------------------------------------------------------------------*/


void input_en_pullup(uint32_t pin_input){ // Configure normal input encoder  pullup
  nrf_gpio_cfg_input(IN_ENCODER, NRF_GPIO_PIN_PULLUP);
}
void input_en_pulldown(uint32_t pin_input){ // Configure normal input encoder pulldown
  nrf_gpio_cfg_input(IN_ENCODER, NRF_GPIO_PIN_PULLDOWN);
}
void input_en_pullnone(uint32_t pin_input){ // // Configure normal input encoder nonepull
  nrf_gpio_cfg_input(IN_ENCODER, NRF_GPIO_PIN_NOPULL);
}

int read_input_en(uint32_t pin_input){ // read input form encoder 

  uint32_t val;
  return  val = nrf_gpio_pin_read(pin_input);
}

/* Private function bodies -----------------------------------------------------------------------*/

// === END FILE ====================================================================================  //