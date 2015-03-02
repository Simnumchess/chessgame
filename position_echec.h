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
    Joueur Jeu_pos; //un indicateur sur le joueur qui doit jouer cette position: {humain;ordinateur}
    echiquier echiquier_ref; //definition d'un echiquier de reference(le dernier etat connu de l'echiquier)
    position_echec(); //constructeur d'une position
    double getvaleur() const; //renvoie la valeur d'une position
    
    position_echec(const position_echec &) //constructeur par copie
    position_echec & operator=(const position_echec &) //operateur =
    
    ~position_echec(); //destructeur d'une position
    void print(); 
};


#endif // POSITION_GLOBALE_H_INCLUDED

