
#include <stdio.h>
#include <stdint.h>

// ========================= TImner =================== //

void gpio_cf();

void test_output();

void timer_power();

void turn_off_deep_sleep_mhcd42();

// ====================== RTC ======================= // 

void rtc_cf_gpio(uint32_t led_id);

void rtc_mode_led();

void rtc_power_and_servo();
// ===================== PWM ========================== //

void pwm_ready_handle(uint32_t pwm_id);

void out_pwm_servo();

// =========== END FILE =============================================== //