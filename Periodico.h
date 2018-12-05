#ifndef PERIODICO_H
#define PERIODICO_H

#include "Publicacao.h"

class Periodico
{
		int numEdicao;
		string mes;
	public:
		Periodico(int codPub, int a, string tit, string ed, int numEd, string m): Publicacao(codPub, a, tit, ed), numEdicao(numEd), mes(m) {};
	};

#endif

