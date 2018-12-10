#include "Livro.h"
#include <iostream>

void Livro::incrementa(){
	qtdeExemplares++;
}

void Livro::decrementa(){
	if(qtdeExemplares == 0){
		std::cout << "Nao temos esse livro " << std::endl;
	}
	else{
		qtdeExemplares--;
	}
}

bool Livro::operator==(Livro l){
	if(get_codPub() == l.get_codPub() && get_ano() == l.get_ano() && get_titulo() == l.get_titulo() && get_editora() == l.get_editora() && get_autores() == l.get_autores())
		return true;
	else
		return false;
}

//int Livro::compare_autores(string aut){
//	return autores.compare(aut);
//}

int Livro::compare_autores(size_t pos, size_t len, string aut){
	return autores.compare(pos, len, aut);
}
