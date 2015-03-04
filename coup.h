#ifndef COUP_H_INCLUDED
#define COUP_H_INCLUDED
#include "piece.h"
#include "echiquier.h"
class coup
{
    public:
    
    couleur col;
    piece piece_jouee;
    piece piece_mangee;
    
    bool coup_possible(echiquier &); //explorer les coups possible en base des placements possibles
    coup(); //initialisation d'un coup;
    
    position pos_ancienne; //l'ancienne position
    position pos_nouvelle; //la nouvelle position
    bool prise_de_piece(); //tester s'il y a prise de piece(un est mangee par l'autre)
    enum coup_speciaux; //tout les coup speciaux
    bool coup_special(); //tester si c'est un coup special

};

#endif // COUP_H_INCLUDED
