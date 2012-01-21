//============================================================================
// Name        : games.cpp
// Author      : Daniel Sader Pontello Neves
// Version     : 0.1
// Copyright   : 
// Description : Projeto
//============================================================================

#include <iostream>
#include <cstring>

using namespace std;

struct jogo {
	char nome[256];
	char genero[256];
	char produtora[256];
	int codigo;
	int estoque;
	int preco;
} jogos[1024];

int numjogos = 0;

void ajuda() {
	cout << "Comandos disponiveis:" << endl;
	cout << endl;
	cout << "cadastrar - Cadastra novo produto" << endl;
	cout << "editar    - Edita um produto" << endl;
	cout << "remover   - Remove um produto" << endl;
	cout << "pesquisar - Pesquisa por um produto" << endl;
	cout << "listar    - Lista produtos" << endl;
	cout << "sair      - Sai do programa" << endl;

}

void cadastrar() {
	cout << "Cadastro" << endl;
	cout << "Nome do produto:";
	cin.getline(jogos[numjogos].nome, 256);
	cout << "Genero:";
	cin.getline(jogos[numjogos].genero, 256);
	cout << "Produtora:";
	cin.getline(jogos[numjogos].produtora, 256);
	cout << "Codigo:";
	cin >> jogos[numjogos].codigo;
	cout << "Preco:";
	cin >> jogos[numjogos].preco;
	cout << "Quantidade em estoque:";
	cin >> jogos[numjogos].estoque;
	cout << "Cadastro realizado com sucesso." << endl;
	numjogos++;
}

void listar() {
	if (numjogos == 0) {
		cout << "Nenhum produto encontrado" << endl;
		return;
	}

	for (int i = 0; i < numjogos; i++) {
		cout << "Nome     :" << jogos[i].nome << endl;
		cout << "Genero   :" << jogos[i].genero << endl;
		cout << "Produtora:" << jogos[i].produtora << endl;
		cout << "Codigo   :" << jogos[i].codigo << endl;
		cout << "Preco    :" << jogos[i].preco << endl;
		cout << "Estoque  :" << jogos[i].estoque << endl;
		cout << endl;
	}
}

void pesquisar() {
	char prod[256];
	cout << "Produto a ser pesquisado:" << endl;
	cin.getline(prod, 256);
	for (int j = 0; j < numjogos; j++) {
		if (strcmp(jogos[j].nome, prod) == 0) {
			cout << "Nome     :" << jogos[j].nome << endl;
			cout << "Genero   :" << jogos[j].genero << endl;
			cout << "Produtora:" << jogos[j].produtora << endl;
			cout << "Codigo   :" << jogos[j].codigo << endl;
			cout << "Preco    :" << jogos[j].preco << endl;
			cout << "Estoque  :" << jogos[j].estoque << endl;
		} else {
			cout << "Produto nao encontrado." << endl;
		}
	}
}

void editar() {
	char prod[256];
	cout << "Produto a ser editado:" << endl;
	cin.getline(prod, 256);
	for (int j = 0; j < numjogos; j++) {
		if (strcmp(jogos[j].nome, prod) == 0) {
			cout << "Produto sendo editado:" << endl;
			cout << "Nome     :" << jogos[j].nome << endl;
			cout << "Genero   :" << jogos[j].genero << endl;
			cout << "Produtora:" << jogos[j].produtora << endl;
			cout << "Codigo   :" << jogos[j].codigo << endl;
			cout << "Preco    :" << jogos[j].preco << endl;
			cout << "Estoque  :" << jogos[j].estoque << endl;
			cout << endl;
			cout << "Novo nome: ";
			cin.getline(jogos[j].nome, 256);
			cout << "Novo genero: ";
			cin.getline(jogos[j].genero, 256);
			cout << "Nova produtora: ";
			cin.getline(jogos[j].produtora, 256);
			cout << "Novo codigo: ";
			cin >> jogos[j].codigo;
			cout << "Novo preco: ";
			cin >> jogos[j].preco;
			cout << "Novo estoque: ";
			cin >> jogos[j].estoque;
			cout << endl;
			cout << "Edicao completa." << endl;
			return;
		} else {
			cout << "Produto nao encontrado." << endl;
		}
	}
}

void remover() {
	char prod[256];
	cout << "Produto a ser removido:" << endl;
	cin.getline(prod, 256);
	for (int j = 0; j <= numjogos; j++) {
		if (strcmp(jogos[j].nome, prod) == 0) {
			strcpy(jogos[j].nome, jogos[numjogos-1].nome);
			strcpy(jogos[j].genero, jogos[numjogos-1].genero);
			strcpy(jogos[j].produtora, jogos[numjogos-1].produtora);
			jogos[j].codigo = jogos[numjogos-1].codigo;
			jogos[j].preco = jogos[numjogos-1].preco;
			jogos[j].estoque = jogos[numjogos-1].estoque;
			numjogos--;
		} else {
			cout << "Produto nao encontrado." << endl;
		}
	}
}

	int main() {
		char comando[64];
		cout << "Cadastro v1.0" << endl;
		ajuda();
		while (true) {
			cout << "comando> ";
			cin.getline(comando, 64);
			if (strcmp(comando, "cadastrar") == 0) {
				cadastrar();
			} else if (strcmp(comando, "editar") == 0) {
				editar();
			} else if (strcmp(comando, "remover") == 0) {
				remover();
			} else if (strcmp(comando, "pesquisar") == 0) {
				pesquisar();
			} else if (strcmp(comando, "ajuda") == 0) {
				ajuda();
			} else if (strcmp(comando, "listar") == 0) {
				listar();
			} else if (strcmp(comando, "sair") == 0) {
				cout << "Saindo..." << endl;
				break;
			} else {
				cout
						<< "Comando nao reconhecido. Digite ajuda para mais informações."
						<< endl;
			}
		}
		return 0;
	}
