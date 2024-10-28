#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "semaforo.h"
#include "archivo.h"
#include "def.h"
#include <unistd.h>
#include <string.h>

int main(int argc, char const *argv[]) {
	
	FILE* file = NULL;
	int i, id_semaforo, id_cajero;
	char str[200+1];
	char filename[15];

	int importe, cant_depositos, es_cheque;

	if (argv[1] == NULL) {
		perror("Se debe proveer el numero de cajero por parametro");
		exit(1);
	}

	id_cajero = atoi(argv[1]);

	memset(filename, 0x00, sizeof(filename));
	sprintf(filename, "cajero%d.dat", id_cajero);

	id_semaforo = creo_semaforo();

	if (id_cajero == 1) {
		inicia_semaforo(id_semaforo, VERDE);
	}

	srand(time(NULL));

	while(1) {

		espera_semaforo(id_semaforo); 
		
		cant_depositos = (rand() % (MAX_CANT_DEPOSITOS - MIN_CANT_DEPOSITOS)) + MIN_CANT_DEPOSITOS; /* 10 to 20 */
		
		printf("Abriendo archivo... desde cajero-%d\n", id_cajero);
		inAbrirArchivo(&file, filename, "a");

		for (i=0; i<cant_depositos; i++) {
			
			importe = (rand() % (MAX_IMPORTE - MIN_IMPORTE)) + MIN_IMPORTE; /* 100 to 500 */
			es_cheque = rand() % 2;

			memset(str, 0x00, sizeof(str));
			sprintf(str, "%d\t%d", importe, es_cheque);
			
			inEscribirArchivo(str, file);
		}

		inCerrarArchivo(&file);
		printf("Cierro archivo desde cajero-%d\n", id_cajero);

		levanta_semaforo(id_semaforo);
		usleep((rand() % 1500) + 1000); /* 1000ms to 2500ms*/
	};

	return 0;	
}
