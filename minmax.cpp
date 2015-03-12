#include "definition.h"
#include "piece.h"
#include <iostream>
#include <ostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

using namespace std;

void piece::print()
{
    switch(type_piece)
    {
        case Pion:
        if(color==blanc)
        cout<<"Pb"<<" ";
        else cout<<"Pn"<<" ";
        break;

        case Tour:
        if(color==blanc)
        cout<<"Tb"<<" ";
        else cout<<"Tn"<<" ";
        break;

        case Cavalier:
        if(color==blanc)
        cout<<"Cb"<<" ";
        else cout<<"Cn"<<" ";
        break;

        case Fou:
        if(color==blanc)
        cout<<"Fb"<<" ";
        else cout<<"Fn"<<" ";
        break;

        case Dame:
        if(color==blanc)
        cout<<"Db"<<" ";
        else cout<<"Dn"<<" ";
        break;

        case Roi:
        if(color==blanc)
        cout<<"Rb"<<" ";
        else cout<<"Rn"<<" ";
        break;

        case Piecevide:
        cout<<"   ";//3espaces 2 pour les lettres et un espace
        break;
    }
}
int piece::getvaleurpiece()
{
    int v=1; //on decide la valeur du v
    switch(type_piece)
    {
        case Pion:
        return v;
        break;
        case Tour:
        return 5*v;
        break;
        case Cavalier:
        return 3*v;
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
bool piece::deplacement(int l,int c)
{
    piece Piece;
    l=Piece.deplacementl;
    c=Piece.deplacementc; //(l,c) coordonnee de la piece apres deplacement
    int i=Piece.i;
    int j=Piece.j; //(i,l) coordonnee de la piece apres deplacement
    switch(type_piece)
    {
        case Pion:
        {
            if(color==noir)
            {
                if( ( ((i-1)==l)&&(j==c) )||( ((i-2)==l)&&(j==c)&&(i==6) ) || ( ((i-1)==l)&&(j-1)==c) || ( ((i-1)==l)&&(j+1)==c))
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
            else if(color==blanc)
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
            if (i==l+1 && j==c)
            {
                return true;
                break;
            }

            else if (i==l && j==c+1)
            {
                return true;
                break;
            }
            else if (i==l-1 && j==c+1)
            {
                return true;
                break;
            }
            else if (i==l+1 && j==c+1)
            {
                return true;
                break;
            }
            else if (i==l && j==c)
            {
                return true;
                break;
            }
            else if (i==l-1 && j==c)
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
        case Piecevide:
        {
            return false;
            break;
        }
    }
}
piece& piece::operator=(const piece & P)
{
        if (this==&P) return *this;
        else
        {
            type_piece=P.type_piece;
            color=P.color;
            val=P.val;
            i=P.i;
            j=P.j;
            deplacementl=P.deplacementl;
            deplacementc=P.deplacementc;
            return *this;
        }
}

piece::piece()
    {
        type_piece=Piecevide;
        val=0;
    }

piece::~piece()
{
}






