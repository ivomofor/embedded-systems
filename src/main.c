#include <stdio.h>
#include <stdint.h>

#define LED_0_MASK (1u << 0)
#define LED_3_MASK (1u << 3)

int main(void)
{
    uint8_t led_state = 0;

    printf("Embedded Systems Learning Project - C23\n");

    printf("Initial LED state: %u\n", (unsigned int)led_state);

    led_state |= LED_0_MASK;

    printf("After turning on LED 0: %u\n", (unsigned int)led_state);

    led_state |= LED_3_MASK;

    if ((led_state & 8u) != 0u) {
        printf("LED 3 is ON\n");
    } else {
        printf("LED 3 is OFF\n");
    }

    printf("After turning on LED 3: %u\n", (unsigned int)led_state);

    led_state &= ~LED_3_MASK;

    if ((led_state & 8u) != 0u) {
        printf("LED 3 is ON\n");
    } else {
        printf("LED 3 is OFF\n");
    }

    return 0;
}