#ifndef ITEMEMPRESTIMO_H
#define ITEMEMPRESTIMO_H

#include "Livro.h"
#include "Date.h"

class ItemEmprestimo
{
		Livro l;
		Date dataDevolucao;
	public:
		ItemEmprestimo(Livro livro): l(livro) {dataDevolucao.reset_date();}
		int get_cod() const {return l.get_codPub();}
		string get_titulo() const {return l.get_titulo();}
		Livro get_Livro() const {return l;}
		std::string get_date() const {return dataDevolucao.get_date();}
		void date_sistema();
		bool operator==(ItemEmprestimo IE);
		void decrementa_livro() {l.decrementa();}
};

#endif
