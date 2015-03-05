#ifndef POSITION_TTT_H_INCLUDED
#define POSITION_TTT_H_INCLUDED
#include "piece.h"
#include "definition.h"
#include "ttt.h"
#include "coup.h"
#include "position.h"

class position_ttt : class position
{
    public:
    coup coup_joue; //
    coup* coup_historique; //memorisation de l'historique des coups joues 
    coup annul_coup(); //annulation d'un coup??
    int resultat(); //regarde si un joueur a gagne
    position* pos_soeur; //un pointeur sur la position soeur
    position* pos_fille; //un pointeur sur la premiere position fille
    joueur Jeu_pos; //un indicateur sur le joueur qui doit jouer cette position: {humain;ordinateur}
    ttt ttt_ref; //definition d'un echiquier de reference(le dernier etat connu de l'echiquier)
    position_ttt maj(); //mise a jour des positions
    double getvaleur() const; //renvoie la valeur d'une position
    position_ttt* get_pos_suiv(); //constructeur de toutes les positions suivantes a une profondeur donnee
    
    position_ttt(); //constructeur d'une position
    position_ttt(const position_ttt &) //constructeur par copie
    position_ttt & operator=(const position_ttt &) //operateur =
    ~position_ttt(); //destructeur d'une position
};
void partie(); //definiton d'une partie



#endif // POSITION_TTT_H_INCLUDED

