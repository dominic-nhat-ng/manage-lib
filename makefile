CC=gcc
CFLAGS=-I.

all: app

app: app.o preprocessing.o
	$(CC) -o app app.o preprocessing.o

app.o: app.c preprocessing.h
	$(CC) -c app.c

preprocessing.o: preprocessing.c preprocessing.h
	$(CC) -c preprocessing.c

clean:
	rm -f *.o app