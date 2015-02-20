#include <iostream>
#include <stdlib.h>
#include <piece.h>
using namespace std;
void TypePiece::print()
{
    switch(type)
    {
        case pion:
        if(couleur==blanc)
        cout<<"Pb"<<" ";
        else cout<<"Pn"<<" ";
        break;

        case tour:
        if(couleur==blanc)
        cout<<"Tb"<<" ";
        else cout<<"Tn"<<" ";
        break;

        case cavalier:
        if(couleur==blanc)
        cout<<"Cb"<<" ";
        else cout<<"Cn"<<" ";
        break;

        case fou:
        if(couleur==blanc)
        cout<<"Fb"<<" ";
        else cout<<"Fn"<<" ";
        break;

        case dame:
        if(couleur==blanc)
        cout<<"Db"<<" ";
        else cout<<"Dn"<<" ";
        break;

        case roi:
        if(couleur==blanc)
        cout<<"Rb"<<" ";
        else cout<<"Rn"<<" ";
        break;

        case piece_vide:
        cout<<"  ";
        break;
    }
}
int TypePiece::getvaleurpiece(int v)
{
    switch(piece)
    {
        case pion:
        return v;
        break;
        case tour:
        return 5*v;
        break:
        case cavalier:
        return 3*v:
        break;
        case fou:
        return 3*v;
        break;
        case dame:
        return 9*v;
        break;
        case roi:
        return 0;
        break;
        case piece_vide:
        return 0;
        break;
    }
}
bool TypePiece::deplacement(int l,int c)
{
    int i=TypePiece.placementl;
    int j=TypePiece.placementc;
    switch(piece)
    {
        case pion:
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
        case tour:
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
        case cavalier:
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
        case fou:
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
        case dame:
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
        case roi:
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
        case piece_vide:
        return false;
        break;

    }
    piece & piece::operator=(const piece & p)
    {
        if(this==&p)
        return *this;
        else
        {
            piece=p.piece;
            couleur=p.couleur;
            val_piece=p.val_piece;
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








