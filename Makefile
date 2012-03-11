CC=gcc
CFLAGS=-Wall -Wextra -Wno-missing-braces

all: test

test: qr_encode.c main.c
	$(CC) $(CFLAGS) qr_encode.c main.c -o test

clean:
	rm -f test
