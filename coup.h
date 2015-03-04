#ifndef COUP_H_INCLUDED
#define COUP_H_INCLUDED
#include "piece.h"
#include "echiquier.h"
class Coup
{
    public:
    
    Couleur col;
    Piece piece_jouee;
    Piece piece_mangee;
    
    bool coup_possible(echiquier &); //explorer les coups possible en base des placements possibles
    Coup(); //initialisation d'un coup;
    
    Position pos_ancienne; //l'ancienne position
    Position pos_nouvelle; //la nouvelle position
    bool prise_de_piece(); //tester s'il y a prise de piece(un est mangee par l'autre)
    enum coup_speciaux; //tout les coup speciaux
    bool coup_special(); //tester si c'est un coup special

};

#endif // COUP_H_INCLUDED
