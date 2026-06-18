CC = gcc
CFLAGS = -Wall -Wextra -g -std=c11 -Iinclude

SRCS = src/main.c src/catalogue.c src/recherche.c src/persistance.c src/ui.c
OBJS = $(SRCS:src/%.c=build/%.o)
TARGET = bin/bibliotheque

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p bin
	$(CC) $(CFLAGS) -o $@ $^

build/%.o: src/%.c
	@mkdir -p build
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf build bin

.PHONY: all clean
