CC = g++
LD = g++

CFLAGS = -Wall -std=c++11
LFLAGS = -Wall -std=c++11

EXERCISEOBJS = linha.o ponto.o main.o

.c.o:
	$(CC) $(CFLAGS) -c $<

exercise: $(EXERCISEOBJS)
	$(LD) $(LFLAGS) -o $@ $(EXERCISEOBJS)

clean:
	rm -f *.o exercise