#include<iostream>
using namespace std;

int main()
{
    int mat[4][4];
    
    for(int i=0;i<=3;i++)
       for(int k=0;k<=3;k++)
       {
            cout << "Entre com o termo [" << i << "][" << k << "] : ";
            cin >> mat[i][k];
       }     
       for(int i=0;i<=3;i++)
          for(int k=0;k<=3;k++)
              cout << "O termo [" << i << "][" << k << "] eh: " << mat[i][k] << endl;
                   
    cin.ignore();
    cin.get();
}
