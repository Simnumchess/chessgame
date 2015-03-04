#include "coup.h"
#include <stdlib.h>
#include "piece.h"
using namespace std;

    Coup::Coup()
    {
    }
    couleur col;
    Piece piece_jouee;
    Position pos_ancienne;
    Position pos_nouvelle;
    bool prise_de_piece;
    enum Coup::coup_speciaux
    {
        petit_roque;
        promotion;
        prise_en_passant;

    }


    Coup::~coup()
    {

    }
    void Coup::print()
    {

    }
    
bool Coup::coup_possible(echiquier E)
{
    switch(piece_jouee.type_piece)
    {
        case Pion:
        
    }
}
