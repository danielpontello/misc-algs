#include<iostream>
using namespace std;

int t1, t2, t3;
char nome1[20], nome2[20], nome3[20];

int main ()
{
    cin.ignore();
    cout << "Entre com o primeiro nome: ";
    cin.getline(nome1,20);
    cout << "Entre com o primeiro tempo de servico: ";
    cin >> t1;
    
    cin.ignore();
    cout << "Entre com o segundo nome: ";
    cin.getline(nome2,20);
    cout << "Entre com o segundo tempo de servico: ";
    cin >> t2;
    
    cin.ignore();
    cout << "Entre com o terceiro nome: ";
    cin.getline(nome3,20);
    cout << "Entre com o terceiro tempo de servico: ";
    cin >> t3;
    
    if (((t1<=16)&&(t1>=4))||((t2<=16)&&(t2>=4))||((t3<=16)&&(t3>=4)))
    {
       cout<<"Um dos funcionarios foi admitido entre 1995 e 2007\n\n";
    }else
    {
         cout<<"Nenhum dos funcionarios foi admitido entre 1995 e 2007\n\n";
    }
    if((t1<t2)&&(t1<t3))
    {
                        cout<<nome1<<" tempo: "<<t1<<endl;
                        if(t2<t3)
                        {
                                 cout<<nome2<<" tempo: "<<t2<<endl;
                                 cout<<nome3<<" tempo: "<<t3<<endl;
                        }else
                        {
                             cout<<nome3<<" tempo: "<<t3<<endl;
                             cout<<nome2<<" tempo: "<<t2<<endl;
                        }
    }
    if((t2<t1)&&(t2<t3))
    {
                        cout<<nome2<<" tempo: "<<t2<<endl;
                        if(t1<t3)
                        {
                                 cout<<nome1<<" tempo: "<<t1<<endl;
                                 cout<<nome3<<" tempo: "<<t3<<endl;
                        }else
                        {
                             cout<<nome3<<" tempo: "<<t3<<endl;
                             cout<<nome1<<" tempo: "<<t1<<endl;
                        }
    }
    if((t3<t1)&&(t3<t1))
    {
                        cout<<nome3<<" tempo: "<<t3<<endl;
                        if(t1<t2)
                        {
                                 cout<<nome1<<" tempo: "<<t1<<endl;
                                 cout<<nome2<<" tempo: "<<t2<<endl;
                        }else
                        {
                             cout<<nome2<<" tempo: "<<t2<<endl;
                             cout<<nome1<<" tempo: "<<t1<<endl;
                        }
    }
    cin.ignore();
    cin.get();
    return (0);
}