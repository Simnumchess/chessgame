#include "position.h"

using namespace std;

Joueur Position::getJoueur()
{
    return Joueur_pos;
}

Position::~Position()
{
    if((pos_soeur!=NULL)||(pos_fille!=NULL))
    delete []pos_fille;
    delete []pos_soeur;
}

//classe abstraite position
// classes filles position pour ttt et pour echecs

Position::Position()
{

*m_position_soeur=0; // pointeur sur la position soeur
*m_position_premiere_fille=0; //pointeur sur la premiere position fille
m_joueur="White";

}

