#include "Emprestimo.h"
#include <iostream>

void Emprestimo::adiciona_livro(Livro &novo_livro){
	if (novo_livro.get_quantidade() <= 0){
		std::cout << "Livro esgotado" << std::endl;
	}
	else{
		novo_livro.decrementa();
	}
}

void Emprestimo::exclui_livro(Livro &livro_excluido){
	livro_excluido.incrementa();
}

void Emprestimo::adiciona_itememprestimo(ItemEmprestimo item){
	itens.push_back(item);
}

void Emprestimo::devolve_livro(Livro &livro_devolvido){
	for(int i = 0; i < itens.size(); i++){
		if(livro_devolvido.get_codPub() == itens[i].get_cod()){
			itens[i].get_Livro().incrementa();
			itens[i].date_sistema();
			return;
		}
	}
}

void Emprestimo::devolve_todos(){
	for(int i = 0; i < itens.size(); i++){
		itens[i].get_Livro().incrementa();
		itens[i].date_sistema();
	}
}

bool Emprestimo::operator==(Emprestimo e){
	if(numero == e.numero && usuario == e.usuario && dataEmprestimo == e.dataEmprestimo)
		return true;
	else
		return false;
}















