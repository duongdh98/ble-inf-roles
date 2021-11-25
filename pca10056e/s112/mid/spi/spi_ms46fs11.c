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

#include "nrf_drv_spi.h"

#ifdef SPIM_PRESENT
#define INSTANCE_COUNT   SPIM_COUNT
#else
#define INSTANCE_COUNT   SPI_COUNT
#endif

static nrf_drv_spi_evt_handler_t m_handlers[INSTANCE_COUNT];
static void *                    m_contexts[INSTANCE_COUNT];

#ifdef SPIM_PRESENT
static void spim_evt_handler(nrfx_spim_evt_t const * p_event,
                             void *                  p_context)
{
    uint32_t inst_idx = (uint32_t)p_context;
    nrf_drv_spi_evt_t const event =
    {
        .type = (nrf_drv_spi_evt_type_t)p_event->type,
        .data =
        {
            .done =
            {
                .p_tx_buffer = p_event->xfer_desc.p_tx_buffer,
                .tx_length   = p_event->xfer_desc.tx_length,
                .p_rx_buffer = p_event->xfer_desc.p_rx_buffer,
                .rx_length   = p_event->xfer_desc.rx_length,
            }
        }
    };
    m_handlers[inst_idx](&event, m_contexts[inst_idx]);
}
#endif // SPIM_PRESENT

#ifdef SPI_PRESENT
static void spi_evt_handler(nrfx_spi_evt_t const * p_event,
                            void *                 p_context)
{
    uint32_t inst_idx = (uint32_t)p_context;
    nrf_drv_spi_evt_t const event =
    {
        .type = (nrf_drv_spi_evt_type_t)p_event->type,
        .data =
        {
            .done =
            {
                .p_tx_buffer = p_event->xfer_desc.p_tx_buffer,
                .tx_length   = p_event->xfer_desc.tx_length,
                .p_rx_buffer = p_event->xfer_desc.p_rx_buffer,
                .rx_length   = p_event->xfer_desc.rx_length,
            }
        }
    };
    m_handlers[inst_idx](&event, m_contexts[inst_idx]);
}
#endif // SPI_PRESENT

ret_code_t nrf_drv_spi_init(nrf_drv_spi_t const * const p_instance,
                            nrf_drv_spi_config_t const * p_config,
                            nrf_drv_spi_evt_handler_t    handler,
                            void *                       p_context)
{
    uint32_t inst_idx = p_instance->inst_idx;
    m_handlers[inst_idx] = handler;
    m_contexts[inst_idx] = p_context;

    ret_code_t result = 0;
    if (NRF_DRV_SPI_USE_SPIM)
    {
#ifdef SPIM_PRESENT
        nrfx_spim_config_t config_spim = NRFX_SPIM_DEFAULT_CONFIG;
        config_spim.sck_pin        = p_config->sck_pin;
        config_spim.mosi_pin       = p_config->mosi_pin;
        config_spim.miso_pin       = p_config->miso_pin;
        config_spim.ss_pin         = p_config->ss_pin;
        config_spim.irq_priority   = p_config->irq_priority;
        config_spim.orc            = p_config->orc;
        config_spim.frequency      = (nrf_spim_frequency_t)p_config->frequency;
        config_spim.mode           = (nrf_spim_mode_t)p_config->mode;
        config_spim.bit_order      = (nrf_spim_bit_order_t)p_config->bit_order;
        result = nrfx_spim_init(&p_instance->u.spim,
                                &config_spim,
                                handler ? spim_evt_handler : NULL,
                                (void *)inst_idx);
#endif
    }
    else if (NRF_DRV_SPI_USE_SPI)
    {
        result = nrfx_spi_init(&p_instance->u.spi,
                               (nrfx_spi_config_t const *)p_config,
                               handler ? spi_evt_handler : NULL,
                               (void *)inst_idx);
    }
    return result;
}


/* Private function bodies -----------------------------------------------------------------------*/

/* ==== END FILE ================================================================================ */