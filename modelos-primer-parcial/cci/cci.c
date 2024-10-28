#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "semaforo.h"
#include "def.h"
#include "funciones.h"

int main(int argc, char const *argv[]) {
	
	int id_semaforo, err, opcion, id_panel;
	char str[CHAR_LEN];

	id_semaforo = creo_semaforo();
	inicia_semaforo(id_semaforo, VERDE);

	while (1) {

		espera_semaforo(id_semaforo);
		opcion = display_menu();

		printf("\nIngrese ID del panel: ");
		scanf("%d", &id_panel);

		memset(str, 0x00, sizeof(str)); /* str limpio antes de cualquier llamado*/
		if (opcion == 1) {
			
			read_panel(id_panel, str);
			printf("Mesaje del panel NR%d: %s", id_panel, str);

		} else {

			printf("Ingrese mensaje a guardar: ");
			scanf("%s", str);
			write_panel(id_panel, str);
		}

		levanta_semaforo(id_semaforo);
		usleep(500);

	}

	return 0;
}
