#include "Interface.h"
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <cstdlib>

Interface::Interface(){
	
}

using namespace std;

/*int Interface::le_inteiro(){
	int x;
	cin >> x;
	while(cin.fail()) {
        cout << "ERRO. Digite um inteiro: " ;
        cin.clear();
        cin.ignore(256,'\n');
        cin >> x;
    }
    return x;
}*/

int Interface::le_inteiro(){
	int x;
	string user_input;
	std::getline(cin, user_input);
	
	while(cin.fail() || cin.eof() || user_input.find_first_not_of("0123456789") != string::npos) {
	    std::cout << "ERRO. Digite um inteiro: ";
	    if( user_input.find_first_not_of("0123456789") == std::string::npos) {
	        cin.clear();
	        cin.ignore(256,'\n');
	    }
	    std::getline(cin, user_input);
    }
    x = atoi(user_input.c_str());
    return x;
}

void Interface::menu(){
	int number_of_stars = 36;
	vector<string> menu_messages;
	menu_messages.push_back(std::string("Cadastrar usuario"));
	menu_messages.push_back(std::string("Cadastrar livro"));
	menu_messages.push_back(std::string("Cadastrar periodico"));
	menu_messages.push_back(std::string("Cadastrar emprestimo"));
	menu_messages.push_back(std::string("Inserir novo item de emprestimo"));
	menu_messages.push_back(std::string("Excluir um usuario"));
	menu_messages.push_back(std::string("Excluir um livro"));
	menu_messages.push_back(std::string("Excluir um periodico"));
	menu_messages.push_back(std::string("Excluir um emprestimo"));
	menu_messages.push_back(std::string("Excluir um item do emprestimo"));
	menu_messages.push_back(std::string("Devolver todos os itens do emprestimo"));
	menu_messages.push_back(std::string("Devolver um livro do emprestimo"));
	menu_messages.push_back(std::string("Pesquisar publicacao por titulo"));
	menu_messages.push_back(std::string("Pesquisar livro por autor"));
	menu_messages.push_back(std::string("Listar todos os usuarios"));
	menu_messages.push_back(std::string("Listar todas as publicacoes"));
	menu_messages.push_back(std::string("Listar todos os emprestimos"));
	menu_messages.push_back(std::string("Sair do programa"));
	
	bool continue_program = true;
	while(continue_program){
		// Exibe menu
		system("cls");
		std::cout << std::string(number_of_stars, '*') << std::endl;
		for(int i=0; i < menu_messages.size(); i++){
			std::cout << i+1 << "_ " << menu_messages[i] << std::endl;
		}
		std::cout << std::string(number_of_stars, '*') << std::endl;
		
		
		// Seleciona item pelo usuario
		int tecla;
		tecla = le_inteiro();
		cout << endl;
		
		// Chama funcao
		switch(tecla){
			case 1:
				cadastra_novo_usuario();
				break;
			case 2:
				cadastra_novo_livro();
				break;
			case 3:
				cadastra_novo_periodico();
				break;
			case 4:
				cadastra_novo_emprestimo();
				break;
			case 5:
				inserir_novo_item_emprestimo();
				break;
			case 6:
				excluir_usuario();
				break;
			case 7:
				excluir_livro();
				break;
			case 15:
				lista_usuarios();
				break;
			case 16:
				lista_publicacoes();
				break;
			case 17:
				lista_emprestimos();
				break;
			case 18:
				std::cout << "Fim do programa" << std::endl;
				continue_program = false;
				break;
			default:
				std::cout << "Tecla invalida " << std::endl;
				break;
		}
	}
	
}

void Interface::cadastra_novo_usuario(){
	string nome, cpf, endereco, telefone;
	cout << "Cadastrando usuario" << endl;
	cout << "Digite o nome do usuario: ";
	std::getline(cin, nome);
	cout << "Digite o cpf: ";
	std::getline(cin, cpf);
	cout << "Digite o endereco: ";
	std::getline(cin, endereco);
	cout << "Digite o telefone: ";
	std::getline(cin, telefone);
	cout << endl << endl;
	
	Usuario user(nome, cpf, endereco, telefone);
	biblio.insere_usuario(user);
}

void Interface::cadastra_novo_livro(){
	int codPub, ano, qt;
	string titulo, editora, autor;
	cout << "Cadastrando livro " << endl;
	cout << "Codigo da publicacao: ";
	codPub = le_inteiro();
	cout << "Ano: ";
	ano = le_inteiro();
	cout << "Titulo: ";
	std::getline(cin, titulo);
	cout << "Editora: ";
	getline(cin, editora);
	cout << "Autor: ";
	getline(cin, autor);
	cout << "Quantidade: ";
	qt = le_inteiro();
	
	Livro livro(codPub, ano, titulo, editora, autor, qt);
	biblio.insere_publicacao(livro);
	
	cout << "Aperte enter para retornar ao menu ..." << endl;
	cin.get() ;
	
}

void Interface::cadastra_novo_periodico(){
	int codPub, ano, numero_edicao;
	string titulo, editora, mes;
	cout << "Cadastrando periodico " << endl;
	cout << "Codigo da publicacao: ";
	codPub = le_inteiro();
	cout << "Ano: ";
	ano = le_inteiro();
	cout << "Titulo: ";
	std::getline(cin, titulo);
	cout << "Editora: ";
	getline(cin, editora);
	cout << "Mes: ";
	getline(cin, mes);
	cout << "Numero edicao: ";
	numero_edicao = le_inteiro();
	
	Periodico period(codPub, ano, titulo, editora, numero_edicao, mes);
	biblio.insere_publicacao(period);
}

void Interface::cadastra_novo_emprestimo(){
	int dias_a_emprestar, indice_do_usuario;
	string cpf;
	vector<Usuario> lista_usuarios = biblio.get_lista_usuarios();
	bool existe = false;
	cout << "Cadastrando emprestimo " << endl;
	cout << "CPF do usuario: ";
	getline(cin, cpf);
	for(int i=0; i<lista_usuarios.size(); i++){
		if (lista_usuarios[i].get_cpf() == cpf){
			cout << "Usuario " << lista_usuarios[i].get_nome() << " encontrado !" << endl;
			indice_do_usuario = i;
			existe = true;
		}
	}
	if (!existe){
		cout << "CPF nao existe, tente novamente!" << endl;
	}
	else{
	cout << "Dias a emprestar: ";
	dias_a_emprestar = le_inteiro();
	Date data_devolucao;
	data_devolucao.adiciona_dias(dias_a_emprestar);
	
	Emprestimo emprestimo(lista_usuarios[indice_do_usuario], data_devolucao);
	biblio.insere_emprestimo(emprestimo);
	cout << "Emprestimo cadastrado! " << endl;
	cout << lista_usuarios[indice_do_usuario].get_nome() << " favor devolver ate " << data_devolucao.get_date();
	}
	cout << "Aperte enter para retornar ao menu ..." << endl;
	cin.get() ;
}

void Interface::inserir_novo_item_emprestimo(){
	vector<Emprestimo> lista_emprestimos = biblio.get_lista_emprestimos();
	vector<Publicacao*> lista_publicacoes = biblio.get_lista_publicacoes();
	int numero, indice_do_emprestimo, indice_do_livro, codPub;
	cout << "Inserindo item de emprestimo " << endl;
	cout << "Numero do emprestimo: ";
	numero = le_inteiro();
	bool existe;
	for(int i=0; i<lista_emprestimos.size(); i++){
		if (lista_emprestimos[i].get_numero() == numero){
			cout << "Emprestimo " << lista_emprestimos[i].get_numero() << " encontrado !" << endl;
			indice_do_emprestimo = i;
			existe = true;
		}
	}
	if (!existe){
		cout << "Emprestimo nao existe, tente novamente!" << endl;
		cout << "Aperte enter para retornar ao menu ..." << endl;
		cin.get();
		return;
	}
	cout << "Digite o codigo do livro: ";
	codPub = le_inteiro();
	existe = false;
	for(int i=0; i<lista_publicacoes.size(); i++){
		if ((*lista_publicacoes[i]).get_codPub() == codPub){
			cout << "Livro " << (*lista_publicacoes[i]).get_titulo() << " encontrado !" << endl;
			indice_do_livro = i;
			existe = true;
		}
	}
	if (!existe){
		cout << "Livro nao existe, tente novamente!" << endl;
		cout << "Aperte enter para retornar ao menu ..." << endl;
		cin.get();
		return;
	}
	if (dynamic_cast<Livro*>(lista_publicacoes[indice_do_livro])){
		Livro * livro = dynamic_cast<Livro*>(lista_publicacoes[indice_do_livro]);
		Livro livro_obj = *livro;
		ItemEmprestimo item(livro_obj);
		biblio.insere_item_emprestimo(lista_emprestimos[indice_do_emprestimo], item);
		cout << "Item " << livro_obj.get_titulo() << " inserido! " << endl;
	}
	else{
		cout << "Erro ao indexar livro" << endl;
	}
	cout << "Aperte enter para retornar ao menu ..." << endl;
	cin.get() ;
	
}

void Interface::lista_usuarios(){
	vector<Usuario> lista_de_usuarios;
	lista_de_usuarios = biblio.get_lista_usuarios();
	for (int i=0; i < lista_de_usuarios.size(); i++){
		cout << "Nome: " << lista_de_usuarios[i].get_nome() << endl;
		cout << "CPF: " << lista_de_usuarios[i].get_cpf() << endl;
		cout << "Endereco: " << lista_de_usuarios[i].get_endereco() << endl;
		cout << "Telefone: " << lista_de_usuarios[i].get_fone() << endl;
		cout << endl;
	}
	cout << "Aperte enter para retornar ao menu ..." << endl;
	//cin.ignore();
	cin.get() ;
}

void Interface::excluir_usuario(){
	int indice_do_usuario;
	string cpf;
	vector<Usuario> lista_usuarios = biblio.get_lista_usuarios();
	bool existe = false;
	cout << "Excluindo um usuario" << endl;
	cout << "CPF do usuario: ";
	getline(cin, cpf);
	for(int i=0; i<lista_usuarios.size(); i++){
		if (lista_usuarios[i].get_cpf() == cpf){
			cout << "Usuario " << lista_usuarios[i].get_nome() << " encontrado !" << endl;
			indice_do_usuario = i;
			existe = true;
		}
	}
	if (!existe){
		cout << "CPF nao existe, tente novamente!" << endl;
	}
	else{
		biblio.exclui_usuario(lista_usuarios[indice_do_usuario]);
		//cout << "Usuario " << lista_usuarios[indice_do_usuario].get_nome() << " excluido com sucesso" << endl;
	}
	cout << "Aperte enter para retornar ao menu ..." << endl;
	cin.get() ;
}

void Interface::lista_publicacoes(){
	/*cout << "Temos " << biblio.get_publicacoes_size() << " Publicacoes" << endl;
	for (int i=0; i < biblio.get_publicacoes_size(); i++){
		cout << "Iteration " << i << endl;
		cout << "Codigo da Publicacao: " << biblio.get_codPub(i) << endl;
		cout << "Ano: " << biblio.get_ano(i) << endl;
		cout << "Titulo: " << biblio.get_titulo(i) << endl;
		cout << "Editora: " << biblio.get_editora(i) << endl;
		cout << endl;
	}*/
	biblio.imprime_publicacoes();
	cout << "Aperte enter para retornar ao menu ..." << endl;
	cin.get() ;
}

void Interface::lista_emprestimos(){
	vector<Emprestimo> lista_de_emprestimos;
	lista_de_emprestimos = biblio.get_lista_emprestimos();
	for (int i=0; i < lista_de_emprestimos.size(); i++){
		cout << "Emprestimo numero " << lista_de_emprestimos[i].get_numero() << endl;
		cout << "Usuario: " << lista_de_emprestimos[i].get_nome_usuario() << endl;
		vector<ItemEmprestimo> vetor_de_itens = lista_de_emprestimos[i].get_itens();
		cout << "Emprestimo tem " << vetor_de_itens.size() << " livros" << endl;
		for (int j=0; j < vetor_de_itens.size(); j++){
			cout << "Item " << vetor_de_itens[j].get_titulo() << endl;
		}
		cout << "Data de devolucao: " << lista_de_emprestimos[i].get_data_devolucao() << endl;
		cout << endl;
	}
	cout << "Aperte enter para retornar ao menu ..." << endl;
	cin.get() ;
}

void Interface::excluir_livro(){
	int codPub, indice_do_livro;
	bool existe = false;
	vector<Publicacao*> lista_publicacoes = biblio.get_lista_publicacoes();
	cout << "Digite o codigo do livro: ";
	codPub = le_inteiro();
	for(int i=0; i<lista_publicacoes.size(); i++){
		if ((*lista_publicacoes[i]).get_codPub() == codPub){
			cout << "Livro " << (*lista_publicacoes[i]).get_titulo() << " encontrado !" << endl;
			indice_do_livro = i;
			existe = true;
		}
	}
	if (!existe){
		cout << "Livro nao existe, tente novamente!" << endl;
		cout << "Aperte enter para retornar ao menu ..." << endl;
		cin.get();
		return;
	}
	if (dynamic_cast<Livro*>(lista_publicacoes[indice_do_livro])){
		Livro * livro = dynamic_cast<Livro*>(lista_publicacoes[indice_do_livro]);
		Livro livro_obj = *livro;
		biblio.exclui_publicacao(livro_obj);
	}
	else{
		cout << "Erro. Publicacao nao e um livro" << endl;
	}
	cout << "Aperte enter para retornar ao menu ..." << endl;
	cin.get() ;
}

