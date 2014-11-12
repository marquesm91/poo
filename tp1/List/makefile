CC=g++
CFLAGS=-W -Wall -ansi -pedantic
LDFLAGS=-lm

all: list main list_e

remove_objects:
	rm -rf *.o

clean:
	ls | grep -v "\." | grep -v makefile | xargs rm

list: list.cpp list.h
	$(CC) $(CFLAGS) -c list.cpp

main: main.cpp list.h
	$(CC) $(CFLAGS) -c main.cpp

list_e:
	$(CC) $(CFLAGS) main.o list.o ${LDFLAGS} -o list
