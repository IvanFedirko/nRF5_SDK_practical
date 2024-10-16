#include "app_error.h"
#include "boards.h"
#include "nrf.h"
#include "nrf_drv_gpiote.h"
#include "nrf_gpio.h"
#include <stdbool.h>

#define led 13
#define button 11

void input_pin_handle(nrf_drv_gpiote_pin_t pin, nrf_gpiote_polarity_t action) {
  nrf_gpio_pin_toggle(led);
}

void gpio_init() {
  ret_code_t err_code; //hold error value

  err_code = nrf_drv_gpiote_init();
  APP_ERROR_CHECK(err_code);

  nrf_gpio_cfg_output(led);
  nrf_gpio_pin_set(led); //turn off

  nrf_drv_gpiote_in_config_t in_config = GPIOTE_CONFIG_IN_SENSE_HITOLO(true);
  in_config.pull = NRF_GPIO_PIN_PULLUP;

  err_code = nrf_drv_gpiote_in_init(button, &in_config, input_pin_handle);
  APP_ERROR_CHECK(err_code);

  nrf_drv_gpiote_in_event_enable(button, true);
}

int btn_interrupt_example(void) {
  gpio_init();
}