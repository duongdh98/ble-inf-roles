/**
  **************************************************************************************************
  * @file   encoder_bm400.c
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

#include "encoder_bm400_bsp.h"
#include "encoder_bm400.h"
#include "ht1621_lcd.h"
#include "nrfx_timer.h"

#include "led_bsp.h"
#include "led.h"
#include "gpio_pin_config.h"
#include "nrf_drv_timer.h"
#include "timer_rtc.h"
#include "app_error.h"
#include "nrf_drv_clock.h"
#include "nrf_drv_rtc.h"


// ===================================== RTC for snesor =================================== //

/* Global configuration. */
/* C standard library. */
/* RTOS. */
/* Application. */
/* Midlleware. */
/* MS46SF1 */

/* Private macros --------------------------------------------------------------------------------*/

/* Private data types ----------------------------------------------------------------------------*/

/* Private variables -----------------------------------------------------------------------------*/

const nrf_drv_rtc_t rtc_encoder = NRF_DRV_RTC_INSTANCE(0); /**< Declaring an instance of nrf_drv_rtc for RTC0. */
static uint32_t tick_rtc = 0;
static uint32_t val = 0;
static uint32_t timecount;

/* Private function prototypes -------------------------------------------------------------------*/
uint32_t timer_over(uint32_t timer){
  return  timer;
}

static void rtc0_handler_encoder(nrf_drv_rtc_int_type_t int_type) // function handle calutor speed encoder.
{
  int count = 0;
  if(int_type == NRFX_RTC_INT_TICK){
      tick_rtc ++;
      if(tick_rtc == 16){ // after 2 second start read sognal encoder 
          int count = 0;
           while(true){

              while(encoder_input_signal_change(IN_ENCODER) == false){
                if(encoder_input_signal_change(IN_ENCODER) == true){
                    val = val + 2;;
                    ht1621_all_number(val);
                }
              }
            count ++;
            if(count == 15768*2 ){  // time stop read signal encoder
              val = 0 ;
              tick_rtc =0;
              break; 
            }
         }
      }
   }
}

static void lfclk_config(void) // set clock for rtc
{
    ret_code_t err_code = nrf_drv_clock_init();
    APP_ERROR_CHECK(err_code);

    nrf_drv_clock_lfclk_request(NULL);
}

static void rtc0_config_enocder(void)
{
    uint32_t err_code;

    //Initialize RTC instance
    nrf_drv_rtc_config_t config = NRF_DRV_RTC_DEFAULT_CONFIG;

    config.prescaler = 4095; // ( f = (32768/(Pcal+1)) => T = 1/f )
    err_code = nrf_drv_rtc_init(&rtc_encoder, &config, rtc0_handler_encoder);
    APP_ERROR_CHECK(err_code);

    //Enable tick event & interrupt
    nrf_drv_rtc_tick_enable(&rtc_encoder,true);
    nrf_drv_rtc_enable(&rtc_encoder);
}

/* Public function bodies ------------------------------------------------------------------------*/

// ========== Calutor tiimer .
void cal_time(){

  lfclk_config();
  rtc0_config_enocder();
}
// ============================================================================================= //

// ============================================================================== //

// Read signal input encoder
bool encoder_input_signal_change(uint32_t INPUT_ENCODER){  

    uint32_t signal = read_input_en(IN_ENCODER);
    if(signal == 1){ // return true if signal = 1
      return  true;
    } 
    if(signal == 0) // return false is signal = 0
    {
      return false;
    }
}
 
void encoder_use_rtc0(){ // use rtc read signal encoder
  cal_time();
}

// =========================================================================== //

void read_signal_encoder_400bm(void){
    ht1621_setup();
    ht1621_start_number(val);

    input_en_pullup(IN_ENCODER);
    encoder_use_rtc0();
    // ******************************************** //
}

// === END FILE ======================================================= // 