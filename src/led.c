#include "led.h"

#include <stdio.h>

void led_on(struct LED *led)
{
    if (led->state == LED_OFF)
    {
        led->state = LED_ON;
        led->times_turned_on++;
    }
}

void led_off(struct LED *led)
{
    led->state = LED_OFF;
}

void print_led_info(const struct LED *led)
{
    printf("LED ID: %u\n", (unsigned int)led->id);

    printf("LED state: %s\n",
           led->state == LED_ON ? "ON" : "OFF");

    printf("Times turned on: %u\n",
           (unsigned int)led->times_turned_on);
}
