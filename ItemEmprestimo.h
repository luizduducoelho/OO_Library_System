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
		int get_cod() {return l.get_codPub();}
		Livro get_Livro() {return l;}
		void date_sistema();
//		ItemEmprestimo &get_item() {return (*this);}
};

#endif
