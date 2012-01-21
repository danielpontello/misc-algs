#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;

int main ()
{
    int c,a=2,b=1;
    float x,s=1; //como 1/2 + 1/2 é = 1, os dois primeiros termos não fazem parte da logica    
    
    do
    {
         cout << "Entre com o valor de x: ";
         cin >> x;
    }while(x<0||x>10);
    
    for(c=7;c>=1;c--) //como 1/2 + 1/2 é = 1, os dois primeiros termos não fazem parte da logica
    {
    s = s + ((a*pow(x,c))/2);
    
    a = a + b;
    b = a - b;  
    }
    
    cout << "O valor da soma eh = " << s;
    
    cin.get();
    cin.ignore();
}

