#ifndef EMPRESTIMO_H
#define EMPRESTIMO_H

#include "Usuario.h"
#include "ItemEmprestimo.h"
#include "Date.h"
#include "Livro.h"
#include <vector>

using std::vector;

class Emprestimo
{
		static int proximoNumero;
		int numero;
		Usuario usuario;
		Date dataEmprestimo, dataPrevDevolucao;
		vector<ItemEmprestimo> itens;
	public:
		Emprestimo(Usuario user, Date devolucao): numero(proximoNumero++), usuario(user), dataPrevDevolucao(devolucao) {};
		int get_numero() const {return numero;}
		void adiciona_itememprestimo(ItemEmprestimo item);
		void adiciona_livro(Livro &novo_livro);
		void exclui_livro(Livro &livro_excluido);
		void devolve_livro(Livro &livro_devolvido);
		void devolve_todos();
		int get_sizeitens() {return itens.size();}
		
		int get_codPub(int i) {return itens[i].get_cod();}
		
		std::string get_cpfuser() const {return usuario.get_cpf();}
		std::string get_nome_usuario() const {return usuario.get_nome();}
		std::string get_data_devolucao() const {return dataPrevDevolucao.get_date();} 
};

#endif
