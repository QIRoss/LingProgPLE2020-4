CC = g++
LD = g++

CFLAGS = -Wall -std=c++11
LFLAGS = -Wall -std=c++11

MAINOBJS = main.o
RESULTSOBJS = results.o

ALL = main.cgi\
	results.cgi

.c.o:
	$(CC) $(CFLAGS) -c $<

all: $(ALL)

main.cgi: $(MAINOBJS)
	$(LD) $(LFLAGS) -o $@ $(MAINOBJS)
	sudo cp $@ /usr/lib/cgi-bin/$@

results.cgi: $(RESULTSOBJS)
	$(LD) $(LFLAGS) -o $@ $(RESULTSOBJS)
	sudo cp $@ /usr/lib/cgi-bin/$@

clean:
	rm -f *.o *.cgi a.out
	sudo rm /usr/lib/cgi-bin/*  -f