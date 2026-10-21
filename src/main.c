#include "gpio.h"

#include <stdio.h>

int main(void)
{
    gpio_set_pin(0);
    gpio_set_pin(2);

    printf("Initial register: 0x%02X\n",
           (unsigned int)gpio_read_register());

    printf("\nTrying to turn on invalid pin 8...\n");
    gpio_set_pin(8);

    printf("Register after invalid operation: 0x%02X\n",
           (unsigned int)gpio_read_register());

    printf("Reading invalid pin 8: %u\n",
           (unsigned int)gpio_is_pin_set(8));

    return 0;
}