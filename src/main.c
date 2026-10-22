#include "gpio.h"

#include <stdio.h>

int main(void)
{
    printf("Initial register: 0x%02X\n",
           (unsigned int)gpio_read_register());

    gpio_set_pin(0);
    gpio_set_pin(3);

    printf("After setting pins 0 and 3: 0x%02X\n",
           (unsigned int)gpio_read_register());

    gpio_clear_pin(0);

    printf("After clearing pin 0: 0x%02X\n",
           (unsigned int)gpio_read_register());

    printf("Pin 0 state: %u\n",
           (unsigned int)gpio_is_pin_set(0));

    printf("Pin 3 state: %u\n",
           (unsigned int)gpio_is_pin_set(3));

    return 0;
}