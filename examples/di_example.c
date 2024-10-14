#include <stdbool.h>
#include <stdint.h>
#include "nrf_delay.h"
#include "nrf_gpio.h"

#define button1 11
#define led1 13

int di_example(void) {
  nrf_gpio_cfg_input(button1, NRF_GPIO_PIN_PULLUP);
  nrf_gpio_cfg_output(led1);
  nrf_gpio_pin_set(led1); // Set logic 1 to pin 13;

  while (1) {

    if(nrf_gpio_pin_read(button1) == 0)
    {
      nrf_gpio_pin_clear(led1);
      while(nrf_gpio_pin_read(button1) == 0);
      nrf_gpio_pin_set(led1);

    }
    nrf_delay_ms(100);
  }
}