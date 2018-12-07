#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include "Livro.h"
#include "Publicacao.h"
#include "Date.h"
#include "Usuario.h"
#include "Emprestimo.h"
#include "ItemEmprestimo.h"
#include <time.h>
#include <string>
#include <vector>

using namespace std;

class Biblioteca{
		vector<Usuario> lista_usuarios;
		vector<Publicacao> lista_publicacoes;
		vector<Emprestimo> lista_emprestimos;
	public:
		Biblioteca();
		void insere_usuario(Usuario user);
		void insere_publicacao(Publicacao publi);
		void insere_emprestimo(Emprestimo emp);
		void insere_item_emprestimo(Emprestimo emp, ItemEmprestimo item_emp);
		void exclui_usuario(Usuario user);
		void exclui_publicacao(Publicacao publi);
		void exclui_emprestimo(Emprestimo emp);
		void exclui_item_emprestimo(Emprestimo emp, ItemEmprestimo item_emp);
		void devolve_item(Emprestimo emp, Livro livro);
		void devolde_todos(Emprestimo emp);
		vector<Publicacao> pesquisa_publicacao(std::string parte_do_titulo);
		vector<Livro> pesquisa_por_autor(std::string parte_do_autor);
		vector<Usuario> get_lista_usuarios();
		vector<Publicacao> get_lista_publicacoes();
		vector<Emprestimo> get_lista_emprestimos();
		void gravar_em_arquivo();
		void ler_do_arquivo();
		
};

#endif
