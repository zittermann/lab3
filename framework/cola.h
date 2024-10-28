#ifndef _COLA
#define _COLA
#include "def.h"

int creo_id_cola_mensajes();
int borrar_mensajes(int);
int recibir_mensaje(int, long , mensaje*);
int enviar_mensaje(int, long, int, int, char*);
int borrar_mensajes(int id_cola_mensajes);
int liberar_cola_de_mensajes(int id_cola_mensajes);

#endif