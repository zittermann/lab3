#include "semaforo.h"
#include "def.h"
#include "archivo.h"
#include "global.h"
#include "funciones.h"

int main(int argc, char const *argv[]) {
	
	int id_semaforo, id_caja, err;
	char filename[CHAR_LEN];
	char str[CHAR_LEN];

	if (argv[1] == NULL) {
		perror("Se debe proveer el ID de la caja por parametro\n");
		exit(1);
	}

	id_caja = atoi(argv[1]);
	
	/* Set filename */
	memset(filename, 0x00, sizeof(filename));
	sprintf(filename, "caja%d.dat", id_caja);

	id_semaforo = creo_semaforo();

	while(1) {

		espera_semaforo(id_semaforo);

		err = inAbrirArchivo(&fp_read, filename, "r");

		if (err != 0) {
			perror("No se puedo abrir el archivo, probablemente porque no existe\n");
		}

	}

	return 0;
}
