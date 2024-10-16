#include "app_error.h"
#include "nrf.h"
#include "nrf_drv_gpiote.h"
#include "nrf_gpio.h"
#include "nrf_delay.h"
#include "nrf_power.h"

#include <stdbool.h>

#define led 13
#define button 11

void input_pin_wakeup_handle(nrf_drv_gpiote_pin_t pin, nrf_gpiote_polarity_t action) {
 // printf("Wake Up!!!\r\n");
 // nrf_gpio_pin_toggle(led);
}

void gpio_init_deep_sleep() {
  //ret_code_t err_code; //hold error value

  //err_code = nrf_drv_gpiote_init();
  //APP_ERROR_CHECK(err_code);

 // nrf_gpio_cfg_output(led);
  //nrf_gpio_pin_set(led); //turn off

 // nrf_drv_gpiote_in_config_t in_config = GPIOTE_CONFIG_IN_SENSE_HITOLO(true);
 // in_config.pull = NRF_GPIO_PIN_PULLUP;

 // err_code = nrf_drv_gpiote_in_init(button, &in_config, input_pin_wakeup_handle);
  //APP_ERROR_CHECK(err_code);

  //nrf_drv_gpiote_in_event_enable(button, true);
}

int deep_sleep_example(void) {
 // printf("App Init\r\n");

  //gpio_init_deep_sleep();

 // printf("Deep Sleep\r\n");

//sd_power_system_off();

  __WFE();
  __SEV();
  __WFE();
  NRF_POWER->SYSTEMOFF = 1;

  while(1)
  {
   printf("Never reached code.. \r\n");
   nrf_delay_ms(1000);
  }
}