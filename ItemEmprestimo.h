#ifndef ITEMEMPRESTIMO_H
#define ITEMEMPRESTIMO_H

#include "Livro.h"

class ItemEmprestimo
{
		Livro l;
		//Date;
	public:
		ItemEmprestimo(int codPub, int a, string tit, string ed, string aut, int qt): l(codPub, a, tit, ed, aut, qt) {};
};

#endif
