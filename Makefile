CC = gcc

CFLAGS = -std=c2x -Wall -Wextra -Wpedantic -g -Iinclude

TARGET = embedded_demo
SOURCES = src/main.c src/led.c src/gpio.c

TEST_TARGET = tests/test_gpio
TEST_SOURCE = tests/test_gpio.c
TEST_SUPPORT = src/gpio.c

.PHONY: all clean test

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

$(TEST_TARGET): $(TEST_SOURCE) $(TEST_SUPPORT) include/gpio.h
	$(CC) $(CFLAGS) $(TEST_SOURCE) $(TEST_SUPPORT) -o $(TEST_TARGET)

test: $(TEST_TARGET)
	./$(TEST_TARGET)

clean:
	rm -f $(TARGET) $(TEST_TARGET) main.o led.o gpio.o
