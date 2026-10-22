#ifndef LED_H
#define LED_H

#include <stdint.h>

enum LEDState
{
    LED_OFF,
    LED_ON
};

struct LED
{
    uint8_t id;
    uint8_t pin;
    enum LEDState state;
    uint32_t times_turned_on;
};

void led_on(struct LED *led);
void led_off(struct LED *led);
void print_led_info(const struct LED *led);

#endif
