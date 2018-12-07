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

int Emprestimo::proximoNumero = 0;

int main(){
	
	///////// Livro
	int codigo = 0002, ano = 1998;
	string titulo = "Who ordered this truckload of dong";
	string edicao = "Segunda edicao em Pt", autor = "Ajahn B";
	int quantidade = 1;
	Livro l1(codigo, ano, titulo, edicao, autor, quantidade);
	l1.decrementa();
	l1.decrementa();
	l1.decrementa();
	l1.incrementa();
	quantidade = l1.get_quantidade();
	cout << "Temos " << quantidade << " livros" << endl;
	
	////////// Emprestimo
	string nome="Luiz C", cpf="127.999.000-46", endereco="Rua Feliz, BH", fone="35 99999-0000";
	Usuario luiz(nome, cpf, endereco, fone);
	Date devolucao;
	devolucao.adiciona_dias(30);
	cout << "Devolver dia " << devolucao.get_date() << endl;
	Emprestimo meu_emprestimo(luiz, devolucao);
	meu_emprestimo.adiciona_livro(l1);
	cout << "Temos " << l1.get_quantidade() << " livros" << endl;
	meu_emprestimo.adiciona_livro(l1);
	cout << "Temos " << l1.get_quantidade() << " livros" << endl;
	meu_emprestimo.exclui_livro(l1);
	cout << "Temos " << l1.get_quantidade() << " livros" << endl;
	meu_emprestimo.adiciona_livro(l1);
	cout << "Temos " << l1.get_quantidade() << " livros" << endl;
	meu_emprestimo.adiciona_livro(l1);
	cout << "Temos " << l1.get_quantidade() << " livros" << endl;
	
	/////////// Interface
	cout << endl;
	Interface interface;
	interface.menu();
	
	return 0;
}
