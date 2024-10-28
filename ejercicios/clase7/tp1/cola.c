#include "cola.h"
#include "def.h"
#include "clave.h"
#include "stdlib.h"

int creo_id_cola_mensajes() {
	int id_cola_mensajes = msgget (creo_clave(), 0600 | IPC_CREAT);
	if (id_cola_mensajes == -1)
	{
		printf("Error al obtener identificador para cola mensajes\n");
		exit (-1);
	}
	return id_cola_mensajes;
}

int enviar_mensaje(int id_cola_mensajes, long rLongDest, int rIntRte, int rIntEvento, char* rpCharMsg) {
	mensaje msg;
	msg.long_dest 	= rLongDest;
	msg.int_rte    	= rIntRte;
	msg.int_evento 	= rIntEvento;
	strcpy(msg.char_mensaje, rpCharMsg);
	return msgsnd (id_cola_mensajes, (struct msgbuf *)&msg, sizeof(msg.int_rte)+sizeof(msg.int_evento)+sizeof(msg.char_mensaje), IPC_NOWAIT);
}		

int recibir_mensaje(int id_cola_mensajes, long rLongDest, mensaje* rMsg) {
	mensaje msg;
	int res;
	res = msgrcv (id_cola_mensajes, (struct msgbuf *)&msg,  sizeof(msg.int_rte)+sizeof(msg.int_evento)+sizeof(msg.char_mensaje), 	rLongDest, 0);
	
	rMsg->long_dest 	    = msg.long_dest;
	rMsg->int_rte    	= msg.int_rte;
	rMsg->int_evento 	= msg.int_evento;
	strcpy(rMsg->char_mensaje, msg.char_mensaje);
	return res;
}

int borrar_mensajes(int id_cola_mensajes) {
	mensaje msg;
	int res;
	do {
		res = msgrcv (id_cola_mensajes, (struct msgbuf *)&msg,  sizeof(msg.int_rte)+sizeof(msg.int_evento)+sizeof(msg.char_mensaje), 	0, IPC_NOWAIT);
	} while(res>0);
	return res;
}

int liberar_cola_de_mensajes(int id_cola_mensajes){
	/*
		Se borra y cierra la cola de mensajes.
		IPC_RMID indica que se quiere borrar. El puntero del final son datos
		que se quieran pasar para otros comandos. IPC_RMID no necesita datos,
		así que se pasa un puntero a NULL.

		SE BORRA AL FINAL DE LA EJECUCIÓN DEL ÚLTIMO PROCESO
	*/
	msgctl (id_cola_mensajes, IPC_RMID, (struct msqid_ds *)NULL);

}
