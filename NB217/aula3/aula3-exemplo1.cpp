#include<iostream>
using namespace std;

int main ()
(
    char nome [20];
    float nota1, nota2, nota3, media;
        
    cout << "Entre com as notas: \n";
    cin >> nota1 >> nota2 >> nota3;
    cout << "Entre com o seu nome: \n";
    cin.getline(nome,20);
    
    media = (nota1 + nota2 + nota3)/3;
    
    if (media>= 70)
       cout << "Nome: \n" << nome << "Media: \n" << media << "APROVADO!";
              
    else
        cout << "Nome: \n" << nome << "Media: \n" << media << "REPROVADO!";
                    
        cin.ignore();
        cin.get();
}
