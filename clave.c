#include <stdio.h>
#include <stdlib.h>
#include "clave.h"
#include "def.h"
#include <sys/ipc.h>

key_t creo_clave(void) {

	key_t clave;
	clave = ftok(DEFAULT_PATH, DEFAULT_VALUE);

	if (clave == (key_t)-1) {
		printf("Could not generate key_t\n");
		exit(0);
	}

	return clave;

}
