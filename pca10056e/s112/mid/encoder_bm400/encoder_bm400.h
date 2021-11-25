/**
  **************************************************************************************************
  * @file   encoder_bm400.h
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

// Include file for encoder file
#ifndef  _ENCODER_BM400_H
#define  _ENCODER_BM400_H

#ifdef __cplusplus
extern "C" {
#endif


#include "nrf.h"
#include "bsp.h"
#include "app_pwm.h"
#include "gpio_pin_config.h"
#include "app_error.h"
#include "nrf_delay.h"
#include "nrfx_timer.h"

/* Global configuration. */

/* RTOS. */

/* Middleware. */

/* Public macros ---------------------------------------------------------------------------------*/

/* Public data types -----------------------------------------------------------------------------*/

/* Public function prototypes --------------------------------------------------------------------*/

// Write function for servo
bool encoder_input_signal_change(uint32_t INPUT_ENCODER);

void encoder_use_rtc0();

void read_signal_encoder_400bm(void);

#ifdef __cplusplus
}
#endif

#endif /* _ENCODER_BM400_H */

// ==== END FILE ============================================ //