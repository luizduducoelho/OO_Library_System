#ifndef PUBLICACAO_H
#define PUBLICACAO_H

#include <string>

using std::string;

class Publicacao
{
		int codPublicacao, ano;
		string titulo, editora;
	public:
		Publicacao(int codPub, int a, string tit, string ed): codPublicacao(codPub), ano(a), titulo(tit), editora(ed) {};
};

#endif
