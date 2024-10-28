#include <stdlib.h>
#include <stdlib.h>
#include "clave.h"
#include "def.h"
#include "memoria.h"
#include <signal.h>

static volatile int stop = 0;

void intHandler(int value) {
	stop = 1;
}

int main(int argc, char const *argv[]) {
	
	int id_memoria;
	dato *memoria = NULL;
	int i, aleatorio;

	signal(SIGINT, intHandler);

	memoria = (dato*)creo_memoria(sizeof(dato)*CANTIDAD, &id_memoria, DEFAULT_KEY);

	srand(time(NULL));
	while(!stop) {
		printf("Escribimos en la memoria\n");

		for (i=0; i<CANTIDAD; i++) {
			aleatorio = rand()%(HASTA-DESDE)+DESDE;
			memoria[i].numero = aleatorio ;
			memoria[i].letra = 0x41 + aleatorio ;

			printf("Escrito %d %c\n", memoria[i].numero, memoria[i].letra);
		}
		printf("Dejamos de escribir en la memoria\n");
		sleep (10);
	}
	
	/*
		Terminada de usar la memoria compartida, la liberamos.
	*/
	shmdt ((char *)memoria);
	shmctl (id_memoria, IPC_RMID, (struct shmid_ds *)NULL);
	return 0;
}
