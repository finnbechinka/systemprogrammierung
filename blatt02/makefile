CC = gcc
CFLAGS = -ansi -pedantic -Wall -Iinclude
LDLIBS = -lm -lwiringPi 
OBJS = segmentanzeige.o TM1637.0

.PHONY: all clean distclean run doc

all: bin/segmentanzeige

run: bin/segmentanzeige
	bin/segmentanzeige

doc: Doxyfile
	doxygen Doxyfile

Doxyfile:
	doxygen -g

bin/segmentanzeige: src/ledanzeige/segmentanzeige.c src/ledanzeige/TM1637.c
	gcc -ansi -pedantic -Wall -Iinclude -lwiringPi -lm -o bin/segmentanzeige src/ledanzeige/segmentanzeige.c src/ledanzeige/TM1637.c
	
clean:
	rm -rf segmentanzeige $(OBJS) segmentanzeige

distclean: clean
	rm -rf bin/ledanzeige lib/ledanzeige doc/ledanzeige