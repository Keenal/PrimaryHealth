CFLAGS = -g -Wall
CC = gcc

objs = main.o

all: main

main: main.o
	$(CC) $(CFLAGS) -o main main.o

main.o: main.c

.PHONY: clean
clean:
	rm main $(objs)
