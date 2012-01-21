#include<iostream>
#include<cstring>
using namespace std;

struct condominio
{
     char nome[50];
     int bloco;
     int num;
     int in_out=0;
}

void inclusao(void)
{
     fseek(p,0,SEEK_SET);
     fread(&c,sizeof(c),1,p);
                      
     cin.ignore();
     cout<<"Entre com o nome do morador: ";
     cin.getline(condominio[nmc].nome,50);
     cout<< "Entre com o bloco da casa do morador: ";
     cin>> condominio[nmc].bloco;
     cout<< "Entre com o numero da casa: ";
     cin>> condominio[nmc].num;
     condominio[nmc]in_out=1;
     nmc++;
     cout<<endl;
}
     
void edicao(void)
{
    char nom[50];
    cin.ignore();
    cout << "Entre com o nome do morador cujos dados serao editados: ";
    cin.getline(nom,50);
    
    for(int i=0;i<nmc;i++)
    {
        salto = sizeof(carros)*i+sizeof(c);
        fseek(p,salto,SEEK_SET);
        fread(&condominio,sizeof(condominio),1,p);
        if(strcmp(nom,condominio[i].nome)==0) 
        {
            cin.ignore();
            cout << "Novo nome: " << endl;
            cin.getline(condominio[i].nome,50); 
            cout << "Novo bloco: " << endl;
            cin >> condominio[i].bloco;
            cout << "Novo numero: " << endl;
            cin>> condominio[i].num;
        }
    }
} 
     
void pesquisa(void)
{
    char nom[50];
    cin.ignore();
    cout << "Entre com o nome do morador cujos dados serao pesquisados:";
    cin.getline(nom,50);
    
    for(int i=0;i<nmc;i++)
    {
        salto = sizeof(condominio)*i+sizeof(c);
        fseek(p,salto,SEEK_SET);
        fread(&condominio,sizeof(condominio),1,p);
        if(strcmp(nom,condominio[i].nome)==0) 
        {
            cout << "Morador: " << condominio[i].nome << endl;
            cout << "Bloco: " << condominio[i].bloco << endl;
            cout << "Numero: " << condominio[i].num << endl;
        }
    }
}

void listagem(void)
{
    char nom[50];
    int inside;
    cout << "Deseja atualizar se o morador se encontra no condominio? 1-Sim 2-Nao";
    cin >> inside;
    
    switch(inside)
    {
        case 1: 
             cout << "Entre com o nome do morador que deseja atualizar";
             cin >> nom;
             for(int i=0;i<nmc;i++)
             {
                salto = sizeof(condominio)*i+sizeof(c);
                fseek(p,salto,SEEK_SET);
                fread(&condominio,sizeof(condominio),1,p);
                if(strcmp(nom,condominio[i].nome)==0) 
                   {
                       if(condominio[i].in_out==0)
                          condominio[i].in_out = 1;
                          else
                             condominio[i].in_out = 0;
                       
             }
             break;
        case 2:
             break;
    }
    cout << "Moradores que estao no condominio: ";
    for(int j=0;j<nmc;j++)
    {
        if(condominio[j].in_out==1)
           cout << condominio[j].nome;
    }
}

void exclusao(void)
{
    char nom[50];
    cin.ignore();
    cout << "Entre com o nome do morador cujos dados serao excluidos: ";
    cin.getline(nom,50);
    
    for(int i=0;i<nmc;i++)
    {
        salto = sizeof(carros)*i+sizeof(c);
        fseek(p,salto,SEEK_SET);
        fread(&condominio,sizeof(condominio),1,p);
        if(strcmp(nom,condominio[i].nome)==0) 
        {
            cin.ignore();
            cout << "Dados do morador " << condominio[i].nome " foram deletados";
            condominio[i].nome = "                                                  ";
            condominio[i].bloco = 0;
            condominio[i].num = 0;
            condominio[i].in_out = 0;
        }
    }
} 

FILE *p;

int main()
{
    int nmc; //numero de moradores do condominio
    the_condom condominio;
    int op,salto = 0;
    char marca[15];
    
    p = fopen("carros.txt","rb+");
    if(p==NULL)
    {
        p = fopen("carros.txt","wb+");
        if(p==NULL)
            exit(0);
    }
    
    do{
        system("cls");
        cout << "1 - Cadastrar\n";
        cout << "2 - Editar\n";
        cout << "3 - Excluir\n";
        cout << "4 - Pesquisar\n";
        cout << "5 - Listar\n";
        cout << "6 - Sair\n";
        cin >> op;
        
        switch(op)
        {
            case 1: inclusao();                        
                    break;            
            
            case 2: edicao();
                    break;
            
            case 3: exclusao();
                    break;
                 
            case 4: pesquisa();
                    break;
                 
            case 5: listagem();
                    break;
                                  
            case 6: system("exit");
                    break;
        }
        cin.ignore();
        cin.get();
    }while(op!=6);
    fclose(p);
}
