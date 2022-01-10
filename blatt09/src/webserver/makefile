CXX = g++
CFLAGS = -Wall -I../../include/
LDLIBS = 
OBJS = server.o
HEADERS = 

.PHONY: all clean distclean run doc

all: fbtHttpd

run: install
	../../bin/fbtHttpd testfolder1 15151

doc: Doxyfile
	mkdir -p doc
	doxygen Doxyfile

Doxyfile:
	rmdir -rf doc
	mkdir -p doc
	doxygen -g

fbtHttpd: $(OBJS)
	$(CXX) -o $@ $^

server.o: server.cpp
	$(CXX) -c $(CFLAGS) $^ -o $@

install: fbtHttpd
	mkdir -p ../../bin
	cp -arv testfolder1 ../../bin
	mv $(OBJS) ../../bin
	mv fbtHttpd ../../bin

clean:
	rm -rf $(OBJS)

distclean: clean
	rm -rf ../../bin ../../lib ../../doc