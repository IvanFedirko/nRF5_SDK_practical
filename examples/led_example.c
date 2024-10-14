#include <stdbool.h>
#include <stdint.h>
#include "nrf_delay.h"
#include "nrf_gpio.h"

#define led1 13
#define led2 14

int led_example(void) {
  nrf_gpio_cfg_output(led1);
  nrf_gpio_cfg_output(led2);

  while (1) {
    nrf_gpio_pin_set(led1); // Set logic 1 to pin 13
    nrf_delay_ms(100);
    nrf_gpio_pin_clear(led1); // Set pin to logic 0
    nrf_delay_ms(100);

    nrf_gpio_pin_toggle(led2);
  }
}