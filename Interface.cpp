#include "Interface.h"
#include <string>
#include <vector>
#include <iostream>

Interface::Interface(){
	
}

using namespace std;

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
		std::cout << std::string(number_of_stars, '*') << std::endl;
		for(int i=0; i < menu_messages.size(); i++){
			std::cout << i+1 << "_ " << menu_messages[i] << std::endl;
		}
		std::cout << std::string(number_of_stars, '*') << std::endl << std::endl << std::endl;
		
		
		// Seleciona item pelo usuario
		int tecla;
		std::cin >> tecla;   // TRATAR ENTRADAS INVALIDAS
		
		// Chama funcao
		switch(tecla){
			case 1:
				cadastra_novo_usuario();
				break;
			case 15:
				lista_usuarios();
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
	cout << "Aperte para retornar ao menu ...";
	getc;
}
