#include <stdio.h>
#include <stdint.h>

int main(void)
{
    volatile uint32_t status_register = 0;

    volatile uint32_t *register_pointer = &status_register;

    printf("Initial status: %u\n",
           (unsigned int)*register_pointer);

    *register_pointer = 1;

    printf("Updated status: %u\n",
           (unsigned int)*register_pointer);

    return 0;
}