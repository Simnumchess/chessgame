#include "ttt.h"
#include "piece.h"
#include "definition.h"
#include <iostream>
#include <ostream>


ttt::ttt() //initialisation
{
    char ttttab[dim][dim];
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
    cout<<endl;
    cout<<"   A   B   C"<<endl;
    
    cout<<"1  "<<ttttab[0][0]<<" | "<<ttttab[0][1]<<" | "<<ttttab[0][2]<<endl;
    cout<<"   ---------"<<endl;
    
    cout<<"2  "<<ttttab[1][0]<<" | "<<ttttab[1][1]<<" | "<<ttttab[1][2]<<endl;
    cout<<"   ---------"<<endl;
    
    cout<<"3  "<<ttttab[2][0]<<" | "<<ttttab[2][1]<<" | "<<ttttab[2][2]<<endl;
    cout<<endl;
    
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


