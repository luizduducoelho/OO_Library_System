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
		int get_codPub() const {return codPublicacao;}
		int get_ano() const {return ano;}
		string get_titulo() const {return titulo;}
		string get_editora() const {return editora;}
		virtual bool teste() {}; // True para LIVRO, False para PERIODICO
		bool operator==(Publicacao p);
};

#endif
