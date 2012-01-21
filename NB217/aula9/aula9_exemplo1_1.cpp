#include<iostream>
using namespace std;

int main()
{
    int vet[4];
    
    for(int i=0;i<4;i++)
    {
        cout << "Entre com um valor inteiro: ";
        cin >> vet[i];
    }
    
    cout << endl << endl;
    for(int i=0;i<4;i++)
        cout << "O valor da posicao " << i << " eh: " << vet[i] << endl;
        
    cin.ignore();
    cin.get();
    
}
