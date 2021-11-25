/**
  **************************************************************************************************
  * @file   buttom_bsp.h
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

// Configure gpio for buttoms.

#include "gpio_pin_config.h"
#include "nrf_gpio.h"

#ifndef _BUTTOM_BSP_H
#define _BUTTOM_BSP_H

#ifdef  __cplusplus
extern "C" {
#endif

/* Global configuration. */

/* RTOS. */

/* Driverware. */

/* Public macros ---------------------------------------------------------------------------------*/

/* Public data types -----------------------------------------------------------------------------*/

/* Public function prototypes --------------------------------------------------------------------*/

// Configure normal signal buttom PULLUP.
void buttom_init_up(uint32_t buttoms);

// Configure normal signal buttom PULLDOWN.
void buttom_init_down(uint32_t buttoms);

// Configure normal signal buttom NOPULL
void buttom_init_none(uint32_t buttoms);

// Configure read values input form gpio.
int read_input_buttom(uint32_t buttoms);

/* Private function bodies -----------------------------------------------------------------------*/

#ifdef cplusplus
extern "C"
}
#endif

#endif /* _BUTTOM_BSP_H */


/* END OF FILE ************************************************************************************/