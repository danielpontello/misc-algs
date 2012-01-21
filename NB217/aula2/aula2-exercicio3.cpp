#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    float m1, m2, d, F;
        
    cout << "Entre com o valor da massa m1:\n";
    cin >> m1;
    cout << "Entre com o valor da massa m2:\n";
    cin >> m2;
    cout << "Entre com o valor da distancia:\n";
    cin >> d;   
    
    F = (6.673e8*m1*m2)/pow(d,2);
    
    cout << "O valor da forca eh:" << F;
    
    cin.ignore();
    cin.get();    
}
