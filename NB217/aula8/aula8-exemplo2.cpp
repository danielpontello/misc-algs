#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;

float media(float n1,float n2, float n3)
{
      float media;
      media = (n1+n2+n3)/3.0;
      return media;
}

int main ()
{
    float n1,n2,n3;
     
    cout << "Entre com as tres notas ";
    cin >> n1 >> n2 >> n3;
    
    cout << "A media eh: " << media(n1,n2,n3);


    cin.get();
    cin.ignore();
    
}
