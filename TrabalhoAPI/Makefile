CC = g++
LD = g++

CFLAGS = -Wall -std=c++11
LFLAGS = -Wall -std=c++11

MAINOBJS = templateEngine.o main.o
IMGPREVIEWOBJS = templateEngine.o imgPreview.o
READDBOBJS = templateEngine.o readDb.o
WRITEDBOBJS = templateEngine.o writeDb.o
TESTOBJS = api.o

ALL = main\
	imgPreview\
	readDb\
	writeDb\
	test\

.c.o:
	$(CC) $(CFLAGS) -c $<

all: $(ALL)

main: $(MAINOBJS)
	$(LD) $(LFLAGS) -o $@ $(MAINOBJS)
	sudo cp $@ /usr/lib/cgi-bin/$@

imgPreview: $(IMGPREVIEWOBJS)
	$(LD) $(LFLAGS) -o $@ $(IMGPREVIEWOBJS)
	sudo cp $@ /usr/lib/cgi-bin/$@

readDb: $(READDBOBJS)
	$(LD) $(LFLAGS) -o $@ $(READDBOBJS)
	sudo cp $@ /usr/lib/cgi-bin/$@

writeDb: $(WRITEDBOBJS)
	$(LD) $(LFLAGS) -o $@ $(WRITEDBOBJS)
	sudo cp $@ /usr/lib/cgi-bin/$@


clean:
	rm -f *.o $(ALL)
	sudo rm /usr/lib/cgi-bin/*  -f