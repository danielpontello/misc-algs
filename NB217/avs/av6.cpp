#include<iostream>
using namespace std;

int main()
{
    int mat[12][2];
    int c;
    float total=0;
    int slap=0;
    int sdesk=0;
    int maior;
    
    for(int lap=0;lap<12;lap++)
        for(int desk=0;desk<2;desk++)
        {
           cout << "Entre, para cada mes, com o numero de laptop's vendidos, em seguida o de desktop's: ";
           cin >> mat[lap][desk];
           
           total = total + desk;
           
           if (desk>300)
              {
                 c++;
              }
              
           if (lap>desk){
                  slap = slap + lap;
              }else{
                  sdesk = sdesk + desk;
                   }
                  
                  if (slap>sdesk){
                     maior = 0;
                     }else{
                         maior = 1;
                     }
             
        }
        
    cout << "O numero de meses que se vendeu mais de 300 laptop's eh: " << c << endl;
    cout << "A media de desktop's vendidos eh: " << total/12.0 << endl;
    cout << "O modelo que obteve a maior quantidade vendida em um mes esta na coluna: " << maior << endl;      
         
    cin.ignore();
    cin.get();
}
