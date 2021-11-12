CC=gcc
SHELL=/bin/bash
CFLAGS=-O0 -g -D_FORTIFY_SOURCE=2 -Wall -Werror -Wl,-z,relro -Wl,-z,now

all: test

test: test.c deque.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	@rm test