#include "semaforo.h"
#include "def.h"
#include "archivo.h"
#include "global.h"
#include "funciones.h"

struct productos {
	
	int precio;
	char descripcion[CHAR_LEN];

};


int main(int argc, char const *argv[]) {
	
	int id_semaforo, precio, err, caja;
	char descripcion[CHAR_LEN];
	char caja_filename[CHAR_LEN];
	char str[CHAR_LEN];

	id_semaforo = creo_semaforo();
	inicia_semaforo(id_semaforo, VERDE);

	while(1) {

		espera_semaforo(id_semaforo);

		printf("Ingrese la descripcion del producto: ");
		memset(descripcion, 0x00, sizeof(descripcion));
		scanf("%s", descripcion);

		printf("\nIngrese precio del producto: ");
		scanf("%d", precio);

		caja = which_box(precio);

		if (caja == -1) {
			perror("El precio del producto debe ser mayor a 0\n");
		} else {

			memset(caja_filename, 0x00, sizeof(caja_filename));
			sprintf(caja_filename, "caja%d.dat", caja);
			
			err = inAbrirArchivo(&fp_write, caja_filename, "a");

			if (err != 0) {
				perror("No se pudo abrir archivo desde DERIVADOR\n");
			} else {

				memset(str, 0x00, sizeof(str));
				sprintf(str, "%d\t%s", precio, descripcion);

				inEscribirArchivo(str, &fp_write);
				inCerrarArchivo(&fp_write);

			}

		}

		levanta_semaforo(id_semaforo);
		usleep(100);

	}

	return 0;
}
