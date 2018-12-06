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




