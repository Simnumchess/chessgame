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
    for(int i=0;i<dim;i++)
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
echiquier::~echiquier()
{
    if(echectab!=NULL)
    {
        for(int i=0;i<dim;i++)
        {
            delete []echectab[i];
        }
        delete []echectab;
    }
}
void echiquier::print()
{
    char echec_tab_indicel[8];
    char echec_tab_indicec[8];
    echec_tab_indicel[0]='8';
    echec_tab_indicel[1]='7';
    echec_tab_indicel[2]='6';
    echec_tab_indicel[3]='5';
    echec_tab_indicel[4]='4';
    echec_tab_indicel[5]='3';
    echec_tab_indicel[6]='2';
    echec_tab_indicel[7]='1';
    
    echec_tab_indicec[0]='A';
    echec_tab_indicec[1]='B';
    echec_tab_indicec[2]='C';
    echec_tab_indicec[3]='D';
    echec_tab_indicec[4]='E';
    echec_tab_indicec[5]='F';
    echec_tab_indicec[6]='G';
    echec_tab_indicec[7]='H';
    
    for(int k=0;k<dim;k++)
    {
        cout<<echec_tab_indicec[k]<<"  ";
    }
    for (int i=0; i<dim; i++)
    {
        cout<<endl;
        for (int j=0; j<dim; j++)
        {
            echectab[i][j].print();
        }
        cout<<echec_tab_indicel[i];
    }
    
    /*cout<<"    ";//4 espaces
     for(int i=0;i<dim;i++)
     {
     cout<<echec_tab_indicec[i]<<" ";
     
     for(int j=0;j<8;j++)
     {
     Piece P;
     P=echectab[i][j];
     P.print();
     }
     cout<<echec_tab_indicec[i]<<endl;
     }
     */
    /*for(int k=0;k<dim;k++)
     {
     cout<<"  ";
     cout<<echec_tab_indicel[k]<<"  ";
     cout<<endl;
     }
     cout<<"    ";//4 espaces
     for(int i=0;i<dim;i++)
     {
     cout<<echec_tab_indicec[i]<<" ";
     
     for(int j=0;j<8;j++)
     {
     Piece P;
     P=echectab[i][j];
     P.print();
     }
     cout<<echec_tab_indicec[i]<<endl;
     }
     */
    
    
    
}

echiquier::echiquier(const echiquier & Echec) //constructeur par copie
{
    dim=Echec.dim;
    echectab=new piece*[dim];
    for(int i=0;i<dim;i++)
    {
        for(int j=0;j<dim;j++) {echectab[i][j]=Echec.echectab[i][j];}
    }

}
echiquier & echiquier::operator=(const echiquier & Echec) //operator par copie
{
    dim=Echec.dim;
    echectab=NULL;
    if(dim<=0)
    return *this;
    echectab=new piece*[dim];
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

