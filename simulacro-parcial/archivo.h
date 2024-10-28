#ifndef _ARCHIVOS
#define _ARCHIVOS
#include <stdio.h>

extern FILE* fp_read;
extern FILE* fp_write; 

int inAbrirArchivo(FILE** file, const char* filename, char* mode);

int inCerrarArchivo(FILE** file);

int inLeerArchivo(char* buffer, int maxLen, FILE **fp);

int inEscribirArchivo(char* texto, FILE **fp);

int inEliminarArchivo(char* filename);

#endif
