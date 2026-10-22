#include "gpio.h"
#include "led.h"

#include <stdio.h>

int main(void)
{
    struct LED led = {
        .id = 1,
        .pin = 2,
        .state = LED_OFF,
        .times_turned_on = 0
    };

    printf("Running LED tests...\n");

    /* Test 1: Turning on an LED sets its GPIO pin. */
    led_on(&led);

    if (led.state != LED_ON ||
        gpio_is_pin_set(2) != 1 ||
        led.times_turned_on != 1)
    {
        printf("FAIL: Turning on an LED.\n");
        return 1;
    }

    printf("PASS: Turning on an LED sets its GPIO pin.\n");

    /* Test 2: Turning on an already-on LED doesn't increment the counter. */
    led_on(&led);

    if (led.times_turned_on != 1)
    {
        printf("FAIL: Repeated led_on() incremented the counter.\n");
        return 1;
    }

    printf("PASS: Repeated led_on() preserves the counter.\n");

    /* Test 3: Turning off an LED clears its GPIO pin. */
    led_off(&led);

    if (led.state != LED_OFF ||
        gpio_is_pin_set(2) != 0)
    {
        printf("FAIL: Turning off an LED.\n");
        return 1;
    }

    printf("PASS: Turning off an LED clears its GPIO pin.\n");

    printf("All LED tests passed!\n");

    return 0;
}
