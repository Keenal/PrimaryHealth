CFLAGS = -g -Wall
CC = gcc

objs = main.o menus.o user.o

all: main

main: main.o menus.o user.o
	$(CC) $(CFLAGS) -o main main.o menus.o user.o

main.o: main.c

menus.o: menus.c menus.h

user.o: user.c user.h

.PHONY: clean
clean:
	rm main $(objs)
