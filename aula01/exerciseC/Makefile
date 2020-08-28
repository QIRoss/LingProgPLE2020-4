CC = g++
LD = g++

CFLAGS = -Wall -std=c11
LFLAGS = -Wall -std=c11

EXERCISEOBJS = agenda.o main.o

.c.o:
	$(CC) $(CFLAGS) -c $<

exercise: $(EXERCISEOBJS)
	$(LD) $(LFLAGS) -o $@ $(EXERCISEOBJS)

clean:
	rm -f *.o exercise