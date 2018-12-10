#include "Emprestimo.h"
#include "Erro.h"
#include <iostream>

void Emprestimo::exclui_livro(Livro &livro_excluido){
	livro_excluido.incrementa();
}

void Emprestimo::adiciona_itememprestimo(ItemEmprestimo item){
	if (usuario.verifica_penalizacao()){
		item.decrementa_livro();
		itens.push_back(item);
	}
	else{
		throw Erro("Usuario esta penalizado, nao pode fazer emprestimo!");
	}
}

void Emprestimo::devolve_livro(Livro &livro_devolvido){
	for(int i = 0; i < itens.size(); i++){
		if(livro_devolvido.get_codPub() == itens[i].get_cod()){
			itens[i].get_Livro().incrementa();
			itens[i].date_sistema();
			usuario.recebe_penalizacao(dataPrevDevolucao);
			return;
		}
	}
}

void Emprestimo::devolve_todos(){
	for(int i = 0; i < itens.size(); i++){
		itens[i].get_Livro().incrementa();
		itens[i].date_sistema();
		usuario.recebe_penalizacao(dataPrevDevolucao);
	}
}

bool Emprestimo::operator==(Emprestimo e){
	if(numero == e.numero && usuario == e.usuario && dataEmprestimo == e.dataEmprestimo)
		return true;
	else
		return false;
}















