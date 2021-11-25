/**
  **************************************************************************************************
  * @file   ht1621_lcd_bsp.h
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
#include "gpio_pin_config.h"
#include "nrf_delay.h"
#include "nrf_gpio.h"

#ifndef  _HT1621_LED_BSP_H
#define  _HT1621_LED_BSP_H

#ifdef __cplusplus
extern "C" {
#endif

/* Global configuration. */

/* RTOS. */

/* Driverware. */

/* Public macros ---------------------------------------------------------------------------------*/

/* Public data types -----------------------------------------------------------------------------*/

/* Public function prototypes --------------------------------------------------------------------*/

// difine gpio ht1621

#define CS 4  //Pin 12 as chip selection output
#define WR 16  //Pin 16 as read clock  output
#define DATA 12  //Pin 4 as Serial data output
#define HIGH 1
#define LOW 0
#define CS1    nrf_gpio_pin_write(CS, HIGH) 
#define CS0    nrf_gpio_pin_write(CS, LOW)
#define WR1    nrf_gpio_pin_write(WR, HIGH) 
#define WR0    nrf_gpio_pin_write(WR, LOW)
#define DATA1  nrf_gpio_pin_write(DATA, HIGH) 
#define DATA0  nrf_gpio_pin_write(DATA, LOW)

/***************************HT1621***************************************/
#define  COMMODE    0x52  //4COM,1/3bias  1000    010 1001  0  
#define  RCOSC      0x30  //1000 0011 0000 
#define  LCD_ON     0x06  //1000     0000 0 11 0 
#define  LCD_OFF    0x04  
#define  SYS_EN     0x02  //1000   0000 0010 
#define  CTRl_CMD   0x80  
#define  Data_CMD   0xa0

void ht1621_sendbit(uint8_t sdata, uint8_t  cnt);

void ht1621_sendcmd(uint8_t command);

void ht1621_write(uint8_t addr, uint8_t sdata);

void ht1621_all_off(uint8_t num);

void ht1621_all_on(uint8_t num);

void ht1621_init(void);

/* Private function bodies -----------------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif /* _HT1621_LED_BSP_H */
// ================ END FILE ========================================== //