#include "coup.h"
#include <stdlib.h>
#include <piece.h>

    coup::coup()
    {
    }
    couleur col;
    piece piece_jouee;
    position pos_ancienne;
    position pos_nouvelle;
    bool prise_de_piece;
    enum coup::coup_speciaux
    {
        petit_roque;
        promotion;
        prise_en_passant;

    }


    coup::~coup()
    {

    }
    void coup::print()
    {

    }
