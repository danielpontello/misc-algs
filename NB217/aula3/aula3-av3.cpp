#include<iostream>
using namespace std;

int main ()
(
    char pessoa1[20], pessoa2[20];
    int idade1, idade2;
    
    cin.ignore();
    cout << "Entre com o nome da primeira pessoa: ";
    cin.getline(pessoa1,20);
    cout << "Entre com a idade da primeira pessoa: ";
    cin >> idade1;
    cout << "Entre com o nome segunda pessoa: ";
    cin.getline(pessoa2,20);
    cout << "Entre com a idade da segunda pessoa: ";
    cin >> idade2;
    
    if ((2011-idade1>=1980)&& (2011-idade1<=2011))
       cout << "Nome: \n" << pessoa1;
        
    if ((2011-idade2>=1980)&& (2011-idade2<=2011))
       cout << "Nome: \n" << pessoa2;
        
    if (idade1>idade2)
    {
        cout << "Nome: \n" << pessoa1 << "Nasc: " << 2011-idade1;
        cout << "Nome: \n" << pessoa2 << "Nasc: " << 2011-idade2;               
    }                  
    
    else
    {
        cout << "Nome: \n" << pessoa2 << "Nasc: " << 2011-idade2;
        cout << "Nome: \n" << pessoa1 << "Nasc: " << 2011-idade1;
    }
    
        cin.ignore();
        cin.get();
}
