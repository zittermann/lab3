CC=gcc
CFLAGS=-Wall -pedantic-errors -std=gnu89 -O3
HEADERS=-I./

SRC=archivo.c clave.c semaforo.c 

build: clean avion panel

avion: clean
	$(CC) -o avion avion.c $(SRC) $(CFLAGS) $(HEADERS)

panel: clean
	$(CC) -o panel panel.c $(SRC) $(CFLAGS) $(HEADERS)

clean:
	rm -rf *.o *.txt avion panel