CXX = g++
CFLAGS = -Wall -I../../include/smartpointer
LDLIBS = 
OBJS = RefCounter.o
HEADERS = NullPointerException.h RefCounter.h SmartPointer.h

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

RefCounter.o: RefCounter.cpp
	$(CXX) -c $(CFLAGS) $^ -o $@

install: program
	mkdir -p ../../bin
	mv $(OBJS) ../../bin
	mv program ../../bin

clean:
	rm -rf $(OBJS)

distclean: clean
	rmdir -rf ../../bin ../../lib ../../doc