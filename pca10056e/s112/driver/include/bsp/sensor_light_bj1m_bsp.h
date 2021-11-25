/**
  **************************************************************************************************
  * @file   sensor_light_bj1m_bsp.h
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

/* RTOS. */

/* Driverware. */

/* Public macros ---------------------------------------------------------------------------------*/

/* Public data types -----------------------------------------------------------------------------*/

/* Public function prototypes --------------------------------------------------------------------*/

void sensor_init_up(uint32_t PIN_INPUT); // configure  gpio input for out put digital sensor if normal signal of sensor is high

void sensor_init_down(uint32_t PIN_INPUT); // configure  gpio input for out put digital sensor if normal signal of sensor is low

int read_in_sensor(uint32_t PIN_INPUT);


// END FILE. ============================================================== //
