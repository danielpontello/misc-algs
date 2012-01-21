#include<iostream>
using namespace std;

int main()
{
    float a,b,c,d,e,f,x,y;
    
    cout << "Entre com o valor das constantes:\n";
    cin >> a >> b >> c >> d >> e >> f;
    
    x = (c*e - b*f) / (a*e - b*d);
    y = (a*f - c*b) / (a*e - b*d);
    
    cout << "X =" << x << " e Y =" << y;

    cin.ignore();
    cin.get();    
}