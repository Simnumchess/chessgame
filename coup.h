#ifndef COUP_H_INCLUDED
#define COUP_H_INCLUDED

#include "Piece.h"
#include "Echiquier.h"

//enum coup_speciaux{};

class Coup
{
    public :

    couleur color;
    Piece piece_jouee;
    int ancienne_l;//ancienne position ligne
    int ancienne_c;//ancienne position colonne
    int nouvelle_l;//nouvelle position ligne
    int nouvelle_c;//nouvelle position colonne
    bool prise_piece(Echiquier e);
    //bool coup_special;
    void conv_num_lettre(int n);//affiche la lettre correspondant au numero de colonne
    void coda_std_cp(Echiquier e);

    Coup(); //constructeur
    Coup & operator=(const Coup &); //operateur = pour un coup
     Coup(const Coup & p); //operateur par copie
    ~Coup();
};

#endif // COUP_H_INCLUDED

