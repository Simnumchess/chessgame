#include "echiquier.h"
#include "piece.h"
#include "definition.h"
#include <iostream>
#include <ostream>

using namespace std;

ehciquier::echiquier() //initialisation
{
    dim=8; //la dimension d'un echiquier
    echectab=new piece*[8];
    for(int i=0;i<8;i++)
    {
        echectab[i]=new piece[8];
        {
            for(j=0;j<8;j++)
            Piece PV;
            PV.type_piece=Piecevide;
            ehcectab[i][j]=PV;
        }
    }
    for(int i=0;i<8;i++)
    {
        Piece Pb;
        Pb.type_piece=Pion;
        Pb.col=blanc;
        echectab[1][i]=Pb;

        Piece Pn;
        Pb.type_piece=Pion;
        Pb.col=noir;
        echectab[6][i]=Pn;

        Piece Tb;
        Tb.type_piece=Tour;
        Tb.col=blanc;
        echec[0][0]=Tb;
        echec[0][7]=Tb;

        Piece Tn;
        Tn.type_piece=Tour;
        Tn.col=noir;
        echec[7][0]=Tn;
        echec[7][7]=Tn;

        Piece Cb;
        Cb.type_piece=Cavalier;
        Cb.col=blanc;
        echec[0][1]=Cb;
        echec[0][6]=Cb;

        Piece Cn;
        Cn.type_piece=Cvalier;
        Cn.col=noir;
        echec[7][1]=noir;
        echec[7][6]=noir;

        Piece Fb;
        Fb.type_piece=Fou;
        Fb.col=blanc;
        echec[0][2]=Fb;
        echec[0][5]=Fb;

        Piece Fn;
        Fn.type_piece=Fou;
        Fn.col=noir;
        echec[7][2]=Fn;
        echec[7][5]=Fn;

        Piece Db;
        Db.type_piece=Dame;
        Db.col=blanc;
        echec[0][3]=Db;

        Piece Dn;
        Dn.type_piece=Dame;
        Dn.col=noir;
        echec[7][3]=Dn;

        Piece Rb;
        Rb.type_piece=Roi;
        Rb.col=blanc;
        echec[0][4]=Rb;

        Piece Rn;
        Rn.type_piece=Roi;
        Rn.col=noir;
        echec[7][4]=Dn;
    }

}
echiquier::~echiquier()
{
    if(echectab!=NULL)
    for(int i=0:i<8;i++)
    {
        delete []echectab[i];
        for(int j=0;j<8;j++)
        delete []echectab;
    }
}
void echiquier::print()
{
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        Piece P;
        P=echectab[i][j];
        P.print();
    }

}
echiquier::echiquier(const echiquier & Echec) //constructeur par copie
{
    dim=Echec.dim;
    echectab=new piece*[dim];
    for(int i=0;i<dim;i++)
    {
        for(j=0;j<dim;j++)
        ehcectab[i][j]=Echec.echectab[i][j];
    }

}
echiquier::echiquier & operator=(const echiquier & Echec) //operator par copie
{
    dim=Echec.dim;
    echectab=NULL;
    if(dim<=0)
    return *this;
    echectab=new piece*[8];
     for(int i=0;i<dim;i++)
    {
        for(j=0;j<dim;j++)
        ehcectab[i][j]=Echec.echectab[i][j];
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

