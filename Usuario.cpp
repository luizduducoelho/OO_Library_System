#include "Usuario.h"

bool Usuario::operator==(Usuario user){
	if(nome == user.nome && cpf == user.cpf && endereco == user.endereco && fone == user.fone)
		return true;
	else
		return false;
}
