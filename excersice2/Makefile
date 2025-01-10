# Makefile for task 2

# Compiler
CC = gcc
TARGET = signal_handler

# Compiler flags
CFLAGS = -Wall -g

# Default target
all: $(TARGET)

# Build the target
$(TARGET): Task_2.c
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Clean up build files
clean:
	rm -f $(TARGET)
