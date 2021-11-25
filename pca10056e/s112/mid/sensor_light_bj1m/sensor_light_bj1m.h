/**
  **************************************************************************************************
  * @file   sensor_light_bj1m.h
  * @author duongdh
  * @date   24-11-2020
  * @brief  Header file for time delay.
  **************************************************************************************************
  */
// Include file for encoder file
#include "gpio_pin_config.h"

// @ ****************************************** @ //
// configure for Sensor 

bool read_signal_sensor_up(uint32_t PIN_INPUT); // read signal sensor if normal signal of sensor is high

bool read_signal_sensor_down(uint32_t PIN_INPUT); //read signal sensor if normal signal of sensor is low

void sensor_counting_number(uint32_t number_couting); // ==================== 

// @ ......................................... @ //