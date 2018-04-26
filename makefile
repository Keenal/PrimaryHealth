CFLAGS = -g -Wall
CC = gcc

objs = main.o menus.o patient.o database.o admin.o doc.o nurse.o helpers.o

all: main

main: $(objs)
	$(CC) $(CFLAGS) -o main $(objs) 

main.o: main.c

menus.o: menus.c menus.h

patient.o: patient.c patient.h

database.o: database.c database.h

admin.o: admin.c admin.h

doc.o: doc.c doc.h

nurse.o: nurse.c nurse.h

helpers.o: helpers.c helpers.h

.PHONY: clean
clean:
	rm main $(objs)
