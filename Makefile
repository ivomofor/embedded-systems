CC = gcc

CFLAGS = -std=c2x -Wall -Wextra -Wpedantic -g -Iinclude

TARGET = embedded_demo
SOURCES = src/main.c src/led.c src/gpio_sim.c

GPIO_TEST_TARGET = tests/test_gpio
GPIO_TEST_SOURCE = tests/test_gpio.c
GPIO_TEST_SUPPORT = src/gpio_sim.c

LED_TEST_TARGET = tests/test_led
LED_TEST_SOURCE = tests/test_led.c
LED_TEST_SUPPORT = src/led.c src/gpio_sim.c

.PHONY: all clean test

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

$(GPIO_TEST_TARGET): $(GPIO_TEST_SOURCE) $(GPIO_TEST_SUPPORT) include/gpio.h
	$(CC) $(CFLAGS) $(GPIO_TEST_SOURCE) $(GPIO_TEST_SUPPORT) -o $(GPIO_TEST_TARGET)

$(LED_TEST_TARGET): $(LED_TEST_SOURCE) $(LED_TEST_SUPPORT) include/led.h include/gpio.h
	$(CC) $(CFLAGS) $(LED_TEST_SOURCE) $(LED_TEST_SUPPORT) -o $(LED_TEST_TARGET)

test: $(GPIO_TEST_TARGET) $(LED_TEST_TARGET)
	./$(GPIO_TEST_TARGET)
	./$(LED_TEST_TARGET)

clean:
	rm -f $(TARGET) $(GPIO_TEST_TARGET) $(LED_TEST_TARGET) main.o led.o gpio.o gpio_sim.o