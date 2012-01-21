#include<iostream>
using namespace std;

int main ()
{
    char nome[10],resp;
    int idade,i=0;
    
    do
    {
        cin.ignore();
        cout << "Entre com o nome: ";
        cin.getline(nome,10);
        do
        {
           cout << "Entre com a idade: ";
           cin >> idade;
        }while(idade<0 || idade>100);
        
        cout << "Deseja continuar? (s=sim/n=nao)\n";
        cin >> resp;
        i++;
    }while(resp=='s' || resp=='S');
    
    cout << "Total de dados entrados eh: " << i;
    
    cin.get();
    cin.ignore();
}
