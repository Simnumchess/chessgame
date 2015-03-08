#include "ttt.h"
#include "piece.h"
#include "definition.h"
#include <iostream>
#include <ostream>

using namespace std;

ttt::ttt() //initialisation
{
    dim=3; //la dimension d'un ttt
    ttttab=new char*[dim];
    for(int i=0;i<dim;i++)
    {
        ttttab[i]=new char[dim];
        {
            for(int j=0;j<dim;j++)
            ttttab[i][j]=' ';
        }
    }
}


ttt::~ttt()
{
    if(ttttab!=NULL)
    for(int i=0:i<dim;i++)
    {
        delete []ttttab[i];
        delete []ttttab;
    }
}


void ttt::print()
{
    char* ttt_tab_indicel[dim];//lettres
    char* ttt_tab_indicec[dim];//chiffres
    ttt_tab_indicel[0]='A';
    ttt_tab_indicel[1]='B';
    ttt_tab_indicel[2]='C';

    ttt_tab_indicec[0]='1';
    ttt_tab_indicec[1]='2';
    ttt_tab_indicec[2]='3';

    for(int i=0:i<dim;i++) //premiere ligne : les indices lettres
    {
        cout<<"  ";
        cout<<ttt_tab_indicel[i]<<"  ";
        cout<<endl;
    }
    {
        for(int i=0;i<dim,i++) //on parcourt les lignes
        {
            cout<<ttt_tab_indicec[i]<<" ";//indice chiffre
            for(int j=0;j<dim;j++)
            {
                cout<<ttttab[i][j]<<"|";
            }
            cout<<ttt_tab_indicec[i]<<endl; //indice chiffre, puis on passe à la ligne
            cout<<"------"<<endl;
        }
    }
    for(int i=0:i<dim;i++)
    {
        cout<<"  ";
        cout<<ttt_tab_indicel[i]<<"  ";//dernière ligne : indices lettres
        cout<<endl;
    }
}



ttt::ttt(const ttt & TTT) //constructeur par copie
{
    dim=TTT.dim;
    ttttab=new int*[dim];
    for(int i=0;i<dim;i++)
    {
        for(int j=0;j<dim;j++)
        ttttab[i][j]=TTT.ttttab[i][j];
    }
}


ttt::ttt & operator=(const ttt & TTT) //operator par copie
{
    dim=TTT.dim;
    ttttab=NULL;
    if(dim<=0)
    return *this;
    ttttab=new int*[dim];
     for(int i=0;i<dim;i++)
    {
        for(int j=0;j<dim;j++)
        ttttab[i][j]=TTT.ttttab[i][j];
    }
    return *this;
}


bool ttt::casevide(int l,int c)
{
    if(ttttab[l][c]==0)
    return true;
    else
    return false;
}


