#ifndef PERIODICO_H
#define PERIODICO_H

#include "Publicacao.h"

class Periodico: public Publicacao
{
		int numEdicao;
		string mes;
	public:
		Periodico(int codPub, int a, string tit, string ed, int numEd, string m): Publicacao(codPub, a, tit, ed), numEdicao(numEd), mes(m) {};
		int compare_autores(string aut) {};
		int get_numEdicao() const {return numEdicao;}
		string get_mes() const {return mes;}
	};

#endif

