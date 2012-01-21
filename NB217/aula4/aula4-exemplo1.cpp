#include<iostream>
using namespace std;

int main()
{
    float x,y,resultado;
    int op;
    
    cout << "Entre com os 2 valores: ";
    cin >> x >> y;
    
    cout << "Calculadora\n";
    cout << "1 -- Soma\n";
    cout << "2 -- Subtracao\n\n";
    
    cout << "Entre com sua opcao: ";
    cin >> op;
    
    switch(op)
    {
         case 1: cout << "O resultado da soma eh: " << x+y;
         break;
         case 2: cout << "O resultado da subtracao eh: " <<x-y;
         break;
    }
    
    cin.ignore();
    cin.get();
}
