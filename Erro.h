#ifndef ERRO_H
#define EROO_H

#include <string>

class Erro{
		std::string message;
	public:
		Erro(std::string msg): message(msg) {};
		std::string get_erro() const {return message;}
};

#endif
