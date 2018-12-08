#ifndef LIVRO_H
#define LIVRO_H

#include "Publicacao.h"

class Livro: public Publicacao{
		int qtdeExemplares;
		string autores;
	public:
		Livro(int codPub, int a, string tit, string ed, string aut, int qt = 0): Publicacao(codPub, a, tit, ed), autores(aut), qtdeExemplares(qt) {};
		void incrementa();
		void decrementa();
		int get_quantidade() const {return qtdeExemplares;}
		string get_autores() const {return autores;}
		int get_cod() const {return Publicacao::get_codPub();}
		bool teste() {return true;}
//		~Livro();
};

#endif

