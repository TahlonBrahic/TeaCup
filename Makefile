# Define compiler and compiler flags
CC = gcc
CFLAGS = -g -Wall

# Target executable name
TARGET = TeaCup

# All C files in root directory
SRCS = $(wildcard *.c)

# Object files
OBJS = $(SRCS:.c=.o)

# Default Target
all: $(TARGET)

$(TARGET): $(OBJS)
    $(CC) $(CFLAGS) -o $@ $^

# Obtain object files
%.o: %.c    
    $(CC) $(CFLAGS) -c $< -o $@

# Clean Target
clean:
    rm -f $(TARGET) $(OBJS)

.PHONY: all clean