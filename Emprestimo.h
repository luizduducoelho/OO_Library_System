#ifndef EMPRESTIMO_H
#define EMPRESTIMO_H

#include "Usuario.h"
#include "ItemEmprestimo.h"
#include "Date.h"
#include "Livro.h"
#include <vector>

using std::vector;

class Emprestimo
{
		static int proximoNumero;
		int numero;
		Usuario usuario;
		Date dataEmprestimo, dataPrevDevolucao;
		vector<ItemEmprestimo> itens;
	public:
		Emprestimo(Usuario user, Date devolucao): numero(proximoNumero++), usuario(user), dataPrevDevolucao(devolucao) {};
		void adiciona_livro(Livro &novo_livro);
		void exclui_livro(Livro &livro_excluido);
		void devolve_livro(Livro &livro_devolvido);
		void devolve_todos();
};

#endif
/*
� Classe Emprestimo:

O atributo proximoNumero deve ser est�tico e ser� usado para armazenar o pr�ximo n�mero de empr�stimo. A lista
de itens de empr�stimos pode ser implementada atrav�s da classe Vector;
� deve existir um m�todo construtor que inicializa os atributos com os seguintes valores: numero (pr�ximo
n�mero sequencial), dataEmprestimo (data corrente do sistema), dataPrevDevolucao e usu�rio (passados
como argumentos);
� deve existir um m�todo para adicionar um item (livro) ao empr�stimo. Argumento: o livro. A quantidade
de exemplares do livro deve ser decrementada de uma unidade (verificar se a quantidade � suficiente);
� deve existir um m�todo para excluir um item (livro) do empr�stimo. Argumento: o livro a ser exclu�do. A
quantidade de exemplares do livro deve ser incrementada de uma unidade;
� deve existir um m�todo para devolver um item (livro) do empr�stimo. Argumento: o livro a ser
devolvido. A quantidade de exemplares do livro deve ser incrementada de uma unidade. A data de
devolu��o do item deve ser atualizada pela data do sistema;
� deve existir um m�todo para devolver todos os livros do empr�stimo. A quantidade de exemplares de
todos os itens (livros) do empr�stimo deve ser incrementada

*/
