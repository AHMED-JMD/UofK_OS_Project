# Compiler and target
CC = gcc
TARGET = task_1

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): task_1.c
	$(CC) -o $(TARGET) task_1.c

# Run the program
run: $(TARGET)
	./$(TARGET)

# Clean up generated files
clean:
	rm -f $(TARGET)
