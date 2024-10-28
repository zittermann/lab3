#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "semaforo.h"
#include "archivo.h"
#include "def.h"
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char const *argv[]) {
	
	FILE* file = 0;
	int i, num_lote, err, id_semaforo;
	char str[100];
	char new_filename[20+1];
	char filename[15];
	int cont_lote=1;
	int int_token;

	int cont_efetivo, acu_efectivo;
	int cont_cheque, acu_cheque, aux_importe;
	bool is_importe = true; /* tells if the value is importe or cheque validation */

	const char delimiter[] = "\t";
	char *token;

	id_semaforo = creo_semaforo();

	while(1) {

		for (i=1; i<CANT_CAJEROS+1; i++) { /* Siendo i el numero de cajero dentro del bucle */

			espera_semaforo(id_semaforo);
			memset(filename, 0x00, sizeof(filename));
			sprintf(filename, "cajero%d.dat", i);

			printf("Abriendo archivo %s... desde tesorero\n", filename);
			err = inAbrirArchivo(&file, filename, "r");

			if (err != 0) {
				printf("No se pudo abrir %s desde tesorero; \
				quizas porque todavia no existe", filename);
			} else {

				/* Set them all to zero */
				cont_cheque = cont_efetivo = acu_cheque = acu_efectivo = 0;

				while(!feof(file)) {
					
					memset(str, 0x00, sizeof(str));
					inLeerArchivo(str, 100, &file);
					printf("%s\n", str);

					token = strtok(str, delimiter);

					while (token != NULL) {

						int_token = atoi(token); /* We'll work with int to ease the job */

						if (is_importe) {
							aux_importe = int_token; /* Amount saved in aux */
						} else {

							if (int_token == 0) { /* 0 = cheque; 1 = efectivo */

								cont_cheque++;
								acu_cheque += aux_importe;

							} else {

								cont_efetivo++;
								acu_efectivo += aux_importe;

							}
						}
					}
				}
			}

				printf("Cierro %s desde tesorero.\n", filename);
				inCerrarArchivo(&file);
				
				printf("Renombro archivo\n");
				memset(new_filename, 0x00, sizeof(new_filename));
				sprintf(new_filename, "cajero%d.%d.bat", i, cont_lote); /* Ej: cajero1.999.dat */

				if (rename(filename, new_filename) ) {
					printf("Renamed successfully!\n");
				} else {
					perror("Could not rename file\n");
				}

				printf("Cheques: %d - Monto cheques: %d\n", cont_cheque, acu_cheque);
				printf("Efectivo: %d - Monto efectivo: %d\n", cont_efetivo, acu_efectivo);

		}

		levanta_semaforo(id_semaforo); 
		usleep(500);

	};

	return 0;	
}
