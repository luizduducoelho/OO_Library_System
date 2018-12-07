#include "Biblioteca.h"

Biblioteca::Biblioteca(){
	
}

void Biblioteca::insere_usuario(Usuario user){
	lista_usuarios.push_back(user);
}

void Biblioteca::insere_publicacao(Publicacao publi){
	lista_publicacoes.push_back(publi);
}

std::vector<Usuario> Biblioteca::get_lista_usuarios() const{
	return lista_usuarios;
}
