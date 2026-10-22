#include "gpio.h"

#include <stdio.h>

int main(void)
{
    printf("Running GPIO tests...\n");

    /* Test 1: Register starts at zero. */
    if (gpio_read_register() != 0)
    {
        printf("FAIL: Initial register should be zero.\n");
        return 1;
    }

    printf("PASS: Initial register is zero.\n");

    /* Test 2: Turn on pin 2. */
    gpio_set_pin(2);

    if (gpio_is_pin_set(2) != 1)
    {
        printf("FAIL: Pin 2 should be ON.\n");
        return 1;
    }

    printf("PASS: Pin 2 turns ON.\n");

    /* Test 3: Turn off pin 2. */
    gpio_clear_pin(2);

    if (gpio_is_pin_set(2) != 0)
    {
        printf("FAIL: Pin 2 should be OFF.\n");
        return 1;
    }

    printf("PASS: Pin 2 turns OFF.\n");

    /* Test 4: Invalid pin must not change the register. */
    gpio_set_pin(8);

    if (gpio_read_register() != 0)
    {
        printf("FAIL: Invalid pin changed the register.\n");
        return 1;
    }

    printf("PASS: Invalid pin does not change the register.\n");

    /* Test 5: Reading an invalid pin returns zero. */
    if (gpio_is_pin_set(8) != 0)
    {
        printf("FAIL: Invalid pin read should return zero.\n");
        return 1;
    }

    printf("PASS: Invalid pin read returns zero.\n");

    /* Test 6: Clearing one pin must not affect another pin. */
    gpio_set_pin(1);
    gpio_set_pin(3);

    gpio_clear_pin(1);

    if (gpio_is_pin_set(1) != 0)
    {
        printf("FAIL: Pin 1 should be OFF.\n");
        return 1;
    }

    if (gpio_is_pin_set(3) != 1)
    {
        printf("FAIL: Clearing pin 1 affected pin 3.\n");
        return 1;
    }

    printf("PASS: Clearing one pin does not affect another.\n");

    /* Test 7: Toggling an OFF pin turns it ON. */
    gpio_clear_pin(3);
    gpio_toggle_pin(3);

    if (gpio_is_pin_set(3) != 1)
    {
        printf("FAIL: Toggling an OFF pin should turn it ON.\n");
        return 1;
    }

    printf("PASS: Toggling an OFF pin turns it ON.\n");

    /* Test 8: Toggling an ON pin turns it OFF. */
    gpio_toggle_pin(3);

    if (gpio_is_pin_set(3) != 0)
    {
        printf("FAIL: Toggling an ON pin should turn it OFF.\n");
        return 1;
    }

    printf("PASS: Toggling an ON pin turns it OFF.\n");

    printf("All GPIO tests passed!\n");

    return 0;
}