CXX = g++
CFLAGS = -Wall -I../../include/ringbuffer
LDLIBS = 
OBJS = main.o CustomAllocator.o
HEADERS = ringbuffer.h CustomAllocator.h

.PHONY: all clean distclean run doc

all: program

run: install
	../../bin/program

doc: Doxyfile
	mkdir -p doc
	doxygen Doxyfile

Doxyfile:
	rmdir -rf doc
	mkdir -p doc
	doxygen -g

program: $(OBJS)
	$(CXX) -o $@ $^

main.o: main.cpp
	$(CXX) -c $(CFLAGS) $^ -o $@

CustomAllocator.o: CustomAllocator.cpp
	$(CXX) -c $(CFLAGS) $^ -o $@

install: program
	mkdir -p ../../bin
	mv $(OBJS) ../../bin
	mv program ../../bin

clean:
	rm -rf $(OBJS) ../../bin/program

distclean: clean
	rmdir -rf ../../bin/ringbuffer ../../lib/ringbuffer ../../doc/ringbuffer