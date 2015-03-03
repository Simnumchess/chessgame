#ifndef POSITION_GLOBALE_H_INCLUDED
#define POSITION_GLOBALE_H_INCLUDED
#include "piece.h"
#include "definition.h"
#include "echiquier.h"
#include "coup.h"

class position_echec : class position
{
    public:
    coup coup_joue; //
    coup* coup_historique; //memorisation de l'historique des coups joues 
    coup annul_coup(); //annulation d'un coup??
    int resultat(); //regarde si un joueur a gagne
    position* pos_soeur; //un pointeur sur la position soeur
    position* pos_fille; //un pointeur sur la premiere position fille
    Joueur Jeu_pos; //un indicateur sur le joueur qui doit jouer cette position: {humain;ordinateur}
    echiquier echiquier_ref; //definition d'un echiquier de reference(le dernier etat connu de l'echiquier)
    position_echec maj(); //mise a jour des positions
    double getvaleur() const; //renvoie la valeur d'une position
    position_ehec* get_pos_suiv(); //constructeur de toutes les positions suivantes a une profondeur donnee
    
    position_echec(); //constructeur d'une position
    position_echec(const position_echec &) //constructeur par copie
    position_echec & operator=(const position_echec &) //operateur =
    ~position_echec(); //destructeur d'une position
};
void partie(); //definiton d'une partie



#endif // POSITION_GLOBALE_H_INCLUDED

