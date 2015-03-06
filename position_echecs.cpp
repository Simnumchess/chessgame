#include "position.h"
#include "piece.h"
#include "position_echecs.h"
#include "echiquier.h"
#include "coup.h"
#include "minmax.h"
#include <ostream>
#include <iostream>
using namespace std;

position_echec::val_pos_ordinateur()
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
position_echec::val_pos_humain()
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



position_echecs::~position_echecs() // destructeur de toutes les positions filles
{
    if((pos_fille!=NULL)||(pos_soeur!==NULL))
    delete []pos_fille;
    delete []pos_soeur;
}
double position_echecs::getvaleur(double alpha,double beta) const// la fonction qui renvoie la valeur d'une position
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
position_echecs* position_echecs::get_pos_suiv()
{
    position_echecs* pos_fille=new position_echecs[100]; //un tableau de position fille
    int n=0;
    if(Jeu_pos==humain) //si le humain joue
    {
        for(int l=0;l<8;l++)
        {
            for(int c=0;c<8;c++)
            {
                if((echiquier_ref.echectab[l][c].type_piece!=Piecevide)&&(echiquier_ref.ehectab[l][c].col==blanc))
                //coup possible??
                //class coup: piece_jouee;piece_mangee;coordonnee avant le coup;coordonnee apres le coup;bool coup_possible()
                coup C;
                C.piece_jouee=echiquier_ref.echectab[l][c];
                C.piece_mangee=Piece() //piecevide
                if(bool coup_possible(coup C)==true)
                {
                    pos_fille[n]=position_echec(*this);
                    if(Jeu_pos==humain)
                    {
                        pos_fille[n].Jeu_pos==ordinateur;
                    }
                    else
                    {
                        pos_fille[n].Jeu_pos==humain;
                    }
                    n++;
                }
                
                
                
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
                //coup possible??
                
            }
        }
        return pos_fille;
    }
}
int position_echecs::resultat() const
{
    if(coup_joue.piece_mangee.type_piece==Roi)
    {
        if(coup_joue.piece_mangee.col==blanc)
        {
            
            cout<<"You lose";
            return mini;
            else 
            cout<<"You win";
            return maxi;
            
        }
    }
    
    else return 0;
    cout<<"Please continue..."
}
position_echecs & position_echecs::explorer() //explorer 4 coups(2 par joueurs)
{
    int l1,l2,c1,c2=0;
    //explorer les coups
    coup cp=coup();
    cp.piece_jouee=echiquier_ref[l1][c1];
    cp.piece_mangee=echiauier_ref[l2][c2];
    cp.ligne_init=l1;
    cp.colone_init=c1;
    cp.ligne_final=l2;
    cp.colone_final=c2;
    cp.col=echiquier_ref.echectab[l1][c1].col;
    
}
position_echecs position_echecs::maj() //mise a jour de l'echiquier de reference apres les coups jouees
{
    //coup possible
}



position_echecs & position_echecs::operator=(const position_echecs & p) //operateur = pour une position_echec
{
    if(this==&p) 
    return *this;
    else 
    {
        echiquier_ref=p.echiquier_ref;
        coup_joue=p.coup_joue;
        coup_historique=p.coup_historique;
        pos_fille=p.pos_fille;
        pos_soeur=p.pos_soeur;
        return *this;
    }
}
position_echecs::position_echecs(const position_echecs & p) //operateur par copie
{
    echiquier_ref=p.echiquier_ref;
    coup_joue=p.coup_joue;
    coup_historique=p.coup_historique;
    pos_fille=p.pos_fille;
    pos_soeur=p.pos_soeur;
    return *this;
}
position_echecs::position_echecs(echiquier E) //constructeur de la position initiale
{
    echiquier_ref=E;
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
    position_echecs pos_init=position_echecs(E); //definition de la position de l'echiquier E
    pos_init.Jeu_pos=humain;
    
    
}

