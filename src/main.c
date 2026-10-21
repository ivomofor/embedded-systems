#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint8_t led_state = 0;
    uint8_t *led_pointer = NULL;

    led_pointer = &led_state;

    *led_pointer = 1;

    printf("LED state: %u\n",
           (unsigned int)led_state);

    *led_pointer = 0;

    printf("LED state: %u\n",
           (unsigned int)led_state);

    return 0;
}