#Project 1: Roman to Arabic number converter
#Programmer: Ian Royer
#Course: S18 CSC111
#Professor: Dr. Lee

SOURCES = mync.c r2a.c a2r.c
OBJECTS = mync.o r2a.o a2r.o
HEADERS = mync.h
CFLAGS = -g -Wall

mync: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o mync

clean:
	rm -fR *o mync
