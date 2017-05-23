#ifndef SOCKETDATAGRAMA_H_
#define SOCKETDATAGRAMA_H_

#include <arpa/inet.h>
#include <errno.h>
#include <iostream>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/time.h>
#include <unistd.h>

#include "PaqueteDatagrama.h"

class SocketDatagrama{
private:
	struct sockaddr_in direccionLocal;
	struct sockaddr_in direccionForanea;
	struct timeval s_timeout;
	bool timeout;
	int s; //ID socket
public:
	SocketDatagrama(int);
	~SocketDatagrama();
	//Recibe un paquete tipo datagrama proveniente de este socket
	int recibe(PaqueteDatagrama &p);
	//Envía un paquete tipo datagrama desde este socket
	int envia(PaqueteDatagrama &p);
	void setTimeout(time_t segundos, suseconds_t microseconds);
	void unsetTimeout();
	int recibeTimeout(PaqueteDatagrama &p);
};

#endif