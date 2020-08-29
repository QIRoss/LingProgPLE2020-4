CC = g++
LD = g++

CFLAGS = -Wall -std=gnu++17
LFLAGS = -Wall -std=gnu++17

EXERCISEOBJS = agenda.o main.o

.c.o:
	$(CC) $(CFLAGS) -c $<

exercise: $(EXERCISEOBJS)
	$(LD) $(LFLAGS) -o $@ $(EXERCISEOBJS)

clean:
	rm -f *.o exercise