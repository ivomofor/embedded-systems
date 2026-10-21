#include "led.h"

#include <stdio.h>

int main(void)
{
    struct LED led1 = {
        .id = 1,
        .state = LED_OFF,
        .times_turned_on = 0
    };

    struct LED led2 = {
        .id = 2,
        .state = LED_OFF,
        .times_turned_on = 0
    };

    printf("Initial LED states:\n");
    print_led_info(&led1);
    print_led_info(&led2);

    printf("\nTurning on both LEDs...\n");
    led_on(&led1);
    led_on(&led2);

    print_led_info(&led1);
    print_led_info(&led2);

    printf("\nTurning off LED 1...\n");
    led_off(&led1);

    print_led_info(&led1);
    print_led_info(&led2);

    return 0;
}