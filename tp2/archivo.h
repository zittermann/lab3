#ifndef _ARCHIVOS
#define _ARCHIVOS
#include <stdio.h>

int inAbrirArchivo(FILE** file, char* filename, char* mode);

int inCerrarArchivo(FILE** file);

int inLeerArchivo(char* buffer, int len, FILE** file);

int inEscribirArchivo(char* text, FILE* file);

#endif
