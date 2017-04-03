#include "SocketDatagrama.h"

#include "gfxModified.h"
#include <iostream>
#include <cstdlib>
#include <math.h>
#include <string.h>
#include <stdbool.h>

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
using namespace std;

#define BUF_SIZE 1000
#define PI 3.1416

int main(int args, char *argv[]){
	int ysize = 600;
	int xsize = 800;
	char c;

	// Open a new window for drawing.
	gfx_open(xsize,ysize,"Grafica Fourier");

	//cout << "Soy el servidor" << endl;
	char *IP = argv[1];
	int PUERTO = atoi(argv[2]);
	int  leidos = 0, destino;
	int PUERTOCli = atoi(argv[3]);
	SocketDatagrama sock(PUERTO);
	int cooX=0, cooY=0;

	gfx_color(0,200,100);
	gfx_line(xsize/2,0,xsize/2,ysize);
	gfx_line(0,ysize/2,xsize,ysize/2);
	gfx_flush();

	while(1){
		PaqueteDatagrama resp(10);
//		char * cad = resp.obtieneDatos();
		
		//recibe x para graficar
		sock.recibe(resp);
		string cad = resp.obtieneDatos();
		//guarda coordenada x
		cout << "Longitud cad " << resp.obtieneDatos() << endl;
/*		for(int i = 0; i < 8; i++)
			cout << cad[i] + 'A' << endl;
		sleep(3);*/

		cooX = atoi((cad.substr(0,4)).c_str());
		cout << "coordX: " << cooX << endl;
		//recibe y para graficar
		//sock.recibe(resp);
		int ind = cad.find('?');
		int ind2 = cad.length();
		cout << "Ind " << ind << endl;
		cout << "Ind2 " << ind2 << endl;
		cout << "substr " << cad.substr(ind ,ind2-ind) << endl;
		cooY = atoi( cad.substr(ind + 1 ,ind2-ind).c_str() );
		cout << "coordY: " << cooY << endl;
		//grafica el punto
		//blue
		gfx_color(0,0,200);
		gfx_point(cooX, cooY);
		gfx_flush();			
	}
	
	//if((c = gfx_wait()) == 'q')
	//	break;
	close(destino);
	return 0;
}
