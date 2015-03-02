#ifndef POSITION_GLOBALE_H_INCLUDED
#define POSITION_GLOBALE_H_INCLUDED
#include "piece.h"
#include "definition.h"
#include "echiquier.h"
class position_echec : class position
{
    public:
    position* pos_soeur; //un pointeur sur la position soeur
    position* pos_fille; //un pointeur sur la premiere position fille
    Joueur Jeu_pos; //un indicateur sur le joueur qui doit jouer cette position
    ~position_echec();
    double getvaleur() const;

    position_echec(); //
    position_echec(const position_echec &)

    position_echec & operator=(const position_echec &)
    void print();

};


#endif // POSITION_GLOBALE_H_INCLUDED

