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

typedef struct avion {
	int nro_avion;
	char ciudad[CHAR_LEN];
} avion;


#endif