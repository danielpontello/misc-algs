#include<iostream>
using namespace std;

struct carro
{
       char marca[15];
       int ano;
       char cor[10];
       float preco;
};

int main()
{
    carro carros[5];
    int op;
    char marca[15];
    
    
    do{ 
    system("cls");   
    cout<<"1- Cadastrar" << endl;
    cout<<"2- Pesquisar" << endl;
    cout<<"3- Listar" << endl;
    cout<<"4- sair" << endl;
    cout<<"\n Selecione uma opcao: ";
    cin>> op;
    
    switch(op)
    {
              case 1: for(int i=0;i<5;i++)
                      {
                         cin.ignore();
                         cout<<"Entre com a marca: ";
                         cin.getline(carros[i].marca,15);
                         cout<< "Entre com o ano: ";
                         cin>> carros[i].ano;
                         cin.ignore();
                         cout<< "Entre com a cor: ";
                         cin.getline(carros[i].cor,10);
                         cout<< "Entre com o preco: ";
                         cin>> carros[i].preco;
                         cout<<endl;
                         }
                         break;
                         
              case 2: cin.ignore();
                      cout<< "Entre com uma marca: ";
                      cin.getline(marca,15);
                      for(int i=0;i<5;i++)
                      {
                              if(strcmp(marca,carros[i].marca)==0)
                              {
                                 cout<<"Marca: "<< carros[i].marca;
                                 cout<<"Ano: "<< carros[i].ano;
                                 cout<<"Cor: "<< carros[i].cor;
                                 cout<<"Preco: "<< carros[i].preco;
                                 break;
                              }
                              break;
                              }      
    }
    }while(op!=4);
    cin.ignore();
    cin.get();
}
    
