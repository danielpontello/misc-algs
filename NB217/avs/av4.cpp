#include<iostream>
using namespace std;

int main()

{    
     char nome[20];
     int TC, CC, P, MP=0, M, n=0, TP=0, CCM=0, TCM=0, QC=0, QT=0, Perc;
     /*tempo de jogo, código do competidor, pontuação, maior número de pontos, média, número de jogadores com menos de 4 minutos,
     total de pontos, codigo do competidor com maior numero de pontos, tempo do competidor com maior numero de pontos,*/
     
     cin.ignore();
     cout << "Digite o nome do competidor: \n";
     cin.getline(nome,20);
     cout << "Digite o tempo de jogo do competidor (no intervalo de 0 a 10 minutos): \n";
     cin >> TC;
     cout << "Digite o codigo do competidor: \n";
     cin >> CC;
     cout << "Digite a pontuacao do competidor: \n";
     cin >> P;
     
     while (TC!=0)
     {
      
           if (TC<4)
           {
              TP = TP + P;
              n++;
              M = TP/n;
           }
     
           if (P>MP)
           {
              MP = P;
              CCM = CC;
              TCM = TC;
           }
           
           if (P>225)
           {
              QC++; 
              Perc = (QC*100)/QT;          
           }
                
     cin.ignore();
     cout << "Digite o nome do competidor: \n";
     cin.getline(nome,20);
     cout << "Digite o tempo de jogo do competidor: \n";
     cin >> TC;
     cout << "Digite o codigo do competidor: \n";
     cin >> CC;
     cout << "Digite a pontuacao do competidor: \n";
     cin >> P; 
     
     }     
     cout << "Candidato vencedor: \n";
     cout << "Codigo: \n" << CCM;
     cout << "Tempo de jogo: \n" << TCM;
     cout << "Pontos: \n" << MP;
     cout << "Percentual de jogadores que fizeram mais que 225 pontos: \n" << Perc;      
      
     cin.ignore();
     cin.get();
}
