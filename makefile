CFLAGS = -g -Wall
CC = gcc

objs = main.o user.o database.o

all: main

main: $(objs)
	$(CC) $(CFLAGS) -o main main.o user.o database.o

main.o: main.c

user.o: user.c user.h

database.o: database.c database.h

.PHONY: clean
clean:
	rm main $(objs)