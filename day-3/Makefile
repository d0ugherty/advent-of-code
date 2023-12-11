
# VARIABLES

CC = g++
CFLAGS = -Wall -g
LDFLAGS = -lstdc++
TARGET = day-3

# RULES

all: $(TARGET)

$(TARGET): day3.cpp
	$(CC) $(CFLAGS) -o $(TARGET) day3.cpp $(LDFLAGS)

clean:
	rm -f $(TARGET)

.PHONY: all-clean
