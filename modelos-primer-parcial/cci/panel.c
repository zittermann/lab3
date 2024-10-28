#include <stdio.h>
#include <stdlib.h>
#include "global.h"
#include "def.h"
#include "semaforo.h"
#include "archivo.h"
#include "funciones.h"

int main(int argc, char const *argv[]) {
	
	int id_semaforo, id_panel, err;
	char current_message[CHAR_LEN];
	char filename[CHAR_LEN];

	if (argv[1] == NULL) {
		perror("Se debe proveer el ID de la caja por parametro\n");
		exit(1);
	}
	
	id_panel = atoi(argv[1]);
	
	memset(filename, 0x00, sizeof(filename));
	get_filename(id_panel, filename); /* Generate filename */

	memset(current_message, 0x00, sizeof(current_message));
	sprintf(current_message, "default");

	id_semaforo = creo_semaforo();

	while(1) {
		
		espera_semaforo(id_semaforo);

		update_panel(id_panel, current_message);

		levanta_semaforo(id_semaforo);
		usleep(500);

	}

	return 0;
}
