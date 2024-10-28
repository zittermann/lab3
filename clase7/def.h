#ifndef _DEF
#define _DEF

#include <sys/ipc.h>
#include <sys/sem.h>

#define DEFAULT_PATH "/bin/ls"
#define DEFAULT_KEY 33

#define ROJO 0
#define VERDE 1

#define NUM_CIUDADES 3
#define CHAR_LEN 100

#define CANTIDAD 10
#define CANTIDAD_TOTAL 10
#define DESDE 0
#define HASTA 2

typedef struct tipo_dato dato;
struct tipo_dato {
	int numero;
	char letra;
};

#endif