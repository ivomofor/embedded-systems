#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>

void gpio_set_pin(uint8_t pin);
void gpio_clear_pin(uint8_t pin);
uint8_t gpio_read_register(void);
uint8_t gpio_is_pin_set(uint8_t pin);

#endif

