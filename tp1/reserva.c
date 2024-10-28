#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "semaforo.h"
#include "archivo.h"
#include "def.h"
#include <unistd.h>
#include <string.h>

int main(int argc, char const *argv[]) {
	
	FILE* file = 0;
	int i, err, id_semaforo;
	char str[200+1];
	char new_name[13+1];

	int cont_lote=0;

	id_semaforo = creo_semaforo();

	while(1) {

		espera_semaforo(id_semaforo); 

		printf("Abriendo archivo... desde consumidor\n");
		err = inAbrirArchivo(&file, "lote.dat", "rb");

		if (err != 0)
			perror("No se pudo abrir archivo desde consumidor");
		

		while(!feof(file)) {
			memset(str, 0x00, sizeof(str));

			inLeerArchivo(str, file);
			printf("%s\n", str);
		}

		inCerrarArchivo(&file);
		printf("Cierro archivo desde consumidor.\n");

		printf("Renombro archivo\n");
		memset(new_name, 0x00, sizeof(new_name));
		sprintf(new_name, "lote.%d.bat", i);

		if (rename("lote.bat", new_name) ) {
			printf("Renamed successfully!\n");
		} else {
			perror("Could not rename file\n");
		}

		levanta_semaforo(id_semaforo); 
		usleep(300);

	};

	return 0;	
}
