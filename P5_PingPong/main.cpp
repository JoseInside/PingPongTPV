/*
//////////////////////////////////////////////////////////////////////////


	PR�CTICA 6  -  PING PONG (TEOR�A PROGRAMACI�N DE VIDEOJUEGOS)

			AUTOR: JOSE MAR�A MONREAL GONZ�LEZ
			

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
