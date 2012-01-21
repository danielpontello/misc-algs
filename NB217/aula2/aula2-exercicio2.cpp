#include<iostream>
using namespace std;

int main()
{
    float real, dolar;
    
    cout << "Entre com o valor em reais:\n";
    cin >> real;
    
    dolar = real/1.57;
        
    cout << "O valor em dolares eh =" << dolar;

    cin.ignore();
    cin.get();    
}
