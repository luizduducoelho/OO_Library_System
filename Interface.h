#ifndef INTERFACE_H
#define INTERFACE_H

#include "Biblioteca.h"
#include <string>
#include <vector>
#include <iostream>

class Interface{
	Biblioteca biblio;
	public:
		Interface();
		void menu();
		void cadastra_novo_usuario();
		void lista_usuarios();
};

#endif
