
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
    echiquier echiquier_ref; //definition d'un echiquier de reference(le dernier etat connu de l'echiquier)
    int nbcoup();
    // coup* liste_coup; //memorisation de l'historique des coups joués
    position_echecs* pos_soeur; //un pointeur sur la position soeur
    position_echecs* pos_fille; //un pointeur sur la premiere position fille
    Joueur Jeu_pos; //un indicateur sur le joueur qui doit jouer cette position: {humain, ordinateur}
    
    echiquier maj(); //mise a jour des positions
    int getvaleur(); //renvoie la valeur d'une position
    position_echecs* get_pos_suiv(position_echecs & ); //constructeur de toutes les positions suivantes a une profondeur donnee
    
    position_echecs(); //constructeur d'une position
    position_echecs(const position_echecs &); //constructeur par copie
    position_echecs & operator=(const position_echecs &); //operateur =
    ~position_echecs(); //destructeur d'une position
    
    position_echecs IA();//jeu
    
    bool fin_partie();//indicateur de fin de partie
    
};



#endif // POSITION_ECHECS_H_INCLUDEDDED

