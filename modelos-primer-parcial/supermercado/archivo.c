#include <stdio.h>
#include "stdlib.h"
#include "string.h"

#include "archivo.h"

FILE *fp_read = NULL;
FILE *fp_write = NULL; 

/* Archivo debe estar en este directorio */
int inAbrirArchivo(FILE** file, const char* filename, char* mode) {

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

int inLeerArchivo(char* buffer, int maxLen, FILE **fp) {
    
	if (*fp == NULL) {
        return 0;  
    }
    
	/*
    if (fgets(buffer, maxLen, *fp) != NULL) {
        buffer[strcspn(buffer, "\n")] = 0;
        return 1;  
    }
	*/

	if(fgets(buffer, maxLen, *fp) != NULL) {
		return 1;
	}

    return 0;  
}

int inEscribirArchivo(char* texto, FILE **fp) {
    if (*fp == NULL) {
        return 0;
    }
    fprintf(*fp, "%s\n", texto);
    return 1;
}

int inEliminarArchivo(char* filename) {
	remove(filename);
}
