CC = g++
LD = g++

CFLAGS = -Wall -std=c++11
LFLAGS = -Wall -std=c++11

MAINOBJS = main.o

.c.o:
	$(CC) $(CFLAGS) -c $<

main: $(MAINOBJS)
	$(LD) $(LFLAGS) -o $@ $(MAINOBJS)
	sudo cp $@ /usr/lib/cgi-bin/$@

clean:
	rm -f *.o main a.out
	sudo rm /usr/lib/cgi-bin/*  -f