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
	static int saldo = 0;

	printf("Destino   %d\n", (int) msg.long_dest);
	printf("Remitente %d\n", msg.int_rte);
	printf("Evento    %d\n", msg.int_evento);
	printf("Mensaje   %s\n", msg.char_mensaje);

	switch (msg.int_evento) {
		case EVT_CONSULTA_SALDO:
			
			printf("Consulta saldo\n");
			sprintf(cadena, "%d", saldo);
			printf(cadena);
			enviar_mensaje(id_cola_mensajes, msg.int_rte, MSG_BANCO, EVT_RTA_SALDO, cadena);
			break;
		
		case EVT_DEPOSITO:

			printf("Consulta deposito\n");
			saldo += atoi(msg.char_mensaje);

			sprintf(cadena, "%d", saldo);
			printf(cadena);
			enviar_mensaje(id_cola_mensajes, msg.int_rte, MSG_BANCO, EVT_RTA_DEPOSITO_OK, cadena);
			break;

		case EVT_EXTRACCION:

			printf("Consulta extraccion\n");
			saldo -= atoi(msg.char_mensaje);

			sprintf(cadena, "%d", saldo);
			printf(cadena);
			enviar_mensaje(id_cola_mensajes, msg.int_rte, MSG_BANCO, EVT_RTA_EXTRACCION_OK, cadena);
			break;

		default:
			printf("Evento sin definir\n");
			break;
	}

}

int main(int argc, char const *argv[]) {
	
	int id_cola_mensajes;
	mensaje msg;

	signal(SIGINT, intHandler);

	id_cola_mensajes = creo_id_cola_mensajes();
	borrar_mensajes(id_cola_mensajes);

	while(!stop) {
		recibir_mensaje(id_cola_mensajes, MSG_BANCO, &msg);
		procesar_evento(id_cola_mensajes, msg);
		sleep(1);
	}

	liberar_cola_de_mensajes(id_cola_mensajes);

	return 0;
}
