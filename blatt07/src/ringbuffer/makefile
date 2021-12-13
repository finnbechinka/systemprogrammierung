CXX = g++
CFLAGS = -std=c11 -pedantic -Wall -Iinclude
LDLIBS = -lm
OBJS = 

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

program: bin/ringbuffer.o bin/main.o
	g++ bin/ringbuffer.o bin/main.o -o bin/program

bin/ringbuffer.o: src/ringbuffer/ringbuffer.cpp include/ringbuffer/CustomAllocator.h
	g++ -Iinclude -c src/ringbuffer/ringbuffer.cpp

bin/bin/main.o: src/ringbuffer/main.cpp include/ringbuffer/CustomAllocator.h
	g++ -Iinclude -c src/ringbuffer/main.cpp

install: program
	mkdir -p bin

clean:
	rm -rf bin/ringbuffer.o bin/main.o bin/program

distclean: clean
	rmdir -rf bin/ringbuffer lib/ringbuffer doc/ringbuffer