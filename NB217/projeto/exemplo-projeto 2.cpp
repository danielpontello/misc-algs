#include<iostream>
#include<cstring>
using namespace std;

struct carro
{
    char marca[15];
    int ano;
    char cor[10];
    float preco;
};

FILE *p;

int main()
{
    carro carros;
    int op,c = 0,salto = 0;
    char marca[15];
    
    p = fopen("carros.txt","rb+");
    if(p==NULL)
    {
        p = fopen("carros.txt","wb+");
        if(p==NULL)
            exit(0);
    }
    
    do{
        system("cls");
        cout << "1 - Cadastrar\n";
        cout << "2 - Pesquisar\n";
        cout << "3 - Sair\n";
        cout << "Selecione uma opcao:";
        cin >> op;
        
        switch(op)
        {
            case 1: fseek(p,0,SEEK_SET);
                    fread(&c,sizeof(c),1,p);
                    
                    cin.ignore();
                    cout << "Entre com o marca:";
                    cin.getline(carros.marca,15);
                    cout << "Entre com o ano:";
                    cin >> carros.ano;
                    cin.ignore();
                    cout << "Entre com a cor:";
                    cin.getline(carros.cor,10);
                    cout << "Entre com o preco:";
                    cin >> carros.preco;
                    
                    salto = sizeof(carros)*c + sizeof(c);
                    fseek(p,salto,SEEK_SET);
                    fwrite(&carros,sizeof(carros),1,p);
                    c++;
                    fseek(p,0,SEEK_SET);
                    fwrite(&c,sizeof(c),1,p);
                    break;
                        
            
            case 2: fseek(p,0,SEEK_SET);
                    fread(&c,sizeof(c),1,p);
                    
                    cin.ignore();
                    cout << "Entre com a marca a ser pesquisada:";
                    cin.getline(marca,15);
                    for(int i=0;i<c;i++)
                    {
                        salto = sizeof(carros)*i+sizeof(c);
                        fseek(p,salto,SEEK_SET);
                        fread(&carros,sizeof(carros),1,p);
                        if(strcmp(marca,carros.marca)==0) {
                            cout << "Marca: " << carros.marca << endl;
                            cout << "Ano: " << carros.ano << endl;
                            cout << "Cor: " << carros.cor << endl;
                            cout << "Preco: " << carros.preco << endl;
                        }
                    }
                    break;
                 
            case 3: system("exit");
                    break;
        }
        cin.ignore();
        cin.get();
    }while(op!=3);
    fclose(p);
}
