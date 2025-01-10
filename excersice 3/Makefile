# Compiler and target
CC = gcc
TARGET = task_3

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): task_3.c
	$(CC) -o $(TARGET) task_3.c

# Run the program
run: $(TARGET)
	./$(TARGET) 14:30 2025-01-10

# Clean up generated files
clean:
	rm -f $(TARGET)
