CFLAGS = -g -Wall
CC = gcc

objs = main.o menus.o

all: main

main: main.o menus.o
	$(CC) $(CFLAGS) -o main main.o menus.o

main.o: main.c

menus.o: menus.c menus.h

.PHONY: clean
clean:
	rm main $(objs)
