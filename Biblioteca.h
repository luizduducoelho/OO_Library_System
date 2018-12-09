#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include "Livro.h"
#include "Publicacao.h"
#include "Periodico.h"
#include "Date.h"
#include "Usuario.h"
#include "Emprestimo.h"
#include "ItemEmprestimo.h"
#include <time.h>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Biblioteca{
		vector<Usuario> lista_usuarios;
		vector<Publicacao*> lista_publicacoes;
		vector<Emprestimo> lista_emprestimos;
	public:
		Biblioteca();
		void insere_usuario(Usuario user);
		void insere_publicacao(Publicacao &publi);  // {lista_publicacoes.push_back(&publi);}
		void insere_emprestimo(Emprestimo emp);
		void insere_item_emprestimo(Emprestimo emp, ItemEmprestimo item_emp);
		void exclui_usuario(Usuario user);
		void exclui_publicacao(Publicacao &publi);
		void exclui_emprestimo(Emprestimo emp);
		void exclui_item_emprestimo(Emprestimo emp, ItemEmprestimo item_emp);
		void devolve_item(Emprestimo emp, Livro livro);
		void devolde_todos(Emprestimo emp);
		vector<Publicacao> pesquisa_publicacao(std::string parte_do_titulo);
		vector<Livro> pesquisa_por_autor(std::string parte_do_autor);
		vector<Usuario> get_lista_usuarios() const {return lista_usuarios;}
		vector<Publicacao*> get_lista_publicacoes() const {return lista_publicacoes;}
		vector<Emprestimo> get_lista_emprestimos() const {return lista_emprestimos;}
		void gravar_em_arquivo();
		void ler_do_arquivo();
		int get_publicacoes_size() const {return lista_publicacoes.size();}
		int get_codPub(int index) const {return lista_publicacoes[index]->get_codPub();}
		int get_ano(int index) const {return lista_publicacoes[index]->get_ano();}
		string get_titulo(int index) const {return lista_publicacoes[index]->get_titulo();}
		string get_editora(int index) const {return lista_publicacoes[index]->get_editora();}
		void imprime_publicacoes();
		
};

#endif
