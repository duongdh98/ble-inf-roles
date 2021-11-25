/**
  **************************************************************************************************
  * @file   spi_ms 46fs11.c
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

#include <stdlib.h>
#include "nrf.h"
#include "gpio_pin_config.h"
#include "led.h"
#include "led_bsp.h"
#include "nrf_drv_timer.h"
#include "timer_rtc.h"
#include "app_error.h"
#include "nrf_drv_clock.h"
#include "nrf_drv_rtc.h"

// ==== PWM === //
#include "bsp.h"
#include "app_pwm.h"

#define FERQ_IN_US 2000

// ==================== RTC ============================= //
/* Global configuration. */
/* C standard library. */
/* RTOS. */
/* Application. */
/* Midlleware. */
/* MS46SF1 */

/* Private macros --------------------------------------------------------------------------------*/

/* Private data types ----------------------------------------------------------------------------*/

APP_PWM_INSTANCE(m_pwm, 1); // For PWM

/* Private variables -----------------------------------------------------------------------------*/

const nrf_drv_rtc_t rtc = NRF_DRV_RTC_INSTANCE(0); /**< Declaring an instance of nrf_drv_rtc for RTC0. */
const nrf_drv_rtc_t rtc1 = NRF_DRV_RTC_INSTANCE(1); /**< Declaring an instance of nrf_drv_rtc for RTC1. */
uint32_t tick_rtc1 = 0;
const nrf_drv_rtc_t rtc_p_servo = NRF_DRV_RTC_INSTANCE(0); /**< Declaring an instance of nrf_drv_rtc for RTC0. */

static uint32_t tick_rtc = 0;
static uint32_t tick_servo = 0;

/* Private function prototypes -------------------------------------------------------------------*/

static void lfclk_config(void) // Configure clock for rtc
{
    ret_code_t err_code = nrf_drv_clock_init();
    APP_ERROR_CHECK(err_code);

    nrf_drv_clock_lfclk_request(NULL);
}

static void rtc_config(void) // Configure RTC - RTC 0
{
    uint32_t err_code;
    //Initialize RTC instance
    nrf_drv_rtc_config_t config = NRF_DRV_RTC_DEFAULT_CONFIG;
    config.prescaler = 4095; // ( f = (32768/(Pcal+1)) => T = 1/f )
    err_code = nrf_drv_rtc_init(&rtc, &config, rtc_config);
    APP_ERROR_CHECK(err_code);

    //Enable tick event & interrupt
    nrf_drv_rtc_tick_enable(&rtc,true);
    nrf_drv_rtc_enable(&rtc);
}

/* Public function bodies ------------------------------------------------------------------------*/

void rtc_cf_gpio(uint32_t led_id){ // Use led test rtc
  led_init(led_id);
}

// ===== Handle test led output GPIO_5.

void rtc_handler(nrf_drv_rtc_int_type_t int_type) 
{
  tick_rtc ++;
  if(int_type == NRFX_RTC_INT_TICK){
    if(tick_rtc == 1){
      led_down(GPIO_5);
    }
    else if(tick_rtc == 9){
      led_up(GPIO_5);
      tick_rtc = 0;
    }
  }
}



// * ===================================================== * //

// === RTC 1 ==============================================;

/**
 * @brief Handler for timer events.
 */
void rtc1_power_event_handler(nrf_timer_event_t event_type, void* p_context)
{
    if(event_type == NRFX_RTC_INT_TICK){
      tick_rtc1 ++;
      if(tick_rtc1 == 1){
        led_init(GPIO_1);
        led_down(GPIO_1);
      }
      else if(tick_rtc1 == 120) // aboout 15s .
      {
        led_init(GPIO_1);
        led_up(GPIO_1);
        tick_rtc1 =0;
      }
    }
}

/**
 * @brief Function for main application entry.
 */

// Turn off mode deepsleep MHCD42 use RTC 1 .
void rtc1_config() // Rtc config - use RTC1
{
    uint32_t err_code;

    //Initialize RTC instance
    nrf_drv_rtc_config_t config = NRF_DRV_RTC_DEFAULT_CONFIG;
    config.prescaler = 4095; // ( f = (32768/(Pcal+1)) => T = 1/f )
    err_code = nrf_drv_rtc_init(&rtc1, &config, rtc1_power_event_handler);
    APP_ERROR_CHECK(err_code);
    //Enable tick event & interrupt
    nrf_drv_rtc_tick_enable(&rtc1,true);

    //Set compare channel to trigger interrupt after COMPARE_COUNTERTIME seconds
    //err_code = nrf_drv_rtc_cc_set(&rtc,0,COMPARE_COUNTERTIME * 2,true);
    //APP_ERROR_CHECK(err_code);

    //Power on RTC instance
    nrf_drv_rtc_enable(&rtc1);
}

void timer_power(){ // function for turn off mode deeep sleep
  lfclk_config();
  rtc1_config();
}

// ========================== Configure function for signal servo use RTC 0 ======================= //

void rtc_handler_power_and_servo(nrf_drv_rtc_int_type_t int_type)
{
  tick_rtc ++;

  led_init(GPIO_2);

  if(int_type == NRFX_RTC_INT_TICK){
    if(tick_rtc == 1){
      led_down(GPIO_2);
    }
    else if(tick_rtc == 120){
      led_up(GPIO_2);
      tick_rtc = 0;
    }
  }
}


static void rtc_config_servo(void) // set output for servo
{
    uint32_t err_code;
    //Initialize RTC instance
    nrf_drv_rtc_config_t config = NRF_DRV_RTC_DEFAULT_CONFIG;
    config.prescaler = 4095; // ( f = (32768/(Pcal+1)) => T = 1/f )
    err_code = nrf_drv_rtc_init(&rtc_p_servo, &config, rtc_handler_power_and_servo);
    APP_ERROR_CHECK(err_code);

    //Enable tick event & interrupt
    nrf_drv_rtc_tick_enable(&rtc_p_servo,true);
    nrf_drv_rtc_enable(&rtc_p_servo);

}

/**=================== __________________________=============================*/

// ====== turn off mode deepsleep in mhcd42 use timer 1 ================================= //
void turn_off_deep_sleep_mhcd42(){
  timer_power();
}

// ======== turn on mode rtc =============================================== //
void rtc_mode_led(){
  rtc_cf_gpio(GPIO_5);
  lfclk_config();
  rtc_config();
}

// =========== Configure servo use RTC 0 ============================ //
void rtc_power_and_servo(){

  lfclk_config();
  rtc_config_servo();
}


// ========================= PWM ==================================== //

static volatile bool ready_flag;

void pwm_ready_handle(uint32_t pwm_id){
    ready_flag = true;
}

void out_pwm_servo(){

  ret_code_t err_code;

  app_pwm_config_t pwm_config = APP_PWM_DEFAULT_CONFIG_1CH(FERQ_IN_US, GPIO_1);
  pwm_config.pin_polarity[1] = APP_PWM_POLARITY_ACTIVE_HIGH;
  err_code = app_pwm_init(&m_pwm, &pwm_config, pwm_ready_handle);

  APP_ERROR_CHECK(err_code);
  app_pwm_enable(&m_pwm);

  while(true){
    while(app_pwm_channel_duty_set(&m_pwm, 0, 100) == NRF_ERROR_BUSY);
    //nrf_delay_ms(100);

    while(app_pwm_channel_duty_set(&m_pwm, 0, 500) == NRF_ERROR_BUSY);
    //nrf_delay_ms(100);

    while(app_pwm_channel_duty_set(&m_pwm, 0, 1000) == NRF_ERROR_BUSY);
    //nrf_delay_ms(100);

    //while(app_pwm_channel_duty_set(&m_pwm, 0, 4000) == NRF_ERROR_BUSY);
    //nrf_delay_ms(100);
  }
}

// == END FILE ============================================== //