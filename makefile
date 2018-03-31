CFLAGS = -g -Wall
CC = gcc

objs = main.o menus.o

all: main

main: $(objs)
	$(CC) $(CFLAGS) -o main $(objs) 

main.o: main.c

menus.o: menus.c menus.h

.PHONY: clean
clean:
	rm main $(objs)
