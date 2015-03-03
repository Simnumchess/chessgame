#include "definition.h"
#include "piece.h"
#include <iostream>
#include <ostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

using namespace std;

void Piece::print()
{
    switch(type_piece)
    {
        case Pion:
        if(couleur==blanc)
        cout<<"Pb"<<" ";
        else cout<<"Pn"<<" ";
        break;

        case Tour:
        if(couleur==blanc)
        cout<<"Tb"<<" ";
        else cout<<"Tn"<<" ";
        break;

        case Cavalier:
        if(couleur==blanc)
        cout<<"Cb"<<" ";
        else cout<<"Cn"<<" ";
        break;

        case Fou:
        if(couleur==blanc)
        cout<<"Fb"<<" ";
        else cout<<"Fn"<<" ";
        break;

        case Dame:
        if(couleur==blanc)
        cout<<"Db"<<" ";
        else cout<<"Dn"<<" ";
        break;

        case Roi:
        if(couleur==blanc)
        cout<<"Rb"<<" ";
        else cout<<"Rn"<<" ";
        break;

        case Piecevide:
        cout<<"  ";
        break;
    }
}
int Piece::getvaleurpiece()
{
    int v; //on decide la valeur du v
    switch(type_piece)
    {
        case Pion:
        return v;
        break;
        case Tour:
        return 5*v;
        break:
        case Cavalier:
        return 3*v:
        break;
        case Fou:
        return 3*v;
        break;
        case Dame:
        return 9*v;
        break;
        case Roi:
        return 0;
        break;
        case Piecevide:
        return 0;
        break;
    }
}
bool Piece::deplacement()
{
    int l=Piece.deplacementl;
    int c=Piece.deplacementc; //(l,c) deplacement relatif
    int i=Piece.i;
    int j=Piece.j; //(i,l) coordonnee de la piece apres deplacement
    switch(type_piece)
    {
        case Pion:
        {
            if(couleur==blanc)
            {
                if((((i-1)==l)&&(j==c))||(((i-2)==l)&&(j==c)&&(i==6)))
                {
                    return true;
                    break;
                }
                else
                {
                    return false;
                    break;
                }
            }
            else
            {
                if((((i+1)==l)&&(j==c))||(((i+2)==l)&&(j==c)&&(i==1)))
                {
                    return true;
                    break;
                }
                else
                {
                    return false;
                    break;
                }

            }
        }
        case Tour:
        {
            if(j==c)
            {
                return true;
                break;
            }
            else
            {
                if(i==l)
                {
                    return true;
                    break;
                }
                else
                {
                    return false;
                    break;
                }
            }
        }
        case Cavalier:
        {
            if((i==(l+1))&&(j==(c+2)))
            {
                return true;
                break;
            }
            else if((i==(l+2))&&(j==(c+1)))
            {
                return true;
                break;
            }
            else if((i==(l-1))&&(j==(c+2)))
            {
                return true;
                break;
            }
            else if((i==(l-2))&&(j==(c+1)))
            {
                return true;
                break;
            }
            else if((i==(l+2))&&(j==(c-1)))
            {
                return true;
                break;
            }
            else if((i==(l+1))&&(j==(c-2)))
            {
                return true;
                break;
            }
            else
            {
                return false;
                break;
            }
        }
        case Fou:
        {
            if(((i-l)==(j-c))||((i-l)==(c-j)))
            {
                return true;
                break;
            }
            else
            {
                return false;
                break;
            }
        }
        case Dame:
        {
            if(abs(i-l)==abs(j-c))
            {
                return true;
                break;
            }
            if(j==c)
            {
                return true;
                break;
            }
            else
            {
                if(i==l)
                {
                    return true;
                    break;
                }
                else
                {
                    return false;
                    break;
                }
            }
        }
        case Roi:
        {
            if(i==l+1)&&(j==c)
            {
                return true;
                break;
            }

            else if(i==l)&&(j==c+1)
            {
                return true;
                break;
            }
            else if(i==l-1)&&(j==c+1)
            {
                return true;
                break;
            }
            else if(i==l+1)&&(j==c+1)
            {
                return true;
                break;
            }
            else if(i==l)&&(j==c)
            {
                return true;
                break;
            }
            else if(i==l-1)&&(j==c)
            {
                return true;
                break;
            }
            else
            {
                return false;
                break;
            }
        }
        case PV:
        return false;
        break;

    }
    Piece & Piece::operator=(const Piece & p)
    {
        if(this==&p)
        return *this;
        else
        {
            Piece=p.Piece;
            couleur=p.couleur;
            val=p.val;
            placementl=p.placementl;
            placementc=p.placementc;
        }
    }
    piece::~piece()
    {

    }
    piece::piece()
    {

    }

}








