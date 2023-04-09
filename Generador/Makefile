CC=gcc
# CFLAGS=-O2 -Wall -lstdc++ -lm
CFLAGS=-O2 -Wall -static-libstdc++ -lm

all: generador clean

generador: generador.o main.o
	$(CC) $(CFLAGS) -o generador $^

generador.o: generador.cpp generador.h
	$(CC) $(CFLAGS) -c generador.cpp
	
main.o: main.cpp generador.h
	$(CC) $(CFLAGS) -c main.cpp

clean:
	rm -f *.o
