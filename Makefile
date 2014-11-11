CC=g++
CFLAGS= -std=c++11

all: clean rexec coordenada.o forma.o main.o tp2

# Start creating the objects
main.o: main.cpp
	$(CC) -c main.cpp $(CFLAGS)

forma.o: forma.cpp forma.h
	$(CC) -c forma.cpp $(CFLAGS)

coordenada.o: coordenada.cpp coordenada.h
	$(CC) -c coordenada.cpp $(CFLAGS)
# End creating the objects

# Start creating the executables	
tp2:
	$(CC) $(CFLAGS) -o tp2 forma.o main.o coordenada.o
# End creating the executables

# Delete all objects files
clean:
	rm -rf *.o

# Delete all executables
rexec:
	find . -perm +100 -type f -delete

