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
			case 15:
				lista_usuarios();
				break;
			case 16:
				lista_publicacoes();
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
	
}

void Interface::cadastra_novo_periodico(){
	int codPub, ano, numero_edicao;
	string titulo, editora, mes;
	cout << "Cadastrando livro " << endl;
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

void Interface::lista_publicacoes(){
	vector<Publicacao> lista_de_publicacoes;
	lista_de_publicacoes = biblio.get_lista_publicacoes();
	for (int i=0; i < lista_de_publicacoes.size(); i++){
		cout << "Codigo da Publicacao: " << lista_de_publicacoes[i].get_codPub() << endl;
		cout << "Ano: " << lista_de_publicacoes[i].get_ano() << endl;
		cout << "Titulo: " << lista_de_publicacoes[i].get_titulo() << endl;
		cout << "Editora: " << lista_de_publicacoes[i].get_editora() << endl;
		cout << endl;
	}
	cout << "Aperte enter para retornar ao menu ..." << endl;
	cin.get() ;
}
