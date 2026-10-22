#include "gpio.h"

static uint8_t gpio_register = 0;

void gpio_set_pin(uint8_t pin)
{
    if (pin < 8)
    {
        gpio_register |= (uint8_t)(1u << pin);
    }
}

void gpio_clear_pin(uint8_t pin)
{
    if (pin < 8)
    {
        gpio_register &= (uint8_t)~(1u << pin);
    }
}

uint8_t gpio_read_register(void)
{
    return gpio_register;
}

uint8_t gpio_is_pin_set(uint8_t pin)
{
    if (pin >= 8)
    {
        return 0;
    }

    return (gpio_register & (uint8_t)(1u << pin)) != 0;
}
