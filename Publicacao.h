#ifndef PUBLICACAO_H
#define PUBLICACAO_H

#include <string>

using std::string;

class Publicacao
{	
	protected:
		int codPublicacao, ano;
		string titulo, editora;
	public:
		Publicacao(int codPub, int a, string tit, string ed): codPublicacao(codPub), ano(a), titulo(tit), editora(ed) {};
		virtual int get_codPub() const {return codPublicacao;}
		virtual int get_ano() const {return ano;}
		virtual string get_titulo() const {return titulo;}
		virtual string get_editora() const {return editora;}
		virtual bool teste() {}; // True para LIVRO, False para PERIODICO
		virtual bool operator==(Publicacao p);
		int compare_titulo(string tit);
		virtual int compare_autores(string aut) {};
};

#endif
