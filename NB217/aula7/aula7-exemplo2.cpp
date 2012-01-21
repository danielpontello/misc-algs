#include<iostream>
#include<cmath>
using namespace std;

int main ()
{
    int n,i,d=1;
    float s=0,pi;
    
    cout << "Entre com o numero de termos: ";
    cin >> n;
    
    for(i=1;i<=n;i++)
    {
       if(i%2!=0)
           s = s + 1.0/pow(d,3.0);
       else
           s = s - 1.0/pow(d,3.0);
       d += 2;
       pi = pow((s*32.0),(1.0/3.0));
    }
    cout << "O valor de PI = " << pi;
    
    cin.get();
    cin.ignore();
}
