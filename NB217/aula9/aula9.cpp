#include<iostream>
using namespace std;

int main()
{
    int ano[12][4];
    float total=0;
    int menor = 100000;

    for(int mes=0;mes<12;mes++)
        for(int semana=0;semana<4;semana++)
        {
            cout << "Entre com a produ��o semanal: ";
            cin >> ano[mes][semana];
            total += ano[mes][semana];
            if(ano[mes][semana]<menor)
                menor = ano[mes][semana];
        }
    
    cout << "O total produzido: " << total << endl;
    cout << "A media mensal de produ��o: " << total/12.0 << endl;
    cout << "Valor da semana de menor produ��o: " << menor << endl;
                 
    cin.ignore();
    cin.get();
}
    
    
