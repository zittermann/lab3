#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "semaforo.h"
#include "archivo.h"
#include "def.h"
#include <unistd.h>
#include <string.h>

int main(int argc, char const *argv[]) {
	
	FILE* file = NULL;
	int i, id_semaforo, r;
	char str[200+1];

	id_semaforo = creo_semaforo();
	inicia_semaforo(id_semaforo, VERDE);
	srand(time(NULL));

	while(1) {
		espera_semaforo(id_semaforo); 

		r = (rand() % 10); /* 0 to 10 */

		printf("Abriendo archivo... desde carga\n");
		inAbrirArchivo(&file, "lote.dat", "ab");

		for (i=0; i<r; i++) {
			
			memset(str, 0x00, sizeof(str));
			sprintf(str, "%d-TAIWAN-GERMAN", i+1000);
			
			inEscribirArchivo(str, file);
		}

		inCerrarArchivo(&file);
		printf("Cierro archivo desde carga.\n");

		levanta_semaforo(id_semaforo);
		usleep(50*r);

	};

	return 0;	
}
