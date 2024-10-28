#include <stdio.h>
#include "stdlib.h"
#include "string.h"

#include "archivo.h"

FILE* fp_read = NULL;
FILE* fp_write = NULL; 

/* Archivo debe estar en este directorio */
int inAbrirArchivo(FILE** file, char* filename, char* mode) {

	*file = fopen(filename, mode);

	if (file == NULL) {
		return 1; /* Error */
	}
    
	return 0;

}

/* Archivo debe estar en este directorio */
int inCerrarArchivo(FILE** file) { 

	if (*file != NULL) { /* threw an error */

		fclose(*file);
		*file = NULL;

		return 0;
	}

	return 0;
}

int inLeerArchivo(char* buffer, int len, FILE** file) {

	if (*file == NULL) { 
		return 1;
	}

  	/* Si la línea leída, almacenada en el buffer, es distinta de null */
	if (fgets(buffer, len, *file) != NULL) {

		/* 
		strcspn() devuelve la len() entre el pricipio del array y el segundo arguemnto.
		En este caso el final de la línea 
		*/
		buffer[strcspn(buffer, "\n")] = 0; /* Último char de la línea set to 0 */
		return 0;
	}

	return 1;
}

int inEscribirArchivo(char* buffer, FILE* file) {

	if (file == NULL) {
		return 1;
	}

	fprintf(file, "%s\n", buffer);
	return 0;
}
