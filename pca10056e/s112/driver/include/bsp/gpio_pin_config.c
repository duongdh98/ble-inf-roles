/**
  **************************************************************************************************
  * @file   gpio_pin_config.c
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

  #include "gpio_pin_config.h"

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

  void pin_init_out(uint32_t pin_id){ // Configure pin output .
    nrf_gpio_cfg_output(pin_id);
  }
  void pin_up(uint32_t pin_id){ // set pin.
    nrf_gpio_pin_set(pin_id);
  }
  
  void pin_down(uint32_t pin_id){ // clear pin.
    nrf_gpio_pin_clear(pin_id);
  }

/* Private function bodies -----------------------------------------------------------------------*/

  // === =END FILE ================================================ //