/*
//////////////////////////////////////////////////////////////////////////


	PRÁCTICA 6  -  PING PONG (TEORÍA PROGRAMACIÓN DE VIDEOJUEGOS)

			AUTOR: JOSE MARÍA MONREAL GONZÁLEZ
			

//////////////////////////////////////////////////////////////////////////
*/


#include "PingPong.h"

using namespace std;

int main(int ac, char** av) {

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // Check Memory Leaks

	PingPong g;
	g.start();
	return 0;
}
