#include "Echiquier.h"
#include "Piece.h"
#include "Coup.h"
#include <iostream>
#include <ostream>

bool Coup::prise_piece(Echiquier e)
{
    if (e.echectab[nouvelle_l][nouvelle_c].type_piece.Nom_piece==Piecevide)
    {
        return false;
    }
    else return true;
}

void Coup::conv_num_lettre(int n)
{
    switch(n)
    {
    case 0:
    cout<<'A';
    break;

    case 1:
    cout<<'B';
    break;

    case 2:
    cout<<'C';
    break;

    case 3:
    cout<<'D';
    break;

    case 4:
    cout<<'E';
    break;

    case 5:
    cout<<'F';
    break;

    case 6:
    cout<<'G';
    break;

    case 7:
    cout<<'H';
    break;
    }
}

void Coup::coda_std_cp(Echiquier e)
{
    switch (piece_jouee.type_piece.Nom_piece)
        {
        case Pion:
        break;

        case Roi:
        cout<<'Roi';
        break;

        case Tour:
        cout<<'Tour';
        break;

        case Cavalier:
        cout<<'Cavalier';
        break;

        case Fou:
        cout<<'Fou';
        break;

        case Dame:
        cout<<'Dame';
        break;

    if (prise_piece(e))
        {
        cout<<'x';
        }
        conv_num_lettre(ancienne_c);
        cout<<ancienne_l;
        cout<<"-";
        conv_num_lettre(nouvelle_c);
        cout<<nouvelle_l;
    }
}


Coup::~Coup()
{

}

Coup::Coup()
{
    color=blanc;
    piece_jouee=Piece();
    ancienne_l=0;
    ancienne_c=0;
    nouvelle_l=0;
    nouvelle_c=0;
}


Coup::Coup(const Coup & p) //operateur par copie
{
    color=p.color;
    piece_jouee=p.piece_jouee;
    ancienne_l=p.ancienne_l;
    ancienne_c=p.ancienne_c;
    nouvelle_l=p.nouvelle_l;
    nouvelle_c=p.nouvelle_c;

}

Coup & Coup::operator=(const Coup & p) //operateur = pour une piece
{
    if (this==&p) return *this;
    else{
    color=p.color;
    piece_jouee=p.piece_jouee;
    ancienne_l=p.ancienne_l;
    ancienne_c=p.ancienne_c;
    nouvelle_l=p.nouvelle_l;
    nouvelle_c=p.nouvelle_c;

    return *this;}
}

