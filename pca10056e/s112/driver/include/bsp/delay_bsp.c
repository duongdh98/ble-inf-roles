/**
  **************************************************************************************************
  * @file   delay_bsp.c
  * @brief  function of file.
  * @by     duongdh | 16-now-2020 | Launch for CouterSensor-FWCore.
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

#include "delay_bsp.h"

/* Global configuration. */
/* C standard library. */
/* RTOS. */
/* Application. */
/* Driverware. */
/* MS46SF1 */
// Define function for buttoms.


/* Private macros --------------------------------------------------------------------------------*/

/* Private data types ----------------------------------------------------------------------------*/

/* Private variables -----------------------------------------------------------------------------*/

/* Private function prototypes -------------------------------------------------------------------*/


/* Private function bodies -----------------------------------------------------------------------*/


/* Public function bodies ------------------------------------------------------------------------*/
// delay ms.
void delay_ms(int val){
  nrf_delay_ms(val);
}

// delay us
void delay_us(int val){
  nrf_delay_us(val);
}

/* Private function bodies -----------------------------------------------------------------------*/

/* END OF FILE ************************************************************************************/