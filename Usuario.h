#ifndef USUARIO_H
#define USUARIO_H

#include "Date.h"
#include <string>

using std::string;

class Usuario
{
		string nome, cpf, endereco, fone;
		Date dataPenalizacao;
	public:
		Usuario(string n, string c, string e, string f): nome(n), cpf(c), endereco(e), fone(f) {};
		std::string get_nome() const {return nome;}
		std::string get_cpf() const {return cpf;}
		std::string get_endereco() const {return endereco;}
		std::string get_fone() const {return fone;}
		std::string get_data_penalizacao() const {return dataPenalizacao.get_date();}
		struct tm * get_structtm() const {return dataPenalizacao.get_structtm();}
		void set_date_string(std::string time_string) {dataPenalizacao.set_date(time_string);}
		bool operator==(Usuario user);
		//~Usuario();
};

#endif

