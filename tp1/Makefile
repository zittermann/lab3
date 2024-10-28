CC=gcc

CFLAGS=-Wall -pedantic-errors -std=gnu89 -O3

HEADERS=-I./

build: clean carga reserva

carga: clean
	$(CC) -o carga carga.c archivo.c clave.c semaforo.c $(CFLAGS) $(HEADERS)

reserva: clean
	$(CC) -o reserva reserva.c archivo.c clave.c semaforo.c $(CFLAGS) $(HEADERS)

clean:
	rm -rf *.o carga reserva