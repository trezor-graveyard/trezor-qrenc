CC=gcc
CFLAGS=-Wall -Wextra

all: test

test: qr_encode.c test.c
	$(CC) $(CFLAGS) qr_encode.c test.c -o test

clean:
	rm -f test
