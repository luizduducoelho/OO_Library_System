#ifndef INTERFACE_H
#define INTERFACE_H

#include "Biblioteca.h"
#include <string>
#include <vector>
#include <iostream>

class Interface{
	Biblioteca biblio;
	public:
		Interface();
		int le_inteiro();
		void menu();
		void cadastra_novo_usuario();
		void cadastra_novo_livro();
		void cadastra_novo_periodico();
		void cadastra_novo_emprestimo();
		void inserir_novo_item_emprestimo();
		void excluir_usuario();
		void excluir_livro();
		void excluir_periodico();
		void excluir_emprestimo();
		void excluir_item_emprestimo();
		void devolve_todos();
		void devolve_livro();
		void pesquisa_publicacao_por_titulo();
		void pesquisa_livro_por_autor();
		void lista_publicacoes();
		void lista_emprestimos();
		void lista_usuarios();
};

#endif
