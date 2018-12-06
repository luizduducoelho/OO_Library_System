#ifndef ITEMEMPRESTIMO_H
#define ITEMEMPRESTIMO_H

#include "Livro.h"
#include "Date.h"

class ItemEmprestimo
{
		Livro l;
		Date dataDevolucao;
	public:
		ItemEmprestimo(Livro livro): l(livro) {};
};

#endif
