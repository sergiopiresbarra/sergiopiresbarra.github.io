#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

struct domino
{
    int x;
    int y;
    bool estilo;
    int orientacao;
};

struct ConjuntodePecas
{
    domino vd[28] ;
    int n;
};

struct jogo
{
    ConjuntodePecas j1;
    ConjuntodePecas j2;
    ConjuntodePecas cp;
    ConjuntodePecas mesa;
};

ConjuntodePecas nova ( )
{
    ConjuntodePecas conj ;
    conj.n=0;
    return conj;
}

//tamanho do conjunto
int tamanho (ConjuntodePecas conj)
{
    return conj.n;
}

domino elemento(ConjuntodePecas v,int x)
{
    return v.vd[x];
}

//adicionar peças
void inserir(domino d, ConjuntodePecas &c)
{
    c.vd[c.n]=d;
    c.n++;
}

void remover(int pos, ConjuntodePecas &c)
{
    for(int i=pos; i<c.n-1 ; i++)
    {

        c.vd[i]=c.vd[i+1];
    }
    c.n--;
}

bool Terminou(jogo j)
{
    if (tamanho(j.j1)==0)
    {
        return true;
    }
    else
    {
        if (tamanho(j.j2)==0)
        {
            return true;
        }
        else
        {
            if (tamanho(j.cp)==0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}

int Ganhou (jogo j)
{
    if (tamanho(j.j1)==0)
    {
        return 1;
    }
    else
    {
        if (tamanho(j.j2)==0)
        {
            return 2;
        }
        else
        {
            if (tamanho(j.cp)==0)
            {
                if (tamanho(j.j1)<tamanho(j.j2))
                {
                    return 1;
                }
                else
                {
                    if (tamanho(j.j1)>tamanho(j.j2))
                    {
                        return 2;
                    }
                    else
                    {
                        return 3;
                    }
                }
            }
        }
    }
}

int pedraDomino (int M[3][3], int p)
{
    if (p==1 || p==3 || p==5)
    {
        M[1][1]=1;
    }
    if (p>1)
    {
        M[0][0]=1;
        M[2][2]=1;
    }
    if (p>3)
    {
        M[0][2]=1;
        M[2][0]=1;
    }
    if (p==6)
    {
        M[1][0]=1;
        M[1][2]=1;
    }
}

bool estilo (int x)
{
    if (x==1)
    {
        return true;
    }
    if (x==0)
    {
        return false;
    }
}

void desenharleds (int M[3][3], int i)
{
    for (int k=0; k<3; k++)
    {
        if (M[i][k]==1)
        {
            cout << "*";
        }
        else
        {
            cout << " ";
        }
    }
}

void estilodeleds (int M1[3][3], int M2[3][3], int o, int x, int y)
{
    if (o==1)
    {
        pedraDomino(M1,x);
        for (int i=0; i<3; i++)
        {
            for (int j=0; j<3; j++)
            {
                if (M1[i][j]==1)
                {
                    cout << "*" << " ";
                }
                else
                {
                    cout << " ";
                }
            }
            cout << endl;
        }
        for(int i=0; i<=3 ; i++)
        {
            cout<<"-";
        }
        cout << endl;
        pedraDomino(M2,y);
        for (int i=0; i<3; i++)
        {
            for (int j=0; j<3; j++)
            {
                if (M2[i][j]==1)
                {
                    cout << "*" << " ";
                }
                else
                {
                    cout << " ";
                }
            }
            cout << endl;
        }
    }
    if (o==2)
    {
        pedraDomino(M2,y);
        for (int i=0; i<3; i++)
        {
            for (int j=0; j<3; j++)
            {
                if (M2[i][j]==1)
                {
                    cout << "*" << " ";
                }
                else
                {
                    cout << " ";
                }
            }
            cout << endl;
        }
        for(int i=0; i<=3 ; i++)
        {
            cout<<"-";
        }
        cout << endl;
        pedraDomino(M1,x);
        for (int i=0; i<3; i++)
        {
            for (int j=0; j<3; j++)
            {
                if (M1[i][j]==1)
                {
                    cout << "*" << " ";
                }
                else
                {
                    cout << " ";
                }
            }
            cout << endl;
        }
    }
    if (o==3)
    {
        pedraDomino(M1,x);
        pedraDomino (M2,y);
        for (int j=0; j<3; j++)
        {
            desenharleds(M1,j);
            cout<<"|";
            desenharleds(M2,j);
            cout << endl;
        }
    }
    if (o==4)
    {
        pedraDomino(M1,x);
        pedraDomino (M2,y);
        for (int j=0; j<3; j++)
        {
            desenharleds(M2,j);
            cout<<"|";
            desenharleds(M1,j);
            cout << endl;
        }
    }
}

void estilonumeros (int o, int x, int y)
{
    if (o==1)
    {
        cout <<" "<<x<<endl;
        cout <<"---"<<endl;
        cout <<" "<<y<<endl;
    }
    if (o==2)
    {
        cout <<" "<<y<<endl;
        cout <<"---"<<endl;
        cout <<" "<<x<<endl;
    }
    if (o==3)
    {
        cout << x << " | " << y << endl;
    }
    if (o==4)
    {
        cout << y << " | " << x << endl;
    }
}

void pedrasDomino (int x, int y, int e, int o)
{
    int M1[3][3],M2[3][3];
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            M1[i][j]=0;
        }
    }
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            M2[i][j]=0;
        }
    }
    if (estilo(e)==true)
    {
        estilodeleds(M1,M2,o,x,y);
    }
    else
    {
        estilonumeros(o,x,y);
    }
}

ConjuntodePecas novoConjunto()
{
    ConjuntodePecas v;
    v.n=0;
    return v;
}

jogo jogo_inic()
{
    jogo novo;
    novo.cp=novoConjunto();
    novo.j1=novoConjunto();
    novo.j2=novoConjunto();
    novo.mesa=novoConjunto();
    srand ( time ( NULL ));

    for(int i=0; i<=6; i++)
    {
        for(int j=i ; j<=6 ; j++)
        {
            domino d;
            d.x=i;
            d.y=j;
            inserir(d,novo.cp);
        }
    }
    //EMBARALHAR CP;

    for(int i=0; i<=novo.cp.n; i++)
    {
        int x=rand()%tamanho(novo.cp);
        domino d= elemento(novo.cp,x);
        remover(x,novo.cp);
        inserir(d,novo.cp);
    }

    for(int i=1; i<=7; i++)
    {
        int x=rand()%tamanho(novo.cp);
        domino d= elemento(novo.cp,x);
        remover(x,novo.cp);
        inserir(d,novo.j1);
    }
    for(int i=1; i<=7; i++)
    {
        int y=rand()%tamanho(novo.cp);
        domino d= elemento(novo.cp,y);
        remover(y,novo.cp);
        inserir(d,novo.j2);
    }
    return novo;
}


bool maiorpecaJ1(jogo c)
{
    int maiorJ1=0;
    int maiorJ2=0;
    for(int i=0; i<c.j1.n; i++)
    {
        if((c.j1.vd[i].x+c.j1.vd[i].y)>=maiorJ1)
            maiorJ1=c.j1.vd[i].x+c.j1.vd[i].y;
    }
    for(int i=0; i<c.j2.n; i++)
    {
        if((c.j2.vd[i].x+c.j2.vd[i].y)>=maiorJ2)
            maiorJ2=c.j2.vd[i].x+c.j2.vd[i].y;
    }

    if(maiorJ1>=maiorJ2)
    {
        return true;
    }
    else
    {
        return false;
    }

}

void pedrasnatela(jogo c)
{
    int e;
    if(c.mesa.n<=4)
    {
        for(int i=0; i<c.mesa.n; i++)
        {
            if(c.mesa.vd[i].estilo)
            {
                e=1;
            }
            else
            {
                e=0;
            }
            pedrasDomino(c.mesa.vd[i].x,c.mesa.vd[i].y,e,c.mesa.vd[i].orientacao);
        }
    }
    else
    {
        for(int i=0; i<2; i++)
        {
            if(c.mesa.vd[i].estilo)
            {
                e=1;
            }
            else
            {
                e=0;
            }

            pedrasDomino(c.mesa.vd[i].x,c.mesa.vd[i].y,e,c.mesa.vd[i].orientacao);
        }
        for(int i=c.mesa.n-1; i<=c.mesa.n; i++)
        {
            if(c.mesa.vd[i].estilo)
            {
                e=1;
            }
            else
            {
                e=0;
            }

            pedrasDomino(c.mesa.vd[i].x,c.mesa.vd[i].y,e,c.mesa.vd[i].orientacao);
        }


    }


}

void status(jogo c)
{

    cout<<"STATUS: "<<endl;

    cout<<"pecas pra comprar: "<<"Ha "<<c.cp.n<<" pedras pra comprar!";
    //AQUI MOSTRA AS PEDRAS DISPONIVEIS PRA COMPRAR - opcao desativada;
    /*for(int j=0; j<c.cp.n; j++)
    {
        cout<<c.cp.vd[j].x<<"/"<<c.cp.vd[j].y;
        cout<<" , ";
    }
    */
    cout<<endl<<"pecas da mesa: ";

    for(int j=0; j<c.mesa.n; j++)
    {
        cout<<c.mesa.vd[j].x<<"/"<<c.mesa.vd[j].y;
        cout<<" , ";
    }
    cout<<endl<<"jogador 1: ";

    for(int j=0; j<c.j1.n; j++)
    {
        cout<<c.j1.vd[j].x<<"/"<<c.j1.vd[j].y;
        cout<<" , ";
    }
    cout<<endl<<"jogador 2: ";

    for(int j=0; j<c.j2.n; j++)
    {
        cout<<c.j2.vd[j].x<<"/"<<c.j2.vd[j].y;
        cout<<" , ";
    }
    cout<<endl;

    pedrasnatela(c);
}

jogo opcoesdojogador(jogo c, domino d, int u)
{
    int h,e,o;
    if(u==1)
    {
        if(c.j1.n>0)
        {
            cout<<endl<<"1 - para jogar uma peca. "<<"2 - para comprar uma peca: ";
            cin>>h;
            if(h==1)
            {

                cout<<endl<<"escolha uma peca de 1 a "<<c.j1.n<<": ";
                for(int j=0; j<c.j1.n; j++)
                {
                    cout<<c.j1.vd[j].x<<"/"<<c.j1.vd[j].y;
                    cout<<" , ";
                }
                cin>>h;
                d.x=c.j1.vd[h-1].x;
                d.y=c.j1.vd[h-1].y;
                //verificar se pode jogar a peca na mesa;
                if(c.mesa.n>0)
                {
                    if(d.x==c.mesa.vd[0].x || d.x==c.mesa.vd[c.mesa.n].y || d.y==c.mesa.vd[0].x || d.y==c.mesa.vd[c.mesa.n].y)
                    {
                        remover(h-1,c.j1);
                        inserir(d,c.mesa);
                        cout<<endl;
                        cout << "caso queira com estilo led, digite 1, caso contrario, digite 0"<< endl;
                        cin >> e;
                        c.mesa.vd[c.mesa.n-1].estilo=estilo(e);
                        cout << "escolha a orientacao, sabendo que: 1-vertical; 2-vertical invertido; 3-horizontal; 4-horiontal invertida" << endl;
                        cout<<" "<<endl;
                        cin >> o;
                        c.mesa.vd[c.mesa.n-1].orientacao=o;
                        status(c);
                        return c;

                    }
                    else
                    {
                        cout<<endl<<"Nao pode jogar essa peca. Escolha outra peca: ";
                        status(c);
                        opcoesdojogador(c,d,1);
                    }
                }
                else
                {
                    remover(h-1,c.j1);
                    inserir(d,c.mesa);
                    cout<<endl;
                    cout << "caso queira com estilo led, digite 1, caso contrario, digite 0"<< endl;
                    cin >> e;
                    c.mesa.vd[c.mesa.n-1].estilo=estilo(e);
                    cout << "escolha a orientacao, sabendo que: 1-vertical; 2-vertical invertido; 3-horizontal; 4-horiontal invertida" << endl;
                    cout<<" "<<endl;
                    cin >> o;
                    c.mesa.vd[c.mesa.n-1].orientacao=o;
                    status(c);
                    return c;
                }
            }
            if(h==2)
            {
                if(c.cp.n>0)
                {
                    d.x=c.cp.vd[0].x;
                    d.y=c.cp.vd[0].y;
                    remover(0,c.cp);
                    inserir(d,c.j1);
                    status(c);
                    opcoesdojogador(c,d,1);

                }
                else
                {
                    status(c);
                    cout<<"Nao ha pecas para comprar !!!"<<endl;
                    return c;
                }
            }
        }
        else
        {
            status(c);
            cout<<"Nao ha pecas para o jogador 1 !!!"<<endl;
            return c;
        }
    }
    if(u==2)
    {
        if(c.j2.n>0)
        {
            cout<<endl<<"1 - para jogar uma peca. "<<"2 - para comprar uma peca: ";
            cin>>h;
            if(h==1)
            {

                cout<<endl<<"escolha uma peca de 1 a "<<c.j2.n<<": ";
                for(int j=0; j<c.j2.n; j++)
                {
                    cout<<c.j2.vd[j].x<<"/"<<c.j2.vd[j].y;
                    cout<<" , ";
                }
                cin>>h;
                d.x=c.j2.vd[h-1].x;
                d.y=c.j2.vd[h-1].y;
                //verificar se pode jogar a peca na mesa;
                if(c.mesa.n>0)
                {
                    if(d.x==c.mesa.vd[0].x || d.x==c.mesa.vd[c.mesa.n].y || d.y==c.mesa.vd[0].x || d.y==c.mesa.vd[c.mesa.n].y)
                    {
                        remover(h-1,c.j2);
                        inserir(d,c.mesa);
                        cout<<endl;
                        cout << "caso queira com estilo led, digite 1, caso contrario, digite 0"<< endl;
                        cin >> e;
                        c.mesa.vd[c.mesa.n-1].estilo=estilo(e);
                        cout << "escolha a orientacao, sabendo que: 1-vertical; 2-vertical invertido; 3-horizontal; 4-horiontal invertida" << endl;
                        cin >> o;
                        c.mesa.vd[c.mesa.n-1].orientacao=o;
                        status(c);
                        return c;

                    }
                    else
                    {
                        cout<<"Nao pode jogar essa peca. Escolha outra peca: ";
                        status(c);
                        opcoesdojogador(c,d,2);
                    }
                }
                else
                {
                    remover(h-1,c.j2);
                    inserir(d,c.mesa);
                    cout<<endl;
                    cout << "caso queira com estilo led, digite 1, caso contrario, digite 0"<< endl;
                    cin >> e;
                    c.mesa.vd[c.mesa.n-1].estilo=estilo(e);
                    cout << "escolha a orientacao, sabendo que: 1-vertical; 2-vertical invertido; 3-horizontal; 4-horiontal invertida" << endl;
                    cin >> o;
                    c.mesa.vd[c.mesa.n-1].orientacao=o;
                    status(c);
                    return c;
                }
            }
            if(h==2)
            {
                if(c.cp.n>0)
                {
                    d.x=c.cp.vd[0].x;
                    d.y=c.cp.vd[0].y;
                    remover(0,c.cp);
                    inserir(d,c.j2);
                    status(c);
                    opcoesdojogador(c,d,2);
                }
                else
                {
                    status(c);
                    cout<<"Nao ha pecas para comprar !!!"<<endl;
                    return c;
                }
            }
        }

        else
        {
            cout<<"Nao ha pecas para o jogador 2"<<endl;
        }
    }
}

void menu()
{
    int p=0,k=0,n;
    cout<<"JOGO DE DOMINO MULTIPLAYER";
    cout<<endl;
    cout<<endl<<"Digite 1 para comecar a jogar!";
    cout<<endl;
    cin>>n;
    if(n==1)
    {

        domino d;
        jogo c = jogo_inic();
        status(c);
        cout<<endl<<"escolha a opcao: ";

        if(maiorpecaJ1(c))
        {
            cout<<endl<<"jogador 1: ";
            k=2;
            c=opcoesdojogador(c,d,1);

        }
        else
        {
            cout<<endl<<"jogador 2: ";
            k=1;
            c=opcoesdojogador(c,d,2);
        }

        while(p<1)
        {
            if(k==1)
            {
                cout<<endl<<"jogador 1: ";
                k=2;
                c=opcoesdojogador(c,d,1);
                //if(Terminou(c)){
                //        if()
               // Ganhou(c);

            }
            if(k==2)
            {
                cout<<endl<<"jogador 2: ";
                k=1;
                c=opcoesdojogador(c,d,2);
                //if(Terminou(c)){
                //        if()
               // Ganhou(c);
            }

        }
    }

}
int main ()
{
    menu();
    return 0;
}
