/**
  **************************************************************************************************
  * @file   ht1621_lcd.c
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

#include "ht1621_lcd_bsp.h"
#include "ht1621_lcd.h"
#include "gpio_pin_config.h"
#include "delay.h"

/* Global configuration. */
/* C standard library. */
/* RTOS. */
/* Application. */
/* Midlleware. */
/* MS46SF1 */

/* Private macros --------------------------------------------------------------------------------*/

/* Private data types ----------------------------------------------------------------------------*/

// Hex number
const char num[]={0x7D,0x60,0x3E,0x7A,0x63,0x5B,0x5F,0x70,0x7F,0x7B,0x77,0x4F,0x1D,0x0E};//0x6E,0x1F,0x17,0x67,0x47,0x0D,0x46,0x75,0x37,0x06,0x0F,0x6D,0x02,0x00,
//                    //0      1      2      3        4      5      6       7       8       9
//char dispnum[6]={0x00,0x00,0x00,0x00,0x00,0x00}; 

/* Private variables -----------------------------------------------------------------------------*/

/* Private function prototypes -------------------------------------------------------------------*/

/* Public function bodies ------------------------------------------------------------------------*/


void ht1621_setup(){
    
    pin_init_out(CS); 
    pin_init_out(WR); 
    pin_init_out(DATA); 
    CS1;
    DATA1;
    WR1;
    delay_m_second(50);

    ht1621_init();
    ht1621_all_on(16);
    delay_m_second(1000);
    ht1621_all_off(16);
    delay_m_second(1000);
    
    //ht1621_write(0, num[0]);
    //ht1621_write(2, num[0]);
    //ht1621_write(4, num[0]);
    //ht1621_write(6, num[0]);
    //ht1621_write(8, num[0]);
    //ht1621_write(10, num[0]);
}

// ........................................... //
// @ Configure count number for ht1621

void ht1621_number_0(uint32_t number_sensor){
  
  if( 0 <= number_sensor < 10){

    int j = number_sensor;
    ht1621_write(0, num[j]);
  }
}

void ht1621_number_1(uint32_t number_sensor){
  
  if(10 <= number_sensor < 100){

    uint32_t j = number_sensor/10;
    ht1621_write(2, num[j]);
    ht1621_number_0(number_sensor%10);
  }
}

void ht1621_number_2(uint32_t number_sensor){
  
   if(100 <= number_sensor < 1000){
    
      uint32_t j = number_sensor/100;
      ht1621_write(4, num[j]);
      ht1621_number_1(number_sensor%100);
   }
}
void ht1621_number_3(uint32_t number_sensor){

  if(1000 <= number_sensor < 10000){
    
      uint32_t j = number_sensor/1000;
      ht1621_write(6, num[j]);
      ht1621_number_2(number_sensor%1000);
   }
}
void ht1621_number_4(uint32_t number_sensor){
  
   if(10000 <= number_sensor < 100000){
    
      uint32_t j = number_sensor/10000;
      ht1621_write(8, num[j]);
      ht1621_number_3(number_sensor%10000);
   }
}
void ht1621_number_5(uint32_t number_sensor){

    if(100000 <= number_sensor < 1000000){
    
      uint32_t j = number_sensor/100000;
      if(j>=10){
        j=0;
      }
      ht1621_write(10, num[j]);
      ht1621_number_4(number_sensor%100000);
   }
}

// void show number in lcd led

void ht1621_all_number(uint32_t number_sensor){
    ht1621_number_1(number_sensor);
    ht1621_number_2(number_sensor);
    ht1621_number_3(number_sensor);
    ht1621_number_4(number_sensor);
    ht1621_number_5(number_sensor);
}
// ............................................... //
// show number start in ht1621

void ht1621_start_number(uint32_t number_start){
  
  ht1621_all_number(number_start);
}

void ht1621_show_number(uint32_t number_start){
  
  ht1621_all_number(number_start);
}

/* Private function bodies -----------------------------------------------------------------------*/

/* === END FILE ============================================================================== */