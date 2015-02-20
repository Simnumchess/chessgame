#include "position.h"
#include "echiquier.h"
#include "piece.h"

using namespace std;

Joueur position::getJoueur()
{
    if()
    return humain;
    if()
    return ordinadeur;
}

position::~position()
{
    if((pos_soeur!=NULL)||(pos_fille!=NULL))
    delete []pos_fille;
    delete []pos_soeur;
}
position::val_pos_ordinateur()
{
    for(int l=0; l<8; l++)
    {
        for(int c=0;c<8;c++)
        if(!(bool casevide(int l,int c)))
        {
            if(echectab[l][c].couleur==noir)
            val_pos_ordinateur=val_pos_ordinateur+echectab[l][c].getvaleurpiece();

        }
    }
    return val_pos_ordinateur;
}
position::val_pos_humain()
{
    for(int l=0; l<8; l++)
    {
        for(int c=0;c<8;c++)
        if(!(bool casevide(int l,int c)))
        {
            if(ehcectab[l][c].couleur==blanc)
            val_pos_humain=val_pos_humain+echectab[l][c].getvaleurpiece();

        }
    }
    return val_pos_humain;
}


//classe abstraite position
// classes filles position pour ttt et pour echecs

Position::Position()
{

*m_position_soeur=0; // pointeur sur la position soeur
*m_position_premiere_fille=0; //pointeur sur la premiere position fille
m_joueur="White";

}

