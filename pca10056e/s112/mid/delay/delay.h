/**
  **************************************************************************************************
  * @file   delay.h
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

 #include "delay_bsp.h"

 #ifndef  _DELAY_H
 #define  _DELAY_H

 #if __cplusplus
  extern "C"{
  #endif


/* Global configuration. */

/* RTOS. */

/* Middleware. */

/* Public macros ---------------------------------------------------------------------------------*/

/* Public data types -----------------------------------------------------------------------------*/

/* Public function prototypes --------------------------------------------------------------------*/

// delay ms.
void delay_m_second(int val);

// delay us.
void delay_u_second(int val);

#ifdef __cplusplus
}
#endif

#endif /* _DELAY_H */


/* END OF FILE *************************************************************/