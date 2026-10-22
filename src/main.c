#include "gpio.h"
#include "led.h"

#include <stdio.h>

int main(void)
{
    struct LED led1 = {
        .id = 1,
        .pin = 0,
        .state = LED_OFF,
        .times_turned_on = 0
    };

    struct LED led2 = {
        .id = 2,
        .pin = 3,
        .state = LED_OFF,
        .times_turned_on = 0
    };

    printf("Initial GPIO register: 0x%02X\n",
           (unsigned int)gpio_read_register());

    printf("\nInitial LED states:\n");
    print_led_info(&led1);
    print_led_info(&led2);

    printf("\nTurning on both LEDs...\n");
    led_on(&led1);
    led_on(&led2);

    print_led_info(&led1);
    print_led_info(&led2);

    printf("GPIO register: 0x%02X\n",
           (unsigned int)gpio_read_register());

    printf("\nTurning off LED 1...\n");
    led_off(&led1);

    print_led_info(&led1);
    print_led_info(&led2);

    printf("GPIO register: 0x%02X\n",
           (unsigned int)gpio_read_register());

    return 0;
}