CC=gcc
CFLAGS=-Wall -pedantic-errors -std=gnu89 -O3
HEADERS=-I./

SRC=archivo.c clave.c semaforo.c funciones.c memoria.c

build: clean proceso1 proceso2

proceso1: clean
	$(CC) -o proceso1 proceso1.c $(SRC) $(CFLAGS) $(HEADERS)

proceso2: clean
	$(CC) -o proceso2 proceso2.c $(SRC) $(CFLAGS) $(HEADERS)

clean:
	rm -rf *.o *.txt proceso1 proceso2