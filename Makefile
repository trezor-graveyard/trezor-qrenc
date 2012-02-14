all: test

test: qr_encode.c main.c
	gcc qr_encode.c main.c -o test

clean:
	rm -f test
