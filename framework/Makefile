CC=gcc
CFLAGS=-Wall -pedantic-errors -std=gnu89 -O3 -pthread
HEADERS=-I./

SRC=archivo.c clave.c semaforo.c funciones.c memoria.c cola.c

build: clean banco cajero

banco: clean
	$(CC) -o banco banco.c $(SRC) $(CFLAGS) $(HEADERS)

cajero: clean
	$(CC) -o cajero cajero.c $(SRC) $(CFLAGS) $(HEADERS)

clean:
	rm -rf *.o *.txt cajero banco