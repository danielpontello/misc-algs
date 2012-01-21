#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;

struct the_cond
{
     char nome[50];
     int bloco;
     int num;
     bool in_out;
     //int nmc;
};

int s, salto;
the_cond cond[15];        
int nmc; //numero de moradores do condominio 
        
FILE *p;

  void inclusao(void)
{  
      int t=0,c=0; //critica de dados
      char nom[50];
      
      cout<<"CADASTRO DE MORADORES\n\n"; 
      do
      { 
        
            p=fopen("cond.txt","rb+");
            fseek(p,0,SEEK_SET);
            fread(&s,sizeof(s),1,p);
        for(int k=0;k<s;k++)
        {
            salto=sizeof(cond)*k+sizeof(s);
            fseek(p,salto,SEEK_SET);
            fread(&cond,sizeof(cond),1,p);        
           // cout<<" "<<cond;
        } 
          cin.ignore();
          cout<<"NOME do morador(a): ";
          cin.getline(cond[nmc].nome,50);
          strcpy(nom,cond[nmc].nome); //copia para nom o nome digitado para depois comparar e
                                        //ver se esse nome já havia sido cadastrado
            for(int i=0;i<nmc;i++)
              if (strcmp(nom,cond[i].nome)==0) 
                 c++; //indicador de que o nome digitado ja esta cadastrado
             if(c==0) //verifica se nome já está cadastrado. Se não, inicia cadastro
             {                                   
                 cout<<"BLOCO do apartamento do morador(a): ";
                 do{                
                        cin>> cond[nmc].bloco;
                   }while(cond[nmc].bloco<=0);//critica de dados: bloco é um numero natural diferente de 0
                   
                 cout<<"NUMERO apartamento: ";
                 do{
                        cin>> cond[nmc].num;
                   }while(cond[nmc].num<=0);//critica de dados: bloco é um numero natural diferente de 0
                   
                 cond[nmc].in_out = true;
                 nmc++; //incrementa numero de moradores do condominio
                        //usado para depois indicar proxima posição a ser preenchida no "condom[50]"
                 cout<<"\nDESEJA CADASTRAR MAIS ALGUM MORADOR(A)?\n"<<"[0]NAO / [1]SIM: ";
                 cin>>t;
             }
             else
             {
                 cout<<"MORADOR(A) JA CADASTRADO!\n";
                 t==1;
                 c=0;
             }
             cout<<".............................................................\n";
         fseek(p,0,SEEK_SET);
         fread(&s,sizeof(s),1,p);
         salto=sizeof(cond)*s+sizeof(s);
         fseek(p,salto,SEEK_SET);
         fwrite(&cond,sizeof(cond),1,p);
         fseek(p,0,SEEK_SET);
         s++;
         fwrite(&s,sizeof(s),1,p);     
      }while(t==1); //enquanto t nao for igual a zero (nao quer mais cadastrar), nao sai   
         cout<<"\nCADASTRO FINALIZADO COM SUCESSO!";
         cout<<"\n(APERTE ENTER PARA VOLTAR AO MENU)";
}; 
        
void edicao(void)
{
    char nom[50];
    int c=0, t=1; //critica de dados
    cout << "EDICAO DE DADOS";
    do{
        cin.ignore();
        cout << "\nEntre com o nome do morador(a) cujos dados serao EDITADOS: ";
        cin.getline(nom,50);
    
        for(int i=0;i<nmc;i++)
        {
            salto = sizeof(cond[i])*i+sizeof(s);
            fseek(p,salto,SEEK_SET);
            fread(&cond,sizeof(cond),1,p);
            
            
            if(strcmp(nom,cond[i].nome)==0) 
            {
                //cin.ignore();
                cout << "Entre com novo NOME: ";
                cin.getline(cond[i].nome,50); 
                cout << "Entre com novo BLOCO: ";
                cin >> cond[i].bloco;
                cout << "Entre com novo NUMERO do apartamento: ";
                cin>> cond[i].num;
                c=1;
                cout<<"\nEDICAO REALIZADA COM SUCESSO!\n";
            }
          }
          if(c==0) //verifica se nome digitado consta na base de cadastro
                  cout<<"\nNAO HA NENHUM MORADOR(A) COM O NOME DIGITADO!";
          cout<<"\nDESEJA SAIR DA EDICAO OU TENTAR OUTRO NOME?";
          cout<<"\n[0]SAIR / [1]NOVO NOME: ";
          cin>>t;
        }while(t==1);
        cout << "\n.............................................................\n";
        cout << "\nEDICAO DE DADOS FINALIZADA!";
        cout << "\n(APERTE ENTER PARA VOLTAR AO MENU)";
};
     
void pesquisa(void)
{
    int c=0, t=1;
    char nom[50];
    cout<<"PESQUISA DE DADOS DOS MORADORES DESTE CONDOMINIO";
    do
    {
        p=fopen("cond.txt","rb+");
        fseek(p,0,SEEK_SET);
        fread(&s,sizeof(s),1,p);
        for(int k=0;k<s;k++)
        {
            salto=sizeof(cond)*k+sizeof(s);
            fseek(p,salto,SEEK_SET);
            fread(&cond,sizeof(cond),1,p);
           // cout<<" "<<cond;
        
        } 
        cin.ignore();
        cout<<"\nEntre com o nome do morador cujos dados serao PESQUISADOS: ";
        cin.getline(nom,50);
        
        for(int i=0;i<nmc;i++)
        {
            /*salto = sizeof(condom)*i+sizeof(c);
            fseek(p,salto,SEEK_SET);
            fread(&condominio,sizeof(condom),1,p);*/
            if(strcmp(nom,cond[i].nome)==0) 
            {
                cout << "Morador: " << cond[i].nome << endl;
                cout << "Bloco: " << cond[i].bloco << endl;
                cout << "Numero: " << cond[i].num << endl;
                c=1;
            }
        }
        if(c==0) //verifica se nome digitado consta na base de cadastro
                 cout<<"\nNAO HA NENHUM MORADOR(A) COM O NOME DIGITADO!";
                 
        cout<<"\nDESEJA PESQUISAR OUTRO NOME?";
        cout<<"\n[0]NAO / [1]SIM: ";
        cin>>t;
        
    }while(t==1);
        cout << "\n.............................................................\n";
        cout << "\nPESQUISA DE DADOS FINALIZADA!";
        cout << "\n(APERTE ENTER PARA VOLTAR AO MENU)";
};

void listagem(void)
{
    char nom[50];
    int inside,t=0,c;
    do
    {
        cout << "Deseja atualizar se algum morador(a) ENTROU/SAIU do condominio?"<<"\n[0]NAO / [1]SIM: ";
        cin >> inside;
        c=0;
        switch(inside)
        {
            case 0: break; //nao faz nada!            
                 
            case 1:
                 do
                 {
                     cout << "Nome do morador(a) que deseja ATUALIZAR: ";
                     cin >> nom;
                     for(int i=0;i<nmc;i++)
                     {
                        /*salto = sizeof(condom)*i+sizeof(c);
                        fseek(p,salto,SEEK_SET);
                        fread(&condominio,sizeof(condominio),1,p);*/
                        if(strcmp(nom,cond[i].nome)==0) 
                        {
                          if(cond[i].in_out == true)
                          {
                             cond[i].in_out=false;//caso estava IN, atualiza para morador OUT
                             cout<<".............................................................\n";
                             cout<<"\nATUALIZADO! Morador(a) "<<cond[i].nome<<" deixou o THE COND.\n";
                             c=1;
                          }
                          else
                          {   
                             cond[i].in_out=true;//caso estava OUT, atualiza para morador IN
                             cout<<".............................................................\n";                              
                             cout<<"\nATUALIZADO! Morador(a) "<<cond[i].nome<<" entrou no THE COND.\n";
                             c=1;
                          }  
                        }                                 
                     } 
                     if(c==0)//verifica se ha morador com este nome no banco de cadastro
                             cout<<"\nNAO HA NENHUM MORADOR(A) COM ESTE NOME NO CONDOMINIO!\n";
                 }while(c==0);  
                 break;
                 
            default: cout<<"\nESTA NAO E UMA ESCOLHA VALIDA!\n"; 
                     break; //default: se o usuario digita um numero diferente de 0/1, aparece isso!
        }
    }while(inside!=1 && inside!=0);//caso o usuario digite um numero errado, volta e pergunta de novo
        
    cout << "\nMORADORES QUE ESTAO NO CONDOMINIO: ";
    for(int j=0;j<nmc;j++)
    {
        if(cond[j].in_out==true) //mostra TODOS os moradores que ESTAO IN no The_Cond
        {
           cout<<endl; 
           cout << cond[j].nome;
           t=1;//indicador de que há, pelo menos, um morador no condominio
        }
    }

    
    if(t==0)//caso nao haja NENHUM morador IN
        cout<<"Nao ha nenhum morador(a) no THE COND..\n";
 /*   else
      {
        cout<<"\n\nMORADORES QUE ESTAO FORA DO CONDOMINIO: ";
        for(int j=0;j<nmc;j++)
            if(cond[j].in_out==false)
            {
               cout<<endl;
               cout<<cond[j].nome;
            }*/
    cout << "\n.............................................................\n";
    cout << "\n(APERTE ENTER PARA RETORNAR AO MENU)";
};

void exclusao(void)
{
    int c=0,t,p=1; //confirmação de que deseja deletar dados do morador e critica de dados
    char nom[50];
    cout<<"EXCLUSAO DE DADOS\n";
    do
    {  
        cin.ignore();             
        cout << "Entre com o nome do morador(a) cujos dados serao EXCLUIDOS: ";
        cin.getline(nom,50);
        t=0;         
        for(int i=0;i<nmc;i++)
        {
          //  salto = sizeof(cond)*i+sizeof(s);
          //  fseek(p,salto,SEEK_SET);
           // fread(&cond,sizeof(cond),1,p);
            
            if(strcmp(nom,cond[i].nome)==0) 
            {
                cout<<"\nTEM CERTEZA DE QUE DESEJA DELETAR OS DADOS DO MORADOR(A) "<<cond[i].nome<<"?";
                cout<<"\n[0]NAO / [1]SIM: ";
                cin>>c;
                if(c==1)
                {
                    cin.ignore();
                    cout << "Dados do morador(a) " << cond[i].nome << " foram deletados\n";
                    strcpy(cond[i].nome,"                                                 ");
                    cond[i].bloco = 0;
                    cond[i].num = 0;
                    cond[i].in_out = false;
                   //apaga todos os dados do morador!
                }
                t=1;            
            }
        }
        if(t==0)
            cout<<"\nNAO HA NENHUM MORADOR(A) NO CONDOMINIO COM ESTE NOME!";
        cout<<"\nDESEJA ENTRAR COM OUTRO NOME? [0]NAO / [1]SIM: ";
        cin>>p;
        cout<<endl;
    }while(p==1);
    cout << ".............................................................\n";
    cout << "\nEXCLUSAO FINALIZADA!";
    cout << "\n(APERTE ENTER PARA VOLTAR AO MENU PRINCIPAL";

}; 



int main()
{
    //int nmc; //numero de moradores do condominio

    int op;//,salto = 0;
        
    p = fopen("cond.txt","rb+");
    if(p==NULL)
    {
        p = fopen("cond.txt","wb+");
        if(p==NULL)
            exit(0);
    }
    
    do{
        system("cls");
        cout << "CONDOMINIO THE COND"<<endl<<"REGISTRO DE MORADORES" << endl;
        cout << "1 - Cadastrar\n";
        cout << "2 - Editar\n";
        cout << "3 - Excluir\n";
        cout << "4 - Pesquisar\n";
        cout << "5 - Listar\n";
        cout << "6 - Sair\n";
        cout << "\n O QUE VOCE DESEJA? (ESCOLHA UMA DAS SEIS OPCOES): ";
        cin >> op;       
        cout << ".............................................................\n";
        
        switch(op)
        {
            case 1: inclusao();                        
                    break;            
            
            case 2: edicao();
                    break;
            
            case 3: exclusao();
                    break;
                 
            case 4: pesquisa();
                    break;
                 
            case 5: listagem();
                    break;
                                  
            case 6: cout<<"\n       REGISTRO DE MORADORES ENCERRADO!";
                    cout<<"\n       OBRIGADO . CONDOMINIO THE COND";
                    system("exit");
                    break;
            
            default: cout<<"OPCAO MARCADA NAO CONSTA NO MENU!";
                     cout<<"\nPOR FAVOR, TENTE NOVAMENTE..";
                     cout<<"\n.............................................................\n";
                     break;//caso tenha digitado um numero diferente de 1/2/3/4/5/6
        }
        cin.ignore();
        cin.get();
    }while(op!=6);
    fclose(p); //encerra aplicativo
}
