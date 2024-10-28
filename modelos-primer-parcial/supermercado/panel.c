#include <stdio.h>
#include <stdlib.h>
#include "global.h"
#include "def.h"
#include "semaforo.h"
#include "archivo.h"

int main(int argc, char const *argv[]) {
	
	int id_semaforo, err;
	char str[CHAR_LEN];

	id_semaforo = creo_semaforo();

	while(1) {

		espera_semaforo(id_semaforo);

		err = inAbrirArchivo(&fp_read, "aviones.txt", "r");
		if (err != 0) {

			printf("No se pudo abrir archivo desde PANEL\n");

		} else {

			memset(str, 0x00, sizeof(str));
			while(inLeerArchivo(str, CHAR_LEN, &fp_read)) {

				printf("%s", str);
				
			}
		}

		inCerrarArchivo(&fp_read);
		inEliminarArchivo("aviones.txt");

		levanta_semaforo(id_semaforo);
		usleep(500);

	}

	return 0;
}
