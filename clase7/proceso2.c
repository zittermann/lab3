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
	int i,j;

	signal(SIGINT, intHandler);
	
	memoria = (dato*)creo_memoria(sizeof(dato)*CANTIDAD, &id_memoria, DEFAULT_KEY);
	
	/*
		Vamos leyendo el valor de la memoria con esperas de un segundo
		y mostramos en pantalla dicho valor. Debería ir cambiando según
		p1 lo va modificando.
	*/
	while(!stop) {

		printf("leemos la memoria\n");
		
		for (i=0; i<CANTIDAD; i++) {
			printf("Leido %d %c\n", memoria[i].numero, memoria[i].letra);
		}

		printf("Dejamos de leer la memoria\n");
		sleep (1);
	}

	/* Terminada de usar la memoria compartida, la liberamos. */
	shmdt ((char *)memoria);
	shmctl (id_memoria, IPC_RMID, (struct shmid_ds *)NULL);
	return 0;

}

