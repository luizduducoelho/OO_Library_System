#include "Biblioteca.h"

int Emprestimo::proximoNumero = 0;

Biblioteca::Biblioteca(){	
}

void Biblioteca::insere_usuario(Usuario user){
	lista_usuarios.push_back(user);
}

void Biblioteca::insere_publicacao(Publicacao &publi){
	//lista_publicacoes.push_back(&publi);
	if(dynamic_cast<Livro*>(&publi)){
		Livro* new_pointer = dynamic_cast<Livro*>(&publi);
		lista_publicacoes.push_back(new Livro(new_pointer->get_codPub(), new_pointer->get_ano(), new_pointer->get_titulo(), new_pointer->get_editora(),new_pointer->get_autores(), new_pointer->get_quantidade()));
		//lista_publicacoes.push_back(new Livro(dynamic_cast<Livro*>(&publi));
	}
	else if(dynamic_cast<Periodico*>(&publi)){
		Periodico* new_pointer = dynamic_cast<Periodico*>(&publi);
		lista_publicacoes.push_back(new Periodico(new_pointer->get_codPub(), new_pointer->get_ano(), new_pointer->get_titulo(), new_pointer->get_editora(), new_pointer->get_numEdicao(), new_pointer->get_mes()));
	}
	else{
		std::cout << "Erro. Tipo desonhecido" << endl;
	}
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
	for(int i = 0; i < lista_emprestimos.size(); i++){
		if(lista_emprestimos[i].get_user() == user)
			return; // THROW!!! Usuario com emprestimo
	}
	for(int j = 0; j < lista_usuarios.size(); j++){
		if(lista_usuarios[j] == user){
			lista_usuarios.erase(lista_usuarios.begin() + j);
			return;
		}
	}						
}


void Biblioteca::exclui_publicacao(Publicacao &publi){
	if(publi.teste()){
		
		
	}
	for(int i = 0; i < lista_publicacoes.size(); i++){
		if(lista_publicacoes[i]->get_codPub() == publi.get_codPub()){
			if (dynamic_cast<Livro*>(lista_publicacoes[i])){  // Se eh livro
				for(int j = 0; j < lista_emprestimos.size(); j++){
					vector<ItemEmprestimo> itens = lista_emprestimos[j].get_itens();
					for(int k = 0; k < lista_emprestimos[j].get_sizeitens(); k++){
						if (itens[k].get_cod() == publi.get_codPub()){
							return;
						}
					}
				}
			}
			lista_publicacoes.erase(lista_publicacoes.begin() + i);
			return;
		}
	}	
}

void Biblioteca::exclui_emprestimo(Emprestimo emp){
	if(emp.get_sizeitens() != 0)
		return; // !!! LANÇAR THROW, tem itens no empréstimo
	else{
		for(int i = 0; i < lista_emprestimos.size(); i++){
			if(lista_emprestimos[i] == emp){
				lista_emprestimos.erase(lista_emprestimos.begin() + i);
				return;
			}
		}	
	}
}

/*
void Biblioteca::exclui_item_emprestimo(Emprestimo emp, ItemEmprestimo item_emp){
	for(int i = 0; i < lista_emprestimos.size(); i++){
		if(lista_emprestimos[i] == emp){
			for(int j = 0; j < lista_emprestimos[i].get_sizeitens(); j++){
				if(item_emp.get_Livro() == lista_emprestimos[i].get_codPub(j)){	
					Livro l = item_emp.get_Livro();
					lista_emprestimos[i].exclui_livro(l);
					return;
				}
			}
		}
	}
}*/

/*
void Biblioteca::devolve_item(Emprestimo emp, Livro livro){
	for(int i = 0; i < lista_emprestimos.size(); i++){
		if(lista_emprestimos[i].get_numero() == emp.get_numero()){
			for(int j = 0; j < lista_emprestimos[i].get_sizeitens(); j++){
				if(livro.get_codPub() == lista_emprestimos[i].get_codPub(j)){
					lista_emprestimos[i].devolve_livro(livro);
				}
			}
		}
	}
}*/

void Biblioteca::imprime_publicacoes(){
	for (int i=0; i < lista_publicacoes.size(); i++){
		std::cout << "Codigo da Publicacao: " << lista_publicacoes[i]->get_codPub() << std::endl;
		std::cout << "Ano: " << lista_publicacoes[i]->get_ano() << std::endl;
		std::cout << "Titulo: " << lista_publicacoes[i]->get_titulo() << std::endl;
		std::cout << "Editora: " << lista_publicacoes[i]->get_editora() << std::endl;
		if(dynamic_cast<Livro*>(lista_publicacoes[i])){
			Livro* new_pointer = dynamic_cast<Livro*>(lista_publicacoes[i]);
			std::cout << "Autores: " << new_pointer->get_autores() << std::endl;
			std::cout << "Quantidade: " << new_pointer->get_quantidade() << std::endl;
		}
		else if(dynamic_cast<Periodico*>(lista_publicacoes[i])){
			Periodico* new_pointer = dynamic_cast<Periodico*>(lista_publicacoes[i]);
			std::cout << "Numero edicao: " << new_pointer->get_numEdicao() << std::endl;
			std::cout << "Mes: " << new_pointer->get_mes() << std::endl;
		}
		std::cout << std::endl;
	}
}

vector<Publicacao> Biblioteca::pesquisa_publicacao(std::string parte_do_titulo){
	vector<Publicacao> p_aux;
	for(int i = 0; i < lista_publicacoes.size(); i++){
		if(lista_publicacoes[i]->compare_titulo(parte_do_titulo) > 4)
			p_aux.push_back(*lista_publicacoes[i]);
	}
	return p_aux;
}
 vector<Livro> Biblioteca::pesquisa_por_autor(std::string parte_do_autor){
	vector<Livro> l_aux;
	for(int i = 0; i < lista_publicacoes.size(); i++){
		if((lista_publicacoes[i]->compare_autores(parte_do_autor) > 3) && (lista_publicacoes[i]->teste())){
			Livro &l = (Livro&)lista_publicacoes[i];
			l_aux.push_back(l);
		}
	}
	return l_aux;
}				


