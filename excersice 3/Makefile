# Compiler and target
CC = gcc
TARGET = alarm

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): alarm.c
	$(CC) -o $(TARGET) alarm.c

# Run the program
run: $(TARGET)
	./$(TARGET) 14:30 2025-01-10

# Clean up generated files
clean:
	rm -f $(TARGET)

# Phony targets
.PHONY: all run clean
