#include <stdbool.h>
#include <stdint.h>

#include "nrf_delay.h"
#include "nrf_gpio.h"

#include "boards.h"

#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "nrf_log_default_backends.h"
#include "nrf_log_backend_rtt.h"

#define NRF_FPRINTF_FLAG_AUTOMATIC_CR_ON_LF_ENABLED 0
#define NRF_LOG_BACKEND_RTT_ENABLED 1
#define NRF_LOG_BACKEND_UART_ENABLED 0
#define NRF_LOG_ENABLED 1
#define NRF_LOG_DEFERRED 1

#define button1 11
#define led1 13

int log_example(void) {

  APP_ERROR_CHECK(NRF_LOG_INIT(NULL));
  NRF_LOG_DEFAULT_BACKENDS_INIT();



  nrf_gpio_cfg_input(button1, NRF_GPIO_PIN_PULLUP);
  nrf_gpio_cfg_output(led1);
  nrf_gpio_pin_set(led1); // Set logic 1 to pin 13;

  printf("Main Application Started\r\n");

  NRF_LOG_INFO("Application started..\r\r\n");

  while (1) {

    if (nrf_gpio_pin_read(button1) == 0) {
      nrf_gpio_pin_clear(led1);
      NRF_LOG_WARNING("Button pressed..");
      while (nrf_gpio_pin_read(button1) == 0)
        ;
      NRF_LOG_WARNING("Button released..");
      nrf_gpio_pin_set(led1);
    }
    nrf_delay_ms(100);
  }
}