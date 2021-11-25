/**
  **************************************************************************************************
  * @file   ht1621_lcd_bsp.c
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
  #include "ht1621_lcd_bsp.h"

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

  void ht1621_sendbit(uint8_t sdata, uint8_t cnt){
  
  for(uint8_t i = 0; i < cnt; i++ ){
    WR0;
    if(sdata&0x80) DATA1;
    else DATA0;
    WR1;
    sdata <<= 1;
  }
}

// ................................................. //

// send command
void ht1621_sendcmd(uint8_t command){
  CS0;
  ht1621_sendbit(0x80, 4);
  ht1621_sendbit(command, 8);
  CS1;
}
// ............................................... //

void ht1621_write(uint8_t addr, uint8_t sdata){
  
  addr <<= 2;
  CS0;
  ht1621_sendbit(0xa0, 3);
  ht1621_sendbit(addr, 6);
  ht1621_sendbit(sdata, 8);
  CS1;
}
//................................................... //

void ht1621_all_off(uint8_t num){
  
  uint8_t addr = 0;

  for(uint8_t i = 0; i < num; i++){
    ht1621_write(addr, 0x00);
    addr += 2;
  }
}
// .................................................. //

void ht1621_all_on(uint8_t num){
  
  uint8_t addr = 0;

  for(uint8_t i = 0; i < num; i++){
    ht1621_write(addr, 0xff);
    addr += 2;
  }
}

// .............................................. //

void ht1621_init(void){
  
  ht1621_sendcmd(SYS_EN);
  ht1621_sendcmd(RCOSC);
  ht1621_sendcmd(COMMODE);
  ht1621_sendcmd(LCD_ON);
}

/* Private function bodies -----------------------------------------------------------------------*/

/* ===== END FILE ================================================================================ */