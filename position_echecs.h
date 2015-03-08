
#ifndef POSITION_ECHECS_H_INCLUDED
#define POSITION_ECHECS_H_INCLUDED
#include "piece.h"
#include "definition.h"
#include "echiquier.h"
#include "coup.h"

class position_echecs
{
    public:
    coup coup_joue; //
    // coup* coup_historique; //memorisation de l'historique des coups joues
    // coup annul_coup(); //annulation d'un coup??
    int resultat(); //regarde si un joueur a gagne
    int val_pos_ordinateur(); //renvoie la valeur de la position de l'ordinateur
    int val_pos_humain(); //renvoir la valeur de la position du huamin
    position_echecs* pos_soeur; //un pointeur sur la position soeur
    position_echecs* pos_fille; //un pointeur sur la premiere position fille
    Joueur Jeu_pos; //un indicateur sur le joueur qui doit jouer cette position: {humain;ordinateur}
    echiquier echiquier_ref; //definition d'un echiquier de reference(le dernier etat connu de l'echiquier)
    position_echecs maj(); //mise a jour des positions
    double getvaleur(); //renvoie la valeur d'une position
    position_echecs* get_pos_suiv(); //constructeur de toutes les positions suivantes a une profondeur donnee
    
    position_echecs(); //constructeur d'une position
    position_echecs(const position_echecs &); //constructeur par copie
    position_echecs & operator=(const position_echecs &); //operateur =
    ~position_echecs(); //destructeur d'une position
};



#endif // POSITION_ECHECS_H_INCLUDEDDED

