#include "position.h"
#include "position.cpp"
#include "piece.h"
#include "piece.cpp"
#include "position_echec.h"
#include "position_echec.cpp"
#include "echiquier.h"
#include "echiquier.cpp"
#include <ostream>
#include <iostream>
using namespace std;

position_echec::~position_echec() // destructeur de toutes les positions filles d'une position
{
    if((pos_fille!=NULL)||(pos_soeur!==NULL))
    delete []pos_fille;
    delete []pos_soeur;
}
double position_echec::getvaleur(double alpha,double beta) const// la fonction qui renvoie la valeur d'une position
{
    int cont_ordinateur=0;
    int cont_humain=0;

    for(int l=0;l<8:l++)
    {
        for(int c=0;c<8:c++)
        if(!(bool casevide(int l,int c)))&&(ehcectab[l][c].couleur==noir)
        cont_ordinateur++;
    }
    for(int l=0;l<8:l++)
    {
        for(int c=0;c<8:c++)
        if(!(bool casevide(int l,int c)))&&(ehcectab[l][c].couleur==blanc)
        cont_humain++;
    }
    double valeur;
    valeur=alpha*(position.val_pos_humain-position.val_pos_ordinateur)+beta*(cont_humain-cont_ordinateur);
    return valeur;
}
position_echec* position_echec::get_pos_suiv() const
{
    position_echec* pos_fille=new position_echec[100];
    if(Jeu_pos==humain) //si le humain joue
    {
        for(int l=0;l<8;l++)
        {
            for(int c=0;c<8;c++)
            {
                if((echiquier_ref.echectab[l][c]!=PV)&&(echiquier_ref.ehectab[l][c].col==blanc))
                coup possible??
                
            }
        }
        return pos_fille;
    }
    else if(Jeu_pos==ordinateur) //si l'ordinateur joue
    {
        for(int l=0;l<8;l++)
        {
            for(int c=0;c<8;c++)
            {
                if((echiquier_ref.echectab[l][c]!=PV)&&(echiquier_ref.ehectab[l][c].col==noir))
                coup possible??
                
            }
        }
        return pos_fille;
    }
}

void partie() //definition d'une partie
{
    echiquier E; //definition d'un echiquier
    E=echiquier(); //initiqlisqtion d'un echiquier
    E.print();
    
    //coup possible pour le joueur humain
    //coup joue par le joueur huamin
    
    //determiner le meilleur coup du joueur ordinateur(minmax)
    //coup joue par le joueur ordinateur
    position_echec pos_init=position_echec(E); //definition de la position de l'echiquier E
    pos_init.Jeu_pos=humain;
    
    
}

