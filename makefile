CC=gcc
CFLAGS=-I.

all: app

app: app.o preprocessing.o reader_management.o
	$(CC) -o app app.o preprocessing.o reader_management.o
	rm -f *.o

app.o: app.c preprocessing.h reader_management.h
	$(CC) -c app.c

preprocessing.o: preprocessing.c preprocessing.h
	$(CC) -c preprocessing.c

reader_management.o: reader_management.c reader_management.h
	$(CC) -c reader_management.c

clean:
	rm -f *.o app