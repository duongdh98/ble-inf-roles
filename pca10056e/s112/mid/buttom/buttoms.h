/**
  **************************************************************************************************
  * @file   buttoms.h
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
#include "buttom_bsp.h"

#ifndef _BUTTOM_H
#define _BUTTOM_H

#ifdef  __cplusplus
extern "C" {
#endif

/* Global configuration. */

/* RTOS. */

/* Middleware. */

/* Public macros ---------------------------------------------------------------------------------*/

/* Public data types -----------------------------------------------------------------------------*/

/* Public function prototypes --------------------------------------------------------------------*/

// Return true if event was started ( normol signal pin buttom was PULLUP )
bool buttom_reset_up(uint32_t input_buttoms);

// Return true if event was started ( normol signal pin buttom was  PULLDOWN )
bool buttom_reset_down(uint32_t input_buttoms);

#ifdef cplusplus
extern "C"
}
#endif

#endif /* _BUTTOMS_H */

/* END OF FILE ************************************************************************************/