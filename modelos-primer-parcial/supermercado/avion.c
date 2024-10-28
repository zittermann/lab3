#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "semaforo.h"
#include "def.h"
#include "global.h"
#include "archivo.h"

int main(int argc, char const *argv[]) {
	
	int id_semaforo, id_avion, err;
	char origen[CHAR_LEN];
	char cod_vuelo[CHAR_LEN];

	if (argv[1] == NULL) {
		perror("Se debe proveer el ID de avion por parametro\n");
		exit(1);
	}

	id_avion = atoi(argv[1]);
	id_semaforo = creo_semaforo();

	if (id_avion == 1) {
		inicia_semaforo(id_semaforo, VERDE);
	}

	while(1) {

		espera_semaforo(id_semaforo);
		
		printf("Ingrese el codigo de la ciudad de origen: ");
		memset(origen, 0x00, sizeof(origen));
		scanf("%s", origen);

		memset(cod_vuelo, 0x00, sizeof(cod_vuelo));
		sprintf(cod_vuelo, "%d-%s", id_avion, origen);
		
		printf("Abriendo archivo\n");
		err = inAbrirArchivo(&fp_write, "aviones.txt", "a");

		if (err != 0) {
		
			printf("No se pudo abrir archivo desde VUELO %s\n", cod_vuelo);
		
		} else {

			inEscribirArchivo(cod_vuelo, &fp_write);
			inCerrarArchivo(&fp_write);
		}

		levanta_semaforo(id_semaforo);
	}

	return 0;
}
