#include <stdio.h>
#include <stdint.h>

enum LEDState
{
    LED_OFF,
    LED_ON
};

struct LED
{
    uint8_t id;
    enum LEDState state;
    uint32_t times_turned_on;
};

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