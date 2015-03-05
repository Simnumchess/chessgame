#include "ttt.h"
#include "piece.h"
#include "definition.h"
#include <iostream>
#include <ostream>

using namespace std;

ttt::ttt() //initialisation
{
    dim=3; //la dimension d'un ttt
    ttttab=new piece*[3];
    for(int i=0;i<3;i++)
    {
        ttttab[i]=new piece[3];
        {
            for(int j=0;j<3;j++)
            ttttab[i][j]=0;
        }
    }
}


ttt::~ttt()
{
    if(ttttab!=NULL)
    for(int i=0:i<3;i++)
    {
        delete []ttttab[i];
        for(int j=0;j<3;j++)
        delete []ttttab;
    }
}


void ttt::print()
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        cout<<ttttab[i][j]<<endl; // Comment on fait pour sauter une ligne ? Automatique ?
    }
}


ttt::ttt(const ttt & TTT) //constructeur par copie
{
    dim=TTT.dim;
    ttttab=new piece*[dim];
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
    ttttab=new piece*[3];
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


