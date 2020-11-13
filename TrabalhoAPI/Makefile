CC = g++
LD = g++

CFLAGS = -Wall -std=c++11
LFLAGS = -Wall -std=c++11

MAINOBJS = templateEngine.o main.o database.o
IMGPREVIEWOBJS = templateEngine.o imgPreview.o database.o
READDBOBJS = templateEngine.o readDb.o database.o
WRITEDBOBJS = templateEngine.o writeDb.o database.o

ALL = main\
	imgPreview\
	readDb\
	writeDb\
	
.c.o:
	$(CC) $(CFLAGS) -c $<

all: $(ALL)

main: $(MAINOBJS)
	$(LD) $(LFLAGS) -o $@ $(MAINOBJS) -lcgicc -lpqxx -lpq
	sudo cp $@ /usr/lib/cgi-bin/$@

imgPreview: $(IMGPREVIEWOBJS)
	$(LD) $(LFLAGS) -o $@ $(IMGPREVIEWOBJS) -lcgicc -lpqxx -lpq
	sudo cp $@ /usr/lib/cgi-bin/$@

readDb: $(READDBOBJS)
	$(LD) $(LFLAGS) -o $@ $(READDBOBJS) -lcgicc -lpqxx -lpq
	sudo cp $@ /usr/lib/cgi-bin/$@

writeDb: $(WRITEDBOBJS)
	$(LD) $(LFLAGS) -o $@ $(WRITEDBOBJS) -lcgicc -lpqxx -lpq
	sudo cp $@ /usr/lib/cgi-bin/$@


clean:
	rm -f *.o $(ALL)
	sudo rm /usr/lib/cgi-bin/*  -f