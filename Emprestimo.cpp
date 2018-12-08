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
