CFLAGS = -g -Wall
CC = gcc

objs = main.o user.o

all: main

main: main.o user.o
	$(CC) $(CFLAGS) -o main main.o user.o

main.o: main.c

user.o: user.c user.h

.PHONY: clean
clean:
	rm main $(objs)