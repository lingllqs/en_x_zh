CC = gcc
CFLAGS = -Wall
LDFLAGS = -lsqlite3
BUILD = build

SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)

TARGET = bin/dict

all: $(TARGET)

$(TARGET): $(OBJ)
	mkdir -p bin
	$(CC) -o $@ $^ $(LDFLAGS)

clean:
	rm -f src/*.o $(TARGET)
