CC=gcc
CHECKLIBS = -lcheck -lrt -lpthread -lm

OPTFLAGS  = -Os -g

CFLAGS   += $(OPTFLAGS) \
            -W \
            -Wall \
            -Wextra \
            -Wimplicit-function-declaration \
            -Wredundant-decls \
            -Wstrict-prototypes \
            -Wundef \
            -Wshadow \
            -Wpointer-arith \
            -Wformat \
            -Wreturn-type \
            -Wsign-compare \
            -Wmultichar \
            -Wformat-nonliteral \
            -Winit-self \
            -Wuninitialized \
            -Wformat-security \
            -Werror \
            -DQR_MAX_VERSION=0

all: test tests

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

test: qr_encode.o test.o
	$(CC) $(CFLAGS) qr_encode.c test.c -o test

tests: qr_encode.o tests.o
	$(CC) qr_encode.o tests.o $(CHECKLIBS) -o tests

clean:
	rm -f *.o test tests
