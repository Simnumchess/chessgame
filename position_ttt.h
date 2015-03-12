
#ifndef POSITION_ECHECS_H_INCLUDED
#define POSITION_ECHECS_H_INCLUDED
#include "definition.h"
#include "ttt.h"

class position_ttt
{
public:
    ttt ttt_ref; //definition d'un echiquier de reference(le dernier etat connu de l'echiquier)
    // coup* coup_historique; //memorisation de l'historique des coups joues
    // coup annul_coup(); //annulation d'un coup??
    position_ttt* pos_soeur; //un pointeur sur la position soeur
    position_ttt* pos_fille; //un pointeur sur la premiere position fille
    Joueur Jeu_pos; //un indicateur sur le joueur qui doit jouer cette position: {humain, ordinateur}
    
    ttt maj(int); //mise a jour des positions
    position_ttt* get_pos_suiv(position_ttt & ); //constructeur de toutes les positions suivantes a une profondeur donnee
    
    position_ttt(); //constructeur d'une position
    position_ttt(const position_ttt &); //constructeur par copie
    position_ttt & operator=(const position_ttt &); //operateur =
    ~position_ttt(); //destructeur d'une position
    
    position_ttt IA();//jeu
    
    char fin_partie();//indicateur de fin de partie
    string getJoueur();
    
};



#endif // POSITION_ECHECS_H_INCLUDEDDED

