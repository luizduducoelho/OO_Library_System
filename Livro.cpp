#include "Livro.h"

void Livro::incrementa(){
	qtdeExemplares++;
}

void Livro::decrementa(){
	if(qtdeExemplares == 0){
	//	throw Error_qt();
	}
	else{
		qtdeExemplares--;
	}
	
}




