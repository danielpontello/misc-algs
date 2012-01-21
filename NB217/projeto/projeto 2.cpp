#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;

struct the_cond {
	char nome[50];
	int bloco;
	int num;
	bool in_out;
};

int t=0;

the_cond cond[500];
int nmc = 0; //numero de moradores do condominio
int posdel = 0; //posicao do morador deletado

FILE *p;

void inclusao(void) {
	int t = 0, c = 0; //critica de dados
	char nom[50];
	//fseek(p,0,SEEK_SET);
	//fread(&c,sizeof(c),1,p);
	cout << "CADASTRO DE MORADORES\n\n";
	do {
		cin.ignore();
		cout << "Nome do morador: ";
		cin.getline(cond[nmc].nome, 50);
		strcpy(nom, cond[nmc].nome);

		for (int i = 0; i < nmc; i++)
			if (strcmp(nom, cond[i].nome) == 0)
				c++;
		if (c == 0) {
			cout << "Bloco do apartamento do morador: ";
			do {
				cin >> cond[nmc].bloco;
			} while (cond[nmc].bloco <= 0);

			cout << "Numero apartamento: ";
			do {
				cin >> cond[nmc].num;
			} while (cond[nmc].num <= 0);

			cond[nmc].in_out = true;
			nmc++;
			cout << "\nDESEJA CADASTRAR MAIS ALGUM MORADOR?\n"
					<< "[0]NAO / [1]SIM: ";
			cin >> t;
		} else {
			cout << "MORADOR JA CADASTRADO!\n";
			t = 1;
			c = 0;
		}
		cout
				<< ".............................................................\n";

	} while (t == 1);
	cout << "\nCADASTRO FINALIZADO COM SUCESSO!";
	cout << "\n(APERTE ENTER PARA VOLTAR AO MENU)";
}
;

void edicao(void) {
	char nom[50];
	int c = 0, t = 1; //critica de dados
	cout << "EDICAO DE DADOS";
	do {
		cin.ignore();
		cout << "\nEntre com o nome do morador cujos dados serao EDITADOS: ";
		cin.getline(nom, 50);

		for (int i = 0; i < nmc; i++) {
			/*  salto = sizeof(carros)*i+sizeof(c);
			 fseek(p,salto,SEEK_SET);
			 fread(&condominio,sizeof(condominio),1,p);*/
			if (strcmp(nom, cond[i].nome) == 0) {
				//cin.ignore();
				cout << "Entre com novo NOME: " << endl;
				cin.getline(cond[i].nome, 50);
				cout << "Entre com novo BLOCO: " << endl;
				cin >> cond[i].bloco;
				cout << "Entre com novo NUMERO do apartamento: " << endl;
				cin >> cond[i].num;
				cond[i].in_out=true;
				c = 1;
			}
			if (c == 0)
				cout << "\nNAO HA NENHUM MORADOR COM O NOME DIGITADO!";
		}
		cout << "\nDESEJA SAIR DA EDICAO OU TENTAR OUTRO NOME?";
		cout << "\n[0]SAIR / [1]NOVO NOME: ";
		cin >> t;
	} while (t == 1);
	cout << "\nEDICAO DE DADOS FINALIZADA!";
	cout << "\n(APERTE ENTER PARA VOLTAR AO MENU)";
}
;

void entrada() {
	char nom[50];
	int c;
	c = 0;
do {
			cout << "Nome do morador que vai sair/entrar: ";
			cin >> nom;
			for (int i = 0; i < nmc; i++) {
				/*salto = sizeof(condom)*i+sizeof(c);
				 fseek(p,salto,SEEK_SET);
				 fread(&condominio,sizeof(condominio),1,p);*/
				if (strcmp(nom, cond[i].nome) == 0) {
						cond[i].in_out = !cond[i].in_out;
						cout << ".............................................................\n";
						cout << "\nATUALIZADO!" << nom << " deixou o THE COND.\n";
						c = 1;
				}
			}
			c = 1;
			if (c == 0)
				cout << "\nNAO HA NENHUM MORADOR COM ESTE NOME NO CONDOMINIO!\n";
		} while (c == 0);
}

void pesquisa(void) {
	int c = 0, t = 1;
	char nom[50];
	cout << "PESQUISA DE DADOS DOS MORADORES DESTE CONDOMINIO";
	do {
		cin.ignore();
		cout << "\nEntre com o nome do morador cujos dados serao PESQUISADOS:";
		cin.getline(nom, 50);

		for (int i = 0; i < nmc; i++) {
			/*salto = sizeof(condom)*i+sizeof(c);
			 fseek(p,salto,SEEK_SET);
			 fread(&condominio,sizeof(condom),1,p);*/
			if (strcmp(nom, cond[i].nome) == 0) {
				cout << "Morador: " << cond[i].nome << endl;
				cout << "Bloco: " << cond[i].bloco << endl;
				cout << "Numero: " << cond[i].num << endl;
				cout << "Esta no condominio?: " << cond[i].in_out << endl;
				c = 1;
			}
		}
		if (c == 0)
			cout << "\nNAO HA NENHUM MORADOR COM O NOME DIGITADO!";

		cout << "\nDESEJA SAIR DA EDICAO OU TENTAR OUTRO NOME?";
		cout << "\n[0]SAIR / [1]NOVO NOME: ";
		cin >> t;

	} while (t == 1);
	cout << "\nPESQUISA DE DADOS FINALIZADA!";
	cout << "\n(APERTE ENTER PARA VOLTAR AO MENU)";
}
;

void listagem(void) {
	cout << "\nMORADORES DENTRO DO CONDOMINIO: ";
	for (int j = 0; j < nmc; j++) {
		if (cond[j].in_out == true) {
			cout << endl;
			cout << cond[j].nome;
			t = 1;
		}
	}

	cout << "\n MORADORES FORA DO CONDOMINIO: ";
	for (int j = 0; j < nmc; j++) {
			if (cond[j].in_out == false) {
				cout << endl;
				cout << cond[j].nome;
				t = 1;
			}
	}
}
;

void exclusao(void) {
	char nom[50];
	cin.ignore();
	cout << "EXCLUSAO DE DADOS\n";
	cout << "Entre com o nome do morador cujos dados serao excluidos: ";
	cin.getline(nom, 50);

	for (int i = 0; i < nmc; i++) {
		/*salto = sizeof(carros)*i+sizeof(c);
		 fseek(p,salto,SEEK_SET);
		 fread(&condominio,sizeof(condominio),1,p);*/
		if (strcmp(nom, cond[i].nome) == 0) {
			cin.ignore();
			cout << "Dados do morador " << cond[i].nome << " foram deletados";
			strcpy(cond[i].nome, cond[nmc].nome);
			cond[i].bloco = cond[nmc].bloco;
			cond[i].num = cond[nmc].num;
			cond[i].in_out = cond[nmc].in_out;
			// posdel=i;
		}
	}
}
;

int main() {
	//int nmc; //numero de moradores do condominio

	int op;

	p = fopen("cond.txt", "rb+");
	if (p == NULL) {
		p = fopen("cond.txt", "wb+");
		if (p == NULL)
			return 0;
	}

	do {
		system("cls");
		cout << "CONDOMINIO THE COND" << endl << "REGISTRO DE MORADORES" << endl;
		cout << "1 - Cadastrar\n";
		cout << "2 - Editar\n";
		cout << "3 - Excluir\n";
		cout << "4 - Pesquisar\n";
		cout << "5 - Listar\n";
		cout << "6 - Entrada e Saida\n";
		cout << "7 - Sair\n";
		cout << "\n O QUE VOCE DESEJA? (ESCOLHA UMA DAS 6 OPCOES): ";
		cin >> op;
		cout
				<< ".............................................................\n";

		switch (op) {
		case 1:
			inclusao();
			break;

		case 2:
			edicao();
			break;

		case 3:
			exclusao();
			break;

		case 4:
			pesquisa();
			break;

		case 5:
			listagem();
			break;

		case 6:
			entrada();
			break;

		case 7:
			cout << "\n       REGISTRO DE MORADORES ENCERRADO!";
			cout << "\n       OBRIGADO . CONDOMINIO THE CONDON";
			return 0;
			break;

		default:
			cout << "OPCAO MARCADA NAO CONSTA NO MENU!";
			cout << "\nPOR FAVOR, TENTE NOVAMENTE..";
			cout
					<< "\n.............................................................\n";
			break;
		}
		cin.ignore();
		cin.get();
	} while (op != 6);
	fclose(p);
}
