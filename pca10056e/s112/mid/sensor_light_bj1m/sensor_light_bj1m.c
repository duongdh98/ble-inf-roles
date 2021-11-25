/**
  **************************************************************************************************
  * @file   sensor_light_bj1m.c
  * @author duongdh
  * @date   24-11-2020
  * @brief  Source file for time delay.
  **************************************************************************************************
  */

#include "sensor_light_bj1m.h"
#include "ht1621_lcd.h"
#include "gpio_pin_config.h"
#include "buttoms.h"
#include "sensor_light_bj1m_bsp.h"

// ========= congigure gpio ipput for sensor =================================================== //
//.............................................................................//

bool read_signal_sensor_up(uint32_t PIN_INPUT){ // read signal sensor if normal signal of sensor is high
  sensor_init_up(PIN_INPUT);
  if(read_in_sensor(PIN_INPUT) == 0){
    return true;
  }
  else if (read_in_sensor(PIN_INPUT) == 1){
    return false;
  }
}

//===================================================================================================//
bool read_signal_sensor_down(uint32_t PIN_INPUT){ //read signal sensor if normal signal of sensor is low
  sensor_init_up(PIN_INPUT);
  if(read_in_sensor(PIN_INPUT) == 1){
    return true;
  }
  else if (read_in_sensor(PIN_INPUT) == 0){
    return  false;
  }
}

// ============================================================================================= 
void sensor_counting_number(uint32_t number_couting){
  uint32_t num;
  num = number_couting;
  sensor_init_up(INPUT_SENSOR);

  while(true){
    // while have not product if push reset then return numbar start
    if(buttom_reset_down(RESET_BUTTOM) == true)
    {
      number_couting = num;
      ht1621_start_number(number_couting);
    }
    if(read_signal_sensor_up(INPUT_SENSOR) == true){
      while(read_signal_sensor_up(INPUT_SENSOR) == true){
        // while have not product if push reset then return numbar start
        if(buttom_reset_down(RESET_BUTTOM) == true){
          number_couting = num;
          ht1621_start_number(number_couting);
        }
      }
      // ++ number and check value of number after add
      number_couting ++;
      if(number_couting > 999999){
        number_couting = 0;
      }
      // @ show number in lcd led
      ht1621_all_number(number_couting);
      if(buttom_reset_down(RESET_BUTTOM) == true){
        number_couting = num;
        ht1621_start_number(number_couting);
      }
    }
  }
  // Tu tu sua. ============================== //
}
// @ ======================================================================================== @ //

