#include <iostream>
#include "Livro.h"
#include "Publicacao.h"
#include "Date.h"
#include "Usuario.h"
#include "Emprestimo.h"
#include "Interface.h"
#include <time.h>
#include <string>

using namespace std;

//int Emprestimo::proximoNumero = 0;

int main(){
	
	/////////// Interface
	cout << endl;
	Interface interface;
	interface.menu();
	
	return 0;
}
