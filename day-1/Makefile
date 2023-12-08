
# VARIABLES

CC = g++
CFLAGS = -Wall -g
LDFLAGS = -lstdc++
TARGET = day-1

# RULES

all: $(TARGET)

$(TARGET): main.cpp
	$(CC) $(CFLAGS) -o $(TARGET) main.cpp $(LDFLAGS)

clean:
	rm -f $(TARGET)

.PHONY: all-clean
