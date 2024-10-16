#include <stdbool.h>
#include <stdint.h>
#include "nrf_delay.h"
#include "boards.h"


int led_board_example(void)
{
    /* Configure board. */
    bsp_board_init(BSP_INIT_LEDS);

    /* Toggle LEDs. */
    while (true)
    {
        bsp_board_led_on(0);
        nrf_delay_ms(400);
        bsp_board_led_off(0);
        nrf_delay_ms(400);
        for (int i = 0; i < LEDS_NUMBER; i++)
        {
            bsp_board_led_invert(i);
            nrf_delay_ms(500);
        }
    }
}