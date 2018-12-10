#include "Biblioteca.h"
#include "Erro.h"

int Emprestimo::proximoNumero = 0;

Biblioteca::Biblioteca(){	
}

void Biblioteca::insere_usuario(Usuario user){
	lista_usuarios.push_back(user);
}

void Biblioteca::insere_publicacao(Publicacao &publi){
	if(dynamic_cast<Livro*>(&publi)){
		Livro* new_pointer = dynamic_cast<Livro*>(&publi);
		lista_publicacoes.push_back(new Livro(new_pointer->get_codPub(), new_pointer->get_ano(), new_pointer->get_titulo(), new_pointer->get_editora(),new_pointer->get_autores(), new_pointer->get_quantidade()));
	}
	else if(dynamic_cast<Periodico*>(&publi)){
		Periodico* new_pointer = dynamic_cast<Periodico*>(&publi);
		lista_publicacoes.push_back(new Periodico(new_pointer->get_codPub(), new_pointer->get_ano(), new_pointer->get_titulo(), new_pointer->get_editora(), new_pointer->get_numEdicao(), new_pointer->get_mes()));
	}
	else{
		throw Erro("Erro nao identificado!");
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
			throw Erro("Usuario possui emprestimo! Nao eh possivel excluir");
	}
	for(int j = 0; j < lista_usuarios.size(); j++){
		if(lista_usuarios[j] == user){
			lista_usuarios.erase(lista_usuarios.begin() + j);
			return;
		}
	}						
}


void Biblioteca::exclui_publicacao(Publicacao &publi){
	for(int i = 0; i < lista_publicacoes.size(); i++){
		if(lista_publicacoes[i]->get_codPub() == publi.get_codPub()){
			if (dynamic_cast<Livro*>(lista_publicacoes[i])){
				for(int j = 0; j < lista_emprestimos.size(); j++){
					vector<ItemEmprestimo> itens = lista_emprestimos[j].get_itens();
					for(int k = 0; k < lista_emprestimos[j].get_sizeitens(); k++){
						if (itens[k].get_cod() == publi.get_codPub()){
							throw Erro("A publicacao eh um Livro e possui emprestimo! Nao eh possivel excluir");
						}
					}
				}
			}
			lista_publicacoes.erase(lista_publicacoes.begin() + i);
			return;
		}
	}throw Erro("A publicacao eh um Periodico! Nao eh possivel excluir");
}

void Biblioteca::exclui_emprestimo(Emprestimo emp){
	if(emp.get_sizeitens() != 0)
		throw Erro("Ha itens no Emprestimo! Nao eh possivel excluir o Emprestimo antes da devolucao.");
	else{
		for(int i = 0; i < lista_emprestimos.size(); i++){
			if(lista_emprestimos[i] == emp){
				lista_emprestimos.erase(lista_emprestimos.begin() + i);
				return;
			}
		}	
	}
}

void Biblioteca::exclui_item_emprestimo(Emprestimo emp, ItemEmprestimo item_emp){
	for(int i = 0; i < lista_emprestimos.size(); i++){
		if(lista_emprestimos[i] == emp){
			for(int j = 0; j < lista_emprestimos[i].get_sizeitens(); j++){
				if(item_emp == lista_emprestimos[i].get_item(j)){	
					lista_emprestimos[i].get_itens().erase(lista_emprestimos[i].get_itens().begin() + j);
				}
			}
		}
	}
}

void Biblioteca::devolve_item(Emprestimo emp, Livro livro){
	for(int i = 0; i < lista_emprestimos.size(); i++){
		if(lista_emprestimos[i] == emp){
			for(int j = 0; j < lista_emprestimos[i].get_sizeitens(); j++){
				if(livro.get_codPub() == lista_emprestimos[i].get_codPub(j)){
					lista_emprestimos[i].devolve_livro(livro);
				}
			}
		}
	}
}

void Biblioteca::devolve_todos(Emprestimo emp){
	for(int i = 0; i < lista_emprestimos.size(); i++){
		if(lista_emprestimos[i] == emp)
			lista_emprestimos[i].devolve_todos();			
	}
}

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

vector<Publicacao*> Biblioteca::pesquisa_publicacao(std::string parte_do_titulo){
	vector<Publicacao*> p_aux;
	size_t found;
	for(int i = 0; i < lista_publicacoes.size(); i++){
		found = lista_publicacoes[i]->get_titulo().find(parte_do_titulo);
		if (found != string::npos){
			if(lista_publicacoes[i]->compare_titulo(found, parte_do_titulo.length(), parte_do_titulo) == 0)
				p_aux.push_back(lista_publicacoes[i]);
		}
	}
	return p_aux;
}

vector<Livro> Biblioteca::pesquisa_por_autor(std::string parte_do_autor){
	vector<Livro> l_aux;
	size_t found;
	for(int i = 0; i < lista_publicacoes.size(); i++){
		if (dynamic_cast<Livro*>(&(*lista_publicacoes[i]))){
			Livro* livro = dynamic_cast<Livro*>(&(*lista_publicacoes[i]));
			found = livro->get_autores().find(parte_do_autor);
			if (found != string::npos){
				if(livro->compare_autores(found, parte_do_autor.length(), parte_do_autor) == 0 || livro->compare_autores(found, parte_do_autor.length(), parte_do_autor) > 3){
					Livro &l = (Livro&)(*lista_publicacoes[i]);
					l_aux.push_back(l);
				}
			}
		}
	}
	return l_aux;
}				


