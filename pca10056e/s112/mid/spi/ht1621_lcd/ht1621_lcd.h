/**
  **************************************************************************************************
  * @file   ht1621_lcd.h
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

#ifndef  HT1621
#define  HT1621

/* Global configuration. */

/* RTOS. */

/* Middleware. */

/* Public macros ---------------------------------------------------------------------------------*/

/* Public data types -----------------------------------------------------------------------------*/

/* Public function prototypes --------------------------------------------------------------------*/

void ht1621_setup();

void ht1621_number_0(uint32_t number_sensor);
void ht1621_number_1(uint32_t number_sensor);
void ht1621_number_2(uint32_t number_sensor);
void ht1621_number_3(uint32_t number_sensor);
void ht1621_number_4(uint32_t number_sensor);
void ht1621_number_5(uint32_t number_sensor);


void ht1621_all_number(uint32_t number_sensor);

void ht1621_start_number(uint32_t number_start);

void ht1621_show_number(uint32_t number_start);

// @ ........................................................ @ //

#endif

/* === END FILE ===============================================  */