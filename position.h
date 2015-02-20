#ifndef POSITION_H_INCLUDED
#define POSITION_H_INCLUDED

class position
{
    public:

    enum Joueur
    {
        humain;
        ordinateur;
    }
    int val_pos_humain();
    int val_pos_ordinateur();
    int i;
    int j;
    position *pos_soeur;
    position *pos_fille;
    Joueur getJoueur();

    ~position ();


};


#endif // POSITION_H_INCLUDED

