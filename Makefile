CC=gcc
CFLAGS=-Wall -Wextra -g -ggdb3
CHECKLIBS = -lcheck -lrt -lpthread -lm

all: test tests

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

test: qr_encode.o test.o
	$(CC) $(CFLAGS) qr_encode.c test.c -o test

tests: qr_encode.o tests.o
	$(CC) qr_encode.o tests.o $(CHECKLIBS) -o tests

clean:
	rm -f *.o test tests
