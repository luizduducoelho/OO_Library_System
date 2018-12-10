#include "ItemEmprestimo.h"

void ItemEmprestimo::date_sistema(){
	Date data_sistema;
	dataDevolucao.set_date(data_sistema.get_date());
}

bool ItemEmprestimo::operator==(ItemEmprestimo IE){
	if(l == IE.l && dataDevolucao == IE.dataDevolucao)
		return true;
	else
		return false;
}
