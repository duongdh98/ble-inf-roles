/***************************************************************************************************************
 * @auth            : duongdh                                                                                  
 * @day             : 15-july-2021 
 * @file            : inf_sensor_bsp.h                                                                            
 * @dissaption      : File to create FW-Core . Coding in free time                                              
***************************************************************************************************************/

#ifndef  _INR_SENSOR_BSP_H
#define  _INR_SENSOR_BSP_H

#ifdef __cplusplus
extern "C" {
#endif

/* Public macros ---------------------------------------------------------------------------------*/
/* Include ---------------------------------------------------------------------------------------*/

#include "gpio_pin_config.h"
#include "nrf_gpio.h"
#include "nrf.h"
#include "nrf_drv_gpiote.h"
#include "app_error.h"

/* Define ----------------------------------------------------------------------------------------*/

#define  POINT_START  INF_SENSOR_START
#define  POINT_STOP   INF_SENSOR_STOP

/* Private data types ----------------------------------------------------------------------------*/
/* Public data types -----------------------------------------------------------------------------*/
/* Private function prototypes -------------------------------------------------------------------*/
/* Public function prototypes --------------------------------------------------------------------*/

void inf_sensor_init_up(uint32_t num);

void inf_sensor_init_down(uint32_t num);

void inf_sensor_init_none(uint32_t num);

uint32_t read_input_inf_sensor(uint32_t num);

void gpiote_point_init();

void enable_point_start();
void enable_point_stop();

void disenable_point_start();
void disenable_point_stop();

#ifdef __cplusplus
}
#endif

#endif /* _INR_SENSOR_BSP_H */

/* END OF FILE ************************************************************************************/
