#include<iostream>
using namespace std;

int main ()
{
    int n,i;
    
    cout << "Entre com o valor final da contagem: ";
    cin >> n;
    
    for(i=0;i<=n;i++)
        cout << " " <<i;    
    
    cin.get();
    cin.ignore();
}
