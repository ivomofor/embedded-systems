#include <stdio.h>
#include <stdint.h>

#define LED_0_MASK (1u << 0)
#define LED_3_MASK (1u << 3)

void greet(void)
{
    printf("Learning embedded systems with C23!\n");
}

void led_on(uint8_t *state, uint8_t mask)
{
    *state |= mask;
}

void led_off(uint8_t *state, uint8_t mask)
{
    *state &= (uint8_t)~mask;
}

int main(void)
{
    uint8_t led_state = 0;

    printf("Embedded Systems Learning Project - C23\n");

    greet();

    printf("Initial LED state: %u\n", (unsigned int)led_state);

    led_on(&led_state, LED_0_MASK);

    printf("After turning on LED 0: %u\n", (unsigned int)led_state);

    led_on(&led_state, LED_3_MASK);

    if ((led_state & 8u) != 0u) {
        printf("LED 3 is ON\n");
    } else {
        printf("LED 3 is OFF\n");
    }

    printf("After turning on LED 3: %u\n", (unsigned int)led_state);

    led_off(&led_state, LED_3_MASK);

    printf("After turning off LED 3: %u\n",
       (unsigned int)led_state);

    led_off(&led_state, LED_0_MASK);

    printf("After turning off LED 0: %u\n",
           (unsigned int)led_state);

    if ((led_state & 8u) != 0u) {
        printf("LED 3 is ON\n");
    } else {
        printf("LED 3 is OFF\n");
    }

    return 0;
}