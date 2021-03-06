#include "echiquier.h"
#include "piece.h"
#include "definition.h"
#include <iostream>
#include <ostream>

using namespace std;

echiquier::echiquier() //initialisation
{
    for(int k=0;k<8;k++)
    {
        for(int j=0;j<8;j++)
        {
            piece PV;
            PV.type_piece=Piecevide;
            echectab[k][j]=PV;
        }
    }
    for(int i=0;i<8;i++)
    {
        piece Pb;
        Pb.type_piece=Pion;
        Pb.color=blanc;
        echectab[6][i]=Pb;

        piece Pn;
        Pn.type_piece=Pion;
        Pn.color=noir;
        echectab[1][i]=Pn;

        piece Tb;
        Tb.type_piece=Tour;
        Tb.color=blanc;
        echectab[7][0]=Tb;
        echectab[7][7]=Tb;

        piece Tn;
        Tn.type_piece=Tour;
        Tn.color=noir;
        echectab[0][0]=Tn;
        echectab[0][7]=Tn;

        piece Cb;
        Cb.type_piece=Cavalier;
        Cb.color=blanc;
        echectab[7][1]=Cb;
        echectab[7][6]=Cb;

        piece Cn;
        Cn.type_piece=Cavalier;
        Cn.color=noir;
        echectab[0][1]=Cn;
        echectab[0][6]=Cn;

        piece Fb;
        Fb.type_piece=Fou;
        Fb.color=blanc;
        echectab[7][2]=Fb;
        echectab[7][5]=Fb;

        piece Fn;
        Fn.type_piece=Fou;
        Fn.color=noir;
        echectab[0][2]=Fn;
        echectab[0][5]=Fn;

        piece Db;
        Db.type_piece=Dame;
        Db.color=blanc;
        echectab[7][3]=Db;

        piece Dn;
        Dn.type_piece=Dame;
        Dn.color=noir;
        echectab[0][3]=Dn;

        piece Rb;
        Rb.type_piece=Roi;
        Rb.color=blanc;
        echectab[7][4]=Rb;

        piece Rn;
        Rn.type_piece=Roi;
        Rn.color=noir;
        echectab[0][4]=Dn;
    }

}

 /*
  echiquier::~echiquier()
{
    if(echectab!=NULL)
    {
        for(int i=0;i<8;i++)
        {
            for(int j=0;j<8;j++)
            {
            delete []echectab[i][j];
            }
        delete []echectab[i];
        }
    }
}

*/

echiquier::~echiquier()
{
}

void echiquier::print()
{
    cout<<"A  B  C  D  E  F  G  H";

    for (int i=0; i<8; i++)
    {
        cout<<endl;
        for (int j=0; j<8; j++)
        {
            echectab[i][j].print();
        }
        cout<<i+1;
    }
    cout<<endl<<endl;
    
}
    


 echiquier::echiquier(const echiquier & Echec) //constructeur par copie
{
    piece echectab[8][8];
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++) {echectab[i][j]=Echec.echectab[i][j];}
    }

}
 


 echiquier & echiquier::operator=(const echiquier & Echec) //operator par copie
{
    piece echectab[8][8];
     for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
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

