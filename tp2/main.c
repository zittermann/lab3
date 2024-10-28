#include <stdio.h>
#include "semaforo.h"
#include "def.h"

int main(int argc, char const *argv[]) {
	
	int i, id_semaforo;
	id_semaforo = creo_semaforo();

	inicia_semaforo(id_semaforo, VERDE);
	
	while(1) {
		espera_semaforo(id_semaforo);
		printf("Seccion critica\n");
		sleep (1);
		levanta_semaforo(id_semaforo);
		sleep (10);
	}
	return 0;	
}
