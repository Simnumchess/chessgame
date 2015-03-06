#include "echiquier.h"
#include "piece.h"
#include "definition.h"
#include <iostream>
#include <ostream>

using namespace std;

ehciquier::echiquier() //initialisation
{
    dim=8; //la dimension d'un echiquier
    echectab=new piece*[dim];
    for(int i=0;i<dim;i++)
    {
        echectab[i]=new piece[dim];
        {
            for(int j=0;j<dim;j++)
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
        Pn.type_piece=Pion;
        Pn.col=noir;
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
echiquier::~echiquier()
{
    if(echectab!=NULL)
    for(int i=0:i<8;i++)
    delete []echectab[i];
    delete []echectab;
}
void echiquier::print()
{
    char* echec_tab_indicel[8];
    char* ehcec_tab_indicec[8];
    echec_tab_indicel[0]='A';
    echec_tab_indicel[1]='A';
    echec_tab_indicel[2]='A';
    echec_tab_indicel[3]='A';
    echec_tab_indicel[4]='A';
    echec_tab_indicel[5]='A';
    echec_tab_indicel[6]='A';
    echec_tab_indicel[7]='A';
    
    echec_tab_indicec[0]='1';
    echec_tab_indicec[1]='2';
    echec_tab_indicec[2]='3';
    echec_tab_indicec[3]='4';
    echec_tab_indicec[4]='5';
    echec_tab_indicec[5]='6';
    echec_tab_indicec[6]='7';
    echec_tab_indicec[7]='8';
    for(int i=0:i<dim;i++)
    {
        cout<<"  ";
        cout<<echec_tab_indicel[k]<<"  ";
        cout<<endl;
    }
    {
        for(int i=0;i<dim,i++)
        {
            cout<<echec_tab_indicec[i]<<" ";
            for(int j=0;j<8;j++)
            {
                Piece P;
                P=echectab[i][j];
                P.print(); 
                
            }
            cout<<echec_tab_indice[i]<<endl;
        }
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
        for(int j=0;j<dim;j++)
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

