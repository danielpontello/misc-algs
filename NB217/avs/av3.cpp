#include<iostream>
using namespace std;

int main()
{
    int x,y,z,resultado,op;
    
    cout << "Entre com um valor pra x: ";
    cin >> x;
    cout << "Entre com um valor pra y: ";
    cin >> y;
    cout << "Entre com um valor pra z: ";
    cin >> z;
    
    cout << "Menu: \n";
    cout << "1 -- Verificar existencia de multiplos de 5\n";
    cout << "2 -- Exibir numeros pares\n";
    cout << "Entre com sua opcao: ";
    cin >> op;
    
    switch(op)
    {
         case 1: 
         {
             if ((x%5==0)||(y%5==0)||(z%5==0))
             cout << "Ha pelo menos um multiplo de 5 entre os valores dados";
             break;        
         }    
             
         case 2: 
         {
              if(x%2==0)
              {
                   cout << x;
              }
              if(y%2==0)
              {
                   cout << y;
              }
              if(z%2==0)
              {
                   cout << z;
              }
              break;
         }   
    }

    cin.ignore();
    cin.get();
}
