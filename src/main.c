#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint8_t led_state = 0;

    printf("Embedded Systems Learning Project - C23\n");

    printf("Initial LED state: %u\n", (unsigned int)led_state);

    led_state = led_state | 1u;

    printf("After turning on LED 0: %u\n", (unsigned int)led_state);

    led_state = led_state | 8u;

    if ((led_state & 8u) != 0u) {
        printf("LED 3 is ON\n");
    } else {
        printf("LED 3 is OFF\n");
    }

    printf("After turning on LED 3: %u\n", (unsigned int)led_state);

    led_state = led_state & ~8u;

    if ((led_state & 8u) != 0u) {
        printf("LED 3 is ON\n");
    } else {
        printf("LED 3 is OFF\n");
    }

    return 0;
}