CFLAGS = -g -Wall
CC = gcc

objs = main.o menus.o patient.o database.o admin.o

all: main

main: $(objs)
	$(CC) $(CFLAGS) -o main $(objs) 

main.o: main.c

menus.o: menus.c menus.h

patient.o: patient.c patient.h

database.o: database.c database.h

admin.o: admin.c admin.h

.PHONY: clean
clean:
	rm main $(objs)
