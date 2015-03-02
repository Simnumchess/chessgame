#include "echiquier.h"
#include "piece.h"
#include "definition.h"
#include <iostream>


using namespace std;

ehciquier::echiquier() //initialisation
{
    dim=8;
    echectab=new piece*[8];
    for(int i=0;i<8;i++)
    {
        echectab[i]=new piece[8];
        {
            for(j=0;j<8;j++)
            Piece PV;
            PV.type=Piecevide;
            ehcectab[i][j]=PV;
        }
    }
    for(int i=0;i<8;i++)
    {
        Piece Pb;
        Pb.type=Pion;
        Pb.val=v;
        Pb.couleur=blanc;
        echectab[1][i]=Pb;

        Piece Pn;
        Pb.type=Pion;
        Pb.val=v;
        Pb.couleur=noir;
        echectab[6][i]=Pn;

        Piece Tb;
        Tb.type=tour;
        Tb.val=5*v;
        Tb.couleur=blanc;
        echec[0][0]=Tb;
        echec[0][7]=Tb;

        Piece Tn;
        Tn.type=tour;
        Tn.val=5*v;
        Tn.couleur=noir;
        echec[7][0]=Tn;
        echec[7][7]=Tn;

        Piece Cb;
        Cb.type=cavalier;
        Cb.val=3*v;
        Cb.couleur=blanc;
        echec[0][1]=Cb;
        echec[0][6]=Cb;

        Piece Cn;
        Cn.type=cavalier;
        Cn.val=3*v;
        Cn.couleur=noir;
        echec[7][1]=noir;
        echec[7][6]=noir;

        Piece Fb;
        Fb.type=fou;
        Fb.val=3*v;
        Fb.couleur=blanc;
        echec[0][2]=Fb;
        echec[0][5]=Fb;

        Piece Fn;
        Fn.type=fou;
        Fn.val=3*v;
        Fn.couleur=noir;
        echec[7][2]=Fn;
        echec[7][5]=Fn;

        Piece Db;
        Db.type=dame;
        Db.val=9*v;
        Db.couleur=blanc;
        echec[0][3]=Db;

        Piece Dn;
        Dn.type=dame;
        Dn.val=9*v;
        Dn.couleur=noir;
        echec[7][3]=Dn;

        Piece Rb;
        Rb.type=roi;
        Rb.val=0;
        Rb.couleur=blanc;
        echec[0][4]=Rb;

        Piece Rn;
        Rn.type=roi;
        Rn.val=0;
        Rn.couleur=noir;
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
        Piece p;
        p=echectab[i][j];
        p.print();
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
    if(echiquier[l][c]==piece_vide)
    return true;
    else
    return false;
}

