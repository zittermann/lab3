CC=gcc
CFLAGS=-Wall -pedantic-errors -std=gnu89 -O3
HEADERS=-I./

SRC=archivo.c clave.c semaforo.c funciones.c

build: clean cci panel

cci: clean
	$(CC) -o cci cci.c $(SRC) $(CFLAGS) $(HEADERS)

panel: clean
	$(CC) -o panel panel.c $(SRC) $(CFLAGS) $(HEADERS)

clean:
	rm -rf *.o *.txt cci panel