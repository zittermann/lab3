#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include "def.h"
#include "cola.h"
#include <stdbool.h>

volatile sig_atomic_t stop = false;

void intHandler(int dummy) {
    stop = true;
}

procesar_evento(int id_cola_mensajes, mensaje msg) {

	char cadena[100];

	printf("Destino   %d\n", (int) msg.long_dest);
	printf("Remitente %d\n", msg.int_rte);
	printf("Evento    %d\n", msg.int_evento);
	printf("Mensaje   %s\n", msg.char_mensaje);

	switch (msg.int_evento) {
		case EVT_RTA_SALDO:
			
			printf("Consulta saldo\n");
			sprintf(cadena, "Saldo deposito: %d\n", msg.char_mensaje);
			printf(cadena);
			break;
		
		case EVT_RTA_DEPOSITO_OK:

			printf("Respuesta deposito\n");
			sprintf(cadena, "Saldo post-deposito: %d\n", msg.char_mensaje);
			printf(cadena);
			break;

		case EVT_RTA_EXTRACCION_OK:

			printf("Respuesta extraccion\n");
			sprintf(cadena, "Saldo post-extraccion: %d\n", msg.char_mensaje);
			printf(cadena);
			break;

		default:
			printf("Evento sin definir\n");
			break;
	}

}

int main(int argc, char const *argv[]){
	
	int id_cola_mensajes;
	mensaje msg;

	signal(SIGINT, intHandler);
	
	id_cola_mensajes = creo_id_cola_mensajes();
	
	while(!stop) {
		enviar_mensaje(id_cola_mensajes, MSG_BANCO, MSG_CAJERO, EVT_CONSULTA_SALDO, "GET SALDO");
		recibir_mensaje(id_cola_mensajes, MSG_CAJERO, &msg);
		procesar_evento(id_cola_mensajes, msg);

		/*
		enviar_mensaje(id_cola_mensajes, MSG_BANCO, MSG_CAJERO, EVT_DEPOSITO, "100");
		recibir_mensaje(id_cola_mensajes, MSG_CAJERO, &msg);

		enviar_mensaje(id_cola_mensajes, MSG_BANCO, MSG_CAJERO, EVT_EXTRACCION, "50");
		recibir_mensaje(id_cola_mensajes, MSG_CAJERO, &msg);
		*/

		sleep(2);
	}

	return 0;
}
