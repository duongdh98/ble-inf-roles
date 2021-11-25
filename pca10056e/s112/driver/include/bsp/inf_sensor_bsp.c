/***************************************************************************************************************
 * @auth            : duongdh                                                                                  
 * @day             : 15-july-2021 
 * @file            : inf_sensor.c                                                                            
 * @dissaption      : File to create FW-Core . Coding in free time                                              
***************************************************************************************************************/

/*  Indent using spaces
    Tab width   : 4 spaces
    Line width  : 100 characters
    Line ending : LF (0x0A) */

/* Public macros ---------------------------------------------------------------------------------*/
/* Include ---------------------------------------------------------------------------------------*/
#include "inf_sensor_bsp.h"

/* Define ----------------------------------------------------------------------------------------*/
/* Private data types ----------------------------------------------------------------------------*/
/* Public data types -----------------------------------------------------------------------------*/

uint32_t g_start;
uint32_t g_stop;

/* Private function prototypes -------------------------------------------------------------------*/

/* Public function prototypes --------------------------------------------------------------------*/

void inf_sensor_init_up(uint32_t num) {

  nrf_gpio_cfg_input(num, NRF_GPIO_PIN_PULLUP);
}

void inf_sensor_init_down(uint32_t num) {

  nrf_gpio_cfg_input(num, NRF_GPIO_PIN_PULLDOWN);
}

void inf_sensor_init_none(uint32_t num) {

  nrf_gpio_cfg_input(num, NRF_GPIO_PIN_NOPULL);
}

uint32_t read_input_inf_sensor(uint32_t num) {
  
  uint32_t value;
  return  value = nrf_gpio_pin_read(num);
}

void handle_point_start(nrf_drv_gpiote_pin_t pin_num, nrf_gpiote_polarity_t action) {

  if (action) {
    g_start = action;
  }

}

void handle_point_stop(nrf_drv_gpiote_pin_t pin_num, nrf_gpiote_polarity_t action) {
  
  if (action) {
    g_stop = action;
  }
}

void gpiote_point_init() {

  /* --- Initialization gpiote ( interupt ) init --- */
  nrf_drv_gpiote_init();
  
  /* --- initialization point start --- */
  nrf_drv_gpiote_in_config_t cfg_point_start = GPIOTE_CONFIG_IN_SENSE_HITOLO(true);
  cfg_point_start.pull = NRF_GPIO_PIN_NOPULL;

  /* --- initialization point stop --- */
  nrf_drv_gpiote_in_config_t cfg_point_stop = GPIOTE_CONFIG_IN_SENSE_LOTOHI(true);
  cfg_point_stop.pull = NRF_GPIO_PIN_NOPULL;

  /* --- Initialization catch handle if have event --- */
  nrf_drv_gpiote_in_init(POINT_START, &cfg_point_start, handle_point_start);
  nrf_drv_gpiote_in_init(POINT_STOP, &cfg_point_stop, handle_point_stop);

}

void enable_point_start() {
  nrf_drv_gpiote_in_event_enable(POINT_START, true); // Enable interupt point start
}

void enable_point_stop() {
  nrf_drv_gpiote_in_event_enable(POINT_STOP, true); // Enable interupt point start
}

void disenable_point_start() {
  nrf_drv_gpiote_in_event_disable(POINT_START);
  nrf_gpio_cfg_sense_set(POINT_START, NRF_GPIO_PIN_NOSENSE);
}

void disenable_point_stop() {
  nrf_drv_gpiote_in_event_disable(POINT_STOP);
  nrf_gpio_cfg_sense_set(POINT_STOP, NRF_GPIO_PIN_NOSENSE);
}

/* END OF FILE ************************************************************************************/