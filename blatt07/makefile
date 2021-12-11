CC = gcc
CFLAGS = -std=c11 -pedantic -Wall -Iinclude
LDLIBS = -lm
OBJS = ringbuffer.o

.PHONY: all clean distclean run doc

all: program

run: install
	bin/program

doc: Doxyfile
	mkdir -p doc
	doxygen Doxyfile

Doxyfile:
	rmdir -rf doc
	mkdir -p doc
	doxygen -g

program: src/ringbuffer/ringbuffer.c include/ringbuffer/ringbuffer.h
	$(CC) $(CFLAGS) $(LDLIBS) -o program src/ringbuffer/ringbuffer.c include/ringbuffer/ringbuffer.h

install: program
	mkdir -p bin
	mv program bin

clean:
	rm -rf $(OBJS) bin/program

distclean: clean
	rmdir -rf bin/ringbuffer lib/ringbuffer doc/ringbuffer