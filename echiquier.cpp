#include "echiquier.h"
#include "piece.h"
#include "definition.h"
#include <iostream>
#include <ostream>

using namespace std;

echiquier::echiquier() //initialisation
{
    dim=8; //la dimension d'un echiquier
    echectab=new piece*[dim];
    for(int i=0;i<dim;i++)
    {
        echectab[i]=new piece[dim];
        {
            for(int j=0;j<dim;j++)
            {
                piece PV;
                PV.type_piece=Piecevide;
                echectab[i][j]=PV;
            }
            
        }
    }
    for(int i=0;i<8;i++)
    {
        piece Pb;
        Pb.type_piece=Pion;
        Pb.color=blanc;
        echectab[1][i]=Pb;

        piece Pn;
        Pn.type_piece=Pion;
        Pn.color=noir;
        echectab[6][i]=Pn;

        piece Tb;
        Tb.type_piece=Tour;
        Tb.color=blanc;
        echectab[0][0]=Tb;
        echectab[0][7]=Tb;

        piece Tn;
        Tn.type_piece=Tour;
        Tn.color=noir;
        echectab[7][0]=Tn;
        echectab[7][7]=Tn;

        piece Cb;
        Cb.type_piece=Cavalier;
        Cb.color=blanc;
        echectab[0][1]=Cb;
        echectab[0][6]=Cb;

        piece Cn;
        Cn.type_piece=Cavalier;
        Cn.color=noir;
        echectab[7][1].color=noir;
        echectab[7][6].color=noir;

        piece Fb;
        Fb.type_piece=Fou;
        Fb.color=blanc;
        echectab[0][2]=Fb;
        echectab[0][5]=Fb;

        piece Fn;
        Fn.type_piece=Fou;
        Fn.color=noir;
        echectab[7][2]=Fn;
        echectab[7][5]=Fn;

        piece Db;
        Db.type_piece=Dame;
        Db.color=blanc;
        echectab[0][3]=Db;

        piece Dn;
        Dn.type_piece=Dame;
        Dn.color=noir;
        echectab[7][3]=Dn;

        piece Rb;
        Rb.type_piece=Roi;
        Rb.color=blanc;
        echectab[0][4]=Rb;

        piece Rn;
        Rn.type_piece=Roi;
        Rn.color=noir;
        echectab[7][4]=Dn;
    }

}
echiquier::~echiquier()
{
    if(echectab!=NULL)
        for(int i=0;i<8;i++)
    delete []echectab[i];
    delete []echectab;
}
void echiquier::print()
{
    char a[8]={'A','B','C','D','E','F','G','H'};
    int b[8]={'1','2','3','4','5','6','7','8'};
    for(int i=0;i<dim;i++)
    {
        cout<<"  ";
        cout<<a[i]<<"  ";
        cout<<endl;
    }
    for(int i=0;i<dim;i++)
    {
        cout<<b[i]<<" ";
        for(int j=0;j<8;j++)
        {
            piece P;
            P=echectab[i][j];
            P.print();
        }
        cout<<b[i]<<endl;
    }
    for(int i=0;i<dim;i++)
    {
        cout<<"  ";
        cout<<a[i]<<"  ";
        cout<<endl;
    }

}
echiquier::echiquier(const echiquier & Echec) //constructeur par copie
{
    dim=Echec.dim;
    echectab=new piece*[dim];
    for(int i=0;i<dim;i++)
    {
        for(int j=0;j<dim;j++)
        echectab[i][j]=Echec.echectab[i][j];
    }

}
echiquier & echiquier::operator=(const echiquier & Echec)  //operator par copie
{
    dim=Echec.dim;
    echectab=NULL;
    if(dim<=0)
    return *this;
    echectab=new piece*[8];
     for(int i=0;i<dim;i++)
    {
        for(int j=0;j<dim;j++)
        echectab[i][j]=Echec.echectab[i][j];
    }
    return *this;

}
bool echiquier::casevide(int l,int c)
{
    if(echectab[l][c].type_piece==Piecevide)
    return true;
    else
    return false;
}

