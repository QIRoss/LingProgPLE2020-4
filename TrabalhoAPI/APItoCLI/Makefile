CC = g++
LD = g++

CFLAGS = -Wall -std=c++11
LFLAGS = -Wall -std=c++11

MAINOBJS =  main.o

ALL = main\
	
.c.o:
	$(CC) $(CFLAGS) -c $<

all: $(ALL)

main: $(MAINOBJS)
	$(LD) $(LFLAGS) -o $@ $(MAINOBJS)

clean:
	rm -f *.o $(ALL)