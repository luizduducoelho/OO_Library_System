#ifndef EMPRESTIMO_H
#define EMPRESTIMO_H

#include "Usuario.h"
#include "ItemEmprestimo.h"
#include <vector>

using std::vector;

class Emprestimo
{
		static int proximoNumero;
		int numero;
		Usuario usuario;
		vector<ItemEmprestimo> itens;
	public:
};

#endif
/*
• Classe Emprestimo:

O atributo proximoNumero deve ser estático e será usado para armazenar o próximo número de empréstimo. A lista
de itens de empréstimos pode ser implementada através da classe Vector;
§ deve existir um método construtor que inicializa os atributos com os seguintes valores: numero (próximo
número sequencial), dataEmprestimo (data corrente do sistema), dataPrevDevolucao e usuário (passados
como argumentos);
§ deve existir um método para adicionar um item (livro) ao empréstimo. Argumento: o livro. A quantidade
de exemplares do livro deve ser decrementada de uma unidade (verificar se a quantidade é suficiente);
§ deve existir um método para excluir um item (livro) do empréstimo. Argumento: o livro a ser excluído. A
quantidade de exemplares do livro deve ser incrementada de uma unidade;
§ deve existir um método para devolver um item (livro) do empréstimo. Argumento: o livro a ser
devolvido. A quantidade de exemplares do livro deve ser incrementada de uma unidade. A data de
devolução do item deve ser atualizada pela data do sistema;
§ deve existir um método para devolver todos os livros do empréstimo. A quantidade de exemplares de
todos os itens (livros) do empréstimo deve ser incrementada

*/
