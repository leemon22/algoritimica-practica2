CC=g++
CFLAGS=-O2

all: especifico clean


especifico: especifico.o vaca.o main.o
	$(CC) $(CFLAGS) -o especifico $^

main.o: main.cpp especifico.h vaca.h
	$(CC) $(CFLAGS) -c main.cpp

especifico.o: especifico.cpp especifico.h vaca.h
	$(CC) $(CFLAGS) -c especifico.cpp

vaca.o: vaca.cpp vaca.h
	$(CC) $(CFLAGS) -c vaca.cpp

clean:
	rm -f *.o
