/**
  **************************************************************************************************
  * @file   buttom_bsp.c
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

/* Global configuration. */
/* C standard library. */
/* RTOS. */
/* Application. */
/* Driverware. */
/* MS46SF1 */

/* Private macros --------------------------------------------------------------------------------*/

/* Private data types ----------------------------------------------------------------------------*/

/* Private variables -----------------------------------------------------------------------------*/

/* Private function prototypes -------------------------------------------------------------------*/

/* Public function bodies ------------------------------------------------------------------------*/

//  Configure normal signal buttom PULLUP.

void buttom_init_up(uint32_t buttoms){
  nrf_gpio_cfg_input(buttoms, NRF_GPIO_PIN_PULLUP);
}

// Configure normal signal buttom PULLDOWN.

void buttom_init_down(uint32_t buttoms){
  nrf_gpio_cfg_input(buttoms, NRF_GPIO_PIN_PULLDOWN);
}

// Configure normal signal buttom NOPULL

void buttom_init_none(uint32_t buttoms){
  nrf_gpio_cfg_input(buttoms, NRF_GPIO_PIN_NOPULL);
}

// Configure read values input form gpio.

int read_input_buttom(uint32_t buttoms){
  int val;
  return  val = nrf_gpio_pin_read(buttoms);
}

/* Private function bodies -----------------------------------------------------------------------*/


/* END OF FILE ************************************************************************************/