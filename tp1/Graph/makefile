CC=g++
CFLAGS=-W -Wall -ansi -pedantic
LDFLAGS=-lm

all: graph.o graph_e

remove_objects:
	rm -rf *.o

clean:
	ls | grep -v "\." | grep -v makefile | xargs rm

graph.o: graph.cpp stack.h queue.h graph.h
	$(CC) $(CFLAGS) -c graph.cpp
	
graph_e:
	$(CC) $(CFLAGS) graph.o ${LDFLAGS} -o graph
