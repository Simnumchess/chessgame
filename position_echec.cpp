#include "position.h"
#include "position_echec.h"
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
position_ehec* position_echec::get_pos-suiv() const
{
    position_echec* pos_fille=new position_echec[100];
    if(Jeu_pos==humain)
    {
        for(int l=0;l<8;l++)
        {
            for(int c=0;c<8;c++)
            {
                if((echiquier_ref.echectab[l][c]!=PV)&&(echiquier_ref.ehectab[l][c].col==blanc))
                
            }
        }
    }
    
}

