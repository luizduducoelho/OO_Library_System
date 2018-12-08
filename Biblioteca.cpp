#include "Biblioteca.h"

Biblioteca::Biblioteca(){	
}

void Biblioteca::insere_usuario(Usuario user){
	lista_usuarios.push_back(user);
}

void Biblioteca::insere_emprestimo(Emprestimo emp){
	lista_emprestimos.push_back(emp);
}

void Biblioteca::insere_item_emprestimo(Emprestimo emp, ItemEmprestimo item_emp){	
	for(int i = 0; i < lista_emprestimos.size(); i++){
		if(lista_emprestimos[i].get_numero() == emp.get_numero())
			lista_emprestimos[i].adiciona_itememprestimo(item_emp);
			return;
	}
}

void Biblioteca::exclui_usuario(Usuario user){
	for(int i = 0; i < lista_usuarios.size(); i++){
		if(lista_usuarios[i].get_cpf() == user.get_cpf()){
			for(int j = 0; j < lista_emprestimos.size(); j++){
				if(lista_usuarios[i].get_cpf() == lista_emprestimos[j].get_cpfuser()){
					return;
				}
			}
			lista_usuarios.erase(lista_usuarios.begin() + i);
			return;
		}
	}	
}

/*void Biblioteca::exclui_publicacao(Publicacao publi){
	for(int i = 0; i < lista_publicacoes.size(); i++){
		if(lista_publicacoes[i].get_codPub() == publi.get_codPub()){
			lista_publicacoes.erase(lista_publicacoes.begin() + i);
			return;
		}
	}	
}*/

void Biblioteca::exclui_emprestimo(Emprestimo emp){
	for(int i = 0; i < lista_emprestimos.size(); i++){
		if(lista_emprestimos[i].get_numero() == emp.get_numero()){
			lista_emprestimos.erase(lista_emprestimos.begin() + i);
			return;
		}
	}	
}

