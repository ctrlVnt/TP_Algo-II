CC=gcc
LD=gcc
CFLAGS=-g -Wall -pedantic -std=c11 -Werror
LIBS=-lm
# gtk+-2.0 pour GTK2 
# gtk+-3.0 pour GTK3 (choisi ici)
GTKCFLAGS:=$(shell pkg-config --cflags gtk+-3.0)
GTKLIBS:=$(shell pkg-config --libs gtk+-3.0)

all: main

main: main.o points.o particules.o forces.o obstacles.o arbre.o
	$(LD) main.o points.o particules.o forces.o obstacles.o arbre.o $(GTKLIBS) $(LIBS) -o main

main.o: main.c
	$(CC) -c $(CFLAGS) $(GTKCFLAGS) main.c -o main.o

points.o: points.c points.h 
	$(CC) -c $(CFLAGS) $(GTKCFLAGS) points.c -o points.o

obstacles.o: obstacles.c obstacles.h 
	$(CC) -c $(CFLAGS) $(GTKCFLAGS) obstacles.c -o obstacles.o

arbre.o: arbre.c arbre.h 
	$(CC) -c $(CFLAGS) $(GTKCFLAGS) arbre.c -o arbre.o

particules.o: particules.c particules.h 
	$(CC) -c $(CFLAGS) $(GTKCFLAGS) particules.c -o particules.o

forces.o: forces.c forces.h 
	$(CC) -c $(CFLAGS) $(GTKCFLAGS) forces.c -o forces.o

clean:
	rm -f main main.o particules.o forces.o arbre.o points.o obstacles.o

fullclean: clean
	rm -f *~ *.fig.bak
