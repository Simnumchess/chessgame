
#ifndef COUP_H_INCLUDED
#define COUP_H_INCLUDED

#include"piece.h"
#include"echiquier.h"

class coup
{
    public :
    piece piece_jouee;
    piece piece_mangee;
    int ligne_init;
    int colonne_init;
    int ligne_final;
    int colonne_final;
    couleur color;
    bool coup_possible_non_complet(echiquier e);
    bool coup_possible(echiquier e); //on essaye d'utiliser les fonctions déplacement de chaque piece dans cette fonction...
    bool obstacle(echiquier e);
    bool echec(echiquier e);
    coup(); //constructeur
    coup & operator=(const coup &); //operateur = pour un coup
     coup(const coup & p); //operateur par copie
    ~coup();
};

#endif // COUP_H_INCLUDED
