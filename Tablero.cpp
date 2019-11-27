#include "Tablero.h"

Tablero::Tablero(int tamanio) {
	int const tamanioTablero = tamanio;
	
	this->tamanio = tamanio;
	
	this->tablero = new char*[tamanio];
	for (int i = 0; i < tamanio; i++) {
		this->tablero[i] = new char[tamanio];
	}
}

char** Tablero::obtenerTablero() {
	return this->tablero;
}
