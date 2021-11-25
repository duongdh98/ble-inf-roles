/**
  **************************************************************************************************
  * @file   zerr.h
  * @brief  Header file for zerr module.
  * @by     khanhcq | 05-May-2014 | Launch for ZenBee-FWCore.
  *         khanhcq | 22-February-2017 | Modify for ZenBee-Boot.
  *         khanhcq | 21-May-2019 | Modify for ZenLight-FWCore.
  **************************************************************************************************
  *
  * Copyright (C) 2017 Leanwell Technology Co.,Ltd. All rights reserved.
  *
  * All information contained herein is the property of Leanwell Technology Co.,Ltd. The intellectual
  * and technical concepts contained herein are proprietary to Leanwell Technology Co.,Ltd and are
  * protected by trade secret or copyright law. Dissemination of this information or reproduction of
  * this material is strictly forbidden unless prior written permission is obtained from Leanwell
  * Technology Co.,Ltd.
  *
  * This file is part of ZenLight-FWCore.
  **************************************************************************************************
  */

/*  Indent using spaces
    Tab width   : 4 spaces
    Line width  : 100 characters
    Line ending : LF (0x0A) */

#ifndef _ZERR_H
#define _ZERR_H

#ifdef __cplusplus
extern "C" {
#endif

/* Public macros ---------------------------------------------------------------------------------*/
#define ZERR(x)             zerr_get_str_err(x)

/* Public data types -----------------------------------------------------------------------------*/

/* Module definition. */
typedef enum
{
    ZERR_MODULE_EVTCAP,
    ZERR_MODULE_MIFARE,
    ZERR_MODULE_FINGER,
    ZERR_MODULE_TBED,

    ZERR_MODULE_XXX
} zerr_module_t;

/* Object definition. */
typedef enum
{
    ZERR_OBJECT_MIFARE,
    ZERR_OBJECT_FINGER,

    ZERR_OBJECT_RFU
} zerr_object_t;

/* Error code definition. */
typedef enum
{
    /* Common error code. */
    ZERR_OK                         = 0u,   /* Success. */
    ZERR_OPEN_ALREADY               = 1u,   /* Has been already opened. */
    ZERR_INVALID_PARAM              = 2u,   /* Parameter is NULL. */
    ZERR_MEM_OUT,                           /* Out of memory. */
    ZERR_TIME_OUT,                          /* Out of time. */
    ZERR_NOT_OPEN,                          /* Has not been opened yet or unable to open. */
    ZERR_STORAGE_OUT,                       /* Out of storage. */
    ZERR_EXIST,                             /* Item exists. */

    /* After adding an error code, MUST go to zerr.c to add a string representation for it. */

    ZERR_EMPTY,                             /**< Storage is empty */
    ZERR_FULL,                              /**< Storage is full */
    ZERR_TX,                                /**< Unable to transmit */
    ZERR_RX,                                /**< Unable to receive */
    ZERR_NOT_FOUND,                         /**< Not found */
    ZERR_UNPLUG,                            /**< Unplug */

    /* FATFS error code */
    ZERR_LINK,                              /**< Unable to link or unlink */

    /* Module internal error code. */
    ZERR_INTERNAL_EVTCAP,                   /* Error in evtcap module. */
    ZERR_INTERNAL_MIFARE,                   /* Error in mifare module. */
    ZERR_INTERNAL_SL025,                    /* Error in sl025 module. */
    ZERR_INTERNAL_SL013,                    /* Error in sl025 module. */
    ZERR_INTERNAL_ESP,                      /* Error in esp module. */
    ZERR_INTERNAL_FINGER,                   /* Error in finger module. */
    ZERR_INTERNAL_R301T,                    /* Error in r301t module. */

    ZERR_READ,                              /**< Read fail */
    ZERR_WRITE,                             /**< Write fail */
    ZERR_AUTHEN,                            /**< Not authenticate */
    ZERR_CRC,                               /**< Checksum error */

    /* RC522 error code */
    ZERR_PROTOCOL,                          /**< Mifare start bit wrong, buffer length error */
    ZERR_PARITY,                            /**< Parity error detected by RC or library */
    ZERR_COLLISION,                         /**< Typically, the RC repors such an error */
    ZERR_BUFFER_OVERFLOW,                   /**< Attempt to write beyond the end of a buffer */
    ZERR_TEMP,                              /**< Temperature sensor detect overheat */
    ZERR_FIFO_WRITE,                        /**< Error caused because of interface conflict during
                                            write access to FIFO */
    ZERR_BITCOUNT,                          /**< Typically, the RC reports such an error */
    ZERR_BYTECOUNT,                         /**< Typically, the RC reports such an error */
    ZERR_CASC_LEVEL,                        /**< Typically, the RC reports such an error */
    ZERR_FORMAT,                            /**< The data format does not match the spec */

    ZERR_SUPPORT                            /**< Don't support */
} zerr_t;

/* Public function prototypes --------------------------------------------------------------------*/

/**
  * @brief      Convert an error to a string representation.
  * @param[in]  error_code: an integer indicates an error.
  * @retval     A string representation for such error.
  */
const char*
zerr_get_str_err (zerr_t error_code);

/**
  * @brief      Display system error on LCD and suspend the calling task.
  * @param[in]  module_code: module gets error.
  * @param[in]  object_code: object in evtcap gets error.
  * @param[in]  error_code: error code.
  * @retval     None.
  */
void
zerr_suspend (zerr_module_t module_code, zerr_object_t object_code, zerr_t error_code);

#ifdef __cplusplus
}
#endif

#endif /* _ZERR_H */

/* END OF FILE ************************************************************************************/
