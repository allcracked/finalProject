#ifndef TABLERO_H
#define TABLERO_H

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Tablero
{
	public:
		Tablero(int tamanio);
		char** obtenerTablero();
		
	protected:
		char** tablero;
		int tamanio;
		char letras[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
		string palabrasFaciles[7] = {"HOLA", "CASA", "NADA", "PAPA", "MAMA", "MEME", "AAAA"};
		string palabrasDificiles[7] = {"CAMARON", "DINERO", "DIGNIDAD", "AMARILLO", "VENTILADOR", "PANTALLA", "TECLADO"};
};

#endif
