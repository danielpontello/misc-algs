#include<iostream>
using namespace std;

int main ()
{
    char login[10], senha[20];
    
    do
    {
         cin.ignore();
         cout << "Entre com o login: \n";
         cin.getline(login,10);
         cout << "Entre com a senha: \n";
         cin.getline(senha,20);
    
         
         if(strcmp(login,"aluno")!=0 || strcmp(senha,"alunoinatel")!=0)
         {
            cout << "Senha incorreta";
         }
         
    }while(strcmp(login,"aluno")!=0 || strcmp(senha,"alunoinatel")!=0);
    
    cout << "Senha correta: " << senha;
         
    cin.get();
    cin.ignore();
}
