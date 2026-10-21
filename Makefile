CC = gcc

CFLAGS = -std=c2x -Wall -Wextra -Wpedantic -g -Iinclude

TARGET = embedded_demo

SOURCES = src/main.c src/led.c

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

clean:
	rm -f $(TARGET) main.o led.o
