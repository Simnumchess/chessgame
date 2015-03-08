#include "ttt.h"
#include "piece.h"
#include "definition.h"
#include <iostream>
#include <ostream>

using namespace std;

ttt::ttt() //initialisation
{
    dim=3; //la dimension d'un ttt
    ttttab=new int*[dim];
    for(int i=0;i<dim;i++)
    {
        ttttab[i]=new int[dim];
        {
            for(int j=0;j<dim;j++)
            ttttab[i][j]=0;
        }
    }
}


ttt::~ttt()
{
    if(ttttab!=NULL)
    for(int i=0:i<dim;i++)
    {
        delete []ttttab[i];
        for(int j=0;j<dim;j++)
        delete []ttttab;
    }
}


void ttt::print()
{
    char* ttt_tab_indicel[dim];
    char* ehcec_tab_indicec[dim];
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
        for(int i=0;i<dim,i++) //on parcourt les colonnes
        {
            cout<<ttt_tab_indicec[i]<<" ";
            for(int j=0;j<dim;j++)
            {
                cout<<ttttab[i][j]<<" ";
            }
            cout<<ttt_tab_indicec[i]<<endl; //derniere ligne : les indices lettres
        }
    }
    for(int i=0:i<dim;i++)
    {
        cout<<"  ";
        cout<<ttt_tab_indicel[i]<<"  ";
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


