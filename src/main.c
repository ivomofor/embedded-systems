#include <stdio.h>
#include <stdint.h>
#include <limits.h>

int main(void)
{
    uint8_t led_state = 0;

    printf("Embedded Systems Learning Project - C23\n");

    printf("Initial LED state: %u\n", (unsigned int)led_state);

    led_state = 1;

    printf("LED state after turning it on: %u\n",
           (unsigned int)led_state);

    printf("Size of uint8_t: %zu byte(s)\n", sizeof(uint8_t));
    printf("Maximum uint8_t value: %u\n", (unsigned int)UINT8_MAX);

    return 0;
}