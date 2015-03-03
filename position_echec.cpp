#include "position.h"
#include "piece.h"
#include "position_echec.h"
#include "echiquier.h"
#include "coup.h"
#include "minmax.h"
#include <ostream>
#include <iostream>
using namespace std;

position_echec::~position_echec() // destructeur de toutes les positions filles
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
position_echec* position_echec::get_pos_suiv()
{
    position_echec* pos_fille=new position_echec[100]; //un tableau de position fille
    if(Jeu_pos==humain) //si le humain joue
    {
        for(int l=0;l<8;l++)
        {
            for(int c=0;c<8;c++)
            {
                if((echiquier_ref.echectab[l][c].type_piece!=Piecevide)&&(echiquier_ref.ehectab[l][c].col==blanc))
                //coup possible??
                coup C;
                C.piece_jouee=echiquier_ref.echectab[l][c];
                
                
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
position_echec & position_echec::explorer() //explorer 4 coups(2 par joueurs)
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
position_echec position_echec::renouveler() //mise a jour de l'echiquier de reference apres les coups jouees
{
    //coup possible
}

int position_echec::val_position() const //tester si quelqu'un a gagne
{
    if(coup_jouee.piece_mangee.type_piece==ROi)
    {
        if(coup_jouee.piece_mangee.col==nor)
        return maxi; //le humain gagne
        else return mini; //l'ordinateur gagne
    }
    else return 0; //personne gagne, le jeu continue
}

position_echec & position_echec::operator=(const position_echec & p) //operateur = pour une position_echec
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
position_echec::position_echec(const position_echec & p) //operateur par copie
{
    echiquier_ref=p.echiquier_ref;
    coup_joue=p.coup_joue;
    coup_historique=p.coup_historique;
    pos_fille=p.pos_fille;
    pos_soeur=p.pos_soeur;
    return *this;
}
position_echec::position_echec(echiquier E) //constructeur de la position initiale
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
    position_echec pos_init=position_echec(E); //definition de la position de l'echiquier E
    pos_init.Jeu_pos=humain;
    
    
}

