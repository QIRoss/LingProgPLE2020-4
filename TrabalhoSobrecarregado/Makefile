CC = g++
LD = g++

CFLAGS = -Wall -std=c++11
LFLAGS = -Wall -std=c++11

MAINOBJS = catalogo.o main.o

.c.o:
	$(CC) $(CFLAGS) -c $<

main: $(MAINOBJS)
	$(LD) $(LFLAGS) -o $@ $(MAINOBJS)

clean:
	rm -f *.o main a.out