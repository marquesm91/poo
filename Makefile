CC=g++
CFLAGS= -std=c++11

all: clean rexec coordenada.o forma.o forma1D.o linha.o circulo.o main.o tp2 clean

# Start creating the objects
main.o: main.cpp
	$(CC) -c main.cpp $(CFLAGS)

coordenada.o: Coordenadas.cpp Coordenadas.h
	$(CC) -c Coordenadas.cpp $(CFLAGS)

forma.o: Forma.cpp Forma.h
	$(CC) -c Forma.cpp $(CFLAGS)

forma1D.o: Forma1D.cpp Forma1D.h
	$(CC) -c Forma1D.cpp $(CFLAGS)

linha.o: Linha.cpp Linha.h
	$(CC) -c Linha.cpp $(CFLAGS)

circulo.o: Circulo.cpp Circulo.h
	$(CC) -c Circulo.cpp $(CFLAGS)
# End creating the objects

# Start creating the executables	
tp2:
	$(CC) $(CFLAGS) -o tp2 Coordenadas.o Forma.o Forma1D.o Linha.o Circulo.o main.o  
# End creating the executables

# Delete all objects files
clean:
	rm -rf *.o

# Delete all executables
rexec:
	find . -perm +100 -type f -delete

