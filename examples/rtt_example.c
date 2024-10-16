#include <stdbool.h>
#include <stdint.h>
#include "nrf_delay.h"
#include "nrf_gpio.h"
#include "boards.h"

#define button1 11
#define led1 13

int rtt_example(void) {
  printf("Main Application Started\r\n");

  nrf_gpio_cfg_input(button1, NRF_GPIO_PIN_PULLUP);
  nrf_gpio_cfg_output(led1);
  nrf_gpio_pin_set(led1); // Set logic 1 to pin 13;

  while (1) {

    if(nrf_gpio_pin_read(button1) == 0)
    {
      nrf_gpio_pin_clear(led1);
      printf("Button pressed\r\n");
      while(nrf_gpio_pin_read(button1) == 0);
      printf("Button released\r\n");
      nrf_gpio_pin_set(led1);

    }
    nrf_delay_ms(100);
  }
}