#include "Biblioteca.h"

Biblioteca::Biblioteca(){
	
}

void Biblioteca::insere_usuario(Usuario user){
	lista_usuarios.push_back(user);
}

void Biblioteca::insere_emprestimo(Emprestimo emp){
	lista_emprestimos.push_back(emp);
}

//void Biblioteca::insere_item_emprestimo(Emprestimo emp, ItemEmprestimo item_emp){	
//}
