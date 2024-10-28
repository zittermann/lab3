CC=gcc
CFLAGS=-Wall -pedantic-errors -std=gnu89 -O3
HEADERS=-I./

SRC=archivo.c clave.c semaforo.c 

build: clean cajero tesorero

cajero: clean
	$(CC) -o cajero cajero.c $(SRC) $(CFLAGS) $(HEADERS)

tesorero: clean
	$(CC) -o tesorero tesorero.c $(SRC) $(CFLAGS) $(HEADERS)

clean:
	rm -rf *.o *.dat cajero tesorero