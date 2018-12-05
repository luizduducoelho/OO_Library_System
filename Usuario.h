#ifndef USUARIO_H
#define USUARIO_H

#include <string>

using std::string;

class Usuario
{
		string nome, cpf, endereco, fone;
		// Date dataPenalizacao
	public:
		Usuario(string n, string c, string e, string f): nome(n), cpf(c), endereco(e), fone(f) {};
		//set(Date )
		//~Usuario();
};

#endif

