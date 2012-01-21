#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;

void altera (int &x);

int main ()
{
    int x;
     
          cout << "Entre com um valor inteiro: ";
          cin >> x;
    
    altera(x);
    
    cout << "O valor de x eh = " << x;
    
    cin.get();
    cin.ignore();
}

void altera(int &x)
{
     if(x<0)
            x = x*(-1);
