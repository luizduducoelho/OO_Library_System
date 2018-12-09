#include "Publicacao.h"

bool Publicacao::operator==(Publicacao p){
	if(codPublicacao == p.codPublicacao && ano == p.ano && titulo == p.titulo && editora == p.editora)
		return true;
	else
		return false;	
}

