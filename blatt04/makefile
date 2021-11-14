CC = gcc
CFLAGS = -ansi -pedantic -Wall -Iinclude
LDLIBS = -lm -lwiringPi 
OBJS = segmentanzeige.o TM1637.o

.PHONY: all clean distclean run doc

all: program

run: install
	bin/program

doc: Doxyfile
	mkdir -p doc
	doxygen Doxyfile

Doxyfile:
	doxygen -g

program: src/ledanzeige/segmentanzeige.c src/ledanzeige/TM1637.c include/ledanzeige/segmentanzeige.h include/ledanzeige/TM1637.h include/ledanzeige/TM1637_intern.h
	$(CC) $(CFLAGS) $(LDLIBS) -o program src/ledanzeige/segmentanzeige.c src/ledanzeige/TM1637.c

install: program
	mkdir -p bin
	mv program bin

clean:
	rm -rf program $(OBJS)

distclean: clean
	rmdir -rf bin/ledanzeige lib/ledanzeige doc/ledanzeige