#ifndef _ARCHIVOS
#define _ARCHIVOS
#include <stdio.h>

int inAbrirArchivo(FILE** file, char* filename, char* mode);

int inCerrarArchivo(FILE** file);

int inLeerArchivo(char* buffer, int len);

int inEscribirArchivo(char* text);

#endif
