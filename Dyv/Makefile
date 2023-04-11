CC=g++
CFLAGS=-O2

all: dyv clean


dyv: dyv.o vaca.o main.o referencia.o
	$(CC) $(CFLAGS) -o dyv $^

main.o: main.cpp dyv.h vaca.h
	$(CC) $(CFLAGS) -c main.cpp

dyv.o: dyv.cpp dyv.h vaca.h referencia.h
	$(CC) $(CFLAGS) -c dyv.cpp

referencia.o: referencia.cpp referencia.h vaca.h
	$(CC) $(CFLAGS) -c referencia.cpp

vaca.o: vaca.cpp vaca.h
	$(CC) $(CFLAGS) -c vaca.cpp

clean:
	rm -f *.o
