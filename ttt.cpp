#include "ttt.h"
#include "piece.h"
#include "definition.h"
#include <iostream>
#include <ostream>

using namespace std;

ttt::ttt() //initialisation
{
    dim=8; //la dimension d'un echiquier
    ttttab=new piece*[3];
    for(int i=0;i<3;i++)
    {
        echectab[i]=new piece[8];
        {
            for(int j=0;j<8;j++)
            piece PV;
            PV.type_piece=Piecevide;
            ehcectab[i][j]=PV;
        }
    }
    for(int i=0;i<8;i++)
    {
        piece Pb;
        Pb.type_piece=Pion;
        Pb.col=blanc;
        echectab[1][i]=Pb;

        piece Pn;
        Pb.type_piece=Pion;
        Pb.col=noir;
        echectab[6][i]=Pn;

        piece Tb;
        Tb.type_piece=Tour;
        Tb.col=blanc;
        echec[0][0]=Tb;
        echec[0][7]=Tb;

        piece Tn;
        Tn.type_piece=Tour;
        Tn.col=noir;
        echec[7][0]=Tn;
        echec[7][7]=Tn;

        piece Cb;
        Cb.type_piece=Cavalier;
        Cb.col=blanc;
        echec[0][1]=Cb;
        echec[0][6]=Cb;

        piece Cn;
        Cn.type_piece=Cvalier;
        Cn.col=noir;
        echec[7][1]=noir;
        echec[7][6]=noir;

        piece Fb;
        Fb.type_piece=Fou;
        Fb.col=blanc;
        echec[0][2]=Fb;
        echec[0][5]=Fb;

        piece Fn;
        Fn.type_piece=Fou;
        Fn.col=noir;
        echec[7][2]=Fn;
        echec[7][5]=Fn;

        piece Db;
        Db.type_piece=Dame;
        Db.col=blanc;
        echec[0][3]=Db;

        piece Dn;
        Dn.type_piece=Dame;
        Dn.col=noir;
        echec[7][3]=Dn;

        piece Rb;
        Rb.type_piece=Roi;
        Rb.col=blanc;
        echec[0][4]=Rb;

        piece Rn;
        Rn.type_piece=Roi;
        Rn.col=noir;
        echec[7][4]=Dn;
    }

}
ttt::~ttt()
{
    if(ttttab!=NULL)
    for(int i=0:i<8;i++)
    {
        delete []ttttab[i];
        for(int j=0;j<8;j++)
        delete []ttttab;
    }
}
void ttt::print()
{
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        Piece P;
        P=ttttab[i][j];
        P.print();
    }

}
ttt::ttt(const ttt & TTT) //constructeur par copie
{
    dim=TTT.dim;
    ttttab=new piece*[dim];
    for(int i=0;i<dim;i++)
    {
        for(j=0;j<dim;j++)
        ttttab[i][j]=TTT.ttttab[i][j];
    }

}
ttt::ttt & operator=(const ttt & TTT) //operator par copie
{
    dim=TTT.dim;
    ttttab=NULL;
    if(dim<=0)
    return *this;
    ttttab=new piece*[8];
     for(int i=0;i<dim;i++)
    {
        for(int j=0;j<dim;j++)
        ttttab[i][j]=TTT.ttttab[i][j];
    }
    return *this;

}
bool ttt::casevide(int l,int c)
{
    if(ttttab[l][c].type_piece==Piecevide)
    return true;
    else
    return false;
}


